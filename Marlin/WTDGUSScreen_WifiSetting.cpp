/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_WifiSetting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern char ipAddress[16];
extern char esp32_version[8];

void DGUS_Screen_WifiSetting::Init()
{
	dserial.LoadScreen(SCREEN_WIFI_SETTING);
	holdontime = getcurrenttime();
	WT_Get_ESP32Version();
	WT_Get_IP();

	dserial.SendString_P(ADDR_WIFI_TITLE, MMSG_MACHINE_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_WIFI_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_WIFI_ITEM1, MMSG_WIFI_CONFIG_ITEM1[wtvar_language], 32);
	dserial.SendString(ADDR_WIFI_VALUE1, esp32_version, 16);

	dserial.SendString_P(ADDR_WIFI_ITEM2, MMSG_WIFI_CONFIG_ITEM2[wtvar_language], 32);
	dserial.SendString(ADDR_WIFI_VALUE2, ipAddress, 16);

	dserial.SendString_P(ADDR_WIFI_CONFIG, MMSG_WIFI_CONFIG[wtvar_language], 48);
	dserial.SendString_P(ADDR_WIFI_OTA, MMSG_WIFI_OTA[wtvar_language], 48);
}

void DGUS_Screen_WifiSetting::Update()
{
	dserial.SendString(ADDR_MACHINE_VALUE1, esp32_version, 16);
	dserial.SendString(ADDR_MACHINE_VALUE2, ipAddress, 16);
}

void DGUS_Screen_WifiSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_WIFIE_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_WIFI_BUTTON_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_WIFI_BUTTON_CONFIG)
			{
				dgus.GotoSmartConfigMenu();
			}
			else if (gltouchpara.value == KEY_WIFI_BUTTON_OTA)
			{
				dgus.GotoOTAMenu();
			}
		}
	}
}