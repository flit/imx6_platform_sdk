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

void press_key_test(void);

/*!
 * Main unit test for the Keypad.
 * @return  0
 */
void keypad_test(void)
{
    uint8_t sel;

    printf("Start Keypad unit tests:");

    do {
        printf("\n  1 - press a key test.\n");
        printf("  2 - for test 2.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
        	press_key_test();
        if (sel == '2')
        	press_key_test();

    } while(1);

    return;
}

/*!
 *
 */
void press_key_test(void)
{
    uint8_t i, kppcol, kpprow;
    uint16_t read_keys[8];

    /* this is a 3x3 matrix - col[7:5] x row[7:5] */
    kppcol = kpprow = 0xE0;

    kpp_init(kppcol, kpprow);

    do
    {
        printf("Please press any key:\n");

        /* get the pressed key(s) */
        kpp_get_keypad_state(read_keys, WF_INTERRUPT);

        /* wait for no key pressed */
        kpp_wait_for_release_state();

        for(i=0;i<8;i++)
        {
            if((read_keys[i] & 0xFF) != 0x00)
                printf("Key %04X was pressed.\n",read_keys[i]);
        }

    } while(1);
}
