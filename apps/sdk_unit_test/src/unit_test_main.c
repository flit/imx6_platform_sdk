/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "version.h"
#include "cortex_a9.h"
#include "mmu.h"

extern int SDK_TEST(void);

int32_t board_id = 0;
int32_t board_rev = 0;

static char board_name[20];
static char board_revision[20];
static char chip_name[20];

/*!
 * @brief Print out the release version info.
 */
static void print_version(void)
{
    // read the ROM Version to decide the SoC version
    switch (readl(0x48) & 0xFF) {
    case 0x10:
        sprintf(chip_name, "i.MX6DQ TO1.0");
        break;
    default:
        sprintf(chip_name, "i.MX6QD TOx.x");
    }

//     if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_SABRE_AI)
//         sprintf(board_name, "SABRE Auto");
//     else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_SMART_DEVICE)
//         sprintf(board_name, "SABRE Smart Device (SD)");
//     else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_SABRE_LITE)
//         sprintf(board_name, "Sabre-Lite Board");
//     else if (BOARD_TYPE_ID == BOARD_ID_MX6DQ_EVB)
//         sprintf(board_name, "Armadillo EVB");
//     else
//         sprintf(board_name, "UNKNOWN    Board ID!");
// 
//     if (BOARD_VERSION_ID == BOARD_VERSION_1)
//         sprintf(board_revision, "Rev A");
//     else if (BOARD_VERSION_ID == BOARD_VERSION_2)
//         sprintf(board_revision, "Rev B");
//     else if (BOARD_VERSION_ID == BOARD_VERSION_3)
//         sprintf(board_revision, "Rev C");
//     else if (BOARD_VERSION_ID == BOARD_VERSION_4)
//         sprintf(board_revision, "Rev D");
//     else if (BOARD_VERSION_ID == BOARD_VERSION_5)
//         sprintf(board_revision, "Rev E");
//     else
//         sprintf(board_revision, "UNKNOWN Board Rev!");

    print_ver(chip_name, board_name, board_revision);
}

void platform_init(void)
{
    // Initialize clock sources, dividers, ... 
    ccm_init();
    
    // Configure the EPIT timer used for system delay function. 
    system_time_init();
    
    // populate the freq member of the referenced hw_module in mx6dq_module 
    freq_populate();

    // Initialize the debug/console UART 
    uart_init(&g_debug_uart, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);

    // flush UART RX FIFO 
    uint8_t c;
    do {
        c = uart_getchar(&g_debug_uart);
    } while (c != NONE_CHAR);

    // Some init for the board 
    board_init();

    print_version();

    board_id = BOARD_TYPE_ID;
    board_rev = BOARD_VERSION_ID;

    show_freq();
    show_ddr_config();
}

/*!
 * main function that decides which tests to run and prompts the user before
 * running test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
    // Enable interrupts.
    gic_set_cpu_priority_mask(0xff);
    gic_cpu_enable(true);
    gic_enable(true);

    enable_neon_fpu();

#if defined(BOARD_EVB)||defined(BOARD_SMART_DEVICE)
    system_memory_arrange();
    disable_strict_align_check();
#endif

    platform_init();

    SDK_TEST();

    _sys_exit(0);

    return 0;
}
