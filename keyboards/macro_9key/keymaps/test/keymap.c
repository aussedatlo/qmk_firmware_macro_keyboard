/*
Copyright 2024 Custom

Test keymap for verifying all keys work correctly.
Each key outputs a unique letter (A-I) for easy identification.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Test Layout - Each key outputs a unique letter
     * ┌───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │   │
     * ├───┼───┼───┼───┼───┤
     * │ E │ F │ G │ H │ I │
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_A,    KC_B,    KC_C,    KC_D,    /* Row 0: K00=A, K01=B, K02=C, K03=D */
        KC_E,    KC_F,    KC_G,    KC_H,    KC_I  /* Row 1: K10=E, K11=F, K12=G, K13=H, K14=I */
    )
};


