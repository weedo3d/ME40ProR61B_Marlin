/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "configuration_store.h"
#include "WTDGUSScreen_PrintingSetting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_PrintingSetting::Init()
{
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	pageid = 0;
	dserial.SendString_P(ADDR_SETTING_TEXT_TITLE, MMSG_PRINTINT_SETTING_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
}

void DGUS_Screen_PrintingSetting::Update()
{
	// do nothing
}

void DGUS_Screen_PrintingSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_SETTING_KEY)
		{	
			gltouchpara.validflg = false;
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
					if (card.sdprinting)
					{
						dgus.ShowMessageRetrun_P(MMSG_NOTICE_TITLE[wtvar_language],
						MMSG_BACK[wtvar_language],
						MMSG_EMPTY, 
						MMSG_EMPTY, 
						MMSG_PRINTING_NOTICE[wtvar_language],
						MMSG_EMPTY, 
						MMSG_EMPTY, 
						MMSG_EMPTY, 
						MMSG_EMPTY);
					}
					else
						ShowFilamentOption();
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
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{
					ShowTempSetting();
				}
				else if (pageid == 1)
				{
					dgus.GotoSavePrintingMenu();
				}

			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
				{
					dgus.GotoSpeedSettingMenu();
				}
				else if (pageid == 1)
				{
					
				}
			}
			else if (gltouchpara.value == KEY_SETTING_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_2OPTION_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2OPTION_BUTTON_RETURN)
			{
				dserial.LoadScreen(SCREEN_SETTING);
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM1)
			{
				dgus.GotoLoadFilament(this);
			}
			else if (gltouchpara.value == KEY_2OPTION_BUTTON_ITEM2)
			{
				dgus.GotoUnloadFilament(this);
			}
		}
		else if (gltouchpara.address == ADDR_TEMP_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TEMP_BUTTON2)
			{
				thermalManager.target_temperature[0] = target_nozzle0;
				thermalManager.target_temperature_bed = target_bed;

				dserial.LoadScreen(SCREEN_SETTING);
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON1)
			{
				dserial.LoadScreen(SCREEN_SETTING);
			}
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE1)
		{	
			gltouchpara.validflg = false;
			target_nozzle0 = gltouchpara.value;
			ShowTarget();
		}
		else if (gltouchpara.address == ADDR_TEMP_VALUE2)
		{	
			gltouchpara.validflg = false;
			target_bed = gltouchpara.value;
			ShowTarget();
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


void DGUS_Screen_PrintingSetting::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_PrintingSetting::ShowNextPage(void)
{
	if (pageid < 1)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_PrintingSetting::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_FILAMENT);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_FILAMENT[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_TEMP);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_TEMP[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_SPEED);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_SPEED[wtvar_language], 32);

	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_EMPTY, 20);
		if (wtvar_enablepoweroff)
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_ON);
		else
			dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_OFF);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_POWEROFF);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_POWEROFF[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_SAVE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_SAVE[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_NONE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_EMPTY, 32);

	}
}

void DGUS_Screen_PrintingSetting::ShowFilamentOption(void)
{
	dserial.LoadScreen(SCREEN_2OPTION);

	dserial.SendString_P(ADDR_2OPTION_TEXT_TITLE, MMSG_FILAMENT_OPERATION_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_2OPTION_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_2OPTION_TEXT_BUTTON1, MMSG_SETTING_FEED[wtvar_language], 20);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON1, ENUM_SETTING_FEED_IN);

	dserial.SendString_P(ADDR_2OPTION_TEXT_BUTTON2, MMSG_SETTING_RETRACT[wtvar_language], 20);
	dserial.SendInt16(ADDR_2OPTION_ICON_BUTTON2, ENUM_SETTING_RETRACT);

}

void DGUS_Screen_PrintingSetting::ShowTempSetting(void)
{
	dserial.LoadScreen(SCREEN_TEMP_SETTING);

	dserial.SendString_P(ADDR_TEMP_TEXT_TITLE, MMSG_PREHEAT_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_TEMP_ICON_HELP, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_TEMP_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString_P(ADDR_TEMP_TEXT_BUTTON2, MMSG_OK[wtvar_language], 20);
	dserial.SendString_P(ADDR_TEMP_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE[wtvar_language], 16);
	dserial.SendString_P(ADDR_TEMP_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], 16);

	target_nozzle0 = thermalManager.target_temperature[0];
	target_bed = thermalManager.target_temperature_bed;

	dserial.SendInt16(ADDR_TEMP_VALUE1, target_nozzle0);
	dserial.SendInt16(ADDR_TEMP_VALUE2, target_bed);
	
	ShowTarget();
}

void DGUS_Screen_PrintingSetting::ShowTarget(void)
{
	char b[8];

	memset(b, 0, 8);
	sprintf_P(b, TEMP_STRING, target_nozzle0);
	dserial.SendString(ADDR_TEMP_TEXT_VALUE1, b, 8);

	memset(b, 0, 8);
	sprintf_P(b, TEMP_STRING, target_bed);
	dserial.SendString(ADDR_TEMP_TEXT_VALUE2, b, 8);

}

void DGUS_Screen_PrintingSetting::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP03_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP03_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP03_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP03_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP03_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP03_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP03_LINE7[wtvar_language], 60);
}
