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

struct revived_key revived_values[CD_LAST - CD_FIRST - 1] = {
  [CD_ECRC - CD_FIRST - 1] = { CA_CIRC, CA_E },
  [CD_ETRM - CD_FIRST - 1] = { CA_DIAE, CA_E },
  [CD_ICRC - CD_FIRST - 1] = { CA_CIRC, CA_I },
  [CD_ITRM - CD_FIRST - 1] = { CA_DIAE, CA_I },
  [CD_OCRC - CD_FIRST - 1] = { CA_CIRC, CA_O },
  [CD_UCRC - CD_FIRST - 1] = { CA_CIRC, CA_U },
  [CD_ACRC - CD_FIRST - 1] = { CA_CIRC, CA_A },
};

struct custom_shifted_key shifted_values[CS_LAST - CS_FIRST - 1] = {
  [CS_DOT  - CS_FIRST - 1] = { CA_DOT,  CA_EXLM },
  [CS_COMM - CS_FIRST - 1] = { CA_COMM, CA_QUES },
  [CS_LCBR - CS_FIRST - 1] = { CA_LCBR, CA_COPY },
  [CS_RCBR - CS_FIRST - 1] = { CA_RCBR, CA_REGD },
  [CS_LPRN - CS_FIRST - 1] = { CA_LPRN, CA_LSQU },
  [CS_RPRN - CS_FIRST - 1] = { CA_RPRN, CA_RSQU },
  [CS_LBRC - CS_FIRST - 1] = { CA_RBRC, CA_HASH },
  [CS_RBRC - CS_FIRST - 1] = { CA_RBRC, CA_AT   },
  [CS_EURO - CS_FIRST - 1] = { CA_EURO, CA_PND  },
  [CS_DLR  - CS_FIRST - 1] = { CA_DLR,  CA_YEN  },
  [CS_CENT - CS_FIRST - 1] = { CA_CENT, CA_CURR },
  [CS_DQUO - CS_FIRST - 1] = { CA_DQUO, CA_LDQU },
  [CS_QUOT - CS_FIRST - 1] = { CA_QUOT, CA_DQUO },
  [CS_APOS - CS_FIRST - 1] = { CA_QUOT, CA_RDQU },
  [CS_ESZT - CS_FIRST - 1] = { CA_SS,   CA_SECT },
  [CS_CIRC - CS_FIRST - 1] = { CA_CIRC, CA_CARN },
  [CS_DIAE - CS_FIRST - 1] = { CA_DIAE, CA_DACU },
  [CS_GRV  - CS_FIRST - 1] = { CA_GRV,  CA_ACUT },
  [CS_RNGA - CS_FIRST - 1] = { CA_RNGA, CA_BREV },
  [CS_DTIL - CS_FIRST - 1] = { CA_DTIL, CA_MACR },
  [CS_COPY - CS_FIRST - 1] = { CA_COPY, CA_REGD },
  [CS_LABK - CS_FIRST - 1] = { CA_LABK, CA_LDAQ },
  [CS_RABK - CS_FIRST - 1] = { CA_RABK, CA_RDAQ },
  [CS_AT   - CS_FIRST - 1] = { CA_AT,   CA_HASH },
  [CS_AMPR - CS_FIRST - 1] = { CA_AMPR, CA_TM   },
  [CS_PIPE - CS_FIRST - 1] = { CA_PIPE, CA_BRKP },
  [CS_COLN - CS_FIRST - 1] = { CA_COLN, CA_EQL  },
  [CS_MINS - CS_FIRST - 1] = { CA_MINS, CA_COLN },
  [CS_TILD - CS_FIRST - 1] = { CA_TILD, CA_DEG  },
  // Numpad
  [CS_P0   - CS_FIRST - 1] = { KC_P0,   CA_DEG  },
  [CS_P1   - CS_FIRST - 1] = { KC_P1,   CA_SUP1 },
  [CS_P2   - CS_FIRST - 1] = { KC_P2,   CA_SUP2 },
  [CS_P3   - CS_FIRST - 1] = { KC_P3,   CA_SUP3 },
  [CS_P4   - CS_FIRST - 1] = { KC_P4,   CA_QRTR },
  [CS_P5   - CS_FIRST - 1] = { KC_P5,   CA_HALF },
  [CS_P6   - CS_FIRST - 1] = { KC_P6,   CA_TQTR },
  [CS_P7   - CS_FIRST - 1] = { KC_P7,   CA_TEIG },
  [CS_P8   - CS_FIRST - 1] = { KC_P8,   CA_FEIG },
  [CS_P9   - CS_FIRST - 1] = { KC_P9,   CA_SEIG },
  [CS_PAST - CS_FIRST - 1] = { KC_PAST, CA_PERC },
  [CS_PPLS - CS_FIRST - 1] = { KC_PPLS, CA_MUL  },
  [CS_PSLS - CS_FIRST - 1] = { CA_SLSH, CA_BSLS },
  // Small boards
  [CS_SPC  - CS_FIRST - 1] = { KC_SPC,  KC_BSPC },
};

// TODO make that repeat on hold
bool custom_shift(uint16_t keycode, keyrecord_t *record){
  const struct custom_shifted_key key = shifted_values[keycode - CS_FIRST - 1];
  if (record->event.pressed) {
    uint8_t temp_mods = get_mods();
    if (temp_mods == MOD_BIT(KC_LSHIFT) || temp_mods == MOD_BIT(KC_RSHIFT) || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
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
    // --- not sure anymore...
	  unregister_code16(key.shifted_keycode);
    unregister_code16(key.keycode);
  }
  return false;
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
  return false;
}

bool process_record_hedgestock(uint16_t keycode, keyrecord_t *record) {
  if(keycode >= CS_FIRST && keycode < CS_LAST) {
    return custom_shift(keycode, record);
  }
  if(keycode >= CD_FIRST && keycode < CD_LAST) {
    return dead_key_macro(keycode, record);
  }
  return true;
};