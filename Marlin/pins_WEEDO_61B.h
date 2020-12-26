/**
* Copyright (C) 2020 WEEDO3D
* Author: perron@163.com
*/

#ifndef BOARD_NAME
#define BOARD_NAME "WEEDO 61B"
#endif

#define LARGE_FLASH true


// X Endstop
#define X_MIN_PIN           35
#define X_MAX_PIN           -1

// Y Endstop
#define Y_MIN_PIN			34
#define Y_MAX_PIN			37

// Z Endstop
#define Z_MIN_PIN			4
#define Z_MIN_PROBE_PIN		33

// X Motor
#define X_STEP_PIN         58
#define X_DIR_PIN          59
#define X_ENABLE_PIN       57

// Y Motor
#define Y_STEP_PIN         61
#define Y_DIR_PIN          62
#define Y_ENABLE_PIN       60

// Z Motor
#define Z_STEP_PIN         23
#define Z_DIR_PIN          24
#define Z_ENABLE_PIN       22

// B Motor
#define E1_STEP_PIN        55
#define E1_DIR_PIN         56
#define E1_ENABLE_PIN      54

// A Motor
#define E0_STEP_PIN        64
#define E0_DIR_PIN         65
#define E0_ENABLE_PIN      63

// Extruder0
#define FAN_PIN           9 // IO pin. Buffer needed
#define HEATER_0_PIN     10   // EXTRUDER 1
#define TEMP_0_PIN         13   // ANALOG NUMBERING

// Heater Bed
#define HEATER_BED_PIN		8    // BED
#define TEMP_BED_PIN         14   // ANALOG NUMBERING

#define POWEROFFPIN 28

// Filament out sensor
#define FIL_RUNOUT_PIN     36

// Card Reader
#define SDSS               53
#define SD_DETECT_PIN 49

#define SDPOWER            -1
#define PS_ON_PIN			28

// BUZZ
#define BEEPER_PIN		 48

// UART LED
#define LED_PIN            13

// AIR FILTER FAN
#define AIR_FAN_PIN			72

