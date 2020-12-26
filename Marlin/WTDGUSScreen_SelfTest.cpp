/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "WTDGUSScreen_SelfTest.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

#define NOZZLE_HEATING_WAITING		30000
#define BED_HEATING_WAITING			30000
#define NOOZLE_LOW_HEATING_TEMP		10
#define NOZZLE_HIGH_HEATING_TEMP	5
#define BED_LOW_HEATING_TEMP		3
#define BED_HIGH_HEATING_TEMP		2
#define NOZZLE_THRESHOLD			150
#define BED_THRESHOLD				50
#define XY_WAITING					25000
#define Z_WAITING					50000

void DGUS_Screen_SelfTest::Init()
{
	dserial.LoadScreen(SCREEN_MACHINE_INFO);
	holdontime = getcurrenttime();
	beginTime = getcurrenttime();
	axisTime = getcurrenttime();

	dserial.SendString_P(ADDR_MACHINE_TITLE, MMSG_SELF_TEST_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_MACHINE_BUTTON2, MMSG_SKIP[wtvar_language], 20);
	dserial.SendString_P(ADDR_MACHINE_ITEM1, MMSG_SELF_TEST_ITEM1[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM2, MMSG_SELF_TEST_ITEM2[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM3, MMSG_SELF_TEST_ITEM4[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM4, MMSG_SELF_TEST_ITEM5[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM5, MMSG_SELF_TEST_ITEM6[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_ITEM6, MMSG_EMPTY, 32);

	dserial.SendInt16(ADDR_MACHINE_ICON_HELP, ENUM_HELP_ICON_HELP);

	nozzleState = SNE_READING;
	temp_nozzle0 = thermalManager.current_temperature[0];
	if (temp_nozzle0 < -10)
	{
		dserial.SendString_P(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_VALUE1, MMSG_EMPTY, 30);
		nozzleState = SNE_ERROR;
	}
	else
	{
		if (temp_nozzle0 < NOZZLE_THRESHOLD)
			target_nozzle0 = temp_nozzle0 + NOOZLE_LOW_HEATING_TEMP;
		else
			target_nozzle0 = temp_nozzle0 + NOZZLE_HIGH_HEATING_TEMP;

		thermalManager.target_temperature[0] = target_nozzle0;

		dserial.SendString_P(ADDR_MACHINE_VALUE1, MMSG_SELF_TEST_HEATING[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_ERROR1, MMSG_EMPTY, 30);
		nozzleState = SNE_HEATING;
	}

	bedState = SBE_READING;
	temp_bed = thermalManager.current_temperature_bed;
	if (temp_bed < -10)
	{
		dserial.SendString_P(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_VALUE2, MMSG_EMPTY, 30);
		bedState = SBE_ERROR;
	}
	else
	{
		if (temp_bed < BED_THRESHOLD)
			target_bed = temp_bed + BED_LOW_HEATING_TEMP;
		else
			target_bed = temp_bed + BED_HIGH_HEATING_TEMP;

		thermalManager.target_temperature_bed = target_bed;

		dserial.SendString_P(ADDR_MACHINE_VALUE2, MMSG_SELF_TEST_HEATING[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_ERROR2, MMSG_EMPTY, 30);
		bedState = SBE_HEATING;
	}

	doxhome();	

	dserial.SendString_P(ADDR_MACHINE_ERROR3, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR4, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR5, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_MACHINE_ERROR6, MMSG_EMPTY, 30);
}

void DGUS_Screen_SelfTest::Update()
{
	temp_nozzle0 = thermalManager.current_temperature[0];
	temp_bed = thermalManager.current_temperature_bed;

	if (nozzleState == SNE_HEATING)
	{
		if ((beginTime + NOZZLE_HEATING_WAITING) > getcurrenttime())
		{
			if (temp_nozzle0 >= target_nozzle0)
			{
				dserial.SendString_P(ADDR_MACHINE_VALUE1, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				nozzleState = SNE_END;
				thermalManager.target_temperature[0] = 0;
			}
		}
		else
		{	
			dserial.SendString_P(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOHEAT[wtvar_language], 32);
			dserial.SendString_P(ADDR_MACHINE_VALUE1, MMSG_EMPTY, 30);
			nozzleState = SNE_ERROR;
			thermalManager.target_temperature[0] = 0;
		}
	}

	if (bedState == SBE_HEATING)
	{
		if ((beginTime + BED_HEATING_WAITING) > getcurrenttime())
		{
			if (temp_bed >= target_bed)
			{
				dserial.SendString_P(ADDR_MACHINE_VALUE2, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				bedState = SBE_END;
				thermalManager.target_temperature_bed = 0;
			}
		}
		else
		{	
			dserial.SendString_P(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOHEAT[wtvar_language], 32);
			dserial.SendString_P(ADDR_MACHINE_VALUE2, MMSG_EMPTY, 30);
			bedState = SBE_ERROR;
			thermalManager.target_temperature_bed = 0;
		}
	}

	if (axisState == SAE_XMOVING)
	{
		if ((axisTime + XY_WAITING) > getcurrenttime())
		{
			if (!READ(X_MIN_PIN))
			{
				dserial.SendString_P(ADDR_MACHINE_VALUE3, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				doyhome();
			}
		}
		else
		{	
			dserial.SendString_P(ADDR_MACHINE_ERROR3, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendString_P(ADDR_MACHINE_VALUE3, MMSG_EMPTY, 30);
			axisState = SAE_ERROR;
		}
	}
	else if (axisState == SAE_YMOVING)
	{
		if ((axisTime + XY_WAITING) > getcurrenttime())
		{
			if (!READ(Y_MIN_PIN))
			{
				dserial.SendString_P(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				dozhome();
			}
		}
		else
		{	
			dserial.SendString_P(ADDR_MACHINE_ERROR4, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendString_P(ADDR_MACHINE_VALUE4, MMSG_EMPTY, 30);
			axisState = SAE_ERROR;
		}
	}
	else if (axisState == SAE_ZMOVING)
	{
		if ((axisTime + Z_WAITING) > getcurrenttime())
		{
			if (!READ(Z_MIN_PIN))
			{
				dserial.SendString_P(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_PASS[wtvar_language], 32);
				axisState = SAE_END;
				enqueue_and_echo_commands_P(PSTR("G1 Z50 F500"));
			}
		}
		else
		{	
			dserial.SendString_P(ADDR_MACHINE_ERROR5, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
			dserial.SendString_P(ADDR_MACHINE_VALUE5, MMSG_EMPTY, 30);
			axisState = SAE_ERROR;
		}
	}

	if (nozzleState == SNE_END && bedState == SBE_END && axisState == SAE_END)
	{	
		enqueue_and_echo_commands_P(PSTR("M18"));
		dgus.QuitTestingMode();
		Goback();
	}
}

void DGUS_Screen_SelfTest::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_MACHINE_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_MACHINE_BUTTON2)
			{
				thermalManager.target_temperature[0] = 0;
				thermalManager.target_temperature_bed = 0;
				enqueue_and_echo_commands_P(PSTR("M18"));
				dgus.QuitTestingMode();
				Goback();
			}
			else if (gltouchpara.value == KEY_MACHINE_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_MACHINE_INFO);
			}
		}
	}
}

void DGUS_Screen_SelfTest::NozzleTempError(void)
{
	dserial.SendString_P(ADDR_MACHINE_ERROR1, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_VALUE1, MMSG_EMPTY, 30);
	nozzleState = SNE_ERROR;
}

void DGUS_Screen_SelfTest::BedTempError(void)
{
	dserial.SendString_P(ADDR_MACHINE_ERROR2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 32);
	dserial.SendString_P(ADDR_MACHINE_VALUE2, MMSG_EMPTY, 30);
	bedState = SBE_ERROR;
}

void DGUS_Screen_SelfTest::EndStopError(void)
{
	if (axisState == SAE_XMOVING)
	{
		dserial.SendString_P(ADDR_MACHINE_ERROR3, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_VALUE3, MMSG_EMPTY, 30);
	}
	else if (axisState == SAE_YMOVING)
	{
		dserial.SendString_P(ADDR_MACHINE_ERROR4, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_VALUE4, MMSG_EMPTY, 30);
	}
	else if (axisState == SAE_ZMOVING)
	{
		dserial.SendString_P(ADDR_MACHINE_ERROR5, MMSG_SELF_TEST_NOHOMING[wtvar_language], 32);
		dserial.SendString_P(ADDR_MACHINE_VALUE5, MMSG_EMPTY, 30);
	}
	axisState = SAE_ERROR;
}

void DGUS_Screen_SelfTest::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP05_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP05_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP05_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP05_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP05_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP05_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP05_LINE7[wtvar_language], 60);
}


void DGUS_Screen_SelfTest::doxhome(void)
{
	if (!READ(X_MIN_PIN))
	{
		dserial.SendString_P(ADDR_MACHINE_VALUE3, MMSG_SELF_TEST_PASS[wtvar_language], 32);
		doyhome();
	}
	else
	{
		
		dserial.SendString_P(ADDR_MACHINE_VALUE3, MMSG_SELF_TEST_MOVING[wtvar_language], 32);
		enqueue_and_echo_commands_P(PSTR("G28 X F2000"));
		axisState = SAE_XMOVING;
	}
}


void DGUS_Screen_SelfTest::doyhome(void)
{
	if (!READ(Y_MIN_PIN))
	{
		dserial.SendString_P(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_PASS[wtvar_language], 32);
		dozhome();
	}
	else
	{
		dserial.SendString_P(ADDR_MACHINE_VALUE4, MMSG_SELF_TEST_MOVING[wtvar_language], 32);
		
		enqueue_and_echo_commands_P(PSTR("G28 Y F2000"));
		axisState = SAE_YMOVING;
		axisTime = getcurrenttime();
	}
}


void DGUS_Screen_SelfTest::dozhome(void)
{
	if (!READ(Z_MIN_PIN))
	{
		dserial.SendString_P(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_PASS[wtvar_language], 32);
		axisState = SAE_END;
	}
	else
	{
		dserial.SendString_P(ADDR_MACHINE_VALUE5, MMSG_SELF_TEST_MOVING[wtvar_language], 32);
		
		enqueue_and_echo_commands_P(PSTR("G28 XY F2000"));
		enqueue_and_echo_commands_P(PSTR("G28 Z F500"));
		axisState = SAE_ZMOVING;
		axisTime = getcurrenttime();
	}
}