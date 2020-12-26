/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "WTDGUSScreenBase.h"
#include "WTDGUSManager.h"

void DGUS_Screen_Base::Goback()
{
	if (parent != NULL)
		dgus.GotoScreen(parent);
}