/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "configuration_store.h"
#include "WTDGUSScreen_RestoreSetting.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_RestoreSetting::Init()
{
	dserial.LoadScreen(SCREEN_2BINFO);
	dserial.SendString_P(ADDR_2BINFO_TITLE, MMSG_CONFIRM_TITLE[wtvar_language], 30);
	dserial.SendInt16(ADDR_2BINFO_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON1, MMSG_NO[wtvar_language], 20);
	dserial.SendString_P(ADDR_2BINFO_TEXT_BUTTON2, MMSG_YES[wtvar_language], 20);

	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE1, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE2, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE3, MMSG_RESTORE_SETTING_LINE1[wtvar_language], 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE4, MMSG_EMPTY, 50);
	dserial.SendString_P(ADDR_2BINFO_TEXT_LINE5, MMSG_EMPTY, 50);

	holdontime = getcurrenttime();
}

void DGUS_Screen_RestoreSetting::Update()
{

}

void DGUS_Screen_RestoreSetting::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_2BINFO_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_2BINFO_ITEM2)
			{
				settings.reset();
				settings.save();				
				wt_restart();
			}
			else if (gltouchpara.value == KEY_2BINFO_ITEM1)
			{
				Goback();
			}
		}
		
	}
}
