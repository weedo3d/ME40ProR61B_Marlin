/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "configuration_store.h"
#include "WTDGUSScreen_ZOffset.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_ZOffset::manual_move_to_current(AxisEnum axis)
{
	manual_move_start_time = millis();
	manual_move_axis = (int8_t)axis;
}

void DGUS_Screen_ZOffset::manage_manual_move() 
{

	if (manual_move_axis != (int8_t)NO_AXIS && ELAPSED(millis(), manual_move_start_time) && !planner.is_full()) 
	{
		planner.buffer_line_kinematic(current_position, planner.max_feedrate_mm_s[Z_AXIS], active_extruder);
		manual_move_axis = (int8_t)NO_AXIS;
	}
}

void DGUS_Screen_ZOffset::Init()
{
	dgus.ShowMovingMessage();
	enqueue_and_echo_commands_P(PSTR("G28\nG29\nG1 X150 Y150 F2000\nG1 Z0 F200"));

	dserial.SendString_P(ADDR_ZOFFSET_TEXT_TITLE, MMSG_ZOFFSET_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_ZOFFSET_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString_P(ADDR_ZOFFSET_TEXT_BUTTON2, MMSG_SAVE[wtvar_language], 20);
	dserial.SendString_P(ADDR_ZOFFSET_TEXT_LINE1, MMSG_ZOFFSET_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_ZOFFSET_TEXT_LINE2, MMSG_ZOFFSET_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_ZOFFSET_TEXT_LINE3, MMSG_ZOFFSET_LINE3[wtvar_language], 60);

	holdontime = getcurrenttime();
	updaterate = 200;
	zState = ZOSE_BEGIN;
	zoffset_current = zprobe_zoffset;
	manual_move_start_time = 0;
	manual_move_axis = (int8_t)NO_AXIS;
	ShowZOffset();
}

void DGUS_Screen_ZOffset::Update()
{
	switch (zState)
	{
	case ZOSE_BEGIN:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_ZOFFSET);
			zState = ZOSE_INPUT;
			zoffset_beginZpos = current_position[Z_AXIS];
		}
	}
	break;

	case ZOSE_INPUT:
		manage_manual_move();
		break;

	default:
		break;
	}
}

void DGUS_Screen_ZOffset::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_ZOFFSET_KEY)
		{
			if (gltouchpara.value == KEY_ZOFFSET_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_SAVE)
			{
				zprobe_zoffset = zoffset_current;
				(void)settings.save();
				enqueue_and_echo_commands_P(PSTR("G1 Z50 F200"));
				Goback();

			}
			else if (gltouchpara.value == KEY_ZOFFSET_DEC)
			{
				zoffset_current -= 0.1;
				if (zoffset_current >= -9.9) 
					current_position[Z_AXIS] -= 0.1;
				else
					zoffset_current = -9.9;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			else if (gltouchpara.value == KEY_ZOFFSET_ADD)
			{
				zoffset_current += 0.1;
				if (zoffset_current <= 9.9)
					current_position[Z_AXIS] += 0.1;
				else
					zoffset_current = 9.9;
				manual_move_to_current(Z_AXIS);
				ShowZOffset();
			}
			
		}
		gltouchpara.validflg = false;
	}
}

void DGUS_Screen_ZOffset::ShowZOffset(void)
{
	char a[6];
	memset(a, 0, 6);
	dtostrf(zoffset_current, 2, 1, a);
	dserial.SendString(ADDR_ZOFFSET_TEXT_VALUE, a, 6);
}