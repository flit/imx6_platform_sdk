/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file uart.c
 * @brief Simple poll-driven on-chip UART driver to send and receive characters
 *
 */

#include "imx_uart.h"

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
uint32_t uart_get_reffreq(struct hw_module *port)
{
    uint32_t div = UART_UFCR_RFDIV;
    uint32_t ret = 0;

    if (div == UART_UFCR_RFDIV_2)
        ret = port->freq / 2;
    else if (div == UART_UFCR_RFDIV_4)
        ret = port->freq / 4;
    else if (div == UART_UFCR_RFDIV_7)
        ret = port->freq / 7;

    return ret;
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
void uart_send_char(struct hw_module *port, unsigned char *ch)
{
    volatile struct mx_uart *puart = (volatile struct mx_uart *)port->base;

#ifdef debug_uart_log_buf
    __log_buf[diag_bp++] = c;
    return;
#endif

    /* Wait for Tx FIFO not full */
    while (puart->uts & UART_UTS_TXFULL) ;  // tx fifo not full

    /* Replace line feed with '\r' */
    if (*ch == '\n') {
        puart->utxd[0] = '\r';

        while (puart->uts & UART_UTS_TXFULL) ;
    }

    puart->utxd[0] = *ch;
}

/*!
 * Receive a character on the UART port
 *
 * @return      a character received from the UART port; if the fifo
 *              is empty, return 0xFF
 */
char uart_receive_char(struct hw_module *port)
{
    volatile struct mx_uart *puart = (volatile struct mx_uart *)port->base;

    // If receive fifo is empty, return false
    if (puart->uts & UART_UTS_RXEMPTY)
        return 0xFF;

    return (uint8_t) puart->urxd[0];
}

/*!
 * @brief   Configure the RX or TX FIFO mode
 *
 * @param   port - pointer to the UART module structure
 * @param   fifo – FIFO to configure: RX_FIFO or TX_FIFO.
 * @param   trigger_level – set the trigger level of the FIFO to generate
 *                an IRQ or a DMA request: number of characters.
 * @param   service_mode – FIFO served with IRQ/polling or DMA.
*/
void uart_set_FIFO_mode(struct hw_module *port, uint8_t fifo, uint8_t trigger_level,
                        uint8_t service_mode)
{
    volatile struct mx_uart *puart = (volatile struct mx_uart *)port->base;

    if (fifo = TX_FIFO) {
        /* Configure the TX_FIFO trigger level */
        puart->ufcr &= ~(0x3F << UART_UFCR_TXTL_SHF);
        puart->ufcr |= (trigger_level << UART_UFCR_TXTL_SHF);
        /* Configure the TX_FIFO service mode */
        puart->ucr1 |= UART_UCR1_TXDMAEN;
    } else {                    /* fifo = RX_FIFO */
        /* Configure the RX_FIFO trigger level */
        puart->ufcr &= ~(0x3F << UART_UFCR_RXTL_SHF);
        puart->ufcr |= (trigger_level << UART_UFCR_RXTL_SHF);
        /* Configure the RX_FIFO service mode */
        puart->ucr1 |= UART_UCR1_RXDMAEN;
    }
}

/*!
 * @brief   Initialize the UART port
 *
 * @param   port - pointer to the UART module structure
 * @param   baudrate – serial baud rate such 9600, 57600, 115200, etc.
 * @param   parity – enable parity checking: PARITY_NONE, PARITY_EVEN, PARITY_ODD.
 * @param   stopbits – number of stop bits: STOPBITS_ONE, STOPBITS_TWO.
 * @param   datasize – number of bits in a data: SEVENBITS, EIGHTBITS, NINEBITS (like RS-485 but not supported).
 * @param   flowcontrol – enable (RTS/CTS) hardware flow control: FLOWCTRL_ON, FLOWCTRL_OFF.
*/
void uart_init(struct hw_module *port, uint32_t baudrate, uint8_t parity,
               uint8_t stopbits, uint8_t datasize, uint8_t flowcontrol)
{
    volatile struct mx_uart *puart = (volatile struct mx_uart *)port->base;

    /* Wait for UART to finish transmitting */
    while (!(puart->uts & UART_UTS_TXEMPTY)) ;

    /* Disable UART */
    puart->ucr1 &= ~UART_UCR1_UARTEN;

    /* Configure FIFOs */
    puart->ufcr = (1 << UART_UFCR_RXTL_SHF) | UART_UFCR_RFDIV | (2 << UART_UFCR_TXTL_SHF);

    /* Setup One Millisecond timer */
    puart->onems = uart_get_reffreq(port) / 1000;

    /* Set parity */
    if (parity == PARITY_NONE)
        puart->ucr2 &= ~(UART_UCR2_PREN | UART_UCR2_PROE);
    else if (parity == PARITY_ODD)
        puart->ucr2 |= UART_UCR2_PREN | UART_UCR2_PROE;
    else {                      /* parity == PARITY_EVEN */
        puart->ucr2 |= UART_UCR2_PREN;
        puart->ucr2 &= ~UART_UCR2_PROE;
    }

    /* Set stop bit */
    if (stopbits == STOPBITS_ONE)
        puart->ucr2 &= ~UART_UCR2_STPB;
    else                        /* stopbits == STOPBITS_TWO */
        puart->ucr2 |= UART_UCR2_STPB;

    /* Set stop bit */
    if (datasize == EIGHTBITS)
        puart->ucr2 |= UART_UCR2_WS;
    else                        /* stopbits == STOPBITS_TWO */
        puart->ucr2 &= ~UART_UCR2_WS;

    /* Configure the flow control */
    if (flowcontrol == FLOWCTRL_ON) {
        /* transmit done when RTS asserted */
        puart->ucr2 &= ~UART_UCR2_IRTS;
        /* CTS controlled by the receiver */
        puart->ucr2 |= UART_UCR2_CTSC;
    } else {                    /* flowcontrol == FLOWCTRL_OFF */
        /* Ignore RTS */
        puart->ucr2 |= UART_UCR2_IRTS;
        /* CTS controlled by the CTS bit */
        puart->ucr2 &= ~UART_UCR2_CTSC;
    }

    /* Enable UART */
    puart->ucr1 |= UART_UCR1_UARTEN;

    /* Enable FIFOs and does software reset to clear status flags, reset
       the transmit and receive state machine, and reset the FIFOs */
    puart->ucr2 |= UART_UCR2_TXEN | UART_UCR2_RXEN | UART_UCR2_SRST;

    /* Set the numerator value minus one of the BRM ratio */
    puart->ubir = (baudrate / 100) - 1;

    /* Set the denominator value minus one of the BRM ratio */
    puart->ubmr = ((uart_get_reffreq(port) / 1600) - 1);
}
