/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "cardreader.h"
#include "temperature.h"
#include "WTDGUSManager.h"
#include "WTDGUSConfig.h"
#include "WTDGUSSerial.h"
#include "WTCounter.h"

DGUSManager dgus;

enum TouchCmdSts
{
	NOTHING = 0,
	FOUNDHEAD1 = 1,
	FOUNDHEAD2 = 2,
	FOUNDLEN = 3,
	FOUNDFUN = 4,
	FOUNDDATA = 5,
	CMDVALID = 6
};

TouchPara gltouchpara;

DGUSManager::DGUSManager()
{

}

void DGUSManager::Init(unsigned long baud)
{
	dserial.Init(baud);

	lcd_sd_status = 2;

	InitMenu();
	reset();
	memset(filename, 0, 21);
	testingMode = false;
}

void DGUSManager::Update()
{
	process();

	nowtime = getcurrenttime();
	if (nowtime > screenCurrent->holdontime + screenCurrent->updaterate)
	{
		screenCurrent->holdontime = nowtime;
		screenCurrent->Update();
	}

	const uint8_t sd_status = (uint8_t)IS_SD_INSERTED;
	if (sd_status != lcd_sd_status)
	{
		uint8_t old_sd_status = lcd_sd_status; 
		lcd_sd_status = sd_status;

		if (sd_status == 0) 
		{
			card.initsd();
			if (old_sd_status == 2)
				card.beginautostart(); 
			else
			{
				SERIAL_ECHO_START();
				SERIAL_ECHOLNPGM(MSG_SD_CARD_OK);
			}
		}
		else {
			card.release();
			if (old_sd_status != 2)
			{
				SERIAL_ECHO_START();
				SERIAL_ECHOLNPGM(MSG_SD_INIT_FAIL);
			}
		}
	}
}


void DGUSManager::process()
{
	uint8_t b;

	if (dserial.available() < 9)	
		return;

	while (dserial.available() > 0)
	{
		b = (uint8_t)dserial.read();
		//SERIAL_PROTOCOLLNPAIR("serial3:", b);
		if (state == DS_START1)
		{
			if (b == DGUS_START_BYTE_1)
				state = DS_START2;
		}
		else if (state == DS_START2)
		{
			if (b == DGUS_START_BYTE_2)
				state = DS_LEN;
			else
				reset();
		}
		else if (state == DS_LEN)
		{
			if (b < DGUS_PAYLOAD_LENGTH && b > 0)
			{
				expected_length = b;
				state = DS_PAYLOAD;
			}
			else
				reset();
		}
		else if (state == DS_PAYLOAD)
		{
			append(b);

			if (length >= expected_length)
			{
				gltouchpara.address = (payload[1] << 8) | payload[2];

				if (gltouchpara.address == 0x84)
				{
					gltouchpara.value = (payload[6] << 8) | payload[7];
					gltouchpara.validflg = true;
					SERIAL_ECHOLNPAIR("DGUS Screen ID:", gltouchpara.value);
					screenCurrent->KeyProcess();
				}
				else
				{
					gltouchpara.value = (payload[4] << 8) | payload[5];

					if (gltouchpara.address >= 0x1000 && gltouchpara.address <= 0x2FFFF)
					{
						gltouchpara.validflg = true;
						SERIAL_ECHOLNPGM("DGUS key pressed");
						SERIAL_ECHOLNPAIR("addr: ", gltouchpara.address);
						SERIAL_ECHOLNPAIR("val: ", gltouchpara.value);
						screenCurrent->KeyProcess();
						wt_timer.restart();
					}
				}
				reset();
			}
		}
	}
}

void DGUSManager::InitMenu()
{
	screenMain = new DGUS_Screen_Main();
	screenPrepare = new DGUS_Screen_Prepare();
	screenControl = new DGUS_Screen_Control();
	screenSDCard = new DGUS_Screen_SDCard();
	screenStatus = new DGUS_Screen_Status();
	screenError = new DGUS_Screen_Error();
	screenPrintEnd = new DGUS_Screen_PrintEnd();
	screenPowerOff = new DGUS_Screen_PowerOff();
	screenPrintingSetting = new DGUS_Screen_PrintingSetting();
	screenLevelbed = new DGUS_Screen_Levelbed();
	screenFilament = new DGUS_Screen_Filament();
	screenPreheat = new DGUS_Screen_Preheat();;
	screenMachineInfo = new DGUS_Screen_MachineInfo();
	screenWifiSetting = new DGUS_Screen_WifiSetting();
	screenSavePrinting = new DGUS_Screen_SavePrinting();
	screenResumePrinting = new DGUS_Screen_ResumePrinting();
	screenBoot = new DGUS_Screen_Boot();
	screenRestoreSetting = new DGUS_Screen_RestoreSetting();
	screenTestMode = new DGUS_Screen_TestMode();
	screenSmartConfig = new DGUS_Screen_SmartConfig();
	screenMessageReturn = new DGUS_Screen_Message_Return();
	screenMessageNoReturn = new DGUS_Screen_Message_NoReturn();
	screenOTA = new DGUS_Screen_OTA();
	screenZOffset = new DGUS_Screen_ZOffset();
	screenLanguage = new DGUS_Screen_Language();
	screenJob = new DGUS_Screen_Job();
	screenProximity = new DGUS_Screen_Proximity();
	screenSpeed = new DGUS_Screen_Speed();
	screenPowersave = new DGUS_Screen_PowerSave();
	screenSelftest = new DGUS_Screen_SelfTest();
	screenHelp = new DGUS_Screen_Help();
	screenErrorDiag = new DGUS_Screen_ErrorDiag();
	screenHelpList = new DGUS_Screen_HelpList();

	screenSDCard->SetParent(dgus.screenMain);
	screenPrepare->SetParent(dgus.screenMain);
	screenControl->SetParent(dgus.screenMain);
	screenPrintEnd->SetParent(dgus.screenMain);
	screenSelftest->SetParent(dgus.screenMain);
	screenHelp->SetParent(dgus.screenMain);
	screenFilament->SetParent(dgus.screenPrepare);
	screenLevelbed->SetParent(dgus.screenPrepare);
	screenPreheat->SetParent(dgus.screenPrepare);
	screenJob->SetParent(dgus.screenPrepare);
	screenZOffset->SetParent(dgus.screenPrepare);
	screenProximity->SetParent(dgus.screenPrepare);
	screenWifiSetting->SetParent(dgus.screenControl);
	screenMachineInfo->SetParent(dgus.screenControl);
	screenPowersave->SetParent(dgus.screenControl);
	screenRestoreSetting->SetParent(dgus.screenControl);
	screenSmartConfig->SetParent(screenWifiSetting);
	screenOTA->SetParent(screenWifiSetting);
	screenTestMode->SetParent(dgus.screenMain);
	screenMessageReturn->SetParent(dgus.screenMain);
	screenPrintingSetting->SetParent(dgus.screenStatus);
	screenSpeed->SetParent(screenPrintingSetting);
	screenLanguage->SetParent(dgus.screenMain);
	screenErrorDiag->SetParent(screenHelp);
	screenHelpList->SetParent(screenHelp);

	screenCurrent = dgus.screenMain;
}

void DGUSManager::GotoMain(void)
{
	testingMode = false;
	screenCurrent = dgus.screenMain;
	screenCurrent->Init();
}

void DGUSManager::GotoScreen(DGUS_Screen_Base* screen)
{
	screenCurrent = screen;
	screenCurrent->Init();
}

void DGUSManager::LoadSubScreen(DGUS_Screen_Base* screen, DGUS_Screen_Base* parent)
{
	screenCurrent = screen;
	screenCurrent->SetParent(parent);
	screenCurrent->Init();
}

void DGUSManager::ResetScreen(void)
{
	dserial.ResetScreen();
}

void DGUSManager::GotoLoadFilament(DGUS_Screen_Base* parent)
{
	screenFilament->operation = FILAMENT_OPERATION_LOAD;
	screenFilament->SetParent(parent);
	GotoScreen(screenFilament);
}

void DGUSManager::GotoUnloadFilament(DGUS_Screen_Base* parent)
{
	screenFilament->operation = FILAMENT_OPERATION_UNLOAD;
	screenFilament->SetParent(parent);
	GotoScreen(screenFilament);
}

void DGUSManager::reset()
{
	memset(payload, 0 , DGUS_PAYLOAD_LENGTH);
	length = 0;
	expected_length = 0;
	state = DS_START1;
}

void DGUSManager::append(uint8_t data)
{
	if (length < DGUS_PAYLOAD_LENGTH)
	{
		payload[length] = data;
		length++;
	}
}

void DGUSManager::ShowMessageRetrun_P(const char* title,
	const char* button,
	const char* line1,
	const char* line2,
	const char* line3,
	const char* line4,
	const char* line5,
	const char* line6,
	const char* line7)
{
	LoadMessageReturnMenu(screenCurrent);
	screenMessageReturn->Title_P(title);
	screenMessageReturn->Button_P(button);
	screenMessageReturn->Line1_P(line1);
	screenMessageReturn->Line2_P(line2);
	screenMessageReturn->Line3_P(line3);
	screenMessageReturn->Line4_P(line4);
	screenMessageReturn->Line5_P(line5);
}

void DGUSManager::ShowMessageNoRetrun_P(const char* title,
	const char* line1,
	const char* line2,
	const char* line3,
	const char* line4,
	const char* line5,
	const char* line6,
	const char* line7,
	const char* line8,
	const char* line9)
{
	LoadMessageNoReturnMenu(screenCurrent);
	screenMessageNoReturn->Title_P(title);
	screenMessageNoReturn->Line1_P(line1);
	screenMessageNoReturn->Line2_P(line2);
	screenMessageNoReturn->Line3_P(line3);
	screenMessageNoReturn->Line4_P(line4);
	screenMessageNoReturn->Line5_P(line5);
	screenMessageNoReturn->Line6_P(line6);
}


void DGUSManager::ShowErrorMessage_P(const char* title,
	const char* line1,
	const char* line2,
	const char* line3,
	const char* line4,
	const char* line5,
	const char* line6)
{
	GotoScreen(screenError);
	screenError->Title_P(title);
	screenError->Line1_P(line1);
	screenError->Line2_P(line2);
	screenError->Line3_P(line3);
	screenError->Line4_P(line4);
	screenError->Line5_P(line5);
	screenError->Line6_P(line6);
}


void DGUSManager::ShowErrorMessage(const char* msg)
{
	ShowErrorMessage_P(MMSG_ERROR_TITLE[wtvar_language],
		MMSG_EMPTY,
		MMSG_EMPTY,
		msg,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY);
}

void DGUSManager::ShowErrorMessageString(const char* msg)
{
	GotoScreen(screenError);
	screenError->Title_P(MMSG_ERROR_TITLE[wtvar_language]);
	screenError->Line1_P(MMSG_EMPTY);
	screenError->Line2_P(MMSG_EMPTY);
	screenError->Line3(msg);
	screenError->Line4_P(MMSG_EMPTY);
	screenError->Line5_P(MMSG_EMPTY);
	screenError->Line6_P(MMSG_EMPTY);
}

void DGUSManager::ShowRunoutMessage(void)
{
	LoadMessageReturnMenu(screenStatus);
	screenMessageReturn->Title_P(MMSG_ERROR_TITLE[wtvar_language]);
	screenMessageReturn->Button_P(MMSG_CONTINUE[wtvar_language]);
	screenMessageReturn->Line1_P(MMSG_EMPTY);
	screenMessageReturn->Line2_P(MMSG_EMPTY);
	screenMessageReturn->Line3_P(MMSG_RUNOUT_1[wtvar_language]);
	screenMessageReturn->Line4_P(MMSG_EMPTY);
	screenMessageReturn->Line5_P(MMSG_EMPTY);
}

void DGUSManager::ShowMessage(const char* msg)
{
	LoadMessageReturnMenu(screenCurrent);
	screenMessageReturn->Title_P(MMSG_NOTICE_TITLE[wtvar_language]);
	screenMessageReturn->Button_P(MMSG_BACK[wtvar_language]);
	screenMessageReturn->Line1_P(MMSG_EMPTY);
	screenMessageReturn->Line2_P(MMSG_EMPTY);
	screenMessageReturn->Line3(msg);
	screenMessageReturn->Line4_P(MMSG_EMPTY);
	screenMessageReturn->Line5_P(MMSG_EMPTY);
}

void DGUSManager::ShowMessage_P(const char* msg)
{
	LoadMessageReturnMenu(screenCurrent);
	screenMessageReturn->Title_P(MMSG_NOTICE_TITLE[wtvar_language]);
	screenMessageReturn->Button_P(MMSG_BACK[wtvar_language]);
	screenMessageReturn->Line1_P(MMSG_EMPTY);
	screenMessageReturn->Line2_P(MMSG_EMPTY);
	screenMessageReturn->Line3_P(msg);
	screenMessageReturn->Line4_P(MMSG_EMPTY);
	screenMessageReturn->Line5_P(MMSG_EMPTY);
}

void DGUSManager::ShowNoRetrunMessage_P(const char* msg)
{
	ShowMessageNoRetrun_P(MMSG_NOTICE_TITLE[wtvar_language],
		MMSG_EMPTY,
		MMSG_EMPTY,
		msg,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY);
}

void DGUSManager::ShowUploadingMenu(char* msg)
{
	LoadMessageNoReturnMenu(screenCurrent);
	screenMessageNoReturn->Title_P(MMSG_Uploading_Title[wtvar_language]);
	screenMessageNoReturn->Line3_P(MMSG_Uploading1[wtvar_language]);
	screenMessageNoReturn->Line5(msg);
}
void DGUSManager::ShowUploadFailMenu()
{
	ShowMessageNoRetrun_P(MMSG_ERROR_TITLE[wtvar_language],
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_UploadFail1[wtvar_language],
		MMSG_UploadFail2[wtvar_language],
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY,
		MMSG_EMPTY);
}

void DGUSManager::SetFilename(const char* fname)
{
	memset(filename, 0, 21);
	uint8_t _len = strlen(fname);
	if (_len <= 20)
	{
		strcpy(filename, fname);
		for (uint8_t i = _len; i < 20; i++)
			filename[i] = 0x20;
		
	}
	else
	{
		strncpy(filename, fname, 20);
	}

	filename[20] = 0;

	screenStatus->ShowFilename(filename);
	screenPrintEnd->ShowFilename(filename);
}

void DGUSManager::SetPrintTime(const char* time)
{

}

void DGUSManager::ShowMovingMessage(void)
{
	dserial.LoadScreen(SCREEN_NOTICE);
	dserial.SendString_P(ADDR_NOTICE_TEXT_TITLE, MMSG_NOTICE_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE1, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE2, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE3, MMSG_NOTICE_MOVING[wtvar_language], 50);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE4, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE5, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE6, MMSG_EMPTY, 50);
}

void DGUSManager::NozzleTempError(void)
{
	thermalManager.disable_all_heaters();
	screenSelftest->NozzleTempError();
}

void DGUSManager::BedTempError(void)
{
	thermalManager.disable_all_heaters();
	screenSelftest->BedTempError();
}

void DGUSManager::EndStopError(void)
{
	screenSelftest->EndStopError();
}
