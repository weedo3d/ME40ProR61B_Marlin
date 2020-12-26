/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDGUSSCREENBASE_H
#define WTDGUSSCREENBASE_H

#include "Marlin.h"

class DGUS_Screen_Base
{
	public:
		DGUS_Screen_Base(void) { parent = NULL;}
		void SetParent(DGUS_Screen_Base* p) { parent = p; }
		void Goback(void);
		 
		virtual void Init(void) {};
		virtual void Update(void) {};
		virtual void KeyProcess(void) {};
		virtual void ShowFilename(const char* fname) {};

		uint32_t updaterate = 1000;
		uint32_t holdontime;

	protected:
		DGUS_Screen_Base* parent;
};

#endif
