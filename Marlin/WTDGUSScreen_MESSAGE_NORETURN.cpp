/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Message_NOReturn.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Message_NoReturn::Init()
{
	dserial.LoadScreen(SCREEN_NOTICE);
	isAutoReturn = false;
	holdontime = getcurrenttime();
}

void DGUS_Screen_Message_NoReturn::Update()
{
	if (parent != NULL)
		parent->Update();

	if (isAutoReturn)
	{
		if (planner.has_blocks_queued() == false)
			Goback();
	}
}

void DGUS_Screen_Message_NoReturn::KeyProcess()
{
	if (parent != NULL)
		parent->KeyProcess();
}

void DGUS_Screen_Message_NoReturn::Title(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_TITLE, title, 30);
}

void DGUS_Screen_Message_NoReturn::Line1(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE1, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line2(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE2, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line3(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE3, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line4(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE4, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line5(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE5, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line6(const char* title)
{
	dserial.SendString(ADDR_NOTICE_TEXT_LINE6, title, 50);
}

void DGUS_Screen_Message_NoReturn::Title_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_TITLE, title, 30);
}

void DGUS_Screen_Message_NoReturn::Line1_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE1, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line2_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE2, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line3_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE3, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line4_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE4, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line5_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE5, title, 50);
}

void DGUS_Screen_Message_NoReturn::Line6_P(const char* title)
{
	dserial.SendString_P(ADDR_NOTICE_TEXT_LINE6, title, 50);
}
