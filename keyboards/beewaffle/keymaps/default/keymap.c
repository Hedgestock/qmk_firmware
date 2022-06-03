#include QMK_KEYBOARD_H
#include "keymap_french.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_5x6(
    KC_ESC,  FR_AMP,  FR_EACU, FR_DQUO, FR_APOS, FR_LPRN,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_SHIFT,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_CTRL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                                        KC_DEL,
                                    KC_ENT, KC_SPC, KC_BSPC,
                                                KC_ALT
  )
};