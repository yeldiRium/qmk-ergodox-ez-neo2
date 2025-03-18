#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// State bitmap to track which key(s) enabled NEO_3 layer
static uint8_t neo3_state = 0;
// State bitmap to track key combo for CAPSLOCK
static uint8_t capslock_state = 0;

// bitmasks for modifier keys
#define MODS_NONE   0
#define MODS_SHIFT  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define MODS_CTRL   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL))
#define MODS_ALT    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI    (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

// Layers
#define NEO_1   0      // layer_0
#define NEO_3   1      // layer_1
#define NEO_4   2      // layer_2
#define DE_NORMAL    5      // layer_5
#define FKEYS   6      // layer_6

// Used to trigger macros / sequences of keypresses
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,     // can always be here
  NEO2_LMOD3,
  NEO2_RMOD3,
  YELDIR_AC,
  YELDIR_CTLTAB,
  YELDIR_CTLSTAB,
  NEO2_1,
  NEO2_2,
  NEO2_3,
  NEO2_4,
  NEO2_5,
  NEO2_6,
  NEO2_7,
  NEO2_8,
  NEO2_9,
  NEO2_0,
  NEO2_MINUS,
  NEO2_COMMA,
  NEO2_DOT,
  NEO2_SHARP_S
};

#define NEO2_LMOD4  MO(NEO_4)
#define NEO2_RMOD4  NEO2_LMOD4

// NEO_3 special characters
#define N2_ELL      RALT(DE_DOT)                // …

// NEO_4 special characters
#define N2_MDOT     RALT(DE_COMM)               // ·
#define N2_IEXC     RSA(DE_1)                   // ¡
#define N2_IQUE     RSA(DE_SS)                  // ¿

// My own special things
#define YELDIR_MOVETABLEFT           LCTL(LSFT(KC_PGUP))
#define YELDIR_MOVETABRIGHT          LCTL(LSFT(KC_PGDN))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NEO_1] = LAYOUT_ergodox(
    // left hand side - main
    KC_NO /* NOOP */, NEO2_1,                   NEO2_2,                   NEO2_3,                   NEO2_4,           NEO2_5,           KC_NO,
    KC_TAB,           DE_X,                     DE_V,                     DE_L,                     DE_C,             DE_W,             YELDIR_CTLSTAB,
    NEO2_LMOD3,       DE_U,                     DE_I,                     DE_A,                     DE_E,             DE_O,
    KC_LSFT,          DE_UDIA,                  DE_ODIA,                  DE_ADIA,                  DE_P,             DE_Z,             KC_MS_BTN1,
    KC_MS_WH_LEFT,    KC_MS_WH_DOWN,            KC_MS_WH_UP,              KC_MS_WH_RIGHT,           NEO2_LMOD4,

    // left hand side - thumb cluster
                      KC_APPLICATION,   LCTL(DE_S),
                                        YELDIR_AC,
    KC_LGUI,          KC_LALT,          KC_LCTL,

    // right hand side - main
    TO(DE_NORMAL),    NEO2_6,           NEO2_7,           NEO2_8,           NEO2_9,           NEO2_0,           NEO2_MINUS,
    YELDIR_CTLTAB,    DE_K,             DE_H,             DE_G,             DE_F,             DE_Q,             NEO2_SHARP_S,
                      DE_S,             DE_N,             DE_R,             DE_T,             DE_D,             DE_Y,
    KC_MS_BTN2,       DE_B,             DE_M,             NEO2_COMMA,       NEO2_DOT,         DE_J,             KC_RSFT,
                                        NEO2_RMOD4,       KC_MS_LEFT,       KC_MS_DOWN,       KC_MS_UP,         KC_MS_RIGHT,

    // right hand side - thumb cluster
    KC_NO,            MO(FKEYS),
    YELDIR_AC,
    KC_RCTL,          KC_RALT,          KC_SPACE
  ),

  [NEO_3] = LAYOUT_ergodox(
    // left hand side - main
    _______,            _______,               _______,               _______,               _______,                    _______,                      _______,
    _______,            N2_ELL,      DE_UNDS,    DE_LBRC,      DE_RBRC,          DE_CIRC,            YELDIR_MOVETABLEFT,
    _______,            DE_BSLS,        DE_SLSH,         DE_LCBR,     DE_RCBR,         DE_ASTR,
    _______,            DE_HASH,          DE_DLR,        DE_PIPE,          DE_TILD,             DE_GRV,              _______,
    _______,            _______,               _______,               _______,               _______,

    // left hand side - thumb cluster
                        _______,              _______,
                                              _______,
    _______,            _______,              _______,

    // right hand side - main
    _______,            _______,               _______,               _______,               _______,                    _______,                      _______,
    YELDIR_MOVETABRIGHT,DE_EXLM,   DE_LABK,      DE_RABK,   DE_EQL,              DE_AMPR,            DE_EURO,
                        DE_QUES,  DE_LPRN,  DE_RPRN,  DE_MINS,       DE_COLN,                DE_AT,
    _______,            DE_PLUS,          DE_PERC,       DE_DQUO,  DE_QUOT,       DE_SCLN,            _______,
                                               _______,               _______,               _______,                    _______,                      _______,

    // right hand side - thumb cluster
    _______,            _______,
    _______,
    _______,            _______,              _______
  ),

  [NEO_4] = LAYOUT_ergodox(
    // left hand side - main
    _______,            _______,                  _______,                  _______,              N2_MDOT, _______,               _______,
    _______,            KC_PGUP,                  KC_BSPC,                  KC_UP,                KC_DELETE,          KC_PGDN,               _______,
    _______,            KC_HOME,                  KC_LEFT,                  KC_DOWN,              KC_RIGHT,           KC_END,
    _______,            KC_ESCAPE,                KC_TAB,                   KC_INSERT,            KC_ENTER,           _______,               _______,
    _______,            _______,                  _______,                  _______,              _______,

    // left hand side - thumb cluster
                        _______,                  _______,
                                                  _______,
    _______,            _______,                  _______,

    // right hand side - main
    _______,            _______,                   KC_TAB,                   DE_SLSH,     DE_ASTR,         DE_MINS,              _______,
    _______,            N2_IEXC,   KC_7,                     KC_8,              KC_9,            DE_PLUS,              _______,
                        N2_IQUE,  KC_4,                     KC_5,              KC_6,            DE_COMM,              DE_DOT,
    _______,            DE_COLN,             KC_1,                     KC_2,              KC_3,            DE_SCLN,    _______,
                                                  _______,                   KC_0,              _______,         _______,              _______,

    // right hand side - thumb cluster
    _______,            _______,
    _______,
    _______,            _______,                  _______
  ),

  [DE_NORMAL] = LAYOUT_ergodox(
    // left hand side - main
    KC_ESCAPE,        DE_1,         DE_2,       DE_3,       DE_4,       DE_5,       KC_ESCAPE,
    KC_TAB,           DE_Q,         DE_W,       DE_E,       DE_R,       DE_T,       KC_NO /* NOOP */,
    KC_LSFT,          DE_A,         DE_S,       DE_D,       DE_F,       DE_G,
    KC_LSFT,          DE_Y,         DE_X,       DE_C,       DE_V,       DE_B,       KC_NO /* NOOP */,
    KC_LCTL,          KC_LGUI,      KC_LALT,    KC_NO,      MO(FKEYS),

    // left hand side - thumb cluster
                      KC_NO,        KC_NO,
                                    KC_NO,
    KC_SPACE,         KC_LALT,      KC_LCTL,

    // right hand side - main
    TO(NEO_1),        DE_6,         DE_7,       DE_8,       DE_9,       DE_0,       DE_SS,
    KC_NO,            DE_Z,         DE_U,       DE_I,       DE_O,       DE_P,       DE_UDIA,
                      DE_H,         DE_J,       DE_K,       DE_L,       DE_ODIA,    DE_ADIA,
    KC_NO /* NOOP */, DE_N,         DE_M,       DE_COMM,    DE_DOT,     DE_MINS,    KC_RSFT,
                                    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_RGUI,

    // right hand side - thumb cluster
    KC_RALT,          KC_RCTL,
    KC_NO,
    KC_BSPC,          KC_ENTER,     KC_SPACE
  ),

  [FKEYS] = LAYOUT_ergodox(
    // left hand side - main
    KC_MEDIA_REWIND,        KC_F1,              KC_F2,              KC_F3,                KC_F4,              KC_F5,              KC_F11,
    KC_MEDIA_PLAY_PAUSE,    _______,            _______,            _______,              _______,            _______,            _______,
    KC_MEDIA_FAST_FORWARD,  _______,            _______,            _______,              _______,            _______,
    _______,                _______,            _______,            _______,              _______,            _______,            _______,
    _______,                _______,            _______,            _______,              _______,

    // left hand side - thumb cluster
                            _______,            _______,
                                                _______,
    _______,                _______,            _______,

    // right hand side - main
    KC_F12,                 KC_F6,              KC_F7,              KC_F8,                KC_F9,              KC_F10,             KC_AUDIO_VOL_UP,
    _______,                _______,            _______,            _______,              _______,            _______,            KC_AUDIO_VOL_DOWN,
                            _______,            _______,            _______,              _______,            _______,            KC_AUDIO_MUTE,
    _______,                _______,            _______,            _______,              _______,            _______,            _______,
                                                _______,            _______,              _______,            _______,            _______,

    // right hand side - thumb cluster
    _______,                _______,
    _______,
    _______,                _______,            _______
  ),
};

// Special remapping for keys with different keycodes/macros when used with shift modifiers.
bool process_record_user_shifted(uint16_t keycode, keyrecord_t *record) {
  uint8_t active_modifiers = get_mods();
  uint8_t shifted = active_modifiers & MODS_SHIFT;

  // Early return on key release
  if(!record->event.pressed) {
    return true;
  }

  if(shifted) {
    clear_mods();

    switch(keycode) {
      case NEO2_1:
        // degree symbol
        SEND_STRING(SS_LSFT("`"));
        break;
      case NEO2_2:
        // section symbol
        SEND_STRING(SS_LSFT("3"));
        break;
      case NEO2_3:
        SEND_STRING(SS_RALT("1"));
        break;
      case NEO2_4:
        // right angled quote
        SEND_STRING(SS_RALT("z"));
        break;
      case NEO2_5:
        // left angled quote
        SEND_STRING(SS_RALT("x"));
        break;
      case NEO2_6:
        // dollar sign
        SEND_STRING(SS_LSFT("4"));
        break;
      case NEO2_7:
        // euro sign
        SEND_STRING(SS_RALT("e"));
        break;
      case NEO2_8:
        // low9 double quote
        SEND_STRING(SS_RALT("v"));
        break;
      case NEO2_9:
        // left double quote
        SEND_STRING(SS_RALT("b"));
        break;
      case NEO2_0:
        // right double quote
        SEND_STRING(SS_RALT("n"));
        break;
      case NEO2_MINUS:
        // em dash
        SEND_STRING(SS_LSFT(SS_RALT("/")));
        break;
      case NEO2_COMMA:
        // en dash
        SEND_STRING(SS_RALT("/"));
        break;
      case NEO2_DOT:
        // bullet
        SEND_STRING(SS_RALT(","));
        break;
      case NEO2_SHARP_S:
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
      case NEO2_1:
        SEND_STRING(SS_TAP(X_1));
        break;
      case NEO2_2:
        SEND_STRING(SS_TAP(X_2));
        break;
      case NEO2_3:
        SEND_STRING(SS_TAP(X_3));
        break;
      case NEO2_4:
        SEND_STRING(SS_TAP(X_4));
        break;
      case NEO2_5:
        SEND_STRING(SS_TAP(X_5));
        break;
      case NEO2_6:
        SEND_STRING(SS_TAP(X_6));
        break;
      case NEO2_7:
        SEND_STRING(SS_TAP(X_7));
        break;
      case NEO2_8:
        SEND_STRING(SS_TAP(X_8));
        break;
      case NEO2_9:
        SEND_STRING(SS_TAP(X_9));
        break;
      case NEO2_0:
        SEND_STRING(SS_TAP(X_0));
        break;
      case NEO2_MINUS:
        SEND_STRING(SS_TAP(X_SLASH));
        break;
      case NEO2_COMMA:
        SEND_STRING(SS_TAP(X_COMMA));
        break;
      case NEO2_DOT:
        SEND_STRING(SS_TAP(X_DOT));
        break;
      case NEO2_SHARP_S:
        // ß
        SEND_STRING(SS_TAP(X_MINS));
        break;
      case DE_CIRC:
        SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_SPACE));
        break;
      case DE_GRV:
        SEND_STRING(SS_LSFT("=") SS_TAP(X_SPACE));
        break;
      case YELDIR_CTLTAB:
        SEND_STRING(SS_LCTL("\t"));
        break;
      case YELDIR_CTLSTAB:
        SEND_STRING(SS_LSFT(SS_LCTL("\t")));
        break;
      default:
        return true;
    }

    return false;
  }
}

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_LSFT:
      if (record->event.pressed) {
        capslock_state |= (MOD_BIT(KC_LSFT));
      } else {
        capslock_state &= ~(MOD_BIT(KC_LSFT));
      }
      break;
    case KC_RSFT:
      if (record->event.pressed) {
        capslock_state |= MOD_BIT(KC_RSFT);
      } else {
        capslock_state &= ~(MOD_BIT(KC_RSFT));
      }
      break;
    case YELDIR_AC:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
      }
      break;
    case NEO2_LMOD3:
      if (record->event.pressed) {
        layer_on(NEO_3);
        neo3_state |= (1 << 1);
      } else {
        // Turn off NEO_3 layer unless it's enabled through NEO2_RMOD3 as well.
        if ((neo3_state & ~(1 << 1)) == 0) {
          layer_off(NEO_3);
        }
        neo3_state &= ~(1 << 1);
      }
      break;
  }

  if ((capslock_state & MODS_SHIFT) == MODS_SHIFT) {
    // CAPSLOCK is currently active, disable it
    if (host_keyboard_led_state().caps_lock) {
      unregister_code(KC_LOCKING_CAPS_LOCK);
    } else {
      register_code(KC_LOCKING_CAPS_LOCK);
    }
    return false;
  }

  return process_record_user_shifted(keycode, record);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NEO_3:
            ergodox_right_led_1_on();
            break;
        case NEO_4:
            ergodox_right_led_2_on();
            break;
        case DE_NORMAL:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }
};
