/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
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

#include "sdk.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Enables Vbus for the given USB port.
 *
 * The procedure to enable Vbus depends on both the Chip and board hardware.
 *
 * @param port      USB module to initialize
 *
 * @todo Need to implement for MX6SL EVK.
 */
void usbEnableVbus(usb_module_t * port)
{
    switch (port->controllerID)
    {
    case OTG:
    case OTG1:		// MX6SL first OTG controller.
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
    case OTG2:		// MX6SL second OTG controller
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
 * @brief Disables Vbus for the given USB port
 *
 * The procedure to enable Vbus depends on both the Chip and board hardware.
 *
 * @param port      USB module to initialize
 *
 * @todo Need to implement for MX6SL EVK.
 */
void usbDisableVbus(usb_module_t * port)
{
    switch (port->controllerID)
    {
    case OTG:
    case OTG1:		// MX6SL first OTG controller.
#ifdef BOARD_SABRE_AI
        max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 0);
#endif
#if defined(BOARD_EVB) || defined(BOARD_SMART_DEVICE)
        gpio_set_level(GPIO_PORT3, 22, GPIO_LOW_LEVEL);
#endif
        break;
        
    case Host1:
    case OTG2:		// MX6SL first OTG controller.
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
