#pragma once

#include QMK_KEYBOARD_H

#include "keymap_canadian_multilingual.h"

#if !defined(CUSTOM_SAFE_RANGE)
#    define CUSTOM_SAFE_RANGE SAFE_RANGE
#endif

enum revived_key_keycodes {
  CD_FIRST = CUSTOM_SAFE_RANGE,
  CD_ECRC,
  CD_ETRM,
  CD_ICRC,
  CD_ITRM,
  CD_OCRC,
  CD_UCRC,
  CD_ACRC,
  CD_LAST,
};

enum custom_shift_keycodes {
  CS_FIRST = CD_LAST,
  CS_DOT,
  CS_COMM,
  CS_LCBR,
  CS_RCBR,
  CS_LPRN,
  CS_RPRN,
  CS_LBRC,
  CS_RBRC,
  CS_EURO,
  CS_DLR,
  CS_CENT,
  CS_DQUO,
  CS_QUOT,
  CS_APOS,
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
  CS_PIPE,
  CS_COLN,
  CS_MINS,
  CS_TILD,
  CS_P0,
  CS_P1,
  CS_P2,
  CS_P3,
  CS_P4,
  CS_P5,
  CS_P6,
  CS_P7,
  CS_P8,
  CS_P9,
  CS_PAST,
  CS_PPLS,
  CS_PSLS,
  CS_SPC,
  CS_LAST,
};

bool process_record_hedgestock(uint16_t keycode, keyrecord_t *record);

enum combos {
  COMM_DOT_SCLN,
  PPLS_MINS_PLMN,
  COLN_MINS_DIV,
  O_E_OE,
  A_E_AE,
  COMBO_SAFE_RANGE,
};
