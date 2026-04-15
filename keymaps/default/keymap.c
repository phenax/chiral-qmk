#include "keycodes.h"
#include "keymap_us.h"
#include <stdint.h>
#include QMK_KEYBOARD_H

enum Layers {
  BaseLayer,
  NumbersLayer,
  SystemLayer,
  ControlLayer,
};

DEFINE_LAYER_LIGHTS({
    [BaseLayer] = {DefaultLayerColorHSV},
    [NumbersLayer] = {0x64, 0xff, 20},
    [SystemLayer] = {0x00, 0xff, 20},
    [ControlLayer] = {0xdd, 0xff, 20},
})

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default layer
  [BaseLayer] = LAYOUT(
    XXX,                     LT(ControlLayer, KC_Q), KC_W, KC_E, KC_R, KC_T,
    LT(SystemLayer, KC_TAB), KC_A,                   KC_S, KC_D, KC_F, KC_G,
    XXX,                     KC_Z,                   KC_X, KC_C, KC_V, KC_B, KC_SLASH,
    KC_DOT, /* gap */ MT(LGUI(MOD_LSFT), KC_BACKSLASH), MT(MOD_LCTL, KC_SPACE), MT(MOD_LGUI, KC_ESC), MT(MOD_LSFT, KC_LEFT_BRACKET),

         KC_UNDERSCORE, KC_Y, KC_U, KC_I, KC_O, KC_P,
         KC_TAB,        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON,
    XXX, XXX,           KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
    KC_BACKSPACE, MO(NumbersLayer), MT(MOD_RSFT, KC_ENTER), KC_UNDERSCORE, /* gap */ KC_LEFT_CURLY_BRACE
  ),
  // Numbers layer
  [NumbersLayer] = LAYOUT(
    _______, KC_1, KC_2, KC_3, KC_4, KC_5,
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______, _______,
    _______, /* gap */  _______, _______, _______, _______,

             KC_6,    KC_7, KC_8, KC_9, _______, _______,
             _______, KC_4, KC_5, KC_6, _______, _______,
    _______, _______, KC_1, KC_2, KC_3, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /* gap */ XXXXXXX
  ),
  // Systems layer
  [SystemLayer] = LAYOUT(
    _______, _______,   _______, _______, _______, _______,
    _______, _______,   _______, _______, _______, _______,
    _______, QK_UNDERGLOW_VALUE_DOWN, QK_UNDERGLOW_VALUE_UP, _______, _______, _______, _______,
    _______, /* gap */  QK_BOOTLOADER, _______, _______, _______,

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
