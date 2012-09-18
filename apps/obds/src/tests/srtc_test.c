/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file srtc.c
 * @brief Basic security RTC test
 *
 */

#include "hardware.h"

/*!
 * The SRTC test enables the SRTC and check if the SRTC LP counter toggles.
 */
int srtc_test_enable;
int srtc_test(void)
{
    u32 c1, c2;

    PROMPT_RUN_TEST("SRTC");

    // enable SRTC HP
    writel(0x8, SRTC_HPCR);

    c1 = readl(SRTC_HPSCMR);
    c2 = readl(SRTC_HPSCLR);

    hal_delay_us(10000);

    if (c1 == readl(SRTC_HPSCMR) && c2 == readl(SRTC_HPSCLR)) {
        printf("SRTC secure counter failed to run\n");
        return TEST_FAILED;
    } else {
        printf("SRTC HP counter is running\n");
    }

    // enable SRTC LP
    writel(0x8, SRTC_LPCR);

    c1 = readl(SRTC_LPSCMR);
    c2 = readl(SRTC_LPSCLR);
    hal_delay_us(10000);

    if (c1 == readl(SRTC_LPSCMR) && c2 == readl(SRTC_LPSCLR)) {
        printf("SRTC secure counter failed to run\n");
        return TEST_FAILED;
    }

    printf(" SRTC test passed \n");
    return TEST_PASSED;
}

//RUN_TEST("SRTC", srtc_test)
