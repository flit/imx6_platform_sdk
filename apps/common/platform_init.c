/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void platform_init(void)
{
    // Enable interrupts.
    gic_set_cpu_priority_mask(0xff);
    gic_cpu_enable(true);
    gic_enable(true);
    
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
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
