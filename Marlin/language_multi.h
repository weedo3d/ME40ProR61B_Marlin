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
const char TEMP_STRING[] PROGMEM = { "%d℃" };

const char MMSG_UNKNOWN[] PROGMEM = { "UNKNOWN" };

const char MMSG_ERR_HOMING_FAILED[3][20] PROGMEM = {
	"回原点失败",			
	"Homing failed",
	"Homing fallo"
};

const char MMSG_ERR_PROBING_FAILED[3][20] PROGMEM = {
	"自动调平失败",			
	"Probing failed",
	"Fallo de sondeo"
};

const char MMSG_SMARTCONFIG_TITLE[3][20] PROGMEM = {
	"设置WIFI网络",			
	"WIFI CONFIG",
	"CONFIGURACION WIFI"
};

const char MMSG_SMARTCONFIG_LINE1[3][50] PROGMEM = {
	"使用手机或电脑连接到WIFI热点WIFICAMWDxxxxxx",			
	"Use phone or computer to join the hotspot ",
	"Use el teléfono o la computadora para unirse al"
};

const char MMSG_SMARTCONFIG_LINE2[3][52] PROGMEM = {
	"使用浏览器访问http://10.10.0.1:88/, 页面会显示",
	"WIFICAMWDxxxxxx. Use a browser to visit",
	"punto de acceso WIFICAMWDxxxxxx. Use un navegador"
};

const char MMSG_SMARTCONFIG_LINE3[3][50] PROGMEM = {
	"附近可用的WIFI网络. 点击网络名后输入密码，",
	"http://10.10.0.1:88/. Click the scanned ",
	"para visitar http://10.10.0.1:88/. Haga clic en"
};

const char MMSG_SMARTCONFIG_LINE4[3][52] PROGMEM = {
	"点击Join. 页面提示Success表示联网成功.",
	"network name and enter the password.",
	"el nombre de la red escaneada e ingrese la contr"
};

const char MMSG_SMARTCONFIG_LINE5[3][50] PROGMEM = {
	"然后重启打印机.",
	"Click Join and wait. When the page prompts",
	"asena. Haz clic en Unirse y espera. Cuando la"
};

const char MMSG_SMARTCONFIG_LINE6[3][50] PROGMEM = {
	" ",
	"Success, restart the printer.",
	"página indique Correcto, reinicie la impresora"
};

const char MMSG_OTA_TITLE[3][15] PROGMEM = {
	"WIFI固件升级",			
	"WIFI OTA",
	"WIFI OTA"
};

const char MMSG_BACK[3][10] PROGMEM = {
	"  返回",			// 
	"  Back ",
	" Volver "
};

const char MMSG_OTA_LINE1[3][30] PROGMEM = {
	" ",
	" Checking for updates, ",
	" Comprobando actualizaciones,"
};

const char MMSG_OTA_LINE2[3][40] PROGMEM = {
	" 正在检测更新, 请不要关闭电源",
	" please do not turn off the power.",
	" Por favor, no apague la alimentación."
};

const char MMSG_OTA_LINE3[3][40] PROGMEM = {
	" 更新成功后, 请重启打印机",
	" Reboot the printer after the update.",
	" Reinicie la impresora después de"
};

const char MMSG_OTA_LINE4[3][20] PROGMEM = {
	" ",
	" ",
	" la actualización."
};

const char MMSG_ERROR_TITLE[3][8] PROGMEM = {
	"错误",			
	"Error",
	"Error"
};

const char MMSG_NOTICE_TITLE[3][9] PROGMEM = {
	"提示",			
	"Notice",
	"Notar"
};

const char MMSG_UploadFail1[3][18] PROGMEM = {
	" 下载失败!",
	" Upload fail!",
	" Fallo de carga"
};

const char MMSG_UploadFail2[3][50] PROGMEM = {
	" 请重启打印机后再次尝试",
	" Roboot the printer and try again.",
	" Reinicie la impresora y vuelva a intentarlo."
};

const char MMSG_Uploading_Title[3][16] PROGMEM = {
	"下载文件",
	"Upload File",
	"Subir archivo"
};

const char MMSG_Uploading1[3][14] PROGMEM = {
	" 正在下载...",
	" Upload...",
	" Subir..."
};

const char MMSG_SDCARD_STOP[3][25] PROGMEM = {
	" 正在停止打印...",
	" Stop printing...",
	" Dejar de imprimir ..."
};

const char MMSG_SDCARD_PAUSE[3][26] PROGMEM = {
	" 正在暂停打印...",
	" Pause printing...",
	" Pausa la impresión ..."
};

const char MMSG_SDCARD_RESUME[3][28] PROGMEM = {
	" 正在恢复打印...",
	" Resume printing...",
	" Reanudar la impresión ..."
};

const char MMSG_SDCARD_SAVE[3][24] PROGMEM = {
	" 正在保存关机...",
	" Save printing...",
	" Guardar impresión ..."
};

const char MMSG_RUNOUT_1[3][42] PROGMEM = {
	" 检测到料丝缺失，打印暂停",
	" Filament runout, print paused",
	"Salida de filamento, impresión en pausa"
};

const char MMSG_CONTINUE[3][10] PROGMEM = {
	" 继续 ",			
	"Continue",
	"Continuar"
};

const char MMSG_MAIN_BUTTON1[3][12] PROGMEM = {
	"   打印",	
	"   Print",
	" Impresión"
};

const char MMSG_MAIN_BUTTON2[3][16] PROGMEM = {
	"   维护",
	"Maintenance",
	"Mantenimiento"
};

const char MMSG_MAIN_BUTTON3[3][10] PROGMEM = {
	"   设置",
	"  Setting",
	"  Ajuste"
};

const char MMSG_MAIN_BUTTON4[3][10] PROGMEM = {
	"   帮助",
	"   Help  ",
	"  Ayuda"
};

const char MMSG_TF_TITLE[3][30] PROGMEM = {
	"选择打印文件",
	"Select Print File",
	"Seleccione Imprimir Archivo"
};

const char MMSG_NEXT_PAGE[3][14] PROGMEM = {
	"  下一页   ",
	"  Next     ",
	" Siguiente "
};

const char MMSG_PRE_PAGE[3][14] PROGMEM = {
	"  上一页   ",
	" Previous  ",
	" Anterior  "
};

const char MMSG_LANGUAGE_TITLE[3][25] PROGMEM = {
	"选择界面语言",
	"Language Setting",
	"Configuración de idioma"
};

const char MMSG_LANGUAGE_ITEM1[3][10] PROGMEM = {
	" 中文",
	" Chinese",
	" Chino"
};

const char MMSG_LANGUAGE_ITEM2[3][10] PROGMEM = {
	" 英语",
	" English",
	" Inglés"
};

const char MMSG_LANGUAGE_ITEM3[3][12] PROGMEM = {
	" 日语",
	" Japanese",
	" Japoneses"
};

const char MMSG_LANGUAGE_ITEM4[3][12] PROGMEM = {
	" 西班牙语",
	" Spanish",
	" Espanola"
};

const char MMSG_PREPARE_TITLE[3][32] PROGMEM = {
	"打印机维护",
	"Printer Maintenance",
	"Mantenimiento de la impresora"
};

const char MMSG_SETTING_FILAMENT[3][20] PROGMEM = {
	"    料丝操作",
	"Filament Operation",
	"    Filamento"
};

const char MMSG_SETTING_TEMP[3][16] PROGMEM = {
	"    温度设置",
	"   Temperature",
	"   Temperatura"
};

const char MMSG_SETTING_SPEED[3][15] PROGMEM = {
	"    速度设置",
	"     Speed",
	"   Velocidad"
};

const char MMSG_SETTING_SAVE[3][20] PROGMEM = {
	"    保存关机",
	"    Save&Off",
	" Guardar impresión"
};

const char MMSG_SETTING_FEED[3][22] PROGMEM = {
	"    自动进丝",
	"  Filament Feed",
	"Entrada de filamento"
};

const char MMSG_SETTING_RETRACT[3][22] PROGMEM = {
	"    自动退丝",
	" Filament Retract",
	"Salida de filamento"
};

const char MMSG_SETTING_HEAT[3][16] PROGMEM = {
	"    手动加热",
	"    Preheat",
	"   Precalentar"
};

const char MMSG_SETTING_JOG[3][16] PROGMEM = {
	"    点动模式",
	"   Jog Mode",
	"  Modo de jog"
};

const char MMSG_SETTING_LEVELBED[3][22] PROGMEM = {
	"    平台校准",
	"   Level Bed",
	" Nivelar plataforma"
};

const char MMSG_SETTING_ZOFFSET[3][15] PROGMEM = {
	"    Z轴偏置",
	"   Z Offset",
	"   Desfase Z"
};

const char MMSG_SETTING_SENSOR[3][20] PROGMEM = {
	"接近开关高度调节",
	" Proximity Height",
	"   Proximidad"
};

const char MMSG_SETTING_MOTOROFF[3][18] PROGMEM = {
	"    关闭电机",
	"   Motor Off",
	"  Motor apagado"
};

const char MMSG_SETTING_TITLE[3][22] PROGMEM = {
	"打印机参数设置",
	"Printer Setting",
	"Ajuste de parámetros"
};

const char MMSG_SETTING_WIFI[3][18] PROGMEM = {
	"  Wifi网络设置",
	"   Wifi Setting",
	"   Red wifi"
};

const char MMSG_SETTING_POWEROFF[3][20] PROGMEM = {
	"  打印完成关机",
	" Auto Power Off",
	"Apagado automático"
};

const char MMSG_SETTING_LANGUAGE[3][20] PROGMEM = {
	"    语言设置",
	" Language Setting",
	"     Idioma"
};

const char MMSG_SETTING_INFO[3][16] PROGMEM = {
	"    设备信息",
	"   Machine Info",
	"   Informacion"
};

const char MMSG_SETTING_RUNOUT[3][22] PROGMEM = {
	"    料丝检测",
	"  Runout Sensor",
	"Sensor de filamento"
};

const char MMSG_SETTING_SELFTEST[3][16] PROGMEM = {
	"    开机自检",
	"     Post",
	"   Autoprueba"
};

const char MMSG_SETTING_POWERSAVE[3][20] PROGMEM = {
	"    节电模式",
	"Power Save Mode",
	"Ahorro de energía"
};

const char MMSG_SETTING_RESTORE[3][20] PROGMEM = {
	"  恢复出厂设置",
	"  Restore Default",
	" Restaurar memoria",
};

const char MMSG_STATUS_TITLE_PRINTING[3][12] PROGMEM = {
	"正在打印",
	"Printing",
	"Impresión"
};

const char MMSG_STATUS_TITLE_PAUSE[3][20] PROGMEM = {
	"打印暂停",
	"Print Pause",
	"Pausa de impresión",
};

const char MMSG_STATUS_LABEL_FILE[3][8] PROGMEM = {
	"文件",
	"File",
	"Archivo",
};

const char MMSG_STATUS_LABEL_SPEED[3][10] PROGMEM = {
	"打印速度",
	"Speed",
	"Velocidad",
};

const char MMSG_STATUS_LABEL_NOZZLE[3][10] PROGMEM = {
	"喷头温度",
	"Nozzle",
	"Boquilla",
};

const char MMSG_STATUS_LABEL_BED[3][10] PROGMEM = {
	"平台温度",
	"Bed",
	"Cama",
};

const char MMSG_STATUS_LABEL_ELAPSED[3][15] PROGMEM = {
	"已用时间",
	"Elapsed",
	"Transcurrido",
};

const char MMSG_STATUS_LABEL_REMAIN[3][13] PROGMEM = {
	"剩余时间",
	"Remain",
	"Permanecer",
};

const char MMSG_STATUS_LABEL_PERCENT[3][13] PROGMEM = {
	"打印进度",
	"Percent",
	"Por ciento",
};

const char MMSG_EXIT[3][10] PROGMEM = {
	"  退出",
	"  Quit",
	"  Dejar",
};

const char MMSG_PAUSE[3][10] PROGMEM = {
	"  暂停",
	"  Pause",
	"  Pausa",
};

const char MMSG_RESUME[3][12] PROGMEM = {
	"  继续",
	"  Resume",
	"  Continuar",
};

const char MMSG_SETTING[3][10] PROGMEM = {
	"  设置",
	" Setting",
	" Ajuste",
};

const char MMSG_YES[3][7] PROGMEM = {
	"  确定",
	"  YES",
	"  Si",
};

const char MMSG_NO[3][7] PROGMEM = {
	"  取消",
	"  NO",
	"  NO",
};

const char MMSG_PRINTINT_SETTING_TITLE[3][30] PROGMEM = {
	"打印参数设置",
	"Printing Setting",
	"Configuración de impresión",
};

const char MMSG_CONFIRM_TITLE[3][30] PROGMEM = {
	"确认",
	"Confirm",
	"Confirmar",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE2[3][46] PROGMEM = {
	"当前打印任务将中止，并且不可恢复。",
	"The current print job will be aborted",
	"El trabajo de impresión actual se cancelará",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE3[3][27] PROGMEM = {
	"你确定要退出吗？",
	"and cannot be recovered.",
	"y no se podrá recuperar.",
};

const char MMSG_QUIT_PRINT_CONFIRM_LINE4[3][32] PROGMEM = {
	" ",
	"Are you sure you want to quit?",
	"Seguro que quieres salir?",
};

const char MMSG_FILAMENT_OPERATION_TITLE[3][30] PROGMEM = {
	"料丝操作",
	"Filament Operation",
	"Operación del filamento",
};

const char MMSG_OK[3][12] PROGMEM = {
	"  确定",
	"  OK",
	"DE ACUERDO",
};

const char MMSG_CANCEL[3][10] PROGMEM = {
	"  取消",
	" Cancel",
	" Cancelar",
};

const char MMSG_PREHEAT_TITLE[3][32] PROGMEM = {
	"设置目标温度",
	"Set Target Temperature",
	"Ajustar la temperatura objetivo",
};

const char MMSG_ERROR_MINTEMP[3][50] PROGMEM = {
	"喷头故障: 无法读取到有效温度, 请检查喷头接口",
	"Nozzle failure: temperature can't be read",
	"Fallo de la boquilla: error de temperatura",
};

const char MMSG_ERROR_BEDTEMP[3][50] PROGMEM = {
	"热床故障: 无法读取到有效温度, 请检查热床接口",
	"Bed failure: temperature can't be read",
	"Falla de cama: la temperatura no se puede leer",
};

const char MMSG_ERROR_MAXTEMP[3][50] PROGMEM = {
	"喷头故障: 温度超过有效范围",
	"Nozzle failure: temperature exceeds maximum",
	"Fallo de la boquilla: temperatura demasiado alta",
};

const char MMSG_FILAMENT_TYPE_TITLE[3][20] PROGMEM = {
	"选择料丝类型",
	"Filament Type",
	"Tipo de filamento",
};

const char MMSG_FILAMENT_TYPE_NAME1[10] PROGMEM = {
	"PLA 210℃"
};

const char MMSG_FILAMENT_TYPE_NAME2[10] PROGMEM = {
	"ABS 235℃"
};

const char MMSG_FILAMENT_TYPE_NAME4[10] PROGMEM = {
	"TPU 240℃"
};

const char MMSG_FILAMENT_TYPE_NAME3[3][23] PROGMEM = {
	"高温料丝 260℃",
	"Other Filament 260℃",
	"Otro filamento 260℃",
};

const char MMSG_FILAMENT_TYPE_TEMP1[6] PROGMEM = {
	"210℃"
};

const char MMSG_FILAMENT_TYPE_TEMP2[6] PROGMEM = {
	"235℃"
};

const char MMSG_FILAMENT_TYPE_TEMP3[6] PROGMEM = {
	"260℃"
};

const char MMSG_FILAMENT_TYPE_TEMP4[6] PROGMEM = {
	"240℃"
};

const char MMSG_FILAMENT_LEFT_IN_TITLE[3][30] PROGMEM = {
	"左喷头自动进丝",
	"Left Nozzle Filament Feed",
	"Boquilla izquierda Feedin",
};

const char MMSG_FILAMENT_RIGHT_IN_TITLE[3][30] PROGMEM = {
	"右喷头自动进丝",
	"Right Nozzle Filament Feed",
	"Boquilla derecha Feedin",
};

const char MMSG_FILAMENT_LEFT_OUT_TITLE[3][30] PROGMEM = {
	"左喷头自动退丝",
	"Left Nozzle Filament Retract",
	"Boquilla izquierda retraída",
};

const char MMSG_FILAMENT_RIGHT_OUT_TITLE[3][30] PROGMEM = {
	"右喷头自动退丝",
	"Right Nozzle Filament Retract",
	"Boquilla derecha retraída",
};

const char MMSG_FILAMENT_IN_LINE1[3][14] PROGMEM = {
	"正在加热...",
	"Heating...",
	"Calefacción"
};

const char MMSG_FILAMENT_IN_LINE2[3][40] PROGMEM = {
	"请将料丝插入挤出器模块，然后稍等片刻",
	"Insert the filament and wait a while",
	"Insertar el filamento y esperar un rato",
};

const char MMSG_FILAMENT_OUT_LINE2[3][32] PROGMEM = {
	"请稍等",
	"Please wait a few minutes",
	"Por favor espere unos minutos",
};

const char MMSG_FILAMENT_IN_LINE3[3][28] PROGMEM = {
	"正在进丝...",
	"Filament feeding...",
	"Filamento de alimentación",
};

const char MMSG_FILAMENT_OUT_LINE3[3][30] PROGMEM = {
	"正在退丝...",
	"Filament retracting...",
	"Filamento de retracción ...",
};

const char MMSG_HEATING_TITLE[3][14] PROGMEM = {
	"正在加热",
	"Heating",
	"Calefacción"
};

const char MMSG_JOB_TITLE[3][14] PROGMEM = {
	"点动模式",
	"Jog Mode",
	"Modo de jog",
};

const char MMSG_RETURN_HOME[3][20] PROGMEM = {
	"   返回原点",
	" Return Home",
	"Volver a origen",
};

const char MMSG_LEVEL_TITLE[3][20] PROGMEM = {
	"平台校准",
	"Level Bed",
	"Nivelar plataforma"
};

const char MMSG_BEGIN[3][10] PROGMEM = {
	"  开始",
	"  Begin",
	" Comenzar",
};

const char MMSG_END[3][10] PROGMEM = {
	"  结束",
	"  End",
	"  Fin",
};

const char MMSG_NEXT[3][12] PROGMEM = {
	"  下一步",
	"  Next",
	" Siguiente",
};

const char MMSG_LEVEL0_LINE1[3][40] PROGMEM = {
	"平台校准是以喷头为基准, 依次",
	"Level Bed is to measure and adjust",
	"La cama nivelada es para medir y",
};

const char MMSG_LEVEL0_LINE2[3][40] PROGMEM = {
	"测量并调节平台4个点与喷头的间隙,",
	"the gap between the 4 points of",
	"ajustar el espacio entre los 4 puntos",
};

const char MMSG_LEVEL0_LINE3[3][34] PROGMEM = {
	"确保打印平台平行于喷头工作平台.",
	"the platform and the nozzle.",
	"de la plataforma y la boquilla.",
};

const char MMSG_LEVEL0_LINE4[3][32] PROGMEM = {
	"准备一张白纸后开始.",
	"Prepare a paper and begin.",
	"Preparar un papel y comenzar.",
};

const char MMSG_LEVEL1_LINE1[3][40] PROGMEM = {
	"调节平台右后方的螺母,",
	"Adjust the nut on the right rear of",
	"Ajustar la tuerca en la parte posterior",
};

const char MMSG_LEVEL1_LINE2[3][40] PROGMEM = {
	"直至喷头与平台的间隙为一张纸",
	"the bed, until the gap is the",
	"derecha de la cama, hasta que el espa",
};

const char MMSG_LEVEL1_LINE3[3][40] PROGMEM = {
	"的厚度.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL1_LINE4[3][40] PROGMEM = {
	"完成后点下一步.",
	"Click Next to continue.",
	"Haga clic en Siguiente para continuar.",
};

const char MMSG_LEVEL2_LINE1[3][40] PROGMEM = {
	"调节平台左后方的螺母,",
	"Adjust the nut on the left rear of",
	"Ajustar la tuerca en la parte posterior",
};

const char MMSG_LEVEL2_LINE2[3][40] PROGMEM = {
	"直至喷头与平台的间隙为一张纸",
	"the bed, until the gap is the",
	"izquierda de la cama, hasta que el esp",
};

const char MMSG_LEVEL2_LINE3[3][40] PROGMEM = {
	"的厚度.",
	"thickness of a piece of paper.",
	"acio es el grosor de una hoja de pap",
};

const char MMSG_LEVEL2_LINE4[3][40] PROGMEM = {
	"完成后点下一步.",
	"Click Next to continue.",
	"el.Haga clic enSiguiente para continuar",
};

const char MMSG_LEVEL3_LINE1[3][40] PROGMEM = {
	"调节平台左前方的螺母,",
	"Adjust the nut on the left front of",
	"Ajustar la tuerca enla parte frontal iz",
};

const char MMSG_LEVEL3_LINE2[3][40] PROGMEM = {
	"直至喷头与平台的间隙为一张纸",
	"the bed, until the gap is the",
	"quierda de la cama, hasta que el espa",
};

const char MMSG_LEVEL3_LINE3[3][40] PROGMEM = {
	"的厚度.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL3_LINE4[3][40] PROGMEM = {
	"完成后点下一步.",
	"Click Next to continue.",
	"Haga clic en Siguiente para continuar.",
};

const char MMSG_LEVEL4_LINE1[3][40] PROGMEM = {
	"调节平台右前方的螺母,",
	"Adjust the nut on the right front of",
	"Ajustar la tuerca en la parte frontal",
};

const char MMSG_LEVEL4_LINE2[3][40] PROGMEM = {
	"直至喷头与平台的间隙为一张纸",
	"the bed, until the gap is the",
	"derecha de la cama, hasta que el espa",
};

const char MMSG_LEVEL4_LINE3[3][40] PROGMEM = {
	"的厚度.",
	"thickness of a piece of paper.",
	"cio es el grosor de una hoja de papel",
};

const char MMSG_LEVEL4_LINE4[3][40] PROGMEM = {
	"完成后结束平台校准.",
	"Click End to finish Level Bed.",
	"Haga clic en Finalizar para finalizar.",
};

const char MMSG_NOTICE_MOVING[3][40] PROGMEM = {
	"正在移动, 请稍等...",
	"Moving, please wait...",
	"En movimiento, por favor espere...",
};

const char MMSG_ZOFFSET_TITLE[3][30] PROGMEM = {
	"Z轴偏置设置",
	"Z Offset Setting",
	"Ajuste de compensación de Z",
};

const char MMSG_SAVE[3][10] PROGMEM = {
	"  保存",
	"  Save",
	" Guardar",
};

const char MMSG_ZOFFSET_LINE1[3][60] PROGMEM = {
	"Z轴偏置用于微调喷头与平台的间隙, 准备一张纸片置于喷",
	"Z Offset is used to fine-tune the gap between nozzle",
	"Z Offset se utiliza para ajustar el espacio. Haga clic en",
};

const char MMSG_ZOFFSET_LINE2[3][55] PROGMEM = {
	"头下. 点击按钮上下微动平台, 直至间隙为一张纸的厚度.",
	"and bed. Click button to move bed up or down until",
	"botón para mover la cama arriba o hacia abajo hasta",
};

const char MMSG_ZOFFSET_LINE3[3][52] PROGMEM = {
	"完成后点击保存退出.",
	"the gap is the thickness of a piece of paper.",
	"que el espacio es el grosor de una hoja de papel.",
};

const char MMSG_MOTOROFF_LINE1[3][46] PROGMEM = {
	"所有电机输出已关闭",
	"All motor outputs are off.",
	"Todas las salidas del motor están apagadas.",
};

const char MMSG_POXIMITY_TITLE[3][32] PROGMEM = {
	"接近开关高度调节",
	"Proximity Height Adjustment",
	"Ajuste de altura de proximidad",
};

const char MMSG_POXIMITY_LINE1[3][52] PROGMEM = {
	"平台停止运行后, 接近开关应该为导通状态. 如果开关为",
	"After moving, the proximity should be on. If it",
	"Después de mover, la proximidad debe estar en.",
};

const char MMSG_POXIMITY_LINE2[3][54] PROGMEM = {
	"断开状态, 请松开固定接近开关的螺丝, 向下微调接近开",
	"is off, loosen the screw and fine-tune the height",
	"De lo contrario, afloje el tornillo y ajuste la alt",
};

const char MMSG_POXIMITY_LINE3[3][52] PROGMEM = {
	"关高度, 直至开关导通. 然后拧紧螺丝固定好接近开关.",
	"of proximity, until the switch is turned on. Then",
	"ura de proximidad hasta que se encienda el inte",
};

const char MMSG_POXIMITY_LINE4[3][52] PROGMEM = {
	"接近开关当前状态:",
	"fix the position of proximity. Current status is:",
	"rruptor. Entonces arréglalo. El estado actual es:",
};

const char MMSG_SWITCH_ON[3][5] PROGMEM = {
	"导通",
	"ON",
	"ON",
};

const char MMSG_SWITCH_OFF[3][5] PROGMEM = {
	"断开",
	"OFF",
	"OFF",
};

const char MMSG_MACHINE_TITLE[3][28] PROGMEM = {
	"设备信息",
	"Machine Information",
	"Información de la máquina",
};

const char MMSG_MACHINE_ITEM1[3][26] PROGMEM = {
	"设备名称:",
	"Device Name:",
	"Nombre del dispositivo:",
};

const char MMSG_MACHINE_ITEM2[3][16] PROGMEM = {
	"已打印时间:",
	"Printed Time:",
	"Hora impresa:",
};

const char MMSG_MACHINE_ITEM3[3][22] PROGMEM = {
	"固件版本:",
	"Firmware Version:",
	"Versión de firmware:",
};

const char MMSG_MACHINE_ITEM4[3][14] PROGMEM = {
	"UI版本:",
	"UI Version:",
	"UI:",
};

const char MMSG_MACHINE_ITEM5[3][24] PROGMEM = {
	"设备序列号:",
	"Device Serial:",
	"Serie del dispositivo:",
};

const char MMSG_MACHINE_ITEM6[3][20] PROGMEM = {
	"云平台状态:",
	"Cloud State:",
	"Estado de la nube:",
};

const char MMSG_WIFI_CONFIG_ITEM1[3][18] PROGMEM = {
	"WIFI固件版本:",
	"WIFI Version:",
	"Versión WIFI:",
};

const char MMSG_WIFI_CONFIG_ITEM2[3][22] PROGMEM = {
	"WIFI IP地址:",
	"WIFI IP Address:",
	"Dirección IP WIFI:",
};

const char MMSG_WIFI_CONFIG[3][30] PROGMEM = {
	"配置WIFI网络",
	"Config WIFI Network",
	"Config WIFI Network",
};

const char MMSG_WIFI_OTA[3][30] PROGMEM = {
	"在线升级WIFI设备固件",
	"Update WIFI Firmware Online",
	"Firmware WIFI OTA",
};

const char MMSG_PRINTEND_TITLE[3][22] PROGMEM = {
	"打印完成",
	"Print Completed",
	"Imprimir Completado",
};

const char MMSG_PRINTEND_FILE[3][22] PROGMEM = {
	"文件名:",
	"Filename:",
	"Nombre del archivo:",
};

const char MMSG_PRINTEND_TIME[3][22] PROGMEM = {
	"打印时间:",
	"Print Time:",
	"Tiempo de impresión:",
};

const char MMSG_PRINTEND_FILAMENT[3][21] PROGMEM = {
	"使用料丝:",
	"Using Filament:",
	"Utilizando filamento",
};

const char MMSG_PRINTEND_AGAIN[3][21] PROGMEM = {
	"  再次打印",
	" Print Again",
	"Imprimir de nuevo",
};

const char MMSG_POWEROFF_TITLE[3][20] PROGMEM = {
	"准备关机",
	"Prepare Poweroff",
	"Preparar el apagado",
};

const char MMSG_POWEROFF_LINE1[3][38] PROGMEM = {
	"正在准备关闭打印机.",
	"Preparing to turn off the printer.",
	"Preparando para apagar la impresora.",
};

const char MMSG_POWEROFF_LINE2[3][18] PROGMEM = {
	"剩余时间:",
	"Remaining time:",
	"Tiempo restante:",
};

const char MMSG_RESTORE_SETTING_LINE1[3][48] PROGMEM = {
	"确定要恢复出厂设置吗？",
	"Are you sure to restore the factory settings?",
	"Estás seguro de restaurar a la predeterminada?",
};

const char MMSG_SPEED_SETTING_TITLE[3][22] PROGMEM = {
	"打印速度设置",
	"Print Speed Setting",
	"Ajuste de velocidad",
};

const char MMSG_POWER_SAVE_TITLE[3][30] PROGMEM = {
	"自动关闭电源设置",
	"Auto Power Off Setting",
	"Ajuste de apagado automático",
};

const char MMSG_POWEROFF_VALUE1[3][14] PROGMEM = {
	"   关闭",
	"  Disable",
	" Inhabilitar",
};

const char MMSG_POWEROFF_VALUE2[3][12] PROGMEM = {
	"  1分钟",
	"  1 min",
	" 1 minuto",
};

const char MMSG_POWEROFF_VALUE3[3][12] PROGMEM = {
	"  5分钟",
	"  5 min",
	"5 minutos",
};

const char MMSG_POWEROFF_VALUE4[3][12] PROGMEM = {
	"  10分钟",
	"  10 min",
	"10 minutos",
};

const char MMSG_POWEROFF_VALUE5[3][12] PROGMEM = {
	"  15分钟",
	"  15 min",
	"15 minutos",
};

const char MMSG_POWEROFF_VALUE6[3][12] PROGMEM = {
	"  30分钟",
	"  30 min",
	"30 minutos",
};

const char MMSG_SELF_TEST_TITLE[3][25] PROGMEM = {
	"开机自检",
	"Post",
	"Autoprueba de encendido"
};

const char MMSG_SKIP[3][10] PROGMEM = {
	"  跳过",
	"  Skip",
	"  Saltar"
};

const char MMSG_SELF_TEST_ITEM1[3][16] PROGMEM = {
	"喷头加热:",
	"Nozzle Heating:",
	"Boquilla:"
};

const char MMSG_SELF_TEST_ITEM2[3][16] PROGMEM = {
	"平台加热:",
	"Bed Heating:",
	"Plataforma"
};

const char MMSG_SELF_TEST_ITEM3[3][16] PROGMEM = {
	"料丝传感器:",
	"Runout Sensor:",
	"Filamento:"
};

const char MMSG_SELF_TEST_ITEM4[3][16] PROGMEM = {
	"X轴归位:",
	"X Axis Homing:",
	"X Axis Homing:"
};

const char MMSG_SELF_TEST_ITEM5[3][16] PROGMEM = {
	"Y轴归位:",
	"Y Axis Homing:",
	"Y Axis Homing:"
};

const char MMSG_SELF_TEST_ITEM6[3][16] PROGMEM = {
	"Z轴归位:",
	"Z Axis Homing:",
	"Z Axis Homing:"
};

const char MMSG_SELF_TEST_PASS[3][10] PROGMEM = {
	"正常",
	"PASS",
	"PASAR"
};

const char MMSG_SELF_TEST_NOTEMP[3][30] PROGMEM = {
	"无法读取温度!",
	"Temperature can't be read!",
	"Error de temperatura"
};

const char MMSG_SELF_TEST_NOHEAT[3][26] PROGMEM = {
	"加热失败!",
	"Heating fail!",
	"Falla de calentamiento"
};

const char MMSG_SELF_TEST_HEATING[3][15] PROGMEM = {
	"正在加热...",
	"Heating...",
	"Calefacción"
};

const char MMSG_SELF_TEST_RUNOUT_OK[3][16] PROGMEM = {
	"料丝已插入",
	"Filament OK",
	"Filamento ok"
};

const char MMSG_SELF_TEST_RUNOUT_FAIL[3][18] PROGMEM = {
	"未检测到料丝",
	"NO Filament",
	"NO filamento"
};

const char MMSG_SELF_TEST_MOVING[3][18] PROGMEM = {
	"正在移动...",
	"Moving...",
	"Emocionante"
};

const char MMSG_SELF_TEST_NOHOMING[3][16] PROGMEM = {
	"无法归位!",
	"Homing Fail!",
	"Homing fallo!"
};

const char MMSG_HELP_TITLE[3][6] PROGMEM = {
	"帮助",
	"Help",
	"Ayuda"
};

const char MMSG_HELP_GUIDE[3][18] PROGMEM = {
	"    使用向导",
	"   Quick Guide",
	"   Guía rápida"
};

const char MMSG_HELP_FAQ[3][20] PROGMEM = {
	"    常见问题",
	"      FAQ",
	"      FAQ"
};

const char MMSG_HELP_DIAG[3][22] PROGMEM = {
	"    故障诊断",
	"  Error Diagnosis",
	"   Diagnostico"
};

const char MMSG_HELP_VIDEO[3][20] PROGMEM = {
	"    在线视频",
	"   Online Video",
	"  Video en linea"
};

const char MMSG_SAVE_PRINTING[3][40] PROGMEM = {
	"正在保存打印进度...",
	"Saving print progress...",
	"Guardando progreso de impresión ..."
};

const char MMSG_RESUME_LINE1[3][36] PROGMEM = {
	"发现保存进度, 是否恢复打印?",
	"Found the save progress,",
	"Encontró el progreso de guardar,"
};

const char MMSG_RESUME_LINE2[3][26] PROGMEM = {
	"",
	"resume printing?",
	"reanudar la impresión?"
};

const char MMSG_RESUME_PRINTING[3][40] PROGMEM = {
	"正在恢复打印进度...",
	"Resuming print progress...",
	"Reanudando el progreso de impresión"
};

const char MMSG_HELPLIST_TITLE[3][10] PROGMEM = {
	"常见问题",
	"FAQ",
	"FAQ"
};

const char MMSG_HELPVIDEO_TITLE[3][18] PROGMEM = {
	"在线视频",
	"Online Video",
	"Video en linea"
};

const char MMSG_PRINTING_NOTICE[3][35] PROGMEM = { 
	"请暂停后再进行操作",
	"Please pause before proceeding",
	"Pausa antes de continuar",
};

const char MMSG_FILAMENT_CHOICE_EXTRUDER_TITLE[3][30] PROGMEM = {
	"选择喷头",
	"Select Nozzle",
	"Seleccionar boquilla",
};

const char MMSG_FILAMENT_LEFT_EXTRUDER[3][30] PROGMEM = {
	"    左喷头",
	"  Left Nozzle",
	" Boquilla izquierda",
};

const char MMSG_FILAMENT_RIGHT_EXTRUDER[3][30] PROGMEM = {
	"    右喷头",
	"  Right Nozzle",
	" Boquilla derecha",
};

const char MMSG_STOPPED[] PROGMEM = { "STOPPED. " };
const char MMSG_ERR_Z_HOMING[] PROGMEM = { "Home XY first" };
const char MMSG_ZPROBE_OUT[] PROGMEM = { "Z Probe past bed" };

#endif // 
