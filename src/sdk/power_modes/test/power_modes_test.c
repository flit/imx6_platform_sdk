/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "timer/epit.h"

static void tick_timer_interrupt_routine(void);

/* EPIT2 port is free for i.MX6DQ/SDL and i.MX53 SDK as EPIT1 is used
   for a global delay function */
static struct hw_module g_tick_timer = {
    "EPIT2 for system tick",
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    &tick_timer_interrupt_routine,
};

/*! 
 * EPIT interrupt handler.
 */
void tick_timer_interrupt_routine(void)
{
    /* clear the compare event flag */
    epit_get_compare_event(&g_tick_timer);
    epit_counter_disable(&g_tick_timer);
}

void power_modes_test(void)
{
    printf("Starting the low power modes test.\n");

    /* Initialize the EPIT timer with interrupt */
    /* By using CKIL and a prescaler of 33, the counter frequency is ~1kHz */
    g_tick_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&g_tick_timer, CLKSRC_CKIL, 33,
              SET_AND_FORGET, 5000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&g_tick_timer, ENABLE);

    /* allow the EPIT2 interrupt source to wake up the processor */
    ccm_set_lpm_wakeup_source(g_tick_timer.irq_id, ENABLE);

    /************* WAIT MODE *************************/
    printf("Entering wait state. The EPIT will wake up the core in ~5s.\n");
    /* delay is just used to allow the complete display of the above
       message before going into low power mode */ 
    hal_delay_us(10000);
    /* enable IRQ in 5000 clock cycles of CKIL = ~5s */
    epit_counter_enable(&g_tick_timer, 5000, IRQ_MODE);

    ccm_enter_low_power(WAIT_MODE);

    printf("Exiting wait state.\n");

    /************* STOP MODE *************************/
    printf("Entering stop state. The EPIT will wake up the core in ~5s.\n");
    /* delay is just used to allow the complete display of the above
       message before going into low power mode */ 
    hal_delay_us(10000);
    /* enable IRQ in 5000 clock cycles of CKIL = ~5s */
    epit_counter_enable(&g_tick_timer, 5000, IRQ_MODE);

    ccm_enter_low_power(STOP_MODE);

    printf("Exiting stop state.\n");

    printf("Exiting from the low power modes test.\n");
}
