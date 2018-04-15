#include "preonic.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
# include "audio.h"
#endif
#ifdef STENO_ENABLE
# include "keymap_steno.h"
#endif

#ifdef MIDI_ENABLE
# define PLOVER_MIDI
#endif

#ifdef STENO_ENABLE
# define PLOVER_GEMINI
# define PLOVER_TXBOLT
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum _layers {
    _QWERTY,
    _QWERTY_BP,
#ifdef PLOVER_MIDI
    _PLOVER_MIDI,
#endif
#ifdef PLOVER_GEMINI
    _PLOVER_GEMINI,
#endif
#ifdef PLOVER_TXBOLT
    _PLOVER_TXBOLT,
#endif
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum _keycodes {
    QWERTY = SAFE_RANGE,
    QWERTBP,
    PLVRMID,
    PLVRGEM,
    PLVRTX,
    LOWER,
    RAISE,
    ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  =   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Lower| Ctrl | GUI  | Alt  |Space | Esc  | Enter| Space|  Alt |   [  |   ]  | Bksp |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = {
        {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL },
        {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
        {LOWER,   KC_RCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_ESC,  KC_ENT,  KC_SPC,  KC_RALT, KC_LBRC, KC_RBRC, KC_BSPC}
    },

    [_QWERTY_BP] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, RAISE  , _______, _______, _______, _______, _______, _______, _______, _______}
    },

#ifdef PLOVER_MIDI
    [_PLOVER_MIDI] = {
        {_______, MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    , MI_D_3    },
        {_______, MI_E_3    , MI_F_3    , MI_G_3    , MI_A_3    , MI_D_4    , MI_D_4    , MI_Fs_4   , MI_Gs_4   , MI_As_4   , MI_C_5    , MI_D_5    },
        {_______, MI_E_3    , MI_Fs_3   , MI_Gs_3   , MI_As_3   , MI_D_4    , MI_D_4    , MI_G_4    , MI_A_4    , MI_B_4    , MI_Cs_5   , MI_Ds_5   },
        {_______, XXXXXXX   , XXXXXXX   , MI_B_3    , MI_C_4    , XXXXXXX   , XXXXXXX   , MI_E_4    , MI_F_4    , XXXXXXX   , XXXXXXX   , XXXXXXX   },
        {_______, _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   }
    },
#endif

#ifdef PLOVER_GEMINI
    [_PLOVER_GEMINI] = {
        {_______, STN_N1    , STN_N2    , STN_N3    , STN_N4    , STN_N5    , STN_N6    , STN_N7    , STN_N8    , STN_N9    , STN_NA    , STN_NB    },
        {_______, STN_S1    , STN_TL    , STN_PL    , STN_HL    , STN_ST1   , STN_ST3   , STN_FR    , STN_PR    , STN_LR    , STN_TR    , STN_DR    },
        {_______, STN_S2    , STN_KL    , STN_WL    , STN_RL    , STN_ST2   , STN_ST4   , STN_RR    , STN_BR    , STN_GR    , STN_SR    , STN_ZR    },
        {_______, XXXXXXX   , XXXXXXX   , STN_A     , STN_O     , XXXXXXX   , XXXXXXX   , STN_E     , STN_U     , XXXXXXX   , XXXXXXX   , XXXXXXX   },
        {_______, _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   }
    },
#endif

#ifdef PLOVER_TXBOLT
    [_PLOVER_TXBOLT] = {
        {_______, STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   , STN_NUM   },
        {_______, STN_SL    , STN_TL    , STN_PL    , STN_HL    , STN_STR   , STN_STR   , STN_FR    , STN_PR    , STN_LR    , STN_TR    , STN_DR    },
        {_______, STN_SL    , STN_KL    , STN_WL    , STN_RL    , STN_STR   , STN_STR   , STN_RR    , STN_BR    , STN_GR    , STN_SR    , STN_ZR    },
        {_______, XXXXXXX   , XXXXXXX   , STN_A     , STN_O     , XXXXXXX   , XXXXXXX   , STN_E     , STN_U     , XXXXXXX   , XXXXXXX   , XXXXXXX   },
        {_______, _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   }
    },
#endif

    [_LOWER] = {
        {RESET  , _______, _______, _______, _______, _______, _______, QWERTY , QWERTBP, PLVRMID, PLVRGEM, PLVRTX },
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, KC_WH_U, _______},
        {_______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______},
        {_______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______}
    },

    [_RAISE] = {
        {_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 },
        {_______, KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_F12 },
        {_______, KC_PDOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_MENU, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
        {_______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, _______, _______, _______, _______, KC_BSLS, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },

    [_ADJUST] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },

};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
    {NOTE_B5, 20},
    {NOTE_B6, 8},
    {NOTE_DS6, 20},
    {NOTE_B6, 8}
};

float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_plover[][2] = SONG(PLOVER_SOUND);
float tone_midi[][2] = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(tone_qwerty);
#endif
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    case QWERTBP:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(tone_qwerty);
#endif
            set_single_persistent_default_layer(_QWERTY_BP);
        }
        return false;
    case PLVRGEM:
#ifdef PLOVER_GEMINI
        if (record->event.pressed) {
# ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(tone_plover);
# endif
            steno_set_mode(STENO_MODE_GEMINI);
            set_single_persistent_default_layer(_PLOVER_GEMINI);
        }
#endif
        return false;
    case PLVRTX:
#ifdef PLOVER_TXBOLT
        if (record->event.pressed) {
# ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(tone_plover);
# endif
            steno_set_mode(STENO_MODE_BOLT);
            set_single_persistent_default_layer(_PLOVER_TXBOLT);
        }
#endif
        return false;
    case PLVRMID:
#ifdef PLOVER_MIDI
        if (record->event.pressed) {
# ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(tone_plover);
# endif
            set_single_persistent_default_layer(_PLOVER_MIDI);
        }
#endif
        return false;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
    }
    return true;
};

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
