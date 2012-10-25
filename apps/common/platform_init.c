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
#include "board_io_expanders.h"
#include "platform_init.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! @brief Fills in the frequency info in each module's structure.
void freq_populate(void)
{
    int32_t i;
    hw_module_t *tmp;

    // Populate module frequency settings (important for UART driver)
    for (i = 0; (tmp = g_imx_modules[i]) != NULL; i++)
    {
        tmp->freq = get_module_freq(tmp->base);
    }
}

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
    board_ioexpander_init();
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
