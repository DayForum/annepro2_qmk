#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

enum custom_codes {
  ENABLE_OR_DISABLE_LEDS
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,   KC_7, KC_8,           KC_9,    KC_0,    KC_MINS,  KC_EQL, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,   KC_U, KC_I,           KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,   KC_H,   KC_J, KC_K,           KC_L, KC_SCLN,    KC_QUOT,  KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   KC_N,   KC_M, KC_COMM,      KC_DOT, KC_SLSH,    KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_RCTL
),
  /*
  * Layer _FN1_LAYER
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
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END,  KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLD, KC_MPLY, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_INS,  KC_DEL,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_AP2_USB,     KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_AP_LED_ON, ENABLE_OR_DISABLE_LEDS, KC_AP_LED_SPEED, KC_AP_LED_NEXT_INTENSITY, KC_AP2_BT_UNPAIR,
    KC_TRNS,        KC_TRNS,    KC_UP,      KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,      KC_PSCR,       KC_HOME, KC_END, KC_TRNS,
    KC_TRNS,        KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,      KC_PGUP,       KC_PGDN, KC_TRNS,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_INS,       KC_DEL,        KC_TRNS,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}



// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
	const annepro2Led_t colorinitializing = {
        .p.red = 0x00, //00
        .p.green = 0xff, //78
        .p.blue = 0x00, //ff
        .p.alpha = 0xff
    };
    annepro2LedEnable();
	annepro2LedBlink(0, 0, colorinitializing, 5, 20);
	annepro2LedSetProfile(1);
}


bool is_led_on = true;

const annepro2Led_t colorwasd = {
    .p.red = 0xff, //00
    .p.green = 0xff, //78
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};
const annepro2Led_t colorhomeend = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //00
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};
const annepro2Led_t colorpgdnpdup = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //78
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};
const annepro2Led_t colorinsdel = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //ff
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};
const annepro2Led_t colorprtsc = {
    .p.red = 0xff, //00
    .p.green = 0xff, //00
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};
const annepro2Led_t colordel = {
    .p.red = 0xff, //00
    .p.green = 0xff, //00
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};
const annepro2Led_t colorvolume = {
    .p.red = 0x00, //00
    .p.green = 0x1e, //00
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};

//--------------------------------------------------------------------------------------------

const annepro2Led_t coloresc = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //00
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};
const annepro2Led_t colorbtkeys = {
    .p.red = 0xff, //00
    .p.green = 0xff, //00
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};
const annepro2Led_t colorrgbset = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //ff
    .p.blue = 0xff, //ff
    .p.alpha = 0xff
};
const annepro2Led_t colorrgbonoff = {
    .p.red = 0xff, //00
    .p.green = 0xff, //ff
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};
const annepro2Led_t colorbtunpair = {
    .p.red = 0xff, //ff
    .p.green = 0xff, //00
    .p.blue = 0xff, //00
    .p.alpha = 0xff
};

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      annepro2LedMaskSetKey(0, 0, coloresc);
      annepro2LedMaskSetKey(1, 2, colorwasd);
	  annepro2LedMaskSetKey(2, 1, colorwasd);
	  annepro2LedMaskSetKey(2, 2, colorwasd);
	  annepro2LedMaskSetKey(2, 3, colorwasd);
	  annepro2LedMaskSetKey(1, 11, colorhomeend);
	  annepro2LedMaskSetKey(1, 12, colorhomeend);
	  annepro2LedMaskSetKey(2, 10, colorpgdnpdup);
	  annepro2LedMaskSetKey(2, 11, colorpgdnpdup);
	  annepro2LedMaskSetKey(3, 10, colorinsdel);
	  annepro2LedMaskSetKey(3, 11, colorinsdel);
      annepro2LedMaskSetKey(1, 10, colorprtsc);
	  annepro2LedMaskSetKey(0, 13, colordel);
      annepro2LedMaskSetKey(3, 1, colorvolume);
      annepro2LedMaskSetKey(3, 2, colorvolume);
      annepro2LedMaskSetKey(3, 3, colorvolume);
      annepro2LedMaskSetKey(3, 4, colorvolume);
      annepro2LedMaskSetKey(3, 5, colorvolume);
      break;
    case _FN2_LAYER:
	  annepro2LedMaskSetKey(0, 0, coloresc);
	  annepro2LedMaskSetKey(0, 1, colorbtkeys);
	  annepro2LedMaskSetKey(0, 2, colorbtkeys);
	  annepro2LedMaskSetKey(0, 3, colorbtkeys);
	  annepro2LedMaskSetKey(0, 4, colorbtkeys);
	  annepro2LedMaskSetKey(0, 11, colorrgbset);
	  annepro2LedMaskSetKey(0, 9, colorrgbset);
	  annepro2LedMaskSetKey(0, 12, colorrgbset);
	  annepro2LedMaskSetKey(0, 10, colorrgbonoff);
	  annepro2LedMaskSetKey(0, 13, colorbtunpair);
      break;
    default:
      // Reset back to the current profile
      annepro2LedResetForegroundColor();
      break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the caps-lock to red
    const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0xff
    };

    annepro2LedMaskSetKey(2, 0, color);
    /* NOTE: Instead of colouring the capslock only, you can change the whole
       keyboard with annepro2LedSetForegroundColor */
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
      const annepro2Led_t color = {
          .p.red = 0xff,
          .p.green = 0x00,
          .p.blue = 0x00,
          .p.alpha = 0x00
      };
      annepro2LedMaskSetKey(2, 0, color);
    }
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ENABLE_OR_DISABLE_LEDS:
      if (record->event.pressed) {
        if(is_led_on) {
          is_led_on = false;
          annepro2LedDisable();
        } else {
          annepro2LedEnable();
          is_led_on = true;
        }
      }
      return true;
    default:
      return true;
  }
}
