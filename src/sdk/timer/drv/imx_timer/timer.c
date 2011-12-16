/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file timer.c
 * @brief Basic timer functions
 *
 * @ingroup diag_timer
 */

#include "hardware.h"

/*!
 * Delay function used in the system.
 *
 * @param  usecs - delay in micro seconds.
 */
void hal_delay_us(uint32_t usecs)
{
    if (usecs == 0) {
        return;
    }

    /* enable the counter first */
    epit_counter_enable(&g_system_timer, usecs, POLLING_MODE);
    /* wait for the compare event */
    while (!epit_get_compare_event(&g_system_timer)) ;
    /* disable the counter to save power */
    epit_counter_disable(&g_system_timer);
}

/*!
 * Init function used of the EPIT timer used for delay.
 */
void system_time_init(void)
{
    /* EPIT1 is used for the delay function */
    /* Initialize the EPIT timer used for system time functions */
    /* typical IPG_CLK is in MHz, so divide it to get a reference
       clock of 1MHz => 1us per count */
    g_system_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&g_system_timer, CLKSRC_IPG_CLK, g_system_timer.freq / 1000000,
              SET_AND_FORGET, 1000, WAIT_MODE_EN | STOP_MODE_EN);
}
