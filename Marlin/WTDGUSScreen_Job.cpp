/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSScreen_Job.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_Job::Init()
{
	dserial.LoadScreen(SCREEN_JOB);
	holdontime = getcurrenttime();
	
	dserial.SendString_P(ADDR_JOB_TEXT_TITLE, MMSG_JOB_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_JOB_TEXT_BUTTON1, MMSG_RETURN_HOME[wtvar_language], 20);
	dserial.SendString_P(ADDR_JOB_TEXT_BUTTON2, MMSG_BACK[wtvar_language], 20);
}

void DGUS_Screen_Job::Update()
{
	// do nothing
}

void DGUS_Screen_Job::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		gltouchpara.validflg = false;
		if (gltouchpara.address == ADDR_JOB_XADD1)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X-1 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_XADD2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X-10 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_XADD3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X-50 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC1)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X1 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X10 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_XDEC3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 X50 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YADD1)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y1 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YADD2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y10 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YADD3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y50 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC1)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y-1 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y-10 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_YDEC3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Y-50 F1000"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD1)
		{	
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z0.1 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z1 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZADD3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z10 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC1)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z-0.1 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC2)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z-1 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_ZDEC3)
		{
			enqueue_and_echo_commands_P(PSTR("M211 S0"));
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z-10 F200"));
			enqueue_and_echo_commands_P(PSTR("M211 S1"));
		}
		else if (gltouchpara.address == ADDR_JOB_KEY)
		{
			if (gltouchpara.value == KEY_JOB_BUTTON2)
			{
				enqueue_and_echo_commands_P(PSTR("G90"));
				Goback();
			}
			else if (gltouchpara.value == KEY_JOB_BUTTON1)
			{
				enqueue_and_echo_commands_P(PSTR("G28"));
			}
			else if (gltouchpara.value == KEY_JOB_BUTTON_HELP)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_JOB);
			}
		}
	}
}

void DGUS_Screen_Job::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP10_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP10_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP10_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP10_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP10_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP10_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP10_LINE7[wtvar_language], 60);
}