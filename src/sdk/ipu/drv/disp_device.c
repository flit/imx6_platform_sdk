/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file ipu_common.c
 * @brief common functions defination of IPU.
 * @ingroup diag_ipu
 */

#include <string.h>
#include "ipu_common.h"
#include "hardware.h"

void ldb_config(int bit_mode)
{
    char recvCh = NONE_CHAR;

    /*LVDS panel test */
    printf("Please select LVDS port to use:\n");
    printf("\t0 - LVDS port 0\n");
    printf("\t1 - LVDS port 1\n");
    printf("\t2 - LVDS port 0 and port 1\n");
    printf("\t3 - LVDS port 0 and port 1 in split mode\n");

    do {
        recvCh = uart_receive_char(&debug_uart);

        if (recvCh == '0') {
            /* enable DI0 on LVDS port 0 */
            writel(0x0001 | (bit_mode << 5), IOMUXC_GPR2);
            break;
        } else if (recvCh == '1') {
            /* enable DI0 on LVDS port 1 */
            writel(0x0004 | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '2') {
            /* enable DI0 on both LVDS ports */
            writel(0x0005 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '3') {
            /* enable DI0 on LVDS port 0 and 1 in split mode */
            writel(0x0015 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        }
    }
    while (1);

}

void display_device_init(void)
{
    ldb_iomux_config();
    ldb_clock_config(65000000);
    lvds_power_on();
    ldb_config(0);
}
