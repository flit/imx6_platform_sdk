/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
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
#include <snvs.h>
#include <rtc.h>
#include "snvs_rtc_test.h"

static int32_t onetime_tick = 0;
static int32_t periodic_tick = 0;

void one_time_tick_callback(void)
{
    onetime_tick = 1;
}

void periodic_tick_callback(void)
{
    periodic_tick ++;
    if(periodic_tick > 10)
        rtc_deinit();
}

void one_time_timer_test(void)
{
    int loop = 0xFFFFFF;

    onetime_tick = 0;

    rtc_init();
    
    rtc_setup_onetime_timer(10, one_time_tick_callback);

    while(loop--)
    {
        if(onetime_tick)
            break;
    }

    if(onetime_tick == 0)
        printf( "SNVS RTC Timer Test Failed!!\n");
    else
        printf( "SNVS RTC Timer Test Passed!!\n");

    rtc_deinit();
}

void periodic_timer_test(void)
{
    int loop = 0xFFFFFF;

    periodic_tick = 0;

    rtc_init();
    
    rtc_setup_periodic_timer(2, periodic_tick_callback);

    while(loop--)
    {
        if(periodic_tick > 10)
            break;
    }

    if(periodic_tick == 0)
        printf( "SNVS RTC Periodic Test Failed!!\n");
    else
        printf( "SNVS RTC Periodic Test Passed with %d periodic interrupts!!\n", periodic_tick);

    rtc_deinit();
}

/*!
 * Main unit test for the RTC.
 * @return  0
 */
int32_t snvs_rtc_test(void)
{
    uint8_t sel;

    printf("Start SNVS RTC unit tests:");

    do {

        printf("\n  1 - for one time timer test.\n");
        printf("  2 - for periodic timer test.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            one_time_timer_test();
        if (sel == '2')
            periodic_timer_test();

    } while(1);

    return 0;
}
