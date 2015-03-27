/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "action_code.h"
#include "action_macro.h"
#include "action_layer.h"
#include "bootloader.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "ergodox.h"


/* ErgoDox keymap definition macro */
#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,k06,                                \
    k10,k11,k12,k13,k14,k15,k16,                                \
    k20,k21,k22,k23,k24,k25,                                    \
    k30,k31,k32,k33,k34,k35,k36,                                \
    k40,k41,k42,k43,k44,                                        \
                            k55,k56,                            \
                                k54,                            \
                        k53,k52,k51,                            \
                                                                \
    /* right hand, spatial positions */                         \
        k07,k08,k09,k0A,k0B,k0C,k0D,                            \
        k17,k18,k19,k1A,k1B,k1C,k1D,                            \
            k28,k29,k2A,k2B,k2C,k2D,                            \
        k37,k38,k39,k3A,k3B,k3C,k3D,                            \
                k49,k4A,k4B,k4C,k4D,                            \
    k57,k58,                                                    \
    k59,                                                        \
    k5C,k5B,k5A )                                               \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { KC_##k00,KC_##k10,KC_##k20,KC_##k30,KC_##k40,KC_NO   },   \
    { KC_##k01,KC_##k11,KC_##k21,KC_##k31,KC_##k41,KC_##k51},   \
    { KC_##k02,KC_##k12,KC_##k22,KC_##k32,KC_##k42,KC_##k52},   \
    { KC_##k03,KC_##k13,KC_##k23,KC_##k33,KC_##k43,KC_##k53},   \
    { KC_##k04,KC_##k14,KC_##k24,KC_##k34,KC_##k44,KC_##k54},   \
    { KC_##k05,KC_##k15,KC_##k25,KC_##k35,KC_NO,   KC_##k55},   \
    { KC_##k06,KC_##k16,KC_NO,   KC_##k36,KC_NO,   KC_##k56},   \
                                                                \
    { KC_##k07,KC_##k17,KC_NO,   KC_##k37,KC_NO,   KC_##k57},   \
    { KC_##k08,KC_##k18,KC_##k28,KC_##k38,KC_NO,   KC_##k58},   \
    { KC_##k09,KC_##k19,KC_##k29,KC_##k39,KC_##k49,KC_##k59},   \
    { KC_##k0A,KC_##k1A,KC_##k2A,KC_##k3A,KC_##k4A,KC_##k5A},   \
    { KC_##k0B,KC_##k1B,KC_##k2B,KC_##k3B,KC_##k4B,KC_##k5B},   \
    { KC_##k0C,KC_##k1C,KC_##k2C,KC_##k3C,KC_##k4C,KC_##k5C},   \
    { KC_##k0D,KC_##k1D,KC_##k2D,KC_##k3D,KC_##k4D,KC_NO   }    \
   }

#if defined(KEYMAP_DVORAK)
#include "keymap_dvorak.h"
#elif defined(KEYMAP_COLEMAK)
#include "keymap_colemak.h"
#elif defined(KEYMAP_WORKMAN)
#include "keymap_workman.h"
#elif defined(KEYMAP_MICRO)
#include "keymap_micro.h"
#elif defined(KEYMAP_CUB)
#include "keymap_cub.h"
#else

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        EQL, 1,   2,   3,   4,   5,   ESC,
        BSLS,Q,   W,   F,   P,   G,   FN2,
        TAB, A,   R,   S,   T,   D,
         FN6,Z,   X,   C,   V,   B,   FN8,
        LGUI,GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           VOLU,
                                 FN5,FN3, VOLD,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,J,   L,   U,   Y,   SCLN,   RBRC,
                  H,   N,   E,   I,      O,FN10,
             FN1, K,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,FN2,
        RALT,RCTL,
        HOME,
         END,ENT, SPC
    ),
    KEYMAP(  // layer 1: qwerty
        // left hand
        EQL, 1,   2,   3,   4,   5,   ESC,
        BSLS,Q,   W,   E,   R,   T,   FN2,
        TAB, A,   S,   D,   F,   G,
        FN6, Z,   X,   C,   V,   B,   FN7,
        LGUI,GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 FN5,FN3, END,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,FN2,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, SPC 
    ),

    KEYMAP(  // layer 2 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        PGUP,
        PGDN,TRNS,TRNS
    ),



    KEYMAP(  // layer 3: Mouse Layer
        // left hand
        FN0,PAUS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 BTN1,TRNS,TRNS,
        // right hand
             TRNS,TRNS,  TRNS,  TRNS,  TRNS,  TRNS,TRNS,
             TRNS,TRNS,  WH_D,  MS_U,  WH_U,  TRNS,TRNS,
                  TRNS,  MS_L,  MS_D,  MS_R, TRNS,TRNS,
             TRNS,TRNS,  TRNS,  TRNS,  TRNS,  TRNS,TRNS,
                         TRNS,  TRNS,  TRNS,  TRNS, FN4,
        TRNS,TRNS,
        PGUP,
        PGDN,TRNS,BTN2
    ),
    KEYMAP(  // layer 4 : Layout Selector
        // left hand
        FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS, FN8, FN7,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(TEENSY_KEY),                  // FN0 - Teensy key
    [1] = ACTION_LAYER_MOMENTARY(2),                    // FN1 - switch to Layer2 function layer
    [2] = ACTION_LAYER_TAP_TOGGLE(3),					// Mouse layer
    [3] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DEL),
    [4] = ACTION_LAYER_OFF(3, ON_RELEASE),
    [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPC),
    [6] = ACTION_MODS_ONESHOT(MOD_LSFT),  
    [7] = ACTION_DEFAULT_LAYER_SET(0),  				// set colemak layout
    [8] = ACTION_DEFAULT_LAYER_SET(1),  				// set qwerty layout
    [9] = ACTION_LAYER_MOMENTARY(4),  					// Layout Selector
    [10] = ACTION_LAYER_TAP_KEY(3, KC_QUOT),

};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

#endif


#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

#if defined(KEYMAP_CUB)

// function keymap_fn_to_action will be defined in keymap_cub.h

#else
/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
#endif
