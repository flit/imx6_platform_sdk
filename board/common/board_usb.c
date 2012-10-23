/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * This function enables Vbus for the given USB port\n
 * The procedure to enable Vbus depends on both the Chip and board hardware\n
 *
 * @param port      USB module to initialize
 */
void usbEnableVbus(usb_module_t * port)
{

    switch (port->controllerID) {
    case OTG:
    case OTG1:
#ifdef BOARD_SABRE_AI
        // Vbus control is on I2C port expander C1 for the ARD board.
        max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 1);
#endif
#if defined(BOARD_EVB) || defined(BOARD_SMART_DEVICE)
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D22, ALT5);
        gpio_set_direction(GPIO_PORT3, 22, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 22, GPIO_HIGH_LEVEL);
#endif
#if defined(BOARD_EVK)
        BW_USBNC_USB_OTG1_CTRL_PWR_POL(1);
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_COL4, ALT6);
#endif

        break;
    case Host1:
    case OTG2:
#ifdef BOARD_SABRE_AI
        // Vbus control is on I2C port expander B7 for the ARD board.
        max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 1);
#endif

#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D31, ALT5);
        gpio_set_direction(GPIO_PORT3, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 31, GPIO_HIGH_LEVEL);
#endif
#ifdef BOARD_SMART_DEVICE
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D30, ALT5);
        gpio_set_direction(GPIO_PORT3, 30, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 30, GPIO_HIGH_LEVEL);
#endif
#if defined(BOARD_EVK)
        BW_USBNC_USB_OTG2_CTRL_PWR_POL(1);
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_COL5, ALT6);
#endif

        break;
    case Host2:
#ifdef BOARD_EVB

#endif
        break;
    case Host3:
        // Nothing to be done here.
        break;
    default:
        // no such controller
        break;
    }
}

/*!
 * This function disables Vbus for the given USB port\n
 * The procedure to enable Vbus depends on both the Chip and board hardware\n
 * This implementation is for the MX6q Sabre-AI board\n
 *
 * @param port      USB module to initialize
 */
void usbDisableVbus(usb_module_t * port)
{
    switch (port->controllerID) {
    case OTG:
#ifdef BOARD_SABRE_AI
        max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 0);
#endif
#if defined(BOARD_EVB) || defined(BOARD_SMART_DEVICE)
        gpio_set_level(GPIO_PORT3, 22, GPIO_LOW_LEVEL);
#endif
        break;
    case Host1:
#ifdef BOARD_SABRE_AI
        max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 0);
#endif
#ifdef BOARD_EVB
        gpio_set_level(GPIO_PORT3, 31, GPIO_LOW_LEVEL);
#endif
#ifdef BOARD_SMART_DEVICE
        gpio_set_level(GPIO_PORT3, 30, GPIO_LOW_LEVEL);
#endif
    case Host2:
#ifdef BOARD_EVB

#endif
        break;
    case Host3:
        // Nothing to be done here.
        break;
    default:
        // no such controller
        break;
    }
}

/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
