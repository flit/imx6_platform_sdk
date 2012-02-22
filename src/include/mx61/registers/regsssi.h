/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SSI_H
#define _SSI_H

#include "regs.h"

#ifndef REGS_SSI_BASE
#define REGS_SSI0_BASE (REGS_BASE + 0x02028000)
#define REGS_SSI1_BASE (REGS_BASE + 0x0202c000)
#define REGS_SSI2_BASE (REGS_BASE + 0x02030000)
#define REGS_SSI_BASE(x) ( x == 0 ? REGS_SSI0_BASE : x == 1 ? REGS_SSI1_BASE : x == 2 ? REGS_SSI2_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_SSI_SSI_STX - SSI Transmit Data Register n
 *
 * Enable SSI (SSIEN=1) before writing to SSI Transmit Data                             Registers.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STXN : 32; //!< SSI Transmit Data. These bits store the data to be transmitted by the These are implemented as the first word of their respective Tx FIFOs. Data written to these registers is transferred to the Transmit Shift Register (TXSR), when shifting of the previous data is complete. If both FIFOs are in use, data is alternately transferred from STX0 and STX1, to TXSR. Multiple writes to the STX registers will not result in the previous data being over-written by the subsequent data. STX1 can only be used in Two-Channel mode of operation. Protection from over-writing is present irrespective of whether the transmitter is enabled or not.  Example 1: If Tx FIFO0 is in use and user writes Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write Data1. Data1... Data8 Data15 are stored in the FIFO while Data9 Data16 is discarded.  Example 2: If Tx FIFO0 is not in use and user writes Data1, Data2 to STX0, then Data2 will not over-write Data1 and will be discarded.
    } B;
} hw_ssi_ssi_stx_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STX register
 */
#define HW_SSI_SSI_STX_ADDR(x)      (REGS_SSI_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STX(x)           (*(volatile hw_ssi_ssi_stx_t *) HW_SSI_SSI_STX_ADDR(x))
#define HW_SSI_SSI_STX_RD(x)        (HW_SSI_SSI_STX(x).U)
#define HW_SSI_SSI_STX_WR(x, v)     (HW_SSI_SSI_STX(x).U = (v))
#define HW_SSI_SSI_STX_SET(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) |  (v)))
#define HW_SSI_SSI_STX_CLR(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) & ~(v)))
#define HW_SSI_SSI_STX_TOG(x, v)    (HW_SSI_SSI_STX_WR(x, HW_SSI_SSI_STX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STX bitfields
 */

/* --- Register HW_SSI_SSI_STX, field STXN
 *
 * SSI Transmit Data. These bits store the data to be transmitted by the
 * These are implemented as the first word of their respective Tx
 * FIFOs. Data written to these registers is transferred to the
 * Transmit Shift Register (TXSR), when shifting of the previous data
 * is complete. If both FIFOs are in use, data is alternately
 * transferred from STX0 and STX1, to TXSR. Multiple writes to the STX
 * registers will not result in the previous data being over-written by
 * the subsequent data. STX1 can only be used in Two-Channel mode of
 * operation. Protection from over-writing is present irrespective of
 * whether the transmitter is enabled or not.  Example 1: If Tx FIFO0 is in use and user writes
 * Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write
 * Data1. Data1... Data8 Data15 are stored in the FIFO                                     while
 * Data9 Data16 is discarded.  Example 2: If Tx FIFO0 is not in use and user writes Data1, Data2 to
 * STX0, then Data2 will not over-write Data1 and will be                                 discarded.
 */

#define BP_SSI_SSI_STX_STXN      0
#define BM_SSI_SSI_STX_STXN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STX_STXN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STX_STXN)
#else
#define BF_SSI_SSI_STX_STXN(v)   (((v) << 0) & BM_SSI_SSI_STX_STXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STX_STXN(v)   BF_CS1(SSI_SSI_STX, STXN, v)
#endif

/*!
 * @brief HW_SSI_SSI_SRX - SSI Receive Data Register n
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SRXN : 32; //!< SSI Receive Data. These bits store the data received by the These are implemented as the first word of their respective Rx FIFOs. These bits receive data from the RXSR depending on the mode of operation. In case both FIFOs are in use, data is transferred to each data register alternately. SRX1 can only be used in Two-Channel mode of operation.
    } B;
} hw_ssi_ssi_srx_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRX register
 */
#define HW_SSI_SSI_SRX_ADDR(x)      (REGS_SSI_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRX(x)           (*(volatile hw_ssi_ssi_srx_t *) HW_SSI_SSI_SRX_ADDR(x))
#define HW_SSI_SSI_SRX_RD(x)        (HW_SSI_SSI_SRX(x).U)
#define HW_SSI_SSI_SRX_WR(x, v)     (HW_SSI_SSI_SRX(x).U = (v))
#define HW_SSI_SSI_SRX_SET(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) |  (v)))
#define HW_SSI_SSI_SRX_CLR(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) & ~(v)))
#define HW_SSI_SSI_SRX_TOG(x, v)    (HW_SSI_SSI_SRX_WR(x, HW_SSI_SSI_SRX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRX bitfields
 */

/* --- Register HW_SSI_SSI_SRX, field SRXN
 *
 * SSI Receive Data. These bits store the data received by the These are
 * implemented as the first word of their respective Rx FIFOs. These
 * bits receive data from the RXSR depending on the mode of operation.
 * In case both FIFOs are in use, data is transferred to each data
 * register alternately. SRX1 can only be used in Two-Channel mode of
 * operation.
 */

#define BP_SSI_SSI_SRX_SRXN      0
#define BM_SSI_SSI_SRX_SRXN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRX_SRXN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRX_SRXN)
#else
#define BF_SSI_SSI_SRX_SRXN(v)   (((v) << 0) & BM_SSI_SSI_SRX_SRXN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRX_SRXN(v)   BF_CS1(SSI_SSI_SRX, SRXN, v)
#endif

/*!
 * @brief HW_SSI_SSI_SCR - SSI Control Register
 *
 * The SSI Control Register (SSI_SCR) sets up the SSI reset is controlled by
 * bit 0 in the SSI_SCR. SSI operating modes are also selected in this
 * register (except AC97 mode which is selected in the SSI_SACNT
 * register).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SSIEN : 1; //!< SSIEN - SSI Enable  This bit is used to enable/disable the When disabled, all SSI status bits are preset to the same state produced by the power-on reset, all control bits are unaffected, the contents of Tx and Rx FIFOs are cleared. When SSI is disabled, all internal clocks are disabled (except register access clock).
        unsigned TE : 1; //!< Transmit Enable. This control bit enables the transmit section of the It enables the transfer of the contents of the STX registers to the TXSR and also enables the internal transmit clock. The transmit section is enabled when this bit is set and a frame boundary is detected. When this bit is cleared, the transmitter continues to send data until the end of the current frame and then stops. Data can be written to the STX registers with the TE bit cleared (the corresponding TDE bit will be cleared). If the TE bit is cleared and then set again before the second to last bit of the last time slot in the current frame, data transmission continues without interruption. The normal transmit enable sequence is to write data to the STX register(s) and then set the TE bit. The normal disable sequence is to clear the TE and TIE bits after the TDE bit is set.  In gated clock mode, clearing the TE bit results in the clock stopping after the data currently in TXSR has shifted out. When the TE bit is set, the clock starts immediately (for internal gated clock mode). TE should not be toggled in the same frame.  After enabling/disabling transmission, SSI expects 4 setup clock cycles before arrival of frame-sync for frame-sync to be accepted/rejected by In case of fewer clock cycles, there is high probability of the frame-sync to get missed.  Note: If continuos clock is not provided, SSI expects 6 clock cycles before arrival of frame-sync for frame-sync to be accepted by
        unsigned RE : 1; //!< Receive Enable. This control bit enables the receive section of the When this bit is enabled, data reception starts with the arrival of the next frame sync. If data is being received when this bit is cleared, data reception continues until the end of the current frame and then stops. If this bit is set again before the second to last bit of the last time slot in the current frame, then reception continues without interruption. RE should not be toggled in the same frame.
        unsigned NET : 1; //!< Network Mode. This bit controls whether SSI is in network mode or not.
        unsigned SYN : 1; //!< Synchronous Mode. This bit controls whether SSI is in synchronous mode or not. In synchronous mode, the transmit and receive sections of SSI share a common clock port (STCK) and frame sync port (STFS).
        unsigned I2S_MODE : 2; //!< I2S Mode Select. These bits allow the SSI to operate in Normal, I2S Master or I2S Slave mode. Refer to for a detailed description of I2S Mode of operation. Refer to for details regarding settings.
        unsigned SYS_CLK_EN : 1; //!< Network Clock (Oversampling Clock) Enable. When set, this bit allows the SSI to output the network clock (ccm_ssi_clk) at the SRCK port, provided that synchronous mode, and transmit internal clock mode are set. The relationship between bit clock and network clock (ccm_ssi_clk) is determined by DIV2, PSR, and PM bits. This feature is especially useful in I2S Master mode to output network clock (oversampling clock) on SRCK port.
        unsigned TCH_EN : 1; //!< Two-Channel Operation Enable. This bit allows SSI to operate in the two-channel mode.In this mode while receiving, the RXSR transfers data to SRX0 and SRX1 alternately and while transmitting, data is alternately transferred from STX0 and STX1 to TXSR. For an even number of slots, Two-Channel Operation can be enabled to optimize usage of both FIFOs or disabled as in the case of odd number of active slots. This feature is especially useful in I2S mode, where data for Left Speaker can be placed in Tx-FIFO0 and for Right speaker in Tx-FIFO1.  Review_Q&A: Mike Austin-Which SRX and STX registers are not used with two-channel mode disabled?
        unsigned CLK_IST : 1; //!< Clock Idle State. This bit controls the idle state of the transmit clock port during SSI internal gated mode.  Note: When Clock idle state is '1' the clock polarity should always be negedge triggered and when Clock idle = '0' the clock polarity should always be positive edge triggered.
        unsigned TFR_CLK_DIS : 1; //!< Transmit Frame Clock Disable.  This bit provide option to keep the Frame-sync and Clock enabled or disabled after current transmit frame, in which transmitter is disabled by clearing TE bit. Writing to this bit has effect only when SSI is enabled TE is disabled.
        unsigned RFR_CLK_DIS : 1; //!< Receive Frame Clock Disable.  This bit provides the option to keep the Frame-sync and Clock enabled or to disable them after the receive frame in which the receiver is disabled. Writing to this bit has effect only when RE is disabled.The receiver is disabled by clearing the RE bit.
        unsigned SYNC_TX_FS : 1; //!< SYNC_FS_TX bit provides a safe window for TE to be visible to the internal circuit which is just after FS occurrence. When SYNC_TX_FS is set, TE(SCR[1]) gets latched on FS occurrence & latched TE is used to enable/disable SSI transmitter. TE needs setup of 2 bit-clock cycles before occurrence of FS. If TE is changed within 2 bit-clock cycles of FS occurrence, there is high probability that TE will be latched on next FS.  Note: With TFR_CLK_DIS feature on, TE is used directly to enable transmitter in following cases (i) Sync mode & Rx disabled (ii) Async Mode. Latched-TE is used to disable the transmitter.  This bit has no relevance in gated mode and AC97 mode.
        unsigned RESERVED0 : 19; //!< Reserved
    } B;
} hw_ssi_ssi_scr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SCR register
 */
#define HW_SSI_SSI_SCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SCR(x)           (*(volatile hw_ssi_ssi_scr_t *) HW_SSI_SSI_SCR_ADDR(x))
#define HW_SSI_SSI_SCR_RD(x)        (HW_SSI_SSI_SCR(x).U)
#define HW_SSI_SSI_SCR_WR(x, v)     (HW_SSI_SSI_SCR(x).U = (v))
#define HW_SSI_SSI_SCR_SET(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) |  (v)))
#define HW_SSI_SSI_SCR_CLR(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) & ~(v)))
#define HW_SSI_SSI_SCR_TOG(x, v)    (HW_SSI_SSI_SCR_WR(x, HW_SSI_SSI_SCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SCR bitfields
 */

/* --- Register HW_SSI_SSI_SCR, field SSIEN
 *
 * SSIEN - SSI Enable  This bit is used to enable/disable the When disabled, all SSI status
 * bits are preset to the same state produced by the power-on reset,
 * all control bits are unaffected, the contents of Tx and Rx FIFOs are
 * cleared. When SSI is disabled, all internal clocks are disabled
 * (except register access clock).
 */

#define BP_SSI_SSI_SCR_SSIEN      0
#define BM_SSI_SSI_SCR_SSIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SSIEN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SCR_SSIEN)
#else
#define BF_SSI_SSI_SCR_SSIEN(v)   (((v) << 0) & BM_SSI_SSI_SCR_SSIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SSIEN(v)   BF_CS1(SSI_SSI_SCR, SSIEN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TE
 *
 * Transmit Enable. This control bit enables the transmit section of the
 * It enables the transfer of the contents of the STX registers to the
 * TXSR and also enables the internal transmit clock. The transmit
 * section is enabled when this bit is set and a frame boundary is
 * detected. When this bit is cleared, the transmitter continues to
 * send data until the end of the current frame and then stops. Data
 * can be written to the STX registers with the TE bit cleared (the
 * corresponding TDE bit will be cleared). If the TE bit is cleared and
 * then set again before the second to last bit of the last time slot
 * in the current frame, data transmission continues without
 * interruption. The normal transmit enable sequence is to write data
 * to the STX register(s) and then set the TE bit. The normal disable
 * sequence is to clear the TE and TIE bits after the TDE bit is
 * set.  In gated clock mode, clearing the TE bit results in the clock
 * stopping after the data currently in TXSR has shifted out. When the
 * TE bit is set, the clock starts immediately (for internal gated
 * clock mode). TE should not be toggled in the same frame.  After enabling/disabling transmission,
 * SSI expects 4 setup clock                                 cycles before arrival of frame-sync for
 * frame-sync to be                                 accepted/rejected by In case of fewer clock
 * cycles, there is high                                 probability of the frame-sync to get
 * missed.  Note: If continuos clock is not provided, SSI expects 6 clock cycles
 * before arrival of frame-sync for frame-sync to be accepted by
 */

#define BP_SSI_SSI_SCR_TE      1
#define BM_SSI_SSI_SCR_TE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TE(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SCR_TE)
#else
#define BF_SSI_SSI_SCR_TE(v)   (((v) << 1) & BM_SSI_SSI_SCR_TE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TE(v)   BF_CS1(SSI_SSI_SCR, TE, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field RE
 *
 * Receive Enable. This control bit enables the receive section of the
 * When this bit is enabled, data reception starts with the arrival of
 * the next frame sync. If data is being received when this bit is
 * cleared, data reception continues until the end of the current frame
 * and then stops. If this bit is set again before the second to last
 * bit of the last time slot in the current frame, then reception
 * continues without interruption. RE should not be toggled in the same
 * frame.
 */

#define BP_SSI_SSI_SCR_RE      2
#define BM_SSI_SSI_SCR_RE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_RE(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SCR_RE)
#else
#define BF_SSI_SSI_SCR_RE(v)   (((v) << 2) & BM_SSI_SSI_SCR_RE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_RE(v)   BF_CS1(SSI_SSI_SCR, RE, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field NET
 *
 * Network Mode. This bit controls whether SSI is in network mode or
 * not.
 */

#define BP_SSI_SSI_SCR_NET      3
#define BM_SSI_SSI_SCR_NET      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_NET(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SCR_NET)
#else
#define BF_SSI_SSI_SCR_NET(v)   (((v) << 3) & BM_SSI_SSI_SCR_NET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_NET(v)   BF_CS1(SSI_SSI_SCR, NET, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SYN
 *
 * Synchronous Mode. This bit controls whether SSI is in synchronous
 * mode or not. In synchronous mode, the transmit and receive sections
 * of SSI share a common clock port (STCK) and frame sync port
 * (STFS).
 */

#define BP_SSI_SSI_SCR_SYN      4
#define BM_SSI_SSI_SCR_SYN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYN(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SCR_SYN)
#else
#define BF_SSI_SSI_SCR_SYN(v)   (((v) << 4) & BM_SSI_SSI_SCR_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYN(v)   BF_CS1(SSI_SSI_SCR, SYN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field I2S_MODE
 *
 * I2S Mode Select. These bits allow the SSI to operate in Normal, I2S
 * Master or I2S Slave mode. Refer to for a detailed description of I2S
 * Mode of operation. Refer to for details regarding                                 settings.
 */

#define BP_SSI_SSI_SCR_I2S_MODE      5
#define BM_SSI_SSI_SCR_I2S_MODE      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_I2S_MODE(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SCR_I2S_MODE)
#else
#define BF_SSI_SSI_SCR_I2S_MODE(v)   (((v) << 5) & BM_SSI_SSI_SCR_I2S_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_I2S_MODE(v)   BF_CS1(SSI_SSI_SCR, I2S_MODE, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SYS_CLK_EN
 *
 * Network Clock (Oversampling Clock) Enable. When set, this bit allows
 * the SSI to output the network clock (ccm_ssi_clk) at the SRCK port, provided that synchronous
 * mode, and transmit internal clock mode are set. The relationship
 * between bit clock and network clock (ccm_ssi_clk) is determined by DIV2, PSR, and PM bits.
 * This feature is especially useful in I2S Master mode to output
 * network clock (oversampling clock) on SRCK port.
 */

#define BP_SSI_SSI_SCR_SYS_CLK_EN      7
#define BM_SSI_SSI_SCR_SYS_CLK_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#else
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   (((v) << 7) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYS_CLK_EN(v)   BF_CS1(SSI_SSI_SCR, SYS_CLK_EN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TCH_EN
 *
 * Two-Channel Operation Enable. This bit allows SSI to operate in the
 * two-channel mode.In this mode while receiving, the RXSR transfers
 * data to SRX0 and SRX1 alternately and while transmitting, data is
 * alternately transferred from STX0 and STX1 to TXSR. For an even
 * number of slots, Two-Channel Operation can be enabled to optimize
 * usage of both FIFOs or disabled as in the case of odd number of
 * active slots. This feature is especially useful in I2S mode, where
 * data for Left Speaker can be placed in Tx-FIFO0 and for Right
 * speaker in Tx-FIFO1.  Review_Q&A: Mike Austin-Which SRX and STX
 * registers are not used with two-channel mode disabled?
 */

#define BP_SSI_SSI_SCR_TCH_EN      8
#define BM_SSI_SSI_SCR_TCH_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TCH_EN(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SCR_TCH_EN)
#else
#define BF_SSI_SSI_SCR_TCH_EN(v)   (((v) << 8) & BM_SSI_SSI_SCR_TCH_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TCH_EN(v)   BF_CS1(SSI_SSI_SCR, TCH_EN, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field CLK_IST
 *
 * Clock Idle State. This bit controls the idle state of the transmit
 * clock port during SSI internal gated mode.  Note: When Clock idle state is '1' the clock polarity
 * should always                                 be negedge triggered and when Clock idle = '0' the
 * clock polarity                                 should always be positive edge triggered.
 */

#define BP_SSI_SSI_SCR_CLK_IST      9
#define BM_SSI_SSI_SCR_CLK_IST      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_CLK_IST(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SCR_CLK_IST)
#else
#define BF_SSI_SSI_SCR_CLK_IST(v)   (((v) << 9) & BM_SSI_SSI_SCR_CLK_IST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_CLK_IST(v)   BF_CS1(SSI_SSI_SCR, CLK_IST, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field TFR_CLK_DIS
 *
 * Transmit Frame Clock Disable.  This bit provide option to keep the Frame-sync and Clock enabled
 * or                                 disabled after current transmit frame, in which transmitter is
 * disabled by clearing TE bit. Writing to this bit has effect only
 * when SSI is enabled TE is disabled.
 */

#define BP_SSI_SSI_SCR_TFR_CLK_DIS      10
#define BM_SSI_SSI_SCR_TFR_CLK_DIS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#else
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   (((v) << 10) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_TFR_CLK_DIS(v)   BF_CS1(SSI_SSI_SCR, TFR_CLK_DIS, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field RFR_CLK_DIS
 *
 * Receive Frame Clock Disable.  This bit provides the option to keep the Frame-sync and Clock
 * enabled                                 or to disable them after the receive frame in which the
 * receiver is                                 disabled. Writing to this bit has effect only when RE
 * is                                 disabled.The receiver is disabled by clearing the RE bit.
 */

#define BP_SSI_SSI_SCR_RFR_CLK_DIS      11
#define BM_SSI_SSI_SCR_RFR_CLK_DIS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   ((((reg32_t) v) << 11) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#else
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   (((v) << 11) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_RFR_CLK_DIS(v)   BF_CS1(SSI_SSI_SCR, RFR_CLK_DIS, v)
#endif

/* --- Register HW_SSI_SSI_SCR, field SYNC_TX_FS
 *
 * SYNC_FS_TX bit provides a safe window for TE to be visible to the
 * internal circuit which is just after FS occurrence. When SYNC_TX_FS
 * is set, TE(SCR[1]) gets latched on FS occurrence & latched TE is
 * used to enable/disable SSI transmitter. TE needs setup of 2                                 bit-
 * clock cycles before occurrence of FS. If TE is changed within 2
 * bit-clock cycles of FS occurrence, there is high probability that TE
 * will be latched on next FS.  Note: With TFR_CLK_DIS feature on, TE is used directly to enable
 * transmitter in following cases (i) Sync mode & Rx disabled (ii)
 * Async Mode. Latched-TE is used to disable the transmitter.  This bit has no relevance in gated
 * mode and AC97 mode.
 */

#define BP_SSI_SSI_SCR_SYNC_TX_FS      12
#define BM_SSI_SSI_SCR_SYNC_TX_FS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#else
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   (((v) << 12) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SCR_SYNC_TX_FS(v)   BF_CS1(SSI_SSI_SCR, SYNC_TX_FS, v)
#endif

/*!
 * @brief HW_SSI_SSI_SISR - SSI Interrupt Status Register
 *
 * The SSI Interrupt Status Register (SSI_SISR) is used to monitor the SSI. This
 * register is used by the core to interrogate the status of the In gated
 * mode of operation the TFS, RFS, TLS, RLS, TFRC and RFRC bits of AISR
 * register are not generated. The status bits are described in the
 * following table.   SSI Status flags are valid when SSI is enabled.  See and for interrupt source
 * mapping.  All the flags in the SSI_SISR are updated after the first bit of the
 * next SSI word has completed transmission or reception. Certain
 * status bits (ROE0/1 and TUE0/1) are cleared by writing 1 to the
 * corresponding interrupt status bit in SSI_SISR.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFE0 : 1; //!< Transmit FIFO Empty 0. This flag is set when the empty slots in Tx FIFO exceed or are equal to the selected Tx FIFO WaterMark 0 (TFWM0) threshold. The setting of TFE0 only causes an interrupt when TIE and TFE0_EN are set and Tx FIFO0 is enabled. The TFE0 bit is automatically cleared when the data level in Tx FIFO0 becomes more than the amount specified by the watermark bits. The TFE0 bit is set by POR and SSI reset.
        unsigned TFE1 : 1; //!< Transmit FIFO Empty 1. This flag is set when the empty slots in Tx FIFO exceed or are equal to the selected Tx FIFO WaterMark 1 (TFWM1) threshold and the Two-Channel mode is selected. The setting of TFE1 only causes an interrupt when TIE and TFE1_EN are set, Tx FIFO1 is enabled and Two-Channel mode is selected. The TFE1 bit is automatically cleared when the data level in Tx FIFO1 becomes more than the amount specified by the watermark bits. The TFE1 bit is set by POR and SSI reset.
        unsigned RFF0 : 1; //!< Receive FIFO Full 0. This flag is set when Rx FIFO0 is enabled and the data level in Rx FIFO0 reaches the selected Rx FIFO WaterMark 0 (RFWM0) threshold. The setting of RFF0 only causes an interrupt when RIE and RFF0_EN are set and Rx FIFO0 is enabled. RFF0 is automatically cleared when the amount of data in Rx FIFO0 falls below the threshold. The RFF0 bit is cleared by POR and SSI reset.  When Rx FIFO0 contains 8 15 words, the maximum it can hold, all further data received (for storage in this FIFO) is ignored until the FIFO contents are read.
        unsigned RFF1 : 1; //!< Receive FIFO Full 1. This flag is set when Rx FIFO1 is enabled, the data level in Rx FIFO1 reaches the selected Rx FIFO WaterMark 1 (RFWM1) threshold and the SSI is in Two-Channel mode. The setting of RFF1 only causes an interrupt when RIE and RFF1_EN are set, Rx FIFO1 is enabled and the Two-Channel mode is selected. RFF1 is automatically cleared when the amount of data in Rx FIFO1 falls below the threshold. The RFF1 bit is cleared by POR and SSI reset.  When Rx FIFO1 contains 8 15 words, the maximum it can hold, all further data received (for storage in this FIFO) is ignored until the FIFO contents are read.
        unsigned RLS : 1; //!< Receive Last Time Slot. This flag indicates the last time slot in a frame. When set, it indicates that the current time slot is the last receive time slot of the frame. RLS is set at the end of the last time slot and causes the SSI to issue an interrupt (if RIE and RLS_EN are set). RLS is cleared when the SISR is read with this bit set. The RLS bit is cleared by POR and SSI reset.
        unsigned TLS : 1; //!< Transmit Last Time Slot. This flag indicates the last time slot in a frame. When set, it indicates that the current time slot is the last time slot of the frame. TLS is set at the start of the last transmit time slot and causes the SSI to issue an interrupt (if TIE and TLS_EN are set). TLS is not generated when frame rate is 1 in normal mode of operation. TLS is cleared when the SISR is read with this bit set. The TLS bit is cleared by POR and SSI reset.
        unsigned RFS : 1; //!< Receive Frame Sync. This flag indicates the occurrence of receive frame sync. In Network mode, the RFS bit is set when the first slot of the frame is being received. It is cleared when the next slot begins to be received. In Normal mode, this bit is always high (When DC = 0). This flag causes an interrupt if RIE and RFS_EN are set. The RFS bit is cleared by POR and SSI reset.
        unsigned TFS : 1; //!< Transmit Frame Sync. This flag indicates the occurrence of transmit frame sync. Data written to the STX registers during the time slot when the TFS flag is set, is sent during the second time slot (in Network mode) or in the next first time slot (in Normal mode). In Network mode, the TFS bit is set during transmission of the first time slot of the frame and is then cleared when starting transmission of the next time slot. In Normal mode, this bit is high for the first time slot. This flag causes an interrupt if TIE and TFS_EN are set. The TFS bit is cleared by POR and SSI reset.
        unsigned TUE0 : 1; //!< Transmitter Underrun Error 0. This flag is set when the TXSR is empty (no data to be transmitted), the TDE0 flag is set and a transmit time slot occurs. When a transmit underrun error occurs, the previous data is retransmitted. In Network mode, each time slot requires data transmission (unless masked through STMSK register), when the transmitter is enabled (TE is set).  The TUE0 flag causes an interrupt if TIE and TUE0_EN are set.  The TUE0 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit.
        unsigned TUE1 : 1; //!< Transmitter Underrun Error 1. This flag is set when the TXSR is empty (no data to be transmitted), the TDE1 flag is set, a transmit time slot occurs and the SSI is in Two-Channel mode. When a transmit underrun error occurs, the previous data is retransmitted. In Network mode, each time slot requires data transmission (unless masked through STMSK register), when the transmitter is enabled (TE is set).  The TUE1 flag causes an interrupt if TIE and TUE1_EN are set.  The TUE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit.
        unsigned ROE0 : 1; //!< Receiver Overrun Error 0. This flag is set when the RXSR is filled and ready to transfer to SRX0 register or to Rx FIFO 0 (when enabled) and these are already full. If Rx FIFO 0 is enabled, this is indicated by RFF0 flag, else this is indicated by the RDR0 flag. The RXSR is not transferred in this case.  The ROE0 flag causes an interrupt if RIE and ROE0_EN are set.  The ROE0 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit. Clearing the RE bit does not affect the ROE0 bit.
        unsigned ROE1 : 1; //!< Receiver Overrun Error 1. This flag is set when the RXSR is filled and ready to transfer to SRX1 register or to Rx FIFO 1 (when enabled) and these are already full and Two-Channel mode is selected. If Rx FIFO 1 is enabled, this is indicated by RFF1 flag, else this is indicated by the RDR1 flag. The RXSR is not transferred in this case.  The ROE1 flag causes an interrupt if RIE and ROE1_EN are set.  The ROE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit. Clearing the RE bit does not affect the ROE1 bit.
        unsigned TDE0 : 1; //!< Transmit Data Register Empty 0. This flag is set whenever data is transferred to TXSR from STX0 register.  If Tx FIFO 0 is enabled, this occurs when there is at least one empty slot in STX0 or Tx FIFO 0. If Tx FIFO 0 is not enabled, this occurs when the contents of STX0 are transferred to TXSR.  The TDE0 bit is cleared when the Core writes to STX0. If TIE and TDE0_EN are set, an SSI Transmit Data 0 interrupt request is issued on setting of TDE0 bit. The TDE0 bit is cleared by POR and SSI reset.
        unsigned TDE1 : 1; //!< Transmit Data Register Empty 1. This flag is set whenever data is transferred to TXSR from STX1 register and Two-Channel mode is selected.  If Tx FIFO1 is enabled, this occurs when there is at least one empty slot in STX1 or Tx FIFO1. If Tx FIFO1 is not enabled, this occurs when the contents of STX1 are transferred to TXSR.  The TDE1 bit is cleared when the Core writes to STX1. If TIE and TDE1_EN are set, an SSI Transmit Data 1 interrupt request is issued on setting of TDE1 bit. The TDE1 bit is cleared by POR and SSI reset.
        unsigned RDR0 : 1; //!< Receive Data Ready 0. This flag bit is set when SRX0 or Rx FIFO 0 is loaded with a new value.  RDR0 is cleared when the Core reads the SRX0 register. If Rx FIFO 0 is enabled, RDR0 is cleared when the FIFO is empty.  If RIE and RDR0_EN are set, a Receive Data 0 interrupt request is issued on setting of RDR0 bit in case Rx FIFO0 is disabled, if the FIFO is enabled, the interrupt is issued on RFF0 assertion. The RDR0 bit is cleared by POR and SSI reset.
        unsigned RDR1 : 1; //!< Receive Data Ready 1. This flag bit is set when SRX1 or Rx FIFO 1 is loaded with a new value and Two-Channel mode is selected.  RDR1 is cleared when the Core reads the SRX1 register. If Rx FIFO 1 is enabled, RDR1 is cleared when the FIFO is empty.  If RIE and RDR1_EN are set, a Receive Data 1 interrupt request is issued on setting of RDR1 bit in case Rx FIFO1 is disabled, if the FIFO is enabled, the interrupt is issued on RFF1 assertion. The RDR1 bit is cleared by POR and SSI reset.
        unsigned RXT : 1; //!< Receive Tag Updated. This status bit is set each time there is a difference in the previous and current value of the received tag. It causes the Receive Tag Interrupt (if RXT_EN bit is set). This bit is cleared on reading the SATAG register.
        unsigned CMDDU : 1; //!< Command Data Register Updated. This bit causes the Command Data Updated interrupt (when CMDDU_EN bit is set). This status bit is set each time there is a difference in the previous and current value of the received Command Data. This bit is cleared on reading the SACDAT register.
        unsigned CMDAU : 1; //!< Command Address Register Updated. This bit causes the Command Address Updated interrupt (when CMDAU_EN bit is set). This status bit is set each time there is a difference in the previous and current value of the received Command Address. This bit is cleared on reading the SACADD register.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned TFRC : 1; //!< Transmit Frame Complete. This flag is set at the end of the frame during which Transmitter is disabled. If Transmit Frame & Clock are not disabled in the same frame, this flag is also set at the end of the frame in which Transmit Frame & Clock are disabled. See description of TFR_CLK_DIS bit for more details on how to disable Transmit Frame & Clock or keep them enabled after transmitter is disabled.
        unsigned RFRC : 1; //!< Receive Frame Complete. This flag is set at the end of the frame during which Receiver is disabled. If Receive Frame & Clock are not disabled in the same frame, this flag is also set at the end of the frame in which Receive Frame & Clock are disabled. See the description of RFR_CLK_DIS bit for more details on how to disable Receiver Frame & Clock or keep them enabled after receiver is disabled.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_ssi_ssi_sisr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SISR register
 */
#define HW_SSI_SSI_SISR_ADDR(x)      (REGS_SSI_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SISR(x)           (*(volatile hw_ssi_ssi_sisr_t *) HW_SSI_SSI_SISR_ADDR(x))
#define HW_SSI_SSI_SISR_RD(x)        (HW_SSI_SSI_SISR(x).U)
#define HW_SSI_SSI_SISR_WR(x, v)     (HW_SSI_SSI_SISR(x).U = (v))
#define HW_SSI_SSI_SISR_SET(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) |  (v)))
#define HW_SSI_SSI_SISR_CLR(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) & ~(v)))
#define HW_SSI_SSI_SISR_TOG(x, v)    (HW_SSI_SSI_SISR_WR(x, HW_SSI_SSI_SISR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SISR bitfields
 */

/* --- Register HW_SSI_SSI_SISR, field TFE0
 *
 * Transmit FIFO Empty 0. This flag is set when the empty slots in Tx
 * FIFO exceed or are equal to the selected Tx FIFO WaterMark 0 (TFWM0)
 * threshold. The setting of TFE0 only causes an interrupt when TIE and
 * TFE0_EN are set and Tx FIFO0 is enabled. The TFE0 bit is
 * automatically cleared when the data level in Tx FIFO0 becomes more
 * than the amount specified by the watermark bits. The TFE0 bit is set
 * by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_TFE0      0
#define BM_SSI_SSI_SISR_TFE0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFE0(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SISR_TFE0)
#else
#define BF_SSI_SSI_SISR_TFE0(v)   (((v) << 0) & BM_SSI_SSI_SISR_TFE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFE0(v)   BF_CS1(SSI_SSI_SISR, TFE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFE1
 *
 * Transmit FIFO Empty 1. This flag is set when the empty slots in Tx
 * FIFO exceed or are equal to the selected Tx FIFO WaterMark 1 (TFWM1)
 * threshold and the Two-Channel mode is selected. The setting of TFE1
 * only causes an interrupt when TIE and TFE1_EN are set, Tx FIFO1 is
 * enabled and Two-Channel mode is selected. The TFE1 bit is
 * automatically cleared when the data level in Tx FIFO1 becomes more
 * than the amount specified by the watermark bits. The TFE1 bit is set
 * by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_TFE1      1
#define BM_SSI_SSI_SISR_TFE1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFE1(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SISR_TFE1)
#else
#define BF_SSI_SSI_SISR_TFE1(v)   (((v) << 1) & BM_SSI_SSI_SISR_TFE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFE1(v)   BF_CS1(SSI_SSI_SISR, TFE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFF0
 *
 * Receive FIFO Full 0. This flag is set when Rx FIFO0 is enabled and
 * the data level in Rx FIFO0 reaches the selected Rx FIFO WaterMark 0
 * (RFWM0) threshold. The setting of RFF0 only causes an interrupt when
 * RIE and RFF0_EN are set and Rx FIFO0 is enabled. RFF0 is
 * automatically cleared when the amount of data in Rx FIFO0 falls
 * below the threshold. The RFF0 bit is cleared by POR and SSI
 * reset.  When Rx FIFO0 contains 8 15 words, the maximum it can
 * hold, all further data received (for storage in this FIFO) is
 * ignored until the FIFO contents are read.
 */

#define BP_SSI_SSI_SISR_RFF0      2
#define BM_SSI_SSI_SISR_RFF0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFF0(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SISR_RFF0)
#else
#define BF_SSI_SSI_SISR_RFF0(v)   (((v) << 2) & BM_SSI_SSI_SISR_RFF0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFF0(v)   BF_CS1(SSI_SSI_SISR, RFF0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFF1
 *
 * Receive FIFO Full 1. This flag is set when Rx FIFO1 is enabled, the
 * data level in Rx FIFO1 reaches the selected Rx FIFO WaterMark 1
 * (RFWM1) threshold and the SSI is in Two-Channel mode. The setting of
 * RFF1 only causes an interrupt when RIE and RFF1_EN are set, Rx FIFO1
 * is enabled and the Two-Channel mode is selected. RFF1 is
 * automatically cleared when the amount of data in Rx FIFO1 falls
 * below the threshold. The RFF1 bit is cleared by POR and SSI
 * reset.  When Rx FIFO1 contains 8 15 words, the maximum it can
 * hold, all further data received (for storage in this FIFO) is
 * ignored until the FIFO contents are read.
 */

#define BP_SSI_SSI_SISR_RFF1      3
#define BM_SSI_SSI_SISR_RFF1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFF1(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SISR_RFF1)
#else
#define BF_SSI_SSI_SISR_RFF1(v)   (((v) << 3) & BM_SSI_SSI_SISR_RFF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFF1(v)   BF_CS1(SSI_SSI_SISR, RFF1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RLS
 *
 * Receive Last Time Slot. This flag indicates the last time slot in a
 * frame. When set, it indicates that the current time slot is the last
 * receive time slot of the frame. RLS is set at the end of the last
 * time slot and causes the SSI to issue an interrupt (if RIE and
 * RLS_EN are set). RLS is cleared when the SISR is read with this bit
 * set. The RLS bit is cleared by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_RLS      4
#define BM_SSI_SSI_SISR_RLS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RLS(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SISR_RLS)
#else
#define BF_SSI_SSI_SISR_RLS(v)   (((v) << 4) & BM_SSI_SSI_SISR_RLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RLS(v)   BF_CS1(SSI_SSI_SISR, RLS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TLS
 *
 * Transmit Last Time Slot. This flag indicates the last time slot in a
 * frame. When set, it indicates that the current time slot is the last
 * time slot of the frame. TLS is set at the start of the last transmit
 * time slot and causes the SSI to issue an interrupt (if TIE and
 * TLS_EN are set). TLS is not generated when frame rate is 1 in normal
 * mode of operation. TLS is cleared when the SISR is read with this
 * bit set. The TLS bit is cleared by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_TLS      5
#define BM_SSI_SSI_SISR_TLS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TLS(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SISR_TLS)
#else
#define BF_SSI_SSI_SISR_TLS(v)   (((v) << 5) & BM_SSI_SSI_SISR_TLS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TLS(v)   BF_CS1(SSI_SSI_SISR, TLS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFS
 *
 * Receive Frame Sync. This flag indicates the occurrence of receive
 * frame sync. In Network mode, the RFS bit is set when the first slot
 * of the frame is being received. It is cleared when the next slot
 * begins to be received. In Normal mode, this bit is always high (When
 * DC = 0). This flag causes an interrupt if RIE and RFS_EN are set.
 * The RFS bit is cleared by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_RFS      6
#define BM_SSI_SSI_SISR_RFS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFS(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_SISR_RFS)
#else
#define BF_SSI_SSI_SISR_RFS(v)   (((v) << 6) & BM_SSI_SSI_SISR_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFS(v)   BF_CS1(SSI_SSI_SISR, RFS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFS
 *
 * Transmit Frame Sync. This flag indicates the occurrence of transmit
 * frame sync. Data written to the STX registers during the time slot
 * when the TFS flag is set, is sent during the second time slot (in
 * Network mode) or in the next first time slot (in Normal mode). In
 * Network mode, the TFS bit is set during transmission of the first
 * time slot of the frame and is then cleared when starting
 * transmission of the next time slot. In Normal mode, this bit is high
 * for the first time slot. This flag causes an interrupt if TIE and
 * TFS_EN are set. The TFS bit is cleared by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_TFS      7
#define BM_SSI_SSI_SISR_TFS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFS(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SISR_TFS)
#else
#define BF_SSI_SSI_SISR_TFS(v)   (((v) << 7) & BM_SSI_SSI_SISR_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFS(v)   BF_CS1(SSI_SSI_SISR, TFS, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TUE0
 *
 * Transmitter Underrun Error 0. This flag is set when the TXSR is empty
 * (no data to be transmitted), the TDE0 flag is set and a transmit
 * time slot occurs. When a transmit underrun error occurs, the
 * previous data is retransmitted. In Network mode, each time slot
 * requires data transmission (unless masked through STMSK register),
 * when the transmitter is enabled (TE is set).  The TUE0 flag causes an interrupt if TIE and
 * TUE0_EN are set.  The TUE0 bit is cleared by POR and SSI reset. It is also cleared by
 * writing '1' to this bit.
 */

#define BP_SSI_SSI_SISR_TUE0      8
#define BM_SSI_SSI_SISR_TUE0      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TUE0(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SISR_TUE0)
#else
#define BF_SSI_SSI_SISR_TUE0(v)   (((v) << 8) & BM_SSI_SSI_SISR_TUE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TUE0(v)   BF_CS1(SSI_SSI_SISR, TUE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TUE1
 *
 * Transmitter Underrun Error 1. This flag is set when the TXSR is empty
 * (no data to be transmitted), the TDE1 flag is set, a transmit time
 * slot occurs and the SSI is in Two-Channel mode. When a transmit
 * underrun error occurs, the previous data is retransmitted. In
 * Network mode, each time slot requires data transmission (unless
 * masked through STMSK register), when the transmitter is enabled (TE
 * is set).  The TUE1 flag causes an interrupt if TIE and TUE1_EN are set.  The TUE1 bit is cleared
 * by POR and SSI reset. It is also cleared by                                 writing '1' to this
 * bit.
 */

#define BP_SSI_SSI_SISR_TUE1      9
#define BM_SSI_SSI_SISR_TUE1      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TUE1(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SISR_TUE1)
#else
#define BF_SSI_SSI_SISR_TUE1(v)   (((v) << 9) & BM_SSI_SSI_SISR_TUE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TUE1(v)   BF_CS1(SSI_SSI_SISR, TUE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field ROE0
 *
 * Receiver Overrun Error 0. This flag is set when the RXSR is filled
 * and ready to transfer to SRX0 register or to Rx FIFO 0 (when
 * enabled) and these are already full. If Rx FIFO 0 is enabled, this
 * is indicated by RFF0 flag, else this is indicated by the RDR0 flag.
 * The RXSR is not transferred in this case.  The ROE0 flag causes an interrupt if RIE and ROE0_EN
 * are set.  The ROE0 bit is cleared by POR and SSI reset. It is also cleared by
 * writing '1' to this bit. Clearing the RE bit does not affect the
 * ROE0 bit.
 */

#define BP_SSI_SSI_SISR_ROE0      10
#define BM_SSI_SSI_SISR_ROE0      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_ROE0(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SISR_ROE0)
#else
#define BF_SSI_SSI_SISR_ROE0(v)   (((v) << 10) & BM_SSI_SSI_SISR_ROE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_ROE0(v)   BF_CS1(SSI_SSI_SISR, ROE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field ROE1
 *
 * Receiver Overrun Error 1. This flag is set when the RXSR is filled
 * and ready to transfer to SRX1 register or to Rx FIFO 1 (when
 * enabled) and these are already full and Two-Channel mode is
 * selected. If Rx FIFO 1 is enabled, this is indicated by RFF1 flag,
 * else this is indicated by the RDR1 flag. The RXSR is not transferred
 * in this case.  The ROE1 flag causes an interrupt if RIE and ROE1_EN are set.  The ROE1 bit is
 * cleared by POR and SSI reset. It is also cleared by                                 writing '1'
 * to this bit. Clearing the RE bit does not affect the                                 ROE1 bit.
 */

#define BP_SSI_SSI_SISR_ROE1      11
#define BM_SSI_SSI_SISR_ROE1      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_ROE1(v)   ((((reg32_t) v) << 11) & BM_SSI_SSI_SISR_ROE1)
#else
#define BF_SSI_SSI_SISR_ROE1(v)   (((v) << 11) & BM_SSI_SSI_SISR_ROE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_ROE1(v)   BF_CS1(SSI_SSI_SISR, ROE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TDE0
 *
 * Transmit Data Register Empty 0. This flag is set whenever data is
 * transferred to TXSR from STX0 register.  If Tx FIFO 0 is enabled, this occurs when there is at
 * least one empty                                 slot in STX0 or Tx FIFO 0. If Tx FIFO 0 is not
 * enabled, this occurs                                 when the contents of STX0 are transferred to
 * TXSR.  The TDE0 bit is cleared when the Core writes to STX0. If TIE and
 * TDE0_EN are set, an SSI Transmit Data 0 interrupt request is issued
 * on setting of TDE0 bit. The TDE0 bit is cleared by POR and SSI
 * reset.
 */

#define BP_SSI_SSI_SISR_TDE0      12
#define BM_SSI_SSI_SISR_TDE0      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TDE0(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SISR_TDE0)
#else
#define BF_SSI_SSI_SISR_TDE0(v)   (((v) << 12) & BM_SSI_SSI_SISR_TDE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TDE0(v)   BF_CS1(SSI_SSI_SISR, TDE0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TDE1
 *
 * Transmit Data Register Empty 1. This flag is set whenever data is
 * transferred to TXSR from STX1 register and Two-Channel mode is
 * selected.  If Tx FIFO1 is enabled, this occurs when there is at least one empty
 * slot in STX1 or Tx FIFO1. If Tx FIFO1 is not enabled, this occurs
 * when the contents of STX1 are transferred to TXSR.  The TDE1 bit is cleared when the Core writes
 * to STX1. If TIE and                                 TDE1_EN are set, an SSI Transmit Data 1
 * interrupt request is issued                                 on setting of TDE1 bit. The TDE1 bit
 * is cleared by POR and SSI                                 reset.
 */

#define BP_SSI_SSI_SISR_TDE1      13
#define BM_SSI_SSI_SISR_TDE1      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TDE1(v)   ((((reg32_t) v) << 13) & BM_SSI_SSI_SISR_TDE1)
#else
#define BF_SSI_SSI_SISR_TDE1(v)   (((v) << 13) & BM_SSI_SSI_SISR_TDE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TDE1(v)   BF_CS1(SSI_SSI_SISR, TDE1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RDR0
 *
 * Receive Data Ready 0. This flag bit is set when SRX0 or Rx FIFO 0 is
 * loaded with a new value.  RDR0 is cleared when the Core reads the SRX0 register. If Rx FIFO 0
 * is enabled, RDR0 is cleared when the FIFO is empty.  If RIE and RDR0_EN are set, a Receive Data 0
 * interrupt request is                                 issued on setting of RDR0 bit in case Rx
 * FIFO0 is disabled, if the                                 FIFO is enabled, the interrupt is
 * issued on RFF0 assertion. The RDR0                                 bit is cleared by POR and SSI
 * reset.
 */

#define BP_SSI_SSI_SISR_RDR0      14
#define BM_SSI_SSI_SISR_RDR0      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RDR0(v)   ((((reg32_t) v) << 14) & BM_SSI_SSI_SISR_RDR0)
#else
#define BF_SSI_SSI_SISR_RDR0(v)   (((v) << 14) & BM_SSI_SSI_SISR_RDR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RDR0(v)   BF_CS1(SSI_SSI_SISR, RDR0, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RDR1
 *
 * Receive Data Ready 1. This flag bit is set when SRX1 or Rx FIFO 1 is
 * loaded with a new value and Two-Channel mode is selected.  RDR1 is cleared when the Core reads
 * the SRX1 register. If Rx FIFO 1                                 is enabled, RDR1 is cleared when
 * the FIFO is empty.  If RIE and RDR1_EN are set, a Receive Data 1 interrupt request is
 * issued on setting of RDR1 bit in case Rx FIFO1 is disabled, if the
 * FIFO is enabled, the interrupt is issued on RFF1 assertion. The RDR1
 * bit is cleared by POR and SSI reset.
 */

#define BP_SSI_SSI_SISR_RDR1      15
#define BM_SSI_SSI_SISR_RDR1      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RDR1(v)   ((((reg32_t) v) << 15) & BM_SSI_SSI_SISR_RDR1)
#else
#define BF_SSI_SSI_SISR_RDR1(v)   (((v) << 15) & BM_SSI_SSI_SISR_RDR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RDR1(v)   BF_CS1(SSI_SSI_SISR, RDR1, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RXT
 *
 * Receive Tag Updated. This status bit is set each time there is a
 * difference in the previous and current value of the received tag. It
 * causes the Receive Tag Interrupt (if RXT_EN bit is set). This bit is
 * cleared on reading the SATAG register.
 */

#define BP_SSI_SSI_SISR_RXT      16
#define BM_SSI_SSI_SISR_RXT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RXT(v)   ((((reg32_t) v) << 16) & BM_SSI_SSI_SISR_RXT)
#else
#define BF_SSI_SSI_SISR_RXT(v)   (((v) << 16) & BM_SSI_SSI_SISR_RXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RXT(v)   BF_CS1(SSI_SSI_SISR, RXT, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field CMDDU
 *
 * Command Data Register Updated. This bit causes the Command Data
 * Updated interrupt (when CMDDU_EN bit is set). This status bit is set
 * each time there is a difference in the previous and current value of
 * the received Command Data. This bit is cleared on reading the SACDAT
 * register.
 */

#define BP_SSI_SSI_SISR_CMDDU      17
#define BM_SSI_SSI_SISR_CMDDU      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_CMDDU(v)   ((((reg32_t) v) << 17) & BM_SSI_SSI_SISR_CMDDU)
#else
#define BF_SSI_SSI_SISR_CMDDU(v)   (((v) << 17) & BM_SSI_SSI_SISR_CMDDU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_CMDDU(v)   BF_CS1(SSI_SSI_SISR, CMDDU, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field CMDAU
 *
 * Command Address Register Updated. This bit causes the Command Address
 * Updated interrupt (when CMDAU_EN bit is set). This status bit is set
 * each time there is a difference in the previous and current value of
 * the received Command Address. This bit is cleared on reading the
 * SACADD register.
 */

#define BP_SSI_SSI_SISR_CMDAU      18
#define BM_SSI_SSI_SISR_CMDAU      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_CMDAU(v)   ((((reg32_t) v) << 18) & BM_SSI_SSI_SISR_CMDAU)
#else
#define BF_SSI_SSI_SISR_CMDAU(v)   (((v) << 18) & BM_SSI_SSI_SISR_CMDAU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_CMDAU(v)   BF_CS1(SSI_SSI_SISR, CMDAU, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field TFRC
 *
 * Transmit Frame Complete. This flag is set at the end of the frame
 * during which Transmitter is disabled. If Transmit Frame & Clock
 * are not disabled in the same frame, this flag is also set at the end
 * of the frame in which Transmit Frame & Clock are disabled. See
 * description of TFR_CLK_DIS                                 bit for more details
 * on how to disable Transmit Frame & Clock or keep them enabled
 * after transmitter is disabled.
 */

#define BP_SSI_SSI_SISR_TFRC      23
#define BM_SSI_SSI_SISR_TFRC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_TFRC(v)   ((((reg32_t) v) << 23) & BM_SSI_SSI_SISR_TFRC)
#else
#define BF_SSI_SSI_SISR_TFRC(v)   (((v) << 23) & BM_SSI_SSI_SISR_TFRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_TFRC(v)   BF_CS1(SSI_SSI_SISR, TFRC, v)
#endif

/* --- Register HW_SSI_SSI_SISR, field RFRC
 *
 * Receive Frame Complete. This flag is set at the end of the frame
 * during which Receiver is disabled. If Receive Frame & Clock are
 * not disabled in the same frame, this flag is also set at the end of
 * the frame in which Receive Frame & Clock are disabled. See the
 * description of RFR_CLK_DIS                                   bit for more details
 * on how to disable Receiver Frame & Clock or keep them enabled
 * after receiver is disabled.
 */

#define BP_SSI_SSI_SISR_RFRC      24
#define BM_SSI_SSI_SISR_RFRC      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SISR_RFRC(v)   ((((reg32_t) v) << 24) & BM_SSI_SSI_SISR_RFRC)
#else
#define BF_SSI_SSI_SISR_RFRC(v)   (((v) << 24) & BM_SSI_SSI_SISR_RFRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SISR_RFRC(v)   BF_CS1(SSI_SSI_SISR, RFRC, v)
#endif

/*!
 * @brief HW_SSI_SIER - SSI Interrupt Enable Register
 *
 * The SSI Interrupt Enable Register (SIER) is a 25-bit register used to set
 * up the SSI interrupts and DMA requests.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ENABLE_BITS : 19; //!< Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt to the Core or not.
        unsigned TIE : 1; //!< Transmit Interrupt Enable. This control bit allows the SSI to issue transmitter data related interrupts to the Core. Refer to for a detailed description of this bit.
        unsigned TDMAE : 1; //!< Transmit DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests are generated when any of the TFE0/1 bits in the SISR are set and if the corresponding TFEN bit is also set. If the corresponding FIFO is disabled, a DMA request is generated when the corresponding TDE bit is set.
        unsigned RIE : 1; //!< Receive Interrupt Enable. This control bit allows the SSI to issue receiver related interrupts to the Core. Refer to for a detailed description of this bit.
        unsigned RDMAE : 1; //!< Receive DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests are generated when any of the RFF0/1 bits in the SISR are set and if the corresponding RFEN bit is also set. If the corresponding FIFO is disabled, a DMA request is generated when the corresponding RDR bit is set.
        unsigned ENABLE_BITS1 : 2; //!< Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt to the Core or not.
        unsigned RESERVED0 : 7; //!< Reserved
    } B;
} hw_ssi_sier_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SIER register
 */
#define HW_SSI_SIER_ADDR(x)      (REGS_SSI_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SIER(x)           (*(volatile hw_ssi_sier_t *) HW_SSI_SIER_ADDR(x))
#define HW_SSI_SIER_RD(x)        (HW_SSI_SIER(x).U)
#define HW_SSI_SIER_WR(x, v)     (HW_SSI_SIER(x).U = (v))
#define HW_SSI_SIER_SET(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) |  (v)))
#define HW_SSI_SIER_CLR(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) & ~(v)))
#define HW_SSI_SIER_TOG(x, v)    (HW_SSI_SIER_WR(x, HW_SSI_SIER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SIER bitfields
 */

/* --- Register HW_SSI_SIER, field ENABLE_BITS
 *
 * Enable Bit. Each bit controls whether the corresponding status bit in
 * SISR can issue an interrupt to the Core or not.
 */

#define BP_SSI_SIER_ENABLE_BITS      0
#define BM_SSI_SIER_ENABLE_BITS      0x0007ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_ENABLE_BITS(v)   ((((reg32_t) v) << 0) & BM_SSI_SIER_ENABLE_BITS)
#else
#define BF_SSI_SIER_ENABLE_BITS(v)   (((v) << 0) & BM_SSI_SIER_ENABLE_BITS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_ENABLE_BITS(v)   BF_CS1(SSI_SIER, ENABLE_BITS, v)
#endif

/* --- Register HW_SSI_SIER, field TIE
 *
 * Transmit Interrupt Enable. This control bit allows the SSI to issue
 * transmitter data related interrupts to the Core. Refer to for a detailed description of this
 * bit.
 */

#define BP_SSI_SIER_TIE      19
#define BM_SSI_SIER_TIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_TIE(v)   ((((reg32_t) v) << 19) & BM_SSI_SIER_TIE)
#else
#define BF_SSI_SIER_TIE(v)   (((v) << 19) & BM_SSI_SIER_TIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_TIE(v)   BF_CS1(SSI_SIER, TIE, v)
#endif

/* --- Register HW_SSI_SIER, field TDMAE
 *
 * Transmit DMA Enable. This bit allows SSI to request for DMA
 * transfers. When enabled, DMA requests are generated when any of the
 * TFE0/1 bits in the SISR are set and if the corresponding TFEN bit is
 * also set. If the corresponding FIFO is disabled, a DMA request is
 * generated when the corresponding TDE bit is set.
 */

#define BP_SSI_SIER_TDMAE      20
#define BM_SSI_SIER_TDMAE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_TDMAE(v)   ((((reg32_t) v) << 20) & BM_SSI_SIER_TDMAE)
#else
#define BF_SSI_SIER_TDMAE(v)   (((v) << 20) & BM_SSI_SIER_TDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_TDMAE(v)   BF_CS1(SSI_SIER, TDMAE, v)
#endif

/* --- Register HW_SSI_SIER, field RIE
 *
 * Receive Interrupt Enable. This control bit allows the SSI to issue
 * receiver related interrupts to the Core. Refer to for a detailed description of this
 * bit.
 */

#define BP_SSI_SIER_RIE      21
#define BM_SSI_SIER_RIE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_RIE(v)   ((((reg32_t) v) << 21) & BM_SSI_SIER_RIE)
#else
#define BF_SSI_SIER_RIE(v)   (((v) << 21) & BM_SSI_SIER_RIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_RIE(v)   BF_CS1(SSI_SIER, RIE, v)
#endif

/* --- Register HW_SSI_SIER, field RDMAE
 *
 * Receive DMA Enable. This bit allows SSI to request for DMA transfers.
 * When enabled, DMA requests are generated when any of the RFF0/1 bits
 * in the SISR are set and if the corresponding RFEN bit is also set.
 * If the corresponding FIFO is disabled, a DMA request is generated
 * when the corresponding RDR bit is set.
 */

#define BP_SSI_SIER_RDMAE      22
#define BM_SSI_SIER_RDMAE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_RDMAE(v)   ((((reg32_t) v) << 22) & BM_SSI_SIER_RDMAE)
#else
#define BF_SSI_SIER_RDMAE(v)   (((v) << 22) & BM_SSI_SIER_RDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_RDMAE(v)   BF_CS1(SSI_SIER, RDMAE, v)
#endif

/* --- Register HW_SSI_SIER, field ENABLE_BITS
 *
 * Enable Bit. Each bit controls whether the corresponding status bit in
 * SISR can issue an interrupt to the Core or not.
 */

#define BP_SSI_SIER_ENABLE_BITS      23
#define BM_SSI_SIER_ENABLE_BITS      0x01800000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SIER_ENABLE_BITS(v)   ((((reg32_t) v) << 23) & BM_SSI_SIER_ENABLE_BITS)
#else
#define BF_SSI_SIER_ENABLE_BITS(v)   (((v) << 23) & BM_SSI_SIER_ENABLE_BITS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SIER_ENABLE_BITS(v)   BF_CS1(SSI_SIER, ENABLE_BITS, v)
#endif

/*!
 * @brief HW_SSI_SSI_STCR - SSI Transmit Configuration Register
 *
 * The SSI Transmit Configuration Register (SSI_STCR) is a read/write
 * control register used to direct the transmit operation of the STCR
 * controls the direction of the bit clock and frame sync ports, STCK and
 * STFS. Interrupt enable bit for the transmit sections is provided in this
 * control register. The Power-on reset clears all SSI_STCR bits. However,
 * SSI reset does not affect the SSI_STCR bits. The SSI_STCR bits are
 * described in the following paragraphs. See the Programmable Registers
 * section for the programming model of the SSI. The SSI Control Register
 * (SSI_SCR) must first be set to enable interrupts. Next, the SSI
 * interrupt bit in the Interrupt Enable Register (SSI_SIER) must be set to
 * enable the interrupt. Finally, the interrupt can be enabled from within
 * the
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TEFS : 1; //!< Transmit Early Frame Sync. This bit controls when the frame sync is initiated for the transmit section. The frame sync signal is deasserted after one bit-for-bit length frame sync and after one word-for-word length frame sync. In case of synchronous operation, the frame sync can also be initiated on receiving the first bit of data.
        unsigned TFSL : 1; //!< Transmit Frame Sync Length. This bit controls the length of the frame sync signal to be generated or recognized for the transmit section. The length of a word-long frame sync is same as the length of the data word selected by WL[3:0].
        unsigned TFSI : 1; //!< Transmit Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for the transmit section of SSI.
        unsigned TSCKP : 1; //!< Transmit Clock Polarity. This bit controls which bit clock edge is used to clock out data for the transmit section. Note: TSCKP is 0 CLK_IST = 0; TSCKP is 1CLK_IST = 1
        unsigned TSHFD : 1; //!< Transmit Shift Direction. This bit controls whether the MSB or LSB will be transmitted first in a sample.  The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0. Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (TSHFD cleared).
        unsigned TXDIR : 1; //!< Transmit Clock Direction. This bit controls the direction and source of the clock signal used to clock the TXSR. Internally generated clock is output through the STCK port. External clock is taken from this port. Refer to for details of clock pin configurations.
        unsigned TFDIR : 1; //!< Transmit Frame Direction. This bit controls the direction and source of the transmit frame sync signal. Internally generated frame sync signal is sent out through the STFS port and external frame sync is taken from the same port.
        unsigned TFEN0 : 1; //!< Transmit FIFO Enable 0. This bit enables transmit FIFO 0. When enabled, the FIFO allows 8 15 samples to be transmitted by the SSI per channel (a 9th sample can be shifting out) before TDE0 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is transferred to the transmit shift register (provided the interrupt is enabled).
        unsigned TFEN1 : 1; //!< Transmit FIFO Enable 1. This bit enables transmit FIFO 1. When enabled, the FIFO allows 8 15 samples to be transmitted by the SSI (per channel) (a 9th sample can be shifting out) before TDE1 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is transferred to the transmit shift register (provided the interrupt is enabled).
        unsigned TXBIT0 : 1; //!< Transmit Bit 0. This control bit allows SSI to transmit the data word from bit position 0 or 15/31 in the transmit shift register. The shifting data direction can be MSB or LSB first, controlled by the TSHFD bit.
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_ssi_ssi_stcr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STCR register
 */
#define HW_SSI_SSI_STCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STCR(x)           (*(volatile hw_ssi_ssi_stcr_t *) HW_SSI_SSI_STCR_ADDR(x))
#define HW_SSI_SSI_STCR_RD(x)        (HW_SSI_SSI_STCR(x).U)
#define HW_SSI_SSI_STCR_WR(x, v)     (HW_SSI_SSI_STCR(x).U = (v))
#define HW_SSI_SSI_STCR_SET(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) |  (v)))
#define HW_SSI_SSI_STCR_CLR(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) & ~(v)))
#define HW_SSI_SSI_STCR_TOG(x, v)    (HW_SSI_SSI_STCR_WR(x, HW_SSI_SSI_STCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STCR bitfields
 */

/* --- Register HW_SSI_SSI_STCR, field TEFS
 *
 * Transmit Early Frame Sync. This bit controls when the frame sync is
 * initiated for the transmit section. The frame sync signal is
 * deasserted after one bit-for-bit length frame sync and after one
 * word-for-word length frame sync. In case of synchronous operation,
 * the frame sync can also be initiated on receiving the first bit of
 * data.
 */

#define BP_SSI_SSI_STCR_TEFS      0
#define BM_SSI_SSI_STCR_TEFS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TEFS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STCR_TEFS)
#else
#define BF_SSI_SSI_STCR_TEFS(v)   (((v) << 0) & BM_SSI_SSI_STCR_TEFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TEFS(v)   BF_CS1(SSI_SSI_STCR, TEFS, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFSL
 *
 * Transmit Frame Sync Length. This bit controls the length of the frame
 * sync signal to be generated or recognized for the transmit section.
 * The length of a word-long frame sync is same as the length of the
 * data word selected by WL[3:0].
 */

#define BP_SSI_SSI_STCR_TFSL      1
#define BM_SSI_SSI_STCR_TFSL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFSL(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_STCR_TFSL)
#else
#define BF_SSI_SSI_STCR_TFSL(v)   (((v) << 1) & BM_SSI_SSI_STCR_TFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFSL(v)   BF_CS1(SSI_SSI_STCR, TFSL, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFSI
 *
 * Transmit Frame Sync Invert. This bit controls the active state of the
 * frame sync I/O signal for the transmit section of SSI.
 */

#define BP_SSI_SSI_STCR_TFSI      2
#define BM_SSI_SSI_STCR_TFSI      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFSI(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_STCR_TFSI)
#else
#define BF_SSI_SSI_STCR_TFSI(v)   (((v) << 2) & BM_SSI_SSI_STCR_TFSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFSI(v)   BF_CS1(SSI_SSI_STCR, TFSI, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TSCKP
 *
 * Transmit Clock Polarity. This bit controls which bit clock edge is
 * used to clock out data for the transmit section. Note: TSCKP is 0
 * CLK_IST = 0; TSCKP is 1CLK_IST = 1
 */

#define BP_SSI_SSI_STCR_TSCKP      3
#define BM_SSI_SSI_STCR_TSCKP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TSCKP(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_STCR_TSCKP)
#else
#define BF_SSI_SSI_STCR_TSCKP(v)   (((v) << 3) & BM_SSI_SSI_STCR_TSCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TSCKP(v)   BF_CS1(SSI_SSI_STCR, TSCKP, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TSHFD
 *
 * Transmit Shift Direction. This bit controls whether the MSB or LSB
 * will be transmitted first in a sample.  The CODEC device labels the MSB as bit 0, whereas the
 * Core labels                                 the LSB as bit 0. Therefore, when using a standard
 * CODEC, Core MSB                                 (CODEC LSB) is shifted in first (TSHFD cleared).
 */

#define BP_SSI_SSI_STCR_TSHFD      4
#define BM_SSI_SSI_STCR_TSHFD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TSHFD(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_STCR_TSHFD)
#else
#define BF_SSI_SSI_STCR_TSHFD(v)   (((v) << 4) & BM_SSI_SSI_STCR_TSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TSHFD(v)   BF_CS1(SSI_SSI_STCR, TSHFD, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TXDIR
 *
 * Transmit Clock Direction. This bit controls the direction and source
 * of the clock signal used to clock the TXSR. Internally generated
 * clock is output through the STCK port. External clock is taken from
 * this port. Refer to for details of clock pin                                 configurations.
 */

#define BP_SSI_SSI_STCR_TXDIR      5
#define BM_SSI_SSI_STCR_TXDIR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TXDIR(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_STCR_TXDIR)
#else
#define BF_SSI_SSI_STCR_TXDIR(v)   (((v) << 5) & BM_SSI_SSI_STCR_TXDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TXDIR(v)   BF_CS1(SSI_SSI_STCR, TXDIR, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFDIR
 *
 * Transmit Frame Direction. This bit controls the direction and source
 * of the transmit frame sync signal. Internally generated frame sync
 * signal is sent out through the STFS port and external frame sync is
 * taken from the same port.
 */

#define BP_SSI_SSI_STCR_TFDIR      6
#define BM_SSI_SSI_STCR_TFDIR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFDIR(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_STCR_TFDIR)
#else
#define BF_SSI_SSI_STCR_TFDIR(v)   (((v) << 6) & BM_SSI_SSI_STCR_TFDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFDIR(v)   BF_CS1(SSI_SSI_STCR, TFDIR, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFEN0
 *
 * Transmit FIFO Enable 0. This bit enables transmit FIFO 0. When
 * enabled, the FIFO allows 8 15 samples to be transmitted                                 by the
 * SSI per channel (a 9th sample can be shifting out) before                                 TDE0
 * bit is set. When the FIFO is disabled, an interrupt is                                 generated
 * when a single sample is transferred to the transmit shift
 * register (provided the interrupt is enabled).
 */

#define BP_SSI_SSI_STCR_TFEN0      7
#define BM_SSI_SSI_STCR_TFEN0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFEN0(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_STCR_TFEN0)
#else
#define BF_SSI_SSI_STCR_TFEN0(v)   (((v) << 7) & BM_SSI_SSI_STCR_TFEN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFEN0(v)   BF_CS1(SSI_SSI_STCR, TFEN0, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TFEN1
 *
 * Transmit FIFO Enable 1. This bit enables transmit FIFO 1. When
 * enabled, the FIFO allows 8 15 samples to be transmitted                                 by the
 * SSI (per channel) (a 9th sample can be shifting out) before                                 TDE1
 * bit is set. When the FIFO is disabled, an interrupt is                                 generated
 * when a single sample is transferred to the transmit shift
 * register (provided the interrupt is enabled).
 */

#define BP_SSI_SSI_STCR_TFEN1      8
#define BM_SSI_SSI_STCR_TFEN1      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TFEN1(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_STCR_TFEN1)
#else
#define BF_SSI_SSI_STCR_TFEN1(v)   (((v) << 8) & BM_SSI_SSI_STCR_TFEN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TFEN1(v)   BF_CS1(SSI_SSI_STCR, TFEN1, v)
#endif

/* --- Register HW_SSI_SSI_STCR, field TXBIT0
 *
 * Transmit Bit 0. This control bit allows SSI to transmit the data word
 * from bit position 0 or 15/31 in the transmit shift register. The
 * shifting data direction can be MSB or LSB first, controlled by the
 * TSHFD bit.
 */

#define BP_SSI_SSI_STCR_TXBIT0      9
#define BM_SSI_SSI_STCR_TXBIT0      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCR_TXBIT0(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_STCR_TXBIT0)
#else
#define BF_SSI_SSI_STCR_TXBIT0(v)   (((v) << 9) & BM_SSI_SSI_STCR_TXBIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCR_TXBIT0(v)   BF_CS1(SSI_SSI_STCR, TXBIT0, v)
#endif

/*!
 * @brief HW_SSI_SSI_SRCR - SSI Receive Configuration Register
 *
 * The SSI Receive Configuration Register (SSI_SRCR) is a read/write control
 * register used to direct the receive operation of the SSI. SSI.SRCR
 * controls the direction of the bit clock and frame sync ports, SRCK and
 * SRFS. Interrupt enable bit for the transmit sections is provided in this
 * control register. The Power-on reset clears all SSI_SRCR bits. However,
 * SSI reset does not affect the SSI_SRCR bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REFS : 1; //!< Receive Early Frame Sync. This bit controls when the frame sync is initiated for the receive section. The frame sync is disabled after one bit-for-bit length frame sync and after one word-for-word length frame sync.
        unsigned RFSL : 1; //!< Receive Frame Sync Length. This bit controls the length of the frame sync signal to be generated or recognized for the receive section. The length of a word-long frame sync is same as the length of the data word selected by WL[3:0].
        unsigned RFSI : 1; //!< Receive Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for the receive section of SSI.
        unsigned RSCKP : 1; //!< Receive Clock Polarity. This bit controls which bit clock edge is used to latch in data for the receive section.
        unsigned RSHFD : 1; //!< Receive Shift Direction. This bit controls whether the MSB or LSB will be received first in a sample.  The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0. Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (RSHFD cleared).
        unsigned RXDIR : 1; //!< Receive Clock Direction. This bit controls the direction and source of the clock signal used to clock the RXSR. Internally generated clock is output through the SRCK port. External clock is taken from this port. Refer to for details on clock pin configurations.
        unsigned RFDIR : 1; //!< Receive Frame Direction. This bit controls the direction and source of the receive frame sync signal. Internally generated frame sync signal is sent out through the SRFS port and external frame sync is taken from the same port.
        unsigned RFEN0 : 1; //!< Receive FIFO Enable 0. This bit enables receive FIFO 0. When enabled, the FIFO allows 8 15 samples to be received by the SSI (per channel) (a 16th sample can be shifting in) before RDR0 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is received by the SSI (provided the interrupt is enabled).
        unsigned RFEN1 : 1; //!< Receive FIFO Enable 1. This bit enables receive FIFO 1. When enabled, the FIFO allows 8 15 samples to be received by the SSI per channel (a 16th sample can be shifting in) before RDR1 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is received by the SSI (provided the interrupt is enabled).
        unsigned RXBIT0 : 1; //!< Receive Bit 0. This control bit allows SSI to receive the data word at bit position 0 or 15/31 in the receive shift register. The shifting data direction can be MSB or LSB first, controlled by the RSHFD bit.
        unsigned RXEXT : 1; //!< Receive Data Extension. This control bit allows SSI to store the received data word in sign extended form. This bit affects data storage only in case received data is LSB aligned (SRCR[9]=1)
        unsigned RESERVED0 : 21; //!< Reserved
    } B;
} hw_ssi_ssi_srcr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRCR register
 */
#define HW_SSI_SSI_SRCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRCR(x)           (*(volatile hw_ssi_ssi_srcr_t *) HW_SSI_SSI_SRCR_ADDR(x))
#define HW_SSI_SSI_SRCR_RD(x)        (HW_SSI_SSI_SRCR(x).U)
#define HW_SSI_SSI_SRCR_WR(x, v)     (HW_SSI_SSI_SRCR(x).U = (v))
#define HW_SSI_SSI_SRCR_SET(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) |  (v)))
#define HW_SSI_SSI_SRCR_CLR(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) & ~(v)))
#define HW_SSI_SSI_SRCR_TOG(x, v)    (HW_SSI_SSI_SRCR_WR(x, HW_SSI_SSI_SRCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRCR bitfields
 */

/* --- Register HW_SSI_SSI_SRCR, field REFS
 *
 * Receive Early Frame Sync. This bit controls when the frame sync is
 * initiated for the receive section. The frame sync is disabled after
 * one bit-for-bit length frame sync and after one word-for-word length
 * frame sync.
 */

#define BP_SSI_SSI_SRCR_REFS      0
#define BM_SSI_SSI_SRCR_REFS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_REFS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRCR_REFS)
#else
#define BF_SSI_SSI_SRCR_REFS(v)   (((v) << 0) & BM_SSI_SSI_SRCR_REFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_REFS(v)   BF_CS1(SSI_SSI_SRCR, REFS, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFSL
 *
 * Receive Frame Sync Length. This bit controls the length of the frame
 * sync signal to be generated or recognized for the receive section.
 * The length of a word-long frame sync is same as the length of the
 * data word selected by WL[3:0].
 */

#define BP_SSI_SSI_SRCR_RFSL      1
#define BM_SSI_SSI_SRCR_RFSL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFSL(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SRCR_RFSL)
#else
#define BF_SSI_SSI_SRCR_RFSL(v)   (((v) << 1) & BM_SSI_SSI_SRCR_RFSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFSL(v)   BF_CS1(SSI_SSI_SRCR, RFSL, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFSI
 *
 * Receive Frame Sync Invert. This bit controls the active state of the
 * frame sync I/O signal for the receive section of SSI.
 */

#define BP_SSI_SSI_SRCR_RFSI      2
#define BM_SSI_SSI_SRCR_RFSI      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFSI(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SRCR_RFSI)
#else
#define BF_SSI_SSI_SRCR_RFSI(v)   (((v) << 2) & BM_SSI_SSI_SRCR_RFSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFSI(v)   BF_CS1(SSI_SSI_SRCR, RFSI, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RSCKP
 *
 * Receive Clock Polarity. This bit controls which bit clock edge is
 * used to latch in data for the receive section.
 */

#define BP_SSI_SSI_SRCR_RSCKP      3
#define BM_SSI_SSI_SRCR_RSCKP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RSCKP(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SRCR_RSCKP)
#else
#define BF_SSI_SSI_SRCR_RSCKP(v)   (((v) << 3) & BM_SSI_SSI_SRCR_RSCKP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RSCKP(v)   BF_CS1(SSI_SSI_SRCR, RSCKP, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RSHFD
 *
 * Receive Shift Direction. This bit controls whether the MSB or LSB
 * will be received first in a sample.  The CODEC device labels the MSB as bit 0, whereas the Core
 * labels                                 the LSB as bit 0. Therefore, when using a standard CODEC,
 * Core MSB                                 (CODEC LSB) is shifted in first (RSHFD cleared).
 */

#define BP_SSI_SSI_SRCR_RSHFD      4
#define BM_SSI_SSI_SRCR_RSHFD      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RSHFD(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SRCR_RSHFD)
#else
#define BF_SSI_SSI_SRCR_RSHFD(v)   (((v) << 4) & BM_SSI_SSI_SRCR_RSHFD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RSHFD(v)   BF_CS1(SSI_SSI_SRCR, RSHFD, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RXDIR
 *
 * Receive Clock Direction. This bit controls the direction and source
 * of the clock signal used to clock the RXSR. Internally generated
 * clock is output through the SRCK port. External clock is taken from
 * this port. Refer to for details on clock pin                                 configurations.
 */

#define BP_SSI_SSI_SRCR_RXDIR      5
#define BM_SSI_SSI_SRCR_RXDIR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXDIR(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SRCR_RXDIR)
#else
#define BF_SSI_SSI_SRCR_RXDIR(v)   (((v) << 5) & BM_SSI_SSI_SRCR_RXDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXDIR(v)   BF_CS1(SSI_SSI_SRCR, RXDIR, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFDIR
 *
 * Receive Frame Direction. This bit controls the direction and source
 * of the receive frame sync signal. Internally generated frame sync
 * signal is sent out through the SRFS port and external frame sync is
 * taken from the same port.
 */

#define BP_SSI_SSI_SRCR_RFDIR      6
#define BM_SSI_SSI_SRCR_RFDIR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFDIR(v)   ((((reg32_t) v) << 6) & BM_SSI_SSI_SRCR_RFDIR)
#else
#define BF_SSI_SSI_SRCR_RFDIR(v)   (((v) << 6) & BM_SSI_SSI_SRCR_RFDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFDIR(v)   BF_CS1(SSI_SSI_SRCR, RFDIR, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFEN0
 *
 * Receive FIFO Enable 0. This bit enables receive FIFO 0. When enabled,
 * the FIFO allows 8 15 samples to be received by                                 the SSI (per
 * channel) (a 16th sample can be shifting in) before RDR0                                 bit is
 * set. When the FIFO is disabled, an interrupt is generated                                 when a
 * single sample is received by the SSI (provided the interrupt                                 is
 * enabled).
 */

#define BP_SSI_SSI_SRCR_RFEN0      7
#define BM_SSI_SSI_SRCR_RFEN0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFEN0(v)   ((((reg32_t) v) << 7) & BM_SSI_SSI_SRCR_RFEN0)
#else
#define BF_SSI_SSI_SRCR_RFEN0(v)   (((v) << 7) & BM_SSI_SSI_SRCR_RFEN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFEN0(v)   BF_CS1(SSI_SSI_SRCR, RFEN0, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RFEN1
 *
 * Receive FIFO Enable 1. This bit enables receive FIFO 1. When enabled,
 * the FIFO allows 8 15 samples to be received by                                 the SSI per
 * channel (a 16th sample can be shifting in) before RDR1                                 bit is
 * set. When the FIFO is disabled, an interrupt is generated                                 when a
 * single sample is received by the SSI (provided the interrupt                                 is
 * enabled).
 */

#define BP_SSI_SSI_SRCR_RFEN1      8
#define BM_SSI_SSI_SRCR_RFEN1      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RFEN1(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SRCR_RFEN1)
#else
#define BF_SSI_SSI_SRCR_RFEN1(v)   (((v) << 8) & BM_SSI_SSI_SRCR_RFEN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RFEN1(v)   BF_CS1(SSI_SSI_SRCR, RFEN1, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RXBIT0
 *
 * Receive Bit 0. This control bit allows SSI to receive the data word
 * at bit position 0 or 15/31 in the receive shift register. The
 * shifting data direction can be MSB or LSB first, controlled by the
 * RSHFD bit.
 */

#define BP_SSI_SSI_SRCR_RXBIT0      9
#define BM_SSI_SSI_SRCR_RXBIT0      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXBIT0(v)   ((((reg32_t) v) << 9) & BM_SSI_SSI_SRCR_RXBIT0)
#else
#define BF_SSI_SSI_SRCR_RXBIT0(v)   (((v) << 9) & BM_SSI_SSI_SRCR_RXBIT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXBIT0(v)   BF_CS1(SSI_SSI_SRCR, RXBIT0, v)
#endif

/* --- Register HW_SSI_SSI_SRCR, field RXEXT
 *
 * Receive Data Extension. This control bit allows SSI to store the
 * received data word in sign extended form. This bit affects data
 * storage only in case received data is LSB aligned (SRCR[9]=1)
 */

#define BP_SSI_SSI_SRCR_RXEXT      10
#define BM_SSI_SSI_SRCR_RXEXT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRCR_RXEXT(v)   ((((reg32_t) v) << 10) & BM_SSI_SSI_SRCR_RXEXT)
#else
#define BF_SSI_SSI_SRCR_RXEXT(v)   (((v) << 10) & BM_SSI_SSI_SRCR_RXEXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRCR_RXEXT(v)   BF_CS1(SSI_SSI_SRCR, RXEXT, v)
#endif

/*!
 * @brief HW_SSI_SSI_STCCR - SSI Transmit Clock Control Register
 *
 * The SSI Transmit and Receive Control (SSI_STCCR and SSI_SRCCR) registers
 * are 19-bit, read/write control registers used to direct the operation of
 * the SSI. The Clock Controller Module (CCM) can source the SSI clock
 * (SSI's sys clock-from CCM's ssi_clk_root ccm_ssi_clk ) from multiple sources and perform
 * fractional                             division to support commonly used audio bit rates. The CCM
 * can maintain                             the SSI's sys clock ccm_ssi_clk  (ccm_ssi_clk) frequency
 * at a constant rate                             even in cases where the ipg_clk (from CCM)
 * peripheral clock frequency changes. These registers control the SSI
 * clock generator, bit and frame sync rates, word length, and number of
 * words per frame for the serial data. The SSI.STCCR register is dedicated
 * to the transmit section, and the SSI_SRCCR register is dedicated to the
 * receive section except in Synchronous mode, in which the SSI_STCCR
 * register controls both the receive and transmit sections. Power-on reset
 * clears all SSI_STCCR and SSI_SRCCR bits. SSI reset does not affect the
 * SSI_STCCR and SSI_SRCCR bits. The control bits are described in the
 * following paragraphs. Although the bit patterns of the SSI_STCCR and
 * SSI_SRCCR registers are the same, the contents of these two registers
 * can be programmed differently.   SSI Data Length            WL3    WL2    WL1    WL0    Number of
 * Bits/Word    Supported in Implementation        0    0    0    0    2    No      0    0    0    1
 * 4    No      0    0    1    0    6    No      0    0    1    1    8    Yes      0    1    0    0
 * 10    Yes      0    1    0    1    12    Yes      0    1    1    0    14    No      0    1    1
 * 1    16    Yes      1    0    0    0    18    Yes      1    0    0    1    20    Yes      1    0
 * 1    0    22    Yes      1    0    1    1    24    Yes      1    1    0    0    26    No      1
 * 1    0    1    28    No      1    1    1    0    30    No      1    1    1    1    32    No
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PM7 : 8; //!< Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the clock port.  A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be selected. Refer to for details regarding settings.
        unsigned DC4 : 5; //!< Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio determines the word transfer rate. In Network mode, this ratio sets the number of words per frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode.  In Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A bit-length frame sync must be used in this case.  These bits can be programmed with values ranging from "00000" to "11111" to control the number of words in a frame.
        unsigned WL3 : 4; //!< Word Length Control. These bits are used to control the length of the data words being transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI works with a fixed word length of 32, and the WL bits are used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than 16 bits, it will result in a word length of 20 bits.  [table]
        unsigned PSR : 1; //!< Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable prescaler. It extends the range of the prescaler for those cases where a slower bit clock is required.  0 Prescaler bypassed.  1 Prescaler used to divide clock by 8.
        unsigned DIV2 : 1; //!< Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers.  0 Divider bypassed.  1 Divider used to divide clock by 2.
        unsigned RESERVED0 : 13; //!< Reserved
    } B;
} hw_ssi_ssi_stccr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STCCR register
 */
#define HW_SSI_SSI_STCCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STCCR(x)           (*(volatile hw_ssi_ssi_stccr_t *) HW_SSI_SSI_STCCR_ADDR(x))
#define HW_SSI_SSI_STCCR_RD(x)        (HW_SSI_SSI_STCCR(x).U)
#define HW_SSI_SSI_STCCR_WR(x, v)     (HW_SSI_SSI_STCCR(x).U = (v))
#define HW_SSI_SSI_STCCR_SET(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) |  (v)))
#define HW_SSI_SSI_STCCR_CLR(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) & ~(v)))
#define HW_SSI_SSI_STCCR_TOG(x, v)    (HW_SSI_SSI_STCCR_WR(x, HW_SSI_SSI_STCCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STCCR bitfields
 */

/* --- Register HW_SSI_SSI_STCCR, field PM7
 *
 * Prescaler Modulus Select. These bits control the prescale divider in
 * the clock generator. This prescaler is used only in Internal Clock
 * mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the
 * clock port.  A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be
 * selected. Refer to for details regarding settings.
 */

#define BP_SSI_SSI_STCCR_PM7      0
#define BM_SSI_SSI_STCCR_PM7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_PM7(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STCCR_PM7)
#else
#define BF_SSI_SSI_STCCR_PM7(v)   (((v) << 0) & BM_SSI_SSI_STCCR_PM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_PM7(v)   BF_CS1(SSI_SSI_STCCR, PM7, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field DC4
 *
 * Frame Rate Divider Control. These bits are used to control the divide
 * ratio for the programmable frame rate dividers. The divide ratio
 * works on the word clock. In Normal mode, this ratio determines the
 * word transfer rate. In Network mode, this ratio sets the number of
 * words per frame. The divide ratio ranges from 1 to 32 in Normal mode
 * and from 2 to 32 in Network mode.  In Normal mode, a divide ratio of 1 (DC=00000) provides
 * continuous                                 periodic data word transfer. A bit-length frame sync
 * must be used in                                 this case.  These bits can be programmed with
 * values ranging from "00000" to                                 "11111" to control the number of
 * words in a frame.
 */

#define BP_SSI_SSI_STCCR_DC4      8
#define BM_SSI_SSI_STCCR_DC4      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_DC4(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_STCCR_DC4)
#else
#define BF_SSI_SSI_STCCR_DC4(v)   (((v) << 8) & BM_SSI_SSI_STCCR_DC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_DC4(v)   BF_CS1(SSI_SSI_STCCR, DC4, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field WL3
 *
 * Word Length Control. These bits are used to control the length of the
 * data words being transferred by the SSI. These bits control the Word
 * Length Divider in the Clock Generator. They also control the frame
 * sync pulse length when the FSL bit is cleared. In I2S Master mode,
 * the SSI works with a fixed word length of 32, and the WL bits are
 * used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word
 * length is set to any value other than 16 bits, it will result in a
 * word length of 20 bits.  [table]
 */

#define BP_SSI_SSI_STCCR_WL3      13
#define BM_SSI_SSI_STCCR_WL3      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_WL3(v)   ((((reg32_t) v) << 13) & BM_SSI_SSI_STCCR_WL3)
#else
#define BF_SSI_SSI_STCCR_WL3(v)   (((v) << 13) & BM_SSI_SSI_STCCR_WL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_WL3(v)   BF_CS1(SSI_SSI_STCCR, WL3, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field PSR
 *
 * Prescaler Range. This bit controls a fixed divide-by-eight prescaler
 * in series with the variable prescaler. It extends the range of the
 * prescaler for those cases where a slower bit clock is required.  0 Prescaler bypassed.  1
 * Prescaler used to divide clock by 8.
 */

#define BP_SSI_SSI_STCCR_PSR      17
#define BM_SSI_SSI_STCCR_PSR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_PSR(v)   ((((reg32_t) v) << 17) & BM_SSI_SSI_STCCR_PSR)
#else
#define BF_SSI_SSI_STCCR_PSR(v)   (((v) << 17) & BM_SSI_SSI_STCCR_PSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_PSR(v)   BF_CS1(SSI_SSI_STCCR, PSR, v)
#endif

/* --- Register HW_SSI_SSI_STCCR, field DIV2
 *
 * Divide By 2. This bit controls a divide-by-two divider in series with
 * the rest of the prescalers.  0 Divider bypassed.  1 Divider used to divide clock by 2.
 */

#define BP_SSI_SSI_STCCR_DIV2      18
#define BM_SSI_SSI_STCCR_DIV2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STCCR_DIV2(v)   ((((reg32_t) v) << 18) & BM_SSI_SSI_STCCR_DIV2)
#else
#define BF_SSI_SSI_STCCR_DIV2(v)   (((v) << 18) & BM_SSI_SSI_STCCR_DIV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STCCR_DIV2(v)   BF_CS1(SSI_SSI_STCCR, DIV2, v)
#endif

/*!
 * @brief HW_SSI_SRCCR - SSI Receive Clock Control Register
 *
 * The SSI Transmit and Receive Control (SSI_STCCR and SSI_SRCCR) registers
 * are 19-bit, read/write control registers used to direct the operation of
 * the SSI. The Clock Controller Module (CCM) can source the SSI clock
 * (SSI's sys clock-from CCM's ssi_clk_root ccm_ssi_clk ) from multiple sources and perform
 * fractional                             division to support commonly used audio bit rates. The CCM
 * can maintain                             the SSI's sys clock ccm_ssi_clk  (ccm_ssi_clk) frequency
 * at a constant rate                             even in cases where the ipg_clk from CCM
 * peripheral clock frequency changes. These registers control the SSI
 * clock generator, bit and frame sync rates, word length, and number of
 * words per frame for the serial data. The SSI_STCCR register is dedicated
 * to the transmit section, and the SSI_SRCCR register is dedicated to the
 * receive section except in Synchronous mode, in which the SSI_STCCR
 * register controls both the receive and transmit sections. Power-on reset
 * clears all SSI_STCCR and SSI_SRCCR bits. SSI reset does not affect the
 * SSI_STCCR and SSI_SRCCR bits. The control bits are described in the
 * following paragraphs. Although the bit patterns of the SSI_STCCR and
 * SSI_SRCCR registers are the same, the contents of these two registers
 * can be programmed differently.   SSI Data Length            WL3    WL2    WL1    WL0    Number of
 * Bits/Word    Supported in Implementation        0    0    0    0    2    No      0    0    0    1
 * 4    No      0    0    1    0    6    No      0    0    1    1    8    Yes      0    1    0    0
 * 10    Yes      0    1    0    1    12    Yes      0    1    1    0    14    No      0    1    1
 * 1    16    Yes      1    0    0    0    18    Yes      1    0    0    1    20    Yes      1    0
 * 1    0    22    Yes      1    0    1    1    24    Yes      1    1    0    0    26    No      1
 * 1    0    1    28    No      1    1    1    0    30    No      1    1    1    1    32    No
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PM7 : 8; //!< Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the clock port.  A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be selected. Refer to for details regarding settings.
        unsigned DC4 : 5; //!< Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio determines the word transfer rate. In Network mode, this ratio sets the number of words per frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode.  In Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A bit-length frame sync must be used in this case.  These bits can be programmed with values ranging from "00000" to "11111" to control the number of words in a frame.
        unsigned WL3 : 4; //!< Word Length Control. These bits are used to control the length of the data words being transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI works with a fixed word length of 32, and the WL bits are used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than 16 bits, it will result in a word length of 20 bits.  [table]
        unsigned PSR : 1; //!< Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable prescaler. It extends the range of the prescaler for those cases where a slower bit clock is required.  0 Prescaler bypassed.  1 Prescaler used to divide clock by 8.
        unsigned DIV2 : 1; //!< Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers.  0 Divider bypassed.  1 Divider used to divide clock by 2.
        unsigned RESERVED0 : 13; //!< Reserved
    } B;
} hw_ssi_srccr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SRCCR register
 */
#define HW_SSI_SRCCR_ADDR(x)      (REGS_SSI_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SRCCR(x)           (*(volatile hw_ssi_srccr_t *) HW_SSI_SRCCR_ADDR(x))
#define HW_SSI_SRCCR_RD(x)        (HW_SSI_SRCCR(x).U)
#define HW_SSI_SRCCR_WR(x, v)     (HW_SSI_SRCCR(x).U = (v))
#define HW_SSI_SRCCR_SET(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) |  (v)))
#define HW_SSI_SRCCR_CLR(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) & ~(v)))
#define HW_SSI_SRCCR_TOG(x, v)    (HW_SSI_SRCCR_WR(x, HW_SSI_SRCCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SRCCR bitfields
 */

/* --- Register HW_SSI_SRCCR, field PM7
 *
 * Prescaler Modulus Select. These bits control the prescale divider in
 * the clock generator. This prescaler is used only in Internal Clock
 * mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the
 * clock port.  A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be
 * selected. Refer to for details regarding settings.
 */

#define BP_SSI_SRCCR_PM7      0
#define BM_SSI_SRCCR_PM7      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_PM7(v)   ((((reg32_t) v) << 0) & BM_SSI_SRCCR_PM7)
#else
#define BF_SSI_SRCCR_PM7(v)   (((v) << 0) & BM_SSI_SRCCR_PM7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_PM7(v)   BF_CS1(SSI_SRCCR, PM7, v)
#endif

/* --- Register HW_SSI_SRCCR, field DC4
 *
 * Frame Rate Divider Control. These bits are used to control the divide
 * ratio for the programmable frame rate dividers. The divide ratio
 * works on the word clock. In Normal mode, this ratio determines the
 * word transfer rate. In Network mode, this ratio sets the number of
 * words per frame. The divide ratio ranges from 1 to 32 in Normal mode
 * and from 2 to 32 in Network mode.  In Normal mode, a divide ratio of 1 (DC=00000) provides
 * continuous                                 periodic data word transfer. A bit-length frame sync
 * must be used in                                 this case.  These bits can be programmed with
 * values ranging from "00000" to                                 "11111" to control the number of
 * words in a frame.
 */

#define BP_SSI_SRCCR_DC4      8
#define BM_SSI_SRCCR_DC4      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_DC4(v)   ((((reg32_t) v) << 8) & BM_SSI_SRCCR_DC4)
#else
#define BF_SSI_SRCCR_DC4(v)   (((v) << 8) & BM_SSI_SRCCR_DC4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_DC4(v)   BF_CS1(SSI_SRCCR, DC4, v)
#endif

/* --- Register HW_SSI_SRCCR, field WL3
 *
 * Word Length Control. These bits are used to control the length of the
 * data words being transferred by the SSI. These bits control the Word
 * Length Divider in the Clock Generator. They also control the frame
 * sync pulse length when the FSL bit is cleared. In I2S Master mode,
 * the SSI works with a fixed word length of 32, and the WL bits are
 * used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word
 * length is set to any value other than 16 bits, it will result in a
 * word length of 20 bits.  [table]
 */

#define BP_SSI_SRCCR_WL3      13
#define BM_SSI_SRCCR_WL3      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_WL3(v)   ((((reg32_t) v) << 13) & BM_SSI_SRCCR_WL3)
#else
#define BF_SSI_SRCCR_WL3(v)   (((v) << 13) & BM_SSI_SRCCR_WL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_WL3(v)   BF_CS1(SSI_SRCCR, WL3, v)
#endif

/* --- Register HW_SSI_SRCCR, field PSR
 *
 * Prescaler Range. This bit controls a fixed divide-by-eight prescaler
 * in series with the variable prescaler. It extends the range of the
 * prescaler for those cases where a slower bit clock is required.  0 Prescaler bypassed.  1
 * Prescaler used to divide clock by 8.
 */

#define BP_SSI_SRCCR_PSR      17
#define BM_SSI_SRCCR_PSR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_PSR(v)   ((((reg32_t) v) << 17) & BM_SSI_SRCCR_PSR)
#else
#define BF_SSI_SRCCR_PSR(v)   (((v) << 17) & BM_SSI_SRCCR_PSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_PSR(v)   BF_CS1(SSI_SRCCR, PSR, v)
#endif

/* --- Register HW_SSI_SRCCR, field DIV2
 *
 * Divide By 2. This bit controls a divide-by-two divider in series with
 * the rest of the prescalers.  0 Divider bypassed.  1 Divider used to divide clock by 2.
 */

#define BP_SSI_SRCCR_DIV2      18
#define BM_SSI_SRCCR_DIV2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SRCCR_DIV2(v)   ((((reg32_t) v) << 18) & BM_SSI_SRCCR_DIV2)
#else
#define BF_SSI_SRCCR_DIV2(v)   (((v) << 18) & BM_SSI_SRCCR_DIV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SRCCR_DIV2(v)   BF_CS1(SSI_SRCCR, DIV2, v)
#endif

/*!
 * @brief HW_SSI_SSI_SFCSR - SSI FIFO Control/Status Register
 *
 * The SSI FIFO Control / Status Register indicates the                             status of the
 * Transmit FIFO Empty flag, with different settings of the                             Transmit
 * FIFO WaterMark bits and varying amounts of data in the Tx                             FIFO  .
 * Status of Transmit FIFO Empty Flag               Transmit FIFO Watermark (TFWM)    Number of data
 * in Tx-Fifo      1    2    3    4    5    6    7    8        1    1    1    1    1    1    1    1
 * 0      2    1    1    1    1    1    1    0    0      3    1    1    1    1    1    0    0    0
 * 4    1    1    1    1    0    0    0    0      5    1    1    1    0    0    0    0    0      6
 * 1    1    0    0    0    0    0    0      7    1    0    0    0    0    0    0    0      8    0
 * 0    0    0    0    0    0    0        Status of Transmit FIFO Empty Flag
 * Transmit FIFO Watermark (TFWM)    Number of data in Tx-Fifo      1    2    3    4    5    6    7
 * 8    9    10    11    12    13    14    15        1    1    1    1    1    1    1    1    1    1
 * 1    1    1    1    1    0      2    1    1    1    1    1    1    1    1    1    1    1    1
 * 1    0    0      3    1    1    1    1    1    1    1    1    1    1    1    1    0    0    0
 * 4    1    1    1    1    1    1    1    1    1    1    1    0    0    0    0      5    1    1
 * 1    1    1    1    1    1    1    1    0    0    0    0    0      6    1    1    1    1    1
 * 1    1    1    1    0    0    0    0    0    0      7    1    1    1    1    1    1    1    1
 * 0    0    0    0    0    0    0      8    1    1    1    1    1    1    1    0    0    0    0
 * 0    0    0    0      9    1    1    1    1    1    1    0    0    0    0    0    0    0    0
 * 0      10    1    1    1    1    1    0    0    0    0    0    0    0    0    0    0      11    1
 * 1    1    1    0    0    0    0    0    0    0    0    0    0    0      12    1    1    1    0
 * 0    0    0    0    0    0    0    0    0    0    0      13    1    1    0    0    0    0    0
 * 0    0    0    0    0    0    0    0      14    1    0    0    0    0    0    0    0    0    0
 * 0    0    0    0    0      15    0    0    0    0    0    0    0    0    0    0    0    0    0
 * 0    0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFWM0 : 4; //!< Transmit FIFO Empty WaterMark 0. These bits control the threshold at which the TFE0 flag will be set. The TFE0 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected threshold. See SSI_SFCSR_bf4 for details regarding settings for transmit FIFO watermark bits.
        unsigned RFWM0 : 4; //!< Receive FIFO Full WaterMark 0. These bits control the threshold at which the RFF0 flag will be set. The RFF0 flag is set whenever the data level in Rx FIFO 0 reaches the selected threshold. See SSI_SFCSR_bf3 for details regarding settings for receive FIFO watermark bits.
        unsigned TFCNT0 : 4; //!< Transmit FIFO Counter 0. These bits indicate the number of data words in Transmit FIFO 0. See SSI_SFCSR_bf2 for details regarding settings for transmit FIFO counter bits.
        unsigned RFCNT0 : 4; //!< Receive FIFO Counter 0. These bits indicate the number of data words in Receive FIFO 0. See SSI_SFCSR_bf1 for details regarding settings for receive FIFO counter bits.
        unsigned TFWM1 : 4; //!< Transmit FIFO Empty WaterMark 1. These bits control the threshold at which the TFE1 flag will be set. The TFE1 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected threshold.
        unsigned RFWM1 : 4; //!< Receive FIFO Full WaterMark 1. These bits control the threshold at which the RFF1 flag will be set. The RFF1 flag is set whenever the data level in Rx FIFO 1 reaches the selected threshold.
        unsigned TFCNT1 : 4; //!< Transmit FIFO Counter1. These bits indicate the number of data words in Transmit FIFO.
        unsigned RFCNT1 : 4; //!< Receive FIFO Counter1. These bits indicate the number of data words in Receive FIFO 1.
    } B;
} hw_ssi_ssi_sfcsr_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SFCSR register
 */
#define HW_SSI_SSI_SFCSR_ADDR(x)      (REGS_SSI_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SFCSR(x)           (*(volatile hw_ssi_ssi_sfcsr_t *) HW_SSI_SSI_SFCSR_ADDR(x))
#define HW_SSI_SSI_SFCSR_RD(x)        (HW_SSI_SSI_SFCSR(x).U)
#define HW_SSI_SSI_SFCSR_WR(x, v)     (HW_SSI_SSI_SFCSR(x).U = (v))
#define HW_SSI_SSI_SFCSR_SET(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) |  (v)))
#define HW_SSI_SSI_SFCSR_CLR(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) & ~(v)))
#define HW_SSI_SSI_SFCSR_TOG(x, v)    (HW_SSI_SSI_SFCSR_WR(x, HW_SSI_SSI_SFCSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SFCSR bitfields
 */

/* --- Register HW_SSI_SSI_SFCSR, field TFWM0
 *
 * Transmit FIFO Empty WaterMark 0. These bits control the threshold at
 * which the TFE0 flag will be set. The TFE0 flag is set whenever the
 * empty slots in Tx FIFO exceed or are equal to the selected
 * threshold. See                                      SSI_SFCSR_bf4 for details
 * regarding settings for transmit FIFO watermark bits.
 */

#define BP_SSI_SSI_SFCSR_TFWM0      0
#define BM_SSI_SSI_SFCSR_TFWM0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFWM0(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SFCSR_TFWM0)
#else
#define BF_SSI_SSI_SFCSR_TFWM0(v)   (((v) << 0) & BM_SSI_SSI_SFCSR_TFWM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFWM0(v)   BF_CS1(SSI_SSI_SFCSR, TFWM0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFWM0
 *
 * Receive FIFO Full WaterMark 0. These bits control the threshold at
 * which the RFF0 flag will be set. The RFF0 flag is set whenever the
 * data level in Rx FIFO 0 reaches the selected threshold.                                      See
 * SSI_SFCSR_bf3 for details                                 regarding settings for receive FIFO
 * watermark bits.
 */

#define BP_SSI_SSI_SFCSR_RFWM0      4
#define BM_SSI_SSI_SFCSR_RFWM0      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFWM0(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SFCSR_RFWM0)
#else
#define BF_SSI_SSI_SFCSR_RFWM0(v)   (((v) << 4) & BM_SSI_SSI_SFCSR_RFWM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFWM0(v)   BF_CS1(SSI_SSI_SFCSR, RFWM0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFCNT0
 *
 * Transmit FIFO Counter 0. These bits indicate the number of data words
 * in Transmit FIFO 0. See                                     SSI_SFCSR_bf2 for details
 * regarding settings for transmit FIFO counter bits.
 */

#define BP_SSI_SSI_SFCSR_TFCNT0      8
#define BM_SSI_SSI_SFCSR_TFCNT0      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   ((((reg32_t) v) << 8) & BM_SSI_SSI_SFCSR_TFCNT0)
#else
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   (((v) << 8) & BM_SSI_SSI_SFCSR_TFCNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFCNT0(v)   BF_CS1(SSI_SSI_SFCSR, TFCNT0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFCNT0
 *
 * Receive FIFO Counter 0. These bits indicate the number of data words
 * in Receive FIFO 0. See                                      SSI_SFCSR_bf1 for details
 * regarding settings for receive FIFO counter bits.
 */

#define BP_SSI_SSI_SFCSR_RFCNT0      12
#define BM_SSI_SSI_SFCSR_RFCNT0      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   ((((reg32_t) v) << 12) & BM_SSI_SSI_SFCSR_RFCNT0)
#else
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   (((v) << 12) & BM_SSI_SSI_SFCSR_RFCNT0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFCNT0(v)   BF_CS1(SSI_SSI_SFCSR, RFCNT0, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFWM1
 *
 * Transmit FIFO Empty WaterMark 1. These bits control the threshold at
 * which the TFE1 flag will be set. The TFE1 flag is set whenever the
 * empty slots in Tx FIFO exceed or are equal to the selected
 * threshold.
 */

#define BP_SSI_SSI_SFCSR_TFWM1      16
#define BM_SSI_SSI_SFCSR_TFWM1      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFWM1(v)   ((((reg32_t) v) << 16) & BM_SSI_SSI_SFCSR_TFWM1)
#else
#define BF_SSI_SSI_SFCSR_TFWM1(v)   (((v) << 16) & BM_SSI_SSI_SFCSR_TFWM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFWM1(v)   BF_CS1(SSI_SSI_SFCSR, TFWM1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFWM1
 *
 * Receive FIFO Full WaterMark 1. These bits control the threshold at
 * which the RFF1 flag will be set. The RFF1 flag is set whenever the
 * data level in Rx FIFO 1 reaches the selected threshold.
 */

#define BP_SSI_SSI_SFCSR_RFWM1      20
#define BM_SSI_SSI_SFCSR_RFWM1      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFWM1(v)   ((((reg32_t) v) << 20) & BM_SSI_SSI_SFCSR_RFWM1)
#else
#define BF_SSI_SSI_SFCSR_RFWM1(v)   (((v) << 20) & BM_SSI_SSI_SFCSR_RFWM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFWM1(v)   BF_CS1(SSI_SSI_SFCSR, RFWM1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFCNT1
 *
 * Transmit FIFO Counter1. These bits indicate the number of data words
 * in Transmit FIFO.
 */

#define BP_SSI_SSI_SFCSR_TFCNT1      24
#define BM_SSI_SSI_SFCSR_TFCNT1      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   ((((reg32_t) v) << 24) & BM_SSI_SSI_SFCSR_TFCNT1)
#else
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   (((v) << 24) & BM_SSI_SSI_SFCSR_TFCNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_TFCNT1(v)   BF_CS1(SSI_SSI_SFCSR, TFCNT1, v)
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFCNT1
 *
 * Receive FIFO Counter1. These bits indicate the number of data words
 * in Receive FIFO 1.
 */

#define BP_SSI_SSI_SFCSR_RFCNT1      28
#define BM_SSI_SSI_SFCSR_RFCNT1      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   ((((reg32_t) v) << 28) & BM_SSI_SSI_SFCSR_RFCNT1)
#else
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   (((v) << 28) & BM_SSI_SSI_SFCSR_RFCNT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SFCSR_RFCNT1(v)   BF_CS1(SSI_SSI_SFCSR, RFCNT1, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACNT - SSI AC97 Control Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AC97EN : 1; //!< AC97 Mode Enable. This bit is used to enable SSI AC97 operation. Refer to for details of AC97 operation.
        unsigned FV : 1; //!< Fixed/Variable Operation. This bit selects whether the SSI is in AC97 Fixed mode or AC97 Variable mode.
        unsigned TIF : 1; //!< Tag in FIFO. This bit controls the destination of the information received in AC97 tag slot (Slot #0).
        unsigned RD : 1; //!< Read Command. This bit specifies whether the next frame will carry an AC97 Read Command or not. The programmer should take care that only one of the bits (WR or RD) is set at a time. When this bit is set, the corresponding tag bit (corresponding to Command Address slot of the next Tx frame) is automatically set. This bit is automatically cleared by the SSI after completing transmission of a frame.
        unsigned WR : 1; //!< Write Command. This bit specifies whether the next frame will carry an AC97 Write Command or not. The programmer should take care that only one of the bits (WR or RD) is set at a time. When this bit is set, the corresponding tag bits (corresponding to Command Address and Command Data slots of the next Tx frame) are automatically set. This bit is automatically cleared by the SSI after completing transmission of a frame.
        unsigned FRDIV : 6; //!< Frame Rate Divider. These bits control the frequency of AC97 data transmission/reception. They are programmed with the number of frames for which the SSI should be idle, after operating in one frame. Through these bits, AC97 frequency of operation, from 48 KHz (000000) to 1 KHz (101111) can be achieved.  Sample Value: 001010 (10 Decimal) = SSI will operate once every 11 frames.
        unsigned RESERVED0 : 21; //!< Reserved
    } B;
} hw_ssi_ssi_sacnt_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACNT register
 */
#define HW_SSI_SSI_SACNT_ADDR(x)      (REGS_SSI_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACNT(x)           (*(volatile hw_ssi_ssi_sacnt_t *) HW_SSI_SSI_SACNT_ADDR(x))
#define HW_SSI_SSI_SACNT_RD(x)        (HW_SSI_SSI_SACNT(x).U)
#define HW_SSI_SSI_SACNT_WR(x, v)     (HW_SSI_SSI_SACNT(x).U = (v))
#define HW_SSI_SSI_SACNT_SET(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) |  (v)))
#define HW_SSI_SSI_SACNT_CLR(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) & ~(v)))
#define HW_SSI_SSI_SACNT_TOG(x, v)    (HW_SSI_SSI_SACNT_WR(x, HW_SSI_SSI_SACNT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACNT bitfields
 */

/* --- Register HW_SSI_SSI_SACNT, field AC97EN
 *
 * AC97 Mode Enable. This bit is used to enable SSI AC97 operation.
 * Refer to for details of AC97 operation.
 */

#define BP_SSI_SSI_SACNT_AC97EN      0
#define BM_SSI_SSI_SACNT_AC97EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_AC97EN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACNT_AC97EN)
#else
#define BF_SSI_SSI_SACNT_AC97EN(v)   (((v) << 0) & BM_SSI_SSI_SACNT_AC97EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_AC97EN(v)   BF_CS1(SSI_SSI_SACNT, AC97EN, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field FV
 *
 * Fixed/Variable Operation. This bit selects whether the SSI is in AC97
 * Fixed mode or AC97 Variable mode.
 */

#define BP_SSI_SSI_SACNT_FV      1
#define BM_SSI_SSI_SACNT_FV      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_FV(v)   ((((reg32_t) v) << 1) & BM_SSI_SSI_SACNT_FV)
#else
#define BF_SSI_SSI_SACNT_FV(v)   (((v) << 1) & BM_SSI_SSI_SACNT_FV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_FV(v)   BF_CS1(SSI_SSI_SACNT, FV, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field TIF
 *
 * Tag in FIFO. This bit controls the destination of the information
 * received in AC97 tag slot (Slot #0).
 */

#define BP_SSI_SSI_SACNT_TIF      2
#define BM_SSI_SSI_SACNT_TIF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_TIF(v)   ((((reg32_t) v) << 2) & BM_SSI_SSI_SACNT_TIF)
#else
#define BF_SSI_SSI_SACNT_TIF(v)   (((v) << 2) & BM_SSI_SSI_SACNT_TIF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_TIF(v)   BF_CS1(SSI_SSI_SACNT, TIF, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field RD
 *
 * Read Command. This bit specifies whether the next frame will carry an
 * AC97 Read Command or not. The programmer should take care that only
 * one of the bits (WR or RD) is set at a time. When this bit is set,
 * the corresponding tag bit (corresponding to Command Address slot of
 * the next Tx frame) is automatically set. This bit is automatically
 * cleared by the SSI after completing transmission of a frame.
 */

#define BP_SSI_SSI_SACNT_RD      3
#define BM_SSI_SSI_SACNT_RD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_RD(v)   ((((reg32_t) v) << 3) & BM_SSI_SSI_SACNT_RD)
#else
#define BF_SSI_SSI_SACNT_RD(v)   (((v) << 3) & BM_SSI_SSI_SACNT_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_RD(v)   BF_CS1(SSI_SSI_SACNT, RD, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field WR
 *
 * Write Command. This bit specifies whether the next frame will carry
 * an AC97 Write Command or not. The programmer should take care that
 * only one of the bits (WR or RD) is set at a time. When this bit is
 * set, the corresponding tag bits (corresponding to Command Address
 * and Command Data slots of the next Tx frame) are automatically set.
 * This bit is automatically cleared by the SSI after completing
 * transmission of a frame.
 */

#define BP_SSI_SSI_SACNT_WR      4
#define BM_SSI_SSI_SACNT_WR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_WR(v)   ((((reg32_t) v) << 4) & BM_SSI_SSI_SACNT_WR)
#else
#define BF_SSI_SSI_SACNT_WR(v)   (((v) << 4) & BM_SSI_SSI_SACNT_WR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_WR(v)   BF_CS1(SSI_SSI_SACNT, WR, v)
#endif

/* --- Register HW_SSI_SSI_SACNT, field FRDIV
 *
 * Frame Rate Divider. These bits control the frequency of AC97 data
 * transmission/reception. They are programmed with the number of
 * frames for which the SSI should be idle, after operating in one
 * frame. Through these bits, AC97 frequency of operation, from 48 KHz
 * (000000) to 1 KHz (101111) can be achieved.  Sample Value: 001010 (10 Decimal) = SSI will operate
 * once every 11                                 frames.
 */

#define BP_SSI_SSI_SACNT_FRDIV      5
#define BM_SSI_SSI_SACNT_FRDIV      0x000007e0

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACNT_FRDIV(v)   ((((reg32_t) v) << 5) & BM_SSI_SSI_SACNT_FRDIV)
#else
#define BF_SSI_SSI_SACNT_FRDIV(v)   (((v) << 5) & BM_SSI_SSI_SACNT_FRDIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACNT_FRDIV(v)   BF_CS1(SSI_SSI_SACNT, FRDIV, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACADD - SSI AC97 Command Address Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SACADD : 19; //!< AC97 Command Address. These bits store the Command Address Slot information (bit 19 of the slot is sent in accordance with the Read and Write Command bits in SSI_SACNT register). These bits can be updated by a direct write from the Core. They are also updated with the information received in the incoming Command Address Slot. If the contents of these bits change due to an update, the CMDAU bit in SISR is set.
        unsigned RESERVED0 : 13; //!< Reserved
    } B;
} hw_ssi_ssi_sacadd_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACADD register
 */
#define HW_SSI_SSI_SACADD_ADDR(x)      (REGS_SSI_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACADD(x)           (*(volatile hw_ssi_ssi_sacadd_t *) HW_SSI_SSI_SACADD_ADDR(x))
#define HW_SSI_SSI_SACADD_RD(x)        (HW_SSI_SSI_SACADD(x).U)
#define HW_SSI_SSI_SACADD_WR(x, v)     (HW_SSI_SSI_SACADD(x).U = (v))
#define HW_SSI_SSI_SACADD_SET(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) |  (v)))
#define HW_SSI_SSI_SACADD_CLR(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) & ~(v)))
#define HW_SSI_SSI_SACADD_TOG(x, v)    (HW_SSI_SSI_SACADD_WR(x, HW_SSI_SSI_SACADD_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACADD bitfields
 */

/* --- Register HW_SSI_SSI_SACADD, field SACADD
 *
 * AC97 Command Address. These bits store the Command Address Slot
 * information (bit 19 of the slot is sent in accordance with the Read
 * and Write Command bits in SSI_SACNT register). These bits can be
 * updated by a direct write from the Core. They are also updated with
 * the information received in the incoming Command Address Slot. If
 * the contents of these bits change due to an update, the CMDAU bit in
 * SISR is set.
 */

#define BP_SSI_SSI_SACADD_SACADD      0
#define BM_SSI_SSI_SACADD_SACADD      0x0007ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACADD_SACADD(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACADD_SACADD)
#else
#define BF_SSI_SSI_SACADD_SACADD(v)   (((v) << 0) & BM_SSI_SSI_SACADD_SACADD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACADD_SACADD(v)   BF_CS1(SSI_SSI_SACADD, SACADD, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACDAT - SSI AC97 Command Data Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SACDAT : 20; //!< AC97 Command Data. The outgoing Command Data Slot carries the information contained in these bits. These bits can be updated by a direct write from the Core. They are also updated with the information received in the incoming Command Data Slot. If the contents of these bits change due to an update, the CMDDU bit in SISR is set. These bits are transmitted only during AC97 Write Command. During AC97 Read Command, 0x00000 is transmitted in time slot #2.
        unsigned RESERVED0 : 12; //!< Reserved
    } B;
} hw_ssi_ssi_sacdat_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACDAT register
 */
#define HW_SSI_SSI_SACDAT_ADDR(x)      (REGS_SSI_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACDAT(x)           (*(volatile hw_ssi_ssi_sacdat_t *) HW_SSI_SSI_SACDAT_ADDR(x))
#define HW_SSI_SSI_SACDAT_RD(x)        (HW_SSI_SSI_SACDAT(x).U)
#define HW_SSI_SSI_SACDAT_WR(x, v)     (HW_SSI_SSI_SACDAT(x).U = (v))
#define HW_SSI_SSI_SACDAT_SET(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) |  (v)))
#define HW_SSI_SSI_SACDAT_CLR(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) & ~(v)))
#define HW_SSI_SSI_SACDAT_TOG(x, v)    (HW_SSI_SSI_SACDAT_WR(x, HW_SSI_SSI_SACDAT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACDAT bitfields
 */

/* --- Register HW_SSI_SSI_SACDAT, field SACDAT
 *
 * AC97 Command Data. The outgoing Command Data Slot carries the
 * information contained in these bits. These bits can be updated by a
 * direct write from the Core. They are also updated with the
 * information received in the incoming Command Data Slot. If the
 * contents of these bits change due to an update, the CMDDU bit in
 * SISR is set. These bits are transmitted only during AC97 Write
 * Command. During AC97 Read Command, 0x00000 is transmitted in time
 * slot #2.
 */

#define BP_SSI_SSI_SACDAT_SACDAT      0
#define BM_SSI_SSI_SACDAT_SACDAT      0x000fffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACDAT_SACDAT(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACDAT_SACDAT)
#else
#define BF_SSI_SSI_SACDAT_SACDAT(v)   (((v) << 0) & BM_SSI_SSI_SACDAT_SACDAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACDAT_SACDAT(v)   BF_CS1(SSI_SSI_SACDAT, SACDAT, v)
#endif

/*!
 * @brief HW_SSI_SATAG - SSI AC97 Tag Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SATAG : 16; //!< AC97 Tag Value. Writing to this register (by the Core) sets the value of the Tx-Tag in AC97 fixed mode of operation. On a read, the Core gets the Rx-Tag Value received (in the last frame) from the Codec. If TIF bit in SSI_SACNT register is set, the TAG value is also stored in Rx-FIFO in addition to SATAG register. When the received Tag value changes, the RXT bit in SISR register is set.  Bits SATAG[1:0] convey the Codec -ID. In current implementation only Primary Codecs are supported. Thus writing value 2'b00 to this field is mandatory.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_ssi_satag_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SATAG register
 */
#define HW_SSI_SATAG_ADDR(x)      (REGS_SSI_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SATAG(x)           (*(volatile hw_ssi_satag_t *) HW_SSI_SATAG_ADDR(x))
#define HW_SSI_SATAG_RD(x)        (HW_SSI_SATAG(x).U)
#define HW_SSI_SATAG_WR(x, v)     (HW_SSI_SATAG(x).U = (v))
#define HW_SSI_SATAG_SET(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) |  (v)))
#define HW_SSI_SATAG_CLR(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) & ~(v)))
#define HW_SSI_SATAG_TOG(x, v)    (HW_SSI_SATAG_WR(x, HW_SSI_SATAG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SATAG bitfields
 */

/* --- Register HW_SSI_SATAG, field SATAG
 *
 * AC97 Tag Value. Writing to this register (by the Core) sets the
 * value of the Tx-Tag in AC97 fixed mode of operation. On a read, the
 * Core gets the Rx-Tag Value received (in the last frame) from the
 * Codec. If TIF bit in SSI_SACNT register is set, the TAG value is
 * also stored in Rx-FIFO in addition to SATAG register. When the
 * received Tag value changes, the RXT bit in SISR register is set.  Bits SATAG[1:0] convey the
 * Codec -ID. In current implementation only                                 Primary Codecs are
 * supported. Thus writing value 2'b00 to this field                                 is mandatory.
 */

#define BP_SSI_SATAG_SATAG      0
#define BM_SSI_SATAG_SATAG      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SATAG_SATAG(v)   ((((reg32_t) v) << 0) & BM_SSI_SATAG_SATAG)
#else
#define BF_SSI_SATAG_SATAG(v)   (((v) << 0) & BM_SSI_SATAG_SATAG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SATAG_SATAG(v)   BF_CS1(SSI_SATAG, SATAG, v)
#endif

/*!
 * @brief HW_SSI_SSI_STMSK - SSI Transmit Time Slot Mask Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STMSK : 32; //!< Transmit Mask. These bits indicate which slot has been masked in the current frame. The Core can write to this register to control the time slots in which the SSI transmits data. Each bit has info corresponding to the respective time slot in the frame. Transmit mask bits should not be used in I2S Slave mode of operation. SSI_STMSK register value must be set before enabling Transmission.
    } B;
} hw_ssi_ssi_stmsk_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STMSK register
 */
#define HW_SSI_SSI_STMSK_ADDR(x)      (REGS_SSI_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STMSK(x)           (*(volatile hw_ssi_ssi_stmsk_t *) HW_SSI_SSI_STMSK_ADDR(x))
#define HW_SSI_SSI_STMSK_RD(x)        (HW_SSI_SSI_STMSK(x).U)
#define HW_SSI_SSI_STMSK_WR(x, v)     (HW_SSI_SSI_STMSK(x).U = (v))
#define HW_SSI_SSI_STMSK_SET(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) |  (v)))
#define HW_SSI_SSI_STMSK_CLR(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) & ~(v)))
#define HW_SSI_SSI_STMSK_TOG(x, v)    (HW_SSI_SSI_STMSK_WR(x, HW_SSI_SSI_STMSK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_STMSK bitfields
 */

/* --- Register HW_SSI_SSI_STMSK, field STMSK
 *
 * Transmit Mask. These bits indicate which slot has been masked in the
 * current frame. The Core can write to this register to control the
 * time slots in which the SSI transmits data. Each bit has info
 * corresponding to the respective time slot in the frame. Transmit
 * mask bits should not be used in I2S Slave mode of operation.
 * SSI_STMSK register value must be set before enabling
 * Transmission.
 */

#define BP_SSI_SSI_STMSK_STMSK      0
#define BM_SSI_SSI_STMSK_STMSK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_STMSK_STMSK(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_STMSK_STMSK)
#else
#define BF_SSI_SSI_STMSK_STMSK(v)   (((v) << 0) & BM_SSI_SSI_STMSK_STMSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_STMSK_STMSK(v)   BF_CS1(SSI_SSI_STMSK, STMSK, v)
#endif

/*!
 * @brief HW_SSI_SSI_SRMSK - SSI Receive Time Slot Mask Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SRMSK : 32; //!< Receive Mask. These bits indicate which slot has been masked in the current frame. The Core can write to this register to control the time slots in which the SSI receives data. Each bit has info corresponding to the respective time slot in the frame. SSI_SRMSK register value must be set before enabling Receiver. Receive mask bits should not be used in I2S Slave mode of operation.
    } B;
} hw_ssi_ssi_srmsk_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRMSK register
 */
#define HW_SSI_SSI_SRMSK_ADDR(x)      (REGS_SSI_BASE(x) + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRMSK(x)           (*(volatile hw_ssi_ssi_srmsk_t *) HW_SSI_SSI_SRMSK_ADDR(x))
#define HW_SSI_SSI_SRMSK_RD(x)        (HW_SSI_SSI_SRMSK(x).U)
#define HW_SSI_SSI_SRMSK_WR(x, v)     (HW_SSI_SSI_SRMSK(x).U = (v))
#define HW_SSI_SSI_SRMSK_SET(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) |  (v)))
#define HW_SSI_SSI_SRMSK_CLR(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) & ~(v)))
#define HW_SSI_SSI_SRMSK_TOG(x, v)    (HW_SSI_SSI_SRMSK_WR(x, HW_SSI_SSI_SRMSK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SRMSK bitfields
 */

/* --- Register HW_SSI_SSI_SRMSK, field SRMSK
 *
 * Receive Mask. These bits indicate which slot has been masked in the
 * current frame. The Core can write to this register to control the
 * time slots in which the SSI receives data. Each bit has info
 * corresponding to the respective time slot in the frame. SSI_SRMSK
 * register value must be set before enabling Receiver. Receive mask
 * bits should not be used in I2S Slave mode of operation.
 */

#define BP_SSI_SSI_SRMSK_SRMSK      0
#define BM_SSI_SSI_SRMSK_SRMSK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SRMSK_SRMSK(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SRMSK_SRMSK)
#else
#define BF_SSI_SSI_SRMSK_SRMSK(v)   (((v) << 0) & BM_SSI_SSI_SRMSK_SRMSK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SRMSK_SRMSK(v)   BF_CS1(SSI_SSI_SRMSK, SRMSK, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACCST - SSI AC97 Channel Status Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SACCST : 10; //!< AC97 Channel Status. These bits indicate which data slot has been enabled in AC97 variable mode operation. This register is updated in case the core enables/disables a channel through a write to SSI_SACCEN/SSI_SACCDIS register or the external codec enables a channel by sending a '1' in the corresponding SLOTREQ bit. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). The contents of this register only have relevance while the SSI is operating in AC97 variable mode. Writes to this register result in an error response on the block interface.
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_ssi_ssi_saccst_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCST register
 */
#define HW_SSI_SSI_SACCST_ADDR(x)      (REGS_SSI_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCST(x)           (*(volatile hw_ssi_ssi_saccst_t *) HW_SSI_SSI_SACCST_ADDR(x))
#define HW_SSI_SSI_SACCST_RD(x)        (HW_SSI_SSI_SACCST(x).U)
#define HW_SSI_SSI_SACCST_WR(x, v)     (HW_SSI_SSI_SACCST(x).U = (v))
#define HW_SSI_SSI_SACCST_SET(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) |  (v)))
#define HW_SSI_SSI_SACCST_CLR(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCST_TOG(x, v)    (HW_SSI_SSI_SACCST_WR(x, HW_SSI_SSI_SACCST_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCST bitfields
 */

/* --- Register HW_SSI_SSI_SACCST, field SACCST
 *
 * AC97 Channel Status. These bits indicate which data slot has been
 * enabled in AC97 variable mode operation. This register is updated in
 * case the core enables/disables a channel through a write to
 * SSI_SACCEN/SSI_SACCDIS register or the external codec enables a
 * channel by sending a '1' in the corresponding SLOTREQ bit. Bit [0]
 * corresponds to the first data slot in an AC97 frame (Slot #3) and
 * Bit [9] corresponds to the tenth data slot (slot #12). The contents
 * of this register only have relevance while the SSI is operating in
 * AC97 variable mode. Writes to this register result in an error
 * response on the block interface.
 */

#define BP_SSI_SSI_SACCST_SACCST      0
#define BM_SSI_SSI_SACCST_SACCST      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCST_SACCST(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCST_SACCST)
#else
#define BF_SSI_SSI_SACCST_SACCST(v)   (((v) << 0) & BM_SSI_SSI_SACCST_SACCST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCST_SACCST(v)   BF_CS1(SSI_SSI_SACCST, SACCST, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACCEN - SSI AC97 Channel Enable Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SACCEN : 10; //!< AC97 Channel Enable. The Core writes a '1' to these bits to enable an AC97 data channel. Writing a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have effect in the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_ssi_ssi_saccen_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCEN register
 */
#define HW_SSI_SSI_SACCEN_ADDR(x)      (REGS_SSI_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCEN(x)           (*(volatile hw_ssi_ssi_saccen_t *) HW_SSI_SSI_SACCEN_ADDR(x))
#define HW_SSI_SSI_SACCEN_RD(x)        (HW_SSI_SSI_SACCEN(x).U)
#define HW_SSI_SSI_SACCEN_WR(x, v)     (HW_SSI_SSI_SACCEN(x).U = (v))
#define HW_SSI_SSI_SACCEN_SET(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) |  (v)))
#define HW_SSI_SSI_SACCEN_CLR(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCEN_TOG(x, v)    (HW_SSI_SSI_SACCEN_WR(x, HW_SSI_SSI_SACCEN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCEN bitfields
 */

/* --- Register HW_SSI_SSI_SACCEN, field SACCEN
 *
 * AC97 Channel Enable. The Core writes a '1' to these bits to enable an
 * AC97 data channel. Writing a '0' has no effect. Bit [0] corresponds
 * to the first data slot in an AC97 frame (Slot #3) and Bit [9]
 * corresponds to the tenth data slot (slot #12). Writes to these bits
 * only have effect in the AC97 Variable mode of operation. These bits
 * are always read as '0' by the Core.
 */

#define BP_SSI_SSI_SACCEN_SACCEN      0
#define BM_SSI_SSI_SACCEN_SACCEN      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCEN_SACCEN(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCEN_SACCEN)
#else
#define BF_SSI_SSI_SACCEN_SACCEN(v)   (((v) << 0) & BM_SSI_SSI_SACCEN_SACCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCEN_SACCEN(v)   BF_CS1(SSI_SSI_SACCEN, SACCEN, v)
#endif

/*!
 * @brief HW_SSI_SSI_SACCDIS - SSI AC97 Channel Disable Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SACCDIS : 10; //!< AC97 Channel Disable. The Core writes a '1' to these bits to disable an AC97 data channel. Writing a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have effect in the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_ssi_ssi_saccdis_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCDIS register
 */
#define HW_SSI_SSI_SACCDIS_ADDR(x)      (REGS_SSI_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCDIS(x)           (*(volatile hw_ssi_ssi_saccdis_t *) HW_SSI_SSI_SACCDIS_ADDR(x))
#define HW_SSI_SSI_SACCDIS_RD(x)        (HW_SSI_SSI_SACCDIS(x).U)
#define HW_SSI_SSI_SACCDIS_WR(x, v)     (HW_SSI_SSI_SACCDIS(x).U = (v))
#define HW_SSI_SSI_SACCDIS_SET(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) |  (v)))
#define HW_SSI_SSI_SACCDIS_CLR(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) & ~(v)))
#define HW_SSI_SSI_SACCDIS_TOG(x, v)    (HW_SSI_SSI_SACCDIS_WR(x, HW_SSI_SSI_SACCDIS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual SSI_SSI_SACCDIS bitfields
 */

/* --- Register HW_SSI_SSI_SACCDIS, field SACCDIS
 *
 * AC97 Channel Disable. The Core writes a '1' to these bits to disable
 * an AC97 data channel. Writing a '0' has no effect. Bit [0]
 * corresponds to the first data slot in an AC97 frame (Slot #3) and
 * Bit [9] corresponds to the tenth data slot (slot #12). Writes to
 * these bits only have effect in the AC97 Variable mode of operation.
 * These bits are always read as '0' by the Core.
 */

#define BP_SSI_SSI_SACCDIS_SACCDIS      0
#define BM_SSI_SSI_SACCDIS_SACCDIS      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   ((((reg32_t) v) << 0) & BM_SSI_SSI_SACCDIS_SACCDIS)
#else
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   (((v) << 0) & BM_SSI_SSI_SACCDIS_SACCDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SSI_SSI_SACCDIS_SACCDIS(v)   BF_CS1(SSI_SSI_SACCDIS, SACCDIS, v)
#endif



/*!
 * @brief All SSI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_ssi_ssi_stx_t SSI_STX; //!< SSI Transmit Data Register n
    reg32_t _reserved0;
    volatile hw_ssi_ssi_srx_t SSI_SRX; //!< SSI Receive Data Register n
    reg32_t _reserved1;
    volatile hw_ssi_ssi_scr_t SSI_SCR; //!< SSI Control Register
    volatile hw_ssi_ssi_sisr_t SSI_SISR; //!< SSI Interrupt Status Register
    volatile hw_ssi_sier_t SIER; //!< SSI Interrupt Enable Register
    volatile hw_ssi_ssi_stcr_t SSI_STCR; //!< SSI Transmit Configuration Register
    volatile hw_ssi_ssi_srcr_t SSI_SRCR; //!< SSI Receive Configuration Register
    volatile hw_ssi_ssi_stccr_t SSI_STCCR; //!< SSI Transmit Clock Control Register
    volatile hw_ssi_srccr_t SRCCR; //!< SSI Receive Clock Control Register
    volatile hw_ssi_ssi_sfcsr_t SSI_SFCSR; //!< SSI FIFO Control/Status Register
    reg32_t _reserved2[2];
    volatile hw_ssi_ssi_sacnt_t SSI_SACNT; //!< SSI AC97 Control Register
    volatile hw_ssi_ssi_sacadd_t SSI_SACADD; //!< SSI AC97 Command Address Register
    volatile hw_ssi_ssi_sacdat_t SSI_SACDAT; //!< SSI AC97 Command Data Register
    volatile hw_ssi_satag_t SATAG; //!< SSI AC97 Tag Register
    volatile hw_ssi_ssi_stmsk_t SSI_STMSK; //!< SSI Transmit Time Slot Mask Register
    volatile hw_ssi_ssi_srmsk_t SSI_SRMSK; //!< SSI Receive Time Slot Mask Register
    volatile hw_ssi_ssi_saccst_t SSI_SACCST; //!< SSI AC97 Channel Status Register
    volatile hw_ssi_ssi_saccen_t SSI_SACCEN; //!< SSI AC97 Channel Enable Register
    volatile hw_ssi_ssi_saccdis_t SSI_SACCDIS; //!< SSI AC97 Channel Disable Register
} hw_ssi_t
#endif

//! @brief Macro to access all SSI registers.
//! @param x SSI instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SSI(0)</code>.
#define HW_SSI(x)     (*(volatile hw_ssi_t *) REGS_SSI_BASE(x))


#endif // _SSI_H
