/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDUGSSCREEN_MACHINEINFO_H
#define WTDUGSSCREEN_MACHINEINFO_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSConfig.h"

class DGUS_Screen_MachineInfo : public DGUS_Screen_Base
{
public:
	void Init(void);
	void Update(void);
	void KeyProcess(void);
};

#endif
