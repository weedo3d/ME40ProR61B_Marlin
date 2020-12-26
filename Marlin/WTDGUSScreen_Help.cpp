/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSScreen_Help.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"


void DGUS_Screen_Help::Init()
{
	dserial.LoadScreen(SCREEN_HELPMENU);

	holdontime = getcurrenttime();

	dserial.SendString_P(ADDR_HELPMENU_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELPMENU_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendInt16(ADDR_HELPMENU_ICON1, ENUM_SETTING_FAQ);
	dserial.SendString_P(ADDR_HELPMENU_ITEM1, MMSG_HELP_FAQ[wtvar_language], 32);

	dserial.SendInt16(ADDR_HELPMENU_ICON2, ENUM_SETTING_DIAG);
	dserial.SendString_P(ADDR_HELPMENU_ITEM2, MMSG_HELP_DIAG[wtvar_language], 32);

	dserial.SendInt16(ADDR_HELPMENU_ICON3, ENUM_SETTING_NONE);
	dserial.SendString_P(ADDR_HELPMENU_ITEM3, MMSG_EMPTY, 32);

}

void DGUS_Screen_Help::Update()
{
	// do nothing
}

void DGUS_Screen_Help::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_HELPMENU_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELPMENU_BUTTON_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM1)
			{
				dgus.GotoHelpListMenu();
			}
			else if (gltouchpara.value == KEY_HELPMENU_BUTTON_ITEM2)
			{
				dgus.GotoErrorDiaglogMenu();
			}

		}
		
	}
}

