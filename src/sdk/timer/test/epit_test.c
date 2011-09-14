/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "epit_test.h"

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
        } while (sel == (uint8_t) 0xFF);

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

void epit_delay_test(void)
{
    uint32_t counter = 0;
    /* stops after xx seconds */
    uint32_t max_duration = 10;

    printf("This test displays the elapsed number of second.\n");
    printf("Test exists after %d seconds.\n",max_duration);

    while (counter != max_duration) {        
        hal_delay_us(1000000);
        counter++;
        printf("%ds\n",counter);
    };
}

/* EPIT2 port is free for i.MX61 and i.MX53 SDK as EPIT1 is used
   for a global delay function */
static struct hw_module g_tick_timer = {
    "EPIT2 for system tick",
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    &tick_timer_interrupt_handler,
};

static uint8_t g_wait_flag;

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
void epit_tick_test(void)
{
    uint32_t counter = 0;
    /* stops after xx seconds */
    uint32_t max_duration = 10;

    printf("EPIT is programmed to generate an interrupt every 10ms as a tick timer.\n");
    printf("Test exists after %d seconds.\n",max_duration);

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
        g_wait_flag = 1;
        while (g_wait_flag == 1);
        counter++;

        if (!(counter%100)) 
            printf("Elapsed time %d seconds <=> %d ticks.\n", counter/100, counter);
    };

    epit_counter_disable(&g_tick_timer);
}