/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _AUDMUX_H
#define _AUDMUX_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_AUDMUX_PTCR1 - Port Timing Control Register 1
 * - HW_AUDMUX_PDCR1 - Port Data Control Register 1
 * - HW_AUDMUX_PTCR2 - Port Timing Control Register 2
 * - HW_AUDMUX_PDCR2 - Port Data Control Register 2
 * - HW_AUDMUX_PTCR3 - Port Timing Control Register 3
 * - HW_AUDMUX_PDCR3 - Port Data Control Register 3
 * - HW_AUDMUX_PTCR4 - Port Timing Control Register n 4
 * - HW_AUDMUX_PDCR4 - Port Data Control Register 4
 * - HW_AUDMUX_PTCR5 - Port Timing Control Register n 5
 * - HW_AUDMUX_PDCR5 - Port Data Control Register 5
 * - HW_AUDMUX_PTCR6 - Port Timing Control Register n 6
 * - HW_AUDMUX_PDCR6 - Port Data Control Register 6
 * - HW_AUDMUX_PTCR7 - Port Timing Control Register n 7
 * - HW_AUDMUX_PDCR7 - Port Data Control Register 7
 *
 * hw_audmux_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_AUDMUX_BASE
#define REGS_AUDMUX_BASE (0x021d8000) //!< Base address for AUDMUX.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR1 - Port Timing Control Register 1 (RW)
 *
 * PTCR1 is the Port Timing Control Register for Port 1.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr1_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR1 register
 */
#define HW_AUDMUX_PTCR1_ADDR      (REGS_AUDMUX_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR1           (*(volatile hw_audmux_ptcr1_t *) HW_AUDMUX_PTCR1_ADDR)
#define HW_AUDMUX_PTCR1_RD()      (HW_AUDMUX_PTCR1.U)
#define HW_AUDMUX_PTCR1_WR(v)     (HW_AUDMUX_PTCR1.U = (v))
#define HW_AUDMUX_PTCR1_SET(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() |  (v)))
#define HW_AUDMUX_PTCR1_CLR(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() & ~(v)))
#define HW_AUDMUX_PTCR1_TOG(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR1 bitfields
 */

/* --- Register HW_AUDMUX_PTCR1, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR1_SYN      (11)
#define BM_AUDMUX_PTCR1_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR1_SYN)
#else
#define BF_AUDMUX_PTCR1_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR1_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR1_SYN(v)   BF_CS1(AUDMUX_PTCR1, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR1_RCSEL      (12)
#define BM_AUDMUX_PTCR1_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#else
#define BF_AUDMUX_PTCR1_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR1_RCSEL(v)   BF_CS1(AUDMUX_PTCR1, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR1_RCLKDIR      (16)
#define BM_AUDMUX_PTCR1_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#else
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR1_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR1_RFSEL      (17)
#define BM_AUDMUX_PTCR1_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#else
#define BF_AUDMUX_PTCR1_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR1_RFSEL(v)   BF_CS1(AUDMUX_PTCR1, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR1_RFS_DIR      (21)
#define BM_AUDMUX_PTCR1_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR1_RFS_DIR)
#else
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR1_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR1_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR1, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR1_TCSEL      (22)
#define BM_AUDMUX_PTCR1_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#else
#define BF_AUDMUX_PTCR1_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR1_TCSEL(v)   BF_CS1(AUDMUX_PTCR1, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR1_TCLKDIR      (26)
#define BM_AUDMUX_PTCR1_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#else
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR1_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR1_TFSEL      (27)
#define BM_AUDMUX_PTCR1_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#else
#define BF_AUDMUX_PTCR1_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR1_TFSEL(v)   BF_CS1(AUDMUX_PTCR1, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR1, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR1_TFS_DIR      (31)
#define BM_AUDMUX_PTCR1_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR1_TFS_DIR)
#else
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR1_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR1_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR1, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR1 - Port Data Control Register 1 (RW)
 *
 * PDCR1 is the Port Data Control Register for Port 1.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr1_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR1 register
 */
#define HW_AUDMUX_PDCR1_ADDR      (REGS_AUDMUX_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR1           (*(volatile hw_audmux_pdcr1_t *) HW_AUDMUX_PDCR1_ADDR)
#define HW_AUDMUX_PDCR1_RD()      (HW_AUDMUX_PDCR1.U)
#define HW_AUDMUX_PDCR1_WR(v)     (HW_AUDMUX_PDCR1.U = (v))
#define HW_AUDMUX_PDCR1_SET(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() |  (v)))
#define HW_AUDMUX_PDCR1_CLR(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() & ~(v)))
#define HW_AUDMUX_PDCR1_TOG(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR1 bitfields
 */

/* --- Register HW_AUDMUX_PDCR1, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR1_INMMASK      (0)
#define BM_AUDMUX_PDCR1_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR1_INMMASK)
#else
#define BF_AUDMUX_PDCR1_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR1_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR1_INMMASK(v)   BF_CS1(AUDMUX_PDCR1, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR1, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR1_MODE      (8)
#define BM_AUDMUX_PDCR1_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR1_MODE)
#else
#define BF_AUDMUX_PDCR1_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR1_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR1_MODE(v)   BF_CS1(AUDMUX_PDCR1, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR1, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR1_TXRXEN      (12)
#define BM_AUDMUX_PDCR1_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR1_TXRXEN)
#else
#define BF_AUDMUX_PDCR1_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR1_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR1_TXRXEN(v)   BF_CS1(AUDMUX_PDCR1, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR1, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR1_RXDSEL      (13)
#define BM_AUDMUX_PDCR1_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR1_RXDSEL)
#else
#define BF_AUDMUX_PDCR1_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR1_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR1_RXDSEL(v)   BF_CS1(AUDMUX_PDCR1, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR2 - Port Timing Control Register 2 (RW)
 *
 * PTCR2 is the Port Timing Control Register for Port 2.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr2_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR2 register
 */
#define HW_AUDMUX_PTCR2_ADDR      (REGS_AUDMUX_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR2           (*(volatile hw_audmux_ptcr2_t *) HW_AUDMUX_PTCR2_ADDR)
#define HW_AUDMUX_PTCR2_RD()      (HW_AUDMUX_PTCR2.U)
#define HW_AUDMUX_PTCR2_WR(v)     (HW_AUDMUX_PTCR2.U = (v))
#define HW_AUDMUX_PTCR2_SET(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() |  (v)))
#define HW_AUDMUX_PTCR2_CLR(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() & ~(v)))
#define HW_AUDMUX_PTCR2_TOG(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR2 bitfields
 */

/* --- Register HW_AUDMUX_PTCR2, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR2_SYN      (11)
#define BM_AUDMUX_PTCR2_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR2_SYN)
#else
#define BF_AUDMUX_PTCR2_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR2_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR2_SYN(v)   BF_CS1(AUDMUX_PTCR2, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR2_RCSEL      (12)
#define BM_AUDMUX_PTCR2_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#else
#define BF_AUDMUX_PTCR2_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR2_RCSEL(v)   BF_CS1(AUDMUX_PTCR2, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR2_RCLKDIR      (16)
#define BM_AUDMUX_PTCR2_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#else
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR2_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR2_RFSEL      (17)
#define BM_AUDMUX_PTCR2_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#else
#define BF_AUDMUX_PTCR2_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR2_RFSEL(v)   BF_CS1(AUDMUX_PTCR2, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR2_RFS_DIR      (21)
#define BM_AUDMUX_PTCR2_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR2_RFS_DIR)
#else
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR2_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR2_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR2, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR2_TCSEL      (22)
#define BM_AUDMUX_PTCR2_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#else
#define BF_AUDMUX_PTCR2_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR2_TCSEL(v)   BF_CS1(AUDMUX_PTCR2, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR2_TCLKDIR      (26)
#define BM_AUDMUX_PTCR2_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#else
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR2_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR2_TFSEL      (27)
#define BM_AUDMUX_PTCR2_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#else
#define BF_AUDMUX_PTCR2_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR2_TFSEL(v)   BF_CS1(AUDMUX_PTCR2, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR2, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR2_TFS_DIR      (31)
#define BM_AUDMUX_PTCR2_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR2_TFS_DIR)
#else
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR2_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR2_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR2, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR2 - Port Data Control Register 2 (RW)
 *
 * PDCR2 is the Port Data Control Register for Port 2.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr2_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR2 register
 */
#define HW_AUDMUX_PDCR2_ADDR      (REGS_AUDMUX_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR2           (*(volatile hw_audmux_pdcr2_t *) HW_AUDMUX_PDCR2_ADDR)
#define HW_AUDMUX_PDCR2_RD()      (HW_AUDMUX_PDCR2.U)
#define HW_AUDMUX_PDCR2_WR(v)     (HW_AUDMUX_PDCR2.U = (v))
#define HW_AUDMUX_PDCR2_SET(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() |  (v)))
#define HW_AUDMUX_PDCR2_CLR(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() & ~(v)))
#define HW_AUDMUX_PDCR2_TOG(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR2 bitfields
 */

/* --- Register HW_AUDMUX_PDCR2, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR2_INMMASK      (0)
#define BM_AUDMUX_PDCR2_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR2_INMMASK)
#else
#define BF_AUDMUX_PDCR2_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR2_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR2_INMMASK(v)   BF_CS1(AUDMUX_PDCR2, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR2, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR2_MODE      (8)
#define BM_AUDMUX_PDCR2_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR2_MODE)
#else
#define BF_AUDMUX_PDCR2_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR2_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR2_MODE(v)   BF_CS1(AUDMUX_PDCR2, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR2, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR2_TXRXEN      (12)
#define BM_AUDMUX_PDCR2_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR2_TXRXEN)
#else
#define BF_AUDMUX_PDCR2_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR2_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR2_TXRXEN(v)   BF_CS1(AUDMUX_PDCR2, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR2, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR2_RXDSEL      (13)
#define BM_AUDMUX_PDCR2_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR2_RXDSEL)
#else
#define BF_AUDMUX_PDCR2_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR2_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR2_RXDSEL(v)   BF_CS1(AUDMUX_PDCR2, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR3 - Port Timing Control Register 3 (RW)
 *
 * PTCR3 is the Port Timing Control Register for Port 3.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr3_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR3 register
 */
#define HW_AUDMUX_PTCR3_ADDR      (REGS_AUDMUX_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR3           (*(volatile hw_audmux_ptcr3_t *) HW_AUDMUX_PTCR3_ADDR)
#define HW_AUDMUX_PTCR3_RD()      (HW_AUDMUX_PTCR3.U)
#define HW_AUDMUX_PTCR3_WR(v)     (HW_AUDMUX_PTCR3.U = (v))
#define HW_AUDMUX_PTCR3_SET(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() |  (v)))
#define HW_AUDMUX_PTCR3_CLR(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() & ~(v)))
#define HW_AUDMUX_PTCR3_TOG(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR3 bitfields
 */

/* --- Register HW_AUDMUX_PTCR3, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR3_SYN      (11)
#define BM_AUDMUX_PTCR3_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR3_SYN)
#else
#define BF_AUDMUX_PTCR3_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR3_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR3_SYN(v)   BF_CS1(AUDMUX_PTCR3, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR3_RCSEL      (12)
#define BM_AUDMUX_PTCR3_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#else
#define BF_AUDMUX_PTCR3_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR3_RCSEL(v)   BF_CS1(AUDMUX_PTCR3, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR3_RCLKDIR      (16)
#define BM_AUDMUX_PTCR3_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#else
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR3_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR3_RFSEL      (17)
#define BM_AUDMUX_PTCR3_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#else
#define BF_AUDMUX_PTCR3_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR3_RFSEL(v)   BF_CS1(AUDMUX_PTCR3, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR3_RFS_DIR      (21)
#define BM_AUDMUX_PTCR3_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR3_RFS_DIR)
#else
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR3_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR3_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR3, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR3_TCSEL      (22)
#define BM_AUDMUX_PTCR3_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#else
#define BF_AUDMUX_PTCR3_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR3_TCSEL(v)   BF_CS1(AUDMUX_PTCR3, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR3_TCLKDIR      (26)
#define BM_AUDMUX_PTCR3_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#else
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR3_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR3_TFSEL      (27)
#define BM_AUDMUX_PTCR3_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#else
#define BF_AUDMUX_PTCR3_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR3_TFSEL(v)   BF_CS1(AUDMUX_PTCR3, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR3, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR3_TFS_DIR      (31)
#define BM_AUDMUX_PTCR3_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR3_TFS_DIR)
#else
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR3_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR3_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR3, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR3 - Port Data Control Register 3 (RW)
 *
 * PDCR3 is the Port Data Control Register for Port 3.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr3_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR3 register
 */
#define HW_AUDMUX_PDCR3_ADDR      (REGS_AUDMUX_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR3           (*(volatile hw_audmux_pdcr3_t *) HW_AUDMUX_PDCR3_ADDR)
#define HW_AUDMUX_PDCR3_RD()      (HW_AUDMUX_PDCR3.U)
#define HW_AUDMUX_PDCR3_WR(v)     (HW_AUDMUX_PDCR3.U = (v))
#define HW_AUDMUX_PDCR3_SET(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() |  (v)))
#define HW_AUDMUX_PDCR3_CLR(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() & ~(v)))
#define HW_AUDMUX_PDCR3_TOG(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR3 bitfields
 */

/* --- Register HW_AUDMUX_PDCR3, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR3_INMMASK      (0)
#define BM_AUDMUX_PDCR3_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR3_INMMASK)
#else
#define BF_AUDMUX_PDCR3_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR3_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR3_INMMASK(v)   BF_CS1(AUDMUX_PDCR3, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR3, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR3_MODE      (8)
#define BM_AUDMUX_PDCR3_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR3_MODE)
#else
#define BF_AUDMUX_PDCR3_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR3_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR3_MODE(v)   BF_CS1(AUDMUX_PDCR3, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR3, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR3_TXRXEN      (12)
#define BM_AUDMUX_PDCR3_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR3_TXRXEN)
#else
#define BF_AUDMUX_PDCR3_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR3_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR3_TXRXEN(v)   BF_CS1(AUDMUX_PDCR3, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR3, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR3_RXDSEL      (13)
#define BM_AUDMUX_PDCR3_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR3_RXDSEL)
#else
#define BF_AUDMUX_PDCR3_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR3_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR3_RXDSEL(v)   BF_CS1(AUDMUX_PDCR3, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR4 - Port Timing Control Register n 4 (RW)
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr4_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR4 register
 */
#define HW_AUDMUX_PTCR4_ADDR      (REGS_AUDMUX_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR4           (*(volatile hw_audmux_ptcr4_t *) HW_AUDMUX_PTCR4_ADDR)
#define HW_AUDMUX_PTCR4_RD()      (HW_AUDMUX_PTCR4.U)
#define HW_AUDMUX_PTCR4_WR(v)     (HW_AUDMUX_PTCR4.U = (v))
#define HW_AUDMUX_PTCR4_SET(v)    (HW_AUDMUX_PTCR4_WR(HW_AUDMUX_PTCR4_RD() |  (v)))
#define HW_AUDMUX_PTCR4_CLR(v)    (HW_AUDMUX_PTCR4_WR(HW_AUDMUX_PTCR4_RD() & ~(v)))
#define HW_AUDMUX_PTCR4_TOG(v)    (HW_AUDMUX_PTCR4_WR(HW_AUDMUX_PTCR4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR4 bitfields
 */

/* --- Register HW_AUDMUX_PTCR4, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR4_SYN      (11)
#define BM_AUDMUX_PTCR4_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR4_SYN)
#else
#define BF_AUDMUX_PTCR4_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR4_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR4_SYN(v)   BF_CS1(AUDMUX_PTCR4, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR4_RCSEL      (12)
#define BM_AUDMUX_PTCR4_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR4_RCSEL)
#else
#define BF_AUDMUX_PTCR4_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR4_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR4_RCSEL(v)   BF_CS1(AUDMUX_PTCR4, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR4_RCLKDIR      (16)
#define BM_AUDMUX_PTCR4_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR4_RCLKDIR)
#else
#define BF_AUDMUX_PTCR4_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR4_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR4_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR4, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR4_RFSEL      (17)
#define BM_AUDMUX_PTCR4_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR4_RFSEL)
#else
#define BF_AUDMUX_PTCR4_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR4_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR4_RFSEL(v)   BF_CS1(AUDMUX_PTCR4, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR4_RFS_DIR      (21)
#define BM_AUDMUX_PTCR4_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR4_RFS_DIR)
#else
#define BF_AUDMUX_PTCR4_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR4_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR4_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR4, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR4_TCSEL      (22)
#define BM_AUDMUX_PTCR4_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR4_TCSEL)
#else
#define BF_AUDMUX_PTCR4_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR4_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR4_TCSEL(v)   BF_CS1(AUDMUX_PTCR4, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR4_TCLKDIR      (26)
#define BM_AUDMUX_PTCR4_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR4_TCLKDIR)
#else
#define BF_AUDMUX_PTCR4_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR4_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR4_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR4, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR4_TFSEL      (27)
#define BM_AUDMUX_PTCR4_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR4_TFSEL)
#else
#define BF_AUDMUX_PTCR4_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR4_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR4_TFSEL(v)   BF_CS1(AUDMUX_PTCR4, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR4, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR4_TFS_DIR      (31)
#define BM_AUDMUX_PTCR4_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR4_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR4_TFS_DIR)
#else
#define BF_AUDMUX_PTCR4_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR4_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR4_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR4, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR4 - Port Data Control Register 4 (RW)
 *
 * PDCR4 is the Port Data Control Register for Port 4.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr4_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR4 register
 */
#define HW_AUDMUX_PDCR4_ADDR      (REGS_AUDMUX_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR4           (*(volatile hw_audmux_pdcr4_t *) HW_AUDMUX_PDCR4_ADDR)
#define HW_AUDMUX_PDCR4_RD()      (HW_AUDMUX_PDCR4.U)
#define HW_AUDMUX_PDCR4_WR(v)     (HW_AUDMUX_PDCR4.U = (v))
#define HW_AUDMUX_PDCR4_SET(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() |  (v)))
#define HW_AUDMUX_PDCR4_CLR(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() & ~(v)))
#define HW_AUDMUX_PDCR4_TOG(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR4 bitfields
 */

/* --- Register HW_AUDMUX_PDCR4, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR4_INMMASK      (0)
#define BM_AUDMUX_PDCR4_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR4_INMMASK)
#else
#define BF_AUDMUX_PDCR4_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR4_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR4_INMMASK(v)   BF_CS1(AUDMUX_PDCR4, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR4, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR4_MODE      (8)
#define BM_AUDMUX_PDCR4_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR4_MODE)
#else
#define BF_AUDMUX_PDCR4_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR4_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR4_MODE(v)   BF_CS1(AUDMUX_PDCR4, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR4, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR4_TXRXEN      (12)
#define BM_AUDMUX_PDCR4_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR4_TXRXEN)
#else
#define BF_AUDMUX_PDCR4_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR4_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR4_TXRXEN(v)   BF_CS1(AUDMUX_PDCR4, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR4, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR4_RXDSEL      (13)
#define BM_AUDMUX_PDCR4_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR4_RXDSEL)
#else
#define BF_AUDMUX_PDCR4_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR4_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR4_RXDSEL(v)   BF_CS1(AUDMUX_PDCR4, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR5 - Port Timing Control Register n 5 (RW)
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr5_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR5 register
 */
#define HW_AUDMUX_PTCR5_ADDR      (REGS_AUDMUX_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR5           (*(volatile hw_audmux_ptcr5_t *) HW_AUDMUX_PTCR5_ADDR)
#define HW_AUDMUX_PTCR5_RD()      (HW_AUDMUX_PTCR5.U)
#define HW_AUDMUX_PTCR5_WR(v)     (HW_AUDMUX_PTCR5.U = (v))
#define HW_AUDMUX_PTCR5_SET(v)    (HW_AUDMUX_PTCR5_WR(HW_AUDMUX_PTCR5_RD() |  (v)))
#define HW_AUDMUX_PTCR5_CLR(v)    (HW_AUDMUX_PTCR5_WR(HW_AUDMUX_PTCR5_RD() & ~(v)))
#define HW_AUDMUX_PTCR5_TOG(v)    (HW_AUDMUX_PTCR5_WR(HW_AUDMUX_PTCR5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR5 bitfields
 */

/* --- Register HW_AUDMUX_PTCR5, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR5_SYN      (11)
#define BM_AUDMUX_PTCR5_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR5_SYN)
#else
#define BF_AUDMUX_PTCR5_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR5_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR5_SYN(v)   BF_CS1(AUDMUX_PTCR5, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR5_RCSEL      (12)
#define BM_AUDMUX_PTCR5_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR5_RCSEL)
#else
#define BF_AUDMUX_PTCR5_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR5_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR5_RCSEL(v)   BF_CS1(AUDMUX_PTCR5, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR5_RCLKDIR      (16)
#define BM_AUDMUX_PTCR5_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR5_RCLKDIR)
#else
#define BF_AUDMUX_PTCR5_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR5_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR5_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR5, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR5_RFSEL      (17)
#define BM_AUDMUX_PTCR5_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR5_RFSEL)
#else
#define BF_AUDMUX_PTCR5_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR5_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR5_RFSEL(v)   BF_CS1(AUDMUX_PTCR5, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR5_RFS_DIR      (21)
#define BM_AUDMUX_PTCR5_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR5_RFS_DIR)
#else
#define BF_AUDMUX_PTCR5_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR5_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR5_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR5, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR5_TCSEL      (22)
#define BM_AUDMUX_PTCR5_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR5_TCSEL)
#else
#define BF_AUDMUX_PTCR5_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR5_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR5_TCSEL(v)   BF_CS1(AUDMUX_PTCR5, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR5_TCLKDIR      (26)
#define BM_AUDMUX_PTCR5_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR5_TCLKDIR)
#else
#define BF_AUDMUX_PTCR5_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR5_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR5_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR5, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR5_TFSEL      (27)
#define BM_AUDMUX_PTCR5_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR5_TFSEL)
#else
#define BF_AUDMUX_PTCR5_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR5_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR5_TFSEL(v)   BF_CS1(AUDMUX_PTCR5, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR5, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR5_TFS_DIR      (31)
#define BM_AUDMUX_PTCR5_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR5_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR5_TFS_DIR)
#else
#define BF_AUDMUX_PTCR5_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR5_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR5_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR5, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR5 - Port Data Control Register 5 (RW)
 *
 * PDCR5 is the Port Data Control Register for Port 5.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr5_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR5 register
 */
#define HW_AUDMUX_PDCR5_ADDR      (REGS_AUDMUX_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR5           (*(volatile hw_audmux_pdcr5_t *) HW_AUDMUX_PDCR5_ADDR)
#define HW_AUDMUX_PDCR5_RD()      (HW_AUDMUX_PDCR5.U)
#define HW_AUDMUX_PDCR5_WR(v)     (HW_AUDMUX_PDCR5.U = (v))
#define HW_AUDMUX_PDCR5_SET(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() |  (v)))
#define HW_AUDMUX_PDCR5_CLR(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() & ~(v)))
#define HW_AUDMUX_PDCR5_TOG(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR5 bitfields
 */

/* --- Register HW_AUDMUX_PDCR5, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR5_INMMASK      (0)
#define BM_AUDMUX_PDCR5_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR5_INMMASK)
#else
#define BF_AUDMUX_PDCR5_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR5_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR5_INMMASK(v)   BF_CS1(AUDMUX_PDCR5, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR5, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR5_MODE      (8)
#define BM_AUDMUX_PDCR5_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR5_MODE)
#else
#define BF_AUDMUX_PDCR5_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR5_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR5_MODE(v)   BF_CS1(AUDMUX_PDCR5, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR5, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR5_TXRXEN      (12)
#define BM_AUDMUX_PDCR5_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR5_TXRXEN)
#else
#define BF_AUDMUX_PDCR5_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR5_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR5_TXRXEN(v)   BF_CS1(AUDMUX_PDCR5, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR5, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR5_RXDSEL      (13)
#define BM_AUDMUX_PDCR5_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR5_RXDSEL)
#else
#define BF_AUDMUX_PDCR5_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR5_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR5_RXDSEL(v)   BF_CS1(AUDMUX_PDCR5, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR6 - Port Timing Control Register n 6 (RW)
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr6_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR6 register
 */
#define HW_AUDMUX_PTCR6_ADDR      (REGS_AUDMUX_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR6           (*(volatile hw_audmux_ptcr6_t *) HW_AUDMUX_PTCR6_ADDR)
#define HW_AUDMUX_PTCR6_RD()      (HW_AUDMUX_PTCR6.U)
#define HW_AUDMUX_PTCR6_WR(v)     (HW_AUDMUX_PTCR6.U = (v))
#define HW_AUDMUX_PTCR6_SET(v)    (HW_AUDMUX_PTCR6_WR(HW_AUDMUX_PTCR6_RD() |  (v)))
#define HW_AUDMUX_PTCR6_CLR(v)    (HW_AUDMUX_PTCR6_WR(HW_AUDMUX_PTCR6_RD() & ~(v)))
#define HW_AUDMUX_PTCR6_TOG(v)    (HW_AUDMUX_PTCR6_WR(HW_AUDMUX_PTCR6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR6 bitfields
 */

/* --- Register HW_AUDMUX_PTCR6, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR6_SYN      (11)
#define BM_AUDMUX_PTCR6_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR6_SYN)
#else
#define BF_AUDMUX_PTCR6_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR6_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR6_SYN(v)   BF_CS1(AUDMUX_PTCR6, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR6_RCSEL      (12)
#define BM_AUDMUX_PTCR6_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR6_RCSEL)
#else
#define BF_AUDMUX_PTCR6_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR6_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR6_RCSEL(v)   BF_CS1(AUDMUX_PTCR6, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR6_RCLKDIR      (16)
#define BM_AUDMUX_PTCR6_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR6_RCLKDIR)
#else
#define BF_AUDMUX_PTCR6_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR6_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR6_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR6, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR6_RFSEL      (17)
#define BM_AUDMUX_PTCR6_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR6_RFSEL)
#else
#define BF_AUDMUX_PTCR6_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR6_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR6_RFSEL(v)   BF_CS1(AUDMUX_PTCR6, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR6_RFS_DIR      (21)
#define BM_AUDMUX_PTCR6_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR6_RFS_DIR)
#else
#define BF_AUDMUX_PTCR6_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR6_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR6_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR6, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR6_TCSEL      (22)
#define BM_AUDMUX_PTCR6_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR6_TCSEL)
#else
#define BF_AUDMUX_PTCR6_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR6_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR6_TCSEL(v)   BF_CS1(AUDMUX_PTCR6, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR6_TCLKDIR      (26)
#define BM_AUDMUX_PTCR6_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR6_TCLKDIR)
#else
#define BF_AUDMUX_PTCR6_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR6_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR6_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR6, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR6_TFSEL      (27)
#define BM_AUDMUX_PTCR6_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR6_TFSEL)
#else
#define BF_AUDMUX_PTCR6_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR6_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR6_TFSEL(v)   BF_CS1(AUDMUX_PTCR6, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR6, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR6_TFS_DIR      (31)
#define BM_AUDMUX_PTCR6_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR6_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR6_TFS_DIR)
#else
#define BF_AUDMUX_PTCR6_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR6_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR6_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR6, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR6 - Port Data Control Register 6 (RW)
 *
 * PDCR6 is the Port Data Control Register for Port 6.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr6_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR6 register
 */
#define HW_AUDMUX_PDCR6_ADDR      (REGS_AUDMUX_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR6           (*(volatile hw_audmux_pdcr6_t *) HW_AUDMUX_PDCR6_ADDR)
#define HW_AUDMUX_PDCR6_RD()      (HW_AUDMUX_PDCR6.U)
#define HW_AUDMUX_PDCR6_WR(v)     (HW_AUDMUX_PDCR6.U = (v))
#define HW_AUDMUX_PDCR6_SET(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() |  (v)))
#define HW_AUDMUX_PDCR6_CLR(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() & ~(v)))
#define HW_AUDMUX_PDCR6_TOG(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR6 bitfields
 */

/* --- Register HW_AUDMUX_PDCR6, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR6_INMMASK      (0)
#define BM_AUDMUX_PDCR6_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR6_INMMASK)
#else
#define BF_AUDMUX_PDCR6_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR6_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR6_INMMASK(v)   BF_CS1(AUDMUX_PDCR6, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR6, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR6_MODE      (8)
#define BM_AUDMUX_PDCR6_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR6_MODE)
#else
#define BF_AUDMUX_PDCR6_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR6_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR6_MODE(v)   BF_CS1(AUDMUX_PDCR6, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR6, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR6_TXRXEN      (12)
#define BM_AUDMUX_PDCR6_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR6_TXRXEN)
#else
#define BF_AUDMUX_PDCR6_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR6_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR6_TXRXEN(v)   BF_CS1(AUDMUX_PDCR6, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR6, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR6_RXDSEL      (13)
#define BM_AUDMUX_PDCR6_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR6_RXDSEL)
#else
#define BF_AUDMUX_PDCR6_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR6_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR6_RXDSEL(v)   BF_CS1(AUDMUX_PDCR6, RXDSEL, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR7 - Port Timing Control Register n 7 (RW)
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr7_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR7 register
 */
#define HW_AUDMUX_PTCR7_ADDR      (REGS_AUDMUX_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR7           (*(volatile hw_audmux_ptcr7_t *) HW_AUDMUX_PTCR7_ADDR)
#define HW_AUDMUX_PTCR7_RD()      (HW_AUDMUX_PTCR7.U)
#define HW_AUDMUX_PTCR7_WR(v)     (HW_AUDMUX_PTCR7.U = (v))
#define HW_AUDMUX_PTCR7_SET(v)    (HW_AUDMUX_PTCR7_WR(HW_AUDMUX_PTCR7_RD() |  (v)))
#define HW_AUDMUX_PTCR7_CLR(v)    (HW_AUDMUX_PTCR7_WR(HW_AUDMUX_PTCR7_RD() & ~(v)))
#define HW_AUDMUX_PTCR7_TOG(v)    (HW_AUDMUX_PTCR7_WR(HW_AUDMUX_PTCR7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PTCR7 bitfields
 */

/* --- Register HW_AUDMUX_PTCR7, field SYN[11:11] (RW)
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and
 * receive sections use common clock and frame sync signals (that is, the port is a 4-wire
 * interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync
 * signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).
 * RCLKDIR and SYN should not be changed at the same time.
 *
 * Values:
 * 0 - Asynchronous mode
 * 1 - Synchronous mode (default)
 */

#define BP_AUDMUX_PTCR7_SYN      (11)
#define BM_AUDMUX_PTCR7_SYN      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR7_SYN)
#else
#define BF_AUDMUX_PTCR7_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR7_SYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR7_SYN(v)   BF_CS1(AUDMUX_PTCR7, SYN, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field RCSEL[15:12] (RW)
 *
 * Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced
 * from TxClk and RxClk from other ports.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR7_RCSEL      (12)
#define BM_AUDMUX_PTCR7_RCSEL      (0x0000f000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR7_RCSEL)
#else
#define BF_AUDMUX_PTCR7_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR7_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR7_RCSEL(v)   BF_CS1(AUDMUX_PTCR7, RCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field RCLKDIR[16:16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR7_RCLKDIR      (16)
#define BM_AUDMUX_PTCR7_RCLKDIR      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR7_RCLKDIR)
#else
#define BF_AUDMUX_PTCR7_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR7_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR7_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR7, RCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field RFSEL[20:17] (RW)
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be
 * sourced from TxFS and RxFS from other ports.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR7_RFSEL      (17)
#define BM_AUDMUX_PTCR7_RFSEL      (0x001e0000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR7_RFSEL)
#else
#define BF_AUDMUX_PTCR7_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR7_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR7_RFSEL(v)   BF_CS1(AUDMUX_PTCR7, RFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field RFS_DIR[21:21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR7_RFS_DIR      (21)
#define BM_AUDMUX_PTCR7_RFS_DIR      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR7_RFS_DIR)
#else
#define BF_AUDMUX_PTCR7_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR7_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR7_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR7, RFS_DIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field TCSEL[25:22] (RW)
 *
 * Transmit Clock Select. Selects the source port from which TxClk is sourced.
 *
 * Values:
 * 0xxx - Selects TxClk from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxClk from port.
 */

#define BP_AUDMUX_PTCR7_TCSEL      (22)
#define BM_AUDMUX_PTCR7_TCSEL      (0x03c00000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR7_TCSEL)
#else
#define BF_AUDMUX_PTCR7_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR7_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR7_TCSEL(v)   BF_CS1(AUDMUX_PTCR7, TCSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field TCLKDIR[26:26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR7_TCLKDIR      (26)
#define BM_AUDMUX_PTCR7_TCLKDIR      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR7_TCLKDIR)
#else
#define BF_AUDMUX_PTCR7_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR7_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR7_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR7, TCLKDIR, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field TFSEL[30:27] (RW)
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
 *
 * Values:
 * 0xxx - Selects TxFS from port.
 * x000 - Port 1
 * x110 - Port 7
 * x111 - Reserved
 * 1xxx - Selects RxFS from port.
 */

#define BP_AUDMUX_PTCR7_TFSEL      (27)
#define BM_AUDMUX_PTCR7_TFSEL      (0x78000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR7_TFSEL)
#else
#define BF_AUDMUX_PTCR7_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR7_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR7_TFSEL(v)   BF_CS1(AUDMUX_PTCR7, TFSEL, v)
#endif


/* --- Register HW_AUDMUX_PTCR7, field TFS_DIR[31:31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR7_TFS_DIR      (31)
#define BM_AUDMUX_PTCR7_TFS_DIR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR7_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR7_TFS_DIR)
#else
#define BF_AUDMUX_PTCR7_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR7_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR7_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR7, TFS_DIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR7 - Port Data Control Register 7 (RW)
 *
 * PDCR7 PDCR6 is the Port Data Control Register for Port 7 Port 6 .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INMMASK : 8; //!< Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXRXEN : 1; //!< Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_audmux_pdcr7_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR7 register
 */
#define HW_AUDMUX_PDCR7_ADDR      (REGS_AUDMUX_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR7           (*(volatile hw_audmux_pdcr7_t *) HW_AUDMUX_PDCR7_ADDR)
#define HW_AUDMUX_PDCR7_RD()      (HW_AUDMUX_PDCR7.U)
#define HW_AUDMUX_PDCR7_WR(v)     (HW_AUDMUX_PDCR7.U = (v))
#define HW_AUDMUX_PDCR7_SET(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() |  (v)))
#define HW_AUDMUX_PDCR7_CLR(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() & ~(v)))
#define HW_AUDMUX_PDCR7_TOG(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual AUDMUX_PDCR7 bitfields
 */

/* --- Register HW_AUDMUX_PDCR7, field INMMASK[7:0] (RW)
 *
 * Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be
 * ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0
 * represents RxD from Port 1.
 *
 * Values:
 * 0 - Includes RxDn for ANDing
 * 1 - Excludes RxDn from ANDing
 */

#define BP_AUDMUX_PDCR7_INMMASK      (0)
#define BM_AUDMUX_PDCR7_INMMASK      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR7_INMMASK)
#else
#define BF_AUDMUX_PDCR7_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR7_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR7_INMMASK(v)   BF_CS1(AUDMUX_PDCR7, INMMASK, v)
#endif


/* --- Register HW_AUDMUX_PDCR7, field MODE[8:8] (RW)
 *
 * Mode Select. This field selects the mode in which the port is to operate. The modes of operation
 * include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed
 * to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is
 * ignored. INMMASK determines which RxD signals are ANDed together.
 *
 * Values:
 * 0 - Normal mode
 * 1 - Internal Network mode
 */

#define BP_AUDMUX_PDCR7_MODE      (8)
#define BM_AUDMUX_PDCR7_MODE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR7_MODE)
#else
#define BF_AUDMUX_PDCR7_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR7_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR7_MODE(v)   BF_CS1(AUDMUX_PDCR7, MODE, v)
#endif


/* --- Register HW_AUDMUX_PDCR7, field TXRXEN[12:12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR7_TXRXEN      (12)
#define BM_AUDMUX_PDCR7_TXRXEN      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR7_TXRXEN)
#else
#define BF_AUDMUX_PDCR7_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR7_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR7_TXRXEN(v)   BF_CS1(AUDMUX_PDCR7, TXRXEN, v)
#endif


/* --- Register HW_AUDMUX_PDCR7, field RXDSEL[15:13] (RW)
 *
 * Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1
 * (that is, Internal Network Mode is enabled).
 *
 * Values:
 * xxx - Port number for RxD
 * 000 - Port 1
 * 110 - Port 7
 * 111 - Reserved
 */

#define BP_AUDMUX_PDCR7_RXDSEL      (13)
#define BM_AUDMUX_PDCR7_RXDSEL      (0x0000e000)

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR7_RXDSEL)
#else
#define BF_AUDMUX_PDCR7_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR7_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR7_RXDSEL(v)   BF_CS1(AUDMUX_PDCR7, RXDSEL, v)
#endif



/*!
 * @brief All AUDMUX module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_audmux_ptcr1_t PTCR1; //!< Port Timing Control Register 1
    volatile hw_audmux_pdcr1_t PDCR1; //!< Port Data Control Register 1
    volatile hw_audmux_ptcr2_t PTCR2; //!< Port Timing Control Register 2
    volatile hw_audmux_pdcr2_t PDCR2; //!< Port Data Control Register 2
    volatile hw_audmux_ptcr3_t PTCR3; //!< Port Timing Control Register 3
    volatile hw_audmux_pdcr3_t PDCR3; //!< Port Data Control Register 3
    volatile hw_audmux_ptcr4_t PTCR4; //!< Port Timing Control Register n 4
    volatile hw_audmux_pdcr4_t PDCR4; //!< Port Data Control Register 4
    volatile hw_audmux_ptcr5_t PTCR5; //!< Port Timing Control Register n 5
    volatile hw_audmux_pdcr5_t PDCR5; //!< Port Data Control Register 5
    volatile hw_audmux_ptcr6_t PTCR6; //!< Port Timing Control Register n 6
    volatile hw_audmux_pdcr6_t PDCR6; //!< Port Data Control Register 6
    volatile hw_audmux_ptcr7_t PTCR7; //!< Port Timing Control Register n 7
    volatile hw_audmux_pdcr7_t PDCR7; //!< Port Data Control Register 7
} hw_audmux_t;
#endif

//! @brief Macro to access all AUDMUX registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_AUDMUX(0)</code>.
#define HW_AUDMUX     (*(volatile hw_audmux_t *) REGS_AUDMUX_BASE)


#endif // _AUDMUX_H
