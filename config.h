// Copyright 2023 Alen Karnil (@datapaganism)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define DEBOUNCE 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
