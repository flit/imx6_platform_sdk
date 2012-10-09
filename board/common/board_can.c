/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "registers/regsflexcan.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * board dependent IOMUX configuration functions
 */
void hw_can_iomux_config(uint32_t module_instance)
{

#ifdef BOARD_SABRE_AI
    /* CAN_EN active high output */
    max7310_set_gpio_output(1, 6, GPIO_HIGH_LEVEL); //expander b, io6

    /* CAN_STBY active high output */
    max7310_set_gpio_output(1, 5, GPIO_HIGH_LEVEL); //expander b, io5 
#endif

    can_iomux_config(module_instance);

#ifdef BOARD_SABRE_AI
    switch (module_instance)
    {
    case HW_FLEXCAN1:
        /* Select CAN, ENET_CAN1_STEER(PORT_EXP_B3) */
        max7310_set_gpio_output(1, 3, GPIO_HIGH_LEVEL); //expander b, io3
        /* Select ALT5 mode of GPIO_4 for GPIO1_4 - CAN1_NERR_B */
        /* active low input */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
        gpio_set_direction(GPIO_PORT1, 4, GPIO_GDIR_INPUT);
        break;

    case HW_FLEXCAN2:
        /* Select ALT5 mode of SD4_DAT3 for GPIO2_11 - CAN2_NERR_B */
        /* active low input */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
        gpio_set_direction(GPIO_PORT2, 11, GPIO_GDIR_INPUT);
        break;

    default:
        printf("ERR: invalid FLEXCAN instance for iomux config\n");
        break;
    }
#endif
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
