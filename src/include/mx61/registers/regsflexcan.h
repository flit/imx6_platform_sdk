/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _FLEXCAN_H
#define _FLEXCAN_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_FLEXCAN_MCR - Module Configuration Register
 * - HW_FLEXCAN_CTRL1 - Control 1 Register
 * - HW_FLEXCAN_TIMER - Free Running Timer Register
 * - HW_FLEXCAN_RXMGMASK - Rx Mailboxes Global Mask Register
 * - HW_FLEXCAN_RX14MASK - Rx Buffer 14 Mask Register
 * - HW_FLEXCAN_RX15MASK - Rx Buffer 15 Mask Register
 * - HW_FLEXCAN_ECR - Error Counter Register
 * - HW_FLEXCAN_ESR1 - Error and Status 1 Register
 * - HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register
 * - HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register
 * - HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register
 * - HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register
 * - HW_FLEXCAN_CTRL2 - Control 2 Register
 * - HW_FLEXCAN_ESR2 - Error and Status 2 Register
 * - HW_FLEXCAN_CRCR - CRC Register
 * - HW_FLEXCAN_RXFGMASK - Rx FIFO Global Mask Register
 * - HW_FLEXCAN_RXFIR - Rx FIFO Information Register
 * - HW_FLEXCAN_RXIMR0-RXIMR63 - Rx Individual Mask Registers
 * - HW_FLEXCAN_GFWR - Glitch Filter Width Registers
 *
 * hw_flexcan_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_FLEXCAN_BASE
#define REGS_FLEXCAN0_BASE (0x02090000) //!< Base address for FLEXCAN instance number 0.
#define REGS_FLEXCAN1_BASE (0x02094000) //!< Base address for FLEXCAN instance number 1.

//! @brief Get the base address of FLEXCAN by instance number.
//! @param x FLEXCAN instance number, from 0 through 2.
#define REGS_FLEXCAN_BASE(x) ( x == 0 ? REGS_FLEXCAN0_BASE : x == 1 ? REGS_FLEXCAN1_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_MCR - Module Configuration Register (RW)
 *
 * This register defines global system configurations, such as the module operation mode (e.g., low
 * power) and maximum message buffer configuration. {statement}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MAXMB : 7; //!< This 7-bit field defines the number of the last Message Buffers that will take part in the matching and arbitration processes {FlexCAN3MemAccessStim,FlexCAN3RegAccessStim} . The reset value (0x0F) is equivalent to 16 MB configuration {FlexCAN3MemAccessStim,FlexCAN3RegAccessStim} . This field can only be written in Freeze Mode as it is blocked by hardware in other modes Number of the last MB = MAXMB. {flexcan2_ipi_slv_flex_reg_mcr_maxmb} Additionally, the value of MAXMB must encompass the FIFO size defined by CTRL2[RFFN] {FlexCAN3RegAccessStim,FlexCAN3RxRpsCkr} MAXMB also impacts the definition of the minimum number of peripheral clocks per CAN bit as described in (see ).
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IDAM : 2; //!< This 2-bit field identifies the format of the elements of the Rx FIFO filter table, as shown below. Note that all elements of the table are configured at the same time by this field (they are all the same format). See . This bit can only be written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned AEN : 1; //!< This bit is supplied for backwards compatibility reasons. When asserted, it enables the Tx abort feature. This feature guarantees a safe procedure for aborting a pending transmission, so that no frame is sent in the CAN bus without notification. This bit can only be written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} Write Abort code into Rx Mailboxes can cause unpredictable results when the MCR[AEN] is asserted.
        unsigned LPRIO_EN : 1; //!< This bit is provided for backwards compatibility reasons. It controls whether the local priority feature is enabled or not. It is used to extend the ID used during the arbitration process. With this extended ID concept, the arbitration process is done based on the full 32-bit word, but the actual transmitted ID still has 11-bit for standard frames and 29-bit for extended frames.This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned IRMQ : 1; //!< This bit indicates whether Rx matching process will be based either on individual masking and queue or on masking scheme with RXMGMASK, RX14MASK and RX15MASK, RXFGMASK {FlexCAN3RxStim,FlexCAN3RxMaskStim,FlexCAN3RxRpsCkr,cover_irmq} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
        unsigned SRX_DIS : 1; //!< This bit defines whether FlexCAN is allowed to receive frames transmitted by itself {FlexCAN3RxStim,FlexCAN3RxRpsCkr,cover_srx_dis} . If this bit is asserted, frames transmitted by the module will not be stored in any MB, regardless if the MB is programmed with an ID that matches the transmitted frame, and no interrupt flag or interrupt signal will be generated due to the frame reception {FlexCAN3RxStim,FlexCAN3RxRpsCkr,cover_srx_dis} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} .
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned WAK_SRC : 1; //!< This bit defines whether the integrated low-pass filter is applied to protect the Rx CAN input from spurious wake up.See {statement} for more information. This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned LPM_ACK : 1; //!< This read-only bit indicates that FLEXCAN is either in Disable Mode or Stop Mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . Either of these low power modes can not be entered until all current transmission or reception processes have finished, so the ARM can poll the LPM_ACK bit to know when FLEXCAN has actually entered low power mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} {statement} . See , and for more information {Statement}
        unsigned WRN_EN : 1; //!< When asserted, this bit enables the generation of the TWRN_INT and RWRN_INT flags in the Error and Status Register. If WRN_EN is negated, the TWRN_INT and RWRN_INT flags will always be zero, independent of the values of the error counters, and no warning interrupt will ever be generated.This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned SLF_WAK : 1; //!< This bit enables the Self Wake Up feature when FLEXCAN is in Stop Mode {flexcan2_ipi_slv_flex_reg_mcr_swu} . If this bit had been asserted by the time FLEXCAN entered Stop Mode, then FLEXCAN will look for a recessive to dominant transition on the bus during these modes {flexcan2_ipi_slv_flex_reg_mcr_swu} . If a transition from recessive to dominant is detected during Stop Mode, then FLEXCAN generates, if enabled to do so, a Wake Up interrupt to the ARM so that it can resume the clocks globally and FlexCAN can request to resume the clocks {FlexCAN3LPMRandStim_todo,FlexCAN3IPSRpsCkr,assert_wakeup_stop_clear} . {flexcan2_ipi_slv_flex_reg_mcr_swu} This bit can not be written while the module is in Stop Mode {flexcan2_ipi_slv_flex_reg_mcr_swu} .
        unsigned SUPV : 1; //!< This bit configures some of the FLEXCAN registers to be either in Supervisor or User Mode {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_access} . Reset value of this bit is '1', so the affected registers start with Supervisor access allowance only . {flexcan2_ipi_slv_flex_reg_access} This bit can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} .
        unsigned FRZ_ACK : 1; //!< This read-only bit indicates that FLEXCAN is in Freeze Mode and its prescaler is stopped {flexcan2_ipi_slv_flex_freezemode} . The Freeze Mode request cannot be granted until current transmission or reception processes have finished {flexcan2_ipi_slv_flex_freezemode} . Therefore the software can poll the FRZ_ACK bit to know when FLEXCAN has actually entered Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . If Freeze Mode request is negated, then this bit is negated once the FLEXCAN prescaler is running again. {flexcan2_ipi_slv_flex_freezemode} If Freeze Mode is requested while FLEXCAN is in any of the low power modes, then the FRZ_ACK bit will only be set when the low power mode is exited {flexcan2_ipi_slv_flex_freezemode} {statement} . See for more information {Statement}
        unsigned SOFT_RST : 1; //!< When this bit is asserted, FlexCAN resets its internal state machines and some of the memory mapped registers {FlexCAN3RegAccessStim} . The following registers are reset: MCR (except the MDIS bit), TIMER, TCR, ECR, ESR1, ESR2, ESR3, IMASK1, IMASK2, IMASK3, IMASK4, IFLAG1, IFLAG2 IFLAG3, IFLAG4, IMEUR, LRFR and CRCR {FlexCAN3RegAccessStim} . Configuration registers that control the interface to the CAN bus are not affected by soft reset {assert_soft_rst_todo} . The following registers are unaffected: CTRL {flexcan2_ipi_slv_flex_softreset} 1, CTRL2, RXIMR0-RXIMR63 {flexcan2_ipi_slv_flex_softreset} , RXGMASK, RX14MASK, RX15MASK {flexcan2_ipi_slv_flex_softreset} , RXFGMASK, RXFIR and all Message Buffers {flexcan2_ipi_slv_flex_softreset} The SOFT_RST bit can be asserted directly by the ARM when it writes to the MCR Register. It may take some time to fully propagate its effect {statement} . The SOFT_RST bit remains asserted while reset is pending, and is automatically negated when reset completes {flexcan2_ipi_slv_flex_softreset} . Therefore, software can poll this bit to know when the soft reset has completed. {flexcan2_ipi_slv_flex_softreset} Soft reset cannot be applied while clocks are shut down in any of the low power modes {statement} . The module should be first removed from low power mode, and then soft reset can be applied {statement} .
        unsigned WAK_MSK : 1; //!< This bit enables the Wake Up Interrupt generation. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned NOT_RDY : 1; //!< This read-only bit indicates that FLEXCAN is either in Disable Mode, Stop Mode or Freeze Mode {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . It is negated once FLEXCAN has exited these modes. {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode}{flexcan2_ipi_slv_flex_reg_mcr_swu}
        unsigned HALT : 1; //!< Assertion of this bit puts the FLEXCAN module into Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . The ARM should clear it after initializing the Message Buffers and Control Register {statement} . No reception or transmission is performed by FLEXCAN before this bit is cleared {flexcan2_ipi_slv_flex_freezemode} . Freeze Mode can not be entered while FLEXCAN is in any of the low power modes {flexcan2_ipi_slv_flex_freezemode} {statement} .See for more information {Statement}
        unsigned RFEN : 1; //!< This bit controls whether the Rx FIFO feature is enabled or not {assert_rxfifo_*} . In Legacy Mode, w W hen RFEN is set, MBs 0 to 5 cannot be used for normal reception and transmission because the corresponding memory region (0x80-0xDC) is used by the FIFO engine as well as additional MBs (up to 32, depending on CTRL2[RFFN] setting) which are used as Rx FIFO ID Filter Table elements {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} .RFEN also impacts the definition of the minimum number of peripheral clocks per CAN bit as described in (see ).This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned FRZ : 1; //!< The FRZ bit specifies the FLEXCAN behavior when the HALT bit in the MCR Register is set or when Debug Mode is requested at ARM level . When FRZ is asserted, FLEXCAN is enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . Negation of this bit field causes FLEXCAN to exit from Freeze Mode {flexcan2_ipi_slv_flex_freezemode} .
        unsigned MDIS : 1; //!< This bit controls whether FLEXCAN is enabled or not {flexcan2_ipi_slv_flex_disablemode} . When disabled, FLEXCAN shuts down the clocks to the CAN Protocol Interface and Message Buffer Management sub-modules {flexcan2_ipi_slv_flex_disablemode} . This is the only bit in MCR not affected by soft reset {flexcan2_ipi_slv_flex_softreset} . {statement} See for more information. {Statement}
    } B;
} hw_flexcan_mcr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_MCR register
 */
#define HW_FLEXCAN_MCR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_MCR(x)           (*(volatile hw_flexcan_mcr_t *) HW_FLEXCAN_MCR_ADDR(x))
#define HW_FLEXCAN_MCR_RD(x)        (HW_FLEXCAN_MCR(x).U)
#define HW_FLEXCAN_MCR_WR(x, v)     (HW_FLEXCAN_MCR(x).U = (v))
#define HW_FLEXCAN_MCR_SET(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) |  (v)))
#define HW_FLEXCAN_MCR_CLR(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) & ~(v)))
#define HW_FLEXCAN_MCR_TOG(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_MCR bitfields
 */

/* --- Register HW_FLEXCAN_MCR, field MAXMB (RW)
 *
 * This 7-bit field defines the number of the last Message Buffers that will take part in the
 * matching and arbitration processes {FlexCAN3MemAccessStim,FlexCAN3RegAccessStim} . The reset
 * value (0x0F) is equivalent to 16 MB configuration {FlexCAN3MemAccessStim,FlexCAN3RegAccessStim} .
 * This field can only be written in Freeze Mode as it is blocked by hardware in other modes Number
 * of the last MB = MAXMB. {flexcan2_ipi_slv_flex_reg_mcr_maxmb} Additionally, the value of MAXMB
 * must encompass the FIFO size defined by CTRL2[RFFN] {FlexCAN3RegAccessStim,FlexCAN3RxRpsCkr}
 * MAXMB also impacts the definition of the minimum number of peripheral clocks per CAN bit as
 * described in (see ).
 */

#define BP_FLEXCAN_MCR_MAXMB      0
#define BM_FLEXCAN_MCR_MAXMB      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_MAXMB(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_MCR_MAXMB)
#else
#define BF_FLEXCAN_MCR_MAXMB(v)   (((v) << 0) & BM_FLEXCAN_MCR_MAXMB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MAXMB field to a new value.
#define BW_FLEXCAN_MCR_MAXMB(v)   BF_CS1(FLEXCAN_MCR, MAXMB, v)
#endif

/* --- Register HW_FLEXCAN_MCR, field IDAM (RW)
 *
 * This 2-bit field identifies the format of the elements of the Rx FIFO filter table, as shown
 * below. Note that all elements of the table are configured at the same time by this field (they
 * are all the same format). See . This bit can only be written in Freeze mode as it is blocked by
 * hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
 *
 * Values:
 * 00 - Format A One full ID (standard or extended) per ID filter Table element.
 * 01 - Format B Two full standard IDs or two partial 14-bit extended IDs per ID filter Table element.
 * 10 - Format C Four partial 8-bit IDs (standard or extended) per ID filter Table element.
 * 11 - Format D All frames rejected.
 */

#define BP_FLEXCAN_MCR_IDAM      8
#define BM_FLEXCAN_MCR_IDAM      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_IDAM(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_MCR_IDAM)
#else
#define BF_FLEXCAN_MCR_IDAM(v)   (((v) << 8) & BM_FLEXCAN_MCR_IDAM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDAM field to a new value.
#define BW_FLEXCAN_MCR_IDAM(v)   BF_CS1(FLEXCAN_MCR, IDAM, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field AEN (RW)
 *
 * This bit is supplied for backwards compatibility reasons. When asserted, it enables the Tx abort
 * feature. This feature guarantees a safe procedure for aborting a pending transmission, so that no
 * frame is sent in the CAN bus without notification. This bit can only be written in Freeze mode as
 * it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} Write Abort
 * code into Rx Mailboxes can cause unpredictable results when the MCR[AEN] is asserted.
 *
 * Values:
 * 1 - Abort enabled
 * 0 - Abort disabled
 */

#define BP_FLEXCAN_MCR_AEN      12
#define BM_FLEXCAN_MCR_AEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_AEN(v)   ((((reg32_t) v) << 12) & BM_FLEXCAN_MCR_AEN)
#else
#define BF_FLEXCAN_MCR_AEN(v)   (((v) << 12) & BM_FLEXCAN_MCR_AEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AEN field to a new value.
#define BW_FLEXCAN_MCR_AEN(v)   BF_CS1(FLEXCAN_MCR, AEN, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field LPRIO_EN (RW)
 *
 * This bit is provided for backwards compatibility reasons. It controls whether the local priority
 * feature is enabled or not. It is used to extend the ID used during the arbitration process. With
 * this extended ID concept, the arbitration process is done based on the full 32-bit word, but the
 * actual transmitted ID still has 11-bit for standard frames and 29-bit for extended frames.This
 * bit can only be written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Local Priority enabled
 * 0 - Local Priority disabled
 */

#define BP_FLEXCAN_MCR_LPRIO_EN      13
#define BM_FLEXCAN_MCR_LPRIO_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_LPRIO_EN(v)   ((((reg32_t) v) << 13) & BM_FLEXCAN_MCR_LPRIO_EN)
#else
#define BF_FLEXCAN_MCR_LPRIO_EN(v)   (((v) << 13) & BM_FLEXCAN_MCR_LPRIO_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LPRIO_EN field to a new value.
#define BW_FLEXCAN_MCR_LPRIO_EN(v)   BF_CS1(FLEXCAN_MCR, LPRIO_EN, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field IRMQ (RW)
 *
 * This bit indicates whether Rx matching process will be based either on individual masking and
 * queue or on masking scheme with RXMGMASK, RX14MASK and RX15MASK, RXFGMASK
 * {FlexCAN3RxStim,FlexCAN3RxMaskStim,FlexCAN3RxRpsCkr,cover_irmq} . This bit can only be written in
 * Freeze mode as it is blocked by hardware in other modes.
 * {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
 *
 * Values:
 * 1 - Individual Rx masking and queue feature are enabled.
 * 0 - Individual Rx masking and queue feature are disabled.For backward compatibility, the reading of C/S
 *     word locks the MB even if it is EMPTY.
 */

#define BP_FLEXCAN_MCR_IRMQ      16
#define BM_FLEXCAN_MCR_IRMQ      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_IRMQ(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_MCR_IRMQ)
#else
#define BF_FLEXCAN_MCR_IRMQ(v)   (((v) << 16) & BM_FLEXCAN_MCR_IRMQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRMQ field to a new value.
#define BW_FLEXCAN_MCR_IRMQ(v)   BF_CS1(FLEXCAN_MCR, IRMQ, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field SRX_DIS (RW)
 *
 * This bit defines whether FlexCAN is allowed to receive frames transmitted by itself
 * {FlexCAN3RxStim,FlexCAN3RxRpsCkr,cover_srx_dis} . If this bit is asserted, frames transmitted by
 * the module will not be stored in any MB, regardless if the MB is programmed with an ID that
 * matches the transmitted frame, and no interrupt flag or interrupt signal will be generated due to
 * the frame reception {FlexCAN3RxStim,FlexCAN3RxRpsCkr,cover_srx_dis} . This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes
 * {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} .
 *
 * Values:
 * 1 - Self reception disabled
 * 0 - Self reception enabled
 */

#define BP_FLEXCAN_MCR_SRX_DIS      17
#define BM_FLEXCAN_MCR_SRX_DIS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SRX_DIS(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_MCR_SRX_DIS)
#else
#define BF_FLEXCAN_MCR_SRX_DIS(v)   (((v) << 17) & BM_FLEXCAN_MCR_SRX_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRX_DIS field to a new value.
#define BW_FLEXCAN_MCR_SRX_DIS(v)   BF_CS1(FLEXCAN_MCR, SRX_DIS, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field WAK_SRC (RW)
 *
 * This bit defines whether the integrated low-pass filter is applied to protect the Rx CAN input
 * from spurious wake up.See {statement} for more information. This bit can only be written in
 * Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - FLEXCAN uses the filtered Rx input to detect recessive to dominant edges on the CAN bus
 *     {flexcan2_ipi_slv_flex_reg_mcr_swu}
 * 0 - FLEXCAN uses the unfiltered Rx input to detect recessive to dominant edges on the CAN bus.
 *     {flexcan2_ipi_slv_flex_reg_mcr_swu}
 */

#define BP_FLEXCAN_MCR_WAK_SRC      19
#define BM_FLEXCAN_MCR_WAK_SRC      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WAK_SRC(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_MCR_WAK_SRC)
#else
#define BF_FLEXCAN_MCR_WAK_SRC(v)   (((v) << 19) & BM_FLEXCAN_MCR_WAK_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_SRC field to a new value.
#define BW_FLEXCAN_MCR_WAK_SRC(v)   BF_CS1(FLEXCAN_MCR, WAK_SRC, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field LPM_ACK (RO)
 *
 * This read-only bit indicates that FLEXCAN is either in Disable Mode or Stop Mode {flexcan2_ipi_sl
 * v_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . Either of
 * these low power modes can not be entered until all current transmission or reception processes
 * have finished, so the ARM can poll the LPM_ACK bit to know when FLEXCAN has actually entered low
 * power mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_f
 * lex_dozemode} {statement} . See , and for more information {Statement}
 *
 * Values:
 * 1 - FLEXCAN is either in Disable Mode, or Stop mode
 *     {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_doz
 *     emode}
 * 0 - FLEXCAN not in any of the low power modes
 *     {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_doz
 *     emode}
 */

#define BP_FLEXCAN_MCR_LPM_ACK      20
#define BM_FLEXCAN_MCR_LPM_ACK      0x00100000


/* --- Register HW_FLEXCAN_MCR, field WRN_EN (RW)
 *
 * When asserted, this bit enables the generation of the TWRN_INT and RWRN_INT flags in the Error
 * and Status Register. If WRN_EN is negated, the TWRN_INT and RWRN_INT flags will always be zero,
 * independent of the values of the error counters, and no warning interrupt will ever be
 * generated.This bit can only be written in Freeze mode as it is blocked by hardware in other
 * modes.
 *
 * Values:
 * 1 - TWRN_INT and RWRN_INT bits are set when the respective error counter transition from <96 to ≥ 96.
 * 0 - TWRN_INT and RWRN_INT bits are zero, independent of the values in the error counters.
 */

#define BP_FLEXCAN_MCR_WRN_EN      21
#define BM_FLEXCAN_MCR_WRN_EN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WRN_EN(v)   ((((reg32_t) v) << 21) & BM_FLEXCAN_MCR_WRN_EN)
#else
#define BF_FLEXCAN_MCR_WRN_EN(v)   (((v) << 21) & BM_FLEXCAN_MCR_WRN_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WRN_EN field to a new value.
#define BW_FLEXCAN_MCR_WRN_EN(v)   BF_CS1(FLEXCAN_MCR, WRN_EN, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field SLF_WAK (RW)
 *
 * This bit enables the Self Wake Up feature when FLEXCAN is in Stop Mode
 * {flexcan2_ipi_slv_flex_reg_mcr_swu} . If this bit had been asserted by the time FLEXCAN entered
 * Stop Mode, then FLEXCAN will look for a recessive to dominant transition on the bus during these
 * modes {flexcan2_ipi_slv_flex_reg_mcr_swu} . If a transition from recessive to dominant is
 * detected during Stop Mode, then FLEXCAN generates, if enabled to do so, a Wake Up interrupt to
 * the ARM so that it can resume the clocks globally and FlexCAN can request to resume the clocks
 * {FlexCAN3LPMRandStim_todo,FlexCAN3IPSRpsCkr,assert_wakeup_stop_clear} .
 * {flexcan2_ipi_slv_flex_reg_mcr_swu} This bit can not be written while the module is in Stop Mode
 * {flexcan2_ipi_slv_flex_reg_mcr_swu} .
 *
 * Values:
 * 1 - FLEXCAN Self Wake Up feature is enabled {flexcan2_ipi_slv_flex_reg_mcr_swu}
 * 0 - FLEXCAN Self Wake Up feature is disabled {flexcan2_ipi_slv_flex_reg_mcr_swu}
 */

#define BP_FLEXCAN_MCR_SLF_WAK      22
#define BM_FLEXCAN_MCR_SLF_WAK      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SLF_WAK(v)   ((((reg32_t) v) << 22) & BM_FLEXCAN_MCR_SLF_WAK)
#else
#define BF_FLEXCAN_MCR_SLF_WAK(v)   (((v) << 22) & BM_FLEXCAN_MCR_SLF_WAK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLF_WAK field to a new value.
#define BW_FLEXCAN_MCR_SLF_WAK(v)   BF_CS1(FLEXCAN_MCR, SLF_WAK, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field SUPV (RW)
 *
 * This bit configures some of the FLEXCAN registers to be either in Supervisor or User Mode {flexca
 * n2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_a
 * ccess} . Reset value of this bit is '1', so the affected registers start with Supervisor access
 * allowance only . {flexcan2_ipi_slv_flex_reg_access} This bit can only be written in Freeze mode
 * as it is blocked by hardware in other modes {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} .
 *
 * Values:
 * 1 - FlexCAN is in Supervisor Mode {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . Affected registers allow
 *     only Supervisor access {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim,cover_supv} . Unrestricted
 *     access (ips_supervisor_access negated) behaves as though the access was done to an
 *     unimplemented register location
 * 0 - FlexCAN is in User Mode {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . Affected registers allow both
 *     Supervisor and Unrestricted accesses  {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_fle
 *     x_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_access}
 */

#define BP_FLEXCAN_MCR_SUPV      23
#define BM_FLEXCAN_MCR_SUPV      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SUPV(v)   ((((reg32_t) v) << 23) & BM_FLEXCAN_MCR_SUPV)
#else
#define BF_FLEXCAN_MCR_SUPV(v)   (((v) << 23) & BM_FLEXCAN_MCR_SUPV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUPV field to a new value.
#define BW_FLEXCAN_MCR_SUPV(v)   BF_CS1(FLEXCAN_MCR, SUPV, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field FRZ_ACK (RO)
 *
 * This read-only bit indicates that FLEXCAN is in Freeze Mode and its prescaler is stopped
 * {flexcan2_ipi_slv_flex_freezemode} . The Freeze Mode request cannot be granted until current
 * transmission or reception processes have finished {flexcan2_ipi_slv_flex_freezemode} . Therefore
 * the software can poll the FRZ_ACK bit to know when FLEXCAN has actually entered Freeze Mode
 * {flexcan2_ipi_slv_flex_freezemode} . If Freeze Mode request is negated, then this bit is negated
 * once the FLEXCAN prescaler is running again. {flexcan2_ipi_slv_flex_freezemode} If Freeze Mode is
 * requested while FLEXCAN is in any of the low power modes, then the FRZ_ACK bit will only be set
 * when the low power mode is exited {flexcan2_ipi_slv_flex_freezemode} {statement} . See for more
 * information {Statement}
 *
 * Values:
 * 1 - FLEXCAN in Freeze Mode, prescaler stopped {flexcan2_ipi_slv_flex_freezemode}
 * 0 - FLEXCAN not in Freeze Mode, prescaler running {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_FRZ_ACK      24
#define BM_FLEXCAN_MCR_FRZ_ACK      0x01000000


/* --- Register HW_FLEXCAN_MCR, field SOFT_RST (RW)
 *
 * When this bit is asserted, FlexCAN resets its internal state machines and some of the memory
 * mapped registers {FlexCAN3RegAccessStim} . The following registers are reset: MCR (except the
 * MDIS bit), TIMER, TCR, ECR, ESR1, ESR2, ESR3, IMASK1, IMASK2, IMASK3, IMASK4, IFLAG1, IFLAG2
 * IFLAG3, IFLAG4, IMEUR, LRFR and CRCR {FlexCAN3RegAccessStim} . Configuration registers that
 * control the interface to the CAN bus are not affected by soft reset {assert_soft_rst_todo} . The
 * following registers are unaffected: CTRL {flexcan2_ipi_slv_flex_softreset} 1, CTRL2,
 * RXIMR0-RXIMR63 {flexcan2_ipi_slv_flex_softreset} , RXGMASK, RX14MASK, RX15MASK
 * {flexcan2_ipi_slv_flex_softreset} , RXFGMASK, RXFIR and all Message Buffers
 * {flexcan2_ipi_slv_flex_softreset} The SOFT_RST bit can be asserted directly by the ARM when it
 * writes to the MCR Register. It may take some time to fully propagate its effect {statement} . The
 * SOFT_RST bit remains asserted while reset is pending, and is automatically negated when reset
 * completes {flexcan2_ipi_slv_flex_softreset} . Therefore, software can poll this bit to know when
 * the soft reset has completed. {flexcan2_ipi_slv_flex_softreset} Soft reset cannot be applied
 * while clocks are shut down in any of the low power modes {statement} . The module should be first
 * removed from low power mode, and then soft reset can be applied {statement} .
 *
 * Values:
 * 1 - Reset the registers
 * 0 - No reset request {flexcan2_ipi_slv_flex_softreset}
 */

#define BP_FLEXCAN_MCR_SOFT_RST      25
#define BM_FLEXCAN_MCR_SOFT_RST      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_SOFT_RST(v)   ((((reg32_t) v) << 25) & BM_FLEXCAN_MCR_SOFT_RST)
#else
#define BF_FLEXCAN_MCR_SOFT_RST(v)   (((v) << 25) & BM_FLEXCAN_MCR_SOFT_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RST field to a new value.
#define BW_FLEXCAN_MCR_SOFT_RST(v)   BF_CS1(FLEXCAN_MCR, SOFT_RST, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field WAK_MSK (RW)
 *
 * This bit enables the Wake Up Interrupt generation. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 1 - Wake Up Interrupt is enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - Wake Up Interrupt is disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_MCR_WAK_MSK      26
#define BM_FLEXCAN_MCR_WAK_MSK      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_WAK_MSK(v)   ((((reg32_t) v) << 26) & BM_FLEXCAN_MCR_WAK_MSK)
#else
#define BF_FLEXCAN_MCR_WAK_MSK(v)   (((v) << 26) & BM_FLEXCAN_MCR_WAK_MSK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_MSK field to a new value.
#define BW_FLEXCAN_MCR_WAK_MSK(v)   BF_CS1(FLEXCAN_MCR, WAK_MSK, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field NOT_RDY (RO)
 *
 * This read-only bit indicates that FLEXCAN is either in Disable Mode, Stop Mode or Freeze Mode {fl
 * excan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode
 * }{flexcan2_ipi_slv_flex_dozemode} . It is negated once FLEXCAN has exited these modes. {flexcan2_
 * ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexc
 * an2_ipi_slv_flex_dozemode}{flexcan2_ipi_slv_flex_reg_mcr_swu}
 *
 * Values:
 * 1 - FLEXCAN module is either in Disable Mode, Stop Mode or Freeze Mode {flexcan2_ipi_slv_flex_freezemode
 *     }{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_do
 *     zemode}
 * 0 - FLEXCAN module is either in Normal Mode, Listen-Only Mode or Loop-Back Mode {flexcan2_ipi_slv_flex_f
 *     reezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_sl
 *     v_flex_dozemode}
 */

#define BP_FLEXCAN_MCR_NOT_RDY      27
#define BM_FLEXCAN_MCR_NOT_RDY      0x08000000


/* --- Register HW_FLEXCAN_MCR, field HALT (RW)
 *
 * Assertion of this bit puts the FLEXCAN module into Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 * . The ARM should clear it after initializing the Message Buffers and Control Register {statement}
 * . No reception or transmission is performed by FLEXCAN before this bit is cleared
 * {flexcan2_ipi_slv_flex_freezemode} . Freeze Mode can not be entered while FLEXCAN is in any of
 * the low power modes {flexcan2_ipi_slv_flex_freezemode} {statement} .See for more information
 * {Statement}
 *
 * Values:
 * 1 - Enters Freeze Mode if the FRZ bit is asserted. {flexcan2_ipi_slv_flex_freezemode}
 * 0 - No Freeze Mode request. {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_HALT      28
#define BM_FLEXCAN_MCR_HALT      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_HALT(v)   ((((reg32_t) v) << 28) & BM_FLEXCAN_MCR_HALT)
#else
#define BF_FLEXCAN_MCR_HALT(v)   (((v) << 28) & BM_FLEXCAN_MCR_HALT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HALT field to a new value.
#define BW_FLEXCAN_MCR_HALT(v)   BF_CS1(FLEXCAN_MCR, HALT, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field RFEN (RW)
 *
 * This bit controls whether the Rx FIFO feature is enabled or not {assert_rxfifo_*} . In Legacy
 * Mode, w W hen RFEN is set, MBs 0 to 5 cannot be used for normal reception and transmission
 * because the corresponding memory region (0x80-0xDC) is used by the FIFO engine as well as
 * additional MBs (up to 32, depending on CTRL2[RFFN] setting) which are used as Rx FIFO ID Filter
 * Table elements {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} .RFEN also impacts the definition of the
 * minimum number of peripheral clocks per CAN bit as described in (see ).This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - FIFO enabled
 * 0 - FIFO not enabled
 */

#define BP_FLEXCAN_MCR_RFEN      29
#define BM_FLEXCAN_MCR_RFEN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_RFEN(v)   ((((reg32_t) v) << 29) & BM_FLEXCAN_MCR_RFEN)
#else
#define BF_FLEXCAN_MCR_RFEN(v)   (((v) << 29) & BM_FLEXCAN_MCR_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFEN field to a new value.
#define BW_FLEXCAN_MCR_RFEN(v)   BF_CS1(FLEXCAN_MCR, RFEN, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field FRZ (RW)
 *
 * The FRZ bit specifies the FLEXCAN behavior when the HALT bit in the MCR Register is set or when
 * Debug Mode is requested at ARM level . When FRZ is asserted, FLEXCAN is enabled to enter Freeze
 * Mode {flexcan2_ipi_slv_flex_freezemode} . Negation of this bit field causes FLEXCAN to exit from
 * Freeze Mode {flexcan2_ipi_slv_flex_freezemode} .
 *
 * Values:
 * 1 - Enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 * 0 - Not enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_FRZ      30
#define BM_FLEXCAN_MCR_FRZ      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_FRZ(v)   ((((reg32_t) v) << 30) & BM_FLEXCAN_MCR_FRZ)
#else
#define BF_FLEXCAN_MCR_FRZ(v)   (((v) << 30) & BM_FLEXCAN_MCR_FRZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRZ field to a new value.
#define BW_FLEXCAN_MCR_FRZ(v)   BF_CS1(FLEXCAN_MCR, FRZ, v)
#endif


/* --- Register HW_FLEXCAN_MCR, field MDIS (RW)
 *
 * This bit controls whether FLEXCAN is enabled or not {flexcan2_ipi_slv_flex_disablemode} . When
 * disabled, FLEXCAN shuts down the clocks to the CAN Protocol Interface and Message Buffer
 * Management sub-modules {flexcan2_ipi_slv_flex_disablemode} . This is the only bit in MCR not
 * affected by soft reset {flexcan2_ipi_slv_flex_softreset} . {statement} See for more information.
 * {Statement}
 *
 * Values:
 * 1 - Disable the FLEXCAN module {flexcan2_ipi_slv_flex_disablemode}
 * 0 - Enable the FLEXCAN module {flexcan2_ipi_slv_flex_disablemode}
 */

#define BP_FLEXCAN_MCR_MDIS      31
#define BM_FLEXCAN_MCR_MDIS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_MCR_MDIS(v)   ((((reg32_t) v) << 31) & BM_FLEXCAN_MCR_MDIS)
#else
#define BF_FLEXCAN_MCR_MDIS(v)   (((v) << 31) & BM_FLEXCAN_MCR_MDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MDIS field to a new value.
#define BW_FLEXCAN_MCR_MDIS(v)   BF_CS1(FLEXCAN_MCR, MDIS, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_CTRL1 - Control 1 Register (RW)
 *
 * This register is defined for specific FLEXCAN control features related to the CAN bus, such as
 * bit-rate, programmable sampling point within an Rx bit, Loop Back Mode, Listen Only Mode, Bus Off
 * recovery behavior and interrupt enabling (Bus-Off, Error, Warning) {statement} . It also
 * determines the Division Factor for the clock prescaler. {flexcan2_ipi_slv_can_timing_parameters}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PROP_SEG : 3; //!< This 3-bit field defines the length of the Propagation Segment in the bit time {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0-7. {flexcan2_ipi_slv_can_timing_parameters} This field can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} Propagation Segment Time = (PROPSEG + 1) * Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters} Time-Quantum = one Sclock period. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned LOM : 1; //!< This bit configures FLEXCAN to operate in Listen Only Mode {flexcan2_ipi_slv_flex_lomode} . In this mode, transmission is disabled, all error counters are frozen and the module operates in a CAN Error Passive mode {flexcan2_ipi_slv_flex_lomode} . Only messages acknowledged by another CAN station will be received {flexcan2_ipi_slv_flex_lomode} . If FLEXCAN detects a message that has not been acknowledged, it will flag a BIT0 error (without changing the REC), as if it was trying to acknowledge the message {flexcan2_ipi_slv_flex_lomode} . Listen-Only Mode acknowledgement can be obtained by the state of ESR1[FLT_CONF] field which is Passive Error when Listen-Only Mode is entered {can_protocol_model,FlexCAN3IPSRpsCkr} . There can be some delay between the Listen-Only Mode request and acknowledge. {FlexCAN3ModesStim_todo,FlexCAN3IPSRpsCkr} This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned LBUF : 1; //!< This bit defines the ordering mechanism for Message Buffer transmission. When asserted, the LPRIO_EN bit does not affect the priority arbitration. {flexcan2_ipi_slv_flex_reg_ctrl_lbuf} This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned TSYN : 1; //!< This bit enables a mechanism that resets the free-running timer each time a message is received in Message Buffer 0 {flexcan2_ipi_slv_flex_reg_ctrl_tsyn} . This feature provides means to synchronize multiple FLEXCAN stations with a special "SYNC" message (i.e., global network time). {statement} If the RFEN bit in MCR is set (FIFO enabled), the first available Mailbox, according to CTRL2[RFFN] setting, is used for timer synchronization instead of MB0.This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned BOFF_REC : 1; //!< This bit defines how FLEXCAN recovers from Bus Off state. {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} If this bit is negated, automatic recovering from Bus Off state occurs according to the CAN Specification 2.0B {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the bit is asserted, automatic recovering from Bus Off is disabled and the module remains in Bus Off state until the bit is negated by the user {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs before 128 sequences of 11 recessive bits are detected on the CAN bus, then Bus Off recovery happens as if the BOFF_REC bit had never been asserted {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs after 128 sequences of 11 recessive bits occurred, then FLEXCAN will re-synchronize to the bus by waiting for 11 recessive bits before joining the bus {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . After negation, the BOFF_REC bit can be re-asserted again during Bus Off, but it will only be effective the next time the module enters Bus Off {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If BOFF_REC was negated when the module entered Bus Off, asserting it during Bus Off will not be effective for the current Bus Off recovery {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} .
        unsigned SMP : 1; //!< This bit defines the sampling mode of CAN bits at the Rx input {Statement} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim}
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned RWRN_MSK : 1; //!< This bit provides a mask for the Rx Warning Interrupt associated with the RWRN_INT flag in the Error and Status Register {Statement} . This bit is read as zero when MCR[WRN_EN] bit is negated. This bit can only be written if MCR[WRN_EN] bit is asserted.
        unsigned TWRN_MSK : 1; //!< This bit provides a mask for the Tx Warning Interrupt associated with the TWRN_INT flag in the Error and Status Register {Statement} . This bit is read as zero when MCR[WRN_EN] bit is negated. This bit can only be written if MCR[WRN_EN] bit is asserted.
        unsigned LPB : 1; //!< This bit configures FlexCAN to operate in Loop-Back Mode {Statement} . In this mode, FlexCAN performs an internal loop back that can be used for self test operation {Statement} . The bit stream output of the transmitter is fed back internally to the receiver input {Statement} . The Rx CAN input pin is ignored and the Tx CAN output goes to the recessive state (logic '1') {assert_lpb_mode} . FlexCAN behaves as it normally does when transmitting, and treats its own transmitted message as a message received from a remote node {FlexCAN3RxRpsCkr} . In this mode, FlexCAN ignores the bit sent during the ACK slot in the CAN frame acknowledge field, generating an internal acknowledge bit to ensure proper reception of its own message {FlexCAN3RxRpsCkr} . Both transmit and receive interrupts are generated {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ERR_MSK : 1; //!< This bit provides a mask for the Error Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned BOFF_MSK : 1; //!< This bit provides a mask for the Bus Off Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned PSEG2 : 3; //!< This 3-bit field defines the length of Phase Buffer Segment 2 in the bit time {Statement} . The valid programmable values are 1 - 7 {cover_pseg2} . This field can only be written in Freeze mode as it is blocked by hardware in other modes Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned PSEG1 : 3; //!< This 3-bit field defines the length of Phase Buffer Segment 1 in the bit time {Statement} . The valid programmable values are 0 - 7 {cover_pseg1} . This field can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim}{flexcan2_ipi_slv_can_timing_parameters} Phase Buffer Segment 1 = (PSEG1 + 1) x Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned RJW : 2; //!< This 2-bit field defines the maximum number of time quanta One time quantum is equal to the Sclock period. {Statement} that a bit time can be changed by one re-synchronization {Statement} . The valid programmable values are 0 - 3 {cover_rjw} . This field can only be written in Freeze mode as it is blocked by hardware in other modes Resync Jump Width = RJW + 1. {flexcan2_ipi_slv_can_timing_resynchronization}
        unsigned PRESDIV : 8; //!< This 8-bit field defines the ratio between the PE clock frequency and the Serial Clock (Sclock) frequency {Statement} . The Sclock period defines the time quantum of the CAN protocol {Statement} . For the reset value, the Sclock frequency is equal to the PE clock frequency {cover_presdiv} . The Maximum value of this register is 0xFF, that gives a minimum Sclock frequency equal to the PE clock frequency divided by 256.For more information refer to . This field can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} . Sclock frequency = CPI clock frequency / (PRESDIV+1) {flexcan2_ipi_slv_can_timing_parameters}
    } B;
} hw_flexcan_ctrl1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CTRL1 register
 */
#define HW_FLEXCAN_CTRL1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CTRL1(x)           (*(volatile hw_flexcan_ctrl1_t *) HW_FLEXCAN_CTRL1_ADDR(x))
#define HW_FLEXCAN_CTRL1_RD(x)        (HW_FLEXCAN_CTRL1(x).U)
#define HW_FLEXCAN_CTRL1_WR(x, v)     (HW_FLEXCAN_CTRL1(x).U = (v))
#define HW_FLEXCAN_CTRL1_SET(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) |  (v)))
#define HW_FLEXCAN_CTRL1_CLR(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) & ~(v)))
#define HW_FLEXCAN_CTRL1_TOG(x, v)    (HW_FLEXCAN_CTRL1_WR(x, HW_FLEXCAN_CTRL1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_CTRL1 bitfields
 */

/* --- Register HW_FLEXCAN_CTRL1, field PROP_SEG (RW)
 *
 * This 3-bit field defines the length of the Propagation Segment in the bit time
 * {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0-7.
 * {flexcan2_ipi_slv_can_timing_parameters} This field can only be written in Freeze mode as it is
 * blocked by hardware in other modes {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} Propagation Segment
 * Time = (PROPSEG + 1) * Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters} Time-Quantum = one
 * Sclock period. {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL1_PROP_SEG      0
#define BM_FLEXCAN_CTRL1_PROP_SEG      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PROP_SEG(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_CTRL1_PROP_SEG)
#else
#define BF_FLEXCAN_CTRL1_PROP_SEG(v)   (((v) << 0) & BM_FLEXCAN_CTRL1_PROP_SEG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_SEG field to a new value.
#define BW_FLEXCAN_CTRL1_PROP_SEG(v)   BF_CS1(FLEXCAN_CTRL1, PROP_SEG, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field LOM (RW)
 *
 * This bit configures FLEXCAN to operate in Listen Only Mode {flexcan2_ipi_slv_flex_lomode} . In
 * this mode, transmission is disabled, all error counters are frozen and the module operates in a
 * CAN Error Passive mode {flexcan2_ipi_slv_flex_lomode} . Only messages acknowledged by another CAN
 * station will be received {flexcan2_ipi_slv_flex_lomode} . If FLEXCAN detects a message that has
 * not been acknowledged, it will flag a BIT0 error (without changing the REC), as if it was trying
 * to acknowledge the message {flexcan2_ipi_slv_flex_lomode} . Listen-Only Mode acknowledgement can
 * be obtained by the state of ESR1[FLT_CONF] field which is Passive Error when Listen-Only Mode is
 * entered {can_protocol_model,FlexCAN3IPSRpsCkr} . There can be some delay between the Listen-Only
 * Mode request and acknowledge. {FlexCAN3ModesStim_todo,FlexCAN3IPSRpsCkr} This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - FLEXCAN module operates in Listen Only Mode {flexcan2_ipi_slv_flex_lomode}
 * 0 - Listen Only Mode is deactivated {flexcan2_ipi_slv_flex_lomode}
 */

#define BP_FLEXCAN_CTRL1_LOM      3
#define BM_FLEXCAN_CTRL1_LOM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LOM(v)   ((((reg32_t) v) << 3) & BM_FLEXCAN_CTRL1_LOM)
#else
#define BF_FLEXCAN_CTRL1_LOM(v)   (((v) << 3) & BM_FLEXCAN_CTRL1_LOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOM field to a new value.
#define BW_FLEXCAN_CTRL1_LOM(v)   BF_CS1(FLEXCAN_CTRL1, LOM, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field LBUF (RW)
 *
 * This bit defines the ordering mechanism for Message Buffer transmission. When asserted, the
 * LPRIO_EN bit does not affect the priority arbitration. {flexcan2_ipi_slv_flex_reg_ctrl_lbuf} This
 * bit can only be written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Lowest number buffer is transmitted first {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
 * 0 - Buffer with highest priority is transmitted first {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
 */

#define BP_FLEXCAN_CTRL1_LBUF      4
#define BM_FLEXCAN_CTRL1_LBUF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LBUF(v)   ((((reg32_t) v) << 4) & BM_FLEXCAN_CTRL1_LBUF)
#else
#define BF_FLEXCAN_CTRL1_LBUF(v)   (((v) << 4) & BM_FLEXCAN_CTRL1_LBUF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LBUF field to a new value.
#define BW_FLEXCAN_CTRL1_LBUF(v)   BF_CS1(FLEXCAN_CTRL1, LBUF, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field TSYN (RW)
 *
 * This bit enables a mechanism that resets the free-running timer each time a message is received
 * in Message Buffer 0 {flexcan2_ipi_slv_flex_reg_ctrl_tsyn} . This feature provides means to
 * synchronize multiple FLEXCAN stations with a special "SYNC" message (i.e., global network time).
 * {statement} If the RFEN bit in MCR is set (FIFO enabled), the first available Mailbox, according
 * to CTRL2[RFFN] setting, is used for timer synchronization instead of MB0.This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Timer Sync feature enabled {flexcan2_ipi_slv_flex_reg_ctrl_tsyn}
 * 0 - Timer Sync feature disabled {flexcan2_ipi_slv_flex_reg_ctrl_tsyn}
 */

#define BP_FLEXCAN_CTRL1_TSYN      5
#define BM_FLEXCAN_CTRL1_TSYN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_TSYN(v)   ((((reg32_t) v) << 5) & BM_FLEXCAN_CTRL1_TSYN)
#else
#define BF_FLEXCAN_CTRL1_TSYN(v)   (((v) << 5) & BM_FLEXCAN_CTRL1_TSYN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TSYN field to a new value.
#define BW_FLEXCAN_CTRL1_TSYN(v)   BF_CS1(FLEXCAN_CTRL1, TSYN, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field BOFF_REC (RW)
 *
 * This bit defines how FLEXCAN recovers from Bus Off state.
 * {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} If this bit is negated, automatic recovering from Bus
 * Off state occurs according to the CAN Specification 2.0B {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 * . If the bit is asserted, automatic recovering from Bus Off is disabled and the module remains in
 * Bus Off state until the bit is negated by the user {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If
 * the negation occurs before 128 sequences of 11 recessive bits are detected on the CAN bus, then
 * Bus Off recovery happens as if the BOFF_REC bit had never been asserted
 * {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs after 128 sequences of 11
 * recessive bits occurred, then FLEXCAN will re-synchronize to the bus by waiting for 11 recessive
 * bits before joining the bus {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . After negation, the
 * BOFF_REC bit can be re-asserted again during Bus Off, but it will only be effective the next time
 * the module enters Bus Off {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If BOFF_REC was negated when
 * the module entered Bus Off, asserting it during Bus Off will not be effective for the current Bus
 * Off recovery {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} .
 *
 * Values:
 * 1 - Automatic recovering from Bus Off state disabled {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 * 0 - Automatic recovering from Bus Off state enabled, according to CAN Spec 2.0 part B
 *     {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 */

#define BP_FLEXCAN_CTRL1_BOFF_REC      6
#define BM_FLEXCAN_CTRL1_BOFF_REC      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_BOFF_REC(v)   ((((reg32_t) v) << 6) & BM_FLEXCAN_CTRL1_BOFF_REC)
#else
#define BF_FLEXCAN_CTRL1_BOFF_REC(v)   (((v) << 6) & BM_FLEXCAN_CTRL1_BOFF_REC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_REC field to a new value.
#define BW_FLEXCAN_CTRL1_BOFF_REC(v)   BF_CS1(FLEXCAN_CTRL1, BOFF_REC, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field SMP (RW)
 *
 * This bit defines the sampling mode of CAN bits at the Rx input {Statement} . This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim}
 *
 * Values:
 * 1 - Three samples are used to determine the value of the received bit: the regular one (sample point)
 *     and 2 preceding samples, a majority rule is used {flexcan2_ipi_slv_flex_reg_ctrl_smp}
 * 0 - Just one sample is used to determine the bit value {flexcan2_ipi_slv_flex_reg_ctrl_smp}
 */

#define BP_FLEXCAN_CTRL1_SMP      7
#define BM_FLEXCAN_CTRL1_SMP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_SMP(v)   ((((reg32_t) v) << 7) & BM_FLEXCAN_CTRL1_SMP)
#else
#define BF_FLEXCAN_CTRL1_SMP(v)   (((v) << 7) & BM_FLEXCAN_CTRL1_SMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SMP field to a new value.
#define BW_FLEXCAN_CTRL1_SMP(v)   BF_CS1(FLEXCAN_CTRL1, SMP, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field RWRN_MSK (RW)
 *
 * This bit provides a mask for the Rx Warning Interrupt associated with the RWRN_INT flag in the
 * Error and Status Register {Statement} . This bit is read as zero when MCR[WRN_EN] bit is negated.
 * This bit can only be written if MCR[WRN_EN] bit is asserted.
 *
 * Values:
 * 1 - Rx Warning Interrupt enabled
 * 0 - Rx Warning Interrupt disabled
 */

#define BP_FLEXCAN_CTRL1_RWRN_MSK      10
#define BM_FLEXCAN_CTRL1_RWRN_MSK      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_RWRN_MSK(v)   ((((reg32_t) v) << 10) & BM_FLEXCAN_CTRL1_RWRN_MSK)
#else
#define BF_FLEXCAN_CTRL1_RWRN_MSK(v)   (((v) << 10) & BM_FLEXCAN_CTRL1_RWRN_MSK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWRN_MSK field to a new value.
#define BW_FLEXCAN_CTRL1_RWRN_MSK(v)   BF_CS1(FLEXCAN_CTRL1, RWRN_MSK, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field TWRN_MSK (RW)
 *
 * This bit provides a mask for the Tx Warning Interrupt associated with the TWRN_INT flag in the
 * Error and Status Register {Statement} . This bit is read as zero when MCR[WRN_EN] bit is negated.
 * This bit can only be written if MCR[WRN_EN] bit is asserted.
 *
 * Values:
 * 1 - Tx Warning Interrupt enabled
 * 0 - Tx Warning Interrupt disabled
 */

#define BP_FLEXCAN_CTRL1_TWRN_MSK      11
#define BM_FLEXCAN_CTRL1_TWRN_MSK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_TWRN_MSK(v)   ((((reg32_t) v) << 11) & BM_FLEXCAN_CTRL1_TWRN_MSK)
#else
#define BF_FLEXCAN_CTRL1_TWRN_MSK(v)   (((v) << 11) & BM_FLEXCAN_CTRL1_TWRN_MSK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TWRN_MSK field to a new value.
#define BW_FLEXCAN_CTRL1_TWRN_MSK(v)   BF_CS1(FLEXCAN_CTRL1, TWRN_MSK, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field LPB (RW)
 *
 * This bit configures FlexCAN to operate in Loop-Back Mode {Statement} . In this mode, FlexCAN
 * performs an internal loop back that can be used for self test operation {Statement} . The bit
 * stream output of the transmitter is fed back internally to the receiver input {Statement} . The
 * Rx CAN input pin is ignored and the Tx CAN output goes to the recessive state (logic '1')
 * {assert_lpb_mode} . FlexCAN behaves as it normally does when transmitting, and treats its own
 * transmitted message as a message received from a remote node {FlexCAN3RxRpsCkr} . In this mode,
 * FlexCAN ignores the bit sent during the ACK slot in the CAN frame acknowledge field, generating
 * an internal acknowledge bit to ensure proper reception of its own message {FlexCAN3RxRpsCkr} .
 * Both transmit and receive interrupts are generated {FlexCAN3RxRpsCkr} . This bit can only be
 * written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Loop Back enabled {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
 * 0 - Loop Back disabled {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
 */

#define BP_FLEXCAN_CTRL1_LPB      12
#define BM_FLEXCAN_CTRL1_LPB      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_LPB(v)   ((((reg32_t) v) << 12) & BM_FLEXCAN_CTRL1_LPB)
#else
#define BF_FLEXCAN_CTRL1_LPB(v)   (((v) << 12) & BM_FLEXCAN_CTRL1_LPB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LPB field to a new value.
#define BW_FLEXCAN_CTRL1_LPB(v)   BF_CS1(FLEXCAN_CTRL1, LPB, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field ERR_MSK (RW)
 *
 * This bit provides a mask for the Error Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 1 - Error interrupt enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - Error interrupt disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_CTRL1_ERR_MSK      14
#define BM_FLEXCAN_CTRL1_ERR_MSK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_ERR_MSK(v)   ((((reg32_t) v) << 14) & BM_FLEXCAN_CTRL1_ERR_MSK)
#else
#define BF_FLEXCAN_CTRL1_ERR_MSK(v)   (((v) << 14) & BM_FLEXCAN_CTRL1_ERR_MSK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_MSK field to a new value.
#define BW_FLEXCAN_CTRL1_ERR_MSK(v)   BF_CS1(FLEXCAN_CTRL1, ERR_MSK, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field BOFF_MSK (RW)
 *
 * This bit provides a mask for the Bus Off Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 1 - Bus Off interrupt enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - Bus Off interrupt disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_CTRL1_BOFF_MSK      15
#define BM_FLEXCAN_CTRL1_BOFF_MSK      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_BOFF_MSK(v)   ((((reg32_t) v) << 15) & BM_FLEXCAN_CTRL1_BOFF_MSK)
#else
#define BF_FLEXCAN_CTRL1_BOFF_MSK(v)   (((v) << 15) & BM_FLEXCAN_CTRL1_BOFF_MSK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_MSK field to a new value.
#define BW_FLEXCAN_CTRL1_BOFF_MSK(v)   BF_CS1(FLEXCAN_CTRL1, BOFF_MSK, v)
#endif


/* --- Register HW_FLEXCAN_CTRL1, field PSEG2 (RW)
 *
 * This 3-bit field defines the length of Phase Buffer Segment 2 in the bit time {Statement} . The
 * valid programmable values are 1 - 7 {cover_pseg2} . This field can only be written in Freeze mode
 * as it is blocked by hardware in other modes Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta.
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL1_PSEG2      16
#define BM_FLEXCAN_CTRL1_PSEG2      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PSEG2(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_CTRL1_PSEG2)
#else
#define BF_FLEXCAN_CTRL1_PSEG2(v)   (((v) << 16) & BM_FLEXCAN_CTRL1_PSEG2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSEG2 field to a new value.
#define BW_FLEXCAN_CTRL1_PSEG2(v)   BF_CS1(FLEXCAN_CTRL1, PSEG2, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field PSEG1 (RW)
 *
 * This 3-bit field defines the length of Phase Buffer Segment 1 in the bit time {Statement} . The
 * valid programmable values are 0 - 7 {cover_pseg1} . This field can only be written in Freeze mode
 * as it is blocked by hardware in other modes
 * {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim}{flexcan2_ipi_slv_can_timing_parameters} Phase Buffer
 * Segment 1 = (PSEG1 + 1) x Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL1_PSEG1      19
#define BM_FLEXCAN_CTRL1_PSEG1      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PSEG1(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_CTRL1_PSEG1)
#else
#define BF_FLEXCAN_CTRL1_PSEG1(v)   (((v) << 19) & BM_FLEXCAN_CTRL1_PSEG1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSEG1 field to a new value.
#define BW_FLEXCAN_CTRL1_PSEG1(v)   BF_CS1(FLEXCAN_CTRL1, PSEG1, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field RJW (RW)
 *
 * This 2-bit field defines the maximum number of time quanta One time quantum is equal to the
 * Sclock period. {Statement} that a bit time can be changed by one re-synchronization {Statement} .
 * The valid programmable values are 0 - 3 {cover_rjw} . This field can only be written in Freeze
 * mode as it is blocked by hardware in other modes Resync Jump Width = RJW + 1.
 * {flexcan2_ipi_slv_can_timing_resynchronization}
 */

#define BP_FLEXCAN_CTRL1_RJW      22
#define BM_FLEXCAN_CTRL1_RJW      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_RJW(v)   ((((reg32_t) v) << 22) & BM_FLEXCAN_CTRL1_RJW)
#else
#define BF_FLEXCAN_CTRL1_RJW(v)   (((v) << 22) & BM_FLEXCAN_CTRL1_RJW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RJW field to a new value.
#define BW_FLEXCAN_CTRL1_RJW(v)   BF_CS1(FLEXCAN_CTRL1, RJW, v)
#endif

/* --- Register HW_FLEXCAN_CTRL1, field PRESDIV (RW)
 *
 * This 8-bit field defines the ratio between the PE clock frequency and the Serial Clock (Sclock)
 * frequency {Statement} . The Sclock period defines the time quantum of the CAN protocol
 * {Statement} . For the reset value, the Sclock frequency is equal to the PE clock frequency
 * {cover_presdiv} . The Maximum value of this register is 0xFF, that gives a minimum Sclock
 * frequency equal to the PE clock frequency divided by 256.For more information refer to . This
 * field can only be written in Freeze mode as it is blocked by hardware in other modes
 * {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} . Sclock frequency = CPI clock frequency / (PRESDIV+1)
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL1_PRESDIV      24
#define BM_FLEXCAN_CTRL1_PRESDIV      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL1_PRESDIV(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_CTRL1_PRESDIV)
#else
#define BF_FLEXCAN_CTRL1_PRESDIV(v)   (((v) << 24) & BM_FLEXCAN_CTRL1_PRESDIV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESDIV field to a new value.
#define BW_FLEXCAN_CTRL1_PRESDIV(v)   BF_CS1(FLEXCAN_CTRL1, PRESDIV, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_TIMER - Free Running Timer Register (RW)
 *
 * This register represents a 16-bit free running counter that can be read and written by the ARM
 * {flexcan2_ipi_slv_flex_reg_timer} . The timer starts from $0000 after Reset, counts linearly to
 * $FFFF, and wraps around. {flexcan2_ipi_slv_flex_reg_timer}  The timer is clocked by the FLEXCAN
 * bit-clock (which defines the baud rate on the CAN bus) {flexcan2_ipi_slv_flex_reg_timer} . During
 * a message transmission/reception, it increments by one for each bit that is received or
 * transmitted {flexcan2_ipi_slv_flex_reg_timer} . When there is no message on the bus, it counts
 * using the previously programmed baud rate. {flexcan2_ipi_slv_flex_reg_timer} During Freeze Mode,
 * disable, and stop mode, the timer is not incremented {flexcan2_ipi_slv_flex_reg_timer} .  The
 * timer value is captured at the beginning of the identifier field of any frame on the CAN bus
 * {flexcan2_ipi_slv_flex_reg_timer} . This captured value is written into the Time Stamp entry in a
 * message buffer after a successful reception or transmission of a message.
 * {flexcan2_ipi_slv_flex_reg_timer}  If bit CTRL1[TSYN] is asserted the Timer is reset whenever a
 * message is received in the first available Mailbox, according to CTRL2[RFFN] setting.  ARM can
 * write to this register anytime {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . However, if the write
 * occurs at the same time that the Timer is being reset by a reception in the first Mailbox, then
 * the write value is discarded.  Reading this register affects the Mailbox Unlocking procedure
 * {FlexCAN3RxRpsCkr} . For additional details, refer to . {Statement}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TIMER : 16; //!< TIMER
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_flexcan_timer_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_TIMER register
 */
#define HW_FLEXCAN_TIMER_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_TIMER(x)           (*(volatile hw_flexcan_timer_t *) HW_FLEXCAN_TIMER_ADDR(x))
#define HW_FLEXCAN_TIMER_RD(x)        (HW_FLEXCAN_TIMER(x).U)
#define HW_FLEXCAN_TIMER_WR(x, v)     (HW_FLEXCAN_TIMER(x).U = (v))
#define HW_FLEXCAN_TIMER_SET(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) |  (v)))
#define HW_FLEXCAN_TIMER_CLR(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) & ~(v)))
#define HW_FLEXCAN_TIMER_TOG(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_TIMER bitfields
 */

/* --- Register HW_FLEXCAN_TIMER, field TIMER (RW)
 *
 * TIMER
 */

#define BP_FLEXCAN_TIMER_TIMER      0
#define BM_FLEXCAN_TIMER_TIMER      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_TIMER_TIMER(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_TIMER_TIMER)
#else
#define BF_FLEXCAN_TIMER_TIMER(v)   (((v) << 0) & BM_FLEXCAN_TIMER_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMER field to a new value.
#define BW_FLEXCAN_TIMER_TIMER(v)   BF_CS1(FLEXCAN_TIMER, TIMER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RXMGMASK - Rx Mailboxes Global Mask Register (RW)
 *
 * RXMGMASK is provided for legacy support. Asserting the MCR[IRMQ] bit causes the RXMGMASK Register
 * to have no effect on the module operation {FlexCAN3RxMaskStim,FlexCAN3RxRpsCkr} .  In Enhanced
 * Mode, RXMGMASK is used to mask the filter fields of all Rx MBs, excluding MBs 14-15, which have
 * individual mask registers {FlexCAN3RxMaskStim,FlexCAN3RxRpsCkr} . For MCUs not supporting Mailbox
 * ID Filter Masks, when CTRL3[MBFEN] bit is set the RXMGMASK also applies to all elements of the
 * Mailbox ID Filters {Functional Test} . PRL v0.5 ref 2.08 {Statement}  This register can only be
 * written in Freeze mode as it is blocked by hardware in other modes.   Rx Mailboxes Global Mask
 * usage in Legacy Mode {Statement}            SMB[RTR] RTR bit of the Incoming Frame. It is saved
 * into an auxiliary MB called Rx Serial Message Buffer (Rx SMB).
 * {FlexCAN3RxMatchFrame,FlexCAN3RxRpsCkr}   CTRL2[RRS]  CTRL2[EACEN]  Mailbox filter fields
 * MB[RTR]  MB[IDE]  MB[ID]  reserved      0  -  0  - Note If CTRL2[EACEN] bit is negated the RTR
 * bit of Mailbox is never compared with the RTR bit of the Incoming Frame (Rx SMB[RTR]).
 * {FlexCAN3RxMatchFrame,FlexCAN3RxRpsCkr}   - Note If CTRL2[EACEN] bit is negated the IDE bit of
 * Mailbox is always compared with the IDE bit of the Incoming Frame (Rx SMB[IDE]).
 * {FlexCAN3RxMatchFrame,FlexCAN3RxRpsCkr}   MG[ 28:0 3:31 ]  MG[ 31:29 0:3 ]    0  -  1  MG[ 31 0 ]
 * MG[ 30 1 ]  MG[ 28:0 3:31 ]  MG[ 29 2 ]    1  0  -  -  -  -  MG[ 31:0 0:31 ]    1  1  0  -  -
 * MG[ 28:0 3:31 ]  MG[ 31:29 0:3 ]    1  1  1  MG[ 31 0 ]  MG[ 30 1 ]  MG[ 28:0 3:31 ]  MG[ 29 2 ]
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MG31 : 32; //!< These bits mask the Mailbox filter bits as shown in the figure above {Statement} . Note that the alignment with the ID word of the Mailbox is not perfect as the two most significant MG bits affect the fields RTR and IDE which are located in the Control and Status word of the Mailbox {FlexCAN3RxMaskStim,FlexCAN3RegAccessStim,FlexCAN3MemAccessStim,FlexCAN3RxRpsCkr} . shows in detail which MG bits mask each Mailbox filter field.
    } B;
} hw_flexcan_rxmgmask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXMGMASK register
 */
#define HW_FLEXCAN_RXMGMASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXMGMASK(x)           (*(volatile hw_flexcan_rxmgmask_t *) HW_FLEXCAN_RXMGMASK_ADDR(x))
#define HW_FLEXCAN_RXMGMASK_RD(x)        (HW_FLEXCAN_RXMGMASK(x).U)
#define HW_FLEXCAN_RXMGMASK_WR(x, v)     (HW_FLEXCAN_RXMGMASK(x).U = (v))
#define HW_FLEXCAN_RXMGMASK_SET(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) |  (v)))
#define HW_FLEXCAN_RXMGMASK_CLR(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RXMGMASK_TOG(x, v)    (HW_FLEXCAN_RXMGMASK_WR(x, HW_FLEXCAN_RXMGMASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RXMGMASK bitfields
 */

/* --- Register HW_FLEXCAN_RXMGMASK, field MG31 (RW)
 *
 * These bits mask the Mailbox filter bits as shown in the figure above {Statement} . Note that the
 * alignment with the ID word of the Mailbox is not perfect as the two most significant MG bits
 * affect the fields RTR and IDE which are located in the Control and Status word of the Mailbox
 * {FlexCAN3RxMaskStim,FlexCAN3RegAccessStim,FlexCAN3MemAccessStim,FlexCAN3RxRpsCkr} . shows in
 * detail which MG bits mask each Mailbox filter field.
 *
 * Values:
 * 0 - the corresponding bit in the filter is "don't care"
 * 1 - The corresponding bit in the filter is checked against the one received
 */

#define BP_FLEXCAN_RXMGMASK_MG31      0
#define BM_FLEXCAN_RXMGMASK_MG31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXMGMASK_MG31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXMGMASK_MG31)
#else
#define BF_FLEXCAN_RXMGMASK_MG31(v)   (((v) << 0) & BM_FLEXCAN_RXMGMASK_MG31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MG31 field to a new value.
#define BW_FLEXCAN_RXMGMASK_MG31(v)   BF_CS1(FLEXCAN_RXMGMASK, MG31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX14MASK - Rx Buffer 14 Mask Register (RW)
 *
 * RX14MASK is provided for legacy support, asserting the MCR[IRMQ] bit causes the RX14MASK to have
 * no effect on the module operation
 * {FlexCAN3RxMaskStim,FlexCAN3RegAccessStim,FlexCAN3MemAccessStim,FlexCAN3RxRpsCkr} .  RX14MASK is
 * used to mask the filter fields of Message Buffer 14 {Statement} .  This register can only be
 * programmed while the module is in Freeze Mode as it is blocked by hardware in other modes
 * {FlexCAN3MemAccessStim,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim}{flexcan2_ipi_slv_flex_reg_rxmask}
 * .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX14M31 : 32; //!< These bits mask Mailbox 14 filter bits in the same fashion as RXMGMASK masks other Mailboxes filters (see )
    } B;
} hw_flexcan_rx14mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX14MASK register
 */
#define HW_FLEXCAN_RX14MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX14MASK(x)           (*(volatile hw_flexcan_rx14mask_t *) HW_FLEXCAN_RX14MASK_ADDR(x))
#define HW_FLEXCAN_RX14MASK_RD(x)        (HW_FLEXCAN_RX14MASK(x).U)
#define HW_FLEXCAN_RX14MASK_WR(x, v)     (HW_FLEXCAN_RX14MASK(x).U = (v))
#define HW_FLEXCAN_RX14MASK_SET(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX14MASK_CLR(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX14MASK_TOG(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX14MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX14MASK, field RX14M31 (RW)
 *
 * These bits mask Mailbox 14 filter bits in the same fashion as RXMGMASK masks other Mailboxes
 * filters (see )
 *
 * Values:
 * 0 - the corresponding bit in the filter is "don't care"
 * 1 - The corresponding bit in the filter is checked
 */

#define BP_FLEXCAN_RX14MASK_RX14M31      0
#define BM_FLEXCAN_RX14MASK_RX14M31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RX14MASK_RX14M31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RX14MASK_RX14M31)
#else
#define BF_FLEXCAN_RX14MASK_RX14M31(v)   (((v) << 0) & BM_FLEXCAN_RX14MASK_RX14M31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX14M31 field to a new value.
#define BW_FLEXCAN_RX14MASK_RX14M31(v)   BF_CS1(FLEXCAN_RX14MASK, RX14M31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX15MASK - Rx Buffer 15 Mask Register (RW)
 *
 * RX15MASK is provided for legacy support, asserting the MCR[IRMQ] bit causes the RX15MASK Register
 * to have no effect on the module operation.
 * {FlexCAN3RxMaskStim,FlexCAN3MemAccessStim,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim}  RX15MASK is
 * used to mask the filter fields of Message Buffer 15 {Statement} .  This register can only be
 * programmed while the module is in Freeze Mode as it is blocked by hardware in other modes
 * {FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} .  {flexcan2_ipi_slv_flex_reg_access}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RX15M31 : 32; //!< These bits mask Mailbox 15 filter bits in the same fashion as RXMGMASK masks other Mailboxes filters (see ).
    } B;
} hw_flexcan_rx15mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX15MASK register
 */
#define HW_FLEXCAN_RX15MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX15MASK(x)           (*(volatile hw_flexcan_rx15mask_t *) HW_FLEXCAN_RX15MASK_ADDR(x))
#define HW_FLEXCAN_RX15MASK_RD(x)        (HW_FLEXCAN_RX15MASK(x).U)
#define HW_FLEXCAN_RX15MASK_WR(x, v)     (HW_FLEXCAN_RX15MASK(x).U = (v))
#define HW_FLEXCAN_RX15MASK_SET(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX15MASK_CLR(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX15MASK_TOG(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX15MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX15MASK, field RX15M31 (RW)
 *
 * These bits mask Mailbox 15 filter bits in the same fashion as RXMGMASK masks other Mailboxes
 * filters (see ).
 *
 * Values:
 * 0 - the corresponding bit in the filter is "don't care"
 * 1 - The corresponding bit in the filter is checked
 */

#define BP_FLEXCAN_RX15MASK_RX15M31      0
#define BM_FLEXCAN_RX15MASK_RX15M31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RX15MASK_RX15M31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RX15MASK_RX15M31)
#else
#define BF_FLEXCAN_RX15MASK_RX15M31(v)   (((v) << 0) & BM_FLEXCAN_RX15MASK_RX15M31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX15M31 field to a new value.
#define BW_FLEXCAN_RX15MASK_RX15M31(v)   BF_CS1(FLEXCAN_RX15MASK, RX15M31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_ECR - Error Counter Register (RW)
 *
 * This register has 2 8-bit fields reflecting the value of two FLEXCAN error counters: Transmit
 * Error Counter (Tx_Err_Counter field) and Receive Error Counter (Rx_Err_Counter field)
 * {flexcan2_ipi_slv_can_counters_tx}{flexcan2_ipi_slv_can_counters_rx} . The rules for increasing
 * and decreasing these counters are described in the CAN protocol and are completely implemented in
 * the FLEXCAN module {flexcan2_ipi_slv_can_counters_tx}{flexcan2_ipi_slv_can_counters_rx} . Both
 * counters are read only except in Test Mode or Freeze Mode, where they can be written by the ARM.
 * {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_reg_test}  FLEXCAN responds to any bus
 * state as described in the protocol {statement} , e.g. transmit 'Error Active' or 'Error Passive'
 * flag, delay its transmission start time ('Error Passive') and avoid any influence on the bus when
 * in 'Bus Off' state {statement} . The following are the basic rules for FLEXCAN bus state
 * transitions. {statement}   If the value of Tx_Err_Counter or Rx_Err_Counter increases to be
 * greater than or equal to 128, the FLT_CONF field in the Error and Status Register is updated to
 * reflect 'Error Passive' state
 * {flexcan2_ipi_slv_can_error_multipleerrors}{flexcan2_ipi_slv_flex_reg_esr_fltconf} .  If the
 * FLEXCAN state is 'Error Passive', and either Tx_Err_Counter or Rx_Err_Counter decrements to a
 * value less than or equal to 127 while the other already satisfies this condition, the FLT_CONF
 * field in the Error and Status Register is updated to reflect 'Error Active' state
 * {flexcan2_ipi_slv_can_error_multipleerrors}{flexcan2_ipi_slv_flex_reg_esr_fltconf} .  If the
 * value of Tx_Err_Counter increases to be greater than 255, the FLT_CONF field in the Error and
 * Status Register is updated to reflect 'Bus Off' state, and an interrupt may be issued {flexcan2_i
 * pi_slv_flex_reg_esr_fltconf}{flexcan2_ipi_slv_flex_reg_esr_int}{flexcan2_ipi_slv_flex_busoff} .
 * The value of Tx_Err_Counter is then reset to zero. {flexcan2_ipi_slv_flex_busoff}   If FLEXCAN is
 * in 'Bus Off' state, then Tx_Err_Counter is cascaded together with another internal counter to
 * count the 128th occurrences of 11 consecutive recessive bits on the bus
 * {flexcan2_ipi_slv_flex_busoff} . Hence, Tx_Err_Counter is reset to zero and counts in a manner
 * where the internal counter counts 11 such bits and then wraps around while incrementing the
 * Tx_Err_Counter {flexcan2_ipi_slv_flex_busoff} . When Tx_Err_Counter reaches the value of 128, the
 * FLT_CONF field in the Error and Status Register is updated to be 'Error Active' and both error
 * counters are reset to zero {flexcan2_ipi_slv_flex_busoff} . At any instance of dominant bit
 * following a stream of less than 11 consecutive recessive bits, the internal counter resets itself
 * to zero without affecting the Tx_Err_Counter value. {flexcan2_ipi_slv_flex_busoff}   If during
 * system start-up, only one node is operating, then its Tx_Err_Counter increases in each message it
 * is trying to transmit, as a result of acknowledge errors (indicated by the ACK_ERR bit in the
 * Error and Status Register) {flexcan2_ipi_slv_can_error_multipleerrors} . After the transition to
 * 'Error Passive' state, the Tx_Err_Counter does not increment anymore by acknowledge errors
 * {flexcan2_ipi_slv_can_error_multipleerrors} . Therefore the device never goes to the 'Bus Off'
 * state. {flexcan2_ipi_slv_can_error_multipleerrors}   If the Rx_Err_Counter increases to a value
 * greater than 127, it is not incremented further, even if more errors are detected while being a
 * receiver {flexcan2_ipi_slv_can_error_multipleerrors} . At the next successful message reception,
 * the counter is set to a value between 119 and 127 to resume to 'Error Active' state.
 * {flexcan2_ipi_slv_can_error_multipleerrors}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_ERR_COUNTER : 8; //!< Tx_Err_Counter
        unsigned RX_ERR_COUNTER : 8; //!< Rx_Err_Counter
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_flexcan_ecr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ECR register
 */
#define HW_FLEXCAN_ECR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ECR(x)           (*(volatile hw_flexcan_ecr_t *) HW_FLEXCAN_ECR_ADDR(x))
#define HW_FLEXCAN_ECR_RD(x)        (HW_FLEXCAN_ECR(x).U)
#define HW_FLEXCAN_ECR_WR(x, v)     (HW_FLEXCAN_ECR(x).U = (v))
#define HW_FLEXCAN_ECR_SET(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) |  (v)))
#define HW_FLEXCAN_ECR_CLR(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) & ~(v)))
#define HW_FLEXCAN_ECR_TOG(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_ECR bitfields
 */

/* --- Register HW_FLEXCAN_ECR, field TX_ERR_COUNTER (RW)
 *
 * Tx_Err_Counter
 */

#define BP_FLEXCAN_ECR_TX_ERR_COUNTER      0
#define BM_FLEXCAN_ECR_TX_ERR_COUNTER      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_ECR_TX_ERR_COUNTER)
#else
#define BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)   (((v) << 0) & BM_FLEXCAN_ECR_TX_ERR_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_ERR_COUNTER field to a new value.
#define BW_FLEXCAN_ECR_TX_ERR_COUNTER(v)   BF_CS1(FLEXCAN_ECR, TX_ERR_COUNTER, v)
#endif

/* --- Register HW_FLEXCAN_ECR, field RX_ERR_COUNTER (RW)
 *
 * Rx_Err_Counter
 */

#define BP_FLEXCAN_ECR_RX_ERR_COUNTER      8
#define BM_FLEXCAN_ECR_RX_ERR_COUNTER      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_ECR_RX_ERR_COUNTER)
#else
#define BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)   (((v) << 8) & BM_FLEXCAN_ECR_RX_ERR_COUNTER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ERR_COUNTER field to a new value.
#define BW_FLEXCAN_ECR_RX_ERR_COUNTER(v)   BF_CS1(FLEXCAN_ECR, RX_ERR_COUNTER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_ESR1 - Error and Status 1 Register (RW)
 *
 * This register reflects various error conditions, some general status of the device and it is the
 * source of four interrupts to the ARM.  T he ARM read action clears bits 15-10 16-21 , therefore
 * the reported error conditions  (bits 15-10) (bits 16-21) are those that occurred since the last
 * time the ARM read this register {assert_clear_error_flags} . Bits 9-3 22-28 are status bits
 * {Statement} . In Enhanced Mode the error condition bits can be cleared by writing '1' to them
 * (writing '0' has no effect). {Functional Test}  Some bits in this register are read-only and some
 * are not {Statement} .   FlexCAN State {Statement}          SYNCH  IDLE  TX  RX  FlexCAN state
 * 0  0  0  0  Not synchronized to CAN bus    1  1  x  x  Idle    1  0  1  0  Transmitting    1  0
 * 0  1  Receiving    other combinations  Reserved
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned WAK_INT : 1; //!< When FLEXCAN is Stop Mode and a recessive to dominant transition is detected on the CAN bus and if the WAK_MSK bit in the MCR Register is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to '1' {flexcan2_ipi_slv_flex_reg_esr_int} . When SLF_WAK is negated, this flag is masked {Functional Test} . ARM must clear this flag before disabling the bit {Functional Test} . Otherwise it will be set when the SLF_WAK is set again {assert_wakeup_int*} . Writing '0' has no effect
        unsigned ERR_INT : 1; //!< This bit indicates that at least one of the Error Bits (bits 15-10) (bits 16-21) is set {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register (ERR_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to '1' {flexcan2_ipi_slv_flex_reg_esr_int} . Writing '0' has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned BOFF_INT : 1; //!< This bit is set when FLEXCAN enters 'Bus Off' state {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register (BOFF_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to '1'. Writing '0' has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned RX : 1; //!< This bit indicates if FlexCAN is receiving a message. Refer to .
        unsigned FLT_CONF : 2; //!< If the LOM bit in the Control Register is asserted, after some delay that depends on the CAN bit timing the FLT_CONF field will indicate "Error Passive". The very same delay affects the way how FLT_CONF reflects an update to ECR register by the ARM {Statement} . It may be necessary up to one CAN bit time to get them coherent again. {assert_listen_mode} Since the Control Register is not affected by soft reset, the FLT_CONF field will not be affected by soft reset if the LOM bit is asserted. {assert_listen_mode_soft_rst,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} This 2-bit field indicates the Confinement State of the FLEXCAN module, as shown in below:
        unsigned TX : 1; //!< This bit indicates if FLEXCAN is transmitting a message.Refer to .
        unsigned IDLE : 1; //!< This bit indicates when CAN bus is in IDLE state. {flexcan2_ipi_slv_flex_reg_esr_idle} Refer to .
        unsigned RX_WRN : 1; //!< This bit indicates when repetitive errors are occurring during message reception. {statement}
        unsigned TX_WRN : 1; //!< This bit indicates when repetitive errors are occurring during message transmission. {statement}
        unsigned STF_ERR : 1; //!< This bit indicates that a Stuffing Error has been detected. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned FRM_ERR : 1; //!< This bit indicates that a Form Error has been detected by the receiver node, i.e., a fixed-form bit field contains at least one illegal bit. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned CRC_ERR : 1; //!< This bit indicates that a CRC Error has been detected by the receiver node, i.e., the calculated CRC is different from the received. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned ACK_ERR : 1; //!< This bit indicates that an Acknowledge Error has been detected by the transmitter node, i.e., a dominant bit has not been detected during the ACK SLOT {flexcan2_ipi_slv_flex_reg_esr_error} .
        unsigned BIT0_ERR : 1; //!< This bit indicates when an inconsistency occurs between the transmitted and the received bit in a message. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned BIT1_ERR : 1; //!< This bit indicates when an inconsistency occurs between the transmitted and the received bit in a message {flexcan2_ipi_slv_flex_reg_esr_error} . This bit is not set by a transmitter in case of arbitration field or ACK slot, or in case of a node sending a passive error flag that detects dominant bits. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned RWRN_INT : 1; //!< If the WRN_EN bit in MCR is asserted, the RWRN_INT bit is set when the RX_WRN flag transition from '0' to '1', meaning that the Rx error counters reached 96 {assert_rx_warning_*} . If the corresponding mask bit in the Control Register (RWRN_MSK) is set, an interrupt is generated to the ARM {assert_rx_warning_*} . This bit is cleared by writing it to '1'. When WRN_EN is negated, this flag is masked {assert_rx_warning_*} . ARM must clear this flag before disabling the bit {assert_rx_warning_*} . Otherwise it will be set when the WRN_EN is set again {assert_rx_warning_*} . Writing '0' has no effect. This bit is not updated during Freeze mode.
        unsigned TWRN_INT : 1; //!< If the WRN_EN bit in MCR is asserted, the TWRN_INT bit is set when the TX_WRN flag transition from '0' to '1', meaning that the Tx error counter reached 96 {assert_tx_warning_*} . If the corresponding mask bit in the Control Register (TWRN_MSK) is set, an interrupt is generated to the ARM {assert_tx_warning_*} . This bit is cleared by writing it to '1'. When WRN_EN is negated, this flag is masked {assert_tx_warning_*} . ARM must clear this flag before disabling the bit {assert_tx_warning_*} . Otherwise it will be set when the WRN_EN is set again {assert_tx_warning_*} . Writing '0' has no effect. {FlexCAN3Rpd} This flag is not generated during "Bus Off" state. This bit is not updated during Freeze mode.
        unsigned SYNCH : 1; //!< This read-only flag indicates whether the FlexCAN is synchronized to the CAN bus and able to participate in the communication process {can_protocol_model,FlexCAN3IPSRpsCkr} . It is set and cleared by the FlexCAN {can_protocol_model,FlexCAN3IPSRpsCkr} . Refer to
        unsigned RESERVED0 : 13; //!< Reserved
    } B;
} hw_flexcan_esr1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ESR1 register
 */
#define HW_FLEXCAN_ESR1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ESR1(x)           (*(volatile hw_flexcan_esr1_t *) HW_FLEXCAN_ESR1_ADDR(x))
#define HW_FLEXCAN_ESR1_RD(x)        (HW_FLEXCAN_ESR1(x).U)
#define HW_FLEXCAN_ESR1_WR(x, v)     (HW_FLEXCAN_ESR1(x).U = (v))
#define HW_FLEXCAN_ESR1_SET(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) |  (v)))
#define HW_FLEXCAN_ESR1_CLR(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) & ~(v)))
#define HW_FLEXCAN_ESR1_TOG(x, v)    (HW_FLEXCAN_ESR1_WR(x, HW_FLEXCAN_ESR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_ESR1 bitfields
 */

/* --- Register HW_FLEXCAN_ESR1, field WAK_INT (RW)
 *
 * When FLEXCAN is Stop Mode and a recessive to dominant transition is detected on the CAN bus and
 * if the WAK_MSK bit in the MCR Register is set, an interrupt is generated to the ARM
 * {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to '1'
 * {flexcan2_ipi_slv_flex_reg_esr_int} . When SLF_WAK is negated, this flag is masked {Functional
 * Test} . ARM must clear this flag before disabling the bit {Functional Test} . Otherwise it will
 * be set when the SLF_WAK is set again {assert_wakeup_int*} . Writing '0' has no effect
 *
 * Values:
 * 1 - Indicates a recessive to dominant transition received on the CAN bus when the FLEXCAN module is in
 *     Stop Mode {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR1_WAK_INT      0
#define BM_FLEXCAN_ESR1_WAK_INT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_WAK_INT(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_ESR1_WAK_INT)
#else
#define BF_FLEXCAN_ESR1_WAK_INT(v)   (((v) << 0) & BM_FLEXCAN_ESR1_WAK_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_INT field to a new value.
#define BW_FLEXCAN_ESR1_WAK_INT(v)   BF_CS1(FLEXCAN_ESR1, WAK_INT, v)
#endif


/* --- Register HW_FLEXCAN_ESR1, field ERR_INT (RW)
 *
 * This bit indicates that at least one of the Error Bits (bits 15-10) (bits 16-21) is set
 * {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register
 * (ERR_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This
 * bit is cleared by writing it to '1' {flexcan2_ipi_slv_flex_reg_esr_int} . Writing '0' has no
 * effect. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 1 - Indicates setting of any Error Bit in the Error and Status Register
 *     {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR1_ERR_INT      1
#define BM_FLEXCAN_ESR1_ERR_INT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_ERR_INT(v)   ((((reg32_t) v) << 1) & BM_FLEXCAN_ESR1_ERR_INT)
#else
#define BF_FLEXCAN_ESR1_ERR_INT(v)   (((v) << 1) & BM_FLEXCAN_ESR1_ERR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_INT field to a new value.
#define BW_FLEXCAN_ESR1_ERR_INT(v)   BF_CS1(FLEXCAN_ESR1, ERR_INT, v)
#endif


/* --- Register HW_FLEXCAN_ESR1, field BOFF_INT (RW)
 *
 * This bit is set when FLEXCAN enters 'Bus Off' state {flexcan2_ipi_slv_flex_reg_esr_int} . If the
 * corresponding mask bit in the Control Register (BOFF_MSK) is set, an interrupt is generated to
 * the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to '1'. Writing
 * '0' has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 1 - FLEXCAN module entered 'Bus Off' state {flexcan2_ipi_slv_flex_reg_esr_int}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR1_BOFF_INT      2
#define BM_FLEXCAN_ESR1_BOFF_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_BOFF_INT(v)   ((((reg32_t) v) << 2) & BM_FLEXCAN_ESR1_BOFF_INT)
#else
#define BF_FLEXCAN_ESR1_BOFF_INT(v)   (((v) << 2) & BM_FLEXCAN_ESR1_BOFF_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_INT field to a new value.
#define BW_FLEXCAN_ESR1_BOFF_INT(v)   BF_CS1(FLEXCAN_ESR1, BOFF_INT, v)
#endif


/* --- Register HW_FLEXCAN_ESR1, field RX (RO)
 *
 * This bit indicates if FlexCAN is receiving a message. Refer to .
 *
 * Values:
 * 1 - FLEXCAN is transmitting a message {flexcan2_ipi_slv_flex_reg_esr_idle}
 * 0 - FLEXCAN is receiving a message {flexcan2_ipi_slv_flex_reg_esr_idle}
 */

#define BP_FLEXCAN_ESR1_RX      3
#define BM_FLEXCAN_ESR1_RX      0x00000008


/* --- Register HW_FLEXCAN_ESR1, field FLT_CONF (RO)
 *
 * If the LOM bit in the Control Register is asserted, after some delay that depends on the CAN bit
 * timing the FLT_CONF field will indicate "Error Passive". The very same delay affects the way how
 * FLT_CONF reflects an update to ECR register by the ARM {Statement} . It may be necessary up to
 * one CAN bit time to get them coherent again. {assert_listen_mode} Since the Control Register is
 * not affected by soft reset, the FLT_CONF field will not be affected by soft reset if the LOM bit
 * is asserted. {assert_listen_mode_soft_rst,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} This 2-bit
 * field indicates the Confinement State of the FLEXCAN module, as shown in below:
 *
 * Values:
 * 00 - Error Active
 * 01 - Error Passive
 * 1x - Bus off
 */

#define BP_FLEXCAN_ESR1_FLT_CONF      4
#define BM_FLEXCAN_ESR1_FLT_CONF      0x00000030


/* --- Register HW_FLEXCAN_ESR1, field TX (RO)
 *
 * This bit indicates if FLEXCAN is transmitting a message.Refer to .
 *
 * Values:
 * 1 - FLEXCAN is transmitting a message {flexcan2_ipi_slv_flex_reg_esr_idle}
 * 0 - FLEXCAN is receiving a message {flexcan2_ipi_slv_flex_reg_esr_idle}
 */

#define BP_FLEXCAN_ESR1_TX      6
#define BM_FLEXCAN_ESR1_TX      0x00000040


/* --- Register HW_FLEXCAN_ESR1, field IDLE (RO)
 *
 * This bit indicates when CAN bus is in IDLE state. {flexcan2_ipi_slv_flex_reg_esr_idle} Refer to .
 *
 * Values:
 * 1 - CAN bus is now IDLE {flexcan2_ipi_slv_flex_reg_esr_idle}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_idle}
 */

#define BP_FLEXCAN_ESR1_IDLE      7
#define BM_FLEXCAN_ESR1_IDLE      0x00000080


/* --- Register HW_FLEXCAN_ESR1, field RX_WRN (RO)
 *
 * This bit indicates when repetitive errors are occurring during message reception. {statement}
 *
 * Values:
 * 1 - Rx_Err_Counter ≥ 96 {flexcan2_ipi_slv_can_error_multipleerrors}
 * 0 - No such occurrence {flexcan2_ipi_slv_can_error_multipleerrors}
 */

#define BP_FLEXCAN_ESR1_RX_WRN      8
#define BM_FLEXCAN_ESR1_RX_WRN      0x00000100


/* --- Register HW_FLEXCAN_ESR1, field TX_WRN (RO)
 *
 * This bit indicates when repetitive errors are occurring during message transmission. {statement}
 *
 * Values:
 * 1 - TX_Err_Counter ≥ 96 {flexcan2_ipi_slv_can_error_multipleerrors}
 * 0 - No such occurrence {flexcan2_ipi_slv_can_error_multipleerrors}
 */

#define BP_FLEXCAN_ESR1_TX_WRN      9
#define BM_FLEXCAN_ESR1_TX_WRN      0x00000200


/* --- Register HW_FLEXCAN_ESR1, field STF_ERR (RO)
 *
 * This bit indicates that a Stuffing Error has been detected. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 1 - A Stuffing Error occurred since last read of this register. {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence. {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_STF_ERR      10
#define BM_FLEXCAN_ESR1_STF_ERR      0x00000400


/* --- Register HW_FLEXCAN_ESR1, field FRM_ERR (RO)
 *
 * This bit indicates that a Form Error has been detected by the receiver node, i.e., a fixed-form
 * bit field contains at least one illegal bit. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 1 - A Form Error occurred since last read of this register {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_FRM_ERR      11
#define BM_FLEXCAN_ESR1_FRM_ERR      0x00000800


/* --- Register HW_FLEXCAN_ESR1, field CRC_ERR (RO)
 *
 * This bit indicates that a CRC Error has been detected by the receiver node, i.e., the calculated
 * CRC is different from the received. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 1 - A CRC error occurred since last read of this register. {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_CRC_ERR      12
#define BM_FLEXCAN_ESR1_CRC_ERR      0x00001000


/* --- Register HW_FLEXCAN_ESR1, field ACK_ERR (RO)
 *
 * This bit indicates that an Acknowledge Error has been detected by the transmitter node, i.e., a
 * dominant bit has not been detected during the ACK SLOT {flexcan2_ipi_slv_flex_reg_esr_error} .
 *
 * Values:
 * 1 - An ACK error occurred since last read of this register {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_ACK_ERR      13
#define BM_FLEXCAN_ESR1_ACK_ERR      0x00002000


/* --- Register HW_FLEXCAN_ESR1, field BIT0_ERR (RO)
 *
 * This bit indicates when an inconsistency occurs between the transmitted and the received bit in a
 * message. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 1 - At least one bit sent as dominant is received as recessive {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_BIT0_ERR      14
#define BM_FLEXCAN_ESR1_BIT0_ERR      0x00004000


/* --- Register HW_FLEXCAN_ESR1, field BIT1_ERR (RO)
 *
 * This bit indicates when an inconsistency occurs between the transmitted and the received bit in a
 * message {flexcan2_ipi_slv_flex_reg_esr_error} . This bit is not set by a transmitter in case of
 * arbitration field or ACK slot, or in case of a node sending a passive error flag that detects
 * dominant bits. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 1 - At least one bit sent as recessive is received as dominant {flexcan2_ipi_slv_flex_reg_esr_error}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR1_BIT1_ERR      15
#define BM_FLEXCAN_ESR1_BIT1_ERR      0x00008000


/* --- Register HW_FLEXCAN_ESR1, field RWRN_INT (RW)
 *
 * If the WRN_EN bit in MCR is asserted, the RWRN_INT bit is set when the RX_WRN flag transition
 * from '0' to '1', meaning that the Rx error counters reached 96 {assert_rx_warning_*} . If the
 * corresponding mask bit in the Control Register (RWRN_MSK) is set, an interrupt is generated to
 * the ARM {assert_rx_warning_*} . This bit is cleared by writing it to '1'. When WRN_EN is negated,
 * this flag is masked {assert_rx_warning_*} . ARM must clear this flag before disabling the bit
 * {assert_rx_warning_*} . Otherwise it will be set when the WRN_EN is set again
 * {assert_rx_warning_*} . Writing '0' has no effect. This bit is not updated during Freeze mode.
 *
 * Values:
 * 1 - The Rx error counter transition from < 96 to >= 96
 * 0 - No such occurrence
 */

#define BP_FLEXCAN_ESR1_RWRN_INT      16
#define BM_FLEXCAN_ESR1_RWRN_INT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_RWRN_INT(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_ESR1_RWRN_INT)
#else
#define BF_FLEXCAN_ESR1_RWRN_INT(v)   (((v) << 16) & BM_FLEXCAN_ESR1_RWRN_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWRN_INT field to a new value.
#define BW_FLEXCAN_ESR1_RWRN_INT(v)   BF_CS1(FLEXCAN_ESR1, RWRN_INT, v)
#endif


/* --- Register HW_FLEXCAN_ESR1, field TWRN_INT (RW)
 *
 * If the WRN_EN bit in MCR is asserted, the TWRN_INT bit is set when the TX_WRN flag transition
 * from '0' to '1', meaning that the Tx error counter reached 96 {assert_tx_warning_*} . If the
 * corresponding mask bit in the Control Register (TWRN_MSK) is set, an interrupt is generated to
 * the ARM {assert_tx_warning_*} . This bit is cleared by writing it to '1'. When WRN_EN is negated,
 * this flag is masked {assert_tx_warning_*} . ARM must clear this flag before disabling the bit
 * {assert_tx_warning_*} . Otherwise it will be set when the WRN_EN is set again
 * {assert_tx_warning_*} . Writing '0' has no effect. {FlexCAN3Rpd} This flag is not generated
 * during "Bus Off" state. This bit is not updated during Freeze mode.
 *
 * Values:
 * 1 - The Tx error counter transition from < 96 to >= 96
 * 0 - No such occurrence
 */

#define BP_FLEXCAN_ESR1_TWRN_INT      17
#define BM_FLEXCAN_ESR1_TWRN_INT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_ESR1_TWRN_INT(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_ESR1_TWRN_INT)
#else
#define BF_FLEXCAN_ESR1_TWRN_INT(v)   (((v) << 17) & BM_FLEXCAN_ESR1_TWRN_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TWRN_INT field to a new value.
#define BW_FLEXCAN_ESR1_TWRN_INT(v)   BF_CS1(FLEXCAN_ESR1, TWRN_INT, v)
#endif


/* --- Register HW_FLEXCAN_ESR1, field SYNCH (RO)
 *
 * This read-only flag indicates whether the FlexCAN is synchronized to the CAN bus and able to
 * participate in the communication process {can_protocol_model,FlexCAN3IPSRpsCkr} . It is set and
 * cleared by the FlexCAN {can_protocol_model,FlexCAN3IPSRpsCkr} . Refer to
 *
 * Values:
 * 1 - FlexCAN is synchronized to the CAN bus
 * 0 - FlexCAN is not synchronized to the CAN bus
 */

#define BP_FLEXCAN_ESR1_SYNCH      18
#define BM_FLEXCAN_ESR1_SYNCH      0x00040000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register (RW)
 *
 * This register allows any number of a range of 32 Message Buffer Interrupts to be enabled or
 * disabled {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt mask bit per buffer,
 * enabling the ARM to determine which buffer generates an interrupt after a successful transmission
 * or reception {flexcan2_ipi_slv_flex_mbuffer_int} (i.e. when the corresponding IFLAG2 bit is set)
 * {flexcan2_ipi_slv_flex_mbuffer_int} .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BUF63M : 32; //!< Each bit enables or disables the respective FLEXCAN Message Buffer (MB32 to MB63) Interrupt. {flexcan2_ipi_slv_flex_mbuffer_int} Setting or clearing a bit in the IMASK2 Register can assert or negate an interrupt request, if the corresponding IFLAG2 bit is set. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_imask2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK2 register
 */
#define HW_FLEXCAN_IMASK2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK2(x)           (*(volatile hw_flexcan_imask2_t *) HW_FLEXCAN_IMASK2_ADDR(x))
#define HW_FLEXCAN_IMASK2_RD(x)        (HW_FLEXCAN_IMASK2(x).U)
#define HW_FLEXCAN_IMASK2_WR(x, v)     (HW_FLEXCAN_IMASK2(x).U = (v))
#define HW_FLEXCAN_IMASK2_SET(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK2_CLR(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK2_TOG(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IMASK2 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK2, field BUF63M (RW)
 *
 * Each bit enables or disables the respective FLEXCAN Message Buffer (MB32 to MB63) Interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int} Setting or clearing a bit in the IMASK2 Register can assert
 * or negate an interrupt request, if the corresponding IFLAG2 bit is set.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - The corresponding buffer Interrupt is disabled {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer Interrupt is enabled {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IMASK2_BUF63M      0
#define BM_FLEXCAN_IMASK2_BUF63M      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMASK2_BUF63M(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IMASK2_BUF63M)
#else
#define BF_FLEXCAN_IMASK2_BUF63M(v)   (((v) << 0) & BM_FLEXCAN_IMASK2_BUF63M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF63M field to a new value.
#define BW_FLEXCAN_IMASK2_BUF63M(v)   BF_CS1(FLEXCAN_IMASK2, BUF63M, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register (RW)
 *
 * This register allows to enable or disable any number of a range of 32 Message Buffer Interrupts
 * {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt mask bit per buffer, enabling the
 * ARM to determine which buffer generates an interrupt after a successful transmission or reception
 * {flexcan2_ipi_slv_flex_mbuffer_int} (i.e., when the corresponding IFLAG1 bit is set).
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BUF31M : 32; //!< Each bit enables or disables the respective FLEXCAN Message Buffer (MB0 to MB31) Interrupt. {flexcan2_ipi_slv_flex_mbuffer_int} Setting or clearing a bit in the IMASK1 Register can assert or negate an interrupt request, if the corresponding IFLAG1 bit is set
    } B;
} hw_flexcan_imask1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK1 register
 */
#define HW_FLEXCAN_IMASK1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK1(x)           (*(volatile hw_flexcan_imask1_t *) HW_FLEXCAN_IMASK1_ADDR(x))
#define HW_FLEXCAN_IMASK1_RD(x)        (HW_FLEXCAN_IMASK1(x).U)
#define HW_FLEXCAN_IMASK1_WR(x, v)     (HW_FLEXCAN_IMASK1(x).U = (v))
#define HW_FLEXCAN_IMASK1_SET(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK1_CLR(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK1_TOG(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IMASK1 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK1, field BUF31M (RW)
 *
 * Each bit enables or disables the respective FLEXCAN Message Buffer (MB0 to MB31) Interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int} Setting or clearing a bit in the IMASK1 Register can assert
 * or negate an interrupt request, if the corresponding IFLAG1 bit is set
 *
 * Values:
 * 0 - The corresponding buffer Interrupt is disabled {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer Interrupt is enabled {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IMASK1_BUF31M      0
#define BM_FLEXCAN_IMASK1_BUF31M      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IMASK1_BUF31M(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IMASK1_BUF31M)
#else
#define BF_FLEXCAN_IMASK1_BUF31M(v)   (((v) << 0) & BM_FLEXCAN_IMASK1_BUF31M)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF31M field to a new value.
#define BW_FLEXCAN_IMASK1_BUF31M(v)   BF_CS1(FLEXCAN_IMASK1, BUF31M, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register (RW)
 *
 * This register defines the flags for 32 Message Buffer interrupts
 * {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt flag bit per buffer
 * {flexcan2_ipi_slv_flex_mbuffer_int} . Each successful transmission or reception sets the
 * corresponding IFLAG2 bit {flexcan2_ipi_slv_flex_mbuffer_int} . If the corresponding IMASK2 bit is
 * set, an interrupt will be generated. {flexcan2_ipi_slv_flex_mbuffer_int} The interrupt flag must
 * be cleared by writing it to '1' {flexcan2_ipi_slv_flex_mbuffer_int} . Writing '0' has no effect.
 * {flexcan2_ipi_slv_flex_mbuffer_int} Before updating MCR[MAXMB] field, ARM must treat the IFLAG2
 * bits which MB value is greater than the MCR[MAXMB] to be updated, otherwise they will keep set
 * and be inconsistent with the amount of MBs available.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BUF63I : 32; //!< Each bit flags the respective FLEXCAN Message Buffer (MB32 to MB63) interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_iflag2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG2 register
 */
#define HW_FLEXCAN_IFLAG2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG2(x)           (*(volatile hw_flexcan_iflag2_t *) HW_FLEXCAN_IFLAG2_ADDR(x))
#define HW_FLEXCAN_IFLAG2_RD(x)        (HW_FLEXCAN_IFLAG2(x).U)
#define HW_FLEXCAN_IFLAG2_WR(x, v)     (HW_FLEXCAN_IFLAG2(x).U = (v))
#define HW_FLEXCAN_IFLAG2_SET(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG2_CLR(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG2_TOG(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IFLAG2 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG2, field BUF63I (RW)
 *
 * Each bit flags the respective FLEXCAN Message Buffer (MB32 to MB63) interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer has successfully completed transmission or reception
 *     {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG2_BUF63I      0
#define BM_FLEXCAN_IFLAG2_BUF63I      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG2_BUF63I(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IFLAG2_BUF63I)
#else
#define BF_FLEXCAN_IFLAG2_BUF63I(v)   (((v) << 0) & BM_FLEXCAN_IFLAG2_BUF63I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF63I field to a new value.
#define BW_FLEXCAN_IFLAG2_BUF63I(v)   BF_CS1(FLEXCAN_IFLAG2, BUF63I, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register (RW)
 *
 * This register defines the flags for 32 Message Buffer interrupts
 * {flexcan2_ipi_slv_flex_mbuffer_int} and FIFO interrupts. It contains one interrupt flag bit per
 * buffer {flexcan2_ipi_slv_flex_mbuffer_int} . Each successful transmission or reception sets the
 * corresponding IFLAG1 bit {flexcan2_ipi_slv_flex_mbuffer_int} . If the corresponding IMASK1 bit is
 * set, an interrupt will be generated. {flexcan2_ipi_slv_flex_mbuffer_int} The Interrupt flag must
 * be cleared by writing it to '1' {flexcan2_ipi_slv_flex_mbuffer_int} . Writing '0' has no effect.
 * {flexcan2_ipi_slv_flex_mbuffer_int}  W hen the RFEN bit in the MCR is set (Rx FIFO enabled), the
 * function of the 8 least significant interrupt flags (BUF7I - BUF0I) is changed to support the
 * FIFO operation {FlexCAN3RxRpsCkr} . BUF7I, BUF6I and BUF5I indicate operating conditions of the
 * FIFO, while BUF4I to BUF0I are not used. {FlexCAN3RxRpsCkr} Before enabling the RFEN, ARM must
 * service the IFLAGS asserted in the Rx FIFO region (see ) {FlexCAN3IflagStim_todo} . Otherwise,
 * these IFLAGS will mistakenly show the related MBs now belonging to FIFO as having contents to be
 * serviced {FlexCAN3IflagStim_todo} . When the RFEN is negated, the FIFO flags must be cleared
 * {FlexCAN3IflagStim_todo} . The same care must be taken when a RFFN value is selected extending Rx
 * FIFO filters beyond MB7 (see ) {Statement} . For example, when RFFN is 0x8, the MB0-23 range is
 * occupied by Rx FIFO filters and related IFLAGS must be cleared. {FlexCAN3IflagStim_todo}  Before
 * updating MCR[MAXMB] field, ARM must service the IFLAG1 which MB value is greater than the
 * MCR[MAXMB] to be updated, otherwise they will keep set and be inconsistent with the amount of MBs
 * available.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BUF4I : 5; //!< If the Rx FIFO is not enabled, these bits flag the interrupts for MB0 to MB4 {Statement} . If the Rx FIFO is enabled, these flags are not used and must be considered as reserved locations {FlexCAN3RxRpsCkr} . These flags are cleared by the FlexCAN whenever the bit MCR[RFEN] is changed by ARM writes. {FlexCAN3IflagStim_todo}
        unsigned BUF5I : 1; //!< If the Rx FIFO is not enabled, this bit flags the interrupt for MB5 {Statement} . If the Rx FIFO is enabled, this flag indicates that at least one frame is available to be read from the Rx FIFO {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . This flag is cleared by the FlexCAN whenever the bit MCR[RFEN] is changed by ARM writes.
        unsigned BUF6I : 1; //!< If the Rx FIFO is not enabled, this bit flags the interrupt for MB6 {Statement} . If the MCR[RFEN] bit is asserted, this flag indicates when the number of unread messages within the Rx FIFO is increased to 5 from 4 due to the reception of a new one, meaning that the Rx FIFO is almost full {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . Note that if the flag is cleared while the number of unread messages is greater than 4 it will not assert again until the number of unread messages within the Rx FIFO is decreased to equal or less than 4. This flag is cleared by the FlexCAN whenever the bit MCR[RFEN] is changed by ARM writes.
        unsigned BUF7I : 1; //!< If the Rx FIFO is not enabled, this bit flags the interrupt for MB7 {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . If the MCR[RFEN] bit is asserted, this flag indicates that a message was lost because Rx FIFO is full {Functional Test} . Note that the flag will not be asserted when the Rx FIFO is full and the message was captured by a Mailbox. This flag is cleared by the FlexCAN whenever the bit MCR[RFEN] is changed by ARM writes.
        unsigned BUF31I : 24; //!< Each bit flags the respective FLEXCAN Message Buffer (MB8 to MB31) interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_iflag1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG1 register
 */
#define HW_FLEXCAN_IFLAG1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG1(x)           (*(volatile hw_flexcan_iflag1_t *) HW_FLEXCAN_IFLAG1_ADDR(x))
#define HW_FLEXCAN_IFLAG1_RD(x)        (HW_FLEXCAN_IFLAG1(x).U)
#define HW_FLEXCAN_IFLAG1_WR(x, v)     (HW_FLEXCAN_IFLAG1(x).U = (v))
#define HW_FLEXCAN_IFLAG1_SET(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG1_CLR(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG1_TOG(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IFLAG1 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG1, field BUF4I (RW)
 *
 * If the Rx FIFO is not enabled, these bits flag the interrupts for MB0 to MB4 {Statement} . If the
 * Rx FIFO is enabled, these flags are not used and must be considered as reserved locations
 * {FlexCAN3RxRpsCkr} . These flags are cleared by the FlexCAN whenever the bit MCR[RFEN] is changed
 * by ARM writes. {FlexCAN3IflagStim_todo}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - Corresponding MB completed transmission/reception
 */

#define BP_FLEXCAN_IFLAG1_BUF4I      0
#define BM_FLEXCAN_IFLAG1_BUF4I      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF4I(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_IFLAG1_BUF4I)
#else
#define BF_FLEXCAN_IFLAG1_BUF4I(v)   (((v) << 0) & BM_FLEXCAN_IFLAG1_BUF4I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF4I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF4I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF4I, v)
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF5I (RW)
 *
 * If the Rx FIFO is not enabled, this bit flags the interrupt for MB5 {Statement} . If the Rx FIFO
 * is enabled, this flag indicates that at least one frame is available to be read from the Rx FIFO
 * {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . This flag is cleared by the FlexCAN whenever the bit MCR[RFEN]
 * is changed by ARM writes.
 *
 * Values:
 * 1 - MB5 completed transmission/reception or frames available in the FIFO
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF5I      5
#define BM_FLEXCAN_IFLAG1_BUF5I      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF5I(v)   ((((reg32_t) v) << 5) & BM_FLEXCAN_IFLAG1_BUF5I)
#else
#define BF_FLEXCAN_IFLAG1_BUF5I(v)   (((v) << 5) & BM_FLEXCAN_IFLAG1_BUF5I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF5I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF5I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF5I, v)
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF6I (RW)
 *
 * If the Rx FIFO is not enabled, this bit flags the interrupt for MB6 {Statement} . If the
 * MCR[RFEN] bit is asserted, this flag indicates when the number of unread messages within the Rx
 * FIFO is increased to 5 from 4 due to the reception of a new one, meaning that the Rx FIFO is
 * almost full {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . Note that if the flag is cleared while the number of
 * unread messages is greater than 4 it will not assert again until the number of unread messages
 * within the Rx FIFO is decreased to equal or less than 4. This flag is cleared by the FlexCAN
 * whenever the bit MCR[RFEN] is changed by ARM writes.
 *
 * Values:
 * 1 - MB6 completed transmission/reception or FIFO almost full
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF6I      6
#define BM_FLEXCAN_IFLAG1_BUF6I      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF6I(v)   ((((reg32_t) v) << 6) & BM_FLEXCAN_IFLAG1_BUF6I)
#else
#define BF_FLEXCAN_IFLAG1_BUF6I(v)   (((v) << 6) & BM_FLEXCAN_IFLAG1_BUF6I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF6I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF6I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF6I, v)
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF7I (RW)
 *
 * If the Rx FIFO is not enabled, this bit flags the interrupt for MB7
 * {FlexCAN3RxRpsCkr,FlexCAN3Rpd} . If the MCR[RFEN] bit is asserted, this flag indicates that a
 * message was lost because Rx FIFO is full {Functional Test} . Note that the flag will not be
 * asserted when the Rx FIFO is full and the message was captured by a Mailbox. This flag is cleared
 * by the FlexCAN whenever the bit MCR[RFEN] is changed by ARM writes.
 *
 * Values:
 * 1 - MB7 completed transmission/reception or FIFO overflow {flexcan2_ipi_slv_flex_mbuffer_int}
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF7I      7
#define BM_FLEXCAN_IFLAG1_BUF7I      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF7I(v)   ((((reg32_t) v) << 7) & BM_FLEXCAN_IFLAG1_BUF7I)
#else
#define BF_FLEXCAN_IFLAG1_BUF7I(v)   (((v) << 7) & BM_FLEXCAN_IFLAG1_BUF7I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF7I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF7I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF7I, v)
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF31I (RW)
 *
 * Each bit flags the respective FLEXCAN Message Buffer (MB8 to MB31) interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding MB has successfully completed transmission or reception
 *     {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF31I      8
#define BM_FLEXCAN_IFLAG1_BUF31I      0xffffff00

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_IFLAG1_BUF31I(v)   ((((reg32_t) v) << 8) & BM_FLEXCAN_IFLAG1_BUF31I)
#else
#define BF_FLEXCAN_IFLAG1_BUF31I(v)   (((v) << 8) & BM_FLEXCAN_IFLAG1_BUF31I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF31I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF31I(v)   BF_CS1(FLEXCAN_IFLAG1, BUF31I, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_CTRL2 - Control 2 Register (RW)
 *
 * This register contains control bits for CAN errors, FIFO features and mode selection.   Rx FIFO
 * Filters in Legacy Mode {Statement}           RFFN [3:0] [0:3]  Number of Rx FIFO filters  Message
 * Buffers occupied by Rx FIFO and ID Filter Table  Remaining Available Mailboxes The number of the
 * last remaining available mailboxes is defined by the MCR[MAXMB] field.   Rx FIFO ID Filter Table
 * Elements Affected by Rx Individual Masks If Rx Individual Mask Registers are not enabled then all
 * Rx FIFO filters are affected by the Rx FIFO Global Mask.   Rx FIFO ID Filter Table Elements
 * Affected by Rx FIFO Global Mask       0x0  8  MB 0-7  MB 8-63  Elements 0-7  none    0x1  16  MB
 * 0-9  MB 10-63  Elements 0-9  Elements 10-15    0x2  24  MB 0-11  MB 12-63  Elements 0-11
 * Elements 12-23    0x3  32  MB 0-13  MB 14-63  Elements 0-13  Elements 14-31    0x4  40  MB 0-15
 * MB 16-63  Elements 0-15  Elements 16-39    0x5  48  MB 0-17  MB 18-63  Elements 0-17  Elements
 * 18-47    0x6  56  MB 0-19  MB 20-63  Elements 0-19  Elements 20-55    0x7  64  MB 0-21  MB 22-63
 * Elements 0-21  Elements 22-63    0x8  72  MB 0-23  MB 24-63  Elements 0-23  Elements 24-71    0x9
 * 80  MB 0-25  MB 26-63  Elements 0-25  Elements 26-79    0xA  88  MB 0-27  MB 28-63  Elements 0-27
 * Elements 28-87    0xB  96  MB 0-29  MB 30-63  Elements 0-29  Elements 30-95    0xC  104  MB 0-31
 * MB 32-63  Elements 0-31  Elements 32-103    0xD  112  MB 0-33  MB 34-63  Elements 0-31  Elements
 * 32-111    0xE  120  MB 0-35  MB 36-63  Elements 0-31  Elements 32-119    0xF  128  MB 0-37  MB
 * 38-63  Elements 0-31  Elements 32-127      In Legacy Mode, e E ach group of eight filters
 * occupies a memory space equivalent to two Message Buffers which means that the more filters are
 * implemented the less Mailboxes will be available. {Statement}  Considering that the Rx FIFO
 * occupies the memory space originally reserved for MB0-5, RFFN should be programmed with a value
 * corresponding to a number of filters not greater than the number of available memory words which
 * can be calculated as follows: {Statement}     where SETUP_MB is MAXMB. {Statement}  The number of
 * remaining Mailboxes available will be: {Statement}     If the Number of Rx FIFO Filters
 * programmed through RFFN exceeds the SETUP_MB value, the exceeding ones will not be functional.
 * {Statement} Unshaded regions in indicate the valid combinations of MAXMB, RFEN and RFFN, shaded
 * regions are not functional.   Valid Combinations of MAXMB, RFEN and RFFN
 * RFFN  0  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15    RFEN  0  1  1  1  1  1  1  1  1
 * 1  1  1  1  1  1  1  1    MAXMB       0 - 6                     7 - 8                     9 - 10
 * 11 - 12                     13 -14                     15 - 16                     17 -18
 * 19 - 20                     21 - 22                     23 - 24                     25 - 26
 * 27 - 28                     29 -30                     31 - 32                     33 - 34
 * 35 - 36                     37 - 63                       LOSTRLMSK - Lost Rx Locked Mask.  This
 * bit provides a mask for the ESR2[LOSTRLF] bit interrupt.  1= Lost Rx Locked Interrupt enabled.
 * 0= Lost Rx Locked Interrupt disabled.  LOSTRMMSK - Lost Rx Matched Mask.  This bit provides a
 * mask for the ESR2[LOSTRMF] bit interrupt.  1= Lost Rx Matched Interrupt enabled.  0= Lost Rx
 * Matched Interrupt disabled.  IMEUMASK - Individual Matching Elements Update mask.  This bit
 * provides a mask for the ESR2[IMEUF] bit interrupt.  1= IMEU Interrupt enabled.  0= IMEU Interrupt
 * disabled.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned EACEN : 1; //!< This bit controls the comparison of IDE and RTR bits within Rx Mailboxes filters with their corresponding bits in the incoming frame by the matching process {FlexCAN3RxRpsCkr} . This bit does not affect matching for Rx FIFO {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
        unsigned RRS : 1; //!< If this bit is asserted Remote Request Frame is submitted to a matching process and stored in the corresponding Message Buffer in the same fashion of a Data Frame {FlexCAN3RxRpsCkr} . No automatic Remote Response Frame will be generated {FlexCAN3RxRpsCkr} . If this bit is negated the Remote Request Frame is submitted to a matching process and an automatic Remote Response Frame is generated if a Message Buffer with CODE=0b1010 is found with the same ID {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned MRP : 1; //!< If this bit is set the matching process starts from the Mailboxes and if no match occurs the matching continues on the Rx FIFO {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
        unsigned TASD : 5; //!< This 5-bit field indicates how many CAN bits the Tx arbitration process start point can be delayed from the first bit of CRC field on CAN bus {Statement} . This field can only be written in Freeze mode as it is blocked by hardware in other modes. FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim This field is useful to optimize the transmit performance based on factors such as: peripheral/serial clock ratio, CAN bit timing and number of MBs {Statement} . The duration of an arbitration process, in terms of CAN bits, is directly proportional to the number of available MBs and CAN baud rate and inversely proportional to the peripheral clock frequency. {Statement} The optimal arbitration timing is that in which the last MB is scanned right before the first bit of the Intermission field of a CAN frame {Statement} . Therefore, if there are few MBs and the system/serial clock ratio is high and the CAN baud rate is low then the arbitration can be delayed and vice-versa. {Statement} If TASD is 0 then the arbitration start is not delayed, thus ARM has less time to configure a Tx MB for the next arbitration, but more time is reserved for arbitration {Statement} . In the other hand, if TASD is 24 then ARM can configure a Tx MB later and less time is reserved for arbitration. {Statement} If too little time is reserved for arbitration the FlexCAN may be not able to find winner MBs in time to compete with other nodes for the CAN bus {Statement} . If the arbitration ends too much time before the first bit of Intermission field then there is a chance that ARM reconfigure some Tx MBs and the winner MB is not the best to be transmitted {Statement} . The reset value is different on various platforms, according to their peripheral clock frequency, number of MBs and target CAN baud rate {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . If ATASP bit is set TASD is updated automatically by the module itself on every end of frame {Functional Test} . The optimal configuration for TASD can be calculated as: {Statement} where: {Statement} f CANCLK is the Protocol Engine (PE) Clock in Hz; PE clock is derrived from CAN_CLK_ROOT in CCM. See {Statement} f SYS is the peripheral clock in Hz; {Statement} MAXMB is the value in CTRL1[MAXMB] field; {Statement} RFEN is the value in CTRL1[RFEN] bit; {Statement} RFFN is the value in CTRL2[RFFN] field; {Statement} PSEG1 is the value in CTRL1[PSEG1] field; {Statement} PSEG2 is the value in CTRL1[PSEG2] field; {Statement} PROPSEG is the value in CTRL1[PROPSEG] field; {Statement} PRESDIV is the value in CTRL1[PRESDIV] field. {Statement} Please refer to and for more details {Statement} .
        unsigned RFEN : 4; //!< This 4-bit field defines the number of Rx FIFO filters according to {Statement} . The maximum selectable number of filters is determined by the ARM {cover_rxfifo_filter} . This field can only be written in Freeze mode as it is blocked by hardware in other modes {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . RFFN defines a number of Message Buffers occupied by Rx FIFO and ID Filter (see ) that may not e xceed the number of available Mailboxes present in module, defined by MCR[MAXMB]. {FlexCAN3RxRpsCkr,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} Default RFFN value is 0x0, which leads to a total of 8 Rx FIFO filters, occupies the first 8 Message Buffers (MB 0-7) and makes available the next Message Buffers (MB 8-63) for Mailboxes. As a second example, when RFFN is set to 0xD, there will be 112 Rx FIFO filters, located in MB 0-33, and MB 34-63 are available for Mailboxes {Statement} . Notice that, in this case, individual masks (RXIMR) will just cover Rx FIFO filters in 0-31 range, and filters 32-111 will use RXFGMASK {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . In case of reducing the number of last Message Buffers, MCR[MAXMB] (see ) can be adjusted by the application to minimum of 33, in order to give room to the Rx FIFO and its ID Filter Table defined by RFFN {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . On the contrary, if the application sets MCR[MAXMB] to 16, for instance, the maximum RFFN is limited to 0x4 {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . RFFN also impacts the definition of the minimum number of peripheral clocks per CAN bit as described in (see ).
        unsigned WRMFRZ : 1; //!< Enable unrestricted write access to FlexCAN memory in Freeze mode {FlexCAN3RegAccessStim,FlexCAN3MemAccessStim} . This bit can only be written in Freeze mode and has no effect out of Freeze mode. {FlexCAN3RegAccessStim,FlexCAN3MemAccessStim}
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned RESERVED2 : 1; //!< must be written as 0
    } B;
} hw_flexcan_ctrl2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CTRL2 register
 */
#define HW_FLEXCAN_CTRL2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CTRL2(x)           (*(volatile hw_flexcan_ctrl2_t *) HW_FLEXCAN_CTRL2_ADDR(x))
#define HW_FLEXCAN_CTRL2_RD(x)        (HW_FLEXCAN_CTRL2(x).U)
#define HW_FLEXCAN_CTRL2_WR(x, v)     (HW_FLEXCAN_CTRL2(x).U = (v))
#define HW_FLEXCAN_CTRL2_SET(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) |  (v)))
#define HW_FLEXCAN_CTRL2_CLR(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) & ~(v)))
#define HW_FLEXCAN_CTRL2_TOG(x, v)    (HW_FLEXCAN_CTRL2_WR(x, HW_FLEXCAN_CTRL2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_CTRL2 bitfields
 */

/* --- Register HW_FLEXCAN_CTRL2, field EACEN (RW)
 *
 * This bit controls the comparison of IDE and RTR bits within Rx Mailboxes filters with their
 * corresponding bits in the incoming frame by the matching process {FlexCAN3RxRpsCkr} . This bit
 * does not affect matching for Rx FIFO {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze
 * mode as it is blocked by hardware in other modes. {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr}
 *
 * Values:
 * 1 - Enables the comparison of both Rx Mailbox filter's IDE and RTR bit with their corresponding bits
 *     within the incoming frame {FlexCAN3RxRpsCkr} . Mask bits do apply.
 * 0 - Rx Mailbox filter's IDE bit is always compared and RTR is never compared despite mask bits.
 */

#define BP_FLEXCAN_CTRL2_EACEN      16
#define BM_FLEXCAN_CTRL2_EACEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_EACEN(v)   ((((reg32_t) v) << 16) & BM_FLEXCAN_CTRL2_EACEN)
#else
#define BF_FLEXCAN_CTRL2_EACEN(v)   (((v) << 16) & BM_FLEXCAN_CTRL2_EACEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EACEN field to a new value.
#define BW_FLEXCAN_CTRL2_EACEN(v)   BF_CS1(FLEXCAN_CTRL2, EACEN, v)
#endif


/* --- Register HW_FLEXCAN_CTRL2, field RRS (RW)
 *
 * If this bit is asserted Remote Request Frame is submitted to a matching process and stored in the
 * corresponding Message Buffer in the same fashion of a Data Frame {FlexCAN3RxRpsCkr} . No
 * automatic Remote Response Frame will be generated {FlexCAN3RxRpsCkr} . If this bit is negated the
 * Remote Request Frame is submitted to a matching process and an automatic Remote Response Frame is
 * generated if a Message Buffer with CODE=0b1010 is found with the same ID {FlexCAN3RxRpsCkr} .
 * This bit can only be written in Freeze mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Remote Request Frame is stored
 * 0 - Remote Response Frame is generated
 */

#define BP_FLEXCAN_CTRL2_RRS      17
#define BM_FLEXCAN_CTRL2_RRS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_RRS(v)   ((((reg32_t) v) << 17) & BM_FLEXCAN_CTRL2_RRS)
#else
#define BF_FLEXCAN_CTRL2_RRS(v)   (((v) << 17) & BM_FLEXCAN_CTRL2_RRS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RRS field to a new value.
#define BW_FLEXCAN_CTRL2_RRS(v)   BF_CS1(FLEXCAN_CTRL2, RRS, v)
#endif


/* --- Register HW_FLEXCAN_CTRL2, field MRP (RW)
 *
 * If this bit is set the matching process starts from the Mailboxes and if no match occurs the
 * matching continues on the Rx FIFO {FlexCAN3RxRpsCkr} . This bit can only be written in Freeze
 * mode as it is blocked by hardware in other modes.
 *
 * Values:
 * 1 - Matching starts from Mailboxes and continues on Rx FIFO
 * 0 - Matching starts from Rx FIFO and continues on Mailboxes
 */

#define BP_FLEXCAN_CTRL2_MRP      18
#define BM_FLEXCAN_CTRL2_MRP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_MRP(v)   ((((reg32_t) v) << 18) & BM_FLEXCAN_CTRL2_MRP)
#else
#define BF_FLEXCAN_CTRL2_MRP(v)   (((v) << 18) & BM_FLEXCAN_CTRL2_MRP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MRP field to a new value.
#define BW_FLEXCAN_CTRL2_MRP(v)   BF_CS1(FLEXCAN_CTRL2, MRP, v)
#endif


/* --- Register HW_FLEXCAN_CTRL2, field TASD (RW)
 *
 * This 5-bit field indicates how many CAN bits the Tx arbitration process start point can be
 * delayed from the first bit of CRC field on CAN bus {Statement} . This field can only be written
 * in Freeze mode as it is blocked by hardware in other modes.
 * FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim This field is useful to optimize the transmit performance
 * based on factors such as: peripheral/serial clock ratio, CAN bit timing and number of MBs
 * {Statement} . The duration of an arbitration process, in terms of CAN bits, is directly
 * proportional to the number of available MBs and CAN baud rate and inversely proportional to the
 * peripheral clock frequency. {Statement} The optimal arbitration timing is that in which the last
 * MB is scanned right before the first bit of the Intermission field of a CAN frame {Statement} .
 * Therefore, if there are few MBs and the system/serial clock ratio is high and the CAN baud rate
 * is low then the arbitration can be delayed and vice-versa. {Statement} If TASD is 0 then the
 * arbitration start is not delayed, thus ARM has less time to configure a Tx MB for the next
 * arbitration, but more time is reserved for arbitration {Statement} . In the other hand, if TASD
 * is 24 then ARM can configure a Tx MB later and less time is reserved for arbitration. {Statement}
 * If too little time is reserved for arbitration the FlexCAN may be not able to find winner MBs in
 * time to compete with other nodes for the CAN bus {Statement} . If the arbitration ends too much
 * time before the first bit of Intermission field then there is a chance that ARM reconfigure some
 * Tx MBs and the winner MB is not the best to be transmitted {Statement} . The reset value is
 * different on various platforms, according to their peripheral clock frequency, number of MBs and
 * target CAN baud rate {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . If ATASP bit is set TASD is
 * updated automatically by the module itself on every end of frame {Functional Test} . The optimal
 * configuration for TASD can be calculated as: {Statement} where: {Statement} f CANCLK is the
 * Protocol Engine (PE) Clock in Hz; PE clock is derrived from CAN_CLK_ROOT in CCM. See {Statement}
 * f SYS is the peripheral clock in Hz; {Statement} MAXMB is the value in CTRL1[MAXMB] field;
 * {Statement} RFEN is the value in CTRL1[RFEN] bit; {Statement} RFFN is the value in CTRL2[RFFN]
 * field; {Statement} PSEG1 is the value in CTRL1[PSEG1] field; {Statement} PSEG2 is the value in
 * CTRL1[PSEG2] field; {Statement} PROPSEG is the value in CTRL1[PROPSEG] field; {Statement} PRESDIV
 * is the value in CTRL1[PRESDIV] field. {Statement} Please refer to and for more details
 * {Statement} .
 */

#define BP_FLEXCAN_CTRL2_TASD      19
#define BM_FLEXCAN_CTRL2_TASD      0x00f80000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_TASD(v)   ((((reg32_t) v) << 19) & BM_FLEXCAN_CTRL2_TASD)
#else
#define BF_FLEXCAN_CTRL2_TASD(v)   (((v) << 19) & BM_FLEXCAN_CTRL2_TASD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TASD field to a new value.
#define BW_FLEXCAN_CTRL2_TASD(v)   BF_CS1(FLEXCAN_CTRL2, TASD, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field RFEN (RW)
 *
 * This 4-bit field defines the number of Rx FIFO filters according to {Statement} . The maximum
 * selectable number of filters is determined by the ARM {cover_rxfifo_filter} . This field can only
 * be written in Freeze mode as it is blocked by hardware in other modes
 * {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} . RFFN defines a number of Message Buffers occupied by
 * Rx FIFO and ID Filter (see ) that may not e xceed the number of available Mailboxes present in
 * module, defined by MCR[MAXMB]. {FlexCAN3RxRpsCkr,FlexCAN3IPSRpsCkr,FlexCAN3RegAccessStim} Default
 * RFFN value is 0x0, which leads to a total of 8 Rx FIFO filters, occupies the first 8 Message
 * Buffers (MB 0-7) and makes available the next Message Buffers (MB 8-63) for Mailboxes. As a
 * second example, when RFFN is set to 0xD, there will be 112 Rx FIFO filters, located in MB 0-33,
 * and MB 34-63 are available for Mailboxes {Statement} . Notice that, in this case, individual
 * masks (RXIMR) will just cover Rx FIFO filters in 0-31 range, and filters 32-111 will use RXFGMASK
 * {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . In case of reducing the number of last Message Buffers,
 * MCR[MAXMB] (see ) can be adjusted by the application to minimum of 33, in order to give room to
 * the Rx FIFO and its ID Filter Table defined by RFFN {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . On
 * the contrary, if the application sets MCR[MAXMB] to 16, for instance, the maximum RFFN is limited
 * to 0x4 {FlexCAN3RxFIFOStim,FlexCAN3RxRpsCkr} . RFFN also impacts the definition of the minimum
 * number of peripheral clocks per CAN bit as described in (see ).
 */

#define BP_FLEXCAN_CTRL2_RFEN      24
#define BM_FLEXCAN_CTRL2_RFEN      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_RFEN(v)   ((((reg32_t) v) << 24) & BM_FLEXCAN_CTRL2_RFEN)
#else
#define BF_FLEXCAN_CTRL2_RFEN(v)   (((v) << 24) & BM_FLEXCAN_CTRL2_RFEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFEN field to a new value.
#define BW_FLEXCAN_CTRL2_RFEN(v)   BF_CS1(FLEXCAN_CTRL2, RFEN, v)
#endif

/* --- Register HW_FLEXCAN_CTRL2, field WRMFRZ (RW)
 *
 * Enable unrestricted write access to FlexCAN memory in Freeze mode
 * {FlexCAN3RegAccessStim,FlexCAN3MemAccessStim} . This bit can only be written in Freeze mode and
 * has no effect out of Freeze mode. {FlexCAN3RegAccessStim,FlexCAN3MemAccessStim}
 *
 * Values:
 * 1 - Enable unrestricted write access to FlexCAN memory
 * 0 - Keep the write access restricted in some regions of FlexCAN memory
 */

#define BP_FLEXCAN_CTRL2_WRMFRZ      28
#define BM_FLEXCAN_CTRL2_WRMFRZ      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_CTRL2_WRMFRZ(v)   ((((reg32_t) v) << 28) & BM_FLEXCAN_CTRL2_WRMFRZ)
#else
#define BF_FLEXCAN_CTRL2_WRMFRZ(v)   (((v) << 28) & BM_FLEXCAN_CTRL2_WRMFRZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WRMFRZ field to a new value.
#define BW_FLEXCAN_CTRL2_WRMFRZ(v)   BF_CS1(FLEXCAN_CTRL2, WRMFRZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_ESR2 - Error and Status 2 Register (RO)
 *
 * This register reflects various interrupt flags and some general status.  LOSTRLF - Lost Rx Locked
 * Flag  This flag is asserted whenever there is a pending frame to be moved into MB or FIFO but
 * current target is being requested to be updated. LOSTRLF is cleared by writing it to '1'. When
 * CTRL2[IMEUEN] is negated, this flag is masked. CPU must clear this flag before disabling the bit.
 * Otherwise it will be set when the CTRL2[IMEUEN] is set again. Writing '0' has no effect.  1=
 * Pending move-in frame to a locked MB was cancelled due to update request.  0= no such occurrence.
 * LOSTRMF - Lost Rx Matched Flag  This flag is asserted whenever there is a winner from current
 * frame was not moved to MB or FIFO, but current target is being requested to be updated. LOSTRMF
 * is cleared by writing it to '1'. When CTRL2[IMEUEN] is negated, this flag is masked. CPU must
 * clear this flag before disabling the bit. Otherwise it will be set when the CTRL2[IMEUEN] is set
 * again. Writing '0' has no effect.  1= Current receive frame is lost because the destination is
 * being request for updating.  0= no such occurrence.  IMEUF - IMEU Flag  This flag is asserted
 * whenever there is a transition from 0 to 1 in the IMEUR[IMEUACK] bit of one or more of the
 * Mailboxes. If IMEUF is asserted the CPU should clear it and then check the state of both IMEUREQ
 * and IMEUACK bits to find out which ones can have their matching elements updated in Normal Mode.
 * IMEUF is cleared by writing it to '1' or when CTRL2[IMEUEN] is negated. Writing '0' has no
 * effect.  1= new IMEU request acknowledged.  0= no such occurrence.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 13; //!< Reserved
        unsigned IMB : 1; //!< If ESR2[VPS] is asserted, this bit indicates whether there is any inactive Mailbox (CODE field is either 0b1000 or 0b0000). {FlexCAN3TxRpsCkr} This bit is asserted in the following cases: (1) During arbitration, if a LPTM is found and it is inactive. (2) If IMB is not asserted and a frame is transmitted successfully. (3) This bit is cleared in all start of arbitration (see ). LPTM mechanism have the following behavior: if a MB is successfully transmitted and ESR2[IMB]=0 (no inactive Mailbox), then ESR2[VPS] and ESR2[IMB] are asserted and the index related to the MB just transmitted is loaded into ESR2[LPTM].
        unsigned VPS : 1; //!< This bit indicates whether IMB and LPTM contents are currently valid or not {FlexCAN3TxRpsCkr} . VPS is asserted upon every complete Tx arbitration process unless the ARM writes to Control and Status word of a Mailbox that has already been scanned (i.e. it is behind Tx Arbitration Pointer) during the Tx arbitration process {Statement} . If there is no inactive Mailbox and only one Tx Mailbox which is being transmitted then VPS is not asserted {FlexCAN3TxRpsCkr} . VPS is negated upon the start of every Tx arbitration process or upon a write to Control and Status word of any Mailbox or if Tx FIFO Successful Transmission Flag is asserted {FlexCAN3TxRpsCkr} .ESR2[VPS] is not affected by any ARM write into Control Status (C/S) of a MB which is blocked by abort mechanism. When MCR[AEN] is asserted, the abort code write in C/S of a MB that is been transmitted (pending abort), or any write attempt into a Tx MB with IFLAG set is blocked.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned LPTM : 7; //!< If ESR2[VPS] is asserted, his 7-bit field indicates the lowest number inactive Mailbox (refer to IMB bit description) {FlexCAN3TxRpsCkr} . If there is no inactive Mailbox then the Mailbox indicated depends on CTRL1[LBUF] bit value {Statement} . If CTRL1[LBUF] bit is negated then the Mailbox indicated is the one which has the greatest arbitration value (see ) {FlexCAN3TxRpsCkr} . If CTRL1[LBUF] bit is asserted then the Mailbox indicated is the highest number active Tx Mailbox {FlexCAN3TxRpsCkr} . If a Tx Mailbox is being transmitted it is not considered in LPTM calculation {FlexCAN3TxRpsCkr} . If ESR2[IMB] is not asserted and a frame is transmitted successfully, LPTM is updated with its Mailbox number.
        unsigned RESERVED2 : 9; //!< Reserved
    } B;
} hw_flexcan_esr2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ESR2 register
 */
#define HW_FLEXCAN_ESR2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ESR2(x)           (*(volatile hw_flexcan_esr2_t *) HW_FLEXCAN_ESR2_ADDR(x))
#define HW_FLEXCAN_ESR2_RD(x)        (HW_FLEXCAN_ESR2(x).U)
#endif

/*
 * constants & macros for individual FLEXCAN_ESR2 bitfields
 */

/* --- Register HW_FLEXCAN_ESR2, field IMB (RO)
 *
 * If ESR2[VPS] is asserted, this bit indicates whether there is any inactive Mailbox (CODE field is
 * either 0b1000 or 0b0000). {FlexCAN3TxRpsCkr} This bit is asserted in the following cases: (1)
 * During arbitration, if a LPTM is found and it is inactive. (2) If IMB is not asserted and a frame
 * is transmitted successfully. (3) This bit is cleared in all start of arbitration (see ). LPTM
 * mechanism have the following behavior: if a MB is successfully transmitted and ESR2[IMB]=0 (no
 * inactive Mailbox), then ESR2[VPS] and ESR2[IMB] are asserted and the index related to the MB just
 * transmitted is loaded into ESR2[LPTM].
 *
 * Values:
 * 1 - If ESR2[VPS] is asserted, there is at least one inactive Mailbox {FlexCAN3TxRpsCkr} . LPTM content
 *     is the number of the first one.
 * 0 - If ESR2[VPS] is asserted, the ESR2[LPTM] is not an inactive Mailbox.
 */

#define BP_FLEXCAN_ESR2_IMB      13
#define BM_FLEXCAN_ESR2_IMB      0x00002000


/* --- Register HW_FLEXCAN_ESR2, field VPS (RO)
 *
 * This bit indicates whether IMB and LPTM contents are currently valid or not {FlexCAN3TxRpsCkr} .
 * VPS is asserted upon every complete Tx arbitration process unless the ARM writes to Control and
 * Status word of a Mailbox that has already been scanned (i.e. it is behind Tx Arbitration Pointer)
 * during the Tx arbitration process {Statement} . If there is no inactive Mailbox and only one Tx
 * Mailbox which is being transmitted then VPS is not asserted {FlexCAN3TxRpsCkr} . VPS is negated
 * upon the start of every Tx arbitration process or upon a write to Control and Status word of any
 * Mailbox or if Tx FIFO Successful Transmission Flag is asserted {FlexCAN3TxRpsCkr} .ESR2[VPS] is
 * not affected by any ARM write into Control Status (C/S) of a MB which is blocked by abort
 * mechanism. When MCR[AEN] is asserted, the abort code write in C/S of a MB that is been
 * transmitted (pending abort), or any write attempt into a Tx MB with IFLAG set is blocked.
 *
 * Values:
 * 1 - Contents of IMB and LPTM are valid
 * 0 - Contents of IMB and LPTM are invalid
 */

#define BP_FLEXCAN_ESR2_VPS      14
#define BM_FLEXCAN_ESR2_VPS      0x00004000


/* --- Register HW_FLEXCAN_ESR2, field LPTM (RO)
 *
 * If ESR2[VPS] is asserted, his 7-bit field indicates the lowest number inactive Mailbox (refer to
 * IMB bit description) {FlexCAN3TxRpsCkr} . If there is no inactive Mailbox then the Mailbox
 * indicated depends on CTRL1[LBUF] bit value {Statement} . If CTRL1[LBUF] bit is negated then the
 * Mailbox indicated is the one which has the greatest arbitration value (see ) {FlexCAN3TxRpsCkr} .
 * If CTRL1[LBUF] bit is asserted then the Mailbox indicated is the highest number active Tx Mailbox
 * {FlexCAN3TxRpsCkr} . If a Tx Mailbox is being transmitted it is not considered in LPTM
 * calculation {FlexCAN3TxRpsCkr} . If ESR2[IMB] is not asserted and a frame is transmitted
 * successfully, LPTM is updated with its Mailbox number.
 */

#define BP_FLEXCAN_ESR2_LPTM      16
#define BM_FLEXCAN_ESR2_LPTM      0x007f0000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_CRCR - CRC Register (RO)
 *
 * This register provides information about the CRC of transmitted messages {Statement}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXCRC : 15; //!< This field indicates the CRC value of the last message transmitted {FlexCAN3IPSRpsCkr,FlexCAN3TxRpsCkr} . This field is updated at the same time the Tx Interrupt Flag is asserted.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned MBCRC : 7; //!< This field indicates the number of the Mailbox corresponding to the value in TXCRC field.
        unsigned RESERVED1 : 9; //!< Reserved
    } B;
} hw_flexcan_crcr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CRCR register
 */
#define HW_FLEXCAN_CRCR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CRCR(x)           (*(volatile hw_flexcan_crcr_t *) HW_FLEXCAN_CRCR_ADDR(x))
#define HW_FLEXCAN_CRCR_RD(x)        (HW_FLEXCAN_CRCR(x).U)
#endif

/*
 * constants & macros for individual FLEXCAN_CRCR bitfields
 */

/* --- Register HW_FLEXCAN_CRCR, field TXCRC (RO)
 *
 * This field indicates the CRC value of the last message transmitted
 * {FlexCAN3IPSRpsCkr,FlexCAN3TxRpsCkr} . This field is updated at the same time the Tx Interrupt
 * Flag is asserted.
 */

#define BP_FLEXCAN_CRCR_TXCRC      0
#define BM_FLEXCAN_CRCR_TXCRC      0x00007fff

/* --- Register HW_FLEXCAN_CRCR, field MBCRC (RO)
 *
 * This field indicates the number of the Mailbox corresponding to the value in TXCRC field.
 */

#define BP_FLEXCAN_CRCR_MBCRC      16
#define BM_FLEXCAN_CRCR_MBCRC      0x007f0000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RXFGMASK - Rx FIFO Global Mask Register (RW)
 *
 * If Rx FIFO is enabled RXFGMASK is used to mask the Rx FIFO ID Filter Table elements that do not
 * have a corresponding RXIMR according to CTRL2[RFFN] field setting in Legacy Mode and Rx FIFO ID
 * Filters 32-127 in Enhanced Mode {FlexCAN3RxRpsCkr} .  This register can only be written in Freeze
 * Mode as it is blocked by hardware in other modes {FlexCAN3RegAccessStim,FlexCAN3IPSRpsCkr} .   Rx
 * FIFO Global Mask usage in Legacy Mode {Statement}            Rx FIFO ID Filter Table Elements
 * Format (MCR[IDAM])  Identifier Acceptance Filter fields    RTR  IDE  RXIDA  RXIDB  RXIDC
 * reserved      A  FGM[ 31 0 ]  FGM[ 30 1 ]  FGM[ 29:1 2:30 ]  -  -  FGM[ 0 31 ]    B  FGM[ 31 0 ]
 * FGM[ 15 16 ]  FGM[ 30 1 ] FGM[ 14 17 ]  -  FGM[ 29:16 2:15 ] FGM[ 13:0 18:31 ] If MCR[IDAM] field
 * is equivalent to the format B only the fourteen most significant bits of the Identifier of the
 * incoming frame are compared with the Rx FIFO filter. {FlexCAN3RxRpsCkr}  -    C  -  -  -  FGM[
 * 31:24 0:7 ] FGM[ 23:16 8:15 ] FGM[ 15:8 16:23 ] FGM[ 7:0 24:31 ] If MCR[IDAM] field is equivalent
 * to the format C only the eight most significant bits of the Identifier of the incoming frame are
 * compared with the Rx FIFO filter. {FlexCAN3RxRpsCkr}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FGM31 : 32; //!< These bits mask the ID Filter Table elements bits in a perfect alignment. shows in detail which FGM bits mask each IDAF field {FlexCAN3RxRpsCkr} .
    } B;
} hw_flexcan_rxfgmask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXFGMASK register
 */
#define HW_FLEXCAN_RXFGMASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXFGMASK(x)           (*(volatile hw_flexcan_rxfgmask_t *) HW_FLEXCAN_RXFGMASK_ADDR(x))
#define HW_FLEXCAN_RXFGMASK_RD(x)        (HW_FLEXCAN_RXFGMASK(x).U)
#define HW_FLEXCAN_RXFGMASK_WR(x, v)     (HW_FLEXCAN_RXFGMASK(x).U = (v))
#define HW_FLEXCAN_RXFGMASK_SET(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) |  (v)))
#define HW_FLEXCAN_RXFGMASK_CLR(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RXFGMASK_TOG(x, v)    (HW_FLEXCAN_RXFGMASK_WR(x, HW_FLEXCAN_RXFGMASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RXFGMASK bitfields
 */

/* --- Register HW_FLEXCAN_RXFGMASK, field FGM31 (RW)
 *
 * These bits mask the ID Filter Table elements bits in a perfect alignment. shows in detail which
 * FGM bits mask each IDAF field {FlexCAN3RxRpsCkr} .
 *
 * Values:
 * 0 - The corresponding bit in the filter is "don't care"
 *     {FlexCAN3MemAccessStim,FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr}
 * 1 - The corresponding bit in the filter is checked
 *     {FlexCAN3MemAccessStim,FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr}
 */

#define BP_FLEXCAN_RXFGMASK_FGM31      0
#define BM_FLEXCAN_RXFGMASK_FGM31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXFGMASK_FGM31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXFGMASK_FGM31)
#else
#define BF_FLEXCAN_RXFGMASK_FGM31(v)   (((v) << 0) & BM_FLEXCAN_RXFGMASK_FGM31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FGM31 field to a new value.
#define BW_FLEXCAN_RXFGMASK_FGM31(v)   BF_CS1(FLEXCAN_RXFGMASK, FGM31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RXFIR - Rx FIFO Information Register (RO)
 *
 * RXFIR provides information on Rx FIFO. {FlexCAN3MemAccessStim}  This register is the port through
 * which ARM accesses the output of the RXFIR FIFO located in RAM
 * {FlexCAN3MemAccessStim,FlexCAN3RxRpsCkr} . The RXFIR FIFO is written by the FlexCAN whenever a
 * new message is moved into the Rx FIFO as well as its output is updated whenever the output of the
 * Rx FIFO is updated with the next message {FlexCAN3MemAccessStim,FlexCAN3RxRpsCkr} . Refer to to
 * find instructions on reading this register. {Statement}
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IDHIT : 9; //!< This 9-bit field indicates which Identifier Acceptance Filter (see ) was hit by the received message that is in the output of the Rx FIFO {Statement} . (refer to for details) If multiple filters match the incoming message ID then the first matching IDAF found (lowest number) by the matching process is indicated {FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr} . This field is valid only while the IFLAG[BUF5I] is asserted {FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr} .
        unsigned RESERVED0 : 23; //!< Reserved
    } B;
} hw_flexcan_rxfir_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXFIR register
 */
#define HW_FLEXCAN_RXFIR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXFIR(x)           (*(volatile hw_flexcan_rxfir_t *) HW_FLEXCAN_RXFIR_ADDR(x))
#define HW_FLEXCAN_RXFIR_RD(x)        (HW_FLEXCAN_RXFIR(x).U)
#endif

/*
 * constants & macros for individual FLEXCAN_RXFIR bitfields
 */

/* --- Register HW_FLEXCAN_RXFIR, field IDHIT (RO)
 *
 * This 9-bit field indicates which Identifier Acceptance Filter (see ) was hit by the received
 * message that is in the output of the Rx FIFO {Statement} . (refer to for details) If multiple
 * filters match the incoming message ID then the first matching IDAF found (lowest number) by the
 * matching process is indicated {FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr} . This field is valid only
 * while the IFLAG[BUF5I] is asserted {FlexCAN3IPSRpsCkr,FlexCAN3RxRpsCkr} .
 */

#define BP_FLEXCAN_RXFIR_IDHIT      0
#define BM_FLEXCAN_RXFIR_IDHIT      0x000001ff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RXIMR0-RXIMR63 - Rx Individual Mask Registers (RW)
 *
 * RXIMR are used as acceptance masks for ID filtering in Rx MBs and the Rx FIFO {Statement} . If
 * the Rx FIFO is not enabled, one mask register is provided for each available Mailbox, providing
 * ID masking capability on a per Mailbox basis. {FlexCAN3RxRpsCkr}  In Legacy Mode only the first
 * 64 masks are available (RXIMR0-63) {FlexCAN3RxRpsCkr} . When the Rx FIFO is enabled (MCR[RFEN]
 * bit is asserted), up to 32 Rx Individual Mask Registers can apply to the Rx FIFO ID Filter Table
 * elements on a one-to-one correspondence depending on CTRL2[RFFN] setting {FlexCAN3RxRpsCkr} .
 * Refer to for details {Statement} .  RXIMR can only be written by the ARM either while the module
 * is in Freeze Mode or when IMEU is enabled (CTRL2[IMEUEN] asserted) , otherwise they are blocked
 * by hardware {FlexCAN3MemAccessStim} {Statement} .  The Individual Rx Mask Registers are not
 * affected by reset and must be explicitly initialized prior to any reception
 * {FlexCAN3MemAccessStim} .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MI31 : 32; //!< These bits mask both Mailbox filter and Rx FIFO ID Filter Table element in distinct ways. {Statement} For Mailbox filter refer to {Statement} . For Rx FIFO ID Filter Table element refer to {Statement} .
    } B;
} hw_flexcan_rximr0-rximr63_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXIMR0-RXIMR63 register
 */
#define HW_FLEXCAN_RXIMR0-RXIMR63_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXIMR0-RXIMR63(x)           (*(volatile hw_flexcan_rximr0-rximr63_t *) HW_FLEXCAN_RXIMR0-RXIMR63_ADDR(x))
#define HW_FLEXCAN_RXIMR0-RXIMR63_RD(x)        (HW_FLEXCAN_RXIMR0-RXIMR63(x).U)
#define HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, v)     (HW_FLEXCAN_RXIMR0-RXIMR63(x).U = (v))
#define HW_FLEXCAN_RXIMR0-RXIMR63_SET(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) |  (v)))
#define HW_FLEXCAN_RXIMR0-RXIMR63_CLR(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) & ~(v)))
#define HW_FLEXCAN_RXIMR0-RXIMR63_TOG(x, v)    (HW_FLEXCAN_RXIMR0-RXIMR63_WR(x, HW_FLEXCAN_RXIMR0-RXIMR63_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RXIMR0-RXIMR63 bitfields
 */

/* --- Register HW_FLEXCAN_RXIMR0-RXIMR63, field MI31 (RW)
 *
 * These bits mask both Mailbox filter and Rx FIFO ID Filter Table element in distinct ways.
 * {Statement} For Mailbox filter refer to {Statement} . For Rx FIFO ID Filter Table element refer
 * to {Statement} .
 *
 * Values:
 * 0 - the corresponding bit in the filter is "don't care"
 * 1 - The corresponding bit in the filter is checked
 */

#define BP_FLEXCAN_RXIMR0-RXIMR63_MI31      0
#define BM_FLEXCAN_RXIMR0-RXIMR63_MI31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_RXIMR0-RXIMR63_MI31)
#else
#define BF_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   (((v) << 0) & BM_FLEXCAN_RXIMR0-RXIMR63_MI31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31 field to a new value.
#define BW_FLEXCAN_RXIMR0-RXIMR63_MI31(v)   BF_CS1(FLEXCAN_RXIMR0-RXIMR63, MI31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_GFWR - Glitch Filter Width Registers (RW)
 *
 * The Glitch Filter just takes effects when FLEXCAN enters the STOP mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GFWR : 8; //!< It determines the Glitch Filter Width. The width will be divided from Oscillator clock by GFWR values. By default, it is 5.33us when the oscillator is 24MHz.
        unsigned RESERVED0 : 24; //!< Reserved
    } B;
} hw_flexcan_gfwr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_GFWR register
 */
#define HW_FLEXCAN_GFWR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x9e0)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_GFWR(x)           (*(volatile hw_flexcan_gfwr_t *) HW_FLEXCAN_GFWR_ADDR(x))
#define HW_FLEXCAN_GFWR_RD(x)        (HW_FLEXCAN_GFWR(x).U)
#define HW_FLEXCAN_GFWR_WR(x, v)     (HW_FLEXCAN_GFWR(x).U = (v))
#define HW_FLEXCAN_GFWR_SET(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) |  (v)))
#define HW_FLEXCAN_GFWR_CLR(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) & ~(v)))
#define HW_FLEXCAN_GFWR_TOG(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_GFWR bitfields
 */

/* --- Register HW_FLEXCAN_GFWR, field GFWR (RW)
 *
 * It determines the Glitch Filter Width. The width will be divided from Oscillator clock by GFWR
 * values. By default, it is 5.33us when the oscillator is 24MHz.
 */

#define BP_FLEXCAN_GFWR_GFWR      0
#define BM_FLEXCAN_GFWR_GFWR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_FLEXCAN_GFWR_GFWR(v)   ((((reg32_t) v) << 0) & BM_FLEXCAN_GFWR_GFWR)
#else
#define BF_FLEXCAN_GFWR_GFWR(v)   (((v) << 0) & BM_FLEXCAN_GFWR_GFWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GFWR field to a new value.
#define BW_FLEXCAN_GFWR_GFWR(v)   BF_CS1(FLEXCAN_GFWR, GFWR, v)
#endif


/*!
 * @brief All FLEXCAN module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_flexcan_mcr_t MCR; //!< Module Configuration Register
    volatile hw_flexcan_ctrl1_t CTRL1; //!< Control 1 Register
    volatile hw_flexcan_timer_t TIMER; //!< Free Running Timer Register
    reg32_t _reserved0;
    volatile hw_flexcan_rxmgmask_t RXMGMASK; //!< Rx Mailboxes Global Mask Register
    volatile hw_flexcan_rx14mask_t RX14MASK; //!< Rx Buffer 14 Mask Register
    volatile hw_flexcan_rx15mask_t RX15MASK; //!< Rx Buffer 15 Mask Register
    volatile hw_flexcan_ecr_t ECR; //!< Error Counter Register
    volatile hw_flexcan_esr1_t ESR1; //!< Error and Status 1 Register
    volatile hw_flexcan_imask2_t IMASK2; //!< Interrupt Masks 2 Register
    volatile hw_flexcan_imask1_t IMASK1; //!< Interrupt Masks 1 Register
    volatile hw_flexcan_iflag2_t IFLAG2; //!< Interrupt Flags 2 Register
    volatile hw_flexcan_iflag1_t IFLAG1; //!< Interrupt Flags 1 Register
    volatile hw_flexcan_ctrl2_t CTRL2; //!< Control 2 Register
    volatile hw_flexcan_esr2_t ESR2; //!< Error and Status 2 Register
    reg32_t _reserved1[2];
    volatile hw_flexcan_crcr_t CRCR; //!< CRC Register
    volatile hw_flexcan_rxfgmask_t RXFGMASK; //!< Rx FIFO Global Mask Register
    volatile hw_flexcan_rxfir_t RXFIR; //!< Rx FIFO Information Register
    reg32_t _reserved2[524];
    volatile hw_flexcan_rximr0-rximr63_t RXIMR0-RXIMR63; //!< Rx Individual Mask Registers
    reg32_t _reserved3[87];
    volatile hw_flexcan_gfwr_t GFWR; //!< Glitch Filter Width Registers
} hw_flexcan_t
#endif

//! @brief Macro to access all FLEXCAN registers.
//! @param x FLEXCAN instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_FLEXCAN(0)</code>.
#define HW_FLEXCAN(x)     (*(volatile hw_flexcan_t *) REGS_FLEXCAN_BASE(x))


#endif // _FLEXCAN_H
