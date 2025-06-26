// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_brazilian_abnt2.h"
// #include "sendstring_brazilian_abnt2.h"

//--------------------------------------------------------//
//                       DEFINITIONS                      //
//--------------------------------------------------------//

enum layers {
    _ALPHA_A = 0,
    _ALPHA_B,
    _GIMP,
    _NUMPAD,
    _SHORTCUTS,
    _SYMBOLS,
    _NAVVOL,
	_MACROS,
	_OTHERS,
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[9];
enum tap_dance_codes {
  DNC_CTRL_C,
  DNC_CTRL_V,
  DNC_CTRL_H,
  DNC_CTRL_F,
  DNC_CTRL_T,
  DNC_LIBOFF,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};

#define MY_CTL_C TD(DNC_CTRL_C)
#define MY_CTL_V TD(DNC_CTRL_V)
#define MY_CTL_H TD(DNC_CTRL_H)
#define MY_CTL_F TD(DNC_CTRL_F)
#define MY_CTL_T TD(DNC_CTRL_T)
#define MY_OFFCE TD(DNC_LIBOFF)
#define MY_SFTAB S(KC_TAB)
#define MY_NXTAB C(KC_TAB)
#define MY_PVTAB C(S(KC_TAB))
#define MY_E     LCTL_T(KC_E)
#define MY_A     LSFT_T(KC_A)
#define MY_O     C_S_T(KC_O)
#define MY_I     LSFT_T(KC_I)
#define MY_T     LCTL_T(KC_T)
#define MY_RETRN TO(_ALPHA_A)

#define THUMB_L4 KC_BSPC
#define THUMB_L3 LT(_ALPHA_B, KC_BSPC)
#define THUMB_L2 LT(_SHORTCUTS, KC_BSPC)
#define THUMB_L1 TG(_NUMPAD)
#define THUMB_LA RM_TOGG
#define THUMB_LB TG(_GIMP)
#define THUMB_RB MS_BTN1
#define THUMB_RA MS_BTN2
#define THUMB_R1 KC_ENTER
#define THUMB_R2 OSL(_SYMBOLS)
#define THUMB_R3 LT(_NAVVOL, KC_SPACE)
#define THUMB_R4 TG(_NAVVOL)

#define THM_L2nv LT(_SHORTCUTS, KC_DEL)
#define THM_R3nm LT(_NAVVOL, KC_0)

#define DF_F5_F2 LT(8, KC_F5)
#define DF_HOME  LT(8, KC_HOME)
#define DF_END   LT(8, KC_END)
#define MY_R     LT(8, KC_R)
#define MY_S     LT(8, KC_S)
#define MY_L     LT(8, KC_L)

enum custom_keycodes {
	MC_3DOTS = SAFE_RANGE,
	MC_CAO,
	MC_COES,
	MC_RS,
	MC_E,
	MC_ING,
	MC_GHT,
	MC_PX,
	MC_QU,
	MC_TH,
	MC_Agrve,
	MC_2parntes,
	MC_2brackts,
	MC_2crlbrks,
	MC_2quotes,
	MC_cutey,
	MC_doubt,
	MC_link,
	MC_squez,
	MC_tired,
	MC_break,
	MC_sdeye,
	MC_astrs,
	MC_rqv,
	MC_nota,
};

//--------------------------------------------------------//
//                         LAYERS                         //
//--------------------------------------------------------//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	 * Alpha A: Base layer
	 *
	 * ,----------------------------------------------------------.                                   ,----------------------------------------------------.
	 * |  Ctl+C* | Ctl+V* |  F5/F2  |   Esc   |   Del   | Ctl+Bsp |                                   |    <    |   (   |   [   |   {   |   *   |   Alt    |
	 * |---------+--------+---------+---------+---------+---------|                                   |---------+-------+-------+-------+-------+----------|
	 * |  Ctl+Z  |  ' "   |    £    |    H    |    G    |    K    |                                   |    Y    |  R/´  |  S/^  |  L/~  |   W   |  AltGr   |
	 * |---------+--------+---------+---------+---------+---------|                                   |---------+-------+-------+-------+-------+----------|
	 * | Alt+Tab |   P    | Ct+Sh/O |  Ctl/E  |  Sft/A  |    §    |                                   |    B    | Sft/I | Ctl/T |   N   |   C   |   - _    |
	 * |---------+--------+---------+---------+---------+---------+----------------.  ,---------------+---------+-------+-------+-------+-------+----------|
	 * |   Tab   | ______ |    J    |    Q    |    U    |    X    |   RGB   |  L2  |  | Click | RClck |    V    |   M   |   D   |   F   |   Z   | Menu/GUI |
	 * `----------------------------+---------+---------+---------+---------+------|  |-------+-------+---------+-------+-------+--------------------------'
	 *                              | _______ |  Bksp   | L1/Bksp | L4/Bksp |  L3  |  | Enter |  L5   | L6/Space|  L6   | _____ |
	 *                              `----------------------------------------------'  `-----------------------------------------'
	 * ,-----------------------------------.                                                                           ,-----------------------------------.
	 * | Mute |      |       |      |      |                                                                           |      |      |       |      |      |
	 * `-----------------------------------'                                                                           `-----------------------------------'
	 */
    [_ALPHA_A] = LAYOUT_elora_hlc(
		MY_CTL_C, MY_CTL_V, DF_F5_F2, KC_ESC  , KC_DEL  , C(KC_BSPC),                                       KC_LT   , KC_LPRN , BR_LBRC , BR_LCBR , KC_ASTR , KC_LALT,
		C(KC_Z) , BR_QUOT , BR_PND  , KC_H    , KC_G    , KC_K    ,                                         KC_Y    , MY_R    , MY_S    , MY_L    , KC_W    , KC_RALT,
		A(KC_TAB),KC_P    , MY_O    , MY_E    , MY_A    , BR_SECT ,                                         KC_B    , MY_I    , MY_T    , KC_N    , KC_C    , KC_MINUS,
		KC_TAB  , XXXXXXX , KC_J    , KC_Q    , KC_U    , KC_X    , THUMB_LA, THUMB_LB, THUMB_RB, THUMB_RA, KC_V    , KC_M    , KC_D    , KC_F    , KC_Z    , LGUI_T(KC_APP),
		                              XXXXXXX , THUMB_L4, THUMB_L3, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_R4, XXXXXXX ,
		KC_KB_MUTE,XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX ,                                                             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
	),

	/*
	 * Alpha B: Complement to base layer with hard to reach letters
	 *
	 * ,---------------------------------------.                              ,------------------------------------.
	 * |         |     |     |     |     |     |                              |     |     |     |      |     |     |
	 * |---------+-----+-----+-----+-----+-----|                              |-----+-----+-----+------+-----+-----|
	 * |         |     |     |     |     |     |                              |     |  C  |  K  |  X   |     |     |
	 * |---------+-----+-----+-----------+-----|                              |-----+-----+-----+------+-----+-----|
	 * | Sft+Tab |     |  Q  |  H  |  G  |     |                              | - _ | ing | ght |  Z   |  Ç  |     |
	 * |---------+-----+-----+-----+-----+-----+-------------.  ,-------------+-----+-----+-----+------+-----+-----|
	 * | Sft+Tab |     |     |     |     |     |      |      |  |      |      |     |     | ção | ções |     |     |
	 * `---------------------+-----+-----+-----+------+------|  |------+------+-----+-----+-----+------------------'
	 *                       |     |     |     |      |      |  |      |      |     |     |     |
	 *                       `-------------------------------'  `-------------------------------'
	 * ,-----------------------------------.                                   ,-----------------------------------.
	 * |      |      |       |      |      |                                   |      |      |       |      |      |
	 * `-----------------------------------'                                   `-----------------------------------'
	 */
	[_ALPHA_B] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , KC_C    , KC_K    , KC_X    , _______ , _______ ,
		MY_SFTAB, _______ , KC_Q    , KC_H    , KC_G    , _______ ,                                         KC_MINUS, MC_ING  , MC_GHT  , KC_Z    , BR_CCED , _______ ,
		MY_SFTAB, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , MC_CAO  , MC_COES , _______ , _______ ,
							_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * GIMP: Shortcuts for image software
	 *
	 * ,-------------------------------------------.                              ,-------------------------------------------.
	 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
	 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
	 *                        |      |      |      |      |      |  |      |      |      |      |      |
	 *                        `----------------------------------'  `----------------------------------'
	 * ,-----------------------------------.                                              ,-----------------------------------.
	 * |      |      |       |      |      |                                              |      |      |       |      |      |
	 * `-----------------------------------'                                              `-----------------------------------'
	 */
	[_GIMP] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
								      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * NumPad: All things numbers
	 *
	 * ,----------------------------------------------------------.                                     ,---------------------------------------------.
	 * | _______ | ______ | _______ | _______ |         |         |                                     |  _____  | ____  | ____  | ____  | ___ | ___ |
	 * |---------+--------+---------+---------+---------+---------|                                     |---------+-------+-------+-------+-----+-----|
	 * | _______ | ______ |         |   px    |  R$_    | _______ |                                     |    *    |   7   |   8   |   9   |  +  | ___ |
	 * |---------+--------+---------+---------+---------+---------|                                     |---------+-------+-------+-------+-----+-----|
	 * | _______ | ______ |    %    |    :    |    H    |   _e_   |                                     |    /    |   4   |   5   |   6   |  -  | ___ |
	 * |---------+--------+---------+---------+---------+---------+---------------.  ,------------------+---------+-------+-------+-------+-----+-----|
	 * | _______ |   K    |         |         |    X    | _______ | ______ | ____ |  | _____ | ________ |         |   1   |   2   |   3   |     | ___ |
	 * `----------------------------+---------+---------+---------+--------+------|  |-------+----------+---------+-------+-------+-------------------'
	 *                              | _______ |   ???   |   ???   | L4/Del |  ??  |  | Enter | L5/Enter | L6 / 0  | Space | _____ |
	 *                              `---------------------------------------------'  `--------------------------------------------'
	 * ,-----------------------------------.                                                                      ,-----------------------------------.
	 * | ____ | ____ | _____ | ____ | ____ |                                                                      | ____ | ____ | _____ | ____ | ____ |
	 * `-----------------------------------'                                                                      `-----------------------------------'
	 */
	[_NUMPAD] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , XXXXXXX , MC_PX   , MC_RS   , _______ ,                                         KC_PAST , KC_7    , KC_8    , KC_9    , KC_PPLS , _______ ,
		_______ , _______ , _______ , _______ , KC_H    , MC_E    ,                                         KC_PSLS , KC_4    , KC_5    , KC_6    , KC_PMNS , _______ ,
		_______ , KC_K    , XXXXXXX , XXXXXXX , KC_X    , _______ , _______ , _______ , _______ , _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX , _______ ,
								      _______ , _______ , _______ , THM_L2nv, _______ , _______ , _______ , THM_R3nm, KC_SPACE, _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * Shortcuts
	 *
	 * ,---------------------------------------------------.                              ,------------------------------------------------.
	 * |        |        |        |       |       |        |                              |      |   Ins   |       |       |       |       |
	 * |--------+--------+--------+-------+-------+--------|                              |------+---------+-------+-------+-------+-------|
	 * |        |        | Ctl+T* | Ctl+A | Ctl+W | Ctl+F4 |                              |      | Office* |       |       |       |       |
	 * |--------+--------+--------+-------+-------+--------|                              |------+---------+-------+-------+-------+-------|
	 * |        | Ctl+H* | Ctl+F* | Ctl+S | Ctl+Z | Ctl+Y  |                              |      |  Ctl+I  | Ctl+U | Ctl+/ |       |       |
	 * |--------+--------+--------+-------+-------+--------+-------------.  ,-------------+------+---------+-------+-------+-------+-------|
	 * |        |        |        |       |       |        |      |      |  |      |      |      |  Ctl+B  | Ctl+T | Ctl+8 | Ctl+9 | Ctl+0 |
	 * `--------------------------+-------+-------+--------+------+------|  |------+------+------+---------+-------+-----------------------'
	 *                            |       |       |        |      |      |  |      |      |      |         |       |
	 *                            `--------------------------------------'  `--------------------------------------'
	 * ,-----------------------------------.                                                           ,-----------------------------------.
	 * |      |      |       |      |      |                                                           |      |      |       |      |      |
	 * `-----------------------------------'                                                           `-----------------------------------'
	 */
	[_SHORTCUTS] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX ,                                         XXXXXXX , KC_INS  , _______ , _______ , _______ , _______ ,
		_______ , _______ , MY_CTL_T, C(KC_A) , C(KC_W) , A(KC_F4),                                         XXXXXXX , MY_OFFCE, _______ , _______ , XXXXXXX , _______ ,
		_______ , MY_CTL_H, MY_CTL_F, C(KC_S) , C(KC_Z) , C(KC_Y) ,                                         XXXXXXX , C(KC_I) , C(KC_U) ,C(BR_SLSH),XXXXXXX , XXXXXXX ,
		_______ , _______ , XXXXXXX , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , XXXXXXX , C(KC_B) , C(KC_T) , C(KC_8) , C(KC_9) , C(KC_0) ,
								      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * Symbols
	 *
	 * ,-------------------------------------------.                                ,-------------------------------------------.
	 * | ______ | ____ | ____ | ____ |      |      |                                |      |  ´   |  ^   |  ~   |      |        |
	 * |--------+------+------+------+------+------|                                |------+------+------+------+------+--------|
	 * | ______ |  "   |  º   |  ª   |  $   |      |                                |  °   |  _   |  #   |  @   |      |        |
	 * |--------+------+------+------+------+------|                                |------+------+------+------+------+--------|
	 * | ______ |  "   |  %   |  &   |  ;   |  |   |                                |  :   |  ?   |  !   |  /   |      |        |
	 * |--------+------+------+------+------+------+---------------.  ,-------------+------+------+------+------+------+--------|
	 * |        |      |      |      |  *   |      |        |      |  |      |      |      |  +   |  =   |  \   |      |        |
	 * `----------------------+------+------+------+--------+------|  |------+------+------+------+------+----------------------'
	 *                        |      |      |      | L4/Del |      |  |      |      |      |      |      |
	 *                        `------------------------------------'  `----------------------------------'
	 * ,-----------------------------------.                                                ,-----------------------------------.
	 * |      |      |       |      |      |                                                |      |      |       |      |      |
	 * `-----------------------------------'                                                `-----------------------------------'
	 */
	[_SYMBOLS] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX ,                                         XXXXXXX , BR_ACUT , BR_CIRC , BR_TILD , XXXXXXX , XXXXXXX ,
		_______ , BR_DQUO , BR_FORD , BR_MORD , KC_DLR  , XXXXXXX ,                                         BR_DEG  , KC_UNDS , KC_HASH , KC_AT   , XXXXXXX , XXXXXXX ,
		_______ , MC_Agrve, KC_PERC , KC_AMPR , BR_SCLN , BR_PIPE ,                                         BR_COLN , BR_QUES , KC_EXLM , BR_SLSH , XXXXXXX , XXXXXXX ,
		_______ , _______ , XXXXXXX , XXXXXXX , KC_ASTR , XXXXXXX , _______ , _______ , _______ , _______ , XXXXXXX , KC_PLUS , KC_EQUAL, BR_BSLS , XXXXXXX , XXXXXXX ,
								      _______ , _______ , _______ , THM_L2nv, _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * NavVol: Navigation keys and volume and music control
	 *
	 * ,-----------------------------------------------.                                ,--------------------------------------------.
	 * | ______ | ____ |      | ______ | ______ |      |                                |      |      | PGUP |       | Prev |  Next  |
	 * |--------+------+------+--------+--------+------|                                |------+------+------+-------+------+--------|
	 * | ______ | ____ |      | PrvTab | NxtTab |      |                                |      | HOME | PGDD |  END  |  K   |  Play  |
	 * |--------+------+------+--------+--------+------|                                |------+------+------+-------+------+--------|
	 * | ______ | ____ | ____ |  Ctrl  |  Shft  |      |                                |      | LEFT |  UP  | RIGHT |  M   |  Mute  |
	 * |--------+------+------+--------+--------+------+---------------.  ,-------------+------+------+------+-------+------+--------|
	 * | ______ | ____ |      | BrgtUp | BrgtDw |      | ______ | ____ |  | ____ | ____ |      |      | DOWN |       | VDwn |  VlUp  |
	 * `----------------------+--------+--------+------+--------+------|  |------+------+------+------+------+-----------------------'
	 *                        | ______ | ______ | ____ | L4/Del | ____ |  | ____ | ____ | ____ | ____ | ____ |
	 *                        `----------------------------------------'  `----------------------------------'
	 * ,-----------------------------------.                                                     ,-----------------------------------.
	 * |      |      |       |      |      |                                                     |      |      |       |      |      |
	 * `-----------------------------------'                                                     `-----------------------------------'
	 */
	[_NAVVOL] = LAYOUT_elora_hlc(
		_______ , _______ , XXXXXXX , _______ , _______ , XXXXXXX ,                                         XXXXXXX , XXXXXXX , KC_PGUP , XXXXXXX , KC_MPRV , KC_MNXT ,
		_______ , _______ , XXXXXXX , MY_PVTAB, MY_NXTAB, XXXXXXX ,                                         XXXXXXX , DF_HOME , KC_PGDN , DF_END  , KC_K    , KC_MPLY ,
		_______,_______,_______,OSM(MOD_LCTL),OSM(MOD_LSFT),XXXXXXX,                                        XXXXXXX , KC_LEFT , KC_UP   , KC_RIGHT, KC_M    , KC_MUTE ,
		_______ , _______ , XXXXXXX , KC_BRID , KC_BRIU , XXXXXXX , _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , KC_DOWN , XXXXXXX , KC_VOLD , KC_VOLU ,
								      _______ , _______ , _______ , THM_L2nv, _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * Macros
	 *
	 * ,-----------------------------------------.                              ,--------------------------------------------.
	 * |      |     |      |       |      |      |                              |     |      |       |       |      |        |
	 * |------+-----+------+-------+------+------|                              |-----+------+-------+-------+------+--------|
	 * |      |     |      | {{|}} | _=>_ |      |                              |     |  ^^  |  (?)  | []()  |      |        |
	 * |------+-----+------+-------+------+------|                              |-----+------+-------+-------+------+--------|
	 * |      |     | $(|) | $this |  ->  | \**  |                              | >~< | = =  | (...) | ,rqv  |      |        |
	 * |------+-----+------+-------+------+------+-------------.  ,-------------+-----+------+-------+-------+------+--------|
	 * | </|> | <|> |      |  \*   |  *\  |      |      |      |  |      |      |     |  ¬¬  |  *|*  | ,nota |      |        |
	 * `-------------------+-------+------+------+------+------|  |------+------+-----+------+-------+-----------------------'
	 *                     |       |      |      |      |      |  |      |      |     |      |       |
	 *                     `-----------------------------------'  `----------------------------------'
	 * ,-----------------------------------.                                             ,-----------------------------------.
	 * |      |      |       |      |      |                                             |      |      |       |      |      |
	 * `-----------------------------------'                                             `-----------------------------------'
	 */
	[_MACROS] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX ,                                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		_______ , _______ , XXXXXXX , _______ , _______ , XXXXXXX ,                                         XXXXXXX , MC_cutey, MC_doubt, MC_link , XXXXXXX , XXXXXXX ,
		_______ , XXXXXXX , _______ , _______ , _______ , _______ ,                                         MC_squez, MC_tired, MC_break, MC_rqv  , XXXXXXX , XXXXXXX ,
		_______ , _______ , XXXXXXX , _______ , _______ , XXXXXXX , _______ , _______ , _______ , _______ , XXXXXXX , MC_sdeye, MC_astrs, MC_nota , XXXXXXX , XXXXXXX ,
								      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

	/*
	 * Other functions
	 *
	 * ,------------------------------------------------.                              ,----------------------------------------------.
	 * |        |      |      |       |        |        |                              |      |       |       |       |       |       |
	 * |--------+------+------+-------+--------+--------|                              |------+-------+-------+-------+-------+-------|
	 * |        |      | Sat+ | Brgt+ |  Next  | Speed+ |                              |      |       |       |       |       |       |
	 * |--------+------+------+-------+--------+--------|                              |------+-------+-------+-------+-------+-------|
	 * |        |      | Sat- | Brgt- |  Prev  | Speed- |                              |      |       |       |       |       |       |
	 * |--------+------+------+-------+--------+--------+-------------.  ,-------------+------+-------+-------+-------+-------+-------|
	 * |        |      |      |       | On/Off |        |      |      |  |      |      |      |       |       |       |       |       |
	 * `----------------------+-------+--------+--------+------+------|  |------+------+------+-------+-------+-----------------------'
	 *                        |  L0   |  L0    |  L0    |  L0  |  L0  |  |  L0  |  L0  |  L0  |  L0   |  L0   |
	 *                        `---------------------------------------'  `------------------------------------'
	 * ,-----------------------------------.                                                      ,-----------------------------------.
	 * |      |      |       |      |      |                                                      |      |      |       |      |      |
	 * `-----------------------------------'                                                      `-----------------------------------'
	 */
	[_OTHERS] = LAYOUT_elora_hlc(
		_______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , RM_SATU , RM_VALU , RM_NEXT , RM_SPDU ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , RM_SATD , RM_VALD , RM_PREV , RM_SPDD ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
		_______ , _______ , _______ , _______ , RM_TOGG , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
								      MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN, MY_RETRN,
        _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),
};


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_elora_hlc(
//       _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//       _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//       _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//       _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//       _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
//     ),

//--------------------------------------------------------//
//                        ENCODERS                        //
//--------------------------------------------------------//

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [5] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [6] = { ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [7] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [8] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif // defined(ENCODER_MAP_ENABLE)

//--------------------------------------------------------//
//                         COMBOS                         //
//--------------------------------------------------------//

const uint16_t PROGMEM cmb_RS_Y[]     = { MY_R, MY_S, COMBO_END};
const uint16_t PROGMEM cmb_LS_W[]     = { MY_L, MY_S, COMBO_END};
const uint16_t PROGMEM cmb_MD_V[]     = { KC_M, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_DF_Z[]     = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ET_H[]     = { MY_E, MY_T, COMBO_END};
const uint16_t PROGMEM cmb_ON_J[]     = { MY_O, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_AI_QU[]    = { MY_A, MY_I, COMBO_END};
const uint16_t PROGMEM cmb_ITN_TH[]   = { MY_I, MY_T, KC_N, COMBO_END};

const uint16_t PROGMEM cmb_Ranglbrk[] = { KC_LT, KC_LPRN, COMBO_END};
const uint16_t PROGMEM cmb_Rparnts[]  = { KC_LPRN, BR_LBRC, COMBO_END};
const uint16_t PROGMEM cmb_Rbracket[] = { BR_LBRC, BR_LCBR, COMBO_END};
const uint16_t PROGMEM cmb_Rcrlybrc[] = { BR_LCBR, KC_ASTR, COMBO_END};
const uint16_t PROGMEM cmb_3dots[]    = { KC_LPRN, BR_LBRC, BR_LCBR, COMBO_END};
const uint16_t PROGMEM cmb_RL_comma[] = { MY_R, MY_L, COMBO_END};
const uint16_t PROGMEM cmb_RSL_dot[]  = { MY_R, MY_S, MY_L, COMBO_END};
const uint16_t PROGMEM cmb_hsat_pls[] = { KC_HASH, KC_AT, COMBO_END};
const uint16_t PROGMEM cmb_excsl_eq[] = { KC_EXLM, BR_SLSH, COMBO_END};
const uint16_t PROGMEM cmb_bang_cln[] = { BR_QUES, KC_EXLM, COMBO_END};
const uint16_t PROGMEM cmb_79_comma[] = { KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM cmb_789_dot[]  = { KC_7, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM cmb_89_plus[]  = { KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM cmb_56_equal[] = { KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM cmb_45_colon[] = { KC_4, KC_5, COMBO_END};

const uint16_t PROGMEM cmb_2parntes[] = { KC_LPRN, MY_R, COMBO_END};
const uint16_t PROGMEM cmb_2brackts[] = { BR_LBRC, MY_S, COMBO_END};
const uint16_t PROGMEM cmb_2crlbrks[] = { BR_LCBR, MY_L, COMBO_END};
const uint16_t PROGMEM cmb_2quotes[]  = { MY_S, MY_T, COMBO_END};

const uint16_t PROGMEM cmb_ASS_shft[] = { MY_A, BR_SECT, COMBO_END};
const uint16_t PROGMEM cmb_BI_shift[] = { KC_B, MY_I, COMBO_END};
const uint16_t PROGMEM cmb_UM_CpWrd[] = { KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_SSB_CpLk[] = { BR_SECT, KC_B, COMBO_END};

const uint16_t PROGMEM cmb_tmbs_mcr[] = { THUMB_L3, THUMB_R3, COMBO_END};
const uint16_t PROGMEM cmb_tmbs_oth[] = { THUMB_L4, THUMB_R4, COMBO_END};

const uint16_t PROGMEM cmb_LBOOT[]    = { THUMB_LA, THUMB_LB, COMBO_END};
const uint16_t PROGMEM cmb_RBOOT[]    = { THUMB_RA, THUMB_RB, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_RS_Y,     KC_Y),
    COMBO(cmb_LS_W,     KC_W),
    COMBO(cmb_MD_V,     KC_V),
    COMBO(cmb_DF_Z,     KC_Z),
    COMBO(cmb_ET_H,     KC_H),
    COMBO(cmb_ON_J,     KC_J),
    COMBO(cmb_AI_QU,    MC_QU),
    COMBO(cmb_ITN_TH,   MC_TH),

    COMBO(cmb_Ranglbrk, KC_RABK),
    COMBO(cmb_Rparnts,  KC_RPRN),
    COMBO(cmb_Rbracket, BR_RBRC),
    COMBO(cmb_Rcrlybrc, BR_RCBR),
    COMBO(cmb_3dots,    MC_3DOTS),
    COMBO(cmb_RL_comma, KC_COMMA),
    COMBO(cmb_RSL_dot,  KC_DOT),
    COMBO(cmb_hsat_pls, KC_PLUS),
    COMBO(cmb_excsl_eq, KC_EQUAL),
    COMBO(cmb_bang_cln, BR_COLN),
    COMBO(cmb_79_comma, KC_COMMA),
    COMBO(cmb_789_dot,  KC_DOT),
    COMBO(cmb_89_plus,  KC_KP_PLUS),
    COMBO(cmb_56_equal, KC_EQUAL),
    COMBO(cmb_45_colon, BR_COLN),

    COMBO(cmb_2parntes, MC_2parntes),
    COMBO(cmb_2brackts, MC_2brackts),
    COMBO(cmb_2crlbrks, MC_2crlbrks),
    COMBO(cmb_2quotes,  MC_2quotes),

    COMBO(cmb_ASS_shft, OSM(MOD_LSFT)),
    COMBO(cmb_BI_shift, OSM(MOD_RSFT)),
    COMBO(cmb_UM_CpWrd, CW_TOGG),
    COMBO(cmb_SSB_CpLk, KC_CAPS),

    COMBO(cmb_tmbs_mcr, OSL(_MACROS)),
    COMBO(cmb_tmbs_oth, TG(_OTHERS)),

    COMBO(cmb_LBOOT,    QK_BOOT),
    COMBO(cmb_RBOOT,    QK_BOOT),
};

//--------------------------------------------------------//
//                         MACROS                         //
//--------------------------------------------------------//


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	const uint8_t mods = get_mods();
	const uint8_t oneshot_mods = get_oneshot_mods();

	switch (keycode) {
		case MC_QU:
			if (record->event.pressed) {
				if ((mods | oneshot_mods) & (MOD_MASK_SHIFT)) { // Is shift held?
					// Temporarily delete shift
					del_oneshot_mods(MOD_MASK_SHIFT);
					unregister_mods(MOD_MASK_SHIFT);
					send_string_with_delay("Qu", 10);
					register_mods(mods); // Restore mods
				} else {
					send_string_with_delay("qu", 10);
				}
			}
			break;
		case MC_TH:
			if (record->event.pressed) {
				if ((mods | oneshot_mods) & (MOD_MASK_SHIFT)) { // Is shift held?
					// Temporarily delete shift
					del_oneshot_mods(MOD_MASK_SHIFT);
					unregister_mods(MOD_MASK_SHIFT);
					send_string_with_delay("Th", 10);
					register_mods(mods); // Restore mods
				} else {
					send_string_with_delay("th", 10);
				}
			}
			break;
		case MC_ING:
			if (record->event.pressed) {
				send_string_with_delay("ing", 10);
			}
			break;
		case MC_GHT:
			if (record->event.pressed) {
				send_string_with_delay("ght", 10);
			}
			break;
		case MC_CAO:
			if (record->event.pressed) {
				send_string_with_delay(SS_TAP(X_SCLN) SS_TAP(X_QUOTE) "ao", 10);
			}
			break;
		case MC_COES:
			if (record->event.pressed) {
				send_string_with_delay(SS_TAP(X_SCLN) SS_TAP(X_QUOTE) "oes", 10);
			}
			break;
		case MC_Agrve: // à / À
			if (record->event.pressed) {
				if ((mods | oneshot_mods) & (MOD_MASK_SHIFT)) { // Is shift held?
					// Temporarily delete shift
					del_oneshot_mods(MOD_MASK_SHIFT);
					unregister_mods(MOD_MASK_SHIFT);
					send_string_with_delay(SS_LSFT(SS_TAP(X_LBRC)) "A", 10);
					register_mods(mods); // Restore mods
				} else {
					send_string_with_delay(SS_LSFT(SS_TAP(X_LBRC)) "a", 10);
				}
			}
			break;
		case MC_PX:
			if (record->event.pressed) {
				send_string_with_delay("px", 10);
			}
			break;
		case MC_RS:
			if (record->event.pressed) {
				send_string_with_delay("R$ ", 10);
			}
			break;
		case MC_E:
			if (record->event.pressed) {
				send_string_with_delay(" e ", 10);
			}
			break;

		case MC_3DOTS:
			if (record->event.pressed) {
				send_string_with_delay("...", 10);
			}
			break;
		case MC_2parntes: // (|)
			if (record->event.pressed) {
				send_string_with_delay("()" SS_TAP(X_LEFT), 10);
			}
			break;
		case MC_2brackts: // [|]
			if (record->event.pressed) {
				send_string_with_delay(SS_TAP(X_RBRC) SS_TAP(X_BSLS) SS_TAP(X_LEFT), 10);
			}
			break;
		case MC_2crlbrks: // {|}
			if (record->event.pressed) {
				send_string_with_delay(SS_LSFT(SS_TAP(X_RBRC) SS_TAP(X_BSLS)) SS_TAP(X_LEFT), 10);
			}
			break;
		case MC_2quotes: // "|"
			if (record->event.pressed) {
				send_string_with_delay(SS_LSFT(SS_TAP(X_GRAVE) SS_TAP(X_GRAVE)) SS_TAP(X_LEFT), 10);
			}
			break;

    // case ST_MACRO_35:
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(10)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(10)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(10)  SS_LSFT(SS_TAP(X_BSLS))SS_DELAY(10)  SS_TAP(X_LEFT)SS_DELAY(10)  SS_TAP(X_LEFT));
    // }
    // break;
    // case ST_MACRO_36:
    // if (record->event.pressed) {
      // SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(10)  SS_TAP(X_EQUAL)SS_DELAY(10)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(10)  SS_TAP(X_SPACE));
    // }
    // break;
    // case ST_MACRO_37:
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_4))SS_DELAY(10)  SS_LSFT(SS_TAP(X_9))SS_DELAY(10)  SS_LSFT(SS_TAP(X_0))SS_DELAY(10)  SS_TAP(X_LEFT));
    // }
    // break;
    // case ST_MACRO_38:
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_4))SS_DELAY(10)  SS_TAP(X_T)SS_DELAY(10)  SS_TAP(X_H)SS_DELAY(10)  SS_TAP(X_I)SS_DELAY(10)  SS_TAP(X_S));
    // }
    // break;
    // case ST_MACRO_39:
    // if (record->event.pressed) {
      // SEND_STRING(SS_TAP(X_MINUS)SS_DELAY(10)  SS_LSFT(SS_TAP(X_DOT)));
    // }
    // break;
    // case ST_MACRO_40:
    // if (record->event.pressed) {
      // SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(10)  SS_LSFT(SS_TAP(X_8))SS_DELAY(10)  SS_LSFT(SS_TAP(X_8))  SS_DELAY(100) SS_TAP(X_ENTER));
    // }
    // break;
    // case ST_MACRO_41: // </|>
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(10)  SS_TAP(X_INTERNATIONAL_1)SS_DELAY(10)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(10)  SS_TAP(X_LEFT));
    // }
    // break;
    // case ST_MACRO_42: // <|>
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_COMMA))SS_DELAY(10)  SS_LSFT(SS_TAP(X_DOT))SS_DELAY(10)  SS_TAP(X_LEFT));
    // }
    // break;
    // case ST_MACRO_43: // |*_
    // if (record->event.pressed) {
      // SEND_STRING(SS_TAP(X_INTERNATIONAL_1)SS_DELAY(10)  SS_LSFT(SS_TAP(X_8))SS_DELAY(10)  SS_TAP(X_SPACE));
    // }
    // break;
    // case ST_MACRO_44: // _*|
    // if (record->event.pressed) {
      // SEND_STRING(SS_LSFT(SS_TAP(X_SPACE))SS_DELAY(10)  SS_LSFT(SS_TAP(X_8))SS_DELAY(10)  SS_TAP(X_INTERNATIONAL_1));
    // }
    // break;

		case MC_cutey: // ^^
			if (record->event.pressed) {
				send_string_with_delay(SS_LSFT(SS_TAP(X_QUOTE) SS_TAP(X_QUOTE) SS_TAP(X_QUOTE) SS_TAP(X_QUOTE)), 10);
			}
			break;
		case MC_doubt:
			if (record->event.pressed) { // (?)
				send_string_with_delay("(" SS_LSFT(SS_TAP(X_INTERNATIONAL_1)) ")", 10);
			}
			break;
		case MC_link:
			if (record->event.pressed) { // [](|)
				send_string_with_delay(SS_TAP(X_RBRC) SS_TAP(X_BSLS) "()" SS_TAP(X_LEFT), 10);
			}
			break;
		case MC_squez:
			if (record->event.pressed) { // >~<
				send_string_with_delay(">" SS_TAP(X_QUOTE)  SS_TAP(X_QUOTE) "<", 10);
			}
			break;
		case MC_tired:
			if (record->event.pressed) {
				send_string_with_delay("= =", 10);
			}
			break;
		case MC_break:
			if (record->event.pressed) {
				send_string_with_delay("(...)", 10);
			}
			break;
		case MC_sdeye: // ¬¬
			if (record->event.pressed) {
				send_string_with_delay(SS_ALGR(SS_TAP(X_6)) SS_ALGR(SS_TAP(X_6)), 10);
			}
			break;
		case MC_rqv:
			if (record->event.pressed) { // ,rqv | Ctrl+9 | Enter
				send_string_with_delay(",rqv" SS_DELAY(200) SS_LCTL(SS_TAP(X_9)) SS_DELAY(200) SS_TAP(X_ENTER), 10);
			}
			break;
		case MC_astrs: // *|*
			if (record->event.pressed) {
				send_string_with_delay("**" SS_TAP(X_LEFT), 10);
			}
			break;
		case MC_nota:
			if (record->event.pressed) {
				send_string_with_delay(",nota", 10);
			}
			break;


		case DF_F5_F2:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_F5);
				} else {
					unregister_code16(KC_F5);
				}
			} else {
				if (record->event.pressed) {
					register_code16(KC_F2);
				} else {
					unregister_code16(KC_F2);
				}  
			}  
			return false;
    // case DUAL_FUNC_3:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // register_code16(LCTL(LSFT(KC_R)));
        // } else {
          // unregister_code16(LCTL(LSFT(KC_R)));
        // }
      // } else {
        // if (record->event.pressed) {
          // register_code16(KC_LEFT_ALT);
        // } else {
          // unregister_code16(KC_LEFT_ALT);
        // }  
      // }  
      // return false;
    // case DUAL_FUNC_4:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // register_code16(LCTL(KC_S));
        // } else {
          // unregister_code16(LCTL(KC_S));
        // }
      // } else {
        // if (record->event.pressed) {
          // register_code16(KC_LEFT_CTRL);
        // } else {
          // unregister_code16(KC_LEFT_CTRL);
        // }  
      // }  
      // return false;
    // case DUAL_FUNC_5:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // register_code16(LCTL(KC_Z));
        // } else {
          // unregister_code16(LCTL(KC_Z));
        // }
      // } else {
        // if (record->event.pressed) {
          // register_code16(KC_LEFT_SHIFT);
        // } else {
          // unregister_code16(KC_LEFT_SHIFT);
        // }  
      // }  
      // return false;
    // case DUAL_FUNC_6:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // layer_move(0);
        // } else {
          // layer_move(0);
        // }
      // } else {
        // if (record->event.pressed) {
          // layer_on(3);
        // } else {
          // layer_off(3);
        // }  
      // }  
      // return false;
    // case DUAL_FUNC_7:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // register_code16(BR_COLN);
        // } else {
          // unregister_code16(BR_COLN);
        // }
      // } else {
        // if (record->event.pressed) {
          // register_code16(KC_LEFT_CTRL);
        // } else {
          // unregister_code16(KC_LEFT_CTRL);
        // }  
      // }  
      // return false;
    // case DUAL_FUNC_8:
      // if (record->tap.count > 0) {
        // if (record->event.pressed) {
          // layer_move(0);
        // } else {
          // layer_move(0);
        // }
      // } else {
        // if (record->event.pressed) {
          // layer_on(4);
        // } else {
          // layer_off(4);
        // }  
      // }  
      // return false;
		case DF_HOME:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_HOME);
				} else {
					unregister_code16(KC_HOME);
				}
			} else {
				if (record->event.pressed) {
					register_code16(RCTL(KC_HOME));
				} else {
					unregister_code16(RCTL(KC_HOME));
				}
			}
			return false;
		case DF_END:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_END);
				} else {
					unregister_code16(KC_END);
				}
			} else {
				if (record->event.pressed) {
					register_code16(RCTL(KC_END));
				} else {
					unregister_code16(RCTL(KC_END));
				}
			}
			return false;
			
		case MY_R:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_R);
				} else {
					unregister_code16(KC_R);
				}
			} else {
				if (record->event.pressed) {
					register_code16(BR_ACUT);
				} else {
					unregister_code16(BR_ACUT);
				}  
			}  
			return false;
		case MY_S:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_S);
				} else {
					unregister_code16(KC_S);
				}
			} else {
				if (record->event.pressed) {
					register_code16(BR_CIRC);
				} else {
					unregister_code16(BR_CIRC);
				}  
			}  
			return false;
		case MY_L:
			if (record->tap.count > 0) {
				if (record->event.pressed) {
					register_code16(KC_L);
				} else {
					unregister_code16(KC_L);
				}
			} else {
				if (record->event.pressed) {
					register_code16(BR_TILD);
				} else {
					unregister_code16(BR_TILD);
				}  
			}  
			return false;
	}
	return true;
}

//--------------------------------------------------------//
//                        TAP DANCE                       //
//--------------------------------------------------------//

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

//--------------------------------------------------------//

void on_dnc_ctrl_c(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_c_finished(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_c_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_ctrl_c(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dnc_ctrl_c_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:  register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP:  register_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: register_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dnc_ctrl_c_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:  unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP:  unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LSFT(KC_C))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[0].step = 0;
}

//--------------------------------------------------------//

void on_dnc_ctrl_v(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_v_finished(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_v_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_ctrl_v(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dnc_ctrl_v_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LSFT(KC_V)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_V)); register_code16(LCTL(KC_V));
    }
}

void dnc_ctrl_v_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_V)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
    }
    dance_state[1].step = 0;
}

//--------------------------------------------------------//

void on_dnc_ctrl_h(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_h_finished(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_h_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_ctrl_h(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_H));
        tap_code16(LCTL(KC_H));
        tap_code16(LCTL(KC_H));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_H));
    }
}

void dnc_ctrl_h_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_H)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_H))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_H)); register_code16(LCTL(KC_H));
    }
}

void dnc_ctrl_h_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_H)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_H))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_H))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_H)); break;
    }
    dance_state[2].step = 0;
}

//--------------------------------------------------------//

void on_dnc_ctrl_f(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_f_finished(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_f_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_ctrl_f(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_F));
        tap_code16(LCTL(KC_F));
        tap_code16(LCTL(KC_F));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_F));
    }
}

void dnc_ctrl_f_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_F)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_F))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_F))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_F)); register_code16(LCTL(KC_F));
    }
}

void dnc_ctrl_f_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_F)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_F))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_F))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_F)); break;
    }
    dance_state[3].step = 0;
}

//--------------------------------------------------------//

void on_dnc_ctrl_t(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_t_finished(tap_dance_state_t *state, void *user_data);
void dnc_ctrl_t_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_ctrl_t(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_T));
        tap_code16(LCTL(KC_T));
        tap_code16(LCTL(KC_T));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_T));
    }
}

void dnc_ctrl_t_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_T)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_T)); register_code16(LCTL(KC_T));
    }
}

void dnc_ctrl_t_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_T)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_T)); break;
    }
    dance_state[4].step = 0;
}

//--------------------------------------------------------//

void on_dnc_libre_office(tap_dance_state_t *state, void *user_data);
void dnc_libre_office_finished(tap_dance_state_t *state, void *user_data);
void dnc_libre_office_reset(tap_dance_state_t *state, void *user_data);

void on_dnc_libre_office(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(LSFT(KC_2))));
        tap_code16(LALT(LCTL(LSFT(KC_2))));
        tap_code16(LALT(LCTL(LSFT(KC_2))));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(LSFT(KC_2))));
    }
}

void dnc_libre_office_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(LSFT(KC_2)))); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LSFT(KC_0)))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LSFT(KC_0)))); break;
        case DOUBLE_HOLD: register_code16(LALT(LCTL(LSFT(KC_1)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(LSFT(KC_2)))); register_code16(LALT(LCTL(LSFT(KC_2))));
    }
}

void dnc_libre_office_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_2)))); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LSFT(KC_0)))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_0)))); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LCTL(LSFT(KC_1)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_2)))); break;
    }
    dance_state[5].step = 0;
}

//--------------------------------------------------------//

void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case DOUBLE_TAP: register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state[6].step = 0;
}

//--------------------------------------------------------//

void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
        tap_code16(LSFT(KC_H));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_H));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_H)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_H)); register_code16(LSFT(KC_H));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_H)); break;
    }
    dance_state[7].step = 0;
}

//--------------------------------------------------------//

void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DNC_CTRL_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_ctrl_c, dnc_ctrl_c_finished, dnc_ctrl_c_reset),
        [DNC_CTRL_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_ctrl_v, dnc_ctrl_v_finished, dnc_ctrl_v_reset),
        [DNC_CTRL_H] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_ctrl_h, dnc_ctrl_h_finished, dnc_ctrl_h_reset),
        [DNC_CTRL_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_ctrl_f, dnc_ctrl_f_finished, dnc_ctrl_f_reset),
        [DNC_CTRL_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_ctrl_t, dnc_ctrl_t_finished, dnc_ctrl_t_reset),
        [DNC_LIBOFF] = ACTION_TAP_DANCE_FN_ADVANCED(on_dnc_libre_office, dnc_libre_office_finished, dnc_libre_office_reset),
        // [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        // [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};

//--------------------------------------------------------//
//                       LAYER COLORS                     //
//--------------------------------------------------------//

#define LED_TRANS          1,   1,   1
#define LED_OFF            0,   0,   0
#define LED_RED          120,   0,   0
// #define LED_GRAY         0, 0, 0
// #define LED_DARK_GREEN   0, 0, 0
// #define LED_LIGHT_BLUE   0, 0, 0
#define LED_DARK_BLUE      0,   0, 228
#define LED_LIGHT_GREEN  127, 255,  29
#define LED_DARK_GREEN     0, 153,  17



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
	rgb_matrix_enable();
}

/*
 * LEDs template
 * NÃO ESQUECER: VALORES DA ESQUERDA SUBSTITUIRÃO OS DA DIREITA SE NÃO DEFINIDOS!
 *
 *                ,--------------.                      ,--------------.
 *                | 02 | 01 | 00 |                      | 37 | 38 | 39 |
 *                |----+----+----|                      |----+----+----|
 *                | 03 | 04 | 05 |                      | 42 | 41 | 40 |
 *                `--------------'                      `--------------'
 * ,-----------------------------.                      ,-----------------------------.
 * | 36 | 35 | 34 | 33 | 32 | 31 |                      | 68 | 69 | 70 | 71 | 72 | 73 |
 * |----+----+----+----+----+----|                      |----+----+----+----+----+----|
 * | 30 | 29 | 28 | 27 | 26 | 25 |                      | 62 | 63 | 64 | 65 | 66 | 67 |
 * |----+----+----+----+----+----|                      |----+----+----+----+----+----|
 * | 24 | 23 | 22 | 21 | 20 | 19 |                      | 56 | 57 | 58 | 59 | 60 | 61 |
 * |----+----+----+----+----+----+---------.  ,---------+----+----+----+----+----+----|
 * | 18 | 17 | 16 | 15 | 14 | 13 | 12 | 11 |  | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 |
 * `--------------+----+----+----+----+----|  |----+----+----+----+----+--------------'
 *                | 10 | 09 | 08 | 07 | 06 |  | 43 | 44 | 45 | 46 | 47 |
 *                `------------------------'  `------------------------'
 */

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
	[_NUMPAD] = {
		{LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255},
		{255,255,255}, {255,255,255},
		{LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},
		{LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},

		{LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{LED_TRANS}, {LED_TRANS}, {LED_TRANS},
		{255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255},
		{255,255,255}, {255,255,255},
		{0,0,0}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {0,0,0}, {0,0,0},
		{LED_DARK_GREEN}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {LED_DARK_GREEN}, {0,0,0},
		{LED_DARK_GREEN}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {LED_LIGHT_GREEN}, {LED_DARK_GREEN}, {0,0,0},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},
	},
	[_NAVVOL] = {
		{LED_DARK_BLUE}, {LED_DARK_BLUE}, {LED_DARK_BLUE},
		{LED_DARK_BLUE}, {LED_DARK_BLUE}, {LED_DARK_BLUE},
		{255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255},
		{255,255,255}, {255,255,255},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},
		{LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF}, {LED_OFF},

		{LED_DARK_BLUE}, {LED_DARK_BLUE}, {LED_DARK_BLUE},
		{LED_DARK_BLUE}, {LED_DARK_BLUE}, {LED_DARK_BLUE},
		{255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255},
		{255,255,255}, {255,255,255},
		{0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0},
		{0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0},
		{0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0},
		{0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0},
	},
};

/* void set_layer_color(int layer) {
	for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
		HSV hsv = {
			.h = pgm_read_byte(&ledmap[layer][i][0]),
			.s = pgm_read_byte(&ledmap[layer][i][1]),
			.v = pgm_read_byte(&ledmap[layer][i][2]),
		};
		//if (hsv.h == 1 && hsv.s == 1) {
		//	return; // LED_TRANS
		//}
		RGB rgb = hsv_to_rgb(hsv);
		float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
		rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
	}
} */
void set_layer_color(int layer) {
	for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
		RGB rgb = {
			.r = ledmap[layer][i][0],
			.g = ledmap[layer][i][1],
			.b = ledmap[layer][i][2],
		};
		if (!rgb.r && !rgb.g && !rgb.b) {
			rgb_matrix_set_color( i, 0, 0, 0 );
		} else {
			rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
		}
	}
}

bool rgb_matrix_indicators_user(void) {
	switch (biton32(layer_state)) {
		case _ALPHA_A:
		case _ALPHA_B:
			if (host_keyboard_led_state().caps_lock) {
				rgb_matrix_set_color(31, 255, 255, 255);
			}
			if (is_caps_word_on()) {
				rgb_matrix_set_color(31, 255, 255, 255);
			}
			break;
		case _NUMPAD:
			set_layer_color(_NUMPAD);
			
			break;
		case _SHORTCUTS:
			rgb_matrix_set_color(12, LED_RED);
			break;
		case _SYMBOLS:
			rgb_matrix_set_color(12, LED_DARK_BLUE);
			break;
		case _NAVVOL:
			set_layer_color(_NAVVOL);
			break;
		case _MACROS:

			break;
	}
	return true;
}

void caps_word_set_user(bool active) {
    if (!active) { //When Caps Word deactivates
        rgb_matrix_set_color(31, LED_OFF);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
	// Use 'static' variable to remember the previous status
	static bool symbols_on = false;

	if (symbols_on != IS_LAYER_ON_STATE(state, _SYMBOLS)) {
		symbols_on = !symbols_on;
		if (symbols_on) {  // Just entered the layer
			rgb_matrix_set_color(12, LED_DARK_BLUE);
		} else {          // Just exited the layer
			rgb_matrix_set_color(12, LED_OFF);
		}
	}

	return state;
}