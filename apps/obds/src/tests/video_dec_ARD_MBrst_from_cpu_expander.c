/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "obds.h"
#include "hardware.h"

// adv7180 functions
extern void adv7180_i2c_init_obds(void);
extern unsigned char adv7180_reg_read(unsigned char reg_addr);
extern int adv7180_reg_write(unsigned char reg_addr, unsigned char data);
extern void adv7180_set_gpio_output(unsigned int io_x, unsigned int level);

int ard_mb_expander_reset_test_enable = 0;
int ard_mb_expander_reset_test(void)
{
    int result;

    if (!ard_mb_expander_reset_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("SABRE AI Main Board Reset via IO Expander", NULL);

    result = 0;                 // fail

    printf("\nChecking if IO expander GPIO can reset MB peripherals\n");
    /* blink LED1 and LED2 attached to gpios of the ADV7180 */

    adv7180_i2c_init_obds();
    adv7180_reg_write(0x00, 0x03);  //when reset will be set to 0

    // rset via io expander on CPU card
    /* toggle MAIN_PER_RST_B(PORT_EXP_A3) on Expander A  */
    max7310_set_gpio_output(0, 3, GPIO_LOW_LEVEL);  //expander a, io3
    hal_delay_us(500000);
    max7310_set_gpio_output(0, 3, GPIO_HIGH_LEVEL); //expander a, io3 

    if (adv7180_reg_read(0x00) == 0) {
        result = 1;             //test passed, adv7180 was reset
    }

    if (result != 0) {
        printf("    MB Reset via CPU IO expander test passed \n");
        return TEST_PASSED;
    } else {
        printf("    **MB Reset via CPU IO expander failed \n");
        return TEST_FAILED;
    }
}

//RUN_TEST("SABRE AI MB Reset via Expander", ard_mb_expander_reset_test)
