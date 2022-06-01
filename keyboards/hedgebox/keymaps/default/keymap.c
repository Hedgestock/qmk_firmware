#include QMK_KEYBOARD_H

enum layers {
  KEY, // Keyboard inputs
  JOY, // Controller inputs
  FUN, // Fuction keys and layout switching
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KEY] = LAYOUT_fightbox_16(
    KC_UP, KC_LEFT, KC_RIGHT, KC_DOWN,      KC_P, KC_K, KC_S, KC_D,
                                            KC_A, KC_B, KC_C, KC_R,
                  KC_UP,  LT(FUN,KC_ENT), KC_SPC,  KC_H
    ),
    [JOY] = LAYOUT_fightbox_16(
    JS_BUTTON0, JS_BUTTON1, JS_BUTTON2, JS_BUTTON3,     JS_BUTTON4, JS_BUTTON5, JS_BUTTON6, JS_BUTTON7,
                                                        JS_BUTTON8, JS_BUTTON9, JS_BUTTON10, JS_BUTTON11,
                      JS_BUTTON12,  LT(FUN,JS_BUTTON13), JS_BUTTON14,  JS_BUTTON15
    ),
    [FUN] = LAYOUT_fightbox_16(
    KC_NO, KC_NO, KC_NO, KC_NO,      TO(KEY), TO(JOY), KC_NO, KC_NO,
                                     KC_NO, KC_NO, KC_NO, KC_NO,
                  KC_NO,  KC_NO, KC_NO,  KC_NO
    )
};

