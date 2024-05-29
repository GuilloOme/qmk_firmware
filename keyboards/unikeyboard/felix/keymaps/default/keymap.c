#include QMK_KEYBOARD_H

enum my_keycodes {
  M_JIGL = SAFE_RANGE,
};

bool is_mouse_jiggle_active = false;
bool mouse_jiggle_direction = false; // used to alternate direction
uint32_t mouse_jiggle_base_frequency = 5000; // the random frequencies will be based on it (between value and value*256)
uint16_t mouse_jiggle_minimal_frequency = 10000;
uint32_t mouse_jiggle_frequency = 0;
uint32_t mouse_jiggle_timer = 0;

static uint8_t simple_rand(void) { // generate a pseudo-random between 1-256 (https://getreuer.info/posts/keyboards/macros3/index.html#random-emojis)
  static uint16_t random = 1;
  random *= UINT16_C(36563);
  return (uint8_t)(random >> 8)+1;
}

static uint32_t get_random_frequency(void){
  return (uint32_t)(((simple_rand()*mouse_jiggle_base_frequency)/256)+mouse_jiggle_minimal_frequency);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case M_JIGL:
          if (record->event.pressed) {
              mouse_jiggle_frequency = get_random_frequency();
              is_mouse_jiggle_active = !is_mouse_jiggle_active;
          }
          break;
    }

    return true;
}

void matrix_scan_user(void) {

    if (is_mouse_jiggle_active) {
        if (timer_elapsed(mouse_jiggle_timer) > mouse_jiggle_frequency) {
            mouse_jiggle_timer = timer_read();
            if (mouse_jiggle_direction) {
                tap_code(KC_MS_LEFT);
            } else {
                tap_code(KC_MS_RIGHT);
            }
            mouse_jiggle_direction = !mouse_jiggle_direction;
            mouse_jiggle_frequency = get_random_frequency();
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_5x4(
        KC_NUM,  KC_PSLS, KC_PAST, QK_BOOTLOADER,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_END,
        KC_P1,   KC_P2,   KC_P3,   M_JIGL,
        KC_P0,   KC_PEQL, KC_PDOT, KC_PENT
    )
};

