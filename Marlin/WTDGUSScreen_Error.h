/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_ERROR_H
#define WTDUGSSCREEN_ERROR_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Error : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

	void Title(const char* title);
	void Line1(const char* title);
	void Line2(const char* title);
	void Line3(const char* title);
	void Line4(const char* title);
	void Line5(const char* title);
	void Line6(const char* title);

	void Title_P(const char* title);
	void Line1_P(const char* title);
	void Line2_P(const char* title);
	void Line3_P(const char* title);
	void Line4_P(const char* title);
	void Line5_P(const char* title);
	void Line6_P(const char* title);

private:
	int16_t temp_nozzle0;
	int16_t temp_bed;
};

#endif