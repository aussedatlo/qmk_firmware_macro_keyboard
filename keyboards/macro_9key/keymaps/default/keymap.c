/*
Copyright 2024 Custom

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
#include <avr/io.h>

static bool    encoder_button_state = false;

void keyboard_pre_init_user(void) {
    // Enable pull-ups for the encoder pins
    setPinInputHigh(F6);
    setPinInputHigh(F5);
    setPinInputHigh(F4);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

bool encoder_button_update_user(uint8_t index, bool pressed) {
    if (pressed) {
        tap_code16(KC_MUTE);
    }
    return false;
}

void matrix_scan_user(void) {
    // Encoder push switch on F4 (active low with pull-up)
    bool pressed = !readPin(F4);
    if (pressed != encoder_button_state) {
        encoder_button_state = pressed;
        encoder_button_update_user(0, pressed);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │K00│K01│K02│K03│   │
     * ├───┼───┼───┼───┼───┤
     * │K10│K11│K12│K13│K14│
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_KP_1, KC_KP_2,   KC_KP_3,   KC_KP_4,
        KC_KP_5, KC_KP_6,   KC_KP_7,   KC_KP_8
    )
};

