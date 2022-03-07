/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#  define STARTUP_SONG SONG(ED_NOTE(_A4), ED_NOTE(_E5), ED_NOTE(_A5), Q__NOTE(_E6),)
#  define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND) }
#endif

// Fix startup sound
#define AUDIO_INIT_DELAY

#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_LAYERS
#endif

// Tapping fixes
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD