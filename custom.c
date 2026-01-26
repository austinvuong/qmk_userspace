#include "quantum.h"

// The tap key KC_. will get replaced by REPEAT
#define LT_REP_2 LT(2, KC_2)
#define LT_REP_3 LT(3, KC_3)

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case LT_REP_2:
        case LT_REP_3:
        case KC_BSPC:
        case KC_DEL:
        case KC_ENT:
        case KC_TAB:
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_REP_2:
        case LT_REP_3:
            if (record->tap.count) {               // On tap.
                repeat_key_invoke(&record->event); // Repeat the last key.
                return false;                      // Skip default handling.
            }
            break;

            // Other macros...
    }
    return true; // Continue default handling.
}
