/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpt.c
 * @brief GPT driver.
 *
 */

#include "hardware.h"

#ifdef _FLORENT_NOT_READY_YET_
/*! 
 * Get the output compare status flag an clear if sets.
 * This function is typically used for polling method.
 *
 * @param   port - pointer to the GPT module structure.
 * @return  the value of the compare event flag.
 */
uint32_t gpt_get_compare_event(struct hw_module *port)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t status_register;

    /* get the status */
    status_register = pgpt->gptsr;
    /* clear it if found set */
    if (status_register == GPTSR_OF1)
        pgpt->gpt_sr |= GPTSR_OF1;

    /* return the read value before the bit was cleared */
    return status_register;
}

/*! 
 * Disable the counter. It saves energy when not used.
 *
 * @param   port - pointer to the GPT module structure.
 */
void gpt_counter_disable(struct hw_module *port)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;

    /* disable the counter */
    pgpt->gptcr &= ~GPTCR_EN;

    /* ensure to leave the counter in a proper state
       by disabling the output compare interrupt */
    pgpt->gptcr &= ~GPTCR_OCIEN;
    /* and clearing possible remaining compare event */
    pgpt->gptsr |= GPTSR_OCIF;
}

/*! 
 * Enable the GPT module. Used for instance when the gpt_init is done, and
 * other interrupt related settings are ready.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   load_val - load value from where the counter start in SET_AND_FORGET mode.
 * @param   irq_mode - interrupt mode: IRQ_MODE or POLLING_MODE.
 */
void gpt_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;

    /* set the load register especially if RLD=reload_mode=SET_AND_FORGET=1 */
    pgpt->gptlr = load_val;

    /* ensure to start the counter in a proper state
       by clearing possible remaining compare event */
    pgpt->gptsr |= GPTSR_OCIF;

    /* set the mode when the output compare event occur: IRQ or polling */
    if (irq_mode == IRQ_MODE)
        pgpt->gptcr |= GPTCR_OCIEN;
    else    /* polling */
        pgpt->gptcr &= ~GPTCR_OCIEN;

    /* finally, enable the counter */
    pgpt->gptcr |= GPTCR_EN;
}
#endif
/*! 
 * Setup GPT interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the GPT module structure.
 */
void gpt_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_1, 0);
    }
    else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_1);
}

/*  * @param   prescaler - prescaler of source clock from 1 to 4096. */

/*! 
 * Initialize the GPT timer.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   clock_src - source clock of the counter: CLKSRC_OFF, CLKSRC_IPG_CLK,
 *                      CLKSRC_PER_CLK, CLKSRC_CKIL, CLKSRC_CLKIN.
 * @param   counter_mode - counter mode: FREE_RUN_MODE or RESTART_MODE.
 * @param   low_power_mode - low power during which the timer is enabled:
 *                           WAIT_MODE_EN and/or STOP_MODE_EN.
 */
void gpt_init(struct hw_module *port, uint32_t clock_src,
              uint32_t counter_mode, uint32_t low_power_mode)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t control_reg_tmp = 0;

    /* enable the source clocks to the GPT port */
    clock_gating_config(port->base, CLOCK_ON);

    /* start with a known state by disabling and reseting the module */
    pgpt->gpt_cr = GPTCR_SWR;
    /* wait for the reset to complete */
    while ((pgpt->gpt_cr & GPTCR_SWR) != 0) ;

    /* set the reference source clock for the counter */
    control_reg_tmp |= GPTCR_CLKSRC(clock_src);

    /* set the counter mode */
    control_reg_tmp |= counter_mode;

    /* set behavior for low power mode */
    if (low_power_mode & WAIT_MODE_EN)
        control_reg_tmp |= GPTCR_WAITEN;
    if (low_power_mode & STOP_MODE_EN)
        control_reg_tmp |= GPTCR_STOPEN;

    /* specify from where the counter starts to count when enabled */
    /* this code makes it start from 0 */
    control_reg_tmp |= GPTCR_ENMOD;

    /* finally write the control register */
    pgpt->gpt_cr = control_reg_tmp;
}
