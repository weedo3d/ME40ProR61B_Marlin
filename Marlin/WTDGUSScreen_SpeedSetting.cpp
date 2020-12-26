/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSScreen_SpeedSetting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_Speed::Init()
{
	dserial.LoadScreen(SCREEN_SPEED_SETTING);
	holdontime = getcurrenttime();

	dserial.SendString_P(ADDR_SPEED_TEXT_TITLE, MMSG_SPEED_SETTING_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_SPEED_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString_P(ADDR_SPEED_TEXT_BUTTON2, MMSG_OK[wtvar_language], 20);
	dserial.SendString_P(ADDR_SPEED_TEXT1, MMSG_SPEED_VALUE1, 8);
	dserial.SendString_P(ADDR_SPEED_TEXT2, MMSG_SPEED_VALUE2, 8);
	dserial.SendString_P(ADDR_SPEED_TEXT3, MMSG_SPEED_VALUE3, 8);
	dserial.SendString_P(ADDR_SPEED_TEXT4, MMSG_SPEED_VALUE4, 8);
	dserial.SendString_P(ADDR_SPEED_TEXT5, MMSG_SPEED_VALUE5, 8);
	dserial.SendString_P(ADDR_SPEED_TEXT6, MMSG_SPEED_VALUE6, 8);

	dserial.SendInt16(ADDR_SPEED_ICON_HELP, ENUM_HELP_ICON_HELP);

	if (feedrate_percentage < 50)
		ShowButtonOn(1);
	else if (feedrate_percentage < 100)
		ShowButtonOn(2);
	else if (feedrate_percentage < 200)
		ShowButtonOn(3);
	else if (feedrate_percentage < 400)
		ShowButtonOn(4);
	else if (feedrate_percentage < 600)
		ShowButtonOn(5);
	else 
		ShowButtonOn(6);

	temp_feedrate = feedrate_percentage;
}

void DGUS_Screen_Speed::Update()
{
	// do nothing
}

void DGUS_Screen_Speed::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_SPEED_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_SPEED_BUTTON1)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON2)
			{
				feedrate_percentage = temp_feedrate;
				Goback();
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM1)
			{
				temp_feedrate = 25;
				ShowButtonOn(1);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM2)
			{
				temp_feedrate = 50;
				ShowButtonOn(2);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM3)
			{	
				temp_feedrate = 100;
				ShowButtonOn(3);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM4)
			{
				temp_feedrate = 200;
				ShowButtonOn(4);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM5)
			{
				temp_feedrate = 400;
				ShowButtonOn(5);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_ITEM6)
			{
				temp_feedrate = 600;
				ShowButtonOn(6);
			}
			else if (gltouchpara.value == KEY_SPEED_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_SPEED_SETTING);
			}
		}
	}
}

void DGUS_Screen_Speed::ShowButtonOn(uint8_t id)
{
	if (id == 1)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 2)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 3)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 4)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 5)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_ON);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_OFF);
	}
	else if (id == 6)
	{
		dserial.SendInt16(ADDR_SPEED_ICON1, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON2, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON3, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON4, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON5, ENUM_SPEED_ICON_OFF);
		dserial.SendInt16(ADDR_SPEED_ICON6, ENUM_SPEED_ICON_ON);
	}
}

void DGUS_Screen_Speed::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP04_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP04_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP04_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP04_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP04_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP04_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP04_LINE7[wtvar_language], 60);
}