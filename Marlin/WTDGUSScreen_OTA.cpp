/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSScreen_OTA.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern char esp32_message[22];

void DGUS_Screen_OTA::Init()
{
	dgus.LoadMessageReturnMenu(this);
	dgus.GetScreenMessageReturn()->Title_P(MMSG_OTA_TITLE[wtvar_language]);
	dgus.GetScreenMessageReturn()->Button_P(MMSG_BACK[wtvar_language]);
	dgus.GetScreenMessageReturn()->Line1_P(MMSG_OTA_LINE1[wtvar_language]);
	dgus.GetScreenMessageReturn()->Line2_P(MMSG_OTA_LINE2[wtvar_language]);
	dgus.GetScreenMessageReturn()->Line3_P(MMSG_OTA_LINE3[wtvar_language]);
	dgus.GetScreenMessageReturn()->Line4_P(MMSG_OTA_LINE4[wtvar_language]);
	dgus.GetScreenMessageReturn()->Line5_P(MMSG_EMPTY);

	WT_OTA_Default();

	holdontime = getcurrenttime();
}

void DGUS_Screen_OTA::Update()
{
	dgus.GetScreenMessageReturn()->Line5(esp32_message);
}

void DGUS_Screen_OTA::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_INFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_INFO_RETURN)
			{
				Goback();
			}
		}
	}
}
