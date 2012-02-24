/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _UARTV2_H
#define _UARTV2_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_UARTV2_URXD - UART Receiver Register
 * - HW_UARTV2_UTXD - UART Transmitter Register
 * - HW_UARTV2_UCR1 - UART Control Register 1
 * - HW_UARTV2_UCR2 - UART Control Register 2
 * - HW_UARTV2_UCR3 - UART Control Register 3
 * - HW_UARTV2_UCR4 - UART Control Register 4
 * - HW_UARTV2_UFCR - UART FIFO Control Register
 * - HW_UARTV2_USR1 - UART Status Register 1
 * - HW_UARTV2_USR2 - UART Status Register 2
 * - HW_UARTV2_UESC - UART Escape Character Register
 * - HW_UARTV2_UTIM - UART Escape Timer Register
 * - HW_UARTV2_UBIR - UART BRM Incremental Register
 * - HW_UARTV2_UBMR - UART BRM Modulator Register
 * - HW_UARTV2_UBRC - UART Baud Rate Count Register
 * - HW_UARTV2_ONEMS - UART One Millisecond Register
 * - HW_UARTV2_UTS - UART Test Register
 * - HW_UARTV2_UMCR - UART RS-485 Mode Control Register
 *
 * hw_uartv2_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_UARTV2_BASE
#define REGS_UARTV20_BASE (0x02020000) //!< Base address for UARTV2 instance number 0.
#define REGS_UARTV21_BASE (0x021e8000) //!< Base address for UARTV2 instance number 1.
#define REGS_UARTV22_BASE (0x021ec000) //!< Base address for UARTV2 instance number 2.
#define REGS_UARTV23_BASE (0x021f0000) //!< Base address for UARTV2 instance number 3.
#define REGS_UARTV24_BASE (0x021f4000) //!< Base address for UARTV2 instance number 4.

//! @brief Get the base address of UARTV2 by instance number.
//! @param x UARTV2 instance number, from 0 through 5.
#define REGS_UARTV2_BASE(x) ( x == 0 ? REGS_UARTV20_BASE : x == 1 ? REGS_UARTV21_BASE : x == 2 ? REGS_UARTV22_BASE : x == 3 ? REGS_UARTV23_BASE : x == 4 ? REGS_UARTV24_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_URXD - UART Receiver Register (RO)
 *
 * The UART will yield a transfer error on the peripheral bus when core is reading URXD register
 * with receive interface disabled (RXEN=0 or UARTEN=0).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX_DATA : 8; //!< Received Data . Holds the received character. In 7-bit mode, the most significant bit (MSB) is forced to 0. In 8-bit mode, all bits are active.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned PRERR : 1; //!< In RS-485 mode, it holds the ninth data bit (bit [8]) of received 9-bit RS-485 data In RS232/IrDA mode, it is the Parity Error flag . Indicates whether the current character was detected with a parity error and is possibly corrupted. PRERR is updated for each character read from the RxFIFO. When parity is disabled, PRERR always reads as 0.
        unsigned BRK : 1; //!< BREAK Detect. Indicates whether the current character was detected as a BREAK character. The data bits and the stop bit are all 0. The FRMERR bit is set when BRK is set. When odd parity is selected, PRERR is also set when BRK is set. BRK is valid for each character read from the RxFIFO.
        unsigned FRMERR : 1; //!< Frame Error. Indicates whether the current character had a framing error (a missing stop bit) and is possibly corrupted. FRMERR is updated for each character read from the RxFIFO.
        unsigned OVRRUN : 1; //!< Receiver Overrun. This read-only bit, when HIGH, indicates that the corresponding character was stored in the last position (32nd) of the Rx FIFO. Even if a 33rd character has not been detected, this bit will be set to '1' for the 32nd character.
        unsigned ERR : 1; //!< Error Detect. Indicates whether the character present in the RX_DATA field has an error (OVRRUN, FRMERR, BRK or PRERR) status. The ERR bit is updated and valid for each received character.
        unsigned CHARRDY : 1; //!< Character Ready. This read-only bit indicates an invalid read when the FIFO becomes empty and software tries to read the same old data. This bit should not be used for polling for data written to the RX FIFO.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_uartv2_urxd_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_URXD register
 */
#define HW_UARTV2_URXD_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_URXD(x)           (*(volatile hw_uartv2_urxd_t *) HW_UARTV2_URXD_ADDR(x))
#define HW_UARTV2_URXD_RD(x)        (HW_UARTV2_URXD(x).U)
#endif

/*
 * constants & macros for individual UARTV2_URXD bitfields
 */

/* --- Register HW_UARTV2_URXD, field RX_DATA (RO)
 *
 * Received Data . Holds the received character. In 7-bit mode, the most significant bit (MSB) is
 * forced to 0. In 8-bit mode, all bits are active.
 */

#define BP_UARTV2_URXD_RX_DATA      0
#define BM_UARTV2_URXD_RX_DATA      0x000000ff

/* --- Register HW_UARTV2_URXD, field PRERR (RO)
 *
 * In RS-485 mode, it holds the ninth data bit (bit [8]) of received 9-bit RS-485 data In RS232/IrDA
 * mode, it is the Parity Error flag . Indicates whether the current character was detected with a
 * parity error and is possibly corrupted. PRERR is updated for each character read from the RxFIFO.
 * When parity is disabled, PRERR always reads as 0.
 *
 * Values:
 * 0 - = No parity error was detected for data in the RX_DATA field
 * 1 - = A parity error was detected for data in the RX_DATA field
 */

#define BP_UARTV2_URXD_PRERR      10
#define BM_UARTV2_URXD_PRERR      0x00000400


/* --- Register HW_UARTV2_URXD, field BRK (RO)
 *
 * BREAK Detect. Indicates whether the current character was detected as a BREAK character. The data
 * bits and the stop bit are all 0. The FRMERR bit is set when BRK is set. When odd parity is
 * selected, PRERR is also set when BRK is set. BRK is valid for each character read from the
 * RxFIFO.
 *
 * Values:
 * 0 - The current character is not a BREAK character
 * 1 - The current character is a BREAK character
 */

#define BP_UARTV2_URXD_BRK      11
#define BM_UARTV2_URXD_BRK      0x00000800


/* --- Register HW_UARTV2_URXD, field FRMERR (RO)
 *
 * Frame Error. Indicates whether the current character had a framing error (a missing stop bit) and
 * is possibly corrupted. FRMERR is updated for each character read from the RxFIFO.
 *
 * Values:
 * 0 - The current character has no framing error
 * 1 - The current character has a framing error
 */

#define BP_UARTV2_URXD_FRMERR      12
#define BM_UARTV2_URXD_FRMERR      0x00001000


/* --- Register HW_UARTV2_URXD, field OVRRUN (RO)
 *
 * Receiver Overrun. This read-only bit, when HIGH, indicates that the corresponding character was
 * stored in the last position (32nd) of the Rx FIFO. Even if a 33rd character has not been
 * detected, this bit will be set to '1' for the 32nd character.
 *
 * Values:
 * 0 - No RxFIFO overrun was detected
 * 1 - A RxFIFO overrun was detected
 */

#define BP_UARTV2_URXD_OVRRUN      13
#define BM_UARTV2_URXD_OVRRUN      0x00002000


/* --- Register HW_UARTV2_URXD, field ERR (RO)
 *
 * Error Detect. Indicates whether the character present in the RX_DATA field has an error (OVRRUN,
 * FRMERR, BRK or PRERR) status. The ERR bit is updated and valid for each received character.
 *
 * Values:
 * 0 - No error status was detected
 * 1 - An error status was detected
 */

#define BP_UARTV2_URXD_ERR      14
#define BM_UARTV2_URXD_ERR      0x00004000


/* --- Register HW_UARTV2_URXD, field CHARRDY (RO)
 *
 * Character Ready. This read-only bit indicates an invalid read when the FIFO becomes empty and
 * software tries to read the same old data. This bit should not be used for polling for data
 * written to the RX FIFO.
 *
 * Values:
 * 0 - Character in RX_DATA field and associated flags are invalid.
 * 1 - Character in RX_DATA field and associated flags valid and ready for reading.
 */

#define BP_UARTV2_URXD_CHARRDY      15
#define BM_UARTV2_URXD_CHARRDY      0x00008000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UTXD - UART Transmitter Register (WO)
 *
 * The UART will yield a transfer error on the peripheral bus when core is writing into UART_URXD
 * register with transmit interface disabled (TXEN=0 or UARTEN=0). Memory space between UART_URXD
 * and UART_UTXD registers is reserved. Any read or write access to this space will be considered as
 * an invalid access and yield a transfer error .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_DATA : 8; //!< Transmit Data . Holds the parallel transmit data inputs. In 7-bit mode, D7 is ignored. In 8-bit mode, all bits are used. Data is transmitted least significant bit (LSB) first. A new character is transmitted when the TX_DATA field is written. The TX_DATA field must be written only when the TRDY bit is high to ensure that corrupted data is not sent.
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_uartv2_utxd_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTXD register
 */
#define HW_UARTV2_UTXD_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTXD(x)           (*(volatile hw_uartv2_utxd_t *) HW_UARTV2_UTXD_ADDR(x))
#define HW_UARTV2_UTXD_WR(x, v)     (HW_UARTV2_UTXD(x).U = (v))
#endif

/*
 * constants & macros for individual UARTV2_UTXD bitfields
 */

/* --- Register HW_UARTV2_UTXD, field TX_DATA (WO)
 *
 * Transmit Data . Holds the parallel transmit data inputs. In 7-bit mode, D7 is ignored. In 8-bit
 * mode, all bits are used. Data is transmitted least significant bit (LSB) first. A new character
 * is transmitted when the TX_DATA field is written. The TX_DATA field must be written only when the
 * TRDY bit is high to ensure that corrupted data is not sent.
 */

#define BP_UARTV2_UTXD_TX_DATA      0
#define BM_UARTV2_UTXD_TX_DATA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTXD_TX_DATA(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTXD_TX_DATA)
#else
#define BF_UARTV2_UTXD_TX_DATA(v)   (((v) << 0) & BM_UARTV2_UTXD_TX_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_DATA field to a new value.
#define BW_UARTV2_UTXD_TX_DATA(v)   BF_CS1(UARTV2_UTXD, TX_DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UCR1 - UART Control Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UARTEN : 1; //!< UART Enable . Enables/Disables the UART. If UARTEN is negated in the middle of a transmission, the transmitter stops and pulls the TXD line to a logic 1. UARTEN must be set to 1 before any access to UTXD and URXD registers, otherwise a transfer error is returned. Output ipg_uart_clk_en is internally connected to UARTEN and can be used for software controlled clock gating purpose. This bit can be set to 1 along with other bits in this register. There is no restriction to the sequence of programing this bit and other control registers.
        unsigned DOZE : 1; //!< DOZE . Determines the UART enable condition in the DOZE state. When doze_req input pin is at '1', (the ARM Platform executes a doze instruction and the system is placed in the Doze State), the DOZE bit affects operation of the UART. While in the Doze State, if this bit is asserted, the UART is disabled. See the description in .
        unsigned ATDMAEN : 1; //!< Aging DMA Timer Enable . Enables/Disables the receive DMA request dma_req_rx for the aging timer interrupt (triggered with AGTIM flag in USR1[8]).
        unsigned TXDMAEN : 1; //!< Transmitter Ready DMA Enable . Enables/Disables the transmit DMA request dma_req_tx when the transmitter has one or more slots available in the TxFIFO. The fill level in the TxFIFO that generates the dma_req_tx is controlled by the TXTL bits. A DMA request will be issued as long as TXDMAEN and TRDY are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the transmit DMA request.
        unsigned SNDBRK : 1; //!< Send BREAK . Forces the transmitter to send a BREAK character. The transmitter finishes sending the character in progress (if any) and sends BREAK characters until SNDBRK is reset. Because the transmitter samples SNDBRK after every bit is transmitted, it is important that SNDBRK is asserted high for a sufficient period of time to generate a valid BREAK. After the BREAK transmission completes, the UART transmits 2 mark bits. The user can continue to fill the TxFIFO and any characters remaining are transmitted when the BREAK is terminated.
        unsigned RTSDEN : 1; //!< RTS Delta Interrupt Enable . Enables/Disables the RTSD interrupt. The current status of the RTS pin is read in the RTSS bit.
        unsigned TXMPTYEN : 1; //!< Transmitter Empty Interrupt Enable . Enables/Disables the transmitter FIFO empty (TXFE) interrupt. interrupt_tx interrupt_uart . When negated, the TXFE interrupt is disabled. An interrupt will be issued as long as TXMPTYEN and TXFE are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TXFE interrupt.
        unsigned IREN : 1; //!< Infrared Interface Enable . Enables/Disables the IR interface. See the IR interface description in , for more information. Note: MDEN(UMCR[0]) must be cleared to 0 when using IrDA interface. See
        unsigned RXDMAEN : 1; //!< Receive Ready DMA Enable . Enables/Disables the receive DMA request dma_req_rx when the receiver has data in the RxFIFO. The fill level in the RxFIFO at which a DMA request is generated is controlled by the RXTL bits. When negated, the receive DMA request is disabled.
        unsigned RRDYEN : 1; //!< Receiver Ready Interrupt Enable . Enables/Disables the RRDY interrupt when the RxFIFO contains data. The fill level in the RxFIFO at which an interrupt is generated is controlled by the RXTL bits. When RRDYEN is negated, the receiver ready interrupt is disabled.
        unsigned ICD : 2; //!< Idle Condition Detect . Controls the number of frames RXD is allowed to be idle before an idle condition is reported.
        unsigned IDEN : 1; //!< Idle Condition Detected Interrupt Enable . Enables/Disables the IDLE bit to generate an interrupt ( interrupt_rx interrupt_uart = 0).
        unsigned TRDYEN : 1; //!< Transmitter Ready Interrupt Enable . Enables/Disables the transmitter Ready Interrupt (TRDY) when the transmitter has one or more slots available in the TxFIFO. The fill level in the TXFIFO at which an interrupt is generated is controlled by TxTL bits. When TRDYEN is negated, the transmitter ready interrupt is disabled. An interrupt will be issued as long as TRDYEN and TRDY are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TRDY interrupt.
        unsigned ADBR : 1; //!< Automatic Detection of Baud Rate . Enables/Disables automatic baud rate detection. When the ADBR bit is set and the ADET bit is cleared, the receiver detects the incoming baud rate automatically. The ADET flag is set when the receiver verifies that the incoming baud rate is detected properly by detecting an ASCII character "A" or "a" (0x61 or 0x41).
        unsigned ADEN : 1; //!< Automatic Baud Rate Detection Interrupt Enable . Enables/Disables the automatic baud rate detect complete (ADET) bit to generate an interrupt ( interrupt_mint interrupt_uart = 0).
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ucr1_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR1 register
 */
#define HW_UARTV2_UCR1_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR1(x)           (*(volatile hw_uartv2_ucr1_t *) HW_UARTV2_UCR1_ADDR(x))
#define HW_UARTV2_UCR1_RD(x)        (HW_UARTV2_UCR1(x).U)
#define HW_UARTV2_UCR1_WR(x, v)     (HW_UARTV2_UCR1(x).U = (v))
#define HW_UARTV2_UCR1_SET(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) |  (v)))
#define HW_UARTV2_UCR1_CLR(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) & ~(v)))
#define HW_UARTV2_UCR1_TOG(x, v)    (HW_UARTV2_UCR1_WR(x, HW_UARTV2_UCR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UCR1 bitfields
 */

/* --- Register HW_UARTV2_UCR1, field UARTEN (RW)
 *
 * UART Enable . Enables/Disables the UART. If UARTEN is negated in the middle of a transmission,
 * the transmitter stops and pulls the TXD line to a logic 1. UARTEN must be set to 1 before any
 * access to UTXD and URXD registers, otherwise a transfer error is returned. Output ipg_uart_clk_en
 * is internally connected to UARTEN and can be used for software controlled clock gating purpose.
 * This bit can be set to 1 along with other bits in this register. There is no restriction to the
 * sequence of programing this bit and other control registers.
 *
 * Values:
 * 0 - Disable the UART
 * 1 - Enable the UART
 */

#define BP_UARTV2_UCR1_UARTEN      0
#define BM_UARTV2_UCR1_UARTEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_UARTEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR1_UARTEN)
#else
#define BF_UARTV2_UCR1_UARTEN(v)   (((v) << 0) & BM_UARTV2_UCR1_UARTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UARTEN field to a new value.
#define BW_UARTV2_UCR1_UARTEN(v)   BF_CS1(UARTV2_UCR1, UARTEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field DOZE (RW)
 *
 * DOZE . Determines the UART enable condition in the DOZE state. When doze_req input pin is at '1',
 * (the ARM Platform executes a doze instruction and the system is placed in the Doze State), the
 * DOZE bit affects operation of the UART. While in the Doze State, if this bit is asserted, the
 * UART is disabled. See the description in .
 *
 * Values:
 * 0 - The UART is enabled when in DOZE state
 * 1 - The UART is disabled when in DOZE state
 */

#define BP_UARTV2_UCR1_DOZE      1
#define BM_UARTV2_UCR1_DOZE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_DOZE(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR1_DOZE)
#else
#define BF_UARTV2_UCR1_DOZE(v)   (((v) << 1) & BM_UARTV2_UCR1_DOZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOZE field to a new value.
#define BW_UARTV2_UCR1_DOZE(v)   BF_CS1(UARTV2_UCR1, DOZE, v)
#endif


/* --- Register HW_UARTV2_UCR1, field ATDMAEN (RW)
 *
 * Aging DMA Timer Enable . Enables/Disables the receive DMA request dma_req_rx for the aging timer
 * interrupt (triggered with AGTIM flag in USR1[8]).
 *
 * Values:
 * 0 - Disable AGTIM DMA request
 * 1 - Enable AGTIM DMA request
 */

#define BP_UARTV2_UCR1_ATDMAEN      2
#define BM_UARTV2_UCR1_ATDMAEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ATDMAEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR1_ATDMAEN)
#else
#define BF_UARTV2_UCR1_ATDMAEN(v)   (((v) << 2) & BM_UARTV2_UCR1_ATDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDMAEN field to a new value.
#define BW_UARTV2_UCR1_ATDMAEN(v)   BF_CS1(UARTV2_UCR1, ATDMAEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field TXDMAEN (RW)
 *
 * Transmitter Ready DMA Enable . Enables/Disables the transmit DMA request dma_req_tx when the
 * transmitter has one or more slots available in the TxFIFO. The fill level in the TxFIFO that
 * generates the dma_req_tx is controlled by the TXTL bits. A DMA request will be issued as long as
 * TXDMAEN and TRDY are high even if the transmitter is not enabled. In general, user should enable
 * the transmitter before enabling the transmit DMA request.
 *
 * Values:
 * 0 - Disable transmit DMA request
 * 1 - Enable transmit DMA request
 */

#define BP_UARTV2_UCR1_TXDMAEN      3
#define BM_UARTV2_UCR1_TXDMAEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TXDMAEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR1_TXDMAEN)
#else
#define BF_UARTV2_UCR1_TXDMAEN(v)   (((v) << 3) & BM_UARTV2_UCR1_TXDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXDMAEN field to a new value.
#define BW_UARTV2_UCR1_TXDMAEN(v)   BF_CS1(UARTV2_UCR1, TXDMAEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field SNDBRK (RW)
 *
 * Send BREAK . Forces the transmitter to send a BREAK character. The transmitter finishes sending
 * the character in progress (if any) and sends BREAK characters until SNDBRK is reset. Because the
 * transmitter samples SNDBRK after every bit is transmitted, it is important that SNDBRK is
 * asserted high for a sufficient period of time to generate a valid BREAK. After the BREAK
 * transmission completes, the UART transmits 2 mark bits. The user can continue to fill the TxFIFO
 * and any characters remaining are transmitted when the BREAK is terminated.
 *
 * Values:
 * 0 - Do not send a BREAK character
 * 1 - Send a BREAK character (continuous 0s)
 */

#define BP_UARTV2_UCR1_SNDBRK      4
#define BM_UARTV2_UCR1_SNDBRK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_SNDBRK(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR1_SNDBRK)
#else
#define BF_UARTV2_UCR1_SNDBRK(v)   (((v) << 4) & BM_UARTV2_UCR1_SNDBRK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SNDBRK field to a new value.
#define BW_UARTV2_UCR1_SNDBRK(v)   BF_CS1(UARTV2_UCR1, SNDBRK, v)
#endif


/* --- Register HW_UARTV2_UCR1, field RTSDEN (RW)
 *
 * RTS Delta Interrupt Enable . Enables/Disables the RTSD interrupt. The current status of the RTS
 * pin is read in the RTSS bit.
 *
 * Values:
 * 0 - Disable RTSD interrupt
 * 1 - Enable RTSD interrupt
 */

#define BP_UARTV2_UCR1_RTSDEN      5
#define BM_UARTV2_UCR1_RTSDEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RTSDEN(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR1_RTSDEN)
#else
#define BF_UARTV2_UCR1_RTSDEN(v)   (((v) << 5) & BM_UARTV2_UCR1_RTSDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSDEN field to a new value.
#define BW_UARTV2_UCR1_RTSDEN(v)   BF_CS1(UARTV2_UCR1, RTSDEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field TXMPTYEN (RW)
 *
 * Transmitter Empty Interrupt Enable . Enables/Disables the transmitter FIFO empty (TXFE)
 * interrupt. interrupt_tx interrupt_uart . When negated, the TXFE interrupt is disabled. An
 * interrupt will be issued as long as TXMPTYEN and TXFE are high even if the transmitter is not
 * enabled. In general, user should enable the transmitter before enabling the TXFE interrupt.
 *
 * Values:
 * 0 - Disable the transmitter FIFO empty interrupt
 * 1 - Enable the transmitter FIFO empty interrupt
 */

#define BP_UARTV2_UCR1_TXMPTYEN      6
#define BM_UARTV2_UCR1_TXMPTYEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TXMPTYEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR1_TXMPTYEN)
#else
#define BF_UARTV2_UCR1_TXMPTYEN(v)   (((v) << 6) & BM_UARTV2_UCR1_TXMPTYEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXMPTYEN field to a new value.
#define BW_UARTV2_UCR1_TXMPTYEN(v)   BF_CS1(UARTV2_UCR1, TXMPTYEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field IREN (RW)
 *
 * Infrared Interface Enable . Enables/Disables the IR interface. See the IR interface description
 * in , for more information. Note: MDEN(UMCR[0]) must be cleared to 0 when using IrDA interface.
 * See
 *
 * Values:
 * 0 - Disable the IR interface
 * 1 - Enable the IR interface
 */

#define BP_UARTV2_UCR1_IREN      7
#define BM_UARTV2_UCR1_IREN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_IREN(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR1_IREN)
#else
#define BF_UARTV2_UCR1_IREN(v)   (((v) << 7) & BM_UARTV2_UCR1_IREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IREN field to a new value.
#define BW_UARTV2_UCR1_IREN(v)   BF_CS1(UARTV2_UCR1, IREN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field RXDMAEN (RW)
 *
 * Receive Ready DMA Enable . Enables/Disables the receive DMA request dma_req_rx when the receiver
 * has data in the RxFIFO. The fill level in the RxFIFO at which a DMA request is generated is
 * controlled by the RXTL bits. When negated, the receive DMA request is disabled.
 *
 * Values:
 * 0 - Disable DMA request
 * 1 - Enable DMA request
 */

#define BP_UARTV2_UCR1_RXDMAEN      8
#define BM_UARTV2_UCR1_RXDMAEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RXDMAEN(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR1_RXDMAEN)
#else
#define BF_UARTV2_UCR1_RXDMAEN(v)   (((v) << 8) & BM_UARTV2_UCR1_RXDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDMAEN field to a new value.
#define BW_UARTV2_UCR1_RXDMAEN(v)   BF_CS1(UARTV2_UCR1, RXDMAEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field RRDYEN (RW)
 *
 * Receiver Ready Interrupt Enable . Enables/Disables the RRDY interrupt when the RxFIFO contains
 * data. The fill level in the RxFIFO at which an interrupt is generated is controlled by the RXTL
 * bits. When RRDYEN is negated, the receiver ready interrupt is disabled.
 *
 * Values:
 * 0 - Disables the RRDY interrupt
 * 1 - Enables the RRDY interrupt
 */

#define BP_UARTV2_UCR1_RRDYEN      9
#define BM_UARTV2_UCR1_RRDYEN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_RRDYEN(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR1_RRDYEN)
#else
#define BF_UARTV2_UCR1_RRDYEN(v)   (((v) << 9) & BM_UARTV2_UCR1_RRDYEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RRDYEN field to a new value.
#define BW_UARTV2_UCR1_RRDYEN(v)   BF_CS1(UARTV2_UCR1, RRDYEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field ICD (RW)
 *
 * Idle Condition Detect . Controls the number of frames RXD is allowed to be idle before an idle
 * condition is reported.
 *
 * Values:
 * 00 - Idle for more than 4 frames
 * 01 - Idle for more than 8 frames
 * 10 - Idle for more than 16 frames
 * 11 - Idle for more than 32 frames
 */

#define BP_UARTV2_UCR1_ICD      10
#define BM_UARTV2_UCR1_ICD      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ICD(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR1_ICD)
#else
#define BF_UARTV2_UCR1_ICD(v)   (((v) << 10) & BM_UARTV2_UCR1_ICD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICD field to a new value.
#define BW_UARTV2_UCR1_ICD(v)   BF_CS1(UARTV2_UCR1, ICD, v)
#endif


/* --- Register HW_UARTV2_UCR1, field IDEN (RW)
 *
 * Idle Condition Detected Interrupt Enable . Enables/Disables the IDLE bit to generate an interrupt
 * ( interrupt_rx interrupt_uart = 0).
 *
 * Values:
 * 0 - Disable the IDLE interrupt
 * 1 - Enable the IDLE interrupt
 */

#define BP_UARTV2_UCR1_IDEN      12
#define BM_UARTV2_UCR1_IDEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_IDEN(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR1_IDEN)
#else
#define BF_UARTV2_UCR1_IDEN(v)   (((v) << 12) & BM_UARTV2_UCR1_IDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDEN field to a new value.
#define BW_UARTV2_UCR1_IDEN(v)   BF_CS1(UARTV2_UCR1, IDEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field TRDYEN (RW)
 *
 * Transmitter Ready Interrupt Enable . Enables/Disables the transmitter Ready Interrupt (TRDY) when
 * the transmitter has one or more slots available in the TxFIFO. The fill level in the TXFIFO at
 * which an interrupt is generated is controlled by TxTL bits. When TRDYEN is negated, the
 * transmitter ready interrupt is disabled. An interrupt will be issued as long as TRDYEN and TRDY
 * are high even if the transmitter is not enabled. In general, user should enable the transmitter
 * before enabling the TRDY interrupt.
 *
 * Values:
 * 0 - Disable the transmitter ready interrupt
 * 1 - Enable the transmitter ready interrupt
 */

#define BP_UARTV2_UCR1_TRDYEN      13
#define BM_UARTV2_UCR1_TRDYEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_TRDYEN(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR1_TRDYEN)
#else
#define BF_UARTV2_UCR1_TRDYEN(v)   (((v) << 13) & BM_UARTV2_UCR1_TRDYEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TRDYEN field to a new value.
#define BW_UARTV2_UCR1_TRDYEN(v)   BF_CS1(UARTV2_UCR1, TRDYEN, v)
#endif


/* --- Register HW_UARTV2_UCR1, field ADBR (RW)
 *
 * Automatic Detection of Baud Rate . Enables/Disables automatic baud rate detection. When the ADBR
 * bit is set and the ADET bit is cleared, the receiver detects the incoming baud rate
 * automatically. The ADET flag is set when the receiver verifies that the incoming baud rate is
 * detected properly by detecting an ASCII character "A" or "a" (0x61 or 0x41).
 *
 * Values:
 * 0 - Disable automatic detection of baud rate
 * 1 - Enable automatic detection of baud rate
 */

#define BP_UARTV2_UCR1_ADBR      14
#define BM_UARTV2_UCR1_ADBR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ADBR(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR1_ADBR)
#else
#define BF_UARTV2_UCR1_ADBR(v)   (((v) << 14) & BM_UARTV2_UCR1_ADBR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADBR field to a new value.
#define BW_UARTV2_UCR1_ADBR(v)   BF_CS1(UARTV2_UCR1, ADBR, v)
#endif


/* --- Register HW_UARTV2_UCR1, field ADEN (RW)
 *
 * Automatic Baud Rate Detection Interrupt Enable . Enables/Disables the automatic baud rate detect
 * complete (ADET) bit to generate an interrupt ( interrupt_mint interrupt_uart = 0).
 *
 * Values:
 * 0 - Disable the automatic baud rate detection interrupt
 * 1 - Enable the automatic baud rate detection interrupt
 */

#define BP_UARTV2_UCR1_ADEN      15
#define BM_UARTV2_UCR1_ADEN      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR1_ADEN(v)   ((((reg32_t) v) << 15) & BM_UARTV2_UCR1_ADEN)
#else
#define BF_UARTV2_UCR1_ADEN(v)   (((v) << 15) & BM_UARTV2_UCR1_ADEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADEN field to a new value.
#define BW_UARTV2_UCR1_ADEN(v)   BF_CS1(UARTV2_UCR1, ADEN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UCR2 - UART Control Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SRST : 1; //!< Software Reset . Once the software writes 0 to SRST , the software reset remains active for 4 module_clock (ipg_perclk) cycles before the hardware deasserts SRST . The software can only write 0 to SRST . Writing 1 to SRST is ignored.
        unsigned RXEN : 1; //!< Receiver Enable . Enables/Disables the receiver. When the receiver is enabled, if the RXD input is already low, the receiver does not recognize BREAK characters, because it requires a valid 1-to-0 transition before it can accept any character.
        unsigned TXEN : 1; //!< Transmitter Enable . Enables/Disables the transmitter. When TXEN is negated the transmitter is disabled and idle. When the UARTEN and TXEN bits are set the transmitter is enabled. If TXEN is negated in the middle of a transmission, the UART disables the transmitter immediately, and starts marking 1s. The transmitter FIFO cannot be written when this bit is cleared.
        unsigned ATEN : 1; //!< Aging Timer Enable . This bit is used to enable the aging timer interrupt (triggered with AGTIM)
        unsigned RTSEN : 1; //!< Request to Send Interrupt Enable. Controls the RTS edge sensitive interrupt. When RTSEN is asserted and the programmed edge is detected on the RTS pin (the RTSF bit is asserted), an interrupt will be generated on the interrupt_mint interrupt_uart pin. (See .)
        unsigned WS : 1; //!< Word Size . Controls the character length. When WS is high, the transmitter and receiver are in 8-bit mode. When WS is low, they are in 7-bit mode. The transmitter ignores bit 7 and the receiver sets bit 7 to 0. WS can be changed in-between transmission (reception) of characters, however not when a transmission (reception) is in progress, in which case the length of the current character being transmitted (received) is unpredictable.
        unsigned STPB : 1; //!< Stop . Controls the number of stop bits after a character. When STPB is low, 1 stop bit is sent. When STPB is high, 2 stop bits are sent. STPB also affects the receiver.
        unsigned PROE : 1; //!< Parity Odd/Even . Controls the sense of the parity generator and checker. When PROE is high, odd parity is generated and expected. When PROE is low, even parity is generated and expected. PROE has no function if PREN is low.
        unsigned PREN : 1; //!< Parity Enable . Enables/Disables the parity generator in the transmitter and parity checker in the receiver. When PREN is asserted, the parity generator and checker are enabled, and disabled when PREN is negated.
        unsigned RTEC : 2; //!< Request to Send Edge Control . Selects the edge that triggers the RTS interrupt. This has no effect on the RTS delta interrupt. RTEC has an effect only when RTSEN = 1 (see ).
        unsigned ESCEN : 1; //!< Escape Enable . Enables/Disables the escape sequence detection logic.
        unsigned CTS : 1; //!< Clear to Send . Controls the CTS pin when the CTSC bit is negated. CTS has no function when CTSC is asserted.
        unsigned CTSC : 1; //!< CTS Pin Control . Controls the operation of the CTS output pin. When CTSC is asserted, the CTS output pin is controlled by the receiver. When the RxFIFO is filled to the level of the programmed trigger level and the start bit of the overflowing character (TRIGGER LEVEL + 1) is validated, the CTS output pin is negated to indicate to the far-end transmitter to stop transmitting. When the trigger level is programmed for less than 32, the receiver continues to receive data until the RxFIFO is full. When the CTSC bit is negated, the CTS output pin is controlled by the CTS bit. On reset, because CTSC is cleared to 0, the CTS pin is controlled by the CTS bit, which again is cleared to 0 on reset. This means that on reset the CTS signal is negated.
        unsigned IRTS : 1; //!< Ignore RTS Pin . Forces the RTS input signal presented to the transmitter to always be asserted (set to low), effectively ignoring the external pin. When in this mode, the RTS pin serves as a general purpose input.
        unsigned ESCI : 1; //!< Escape Sequence Interrupt Enable . Enables/Disables the ESCF bit to generate an interrupt.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ucr2_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR2 register
 */
#define HW_UARTV2_UCR2_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR2(x)           (*(volatile hw_uartv2_ucr2_t *) HW_UARTV2_UCR2_ADDR(x))
#define HW_UARTV2_UCR2_RD(x)        (HW_UARTV2_UCR2(x).U)
#define HW_UARTV2_UCR2_WR(x, v)     (HW_UARTV2_UCR2(x).U = (v))
#define HW_UARTV2_UCR2_SET(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) |  (v)))
#define HW_UARTV2_UCR2_CLR(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) & ~(v)))
#define HW_UARTV2_UCR2_TOG(x, v)    (HW_UARTV2_UCR2_WR(x, HW_UARTV2_UCR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UCR2 bitfields
 */

/* --- Register HW_UARTV2_UCR2, field SRST (RW)
 *
 * Software Reset . Once the software writes 0 to SRST , the software reset remains active for 4
 * module_clock (ipg_perclk) cycles before the hardware deasserts SRST . The software can only write
 * 0 to SRST . Writing 1 to SRST is ignored.
 *
 * Values:
 * 0 - Reset the transmit and receive state machines, all FIFOs and register USR1, USR2, UBIR, UBMR, UBRC ,
 *     URXD, UTXD and UTS[6-3].
 * 1 - No reset
 */

#define BP_UARTV2_UCR2_SRST      0
#define BM_UARTV2_UCR2_SRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_SRST(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR2_SRST)
#else
#define BF_UARTV2_UCR2_SRST(v)   (((v) << 0) & BM_UARTV2_UCR2_SRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRST field to a new value.
#define BW_UARTV2_UCR2_SRST(v)   BF_CS1(UARTV2_UCR2, SRST, v)
#endif


/* --- Register HW_UARTV2_UCR2, field RXEN (RW)
 *
 * Receiver Enable . Enables/Disables the receiver. When the receiver is enabled, if the RXD input
 * is already low, the receiver does not recognize BREAK characters, because it requires a valid
 * 1-to-0 transition before it can accept any character.
 *
 * Values:
 * 0 - Disable the receiver
 * 1 - Enable the receiver
 */

#define BP_UARTV2_UCR2_RXEN      1
#define BM_UARTV2_UCR2_RXEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RXEN(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR2_RXEN)
#else
#define BF_UARTV2_UCR2_RXEN(v)   (((v) << 1) & BM_UARTV2_UCR2_RXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXEN field to a new value.
#define BW_UARTV2_UCR2_RXEN(v)   BF_CS1(UARTV2_UCR2, RXEN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field TXEN (RW)
 *
 * Transmitter Enable . Enables/Disables the transmitter. When TXEN is negated the transmitter is
 * disabled and idle. When the UARTEN and TXEN bits are set the transmitter is enabled. If TXEN is
 * negated in the middle of a transmission, the UART disables the transmitter immediately, and
 * starts marking 1s. The transmitter FIFO cannot be written when this bit is cleared.
 *
 * Values:
 * 0 - Disable the transmitter
 * 1 - Enable the transmitter
 */

#define BP_UARTV2_UCR2_TXEN      2
#define BM_UARTV2_UCR2_TXEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_TXEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR2_TXEN)
#else
#define BF_UARTV2_UCR2_TXEN(v)   (((v) << 2) & BM_UARTV2_UCR2_TXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEN field to a new value.
#define BW_UARTV2_UCR2_TXEN(v)   BF_CS1(UARTV2_UCR2, TXEN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field ATEN (RW)
 *
 * Aging Timer Enable . This bit is used to enable the aging timer interrupt (triggered with AGTIM)
 *
 * Values:
 * 0 - AGTIM interrupt disabled
 * 1 - AGTIM interrupt enabled
 */

#define BP_UARTV2_UCR2_ATEN      3
#define BM_UARTV2_UCR2_ATEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ATEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR2_ATEN)
#else
#define BF_UARTV2_UCR2_ATEN(v)   (((v) << 3) & BM_UARTV2_UCR2_ATEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEN field to a new value.
#define BW_UARTV2_UCR2_ATEN(v)   BF_CS1(UARTV2_UCR2, ATEN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field RTSEN (RW)
 *
 * Request to Send Interrupt Enable. Controls the RTS edge sensitive interrupt. When RTSEN is
 * asserted and the programmed edge is detected on the RTS pin (the RTSF bit is asserted), an
 * interrupt will be generated on the interrupt_mint interrupt_uart pin. (See .)
 *
 * Values:
 * 0 - Disable request to send interrupt
 * 1 - Enable request to send interrupt
 */

#define BP_UARTV2_UCR2_RTSEN      4
#define BM_UARTV2_UCR2_RTSEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RTSEN(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR2_RTSEN)
#else
#define BF_UARTV2_UCR2_RTSEN(v)   (((v) << 4) & BM_UARTV2_UCR2_RTSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSEN field to a new value.
#define BW_UARTV2_UCR2_RTSEN(v)   BF_CS1(UARTV2_UCR2, RTSEN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field WS (RW)
 *
 * Word Size . Controls the character length. When WS is high, the transmitter and receiver are in
 * 8-bit mode. When WS is low, they are in 7-bit mode. The transmitter ignores bit 7 and the
 * receiver sets bit 7 to 0. WS can be changed in-between transmission (reception) of characters,
 * however not when a transmission (reception) is in progress, in which case the length of the
 * current character being transmitted (received) is unpredictable.
 *
 * Values:
 * 0 - 7-bit transmit and receive character length (not including START, STOP or PARITY bits)
 * 1 - 8-bit transmit and receive character length (not including START, STOP or PARITY bits)
 */

#define BP_UARTV2_UCR2_WS      5
#define BM_UARTV2_UCR2_WS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_WS(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR2_WS)
#else
#define BF_UARTV2_UCR2_WS(v)   (((v) << 5) & BM_UARTV2_UCR2_WS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WS field to a new value.
#define BW_UARTV2_UCR2_WS(v)   BF_CS1(UARTV2_UCR2, WS, v)
#endif


/* --- Register HW_UARTV2_UCR2, field STPB (RW)
 *
 * Stop . Controls the number of stop bits after a character. When STPB is low, 1 stop bit is sent.
 * When STPB is high, 2 stop bits are sent. STPB also affects the receiver.
 *
 * Values:
 * 0 - The transmitter sends 1 stop bit. The receiver expects 1 or more stop bits.
 * 1 - The transmitter sends 2 stop bits. The receiver expects 2 or more stop bits.
 */

#define BP_UARTV2_UCR2_STPB      6
#define BM_UARTV2_UCR2_STPB      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_STPB(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR2_STPB)
#else
#define BF_UARTV2_UCR2_STPB(v)   (((v) << 6) & BM_UARTV2_UCR2_STPB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STPB field to a new value.
#define BW_UARTV2_UCR2_STPB(v)   BF_CS1(UARTV2_UCR2, STPB, v)
#endif


/* --- Register HW_UARTV2_UCR2, field PROE (RW)
 *
 * Parity Odd/Even . Controls the sense of the parity generator and checker. When PROE is high, odd
 * parity is generated and expected. When PROE is low, even parity is generated and expected. PROE
 * has no function if PREN is low.
 *
 * Values:
 * 0 - Even parity
 * 1 - Odd parity
 */

#define BP_UARTV2_UCR2_PROE      7
#define BM_UARTV2_UCR2_PROE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_PROE(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR2_PROE)
#else
#define BF_UARTV2_UCR2_PROE(v)   (((v) << 7) & BM_UARTV2_UCR2_PROE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROE field to a new value.
#define BW_UARTV2_UCR2_PROE(v)   BF_CS1(UARTV2_UCR2, PROE, v)
#endif


/* --- Register HW_UARTV2_UCR2, field PREN (RW)
 *
 * Parity Enable . Enables/Disables the parity generator in the transmitter and parity checker in
 * the receiver. When PREN is asserted, the parity generator and checker are enabled, and disabled
 * when PREN is negated.
 *
 * Values:
 * 0 - Disable parity generator and checker
 * 1 - Enable parity generator and checker
 */

#define BP_UARTV2_UCR2_PREN      8
#define BM_UARTV2_UCR2_PREN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_PREN(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR2_PREN)
#else
#define BF_UARTV2_UCR2_PREN(v)   (((v) << 8) & BM_UARTV2_UCR2_PREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PREN field to a new value.
#define BW_UARTV2_UCR2_PREN(v)   BF_CS1(UARTV2_UCR2, PREN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field RTEC (RW)
 *
 * Request to Send Edge Control . Selects the edge that triggers the RTS interrupt. This has no
 * effect on the RTS delta interrupt. RTEC has an effect only when RTSEN = 1 (see ).
 *
 * Values:
 * 00 - Trigger interrupt on a rising edge
 * 01 - Trigger interrupt on a falling edge
 * 1X - Trigger interrupt on any edge
 */

#define BP_UARTV2_UCR2_RTEC      9
#define BM_UARTV2_UCR2_RTEC      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_RTEC(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR2_RTEC)
#else
#define BF_UARTV2_UCR2_RTEC(v)   (((v) << 9) & BM_UARTV2_UCR2_RTEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTEC field to a new value.
#define BW_UARTV2_UCR2_RTEC(v)   BF_CS1(UARTV2_UCR2, RTEC, v)
#endif


/* --- Register HW_UARTV2_UCR2, field ESCEN (RW)
 *
 * Escape Enable . Enables/Disables the escape sequence detection logic.
 *
 * Values:
 * 0 - Disable escape sequence detection
 * 1 - Enable escape sequence detection
 */

#define BP_UARTV2_UCR2_ESCEN      11
#define BM_UARTV2_UCR2_ESCEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ESCEN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UCR2_ESCEN)
#else
#define BF_UARTV2_UCR2_ESCEN(v)   (((v) << 11) & BM_UARTV2_UCR2_ESCEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCEN field to a new value.
#define BW_UARTV2_UCR2_ESCEN(v)   BF_CS1(UARTV2_UCR2, ESCEN, v)
#endif


/* --- Register HW_UARTV2_UCR2, field CTS (RW)
 *
 * Clear to Send . Controls the CTS pin when the CTSC bit is negated. CTS has no function when CTSC
 * is asserted.
 *
 * Values:
 * 0 - The CTS pin is high (inactive)
 * 1 - The CTS pin is low (active)
 */

#define BP_UARTV2_UCR2_CTS      12
#define BM_UARTV2_UCR2_CTS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_CTS(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR2_CTS)
#else
#define BF_UARTV2_UCR2_CTS(v)   (((v) << 12) & BM_UARTV2_UCR2_CTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTS field to a new value.
#define BW_UARTV2_UCR2_CTS(v)   BF_CS1(UARTV2_UCR2, CTS, v)
#endif


/* --- Register HW_UARTV2_UCR2, field CTSC (RW)
 *
 * CTS Pin Control . Controls the operation of the CTS output pin. When CTSC is asserted, the CTS
 * output pin is controlled by the receiver. When the RxFIFO is filled to the level of the
 * programmed trigger level and the start bit of the overflowing character (TRIGGER LEVEL + 1) is
 * validated, the CTS output pin is negated to indicate to the far-end transmitter to stop
 * transmitting. When the trigger level is programmed for less than 32, the receiver continues to
 * receive data until the RxFIFO is full. When the CTSC bit is negated, the CTS output pin is
 * controlled by the CTS bit. On reset, because CTSC is cleared to 0, the CTS pin is controlled by
 * the CTS bit, which again is cleared to 0 on reset. This means that on reset the CTS signal is
 * negated.
 *
 * Values:
 * 0 - The CTS pin is controlled by the CTS bit
 * 1 - The CTS pin is controlled by the receiver
 */

#define BP_UARTV2_UCR2_CTSC      13
#define BM_UARTV2_UCR2_CTSC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_CTSC(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR2_CTSC)
#else
#define BF_UARTV2_UCR2_CTSC(v)   (((v) << 13) & BM_UARTV2_UCR2_CTSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTSC field to a new value.
#define BW_UARTV2_UCR2_CTSC(v)   BF_CS1(UARTV2_UCR2, CTSC, v)
#endif


/* --- Register HW_UARTV2_UCR2, field IRTS (RW)
 *
 * Ignore RTS Pin . Forces the RTS input signal presented to the transmitter to always be asserted
 * (set to low), effectively ignoring the external pin. When in this mode, the RTS pin serves as a
 * general purpose input.
 *
 * Values:
 * 0 - Transmit only when the RTS pin is asserted
 * 1 - Ignore the RTS pin
 */

#define BP_UARTV2_UCR2_IRTS      14
#define BM_UARTV2_UCR2_IRTS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_IRTS(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR2_IRTS)
#else
#define BF_UARTV2_UCR2_IRTS(v)   (((v) << 14) & BM_UARTV2_UCR2_IRTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRTS field to a new value.
#define BW_UARTV2_UCR2_IRTS(v)   BF_CS1(UARTV2_UCR2, IRTS, v)
#endif


/* --- Register HW_UARTV2_UCR2, field ESCI (RW)
 *
 * Escape Sequence Interrupt Enable . Enables/Disables the ESCF bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the escape sequence interrupt
 * 1 - Enable the escape sequence interrupt
 */

#define BP_UARTV2_UCR2_ESCI      15
#define BM_UARTV2_UCR2_ESCI      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR2_ESCI(v)   ((((reg32_t) v) << 15) & BM_UARTV2_UCR2_ESCI)
#else
#define BF_UARTV2_UCR2_ESCI(v)   (((v) << 15) & BM_UARTV2_UCR2_ESCI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCI field to a new value.
#define BW_UARTV2_UCR2_ESCI(v)   BF_CS1(UARTV2_UCR2, ESCI, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UCR3 - UART Control Register 3 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ACIEN : 1; //!< Autobaud Counter Interrupt Enable. This bit is used to enable the autobaud counter stopped interrupt (triggered with ACST (USR2[11]).
        unsigned INVT : 1; //!< Invert TXD output in RS-232/RS-485 mode, set TXD active level in IrDA mode. In RS232/RS-485 mode(UMCR[0] = 1), if this bit is set to 1, the TXD output is inverted before transmitted. In IrDA mode , when INVT is cleared, the infrared logic block transmits a positive IR 3/16 pulse for all 0s and 0s are transmitted for 1s. When INVT is set (INVT = 1), the infrared logic block transmits an active low or negative infrared 3/16 pulse for all 0s and 1s are transmitted for 1s.
        unsigned RXDMUXSEL : 1; //!< RXD Muxed Input Selected. Selects proper input pins for serial and Infrared input signal. In this chip, UARTs are used in MUXED mode, so that this bit should always be set. In this chip, UARTs are used in Non-MUXED mode, so that this bit should always be cleared. 0 Input pin RXD (ipp_uart_rxd_mux) is not used for serial and IR interfaces 1 Input pin RXD (ipp_uart_rxd_mux) is used for serial and IR interfaces 0 Serial input pin is UART_RXD (ipp_uart_rxd) and IrDA input pin is UART_RXD_IR (ipp_uart_rxd_ir) 1 Input pin UART_RXD (ipp_uart_rxd) and UART_RXD_IR (ipp_uart_rxd_ir) are not used
        unsigned DTRDEN : 1; //!< This bit is not used in this chip. Data Terminal Ready Delta Enable . Enables / Disables the asynchronous DTRD interrupt. When DTRDEN is asserted and an edge (rising or falling) is detected on DTR (in DCE mode) or on DSR (in DTE mode), then an interrupt is generated.
        unsigned AWAKEN : 1; //!< Asynchronous WAKE Interrupt Enable. Controls the asynchronous WAKE interrupt. An interrupt is generated when AWAKEN is asserted and a falling edge is detected on the RXD pin.
        unsigned AIRINTEN : 1; //!< Asynchronous IR WAKE Interrupt Enable. Controls the asynchronous IR WAKE interrupt. An interrupt is generated when AIRINTEN is asserted and a pulse is detected on the RXD pin.
        unsigned RXDSEN : 1; //!< Receive Status Interrupt Enable. Controls the receive status interrupt ( interrupt_rx interrupt_uart ). When this bit is enabled and RXDS status bit is set, the interrupt interrupt_rx interrupt_uart will be generated.
        unsigned ADNIMP : 1; //!< Autobaud Detection Not Improved-. Disables new features of autobaud detection (See , for more details).
        unsigned RI : 1; //!< This bit is not used in this chip. Ring Indicator . In DCE mode this bit is used by software to control the RI output pin for the modem interface. In DTE mode, when this bit is set, it will enable the status bit RIDELT (USR2 (10)) to cause an interrupt.
        unsigned DCD : 1; //!< This bit is not used in this chip. Data Carrier Detect . In DCE mode this bit is used by software to control the DCD output pin for the modem interface. In DTE mode, when this bit is set, it will enable the status bit DCDDELT (USR2 (6)) to cause an interrupt.
        unsigned DSR : 1; //!< This bit is not used in this chip. Data Set Ready . This bit is used by software to control the DSR/DTR output pin for the modem interface. In DCE mode it applies to DSR and in DTE mode it applies to DTR .
        unsigned FRAERREN : 1; //!< Frame Error Interrupt Enable. Enables/Disables the interrupt. When asserted, FRAERREN causes the FRAMERR bit to generate an interrupt.
        unsigned PARERREN : 1; //!< Parity Error Interrupt Enable. Enables/Disables the interrupt. When asserted, PARERREN causes the PARITYERR bit to generate an interrupt.
        unsigned DTREN : 1; //!< This bit is not used in this chip. Data Terminal Ready Interrupt Enable . When this bit is set, it will enable the status bit DTRF (USR2 [13]) (DTR/DSR edge sensitive interrupt) to cause an interrupt.
        unsigned DPEC : 2; //!< This bit is not used in this chip. DTR/DSR Interrupt Edge Control . These bits control the edge of DTR (DCE) or DSR (DTE) on which an interrupt will be generated. An interrupt will only be generated if the DTREN bit is set.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ucr3_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR3 register
 */
#define HW_UARTV2_UCR3_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR3(x)           (*(volatile hw_uartv2_ucr3_t *) HW_UARTV2_UCR3_ADDR(x))
#define HW_UARTV2_UCR3_RD(x)        (HW_UARTV2_UCR3(x).U)
#define HW_UARTV2_UCR3_WR(x, v)     (HW_UARTV2_UCR3(x).U = (v))
#define HW_UARTV2_UCR3_SET(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) |  (v)))
#define HW_UARTV2_UCR3_CLR(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) & ~(v)))
#define HW_UARTV2_UCR3_TOG(x, v)    (HW_UARTV2_UCR3_WR(x, HW_UARTV2_UCR3_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UCR3 bitfields
 */

/* --- Register HW_UARTV2_UCR3, field ACIEN (RW)
 *
 * Autobaud Counter Interrupt Enable. This bit is used to enable the autobaud counter stopped
 * interrupt (triggered with ACST (USR2[11]).
 *
 * Values:
 * 0 - ACST interrupt disabled
 * 1 - ACST interrupt enabled
 */

#define BP_UARTV2_UCR3_ACIEN      0
#define BM_UARTV2_UCR3_ACIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_ACIEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR3_ACIEN)
#else
#define BF_UARTV2_UCR3_ACIEN(v)   (((v) << 0) & BM_UARTV2_UCR3_ACIEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACIEN field to a new value.
#define BW_UARTV2_UCR3_ACIEN(v)   BF_CS1(UARTV2_UCR3, ACIEN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field INVT (RW)
 *
 * Invert TXD output in RS-232/RS-485 mode, set TXD active level in IrDA mode. In RS232/RS-485
 * mode(UMCR[0] = 1), if this bit is set to 1, the TXD output is inverted before transmitted. In
 * IrDA mode , when INVT is cleared, the infrared logic block transmits a positive IR 3/16 pulse for
 * all 0s and 0s are transmitted for 1s. When INVT is set (INVT = 1), the infrared logic block
 * transmits an active low or negative infrared 3/16 pulse for all 0s and 1s are transmitted for 1s.
 *
 * Values:
 * 0 -  TXD is not inverted
 * 1 -  TXD is inverted
 * 0 - TXD  Active low transmission
 * 1 - TXD Active high transmission
 */

#define BP_UARTV2_UCR3_INVT      1
#define BM_UARTV2_UCR3_INVT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_INVT(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR3_INVT)
#else
#define BF_UARTV2_UCR3_INVT(v)   (((v) << 1) & BM_UARTV2_UCR3_INVT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVT field to a new value.
#define BW_UARTV2_UCR3_INVT(v)   BF_CS1(UARTV2_UCR3, INVT, v)
#endif


/* --- Register HW_UARTV2_UCR3, field RXDMUXSEL (RW)
 *
 * RXD Muxed Input Selected. Selects proper input pins for serial and Infrared input signal. In this
 * chip, UARTs are used in MUXED mode, so that this bit should always be set. In this chip, UARTs
 * are used in Non-MUXED mode, so that this bit should always be cleared. 0 Input pin RXD
 * (ipp_uart_rxd_mux) is not used for serial and IR interfaces 1 Input pin RXD (ipp_uart_rxd_mux) is
 * used for serial and IR interfaces 0 Serial input pin is UART_RXD (ipp_uart_rxd) and IrDA input
 * pin is UART_RXD_IR (ipp_uart_rxd_ir) 1 Input pin UART_RXD (ipp_uart_rxd) and UART_RXD_IR
 * (ipp_uart_rxd_ir) are not used
 */

#define BP_UARTV2_UCR3_RXDMUXSEL      2
#define BM_UARTV2_UCR3_RXDMUXSEL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RXDMUXSEL(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR3_RXDMUXSEL)
#else
#define BF_UARTV2_UCR3_RXDMUXSEL(v)   (((v) << 2) & BM_UARTV2_UCR3_RXDMUXSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDMUXSEL field to a new value.
#define BW_UARTV2_UCR3_RXDMUXSEL(v)   BF_CS1(UARTV2_UCR3, RXDMUXSEL, v)
#endif

/* --- Register HW_UARTV2_UCR3, field DTRDEN (RW)
 *
 * This bit is not used in this chip. Data Terminal Ready Delta Enable . Enables / Disables the
 * asynchronous DTRD interrupt. When DTRDEN is asserted and an edge (rising or falling) is detected
 * on DTR (in DCE mode) or on DSR (in DTE mode), then an interrupt is generated.
 *
 * Values:
 * 0 - Disable DTRD interrupt
 * 1 - Enable DTRD interrupt
 */

#define BP_UARTV2_UCR3_DTRDEN      3
#define BM_UARTV2_UCR3_DTRDEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DTRDEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR3_DTRDEN)
#else
#define BF_UARTV2_UCR3_DTRDEN(v)   (((v) << 3) & BM_UARTV2_UCR3_DTRDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRDEN field to a new value.
#define BW_UARTV2_UCR3_DTRDEN(v)   BF_CS1(UARTV2_UCR3, DTRDEN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field AWAKEN (RW)
 *
 * Asynchronous WAKE Interrupt Enable. Controls the asynchronous WAKE interrupt. An interrupt is
 * generated when AWAKEN is asserted and a falling edge is detected on the RXD pin.
 *
 * Values:
 * 0 - Disable the AWAKE interrupt
 * 1 - Enable the AWAKE interrupt
 */

#define BP_UARTV2_UCR3_AWAKEN      4
#define BM_UARTV2_UCR3_AWAKEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_AWAKEN(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR3_AWAKEN)
#else
#define BF_UARTV2_UCR3_AWAKEN(v)   (((v) << 4) & BM_UARTV2_UCR3_AWAKEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AWAKEN field to a new value.
#define BW_UARTV2_UCR3_AWAKEN(v)   BF_CS1(UARTV2_UCR3, AWAKEN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field AIRINTEN (RW)
 *
 * Asynchronous IR WAKE Interrupt Enable. Controls the asynchronous IR WAKE interrupt. An interrupt
 * is generated when AIRINTEN is asserted and a pulse is detected on the RXD pin.
 *
 * Values:
 * 0 - Disable the AIRINT interrupt
 * 1 - Enable the AIRINT interrupt
 */

#define BP_UARTV2_UCR3_AIRINTEN      5
#define BM_UARTV2_UCR3_AIRINTEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_AIRINTEN(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR3_AIRINTEN)
#else
#define BF_UARTV2_UCR3_AIRINTEN(v)   (((v) << 5) & BM_UARTV2_UCR3_AIRINTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AIRINTEN field to a new value.
#define BW_UARTV2_UCR3_AIRINTEN(v)   BF_CS1(UARTV2_UCR3, AIRINTEN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field RXDSEN (RW)
 *
 * Receive Status Interrupt Enable. Controls the receive status interrupt ( interrupt_rx
 * interrupt_uart ). When this bit is enabled and RXDS status bit is set, the interrupt interrupt_rx
 * interrupt_uart will be generated.
 *
 * Values:
 * 0 - Disable the RXDS interrupt
 * 1 - Enable the RXDS interrupt
 */

#define BP_UARTV2_UCR3_RXDSEN      6
#define BM_UARTV2_UCR3_RXDSEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RXDSEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR3_RXDSEN)
#else
#define BF_UARTV2_UCR3_RXDSEN(v)   (((v) << 6) & BM_UARTV2_UCR3_RXDSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEN field to a new value.
#define BW_UARTV2_UCR3_RXDSEN(v)   BF_CS1(UARTV2_UCR3, RXDSEN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field ADNIMP (RW)
 *
 * Autobaud Detection Not Improved-. Disables new features of autobaud detection (See , for more
 * details).
 *
 * Values:
 * 0 - Autobaud detection new features selected
 * 1 - Keep old autobaud detection mechanism
 */

#define BP_UARTV2_UCR3_ADNIMP      7
#define BM_UARTV2_UCR3_ADNIMP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_ADNIMP(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR3_ADNIMP)
#else
#define BF_UARTV2_UCR3_ADNIMP(v)   (((v) << 7) & BM_UARTV2_UCR3_ADNIMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADNIMP field to a new value.
#define BW_UARTV2_UCR3_ADNIMP(v)   BF_CS1(UARTV2_UCR3, ADNIMP, v)
#endif


/* --- Register HW_UARTV2_UCR3, field RI (RW)
 *
 * This bit is not used in this chip. Ring Indicator . In DCE mode this bit is used by software to
 * control the RI output pin for the modem interface. In DTE mode, when this bit is set, it will
 * enable the status bit RIDELT (USR2 (10)) to cause an interrupt.
 *
 * Values:
 * 0 - RI pin is logic zero (DCE mode)
 * 1 - RI pin is logic one (DCE mode)
 * 0 - RIDELT interrupt disabled (DTE mode)
 * 1 - RIDELT interrupt enabled (DTE mode)
 */

#define BP_UARTV2_UCR3_RI      8
#define BM_UARTV2_UCR3_RI      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_RI(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR3_RI)
#else
#define BF_UARTV2_UCR3_RI(v)   (((v) << 8) & BM_UARTV2_UCR3_RI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RI field to a new value.
#define BW_UARTV2_UCR3_RI(v)   BF_CS1(UARTV2_UCR3, RI, v)
#endif


/* --- Register HW_UARTV2_UCR3, field DCD (RW)
 *
 * This bit is not used in this chip. Data Carrier Detect . In DCE mode this bit is used by software
 * to control the DCD output pin for the modem interface. In DTE mode, when this bit is set, it will
 * enable the status bit DCDDELT (USR2 (6)) to cause an interrupt.
 *
 * Values:
 * 0 - DCD pin is logic zero (DCE mode)
 * 1 - DCD pin is logic one (DCE mode)
 * 0 - DCDDELT interrupt disabled (DTE mode)
 * 1 - DCDDELT interrupt enabled (DTE mode)
 */

#define BP_UARTV2_UCR3_DCD      9
#define BM_UARTV2_UCR3_DCD      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DCD(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR3_DCD)
#else
#define BF_UARTV2_UCR3_DCD(v)   (((v) << 9) & BM_UARTV2_UCR3_DCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCD field to a new value.
#define BW_UARTV2_UCR3_DCD(v)   BF_CS1(UARTV2_UCR3, DCD, v)
#endif


/* --- Register HW_UARTV2_UCR3, field DSR (RW)
 *
 * This bit is not used in this chip. Data Set Ready . This bit is used by software to control the
 * DSR/DTR output pin for the modem interface. In DCE mode it applies to DSR and in DTE mode it
 * applies to DTR .
 *
 * Values:
 * 0 - DSR/ DTR pin is logic zero
 * 1 - DSR/ DTR pin is logic one
 */

#define BP_UARTV2_UCR3_DSR      10
#define BM_UARTV2_UCR3_DSR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DSR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR3_DSR)
#else
#define BF_UARTV2_UCR3_DSR(v)   (((v) << 10) & BM_UARTV2_UCR3_DSR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSR field to a new value.
#define BW_UARTV2_UCR3_DSR(v)   BF_CS1(UARTV2_UCR3, DSR, v)
#endif


/* --- Register HW_UARTV2_UCR3, field FRAERREN (RW)
 *
 * Frame Error Interrupt Enable. Enables/Disables the interrupt. When asserted, FRAERREN causes the
 * FRAMERR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the frame error interrupt
 * 1 - Enable the frame error interrupt
 */

#define BP_UARTV2_UCR3_FRAERREN      11
#define BM_UARTV2_UCR3_FRAERREN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_FRAERREN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UCR3_FRAERREN)
#else
#define BF_UARTV2_UCR3_FRAERREN(v)   (((v) << 11) & BM_UARTV2_UCR3_FRAERREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAERREN field to a new value.
#define BW_UARTV2_UCR3_FRAERREN(v)   BF_CS1(UARTV2_UCR3, FRAERREN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field PARERREN (RW)
 *
 * Parity Error Interrupt Enable. Enables/Disables the interrupt. When asserted, PARERREN causes the
 * PARITYERR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the parity error interrupt
 * 1 - Enable the parity error interrupt
 */

#define BP_UARTV2_UCR3_PARERREN      12
#define BM_UARTV2_UCR3_PARERREN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_PARERREN(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UCR3_PARERREN)
#else
#define BF_UARTV2_UCR3_PARERREN(v)   (((v) << 12) & BM_UARTV2_UCR3_PARERREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PARERREN field to a new value.
#define BW_UARTV2_UCR3_PARERREN(v)   BF_CS1(UARTV2_UCR3, PARERREN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field DTREN (RW)
 *
 * This bit is not used in this chip. Data Terminal Ready Interrupt Enable . When this bit is set,
 * it will enable the status bit DTRF (USR2 [13]) (DTR/DSR edge sensitive interrupt) to cause an
 * interrupt.
 *
 * Values:
 * 0 - Data Terminal Ready Interrupt Disabled
 * 1 - Data Terminal Ready Interrupt Enabled
 */

#define BP_UARTV2_UCR3_DTREN      13
#define BM_UARTV2_UCR3_DTREN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DTREN(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UCR3_DTREN)
#else
#define BF_UARTV2_UCR3_DTREN(v)   (((v) << 13) & BM_UARTV2_UCR3_DTREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTREN field to a new value.
#define BW_UARTV2_UCR3_DTREN(v)   BF_CS1(UARTV2_UCR3, DTREN, v)
#endif


/* --- Register HW_UARTV2_UCR3, field DPEC (RW)
 *
 * This bit is not used in this chip. DTR/DSR Interrupt Edge Control . These bits control the edge
 * of DTR (DCE) or DSR (DTE) on which an interrupt will be generated. An interrupt will only be
 * generated if the DTREN bit is set.
 *
 * Values:
 * 00 - interrupt generated on rising edge
 * 01 - interrupt generated on falling edge
 * 1X - interrupt generated on either edge
 */

#define BP_UARTV2_UCR3_DPEC      14
#define BM_UARTV2_UCR3_DPEC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR3_DPEC(v)   ((((reg32_t) v) << 14) & BM_UARTV2_UCR3_DPEC)
#else
#define BF_UARTV2_UCR3_DPEC(v)   (((v) << 14) & BM_UARTV2_UCR3_DPEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPEC field to a new value.
#define BW_UARTV2_UCR3_DPEC(v)   BF_CS1(UARTV2_UCR3, DPEC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UCR4 - UART Control Register 4 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DREN : 1; //!< Receive Data Ready Interrupt Enable . Enables/Disables the RDR bit to generate an interrupt.
        unsigned OREN : 1; //!< Receiver Overrun Interrupt Enable . Enables/Disables the ORE bit to generate an interrupt.
        unsigned BKEN : 1; //!< BREAK Condition Detected Interrupt Enable . Enables/Disables the BRCD bit to generate an interrupt.
        unsigned TCEN : 1; //!< Transmit Complete Interrupt Enable . Enables/Disables the TXDC bit to generate an interrupt ( interrupt_tx interrupt_uart = 0) An interrupt will be issued as long as TCEN and TXDC are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TXDC interrupt.
        unsigned LPBYP : 1; //!< Low Power Bypass . Allows to bypass the low power new features in UART. To use during debug phase.
        unsigned IRSC : 1; //!< IR Special Case . Selects the clock for the vote logic. When set, IRSC switches the vote logic clock from the sampling clock to the UART reference clock. The IR pulses are counted a predetermined amount of time depending on the reference frequency. See .
        unsigned IDDMAEN : 1; //!< DMA IDLE Condition Detected Interrupt Enable Enables/Disables the receive DMA request dma_req_rx for the IDLE interrupt (triggered with IDLE flag in USR2[12]).
        unsigned WKEN : 1; //!< WAKE Interrupt Enable . Enables/Disables the WAKE bit to generate an interrupt. The WAKE bit is set at the detection of a start bit by the receiver.
        unsigned ENIRI : 1; //!< Serial Infrared Interrupt Enable . Enables/Disables the serial infrared interrupt.
        unsigned INVR : 1; //!< Invert RXD input in RS-232/RS-485 Mode, d etermine RXD input logic level being sampled in In IrDA mode. In RS232/RS-485 Mode(UMCR[0] = 1), if this bit is set to 1, the RXD input is inverted before sampled. In IrDA mode ,when cleared, the infrared logic block expects an active low or negative IR 3/16 pulse for 0s and 1s are expected for 1s. When INVR is set (INVR 1), the infrared logic block expects an active high or positive IR 3/16 pulse for 0s and 0s are expected for 1s.
        unsigned CTSTL : 6; //!< CTS Trigger Level . Controls the threshold at which the CTS pin is deasserted by the RxFIFO. After the trigger level is reached and the CTS pin is deasserted, the RxFIFO continues to receive data until it is full. The CTSTL bits are encoded as shown in the Settings column. Settings 0 to 32 are in use. All other settings are Reserved.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ucr4_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UCR4 register
 */
#define HW_UARTV2_UCR4_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UCR4(x)           (*(volatile hw_uartv2_ucr4_t *) HW_UARTV2_UCR4_ADDR(x))
#define HW_UARTV2_UCR4_RD(x)        (HW_UARTV2_UCR4(x).U)
#define HW_UARTV2_UCR4_WR(x, v)     (HW_UARTV2_UCR4(x).U = (v))
#define HW_UARTV2_UCR4_SET(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) |  (v)))
#define HW_UARTV2_UCR4_CLR(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) & ~(v)))
#define HW_UARTV2_UCR4_TOG(x, v)    (HW_UARTV2_UCR4_WR(x, HW_UARTV2_UCR4_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UCR4 bitfields
 */

/* --- Register HW_UARTV2_UCR4, field DREN (RW)
 *
 * Receive Data Ready Interrupt Enable . Enables/Disables the RDR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable RDR interrupt
 * 1 - Enable RDR interrupt
 */

#define BP_UARTV2_UCR4_DREN      0
#define BM_UARTV2_UCR4_DREN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_DREN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UCR4_DREN)
#else
#define BF_UARTV2_UCR4_DREN(v)   (((v) << 0) & BM_UARTV2_UCR4_DREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DREN field to a new value.
#define BW_UARTV2_UCR4_DREN(v)   BF_CS1(UARTV2_UCR4, DREN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field OREN (RW)
 *
 * Receiver Overrun Interrupt Enable . Enables/Disables the ORE bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable ORE interrupt
 * 1 - Enable ORE interrupt
 */

#define BP_UARTV2_UCR4_OREN      1
#define BM_UARTV2_UCR4_OREN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_OREN(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UCR4_OREN)
#else
#define BF_UARTV2_UCR4_OREN(v)   (((v) << 1) & BM_UARTV2_UCR4_OREN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OREN field to a new value.
#define BW_UARTV2_UCR4_OREN(v)   BF_CS1(UARTV2_UCR4, OREN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field BKEN (RW)
 *
 * BREAK Condition Detected Interrupt Enable . Enables/Disables the BRCD bit to generate an
 * interrupt.
 *
 * Values:
 * 0 - Disable the BRCD interrupt
 * 1 - Enable the BRCD interrupt
 */

#define BP_UARTV2_UCR4_BKEN      2
#define BM_UARTV2_UCR4_BKEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_BKEN(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UCR4_BKEN)
#else
#define BF_UARTV2_UCR4_BKEN(v)   (((v) << 2) & BM_UARTV2_UCR4_BKEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BKEN field to a new value.
#define BW_UARTV2_UCR4_BKEN(v)   BF_CS1(UARTV2_UCR4, BKEN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field TCEN (RW)
 *
 * Transmit Complete Interrupt Enable . Enables/Disables the TXDC bit to generate an interrupt (
 * interrupt_tx interrupt_uart = 0) An interrupt will be issued as long as TCEN and TXDC are high
 * even if the transmitter is not enabled. In general, user should enable the transmitter before
 * enabling the TXDC interrupt.
 *
 * Values:
 * 0 - Disable TXDC interrupt
 * 1 - Enable TXDC interrupt
 */

#define BP_UARTV2_UCR4_TCEN      3
#define BM_UARTV2_UCR4_TCEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_TCEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UCR4_TCEN)
#else
#define BF_UARTV2_UCR4_TCEN(v)   (((v) << 3) & BM_UARTV2_UCR4_TCEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCEN field to a new value.
#define BW_UARTV2_UCR4_TCEN(v)   BF_CS1(UARTV2_UCR4, TCEN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field LPBYP (RW)
 *
 * Low Power Bypass . Allows to bypass the low power new features in UART. To use during debug
 * phase.
 *
 * Values:
 * 0 - Low power features enabled
 * 1 - Low power features disabled
 */

#define BP_UARTV2_UCR4_LPBYP      4
#define BM_UARTV2_UCR4_LPBYP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_LPBYP(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UCR4_LPBYP)
#else
#define BF_UARTV2_UCR4_LPBYP(v)   (((v) << 4) & BM_UARTV2_UCR4_LPBYP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LPBYP field to a new value.
#define BW_UARTV2_UCR4_LPBYP(v)   BF_CS1(UARTV2_UCR4, LPBYP, v)
#endif


/* --- Register HW_UARTV2_UCR4, field IRSC (RW)
 *
 * IR Special Case . Selects the clock for the vote logic. When set, IRSC switches the vote logic
 * clock from the sampling clock to the UART reference clock. The IR pulses are counted a
 * predetermined amount of time depending on the reference frequency. See .
 *
 * Values:
 * 0 - The vote logic uses the sampling clock (16x baud rate) for normal operation
 * 1 - The vote logic uses the UART reference clock
 */

#define BP_UARTV2_UCR4_IRSC      5
#define BM_UARTV2_UCR4_IRSC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_IRSC(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UCR4_IRSC)
#else
#define BF_UARTV2_UCR4_IRSC(v)   (((v) << 5) & BM_UARTV2_UCR4_IRSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRSC field to a new value.
#define BW_UARTV2_UCR4_IRSC(v)   BF_CS1(UARTV2_UCR4, IRSC, v)
#endif


/* --- Register HW_UARTV2_UCR4, field IDDMAEN (RW)
 *
 * DMA IDLE Condition Detected Interrupt Enable Enables/Disables the receive DMA request dma_req_rx
 * for the IDLE interrupt (triggered with IDLE flag in USR2[12]).
 *
 * Values:
 * 0 - DMA IDLE interrupt disabled
 * 1 - DMA IDLE interrupt enabled
 */

#define BP_UARTV2_UCR4_IDDMAEN      6
#define BM_UARTV2_UCR4_IDDMAEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_IDDMAEN(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UCR4_IDDMAEN)
#else
#define BF_UARTV2_UCR4_IDDMAEN(v)   (((v) << 6) & BM_UARTV2_UCR4_IDDMAEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDDMAEN field to a new value.
#define BW_UARTV2_UCR4_IDDMAEN(v)   BF_CS1(UARTV2_UCR4, IDDMAEN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field WKEN (RW)
 *
 * WAKE Interrupt Enable . Enables/Disables the WAKE bit to generate an interrupt. The WAKE bit is
 * set at the detection of a start bit by the receiver.
 *
 * Values:
 * 0 - Disable the WAKE interrupt
 * 1 - Enable the WAKE interrupt
 */

#define BP_UARTV2_UCR4_WKEN      7
#define BM_UARTV2_UCR4_WKEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_WKEN(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UCR4_WKEN)
#else
#define BF_UARTV2_UCR4_WKEN(v)   (((v) << 7) & BM_UARTV2_UCR4_WKEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKEN field to a new value.
#define BW_UARTV2_UCR4_WKEN(v)   BF_CS1(UARTV2_UCR4, WKEN, v)
#endif


/* --- Register HW_UARTV2_UCR4, field ENIRI (RW)
 *
 * Serial Infrared Interrupt Enable . Enables/Disables the serial infrared interrupt.
 *
 * Values:
 * 0 - Serial infrared Interrupt disabled
 * 1 - Serial infrared Interrupt enabled
 */

#define BP_UARTV2_UCR4_ENIRI      8
#define BM_UARTV2_UCR4_ENIRI      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_ENIRI(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UCR4_ENIRI)
#else
#define BF_UARTV2_UCR4_ENIRI(v)   (((v) << 8) & BM_UARTV2_UCR4_ENIRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRI field to a new value.
#define BW_UARTV2_UCR4_ENIRI(v)   BF_CS1(UARTV2_UCR4, ENIRI, v)
#endif


/* --- Register HW_UARTV2_UCR4, field INVR (RW)
 *
 * Invert RXD input in RS-232/RS-485 Mode, d etermine RXD input logic level being sampled in In IrDA
 * mode. In RS232/RS-485 Mode(UMCR[0] = 1), if this bit is set to 1, the RXD input is inverted
 * before sampled. In IrDA mode ,when cleared, the infrared logic block expects an active low or
 * negative IR 3/16 pulse for 0s and 1s are expected for 1s. When INVR is set (INVR 1), the infrared
 * logic block expects an active high or positive IR 3/16 pulse for 0s and 0s are expected for 1s.
 *
 * Values:
 * 0 -  RXD input is not inverted
 * 1 -  RXD input is inverted
 * 0 - RXD active low detection
 * 1 - RXD active high detection
 */

#define BP_UARTV2_UCR4_INVR      9
#define BM_UARTV2_UCR4_INVR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_INVR(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UCR4_INVR)
#else
#define BF_UARTV2_UCR4_INVR(v)   (((v) << 9) & BM_UARTV2_UCR4_INVR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INVR field to a new value.
#define BW_UARTV2_UCR4_INVR(v)   BF_CS1(UARTV2_UCR4, INVR, v)
#endif


/* --- Register HW_UARTV2_UCR4, field CTSTL (RW)
 *
 * CTS Trigger Level . Controls the threshold at which the CTS pin is deasserted by the RxFIFO.
 * After the trigger level is reached and the CTS pin is deasserted, the RxFIFO continues to receive
 * data until it is full. The CTSTL bits are encoded as shown in the Settings column. Settings 0 to
 * 32 are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - 0 characters received
 * 000001 - 1 characters in the RxFIFO
 * ... - 
 * ... - 
 * 100000 - 32 characters in the RxFIFO (maximum)
 */

#define BP_UARTV2_UCR4_CTSTL      10
#define BM_UARTV2_UCR4_CTSTL      0x0000fc00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UCR4_CTSTL(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UCR4_CTSTL)
#else
#define BF_UARTV2_UCR4_CTSTL(v)   (((v) << 10) & BM_UARTV2_UCR4_CTSTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CTSTL field to a new value.
#define BW_UARTV2_UCR4_CTSTL(v)   BF_CS1(UARTV2_UCR4, CTSTL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UFCR - UART FIFO Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXTL : 6; //!< Receiver Trigger Level . Controls the threshold at which a maskable interrupt is generated by the RxFIFO. A maskable interrupt is generated whenever the data level in the RxFIFO reaches the selected threshold. The RXTL bits are encoded as shown in the Settings column. Setting 0 to 32 are in use. All other settings are Reserved.
        unsigned DCEDTE : 1; //!< DCE/DTE mode select . Select UART as data communication equipment (DCE mode) or as data terminal equipment (DTE mode).
        unsigned RFDIV : 3; //!< Reference Frequency Divider. Controls the divide ratio for the reference clock. The input clock is module_clock (ipg_perclk) . The output from the divider is ref_clk which is used by BRM to create the 16x baud rate oversampling clock ( brm_clk ).
        unsigned TXTL : 6; //!< Transmitter Trigger Level . Controls the threshold at which a maskable interrupt is generated by the TxFIFO. A maskable interrupt is generated whenever the data level in the TxFIFO falls below the selected threshold. The bits are encoded as shown in the Settings column. Settings 0 to 32 are in use. All other settings are Reserved.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ufcr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UFCR register
 */
#define HW_UARTV2_UFCR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UFCR(x)           (*(volatile hw_uartv2_ufcr_t *) HW_UARTV2_UFCR_ADDR(x))
#define HW_UARTV2_UFCR_RD(x)        (HW_UARTV2_UFCR(x).U)
#define HW_UARTV2_UFCR_WR(x, v)     (HW_UARTV2_UFCR(x).U = (v))
#define HW_UARTV2_UFCR_SET(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) |  (v)))
#define HW_UARTV2_UFCR_CLR(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) & ~(v)))
#define HW_UARTV2_UFCR_TOG(x, v)    (HW_UARTV2_UFCR_WR(x, HW_UARTV2_UFCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UFCR bitfields
 */

/* --- Register HW_UARTV2_UFCR, field RXTL (RW)
 *
 * Receiver Trigger Level . Controls the threshold at which a maskable interrupt is generated by the
 * RxFIFO. A maskable interrupt is generated whenever the data level in the RxFIFO reaches the
 * selected threshold. The RXTL bits are encoded as shown in the Settings column. Setting 0 to 32
 * are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - 0 characters received
 * 000001 - RxFIFO has 1 character
 * ... - 
 * ... - 
 * 011111 - RxFIFO has 31 characters
 * 100000 - RxFIFO has 32 characters (maximum)
 */

#define BP_UARTV2_UFCR_RXTL      0
#define BM_UARTV2_UFCR_RXTL      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_RXTL(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UFCR_RXTL)
#else
#define BF_UARTV2_UFCR_RXTL(v)   (((v) << 0) & BM_UARTV2_UFCR_RXTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXTL field to a new value.
#define BW_UARTV2_UFCR_RXTL(v)   BF_CS1(UARTV2_UFCR, RXTL, v)
#endif


/* --- Register HW_UARTV2_UFCR, field DCEDTE (RW)
 *
 * DCE/DTE mode select . Select UART as data communication equipment (DCE mode) or as data terminal
 * equipment (DTE mode).
 *
 * Values:
 * 0 - DCE mode selected
 * 1 - DTE mode selected
 */

#define BP_UARTV2_UFCR_DCEDTE      6
#define BM_UARTV2_UFCR_DCEDTE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_DCEDTE(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UFCR_DCEDTE)
#else
#define BF_UARTV2_UFCR_DCEDTE(v)   (((v) << 6) & BM_UARTV2_UFCR_DCEDTE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCEDTE field to a new value.
#define BW_UARTV2_UFCR_DCEDTE(v)   BF_CS1(UARTV2_UFCR, DCEDTE, v)
#endif


/* --- Register HW_UARTV2_UFCR, field RFDIV (RW)
 *
 * Reference Frequency Divider. Controls the divide ratio for the reference clock. The input clock
 * is module_clock (ipg_perclk) . The output from the divider is ref_clk which is used by BRM to
 * create the 16x baud rate oversampling clock ( brm_clk ).
 *
 * Values:
 * 000 - Divide input clock by 6
 * 001 - Divide input clock by 5
 * 010 - Divide input clock by 4
 * 011 - Divide input clock by 3
 * 100 - Divide input clock by 2
 * 101 - Divide input clock by 1
 * 110 - Divide input clock by 7
 * 111 - Reserved
 */

#define BP_UARTV2_UFCR_RFDIV      7
#define BM_UARTV2_UFCR_RFDIV      0x00000380

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_RFDIV(v)   ((((reg32_t) v) << 7) & BM_UARTV2_UFCR_RFDIV)
#else
#define BF_UARTV2_UFCR_RFDIV(v)   (((v) << 7) & BM_UARTV2_UFCR_RFDIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFDIV field to a new value.
#define BW_UARTV2_UFCR_RFDIV(v)   BF_CS1(UARTV2_UFCR, RFDIV, v)
#endif


/* --- Register HW_UARTV2_UFCR, field TXTL (RW)
 *
 * Transmitter Trigger Level . Controls the threshold at which a maskable interrupt is generated by
 * the TxFIFO. A maskable interrupt is generated whenever the data level in the TxFIFO falls below
 * the selected threshold. The bits are encoded as shown in the Settings column. Settings 0 to 32
 * are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - Reserved
 * 000001 - Reserved
 * 000010 - TxFIFO has 2 or fewer characters
 * ... - 
 * ... - 
 * 011111 - TxFIFO has 31 or fewer characters
 * 100000 - TxFIFO has 32 characters (maximum)
 */

#define BP_UARTV2_UFCR_TXTL      10
#define BM_UARTV2_UFCR_TXTL      0x0000fc00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UFCR_TXTL(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UFCR_TXTL)
#else
#define BF_UARTV2_UFCR_TXTL(v)   (((v) << 10) & BM_UARTV2_UFCR_TXTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXTL field to a new value.
#define BW_UARTV2_UFCR_TXTL(v)   BF_CS1(UARTV2_UFCR, TXTL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_USR1 - UART Status Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned SAD : 1; //!< RS-485 Slave Address Detected Interrupt Flag. Indicates if RS-485 Slave Address was detected . SAD was asserted in RS-485 mode when the SADEN bit is set and Slave Address is detected in RxFIFO (in Nomal Address Detect Mode, the 9 th data bit = 1; in Automatic Address Detect Mode, the received charater matches the programmed SLADDR).
        unsigned AWAKE : 1; //!< Asynchronous WAKE Interrupt Flag. Indicates that a falling edge was detected on the UART_RXD_IR RXD pin. Clear AWAKE by writing 1 to it. Writing 0 to AWAKE has no effect. Caution: AWAKE Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not (see UART RS-485 Mode Control Register ).
        unsigned AIRINT : 1; //!< Asynchronous IR WAKE Interrupt Flag. Indicates that the IR WAKE pulse was detected on the UART_RXD_IR RXD pin. Clear AIRINT by writing 1 to it. Writing 0 to AIRINT has no effect. Caution: AIRINT Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not (see ).
        unsigned RXDS : 1; //!< Receiver IDLE Interrupt Flag. Indicates that the receiver state machine is in an IDLE state, the next state is IDLE, and the receive pin is high. RXDS is automatically cleared when a character is received. RXDS is active only when the receiver is enabled.
        unsigned DTRD : 1; //!< This bit is not used in this chip. DTR Delta. Indicates whether DTR (in DCE mode) or DSR (in DTE mode) pins changed state. DTRD generates a maskable interrupt if DTRDEN (UCR3[3]) is set. Clear DTRD by writing 1 to it. Writing 0 to DTRD has no effect.
        unsigned AGTIM : 1; //!< Ageing Timer Interrupt Flag. Indicates that data in the RxFIFO has been idle for a time of 8 character lengths (where a character length consists of 7 or 8 bits, depending on the setting of the WS bit in UCR2, with the bit time corresponding to the baud rate setting) and FIFO data level is less than RxFIFO threshold level (RXTL in the UFCR). Clear by writing a 1 to it.
        unsigned RRDY : 1; //!< Receiver Ready Interrupt / DMA Flag . Indicates that the RxFIFO data level is above the threshold set by the RXTL bits. (See the RXTL bits description in for setting the interrupt threshold.) When asserted, RRDY generates a maskable interrupt or DMA request. RRDY is automatically cleared when data level in the RxFIFO goes below the set threshold level. At reset, RRDY is set to 0.
        unsigned FRAMERR : 1; //!< Frame Error Interrupt Flag . Indicates that a frame error is detected. The interrupt_mint interrupt_uart interrupt will be generated if a frame error is detected and the interrupt is enabled. Clear FRAMERR by writing 1 to it. Writing 0 to FRAMERR has no effect.
        unsigned ESCF : 1; //!< Escape Sequence Interrupt Flag . Indicates if an escape sequence was detected. ESCF is asserted when the ESCEN bit is set and an escape sequence is detected in the RxFIFO. Clear ESCF by writing 1 to it. Writing 0 to ESCF has no effect.
        unsigned RTSD : 1; //!< RTS Delta. Indicates whether the RTS pin changed state. It (RTSD) generates a maskable interrupt. When in STOP mode, RTS assertion sets RTSD and can be used to wake the processor. The current state of the RTS pin is available on the RTSS bit. Clear RTSD by writing 1 to it. Writing 0 to RTSD has no effect. At reset, RTSD is set to 0.
        unsigned TRDY : 1; //!< Transmitter Ready Interrupt / DMA Flag . Indicates that the TxFIFO emptied below its target threshold and requires data. TRDY is automatically cleared when the data level in the TxFIFO exceeds the threshold set by TXTL bits. At reset, TRDY is set to 1.
        unsigned RTSS : 1; //!< RTS Pin Status . Indicates the current status of the RTS pin. A "snapshot" of the pin is taken immediately before RTSS is presented to the data bus. RTSS cannot be cleared because all writes to RTSS are ignored. At reset, RTSS is set to 0.
        unsigned PARITYERR : 1; //!< Parity Error Interrupt Flag . Indicates a parity error is detected. PARITYERR is cleared by writing 1 to it. Writing 0 to PARITYERR has no effect. When parity is disabled, PARITYERR always reads 0. At reset, PARITYERR is set to 0.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_uartv2_usr1_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_USR1 register
 */
#define HW_UARTV2_USR1_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_USR1(x)           (*(volatile hw_uartv2_usr1_t *) HW_UARTV2_USR1_ADDR(x))
#define HW_UARTV2_USR1_RD(x)        (HW_UARTV2_USR1(x).U)
#define HW_UARTV2_USR1_WR(x, v)     (HW_UARTV2_USR1(x).U = (v))
#define HW_UARTV2_USR1_SET(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) |  (v)))
#define HW_UARTV2_USR1_CLR(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) & ~(v)))
#define HW_UARTV2_USR1_TOG(x, v)    (HW_UARTV2_USR1_WR(x, HW_UARTV2_USR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_USR1 bitfields
 */

/* --- Register HW_UARTV2_USR1, field SAD (W1C)
 *
 * RS-485 Slave Address Detected Interrupt Flag. Indicates if RS-485 Slave Address was detected .
 * SAD was asserted in RS-485 mode when the SADEN bit is set and Slave Address is detected in RxFIFO
 * (in Nomal Address Detect Mode, the 9 th data bit = 1; in Automatic Address Detect Mode, the
 * received charater matches the programmed SLADDR).
 *
 * Values:
 * 0 - No slave address detected
 * 1 - Slave address detected
 */

#define BP_UARTV2_USR1_SAD      3
#define BM_UARTV2_USR1_SAD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_SAD(v)   ((((reg32_t) v) << 3) & BM_UARTV2_USR1_SAD)
#else
#define BF_UARTV2_USR1_SAD(v)   (((v) << 3) & BM_UARTV2_USR1_SAD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SAD field to a new value.
#define BW_UARTV2_USR1_SAD(v)   BF_CS1(UARTV2_USR1, SAD, v)
#endif


/* --- Register HW_UARTV2_USR1, field AWAKE (W1C)
 *
 * Asynchronous WAKE Interrupt Flag. Indicates that a falling edge was detected on the UART_RXD_IR
 * RXD pin. Clear AWAKE by writing 1 to it. Writing 0 to AWAKE has no effect. Caution: AWAKE
 * Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not
 * (see UART RS-485 Mode Control Register ).
 *
 * Values:
 * 0 - No falling edge was detected on the RXD Serial pin
 * 1 - A falling edge was detected on the RXD Serial pin
 */

#define BP_UARTV2_USR1_AWAKE      4
#define BM_UARTV2_USR1_AWAKE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AWAKE(v)   ((((reg32_t) v) << 4) & BM_UARTV2_USR1_AWAKE)
#else
#define BF_UARTV2_USR1_AWAKE(v)   (((v) << 4) & BM_UARTV2_USR1_AWAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AWAKE field to a new value.
#define BW_UARTV2_USR1_AWAKE(v)   BF_CS1(UARTV2_USR1, AWAKE, v)
#endif


/* --- Register HW_UARTV2_USR1, field AIRINT (W1C)
 *
 * Asynchronous IR WAKE Interrupt Flag. Indicates that the IR WAKE pulse was detected on the
 * UART_RXD_IR RXD pin. Clear AIRINT by writing 1 to it. Writing 0 to AIRINT has no effect. Caution:
 * AIRINT Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1)
 * or not (see ).
 *
 * Values:
 * 0 - No pulse was detected on the RXD IrDA pin
 * 1 - A pulse was detected on the RXD IrDA pin
 */

#define BP_UARTV2_USR1_AIRINT      5
#define BM_UARTV2_USR1_AIRINT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AIRINT(v)   ((((reg32_t) v) << 5) & BM_UARTV2_USR1_AIRINT)
#else
#define BF_UARTV2_USR1_AIRINT(v)   (((v) << 5) & BM_UARTV2_USR1_AIRINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AIRINT field to a new value.
#define BW_UARTV2_USR1_AIRINT(v)   BF_CS1(UARTV2_USR1, AIRINT, v)
#endif


/* --- Register HW_UARTV2_USR1, field RXDS (RO)
 *
 * Receiver IDLE Interrupt Flag. Indicates that the receiver state machine is in an IDLE state, the
 * next state is IDLE, and the receive pin is high. RXDS is automatically cleared when a character
 * is received. RXDS is active only when the receiver is enabled.
 *
 * Values:
 * 0 - Receive in progress
 * 1 - Receiver is IDLE
 */

#define BP_UARTV2_USR1_RXDS      6
#define BM_UARTV2_USR1_RXDS      0x00000040


/* --- Register HW_UARTV2_USR1, field DTRD (W1C)
 *
 * This bit is not used in this chip. DTR Delta. Indicates whether DTR (in DCE mode) or DSR (in DTE
 * mode) pins changed state. DTRD generates a maskable interrupt if DTRDEN (UCR3[3]) is set. Clear
 * DTRD by writing 1 to it. Writing 0 to DTRD has no effect.
 *
 * Values:
 * 0 - DTR (DCE) or DSR (DTE) pin did not change state since last cleared
 * 1 - DTR (DCE) or DSR (DTE) pin changed state (write 1 to clear)
 */

#define BP_UARTV2_USR1_DTRD      7
#define BM_UARTV2_USR1_DTRD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_DTRD(v)   ((((reg32_t) v) << 7) & BM_UARTV2_USR1_DTRD)
#else
#define BF_UARTV2_USR1_DTRD(v)   (((v) << 7) & BM_UARTV2_USR1_DTRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRD field to a new value.
#define BW_UARTV2_USR1_DTRD(v)   BF_CS1(UARTV2_USR1, DTRD, v)
#endif


/* --- Register HW_UARTV2_USR1, field AGTIM (W1C)
 *
 * Ageing Timer Interrupt Flag. Indicates that data in the RxFIFO has been idle for a time of 8
 * character lengths (where a character length consists of 7 or 8 bits, depending on the setting of
 * the WS bit in UCR2, with the bit time corresponding to the baud rate setting) and FIFO data level
 * is less than RxFIFO threshold level (RXTL in the UFCR). Clear by writing a 1 to it.
 *
 * Values:
 * 0 - AGTIM is not active
 * 1 - AGTIM is active (write 1 to clear)
 */

#define BP_UARTV2_USR1_AGTIM      8
#define BM_UARTV2_USR1_AGTIM      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_AGTIM(v)   ((((reg32_t) v) << 8) & BM_UARTV2_USR1_AGTIM)
#else
#define BF_UARTV2_USR1_AGTIM(v)   (((v) << 8) & BM_UARTV2_USR1_AGTIM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AGTIM field to a new value.
#define BW_UARTV2_USR1_AGTIM(v)   BF_CS1(UARTV2_USR1, AGTIM, v)
#endif


/* --- Register HW_UARTV2_USR1, field RRDY (RO)
 *
 * Receiver Ready Interrupt / DMA Flag . Indicates that the RxFIFO data level is above the threshold
 * set by the RXTL bits. (See the RXTL bits description in for setting the interrupt threshold.)
 * When asserted, RRDY generates a maskable interrupt or DMA request. RRDY is automatically cleared
 * when data level in the RxFIFO goes below the set threshold level. At reset, RRDY is set to 0.
 *
 * Values:
 * 0 - No character ready
 * 1 - Character(s) ready (interrupt posted)
 */

#define BP_UARTV2_USR1_RRDY      9
#define BM_UARTV2_USR1_RRDY      0x00000200


/* --- Register HW_UARTV2_USR1, field FRAMERR (W1C)
 *
 * Frame Error Interrupt Flag . Indicates that a frame error is detected. The interrupt_mint
 * interrupt_uart interrupt will be generated if a frame error is detected and the interrupt is
 * enabled. Clear FRAMERR by writing 1 to it. Writing 0 to FRAMERR has no effect.
 *
 * Values:
 * 0 - No frame error detected
 * 1 - Frame error detected (write 1 to clear)
 */

#define BP_UARTV2_USR1_FRAMERR      10
#define BM_UARTV2_USR1_FRAMERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_FRAMERR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_USR1_FRAMERR)
#else
#define BF_UARTV2_USR1_FRAMERR(v)   (((v) << 10) & BM_UARTV2_USR1_FRAMERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAMERR field to a new value.
#define BW_UARTV2_USR1_FRAMERR(v)   BF_CS1(UARTV2_USR1, FRAMERR, v)
#endif


/* --- Register HW_UARTV2_USR1, field ESCF (W1C)
 *
 * Escape Sequence Interrupt Flag . Indicates if an escape sequence was detected. ESCF is asserted
 * when the ESCEN bit is set and an escape sequence is detected in the RxFIFO. Clear ESCF by writing
 * 1 to it. Writing 0 to ESCF has no effect.
 *
 * Values:
 * 0 - No escape sequence detected
 * 1 - Escape sequence detected (write 1 to clear).
 */

#define BP_UARTV2_USR1_ESCF      11
#define BM_UARTV2_USR1_ESCF      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_ESCF(v)   ((((reg32_t) v) << 11) & BM_UARTV2_USR1_ESCF)
#else
#define BF_UARTV2_USR1_ESCF(v)   (((v) << 11) & BM_UARTV2_USR1_ESCF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCF field to a new value.
#define BW_UARTV2_USR1_ESCF(v)   BF_CS1(UARTV2_USR1, ESCF, v)
#endif


/* --- Register HW_UARTV2_USR1, field RTSD (W1C)
 *
 * RTS Delta. Indicates whether the RTS pin changed state. It (RTSD) generates a maskable interrupt.
 * When in STOP mode, RTS assertion sets RTSD and can be used to wake the processor. The current
 * state of the RTS pin is available on the RTSS bit. Clear RTSD by writing 1 to it. Writing 0 to
 * RTSD has no effect. At reset, RTSD is set to 0.
 *
 * Values:
 * 0 - RTS pin did not change state since last cleared
 * 1 - RTS pin changed state (write 1 to clear)
 */

#define BP_UARTV2_USR1_RTSD      12
#define BM_UARTV2_USR1_RTSD      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_RTSD(v)   ((((reg32_t) v) << 12) & BM_UARTV2_USR1_RTSD)
#else
#define BF_UARTV2_USR1_RTSD(v)   (((v) << 12) & BM_UARTV2_USR1_RTSD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSD field to a new value.
#define BW_UARTV2_USR1_RTSD(v)   BF_CS1(UARTV2_USR1, RTSD, v)
#endif


/* --- Register HW_UARTV2_USR1, field TRDY (RO)
 *
 * Transmitter Ready Interrupt / DMA Flag . Indicates that the TxFIFO emptied below its target
 * threshold and requires data. TRDY is automatically cleared when the data level in the TxFIFO
 * exceeds the threshold set by TXTL bits. At reset, TRDY is set to 1.
 *
 * Values:
 * 0 - The transmitter does not require data
 * 1 - The transmitter requires data (interrupt posted)
 */

#define BP_UARTV2_USR1_TRDY      13
#define BM_UARTV2_USR1_TRDY      0x00002000


/* --- Register HW_UARTV2_USR1, field RTSS (RO)
 *
 * RTS Pin Status . Indicates the current status of the RTS pin. A "snapshot" of the pin is taken
 * immediately before RTSS is presented to the data bus. RTSS cannot be cleared because all writes
 * to RTSS are ignored. At reset, RTSS is set to 0.
 *
 * Values:
 * 0 - The RTS pin is high (inactive)
 * 1 - The RTS pin is low (active)
 */

#define BP_UARTV2_USR1_RTSS      14
#define BM_UARTV2_USR1_RTSS      0x00004000


/* --- Register HW_UARTV2_USR1, field PARITYERR (W1C)
 *
 * Parity Error Interrupt Flag . Indicates a parity error is detected. PARITYERR is cleared by
 * writing 1 to it. Writing 0 to PARITYERR has no effect. When parity is disabled, PARITYERR always
 * reads 0. At reset, PARITYERR is set to 0.
 *
 * Values:
 * 0 - No parity error detected
 * 1 - Parity error detected (write 1 to clear)
 */

#define BP_UARTV2_USR1_PARITYERR      15
#define BM_UARTV2_USR1_PARITYERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR1_PARITYERR(v)   ((((reg32_t) v) << 15) & BM_UARTV2_USR1_PARITYERR)
#else
#define BF_UARTV2_USR1_PARITYERR(v)   (((v) << 15) & BM_UARTV2_USR1_PARITYERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PARITYERR field to a new value.
#define BW_UARTV2_USR1_PARITYERR(v)   BF_CS1(UARTV2_USR1, PARITYERR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_USR2 - UART Status Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RDR : 1; //!< Receive Data Ready -Indicates that at least 1 character is received and written to the RxFIFO. If the URXD register is read and there is only 1 character in the RxFIFO, RDR is automatically cleared.
        unsigned ORE : 1; //!< Overrun Error . When set to 1, ORE indicates that the receive buffer (RxFIFO) was full (32 chars inside), and a 33rd character has been fully received. This 33rd character has been discarded. Clear ORE by writing 1 to it. Writing 0 to ORE has no effect.
        unsigned BRCD : 1; //!< BREAK Condition Detected . Indicates that a BREAK condition was detected by the receiver. Clear BRCD by writing 1 to it. Writing 0 to BRCD has no effect.
        unsigned TXDC : 1; //!< Transmitter Complete . Indicates that the transmit buffer (TxFIFO) and Shift Register is empty; therefore the transmission is complete. TXDC is cleared automatically when data is written to the TxFIFO.
        unsigned RTSF : 1; //!< RTS Edge Triggered Interrupt Flag. Indicates if a programmed edge is detected on the RTS pin. The RTEC bits select the edge that generates an interrupt (see ). RTSF can generate an interrupt that can be masked using the RTSEN bit. Clear RTSF by writing 1 to it. Writing 0 to RTSF has no effect.
        unsigned DCDIN : 1; //!< This bit is not used in this chip. Data Carrier Detect Input . This bit is used in DTE mode reflect the status of the Data Carrier Detect input ( DCD ). The Data Carrier Detect input is used to indicate that a carrier signal has been detected. In DCE mode this bit is always zero.
        unsigned DCDDELT : 1; //!< This bit is not used in this chip. Data Carrier Detect Delta . This bit is used in DTE mode to indicate that the Data Carrier Detect input ( DCD ) has changed state. This flag can cause an interrupt if DCD (UCR3[9]) is enabled. When in STOP mode, this bit can be used to wake the processor. In DCE mode this bit is always zero.
        unsigned WAKE : 1; //!< Wake . Indicates the start bit is detected. WAKE can generate an interrupt that can be masked using the WKEN bit. Clear WAKE by writing 1 to it. Writing 0 to WAKE has no effect.
        unsigned IRINT : 1; //!< Serial Infrared Interrupt Flag. When an edge is detected on the RXD pin during SIR Mode, this flag will be asserted. This flag can cause an interrupt which can be masked using the control bit ENIRI: UCR4 [8].
        unsigned RIIN : 1; //!< This bit is not used in this chip. Ring Indicator Input . This bit is used in DTE mode to reflect the status if the Ring Indicator input ( RI ). The Ring Indicator input is used to indicate that a ring has occurred. In DCE mode this bit is always zero.
        unsigned RIDELT : 1; //!< This bit is not used in this chip. Ring Indicator Delta . This bit is used in DTE mode to indicate that the Ring Indicator input ( RI ) has changed state. This flag can generate an interrupt if RI (UCR3[8]) is enabled. RIDELT is cleared by writing 1 to it. Writing 0 to RIDELT has no effect.
        unsigned ACST : 1; //!< Autobaud Counter Stopped . In autobaud detection (ADBR=1), indicates the counter which determines the baud rate was running and is now stopped. This means either START bit is finished (if ADNIMP=1), or Bit 0 is finished (if ADNIMP=0). See , for more details. An interrupt can be flagged on interrupt_mint interrupt_uart if ACIEN=1.
        unsigned IDLE : 1; //!< Idle Condition . Indicates that an idle condition has existed for more than a programmed amount frame (see . An interrupt can be generated by this IDLE bit if IDEN (UCR1[12]) is enabled. IDLE is cleared by writing 1 to it. Writing 0 to IDLE has no effect.
        unsigned DTRF : 1; //!< This bit is not used in this chip. DTR edge triggered interrupt flag . This bit is asserted, when the programmed edge is detected on the DTR pin (DCE mode) or on DSR (DTE mode). This flag can cause an interrupt if DTREN (UCR3[13]) is enabled.
        unsigned TXFE : 1; //!< Transmit Buffer FIFO Empty . Indicates that the transmit buffer (TxFIFO) is empty. TXFE is cleared automatically when data is written to the TxFIFO. Even though TXFE is high, the transmission might still be in progress.
        unsigned ADET : 1; //!< Automatic Baud Rate Detect Complete . Indicates that an "A" or "a" was received and that the receiver detected and verified the incoming baud rate. Clear ADET by writing 1 to it. Writing 0 to ADET has no effect.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_usr2_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_USR2 register
 */
#define HW_UARTV2_USR2_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_USR2(x)           (*(volatile hw_uartv2_usr2_t *) HW_UARTV2_USR2_ADDR(x))
#define HW_UARTV2_USR2_RD(x)        (HW_UARTV2_USR2(x).U)
#define HW_UARTV2_USR2_WR(x, v)     (HW_UARTV2_USR2(x).U = (v))
#define HW_UARTV2_USR2_SET(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) |  (v)))
#define HW_UARTV2_USR2_CLR(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) & ~(v)))
#define HW_UARTV2_USR2_TOG(x, v)    (HW_UARTV2_USR2_WR(x, HW_UARTV2_USR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_USR2 bitfields
 */

/* --- Register HW_UARTV2_USR2, field RDR (RO)
 *
 * Receive Data Ready -Indicates that at least 1 character is received and written to the RxFIFO. If
 * the URXD register is read and there is only 1 character in the RxFIFO, RDR is automatically
 * cleared.
 *
 * Values:
 * 0 - No receive data ready
 * 1 - Receive data ready
 */

#define BP_UARTV2_USR2_RDR      0
#define BM_UARTV2_USR2_RDR      0x00000001


/* --- Register HW_UARTV2_USR2, field ORE (W1C)
 *
 * Overrun Error . When set to 1, ORE indicates that the receive buffer (RxFIFO) was full (32 chars
 * inside), and a 33rd character has been fully received. This 33rd character has been discarded.
 * Clear ORE by writing 1 to it. Writing 0 to ORE has no effect.
 *
 * Values:
 * 0 - No overrun error
 * 1 - Overrun error (write 1 to clear)
 */

#define BP_UARTV2_USR2_ORE      1
#define BM_UARTV2_USR2_ORE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ORE(v)   ((((reg32_t) v) << 1) & BM_UARTV2_USR2_ORE)
#else
#define BF_UARTV2_USR2_ORE(v)   (((v) << 1) & BM_UARTV2_USR2_ORE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ORE field to a new value.
#define BW_UARTV2_USR2_ORE(v)   BF_CS1(UARTV2_USR2, ORE, v)
#endif


/* --- Register HW_UARTV2_USR2, field BRCD (W1C)
 *
 * BREAK Condition Detected . Indicates that a BREAK condition was detected by the receiver. Clear
 * BRCD by writing 1 to it. Writing 0 to BRCD has no effect.
 *
 * Values:
 * 0 - No BREAK condition was detected
 * 1 - A BREAK condition was detected (write 1 to clear)
 */

#define BP_UARTV2_USR2_BRCD      2
#define BM_UARTV2_USR2_BRCD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_BRCD(v)   ((((reg32_t) v) << 2) & BM_UARTV2_USR2_BRCD)
#else
#define BF_UARTV2_USR2_BRCD(v)   (((v) << 2) & BM_UARTV2_USR2_BRCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BRCD field to a new value.
#define BW_UARTV2_USR2_BRCD(v)   BF_CS1(UARTV2_USR2, BRCD, v)
#endif


/* --- Register HW_UARTV2_USR2, field TXDC (RO)
 *
 * Transmitter Complete . Indicates that the transmit buffer (TxFIFO) and Shift Register is empty;
 * therefore the transmission is complete. TXDC is cleared automatically when data is written to the
 * TxFIFO.
 *
 * Values:
 * 0 - Transmit is incomplete
 * 1 - Transmit is complete
 */

#define BP_UARTV2_USR2_TXDC      3
#define BM_UARTV2_USR2_TXDC      0x00000008


/* --- Register HW_UARTV2_USR2, field RTSF (W1C)
 *
 * RTS Edge Triggered Interrupt Flag. Indicates if a programmed edge is detected on the RTS pin. The
 * RTEC bits select the edge that generates an interrupt (see ). RTSF can generate an interrupt that
 * can be masked using the RTSEN bit. Clear RTSF by writing 1 to it. Writing 0 to RTSF has no
 * effect.
 *
 * Values:
 * 0 - Programmed edge not detected on RTS
 * 1 - Programmed edge detected on RTS (write 1 to clear)
 */

#define BP_UARTV2_USR2_RTSF      4
#define BM_UARTV2_USR2_RTSF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RTSF(v)   ((((reg32_t) v) << 4) & BM_UARTV2_USR2_RTSF)
#else
#define BF_UARTV2_USR2_RTSF(v)   (((v) << 4) & BM_UARTV2_USR2_RTSF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSF field to a new value.
#define BW_UARTV2_USR2_RTSF(v)   BF_CS1(UARTV2_USR2, RTSF, v)
#endif


/* --- Register HW_UARTV2_USR2, field DCDIN (RO)
 *
 * This bit is not used in this chip. Data Carrier Detect Input . This bit is used in DTE mode
 * reflect the status of the Data Carrier Detect input ( DCD ). The Data Carrier Detect input is
 * used to indicate that a carrier signal has been detected. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Carrier signal Detected
 * 1 - No Carrier signal Detected
 */

#define BP_UARTV2_USR2_DCDIN      5
#define BM_UARTV2_USR2_DCDIN      0x00000020


/* --- Register HW_UARTV2_USR2, field DCDDELT (W1C)
 *
 * This bit is not used in this chip. Data Carrier Detect Delta . This bit is used in DTE mode to
 * indicate that the Data Carrier Detect input ( DCD ) has changed state. This flag can cause an
 * interrupt if DCD (UCR3[9]) is enabled. When in STOP mode, this bit can be used to wake the
 * processor. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Data Carrier Detect input has not changed state
 * 1 - Data Carrier Detect input has changed state (write 1 to clear)
 */

#define BP_UARTV2_USR2_DCDDELT      6
#define BM_UARTV2_USR2_DCDDELT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_DCDDELT(v)   ((((reg32_t) v) << 6) & BM_UARTV2_USR2_DCDDELT)
#else
#define BF_UARTV2_USR2_DCDDELT(v)   (((v) << 6) & BM_UARTV2_USR2_DCDDELT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCDDELT field to a new value.
#define BW_UARTV2_USR2_DCDDELT(v)   BF_CS1(UARTV2_USR2, DCDDELT, v)
#endif


/* --- Register HW_UARTV2_USR2, field WAKE (W1C)
 *
 * Wake . Indicates the start bit is detected. WAKE can generate an interrupt that can be masked
 * using the WKEN bit. Clear WAKE by writing 1 to it. Writing 0 to WAKE has no effect.
 *
 * Values:
 * 0 - start bit not detected
 * 1 - start bit detected (write 1 to clear)
 */

#define BP_UARTV2_USR2_WAKE      7
#define BM_UARTV2_USR2_WAKE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_WAKE(v)   ((((reg32_t) v) << 7) & BM_UARTV2_USR2_WAKE)
#else
#define BF_UARTV2_USR2_WAKE(v)   (((v) << 7) & BM_UARTV2_USR2_WAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKE field to a new value.
#define BW_UARTV2_USR2_WAKE(v)   BF_CS1(UARTV2_USR2, WAKE, v)
#endif


/* --- Register HW_UARTV2_USR2, field IRINT (W1C)
 *
 * Serial Infrared Interrupt Flag. When an edge is detected on the RXD pin during SIR Mode, this
 * flag will be asserted. This flag can cause an interrupt which can be masked using the control bit
 * ENIRI: UCR4 [8].
 *
 * Values:
 * 0 - no edge detected
 * 1 - valid edge detected (write 1 to clear)
 */

#define BP_UARTV2_USR2_IRINT      8
#define BM_UARTV2_USR2_IRINT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_IRINT(v)   ((((reg32_t) v) << 8) & BM_UARTV2_USR2_IRINT)
#else
#define BF_UARTV2_USR2_IRINT(v)   (((v) << 8) & BM_UARTV2_USR2_IRINT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRINT field to a new value.
#define BW_UARTV2_USR2_IRINT(v)   BF_CS1(UARTV2_USR2, IRINT, v)
#endif


/* --- Register HW_UARTV2_USR2, field RIIN (RO)
 *
 * This bit is not used in this chip. Ring Indicator Input . This bit is used in DTE mode to reflect
 * the status if the Ring Indicator input ( RI ). The Ring Indicator input is used to indicate that
 * a ring has occurred. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Ring Detected
 * 1 - No Ring Detected
 */

#define BP_UARTV2_USR2_RIIN      9
#define BM_UARTV2_USR2_RIIN      0x00000200


/* --- Register HW_UARTV2_USR2, field RIDELT (W1C)
 *
 * This bit is not used in this chip. Ring Indicator Delta . This bit is used in DTE mode to
 * indicate that the Ring Indicator input ( RI ) has changed state. This flag can generate an
 * interrupt if RI (UCR3[8]) is enabled. RIDELT is cleared by writing 1 to it. Writing 0 to RIDELT
 * has no effect.
 *
 * Values:
 * 0 - Ring Indicator input has not changed state
 * 1 - Ring Indicator input has changed state (write 1 to clear)
 */

#define BP_UARTV2_USR2_RIDELT      10
#define BM_UARTV2_USR2_RIDELT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_RIDELT(v)   ((((reg32_t) v) << 10) & BM_UARTV2_USR2_RIDELT)
#else
#define BF_UARTV2_USR2_RIDELT(v)   (((v) << 10) & BM_UARTV2_USR2_RIDELT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RIDELT field to a new value.
#define BW_UARTV2_USR2_RIDELT(v)   BF_CS1(UARTV2_USR2, RIDELT, v)
#endif


/* --- Register HW_UARTV2_USR2, field ACST (W1C)
 *
 * Autobaud Counter Stopped . In autobaud detection (ADBR=1), indicates the counter which determines
 * the baud rate was running and is now stopped. This means either START bit is finished (if
 * ADNIMP=1), or Bit 0 is finished (if ADNIMP=0). See , for more details. An interrupt can be
 * flagged on interrupt_mint interrupt_uart if ACIEN=1.
 *
 * Values:
 * 0 - Measurement of bit length not finished (in autobaud)
 * 1 - Measurement of bit length finished (in autobaud). (write 1 to clear)
 */

#define BP_UARTV2_USR2_ACST      11
#define BM_UARTV2_USR2_ACST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ACST(v)   ((((reg32_t) v) << 11) & BM_UARTV2_USR2_ACST)
#else
#define BF_UARTV2_USR2_ACST(v)   (((v) << 11) & BM_UARTV2_USR2_ACST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACST field to a new value.
#define BW_UARTV2_USR2_ACST(v)   BF_CS1(UARTV2_USR2, ACST, v)
#endif


/* --- Register HW_UARTV2_USR2, field IDLE (W1C)
 *
 * Idle Condition . Indicates that an idle condition has existed for more than a programmed amount
 * frame (see . An interrupt can be generated by this IDLE bit if IDEN (UCR1[12]) is enabled. IDLE
 * is cleared by writing 1 to it. Writing 0 to IDLE has no effect.
 *
 * Values:
 * 0 - No idle condition detected
 * 1 - Idle condition detected (write 1 to clear)
 */

#define BP_UARTV2_USR2_IDLE      12
#define BM_UARTV2_USR2_IDLE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_IDLE(v)   ((((reg32_t) v) << 12) & BM_UARTV2_USR2_IDLE)
#else
#define BF_UARTV2_USR2_IDLE(v)   (((v) << 12) & BM_UARTV2_USR2_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDLE field to a new value.
#define BW_UARTV2_USR2_IDLE(v)   BF_CS1(UARTV2_USR2, IDLE, v)
#endif


/* --- Register HW_UARTV2_USR2, field DTRF (W1C)
 *
 * This bit is not used in this chip. DTR edge triggered interrupt flag . This bit is asserted, when
 * the programmed edge is detected on the DTR pin (DCE mode) or on DSR (DTE mode). This flag can
 * cause an interrupt if DTREN (UCR3[13]) is enabled.
 *
 * Values:
 * 0 - Programmed edge not detected on DTR/DSR
 * 1 - Programmed edge detected on DTR/DSR (write 1 to clear)
 */

#define BP_UARTV2_USR2_DTRF      13
#define BM_UARTV2_USR2_DTRF      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_DTRF(v)   ((((reg32_t) v) << 13) & BM_UARTV2_USR2_DTRF)
#else
#define BF_UARTV2_USR2_DTRF(v)   (((v) << 13) & BM_UARTV2_USR2_DTRF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRF field to a new value.
#define BW_UARTV2_USR2_DTRF(v)   BF_CS1(UARTV2_USR2, DTRF, v)
#endif


/* --- Register HW_UARTV2_USR2, field TXFE (RO)
 *
 * Transmit Buffer FIFO Empty . Indicates that the transmit buffer (TxFIFO) is empty. TXFE is
 * cleared automatically when data is written to the TxFIFO. Even though TXFE is high, the
 * transmission might still be in progress.
 *
 * Values:
 * 0 - The transmit buffer (TxFIFO) is not empty
 * 1 - The transmit buffer (TxFIFO) is empty
 */

#define BP_UARTV2_USR2_TXFE      14
#define BM_UARTV2_USR2_TXFE      0x00004000


/* --- Register HW_UARTV2_USR2, field ADET (W1C)
 *
 * Automatic Baud Rate Detect Complete . Indicates that an "A" or "a" was received and that the
 * receiver detected and verified the incoming baud rate. Clear ADET by writing 1 to it. Writing 0
 * to ADET has no effect.
 *
 * Values:
 * 0 - ASCII "A" or "a" was not received
 * 1 - ASCII "A" or "a" was received (write 1 to clear)
 */

#define BP_UARTV2_USR2_ADET      15
#define BM_UARTV2_USR2_ADET      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_USR2_ADET(v)   ((((reg32_t) v) << 15) & BM_UARTV2_USR2_ADET)
#else
#define BF_UARTV2_USR2_ADET(v)   (((v) << 15) & BM_UARTV2_USR2_ADET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADET field to a new value.
#define BW_UARTV2_USR2_ADET(v)   BF_CS1(UARTV2_USR2, ADET, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UESC - UART Escape Character Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ESC_CHAR : 8; //!< UART Escape Character . Holds the selected escape character that all received characters are compared against to detect an escape sequence.
        unsigned RESERVED0 : 24; //!< Reserved
    } B;
} hw_uartv2_uesc_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UESC register
 */
#define HW_UARTV2_UESC_ADDR(x)      (REGS_UARTV2_BASE(x) + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UESC(x)           (*(volatile hw_uartv2_uesc_t *) HW_UARTV2_UESC_ADDR(x))
#define HW_UARTV2_UESC_RD(x)        (HW_UARTV2_UESC(x).U)
#define HW_UARTV2_UESC_WR(x, v)     (HW_UARTV2_UESC(x).U = (v))
#define HW_UARTV2_UESC_SET(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) |  (v)))
#define HW_UARTV2_UESC_CLR(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) & ~(v)))
#define HW_UARTV2_UESC_TOG(x, v)    (HW_UARTV2_UESC_WR(x, HW_UARTV2_UESC_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UESC bitfields
 */

/* --- Register HW_UARTV2_UESC, field ESC_CHAR (RW)
 *
 * UART Escape Character . Holds the selected escape character that all received characters are
 * compared against to detect an escape sequence.
 */

#define BP_UARTV2_UESC_ESC_CHAR      0
#define BM_UARTV2_UESC_ESC_CHAR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UESC_ESC_CHAR(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UESC_ESC_CHAR)
#else
#define BF_UARTV2_UESC_ESC_CHAR(v)   (((v) << 0) & BM_UARTV2_UESC_ESC_CHAR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ESC_CHAR field to a new value.
#define BW_UARTV2_UESC_ESC_CHAR(v)   BF_CS1(UARTV2_UESC, ESC_CHAR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UTIM - UART Escape Timer Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TIM : 12; //!< UART Escape Timer. Holds the maximum time interval (in ms) allowed between escape characters. The escape timer register is programmable in intervals of 2 ms. See and for more information on the UART escape sequence detection. Reset value 0x000 = 2 ms up to 0xFFF = 8.192 s.
        unsigned RESERVED0 : 20; //!< Reserved
    } B;
} hw_uartv2_utim_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTIM register
 */
#define HW_UARTV2_UTIM_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTIM(x)           (*(volatile hw_uartv2_utim_t *) HW_UARTV2_UTIM_ADDR(x))
#define HW_UARTV2_UTIM_RD(x)        (HW_UARTV2_UTIM(x).U)
#define HW_UARTV2_UTIM_WR(x, v)     (HW_UARTV2_UTIM(x).U = (v))
#define HW_UARTV2_UTIM_SET(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) |  (v)))
#define HW_UARTV2_UTIM_CLR(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) & ~(v)))
#define HW_UARTV2_UTIM_TOG(x, v)    (HW_UARTV2_UTIM_WR(x, HW_UARTV2_UTIM_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UTIM bitfields
 */

/* --- Register HW_UARTV2_UTIM, field TIM (RW)
 *
 * UART Escape Timer. Holds the maximum time interval (in ms) allowed between escape characters. The
 * escape timer register is programmable in intervals of 2 ms. See and for more information on the
 * UART escape sequence detection. Reset value 0x000 = 2 ms up to 0xFFF = 8.192 s.
 */

#define BP_UARTV2_UTIM_TIM      0
#define BM_UARTV2_UTIM_TIM      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTIM_TIM(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTIM_TIM)
#else
#define BF_UARTV2_UTIM_TIM(v)   (((v) << 0) & BM_UARTV2_UTIM_TIM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIM field to a new value.
#define BW_UARTV2_UTIM_TIM(v)   BF_CS1(UARTV2_UTIM, TIM, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UBIR - UART BRM Incremental Register (RW)
 *
 * This register can be written by both software and hardware. When enabling the automatic baud rate
 * detection feature hardware can write 0x000F value into the UBIR after finishing detecting baud
 * rate. Hardware has higher priority when both software and hardware try to write it at the same
 * cycle Note: The write priority in the new design is not same as the original UART. In the orginal
 * design, software has higher priotiry than hardware when writing this register at the same time.
 * .  Please note software reset will reset the register to its reset value.  Writes to the UBIR and
 * UBMR registers will only take effect if the UART Enable bit (UARTEN) in the Uart Control Register
 * 1 (UCR1) is set.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INC : 16; //!< Incremental Numerator. Holds the numerator value minus one of the BRM ratio (see ). The UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly. If only one register is written to by software, the BRM will ignore this data until the other register is written to by software. Updating this field using byte accesses is not recommended and is undefined.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ubir_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBIR register
 */
#define HW_UARTV2_UBIR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBIR(x)           (*(volatile hw_uartv2_ubir_t *) HW_UARTV2_UBIR_ADDR(x))
#define HW_UARTV2_UBIR_RD(x)        (HW_UARTV2_UBIR(x).U)
#define HW_UARTV2_UBIR_WR(x, v)     (HW_UARTV2_UBIR(x).U = (v))
#define HW_UARTV2_UBIR_SET(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) |  (v)))
#define HW_UARTV2_UBIR_CLR(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) & ~(v)))
#define HW_UARTV2_UBIR_TOG(x, v)    (HW_UARTV2_UBIR_WR(x, HW_UARTV2_UBIR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UBIR bitfields
 */

/* --- Register HW_UARTV2_UBIR, field INC (RW)
 *
 * Incremental Numerator. Holds the numerator value minus one of the BRM ratio (see ). The UBIR
 * register MUST be updated before the UBMR register for the baud rate to be updated correctly. If
 * only one register is written to by software, the BRM will ignore this data until the other
 * register is written to by software. Updating this field using byte accesses is not recommended
 * and is undefined.
 */

#define BP_UARTV2_UBIR_INC      0
#define BM_UARTV2_UBIR_INC      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UBIR_INC(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UBIR_INC)
#else
#define BF_UARTV2_UBIR_INC(v)   (((v) << 0) & BM_UARTV2_UBIR_INC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INC field to a new value.
#define BW_UARTV2_UBIR_INC(v)   BF_CS1(UARTV2_UBIR, INC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UBMR - UART BRM Modulator Register (RW)
 *
 * This register can be written by both software and hardware. When enabling the automatic baud rate
 * detection feature hardware can write a proper value into the UBMR based on detected baud rate.
 * Hardware has higher priority when both software and hardware try to write it at the same cycle
 * Note: The write priority in the new design is not same as the original UART. In the orginal
 * design, software has higher priotiry than hardware when writing this register at the same time.
 * .  Please note software reset will reset the register to its reset value.  Writes to the UBIR and
 * UBMR registers will only take effect if the UART Enable bit (UARTEN) in the Uart Control Register
 * 1 (UCR1) is set.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MOD : 16; //!< Modulator Denominator. Holds the value of the denominator minus one of the BRM ratio (see ). The UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly. If only one register is written to by software, the BRM will ignore this data until the other register is written to by software. Updating this register using byte accesses is not recommended and undefined.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ubmr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBMR register
 */
#define HW_UARTV2_UBMR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBMR(x)           (*(volatile hw_uartv2_ubmr_t *) HW_UARTV2_UBMR_ADDR(x))
#define HW_UARTV2_UBMR_RD(x)        (HW_UARTV2_UBMR(x).U)
#define HW_UARTV2_UBMR_WR(x, v)     (HW_UARTV2_UBMR(x).U = (v))
#define HW_UARTV2_UBMR_SET(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) |  (v)))
#define HW_UARTV2_UBMR_CLR(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) & ~(v)))
#define HW_UARTV2_UBMR_TOG(x, v)    (HW_UARTV2_UBMR_WR(x, HW_UARTV2_UBMR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UBMR bitfields
 */

/* --- Register HW_UARTV2_UBMR, field MOD (RW)
 *
 * Modulator Denominator. Holds the value of the denominator minus one of the BRM ratio (see ). The
 * UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly.
 * If only one register is written to by software, the BRM will ignore this data until the other
 * register is written to by software. Updating this register using byte accesses is not recommended
 * and undefined.
 */

#define BP_UARTV2_UBMR_MOD      0
#define BM_UARTV2_UBMR_MOD      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UBMR_MOD(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UBMR_MOD)
#else
#define BF_UARTV2_UBMR_MOD(v)   (((v) << 0) & BM_UARTV2_UBMR_MOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD field to a new value.
#define BW_UARTV2_UBMR_MOD(v)   BF_CS1(UARTV2_UBMR, MOD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UBRC - UART Baud Rate Count Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BCNT : 16; //!< Baud Rate Count Register. This read only register is used to count the start bit of the incoming baud rate (if ADNIMP=1), or start bit + bit0 (if ADNIMP=0). When the measurement is done, the Baud Rate Count Register contains the number of UART internal clock cycles (clock after divider) present in an incoming bit. BCNT retains its value until the next Automatic Baud Rate Detection sequence has been initiated. The 16 bit Baud Rate Count register is reset to 4 and stays at hex FFFF in the case of an overflow.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_uartv2_ubrc_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UBRC register
 */
#define HW_UARTV2_UBRC_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UBRC(x)           (*(volatile hw_uartv2_ubrc_t *) HW_UARTV2_UBRC_ADDR(x))
#define HW_UARTV2_UBRC_RD(x)        (HW_UARTV2_UBRC(x).U)
#endif

/*
 * constants & macros for individual UARTV2_UBRC bitfields
 */

/* --- Register HW_UARTV2_UBRC, field BCNT (RO)
 *
 * Baud Rate Count Register. This read only register is used to count the start bit of the incoming
 * baud rate (if ADNIMP=1), or start bit + bit0 (if ADNIMP=0). When the measurement is done, the
 * Baud Rate Count Register contains the number of UART internal clock cycles (clock after divider)
 * present in an incoming bit. BCNT retains its value until the next Automatic Baud Rate Detection
 * sequence has been initiated. The 16 bit Baud Rate Count register is reset to 4 and stays at hex
 * FFFF in the case of an overflow.
 */

#define BP_UARTV2_UBRC_BCNT      0
#define BM_UARTV2_UBRC_BCNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_ONEMS - UART One Millisecond Register (RW)
 *
 * This register has been expanded from 16 bits to 24 bits. In previous versions, the 16-bit ONEMS
 * can only support the maximum 65.535MHz (0xFFFFx1000) ref_clk . To support 4Mbps Bluetooth
 * application with 66.5MHz   module_clock  (ipg_perclk)   , the value 0x103C4 (66.5M/1000) should
 * be written into this register. In this case, the 16 bits are not enough to contain the 0x103C4.
 * So this register was expanded to 24 bits to support high frequency of the ref_clk .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ONEMS : 24; //!< One Millisecond Register. This 24-bit register must contain the value of the UART internal frequency ( ref_clk in ) divided by 1000. The internal frequency is obtained after the UART BRM internal divider (F ( ref_clk ) = F( module_clock ) / RFDIV). In fact this register contains the value corresponding to the number of UART BRM internal clock cycles present in one millisecond. The ONEMS (and UTIM) registers value are used in the escape character detection feature ( ) to count the number of clock cycles left between two escape characters. The ONEMS register is also used in infrared special case mode (IRSC = UCR4[5] = 1'b1), see .
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_uartv2_onems_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_ONEMS register
 */
#define HW_UARTV2_ONEMS_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_ONEMS(x)           (*(volatile hw_uartv2_onems_t *) HW_UARTV2_ONEMS_ADDR(x))
#define HW_UARTV2_ONEMS_RD(x)        (HW_UARTV2_ONEMS(x).U)
#define HW_UARTV2_ONEMS_WR(x, v)     (HW_UARTV2_ONEMS(x).U = (v))
#define HW_UARTV2_ONEMS_SET(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) |  (v)))
#define HW_UARTV2_ONEMS_CLR(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) & ~(v)))
#define HW_UARTV2_ONEMS_TOG(x, v)    (HW_UARTV2_ONEMS_WR(x, HW_UARTV2_ONEMS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_ONEMS bitfields
 */

/* --- Register HW_UARTV2_ONEMS, field ONEMS (RW)
 *
 * One Millisecond Register. This 24-bit register must contain the value of the UART internal
 * frequency ( ref_clk in ) divided by 1000. The internal frequency is obtained after the UART BRM
 * internal divider (F ( ref_clk ) = F( module_clock ) / RFDIV). In fact this register contains the
 * value corresponding to the number of UART BRM internal clock cycles present in one millisecond.
 * The ONEMS (and UTIM) registers value are used in the escape character detection feature ( ) to
 * count the number of clock cycles left between two escape characters. The ONEMS register is also
 * used in infrared special case mode (IRSC = UCR4[5] = 1'b1), see .
 */

#define BP_UARTV2_ONEMS_ONEMS      0
#define BM_UARTV2_ONEMS_ONEMS      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_ONEMS_ONEMS(v)   ((((reg32_t) v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#else
#define BF_UARTV2_ONEMS_ONEMS(v)   (((v) << 0) & BM_UARTV2_ONEMS_ONEMS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ONEMS field to a new value.
#define BW_UARTV2_ONEMS_ONEMS(v)   BF_CS1(UARTV2_ONEMS, ONEMS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UTS - UART Test Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SOFTRST : 1; //!< Software Reset. Indicates the status of the software reset ( SRST bit of UCR2).
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned RXFULL : 1; //!< RxFIFO FULL. Indicates the RxFIFO is full.
        unsigned TXFULL : 1; //!< TxFIFO FULL. Indicates the TxFIFO is full.
        unsigned RXEMPTY : 1; //!< RxFIFO Empty. Indicates the RxFIFO is empty.
        unsigned TXEMPTY : 1; //!< TxFIFO Empty. Indicates that the TxFIFO is empty.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned RXDBG : 1; //!< This bit is not used in this chip. The user should clear this bit for future compatibility. RX_fifo_debug_mode. This bit controls the operation of the RX fifo read counter when in debug mode.
        unsigned LOOPIR : 1; //!< Loop TX and RX for IR Test (LOOPIR) . This bit controls loopback from transmitter to receiver in the InfraRed interface.
        unsigned DBGEN : 1; //!< This bit is not used in this chip. The user should clear this bit for future compatibility. debug_enable . This bit controls whether to respond to the debug_req input signal.
        unsigned LOOP : 1; //!< Loop TX and RX for Test. Controls loopback for test purposes. When LOOP is high, the receiver input is internally connected to the transmitter and ignores the RXD pin. The transmitter is unaffected by LOOP. If RXDMUXSEL (UCR3[2]) is set to 1, the loopback is applied on serial and IrDA signals. If RXDMUXSEL is set to 0, the loopback is only applied on serial signals.
        unsigned FRCPERR : 1; //!< Force Parity Error. Forces the transmitter to generate a parity error if parity is enabled. FRCPERR is provided for system debugging.
        unsigned RESERVED2 : 18; //!< Reserved
    } B;
} hw_uartv2_uts_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UTS register
 */
#define HW_UARTV2_UTS_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb4)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UTS(x)           (*(volatile hw_uartv2_uts_t *) HW_UARTV2_UTS_ADDR(x))
#define HW_UARTV2_UTS_RD(x)        (HW_UARTV2_UTS(x).U)
#define HW_UARTV2_UTS_WR(x, v)     (HW_UARTV2_UTS(x).U = (v))
#define HW_UARTV2_UTS_SET(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) |  (v)))
#define HW_UARTV2_UTS_CLR(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) & ~(v)))
#define HW_UARTV2_UTS_TOG(x, v)    (HW_UARTV2_UTS_WR(x, HW_UARTV2_UTS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UTS bitfields
 */

/* --- Register HW_UARTV2_UTS, field SOFTRST (RW)
 *
 * Software Reset. Indicates the status of the software reset ( SRST bit of UCR2).
 *
 * Values:
 * 0 - Software reset inactive
 * 1 - Software reset active
 */

#define BP_UARTV2_UTS_SOFTRST      0
#define BM_UARTV2_UTS_SOFTRST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_SOFTRST(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UTS_SOFTRST)
#else
#define BF_UARTV2_UTS_SOFTRST(v)   (((v) << 0) & BM_UARTV2_UTS_SOFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFTRST field to a new value.
#define BW_UARTV2_UTS_SOFTRST(v)   BF_CS1(UARTV2_UTS, SOFTRST, v)
#endif


/* --- Register HW_UARTV2_UTS, field RXFULL (RW)
 *
 * RxFIFO FULL. Indicates the RxFIFO is full.
 *
 * Values:
 * 0 - The RxFIFO is not full
 * 1 - The RxFIFO is full
 */

#define BP_UARTV2_UTS_RXFULL      3
#define BM_UARTV2_UTS_RXFULL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXFULL(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UTS_RXFULL)
#else
#define BF_UARTV2_UTS_RXFULL(v)   (((v) << 3) & BM_UARTV2_UTS_RXFULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFULL field to a new value.
#define BW_UARTV2_UTS_RXFULL(v)   BF_CS1(UARTV2_UTS, RXFULL, v)
#endif


/* --- Register HW_UARTV2_UTS, field TXFULL (RW)
 *
 * TxFIFO FULL. Indicates the TxFIFO is full.
 *
 * Values:
 * 0 - The TxFIFO is not full
 * 1 - The TxFIFO is full
 */

#define BP_UARTV2_UTS_TXFULL      4
#define BM_UARTV2_UTS_TXFULL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_TXFULL(v)   ((((reg32_t) v) << 4) & BM_UARTV2_UTS_TXFULL)
#else
#define BF_UARTV2_UTS_TXFULL(v)   (((v) << 4) & BM_UARTV2_UTS_TXFULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFULL field to a new value.
#define BW_UARTV2_UTS_TXFULL(v)   BF_CS1(UARTV2_UTS, TXFULL, v)
#endif


/* --- Register HW_UARTV2_UTS, field RXEMPTY (RW)
 *
 * RxFIFO Empty. Indicates the RxFIFO is empty.
 *
 * Values:
 * 0 - The RxFIFO is not empty
 * 1 - The RxFIFO is empty
 */

#define BP_UARTV2_UTS_RXEMPTY      5
#define BM_UARTV2_UTS_RXEMPTY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXEMPTY(v)   ((((reg32_t) v) << 5) & BM_UARTV2_UTS_RXEMPTY)
#else
#define BF_UARTV2_UTS_RXEMPTY(v)   (((v) << 5) & BM_UARTV2_UTS_RXEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXEMPTY field to a new value.
#define BW_UARTV2_UTS_RXEMPTY(v)   BF_CS1(UARTV2_UTS, RXEMPTY, v)
#endif


/* --- Register HW_UARTV2_UTS, field TXEMPTY (RW)
 *
 * TxFIFO Empty. Indicates that the TxFIFO is empty.
 *
 * Values:
 * 0 - The TxFIFO is not empty
 * 1 - The TxFIFO is empty
 */

#define BP_UARTV2_UTS_TXEMPTY      6
#define BM_UARTV2_UTS_TXEMPTY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_TXEMPTY(v)   ((((reg32_t) v) << 6) & BM_UARTV2_UTS_TXEMPTY)
#else
#define BF_UARTV2_UTS_TXEMPTY(v)   (((v) << 6) & BM_UARTV2_UTS_TXEMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEMPTY field to a new value.
#define BW_UARTV2_UTS_TXEMPTY(v)   BF_CS1(UARTV2_UTS, TXEMPTY, v)
#endif


/* --- Register HW_UARTV2_UTS, field RXDBG (RW)
 *
 * This bit is not used in this chip. The user should clear this bit for future compatibility.
 * RX_fifo_debug_mode. This bit controls the operation of the RX fifo read counter when in debug
 * mode.
 *
 * Values:
 * 0 - rx fifo read pointer does not increment
 * 1 - rx_fifo read pointer increments as normal
 */

#define BP_UARTV2_UTS_RXDBG      9
#define BM_UARTV2_UTS_RXDBG      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_RXDBG(v)   ((((reg32_t) v) << 9) & BM_UARTV2_UTS_RXDBG)
#else
#define BF_UARTV2_UTS_RXDBG(v)   (((v) << 9) & BM_UARTV2_UTS_RXDBG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBG field to a new value.
#define BW_UARTV2_UTS_RXDBG(v)   BF_CS1(UARTV2_UTS, RXDBG, v)
#endif


/* --- Register HW_UARTV2_UTS, field LOOPIR (RW)
 *
 * Loop TX and RX for IR Test (LOOPIR) . This bit controls loopback from transmitter to receiver in
 * the InfraRed interface.
 *
 * Values:
 * 0 - No IR loop
 * 1 - Connect IR transmitter to IR receiver
 */

#define BP_UARTV2_UTS_LOOPIR      10
#define BM_UARTV2_UTS_LOOPIR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_LOOPIR(v)   ((((reg32_t) v) << 10) & BM_UARTV2_UTS_LOOPIR)
#else
#define BF_UARTV2_UTS_LOOPIR(v)   (((v) << 10) & BM_UARTV2_UTS_LOOPIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOPIR field to a new value.
#define BW_UARTV2_UTS_LOOPIR(v)   BF_CS1(UARTV2_UTS, LOOPIR, v)
#endif


/* --- Register HW_UARTV2_UTS, field DBGEN (RW)
 *
 * This bit is not used in this chip. The user should clear this bit for future compatibility.
 * debug_enable . This bit controls whether to respond to the debug_req input signal.
 *
 * Values:
 * 0 - UART will go into debug mode when debug_req is HIGH
 * 1 - UART will not go into debug mode even if debug_req is HIGH
 */

#define BP_UARTV2_UTS_DBGEN      11
#define BM_UARTV2_UTS_DBGEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_DBGEN(v)   ((((reg32_t) v) << 11) & BM_UARTV2_UTS_DBGEN)
#else
#define BF_UARTV2_UTS_DBGEN(v)   (((v) << 11) & BM_UARTV2_UTS_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_UARTV2_UTS_DBGEN(v)   BF_CS1(UARTV2_UTS, DBGEN, v)
#endif


/* --- Register HW_UARTV2_UTS, field LOOP (RW)
 *
 * Loop TX and RX for Test. Controls loopback for test purposes. When LOOP is high, the receiver
 * input is internally connected to the transmitter and ignores the RXD pin. The transmitter is
 * unaffected by LOOP. If RXDMUXSEL (UCR3[2]) is set to 1, the loopback is applied on serial and
 * IrDA signals. If RXDMUXSEL is set to 0, the loopback is only applied on serial signals.
 *
 * Values:
 * 0 - Normal receiver operation
 * 1 - Internally connect the transmitter output to the receiver input
 */

#define BP_UARTV2_UTS_LOOP      12
#define BM_UARTV2_UTS_LOOP      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_LOOP(v)   ((((reg32_t) v) << 12) & BM_UARTV2_UTS_LOOP)
#else
#define BF_UARTV2_UTS_LOOP(v)   (((v) << 12) & BM_UARTV2_UTS_LOOP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOP field to a new value.
#define BW_UARTV2_UTS_LOOP(v)   BF_CS1(UARTV2_UTS, LOOP, v)
#endif


/* --- Register HW_UARTV2_UTS, field FRCPERR (RW)
 *
 * Force Parity Error. Forces the transmitter to generate a parity error if parity is enabled.
 * FRCPERR is provided for system debugging.
 *
 * Values:
 * 0 - Generate normal parity
 * 1 - Generate inverted parity (error)
 */

#define BP_UARTV2_UTS_FRCPERR      13
#define BM_UARTV2_UTS_FRCPERR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UTS_FRCPERR(v)   ((((reg32_t) v) << 13) & BM_UARTV2_UTS_FRCPERR)
#else
#define BF_UARTV2_UTS_FRCPERR(v)   (((v) << 13) & BM_UARTV2_UTS_FRCPERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRCPERR field to a new value.
#define BW_UARTV2_UTS_FRCPERR(v)   BF_CS1(UARTV2_UTS, FRCPERR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UARTV2_UMCR - UART RS-485 Mode Control Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MDEN : 1; //!< 9-bit data or Multidrop Mode (RS-485) Enable.
        unsigned SLAM : 1; //!< RS-485 Slave Address Detect Mode Selection.
        unsigned TXB8 : 1; //!< Transmit RS-485 bit 8 (the ninth bit or 9 th bit). In RS-485 mode, software writes TXB8 bit as the 9 th data bit to be transmitted.
        unsigned SADEN : 1; //!< RS-485 Slave Address Detected Interrupt Enable.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned SLADDR : 8; //!< RS-485 Slave Address Character. Holds the selected slave adress character that the receiver wil try to detect.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_uartv2_umcr_t;
#endif

/*
 * constants & macros for entire multi-block UARTV2_UMCR register
 */
#define HW_UARTV2_UMCR_ADDR(x)      (REGS_UARTV2_BASE(x) + 0xb8)

#ifndef __LANGUAGE_ASM__
#define HW_UARTV2_UMCR(x)           (*(volatile hw_uartv2_umcr_t *) HW_UARTV2_UMCR_ADDR(x))
#define HW_UARTV2_UMCR_RD(x)        (HW_UARTV2_UMCR(x).U)
#define HW_UARTV2_UMCR_WR(x, v)     (HW_UARTV2_UMCR(x).U = (v))
#define HW_UARTV2_UMCR_SET(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) |  (v)))
#define HW_UARTV2_UMCR_CLR(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) & ~(v)))
#define HW_UARTV2_UMCR_TOG(x, v)    (HW_UARTV2_UMCR_WR(x, HW_UARTV2_UMCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UARTV2_UMCR bitfields
 */

/* --- Register HW_UARTV2_UMCR, field MDEN (RW)
 *
 * 9-bit data or Multidrop Mode (RS-485) Enable.
 *
 * Values:
 * 0 - Normal RS-232 or IrDA mode, see for detail.
 * 1 - Enable RS-485 mode, see for detail
 */

#define BP_UARTV2_UMCR_MDEN      0
#define BM_UARTV2_UMCR_MDEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_MDEN(v)   ((((reg32_t) v) << 0) & BM_UARTV2_UMCR_MDEN)
#else
#define BF_UARTV2_UMCR_MDEN(v)   (((v) << 0) & BM_UARTV2_UMCR_MDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MDEN field to a new value.
#define BW_UARTV2_UMCR_MDEN(v)   BF_CS1(UARTV2_UMCR, MDEN, v)
#endif


/* --- Register HW_UARTV2_UMCR, field SLAM (RW)
 *
 * RS-485 Slave Address Detect Mode Selection.
 *
 * Values:
 * 0 - Select Normal Address Detect mode
 * 1 - Select Automatic Address Detect mode
 */

#define BP_UARTV2_UMCR_SLAM      1
#define BM_UARTV2_UMCR_SLAM      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SLAM(v)   ((((reg32_t) v) << 1) & BM_UARTV2_UMCR_SLAM)
#else
#define BF_UARTV2_UMCR_SLAM(v)   (((v) << 1) & BM_UARTV2_UMCR_SLAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLAM field to a new value.
#define BW_UARTV2_UMCR_SLAM(v)   BF_CS1(UARTV2_UMCR, SLAM, v)
#endif


/* --- Register HW_UARTV2_UMCR, field TXB8 (RW)
 *
 * Transmit RS-485 bit 8 (the ninth bit or 9 th bit). In RS-485 mode, software writes TXB8 bit as
 * the 9 th data bit to be transmitted.
 *
 * Values:
 * 0 - 0 will be transmitted as the RS485 9 th data bit
 * 1 - 1 will be transmitted as the RS485 9 th data bit
 */

#define BP_UARTV2_UMCR_TXB8      2
#define BM_UARTV2_UMCR_TXB8      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_TXB8(v)   ((((reg32_t) v) << 2) & BM_UARTV2_UMCR_TXB8)
#else
#define BF_UARTV2_UMCR_TXB8(v)   (((v) << 2) & BM_UARTV2_UMCR_TXB8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB8 field to a new value.
#define BW_UARTV2_UMCR_TXB8(v)   BF_CS1(UARTV2_UMCR, TXB8, v)
#endif


/* --- Register HW_UARTV2_UMCR, field SADEN (RW)
 *
 * RS-485 Slave Address Detected Interrupt Enable.
 *
 * Values:
 * 0 - Disable RS-485 Slave Address Detected Interrupt
 * 1 - Enable RS-485 Slave Address Detected Interrupt
 */

#define BP_UARTV2_UMCR_SADEN      3
#define BM_UARTV2_UMCR_SADEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SADEN(v)   ((((reg32_t) v) << 3) & BM_UARTV2_UMCR_SADEN)
#else
#define BF_UARTV2_UMCR_SADEN(v)   (((v) << 3) & BM_UARTV2_UMCR_SADEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SADEN field to a new value.
#define BW_UARTV2_UMCR_SADEN(v)   BF_CS1(UARTV2_UMCR, SADEN, v)
#endif


/* --- Register HW_UARTV2_UMCR, field SLADDR (RW)
 *
 * RS-485 Slave Address Character. Holds the selected slave adress character that the receiver wil
 * try to detect.
 */

#define BP_UARTV2_UMCR_SLADDR      8
#define BM_UARTV2_UMCR_SLADDR      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_UARTV2_UMCR_SLADDR(v)   ((((reg32_t) v) << 8) & BM_UARTV2_UMCR_SLADDR)
#else
#define BF_UARTV2_UMCR_SLADDR(v)   (((v) << 8) & BM_UARTV2_UMCR_SLADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLADDR field to a new value.
#define BW_UARTV2_UMCR_SLADDR(v)   BF_CS1(UARTV2_UMCR, SLADDR, v)
#endif


/*!
 * @brief All UARTV2 module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_uartv2_urxd_t URXD; //!< UART Receiver Register
    reg32_t _reserved0[15];
    volatile hw_uartv2_utxd_t UTXD; //!< UART Transmitter Register
    reg32_t _reserved1[15];
    volatile hw_uartv2_ucr1_t UCR1; //!< UART Control Register 1
    volatile hw_uartv2_ucr2_t UCR2; //!< UART Control Register 2
    volatile hw_uartv2_ucr3_t UCR3; //!< UART Control Register 3
    volatile hw_uartv2_ucr4_t UCR4; //!< UART Control Register 4
    volatile hw_uartv2_ufcr_t UFCR; //!< UART FIFO Control Register
    volatile hw_uartv2_usr1_t USR1; //!< UART Status Register 1
    volatile hw_uartv2_usr2_t USR2; //!< UART Status Register 2
    volatile hw_uartv2_uesc_t UESC; //!< UART Escape Character Register
    volatile hw_uartv2_utim_t UTIM; //!< UART Escape Timer Register
    volatile hw_uartv2_ubir_t UBIR; //!< UART BRM Incremental Register
    volatile hw_uartv2_ubmr_t UBMR; //!< UART BRM Modulator Register
    volatile hw_uartv2_ubrc_t UBRC; //!< UART Baud Rate Count Register
    volatile hw_uartv2_onems_t ONEMS; //!< UART One Millisecond Register
    volatile hw_uartv2_uts_t UTS; //!< UART Test Register
    volatile hw_uartv2_umcr_t UMCR; //!< UART RS-485 Mode Control Register
} hw_uartv2_t;
#endif

//! @brief Macro to access all UARTV2 registers.
//! @param x UARTV2 instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_UARTV2(0)</code>.
#define HW_UARTV2(x)     (*(volatile hw_uartv2_t *) REGS_UARTV2_BASE(x))


#endif // _UARTV2_H
