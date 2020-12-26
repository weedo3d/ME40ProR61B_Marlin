/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "duration_t.h"
#include "printcounter.h"
#include "WTDGUSScreen_Status.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTCounter.h"
#include "WTHelpDoc.h"

void DGUS_Screen_Status::Init()
{
	dserial.LoadScreen(SCREEN_STATUS);

	lasttemp_nozzle0 = -100;
	lasttemp_bed = -100;
	percent_last = -1;
	lastfeedrate = -1;

	Update();

	if (card.sdprinting || wt_onlineprinting == SPARK_PRINTING)
	{
		dserial.SendString_P(ADDR_STATUS_TEXT_TITLE, MMSG_STATUS_TITLE_PRINTING[wtvar_language], 30);
		dserial.SendString_P(ADDR_STATUS_TEXT_BUTTON2, MMSG_PAUSE[wtvar_language], 20);
	}
	else
	{
		dserial.SendString_P(ADDR_STATUS_TEXT_TITLE, MMSG_STATUS_TITLE_PAUSE[wtvar_language], 30);
		dserial.SendString_P(ADDR_STATUS_TEXT_BUTTON2, MMSG_RESUME[wtvar_language], 20);
	}
	   	  	
	dserial.SendString_P(ADDR_STATUS_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], 20);
	dserial.SendString_P(ADDR_STATUS_TEXT_BUTTON3, MMSG_SETTING[wtvar_language], 20);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME1, MMSG_STATUS_LABEL_FILE[wtvar_language], 10);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME4, MMSG_STATUS_LABEL_SPEED[wtvar_language], 16);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME2, MMSG_STATUS_LABEL_NOZZLE[wtvar_language], 16);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME3, MMSG_STATUS_LABEL_BED[wtvar_language], 16);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME5, MMSG_STATUS_LABEL_ELAPSED[wtvar_language], 16);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME6, MMSG_STATUS_LABEL_REMAIN[wtvar_language], 16);
	dserial.SendString_P(ADDR_STATUS_TEXT_NAME7, MMSG_STATUS_LABEL_PERCENT[wtvar_language], 16);

	holdontime = getcurrenttime();

	wt_timer.stop();
}

void DGUS_Screen_Status::OutputTemp(uint16_t addr, int16_t temp)
{
	ZERO(b);
	sprintf_P(b, TEMP_STRING, temp);
	dserial.SendString(addr, b, 6);
}

void DGUS_Screen_Status::Update()
{
	temp_nozzle0 = thermalManager.current_temperature[0];
	temp_bed = thermalManager.current_temperature_bed;

	if ((lasttemp_nozzle0 != temp_nozzle0) || (lasttemp_bed != temp_bed))
	{
		if (temp_nozzle0 >= 0)
			OutputTemp(ADDR_STATUS_TEXT_VALUE2, temp_nozzle0);
		else
			OutputTemp(ADDR_STATUS_TEXT_VALUE2, 0);

		if (temp_bed >= 0)
			OutputTemp(ADDR_STATUS_TEXT_VALUE3, temp_bed);
		else
			OutputTemp(ADDR_STATUS_TEXT_VALUE3, 0);
	}

	lasttemp_nozzle0 = temp_nozzle0;
	lasttemp_bed = temp_bed;

	if (lastfeedrate != feedrate_percentage)
	{
		ZERO(b);
		sprintf_P(b, PSTR("%3d%%"), feedrate_percentage);
		dserial.SendString(ADDR_STATUS_TEXT_VALUE4, b, 4);
		lastfeedrate = feedrate_percentage;
	}

	if (wt_onlineprinting == SPARK_IDLE)
		percent_current = card.percentDone();
	else
		percent_current = progress_bar_percent;

	if (percent_current != percent_last)
	{
		ZERO(b);
		sprintf_P(b, PSTR("%3d%%"), percent_current);
		dserial.SendString(ADDR_STATUS_TEXT_VALUE7, b, 4);

		percent_progress = percent_current / 10;
		if (percent_progress > 10) percent_progress = 10;

		dserial.SendInt16(ADDR_STATUS_PERCENT, percent_progress);

		percent_last = percent_current;
	}

	ZERO(b);
	duration_t elapsed = print_job_timer.duration();
	bool has_days = (elapsed.value >= 60 * 60 * 24L);
	elapsed.toDigital(b, has_days);
	dserial.SendString(ADDR_STATUS_TEXT_VALUE5, b, 10);

	if (percent_current == 0)
	{
		dserial.SendString_P(ADDR_STATUS_TEXT_VALUE6, MMSG_UNKNOWN_TIME, 10);
	}
	else
	{
		ZERO(b);
		duration_t remained = elapsed.value * (100 - percent_current ) / percent_current;
		if (remained.value < 60)	
			remained.value = 60;
		has_days = (remained.value >= 60 * 60 * 24L);
		remained.toDigital(b, has_days);
		dserial.SendString(ADDR_STATUS_TEXT_VALUE6, b, 10);
	}

}

void DGUS_Screen_Status::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_STATUS_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_STATUS_RETURN)
			{
				ShowDialog();
			}
			else if (gltouchpara.value == KEY_STATUS_PAUSE)
			{
				if (wt_onlineprinting == SPARK_IDLE)
				{
					if (card.sdprinting)
						wt_sdcard_pause();
					else
						wt_sdcard_resume();
				}
				else if (wt_onlineprinting == SPARK_PRINTING)
				{
					wt_online_pause();
				}
				else
				{
					wt_online_resume();
				}
			}
			else if (gltouchpara.value == KEY_STATUS_SETTING)
			{
				if (wt_onlineprinting == SPARK_IDLE)			
					dgus.GotoPrintingSettingMenu();
			}
			else if (gltouchpara.value == KEY_STATUS_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_2BINFO_KEY)
		{	
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2BINFO_ITEM1)
			{	// cancel
				dserial.LoadScreen(SCREEN_STATUS);
			}
			else if (gltouchpara.value == KEY_2BINFO_ITEM2)
			{	// quit
				if (wt_onlineprinting == SPARK_IDLE)
					wt_sdcard_stop();
				else
					wt_online_cancel();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_STATUS);
			}
		}
	}
}

void DGUS_Screen_Status::ShowFilename(const char* fname)
{
	dserial.SendString(ADDR_STATUS_TEXT_VALUE1, fname);
}

void DGUS_Screen_Status::ShowDialog(void)
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString_P(ADDR_2BINFO_TITLE, MMSG_CONFIRM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], 20);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], 20);

	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE1, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE2, MMSG_QUIT_PRINT_CONFIRM_LINE2[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE3, MMSG_QUIT_PRINT_CONFIRM_LINE3[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE4, MMSG_QUIT_PRINT_CONFIRM_LINE4[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE5, MMSG_EMPTY, 50);
}

void DGUS_Screen_Status::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP02_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP02_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP02_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP02_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP02_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP02_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP02_LINE7[wtvar_language], 60);
}

