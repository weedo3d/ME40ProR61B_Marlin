/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "power_loss_recovery.h"
#include "printcounter.h"
#include "WTDGUSScreen_SavePrinting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern float resume_position[XYZE];

void DGUS_Screen_SavePrinting::Init()
{
	dgus.ShowNoRetrunMessage_P(MMSG_SAVE_PRINTING[wtvar_language]);
	state = DSSP_CHKSTS;
	holdontime = getcurrenttime();
}

void DGUS_Screen_SavePrinting::Update()
{
	switch (state)
	{
	case DSSP_NOTHING:
		break;

	case DSSP_CHKSTS:
	{
		if (card.sdprinting)
			state = DSSP_PAUSEDSD;
		else
			state = DSSP_HASPAUSED;

		if (!++job_recovery_info.valid_head) ++job_recovery_info.valid_head; 
		job_recovery_info.valid_foot = job_recovery_info.valid_head;

	}
	break;

	case DSSP_PAUSEDSD:
	{
		card.pauseSDPrint();
		state = DSSP_WAITCLEARBUF;
	}
	break;

	case DSSP_WAITCLEARBUF:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			COPY(job_recovery_info.current_position, current_position);
			state = DSSP_GOSETPOS;
		}
	}
	break;

	case DSSP_HASPAUSED:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			COPY(job_recovery_info.current_position, resume_position);
			state = DSSP_GOSETPOS;
		}
	}
	break;

	case DSSP_GOSETPOS:
	{
		enqueue_and_echo_commands_P(PSTR("G28 R0 XY"));
		state = DSSP_WAITPOS;
	}
	break;

	case DSSP_WAITPOS:
	{
		if ((planner.has_blocks_queued() == false) && (commands_in_queue == 0))
		{
			state = DSSP_SAVEPARA;
		}
	}
	break;

	case DSSP_SAVEPARA:
	{

		job_recovery_info.active_hotend = active_extruder;

		COPY(job_recovery_info.target_temperature, thermalManager.target_temperature);

		job_recovery_info.target_temperature_bed = thermalManager.target_temperature_bed;

		job_recovery_info.cmd_queue_index_r = 0;
		job_recovery_info.commands_in_queue = 0;

		job_recovery_info.print_job_elapsed = print_job_timer.duration();

		card.getAbsFilename(job_recovery_info.sd_filename);
		job_recovery_info.sdpos = card.getIndex();

		card.openJobRecoveryFile(false);
		(void)card.saveJobRecoveryInfo();
	
		state = DSSP_SHUTNOW;

	}
	break;

	case DSSP_SHUTNOW:
	{
		wt_PowerOff();
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_SavePrinting::KeyProcess()
{
	// do nothing
}