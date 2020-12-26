/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "power_loss_recovery.h"
#include "WTDGUSScreen_ResumePrinting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_ResumePrinting::Init()
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString_P(ADDR_2BINFO_TITLE, MMSG_CONFIRM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], 20);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], 20);

	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE1, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE2, MMSG_RESUME_LINE1[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE3, MMSG_RESUME_LINE2[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE4, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE5, MMSG_EMPTY, 50);
	state = DSEP_NOTHING;
	holdontime = getcurrenttime();
}

void DGUS_Screen_ResumePrinting::Update()
{
	char headgcode[40] = { 0 }, flchar[10] = { 0 };

	switch (state)
	{
	case DSEP_START:
	{
		enqueue_and_echo_commands_P(PSTR("G28 R0 XY"));
		enqueue_and_echo_commands_P(PSTR("M420 S1"));
		//enqueue_and_echo_commands_P(PSTR("M420 V"));
		state = DSEP_HEATING;

	}
	break;

	case DSEP_HEATING:
	{
		thermalManager.target_temperature[0] = job_recovery_info.target_temperature[0];
		thermalManager.target_temperature_bed = job_recovery_info.target_temperature_bed;
		state = DSEP_WAITHEATING;
	}
	break;

	case DSEP_WAITHEATING:
	{
		if ((thermalManager.current_temperature[0] >= thermalManager.target_temperature[0] - 2) &&
			(thermalManager.current_temperature[0] <= thermalManager.target_temperature[0] + 2) &&
			(thermalManager.current_temperature[0] > 180))
		{
			state = DSEP_GOHOME;
		}
	}
	break;

	case DSEP_GOHOME:
	{
		set_destination_from_current();
		destination[E_CART] += 20 / planner.e_factor[active_extruder];
		planner.buffer_line_kinematic(destination, 3, active_extruder);
		set_current_from_destination();

		state = DSEP_WAITGOHOME;
	}
	break;

	case DSEP_WAITGOHOME:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			state = DSEP_SETPOS;
		}
	}
	break;

	case DSEP_SETPOS:
	{
		ZERO(headgcode);
		strcat_P(headgcode, PSTR("G92 Z"));
		dtostrf(job_recovery_info.current_position[Z_AXIS] + job_recovery_info.zoffset, 3, 3, flchar);
		strcat(headgcode, flchar);

		enqueue_and_echo_command(headgcode);

		ZERO(headgcode);
		strcat_P(headgcode, PSTR("G92 E"));
		dtostrf(job_recovery_info.current_position[E_CART], 3, 3, flchar);
		strcat(headgcode, flchar);
		enqueue_and_echo_command(headgcode);

		r = job_recovery_info.cmd_queue_index_r;
		c = job_recovery_info.commands_in_queue;
		state = DSEP_WAITBUFFER;
	}
	break;

	case DSEP_WAITSETPOS:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			while (c--)
			{
				enqueue_and_echo_command(job_recovery_info.command_queue[r]);
				r = (r + 1) % BUFSIZE;
			}
			state = DSEP_WAITBUFFER;			
		}
	}
	break;

	case DSEP_WAITBUFFER:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			state = DSEP_OPENFILE;
		}
	}
	break;


	case DSEP_OPENFILE:
	{
		memset(headgcode, 0, sizeof(headgcode));
		sprintf_P(headgcode, PSTR("M23 %s"), job_recovery_info.sd_filename);
		enqueue_and_echo_command(headgcode);

		memset(headgcode, 0, sizeof(headgcode));
		sprintf_P(headgcode, PSTR("M24 S%ld T%ld"), job_recovery_info.sdpos, job_recovery_info.print_job_elapsed);
		enqueue_and_echo_command(headgcode);

		state = DSEP_COMPLETE;
	}
	break;

	case DSEP_COMPLETE:
	{
		state = DSEP_NOTHING;
		dgus.GotoStatusMenu();
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_ResumePrinting::KeyProcess()
{
	if (gltouchpara.address == ADDR_2BINFO_KEY)
	{	
		gltouchpara.validflg = false;
		if (gltouchpara.value == KEY_2BINFO_ITEM1)
		{	// NO
			card.removeJobRecoveryFile();
			card.autostart_index = 0;
			dgus.GotoMain();
		}
		else if (gltouchpara.value == KEY_2BINFO_ITEM2)
		{	// YES
			state = DSEP_START;
			dgus.ShowNoRetrunMessage_P(MMSG_RESUME_PRINTING[wtvar_language]);
		}
	}
}
