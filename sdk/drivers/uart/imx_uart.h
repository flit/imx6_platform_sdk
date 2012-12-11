/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
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
 * @file imx_uart.h
 * @brief various defines used by imx_uart.c
 */

#ifndef __IMX_UART_H__
#define __IMX_UART_H__

#include "sdk.h"

//! @addtogroup diag_uart
//! @{

//////////////////////////////////////////////////////////////////////////
//Constants
/////////////////////////////////////////////////////////////////////////

/* UART specific defines */
//! @brief Modes of the PARITY for UART transfer.
enum _uart_parity
{
	PARITY_NONE = 0, //!< PARITY mode is PARITY_NONE.
	PARITY_EVEN = 2, //!< PARITY mode is PARITY_EVEN.
        PARITY_ODD  = 3  //!< PARITY mode is PARITY_ODD. 
};

//!  @brief Number of stopbits after a character.
enum _uart_stopbits
{
	STOPBITS_ONE = 0, //!< One stopbits after a character.
	STOPBITS_TWO = 1  //!< Two stopbits after a character.
};

//!  @brief Flow control mode for UART transfer.
enum _uart_flowctrl
{
	FLOWCTRL_OFF = 0, //!< Flow control off for UART transfer.
	FLOWCTRL_ON  = 1  //!< Flow control on for UART transfer.
};

//!  @brief Specify the FIFO for UART transfer.
enum _uart_fifo
{
	TX_FIFO = 0,	  //!< Config the TX fifo for UART transfer.
	RX_FIFO = 1	  //!< Config the RX fifo for UART transfer.
};   	

//! @brief Specify the number of bits in a data
enum _uart_bits
{
	SEVENBITS = 0,	  //!< Config seven bits in a data.
	EIGHTBITS = 1     //!< Config eight bits in a data.
};

//! @brief Specify the service mode
#define	DMA_MODE  2	  //!< Config the service mode for dma request.
#define	IRQ_MODE  1      //!< Config the service mode for interrupt.

//////////////////////////////////////////////////////////////////////////
//API
/////////////////////////////////////////////////////////////////////////


/*!
 * @brief   Initialize the UART port
 *
 * @param   port pointer to the UART module structure.
 * @param   baudrate serial baud rate such 9600, 57600, 115200, etc.
 * @param   parity enable parity checking: PARITY_NONE, PARITY_EVEN,
 *                   PARITY_ODD.
 * @param   stopbits number of stop bits: STOPBITS_ONE, STOPBITS_TWO.
 * @param   datasize number of bits in a data: SEVENBITS, EIGHTBITS,
 *                     NINEBITS (like RS-485 but not supported).
 * @param   flowcontrol enable (RTS/CTS) hardware flow control:
 *                        FLOWCTRL_ON, FLOWCTRL_OFF.
 */
void uart_init(struct hw_module *port, uint32_t baudrate, uint8_t parity,uint8_t stopbits, uint8_t datasize, uint8_t flowcontrol);

/*!
 * @brief   Output a character to UART port
 *
 * @param   port pointer to the UART module structure
 * @param   ch pointer to the character for output
 * @return  the character that has been sent
 */
uint8_t uart_putchar(struct hw_module *port, uint8_t * ch);

/*!
 * @brief   Receive a character on the UART port
 *
 * @param   port pointer to the UART module structure
 * @return  a character received from the UART port; if the RX FIFO
 *          is empty or errors are detected, it returns NONE_CHAR
 */
uint8_t uart_getchar(struct hw_module *port);


/*!
 * @brief   Receive unsigned integer input on the UART port
 *
 * @param   Integer pointer to the value which want to get the interget input from user.
 * @return  If correctly get an valid interger input, return TRUE. If errors are detected, it returns FALSE.
 */
int uart_get_integer(uint32_t *value);
/*!
 * @brief   Configure the RX or TX FIFO level and trigger mode
 *
 * @param   port pointer to the UART module structure
 * @param   fifo FIFO to configure: RX_FIFO or TX_FIFO.
 * @param   trigger_level set the trigger level of the FIFO to generate
 *                          an IRQ or a DMA request: number of characters.
 * @param   service_mode FIFO served with DMA or IRQ or polling (default).
 */
void uart_set_FIFO_mode(struct hw_module *port, uint8_t fifo, uint8_t trigger_level,
                        uint8_t service_mode);

/*!
 * @brief   Enables UART loopback test mode
 *
 * @param   port pointer to the UART module structure
 * @param   state enable/disable the loopback mode
 */
void uart_set_loopback_mode(struct hw_module *port, uint8_t state);

/*!
 * @brief   Setup UART interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port pointer to the UART module structure.
 * @param   state ENABLE or DISABLE the interrupt.
 */
void uart_setup_interrupt(struct hw_module *port, uint8_t state);


/*!
 * @brief   Obtain UART reference frequency
 *
 * @param   port pointer to the UART module structure
 * @return  reference frequency in Hz
 */
uint32_t uart_get_reffreq(struct hw_module *port);

//! @name Board support functions
//!
//! These functions are called by the driver in order to factor out board
//! specific functionality. They must be defined by the board support
//! library or the application.
//@{
//! @brief Configure IOMUX for the UART driver.
void uart_iomux_config(int instance);
//@}

//! @}

#endif //__IMX_UART_H__
