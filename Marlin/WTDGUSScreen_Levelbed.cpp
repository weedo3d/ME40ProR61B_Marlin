/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/
#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Levelbed.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Levelbed::Init()
{
	dserial.LoadScreen(SCREEN_LEVEL);

	dserial.SendString_P(ADDR_LEVEL_TITLE, MMSG_LEVEL_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_LEVEL_TEXT_BUTTON1, MMSG_CANCEL[wtvar_language], 20);
	dserial.SendString_P(ADDR_LEVEL_TEXT_BUTTON2, MMSG_BEGIN[wtvar_language], 20);
	dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_BEGIN);
	dserial.SendString_P(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL0_LINE1[wtvar_language], 40);
	dserial.SendString_P(ADDR_LEVEL_TEXT_LINE2, MMSG_LEVEL0_LINE2[wtvar_language], 40);
	dserial.SendString_P(ADDR_LEVEL_TEXT_LINE3, MMSG_LEVEL0_LINE3[wtvar_language], 40);
	dserial.SendString_P(ADDR_LEVEL_TEXT_LINE4, MMSG_LEVEL0_LINE4[wtvar_language], 40);

	holdontime = getcurrenttime();
	levelbedmanuelsts = LBSE_NOTHING;
}

void DGUS_Screen_Levelbed::Update()
{
	switch (levelbedmanuelsts)
	{
	case LBSE_NOTHING:
		break;

	case LBSE_WAITHOME:
	{
		if (planner.has_blocks_queued() == false)
		{
			enqueue_and_echo_commands_P(PSTR("G1 Z10 F600"));
			enqueue_and_echo_commands_P(PSTR("G1 X10 Y10 F4000"));
			enqueue_and_echo_commands_P(PSTR("G1 Z0 F300"));

			levelbedmanuelsts = LBSE_WAIT1STPT;
		}
	}

	case LBSE_WAIT1STPT:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendString_P(ADDR_LEVEL_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS3);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL3_LINE1[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE2, MMSG_LEVEL3_LINE2[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE3, MMSG_LEVEL3_LINE3[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE4, MMSG_LEVEL3_LINE4[wtvar_language], 40);

			levelbedmanuelsts = LBSE_WAIT_INPUT1;
		}
	}
	break;

	case LBSE_WAIT2NDPT:
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS4);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL4_LINE1[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE2, MMSG_LEVEL4_LINE2[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE3, MMSG_LEVEL4_LINE3[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE4, MMSG_LEVEL2_LINE4[wtvar_language], 40);

			levelbedmanuelsts = LBSE_WAIT_INPUT2;
		}
		break;

	case LBSE_WAIT3RDPT:
	{
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS1);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL1_LINE1[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE2, MMSG_LEVEL1_LINE2[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE3, MMSG_LEVEL1_LINE3[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE4, MMSG_LEVEL1_LINE4[wtvar_language], 40);

			levelbedmanuelsts = LBSE_WAIT_INPUT3;
		}
	}
	break;

	case LBSE_WAIT4THPT:
		if (planner.has_blocks_queued() == false)
		{
			dserial.LoadScreen(SCREEN_LEVEL);
			dserial.SendInt16(ADDR_LEVEL_ICON, ENUM_LEVEL_POS2);
			dserial.SendString_P(ADDR_LEVEL_TEXT_BUTTON2, MMSG_END[wtvar_language], 20);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE1, MMSG_LEVEL2_LINE1[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE2, MMSG_LEVEL2_LINE2[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE3, MMSG_LEVEL2_LINE3[wtvar_language], 40);
			dserial.SendString_P(ADDR_LEVEL_TEXT_LINE4, MMSG_LEVEL4_LINE4[wtvar_language], 40);

			levelbedmanuelsts = LBSE_WAIT_INPUT4;
		}
		break;

	case LBSE_WAITCOMPELTE:
	{
		if (planner.has_blocks_queued() == false)
		{
			levelbedmanuelsts = LBSE_NOTHING;
			Goback();
		}
	}
	break;

	case LBSE_WAITCANCELLED:
	{
		if (planner.has_blocks_queued() == false)
		{
			levelbedmanuelsts = LBSE_NOTHING;
			Goback();
		}
	}
	break;

	default:
		break;
	}
}

void DGUS_Screen_Levelbed::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LEVEL_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_LEVEL_BUTTON2)
			{
				switch (levelbedmanuelsts)
				{
				case LBSE_NOTHING:
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G28\n"));
					enqueue_and_echo_commands_P(PSTR("G1 Z410 F600"));
					enqueue_and_echo_commands_P(PSTR("G28 Z"));
					levelbedmanuelsts = LBSE_WAITHOME;
					break;

				case LBSE_WAIT_INPUT1:
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G1 Z10 F600"));
					enqueue_and_echo_commands_P(PSTR("G1 X290 Y10 F4000"));
					enqueue_and_echo_commands_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT2NDPT;
					break;

				case LBSE_WAIT_INPUT2:
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G1 Z10 F600"));
					enqueue_and_echo_commands_P(PSTR("G1 X290 Y300 F4000"));
					enqueue_and_echo_commands_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT3RDPT;
					break;

				case LBSE_WAIT_INPUT3:
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G1 Z10 F600"));
					enqueue_and_echo_commands_P(PSTR("G1 X10 Y300 F4000"));
					enqueue_and_echo_commands_P(PSTR("G1 Z0 F300"));
					levelbedmanuelsts = LBSE_WAIT4THPT;
					break;

				case LBSE_WAIT_INPUT4:
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G1 Z50 F600"));
					enqueue_and_echo_commands_P(PSTR("G28 X Y"));
					levelbedmanuelsts = LBSE_WAITCOMPELTE;
					break;
				}
			}
			else if (gltouchpara.value == KEY_LEVEL_BUTTON1)
			{
				if (levelbedmanuelsts == LBSE_NOTHING)
				{
					Goback();
				}
				else
				{
					dgus.ShowMovingMessage();
					enqueue_and_echo_commands_P(PSTR("G1 Z50 F600"));
					enqueue_and_echo_commands_P(PSTR("G28 X Y"));
					levelbedmanuelsts = LBSE_WAITCANCELLED;
				}
			}
		}

	}
}
