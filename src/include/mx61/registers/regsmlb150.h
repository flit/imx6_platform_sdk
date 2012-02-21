/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MLB_H
#define _MLB_H

#include "regs.h"

#ifndef REGS_MLB_BASE
#define REGS_MLB_BASE (REGS_BASE + 0x0218c000)
#endif


/*!
 * @brief HW_MLB_MLBC0 - MediaLB Control 0 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< MediaLB enable. When set, MediaLB clock, signal, and data are received and transmitted on the appropriate MediaLB pins.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 3; //!< MediaLB clock speed select.
        unsigned RESERVED3 : 1; //!< MediaLB 6-pin enable.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RESERVED5 : 1; //!< MediaLB lock status. When set, indicates that the MediaLB block is synchronized to the incoming MediaLB frame. If MLBLK is clear (unlocked), MLBLK is set after FRAMESYNC is detected at the same position for three consecutive frames. If MLBLK is set (locked), MLBLK is cleared after not receiving FRAMESYNC at the expected time for two consecutive frames. While MLBLK is set, FRAMESYNC patterns occurring at locations other than the expected one are ignored. (read-only)
        unsigned RESERVED6 : 4; //!< Reserved
        unsigned RESERVED7 : 1; //!< Asynchronous Tx packet retry. When set, an asynchronous packet that is flagged with a Break or ProtocolError by the receiver is retransmitted. When cleared, an asynchronous packet that is flagged with a Break or ProtocolError by the receiver is skipped.
        unsigned RESERVED8 : 1; //!< Reserved
        unsigned RESERVED9 : 1; //!< Control Tx packet retry. When set, a control packet that is flagged with a Break or ProtocolError by the receiver is retransmitted. When cleared, a control packet that is flagged with a Break or ProtocolError by the receiver is skipped.
        unsigned FCNT : 3; //!< The number of frames per sub-buffer for synchronous channels.
        unsigned RESERVED10 : 14; //!< Reserved
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

/* --- Register HW_MLB_MLBC0, field FCNT
 *
 * The number of frames per sub-buffer for synchronous channels.
 */

#define BP_MLB_MLBC0_FCNT      15
#define BM_MLB_MLBC0_FCNT      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBC0_FCNT(v)   ((((reg32_t) v) << 15) & BM_MLB_MLBC0_FCNT)
#else
#define BF_MLB_MLBC0_FCNT(v)   (((v) << 15) & BM_MLB_MLBC0_FCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBC0_FCNT(v)   BF_CS1(MLB_MLBC0, FCNT, v)
#endif

/*!
 * @brief HW_MLB_MLBPC0 - MediaLB 6-pin Control 0 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned RESERVED1 : 1; //!< MediaLB (6-pin) hysteresis enable. When set, enables hysteresis on the MediaLB clock. This value is driven on mlb_clk_hys_enable output pin and has no internal function.
        unsigned RESERVED2 : 20; //!< Reserved
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

/*!
 * @brief HW_MLB_MS0 - MediaLB Channel Status 0 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< MediaLB channel status. Indicates the channel status for MediaLB channels 31 to 0. Channel status bits are set by hardware and cleared by software. Status is only set if the appropriate bits in the MIEN register are set.
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
#define HW_MLB_MS0_WR(v)     (HW_MLB_MS0.U = (v))
#define HW_MLB_MS0_SET(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() |  (v)))
#define HW_MLB_MS0_CLR(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() & ~(v)))
#define HW_MLB_MS0_TOG(v)    (HW_MLB_MS0_WR(HW_MLB_MS0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MS0 bitfields
 */

/*!
 * @brief HW_MLB_MLBPC2 - MediaLB 6-pin Control 2 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SDOPC : 1; //!< MLB 3-pin interface: Signal/Data output phase control.
        unsigned SDRTO : 2; //!< MLB 6-pin interface: Signal/Data receiver threshold offset control.
        unsigned RESERVED0 : 29; //!< Reserved.
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
#define HW_MLB_MLBPC2_WR(v)     (HW_MLB_MLBPC2.U = (v))
#define HW_MLB_MLBPC2_SET(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() |  (v)))
#define HW_MLB_MLBPC2_CLR(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() & ~(v)))
#define HW_MLB_MLBPC2_TOG(v)    (HW_MLB_MLBPC2_WR(HW_MLB_MLBPC2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBPC2 bitfields
 */

/* --- Register HW_MLB_MLBPC2, field SDOPC
 *
 * MLB 3-pin interface: Signal/Data output phase control.
 */

#define BP_MLB_MLBPC2_SDOPC      0
#define BM_MLB_MLBPC2_SDOPC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBPC2_SDOPC(v)   ((((reg32_t) v) << 0) & BM_MLB_MLBPC2_SDOPC)
#else
#define BF_MLB_MLBPC2_SDOPC(v)   (((v) << 0) & BM_MLB_MLBPC2_SDOPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBPC2_SDOPC(v)   BF_CS1(MLB_MLBPC2, SDOPC, v)
#endif

/* --- Register HW_MLB_MLBPC2, field SDRTO
 *
 * MLB 6-pin interface: Signal/Data receiver threshold offset control.
 */

#define BP_MLB_MLBPC2_SDRTO      1
#define BM_MLB_MLBPC2_SDRTO      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_MLB_MLBPC2_SDRTO(v)   ((((reg32_t) v) << 1) & BM_MLB_MLBPC2_SDRTO)
#else
#define BF_MLB_MLBPC2_SDRTO(v)   (((v) << 1) & BM_MLB_MLBPC2_SDRTO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_MLBPC2_SDRTO(v)   BF_CS1(MLB_MLBPC2, SDRTO, v)
#endif

/*!
 * @brief HW_MLB_MS1 - MediaLB Channel Status1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< MediaLB channel status. Indicates the channel status for MediaLB channels 63 to 32. Channel status bits are set by hardware and cleared by software. Status is only set if the appropriate bits in the MIEN register are set.
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
#define HW_MLB_MS1_WR(v)     (HW_MLB_MS1.U = (v))
#define HW_MLB_MS1_SET(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() |  (v)))
#define HW_MLB_MS1_CLR(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() & ~(v)))
#define HW_MLB_MS1_TOG(v)    (HW_MLB_MS1_WR(HW_MLB_MS1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MS1 bitfields
 */

/*!
 * @brief HW_MLB_MSS - MediaLB System Status Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reset system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned RESERVED1 : 1; //!< Network lock system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned RESERVED2 : 1; //!< Network unlock system command detected (in the system quadlet). Set by hardware, cleared by software.
        unsigned RESERVED3 : 1; //!< Channel scan system command detected (in the system quadlet). Set by hardware, cleared by software. If the node address specified in Data quadlet matches the value in MLBC1.NDA , the device responds either "device present" or "device present, request service" system response in the next system quadlet.
        unsigned RESERVED4 : 1; //!< Software system command detected (in the system quadlet). Set by hardware, cleared by software. Data is stored in the MSD register for this command.
        unsigned RESERVED5 : 1; //!< Service request enabled. When set, the MediaLB block responds with a "device present, request service" system response if a matching channel scan system command is detected. When cleared, the MediaLB block responds with a "device present" system response.
        unsigned RESERVED6 : 26; //!< Reserved
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
#define HW_MLB_MSS_WR(v)     (HW_MLB_MSS.U = (v))
#define HW_MLB_MSS_SET(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() |  (v)))
#define HW_MLB_MSS_CLR(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() & ~(v)))
#define HW_MLB_MSS_TOG(v)    (HW_MLB_MSS_WR(HW_MLB_MSS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MSS bitfields
 */

/*!
 * @brief HW_MLB_MSD - MediaLB System Data Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8; //!< System data (byte 0). Updated with MediaLB Data[7:0] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD0 is not updated. (read-only)
        unsigned RESERVED1 : 8; //!< System data (byte 1). Updated with MediaLB Data[15:8] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD1 is not updated. (read-only)
        unsigned RESERVED2 : 8; //!< System data (byte 2). Updated with MediaLB Data[23:16] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD2 is not updated. (read-only)
        unsigned RESERVED3 : 8; //!< System data (byte 3). Updated with MediaLB Data[31:24] when a MediaLB software system command is received in the system quadlet. If MSS.SWSYSCMD is already set, then SD3 is not updated. (read-only)
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
#define HW_MLB_MSD_WR(v)     (HW_MLB_MSD.U = (v))
#define HW_MLB_MSD_SET(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() |  (v)))
#define HW_MLB_MSD_CLR(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() & ~(v)))
#define HW_MLB_MSD_TOG(v)    (HW_MLB_MSD_WR(HW_MLB_MSD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MSD bitfields
 */

/*!
 * @brief HW_MLB_MIEN - MediaLB Interrupt Enable Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Isochronous Rx protocol error enable. When set, a ProtocolError detected on an isochronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED1 : 1; //!< Isochronous Rx buffer overflow enable. When set, a buffer overflow on an isochronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set. This occurs only when isochronous flow control is disabled.
        unsigned RESERVED2 : 14; //!< Reserved
        unsigned RESERVED3 : 1; //!< Synchronous protocol error enable. When set, a ProtocolError detected on a synchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED4 : 1; //!< Asynchronous Rx done enable. When set, a packet received with no errors on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED5 : 1; //!< Asynchronous Rx protocol error enable. When set, a ProtocolError detected on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED6 : 1; //!< Asynchronous Rx break enable. When set, a AsyncBreak command received from the transmitter on an asynchronous Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED7 : 1; //!< Asynchronous Tx packet done enable. When set, a packet transmitted with no errors on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED8 : 1; //!< Asynchronous Tx protocol error enable. When set, a ProtocolError generated by the receiver on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED9 : 1; //!< Asynchronous Tx break enable. When set, a ReceiverBreak response received from the receiver on an asynchronous Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED10 : 1; //!< Reserved
        unsigned RESERVED11 : 1; //!< Control Rx packet done enable. When set, a packet received with no errors on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED12 : 1; //!< Control Rx protocol error enable. When set, a ProtocolError detected on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED13 : 1; //!< Control Rx break enable. When set, a ControlBreak command received from the transmitter on a control Rx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED14 : 1; //!< Control Tx packet done enable. When set, a packet transmitted with no errors on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED15 : 1; //!< Control Tx protocol error enable. When set, a ProtocolError generated by the receiver on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED16 : 1; //!< Control Tx break enable. When set, a ReceiverBreak response received from the receiver on a control Tx channel causes the appropriate channel bit in the MS0 or MS1 registers to be set.
        unsigned RESERVED17 : 2; //!< Reserved
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

/*!
 * @brief HW_MLB_MLBPC1 - MediaLB 6-pin Control 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Signal/Data receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_sig_data_rx_bias_ctl[3:0] output pin and has no internal function.
        unsigned RESERVED1 : 4; //!< Signal/Data transmitter bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_sig_data_tx_bias_ctl[3:0] output pin and has no internal function.
        unsigned RESERVED2 : 4; //!< Clock receiver bias control (for MediaLB 6-pin interface). Must be written to 0xC when MediaLB 6-pin is initialized (final value needs to be determined through characterization). This value is driven on mlb_clk_rx_bias_ctl[3:0] output pin and has no internal function.
        unsigned RESERVED3 : 20; //!< Reserved
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

/*!
 * @brief HW_MLB_MLBC1 - MediaLB Control 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6; //!< Reserved
        unsigned RESERVED1 : 1; //!< MediaLB lock error status. Set when MediaLB is unlocked; cleared by software.
        unsigned RESERVED2 : 1; //!< MediaLB clock missing status. Set when MediaLB clock is not toggling at the pin; cleared by software.
        unsigned RESERVED3 : 8; //!< Node device address. Used for system commands directed to individual MediaLB nodes.
        unsigned RESERVED4 : 16; //!< Reserved
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
#define HW_MLB_MLBC1_WR(v)     (HW_MLB_MLBC1.U = (v))
#define HW_MLB_MLBC1_SET(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() |  (v)))
#define HW_MLB_MLBC1_CLR(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() & ~(v)))
#define HW_MLB_MLBC1_TOG(v)    (HW_MLB_MLBC1_WR(HW_MLB_MLBC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MLBC1 bitfields
 */

/*!
 * @brief HW_MLB_HCTL - HBI Control Register
 *
 * The HC can control and monitor general operation of the HBI block by
 * reading and writing the HBI Control Register (HCTL) through the I/O
 * interface. Each bit of HCTL is read/write.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< AGU0 software reset
        unsigned RESERVED1 : 1; //!< AGU1 software reset
        unsigned RESERVED2 : 13; //!< Reserved
        unsigned RESERVED3 : 1; //!< HBI enable
        unsigned RESERVED4 : 16; //!< Reserved
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

/*!
 * @brief HW_MLB_HCMR0 - HBI Channel Mask 0 Register
 *
 * The HC can control which channel(s) are able to generate an HBI interrupt
 * by writing the HBI Channel Mask Registers (HCMRn). The HCMRn registers
 * mask the channel interrupt on the hbi_hintb signal (i.e. hbi_hintb will not become active for any
 * masked channel).                             Each bit of HCMRn is read/write.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel mask bit
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

/*!
 * @brief HW_MLB_HCMR1 - HBI Channel Mask 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel mask bit
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

/*!
 * @brief HW_MLB_HCER0 - HBI Channel Error 0 Register
 *
 * The HBI Channel Error Registers (HCERn) indicate which channel(s) have
 * encountered fatal errors.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel error bit
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
#define HW_MLB_HCER0_WR(v)     (HW_MLB_HCER0.U = (v))
#define HW_MLB_HCER0_SET(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() |  (v)))
#define HW_MLB_HCER0_CLR(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() & ~(v)))
#define HW_MLB_HCER0_TOG(v)    (HW_MLB_HCER0_WR(HW_MLB_HCER0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCER0 bitfields
 */

/*!
 * @brief HW_MLB_HCER1 - HBI Channel Error 1 Register
 *
 * HCERn status bits are set when hardware detects hardware errors on the
 * given logical channel, including:   Channel opened, but not enabled,  Channel programmed with
 * invalid channel type, or  Out-of-range PML for asynchronous or control Tx channels
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel error bit
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
#define HW_MLB_HCER1_WR(v)     (HW_MLB_HCER1.U = (v))
#define HW_MLB_HCER1_SET(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() |  (v)))
#define HW_MLB_HCER1_CLR(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() & ~(v)))
#define HW_MLB_HCER1_TOG(v)    (HW_MLB_HCER1_WR(HW_MLB_HCER1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCER1 bitfields
 */

/*!
 * @brief HW_MLB_HCBR0 - HBI Channel Busy 0 Register
 *
 * The HC can determine which channel(s) are busy by reading the HBI Channel
 * Busy Registers (HCBRn). An HBI channel is busy if:   it is currently loaded into one of the two
 * AGUs  the channel is enabled, CE = 1 from the Channel Allocation Table ( ), and  the DMA is
 * active   When an HBI channel is busy, hardware may write back its local copy of
 * the channel descriptor at any time. System software should not write a
 * CDT descriptor for a channel that is busy. Only two HBI channels can be
 * busy at any given time. Each bit of HCBRn is read-only.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel busy bit
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
#define HW_MLB_HCBR0_WR(v)     (HW_MLB_HCBR0.U = (v))
#define HW_MLB_HCBR0_SET(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() |  (v)))
#define HW_MLB_HCBR0_CLR(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() & ~(v)))
#define HW_MLB_HCBR0_TOG(v)    (HW_MLB_HCBR0_WR(HW_MLB_HCBR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCBR0 bitfields
 */

/*!
 * @brief HW_MLB_HCBR1 - HBI Channel Busy 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise channel busy bit
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
#define HW_MLB_HCBR1_WR(v)     (HW_MLB_HCBR1.U = (v))
#define HW_MLB_HCBR1_SET(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() |  (v)))
#define HW_MLB_HCBR1_CLR(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() & ~(v)))
#define HW_MLB_HCBR1_TOG(v)    (HW_MLB_HCBR1_WR(HW_MLB_HCBR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_HCBR1 bitfields
 */

/*!
 * @brief HW_MLB_MDAT0 - MIF Data 0 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< CTR data - bits[31:0] of 128-bit entry or  DBR data - bits[7:0] of 8-bit entry
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

/*!
 * @brief HW_MLB_MDAT1 - MIF Data 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< CTR data - bits[63:32] of 128-bit entry
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

/*!
 * @brief HW_MLB_MDAT2 - MIF Data 2 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< CTR data - bits[95:64] of 128-bit entry
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

/*!
 * @brief HW_MLB_MDAT3 - MIF Data 3 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< CTR data - bits[127:96] of 128-bit entry
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

/*!
 * @brief HW_MLB_MDWE0 - MIF Data Write Enable 0 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise write enable for CTR data - bits[31:0]
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

/*!
 * @brief HW_MLB_MDWE1 - MIF Data Write Enable 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise write enable for CTR data - bits[63:32]
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

/*!
 * @brief HW_MLB_MDWE2 - MIF Data Write Enable 2 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise write enable for CTR data - bits[95:64]
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

/*!
 * @brief HW_MLB_MDWE3 - MIF Data Write Enable 3 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Bitwise write enable for CTR data - bits[127:96]
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

/*!
 * @brief HW_MLB_MCTL - MIF Control Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Transfer complete (write 0 to clear)
        unsigned RESERVED1 : 31; //!< Reserved
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
#define HW_MLB_MCTL_WR(v)     (HW_MLB_MCTL.U = (v))
#define HW_MLB_MCTL_SET(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() |  (v)))
#define HW_MLB_MCTL_CLR(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() & ~(v)))
#define HW_MLB_MCTL_TOG(v)    (HW_MLB_MCTL_WR(HW_MLB_MCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_MCTL bitfields
 */

/*!
 * @brief HW_MLB_MADR - MIF Address Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8; //!< CTR address of 128-bit entry or  DBR address of 8-bit entry - bits[7:0]
        unsigned RESERVED1 : 6; //!< DBR address of 8-bit entry - bits[13:8]
        unsigned RESERVED2 : 16; //!< Reserved
        unsigned RESERVED3 : 1; //!< Target location bit
        unsigned RESERVED4 : 1; //!< Write-Not-Read selection
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

/*!
 * @brief HW_MLB_ACTL - AHB Control Register
 *
 * The AHB Control (ACTL) register is written by the HC to configure the
 * AMBA AHB block for channel interrupts. ACTL contains three configuration
 * fields, one is used to select the DMA mode, one is used to mux channel
 * interrupts onto a single interrupt signal, and the last selects the
 * method of clearing channel interrupts (either software or hardware).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SCE : 1; //!< Software clear enable:
        unsigned SMX : 1; //!< AHB interrupt mux enable:
        unsigned DMA_MODE : 1; //!< DMA Mode:
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned MPB : 1; //!< DMA Packet buffering mode.
        unsigned RSVD : 27; //!< Reserved
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

/* --- Register HW_MLB_ACTL, field SCE
 *
 * Software clear enable:
 */

#define BP_MLB_ACTL_SCE      0
#define BM_MLB_ACTL_SCE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_SCE(v)   ((((reg32_t) v) << 0) & BM_MLB_ACTL_SCE)
#else
#define BF_MLB_ACTL_SCE(v)   (((v) << 0) & BM_MLB_ACTL_SCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_SCE(v)   BF_CS1(MLB_ACTL, SCE, v)
#endif

/* --- Register HW_MLB_ACTL, field SMX
 *
 * AHB interrupt mux enable:
 */

#define BP_MLB_ACTL_SMX      1
#define BM_MLB_ACTL_SMX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_SMX(v)   ((((reg32_t) v) << 1) & BM_MLB_ACTL_SMX)
#else
#define BF_MLB_ACTL_SMX(v)   (((v) << 1) & BM_MLB_ACTL_SMX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_SMX(v)   BF_CS1(MLB_ACTL, SMX, v)
#endif

/* --- Register HW_MLB_ACTL, field DMA_MODE
 *
 * DMA Mode:
 */

#define BP_MLB_ACTL_DMA_MODE      2
#define BM_MLB_ACTL_DMA_MODE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_DMA_MODE(v)   ((((reg32_t) v) << 2) & BM_MLB_ACTL_DMA_MODE)
#else
#define BF_MLB_ACTL_DMA_MODE(v)   (((v) << 2) & BM_MLB_ACTL_DMA_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_DMA_MODE(v)   BF_CS1(MLB_ACTL, DMA_MODE, v)
#endif

/* --- Register HW_MLB_ACTL, field MPB
 *
 * DMA Packet buffering mode.
 */

#define BP_MLB_ACTL_MPB      4
#define BM_MLB_ACTL_MPB      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_MPB(v)   ((((reg32_t) v) << 4) & BM_MLB_ACTL_MPB)
#else
#define BF_MLB_ACTL_MPB(v)   (((v) << 4) & BM_MLB_ACTL_MPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_MPB(v)   BF_CS1(MLB_ACTL, MPB, v)
#endif

/* --- Register HW_MLB_ACTL, field RSVD
 *
 * Reserved
 */

#define BP_MLB_ACTL_RSVD      5
#define BM_MLB_ACTL_RSVD      0xffffffe0

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACTL_RSVD(v)   ((((reg32_t) v) << 5) & BM_MLB_ACTL_RSVD)
#else
#define BF_MLB_ACTL_RSVD(v)   (((v) << 5) & BM_MLB_ACTL_RSVD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACTL_RSVD(v)   BF_CS1(MLB_ACTL, RSVD, v)
#endif

/*!
 * @brief HW_MLB_ACSR0 - AHB Channel Status 0 Register
 *
 * The AHB Channel Status (ACSRn) registers contain interrupt bits for each
 * of the 64 physical channels. When an ACSRn register bit is set, it
 * indicates that the corresponding physical channel has an interrupt
 * pending.  An AHB interrupt is triggered when either DNEn or ERRn is set within the
 * AHB Channel Descriptor. The HC is notified of the channel interrupt via ahb_int[1:0] . When an
 * interrupt occurs in ACSR0 (for channels                             31 to 0) ahb_int[0] is set.
 * When an interrupt occurs in ACSR1                             (for channels 63 to 32) ahb_int[1]
 * is set.  Interrupts in ACSR0 and ACSR1 can be optionally muxed onto a single
 * interrupt signal, ahb_int[0] , if ACTL.SMX = 1. If ACTL.SCE = 0,
 * hardware automatically clears the interrupt bit(s) after the HC reads
 * the ACSRn register. Alternatively, if ACTL.SCE = 1, software must write
 * a 1 to the appropriate bit(s) of ACSRn to clear the interrupt(s).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned V : 32; //!< Interrupt status for logical channels 31 to 0:
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
#define HW_MLB_ACSR0_WR(v)     (HW_MLB_ACSR0.U = (v))
#define HW_MLB_ACSR0_SET(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() |  (v)))
#define HW_MLB_ACSR0_CLR(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() & ~(v)))
#define HW_MLB_ACSR0_TOG(v)    (HW_MLB_ACSR0_WR(HW_MLB_ACSR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACSR0 bitfields
 */

/* --- Register HW_MLB_ACSR0, field V
 *
 * Interrupt status for logical channels 31 to 0:
 */

#define BP_MLB_ACSR0_V      0
#define BM_MLB_ACSR0_V      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACSR0_V(v)   ((((reg32_t) v) << 0) & BM_MLB_ACSR0_V)
#else
#define BF_MLB_ACSR0_V(v)   (((v) << 0) & BM_MLB_ACSR0_V)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACSR0_V(v)   BF_CS1(MLB_ACSR0, V, v)
#endif

/*!
 * @brief HW_MLB_ACSR1 - AHB Channel Status 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHS : 32; //!< Interrupt status for logical channels 63 to 32:
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
#define HW_MLB_ACSR1_WR(v)     (HW_MLB_ACSR1.U = (v))
#define HW_MLB_ACSR1_SET(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() |  (v)))
#define HW_MLB_ACSR1_CLR(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() & ~(v)))
#define HW_MLB_ACSR1_TOG(v)    (HW_MLB_ACSR1_WR(HW_MLB_ACSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MLB_ACSR1 bitfields
 */

/* --- Register HW_MLB_ACSR1, field CHS
 *
 * Interrupt status for logical channels 63 to 32:
 */

#define BP_MLB_ACSR1_CHS      0
#define BM_MLB_ACSR1_CHS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACSR1_CHS(v)   ((((reg32_t) v) << 0) & BM_MLB_ACSR1_CHS)
#else
#define BF_MLB_ACSR1_CHS(v)   (((v) << 0) & BM_MLB_ACSR1_CHS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACSR1_CHS(v)   BF_CS1(MLB_ACSR1, CHS, v)
#endif

/*!
 * @brief HW_MLB_ACMR0 - AHB Channel Mask 0 Register
 *
 * Using the AHB Channel Mask (ACMRn) register, the HC can control which
 * channel(s) generate interrupts on ahb_int[1:0] . All ACMRn                             register
 * bits default as '0' ("masked"); therefore, the HC must                             initially
 * write ACMRn to enable interrupts. Each bit of ACMRn is                             read/write
 * accessible.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHM : 32; //!< Bitwise channel mask bit:
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

/* --- Register HW_MLB_ACMR0, field CHM
 *
 * Bitwise channel mask bit:
 */

#define BP_MLB_ACMR0_CHM      0
#define BM_MLB_ACMR0_CHM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACMR0_CHM(v)   ((((reg32_t) v) << 0) & BM_MLB_ACMR0_CHM)
#else
#define BF_MLB_ACMR0_CHM(v)   (((v) << 0) & BM_MLB_ACMR0_CHM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACMR0_CHM(v)   BF_CS1(MLB_ACMR0, CHM, v)
#endif

/*!
 * @brief HW_MLB_ACMR1 - AHB Channel Mask 1 Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHM : 32; //!< Bitwise channel mask bit:
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

/* --- Register HW_MLB_ACMR1, field CHM
 *
 * Bitwise channel mask bit:
 */

#define BP_MLB_ACMR1_CHM      0
#define BM_MLB_ACMR1_CHM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MLB_ACMR1_CHM(v)   ((((reg32_t) v) << 0) & BM_MLB_ACMR1_CHM)
#else
#define BF_MLB_ACMR1_CHM(v)   (((v) << 0) & BM_MLB_ACMR1_CHM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MLB_ACMR1_CHM(v)   BF_CS1(MLB_ACMR1, CHM, v)
#endif



/*!
 * @brief All MLB module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
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
} hw_mlb_t
#endif

//! @brief Macro to access all MLB registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MLB(0)</code>.
#define HW_MLB     (*(volatile hw_mlb_t *) REGS_MLB_BASE)


#endif // _MLB_H
