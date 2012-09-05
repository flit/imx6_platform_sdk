/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ds90ur124.c
 * @brief Driver and test for the deserializer DS90UR124 controlled through I2C.
 *
 * @ingroup diag_deserializer
 */

#include "hardware.h"

extern void adv7180_set_gpio_output(unsigned int, unsigned int);
extern void adv7180_i2c_init(void);
extern void adv7180_set_tristate_output(void);
void deserializer_io_config(void);

/*!
 * Init function of the deserializer DS90UR124.
 */
void ds90ur124_init(void)
{
    /* init the ADV7180 which handles PWRDN and OE signals
       of the DS90UR124 */
    adv7180_i2c_init();
    /* Data, hsync, and vsync signals are shared between
       the deserializer and video in chip */
    /* video in I/O placed in tri-state */
    adv7180_set_tristate_output();
    /* Enable power to DS90UR124 */
    adv7180_set_gpio_output(0, GPIO_HIGH_LEVEL);
    /* Enable receiver of DS90UR124 */
    adv7180_set_gpio_output(1, GPIO_HIGH_LEVEL);
    /* call hardware.h I/O init */
    deserializer_io_config();
}

/*!
 * This test uses a demo kit from National with a serializer DS90UR214.
 * A clock is connected at J1.TCLK of this board, and JP1 is removed to
 * avoid conneting RED signal of the USB cable to +5V.
 * The demo board is connected to the SABRE AI with a USB cable
 * The LED D56 is used to observe if DS90UR124' PLL is locked, if light up
 * it means the clock is correctly received and de-serialized.
 * Connect a cable to JP1.VDD of the demo board, the other side will
 * be sequentially connected to the asked contact of J1.
 * As long as the test runs, the value is received correctly on the
 * observed pin.
 */
void ds90ur124_receive_cnx_test(void)
{
    int i;

    /* IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC => (SW_MUX_BASE_ADDR + 0xac)
       IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT4 => (SW_MUX_BASE_ADDR + 0xb0)
       ...
       IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18 (SW_MUX_BASE_ADDR + 0xe8)
       IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19 (SW_MUX_BASE_ADDR + 0xec) */

    /* configure everything as an I/O and test it receives a high level
       CSI0_DAT[19:4]
       GPIO5_22 to GPIO5_31 */
    for (i = 0; i < 10; i++) {
        writel(ALT1, SW_MUX_BASE_ADDR + 0xb0 + i * 4);
        gpio_dir_config(GPIO_PORT5, 22 + i, GPIO_GDIR_INPUT);
        printf("  Please set serializer pin J1.%d to high\n", i);
        while (gpio_read_data(GPIO_PORT5, 22 + i) != 1) ;
    }

    /* GPIO6_0 to GPIO0_5 */
    for (i = 0; i < 6; i++) {
        writel(ALT1, SW_MUX_BASE_ADDR + 0xd8 + i * 4);
        gpio_dir_config(GPIO_PORT6, i, GPIO_GDIR_INPUT);
        printf("  Please set serializer pin J1.%d to high\n", i + 10);
        while (gpio_read_data(GPIO_PORT6, i) != 1) ;
    }

    /* GPIO5_19 <=> CSI0_HSYNC */
    writel(ALT1, SW_MUX_BASE_ADDR + 0xa4);
    gpio_dir_config(GPIO_PORT5, 19, GPIO_GDIR_INPUT);
    printf("  Please set serializer pin J1.22 to high\n");
    while (gpio_read_data(GPIO_PORT5, 19) != 1) ;

    /* GPIO5_21 <=> CSI0_VSYNC */
    writel(ALT1, SW_MUX_BASE_ADDR + 0xac);
    gpio_dir_config(GPIO_PORT5, 21, GPIO_GDIR_INPUT);
    printf("  Please set serializer pin J1.23 to high\n");
    while (gpio_read_data(GPIO_PORT5, 21) != 1) ;

    printf("Test is finished, you can get back to your doze state :-D\n");
}

/*!
 * The test reads some data from the deserializer on the CSI.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int ds90ur124_test_enable;
int ds90ur124_test_main(void)
{
    if (!ds90ur124_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("DE-SERIALIZER DS90UR124");

    printf(" Please ensure that the demo board is connected through a USB cable.\n");
    printf(" JP1 should be removed from this board.\n");
    printf
        (" A clock should be provided on J1.TCLK, and LED D56 of the SABRE AI should light up.\n");

    if (!is_input_char('y')) {
        return TEST_BYPASSED;
    }

    ds90ur124_init();
    ds90ur124_receive_cnx_test();

    // the test can't fail because the above function uses while conditions !
    return TEST_PASSED;
}

//RUN_TEST_INTERACTIVE("DE-SERIALIZER DS90UR124", ds90ur124_test_main)
