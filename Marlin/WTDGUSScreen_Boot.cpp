/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#include "Marlin.h"
#include "temperature.h"
#include "cardreader.h"
#include "planner.h"
#include "power_loss_recovery.h"
#include "WTDGUSScreen_Boot.h"
#include "WTDGUSSerial.h"
#include "WTDGUSConfig.h"
#include "WTDGUSManager.h"

extern uint8_t wtvar_skipTest;

void DGUS_Screen_Boot::Init()
{
	dserial.payload_reset();
	dserial.payload_append_byte(DGUS_CMD_ReadVAR);
	dserial.payload_append_int(0x0084);
	dserial.payload_append_byte(0x2);
	dserial.payload_send();
	holdontime = getcurrenttime();

	WT_Get_IP();
}

void DGUS_Screen_Boot::Update()
{
	// do nothing
}

void DGUS_Screen_Boot::KeyProcess()
{
	if (gltouchpara.validflg)
	{
		if (gltouchpara.address == 0x84)
		{
			if (gltouchpara.value != 0x0)
			{
				dgus.ResetScreen();
				safe_delay(3000);
			}

			if (card.jobRecoverFileExists())
			{
				memset(&job_recovery_info, 0, sizeof(job_recovery_info));
				card.openJobRecoveryFile(true);
				card.loadJobRecoveryInfo();
				card.closeJobRecoveryFile();

				dgus.GotoResumePrintingMenu();
			}
			else
			{
				if (wtvar_enableselftest && wtvar_skipTest == 0)
					dgus.GotoSelfTest();
				else
					dgus.GotoMain();
			}
		}
		gltouchpara.validflg = false;
	}
}