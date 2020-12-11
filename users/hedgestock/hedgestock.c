#include "hedgestock.h"

struct custom_shifted_key
{
  uint16_t keycode;
  uint16_t shifted_keycode;
};

struct revived_key
{
  uint16_t dead_keycode;
  uint16_t keycode;
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
  { CA_CENT, CA_CURR },  // CS_CENT
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
  { CA_TILD, CA_DEG  },  // CS_TILD
  { KC_PAST, CA_PERC },  // CS_PAST
  { KC_PPLS, CA_MUL  },  // CS_PPLS
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