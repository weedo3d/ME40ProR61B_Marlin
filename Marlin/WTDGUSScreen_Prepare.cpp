/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Prepare.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_Prepare::Init()
{
	SERIAL_PROTOCOLLNPGM("load screen prepare");
	dserial.LoadScreen(SCREEN_SETTING);
	holdontime = getcurrenttime();
	pageid = 0;
	dserial.SendString_P(ADDR_SETTING_TEXT_TITLE, MMSG_PREPARE_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_SETTING_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_SETTING_ICON_HELP, ENUM_HELP_ICON_HELP);
	ShowPage();
}

void DGUS_Screen_Prepare::Update()
{
	// do nothing
}

void DGUS_Screen_Prepare::KeyProcess()
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
					dgus.GotoLoadFilament(this);
				else if (pageid == 1)
					dgus.GotoJobMenu();
				else if (pageid == 2)
					dgus.GotoProximityMenu();
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM2)
			{
				if (pageid == 0)
				{
					dgus.GotoUnloadFilament(this);
				}
				else if (pageid == 1)
				{
					dgus.GotoLevelMenu();
				}
				else if (pageid == 2)
				{
					dgus.ShowMessage_P(MMSG_MOTOROFF_LINE1[wtvar_language]);
					enqueue_and_echo_commands_P(PSTR("M84"));
				}
				
			}
			else if (gltouchpara.value == KEY_SETTING_ITEM3)
			{
				if (pageid == 0)
					dgus.GotoPreheatMenu();
				else if (pageid == 1)
					dgus.GotoZOffsetMenu();
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

void DGUS_Screen_Prepare::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_Prepare::ShowNextPage(void)
{
	if (pageid < 2)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_Prepare::ShowPage(void)
{
	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_FEED_IN);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_FEED[wtvar_language], 32);
		
		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_RETRACT);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_RETRACT[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_HEAT);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_HEAT[wtvar_language], 32);

	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language]);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_JOB);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_JOG[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_LEVELBED);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_LEVELBED[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_ZOFFSET);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_SETTING_ZOFFSET[wtvar_language], 32);

	}
	else if (pageid == 2)
	{
		dserial.SendString_P(ADDR_SETTING_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_SETTING_TEXT_NEXT, MMSG_EMPTY, 20);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM1, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM1, ENUM_SETTING_SENSOR);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM1, MMSG_SETTING_SENSOR[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM2, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM2, ENUM_SETTING_MOTOROFF);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM2, MMSG_SETTING_MOTOROFF[wtvar_language], 32);

		dserial.SendInt16(ADDR_SETTING_ICON_ITEM3, ENUM_OPTION_NONE);
		dserial.SendInt16(ADDR_SETTING_IMG_ITEM3, ENUM_SETTING_NONE);
		dserial.SendString_P(ADDR_SETTING_TEXT_ITEM3, MMSG_EMPTY, 32);

	}
}

void DGUS_Screen_Prepare::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);
	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP06_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP06_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP06_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP06_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP06_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP06_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP07_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP07_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP07_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP07_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP07_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP07_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP07_LINE7[wtvar_language], 60);
	}
	else if (pageid == 2)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP08_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP08_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP08_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP08_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP08_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP08_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}

}