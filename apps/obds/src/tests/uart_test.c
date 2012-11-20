/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
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

/*!
 * @file uart_test.c
 * @brief UART driver unit test.
 * @ingroup diag_uart
 */

#include <stdio.h>
#include "obds.h"
#include "soc_memory_map.h"
#include "irq_numbers.h"
#include "uart/imx_uart.h"

void uart_interrupt_handler(void);

/* UART3 port is free for i.MX6DQ/SDL and i.MX53 platforms */
static hw_module_t uart_port = {
    "UART3 for test",
    3,
    UART3_BASE_ADDR,
    27000000,
    IMX_INT_UART3,
    &uart_interrupt_handler,
};

static volatile uint8_t g_wait_for_irq;

static const char * const uart_test_name = "UART Test";

/*! 
 * UART interrupt handler.
 *
 * @return  none
 */
void uart_interrupt_handler(void)
{
    uint8_t read_char;

    read_char = uart_getchar(&uart_port);
    printf("IRQ subroutine of tested UART - Read char is %c\n", read_char);
    g_wait_for_irq = 0;
}

/*! 
 * UART test. The tested port is configured to generate an IRQ everytime
 * a data is received. The port is configured in loopback.
 * The debug/console port is used to receive a character typed in a terminal.
 * This character is sent to the tested UART Tx FIFO, and the IRQ routine
 * triggered when the data is received display this character to the terminal.
 * It is like an echo test which uses the tested UART for the echo.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
test_return_t uart_test(void)
{
    uint8_t sel;
    
	const char* const indent = menu_get_indent();

    if ( prompt_run_test(uart_test_name, indent) != TEST_CONTINUE )
    	return TEST_BYPASSED;

    printf("\n%s---- Running UART test, type 'x' to exit.\n", indent);

    /* Initialize the UART port */
    uart_init(&uart_port, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);
    /* Set the IRQ mode for the Rx FIFO */
    uart_set_FIFO_mode(&uart_port, RX_FIFO, 1, IRQ_MODE);
    /* Enable loopback mode */
    uart_set_loopback_mode(&uart_port, TRUE);
    /* Set the ISR and enable the interrupts for UART3 */
    uart_setup_interrupt(&uart_port, TRUE);

    do {
        g_wait_for_irq = 1;
        printf("%sPlease type x to exit:\n", indent);
        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("%s\nTest exit.\n", indent);
            /* Disable the interrupts for UART3 */
            uart_setup_interrupt(&uart_port, FALSE);
            break;
        }

        /* send the character to the tested UART */
        /* it will be displayed once read in the tested UART ISR */
        uart_putchar(&uart_port, &sel);
        /* wait for ISR to clear the flag before continuing */
        while (g_wait_for_irq == 1) ;

    } while (1);

    return TEST_PASSED;
}
