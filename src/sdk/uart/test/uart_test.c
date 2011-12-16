/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file uart_test.c
 * @brief UART driver unit test.
 * @ingroup diag_uart
 */

#include <stdio.h>
#include "uart_test.h"

/* UART3 port is free for i.MX61 and i.MX53 platforms */
static struct hw_module uart_port = {
    "UART3 for test",
    UART3_BASE_ADDR,
    27000000,
    IMX_INT_UART3,
    &uart_interrupt_handler,
};

static uint8_t g_wait_flag;

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
    g_wait_flag = 0;
}

/*! 
 * UART test. The tested port is configured to generate an IRQ everytime
 * a data is received. The port is configured in loopback.
 * The debug/console port is used to receive a character typed in a terminal.
 * This character is sent to the tested UART Tx FIFO, and the IRQ routine
 * triggered when the data is received display this character to the terminal.
 * It is like an echo test which uses the tested UART for the echo.
 *
 * @return  none
 */
int32_t uart_test(void)
{
    uint8_t sel;

    printf("\n---- Running UART test, type 'x' to exit.\n");

    /* Initialize the UART port */
    uart_init(&uart_port, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);
    /* Set the IRQ mode for the Rx FIFO */
    uart_set_FIFO_mode(&uart_port, RX_FIFO, 1, IRQ_MODE);
    /* Enable loopback mode */
    uart_set_loopback_mode(&uart_port, ENABLE);
    /* Set the ISR and enable the interrupts for UART3 */
    uart_setup_interrupt(&uart_port, ENABLE);

    do {
        g_wait_flag = 1;
        printf("Please type a character - x to exit:\n");
        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            /* Disable the interrupts for UART3 */
            uart_setup_interrupt(&uart_port, DISABLE);
            break;
        }

        /* send the character to the tested UART */
        /* it will be displayed once read in the tested UART ISR */
        uart_putchar(&uart_port, &sel);
        /* wait for ISR to clear the flag before continuing */
        while (g_wait_flag == 1) ;

    } while (1);

    return 0;
}
