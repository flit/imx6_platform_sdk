/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "obds.h"
#include "hardware.h"
#include "gpio_define.h"
#include "io.h"

extern void android_buttons_iomux_config(void); // define in hardware.c

void configure_android_button(u32 base_address, u32 gpio_number)
{
    int temp;

    /* if the base address is DUMMY_VALUE_NOT_USED, there's no button for that function */
    if (base_address != DUMMY_VALUE_NOT_USED)
    {
        temp = readl(base_address + GPIO_GDIR0_OFFSET);
        writel(temp & (~(1 << gpio_number)), base_address + GPIO_GDIR0_OFFSET); // set dir to input
    
        // set ICR register to falling-edge sensitive, since pushing button pulls gpio to GND
        if (gpio_number > 15) {
            writel(GPIO_ICR_FALL_EDGE << ((gpio_number - 16) * 2), base_address + GPIO_ICR2_OFFSET);    // GPIOs 16-31 use ICR2 reg
        } else {                    //gpio less than 16
            writel(GPIO_ICR_FALL_EDGE << (gpio_number * 2), base_address + GPIO_ICR1_OFFSET);   // GPIOs 0-15 use ICR1 reg
        }
    
        // enable GPIO interrupt within the module this does not cuase interrupts to trigger to ARM core unless also enabled in TZIC
        temp = readl(base_address + GPIO_IMR_OFFSET);
        writel(temp | (1 << gpio_number), base_address + GPIO_IMR_OFFSET);
    
        // w1c, clear initial status in-case set
        writel((1 << gpio_number), base_address + GPIO_ISR_OFFSET);
    }
}

/*!
 * Initialize gpios for the android buttons
 *
 */
void init_android_buttons(void)
{
    android_buttons_iomux_config(); // configure iomux, defined in hardware.c hw specific
    // configure GPIOs as interrupts
    // the button defines used are declared in hardware.h (HW specific)
    // HOME_BUTTON_GOPIO_BASE, HOME_BUTTON_GPIO_NUM, BACK_GPIO_BASE, BACK_BUTTON_GPIO_NUM .. etc
    // making it generic to GPIO base address and GPIO number because in future 
    // these can be mapped to any GPIO and may not necessarily be same GPIO for all HW
    configure_android_button(HOME_BUTTON_GOPIO_BASE, HOME_BUTTON_GPIO_NUM);
    configure_android_button(BACK_BUTTON_GOPIO_BASE, BACK_BUTTON_GPIO_NUM);
    configure_android_button(PROG_BUTTON_GOPIO_BASE, PROG_BUTTON_GPIO_NUM);
    configure_android_button(VOLPLUS_BUTTON_GOPIO_BASE, VOLPLUS_BUTTON_GPIO_NUM);
    configure_android_button(VOLNEG_BUTTON_GOPIO_BASE, VOLNEG_BUTTON_GPIO_NUM);
}

void check_android_button_status(void)
{
    int i;
    // first add some debouncing delay, flag will be set no matter how long wait since its an interrupt trigger
    for (i = 0; i < 200000; i++) ;
    if ((1 << HOME_BUTTON_GPIO_NUM) & readl(HOME_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET)) {
        printf("  HOME button pressed \n");
        // w1c, clear initial status in-case set
        writel((1 << HOME_BUTTON_GPIO_NUM), HOME_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET);
    }

    if ((1 << BACK_BUTTON_GPIO_NUM) & readl(BACK_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET)) {
        printf("  BACK button pressed \n");
        // w1c, clear initial status in-case set
        writel((1 << BACK_BUTTON_GPIO_NUM), BACK_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET);
    }

    if ((1 << PROG_BUTTON_GPIO_NUM) & readl(PROG_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET)) {
        printf("  PROG button pressed \n");
        // w1c, clear initial status in-case set
        writel((1 << PROG_BUTTON_GPIO_NUM), PROG_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET);
    }

    if ((1 << VOLPLUS_BUTTON_GPIO_NUM) & readl(VOLPLUS_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET)) {
        printf("  VOL+ button pressed \n");
        // w1c, clear initial status in-case set
        writel((1 << VOLPLUS_BUTTON_GPIO_NUM), VOLPLUS_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET);
    }

    if ((1 << VOLNEG_BUTTON_GPIO_NUM) & readl(VOLNEG_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET)) {
        printf("  VOL- button pressed \n");
        // w1c, clear initial status in-case set
        writel((1 << VOLNEG_BUTTON_GPIO_NUM), VOLNEG_BUTTON_GOPIO_BASE + GPIO_ISR_OFFSET);
    }
}

/*!
 * @return      TEST_PASSED or  TEST_FAILED    
 */
int android_buttons_test_enable = 0;    // global test flag, set in imx##.c platform_init function
int android_buttons_test(void)
{
    unsigned char input;

    if (!android_buttons_test_enable) {
        return TEST_NOTPRESENT;
    }
    PROMPT_RUN_TEST("ANDROID BUTTONS");

    printf("Press all the Android buttons (on SABRE AI main board) you wish to test\n");
    printf("Pressing each button should result in an equivalent unique message to screen\n");
    printf("Pressing any key on the keyboard exits this test\n");
    while (1) {
        check_android_button_status();
        input = getchar();
//        input = receive_char();
        if (input != NONE_CHAR)
            break;
    }

    printf("Did you get unique message for HOME, PROG, VOL+, VOL-, and BACK buttons? [y/n]\n");
	input = getchar();
	input = getchar();

//    input = receive_char();     //this was last key pressed to exit test
//    input = receive_char();     // get yes/no reply
    if (is_input_char('y')) {
        printf("  ANDROID BUTTONS test passed \n");
        return TEST_PASSED;
    }
    //if (input == 'y' || input == 'Y') {
    //    printf("  ANDROID BUTTONS test passed \n");
    //    return TEST_PASSED;
    //}
    printf("  ** ANDROID BUTTONS test failed ** \n");
    return TEST_FAILED;
}

//RUN_TEST("ANDROID BUTTONS", android_buttons_test)
