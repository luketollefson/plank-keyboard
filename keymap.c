// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RUSSIAN 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  RUSSIAN,
  LOWER,
  RAISE,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |Shirft| ALT  | GUI  |Space |Lower |Raise |Shift | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_CAPS, KC_LSFT, KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   ;  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   "  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | shift| ALT  | GUI  |Space |Lower |Raise |Shift | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LCTL, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_CAPS, KC_LSFT, KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Russian
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | shift| ALT  | GUI  |Space |Lower |Raise |Shift |   Х  |  Э   |  Ё   |  Ъ   |
 * `-----------------------------------------------------------------------------------'
 */
[_RUSSIAN] = {
  {KC_TAB, UC(0x041F), _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
  {KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS},
  {KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT },
  {KC_CAPS, KC_LSFT, KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_RSFT, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | print|SysReq|ScrLk | Pause|      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |   [  |  {   |   }  |   (  |   =  |   *  |   )  |   +  |   ]  |   !  |   #  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   /  |   @  |   \  |      |      |      |   $  |   &  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | End  | PgDn | PgUp | Home |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_PSCR,KC_SYSREQ,KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______},
  {KC_DEL,  KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH},
  {_______, _______, KC_SLSH, KC_AT,   KC_BSLS, _______, _______, _______, KC_DLR,  KC_AMPR, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_PGUP, KC_HOME}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ins  |   7  |   5  |   3  |   1  |   9  |   0  |   2  |   4  |   6  |   8  |   `  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   ?  |   ^  |   |  |      |      |   ~  |   %  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_INS,  KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_GRV },
  {_______, _______, M(0),    KC_CIRC, KC_PIPE, _______, _______, KC_TILD, KC_PERC, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise) function layout
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  Dim | Brigt|qwerty|dvorak|Vol Up|Vol Dn| Mute |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F5  |  F3  |  F1  |  F9  |  F10 |  F2  |  F4  |  F6  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F17 |  F15 |  F13 |  F11 |  F19 |  F20 |  F12 |  F14 |  F16 |  F18 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, _______, _______, RUSSIAN, QWERTY,  DVORAK,  KC_VOLU, KC_VOLD, KC__MUTE,_______, M(1)   },
  {_______, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   _______},
  {_______, KC_F17,  KC_F15,  KC_F13,  KC_F11,  KC_F19,  KC_F10,  KC_F12,  KC_F14,  KC_F16,  KC_F18,  _______},   ///Needs updating, brightness control
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  if (record->event.pressed) {
    switch(id) {
      case 0: 
        SEND_STRING("?");
        break;
    }
  }
  return MACRO_NONE;
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
	case RUSSIAN:
	  if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_RUSSIAN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
