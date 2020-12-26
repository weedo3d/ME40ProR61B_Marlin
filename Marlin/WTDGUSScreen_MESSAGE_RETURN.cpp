/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Message_Return.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Message_Return::Init()
{
	dserial.LoadScreen(SCREEN_INFO);

	Title_P(MMSG_EMPTY);
	Button_P(MMSG_EMPTY);
	Line1_P(MMSG_EMPTY);
	Line2_P(MMSG_EMPTY);
	Line3_P(MMSG_EMPTY);
	Line4_P(MMSG_EMPTY);
	Line5_P(MMSG_EMPTY);
	holdontime = getcurrenttime();
}

void DGUS_Screen_Message_Return::Update()
{
	if (parent != NULL)
		parent->Update();
}

void DGUS_Screen_Message_Return::KeyProcess()
{
	if (parent != NULL)
		parent->KeyProcess();

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

void DGUS_Screen_Message_Return::Title(const char* title)
{
	dserial.SendString(ADDR_INFO_TITLE, title, 30);
}

void DGUS_Screen_Message_Return::Button(const char* title)
{
	dserial.SendString(ADDR_INFO_RETURN, title, 20);
}

void DGUS_Screen_Message_Return::Line1(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE1, title, 60);
}

void DGUS_Screen_Message_Return::Line2(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE2, title, 60);
}

void DGUS_Screen_Message_Return::Line3(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE3, title, 60);
}

void DGUS_Screen_Message_Return::Line4(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE4, title, 60);
}

void DGUS_Screen_Message_Return::Line5(const char* title)
{
	dserial.SendString(ADDR_INFO_LINE5, title, 60);
}

void DGUS_Screen_Message_Return::Title_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_TITLE, title, 30);
}

void DGUS_Screen_Message_Return::Button_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_RETURN, title, 20);
}

void DGUS_Screen_Message_Return::Line1_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_LINE1, title, 60);
}

void DGUS_Screen_Message_Return::Line2_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_LINE2, title, 60);
}

void DGUS_Screen_Message_Return::Line3_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_LINE3, title, 60);
}

void DGUS_Screen_Message_Return::Line4_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_LINE4, title, 60);
}

void DGUS_Screen_Message_Return::Line5_P(const char* title)
{
	dserial.SendString_P(ADDR_INFO_LINE5, title, 60);
}