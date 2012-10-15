/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file srtc.c
 * @brief  SRTC driver source file.
 *
 * @ingroup diag_timer
 */

#include "sdk.h"
#include "rtc/rtc.h"
#include "registers/regssnvs.h"
#include "irq_numbers.h"
#include "interrupt.h"
#include "snvs/snvs.h"

/*!
 * @brief SRTC strucures used by the driver.
 */
typedef struct snvs_srtc_module_ {
    hw_module_t *port;
    funct_t onetime_timer_callback;
} snvs_srtc_module_t;

void snvs_srtc_setup_interrupt(struct hw_module *port, uint8_t state);
void snvs_srtc_interrupt_handler(void);

static hw_module_t port = {
        "SNVS SRTC Driver",                 // Driver Name 
        1,                                  // Instance number 
        REGS_SNVS_BASE,                     // Block base address in memory map
        0,                                  // Frequency 
        IMX_INT_SNVS,                   // Interrupt ID
        &snvs_srtc_interrupt_handler        // Irq handler 
};

static snvs_srtc_module_t s_snvs_srtc_module = {
    &port,
    NULL
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Setup SNVS interrupt.
 *
 * Enables or disables the related HW module interrupt, and attached the related
 * sub-routine into the vector table.
 *
 * @param   port Pointer to the SNVS module structure.
 * @param   state true to enable or false to disable.
 */
void snvs_srtc_setup_interrupt(struct hw_module *port, uint8_t state)
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

/*!
 * @brief SNVS SRTC interrupt handler.
 */
void snvs_srtc_interrupt_handler(void)
{
    snvs_srtc_setup_interrupt(s_snvs_srtc_module.port, false);

    if (HW_SNVS_LPSR.B.LPTA && s_snvs_srtc_module.onetime_timer_callback != NULL)
    {
        HW_SNVS_LPSR_CLR(BM_SNVS_LPSR_LPTA);

        s_snvs_srtc_module.onetime_timer_callback();
        s_snvs_srtc_module.onetime_timer_callback = NULL;
        snvs_srtc_alarm(s_snvs_srtc_module.port, false);
    }   
    else
    {
        snvs_srtc_setup_interrupt(s_snvs_srtc_module.port, true);
    }
}

void srtc_init(void)
{
    // Initialize SNVS driver 
    snvs_init(s_snvs_srtc_module.port);

    // Start SRTC counter 
    snvs_srtc_counter(s_snvs_srtc_module.port, true);

    // Keep time alarm disabled 
    snvs_srtc_alarm(s_snvs_srtc_module.port, false);
}

void srtc_deinit(void)
{
    // Disable the interrupt 
    snvs_srtc_setup_interrupt(s_snvs_srtc_module.port, false);

    // Disable the counter 
    snvs_srtc_counter(s_snvs_srtc_module.port, false);
    snvs_srtc_alarm(s_snvs_srtc_module.port, false);

    // Deinitialize SNVS 
    snvs_deinit(s_snvs_srtc_module.port);
}

void srtc_setup_onetime_timer(uint32_t timeout, funct_t callback)
{
    // Disables the interrupt 
    snvs_srtc_setup_interrupt(s_snvs_srtc_module.port, false);

    // Clear the SRTC counter 
    snvs_srtc_set_counter(s_snvs_srtc_module.port, 0);

    // Program the timeout value 
    snvs_srtc_set_alarm_timeout(s_snvs_srtc_module.port, timeout);

    // Set the callback function 
    s_snvs_srtc_module.onetime_timer_callback = callback;

    // Reanable the interrupt 
    snvs_srtc_setup_interrupt(s_snvs_srtc_module.port, true);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
