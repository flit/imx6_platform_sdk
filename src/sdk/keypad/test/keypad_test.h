/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file keypad_test.h
 * @brief Keypad unit tests header file.
 *
 * @ingroup diag_keypad
 */

#ifndef __KEYPAD_TEST_H__
#define __KEYPAD_TEST_H__

#include "io.h"

#define NO_KEY "NOT VALID"

static const int8_t* KEYPAD_MAP[8][8] = {
    /* COL0    COL1    COL2    COL3    COL4    COL5    COL6    COL7 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY }, /* ROW0 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY }, /* ROW1 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY }, /* ROW2 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY }, /* ROW3 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY }, /* ROW4 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, "SW4" , "SW5" , "SW7"  }, /* ROW5 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, "SW9" , "SW10", "SW11" }, /* ROW6 */
    { NO_KEY, NO_KEY, NO_KEY, NO_KEY, NO_KEY, "SW12", "SW13", "SW14" }, /* ROW7 */
};

#endif /* __KEYPAD_TEST_H__ */
