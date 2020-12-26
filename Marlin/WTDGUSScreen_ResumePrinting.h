/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_RESUMEPRINTING_H
#define WTDUGSSCREEN_RESUMEPRINTING_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_ResumePrinting : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum DSEP_ENUM
	{
		DSEP_NOTHING = 0,
		DSEP_FOUNDFILE = 1,
		DSEP_WAITUSER = 2,
		DSEP_START = 3,
		DSEP_HEATING = 4,
		DSEP_WAITHEATING = 5,
		DSEP_GOHOME = 6,
		DSEP_WAITGOHOME = 7,
		DSEP_SETPOS = 8,
		DSEP_WAITSETPOS = 9,
		DSEP_WAITBUFFER = 10,
		DSEP_OPENFILE = 11,
		DSEP_COMPLETE = 12
	};

	DSEP_ENUM state;

	uint8_t r, c;
};

#endif

