#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define COLE 0 // Colemak layer
#define BASE 1 // QWERTY layer
#define WORK 2 // Workman layer
#define SYMB 3 // symbols
#define MDIA 4 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Colemak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Save |           |  L2  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  | Del  |           | Ctr+ |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           | Win  |------+------+------+------+------+--------|
 * |   L1   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|  _   |           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |/ ~L3 | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctl+Sh|AltTab| LGui | Undo | Redo |                                       | Left |  Up  | Down |Right | ->L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | Esc  |       | Home | End   |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Copy |       | PgUp |       |      |
 *                                 | Space|Back  |------|       |------| Enter |Space |
 *                                 | /CTRL|Space |Paste |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[COLE] = KEYMAP(  // layer 0 : Colemak
        // left hand
        KC_EQL,         KC_1,         	KC_2,    KC_3,   KC_4,   KC_5,    	LCTL(KC_S),
        KC_TAB,         KC_Q,         	KC_W,    KC_F,   KC_P,   KC_G,   	KC_DELT,
        KC_FN0,        	KC_A,         	KC_R,    KC_S,   KC_T,   KC_D,
        KC_LSFT,        KC_Z, 			KC_X,    KC_C,   KC_V,   KC_B,   	KC_UNDS,
		M(3),			M(1),      		M(4), 	 LCTL(KC_Z),LCTL(KC_Y),
														KC_LGUI,  KC_ESC,
																  LCTL(KC_C),
                                            CTL_T(KC_SPC),KC_BSPC,LCTL(KC_V),
        // right hand
            TG(SYMB),     		KC_6,   KC_7,   KC_8,   KC_9,   KC_0,            KC_MINS,
            M(2),  				KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,         KC_BSLS,
								KC_H,   KC_N,   KC_E,   KC_I,   KC_O, 			 KC_QUOT,
            MEH_T(KC_NO),		KC_K,   KC_M,   KC_COMM,KC_DOT, LT(MDIA,KC_SLSH),KC_RSFT,
										KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,KC_FN2,
			KC_HOME,        KC_END,
			KC_PGUP,
			KC_PGDN,KC_ENT, KC_SPC
    ),

/* Keymap 1: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |  L2  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           | Ctr+ |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           | Win  |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           | Meh  |------+------+------+------+------+--------|
 * | 	    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  Up  | Down |   [  | ]/L3 | ->L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Del  |       | Alt  |Ctrl    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back  |------|       |------| Enter  |Space |
 *                                 |      |Space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,	KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,	KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,	KC_A,		KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,	KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS, 	KC_TRNS,	KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,  		KC_TRNS,
																KC_TRNS,
                                                KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,    	KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
			 KC_TRNS,  		KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
							KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
             KC_TRNS,KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,       	KC_RSFT,
                                  KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_FN3,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Workman layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |  L2  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   D  |   R  |   W  |   B  |      |           | Ctr+ |   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           | Win  |------+------+------+------+------+--------|
 * |        |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------|      |           | Meh  |------+------+------+------+------+--------|
 * | 	    |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  Up  | Down |   [  | ]/L3 | ->L0 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Del  |       | Alt  |Ctrl    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back  |------|       |------| Enter  |Space |
 *                                 |      |Space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [WORK] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,	KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,	KC_Q,       KC_D,   KC_R,   KC_W,   KC_B,   KC_TRNS,
        KC_TRNS,	KC_A,       KC_S,   KC_H,   KC_T,   KC_G,
        KC_TRNS,	KC_Z,       KC_X,   KC_M,   KC_C,   KC_V,   KC_TRNS,
        KC_TRNS, 	KC_TRNS,	KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,  		KC_TRNS,
																KC_TRNS,
                                                KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,    	KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   	KC_MINS,
			 KC_TRNS,  		KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,   	KC_BSLS,
							KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,		KC_QUOT,
             KC_TRNS,		KC_K,   KC_L,   KC_COMM,KC_DOT, KC_SLSH,	KC_RSFT,
                                  KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,	KC_FN1,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),

/* Keymap 3: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrintSc|  F1  |  F2  |  F3  |  F4  |  F5  |   `  |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   +  |   =  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   &  |   -  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   <  |   >  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  F8  |  F9  |  F10 |  F11 |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_PSCR,KC_F1,  		 KC_F2,        KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,LSFT(KC_EQL), KC_EQL,       KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,LSFT(KC_7),	 KC_MINS,      KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,LSFT(KC_COMM),LSFT(KC_DOT), KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_F8,  		 KC_F9,        KC_F10, KC_F11,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN0 - Momentary Layer 1 (Symbols)
	[1] = ACTION_LAYER_SET_CLEAR(WORK),					// FN1 - Go to Colemak Layer
	[2] = ACTION_LAYER_SET(BASE, ON_RELEASE), 			// FN2 - Go to QWERTY Layer
	[3] = ACTION_LAYER_SET(WORK, ON_RELEASE)			// FN3 - Go to Workman Layer
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
		case 1: 
		if (record->event.pressed) {
			return MACRO( D(LALT), D(TAB), W(200), U(TAB), END );
		} else {
			return MACRO( U(LALT), END );
		}
		break;
		case 2: 
		if (record->event.pressed) {
			return MACRO( D(LCTL), D(LGUI), END );
		} else {
			return MACRO( U(LGUI), U(LCTL), END );
		}
		break;
		case 3: 
		if (record->event.pressed) {
			return MACRO( D(LCTL), D(LSFT), END );
		} else {
			return MACRO( U(LSFT), U(LCTL), END );
		}
		break;
		case 4: 
		if (record->event.pressed) {
			return MACRO( D(LGUI), END );
		} else {
			return MACRO( U(LGUI), END );
		}
		break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case BASE:
			ergodox_right_led_3_on();
            break;
        case SYMB:			
			ergodox_right_led_1_on();
            break;
		case WORK:			
			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
            break;
		case MDIA:			
            ergodox_right_led_2_on();
			break;
        default:
            // none
            break;
    }

};
