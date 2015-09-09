#include "extended_keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = { /* Colemak */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, FUNC(4) },
  { KC_TAB,  CM_Q,    CM_W,    CM_F,    CM_P,    CM_G,    CM_J,    CM_L,    CM_U,    CM_Y,    CM_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME  },
  { FUNC(3), CM_A,    CM_R,    CM_S,    CM_T,    CM_D,    CM_H,    CM_N,    CM_E,    CM_I,    CM_O,    KC_QUOT, KC_ENT,  FUNC(1),   KC_PGUP},
  { KC_LSFT, CM_Z,    CM_X,    CM_C,    CM_V,    CM_B,    CM_K,    CM_M,    CM_COMM, CM_DOT,  CM_SLSH, KC_RSFT, FUNC(1),   KC_NO,   KC_A },
  { KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, KC_BSPC, KC_DEL,  KC_ENT,   KC_SPC, FUNC(2), KC_RGUI, KC_NO,   KC_NO, KC_NO, KC_NO, KC_N },
 },
 [1] = { /* function */
  { KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO   },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_MPLY },
  { KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, FUNC(1), KC_TRNS, KC_NO,   KC_TRNS, FUNC(2), KC_TRNS, KC_NO,   KC_TRNS, KC_MPRV, KC_DOWN, KC_MNXT },
 },
[3] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, FUNC(5)   },
  { KC_TAB,  CM_Q,    CM_W,    CM_E,    CM_R,    CM_T,    CM_Y,    CM_U,    CM_I,    CM_O,    CM_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME  },
  { FUNC(3), CM_A,    CM_S,    CM_D,    CM_F,    CM_G,    CM_H,    CM_J,    CM_K,    CM_L,    CM_SCLN,    KC_QUOT, KC_ENT,  FUNC(1),   KC_PGUP},
  { KC_LSFT, CM_Z,    CM_X,    CM_C,    CM_V,    CM_B,    CM_N,    CM_M,    CM_COMM, CM_DOT,  CM_SLSH, KC_RSFT, KC_UP,   KC_NO,   KC_PGDN },
  { KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, KC_BSPC, KC_DEL,  KC_ENT,   KC_SPC, FUNC(2), KC_RGUI, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_END },
 },
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(1),
[3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
	[4] = ACTION_DEFAULT_LAYER_SET(3),
[5] = ACTION_DEFAULT_LAYER_SET(0),
};


