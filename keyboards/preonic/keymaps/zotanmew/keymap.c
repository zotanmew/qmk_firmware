/* Copyright 2015-2021 Jack Humbert
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

#define SH_NUHS S(KC_NUHS)
#define SH_NUBS S(KC_NUBS)

#define SPC_LWR LT(_LOWER,KC_SPC)

enum preonic_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  DE_EURO,
  DE_OUML,
  DE_AUML,
  DE_UUML,
  DE_SHPS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |  Opt |  Cmd | Lower|    Space    | Raise| Left |  Up  | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */

[_BASE] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |      |   $  |   €  |      |      |      |   ü  |      |      |   ö  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   ä  |   ß  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |ISO ~ |ISO | |ISO # |ISO / |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgUp | PgDn |  End |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  _______, KC_DLR,  DE_EURO, _______, _______, _______, DE_UUML, _______, DE_OUML, _______, _______,
  _______, DE_AUML, DE_SHPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, SH_NUHS, SH_NUBS, KC_NUHS, KC_NUBS,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   +  |   -  |   (  |   )  |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   =  |   _  |   [  |   ]  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   +  |   -  |   |  |   #  |      |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Play/Pause |      | Play | Vol+ | Vol- |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_preonic_grid(
  KC_TILD, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_EQL,  KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, KC_QUOT,
  _______, KC_PLUS, KC_MINS, KC_PIPE, KC_HASH, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, KC_VOLD, KC_MUTE
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap| Base |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, BASE,    _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

const rgblight_segment_t PROGMEM my_base_layer[]   = RGBLIGHT_LAYER_SEGMENTS({1, 8, HSV_OFF});
const rgblight_segment_t PROGMEM my_lower_layer[]  = RGBLIGHT_LAYER_SEGMENTS({1, 8, HSV_TEAL});
const rgblight_segment_t PROGMEM my_raise_layer[]  = RGBLIGHT_LAYER_SEGMENTS({1, 8, HSV_ORANGE});
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({1, 8, HSV_MAGENTA});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_base_layer,
  my_lower_layer,
  my_raise_layer,
  my_adjust_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
  rgblight_set_layer_state(0, true);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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