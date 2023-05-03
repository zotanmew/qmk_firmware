  /* Copyright 2019 Yiancar
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

enum nk65_layers {
  _BASE,
  _FUNC,
  _MOD,
  _ADJUST
};

enum nk65_keycodes {
  BASE = SAFE_RANGE,
  FUNC,
  MOD,
  SC_UML,
  DE_EURO,
  DE_OUML,
  DE_AUML,
  DE_UUML,
  DE_SHPS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_65_ansi( /* Base */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    MOD,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          FUNC,    MOD,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_RGUI
),

[_FUNC] = LAYOUT_65_ansi( /* Func */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
    _______, _______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______,          _______, KC_END,
    _______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  _______,          _______, _______,
    KC_VOLU, KC_VOLD, KC_MUTE,                   _______,                            _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______
),

[_MOD] = LAYOUT_65_ansi( /* Mod */
    KC_TILD, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_EQL,  KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, SC_UML,  _______, _______, _______, _______, _______, _______, _______,
    _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, KC_PLUS, KC_MINS, KC_PIPE, KC_HASH, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_65_ansi( /* Adjust */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
        update_tri_layer(_FUNC, _MOD, _ADJUST);
      } else {
        layer_off(_FUNC);
        update_tri_layer(_FUNC, _MOD, _ADJUST);
      }
      return false;
    case MOD:
      if (record->event.pressed) {
        layer_on(_MOD);
        update_tri_layer(_FUNC, _MOD, _ADJUST);
      } else {
        layer_off(_MOD);
        update_tri_layer(_FUNC, _MOD, _ADJUST);
      }
      return false;
    case SC_UML:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          unregister_code(KC_LSFT);
          SEND_STRING(SS_LALT("u"));
          register_code(KC_LSFT);
        }
        else {
          SEND_STRING(SS_LALT("u"));
        }
      }
      return false;
    case DE_EURO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT("2")));
      }
      return false;
    case DE_SHPS:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("s"));
      }
      return false;
    case DE_OUML:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          unregister_code(KC_LSFT);
          SEND_STRING(SS_LALT("u")"O");
          register_code(KC_LSFT);
        }
        else {
          SEND_STRING(SS_LALT("u")"o");
        }
      }
      return false;
    case DE_AUML:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          unregister_code(KC_LSFT);
          SEND_STRING(SS_LALT("u")"A");
          register_code(KC_LSFT);
        }
        else {
          SEND_STRING(SS_LALT("u")"a");
        }
      }
      return false;
    case DE_UUML:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          unregister_code(KC_LSFT);
          SEND_STRING(SS_LALT("u")"U");
          register_code(KC_LSFT);
        }
        else {
          SEND_STRING(SS_LALT("u")"u");
        }
      }
      return false;
  }
  return true;
};