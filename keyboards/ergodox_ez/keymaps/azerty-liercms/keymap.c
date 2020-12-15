#include "hedgestock.h"
#include "action_layer.h"
#include "keymap_french.h"
#include "keymap_steno.h"

enum layers {
  AZER = 0,
  AZERSYM,
  AZERFUN,

  LIERCMS,
  LIERACC,
  LIERSYM,

  TXBOLT,

  MHBASE,
  MHFUN,
};

enum my_keycodes {
  XMAS = EZ_SAFE_RANGE,
};

enum combos_extension {
  ENTER_SPACE_TAB,
};

const uint16_t PROGMEM scln_combo[] = {CS_COMM, CS_DOT, COMBO_END};
const uint16_t PROGMEM plmn_combo[] = {CS_PPLS, KC_MINS, COMBO_END};
const uint16_t PROGMEM div_combo[] = {CS_COLN, KC_MINS, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {CA_O, CA_E, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {CA_A, CA_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_ENTER, KC_SPACE, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [COMM_DOT_SCLN] = COMBO(scln_combo, CA_SCLN),
  [PPLS_MINS_PLMN] = COMBO(plmn_combo, CA_PLMN),
  [COLN_MINS_DIV] = COMBO(div_combo, CA_DIV),
  [O_E_OE] = COMBO(oe_combo, CA_OE),
  [A_E_AE] = COMBO(ae_combo, CA_AE),
  [ENTER_SPACE_TAB] = COMBO(tab_combo, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// azerty layout because I'm french
  [AZER] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      FR_AMP,         FR_EACU,        FR_DQUO,        FR_APOS,        FR_LPRN,        TT(AZERFUN),                                    TT(AZERFUN),    FR_MINS,        FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,        KC_INSERT,
    KC_TAB,         FR_A,           FR_Z,           FR_E,           FR_R,           FR_T,           FR_DLR,                                         FR_ASTR,        FR_Y,           FR_U,           FR_I,           FR_O,           FR_P,           FR_CIRC,
    LSFT_T(KC_CAPSLOCK),FR_Q,       FR_S,           FR_D,           FR_F,           FR_G,                                                                           FR_H,           FR_J,           FR_K,           FR_L,           FR_M,           RSFT_T(KC_CAPSLOCK),
    KC_LCTRL,       FR_W,           FR_X,           FR_C,           FR_V,           FR_B,           TT(AZERSYM),                                    TT(AZERSYM),    FR_N,           FR_COMM,        FR_SCLN,        FR_COLN,        FR_EXLM,        KC_RCTRL,
    TO(LIERCMS),    KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          KC_RGUI,        KC_RALT,        FR_UGRV,
                                                                                                    KC_HOME,        TO(MHBASE),     TO(TXBOLT),     KC_END,
                                                                                                                    KC_SPACE,       KC_PGUP,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_ENTER,       KC_PGDOWN,      KC_ENTER,       KC_SPACE
  ),
  [AZERSYM] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, FR_GRV,         FR_HASH,        FR_LCBR,        FR_RCBR,        FR_PIPE,        FR_EURO,                                        FR_COLN,        KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, FR_PERC,
    KC_NUMLOCK,     FR_LESS,        FR_GRTR,        FR_LPRN,        FR_RPRN,        FR_EQL,                                                                         KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_NUMLOCK,
    KC_TRANSPARENT, FR_BSLS,        FR_SLSH,        FR_LBRC,        FR_RBRC,        FR_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_0,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_SUP2,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // rework this layer
  [AZERFUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT,                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         LCTL(LSFT(KC_ESCAPE)),LED_LEVEL,                                KC_MY_COMPUTER, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(LSFT(KC_S)),                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(FR_Z),     LCTL(KC_Y),                                     KC_CALCULATOR,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, XMAS,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// lier layout based on canadian multinligual keyboard
  [LIERCMS] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_INSERT,
    TT(LIERACC),    CA_C,           CA_P,           CA_O,           CA_V,           CA_W,           KC_NO,                                          KC_NO,          CA_J,           CA_D,           CA_U,           CA_X,           CA_M,           TT(LIERACC),
    LSFT_T(KC_CAPSLOCK),CA_L,       CA_I,           CA_E,           CA_R,           CS_DOT,                                                                         CS_COMM,        CA_T,           CA_S,           CA_A,           CA_N,           LSFT_T(KC_CAPSLOCK),
    KC_LCTRL,       CA_F,           CA_Y,           CA_Q,           CA_H,           CS_QUOT,        TT(LIERSYM),                                    TT(LIERSYM),    CS_MINS,        CA_G,           CA_B,           CA_K,           CA_Z,           KC_LCTRL,
    TG(LIERCMS),    KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          KC_RGUI,        KC_RALT,        KC_NO,
                                                                                                    KC_NO,          TO(MHBASE),     TO(TXBOLT),     KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_NO,          KC_NO,          KC_ENTER,       KC_SPACE
  ),
  [LIERACC] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CA_CCED,        CD_ITRM,        CD_OCRC,        CA_OSTR,        CD_ETRM,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CA_ENOT,        CA_UGRV,        CD_UCRC,        CD_ACRC,        CA_MICR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          CD_ICRC,        CA_EACU,        CA_EGRV,        CD_ECRC,                                                                        CA_CEDL,        KC_NO,          CS_ESZT,        CA_AGRV,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          CS_CIRC,        CS_DIAE,        KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          CS_GRV,         CS_RNGA,        CS_DTIL,        CA_DOTA,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LIERSYM] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CS_PIPE,        CS_AMPR,        CS_LCBR,        CS_RCBR,        CS_CENT,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CS_PPLS,        CS_P7,          CS_P8,          CS_P9,          CS_PSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, CS_DQUO,        CS_APOS,        CS_LPRN,        CS_RPRN,        CS_DLR,                                                                         CA_MINS,        CS_P4,          CS_P5,          CS_P6,          CS_PAST,        KC_TRANSPARENT,
    KC_TRANSPARENT, CS_LABK,        CS_RABK,        CS_LBRC,        CS_RBRC,        CS_EURO,        KC_TRANSPARENT,                                 KC_TRANSPARENT, CS_COLN,        CS_P1,          CS_P2,          CS_P3,          CS_P0,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
/* Keymap 6: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   #  |   #  |   #  |   #  |   #  |           |   #  |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |   H  |   *  |           |   *  |   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  |------|           |------|   R  |   B  |   G  |   S  |   Z  |        |
 * |--------+------+------+------+------+------|      |           |BAKSPC|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |LYRSWT|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
  [TXBOLT] = LAYOUT_ergodox_pretty(
       KC_NO,   KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,      STN_N6,   STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  KC_NO,
       KC_NO,   KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,     STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  KC_NO,
       KC_NO,   KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,                         STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_BSPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   TO(AZER),                       TG(TXBOLT), KC_NO,
                                                    KC_NO,                          KC_NO,
                                  STN_A,   STN_O,   KC_NO,                          KC_NO,    STN_E,   STN_U
  ),
//Monster Hunter
  [MHBASE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_6,           KC_M,/*Opens map in monster hunter world*/      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_7,                                                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LCTRL,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_8,           KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TO(LIERCMS),    KC_NO,          KC_NO,          KC_N,           MO(MHFUN),                                                                                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                        /*          ^^^^           */                               KC_NO,          TG(MHBASE),     TO(TXBOLT),     KC_NO,
                                        /* Used in menu navigation */                                               KC_NO,          KC_NO,
                                                                                    KC_SPACE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
  [MHFUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

// Set the steno mode to TXBolt
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT);
};

// struct blink {
//   uint16_t delay;
//   void (*led)(void);
//   struct blink* next;
// };

// static struct blink *current_pattern = NULL;

// static uint16_t timer;

// struct blink p1b2;

// struct blink p1b1 = {
//   100,
//   &ergodox_right_led_1_on,
//   &p1b2,
// };

// struct blink p1b2 = {
//   500,
//   &ergodox_right_led_2_on,
//   &p1b1,
// };

// void matrix_scan_user(void) {
//   if (current_pattern == NULL){
//     current_pattern = &p1b1;
//     timer = timer_read();
//   } else
//   {
//     if (timer_elapsed(timer) > current_pattern->delay) {
//       ergodox_led_all_off();
//       current_pattern = current_pattern->next;
//       current_pattern->led();
//       timer = timer_read();
//     }
//   }
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_hedgestock(keycode, record)) return false;
  return true;
};

bool led_update_user(led_t led_state) {
  if (led_state.caps_lock) {
      ergodox_right_led_3_on();
  } else {
      ergodox_right_led_3_off();
  }
  return true;
}

int is_layer_on(uint32_t state, enum layers layer)
{
  return (1 << layer) & state;
}

// uint8_t is O to 255
// I'd greatly benefit from some self reflection here for calling ergodox_right_led_X_on()
uint32_t layer_state_set_user(uint32_t state)
{
  // uint8_t layer = biton32(state);
  uint8_t dim = 5;
  uint8_t medium = 50;
  uint8_t bright = 255;

  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  combo_disable();
  if (is_layer_on(state, AZERSYM))
  {
    ergodox_right_led_1_set(medium);
    ergodox_right_led_1_on();
  }
  if (is_layer_on(state, AZERFUN))
  {
    ergodox_right_led_2_set(medium);
    ergodox_right_led_2_on();
  }

  if (is_layer_on(state, LIERCMS))
  { 
    combo_enable();
    ergodox_right_led_1_set(dim);
    ergodox_right_led_1_on();
    ergodox_right_led_2_set(dim);
    ergodox_right_led_2_on();
  }
  if (is_layer_on(state, LIERSYM))
  {
    ergodox_right_led_1_set(bright);
    ergodox_right_led_1_on();
  }
  if (is_layer_on(state, LIERACC))
  {
    ergodox_right_led_2_set(bright);
    ergodox_right_led_2_on();
  }

  if (is_layer_on(state, TXBOLT))
  {
    ergodox_right_led_1_set(bright);
    ergodox_right_led_1_on();
    ergodox_right_led_2_set(bright);
    ergodox_right_led_2_on();
  }

  if (is_layer_on(state, MHBASE))
  {
    ergodox_right_led_1_set(dim);
    ergodox_right_led_1_on();
  }
  if (is_layer_on(state, MHFUN))
  {
    ergodox_right_led_2_set(dim);
    ergodox_right_led_2_on();
  }
  return state;
};
