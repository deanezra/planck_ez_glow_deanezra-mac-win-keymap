// TODOS:
// 1. Add macro to Adjust layer to W = Default layer = WBASE, M = Default layer = BASE - DF(0) of set_persistent_layer()
// 2. Replace the WORYX P macro with a Windows one for £ symbol (USA International = Right Alt + Shift + 4)
// 3. Replace thw WORYX A macro with Windows one for @ (May not be needed) - Shift +2
// 4. Any other mac specific keys that done work on Windows? Home and End?

#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
//#include "keymap_german.h"
//#include "keymap_nordic.h"
//#include "keymap_french.h"
//#include "keymap_spanish.h"
//#include "keymap_hungarian.h"
//#include "keymap_swedish.h"
//#include "keymap_br_abnt2.h"
//#include "keymap_canadian_multilingual.h"
//#include "keymap_german_ch.h"
//#include "keymap_jp.h"
//#include "keymap_korean.h"
//#include "keymap_bepo.h"
//#include "keymap_italian.h"
//#include "keymap_slovenian.h"
//#include "keymap_lithuanian_azerty.h"
//#include "keymap_danish.h"
//#include "keymap_norwegian.h"
//#include "keymap_portuguese.h"
//#include "keymap_contributions.h"
//#include "keymap_czech.h"
//#include "keymap_romanian.h"
//#include "keymap_russian.h"
#include "keymap_uk.h"
//#include "keymap_estonian.h"
//#include "keymap_belgian.h"
//#include "keymap_us_international.h"
//#include "keymap_croatian.h"
//#include "keymap_turkish_q.h"
//#include "keymap_slovak.h"

#include "sendstring_uk.h"

#include "print.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

// Apple Mac specific UK key codes:
#define KC_UK_MAC_PND LALT(KC_3)

// Key overrides:
const key_override_t single_quote_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, UK_DQUO);  // Shift ' is " (insteasd of @)
const key_override_t two_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_AT); // Shift 2 is @ instead of "

const key_override_t **key_overrides = (const key_override_t*[]){
    &single_quote_key_override,
    &two_key_override,
    NULL
};
// End Key overrides.


enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  WINDOWS_MODE,
  MAC_MODE,
};


// Note: To stop odd bugs, always keep Adjust last in list of layers.
enum planck_layers {
  _MBASE,
  _MLOWER,
  _MRAISE,
  _MORYX,
  _WBASE,
  _WLOWER,
  _WRAISE,
  _WORYX,
  _ADJUST,
};

// Mac specific layers:
#define MLOWER MO(_MLOWER)
#define MRAISE MO(_MRAISE)
#define MORYX MO(_MORYX)

// Windows specific layers:
#define WLOWER MO(_WLOWER)
#define WRAISE MO(_WRAISE)
#define WORYX MO(_WORYX)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MBASE] = LAYOUT_planck_grid(
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_QUOTE,       KC_SCOLON,
    MT(MOD_LSFT, KC_CAPSLOCK),KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_ENTER,
    MORYX,          KC_LCTRL,       KC_LALT,        KC_LGUI,        MLOWER,          KC_SPACE,       KC_NO,          MRAISE,          KC_SLASH,       KC_LEFT,        KC_DOWN,        KC_RIGHT
  ),

  [_MLOWER] = LAYOUT_planck_grid(
    UK_TILD,        KC_EXLM,        UK_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        KC_NO,          KC_TRANSPARENT, KC_BSLASH,      KC_HOME,        KC_PGDOWN,      KC_END
  ),

  [_MRAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_BSLASH,      KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    RESET,          KC_TRANSPARENT, WINDOWS_MODE,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_0,     KC_TRANSPARENT,
    KC_DELETE,      RGB_MOD,        AU_ON,          AU_OFF,         AU_TOG,         KC_TRANSPARENT, KC_HASH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, MAC_MODE,            KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAI,        RGB_TOG,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD,        RGB_VAD,        RGB_HUI
  ),

  [_MORYX] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UK_MAC_PND,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AT,          KC_TRANSPARENT, KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, UK_HASH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_WBASE] = LAYOUT_planck_grid(
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_QUOTE,       KC_SCOLON,
    MT(MOD_LSFT, KC_CAPSLOCK),KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_ENTER,
    WORYX,          KC_LCTRL,       KC_LALT,        KC_LGUI,        WLOWER,          KC_SPACE,       KC_NO,          WRAISE,          KC_SLASH,       KC_LEFT,        KC_DOWN,        KC_RIGHT
  ),

  [_WLOWER] = LAYOUT_planck_grid(
    UK_TILD,        KC_EXLM,        UK_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        KC_NO,          KC_TRANSPARENT, KC_BSLASH,      KC_HOME,        KC_PGDOWN,      KC_END
  ),

  [_WRAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_BSLASH,      KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_TRANSPARENT
  ),

  [_WORYX] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UK_PND,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AT,          KC_TRANSPARENT, KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, UK_HASH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WINDOWS_MODE:
    if (record->event.pressed) {
      print("Entering windows mode.");
      SEND_STRING("Entering Windows mode.");
      // Make default layer the make windows base layer, which will only move to windows layers.
      default_layer_set(1UL<<_WBASE);
    }
    break;
    case MAC_MODE:
    if (record->event.pressed) {
      print("Entering mac mode.");
      SEND_STRING("Entering Mac mode.");
      // Make default layer the mac base layer, which will only move to mac layers.
      default_layer_set(1UL<<_MBASE);
      // Could used the persistant_default_layer_set() that write to eeprom, but didnt want to wear out.

    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_3) ));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_MRAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case WRAISE:
    case WLOWER:
    case MRAISE:
    case MLOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    // In this function we make the Adjust layer work by checking if user has both the lower and raise layers active
    // (e.g. they are pressing lower and raise at same time), then goto adjust layer:

    // So standard QMK keymaps call the update_tri_layer_state() method, which is fine if we only goto adjust
    // with two layers being active at same time, however in this keymap, we have two versions of raise and two
    // of lower (one for each OS), so it cant be used.
    //return update_tri_layer_state(state, _MLOWER, _MRAISE, _ADJUST);

    // So the workaround is to check the two sets of layers active manually:
    if ( ( layer_state_cmp(state, _MLOWER) && layer_state_cmp(state, _MRAISE ) ) ||
         ( layer_state_cmp(state, _WLOWER) && layer_state_cmp(state, _WRAISE ) ) ) {
        return state | (1UL<<_ADJUST);
    } else {
        return state & ~(1UL<<_ADJUST);
    }

}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;

  // Lets default to Windows base layer by default on startup:
  default_layer_set(1UL<<_WBASE);
}


