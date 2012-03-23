/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_AUDMUX_REGISTERS_H__
#define __HW_AUDMUX_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL AUDMUX registers defined in this header file.
 *
 * - HW_AUDMUX_PTCR1 - Port Timing Control Register 1
 * - HW_AUDMUX_PDCR1 - Port Data Control Register 1
 * - HW_AUDMUX_PTCR2 - Port Timing Control Register 2
 * - HW_AUDMUX_PDCR2 - Port Data Control Register 2
 * - HW_AUDMUX_PTCR3 - Port Timing Control Register 3
 * - HW_AUDMUX_PDCR3 - Port Data Control Register 3
 * - HW_AUDMUX_PTCR4 - Port Timing Control Register n
 * - HW_AUDMUX_PDCR4 - Port Data Control Register 4
 * - HW_AUDMUX_PTCR5 - Port Timing Control Register n
 * - HW_AUDMUX_PDCR5 - Port Data Control Register 5
 * - HW_AUDMUX_PTCR6 - Port Timing Control Register n
 * - HW_AUDMUX_PDCR6 - Port Data Control Register 6
 * - HW_AUDMUX_PTCR7 - Port Timing Control Register n
 * - HW_AUDMUX_PDCR7 - Port Data Control Register 7
 *
 * - hw_audmux_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_AUDMUX_BASE
#define HW_AUDMUX_INSTANCE_COUNT (1) //!< Number of instances of the AUDMUX module.
#define REGS_AUDMUX_BASE (0x021d8000) //!< Base address for AUDMUX.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR1 - Port Timing Control Register 1 (RW)
 *
 * Reset value: 0xad400800
 *
 * PTCR1 is the Port Timing Control Register for Port 1.
 */
typedef union _hw_audmux_ptcr1
{
    reg32_t U;
    struct _hw_audmux_ptcr1_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR1, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR1_SYN      (11)      //!< Bit position for AUDMUX_PTCR1_SYN.
#define BM_AUDMUX_PTCR1_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR1_SYN.

//! @brief Get value of AUDMUX_PTCR1_SYN from a register value.
#define BG_AUDMUX_PTCR1_SYN(r)   (((r) & BM_AUDMUX_PTCR1_SYN) >> BP_AUDMUX_PTCR1_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_SYN.
#define BF_AUDMUX_PTCR1_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_SYN) & BM_AUDMUX_PTCR1_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_SYN.
#define BF_AUDMUX_PTCR1_SYN(v)   (((v) << BP_AUDMUX_PTCR1_SYN) & BM_AUDMUX_PTCR1_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR1_SYN(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_SYN) | BF_AUDMUX_PTCR1_SYN(v)))
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

#define BP_AUDMUX_PTCR1_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR1_RCSEL.
#define BM_AUDMUX_PTCR1_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR1_RCSEL.

//! @brief Get value of AUDMUX_PTCR1_RCSEL from a register value.
#define BG_AUDMUX_PTCR1_RCSEL(r)   (((r) & BM_AUDMUX_PTCR1_RCSEL) >> BP_AUDMUX_PTCR1_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_RCSEL.
#define BF_AUDMUX_PTCR1_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_RCSEL) & BM_AUDMUX_PTCR1_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_RCSEL.
#define BF_AUDMUX_PTCR1_RCSEL(v)   (((v) << BP_AUDMUX_PTCR1_RCSEL) & BM_AUDMUX_PTCR1_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR1_RCSEL(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_RCSEL) | BF_AUDMUX_PTCR1_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR1, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR1_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR1_RCLKDIR.
#define BM_AUDMUX_PTCR1_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR1_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR1_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR1_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR1_RCLKDIR) >> BP_AUDMUX_PTCR1_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_RCLKDIR.
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_RCLKDIR) & BM_AUDMUX_PTCR1_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_RCLKDIR.
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR1_RCLKDIR) & BM_AUDMUX_PTCR1_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR1_RCLKDIR(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_RCLKDIR) | BF_AUDMUX_PTCR1_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR1_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR1_RFSEL.
#define BM_AUDMUX_PTCR1_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR1_RFSEL.

//! @brief Get value of AUDMUX_PTCR1_RFSEL from a register value.
#define BG_AUDMUX_PTCR1_RFSEL(r)   (((r) & BM_AUDMUX_PTCR1_RFSEL) >> BP_AUDMUX_PTCR1_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_RFSEL.
#define BF_AUDMUX_PTCR1_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_RFSEL) & BM_AUDMUX_PTCR1_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_RFSEL.
#define BF_AUDMUX_PTCR1_RFSEL(v)   (((v) << BP_AUDMUX_PTCR1_RFSEL) & BM_AUDMUX_PTCR1_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR1_RFSEL(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_RFSEL) | BF_AUDMUX_PTCR1_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR1, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR1_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR1_RFS_DIR.
#define BM_AUDMUX_PTCR1_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR1_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR1_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR1_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR1_RFS_DIR) >> BP_AUDMUX_PTCR1_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_RFS_DIR.
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_RFS_DIR) & BM_AUDMUX_PTCR1_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_RFS_DIR.
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR1_RFS_DIR) & BM_AUDMUX_PTCR1_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR1_RFS_DIR(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_RFS_DIR) | BF_AUDMUX_PTCR1_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR1_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR1_TCSEL.
#define BM_AUDMUX_PTCR1_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR1_TCSEL.

//! @brief Get value of AUDMUX_PTCR1_TCSEL from a register value.
#define BG_AUDMUX_PTCR1_TCSEL(r)   (((r) & BM_AUDMUX_PTCR1_TCSEL) >> BP_AUDMUX_PTCR1_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_TCSEL.
#define BF_AUDMUX_PTCR1_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_TCSEL) & BM_AUDMUX_PTCR1_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_TCSEL.
#define BF_AUDMUX_PTCR1_TCSEL(v)   (((v) << BP_AUDMUX_PTCR1_TCSEL) & BM_AUDMUX_PTCR1_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR1_TCSEL(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_TCSEL) | BF_AUDMUX_PTCR1_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR1, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR1_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR1_TCLKDIR.
#define BM_AUDMUX_PTCR1_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR1_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR1_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR1_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR1_TCLKDIR) >> BP_AUDMUX_PTCR1_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_TCLKDIR.
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_TCLKDIR) & BM_AUDMUX_PTCR1_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_TCLKDIR.
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR1_TCLKDIR) & BM_AUDMUX_PTCR1_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR1_TCLKDIR(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_TCLKDIR) | BF_AUDMUX_PTCR1_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR1_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR1_TFSEL.
#define BM_AUDMUX_PTCR1_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR1_TFSEL.

//! @brief Get value of AUDMUX_PTCR1_TFSEL from a register value.
#define BG_AUDMUX_PTCR1_TFSEL(r)   (((r) & BM_AUDMUX_PTCR1_TFSEL) >> BP_AUDMUX_PTCR1_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_TFSEL.
#define BF_AUDMUX_PTCR1_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_TFSEL) & BM_AUDMUX_PTCR1_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_TFSEL.
#define BF_AUDMUX_PTCR1_TFSEL(v)   (((v) << BP_AUDMUX_PTCR1_TFSEL) & BM_AUDMUX_PTCR1_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR1_TFSEL(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_TFSEL) | BF_AUDMUX_PTCR1_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR1, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR1_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR1_TFS_DIR.
#define BM_AUDMUX_PTCR1_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR1_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR1_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR1_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR1_TFS_DIR) >> BP_AUDMUX_PTCR1_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR1_TFS_DIR.
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR1_TFS_DIR) & BM_AUDMUX_PTCR1_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR1_TFS_DIR.
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR1_TFS_DIR) & BM_AUDMUX_PTCR1_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR1_TFS_DIR(v)   (HW_AUDMUX_PTCR1_WR((HW_AUDMUX_PTCR1_RD() & ~BM_AUDMUX_PTCR1_TFS_DIR) | BF_AUDMUX_PTCR1_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR1 - Port Data Control Register 1 (RW)
 *
 * Reset value: 0x0000a000
 *
 * PDCR1 is the Port Data Control Register for Port 1.
 */
typedef union _hw_audmux_pdcr1
{
    reg32_t U;
    struct _hw_audmux_pdcr1_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR1_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR1_INMMASK.
#define BM_AUDMUX_PDCR1_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR1_INMMASK.

//! @brief Get value of AUDMUX_PDCR1_INMMASK from a register value.
#define BG_AUDMUX_PDCR1_INMMASK(r)   (((r) & BM_AUDMUX_PDCR1_INMMASK) >> BP_AUDMUX_PDCR1_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR1_INMMASK.
#define BF_AUDMUX_PDCR1_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR1_INMMASK) & BM_AUDMUX_PDCR1_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR1_INMMASK.
#define BF_AUDMUX_PDCR1_INMMASK(v)   (((v) << BP_AUDMUX_PDCR1_INMMASK) & BM_AUDMUX_PDCR1_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR1_INMMASK(v)   (HW_AUDMUX_PDCR1_WR((HW_AUDMUX_PDCR1_RD() & ~BM_AUDMUX_PDCR1_INMMASK) | BF_AUDMUX_PDCR1_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR1, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR1_MODE      (8)      //!< Bit position for AUDMUX_PDCR1_MODE.
#define BM_AUDMUX_PDCR1_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR1_MODE.

//! @brief Get value of AUDMUX_PDCR1_MODE from a register value.
#define BG_AUDMUX_PDCR1_MODE(r)   (((r) & BM_AUDMUX_PDCR1_MODE) >> BP_AUDMUX_PDCR1_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR1_MODE.
#define BF_AUDMUX_PDCR1_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR1_MODE) & BM_AUDMUX_PDCR1_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR1_MODE.
#define BF_AUDMUX_PDCR1_MODE(v)   (((v) << BP_AUDMUX_PDCR1_MODE) & BM_AUDMUX_PDCR1_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR1_MODE(v)   (HW_AUDMUX_PDCR1_WR((HW_AUDMUX_PDCR1_RD() & ~BM_AUDMUX_PDCR1_MODE) | BF_AUDMUX_PDCR1_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR1, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR1_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR1_TXRXEN.
#define BM_AUDMUX_PDCR1_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR1_TXRXEN.

//! @brief Get value of AUDMUX_PDCR1_TXRXEN from a register value.
#define BG_AUDMUX_PDCR1_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR1_TXRXEN) >> BP_AUDMUX_PDCR1_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR1_TXRXEN.
#define BF_AUDMUX_PDCR1_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR1_TXRXEN) & BM_AUDMUX_PDCR1_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR1_TXRXEN.
#define BF_AUDMUX_PDCR1_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR1_TXRXEN) & BM_AUDMUX_PDCR1_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR1_TXRXEN(v)   (HW_AUDMUX_PDCR1_WR((HW_AUDMUX_PDCR1_RD() & ~BM_AUDMUX_PDCR1_TXRXEN) | BF_AUDMUX_PDCR1_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR1_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR1_RXDSEL.
#define BM_AUDMUX_PDCR1_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR1_RXDSEL.

//! @brief Get value of AUDMUX_PDCR1_RXDSEL from a register value.
#define BG_AUDMUX_PDCR1_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR1_RXDSEL) >> BP_AUDMUX_PDCR1_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR1_RXDSEL.
#define BF_AUDMUX_PDCR1_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR1_RXDSEL) & BM_AUDMUX_PDCR1_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR1_RXDSEL.
#define BF_AUDMUX_PDCR1_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR1_RXDSEL) & BM_AUDMUX_PDCR1_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR1_RXDSEL(v)   (HW_AUDMUX_PDCR1_WR((HW_AUDMUX_PDCR1_RD() & ~BM_AUDMUX_PDCR1_RXDSEL) | BF_AUDMUX_PDCR1_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR2 - Port Timing Control Register 2 (RW)
 *
 * Reset value: 0xa5000800
 *
 * PTCR2 is the Port Timing Control Register for Port 2.
 */
typedef union _hw_audmux_ptcr2
{
    reg32_t U;
    struct _hw_audmux_ptcr2_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR2, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR2_SYN      (11)      //!< Bit position for AUDMUX_PTCR2_SYN.
#define BM_AUDMUX_PTCR2_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR2_SYN.

//! @brief Get value of AUDMUX_PTCR2_SYN from a register value.
#define BG_AUDMUX_PTCR2_SYN(r)   (((r) & BM_AUDMUX_PTCR2_SYN) >> BP_AUDMUX_PTCR2_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_SYN.
#define BF_AUDMUX_PTCR2_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_SYN) & BM_AUDMUX_PTCR2_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_SYN.
#define BF_AUDMUX_PTCR2_SYN(v)   (((v) << BP_AUDMUX_PTCR2_SYN) & BM_AUDMUX_PTCR2_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR2_SYN(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_SYN) | BF_AUDMUX_PTCR2_SYN(v)))
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

#define BP_AUDMUX_PTCR2_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR2_RCSEL.
#define BM_AUDMUX_PTCR2_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR2_RCSEL.

//! @brief Get value of AUDMUX_PTCR2_RCSEL from a register value.
#define BG_AUDMUX_PTCR2_RCSEL(r)   (((r) & BM_AUDMUX_PTCR2_RCSEL) >> BP_AUDMUX_PTCR2_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_RCSEL.
#define BF_AUDMUX_PTCR2_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_RCSEL) & BM_AUDMUX_PTCR2_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_RCSEL.
#define BF_AUDMUX_PTCR2_RCSEL(v)   (((v) << BP_AUDMUX_PTCR2_RCSEL) & BM_AUDMUX_PTCR2_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR2_RCSEL(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_RCSEL) | BF_AUDMUX_PTCR2_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR2, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR2_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR2_RCLKDIR.
#define BM_AUDMUX_PTCR2_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR2_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR2_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR2_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR2_RCLKDIR) >> BP_AUDMUX_PTCR2_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_RCLKDIR.
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_RCLKDIR) & BM_AUDMUX_PTCR2_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_RCLKDIR.
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR2_RCLKDIR) & BM_AUDMUX_PTCR2_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR2_RCLKDIR(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_RCLKDIR) | BF_AUDMUX_PTCR2_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR2_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR2_RFSEL.
#define BM_AUDMUX_PTCR2_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR2_RFSEL.

//! @brief Get value of AUDMUX_PTCR2_RFSEL from a register value.
#define BG_AUDMUX_PTCR2_RFSEL(r)   (((r) & BM_AUDMUX_PTCR2_RFSEL) >> BP_AUDMUX_PTCR2_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_RFSEL.
#define BF_AUDMUX_PTCR2_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_RFSEL) & BM_AUDMUX_PTCR2_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_RFSEL.
#define BF_AUDMUX_PTCR2_RFSEL(v)   (((v) << BP_AUDMUX_PTCR2_RFSEL) & BM_AUDMUX_PTCR2_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR2_RFSEL(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_RFSEL) | BF_AUDMUX_PTCR2_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR2, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR2_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR2_RFS_DIR.
#define BM_AUDMUX_PTCR2_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR2_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR2_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR2_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR2_RFS_DIR) >> BP_AUDMUX_PTCR2_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_RFS_DIR.
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_RFS_DIR) & BM_AUDMUX_PTCR2_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_RFS_DIR.
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR2_RFS_DIR) & BM_AUDMUX_PTCR2_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR2_RFS_DIR(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_RFS_DIR) | BF_AUDMUX_PTCR2_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR2_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR2_TCSEL.
#define BM_AUDMUX_PTCR2_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR2_TCSEL.

//! @brief Get value of AUDMUX_PTCR2_TCSEL from a register value.
#define BG_AUDMUX_PTCR2_TCSEL(r)   (((r) & BM_AUDMUX_PTCR2_TCSEL) >> BP_AUDMUX_PTCR2_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_TCSEL.
#define BF_AUDMUX_PTCR2_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_TCSEL) & BM_AUDMUX_PTCR2_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_TCSEL.
#define BF_AUDMUX_PTCR2_TCSEL(v)   (((v) << BP_AUDMUX_PTCR2_TCSEL) & BM_AUDMUX_PTCR2_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR2_TCSEL(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_TCSEL) | BF_AUDMUX_PTCR2_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR2, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR2_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR2_TCLKDIR.
#define BM_AUDMUX_PTCR2_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR2_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR2_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR2_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR2_TCLKDIR) >> BP_AUDMUX_PTCR2_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_TCLKDIR.
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_TCLKDIR) & BM_AUDMUX_PTCR2_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_TCLKDIR.
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR2_TCLKDIR) & BM_AUDMUX_PTCR2_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR2_TCLKDIR(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_TCLKDIR) | BF_AUDMUX_PTCR2_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR2_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR2_TFSEL.
#define BM_AUDMUX_PTCR2_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR2_TFSEL.

//! @brief Get value of AUDMUX_PTCR2_TFSEL from a register value.
#define BG_AUDMUX_PTCR2_TFSEL(r)   (((r) & BM_AUDMUX_PTCR2_TFSEL) >> BP_AUDMUX_PTCR2_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_TFSEL.
#define BF_AUDMUX_PTCR2_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_TFSEL) & BM_AUDMUX_PTCR2_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_TFSEL.
#define BF_AUDMUX_PTCR2_TFSEL(v)   (((v) << BP_AUDMUX_PTCR2_TFSEL) & BM_AUDMUX_PTCR2_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR2_TFSEL(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_TFSEL) | BF_AUDMUX_PTCR2_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR2, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR2_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR2_TFS_DIR.
#define BM_AUDMUX_PTCR2_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR2_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR2_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR2_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR2_TFS_DIR) >> BP_AUDMUX_PTCR2_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR2_TFS_DIR.
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR2_TFS_DIR) & BM_AUDMUX_PTCR2_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR2_TFS_DIR.
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR2_TFS_DIR) & BM_AUDMUX_PTCR2_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR2_TFS_DIR(v)   (HW_AUDMUX_PTCR2_WR((HW_AUDMUX_PTCR2_RD() & ~BM_AUDMUX_PTCR2_TFS_DIR) | BF_AUDMUX_PTCR2_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR2 - Port Data Control Register 2 (RW)
 *
 * Reset value: 0x00008000
 *
 * PDCR2 is the Port Data Control Register for Port 2.
 */
typedef union _hw_audmux_pdcr2
{
    reg32_t U;
    struct _hw_audmux_pdcr2_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR2_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR2_INMMASK.
#define BM_AUDMUX_PDCR2_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR2_INMMASK.

//! @brief Get value of AUDMUX_PDCR2_INMMASK from a register value.
#define BG_AUDMUX_PDCR2_INMMASK(r)   (((r) & BM_AUDMUX_PDCR2_INMMASK) >> BP_AUDMUX_PDCR2_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR2_INMMASK.
#define BF_AUDMUX_PDCR2_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR2_INMMASK) & BM_AUDMUX_PDCR2_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR2_INMMASK.
#define BF_AUDMUX_PDCR2_INMMASK(v)   (((v) << BP_AUDMUX_PDCR2_INMMASK) & BM_AUDMUX_PDCR2_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR2_INMMASK(v)   (HW_AUDMUX_PDCR2_WR((HW_AUDMUX_PDCR2_RD() & ~BM_AUDMUX_PDCR2_INMMASK) | BF_AUDMUX_PDCR2_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR2, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR2_MODE      (8)      //!< Bit position for AUDMUX_PDCR2_MODE.
#define BM_AUDMUX_PDCR2_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR2_MODE.

//! @brief Get value of AUDMUX_PDCR2_MODE from a register value.
#define BG_AUDMUX_PDCR2_MODE(r)   (((r) & BM_AUDMUX_PDCR2_MODE) >> BP_AUDMUX_PDCR2_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR2_MODE.
#define BF_AUDMUX_PDCR2_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR2_MODE) & BM_AUDMUX_PDCR2_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR2_MODE.
#define BF_AUDMUX_PDCR2_MODE(v)   (((v) << BP_AUDMUX_PDCR2_MODE) & BM_AUDMUX_PDCR2_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR2_MODE(v)   (HW_AUDMUX_PDCR2_WR((HW_AUDMUX_PDCR2_RD() & ~BM_AUDMUX_PDCR2_MODE) | BF_AUDMUX_PDCR2_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR2, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR2_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR2_TXRXEN.
#define BM_AUDMUX_PDCR2_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR2_TXRXEN.

//! @brief Get value of AUDMUX_PDCR2_TXRXEN from a register value.
#define BG_AUDMUX_PDCR2_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR2_TXRXEN) >> BP_AUDMUX_PDCR2_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR2_TXRXEN.
#define BF_AUDMUX_PDCR2_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR2_TXRXEN) & BM_AUDMUX_PDCR2_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR2_TXRXEN.
#define BF_AUDMUX_PDCR2_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR2_TXRXEN) & BM_AUDMUX_PDCR2_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR2_TXRXEN(v)   (HW_AUDMUX_PDCR2_WR((HW_AUDMUX_PDCR2_RD() & ~BM_AUDMUX_PDCR2_TXRXEN) | BF_AUDMUX_PDCR2_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR2_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR2_RXDSEL.
#define BM_AUDMUX_PDCR2_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR2_RXDSEL.

//! @brief Get value of AUDMUX_PDCR2_RXDSEL from a register value.
#define BG_AUDMUX_PDCR2_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR2_RXDSEL) >> BP_AUDMUX_PDCR2_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR2_RXDSEL.
#define BF_AUDMUX_PDCR2_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR2_RXDSEL) & BM_AUDMUX_PDCR2_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR2_RXDSEL.
#define BF_AUDMUX_PDCR2_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR2_RXDSEL) & BM_AUDMUX_PDCR2_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR2_RXDSEL(v)   (HW_AUDMUX_PDCR2_WR((HW_AUDMUX_PDCR2_RD() & ~BM_AUDMUX_PDCR2_RXDSEL) | BF_AUDMUX_PDCR2_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR3 - Port Timing Control Register 3 (RW)
 *
 * Reset value: 0x9cc00800
 *
 * PTCR3 is the Port Timing Control Register for Port 3.
 */
typedef union _hw_audmux_ptcr3
{
    reg32_t U;
    struct _hw_audmux_ptcr3_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR3, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR3_SYN      (11)      //!< Bit position for AUDMUX_PTCR3_SYN.
#define BM_AUDMUX_PTCR3_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR3_SYN.

//! @brief Get value of AUDMUX_PTCR3_SYN from a register value.
#define BG_AUDMUX_PTCR3_SYN(r)   (((r) & BM_AUDMUX_PTCR3_SYN) >> BP_AUDMUX_PTCR3_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_SYN.
#define BF_AUDMUX_PTCR3_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_SYN) & BM_AUDMUX_PTCR3_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_SYN.
#define BF_AUDMUX_PTCR3_SYN(v)   (((v) << BP_AUDMUX_PTCR3_SYN) & BM_AUDMUX_PTCR3_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR3_SYN(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_SYN) | BF_AUDMUX_PTCR3_SYN(v)))
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

#define BP_AUDMUX_PTCR3_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR3_RCSEL.
#define BM_AUDMUX_PTCR3_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR3_RCSEL.

//! @brief Get value of AUDMUX_PTCR3_RCSEL from a register value.
#define BG_AUDMUX_PTCR3_RCSEL(r)   (((r) & BM_AUDMUX_PTCR3_RCSEL) >> BP_AUDMUX_PTCR3_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_RCSEL.
#define BF_AUDMUX_PTCR3_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_RCSEL) & BM_AUDMUX_PTCR3_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_RCSEL.
#define BF_AUDMUX_PTCR3_RCSEL(v)   (((v) << BP_AUDMUX_PTCR3_RCSEL) & BM_AUDMUX_PTCR3_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR3_RCSEL(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_RCSEL) | BF_AUDMUX_PTCR3_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR3, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR3_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR3_RCLKDIR.
#define BM_AUDMUX_PTCR3_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR3_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR3_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR3_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR3_RCLKDIR) >> BP_AUDMUX_PTCR3_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_RCLKDIR.
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_RCLKDIR) & BM_AUDMUX_PTCR3_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_RCLKDIR.
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR3_RCLKDIR) & BM_AUDMUX_PTCR3_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR3_RCLKDIR(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_RCLKDIR) | BF_AUDMUX_PTCR3_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR3_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR3_RFSEL.
#define BM_AUDMUX_PTCR3_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR3_RFSEL.

//! @brief Get value of AUDMUX_PTCR3_RFSEL from a register value.
#define BG_AUDMUX_PTCR3_RFSEL(r)   (((r) & BM_AUDMUX_PTCR3_RFSEL) >> BP_AUDMUX_PTCR3_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_RFSEL.
#define BF_AUDMUX_PTCR3_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_RFSEL) & BM_AUDMUX_PTCR3_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_RFSEL.
#define BF_AUDMUX_PTCR3_RFSEL(v)   (((v) << BP_AUDMUX_PTCR3_RFSEL) & BM_AUDMUX_PTCR3_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR3_RFSEL(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_RFSEL) | BF_AUDMUX_PTCR3_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR3, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR3_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR3_RFS_DIR.
#define BM_AUDMUX_PTCR3_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR3_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR3_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR3_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR3_RFS_DIR) >> BP_AUDMUX_PTCR3_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_RFS_DIR.
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_RFS_DIR) & BM_AUDMUX_PTCR3_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_RFS_DIR.
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR3_RFS_DIR) & BM_AUDMUX_PTCR3_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR3_RFS_DIR(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_RFS_DIR) | BF_AUDMUX_PTCR3_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR3_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR3_TCSEL.
#define BM_AUDMUX_PTCR3_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR3_TCSEL.

//! @brief Get value of AUDMUX_PTCR3_TCSEL from a register value.
#define BG_AUDMUX_PTCR3_TCSEL(r)   (((r) & BM_AUDMUX_PTCR3_TCSEL) >> BP_AUDMUX_PTCR3_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_TCSEL.
#define BF_AUDMUX_PTCR3_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_TCSEL) & BM_AUDMUX_PTCR3_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_TCSEL.
#define BF_AUDMUX_PTCR3_TCSEL(v)   (((v) << BP_AUDMUX_PTCR3_TCSEL) & BM_AUDMUX_PTCR3_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR3_TCSEL(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_TCSEL) | BF_AUDMUX_PTCR3_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR3, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR3_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR3_TCLKDIR.
#define BM_AUDMUX_PTCR3_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR3_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR3_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR3_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR3_TCLKDIR) >> BP_AUDMUX_PTCR3_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_TCLKDIR.
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_TCLKDIR) & BM_AUDMUX_PTCR3_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_TCLKDIR.
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR3_TCLKDIR) & BM_AUDMUX_PTCR3_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR3_TCLKDIR(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_TCLKDIR) | BF_AUDMUX_PTCR3_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR3_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR3_TFSEL.
#define BM_AUDMUX_PTCR3_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR3_TFSEL.

//! @brief Get value of AUDMUX_PTCR3_TFSEL from a register value.
#define BG_AUDMUX_PTCR3_TFSEL(r)   (((r) & BM_AUDMUX_PTCR3_TFSEL) >> BP_AUDMUX_PTCR3_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_TFSEL.
#define BF_AUDMUX_PTCR3_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_TFSEL) & BM_AUDMUX_PTCR3_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_TFSEL.
#define BF_AUDMUX_PTCR3_TFSEL(v)   (((v) << BP_AUDMUX_PTCR3_TFSEL) & BM_AUDMUX_PTCR3_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR3_TFSEL(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_TFSEL) | BF_AUDMUX_PTCR3_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR3, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR3_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR3_TFS_DIR.
#define BM_AUDMUX_PTCR3_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR3_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR3_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR3_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR3_TFS_DIR) >> BP_AUDMUX_PTCR3_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR3_TFS_DIR.
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR3_TFS_DIR) & BM_AUDMUX_PTCR3_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR3_TFS_DIR.
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR3_TFS_DIR) & BM_AUDMUX_PTCR3_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR3_TFS_DIR(v)   (HW_AUDMUX_PTCR3_WR((HW_AUDMUX_PTCR3_RD() & ~BM_AUDMUX_PTCR3_TFS_DIR) | BF_AUDMUX_PTCR3_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR3 - Port Data Control Register 3 (RW)
 *
 * Reset value: 0x00006000
 *
 * PDCR3 is the Port Data Control Register for Port 3.
 */
typedef union _hw_audmux_pdcr3
{
    reg32_t U;
    struct _hw_audmux_pdcr3_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR3_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR3_INMMASK.
#define BM_AUDMUX_PDCR3_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR3_INMMASK.

//! @brief Get value of AUDMUX_PDCR3_INMMASK from a register value.
#define BG_AUDMUX_PDCR3_INMMASK(r)   (((r) & BM_AUDMUX_PDCR3_INMMASK) >> BP_AUDMUX_PDCR3_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR3_INMMASK.
#define BF_AUDMUX_PDCR3_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR3_INMMASK) & BM_AUDMUX_PDCR3_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR3_INMMASK.
#define BF_AUDMUX_PDCR3_INMMASK(v)   (((v) << BP_AUDMUX_PDCR3_INMMASK) & BM_AUDMUX_PDCR3_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR3_INMMASK(v)   (HW_AUDMUX_PDCR3_WR((HW_AUDMUX_PDCR3_RD() & ~BM_AUDMUX_PDCR3_INMMASK) | BF_AUDMUX_PDCR3_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR3, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR3_MODE      (8)      //!< Bit position for AUDMUX_PDCR3_MODE.
#define BM_AUDMUX_PDCR3_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR3_MODE.

//! @brief Get value of AUDMUX_PDCR3_MODE from a register value.
#define BG_AUDMUX_PDCR3_MODE(r)   (((r) & BM_AUDMUX_PDCR3_MODE) >> BP_AUDMUX_PDCR3_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR3_MODE.
#define BF_AUDMUX_PDCR3_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR3_MODE) & BM_AUDMUX_PDCR3_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR3_MODE.
#define BF_AUDMUX_PDCR3_MODE(v)   (((v) << BP_AUDMUX_PDCR3_MODE) & BM_AUDMUX_PDCR3_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR3_MODE(v)   (HW_AUDMUX_PDCR3_WR((HW_AUDMUX_PDCR3_RD() & ~BM_AUDMUX_PDCR3_MODE) | BF_AUDMUX_PDCR3_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR3, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR3_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR3_TXRXEN.
#define BM_AUDMUX_PDCR3_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR3_TXRXEN.

//! @brief Get value of AUDMUX_PDCR3_TXRXEN from a register value.
#define BG_AUDMUX_PDCR3_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR3_TXRXEN) >> BP_AUDMUX_PDCR3_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR3_TXRXEN.
#define BF_AUDMUX_PDCR3_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR3_TXRXEN) & BM_AUDMUX_PDCR3_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR3_TXRXEN.
#define BF_AUDMUX_PDCR3_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR3_TXRXEN) & BM_AUDMUX_PDCR3_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR3_TXRXEN(v)   (HW_AUDMUX_PDCR3_WR((HW_AUDMUX_PDCR3_RD() & ~BM_AUDMUX_PDCR3_TXRXEN) | BF_AUDMUX_PDCR3_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR3_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR3_RXDSEL.
#define BM_AUDMUX_PDCR3_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR3_RXDSEL.

//! @brief Get value of AUDMUX_PDCR3_RXDSEL from a register value.
#define BG_AUDMUX_PDCR3_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR3_RXDSEL) >> BP_AUDMUX_PDCR3_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR3_RXDSEL.
#define BF_AUDMUX_PDCR3_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR3_RXDSEL) & BM_AUDMUX_PDCR3_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR3_RXDSEL.
#define BF_AUDMUX_PDCR3_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR3_RXDSEL) & BM_AUDMUX_PDCR3_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR3_RXDSEL(v)   (HW_AUDMUX_PDCR3_WR((HW_AUDMUX_PDCR3_RD() & ~BM_AUDMUX_PDCR3_RXDSEL) | BF_AUDMUX_PDCR3_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR4 - Port Timing Control Register n (RW)
 *
 * Reset value: 0x00000800
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union _hw_audmux_ptcr4
{
    reg32_t U;
    struct _hw_audmux_ptcr4_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR4, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR4_SYN      (11)      //!< Bit position for AUDMUX_PTCR4_SYN.
#define BM_AUDMUX_PTCR4_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR4_SYN.

//! @brief Get value of AUDMUX_PTCR4_SYN from a register value.
#define BG_AUDMUX_PTCR4_SYN(r)   (((r) & BM_AUDMUX_PTCR4_SYN) >> BP_AUDMUX_PTCR4_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_SYN.
#define BF_AUDMUX_PTCR4_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_SYN) & BM_AUDMUX_PTCR4_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_SYN.
#define BF_AUDMUX_PTCR4_SYN(v)   (((v) << BP_AUDMUX_PTCR4_SYN) & BM_AUDMUX_PTCR4_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR4_SYN(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_SYN) | BF_AUDMUX_PTCR4_SYN(v)))
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

#define BP_AUDMUX_PTCR4_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR4_RCSEL.
#define BM_AUDMUX_PTCR4_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR4_RCSEL.

//! @brief Get value of AUDMUX_PTCR4_RCSEL from a register value.
#define BG_AUDMUX_PTCR4_RCSEL(r)   (((r) & BM_AUDMUX_PTCR4_RCSEL) >> BP_AUDMUX_PTCR4_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_RCSEL.
#define BF_AUDMUX_PTCR4_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_RCSEL) & BM_AUDMUX_PTCR4_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_RCSEL.
#define BF_AUDMUX_PTCR4_RCSEL(v)   (((v) << BP_AUDMUX_PTCR4_RCSEL) & BM_AUDMUX_PTCR4_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR4_RCSEL(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_RCSEL) | BF_AUDMUX_PTCR4_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR4, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR4_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR4_RCLKDIR.
#define BM_AUDMUX_PTCR4_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR4_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR4_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR4_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR4_RCLKDIR) >> BP_AUDMUX_PTCR4_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_RCLKDIR.
#define BF_AUDMUX_PTCR4_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_RCLKDIR) & BM_AUDMUX_PTCR4_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_RCLKDIR.
#define BF_AUDMUX_PTCR4_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR4_RCLKDIR) & BM_AUDMUX_PTCR4_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR4_RCLKDIR(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_RCLKDIR) | BF_AUDMUX_PTCR4_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR4_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR4_RFSEL.
#define BM_AUDMUX_PTCR4_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR4_RFSEL.

//! @brief Get value of AUDMUX_PTCR4_RFSEL from a register value.
#define BG_AUDMUX_PTCR4_RFSEL(r)   (((r) & BM_AUDMUX_PTCR4_RFSEL) >> BP_AUDMUX_PTCR4_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_RFSEL.
#define BF_AUDMUX_PTCR4_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_RFSEL) & BM_AUDMUX_PTCR4_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_RFSEL.
#define BF_AUDMUX_PTCR4_RFSEL(v)   (((v) << BP_AUDMUX_PTCR4_RFSEL) & BM_AUDMUX_PTCR4_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR4_RFSEL(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_RFSEL) | BF_AUDMUX_PTCR4_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR4, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR4_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR4_RFS_DIR.
#define BM_AUDMUX_PTCR4_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR4_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR4_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR4_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR4_RFS_DIR) >> BP_AUDMUX_PTCR4_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_RFS_DIR.
#define BF_AUDMUX_PTCR4_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_RFS_DIR) & BM_AUDMUX_PTCR4_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_RFS_DIR.
#define BF_AUDMUX_PTCR4_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR4_RFS_DIR) & BM_AUDMUX_PTCR4_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR4_RFS_DIR(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_RFS_DIR) | BF_AUDMUX_PTCR4_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR4_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR4_TCSEL.
#define BM_AUDMUX_PTCR4_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR4_TCSEL.

//! @brief Get value of AUDMUX_PTCR4_TCSEL from a register value.
#define BG_AUDMUX_PTCR4_TCSEL(r)   (((r) & BM_AUDMUX_PTCR4_TCSEL) >> BP_AUDMUX_PTCR4_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_TCSEL.
#define BF_AUDMUX_PTCR4_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_TCSEL) & BM_AUDMUX_PTCR4_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_TCSEL.
#define BF_AUDMUX_PTCR4_TCSEL(v)   (((v) << BP_AUDMUX_PTCR4_TCSEL) & BM_AUDMUX_PTCR4_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR4_TCSEL(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_TCSEL) | BF_AUDMUX_PTCR4_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR4, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR4_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR4_TCLKDIR.
#define BM_AUDMUX_PTCR4_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR4_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR4_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR4_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR4_TCLKDIR) >> BP_AUDMUX_PTCR4_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_TCLKDIR.
#define BF_AUDMUX_PTCR4_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_TCLKDIR) & BM_AUDMUX_PTCR4_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_TCLKDIR.
#define BF_AUDMUX_PTCR4_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR4_TCLKDIR) & BM_AUDMUX_PTCR4_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR4_TCLKDIR(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_TCLKDIR) | BF_AUDMUX_PTCR4_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR4_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR4_TFSEL.
#define BM_AUDMUX_PTCR4_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR4_TFSEL.

//! @brief Get value of AUDMUX_PTCR4_TFSEL from a register value.
#define BG_AUDMUX_PTCR4_TFSEL(r)   (((r) & BM_AUDMUX_PTCR4_TFSEL) >> BP_AUDMUX_PTCR4_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_TFSEL.
#define BF_AUDMUX_PTCR4_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_TFSEL) & BM_AUDMUX_PTCR4_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_TFSEL.
#define BF_AUDMUX_PTCR4_TFSEL(v)   (((v) << BP_AUDMUX_PTCR4_TFSEL) & BM_AUDMUX_PTCR4_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR4_TFSEL(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_TFSEL) | BF_AUDMUX_PTCR4_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR4, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR4_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR4_TFS_DIR.
#define BM_AUDMUX_PTCR4_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR4_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR4_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR4_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR4_TFS_DIR) >> BP_AUDMUX_PTCR4_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR4_TFS_DIR.
#define BF_AUDMUX_PTCR4_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR4_TFS_DIR) & BM_AUDMUX_PTCR4_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR4_TFS_DIR.
#define BF_AUDMUX_PTCR4_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR4_TFS_DIR) & BM_AUDMUX_PTCR4_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR4_TFS_DIR(v)   (HW_AUDMUX_PTCR4_WR((HW_AUDMUX_PTCR4_RD() & ~BM_AUDMUX_PTCR4_TFS_DIR) | BF_AUDMUX_PTCR4_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR4 - Port Data Control Register 4 (RW)
 *
 * Reset value: 0x00004000
 *
 * PDCR4 is the Port Data Control Register for Port 4.
 */
typedef union _hw_audmux_pdcr4
{
    reg32_t U;
    struct _hw_audmux_pdcr4_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR4_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR4_INMMASK.
#define BM_AUDMUX_PDCR4_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR4_INMMASK.

//! @brief Get value of AUDMUX_PDCR4_INMMASK from a register value.
#define BG_AUDMUX_PDCR4_INMMASK(r)   (((r) & BM_AUDMUX_PDCR4_INMMASK) >> BP_AUDMUX_PDCR4_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR4_INMMASK.
#define BF_AUDMUX_PDCR4_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR4_INMMASK) & BM_AUDMUX_PDCR4_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR4_INMMASK.
#define BF_AUDMUX_PDCR4_INMMASK(v)   (((v) << BP_AUDMUX_PDCR4_INMMASK) & BM_AUDMUX_PDCR4_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR4_INMMASK(v)   (HW_AUDMUX_PDCR4_WR((HW_AUDMUX_PDCR4_RD() & ~BM_AUDMUX_PDCR4_INMMASK) | BF_AUDMUX_PDCR4_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR4, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR4_MODE      (8)      //!< Bit position for AUDMUX_PDCR4_MODE.
#define BM_AUDMUX_PDCR4_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR4_MODE.

//! @brief Get value of AUDMUX_PDCR4_MODE from a register value.
#define BG_AUDMUX_PDCR4_MODE(r)   (((r) & BM_AUDMUX_PDCR4_MODE) >> BP_AUDMUX_PDCR4_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR4_MODE.
#define BF_AUDMUX_PDCR4_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR4_MODE) & BM_AUDMUX_PDCR4_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR4_MODE.
#define BF_AUDMUX_PDCR4_MODE(v)   (((v) << BP_AUDMUX_PDCR4_MODE) & BM_AUDMUX_PDCR4_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR4_MODE(v)   (HW_AUDMUX_PDCR4_WR((HW_AUDMUX_PDCR4_RD() & ~BM_AUDMUX_PDCR4_MODE) | BF_AUDMUX_PDCR4_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR4, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR4_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR4_TXRXEN.
#define BM_AUDMUX_PDCR4_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR4_TXRXEN.

//! @brief Get value of AUDMUX_PDCR4_TXRXEN from a register value.
#define BG_AUDMUX_PDCR4_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR4_TXRXEN) >> BP_AUDMUX_PDCR4_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR4_TXRXEN.
#define BF_AUDMUX_PDCR4_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR4_TXRXEN) & BM_AUDMUX_PDCR4_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR4_TXRXEN.
#define BF_AUDMUX_PDCR4_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR4_TXRXEN) & BM_AUDMUX_PDCR4_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR4_TXRXEN(v)   (HW_AUDMUX_PDCR4_WR((HW_AUDMUX_PDCR4_RD() & ~BM_AUDMUX_PDCR4_TXRXEN) | BF_AUDMUX_PDCR4_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR4_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR4_RXDSEL.
#define BM_AUDMUX_PDCR4_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR4_RXDSEL.

//! @brief Get value of AUDMUX_PDCR4_RXDSEL from a register value.
#define BG_AUDMUX_PDCR4_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR4_RXDSEL) >> BP_AUDMUX_PDCR4_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR4_RXDSEL.
#define BF_AUDMUX_PDCR4_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR4_RXDSEL) & BM_AUDMUX_PDCR4_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR4_RXDSEL.
#define BF_AUDMUX_PDCR4_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR4_RXDSEL) & BM_AUDMUX_PDCR4_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR4_RXDSEL(v)   (HW_AUDMUX_PDCR4_WR((HW_AUDMUX_PDCR4_RD() & ~BM_AUDMUX_PDCR4_RXDSEL) | BF_AUDMUX_PDCR4_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR5 - Port Timing Control Register n (RW)
 *
 * Reset value: 0x00000800
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union _hw_audmux_ptcr5
{
    reg32_t U;
    struct _hw_audmux_ptcr5_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR5, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR5_SYN      (11)      //!< Bit position for AUDMUX_PTCR5_SYN.
#define BM_AUDMUX_PTCR5_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR5_SYN.

//! @brief Get value of AUDMUX_PTCR5_SYN from a register value.
#define BG_AUDMUX_PTCR5_SYN(r)   (((r) & BM_AUDMUX_PTCR5_SYN) >> BP_AUDMUX_PTCR5_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_SYN.
#define BF_AUDMUX_PTCR5_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_SYN) & BM_AUDMUX_PTCR5_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_SYN.
#define BF_AUDMUX_PTCR5_SYN(v)   (((v) << BP_AUDMUX_PTCR5_SYN) & BM_AUDMUX_PTCR5_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR5_SYN(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_SYN) | BF_AUDMUX_PTCR5_SYN(v)))
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

#define BP_AUDMUX_PTCR5_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR5_RCSEL.
#define BM_AUDMUX_PTCR5_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR5_RCSEL.

//! @brief Get value of AUDMUX_PTCR5_RCSEL from a register value.
#define BG_AUDMUX_PTCR5_RCSEL(r)   (((r) & BM_AUDMUX_PTCR5_RCSEL) >> BP_AUDMUX_PTCR5_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_RCSEL.
#define BF_AUDMUX_PTCR5_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_RCSEL) & BM_AUDMUX_PTCR5_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_RCSEL.
#define BF_AUDMUX_PTCR5_RCSEL(v)   (((v) << BP_AUDMUX_PTCR5_RCSEL) & BM_AUDMUX_PTCR5_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR5_RCSEL(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_RCSEL) | BF_AUDMUX_PTCR5_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR5, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR5_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR5_RCLKDIR.
#define BM_AUDMUX_PTCR5_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR5_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR5_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR5_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR5_RCLKDIR) >> BP_AUDMUX_PTCR5_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_RCLKDIR.
#define BF_AUDMUX_PTCR5_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_RCLKDIR) & BM_AUDMUX_PTCR5_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_RCLKDIR.
#define BF_AUDMUX_PTCR5_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR5_RCLKDIR) & BM_AUDMUX_PTCR5_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR5_RCLKDIR(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_RCLKDIR) | BF_AUDMUX_PTCR5_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR5_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR5_RFSEL.
#define BM_AUDMUX_PTCR5_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR5_RFSEL.

//! @brief Get value of AUDMUX_PTCR5_RFSEL from a register value.
#define BG_AUDMUX_PTCR5_RFSEL(r)   (((r) & BM_AUDMUX_PTCR5_RFSEL) >> BP_AUDMUX_PTCR5_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_RFSEL.
#define BF_AUDMUX_PTCR5_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_RFSEL) & BM_AUDMUX_PTCR5_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_RFSEL.
#define BF_AUDMUX_PTCR5_RFSEL(v)   (((v) << BP_AUDMUX_PTCR5_RFSEL) & BM_AUDMUX_PTCR5_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR5_RFSEL(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_RFSEL) | BF_AUDMUX_PTCR5_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR5, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR5_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR5_RFS_DIR.
#define BM_AUDMUX_PTCR5_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR5_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR5_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR5_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR5_RFS_DIR) >> BP_AUDMUX_PTCR5_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_RFS_DIR.
#define BF_AUDMUX_PTCR5_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_RFS_DIR) & BM_AUDMUX_PTCR5_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_RFS_DIR.
#define BF_AUDMUX_PTCR5_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR5_RFS_DIR) & BM_AUDMUX_PTCR5_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR5_RFS_DIR(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_RFS_DIR) | BF_AUDMUX_PTCR5_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR5_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR5_TCSEL.
#define BM_AUDMUX_PTCR5_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR5_TCSEL.

//! @brief Get value of AUDMUX_PTCR5_TCSEL from a register value.
#define BG_AUDMUX_PTCR5_TCSEL(r)   (((r) & BM_AUDMUX_PTCR5_TCSEL) >> BP_AUDMUX_PTCR5_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_TCSEL.
#define BF_AUDMUX_PTCR5_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_TCSEL) & BM_AUDMUX_PTCR5_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_TCSEL.
#define BF_AUDMUX_PTCR5_TCSEL(v)   (((v) << BP_AUDMUX_PTCR5_TCSEL) & BM_AUDMUX_PTCR5_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR5_TCSEL(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_TCSEL) | BF_AUDMUX_PTCR5_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR5, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR5_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR5_TCLKDIR.
#define BM_AUDMUX_PTCR5_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR5_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR5_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR5_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR5_TCLKDIR) >> BP_AUDMUX_PTCR5_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_TCLKDIR.
#define BF_AUDMUX_PTCR5_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_TCLKDIR) & BM_AUDMUX_PTCR5_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_TCLKDIR.
#define BF_AUDMUX_PTCR5_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR5_TCLKDIR) & BM_AUDMUX_PTCR5_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR5_TCLKDIR(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_TCLKDIR) | BF_AUDMUX_PTCR5_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR5_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR5_TFSEL.
#define BM_AUDMUX_PTCR5_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR5_TFSEL.

//! @brief Get value of AUDMUX_PTCR5_TFSEL from a register value.
#define BG_AUDMUX_PTCR5_TFSEL(r)   (((r) & BM_AUDMUX_PTCR5_TFSEL) >> BP_AUDMUX_PTCR5_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_TFSEL.
#define BF_AUDMUX_PTCR5_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_TFSEL) & BM_AUDMUX_PTCR5_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_TFSEL.
#define BF_AUDMUX_PTCR5_TFSEL(v)   (((v) << BP_AUDMUX_PTCR5_TFSEL) & BM_AUDMUX_PTCR5_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR5_TFSEL(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_TFSEL) | BF_AUDMUX_PTCR5_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR5, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR5_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR5_TFS_DIR.
#define BM_AUDMUX_PTCR5_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR5_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR5_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR5_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR5_TFS_DIR) >> BP_AUDMUX_PTCR5_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR5_TFS_DIR.
#define BF_AUDMUX_PTCR5_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR5_TFS_DIR) & BM_AUDMUX_PTCR5_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR5_TFS_DIR.
#define BF_AUDMUX_PTCR5_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR5_TFS_DIR) & BM_AUDMUX_PTCR5_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR5_TFS_DIR(v)   (HW_AUDMUX_PTCR5_WR((HW_AUDMUX_PTCR5_RD() & ~BM_AUDMUX_PTCR5_TFS_DIR) | BF_AUDMUX_PTCR5_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR5 - Port Data Control Register 5 (RW)
 *
 * Reset value: 0x00002000
 *
 * PDCR5 is the Port Data Control Register for Port 5.
 */
typedef union _hw_audmux_pdcr5
{
    reg32_t U;
    struct _hw_audmux_pdcr5_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR5_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR5_INMMASK.
#define BM_AUDMUX_PDCR5_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR5_INMMASK.

//! @brief Get value of AUDMUX_PDCR5_INMMASK from a register value.
#define BG_AUDMUX_PDCR5_INMMASK(r)   (((r) & BM_AUDMUX_PDCR5_INMMASK) >> BP_AUDMUX_PDCR5_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR5_INMMASK.
#define BF_AUDMUX_PDCR5_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR5_INMMASK) & BM_AUDMUX_PDCR5_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR5_INMMASK.
#define BF_AUDMUX_PDCR5_INMMASK(v)   (((v) << BP_AUDMUX_PDCR5_INMMASK) & BM_AUDMUX_PDCR5_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR5_INMMASK(v)   (HW_AUDMUX_PDCR5_WR((HW_AUDMUX_PDCR5_RD() & ~BM_AUDMUX_PDCR5_INMMASK) | BF_AUDMUX_PDCR5_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR5, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR5_MODE      (8)      //!< Bit position for AUDMUX_PDCR5_MODE.
#define BM_AUDMUX_PDCR5_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR5_MODE.

//! @brief Get value of AUDMUX_PDCR5_MODE from a register value.
#define BG_AUDMUX_PDCR5_MODE(r)   (((r) & BM_AUDMUX_PDCR5_MODE) >> BP_AUDMUX_PDCR5_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR5_MODE.
#define BF_AUDMUX_PDCR5_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR5_MODE) & BM_AUDMUX_PDCR5_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR5_MODE.
#define BF_AUDMUX_PDCR5_MODE(v)   (((v) << BP_AUDMUX_PDCR5_MODE) & BM_AUDMUX_PDCR5_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR5_MODE(v)   (HW_AUDMUX_PDCR5_WR((HW_AUDMUX_PDCR5_RD() & ~BM_AUDMUX_PDCR5_MODE) | BF_AUDMUX_PDCR5_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR5, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR5_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR5_TXRXEN.
#define BM_AUDMUX_PDCR5_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR5_TXRXEN.

//! @brief Get value of AUDMUX_PDCR5_TXRXEN from a register value.
#define BG_AUDMUX_PDCR5_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR5_TXRXEN) >> BP_AUDMUX_PDCR5_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR5_TXRXEN.
#define BF_AUDMUX_PDCR5_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR5_TXRXEN) & BM_AUDMUX_PDCR5_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR5_TXRXEN.
#define BF_AUDMUX_PDCR5_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR5_TXRXEN) & BM_AUDMUX_PDCR5_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR5_TXRXEN(v)   (HW_AUDMUX_PDCR5_WR((HW_AUDMUX_PDCR5_RD() & ~BM_AUDMUX_PDCR5_TXRXEN) | BF_AUDMUX_PDCR5_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR5_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR5_RXDSEL.
#define BM_AUDMUX_PDCR5_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR5_RXDSEL.

//! @brief Get value of AUDMUX_PDCR5_RXDSEL from a register value.
#define BG_AUDMUX_PDCR5_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR5_RXDSEL) >> BP_AUDMUX_PDCR5_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR5_RXDSEL.
#define BF_AUDMUX_PDCR5_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR5_RXDSEL) & BM_AUDMUX_PDCR5_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR5_RXDSEL.
#define BF_AUDMUX_PDCR5_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR5_RXDSEL) & BM_AUDMUX_PDCR5_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR5_RXDSEL(v)   (HW_AUDMUX_PDCR5_WR((HW_AUDMUX_PDCR5_RD() & ~BM_AUDMUX_PDCR5_RXDSEL) | BF_AUDMUX_PDCR5_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR6 - Port Timing Control Register n (RW)
 *
 * Reset value: 0x00000800
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union _hw_audmux_ptcr6
{
    reg32_t U;
    struct _hw_audmux_ptcr6_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR6, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR6_SYN      (11)      //!< Bit position for AUDMUX_PTCR6_SYN.
#define BM_AUDMUX_PTCR6_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR6_SYN.

//! @brief Get value of AUDMUX_PTCR6_SYN from a register value.
#define BG_AUDMUX_PTCR6_SYN(r)   (((r) & BM_AUDMUX_PTCR6_SYN) >> BP_AUDMUX_PTCR6_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_SYN.
#define BF_AUDMUX_PTCR6_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_SYN) & BM_AUDMUX_PTCR6_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_SYN.
#define BF_AUDMUX_PTCR6_SYN(v)   (((v) << BP_AUDMUX_PTCR6_SYN) & BM_AUDMUX_PTCR6_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR6_SYN(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_SYN) | BF_AUDMUX_PTCR6_SYN(v)))
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

#define BP_AUDMUX_PTCR6_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR6_RCSEL.
#define BM_AUDMUX_PTCR6_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR6_RCSEL.

//! @brief Get value of AUDMUX_PTCR6_RCSEL from a register value.
#define BG_AUDMUX_PTCR6_RCSEL(r)   (((r) & BM_AUDMUX_PTCR6_RCSEL) >> BP_AUDMUX_PTCR6_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_RCSEL.
#define BF_AUDMUX_PTCR6_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_RCSEL) & BM_AUDMUX_PTCR6_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_RCSEL.
#define BF_AUDMUX_PTCR6_RCSEL(v)   (((v) << BP_AUDMUX_PTCR6_RCSEL) & BM_AUDMUX_PTCR6_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR6_RCSEL(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_RCSEL) | BF_AUDMUX_PTCR6_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR6, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR6_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR6_RCLKDIR.
#define BM_AUDMUX_PTCR6_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR6_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR6_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR6_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR6_RCLKDIR) >> BP_AUDMUX_PTCR6_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_RCLKDIR.
#define BF_AUDMUX_PTCR6_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_RCLKDIR) & BM_AUDMUX_PTCR6_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_RCLKDIR.
#define BF_AUDMUX_PTCR6_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR6_RCLKDIR) & BM_AUDMUX_PTCR6_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR6_RCLKDIR(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_RCLKDIR) | BF_AUDMUX_PTCR6_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR6_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR6_RFSEL.
#define BM_AUDMUX_PTCR6_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR6_RFSEL.

//! @brief Get value of AUDMUX_PTCR6_RFSEL from a register value.
#define BG_AUDMUX_PTCR6_RFSEL(r)   (((r) & BM_AUDMUX_PTCR6_RFSEL) >> BP_AUDMUX_PTCR6_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_RFSEL.
#define BF_AUDMUX_PTCR6_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_RFSEL) & BM_AUDMUX_PTCR6_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_RFSEL.
#define BF_AUDMUX_PTCR6_RFSEL(v)   (((v) << BP_AUDMUX_PTCR6_RFSEL) & BM_AUDMUX_PTCR6_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR6_RFSEL(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_RFSEL) | BF_AUDMUX_PTCR6_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR6, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR6_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR6_RFS_DIR.
#define BM_AUDMUX_PTCR6_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR6_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR6_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR6_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR6_RFS_DIR) >> BP_AUDMUX_PTCR6_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_RFS_DIR.
#define BF_AUDMUX_PTCR6_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_RFS_DIR) & BM_AUDMUX_PTCR6_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_RFS_DIR.
#define BF_AUDMUX_PTCR6_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR6_RFS_DIR) & BM_AUDMUX_PTCR6_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR6_RFS_DIR(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_RFS_DIR) | BF_AUDMUX_PTCR6_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR6_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR6_TCSEL.
#define BM_AUDMUX_PTCR6_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR6_TCSEL.

//! @brief Get value of AUDMUX_PTCR6_TCSEL from a register value.
#define BG_AUDMUX_PTCR6_TCSEL(r)   (((r) & BM_AUDMUX_PTCR6_TCSEL) >> BP_AUDMUX_PTCR6_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_TCSEL.
#define BF_AUDMUX_PTCR6_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_TCSEL) & BM_AUDMUX_PTCR6_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_TCSEL.
#define BF_AUDMUX_PTCR6_TCSEL(v)   (((v) << BP_AUDMUX_PTCR6_TCSEL) & BM_AUDMUX_PTCR6_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR6_TCSEL(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_TCSEL) | BF_AUDMUX_PTCR6_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR6, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR6_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR6_TCLKDIR.
#define BM_AUDMUX_PTCR6_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR6_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR6_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR6_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR6_TCLKDIR) >> BP_AUDMUX_PTCR6_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_TCLKDIR.
#define BF_AUDMUX_PTCR6_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_TCLKDIR) & BM_AUDMUX_PTCR6_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_TCLKDIR.
#define BF_AUDMUX_PTCR6_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR6_TCLKDIR) & BM_AUDMUX_PTCR6_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR6_TCLKDIR(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_TCLKDIR) | BF_AUDMUX_PTCR6_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR6_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR6_TFSEL.
#define BM_AUDMUX_PTCR6_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR6_TFSEL.

//! @brief Get value of AUDMUX_PTCR6_TFSEL from a register value.
#define BG_AUDMUX_PTCR6_TFSEL(r)   (((r) & BM_AUDMUX_PTCR6_TFSEL) >> BP_AUDMUX_PTCR6_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_TFSEL.
#define BF_AUDMUX_PTCR6_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_TFSEL) & BM_AUDMUX_PTCR6_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_TFSEL.
#define BF_AUDMUX_PTCR6_TFSEL(v)   (((v) << BP_AUDMUX_PTCR6_TFSEL) & BM_AUDMUX_PTCR6_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR6_TFSEL(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_TFSEL) | BF_AUDMUX_PTCR6_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR6, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR6_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR6_TFS_DIR.
#define BM_AUDMUX_PTCR6_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR6_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR6_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR6_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR6_TFS_DIR) >> BP_AUDMUX_PTCR6_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR6_TFS_DIR.
#define BF_AUDMUX_PTCR6_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR6_TFS_DIR) & BM_AUDMUX_PTCR6_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR6_TFS_DIR.
#define BF_AUDMUX_PTCR6_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR6_TFS_DIR) & BM_AUDMUX_PTCR6_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR6_TFS_DIR(v)   (HW_AUDMUX_PTCR6_WR((HW_AUDMUX_PTCR6_RD() & ~BM_AUDMUX_PTCR6_TFS_DIR) | BF_AUDMUX_PTCR6_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR6 - Port Data Control Register 6 (RW)
 *
 * Reset value: 0x00000000
 *
 * PDCR6 is the Port Data Control Register for Port 6.
 */
typedef union _hw_audmux_pdcr6
{
    reg32_t U;
    struct _hw_audmux_pdcr6_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 5 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR6_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR6_INMMASK.
#define BM_AUDMUX_PDCR6_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR6_INMMASK.

//! @brief Get value of AUDMUX_PDCR6_INMMASK from a register value.
#define BG_AUDMUX_PDCR6_INMMASK(r)   (((r) & BM_AUDMUX_PDCR6_INMMASK) >> BP_AUDMUX_PDCR6_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR6_INMMASK.
#define BF_AUDMUX_PDCR6_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR6_INMMASK) & BM_AUDMUX_PDCR6_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR6_INMMASK.
#define BF_AUDMUX_PDCR6_INMMASK(v)   (((v) << BP_AUDMUX_PDCR6_INMMASK) & BM_AUDMUX_PDCR6_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR6_INMMASK(v)   (HW_AUDMUX_PDCR6_WR((HW_AUDMUX_PDCR6_RD() & ~BM_AUDMUX_PDCR6_INMMASK) | BF_AUDMUX_PDCR6_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR6, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR6_MODE      (8)      //!< Bit position for AUDMUX_PDCR6_MODE.
#define BM_AUDMUX_PDCR6_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR6_MODE.

//! @brief Get value of AUDMUX_PDCR6_MODE from a register value.
#define BG_AUDMUX_PDCR6_MODE(r)   (((r) & BM_AUDMUX_PDCR6_MODE) >> BP_AUDMUX_PDCR6_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR6_MODE.
#define BF_AUDMUX_PDCR6_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR6_MODE) & BM_AUDMUX_PDCR6_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR6_MODE.
#define BF_AUDMUX_PDCR6_MODE(v)   (((v) << BP_AUDMUX_PDCR6_MODE) & BM_AUDMUX_PDCR6_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR6_MODE(v)   (HW_AUDMUX_PDCR6_WR((HW_AUDMUX_PDCR6_RD() & ~BM_AUDMUX_PDCR6_MODE) | BF_AUDMUX_PDCR6_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR6, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR6_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR6_TXRXEN.
#define BM_AUDMUX_PDCR6_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR6_TXRXEN.

//! @brief Get value of AUDMUX_PDCR6_TXRXEN from a register value.
#define BG_AUDMUX_PDCR6_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR6_TXRXEN) >> BP_AUDMUX_PDCR6_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR6_TXRXEN.
#define BF_AUDMUX_PDCR6_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR6_TXRXEN) & BM_AUDMUX_PDCR6_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR6_TXRXEN.
#define BF_AUDMUX_PDCR6_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR6_TXRXEN) & BM_AUDMUX_PDCR6_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR6_TXRXEN(v)   (HW_AUDMUX_PDCR6_WR((HW_AUDMUX_PDCR6_RD() & ~BM_AUDMUX_PDCR6_TXRXEN) | BF_AUDMUX_PDCR6_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR6_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR6_RXDSEL.
#define BM_AUDMUX_PDCR6_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR6_RXDSEL.

//! @brief Get value of AUDMUX_PDCR6_RXDSEL from a register value.
#define BG_AUDMUX_PDCR6_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR6_RXDSEL) >> BP_AUDMUX_PDCR6_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR6_RXDSEL.
#define BF_AUDMUX_PDCR6_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR6_RXDSEL) & BM_AUDMUX_PDCR6_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR6_RXDSEL.
#define BF_AUDMUX_PDCR6_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR6_RXDSEL) & BM_AUDMUX_PDCR6_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR6_RXDSEL(v)   (HW_AUDMUX_PDCR6_WR((HW_AUDMUX_PDCR6_RD() & ~BM_AUDMUX_PDCR6_RXDSEL) | BF_AUDMUX_PDCR6_RXDSEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PTCR7 - Port Timing Control Register n (RW)
 *
 * Reset value: 0x00000800
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
typedef union _hw_audmux_ptcr7
{
    reg32_t U;
    struct _hw_audmux_ptcr7_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned SYN : 1; //!< [11] Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface). RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< [15:12] Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< [16] Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< [20:17] Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< [21] Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< [25:22] Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< [26] Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< [30:27] Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< [31] Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
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

/* --- Register HW_AUDMUX_PTCR7, field SYN[11] (RW)
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

#define BP_AUDMUX_PTCR7_SYN      (11)      //!< Bit position for AUDMUX_PTCR7_SYN.
#define BM_AUDMUX_PTCR7_SYN      (0x00000800)  //!< Bit mask for AUDMUX_PTCR7_SYN.

//! @brief Get value of AUDMUX_PTCR7_SYN from a register value.
#define BG_AUDMUX_PTCR7_SYN(r)   (((r) & BM_AUDMUX_PTCR7_SYN) >> BP_AUDMUX_PTCR7_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_SYN.
#define BF_AUDMUX_PTCR7_SYN(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_SYN) & BM_AUDMUX_PTCR7_SYN)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_SYN.
#define BF_AUDMUX_PTCR7_SYN(v)   (((v) << BP_AUDMUX_PTCR7_SYN) & BM_AUDMUX_PTCR7_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_AUDMUX_PTCR7_SYN(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_SYN) | BF_AUDMUX_PTCR7_SYN(v)))
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

#define BP_AUDMUX_PTCR7_RCSEL      (12)      //!< Bit position for AUDMUX_PTCR7_RCSEL.
#define BM_AUDMUX_PTCR7_RCSEL      (0x0000f000)  //!< Bit mask for AUDMUX_PTCR7_RCSEL.

//! @brief Get value of AUDMUX_PTCR7_RCSEL from a register value.
#define BG_AUDMUX_PTCR7_RCSEL(r)   (((r) & BM_AUDMUX_PTCR7_RCSEL) >> BP_AUDMUX_PTCR7_RCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_RCSEL.
#define BF_AUDMUX_PTCR7_RCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_RCSEL) & BM_AUDMUX_PTCR7_RCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_RCSEL.
#define BF_AUDMUX_PTCR7_RCSEL(v)   (((v) << BP_AUDMUX_PTCR7_RCSEL) & BM_AUDMUX_PTCR7_RCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSEL field to a new value.
#define BW_AUDMUX_PTCR7_RCSEL(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_RCSEL) | BF_AUDMUX_PTCR7_RCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR7, field RCLKDIR[16] (RW)
 *
 * Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as
 * an output or input. When set as an input, the RCSEL settings are ignored. When set as an output,
 * the RCSEL settings determine the source port of the clock. RCLKDIR and SYN should not be changed
 * at the same time.
 *
 * Values:
 * 0 - RxClk is an input. 1 RxClk is an output.
 */

#define BP_AUDMUX_PTCR7_RCLKDIR      (16)      //!< Bit position for AUDMUX_PTCR7_RCLKDIR.
#define BM_AUDMUX_PTCR7_RCLKDIR      (0x00010000)  //!< Bit mask for AUDMUX_PTCR7_RCLKDIR.

//! @brief Get value of AUDMUX_PTCR7_RCLKDIR from a register value.
#define BG_AUDMUX_PTCR7_RCLKDIR(r)   (((r) & BM_AUDMUX_PTCR7_RCLKDIR) >> BP_AUDMUX_PTCR7_RCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_RCLKDIR.
#define BF_AUDMUX_PTCR7_RCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_RCLKDIR) & BM_AUDMUX_PTCR7_RCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_RCLKDIR.
#define BF_AUDMUX_PTCR7_RCLKDIR(v)   (((v) << BP_AUDMUX_PTCR7_RCLKDIR) & BM_AUDMUX_PTCR7_RCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCLKDIR field to a new value.
#define BW_AUDMUX_PTCR7_RCLKDIR(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_RCLKDIR) | BF_AUDMUX_PTCR7_RCLKDIR(v)))
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

#define BP_AUDMUX_PTCR7_RFSEL      (17)      //!< Bit position for AUDMUX_PTCR7_RFSEL.
#define BM_AUDMUX_PTCR7_RFSEL      (0x001e0000)  //!< Bit mask for AUDMUX_PTCR7_RFSEL.

//! @brief Get value of AUDMUX_PTCR7_RFSEL from a register value.
#define BG_AUDMUX_PTCR7_RFSEL(r)   (((r) & BM_AUDMUX_PTCR7_RFSEL) >> BP_AUDMUX_PTCR7_RFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_RFSEL.
#define BF_AUDMUX_PTCR7_RFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_RFSEL) & BM_AUDMUX_PTCR7_RFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_RFSEL.
#define BF_AUDMUX_PTCR7_RFSEL(v)   (((v) << BP_AUDMUX_PTCR7_RFSEL) & BM_AUDMUX_PTCR7_RFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSEL field to a new value.
#define BW_AUDMUX_PTCR7_RFSEL(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_RFSEL) | BF_AUDMUX_PTCR7_RFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR7, field RFS_DIR[21] (RW)
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the
 * interface as an output or input. When set as an input, the RFSEL settings are ignored. When set
 * as an output, the RFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - RxFS is an input.
 * 1 - RxFS is an output.
 */

#define BP_AUDMUX_PTCR7_RFS_DIR      (21)      //!< Bit position for AUDMUX_PTCR7_RFS_DIR.
#define BM_AUDMUX_PTCR7_RFS_DIR      (0x00200000)  //!< Bit mask for AUDMUX_PTCR7_RFS_DIR.

//! @brief Get value of AUDMUX_PTCR7_RFS_DIR from a register value.
#define BG_AUDMUX_PTCR7_RFS_DIR(r)   (((r) & BM_AUDMUX_PTCR7_RFS_DIR) >> BP_AUDMUX_PTCR7_RFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_RFS_DIR.
#define BF_AUDMUX_PTCR7_RFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_RFS_DIR) & BM_AUDMUX_PTCR7_RFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_RFS_DIR.
#define BF_AUDMUX_PTCR7_RFS_DIR(v)   (((v) << BP_AUDMUX_PTCR7_RFS_DIR) & BM_AUDMUX_PTCR7_RFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFS_DIR field to a new value.
#define BW_AUDMUX_PTCR7_RFS_DIR(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_RFS_DIR) | BF_AUDMUX_PTCR7_RFS_DIR(v)))
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

#define BP_AUDMUX_PTCR7_TCSEL      (22)      //!< Bit position for AUDMUX_PTCR7_TCSEL.
#define BM_AUDMUX_PTCR7_TCSEL      (0x03c00000)  //!< Bit mask for AUDMUX_PTCR7_TCSEL.

//! @brief Get value of AUDMUX_PTCR7_TCSEL from a register value.
#define BG_AUDMUX_PTCR7_TCSEL(r)   (((r) & BM_AUDMUX_PTCR7_TCSEL) >> BP_AUDMUX_PTCR7_TCSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_TCSEL.
#define BF_AUDMUX_PTCR7_TCSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_TCSEL) & BM_AUDMUX_PTCR7_TCSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_TCSEL.
#define BF_AUDMUX_PTCR7_TCSEL(v)   (((v) << BP_AUDMUX_PTCR7_TCSEL) & BM_AUDMUX_PTCR7_TCSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCSEL field to a new value.
#define BW_AUDMUX_PTCR7_TCSEL(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_TCSEL) | BF_AUDMUX_PTCR7_TCSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR7, field TCLKDIR[26] (RW)
 *
 * Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface
 * as an output or input. When set as an input, the TCSEL settings are ignored. When set as an
 * output, the TCSEL settings determine the source port of the clock.
 *
 * Values:
 * 0 - TxClk is an input.
 * 1 - TxClk is an output.
 */

#define BP_AUDMUX_PTCR7_TCLKDIR      (26)      //!< Bit position for AUDMUX_PTCR7_TCLKDIR.
#define BM_AUDMUX_PTCR7_TCLKDIR      (0x04000000)  //!< Bit mask for AUDMUX_PTCR7_TCLKDIR.

//! @brief Get value of AUDMUX_PTCR7_TCLKDIR from a register value.
#define BG_AUDMUX_PTCR7_TCLKDIR(r)   (((r) & BM_AUDMUX_PTCR7_TCLKDIR) >> BP_AUDMUX_PTCR7_TCLKDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_TCLKDIR.
#define BF_AUDMUX_PTCR7_TCLKDIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_TCLKDIR) & BM_AUDMUX_PTCR7_TCLKDIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_TCLKDIR.
#define BF_AUDMUX_PTCR7_TCLKDIR(v)   (((v) << BP_AUDMUX_PTCR7_TCLKDIR) & BM_AUDMUX_PTCR7_TCLKDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCLKDIR field to a new value.
#define BW_AUDMUX_PTCR7_TCLKDIR(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_TCLKDIR) | BF_AUDMUX_PTCR7_TCLKDIR(v)))
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

#define BP_AUDMUX_PTCR7_TFSEL      (27)      //!< Bit position for AUDMUX_PTCR7_TFSEL.
#define BM_AUDMUX_PTCR7_TFSEL      (0x78000000)  //!< Bit mask for AUDMUX_PTCR7_TFSEL.

//! @brief Get value of AUDMUX_PTCR7_TFSEL from a register value.
#define BG_AUDMUX_PTCR7_TFSEL(r)   (((r) & BM_AUDMUX_PTCR7_TFSEL) >> BP_AUDMUX_PTCR7_TFSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_TFSEL.
#define BF_AUDMUX_PTCR7_TFSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_TFSEL) & BM_AUDMUX_PTCR7_TFSEL)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_TFSEL.
#define BF_AUDMUX_PTCR7_TFSEL(v)   (((v) << BP_AUDMUX_PTCR7_TFSEL) & BM_AUDMUX_PTCR7_TFSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSEL field to a new value.
#define BW_AUDMUX_PTCR7_TFSEL(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_TFSEL) | BF_AUDMUX_PTCR7_TFSEL(v)))
#endif


/* --- Register HW_AUDMUX_PTCR7, field TFS_DIR[31] (RW)
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the
 * interface as an output or input. When set as an input, the TFSEL settings are ignored. When set
 * as an output, the TFSEL settings determine the source port of the frame sync.
 *
 * Values:
 * 0 - TxFS is an input.
 * 1 - TxFS is an output.
 */

#define BP_AUDMUX_PTCR7_TFS_DIR      (31)      //!< Bit position for AUDMUX_PTCR7_TFS_DIR.
#define BM_AUDMUX_PTCR7_TFS_DIR      (0x80000000)  //!< Bit mask for AUDMUX_PTCR7_TFS_DIR.

//! @brief Get value of AUDMUX_PTCR7_TFS_DIR from a register value.
#define BG_AUDMUX_PTCR7_TFS_DIR(r)   (((r) & BM_AUDMUX_PTCR7_TFS_DIR) >> BP_AUDMUX_PTCR7_TFS_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PTCR7_TFS_DIR.
#define BF_AUDMUX_PTCR7_TFS_DIR(v)   ((((reg32_t) v) << BP_AUDMUX_PTCR7_TFS_DIR) & BM_AUDMUX_PTCR7_TFS_DIR)
#else
//! @brief Format value for bitfield AUDMUX_PTCR7_TFS_DIR.
#define BF_AUDMUX_PTCR7_TFS_DIR(v)   (((v) << BP_AUDMUX_PTCR7_TFS_DIR) & BM_AUDMUX_PTCR7_TFS_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFS_DIR field to a new value.
#define BW_AUDMUX_PTCR7_TFS_DIR(v)   (HW_AUDMUX_PTCR7_WR((HW_AUDMUX_PTCR7_RD() & ~BM_AUDMUX_PTCR7_TFS_DIR) | BF_AUDMUX_PTCR7_TFS_DIR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AUDMUX_PDCR7 - Port Data Control Register 7 (RW)
 *
 * Reset value: 0x0000c000
 *
 * PDCR7 PDCR6 is the Port Data Control Register for Port 7 Port 6 .
 */
typedef union _hw_audmux_pdcr7
{
    reg32_t U;
    struct _hw_audmux_pdcr7_bitfields
    {
        unsigned INMMASK : 8; //!< [7:0] Internal Network Mode Mask. Bit mask that selects the ports from which the RxD signals are to be ANDed together for internal network mode. Bit 6 represents RxD from Port 7 Port 6 and bit0 represents RxD from Port 1.
        unsigned MODE : 1; //!< [8] Mode Select. This field selects the mode in which the port is to operate. The modes of operation include the following: Normal mode, in which the RxD from the port selected by RXDSEL is routed to the port. Internal Network mode in which RxD from other ports are ANDed together. RXDSEL is ignored. INMMASK determines which RxD signals are ANDed together.
        unsigned RESERVED0 : 3; //!< [11:9] Reserved
        unsigned TXRXEN : 1; //!< [12] Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
        unsigned RXDSEL : 3; //!< [15:13] Receive Data Select. Selects the source port for the RxD data. RXDSEL is ignored if MODE = 0 1 (that is, Internal Network Mode is enabled).
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

#define BP_AUDMUX_PDCR7_INMMASK      (0)      //!< Bit position for AUDMUX_PDCR7_INMMASK.
#define BM_AUDMUX_PDCR7_INMMASK      (0x000000ff)  //!< Bit mask for AUDMUX_PDCR7_INMMASK.

//! @brief Get value of AUDMUX_PDCR7_INMMASK from a register value.
#define BG_AUDMUX_PDCR7_INMMASK(r)   (((r) & BM_AUDMUX_PDCR7_INMMASK) >> BP_AUDMUX_PDCR7_INMMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR7_INMMASK.
#define BF_AUDMUX_PDCR7_INMMASK(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR7_INMMASK) & BM_AUDMUX_PDCR7_INMMASK)
#else
//! @brief Format value for bitfield AUDMUX_PDCR7_INMMASK.
#define BF_AUDMUX_PDCR7_INMMASK(v)   (((v) << BP_AUDMUX_PDCR7_INMMASK) & BM_AUDMUX_PDCR7_INMMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INMMASK field to a new value.
#define BW_AUDMUX_PDCR7_INMMASK(v)   (HW_AUDMUX_PDCR7_WR((HW_AUDMUX_PDCR7_RD() & ~BM_AUDMUX_PDCR7_INMMASK) | BF_AUDMUX_PDCR7_INMMASK(v)))
#endif


/* --- Register HW_AUDMUX_PDCR7, field MODE[8] (RW)
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

#define BP_AUDMUX_PDCR7_MODE      (8)      //!< Bit position for AUDMUX_PDCR7_MODE.
#define BM_AUDMUX_PDCR7_MODE      (0x00000100)  //!< Bit mask for AUDMUX_PDCR7_MODE.

//! @brief Get value of AUDMUX_PDCR7_MODE from a register value.
#define BG_AUDMUX_PDCR7_MODE(r)   (((r) & BM_AUDMUX_PDCR7_MODE) >> BP_AUDMUX_PDCR7_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR7_MODE.
#define BF_AUDMUX_PDCR7_MODE(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR7_MODE) & BM_AUDMUX_PDCR7_MODE)
#else
//! @brief Format value for bitfield AUDMUX_PDCR7_MODE.
#define BF_AUDMUX_PDCR7_MODE(v)   (((v) << BP_AUDMUX_PDCR7_MODE) & BM_AUDMUX_PDCR7_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_AUDMUX_PDCR7_MODE(v)   (HW_AUDMUX_PDCR7_WR((HW_AUDMUX_PDCR7_RD() & ~BM_AUDMUX_PDCR7_MODE) | BF_AUDMUX_PDCR7_MODE(v)))
#endif


/* --- Register HW_AUDMUX_PDCR7, field TXRXEN[12] (RW)
 *
 * Transmit/Receive Switch Enable. Swaps the transmit and receive signals.
 *
 * Values:
 * 0 - No switch (Transmit Pin = Transmit, Receive Pin = Receive)
 * 1 - Switch (Transmit Pin = Receive, Receive Pin = Transmit)
 */

#define BP_AUDMUX_PDCR7_TXRXEN      (12)      //!< Bit position for AUDMUX_PDCR7_TXRXEN.
#define BM_AUDMUX_PDCR7_TXRXEN      (0x00001000)  //!< Bit mask for AUDMUX_PDCR7_TXRXEN.

//! @brief Get value of AUDMUX_PDCR7_TXRXEN from a register value.
#define BG_AUDMUX_PDCR7_TXRXEN(r)   (((r) & BM_AUDMUX_PDCR7_TXRXEN) >> BP_AUDMUX_PDCR7_TXRXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR7_TXRXEN.
#define BF_AUDMUX_PDCR7_TXRXEN(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR7_TXRXEN) & BM_AUDMUX_PDCR7_TXRXEN)
#else
//! @brief Format value for bitfield AUDMUX_PDCR7_TXRXEN.
#define BF_AUDMUX_PDCR7_TXRXEN(v)   (((v) << BP_AUDMUX_PDCR7_TXRXEN) & BM_AUDMUX_PDCR7_TXRXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXRXEN field to a new value.
#define BW_AUDMUX_PDCR7_TXRXEN(v)   (HW_AUDMUX_PDCR7_WR((HW_AUDMUX_PDCR7_RD() & ~BM_AUDMUX_PDCR7_TXRXEN) | BF_AUDMUX_PDCR7_TXRXEN(v)))
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

#define BP_AUDMUX_PDCR7_RXDSEL      (13)      //!< Bit position for AUDMUX_PDCR7_RXDSEL.
#define BM_AUDMUX_PDCR7_RXDSEL      (0x0000e000)  //!< Bit mask for AUDMUX_PDCR7_RXDSEL.

//! @brief Get value of AUDMUX_PDCR7_RXDSEL from a register value.
#define BG_AUDMUX_PDCR7_RXDSEL(r)   (((r) & BM_AUDMUX_PDCR7_RXDSEL) >> BP_AUDMUX_PDCR7_RXDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield AUDMUX_PDCR7_RXDSEL.
#define BF_AUDMUX_PDCR7_RXDSEL(v)   ((((reg32_t) v) << BP_AUDMUX_PDCR7_RXDSEL) & BM_AUDMUX_PDCR7_RXDSEL)
#else
//! @brief Format value for bitfield AUDMUX_PDCR7_RXDSEL.
#define BF_AUDMUX_PDCR7_RXDSEL(v)   (((v) << BP_AUDMUX_PDCR7_RXDSEL) & BM_AUDMUX_PDCR7_RXDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEL field to a new value.
#define BW_AUDMUX_PDCR7_RXDSEL(v)   (HW_AUDMUX_PDCR7_WR((HW_AUDMUX_PDCR7_RD() & ~BM_AUDMUX_PDCR7_RXDSEL) | BF_AUDMUX_PDCR7_RXDSEL(v)))
#endif



/*!
 * @brief All AUDMUX module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_audmux
{
    volatile hw_audmux_ptcr1_t PTCR1; //!< Port Timing Control Register 1
    volatile hw_audmux_pdcr1_t PDCR1; //!< Port Data Control Register 1
    volatile hw_audmux_ptcr2_t PTCR2; //!< Port Timing Control Register 2
    volatile hw_audmux_pdcr2_t PDCR2; //!< Port Data Control Register 2
    volatile hw_audmux_ptcr3_t PTCR3; //!< Port Timing Control Register 3
    volatile hw_audmux_pdcr3_t PDCR3; //!< Port Data Control Register 3
    volatile hw_audmux_ptcr4_t PTCR4; //!< Port Timing Control Register n
    volatile hw_audmux_pdcr4_t PDCR4; //!< Port Data Control Register 4
    volatile hw_audmux_ptcr5_t PTCR5; //!< Port Timing Control Register n
    volatile hw_audmux_pdcr5_t PDCR5; //!< Port Data Control Register 5
    volatile hw_audmux_ptcr6_t PTCR6; //!< Port Timing Control Register n
    volatile hw_audmux_pdcr6_t PDCR6; //!< Port Data Control Register 6
    volatile hw_audmux_ptcr7_t PTCR7; //!< Port Timing Control Register n
    volatile hw_audmux_pdcr7_t PDCR7; //!< Port Data Control Register 7
} hw_audmux_t;
#pragma pack()

//! @brief Macro to access all AUDMUX registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_AUDMUX(0)</code>.
#define HW_AUDMUX     (*(volatile hw_audmux_t *) REGS_AUDMUX_BASE)

#endif


#endif // __HW_AUDMUX_REGISTERS_H__
