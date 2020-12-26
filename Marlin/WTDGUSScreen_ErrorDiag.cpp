/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/
#include "Marlin.h"
#include "temperature.h"
#include "planner.h"
#include "WTDGUSScreen_ErrorDiag.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_ErrorDiag::Init()
{
	dserial.LoadScreen(SCREEN_HELP2);
	holdontime = getcurrenttime();
	updaterate = 500;

	pageid = 1;

	ShowPage();
}

void DGUS_Screen_ErrorDiag::Update()
{
	switch (pageid)
	{
	case 2:
	case 4:
	case 6:
		if (planner.has_blocks_queued() == false && moving)
		{
			moving = 0;
			dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 3:
		if (READ(X_MIN_PIN) && moving)
		{
			moving = 0;
			dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 5:
		if (READ(Y_MIN_PIN) && moving)
		{
			moving = 0;
			dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 7:
		if (READ(Z_MIN_PIN) && moving)
		{
			moving = 0;
			dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_NEXT[wtvar_language], 20);
		}
		break;

	case 8:
		if (thermalManager.current_temperature[0] > 208 && moving)
		{
			moving = 0;
			dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_END[wtvar_language], 20);

			enqueue_and_echo_commands_P(PSTR("G92 E0"));
			enqueue_and_echo_commands_P(PSTR("G1 E50 F200"));
			enqueue_and_echo_commands_P(PSTR("M104 S0"));

			ShowDialog(DIAG_PAGE9_TITLE[wtvar_language],
				DIAG_PAGE9_LINE2[wtvar_language],
				DIAG_PAGE9_LINE3[wtvar_language],
				DIAG_PAGE9_LINE4[wtvar_language],
				DIAG_PAGE9_LINE5[wtvar_language],
				MMSG_EMPTY,
				DIAG_PAGE9_LINE7[wtvar_language],
				MMSG_EMPTY);
		}
		else if (moving)
		{
			temp_nozzle0 = thermalManager.current_temperature[0];
			dserial.SendString(ADDR_HELP2_TEXT_LINE4, temp_nozzle0, 3);
		}

		break;

	default:
		break;
	}
	
}

void DGUS_Screen_ErrorDiag::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELP2_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP2_BUTTON1)
			{
				Finish();
			}
			else if (gltouchpara.value == KEY_HELP2_BUTTON2)
			{
				if (pageid == 1)
				{
					pageid = 2;
					ShowPage();

				}
				else if (pageid == 2 && moving == 0)
				{
					pageid = 3;
					ShowPage();
				}
				else if (pageid == 3 && moving == 0)
				{
					pageid = 4;
					ShowPage();
				}
				else if (pageid == 4 && moving == 0)
				{
					pageid = 5;
					ShowPage();
				}
				else if (pageid == 5 && moving == 0)
				{
					pageid = 6;
					ShowPage();
				}
				else if (pageid == 6 && moving == 0)
				{
					pageid = 7;
					ShowPage();
				}
				else if (pageid == 7 && moving == 0)
				{
					pageid = 8;
					ShowPage();
				}
				else if (pageid == 8 && moving == 0)
				{
					pageid = 9;
					ShowPage();
				}
				else if (pageid == 9 && moving == 0)
				{
					Finish();
				}
			}
		}
	}
}

void DGUS_Screen_ErrorDiag::ShowPage(void)
{
	if (pageid == 1)
	{	
		enqueue_and_echo_commands_P(PSTR("M84"));

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON1, MMSG_EXIT[wtvar_language], 20);
		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_BEGIN[wtvar_language], 20);

		ShowDialog(DIAG_PAGE1_TITLE[wtvar_language],
			DIAG_PAGE1_LINE1[wtvar_language], 
			DIAG_PAGE1_LINE2[wtvar_language],
			DIAG_PAGE1_LINE3[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);

	}
	else if (pageid == 2)
	{	
		enqueue_and_echo_commands_P(PSTR("M211 S0"));
		enqueue_and_echo_commands_P(PSTR("M121"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 X-50 F1000"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 X50"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY, 20);

		ShowDialog(DIAG_PAGE1_TITLE[wtvar_language],
			DIAG_PAGE2_LINE1[wtvar_language],
			DIAG_PAGE2_LINE2[wtvar_language],
			DIAG_PAGE2_LINE3[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);

	}
	else if (pageid == 3)
	{	
		enqueue_and_echo_commands_P(PSTR("M211 S1"));
		enqueue_and_echo_commands_P(PSTR("M120"));
		enqueue_and_echo_commands_P(PSTR("G28 X"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY, 20);

		ShowDialog(DIAG_PAGE3_TITLE[wtvar_language],
			DIAG_PAGE3_LINE1[wtvar_language],
			DIAG_PAGE3_LINE2[wtvar_language],
			DIAG_PAGE3_LINE3[wtvar_language],
			DIAG_PAGE3_LINE4[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);
	}
	else if (pageid == 4)
	{	
		enqueue_and_echo_commands_P(PSTR("M211 S0"));
		enqueue_and_echo_commands_P(PSTR("M121"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 Y-50 F1000"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 Y50"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY, 20);

		ShowDialog(DIAG_PAGE4_TITLE[wtvar_language],
			DIAG_PAGE4_LINE1[wtvar_language],
			DIAG_PAGE4_LINE2[wtvar_language],
			DIAG_PAGE4_LINE3[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);
	}
	else if (pageid == 5)
	{	
		enqueue_and_echo_commands_P(PSTR("M211 S1"));
		enqueue_and_echo_commands_P(PSTR("M120"));
		enqueue_and_echo_commands_P(PSTR("G28 Y"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY, 20);

		ShowDialog(DIAG_PAGE5_TITLE[wtvar_language],
			DIAG_PAGE5_LINE1[wtvar_language],
			DIAG_PAGE5_LINE2[wtvar_language],
			DIAG_PAGE5_LINE3[wtvar_language],
			DIAG_PAGE5_LINE4[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);
	}
	else if (pageid == 6)
	{
		enqueue_and_echo_commands_P(PSTR("M211 S0"));
		enqueue_and_echo_commands_P(PSTR("M121"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 Z100 F500"));
		enqueue_and_echo_commands_P(PSTR("G91"));
		enqueue_and_echo_commands_P(PSTR("G1 Z-50"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY_10, 20);

		ShowDialog(DIAG_PAGE6_TITLE[wtvar_language],
			DIAG_PAGE6_LINE1[wtvar_language],
			DIAG_PAGE6_LINE2[wtvar_language],
			DIAG_PAGE6_LINE3[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);
	}
	else if (pageid == 7)
	{
		enqueue_and_echo_commands_P(PSTR("M211 S1"));
		enqueue_and_echo_commands_P(PSTR("M120"));
		enqueue_and_echo_commands_P(PSTR("G28 Z"));
		moving = 1;

		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY_10, 20);

		ShowDialog(DIAG_PAGE7_TITLE[wtvar_language],
			DIAG_PAGE7_LINE1[wtvar_language],
			DIAG_PAGE7_LINE2[wtvar_language],
			DIAG_PAGE7_LINE3[wtvar_language],
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY,
			MMSG_EMPTY);
	}
	else if (pageid == 8)
	{	
		dserial.SendString_P(ADDR_HELP2_TEXT_BUTTON2, MMSG_EMPTY_10, 20);

		temp_nozzle0 = thermalManager.current_temperature[0];
		if (temp_nozzle0 < -10)
		{
			ShowDialog(DIAG_PAGE9_TITLE[wtvar_language],
				MMSG_EMPTY,
				MMSG_SELF_TEST_NOTEMP[wtvar_language],
				DIAG_PAGE9_LINE7[wtvar_language],
				MMSG_EMPTY,
				MMSG_EMPTY,
				MMSG_EMPTY,
				MMSG_EMPTY);
		}
		else
		{
			enqueue_and_echo_commands_P(PSTR("G91"));
			enqueue_and_echo_commands_P(PSTR("G1 Z100 F500"));
			enqueue_and_echo_commands_P(PSTR("M104 S210"));
			moving = 1;

			ShowDialog(DIAG_PAGE9_TITLE[wtvar_language],
				MMSG_EMPTY,
				DIAG_PAGE9_LINE1[wtvar_language],
				MMSG_STATUS_LABEL_NOZZLE[wtvar_language],
				MMSG_EMPTY,
				MMSG_EMPTY,
				MMSG_EMPTY,
				MMSG_EMPTY);
		}
	}
}

void DGUS_Screen_ErrorDiag::ShowDialog(const char* title,
	const char* line1,
	const char* line2,
	const char* line3,
	const char* line4,
	const char* line5,
	const char* line6,
	const char* line7)
{
	dserial.SendString_P(ADDR_HELP2_TEXT_TITLE, title, 40);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE1, line1, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE2, line2, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE3, line3, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE4, line4, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE5, line5, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE6, line6, 64);
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE7, line7, 64);
}


void DGUS_Screen_ErrorDiag::NozzleTempError(void)
{
	dserial.SendString_P(ADDR_HELP2_TEXT_LINE2, MMSG_SELF_TEST_NOTEMP[wtvar_language], 64);
}

void DGUS_Screen_ErrorDiag::BedTempError(void)
{

}

void DGUS_Screen_ErrorDiag::EndStopError(void)
{
	switch (pageid)
	{
	case 3:
	case 5:
	case 7:
		dserial.SendString_P(ADDR_HELP2_TEXT_LINE7, MMSG_SELF_TEST_NOHOMING[wtvar_language], 64);
		break;

	default:
		break;
	}
}

void DGUS_Screen_ErrorDiag::Finish(void)
{
	thermalManager.target_temperature[0] = 0;
	thermalManager.target_temperature_bed = 0;
	enqueue_and_echo_commands_P(PSTR("M84"));
	enqueue_and_echo_commands_P(PSTR("M211 S1"));
	dgus.QuitTestingMode();
	Goback();
}