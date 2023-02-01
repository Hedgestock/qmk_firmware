#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x4150
// #define DEVICE_VER      0x0002
// #define MANUFACTURER    Hedgestock
// #define PRODUCT         Hedgebox

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B5, B4, E6, D7 }
#define MATRIX_COL_PINS { B1, B3, B2, B6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXIS_COUNT 0
#define JOYSTICK_AXIS_RESOLUTION 8