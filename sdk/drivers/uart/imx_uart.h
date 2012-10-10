/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_uart.h
 * @brief various defines used by imx_uart.c
 * @ingroup diag_uart
 */

#ifndef __IMX_UART_H__
#define __IMX_UART_H__

#include "sdk.h"

/* UART Registers Bit Fields */
#define UART_UCR1_ADEN      (1 << 15)   // Auto dectect interrupt
#define UART_UCR1_ADBR      (1 << 14)   // Auto detect baud rate
#define UART_UCR1_TRDYEN    (1 << 13)   // Transmitter ready interrupt enable
#define UART_UCR1_IDEN      (1 << 12)   // Idle condition interrupt
#define UART_UCR1_RRDYEN    (1 << 9)    // Recv ready interrupt enable
#define UART_UCR1_RXDMAEN   (1 << 8)    // Recv ready DMA enable
#define UART_UCR1_IREN      (1 << 7)    // Infrared interface enable
#define UART_UCR1_TXMPTYEN  (1 << 6)    // Transimitter empty interrupt enable
#define UART_UCR1_RTSDEN    (1 << 5)    // RTS delta interrupt enable
#define UART_UCR1_SNDBRK    (1 << 4)    // Send break
#define UART_UCR1_TXDMAEN   (1 << 3)    // Transmitter ready DMA enable
#define UART_UCR1_DOZE      (1 << 1)    // Doze
#define UART_UCR1_UARTEN    (1 << 0)    // UART enabled
#define UART_UCR2_ESCI      (1 << 15)   // Escape seq interrupt enable
#define UART_UCR2_IRTS      (1 << 14)   // Ignore RTS pin
#define UART_UCR2_CTSC      (1 << 13)   // CTS pin control
#define UART_UCR2_CTS       (1 << 12)   // Clear to send
#define UART_UCR2_ESCEN     (1 << 11)   // Escape enable
#define UART_UCR2_PREN      (1 << 8)    // Parity enable
#define UART_UCR2_PROE      (1 << 7)    // Parity odd/even
#define UART_UCR2_STPB      (1 << 6)    // Stop
#define UART_UCR2_WS        (1 << 5)    // Word size
#define UART_UCR2_RTSEN     (1 << 4)    // Request to send interrupt enable
#define UART_UCR2_ATEN      (1 << 3)    // Aging timer enable
#define UART_UCR2_TXEN      (1 << 2)    // Transmitter enabled
#define UART_UCR2_RXEN      (1 << 1)    // Receiver enabled
#define UART_UCR2_SRST      (1 << 0)    // SW reset
#define UART_UCR3_PARERREN  (1 << 12)   // Parity interrupt enable
#define UART_UCR3_FRAERREN  (1 << 11)   // Frame error interrupt enable
#define UART_UCR3_ADNIMP    (1 << 7)    // Autobaud detection not improved
#define UART_UCR3_RXDSEN    (1 << 6)    // Receive status interrupt enable
#define UART_UCR3_AIRINTEN  (1 << 5)    // Async IR wake interrupt enable
#define UART_UCR3_AWAKEN    (1 << 4)    // Async wake interrupt enable
#define UART_UCR3_RXDMUXSEL (1 << 2)    // RXD muxed input selected
#define UART_UCR3_INVT      (1 << 1)    // Inverted Infrared transmission
#define UART_UCR3_ACIEN     (1 << 0)    // Autobaud counter interrupt enable
#define UART_UCR4_CTSTL_32  (32 << 10)  // CTS trigger level (32 chars)
#define UART_UCR4_INVR      (1 << 9)    // Inverted infrared reception
#define UART_UCR4_ENIRI     (1 << 8)    // Serial infrared interrupt enable
#define UART_UCR4_WKEN      (1 << 7)    // Wake interrupt enable
#define UART_UCR4_IRSC      (1 << 5)    // IR special case
#define UART_UCR4_LPBYP     (1 << 4)    // Low power bypass
#define UART_UCR4_TCEN      (1 << 3)    // Transmit complete interrupt enable
#define UART_UCR4_BKEN      (1 << 2)    // Break condition interrupt enable
#define UART_UCR4_OREN      (1 << 1)    // Receiver overrun interrupt enable
#define UART_UCR4_DREN      (1 << 0)    // Recv data ready interrupt enable
#define UART_UFCR_RXTL_SHF  0   // Receiver trigger level shift
#define UART_UFCR_RFDIV_1   (5 << 7)    // Reference freq divider (div 1)
#define UART_UFCR_RFDIV_2   (4 << 7)    // Reference freq divider (div 2)
#define UART_UFCR_RFDIV_3   (3 << 7)    // Reference freq divider (div 3)
#define UART_UFCR_RFDIV_4   (2 << 7)    // Reference freq divider (div 4)
#define UART_UFCR_RFDIV_5   (1 << 7)    // Reference freq divider (div 5)
#define UART_UFCR_RFDIV_6   (0 << 7)    // Reference freq divider (div 6)
#define UART_UFCR_RFDIV_7   (6 << 7)    // Reference freq divider (div 7)
#define UART_UFCR_TXTL_SHF  10  // Transmitter trigger level shift
#define UART_USR1_PARITYERR (1 << 15)   // Parity error interrupt flag
#define UART_USR1_RTSS      (1 << 14)   // RTS pin status
#define UART_USR1_TRDY      (1 << 13)   // Transmitter ready interrupt/dma flag
#define UART_USR1_RTSD      (1 << 12)   // RTS delta
#define UART_USR1_ESCF      (1 << 11)   // Escape seq interrupt flag
#define UART_USR1_FRAMERR   (1 << 10)   // Frame error interrupt flag
#define UART_USR1_RRDY      (1 << 9)    // Receiver ready interrupt/dma flag
#define UART_USR1_AGTIM     (1 << 8)    // Aging timeout interrupt status
#define UART_USR1_RXDS      (1 << 6)    // Receiver idle interrupt flag
#define UART_USR1_AIRINT    (1 << 5)    // Async IR wake interrupt flag
#define UART_USR1_AWAKE     (1 << 4)    // Aysnc wake interrupt flag
#define UART_USR2_ADET      (1 << 15)   // Auto baud rate detect complete
#define UART_USR2_TXFE      (1 << 14)   // Transmit buffer FIFO empty
#define UART_USR2_IDLE      (1 << 12)   // Idle condition
#define UART_USR2_ACST      (1 << 11)   // Autobaud counter stopped
#define UART_USR2_IRINT     (1 << 8)    // Serial infrared interrupt flag
#define UART_USR2_WAKE      (1 << 7)    // Wake
#define UART_USR2_RTSF      (1 << 4)    // RTS edge interrupt flag
#define UART_USR2_TXDC      (1 << 3)    // Transmitter complete
#define UART_USR2_BRCD      (1 << 2)    // Break condition
#define UART_USR2_ORE       (1 << 1)    // Overrun error
#define UART_USR2_RDR       (1 << 0)    // Recv data ready
#define UART_UTS_FRCPERR    (1 << 13)   // Force parity error
#define UART_UTS_LOOP       (1 << 12)   // Loop tx and rx
#define UART_UTS_DBGEN      (1 << 11)   // Debug en
#define UART_UTS_TXEMPTY    (1 << 6)    // TxFIFO empty
#define UART_UTS_RXEMPTY    (1 << 5)    // RxFIFO empty
#define UART_UTS_TXFULL     (1 << 4)    // TxFIFO full
#define UART_UTS_RXFULL     (1 << 3)    // RxFIFO full
#define UART_UTS_SOFTRST    (1 << 0)    // Software reset

/* UART specific defines */
#define PARITY_NONE 0
#define PARITY_EVEN 2
#define PARITY_ODD  3
#define STOPBITS_ONE 0
#define STOPBITS_TWO 1
#define SEVENTBITS 0
#define EIGHTBITS 1
#define FLOWCTRL_OFF 0
#define FLOWCTRL_ON 1

#define TX_FIFO 0
#define RX_FIFO 1
#define DMA_MODE 2
#define IRQ_MODE 1

void uart_init(struct hw_module *port, uint32_t baudrate, uint8_t parity,uint8_t stopbits, uint8_t datasize, uint8_t flowcontrol);
uint8_t uart_putchar(struct hw_module *port, uint8_t * ch);
uint8_t uart_getchar(struct hw_module *port);
void uart_set_FIFO_mode(struct hw_module *port, uint8_t fifo, uint8_t trigger_level,
                        uint8_t service_mode);
void uart_set_loopback_mode(struct hw_module *port, uint8_t state);
void uart_setup_interrupt(struct hw_module *port, uint8_t state);

#define UART_WIDTH_32
/* UART Registers list */
#ifdef UART_WIDTH_32
struct imx_uart {
    volatile uint32_t urxd[16];
    volatile uint32_t utxd[16];
    volatile uint32_t ucr1;
    volatile uint32_t ucr2;
    volatile uint32_t ucr3;
    volatile uint32_t ucr4;
    volatile uint32_t ufcr;
    volatile uint32_t usr1;
    volatile uint32_t usr2;
    volatile uint32_t uesc;
    volatile uint32_t utim;
    volatile uint32_t ubir;
    volatile uint32_t ubmr;
    volatile uint32_t ubrc;
    volatile uint32_t onems;
    volatile uint32_t uts;
};
#else
struct imx_uart {
    volatile uint16_t urxd[1];
    volatile uint16_t resv0[31];
    volatile uint16_t utxd[1];
    volatile uint16_t resv1[31];
    volatile uint16_t ucr1;
    volatile uint16_t resv2;
    volatile uint16_t ucr2;
    volatile uint16_t resv3;
    volatile uint16_t ucr3;
    volatile uint16_t resv4;
    volatile uint16_t ucr4;
    volatile uint16_t resv5;
    volatile uint16_t ufcr;
    volatile uint16_t resv6;
    volatile uint16_t usr1;
    volatile uint16_t resv7;
    volatile uint16_t usr2;
    volatile uint16_t resv8;
    volatile uint16_t uesc;
    volatile uint16_t resv9;
    volatile uint16_t utim;
    volatile uint16_t resv10;
    volatile uint16_t ubir;
    volatile uint16_t resv11;
    volatile uint16_t ubmr;
    volatile uint16_t resv12;
    volatile uint16_t ubrc;
    volatile uint16_t resv13;
    volatile uint16_t onems;
    volatile uint16_t resv14;
    volatile uint16_t uts;
    volatile uint16_t resv15;
};
#endif

#endif //__IMX_UART_H__
