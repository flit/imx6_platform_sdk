/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs.c
 * @brief Basic security RTC test of the SNVS module.
 *
 */

#include "hardware.h"

// These defines are used to solve some compilations issue with src/drivers/timer/imx_timer/srtc.c
#define SNVS_SRTC_LPSCMR    SRTC_LPSCMR
#define SNVS_SRTC_LPSCLR    SRTC_LPSCLR
#define SNVS_SRTC_LPCR      SRTC_LPCR
#define SNVS_SRTC_HPSCMR    SRTC_HPSCMR
#define SNVS_SRTC_HPSCLR    SRTC_HPSCLR
#define SNVS_SRTC_HPCR      SRTC_HPCR

/*!
 * The SRTC test enables the SRTC of the SNVS and check if the SRTC LP counter toggles.
 */
int obds_snvs_srtc_test_enable;
int obds_snvs_srtc_test(void)
{
    u32 c1, c2;

    PROMPT_RUN_TEST("SNVS - SRTC");

    // enable SNVS HP
    writel(0x1, SNVS_SRTC_HPCR);

    c1 = readl(SNVS_SRTC_HPSCMR);
    c2 = readl(SNVS_SRTC_HPSCLR);

    hal_delay_us(10000);

    if (c1 == readl(SNVS_SRTC_HPSCMR) && c2 == readl(SNVS_SRTC_HPSCLR)) {
        printf("SNVS SRTC secure counter failed to run\n");
        return TEST_FAILED;
    } else {
        printf("SNVS SRTC HP counter is running\n");
    }

    // enable SNVS LP
    writel(0x1, SNVS_SRTC_LPCR);

    c1 = readl(SNVS_SRTC_LPSCMR);
    c2 = readl(SNVS_SRTC_LPSCLR);
    hal_delay_us(10000);

    if (c1 == readl(SNVS_SRTC_LPSCMR) && c2 == readl(SNVS_SRTC_LPSCLR)) {
        printf("SNVS SRTC secure counter failed to run\n");
        return TEST_FAILED;
    }

    printf("SNVS SRTC test passed \n");
    return TEST_PASSED;
}

//RUN_TEST("SNVS - SRTC", snvs_srtc_test)
