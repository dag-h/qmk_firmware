/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

#define _COLE 0
#define _QWER 1
#define _NUMS 2
#define _SYMS 3
#define _UTIL 4

#define KC_AA RALT(KC_W)
#define KC_AE RALT(KC_A)
#define KC_OE RALT(KC_O)

// #define HOME_N ALT_T(KC_N)
#define HOME_N MT(MOD_LALT, KC_N)
#define HOME_E MT(MOD_LGUI, KC_E)
#define HOME_I MT(MOD_LCTL | MOD_LALT, KC_I)
#define HOME_O MT(MOD_LSFT | MOD_LGUI, KC_O)

#define HOME_A MT(MOD_LSFT | MOD_LGUI, KC_A)
#define HOME_R MT(MOD_LCTL | MOD_LALT, KC_R)
#define HOME_S MT(MOD_LGUI, KC_S)
#define HOME_T MT(MOD_LALT, KC_T)

#define HOME_F11 MT(MOD_LSFT | MOD_LGUI, KC_F11)
#define HOME_F4 MT(MOD_LCTL | MOD_LALT, KC_F4)
#define HOME_F5 MT(MOD_LGUI, KC_F5)
#define HOME_F6 MT(MOD_LALT, KC_F6)

#define HOME_4 MT(MOD_LALT, KC_4)
#define HOME_5 MT(MOD_LGUI, KC_5)
#define HOME_6 MT(MOD_LCTL | MOD_LALT, KC_6)
#define HOME_INS MT(MOD_LSFT | MOD_LGUI, KC_INS)

#define UT_ENT LT(_UTIL, KC_ENT)

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM aa_combo[] = {HOME_A, HOME_R, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {HOME_A, HOME_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {HOME_A, HOME_O, COMBO_END};
combo_t key_combos[] = {
    COMBO(aa_combo, KC_AA),
    COMBO(ae_combo, KC_AE),
    COMBO(oe_combo, KC_OE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM_CTL,MO(_SYMS), KC_SPC,    UT_ENT,MO(_NUMS),OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),

    [_QWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(_UTIL), KC_SPC,     UT_ENT,MO(_NUMS), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUMS] = LAYOUT_split_3x6_3(

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,  KC_F12,   KC_F7,   KC_F8,   KC_F9,   KC_AA,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_PSCR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_LCTL,HOME_F11, HOME_F4, HOME_F5, HOME_F6,   KC_AE,                      XXXXXXX,  HOME_4,  HOME_5,  HOME_6,HOME_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_LSFT,  KC_F10,   KC_F1,   KC_F2,   KC_F3,   KC_OE,                         KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      OSM_CTL, XXXXXXX,  KC_SPC,     UT_ENT, XXXXXXX, OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),


    [_SYMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      OSM_CTL, XXXXXXX, KC_SPC,      UT_ENT, XXXXXXX, OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),

    [_UTIL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_VOLD, KC_WFWD,DF(_COLE), XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_6,    KC_7,   KC_UP,    KC_8,    KC_9,                      KC_MPLY, XXXXXXX,DF(_QWER), XXXXXXX, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      KC_VOLU, KC_WBAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      OSM_CTL, XXXXXXX,  KC_SPC,     UT_ENT, QK_BOOT, OSM_SFT
                                      //`--------------------------'  `--------------------------'
  )
};
