// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "afk79.h"
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _FUNC,
  _NUMPAD
};

enum custom_keycodes {
	UKPND = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode)
	{
		case UKPND:
			if (record->event.pressed)
				SEND_STRING(SS_RALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3)));
			else;
		break;
	}
	return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/*
	 * ,--------------------------------------------------------------------------------------------------------.
	 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Prnt |  Del |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |  BACKSPACE  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |     TAB     |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |     CAPS    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    ENTER    |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |    SHIFT    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | SHFT |  UP  | FUNC |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * | CTRL |  GUI |  ALT |                                                | ALTR | CTRL | LEFT | DOWN | RGHT |
	 * `--------------------------------------------------------------------------------------------------------'
	 */
	[0] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_DEL, 
		KC_GRV,  KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,     KC_BSPC, 
		    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,       KC_BSLS, 
		    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,             KC_ENT, 
		    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, KC_UP, MO(_FUNC), 
		KC_LCTL, KC_LGUI, KC_LALT,              KC_SPC,              LM(_NUMPAD, MOD_RALT), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	/*
	 * ,--------------------------------------------------------------------------------------------------------.
	 * | RSET |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Prnt |  INS |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |   `  |   1  |   2  |   3  |   £  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |  BACKSPACE  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |     TAB     |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |     CAPS    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    ENTER    |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * |    SHIFT    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | SHFT | PGUP | FUNC |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
	 * | CTRL |  GUI |  ALT |                                                | ALTR | CTRL | HOME | PGDN | END  |
	 * `--------------------------------------------------------------------------------------------------------'
	 */
	[_FUNC] = LAYOUT(
		QK_BOOT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UKPND , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),

	[_NUMPAD] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, 
		KC_TRNS, KC_P1, KC_P2, KC_P3, KC_P4 , KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

