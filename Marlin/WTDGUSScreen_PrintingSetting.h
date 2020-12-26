/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_PRINTING_SETTING_H
#define WTDUGSSCREEN_PRINTING_SETTING_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_PrintingSetting : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	void ShowPrePage(void);
	void ShowNextPage(void);
	void ShowPage(void);
	void ShowFilamentOption(void);
	void ShowTarget(void);
	void ShowTempSetting(void);
	void ShowHelp(void);

	uint8_t pageid;
	int target_nozzle0;
	int target_bed;
};

#endif

