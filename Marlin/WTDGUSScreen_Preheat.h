/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_PREHEAT_H
#define WTDUGSSCREEN_PREHEAT_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Preheat : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
private:
	int lasttemp_nozzle0;
	int lasttemp_bed;
	int16_t temp_nozzle0;
	int16_t temp_bed;
	int target_nozzle0;
	int target_bed;
	bool isHeating;
	int percent_nozzle0;
	int percent_bed;
	int begin_nozzle0;
	int begin_bed;

	void ShowTemperature(void);
	void ShowTarget(void);
	void ShowHelp(void);

	char b[8];
};

#endif
