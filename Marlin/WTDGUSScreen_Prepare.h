/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_PREPARE_H
#define WTDUGSSCREEN_PREPARE_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Prepare : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	void ShowPrePage(void);
	void ShowNextPage(void);
	void ShowPage(void);
	void ShowHelp(void);

	uint8_t pageid;
};

#endif
