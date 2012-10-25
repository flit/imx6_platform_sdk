/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include "sdk.h"
#include "pwm/pwm_ifc.h"
#include "iomux_config.h"

static void pwm_isr(void);

static uint32_t pwm_test_end;

static hw_module_t pwm1 = {
    "PWM 1",                    // name 
    1,                          // instance number 
    PWM1_BASE_ADDR,             // register base 
    kPwmClockSourceCkil,        // clock source CKIL 
    IMX_INT_PWM1,               // IRQ ID 
    pwm_isr,                    // ISR callback 
    pwm1_iomux_config,          // IOMUX 
};

static void pwm_isr(void)
{
    printf("PWM output end.\n");

    // Clear FIFO empty status 
    pwm_clear_int_status(&pwm1, kPwmFifoEmptyIrq);

    // Set PWM output end flag 
    pwm_test_end = TRUE;
}

static void pwm_launch_test(void)
{
    uint16_t sample[3] = { 4, 8, 16 };

    pwm_test_end = FALSE;

    // Initialize PWM module 
    if (FALSE == pwm_init(&pwm1, 1024, 32, sample, 3)) {
        printf("PWM init failed.\n");
        return;
    }

    // Setup interrupt for FIFO empty 
    pwm_setup_interrupt(&pwm1, TRUE, kPwmFifoEmptyIrq);

    printf("PWM output start.\n");

    // Enable PWM output 
    pwm_enable(&pwm1);

    // Wait until FIFO empty 
    while (pwm_test_end == FALSE) ;

    // Disable PWM output 
    pwm_disable(&pwm1);

    // Disable PWM interrupt 
    pwm_setup_interrupt(&pwm1, FALSE, kPwmFifoEmptyIrq);
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
