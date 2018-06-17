/*
 * Keyboard: Atreus
 * Keymap:   replicaJunction
 * Version:  0.4
 *
 * This keymap is designed to complement my Ergodox keyboard layout, found in keyboards/ergodox_ez.
 * The Atreus keyboard is a 40% board whose design was heavily influenced by the Ergodox. I now
 * have both keyboards, so I've designed these layouts in an effort to make switching between the
 * two as easy as possible.
 *
 * Clearly, the Atreus is the limiting factor in this equation, so I've taken heavy advantage of
 * function and dual-role keys.
 *
 * The default key layout in this keymap is Colemak-ModDH. Information on that layout can be found
 * here: https://colemakmods.github.io/mod-dh/
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Note that whatever is set as layer 0 will be the default layer of the keyboard.

#define _CO 0 // Colemak
#define _EX 1 // Extend
#define _NU 2 // Numpad
#define _FN 3 // Function

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS
#define KCX_CA  LCTL(KC_LALT)
#define KCX_CS  LCTL(KC_LSFT)
#define KCX_CSA LCTL(LSFT(KC_LALT))
#define KCX_LST LSFT(KC_TAB)
#define KX_COPY LGUI(KC_C)
#define KX_CUT  LGUI(KC_X)
#define KX_PAST LGUI(KC_V)
#define KX_UNDO LGUI(KC_Z)

#define _USER 0 // User macro

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Colemak
   *
   * ,----------------------------------.                     ,----------------------------------.
   * |   Q  |   W  |   F  |   P  |   G  |                     |   J  |   L  |   U  |   Y  |   ;  |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |   A  |   R  |   S  |   T  |   D  |                     |   H  |   N  |   E  |   I  |   O  |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |Z Shft|   X  |   C  |   V  |   B  | ,------.   ,------. |   K  |   M  |   ,  |   .  |/ Shft|
   * +------+------+------+------+------| | Ctrl |   |  Alt | +------+------+------+------+------|
   * |  Esc |  Tab |  Gui | _FN  | Bksp | |      |   |      | |Sp/_NU|Ent/_EX|  -  |   '  |   =  |
   * `----------------------------------' `------'   `------' `----------------------------------'
   *
   */
  [_CO] = LAYOUT(
    KC_Q,        KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,            KC_L,            KC_U,    KC_Y,    KC_SCLN,
    KC_A,        KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,            KC_N,            KC_E,    KC_I,    KC_O,
    SFT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,            KC_M,            KC_COMM, KC_DOT,  SFT_T(KC_SLSH),
    KC_ESC,      KC_TAB,  KC_LGUI, MO(_FN), KC_BSPC, KC_LCTL, KC_LALT, LT(_NU, KC_SPC), LT(_EX, KC_ENT), KC_MINS, KC_QUOT, KC_EQL
  ),

  /*
   * Extend
   *
   * Ctrl+` is a keyboard shortcut for the program ConEmu, which brings up a dropdown console window.
   *
   * Also note that some dual-role keys are overridden here with their modifiers
   *
   * ,----------------------------------.                     ,----------------------------------.
   * |      |      |      |      |Ctrl `|                     | PgUp | Home |   Up |  End |  Del |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |  Tab | Shift|  Alt | Ctrl |      |                     | PgDn | Left | Down | Right| Bksp |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * | Shift|  Cut | Copy |      | Paste| ,------.   ,------. |      | ^Tab |  Tab |      |Insert|
   * +------+------+------+------+------| |  Del |   | Enter| +------+------+------+------+------|
   * |      |      |      |      |      | |      |   |      | | Space|XXXXXX|      |      |PrntSc|
   * `----------------------------------' `------'   `------' `----------------------------------'
   *
   */
  [_EX] = LAYOUT( /* Extend */
    _______, _______, _______, _______, LCTL(KC_GRV),              KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,
     KC_TAB, KC_LSFT, KC_LALT, KC_LCTL, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
    KC_LSFT, KX_CUT,  KX_COPY, _______, KX_PAST,                   _______, KCX_LST, KC_TAB,  _______, KC_INS,
    _______, _______, _______, _______, _______, KC_DEL,  KC_ENT,  KC_SPC,  _______, _______, _______, KC_PSCR
  ),

  /*
   * Numbers and symbols
   *
   * ,----------------------------------.                     ,----------------------------------.
   * |   !  |   @  |   {  |   }  |   &  |                     |   /  |   7  |   8  |   9  |   *  |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |   #  |   $  |   (  |   )  |   ~  |                     |   |  |   4  |   5  |   6  |   -  |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |   %  |   ^  |   [  |   ]  |   `  | ,------.   ,------. |   \  |   1  |   2  |   3  |   +  |
   * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
   * |      |      |      |      |      | |      |   |      | |XXXXXX|   0  |   0  |   .  |   =  |
   * `----------------------------------' `------'   `------' `----------------------------------'
   *
   */
  [_NU] = LAYOUT( /* Numbers and symbols */
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,                    KC_SLSH, KC_7,    KC_8,   KC_9,      KC_ASTR,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TILD,                    KC_PIPE, KC_4,    KC_5,   KC_6,      KC_MINS,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,                     KC_BSLS, KC_1,    KC_2,   KC_3,      KC_PLUS,
    _______, _______, _______, _______, _______, _______,  _______, _______, KC_0,    KC_0,   KC_DOT,    KC_EQL
  ),

  /*
   * Functions
   *
   * ,----------------------------------.                     ,----------------------------------.
   * | Caps |  F9  |  F10 |  F11 |  F12 |                     | _USER|Whl Up|  MUp |Whl Dn|      |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |      |  F5  |  F6  |  F7  |  F8  |                     | Vol ^| MLeft| MDown|MRight|      |
   * +------+------+------+------+------|                     +------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  | ,------.   ,------. | Vol v|LClick|MClick|RClick|      |
   * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
   * |      |      |      |XXXXXX|      | |      |   |      | | _CO  | _DH  | _QW  |      | RESET|
   * `----------------------------------' `------'   `------' `----------------------------------'
   *
   */
  [_FN] = LAYOUT( /* Functions */
    KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,                    M(_USER),KC_WH_U, KC_MS_U, KC_WH_D, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,                     KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,                     KC_VOLD, KC_BTN1, KC_BTN3, KC_BTN2, _______,
    _______, _______, _______, _______, _______, _______, _______, DF(_CO), _______, _______, _______, RESET
  )
};

/*
 * Template
 *
 * ,----------------------------------.                     ,----------------------------------.
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      |                     |      |      |      |      |      |
 * +------+------+------+------+------|                     +------+------+------+------+------|
 * |      |      |      |      |      | ,------.   ,------. |      |      |      |      |      |
 * +------+------+------+------+------| |      |   |      | +------+------+------+------+------|
 * |      |      |      |      |      | |      |   |      | |      |      |      |      |      |
 * `----------------------------------' `------'   `------' `----------------------------------'
 *
 */

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case _USER:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
