/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMABP_H
#define _SDMABP_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_SDMABP_DC0PTR - Channel 0 Pointer
 * - HW_SDMABP_INTR - Channel Interrupts
 * - HW_SDMABP_STOP_STAT - Channel Stop/Channel Status
 * - HW_SDMABP_DSTART - Channel Start
 * - HW_SDMABP_EVTERR - DMA Request Error Register
 * - HW_SDMABP_INTRMASK - Channel DSP Interrupt Mask
 * - HW_SDMABP_EVTERRDBG - DMA Request Error Register
 *
 * hw_sdmabp_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SDMABP_BASE
#define REGS_SDMABP_BASE (0x020ec000) //!< Base address for SDMABP.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_DC0PTR - Channel 0 Pointer (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DC0PTR : 32; //!< Channel 0 Pointer contains the 32-bit address, in BP memory, of the array of channel control blocks starting with the one for channel 0 (the control channel). This register should be initialized by the BP before it enables a channel (for example, channel 0). See the API document SDMA Scripts User Manual for the use of this register. The BP has a read/write access and the SDMA has a read-only access.
    } B;
} hw_sdmabp_dc0ptr_t;
#endif

/*
 * constants & macros for entire SDMABP_DC0PTR register
 */
#define HW_SDMABP_DC0PTR_ADDR      (REGS_SDMABP_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_DC0PTR           (*(volatile hw_sdmabp_dc0ptr_t *) HW_SDMABP_DC0PTR_ADDR)
#define HW_SDMABP_DC0PTR_RD()      (HW_SDMABP_DC0PTR.U)
#define HW_SDMABP_DC0PTR_WR(v)     (HW_SDMABP_DC0PTR.U = (v))
#define HW_SDMABP_DC0PTR_SET(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() |  (v)))
#define HW_SDMABP_DC0PTR_CLR(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() & ~(v)))
#define HW_SDMABP_DC0PTR_TOG(v)    (HW_SDMABP_DC0PTR_WR(HW_SDMABP_DC0PTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMABP_DC0PTR bitfields
 */

/* --- Register HW_SDMABP_DC0PTR, field DC0PTR (RW)
 *
 * Channel 0 Pointer contains the 32-bit address, in BP memory, of the array of channel control
 * blocks starting with the one for channel 0 (the control channel). This register should be
 * initialized by the BP before it enables a channel (for example, channel 0). See the API document
 * SDMA Scripts User Manual for the use of this register. The BP has a read/write access and the
 * SDMA has a read-only access.
 */

#define BP_SDMABP_DC0PTR_DC0PTR      0
#define BM_SDMABP_DC0PTR_DC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_DC0PTR_DC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMABP_DC0PTR_DC0PTR)
#else
#define BF_SDMABP_DC0PTR_DC0PTR(v)   (((v) << 0) & BM_SDMABP_DC0PTR_DC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DC0PTR field to a new value.
#define BW_SDMABP_DC0PTR_DC0PTR(v)   BF_CS1(SDMABP_DC0PTR, DC0PTR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_INTR - Channel Interrupts (w1c)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DI : 32; //!< The BP Interrupts register contains the 32 DI[i] bits. If any bit is set, it will cause an interrupt to the BP. This register is a "write-ones" register to the BP. When the BP sets a bit in this register, the corresponding DI[i] bit is cleared. The interrupt service routine should clear individual channel bits when their interrupts are serviced; failure to do so will cause continuous interrupts. The SDMA is responsible for setting the DI[i] bit corresponding to the current channel when the corresponding done instruction is executed.
    } B;
} hw_sdmabp_intr_t;
#endif

/*
 * constants & macros for entire SDMABP_INTR register
 */
#define HW_SDMABP_INTR_ADDR      (REGS_SDMABP_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_INTR           (*(volatile hw_sdmabp_intr_t *) HW_SDMABP_INTR_ADDR)
#define HW_SDMABP_INTR_RD()      (HW_SDMABP_INTR.U)
#endif

/*
 * constants & macros for individual SDMABP_INTR bitfields
 */

/* --- Register HW_SDMABP_INTR, field DI (W1C)
 *
 * The BP Interrupts register contains the 32 DI[i] bits. If any bit is set, it will cause an
 * interrupt to the BP. This register is a "write-ones" register to the BP. When the BP sets a bit
 * in this register, the corresponding DI[i] bit is cleared. The interrupt service routine should
 * clear individual channel bits when their interrupts are serviced; failure to do so will cause
 * continuous interrupts. The SDMA is responsible for setting the DI[i] bit corresponding to the
 * current channel when the corresponding done instruction is executed.
 */

#define BP_SDMABP_INTR_DI      0
#define BM_SDMABP_INTR_DI      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_STOP_STAT - Channel Stop/Channel Status (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DE : 32; //!< This 32-bit register gives access to the BP (DSP) Enable bits, DE. There is one bit for every channel. This register is a "write-ones" register to the BP. When the BP writes 1 in bit i of this register, it clears the DE[i] and DSTART[i] bits. Reading this register yields the current state of the DE[i] bits.
    } B;
} hw_sdmabp_stop_stat_t;
#endif

/*
 * constants & macros for entire SDMABP_STOP_STAT register
 */
#define HW_SDMABP_STOP_STAT_ADDR      (REGS_SDMABP_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_STOP_STAT           (*(volatile hw_sdmabp_stop_stat_t *) HW_SDMABP_STOP_STAT_ADDR)
#define HW_SDMABP_STOP_STAT_RD()      (HW_SDMABP_STOP_STAT.U)
#define HW_SDMABP_STOP_STAT_WR(v)     (HW_SDMABP_STOP_STAT.U = (v))
#define HW_SDMABP_STOP_STAT_SET(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() |  (v)))
#define HW_SDMABP_STOP_STAT_CLR(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() & ~(v)))
#define HW_SDMABP_STOP_STAT_TOG(v)    (HW_SDMABP_STOP_STAT_WR(HW_SDMABP_STOP_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMABP_STOP_STAT bitfields
 */

/* --- Register HW_SDMABP_STOP_STAT, field DE (W1C)
 *
 * This 32-bit register gives access to the BP (DSP) Enable bits, DE. There is one bit for every
 * channel. This register is a "write-ones" register to the BP. When the BP writes 1 in bit i of
 * this register, it clears the DE[i] and DSTART[i] bits. Reading this register yields the current
 * state of the DE[i] bits.
 */

#define BP_SDMABP_STOP_STAT_DE      0
#define BM_SDMABP_STOP_STAT_DE      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_DSTART - Channel Start (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DSTART : 32; //!< The DSTART/DE registers are 32 bits wide with one bit for every channel. When a bit is written to 1, it enables the corresponding channel. Two physical registers are accessed with that address (DSTART and DE), which enables the BP to trigger a channel a second time before the first trigger was processed. This register is a "write-ones" register to the BP. Neither DSTART[i] bit can be set while the corresponding DE[i] bit is cleared. When the BP tries to set the DSTART[i] bit by writing a one (if the corresponding DE[i] bit is clear), the bit in the DSTART[i] register will remain cleared and the DE[i] bit will be set. If the corresponding DE[i] bit was already set, the DSTART[i] bit will be set. The next time the SDMA channel i attempts to clear the DE[i] bit by means of a done instruction, the bit in the DSTART[i] register will be cleared and the DE[i] bit will take the old value of the DSTART[i] bit. Reading this register yields the current state of the DSTART[i] bits. This mechanism enables the BP to pipeline two DSTART commands per channel.
    } B;
} hw_sdmabp_dstart_t;
#endif

/*
 * constants & macros for entire SDMABP_DSTART register
 */
#define HW_SDMABP_DSTART_ADDR      (REGS_SDMABP_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_DSTART           (*(volatile hw_sdmabp_dstart_t *) HW_SDMABP_DSTART_ADDR)
#define HW_SDMABP_DSTART_RD()      (HW_SDMABP_DSTART.U)
#endif

/*
 * constants & macros for individual SDMABP_DSTART bitfields
 */

/* --- Register HW_SDMABP_DSTART, field DSTART (RO)
 *
 * The DSTART/DE registers are 32 bits wide with one bit for every channel. When a bit is written to
 * 1, it enables the corresponding channel. Two physical registers are accessed with that address
 * (DSTART and DE), which enables the BP to trigger a channel a second time before the first trigger
 * was processed. This register is a "write-ones" register to the BP. Neither DSTART[i] bit can be
 * set while the corresponding DE[i] bit is cleared. When the BP tries to set the DSTART[i] bit by
 * writing a one (if the corresponding DE[i] bit is clear), the bit in the DSTART[i] register will
 * remain cleared and the DE[i] bit will be set. If the corresponding DE[i] bit was already set, the
 * DSTART[i] bit will be set. The next time the SDMA channel i attempts to clear the DE[i] bit by
 * means of a done instruction, the bit in the DSTART[i] register will be cleared and the DE[i] bit
 * will take the old value of the DSTART[i] bit. Reading this register yields the current state of
 * the DSTART[i] bits. This mechanism enables the BP to pipeline two DSTART commands per channel.
 */

#define BP_SDMABP_DSTART_DSTART      0
#define BM_SDMABP_DSTART_DSTART      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_EVTERR - DMA Request Error Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHNERR : 32; //!< This register is used by the SDMA to warn the BP when an incoming DMA request was detected; it then triggers a channel that is already pending or being serviced, which may mean there is an overflow of data for that channel. An interrupt is sent to the BP if the corresponding channel bit is set in the INTRMASK register. This is a "write-ones" register for the scheduler. It is only able to set the flags. The flags are cleared when the register is read by the BP or during an SDMA reset. The CHNERR[i] bit is set when a DMA request that triggers channel i is received through the corresponding input pins and the EP[i] bit is already set. The EVTERR[i] bit is unaffected if the BP tries to set the EP[i] bit when that EP[i] bit is already set.
    } B;
} hw_sdmabp_evterr_t;
#endif

/*
 * constants & macros for entire SDMABP_EVTERR register
 */
#define HW_SDMABP_EVTERR_ADDR      (REGS_SDMABP_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_EVTERR           (*(volatile hw_sdmabp_evterr_t *) HW_SDMABP_EVTERR_ADDR)
#define HW_SDMABP_EVTERR_RD()      (HW_SDMABP_EVTERR.U)
#endif

/*
 * constants & macros for individual SDMABP_EVTERR bitfields
 */

/* --- Register HW_SDMABP_EVTERR, field CHNERR (RO)
 *
 * This register is used by the SDMA to warn the BP when an incoming DMA request was detected; it
 * then triggers a channel that is already pending or being serviced, which may mean there is an
 * overflow of data for that channel. An interrupt is sent to the BP if the corresponding channel
 * bit is set in the INTRMASK register. This is a "write-ones" register for the scheduler. It is
 * only able to set the flags. The flags are cleared when the register is read by the BP or during
 * an SDMA reset. The CHNERR[i] bit is set when a DMA request that triggers channel i is received
 * through the corresponding input pins and the EP[i] bit is already set. The EVTERR[i] bit is
 * unaffected if the BP tries to set the EP[i] bit when that EP[i] bit is already set.
 */

#define BP_SDMABP_EVTERR_CHNERR      0
#define BM_SDMABP_EVTERR_CHNERR      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_INTRMASK - Channel DSP Interrupt Mask (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DIMASK : 32; //!< The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit DIMASK[i] is set, the DI[i] bit is set and an interrupt is sent to the BP when a DMA request error is detected on channel i (for example, EVTERR[i] is set).
    } B;
} hw_sdmabp_intrmask_t;
#endif

/*
 * constants & macros for entire SDMABP_INTRMASK register
 */
#define HW_SDMABP_INTRMASK_ADDR      (REGS_SDMABP_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_INTRMASK           (*(volatile hw_sdmabp_intrmask_t *) HW_SDMABP_INTRMASK_ADDR)
#define HW_SDMABP_INTRMASK_RD()      (HW_SDMABP_INTRMASK.U)
#define HW_SDMABP_INTRMASK_WR(v)     (HW_SDMABP_INTRMASK.U = (v))
#define HW_SDMABP_INTRMASK_SET(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() |  (v)))
#define HW_SDMABP_INTRMASK_CLR(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() & ~(v)))
#define HW_SDMABP_INTRMASK_TOG(v)    (HW_SDMABP_INTRMASK_WR(HW_SDMABP_INTRMASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMABP_INTRMASK bitfields
 */

/* --- Register HW_SDMABP_INTRMASK, field DIMASK (RW)
 *
 * The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit DIMASK[i] is set,
 * the DI[i] bit is set and an interrupt is sent to the BP when a DMA request error is detected on
 * channel i (for example, EVTERR[i] is set).
 */

#define BP_SDMABP_INTRMASK_DIMASK      0
#define BM_SDMABP_INTRMASK_DIMASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMABP_INTRMASK_DIMASK(v)   ((((reg32_t) v) << 0) & BM_SDMABP_INTRMASK_DIMASK)
#else
#define BF_SDMABP_INTRMASK_DIMASK(v)   (((v) << 0) & BM_SDMABP_INTRMASK_DIMASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIMASK field to a new value.
#define BW_SDMABP_INTRMASK_DIMASK(v)   BF_CS1(SDMABP_INTRMASK, DIMASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMABP_EVTERRDBG - DMA Request Error Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHNERR : 32; //!< This register is the same as EVTERR except reading it does not clear its contents. This address is meant to be used in debug mode. The BP OnCE may check this register value without modifying it.
    } B;
} hw_sdmabp_evterrdbg_t;
#endif

/*
 * constants & macros for entire SDMABP_EVTERRDBG register
 */
#define HW_SDMABP_EVTERRDBG_ADDR      (REGS_SDMABP_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SDMABP_EVTERRDBG           (*(volatile hw_sdmabp_evterrdbg_t *) HW_SDMABP_EVTERRDBG_ADDR)
#define HW_SDMABP_EVTERRDBG_RD()      (HW_SDMABP_EVTERRDBG.U)
#endif

/*
 * constants & macros for individual SDMABP_EVTERRDBG bitfields
 */

/* --- Register HW_SDMABP_EVTERRDBG, field CHNERR (RO)
 *
 * This register is the same as EVTERR except reading it does not clear its contents. This address
 * is meant to be used in debug mode. The BP OnCE may check this register value without modifying
 * it.
 */

#define BP_SDMABP_EVTERRDBG_CHNERR      0
#define BM_SDMABP_EVTERRDBG_CHNERR      0xffffffff


/*!
 * @brief All SDMABP module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_sdmabp_dc0ptr_t DC0PTR; //!< Channel 0 Pointer
    volatile hw_sdmabp_intr_t INTR; //!< Channel Interrupts
    volatile hw_sdmabp_stop_stat_t STOP_STAT; //!< Channel Stop/Channel Status
    volatile hw_sdmabp_dstart_t DSTART; //!< Channel Start
    reg32_t _reserved0[6];
    volatile hw_sdmabp_evterr_t EVTERR; //!< DMA Request Error Register
    volatile hw_sdmabp_intrmask_t INTRMASK; //!< Channel DSP Interrupt Mask
    reg32_t _reserved1;
    volatile hw_sdmabp_evterrdbg_t EVTERRDBG; //!< DMA Request Error Register
} hw_sdmabp_t
#endif

//! @brief Macro to access all SDMABP registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SDMABP(0)</code>.
#define HW_SDMABP     (*(volatile hw_sdmabp_t *) REGS_SDMABP_BASE)


#endif // _SDMABP_H
