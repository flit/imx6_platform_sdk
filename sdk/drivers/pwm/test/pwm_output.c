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

#define INVALID_INT	0xFFFFFFFF
uint32_t g_pwm_test_end;

int32_t pwm_output_test(void)
{
    uint16_t sample[3] = { 4, 8, 16 };
    struct pwm_parms pwm;
    uint32_t instance = 1, get_value = 0;
    int32_t retv = TRUE;

    printf("Please select the clock you want to use, enter 'return' key to set\n");
    printf
        ("\t1 - Global Functional Clock\n\t2 - High Frequency Clock or CKIH\n\t3 - Low Reference Clock (32KHz)\n");
    while (1) {
        retv = uart_get_integer(&get_value);
        if (retv == TRUE) {
    		if (get_value >= kPwmClockSourceIpg && get_value <= kPwmClockSourceCkil)
		    break;
	}
        printf("\n!Invalid input! Please input intergers: \n");
    }
    pwm.freq = get_value;
    //pwm.freq = kPwmClockSourceCkil;

    printf("Please input the prescaler you want to set, enter 'return' key to set: \n");
    while (1) {
        retv = uart_get_integer(&get_value);
        if (retv == TRUE)
            break;
        printf("\n!Invalid input! Please input intergers: \n");
    }
    pwm.prescale = get_value;

    printf("Please input the period you want to set, enter 'return' key to set: \n");
    while (1) {
        retv = uart_get_integer(&get_value);
        if (retv == TRUE)
            break;
        printf("\n!Invalid input! Please input intergers: \n");
    }
    pwm.period = get_value;

    printf("freq: %d, prescale %d, period %d\n", pwm.freq, pwm.prescale, pwm.period);

    pwm.instance = instance;
    pwm.sample = sample;
    pwm.smp_cnt = 3;
    pwm.interrupt = kPwmFifoEmptyIrq;
    g_pwm_test_end = FALSE;

    // Configure pins.
    pwm_iomux_config(instance);

    // Initialize PWM module 
    retv = pwm_init(&pwm);
    if (retv == FALSE) {
        printf("PWM init failed.\n");
        return retv;
    }
    printf("PWM output start.\n");

    // Enable PWM output 
    pwm_enable(instance);

    // Wait until FIFO empty 
    while (g_pwm_test_end == FALSE) ;

    // Disable PWM output 
    pwm_disable(instance);

    return retv;
}
