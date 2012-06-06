/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>

#include "hardware.h"
#include "pwm/inc/pwm_ifc.h"

extern void pwm1_iomux_config(void);
static void pwm_isr(void);

static uint32_t pwm_test_end;

static hw_module_t pwm1 = {
    "PWM 1",                    /* name */
    1,                          /* instance number */
    PWM1_BASE_ADDR,             /* register base */
    3,                          /* clock source CKIL */
    IMX_INT_PWM1,               /* IRQ ID */
    pwm_isr,                    /* ISR callback */
    pwm1_iomux_config,          /* IOMUX */
};

static void pwm_isr(void)
{
    printf("PWM output end.\n");

    /* Clear FIFO empty status */
    pwm_clear_int_status(&pwm1, PWMSR_MASK_FE);

    /* Set PWM output end flag */
    pwm_test_end = TRUE;
}

static void pwm_launch_test(void)
{
    uint16_t sample[3] = { 4, 8, 16 };

    pwm_test_end = FALSE;

    /* Initialize PWM module */
    if (FALSE == pwm_init(&pwm1, 1024, 32, sample, 3)) {
        printf("PWM init failed.\n");
        return;
    }

    /* Setup interrupt for FIFO empty */
    pwm_setup_interrupt(&pwm1, ENABLE, PWMIR_MASK_FIE);

    printf("PWM output start.\n");

    /* Enable PWM output */
    pwm_enable(&pwm1);

    /* Wait until FIFO empty */
    while (pwm_test_end == FALSE) ;

    /* Disable PWM output */
    pwm_disable(&pwm1);

    /* Disable PWM interrupt */
    pwm_setup_interrupt(&pwm1, DISABLE, PWMIR_MASK_FIE);
}

int pwm_test(void)
{
    uint8_t sel;

    printf("PWM test start: \n");

    do {
        printf("  s - to start PWM output.\n");
        printf("  x - to exit.\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("Test exit.\n");
            break;
        }

        if (sel == 's') {
            pwm_launch_test();
        }

    } while (1);

    return 0;
}
