/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"

extern int32_t sense_fuse(uint32_t bank, uint32_t row);
extern void fuse_blow_row(uint32_t bank, uint32_t row, uint32_t value);

uint32_t get_int(void);

/*! 
 * OCOTP test.
 * This test allows to read or write a fuse location.
 *
 * @return  none
 */
int32_t ocotp_test(void)
{
    uint8_t sel, bank, row;
    uint32_t value;

    printf("Start OCOTP unit tests:");

    do {
        printf("\n  1 - to read a fuse location.\n");
        printf("  2 - to write a fuse location.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            printf("Go to sense function...\n");
        if (sel == '2')
            printf("Go to blow function...\n");

        printf("Please set the bank (1,2,...): \n");
        do {
            bank = getchar();
        } while (bank == NONE_CHAR);
        /* move from received ASCII code to real value */ 
        bank -= 0x30;
        printf("  %d\n",bank);

        printf("Please set the row (1,2,...): \n");
        do {
            row = getchar();
        } while (row == NONE_CHAR);
        /* move from received ASCII code to real value */
        row -= 0x30;
        printf("  %d\n",row);

        if (sel == '1') {
            printf("Value read in bank %d / row %d is:\n", bank, row);
            printf("0x%08X\n", sense_fuse(bank, row));
        }
        if (sel == '2') {
            value = get_input_hex();

            printf("\n !! Do you really want to blow 0x%08X in bank %d / row %d ? (Y/N)!!\n",
                   value, bank, row);
            printf("Note that writting 0x0 is harmless.\n");
            do {
                sel = getchar();
            } while (sel == NONE_CHAR);
            if((sel == 'Y') || (sel == 'y'))
                fuse_blow_row(bank, row, value);
        }

    } while(1);

    return 0;
}
