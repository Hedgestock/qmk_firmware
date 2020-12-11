/* Copyright 2020 Arthur "Hedgestock" PAMART pamarthur.aito@gmail.com @hedgestock
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


#include "hedgestock.h"

enum combos {
  CB_SCLN,
  CB_OE,
  CB_AE,
  CB_PLMN,
  CB_DIV,
  CB_NMLK,
  CB_ESC,
  CB_DEL,
  CB_TAB,
  CB_CAPS,
  CB_SAFE_RANGE,
};

//still can't do combo with LT keys...
const uint16_t PROGMEM scln_combo[] = {CS_COMM, CS_DOT, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {CD_OCRC, CA_EACU, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {CA_AGRV, CA_EACU, COMBO_END};
const uint16_t PROGMEM plmn_combo[] = {CS_PPLS, KC_MINS, COMBO_END};
const uint16_t PROGMEM div_combo[] = {CS_COLN, KC_MINS, COMBO_END};
const uint16_t PROGMEM nmlk_combo[] = {CS_AMPR, CS_PPLS, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {CA_C, CA_P, COMBO_END};
const uint16_t PROGMEM del_combo[] = {CA_M, CA_X, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_ENTER, CS_SPC, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {CA_W, CA_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CB_SCLN] = COMBO(scln_combo, CA_SCLN),
  [CB_OE] = COMBO(oe_combo, CA_OE),
  [CB_AE] = COMBO(ae_combo, CA_AE),
  [CB_PLMN] = COMBO(plmn_combo, CA_PLMN),
  [CB_DIV] = COMBO(div_combo, CA_DIV),
  [CB_NMLK] = COMBO(nmlk_combo, KC_NLCK),
  [CB_ESC] = COMBO(esc_combo, KC_ESC),
  [CB_DEL] = COMBO(del_combo, KC_DEL),
  [CB_TAB] = COMBO(tab_combo, KC_TAB),
  [CB_CAPS] = COMBO(caps_combo, KC_CAPS),
};

enum layers {
  BASE, // base layer
  ACC,  // accentued letters
  NUM,  // numbers and other characters
  FUN,  // function keys and navigation
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    CA_C,            CA_P,         CA_O,         CA_V,         CA_W,    CA_J,    CA_D,         CA_U,         CA_X,         CA_M,
    LSFT_T(CA_L),    LT(ACC,CA_I), LT(NUM,CA_E), LT(FUN,CA_R), CS_DOT,  CS_COMM, LT(FUN,CA_T), LT(NUM,CA_S), LT(ACC,CA_A), RSFT_T(CA_N),
    LCTL_T(CA_F),    LALT_T(CA_Y), ALGR_T(CA_Q), LWIN_T(CA_H), KC_ENT,  CS_SPC,  RWIN_T(CA_G), LALT_T(CA_B), ALGR_T(CA_K), LCTL_T(CA_Z)
  ),

  [ACC] = LAYOUT_ortho_3x10(
    CA_CCED,         CD_ITRM,      CD_OCRC,      CA_OSTR,      CD_ETRM, CA_ENOT, CA_UGRV,      CD_UCRC,      CD_ACRC,      CA_MICR,
    LSFT_T(KC_CAPS), CD_ICRC,      CA_EACU,      CA_EGRV,      CD_ECRC, CA_CEDL, KC_NO,        CS_ESZT,      CA_AGRV,      RSFT_T(KC_CAPS),
    CA_TM,           CS_COPY,      CS_CIRC,      CS_DIAE,      KC_ENT,  CS_SPC,  CS_GRV,       CS_RNGA,      CS_DTIL,      CA_DOTA
  ),

  [NUM] = LAYOUT_ortho_3x10(
    CA_LDQU,         CA_RDQU,      CS_LCBR,      CS_RCBR,      CS_AMPR, CS_PPLS, KC_P7,        KC_P8,        KC_P9,        CA_SLSH,
    LSFT_T(KC_NLCK), CS_QUOT,      CS_LPRN,      CS_RPRN,      CS_DLR,  CA_MINS, KC_P4,        KC_P5,        KC_P6,        RSFT_T(KC_P0),
    CS_CENT,         CS_TILD,      CS_LABK,      CS_RABK,      CS_EURO, CS_COLN, KC_P1,        KC_P2,        KC_P3,        CS_PAST
  ),

  [FUN] = LAYOUT_ortho_3x10(
    KC_VOLU,         KC_PGDN,      KC_INS,       KC_PGUP,      KC_LALT, KC_ALGR, KC_F1,        KC_F2,        KC_F3,        KC_F4,
    KC_VOLD,         KC_HOME,      KC_UP,        KC_END,       KC_LSFT, KC_LCTL, KC_F5,        KC_F6,        KC_F7,        KC_F8,
    KC_APP,          KC_LEFT,      KC_DOWN,      KC_RIGHT,     KC_ENT,  CS_SPC,  KC_F9,        KC_F10,       KC_F11,       KC_F12
  )
};