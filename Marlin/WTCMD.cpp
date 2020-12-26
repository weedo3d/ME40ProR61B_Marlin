/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/


#include "WTCMD.h"
#include "parser.h"
#include "watchdog.h"
#include "cardreader.h"
#include "printcounter.h"
#include "duration_t.h"
#include "planner.h"
#include "temperature.h"
#include "configuration_store.h"
#include "Marlin.h"
#include "WTDGUSManager.h"
#include "WTDGUSSerial.h"

#define ACTION_ON_PAUSE		"pause"
#define ACTION_ON_PAUSED	"paused"
#define ACTION_ON_RESUME	"resume"
#define ACTION_ON_CANCEL	"cancel"
#define ACTION_ON_DISCONNECT	"disconnect"
#define ACTION_ON_START       "start"
#define ACTION_ON_FINISH      "finish"

extern CardReader card;
extern InPacket inp3;

WT_STATUS wt_machineStatus = WT_STATUS::IDLE;

uint8_t wt_onlineprinting = SPARK_IDLE;		// 0 = not printing, 1 = paused, 2 = printing

char ipAddress[16];
char esp32_name[12];
char esp32_hardware[8];
char esp32_version[8];
char esp32_message[22];
char esp32_serial[16];
bool getIPAddress = false;
bool isOTAUpdating = false;
char uploadFilename[FILENAME_LENGTH + 2];
char wifi_ssid[30];
char wifi_pwd[30];
char parsedString[30];
uint8_t wt_hostmode = HOST_WIIBUILDER;
uint8_t wt_hostmode_init = 0;
uint8_t progress_bar_percent;
char tb_state[20];

void WT_Set_SmartConfig()
{
	getIPAddress = false;
	SERIAL_PROTOCOLLNPGM("WTCMD:CONFIG");
}

void WT_Get_IP()
{
	inp3.SendCommand('I');
}

void WT_ESP32_Restart()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:RESTART");
}

void WT_Get_ESP32Version()
{
	inp3.SendCommand('F');
	inp3.SendCommand('J');
	inp3.SendCommand('K');
}

void WT_OTA_Default()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:OTADEFAULT");
}

void WT_OTA_URI(const char * uri)
{
	SERIAL_PROTOCOLLNPAIR("WTCMD:OTAURI ", uri);
}

void WT_OTA_Force(const char * uri, const char * ver)
{
	SERIAL_PROTOCOLPGM("WTCMD:OTAFORCE ");
	SERIAL_PROTOCOL(uri);
	SERIAL_PROTOCOLPGM(" ");
	SERIAL_PROTOCOLLN(ver);
}

void WT_WIFI_Default()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:WIFIDEFAULT");
}

void WT_WIFI_Join()
{
	SERIAL_EOL();
	SERIAL_PROTOCOLPGM("WTCMD:JOIN ");
	SERIAL_PROTOCOLPAIR("SSID:", wifi_ssid);
	SERIAL_PROTOCOLLNPAIR(" PWD:", wifi_pwd);
}

void WT_TB_STATE()
{
	SERIAL_EOL();
	SERIAL_PROTOCOLPGM("WTCMD:TBSTATE ");
}

void GetMachineStatus()
{
	SERIAL_ECHOPGM("MStatus:");
	SERIAL_ECHO(wt_machineStatus);

	SERIAL_ECHOPGM(" MFile:");
	card.printFilename();

	char buffer[21];
	duration_t elapsed = print_job_timer.duration();
	elapsed.toString(buffer);

	SERIAL_ECHOPGM(" MTime:");
	SERIAL_ECHO(buffer);

	SERIAL_ECHOPGM(" MPercent:");
	card.getStatus();

	SERIAL_EOL();
}

static void ParseIPAddress()
{
	char* tempS;
	tempS = parser.string_arg;

	if (strstr_P(tempS, PSTR("Disconnected")) != NULL)
	{
		strcpy_P(ipAddress, PSTR("Disconnected"));
	}
	else
	{
		strcpy(ipAddress, tempS);
	}
}

static void ParseTBState()
{
	ZERO(tb_state);
	strcpy(tb_state, parser.string_arg);
}

void wt_OpenExtruder0Fan()
{
	digitalWrite(E0_AUTO_FAN_PIN, HIGH);
}

void wt_CloseExtruder0Fan()
{
	digitalWrite(E0_AUTO_FAN_PIN, LOW);
}

void wt_OpenAirFan()
{
#if MB(WEEDO_61B)
	digitalWrite(AIR_FAN_PIN, HIGH);
#endif
}

void wt_CloseAirFan()
{
#if MB(WEEDO_61B)
	digitalWrite(AIR_FAN_PIN, LOW);
#endif
}

void wt_PowerOff()
{
	dserial.LoadScreen(SCREEN_POWER_OFF);
	SERIAL_PROTOCOLPGM("power off...");
	while (1)
	{
		digitalWrite(POWEROFFPIN, HIGH);
		delay(500);
		digitalWrite(POWEROFFPIN, LOW);
		delay(500);

#if ENABLED(USE_WATCHDOG)
		watchdog_reset();
#endif
	}
}

void wt_sdcard_stop()
{
	dgus.ShowNoRetrunMessage_P(MMSG_SDCARD_STOP[wtvar_language]);
	card.stopSDPrint();
	print_job_timer.stop();

	wait_for_heatup = false;

	wtvar_gohome = 1;
	(void)settings.save();

	wt_restart();

}

void wt_sdcard_pause(bool showMessage)
{
	if (showMessage)
		dgus.ShowNoRetrunMessage_P(MMSG_SDCARD_PAUSE[wtvar_language]);
	card.pauseSDPrint();
	print_job_timer.pause();

#if ENABLED(PARK_HEAD_ON_PAUSE)
	enqueue_and_echo_commands_P(PSTR("M125"));
#endif

	dgus.EnableMessageNoReturnAutoGoback();

	wt_machineStatus = WT_STATUS::PAUSE;
}

void wt_sdcard_resume()
{
	dgus.ShowNoRetrunMessage_P(MMSG_SDCARD_RESUME[wtvar_language]);
#if ENABLED(PARK_HEAD_ON_PAUSE)
	enqueue_and_echo_commands_P(PSTR("M24"));
#else
	card.startFileprint();
	print_job_timer.start();
#endif

	planner.synchronize();
	dgus.GotoStatusMenu();

	wt_machineStatus = WT_STATUS::PRINTING;
}


void wt_spark_begin()
{
	wt_onlineprinting = SPARK_PRINTING;
	print_job_timer.start();

	dgus.GotoStatusMenu();
	dgus.SetFilename("Spark Printing");

	wt_machineStatus = WT_STATUS::PRINTING;
}

void wt_spark_end()
{
	wt_machineStatus = WT_STATUS::FINISH;
	wt_onlineprinting = SPARK_IDLE;
	print_job_timer.stop();

#ifdef DGUS_LCD
	dgus.GotoPrintEndMenu();
#endif
}

void wt_spark_cancel()
{
	wt_sdcard_stop();
}

void wt_spark_pause()
{
#if ENABLED(PARK_HEAD_ON_PAUSE)
	enqueue_and_echo_commands_P(PSTR("M125"));
#endif
	print_job_timer.pause();

	wt_machineStatus = WT_STATUS::PAUSE;
	wt_onlineprinting = SPARK_PAUSED;
	dgus.GotoStatusMenu();
}

extern void resume_print(const float &slow_load_length = 0, const float &fast_load_length = 0, const float &purge_length = ADVANCED_PAUSE_PURGE_LENGTH, const int8_t max_beep_count = 0);
void wt_spark_resume()
{
#if ENABLED(PARK_HEAD_ON_PAUSE)
	resume_print(0, 0, 0, 0);
#endif
	print_job_timer.start();

	wt_machineStatus = WT_STATUS::PRINTING;
	wt_onlineprinting = SPARK_PRINTING;
	dgus.GotoStatusMenu();

}

void wt_online_pause()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_PAUSE);
	dgus.ShowNoRetrunMessage_P(MMSG_SDCARD_PAUSE[wtvar_language]);
}

void wt_online_resume()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_RESUME);
}

void wt_online_cancel()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_CANCEL);
	dgus.ShowNoRetrunMessage_P(MMSG_SDCARD_STOP[wtvar_language]);
}

extern uint8_t lcd_status_update_delay;
// W Command Process
void WTCMD_Process()
{
	switch (parser.codenum)
	{
	case 1:		
		wt_spark_begin();
		break;

	case 2:		
		wt_spark_end();
		break;

	case 3:		
		wt_spark_cancel();
		break;

	case 4:		
		wt_spark_pause();
		break;

	case 5:		
		wt_spark_resume();
		break;

	case 106:		
		ZERO(uploadFilename);
		if (strlen(parser.string_arg) <= FILENAME_LENGTH)
			strcpy(uploadFilename, parser.string_arg);
		else
			strncpy(uploadFilename, parser.string_arg, FILENAME_LENGTH);
		dgus.ShowUploadingMenu(uploadFilename);
		break;

	case 201:	
		GetMachineStatus();
		break;

	case 203:	
		wt_restart();
		while (1);
		break;

	case 204:	
		ParseIPAddress();
		getIPAddress = true;
		break;

	case 205:	
		memset(esp32_serial, 0, 16);
		if (strlen(parser.string_arg) <= 16)
			strcpy(esp32_serial, parser.string_arg);
		else
			strncpy(esp32_serial, parser.string_arg, 16);
		break;

	case 206:	
		memset(esp32_version, 0, 8);
		if (strlen(parser.string_arg) <= 8)
			strcpy(esp32_version, parser.string_arg);
		else
			strncpy(esp32_version, parser.string_arg, 8);
		break;

	case 207:	
		memset(esp32_name, 0, 12);
		if (strlen(parser.string_arg) <= 12)
			strcpy(esp32_name, parser.string_arg);
		else
			strncpy(esp32_name, parser.string_arg, 12);
		break;

	case 208:	
		memset(esp32_message, 0, 22);
		if (strlen(parser.string_arg) <= 22)
			strcpy(esp32_message, parser.string_arg);
		else
			strncpy(esp32_message, parser.string_arg, 22);
		break;

	case 209:		
		wt_sdcard_stop();
		while (1);
		break;

	case 210:	
		WT_WIFI_Default();
		break;

	case 211:	
		wt_OpenExtruder0Fan();
		break;

	case 212:	
		wt_CloseExtruder0Fan();
		break;

	case 213:	
		ParseTBState();
		break;

	case 214:	
		wt_OpenAirFan();
		break;

	case 215:		
		wt_CloseAirFan();
		break;
		
	case 300:	
		memset(wifi_ssid, 0, 30);
		strcpy(wifi_ssid, parser.string_arg);
		break;

	case 301:	
		memset(wifi_pwd, 0, 30);
		strcpy(wifi_pwd, parser.string_arg);
		break;

	case 302:		
		WT_WIFI_Join();
		break;

	default:
		 parser.unknown_command_error();

	}

}

uint8_t extractFront(const char* source, char* ident, char* valString)
{
	int len1 = strlen(source);
	int len2 = strlen(ident);

	if (len1 < len2) return 0;

	int start;
	int i = 0;
	const char* sp;
	sp = source;
	do
	{
		start = strstr(sp, ident) - source;
		sp++;
		i++;
	} while ((start > 0) && (start < len1) && (i < len1) && (source[start - 1] != 0x20));

	if (start >= 0 && start < len1)
	{
		sp = source;
		sp += len2 + start;
		i = len2 + start;

		while (i < len1 && *sp != 0x20)
		{
			sp++;
			i++;
		}
		if (i > len2)		
		{
			sp = source;
			sp += len2 + start;
			memcpy(valString, sp, i - len2 - start);
			valString[i - len2 - start] = 0;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

void wt_restart()
{
	asm volatile ("jmp 0");
}
