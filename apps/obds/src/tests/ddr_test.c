/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_ddr_test DDR Test
 */

/*!
 * @file ddr_test.c
 * @brief DDR test driver
 *
 * @ingroup diag_ddr_test
 */

/*
* Note, this file depends that in the SoC header file, CSD0_BASE_ADDR
* CSD1_BASE_ADDR are properly defined.
*/
#include "hardware.h"           /* note, this is where the SoC specific header file is included */

/*!
 * test DDR
 *
 * @param   density        memory size.
 * @param   number_of_cs   chip select number.
 *
 * @return      TEST_PASSED or TEST_FAILED
 */
int ddr_test(u32 density, u32 number_of_cs)
{
    unsigned int failCount = 0;
    unsigned int i;
    unsigned int mem_src;
    unsigned int *ps;
    int bank_size = density / 8;

    /* Data bus, walking ones test */
    /* Looking for shorts on the board, so no need to test both chip selects */

    /* First, write walking ones to DDR memory */
    ps = (unsigned int *)(CSD0_BASE_ADDR + bank_size * 4);

    for (i = 0; i <= 31; i++) {
        *ps = 0x1 << i;
        ps++;
    }

    /* Now, read-verify the memory */
    ps = (unsigned int *)(CSD0_BASE_ADDR + bank_size * 4);

    for (i = 0; i <= 31; i++) {
        if (*ps != (0x1 << i)) {
            failCount++;
        }

        ps++;
    }

    /* BANK ADDRESS test */
    /* CS0 bank address test - note since code is stored in first part of DDR in CSD0
       do not write data to the first bank to avoid overwriting code.
       Hence variable "i" starts at 1 not 0 */
    /* First, write data to each bank */
    for (i = 1; i <= 7; i++) {
        ps = (unsigned int *)(CSD0_BASE_ADDR + bank_size * i);
        *ps = 0x11111111 * i;
    }

    /* Second, read back data from each bank to verify */
    for (i = 1; i <= 7; i++) {
        ps = (unsigned int *)(CSD0_BASE_ADDR + bank_size * i);

        if (*ps != 0x11111111 * i) {
            failCount++;
        }
    }

    if (number_of_cs == 2) {
        /* CS1 bank address test */
        /* First, write data to each bank */
        for (i = 0; i <= 7; i++) {
            ps = (unsigned int *)(CSD1_BASE_ADDR + bank_size * i);
            *ps = 0x88888888 + 0x11111111 * i;
        }

        /* Second, read back data from each bank to verify */
        for (i = 0; i <= 7; i++) {
            ps = (unsigned int *)(CSD1_BASE_ADDR + bank_size * i);

            if (*ps != (0x88888888 + 0x11111111 * i)) {
                failCount++;
            }
        }
    }

    /* DDR ADDRESS test, test the last two banks for each chip select */
    /* CS0 */
    /* First, write data to each row */
    mem_src = CSD0_BASE_ADDR + bank_size * 6;

    for (i = 0; i < bank_size * 2; i = i + 512) {
        ps = (unsigned int *)(mem_src + i);
        *ps = 0x12345678 + 0x11111111 * i;
    }

    /* Second, read back data from each row to verify */
    mem_src = CSD0_BASE_ADDR + bank_size * 6;

    for (i = 0; i < bank_size * 2; i = i + 512) {
        ps = (unsigned int *)(mem_src + i);

        if (*ps != (0x12345678 + 0x11111111 * i)) {
            failCount++;
        }
    }

    if (number_of_cs == 2) {
        /* CS1 */
        /* First, write data to each row */
        mem_src = CSD1_BASE_ADDR + bank_size * 6;

        for (i = 0; i < bank_size * 2; i = i + 512) {
            ps = (unsigned int *)(mem_src + i);
            *ps = 0x87654321 + 0x11111111 * i;
        }

        /* Second, read back data from each row to verify */
        mem_src = CSD1_BASE_ADDR + bank_size * 6;

        for (i = 0; i < bank_size * 2; i = i + 512) {
            ps = (unsigned int *)(mem_src + i);

            if (*ps != (0x87654321 + 0x11111111 * i)) {
                failCount++;
            }
        }
    }

    if (failCount == 0) {
        printf(" DDR test passed \n");
        return TEST_PASSED;
    } else {
        printf(" DDR test failed \n");
        return TEST_FAILED;
    }
}

int ddr_test_enable;
uint32_t ddr_density, ddr_num_of_cs;

/*!
 * Run the DDR test.
 * @return      TEST_PASSED or TEST_FAILED
 */
int run_ddr_test(void)
{
    if (!ddr_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("DDR");

    return ddr_test(ddr_density, ddr_num_of_cs);
}

//RUN_TEST_EARLY("DDR", run_ddr_test)
