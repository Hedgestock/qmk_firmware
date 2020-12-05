/* Copyright 2019 Stefano Marago'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/*
 * The 25% SuperMicro keyboard: a pure - full features - "Alpha 26" keymap on Gherkin, compatible also with 28 and 30 keys layouts
 * See https://github.com/stevexyz/qmk_firmware/blob/master/keyboards/40percentclub/gherkin/keymaps/stevexyz/readme.md for more information
 */


#include QMK_KEYBOARD_H

#include "keymap_canadian_multilingual.h"

enum custom_keycodes {
  CS_FIRST = SAFE_RANGE,
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
  CD_FIRST,
  CD_ECRC,
  CD_ETRM,
  CD_ICRC,
  CD_ITRM,
  CD_OCRC,
  CD_UCRC,
  CD_ACRC,
  CD_LAST,
};

struct custom_shifted_key
{
  uint16_t keycode;
  uint16_t shifted_keycode;
};

// make those look like key_combos
struct custom_shifted_key shifted_values[CS_LAST - CS_FIRST - 1] = {
  { CA_DOT,  CA_EXLM },  // CS_DOT
  { CA_COMM, CA_QUES },  // CS_COMM
  { KC_SPC,  KC_BSPC },  // CS_SPC
  { CA_LCBR, CA_HASH },  // CS_LCBR
  { CA_RCBR, CA_AT   },  // CS_RCBR
  { CA_LPRN, CA_LBRC },  // CS_LPRN
  { CA_RPRN, CA_RBRC },  // CS_RPRN
  { CA_EURO, CA_PND  },  // CS_EURO
  { CA_DLR,  CA_YEN  },  // CS_DLR
  { CA_DQUO, CA_QUOT },  // CS_QUOT
  { CA_SS,   CA_SECT },  // CS_ESZT
  { CA_CIRC, CA_CARN },  // CS_CIRC
  { CA_DIAE, CA_DACU },  // CS_DIAE
  { CA_GRV,  CA_ACUT },  // CS_GRV
  { CA_RNGA, CA_BREV },  // CS_RNGA
  { CA_DTIL, CA_MACR },  // CS_DTIL
  { CA_COPY, CA_REGD },  // CS_COPY
  { CA_LABK, CA_LDAQ },  // CS_LABK
  { CA_RABK, CA_RDAQ },  // CS_RABK
  { CA_AT,   CA_HASH },  // CS_AT
  { CA_AMPR, CA_PIPE },  // CS_AMPR
  { CA_COLN, CA_EQL  },  // CS_COLN
  { CA_NOT,  CA_BRKP },  // CS_NOT
  { CA_TILD, CA_DEG  },  // CS_TILD
  { KC_PAST, CA_PERC },  // CS_PAST
  { KC_PPLS, CA_MUL  },  // CS_PPLS
};

struct revived_key
{
  uint16_t dead_keycode;
  uint16_t keycode;
};

// make those look like key_combos
struct revived_key revived_values[CS_LAST - CS_FIRST - 1] = {
  { CA_CIRC, CA_E },  // CD_ECRC
  { CA_DIAE, CA_E },  // CD_ETRM
  { CA_CIRC, CA_I },  // CD_ICRC
  { CA_DIAE, CA_I },  // CD_ITRM
  { CA_CIRC, CA_O },  // CD_OCRC
  { CA_CIRC, CA_U },  // CD_UCRC
  { CA_CIRC, CA_A },  // CD_ACRC
};

enum combos {
  ESC,
  DEL,
  TAB,
  SCLN,
  OE,
  AE,
  PLMN,
  DIV,
  // NMLK,
};

// look into https://github.com/qmk/qmk_firmware/pull/8591 for actual overlapping and dual function combos
const uint16_t PROGMEM esc_combo[] = {CA_C, CA_P, COMBO_END};
const uint16_t PROGMEM del_combo[] = {CA_M, CA_X, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {CA_W, CA_J, COMBO_END};
const uint16_t PROGMEM scln_combo[] = {CS_COMM, CS_DOT, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {CD_OCRC, CA_EACU, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {CA_AGRV, CA_EACU, COMBO_END};
const uint16_t PROGMEM plmn_combo[] = {CS_PPLS, KC_MINS, COMBO_END};
const uint16_t PROGMEM div_combo[] = {CS_COLN, KC_MINS, COMBO_END};
// const uint16_t PROGMEM nmlk_combo[] = {CA_LDQU, CA_RDQU, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ESC] = COMBO(esc_combo, KC_ESC),
  [DEL] = COMBO(del_combo, KC_DEL),
  [TAB] = COMBO(tab_combo, KC_TAB),
  [SCLN] = COMBO_ACTION(scln_combo),
  [OE] = COMBO_ACTION(oe_combo),
  [AE] = COMBO(ae_combo, CA_AE),
  [PLMN] = COMBO_ACTION(plmn_combo),
  [DIV] = COMBO_ACTION(div_combo),
  // [NMLK] = COMBO(nmlk_combo, KC_NLCK),
};

enum layers {
  BASE, // base layer
  ACC,  // accentued letters
  NUM,  // numbers and other characters
  FUN,  // function keys and navigation
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    CA_C,            CA_P,            CA_O,            CA_V,             CA_W,    CA_J,    CA_D,         CA_U,         CA_X,         CA_M,
    LSFT_T(CA_L),    LT(ACC,CA_I),    LT(NUM,CA_E),    LT(FUN,CA_R),     CS_DOT,  CS_COMM, LT(FUN,CA_T), LT(NUM,CA_S), LT(ACC,CA_A), RSFT_T(CA_N),
    LCTL_T(CA_F),    LALT_T(CA_Y),    ALGR_T(CA_Q),    LWIN_T(CA_H),     KC_ENT,  CS_SPC,  RWIN_T(CA_G), LALT_T(CA_B), ALGR_T(CA_K), LCTL_T(CA_Z)
  ),

  [ACC] = LAYOUT_ortho_3x10(
    CA_CCED,         CD_ITRM,         CD_OCRC,         CA_OSTR,          CD_ETRM, CA_ENOT, CA_UGRV,       CD_UCRC,       CD_ACRC,       KC_NO,
    LSFT_T(KC_CAPS), CD_ICRC,         CA_EACU,         CA_EGRV,          CD_ECRC, CA_CEDL, KC_NO,         CS_ESZT,       CA_AGRV,       RSFT_T(KC_CAPS),
    CA_TM,           CS_COPY,         CS_CIRC,         CS_DIAE,          KC_ENT,  CS_SPC,  CS_GRV,        CS_RNGA,       CS_DTIL,       CA_DOTA
  ),

  [NUM] = LAYOUT_ortho_3x10(
    CA_LDQU,         CA_RDQU,       CS_LCBR,         CS_RCBR,          CS_AMPR,  CS_PPLS,   KC_P7,         KC_P8,         KC_P9,         CA_SLSH,
    LSFT_T(KC_NLCK), CS_QUOT,       CS_LPRN,         CS_RPRN,          CS_DLR,  CA_MINS,   KC_P4,         KC_P5,         KC_P6,         RSFT_T(KC_P0),
    CS_NOT,          CS_TILD,        CS_LABK,        CS_RABK,          CS_EURO,  CS_COLN,   KC_P1,         KC_P2,         KC_P3,         CS_PAST
  ),

  [FUN] = LAYOUT_ortho_3x10(
    KC_VOLU,         KC_PGDN,         KC_INS,          KC_PGUP,          KC_LALT,  KC_ALGR,  KC_F1,         KC_F2,          KC_F3,          KC_F4,
    KC_VOLD,         KC_HOME,         KC_UP,           KC_END,           KC_LSFT,  KC_LCTL,  KC_F5,         KC_F6,          KC_F7,          KC_F8,
    KC_APP,          KC_LEFT,         KC_DOWN,         KC_RIGHT,         KC_ENT,   CS_SPC,   KC_F9,         KC_F10,         KC_F11,         KC_F12
  )
};


// TODO make that repeat on hold
bool custom_shift(uint16_t keycode, keyrecord_t *record){
  const struct custom_shifted_key key = shifted_values[keycode - CS_FIRST - 1];
  if (record->event.pressed) {
    uint8_t temp_mods = get_mods();
    if (temp_mods == MOD_BIT(KC_LSHIFT) || temp_mods == MOD_BIT(KC_RSHIFT)) {
      clear_mods();
      register_code16(key.shifted_keycode);
      set_mods(temp_mods);
    } else
    {
      register_code16(key.keycode);
    }
  } else {
	  // Handling custom shift like that is problematic because of phantom unregistering
    // But needed for combos to work
	  unregister_code16(key.shifted_keycode);
    unregister_code16(key.keycode);
  }
  return true;
}

// TODO make that repeat on hold
bool dead_key_macro(uint16_t keycode, keyrecord_t *record){
  const struct revived_key key = revived_values[keycode - CD_FIRST - 1];
  if (record->event.pressed) {
    uint8_t temp_mods = get_mods();
    clear_mods();
    tap_code16(key.dead_keycode);
    set_mods(temp_mods);
    tap_code16(key.keycode);
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(keycode >= CS_FIRST && keycode < CS_LAST) {
    return custom_shift(keycode, record);
  }
  if(keycode >= CD_FIRST && keycode < CD_LAST) {
    return dead_key_macro(keycode, record);
  }
  return true;
};

// useful for custom shifted keys since its is needed to erase their previous input
// setting the return value in custom_shift to false prevents the combo to be processed
bool process_combo_event(uint8_t combo_index, bool pressed) {
  // I could also put that into a function to ease of development
  switch(combo_index) {
    case SCLN:
      if (pressed) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        register_code16(CA_SCLN);
      } else
      {
        unregister_code16(CA_SCLN);
      }
      break;
    case OE:
      if (pressed) {
        tap_code16(KC_BSPC);
        register_code16(CA_OE);
      } else
      {
        unregister_code16(CA_OE);
      }
      break;
    case PLMN:
      if (pressed) {
        tap_code16(KC_BSPC);
        register_code16(CA_PLMN);
      } else
      {
        unregister_code16(CA_PLMN);
      }
      break;
    case DIV:
      if (pressed) {
        tap_code16(KC_BSPC);
        register_code16(CA_DIV);
      } else
      {
        unregister_code16(CA_DIV);
      }
      break;
  }
  return false;
}