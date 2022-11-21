 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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
#include "drivers/sensors/pimoroni_trackball.h"

void keyboard_post_init_user(void) {
  pimoroni_trackball_set_rgbw(255,215,0,0);
}
extern uint8_t is_master;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                             KC_LCTRL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,   LOWER,   RAISE, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV, _______, _______, _______, _______, _______,               _______, _______, _______,_______, _______, KC_MINS,
  KC_F1,   KC_F2,   KC_UP,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_RBRC,
  KC_LEFT, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT,
  _______, _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_EQL,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  _______,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOTLOADER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

unsigned int state = 0;

static const char PROGMEM space_row_1_map[] = {
    0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
    0x00, 0x1e, 0xff, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x80, 0x81, 0x03, 0x00, 0x00, 0xc0, 0x03, 0x00,
    0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00
};

static const char PROGMEM space_row_1_list[] = {
    0xc0, 0xfc, 0xff, 0xff, 0xff, 0xe1, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x38, 0x38, 0x78, 0x78,
    0x7b, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x03, 0x03, 0x1f, 0xff, 0xff, 0xfc,
    0x80, 0x80, 0x70, 0x70, 0x60, 0x80, 0xc0, 0xc0, 0x80, 0xf8, 0xfc, 0xe6, 0xb2, 0x3e, 0xbe, 0xfe,
    0xec, 0xf8, 0xff, 0xff, 0x02, 0x80, 0x80, 0xc0, 0xe0, 0xc0, 0x80, 0xc0, 0x80, 0x80, 0xc0, 0xfc,
    0xff, 0xff, 0xff, 0xe1, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x38, 0x38, 0x78, 0x78, 0x7b, 0x7f,
    0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x03, 0x03, 0x1f, 0xff, 0xff, 0xfc, 0x80, 0x80,
    0x70, 0x70, 0x60
};

static const char PROGMEM space_row_2_map[] = {
    0x00, 0x00, 0xfc, 0xff, 0xf1, 0xff, 0x03, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3e, 0xfe, 0x00, 0x00, 0xff, 0x07, 0x00, 0x80, 0x03, 0xfe, 0x01, 0x00, 0xc0, 0x01, 0x00,
    0x00, 0x00, 0xfc, 0xff, 0xf1, 0xff, 0x03, 0x00, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM space_row_2_list[] = {
    0x01, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0x80,
    0xc0, 0xe0, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x18, 0x38, 0x38,
    0x03, 0x03, 0x01, 0x07, 0x06, 0x07, 0x05, 0x03, 0x01, 0x03, 0x03, 0x02, 0x03, 0x03, 0x01, 0x80,
    0xc0, 0xc0, 0xc0, 0x40, 0x60, 0x20, 0x20, 0x38, 0x3f, 0x18, 0x03, 0x03, 0x03, 0x80, 0xc0, 0xe0,
    0xe0, 0xe0, 0xf0, 0x70, 0x30, 0x01, 0x03, 0x03, 0x01, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0x80, 0xc0, 0xe0, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x3f, 0x0f, 0x18, 0x38, 0x38, 0x03, 0x03, 0x01
};

static const char PROGMEM space_row_3_map[] = {
    0x00, 0x00, 0xc0, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0x00, 0x00, 0x3c,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0x00, 0x00, 0x3c
};

static const char PROGMEM space_row_3_list[] = {
    0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7c, 0x7c, 0x7c, 0x7f, 0x7f,
    0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x01, 0x80, 0xc0, 0xe0, 0x70, 0xb8, 0x38, 0x3c,
    0x7c, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0x06, 0x40, 0xc0, 0xe0, 0xc0, 0x0e, 0x0e, 0x0e, 0x02, 0x02,
    0x03, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x06, 0x0c, 0x18, 0x30, 0xe0, 0xc0, 0xc0, 0x80, 0xfc,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f,
    0x7f, 0x7f, 0x7c, 0x7c, 0x7c, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x01,
    0x80, 0xc0, 0xe0, 0x70, 0xb8, 0x38, 0x3c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0x06, 0x40, 0xc0,
    0xe0, 0xc0
};

static const char PROGMEM space_row_4_map[] = {
    0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x80, 0x03, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x0f, 0x80, 0xff, 0x7f, 0x00, 0x38, 0x00, 0x00,
    0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x80, 0x03, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x18
};

static const char PROGMEM space_row_4_list[] = {
    0x06, 0x0e, 0x0e, 0x0c, 0x1e, 0x0c, 0x04, 0x0e, 0x0e, 0x03, 0x0f, 0x1f, 0x38, 0x31, 0x71, 0x70,
    0x30, 0x3c, 0x1f, 0x0f, 0x07, 0x01, 0x01, 0x01, 0x03, 0x03, 0x01, 0x03, 0x03, 0x02, 0x02, 0x06,
    0x04, 0x04, 0x0c, 0x0c, 0x08, 0x18, 0x18, 0x10, 0x38, 0x38, 0x10, 0x01, 0x07, 0x0f, 0x1f, 0x3f,
    0x3f, 0x3f, 0x7f, 0x7e, 0x7e, 0x7c, 0x3c, 0x3c, 0x1c, 0x1c, 0x08, 0x30, 0x38, 0x38, 0x06, 0x0e,
    0x0e, 0x0c, 0x1e, 0x0c, 0x04, 0x0e, 0x0e, 0x03, 0x0f, 0x1f, 0x38, 0x31, 0x71, 0x70, 0x30, 0x3c,
    0x1f, 0x0f, 0x07, 0x01, 0x01, 0x01
};

static const char PROGMEM ship_row_1_map[] = {
    0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM ship_row_1_list[] = {
    0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x80
};

static const char PROGMEM ship_row_2_map[] = {
    0xc0, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM ship_row_2_list[] = {
    0x03, 0x07, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e,
    0x3e, 0x7c, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0x80
};

static const char PROGMEM ship_row_3_map[] = {
    0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM ship_row_3_list[] = {
    0x40, 0x60, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x1e, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x03
};

static const char PROGMEM ship_row_4_map[] = {
    0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM ship_row_4_list[] = {
    0x01, 0x01
};

static const char PROGMEM mask_row_1_map[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x01
};

static const char PROGMEM mask_row_1_list[] = {
    0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const char PROGMEM mask_row_2_map[] = {
    0x7f, 0x00, 0x00, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x01
};

static const char PROGMEM mask_row_2_list[] = {
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x1c, 0x08, 0x80, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const char PROGMEM mask_row_3_map[] = {
    0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x01
};

static const char PROGMEM mask_row_3_list[] = {
    0xff, 0xff, 0xff, 0xff, 0x3f, 0x1c, 0x08, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xfc, 0xfe,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static const char PROGMEM mask_row_4_map[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const char PROGMEM mask_row_4_list[] = {
    0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static char get_compressed_byte(const char* input_block_list, const char* input_block_map, const int i) {
    uint8_t bit = i%8;
    uint8_t map_index = i/8;
    uint8_t _block_map = (uint8_t)pgm_read_byte_near(input_block_map + map_index);
    uint8_t nonzero_byte = (_block_map & (1 << bit));
    if (nonzero_byte) {
        return (const char)pgm_read_byte_near(input_block_list + i);
    } else {
        return (const char)0x00;
    }
}

static void render_space(void) {
    char wpm = get_current_wpm();
    char render_row[128];
    int i;
    oled_set_cursor(0,0);
    for(i=0; i<wpm/4; i++) {
        render_row[i] = get_compressed_byte(space_row_1_list, space_row_1_map, i+state);
    };
    for(i=wpm/4; i<128; i++) {
        render_row[i] = (get_compressed_byte(space_row_1_list, space_row_1_map, i+state)&get_compressed_byte(mask_row_1_list, mask_row_1_map, i-wpm/4)) | get_compressed_byte(ship_row_1_list, ship_row_1_map, i-wpm/4);
    };

    oled_write_raw(render_row, 128);
    // oled_write_raw_P(space_row_1, 128);
    oled_set_cursor(0,1);
    for(i=0; i<wpm/4; i++) {
        render_row[i] = get_compressed_byte(space_row_2_list, space_row_2_map, i+state);
    };
    for(i=wpm/4; i<128; i++) {
        render_row[i] = (get_compressed_byte(space_row_2_list, space_row_2_map, i+state)&get_compressed_byte(mask_row_2_list, mask_row_2_map, i-wpm/4)) | get_compressed_byte(ship_row_2_list, ship_row_2_map, i-wpm/4);
    };
    oled_write_raw(render_row, 128);
    oled_set_cursor(0,2);
    for(i=0; i<wpm/4; i++) {
        render_row[i] = get_compressed_byte(space_row_3_list, space_row_3_map, i+state);
    };
    for(i=wpm/4; i<128; i++) {
        render_row[i] = (get_compressed_byte(space_row_3_list, space_row_3_map, i+state)&get_compressed_byte(mask_row_3_list, mask_row_3_map, i-wpm/4)) | get_compressed_byte(ship_row_3_list, ship_row_3_map, i-wpm/4);
    };

    oled_write_raw(render_row, 128);
    oled_set_cursor(0,3);
    for(i=0; i<wpm/4; i++) {
        render_row[i] = get_compressed_byte(space_row_4_list, space_row_4_map, i+state);
    };
    for(i=wpm/4; i<128; i++) {
        render_row[i] = (get_compressed_byte(space_row_4_list, space_row_4_map, i+state)&get_compressed_byte(mask_row_4_list, mask_row_4_map, i-wpm/4)) | get_compressed_byte(ship_row_4_list, ship_row_4_map, i-wpm/4);
    };

    oled_write_raw(render_row, 128);

    state = (state + 1 + (wpm/15)) % (128*2);
}

bool oled_task_user(void) {
  render_space();
    return false;
}

#endif // OLED_ENABLE


// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if(IS_LAYER_ON(_RAISE)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
    return true;
}
#endif

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = -mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LOWER) {
        if (record->event.pressed) {
            set_scrolling = true;
        } else {
            set_scrolling = false;
        }
    }
    return true;
}