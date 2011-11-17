/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_uart.c
 * @brief UART driver.
 *
 */

#include "hardware.h"

#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_2
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_4
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_7

/*!
 * Obtain UART reference frequency
 *
 * @param   port - pointer to the UART module structure
 * @return  reference frequency in Hz
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

/*!
 * Output a character to UART port
 *
 * @param   ch - pointer to the character for output
 * @return  the character that has been sent
 */
uint8_t uart_putchar(struct hw_module * port, uint8_t * ch)
{
    volatile struct imx_uart *puart = (volatile struct imx_uart *)port->base;

    /* Wait for Tx FIFO not full */
    while (puart->uts & UART_UTS_TXFULL) ;

    puart->utxd[0] = *ch;

    return *ch;
}

/*!
 * Receive a character on the UART port
 *
 * @return  a character received from the UART port; if the RX FIFO
 *          is empty or errors are detected, it returns NONE_CHAR
 */
uint8_t uart_getchar(struct hw_module * port)
{
    volatile struct imx_uart *puart = (volatile struct imx_uart *)port->base;
    uint32_t read_data;

    /* If Rx FIFO has no data ready */
    if (!(puart->usr2 & UART_USR2_RDR))
        return NONE_CHAR;

    read_data = puart->urxd[0];

    /* If error are detected */
    if (read_data & 0x7C00)
        return NONE_CHAR;

    return (uint8_t) read_data;
}

/*!
 * Configure the RX or TX FIFO level and trigger mode
 *
 * @param   port - pointer to the UART module structure
 * @param   fifo – FIFO to configure: RX_FIFO or TX_FIFO.
 * @param   trigger_level – set the trigger level of the FIFO to generate
 *                          an IRQ or a DMA request: number of characters.
 * @param   service_mode – FIFO served with DMA or IRQ or polling (default).
 */
void uart_set_FIFO_mode(struct hw_module *port, uint8_t fifo, uint8_t trigger_level,
                        uint8_t service_mode)
{
    volatile struct imx_uart *puart = (volatile struct imx_uart *)port->base;

    if (fifo == TX_FIFO) {
        /* Configure the TX_FIFO trigger level */
        puart->ufcr &= ~(0x3F << UART_UFCR_TXTL_SHF);
        puart->ufcr |= (trigger_level << UART_UFCR_TXTL_SHF);
        /* Configure the TX_FIFO service mode */
        /* Default mode is polling: IRQ and DMA requests are disabled */
        puart->ucr1 &= ~(UART_UCR1_TRDYEN | UART_UCR1_TXDMAEN);
        if (service_mode == DMA_MODE)
            puart->ucr1 |= UART_UCR1_TXDMAEN;
        else if (service_mode == IRQ_MODE)
            puart->ucr1 |= UART_UCR1_TRDYEN;
    } else {                    /* fifo = RX_FIFO */
        /* Configure the RX_FIFO trigger level */
        puart->ufcr &= ~(0x3F << UART_UFCR_RXTL_SHF);
        puart->ufcr |= (trigger_level << UART_UFCR_RXTL_SHF);
        /* Configure the RX_FIFO service mode */
        /* Default mode is polling: IRQ and DMA requests are disabled */
        puart->ucr1 &= ~(UART_UCR1_RRDYEN | UART_UCR1_RXDMAEN);
        if (service_mode == DMA_MODE)
            puart->ucr1 |= UART_UCR1_RXDMAEN;
        else if (service_mode == IRQ_MODE)
            puart->ucr1 |= UART_UCR1_RRDYEN;
    }
}

/*!
 * Enables UART loopback test mode
 *
 * @param   port - pointer to the UART module structure
 * @param   state - enable/disable the loopback mode
 */
void uart_set_loopback_mode(struct hw_module *port, uint8_t state)
{
    volatile struct imx_uart *puart = (volatile struct imx_uart *)port->base;

    if (state == ENABLE)
        puart->uts |= UART_UTS_LOOP;
    else
        puart->uts &= ~UART_UTS_LOOP;
}

/*!
 * Setup UART interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the UART module structure.
 * @param   state - enable/disable the interrupt
 */
void uart_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    } else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
}

/*!
 * Initialize the UART port
 *
 * @param   port - pointer to the UART module structure.
 * @param   baudrate – serial baud rate such 9600, 57600, 115200, etc.
 * @param   parity – enable parity checking: PARITY_NONE, PARITY_EVEN,
 *                   PARITY_ODD.
 * @param   stopbits – number of stop bits: STOPBITS_ONE, STOPBITS_TWO.
 * @param   datasize – number of bits in a data: SEVENBITS, EIGHTBITS,
 *                     NINEBITS (like RS-485 but not supported).
 * @param   flowcontrol – enable (RTS/CTS) hardware flow control:
 *                        FLOWCTRL_ON, FLOWCTRL_OFF.
 */
void uart_init(struct hw_module *port, uint32_t baudrate, uint8_t parity,
               uint8_t stopbits, uint8_t datasize, uint8_t flowcontrol)
{
    volatile struct imx_uart *puart = (volatile struct imx_uart *)port->base;

   /* configure the I/O for the port */
    uart_iomux_config(port->base);

    /* enable the source clocks to the UART port */
    clock_gating_config(port->base, CLOCK_ON);

    /* Wait for UART to finish transmitting before changing the configuration */
    while (!(puart->uts & UART_UTS_TXEMPTY)) ;

    /* Disable UART */
    puart->ucr1 &= ~UART_UCR1_UARTEN;

    /* Configure FIFOs trigger level to half-full and half-empty */
    puart->ufcr = (16 << UART_UFCR_RXTL_SHF) | UART_UFCR_RFDIV | (16 << UART_UFCR_TXTL_SHF);

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

    /* Set data size */
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

    /* the reference manual says that this bit must always be set */
    puart->ucr3 |= UART_UCR3_RXDMUXSEL;

    /* Enable UART */
    puart->ucr1 |= UART_UCR1_UARTEN;

    /* Enable FIFOs and does software reset to clear status flags, reset
       the transmit and receive state machine, and reset the FIFOs */
    puart->ucr2 |= UART_UCR2_TXEN | UART_UCR2_RXEN | UART_UCR2_SRST;

    /* Set the numerator value minus one of the BRM ratio */
    puart->ubir = (baudrate / 100) - 1;

    /* Set the denominator value minus one of the BRM ratio */
    puart->ubmr = ((uart_get_reffreq(port) / 1600) - 1);

    /* Optional: prevent the UART to enter debug state. Useful when debugging
       the code with a JTAG and without active IRQ */
    puart->uts |= UART_UTS_DBGEN;
}
