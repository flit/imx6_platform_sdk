/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "print_clock_info.h"
#include "platform_init.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void show_freq(void)
{
    int32_t i;
    hw_module_t *tmp;
    printf("======== Clock frequencies(HZ) =========\n");

    for (i = 0; (tmp = g_imx_modules[i]) != NULL; i++) {
        printf("%s\t: %d,%03d,%03d\n", tmp->name, tmp->freq / 1000000,
               (tmp->freq % 1000000) / 1000, tmp->freq % 1000);
    }

    printf("========================================\n\n");
}

//! @todo Rewrite for MMDC controller. This code is currently for MX53.
void show_ddr_config(void)
{
#if 0
    uint32_t temp1, dsiz, row, col, cs_info;
    uint32_t temp2, num_banks, ddr_type;
    uint32_t density, megabyte;
    uint32_t num_rows = 1, num_cols = 1, num_dsiz = 1, i = 1;

    printf("========== DDR configuration ===========\n");

    megabyte = 1024 * 1024;
    /* read ESDCTL and gather information */
    temp1 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x00);
    dsiz = ((temp1 & (0x00030000)) >> 16);
    /*Calculate dsize */
    while (i <= dsiz) {
        num_dsiz *= 2;
        i++;
    }
    dsiz = 16 * num_dsiz;

    row = ((temp1 & (0x07000000)) >> 24) + 11;
    col = ((temp1 & (0x00700000)) >> 20) + 9;
    cs_info = (temp1 & (0xC0000000)) >> 30;
    /* read ESDMISC to get # of BANK info */
    temp2 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x18);
    num_banks = (!((temp2 & (0x00000020)) >> 5)) * 4 + 4;
    ddr_type = (temp2 & (0x00000018)) >> 3;
    printf("data bits: %d, num_banks: %d \n", dsiz, num_banks);
    printf("row: %d, col: %d \n", row, col);

    if (ddr_type == 1)
        printf("DDR type is DDR2 \n");
    else if (ddr_type == 2)
        printf("DDR type is LPDDR2\n");
    else
        printf("DDR type is DDR3 \n");

    if (cs_info == 0)
        printf("No chip select is enabled \n");
    else if (cs_info == 2)
        printf("Chip select CSD0 is used \n");
    else if (cs_info == 1)
        printf("Chip select CSD1 is used  \n");
    else
        printf("Both chip select CSD0 and CSD1 are used  \n");

    /* Now calculate the DDR density per chip select */

    i = 1;
    /* First need to calculate the number of rows and cols 2^row and 2^col */
    while (i <= row) {
        num_rows *= 2;
        i++;
    }

    debug_printf("num_rows= %d\n", num_rows);
    i = 1;

    while (i <= col) {
        num_cols *= 2;
        i++;
    }

    debug_printf("num_cols= %d\n", num_cols);
    density = num_rows * num_cols / megabyte;
    density = density * dsiz * num_banks / 8;
    printf("Density per chip select: %dMB \n", density);
    printf("========================================\n\n");
#endif // 0
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
