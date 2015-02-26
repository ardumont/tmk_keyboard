#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q       , KC_W       , KC_E          , KC_R          , KC_T                             , KC_Y          , KC_U   , KC_I   , KC_O   , KC_P, \
         KC_FN4     , KC_S       , KC_D          , KC_F          , KC_G                             , KC_H          , KC_J   , KC_K   , KC_L   , KC_FN5, \
         KC_FN6     , KC_X       , KC_C          , KC_V          , KC_B                             , KC_N          , KC_M   , KC_COMM, KC_DOT , KC_FN7, \
         KC_ESC     , KC_FN3     , KC_BSPC       , KC_FN0        , KC_FN8          , KC_TAB, KC_ENT , KC_FN8        , KC_FN0 , KC_MINS, KC_QUOT, KC_ESC), \
  /* 1: punctuation and numbers */
  KEYMAP(SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_BSLS)                   , SHIFT(KC_MINS) , KC_7  , KC_8   , KC_9   , SHIFT(KC_8), \
         SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9)   , SHIFT(KC_0)   , KC_GRAVE                         , SHIFT(KC_QUOTE), KC_4  , KC_5   , KC_6   , SHIFT(KC_EQUAL), \
         SHIFT(KC_5), SHIFT(KC_6), KC_LBRC       , KC_RBRC       , SHIFT(KC_GRAVE)                  , SHIFT(KC_7)    , KC_1  , KC_2   , KC_3   , KC_BSLS, \
         KC_ESC     , KC_FN1     , KC_BSPC       , KC_FN0        , KC_FN8          , KC_TAB, KC_ENT , KC_FN8         , KC_FN0, KC_DOT , KC_0   , KC_EQUAL), \
  /* 2: arrows and function keys */
  KEYMAP(KC_INS     , KC_HOME    , KC_UP         , KC_END        , KC_PGUP                          , KC_UP         , KC_F7  , KC_F8  , KC_F9  , KC_F10, \
         KC_DEL     , KC_LEFT    , KC_DOWN       , KC_RIGHT      , KC_PGDN                          , KC_DOWN       , KC_F4  , KC_F5  , KC_F6  , KC_F11, \
         KC_NO      , KC_NO      , KC_NO         , KC_NO         , KC_NO                            , KC_NO         , KC_F1  , KC_F2  , KC_F3  , KC_F12, \
         KC_ESC     , KC_FN3     , KC_BSPC       , KC_FN2        , KC_FN8          , KC_TAB, KC_ENT , KC_FN8        , KC_FN2 , KC_NO  , KC_FN3 , KC_ESC), \
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_A), // A tapped then A, A pressed then Ctrl
  [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SCLN), // ; tapped then ;, ; pressed then Ctrl
  [6] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z), // a on tap, shift on pressed
  [7] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SLSH), // ; on tap, shift on pressed
  [8] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_SPC), // space on tap, alt on pressed
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
