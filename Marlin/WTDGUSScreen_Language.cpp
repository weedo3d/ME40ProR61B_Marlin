/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "configuration_store.h"
#include "WTDGUSScreen_Language.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Language::Init()
{
	dserial.LoadScreen(SCREEN_SDCARD);

	dserial.SendString_P(ADDR_LANG_TITLE, MMSG_LANGUAGE_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_LANG_BACK_TEXT, MMSG_BACK[wtvar_language], 20);
	dserial.SendString_P(ADDR_LANG_PRE_TEXT, MMSG_EMPTY, 20);
	dserial.SendString_P(ADDR_LANG_NEXT_TEXT, MMSG_EMPTY, 20);
	dserial.SendInt16(ADDR_TF_HELP_ICON, ENUM_HELP_ICON_NOHELP);
	dserial.SendString_P(ADDR_LANG_ITEM1_TEXT, MMSG_LANGUAGE_ITEM1[wtvar_language], 20);
	dserial.SendString_P(ADDR_LANG_ITEM2_TEXT, MMSG_LANGUAGE_ITEM2[wtvar_language], 20);
	dserial.SendString_P(ADDR_LANG_ITEM3_TEXT, MMSG_LANGUAGE_ITEM4[wtvar_language], 20);
	dserial.SendString_P(ADDR_LANG_ITEM4_TEXT, MMSG_EMPTY, 20);
	dserial.SendString_P(ADDR_LANG_ITEM5_TEXT, MMSG_EMPTY, 30);
	dserial.SendString_P(ADDR_LANG_ITEM6_TEXT, MMSG_EMPTY, 30);

	holdontime = getcurrenttime();
}

void DGUS_Screen_Language::Update()
{

}

void DGUS_Screen_Language::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LANG_KEY)
		{
			if (gltouchpara.value == KEY_LANG_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_LANG_PRE)
			{

			}
			else if (gltouchpara.value == KEY_LANG_NEXT)
			{

			}
			else if (gltouchpara.value == KEY_LANG_ITEM1)
			{
				wtvar_language = 0;
				dgus.GotoMain();
				(void)settings.save();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM2)
			{
				wtvar_language = 1;
				dgus.GotoMain();
				(void)settings.save();
			}
			else if (gltouchpara.value == KEY_LANG_ITEM3)
			{
				wtvar_language = 2;
				dgus.GotoMain();
				(void)settings.save();
			}
		}
		gltouchpara.validflg = false;
	}
}
