#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

enum layers {
    _BEPO,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define TABLO LT(_LOWER, KC_TAB)
#define ENTRA LT(_RAISE, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BEPO
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  B   |  W   |  P   |  O   |  ’   |           |  ^   |  V   |  D   |  L   |  J   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  A   |  U   |  I   |  E   |  ,   |           |  C   |  T   |  S   |  R   |  N   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/GUI| Y/Alt| X/Ctl| ./Sft|  K   |           |  M   | Q/Sft| G/Ctl| H/Alt| F/GUI|
 * `----------------------------------'           `----------------------------------'
 *                  ,------.------.------.    ,------,------.------.
 *                  | Del  |  Tab |      |    |      |Enter |Escape|
 *                  |      | LOWER| Space|    |BckSpc|RAISE |      |
 *                  `------'------|      |    |      |------'------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_BEPO] = LAYOUT(
_______,  BP_B,        BP_W,        BP_P,          BP_O,  BP_QUOT,         BP_DCIR, BP_V ,       BP_D,        BP_L,        BP_J,    _______,
_______,  BP_A,        BP_U,        BP_I,          BP_E,  BP_COMM,         BP_C,    BP_T,        BP_S,        BP_R,        BP_N,    _______,
_______,LGUI_T(BP_Z), ALT_T(BP_Y), CTL_T(BP_X), SFT_T(BP_DOT),     BP_K,         BP_M,    SFT_T(BP_Q), CTL_T(BP_G), ALT_T(BP_H), LGUI_T(BP_F),  _______,
                          KC_DEL,         TABLO,   KC_SPC,         KC_BSPC, ENTRA      , KC_ESC
),

/* Lower.
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   |  |   É  |   &  |   œ  |   È  |           | PgUp | Home |  Up  |  End |ScrlUp|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   æ  |   Ù  |   ¨  |   €  |   $  |           | PgDn | Left | Down | Right|ScrlDn|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   À  |  Alt |  Ctl | Shift|   Ç  |           |      | Shift|  Ctl |  Alt |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,------,------,------.    ,------,------,------.
 *                  |      |      |      |    |      |      |      |
 *                  `------'------|      |    |      |------'------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT(
_______, ALGR(BP_B), BP_EACU,    ALGR(BP_P), ALGR(BP_O),    BP_EGRV,        KC_PGUP,   KC_HOME, KC_UP,   KC_END,   KC_MS_WH_UP,  _______,
_______, ALGR(BP_A), ALGR(BP_U), ALGR(BP_I), ALGR(BP_E),     BP_DLR,        KC_PGDN,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_MS_WH_DOWN,  _______,
_______, BP_AGRV,    KC_LALT,    KC_LCTL,    KC_LSFT,    BP_CCED,        _______,   KC_LSFT, KC_LCTL, KC_LALT,  _______,  _______,
                             _______,    _______,    _______,        _______,   _______, _______
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   "  |   <  |   >  |   (  |   )  |           |   @  |   +  |   -  |   /  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  |   {  |   }  |   [  |   ]  |           |   ~  |   =  |   %  |   \  |   #  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   |  |  Alt |  Ctl | Shift|   '  |           |      | Shift|  Ctl |  Alt |   &  |
 * `----------------------------------'           `----------------------------------'
 *                  ,------,------,------.    ,------,------,------.
 *                  |      |      |      |    |      |      |      |
 *                  `------'------|  _   |    |      |------'------'
 *                                |      |    |      |
 *                                `------'     `------'
 */
[_RAISE] = LAYOUT(
_______,  BP_DQUO, ALGR(BP_LDAQ), ALGR(BP_RDAQ),       BP_LPRN,       BP_RPRN,        BP_AT,      BP_PLUS,    BP_MINS,     BP_SLSH,  BP_ASTR,  _______,
_______, S(BP_PERC),       ALGR(BP_Y),    ALGR(BP_X), ALGR(BP_LPRN), ALGR(BP_RPRN),        ALGR(BP_K), BP_EQL,     BP_PERC,     ALGR(BP_AGRV), S(BP_DLR),  _______,
_______, ALGR(BP_B),       KC_LALT,       KC_LCTL,       KC_LSFT, ALGR(BP_COMM),        _______,    KC_LSFT,    KC_LCTL,     KC_LALT,    ALGR(BP_P),  _______,
                                      _______,       _______,  ALGR(KC_SPC),        _______,    _______,    _______
),

/* Adjust (Lower + Raise)
 * (GUI, ALT, Ctrl, Shft ONLY on left-hand home row)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  Alt |  Ctl | Shift|      |           |      | Shift|  Ctl |  Alt |  F12 |
 * `----------------------------------'           `----------------------------------'
 *                  ,------,------,------.    ,------,------,------.
 *                  |      |      |      |    |      |      |      |
 *                  `------'------|      |    |      |------'------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] = LAYOUT(
_______,  KC_F1,           KC_F2,      KC_F3,      KC_F4,      KC_F5,        KC_F6,    KC_F7,      KC_F8,       KC_F9,       KC_F10,  _______,
_______,  S(BP_DQUO), S(BP_LDAQ), S(BP_RDAQ), S(BP_LPRN), S(BP_RPRN),        S(BP_AT), S(BP_PLUS), S(BP_MINS),  S(BP_SLSH),  S(BP_ASTR),  _______,
_______,  KC_F11,        KC_LALT,    KC_LCTL,    KC_LSFT,    _______,        _______,  KC_LSFT,    KC_LCTL,     KC_LALT,     KC_F12,  _______,
                             _______,    _______,    _______,        _______,  _______,    _______
)
};

/*layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}*/


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE