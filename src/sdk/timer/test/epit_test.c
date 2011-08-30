/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "epit_test.h"

/* EPIT2 port is free for i.MX61 and i.MX53 platforms */
static struct hw_module g_tick_timer = {
    "EPIT2 for system tick",
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    &tick_timer_interrupt_handler,
};

static uint8_t g_wait_flag;

int32_t epit_test(void)
{
    uint8_t sel;

    printf("Start EPIT unit tests:\n");

    do {

        printf("  1 - for delay test.\n");
        printf("  2 - for tick test.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            epit_test_1();
        if (sel == '2')
            epit_test_2();

    } while(1);

    return 0;
}

void epit_test_1(void)
{
    printf("This test endlessly displays a '.' every second\n");
    do {
        hal_delay_us(1000000);
        printf(".\n");
    } while(1);
}

/*! 
 * Tick timer interrupt handler.
 *
 * @return  none
 */
void tick_timer_interrupt_handler(void)
{
    g_wait_flag = 0;
    /* clear the compare event flag */
    epit_get_compare_event(&g_tick_timer);
}

/*!
 * The EPIT is programmed to generate an interrupt every 10ms.
 * It emulates an system tick timer. A counter is increased at every tick.
 * Whenever a second has passed, it displays the counter value.\n");
 * 
*/
void epit_test_2(void)
{
    uint32_t counter = 0;

    printf("EPIT is programmed to generate an interrupt every 10ms as a tick timer.\n");
    printf("Test exists after 10 seconds.\n");

    /* set same frequency than the one known for system timer 
       and that was initialized in platform_init() */
    g_tick_timer.freq = g_system_timer.freq;

    /* Initialize the EPIT timer used for tick timer */
    /* typical PER_CLK is in MHz, so divide it to get a reference
       clock of 1MHz => 1us per count */
    epit_init(&g_tick_timer, CLKSRC_PER_CLK, g_tick_timer.freq/1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&g_tick_timer, ENABLE);
    epit_counter_enable(&g_tick_timer, 10000, IRQ_MODE);

    do {
        g_wait_flag = 1;
        while (g_wait_flag == 1);
        counter++;

        if (!(counter%100)) 
            printf("Elapsed time %d seconds <=> %d ticks.\n", counter/100, counter);
        /* stops after 10 seconds */
        if ((counter/100) == 10)
            break;

    } while(1);

    epit_counter_disable(&g_tick_timer);
}