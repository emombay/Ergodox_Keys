#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define DVOR 1 // Dvorak layer
#define COLE 2 // Colemak layer
#define SYMB 3 // symbols
#define MDIA 4 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  L3  |           |  L3  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Esc  |           | Ctr+ |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           | Win  |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|  _   |           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|AltTab| LGui | Left | Right|                                       |  Up  | Down |   [  |   ]  | ->L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Del  |       | Alt  |Ctrl    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Back  |------|       |------| Enter  |Space |
 *                                 |      |Space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(3),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_UNDS,
        LT(SYMB,KC_GRV),M(1),         KC_LGUI,KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_DELT,
                                                              KC_HOME,
                                                KC_SPC,KC_BSPC,KC_END,
        // right hand
             TG(3),       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
      LCTL(LGUI(KC_NO)),  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_QUOT,
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN3,
             KC_LALT,        KC_RCTL,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_SPC
    ),

/* Keymap 1: Dvorak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   '  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  '"  |      |      |      |      |                                       |      |      |      |      |  ->L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DVOR] = KEYMAP(  // layer 1 : Dvorak
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,   TG(3),
        KC_TRNS,        KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   	KC_TRNS,
        KC_TRNS,        KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_TRNS,        KC_SCLN, 		KC_Q,    KC_J,   KC_K,   KC_X,   	KC_TRNS,
        KC_QUOT,		KC_TRNS,      	KC_TRNS, KC_TRNS,KC_TRNS,
													 KC_TRNS,  KC_TRNS,
                                                               KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             TG(3),     	KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_BSLS,
             KC_TRNS,       KC_F,   KC_G,   KC_C,   KC_R,   KC_L,           KC_SLSH,
							KC_D,   KC_H,   KC_T,   KC_N,   LT(MDIA, KC_S), KC_MINS,
             KC_TRNS,		KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,      		KC_TRNS,
									KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_FN4,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Colemak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O / L2|   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |  ->L0  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[COLE] = KEYMAP(  // layer 2 : Colemak
        // left hand
        KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_Q,         	KC_W,    KC_F,   KC_P,   KC_G,   	KC_TRNS,
        KC_TRNS,        KC_A,         	KC_R,    KC_S,   KC_T,   KC_D,
        KC_TRNS,        KC_Z, 			KC_X,    KC_C,   KC_V,   KC_B,   	KC_TRNS,
        KC_TRNS,		KC_TRNS,      	KC_TRNS, KC_TRNS,KC_TRNS,
													 KC_TRNS,  KC_TRNS,
                                                               KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,     	KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_BSLS,
             KC_TRNS,       KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,        KC_SLSH,
							KC_H,   KC_N,   KC_E,   KC_I,   LT(MDIA, KC_O), KC_MINS,
             KC_TRNS,		KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,      	KC_TRNS,
									KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_FN2,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
/* Keymap 3: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrintSc|  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
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
       KC_PSCR,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_F8,  KC_F9,  KC_F10, KC_F11,
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
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
	[2] = ACTION_LAYER_SET_CLEAR(COLE),					// FN2 - Go to Base Layer
	[3] = ACTION_LAYER_SET(DVOR, ON_RELEASE),			// FN3 - Go to Dvorak Layer
	[4] = ACTION_LAYER_SET(COLE, ON_RELEASE) 			// FN4 - Go to Colemak Layer
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
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
			ergodox_right_led_3_on();
            break;
        case 2:			
			ergodox_right_led_1_on();
			ergodox_right_led_3_on();
            break;
		case 3:			
            ergodox_right_led_1_on();
			break;
		case 4:			
            ergodox_right_led_2_on();
			break;
        default:
            // none
            break;
    }

};
