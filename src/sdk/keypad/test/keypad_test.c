/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file keypad_test.c
 * @brief Keypad unit tests source file.
 *
 * @ingroup diag_keypad
 */

#include <stdio.h>
#include "hardware.h"
#include "keypad_test.h"

void multiple_key_press_test(void);

/*!
 * Main unit test for the Keypad.
 * @return  0
 */
void keypad_test(void)
{
    uint8_t sel;

    printf("Start Keypad unit tests:");

    do {
        printf("\n  1 - Multiple keys pressed test.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            multiple_key_press_test();

    } while(1);

    return;
}

/*!
 * A test that detects that multiple keys are pressed and waits for them
 * to release to print what are the keys.
 */
void multiple_key_press_test(void)
{
    uint8_t row, col, exit_test, kppcol, kpprow;
    uint16_t read_keys[8];

    /* this is a 3x3 matrix - col[7:5] x row[7:5] */
    kppcol = kpprow = 0xE0;

    kpp_open(kppcol, kpprow);

    exit_test = 1;
    do
    {
        printf("Please press any key (SW14 to exit):\n");

        /* get the first pressed key(s) */
        kpp_get_keypad_state(read_keys, WF_INTERRUPT);

        /* a delay is required between 2 captures to detect that
         * multiple keys are pressed
         * It is too difficult for a user to push multiple keys within a single
         * capture of few micro seconds.
         * That delay and the number of captures should be adjusted per applications.
         */
        hal_delay_us(50000);

        /* get the next pressed key(s) after half a second */
        kpp_get_keypad_state(read_keys, WF_INTERRUPT);

        /* wait for no key pressed */
        kpp_wait_for_release_state();

        for(col=0;col<8;col++)
        {
            if((read_keys[col] & 0xFF) != 0x00)
            {
                for(row=0;row<8;row++)
                {
                    if((read_keys[col] & (1 << row)) != 0)
                    {
                        printf("Key %s was pressed.\n",KEYPAD_MAP[row][col]);
                        /* exit test if key on row=col=7 is pressed */
                        if((row & col) == 7)
                            exit_test = 0;
                    }
                }
            }
        }

    } while(exit_test);

    kpp_close();
}
