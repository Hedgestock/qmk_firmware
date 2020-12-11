#pragma once

#include QMK_KEYBOARD_H

#include "keymap_canadian_multilingual.h"

#if !defined(CUSTOM_SAFE_RANGE)
#    define CUSTOM_SAFE_RANGE SAFE_RANGE
#endif

enum custom_shift_keycodes {
  CS_FIRST = CUSTOM_SAFE_RANGE,
  CS_DOT,
  CS_COMM,
  CS_SPC,
  CS_LCBR,
  CS_RCBR,
  CS_LPRN,
  CS_RPRN,
  CS_EURO,
  CS_DLR,
  CS_CENT,
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

enum combos {
  CB_SCLN,
  CB_PLMN,
  CB_DIV,
  CB_OE,
  CB_AE,
  CB_SAFE_RANGE,
};
