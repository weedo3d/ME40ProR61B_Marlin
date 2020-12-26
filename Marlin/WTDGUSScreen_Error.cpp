/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "WTDGUSScreen_Error.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"


void DGUS_Screen_Error::Init()
{
	dserial.LoadScreen(SCREEN_ERROR);

}

void DGUS_Screen_Error::Update()
{
	// do nothing
}

void DGUS_Screen_Error::KeyProcess()
{
	// do nothing
}


void DGUS_Screen_Error::Title(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_TITLE, title);
}

void DGUS_Screen_Error::Line1(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE1, title);
}

void DGUS_Screen_Error::Line2(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE2, title);
}

void DGUS_Screen_Error::Line3(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE3, title);
}

void DGUS_Screen_Error::Line4(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE4, title);
}

void DGUS_Screen_Error::Line5(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE5, title);
}

void DGUS_Screen_Error::Line6(const char* title)
{
	dserial.SendString(ADDR_ERROR_TEXT_LINE6, title);
}

void DGUS_Screen_Error::Title_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_TITLE, title);
}

void DGUS_Screen_Error::Line1_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE1, title);
}

void DGUS_Screen_Error::Line2_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE2, title);
}

void DGUS_Screen_Error::Line3_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE3, title);
}

void DGUS_Screen_Error::Line4_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE4, title);
}

void DGUS_Screen_Error::Line5_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE5, title);
}

void DGUS_Screen_Error::Line6_P(const char* title)
{
	dserial.SendString_P(ADDR_ERROR_TEXT_LINE6, title);
}