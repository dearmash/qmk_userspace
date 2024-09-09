// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYMBOLS,
    _DIGITS,
    _MOVEMENT,
    _WINDOWS,
    _SHORTCUTS,
    _EMPTY,
    _BLOCKED,
};

#define _LSFT_A LSFT_T(KC_A)            // A is shift when held
#define _LSFTCN LSFT_T(KC_SCLN)         // ; is shift when held
#define _SMBL_S LT(_SYMBOLS, KC_S)      // S switches to _SYMBOLS when held
#define _DIGT_D LT(_DIGITS, KC_D)       // D switches to _DIGITS when held
#define _MOVE_F LT(_MOVEMENT, KC_F)     // F switches to _MOVEMENT when held
#define _GUIESC LGUI_T(KC_ESC)          // GUI is esc when tapped
#define _SHWIN  C(KC_UP)                // unused, extra button shows misson control
#define _SHCAT LSG(KC_SPC)              // extra button triggers Shortcat

#define _WIND_G MO(_WINDOWS)            // F-G swtiches to _WINDOWS when held
#define _SHOT_Q LT(_SHORTCUTS, KC_Q)    // Q switches to _SHORTCUTS when held
#define _WD_LFT LALT(KC_LEFT)           // F-J Move left one word at a time
#define _WD_DWN LALT(KC_DOWN)           // F-K Move down one block at a time
#define _WD_UP LALT(KC_UP)              // F-L Move up one block at a time
#define _WD_RGT LALT(KC_RGHT)           // F_; Move right one word at a time

#define _BST_MV (LSFT(KC_LALT))         // F-S BetterSnapTool move window
#define _BST_SZ (LSFT(KC_LGUI))         // F-D BetterSnapTool size window

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    _SHOT_Q, KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
    _LSFT_A, _SMBL_S, _DIGT_D, _MOVE_F, KC_G   ,                      KC_H   , KC_J   , KC_K   , KC_L   , _LSFTCN,
    KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_GRV ,    CW_TOGG, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
    KC_LCTL, KC_LALT, KC_TAB , KC_DEL , KC_BSPC, _GUIESC,    KC_ENT , KC_SPC , KC_MINS, _SHCAT , KC_BSLS, KC_QUOT
  ),
  [_SYMBOLS] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,                      XXXXXXX, S(KC_7), S(KC_8), S(KC_9), S(KC_0),
    XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                      KC_UNDS, S(KC_4), S(KC_5), S(KC_6), KC_PLUS,
    XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, S(KC_1), S(KC_2), S(KC_3), XXXXXXX,
    KC_LCTL, KC_LALT, KC_TAB , KC_DEL , KC_BSPC, _GUIESC,    KC_ENT , KC_SPC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_DIGITS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_7   , KC_8   , KC_9   , KC_0   ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_4   , KC_5   , KC_6   , KC_EQL ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX,
    KC_LCTL, KC_LALT, KC_TAB , KC_DEL , KC_BSPC, _GUIESC,    KC_ENT , KC_SPC , KC_0   , KC_DOT , XXXXXXX, XXXXXXX
  ),
  [_MOVEMENT] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, _WD_LFT, _WD_DWN, _WD_UP , _WD_RGT,
    KC_LSFT, _BST_MV, _BST_SZ, XXXXXXX, _WIND_G,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_INS , KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
    KC_LCTL, KC_LALT, KC_TAB , KC_DEL , KC_BSPC, _GUIESC,    KC_ENT , KC_SPC , XXXXXXX, XXXXXXX, KC_BSLS, KC_QUOT
  ),
  [_WINDOWS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, HYPR(KC_F1), HYPR(KC_F2) , HYPR(KC_F3) , HYPR(KC_F4) ,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                      XXXXXXX, HYPR(KC_F5), HYPR(KC_F6) , HYPR(KC_F7) , HYPR(KC_F8) ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, HYPR(KC_F9), HYPR(KC_F10), HYPR(KC_F11), HYPR(KC_F12),
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX    , XXXXXXX     , XXXXXXX     , XXXXXXX
  ),
  [_SHORTCUTS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, LSG(KC_E), LSG(KC_H),                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX  ,                      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX  , XXXXXXX,    XXXXXXX, XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_LCTL, KC_LALT, KC_TAB , KC_DEL , KC_BSPC, _GUIESC,    KC_ENT , KC_SPC , XXXXXXX, XXXXXXX, KC_BSLS, KC_QUOT
  ),
  [_EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
  ),
  [_BLOCKED] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

