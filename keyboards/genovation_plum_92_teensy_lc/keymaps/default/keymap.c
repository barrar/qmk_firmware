#include "action_layer.h"
#include "genovation_plum_92_teensy_lc.h"
#include "keycode.h"
#include "util.h"
#include "quantum_keycodes.h"
#include "hal.h"
#define  OOOOOO KC_TRNS

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* 0: qerty */
[0] = KEYMAP(
KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_PSCR,KC_F14, KC_F15,
KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,    KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_INS, KC_NO,
KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL, KC_MUTE,
KC_BSPC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_DEL, KC_HOME,KC_PGUP,KC_VOLU,
KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_END, KC_PGDN,KC_VOLD,
KC_LCTL,KC_LALT,KC_LGUI,        KC_SPC,                 KC_ENT,         KC_RALT,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT,TG(1),  MO(2)),

[1] = KEYMAP(
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO,
OOOOOO, M(0),   OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO,
OOOOOO, OOOOOO, OOOOOO,         OOOOOO,                 OOOOOO,         OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO),

[2] = KEYMAP(
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, KC_SLEP,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, M(2),   M(1),
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, KC_F19, KC_F16,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, KC_F23, KC_F20, KC_F17,
OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, OOOOOO, KC_F24, KC_F21, KC_F18,
OOOOOO, OOOOOO, OOOOOO,         OOOOOO,                 OOOOOO,         OOOOOO, OOOOOO, OOOOOO, OOOOOO, KC_F22, OOOOOO, OOOOOO),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    switch(id) {
        case 0: {
        	if (record->event.pressed) {
            	return MACRO(I(30), D(5), U(5), D(5), U(5), END );
        	}
        }
        case 1: {
        	if (record->event.pressed) {
        		register_code(KC_LGUI);
        		register_code(KC_R);
        		unregister_code(KC_R);
        		unregister_code(KC_LGUI);
        		chThdSleepMilliseconds(34);
        		SEND_STRING("nircmd monitor off");
        		register_code(KC_ENT);
        		unregister_code(KC_ENT);
        		return MACRO_NONE;
        	}
        }
         case 2: {
        	if (record->event.pressed) {
        		register_code(KC_LGUI);
        		register_code(KC_R);
        		unregister_code(KC_R);
        		unregister_code(KC_LGUI);
        		chThdSleepMilliseconds(34);
        		SEND_STRING("nircmd speak text ~$clipboard$");
        		register_code(KC_ENT);
        		unregister_code(KC_ENT);
        		return MACRO_NONE;
        	}
        }
    }
    return MACRO_NONE;
};