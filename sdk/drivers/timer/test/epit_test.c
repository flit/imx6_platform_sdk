/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit_test.c
 * @brief EPIT unit tests source file.
 *
 * @ingroup diag_timer
 */

#include <stdio.h>
#include "timer/epit.h"
#include "timer/timer.h"
#include "epit_test.h"

static volatile uint8_t g_wait_for_irq;

/*!
 * Main unit test for the EPIT.
 * @return  0
 */
int32_t epit_test(void)
{
    uint8_t sel;

    printf("Start EPIT unit tests:");

    do {
        printf("\n  1 - for delay test.\n");
        printf("  2 - for tick test.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) NONE_CHAR);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            epit_delay_test();
        if (sel == '2')
            epit_tick_test();

    } while(1);

    return 0;
}

/*!
 * This test uses the system delay function that uses the EPIT counter.
 * The EPIT is configure into timer.c.
 * Whenever a second has passed, it displays the elapsed number of seconds.
 */
void epit_delay_test(void)
{
    uint32_t counter = 0;
    /* stops after xx seconds */
    uint32_t max_duration = 10;

    printf("This test displays the elapsed number of second.\n");
    printf("The test exists after %d seconds.\n",max_duration);

    while (counter != max_duration) {        
        hal_delay_us(1000000);
        counter++;
        printf("%ds\n",counter);
    };
}

/* EPIT2 port is free for i.MX6DQ/SDL and i.MX53 SDK as EPIT1 is used
   for a global delay function */
static hw_module_t g_tick_timer = {
    "EPIT2 for system tick",
    2,
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    &tick_timer_interrupt_routine,
};

/*! 
 * Tick timer interrupt handler.
 */
void tick_timer_interrupt_routine(void)
{
    g_wait_for_irq = 0;
    /* clear the compare event flag */
    epit_get_compare_event(&g_tick_timer);
}

/*!
 * The EPIT is programmed to generate an interrupt every 10ms.
 * It emulates an system tick timer. A counter is increased at every tick.
 * Whenever a second has passed, it displays the counter value.
 */
void epit_tick_test(void)
{
    uint32_t counter = 0;
    /* stops after xx seconds */
    uint32_t max_duration = 10;

    printf("EPIT is programmed to generate an interrupt every 10ms as a tick timer.\n");
    printf("The test exists after %d seconds.\n",max_duration);

    /* Initialize the EPIT timer used for tick timer. An interrupt
       is generated every 10ms */
    /* typical IPG_CLK is in MHz, so divide it to get a reference
       clock of 1MHz => 1us per count */
    g_tick_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&g_tick_timer, CLKSRC_IPG_CLK, g_tick_timer.freq/1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&g_tick_timer, ENABLE);
    epit_counter_enable(&g_tick_timer, 10000, IRQ_MODE);

    while ((counter/100) != max_duration) {
        g_wait_for_irq = 1;
        while (g_wait_for_irq == 1);
        counter++;

        if (!(counter%100)) 
            printf("Elapsed time %d seconds <=> %d ticks.\n", counter/100, counter);
    };

    epit_counter_disable(&g_tick_timer);
}
