/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mx6dq.c
 * @brief platform_init() function
 *
 * @ingroup diag_init
 */

#include <stdio.h>
#include "hardware.h"
#include "version.h"

int board_id = 0;
int board_rev = 0;

static char board_name[20];
static char board_revision[20];
static char chip_name[20];

/*!
 * print out the diag release version info
 */
static void mx6dq_print_ver(void)
{
    // read the ROM Version to decide the SoC version
    switch (readl(0x48) & 0xFF) {
    case 0x10:
        sprintf(chip_name, "i.MX6DQ TO1.0");
        break;
    default:
        sprintf(chip_name, "i.MX6QD TOx.x");
    }

    if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_ARD)
        sprintf(board_name, "SABRE Auto");
    else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_SMART_DEVICE)
        sprintf(board_name, "SABRE Smart Device (SD)");
    else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_SABRE_LITE)
        sprintf(board_name, "Sabre-Lite Board");
    else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_EVB)
        sprintf(board_name, "Armadillo EVB");
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

    /* Initialize clock sources, dividers, ... */
    ccm_init();
    /* Configure the EPIT timer used for system delay function. */
    system_time_init();
    /* populate the freq member of the referenced hw_module in mx6dq_module */
    freq_populate();

    /* Initialize the debug/console UART */
    uart_init(&g_debug_uart, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);
    /* flush UART RX FIFO */
    do {
        c = uart_getchar(&g_debug_uart);
    } while (c != NONE_CHAR);

    /* Some init for the board */
    board_init();

    mx6dq_print_ver();

    board_id = BOARD_TYPE_ID;
    board_rev = BOARD_VERSION_ID;

    show_freq();
    show_ddr_config();
}

#ifdef ALL_TEST_ENABLE
extern void sdma_test(void);
extern void ipu_test(void);
extern void uart_test(void);
extern void gpt_test(void);
extern void epit_test(void);
extern void usdhc_test(void);
extern void hdmi_test(void);
extern void audio_test(void);
extern void i2c_test(void);
extern void gic_test(void);
extern int sata_test(void);
extern void snvs_rtc_test(void);
extern void snvs_srtc_test(void);
extern void flexcan_test(void);
extern int spi_test(void);
extern int vpu_test(void);
extern int gpmi_test(void);
extern int mipi_test();

void ALL_test(void)
{
    uint8_t gic_test_done = 0;

    while (1) {
        printf("Starting the tests suite...\n");
        audio_test();
#ifdef MX6DQ_ARD
        flexcan_test();
#endif /* MX6DQ_ARD */
        epit_test();

        gpt_test();
        hdmi_test();
        i2c_test();
        ipu_test();
#ifndef MX6DQ_SMART_DEVICE
        mipi_test();
#endif /* MX6DQ_SMART_DEVICE */
        sata_test();
        sdma_test();
        snvs_rtc_test();
        snvs_srtc_test();
#ifdef MX6DQ_EVB
//         gpmi_test();
        spi_test();
        vpu_test();
#endif /* MX6DQ_EVB */
        uart_test();
        usdhc_test();

        /* GIC test can only be executed once, and requires a board reset */
        if (gic_test_done == 0) {
            gic_test_done = 0xFF;
            gic_test();
        }
        printf("\n...end of the tests suite.\n");
    }
}
#endif /* ALL_TEST_ENABLE */
