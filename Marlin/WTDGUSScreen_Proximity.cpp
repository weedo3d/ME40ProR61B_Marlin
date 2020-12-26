/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "planner.h"
#include "WTDGUSScreen_Proximity.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Proximity::Init()
{
	dserial.SendString_P(ADDR_INFO_TITLE, MMSG_POXIMITY_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_INFO_RETURN, MMSG_BACK[wtvar_language], 20);
	dserial.SendString_P(ADDR_INFO_LINE1, MMSG_POXIMITY_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_INFO_LINE2, MMSG_POXIMITY_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_INFO_LINE3, MMSG_POXIMITY_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_INFO_LINE4, MMSG_POXIMITY_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_INFO_LINE5, MMSG_SWITCH_OFF[wtvar_language], 60);

	dgus.ShowMovingMessage();
	enqueue_and_echo_commands_P(PSTR("G28"));
	enqueue_and_echo_commands_P(PSTR("G1 X100 Y80 F3000"));
	enqueue_and_echo_commands_P(PSTR("G1 Z10 F500"));
	enqueue_and_echo_commands_P(PSTR("G1 Z0 F100"));

	holdontime = getcurrenttime();
	updaterate = 1000;
	zState = PSE_BEGIN;
}

void DGUS_Screen_Proximity::Update()
{
	switch (zState)
	{
	case PSE_BEGIN:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_INFO);
			zState = PSE_INPUT;
		}
	}
	break;

	case PSE_INPUT:
		if (READ(Z_MIN_PIN))
			dserial.SendString_P(ADDR_INFO_LINE5, MMSG_SWITCH_OFF[wtvar_language], 60);
		else
			dserial.SendString_P(ADDR_INFO_LINE5, MMSG_SWITCH_ON[wtvar_language], 60);
		break;

	case PSE_END:
		if (planner.has_blocks_queued() == false)
		{
			Goback();
		}

	default:
		break;
	}
}

void DGUS_Screen_Proximity::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_INFO_RETURN)
			{
				dgus.ShowMovingMessage();
				enqueue_and_echo_commands_P(PSTR("G28"));
				enqueue_and_echo_commands_P(PSTR("M18"));
				zState = PSE_END;
			}
		}
	}
}
