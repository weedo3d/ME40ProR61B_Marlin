/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WTDGUSMANAGER_H
#define WTDGUSMANAGER_H

#include "WTDGUSScreenBase.h"
#include "WTDGUSScreen_Main.h"
#include "WTDGUSScreen_Prepare.h"
#include "WTDGUSScreen_Control.h"
#include "WTDGUSScreen_SDCard.h"
#include "WTDGUSScreen_Status.h"
#include "WTDGUSScreen_Error.h"
#include "WTDGUSScreen_PrintEnd.h"
#include "WTDGUSScreen_PowerOff.h"
#include "WTDGUSScreen_PrintingSetting.h"
#include "WTDGUSScreen_Levelbed.h"
#include "WTDGUSScreen_Filament.h"
#include "WTDGUSScreen_Preheat.h"
#include "WTDGUSScreen_MachineInfo.h"
#include "WTDGUSScreen_WifiSetting.h"
#include "WTDGUSScreen_SavePrinting.h"
#include "WTDGUSScreen_ResumePrinting.h"
#include "WTDGUSScreen_Boot.h"
#include "WTDGUSScreen_RestoreSetting.h"
#include "WTDGUSScreen_TestMode.h"
#include "WTDGUSScreen_SmartConfig.h"
#include "WTDGUSScreen_MESSAGE_RETURN.h"
#include "WTDGUSScreen_MESSAGE_NORETURN.h"
#include "WTDGUSScreen_OTA.h"
#include "WTDGUSScreen_ZOffset.h"
#include "WTDGUSScreen_Language.h"
#include "WTDGUSScreen_Job.h"
#include "WTDGUSScreen_Proximity.h"
#include "WTDGUSScreen_SpeedSetting.h"
#include "WTDGUSScreen_PowerSave.h"
#include "WTDGUSScreen_SelfTest.h"
#include "WTDGUSScreen_Help.h"
#include "WTDGUSScreen_ErrorDiag.h"
#include "WTDGUSScreen_HelpList.h"

#define DGUS_PAYLOAD_LENGTH		64
#define TestError_

typedef enum {
	DS_START1 = 0,
	DS_START2 = 1,
	DS_LEN = 2,
	DS_PAYLOAD = 3
} DGUSPacketStatusEnum;

class DGUSManager
{
public:
	DGUSManager();

	void Init(unsigned long baud);
	void Update();

	void SetFilename(const char* fname);
	void SetPrintTime(const char* time);

	void GotoScreen(DGUS_Screen_Base* screen);
	void LoadSubScreen(DGUS_Screen_Base* screen, DGUS_Screen_Base* parent);
	void ResetScreen(void);

	void GotoMain(void);
	void GotoLoadFilament(DGUS_Screen_Base* parent);
	void GotoUnloadFilament(DGUS_Screen_Base* parent);
	void GotoSDMenu(void) { GotoScreen(screenSDCard); }
	void GotoBootMenu(void) { GotoScreen(screenBoot); }
	void GotoControlMenu(void) { GotoScreen(screenControl);}
	void GotoPrepareMenu(void) { GotoScreen(screenPrepare);}
	void GotoStatusMenu(void) { GotoScreen(screenStatus); }
	void GotoErrorMenu(void) { GotoScreen(screenError); }
	void GotoLevelMenu(void) { GotoScreen(screenLevelbed); }
	void GotoPreheatMenu(void) { GotoScreen(screenPreheat); }
	void GotoMachineInfoMenu(void) { GotoScreen(screenMachineInfo); }
	void GotoWifiSettingMenu(void) { GotoScreen(screenWifiSetting); }
	void GotoPrintEndMenu(void) { GotoScreen(screenPrintEnd); }
	void GotoPowerOffMenu(void) { GotoScreen(screenPowerOff); }
	void GotoPrintingSettingMenu(void) { GotoScreen(screenPrintingSetting); }
	void GotoSavePrintingMenu(void) { GotoScreen(screenSavePrinting); }
	void GotoResumePrintingMenu(void) { GotoScreen(screenResumePrinting); }
	void GotoRestoreSettingMenu(void) { GotoScreen(screenRestoreSetting); }
	void GotoTestModeMenu(void) { GotoScreen(screenTestMode); }
	void GotoSmartConfigMenu(void) { GotoScreen(screenSmartConfig); }
	void LoadMessageReturnMenu(DGUS_Screen_Base* parent) { LoadSubScreen(screenMessageReturn, parent); }
	DGUS_Screen_Message_Return* GetScreenMessageReturn(void) { return screenMessageReturn; }
	void GotoMessageNoReturnMenu(void) { GotoScreen(screenMessageNoReturn); }
	void LoadMessageNoReturnMenu(DGUS_Screen_Base* parent) { LoadSubScreen(screenMessageNoReturn, parent); }
	DGUS_Screen_Message_NoReturn* GetScreenMessageNoReturn(void) { return screenMessageNoReturn;}
	void GotoOTAMenu(void) { GotoScreen(screenOTA);}
	void GotoZOffsetMenu(void) { GotoScreen(screenZOffset); }
	void GotoLanguageMenu(void) { GotoScreen(screenLanguage); }
	void GotoJobMenu(void) { GotoScreen(screenJob); }
	void GotoProximityMenu(void) { GotoScreen(screenProximity); }
	void GotoSpeedSettingMenu(void) { GotoScreen(screenSpeed); }
	void GotoPowerSaveMenu(void) { GotoScreen(screenPowersave); }
	void GotoSelfTest(void) { testingMode = true; GotoScreen(screenSelftest); }
	void GotoHelpMenu(void) { GotoScreen(screenHelp); }
	void GotoErrorDiaglogMenu(void) { testingMode = true; GotoScreen(screenErrorDiag); }
	void GotoHelpListMenu(void) { GotoScreen(screenHelpList); }

	void ShowMessageRetrun_P(const char* title,
							const char* button,
							const char* line1,
							const char* line2,
							const char* line3,
							const char* line4,
							const char* line5,
							const char* line6,
							const char* line7);

	void ShowMessageNoRetrun_P(const char* title,
		const char* line1,
		const char* line2,
		const char* line3,
		const char* line4,
		const char* line5,
		const char* line6,
		const char* line7,
		const char* line8,
		const char* line9);

	void ShowErrorMessage_P(const char* title,
		const char* line1,
		const char* line2,
		const char* line3,
		const char* line4,
		const char* line5,
		const char* line6);

	void ShowMessage(const char* msg);
	void ShowMessage_P(const char* msg);
	void ShowNoRetrunMessage_P(const char* msg);
	void ShowErrorMessage(const char* msg);
	void ShowErrorMessageString(const char* msg);
	void ShowRunoutMessage(void);

	void ShowUploadingMenu(char* msg);
	void ShowUploadFailMenu();

	void EnableMessageNoReturnAutoGoback(void) { screenMessageNoReturn->SetAutoReturn(); }

	void ShowMovingMessage(void);

	FORCE_INLINE bool isTesting(void) { return testingMode; }

	void QuitTestingMode(void) { testingMode = false; }

	void NozzleTempError(void);

	void BedTempError(void);

	void EndStopError(void);

private:
	void process();
	void InitMenu();
	void reset();
	void append(uint8_t data);

	uint8_t payload[DGUS_PAYLOAD_LENGTH];
	uint8_t length;
	uint8_t expected_length;
	DGUSPacketStatusEnum state;
	uint8_t lcd_sd_status;
	char filename[21];
	bool testingMode;

	DGUS_Screen_Main* screenMain;
	DGUS_Screen_Prepare* screenPrepare;
	DGUS_Screen_Control* screenControl;
	DGUS_Screen_SDCard* screenSDCard;
	DGUS_Screen_Status* screenStatus;
	DGUS_Screen_Error* screenError;
	DGUS_Screen_PrintEnd* screenPrintEnd;
	DGUS_Screen_PowerOff* screenPowerOff;
	DGUS_Screen_PrintingSetting* screenPrintingSetting;
	DGUS_Screen_Levelbed* screenLevelbed;
	DGUS_Screen_Filament* screenFilament;
	DGUS_Screen_Preheat* screenPreheat;
	DGUS_Screen_MachineInfo* screenMachineInfo;
	DGUS_Screen_WifiSetting* screenWifiSetting;
	DGUS_Screen_SavePrinting* screenSavePrinting;
	DGUS_Screen_ResumePrinting* screenResumePrinting;
	DGUS_Screen_Boot* screenBoot;
	DGUS_Screen_RestoreSetting* screenRestoreSetting;
	DGUS_Screen_TestMode* screenTestMode;
	DGUS_Screen_SmartConfig* screenSmartConfig;
	DGUS_Screen_Message_Return* screenMessageReturn;
	DGUS_Screen_Message_NoReturn* screenMessageNoReturn;
	DGUS_Screen_OTA* screenOTA;
	DGUS_Screen_ZOffset* screenZOffset;
	DGUS_Screen_Language* screenLanguage;
	DGUS_Screen_Job* screenJob;
	DGUS_Screen_Proximity* screenProximity;
	DGUS_Screen_Speed* screenSpeed;
	DGUS_Screen_PowerSave* screenPowersave;
	DGUS_Screen_SelfTest* screenSelftest;
	DGUS_Screen_Help* screenHelp;

	DGUS_Screen_ErrorDiag* screenErrorDiag;
	DGUS_Screen_HelpList* screenHelpList;

	DGUS_Screen_Base* screenCurrent;

};

extern DGUSManager dgus;
extern TouchPara gltouchpara;

#endif
