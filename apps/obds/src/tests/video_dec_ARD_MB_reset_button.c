/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "hardware.h"
//#include "imx_i2c.h"

// adv7180 functions
extern void adv7180_i2c_init(void);
extern unsigned char adv7180_reg_read(unsigned char reg_addr);
extern int adv7180_reg_write(unsigned char reg_addr, unsigned char data);
extern void adv7180_set_gpio_output(unsigned int io_x, unsigned int level);

int ard_mb_reset_test_enable = 0;
int ard_mb_reset_test(void)
{
    int result, time;

    if (!ard_mb_reset_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("SABRE AI Main Board Reset Button");

    result = 0;                 // fail

    time = 10;
    printf("\nLED1 and LED2 around ADV7180/U29 will stop blinking after\n");
    printf(" pressing MB Reset button (SW2) on SABRE AI main board. \n");
    printf(" You only have %d seconds to hit the button, so make haste! \n", time);
    /* blink LED1 and LED2 attached to gpios of the ADV7180 */

    adv7180_i2c_init();
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
