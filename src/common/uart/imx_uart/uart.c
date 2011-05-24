/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file uart.c
 * @brief Simple poll-driven on-chip UART driver to send and receive characters
 *
 */

#include "hardware.h"
#include "io.h"
#include "uart.h"

#define UART_UFCR_RFDIV                        UART_UFCR_RFDIV_2
//#define UART_UFCR_RFDIV                        UART_UFCR_RFDIV_4
//#define UART_UFCR_RFDIV                        UART_UFCR_RFDIV_7

/*!
 * Obtain uart reference frequency
 *
 * @param   uart      pointer to the uart module structure
 *
 * @return  reference freq in hz
 */
u32 mx_uart_reffreq(struct hw_module *uart)
{
    u32 div = UART_UFCR_RFDIV;
    u32 ret = 0;

    if (div == UART_UFCR_RFDIV_2)
        ret = uart->freq / 2;
    else if (div == UART_UFCR_RFDIV_4)
        ret = uart->freq / 4;
    else if (div == UART_UFCR_RFDIV_7)
        ret = uart->freq / 7;

    return ret;
}

static volatile struct mx_uart *debug_uart;

/*!
 * Initialize debug uart
 *
 * @param   uart        pointer to the uart module structure
 * @param   baud        desired baud rate for ommunicating to external device
 */
void init_debug_uart(struct hw_module *uart, u32 baud)
{
    debug_uart = (volatile struct mx_uart *)uart->base;

    /* Wait for UART to finish transmitting */
    while (!(debug_uart->uts & UART_UTS_TXEMPTY)) ;

    /* Disable UART */
    debug_uart->ucr1 &= ~UART_UCR1_UARTEN;

    /* Set to default POR state */
    debug_uart->ucr1 = 0x00000000;
    debug_uart->ucr2 = 0x00000000;

    while (!(debug_uart->ucr2 & UART_UCR2_SRST_)) ;

    debug_uart->ucr3 = 0x00000704;
    debug_uart->ucr4 = 0x00008000;
    debug_uart->ufcr = 0x00000801;
    debug_uart->uesc = 0x0000002B;
    debug_uart->utim = 0x00000000;
    debug_uart->ubir = 0x00000000;
    debug_uart->ubmr = 0x00000000;
    debug_uart->onems = 0x00000000;
    debug_uart->uts = 0x00000000;

    /* Configure FIFOs */
    debug_uart->ufcr = (1 << UART_UFCR_RXTL_SHF) | UART_UFCR_RFDIV | (2 << UART_UFCR_TXTL_SHF);

    /* Setup One MS timer */
    debug_uart->onems = mx_uart_reffreq(uart) / 1000;

    /* Set to 8N1 */
    debug_uart->ucr2 &= ~UART_UCR2_PREN;
    debug_uart->ucr2 |= UART_UCR2_WS;
    debug_uart->ucr2 &= ~UART_UCR2_STPB;

    /* Ignore RTS */
    debug_uart->ucr2 |= UART_UCR2_IRTS;

    /* Enable UART */
    debug_uart->ucr1 |= UART_UCR1_UARTEN;

    /* Enable FIFOs */
    debug_uart->ucr2 |= UART_UCR2_SRST_ | UART_UCR2_RXEN | UART_UCR2_TXEN;

    /* Clear status flags */
    debug_uart->usr2 |= UART_USR2_ADET |
        UART_USR2_IDLE |
        UART_USR2_IRINT |
        UART_USR2_WAKE | UART_USR2_RTSF | UART_USR2_BRCD | UART_USR2_ORE | UART_USR2_RDR;

    /* Clear status flags */
    debug_uart->usr1 |= UART_USR1_PARITYERR |
        UART_USR1_RTSD | UART_USR1_ESCF | UART_USR1_FRAMERR | UART_USR1_AIRINT | UART_USR1_AWAKE;

    /* Set the numerator value minus one of the BRM ratio */
    debug_uart->ubir = (baud / 100) - 1;

    /* Set the denominator value minus one of the BRM ratio    */
    debug_uart->ubmr = ((mx_uart_reffreq(uart) / 1600) - 1);
}

#ifdef debug_uart_log_buf
#define DIAG_BUFSIZE 2048
static char __log_buf[DIAG_BUFSIZE];
static int diag_bp = 0;
#endif

/*!
 * Output a character to the debug uart port
 *
 * @param       ch      pointer to the character for output
 */
void sendchar(unsigned char *ch)
{
#ifdef debug_uart_log_buf
    __log_buf[diag_bp++] = c;
    return;
#endif

    // Wait for Tx FIFO not full
    while (debug_uart->uts & UART_UTS_TXFULL)   // tx fifo not full
    {
    }

    if (*ch == '\n')            // Replace line feed with '\r'
    {
        debug_uart->utxd[0] = '\r';

        while (debug_uart->uts & UART_UTS_TXFULL) {
        }
    }

    debug_uart->utxd[0] = *ch;
}

/*!
 * Receive a character for the debug uart port
 *
 * @return      a character received from the debug uart port; if the fifo
 *              is empty, return 0xff
 */
char receive_char(void)
{
    // If receive fifo is empty, return false
    if (debug_uart->uts & UART_UTS_RXEMPTY)
        return 0xFF;

    return (u8) debug_uart->urxd[0];
}

/*!
 * Initialize debug uart
 *
 * @param   uart        pointer to the uart module structure
 * @param   baud        desired baud rate for ommunicating to external device
 */
void init_uart(struct hw_module *uart, u32 baud)
{
    volatile struct mx_uart *puart = (volatile struct mx_uart *)uart->base;

    /* Wait for UART to finish transmitting */
    while (!(puart->uts & UART_UTS_TXEMPTY)) ;

    /* Disable UART */
    puart->ucr1 &= ~UART_UCR1_UARTEN;

    /* Set to default POR state */
    puart->ucr1 = 0x00000000;
    puart->ucr2 = 0x00000000;

    while (!(puart->ucr2 & UART_UCR2_SRST_)) ;

    puart->ucr3 = 0x00000704;
    puart->ucr4 = 0x00008000;
    puart->ufcr = 0x00000801;
    puart->uesc = 0x0000002B;
    puart->utim = 0x00000000;
    puart->ubir = 0x00000000;
    puart->ubmr = 0x00000000;
    puart->onems = 0x00000000;
    puart->uts = 0x00000000;

    /* Configure FIFOs */
    puart->ufcr = (1 << UART_UFCR_RXTL_SHF) | UART_UFCR_RFDIV | (2 << UART_UFCR_TXTL_SHF);

    /* Setup One MS timer */
    puart->onems = mx_uart_reffreq(uart) / 1000;

    /* Set to 8N1 */
    puart->ucr2 &= ~UART_UCR2_PREN;
    puart->ucr2 |= UART_UCR2_WS;
    puart->ucr2 &= ~UART_UCR2_STPB;

    /* Ignore RTS */
    puart->ucr2 |= UART_UCR2_IRTS;

    /* Enable UART */
    puart->ucr1 |= UART_UCR1_UARTEN;

    /* Enable FIFOs */
    puart->ucr2 |= UART_UCR2_SRST_ | UART_UCR2_RXEN | UART_UCR2_TXEN;

    /* Clear status flags */
    puart->usr2 |= UART_USR2_ADET |
        UART_USR2_IDLE |
        UART_USR2_IRINT |
        UART_USR2_WAKE | UART_USR2_RTSF | UART_USR2_BRCD | UART_USR2_ORE | UART_USR2_RDR;

    /* Clear status flags */
    puart->usr1 |= UART_USR1_PARITYERR |
        UART_USR1_RTSD | UART_USR1_ESCF | UART_USR1_FRAMERR | UART_USR1_AIRINT | UART_USR1_AWAKE;

    /* Set the numerator value minus one of the BRM ratio */
    puart->ubir = (baud / 100) - 1;

    /* Set the denominator value minus one of the BRM ratio    */
    puart->ubmr = ((mx_uart_reffreq(uart) / 1600) - 1);
}

/*!
 * Output a character to the debug uart port
 *
 * @param  puart   pointer to the uart hardware
 * @param  ch     	 pointer to the character for output
 */
void uart_sendchar(struct mx_uart *puart, unsigned char *ch)
{
    // Wait for Tx FIFO not full
    while (puart->uts & UART_UTS_TXFULL)    // tx fifo not full
    {
    }

    if (*ch == '\n')            // Replace line feed with '\r'
    {
        puart->utxd[0] = '\r';

        while (puart->uts & UART_UTS_TXFULL) {
        }
    }

    puart->utxd[0] = *ch;
}

/*!
 * Receive a character for the debug uart port
 *
 * @return      a character received from the debug uart port; if the fifo
 *              is empty, return 0xff
 */
char uart_receive_char(struct mx_uart *puart)
{
    // If receive fifo is empty, return false
    if (puart->uts & UART_UTS_RXEMPTY)
        return 0xFF;

    return (u8) puart->urxd[0];
}

/*!
 * Rather meaningless report here because we won't even get here unless user enters 'x' or 'X'.
 * But, still ...
 * @return      TEST_PASSED or  TEST_FAILED    
 */
int uart_test(void)
{
    int retry = 0;

    PROMPT_RUN_TEST("UART");
    printf("Please input char to test UART input function, 'X' exit this test\n");

    while (!is_input_char('x')) {
        if (++retry == MAX_TEST_RETRY) {
            printf("Tried %d times. All failed!\n", retry);
            return TEST_FAILED;
        }
    }
    return TEST_PASSED;
}

