#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "debug.h"
#include "action_layer.h"

enum layers {
  _NEO_1,
  _NEO_3,
  _NEO_4,
  _QWERT,
  _FKEYS,
  _NAV
};

// bitmasks for modifier keys
#define MODS_SHIFT  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))

// Used to trigger macros / sequences of keypresses
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,     // can always be here
  N2_1,
  N2_2,
  N2_3,
  N2_4,
  N2_5,
  N2_6,
  N2_7,
  N2_8,
  N2_9,
  N2_0,
  N2_MINS,
  N2_COMM,
  N2_DOT,
  N2_SS
};

// layer mods
#define N2_NEO3     MO(_NEO_3)
#define N2_NEO4     MO(_NEO_4)
#define YL_QWER     TO(_QWERT)
#define YL_NEO1     TO(_NEO_1)
#define YL_FKEY     MO(_FKEYS)
#define YL_NAV      MO(_NAV)

// NEO_3 special characters
#define N2_ELL      RALT(DE_DOT)                // …

// NEO_4 special characters
#define N2_IEXC     RSA(DE_1)                   // ¡
#define N2_IQUE     RSA(DE_SS)                  // ¿

// My own special things
#define YL_TABL     LSFT(LCTL(KC_TAB))
#define YL_TABR     LCTL(KC_TAB)
#define YL_MTBL     LCTL(LSFT(KC_PGUP))
#define YL_MTBR     LCTL(LSFT(KC_PGDN))
#define YL_SAVE     LCTL(DE_S)
#define YL_AC       LCTL(KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NEO_1] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
      KC_NO,    N2_1,    N2_2,    N2_3,    N2_4,    N2_5,   KC_NO,       YL_QWER,    N2_6,    N2_7,    N2_8,    N2_9,    N2_0, N2_MINS,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
     KC_TAB,    DE_X,    DE_V,    DE_L,    DE_C,    DE_W, YL_TABL,       YL_TABR,    DE_K,    DE_H,    DE_G,    DE_F,    DE_Q,   N2_SS,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    N2_NEO3,    DE_U,    DE_I,    DE_A,    DE_E,    DE_O,                            DE_S,    DE_N,    DE_R,    DE_T,    DE_D,    DE_Y,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, DE_UDIA, DE_ODIA, DE_ADIA,    DE_P,    DE_Z, MS_BTN1,       MS_BTN2,    DE_B,    DE_M, N2_COMM,  N2_DOT,    DE_J, KC_RSFT,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO, N2_NEO4,                                           N2_NEO4,  YL_NAV,   KC_NO,   KC_NO,   KC_NO,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                  KC_APP, YL_SAVE,         KC_NO, YL_FKEY,
                                             //+--------+--------|      |       +--------+
                                                            YL_AC,         YL_AC,
                                     //,       |        |--------|      |-------|        |        |
                                        KC_LGUI, KC_LALT, KC_LCTL,       KC_RCTL, KC_RALT,  KC_SPC
                                     //`-------------------------'      `-------------------------'
  ),

  [_NEO_3] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,  N2_ELL, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, YL_MTBL,       YL_MTBR, DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, DE_EURO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                         DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,   DE_AT,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    _______, DE_HASH,  DE_DLR, DE_PIPE, DE_TILD,  DE_GRV,   KC_NO,         KC_NO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,                                           _______, _______,   KC_NO,   KC_NO,   KC_NO,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                   KC_NO,   KC_NO,         KC_NO,   KC_NO,
                                             //+--------+--------|      |       +--------+
                                                          _______,       _______, 
                                     //,       |        |--------|      |-------|        |        |
                                        _______, _______, _______,       _______, _______, _______
                                     //`-------------------------'      `-------------------------'
  ),

  [_NEO_4] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,  KC_TAB, DE_SLSH, DE_ASTR, DE_MINS,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,   KC_NO,         KC_NO, N2_IEXC,    KC_7,    KC_8,    KC_9, DE_PLUS,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,                         N2_IQUE,    KC_4,    KC_5,    KC_6, DE_COMM,  DE_DOT,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    _______,  KC_ESC,  KC_TAB,  KC_INS,  KC_ENT, KC_UNDO,   KC_NO,         KC_NO, DE_COLN,    KC_1,    KC_2,    KC_3, DE_SCLN,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,                                           _______,    KC_0,   KC_NO,   KC_NO,   KC_NO,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                   KC_NO,   KC_NO,         KC_NO,   KC_NO,
                                             //+--------+--------|      |       +--------+
                                                          _______,       _______, 
                                     //,       |        |--------|      |-------|        |        |
                                        _______, _______, _______,       _______, _______, _______
                                     //`-------------------------'      `-------------------------'
  ),

  [_QWERT] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
     KC_ESC,    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,   KC_NO,       YL_NEO1,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,   DE_SS,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
     KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,   KC_NO,         KC_NO,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, DE_UDIA,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                            DE_H,    DE_J,    DE_K,    DE_L, DE_ODIA, DE_ADIA,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_LSFT,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,   KC_NO,         KC_NO,    DE_N,    DE_M, DE_COMM,  DE_DOT, DE_MINS, KC_RSFT,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LGUI, KC_LALT,   KC_NO, YL_FKEY,                                            KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_RGUI,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                   KC_NO,   KC_NO,       KC_RALT, KC_RCTL,
                                             //+--------+--------|      |       +--------+
                                                            KC_NO,         KC_NO,
                                     //,       |        |--------|      |-------|        |        |
                                         KC_SPC, KC_LALT, KC_LCTL,       KC_BSPC,  KC_ENT,  KC_SPC
                                     //`-------------------------'      `-------------------------'
  ),

  [_FKEYS] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
    KC_MPRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,        KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_VOLU,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_MPLY,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_VOLD,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
    KC_MNXT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_MUTE,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                            KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                   KC_NO,   KC_NO,         KC_NO, _______,
                                             //+--------+--------|      |       +--------+
                                                            KC_NO,         KC_NO,
                                     //,       |        |--------|      |-------|        |        |
                                          KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO
                                     //`-------------------------'      `-------------------------'
  ),

  [_NAV] = LAYOUT_ergodox_pretty(
 //,-------------------------------------------------------------.      ,-------------------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   MS_UP,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO, MS_BTN1, MS_WHLU, MS_BTN2,   KC_NO,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO, MS_LEFT, MS_DOWN, MS_RGHT,   KC_NO,                           KC_NO, MS_WHLL, MS_WHLD, MS_WHLR,   KC_NO,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //|-------+--------+--------+--------+--------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                            KC_NO,   YL_NAV,   KC_NO,   KC_NO,   KC_NO,
 //`-------------------------------------------+--------+--------|      |-------+--------+--------+--------+--------+--------+--------'
                                                   KC_NO,   KC_NO,         KC_NO,   KC_NO,
                                             //+--------+--------|      |       +--------+
                                                            KC_NO,         KC_NO,
                                     //,       |        |--------|      |-------|        |        |
                                        KC_LGUI, KC_LALT, KC_LCTL,       KC_RCTL, KC_RALT,   KC_NO
                                     //`-------------------------'      `-------------------------'
  )
};

// Special remapping for keys with different keycodes/macros when used with shift modifiers.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t active_modifiers = get_mods();
  uint8_t shifted = active_modifiers & MODS_SHIFT;

  // Early return on key release
  if(!record->event.pressed) {
    return true;
  }

  if(shifted) {
    clear_mods();

    switch(keycode) {
      case N2_1:
        // degree symbol
        SEND_STRING(SS_LSFT("`"));
        break;
      case N2_2:
        // section symbol
        SEND_STRING(SS_LSFT("3"));
        break;
      case N2_3:
        SEND_STRING(SS_RALT("1"));
        break;
      case N2_4:
        // right angled quote
        SEND_STRING(SS_RALT("z"));
        break;
      case N2_5:
        // left angled quote
        SEND_STRING(SS_RALT("x"));
        break;
      case N2_6:
        // dollar sign
        SEND_STRING(SS_LSFT("4"));
        break;
      case N2_7:
        // euro sign
        SEND_STRING(SS_RALT("e"));
        break;
      case N2_8:
        // low9 double quote
        SEND_STRING(SS_RALT("v"));
        break;
      case N2_9:
        // left double quote
        SEND_STRING(SS_RALT("b"));
        break;
      case N2_0:
        // right double quote
        SEND_STRING(SS_RALT("n"));
        break;
      case N2_MINS:
        // em dash
        SEND_STRING(SS_LSFT(SS_RALT("/")));
        break;
      case N2_COMM:
        // en dash
        SEND_STRING(SS_RALT("/"));
        break;
      case N2_DOT:
        // bullet
        SEND_STRING(SS_RALT(","));
        break;
      case N2_SS:
        // ẞ
        SEND_STRING(SS_LSFT(SS_RALT("s")));
        break;
      default:
        set_mods(active_modifiers);
        return true;
    }

    set_mods(active_modifiers);
    return false;
  } else {
    switch(keycode) {
      case N2_1:
        SEND_STRING(SS_TAP(X_1));
        break;
      case N2_2:
        SEND_STRING(SS_TAP(X_2));
        break;
      case N2_3:
        SEND_STRING(SS_TAP(X_3));
        break;
      case N2_4:
        SEND_STRING(SS_TAP(X_4));
        break;
      case N2_5:
        SEND_STRING(SS_TAP(X_5));
        break;
      case N2_6:
        SEND_STRING(SS_TAP(X_6));
        break;
      case N2_7:
        SEND_STRING(SS_TAP(X_7));
        break;
      case N2_8:
        SEND_STRING(SS_TAP(X_8));
        break;
      case N2_9:
        SEND_STRING(SS_TAP(X_9));
        break;
      case N2_0:
        SEND_STRING(SS_TAP(X_0));
        break;
      case N2_MINS:
        SEND_STRING(SS_TAP(X_SLASH));
        break;
      case N2_COMM:
        SEND_STRING(SS_TAP(X_COMMA));
        break;
      case N2_DOT:
        SEND_STRING(SS_TAP(X_DOT));
        break;
      case N2_SS:
        // ß
        SEND_STRING(SS_TAP(X_MINS));
        break;
      case DE_CIRC:
        SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_SPACE));
        break;
      case DE_GRV:
        SEND_STRING(SS_LSFT("=") SS_TAP(X_SPACE));
        break;
      default:
        return true;
    }

    return false;
  }
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case _NEO_3:
            ergodox_right_led_1_on();
            break;
        case _NEO_4:
            ergodox_right_led_2_on();
            break;
        case _QWERT:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }
};
