/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "configuration_store.h"
#include "WTDGUSScreen_Control.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_Control::Init()
{
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	pageid = 0;
	dserial.SendString_P(ADDR_SETTING_TEXT_TITLE, MMSG_SETTING_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
	clickCount = 0;

	WT_Get_ESP32Version();
	WT_Get_IP();
}

void DGUS_Screen_Control::Update()
{
	// do nothing
}

void DGUS_Screen_Control::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		gltouchpara.validflg = false;
		if (gltouchpara.address == ADDR_SETTING_KEY)
		{
			if (gltouchpara.value == KEY_SETTING_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_SETTING_NEXT)
			{
				ShowNextPage();
			}
			else if (gltouchpara.value == KEY_SETTING_PRE)
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM1)
			{
				if (pageid == 0)
				{
					dgus.GotoWifiSettingMenu();
				}
				else if (pageid == 1)
				{
					if (wtvar_enablepoweroff)
					{
						wtvar_enablepoweroff = 0;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
					}
					else
					{
						wtvar_enablepoweroff = 1;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
					}
					(void)settings.save();
				}
				else if (pageid == 2)
				{
					dgus.GotoRestoreSettingMenu();
				}
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{
					dgus.GotoLanguageMenu();
				}
				else if (pageid == 1)
				{
					if (wtvar_enableselftest)
					{
						wtvar_enableselftest = 0;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_OFF);
					}
					else
					{
						wtvar_enableselftest = 1;
						dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_ON);
					}
					(void)settings.save();
				}
				else if (pageid == 2)
				{
					
				}
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
				{
					dgus.GotoMachineInfoMenu();
				}
				else if (pageid == 1)
				{
					dgus.GotoPowerSaveMenu();
				}
				else if (pageid == 2)
				{
					clickCount++;
					if (clickCount >= 10)
					{
						clickCount = 0;
						dgus.GotoTestModeMenu();
					}
				}
			}
			else if (gltouchpara.value == KEY_SETTING_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_SETTING);
			}
		}
		
	}
}


void DGUS_Screen_Control::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_Control::ShowNextPage(void)
{
	if (pageid < 2)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_Control::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_WIFI);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_WIFI[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_LANGUAGE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_LANGUAGE[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_INFO);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_INFO[wtvar_language], 32);

	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		if (wtvar_enablepoweroff)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_POWEROFF);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_POWEROFF[wtvar_language], 32);

		if (wtvar_enableselftest)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_SELFTEST);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_SELFTEST[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_POWERSAVING);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_POWERSAVE[wtvar_language], 32);

	}
	else if (pageid == 2)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_EMPTY, 20);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_RESTORE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_RESTORE[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_NONE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_EMPTY, 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_NONE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_EMPTY, 32);

	}
}


void DGUS_Screen_Control::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);
	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP11_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP11_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP11_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP11_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP11_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, MMSG_EMPTY, 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP12_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP12_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP12_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP12_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP12_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP12_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP12_LINE7[wtvar_language], 60);
	}
	else if (pageid == 2)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP13_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP13_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP13_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, MMSG_EMPTY, 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, MMSG_EMPTY, 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, MMSG_EMPTY, 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}

}