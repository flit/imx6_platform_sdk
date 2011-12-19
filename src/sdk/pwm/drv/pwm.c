/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "pwm.h"
#include "interrupt.h"

/*!
 * Intialize the PWM module.
 */
int pwm_init(struct hw_module *port, uint16_t prescale, uint16_t period,
             uint16_t * sample, uint32_t smp_cnt)
{
    int idx;

    pwm_reg_p reg_base = (pwm_reg_p) port->base;

    /* Disable PWM first */
    reg_base->pwmcr &= ~PWMCR_MASK_ENABLE;

    /* Set clock source */
    if ((port->freq < CLK_SRC_IPG) || (port->freq > CLK_SRC_CKIL)) {
        printf("Invalid clock source selection.\n");
        return FALSE;
    }

    reg_base->pwmcr &= ~PWMCR_MASK_CLKSRC;
    reg_base->pwmcr |= port->freq << PWMCR_SHIFT_CLKSRC;

    /* Set FIFO watermark to 4 empty slots */
    reg_base->pwmcr &= ~PWMCR_MASK_FWM;
    reg_base->pwmcr |= PWMCR_FWM_SLOT4;

    /* Set prescale */
    if (prescale >= PWMCR_PRESCALER_MAX) {
        printf("Invalid prescaler value.\n");
        return FALSE;
    }

    reg_base->pwmcr &= ~PWMCR_MASK_PRESCALER;
    reg_base->pwmcr |= prescale << PWMCR_SHIFT_PRESCALER;

    /* Set period */
    reg_base->pwmpr = period;

    /* Write count to FIFO */
    if ((smp_cnt > PWM_CNT_FIFO_SZ) || (smp_cnt < 1)) {
        printf("Invalid number of samples.\n");
        return FALSE;
    }

    for (idx = 0; idx < smp_cnt; idx++) {
        reg_base->pwmsar = sample[idx];
    }

    return TRUE;
}

/*!
 * Clear status that will issue interrupt
 */
void pwm_clear_int_status(struct hw_module *port, uint32_t mask)
{
    pwm_reg_p reg_base = (pwm_reg_p) port->base;

    reg_base->pwmsr = mask;
}

/*!
 * Setup interrupt service routine.
 */
void pwm_setup_interrupt(struct hw_module *port, uint8_t state, uint8_t mask)
{
    pwm_reg_p reg_base = (pwm_reg_p) port->base;

    if (state == ENABLE) {
        /* Disable the IRQ first */
        disable_interrupt(port->irq_id, CPU_0);

        /* Clear status register */
        reg_base->pwmsr = PWMSR_MASK_ALL;

        /* Register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);

        /* Enable the IRQ at ARM core level */
        enable_interrupt(port->irq_id, CPU_0, 0);

        /* Enable interrupt to status */
        reg_base->pwmir &= ~PWMIR_MASK_INT;
        reg_base->pwmir |= mask;
    } else {
        /* Disalbe the IRQ at ARM core level */
        disable_interrupt(port->irq_id, CPU_0);

        /* Clear interrupt enable */
        reg_base->pwmir &= PWMIR_MASK_INT;
    }
}

/*!
 * Enable PWM output
 */
void pwm_enable(struct hw_module *port)
{
    pwm_reg_p reg_base = (pwm_reg_p) port->base;

    reg_base->pwmcr |= PWMCR_MASK_ENABLE;
}

/*!
 * Disable PWM output
 */
void pwm_disable(struct hw_module *port)
{
    pwm_reg_p reg_base = (pwm_reg_p) port->base;

    reg_base->pwmcr &= ~PWMCR_MASK_ENABLE;
}
