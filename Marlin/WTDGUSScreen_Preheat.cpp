/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Preheat.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

#define PREHEAT_TARGET_NOZZLE	200
#define PREHEAT_TARGET_BED		80

void DGUS_Screen_Preheat::Init()
{
	dserial.LoadScreen(SCREEN_TEMP_SETTING);

	lasttemp_nozzle0 = -100;
	lasttemp_bed = -100;

	dserial.SendString_P(ADDR_TEMP_TEXT_TITLE, MMSG_PREHEAT_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_TEMP_ICON_HELP, ENUM_HELP_ICON_HELP);
	dserial.SendString_P(ADDR_TEMP_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString_P(ADDR_TEMP_TEXT_BUTTON2, MMSG_OK[wtvar_language], 20);
	dserial.SendString_P(ADDR_TEMP_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE[wtvar_language], 16);
	dserial.SendString_P(ADDR_TEMP_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], 16);

	dserial.SendInt16(ADDR_TEMP_VALUE1, PREHEAT_TARGET_NOZZLE);
	dserial.SendInt16(ADDR_TEMP_VALUE2, PREHEAT_TARGET_BED);
	target_nozzle0 = PREHEAT_TARGET_NOZZLE;
	target_bed = PREHEAT_TARGET_BED;
	ShowTarget();

	isHeating = false;

	holdontime = getcurrenttime();
}

void DGUS_Screen_Preheat::Update()
{
	if (isHeating)
	{
		ShowTemperature();
	}
}

void DGUS_Screen_Preheat::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TEMP_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TEMP_BUTTON2)
			{
				thermalManager.target_temperature[0] = target_nozzle0;
				thermalManager.target_temperature_bed = target_bed;
				dserial.LoadScreen(SCREEN_PREHEAT_HEATING);
				dserial.SendString_P(ADDR_HEAT_TEXT_TITLE, MMSG_HEATING_TITLE[wtvar_language], 30);
				dserial.SendString_P(ADDR_HEAT_TEXT_BUTTON1, MMSG_SETTING[wtvar_language], 20);
				dserial.SendString_P(ADDR_HEAT_TEXT_BUTTON2, MMSG_CANCEL[wtvar_language], 20);
				dserial.SendString_P(ADDR_HEAT_TEXT_ITEM1, MMSG_STATUS_LABEL_NOZZLE[wtvar_language], 16);
				dserial.SendString_P(ADDR_HEAT_TEXT_ITEM2, MMSG_STATUS_LABEL_BED[wtvar_language], 16);

				begin_nozzle0 = thermalManager.current_temperature[0];
				begin_bed = thermalManager.current_temperature_bed;

				ShowTemperature();

				isHeating = true;

				
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON1)
			{
				thermalManager.target_temperature[0] = 0;
				thermalManager.target_temperature_bed = 0;
				Goback();
			}
			else if (gltouchpara.value == KEY_TEMP_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HEAT_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HEAT_BUTTON2)
			{
				thermalManager.target_temperature[0] = 0;
				thermalManager.target_temperature_bed = 0;
				Goback();
			}
			else if (gltouchpara.value == KEY_HEAT_BUTTON1)
			{
				isHeating = false;
				dserial.LoadScreen(SCREEN_TEMP_SETTING);
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
				dserial.LoadScreen(SCREEN_TEMP_SETTING);
			}
		}
	}
}

void DGUS_Screen_Preheat::ShowTemperature(void)
{
	temp_nozzle0 = thermalManager.current_temperature[0];
	temp_bed = thermalManager.current_temperature_bed;

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_bed != temp_bed))
	{
		ZERO(b);
		sprintf_P(b, TEMP_STRING, temp_nozzle0);
		dserial.SendString(ADDR_HEAT_TEXT_TEMP1, b, 8);

		ZERO(b);
		sprintf_P(b, TEMP_STRING, temp_bed);
		dserial.SendString(ADDR_HEAT_TEXT_TEMP2, b, 8);

		if (temp_nozzle0 < target_nozzle0 && begin_nozzle0 < target_nozzle0)
		{
			if (temp_nozzle0 > begin_nozzle0)
			{
				percent_nozzle0 = (temp_nozzle0 - begin_nozzle0) * 10 / (target_nozzle0 - begin_nozzle0);
				percent_nozzle0++;
				if (percent_nozzle0 > 10) percent_nozzle0 = 10;
			}
			else
				percent_nozzle0 = 0;
		}
		else
		{
			percent_nozzle0 = 10;
		}

		dserial.SendInt16(ADDR_HEAT_BAR_ITEM1, percent_nozzle0);

		if (temp_bed < target_bed && begin_bed < target_bed)
		{
			if (temp_bed > begin_bed)
			{
				percent_bed = (temp_bed - begin_bed) * 10 / (target_bed - begin_bed);
				percent_bed++;
				if (percent_bed > 10) percent_bed = 10;
			}
			else
				percent_bed = 0;
		}
		else
		{
			percent_bed = 10;
		}

		dserial.SendInt16(ADDR_HEAT_BAR_ITEM2, percent_bed);

	}

	lasttemp_nozzle0 = temp_nozzle0;
	lasttemp_bed = temp_bed;
}

void DGUS_Screen_Preheat::ShowTarget(void)
{
	ZERO(b);
	sprintf_P(b, TEMP_STRING, target_nozzle0);
	dserial.SendString(ADDR_TEMP_TEXT_VALUE1, b, 8);

	ZERO(b);
	sprintf_P(b, TEMP_STRING, target_bed);
	dserial.SendString(ADDR_TEMP_TEXT_VALUE2, b, 8);

}

void DGUS_Screen_Preheat::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP09_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP09_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP09_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP09_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP09_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP09_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP09_LINE7[wtvar_language], 60);
}