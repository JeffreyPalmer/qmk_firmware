/*
Copyright 2024 ElectronLab

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define EE_HANDS
//#define MASTER_LEFT
//#define MASTER_RIGHT

//#define TAPPING_TERM 170
#undef  TAPPING_TERM
#define TAPPING_TERM 170

//#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

#undef HOLD_ON_OTHER_KEY_PRESS

#define COMBO_COUNT 1

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
//#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// allow the use of auto shift on home row modifier keys
#define RETRO_SHIFT

// Caps Word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT
//#define NO_ACTION_TAPPING
//#define NO_MUSIC_MODE

// #define COMBO_COUNT 3
//#define VIAL_COMBO_ENTRIES 3

// Bootmagic support
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 1
