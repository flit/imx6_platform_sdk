/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "obds.h"
#include "gpio/gpio.h"
#include "io.h"

static const char * const test_name = "ANDROID BUTTONS Test";

extern void android_buttons_iomux_config(void); // define in hardware.c

void configure_android_button(int32_t gpio_port, int32_t gpio_pin)
{
    /* If the base address is DUMMY_VALUE_NOT_USED, there's no button for that function */
    if (gpio_port != GPIO_NONE)
    {
        // Set direction to input.
        gpio_set_direction(gpio_port, gpio_pin, GPIO_GDIR_INPUT);
    
        // Set ICR register to falling-edge sensitive, since pushing button pulls gpio to GND.
        gpio_set_interrupt_config(gpio_port, gpio_pin, GPIO_ICR_FALL_EDGE);
    
        // Enable GPIO interrupt within the module this does not cause interrupts to trigger
        // to ARM core unless also enabled in TZIC.
        gpio_set_interrupt_mask(gpio_port, gpio_pin, GPIO_IMR_UNMASKED);

        // Clear initial status in-case set.
        gpio_clear_interrupt(gpio_port, gpio_pin);
    }
}

/*!
 * Initialize gpios for the android buttons
 *
 */
void init_android_buttons(void)
{
	// Configure iomux, defined in hardware.c (HW specific)
	android_buttons_iomux_config();

    // Configure GPIOs as interrupts.
    // The button defines used are declared in hardware.h (HW specific)
    // HOME_BUTTON_GPIO_INST, HOME_BUTTON_GPIO_NUM, BACK_GPIO_INST, BACK_BUTTON_GPIO_NUM .. etc
    // Making it generic to GPIO instance and GPIO number because in future
    // these can be mapped to any GPIO and may not necessarily be same GPIO for all HW.
    configure_android_button(HOME_BUTTON_GPIO_INST, HOME_BUTTON_GPIO_NUM);
    configure_android_button(BACK_BUTTON_GPIO_INST, BACK_BUTTON_GPIO_NUM);
    configure_android_button(PROG_BUTTON_GPIO_INST, PROG_BUTTON_GPIO_NUM);
    configure_android_button(VOLPLUS_BUTTON_GPIO_INST, VOLPLUS_BUTTON_GPIO_NUM);
    configure_android_button(VOLMINUS_BUTTON_GPIO_INST, VOLMINUS_BUTTON_GPIO_NUM);
}

void check_android_button_status(const char* const indent)
{
    int i;
    // first add some debouncing delay, flag will be set no matter how long wait since its an interrupt trigger
    for (i = 0; i < 200000; i++) ;

    if ( gpio_get_interrupt_status(HOME_BUTTON_GPIO_INST, HOME_BUTTON_GPIO_NUM) == GPIO_ISR_ASSERTED )
    {
        printf("%s  HOME button pressed.\n", indent);
        // Clear interrupt.
        gpio_clear_interrupt(HOME_BUTTON_GPIO_INST, HOME_BUTTON_GPIO_NUM);
    }

    if ( gpio_get_interrupt_status(BACK_BUTTON_GPIO_INST, BACK_BUTTON_GPIO_NUM) == GPIO_ISR_ASSERTED )
    {
        printf("%s  BACK button pressed \n", indent);
        // Clear interrupt.
        gpio_clear_interrupt(BACK_BUTTON_GPIO_INST, BACK_BUTTON_GPIO_NUM);
    }

    if ( gpio_get_interrupt_status(PROG_BUTTON_GPIO_INST, PROG_BUTTON_GPIO_NUM) == GPIO_ISR_ASSERTED )
    {
        printf("%s  PROG button pressed \n", indent);
        // Clear interrupt.
        gpio_clear_interrupt(PROG_BUTTON_GPIO_INST, PROG_BUTTON_GPIO_NUM);
    }

    if ( gpio_get_interrupt_status(VOLPLUS_BUTTON_GPIO_INST, VOLPLUS_BUTTON_GPIO_NUM) == GPIO_ISR_ASSERTED )
    {
        printf("%s  VOL+ button pressed \n", indent);
        // Clear interrupt.
        gpio_clear_interrupt(VOLPLUS_BUTTON_GPIO_INST, VOLPLUS_BUTTON_GPIO_NUM);
    }

    if ( gpio_get_interrupt_status(VOLMINUS_BUTTON_GPIO_INST, VOLMINUS_BUTTON_GPIO_NUM) == GPIO_ISR_ASSERTED )
    {
        printf("%s  VOL- button pressed \n", indent);
        // Clear interrupt.
        gpio_clear_interrupt(VOLMINUS_BUTTON_GPIO_INST, VOLMINUS_BUTTON_GPIO_NUM);
    }
}

/*!
 * @return      TEST_PASSED or  TEST_FAILED    
 */
menu_action_t android_buttons_test(const menu_context_t* context, void* param)
{
	const char* const indent = menu_get_indent(context);

    if ( prompt_run_test(test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }

    printf("%sPress all the Android buttons (on SABRE AI main board) you wish to test\n", indent);
    printf("%sPressing each button should result in an equivalent unique message to screen\n", indent);
    printf("%sPressing any key on the keyboard exits this test\n", indent);
    while (1)
    {
        check_android_button_status(indent);

        char key_pressed = fgetc(stdin);
        if (key_pressed != NONE_CHAR)
            break;
    }

    printf("%sDid you get unique message for HOME, PROG, VOL+, VOL-, and BACK buttons?\n", indent);
    if (is_input_char('y', indent))
    {
        print_test_passed(test_name, indent);

        *(test_return_t*)param = TEST_PASSED;
        return MENU_CONTINUE;
    }
    else
    {
        print_test_failed(test_name, indent);

        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;
    }
}
