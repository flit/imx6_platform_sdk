/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMAARM_H
#define _SDMAARM_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_SDMAARM_MC0PTR - ARM platform Channel 0 Pointer
 * - HW_SDMAARM_INTR - Channel Interrupts
 * - HW_SDMAARM_STOP_STAT - Channel Stop/Channel Status
 * - HW_SDMAARM_HSTART - Channel Start
 * - HW_SDMAARM_EVTOVR - Channel Event Override
 * - HW_SDMAARM_DSPOVR - Channel BP Override
 * - HW_SDMAARM_HOSTOVR - Channel ARM platform Override
 * - HW_SDMAARM_EVTPEND - Channel Event Pending
 * - HW_SDMAARM_RESET - Reset Register
 * - HW_SDMAARM_EVTERR - DMA Request Error Register
 * - HW_SDMAARM_INTRMASK - Channel ARM platform Interrupt Mask
 * - HW_SDMAARM_PSW - Schedule Status
 * - HW_SDMAARM_EVTERRDBG - DMA Request Error Register
 * - HW_SDMAARM_CONFIG - Configuration Register
 * - HW_SDMAARM_SDMA_LOCK - SDMA LOCK
 * - HW_SDMAARM_ONCE_ENB - OnCE Enable
 * - HW_SDMAARM_ONCE_DATA - OnCE Data Register
 * - HW_SDMAARM_ONCE_INSTR - OnCE Instruction Register
 * - HW_SDMAARM_ONCE_STAT - OnCE Status Register
 * - HW_SDMAARM_ONCE_CMD - OnCE Command Register
 * - HW_SDMAARM_ILLINSTADDR - Illegal Instruction Trap Address
 * - HW_SDMAARM_CHN0ADDR - Channel 0 Boot Address
 * - HW_SDMAARM_EVT_MIRROR - DMA Requests
 * - HW_SDMAARM_EVT_MIRROR2 - DMA Requests 2
 * - HW_SDMAARM_XTRIG_CONF1 - Cross-Trigger Events Configuration Register 1
 * - HW_SDMAARM_XTRIG_CONF2 - Cross-Trigger Events Configuration Register 2
 * - HW_SDMAARM_SDMA_CHNPRI - Channel Priority Registers
 * - HW_SDMAARM_SDMA.CHNENBL - Channel Enable RAM
 *
 * hw_sdmaarm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SDMAARM_BASE
#define REGS_SDMAARM_BASE (0x020ec000) //!< Base address for SDMAARM.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_MC0PTR - ARM platform Channel 0 Pointer (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MC0PTR : 32; //!< Channel 0 Pointer contains the 32-bit address, in ARM platform memory, of channel 0 control block (the boot channel). Appendix A fully describes the SDMA Application Programming Interface (API). The ARM platform has a read/write access and the SDMA has a read-only access.
    } B;
} hw_sdmaarm_mc0ptr_t;
#endif

/*
 * constants & macros for entire SDMAARM_MC0PTR register
 */
#define HW_SDMAARM_MC0PTR_ADDR      (REGS_SDMAARM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_MC0PTR           (*(volatile hw_sdmaarm_mc0ptr_t *) HW_SDMAARM_MC0PTR_ADDR)
#define HW_SDMAARM_MC0PTR_RD()      (HW_SDMAARM_MC0PTR.U)
#define HW_SDMAARM_MC0PTR_WR(v)     (HW_SDMAARM_MC0PTR.U = (v))
#define HW_SDMAARM_MC0PTR_SET(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() |  (v)))
#define HW_SDMAARM_MC0PTR_CLR(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() & ~(v)))
#define HW_SDMAARM_MC0PTR_TOG(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_MC0PTR bitfields
 */

/* --- Register HW_SDMAARM_MC0PTR, field MC0PTR (RW)
 *
 * Channel 0 Pointer contains the 32-bit address, in ARM platform memory, of channel 0 control block
 * (the boot channel). Appendix A fully describes the SDMA Application Programming Interface (API).
 * The ARM platform has a read/write access and the SDMA has a read-only access.
 */

#define BP_SDMAARM_MC0PTR_MC0PTR      0
#define BM_SDMAARM_MC0PTR_MC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_MC0PTR_MC0PTR)
#else
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   (((v) << 0) & BM_SDMAARM_MC0PTR_MC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MC0PTR field to a new value.
#define BW_SDMAARM_MC0PTR_MC0PTR(v)   BF_CS1(SDMAARM_MC0PTR, MC0PTR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_INTR - Channel Interrupts (W1C)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HI : 32; //!< The ARM platform Interrupts register contains the 32 HI[i] bits. If any bit is set, it will cause an interrupt to the ARM platform. This register is a "write-ones" register to the ARM platform. When the ARM platform sets a bit in this register the corresponding HI[i] bit is cleared. The interrupt service routine should clear individual channel bits when their interrupts are serviced, failure to do so will cause continuous interrupts. The SDMA is responsible for setting the HI[i] bit corresponding to the current channel when the corresponding done instruction is executed.
    } B;
} hw_sdmaarm_intr_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTR register
 */
#define HW_SDMAARM_INTR_ADDR      (REGS_SDMAARM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTR           (*(volatile hw_sdmaarm_intr_t *) HW_SDMAARM_INTR_ADDR)
#define HW_SDMAARM_INTR_RD()      (HW_SDMAARM_INTR.U)
#endif

/*
 * constants & macros for individual SDMAARM_INTR bitfields
 */

/* --- Register HW_SDMAARM_INTR, field HI (W1C)
 *
 * The ARM platform Interrupts register contains the 32 HI[i] bits. If any bit is set, it will cause
 * an interrupt to the ARM platform. This register is a "write-ones" register to the ARM platform.
 * When the ARM platform sets a bit in this register the corresponding HI[i] bit is cleared. The
 * interrupt service routine should clear individual channel bits when their interrupts are
 * serviced, failure to do so will cause continuous interrupts. The SDMA is responsible for setting
 * the HI[i] bit corresponding to the current channel when the corresponding done instruction is
 * executed.
 */

#define BP_SDMAARM_INTR_HI      0
#define BM_SDMAARM_INTR_HI      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_STOP_STAT - Channel Stop/Channel Status (w1c)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HE : 32; //!< This 32-bit register gives access to the ARM platform Enable bits. There is one bit for every channel. This register is a "write-ones" register to the ARM platform. When the ARM platform writes 1 in bit i of this register, it clears the HE[i] and HSTART[i] bits. Reading this register yields the current state of the HE[i] bits.
    } B;
} hw_sdmaarm_stop_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_STOP_STAT register
 */
#define HW_SDMAARM_STOP_STAT_ADDR      (REGS_SDMAARM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_STOP_STAT           (*(volatile hw_sdmaarm_stop_stat_t *) HW_SDMAARM_STOP_STAT_ADDR)
#define HW_SDMAARM_STOP_STAT_RD()      (HW_SDMAARM_STOP_STAT.U)
#endif

/*
 * constants & macros for individual SDMAARM_STOP_STAT bitfields
 */

/* --- Register HW_SDMAARM_STOP_STAT, field HE (W1C)
 *
 * This 32-bit register gives access to the ARM platform Enable bits. There is one bit for every
 * channel. This register is a "write-ones" register to the ARM platform. When the ARM platform
 * writes 1 in bit i of this register, it clears the HE[i] and HSTART[i] bits. Reading this register
 * yields the current state of the HE[i] bits.
 */

#define BP_SDMAARM_STOP_STAT_HE      0
#define BM_SDMAARM_STOP_STAT_HE      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_HSTART - Channel Start (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HSTART : 32; //!< The HSTART/HE registers are 32 bits wide with one bit for every channel. When a bit is written to 1, it enables the corresponding channel. Two physical registers are accessed with that address (HSTART and HE), which enables the ARM platform to trigger a channel a second time before the first trigger is processed. This register is a "write-ones" register to the ARM platform. Neither HSTART[i] bit can be set while the corresponding HE[i] bit is cleared. When the ARM platform tries to set the HSTART[i] bit by writing a one (if the corresponding HE[i] bit is clear), the bit in the HSTART[i] register will remain cleared and the HE[i] bit will be set. If the corresponding HE[i] bit was already set, the HSTART[i] bit will be set. The next time the SDMA channel i attempts to clear the HE[i] bit by means of a done instruction, the bit in the HSTART[i] register will be cleared and the HE[i] bit will take the old value of the HSTART[i] bit. Reading this register yields the current state of the HSTART[i] bits. This mechanism enables the ARM platform to pipeline two HSTART commands per channel.
    } B;
} hw_sdmaarm_hstart_t;
#endif

/*
 * constants & macros for entire SDMAARM_HSTART register
 */
#define HW_SDMAARM_HSTART_ADDR      (REGS_SDMAARM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HSTART           (*(volatile hw_sdmaarm_hstart_t *) HW_SDMAARM_HSTART_ADDR)
#define HW_SDMAARM_HSTART_RD()      (HW_SDMAARM_HSTART.U)
#define HW_SDMAARM_HSTART_WR(v)     (HW_SDMAARM_HSTART.U = (v))
#define HW_SDMAARM_HSTART_SET(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() |  (v)))
#define HW_SDMAARM_HSTART_CLR(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() & ~(v)))
#define HW_SDMAARM_HSTART_TOG(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_HSTART bitfields
 */

/* --- Register HW_SDMAARM_HSTART, field HSTART (W1C)
 *
 * The HSTART/HE registers are 32 bits wide with one bit for every channel. When a bit is written to
 * 1, it enables the corresponding channel. Two physical registers are accessed with that address
 * (HSTART and HE), which enables the ARM platform to trigger a channel a second time before the
 * first trigger is processed. This register is a "write-ones" register to the ARM platform. Neither
 * HSTART[i] bit can be set while the corresponding HE[i] bit is cleared. When the ARM platform
 * tries to set the HSTART[i] bit by writing a one (if the corresponding HE[i] bit is clear), the
 * bit in the HSTART[i] register will remain cleared and the HE[i] bit will be set. If the
 * corresponding HE[i] bit was already set, the HSTART[i] bit will be set. The next time the SDMA
 * channel i attempts to clear the HE[i] bit by means of a done instruction, the bit in the
 * HSTART[i] register will be cleared and the HE[i] bit will take the old value of the HSTART[i]
 * bit. Reading this register yields the current state of the HSTART[i] bits. This mechanism enables
 * the ARM platform to pipeline two HSTART commands per channel.
 */

#define BP_SDMAARM_HSTART_HSTART      0
#define BM_SDMAARM_HSTART_HSTART      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTOVR - Channel Event Override (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EO : 32; //!< The Channel Event Override register contains the 32 EO[i] bits. A bit set in this register causes the SDMA to ignore DMA requests when scheduling the corresponding channel.
    } B;
} hw_sdmaarm_evtovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTOVR register
 */
#define HW_SDMAARM_EVTOVR_ADDR      (REGS_SDMAARM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTOVR           (*(volatile hw_sdmaarm_evtovr_t *) HW_SDMAARM_EVTOVR_ADDR)
#define HW_SDMAARM_EVTOVR_RD()      (HW_SDMAARM_EVTOVR.U)
#define HW_SDMAARM_EVTOVR_WR(v)     (HW_SDMAARM_EVTOVR.U = (v))
#define HW_SDMAARM_EVTOVR_SET(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() |  (v)))
#define HW_SDMAARM_EVTOVR_CLR(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() & ~(v)))
#define HW_SDMAARM_EVTOVR_TOG(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_EVTOVR bitfields
 */

/* --- Register HW_SDMAARM_EVTOVR, field EO (RW)
 *
 * The Channel Event Override register contains the 32 EO[i] bits. A bit set in this register causes
 * the SDMA to ignore DMA requests when scheduling the corresponding channel.
 */

#define BP_SDMAARM_EVTOVR_EO      0
#define BM_SDMAARM_EVTOVR_EO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_EVTOVR_EO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_EVTOVR_EO)
#else
#define BF_SDMAARM_EVTOVR_EO(v)   (((v) << 0) & BM_SDMAARM_EVTOVR_EO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EO field to a new value.
#define BW_SDMAARM_EVTOVR_EO(v)   BF_CS1(SDMAARM_EVTOVR, EO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_DSPOVR - Channel BP Override (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DO : 32; //!< The Channel BP Override register contains the 32 DO[i] bits. A bit set in this register causes the SDMA to ignore a BP enable condition when scheduling the corresponding channel. By default, all DO[i] bits are set to 1, which means that register can be ignored when the BP connections are not used. This register is reserved. All DO bits should be set to the reset value of 1. A setting of 0 will prevent SDMA channels from starting according to the condition described in .
    } B;
} hw_sdmaarm_dspovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_DSPOVR register
 */
#define HW_SDMAARM_DSPOVR_ADDR      (REGS_SDMAARM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_DSPOVR           (*(volatile hw_sdmaarm_dspovr_t *) HW_SDMAARM_DSPOVR_ADDR)
#define HW_SDMAARM_DSPOVR_RD()      (HW_SDMAARM_DSPOVR.U)
#define HW_SDMAARM_DSPOVR_WR(v)     (HW_SDMAARM_DSPOVR.U = (v))
#define HW_SDMAARM_DSPOVR_SET(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() |  (v)))
#define HW_SDMAARM_DSPOVR_CLR(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() & ~(v)))
#define HW_SDMAARM_DSPOVR_TOG(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_DSPOVR bitfields
 */

/* --- Register HW_SDMAARM_DSPOVR, field DO (RW)
 *
 * The Channel BP Override register contains the 32 DO[i] bits. A bit set in this register causes
 * the SDMA to ignore a BP enable condition when scheduling the corresponding channel. By default,
 * all DO[i] bits are set to 1, which means that register can be ignored when the BP connections are
 * not used. This register is reserved. All DO bits should be set to the reset value of 1. A setting
 * of 0 will prevent SDMA channels from starting according to the condition described in .
 *
 * Values:
 * 0 - - Reserved
 * 1 - - Reset value.
 */

#define BP_SDMAARM_DSPOVR_DO      0
#define BM_SDMAARM_DSPOVR_DO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_DSPOVR_DO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_DSPOVR_DO)
#else
#define BF_SDMAARM_DSPOVR_DO(v)   (((v) << 0) & BM_SDMAARM_DSPOVR_DO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DO field to a new value.
#define BW_SDMAARM_DSPOVR_DO(v)   BF_CS1(SDMAARM_DSPOVR, DO, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_HOSTOVR - Channel ARM platform Override (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HO : 32; //!< The Channel ARM platform Override register contains the 32 HO[i] bits. A bit set in this register causes the SDMA to ignore the ARM platform enable bit (HE) when scheduling the corresponding channel.
    } B;
} hw_sdmaarm_hostovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_HOSTOVR register
 */
#define HW_SDMAARM_HOSTOVR_ADDR      (REGS_SDMAARM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HOSTOVR           (*(volatile hw_sdmaarm_hostovr_t *) HW_SDMAARM_HOSTOVR_ADDR)
#define HW_SDMAARM_HOSTOVR_RD()      (HW_SDMAARM_HOSTOVR.U)
#define HW_SDMAARM_HOSTOVR_WR(v)     (HW_SDMAARM_HOSTOVR.U = (v))
#define HW_SDMAARM_HOSTOVR_SET(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() |  (v)))
#define HW_SDMAARM_HOSTOVR_CLR(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() & ~(v)))
#define HW_SDMAARM_HOSTOVR_TOG(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_HOSTOVR bitfields
 */

/* --- Register HW_SDMAARM_HOSTOVR, field HO (RW)
 *
 * The Channel ARM platform Override register contains the 32 HO[i] bits. A bit set in this register
 * causes the SDMA to ignore the ARM platform enable bit (HE) when scheduling the corresponding
 * channel.
 */

#define BP_SDMAARM_HOSTOVR_HO      0
#define BM_SDMAARM_HOSTOVR_HO      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_HOSTOVR_HO(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_HOSTOVR_HO)
#else
#define BF_SDMAARM_HOSTOVR_HO(v)   (((v) << 0) & BM_SDMAARM_HOSTOVR_HO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HO field to a new value.
#define BW_SDMAARM_HOSTOVR_HO(v)   BF_CS1(SDMAARM_HOSTOVR, HO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTPEND - Channel Event Pending (W1C)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EP : 32; //!< The Channel Event Pending register contains the 32 EP[i] bits. Reading this register enables the ARM platform to determine what channels are pending after the reception of a DMA request. Setting a bit in this register causes the SDMA to reevaluate scheduling as if a DMA request mapped on this channel had occurred. This is useful for starting up channels, so that initialization is done before awaiting the first request. The scheduler can also set bits in the EVTPEND register according to the received DMA requests. The EP[i] bit may be cleared by the done instruction when running the channel i script. This a "write-ones" mechanism: Writing a '0' does not clear the corresponding bit.
    } B;
} hw_sdmaarm_evtpend_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTPEND register
 */
#define HW_SDMAARM_EVTPEND_ADDR      (REGS_SDMAARM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTPEND           (*(volatile hw_sdmaarm_evtpend_t *) HW_SDMAARM_EVTPEND_ADDR)
#define HW_SDMAARM_EVTPEND_RD()      (HW_SDMAARM_EVTPEND.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVTPEND bitfields
 */

/* --- Register HW_SDMAARM_EVTPEND, field EP (W1C)
 *
 * The Channel Event Pending register contains the 32 EP[i] bits. Reading this register enables the
 * ARM platform to determine what channels are pending after the reception of a DMA request. Setting
 * a bit in this register causes the SDMA to reevaluate scheduling as if a DMA request mapped on
 * this channel had occurred. This is useful for starting up channels, so that initialization is
 * done before awaiting the first request. The scheduler can also set bits in the EVTPEND register
 * according to the received DMA requests. The EP[i] bit may be cleared by the done instruction when
 * running the channel i script. This a "write-ones" mechanism: Writing a '0' does not clear the
 * corresponding bit.
 */

#define BP_SDMAARM_EVTPEND_EP      0
#define BM_SDMAARM_EVTPEND_EP      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_RESET - Reset Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESET : 1; //!< When set, this bit causes the SDMA to be held in a software reset. The internal reset signal is held low 16 cycles; the RESET bit is automatically cleared when the internal reset signal rises.
        unsigned RESCHED : 1; //!< When set, this bit forces the SDMA to reschedule as if a script had executed a done instruction. This enables the ARM platform to recover from a runaway script on a channel by clearing its HE[i] bit via the STOP register, and then forcing a reschedule via the RESCHED bit. The RESCHED bit is cleared when the context switch starts.
        unsigned RESERVED0 : 30; //!< Reserved
    } B;
} hw_sdmaarm_reset_t;
#endif

/*
 * constants & macros for entire SDMAARM_RESET register
 */
#define HW_SDMAARM_RESET_ADDR      (REGS_SDMAARM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_RESET           (*(volatile hw_sdmaarm_reset_t *) HW_SDMAARM_RESET_ADDR)
#define HW_SDMAARM_RESET_RD()      (HW_SDMAARM_RESET.U)
#endif

/*
 * constants & macros for individual SDMAARM_RESET bitfields
 */

/* --- Register HW_SDMAARM_RESET, field RESET (RO)
 *
 * When set, this bit causes the SDMA to be held in a software reset. The internal reset signal is
 * held low 16 cycles; the RESET bit is automatically cleared when the internal reset signal rises.
 */

#define BP_SDMAARM_RESET_RESET      0
#define BM_SDMAARM_RESET_RESET      0x00000001

/* --- Register HW_SDMAARM_RESET, field RESCHED (RO)
 *
 * When set, this bit forces the SDMA to reschedule as if a script had executed a done instruction.
 * This enables the ARM platform to recover from a runaway script on a channel by clearing its HE[i]
 * bit via the STOP register, and then forcing a reschedule via the RESCHED bit. The RESCHED bit is
 * cleared when the context switch starts.
 */

#define BP_SDMAARM_RESET_RESCHED      1
#define BM_SDMAARM_RESET_RESCHED      0x00000002

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTERR - DMA Request Error Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHNERR : 32; //!< This register is used by the SDMA to warn the ARM platform when an incoming DMA request was detected and it triggers a channel that is already pending or being serviced. This probably means there is an overflow of data for that channel. An interrupt is sent to the ARM platform if the corresponding channel bit is set in the INTRMASK register. This is a "write-ones" register for the scheduler. It is only able to set the flags. The flags are cleared when the register is read by the ARM platform or during SDMA reset. The CHNERR[i] bit is set when a DMA request that triggers channel i is received through the corresponding input pins and the EP[i] bit is already set; the EVTERR[i] bit is unaffected if the ARM platform tries to set the EP[i] bit, whereas, that EP[i] bit is already set.
    } B;
} hw_sdmaarm_evterr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERR register
 */
#define HW_SDMAARM_EVTERR_ADDR      (REGS_SDMAARM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERR           (*(volatile hw_sdmaarm_evterr_t *) HW_SDMAARM_EVTERR_ADDR)
#define HW_SDMAARM_EVTERR_RD()      (HW_SDMAARM_EVTERR.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVTERR bitfields
 */

/* --- Register HW_SDMAARM_EVTERR, field CHNERR (RO)
 *
 * This register is used by the SDMA to warn the ARM platform when an incoming DMA request was
 * detected and it triggers a channel that is already pending or being serviced. This probably means
 * there is an overflow of data for that channel. An interrupt is sent to the ARM platform if the
 * corresponding channel bit is set in the INTRMASK register. This is a "write-ones" register for
 * the scheduler. It is only able to set the flags. The flags are cleared when the register is read
 * by the ARM platform or during SDMA reset. The CHNERR[i] bit is set when a DMA request that
 * triggers channel i is received through the corresponding input pins and the EP[i] bit is already
 * set; the EVTERR[i] bit is unaffected if the ARM platform tries to set the EP[i] bit, whereas,
 * that EP[i] bit is already set.
 */

#define BP_SDMAARM_EVTERR_CHNERR      0
#define BM_SDMAARM_EVTERR_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_INTRMASK - Channel ARM platform Interrupt Mask (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HIMASK : 32; //!< The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit HIMASK[i] is set, the HI[i] bit is set and an interrupt is sent to the ARM platform when a DMA request error is detected on channel i (for example, EVTERR[i] is set).
    } B;
} hw_sdmaarm_intrmask_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTRMASK register
 */
#define HW_SDMAARM_INTRMASK_ADDR      (REGS_SDMAARM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTRMASK           (*(volatile hw_sdmaarm_intrmask_t *) HW_SDMAARM_INTRMASK_ADDR)
#define HW_SDMAARM_INTRMASK_RD()      (HW_SDMAARM_INTRMASK.U)
#define HW_SDMAARM_INTRMASK_WR(v)     (HW_SDMAARM_INTRMASK.U = (v))
#define HW_SDMAARM_INTRMASK_SET(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() |  (v)))
#define HW_SDMAARM_INTRMASK_CLR(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() & ~(v)))
#define HW_SDMAARM_INTRMASK_TOG(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_INTRMASK bitfields
 */

/* --- Register HW_SDMAARM_INTRMASK, field HIMASK (RW)
 *
 * The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit HIMASK[i] is set,
 * the HI[i] bit is set and an interrupt is sent to the ARM platform when a DMA request error is
 * detected on channel i (for example, EVTERR[i] is set).
 */

#define BP_SDMAARM_INTRMASK_HIMASK      0
#define BM_SDMAARM_INTRMASK_HIMASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_INTRMASK_HIMASK(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_INTRMASK_HIMASK)
#else
#define BF_SDMAARM_INTRMASK_HIMASK(v)   (((v) << 0) & BM_SDMAARM_INTRMASK_HIMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIMASK field to a new value.
#define BW_SDMAARM_INTRMASK_HIMASK(v)   BF_CS1(SDMAARM_INTRMASK, HIMASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_PSW - Schedule Status (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CCR : 4; //!< The Current Channel Register indicates the number of the channel that is being executed by the SDMA. SDMA. In the case that the SDMA has finished running the channel and has entered sleep state, CCR will indicate the previous running channel.
        unsigned CCP : 4; //!< The Current Channel Priority indicates the priority of the current active channel. When the priority is 0, no channel is running: The SDMA is idle and the CCR value has no meaning. In the case that the SDMA has finished running the channel and has entered sleep state, CCP will indicate the priority of previous running channel.
        unsigned NCR : 5; //!< The Next Channel Register indicates the number of the next scheduled pending channel with the highest priority.
        unsigned NCP : 3; //!< The Next Channel Priority gives the next pending channel priority. When the priority is 0, it means there is no pending channel and the NCR value has no meaning.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmaarm_psw_t;
#endif

/*
 * constants & macros for entire SDMAARM_PSW register
 */
#define HW_SDMAARM_PSW_ADDR      (REGS_SDMAARM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_PSW           (*(volatile hw_sdmaarm_psw_t *) HW_SDMAARM_PSW_ADDR)
#define HW_SDMAARM_PSW_RD()      (HW_SDMAARM_PSW.U)
#endif

/*
 * constants & macros for individual SDMAARM_PSW bitfields
 */

/* --- Register HW_SDMAARM_PSW, field CCR (RO)
 *
 * The Current Channel Register indicates the number of the channel that is being executed by the
 * SDMA. SDMA. In the case that the SDMA has finished running the channel and has entered sleep
 * state, CCR will indicate the previous running channel.
 */

#define BP_SDMAARM_PSW_CCR      0
#define BM_SDMAARM_PSW_CCR      0x0000000f

/* --- Register HW_SDMAARM_PSW, field CCP (RO)
 *
 * The Current Channel Priority indicates the priority of the current active channel. When the
 * priority is 0, no channel is running: The SDMA is idle and the CCR value has no meaning. In the
 * case that the SDMA has finished running the channel and has entered sleep state, CCP will
 * indicate the priority of previous running channel.
 *
 * Values:
 * 0 - No running channel
 * 1 - Active channel priority
 */

#define BP_SDMAARM_PSW_CCP      4
#define BM_SDMAARM_PSW_CCP      0x000000f0


/* --- Register HW_SDMAARM_PSW, field NCR (RO)
 *
 * The Next Channel Register indicates the number of the next scheduled pending channel with the
 * highest priority.
 */

#define BP_SDMAARM_PSW_NCR      8
#define BM_SDMAARM_PSW_NCR      0x00001f00

/* --- Register HW_SDMAARM_PSW, field NCP (RO)
 *
 * The Next Channel Priority gives the next pending channel priority. When the priority is 0, it
 * means there is no pending channel and the NCR value has no meaning.
 *
 * Values:
 * 0 - No running channel
 * 1 - Active channel priority
 */

#define BP_SDMAARM_PSW_NCP      13
#define BM_SDMAARM_PSW_NCP      0x0000e000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTERRDBG - DMA Request Error Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHNERR : 32; //!< This register is the same as EVTERR, except reading it does not clear its contents. This address is meant to be used in debug mode. The ARM platform OnCE may check this register value without modifying it.
    } B;
} hw_sdmaarm_evterrdbg_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERRDBG register
 */
#define HW_SDMAARM_EVTERRDBG_ADDR      (REGS_SDMAARM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERRDBG           (*(volatile hw_sdmaarm_evterrdbg_t *) HW_SDMAARM_EVTERRDBG_ADDR)
#define HW_SDMAARM_EVTERRDBG_RD()      (HW_SDMAARM_EVTERRDBG.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVTERRDBG bitfields
 */

/* --- Register HW_SDMAARM_EVTERRDBG, field CHNERR (RO)
 *
 * This register is the same as EVTERR, except reading it does not clear its contents. This address
 * is meant to be used in debug mode. The ARM platform OnCE may check this register value without
 * modifying it.
 */

#define BP_SDMAARM_EVTERRDBG_CHNERR      0
#define BM_SDMAARM_EVTERRDBG_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_CONFIG - Configuration Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CSM : 2; //!< Selects the Context Switch Mode. The ARM platform has a read/write access. The SDMA cannot modify that register. The value at reset is 3, which selects the dynamic context switch by default. That register can be modified at anytime but the new context switch configuration will only be taken into account at the start of the next restore phase. NOTE: The first call to SDMA's channel 0 Bootload script after reset should use static context switch mode to ensure the context RAM for channel 0 is initialized in the channel SAVE Phase. After Channel 0 is run once, then any of the dynamic context modes can be used.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned ACR : 1; //!< ARM platform DMA / SDMA Core Clock Ratio. Selects the clock ratio between ARM platform DMA interfaces (burst DMA and burst DMA2 and peripheral DMA ) and the internal SDMA core clock. The frequency selection is determined separately by the chip clock controller. This bit has to match the configuration of the chip clock controller that generates the clocks used in the SDMA.
        unsigned RESERVED1 : 6; //!< Reserved
        unsigned RTDOBS : 1; //!< Indicates if Real-Time Debug pins are used: They do not toggle by default in order to reduce power consumption.
        unsigned DSPDMA : 1; //!< This bit's function is reserved and should be configured as zero.
        unsigned RESERVED2 : 19; //!< Reserved
    } B;
} hw_sdmaarm_config_t;
#endif

/*
 * constants & macros for entire SDMAARM_CONFIG register
 */
#define HW_SDMAARM_CONFIG_ADDR      (REGS_SDMAARM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CONFIG           (*(volatile hw_sdmaarm_config_t *) HW_SDMAARM_CONFIG_ADDR)
#define HW_SDMAARM_CONFIG_RD()      (HW_SDMAARM_CONFIG.U)
#define HW_SDMAARM_CONFIG_WR(v)     (HW_SDMAARM_CONFIG.U = (v))
#define HW_SDMAARM_CONFIG_SET(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() |  (v)))
#define HW_SDMAARM_CONFIG_CLR(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() & ~(v)))
#define HW_SDMAARM_CONFIG_TOG(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_CONFIG bitfields
 */

/* --- Register HW_SDMAARM_CONFIG, field CSM (RW)
 *
 * Selects the Context Switch Mode. The ARM platform has a read/write access. The SDMA cannot modify
 * that register. The value at reset is 3, which selects the dynamic context switch by default. That
 * register can be modified at anytime but the new context switch configuration will only be taken
 * into account at the start of the next restore phase. NOTE: The first call to SDMA's channel 0
 * Bootload script after reset should use static context switch mode to ensure the context RAM for
 * channel 0 is initialized in the channel SAVE Phase. After Channel 0 is run once, then any of the
 * dynamic context modes can be used.
 *
 * Values:
 * 0 - static
 * 1 - dynamic low power
 * 2 - dynamic with no loop
 * 3 - dynamic
 */

#define BP_SDMAARM_CONFIG_CSM      0
#define BM_SDMAARM_CONFIG_CSM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_CSM(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_CONFIG_CSM)
#else
#define BF_SDMAARM_CONFIG_CSM(v)   (((v) << 0) & BM_SDMAARM_CONFIG_CSM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSM field to a new value.
#define BW_SDMAARM_CONFIG_CSM(v)   BF_CS1(SDMAARM_CONFIG, CSM, v)
#endif


/* --- Register HW_SDMAARM_CONFIG, field ACR (RW)
 *
 * ARM platform DMA / SDMA Core Clock Ratio. Selects the clock ratio between ARM platform DMA
 * interfaces (burst DMA and burst DMA2 and peripheral DMA ) and the internal SDMA core clock. The
 * frequency selection is determined separately by the chip clock controller. This bit has to match
 * the configuration of the chip clock controller that generates the clocks used in the SDMA.
 *
 * Values:
 * 0 - ARM platform DMA interface frequency equals twice core frequency
 * 1 - ARM platform DMA interface frequency equals core frequency
 */

#define BP_SDMAARM_CONFIG_ACR      4
#define BM_SDMAARM_CONFIG_ACR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_ACR(v)   ((((reg32_t) v) << 4) & BM_SDMAARM_CONFIG_ACR)
#else
#define BF_SDMAARM_CONFIG_ACR(v)   (((v) << 4) & BM_SDMAARM_CONFIG_ACR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_SDMAARM_CONFIG_ACR(v)   BF_CS1(SDMAARM_CONFIG, ACR, v)
#endif


/* --- Register HW_SDMAARM_CONFIG, field RTDOBS (RW)
 *
 * Indicates if Real-Time Debug pins are used: They do not toggle by default in order to reduce
 * power consumption.
 *
 * Values:
 * 0 - RTD pins disabled
 * 1 - RTD pins enabled
 */

#define BP_SDMAARM_CONFIG_RTDOBS      11
#define BM_SDMAARM_CONFIG_RTDOBS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_RTDOBS(v)   ((((reg32_t) v) << 11) & BM_SDMAARM_CONFIG_RTDOBS)
#else
#define BF_SDMAARM_CONFIG_RTDOBS(v)   (((v) << 11) & BM_SDMAARM_CONFIG_RTDOBS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTDOBS field to a new value.
#define BW_SDMAARM_CONFIG_RTDOBS(v)   BF_CS1(SDMAARM_CONFIG, RTDOBS, v)
#endif


/* --- Register HW_SDMAARM_CONFIG, field DSPDMA (RW)
 *
 * This bit's function is reserved and should be configured as zero.
 *
 * Values:
 * 0 - - Reset Value
 * 1 - - Reserved
 */

#define BP_SDMAARM_CONFIG_DSPDMA      12
#define BM_SDMAARM_CONFIG_DSPDMA      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CONFIG_DSPDMA(v)   ((((reg32_t) v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#else
#define BF_SDMAARM_CONFIG_DSPDMA(v)   (((v) << 12) & BM_SDMAARM_CONFIG_DSPDMA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSPDMA field to a new value.
#define BW_SDMAARM_CONFIG_DSPDMA(v)   BF_CS1(SDMAARM_CONFIG, DSPDMA, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_LOCK - SDMA LOCK (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LOCK : 1; //!< The LOCK bit is used to restrict access to update SDMA script memory through ROM channel zero scripts and through the OnCE interface under ARM platform control. The LOCK bit is set: The SDMA_LOCK, ONCE_ENB,CH0ADDR, and ILLINSTADDR registers cannot be written. These registers can be read, but writes are ignored. SDMA software executing out of ROM or RAM may check the LOCK bit in the LOCK register to determine if certain operations are allowed, such as up-loading new scripts. Once the LOCK bit is set to 1, only a reset can clear it. The LOCK bit is cleared by a hardware reset. LOCK is cleared by a software reset only if SRESET_LOCK_CLR is set.
        unsigned SRESET_LOCK_CLR : 1; //!< The SRESET_LOCK_CLR bit determine if the LOCK bit is cleared on a software reset triggered by writing to the RESET register. This bit cannot be changed if LOCK=1. SREST_LOCK_CLR is cleared by conditions that clear the LOCK bit.
        unsigned RESERVED0 : 30; //!< Reserved
    } B;
} hw_sdmaarm_sdma_lock_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_LOCK register
 */
#define HW_SDMAARM_SDMA_LOCK_ADDR      (REGS_SDMAARM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_LOCK           (*(volatile hw_sdmaarm_sdma_lock_t *) HW_SDMAARM_SDMA_LOCK_ADDR)
#define HW_SDMAARM_SDMA_LOCK_RD()      (HW_SDMAARM_SDMA_LOCK.U)
#define HW_SDMAARM_SDMA_LOCK_WR(v)     (HW_SDMAARM_SDMA_LOCK.U = (v))
#define HW_SDMAARM_SDMA_LOCK_SET(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() |  (v)))
#define HW_SDMAARM_SDMA_LOCK_CLR(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() & ~(v)))
#define HW_SDMAARM_SDMA_LOCK_TOG(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_LOCK bitfields
 */

/* --- Register HW_SDMAARM_SDMA_LOCK, field LOCK (RW)
 *
 * The LOCK bit is used to restrict access to update SDMA script memory through ROM channel zero
 * scripts and through the OnCE interface under ARM platform control. The LOCK bit is set: The
 * SDMA_LOCK, ONCE_ENB,CH0ADDR, and ILLINSTADDR registers cannot be written. These registers can be
 * read, but writes are ignored. SDMA software executing out of ROM or RAM may check the LOCK bit in
 * the LOCK register to determine if certain operations are allowed, such as up-loading new scripts.
 * Once the LOCK bit is set to 1, only a reset can clear it. The LOCK bit is cleared by a hardware
 * reset. LOCK is cleared by a software reset only if SRESET_LOCK_CLR is set.
 *
 * Values:
 * 0 - LOCK disengaged.
 * 1 - LOCK enabled.
 */

#define BP_SDMAARM_SDMA_LOCK_LOCK      0
#define BM_SDMAARM_SDMA_LOCK_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA_LOCK_LOCK)
#else
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   (((v) << 0) & BM_SDMAARM_SDMA_LOCK_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK field to a new value.
#define BW_SDMAARM_SDMA_LOCK_LOCK(v)   BF_CS1(SDMAARM_SDMA_LOCK, LOCK, v)
#endif


/* --- Register HW_SDMAARM_SDMA_LOCK, field SRESET_LOCK_CLR (RW)
 *
 * The SRESET_LOCK_CLR bit determine if the LOCK bit is cleared on a software reset triggered by
 * writing to the RESET register. This bit cannot be changed if LOCK=1. SREST_LOCK_CLR is cleared by
 * conditions that clear the LOCK bit.
 *
 * Values:
 * 0 - Software Reset does not clear the LOCK bit.
 * 1 - Software Reset clears the LOCK bit.
 */

#define BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      1
#define BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   ((((reg32_t) v) << 1) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#else
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   (((v) << 1) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRESET_LOCK_CLR field to a new value.
#define BW_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   BF_CS1(SDMAARM_SDMA_LOCK, SRESET_LOCK_CLR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_ENB - OnCE Enable (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENB : 1; //!< The OnCE Enable register selects the OnCE control source: When cleared (0), the OnCE registers are accessed through the JTAG interface; when set (1), the OnCE registers may be accessed by the ARM platform through the addresses described, as follows. After reset, the OnCE registers are accessed through the JTAG interface. Writing a 1 to ENB enables the ARM platform to access the ONCE_* as any other SDMA control register. When cleared (0), all the ONCE_xxx registers cannot be written. The value of ENB cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_sdmaarm_once_enb_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_ENB register
 */
#define HW_SDMAARM_ONCE_ENB_ADDR      (REGS_SDMAARM_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_ENB           (*(volatile hw_sdmaarm_once_enb_t *) HW_SDMAARM_ONCE_ENB_ADDR)
#define HW_SDMAARM_ONCE_ENB_RD()      (HW_SDMAARM_ONCE_ENB.U)
#define HW_SDMAARM_ONCE_ENB_WR(v)     (HW_SDMAARM_ONCE_ENB.U = (v))
#define HW_SDMAARM_ONCE_ENB_SET(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() |  (v)))
#define HW_SDMAARM_ONCE_ENB_CLR(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() & ~(v)))
#define HW_SDMAARM_ONCE_ENB_TOG(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_ENB bitfields
 */

/* --- Register HW_SDMAARM_ONCE_ENB, field ENB (RW)
 *
 * The OnCE Enable register selects the OnCE control source: When cleared (0), the OnCE registers
 * are accessed through the JTAG interface; when set (1), the OnCE registers may be accessed by the
 * ARM platform through the addresses described, as follows. After reset, the OnCE registers are
 * accessed through the JTAG interface. Writing a 1 to ENB enables the ARM platform to access the
 * ONCE_* as any other SDMA control register. When cleared (0), all the ONCE_xxx registers cannot be
 * written. The value of ENB cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_ONCE_ENB_ENB      0
#define BM_SDMAARM_ONCE_ENB_ENB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_ENB_ENB(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_ENB_ENB)
#else
#define BF_SDMAARM_ONCE_ENB_ENB(v)   (((v) << 0) & BM_SDMAARM_ONCE_ENB_ENB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENB field to a new value.
#define BW_SDMAARM_ONCE_ENB_ENB(v)   BF_CS1(SDMAARM_ONCE_ENB, ENB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_DATA - OnCE Data Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Data register of the OnCE JTAG controller. Refer to for information on this register.
    } B;
} hw_sdmaarm_once_data_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_DATA register
 */
#define HW_SDMAARM_ONCE_DATA_ADDR      (REGS_SDMAARM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_DATA           (*(volatile hw_sdmaarm_once_data_t *) HW_SDMAARM_ONCE_DATA_ADDR)
#define HW_SDMAARM_ONCE_DATA_RD()      (HW_SDMAARM_ONCE_DATA.U)
#define HW_SDMAARM_ONCE_DATA_WR(v)     (HW_SDMAARM_ONCE_DATA.U = (v))
#define HW_SDMAARM_ONCE_DATA_SET(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() |  (v)))
#define HW_SDMAARM_ONCE_DATA_CLR(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() & ~(v)))
#define HW_SDMAARM_ONCE_DATA_TOG(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_DATA bitfields
 */

/* --- Register HW_SDMAARM_ONCE_DATA, field DATA (RW)
 *
 * Data register of the OnCE JTAG controller. Refer to for information on this register.
 */

#define BP_SDMAARM_ONCE_DATA_DATA      0
#define BM_SDMAARM_ONCE_DATA_DATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_DATA_DATA(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_DATA_DATA)
#else
#define BF_SDMAARM_ONCE_DATA_DATA(v)   (((v) << 0) & BM_SDMAARM_ONCE_DATA_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_SDMAARM_ONCE_DATA_DATA(v)   BF_CS1(SDMAARM_ONCE_DATA, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_INSTR - OnCE Instruction Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INSTR : 16; //!< Instruction register of the OnCE JTAG controller. Refer to for information on this register.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmaarm_once_instr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_INSTR register
 */
#define HW_SDMAARM_ONCE_INSTR_ADDR      (REGS_SDMAARM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_INSTR           (*(volatile hw_sdmaarm_once_instr_t *) HW_SDMAARM_ONCE_INSTR_ADDR)
#define HW_SDMAARM_ONCE_INSTR_RD()      (HW_SDMAARM_ONCE_INSTR.U)
#define HW_SDMAARM_ONCE_INSTR_WR(v)     (HW_SDMAARM_ONCE_INSTR.U = (v))
#define HW_SDMAARM_ONCE_INSTR_SET(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() |  (v)))
#define HW_SDMAARM_ONCE_INSTR_CLR(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() & ~(v)))
#define HW_SDMAARM_ONCE_INSTR_TOG(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_INSTR bitfields
 */

/* --- Register HW_SDMAARM_ONCE_INSTR, field INSTR (RW)
 *
 * Instruction register of the OnCE JTAG controller. Refer to for information on this register.
 */

#define BP_SDMAARM_ONCE_INSTR_INSTR      0
#define BM_SDMAARM_ONCE_INSTR_INSTR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_INSTR_INSTR)
#else
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   (((v) << 0) & BM_SDMAARM_ONCE_INSTR_INSTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INSTR field to a new value.
#define BW_SDMAARM_ONCE_INSTR_INSTR(v)   BF_CS1(SDMAARM_ONCE_INSTR, INSTR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_STAT - OnCE Status Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ECDR : 3; //!< Event Cell Debug Request. If the debug request comes from the event cell, the reason for entering debug mode is given by the EDR bits. If all three bits of the EDR are reset, then it did not generate any debug request. If the cell did generate a debug request, then at least one of the EDR bits is set (the meaning of the encoding is given below). The encoding of the EDR bits is useful to find out more precisely why the debug request was generated. A debug request from an event cell is generated for a specific combination of the addra_cond, addrb_cond, and data_cond conditions. The value of those fields is given by the EDR bits.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned MST : 1; //!< This flag is raised when the OnCE is controlled from the ARM platform peripheral interface.
        unsigned SWB : 1; //!< This flag is raised when the SDMA has entered debug mode after a software breakpoint.
        unsigned ODR : 1; //!< This flag is raised when the SDMA has entered debug mode after a OnCE debug request.
        unsigned EDR : 1; //!< This flag is raised when the SDMA has entered debug mode after an external debug request.
        unsigned RCV : 1; //!< After each write access to the real time buffer (RTB), the RCV bit is set. This bit is cleared after execution of an rbuffer command and on a JTAG reset.
        unsigned PST : 4; //!< The Processor Status bits reflect the state of the SDMA RISC engine. Its states are as follows: The "Program" state is the usual instruction execution cycle. The "Data" state is inserted when there are wait-states during a load or a store on the data bus (ld or st). The "Change of Flow" state is the second cycle of any instruction that breaks the sequence of instructions (jumps and channel switching instructions). The "Change of Flow in Loop" state is used when an error causes a hardware loop exit. The "Debug" state means the SDMA is in debug mode. The "Functional Unit" state is inserted when there are wait-states during a load or a store on the functional units bus (ldf or stf). In "Sleep" modes, no script is running (this is the RISC engine idle state). The "after Reset" is slightly different because no context restoring phase will happen when a channel is triggered: The script located at address 0 will be executed (boot operation). The "in Sleep" states are the same as above except they do not have any corresponding channel: They are used when entering debug mode after reset. The reason is that it is necessary to return to the "Sleep after Reset" state when leaving debug mode.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_sdmaarm_once_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_STAT register
 */
#define HW_SDMAARM_ONCE_STAT_ADDR      (REGS_SDMAARM_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_STAT           (*(volatile hw_sdmaarm_once_stat_t *) HW_SDMAARM_ONCE_STAT_ADDR)
#define HW_SDMAARM_ONCE_STAT_RD()      (HW_SDMAARM_ONCE_STAT.U)
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_STAT bitfields
 */

/* --- Register HW_SDMAARM_ONCE_STAT, field ECDR (RO)
 *
 * Event Cell Debug Request. If the debug request comes from the event cell, the reason for entering
 * debug mode is given by the EDR bits. If all three bits of the EDR are reset, then it did not
 * generate any debug request. If the cell did generate a debug request, then at least one of the
 * EDR bits is set (the meaning of the encoding is given below). The encoding of the EDR bits is
 * useful to find out more precisely why the debug request was generated. A debug request from an
 * event cell is generated for a specific combination of the addra_cond, addrb_cond, and data_cond
 * conditions. The value of those fields is given by the EDR bits.
 *
 * Values:
 * 0 - 1 matched addra_cond
 * 1 - 1 matched addrb_cond
 * 2 - 1 matched data_cond
 */

#define BP_SDMAARM_ONCE_STAT_ECDR      0
#define BM_SDMAARM_ONCE_STAT_ECDR      0x00000007


/* --- Register HW_SDMAARM_ONCE_STAT, field MST (RO)
 *
 * This flag is raised when the OnCE is controlled from the ARM platform peripheral interface.
 *
 * Values:
 * 0 - The JTAG interface controls the OnCE.
 * 1 - The ARM platform peripheral interface controls the OnCE.
 */

#define BP_SDMAARM_ONCE_STAT_MST      7
#define BM_SDMAARM_ONCE_STAT_MST      0x00000080


/* --- Register HW_SDMAARM_ONCE_STAT, field SWB (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after a software breakpoint.
 */

#define BP_SDMAARM_ONCE_STAT_SWB      8
#define BM_SDMAARM_ONCE_STAT_SWB      0x00000100

/* --- Register HW_SDMAARM_ONCE_STAT, field ODR (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after a OnCE debug request.
 */

#define BP_SDMAARM_ONCE_STAT_ODR      9
#define BM_SDMAARM_ONCE_STAT_ODR      0x00000200

/* --- Register HW_SDMAARM_ONCE_STAT, field EDR (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after an external debug request.
 */

#define BP_SDMAARM_ONCE_STAT_EDR      10
#define BM_SDMAARM_ONCE_STAT_EDR      0x00000400

/* --- Register HW_SDMAARM_ONCE_STAT, field RCV (RO)
 *
 * After each write access to the real time buffer (RTB), the RCV bit is set. This bit is cleared
 * after execution of an rbuffer command and on a JTAG reset.
 */

#define BP_SDMAARM_ONCE_STAT_RCV      11
#define BM_SDMAARM_ONCE_STAT_RCV      0x00000800

/* --- Register HW_SDMAARM_ONCE_STAT, field PST (RO)
 *
 * The Processor Status bits reflect the state of the SDMA RISC engine. Its states are as follows:
 * The "Program" state is the usual instruction execution cycle. The "Data" state is inserted when
 * there are wait-states during a load or a store on the data bus (ld or st). The "Change of Flow"
 * state is the second cycle of any instruction that breaks the sequence of instructions (jumps and
 * channel switching instructions). The "Change of Flow in Loop" state is used when an error causes
 * a hardware loop exit. The "Debug" state means the SDMA is in debug mode. The "Functional Unit"
 * state is inserted when there are wait-states during a load or a store on the functional units bus
 * (ldf or stf). In "Sleep" modes, no script is running (this is the RISC engine idle state). The
 * "after Reset" is slightly different because no context restoring phase will happen when a channel
 * is triggered: The script located at address 0 will be executed (boot operation). The "in Sleep"
 * states are the same as above except they do not have any corresponding channel: They are used
 * when entering debug mode after reset. The reason is that it is necessary to return to the "Sleep
 * after Reset" state when leaving debug mode.
 *
 * Values:
 * 0 - Program
 * 1 - Data
 * 2 - Change of Flow
 * 3 - Change of Flow in Loop
 * 4 - Debug
 * 5 - Functional Unit
 * 6 - Sleep
 * 7 - Save
 * 8 - Program in Sleep
 * 9 - Data in Sleep
 * 10 - Change of Flow in Sleep
 * 11 - Change Flow in Loop in Sleep
 * 12 - Debug in Sleep
 * 13 - Functional Unit in Sleep
 * 14 - Sleep after Reset
 * 15 - Restore
 */

#define BP_SDMAARM_ONCE_STAT_PST      12
#define BM_SDMAARM_ONCE_STAT_PST      0x0000f000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_CMD - OnCE Command Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CMD : 4; //!< Writing to this register will cause the OnCE to execute the command that is written. When needed, the ONCE_DATA and ONCE_INSTR registers should be loaded with the correct value before writing the command to that register. For a list of the OnCE commands and their usage, see . 7-15 reserved
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_sdmaarm_once_cmd_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_CMD register
 */
#define HW_SDMAARM_ONCE_CMD_ADDR      (REGS_SDMAARM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_CMD           (*(volatile hw_sdmaarm_once_cmd_t *) HW_SDMAARM_ONCE_CMD_ADDR)
#define HW_SDMAARM_ONCE_CMD_RD()      (HW_SDMAARM_ONCE_CMD.U)
#define HW_SDMAARM_ONCE_CMD_WR(v)     (HW_SDMAARM_ONCE_CMD.U = (v))
#define HW_SDMAARM_ONCE_CMD_SET(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() |  (v)))
#define HW_SDMAARM_ONCE_CMD_CLR(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() & ~(v)))
#define HW_SDMAARM_ONCE_CMD_TOG(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_CMD bitfields
 */

/* --- Register HW_SDMAARM_ONCE_CMD, field CMD (RW)
 *
 * Writing to this register will cause the OnCE to execute the command that is written. When needed,
 * the ONCE_DATA and ONCE_INSTR registers should be loaded with the correct value before writing the
 * command to that register. For a list of the OnCE commands and their usage, see . 7-15 reserved
 *
 * Values:
 * 0 - rstatus
 * 1 - dmov
 * 2 - exec_once
 * 3 - run_core
 * 4 - exec_core
 * 5 - debug_rqst
 * 6 - rbuffer
 */

#define BP_SDMAARM_ONCE_CMD_CMD      0
#define BM_SDMAARM_ONCE_CMD_CMD      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ONCE_CMD_CMD(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ONCE_CMD_CMD)
#else
#define BF_SDMAARM_ONCE_CMD_CMD(v)   (((v) << 0) & BM_SDMAARM_ONCE_CMD_CMD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CMD field to a new value.
#define BW_SDMAARM_ONCE_CMD_CMD(v)   BF_CS1(SDMAARM_ONCE_CMD, CMD, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ILLINSTADDR - Illegal Instruction Trap Address (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ILLINSTADDR : 14; //!< The Illegal Instruction Trap Address is the address where the SDMA jumps when an illegal instruction is executed. It is 0x0001 after reset. The value of ILLINSTADDR cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_sdmaarm_illinstaddr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ILLINSTADDR register
 */
#define HW_SDMAARM_ILLINSTADDR_ADDR      (REGS_SDMAARM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ILLINSTADDR           (*(volatile hw_sdmaarm_illinstaddr_t *) HW_SDMAARM_ILLINSTADDR_ADDR)
#define HW_SDMAARM_ILLINSTADDR_RD()      (HW_SDMAARM_ILLINSTADDR.U)
#define HW_SDMAARM_ILLINSTADDR_WR(v)     (HW_SDMAARM_ILLINSTADDR.U = (v))
#define HW_SDMAARM_ILLINSTADDR_SET(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() |  (v)))
#define HW_SDMAARM_ILLINSTADDR_CLR(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() & ~(v)))
#define HW_SDMAARM_ILLINSTADDR_TOG(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ILLINSTADDR bitfields
 */

/* --- Register HW_SDMAARM_ILLINSTADDR, field ILLINSTADDR (RW)
 *
 * The Illegal Instruction Trap Address is the address where the SDMA jumps when an illegal
 * instruction is executed. It is 0x0001 after reset. The value of ILLINSTADDR cannot be changed if
 * the LOCK bit in the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_ILLINSTADDR_ILLINSTADDR      0
#define BM_SDMAARM_ILLINSTADDR_ILLINSTADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#else
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   (((v) << 0) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ILLINSTADDR field to a new value.
#define BW_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   BF_CS1(SDMAARM_ILLINSTADDR, ILLINSTADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_CHN0ADDR - Channel 0 Boot Address (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHN0ADDR : 14; //!< This 14-bit register is used by the boot code of the SDMA. After reset, it points to the standard boot routine in ROM (channel 0 routine). By changing this address, you can perform a boot sequence with your own routine. The very first instructions of the boot code fetch the contents of this register (it is also mapped in the SDMA memory space) and jump to the given address. The reset value is 0x0050 (decimal 80). The value of CHN0ADDR cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned SMSZ : 1; //!< The bit 14 (Scratch Memory Size) determines if scratch memory must be available after every channel context. After reset, it is equal to 0, which defines a RAM space of 24 words for each channel. All of this area stores the channel context. By setting this bit, 32 words are reserved for every channel context, which gives eight additional words that can be used by the channel script to store any type of data. Those words are never erased by the context switching mechanism. The value of SMSZ cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 17; //!< Reserved
    } B;
} hw_sdmaarm_chn0addr_t;
#endif

/*
 * constants & macros for entire SDMAARM_CHN0ADDR register
 */
#define HW_SDMAARM_CHN0ADDR_ADDR      (REGS_SDMAARM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CHN0ADDR           (*(volatile hw_sdmaarm_chn0addr_t *) HW_SDMAARM_CHN0ADDR_ADDR)
#define HW_SDMAARM_CHN0ADDR_RD()      (HW_SDMAARM_CHN0ADDR.U)
#define HW_SDMAARM_CHN0ADDR_WR(v)     (HW_SDMAARM_CHN0ADDR.U = (v))
#define HW_SDMAARM_CHN0ADDR_SET(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() |  (v)))
#define HW_SDMAARM_CHN0ADDR_CLR(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() & ~(v)))
#define HW_SDMAARM_CHN0ADDR_TOG(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_CHN0ADDR bitfields
 */

/* --- Register HW_SDMAARM_CHN0ADDR, field CHN0ADDR (RW)
 *
 * This 14-bit register is used by the boot code of the SDMA. After reset, it points to the standard
 * boot routine in ROM (channel 0 routine). By changing this address, you can perform a boot
 * sequence with your own routine. The very first instructions of the boot code fetch the contents
 * of this register (it is also mapped in the SDMA memory space) and jump to the given address. The
 * reset value is 0x0050 (decimal 80). The value of CHN0ADDR cannot be changed if the LOCK bit in
 * the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_CHN0ADDR_CHN0ADDR      0
#define BM_SDMAARM_CHN0ADDR_CHN0ADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#else
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   (((v) << 0) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CHN0ADDR field to a new value.
#define BW_SDMAARM_CHN0ADDR_CHN0ADDR(v)   BF_CS1(SDMAARM_CHN0ADDR, CHN0ADDR, v)
#endif

/* --- Register HW_SDMAARM_CHN0ADDR, field SMSZ (RW)
 *
 * The bit 14 (Scratch Memory Size) determines if scratch memory must be available after every
 * channel context. After reset, it is equal to 0, which defines a RAM space of 24 words for each
 * channel. All of this area stores the channel context. By setting this bit, 32 words are reserved
 * for every channel context, which gives eight additional words that can be used by the channel
 * script to store any type of data. Those words are never erased by the context switching
 * mechanism. The value of SMSZ cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
 *
 * Values:
 * 0 - 24 words per context
 * 1 - 32 words per context
 */

#define BP_SDMAARM_CHN0ADDR_SMSZ      14
#define BM_SDMAARM_CHN0ADDR_SMSZ      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_CHN0ADDR_SMSZ)
#else
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   (((v) << 14) & BM_SDMAARM_CHN0ADDR_SMSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SMSZ field to a new value.
#define BW_SDMAARM_CHN0ADDR_SMSZ(v)   BF_CS1(SDMAARM_CHN0ADDR, SMSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVT_MIRROR - DMA Requests (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EVENTS : 32; //!< This register reflects the DMA requests received by the SDMA for events 31-0. The ARM platform and the SDMA have a read-only access. There is one bit associated with each of 32 DMA request events. This information may be useful during debug of the blocks that generate the DMA requests. The EVT_MIRROR register is cleared following read access.
    } B;
} hw_sdmaarm_evt_mirror_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR register
 */
#define HW_SDMAARM_EVT_MIRROR_ADDR      (REGS_SDMAARM_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR           (*(volatile hw_sdmaarm_evt_mirror_t *) HW_SDMAARM_EVT_MIRROR_ADDR)
#define HW_SDMAARM_EVT_MIRROR_RD()      (HW_SDMAARM_EVT_MIRROR.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVT_MIRROR bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR, field EVENTS (RO)
 *
 * This register reflects the DMA requests received by the SDMA for events 31-0. The ARM platform
 * and the SDMA have a read-only access. There is one bit associated with each of 32 DMA request
 * events. This information may be useful during debug of the blocks that generate the DMA requests.
 * The EVT_MIRROR register is cleared following read access.
 *
 * Values:
 * 0 - DMA request event not pending
 * 1 - DMA request event pending
 */

#define BP_SDMAARM_EVT_MIRROR_EVENTS      0
#define BM_SDMAARM_EVT_MIRROR_EVENTS      0xffffffff


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVT_MIRROR2 - DMA Requests 2 (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EVENTS : 16; //!< This register reflects the DMA requests received by the SDMA for events 47-32. The ARM platform and the SDMA have a read-only access. There is one bit associated with each of DMA request events. This information may be useful during debug of the blocks that generate the DMA requests. The EVT_MIRROR2 register is cleared following read access.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmaarm_evt_mirror2_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR2 register
 */
#define HW_SDMAARM_EVT_MIRROR2_ADDR      (REGS_SDMAARM_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR2           (*(volatile hw_sdmaarm_evt_mirror2_t *) HW_SDMAARM_EVT_MIRROR2_ADDR)
#define HW_SDMAARM_EVT_MIRROR2_RD()      (HW_SDMAARM_EVT_MIRROR2.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVT_MIRROR2 bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR2, field EVENTS (RO)
 *
 * This register reflects the DMA requests received by the SDMA for events 47-32. The ARM platform
 * and the SDMA have a read-only access. There is one bit associated with each of DMA request
 * events. This information may be useful during debug of the blocks that generate the DMA requests.
 * The EVT_MIRROR2 register is cleared following read access.
 *
 * Values:
 * 0 - - DMA request event not pending
 * 1- - DMA request event pending
 */

#define BP_SDMAARM_EVT_MIRROR2_EVENTS      0
#define BM_SDMAARM_EVT_MIRROR2_EVENTS      0x0000ffff


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_XTRIG_CONF1 - Cross-Trigger Events Configuration Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned NUM0 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF0 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned NUM1 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF1 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned NUM2 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF2 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned NUM3 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF3 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by the reception of a DMA request or by the starting of a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_sdmaarm_xtrig_conf1_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF1 register
 */
#define HW_SDMAARM_XTRIG_CONF1_ADDR      (REGS_SDMAARM_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF1           (*(volatile hw_sdmaarm_xtrig_conf1_t *) HW_SDMAARM_XTRIG_CONF1_ADDR)
#define HW_SDMAARM_XTRIG_CONF1_RD()      (HW_SDMAARM_XTRIG_CONF1.U)
#define HW_SDMAARM_XTRIG_CONF1_WR(v)     (HW_SDMAARM_XTRIG_CONF1.U = (v))
#define HW_SDMAARM_XTRIG_CONF1_SET(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF1_CLR(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF1_TOG(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_XTRIG_CONF1 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM0 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM0      0
#define BM_SDMAARM_XTRIG_CONF1_NUM0      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM0 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM0(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM0, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF0 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF0      6
#define BM_SDMAARM_XTRIG_CONF1_CNF0      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   ((((reg32_t) v) << 6) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   (((v) << 6) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF0 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF0(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF0, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM1 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM1      8
#define BM_SDMAARM_XTRIG_CONF1_NUM1      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM1 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM1(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM1, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF1 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF1      14
#define BM_SDMAARM_XTRIG_CONF1_CNF1      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   (((v) << 14) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF1 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF1(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF1, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM2 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM2      16
#define BM_SDMAARM_XTRIG_CONF1_NUM2      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM2 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM2(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM2, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF2 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF2      22
#define BM_SDMAARM_XTRIG_CONF1_CNF2      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   ((((reg32_t) v) << 22) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   (((v) << 22) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF2 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF2(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF2, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM3 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM3      24
#define BM_SDMAARM_XTRIG_CONF1_NUM3      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#else
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM3 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM3(v)   BF_CS1(SDMAARM_XTRIG_CONF1, NUM3, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF3 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by the reception of a DMA request or by the
 * starting of a channel script execution. When a pulse is generated by starting of a channel script
 * execution, it is in fact generated by the restore part of the context switch mechanism.
 * Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset
 * (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF3      30
#define BM_SDMAARM_XTRIG_CONF1_CNF3      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   ((((reg32_t) v) << 30) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#else
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   (((v) << 30) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF3 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF3(v)   BF_CS1(SDMAARM_XTRIG_CONF1, CNF3, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_XTRIG_CONF2 - Cross-Trigger Events Configuration Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned NUM4 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF4 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned NUM5 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF5 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution . When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned NUM6 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF6 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned NUM7 : 6; //!< Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF7 : 1; //!< Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_sdmaarm_xtrig_conf2_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF2 register
 */
#define HW_SDMAARM_XTRIG_CONF2_ADDR      (REGS_SDMAARM_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF2           (*(volatile hw_sdmaarm_xtrig_conf2_t *) HW_SDMAARM_XTRIG_CONF2_ADDR)
#define HW_SDMAARM_XTRIG_CONF2_RD()      (HW_SDMAARM_XTRIG_CONF2.U)
#define HW_SDMAARM_XTRIG_CONF2_WR(v)     (HW_SDMAARM_XTRIG_CONF2.U = (v))
#define HW_SDMAARM_XTRIG_CONF2_SET(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF2_CLR(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF2_TOG(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_XTRIG_CONF2 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM4 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM4      0
#define BM_SDMAARM_XTRIG_CONF2_NUM4      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   (((v) << 0) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM4 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM4(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM4, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF4 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF4      6
#define BM_SDMAARM_XTRIG_CONF2_CNF4      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   ((((reg32_t) v) << 6) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   (((v) << 6) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF4 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF4(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF4, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM5 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM5      8
#define BM_SDMAARM_XTRIG_CONF2_NUM5      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   ((((reg32_t) v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   (((v) << 8) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM5 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM5(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM5, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF5 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution . When a pulse is generated by starting of a channel script execution,
 * it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse
 * is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF5      14
#define BM_SDMAARM_XTRIG_CONF2_CNF5      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   ((((reg32_t) v) << 14) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   (((v) << 14) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF5 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF5(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF5, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM6 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM6      16
#define BM_SDMAARM_XTRIG_CONF2_NUM6      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   ((((reg32_t) v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   (((v) << 16) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM6 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM6(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM6, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF6 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF6      22
#define BM_SDMAARM_XTRIG_CONF2_CNF6      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   ((((reg32_t) v) << 22) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   (((v) << 22) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF6 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF6(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF6, v)
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM7 (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM7      24
#define BM_SDMAARM_XTRIG_CONF2_NUM7      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   ((((reg32_t) v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#else
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   (((v) << 24) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM7 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM7(v)   BF_CS1(SDMAARM_XTRIG_CONF2, NUM7, v)
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF7 (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF7      30
#define BM_SDMAARM_XTRIG_CONF2_CNF7      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   ((((reg32_t) v) << 30) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#else
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   (((v) << 30) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF7 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF7(v)   BF_CS1(SDMAARM_XTRIG_CONF2, CNF7, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI - Channel Priority Registers (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHNPRIN : 3; //!< This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_sdmaarm_sdma_chnpri_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI register
 */
#define HW_SDMAARM_SDMA_CHNPRI_ADDR      (REGS_SDMAARM_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI           (*(volatile hw_sdmaarm_sdma_chnpri_t *) HW_SDMAARM_SDMA_CHNPRI_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI_RD()      (HW_SDMAARM_SDMA_CHNPRI.U)
#define HW_SDMAARM_SDMA_CHNPRI_WR(v)     (HW_SDMAARM_SDMA_CHNPRI.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI_SET(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI_WR(HW_SDMAARM_SDMA_CHNPRI_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI, field CHNPRIN (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI_CHNPRIN      0
#define BM_SDMAARM_SDMA_CHNPRI_CHNPRIN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA_CHNPRI_CHNPRIN)
#else
#define BF_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   (((v) << 0) & BM_SDMAARM_SDMA_CHNPRI_CHNPRIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI_CHNPRIN(v)   BF_CS1(SDMAARM_SDMA_CHNPRI, CHNPRIN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA.CHNENBL - Channel Enable RAM (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENBLN : 32; //!< This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma.chnenbl_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA.CHNENBL register
 */
#define HW_SDMAARM_SDMA.CHNENBL_ADDR      (REGS_SDMAARM_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA.CHNENBL           (*(volatile hw_sdmaarm_sdma.chnenbl_t *) HW_SDMAARM_SDMA.CHNENBL_ADDR)
#define HW_SDMAARM_SDMA.CHNENBL_RD()      (HW_SDMAARM_SDMA.CHNENBL.U)
#define HW_SDMAARM_SDMA.CHNENBL_WR(v)     (HW_SDMAARM_SDMA.CHNENBL.U = (v))
#define HW_SDMAARM_SDMA.CHNENBL_SET(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() |  (v)))
#define HW_SDMAARM_SDMA.CHNENBL_CLR(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() & ~(v)))
#define HW_SDMAARM_SDMA.CHNENBL_TOG(v)    (HW_SDMAARM_SDMA.CHNENBL_WR(HW_SDMAARM_SDMA.CHNENBL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA.CHNENBL bitfields
 */

/* --- Register HW_SDMAARM_SDMA.CHNENBL, field ENBLN (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA.CHNENBL_ENBLN      0
#define BM_SDMAARM_SDMA.CHNENBL_ENBLN      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMAARM_SDMA.CHNENBL_ENBLN(v)   ((((reg32_t) v) << 0) & BM_SDMAARM_SDMA.CHNENBL_ENBLN)
#else
#define BF_SDMAARM_SDMA.CHNENBL_ENBLN(v)   (((v) << 0) & BM_SDMAARM_SDMA.CHNENBL_ENBLN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA.CHNENBL_ENBLN(v)   BF_CS1(SDMAARM_SDMA.CHNENBL, ENBLN, v)
#endif


/*!
 * @brief All SDMAARM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_sdmaarm_mc0ptr_t MC0PTR; //!< ARM platform Channel 0 Pointer
    volatile hw_sdmaarm_intr_t INTR; //!< Channel Interrupts
    volatile hw_sdmaarm_stop_stat_t STOP_STAT; //!< Channel Stop/Channel Status
    volatile hw_sdmaarm_hstart_t HSTART; //!< Channel Start
    volatile hw_sdmaarm_evtovr_t EVTOVR; //!< Channel Event Override
    volatile hw_sdmaarm_dspovr_t DSPOVR; //!< Channel BP Override
    volatile hw_sdmaarm_hostovr_t HOSTOVR; //!< Channel ARM platform Override
    volatile hw_sdmaarm_evtpend_t EVTPEND; //!< Channel Event Pending
    reg32_t _reserved0;
    volatile hw_sdmaarm_reset_t RESET; //!< Reset Register
    volatile hw_sdmaarm_evterr_t EVTERR; //!< DMA Request Error Register
    volatile hw_sdmaarm_intrmask_t INTRMASK; //!< Channel ARM platform Interrupt Mask
    volatile hw_sdmaarm_psw_t PSW; //!< Schedule Status
    volatile hw_sdmaarm_evterrdbg_t EVTERRDBG; //!< DMA Request Error Register
    volatile hw_sdmaarm_config_t CONFIG; //!< Configuration Register
    volatile hw_sdmaarm_sdma_lock_t SDMA_LOCK; //!< SDMA LOCK
    volatile hw_sdmaarm_once_enb_t ONCE_ENB; //!< OnCE Enable
    volatile hw_sdmaarm_once_data_t ONCE_DATA; //!< OnCE Data Register
    volatile hw_sdmaarm_once_instr_t ONCE_INSTR; //!< OnCE Instruction Register
    volatile hw_sdmaarm_once_stat_t ONCE_STAT; //!< OnCE Status Register
    volatile hw_sdmaarm_once_cmd_t ONCE_CMD; //!< OnCE Command Register
    reg32_t _reserved1;
    volatile hw_sdmaarm_illinstaddr_t ILLINSTADDR; //!< Illegal Instruction Trap Address
    volatile hw_sdmaarm_chn0addr_t CHN0ADDR; //!< Channel 0 Boot Address
    volatile hw_sdmaarm_evt_mirror_t EVT_MIRROR; //!< DMA Requests
    volatile hw_sdmaarm_evt_mirror2_t EVT_MIRROR2; //!< DMA Requests 2
    reg32_t _reserved2[2];
    volatile hw_sdmaarm_xtrig_conf1_t XTRIG_CONF1; //!< Cross-Trigger Events Configuration Register 1
    volatile hw_sdmaarm_xtrig_conf2_t XTRIG_CONF2; //!< Cross-Trigger Events Configuration Register 2
    reg32_t _reserved3[34];
    volatile hw_sdmaarm_sdma_chnpri_t SDMA_CHNPRI; //!< Channel Priority Registers
    reg32_t _reserved4[63];
    volatile hw_sdmaarm_sdma.chnenbl_t SDMA.CHNENBL; //!< Channel Enable RAM
} hw_sdmaarm_t
#endif

//! @brief Macro to access all SDMAARM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SDMAARM(0)</code>.
#define HW_SDMAARM     (*(volatile hw_sdmaarm_t *) REGS_SDMAARM_BASE)


#endif // _SDMAARM_H
