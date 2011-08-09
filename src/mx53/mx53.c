/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
/*!
 * @file  mx53.c
 * @brief platform_init() function
 *
 * @ingroup diag_init
 */

#include <stdio.h>
#include "hardware.h"
#include "version.h"

#define SDK_FUSE_CONTROL

extern void init_debug_uart(struct hw_module *uart, uint32_t baud);
extern struct hw_module uart1;
static struct hw_module *debug_uart = &uart1;
int auto_run_enable = 0;

int set_mac(void);
int board_id = 0;
int board_rev = 0;
extern pmic_mc13892_reg_t pmic_mc13892_reg;
extern unsigned int mc13892_i2c_reg(unsigned int reg, unsigned int val, unsigned int dir);
extern int set_mac(void);
extern void program_board_id_fuses(char *chip);
extern void prog_pll(void);

static char board_name[20];
static char board_revision[20];
static char chip_name[20];

/*!
 * print out the diag release version info
 */
static void mx53_print_ver(void)
{
    // read the ROM Version to decide the SoC version
    switch (readl(0x48) & 0xFF) {
    case 0x10:
        sprintf(chip_name, "i.MX53 TO1.0");
        break;
    case 0x20:
        sprintf(chip_name, "i.MX53 TO2.0");
        break;
    default:
        sprintf(chip_name, "i.MX53 TOx.x");
    }

    if (BOARD_TYPE_ID == BOARD_ID_MX53_CPU2)
        sprintf(board_name, "CPU2");
    else if (BOARD_TYPE_ID == BOARD_ID_MX53_ARD)
        sprintf(board_name, "SABRE Auto");
    else if (BOARD_TYPE_ID == BOARD_ID_MX53_SBRTH_LCB)
        sprintf(board_name, "Quick Start");
    else if (BOARD_TYPE_ID == BOARD_ID_MX53_SBRTH_SMD)
        sprintf(board_name, "SABRE Tablet");
    else if (BOARD_TYPE_ID == BOARD_ID_MX53_EVK)
        sprintf(board_name, "EVK");
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

volatile int ard_cpu_only_test = 0;

void platform_init(void)
{
    uint8_t c;

    prog_pll();
    freq_populate();
    /*
     * Note, board type is determined at compile time such that the UART and
     * board can be initialized prior to burning fuses
     */
    board_init();
    init_debug_uart(debug_uart, 115200);
    // flush out UART RX FIFO
    do {
        c = uart_receive_char();
    } while (c != NONE_CHAR);

    mx53_print_ver();

#ifdef SDK_FUSE_CONTROL
    board_id = readl(IIM_BASE_ADDR + 0x87c);
    board_rev = readl(IIM_BASE_ADDR + 0x878);
#else
    board_id = BOARD_TYPE_ID;
    board_rev = BOARD_VERSION_ID;
#endif

}
