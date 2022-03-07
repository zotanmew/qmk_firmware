 /* Copyright 2021 OpenAnnePro community
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    _BASE,
    _MOD,
    _FUNC
};

enum anne_pro_keycodes {
    BASE = SAFE_RANGE,
    MOD,
    EURO
};

/*
* Base
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Mod     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Alt  |  Cmd  |               space             |  Cmd  |  Fn   |  Alt  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       Up       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  Left |  Down | Right |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_60_ansi(
    KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8,    KC_9,    KC_0,               KC_MINS,         KC_EQL,        KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I,    KC_O,    KC_P,               KC_LBRC,         KC_RBRC,       KC_BSLS,
    MOD,     KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN,            KC_QUOT,         KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,   KC_M, KC_COMM, KC_DOT,           KC_SLSH,   RSFT_T(KC_UP),
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                KC_RGUI, LT(_FUNC, KC_LEFT), RALT_T(KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Mod
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_MOD] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME,   KC_END,  _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN,   _______,
    _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,    _______,
    _______, _______, _______,                            _______,                   _______, _______, MO(_FUNC), _______
),
  /*
  * Func
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |RESET| UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |PrSc| HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FUNC] = LAYOUT_60_ansi(
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
    _______, RESET,      KC_UP,      _______,    _______,    _______, _______, _______, _______, _______, KC_PSCR,   KC_HOME, KC_END,  _______,
    _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______, KC_PGUP,   KC_PGDN, _______,
    _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______, KC_INS,    KC_DEL,  _______,
    _______, _______,    _______,                                     _______,                   _______, MO(_FUNC), _______, _______
 ),
};

void keyboard_post_init_user(void) {
    ap2_led_disable();
    ap2_led_reset_foreground_color();
    ap2_led_set_foreground_color(0x00, 0x00, 0x00);
    ////ap2_led_mask_set_all();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOD:
      if (record->event.pressed) {
        layer_on(_MOD);
      } else {
        layer_off(_MOD);
      }
      return false;
      break;
    case EURO:
      if (record->event.pressed){
        send_string("€");
      }
  }
  return true;
};