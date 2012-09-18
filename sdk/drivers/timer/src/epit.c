/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit.c
 * @brief EPIT driver source file.
 *
 * @ingroup diag_timer
 */

#include "timer/epit.h"
#include "timer/timer.h"
#include "core/interrupt.h"
#include "core/ccm_pll.h"
#include "registers/regsepit.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void epit_reload_counter(struct hw_module *port, uint32_t load_val)
{
    // set the load register especially if RLD=reload_mode=SET_AND_FORGET=1 
    HW_EPIT_EPITLR_WR(port->instance, load_val);
}

uint32_t epit_get_counter_value(struct hw_module *port)
{
    return HW_EPIT_EPITCNR_RD(port->instance);
}

void epit_set_compare_event(struct hw_module *port, uint32_t compare_val)
{
    HW_EPIT_EPITCMPR_WR(port->instance, compare_val);
}

uint32_t epit_get_compare_event(struct hw_module *port)
{
    uint32_t status_register;

    // get the status 
    status_register = HW_EPIT_EPITSR_RD(port->instance);
    
    // clear it if found set 
    if (status_register & BM_EPIT_EPITSR_OCIF)
    {
        HW_EPIT_EPITSR_SET(port->instance, BM_EPIT_EPITSR_OCIF);
    }

    // return the read value before the bit was cleared 
    return status_register & BM_EPIT_EPITSR_OCIF;
}

void epit_counter_disable(struct hw_module *port)
{
    /* temporary workaround for the discovered issue when disabling the
     * counter during end of count/reload/set compare flag ??.
     * Set to the max value so that it ensures that the counter couldn't
     * reach 0 when it is disabled.
     */
    HW_EPIT_EPITLR_WR(port->instance, 0xFFFFFFFF);

    // disable the counter 
    HW_EPIT_EPITCR_CLR(port->instance, BM_EPIT_EPITCR_EN);

    // ensure to leave the counter in a proper state
    // by disabling the output compare interrupt
    HW_EPIT_EPITCR_CLR(port->instance, BM_EPIT_EPITCR_OCIEN);
    
    // and clearing possible remaining compare event 
    HW_EPIT_EPITSR_SET(port->instance, BM_EPIT_EPITSR_OCIF);
}

void epit_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode)
{
    // set the load register especially if RLD=reload_mode=SET_AND_FORGET=1
    // and if the value is different from 0 which is the lowest counter value
    if (load_val != 0)
    {
        HW_EPIT_EPITLR_WR(port->instance, load_val);
    }

    // ensure to start the counter in a proper state
    // by clearing possible remaining compare event
    HW_EPIT_EPITSR_SET(port->instance, BM_EPIT_EPITSR_OCIF);

    // set the mode when the output compare event occur: IRQ or polling 
    if (irq_mode == IRQ_MODE)
    {
        HW_EPIT_EPITCR_SET(port->instance, BM_EPIT_EPITCR_OCIEN);
    }
    else
    {
        // polling 
        HW_EPIT_EPITCR_CLR(port->instance, BM_EPIT_EPITCR_OCIEN);
    }

    // finally, enable the counter 
    HW_EPIT_EPITCR_SET(port->instance, BM_EPIT_EPITCR_EN);
}

void epit_setup_interrupt(struct hw_module *port, bool enableIt)
{
    if (enableIt)
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

void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode)
{
    uint32_t control_reg_tmp = 0;

    // enable the source clocks to the EPIT port 
    clock_gating_config(port->base, CLOCK_ON);

    // start with a known state by disabling and reseting the module 
    HW_EPIT_EPITCR_WR(port->instance, BM_EPIT_EPITCR_SWR);
    
    // wait for the reset to complete 
    while ((HW_EPIT_EPITCR(port->instance).B.SWR) != 0) ;

    // set the reference source clock for the counter 
    control_reg_tmp |= BF_EPIT_EPITCR_CLKSRC(clock_src);

    // set the counter clock prescaler value - 0 to 4095 
    control_reg_tmp |= BF_EPIT_EPITCR_PRESCALAR(prescaler-1);

    // set the reload mode 
    if (reload_mode == SET_AND_FORGET)
    {
        control_reg_tmp |= BM_EPIT_EPITCR_RLD;
    }

    // set behavior for low power mode 
    if (low_power_mode & WAIT_MODE_EN)
    {
        control_reg_tmp |= BM_EPIT_EPITCR_WAITEN;
    }
    if (low_power_mode & STOP_MODE_EN)
    {
        control_reg_tmp |= BM_EPIT_EPITCR_STOPEN;
    }

    // make the counter start from a known value when enabled, this is loaded from
    // EPITLR register if RLD=reload_mode=1 or 0xFFFFFFFF if RLD=reload_mode=0
    control_reg_tmp |= BM_EPIT_EPITCR_IOVW | BM_EPIT_EPITCR_ENMOD;

    // finally write the control register 
    HW_EPIT_EPITCR_WR(port->instance, control_reg_tmp);

    // initialize the load register especially if RLD=reload_mode=SET_AND_FORGET=1 
    // and if the value is different from 0 which is the lowest counter value
    if (load_val != 0)
    {
        HW_EPIT_EPITLR_WR(port->instance, load_val);
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
