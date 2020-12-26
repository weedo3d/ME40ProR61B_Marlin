/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_SDCard.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"
#include "WTHelpDoc.h"

void DGUS_Screen_SDCard::Init()
{
	dserial.LoadScreen(SCREEN_SDCARD);

	dserial.SendString_P(ADDR_TF_TITLE, MMSG_TF_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_TF_BACK_TEXT, MMSG_BACK[wtvar_language], 20);
	dserial.SendInt16(ADDR_TF_HELP_ICON, ENUM_HELP_ICON_HELP);

	if (card.cardOK)
	{
		filecount = card.getnrfilenames();
		if (filecount % 6 > 0)
			pagecount = filecount / 6 + 1;
		else
			pagecount = filecount / 6;
		pageid = 0;
		ShowPage(pageid);
	}
	else
	{
		filecount = 0;
		pagecount = 0;
		ClearList();
	}

	pageid = 0;
	cardStatus = card.cardOK;

	holdontime = getcurrenttime();
}

void DGUS_Screen_SDCard::Update()
{
	if (cardStatus != card.cardOK)
	{
		if (card.cardOK)
		{
			filecount = card.getnrfilenames();
			if (filecount % 6 > 0)
				pagecount = filecount / 6 + 1;
			else
				pagecount = filecount / 6;
			pageid = 0;
			ShowPage(pageid);
		}
		else
		{
			ClearList();
			filecount = 0;
			pagecount = 0;
		}

		cardStatus = card.cardOK;
	}
}

void DGUS_Screen_SDCard::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == ADDR_TF_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_TF_RETURN)
			{
				Goback();
			}
			else if (gltouchpara.value == KEY_TF_PRE)//page up
			{
				ShowPrePage();
			}
			else if (gltouchpara.value == KEY_TF_NEXT)//page down
			{
				ShowNextPage();
			}
			else if (gltouchpara.value >= KEY_TF_FILE1 && gltouchpara.value <= KEY_TF_FILE6)//4-7 selected file
			{
				card.getfilename(gltouchpara.value - 4 + pageid * 6);
				card.openAndPrintFile(card.filename);
				dgus.GotoStatusMenu();
			}
			else if (gltouchpara.value == KEY_TF_HELPBUTTON)
			{
				ShowHelp();
			}
		}
		else if (gltouchpara.address == ADDR_HELP1_KEY)
		{
			gltouchpara.validflg = false;
			if (gltouchpara.value == KEY_HELP1_BUTTON_RETURN)
			{	
				dserial.LoadScreen(SCREEN_SDCARD);
			}
		}
	}
}

void DGUS_Screen_SDCard::ShowFileInfo(char* filename, uint8_t index)
{
	if (filename == NULL || strlen(filename) == 0)
		dserial.SendString_P(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, MMSG_EMPTY, 30);
	else
		dserial.SendString(DGUS_SDMENU_FILENAME_ADDR + index * DGUS_SDMENU_FILENAME_INTERVAL, filename, 30);
}

void DGUS_Screen_SDCard::ShowPage(uint8_t id)
{
	uint8_t beginPos, endPos, curIndex;

	beginPos = id * 6;
	if (filecount - beginPos > 6)
		endPos = beginPos + 6;
	else
		endPos = filecount - 1;

	curIndex = 0;
	while (beginPos <= endPos && curIndex < 6)
	{
		memset(filename_buffer, 0, 36);

		card.getfilename(beginPos);

		strcpy(filename_buffer, card.filename);
		ShowFileInfo(filename_buffer, curIndex);

		curIndex++;
		beginPos++;
	}

	while (curIndex < 6)
	{
		ShowFileInfo(NULL, curIndex);
		curIndex++;
	}

	if (pageid == 0)
	{
		dserial.SendString_P(ADDR_TF_PRE_TEXT, MMSG_EMPTY, 20);
		if (pagecount > 1)
			dserial.SendString_P(ADDR_TF_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language]);
		else
			dserial.SendString_P(ADDR_TF_NEXT_TEXT, MMSG_EMPTY, 20);
	}
	else if (pageid == (pagecount - 1))
	{
		dserial.SendString_P(ADDR_TF_NEXT_TEXT, MMSG_EMPTY, 20);
		dserial.SendString_P(ADDR_TF_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language]);
	}
	else
	{
		dserial.SendString_P(ADDR_TF_PRE_TEXT, MMSG_PRE_PAGE[wtvar_language]);
		dserial.SendString_P(ADDR_TF_NEXT_TEXT, MMSG_NEXT_PAGE[wtvar_language]);
	}
}

void DGUS_Screen_SDCard::ShowPrePage(void)
{
	if (filecount > 0 && pageid > 0)
	{
		pageid--;
		ShowPage(pageid);
	}
}

void DGUS_Screen_SDCard::ShowNextPage(void)
{
	if (filecount > 0 && (pageid + 1) < pagecount)
	{
		pageid++;
		ShowPage(pageid);
	}
}

void DGUS_Screen_SDCard::ClearList(void)
{
	for (int i = 0; i < 6; i++)
		ShowFileInfo(NULL, i);

	dserial.SendString_P(ADDR_TF_PRE_TEXT, MMSG_EMPTY, 20);
	dserial.SendString_P(ADDR_TF_NEXT_TEXT, MMSG_EMPTY, 20);
}

void DGUS_Screen_SDCard::ShowHelp(void)
{
	dserial.LoadScreen(SCREEN_HELP1);

	dserial.SendString_P(ADDR_HELP1_TEXT_TITLE, MMSG_HELP_TITLE[wtvar_language], 30);
	dserial.SendString_P(ADDR_HELP1_TEXT_RETURN, MMSG_BACK[wtvar_language], 20);

	dserial.SendString_P(ADDR_HELP1_TEXT_LINE1, HELP_TIP01_LINE1[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE2, HELP_TIP01_LINE2[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE3, HELP_TIP01_LINE3[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE4, HELP_TIP01_LINE4[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE5, HELP_TIP01_LINE5[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE6, HELP_TIP01_LINE6[wtvar_language], 60);
	dserial.SendString_P(ADDR_HELP1_TEXT_LINE7, HELP_TIP01_LINE7[wtvar_language], 60);
}