/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file rtc.c
 * @brief  RTC driver source file.
 *
 * @ingroup diag_timer
 */

#include "hardware.h"

void snvs_rtc_setup_interrupt(struct hw_module *port, uint8_t state);
void snvs_rtc_interrupt_handler(void);

/*!
 * RTC strucures used by the driver.
 */
typedef struct snvs_rtc_module_ {
    struct hw_module *port;
    funct_t onetime_timer_callback;
    funct_t periodic_timer_callback;
} snvs_rtc_module_t;

static struct hw_module port = {
        "SNVS RTC Driver",              /* Driver Name */
        SNVS_BASE_ADDR,                 /* Block base address in memory map */
        0,                              /* Frequency */
        IMX_INT_SNVS,                   /* Interrupt ID*/
        &snvs_rtc_interrupt_handler     /* Irq handler*/ 
};

static struct snvs_rtc_module_ snvs_rtc_module = {
    &port,
    NULL,
    NULL
};

/*!
 * SNVS RTC interrupt handler.
 */
void snvs_rtc_interrupt_handler(void)
{
    volatile struct mx_snvs *psnvs = 
        (volatile struct mx_snvs *)snvs_rtc_module.port->base;

    snvs_rtc_setup_interrupt(snvs_rtc_module.port, DISABLE);

    if(psnvs->hpsr & HPSR_HPTA)
    {
        if(snvs_rtc_module.onetime_timer_callback != NULL)
        {
            snvs_rtc_module.onetime_timer_callback();
            snvs_rtc_module.onetime_timer_callback = NULL;
            snvs_rtc_alarm(snvs_rtc_module.port, DISABLE);
        }
    }   
    if(psnvs->hpsr & HPSR_PI)
    {
        if(snvs_rtc_module.periodic_timer_callback != NULL)
            snvs_rtc_module.periodic_timer_callback();
    }
    if(snvs_rtc_module.periodic_timer_callback || snvs_rtc_module.onetime_timer_callback)
        snvs_rtc_setup_interrupt(snvs_rtc_module.port, ENABLE);
}


/* Local Functions */
/*!
 * Setup SNVS interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the SNVS module structure.
 * @param   state - ENABLE or DISABLE the interrupt.
 */
void snvs_rtc_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    }
    else
    {
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
    }
}

/* Driver API */

/*!
 * Initializes RTC by enabling non-secured real time counter, 
 * disables alarm and periodic interrupt. It also calls internal
 * API snvs_rtc_setup_interrupt to register interrupt service handler
 */
void rtc_init(void)
{
    /* Initialize SNVS driver */
    snvs_init(snvs_rtc_module.port);

    /* Start rtc counter */
    snvs_rtc_counter(snvs_rtc_module.port, ENABLE);

    /* Keeps alarms disabled */
    snvs_rtc_alarm(snvs_rtc_module.port, DISABLE);
    snvs_rtc_periodic_interrupt(snvs_rtc_module.port, 0, DISABLE);

    /* Enable interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, ENABLE);
}

/*!
 * Disables interrupt, counter, alarm and periodic alarm
 */
void rtc_deinit(void)
{
    /* Disable the interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, DISABLE);
    snvs_rtc_module.onetime_timer_callback = NULL;
    snvs_rtc_module.periodic_timer_callback = NULL;
    
    /* Disable the counter and alarms*/
    snvs_rtc_counter(snvs_rtc_module.port, DISABLE);
    snvs_rtc_alarm(snvs_rtc_module.port, DISABLE);
    snvs_rtc_periodic_interrupt(snvs_rtc_module.port, 0, DISABLE);
    /* Deinitialize SNVS */
    snvs_deinit(snvs_rtc_module.port);
}

/*!
 * Calls in appropriate low level API to setup one-time timer
 *
 * @param   timeout - set RTC alarm timeout.
 * @param   callback - callback function to be called from isr.
 */
void rtc_setup_onetime_timer(uint64_t timeout, funct_t callback)
{
    /* Disables interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, DISABLE);

    /* Set secure real time counter to 0 */
    snvs_rtc_set_counter(snvs_rtc_module.port, 0);

    /* Disables interrupt */
    snvs_rtc_set_alarm_timeout(snvs_rtc_module.port, timeout);

    /* Set callback pointer */
    snvs_rtc_module.onetime_timer_callback = callback;

    /* Enable the interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, ENABLE);
}

/*!
 * Calls in appropriate low level API to setup periodic timer
 *
 * @param   periodic_bit - periodic interrupt freq (valid values 0-15)
 * @param   callback - pointer to callback function
 */
void rtc_setup_periodic_timer(uint32_t periodic_bit, funct_t callback)
{
    /* Disable interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, DISABLE);
    
    /* Disable periodic interrupt */
    snvs_rtc_periodic_interrupt(snvs_rtc_module.port, 0, DISABLE);

    /* Set the callback pointer */
    snvs_rtc_module.periodic_timer_callback = callback;

    /* Enable counter and periodic interrupt */
    snvs_rtc_counter(snvs_rtc_module.port, ENABLE);
    snvs_rtc_periodic_interrupt(snvs_rtc_module.port, periodic_bit, ENABLE);

    /* Enable interrupt */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, ENABLE);
}

/*!
 * Calls in appropriate low level API to disable periodic timer
 */
void rtc_disable_periodic_timer(void)
{
    /* Disable interrupts */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, DISABLE);

    /* Disable RTC periodic interrupt */
    snvs_rtc_periodic_interrupt(snvs_rtc_module.port, 0, DISABLE);

    /* Remove callback */
    snvs_rtc_module.periodic_timer_callback = NULL;

    /* Reenable interrupts */
    snvs_rtc_setup_interrupt(snvs_rtc_module.port, ENABLE);
}
