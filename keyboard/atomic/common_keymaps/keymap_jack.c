#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Jack colemak */
  TAB,  Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, BSPC,
  RCTL,  A,    R,    S,    T,    D,    H,    N,    E,    I,    O,     QUOT,
  LSFT, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH, ENT,
  FN3, LCTL, LALT, LGUI, FN2,    SPC,     FN1, LEFT, DOWN, UP,  RGHT),
};
const uint16_t PROGMEM fn_actions[] = {


};
