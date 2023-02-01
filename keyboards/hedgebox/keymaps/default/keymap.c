#include QMK_KEYBOARD_H

enum layers {
  KEY, // Keyboard inputs
  KEY2,// Secondary keyboard inputs
  ARR, // Keyboard inputs arrow based
  JOY, // Controller inputs
  FUN, // Fuction keys and layout switching
};

/* joystick config */
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
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
    JS_0, JS_1, JS_2, JS_3,                          JS_4, JS_5, JS_6,  JS_7,
                                                     JS_8, JS_9, JS_10, JS_11,
                      JS_12,  LT(FUN,JS_13), JS_14,  JS_15
    ),
    [FUN] = LAYOUT_numpad_4x4(
    KC_NO, KC_NO, KC_NO, KC_NO,      TO(KEY), TO(KEY2), TO(ARR), TO(JOY),
                                     KC_NO, KC_NO, KC_NO, KC_NO,
                  KC_NO,  KC_NO, KC_NO,  KC_NO
    )
};