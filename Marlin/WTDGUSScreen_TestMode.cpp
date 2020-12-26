/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_TestMode.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

#define STRING_ON	"on "
#define STRING_OFF	"off"

void DGUS_Screen_TestMode::Init()
{
	dserial.LoadScreen(SCREEN_TEST_MODE);

	ShowEndstop();
	updaterate = 500;
}

void DGUS_Screen_TestMode::Update()
{
	ShowEndstop();
}

void DGUS_Screen_TestMode::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TESTMODE_KEY)
		{
			if (gltouchpara.value == KEY_TESTMODE_X_RUN)
			{	
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 X1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_X_BACK)
			{	
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 X-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_RUN)
			{	
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 Y1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Y_BACK)
			{	
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 Y-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_RUN)
			{	
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 Z1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_Z_BACK)
			{	
				enqueue_and_echo_commands_P(PSTR("G1 Z-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_RUN)
			{	
				enqueue_and_echo_commands_P(PSTR("M302 P1"));
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 E1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_A_BACK)
			{	
				enqueue_and_echo_commands_P(PSTR("M302 P1"));
				enqueue_and_echo_commands_P(PSTR("G91"));
				enqueue_and_echo_commands_P(PSTR("G1 E-1"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_ON)
			{	
				wt_OpenExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_4020_OFF)
			{	
				wt_CloseExtruder0Fan();
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_ON)
			{	
				enqueue_and_echo_commands_P(PSTR("M106"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_5015_OFF)
			{	
				enqueue_and_echo_commands_P(PSTR("M107"));
			}
			else if (gltouchpara.value == KEY_TESTMODE_POWEROFF)
			{	
				wt_PowerOff();
			}
			else if (gltouchpara.value == KEY_TESTMODE_BACK)
			{	
				Goback();
			}
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_TestMode::ShowEndstop(void)
{
	if (READ(X_MIN_PIN))
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_X, PSTR(STRING_ON));
	else
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_X, PSTR(STRING_OFF));

	if (READ(Y_MIN_PIN))
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_Y, PSTR(STRING_ON));
	else
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_Y, PSTR(STRING_OFF));

	if (READ(Z_MIN_PIN))
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_Z, PSTR(STRING_ON));
	else
		dserial.SendString_P(ADDR_TESTMODE_ENDSTOP_Z, PSTR(STRING_OFF));

	if (READ(Z_MIN_PIN))
		dserial.SendString_P(ADDR_TESTMODE_HALL, PSTR(STRING_OFF));
	else
		dserial.SendString_P(ADDR_TESTMODE_HALL, PSTR(STRING_ON));

	if (READ(FIL_RUNOUT_PIN))
		dserial.SendString_P(ADDR_TESTMODE_BREAK, PSTR(STRING_OFF));
	else
		dserial.SendString_P(ADDR_TESTMODE_BREAK, PSTR(STRING_ON));
}