/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SSI_REGISTERS_H__
#define __HW_SSI_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ SSI registers defined in this header file.
 *
 * - HW_SSI_SSI_STX0 - SSI Transmit Data Register n
 * - HW_SSI_SSI_STX1 - SSI Transmit Data Register n
 * - HW_SSI_SSI_SRX0 - SSI Receive Data Register n
 * - HW_SSI_SSI_SRX1 - SSI Receive Data Register n
 * - HW_SSI_SSI_SCR - SSI Control Register
 * - HW_SSI_SSI_SISR - SSI Interrupt Status Register
 * - HW_SSI_SIER - SSI Interrupt Enable Register
 * - HW_SSI_SSI_STCR - SSI Transmit Configuration Register
 * - HW_SSI_SSI_SRCR - SSI Receive Configuration Register
 * - HW_SSI_SSI_STCCR - SSI Transmit Clock Control Register
 * - HW_SSI_SRCCR - SSI Receive Clock Control Register
 * - HW_SSI_SSI_SFCSR - SSI FIFO Control/Status Register
 * - HW_SSI_SSI_SACNT - SSI AC97 Control Register
 * - HW_SSI_SSI_SACADD - SSI AC97 Command Address Register
 * - HW_SSI_SSI_SACDAT - SSI AC97 Command Data Register
 * - HW_SSI_SATAG - SSI AC97 Tag Register
 * - HW_SSI_SSI_STMSK - SSI Transmit Time Slot Mask Register
 * - HW_SSI_SSI_SRMSK - SSI Receive Time Slot Mask Register
 * - HW_SSI_SSI_SACCST - SSI AC97 Channel Status Register
 * - HW_SSI_SSI_SACCEN - SSI AC97 Channel Enable Register
 * - HW_SSI_SSI_SACCDIS - SSI AC97 Channel Disable Register
 *
 * - hw_ssi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SSI_BASE
#define HW_SSI_INSTANCE_COUNT (3) //!< Number of instances of the SSI module.
#define REGS_SSI1_BASE (0x02028000) //!< Base address for SSI instance number 1.
#define REGS_SSI2_BASE (0x0202c000) //!< Base address for SSI instance number 2.
#define REGS_SSI3_BASE (0x02030000) //!< Base address for SSI instance number 3.

//! @brief Get the base address of SSI by instance number.
//! @param x SSI instance number, from 0 through 3.
#define REGS_SSI_BASE(x) ( x == 1 ? REGS_SSI1_BASE : x == 2 ? REGS_SSI2_BASE : x == 3 ? REGS_SSI3_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_STX0 - SSI Transmit Data Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Enable SSI (SSIEN=1) before writing to SSI Transmit Data Registers.
 */
typedef union _hw_ssi_ssi_stx0
{
    reg32_t U;
    struct _hw_ssi_ssi_stx0_bitfields
    {
        unsigned STXN : 32; //!< [31:0] SSI Transmit Data. These bits store the data to be transmitted by the These are implemented as the first word of their respective Tx FIFOs. Data written to these registers is transferred to the Transmit Shift Register (TXSR), when shifting of the previous data is complete. If both FIFOs are in use, data is alternately transferred from STX0 and STX1, to TXSR. Multiple writes to the STX registers will not result in the previous data being over-written by the subsequent data. STX1 can only be used in Two-Channel mode of operation. Protection from over-writing is present irrespective of whether the transmitter is enabled or not. Example 1: If Tx FIFO0 is in use and user writes Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write Data1. Data1... Data8 Data15 are stored in the FIFO while Data9 Data16 is discarded. Example 2: If Tx FIFO0 is not in use and user writes Data1, Data2 to STX0, then Data2 will not over-write Data1 and will be discarded.
    } B;
} hw_ssi_ssi_stx0_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STX0 register
 */
#define HW_SSI_SSI_STX0_ADDR(x)      (REGS_SSI_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STX0(x)           (*(volatile hw_ssi_ssi_stx0_t *) HW_SSI_SSI_STX0_ADDR(x))
#define HW_SSI_SSI_STX0_RD(x)        (HW_SSI_SSI_STX0(x).U)
#define HW_SSI_SSI_STX0_WR(x, v)     (HW_SSI_SSI_STX0(x).U = (v))
#define HW_SSI_SSI_STX0_SET(x, v)    (HW_SSI_SSI_STX0_WR(x, HW_SSI_SSI_STX0_RD(x) |  (v)))
#define HW_SSI_SSI_STX0_CLR(x, v)    (HW_SSI_SSI_STX0_WR(x, HW_SSI_SSI_STX0_RD(x) & ~(v)))
#define HW_SSI_SSI_STX0_TOG(x, v)    (HW_SSI_SSI_STX0_WR(x, HW_SSI_SSI_STX0_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual SSI_SSI_STX0 bitfields
 */

/* --- Register HW_SSI_SSI_STX0, field STXN[31:0] (RW)
 *
 * SSI Transmit Data. These bits store the data to be transmitted by the These are implemented as
 * the first word of their respective Tx FIFOs. Data written to these registers is transferred to
 * the Transmit Shift Register (TXSR), when shifting of the previous data is complete. If both FIFOs
 * are in use, data is alternately transferred from STX0 and STX1, to TXSR. Multiple writes to the
 * STX registers will not result in the previous data being over-written by the subsequent data.
 * STX1 can only be used in Two-Channel mode of operation. Protection from over-writing is present
 * irrespective of whether the transmitter is enabled or not. Example 1: If Tx FIFO0 is in use and
 * user writes Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write Data1. Data1... Data8
 * Data15 are stored in the FIFO while Data9 Data16 is discarded. Example 2: If Tx FIFO0 is not in
 * use and user writes Data1, Data2 to STX0, then Data2 will not over-write Data1 and will be
 * discarded.
 */

#define BP_SSI_SSI_STX0_STXN      (0)      //!< Bit position for SSI_SSI_STX0_STXN.
#define BM_SSI_SSI_STX0_STXN      (0xffffffff)  //!< Bit mask for SSI_SSI_STX0_STXN.

//! @brief Get value of SSI_SSI_STX0_STXN from a register value.
#define BG_SSI_SSI_STX0_STXN(r)   (((r) & BM_SSI_SSI_STX0_STXN) >> BP_SSI_SSI_STX0_STXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STX0_STXN.
#define BF_SSI_SSI_STX0_STXN(v)   ((((reg32_t) v) << BP_SSI_SSI_STX0_STXN) & BM_SSI_SSI_STX0_STXN)
#else
//! @brief Format value for bitfield SSI_SSI_STX0_STXN.
#define BF_SSI_SSI_STX0_STXN(v)   (((v) << BP_SSI_SSI_STX0_STXN) & BM_SSI_SSI_STX0_STXN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STXN field to a new value.
#define BW_SSI_SSI_STX0_STXN(x, v)   (HW_SSI_SSI_STX0_WR(x, (HW_SSI_SSI_STX0_RD(x) & ~BM_SSI_SSI_STX0_STXN) | BF_SSI_SSI_STX0_STXN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_STX1 - SSI Transmit Data Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Enable SSI (SSIEN=1) before writing to SSI Transmit Data Registers.
 */
typedef union _hw_ssi_ssi_stx1
{
    reg32_t U;
    struct _hw_ssi_ssi_stx1_bitfields
    {
        unsigned STXN : 32; //!< [31:0] SSI Transmit Data. These bits store the data to be transmitted by the These are implemented as the first word of their respective Tx FIFOs. Data written to these registers is transferred to the Transmit Shift Register (TXSR), when shifting of the previous data is complete. If both FIFOs are in use, data is alternately transferred from STX0 and STX1, to TXSR. Multiple writes to the STX registers will not result in the previous data being over-written by the subsequent data. STX1 can only be used in Two-Channel mode of operation. Protection from over-writing is present irrespective of whether the transmitter is enabled or not. Example 1: If Tx FIFO0 is in use and user writes Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write Data1. Data1... Data8 Data15 are stored in the FIFO while Data9 Data16 is discarded. Example 2: If Tx FIFO0 is not in use and user writes Data1, Data2 to STX0, then Data2 will not over-write Data1 and will be discarded.
    } B;
} hw_ssi_ssi_stx1_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_STX1 register
 */
#define HW_SSI_SSI_STX1_ADDR(x)      (REGS_SSI_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_STX1(x)           (*(volatile hw_ssi_ssi_stx1_t *) HW_SSI_SSI_STX1_ADDR(x))
#define HW_SSI_SSI_STX1_RD(x)        (HW_SSI_SSI_STX1(x).U)
#define HW_SSI_SSI_STX1_WR(x, v)     (HW_SSI_SSI_STX1(x).U = (v))
#define HW_SSI_SSI_STX1_SET(x, v)    (HW_SSI_SSI_STX1_WR(x, HW_SSI_SSI_STX1_RD(x) |  (v)))
#define HW_SSI_SSI_STX1_CLR(x, v)    (HW_SSI_SSI_STX1_WR(x, HW_SSI_SSI_STX1_RD(x) & ~(v)))
#define HW_SSI_SSI_STX1_TOG(x, v)    (HW_SSI_SSI_STX1_WR(x, HW_SSI_SSI_STX1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual SSI_SSI_STX1 bitfields
 */

/* --- Register HW_SSI_SSI_STX1, field STXN[31:0] (RW)
 *
 * SSI Transmit Data. These bits store the data to be transmitted by the These are implemented as
 * the first word of their respective Tx FIFOs. Data written to these registers is transferred to
 * the Transmit Shift Register (TXSR), when shifting of the previous data is complete. If both FIFOs
 * are in use, data is alternately transferred from STX0 and STX1, to TXSR. Multiple writes to the
 * STX registers will not result in the previous data being over-written by the subsequent data.
 * STX1 can only be used in Two-Channel mode of operation. Protection from over-writing is present
 * irrespective of whether the transmitter is enabled or not. Example 1: If Tx FIFO0 is in use and
 * user writes Data1... Data9 Data16 to STX0, Data9 Data16 will not over-write Data1. Data1... Data8
 * Data15 are stored in the FIFO while Data9 Data16 is discarded. Example 2: If Tx FIFO0 is not in
 * use and user writes Data1, Data2 to STX0, then Data2 will not over-write Data1 and will be
 * discarded.
 */

#define BP_SSI_SSI_STX1_STXN      (0)      //!< Bit position for SSI_SSI_STX1_STXN.
#define BM_SSI_SSI_STX1_STXN      (0xffffffff)  //!< Bit mask for SSI_SSI_STX1_STXN.

//! @brief Get value of SSI_SSI_STX1_STXN from a register value.
#define BG_SSI_SSI_STX1_STXN(r)   (((r) & BM_SSI_SSI_STX1_STXN) >> BP_SSI_SSI_STX1_STXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STX1_STXN.
#define BF_SSI_SSI_STX1_STXN(v)   ((((reg32_t) v) << BP_SSI_SSI_STX1_STXN) & BM_SSI_SSI_STX1_STXN)
#else
//! @brief Format value for bitfield SSI_SSI_STX1_STXN.
#define BF_SSI_SSI_STX1_STXN(v)   (((v) << BP_SSI_SSI_STX1_STXN) & BM_SSI_SSI_STX1_STXN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STXN field to a new value.
#define BW_SSI_SSI_STX1_STXN(x, v)   (HW_SSI_SSI_STX1_WR(x, (HW_SSI_SSI_STX1_RD(x) & ~BM_SSI_SSI_STX1_STXN) | BF_SSI_SSI_STX1_STXN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SRX0 - SSI Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_srx0
{
    reg32_t U;
    struct _hw_ssi_ssi_srx0_bitfields
    {
        unsigned SRXN : 32; //!< [31:0] SSI Receive Data. These bits store the data received by the These are implemented as the first word of their respective Rx FIFOs. These bits receive data from the RXSR depending on the mode of operation. In case both FIFOs are in use, data is transferred to each data register alternately. SRX1 can only be used in Two-Channel mode of operation.
    } B;
} hw_ssi_ssi_srx0_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRX0 register
 */
#define HW_SSI_SSI_SRX0_ADDR(x)      (REGS_SSI_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRX0(x)           (*(volatile hw_ssi_ssi_srx0_t *) HW_SSI_SSI_SRX0_ADDR(x))
#define HW_SSI_SSI_SRX0_RD(x)        (HW_SSI_SSI_SRX0(x).U)
#endif

/*
 * constants & macros for individual SSI_SSI_SRX0 bitfields
 */

/* --- Register HW_SSI_SSI_SRX0, field SRXN[31:0] (RO)
 *
 * SSI Receive Data. These bits store the data received by the These are implemented as the first
 * word of their respective Rx FIFOs. These bits receive data from the RXSR depending on the mode of
 * operation. In case both FIFOs are in use, data is transferred to each data register alternately.
 * SRX1 can only be used in Two-Channel mode of operation.
 */

#define BP_SSI_SSI_SRX0_SRXN      (0)      //!< Bit position for SSI_SSI_SRX0_SRXN.
#define BM_SSI_SSI_SRX0_SRXN      (0xffffffff)  //!< Bit mask for SSI_SSI_SRX0_SRXN.

//! @brief Get value of SSI_SSI_SRX0_SRXN from a register value.
#define BG_SSI_SSI_SRX0_SRXN(r)   (((r) & BM_SSI_SSI_SRX0_SRXN) >> BP_SSI_SSI_SRX0_SRXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SRX1 - SSI Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_srx1
{
    reg32_t U;
    struct _hw_ssi_ssi_srx1_bitfields
    {
        unsigned SRXN : 32; //!< [31:0] SSI Receive Data. These bits store the data received by the These are implemented as the first word of their respective Rx FIFOs. These bits receive data from the RXSR depending on the mode of operation. In case both FIFOs are in use, data is transferred to each data register alternately. SRX1 can only be used in Two-Channel mode of operation.
    } B;
} hw_ssi_ssi_srx1_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SRX1 register
 */
#define HW_SSI_SSI_SRX1_ADDR(x)      (REGS_SSI_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SRX1(x)           (*(volatile hw_ssi_ssi_srx1_t *) HW_SSI_SSI_SRX1_ADDR(x))
#define HW_SSI_SSI_SRX1_RD(x)        (HW_SSI_SSI_SRX1(x).U)
#endif

/*
 * constants & macros for individual SSI_SSI_SRX1 bitfields
 */

/* --- Register HW_SSI_SSI_SRX1, field SRXN[31:0] (RO)
 *
 * SSI Receive Data. These bits store the data received by the These are implemented as the first
 * word of their respective Rx FIFOs. These bits receive data from the RXSR depending on the mode of
 * operation. In case both FIFOs are in use, data is transferred to each data register alternately.
 * SRX1 can only be used in Two-Channel mode of operation.
 */

#define BP_SSI_SSI_SRX1_SRXN      (0)      //!< Bit position for SSI_SSI_SRX1_SRXN.
#define BM_SSI_SSI_SRX1_SRXN      (0xffffffff)  //!< Bit mask for SSI_SSI_SRX1_SRXN.

//! @brief Get value of SSI_SSI_SRX1_SRXN from a register value.
#define BG_SSI_SSI_SRX1_SRXN(r)   (((r) & BM_SSI_SSI_SRX1_SRXN) >> BP_SSI_SSI_SRX1_SRXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SCR - SSI Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The SSI Control Register (SSI_SCR) sets up the SSI reset is controlled by bit 0 in the SSI_SCR.
 * SSI operating modes are also selected in this register (except AC97 mode which is selected in the
 * SSI_SACNT register).
 */
typedef union _hw_ssi_ssi_scr
{
    reg32_t U;
    struct _hw_ssi_ssi_scr_bitfields
    {
        unsigned SSIEN : 1; //!< [0] SSIEN - SSI Enable This bit is used to enable/disable the When disabled, all SSI status bits are preset to the same state produced by the power-on reset, all control bits are unaffected, the contents of Tx and Rx FIFOs are cleared. When SSI is disabled, all internal clocks are disabled (except register access clock).
        unsigned TE : 1; //!< [1] Transmit Enable. This control bit enables the transmit section of the It enables the transfer of the contents of the STX registers to the TXSR and also enables the internal transmit clock. The transmit section is enabled when this bit is set and a frame boundary is detected. When this bit is cleared, the transmitter continues to send data until the end of the current frame and then stops. Data can be written to the STX registers with the TE bit cleared (the corresponding TDE bit will be cleared). If the TE bit is cleared and then set again before the second to last bit of the last time slot in the current frame, data transmission continues without interruption. The normal transmit enable sequence is to write data to the STX register(s) and then set the TE bit. The normal disable sequence is to clear the TE and TIE bits after the TDE bit is set. In gated clock mode, clearing the TE bit results in the clock stopping after the data currently in TXSR has shifted out. When the TE bit is set, the clock starts immediately (for internal gated clock mode). TE should not be toggled in the same frame. After enabling/disabling transmission, SSI expects 4 setup clock cycles before arrival of frame-sync for frame-sync to be accepted/rejected by In case of fewer clock cycles, there is high probability of the frame-sync to get missed. Note: If continuos clock is not provided, SSI expects 6 clock cycles before arrival of frame-sync for frame-sync to be accepted by
        unsigned RE : 1; //!< [2] Receive Enable. This control bit enables the receive section of the When this bit is enabled, data reception starts with the arrival of the next frame sync. If data is being received when this bit is cleared, data reception continues until the end of the current frame and then stops. If this bit is set again before the second to last bit of the last time slot in the current frame, then reception continues without interruption. RE should not be toggled in the same frame.
        unsigned NET : 1; //!< [3] Network Mode. This bit controls whether SSI is in network mode or not.
        unsigned SYN : 1; //!< [4] Synchronous Mode. This bit controls whether SSI is in synchronous mode or not. In synchronous mode, the transmit and receive sections of SSI share a common clock port (STCK) and frame sync port (STFS).
        unsigned I2S_MODE : 2; //!< [6:5] I2S Mode Select. These bits allow the SSI to operate in Normal, I2S Master or I2S Slave mode. Refer to for a detailed description of I2S Mode of operation. Refer to for details regarding settings.
        unsigned SYS_CLK_EN : 1; //!< [7] Network Clock (Oversampling Clock) Enable. When set, this bit allows the SSI to output the network clock (ccm_ssi_clk) at the SRCK port, provided that synchronous mode, and transmit internal clock mode are set. The relationship between bit clock and network clock (ccm_ssi_clk) is determined by DIV2, PSR, and PM bits. This feature is especially useful in I2S Master mode to output network clock (oversampling clock) on SRCK port.
        unsigned TCH_EN : 1; //!< [8] Two-Channel Operation Enable. This bit allows SSI to operate in the two-channel mode.In this mode while receiving, the RXSR transfers data to SRX0 and SRX1 alternately and while transmitting, data is alternately transferred from STX0 and STX1 to TXSR. For an even number of slots, Two-Channel Operation can be enabled to optimize usage of both FIFOs or disabled as in the case of odd number of active slots. This feature is especially useful in I2S mode, where data for Left Speaker can be placed in Tx-FIFO0 and for Right speaker in Tx-FIFO1. Review_Q&A: Mike Austin-Which SRX and STX registers are not used with two-channel mode disabled?
        unsigned CLK_IST : 1; //!< [9] Clock Idle State. This bit controls the idle state of the transmit clock port during SSI internal gated mode. Note: When Clock idle state is '1' the clock polarity should always be negedge triggered and when Clock idle = '0' the clock polarity should always be positive edge triggered.
        unsigned TFR_CLK_DIS : 1; //!< [10] Transmit Frame Clock Disable. This bit provide option to keep the Frame-sync and Clock enabled or disabled after current transmit frame, in which transmitter is disabled by clearing TE bit. Writing to this bit has effect only when SSI is enabled TE is disabled.
        unsigned RFR_CLK_DIS : 1; //!< [11] Receive Frame Clock Disable. This bit provides the option to keep the Frame-sync and Clock enabled or to disable them after the receive frame in which the receiver is disabled. Writing to this bit has effect only when RE is disabled.The receiver is disabled by clearing the RE bit.
        unsigned SYNC_TX_FS : 1; //!< [12] SYNC_FS_TX bit provides a safe window for TE to be visible to the internal circuit which is just after FS occurrence. When SYNC_TX_FS is set, TE(SCR[1]) gets latched on FS occurrence & latched TE is used to enable/disable SSI transmitter. TE needs setup of 2 bit-clock cycles before occurrence of FS. If TE is changed within 2 bit-clock cycles of FS occurrence, there is high probability that TE will be latched on next FS. Note: With TFR_CLK_DIS feature on, TE is used directly to enable transmitter in following cases (i) Sync mode & Rx disabled (ii) Async Mode. Latched-TE is used to disable the transmitter. This bit has no relevance in gated mode and AC97 mode.
        unsigned RESERVED0 : 19; //!< [31:13] Reserved
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

/* --- Register HW_SSI_SSI_SCR, field SSIEN[0] (RW)
 *
 * SSIEN - SSI Enable This bit is used to enable/disable the When disabled, all SSI status bits are
 * preset to the same state produced by the power-on reset, all control bits are unaffected, the
 * contents of Tx and Rx FIFOs are cleared. When SSI is disabled, all internal clocks are disabled
 * (except register access clock).
 *
 * Values:
 * 0 - SSI is disabled.
 * 1 - SSI is enabled.
 */

#define BP_SSI_SSI_SCR_SSIEN      (0)      //!< Bit position for SSI_SSI_SCR_SSIEN.
#define BM_SSI_SSI_SCR_SSIEN      (0x00000001)  //!< Bit mask for SSI_SSI_SCR_SSIEN.

//! @brief Get value of SSI_SSI_SCR_SSIEN from a register value.
#define BG_SSI_SSI_SCR_SSIEN(r)   (((r) & BM_SSI_SSI_SCR_SSIEN) >> BP_SSI_SSI_SCR_SSIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_SSIEN.
#define BF_SSI_SSI_SCR_SSIEN(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_SSIEN) & BM_SSI_SSI_SCR_SSIEN)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_SSIEN.
#define BF_SSI_SSI_SCR_SSIEN(v)   (((v) << BP_SSI_SSI_SCR_SSIEN) & BM_SSI_SSI_SCR_SSIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSIEN field to a new value.
#define BW_SSI_SSI_SCR_SSIEN(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_SSIEN) | BF_SSI_SSI_SCR_SSIEN(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field TE[1] (RW)
 *
 * Transmit Enable. This control bit enables the transmit section of the It enables the transfer of
 * the contents of the STX registers to the TXSR and also enables the internal transmit clock. The
 * transmit section is enabled when this bit is set and a frame boundary is detected. When this bit
 * is cleared, the transmitter continues to send data until the end of the current frame and then
 * stops. Data can be written to the STX registers with the TE bit cleared (the corresponding TDE
 * bit will be cleared). If the TE bit is cleared and then set again before the second to last bit
 * of the last time slot in the current frame, data transmission continues without interruption. The
 * normal transmit enable sequence is to write data to the STX register(s) and then set the TE bit.
 * The normal disable sequence is to clear the TE and TIE bits after the TDE bit is set. In gated
 * clock mode, clearing the TE bit results in the clock stopping after the data currently in TXSR
 * has shifted out. When the TE bit is set, the clock starts immediately (for internal gated clock
 * mode). TE should not be toggled in the same frame. After enabling/disabling transmission, SSI
 * expects 4 setup clock cycles before arrival of frame-sync for frame-sync to be accepted/rejected
 * by In case of fewer clock cycles, there is high probability of the frame-sync to get missed.
 * Note: If continuos clock is not provided, SSI expects 6 clock cycles before arrival of frame-sync
 * for frame-sync to be accepted by
 *
 * Values:
 * 0 - Transmit section disabled.
 * 1 - Transmit section enabled.
 */

#define BP_SSI_SSI_SCR_TE      (1)      //!< Bit position for SSI_SSI_SCR_TE.
#define BM_SSI_SSI_SCR_TE      (0x00000002)  //!< Bit mask for SSI_SSI_SCR_TE.

//! @brief Get value of SSI_SSI_SCR_TE from a register value.
#define BG_SSI_SSI_SCR_TE(r)   (((r) & BM_SSI_SSI_SCR_TE) >> BP_SSI_SSI_SCR_TE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_TE.
#define BF_SSI_SSI_SCR_TE(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_TE) & BM_SSI_SSI_SCR_TE)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_TE.
#define BF_SSI_SSI_SCR_TE(v)   (((v) << BP_SSI_SSI_SCR_TE) & BM_SSI_SSI_SCR_TE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE field to a new value.
#define BW_SSI_SSI_SCR_TE(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_TE) | BF_SSI_SSI_SCR_TE(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field RE[2] (RW)
 *
 * Receive Enable. This control bit enables the receive section of the When this bit is enabled,
 * data reception starts with the arrival of the next frame sync. If data is being received when
 * this bit is cleared, data reception continues until the end of the current frame and then stops.
 * If this bit is set again before the second to last bit of the last time slot in the current
 * frame, then reception continues without interruption. RE should not be toggled in the same frame.
 *
 * Values:
 * 0 - Receive section disabled.
 * 1 - Receive section enabled.
 */

#define BP_SSI_SSI_SCR_RE      (2)      //!< Bit position for SSI_SSI_SCR_RE.
#define BM_SSI_SSI_SCR_RE      (0x00000004)  //!< Bit mask for SSI_SSI_SCR_RE.

//! @brief Get value of SSI_SSI_SCR_RE from a register value.
#define BG_SSI_SSI_SCR_RE(r)   (((r) & BM_SSI_SSI_SCR_RE) >> BP_SSI_SSI_SCR_RE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_RE.
#define BF_SSI_SSI_SCR_RE(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_RE) & BM_SSI_SSI_SCR_RE)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_RE.
#define BF_SSI_SSI_SCR_RE(v)   (((v) << BP_SSI_SSI_SCR_RE) & BM_SSI_SSI_SCR_RE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE field to a new value.
#define BW_SSI_SSI_SCR_RE(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_RE) | BF_SSI_SSI_SCR_RE(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field NET[3] (RW)
 *
 * Network Mode. This bit controls whether SSI is in network mode or not.
 *
 * Values:
 * 0 - Network mode not selected.
 * 1 - Network mode selected.
 */

#define BP_SSI_SSI_SCR_NET      (3)      //!< Bit position for SSI_SSI_SCR_NET.
#define BM_SSI_SSI_SCR_NET      (0x00000008)  //!< Bit mask for SSI_SSI_SCR_NET.

//! @brief Get value of SSI_SSI_SCR_NET from a register value.
#define BG_SSI_SSI_SCR_NET(r)   (((r) & BM_SSI_SSI_SCR_NET) >> BP_SSI_SSI_SCR_NET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_NET.
#define BF_SSI_SSI_SCR_NET(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_NET) & BM_SSI_SSI_SCR_NET)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_NET.
#define BF_SSI_SSI_SCR_NET(v)   (((v) << BP_SSI_SSI_SCR_NET) & BM_SSI_SSI_SCR_NET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NET field to a new value.
#define BW_SSI_SSI_SCR_NET(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_NET) | BF_SSI_SSI_SCR_NET(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field SYN[4] (RW)
 *
 * Synchronous Mode. This bit controls whether SSI is in synchronous mode or not. In synchronous
 * mode, the transmit and receive sections of SSI share a common clock port (STCK) and frame sync
 * port (STFS).
 *
 * Values:
 * 0 - Asynchronous mode selected.
 * 1 - Synchronous mode selected.
 */

#define BP_SSI_SSI_SCR_SYN      (4)      //!< Bit position for SSI_SSI_SCR_SYN.
#define BM_SSI_SSI_SCR_SYN      (0x00000010)  //!< Bit mask for SSI_SSI_SCR_SYN.

//! @brief Get value of SSI_SSI_SCR_SYN from a register value.
#define BG_SSI_SSI_SCR_SYN(r)   (((r) & BM_SSI_SSI_SCR_SYN) >> BP_SSI_SSI_SCR_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_SYN.
#define BF_SSI_SSI_SCR_SYN(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_SYN) & BM_SSI_SSI_SCR_SYN)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_SYN.
#define BF_SSI_SSI_SCR_SYN(v)   (((v) << BP_SSI_SSI_SCR_SYN) & BM_SSI_SSI_SCR_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_SSI_SSI_SCR_SYN(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_SYN) | BF_SSI_SSI_SCR_SYN(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field I2S_MODE[6:5] (RW)
 *
 * I2S Mode Select. These bits allow the SSI to operate in Normal, I2S Master or I2S Slave mode.
 * Refer to for a detailed description of I2S Mode of operation. Refer to for details regarding
 * settings.
 */

#define BP_SSI_SSI_SCR_I2S_MODE      (5)      //!< Bit position for SSI_SSI_SCR_I2S_MODE.
#define BM_SSI_SSI_SCR_I2S_MODE      (0x00000060)  //!< Bit mask for SSI_SSI_SCR_I2S_MODE.

//! @brief Get value of SSI_SSI_SCR_I2S_MODE from a register value.
#define BG_SSI_SSI_SCR_I2S_MODE(r)   (((r) & BM_SSI_SSI_SCR_I2S_MODE) >> BP_SSI_SSI_SCR_I2S_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_I2S_MODE.
#define BF_SSI_SSI_SCR_I2S_MODE(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_I2S_MODE) & BM_SSI_SSI_SCR_I2S_MODE)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_I2S_MODE.
#define BF_SSI_SSI_SCR_I2S_MODE(v)   (((v) << BP_SSI_SSI_SCR_I2S_MODE) & BM_SSI_SSI_SCR_I2S_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the I2S_MODE field to a new value.
#define BW_SSI_SSI_SCR_I2S_MODE(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_I2S_MODE) | BF_SSI_SSI_SCR_I2S_MODE(v)))
#endif

/* --- Register HW_SSI_SSI_SCR, field SYS_CLK_EN[7] (RW)
 *
 * Network Clock (Oversampling Clock) Enable. When set, this bit allows the SSI to output the
 * network clock (ccm_ssi_clk) at the SRCK port, provided that synchronous mode, and transmit
 * internal clock mode are set. The relationship between bit clock and network clock (ccm_ssi_clk)
 * is determined by DIV2, PSR, and PM bits. This feature is especially useful in I2S Master mode to
 * output network clock (oversampling clock) on SRCK port.
 *
 * Values:
 * 0 - network clock (ccm_ssi_clk) not output on SRCK port.
 * 1 - network clock (ccm_ssi_clk) output on SRCK port.
 */

#define BP_SSI_SSI_SCR_SYS_CLK_EN      (7)      //!< Bit position for SSI_SSI_SCR_SYS_CLK_EN.
#define BM_SSI_SSI_SCR_SYS_CLK_EN      (0x00000080)  //!< Bit mask for SSI_SSI_SCR_SYS_CLK_EN.

//! @brief Get value of SSI_SSI_SCR_SYS_CLK_EN from a register value.
#define BG_SSI_SSI_SCR_SYS_CLK_EN(r)   (((r) & BM_SSI_SSI_SCR_SYS_CLK_EN) >> BP_SSI_SSI_SCR_SYS_CLK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_SYS_CLK_EN.
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_SYS_CLK_EN) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_SYS_CLK_EN.
#define BF_SSI_SSI_SCR_SYS_CLK_EN(v)   (((v) << BP_SSI_SSI_SCR_SYS_CLK_EN) & BM_SSI_SSI_SCR_SYS_CLK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYS_CLK_EN field to a new value.
#define BW_SSI_SSI_SCR_SYS_CLK_EN(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_SYS_CLK_EN) | BF_SSI_SSI_SCR_SYS_CLK_EN(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field TCH_EN[8] (RW)
 *
 * Two-Channel Operation Enable. This bit allows SSI to operate in the two-channel mode.In this mode
 * while receiving, the RXSR transfers data to SRX0 and SRX1 alternately and while transmitting,
 * data is alternately transferred from STX0 and STX1 to TXSR. For an even number of slots, Two-
 * Channel Operation can be enabled to optimize usage of both FIFOs or disabled as in the case of
 * odd number of active slots. This feature is especially useful in I2S mode, where data for Left
 * Speaker can be placed in Tx-FIFO0 and for Right speaker in Tx-FIFO1. Review_Q&A: Mike Austin-
 * Which SRX and STX registers are not used with two-channel mode disabled?
 *
 * Values:
 * 0 - Two-channel mode disabled.
 * 1 - Two-channel mode enabled.
 */

#define BP_SSI_SSI_SCR_TCH_EN      (8)      //!< Bit position for SSI_SSI_SCR_TCH_EN.
#define BM_SSI_SSI_SCR_TCH_EN      (0x00000100)  //!< Bit mask for SSI_SSI_SCR_TCH_EN.

//! @brief Get value of SSI_SSI_SCR_TCH_EN from a register value.
#define BG_SSI_SSI_SCR_TCH_EN(r)   (((r) & BM_SSI_SSI_SCR_TCH_EN) >> BP_SSI_SSI_SCR_TCH_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_TCH_EN.
#define BF_SSI_SSI_SCR_TCH_EN(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_TCH_EN) & BM_SSI_SSI_SCR_TCH_EN)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_TCH_EN.
#define BF_SSI_SSI_SCR_TCH_EN(v)   (((v) << BP_SSI_SSI_SCR_TCH_EN) & BM_SSI_SSI_SCR_TCH_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCH_EN field to a new value.
#define BW_SSI_SSI_SCR_TCH_EN(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_TCH_EN) | BF_SSI_SSI_SCR_TCH_EN(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field CLK_IST[9] (RW)
 *
 * Clock Idle State. This bit controls the idle state of the transmit clock port during SSI internal
 * gated mode. Note: When Clock idle state is '1' the clock polarity should always be negedge
 * triggered and when Clock idle = '0' the clock polarity should always be positive edge triggered.
 *
 * Values:
 * 0 - Clock idle state is '0'.
 * 1 - Clock idle state is '1'.
 */

#define BP_SSI_SSI_SCR_CLK_IST      (9)      //!< Bit position for SSI_SSI_SCR_CLK_IST.
#define BM_SSI_SSI_SCR_CLK_IST      (0x00000200)  //!< Bit mask for SSI_SSI_SCR_CLK_IST.

//! @brief Get value of SSI_SSI_SCR_CLK_IST from a register value.
#define BG_SSI_SSI_SCR_CLK_IST(r)   (((r) & BM_SSI_SSI_SCR_CLK_IST) >> BP_SSI_SSI_SCR_CLK_IST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_CLK_IST.
#define BF_SSI_SSI_SCR_CLK_IST(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_CLK_IST) & BM_SSI_SSI_SCR_CLK_IST)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_CLK_IST.
#define BF_SSI_SSI_SCR_CLK_IST(v)   (((v) << BP_SSI_SSI_SCR_CLK_IST) & BM_SSI_SSI_SCR_CLK_IST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_IST field to a new value.
#define BW_SSI_SSI_SCR_CLK_IST(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_CLK_IST) | BF_SSI_SSI_SCR_CLK_IST(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field TFR_CLK_DIS[10] (RW)
 *
 * Transmit Frame Clock Disable. This bit provide option to keep the Frame-sync and Clock enabled or
 * disabled after current transmit frame, in which transmitter is disabled by clearing TE bit.
 * Writing to this bit has effect only when SSI is enabled TE is disabled.
 *
 * Values:
 * 0 - Continue Frame-sync/Clock generation after current frame during which TE is cleared. This may be
 *     required when Frame-sync and Clocks are required from SSI, even when no data is to be
 *     received.
 * 1 - Stop Frame-sync/Clock generation at next frame boundary. This will be effective also in case where
 *     transmitter is already disabled in current or previous frames.
 */

#define BP_SSI_SSI_SCR_TFR_CLK_DIS      (10)      //!< Bit position for SSI_SSI_SCR_TFR_CLK_DIS.
#define BM_SSI_SSI_SCR_TFR_CLK_DIS      (0x00000400)  //!< Bit mask for SSI_SSI_SCR_TFR_CLK_DIS.

//! @brief Get value of SSI_SSI_SCR_TFR_CLK_DIS from a register value.
#define BG_SSI_SSI_SCR_TFR_CLK_DIS(r)   (((r) & BM_SSI_SSI_SCR_TFR_CLK_DIS) >> BP_SSI_SSI_SCR_TFR_CLK_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_TFR_CLK_DIS.
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_TFR_CLK_DIS) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_TFR_CLK_DIS.
#define BF_SSI_SSI_SCR_TFR_CLK_DIS(v)   (((v) << BP_SSI_SSI_SCR_TFR_CLK_DIS) & BM_SSI_SSI_SCR_TFR_CLK_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFR_CLK_DIS field to a new value.
#define BW_SSI_SSI_SCR_TFR_CLK_DIS(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_TFR_CLK_DIS) | BF_SSI_SSI_SCR_TFR_CLK_DIS(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field RFR_CLK_DIS[11] (RW)
 *
 * Receive Frame Clock Disable. This bit provides the option to keep the Frame-sync and Clock
 * enabled or to disable them after the receive frame in which the receiver is disabled. Writing to
 * this bit has effect only when RE is disabled.The receiver is disabled by clearing the RE bit.
 *
 * Values:
 * 0 - Continue Frame-sync/Clock generation after current frame during which RE is cleared. This may be
 *     required when Frame-sync and Clocks are required from SSI, even when no data is to be
 *     received.
 * 1 - Stop Frame-sync/Clock generation at next frame boundary. This will be effective also in case where
 *     receiver is already disabled in current or previous frames.
 */

#define BP_SSI_SSI_SCR_RFR_CLK_DIS      (11)      //!< Bit position for SSI_SSI_SCR_RFR_CLK_DIS.
#define BM_SSI_SSI_SCR_RFR_CLK_DIS      (0x00000800)  //!< Bit mask for SSI_SSI_SCR_RFR_CLK_DIS.

//! @brief Get value of SSI_SSI_SCR_RFR_CLK_DIS from a register value.
#define BG_SSI_SSI_SCR_RFR_CLK_DIS(r)   (((r) & BM_SSI_SSI_SCR_RFR_CLK_DIS) >> BP_SSI_SSI_SCR_RFR_CLK_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_RFR_CLK_DIS.
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_RFR_CLK_DIS) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_RFR_CLK_DIS.
#define BF_SSI_SSI_SCR_RFR_CLK_DIS(v)   (((v) << BP_SSI_SSI_SCR_RFR_CLK_DIS) & BM_SSI_SSI_SCR_RFR_CLK_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFR_CLK_DIS field to a new value.
#define BW_SSI_SSI_SCR_RFR_CLK_DIS(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_RFR_CLK_DIS) | BF_SSI_SSI_SCR_RFR_CLK_DIS(v)))
#endif


/* --- Register HW_SSI_SSI_SCR, field SYNC_TX_FS[12] (RW)
 *
 * SYNC_FS_TX bit provides a safe window for TE to be visible to the internal circuit which is just
 * after FS occurrence. When SYNC_TX_FS is set, TE(SCR[1]) gets latched on FS occurrence & latched
 * TE is used to enable/disable SSI transmitter. TE needs setup of 2 bit-clock cycles before
 * occurrence of FS. If TE is changed within 2 bit-clock cycles of FS occurrence, there is high
 * probability that TE will be latched on next FS. Note: With TFR_CLK_DIS feature on, TE is used
 * directly to enable transmitter in following cases (i) Sync mode & Rx disabled (ii) Async Mode.
 * Latched-TE is used to disable the transmitter. This bit has no relevance in gated mode and AC97
 * mode.
 *
 * Values:
 * 0 - - TE not latched with FS occurrence & used directly for transmitter enable/disable.
 * 1 - - TE latched with FS occurrence & latched-TE used for transmitter enable/disable.
 */

#define BP_SSI_SSI_SCR_SYNC_TX_FS      (12)      //!< Bit position for SSI_SSI_SCR_SYNC_TX_FS.
#define BM_SSI_SSI_SCR_SYNC_TX_FS      (0x00001000)  //!< Bit mask for SSI_SSI_SCR_SYNC_TX_FS.

//! @brief Get value of SSI_SSI_SCR_SYNC_TX_FS from a register value.
#define BG_SSI_SSI_SCR_SYNC_TX_FS(r)   (((r) & BM_SSI_SSI_SCR_SYNC_TX_FS) >> BP_SSI_SSI_SCR_SYNC_TX_FS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SCR_SYNC_TX_FS.
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   ((((reg32_t) v) << BP_SSI_SSI_SCR_SYNC_TX_FS) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#else
//! @brief Format value for bitfield SSI_SSI_SCR_SYNC_TX_FS.
#define BF_SSI_SSI_SCR_SYNC_TX_FS(v)   (((v) << BP_SSI_SSI_SCR_SYNC_TX_FS) & BM_SSI_SSI_SCR_SYNC_TX_FS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC_TX_FS field to a new value.
#define BW_SSI_SSI_SCR_SYNC_TX_FS(x, v)   (HW_SSI_SSI_SCR_WR(x, (HW_SSI_SSI_SCR_RD(x) & ~BM_SSI_SSI_SCR_SYNC_TX_FS) | BF_SSI_SSI_SCR_SYNC_TX_FS(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SISR - SSI Interrupt Status Register (W1C)
 *
 * Reset value: 0x00003003
 *
 * The SSI Interrupt Status Register (SSI_SISR) is used to monitor the SSI. This register is used by
 * the core to interrogate the status of the In gated mode of operation the TFS, RFS, TLS, RLS, TFRC
 * and RFRC bits of AISR register are not generated. The status bits are described in the following
 * table.   SSI Status flags are valid when SSI is enabled.  See and for interrupt source mapping.
 * All the flags in the SSI_SISR are updated after the first bit of the next SSI word has completed
 * transmission or reception. Certain status bits (ROE0/1 and TUE0/1) are cleared by writing 1 to
 * the corresponding interrupt status bit in SSI_SISR.
 */
typedef union _hw_ssi_ssi_sisr
{
    reg32_t U;
    struct _hw_ssi_ssi_sisr_bitfields
    {
        unsigned TFE0 : 1; //!< [0] Transmit FIFO Empty 0. This flag is set when the empty slots in Tx FIFO exceed or are equal to the selected Tx FIFO WaterMark 0 (TFWM0) threshold. The setting of TFE0 only causes an interrupt when TIE and TFE0_EN are set and Tx FIFO0 is enabled. The TFE0 bit is automatically cleared when the data level in Tx FIFO0 becomes more than the amount specified by the watermark bits. The TFE0 bit is set by POR and SSI reset.
        unsigned TFE1 : 1; //!< [1] Transmit FIFO Empty 1. This flag is set when the empty slots in Tx FIFO exceed or are equal to the selected Tx FIFO WaterMark 1 (TFWM1) threshold and the Two-Channel mode is selected. The setting of TFE1 only causes an interrupt when TIE and TFE1_EN are set, Tx FIFO1 is enabled and Two-Channel mode is selected. The TFE1 bit is automatically cleared when the data level in Tx FIFO1 becomes more than the amount specified by the watermark bits. The TFE1 bit is set by POR and SSI reset.
        unsigned RFF0 : 1; //!< [2] Receive FIFO Full 0. This flag is set when Rx FIFO0 is enabled and the data level in Rx FIFO0 reaches the selected Rx FIFO WaterMark 0 (RFWM0) threshold. The setting of RFF0 only causes an interrupt when RIE and RFF0_EN are set and Rx FIFO0 is enabled. RFF0 is automatically cleared when the amount of data in Rx FIFO0 falls below the threshold. The RFF0 bit is cleared by POR and SSI reset. When Rx FIFO0 contains 8 15 words, the maximum it can hold, all further data received (for storage in this FIFO) is ignored until the FIFO contents are read.
        unsigned RFF1 : 1; //!< [3] Receive FIFO Full 1. This flag is set when Rx FIFO1 is enabled, the data level in Rx FIFO1 reaches the selected Rx FIFO WaterMark 1 (RFWM1) threshold and the SSI is in Two-Channel mode. The setting of RFF1 only causes an interrupt when RIE and RFF1_EN are set, Rx FIFO1 is enabled and the Two-Channel mode is selected. RFF1 is automatically cleared when the amount of data in Rx FIFO1 falls below the threshold. The RFF1 bit is cleared by POR and SSI reset. When Rx FIFO1 contains 8 15 words, the maximum it can hold, all further data received (for storage in this FIFO) is ignored until the FIFO contents are read.
        unsigned RLS : 1; //!< [4] Receive Last Time Slot. This flag indicates the last time slot in a frame. When set, it indicates that the current time slot is the last receive time slot of the frame. RLS is set at the end of the last time slot and causes the SSI to issue an interrupt (if RIE and RLS_EN are set). RLS is cleared when the SISR is read with this bit set. The RLS bit is cleared by POR and SSI reset.
        unsigned TLS : 1; //!< [5] Transmit Last Time Slot. This flag indicates the last time slot in a frame. When set, it indicates that the current time slot is the last time slot of the frame. TLS is set at the start of the last transmit time slot and causes the SSI to issue an interrupt (if TIE and TLS_EN are set). TLS is not generated when frame rate is 1 in normal mode of operation. TLS is cleared when the SISR is read with this bit set. The TLS bit is cleared by POR and SSI reset.
        unsigned RFS : 1; //!< [6] Receive Frame Sync. This flag indicates the occurrence of receive frame sync. In Network mode, the RFS bit is set when the first slot of the frame is being received. It is cleared when the next slot begins to be received. In Normal mode, this bit is always high (When DC = 0). This flag causes an interrupt if RIE and RFS_EN are set. The RFS bit is cleared by POR and SSI reset.
        unsigned TFS : 1; //!< [7] Transmit Frame Sync. This flag indicates the occurrence of transmit frame sync. Data written to the STX registers during the time slot when the TFS flag is set, is sent during the second time slot (in Network mode) or in the next first time slot (in Normal mode). In Network mode, the TFS bit is set during transmission of the first time slot of the frame and is then cleared when starting transmission of the next time slot. In Normal mode, this bit is high for the first time slot. This flag causes an interrupt if TIE and TFS_EN are set. The TFS bit is cleared by POR and SSI reset.
        unsigned TUE0 : 1; //!< [8] Transmitter Underrun Error 0. This flag is set when the TXSR is empty (no data to be transmitted), the TDE0 flag is set and a transmit time slot occurs. When a transmit underrun error occurs, the previous data is retransmitted. In Network mode, each time slot requires data transmission (unless masked through STMSK register), when the transmitter is enabled (TE is set). The TUE0 flag causes an interrupt if TIE and TUE0_EN are set. The TUE0 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit.
        unsigned TUE1 : 1; //!< [9] Transmitter Underrun Error 1. This flag is set when the TXSR is empty (no data to be transmitted), the TDE1 flag is set, a transmit time slot occurs and the SSI is in Two-Channel mode. When a transmit underrun error occurs, the previous data is retransmitted. In Network mode, each time slot requires data transmission (unless masked through STMSK register), when the transmitter is enabled (TE is set). The TUE1 flag causes an interrupt if TIE and TUE1_EN are set. The TUE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit.
        unsigned ROE0 : 1; //!< [10] Receiver Overrun Error 0. This flag is set when the RXSR is filled and ready to transfer to SRX0 register or to Rx FIFO 0 (when enabled) and these are already full. If Rx FIFO 0 is enabled, this is indicated by RFF0 flag, else this is indicated by the RDR0 flag. The RXSR is not transferred in this case. The ROE0 flag causes an interrupt if RIE and ROE0_EN are set. The ROE0 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit. Clearing the RE bit does not affect the ROE0 bit.
        unsigned ROE1 : 1; //!< [11] Receiver Overrun Error 1. This flag is set when the RXSR is filled and ready to transfer to SRX1 register or to Rx FIFO 1 (when enabled) and these are already full and Two-Channel mode is selected. If Rx FIFO 1 is enabled, this is indicated by RFF1 flag, else this is indicated by the RDR1 flag. The RXSR is not transferred in this case. The ROE1 flag causes an interrupt if RIE and ROE1_EN are set. The ROE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit. Clearing the RE bit does not affect the ROE1 bit.
        unsigned TDE0 : 1; //!< [12] Transmit Data Register Empty 0. This flag is set whenever data is transferred to TXSR from STX0 register. If Tx FIFO 0 is enabled, this occurs when there is at least one empty slot in STX0 or Tx FIFO 0. If Tx FIFO 0 is not enabled, this occurs when the contents of STX0 are transferred to TXSR. The TDE0 bit is cleared when the Core writes to STX0. If TIE and TDE0_EN are set, an SSI Transmit Data 0 interrupt request is issued on setting of TDE0 bit. The TDE0 bit is cleared by POR and SSI reset.
        unsigned TDE1 : 1; //!< [13] Transmit Data Register Empty 1. This flag is set whenever data is transferred to TXSR from STX1 register and Two-Channel mode is selected. If Tx FIFO1 is enabled, this occurs when there is at least one empty slot in STX1 or Tx FIFO1. If Tx FIFO1 is not enabled, this occurs when the contents of STX1 are transferred to TXSR. The TDE1 bit is cleared when the Core writes to STX1. If TIE and TDE1_EN are set, an SSI Transmit Data 1 interrupt request is issued on setting of TDE1 bit. The TDE1 bit is cleared by POR and SSI reset.
        unsigned RDR0 : 1; //!< [14] Receive Data Ready 0. This flag bit is set when SRX0 or Rx FIFO 0 is loaded with a new value. RDR0 is cleared when the Core reads the SRX0 register. If Rx FIFO 0 is enabled, RDR0 is cleared when the FIFO is empty. If RIE and RDR0_EN are set, a Receive Data 0 interrupt request is issued on setting of RDR0 bit in case Rx FIFO0 is disabled, if the FIFO is enabled, the interrupt is issued on RFF0 assertion. The RDR0 bit is cleared by POR and SSI reset.
        unsigned RDR1 : 1; //!< [15] Receive Data Ready 1. This flag bit is set when SRX1 or Rx FIFO 1 is loaded with a new value and Two-Channel mode is selected. RDR1 is cleared when the Core reads the SRX1 register. If Rx FIFO 1 is enabled, RDR1 is cleared when the FIFO is empty. If RIE and RDR1_EN are set, a Receive Data 1 interrupt request is issued on setting of RDR1 bit in case Rx FIFO1 is disabled, if the FIFO is enabled, the interrupt is issued on RFF1 assertion. The RDR1 bit is cleared by POR and SSI reset.
        unsigned RXT : 1; //!< [16] Receive Tag Updated. This status bit is set each time there is a difference in the previous and current value of the received tag. It causes the Receive Tag Interrupt (if RXT_EN bit is set). This bit is cleared on reading the SATAG register.
        unsigned CMDDU : 1; //!< [17] Command Data Register Updated. This bit causes the Command Data Updated interrupt (when CMDDU_EN bit is set). This status bit is set each time there is a difference in the previous and current value of the received Command Data. This bit is cleared on reading the SACDAT register.
        unsigned CMDAU : 1; //!< [18] Command Address Register Updated. This bit causes the Command Address Updated interrupt (when CMDAU_EN bit is set). This status bit is set each time there is a difference in the previous and current value of the received Command Address. This bit is cleared on reading the SACADD register.
        unsigned RESERVED0 : 4; //!< [22:19] Reserved
        unsigned TFRC : 1; //!< [23] Transmit Frame Complete. This flag is set at the end of the frame during which Transmitter is disabled. If Transmit Frame & Clock are not disabled in the same frame, this flag is also set at the end of the frame in which Transmit Frame & Clock are disabled. See description of TFR_CLK_DIS bit for more details on how to disable Transmit Frame & Clock or keep them enabled after transmitter is disabled.
        unsigned RFRC : 1; //!< [24] Receive Frame Complete. This flag is set at the end of the frame during which Receiver is disabled. If Receive Frame & Clock are not disabled in the same frame, this flag is also set at the end of the frame in which Receive Frame & Clock are disabled. See the description of RFR_CLK_DIS bit for more details on how to disable Receiver Frame & Clock or keep them enabled after receiver is disabled.
        unsigned RESERVED1 : 7; //!< [31:25] Reserved
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

/* --- Register HW_SSI_SSI_SISR, field TFE0[0] (RO)
 *
 * Transmit FIFO Empty 0. This flag is set when the empty slots in Tx FIFO exceed or are equal to
 * the selected Tx FIFO WaterMark 0 (TFWM0) threshold. The setting of TFE0 only causes an interrupt
 * when TIE and TFE0_EN are set and Tx FIFO0 is enabled. The TFE0 bit is automatically cleared when
 * the data level in Tx FIFO0 becomes more than the amount specified by the watermark bits. The TFE0
 * bit is set by POR and SSI reset.
 *
 * Values:
 * 0 - Transmit FIFO0 has data for transmission.
 * 1 - Transmit FIFO0 is empty.
 */

#define BP_SSI_SSI_SISR_TFE0      (0)      //!< Bit position for SSI_SSI_SISR_TFE0.
#define BM_SSI_SSI_SISR_TFE0      (0x00000001)  //!< Bit mask for SSI_SSI_SISR_TFE0.

//! @brief Get value of SSI_SSI_SISR_TFE0 from a register value.
#define BG_SSI_SSI_SISR_TFE0(r)   (((r) & BM_SSI_SSI_SISR_TFE0) >> BP_SSI_SSI_SISR_TFE0)


/* --- Register HW_SSI_SSI_SISR, field TFE1[1] (RO)
 *
 * Transmit FIFO Empty 1. This flag is set when the empty slots in Tx FIFO exceed or are equal to
 * the selected Tx FIFO WaterMark 1 (TFWM1) threshold and the Two-Channel mode is selected. The
 * setting of TFE1 only causes an interrupt when TIE and TFE1_EN are set, Tx FIFO1 is enabled and
 * Two-Channel mode is selected. The TFE1 bit is automatically cleared when the data level in Tx
 * FIFO1 becomes more than the amount specified by the watermark bits. The TFE1 bit is set by POR
 * and SSI reset.
 *
 * Values:
 * 0 - Transmit FIFO1 has data for transmission.
 * 1 - Transmit FIFO1 is empty.
 */

#define BP_SSI_SSI_SISR_TFE1      (1)      //!< Bit position for SSI_SSI_SISR_TFE1.
#define BM_SSI_SSI_SISR_TFE1      (0x00000002)  //!< Bit mask for SSI_SSI_SISR_TFE1.

//! @brief Get value of SSI_SSI_SISR_TFE1 from a register value.
#define BG_SSI_SSI_SISR_TFE1(r)   (((r) & BM_SSI_SSI_SISR_TFE1) >> BP_SSI_SSI_SISR_TFE1)


/* --- Register HW_SSI_SSI_SISR, field RFF0[2] (RO)
 *
 * Receive FIFO Full 0. This flag is set when Rx FIFO0 is enabled and the data level in Rx FIFO0
 * reaches the selected Rx FIFO WaterMark 0 (RFWM0) threshold. The setting of RFF0 only causes an
 * interrupt when RIE and RFF0_EN are set and Rx FIFO0 is enabled. RFF0 is automatically cleared
 * when the amount of data in Rx FIFO0 falls below the threshold. The RFF0 bit is cleared by POR and
 * SSI reset. When Rx FIFO0 contains 8 15 words, the maximum it can hold, all further data received
 * (for storage in this FIFO) is ignored until the FIFO contents are read.
 *
 * Values:
 * 0 - Space available in Receive FIFO0.
 * 1 - Receive FIFO0 is full.
 */

#define BP_SSI_SSI_SISR_RFF0      (2)      //!< Bit position for SSI_SSI_SISR_RFF0.
#define BM_SSI_SSI_SISR_RFF0      (0x00000004)  //!< Bit mask for SSI_SSI_SISR_RFF0.

//! @brief Get value of SSI_SSI_SISR_RFF0 from a register value.
#define BG_SSI_SSI_SISR_RFF0(r)   (((r) & BM_SSI_SSI_SISR_RFF0) >> BP_SSI_SSI_SISR_RFF0)


/* --- Register HW_SSI_SSI_SISR, field RFF1[3] (RO)
 *
 * Receive FIFO Full 1. This flag is set when Rx FIFO1 is enabled, the data level in Rx FIFO1
 * reaches the selected Rx FIFO WaterMark 1 (RFWM1) threshold and the SSI is in Two-Channel mode.
 * The setting of RFF1 only causes an interrupt when RIE and RFF1_EN are set, Rx FIFO1 is enabled
 * and the Two-Channel mode is selected. RFF1 is automatically cleared when the amount of data in Rx
 * FIFO1 falls below the threshold. The RFF1 bit is cleared by POR and SSI reset. When Rx FIFO1
 * contains 8 15 words, the maximum it can hold, all further data received (for storage in this
 * FIFO) is ignored until the FIFO contents are read.
 *
 * Values:
 * 0 - Space available in Receive FIFO1.
 * 1 - Receive FIFO1 is full.
 */

#define BP_SSI_SSI_SISR_RFF1      (3)      //!< Bit position for SSI_SSI_SISR_RFF1.
#define BM_SSI_SSI_SISR_RFF1      (0x00000008)  //!< Bit mask for SSI_SSI_SISR_RFF1.

//! @brief Get value of SSI_SSI_SISR_RFF1 from a register value.
#define BG_SSI_SSI_SISR_RFF1(r)   (((r) & BM_SSI_SSI_SISR_RFF1) >> BP_SSI_SSI_SISR_RFF1)


/* --- Register HW_SSI_SSI_SISR, field RLS[4] (RO)
 *
 * Receive Last Time Slot. This flag indicates the last time slot in a frame. When set, it indicates
 * that the current time slot is the last receive time slot of the frame. RLS is set at the end of
 * the last time slot and causes the SSI to issue an interrupt (if RIE and RLS_EN are set). RLS is
 * cleared when the SISR is read with this bit set. The RLS bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - Current time slot is not last time slot of frame.
 * 1 - Current time slot is the last receive time slot of frame.
 */

#define BP_SSI_SSI_SISR_RLS      (4)      //!< Bit position for SSI_SSI_SISR_RLS.
#define BM_SSI_SSI_SISR_RLS      (0x00000010)  //!< Bit mask for SSI_SSI_SISR_RLS.

//! @brief Get value of SSI_SSI_SISR_RLS from a register value.
#define BG_SSI_SSI_SISR_RLS(r)   (((r) & BM_SSI_SSI_SISR_RLS) >> BP_SSI_SSI_SISR_RLS)


/* --- Register HW_SSI_SSI_SISR, field TLS[5] (RO)
 *
 * Transmit Last Time Slot. This flag indicates the last time slot in a frame. When set, it
 * indicates that the current time slot is the last time slot of the frame. TLS is set at the start
 * of the last transmit time slot and causes the SSI to issue an interrupt (if TIE and TLS_EN are
 * set). TLS is not generated when frame rate is 1 in normal mode of operation. TLS is cleared when
 * the SISR is read with this bit set. The TLS bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - Current time slot is not last time slot of frame.
 * 1 - Current time slot is the last transmit time slot of frame.
 */

#define BP_SSI_SSI_SISR_TLS      (5)      //!< Bit position for SSI_SSI_SISR_TLS.
#define BM_SSI_SSI_SISR_TLS      (0x00000020)  //!< Bit mask for SSI_SSI_SISR_TLS.

//! @brief Get value of SSI_SSI_SISR_TLS from a register value.
#define BG_SSI_SSI_SISR_TLS(r)   (((r) & BM_SSI_SSI_SISR_TLS) >> BP_SSI_SSI_SISR_TLS)


/* --- Register HW_SSI_SSI_SISR, field RFS[6] (RO)
 *
 * Receive Frame Sync. This flag indicates the occurrence of receive frame sync. In Network mode,
 * the RFS bit is set when the first slot of the frame is being received. It is cleared when the
 * next slot begins to be received. In Normal mode, this bit is always high (When DC = 0). This flag
 * causes an interrupt if RIE and RFS_EN are set. The RFS bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - No Occurrence of Receive frame sync.
 * 1 - Receive frame sync occurred during reception of next word in SRX registers.
 */

#define BP_SSI_SSI_SISR_RFS      (6)      //!< Bit position for SSI_SSI_SISR_RFS.
#define BM_SSI_SSI_SISR_RFS      (0x00000040)  //!< Bit mask for SSI_SSI_SISR_RFS.

//! @brief Get value of SSI_SSI_SISR_RFS from a register value.
#define BG_SSI_SSI_SISR_RFS(r)   (((r) & BM_SSI_SSI_SISR_RFS) >> BP_SSI_SSI_SISR_RFS)


/* --- Register HW_SSI_SSI_SISR, field TFS[7] (RO)
 *
 * Transmit Frame Sync. This flag indicates the occurrence of transmit frame sync. Data written to
 * the STX registers during the time slot when the TFS flag is set, is sent during the second time
 * slot (in Network mode) or in the next first time slot (in Normal mode). In Network mode, the TFS
 * bit is set during transmission of the first time slot of the frame and is then cleared when
 * starting transmission of the next time slot. In Normal mode, this bit is high for the first time
 * slot. This flag causes an interrupt if TIE and TFS_EN are set. The TFS bit is cleared by POR and
 * SSI reset.
 *
 * Values:
 * 0 - No Occurrence of Transmit frame sync.
 * 1 - Transmit frame sync occurred during transmission of last word written to STX registers.
 */

#define BP_SSI_SSI_SISR_TFS      (7)      //!< Bit position for SSI_SSI_SISR_TFS.
#define BM_SSI_SSI_SISR_TFS      (0x00000080)  //!< Bit mask for SSI_SSI_SISR_TFS.

//! @brief Get value of SSI_SSI_SISR_TFS from a register value.
#define BG_SSI_SSI_SISR_TFS(r)   (((r) & BM_SSI_SSI_SISR_TFS) >> BP_SSI_SSI_SISR_TFS)


/* --- Register HW_SSI_SSI_SISR, field TUE0[8] (W1C)
 *
 * Transmitter Underrun Error 0. This flag is set when the TXSR is empty (no data to be
 * transmitted), the TDE0 flag is set and a transmit time slot occurs. When a transmit underrun
 * error occurs, the previous data is retransmitted. In Network mode, each time slot requires data
 * transmission (unless masked through STMSK register), when the transmitter is enabled (TE is set).
 * The TUE0 flag causes an interrupt if TIE and TUE0_EN are set. The TUE0 bit is cleared by POR and
 * SSI reset. It is also cleared by writing '1' to this bit.
 *
 * Values:
 * 0 - Default interrupt issued to the Core.
 * 1 - Exception interrupt issued to the Core.
 */

#define BP_SSI_SSI_SISR_TUE0      (8)      //!< Bit position for SSI_SSI_SISR_TUE0.
#define BM_SSI_SSI_SISR_TUE0      (0x00000100)  //!< Bit mask for SSI_SSI_SISR_TUE0.

//! @brief Get value of SSI_SSI_SISR_TUE0 from a register value.
#define BG_SSI_SSI_SISR_TUE0(r)   (((r) & BM_SSI_SSI_SISR_TUE0) >> BP_SSI_SSI_SISR_TUE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SISR_TUE0.
#define BF_SSI_SSI_SISR_TUE0(v)   ((((reg32_t) v) << BP_SSI_SSI_SISR_TUE0) & BM_SSI_SSI_SISR_TUE0)
#else
//! @brief Format value for bitfield SSI_SSI_SISR_TUE0.
#define BF_SSI_SSI_SISR_TUE0(v)   (((v) << BP_SSI_SSI_SISR_TUE0) & BM_SSI_SSI_SISR_TUE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TUE0 field to a new value.
#define BW_SSI_SSI_SISR_TUE0(x, v)   (HW_SSI_SSI_SISR_WR(x, (HW_SSI_SSI_SISR_RD(x) & ~BM_SSI_SSI_SISR_TUE0) | BF_SSI_SSI_SISR_TUE0(v)))
#endif


/* --- Register HW_SSI_SSI_SISR, field TUE1[9] (W1C)
 *
 * Transmitter Underrun Error 1. This flag is set when the TXSR is empty (no data to be
 * transmitted), the TDE1 flag is set, a transmit time slot occurs and the SSI is in Two-Channel
 * mode. When a transmit underrun error occurs, the previous data is retransmitted. In Network mode,
 * each time slot requires data transmission (unless masked through STMSK register), when the
 * transmitter is enabled (TE is set). The TUE1 flag causes an interrupt if TIE and TUE1_EN are set.
 * The TUE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1' to this bit.
 *
 * Values:
 * 0 - Default interrupt issued to the Core.
 * 1 - Exception interrupt issued to the Core.
 */

#define BP_SSI_SSI_SISR_TUE1      (9)      //!< Bit position for SSI_SSI_SISR_TUE1.
#define BM_SSI_SSI_SISR_TUE1      (0x00000200)  //!< Bit mask for SSI_SSI_SISR_TUE1.

//! @brief Get value of SSI_SSI_SISR_TUE1 from a register value.
#define BG_SSI_SSI_SISR_TUE1(r)   (((r) & BM_SSI_SSI_SISR_TUE1) >> BP_SSI_SSI_SISR_TUE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SISR_TUE1.
#define BF_SSI_SSI_SISR_TUE1(v)   ((((reg32_t) v) << BP_SSI_SSI_SISR_TUE1) & BM_SSI_SSI_SISR_TUE1)
#else
//! @brief Format value for bitfield SSI_SSI_SISR_TUE1.
#define BF_SSI_SSI_SISR_TUE1(v)   (((v) << BP_SSI_SSI_SISR_TUE1) & BM_SSI_SSI_SISR_TUE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TUE1 field to a new value.
#define BW_SSI_SSI_SISR_TUE1(x, v)   (HW_SSI_SSI_SISR_WR(x, (HW_SSI_SSI_SISR_RD(x) & ~BM_SSI_SSI_SISR_TUE1) | BF_SSI_SSI_SISR_TUE1(v)))
#endif


/* --- Register HW_SSI_SSI_SISR, field ROE0[10] (W1C)
 *
 * Receiver Overrun Error 0. This flag is set when the RXSR is filled and ready to transfer to SRX0
 * register or to Rx FIFO 0 (when enabled) and these are already full. If Rx FIFO 0 is enabled, this
 * is indicated by RFF0 flag, else this is indicated by the RDR0 flag. The RXSR is not transferred
 * in this case. The ROE0 flag causes an interrupt if RIE and ROE0_EN are set. The ROE0 bit is
 * cleared by POR and SSI reset. It is also cleared by writing '1' to this bit. Clearing the RE bit
 * does not affect the ROE0 bit.
 *
 * Values:
 * 0 - Default interrupt issued to the Core.
 * 1 - Exception interrupt issued to the Core.
 */

#define BP_SSI_SSI_SISR_ROE0      (10)      //!< Bit position for SSI_SSI_SISR_ROE0.
#define BM_SSI_SSI_SISR_ROE0      (0x00000400)  //!< Bit mask for SSI_SSI_SISR_ROE0.

//! @brief Get value of SSI_SSI_SISR_ROE0 from a register value.
#define BG_SSI_SSI_SISR_ROE0(r)   (((r) & BM_SSI_SSI_SISR_ROE0) >> BP_SSI_SSI_SISR_ROE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SISR_ROE0.
#define BF_SSI_SSI_SISR_ROE0(v)   ((((reg32_t) v) << BP_SSI_SSI_SISR_ROE0) & BM_SSI_SSI_SISR_ROE0)
#else
//! @brief Format value for bitfield SSI_SSI_SISR_ROE0.
#define BF_SSI_SSI_SISR_ROE0(v)   (((v) << BP_SSI_SSI_SISR_ROE0) & BM_SSI_SSI_SISR_ROE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROE0 field to a new value.
#define BW_SSI_SSI_SISR_ROE0(x, v)   (HW_SSI_SSI_SISR_WR(x, (HW_SSI_SSI_SISR_RD(x) & ~BM_SSI_SSI_SISR_ROE0) | BF_SSI_SSI_SISR_ROE0(v)))
#endif


/* --- Register HW_SSI_SSI_SISR, field ROE1[11] (W1C)
 *
 * Receiver Overrun Error 1. This flag is set when the RXSR is filled and ready to transfer to SRX1
 * register or to Rx FIFO 1 (when enabled) and these are already full and Two-Channel mode is
 * selected. If Rx FIFO 1 is enabled, this is indicated by RFF1 flag, else this is indicated by the
 * RDR1 flag. The RXSR is not transferred in this case. The ROE1 flag causes an interrupt if RIE and
 * ROE1_EN are set. The ROE1 bit is cleared by POR and SSI reset. It is also cleared by writing '1'
 * to this bit. Clearing the RE bit does not affect the ROE1 bit.
 *
 * Values:
 * 0 - Default interrupt issued to the Core.
 * 1 - Exception interrupt issued to the Core.
 */

#define BP_SSI_SSI_SISR_ROE1      (11)      //!< Bit position for SSI_SSI_SISR_ROE1.
#define BM_SSI_SSI_SISR_ROE1      (0x00000800)  //!< Bit mask for SSI_SSI_SISR_ROE1.

//! @brief Get value of SSI_SSI_SISR_ROE1 from a register value.
#define BG_SSI_SSI_SISR_ROE1(r)   (((r) & BM_SSI_SSI_SISR_ROE1) >> BP_SSI_SSI_SISR_ROE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SISR_ROE1.
#define BF_SSI_SSI_SISR_ROE1(v)   ((((reg32_t) v) << BP_SSI_SSI_SISR_ROE1) & BM_SSI_SSI_SISR_ROE1)
#else
//! @brief Format value for bitfield SSI_SSI_SISR_ROE1.
#define BF_SSI_SSI_SISR_ROE1(v)   (((v) << BP_SSI_SSI_SISR_ROE1) & BM_SSI_SSI_SISR_ROE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROE1 field to a new value.
#define BW_SSI_SSI_SISR_ROE1(x, v)   (HW_SSI_SSI_SISR_WR(x, (HW_SSI_SSI_SISR_RD(x) & ~BM_SSI_SSI_SISR_ROE1) | BF_SSI_SSI_SISR_ROE1(v)))
#endif


/* --- Register HW_SSI_SSI_SISR, field TDE0[12] (RO)
 *
 * Transmit Data Register Empty 0. This flag is set whenever data is transferred to TXSR from STX0
 * register. If Tx FIFO 0 is enabled, this occurs when there is at least one empty slot in STX0 or
 * Tx FIFO 0. If Tx FIFO 0 is not enabled, this occurs when the contents of STX0 are transferred to
 * TXSR. The TDE0 bit is cleared when the Core writes to STX0. If TIE and TDE0_EN are set, an SSI
 * Transmit Data 0 interrupt request is issued on setting of TDE0 bit. The TDE0 bit is cleared by
 * POR and SSI reset.
 *
 * Values:
 * 0 - Data available for transmission.
 * 1 - Data needs to be written by the Core for transmission.
 */

#define BP_SSI_SSI_SISR_TDE0      (12)      //!< Bit position for SSI_SSI_SISR_TDE0.
#define BM_SSI_SSI_SISR_TDE0      (0x00001000)  //!< Bit mask for SSI_SSI_SISR_TDE0.

//! @brief Get value of SSI_SSI_SISR_TDE0 from a register value.
#define BG_SSI_SSI_SISR_TDE0(r)   (((r) & BM_SSI_SSI_SISR_TDE0) >> BP_SSI_SSI_SISR_TDE0)


/* --- Register HW_SSI_SSI_SISR, field TDE1[13] (RO)
 *
 * Transmit Data Register Empty 1. This flag is set whenever data is transferred to TXSR from STX1
 * register and Two-Channel mode is selected. If Tx FIFO1 is enabled, this occurs when there is at
 * least one empty slot in STX1 or Tx FIFO1. If Tx FIFO1 is not enabled, this occurs when the
 * contents of STX1 are transferred to TXSR. The TDE1 bit is cleared when the Core writes to STX1.
 * If TIE and TDE1_EN are set, an SSI Transmit Data 1 interrupt request is issued on setting of TDE1
 * bit. The TDE1 bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - Data available for transmission.
 * 1 - Data needs to be written by the Core for transmission.
 */

#define BP_SSI_SSI_SISR_TDE1      (13)      //!< Bit position for SSI_SSI_SISR_TDE1.
#define BM_SSI_SSI_SISR_TDE1      (0x00002000)  //!< Bit mask for SSI_SSI_SISR_TDE1.

//! @brief Get value of SSI_SSI_SISR_TDE1 from a register value.
#define BG_SSI_SSI_SISR_TDE1(r)   (((r) & BM_SSI_SSI_SISR_TDE1) >> BP_SSI_SSI_SISR_TDE1)


/* --- Register HW_SSI_SSI_SISR, field RDR0[14] (RO)
 *
 * Receive Data Ready 0. This flag bit is set when SRX0 or Rx FIFO 0 is loaded with a new value.
 * RDR0 is cleared when the Core reads the SRX0 register. If Rx FIFO 0 is enabled, RDR0 is cleared
 * when the FIFO is empty. If RIE and RDR0_EN are set, a Receive Data 0 interrupt request is issued
 * on setting of RDR0 bit in case Rx FIFO0 is disabled, if the FIFO is enabled, the interrupt is
 * issued on RFF0 assertion. The RDR0 bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - No new data for Core to read.
 * 1 - New data for Core to read.
 */

#define BP_SSI_SSI_SISR_RDR0      (14)      //!< Bit position for SSI_SSI_SISR_RDR0.
#define BM_SSI_SSI_SISR_RDR0      (0x00004000)  //!< Bit mask for SSI_SSI_SISR_RDR0.

//! @brief Get value of SSI_SSI_SISR_RDR0 from a register value.
#define BG_SSI_SSI_SISR_RDR0(r)   (((r) & BM_SSI_SSI_SISR_RDR0) >> BP_SSI_SSI_SISR_RDR0)


/* --- Register HW_SSI_SSI_SISR, field RDR1[15] (RO)
 *
 * Receive Data Ready 1. This flag bit is set when SRX1 or Rx FIFO 1 is loaded with a new value and
 * Two-Channel mode is selected. RDR1 is cleared when the Core reads the SRX1 register. If Rx FIFO 1
 * is enabled, RDR1 is cleared when the FIFO is empty. If RIE and RDR1_EN are set, a Receive Data 1
 * interrupt request is issued on setting of RDR1 bit in case Rx FIFO1 is disabled, if the FIFO is
 * enabled, the interrupt is issued on RFF1 assertion. The RDR1 bit is cleared by POR and SSI reset.
 *
 * Values:
 * 0 - No new data for Core to read.
 * 1 - New data for Core to read.
 */

#define BP_SSI_SSI_SISR_RDR1      (15)      //!< Bit position for SSI_SSI_SISR_RDR1.
#define BM_SSI_SSI_SISR_RDR1      (0x00008000)  //!< Bit mask for SSI_SSI_SISR_RDR1.

//! @brief Get value of SSI_SSI_SISR_RDR1 from a register value.
#define BG_SSI_SSI_SISR_RDR1(r)   (((r) & BM_SSI_SSI_SISR_RDR1) >> BP_SSI_SSI_SISR_RDR1)


/* --- Register HW_SSI_SSI_SISR, field RXT[16] (RO)
 *
 * Receive Tag Updated. This status bit is set each time there is a difference in the previous and
 * current value of the received tag. It causes the Receive Tag Interrupt (if RXT_EN bit is set).
 * This bit is cleared on reading the SATAG register.
 *
 * Values:
 * 0 - No change in SATAG register.
 * 1 - SATAG register updated with different value.
 */

#define BP_SSI_SSI_SISR_RXT      (16)      //!< Bit position for SSI_SSI_SISR_RXT.
#define BM_SSI_SSI_SISR_RXT      (0x00010000)  //!< Bit mask for SSI_SSI_SISR_RXT.

//! @brief Get value of SSI_SSI_SISR_RXT from a register value.
#define BG_SSI_SSI_SISR_RXT(r)   (((r) & BM_SSI_SSI_SISR_RXT) >> BP_SSI_SSI_SISR_RXT)


/* --- Register HW_SSI_SSI_SISR, field CMDDU[17] (RO)
 *
 * Command Data Register Updated. This bit causes the Command Data Updated interrupt (when CMDDU_EN
 * bit is set). This status bit is set each time there is a difference in the previous and current
 * value of the received Command Data. This bit is cleared on reading the SACDAT register.
 *
 * Values:
 * 0 - No change in SACDAT register.
 * 1 - SACDAT register updated with different value.
 */

#define BP_SSI_SSI_SISR_CMDDU      (17)      //!< Bit position for SSI_SSI_SISR_CMDDU.
#define BM_SSI_SSI_SISR_CMDDU      (0x00020000)  //!< Bit mask for SSI_SSI_SISR_CMDDU.

//! @brief Get value of SSI_SSI_SISR_CMDDU from a register value.
#define BG_SSI_SSI_SISR_CMDDU(r)   (((r) & BM_SSI_SSI_SISR_CMDDU) >> BP_SSI_SSI_SISR_CMDDU)


/* --- Register HW_SSI_SSI_SISR, field CMDAU[18] (RO)
 *
 * Command Address Register Updated. This bit causes the Command Address Updated interrupt (when
 * CMDAU_EN bit is set). This status bit is set each time there is a difference in the previous and
 * current value of the received Command Address. This bit is cleared on reading the SACADD
 * register.
 *
 * Values:
 * 0 - No change in SACADD register.
 * 1 - SACADD register updated with different value.
 */

#define BP_SSI_SSI_SISR_CMDAU      (18)      //!< Bit position for SSI_SSI_SISR_CMDAU.
#define BM_SSI_SSI_SISR_CMDAU      (0x00040000)  //!< Bit mask for SSI_SSI_SISR_CMDAU.

//! @brief Get value of SSI_SSI_SISR_CMDAU from a register value.
#define BG_SSI_SSI_SISR_CMDAU(r)   (((r) & BM_SSI_SSI_SISR_CMDAU) >> BP_SSI_SSI_SISR_CMDAU)


/* --- Register HW_SSI_SSI_SISR, field TFRC[23] (RO)
 *
 * Transmit Frame Complete. This flag is set at the end of the frame during which Transmitter is
 * disabled. If Transmit Frame & Clock are not disabled in the same frame, this flag is also set at
 * the end of the frame in which Transmit Frame & Clock are disabled. See description of TFR_CLK_DIS
 * bit for more details on how to disable Transmit Frame & Clock or keep them enabled after
 * transmitter is disabled.
 *
 * Values:
 * 0 - End of Frame not reached
 * 1 - End of frame reached after disabling TE or disabling TFR_CLK_DIS, when transmitter is already
 *     disabled.
 */

#define BP_SSI_SSI_SISR_TFRC      (23)      //!< Bit position for SSI_SSI_SISR_TFRC.
#define BM_SSI_SSI_SISR_TFRC      (0x00800000)  //!< Bit mask for SSI_SSI_SISR_TFRC.

//! @brief Get value of SSI_SSI_SISR_TFRC from a register value.
#define BG_SSI_SSI_SISR_TFRC(r)   (((r) & BM_SSI_SSI_SISR_TFRC) >> BP_SSI_SSI_SISR_TFRC)


/* --- Register HW_SSI_SSI_SISR, field RFRC[24] (RO)
 *
 * Receive Frame Complete. This flag is set at the end of the frame during which Receiver is
 * disabled. If Receive Frame & Clock are not disabled in the same frame, this flag is also set at
 * the end of the frame in which Receive Frame & Clock are disabled. See the description of
 * RFR_CLK_DIS bit for more details on how to disable Receiver Frame & Clock or keep them enabled
 * after receiver is disabled.
 *
 * Values:
 * 0 - End of Frame not reached
 * 1 - End of frame reached after disabling RE or disabling RFR_CLK_DIS, when receiver is already disabled.
 */

#define BP_SSI_SSI_SISR_RFRC      (24)      //!< Bit position for SSI_SSI_SISR_RFRC.
#define BM_SSI_SSI_SISR_RFRC      (0x01000000)  //!< Bit mask for SSI_SSI_SISR_RFRC.

//! @brief Get value of SSI_SSI_SISR_RFRC from a register value.
#define BG_SSI_SSI_SISR_RFRC(r)   (((r) & BM_SSI_SSI_SISR_RFRC) >> BP_SSI_SSI_SISR_RFRC)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SIER - SSI Interrupt Enable Register (RW)
 *
 * Reset value: 0x00003003
 *
 * The SSI Interrupt Enable Register (SIER) is a 25-bit register used to set up the SSI interrupts
 * and DMA requests.
 */
typedef union _hw_ssi_sier
{
    reg32_t U;
    struct _hw_ssi_sier_bitfields
    {
        unsigned ENABLE_BITS : 19; //!< [18:0] Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt to the Core or not.
        unsigned TIE : 1; //!< [19] Transmit Interrupt Enable. This control bit allows the SSI to issue transmitter data related interrupts to the Core. Refer to for a detailed description of this bit.
        unsigned TDMAE : 1; //!< [20] Transmit DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests are generated when any of the TFE0/1 bits in the SISR are set and if the corresponding TFEN bit is also set. If the corresponding FIFO is disabled, a DMA request is generated when the corresponding TDE bit is set.
        unsigned RIE : 1; //!< [21] Receive Interrupt Enable. This control bit allows the SSI to issue receiver related interrupts to the Core. Refer to for a detailed description of this bit.
        unsigned RDMAE : 1; //!< [22] Receive DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests are generated when any of the RFF0/1 bits in the SISR are set and if the corresponding RFEN bit is also set. If the corresponding FIFO is disabled, a DMA request is generated when the corresponding RDR bit is set.
        unsigned ENABLE_BITS1 : 2; //!< [24:23] Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt to the Core or not.
        unsigned RESERVED0 : 7; //!< [31:25] Reserved
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

/* --- Register HW_SSI_SIER, field ENABLE_BITS[18:0] (RW)
 *
 * Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt
 * to the Core or not.
 *
 * Values:
 * 0 - Corresponding status bit cannot issue interrupt.
 * 1 - Corresponding status bit can issue interrupt.
 */

#define BP_SSI_SIER_ENABLE_BITS      (0)      //!< Bit position for SSI_SIER_ENABLE_BITS.
#define BM_SSI_SIER_ENABLE_BITS      (0x0007ffff)  //!< Bit mask for SSI_SIER_ENABLE_BITS.

//! @brief Get value of SSI_SIER_ENABLE_BITS from a register value.
#define BG_SSI_SIER_ENABLE_BITS(r)   (((r) & BM_SSI_SIER_ENABLE_BITS) >> BP_SSI_SIER_ENABLE_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_ENABLE_BITS.
#define BF_SSI_SIER_ENABLE_BITS(v)   ((((reg32_t) v) << BP_SSI_SIER_ENABLE_BITS) & BM_SSI_SIER_ENABLE_BITS)
#else
//! @brief Format value for bitfield SSI_SIER_ENABLE_BITS.
#define BF_SSI_SIER_ENABLE_BITS(v)   (((v) << BP_SSI_SIER_ENABLE_BITS) & BM_SSI_SIER_ENABLE_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BITS field to a new value.
#define BW_SSI_SIER_ENABLE_BITS(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_ENABLE_BITS) | BF_SSI_SIER_ENABLE_BITS(v)))
#endif


/* --- Register HW_SSI_SIER, field TIE[19] (RW)
 *
 * Transmit Interrupt Enable. This control bit allows the SSI to issue transmitter data related
 * interrupts to the Core. Refer to for a detailed description of this bit.
 *
 * Values:
 * 0 - SSI Transmitter Interrupt requests disabled.
 * 1 - SSI Transmitter Interrupt requests enabled.
 */

#define BP_SSI_SIER_TIE      (19)      //!< Bit position for SSI_SIER_TIE.
#define BM_SSI_SIER_TIE      (0x00080000)  //!< Bit mask for SSI_SIER_TIE.

//! @brief Get value of SSI_SIER_TIE from a register value.
#define BG_SSI_SIER_TIE(r)   (((r) & BM_SSI_SIER_TIE) >> BP_SSI_SIER_TIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_TIE.
#define BF_SSI_SIER_TIE(v)   ((((reg32_t) v) << BP_SSI_SIER_TIE) & BM_SSI_SIER_TIE)
#else
//! @brief Format value for bitfield SSI_SIER_TIE.
#define BF_SSI_SIER_TIE(v)   (((v) << BP_SSI_SIER_TIE) & BM_SSI_SIER_TIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE field to a new value.
#define BW_SSI_SIER_TIE(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_TIE) | BF_SSI_SIER_TIE(v)))
#endif


/* --- Register HW_SSI_SIER, field TDMAE[20] (RW)
 *
 * Transmit DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests
 * are generated when any of the TFE0/1 bits in the SISR are set and if the corresponding TFEN bit
 * is also set. If the corresponding FIFO is disabled, a DMA request is generated when the
 * corresponding TDE bit is set.
 *
 * Values:
 * 0 - SSI Transmitter DMA requests disabled.
 * 1 - SSI Transmitter DMA requests enabled.
 */

#define BP_SSI_SIER_TDMAE      (20)      //!< Bit position for SSI_SIER_TDMAE.
#define BM_SSI_SIER_TDMAE      (0x00100000)  //!< Bit mask for SSI_SIER_TDMAE.

//! @brief Get value of SSI_SIER_TDMAE from a register value.
#define BG_SSI_SIER_TDMAE(r)   (((r) & BM_SSI_SIER_TDMAE) >> BP_SSI_SIER_TDMAE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_TDMAE.
#define BF_SSI_SIER_TDMAE(v)   ((((reg32_t) v) << BP_SSI_SIER_TDMAE) & BM_SSI_SIER_TDMAE)
#else
//! @brief Format value for bitfield SSI_SIER_TDMAE.
#define BF_SSI_SIER_TDMAE(v)   (((v) << BP_SSI_SIER_TDMAE) & BM_SSI_SIER_TDMAE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TDMAE field to a new value.
#define BW_SSI_SIER_TDMAE(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_TDMAE) | BF_SSI_SIER_TDMAE(v)))
#endif


/* --- Register HW_SSI_SIER, field RIE[21] (RW)
 *
 * Receive Interrupt Enable. This control bit allows the SSI to issue receiver related interrupts to
 * the Core. Refer to for a detailed description of this bit.
 *
 * Values:
 * 0 - SSI Receiver Interrupt requests disabled.
 * 1 - SSI Receiver Interrupt requests enabled.
 */

#define BP_SSI_SIER_RIE      (21)      //!< Bit position for SSI_SIER_RIE.
#define BM_SSI_SIER_RIE      (0x00200000)  //!< Bit mask for SSI_SIER_RIE.

//! @brief Get value of SSI_SIER_RIE from a register value.
#define BG_SSI_SIER_RIE(r)   (((r) & BM_SSI_SIER_RIE) >> BP_SSI_SIER_RIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_RIE.
#define BF_SSI_SIER_RIE(v)   ((((reg32_t) v) << BP_SSI_SIER_RIE) & BM_SSI_SIER_RIE)
#else
//! @brief Format value for bitfield SSI_SIER_RIE.
#define BF_SSI_SIER_RIE(v)   (((v) << BP_SSI_SIER_RIE) & BM_SSI_SIER_RIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RIE field to a new value.
#define BW_SSI_SIER_RIE(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_RIE) | BF_SSI_SIER_RIE(v)))
#endif


/* --- Register HW_SSI_SIER, field RDMAE[22] (RW)
 *
 * Receive DMA Enable. This bit allows SSI to request for DMA transfers. When enabled, DMA requests
 * are generated when any of the RFF0/1 bits in the SISR are set and if the corresponding RFEN bit
 * is also set. If the corresponding FIFO is disabled, a DMA request is generated when the
 * corresponding RDR bit is set.
 *
 * Values:
 * 0 - SSI Receiver DMA requests disabled.
 * 1 - SSI Receiver DMA requests enabled.
 */

#define BP_SSI_SIER_RDMAE      (22)      //!< Bit position for SSI_SIER_RDMAE.
#define BM_SSI_SIER_RDMAE      (0x00400000)  //!< Bit mask for SSI_SIER_RDMAE.

//! @brief Get value of SSI_SIER_RDMAE from a register value.
#define BG_SSI_SIER_RDMAE(r)   (((r) & BM_SSI_SIER_RDMAE) >> BP_SSI_SIER_RDMAE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_RDMAE.
#define BF_SSI_SIER_RDMAE(v)   ((((reg32_t) v) << BP_SSI_SIER_RDMAE) & BM_SSI_SIER_RDMAE)
#else
//! @brief Format value for bitfield SSI_SIER_RDMAE.
#define BF_SSI_SIER_RDMAE(v)   (((v) << BP_SSI_SIER_RDMAE) & BM_SSI_SIER_RDMAE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RDMAE field to a new value.
#define BW_SSI_SIER_RDMAE(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_RDMAE) | BF_SSI_SIER_RDMAE(v)))
#endif


/* --- Register HW_SSI_SIER, field ENABLE_BITS1[24:23] (RW)
 *
 * Enable Bit. Each bit controls whether the corresponding status bit in SISR can issue an interrupt
 * to the Core or not.
 *
 * Values:
 * 0 - Corresponding status bit cannot issue interrupt.
 * 1 - Corresponding status bit can issue interrupt.
 */

#define BP_SSI_SIER_ENABLE_BITS1      (23)      //!< Bit position for SSI_SIER_ENABLE_BITS1.
#define BM_SSI_SIER_ENABLE_BITS1      (0x01800000)  //!< Bit mask for SSI_SIER_ENABLE_BITS1.

//! @brief Get value of SSI_SIER_ENABLE_BITS1 from a register value.
#define BG_SSI_SIER_ENABLE_BITS1(r)   (((r) & BM_SSI_SIER_ENABLE_BITS1) >> BP_SSI_SIER_ENABLE_BITS1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SIER_ENABLE_BITS1.
#define BF_SSI_SIER_ENABLE_BITS1(v)   ((((reg32_t) v) << BP_SSI_SIER_ENABLE_BITS1) & BM_SSI_SIER_ENABLE_BITS1)
#else
//! @brief Format value for bitfield SSI_SIER_ENABLE_BITS1.
#define BF_SSI_SIER_ENABLE_BITS1(v)   (((v) << BP_SSI_SIER_ENABLE_BITS1) & BM_SSI_SIER_ENABLE_BITS1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BITS1 field to a new value.
#define BW_SSI_SIER_ENABLE_BITS1(x, v)   (HW_SSI_SIER_WR(x, (HW_SSI_SIER_RD(x) & ~BM_SSI_SIER_ENABLE_BITS1) | BF_SSI_SIER_ENABLE_BITS1(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_STCR - SSI Transmit Configuration Register (RW)
 *
 * Reset value: 0x00000200
 *
 * The SSI Transmit Configuration Register (SSI_STCR) is a read/write control register used to
 * direct the transmit operation of the STCR controls the direction of the bit clock and frame sync
 * ports, STCK and STFS. Interrupt enable bit for the transmit sections is provided in this control
 * register. The Power-on reset clears all SSI_STCR bits. However, SSI reset does not affect the
 * SSI_STCR bits. The SSI_STCR bits are described in the following paragraphs. See the Programmable
 * Registers section for the programming model of the SSI. The SSI Control Register (SSI_SCR) must
 * first be set to enable interrupts. Next, the SSI interrupt bit in the Interrupt Enable Register
 * (SSI_SIER) must be set to enable the interrupt. Finally, the interrupt can be enabled from within
 * the
 */
typedef union _hw_ssi_ssi_stcr
{
    reg32_t U;
    struct _hw_ssi_ssi_stcr_bitfields
    {
        unsigned TEFS : 1; //!< [0] Transmit Early Frame Sync. This bit controls when the frame sync is initiated for the transmit section. The frame sync signal is deasserted after one bit-for-bit length frame sync and after one word-for-word length frame sync. In case of synchronous operation, the frame sync can also be initiated on receiving the first bit of data.
        unsigned TFSL : 1; //!< [1] Transmit Frame Sync Length. This bit controls the length of the frame sync signal to be generated or recognized for the transmit section. The length of a word-long frame sync is same as the length of the data word selected by WL[3:0].
        unsigned TFSI : 1; //!< [2] Transmit Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for the transmit section of SSI.
        unsigned TSCKP : 1; //!< [3] Transmit Clock Polarity. This bit controls which bit clock edge is used to clock out data for the transmit section. Note: TSCKP is 0 CLK_IST = 0; TSCKP is 1CLK_IST = 1
        unsigned TSHFD : 1; //!< [4] Transmit Shift Direction. This bit controls whether the MSB or LSB will be transmitted first in a sample. The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0. Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (TSHFD cleared).
        unsigned TXDIR : 1; //!< [5] Transmit Clock Direction. This bit controls the direction and source of the clock signal used to clock the TXSR. Internally generated clock is output through the STCK port. External clock is taken from this port. Refer to for details of clock pin configurations.
        unsigned TFDIR : 1; //!< [6] Transmit Frame Direction. This bit controls the direction and source of the transmit frame sync signal. Internally generated frame sync signal is sent out through the STFS port and external frame sync is taken from the same port.
        unsigned TFEN0 : 1; //!< [7] Transmit FIFO Enable 0. This bit enables transmit FIFO 0. When enabled, the FIFO allows 8 15 samples to be transmitted by the SSI per channel (a 9th sample can be shifting out) before TDE0 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is transferred to the transmit shift register (provided the interrupt is enabled).
        unsigned TFEN1 : 1; //!< [8] Transmit FIFO Enable 1. This bit enables transmit FIFO 1. When enabled, the FIFO allows 8 15 samples to be transmitted by the SSI (per channel) (a 9th sample can be shifting out) before TDE1 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is transferred to the transmit shift register (provided the interrupt is enabled).
        unsigned TXBIT0 : 1; //!< [9] Transmit Bit 0. This control bit allows SSI to transmit the data word from bit position 0 or 15/31 in the transmit shift register. The shifting data direction can be MSB or LSB first, controlled by the TSHFD bit.
        unsigned RESERVED0 : 22; //!< [31:10] Reserved
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

/* --- Register HW_SSI_SSI_STCR, field TEFS[0] (RW)
 *
 * Transmit Early Frame Sync. This bit controls when the frame sync is initiated for the transmit
 * section. The frame sync signal is deasserted after one bit-for-bit length frame sync and after
 * one word-for-word length frame sync. In case of synchronous operation, the frame sync can also be
 * initiated on receiving the first bit of data.
 *
 * Values:
 * 0 - Transmit frame sync initiated as the first bit of data is transmitted.
 * 1 - Transmit frame sync is initiated one bit before the data is transmitted.
 */

#define BP_SSI_SSI_STCR_TEFS      (0)      //!< Bit position for SSI_SSI_STCR_TEFS.
#define BM_SSI_SSI_STCR_TEFS      (0x00000001)  //!< Bit mask for SSI_SSI_STCR_TEFS.

//! @brief Get value of SSI_SSI_STCR_TEFS from a register value.
#define BG_SSI_SSI_STCR_TEFS(r)   (((r) & BM_SSI_SSI_STCR_TEFS) >> BP_SSI_SSI_STCR_TEFS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TEFS.
#define BF_SSI_SSI_STCR_TEFS(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TEFS) & BM_SSI_SSI_STCR_TEFS)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TEFS.
#define BF_SSI_SSI_STCR_TEFS(v)   (((v) << BP_SSI_SSI_STCR_TEFS) & BM_SSI_SSI_STCR_TEFS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEFS field to a new value.
#define BW_SSI_SSI_STCR_TEFS(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TEFS) | BF_SSI_SSI_STCR_TEFS(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TFSL[1] (RW)
 *
 * Transmit Frame Sync Length. This bit controls the length of the frame sync signal to be generated
 * or recognized for the transmit section. The length of a word-long frame sync is same as the
 * length of the data word selected by WL[3:0].
 *
 * Values:
 * 0 - Transmit frame sync is one-word long.
 * 1 - Transmit frame sync is one-clock-bit long.
 */

#define BP_SSI_SSI_STCR_TFSL      (1)      //!< Bit position for SSI_SSI_STCR_TFSL.
#define BM_SSI_SSI_STCR_TFSL      (0x00000002)  //!< Bit mask for SSI_SSI_STCR_TFSL.

//! @brief Get value of SSI_SSI_STCR_TFSL from a register value.
#define BG_SSI_SSI_STCR_TFSL(r)   (((r) & BM_SSI_SSI_STCR_TFSL) >> BP_SSI_SSI_STCR_TFSL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TFSL.
#define BF_SSI_SSI_STCR_TFSL(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TFSL) & BM_SSI_SSI_STCR_TFSL)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TFSL.
#define BF_SSI_SSI_STCR_TFSL(v)   (((v) << BP_SSI_SSI_STCR_TFSL) & BM_SSI_SSI_STCR_TFSL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSL field to a new value.
#define BW_SSI_SSI_STCR_TFSL(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TFSL) | BF_SSI_SSI_STCR_TFSL(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TFSI[2] (RW)
 *
 * Transmit Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for
 * the transmit section of SSI.
 *
 * Values:
 * 0 - Transmit frame sync is active high.
 * 1 - Transmit frame sync is active low.
 */

#define BP_SSI_SSI_STCR_TFSI      (2)      //!< Bit position for SSI_SSI_STCR_TFSI.
#define BM_SSI_SSI_STCR_TFSI      (0x00000004)  //!< Bit mask for SSI_SSI_STCR_TFSI.

//! @brief Get value of SSI_SSI_STCR_TFSI from a register value.
#define BG_SSI_SSI_STCR_TFSI(r)   (((r) & BM_SSI_SSI_STCR_TFSI) >> BP_SSI_SSI_STCR_TFSI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TFSI.
#define BF_SSI_SSI_STCR_TFSI(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TFSI) & BM_SSI_SSI_STCR_TFSI)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TFSI.
#define BF_SSI_SSI_STCR_TFSI(v)   (((v) << BP_SSI_SSI_STCR_TFSI) & BM_SSI_SSI_STCR_TFSI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSI field to a new value.
#define BW_SSI_SSI_STCR_TFSI(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TFSI) | BF_SSI_SSI_STCR_TFSI(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TSCKP[3] (RW)
 *
 * Transmit Clock Polarity. This bit controls which bit clock edge is used to clock out data for the
 * transmit section. Note: TSCKP is 0 CLK_IST = 0; TSCKP is 1CLK_IST = 1
 *
 * Values:
 * 0 - Data clocked out on rising edge of bit clock.
 * 1 - Data clocked out on falling edge of bit clock.
 */

#define BP_SSI_SSI_STCR_TSCKP      (3)      //!< Bit position for SSI_SSI_STCR_TSCKP.
#define BM_SSI_SSI_STCR_TSCKP      (0x00000008)  //!< Bit mask for SSI_SSI_STCR_TSCKP.

//! @brief Get value of SSI_SSI_STCR_TSCKP from a register value.
#define BG_SSI_SSI_STCR_TSCKP(r)   (((r) & BM_SSI_SSI_STCR_TSCKP) >> BP_SSI_SSI_STCR_TSCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TSCKP.
#define BF_SSI_SSI_STCR_TSCKP(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TSCKP) & BM_SSI_SSI_STCR_TSCKP)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TSCKP.
#define BF_SSI_SSI_STCR_TSCKP(v)   (((v) << BP_SSI_SSI_STCR_TSCKP) & BM_SSI_SSI_STCR_TSCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSCKP field to a new value.
#define BW_SSI_SSI_STCR_TSCKP(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TSCKP) | BF_SSI_SSI_STCR_TSCKP(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TSHFD[4] (RW)
 *
 * Transmit Shift Direction. This bit controls whether the MSB or LSB will be transmitted first in a
 * sample. The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0.
 * Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (TSHFD cleared).
 *
 * Values:
 * 0 - Data transmitted MSB first.
 * 1 - Data transmitted LSB first.
 */

#define BP_SSI_SSI_STCR_TSHFD      (4)      //!< Bit position for SSI_SSI_STCR_TSHFD.
#define BM_SSI_SSI_STCR_TSHFD      (0x00000010)  //!< Bit mask for SSI_SSI_STCR_TSHFD.

//! @brief Get value of SSI_SSI_STCR_TSHFD from a register value.
#define BG_SSI_SSI_STCR_TSHFD(r)   (((r) & BM_SSI_SSI_STCR_TSHFD) >> BP_SSI_SSI_STCR_TSHFD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TSHFD.
#define BF_SSI_SSI_STCR_TSHFD(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TSHFD) & BM_SSI_SSI_STCR_TSHFD)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TSHFD.
#define BF_SSI_SSI_STCR_TSHFD(v)   (((v) << BP_SSI_SSI_STCR_TSHFD) & BM_SSI_SSI_STCR_TSHFD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSHFD field to a new value.
#define BW_SSI_SSI_STCR_TSHFD(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TSHFD) | BF_SSI_SSI_STCR_TSHFD(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TXDIR[5] (RW)
 *
 * Transmit Clock Direction. This bit controls the direction and source of the clock signal used to
 * clock the TXSR. Internally generated clock is output through the STCK port. External clock is
 * taken from this port. Refer to for details of clock pin configurations.
 *
 * Values:
 * 0 - Transmit Clock is external.
 * 1 - Transmit Clock generated internally.
 */

#define BP_SSI_SSI_STCR_TXDIR      (5)      //!< Bit position for SSI_SSI_STCR_TXDIR.
#define BM_SSI_SSI_STCR_TXDIR      (0x00000020)  //!< Bit mask for SSI_SSI_STCR_TXDIR.

//! @brief Get value of SSI_SSI_STCR_TXDIR from a register value.
#define BG_SSI_SSI_STCR_TXDIR(r)   (((r) & BM_SSI_SSI_STCR_TXDIR) >> BP_SSI_SSI_STCR_TXDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TXDIR.
#define BF_SSI_SSI_STCR_TXDIR(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TXDIR) & BM_SSI_SSI_STCR_TXDIR)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TXDIR.
#define BF_SSI_SSI_STCR_TXDIR(v)   (((v) << BP_SSI_SSI_STCR_TXDIR) & BM_SSI_SSI_STCR_TXDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXDIR field to a new value.
#define BW_SSI_SSI_STCR_TXDIR(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TXDIR) | BF_SSI_SSI_STCR_TXDIR(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TFDIR[6] (RW)
 *
 * Transmit Frame Direction. This bit controls the direction and source of the transmit frame sync
 * signal. Internally generated frame sync signal is sent out through the STFS port and external
 * frame sync is taken from the same port.
 *
 * Values:
 * 0 - Frame Sync is external.
 * 1 - Frame Sync generated internally.
 */

#define BP_SSI_SSI_STCR_TFDIR      (6)      //!< Bit position for SSI_SSI_STCR_TFDIR.
#define BM_SSI_SSI_STCR_TFDIR      (0x00000040)  //!< Bit mask for SSI_SSI_STCR_TFDIR.

//! @brief Get value of SSI_SSI_STCR_TFDIR from a register value.
#define BG_SSI_SSI_STCR_TFDIR(r)   (((r) & BM_SSI_SSI_STCR_TFDIR) >> BP_SSI_SSI_STCR_TFDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TFDIR.
#define BF_SSI_SSI_STCR_TFDIR(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TFDIR) & BM_SSI_SSI_STCR_TFDIR)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TFDIR.
#define BF_SSI_SSI_STCR_TFDIR(v)   (((v) << BP_SSI_SSI_STCR_TFDIR) & BM_SSI_SSI_STCR_TFDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFDIR field to a new value.
#define BW_SSI_SSI_STCR_TFDIR(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TFDIR) | BF_SSI_SSI_STCR_TFDIR(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TFEN0[7] (RW)
 *
 * Transmit FIFO Enable 0. This bit enables transmit FIFO 0. When enabled, the FIFO allows 8 15
 * samples to be transmitted by the SSI per channel (a 9th sample can be shifting out) before TDE0
 * bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is
 * transferred to the transmit shift register (provided the interrupt is enabled).
 *
 * Values:
 * 0 - Transmit FIFO 0 disabled.
 * 1 - Transmit FIFO 0 enabled.
 */

#define BP_SSI_SSI_STCR_TFEN0      (7)      //!< Bit position for SSI_SSI_STCR_TFEN0.
#define BM_SSI_SSI_STCR_TFEN0      (0x00000080)  //!< Bit mask for SSI_SSI_STCR_TFEN0.

//! @brief Get value of SSI_SSI_STCR_TFEN0 from a register value.
#define BG_SSI_SSI_STCR_TFEN0(r)   (((r) & BM_SSI_SSI_STCR_TFEN0) >> BP_SSI_SSI_STCR_TFEN0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TFEN0.
#define BF_SSI_SSI_STCR_TFEN0(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TFEN0) & BM_SSI_SSI_STCR_TFEN0)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TFEN0.
#define BF_SSI_SSI_STCR_TFEN0(v)   (((v) << BP_SSI_SSI_STCR_TFEN0) & BM_SSI_SSI_STCR_TFEN0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFEN0 field to a new value.
#define BW_SSI_SSI_STCR_TFEN0(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TFEN0) | BF_SSI_SSI_STCR_TFEN0(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TFEN1[8] (RW)
 *
 * Transmit FIFO Enable 1. This bit enables transmit FIFO 1. When enabled, the FIFO allows 8 15
 * samples to be transmitted by the SSI (per channel) (a 9th sample can be shifting out) before TDE1
 * bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is
 * transferred to the transmit shift register (provided the interrupt is enabled).
 *
 * Values:
 * 0 - Transmit FIFO 1 disabled.
 * 1 - Transmit FIFO 1 enabled.
 */

#define BP_SSI_SSI_STCR_TFEN1      (8)      //!< Bit position for SSI_SSI_STCR_TFEN1.
#define BM_SSI_SSI_STCR_TFEN1      (0x00000100)  //!< Bit mask for SSI_SSI_STCR_TFEN1.

//! @brief Get value of SSI_SSI_STCR_TFEN1 from a register value.
#define BG_SSI_SSI_STCR_TFEN1(r)   (((r) & BM_SSI_SSI_STCR_TFEN1) >> BP_SSI_SSI_STCR_TFEN1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TFEN1.
#define BF_SSI_SSI_STCR_TFEN1(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TFEN1) & BM_SSI_SSI_STCR_TFEN1)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TFEN1.
#define BF_SSI_SSI_STCR_TFEN1(v)   (((v) << BP_SSI_SSI_STCR_TFEN1) & BM_SSI_SSI_STCR_TFEN1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFEN1 field to a new value.
#define BW_SSI_SSI_STCR_TFEN1(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TFEN1) | BF_SSI_SSI_STCR_TFEN1(v)))
#endif


/* --- Register HW_SSI_SSI_STCR, field TXBIT0[9] (RW)
 *
 * Transmit Bit 0. This control bit allows SSI to transmit the data word from bit position 0 or
 * 15/31 in the transmit shift register. The shifting data direction can be MSB or LSB first,
 * controlled by the TSHFD bit.
 *
 * Values:
 * 0 - Shifting with respect to bit 31 (if word length = 16, 18, 20, 22 or 24) or bit 15 (if word length =
 *     8, 10 or 12) of transmit shift register (MSB aligned).
 * 1 - Shifting with respect to bit 0 of transmit shift register (LSB aligned).
 */

#define BP_SSI_SSI_STCR_TXBIT0      (9)      //!< Bit position for SSI_SSI_STCR_TXBIT0.
#define BM_SSI_SSI_STCR_TXBIT0      (0x00000200)  //!< Bit mask for SSI_SSI_STCR_TXBIT0.

//! @brief Get value of SSI_SSI_STCR_TXBIT0 from a register value.
#define BG_SSI_SSI_STCR_TXBIT0(r)   (((r) & BM_SSI_SSI_STCR_TXBIT0) >> BP_SSI_SSI_STCR_TXBIT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCR_TXBIT0.
#define BF_SSI_SSI_STCR_TXBIT0(v)   ((((reg32_t) v) << BP_SSI_SSI_STCR_TXBIT0) & BM_SSI_SSI_STCR_TXBIT0)
#else
//! @brief Format value for bitfield SSI_SSI_STCR_TXBIT0.
#define BF_SSI_SSI_STCR_TXBIT0(v)   (((v) << BP_SSI_SSI_STCR_TXBIT0) & BM_SSI_SSI_STCR_TXBIT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXBIT0 field to a new value.
#define BW_SSI_SSI_STCR_TXBIT0(x, v)   (HW_SSI_SSI_STCR_WR(x, (HW_SSI_SSI_STCR_RD(x) & ~BM_SSI_SSI_STCR_TXBIT0) | BF_SSI_SSI_STCR_TXBIT0(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SRCR - SSI Receive Configuration Register (RW)
 *
 * Reset value: 0x00000200
 *
 * The SSI Receive Configuration Register (SSI_SRCR) is a read/write control register used to direct
 * the receive operation of the SSI. SSI.SRCR controls the direction of the bit clock and frame sync
 * ports, SRCK and SRFS. Interrupt enable bit for the transmit sections is provided in this control
 * register. The Power-on reset clears all SSI_SRCR bits. However, SSI reset does not affect the
 * SSI_SRCR bits.
 */
typedef union _hw_ssi_ssi_srcr
{
    reg32_t U;
    struct _hw_ssi_ssi_srcr_bitfields
    {
        unsigned REFS : 1; //!< [0] Receive Early Frame Sync. This bit controls when the frame sync is initiated for the receive section. The frame sync is disabled after one bit-for-bit length frame sync and after one word-for-word length frame sync.
        unsigned RFSL : 1; //!< [1] Receive Frame Sync Length. This bit controls the length of the frame sync signal to be generated or recognized for the receive section. The length of a word-long frame sync is same as the length of the data word selected by WL[3:0].
        unsigned RFSI : 1; //!< [2] Receive Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for the receive section of SSI.
        unsigned RSCKP : 1; //!< [3] Receive Clock Polarity. This bit controls which bit clock edge is used to latch in data for the receive section.
        unsigned RSHFD : 1; //!< [4] Receive Shift Direction. This bit controls whether the MSB or LSB will be received first in a sample. The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0. Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (RSHFD cleared).
        unsigned RXDIR : 1; //!< [5] Receive Clock Direction. This bit controls the direction and source of the clock signal used to clock the RXSR. Internally generated clock is output through the SRCK port. External clock is taken from this port. Refer to for details on clock pin configurations.
        unsigned RFDIR : 1; //!< [6] Receive Frame Direction. This bit controls the direction and source of the receive frame sync signal. Internally generated frame sync signal is sent out through the SRFS port and external frame sync is taken from the same port.
        unsigned RFEN0 : 1; //!< [7] Receive FIFO Enable 0. This bit enables receive FIFO 0. When enabled, the FIFO allows 8 15 samples to be received by the SSI (per channel) (a 16th sample can be shifting in) before RDR0 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is received by the SSI (provided the interrupt is enabled).
        unsigned RFEN1 : 1; //!< [8] Receive FIFO Enable 1. This bit enables receive FIFO 1. When enabled, the FIFO allows 8 15 samples to be received by the SSI per channel (a 16th sample can be shifting in) before RDR1 bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is received by the SSI (provided the interrupt is enabled).
        unsigned RXBIT0 : 1; //!< [9] Receive Bit 0. This control bit allows SSI to receive the data word at bit position 0 or 15/31 in the receive shift register. The shifting data direction can be MSB or LSB first, controlled by the RSHFD bit.
        unsigned RXEXT : 1; //!< [10] Receive Data Extension. This control bit allows SSI to store the received data word in sign extended form. This bit affects data storage only in case received data is LSB aligned (SRCR[9]=1)
        unsigned RESERVED0 : 21; //!< [31:11] Reserved
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

/* --- Register HW_SSI_SSI_SRCR, field REFS[0] (RW)
 *
 * Receive Early Frame Sync. This bit controls when the frame sync is initiated for the receive
 * section. The frame sync is disabled after one bit-for-bit length frame sync and after one word-
 * for-word length frame sync.
 *
 * Values:
 * 0 - Receive frame sync initiated as the first bit of data is received.
 * 1 - Receive frame sync is initiated one bit before the data is received.
 */

#define BP_SSI_SSI_SRCR_REFS      (0)      //!< Bit position for SSI_SSI_SRCR_REFS.
#define BM_SSI_SSI_SRCR_REFS      (0x00000001)  //!< Bit mask for SSI_SSI_SRCR_REFS.

//! @brief Get value of SSI_SSI_SRCR_REFS from a register value.
#define BG_SSI_SSI_SRCR_REFS(r)   (((r) & BM_SSI_SSI_SRCR_REFS) >> BP_SSI_SSI_SRCR_REFS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_REFS.
#define BF_SSI_SSI_SRCR_REFS(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_REFS) & BM_SSI_SSI_SRCR_REFS)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_REFS.
#define BF_SSI_SSI_SRCR_REFS(v)   (((v) << BP_SSI_SSI_SRCR_REFS) & BM_SSI_SSI_SRCR_REFS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFS field to a new value.
#define BW_SSI_SSI_SRCR_REFS(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_REFS) | BF_SSI_SSI_SRCR_REFS(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RFSL[1] (RW)
 *
 * Receive Frame Sync Length. This bit controls the length of the frame sync signal to be generated
 * or recognized for the receive section. The length of a word-long frame sync is same as the length
 * of the data word selected by WL[3:0].
 *
 * Values:
 * 0 - Receive frame sync is one-word long.
 * 1 - Receive frame sync is one-clock-bit long.
 */

#define BP_SSI_SSI_SRCR_RFSL      (1)      //!< Bit position for SSI_SSI_SRCR_RFSL.
#define BM_SSI_SSI_SRCR_RFSL      (0x00000002)  //!< Bit mask for SSI_SSI_SRCR_RFSL.

//! @brief Get value of SSI_SSI_SRCR_RFSL from a register value.
#define BG_SSI_SSI_SRCR_RFSL(r)   (((r) & BM_SSI_SSI_SRCR_RFSL) >> BP_SSI_SSI_SRCR_RFSL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RFSL.
#define BF_SSI_SSI_SRCR_RFSL(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RFSL) & BM_SSI_SSI_SRCR_RFSL)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RFSL.
#define BF_SSI_SSI_SRCR_RFSL(v)   (((v) << BP_SSI_SSI_SRCR_RFSL) & BM_SSI_SSI_SRCR_RFSL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSL field to a new value.
#define BW_SSI_SSI_SRCR_RFSL(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RFSL) | BF_SSI_SSI_SRCR_RFSL(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RFSI[2] (RW)
 *
 * Receive Frame Sync Invert. This bit controls the active state of the frame sync I/O signal for
 * the receive section of SSI.
 *
 * Values:
 * 0 - Receive frame sync is active high.
 * 1 - Receive frame sync is active low.
 */

#define BP_SSI_SSI_SRCR_RFSI      (2)      //!< Bit position for SSI_SSI_SRCR_RFSI.
#define BM_SSI_SSI_SRCR_RFSI      (0x00000004)  //!< Bit mask for SSI_SSI_SRCR_RFSI.

//! @brief Get value of SSI_SSI_SRCR_RFSI from a register value.
#define BG_SSI_SSI_SRCR_RFSI(r)   (((r) & BM_SSI_SSI_SRCR_RFSI) >> BP_SSI_SSI_SRCR_RFSI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RFSI.
#define BF_SSI_SSI_SRCR_RFSI(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RFSI) & BM_SSI_SSI_SRCR_RFSI)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RFSI.
#define BF_SSI_SSI_SRCR_RFSI(v)   (((v) << BP_SSI_SSI_SRCR_RFSI) & BM_SSI_SSI_SRCR_RFSI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSI field to a new value.
#define BW_SSI_SSI_SRCR_RFSI(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RFSI) | BF_SSI_SSI_SRCR_RFSI(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RSCKP[3] (RW)
 *
 * Receive Clock Polarity. This bit controls which bit clock edge is used to latch in data for the
 * receive section.
 *
 * Values:
 * 0 - Data latched on falling edge of bit clock.
 * 1 - Data latched on rising edge of bit clock.
 */

#define BP_SSI_SSI_SRCR_RSCKP      (3)      //!< Bit position for SSI_SSI_SRCR_RSCKP.
#define BM_SSI_SSI_SRCR_RSCKP      (0x00000008)  //!< Bit mask for SSI_SSI_SRCR_RSCKP.

//! @brief Get value of SSI_SSI_SRCR_RSCKP from a register value.
#define BG_SSI_SSI_SRCR_RSCKP(r)   (((r) & BM_SSI_SSI_SRCR_RSCKP) >> BP_SSI_SSI_SRCR_RSCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RSCKP.
#define BF_SSI_SSI_SRCR_RSCKP(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RSCKP) & BM_SSI_SSI_SRCR_RSCKP)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RSCKP.
#define BF_SSI_SSI_SRCR_RSCKP(v)   (((v) << BP_SSI_SSI_SRCR_RSCKP) & BM_SSI_SSI_SRCR_RSCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSCKP field to a new value.
#define BW_SSI_SSI_SRCR_RSCKP(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RSCKP) | BF_SSI_SSI_SRCR_RSCKP(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RSHFD[4] (RW)
 *
 * Receive Shift Direction. This bit controls whether the MSB or LSB will be received first in a
 * sample. The CODEC device labels the MSB as bit 0, whereas the Core labels the LSB as bit 0.
 * Therefore, when using a standard CODEC, Core MSB (CODEC LSB) is shifted in first (RSHFD cleared).
 *
 * Values:
 * 0 - Data received MSB first.
 * 1 - Data received LSB first.
 */

#define BP_SSI_SSI_SRCR_RSHFD      (4)      //!< Bit position for SSI_SSI_SRCR_RSHFD.
#define BM_SSI_SSI_SRCR_RSHFD      (0x00000010)  //!< Bit mask for SSI_SSI_SRCR_RSHFD.

//! @brief Get value of SSI_SSI_SRCR_RSHFD from a register value.
#define BG_SSI_SSI_SRCR_RSHFD(r)   (((r) & BM_SSI_SSI_SRCR_RSHFD) >> BP_SSI_SSI_SRCR_RSHFD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RSHFD.
#define BF_SSI_SSI_SRCR_RSHFD(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RSHFD) & BM_SSI_SSI_SRCR_RSHFD)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RSHFD.
#define BF_SSI_SSI_SRCR_RSHFD(v)   (((v) << BP_SSI_SSI_SRCR_RSHFD) & BM_SSI_SSI_SRCR_RSHFD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSHFD field to a new value.
#define BW_SSI_SSI_SRCR_RSHFD(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RSHFD) | BF_SSI_SSI_SRCR_RSHFD(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RXDIR[5] (RW)
 *
 * Receive Clock Direction. This bit controls the direction and source of the clock signal used to
 * clock the RXSR. Internally generated clock is output through the SRCK port. External clock is
 * taken from this port. Refer to for details on clock pin configurations.
 *
 * Values:
 * 0 - Receive Clock is external.
 * 1 - Receive Clock generated internally.
 */

#define BP_SSI_SSI_SRCR_RXDIR      (5)      //!< Bit position for SSI_SSI_SRCR_RXDIR.
#define BM_SSI_SSI_SRCR_RXDIR      (0x00000020)  //!< Bit mask for SSI_SSI_SRCR_RXDIR.

//! @brief Get value of SSI_SSI_SRCR_RXDIR from a register value.
#define BG_SSI_SSI_SRCR_RXDIR(r)   (((r) & BM_SSI_SSI_SRCR_RXDIR) >> BP_SSI_SSI_SRCR_RXDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RXDIR.
#define BF_SSI_SSI_SRCR_RXDIR(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RXDIR) & BM_SSI_SSI_SRCR_RXDIR)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RXDIR.
#define BF_SSI_SSI_SRCR_RXDIR(v)   (((v) << BP_SSI_SSI_SRCR_RXDIR) & BM_SSI_SSI_SRCR_RXDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDIR field to a new value.
#define BW_SSI_SSI_SRCR_RXDIR(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RXDIR) | BF_SSI_SSI_SRCR_RXDIR(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RFDIR[6] (RW)
 *
 * Receive Frame Direction. This bit controls the direction and source of the receive frame sync
 * signal. Internally generated frame sync signal is sent out through the SRFS port and external
 * frame sync is taken from the same port.
 *
 * Values:
 * 0 - Frame Sync is external.
 * 1 - Frame Sync generated internally.
 */

#define BP_SSI_SSI_SRCR_RFDIR      (6)      //!< Bit position for SSI_SSI_SRCR_RFDIR.
#define BM_SSI_SSI_SRCR_RFDIR      (0x00000040)  //!< Bit mask for SSI_SSI_SRCR_RFDIR.

//! @brief Get value of SSI_SSI_SRCR_RFDIR from a register value.
#define BG_SSI_SSI_SRCR_RFDIR(r)   (((r) & BM_SSI_SSI_SRCR_RFDIR) >> BP_SSI_SSI_SRCR_RFDIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RFDIR.
#define BF_SSI_SSI_SRCR_RFDIR(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RFDIR) & BM_SSI_SSI_SRCR_RFDIR)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RFDIR.
#define BF_SSI_SSI_SRCR_RFDIR(v)   (((v) << BP_SSI_SSI_SRCR_RFDIR) & BM_SSI_SSI_SRCR_RFDIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFDIR field to a new value.
#define BW_SSI_SSI_SRCR_RFDIR(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RFDIR) | BF_SSI_SSI_SRCR_RFDIR(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RFEN0[7] (RW)
 *
 * Receive FIFO Enable 0. This bit enables receive FIFO 0. When enabled, the FIFO allows 8 15
 * samples to be received by the SSI (per channel) (a 16th sample can be shifting in) before RDR0
 * bit is set. When the FIFO is disabled, an interrupt is generated when a single sample is received
 * by the SSI (provided the interrupt is enabled).
 *
 * Values:
 * 0 - Receive FIFO 0 disabled.
 * 1 - Receive FIFO 0 enabled.
 */

#define BP_SSI_SSI_SRCR_RFEN0      (7)      //!< Bit position for SSI_SSI_SRCR_RFEN0.
#define BM_SSI_SSI_SRCR_RFEN0      (0x00000080)  //!< Bit mask for SSI_SSI_SRCR_RFEN0.

//! @brief Get value of SSI_SSI_SRCR_RFEN0 from a register value.
#define BG_SSI_SSI_SRCR_RFEN0(r)   (((r) & BM_SSI_SSI_SRCR_RFEN0) >> BP_SSI_SSI_SRCR_RFEN0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RFEN0.
#define BF_SSI_SSI_SRCR_RFEN0(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RFEN0) & BM_SSI_SSI_SRCR_RFEN0)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RFEN0.
#define BF_SSI_SSI_SRCR_RFEN0(v)   (((v) << BP_SSI_SSI_SRCR_RFEN0) & BM_SSI_SSI_SRCR_RFEN0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFEN0 field to a new value.
#define BW_SSI_SSI_SRCR_RFEN0(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RFEN0) | BF_SSI_SSI_SRCR_RFEN0(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RFEN1[8] (RW)
 *
 * Receive FIFO Enable 1. This bit enables receive FIFO 1. When enabled, the FIFO allows 8 15
 * samples to be received by the SSI per channel (a 16th sample can be shifting in) before RDR1 bit
 * is set. When the FIFO is disabled, an interrupt is generated when a single sample is received by
 * the SSI (provided the interrupt is enabled).
 *
 * Values:
 * 0 - Receive FIFO 1 disabled.
 * 1 - Receive FIFO 1 enabled.
 */

#define BP_SSI_SSI_SRCR_RFEN1      (8)      //!< Bit position for SSI_SSI_SRCR_RFEN1.
#define BM_SSI_SSI_SRCR_RFEN1      (0x00000100)  //!< Bit mask for SSI_SSI_SRCR_RFEN1.

//! @brief Get value of SSI_SSI_SRCR_RFEN1 from a register value.
#define BG_SSI_SSI_SRCR_RFEN1(r)   (((r) & BM_SSI_SSI_SRCR_RFEN1) >> BP_SSI_SSI_SRCR_RFEN1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RFEN1.
#define BF_SSI_SSI_SRCR_RFEN1(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RFEN1) & BM_SSI_SSI_SRCR_RFEN1)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RFEN1.
#define BF_SSI_SSI_SRCR_RFEN1(v)   (((v) << BP_SSI_SSI_SRCR_RFEN1) & BM_SSI_SSI_SRCR_RFEN1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFEN1 field to a new value.
#define BW_SSI_SSI_SRCR_RFEN1(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RFEN1) | BF_SSI_SSI_SRCR_RFEN1(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RXBIT0[9] (RW)
 *
 * Receive Bit 0. This control bit allows SSI to receive the data word at bit position 0 or 15/31 in
 * the receive shift register. The shifting data direction can be MSB or LSB first, controlled by
 * the RSHFD bit.
 *
 * Values:
 * 0 - Shifting with respect to bit 31 (if word length = 16, 18, 20, 22 or 24) or bit 15 (if word length =
 *     8, 10 or 12) of receive shift register (MSB aligned).
 * 1 - Shifting with respect to bit 0 of receive shift register (LSB aligned).
 */

#define BP_SSI_SSI_SRCR_RXBIT0      (9)      //!< Bit position for SSI_SSI_SRCR_RXBIT0.
#define BM_SSI_SSI_SRCR_RXBIT0      (0x00000200)  //!< Bit mask for SSI_SSI_SRCR_RXBIT0.

//! @brief Get value of SSI_SSI_SRCR_RXBIT0 from a register value.
#define BG_SSI_SSI_SRCR_RXBIT0(r)   (((r) & BM_SSI_SSI_SRCR_RXBIT0) >> BP_SSI_SSI_SRCR_RXBIT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RXBIT0.
#define BF_SSI_SSI_SRCR_RXBIT0(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RXBIT0) & BM_SSI_SSI_SRCR_RXBIT0)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RXBIT0.
#define BF_SSI_SSI_SRCR_RXBIT0(v)   (((v) << BP_SSI_SSI_SRCR_RXBIT0) & BM_SSI_SSI_SRCR_RXBIT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXBIT0 field to a new value.
#define BW_SSI_SSI_SRCR_RXBIT0(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RXBIT0) | BF_SSI_SSI_SRCR_RXBIT0(v)))
#endif


/* --- Register HW_SSI_SSI_SRCR, field RXEXT[10] (RW)
 *
 * Receive Data Extension. This control bit allows SSI to store the received data word in sign
 * extended form. This bit affects data storage only in case received data is LSB aligned
 * (SRCR[9]=1)
 *
 * Values:
 * 0 - Sign extension turned off.
 * 1 - Sign extension turned on.
 */

#define BP_SSI_SSI_SRCR_RXEXT      (10)      //!< Bit position for SSI_SSI_SRCR_RXEXT.
#define BM_SSI_SSI_SRCR_RXEXT      (0x00000400)  //!< Bit mask for SSI_SSI_SRCR_RXEXT.

//! @brief Get value of SSI_SSI_SRCR_RXEXT from a register value.
#define BG_SSI_SSI_SRCR_RXEXT(r)   (((r) & BM_SSI_SSI_SRCR_RXEXT) >> BP_SSI_SSI_SRCR_RXEXT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRCR_RXEXT.
#define BF_SSI_SSI_SRCR_RXEXT(v)   ((((reg32_t) v) << BP_SSI_SSI_SRCR_RXEXT) & BM_SSI_SSI_SRCR_RXEXT)
#else
//! @brief Format value for bitfield SSI_SSI_SRCR_RXEXT.
#define BF_SSI_SSI_SRCR_RXEXT(v)   (((v) << BP_SSI_SSI_SRCR_RXEXT) & BM_SSI_SSI_SRCR_RXEXT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXEXT field to a new value.
#define BW_SSI_SSI_SRCR_RXEXT(x, v)   (HW_SSI_SSI_SRCR_WR(x, (HW_SSI_SSI_SRCR_RD(x) & ~BM_SSI_SSI_SRCR_RXEXT) | BF_SSI_SSI_SRCR_RXEXT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_STCCR - SSI Transmit Clock Control Register (RW)
 *
 * Reset value: 0x00040000
 *
 * The SSI Transmit and Receive Control (SSI_STCCR and SSI_SRCCR) registers are 19-bit, read/write
 * control registers used to direct the operation of the SSI. The Clock Controller Module (CCM) can
 * source the SSI clock (SSI's sys clock-from CCM's ssi_clk_root ccm_ssi_clk ) from multiple sources
 * and perform fractional division to support commonly used audio bit rates. The CCM can maintain
 * the SSI's sys clock ccm_ssi_clk  (ccm_ssi_clk) frequency at a constant rate even in cases where
 * the ipg_clk (from CCM) peripheral clock frequency changes. These registers control the SSI clock
 * generator, bit and frame sync rates, word length, and number of words per frame for the serial
 * data. The SSI.STCCR register is dedicated to the transmit section, and the SSI_SRCCR register is
 * dedicated to the receive section except in Synchronous mode, in which the SSI_STCCR register
 * controls both the receive and transmit sections. Power-on reset clears all SSI_STCCR and
 * SSI_SRCCR bits. SSI reset does not affect the SSI_STCCR and SSI_SRCCR bits. The control bits are
 * described in the following paragraphs. Although the bit patterns of the SSI_STCCR and SSI_SRCCR
 * registers are the same, the contents of these two registers can be programmed differently.   SSI
 * Data Length            WL3    WL2    WL1    WL0    Number of Bits/Word    Supported in
 * Implementation        0    0    0    0    2    No      0    0    0    1    4    No      0    0
 * 1    0    6    No      0    0    1    1    8    Yes      0    1    0    0    10    Yes      0
 * 1    0    1    12    Yes      0    1    1    0    14    No      0    1    1    1    16    Yes
 * 1    0    0    0    18    Yes      1    0    0    1    20    Yes      1    0    1    0    22
 * Yes      1    0    1    1    24    Yes      1    1    0    0    26    No      1    1    0    1
 * 28    No      1    1    1    0    30    No      1    1    1    1    32    No
 */
typedef union _hw_ssi_ssi_stccr
{
    reg32_t U;
    struct _hw_ssi_ssi_stccr_bitfields
    {
        unsigned PM7_PM0 : 8; //!< [7:0] Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the clock port. A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be selected. Refer to for details regarding settings.
        unsigned DC4_DC0 : 5; //!< [12:8] Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio determines the word transfer rate. In Network mode, this ratio sets the number of words per frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode. In Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A bit-length frame sync must be used in this case. These bits can be programmed with values ranging from "00000" to "11111" to control the number of words in a frame.
        unsigned WL3_WL0 : 4; //!< [16:13] Word Length Control. These bits are used to control the length of the data words being transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI works with a fixed word length of 32, and the WL bits are used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than 16 bits, it will result in a word length of 20 bits. [table]
        unsigned PSR : 1; //!< [17] Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable prescaler. It extends the range of the prescaler for those cases where a slower bit clock is required. 0 Prescaler bypassed. 1 Prescaler used to divide clock by 8.
        unsigned DIV2 : 1; //!< [18] Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers. 0 Divider bypassed. 1 Divider used to divide clock by 2.
        unsigned RESERVED0 : 13; //!< [31:19] Reserved
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

/* --- Register HW_SSI_SSI_STCCR, field PM7_PM0[7:0] (RW)
 *
 * Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This
 * prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The
 * bit clock output is available at the clock port. A divide ratio from 1 to 256 (PM[7:0] = 0x00 to
 * 0xFF) can be selected. Refer to for details regarding settings.
 */

#define BP_SSI_SSI_STCCR_PM7_PM0      (0)      //!< Bit position for SSI_SSI_STCCR_PM7_PM0.
#define BM_SSI_SSI_STCCR_PM7_PM0      (0x000000ff)  //!< Bit mask for SSI_SSI_STCCR_PM7_PM0.

//! @brief Get value of SSI_SSI_STCCR_PM7_PM0 from a register value.
#define BG_SSI_SSI_STCCR_PM7_PM0(r)   (((r) & BM_SSI_SSI_STCCR_PM7_PM0) >> BP_SSI_SSI_STCCR_PM7_PM0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCCR_PM7_PM0.
#define BF_SSI_SSI_STCCR_PM7_PM0(v)   ((((reg32_t) v) << BP_SSI_SSI_STCCR_PM7_PM0) & BM_SSI_SSI_STCCR_PM7_PM0)
#else
//! @brief Format value for bitfield SSI_SSI_STCCR_PM7_PM0.
#define BF_SSI_SSI_STCCR_PM7_PM0(v)   (((v) << BP_SSI_SSI_STCCR_PM7_PM0) & BM_SSI_SSI_STCCR_PM7_PM0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PM7_PM0 field to a new value.
#define BW_SSI_SSI_STCCR_PM7_PM0(x, v)   (HW_SSI_SSI_STCCR_WR(x, (HW_SSI_SSI_STCCR_RD(x) & ~BM_SSI_SSI_STCCR_PM7_PM0) | BF_SSI_SSI_STCCR_PM7_PM0(v)))
#endif

/* --- Register HW_SSI_SSI_STCCR, field DC4_DC0[12:8] (RW)
 *
 * Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable
 * frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio
 * determines the word transfer rate. In Network mode, this ratio sets the number of words per
 * frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode. In
 * Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A
 * bit-length frame sync must be used in this case. These bits can be programmed with values ranging
 * from "00000" to "11111" to control the number of words in a frame.
 */

#define BP_SSI_SSI_STCCR_DC4_DC0      (8)      //!< Bit position for SSI_SSI_STCCR_DC4_DC0.
#define BM_SSI_SSI_STCCR_DC4_DC0      (0x00001f00)  //!< Bit mask for SSI_SSI_STCCR_DC4_DC0.

//! @brief Get value of SSI_SSI_STCCR_DC4_DC0 from a register value.
#define BG_SSI_SSI_STCCR_DC4_DC0(r)   (((r) & BM_SSI_SSI_STCCR_DC4_DC0) >> BP_SSI_SSI_STCCR_DC4_DC0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCCR_DC4_DC0.
#define BF_SSI_SSI_STCCR_DC4_DC0(v)   ((((reg32_t) v) << BP_SSI_SSI_STCCR_DC4_DC0) & BM_SSI_SSI_STCCR_DC4_DC0)
#else
//! @brief Format value for bitfield SSI_SSI_STCCR_DC4_DC0.
#define BF_SSI_SSI_STCCR_DC4_DC0(v)   (((v) << BP_SSI_SSI_STCCR_DC4_DC0) & BM_SSI_SSI_STCCR_DC4_DC0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DC4_DC0 field to a new value.
#define BW_SSI_SSI_STCCR_DC4_DC0(x, v)   (HW_SSI_SSI_STCCR_WR(x, (HW_SSI_SSI_STCCR_RD(x) & ~BM_SSI_SSI_STCCR_DC4_DC0) | BF_SSI_SSI_STCCR_DC4_DC0(v)))
#endif

/* --- Register HW_SSI_SSI_STCCR, field WL3_WL0[16:13] (RW)
 *
 * Word Length Control. These bits are used to control the length of the data words being
 * transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They
 * also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI
 * works with a fixed word length of 32, and the WL bits are used to control the amount of valid
 * data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than
 * 16 bits, it will result in a word length of 20 bits. [table]
 */

#define BP_SSI_SSI_STCCR_WL3_WL0      (13)      //!< Bit position for SSI_SSI_STCCR_WL3_WL0.
#define BM_SSI_SSI_STCCR_WL3_WL0      (0x0001e000)  //!< Bit mask for SSI_SSI_STCCR_WL3_WL0.

//! @brief Get value of SSI_SSI_STCCR_WL3_WL0 from a register value.
#define BG_SSI_SSI_STCCR_WL3_WL0(r)   (((r) & BM_SSI_SSI_STCCR_WL3_WL0) >> BP_SSI_SSI_STCCR_WL3_WL0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCCR_WL3_WL0.
#define BF_SSI_SSI_STCCR_WL3_WL0(v)   ((((reg32_t) v) << BP_SSI_SSI_STCCR_WL3_WL0) & BM_SSI_SSI_STCCR_WL3_WL0)
#else
//! @brief Format value for bitfield SSI_SSI_STCCR_WL3_WL0.
#define BF_SSI_SSI_STCCR_WL3_WL0(v)   (((v) << BP_SSI_SSI_STCCR_WL3_WL0) & BM_SSI_SSI_STCCR_WL3_WL0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WL3_WL0 field to a new value.
#define BW_SSI_SSI_STCCR_WL3_WL0(x, v)   (HW_SSI_SSI_STCCR_WR(x, (HW_SSI_SSI_STCCR_RD(x) & ~BM_SSI_SSI_STCCR_WL3_WL0) | BF_SSI_SSI_STCCR_WL3_WL0(v)))
#endif

/* --- Register HW_SSI_SSI_STCCR, field PSR[17] (RW)
 *
 * Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable
 * prescaler. It extends the range of the prescaler for those cases where a slower bit clock is
 * required. 0 Prescaler bypassed. 1 Prescaler used to divide clock by 8.
 */

#define BP_SSI_SSI_STCCR_PSR      (17)      //!< Bit position for SSI_SSI_STCCR_PSR.
#define BM_SSI_SSI_STCCR_PSR      (0x00020000)  //!< Bit mask for SSI_SSI_STCCR_PSR.

//! @brief Get value of SSI_SSI_STCCR_PSR from a register value.
#define BG_SSI_SSI_STCCR_PSR(r)   (((r) & BM_SSI_SSI_STCCR_PSR) >> BP_SSI_SSI_STCCR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCCR_PSR.
#define BF_SSI_SSI_STCCR_PSR(v)   ((((reg32_t) v) << BP_SSI_SSI_STCCR_PSR) & BM_SSI_SSI_STCCR_PSR)
#else
//! @brief Format value for bitfield SSI_SSI_STCCR_PSR.
#define BF_SSI_SSI_STCCR_PSR(v)   (((v) << BP_SSI_SSI_STCCR_PSR) & BM_SSI_SSI_STCCR_PSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_SSI_SSI_STCCR_PSR(x, v)   (HW_SSI_SSI_STCCR_WR(x, (HW_SSI_SSI_STCCR_RD(x) & ~BM_SSI_SSI_STCCR_PSR) | BF_SSI_SSI_STCCR_PSR(v)))
#endif

/* --- Register HW_SSI_SSI_STCCR, field DIV2[18] (RW)
 *
 * Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers.
 * 0 Divider bypassed. 1 Divider used to divide clock by 2.
 */

#define BP_SSI_SSI_STCCR_DIV2      (18)      //!< Bit position for SSI_SSI_STCCR_DIV2.
#define BM_SSI_SSI_STCCR_DIV2      (0x00040000)  //!< Bit mask for SSI_SSI_STCCR_DIV2.

//! @brief Get value of SSI_SSI_STCCR_DIV2 from a register value.
#define BG_SSI_SSI_STCCR_DIV2(r)   (((r) & BM_SSI_SSI_STCCR_DIV2) >> BP_SSI_SSI_STCCR_DIV2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STCCR_DIV2.
#define BF_SSI_SSI_STCCR_DIV2(v)   ((((reg32_t) v) << BP_SSI_SSI_STCCR_DIV2) & BM_SSI_SSI_STCCR_DIV2)
#else
//! @brief Format value for bitfield SSI_SSI_STCCR_DIV2.
#define BF_SSI_SSI_STCCR_DIV2(v)   (((v) << BP_SSI_SSI_STCCR_DIV2) & BM_SSI_SSI_STCCR_DIV2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV2 field to a new value.
#define BW_SSI_SSI_STCCR_DIV2(x, v)   (HW_SSI_SSI_STCCR_WR(x, (HW_SSI_SSI_STCCR_RD(x) & ~BM_SSI_SSI_STCCR_DIV2) | BF_SSI_SSI_STCCR_DIV2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SRCCR - SSI Receive Clock Control Register (RW)
 *
 * Reset value: 0x00040000
 *
 * The SSI Transmit and Receive Control (SSI_STCCR and SSI_SRCCR) registers are 19-bit, read/write
 * control registers used to direct the operation of the SSI. The Clock Controller Module (CCM) can
 * source the SSI clock (SSI's sys clock-from CCM's ssi_clk_root ccm_ssi_clk ) from multiple sources
 * and perform fractional division to support commonly used audio bit rates. The CCM can maintain
 * the SSI's sys clock ccm_ssi_clk  (ccm_ssi_clk) frequency at a constant rate even in cases where
 * the ipg_clk from CCM peripheral clock frequency changes. These registers control the SSI clock
 * generator, bit and frame sync rates, word length, and number of words per frame for the serial
 * data. The SSI_STCCR register is dedicated to the transmit section, and the SSI_SRCCR register is
 * dedicated to the receive section except in Synchronous mode, in which the SSI_STCCR register
 * controls both the receive and transmit sections. Power-on reset clears all SSI_STCCR and
 * SSI_SRCCR bits. SSI reset does not affect the SSI_STCCR and SSI_SRCCR bits. The control bits are
 * described in the following paragraphs. Although the bit patterns of the SSI_STCCR and SSI_SRCCR
 * registers are the same, the contents of these two registers can be programmed differently.   SSI
 * Data Length            WL3    WL2    WL1    WL0    Number of Bits/Word    Supported in
 * Implementation        0    0    0    0    2    No      0    0    0    1    4    No      0    0
 * 1    0    6    No      0    0    1    1    8    Yes      0    1    0    0    10    Yes      0
 * 1    0    1    12    Yes      0    1    1    0    14    No      0    1    1    1    16    Yes
 * 1    0    0    0    18    Yes      1    0    0    1    20    Yes      1    0    1    0    22
 * Yes      1    0    1    1    24    Yes      1    1    0    0    26    No      1    1    0    1
 * 28    No      1    1    1    0    30    No      1    1    1    1    32    No
 */
typedef union _hw_ssi_srccr
{
    reg32_t U;
    struct _hw_ssi_srccr_bitfields
    {
        unsigned PM7_PM0 : 8; //!< [7:0] Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The bit clock output is available at the clock port. A divide ratio from 1 to 256 (PM[7:0] = 0x00 to 0xFF) can be selected. Refer to for details regarding settings.
        unsigned DC4_DC0 : 5; //!< [12:8] Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio determines the word transfer rate. In Network mode, this ratio sets the number of words per frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode. In Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A bit-length frame sync must be used in this case. These bits can be programmed with values ranging from "00000" to "11111" to control the number of words in a frame.
        unsigned WL3_WL0 : 4; //!< [16:13] Word Length Control. These bits are used to control the length of the data words being transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI works with a fixed word length of 32, and the WL bits are used to control the amount of valid data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than 16 bits, it will result in a word length of 20 bits. [table]
        unsigned PSR : 1; //!< [17] Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable prescaler. It extends the range of the prescaler for those cases where a slower bit clock is required. 0 Prescaler bypassed. 1 Prescaler used to divide clock by 8.
        unsigned DIV2 : 1; //!< [18] Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers. 0 Divider bypassed. 1 Divider used to divide clock by 2.
        unsigned RESERVED0 : 13; //!< [31:19] Reserved
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

/* --- Register HW_SSI_SRCCR, field PM7_PM0[7:0] (RW)
 *
 * Prescaler Modulus Select. These bits control the prescale divider in the clock generator. This
 * prescaler is used only in Internal Clock mode to divide the internal clock (ccm_ssi_clk) . The
 * bit clock output is available at the clock port. A divide ratio from 1 to 256 (PM[7:0] = 0x00 to
 * 0xFF) can be selected. Refer to for details regarding settings.
 */

#define BP_SSI_SRCCR_PM7_PM0      (0)      //!< Bit position for SSI_SRCCR_PM7_PM0.
#define BM_SSI_SRCCR_PM7_PM0      (0x000000ff)  //!< Bit mask for SSI_SRCCR_PM7_PM0.

//! @brief Get value of SSI_SRCCR_PM7_PM0 from a register value.
#define BG_SSI_SRCCR_PM7_PM0(r)   (((r) & BM_SSI_SRCCR_PM7_PM0) >> BP_SSI_SRCCR_PM7_PM0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SRCCR_PM7_PM0.
#define BF_SSI_SRCCR_PM7_PM0(v)   ((((reg32_t) v) << BP_SSI_SRCCR_PM7_PM0) & BM_SSI_SRCCR_PM7_PM0)
#else
//! @brief Format value for bitfield SSI_SRCCR_PM7_PM0.
#define BF_SSI_SRCCR_PM7_PM0(v)   (((v) << BP_SSI_SRCCR_PM7_PM0) & BM_SSI_SRCCR_PM7_PM0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PM7_PM0 field to a new value.
#define BW_SSI_SRCCR_PM7_PM0(x, v)   (HW_SSI_SRCCR_WR(x, (HW_SSI_SRCCR_RD(x) & ~BM_SSI_SRCCR_PM7_PM0) | BF_SSI_SRCCR_PM7_PM0(v)))
#endif

/* --- Register HW_SSI_SRCCR, field DC4_DC0[12:8] (RW)
 *
 * Frame Rate Divider Control. These bits are used to control the divide ratio for the programmable
 * frame rate dividers. The divide ratio works on the word clock. In Normal mode, this ratio
 * determines the word transfer rate. In Network mode, this ratio sets the number of words per
 * frame. The divide ratio ranges from 1 to 32 in Normal mode and from 2 to 32 in Network mode. In
 * Normal mode, a divide ratio of 1 (DC=00000) provides continuous periodic data word transfer. A
 * bit-length frame sync must be used in this case. These bits can be programmed with values ranging
 * from "00000" to "11111" to control the number of words in a frame.
 */

#define BP_SSI_SRCCR_DC4_DC0      (8)      //!< Bit position for SSI_SRCCR_DC4_DC0.
#define BM_SSI_SRCCR_DC4_DC0      (0x00001f00)  //!< Bit mask for SSI_SRCCR_DC4_DC0.

//! @brief Get value of SSI_SRCCR_DC4_DC0 from a register value.
#define BG_SSI_SRCCR_DC4_DC0(r)   (((r) & BM_SSI_SRCCR_DC4_DC0) >> BP_SSI_SRCCR_DC4_DC0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SRCCR_DC4_DC0.
#define BF_SSI_SRCCR_DC4_DC0(v)   ((((reg32_t) v) << BP_SSI_SRCCR_DC4_DC0) & BM_SSI_SRCCR_DC4_DC0)
#else
//! @brief Format value for bitfield SSI_SRCCR_DC4_DC0.
#define BF_SSI_SRCCR_DC4_DC0(v)   (((v) << BP_SSI_SRCCR_DC4_DC0) & BM_SSI_SRCCR_DC4_DC0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DC4_DC0 field to a new value.
#define BW_SSI_SRCCR_DC4_DC0(x, v)   (HW_SSI_SRCCR_WR(x, (HW_SSI_SRCCR_RD(x) & ~BM_SSI_SRCCR_DC4_DC0) | BF_SSI_SRCCR_DC4_DC0(v)))
#endif

/* --- Register HW_SSI_SRCCR, field WL3_WL0[16:13] (RW)
 *
 * Word Length Control. These bits are used to control the length of the data words being
 * transferred by the SSI. These bits control the Word Length Divider in the Clock Generator. They
 * also control the frame sync pulse length when the FSL bit is cleared. In I2S Master mode, the SSI
 * works with a fixed word length of 32, and the WL bits are used to control the amount of valid
 * data in those 32 bits. In AC97 Mode of operation, if word length is set to any value other than
 * 16 bits, it will result in a word length of 20 bits. [table]
 */

#define BP_SSI_SRCCR_WL3_WL0      (13)      //!< Bit position for SSI_SRCCR_WL3_WL0.
#define BM_SSI_SRCCR_WL3_WL0      (0x0001e000)  //!< Bit mask for SSI_SRCCR_WL3_WL0.

//! @brief Get value of SSI_SRCCR_WL3_WL0 from a register value.
#define BG_SSI_SRCCR_WL3_WL0(r)   (((r) & BM_SSI_SRCCR_WL3_WL0) >> BP_SSI_SRCCR_WL3_WL0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SRCCR_WL3_WL0.
#define BF_SSI_SRCCR_WL3_WL0(v)   ((((reg32_t) v) << BP_SSI_SRCCR_WL3_WL0) & BM_SSI_SRCCR_WL3_WL0)
#else
//! @brief Format value for bitfield SSI_SRCCR_WL3_WL0.
#define BF_SSI_SRCCR_WL3_WL0(v)   (((v) << BP_SSI_SRCCR_WL3_WL0) & BM_SSI_SRCCR_WL3_WL0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WL3_WL0 field to a new value.
#define BW_SSI_SRCCR_WL3_WL0(x, v)   (HW_SSI_SRCCR_WR(x, (HW_SSI_SRCCR_RD(x) & ~BM_SSI_SRCCR_WL3_WL0) | BF_SSI_SRCCR_WL3_WL0(v)))
#endif

/* --- Register HW_SSI_SRCCR, field PSR[17] (RW)
 *
 * Prescaler Range. This bit controls a fixed divide-by-eight prescaler in series with the variable
 * prescaler. It extends the range of the prescaler for those cases where a slower bit clock is
 * required. 0 Prescaler bypassed. 1 Prescaler used to divide clock by 8.
 */

#define BP_SSI_SRCCR_PSR      (17)      //!< Bit position for SSI_SRCCR_PSR.
#define BM_SSI_SRCCR_PSR      (0x00020000)  //!< Bit mask for SSI_SRCCR_PSR.

//! @brief Get value of SSI_SRCCR_PSR from a register value.
#define BG_SSI_SRCCR_PSR(r)   (((r) & BM_SSI_SRCCR_PSR) >> BP_SSI_SRCCR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SRCCR_PSR.
#define BF_SSI_SRCCR_PSR(v)   ((((reg32_t) v) << BP_SSI_SRCCR_PSR) & BM_SSI_SRCCR_PSR)
#else
//! @brief Format value for bitfield SSI_SRCCR_PSR.
#define BF_SSI_SRCCR_PSR(v)   (((v) << BP_SSI_SRCCR_PSR) & BM_SSI_SRCCR_PSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_SSI_SRCCR_PSR(x, v)   (HW_SSI_SRCCR_WR(x, (HW_SSI_SRCCR_RD(x) & ~BM_SSI_SRCCR_PSR) | BF_SSI_SRCCR_PSR(v)))
#endif

/* --- Register HW_SSI_SRCCR, field DIV2[18] (RW)
 *
 * Divide By 2. This bit controls a divide-by-two divider in series with the rest of the prescalers.
 * 0 Divider bypassed. 1 Divider used to divide clock by 2.
 */

#define BP_SSI_SRCCR_DIV2      (18)      //!< Bit position for SSI_SRCCR_DIV2.
#define BM_SSI_SRCCR_DIV2      (0x00040000)  //!< Bit mask for SSI_SRCCR_DIV2.

//! @brief Get value of SSI_SRCCR_DIV2 from a register value.
#define BG_SSI_SRCCR_DIV2(r)   (((r) & BM_SSI_SRCCR_DIV2) >> BP_SSI_SRCCR_DIV2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SRCCR_DIV2.
#define BF_SSI_SRCCR_DIV2(v)   ((((reg32_t) v) << BP_SSI_SRCCR_DIV2) & BM_SSI_SRCCR_DIV2)
#else
//! @brief Format value for bitfield SSI_SRCCR_DIV2.
#define BF_SSI_SRCCR_DIV2(v)   (((v) << BP_SSI_SRCCR_DIV2) & BM_SSI_SRCCR_DIV2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV2 field to a new value.
#define BW_SSI_SRCCR_DIV2(x, v)   (HW_SSI_SRCCR_WR(x, (HW_SSI_SRCCR_RD(x) & ~BM_SSI_SRCCR_DIV2) | BF_SSI_SRCCR_DIV2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SFCSR - SSI FIFO Control/Status Register (RW)
 *
 * Reset value: 0x00810081
 *
 * The SSI FIFO Control / Status Register indicates the status of the Transmit FIFO Empty flag, with
 * different settings of the Transmit FIFO WaterMark bits and varying amounts of data in the Tx FIFO
 * .   Status of Transmit FIFO Empty Flag               Transmit FIFO Watermark (TFWM)    Number of
 * data in Tx-Fifo      1    2    3    4    5    6    7    8        1    1    1    1    1    1    1
 * 1    0      2    1    1    1    1    1    1    0    0      3    1    1    1    1    1    0    0
 * 0      4    1    1    1    1    0    0    0    0      5    1    1    1    0    0    0    0    0
 * 6    1    1    0    0    0    0    0    0      7    1    0    0    0    0    0    0    0      8
 * 0    0    0    0    0    0    0    0        Status of Transmit FIFO Empty Flag
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
typedef union _hw_ssi_ssi_sfcsr
{
    reg32_t U;
    struct _hw_ssi_ssi_sfcsr_bitfields
    {
        unsigned TFWM0 : 4; //!< [3:0] Transmit FIFO Empty WaterMark 0. These bits control the threshold at which the TFE0 flag will be set. The TFE0 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected threshold. See SSI_SFCSR_bf4 for details regarding settings for transmit FIFO watermark bits.
        unsigned RFWM0 : 4; //!< [7:4] Receive FIFO Full WaterMark 0. These bits control the threshold at which the RFF0 flag will be set. The RFF0 flag is set whenever the data level in Rx FIFO 0 reaches the selected threshold. See SSI_SFCSR_bf3 for details regarding settings for receive FIFO watermark bits.
        unsigned TFCNT0 : 4; //!< [11:8] Transmit FIFO Counter 0. These bits indicate the number of data words in Transmit FIFO 0. See SSI_SFCSR_bf2 for details regarding settings for transmit FIFO counter bits.
        unsigned RFCNT0 : 4; //!< [15:12] Receive FIFO Counter 0. These bits indicate the number of data words in Receive FIFO 0. See SSI_SFCSR_bf1 for details regarding settings for receive FIFO counter bits.
        unsigned TFWM1 : 4; //!< [19:16] Transmit FIFO Empty WaterMark 1. These bits control the threshold at which the TFE1 flag will be set. The TFE1 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected threshold.
        unsigned RFWM1 : 4; //!< [23:20] Receive FIFO Full WaterMark 1. These bits control the threshold at which the RFF1 flag will be set. The RFF1 flag is set whenever the data level in Rx FIFO 1 reaches the selected threshold.
        unsigned TFCNT1 : 4; //!< [27:24] Transmit FIFO Counter1. These bits indicate the number of data words in Transmit FIFO.
        unsigned RFCNT1 : 4; //!< [31:28] Receive FIFO Counter1. These bits indicate the number of data words in Receive FIFO 1.
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

/* --- Register HW_SSI_SSI_SFCSR, field TFWM0[3:0] (RW)
 *
 * Transmit FIFO Empty WaterMark 0. These bits control the threshold at which the TFE0 flag will be
 * set. The TFE0 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected
 * threshold. See SSI_SFCSR_bf4 for details regarding settings for transmit FIFO watermark bits.
 */

#define BP_SSI_SSI_SFCSR_TFWM0      (0)      //!< Bit position for SSI_SSI_SFCSR_TFWM0.
#define BM_SSI_SSI_SFCSR_TFWM0      (0x0000000f)  //!< Bit mask for SSI_SSI_SFCSR_TFWM0.

//! @brief Get value of SSI_SSI_SFCSR_TFWM0 from a register value.
#define BG_SSI_SSI_SFCSR_TFWM0(r)   (((r) & BM_SSI_SSI_SFCSR_TFWM0) >> BP_SSI_SSI_SFCSR_TFWM0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFWM0.
#define BF_SSI_SSI_SFCSR_TFWM0(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_TFWM0) & BM_SSI_SSI_SFCSR_TFWM0)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFWM0.
#define BF_SSI_SSI_SFCSR_TFWM0(v)   (((v) << BP_SSI_SSI_SFCSR_TFWM0) & BM_SSI_SSI_SFCSR_TFWM0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFWM0 field to a new value.
#define BW_SSI_SSI_SFCSR_TFWM0(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_TFWM0) | BF_SSI_SSI_SFCSR_TFWM0(v)))
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFWM0[7:4] (RW)
 *
 * Receive FIFO Full WaterMark 0. These bits control the threshold at which the RFF0 flag will be
 * set. The RFF0 flag is set whenever the data level in Rx FIFO 0 reaches the selected threshold.
 * See SSI_SFCSR_bf3 for details regarding settings for receive FIFO watermark bits.
 */

#define BP_SSI_SSI_SFCSR_RFWM0      (4)      //!< Bit position for SSI_SSI_SFCSR_RFWM0.
#define BM_SSI_SSI_SFCSR_RFWM0      (0x000000f0)  //!< Bit mask for SSI_SSI_SFCSR_RFWM0.

//! @brief Get value of SSI_SSI_SFCSR_RFWM0 from a register value.
#define BG_SSI_SSI_SFCSR_RFWM0(r)   (((r) & BM_SSI_SSI_SFCSR_RFWM0) >> BP_SSI_SSI_SFCSR_RFWM0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFWM0.
#define BF_SSI_SSI_SFCSR_RFWM0(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_RFWM0) & BM_SSI_SSI_SFCSR_RFWM0)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFWM0.
#define BF_SSI_SSI_SFCSR_RFWM0(v)   (((v) << BP_SSI_SSI_SFCSR_RFWM0) & BM_SSI_SSI_SFCSR_RFWM0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFWM0 field to a new value.
#define BW_SSI_SSI_SFCSR_RFWM0(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_RFWM0) | BF_SSI_SSI_SFCSR_RFWM0(v)))
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFCNT0[11:8] (RW)
 *
 * Transmit FIFO Counter 0. These bits indicate the number of data words in Transmit FIFO 0. See
 * SSI_SFCSR_bf2 for details regarding settings for transmit FIFO counter bits.
 */

#define BP_SSI_SSI_SFCSR_TFCNT0      (8)      //!< Bit position for SSI_SSI_SFCSR_TFCNT0.
#define BM_SSI_SSI_SFCSR_TFCNT0      (0x00000f00)  //!< Bit mask for SSI_SSI_SFCSR_TFCNT0.

//! @brief Get value of SSI_SSI_SFCSR_TFCNT0 from a register value.
#define BG_SSI_SSI_SFCSR_TFCNT0(r)   (((r) & BM_SSI_SSI_SFCSR_TFCNT0) >> BP_SSI_SSI_SFCSR_TFCNT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFCNT0.
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_TFCNT0) & BM_SSI_SSI_SFCSR_TFCNT0)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFCNT0.
#define BF_SSI_SSI_SFCSR_TFCNT0(v)   (((v) << BP_SSI_SSI_SFCSR_TFCNT0) & BM_SSI_SSI_SFCSR_TFCNT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFCNT0 field to a new value.
#define BW_SSI_SSI_SFCSR_TFCNT0(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_TFCNT0) | BF_SSI_SSI_SFCSR_TFCNT0(v)))
#endif

/* --- Register HW_SSI_SSI_SFCSR, field RFCNT0[15:12] (RW)
 *
 * Receive FIFO Counter 0. These bits indicate the number of data words in Receive FIFO 0. See
 * SSI_SFCSR_bf1 for details regarding settings for receive FIFO counter bits.
 */

#define BP_SSI_SSI_SFCSR_RFCNT0      (12)      //!< Bit position for SSI_SSI_SFCSR_RFCNT0.
#define BM_SSI_SSI_SFCSR_RFCNT0      (0x0000f000)  //!< Bit mask for SSI_SSI_SFCSR_RFCNT0.

//! @brief Get value of SSI_SSI_SFCSR_RFCNT0 from a register value.
#define BG_SSI_SSI_SFCSR_RFCNT0(r)   (((r) & BM_SSI_SSI_SFCSR_RFCNT0) >> BP_SSI_SSI_SFCSR_RFCNT0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFCNT0.
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_RFCNT0) & BM_SSI_SSI_SFCSR_RFCNT0)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFCNT0.
#define BF_SSI_SSI_SFCSR_RFCNT0(v)   (((v) << BP_SSI_SSI_SFCSR_RFCNT0) & BM_SSI_SSI_SFCSR_RFCNT0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFCNT0 field to a new value.
#define BW_SSI_SSI_SFCSR_RFCNT0(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_RFCNT0) | BF_SSI_SSI_SFCSR_RFCNT0(v)))
#endif

/* --- Register HW_SSI_SSI_SFCSR, field TFWM1[19:16] (RW)
 *
 * Transmit FIFO Empty WaterMark 1. These bits control the threshold at which the TFE1 flag will be
 * set. The TFE1 flag is set whenever the empty slots in Tx FIFO exceed or are equal to the selected
 * threshold.
 *
 * Values:
 * 0000 - Reserved
 * 0001 - TFE set when there are more than or equal to 1 empty slots in Transmit FIFO (default). Transmit FIFO
 *     empty is set when TxFIFO <= 7 14 data.
 * 0010 - TFE set when there are more than or equal to 2 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 6 13 data.
 * 0011 - TFE set when there are more than or equal to 3 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 5 12 data.
 * 0100 - TFE set when there are more than or equal to 4 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 4 11 data.
 * 0101 - TFE set when there are more than or equal to 5 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 3 10 data.
 * 0110 - TFE set when there are more than or equal to 6 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 2 9 data.
 * 0111 - TFE set when there are more than or equal to 7 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 1 8 data.
 * 1000 - TFE set when there are more than or equal to 8 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 0 7 data.
 * 1001 - TFE set when there are more than or equal to 9 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 6 data.
 * 1010 - TFE set when there are more than or equal to 10 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 5 data.
 * 1011 - TFE set when there are more than or equal to 11 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 4 data.
 * 1100 - TFE set when there are more than or equal to 12 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 3 data.
 * 1101 - TFE set when there are more than or equal to 13 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 2 data.
 * 1110 - TFE set when there are more than or equal to 14 empty slots in Transmit FIFO. Transmit FIFO empty is
 *     set when TxFIFO <= 1 data.
 * 1111 - TFE set when there are 15 empty slots in Transmit FIFO. Transmit FIFO empty is set when TxFIFO = 0
 *     data.
 */

#define BP_SSI_SSI_SFCSR_TFWM1      (16)      //!< Bit position for SSI_SSI_SFCSR_TFWM1.
#define BM_SSI_SSI_SFCSR_TFWM1      (0x000f0000)  //!< Bit mask for SSI_SSI_SFCSR_TFWM1.

//! @brief Get value of SSI_SSI_SFCSR_TFWM1 from a register value.
#define BG_SSI_SSI_SFCSR_TFWM1(r)   (((r) & BM_SSI_SSI_SFCSR_TFWM1) >> BP_SSI_SSI_SFCSR_TFWM1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFWM1.
#define BF_SSI_SSI_SFCSR_TFWM1(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_TFWM1) & BM_SSI_SSI_SFCSR_TFWM1)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFWM1.
#define BF_SSI_SSI_SFCSR_TFWM1(v)   (((v) << BP_SSI_SSI_SFCSR_TFWM1) & BM_SSI_SSI_SFCSR_TFWM1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFWM1 field to a new value.
#define BW_SSI_SSI_SFCSR_TFWM1(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_TFWM1) | BF_SSI_SSI_SFCSR_TFWM1(v)))
#endif


/* --- Register HW_SSI_SSI_SFCSR, field RFWM1[23:20] (RW)
 *
 * Receive FIFO Full WaterMark 1. These bits control the threshold at which the RFF1 flag will be
 * set. The RFF1 flag is set whenever the data level in Rx FIFO 1 reaches the selected threshold.
 *
 * Values:
 * 0000 - Reserved
 * 0001 - RFF set when at least one data word has been written to the Receive FIFO. Set when RxFIFO = 1,2.....
 *     8 15 data words
 * 0010 - RFF set when 2 or more data words have been written to the Receive FIFO. Set when RxFIFO = 2,3.....
 *     8 15 data words
 * 0011 - RFF set when 3 or more data words have been written to the Receive FIFO. Set when RxFIFO = 3,4.....
 *     8 15 data words
 * 0100 - RFF set when 4 or more data words have been written to the Receive FIFO. Set when RxFIFO = 4,5.....
 *     8 15 data words
 * 0101 - RFF set when 5 or more data words have been written to the Receive FIFO. Set when RxFIFO = 5,6.....
 *     8 15 data words
 * 0110 - RFF set when 6 or more data words have been written to the Receive.. Set when RxFIFO = 6,7 ,8
 *     ......15 data words
 * 0111 - RFF set when 7 or more data words have been written to the Receive FIFO. Set when RxFIFO = 7,8
 *     ......15 data words
 * 1000 - RFF set when 8 or more data words have been written to the Receive FIFO. Set when RxFIFO = 8,9.....
 *     8 15 data words
 * 1001 - RFF set when 9 or more data words have been written to the Receive FIFO. Set when RxFIFO =
 *     9,10.....15 data words
 * 1010 - RFF set when 10 or more data words have been written to the Receive FIFO. Set when RxFIFO =
 *     10,11.....15 data words
 * 1011 - RFF set when 11 or more data words have been written to the Receive FIFO. Set when RxFIFO =
 *     11,12.....15 data words
 * 1100 - RFF set when 12 or more data words have been written to the Receive FIFO. Set when RxFIFO =
 *     12,13.....15 data words
 * 1101 - RFF set when 13 or more data words have been written to the Receive FIFO. Set when RxFIFO =
 *     13,14,15data words
 * 1110 - RFF set when 14 or more data words have been written to the Receive FIFO. Set when RxFIFO = 14,15
 *     data words
 * 1111 - RFF set when 15 data words have been written to the Receive FIFO (default). Set when RxFIFO = 15
 *     data words
 */

#define BP_SSI_SSI_SFCSR_RFWM1      (20)      //!< Bit position for SSI_SSI_SFCSR_RFWM1.
#define BM_SSI_SSI_SFCSR_RFWM1      (0x00f00000)  //!< Bit mask for SSI_SSI_SFCSR_RFWM1.

//! @brief Get value of SSI_SSI_SFCSR_RFWM1 from a register value.
#define BG_SSI_SSI_SFCSR_RFWM1(r)   (((r) & BM_SSI_SSI_SFCSR_RFWM1) >> BP_SSI_SSI_SFCSR_RFWM1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFWM1.
#define BF_SSI_SSI_SFCSR_RFWM1(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_RFWM1) & BM_SSI_SSI_SFCSR_RFWM1)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFWM1.
#define BF_SSI_SSI_SFCSR_RFWM1(v)   (((v) << BP_SSI_SSI_SFCSR_RFWM1) & BM_SSI_SSI_SFCSR_RFWM1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFWM1 field to a new value.
#define BW_SSI_SSI_SFCSR_RFWM1(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_RFWM1) | BF_SSI_SSI_SFCSR_RFWM1(v)))
#endif


/* --- Register HW_SSI_SSI_SFCSR, field TFCNT1[27:24] (RW)
 *
 * Transmit FIFO Counter1. These bits indicate the number of data words in Transmit FIFO.
 *
 * Values:
 * 0000 - 0 data word in transmit FIFO
 * 0001 - 1 data word in transmit FIFO
 * 0010 - 2 data word in transmit FIFO
 * 0011 - 3 data word in transmit FIFO
 * 0100 - 4 data word in transmit FIFO
 * 0101 - 5 data word in transmit FIFO
 * 0110 - 6 data word in transmit FIFO
 * 0111 - 7 data word in transmit FIFO
 * 1000 - 8 data word in transmit FIFO
 * 1001 - 9 data word in transmit FIFO
 * 1010 - 10 data word in transmit FIFO
 * 1011 - 11 data word in transmit FIFO
 * 1100 - 12 data word in transmit FIFO
 * 1101 - 13 data word in transmit FIFO
 * 1110 - 14 data word in transmit FIFO
 * 1111 - 15 data word in transmit FIFO
 */

#define BP_SSI_SSI_SFCSR_TFCNT1      (24)      //!< Bit position for SSI_SSI_SFCSR_TFCNT1.
#define BM_SSI_SSI_SFCSR_TFCNT1      (0x0f000000)  //!< Bit mask for SSI_SSI_SFCSR_TFCNT1.

//! @brief Get value of SSI_SSI_SFCSR_TFCNT1 from a register value.
#define BG_SSI_SSI_SFCSR_TFCNT1(r)   (((r) & BM_SSI_SSI_SFCSR_TFCNT1) >> BP_SSI_SSI_SFCSR_TFCNT1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFCNT1.
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_TFCNT1) & BM_SSI_SSI_SFCSR_TFCNT1)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_TFCNT1.
#define BF_SSI_SSI_SFCSR_TFCNT1(v)   (((v) << BP_SSI_SSI_SFCSR_TFCNT1) & BM_SSI_SSI_SFCSR_TFCNT1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFCNT1 field to a new value.
#define BW_SSI_SSI_SFCSR_TFCNT1(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_TFCNT1) | BF_SSI_SSI_SFCSR_TFCNT1(v)))
#endif


/* --- Register HW_SSI_SSI_SFCSR, field RFCNT1[31:28] (RW)
 *
 * Receive FIFO Counter1. These bits indicate the number of data words in Receive FIFO 1.
 *
 * Values:
 * 0000 - 0 data word in receive FIFO
 * 0001 - 1 data word in receive FIFO
 * 0010 - 2 data word in receive FIFO
 * 0011 - 3 data word in receive FIFO
 * 0100 - 4 data word in receive FIFO
 * 0101 - 5 data word in receive FIFO
 * 0110 - 6 data word in receive FIFO
 * 0111 - 7 data word in receive FIFO
 * 1000 - 8 data word in receive FIFO
 * 1001 - 9 data word in receive FIFO
 * 1010 - 10 data word in receive FIFO
 * 1011 - 11 data word in receive FIFO
 * 1100 - 12 data word in receive FIFO
 * 1101 - 13 data word in receive FIFO
 * 1110 - 14 data word in receive FIFO
 * 1111 - 15 data word in receive FIFO
 */

#define BP_SSI_SSI_SFCSR_RFCNT1      (28)      //!< Bit position for SSI_SSI_SFCSR_RFCNT1.
#define BM_SSI_SSI_SFCSR_RFCNT1      (0xf0000000)  //!< Bit mask for SSI_SSI_SFCSR_RFCNT1.

//! @brief Get value of SSI_SSI_SFCSR_RFCNT1 from a register value.
#define BG_SSI_SSI_SFCSR_RFCNT1(r)   (((r) & BM_SSI_SSI_SFCSR_RFCNT1) >> BP_SSI_SSI_SFCSR_RFCNT1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFCNT1.
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   ((((reg32_t) v) << BP_SSI_SSI_SFCSR_RFCNT1) & BM_SSI_SSI_SFCSR_RFCNT1)
#else
//! @brief Format value for bitfield SSI_SSI_SFCSR_RFCNT1.
#define BF_SSI_SSI_SFCSR_RFCNT1(v)   (((v) << BP_SSI_SSI_SFCSR_RFCNT1) & BM_SSI_SSI_SFCSR_RFCNT1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFCNT1 field to a new value.
#define BW_SSI_SSI_SFCSR_RFCNT1(x, v)   (HW_SSI_SSI_SFCSR_WR(x, (HW_SSI_SSI_SFCSR_RD(x) & ~BM_SSI_SSI_SFCSR_RFCNT1) | BF_SSI_SSI_SFCSR_RFCNT1(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACNT - SSI AC97 Control Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_sacnt
{
    reg32_t U;
    struct _hw_ssi_ssi_sacnt_bitfields
    {
        unsigned AC97EN : 1; //!< [0] AC97 Mode Enable. This bit is used to enable SSI AC97 operation. Refer to for details of AC97 operation.
        unsigned FV : 1; //!< [1] Fixed/Variable Operation. This bit selects whether the SSI is in AC97 Fixed mode or AC97 Variable mode.
        unsigned TIF : 1; //!< [2] Tag in FIFO. This bit controls the destination of the information received in AC97 tag slot (Slot #0).
        unsigned RD : 1; //!< [3] Read Command. This bit specifies whether the next frame will carry an AC97 Read Command or not. The programmer should take care that only one of the bits (WR or RD) is set at a time. When this bit is set, the corresponding tag bit (corresponding to Command Address slot of the next Tx frame) is automatically set. This bit is automatically cleared by the SSI after completing transmission of a frame.
        unsigned WR : 1; //!< [4] Write Command. This bit specifies whether the next frame will carry an AC97 Write Command or not. The programmer should take care that only one of the bits (WR or RD) is set at a time. When this bit is set, the corresponding tag bits (corresponding to Command Address and Command Data slots of the next Tx frame) are automatically set. This bit is automatically cleared by the SSI after completing transmission of a frame.
        unsigned FRDIV : 6; //!< [10:5] Frame Rate Divider. These bits control the frequency of AC97 data transmission/reception. They are programmed with the number of frames for which the SSI should be idle, after operating in one frame. Through these bits, AC97 frequency of operation, from 48 KHz (000000) to 1 KHz (101111) can be achieved. Sample Value: 001010 (10 Decimal) = SSI will operate once every 11 frames.
        unsigned RESERVED0 : 21; //!< [31:11] Reserved
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

/* --- Register HW_SSI_SSI_SACNT, field AC97EN[0] (RW)
 *
 * AC97 Mode Enable. This bit is used to enable SSI AC97 operation. Refer to for details of AC97
 * operation.
 *
 * Values:
 * 0 - AC97 mode disabled.
 * 1 - SSI in AC97 mode.
 */

#define BP_SSI_SSI_SACNT_AC97EN      (0)      //!< Bit position for SSI_SSI_SACNT_AC97EN.
#define BM_SSI_SSI_SACNT_AC97EN      (0x00000001)  //!< Bit mask for SSI_SSI_SACNT_AC97EN.

//! @brief Get value of SSI_SSI_SACNT_AC97EN from a register value.
#define BG_SSI_SSI_SACNT_AC97EN(r)   (((r) & BM_SSI_SSI_SACNT_AC97EN) >> BP_SSI_SSI_SACNT_AC97EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_AC97EN.
#define BF_SSI_SSI_SACNT_AC97EN(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_AC97EN) & BM_SSI_SSI_SACNT_AC97EN)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_AC97EN.
#define BF_SSI_SSI_SACNT_AC97EN(v)   (((v) << BP_SSI_SSI_SACNT_AC97EN) & BM_SSI_SSI_SACNT_AC97EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AC97EN field to a new value.
#define BW_SSI_SSI_SACNT_AC97EN(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_AC97EN) | BF_SSI_SSI_SACNT_AC97EN(v)))
#endif


/* --- Register HW_SSI_SSI_SACNT, field FV[1] (RW)
 *
 * Fixed/Variable Operation. This bit selects whether the SSI is in AC97 Fixed mode or AC97 Variable
 * mode.
 *
 * Values:
 * 0 - AC97 Fixed Mode.
 * 1 - AC97 Variable Mode.
 */

#define BP_SSI_SSI_SACNT_FV      (1)      //!< Bit position for SSI_SSI_SACNT_FV.
#define BM_SSI_SSI_SACNT_FV      (0x00000002)  //!< Bit mask for SSI_SSI_SACNT_FV.

//! @brief Get value of SSI_SSI_SACNT_FV from a register value.
#define BG_SSI_SSI_SACNT_FV(r)   (((r) & BM_SSI_SSI_SACNT_FV) >> BP_SSI_SSI_SACNT_FV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_FV.
#define BF_SSI_SSI_SACNT_FV(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_FV) & BM_SSI_SSI_SACNT_FV)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_FV.
#define BF_SSI_SSI_SACNT_FV(v)   (((v) << BP_SSI_SSI_SACNT_FV) & BM_SSI_SSI_SACNT_FV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FV field to a new value.
#define BW_SSI_SSI_SACNT_FV(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_FV) | BF_SSI_SSI_SACNT_FV(v)))
#endif


/* --- Register HW_SSI_SSI_SACNT, field TIF[2] (RW)
 *
 * Tag in FIFO. This bit controls the destination of the information received in AC97 tag slot (Slot
 * #0).
 *
 * Values:
 * 0 - Tag info stored in SATAG register.
 * 1 - Tag info stored in Rx FIFO 0.
 */

#define BP_SSI_SSI_SACNT_TIF      (2)      //!< Bit position for SSI_SSI_SACNT_TIF.
#define BM_SSI_SSI_SACNT_TIF      (0x00000004)  //!< Bit mask for SSI_SSI_SACNT_TIF.

//! @brief Get value of SSI_SSI_SACNT_TIF from a register value.
#define BG_SSI_SSI_SACNT_TIF(r)   (((r) & BM_SSI_SSI_SACNT_TIF) >> BP_SSI_SSI_SACNT_TIF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_TIF.
#define BF_SSI_SSI_SACNT_TIF(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_TIF) & BM_SSI_SSI_SACNT_TIF)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_TIF.
#define BF_SSI_SSI_SACNT_TIF(v)   (((v) << BP_SSI_SSI_SACNT_TIF) & BM_SSI_SSI_SACNT_TIF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIF field to a new value.
#define BW_SSI_SSI_SACNT_TIF(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_TIF) | BF_SSI_SSI_SACNT_TIF(v)))
#endif


/* --- Register HW_SSI_SSI_SACNT, field RD[3] (RW)
 *
 * Read Command. This bit specifies whether the next frame will carry an AC97 Read Command or not.
 * The programmer should take care that only one of the bits (WR or RD) is set at a time. When this
 * bit is set, the corresponding tag bit (corresponding to Command Address slot of the next Tx
 * frame) is automatically set. This bit is automatically cleared by the SSI after completing
 * transmission of a frame.
 *
 * Values:
 * 0 - Next frame will not have a Read Command.
 * 1 - Next frame will have a Read Command.
 */

#define BP_SSI_SSI_SACNT_RD      (3)      //!< Bit position for SSI_SSI_SACNT_RD.
#define BM_SSI_SSI_SACNT_RD      (0x00000008)  //!< Bit mask for SSI_SSI_SACNT_RD.

//! @brief Get value of SSI_SSI_SACNT_RD from a register value.
#define BG_SSI_SSI_SACNT_RD(r)   (((r) & BM_SSI_SSI_SACNT_RD) >> BP_SSI_SSI_SACNT_RD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_RD.
#define BF_SSI_SSI_SACNT_RD(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_RD) & BM_SSI_SSI_SACNT_RD)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_RD.
#define BF_SSI_SSI_SACNT_RD(v)   (((v) << BP_SSI_SSI_SACNT_RD) & BM_SSI_SSI_SACNT_RD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RD field to a new value.
#define BW_SSI_SSI_SACNT_RD(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_RD) | BF_SSI_SSI_SACNT_RD(v)))
#endif


/* --- Register HW_SSI_SSI_SACNT, field WR[4] (RW)
 *
 * Write Command. This bit specifies whether the next frame will carry an AC97 Write Command or not.
 * The programmer should take care that only one of the bits (WR or RD) is set at a time. When this
 * bit is set, the corresponding tag bits (corresponding to Command Address and Command Data slots
 * of the next Tx frame) are automatically set. This bit is automatically cleared by the SSI after
 * completing transmission of a frame.
 *
 * Values:
 * 0 - Next frame will not have a Write Command.
 * 1 - Next frame will have a Write Command.
 */

#define BP_SSI_SSI_SACNT_WR      (4)      //!< Bit position for SSI_SSI_SACNT_WR.
#define BM_SSI_SSI_SACNT_WR      (0x00000010)  //!< Bit mask for SSI_SSI_SACNT_WR.

//! @brief Get value of SSI_SSI_SACNT_WR from a register value.
#define BG_SSI_SSI_SACNT_WR(r)   (((r) & BM_SSI_SSI_SACNT_WR) >> BP_SSI_SSI_SACNT_WR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_WR.
#define BF_SSI_SSI_SACNT_WR(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_WR) & BM_SSI_SSI_SACNT_WR)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_WR.
#define BF_SSI_SSI_SACNT_WR(v)   (((v) << BP_SSI_SSI_SACNT_WR) & BM_SSI_SSI_SACNT_WR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WR field to a new value.
#define BW_SSI_SSI_SACNT_WR(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_WR) | BF_SSI_SSI_SACNT_WR(v)))
#endif


/* --- Register HW_SSI_SSI_SACNT, field FRDIV[10:5] (RW)
 *
 * Frame Rate Divider. These bits control the frequency of AC97 data transmission/reception. They
 * are programmed with the number of frames for which the SSI should be idle, after operating in one
 * frame. Through these bits, AC97 frequency of operation, from 48 KHz (000000) to 1 KHz (101111)
 * can be achieved. Sample Value: 001010 (10 Decimal) = SSI will operate once every 11 frames.
 */

#define BP_SSI_SSI_SACNT_FRDIV      (5)      //!< Bit position for SSI_SSI_SACNT_FRDIV.
#define BM_SSI_SSI_SACNT_FRDIV      (0x000007e0)  //!< Bit mask for SSI_SSI_SACNT_FRDIV.

//! @brief Get value of SSI_SSI_SACNT_FRDIV from a register value.
#define BG_SSI_SSI_SACNT_FRDIV(r)   (((r) & BM_SSI_SSI_SACNT_FRDIV) >> BP_SSI_SSI_SACNT_FRDIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACNT_FRDIV.
#define BF_SSI_SSI_SACNT_FRDIV(v)   ((((reg32_t) v) << BP_SSI_SSI_SACNT_FRDIV) & BM_SSI_SSI_SACNT_FRDIV)
#else
//! @brief Format value for bitfield SSI_SSI_SACNT_FRDIV.
#define BF_SSI_SSI_SACNT_FRDIV(v)   (((v) << BP_SSI_SSI_SACNT_FRDIV) & BM_SSI_SSI_SACNT_FRDIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRDIV field to a new value.
#define BW_SSI_SSI_SACNT_FRDIV(x, v)   (HW_SSI_SSI_SACNT_WR(x, (HW_SSI_SSI_SACNT_RD(x) & ~BM_SSI_SSI_SACNT_FRDIV) | BF_SSI_SSI_SACNT_FRDIV(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACADD - SSI AC97 Command Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_sacadd
{
    reg32_t U;
    struct _hw_ssi_ssi_sacadd_bitfields
    {
        unsigned SACADD : 19; //!< [18:0] AC97 Command Address. These bits store the Command Address Slot information (bit 19 of the slot is sent in accordance with the Read and Write Command bits in SSI_SACNT register). These bits can be updated by a direct write from the Core. They are also updated with the information received in the incoming Command Address Slot. If the contents of these bits change due to an update, the CMDAU bit in SISR is set.
        unsigned RESERVED0 : 13; //!< [31:19] Reserved
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

/* --- Register HW_SSI_SSI_SACADD, field SACADD[18:0] (RW)
 *
 * AC97 Command Address. These bits store the Command Address Slot information (bit 19 of the slot
 * is sent in accordance with the Read and Write Command bits in SSI_SACNT register). These bits can
 * be updated by a direct write from the Core. They are also updated with the information received
 * in the incoming Command Address Slot. If the contents of these bits change due to an update, the
 * CMDAU bit in SISR is set.
 */

#define BP_SSI_SSI_SACADD_SACADD      (0)      //!< Bit position for SSI_SSI_SACADD_SACADD.
#define BM_SSI_SSI_SACADD_SACADD      (0x0007ffff)  //!< Bit mask for SSI_SSI_SACADD_SACADD.

//! @brief Get value of SSI_SSI_SACADD_SACADD from a register value.
#define BG_SSI_SSI_SACADD_SACADD(r)   (((r) & BM_SSI_SSI_SACADD_SACADD) >> BP_SSI_SSI_SACADD_SACADD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACADD_SACADD.
#define BF_SSI_SSI_SACADD_SACADD(v)   ((((reg32_t) v) << BP_SSI_SSI_SACADD_SACADD) & BM_SSI_SSI_SACADD_SACADD)
#else
//! @brief Format value for bitfield SSI_SSI_SACADD_SACADD.
#define BF_SSI_SSI_SACADD_SACADD(v)   (((v) << BP_SSI_SSI_SACADD_SACADD) & BM_SSI_SSI_SACADD_SACADD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SACADD field to a new value.
#define BW_SSI_SSI_SACADD_SACADD(x, v)   (HW_SSI_SSI_SACADD_WR(x, (HW_SSI_SSI_SACADD_RD(x) & ~BM_SSI_SSI_SACADD_SACADD) | BF_SSI_SSI_SACADD_SACADD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACDAT - SSI AC97 Command Data Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_sacdat
{
    reg32_t U;
    struct _hw_ssi_ssi_sacdat_bitfields
    {
        unsigned SACDAT : 20; //!< [19:0] AC97 Command Data. The outgoing Command Data Slot carries the information contained in these bits. These bits can be updated by a direct write from the Core. They are also updated with the information received in the incoming Command Data Slot. If the contents of these bits change due to an update, the CMDDU bit in SISR is set. These bits are transmitted only during AC97 Write Command. During AC97 Read Command, 0x00000 is transmitted in time slot #2.
        unsigned RESERVED0 : 12; //!< [31:20] Reserved
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

/* --- Register HW_SSI_SSI_SACDAT, field SACDAT[19:0] (RW)
 *
 * AC97 Command Data. The outgoing Command Data Slot carries the information contained in these
 * bits. These bits can be updated by a direct write from the Core. They are also updated with the
 * information received in the incoming Command Data Slot. If the contents of these bits change due
 * to an update, the CMDDU bit in SISR is set. These bits are transmitted only during AC97 Write
 * Command. During AC97 Read Command, 0x00000 is transmitted in time slot #2.
 */

#define BP_SSI_SSI_SACDAT_SACDAT      (0)      //!< Bit position for SSI_SSI_SACDAT_SACDAT.
#define BM_SSI_SSI_SACDAT_SACDAT      (0x000fffff)  //!< Bit mask for SSI_SSI_SACDAT_SACDAT.

//! @brief Get value of SSI_SSI_SACDAT_SACDAT from a register value.
#define BG_SSI_SSI_SACDAT_SACDAT(r)   (((r) & BM_SSI_SSI_SACDAT_SACDAT) >> BP_SSI_SSI_SACDAT_SACDAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACDAT_SACDAT.
#define BF_SSI_SSI_SACDAT_SACDAT(v)   ((((reg32_t) v) << BP_SSI_SSI_SACDAT_SACDAT) & BM_SSI_SSI_SACDAT_SACDAT)
#else
//! @brief Format value for bitfield SSI_SSI_SACDAT_SACDAT.
#define BF_SSI_SSI_SACDAT_SACDAT(v)   (((v) << BP_SSI_SSI_SACDAT_SACDAT) & BM_SSI_SSI_SACDAT_SACDAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SACDAT field to a new value.
#define BW_SSI_SSI_SACDAT_SACDAT(x, v)   (HW_SSI_SSI_SACDAT_WR(x, (HW_SSI_SSI_SACDAT_RD(x) & ~BM_SSI_SSI_SACDAT_SACDAT) | BF_SSI_SSI_SACDAT_SACDAT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SATAG - SSI AC97 Tag Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_satag
{
    reg32_t U;
    struct _hw_ssi_satag_bitfields
    {
        unsigned SATAG : 16; //!< [15:0] AC97 Tag Value. Writing to this register (by the Core) sets the value of the Tx-Tag in AC97 fixed mode of operation. On a read, the Core gets the Rx-Tag Value received (in the last frame) from the Codec. If TIF bit in SSI_SACNT register is set, the TAG value is also stored in Rx-FIFO in addition to SATAG register. When the received Tag value changes, the RXT bit in SISR register is set. Bits SATAG[1:0] convey the Codec -ID. In current implementation only Primary Codecs are supported. Thus writing value 2'b00 to this field is mandatory.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
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

/* --- Register HW_SSI_SATAG, field SATAG[15:0] (RW)
 *
 * AC97 Tag Value. Writing to this register (by the Core) sets the value of the Tx-Tag in AC97 fixed
 * mode of operation. On a read, the Core gets the Rx-Tag Value received (in the last frame) from
 * the Codec. If TIF bit in SSI_SACNT register is set, the TAG value is also stored in Rx-FIFO in
 * addition to SATAG register. When the received Tag value changes, the RXT bit in SISR register is
 * set. Bits SATAG[1:0] convey the Codec -ID. In current implementation only Primary Codecs are
 * supported. Thus writing value 2'b00 to this field is mandatory.
 */

#define BP_SSI_SATAG_SATAG      (0)      //!< Bit position for SSI_SATAG_SATAG.
#define BM_SSI_SATAG_SATAG      (0x0000ffff)  //!< Bit mask for SSI_SATAG_SATAG.

//! @brief Get value of SSI_SATAG_SATAG from a register value.
#define BG_SSI_SATAG_SATAG(r)   (((r) & BM_SSI_SATAG_SATAG) >> BP_SSI_SATAG_SATAG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SATAG_SATAG.
#define BF_SSI_SATAG_SATAG(v)   ((((reg32_t) v) << BP_SSI_SATAG_SATAG) & BM_SSI_SATAG_SATAG)
#else
//! @brief Format value for bitfield SSI_SATAG_SATAG.
#define BF_SSI_SATAG_SATAG(v)   (((v) << BP_SSI_SATAG_SATAG) & BM_SSI_SATAG_SATAG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SATAG field to a new value.
#define BW_SSI_SATAG_SATAG(x, v)   (HW_SSI_SATAG_WR(x, (HW_SSI_SATAG_RD(x) & ~BM_SSI_SATAG_SATAG) | BF_SSI_SATAG_SATAG(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_STMSK - SSI Transmit Time Slot Mask Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_stmsk
{
    reg32_t U;
    struct _hw_ssi_ssi_stmsk_bitfields
    {
        unsigned STMSK : 32; //!< [31:0] Transmit Mask. These bits indicate which slot has been masked in the current frame. The Core can write to this register to control the time slots in which the SSI transmits data. Each bit has info corresponding to the respective time slot in the frame. Transmit mask bits should not be used in I2S Slave mode of operation. SSI_STMSK register value must be set before enabling Transmission.
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

/* --- Register HW_SSI_SSI_STMSK, field STMSK[31:0] (RW)
 *
 * Transmit Mask. These bits indicate which slot has been masked in the current frame. The Core can
 * write to this register to control the time slots in which the SSI transmits data. Each bit has
 * info corresponding to the respective time slot in the frame. Transmit mask bits should not be
 * used in I2S Slave mode of operation. SSI_STMSK register value must be set before enabling
 * Transmission.
 *
 * Values:
 * 0 - Valid Time Slot.
 * 1 - Time Slot masked (no data transmitted in this time slot).
 */

#define BP_SSI_SSI_STMSK_STMSK      (0)      //!< Bit position for SSI_SSI_STMSK_STMSK.
#define BM_SSI_SSI_STMSK_STMSK      (0xffffffff)  //!< Bit mask for SSI_SSI_STMSK_STMSK.

//! @brief Get value of SSI_SSI_STMSK_STMSK from a register value.
#define BG_SSI_SSI_STMSK_STMSK(r)   (((r) & BM_SSI_SSI_STMSK_STMSK) >> BP_SSI_SSI_STMSK_STMSK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_STMSK_STMSK.
#define BF_SSI_SSI_STMSK_STMSK(v)   ((((reg32_t) v) << BP_SSI_SSI_STMSK_STMSK) & BM_SSI_SSI_STMSK_STMSK)
#else
//! @brief Format value for bitfield SSI_SSI_STMSK_STMSK.
#define BF_SSI_SSI_STMSK_STMSK(v)   (((v) << BP_SSI_SSI_STMSK_STMSK) & BM_SSI_SSI_STMSK_STMSK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STMSK field to a new value.
#define BW_SSI_SSI_STMSK_STMSK(x, v)   (HW_SSI_SSI_STMSK_WR(x, (HW_SSI_SSI_STMSK_RD(x) & ~BM_SSI_SSI_STMSK_STMSK) | BF_SSI_SSI_STMSK_STMSK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SRMSK - SSI Receive Time Slot Mask Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_srmsk
{
    reg32_t U;
    struct _hw_ssi_ssi_srmsk_bitfields
    {
        unsigned SRMSK : 32; //!< [31:0] Receive Mask. These bits indicate which slot has been masked in the current frame. The Core can write to this register to control the time slots in which the SSI receives data. Each bit has info corresponding to the respective time slot in the frame. SSI_SRMSK register value must be set before enabling Receiver. Receive mask bits should not be used in I2S Slave mode of operation.
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

/* --- Register HW_SSI_SSI_SRMSK, field SRMSK[31:0] (RW)
 *
 * Receive Mask. These bits indicate which slot has been masked in the current frame. The Core can
 * write to this register to control the time slots in which the SSI receives data. Each bit has
 * info corresponding to the respective time slot in the frame. SSI_SRMSK register value must be set
 * before enabling Receiver. Receive mask bits should not be used in I2S Slave mode of operation.
 *
 * Values:
 * 0 - Valid Time Slot.
 * 1 - Time Slot masked (no data received in this time slot).
 */

#define BP_SSI_SSI_SRMSK_SRMSK      (0)      //!< Bit position for SSI_SSI_SRMSK_SRMSK.
#define BM_SSI_SSI_SRMSK_SRMSK      (0xffffffff)  //!< Bit mask for SSI_SSI_SRMSK_SRMSK.

//! @brief Get value of SSI_SSI_SRMSK_SRMSK from a register value.
#define BG_SSI_SSI_SRMSK_SRMSK(r)   (((r) & BM_SSI_SSI_SRMSK_SRMSK) >> BP_SSI_SSI_SRMSK_SRMSK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SRMSK_SRMSK.
#define BF_SSI_SSI_SRMSK_SRMSK(v)   ((((reg32_t) v) << BP_SSI_SSI_SRMSK_SRMSK) & BM_SSI_SSI_SRMSK_SRMSK)
#else
//! @brief Format value for bitfield SSI_SSI_SRMSK_SRMSK.
#define BF_SSI_SSI_SRMSK_SRMSK(v)   (((v) << BP_SSI_SSI_SRMSK_SRMSK) & BM_SSI_SSI_SRMSK_SRMSK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRMSK field to a new value.
#define BW_SSI_SSI_SRMSK_SRMSK(x, v)   (HW_SSI_SSI_SRMSK_WR(x, (HW_SSI_SSI_SRMSK_RD(x) & ~BM_SSI_SSI_SRMSK_SRMSK) | BF_SSI_SSI_SRMSK_SRMSK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACCST - SSI AC97 Channel Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_saccst
{
    reg32_t U;
    struct _hw_ssi_ssi_saccst_bitfields
    {
        unsigned SACCST : 10; //!< [9:0] AC97 Channel Status. These bits indicate which data slot has been enabled in AC97 variable mode operation. This register is updated in case the core enables/disables a channel through a write to SSI_SACCEN/SSI_SACCDIS register or the external codec enables a channel by sending a '1' in the corresponding SLOTREQ bit. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). The contents of this register only have relevance while the SSI is operating in AC97 variable mode. Writes to this register result in an error response on the block interface.
        unsigned RESERVED0 : 22; //!< [31:10] Reserved
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
#endif

/*
 * constants & macros for individual SSI_SSI_SACCST bitfields
 */

/* --- Register HW_SSI_SSI_SACCST, field SACCST[9:0] (RO)
 *
 * AC97 Channel Status. These bits indicate which data slot has been enabled in AC97 variable mode
 * operation. This register is updated in case the core enables/disables a channel through a write
 * to SSI_SACCEN/SSI_SACCDIS register or the external codec enables a channel by sending a '1' in
 * the corresponding SLOTREQ bit. Bit [0] corresponds to the first data slot in an AC97 frame (Slot
 * #3) and Bit [9] corresponds to the tenth data slot (slot #12). The contents of this register only
 * have relevance while the SSI is operating in AC97 variable mode. Writes to this register result
 * in an error response on the block interface.
 *
 * Values:
 * 0 - Data channel disabled.
 * 1 - Data channel enabled.
 */

#define BP_SSI_SSI_SACCST_SACCST      (0)      //!< Bit position for SSI_SSI_SACCST_SACCST.
#define BM_SSI_SSI_SACCST_SACCST      (0x000003ff)  //!< Bit mask for SSI_SSI_SACCST_SACCST.

//! @brief Get value of SSI_SSI_SACCST_SACCST from a register value.
#define BG_SSI_SSI_SACCST_SACCST(r)   (((r) & BM_SSI_SSI_SACCST_SACCST) >> BP_SSI_SSI_SACCST_SACCST)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACCEN - SSI AC97 Channel Enable Register (WO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_saccen
{
    reg32_t U;
    struct _hw_ssi_ssi_saccen_bitfields
    {
        unsigned SACCEN : 10; //!< [9:0] AC97 Channel Enable. The Core writes a '1' to these bits to enable an AC97 data channel. Writing a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have effect in the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
        unsigned RESERVED0 : 22; //!< [31:10] Reserved
    } B;
} hw_ssi_ssi_saccen_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCEN register
 */
#define HW_SSI_SSI_SACCEN_ADDR(x)      (REGS_SSI_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCEN(x)           (*(volatile hw_ssi_ssi_saccen_t *) HW_SSI_SSI_SACCEN_ADDR(x))
#define HW_SSI_SSI_SACCEN_WR(x, v)     (HW_SSI_SSI_SACCEN(x).U = (v))
#endif

/*
 * constants & macros for individual SSI_SSI_SACCEN bitfields
 */

/* --- Register HW_SSI_SSI_SACCEN, field SACCEN[9:0] (WO)
 *
 * AC97 Channel Enable. The Core writes a '1' to these bits to enable an AC97 data channel. Writing
 * a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and
 * Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have effect in
 * the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
 *
 * Values:
 * 0 - Write Has no effect.
 * 1 - Write Enables the corresponding data channel.
 */

#define BP_SSI_SSI_SACCEN_SACCEN      (0)      //!< Bit position for SSI_SSI_SACCEN_SACCEN.
#define BM_SSI_SSI_SACCEN_SACCEN      (0x000003ff)  //!< Bit mask for SSI_SSI_SACCEN_SACCEN.

//! @brief Get value of SSI_SSI_SACCEN_SACCEN from a register value.
#define BG_SSI_SSI_SACCEN_SACCEN(r)   (((r) & BM_SSI_SSI_SACCEN_SACCEN) >> BP_SSI_SSI_SACCEN_SACCEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACCEN_SACCEN.
#define BF_SSI_SSI_SACCEN_SACCEN(v)   ((((reg32_t) v) << BP_SSI_SSI_SACCEN_SACCEN) & BM_SSI_SSI_SACCEN_SACCEN)
#else
//! @brief Format value for bitfield SSI_SSI_SACCEN_SACCEN.
#define BF_SSI_SSI_SACCEN_SACCEN(v)   (((v) << BP_SSI_SSI_SACCEN_SACCEN) & BM_SSI_SSI_SACCEN_SACCEN)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SSI_SSI_SACCDIS - SSI AC97 Channel Disable Register (WO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_ssi_ssi_saccdis
{
    reg32_t U;
    struct _hw_ssi_ssi_saccdis_bitfields
    {
        unsigned SACCDIS : 10; //!< [9:0] AC97 Channel Disable. The Core writes a '1' to these bits to disable an AC97 data channel. Writing a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot #3) and Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have effect in the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
        unsigned RESERVED0 : 22; //!< [31:10] Reserved
    } B;
} hw_ssi_ssi_saccdis_t;
#endif

/*
 * constants & macros for entire multi-block SSI_SSI_SACCDIS register
 */
#define HW_SSI_SSI_SACCDIS_ADDR(x)      (REGS_SSI_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SSI_SSI_SACCDIS(x)           (*(volatile hw_ssi_ssi_saccdis_t *) HW_SSI_SSI_SACCDIS_ADDR(x))
#define HW_SSI_SSI_SACCDIS_WR(x, v)     (HW_SSI_SSI_SACCDIS(x).U = (v))
#endif

/*
 * constants & macros for individual SSI_SSI_SACCDIS bitfields
 */

/* --- Register HW_SSI_SSI_SACCDIS, field SACCDIS[9:0] (WO)
 *
 * AC97 Channel Disable. The Core writes a '1' to these bits to disable an AC97 data channel.
 * Writing a '0' has no effect. Bit [0] corresponds to the first data slot in an AC97 frame (Slot
 * #3) and Bit [9] corresponds to the tenth data slot (slot #12). Writes to these bits only have
 * effect in the AC97 Variable mode of operation. These bits are always read as '0' by the Core.
 *
 * Values:
 * 0 - Write Has no effect.
 * 1 - Write Disables the corresponding data channel.
 */

#define BP_SSI_SSI_SACCDIS_SACCDIS      (0)      //!< Bit position for SSI_SSI_SACCDIS_SACCDIS.
#define BM_SSI_SSI_SACCDIS_SACCDIS      (0x000003ff)  //!< Bit mask for SSI_SSI_SACCDIS_SACCDIS.

//! @brief Get value of SSI_SSI_SACCDIS_SACCDIS from a register value.
#define BG_SSI_SSI_SACCDIS_SACCDIS(r)   (((r) & BM_SSI_SSI_SACCDIS_SACCDIS) >> BP_SSI_SSI_SACCDIS_SACCDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SSI_SSI_SACCDIS_SACCDIS.
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   ((((reg32_t) v) << BP_SSI_SSI_SACCDIS_SACCDIS) & BM_SSI_SSI_SACCDIS_SACCDIS)
#else
//! @brief Format value for bitfield SSI_SSI_SACCDIS_SACCDIS.
#define BF_SSI_SSI_SACCDIS_SACCDIS(v)   (((v) << BP_SSI_SSI_SACCDIS_SACCDIS) & BM_SSI_SSI_SACCDIS_SACCDIS)
#endif



/*!
 * @brief All SSI module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ssi
{
    volatile hw_ssi_ssi_stx0_t SSI_STX0; //!< SSI Transmit Data Register n
    volatile hw_ssi_ssi_stx1_t SSI_STX1; //!< SSI Transmit Data Register n
    volatile hw_ssi_ssi_srx0_t SSI_SRX0; //!< SSI Receive Data Register n
    volatile hw_ssi_ssi_srx1_t SSI_SRX1; //!< SSI Receive Data Register n
    volatile hw_ssi_ssi_scr_t SSI_SCR; //!< SSI Control Register
    volatile hw_ssi_ssi_sisr_t SSI_SISR; //!< SSI Interrupt Status Register
    volatile hw_ssi_sier_t SIER; //!< SSI Interrupt Enable Register
    volatile hw_ssi_ssi_stcr_t SSI_STCR; //!< SSI Transmit Configuration Register
    volatile hw_ssi_ssi_srcr_t SSI_SRCR; //!< SSI Receive Configuration Register
    volatile hw_ssi_ssi_stccr_t SSI_STCCR; //!< SSI Transmit Clock Control Register
    volatile hw_ssi_srccr_t SRCCR; //!< SSI Receive Clock Control Register
    volatile hw_ssi_ssi_sfcsr_t SSI_SFCSR; //!< SSI FIFO Control/Status Register
    reg32_t _reserved0[2];
    volatile hw_ssi_ssi_sacnt_t SSI_SACNT; //!< SSI AC97 Control Register
    volatile hw_ssi_ssi_sacadd_t SSI_SACADD; //!< SSI AC97 Command Address Register
    volatile hw_ssi_ssi_sacdat_t SSI_SACDAT; //!< SSI AC97 Command Data Register
    volatile hw_ssi_satag_t SATAG; //!< SSI AC97 Tag Register
    volatile hw_ssi_ssi_stmsk_t SSI_STMSK; //!< SSI Transmit Time Slot Mask Register
    volatile hw_ssi_ssi_srmsk_t SSI_SRMSK; //!< SSI Receive Time Slot Mask Register
    volatile hw_ssi_ssi_saccst_t SSI_SACCST; //!< SSI AC97 Channel Status Register
    volatile hw_ssi_ssi_saccen_t SSI_SACCEN; //!< SSI AC97 Channel Enable Register
    volatile hw_ssi_ssi_saccdis_t SSI_SACCDIS; //!< SSI AC97 Channel Disable Register
} hw_ssi_t;
#pragma pack()

//! @brief Macro to access all SSI registers.
//! @param x SSI instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SSI(0)</code>.
#define HW_SSI(x)     (*(volatile hw_ssi_t *) REGS_SSI_BASE(x))

#endif


#endif // __HW_SSI_REGISTERS_H__
