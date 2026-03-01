#include "keycodes.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

enum Layers {
  BaseLayer,
  NumbersLayer,
  SystemLayer,
  ControlLayer,
  // This stays last
  MAX_LAYER_INDEX,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default layer
  [BaseLayer] = LAYOUT(
    XXX,                     LT(ControlLayer, KC_Q), KC_W, KC_E, KC_R, KC_T,
    LT(SystemLayer, KC_TAB), KC_A,                   KC_S, KC_D, KC_F, KC_G,
    XXX,                     KC_Z,                   KC_X, KC_C, KC_V, KC_B, KC_SLASH,
    KC_DOT, /* gap */ MT(LGUI(MOD_LSFT), KC_BACKSLASH), MT(MOD_LCTL, KC_ENTER), MT(MOD_LGUI, KC_ESC), MOD_LSFT,

         KC_UNDERSCORE, KC_Y, KC_U, KC_I, KC_O, KC_P,
         KC_TAB,        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON,
    XXX, XXX,           KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
    KC_BACKSPACE, MO(NumbersLayer), MT(MOD_RSFT, KC_ENTER), KC_UNDERSCORE, /* gap */ KC_LEFT_CURLY_BRACE
  ),
  // Numbers layer
  [NumbersLayer] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______, _______,
    _______, /* gap */  _______, _______, _______, _______,

             _______, KC_7, KC_8, KC_9, _______, _______,
             _______, KC_4, KC_5, KC_6, _______, _______,
    _______, _______, KC_1, KC_2, KC_3, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /* gap */ XXXXXXX
  ),
  // Systems layer
  [SystemLayer] = LAYOUT(
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______, _______,
    _______, /* gap */  _______, _______, _______, _______,

             _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
             _______, KC_F4, KC_F5, KC_F6, KC_F12, _______,
    _______, _______, KC_F1, KC_F2, KC_F3, _______, _______,
    _______, _______, _______, _______, /* gap */ QK_BOOTLOADER
  ),
  [ControlLayer] = LAYOUT(
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______, _______,
    _______, /* gap */  _______, QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_2,

             _______, _______,   _______, _______, _______, _______,
             QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP,QK_MOUSE_CURSOR_RIGHT, _______, _______,
    _______, QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_DOWN,   QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_RIGHT, _______, _______,
    QK_MOUSE_BUTTON_2, QK_MOUSE_BUTTON_3, QK_MOUSE_BUTTON_1, _______, /* gap */ _______
  ),
};
  // [NewLayer] = LAYOUT(
  //   _______, _______,   _______, _______, _______, _______,
  //   _______, _______,   _______, _______, _______, _______,
  //   _______, _______,   _______, _______, _______, _______, _______,
  //   _______, /* gap */  _______, _______, _______, _______,

  //            _______, _______,   _______, _______, _______, _______,
  //            _______, _______,   _______, _______, _______, _______,
  //   _______, _______, _______,   _______, _______, _______, _______,
  //   _______, _______, _______, _______, /* gap */ _______
  // ),
// clang-format on

#define DefaultLayerColor RGB_WHITE

const uint8_t PROGMEM layer_colors[][3] = {
    [BaseLayer] = {0x00, 0x70, 0x70},
    [NumbersLayer] = {0x00, 0xe9, 0x51},
    [SystemLayer] = {0xFF, 0x00, 0x00},
    [ControlLayer] = {DefaultLayerColor},
};

void keyboard_post_init_user(void) { rgblight_setrgb(DefaultLayerColor); }

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);
  if (layer >= MAX_LAYER_INDEX) {
    rgblight_setrgb(RGB_WHITE);
  } else {
    const uint8_t *color = layer_colors[layer];
    rgblight_setrgb(color[0], color[1], color[2]);
  }
  return state;
}
