/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "WTDGUSScreen_SmartConfig.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern bool getIPAddress;

void DGUS_Screen_SmartConfig::Init()
{
	dgus.LoadMessageNoReturnMenu(this);
	dgus.GetScreenMessageNoReturn()->Title_P(MMSG_SMARTCONFIG_TITLE[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line1_P(MMSG_SMARTCONFIG_LINE1[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line2_P(MMSG_SMARTCONFIG_LINE2[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line3_P(MMSG_SMARTCONFIG_LINE3[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line4_P(MMSG_SMARTCONFIG_LINE4[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line5_P(MMSG_SMARTCONFIG_LINE5[wtvar_language]);
	dgus.GetScreenMessageNoReturn()->Line6_P(MMSG_SMARTCONFIG_LINE6[wtvar_language]);

	WT_Set_SmartConfig();

	holdontime = getcurrenttime();
	chktmpcount = 30;
}

void DGUS_Screen_SmartConfig::Update()
{
	chktmpcount--;

	if (chktmpcount == 0 || getIPAddress)
	{
		Goback();
	}
}

void DGUS_Screen_SmartConfig::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == 0x1074)
		{
			if (gltouchpara.value == 0x01)
			{
				Goback();
			}
		}
		gltouchpara.validflg = false;
	}
}
