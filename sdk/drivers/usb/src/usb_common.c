/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file usb_common.c
 * @brief USB common routines.
 */
/*! This routine returns the current speed of the port\n
 * This must be called after the bus reset is completed.
 *
 * @param	port			The usb controller
 * @return	usbPortSpeed	The operating speed full/high
 */

#include "usb/usb.h"
#include <stdio.h>

usbPortSpeed_t usb_get_port_speed(usb_module_t * port)
{
    usbPortSpeed_t speed;
    uint32_t core = (uint32_t)port->controllerID;

    /* Determine the speed we are connected at. */
    switch (BG_USBC_UH1_PORTSC1_PSPD(HW_USBC_PORTSC1_RD(core))) { 
    case usbSpeedFull:
        speed = usbSpeedFull;
        printf("Connected at full-speed\n");
        break;
    case usbSpeedLow:
        speed = usbSpeedLow;
        printf("Connected at low-speed\n");
        break;
    case usbSpeedHigh:
        speed = usbSpeedHigh;
        printf("Connected at high-speed\n");
        break;
    default:
        speed = usbSpeedUnknown;
        printf("Invalid port speed\n");
        break;
    }
    printf("PORTSC = 0x%08x\n", HW_USBC_PORTSC1_RD(core));

    return speed;
}

/*!
 * This routine performs a byte swap on a 32-bit word
 *
 * @param data
 * @return	Swapped data
 */
uint32_t swap32(uint32_t data)
{
    uint32_t temp = 0;

    temp = (data & 0xff) << 24;
    temp |= ((data & 0xff00) << 8);
    temp |= ((data & 0xff0000) >> 8);
    temp |= ((data & 0xff000000) >> 24);

    return (temp);
}

/*!
 * This function displays a menu and waits for an input char to be received from the UART.\n
 * If the character is a numeric value within the table range, the entry number is returned.
 *
 * @param   *menu_table   the table containing the menu items
 * @return  menu_item     the table entry of the selected item
 *
 */
int get_menu_item(char *menu_table[])
{
    uint8_t input;
    int i, menu_item, num_items;

    for (i = 0; *menu_table[i] != '\0'; i++) {
        printf("%d. %s\n", i, menu_table[i]);
    }
    num_items = i;

    menu_item = -1;
    while (menu_item == -1) {
        printf("Select > ");

        do {
            input = getchar();
        } while (input == NONE_CHAR);   // wait for a character

        if ((input >= '0') && (input <= '9')) {
            menu_item = input - '0';
            if (menu_item < num_items) {
                printf("%1d\n", menu_item);
                return (menu_item);
            } else
                menu_item = -1;
        }
    }
    return (menu_item);
}
