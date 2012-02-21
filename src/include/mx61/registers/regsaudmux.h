/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _AUDMUX_H
#define _AUDMUX_H

#include "regs.h"

#ifndef REGS_AUDMUX_BASE
#define REGS_AUDMUX_BASE (REGS_BASE + 0x021d8000)
#endif


/*!
 * @brief HW_AUDMUX_PTCR1 - Port Timing Control Register 1
 *
 * PTCR1 is the Port Timing Control Register for Port 1.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at the same time.
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

/* --- Register HW_AUDMUX_PTCR1, field SYN
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is
 * chosen and the transmit and receive sections use common clock and
 * frame sync signals (that is, the port is a 4-wire interface). When
 * SYN is cleared, asynchronous mode is chosen and separate clock and
 * frame sync signals are used for the transmit and receive sections
 * (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same
 * time.
 */

#define BP_AUDMUX_PTCR1_SYN      11
#define BM_AUDMUX_PTCR1_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR1_SYN)
#else
#define BF_AUDMUX_PTCR1_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR1_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_SYN(v)   BF_CS1(AUDMUX_PTCR1, SYN, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RCSEL
 *
 * Receive Clock Select. Selects the source port from which RxClk is
 * sourced. RxClk can be sourced from TxClk and RxClk from other
 * ports.
 */

#define BP_AUDMUX_PTCR1_RCSEL      12
#define BM_AUDMUX_PTCR1_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#else
#define BF_AUDMUX_PTCR1_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RCSEL(v)   BF_CS1(AUDMUX_PTCR1, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RCLKDIR
 *
 * Receive Clock Direction Control. This bit sets the direction of the
 * RxClk pin of the interface as an output or input. When set as an
 * input, the RCSEL settings are ignored. When set as an output, the
 * RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at
 * the same time.
 */

#define BP_AUDMUX_PTCR1_RCLKDIR      16
#define BM_AUDMUX_PTCR1_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#else
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RFSEL
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is
 * sourced. RxFS can be sourced from TxFS and RxFS from other                                 ports.
 */

#define BP_AUDMUX_PTCR1_RFSEL      17
#define BM_AUDMUX_PTCR1_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#else
#define BF_AUDMUX_PTCR1_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RFSEL(v)   BF_CS1(AUDMUX_PTCR1, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RFS_DIR
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of
 * the RxFS pin of the interface as an output or input. When set as an
 * input, the RFSEL settings are ignored. When set as an output, the
 * RFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR1_RFS_DIR      21
#define BM_AUDMUX_PTCR1_RFS_DIR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR1_RFS_DIR)
#else
#define BF_AUDMUX_PTCR1_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR1_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR1, RFS_DIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TCSEL
 *
 * Transmit Clock Select. Selects the source port from which TxClk is
 * sourced.
 */

#define BP_AUDMUX_PTCR1_TCSEL      22
#define BM_AUDMUX_PTCR1_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#else
#define BF_AUDMUX_PTCR1_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TCSEL(v)   BF_CS1(AUDMUX_PTCR1, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TCLKDIR
 *
 * Transmit Clock Direction Control. This bit sets the direction of the
 * TxClk pin of the interface as an output or input. When set as an
 * input, the TCSEL settings are ignored. When set as an output, the
 * TCSEL settings determine the source port of the clock.
 */

#define BP_AUDMUX_PTCR1_TCLKDIR      26
#define BM_AUDMUX_PTCR1_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#else
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TFSEL
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS
 * is sourced.
 */

#define BP_AUDMUX_PTCR1_TFSEL      27
#define BM_AUDMUX_PTCR1_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#else
#define BF_AUDMUX_PTCR1_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TFSEL(v)   BF_CS1(AUDMUX_PTCR1, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TFS_DIR
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of
 * the TxFS pin of the interface as an output or input. When set as an
 * input, the TFSEL settings are ignored. When set as an output, the
 * TFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR1_TFS_DIR      31
#define BM_AUDMUX_PTCR1_TFS_DIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR1_TFS_DIR)
#else
#define BF_AUDMUX_PTCR1_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR1_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR1, TFS_DIR, v)
#endif

/*!
 * @brief HW_AUDMUX_PTCR2 - Port Timing Control Register 2
 *
 * PTCR2 is the Port Timing Control Register for Port 2.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at the same time.
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

/* --- Register HW_AUDMUX_PTCR2, field SYN
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is
 * chosen and the transmit and receive sections use common clock and
 * frame sync signals (that is, the port is a 4-wire interface). When
 * SYN is cleared, asynchronous mode is chosen and separate clock and
 * frame sync signals are used for the transmit and receive sections
 * (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same
 * time.
 */

#define BP_AUDMUX_PTCR2_SYN      11
#define BM_AUDMUX_PTCR2_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR2_SYN)
#else
#define BF_AUDMUX_PTCR2_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR2_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_SYN(v)   BF_CS1(AUDMUX_PTCR2, SYN, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RCSEL
 *
 * Receive Clock Select. Selects the source port from which RxClk is
 * sourced. RxClk can be sourced from TxClk and RxClk from other
 * ports.
 */

#define BP_AUDMUX_PTCR2_RCSEL      12
#define BM_AUDMUX_PTCR2_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#else
#define BF_AUDMUX_PTCR2_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RCSEL(v)   BF_CS1(AUDMUX_PTCR2, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RCLKDIR
 *
 * Receive Clock Direction Control. This bit sets the direction of the
 * RxClk pin of the interface as an output or input. When set as an
 * input, the RCSEL settings are ignored. When set as an output, the
 * RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at
 * the same time.
 */

#define BP_AUDMUX_PTCR2_RCLKDIR      16
#define BM_AUDMUX_PTCR2_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#else
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RFSEL
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is
 * sourced. RxFS can be sourced from TxFS and RxFS from other                                 ports.
 */

#define BP_AUDMUX_PTCR2_RFSEL      17
#define BM_AUDMUX_PTCR2_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#else
#define BF_AUDMUX_PTCR2_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RFSEL(v)   BF_CS1(AUDMUX_PTCR2, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RFS_DIR
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of
 * the RxFS pin of the interface as an output or input. When set as an
 * input, the RFSEL settings are ignored. When set as an output, the
 * RFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR2_RFS_DIR      21
#define BM_AUDMUX_PTCR2_RFS_DIR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR2_RFS_DIR)
#else
#define BF_AUDMUX_PTCR2_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR2_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR2, RFS_DIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TCSEL
 *
 * Transmit Clock Select. Selects the source port from which TxClk is
 * sourced.
 */

#define BP_AUDMUX_PTCR2_TCSEL      22
#define BM_AUDMUX_PTCR2_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#else
#define BF_AUDMUX_PTCR2_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TCSEL(v)   BF_CS1(AUDMUX_PTCR2, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TCLKDIR
 *
 * Transmit Clock Direction Control. This bit sets the direction of the
 * TxClk pin of the interface as an output or input. When set as an
 * input, the TCSEL settings are ignored. When set as an output, the
 * TCSEL settings determine the source port of the clock.
 */

#define BP_AUDMUX_PTCR2_TCLKDIR      26
#define BM_AUDMUX_PTCR2_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#else
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TFSEL
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS
 * is sourced.
 */

#define BP_AUDMUX_PTCR2_TFSEL      27
#define BM_AUDMUX_PTCR2_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#else
#define BF_AUDMUX_PTCR2_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TFSEL(v)   BF_CS1(AUDMUX_PTCR2, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TFS_DIR
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of
 * the TxFS pin of the interface as an output or input. When set as an
 * input, the TFSEL settings are ignored. When set as an output, the
 * TFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR2_TFS_DIR      31
#define BM_AUDMUX_PTCR2_TFS_DIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR2_TFS_DIR)
#else
#define BF_AUDMUX_PTCR2_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR2_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR2, TFS_DIR, v)
#endif

/*!
 * @brief HW_AUDMUX_PTCR3 - Port Timing Control Register 3
 *
 * PTCR3 is the Port Timing Control Register for Port 3.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at the same time.
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

/* --- Register HW_AUDMUX_PTCR3, field SYN
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is
 * chosen and the transmit and receive sections use common clock and
 * frame sync signals (that is, the port is a 4-wire interface). When
 * SYN is cleared, asynchronous mode is chosen and separate clock and
 * frame sync signals are used for the transmit and receive sections
 * (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same
 * time.
 */

#define BP_AUDMUX_PTCR3_SYN      11
#define BM_AUDMUX_PTCR3_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR3_SYN)
#else
#define BF_AUDMUX_PTCR3_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR3_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_SYN(v)   BF_CS1(AUDMUX_PTCR3, SYN, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RCSEL
 *
 * Receive Clock Select. Selects the source port from which RxClk is
 * sourced. RxClk can be sourced from TxClk and RxClk from other
 * ports.
 */

#define BP_AUDMUX_PTCR3_RCSEL      12
#define BM_AUDMUX_PTCR3_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#else
#define BF_AUDMUX_PTCR3_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RCSEL(v)   BF_CS1(AUDMUX_PTCR3, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RCLKDIR
 *
 * Receive Clock Direction Control. This bit sets the direction of the
 * RxClk pin of the interface as an output or input. When set as an
 * input, the RCSEL settings are ignored. When set as an output, the
 * RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at
 * the same time.
 */

#define BP_AUDMUX_PTCR3_RCLKDIR      16
#define BM_AUDMUX_PTCR3_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#else
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RFSEL
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is
 * sourced. RxFS can be sourced from TxFS and RxFS from other                                 ports.
 */

#define BP_AUDMUX_PTCR3_RFSEL      17
#define BM_AUDMUX_PTCR3_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#else
#define BF_AUDMUX_PTCR3_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RFSEL(v)   BF_CS1(AUDMUX_PTCR3, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RFS_DIR
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of
 * the RxFS pin of the interface as an output or input. When set as an
 * input, the RFSEL settings are ignored. When set as an output, the
 * RFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR3_RFS_DIR      21
#define BM_AUDMUX_PTCR3_RFS_DIR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR3_RFS_DIR)
#else
#define BF_AUDMUX_PTCR3_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR3_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR3, RFS_DIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TCSEL
 *
 * Transmit Clock Select. Selects the source port from which TxClk is
 * sourced.
 */

#define BP_AUDMUX_PTCR3_TCSEL      22
#define BM_AUDMUX_PTCR3_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#else
#define BF_AUDMUX_PTCR3_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TCSEL(v)   BF_CS1(AUDMUX_PTCR3, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TCLKDIR
 *
 * Transmit Clock Direction Control. This bit sets the direction of the
 * TxClk pin of the interface as an output or input. When set as an
 * input, the TCSEL settings are ignored. When set as an output, the
 * TCSEL settings determine the source port of the clock.
 */

#define BP_AUDMUX_PTCR3_TCLKDIR      26
#define BM_AUDMUX_PTCR3_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#else
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TFSEL
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS
 * is sourced.
 */

#define BP_AUDMUX_PTCR3_TFSEL      27
#define BM_AUDMUX_PTCR3_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#else
#define BF_AUDMUX_PTCR3_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TFSEL(v)   BF_CS1(AUDMUX_PTCR3, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TFS_DIR
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of
 * the TxFS pin of the interface as an output or input. When set as an
 * input, the TFSEL settings are ignored. When set as an output, the
 * TFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR3_TFS_DIR      31
#define BM_AUDMUX_PTCR3_TFS_DIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR3_TFS_DIR)
#else
#define BF_AUDMUX_PTCR3_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR3_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR3, TFS_DIR, v)
#endif

/*!
 * @brief HW_AUDMUX_PTCR - Port Timing Control Register n
 *
 * PTCR n is the Port Timing Control Register for Port n , where n ranges from 4 through 7.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SYN : 1; //!< Synchronous/Asynchronous Select. When SYN is set, synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals (that is, the port is a 4-wire interface). When SYN is cleared, asynchronous mode is chosen and separate clock and frame sync signals are used for the transmit and receive sections (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same time.
        unsigned RCSEL : 4; //!< Receive Clock Select. Selects the source port from which RxClk is sourced. RxClk can be sourced from TxClk and RxClk from other ports.
        unsigned RCLKDIR : 1; //!< Receive Clock Direction Control. This bit sets the direction of the RxClk pin of the interface as an output or input. When set as an input, the RCSEL settings are ignored. When set as an output, the RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at the same time.
        unsigned RFSEL : 4; //!< Receive Frame Sync Select. Selects the source port from which RxFS is sourced. RxFS can be sourced from TxFS and RxFS from other ports.
        unsigned RFS_DIR : 1; //!< Receive Frame Sync Direction Control. This bit sets the direction of the RxFS pin of the interface as an output or input. When set as an input, the RFSEL settings are ignored. When set as an output, the RFSEL settings determine the source port of the frame sync.
        unsigned TCSEL : 4; //!< Transmit Clock Select. Selects the source port from which TxClk is sourced.
        unsigned TCLKDIR : 1; //!< Transmit Clock Direction Control. This bit sets the direction of the TxClk pin of the interface as an output or input. When set as an input, the TCSEL settings are ignored. When set as an output, the TCSEL settings determine the source port of the clock.
        unsigned TFSEL : 4; //!< Transmit Frame Sync Select. Selects the source port from which TxFS is sourced.
        unsigned TFS_DIR : 1; //!< Transmit Frame Sync Direction Control. This bit sets the direction of the TxFS pin of the interface as an output or input. When set as an input, the TFSEL settings are ignored. When set as an output, the TFSEL settings determine the source port of the frame sync.
    } B;
} hw_audmux_ptcr_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR register
 */
#define HW_AUDMUX_PTCR_ADDR      (REGS_AUDMUX_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR           (*(volatile hw_audmux_ptcr_t *) HW_AUDMUX_PTCR_ADDR)
#define HW_AUDMUX_PTCR_RD()      (HW_AUDMUX_PTCR.U)
#define HW_AUDMUX_PTCR_WR(v)     (HW_AUDMUX_PTCR.U = (v))
#define HW_AUDMUX_PTCR_SET(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() |  (v)))
#define HW_AUDMUX_PTCR_CLR(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() & ~(v)))
#define HW_AUDMUX_PTCR_TOG(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PTCR bitfields
 */

/* --- Register HW_AUDMUX_PTCR, field SYN
 *
 * Synchronous/Asynchronous Select. When SYN is set, synchronous mode is
 * chosen and the transmit and receive sections use common clock and
 * frame sync signals (that is, the port is a 4-wire interface). When
 * SYN is cleared, asynchronous mode is chosen and separate clock and
 * frame sync signals are used for the transmit and receive sections
 * (that is, the port is a 6-wire interface).  RCLKDIR and SYN should not be changed at the same
 * time.
 */

#define BP_AUDMUX_PTCR_SYN      11
#define BM_AUDMUX_PTCR_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR_SYN)
#else
#define BF_AUDMUX_PTCR_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_SYN(v)   BF_CS1(AUDMUX_PTCR, SYN, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RCSEL
 *
 * Receive Clock Select. Selects the source port from which RxClk is
 * sourced. RxClk can be sourced from TxClk and RxClk from other
 * ports.
 */

#define BP_AUDMUX_PTCR_RCSEL      12
#define BM_AUDMUX_PTCR_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR_RCSEL)
#else
#define BF_AUDMUX_PTCR_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RCSEL(v)   BF_CS1(AUDMUX_PTCR, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RCLKDIR
 *
 * Receive Clock Direction Control. This bit sets the direction of the
 * RxClk pin of the interface as an output or input. When set as an
 * input, the RCSEL settings are ignored. When set as an output, the
 * RCSEL settings determine the source port of the clock.  RCLKDIR and SYN should not be changed at
 * the same time.
 */

#define BP_AUDMUX_PTCR_RCLKDIR      16
#define BM_AUDMUX_PTCR_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR_RCLKDIR)
#else
#define BF_AUDMUX_PTCR_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RFSEL
 *
 * Receive Frame Sync Select. Selects the source port from which RxFS is
 * sourced. RxFS can be sourced from TxFS and RxFS from other                                 ports.
 */

#define BP_AUDMUX_PTCR_RFSEL      17
#define BM_AUDMUX_PTCR_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR_RFSEL)
#else
#define BF_AUDMUX_PTCR_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RFSEL(v)   BF_CS1(AUDMUX_PTCR, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RFS_DIR
 *
 * Receive Frame Sync Direction Control. This bit sets the direction of
 * the RxFS pin of the interface as an output or input. When set as an
 * input, the RFSEL settings are ignored. When set as an output, the
 * RFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR_RFS_DIR      21
#define BM_AUDMUX_PTCR_RFS_DIR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RFS_DIR(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR_RFS_DIR)
#else
#define BF_AUDMUX_PTCR_RFS_DIR(v)   (((v) << 21) & BM_AUDMUX_PTCR_RFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RFS_DIR(v)   BF_CS1(AUDMUX_PTCR, RFS_DIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TCSEL
 *
 * Transmit Clock Select. Selects the source port from which TxClk is
 * sourced.
 */

#define BP_AUDMUX_PTCR_TCSEL      22
#define BM_AUDMUX_PTCR_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR_TCSEL)
#else
#define BF_AUDMUX_PTCR_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TCSEL(v)   BF_CS1(AUDMUX_PTCR, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TCLKDIR
 *
 * Transmit Clock Direction Control. This bit sets the direction of the
 * TxClk pin of the interface as an output or input. When set as an
 * input, the TCSEL settings are ignored. When set as an output, the
 * TCSEL settings determine the source port of the clock.
 */

#define BP_AUDMUX_PTCR_TCLKDIR      26
#define BM_AUDMUX_PTCR_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR_TCLKDIR)
#else
#define BF_AUDMUX_PTCR_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TFSEL
 *
 * Transmit Frame Sync Select. Selects the source port from which TxFS
 * is sourced.
 */

#define BP_AUDMUX_PTCR_TFSEL      27
#define BM_AUDMUX_PTCR_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR_TFSEL)
#else
#define BF_AUDMUX_PTCR_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TFSEL(v)   BF_CS1(AUDMUX_PTCR, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TFS_DIR
 *
 * Transmit Frame Sync Direction Control. This bit sets the direction of
 * the TxFS pin of the interface as an output or input. When set as an
 * input, the TFSEL settings are ignored. When set as an output, the
 * TFSEL settings determine the source port of the frame sync.
 */

#define BP_AUDMUX_PTCR_TFS_DIR      31
#define BM_AUDMUX_PTCR_TFS_DIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TFS_DIR(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR_TFS_DIR)
#else
#define BF_AUDMUX_PTCR_TFS_DIR(v)   (((v) << 31) & BM_AUDMUX_PTCR_TFS_DIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TFS_DIR(v)   BF_CS1(AUDMUX_PTCR, TFS_DIR, v)
#endif



/*!
 * @brief All AUDMUX module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_audmux_ptcr1_t PTCR1; //!< Port Timing Control Register 1
    reg32_t _reserved0;
    volatile hw_audmux_ptcr2_t PTCR2; //!< Port Timing Control Register 2
    reg32_t _reserved1;
    volatile hw_audmux_ptcr3_t PTCR3; //!< Port Timing Control Register 3
    reg32_t _reserved2;
    volatile hw_audmux_ptcr_t PTCR; //!< Port Timing Control Register n
} hw_audmux_t
#endif

//! @brief Macro to access all AUDMUX registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_AUDMUX(0)</code>.
#define HW_AUDMUX     (*(volatile hw_audmux_t *) REGS_AUDMUX_BASE)


#endif // _AUDMUX_H
