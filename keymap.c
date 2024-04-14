#include QMK_KEYBOARD_H
enum my_keycodes {
    selLine = SAFE_RANGE,
    selWord,
    copyLine,
    copyWord,
    copyAll,
    delWord,
    del2Home,
    del2End,
    delAll,
    winResize,
    winMove,
    ang,
    cbr,
    prn,
    brc
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case selLine:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END) SS_DELAY(6) SS_LSFT(SS_TAP(X_HOME)));
            }
            return true;
        case selWord:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(6) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
            } 
            return true;
        case copyLine:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END) SS_DELAY(6) SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(6) SS_LCTL(SS_TAP(X_C)) SS_DELAY(6) SS_TAP(X_RGHT));
            }
            return true;
        case copyWord:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(6) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(6) SS_LCTL(SS_TAP(X_C)) SS_DELAY(6) SS_TAP(X_RGHT));
            } 
            return true;
        case copyAll:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(6) SS_LCTL(SS_TAP(X_C)) SS_DELAY(6) SS_TAP(X_RGHT));
            } 
            return true;
        case delWord:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_DELAY(6) SS_LCTL(SS_TAP(X_BSPC)));
            }
            return true;
        case del2Home:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(6) SS_TAP(X_BSPC));
            }
            return true;
        case del2End:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(6) SS_TAP(X_BSPC));
            }
            return true;
        case delAll:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(8) SS_TAP(X_BSPC));
            }
            return true;
        case winResize:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(6) SS_TAP(X_SPC) SS_DELAY(8) SS_TAP(X_S) SS_DELAY(6) SS_UP(X_LALT) SS_DELAY(8) SS_TAP(X_DOWN) SS_DELAY(6) SS_TAP(X_RGHT));
            }
            return true;
        case winMove:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(6) SS_TAP(X_SPC) SS_DELAY(8) SS_TAP(X_M) SS_DELAY(6) SS_UP(X_LALT) SS_DELAY(8) SS_TAP(X_UP));
            }
            return true;
        case ang:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_COMM)) SS_DELAY(6) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(6) SS_TAP(X_LEFT));
            }
            return true;
        case cbr:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_LBRC)) SS_DELAY(6) SS_LSFT(SS_TAP(X_RBRC)) SS_DELAY(6) SS_TAP(X_LEFT));
            }
            return true;
        case prn:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(6) SS_LSFT(SS_TAP(X_0)) SS_DELAY(6) SS_TAP(X_LEFT));
            }
            return true;
        case brc:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(6) SS_TAP(X_RBRC) SS_DELAY(6) SS_TAP(X_LEFT));
            }
            return true;
        case LT(3,KC_F13):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z));
                return false;
            }
            return true;
        case LT(4,KC_F14):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Y));
                return false;
            }
            return true;
        case LT(2,KC_F15):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                return false;
            }
            return true;
    }
    return true;
};

const uint16_t PROGMEM combWinup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combNewtab[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combLefttab[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combRghttab[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combWindown[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combClosetab[] = {KC_X, LGUI_T(KC_C), COMBO_END};
const uint16_t PROGMEM combUplevel[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combWinclose[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combBack[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combForward[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combF5[] = {RGUI_T(KC_N), KC_M, COMBO_END};
const uint16_t PROGMEM combDesktop[] = {KC_M, KC_CAPS, COMBO_END};
combo_t key_combos[] = {
    COMBO(combWinup, G(KC_UP)),
    COMBO(combNewtab, C(KC_T)), 
    COMBO(combLefttab, C(S(KC_TAB))), 
    COMBO(combRghttab, C(KC_TAB)), 
    COMBO(combWindown, G(KC_DOWN)), 
    COMBO(combClosetab, C(KC_W)), 
    COMBO(combUplevel, A(KC_UP)), 
    COMBO(combWinclose, A(KC_F4)), 
    COMBO(combBack, A(KC_LEFT)), 
    COMBO(combForward, A(KC_RGHT)), 
    COMBO(combF5, KC_F5), 
    COMBO(combDesktop, G(KC_D)), 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_LSFT, KC_Q,    KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN, KC_ENT,
        KC_PSCR, KC_Y,    KC_Z,         KC_X,         LGUI_T(KC_C), KC_V,   KC_B,   RGUI_T(KC_N), KC_M,         KC_CAPS,      KC_MPRV, KC_MNXT,
        KC_SPC,  KC_LALT, KC_LCTL,      LT(1,KC_ESC), LT(2,KC_TAB), KC_NO,  KC_SPC, LT(3,KC_2),   LT(4,KC_3),   KC_MPLY,      KC_VOLD, KC_VOLU
    ),
    [1] = LAYOUT(
        KC_WH_U, KC_BTN2, A(KC_LEFT), KC_MS_U,   A(KC_RGHT), G(KC_UP),   LSG(KC_UP), KC_WH_L,       KC_WH_U,       KC_WH_R, A(KC_UP),   KC_NO,
        KC_WH_D, KC_BTN1, KC_MS_L,    KC_MS_D,   KC_MS_R,    G(KC_LEFT), G(KC_RGHT), KC_BTN1,       KC_WH_D,       KC_BTN2, A(KC_LEFT), KC_NO,
        KC_NO,   KC_BTN3, KC_ESC,     winResize, winMove,    G(KC_DOWN), A(KC_F4),   KC_BTN3,       KC_ACL0,       KC_ACL2, A(KC_RGHT), KC_NO,
        KC_NO,   KC_NO,   KC_NO,      KC_NO,     KC_NO,      KC_NO,      S(KC_ENT),  G(C(KC_LEFT)), G(C(KC_RGHT)), KC_NO,   KC_NO,      KC_NO
    ),
    [2] = LAYOUT(
        KC_NO, KC_PGUP,  KC_HOME,    KC_UP,      KC_END,     S(KC_UP),   selLine,    del2Home,     copyLine,     del2End, KC_PAUS, KC_NO,
        KC_NO, KC_PGDN,  KC_LEFT,    KC_DOWN,    KC_RGHT,    S(KC_LEFT), S(KC_RGHT), KC_BSPC,      KC_DEL,       delAll,  KC_INS,  KC_NO,
        KC_NO, C(KC_UP), C(KC_DOWN), C(KC_LEFT), C(KC_RGHT), S(KC_DOWN), selWord,    delWord,      copyWord,     copyAll, KC_SCRL, KC_NO,
        KC_NO, KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_ENT,     LT(3,KC_F13), LT(4,KC_F14), KC_NO,   KC_NO,   KC_NO
    ),
    [3] = LAYOUT(
        KC_TILD, KC_SLSH, KC_ASTR, KC_MINS,       KC_PLUS,      ang,     cbr,       KC_1,  KC_2,  KC_3,  KC_HASH, KC_GRV,
        KC_CIRC, KC_UNDS, KC_BSLS, KC_COMM,       KC_DOT,       KC_EQL,  prn,       KC_4,  KC_5,  KC_6,  KC_0,    KC_AT,
        KC_AMPR, KC_PIPE, KC_EXLM, KC_QUES,       KC_SCLN,      KC_COLN, brc,       KC_7,  KC_8,  KC_9,  KC_PERC, KC_DLR,
        KC_NO,   KC_NO,   KC_NO,   LT(1,KC_QUOT), LT(2,KC_F15), KC_NO,   C(KC_ENT), KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO
    ),
    [4] = LAYOUT(
        KC_F1, KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
        KC_NO, MEH(KC_A), MEH(KC_S), MEH(KC_D), MEH(KC_F), MEH(KC_G), MEH(KC_H), MEH(KC_J), MEH(KC_K), MEH(KC_L), MEH(KC_T), KC_NO,
        KC_NO, MEH(KC_Y), MEH(KC_Z), MEH(KC_X), MEH(KC_C), MEH(KC_V), MEH(KC_B), MEH(KC_N), MEH(KC_M), MEH(KC_E), MEH(KC_R), KC_NO,
        KC_NO, KC_NO,     KC_NO,     MEH(KC_Q), MEH(KC_W), KC_NO,     A(KC_ENT), KC_NO,     KC_NO,     KC_NO,     QK_BOOT,   KC_NO
    )
};