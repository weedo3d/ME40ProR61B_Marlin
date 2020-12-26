/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_MAIN_H
#define WTDUGSSCREEN_MAIN_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Main : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	void ShowTemperature(void);
	void ShowIP(void);

	int chktmpcount;
	int lasttemp_nozzle0;
	int lasttemp_bed;
	int16_t temp_nozzle0;
	int16_t temp_bed;
	bool wifiStatus;
	int checkcount;
};

#endif
