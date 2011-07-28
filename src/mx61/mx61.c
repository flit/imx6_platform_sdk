/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mx61.c
 * @brief platform_init() function
 *
 * @ingroup diag_init
 */

#include <stdio.h>
#include "hardware.h"
#include "version.h"

// #define OBDS_FUSE_CONTROL   Leaving out for bring-up

extern void init_debug_uart(struct hw_module *uart, uint32_t baud);
extern struct hw_module uart4;
static struct hw_module *debug_uart = &uart4;   // on iMX61 UART4 is debug UART

int board_id = 0;
int board_rev = 0;

static char board_name[20];
static char board_revision[20];
static char chip_name[20];

/*!
 * print out the diag release version info
 */
static void mx61_print_ver(void)
{
    // read the ROM Version to decide the SoC version
    switch (readl(0x48) & 0xFF) {
    case 0x10:
        sprintf(chip_name, "i.MX61 TO1.0");
        break;
    default:
        sprintf(chip_name, "i.MX6QD TOx.x");
    }

    if (BOARD_TYPE_ID == BOARD_ID_MX61_ARD)
        sprintf(board_name, "Sabre Auto");
    else if (BOARD_TYPE_ID == BOARD_ID_MX61_SMD)
        sprintf(board_name, "SABRE Tablet");
    else
        sprintf(board_name, "UNKNOWN    Board ID!");

    if (BOARD_VERSION_ID == BOARD_VERSION_1)
        sprintf(board_revision, "Rev A");
    else if (BOARD_VERSION_ID == BOARD_VERSION_2)
        sprintf(board_revision, "Rev B");
    else if (BOARD_VERSION_ID == BOARD_VERSION_3)
        sprintf(board_revision, "Rev C");
    else if (BOARD_VERSION_ID == BOARD_VERSION_4)
        sprintf(board_revision, "Rev D");
    else if (BOARD_VERSION_ID == BOARD_VERSION_5)
        sprintf(board_revision, "Rev E");
    else
        sprintf(board_revision, "UNKNOWN Board Rev!");

    print_ver(chip_name, board_name, board_revision);
}

void platform_init(void)
{
    uint8_t c;
    int temp, display = 0;

    // prog_pll();   NEEDS TO BE UPDATED FOR MX6qd
    freq_populate();
    /*
     * Note, board type is determined at compile time such that the UART and
     * board can be initialized prior to burning fuses
     */
    board_init();
    init_debug_uart(debug_uart, 115200);
    // flush out UART RX FIFO
    do {
        c = receive_char();
    } while (c != NONE_CHAR);

    mx61_print_ver();

#ifdef OBDS_FUSE_CONTROL
    board_id = readl(IIM_BASE_ADDR + 0x87c);
    board_rev = readl(IIM_BASE_ADDR + 0x878);
#else
    board_id = BOARD_TYPE_ID;
    board_rev = BOARD_VERSION_ID;
#endif

    show_freq();
    show_ddr_config();
}

void ALL_test(void)
{

    sdma_test();

}
