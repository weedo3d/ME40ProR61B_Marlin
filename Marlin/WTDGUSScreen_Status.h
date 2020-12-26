/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_STATUS_H
#define WTDUGSSCREEN_STATUS_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Status : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
	void ShowFilename(const char* fname);

private:
	void ShowDialog(void);
	void ShowHelp(void);
	void OutputTemp(uint16_t addr, int16_t temp);

	int lasttemp_nozzle0;
	int lasttemp_bed;
	int16_t temp_nozzle0;
	int16_t temp_bed;
	uint8_t percent_current;
	int percent_last;
	uint8_t percent_progress;
	int16_t lastfeedrate;
	char b[12];
};

#endif