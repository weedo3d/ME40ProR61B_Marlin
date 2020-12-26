/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_LEVELBED_H
#define WTDUGSSCREEN_LEVELBED_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_Levelbed : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);

private:
	enum LEVELBED_SCREEN_ENUM
	{
		LBSE_NOTHING = 0,
		LBSE_WAITHOME = 1,
		LBSE_WAIT1STPT = 2,
		LBSE_WAIT2NDPT = 3,
		LBSE_WAIT3RDPT = 4,
		LBSE_WAIT4THPT = 5,
		LBSE_WAITCOMPELTE = 6,
		LBSE_WAITCANCELLED = 7,
		LBSE_WAIT_INPUT1 = 8,
		LBSE_WAIT_INPUT2 = 9,
		LBSE_WAIT_INPUT3 = 10,
		LBSE_WAIT_INPUT4 = 11

	};

	LEVELBED_SCREEN_ENUM levelbedmanuelsts;
};

#endif

