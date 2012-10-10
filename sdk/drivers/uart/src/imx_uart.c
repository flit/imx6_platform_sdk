/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_uart.c
 * @brief UART driver.
 * @ingroup diag_uart
 */

#include "hardware.h"
#include "registers/regsuart.h"

#define UART_UFCR_RFDIV    BF_UART_UFCR_RFDIV(4) 
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_4
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_7
/*!
 * @brief   Obtain UART reference frequency
 *
 * @param   port - pointer to the UART module structure
 * @return  reference frequency in Hz
 */
uint32_t uart_get_reffreq(struct hw_module *port)
{
    uint32_t div = UART_UFCR_RFDIV;
    uint32_t ret = 0;

    if (div == BF_UART_UFCR_RFDIV(4))
        ret = port->freq / 2;
    else if (div == BF_UART_UFCR_RFDIV(2))
        ret = port->freq / 4;
    else if (div == BF_UART_UFCR_RFDIV(6))
        ret = port->freq / 7;

    return ret;
}

/*!
 * @brief   Output a character to UART port
 *
 * @param   port - pointer to the UART module structure
 * @param   ch - pointer to the character for output
 * @return  the character that has been sent
 */
uint8_t uart_putchar(struct hw_module * port, uint8_t * ch)
{
    uint32_t instance = port->instance;

    /* Wait for Tx FIFO not full */
    while (HW_UART_UTS(instance).B.TXFULL);

    HW_UART_UTXD_WR(instance, *ch);

    return *ch;
}

/*!
 * @brief   Receive a character on the UART port
 *
 * @param   port - pointer to the UART module structure
 * @return  a character received from the UART port; if the RX FIFO
 *          is empty or errors are detected, it returns NONE_CHAR
 */
uint8_t uart_getchar(struct hw_module * port)
{
    uint32_t instance = port->instance;
    uint32_t read_data;

    /* If Rx FIFO has no data ready */
    if (!(HW_UART_USR2(instance).B.RDR))
        return NONE_CHAR;

    read_data = HW_UART_URXD_RD(instance); 

    /* If error are detected */
    if (read_data & 0x7C00)
        return NONE_CHAR;

    return (uint8_t) read_data;
}

/*!
 * @brief   Configure the RX or TX FIFO level and trigger mode
 *
 * @param   port - pointer to the UART module structure
 * @param   fifo - FIFO to configure: RX_FIFO or TX_FIFO.
 * @param   trigger_level - set the trigger level of the FIFO to generate
 *                          an IRQ or a DMA request: number of characters.
 * @param   service_mode - FIFO served with DMA or IRQ or polling (default).
 */
void uart_set_FIFO_mode(struct hw_module *port, uint8_t fifo, uint8_t trigger_level,
                        uint8_t service_mode)
{
    uint32_t instance = port->instance;
    if (fifo == TX_FIFO) {
        /* Configure the TX_FIFO trigger level */
        HW_UART_UFCR_CLR(instance,BM_UART_UFCR_TXTL);
        HW_UART_UFCR_SET(instance, BF_UART_UFCR_TXTL(trigger_level)); 
        /* Configure the TX_FIFO service mode */
        /* Default mode is polling: IRQ and DMA requests are disabled */
        HW_UART_UCR1_CLR(instance,(BM_UART_UCR1_TRDYEN | BM_UART_UCR1_TXDMAEN));
        if (service_mode == DMA_MODE)
           HW_UART_UCR1_SET(instance,BM_UART_UCR1_TXDMAEN);
        else if (service_mode == IRQ_MODE)
            HW_UART_UCR1_SET(instance,BM_UART_UCR1_TRDYEN); 
    } else {                    /* fifo = RX_FIFO */
        /* Configure the RX_FIFO trigger level */
         HW_UART_UFCR_CLR(instance,BM_UART_UFCR_RXTL);
        HW_UART_UFCR_SET(instance,BF_UART_UFCR_RXTL(trigger_level)); 
        /* Configure the RX_FIFO service mode */
        /* Default mode is polling: IRQ and DMA requests are disabled */
        HW_UART_UCR1_CLR(instance,(BM_UART_UCR1_RRDYEN | BM_UART_UCR1_RXDMAEN)); 
        if (service_mode == DMA_MODE)
            HW_UART_UCR1_SET(instance,BM_UART_UCR1_RXDMAEN); 
        else if (service_mode == IRQ_MODE)
            HW_UART_UCR1_SET(instance,BM_UART_UCR1_RRDYEN); 
    }
}

/*!
 * @brief   Enables UART loopback test mode
 *
 * @param   port - pointer to the UART module structure
 * @param   state - enable/disable the loopback mode
 */
void uart_set_loopback_mode(struct hw_module *port, uint8_t state)
{
    uint32_t instance = port->instance;
    if (state == TRUE)
	HW_UART_UTS_SET(instance, BM_UART_UTS_LOOP);
    else
        HW_UART_UTS_CLR(instance, BM_UART_UTS_LOOP);
}

/*!
 * @brief   Setup UART interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the UART module structure.
 * @param   state - ENABLE or DISABLE the interrupt.
 */
void uart_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == TRUE) {
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    } else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
}

/*!
 * @brief   Initialize the UART port
 *
 * @param   port - pointer to the UART module structure.
 * @param   baudrate - serial baud rate such 9600, 57600, 115200, etc.
 * @param   parity - enable parity checking: PARITY_NONE, PARITY_EVEN,
 *                   PARITY_ODD.
 * @param   stopbits - number of stop bits: STOPBITS_ONE, STOPBITS_TWO.
 * @param   datasize - number of bits in a data: SEVENBITS, EIGHTBITS,
 *                     NINEBITS (like RS-485 but not supported).
 * @param   flowcontrol - enable (RTS/CTS) hardware flow control:
 *                        FLOWCTRL_ON, FLOWCTRL_OFF.
 */
void uart_init(struct hw_module *port, uint32_t baudrate, uint8_t parity,
               uint8_t stopbits, uint8_t datasize, uint8_t flowcontrol)
{
    uint32_t instance = port->instance;
   /* configure the I/O for the port */
    uart_iomux_config(port->instance);

    /* enable the source clocks to the UART port */
    clock_gating_config(port->base, CLOCK_ON);

    /* Wait for UART to finish transmitting before changing the configuration */
    while (!(HW_UART_UTS(instance).B.TXEMPTY)) ;

    /* Disable UART */
    HW_UART_UCR1_CLR(instance,BM_UART_UCR1_UARTEN );

    /* Configure FIFOs trigger level to half-full and half-empty */
    HW_UART_UFCR_WR(instance, BF_UART_UFCR_RXTL(16) | UART_UFCR_RFDIV | BF_UART_UFCR_TXTL(16)); 

    /* Setup One Millisecond timer */
    HW_UART_ONEMS_WR(instance, uart_get_reffreq(port) / 1000);

    /* Set parity */
    if (parity == PARITY_NONE)
        HW_UART_UCR2_CLR(instance,(BM_UART_UCR2_PREN| BM_UART_UCR2_PROE)); 
    else if (parity == PARITY_ODD)
        HW_UART_UCR2_SET(instance,(BM_UART_UCR2_PREN| BM_UART_UCR2_PROE));
    else {                      /* parity == PARITY_EVEN */
        HW_UART_UCR2_SET(instance, BM_UART_UCR2_PREN);
        HW_UART_UCR2_CLR(instance, BM_UART_UCR2_PROE);
    }

    /* Set stop bit */
    if (stopbits == STOPBITS_ONE)
        HW_UART_UCR2_CLR(instance, BM_UART_UCR2_STPB);
    else                        /* stopbits == STOPBITS_TWO */
        HW_UART_UCR2_SET(instance, BM_UART_UCR2_STPB);

    /* Set data size */
    if (datasize == EIGHTBITS)
        HW_UART_UCR2_SET(instance, BM_UART_UCR2_WS);
    else                        /* stopbits == STOPBITS_TWO */
        HW_UART_UCR2_CLR(instance, BM_UART_UCR2_WS);

    /* Configure the flow control */
    if (flowcontrol == FLOWCTRL_ON) {
        /* transmit done when RTS asserted */
        HW_UART_UCR2_CLR(instance, BM_UART_UCR2_IRTS );
        /* CTS controlled by the receiver */
        HW_UART_UCR2_SET(instance, BM_UART_UCR2_CTSC );
    } else {                    /* flowcontrol == FLOWCTRL_OFF */
        /* Ignore RTS */
        HW_UART_UCR2_SET(instance,  BM_UART_UCR2_IRTS);
        /* CTS controlled by the CTS bit */
        HW_UART_UCR2_CLR(instance,  BM_UART_UCR2_CTSC);
    }

    /* the reference manual says that this bit must always be set */
    HW_UART_UCR3_SET(instance,  BM_UART_UCR3_RXDMUXSEL);

    /* Enable UART */
    HW_UART_UCR1_SET(instance, BM_UART_UCR1_UARTEN);

    /* Enable FIFOs and does software reset to clear status flags, reset
       the transmit and receive state machine, and reset the FIFOs */
    HW_UART_UCR2_SET(instance, BM_UART_UCR2_TXEN | BM_UART_UCR2_RXEN | BM_UART_UCR2_SRST);

    /* Set the numerator value minus one of the BRM ratio */
    HW_UART_UBIR_WR(instance, (baudrate / 100) - 1);

    /* Set the denominator value minus one of the BRM ratio */
    HW_UART_UBMR_WR(instance,  ((uart_get_reffreq(port) / 1600) - 1));

    /* Optional: prevent the UART to enter debug state. Useful when debugging
       the code with a JTAG and without active IRQ */
    HW_UART_UTS_SET(instance, BM_UART_UTS_DBGEN);
}
