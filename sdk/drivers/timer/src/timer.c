/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

#include <assert.h>
#include "hardware.h"
#include "timer/epit.h"
#include "timer/timer.h"
#include "registers/regsarmglobaltimer.h"

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

static void time_init_global_timer();

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

uint32_t g_microsecondTimerMultiple;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

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

void system_time_init(void)
{
    // Init microsecond tick counter.
    time_init_global_timer();
    
    /* EPIT1 is used for the delay function */
    /* Initialize the EPIT timer used for system time functions */
    /* typical IPG_CLK is in MHz, so divide it to get a reference
       clock of 1MHz => 1us per count */
    g_system_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&g_system_timer, CLKSRC_IPG_CLK, g_system_timer.freq / 1000000,
              SET_AND_FORGET, 1000, WAIT_MODE_EN | STOP_MODE_EN);
}

//! Init the ARM global timer to a microsecond-frequency clock.
void time_init_global_timer()
{
    // The ARM private peripheral clock is half the CPU clock.
    uint32_t periphClock = get_main_clock(CPU_CLK) / 2;
    uint32_t prescaler = (periphClock / 1000000) - 1;
    
    // Divide down the prescaler until it fits into 8 bits. We add up the number of ticks
    // it takes to equal a microsecond interval.
    g_microsecondTimerMultiple = 1;
    while (prescaler > 0xff)
    {
        prescaler /= 2;
        ++g_microsecondTimerMultiple;
    }
    
    // Make sure the timer is off.
    HW_ARMGLOBALTIMER_CONTROL.B.TIMER_ENABLE = 0;
    
    // Clear counter.
    HW_ARMGLOBALTIMER_COUNTER0_WR(0);
    HW_ARMGLOBALTIMER_COUNTER1_WR(0);
    
    // Set prescaler and clear other flags.
    HW_ARMGLOBALTIMER_CONTROL_WR(BF_ARMGLOBALTIMER_CONTROL_PRESCALER(prescaler));
    
    // Now turn on the timer.
    HW_ARMGLOBALTIMER_CONTROL.B.TIMER_ENABLE = 1;
}

uint64_t time_get_microseconds()
{
    // First read upper.
    uint32_t upper = HW_ARMGLOBALTIMER_COUNTER1_RD();
    uint32_t lower;
    
    while (true)
    {
        // Read lower.
        lower = HW_ARMGLOBALTIMER_COUNTER0_RD();
        
        // Read upper again.
        uint32_t newUpper = HW_ARMGLOBALTIMER_COUNTER1_RD();
        
        // If the first and second read of the upper bits are the same, then return.
        if (newUpper == upper)
        {
            return (((uint64_t)upper << 32) | (uint64_t)lower) / g_microsecondTimerMultiple;
        }
        
        // Otherwise, start over again.
        upper = newUpper;
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

