/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
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
