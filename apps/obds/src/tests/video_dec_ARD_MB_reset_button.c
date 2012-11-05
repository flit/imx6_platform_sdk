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

#include "obds.h"

// adv7180 functions
extern void adv7180_i2c_init_obds(void);
extern unsigned char adv7180_reg_read(unsigned char reg_addr);
extern int adv7180_reg_write(unsigned char reg_addr, unsigned char data);
extern void adv7180_set_gpio_output(unsigned int io_x, unsigned int level);

int ard_mb_reset_test_enable = 0;
int ard_mb_reset_test(void)
{
    int result, time;

    if (!ard_mb_reset_test_enable) {
        return TEST_NOT_PRESENT;
    }

    PROMPT_RUN_TEST("SABRE AI Main Board Reset Button", NULL);

    result = 0;                 // fail

    time = 10;
    printf("\nLED1 and LED2 around ADV7180/U29 will stop blinking after\n");
    printf(" pressing MB Reset button (SW2) on SABRE AI main board. \n");
    printf(" You only have %d seconds to hit the button, so make haste! \n", time);
    /* blink LED1 and LED2 attached to gpios of the ADV7180 */

    adv7180_i2c_init_obds();
    adv7180_reg_write(0x00, 0x03);  //when reset will be set to 0
    printf(" time left: %ds..............................\n", time--);
    do {
        adv7180_set_gpio_output(2, GPIO_LOW_LEVEL);
        adv7180_set_gpio_output(3, GPIO_LOW_LEVEL);
        hal_delay_us(500000);
        adv7180_set_gpio_output(2, GPIO_HIGH_LEVEL);
        adv7180_set_gpio_output(3, GPIO_HIGH_LEVEL);
        hal_delay_us(500000);
        printf(" %ds.............................................\n", time--);
        if (adv7180_reg_read(0x00) == 0) {
            result = 1;         //test passed, adv7180 was reset
            break;
        }
    }
    while (time != 0);
    printf("\n");

    if (result != 0) {
        printf("    MB Reset button test passed \n");
        return TEST_PASSED;
    } else {
        printf("    **MB Reset button test failed \n");
        return TEST_FAILED;
    }
}

//RUN_TEST("SABRE AI MB Button", ard_mb_reset_test)
