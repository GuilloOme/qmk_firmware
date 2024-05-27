#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FUN1 1 // Function 1
#define FUN2 2 // Function 2
#define FUN3 3 // Function 3


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VERSION,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | esc    | " (1)| « (2)| » (3)| ( (4)| ) (5)| % (=)|           | = (-)| @ (6)| + (7)| - (8)| / (9)| * (0)| W (])  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | $ (`)  | B (Q)| É (W)| P (E)| O (R)| È (T)| BkSp |           | BkSp | ^ (Y)| V (U)| D (I)| L (O)| J (P)| Z ([)  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    | A (A)| U (S)| I (D)| E (F)| , (G)|------|           |------| C (H)| T (J)| S (K)| R (L)| N (;)| M (')  |
 * |--------+------+------+------+------+------| Ç (\)|           | Del  |------+------+------+------+------+--------|
 * | LShift | À (Z)| Y (X)| X (C)| : (V)| K (B)|      |           |      | ? (N)| Q (M)| G (,)| H (.)| F (/)| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|  L3  |      | LGui | LAlt |                                       | RAlt | RGui |      |  L3  | Enter|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Caps | L2~  |       | L2~  | Caps |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|  L1  |------|       |------|   L1   | Space|
 *                                 |      |      | Enter|       | Enter|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_EQUAL,
        KC_GRAVE,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_BSPACE,
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_BSLASH,
        KC_LCTRL,   MO(FUN3),   KC_NO,      KC_LGUI,    KC_LALT,
                                                                    KC_CAPS,    MO(FUN2),
                                                                                KC_NO,
                                                        KC_SPACE,   MO(FUN1),   KC_ENTER,
        // right hand
        KC_MINUS,   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,      KC_RBRACKET,
        KC_BSPACE,  KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      KC_LBRACKET,
                    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,   KC_QUOTE,
        KC_DEL,     KC_N,       KC_M,       KC_COMMA,   KC_DOTE,    KC_SLASH,  KC_RSHIFT,
                                KC_RALT,    KC_RGUI,    KC_NO,      MO(FUN3),  KC_ENTER,
        MO(FUN2),   KC_CAPS,
        KC_NO,
        KC_ENTER,   MO(FUN1),   KC_SPACE
    ),
/* Keymap 1: Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |           |      |      | home |  up  | end  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |selall|      |search| undo | save |------|           |------|      | left | down | right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | lock | cut  | copy | past |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FUN1] = LAYOUT_ergodox(
       // left hand
       _______,     KC_F1,       KC_F2,         KC_F3,          KC_F4,              KC_F5,      KC_F6,
       _______,     KC_F7,       KC_F8,         KC_F9,          KC_F10,             KC_F11,     KC_F12,
       _______,     LCTL(KC_A),  _______,       LCTL(KC_SLASH), LCTL(KC_LBRACKET),  LCTL(KC_K),
       _______,     LGUI(KC_O),  LCTL(KC_C),    LCTL(KC_H),     LCTL(KC_U),         _______,    _______,
       _______,     _______,     _______,       _______,        _______,
                                                                                    _______,    _______,
                                                                                                _______,
                                                                _______,            _______,    _______,
       // right hand
       _______, _______, _______,_______, _______,  _______, _______,
       _______, _______, KC_HOME,KC_UP,   KC_END,   _______, _______,
                _______, KC_LEFT,KC_DOWN, KC_RIGHT, _______, _______,
       _______, _______, _______,_______, _______,  _______, _______,
                         _______,_______, _______,  _______, _______,
       _______,_______,
       _______,
       _______,_______,_______,
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[FUN2] = LAYOUT_ergodox(
       VERSION, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       EPRM   , _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VERSION:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
