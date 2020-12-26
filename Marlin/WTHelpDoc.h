/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef WT_HELPL_DOC_H
#define WT_HELPL_DOC_H

const char HELP_TIP01_LINE1[3][60] PROGMEM = {
	"本界面显示TF卡中的打印文件",
	"This menu displays the print file in TF card.",
	"Este menú muestra el archivo de impresión en la tarjeta",
};

const char HELP_TIP01_LINE2[3][50] PROGMEM = {
	"点击文件名, 开始打印",
	"Click on the filename to start printing.",
	"TF.",
};

const char HELP_TIP01_LINE3[3][60] PROGMEM = {
	"点击返回按钮, 返回主界面",
	"Click the back button to return to the main interface.",
	"Haga clic en el nombre del archivo para comenzar a",
};

const char HELP_TIP01_LINE4[3][60] PROGMEM = {
	"点击上一步或下一步, 显示更多文件",
	"Click the previous or next button to display more files.",
	"imprimir. Haga clic en el botón Atrás para volver a la",
};

const char HELP_TIP01_LINE5[3][20] PROGMEM = {
	" ",
	" ",
	"interfaz principal.",
};

const char HELP_TIP01_LINE6[3][60] PROGMEM = {
	" ",
	" ",
	"Haga clic en el botón anterior o siguiente para mostrar",
};

const char HELP_TIP01_LINE7[3][15] PROGMEM = {
	" ",
	" ",
	"más archivos.",
};

const char HELP_TIP02_LINE1[3][60] PROGMEM = {
	"本界面显示当前打印的文件名, 及打印机的各项状态数据.",
	"This screen displays the information of current job.",
	"Esta pantalla muestra la información del trabajo actual.",
};

const char HELP_TIP02_LINE2[3][60] PROGMEM = {
	"打印剩余时间为预估, 与实际剩余时间会有一定的出入.",
	"The remaining time is estimated, it may be some",
	"El tiempo restante es estimado, puede ser algo diferente",
};

const char HELP_TIP02_LINE3[3][60] PROGMEM = {
	"点击暂定按钮, 打印任务暂停.",
	"different from the actual remaining time.",
	"del tiempo restante real. Haga clic en el botón de pausa",
};

const char HELP_TIP02_LINE4[3][60] PROGMEM = {
	"点击设置按钮, 进入打印参数设置界面.",
	"Click the pause button to pause the print job.",
	"para pausar el trabajo de impresión. Haga clic enel botón",
};

const char HELP_TIP02_LINE5[3][60] PROGMEM = {
	"点击关闭按钮, 当前打印任务将中止.",
	"Click the settings button to goto the print parameters",
	"de configuración para ir a la pantalla de configuraciónde",
};

const char HELP_TIP02_LINE6[3][60] PROGMEM = {
	" ",
	"settings screen. ",
	"los parámetros de impresión. Haga clic en el botón de",
};

const char HELP_TIP02_LINE7[3][60] PROGMEM = {
	" ",
	"Click the quit button to abort the current job.",
	"cerrar para abortar el trabajo actual.",
};

const char HELP_TIP03_LINE1[3][60] PROGMEM = {
	"料丝操作: 载入或卸载料丝",
	"Filament Operation: feeding or retracting the filament",
	"Filamento: alimentación o retracción del filamento.",
};

const char HELP_TIP03_LINE2[3][60] PROGMEM = {
	"温度设置: 改变喷头或热床的温度",
	"Temperature: adjust the temp of the nozzle or bed",
	"Temperatura: ajustar la temperatura de la boquilla o cama.",
};

const char HELP_TIP03_LINE3[3][50] PROGMEM = {
	"速度设置: 调节打印速度",
	"Speed: adjust the printing speed",
	"Velocidad: ajustar la velocidad de impresión.",
};

const char HELP_TIP03_LINE4[3][60] PROGMEM = {
	"打印完成关机: 打开或关闭打印完自动关机功能",
	"Auto Power Off: Automatic shutdown after printing",
	"Apagado automático: apagado automático después de",
};

const char HELP_TIP03_LINE5[3][60] PROGMEM = {
	"保存关机: 保存当前打印任务并自动关机, 重新上电后可以",
	"Save&Off: Save the current job and shut down, you",
	"imprimir. Guardar impresión: guarde el trabajo",
};

const char HELP_TIP03_LINE6[3][60] PROGMEM = {
	"继续打印",
	"can resume the printing after powering up again.",
	"actual y cierre,puede reanudar la impresión",
};

const char HELP_TIP03_LINE7[3][40] PROGMEM = {
	" ",
	" ",
	"después de volver a encenderlo.",
};

const char HELP_TIP04_LINE1[3][60] PROGMEM = {
	"本界面可调节当前打印任务的打印速度.",
	"This menu can adjust the printing speed of the current",
	"Este menú puede ajustar la parte de impresión del",
};

const char HELP_TIP04_LINE2[3][60] PROGMEM = {
	"请注意: 打印速度设置过快会明显降低打印质量.",
	"job.",
	"trabajo actual.",
};

const char HELP_TIP04_LINE3[3][60] PROGMEM = {
	"请尽量使用切片软件中的高速模式来缩短打印时间.",
	"Notice: Printing speed settings too fast will significantly",
	"Aviso: la configuración de la velocidad de impresión",
};

const char HELP_TIP04_LINE4[3][60] PROGMEM = {
	" ",
	"reduce the print quality.",
	"demasiado rápida reducirá significativamente la calidad",
};

const char HELP_TIP04_LINE5[3][60] PROGMEM = {
	" ",
	"Please try to use the high speed mode in the slicing",
	"de impresión.",
};

const char HELP_TIP04_LINE6[3][60] PROGMEM = {
	" ",
	"software to shorten the printing time.",
	"Intente utilizar el modo de alta velocidad en el software",
};

const char HELP_TIP04_LINE7[3][50] PROGMEM = {
	" ",
	" ",
	"de corte para acortar el tiempo de impresión.",
};

const char HELP_TIP05_LINE1[3][60] PROGMEM = {
	"喷头或热床无法读取温度或无法加热故障: 请检查喷头或",
	"Temperature can't be read or heating fail: Please check if",
	"La temperatura no se puede leer o la calefacción falla:",
};

const char HELP_TIP05_LINE2[3][60] PROGMEM = {
	"热床的接线是否松动.",
	"the cable of the nozzle or the bed is loose.",
	"compruebe si el cable de la boquilla o la cama están ",
};

const char HELP_TIP05_LINE3[3][60] PROGMEM = {
	"X,Y,Z轴无法归位故障: 如果喷头未运动, 请检查电机接线",
	"X, Y, Z axis homing fault: If the nozzle is not moving,",
	"sueltos. Falla de giro del eje X, Y, Z: si la boquilla nose",
};

const char HELP_TIP05_LINE4[3][60] PROGMEM = {
	"是否松动. 如果喷头运行到原点位置后未停止, 请检查限位.",
	"please check if the motor cable is loose.",
	"está moviendo, verifique siel cable del motor está suelto",
};

const char HELP_TIP05_LINE5[3][60] PROGMEM = {
	"开关是否损坏, 或是接线是否松动.",
	"If the nozzle don't stop after return to the zero position,",
	"Si la boquilla no se detiene después de volver a la",
};

const char HELP_TIP05_LINE6[3][60] PROGMEM = {
	" ",
	"please check if the endstop is damaged or the cable is",
	"posición cero, compruebe si el tope está da?ado o si el",
};

const char HELP_TIP05_LINE7[3][40] PROGMEM = {
	" ",
	"loose.",
	"cable está suelto.",
};

const char HELP_TIP06_LINE1[3][60] PROGMEM = {
	"自动进丝: 自动加热喷头并载入料丝.",
	"Filament Feed: Automatic heating of the nozzle and",
	"Entrada de filamento: calentamiento automático de la",
};

const char HELP_TIP06_LINE2[3][60] PROGMEM = {
	"自动退丝: 自动加热喷头并退出料丝.",
	"loading of the filament.",
	"boquilla y carga del filamento.",
};

const char HELP_TIP06_LINE3[3][60] PROGMEM = {
	"手动加热: 手动设置喷头和热床的温度并加热.",
	"Filament Retract: Automatically heats the nozzle and",
	"Salida de filamento: calienta automáticamente la boquilla",
};

const char HELP_TIP06_LINE4[3][50] PROGMEM = {
	" ",
	"retract the filament.",
	"y retrae el filamento.",
};

const char HELP_TIP06_LINE5[3][60] PROGMEM = {
	" ",
	"Preheat: Set the temperature of the nozzle or bed",
	"Precalentar: ajuste la temperatura de la boquilla y la",
};

const char HELP_TIP06_LINE6[3][30] PROGMEM = {
	" ",
	"and heating.",
	"cama y la calefacción.",
};

const char HELP_TIP07_LINE1[3][60] PROGMEM = {
	"点动模式: 喷头归位, 以及手动控制XYZ方向的运动.",
	"Jog Mode: Homing and manual control of XYZ motion.",
	"Modo de jog: Homing y control manual de movimiento",
};

const char HELP_TIP07_LINE2[3][60] PROGMEM = {
	"平台校准: 对打印平台的水平度进行调节，使其平行于喷头",
	"Level Bed: Adjust the level of the printing platform so",
	"XYZ. Nivelar plataforma: ajuste el nivel de la plataforma",
};

const char HELP_TIP07_LINE3[3][60] PROGMEM = {
	"运行的XY平台.",
	"that it is parallel to the XY stage of the nozzle.",
	"de impresión de modo que quede paralelo a la etapa",
};

const char HELP_TIP07_LINE4[3][60] PROGMEM = {
	"Z轴偏置: 微调喷头与平台的相对高度，可调大或调小打印时",
	"Z Offset: Fine-tune the relative height of the nozzle and",
	"XY de la boquilla.",
};

const char HELP_TIP07_LINE5[3][60] PROGMEM = {
	"喷头与平台的间隙.",
	"the platform, it can adjust the gap between the nozzle",
	"Desfase Z: ajuste la altura relativa de la boquilla y la",
};

const char HELP_TIP07_LINE6[3][60] PROGMEM = {
	" ",
	"and the platform when printing.",
	"plataforma, puede ajustar el espacio entre la boquilla",
};

const char HELP_TIP07_LINE7[3][30] PROGMEM = {
	" ",
	" ",
	"y la plataforma al imprimir.",
};

const char HELP_TIP08_LINE1[3][60] PROGMEM = {
	"接近开关高度调节: 调节接近开关与喷头的相对位置. 接近",
	"Proximity Height: Adjust the relative position of the",
	"Proximidad: ajuste la posición relativa del interruptor",
};

const char HELP_TIP08_LINE2[3][60] PROGMEM = {
	"开关过高, 会导致自动调平时喷头与平台撞击. 开关过低,",
	"proximity switch to the nozzle.",
	"de proximidad al cabezal rociador.",
};

const char HELP_TIP08_LINE3[3][60] PROGMEM = {
	"打印时容易刮到模型.",
	"Motor Off: When the motor is turned on, the position",
	"Motor apagado: cuando el motor está encendido, la",
};

const char HELP_TIP08_LINE4[3][60] PROGMEM = {
	"关闭电机: 电机打开时, 位置会被锁定无法移动. 当你需要",
	"is locked and cannot be moved.",
	"posición se bloquea y no se puede mover.",
};

const char HELP_TIP08_LINE5[3][60] PROGMEM = {
	"手动调节喷头或平台的位置时, 需要首先关闭电机, 解除电",
	" ",
	" ",
};

const char HELP_TIP08_LINE6[3][60] PROGMEM = {
	"机的锁定.",
	" ",
	" ",
};

const char HELP_TIP09_LINE1[3][60] PROGMEM = {
	"对喷头和平台进行一起加热, 或是仅加热其中的一其.",
	"The nozzle and the bed are heated together or only",
	"La boquilla y la cama se calientan juntas o solo una de",
};

const char HELP_TIP09_LINE2[3][40] PROGMEM = {
	"不需要加热的项目, 可将温度设置为0.",
	"one of them is heated.",
	"ellas se calienta.",
};

const char HELP_TIP09_LINE3[3][60] PROGMEM = {
	"点击确定, 开始加热.",
	"For item that do not require heating, set the",
	"Para los artículos que no requieren calefacción, ajustela",
};

const char HELP_TIP09_LINE4[3][42] PROGMEM = {
	"点击取消, 关闭加热并返回.",
	"temperature to zero.",
	"temperatura a cero.",
};

const char HELP_TIP09_LINE5[3][60] PROGMEM = {
	" ",
	"Click OK to start heating.",
	"Haga clic en el botón Aceptar para iniciar elcalentamiento",
};

const char HELP_TIP09_LINE6[3][60] PROGMEM = {
	" ",
	"Click Cancel to turn off heating and return.",
	"Haga clic en el botón Cancelar para apagar la calefacción",
};

const char HELP_TIP09_LINE7[3][10] PROGMEM = {
	" ",
	" ",
	"y volver.",
};

const char HELP_TIP10_LINE1[3][60] PROGMEM = {
	"点击X左边的按钮, 喷头向左移动, 三个按钮的移动距离",
	"Click the left button of X, the nozzle moves to the ",
	"Haga clic en el botón izquierdo de X, la boquilla se",
};

const char HELP_TIP10_LINE2[3][60] PROGMEM = {
	"分别是50mm, 10mm, 1mm.",
	"left, the distance of the three buttons is 50mm, 10mm",
	"mueve hacia la izquierda, la distancia de los tres botones",
};

const char HELP_TIP10_LINE3[3][60] PROGMEM = {
	"点击Y左边的按钮, 平台向前移动, 三个按钮的移动距离",
	"and 1mm.",
	"es de 50mm, 10mm y 1mm.",
};

const char HELP_TIP10_LINE4[3][60] PROGMEM = {
	"分别是50mm, 10mm, 1mm.",
	"Click the left button of Y, the bed moves forward, ",
	"Haga clic en el botón izquierdo de Y, la boquilla se",
};

const char HELP_TIP10_LINE5[3][60] PROGMEM = {
	"点击Z左边的按钮, 平台向上移动, 三个按钮的移动距离",
	"the distance is same as X.",
	"mueve hacia adelante, la distancia es igual a X.",
};

const char HELP_TIP10_LINE6[3][60] PROGMEM = {
	"分别是10mm, 1mm, 0.1mm.",
	"Click the left button of Z. the bed moves upwards.",
	"Haga clic en el botón izquierdo de Z. la cama se mueve",
};

const char HELP_TIP10_LINE7[3][60] PROGMEM = {
	" ",
	"The distance is 10mm, 1mm amd 0.1mm.",
	"hacia arriba. La distancia es de 10mm, 1mm amd 0.1mm.",
};

const char HELP_TIP11_LINE1[3][60] PROGMEM = {
	"Wifi网络设置: 配置Wifi网络, 以及Wifi设备OTA升级.",
	"Wifi Setting: Configuring Wifi network, and Wifi device",
	"Red wifi: configuración de la red Wifi y actualización de",
};

const char HELP_TIP11_LINE2[3][40] PROGMEM = {
	"语言设置: 设置界面的显示语言.",
	"OTA upgrade.",
	"OTA del dispositivo Wifi.",
};

const char HELP_TIP11_LINE3[3][60] PROGMEM = {
	"设备信息: 显示设备的打印时间和版本信息.",
	"Language Setting: Set the display language of the",
	"Idioma: establece el idioma de visualización de lainterfaz",
};

const char HELP_TIP11_LINE4[3][60] PROGMEM = {
	" ",
	"interface.",
	"Informacion: muestra el tiempo de impresión deldispositivo",
};

const char HELP_TIP11_LINE5[3][60] PROGMEM = {
	" ",
	"Machine Info: Display device print time and version.",
	"y la información de la versión.",
};

const char HELP_TIP12_LINE1[3][60] PROGMEM = {
	"打印完成关机: 打开或关闭打印完自动关机功能.",
	"Auto Power Off: Automatic shutdown after printing.",
	"Apagado automático: apagado automático después de",
};

const char HELP_TIP12_LINE2[3][60] PROGMEM = {
	"开机自检: 打印时启动时, 自动对主要部件进行检测.",
	"Post: Automatic testing the main parts when printer",
	"imprimir. Autoprueba: Prueba automática de las",
};

const char HELP_TIP12_LINE3[3][60] PROGMEM = {
	"节电模式: 打印处于待机状态，且无操作时，在等待一段时间",
	"power on.",
	"partes principales cuando la impresora está encendida.",
};

const char HELP_TIP12_LINE4[3][60] PROGMEM = {
	"后自动关闭电源，以节约能源.",
	"Power Save Mode: When printing is in standby mode",
	"Ahorro de energía: cuando la impresión está en modo de",
};

const char HELP_TIP12_LINE5[3][60] PROGMEM = {
	" ",
	"and there is no operation, it will automatically turn off",
	"espera y no se realiza ninguna operación, se apagará",
};

const char HELP_TIP12_LINE6[3][58] PROGMEM = {
	" ",
	"the power after waiting for a period of time to save",
	"automáticamente después de esperar un período de",
};

const char HELP_TIP12_LINE7[3][35] PROGMEM = {
	" ",
	"energy.",
	"tiempo para ahorrar energía.",
};

const char HELP_TIP13_LINE1[3][60] PROGMEM = {
	"恢复出厂设置: 将打印机设置参数恢复至出厂默认设置.",
	"Restore Default: Restore printer setup parameters to",
	"Restaurar memoria: restaura los parámetros de config",
};

const char HELP_TIP13_LINE2[3][60] PROGMEM = {
	" ",
	"factory defaults.",
	"uración de la impresora a los valores predeterminados",
};

const char HELP_TIP13_LINE3[3][18] PROGMEM = {
	" ",
	" ",
	"de fábrica.",
};

const char HELP_TIP14_LINE1[3][60] PROGMEM = {
	"打印处于待机状态，且无操作时，在等待一段时间后自动关闭",
	"When printing is in standby mode and there is no",
	"Cuando la impresión está en modo de espera y no hay",
};

const char HELP_TIP14_LINE2[3][60] PROGMEM = {
	"电源，以节约能源. 等待时间可设置从1分钟至30分钟.",
	"operation, it will automatically turn off the power after",
	"operación, se apagará automáticamente después de",
};

const char HELP_TIP14_LINE3[3][60] PROGMEM = {
	"选择关闭将禁用节电功能.",
	"waiting for a period of time to save energy.",
	"esperar un período de tiempo para ahorrar energía.",
};

const char HELP_TIP14_LINE4[3][60] PROGMEM = {
	" ",
	"The waiting time can be set from 1 minute to 30",
	"El tiempo de espera se puede configurar desde 1 minuto",
};

const char HELP_TIP14_LINE5[3][20] PROGMEM = {
	" ",
	"minutes.",
	"hasta 30 minutos.",
};

const char HELP_TIP14_LINE6[3][60] PROGMEM = {
	" ",
	"Selecting Off will disable the power save feature.",
	"Si selecciona Desactivado, se desactivará la función de",
};

const char HELP_TIP14_LINE7[3][20] PROGMEM = {
	" ",
	" ",
	"ahorro de energía.",
};

const char HELP_TIP15_TITLE[3][50] PROGMEM = {
	"模型不粘平台或难以取下",
	"Model is not sticky platform or hard to remove",
	"Modelo de plataforma no pegajosa o difícil de",
};

const char HELP_TIP15_LINE1[3][60] PROGMEM = {
	"喷头与平台的间隙过大, 会导致模型粘不住平台.",
	"The gap between the nozzle and the bed is too large,",
	"El espacio entre la boquilla y la cama es demasiado gran",
};

const char HELP_TIP15_LINE2[3][60] PROGMEM = {
	"喷头间隙过小, 会导致模型与平台粘附太紧，难以取下.",
	"which will cause the model to stick to the platform.",
	"de, lo que hará que el modelo se adhiera a la plataforma",
};

const char HELP_TIP15_LINE3[3][60] PROGMEM = {
	"请使用Z轴偏置调节功能, 调节喷头与平台的间隙.",
	"If the gap between the nozzles is too small, the",
	"Si el espacio entre las boquillas es demasiado pequeno, la",
};

const char HELP_TIP15_LINE4[3][60] PROGMEM = {
	" ",
	"adhesion between the model and the platform will be",
	"adherencia entre el modelo y la plataforma será demasi",
};

const char HELP_TIP15_LINE5[3][60] PROGMEM = {
	" ",
	"too tight and it will be difficult to remove.",
	"ado estrecha y será difícil de eliminar. Utilice la fun",
};

const char HELP_TIP15_LINE6[3][60] PROGMEM = {
	" ",
	"Please use the Z-axis offset adjustment function to ",
	"ción de ajuste de desplazamiento del eje Z para ajustar",
};

const char HELP_TIP15_LINE7[3][60] PROGMEM = {
	" ",
	"adjust the gap between the nozzle and the platform.",
	"el espacio entre la boquilla y la plataforma.",
};

const char HELP_TIP16_TITLE[3][30] PROGMEM = {
	"喷头撞平台",
	"The nozzle hits the bed",
	"La boquilla golpea la cama",
};

const char HELP_TIP16_LINE1[3][60] PROGMEM = {
	"在自动调平时, 如果发生喷头撞击平台的问题, 可能是接近",
	"When automatic leveling, if the nozzle hitting the bed, it",
	"Cuando se realiza una nivelación automática, sila boquill",
};

const char HELP_TIP16_LINE2[3][60] PROGMEM = {
	"开关与喷头的相对位置过高导致的.",
	"may be caused by the relative position of the proximity",
	"golpea el lecho, puede deberse a la posición relativa del",
};

const char HELP_TIP16_LINE3[3][60] PROGMEM = {
	"如果之前更换过喷头组件, 请松开固定喷头的螺丝后, 将喷头",
	"switch and the nozzle being too high.",
	"interruptor de proximidad y la boquilla es demasiado alta.",
};

const char HELP_TIP16_LINE4[3][60] PROGMEM = {
	"向上推至最高处, 然后锁紧.",
	"Please use the proximity switch height adjustment fun",
	"Utilice la función de ajuste de altura del interruptor de",
};

const char HELP_TIP16_LINE5[3][60] PROGMEM = {
	"其次, 请使用接近开关高度调节功能, 降低接近开关的高度.",
	"ction to reduce the height of the proximity switch.",
	"proximidad para reducir la altura del interruptor de proxi",
};

const char HELP_TIP16_LINE6[3][60] PROGMEM = {
	"如仍无法解决问题, 可能是接近开关发生故障, 请联系我们",
	"If the problem still cannot be solved, the proximity switch",
	"midad.Si el problema aún no se puede resolver, el interru",
};

const char HELP_TIP16_LINE7[3][60] PROGMEM = {
	"的售后更换配件.",
	"may be faulty. Please contact us to replace the parts.",
	"ptor de proximidad puede estar defectuoso.",
};

const char HELP_TIP17_TITLE[3][30] PROGMEM = {
	"喷头移动时撞机身",
	"The nozzle hits the frame",
	"La boquilla golpea el marco",
};

const char HELP_TIP17_LINE1[3][62] PROGMEM = {
	"可能是限位开关或XY电机出现问题.",
	"Can be a problem with the limit switch or XY motor.",
	"Puede ser un problema con el interruptor de límite o",
};

const char HELP_TIP17_LINE2[3][60] PROGMEM = {
	"首先, 请检查XY的限位开关和电机的接口处是否有松动.",
	"First, check if the XY limit switch and motor interface",
	"el motor XY.",
};

const char HELP_TIP17_LINE3[3][60] PROGMEM = {
	"其次, 请使用故障诊断功能，逐步排查故障点.",
	"are loose.",
	"Primero, verifique si el interruptor de límite XY y la",
};

const char HELP_TIP17_LINE4[3][60] PROGMEM = {
	"然后联系我们的售后更换配件.",
	"Secondly, please use the fault diagnosis function to",
	"interfaz del motor están sueltos.",
};

const char HELP_TIP17_LINE5[3][60] PROGMEM = {
	" ",
	"check the fault point step by step.",
	"En segundo lugar, utilice la función de diagnóstico de",
};

const char HELP_TIP17_LINE6[3][60] PROGMEM = {
	" ",
	"Then contact us to replace the parts.",
	"fallas para verificar el punto de falla paso a paso.",
};

const char HELP_TIP17_LINE7[3][60] PROGMEM = {
	" ",
	" ",
	"Entonces contáctenos para reemplazar las partes.",
};

const char HELP_TIP18_TITLE[3][40] PROGMEM = {
	"自动调平失败",
	"Automatic leveling failure",
	"Fallo de nivelación automática",
};

const char HELP_TIP18_LINE1[3][60] PROGMEM = {
	"首先请检查打印平台是否安装到位.",
	"First check if the print platform is installed.",
	"Primero verifique si la plataforma de impresión está",
};

const char HELP_TIP18_LINE2[3][60] PROGMEM = {
	"其次, 请使用接近开关高度调节功能，降低接近开关的高度.",
	"Secondly, please use the proximity switch height adjust",
	"instalada. En segundo lugar, utilice la función de ajuste",
};

const char HELP_TIP18_LINE3[3][60] PROGMEM = {
	"如仍无法解决问题, 可能是接近开关发生故障, 请联系",
	"ment function to reduce the height of the proximity.",
	"de altura del interruptor de proximidad para reducir la",
};

const char HELP_TIP18_LINE4[3][60] PROGMEM = {
	"我们的售后更换配件.",
	"If the problem still cannot be solved, the proximity",
	"altura del interruptor de proximidad. Si el problema aún",
};

const char HELP_TIP18_LINE5[3][60] PROGMEM = {
	" ",
	"may be faulty. Then contact us to replace the parts.",
	"no se puede resolver, el interruptor de proximidad puede",
};

const char HELP_TIP18_LINE6[3][60] PROGMEM = {
	" ",
	" ",
	"estar defectuoso. Por favor, póngase en contacto con",
};

const char HELP_TIP18_LINE7[3][40] PROGMEM = {
	" ",
	" ",
	"nosotros para reemplazar las piezas.",
};

const char HELP_TIP19_TITLE[3][40] PROGMEM = {
	"喷头无法加热",
	"The nozzle cannot be heated",
	"La boquilla no se puede calentar",
};

const char HELP_TIP19_LINE1[3][60] PROGMEM = {
	"首先请检查喷头组件的接线处是否有松动或损坏.",
	"First check the connection of the nozzle assembly for",
	"Primero, verifique que la conexión del conjunto de la",
};

const char HELP_TIP19_LINE2[3][60] PROGMEM = {
	"其次, 请检查挤出器组件的排线插口处是否有松动或损坏, ",
	"looseness or damage.",
	"boquilla no esté floja o danada.",
};

const char HELP_TIP19_LINE3[3][60] PROGMEM = {
	"以及排线的弯折位置是否有破损.",
	"Next, check the cable connector of the extruder assem",
	"A continuación, verifique que el conector del cable del",
};

const char HELP_TIP19_LINE4[3][60] PROGMEM = {
	"如仍无法解决问题, 请联系我们的售后部门, 我们的技术",
	"bly for looseness or damage, and if the bending position",
	"conjunto de la extrusora no esté flojo o danado, y si",
};

const char HELP_TIP19_LINE5[3][50] PROGMEM = {
	"工程师会提供更详细的指导.",
	"of the cable is broken.",
	"la posición de flexión del cable está rota.",
};

const char HELP_TIP19_LINE6[3][60] PROGMEM = {
	" ",
	"If the problem still cannot be solved, Please contact us.",
	"Si el problema no se puede resolver, contáctenos.",
};

const char HELP_TIP20_TITLE[3][40] PROGMEM = {
	"平台无法加热",
	"The bed cannot be heated",
	"La cama no se puede calentar",
};

const char HELP_TIP20_LINE1[3][60] PROGMEM = {
	"首先请检查平台下面热床的接线处是否有松动或损坏.",
	"First check the cable of the hot bed below the platform",
	"Primero, verifique que el cable de la cama caliente debajo",
};

const char HELP_TIP20_LINE2[3][50] PROGMEM = {
	"其次, 请检查热床线缆是否有破损.",
	"for looseness or damage.",
	"de la plataforma no esté flojo ni danado.",
};

const char HELP_TIP20_LINE3[3][60] PROGMEM = {
	"如仍无法解决问题, 请联系我们的售后部门, 我们的技术",
	"Next, please check if the hot bed cable is damaged.",
	"A continuación, compruebe si el cable de la cama caliente",
};

const char HELP_TIP20_LINE4[3][60] PROGMEM = {
	"工程师会提供更详细的指导.",
	"If the problem still cannot be solved, Please contact us.",
	"está danado.",
};

const char HELP_TIP20_LINE5[3][60] PROGMEM = {
	" ",
	" ",
	"Si el problema no se puede resolver, contáctenos.",
};

const char HELP_VIDEO1[3][46] PROGMEM = {
	"[视频]喷嘴更换与疏通",
	"[Video]Nozzle replacement and unclog",
	"[Vídeo]Reemplazo de boquilla y desatascar",
};

const char HELP_VIDEO1_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTIzMDE4NA",
	"http://player.youku.com/embed/XNDQ1MTIzMDE4NA",
	"http://player.youku.com/embed/XNDQ1MTIzMDE4NA",
};

const char HELP_VIDEO2[3][40] PROGMEM = {
	"[视频]更换喷头组件",
	"[Video]Replacement nozzle module",
	"[Vídeo]Módulo de boquilla de repuesto",
};

const char HELP_VIDEO2_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTE5OTM4MA",
	"http://player.youku.com/embed/XNDQ1MTE5OTM4MA",
	"http://player.youku.com/embed/XNDQ1MTE5OTM4MA",
};

const char HELP_VIDEO3[3][38] PROGMEM = {
	"[视频]更换挤出器组件",
	"[Video]Replace the extruder module",
	"[Vídeo]Reemplace el módulo extrusor",
};

const char HELP_VIDEO3_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTE4NDMzNg",
	"http://player.youku.com/embed/XNDQ1MTE4NDMzNg",
	"http://player.youku.com/embed/XNDQ1MTE4NDMzNg",
};

const char HELP_VIDEO4[3][48] PROGMEM = {
	"[视频]更换接近开关",
	"[Video]Replace the proximity switch",
	"[Vídeo]Reemplace el interruptor de proximidad",
};

const char HELP_VIDEO4_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
};

const char HELP_VIDEO5[3][36] PROGMEM = {
	"[视频]更换热床",
	"[Video]Replace the hot bed",
	"[Vídeo]Reemplazar la cama caliente",
};

const char HELP_VIDEO5_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTIwMjQ5Mg",
	"http://player.youku.com/embed/XNDQ1MTIwMjQ5Mg",
	"http://player.youku.com/embed/XNDQ1MTIwMjQ5Mg",
};

const char HELP_VIDEO6[3][40] PROGMEM = {
	"[视频]更换喷头排线",
	"[Video]Replace the extruder cable",
	"[Vídeo]Reemplace el cable del extrusor",
};

const char HELP_VIDEO6_URL[3][30] PROGMEM = {
	"http://www.weedo3d.cn",
	"http://www.weedo.ltd",
	"http://www.weedo.ltd",
};

const char HELP_VIDEO7[3][30] PROGMEM = {
	"[视频]更换X线束",
	"[Video]Replace the X Cable",
	"[Vídeo]Reemplace el cable X",
};

const char HELP_VIDEO7_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTE3MTkzMg",
	"http://player.youku.com/embed/XNDQ1MTE3MTkzMg",
	"http://player.youku.com/embed/XNDQ1MTE3MTkzMg",
};

const char HELP_VIDEO8[3][44] PROGMEM = {
	"[视频]更换料丝检测传感器",
	"[Video]Replace the runout sensor",
	"[Vídeo]Reemplace el sensor de desviación",
};

const char HELP_VIDEO8_URL[3][46] PROGMEM = {
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
	"http://player.youku.com/embed/XNDQ1MTE4ODcwOA",
};

const char DIAG_PAGE1_TITLE[3][26] PROGMEM = {
	"第1步 X电机诊断",
	"1. X motor diagnosis",
	"1. X diagnostico motor",
};

const char DIAG_PAGE1_LINE1[3][60] PROGMEM = {
	"请手动将喷头移至打印机的中间位置, 将平台移至最底部.",
	"Manually move the nozzle to the middle of the printer",
	"Mueva manualmente la boquilla al centro de la impresora",
};

const char DIAG_PAGE1_LINE2[3][45] PROGMEM = {
	"然后点击开始.",
	"and move the platform to the bottom.",
	"y mueva la plataforma a la parte inferior.",
};

const char DIAG_PAGE1_LINE3[3][30] PROGMEM = {
	" ",
	"Then click on Start.",
	"Luego haga clic en Iniciar.",
};

const char DIAG_PAGE2_LINE1[3][54] PROGMEM = {
	"喷头将先向左移动5cm, 再向右移动5cm. 请观察喷头",
	"The nozzle will move 5cm to the left and 5cm to the",
	"La boquilla se moverá 5 cm a la izquierda y 5 cm a",
};

const char DIAG_PAGE2_LINE2[3][58] PROGMEM = {
	"移动是否正常. ",
	"right. If there is any abnormality, please turn off",
	"la derecha. Si hay alguna anomalía, apague la impresora",
};

const char DIAG_PAGE2_LINE3[3][48] PROGMEM = {
	"如有异常, 请关闭打印机, 检查X电机和连线.",
	"the printer and check the X motor and cable.",
	"y compruebe el motor X y el cableado.",
};

const char DIAG_PAGE3_TITLE[3][35] PROGMEM = {
	"第2步 X限位开关诊断",
	"1. X endstop diagnosis",
	"1. X diagnóstico de finalización",
};

const char DIAG_PAGE3_LINE1[3][57] PROGMEM = {
	"喷头将向左移动至X限位开关处. 请观察喷头向左移动至",
	"The nozzle will move to the left to the X endstop",
	"La boquilla se moverá hacia la derecha hasta el tope X",
};

const char DIAG_PAGE3_LINE2[3][56] PROGMEM = {
	"限位开关后是否立即停止.",
	"and stop immediately. If there is any abnormality,",
	"y se detendrá inmediatamente. Si hay alguna anomalía,",
};

const char DIAG_PAGE3_LINE3[3][56] PROGMEM = {
	"如有异常, 请关闭打印机, 检查X限位开关和连线.",
	"please turn off the printer and check the X endstop",
	"apague la impresora y verifique el tope X y el cable.",
};

const char DIAG_PAGE3_LINE4[3][28] PROGMEM = {
	"如无异常, 点击下一步继续.",
	"and cable.",
	" ",
};

const char DIAG_PAGE4_TITLE[3][25] PROGMEM = {
	"第3步 Y电机诊断",
	"3. Y motor diagnosis",
	"3. Y diagnostico motor",
};

const char DIAG_PAGE4_LINE1[3][52] PROGMEM = {
	"平台将先向后移动5cm, 再向前移动5cm. 请观察平台",
	"The bed will move 5cm backward and then 5cm",
	"La boquilla se moverá 5 cm hacia adelante y luego",
};

const char DIAG_PAGE4_LINE2[3][57] PROGMEM = {
	"移动是否正常. ",
	"forward. If there is any abnormality, please turn off",
	"5 cm hacia atrás. Si hay alguna anomalía, apague la",
};

const char DIAG_PAGE4_LINE3[3][47] PROGMEM = {
	"如有异常, 请关闭打印机, 检查Y电机和连线.",
	"the printer and check the Y motor and cable.",
	"impresora y compruebe el motor Y el cable.",
};

const char DIAG_PAGE5_TITLE[3][35] PROGMEM = {
	"第4步 Y限位开关诊断",
	"4. Y endstop diagnosis",
	"4. Y diagnóstico de finalización",
};

const char DIAG_PAGE5_LINE1[3][53] PROGMEM = {
	"平台将向后移动至Y限位开关处. 请观察喷头向后移动至",
	"The bed will move backwards to the Y endstop",
	"La boquilla se moverá hacia atrás hasta el tope en",
};

const char DIAG_PAGE5_LINE2[3][53] PROGMEM = {
	"限位开关后是否立即停止.",
	"and stop immediately. If there is any abnormality,",
	"Y y se detendrá inmediatamente. Si hay alguna",
};

const char DIAG_PAGE5_LINE3[3][54] PROGMEM = {
	"如有异常, 请关闭打印机, 检查Y限位开关和连线.",
	"please turn off the printer and check the Y endstop",
	"anomalía, apague la impresora y verifique el tope",
};

const char DIAG_PAGE5_LINE4[3][28] PROGMEM = {
	"如无异常, 点击下一步继续.",
	"and cable.",
	"final y el cable.",
};

const char DIAG_PAGE6_TITLE[3][25] PROGMEM = {
	"第5步 Z电机诊断",
	"5. Z motor diagnosis",
	"5. Z diagnostico motor",
};

const char DIAG_PAGE6_LINE1[3][53] PROGMEM = {
	"喷头将先向上移动10cm, 再向下移动5cm. 请观察平台移动",
	"The nozzle will move up 10cm and then down 5cm.",
	"La cama se moverá hacia arriba 10 cm y luego hacia",
};

const char DIAG_PAGE6_LINE2[3][60] PROGMEM = {
	"是否正常. ",
	"If there is any abnormality, please turn off the printer",
	"abajo 5 cm. Si hay alguna anomalía, apague la impresora,",
};

const char DIAG_PAGE6_LINE3[3][50] PROGMEM = {
	"如有异常, 请关闭打印机, 检查Z电机和连线.",
	"check the Z motor and cable.",
	"compruebe el motor Z y el cable.",
};

const char DIAG_PAGE7_TITLE[3][35] PROGMEM = {
	"第6步 Z限位开关诊断",
	"6. Z endstop diagnosis",
	"6. Z diagnóstico de finalización",
};

const char DIAG_PAGE7_LINE1[3][51] PROGMEM = {
	"平台将向下移动至Z限位开关处. 请观察平台向下移动至",
	"The bed will move down to the Z endstop and stop",
	"La cama se moverá hacia abajo hasta el tope Z y",
};

const char DIAG_PAGE7_LINE2[3][60] PROGMEM = {
	"限位开关后是否立即停止.",
	"immediately. If there is any abnormality, please turn off",
	"se detendrá de inmediato. Si hay alguna anomalía,",
};

const char DIAG_PAGE7_LINE3[3][55] PROGMEM = {
	"如有异常, 请关闭打印机, 检查Z限位开关和连线.",
	"the printer, check the Z endstop and cable.",
	"apague la impresora, verifique el tope Z y el cable.",
};

const char DIAG_PAGE9_TITLE[3][32] PROGMEM = {
	"第7步 喷头组件诊断",
	"7. Nozzle diagnostics",
	"7. Diagnóstico de la boquilla",
};

const char DIAG_PAGE9_LINE1[3][53] PROGMEM = {
	"请向挤出器组件中插入PLA料丝, 然后等待喷头加热完成.",
	"Insert PLA and wait for the nozzle to heat up",
	"Inserte PLA y espere a que la boquilla se caliente",
};

const char DIAG_PAGE9_LINE2[3][56] PROGMEM = {
	"请观察喷嘴中是否有料线挤出. ",
	"If no filament extrusion, and extruder motor makes a",
	"Si no hay extrusión de filamentos, y el motor del ext",
};

const char DIAG_PAGE9_LINE3[3][60] PROGMEM = {
	"如没有料线挤出. 请倾听挤出器电机是否发出哒哒声. ",
	"frictional sound, the nozzle may be clogged. If no sound",
	"rusor produce un sonido de fricción, la boquilla puede",
};

const char DIAG_PAGE9_LINE4[3][60] PROGMEM = {
	"如挤出器电机发出哒哒声, 表示喷头堵塞, 请更换喷头组件.",
	"from the extruder motor, the extruder module may",
	"estar obstruida. Si no hay sonido del motor del extrusor,",
};

const char DIAG_PAGE9_LINE5[3][54] PROGMEM = {
	"如没有哒哒声, 表示挤出器组件故障, 请更换挤出器组件.",
	"be faulty.",
	"el módulo del extrusor puede estar defectuoso.",
};

const char DIAG_PAGE9_LINE7[3][35] PROGMEM = {
	"请检查喷头组件及接口.",
	"Check the nozzle and cable",
	"Compruebe la boquilla y el cable",
};


#endif 
