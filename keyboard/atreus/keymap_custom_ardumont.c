#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_FN7, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_FN8, \
         KC_FN5, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_FN6, \
         KC_FN4, KC_TAB, KC_ESC, KC_LSFT, KC_LALT, KC_SPC, KC_SPC, KC_LALT, KC_FN0, KC_MINS, KC_QUOT, KC_FN4),                     \
  /* 1: punctuation and numbers */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_BSLS), \
         KC_RBRC, KC_7, KC_8, KC_9, SHIFT(KC_8), \
         SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_GRAVE, \
         SHIFT(KC_SLSH), KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),                   \
         SHIFT(KC_5), SHIFT(KC_6), KC_LBRC, KC_RBRC, SHIFT(KC_GRAVE), \
         SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,                       \
         KC_FN4, SHIFT(KC_INS), KC_FN1, KC_LSFT, KC_LALT, KC_SPC, KC_SPC, KC_LALT, KC_FN0, KC_DOT, KC_0, KC_FN4), \
  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC_NO, KC_ESC, KC_LSFT, KC_LALT, KC_SPC, KC_SPC, KC_LALT, KC_FN2, KC_NO, KC_FN3, KC_FN4), \
  /* 3: C-i sends TAB and C-m sends ENTER, the rest sends usual CTRL-<character> */
  KEYMAP(CTRL(KC_Q), CTRL(KC_W), CTRL(KC_E), CTRL(KC_R), CTRL(KC_T), CTRL(KC_Y), CTRL(KC_U), KC_TAB, CTRL(KC_O), KC_UP, \
         CTRL(KC_A), CTRL(KC_S), CTRL(KC_D), KC_RIGHT, CTRL(KC_G), KC_BSPC, CTRL(KC_J), CTRL(KC_K), CTRL(KC_L), CTRL(KC_SCLN), \
         CTRL(KC_Z), CTRL(KC_X), CTRL(KC_C), CTRL(KC_V), KC_LEFT, KC_DOWN, KC_ENT, CTRL(KC_COMM), CTRL(KC_DOT), CTRL(KC_SLSH), \
         KC_TRNS, CTRL(KC_TAB), CTRL(KC_ESC), CTRL(KC_LSFT), CTRL(KC_LALT), CTRL(KC_SPC), CTRL(KC_SPC), CTRL(KC_LALT), CTRL(KC_FN0), CTRL(KC_MINS), CTRL(KC_QUOT), KC_TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_LAYER_MOMENTARY(3), // to Ctrl overlay
  [5] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z), // shift on z pressed
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SLSH), // shift on / pressed
  [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_A), // ctrl on a pressed
  [8] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SCLN), // ctrl on ; pressed
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
