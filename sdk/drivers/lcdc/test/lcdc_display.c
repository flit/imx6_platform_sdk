/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_lcd LCD Test
 */

#include "sdk.h"
#include "lcdc/lcdc_common.h"

int32_t lcdc_display_test(void)
{
    char revchar;

    lcdif_display_setup();

    image_center_copy();

    printf("Do you see Freescale logo displayed on the WVGA panel?(Y/y for yes, other for no)\n");

    do {
        revchar = getchar();
    }
    while (revchar == (uint8_t)0xFF);
    if (!(revchar == 'Y' || revchar == 'y'))
        return TEST_FAILED;

    return TEST_PASSED;
}
