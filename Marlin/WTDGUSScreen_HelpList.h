/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_HELP_LIST_H
#define WTDUGSSCREEN_HELP_LIST_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_HelpList : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	void ShowPage();
	void ShowPrePage(void);
	void ShowNextPage(void);
	void ShowHelp(uint8_t id);

	uint8_t pageid;
	uint8_t pagecount;
};

#endif