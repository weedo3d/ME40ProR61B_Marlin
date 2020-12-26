/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "printcounter.h"
#include "duration_t.h"
#include "WTDGUSScreen_MachineInfo.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern char esp32_name[12];
extern char esp32_serial[16];
extern char tb_state[20];

void DGUS_Screen_MachineInfo::Init()
{
	dserial.LoadScreen(SCREEN_MACHINE_INFO);
	holdontime = getcurrenttime();
	WT_Get_ESP32Version();
	WT_TB_STATE();

	dserial.SendString_P(ADDR_MACHINE_TITLE, MMSG_MACHINE_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_MACHINE_BUTTON2, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_MACHINE_ICON_HELP, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_MACHINE_ITEM1, MMSG_MACHINE_ITEM1[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_VALUE1, PSTR(MACHINE_NAME), 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM2, MMSG_MACHINE_ITEM2[wtvar_language], 32);

	printStatistics now = print_job_timer.getStats();
	duration_t elapsed = now.printTime;
	char buffer[21];
	memset(buffer, 0, 21);
	elapsed.toShortTimeString(buffer);
	dserial.SendString(ADDR_MACHINE_VALUE2, buffer, 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM3, MMSG_MACHINE_ITEM3[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_VALUE3, PSTR(SHORT_BUILD_VERSION), 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM4, MMSG_MACHINE_ITEM4[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_VALUE4, PSTR(UI_VERSION), 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM5, MMSG_MACHINE_ITEM5[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_serial, 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM6, MMSG_MACHINE_ITEM6[wtvar_language], 32);
	dserial.SendString(ADDR_MACHINE_VALUE6, tb_state, 32);
	dserial.SendString_P(ADDR_MACHINE_ERROR1, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR2, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR3, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR4, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR5, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR6, MMSG_EMPTY, 30);
}

void DGUS_Screen_MachineInfo::Update()
{
	dserial.SendString(ADDR_MACHINE_VALUE5, esp32_serial, 16);
	dserial.SendString(ADDR_MACHINE_VALUE6, tb_state, 16);
}

void DGUS_Screen_MachineInfo::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MACHINE_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_MACHINE_BUTTON2)
			{
				Goback();
			}
		}
	}
}