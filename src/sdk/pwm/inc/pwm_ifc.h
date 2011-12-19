/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PWM_IFC__
#define __PWM_IFC__

#include "io.h"

#define PWMIR_MASK_FIE ((uint32_t)0x1)  /* FIFO empty */
#define PWMIR_MASK_RIE ((uint32_t)0x2)  /* Rollover */
#define PWMIR_MASK_CIE ((uint32_t)0x4)  /* Compare */

#define PWMSR_MASK_FE  ((uint32_t)0x00000008)   /* FIFO empty */
#define PWMSR_MASK_ROV ((uint32_t)0x00000010)   /* Rollover */
#define PWMSR_MASK_CMP ((uint32_t)0x00000020)   /* Compare */
#define PWMSR_MASK_FWE ((uint32_t)0x00000040)   /* FIFO write error */

/*!
 * Initialize PWM module, setup samples and pulse width.
 *     Pulse Width = (prescale * period) / Fsrc (second)
 *     Duty Cycle = sample[idx] / period
 * Return
 *     TRUE on success
 *     FALSE on fail
 */
extern int pwm_init(struct hw_module *, /* device instance */
                    uint16_t,   /* frequency prescale */
                    uint16_t,   /* period value */
                    uint16_t *, /* sample list */
                    uint32_t);  /* sample count */

/*!
 * Enable/Disable PWM interrupt.
 * Mask could be one or ORed of below:
 *     PWMIR_MASK_FIE
 *     PWMIR_MASK_RIE
 *     PWMIR_MASK_CIE
 */
extern void pwm_setup_interrupt(struct hw_module *, /* device instance */
                                uint8_t,    /* enable or disable */
                                uint8_t);   /* interrupt mask */

/*!
 * Clear interrupt status
 * Mask could be one or ORed of below:
 *     PWMSR_MASK_FE
 *     PWMSR_MASK_ROV
 *     PWMSR_MASK_CMP
 */
void pwm_clear_int_status(struct hw_module *,   /* device instance */
                          uint32_t);    /* status mask */

/*!
 * Enable PWM output.
 */
extern void pwm_enable(struct hw_module *);

/*!
 * Disable PWM ouput.
 */
extern void pwm_disable(struct hw_module *);

#endif
