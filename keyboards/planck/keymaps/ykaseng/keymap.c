/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _BASE,
  _NAVR,
  _MOUR,
  _MEDR,
  _NSL,
  _NSSL,
  _FUNL
};

#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

#define MEDR LT(_MEDR, KC_ESC)
#define NAVR LT(_NAVR, KC_BSPC)
#define MOUR LT(_MOUR, KC_TAB)
#define NSSL LT(_NSSL, KC_ENT)
#define NSL  LT(_NSL,  KC_SPC)
#define FUNL LT(_FUNL, KC_DEL)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LSFT_T(KC_E)
#define HOME_U LCTL_T(KC_U)

// Right-hand home row mods
#define HOME_H RCTL_T(KC_H)aa
#define HOME_T RSFT_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_planck_grid(
    KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,  KC_NA, KC_NA,   KC_F,    KC_G,    KC_C,   KC_R,    KC_L,
    HOME_A,   HOME_O,  HOME_E,  HOME_U,  KC_I,  KC_NA, KC_NA,   KC_D,    HOME_H,  HOME_T, HOME_N,  HOME_S,
    KC_SLSH,  KC_Q,    KC_J,    KC_K,    KC_X,  KC_NA, KC_NA,   KC_B,    KC_M,    KC_W,   KC_V,    KC_Z,
    KC_NA,    KC_NA,   MEDR,    NAVR,    MOUR,  KC_NA, KC_NA,   NSSL,    NSL,     FUNL,   KC_NA,   KC_NA
),
[_MEDR] = LAYOUT_planck_grid(
    KC_RST, KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,
    HOME_A, HOME_O, HOME_E, HOME_U, KC_NA,  KC_NA,  KC_NA,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NU,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_MSTP, KC_MPLY, KC_MUTE, KC_NA,   KC_NA
),
[_NAVR] = LAYOUT_planck_grid(
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
    HOME_A, HOME_O, HOME_E, HOME_U, KC_NA,  KC_NA,  KC_NA,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_ENT,  KC_BSPC, KC_DEL,  KC_NA,   KC_NA
),
[_MOUR] = LAYOUT_planck_grid(
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    HOME_A, HOME_O, HOME_E, HOME_U, KC_NA,  KC_NA,  KC_NA,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NA,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NA,
    KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_NA,  KC_BTN1, KC_BTN3, KC_BTN2, KC_NA,   KC_NA
),
[_FUNL] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,  KC_NA,  KC_NA,  KC_NA,   HOME_H,  HOME_T,  HOME_N,  HOME_S,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NA,   KC_NA,   KC_APP,  KC_SPC,  KC_TAB,   KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA
),
[_NSL] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,   KC_NA,  KC_NA,  KC_NA,   HOME_H,  HOME_T,  HOME_N,  HOME_S,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NA,   KC_NA,   KC_DOT,  KC_0,    KC_MINS,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA
),
[_NSSL] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,  KC_NA,  KC_NA,  KC_NA,   HOME_H,  HOME_T,  HOME_N,  HOME_S,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NA,   KC_NA,   KC_GT,   KC_RPRN, KC_UNDS,  KC_NA,  KC_NA,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA
)

};
