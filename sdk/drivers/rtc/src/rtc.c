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

#include "sdk.h"
#include "rtc/rtc.h"
#include "registers/regssnvs.h"
#include "irq_numbers.h"
#include "interrupt.h"
#include "snvs/snvs.h"

void snvs_rtc_setup_interrupt(struct hw_module *port, uint8_t state);
void snvs_rtc_interrupt_handler(void);

/*!
 * RTC structures used by the driver.
 */
typedef struct snvs_rtc_module_ {
    hw_module_t *port;
    funct_t onetime_timer_callback;
    funct_t periodic_timer_callback;
} snvs_rtc_module_t;

static hw_module_t port = {
        "SNVS RTC Driver",              // Driver Name 
        1,                              // Instance number 
        REGS_SNVS_BASE,                 // Block base address in memory map
        0,                              // Frequency 
        IMX_INT_SNVS,                   // Interrupt ID
        &snvs_rtc_interrupt_handler     // Irq handler 
};

static snvs_rtc_module_t s_snvs_rtc_module = {
    &port,
    NULL,
    NULL
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief SNVS RTC interrupt handler.
 */
void snvs_rtc_interrupt_handler(void)
{
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, false);

    if (HW_SNVS_HPSR.B.HPTA)
    {
        if (s_snvs_rtc_module.onetime_timer_callback != NULL)
        {
            s_snvs_rtc_module.onetime_timer_callback();
            s_snvs_rtc_module.onetime_timer_callback = NULL;
            snvs_rtc_alarm(s_snvs_rtc_module.port, false);
        }
    }

    if (HW_SNVS_HPSR.B.PI)
    {
        if (s_snvs_rtc_module.periodic_timer_callback != NULL)
        {
            s_snvs_rtc_module.periodic_timer_callback();
        }
    }
    
    if (s_snvs_rtc_module.periodic_timer_callback || s_snvs_rtc_module.onetime_timer_callback)
    {
        snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, true);
    }
}

/*!
 * @brief Setup SNVS interrupt.
 *
 * It enables or disables the related HW module interrupt, and attached the related
 * sub-routine into the vector table.
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state Pass true to enable the interrupt, false to disable.
 */
void snvs_rtc_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state)
    {
        // register the IRQ sub-routine 
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        
        // enable the IRQ 
        enable_interrupt(port->irq_id, CPU_0, 0);
    }
    else
    {
        // disable the IRQ 
        disable_interrupt(port->irq_id, CPU_0);
    }
}

void rtc_init(void)
{
    // Initialize SNVS driver 
    snvs_init(s_snvs_rtc_module.port);

    // Start rtc counter 
    snvs_rtc_counter(s_snvs_rtc_module.port, true);

    // Keeps alarms disabled 
    snvs_rtc_alarm(s_snvs_rtc_module.port, false);
    snvs_rtc_periodic_interrupt(s_snvs_rtc_module.port, 0, false);

    // Enable interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, true);
}

void rtc_deinit(void)
{
    // Disable the interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, false);
    s_snvs_rtc_module.onetime_timer_callback = NULL;
    s_snvs_rtc_module.periodic_timer_callback = NULL;
    
    // Disable the counter and alarms
    snvs_rtc_counter(s_snvs_rtc_module.port, false);
    snvs_rtc_alarm(s_snvs_rtc_module.port, false);
    snvs_rtc_periodic_interrupt(s_snvs_rtc_module.port, 0, false);
    
    // Deinitialize SNVS 
    snvs_deinit(s_snvs_rtc_module.port);
}

void rtc_setup_onetime_timer(uint64_t timeout, funct_t callback)
{
    // Disables interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, false);

    // Set secure real time counter to 0 
    snvs_rtc_set_counter(s_snvs_rtc_module.port, 0);

    // Disables interrupt 
    snvs_rtc_set_alarm_timeout(s_snvs_rtc_module.port, timeout);

    // Set callback pointer 
    s_snvs_rtc_module.onetime_timer_callback = callback;

    // Enable the interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, true);
}

void rtc_setup_periodic_timer(uint32_t periodic_bit, funct_t callback)
{
    // Disable interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, false);
    
    // Disable periodic interrupt 
    snvs_rtc_periodic_interrupt(s_snvs_rtc_module.port, 0, false);

    // Set the callback pointer 
    s_snvs_rtc_module.periodic_timer_callback = callback;

    // Enable counter and periodic interrupt 
    snvs_rtc_counter(s_snvs_rtc_module.port, true);
    snvs_rtc_periodic_interrupt(s_snvs_rtc_module.port, periodic_bit, true);

    // Enable interrupt 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, true);
}

void rtc_disable_periodic_timer(void)
{
    // Disable interrupts 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, false);

    // Disable RTC periodic interrupt 
    snvs_rtc_periodic_interrupt(s_snvs_rtc_module.port, 0, false);

    // Remove callback 
    s_snvs_rtc_module.periodic_timer_callback = NULL;

    // Reenable interrupts 
    snvs_rtc_setup_interrupt(s_snvs_rtc_module.port, true);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
