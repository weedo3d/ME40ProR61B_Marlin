/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_HelpList.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_HelpList::Init()
{
	dserial.LoadScreen(SCREEN_LISTMENU);

	dserial.SendString_P(ADDR_LIST_TEXT_TITLE, MMSG_HELPLIST_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_QR_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	pagecount = 4;
	pageid = 0;
	
	ShowPage();

	holdontime = getcurrenttime();
}

void DGUS_Screen_HelpList::Update()
{
	// do nothing
}

void DGUS_Screen_HelpList::KeyProcess()
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
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_LISTMENU);
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

void DGUS_Screen_HelpList::ShowPage()
{
	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_TIP15_TITLE[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, HELP_TIP16_TITLE[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, HELP_TIP17_TITLE[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, HELP_TIP18_TITLE[wtvar_language], 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language], 20);
	}
	else if (pageid == 1)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_TIP19_TITLE[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, HELP_TIP20_TITLE[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, HELP_VIDEO1[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, HELP_VIDEO2[wtvar_language], 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language], 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language], 20);
	}
	else if (pageid == 2)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_VIDEO3[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, HELP_VIDEO4[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, HELP_VIDEO5[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, HELP_VIDEO7[wtvar_language], 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language], 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_NEXT_PAGE[wtvar_language], 20);
	}
	else if (pageid == 3)
	{
		dserial.SendString_P(ADDR_LIST_TEXT_LINE1, HELP_VIDEO8[wtvar_language], 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE2, MMSG_EMPTY, 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE3, MMSG_EMPTY, 64);
		dserial.SendString_P(ADDR_LIST_TEXT_LINE4, MMSG_EMPTY, 64);

		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_PRE, MMSG_PRE_PAGE[wtvar_language], 20);
		dserial.SendString_P(ADDR_LIST_BUTTON_TEXT_NEXT, MMSG_EMPTY, 20);
	}
}

void DGUS_Screen_HelpList::ShowPrePage(void)
{
	if (pageid > 0)
	{
		pageid--;
		ShowPage();
	}
}

void DGUS_Screen_HelpList::ShowNextPage(void)
{
	if ((pageid + 1) < pagecount)
	{
		pageid++;
		ShowPage();
	}
}

void DGUS_Screen_HelpList::ShowHelp(uint8_t id)
{
	if (id <= 6)
	{
		dserial.LoadScreen(SCREEN_HELP1);
		dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
		dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);
	}
	else
	{
		dserial.LoadScreen(SCREEN_QR);
	}

	if (id == 1)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP15_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP15_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP15_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP15_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP15_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP15_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP15_LINE7[wtvar_language], 60);
	}
	else if (id == 2)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP16_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP16_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP16_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP16_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP16_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP16_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP16_LINE7[wtvar_language], 60);
	}
	else if (id == 3)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP17_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP17_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP17_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP17_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP17_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP17_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP17_LINE7[wtvar_language], 60);
	}
	else if (id == 4)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP18_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP18_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP18_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP18_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP18_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP18_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP18_LINE7[wtvar_language], 60);
	}
	else if (id == 5)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP19_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP19_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP19_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP19_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP19_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP19_LINE6[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}
	else if (id == 6)
	{
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP20_LINE1[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP20_LINE2[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP20_LINE3[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP20_LINE4[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP20_LINE5[wtvar_language], 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, MMSG_EMPTY, 60);
		dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, MMSG_EMPTY, 60);
	}
	else if (id == 7)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO1[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO1_URL[wtvar_language], 60);
	}
	else if (id == 8)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO2[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO2_URL[wtvar_language], 60);
	}
	else if (id == 9)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO3[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO3_URL[wtvar_language], 60);
	}
	else if (id == 10)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO4[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO4_URL[wtvar_language], 60);
	}
	else if (id == 11)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO5[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO5_URL[wtvar_language], 60);
	}
	else if (id == 12)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO7[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO7_URL[wtvar_language], 60);
	}
	else if (id == 13)
	{
		dserial.SendString_P(ADDR_QR_TEXT_TILE, HELP_VIDEO8[wtvar_language], 30);
		dserial.SendString_P(ADDR_QR_CODE, HELP_VIDEO8_URL[wtvar_language], 60);
	}
}