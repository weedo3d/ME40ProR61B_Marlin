/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef LANGUAGE_MULTI_H
#define LANGUAGE_MULTI_H

const char MMSG_EMPTY[] PROGMEM = { " " };
const char MMSG_EMPTY_10[] PROGMEM = { "          " };
const char MMSG_UNKNOWN_TIME[] PROGMEM = { "??h??m" };

const char MMSG_SPEED_VALUE1[8] PROGMEM = { "  25%" };
const char MMSG_SPEED_VALUE2[8] PROGMEM = { "  50%" };
const char MMSG_SPEED_VALUE3[8] PROGMEM = { "  100%" };
const char MMSG_SPEED_VALUE4[8] PROGMEM = { "  200%" };
const char MMSG_SPEED_VALUE5[8] PROGMEM = { "  400%" };
const char MMSG_SPEED_VALUE6[8] PROGMEM = { "  600%" };
const char TEMP_STRING[] PROGMEM = { "%d��" };

const char MMSG_UNKNOWN[] PROGMEM = { "UNKNOWN" };

const char MMSG_ERR_HOMING_FAILED[3][20] PROGMEM = {
	"��ԭ��ʧ��",			
	"Homing failed",
	"Homing fallo"
};

const char MMSG_ERR_PROBING_FAILED[3][20] PROGMEM = {
	"�Զ���ƽʧ��",			
	"Probing failed",
	"Fallo de sondeo"
};

const char MMSG_SMARTCONFIG_TITLE[3][20] PROGMEM = {
	"����WIFI����",			
	"WIFI CONFIG",
	"CONFIGURACION WIFI"
};

const char MMSG_SMARTCONFIG_LINE1[3][50] PROGMEM = {
	"ʹ���ֻ���������ӵ�WIFI�ȵ�WIFICAMWDxxxxxx",			
	"Use phone or computer to join the hotspot ",
	"Use el tel��fono o la computadora para unirse al"
};

const char MMSG_SMARTCONFIG_LINE2[3][52] PROGMEM = {
	"ʹ�����������http://10.10.0.1:88/, ҳ�����ʾ",
	"WIFICAMWDxxxxxx. Use a browser to visit",
	"punto de acceso WIFICAMWDxxxxxx. Use un navegador"
};

const char MMSG_SMARTCONFIG_LINE3[3][50] PROGMEM = {
	"�������õ�WIFI����. ������������������룬",
	"http://10.10.0.1:88/. Click the scanned ",
	"para visitar http://10.10.0.1:88/. Haga clic en"
};

const char MMSG_SMARTCONFIG_LINE4[3][52] PROGMEM = {
	"���Join. ҳ����ʾSuccess��ʾ�����ɹ�.",
	"network name and enter the password.",
	"el nombre de la red escaneada e ingrese la contr"
};

const char MMSG_SMARTCONFIG_LINE5[3][50] PROGMEM = {
	"Ȼ��������ӡ��.",
	"Click Join and wait. When the page prompts",
	"asena. Haz clic en Unirse y espera. Cuando la"
};

const char MMSG_SMARTCONFIG_LINE6[3][50] PROGMEM = {
	" ",
	"Success, restart the printer.",
	"p��gina indique Correcto, reinicie la impresora"
};

const char MMSG_OTA_TITLE[3][15] PROGMEM = {
	"WIFI�̼�����",			
	"WIFI OTA",
	"WIFI OTA"
};

const char MMSG_BACK[3][10] PROGMEM = {
	"  ����",			// 
	"  Back ",
	" Volver "
};

const char MMSG_OTA_LINE1[3][30] PROGMEM = {
	" ",
	" Checking for updates, ",
	" Comprobando actualizaciones,"
};

const char MMSG_OTA_LINE2[3][40] PROGMEM = {
	" ���ڼ�����, �벻Ҫ�رյ�Դ",
	" please do not turn off the power.",
	" Por favor, no apague la alimentaci��n."
};

const char MMSG_OTA_LINE3[3][40] PROGMEM = {
	" ���³ɹ���, ��������ӡ��",
	" Reboot the printer after the update.",
	" Reinicie la impresora despu��s de"
};

const char MMSG_OTA_LINE4[3][20] PROGMEM = {
	" ",
	" ",
	" la actualizaci��n."
};

const char MMSG_ERROR_TITLE[3][8] PROGMEM = {
	"����",			
	"Error",
	"Error"
};

const char MMSG_NOTICE_TITLE[3][9] PROGMEM = {
	"��ʾ",			
	"Notice",
	"Notar"
};

const char MMSG_UploadFail1[3][18] PROGMEM = {
	" ����ʧ��!",
	" Upload fail!",
	" Fallo de carga"
};

const char MMSG_UploadFail2[3][50] PROGMEM = {
	" ��������ӡ�����ٴγ���",
	" Roboot the printer and try again.",
	" Reinicie la impresora y vuelva a intentarlo."
};

const char MMSG_Uploading_Title[3][16] PROGMEM = {
	"�����ļ�",
	"Upload File",
	"Subir archivo"
};

const char MMSG_Uploading1[3][14] PROGMEM = {
	" ��������...",
	" Upload...",
	" Subir..."
};

const char MMSG_SDCARD_STOP[3][25] PROGMEM = {
	" ����ֹͣ��ӡ...",
	" Stop printing...",
	" Dejar de imprimir ..."
};

const char MMSG_SDCARD_PAUSE[3][26] PROGMEM = {
	" ������ͣ��ӡ...",
	" Pause printing...",
	" Pausa la impresi��n ..."
};

const char MMSG_SDCARD_RESUME[3][28] PROGMEM = {
	" ���ڻָ���ӡ...",
	" Resume printing...",
	" Reanudar la impresi��n ..."
};

const char MMSG_SDCARD_SAVE[3][24] PROGMEM = {
	" ���ڱ���ػ�...",
	" Save printing...",
	" Guardar impresi��n ..."
};

const char MMSG_RUNOUT_1[3][42] PROGMEM = {
	" ��⵽��˿ȱʧ����ӡ��ͣ",
	" Filament runout, print paused",
	"Salida de filamento, impresi��n en pausa"
};

const char MMSG_CONTINUE[3][10] PROGMEM = {
	" ���� ",			
	"Continue",
	"Continuar"
};

const char MMSG_MAIN_BUTTON1[3][12] PROGMEM = {
	"   ��ӡ",	
	"   Print",
	" Impresi��n"
};

const char MMSG_MAIN_BUTTON2[3][16] PROGMEM = {
	"   ά��",
	"Maintenance",
	"Mantenimiento"
};

const char MMSG_MAIN_BUTTON3[3][10] PROGMEM = {
	"   ����",
	"  Setting",
	"  Ajuste"
};

const char MMSG_MAIN_BUTTON4[3][10] PROGMEM = {
	"   ����",
	"   Help  ",
	"  Ayuda"
};

const char MMSG_TF_TITLE[3][30] PROGMEM = {
	"ѡ���ӡ�ļ�",
	"Select Print File",
	"Seleccione Imprimir Archivo"
};

const char MMSG_NEXT_PAGE[3][14] PROGMEM = {
	"  ��һҳ   ",
	"  Next     ",
	" Siguiente "
};

const char MMSG_PRE_PAGE[3][14] PROGMEM = {
	"  ��һҳ   ",
	" Previous  ",
	" Anterior  "
};

const char MMSG_LANGUAGE_TITLE[3][25] PROGMEM = {
	"ѡ���������",
	"Language Setting",
	"Configuraci��n de idioma"
};

const char MMSG_LANGUAGE_ITEM1[3][10] PROGMEM = {
	" ����",
	" Chinese",
	" Chino"
};

const char MMSG_LANGUAGE_ITEM2[3][10] PROGMEM = {
	" Ӣ��",
	" English",
	" Ingl��s"
};

const char MMSG_LANGUAGE_ITEM3[3][12] PROGMEM = {
	" ����",
	" Japanese",
	" Japoneses"
};

const char MMSG_LANGUAGE_ITEM4[3][12] PROGMEM = {
	" ��������",
	" Spanish",
	" Espanola"
};

const char MMSG_PREPARE_TITLE[3][32] PROGMEM = {
	"��ӡ��ά��",
	"Printer Maintenance",
	"Mantenimiento de la impresora"
};

const char MMSG_SETTING_FILAMENT[3][20] PROGMEM = {
	"    ��˿����",
	"Filament Operation",
	"    Filamento"
};

const char MMSG_SETTING_TEMP[3][16] PROGMEM = {
	"    �¶�����",
	"   Temperature",
	"   Temperatura"
};

const char MMSG_SETTING_SPEED[3][15] PROGMEM = {
	"    �ٶ�����",
	"     Speed",
	"   Velocidad"
};

const char MMSG_SETTING_SAVE[3][20] PROGMEM = {
	"    ����ػ�",
	"    Save&Off",
	" Guardar impresi��n"
};

const char MMSG_SETTING_FEED[3][22] PROGMEM = {
	"    �Զ���˿",
	"  Filament Feed",
	"Entrada de filamento"
};

const char MMSG_SETTING_RETRACT[3][22] PROGMEM = {
	"    �Զ���˿",
	" Filament Retract",
	"Salida de filamento"
};

const char MMSG_SETTING_HEAT[3][16] PROGMEM = {
	"    �ֶ�����",
	"    Preheat",
	"   Precalentar"
};

const char MMSG_SETTING_JOG[3][16] PROGMEM = {
	"    �㶯ģʽ",
	"   Jog Mode",
	"  Modo de jog"
};

const char MMSG_SETTING_LEVELBED[3][22] PROGMEM = {
	"    ƽ̨У׼",
	"   Level Bed",
	" Nivelar plataforma"
};

const char MMSG_SETTING_ZOFFSET[3][15] PROGMEM = {
	"    Z��ƫ��",
	"   Z Offset",
	"   Desfase Z"
};

const char MMSG_SETTING_SENSOR[3][20] PROGMEM = {
	"�ӽ����ظ߶ȵ���",
	" Proximity Height",
	"   Proximidad"
};

const char MMSG_SETTING_MOTOROFF[3][18] PROGMEM = {
	"    �رյ��",
	"   Motor Off",
	"  Motor apagado"
};

const char MMSG_SETTING_TITLE[3][22] PROGMEM = {
	"��ӡ����������",
	"Printer Setting",
	"Ajuste de par��metros"
};

const char MMSG_SETTING_WIFI[3][18] PROGMEM = {
	"  Wifi��������",
	"   Wifi Setting",
	"   Red wifi"
};

const char MMSG_SETTING_POWEROFF[3][20] PROGMEM = {
	"  ��ӡ��ɹػ�",
	" Auto Power Off",
	"Apagado autom��tico"
};

const char MMSG_SETTING_LANGUAGE[3][20] PROGMEM = {
	"    ��������",
	" Language Setting",
	"     Idioma"
};

const char MMSG_SETTING_INFO[3][16] PROGMEM = {
	"    �豸��Ϣ",
	"   Machine Info",
	"   Informacion"
};

const char MMSG_SETTING_RUNOUT[3][22] PROGMEM = {
	"    ��˿���",
	"  Runout Sensor",
	"Sensor de filamento"
};

const char MMSG_SETTING_SELFTEST[3][16] PROGMEM = {
	"    �����Լ�",
	"     Post",
	"   Autoprueba"
};

const char MMSG_SETTING_POWERSAVE[3][20] PROGMEM = {
	"    �ڵ�ģʽ",
	"Power Save Mode",
	"Ahorro de energ��a"
};

const char MMSG_SETTING_RESTORE[3][20] PROGMEM = {
	"  �ָ���������",
	"  Restore Default",
	" Restaurar memoria",
};

const char MMSG_STATUS_TITLE_PRINTING[3][12] PROGMEM = {
	"���ڴ�ӡ",
	"Printing",
	"Impresi��n"
};

const char MMSG_STATUS_TITLE_PAUSE[3][20] PROGMEM = {
	"��ӡ��ͣ",
	"Print Pause",
	"Pausa de impresi��n",
};

const char MMSG_STATUS_LABEL_FILE[3][8] PROGMEM = {
	"�ļ�",
	"File",
	"Archivo",
};

const char MMSG_STATUS_LABEL_SPEED[3][10] PROGMEM = {
	"��ӡ�ٶ�",
	"Speed",
	"Velocidad",
};

const char MMSG_STATUS_LABEL_NOZZLE[3][10] PROGMEM = {
	"��ͷ�¶�",
	"Nozzle",
	"Boquilla",
};

const char MMSG_STATUS_LABEL_BED[3][10] PROGMEM = {
	"ƽ̨�¶�",
	"Bed",
	"Cama",
};

const char MMSG_STATUS_LABEL_ELAPSED[3][15] PROGMEM = {
	"����ʱ��",
	"Elapsed",
	"Transcurrido",
};

const char MMSG_STATUS_LABEL_REMAIN[3][13] PROGMEM = {
	"ʣ��ʱ��",
	"Remain",
	"Permanecer",
};

const char MMSG_STATUS_LABEL_PERCENT[3][13] PROGMEM = {
	"��ӡ����",
	"Percent",
	"Por ciento",
};

const char MMSG_EXIT[3][10] PROGMEM = {
	"  �˳�",
	"  Quit",
	"  Dejar",
};

const char MMSG_PAUSE[3][10] PROGMEM = {
	"  ��ͣ",
	"  Pause",
	"  Pausa",
};

const char MMSG_RESUME[3][12] PROGMEM = {
	"  ����",
	"  Resume",
	"  Continuar",
};

const char MMSG_SETTING[3][10] PROGMEM = {
	"  ����",
	" Setting",
	" Ajuste",
};

const char MMSG_YES[3][7] PROGMEM = {
	"  ȷ��",
	"  YES",
	"  Si",
};

const char MMSG_NO[3][7] PROGMEM = {
	"  ȡ��",
	"  NO",
	"  NO",
};

const char MMSG_PRINTINT_SETTING_TITLE[3][30] PROGMEM = {
	"��ӡ��������",
	"Printing Setting",
	"Configuraci��n de impresi��n",
};

const char MMSG_CONFIRM_TITLE[3][30] PROGMEM = {
	"ȷ��",
	"Confirm",
	"Confirmar",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE2[3][46] PROGMEM = {
	"��ǰ��ӡ������ֹ�����Ҳ��ɻָ���",
	"The current print job will be aborted",
	"El trabajo de impresi��n actual se cancelar��",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE3[3][27] PROGMEM = {
	"��ȷ��Ҫ�˳���",
	"and cannot be recovered.",
	"y no se podr�� recuperar.",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE4[3][32] PROGMEM = {
	" ",
	"Are you sure you want to quit?",
	"Seguro que quieres salir?",
};

const char MMSG_FILAMENT_OPERATION_TITLE[3][30] PROGMEM = {
	"��˿����",
	"Filament Operation",
	"Operaci��n del filamento",
};

const char MMSG_OK[3][12] PROGMEM = {
	"  ȷ��",
	"  OK",
	"DE ACUERDO",
};

const char MMSG_CANCEL[3][10] PROGMEM = {
	"  ȡ��",
	" Cancel",
	" Cancelar",
};

const char MMSG_PREHEAT_TITLE[3][32] PROGMEM = {
	"����Ŀ���¶�",
	"Set Target Temperature",
	"Ajustar la temperatura objetivo",
};

const char MMSG_ERROR_MINTEMP[3][50] PROGMEM = {
	"��ͷ����: �޷���ȡ����Ч�¶�, ������ͷ�ӿ�",
	"Nozzle failure: temperature can't be read",
	"Fallo de la boquilla: error de temperatura",
};

const char MMSG_ERROR_BEDTEMP[3][50] PROGMEM = {
	"�ȴ�����: �޷���ȡ����Ч�¶�, �����ȴ��ӿ�",
	"Bed failure: temperature can't be read",
	"Falla de cama: la temperatura no se puede leer",
};

const char MMSG_ERROR_MAXTEMP[3][50] PROGMEM = {
	"��ͷ����: �¶ȳ�����Ч��Χ",
	"Nozzle failure: temperature exceeds maximum",
	"Fallo de la boquilla: temperatura demasiado alta",
};

const char MMSG_FILAMENT_TYPE_TITLE[3][20] PROGMEM = {
	"ѡ����˿����",
	"Filament Type",
	"Tipo de filamento",
};

const char MMSG_FILAMENT_TYPE_NAME1[10] PROGMEM = {
	"PLA 210��"
};

const char MMSG_FILAMENT_TYPE_NAME2[10] PROGMEM = {
	"ABS 235��"
};

const char MMSG_FILAMENT_TYPE_NAME4[10] PROGMEM = {
	"TPU 240��"
};

const char MMSG_FILAMENT_TYPE_NAME3[3][23] PROGMEM = {
	"������˿ 260��",
	"Other Filament 260��",
	"Otro filamento 260��",
};

const char MMSG_FILAMENT_TYPE_TEMP1[6] PROGMEM = {
	"210��"
};

const char MMSG_FILAMENT_TYPE_TEMP2[6] PROGMEM = {
	"235��"
};

const char MMSG_FILAMENT_TYPE_TEMP3[6] PROGMEM = {
	"260��"
};

const char MMSG_FILAMENT_TYPE_TEMP4[6] PROGMEM = {
	"240��"
};

const char MMSG_FILAMENT_LEFT_IN_TITLE[3][30] PROGMEM = {
	"����ͷ�Զ���˿",
	"Left Nozzle Filament Feed",
	"Boquilla izquierda Feedin",
};

const char MMSG_FILAMENT_RIGHT_IN_TITLE[3][30] PROGMEM = {
	"����ͷ�Զ���˿",
	"Right Nozzle Filament Feed",
	"Boquilla derecha Feedin",
};

const char MMSG_FILAMENT_LEFT_OUT_TITLE[3][30] PROGMEM = {
	"����ͷ�Զ���˿",
	"Left Nozzle Filament Retract",
	"Boquilla izquierda retra��da",
};

const char MMSG_FILAMENT_RIGHT_OUT_TITLE[3][30] PROGMEM = {
	"����ͷ�Զ���˿",
	"Right Nozzle Filament Retract",
	"Boquilla derecha retra��da",
};

const char MMSG_FILAMENT_IN_LINE1[3][14] PROGMEM = {
	"���ڼ���...",
	"Heating...",
	"Calefacci��n"
};

const char MMSG_FILAMENT_IN_LINE2[3][40] PROGMEM = {
	"�뽫��˿���뼷����ģ�飬Ȼ���Ե�Ƭ��",
	"Insert the filament and wait a while",
	"Insertar el filamento y esperar un rato",
};

const char MMSG_FILAMENT_OUT_LINE2[3][32] PROGMEM = {
	"���Ե�",
	"Please wait a few minutes",
	"Por favor espere unos minutos",
};

const char MMSG_FILAMENT_IN_LINE3[3][28] PROGMEM = {
	"���ڽ�˿...",
	"Filament feeding...",
	"Filamento de alimentaci��n",
};

const char MMSG_FILAMENT_OUT_LINE3[3][30] PROGMEM = {
	"������˿...",
	"Filament retracting...",
	"Filamento de retracci��n ...",
};

const char MMSG_HEATING_TITLE[3][14] PROGMEM = {
	"���ڼ���",
	"Heating",
	"Calefacci��n"
};

const char MMSG_JOB_TITLE[3][14] PROGMEM = {
	"�㶯ģʽ",
	"Jog Mode",
	"Modo de jog",
};

const char MMSG_RETURN_HOME[3][20] PROGMEM = {
	"   ����ԭ��",
	" Return Home",
	"Volver a origen",
};

const char MMSG_LEVEL_TITLE[3][20] PROGMEM = {
	"ƽ̨У׼",
	"Level Bed",
	"Nivelar plataforma"
};

const char MMSG_BEGIN[3][10] PROGMEM = {
	"  ��ʼ",
	"  Begin",
	" Comenzar",
};

const char MMSG_END[3][10] PROGMEM = {
	"  ����",
	"  End",
	"  Fin",
};

const char MMSG_NEXT[3][12] PROGMEM = {
	"  ��һ��",
	"  Next",
	" Siguiente",
};

const char MMSG_LEVEL0_LINE1[3][40] PROGMEM = {
	"ƽ̨У׼������ͷΪ��׼, ����",
	"Level Bed is to measure and adjust",
	"La cama nivelada es para medir y",
};

const char MMSG_LEVEL0_LINE2[3][40] PROGMEM = {
	"����������ƽ̨4��������ͷ�ļ�϶,",
	"the gap between the 4 points of",
	"ajustar el espacio entre los 4 puntos",
};

const char MMSG_LEVEL0_LINE3[3][34] PROGMEM = {
	"ȷ����ӡƽ̨ƽ������ͷ����ƽ̨.",
	"the platform and the nozzle.",
	"de la plataforma y la boquilla.",
};

const char MMSG_LEVEL0_LINE4[3][32] PROGMEM = {
	"׼��һ�Ű�ֽ��ʼ.",
	"Prepare a paper and begin.",
	"Preparar un papel y comenzar.",
};

const char MMSG_LEVEL1_LINE1[3][40] PROGMEM = {
	"����ƽ̨�Һ󷽵���ĸ,",
	"Adjust the nut on the right rear of",
	"Ajustar la tuerca en la parte posterior",
};

const char MMSG_LEVEL1_LINE2[3][40] PROGMEM = {
	"ֱ����ͷ��ƽ̨�ļ�϶Ϊһ��ֽ",
	"the bed, until the gap is the",
	"derecha de la cama, hasta que el espa",
};

const char MMSG_LEVEL1_LINE3[3][40] PROGMEM = {
	"�ĺ��.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL1_LINE4[3][40] PROGMEM = {
	"��ɺ����һ��.",
	"Click Next to continue.",
	"Haga clic en Siguiente para continuar.",
};

const char MMSG_LEVEL2_LINE1[3][40] PROGMEM = {
	"����ƽ̨��󷽵���ĸ,",
	"Adjust the nut on the left rear of",
	"Ajustar la tuerca en la parte posterior",
};

const char MMSG_LEVEL2_LINE2[3][40] PROGMEM = {
	"ֱ����ͷ��ƽ̨�ļ�϶Ϊһ��ֽ",
	"the bed, until the gap is the",
	"izquierda de la cama, hasta que el esp",
};

const char MMSG_LEVEL2_LINE3[3][40] PROGMEM = {
	"�ĺ��.",
	"thickness of a piece of paper.",
	"acio es el grosor de una hoja de pap",
};

const char MMSG_LEVEL2_LINE4[3][40] PROGMEM = {
	"��ɺ����һ��.",
	"Click Next to continue.",
	"el.Haga clic enSiguiente para continuar",
};

const char MMSG_LEVEL3_LINE1[3][40] PROGMEM = {
	"����ƽ̨��ǰ������ĸ,",
	"Adjust the nut on the left front of",
	"Ajustar la tuerca enla parte frontal iz",
};

const char MMSG_LEVEL3_LINE2[3][40] PROGMEM = {
	"ֱ����ͷ��ƽ̨�ļ�϶Ϊһ��ֽ",
	"the bed, until the gap is the",
	"quierda de la cama, hasta que el espa",
};

const char MMSG_LEVEL3_LINE3[3][40] PROGMEM = {
	"�ĺ��.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL3_LINE4[3][40] PROGMEM = {
	"��ɺ����һ��.",
	"Click Next to continue.",
	"Haga clic en Siguiente para continuar.",
};

const char MMSG_LEVEL4_LINE1[3][40] PROGMEM = {
	"����ƽ̨��ǰ������ĸ,",
	"Adjust the nut on the right front of",
	"Ajustar la tuerca en la parte frontal",
};

const char MMSG_LEVEL4_LINE2[3][40] PROGMEM = {
	"ֱ����ͷ��ƽ̨�ļ�϶Ϊһ��ֽ",
	"the bed, until the gap is the",
	"derecha de la cama, hasta que el espa",
};

const char MMSG_LEVEL4_LINE3[3][40] PROGMEM = {
	"�ĺ��.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL4_LINE4[3][40] PROGMEM = {
	"��ɺ����ƽ̨У׼.",
	"Click End to finish Level Bed.",
	"Haga clic en Finalizar para finalizar.",
};

const char MMSG_NOTICE_MOVING[3][40] PROGMEM = {
	"�����ƶ�, ���Ե�...",
	"Moving, please wait...",
	"En movimiento, por favor espere...",
};

const char MMSG_ZOFFSET_TITLE[3][30] PROGMEM = {
	"Z��ƫ������",
	"Z Offset Setting",
	"Ajuste de compensaci��n de Z",
};

const char MMSG_SAVE[3][10] PROGMEM = {
	"  ����",
	"  Save",
	" Guardar",
};

const char MMSG_ZOFFSET_LINE1[3][60] PROGMEM = {
	"Z��ƫ������΢����ͷ��ƽ̨�ļ�϶, ׼��һ��ֽƬ������",
	"Z Offset is used to fine-tune the gap between nozzle",
	"Z Offset se utiliza para ajustar el espacio. Haga clic en",
};

const char MMSG_ZOFFSET_LINE2[3][55] PROGMEM = {
	"ͷ��. �����ť����΢��ƽ̨, ֱ����϶Ϊһ��ֽ�ĺ��.",
	"and bed. Click button to move bed up or down until",
	"bot��n para mover la cama arriba o hacia abajo hasta",
};

const char MMSG_ZOFFSET_LINE3[3][52] PROGMEM = {
	"��ɺ��������˳�.",
	"the gap is the thickness of a piece of paper.",
	"que el espacio es el grosor de una hoja de papel.",
};

const char MMSG_MOTOROFF_LINE1[3][46] PROGMEM = {
	"���е������ѹر�",
	"All motor outputs are off.",
	"Todas las salidas del motor est��n apagadas.",
};

const char MMSG_POXIMITY_TITLE[3][32] PROGMEM = {
	"�ӽ����ظ߶ȵ���",
	"Proximity Height Adjustment",
	"Ajuste de altura de proximidad",
};

const char MMSG_POXIMITY_LINE1[3][52] PROGMEM = {
	"ƽֹ̨ͣ���к�, �ӽ�����Ӧ��Ϊ��ͨ״̬. �������Ϊ",
	"After moving, the proximity should be on. If it",
	"Despu��s de mover, la proximidad debe estar en.",
};

const char MMSG_POXIMITY_LINE2[3][54] PROGMEM = {
	"�Ͽ�״̬, ���ɿ��̶��ӽ����ص���˿, ����΢���ӽ���",
	"is off, loosen the screw and fine-tune the height",
	"De lo contrario, afloje el tornillo y ajuste la alt",
};

const char MMSG_POXIMITY_LINE3[3][52] PROGMEM = {
	"�ظ߶�, ֱ�����ص�ͨ. Ȼ��š����˿�̶��ýӽ�����.",
	"of proximity, until the switch is turned on. Then",
	"ura de proximidad hasta que se encienda el inte",
};

const char MMSG_POXIMITY_LINE4[3][52] PROGMEM = {
	"�ӽ����ص�ǰ״̬:",
	"fix the position of proximity. Current status is:",
	"rruptor. Entonces arr��glalo. El estado actual es:",
};

const char MMSG_SWITCH_ON[3][5] PROGMEM = {
	"��ͨ",
	"ON",
	"ON",
};

const char MMSG_SWITCH_OFF[3][5] PROGMEM = {
	"�Ͽ�",
	"OFF",
	"OFF",
};

const char MMSG_MACHINE_TITLE[3][28] PROGMEM = {
	"�豸��Ϣ",
	"Machine Information",
	"Informaci��n de la m��quina",
};

const char MMSG_MACHINE_ITEM1[3][26] PROGMEM = {
	"�豸����:",
	"Device Name:",
	"Nombre del dispositivo:",
};

const char MMSG_MACHINE_ITEM2[3][16] PROGMEM = {
	"�Ѵ�ӡʱ��:",
	"Printed Time:",
	"Hora impresa:",
};

const char MMSG_MACHINE_ITEM3[3][22] PROGMEM = {
	"�̼��汾:",
	"Firmware Version:",
	"Versi��n de firmware:",
};

const char MMSG_MACHINE_ITEM4[3][14] PROGMEM = {
	"UI�汾:",
	"UI Version:",
	"UI:",
};

const char MMSG_MACHINE_ITEM5[3][24] PROGMEM = {
	"�豸���к�:",
	"Device Serial:",
	"Serie del dispositivo:",
};

const char MMSG_MACHINE_ITEM6[3][20] PROGMEM = {
	"��ƽ̨״̬:",
	"Cloud State:",
	"Estado de la nube:",
};

const char MMSG_WIFI_CONFIG_ITEM1[3][18] PROGMEM = {
	"WIFI�̼��汾:",
	"WIFI Version:",
	"Versi��n WIFI:",
};

const char MMSG_WIFI_CONFIG_ITEM2[3][22] PROGMEM = {
	"WIFI IP��ַ:",
	"WIFI IP Address:",
	"Direcci��n IP WIFI:",
};

const char MMSG_WIFI_CONFIG[3][30] PROGMEM = {
	"����WIFI����",
	"Config WIFI Network",
	"Config WIFI Network",
};

const char MMSG_WIFI_OTA[3][30] PROGMEM = {
	"��������WIFI�豸�̼�",
	"Update WIFI Firmware Online",
	"Firmware WIFI OTA",
};

const char MMSG_PRINTEND_TITLE[3][22] PROGMEM = {
	"��ӡ���",
	"Print Completed",
	"Imprimir Completado",
};

const char MMSG_PRINTEND_FILE[3][22] PROGMEM = {
	"�ļ���:",
	"Filename:",
	"Nombre del archivo:",
};

const char MMSG_PRINTEND_TIME[3][22] PROGMEM = {
	"��ӡʱ��:",
	"Print Time:",
	"Tiempo de impresi��n:",
};

const char MMSG_PRINTEND_FILAMENT[3][21] PROGMEM = {
	"ʹ����˿:",
	"Using Filament:",
	"Utilizando filamento",
};

const char MMSG_PRINTEND_AGAIN[3][21] PROGMEM = {
	"  �ٴδ�ӡ",
	" Print Again",
	"Imprimir de nuevo",
};

const char MMSG_POWEROFF_TITLE[3][20] PROGMEM = {
	"׼���ػ�",
	"Prepare Poweroff",
	"Preparar el apagado",
};

const char MMSG_POWEROFF_LINE1[3][38] PROGMEM = {
	"����׼���رմ�ӡ��.",
	"Preparing to turn off the printer.",
	"Preparando para apagar la impresora.",
};

const char MMSG_POWEROFF_LINE2[3][18] PROGMEM = {
	"ʣ��ʱ��:",
	"Remaining time:",
	"Tiempo restante:",
};

const char MMSG_RESTORE_SETTING_LINE1[3][48] PROGMEM = {
	"ȷ��Ҫ�ָ�����������",
	"Are you sure to restore the factory settings?",
	"Est��s seguro de restaurar a la predeterminada?",
};

const char MMSG_SPEED_SETTING_TITLE[3][22] PROGMEM = {
	"��ӡ�ٶ�����",
	"Print Speed Setting",
	"Ajuste de velocidad",
};

const char MMSG_POWER_SAVE_TITLE[3][30] PROGMEM = {
	"�Զ��رյ�Դ����",
	"Auto Power Off Setting",
	"Ajuste de apagado autom��tico",
};

const char MMSG_POWEROFF_VALUE1[3][14] PROGMEM = {
	"   �ر�",
	"  Disable",
	" Inhabilitar",
};

const char MMSG_POWEROFF_VALUE2[3][12] PROGMEM = {
	"  1����",
	"  1 min",
	" 1 minuto",
};

const char MMSG_POWEROFF_VALUE3[3][12] PROGMEM = {
	"  5����",
	"  5 min",
	"5 minutos",
};

const char MMSG_POWEROFF_VALUE4[3][12] PROGMEM = {
	"  10����",
	"  10 min",
	"10 minutos",
};

const char MMSG_POWEROFF_VALUE5[3][12] PROGMEM = {
	"  15����",
	"  15 min",
	"15 minutos",
};

const char MMSG_POWEROFF_VALUE6[3][12] PROGMEM = {
	"  30����",
	"  30 min",
	"30 minutos",
};

const char MMSG_SELF_TEST_TITLE[3][25] PROGMEM = {
	"�����Լ�",
	"Post",
	"Autoprueba de encendido"
};

const char MMSG_SKIP[3][10] PROGMEM = {
	"  ����",
	"  Skip",
	"  Saltar"
};

const char MMSG_SELF_TEST_ITEM1[3][16] PROGMEM = {
	"��ͷ����:",
	"Nozzle Heating:",
	"Boquilla:"
};

const char MMSG_SELF_TEST_ITEM2[3][16] PROGMEM = {
	"ƽ̨����:",
	"Bed Heating:",
	"Plataforma"
};

const char MMSG_SELF_TEST_ITEM3[3][16] PROGMEM = {
	"��˿������:",
	"Runout Sensor:",
	"Filamento:"
};

const char MMSG_SELF_TEST_ITEM4[3][16] PROGMEM = {
	"X���λ:",
	"X Axis Homing:",
	"X Axis Homing:"
};

const char MMSG_SELF_TEST_ITEM5[3][16] PROGMEM = {
	"Y���λ:",
	"Y Axis Homing:",
	"Y Axis Homing:"
};

const char MMSG_SELF_TEST_ITEM6[3][16] PROGMEM = {
	"Z���λ:",
	"Z Axis Homing:",
	"Z Axis Homing:"
};

const char MMSG_SELF_TEST_PASS[3][10] PROGMEM = {
	"����",
	"PASS",
	"PASAR"
};

const char MMSG_SELF_TEST_NOTEMP[3][30] PROGMEM = {
	"�޷���ȡ�¶�!",
	"Temperature can't be read!",
	"Error de temperatura"
};

const char MMSG_SELF_TEST_NOHEAT[3][26] PROGMEM = {
	"����ʧ��!",
	"Heating fail!",
	"Falla de calentamiento"
};

const char MMSG_SELF_TEST_HEATING[3][15] PROGMEM = {
	"���ڼ���...",
	"Heating...",
	"Calefacci��n"
};

const char MMSG_SELF_TEST_RUNOUT_OK[3][16] PROGMEM = {
	"��˿�Ѳ���",
	"Filament OK",
	"Filamento ok"
};

const char MMSG_SELF_TEST_RUNOUT_FAIL[3][18] PROGMEM = {
	"δ��⵽��˿",
	"NO Filament",
	"NO filamento"
};

const char MMSG_SELF_TEST_MOVING[3][18] PROGMEM = {
	"�����ƶ�...",
	"Moving...",
	"Emocionante"
};

const char MMSG_SELF_TEST_NOHOMING[3][16] PROGMEM = {
	"�޷���λ!",
	"Homing Fail!",
	"Homing fallo!"
};

const char MMSG_HELP_TITLE[3][6] PROGMEM = {
	"����",
	"Help",
	"Ayuda"
};

const char MMSG_HELP_GUIDE[3][18] PROGMEM = {
	"    ʹ����",
	"   Quick Guide",
	"   Gu��a r��pida"
};

const char MMSG_HELP_FAQ[3][20] PROGMEM = {
	"    ��������",
	"      FAQ",
	"      FAQ"
};

const char MMSG_HELP_DIAG[3][22] PROGMEM = {
	"    �������",
	"  Error Diagnosis",
	"   Diagnostico"
};

const char MMSG_HELP_VIDEO[3][20] PROGMEM = {
	"    ������Ƶ",
	"   Online Video",
	"  Video en linea"
};

const char MMSG_SAVE_PRINTING[3][40] PROGMEM = {
	"���ڱ����ӡ����...",
	"Saving print progress...",
	"Guardando progreso de impresi��n ..."
};

const char MMSG_RESUME_LINE1[3][36] PROGMEM = {
	"���ֱ������, �Ƿ�ָ���ӡ?",
	"Found the save progress,",
	"Encontr�� el progreso de guardar,"
};

const char MMSG_RESUME_LINE2[3][26] PROGMEM = {
	"",
	"resume printing?",
	"reanudar la impresi��n?"
};

const char MMSG_RESUME_PRINTING[3][40] PROGMEM = {
	"���ڻָ���ӡ����...",
	"Resuming print progress...",
	"Reanudando el progreso de impresi��n"
};

const char MMSG_HELPLIST_TITLE[3][10] PROGMEM = {
	"��������",
	"FAQ",
	"FAQ"
};

const char MMSG_HELPVIDEO_TITLE[3][18] PROGMEM = {
	"������Ƶ",
	"Online Video",
	"Video en linea"
};

const char MMSG_PRINTING_NOTICE[3][35] PROGMEM = { 
	"����ͣ���ٽ��в���",
	"Please pause before proceeding",
	"Pausa antes de continuar",
};

const char MMSG_FILAMENT_CHOICE_EXTRUDER_TITLE[3][30] PROGMEM = {
	"ѡ����ͷ",
	"Select Nozzle",
	"Seleccionar boquilla",
};

const char MMSG_FILAMENT_LEFT_EXTRUDER[3][30] PROGMEM = {
	"    ����ͷ",
	"  Left Nozzle",
	" Boquilla izquierda",
};

const char MMSG_FILAMENT_RIGHT_EXTRUDER[3][30] PROGMEM = {
	"    ����ͷ",
	"  Right Nozzle",
	" Boquilla derecha",
};

const char MMSG_STOPPED[] PROGMEM = { "STOPPED. " };
const char MMSG_ERR_Z_HOMING[] PROGMEM = { "Home XY first" };
const char MMSG_ZPROBE_OUT[] PROGMEM = { "Z Probe past bed" };

#endif // 
