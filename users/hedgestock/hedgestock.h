#include QMK_KEYBOARD_H

#include "keymap_canadian_multilingual.h"

bool custom_shift(uint16_t keycode, keyrecord_t *record);

bool dead_key_macro(uint16_t keycode, keyrecord_t *record);

enum custom_shift_keycodes {
  CS_FIRST = SAFE_RANGE, // For ergodox_ez safe range varies, look into making that work
  CS_DOT,
  CS_COMM,
  CS_SPC,
  CS_LCBR,
  CS_RCBR,
  CS_LPRN,
  CS_RPRN,
  CS_EURO,
  CS_DLR,
  CS_QUOT,
  CS_ESZT,
  CS_CIRC, 
  CS_DIAE,
  CS_GRV,
  CS_RNGA, 
  CS_DTIL,
  CS_COPY,
  CS_LABK,
  CS_RABK,
  CS_AT,
  CS_AMPR,
  CS_COLN,
  CS_NOT,
  CS_TILD,
  CS_PAST,
  CS_PPLS,
  CS_LAST,
};

enum revived_key_keycodes {
  CD_FIRST = CS_LAST,
  CD_ECRC,
  CD_ETRM,
  CD_ICRC,
  CD_ITRM,
  CD_OCRC,
  CD_UCRC,
  CD_ACRC,
  CD_LAST,
};