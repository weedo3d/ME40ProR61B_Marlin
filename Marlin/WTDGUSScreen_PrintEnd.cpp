/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "printcounter.h"
#include "duration_t.h"
#include "WTDGUSScreen_PrintEnd.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

#define JUMP_TO_POWEROFF_MENU	10

void DGUS_Screen_PrintEnd::Init()
{
	dserial.LoadScreen(SCREEN_PRINTING_END);

	dserial.SendString_P(ADDR_PRINTEND_TEXT_TITLE, MMSG_PRINTEND_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_PRINTEND_TEXT_BACK, MMSG_EXIT[wtvar_language], 20);
	dserial.SendString_P(ADDR_PRINTEND_TEXT_AGAIN, MMSG_PRINTEND_AGAIN[wtvar_language], 20);
	dserial.SendString_P(ADDR_PRINTEND_TEXT_FILENAME, MMSG_PRINTEND_FILE[wtvar_language], 30);
	dserial.SendString_P(ADDR_PRINTEND_TEXT_TIME, MMSG_PRINTEND_TIME[wtvar_language], 30);
	dserial.SendString_P(ADDR_PRINTEND_TEXT_FILAMENT, MMSG_PRINTEND_FILAMENT[wtvar_language], 30);

	char b[12];
	memset(b, 0, 12);
	duration_t elapsed = print_job_timer.duration();
	bool has_days = (elapsed.value >= 60 * 60 * 24L);
	elapsed.toDigital(b, has_days);
	dserial.SendString(ADDR_PRINTEND_VALUE_TIME, b, 16);


	count = JUMP_TO_POWEROFF_MENU;
	holdontime = getcurrenttime();
}

void DGUS_Screen_PrintEnd::Update()
{
	if (count > 0)
	{
		count--;
	}
	else
	{
		if (wtvar_enablepoweroff == 1)
		{
			dgus.GotoPowerOffMenu();
		}
	}
}

void DGUS_Screen_PrintEnd::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_PRINTING_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_PRINTEND_BUTTON_BACK)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_PRINTEND_BUTTON_AGAIN)
			{
				card.openAndPrintFile(card.filename);
				dgus.GotoStatusMenu();
			}
			
		}
	}
}

void DGUS_Screen_PrintEnd::ShowFilename(const char* fname)
{
	dserial.SendString(ADDR_PRINT_VALUE_FILENAME, fname, 16);
}