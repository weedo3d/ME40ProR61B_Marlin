/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Main.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTCounter.h"

extern bool getIPAddress;
extern char ipAddress[16];

void DGUS_Screen_Main::Init()
{
	dserial.LoadScreen(SCREEN_MAIN);

	lasttemp_nozzle0 = -100;
	lasttemp_bed = -100;

	dserial.SendString_P(ADDR_MAIN_TEXT1, MMSG_MAIN_BUTTON1[wtvar_language], 20);
	dserial.SendString_P(ADDR_MAIN_TEXT2, MMSG_MAIN_BUTTON2[wtvar_language], 20);
	dserial.SendString_P(ADDR_MAIN_TEXT3, MMSG_MAIN_BUTTON3[wtvar_language], 20);
	dserial.SendString_P(ADDR_MAIN_TEXT4, MMSG_MAIN_BUTTON4[wtvar_language], 20);

	WT_Get_IP();
	ShowTemperature();
	ShowIP();

	holdontime = getcurrenttime();
	chktmpcount = 3;

	wt_timer.start();
}

void DGUS_Screen_Main::Update()
{
	ShowTemperature();

	if (wifiStatus != getIPAddress)
		ShowIP();

	if (checkcount < 0)
	{
		if (!getIPAddress)
			checkcount = 10;
		else
			checkcount = 60;
	}

	if (checkcount > 0)
		checkcount--;

	if (checkcount == 0)
	{
		WT_Get_IP();
		checkcount = -1;
	}
}

void DGUS_Screen_Main::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MAIN_KEY)
		{
			if (gltouchpara.value == KEY_MAIN_BUTTON1)
			{
				dgus.GotoSDMenu();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON2)
			{
				dgus.GotoPrepareMenu();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON3)
			{
				dgus.GotoControlMenu();
			}
			else if (gltouchpara.value == KEY_MAIN_BUTTON4)
			{
				dgus.GotoHelpMenu();
			}
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_Main::ShowTemperature(void)
{
	temp_nozzle0 = thermalManager.current_temperature[0];
	temp_bed = thermalManager.current_temperature_bed;

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_bed != temp_bed))
	{
		if (temp_nozzle0 >= 0)
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE, temp_nozzle0, 3);
		else
			dserial.SendString(ADDR_MAIN_TEXT_NOZZLE, 0, 3);

		if (temp_bed >= 0)
			dserial.SendString(ADDR_MAIN_TEXT_BED, temp_bed, 3);
		else
			dserial.SendString(ADDR_MAIN_TEXT_BED, 0, 3);
	}

	lasttemp_nozzle0 = temp_nozzle0;
	lasttemp_bed = temp_bed;
}

void DGUS_Screen_Main::ShowIP(void)
{
	if (getIPAddress)
	{
		dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_CONNECTED);

		dserial.SendString(ADDR_MAIN_TEXT_IP, ipAddress);
	}
	else
	{
		dserial.SendInt16(ADDR_MAIN_ICON_IP, ENUM_MAIN_IP_DISCONNECTED);

		dserial.SendString_P(ADDR_MAIN_TEXT_IP, MMSG_EMPTY, 20);
	}
	wifiStatus = getIPAddress;
}
