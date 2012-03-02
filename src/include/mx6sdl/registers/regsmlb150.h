/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MLB_H
#define _MLB_H

#include "regs.h"

/*
 * i.MX6SDL MLB registers defined in this header file.
 *
 * - HW_MLB_MLBC0 - MediaLB Control 0 Register
 * - HW_MLB_MLBPC0 - MediaLB 6-pin Control 0 Register
 * - HW_MLB_MS0 - MediaLB Channel Status 0 Register
 * - HW_MLB_MLBPC2 - MediaLB 6-pin Control 2 Register
 * - HW_MLB_MS1 - MediaLB Channel Status1 Register
 * - HW_MLB_MSS - MediaLB System Status Register
 * - HW_MLB_MSD - MediaLB System Data Register
 * - HW_MLB_MIEN - MediaLB Interrupt Enable Register
 * - HW_MLB_MLBPC1 - MediaLB 6-pin Control 1 Register
 * - HW_MLB_MLBC1 - MediaLB Control 1 Register
 * - HW_MLB_HCTL - HBI Control Register
 * - HW_MLB_HCMR0 - HBI Channel Mask 0 Register
 * - HW_MLB_HCMR1 - HBI Channel Mask 1 Register
 * - HW_MLB_HCER0 - HBI Channel Error 0 Register
 * - HW_MLB_HCER1 - HBI Channel Error 1 Register
 * - HW_MLB_HCBR0 - HBI Channel Busy 0 Register
 * - HW_MLB_HCBR1 - HBI Channel Busy 1 Register
 * - HW_MLB_MDAT0 - MIF Data 0 Register
 * - HW_MLB_MDAT1 - MIF Data 1 Register
 * - HW_MLB_MDAT2 - MIF Data 2 Register
 * - HW_MLB_MDAT3 - MIF Data 3 Register
 * - HW_MLB_MDWE0 - MIF Data Write Enable 0 Register
 * - HW_MLB_MDWE1 - MIF Data Write Enable 1 Register
 * - HW_MLB_MDWE2 - MIF Data Write Enable 2 Register
 * - HW_MLB_MDWE3 - MIF Data Write Enable 3 Register
 * - HW_MLB_MCTL - MIF Control Register
 * - HW_MLB_MADR - MIF Address Register
 * - HW_MLB_ACTL - AHB Control Register
 * - HW_MLB_ACSR0 - AHB Channel Status 0 Register
 * - HW_MLB_ACSR1 - AHB Channel Status 1 Register
 * - HW_MLB_ACMR0 - AHB Channel Mask 0 Register
 * - HW_MLB_ACMR1 - AHB Channel Mask 1 Register
 *
 * hw_mlb_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_MLB_BASE
#define REGS_MLB_BASE (0x0218c000) //!< Base address for MLB.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MLBC0 - MediaLB Control 0 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mlbc0
{
    reg32_t U;
    struct _hw_mlb_mlbc0_bitfields
    {
        unsigned MLBEN : 1; //!< [0] MediaLB enable. When set, MediaLB clock, signal, and data are received and transmitted on the appropriate MediaLB pins.
        unsigned RESERVED0 : 1; //!< [1] Reserved
        unsigned MLBCLK : 3; //!< [4:2] MediaLB clock speed select.
        unsigned MLBPEN : 1; //!< [5] MediaLB 6-pin enable.
        unsigned RESERVED1 : 1; //!< [6] Reserved
        unsigned MLBLK : 1; //!< [7] MediaLB lock status. When set, indicates that the MediaLB block is synchronized to the incoming MediaLB frame. If MLBLK is clear (unlocked), MLBLK is set after FRAMESYNC is detected at the same position for three consecutive frames. If MLBLK is set (locked), MLBLK is cleared after not receiving FRAMESYNC at the expected time for two consecutive frames. While MLBLK is set, FRAMESYNC patterns occurring at locations other than the expected one are ignored. (read-only)
        unsigned RESERVED2 : 4; //!< [11:8] Reserved
        unsigned ASYRETRY : 1; //!< [12] Asynchronous Tx packet retry. When set, an asynchronous packet that is flagged with a Break or ProtocolError by the receiver is retransmitted. When cleared, an asynchronous packet that is flagged with a Break or ProtocolError by the receiver is skipped.
        unsigned RESERVED3 : 1; //!< [13] Reserved
        unsigned CTLRETRY : 1; //!< [14] Control Tx packet retry. When set, a control packet that is flagged with a Break or ProtocolError by the receiver is retransmitted. When cleared, a control packet that is flagged with a Break or ProtocolError by the receiver is skipped.
        unsigned FCNT : 3; //!< [17:15] The number of frames per sub-buffer for synchronous channels.
        unsigned RESERVED4 : 14; //!< [31:18] Reserved
    } B;
} hw_mlb_mlbc0_t;
#endif

/*
 * constants & macros for entire MLB_MLBC0 register
 */
#define HW_MLB_MLBC0_ADDR      (REGS_MLB_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBC0           (*(volatile hw_mlb_mlbc0_t *) HW_MLB_MLBC0_ADDR)
#define HW_MLB_MLBC0_RD()      (HW_MLB_MLBC0.U)
#define HW_MLB_MLBC0_WR(v)     (HW_MLB_MLBC0.U = (v))
#define HW_MLB_MLBC0_SET(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() |  (v)))
#define HW_MLB_MLBC0_CLR(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() & ~(v)))
#define HW_MLB_MLBC0_TOG(v)    (HW_MLB_MLBC0_WR(HW_MLB_MLBC0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MLBC0 bitfields
 */

/* --- Register HW_MLB_MLBC0, field MLBEN[0] (RW)
 *
 * MediaLB enable. When set, MediaLB clock, signal, and data are received and transmitted on the
 * appropriate MediaLB pins.
 */

#define BP_MLB_MLBC0_MLBEN      (0)      //!< Bit position for MLB_MLBC0_MLBEN.
#define BM_MLB_MLBC0_MLBEN      (0x00000001)  //!< Bit mask for MLB_MLBC0_MLBEN.

//! @brief Get value of MLB_MLBC0_MLBEN from a register value.
#define BG_MLB_MLBC0_MLBEN(r)   (((r) & BM_MLB_MLBC0_MLBEN) >> BP_MLB_MLBC0_MLBEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_MLBEN.
#define BF_MLB_MLBC0_MLBEN(v)   ((((reg32_t) v) << BP_MLB_MLBC0_MLBEN) & BM_MLB_MLBC0_MLBEN)
#else
//! @brief Format value for bitfield MLB_MLBC0_MLBEN.
#define BF_MLB_MLBC0_MLBEN(v)   (((v) << BP_MLB_MLBC0_MLBEN) & BM_MLB_MLBC0_MLBEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MLBEN field to a new value.
#define BW_MLB_MLBC0_MLBEN(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_MLBEN) | BF_MLB_MLBC0_MLBEN(v)))
#endif

/* --- Register HW_MLB_MLBC0, field MLBCLK[4:2] (RW)
 *
 * MediaLB clock speed select.
 *
 * Values:
 * 000 - 256¥Fs (for MLBPEN = 0)
 * 001 - 512¥Fs (for MLBPEN = 0)
 * 010 - 1024¥Fs (for MLBPEN = 0)
 * 011 - 2048¥Fs (for MLBPEN = 1)
 * 100 - 3072¥Fs (for MLBPEN = 1)
 * 101 - 4096¥Fs (for MLBPEN = 1)
 * 110 - 6144¥Fs (for MLBPEN = 1)
 * 111 - 8192¥Fs (for MLBPEN = 1)
 */

#define BP_MLB_MLBC0_MLBCLK      (2)      //!< Bit position for MLB_MLBC0_MLBCLK.
#define BM_MLB_MLBC0_MLBCLK      (0x0000001c)  //!< Bit mask for MLB_MLBC0_MLBCLK.

//! @brief Get value of MLB_MLBC0_MLBCLK from a register value.
#define BG_MLB_MLBC0_MLBCLK(r)   (((r) & BM_MLB_MLBC0_MLBCLK) >> BP_MLB_MLBC0_MLBCLK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_MLBCLK.
#define BF_MLB_MLBC0_MLBCLK(v)   ((((reg32_t) v) << BP_MLB_MLBC0_MLBCLK) & BM_MLB_MLBC0_MLBCLK)
#else
//! @brief Format value for bitfield MLB_MLBC0_MLBCLK.
#define BF_MLB_MLBC0_MLBCLK(v)   (((v) << BP_MLB_MLBC0_MLBCLK) & BM_MLB_MLBC0_MLBCLK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MLBCLK field to a new value.
#define BW_MLB_MLBC0_MLBCLK(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_MLBCLK) | BF_MLB_MLBC0_MLBCLK(v)))
#endif


/* --- Register HW_MLB_MLBC0, field MLBPEN[5] (RW)
 *
 * MediaLB 6-pin enable.
 *
 * Values:
 * 0 - MediaLB 3-pin interface enabled
 * 1 - MediaLB 6-pin interface enabled
 */

#define BP_MLB_MLBC0_MLBPEN      (5)      //!< Bit position for MLB_MLBC0_MLBPEN.
#define BM_MLB_MLBC0_MLBPEN      (0x00000020)  //!< Bit mask for MLB_MLBC0_MLBPEN.

//! @brief Get value of MLB_MLBC0_MLBPEN from a register value.
#define BG_MLB_MLBC0_MLBPEN(r)   (((r) & BM_MLB_MLBC0_MLBPEN) >> BP_MLB_MLBC0_MLBPEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_MLBPEN.
#define BF_MLB_MLBC0_MLBPEN(v)   ((((reg32_t) v) << BP_MLB_MLBC0_MLBPEN) & BM_MLB_MLBC0_MLBPEN)
#else
//! @brief Format value for bitfield MLB_MLBC0_MLBPEN.
#define BF_MLB_MLBC0_MLBPEN(v)   (((v) << BP_MLB_MLBC0_MLBPEN) & BM_MLB_MLBC0_MLBPEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MLBPEN field to a new value.
#define BW_MLB_MLBC0_MLBPEN(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_MLBPEN) | BF_MLB_MLBC0_MLBPEN(v)))
#endif


/* --- Register HW_MLB_MLBC0, field MLBLK[7] (RO)
 *
 * MediaLB lock status. When set, indicates that the MediaLB block is synchronized to the incoming
 * MediaLB frame. If MLBLK is clear (unlocked), MLBLK is set after FRAMESYNC is detected at the same
 * position for three consecutive frames. If MLBLK is set (locked), MLBLK is cleared after not
 * receiving FRAMESYNC at the expected time for two consecutive frames. While MLBLK is set,
 * FRAMESYNC patterns occurring at locations other than the expected one are ignored. (read-only)
 */

#define BP_MLB_MLBC0_MLBLK      (7)      //!< Bit position for MLB_MLBC0_MLBLK.
#define BM_MLB_MLBC0_MLBLK      (0x00000080)  //!< Bit mask for MLB_MLBC0_MLBLK.

//! @brief Get value of MLB_MLBC0_MLBLK from a register value.
#define BG_MLB_MLBC0_MLBLK(r)   (((r) & BM_MLB_MLBC0_MLBLK) >> BP_MLB_MLBC0_MLBLK)

/* --- Register HW_MLB_MLBC0, field ASYRETRY[12] (RW)
 *
 * Asynchronous Tx packet retry. When set, an asynchronous packet that is flagged with a Break or
 * ProtocolError by the receiver is retransmitted. When cleared, an asynchronous packet that is
 * flagged with a Break or ProtocolError by the receiver is skipped.
 */

#define BP_MLB_MLBC0_ASYRETRY      (12)      //!< Bit position for MLB_MLBC0_ASYRETRY.
#define BM_MLB_MLBC0_ASYRETRY      (0x00001000)  //!< Bit mask for MLB_MLBC0_ASYRETRY.

//! @brief Get value of MLB_MLBC0_ASYRETRY from a register value.
#define BG_MLB_MLBC0_ASYRETRY(r)   (((r) & BM_MLB_MLBC0_ASYRETRY) >> BP_MLB_MLBC0_ASYRETRY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_ASYRETRY.
#define BF_MLB_MLBC0_ASYRETRY(v)   ((((reg32_t) v) << BP_MLB_MLBC0_ASYRETRY) & BM_MLB_MLBC0_ASYRETRY)
#else
//! @brief Format value for bitfield MLB_MLBC0_ASYRETRY.
#define BF_MLB_MLBC0_ASYRETRY(v)   (((v) << BP_MLB_MLBC0_ASYRETRY) & BM_MLB_MLBC0_ASYRETRY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASYRETRY field to a new value.
#define BW_MLB_MLBC0_ASYRETRY(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_ASYRETRY) | BF_MLB_MLBC0_ASYRETRY(v)))
#endif

/* --- Register HW_MLB_MLBC0, field CTLRETRY[14] (RW)
 *
 * Control Tx packet retry. When set, a control packet that is flagged with a Break or ProtocolError
 * by the receiver is retransmitted. When cleared, a control packet that is flagged with a Break or
 * ProtocolError by the receiver is skipped.
 */

#define BP_MLB_MLBC0_CTLRETRY      (14)      //!< Bit position for MLB_MLBC0_CTLRETRY.
#define BM_MLB_MLBC0_CTLRETRY      (0x00004000)  //!< Bit mask for MLB_MLBC0_CTLRETRY.

//! @brief Get value of MLB_MLBC0_CTLRETRY from a register value.
#define BG_MLB_MLBC0_CTLRETRY(r)   (((r) & BM_MLB_MLBC0_CTLRETRY) >> BP_MLB_MLBC0_CTLRETRY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_CTLRETRY.
#define BF_MLB_MLBC0_CTLRETRY(v)   ((((reg32_t) v) << BP_MLB_MLBC0_CTLRETRY) & BM_MLB_MLBC0_CTLRETRY)
#else
//! @brief Format value for bitfield MLB_MLBC0_CTLRETRY.
#define BF_MLB_MLBC0_CTLRETRY(v)   (((v) << BP_MLB_MLBC0_CTLRETRY) & BM_MLB_MLBC0_CTLRETRY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTLRETRY field to a new value.
#define BW_MLB_MLBC0_CTLRETRY(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_CTLRETRY) | BF_MLB_MLBC0_CTLRETRY(v)))
#endif

/* --- Register HW_MLB_MLBC0, field FCNT[17:15] (RW)
 *
 * The number of frames per sub-buffer for synchronous channels.
 *
 * Values:
 * 000 - 1 frame per sub-buffer (Operation is the same as Standard mode.)
 * 001 - 2 frames per sub-buffer
 * 010 - 4 frames per sub-buffer
 * 011 - 8 frames per sub-buffer
 * 100 - 16 frames per sub-buffer
 * 101 - 32 frames per sub-buffer
 * 110 - 64 frames per sub-buffer
 * 111 - Reserved
 */

#define BP_MLB_MLBC0_FCNT      (15)      //!< Bit position for MLB_MLBC0_FCNT.
#define BM_MLB_MLBC0_FCNT      (0x00038000)  //!< Bit mask for MLB_MLBC0_FCNT.

//! @brief Get value of MLB_MLBC0_FCNT from a register value.
#define BG_MLB_MLBC0_FCNT(r)   (((r) & BM_MLB_MLBC0_FCNT) >> BP_MLB_MLBC0_FCNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBC0_FCNT.
#define BF_MLB_MLBC0_FCNT(v)   ((((reg32_t) v) << BP_MLB_MLBC0_FCNT) & BM_MLB_MLBC0_FCNT)
#else
//! @brief Format value for bitfield MLB_MLBC0_FCNT.
#define BF_MLB_MLBC0_FCNT(v)   (((v) << BP_MLB_MLBC0_FCNT) & BM_MLB_MLBC0_FCNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FCNT field to a new value.
#define BW_MLB_MLBC0_FCNT(v)   (HW_MLB_MLBC0_WR((HW_MLB_MLBC0_RD() & ~BM_MLB_MLBC0_FCNT) | BF_MLB_MLBC0_FCNT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MLBPC0 - MediaLB 6-pin Control 0 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mlbpc0
{
    reg32_t U;
    struct _hw_mlb_mlbpc0_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] Reserved
        unsigned MCLKHYS : 1; //!< [11] MediaLB (6-pin) hysteresis enable. When set, enables hysteresis on the MediaLB clock. This value is driven on mlb_clk_hys_enable output pin and has no internal function.
        unsigned RESERVED1 : 20; //!< [31:12] Reserved
    } B;
} hw_mlb_mlbpc0_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC0 register
 */
#define HW_MLB_MLBPC0_ADDR      (REGS_MLB_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC0           (*(volatile hw_mlb_mlbpc0_t *) HW_MLB_MLBPC0_ADDR)
#define HW_MLB_MLBPC0_RD()      (HW_MLB_MLBPC0.U)
#define HW_MLB_MLBPC0_WR(v)     (HW_MLB_MLBPC0.U = (v))
#define HW_MLB_MLBPC0_SET(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() |  (v)))
#define HW_MLB_MLBPC0_CLR(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() & ~(v)))
#define HW_MLB_MLBPC0_TOG(v)    (HW_MLB_MLBPC0_WR(HW_MLB_MLBPC0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MLBPC0 bitfields
 */

/* --- Register HW_MLB_MLBPC0, field MCLKHYS[11] (RW)
 *
 * MediaLB (6-pin) hysteresis enable. When set, enables hysteresis on the MediaLB clock. This value
 * is driven on mlb_clk_hys_enable output pin and has no internal function.
 */

#define BP_MLB_MLBPC0_MCLKHYS      (11)      //!< Bit position for MLB_MLBPC0_MCLKHYS.
#define BM_MLB_MLBPC0_MCLKHYS      (0x00000800)  //!< Bit mask for MLB_MLBPC0_MCLKHYS.

//! @brief Get value of MLB_MLBPC0_MCLKHYS from a register value.
#define BG_MLB_MLBPC0_MCLKHYS(r)   (((r) & BM_MLB_MLBPC0_MCLKHYS) >> BP_MLB_MLBPC0_MCLKHYS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBPC0_MCLKHYS.
#define BF_MLB_MLBPC0_MCLKHYS(v)   ((((reg32_t) v) << BP_MLB_MLBPC0_MCLKHYS) & BM_MLB_MLBPC0_MCLKHYS)
#else
//! @brief Format value for bitfield MLB_MLBPC0_MCLKHYS.
#define BF_MLB_MLBPC0_MCLKHYS(v)   (((v) << BP_MLB_MLBPC0_MCLKHYS) & BM_MLB_MLBPC0_MCLKHYS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MCLKHYS field to a new value.
#define BW_MLB_MLBPC0_MCLKHYS(v)   (HW_MLB_MLBPC0_WR((HW_MLB_MLBPC0_RD() & ~BM_MLB_MLBPC0_MCLKHYS) | BF_MLB_MLBPC0_MCLKHYS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MS0 - MediaLB Channel Status 0 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_ms0
{
    reg32_t U;
    struct _hw_mlb_ms0_bitfields
    {
        unsigned MCS : 32; //!< [31:0] MediaLB channel status. Indicates the channel status for MediaLB channels 31 to 0. Channel status bits are set by hardware and cleared by software. Status is only set if the appropriate bits in the MIEN register are set.
    } B;
} hw_mlb_ms0_t;
#endif

/*
 * constants & macros for entire MLB_MS0 register
 */
#define HW_MLB_MS0_ADDR      (REGS_MLB_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MS0           (*(volatile hw_mlb_ms0_t *) HW_MLB_MS0_ADDR)
#define HW_MLB_MS0_RD()      (HW_MLB_MS0.U)
#endif

/*
 * constants & macros for individual MLB_MS0 bitfields
 */

/* --- Register HW_MLB_MS0, field MCS[31:0] (RO)
 *
 * MediaLB channel status. Indicates the channel status for MediaLB channels 31 to 0. Channel status
 * bits are set by hardware and cleared by software. Status is only set if the appropriate bits in
 * the MIEN register are set.
 */

#define BP_MLB_MS0_MCS      (0)      //!< Bit position for MLB_MS0_MCS.
#define BM_MLB_MS0_MCS      (0xffffffff)  //!< Bit mask for MLB_MS0_MCS.

//! @brief Get value of MLB_MS0_MCS from a register value.
#define BG_MLB_MS0_MCS(r)   (((r) & BM_MLB_MS0_MCS) >> BP_MLB_MS0_MCS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MLBPC2 - MediaLB 6-pin Control 2 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mlbpc2
{
    reg32_t U;
    struct _hw_mlb_mlbpc2_bitfields
    {
        unsigned SDOPC : 1; //!< [0] MLB 3-pin interface: Signal/Data output phase control.
        unsigned SDRTO : 2; //!< [2:1] MLB 6-pin interface: Signal/Data receiver threshold offset control.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved.
        unsigned MORCD : 7; //!< [14:8] Divider factor of MLB output reference clock.MLB output reference clock is divided by MLB bus clock, the divider factor can be choose between 1 to 128.
        unsigned MORCE : 1; //!< [15] Output reference clock (for SPDIF and ASRC) enable.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_mlb_mlbpc2_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC2 register
 */
#define HW_MLB_MLBPC2_ADDR      (REGS_MLB_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC2           (*(volatile hw_mlb_mlbpc2_t *) HW_MLB_MLBPC2_ADDR)
#define HW_MLB_MLBPC2_RD()      (HW_MLB_MLBPC2.U)
#endif

/*
 * constants & macros for individual MLB_MLBPC2 bitfields
 */

/* --- Register HW_MLB_MLBPC2, field SDOPC[0] (RW)
 *
 * MLB 3-pin interface: Signal/Data output phase control.
 *
 * Values:
 * 0 - MLB signal/data launch at rising edge of MLB clock(default)
 * 1 - MLB signal/data launch at falling edge of MLB clock
 */

#define BP_MLB_MLBPC2_SDOPC      (0)      //!< Bit position for MLB_MLBPC2_SDOPC.
#define BM_MLB_MLBPC2_SDOPC      (0x00000001)  //!< Bit mask for MLB_MLBPC2_SDOPC.

//! @brief Get value of MLB_MLBPC2_SDOPC from a register value.
#define BG_MLB_MLBPC2_SDOPC(r)   (((r) & BM_MLB_MLBPC2_SDOPC) >> BP_MLB_MLBPC2_SDOPC)


/* --- Register HW_MLB_MLBPC2, field SDRTO[2:1] (RW)
 *
 * MLB 6-pin interface: Signal/Data receiver threshold offset control.
 */

#define BP_MLB_MLBPC2_SDRTO      (1)      //!< Bit position for MLB_MLBPC2_SDRTO.
#define BM_MLB_MLBPC2_SDRTO      (0x00000006)  //!< Bit mask for MLB_MLBPC2_SDRTO.

//! @brief Get value of MLB_MLBPC2_SDRTO from a register value.
#define BG_MLB_MLBPC2_SDRTO(r)   (((r) & BM_MLB_MLBPC2_SDRTO) >> BP_MLB_MLBPC2_SDRTO)

/* --- Register HW_MLB_MLBPC2, field MORCD[14:8] (RW)
 *
 * Divider factor of MLB output reference clock.MLB output reference clock is divided by MLB bus
 * clock, the divider factor can be choose between 1 to 128.
 *
 * Values:
 * 0x00 - Divider factor is 1.
 * ... - 
 * 0x01 - Divider factor is 2.
 * 0xff - Divider factor is 256.
 */

#define BP_MLB_MLBPC2_MORCD      (8)      //!< Bit position for MLB_MLBPC2_MORCD.
#define BM_MLB_MLBPC2_MORCD      (0x00007f00)  //!< Bit mask for MLB_MLBPC2_MORCD.

//! @brief Get value of MLB_MLBPC2_MORCD from a register value.
#define BG_MLB_MLBPC2_MORCD(r)   (((r) & BM_MLB_MLBPC2_MORCD) >> BP_MLB_MLBPC2_MORCD)


/* --- Register HW_MLB_MLBPC2, field MORCE[15] (RW)
 *
 * Output reference clock (for SPDIF and ASRC) enable.
 *
 * Values:
 * 0 - Enable MLB output reference clock.
 * 1 - Disable MLB output reference clock.
 */

#define BP_MLB_MLBPC2_MORCE      (15)      //!< Bit position for MLB_MLBPC2_MORCE.
#define BM_MLB_MLBPC2_MORCE      (0x00008000)  //!< Bit mask for MLB_MLBPC2_MORCE.

//! @brief Get value of MLB_MLBPC2_MORCE from a register value.
#define BG_MLB_MLBPC2_MORCE(r)   (((r) & BM_MLB_MLBPC2_MORCE) >> BP_MLB_MLBPC2_MORCE)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MS1 - MediaLB Channel Status1 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_ms1
{
    reg32_t U;
    struct _hw_mlb_ms1_bitfields
    {
        unsigned MCS : 32; //!< [31:0] MediaLB channel status. Indicates the channel status for MediaLB channels 63 to 32. Channel status bits are set by hardware and cleared by software. Status is only set if the appropriate bits in the MIEN register are set.
    } B;
} hw_mlb_ms1_t;
#endif

/*
 * constants & macros for entire MLB_MS1 register
 */
#define HW_MLB_MS1_ADDR      (REGS_MLB_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MS1           (*(volatile hw_mlb_ms1_t *) HW_MLB_MS1_ADDR)
#define HW_MLB_MS1_RD()      (HW_MLB_MS1.U)
#endif

/*
 * constants & macros for individual MLB_MS1 bitfields
 */

/* --- Register HW_MLB_MS1, field MCS[31:0] (RO)
 *
 * MediaLB channel status. Indicates the channel status for MediaLB channels 63 to 32. Channel
 * status bits are set by hardware and cleared by software. Status is only set if the appropriate
 * bits in the MIEN register are set.
 */

#define BP_MLB_MS1_MCS      (0)      //!< Bit position for MLB_MS1_MCS.
#define BM_MLB_MS1_MCS      (0xffffffff)  //!< Bit mask for MLB_MS1_MCS.

//! @brief Get value of MLB_MS1_MCS from a register value.
#define BG_MLB_MS1_MCS(r)   (((r) & BM_MLB_MS1_MCS) >> BP_MLB_MS1_MCS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MSS - MediaLB System Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mss
{
    reg32_t U;
    struct _hw_mlb_mss_bitfields
    {
        unsigned RSTSYSCMD : 1; //!< [0] Reset system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned LKSYSCMD : 1; //!< [1] Network lock system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned ULKSYSCMD : 1; //!< [2] Network unlock system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned CSSYSCMD : 1; //!< [3] Channel scan system command detected (in the system quadlet). Set by hardware, cleared by software. If the node address specified in Data quadlet matches the value in MLBC1.NDA , the device responds either "device present" or "device present, request service" system response in the next system quadlet.
        unsigned SWSYSCMD : 1; //!< [4] Software system command detected (in the system quadlet). Set by hardware, cleared by software. Data is stored in the MSD register for this command.
        unsigned SERVREQ : 1; //!< [5] Service request enabled. When set, the MediaLB block responds with a "device present, request service" system response if a matching channel scan system command is detected. When cleared, the MediaLB block responds with a "device present" system response.
        unsigned RESERVED0 : 26; //!< [31:6] Reserved
    } B;
} hw_mlb_mss_t;
#endif

/*
 * constants & macros for entire MLB_MSS register
 */
#define HW_MLB_MSS_ADDR      (REGS_MLB_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MSS           (*(volatile hw_mlb_mss_t *) HW_MLB_MSS_ADDR)
#define HW_MLB_MSS_RD()      (HW_MLB_MSS.U)
#endif

/*
 * constants & macros for individual MLB_MSS bitfields
 */

/* --- Register HW_MLB_MSS, field RSTSYSCMD[0] (RO)
 *
 * Reset system command detected (in the system quadlet). Set by hardware, cleared by software.
 */

#define BP_MLB_MSS_RSTSYSCMD      (0)      //!< Bit position for MLB_MSS_RSTSYSCMD.
#define BM_MLB_MSS_RSTSYSCMD      (0x00000001)  //!< Bit mask for MLB_MSS_RSTSYSCMD.

//! @brief Get value of MLB_MSS_RSTSYSCMD from a register value.
#define BG_MLB_MSS_RSTSYSCMD(r)   (((r) & BM_MLB_MSS_RSTSYSCMD) >> BP_MLB_MSS_RSTSYSCMD)

/* --- Register HW_MLB_MSS, field LKSYSCMD[1] (RO)
 *
 * Network lock system command detected (in the system quadlet). Set by hardware, cleared by
 * software.
 */

#define BP_MLB_MSS_LKSYSCMD      (1)      //!< Bit position for MLB_MSS_LKSYSCMD.
#define BM_MLB_MSS_LKSYSCMD      (0x00000002)  //!< Bit mask for MLB_MSS_LKSYSCMD.

//! @brief Get value of MLB_MSS_LKSYSCMD from a register value.
#define BG_MLB_MSS_LKSYSCMD(r)   (((r) & BM_MLB_MSS_LKSYSCMD) >> BP_MLB_MSS_LKSYSCMD)

/* --- Register HW_MLB_MSS, field ULKSYSCMD[2] (RO)
 *
 * Network unlock system command detected (in the system quadlet). Set by hardware, cleared by
 * software.
 */

#define BP_MLB_MSS_ULKSYSCMD      (2)      //!< Bit position for MLB_MSS_ULKSYSCMD.
#define BM_MLB_MSS_ULKSYSCMD      (0x00000004)  //!< Bit mask for MLB_MSS_ULKSYSCMD.

//! @brief Get value of MLB_MSS_ULKSYSCMD from a register value.
#define BG_MLB_MSS_ULKSYSCMD(r)   (((r) & BM_MLB_MSS_ULKSYSCMD) >> BP_MLB_MSS_ULKSYSCMD)

/* --- Register HW_MLB_MSS, field CSSYSCMD[3] (RO)
 *
 * Channel scan system command detected (in the system quadlet). Set by hardware, cleared by
 * software. If the node address specified in Data quadlet matches the value in MLBC1.NDA , the
 * device responds either "device present" or "device present, request service" system response in
 * the next system quadlet.
 */

#define BP_MLB_MSS_CSSYSCMD      (3)      //!< Bit position for MLB_MSS_CSSYSCMD.
#define BM_MLB_MSS_CSSYSCMD      (0x00000008)  //!< Bit mask for MLB_MSS_CSSYSCMD.

//! @brief Get value of MLB_MSS_CSSYSCMD from a register value.
#define BG_MLB_MSS_CSSYSCMD(r)   (((r) & BM_MLB_MSS_CSSYSCMD) >> BP_MLB_MSS_CSSYSCMD)

/* --- Register HW_MLB_MSS, field SWSYSCMD[4] (RO)
 *
 * Software system command detected (in the system quadlet). Set by hardware, cleared by software.
 * Data is stored in the MSD register for this command.
 */

#define BP_MLB_MSS_SWSYSCMD      (4)      //!< Bit position for MLB_MSS_SWSYSCMD.
#define BM_MLB_MSS_SWSYSCMD      (0x00000010)  //!< Bit mask for MLB_MSS_SWSYSCMD.

//! @brief Get value of MLB_MSS_SWSYSCMD from a register value.
#define BG_MLB_MSS_SWSYSCMD(r)   (((r) & BM_MLB_MSS_SWSYSCMD) >> BP_MLB_MSS_SWSYSCMD)

/* --- Register HW_MLB_MSS, field SERVREQ[5] (RW)
 *
 * Service request enabled. When set, the MediaLB block responds with a "device present, request
 * service" system response if a matching channel scan system command is detected. When cleared, the
 * MediaLB block responds with a "device present" system response.
 */

#define BP_MLB_MSS_SERVREQ      (5)      //!< Bit position for MLB_MSS_SERVREQ.
#define BM_MLB_MSS_SERVREQ      (0x00000020)  //!< Bit mask for MLB_MSS_SERVREQ.

//! @brief Get value of MLB_MSS_SERVREQ from a register value.
#define BG_MLB_MSS_SERVREQ(r)   (((r) & BM_MLB_MSS_SERVREQ) >> BP_MLB_MSS_SERVREQ)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MSD - MediaLB System Data Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_msd
{
    reg32_t U;
    struct _hw_mlb_msd_bitfields
    {
        unsigned SD0 : 8; //!< [7:0] System data (byte 0). Updated with MediaLB Data[7:0] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD0 is not updated. (read-only)
        unsigned SD1 : 8; //!< [15:8] System data (byte 1). Updated with MediaLB Data[15:8] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD1 is not updated. (read-only)
        unsigned SD2 : 8; //!< [23:16] System data (byte 2). Updated with MediaLB Data[23:16] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD2 is not updated. (read-only)
        unsigned SD3 : 8; //!< [31:24] System data (byte 3). Updated with MediaLB Data[31:24] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD3 is not updated. (read-only)
    } B;
} hw_mlb_msd_t;
#endif

/*
 * constants & macros for entire MLB_MSD register
 */
#define HW_MLB_MSD_ADDR      (REGS_MLB_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MSD           (*(volatile hw_mlb_msd_t *) HW_MLB_MSD_ADDR)
#define HW_MLB_MSD_RD()      (HW_MLB_MSD.U)
#endif

/*
 * constants & macros for individual MLB_MSD bitfields
 */

/* --- Register HW_MLB_MSD, field SD0[7:0] (RO)
 *
 * System data (byte 0). Updated with MediaLB Data[7:0] when a MediaLB software system command is
 * received in the system quadlet. If MSS.SWSYSCMD is already set, then SD0 is not updated. (read-
 * only)
 */

#define BP_MLB_MSD_SD0      (0)      //!< Bit position for MLB_MSD_SD0.
#define BM_MLB_MSD_SD0      (0x000000ff)  //!< Bit mask for MLB_MSD_SD0.

//! @brief Get value of MLB_MSD_SD0 from a register value.
#define BG_MLB_MSD_SD0(r)   (((r) & BM_MLB_MSD_SD0) >> BP_MLB_MSD_SD0)

/* --- Register HW_MLB_MSD, field SD1[15:8] (RO)
 *
 * System data (byte 1). Updated with MediaLB Data[15:8] when a MediaLB software system command is
 * received in the system quadlet. If MSS.SWSYSCMD is already set, then SD1 is not updated. (read-
 * only)
 */

#define BP_MLB_MSD_SD1      (8)      //!< Bit position for MLB_MSD_SD1.
#define BM_MLB_MSD_SD1      (0x0000ff00)  //!< Bit mask for MLB_MSD_SD1.

//! @brief Get value of MLB_MSD_SD1 from a register value.
#define BG_MLB_MSD_SD1(r)   (((r) & BM_MLB_MSD_SD1) >> BP_MLB_MSD_SD1)

/* --- Register HW_MLB_MSD, field SD2[23:16] (RO)
 *
 * System data (byte 2). Updated with MediaLB Data[23:16] when a MediaLB software system command is
 * received in the system quadlet. If MSS.SWSYSCMD is already set, then SD2 is not updated. (read-
 * only)
 */

#define BP_MLB_MSD_SD2      (16)      //!< Bit position for MLB_MSD_SD2.
#define BM_MLB_MSD_SD2      (0x00ff0000)  //!< Bit mask for MLB_MSD_SD2.

//! @brief Get value of MLB_MSD_SD2 from a register value.
#define BG_MLB_MSD_SD2(r)   (((r) & BM_MLB_MSD_SD2) >> BP_MLB_MSD_SD2)

/* --- Register HW_MLB_MSD, field SD3[31:24] (RO)
 *
 * System data (byte 3). Updated with MediaLB Data[31:24] when a MediaLB software system command is
 * received in the system quadlet. If MSS.SWSYSCMD is already set, then SD3 is not updated. (read-
 * only)
 */

#define BP_MLB_MSD_SD3      (24)      //!< Bit position for MLB_MSD_SD3.
#define BM_MLB_MSD_SD3      (0xff000000)  //!< Bit mask for MLB_MSD_SD3.

//! @brief Get value of MLB_MSD_SD3 from a register value.
#define BG_MLB_MSD_SD3(r)   (((r) & BM_MLB_MSD_SD3) >> BP_MLB_MSD_SD3)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MIEN - MediaLB Interrupt Enable Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mien
{
    reg32_t U;
    struct _hw_mlb_mien_bitfields
    {
        unsigned ISOC_PE : 1; //!< [0] Isochronous Rx protocol error enable. When set, a ProtocolError detected on an isochronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ISOC_BUFO : 1; //!< [1] Isochronous Rx buffer overflow enable. When set, a buffer overflow on an isochronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set. This occurs only when isochronous flow control is disabled.
        unsigned RESERVED0 : 14; //!< [15:2] Reserved
        unsigned SYNC_PE : 1; //!< [16] Synchronous protocol error enable. When set, a ProtocolError detected on a synchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ARX_DONE : 1; //!< [17] Asynchronous Rx done enable. When set, a packet received with no errors on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ARX_PE : 1; //!< [18] Asynchronous Rx protocol error enable. When set, a ProtocolError detected on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ARX_BREAK : 1; //!< [19] Asynchronous Rx break enable. When set, a AsyncBreak command received from the transmitter on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ATX_DONE : 1; //!< [20] Asynchronous Tx packet done enable. When set, a packet transmitted with no errors on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ATX_PE : 1; //!< [21] Asynchronous Tx protocol error enable. When set, a ProtocolError generated by the receiver on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned ATX_BREAK : 1; //!< [22] Asynchronous Tx break enable. When set, a ReceiverBreak response received from the receiver on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED1 : 1; //!< [23] Reserved
        unsigned CRX_DONE : 1; //!< [24] Control Rx packet done enable. When set, a packet received with no errors on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned CRX_PE : 1; //!< [25] Control Rx protocol error enable. When set, a ProtocolError detected on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned CRX_BREAK : 1; //!< [26] Control Rx break enable. When set, a ControlBreak command received from the transmitter on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned CTX_DONE : 1; //!< [27] Control Tx packet done enable. When set, a packet transmitted with no errors on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned CTX_PE : 1; //!< [28] Control Tx protocol error enable. When set, a ProtocolError generated by the receiver on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned CTX_BREAK : 1; //!< [29] Control Tx break enable. When set, a ReceiverBreak response received from the receiver on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED2 : 2; //!< [31:30] Reserved
    } B;
} hw_mlb_mien_t;
#endif

/*
 * constants & macros for entire MLB_MIEN register
 */
#define HW_MLB_MIEN_ADDR      (REGS_MLB_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MIEN           (*(volatile hw_mlb_mien_t *) HW_MLB_MIEN_ADDR)
#define HW_MLB_MIEN_RD()      (HW_MLB_MIEN.U)
#define HW_MLB_MIEN_WR(v)     (HW_MLB_MIEN.U = (v))
#define HW_MLB_MIEN_SET(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() |  (v)))
#define HW_MLB_MIEN_CLR(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() & ~(v)))
#define HW_MLB_MIEN_TOG(v)    (HW_MLB_MIEN_WR(HW_MLB_MIEN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MIEN bitfields
 */

/* --- Register HW_MLB_MIEN, field ISOC_PE[0] (RW)
 *
 * Isochronous Rx protocol error enable. When set, a ProtocolError detected on an isochronous Rx
 * channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ISOC_PE      (0)      //!< Bit position for MLB_MIEN_ISOC_PE.
#define BM_MLB_MIEN_ISOC_PE      (0x00000001)  //!< Bit mask for MLB_MIEN_ISOC_PE.

//! @brief Get value of MLB_MIEN_ISOC_PE from a register value.
#define BG_MLB_MIEN_ISOC_PE(r)   (((r) & BM_MLB_MIEN_ISOC_PE) >> BP_MLB_MIEN_ISOC_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ISOC_PE.
#define BF_MLB_MIEN_ISOC_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_ISOC_PE) & BM_MLB_MIEN_ISOC_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_ISOC_PE.
#define BF_MLB_MIEN_ISOC_PE(v)   (((v) << BP_MLB_MIEN_ISOC_PE) & BM_MLB_MIEN_ISOC_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISOC_PE field to a new value.
#define BW_MLB_MIEN_ISOC_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ISOC_PE) | BF_MLB_MIEN_ISOC_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ISOC_BUFO[1] (RW)
 *
 * Isochronous Rx buffer overflow enable. When set, a buffer overflow on an isochronous Rx channel
 * causes the appropriate channel bit in the MS0 or MS1 registers to be set. This occurs only when
 * isochronous flow control is disabled.
 */

#define BP_MLB_MIEN_ISOC_BUFO      (1)      //!< Bit position for MLB_MIEN_ISOC_BUFO.
#define BM_MLB_MIEN_ISOC_BUFO      (0x00000002)  //!< Bit mask for MLB_MIEN_ISOC_BUFO.

//! @brief Get value of MLB_MIEN_ISOC_BUFO from a register value.
#define BG_MLB_MIEN_ISOC_BUFO(r)   (((r) & BM_MLB_MIEN_ISOC_BUFO) >> BP_MLB_MIEN_ISOC_BUFO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ISOC_BUFO.
#define BF_MLB_MIEN_ISOC_BUFO(v)   ((((reg32_t) v) << BP_MLB_MIEN_ISOC_BUFO) & BM_MLB_MIEN_ISOC_BUFO)
#else
//! @brief Format value for bitfield MLB_MIEN_ISOC_BUFO.
#define BF_MLB_MIEN_ISOC_BUFO(v)   (((v) << BP_MLB_MIEN_ISOC_BUFO) & BM_MLB_MIEN_ISOC_BUFO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISOC_BUFO field to a new value.
#define BW_MLB_MIEN_ISOC_BUFO(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ISOC_BUFO) | BF_MLB_MIEN_ISOC_BUFO(v)))
#endif

/* --- Register HW_MLB_MIEN, field SYNC_PE[16] (RW)
 *
 * Synchronous protocol error enable. When set, a ProtocolError detected on a synchronous Rx channel
 * causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_SYNC_PE      (16)      //!< Bit position for MLB_MIEN_SYNC_PE.
#define BM_MLB_MIEN_SYNC_PE      (0x00010000)  //!< Bit mask for MLB_MIEN_SYNC_PE.

//! @brief Get value of MLB_MIEN_SYNC_PE from a register value.
#define BG_MLB_MIEN_SYNC_PE(r)   (((r) & BM_MLB_MIEN_SYNC_PE) >> BP_MLB_MIEN_SYNC_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_SYNC_PE.
#define BF_MLB_MIEN_SYNC_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_SYNC_PE) & BM_MLB_MIEN_SYNC_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_SYNC_PE.
#define BF_MLB_MIEN_SYNC_PE(v)   (((v) << BP_MLB_MIEN_SYNC_PE) & BM_MLB_MIEN_SYNC_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC_PE field to a new value.
#define BW_MLB_MIEN_SYNC_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_SYNC_PE) | BF_MLB_MIEN_SYNC_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ARX_DONE[17] (RW)
 *
 * Asynchronous Rx done enable. When set, a packet received with no errors on an asynchronous Rx
 * channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ARX_DONE      (17)      //!< Bit position for MLB_MIEN_ARX_DONE.
#define BM_MLB_MIEN_ARX_DONE      (0x00020000)  //!< Bit mask for MLB_MIEN_ARX_DONE.

//! @brief Get value of MLB_MIEN_ARX_DONE from a register value.
#define BG_MLB_MIEN_ARX_DONE(r)   (((r) & BM_MLB_MIEN_ARX_DONE) >> BP_MLB_MIEN_ARX_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ARX_DONE.
#define BF_MLB_MIEN_ARX_DONE(v)   ((((reg32_t) v) << BP_MLB_MIEN_ARX_DONE) & BM_MLB_MIEN_ARX_DONE)
#else
//! @brief Format value for bitfield MLB_MIEN_ARX_DONE.
#define BF_MLB_MIEN_ARX_DONE(v)   (((v) << BP_MLB_MIEN_ARX_DONE) & BM_MLB_MIEN_ARX_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARX_DONE field to a new value.
#define BW_MLB_MIEN_ARX_DONE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ARX_DONE) | BF_MLB_MIEN_ARX_DONE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ARX_PE[18] (RW)
 *
 * Asynchronous Rx protocol error enable. When set, a ProtocolError detected on an asynchronous Rx
 * channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ARX_PE      (18)      //!< Bit position for MLB_MIEN_ARX_PE.
#define BM_MLB_MIEN_ARX_PE      (0x00040000)  //!< Bit mask for MLB_MIEN_ARX_PE.

//! @brief Get value of MLB_MIEN_ARX_PE from a register value.
#define BG_MLB_MIEN_ARX_PE(r)   (((r) & BM_MLB_MIEN_ARX_PE) >> BP_MLB_MIEN_ARX_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ARX_PE.
#define BF_MLB_MIEN_ARX_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_ARX_PE) & BM_MLB_MIEN_ARX_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_ARX_PE.
#define BF_MLB_MIEN_ARX_PE(v)   (((v) << BP_MLB_MIEN_ARX_PE) & BM_MLB_MIEN_ARX_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARX_PE field to a new value.
#define BW_MLB_MIEN_ARX_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ARX_PE) | BF_MLB_MIEN_ARX_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ARX_BREAK[19] (RW)
 *
 * Asynchronous Rx break enable. When set, a AsyncBreak command received from the transmitter on an
 * asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ARX_BREAK      (19)      //!< Bit position for MLB_MIEN_ARX_BREAK.
#define BM_MLB_MIEN_ARX_BREAK      (0x00080000)  //!< Bit mask for MLB_MIEN_ARX_BREAK.

//! @brief Get value of MLB_MIEN_ARX_BREAK from a register value.
#define BG_MLB_MIEN_ARX_BREAK(r)   (((r) & BM_MLB_MIEN_ARX_BREAK) >> BP_MLB_MIEN_ARX_BREAK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ARX_BREAK.
#define BF_MLB_MIEN_ARX_BREAK(v)   ((((reg32_t) v) << BP_MLB_MIEN_ARX_BREAK) & BM_MLB_MIEN_ARX_BREAK)
#else
//! @brief Format value for bitfield MLB_MIEN_ARX_BREAK.
#define BF_MLB_MIEN_ARX_BREAK(v)   (((v) << BP_MLB_MIEN_ARX_BREAK) & BM_MLB_MIEN_ARX_BREAK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARX_BREAK field to a new value.
#define BW_MLB_MIEN_ARX_BREAK(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ARX_BREAK) | BF_MLB_MIEN_ARX_BREAK(v)))
#endif

/* --- Register HW_MLB_MIEN, field ATX_DONE[20] (RW)
 *
 * Asynchronous Tx packet done enable. When set, a packet transmitted with no errors on an
 * asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ATX_DONE      (20)      //!< Bit position for MLB_MIEN_ATX_DONE.
#define BM_MLB_MIEN_ATX_DONE      (0x00100000)  //!< Bit mask for MLB_MIEN_ATX_DONE.

//! @brief Get value of MLB_MIEN_ATX_DONE from a register value.
#define BG_MLB_MIEN_ATX_DONE(r)   (((r) & BM_MLB_MIEN_ATX_DONE) >> BP_MLB_MIEN_ATX_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ATX_DONE.
#define BF_MLB_MIEN_ATX_DONE(v)   ((((reg32_t) v) << BP_MLB_MIEN_ATX_DONE) & BM_MLB_MIEN_ATX_DONE)
#else
//! @brief Format value for bitfield MLB_MIEN_ATX_DONE.
#define BF_MLB_MIEN_ATX_DONE(v)   (((v) << BP_MLB_MIEN_ATX_DONE) & BM_MLB_MIEN_ATX_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATX_DONE field to a new value.
#define BW_MLB_MIEN_ATX_DONE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ATX_DONE) | BF_MLB_MIEN_ATX_DONE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ATX_PE[21] (RW)
 *
 * Asynchronous Tx protocol error enable. When set, a ProtocolError generated by the receiver on an
 * asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ATX_PE      (21)      //!< Bit position for MLB_MIEN_ATX_PE.
#define BM_MLB_MIEN_ATX_PE      (0x00200000)  //!< Bit mask for MLB_MIEN_ATX_PE.

//! @brief Get value of MLB_MIEN_ATX_PE from a register value.
#define BG_MLB_MIEN_ATX_PE(r)   (((r) & BM_MLB_MIEN_ATX_PE) >> BP_MLB_MIEN_ATX_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ATX_PE.
#define BF_MLB_MIEN_ATX_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_ATX_PE) & BM_MLB_MIEN_ATX_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_ATX_PE.
#define BF_MLB_MIEN_ATX_PE(v)   (((v) << BP_MLB_MIEN_ATX_PE) & BM_MLB_MIEN_ATX_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATX_PE field to a new value.
#define BW_MLB_MIEN_ATX_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ATX_PE) | BF_MLB_MIEN_ATX_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field ATX_BREAK[22] (RW)
 *
 * Asynchronous Tx break enable. When set, a ReceiverBreak response received from the receiver on an
 * asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_ATX_BREAK      (22)      //!< Bit position for MLB_MIEN_ATX_BREAK.
#define BM_MLB_MIEN_ATX_BREAK      (0x00400000)  //!< Bit mask for MLB_MIEN_ATX_BREAK.

//! @brief Get value of MLB_MIEN_ATX_BREAK from a register value.
#define BG_MLB_MIEN_ATX_BREAK(r)   (((r) & BM_MLB_MIEN_ATX_BREAK) >> BP_MLB_MIEN_ATX_BREAK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_ATX_BREAK.
#define BF_MLB_MIEN_ATX_BREAK(v)   ((((reg32_t) v) << BP_MLB_MIEN_ATX_BREAK) & BM_MLB_MIEN_ATX_BREAK)
#else
//! @brief Format value for bitfield MLB_MIEN_ATX_BREAK.
#define BF_MLB_MIEN_ATX_BREAK(v)   (((v) << BP_MLB_MIEN_ATX_BREAK) & BM_MLB_MIEN_ATX_BREAK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATX_BREAK field to a new value.
#define BW_MLB_MIEN_ATX_BREAK(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_ATX_BREAK) | BF_MLB_MIEN_ATX_BREAK(v)))
#endif

/* --- Register HW_MLB_MIEN, field CRX_DONE[24] (RW)
 *
 * Control Rx packet done enable. When set, a packet received with no errors on a control Rx channel
 * causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CRX_DONE      (24)      //!< Bit position for MLB_MIEN_CRX_DONE.
#define BM_MLB_MIEN_CRX_DONE      (0x01000000)  //!< Bit mask for MLB_MIEN_CRX_DONE.

//! @brief Get value of MLB_MIEN_CRX_DONE from a register value.
#define BG_MLB_MIEN_CRX_DONE(r)   (((r) & BM_MLB_MIEN_CRX_DONE) >> BP_MLB_MIEN_CRX_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CRX_DONE.
#define BF_MLB_MIEN_CRX_DONE(v)   ((((reg32_t) v) << BP_MLB_MIEN_CRX_DONE) & BM_MLB_MIEN_CRX_DONE)
#else
//! @brief Format value for bitfield MLB_MIEN_CRX_DONE.
#define BF_MLB_MIEN_CRX_DONE(v)   (((v) << BP_MLB_MIEN_CRX_DONE) & BM_MLB_MIEN_CRX_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRX_DONE field to a new value.
#define BW_MLB_MIEN_CRX_DONE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CRX_DONE) | BF_MLB_MIEN_CRX_DONE(v)))
#endif

/* --- Register HW_MLB_MIEN, field CRX_PE[25] (RW)
 *
 * Control Rx protocol error enable. When set, a ProtocolError detected on a control Rx channel
 * causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CRX_PE      (25)      //!< Bit position for MLB_MIEN_CRX_PE.
#define BM_MLB_MIEN_CRX_PE      (0x02000000)  //!< Bit mask for MLB_MIEN_CRX_PE.

//! @brief Get value of MLB_MIEN_CRX_PE from a register value.
#define BG_MLB_MIEN_CRX_PE(r)   (((r) & BM_MLB_MIEN_CRX_PE) >> BP_MLB_MIEN_CRX_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CRX_PE.
#define BF_MLB_MIEN_CRX_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_CRX_PE) & BM_MLB_MIEN_CRX_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_CRX_PE.
#define BF_MLB_MIEN_CRX_PE(v)   (((v) << BP_MLB_MIEN_CRX_PE) & BM_MLB_MIEN_CRX_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRX_PE field to a new value.
#define BW_MLB_MIEN_CRX_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CRX_PE) | BF_MLB_MIEN_CRX_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field CRX_BREAK[26] (RW)
 *
 * Control Rx break enable. When set, a ControlBreak command received from the transmitter on a
 * control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CRX_BREAK      (26)      //!< Bit position for MLB_MIEN_CRX_BREAK.
#define BM_MLB_MIEN_CRX_BREAK      (0x04000000)  //!< Bit mask for MLB_MIEN_CRX_BREAK.

//! @brief Get value of MLB_MIEN_CRX_BREAK from a register value.
#define BG_MLB_MIEN_CRX_BREAK(r)   (((r) & BM_MLB_MIEN_CRX_BREAK) >> BP_MLB_MIEN_CRX_BREAK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CRX_BREAK.
#define BF_MLB_MIEN_CRX_BREAK(v)   ((((reg32_t) v) << BP_MLB_MIEN_CRX_BREAK) & BM_MLB_MIEN_CRX_BREAK)
#else
//! @brief Format value for bitfield MLB_MIEN_CRX_BREAK.
#define BF_MLB_MIEN_CRX_BREAK(v)   (((v) << BP_MLB_MIEN_CRX_BREAK) & BM_MLB_MIEN_CRX_BREAK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRX_BREAK field to a new value.
#define BW_MLB_MIEN_CRX_BREAK(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CRX_BREAK) | BF_MLB_MIEN_CRX_BREAK(v)))
#endif

/* --- Register HW_MLB_MIEN, field CTX_DONE[27] (RW)
 *
 * Control Tx packet done enable. When set, a packet transmitted with no errors on a control Tx
 * channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CTX_DONE      (27)      //!< Bit position for MLB_MIEN_CTX_DONE.
#define BM_MLB_MIEN_CTX_DONE      (0x08000000)  //!< Bit mask for MLB_MIEN_CTX_DONE.

//! @brief Get value of MLB_MIEN_CTX_DONE from a register value.
#define BG_MLB_MIEN_CTX_DONE(r)   (((r) & BM_MLB_MIEN_CTX_DONE) >> BP_MLB_MIEN_CTX_DONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CTX_DONE.
#define BF_MLB_MIEN_CTX_DONE(v)   ((((reg32_t) v) << BP_MLB_MIEN_CTX_DONE) & BM_MLB_MIEN_CTX_DONE)
#else
//! @brief Format value for bitfield MLB_MIEN_CTX_DONE.
#define BF_MLB_MIEN_CTX_DONE(v)   (((v) << BP_MLB_MIEN_CTX_DONE) & BM_MLB_MIEN_CTX_DONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTX_DONE field to a new value.
#define BW_MLB_MIEN_CTX_DONE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CTX_DONE) | BF_MLB_MIEN_CTX_DONE(v)))
#endif

/* --- Register HW_MLB_MIEN, field CTX_PE[28] (RW)
 *
 * Control Tx protocol error enable. When set, a ProtocolError generated by the receiver on a
 * control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CTX_PE      (28)      //!< Bit position for MLB_MIEN_CTX_PE.
#define BM_MLB_MIEN_CTX_PE      (0x10000000)  //!< Bit mask for MLB_MIEN_CTX_PE.

//! @brief Get value of MLB_MIEN_CTX_PE from a register value.
#define BG_MLB_MIEN_CTX_PE(r)   (((r) & BM_MLB_MIEN_CTX_PE) >> BP_MLB_MIEN_CTX_PE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CTX_PE.
#define BF_MLB_MIEN_CTX_PE(v)   ((((reg32_t) v) << BP_MLB_MIEN_CTX_PE) & BM_MLB_MIEN_CTX_PE)
#else
//! @brief Format value for bitfield MLB_MIEN_CTX_PE.
#define BF_MLB_MIEN_CTX_PE(v)   (((v) << BP_MLB_MIEN_CTX_PE) & BM_MLB_MIEN_CTX_PE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTX_PE field to a new value.
#define BW_MLB_MIEN_CTX_PE(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CTX_PE) | BF_MLB_MIEN_CTX_PE(v)))
#endif

/* --- Register HW_MLB_MIEN, field CTX_BREAK[29] (RW)
 *
 * Control Tx break enable. When set, a ReceiverBreak response received from the receiver on a
 * control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
 */

#define BP_MLB_MIEN_CTX_BREAK      (29)      //!< Bit position for MLB_MIEN_CTX_BREAK.
#define BM_MLB_MIEN_CTX_BREAK      (0x20000000)  //!< Bit mask for MLB_MIEN_CTX_BREAK.

//! @brief Get value of MLB_MIEN_CTX_BREAK from a register value.
#define BG_MLB_MIEN_CTX_BREAK(r)   (((r) & BM_MLB_MIEN_CTX_BREAK) >> BP_MLB_MIEN_CTX_BREAK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MIEN_CTX_BREAK.
#define BF_MLB_MIEN_CTX_BREAK(v)   ((((reg32_t) v) << BP_MLB_MIEN_CTX_BREAK) & BM_MLB_MIEN_CTX_BREAK)
#else
//! @brief Format value for bitfield MLB_MIEN_CTX_BREAK.
#define BF_MLB_MIEN_CTX_BREAK(v)   (((v) << BP_MLB_MIEN_CTX_BREAK) & BM_MLB_MIEN_CTX_BREAK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTX_BREAK field to a new value.
#define BW_MLB_MIEN_CTX_BREAK(v)   (HW_MLB_MIEN_WR((HW_MLB_MIEN_RD() & ~BM_MLB_MIEN_CTX_BREAK) | BF_MLB_MIEN_CTX_BREAK(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MLBPC1 - MediaLB 6-pin Control 1 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mlbpc1
{
    reg32_t U;
    struct _hw_mlb_mlbpc1_bitfields
    {
        unsigned SDRCVBIAS : 4; //!< [3:0] Signal/Data receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_sig_data_rx_bias_ctl[3:0] output pin and has no internal function.
        unsigned SDXMTBIAS : 4; //!< [7:4] Signal/Data transmitter bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_sig_data_tx_bias_ctl[3:0] output pin and has no internal function.
        unsigned CKRCVBIAS : 4; //!< [11:8] Clock receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_clk_rx_bias_ctl[3:0] output pin and has no internal function.
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_mlb_mlbpc1_t;
#endif

/*
 * constants & macros for entire MLB_MLBPC1 register
 */
#define HW_MLB_MLBPC1_ADDR      (REGS_MLB_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBPC1           (*(volatile hw_mlb_mlbpc1_t *) HW_MLB_MLBPC1_ADDR)
#define HW_MLB_MLBPC1_RD()      (HW_MLB_MLBPC1.U)
#define HW_MLB_MLBPC1_WR(v)     (HW_MLB_MLBPC1.U = (v))
#define HW_MLB_MLBPC1_SET(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() |  (v)))
#define HW_MLB_MLBPC1_CLR(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() & ~(v)))
#define HW_MLB_MLBPC1_TOG(v)    (HW_MLB_MLBPC1_WR(HW_MLB_MLBPC1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MLBPC1 bitfields
 */

/* --- Register HW_MLB_MLBPC1, field SDRCVBIAS[3:0] (RW)
 *
 * Signal/Data receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when
 * MediaLB 6-pin is initialized (final value needs to be determined through characterization). This
 * value is driven on mlb_sig_data_rx_bias_ctl[3:0] output pin and has no internal function.
 */

#define BP_MLB_MLBPC1_SDRCVBIAS      (0)      //!< Bit position for MLB_MLBPC1_SDRCVBIAS.
#define BM_MLB_MLBPC1_SDRCVBIAS      (0x0000000f)  //!< Bit mask for MLB_MLBPC1_SDRCVBIAS.

//! @brief Get value of MLB_MLBPC1_SDRCVBIAS from a register value.
#define BG_MLB_MLBPC1_SDRCVBIAS(r)   (((r) & BM_MLB_MLBPC1_SDRCVBIAS) >> BP_MLB_MLBPC1_SDRCVBIAS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBPC1_SDRCVBIAS.
#define BF_MLB_MLBPC1_SDRCVBIAS(v)   ((((reg32_t) v) << BP_MLB_MLBPC1_SDRCVBIAS) & BM_MLB_MLBPC1_SDRCVBIAS)
#else
//! @brief Format value for bitfield MLB_MLBPC1_SDRCVBIAS.
#define BF_MLB_MLBPC1_SDRCVBIAS(v)   (((v) << BP_MLB_MLBPC1_SDRCVBIAS) & BM_MLB_MLBPC1_SDRCVBIAS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDRCVBIAS field to a new value.
#define BW_MLB_MLBPC1_SDRCVBIAS(v)   (HW_MLB_MLBPC1_WR((HW_MLB_MLBPC1_RD() & ~BM_MLB_MLBPC1_SDRCVBIAS) | BF_MLB_MLBPC1_SDRCVBIAS(v)))
#endif

/* --- Register HW_MLB_MLBPC1, field SDXMTBIAS[7:4] (RW)
 *
 * Signal/Data transmitter bias control (for MediaLB 6-pin interface). Must be written to 0xC when
 * MediaLB 6-pin is initialized (final value needs to be determined through characterization). This
 * value is driven on mlb_sig_data_tx_bias_ctl[3:0] output pin and has no internal function.
 */

#define BP_MLB_MLBPC1_SDXMTBIAS      (4)      //!< Bit position for MLB_MLBPC1_SDXMTBIAS.
#define BM_MLB_MLBPC1_SDXMTBIAS      (0x000000f0)  //!< Bit mask for MLB_MLBPC1_SDXMTBIAS.

//! @brief Get value of MLB_MLBPC1_SDXMTBIAS from a register value.
#define BG_MLB_MLBPC1_SDXMTBIAS(r)   (((r) & BM_MLB_MLBPC1_SDXMTBIAS) >> BP_MLB_MLBPC1_SDXMTBIAS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBPC1_SDXMTBIAS.
#define BF_MLB_MLBPC1_SDXMTBIAS(v)   ((((reg32_t) v) << BP_MLB_MLBPC1_SDXMTBIAS) & BM_MLB_MLBPC1_SDXMTBIAS)
#else
//! @brief Format value for bitfield MLB_MLBPC1_SDXMTBIAS.
#define BF_MLB_MLBPC1_SDXMTBIAS(v)   (((v) << BP_MLB_MLBPC1_SDXMTBIAS) & BM_MLB_MLBPC1_SDXMTBIAS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDXMTBIAS field to a new value.
#define BW_MLB_MLBPC1_SDXMTBIAS(v)   (HW_MLB_MLBPC1_WR((HW_MLB_MLBPC1_RD() & ~BM_MLB_MLBPC1_SDXMTBIAS) | BF_MLB_MLBPC1_SDXMTBIAS(v)))
#endif

/* --- Register HW_MLB_MLBPC1, field CKRCVBIAS[11:8] (RW)
 *
 * Clock receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB
 * 6-pin is initialized (final value needs to be determined through characterization). This value is
 * driven on mlb_clk_rx_bias_ctl[3:0] output pin and has no internal function.
 */

#define BP_MLB_MLBPC1_CKRCVBIAS      (8)      //!< Bit position for MLB_MLBPC1_CKRCVBIAS.
#define BM_MLB_MLBPC1_CKRCVBIAS      (0x00000f00)  //!< Bit mask for MLB_MLBPC1_CKRCVBIAS.

//! @brief Get value of MLB_MLBPC1_CKRCVBIAS from a register value.
#define BG_MLB_MLBPC1_CKRCVBIAS(r)   (((r) & BM_MLB_MLBPC1_CKRCVBIAS) >> BP_MLB_MLBPC1_CKRCVBIAS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MLBPC1_CKRCVBIAS.
#define BF_MLB_MLBPC1_CKRCVBIAS(v)   ((((reg32_t) v) << BP_MLB_MLBPC1_CKRCVBIAS) & BM_MLB_MLBPC1_CKRCVBIAS)
#else
//! @brief Format value for bitfield MLB_MLBPC1_CKRCVBIAS.
#define BF_MLB_MLBPC1_CKRCVBIAS(v)   (((v) << BP_MLB_MLBPC1_CKRCVBIAS) & BM_MLB_MLBPC1_CKRCVBIAS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKRCVBIAS field to a new value.
#define BW_MLB_MLBPC1_CKRCVBIAS(v)   (HW_MLB_MLBPC1_WR((HW_MLB_MLBPC1_RD() & ~BM_MLB_MLBPC1_CKRCVBIAS) | BF_MLB_MLBPC1_CKRCVBIAS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MLBC1 - MediaLB Control 1 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mlbc1
{
    reg32_t U;
    struct _hw_mlb_mlbc1_bitfields
    {
        unsigned RESERVED0 : 6; //!< [5:0] Reserved
        unsigned LOCK : 1; //!< [6] MediaLB lock error status. Set when MediaLB is unlocked; cleared by software.
        unsigned CLKM : 1; //!< [7] MediaLB clock missing status. Set when MediaLB clock is not toggling at the pin; cleared by software.
        unsigned NDA : 8; //!< [15:8] Node device address. Used for system commands directed to individual MediaLB nodes.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_mlb_mlbc1_t;
#endif

/*
 * constants & macros for entire MLB_MLBC1 register
 */
#define HW_MLB_MLBC1_ADDR      (REGS_MLB_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MLBC1           (*(volatile hw_mlb_mlbc1_t *) HW_MLB_MLBC1_ADDR)
#define HW_MLB_MLBC1_RD()      (HW_MLB_MLBC1.U)
#endif

/*
 * constants & macros for individual MLB_MLBC1 bitfields
 */

/* --- Register HW_MLB_MLBC1, field LOCK[6] (RO)
 *
 * MediaLB lock error status. Set when MediaLB is unlocked; cleared by software.
 */

#define BP_MLB_MLBC1_LOCK      (6)      //!< Bit position for MLB_MLBC1_LOCK.
#define BM_MLB_MLBC1_LOCK      (0x00000040)  //!< Bit mask for MLB_MLBC1_LOCK.

//! @brief Get value of MLB_MLBC1_LOCK from a register value.
#define BG_MLB_MLBC1_LOCK(r)   (((r) & BM_MLB_MLBC1_LOCK) >> BP_MLB_MLBC1_LOCK)

/* --- Register HW_MLB_MLBC1, field CLKM[7] (RO)
 *
 * MediaLB clock missing status. Set when MediaLB clock is not toggling at the pin; cleared by
 * software.
 */

#define BP_MLB_MLBC1_CLKM      (7)      //!< Bit position for MLB_MLBC1_CLKM.
#define BM_MLB_MLBC1_CLKM      (0x00000080)  //!< Bit mask for MLB_MLBC1_CLKM.

//! @brief Get value of MLB_MLBC1_CLKM from a register value.
#define BG_MLB_MLBC1_CLKM(r)   (((r) & BM_MLB_MLBC1_CLKM) >> BP_MLB_MLBC1_CLKM)

/* --- Register HW_MLB_MLBC1, field NDA[15:8] (RW)
 *
 * Node device address. Used for system commands directed to individual MediaLB nodes.
 */

#define BP_MLB_MLBC1_NDA      (8)      //!< Bit position for MLB_MLBC1_NDA.
#define BM_MLB_MLBC1_NDA      (0x0000ff00)  //!< Bit mask for MLB_MLBC1_NDA.

//! @brief Get value of MLB_MLBC1_NDA from a register value.
#define BG_MLB_MLBC1_NDA(r)   (((r) & BM_MLB_MLBC1_NDA) >> BP_MLB_MLBC1_NDA)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCTL - HBI Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The HC can control and monitor general operation of the HBI block by reading and writing the HBI
 * Control Register (HCTL) through the I/O interface. Each bit of HCTL is read/write.
 */
typedef union _hw_mlb_hctl
{
    reg32_t U;
    struct _hw_mlb_hctl_bitfields
    {
        unsigned RST0 : 1; //!< [0] AGU0 software reset
        unsigned RST1 : 1; //!< [1] AGU1 software reset
        unsigned RESERVED0 : 13; //!< [14:2] Reserved
        unsigned EN : 1; //!< [15] HBI enable
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_mlb_hctl_t;
#endif

/*
 * constants & macros for entire MLB_HCTL register
 */
#define HW_MLB_HCTL_ADDR      (REGS_MLB_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCTL           (*(volatile hw_mlb_hctl_t *) HW_MLB_HCTL_ADDR)
#define HW_MLB_HCTL_RD()      (HW_MLB_HCTL.U)
#define HW_MLB_HCTL_WR(v)     (HW_MLB_HCTL.U = (v))
#define HW_MLB_HCTL_SET(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() |  (v)))
#define HW_MLB_HCTL_CLR(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() & ~(v)))
#define HW_MLB_HCTL_TOG(v)    (HW_MLB_HCTL_WR(HW_MLB_HCTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_HCTL bitfields
 */

/* --- Register HW_MLB_HCTL, field RST0[0] (RW)
 *
 * AGU0 software reset
 *
 * Values:
 * 0 - active
 * 1 - reset
 */

#define BP_MLB_HCTL_RST0      (0)      //!< Bit position for MLB_HCTL_RST0.
#define BM_MLB_HCTL_RST0      (0x00000001)  //!< Bit mask for MLB_HCTL_RST0.

//! @brief Get value of MLB_HCTL_RST0 from a register value.
#define BG_MLB_HCTL_RST0(r)   (((r) & BM_MLB_HCTL_RST0) >> BP_MLB_HCTL_RST0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_HCTL_RST0.
#define BF_MLB_HCTL_RST0(v)   ((((reg32_t) v) << BP_MLB_HCTL_RST0) & BM_MLB_HCTL_RST0)
#else
//! @brief Format value for bitfield MLB_HCTL_RST0.
#define BF_MLB_HCTL_RST0(v)   (((v) << BP_MLB_HCTL_RST0) & BM_MLB_HCTL_RST0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RST0 field to a new value.
#define BW_MLB_HCTL_RST0(v)   (HW_MLB_HCTL_WR((HW_MLB_HCTL_RD() & ~BM_MLB_HCTL_RST0) | BF_MLB_HCTL_RST0(v)))
#endif


/* --- Register HW_MLB_HCTL, field RST1[1] (RW)
 *
 * AGU1 software reset
 *
 * Values:
 * 0 - active
 * 1 - reset
 */

#define BP_MLB_HCTL_RST1      (1)      //!< Bit position for MLB_HCTL_RST1.
#define BM_MLB_HCTL_RST1      (0x00000002)  //!< Bit mask for MLB_HCTL_RST1.

//! @brief Get value of MLB_HCTL_RST1 from a register value.
#define BG_MLB_HCTL_RST1(r)   (((r) & BM_MLB_HCTL_RST1) >> BP_MLB_HCTL_RST1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_HCTL_RST1.
#define BF_MLB_HCTL_RST1(v)   ((((reg32_t) v) << BP_MLB_HCTL_RST1) & BM_MLB_HCTL_RST1)
#else
//! @brief Format value for bitfield MLB_HCTL_RST1.
#define BF_MLB_HCTL_RST1(v)   (((v) << BP_MLB_HCTL_RST1) & BM_MLB_HCTL_RST1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RST1 field to a new value.
#define BW_MLB_HCTL_RST1(v)   (HW_MLB_HCTL_WR((HW_MLB_HCTL_RD() & ~BM_MLB_HCTL_RST1) | BF_MLB_HCTL_RST1(v)))
#endif


/* --- Register HW_MLB_HCTL, field EN[15] (RW)
 *
 * HBI enable
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_MLB_HCTL_EN      (15)      //!< Bit position for MLB_HCTL_EN.
#define BM_MLB_HCTL_EN      (0x00008000)  //!< Bit mask for MLB_HCTL_EN.

//! @brief Get value of MLB_HCTL_EN from a register value.
#define BG_MLB_HCTL_EN(r)   (((r) & BM_MLB_HCTL_EN) >> BP_MLB_HCTL_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_HCTL_EN.
#define BF_MLB_HCTL_EN(v)   ((((reg32_t) v) << BP_MLB_HCTL_EN) & BM_MLB_HCTL_EN)
#else
//! @brief Format value for bitfield MLB_HCTL_EN.
#define BF_MLB_HCTL_EN(v)   (((v) << BP_MLB_HCTL_EN) & BM_MLB_HCTL_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_MLB_HCTL_EN(v)   (HW_MLB_HCTL_WR((HW_MLB_HCTL_RD() & ~BM_MLB_HCTL_EN) | BF_MLB_HCTL_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCMR0 - HBI Channel Mask 0 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The HC can control which channel(s) are able to generate an HBI interrupt by writing the HBI
 * Channel Mask Registers (HCMRn). The HCMRn registers mask the channel interrupt on the hbi_hintb
 * signal (i.e. hbi_hintb will not become active for any masked channel). Each bit of HCMRn is
 * read/write.
 */
typedef union _hw_mlb_hcmr0
{
    reg32_t U;
    struct _hw_mlb_hcmr0_bitfields
    {
        unsigned CHM : 32; //!< [31:0] Bitwise channel mask bit
    } B;
} hw_mlb_hcmr0_t;
#endif

/*
 * constants & macros for entire MLB_HCMR0 register
 */
#define HW_MLB_HCMR0_ADDR      (REGS_MLB_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCMR0           (*(volatile hw_mlb_hcmr0_t *) HW_MLB_HCMR0_ADDR)
#define HW_MLB_HCMR0_RD()      (HW_MLB_HCMR0.U)
#define HW_MLB_HCMR0_WR(v)     (HW_MLB_HCMR0.U = (v))
#define HW_MLB_HCMR0_SET(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() |  (v)))
#define HW_MLB_HCMR0_CLR(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() & ~(v)))
#define HW_MLB_HCMR0_TOG(v)    (HW_MLB_HCMR0_WR(HW_MLB_HCMR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_HCMR0 bitfields
 */

/* --- Register HW_MLB_HCMR0, field CHM[31:0] (RW)
 *
 * Bitwise channel mask bit
 *
 * Values:
 * 0 - masked
 * 1 - unmasked
 */

#define BP_MLB_HCMR0_CHM      (0)      //!< Bit position for MLB_HCMR0_CHM.
#define BM_MLB_HCMR0_CHM      (0xffffffff)  //!< Bit mask for MLB_HCMR0_CHM.

//! @brief Get value of MLB_HCMR0_CHM from a register value.
#define BG_MLB_HCMR0_CHM(r)   (((r) & BM_MLB_HCMR0_CHM) >> BP_MLB_HCMR0_CHM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_HCMR0_CHM.
#define BF_MLB_HCMR0_CHM(v)   ((((reg32_t) v) << BP_MLB_HCMR0_CHM) & BM_MLB_HCMR0_CHM)
#else
//! @brief Format value for bitfield MLB_HCMR0_CHM.
#define BF_MLB_HCMR0_CHM(v)   (((v) << BP_MLB_HCMR0_CHM) & BM_MLB_HCMR0_CHM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHM field to a new value.
#define BW_MLB_HCMR0_CHM(v)   (HW_MLB_HCMR0_WR((HW_MLB_HCMR0_RD() & ~BM_MLB_HCMR0_CHM) | BF_MLB_HCMR0_CHM(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCMR1 - HBI Channel Mask 1 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_hcmr1
{
    reg32_t U;
    struct _hw_mlb_hcmr1_bitfields
    {
        unsigned CHM : 32; //!< [31:0] Bitwise channel mask bit
    } B;
} hw_mlb_hcmr1_t;
#endif

/*
 * constants & macros for entire MLB_HCMR1 register
 */
#define HW_MLB_HCMR1_ADDR      (REGS_MLB_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCMR1           (*(volatile hw_mlb_hcmr1_t *) HW_MLB_HCMR1_ADDR)
#define HW_MLB_HCMR1_RD()      (HW_MLB_HCMR1.U)
#define HW_MLB_HCMR1_WR(v)     (HW_MLB_HCMR1.U = (v))
#define HW_MLB_HCMR1_SET(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() |  (v)))
#define HW_MLB_HCMR1_CLR(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() & ~(v)))
#define HW_MLB_HCMR1_TOG(v)    (HW_MLB_HCMR1_WR(HW_MLB_HCMR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_HCMR1 bitfields
 */

/* --- Register HW_MLB_HCMR1, field CHM[31:0] (RW)
 *
 * Bitwise channel mask bit
 *
 * Values:
 * 0 - masked
 * 1 - unmasked
 */

#define BP_MLB_HCMR1_CHM      (0)      //!< Bit position for MLB_HCMR1_CHM.
#define BM_MLB_HCMR1_CHM      (0xffffffff)  //!< Bit mask for MLB_HCMR1_CHM.

//! @brief Get value of MLB_HCMR1_CHM from a register value.
#define BG_MLB_HCMR1_CHM(r)   (((r) & BM_MLB_HCMR1_CHM) >> BP_MLB_HCMR1_CHM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_HCMR1_CHM.
#define BF_MLB_HCMR1_CHM(v)   ((((reg32_t) v) << BP_MLB_HCMR1_CHM) & BM_MLB_HCMR1_CHM)
#else
//! @brief Format value for bitfield MLB_HCMR1_CHM.
#define BF_MLB_HCMR1_CHM(v)   (((v) << BP_MLB_HCMR1_CHM) & BM_MLB_HCMR1_CHM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHM field to a new value.
#define BW_MLB_HCMR1_CHM(v)   (HW_MLB_HCMR1_WR((HW_MLB_HCMR1_RD() & ~BM_MLB_HCMR1_CHM) | BF_MLB_HCMR1_CHM(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCER0 - HBI Channel Error 0 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The HBI Channel Error Registers (HCERn) indicate which channel(s) have encountered fatal errors.
 */
typedef union _hw_mlb_hcer0
{
    reg32_t U;
    struct _hw_mlb_hcer0_bitfields
    {
        unsigned CERR : 32; //!< [31:0] Bitwise channel error bit
    } B;
} hw_mlb_hcer0_t;
#endif

/*
 * constants & macros for entire MLB_HCER0 register
 */
#define HW_MLB_HCER0_ADDR      (REGS_MLB_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCER0           (*(volatile hw_mlb_hcer0_t *) HW_MLB_HCER0_ADDR)
#define HW_MLB_HCER0_RD()      (HW_MLB_HCER0.U)
#endif

/*
 * constants & macros for individual MLB_HCER0 bitfields
 */

/* --- Register HW_MLB_HCER0, field CERR[31:0] (RO)
 *
 * Bitwise channel error bit
 */

#define BP_MLB_HCER0_CERR      (0)      //!< Bit position for MLB_HCER0_CERR.
#define BM_MLB_HCER0_CERR      (0xffffffff)  //!< Bit mask for MLB_HCER0_CERR.

//! @brief Get value of MLB_HCER0_CERR from a register value.
#define BG_MLB_HCER0_CERR(r)   (((r) & BM_MLB_HCER0_CERR) >> BP_MLB_HCER0_CERR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCER1 - HBI Channel Error 1 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * HCERn status bits are set when hardware detects hardware errors on the given logical channel,
 * including:   Channel opened, but not enabled,  Channel programmed with invalid channel type, or
 * Out-of-range PML for asynchronous or control Tx channels
 */
typedef union _hw_mlb_hcer1
{
    reg32_t U;
    struct _hw_mlb_hcer1_bitfields
    {
        unsigned CERR : 32; //!< [31:0] Bitwise channel error bit
    } B;
} hw_mlb_hcer1_t;
#endif

/*
 * constants & macros for entire MLB_HCER1 register
 */
#define HW_MLB_HCER1_ADDR      (REGS_MLB_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCER1           (*(volatile hw_mlb_hcer1_t *) HW_MLB_HCER1_ADDR)
#define HW_MLB_HCER1_RD()      (HW_MLB_HCER1.U)
#endif

/*
 * constants & macros for individual MLB_HCER1 bitfields
 */

/* --- Register HW_MLB_HCER1, field CERR[31:0] (RO)
 *
 * Bitwise channel error bit
 */

#define BP_MLB_HCER1_CERR      (0)      //!< Bit position for MLB_HCER1_CERR.
#define BM_MLB_HCER1_CERR      (0xffffffff)  //!< Bit mask for MLB_HCER1_CERR.

//! @brief Get value of MLB_HCER1_CERR from a register value.
#define BG_MLB_HCER1_CERR(r)   (((r) & BM_MLB_HCER1_CERR) >> BP_MLB_HCER1_CERR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCBR0 - HBI Channel Busy 0 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The HC can determine which channel(s) are busy by reading the HBI Channel Busy Registers (HCBRn).
 * An HBI channel is busy if:   it is currently loaded into one of the two AGUs  the channel is
 * enabled, CE = 1 from the Channel Allocation Table ( ), and  the DMA is active   When an HBI
 * channel is busy, hardware may write back its local copy of the channel descriptor at any time.
 * System software should not write a CDT descriptor for a channel that is busy. Only two HBI
 * channels can be busy at any given time. Each bit of HCBRn is read-only.
 */
typedef union _hw_mlb_hcbr0
{
    reg32_t U;
    struct _hw_mlb_hcbr0_bitfields
    {
        unsigned CHB : 32; //!< [31:0] Bitwise channel busy bit
    } B;
} hw_mlb_hcbr0_t;
#endif

/*
 * constants & macros for entire MLB_HCBR0 register
 */
#define HW_MLB_HCBR0_ADDR      (REGS_MLB_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCBR0           (*(volatile hw_mlb_hcbr0_t *) HW_MLB_HCBR0_ADDR)
#define HW_MLB_HCBR0_RD()      (HW_MLB_HCBR0.U)
#endif

/*
 * constants & macros for individual MLB_HCBR0 bitfields
 */

/* --- Register HW_MLB_HCBR0, field CHB[31:0] (RO)
 *
 * Bitwise channel busy bit
 *
 * Values:
 * 0 - idle
 * 1 - busy
 */

#define BP_MLB_HCBR0_CHB      (0)      //!< Bit position for MLB_HCBR0_CHB.
#define BM_MLB_HCBR0_CHB      (0xffffffff)  //!< Bit mask for MLB_HCBR0_CHB.

//! @brief Get value of MLB_HCBR0_CHB from a register value.
#define BG_MLB_HCBR0_CHB(r)   (((r) & BM_MLB_HCBR0_CHB) >> BP_MLB_HCBR0_CHB)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_HCBR1 - HBI Channel Busy 1 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_hcbr1
{
    reg32_t U;
    struct _hw_mlb_hcbr1_bitfields
    {
        unsigned CHB : 32; //!< [31:0] Bitwise channel busy bit
    } B;
} hw_mlb_hcbr1_t;
#endif

/*
 * constants & macros for entire MLB_HCBR1 register
 */
#define HW_MLB_HCBR1_ADDR      (REGS_MLB_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_HCBR1           (*(volatile hw_mlb_hcbr1_t *) HW_MLB_HCBR1_ADDR)
#define HW_MLB_HCBR1_RD()      (HW_MLB_HCBR1.U)
#endif

/*
 * constants & macros for individual MLB_HCBR1 bitfields
 */

/* --- Register HW_MLB_HCBR1, field CHB[31:0] (RO)
 *
 * Bitwise channel busy bit
 *
 * Values:
 * 0 - idle
 * 1 - busy
 */

#define BP_MLB_HCBR1_CHB      (0)      //!< Bit position for MLB_HCBR1_CHB.
#define BM_MLB_HCBR1_CHB      (0xffffffff)  //!< Bit mask for MLB_HCBR1_CHB.

//! @brief Get value of MLB_HCBR1_CHB from a register value.
#define BG_MLB_HCBR1_CHB(r)   (((r) & BM_MLB_HCBR1_CHB) >> BP_MLB_HCBR1_CHB)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDAT0 - MIF Data 0 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdat0
{
    reg32_t U;
    struct _hw_mlb_mdat0_bitfields
    {
        unsigned DATA : 32; //!< [31:0] CTR data - bits[31:0] of 128-bit entry or DBR data - bits[7:0] of 8-bit entry
    } B;
} hw_mlb_mdat0_t;
#endif

/*
 * constants & macros for entire MLB_MDAT0 register
 */
#define HW_MLB_MDAT0_ADDR      (REGS_MLB_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT0           (*(volatile hw_mlb_mdat0_t *) HW_MLB_MDAT0_ADDR)
#define HW_MLB_MDAT0_RD()      (HW_MLB_MDAT0.U)
#define HW_MLB_MDAT0_WR(v)     (HW_MLB_MDAT0.U = (v))
#define HW_MLB_MDAT0_SET(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() |  (v)))
#define HW_MLB_MDAT0_CLR(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() & ~(v)))
#define HW_MLB_MDAT0_TOG(v)    (HW_MLB_MDAT0_WR(HW_MLB_MDAT0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDAT0 bitfields
 */

/* --- Register HW_MLB_MDAT0, field DATA[31:0] (RW)
 *
 * CTR data - bits[31:0] of 128-bit entry or DBR data - bits[7:0] of 8-bit entry
 */

#define BP_MLB_MDAT0_DATA      (0)      //!< Bit position for MLB_MDAT0_DATA.
#define BM_MLB_MDAT0_DATA      (0xffffffff)  //!< Bit mask for MLB_MDAT0_DATA.

//! @brief Get value of MLB_MDAT0_DATA from a register value.
#define BG_MLB_MDAT0_DATA(r)   (((r) & BM_MLB_MDAT0_DATA) >> BP_MLB_MDAT0_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDAT0_DATA.
#define BF_MLB_MDAT0_DATA(v)   ((((reg32_t) v) << BP_MLB_MDAT0_DATA) & BM_MLB_MDAT0_DATA)
#else
//! @brief Format value for bitfield MLB_MDAT0_DATA.
#define BF_MLB_MDAT0_DATA(v)   (((v) << BP_MLB_MDAT0_DATA) & BM_MLB_MDAT0_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MLB_MDAT0_DATA(v)   (HW_MLB_MDAT0_WR((HW_MLB_MDAT0_RD() & ~BM_MLB_MDAT0_DATA) | BF_MLB_MDAT0_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDAT1 - MIF Data 1 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdat1
{
    reg32_t U;
    struct _hw_mlb_mdat1_bitfields
    {
        unsigned DATA : 32; //!< [31:0] CTR data - bits[63:32] of 128-bit entry
    } B;
} hw_mlb_mdat1_t;
#endif

/*
 * constants & macros for entire MLB_MDAT1 register
 */
#define HW_MLB_MDAT1_ADDR      (REGS_MLB_BASE + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT1           (*(volatile hw_mlb_mdat1_t *) HW_MLB_MDAT1_ADDR)
#define HW_MLB_MDAT1_RD()      (HW_MLB_MDAT1.U)
#define HW_MLB_MDAT1_WR(v)     (HW_MLB_MDAT1.U = (v))
#define HW_MLB_MDAT1_SET(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() |  (v)))
#define HW_MLB_MDAT1_CLR(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() & ~(v)))
#define HW_MLB_MDAT1_TOG(v)    (HW_MLB_MDAT1_WR(HW_MLB_MDAT1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDAT1 bitfields
 */

/* --- Register HW_MLB_MDAT1, field DATA[31:0] (RW)
 *
 * CTR data - bits[63:32] of 128-bit entry
 */

#define BP_MLB_MDAT1_DATA      (0)      //!< Bit position for MLB_MDAT1_DATA.
#define BM_MLB_MDAT1_DATA      (0xffffffff)  //!< Bit mask for MLB_MDAT1_DATA.

//! @brief Get value of MLB_MDAT1_DATA from a register value.
#define BG_MLB_MDAT1_DATA(r)   (((r) & BM_MLB_MDAT1_DATA) >> BP_MLB_MDAT1_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDAT1_DATA.
#define BF_MLB_MDAT1_DATA(v)   ((((reg32_t) v) << BP_MLB_MDAT1_DATA) & BM_MLB_MDAT1_DATA)
#else
//! @brief Format value for bitfield MLB_MDAT1_DATA.
#define BF_MLB_MDAT1_DATA(v)   (((v) << BP_MLB_MDAT1_DATA) & BM_MLB_MDAT1_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MLB_MDAT1_DATA(v)   (HW_MLB_MDAT1_WR((HW_MLB_MDAT1_RD() & ~BM_MLB_MDAT1_DATA) | BF_MLB_MDAT1_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDAT2 - MIF Data 2 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdat2
{
    reg32_t U;
    struct _hw_mlb_mdat2_bitfields
    {
        unsigned DATA : 32; //!< [31:0] CTR data - bits[95:64] of 128-bit entry
    } B;
} hw_mlb_mdat2_t;
#endif

/*
 * constants & macros for entire MLB_MDAT2 register
 */
#define HW_MLB_MDAT2_ADDR      (REGS_MLB_BASE + 0xc8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT2           (*(volatile hw_mlb_mdat2_t *) HW_MLB_MDAT2_ADDR)
#define HW_MLB_MDAT2_RD()      (HW_MLB_MDAT2.U)
#define HW_MLB_MDAT2_WR(v)     (HW_MLB_MDAT2.U = (v))
#define HW_MLB_MDAT2_SET(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() |  (v)))
#define HW_MLB_MDAT2_CLR(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() & ~(v)))
#define HW_MLB_MDAT2_TOG(v)    (HW_MLB_MDAT2_WR(HW_MLB_MDAT2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDAT2 bitfields
 */

/* --- Register HW_MLB_MDAT2, field DATA[31:0] (RW)
 *
 * CTR data - bits[95:64] of 128-bit entry
 */

#define BP_MLB_MDAT2_DATA      (0)      //!< Bit position for MLB_MDAT2_DATA.
#define BM_MLB_MDAT2_DATA      (0xffffffff)  //!< Bit mask for MLB_MDAT2_DATA.

//! @brief Get value of MLB_MDAT2_DATA from a register value.
#define BG_MLB_MDAT2_DATA(r)   (((r) & BM_MLB_MDAT2_DATA) >> BP_MLB_MDAT2_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDAT2_DATA.
#define BF_MLB_MDAT2_DATA(v)   ((((reg32_t) v) << BP_MLB_MDAT2_DATA) & BM_MLB_MDAT2_DATA)
#else
//! @brief Format value for bitfield MLB_MDAT2_DATA.
#define BF_MLB_MDAT2_DATA(v)   (((v) << BP_MLB_MDAT2_DATA) & BM_MLB_MDAT2_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MLB_MDAT2_DATA(v)   (HW_MLB_MDAT2_WR((HW_MLB_MDAT2_RD() & ~BM_MLB_MDAT2_DATA) | BF_MLB_MDAT2_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDAT3 - MIF Data 3 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdat3
{
    reg32_t U;
    struct _hw_mlb_mdat3_bitfields
    {
        unsigned DATA : 32; //!< [31:0] CTR data - bits[127:96] of 128-bit entry
    } B;
} hw_mlb_mdat3_t;
#endif

/*
 * constants & macros for entire MLB_MDAT3 register
 */
#define HW_MLB_MDAT3_ADDR      (REGS_MLB_BASE + 0xcc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDAT3           (*(volatile hw_mlb_mdat3_t *) HW_MLB_MDAT3_ADDR)
#define HW_MLB_MDAT3_RD()      (HW_MLB_MDAT3.U)
#define HW_MLB_MDAT3_WR(v)     (HW_MLB_MDAT3.U = (v))
#define HW_MLB_MDAT3_SET(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() |  (v)))
#define HW_MLB_MDAT3_CLR(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() & ~(v)))
#define HW_MLB_MDAT3_TOG(v)    (HW_MLB_MDAT3_WR(HW_MLB_MDAT3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDAT3 bitfields
 */

/* --- Register HW_MLB_MDAT3, field DATA[31:0] (RW)
 *
 * CTR data - bits[127:96] of 128-bit entry
 */

#define BP_MLB_MDAT3_DATA      (0)      //!< Bit position for MLB_MDAT3_DATA.
#define BM_MLB_MDAT3_DATA      (0xffffffff)  //!< Bit mask for MLB_MDAT3_DATA.

//! @brief Get value of MLB_MDAT3_DATA from a register value.
#define BG_MLB_MDAT3_DATA(r)   (((r) & BM_MLB_MDAT3_DATA) >> BP_MLB_MDAT3_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDAT3_DATA.
#define BF_MLB_MDAT3_DATA(v)   ((((reg32_t) v) << BP_MLB_MDAT3_DATA) & BM_MLB_MDAT3_DATA)
#else
//! @brief Format value for bitfield MLB_MDAT3_DATA.
#define BF_MLB_MDAT3_DATA(v)   (((v) << BP_MLB_MDAT3_DATA) & BM_MLB_MDAT3_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_MLB_MDAT3_DATA(v)   (HW_MLB_MDAT3_WR((HW_MLB_MDAT3_RD() & ~BM_MLB_MDAT3_DATA) | BF_MLB_MDAT3_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDWE0 - MIF Data Write Enable 0 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdwe0
{
    reg32_t U;
    struct _hw_mlb_mdwe0_bitfields
    {
        unsigned MASK : 32; //!< [31:0] Bitwise write enable for CTR data - bits[31:0]
    } B;
} hw_mlb_mdwe0_t;
#endif

/*
 * constants & macros for entire MLB_MDWE0 register
 */
#define HW_MLB_MDWE0_ADDR      (REGS_MLB_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE0           (*(volatile hw_mlb_mdwe0_t *) HW_MLB_MDWE0_ADDR)
#define HW_MLB_MDWE0_RD()      (HW_MLB_MDWE0.U)
#define HW_MLB_MDWE0_WR(v)     (HW_MLB_MDWE0.U = (v))
#define HW_MLB_MDWE0_SET(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() |  (v)))
#define HW_MLB_MDWE0_CLR(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() & ~(v)))
#define HW_MLB_MDWE0_TOG(v)    (HW_MLB_MDWE0_WR(HW_MLB_MDWE0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDWE0 bitfields
 */

/* --- Register HW_MLB_MDWE0, field MASK[31:0] (RW)
 *
 * Bitwise write enable for CTR data - bits[31:0]
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_MLB_MDWE0_MASK      (0)      //!< Bit position for MLB_MDWE0_MASK.
#define BM_MLB_MDWE0_MASK      (0xffffffff)  //!< Bit mask for MLB_MDWE0_MASK.

//! @brief Get value of MLB_MDWE0_MASK from a register value.
#define BG_MLB_MDWE0_MASK(r)   (((r) & BM_MLB_MDWE0_MASK) >> BP_MLB_MDWE0_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDWE0_MASK.
#define BF_MLB_MDWE0_MASK(v)   ((((reg32_t) v) << BP_MLB_MDWE0_MASK) & BM_MLB_MDWE0_MASK)
#else
//! @brief Format value for bitfield MLB_MDWE0_MASK.
#define BF_MLB_MDWE0_MASK(v)   (((v) << BP_MLB_MDWE0_MASK) & BM_MLB_MDWE0_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK field to a new value.
#define BW_MLB_MDWE0_MASK(v)   (HW_MLB_MDWE0_WR((HW_MLB_MDWE0_RD() & ~BM_MLB_MDWE0_MASK) | BF_MLB_MDWE0_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDWE1 - MIF Data Write Enable 1 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdwe1
{
    reg32_t U;
    struct _hw_mlb_mdwe1_bitfields
    {
        unsigned MASK : 32; //!< [31:0] Bitwise write enable for CTR data - bits[63:32]
    } B;
} hw_mlb_mdwe1_t;
#endif

/*
 * constants & macros for entire MLB_MDWE1 register
 */
#define HW_MLB_MDWE1_ADDR      (REGS_MLB_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE1           (*(volatile hw_mlb_mdwe1_t *) HW_MLB_MDWE1_ADDR)
#define HW_MLB_MDWE1_RD()      (HW_MLB_MDWE1.U)
#define HW_MLB_MDWE1_WR(v)     (HW_MLB_MDWE1.U = (v))
#define HW_MLB_MDWE1_SET(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() |  (v)))
#define HW_MLB_MDWE1_CLR(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() & ~(v)))
#define HW_MLB_MDWE1_TOG(v)    (HW_MLB_MDWE1_WR(HW_MLB_MDWE1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDWE1 bitfields
 */

/* --- Register HW_MLB_MDWE1, field MASK[31:0] (RW)
 *
 * Bitwise write enable for CTR data - bits[63:32]
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_MLB_MDWE1_MASK      (0)      //!< Bit position for MLB_MDWE1_MASK.
#define BM_MLB_MDWE1_MASK      (0xffffffff)  //!< Bit mask for MLB_MDWE1_MASK.

//! @brief Get value of MLB_MDWE1_MASK from a register value.
#define BG_MLB_MDWE1_MASK(r)   (((r) & BM_MLB_MDWE1_MASK) >> BP_MLB_MDWE1_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDWE1_MASK.
#define BF_MLB_MDWE1_MASK(v)   ((((reg32_t) v) << BP_MLB_MDWE1_MASK) & BM_MLB_MDWE1_MASK)
#else
//! @brief Format value for bitfield MLB_MDWE1_MASK.
#define BF_MLB_MDWE1_MASK(v)   (((v) << BP_MLB_MDWE1_MASK) & BM_MLB_MDWE1_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK field to a new value.
#define BW_MLB_MDWE1_MASK(v)   (HW_MLB_MDWE1_WR((HW_MLB_MDWE1_RD() & ~BM_MLB_MDWE1_MASK) | BF_MLB_MDWE1_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDWE2 - MIF Data Write Enable 2 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdwe2
{
    reg32_t U;
    struct _hw_mlb_mdwe2_bitfields
    {
        unsigned MASK : 32; //!< [31:0] Bitwise write enable for CTR data - bits[95:64]
    } B;
} hw_mlb_mdwe2_t;
#endif

/*
 * constants & macros for entire MLB_MDWE2 register
 */
#define HW_MLB_MDWE2_ADDR      (REGS_MLB_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE2           (*(volatile hw_mlb_mdwe2_t *) HW_MLB_MDWE2_ADDR)
#define HW_MLB_MDWE2_RD()      (HW_MLB_MDWE2.U)
#define HW_MLB_MDWE2_WR(v)     (HW_MLB_MDWE2.U = (v))
#define HW_MLB_MDWE2_SET(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() |  (v)))
#define HW_MLB_MDWE2_CLR(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() & ~(v)))
#define HW_MLB_MDWE2_TOG(v)    (HW_MLB_MDWE2_WR(HW_MLB_MDWE2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDWE2 bitfields
 */

/* --- Register HW_MLB_MDWE2, field MASK[31:0] (RW)
 *
 * Bitwise write enable for CTR data - bits[95:64]
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_MLB_MDWE2_MASK      (0)      //!< Bit position for MLB_MDWE2_MASK.
#define BM_MLB_MDWE2_MASK      (0xffffffff)  //!< Bit mask for MLB_MDWE2_MASK.

//! @brief Get value of MLB_MDWE2_MASK from a register value.
#define BG_MLB_MDWE2_MASK(r)   (((r) & BM_MLB_MDWE2_MASK) >> BP_MLB_MDWE2_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDWE2_MASK.
#define BF_MLB_MDWE2_MASK(v)   ((((reg32_t) v) << BP_MLB_MDWE2_MASK) & BM_MLB_MDWE2_MASK)
#else
//! @brief Format value for bitfield MLB_MDWE2_MASK.
#define BF_MLB_MDWE2_MASK(v)   (((v) << BP_MLB_MDWE2_MASK) & BM_MLB_MDWE2_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK field to a new value.
#define BW_MLB_MDWE2_MASK(v)   (HW_MLB_MDWE2_WR((HW_MLB_MDWE2_RD() & ~BM_MLB_MDWE2_MASK) | BF_MLB_MDWE2_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MDWE3 - MIF Data Write Enable 3 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mdwe3
{
    reg32_t U;
    struct _hw_mlb_mdwe3_bitfields
    {
        unsigned MASK : 32; //!< [31:0] Bitwise write enable for CTR data - bits[127:96]
    } B;
} hw_mlb_mdwe3_t;
#endif

/*
 * constants & macros for entire MLB_MDWE3 register
 */
#define HW_MLB_MDWE3_ADDR      (REGS_MLB_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MDWE3           (*(volatile hw_mlb_mdwe3_t *) HW_MLB_MDWE3_ADDR)
#define HW_MLB_MDWE3_RD()      (HW_MLB_MDWE3.U)
#define HW_MLB_MDWE3_WR(v)     (HW_MLB_MDWE3.U = (v))
#define HW_MLB_MDWE3_SET(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() |  (v)))
#define HW_MLB_MDWE3_CLR(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() & ~(v)))
#define HW_MLB_MDWE3_TOG(v)    (HW_MLB_MDWE3_WR(HW_MLB_MDWE3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MDWE3 bitfields
 */

/* --- Register HW_MLB_MDWE3, field MASK[31:0] (RW)
 *
 * Bitwise write enable for CTR data - bits[127:96]
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_MLB_MDWE3_MASK      (0)      //!< Bit position for MLB_MDWE3_MASK.
#define BM_MLB_MDWE3_MASK      (0xffffffff)  //!< Bit mask for MLB_MDWE3_MASK.

//! @brief Get value of MLB_MDWE3_MASK from a register value.
#define BG_MLB_MDWE3_MASK(r)   (((r) & BM_MLB_MDWE3_MASK) >> BP_MLB_MDWE3_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MDWE3_MASK.
#define BF_MLB_MDWE3_MASK(v)   ((((reg32_t) v) << BP_MLB_MDWE3_MASK) & BM_MLB_MDWE3_MASK)
#else
//! @brief Format value for bitfield MLB_MDWE3_MASK.
#define BF_MLB_MDWE3_MASK(v)   (((v) << BP_MLB_MDWE3_MASK) & BM_MLB_MDWE3_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK field to a new value.
#define BW_MLB_MDWE3_MASK(v)   (HW_MLB_MDWE3_WR((HW_MLB_MDWE3_RD() & ~BM_MLB_MDWE3_MASK) | BF_MLB_MDWE3_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MCTL - MIF Control Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_mctl
{
    reg32_t U;
    struct _hw_mlb_mctl_bitfields
    {
        unsigned XCMP : 1; //!< [0] Transfer complete (write 0 to clear)
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_mlb_mctl_t;
#endif

/*
 * constants & macros for entire MLB_MCTL register
 */
#define HW_MLB_MCTL_ADDR      (REGS_MLB_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MCTL           (*(volatile hw_mlb_mctl_t *) HW_MLB_MCTL_ADDR)
#define HW_MLB_MCTL_RD()      (HW_MLB_MCTL.U)
#endif

/*
 * constants & macros for individual MLB_MCTL bitfields
 */

/* --- Register HW_MLB_MCTL, field XCMP[0] (RO)
 *
 * Transfer complete (write 0 to clear)
 */

#define BP_MLB_MCTL_XCMP      (0)      //!< Bit position for MLB_MCTL_XCMP.
#define BM_MLB_MCTL_XCMP      (0x00000001)  //!< Bit mask for MLB_MCTL_XCMP.

//! @brief Get value of MLB_MCTL_XCMP from a register value.
#define BG_MLB_MCTL_XCMP(r)   (((r) & BM_MLB_MCTL_XCMP) >> BP_MLB_MCTL_XCMP)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_MADR - MIF Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_madr
{
    reg32_t U;
    struct _hw_mlb_madr_bitfields
    {
        unsigned ADDR : 8; //!< [7:0] CTR address of 128-bit entry or DBR address of 8-bit entry - bits[7:0]
        unsigned ADDR1 : 6; //!< [13:8] DBR address of 8-bit entry - bits[13:8]
        unsigned RESERVED0 : 16; //!< [29:14] Reserved
        unsigned TB : 1; //!< [30] Target location bit
        unsigned WNR : 1; //!< [31] Write-Not-Read selection
    } B;
} hw_mlb_madr_t;
#endif

/*
 * constants & macros for entire MLB_MADR register
 */
#define HW_MLB_MADR_ADDR      (REGS_MLB_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_MADR           (*(volatile hw_mlb_madr_t *) HW_MLB_MADR_ADDR)
#define HW_MLB_MADR_RD()      (HW_MLB_MADR.U)
#define HW_MLB_MADR_WR(v)     (HW_MLB_MADR.U = (v))
#define HW_MLB_MADR_SET(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() |  (v)))
#define HW_MLB_MADR_CLR(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() & ~(v)))
#define HW_MLB_MADR_TOG(v)    (HW_MLB_MADR_WR(HW_MLB_MADR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_MADR bitfields
 */

/* --- Register HW_MLB_MADR, field ADDR[7:0] (RW)
 *
 * CTR address of 128-bit entry or DBR address of 8-bit entry - bits[7:0]
 */

#define BP_MLB_MADR_ADDR      (0)      //!< Bit position for MLB_MADR_ADDR.
#define BM_MLB_MADR_ADDR      (0x000000ff)  //!< Bit mask for MLB_MADR_ADDR.

//! @brief Get value of MLB_MADR_ADDR from a register value.
#define BG_MLB_MADR_ADDR(r)   (((r) & BM_MLB_MADR_ADDR) >> BP_MLB_MADR_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MADR_ADDR.
#define BF_MLB_MADR_ADDR(v)   ((((reg32_t) v) << BP_MLB_MADR_ADDR) & BM_MLB_MADR_ADDR)
#else
//! @brief Format value for bitfield MLB_MADR_ADDR.
#define BF_MLB_MADR_ADDR(v)   (((v) << BP_MLB_MADR_ADDR) & BM_MLB_MADR_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_MLB_MADR_ADDR(v)   (HW_MLB_MADR_WR((HW_MLB_MADR_RD() & ~BM_MLB_MADR_ADDR) | BF_MLB_MADR_ADDR(v)))
#endif

/* --- Register HW_MLB_MADR, field ADDR1[13:8] (RW)
 *
 * DBR address of 8-bit entry - bits[13:8]
 */

#define BP_MLB_MADR_ADDR1      (8)      //!< Bit position for MLB_MADR_ADDR1.
#define BM_MLB_MADR_ADDR1      (0x00003f00)  //!< Bit mask for MLB_MADR_ADDR1.

//! @brief Get value of MLB_MADR_ADDR1 from a register value.
#define BG_MLB_MADR_ADDR1(r)   (((r) & BM_MLB_MADR_ADDR1) >> BP_MLB_MADR_ADDR1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MADR_ADDR1.
#define BF_MLB_MADR_ADDR1(v)   ((((reg32_t) v) << BP_MLB_MADR_ADDR1) & BM_MLB_MADR_ADDR1)
#else
//! @brief Format value for bitfield MLB_MADR_ADDR1.
#define BF_MLB_MADR_ADDR1(v)   (((v) << BP_MLB_MADR_ADDR1) & BM_MLB_MADR_ADDR1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR1 field to a new value.
#define BW_MLB_MADR_ADDR1(v)   (HW_MLB_MADR_WR((HW_MLB_MADR_RD() & ~BM_MLB_MADR_ADDR1) | BF_MLB_MADR_ADDR1(v)))
#endif

/* --- Register HW_MLB_MADR, field TB[30] (RW)
 *
 * Target location bit
 *
 * Values:
 * 0 - selects CTR
 * 1 - selects DBR
 */

#define BP_MLB_MADR_TB      (30)      //!< Bit position for MLB_MADR_TB.
#define BM_MLB_MADR_TB      (0x40000000)  //!< Bit mask for MLB_MADR_TB.

//! @brief Get value of MLB_MADR_TB from a register value.
#define BG_MLB_MADR_TB(r)   (((r) & BM_MLB_MADR_TB) >> BP_MLB_MADR_TB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MADR_TB.
#define BF_MLB_MADR_TB(v)   ((((reg32_t) v) << BP_MLB_MADR_TB) & BM_MLB_MADR_TB)
#else
//! @brief Format value for bitfield MLB_MADR_TB.
#define BF_MLB_MADR_TB(v)   (((v) << BP_MLB_MADR_TB) & BM_MLB_MADR_TB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TB field to a new value.
#define BW_MLB_MADR_TB(v)   (HW_MLB_MADR_WR((HW_MLB_MADR_RD() & ~BM_MLB_MADR_TB) | BF_MLB_MADR_TB(v)))
#endif


/* --- Register HW_MLB_MADR, field WNR[31] (RW)
 *
 * Write-Not-Read selection
 *
 * Values:
 * 0 - read
 * 1 - write
 */

#define BP_MLB_MADR_WNR      (31)      //!< Bit position for MLB_MADR_WNR.
#define BM_MLB_MADR_WNR      (0x80000000)  //!< Bit mask for MLB_MADR_WNR.

//! @brief Get value of MLB_MADR_WNR from a register value.
#define BG_MLB_MADR_WNR(r)   (((r) & BM_MLB_MADR_WNR) >> BP_MLB_MADR_WNR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_MADR_WNR.
#define BF_MLB_MADR_WNR(v)   ((((reg32_t) v) << BP_MLB_MADR_WNR) & BM_MLB_MADR_WNR)
#else
//! @brief Format value for bitfield MLB_MADR_WNR.
#define BF_MLB_MADR_WNR(v)   (((v) << BP_MLB_MADR_WNR) & BM_MLB_MADR_WNR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WNR field to a new value.
#define BW_MLB_MADR_WNR(v)   (HW_MLB_MADR_WR((HW_MLB_MADR_RD() & ~BM_MLB_MADR_WNR) | BF_MLB_MADR_WNR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_ACTL - AHB Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The AHB Control (ACTL) register is written by the HC to configure the AMBA AHB block for channel
 * interrupts. ACTL contains three configuration fields, one is used to select the DMA mode, one is
 * used to mux channel interrupts onto a single interrupt signal, and the last selects the method of
 * clearing channel interrupts (either software or hardware).
 */
typedef union _hw_mlb_actl
{
    reg32_t U;
    struct _hw_mlb_actl_bitfields
    {
        unsigned SCE : 1; //!< [0] Software clear enable:
        unsigned SMX : 1; //!< [1] AHB interrupt mux enable:
        unsigned DMA_MODE : 1; //!< [2] DMA Mode:
        unsigned RESERVED0 : 1; //!< [3] Reserved.
        unsigned MPB : 1; //!< [4] DMA Packet buffering mode.
        unsigned RESERVED1 : 27; //!< [31:5] Reserved
    } B;
} hw_mlb_actl_t;
#endif

/*
 * constants & macros for entire MLB_ACTL register
 */
#define HW_MLB_ACTL_ADDR      (REGS_MLB_BASE + 0x3c0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACTL           (*(volatile hw_mlb_actl_t *) HW_MLB_ACTL_ADDR)
#define HW_MLB_ACTL_RD()      (HW_MLB_ACTL.U)
#define HW_MLB_ACTL_WR(v)     (HW_MLB_ACTL.U = (v))
#define HW_MLB_ACTL_SET(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() |  (v)))
#define HW_MLB_ACTL_CLR(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() & ~(v)))
#define HW_MLB_ACTL_TOG(v)    (HW_MLB_ACTL_WR(HW_MLB_ACTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_ACTL bitfields
 */

/* --- Register HW_MLB_ACTL, field SCE[0] (RW)
 *
 * Software clear enable:
 *
 * Values:
 * 0 - Hardware clears interrupt after a ACSRn register read
 * 1 - Software clears interrupt
 */

#define BP_MLB_ACTL_SCE      (0)      //!< Bit position for MLB_ACTL_SCE.
#define BM_MLB_ACTL_SCE      (0x00000001)  //!< Bit mask for MLB_ACTL_SCE.

//! @brief Get value of MLB_ACTL_SCE from a register value.
#define BG_MLB_ACTL_SCE(r)   (((r) & BM_MLB_ACTL_SCE) >> BP_MLB_ACTL_SCE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACTL_SCE.
#define BF_MLB_ACTL_SCE(v)   ((((reg32_t) v) << BP_MLB_ACTL_SCE) & BM_MLB_ACTL_SCE)
#else
//! @brief Format value for bitfield MLB_ACTL_SCE.
#define BF_MLB_ACTL_SCE(v)   (((v) << BP_MLB_ACTL_SCE) & BM_MLB_ACTL_SCE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCE field to a new value.
#define BW_MLB_ACTL_SCE(v)   (HW_MLB_ACTL_WR((HW_MLB_ACTL_RD() & ~BM_MLB_ACTL_SCE) | BF_MLB_ACTL_SCE(v)))
#endif


/* --- Register HW_MLB_ACTL, field SMX[1] (RW)
 *
 * AHB interrupt mux enable:
 *
 * Values:
 * 0 - ACSR0 generates an interrupt on ahb_int[0] ; ACSR1 generates an interrupt on ahb_int[1]
 * 1 - ACSR0 and ACSR1 generate an interrupts on ahb_int[0] only
 */

#define BP_MLB_ACTL_SMX      (1)      //!< Bit position for MLB_ACTL_SMX.
#define BM_MLB_ACTL_SMX      (0x00000002)  //!< Bit mask for MLB_ACTL_SMX.

//! @brief Get value of MLB_ACTL_SMX from a register value.
#define BG_MLB_ACTL_SMX(r)   (((r) & BM_MLB_ACTL_SMX) >> BP_MLB_ACTL_SMX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACTL_SMX.
#define BF_MLB_ACTL_SMX(v)   ((((reg32_t) v) << BP_MLB_ACTL_SMX) & BM_MLB_ACTL_SMX)
#else
//! @brief Format value for bitfield MLB_ACTL_SMX.
#define BF_MLB_ACTL_SMX(v)   (((v) << BP_MLB_ACTL_SMX) & BM_MLB_ACTL_SMX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SMX field to a new value.
#define BW_MLB_ACTL_SMX(v)   (HW_MLB_ACTL_WR((HW_MLB_ACTL_RD() & ~BM_MLB_ACTL_SMX) | BF_MLB_ACTL_SMX(v)))
#endif


/* --- Register HW_MLB_ACTL, field DMA_MODE[2] (RW)
 *
 * DMA Mode:
 *
 * Values:
 * 0 - DMA Mode 0
 * 1 - DMA Mode 1
 */

#define BP_MLB_ACTL_DMA_MODE      (2)      //!< Bit position for MLB_ACTL_DMA_MODE.
#define BM_MLB_ACTL_DMA_MODE      (0x00000004)  //!< Bit mask for MLB_ACTL_DMA_MODE.

//! @brief Get value of MLB_ACTL_DMA_MODE from a register value.
#define BG_MLB_ACTL_DMA_MODE(r)   (((r) & BM_MLB_ACTL_DMA_MODE) >> BP_MLB_ACTL_DMA_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACTL_DMA_MODE.
#define BF_MLB_ACTL_DMA_MODE(v)   ((((reg32_t) v) << BP_MLB_ACTL_DMA_MODE) & BM_MLB_ACTL_DMA_MODE)
#else
//! @brief Format value for bitfield MLB_ACTL_DMA_MODE.
#define BF_MLB_ACTL_DMA_MODE(v)   (((v) << BP_MLB_ACTL_DMA_MODE) & BM_MLB_ACTL_DMA_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_MODE field to a new value.
#define BW_MLB_ACTL_DMA_MODE(v)   (HW_MLB_ACTL_WR((HW_MLB_ACTL_RD() & ~BM_MLB_ACTL_DMA_MODE) | BF_MLB_ACTL_DMA_MODE(v)))
#endif


/* --- Register HW_MLB_ACTL, field MPB[4] (RW)
 *
 * DMA Packet buffering mode.
 *
 * Values:
 * 0 - Single-packet mode
 * 1 - Multiple-packet mode
 */

#define BP_MLB_ACTL_MPB      (4)      //!< Bit position for MLB_ACTL_MPB.
#define BM_MLB_ACTL_MPB      (0x00000010)  //!< Bit mask for MLB_ACTL_MPB.

//! @brief Get value of MLB_ACTL_MPB from a register value.
#define BG_MLB_ACTL_MPB(r)   (((r) & BM_MLB_ACTL_MPB) >> BP_MLB_ACTL_MPB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACTL_MPB.
#define BF_MLB_ACTL_MPB(v)   ((((reg32_t) v) << BP_MLB_ACTL_MPB) & BM_MLB_ACTL_MPB)
#else
//! @brief Format value for bitfield MLB_ACTL_MPB.
#define BF_MLB_ACTL_MPB(v)   (((v) << BP_MLB_ACTL_MPB) & BM_MLB_ACTL_MPB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPB field to a new value.
#define BW_MLB_ACTL_MPB(v)   (HW_MLB_ACTL_WR((HW_MLB_ACTL_RD() & ~BM_MLB_ACTL_MPB) | BF_MLB_ACTL_MPB(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_ACSR0 - AHB Channel Status 0 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The AHB Channel Status (ACSRn) registers contain interrupt bits for each of the 64 physical
 * channels. When an ACSRn register bit is set, it indicates that the corresponding physical channel
 * has an interrupt pending.  An AHB interrupt is triggered when either DNEn or ERRn is set within
 * the AHB Channel Descriptor. The HC is notified of the channel interrupt via ahb_int[1:0] . When
 * an interrupt occurs in ACSR0 (for channels 31 to 0) ahb_int[0] is set. When an interrupt occurs
 * in ACSR1 (for channels 63 to 32) ahb_int[1] is set.  Interrupts in ACSR0 and ACSR1 can be
 * optionally muxed onto a single interrupt signal, ahb_int[0] , if ACTL.SMX = 1. If ACTL.SCE = 0,
 * hardware automatically clears the interrupt bit(s) after the HC reads the ACSRn register.
 * Alternatively, if ACTL.SCE = 1, software must write a 1 to the appropriate bit(s) of ACSRn to
 * clear the interrupt(s).
 */
typedef union _hw_mlb_acsr0
{
    reg32_t U;
    struct _hw_mlb_acsr0_bitfields
    {
        unsigned V : 32; //!< [31:0] Interrupt status for logical channels 31 to 0:
    } B;
} hw_mlb_acsr0_t;
#endif

/*
 * constants & macros for entire MLB_ACSR0 register
 */
#define HW_MLB_ACSR0_ADDR      (REGS_MLB_BASE + 0x3d0)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACSR0           (*(volatile hw_mlb_acsr0_t *) HW_MLB_ACSR0_ADDR)
#define HW_MLB_ACSR0_RD()      (HW_MLB_ACSR0.U)
#endif

/*
 * constants & macros for individual MLB_ACSR0 bitfields
 */

/* --- Register HW_MLB_ACSR0, field V[31:0] (RO)
 *
 * Interrupt status for logical channels 31 to 0:
 *
 * Values:
 * 0 - None
 * 1 - Interrupt
 */

#define BP_MLB_ACSR0_V      (0)      //!< Bit position for MLB_ACSR0_V.
#define BM_MLB_ACSR0_V      (0xffffffff)  //!< Bit mask for MLB_ACSR0_V.

//! @brief Get value of MLB_ACSR0_V from a register value.
#define BG_MLB_ACSR0_V(r)   (((r) & BM_MLB_ACSR0_V) >> BP_MLB_ACSR0_V)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_ACSR1 - AHB Channel Status 1 Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_acsr1
{
    reg32_t U;
    struct _hw_mlb_acsr1_bitfields
    {
        unsigned CHS : 32; //!< [31:0] Interrupt status for logical channels 63 to 32:
    } B;
} hw_mlb_acsr1_t;
#endif

/*
 * constants & macros for entire MLB_ACSR1 register
 */
#define HW_MLB_ACSR1_ADDR      (REGS_MLB_BASE + 0x3d4)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACSR1           (*(volatile hw_mlb_acsr1_t *) HW_MLB_ACSR1_ADDR)
#define HW_MLB_ACSR1_RD()      (HW_MLB_ACSR1.U)
#endif

/*
 * constants & macros for individual MLB_ACSR1 bitfields
 */

/* --- Register HW_MLB_ACSR1, field CHS[31:0] (RO)
 *
 * Interrupt status for logical channels 63 to 32:
 *
 * Values:
 * 0 - None
 * 1 - Interrupt
 */

#define BP_MLB_ACSR1_CHS      (0)      //!< Bit position for MLB_ACSR1_CHS.
#define BM_MLB_ACSR1_CHS      (0xffffffff)  //!< Bit mask for MLB_ACSR1_CHS.

//! @brief Get value of MLB_ACSR1_CHS from a register value.
#define BG_MLB_ACSR1_CHS(r)   (((r) & BM_MLB_ACSR1_CHS) >> BP_MLB_ACSR1_CHS)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_ACMR0 - AHB Channel Mask 0 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Using the AHB Channel Mask (ACMRn) register, the HC can control which channel(s) generate
 * interrupts on ahb_int[1:0] . All ACMRn register bits default as '0' ("masked"); therefore, the HC
 * must initially write ACMRn to enable interrupts. Each bit of ACMRn is read/write accessible.
 */
typedef union _hw_mlb_acmr0
{
    reg32_t U;
    struct _hw_mlb_acmr0_bitfields
    {
        unsigned CHM : 32; //!< [31:0] Bitwise channel mask bit:
    } B;
} hw_mlb_acmr0_t;
#endif

/*
 * constants & macros for entire MLB_ACMR0 register
 */
#define HW_MLB_ACMR0_ADDR      (REGS_MLB_BASE + 0x3d8)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACMR0           (*(volatile hw_mlb_acmr0_t *) HW_MLB_ACMR0_ADDR)
#define HW_MLB_ACMR0_RD()      (HW_MLB_ACMR0.U)
#define HW_MLB_ACMR0_WR(v)     (HW_MLB_ACMR0.U = (v))
#define HW_MLB_ACMR0_SET(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() |  (v)))
#define HW_MLB_ACMR0_CLR(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() & ~(v)))
#define HW_MLB_ACMR0_TOG(v)    (HW_MLB_ACMR0_WR(HW_MLB_ACMR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_ACMR0 bitfields
 */

/* --- Register HW_MLB_ACMR0, field CHM[31:0] (RW)
 *
 * Bitwise channel mask bit:
 *
 * Values:
 * 0 - Masked
 * 1 - Unmasked
 */

#define BP_MLB_ACMR0_CHM      (0)      //!< Bit position for MLB_ACMR0_CHM.
#define BM_MLB_ACMR0_CHM      (0xffffffff)  //!< Bit mask for MLB_ACMR0_CHM.

//! @brief Get value of MLB_ACMR0_CHM from a register value.
#define BG_MLB_ACMR0_CHM(r)   (((r) & BM_MLB_ACMR0_CHM) >> BP_MLB_ACMR0_CHM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACMR0_CHM.
#define BF_MLB_ACMR0_CHM(v)   ((((reg32_t) v) << BP_MLB_ACMR0_CHM) & BM_MLB_ACMR0_CHM)
#else
//! @brief Format value for bitfield MLB_ACMR0_CHM.
#define BF_MLB_ACMR0_CHM(v)   (((v) << BP_MLB_ACMR0_CHM) & BM_MLB_ACMR0_CHM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHM field to a new value.
#define BW_MLB_ACMR0_CHM(v)   (HW_MLB_ACMR0_WR((HW_MLB_ACMR0_RD() & ~BM_MLB_ACMR0_CHM) | BF_MLB_ACMR0_CHM(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MLB_ACMR1 - AHB Channel Mask 1 Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_mlb_acmr1
{
    reg32_t U;
    struct _hw_mlb_acmr1_bitfields
    {
        unsigned CHM : 32; //!< [31:0] Bitwise channel mask bit:
    } B;
} hw_mlb_acmr1_t;
#endif

/*
 * constants & macros for entire MLB_ACMR1 register
 */
#define HW_MLB_ACMR1_ADDR      (REGS_MLB_BASE + 0x3dc)

#ifndef __LANGUAGE_ASM__
#define HW_MLB_ACMR1           (*(volatile hw_mlb_acmr1_t *) HW_MLB_ACMR1_ADDR)
#define HW_MLB_ACMR1_RD()      (HW_MLB_ACMR1.U)
#define HW_MLB_ACMR1_WR(v)     (HW_MLB_ACMR1.U = (v))
#define HW_MLB_ACMR1_SET(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() |  (v)))
#define HW_MLB_ACMR1_CLR(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() & ~(v)))
#define HW_MLB_ACMR1_TOG(v)    (HW_MLB_ACMR1_WR(HW_MLB_ACMR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MLB_ACMR1 bitfields
 */

/* --- Register HW_MLB_ACMR1, field CHM[31:0] (RW)
 *
 * Bitwise channel mask bit:
 *
 * Values:
 * 0 - Masked
 * 1 - Unmasked
 */

#define BP_MLB_ACMR1_CHM      (0)      //!< Bit position for MLB_ACMR1_CHM.
#define BM_MLB_ACMR1_CHM      (0xffffffff)  //!< Bit mask for MLB_ACMR1_CHM.

//! @brief Get value of MLB_ACMR1_CHM from a register value.
#define BG_MLB_ACMR1_CHM(r)   (((r) & BM_MLB_ACMR1_CHM) >> BP_MLB_ACMR1_CHM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield MLB_ACMR1_CHM.
#define BF_MLB_ACMR1_CHM(v)   ((((reg32_t) v) << BP_MLB_ACMR1_CHM) & BM_MLB_ACMR1_CHM)
#else
//! @brief Format value for bitfield MLB_ACMR1_CHM.
#define BF_MLB_ACMR1_CHM(v)   (((v) << BP_MLB_ACMR1_CHM) & BM_MLB_ACMR1_CHM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHM field to a new value.
#define BW_MLB_ACMR1_CHM(v)   (HW_MLB_ACMR1_WR((HW_MLB_ACMR1_RD() & ~BM_MLB_ACMR1_CHM) | BF_MLB_ACMR1_CHM(v)))
#endif



/*!
 * @brief All MLB module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_mlb
{
    volatile hw_mlb_mlbc0_t MLBC0; //!< MediaLB Control 0 Register
    reg32_t _reserved0;
    volatile hw_mlb_mlbpc0_t MLBPC0; //!< MediaLB 6-pin Control 0 Register
    volatile hw_mlb_ms0_t MS0; //!< MediaLB Channel Status 0 Register
    volatile hw_mlb_mlbpc2_t MLBPC2; //!< MediaLB 6-pin Control 2 Register
    volatile hw_mlb_ms1_t MS1; //!< MediaLB Channel Status1 Register
    reg32_t _reserved1[2];
    volatile hw_mlb_mss_t MSS; //!< MediaLB System Status Register
    volatile hw_mlb_msd_t MSD; //!< MediaLB System Data Register
    reg32_t _reserved2;
    volatile hw_mlb_mien_t MIEN; //!< MediaLB Interrupt Enable Register
    reg32_t _reserved3[2];
    volatile hw_mlb_mlbpc1_t MLBPC1; //!< MediaLB 6-pin Control 1 Register
    volatile hw_mlb_mlbc1_t MLBC1; //!< MediaLB Control 1 Register
    reg32_t _reserved4[16];
    volatile hw_mlb_hctl_t HCTL; //!< HBI Control Register
    reg32_t _reserved5;
    volatile hw_mlb_hcmr0_t HCMR0; //!< HBI Channel Mask 0 Register
    volatile hw_mlb_hcmr1_t HCMR1; //!< HBI Channel Mask 1 Register
    volatile hw_mlb_hcer0_t HCER0; //!< HBI Channel Error 0 Register
    volatile hw_mlb_hcer1_t HCER1; //!< HBI Channel Error 1 Register
    volatile hw_mlb_hcbr0_t HCBR0; //!< HBI Channel Busy 0 Register
    volatile hw_mlb_hcbr1_t HCBR1; //!< HBI Channel Busy 1 Register
    reg32_t _reserved6[8];
    volatile hw_mlb_mdat0_t MDAT0; //!< MIF Data 0 Register
    volatile hw_mlb_mdat1_t MDAT1; //!< MIF Data 1 Register
    volatile hw_mlb_mdat2_t MDAT2; //!< MIF Data 2 Register
    volatile hw_mlb_mdat3_t MDAT3; //!< MIF Data 3 Register
    volatile hw_mlb_mdwe0_t MDWE0; //!< MIF Data Write Enable 0 Register
    volatile hw_mlb_mdwe1_t MDWE1; //!< MIF Data Write Enable 1 Register
    volatile hw_mlb_mdwe2_t MDWE2; //!< MIF Data Write Enable 2 Register
    volatile hw_mlb_mdwe3_t MDWE3; //!< MIF Data Write Enable 3 Register
    volatile hw_mlb_mctl_t MCTL; //!< MIF Control Register
    volatile hw_mlb_madr_t MADR; //!< MIF Address Register
    reg32_t _reserved7[182];
    volatile hw_mlb_actl_t ACTL; //!< AHB Control Register
    reg32_t _reserved8[3];
    volatile hw_mlb_acsr0_t ACSR0; //!< AHB Channel Status 0 Register
    volatile hw_mlb_acsr1_t ACSR1; //!< AHB Channel Status 1 Register
    volatile hw_mlb_acmr0_t ACMR0; //!< AHB Channel Mask 0 Register
    volatile hw_mlb_acmr1_t ACMR1; //!< AHB Channel Mask 1 Register
} hw_mlb_t;
#pragma pack()
#endif

//! @brief Macro to access all MLB registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MLB(0)</code>.
#define HW_MLB     (*(volatile hw_mlb_t *) REGS_MLB_BASE)


#endif // _MLB_H
