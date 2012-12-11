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
 * @file imx_uart.c
 * @brief UART driver.

 * @ingroup diag_uart
 */

#include "sdk.h"
#include "registers/regsuart.h"
#include "uart/imx_uart.h"
#include "core/ccm_pll.h"
#include "core/interrupt.h"

#define UART_UFCR_RFDIV    BF_UART_UFCR_RFDIV(4) 
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_4
//#define UART_UFCR_RFDIV     UART_UFCR_RFDIV_7

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

uint8_t uart_putchar(struct hw_module * port, uint8_t * ch)
{
    uint32_t instance = port->instance;

    /* Wait for Tx FIFO not full */
    while (HW_UART_UTS(instance).B.TXFULL);

    HW_UART_UTXD_WR(instance, *ch);

    return *ch;
}

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

void uart_set_loopback_mode(struct hw_module *port, uint8_t state)
{
    uint32_t instance = port->instance;
    if (state == TRUE)
	HW_UART_UTS_SET(instance, BM_UART_UTS_LOOP);
    else
        HW_UART_UTS_CLR(instance, BM_UART_UTS_LOOP);
}

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

int uart_get_integer(uint32_t *value)
{
    uint32_t bit_value;
    uint8_t revchar[33] = {0}; /* 32 bit plus one terminal flag*/
    int i, num = 0;

    while (1) {
	revchar[num] = uart_getchar(&g_debug_uart);
	if ((char) revchar[num] == 0x0d) { /* return key*/
	    uart_putchar(&g_debug_uart, &(revchar[num]));
	    revchar[num] = 0x0a; /* move the cursor to the next line */
	    uart_putchar(&g_debug_uart, &(revchar[num]));
	    break;
	} else if ((char) revchar[num] == 0x08 || (char) revchar[num] == 0x7F) {
	    /* delete or backspace */
	    uart_putchar(&g_debug_uart, &(revchar[num]));
	    num--;
	    continue;
	} else if ((char) revchar[num] >= '0' && (char) revchar[num] <= '9'){
	    uart_putchar(&g_debug_uart, &(revchar[num]));
	    num++;
	} else {
	    /* none interger intput. invalid */
	    continue;
	}

	if (num > 32)
	    return FALSE;
    }

    /* last 1 is the terminal char return */
    num--;
    *value = 0;
    for (i = 0; i <= num; i++) {
	bit_value = revchar[i] - 48; /* '0' = 48 */
	if (bit_value > 9 || bit_value < 0) {
	    *value = 0;
	    printf("bit_value %d\n", bit_value);
	    return FALSE;
	} else {
	    *value = (*value * 10 + bit_value) ;
	}
    }

    return TRUE;
}
