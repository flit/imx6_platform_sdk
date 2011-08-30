/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file time.c
 * @brief Basic clock functions used by the ANSI C time (see time.h)
 *
 */

#include "hardware.h"
#include "time.h"

void hal_delay_us(uint32_t usecs)
{
#ifdef MX53
    if (usecs == 0) {
        return;
    }

    /* enable the counter first */
    epit_counter_enable(&g_system_timer, usecs, POLLING_MODE);
    /* wait for the compare event */
    while (!epit_get_compare_event(&g_system_timer)) ;
    /* disable the counter to save power */
    epit_counter_disable(&g_system_timer);

#else /* iMX61 */
    volatile struct mx_epit *pepit = (volatile struct mx_epit *)g_system_timer.base;
    uint32_t delayCount = (usecs * 512) / 15625;

    if (delayCount == 0) {
        return;
    }

    pepit->epitlr = delayCount;

    pepit->epitsr |= EPITSR_OCIF;
   /* do not return until compare bit is set, use IRQ later? */
    while ((pepit->epitsr & EPITSR_OCIF) == 0) ;
    pepit->epitsr |= EPITSR_OCIF;
#endif
}

void system_time_init(uint32_t clock_src)
{
    /* Typically, EPIT1 is used for the delay function */
    /* Initialize the EPIT timer used for system time functions */
    /* typical PER_CLK is in MHz, so divide it to get a reference
       clock of 1MHz => 1us per count */
    epit_init(&g_system_timer, clock_src, g_system_timer.freq/1000000,
              SET_AND_FORGET, 1000, WAIT_MODE_EN | STOP_MODE_EN);
}
