/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpt.c
 * @brief  GPT driver source file.
 *
 * @ingroup diag_timer
 */

#include "hardware.h"

/*!
 * Get rollover event flag and clear it if set.
 * This function can typically be used for polling method, but
 * is also used to clear the status compare flag in IRQ mode.
 *
 * @param   port - pointer to the GPT module structure.
 * @return  the value of the rollover event flag.
 */
uint32_t gpt_get_rollover_event(struct hw_module *port)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t status_register;

    /* get the rollover status bit */
    status_register = pgpt->gpt_sr & GPTSR_ROV;
    /* clear it if found set */
    if (status_register == GPTSR_ROV)
        pgpt->gpt_sr |= GPTSR_ROV;

    /* return the read value before the bit was cleared */
    return status_register;
}

/*!
 * Get a captured value when an event occured, and clear the flag if set.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   flag - checked capture event flag such GPTSR_IF1, GPTSR_IF2.
 * @param   capture_val - the capture register value is returned there 
 *                        if the event is true.
 * @return  the value of the capture event flag.
 */
uint32_t gpt_get_capture_event(struct hw_module *port, uint8_t flag,
                               uint32_t * capture_val)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t status_register;

    /* get the capture status bit */
    status_register = pgpt->gpt_sr & flag;
    /* clear it if set */
    if (status_register == GPTSR_IF1) {
        *(uint32_t *) capture_val = pgpt->gpt_icr1;
        pgpt->gpt_sr |= status_register;
    }
    else if (status_register == GPTSR_IF2) {
        *(uint32_t *) capture_val = pgpt->gpt_icr2;
        pgpt->gpt_sr |= status_register;
    }

    /* return the read value before the bit was cleared */
    return status_register;
}

/*!
 * Set the input capture mode.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   cap_input - capture input: CAP_INPUT1, CAP_INPUT2.
 * @param   cap_input_mode - capture input mode: INPUT_CAP_DISABLE, INPUT_CAP_BOTH_EDGE,
 *                            INPUT_CAP_FALLING_EDGE, INPUT_CAP_RISING_EDGE.
 */
void gpt_set_capture_event(struct hw_module *port, uint8_t cap_input,
                           uint8_t cap_input_mode)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t control_reg_tmp;

    control_reg_tmp = pgpt->gpt_cr;
    /* clear the input mode first */
    control_reg_tmp &= ~GPTCR_IM_MODE(cap_input,0x3);
    /* set the new input mode */
    control_reg_tmp |= GPTCR_IM_MODE(cap_input,cap_input_mode);
    pgpt->gpt_cr = control_reg_tmp;
}

/*!
 * Get a compare event flag and clear it if set.
 * This function can typically be used for polling method, but
 * is also used to clear the status compare flag in IRQ mode.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   flag - checked compare event flag such GPTSR_OF1, GPTSR_OF2, GPTSR_OF3.
 * @return  the value of the compare event flag.
 */
uint32_t gpt_get_compare_event(struct hw_module *port, uint8_t flag)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t status_register;

    /* get the active compare flags */
    status_register = pgpt->gpt_sr & (flag);
    /* clear flags which are active */
    if (status_register != 0x0)
        pgpt->gpt_sr |= status_register;

    /* return the read value before the flags were cleared */
    return status_register;
}

/*!
 * Set a compare event by programming the compare register and 
 * compare output mode.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   cmp_output - compare output: CMP_OUTPUT1, CMP_OUTPUT2, CMP_OUTPUT3.
 * @param   cmp_output_mode - compare output mode: OUTPUT_CMP_DISABLE, OUTPUT_CMP_TOGGLE,
 *                            OUTPUT_CMP_CLEAR, OUTPUT_CMP_SET, OUTPUT_CMP_LOWPULSE.
 * @param   cmp_value - compare value for the compare register.
 */
void gpt_set_compare_event(struct hw_module *port, uint8_t cmp_output,
                           uint8_t cmp_output_mode, uint32_t cmp_value)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;
    uint32_t control_reg_tmp;

    control_reg_tmp = pgpt->gpt_cr;
    /* clear the output mode first */
    control_reg_tmp &= ~GPTCR_OM_MODE(cmp_output,0x7);
    /* set the new output mode */
    control_reg_tmp |= GPTCR_OM_MODE(cmp_output,cmp_output_mode);
    pgpt->gpt_cr = control_reg_tmp;

    /* set the value to compare with */
    if (cmp_output == CMP_OUTPUT1)
        pgpt->gpt_ocr1 = cmp_value;
    else if (cmp_output == CMP_OUTPUT2)
        pgpt->gpt_ocr2 = cmp_value;
    else if (cmp_output == CMP_OUTPUT3)
        pgpt->gpt_ocr3 = cmp_value;
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
    pgpt->gpt_cr &= ~GPTCR_EN;

    /* ensure to leave the counter in a proper state
       by disabling the interrupt sources */
    pgpt->gpt_ir = 0;
    /* and by clearing possible remaining events */
    pgpt->gpt_sr |= GPTSR_ALL;
}

/*!
 * Enable the GPT module. Used typically when the gpt_init is done, and
 * other interrupt related settings are ready.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   irq_mode - interrupt mode: list of enabled IRQ such GPTSR_ROVIE, or
 *                     (GPTSR_IF1IE | GPTSR_OF3IE), ... or POLLING_MODE.
 */
void gpt_counter_enable(struct hw_module *port, uint32_t irq_mode)
{
    volatile struct mx_gpt *pgpt = (volatile struct mx_gpt *)port->base;

    /* ensure to start the counter in a proper state
       by clearing possible remaining events */
    pgpt->gpt_sr |= GPTSR_ALL;

    /* enable the interrupts or clear the register for polling */
    pgpt->gpt_ir = 0;
    pgpt->gpt_ir |= irq_mode;

    /* finally, enable the counter */
    pgpt->gpt_cr |= GPTCR_EN;
}

/*!
 * Setup GPT interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   state - ENABLE or DISABLE the interrupt.
 */
void gpt_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    }
    else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
}

/*!
 * Initialize the GPT timer.
 *
 * @param   port - pointer to the GPT module structure.
 * @param   clock_src - source clock of the counter: CLKSRC_OFF, CLKSRC_IPG_CLK,
 *                      CLKSRC_PER_CLK, CLKSRC_CKIL, CLKSRC_CLKIN.
 * @param   prescaler - prescaler of the source clock from 1 to 4096.
 * @param   counter_mode - counter mode: FREE_RUN_MODE or RESTART_MODE.
 * @param   low_power_mode - low power during which the timer is enabled:
 *                           WAIT_MODE_EN and/or STOP_MODE_EN.
 */
void gpt_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
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
    if (clock_src == CLKSRC_CKIL)
        clock_src++;    /* CKIL source is 0x4 for GPT but 0x3 for EPIT */
    control_reg_tmp |= GPTCR_CLKSRC(clock_src);

    /* the prescaler can be changed at any time, and 
       this affects the output clock immediately */
    pgpt->gpt_pr |= prescaler-1;

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
