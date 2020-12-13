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

enum layers {
  BASE, // base layer
  ACC,  // accentued letters
  NUM,  // numbers and other characters
  FUN,  // function keys and navigation
};

enum combos_extension {
  C_P_ESC = COMBO_SAFE_RANGE,
  X_M_DEL,
  ENT_SPC_TAB,
  CE_NMLK,
  L_I_LSFT,
  I_E_ACC,
  L_I_E_NUM,
  S_A_N_NUM,
  S_A_ACC,
  A_N_RSFT,
  F_Y_LCTL,
  Y_Q_LALT,
  F_Y_Q_LWIN,
  B_K_Z_RWIN,
  K_Z_RALT,
  B_K_LCTL,
  // function keys
  C_M_F1,
  P_M_F2,
  O_M_F3,
  V_M_F4,
  W_M_F5,
  J_M_F6,
  C_X_F7,
  P_X_F8,
  O_X_F9,
  V_X_F10,
  W_X_F11,
  J_X_F12,
};

const uint16_t PROGMEM scln_combo[] = {CS_COMM, CS_DOT, COMBO_END};
const uint16_t PROGMEM plmn_combo[] = {CS_PPLS, KC_MINS, COMBO_END};
const uint16_t PROGMEM div_combo[] = {CS_COLN, KC_MINS, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {CA_O, CA_E, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {CA_A, CA_E, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {CA_C, CA_P, COMBO_END};
const uint16_t PROGMEM del_combo[] = {CA_M, CA_X, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_ENTER, CS_SPC, COMBO_END};
const uint16_t PROGMEM nmlk_combo[] = {CS_CENT, CS_PPLS, COMBO_END};
const uint16_t PROGMEM lsft_combo[] = {CA_L, CA_I, COMBO_END};
const uint16_t PROGMEM lacc_combo[] = {CA_I, CA_E, COMBO_END};
const uint16_t PROGMEM lnum_combo[] = {CA_L, CA_I, CA_E, COMBO_END};
const uint16_t PROGMEM rnum_combo[] = {CA_S, CA_A, CA_N, COMBO_END};
const uint16_t PROGMEM racc_combo[] = {CA_S, CA_A, COMBO_END};
const uint16_t PROGMEM rsft_combo[] = {CA_A, CA_N, COMBO_END};
const uint16_t PROGMEM lctl_combo[] = {CA_F, CA_Y, COMBO_END};
const uint16_t PROGMEM lalt_combo[] = {CA_Y, CA_Q, COMBO_END};
const uint16_t PROGMEM lwin_combo[] = {CA_F, CA_Y, CA_Q, COMBO_END};
const uint16_t PROGMEM rwin_combo[] = {CA_B, CA_K, CA_Z, COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {CA_K, CA_Z, COMBO_END};
const uint16_t PROGMEM rctl_combo[] = {CA_B, CA_K, COMBO_END};
const uint16_t PROGMEM f1_combo[] = {CA_C, CA_M, COMBO_END};
const uint16_t PROGMEM f2_combo[] = {CA_P, CA_M, COMBO_END};
const uint16_t PROGMEM f3_combo[] = {CA_O, CA_M, COMBO_END};
const uint16_t PROGMEM f4_combo[] = {CA_V, CA_M, COMBO_END};
const uint16_t PROGMEM f5_combo[] = {CA_W, CA_M, COMBO_END};
const uint16_t PROGMEM f6_combo[] = {CA_J, CA_M, COMBO_END};
const uint16_t PROGMEM f7_combo[] = {CA_C, CA_X, COMBO_END};
const uint16_t PROGMEM f8_combo[] = {CA_P, CA_X, COMBO_END};
const uint16_t PROGMEM f9_combo[] = {CA_O, CA_X, COMBO_END};
const uint16_t PROGMEM f10_combo[] = {CA_V, CA_X, COMBO_END};
const uint16_t PROGMEM f11_combo[] = {CA_W, CA_X, COMBO_END};
const uint16_t PROGMEM f12_combo[] = {CA_J, CA_X, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [COMM_DOT_SCLN] = COMBO(scln_combo, CA_SCLN),
  [PPLS_MINS_PLMN] = COMBO(plmn_combo, CA_PLMN),
  [COLN_MINS_DIV] = COMBO(div_combo, CA_DIV),
  [O_E_OE] = COMBO(oe_combo, CA_OE),
  [A_E_AE] = COMBO(ae_combo, CA_AE),
  [C_P_ESC] = COMBO(esc_combo, KC_ESC),
  [X_M_DEL] = COMBO(del_combo, KC_DEL),
  [ENT_SPC_TAB] = COMBO(tab_combo, KC_TAB),
  [CE_NMLK] = COMBO(nmlk_combo, KC_NLCK),
  [L_I_LSFT] = COMBO(lsft_combo, LSFT_T(KC_CAPS)),
  [I_E_ACC] = COMBO(lacc_combo, MO(ACC)),
  [L_I_E_NUM] = COMBO(lnum_combo, MO(NUM)),
  [S_A_N_NUM] = COMBO(rnum_combo, MO(NUM)),
  [S_A_ACC] = COMBO(racc_combo, MO(ACC)),
  [A_N_RSFT] = COMBO(rsft_combo, RSFT_T(KC_CAPS)),
  [F_Y_LCTL] = COMBO(lctl_combo, KC_LCTL),
  [Y_Q_LALT] = COMBO(lalt_combo, KC_LALT),
  [F_Y_Q_LWIN] = COMBO(lwin_combo, KC_LWIN),
  [B_K_Z_RWIN] = COMBO(rwin_combo, KC_RWIN),
  [K_Z_RALT] = COMBO(ralt_combo, KC_RALT),
  [B_K_LCTL] = COMBO(rctl_combo, KC_LCTL),
  [C_M_F1] = COMBO(f1_combo, KC_F1),
  [P_M_F2] = COMBO(f2_combo, KC_F2),
  [O_M_F3] = COMBO(f3_combo, KC_F3),
  [V_M_F4] = COMBO(f4_combo, KC_F4),
  [W_M_F5] = COMBO(f5_combo, KC_F5),
  [J_M_F6] = COMBO(f6_combo, KC_F6),
  [C_X_F7] = COMBO(f7_combo, KC_F7),
  [P_X_F8] = COMBO(f8_combo, KC_F8),
  [O_X_F9] = COMBO(f9_combo, KC_F9),
  [V_X_F10] = COMBO(f10_combo, KC_F10),
  [W_X_F11] = COMBO(f11_combo, KC_F11),
  [J_X_F12] = COMBO(f12_combo, KC_F12),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    CA_C,            CA_P,         CA_O,         CA_V,         CA_W,    CA_J,    CA_D,         CA_U,         CA_X,         CA_M,
    CA_L,            CA_I,         CA_E,         CA_R,         CS_DOT,  CS_COMM, CA_T,         CA_S,         CA_A,         CA_N,
    CA_F,            CA_Y,         CA_Q,         CA_H,         KC_ENT,  CS_SPC,  CA_G,         CA_B,         CA_K,         CA_Z
  ),

  [ACC] = LAYOUT_ortho_3x10(
    CA_CCED,         CD_ITRM,      CD_OCRC,      CA_OSTR,      CD_ETRM, CA_ENOT, CA_UGRV,      CD_UCRC,      CD_ACRC,      CA_MICR,
    KC_NO,           CD_ICRC,      CA_EACU,      CA_EGRV,      CD_ECRC, CA_CEDL, KC_NO,        CS_ESZT,      CA_AGRV,      KC_NO,
    KC_NO,           KC_NO,        CS_CIRC,      CS_DIAE,      KC_TRNS, KC_TRNS, CS_GRV,       CS_RNGA,      CS_DTIL,      CA_DOTA
  ),

  [NUM] = LAYOUT_ortho_3x10(
    CS_PIPE,         CS_AMPR,      CS_LCBR,      CS_RCBR,      CS_CENT, CS_PPLS, CS_P7,        CS_P8,        CS_P9,        CS_PSLS,
    CS_DQUO,         CS_APOS,      CS_LPRN,      CS_RPRN,      CS_DLR,  CA_MINS, CS_P4,        CS_P5,        CS_P6,        CS_P0,
    CS_LABK,         CS_RABK,      CS_LBRC,      CS_RBRC,      CS_EURO, CS_COLN, CS_P1,        CS_P2,        CS_P3,        CS_PAST
  ),

  [FUN] = LAYOUT_ortho_3x10(
    KC_VOLU,         KC_PGDN,      KC_INS,       KC_PGUP,      KC_LALT, KC_ALGR, KC_F1,        KC_F2,        KC_F3,        KC_F4,
    KC_VOLD,         KC_HOME,      KC_UP,        KC_END,       KC_LSFT, KC_LCTL, KC_F5,        KC_F6,        KC_F7,        KC_F8,
    KC_APP,          KC_LEFT,      KC_DOWN,      KC_RIGHT,     KC_TRNS, KC_TRNS, KC_F9,        KC_F10,       KC_F11,       KC_F12
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_hedgestock(keycode, record);
};