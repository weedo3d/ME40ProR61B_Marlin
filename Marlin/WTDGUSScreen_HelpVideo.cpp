/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_HelpVideo.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_HelpVideo::Init()
{
	dserial.LoadScreen(SCREEN_LISTMENU);

	dserial.SendString_P(ADDR_LIST_TEXT_TITLE, MMSG_HELPVIDEO_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_QR_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	pagecount = 2;
	pageid = 0;

	ShowPage();

	holdontime = getcurrenttime();
}

void DGUS_Screen_HelpVideo::Update()
{
	// do nothing
}

void DGUS_Screen_HelpVideo::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_LIST_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_LIST_BUTTON_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_LIST_BUTTON_PRE)//page up
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_LIST_BUTTON_NEXT)//page down
			{
				ShowNextPage();
			}
			else if (gltouchpara.value >= KEY_LIST_BUTTON_LINE1 && gltouchpara.value <= KEY_LIST_BUTTON_LINE4)//4-7 selected file
			{
				ShowHelp(gltouchpara.value - 3 + pageid * 4);
			}
		}
		else if (gltouchpara.address == ADDR_QR_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_QR_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_LISTMENU);
			}
		}
	}
}

void DGUS_Screen_HelpVideo::ShowPage()
{
	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_VIDEO1[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, HELP_VIDEO2[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, HELP_VIDEO3[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, HELP_VIDEO4[wtvar_language], 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language], 20);
	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_VIDEO5[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, HELP_VIDEO6[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, HELP_VIDEO7[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, HELP_VIDEO8[wtvar_language], 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language], 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_EMPTY, 20);
	}
}

void DGUS_Screen_HelpVideo::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_HelpVideo::ShowNextPage(void)
{
	if ((pageid + 1) < pagecount)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_HelpVideo::ShowHelp(uint8_t id)
{
	dserial.LoadScreen(SCREEN_QR);

	if (id == 1)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO1[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO1_URL[wtvar_language], 60);
	}
	else if (id == 2)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO2[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO2_URL[wtvar_language], 60);
	}
	else if (id == 3)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO3[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO3_URL[wtvar_language], 60);
	}
	else if (id == 4)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO4[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO4_URL[wtvar_language], 60);
	}
	else if (id == 5)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO5[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO5_URL[wtvar_language], 60);
	}
	else if (id == 6)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO6[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO6_URL[wtvar_language], 60);
	}
	else if (id == 7)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO7[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO7_URL[wtvar_language], 60);
	}
	else if (id == 8)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO8[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO8_URL[wtvar_language], 60);
	}
}