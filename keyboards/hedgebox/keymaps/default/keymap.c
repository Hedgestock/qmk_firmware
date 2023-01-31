#include QMK_KEYBOARD_H

#include "keymap_french.h"

enum layers {
  KEY, // Keyboard inputs
  KEY2,// Secondary keyboard inputs
  ARR, // Keyboard inputs arrow based
  JOY, // Controller inputs
  FUN, // Fuction keys and layout switching
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KEY] = LAYOUT_numpad_4x4(
    FR_Q,    FR_S,    FR_D,     FR_F,       FR_U, FR_I, FR_O, FR_P,
                                            FR_J, FR_K, FR_L, FR_M,
                  KC_BSPC, LT(FUN, KC_DEL), KC_ENT,  KC_SPC
    ),
    [KEY2] = LAYOUT_numpad_4x4(
    FR_A,    FR_Z,    FR_E,     FR_R,       FR_W, FR_X, FR_C, FR_V,
                                            FR_T, FR_G, FR_Y, FR_H,
                  KC_BSPC, LT(FUN, KC_DEL), KC_ENT,  KC_SPC
    ),
    [ARR] = LAYOUT_numpad_4x4(
    KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT,      FR_U, FR_I, FR_O, FR_P,
                                            FR_J, FR_K, FR_L, FR_M,
                  KC_UP,  LT(FUN,KC_ENT), KC_SPC,  KC_H
    ),
    [JOY] = LAYOUT_numpad_4x4(
    JS_BUTTON0, JS_BUTTON1, JS_BUTTON2, JS_BUTTON3,     JS_BUTTON4, JS_BUTTON5, JS_BUTTON6, JS_BUTTON7,
                                                        JS_BUTTON8, JS_BUTTON9, JS_BUTTON10, JS_BUTTON11,
                      JS_BUTTON12,  LT(FUN,JS_BUTTON13), JS_BUTTON14,  JS_BUTTON15
    ),
    [FUN] = LAYOUT_numpad_4x4(
    KC_NO, KC_NO, KC_NO, KC_NO,      TO(KEY), TO(KEY2), TO(ARR), TO(JOY),
                                     KC_NO, KC_NO, KC_NO, KC_NO,
                  KC_NO,  KC_NO, KC_NO,  KC_NO
    )
};

