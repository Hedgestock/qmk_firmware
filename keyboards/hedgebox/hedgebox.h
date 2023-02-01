#pragma once

#include "quantum.h"
#include "keymap_french.h"

#define LAYOUT_numpad_4x4( \
	 K00, K01, K02, K03,   K30, K31, K32, K33, \
	                       K20, K21, K22, K23, \
	          K10,   K11, K12,   K13 \
) { \
	{ K00,   K01,   K02,   K03 }, \
	{ K10,   K11,   K12,   K13 }, \
	{ K20,   K21,   K22,   K23 }, \
	{ K30,   K31,   K32,   K33 } \
}
