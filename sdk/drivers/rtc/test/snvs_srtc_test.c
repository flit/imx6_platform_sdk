/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs_rtc_test.c
 * @brief SNVS RTC unit tests source file.
 *
 * @ingroup diag_timer
 */

#include <stdio.h>
#include "sdk.h"
#include "rtc/srtc.h"
#include "snvs_srtc_test.h"

static int32_t onetime_tick = 0;

void srtc_one_time_tick_callback(void)
{
    onetime_tick = 1;
}

void srtc_one_time_timer_test(void)
{
    int loop = 0xFFFFFFFF;

    onetime_tick = 0;

    srtc_init();
    
    srtc_setup_onetime_timer(1, srtc_one_time_tick_callback);

    while(loop--)
    {
        if(onetime_tick)
            break;
    }

    if(onetime_tick == 0)
        printf( "SNVS SRTC Timer Test Failed!!\n");
    else
        printf( "SNVS SRTC Timer Test Passed!!\n");

    srtc_deinit();
}

/*!
 * Main unit test for the SRTC.
 * @return  0
 */
int32_t snvs_srtc_test(void)
{
    uint8_t sel;

    printf("Start SNVS SRTC unit tests:");

    do {

        printf("\n  1 - for one time timer test.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            srtc_one_time_timer_test();
    } while(1);

    return 0;
}
