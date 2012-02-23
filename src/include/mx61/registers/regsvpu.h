/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VPU_H
#define _VPU_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_VPU_CODERUN - BIT Processor run start
 * - HW_VPU_CODEDOWN - BIT Boot Code Download Data register
 * - HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT
 * - HW_VPU_BITINTCLEAR - BIT Interrupt Clear
 * - HW_VPU_BITINTSTS - BIT Interrupt Status
 * - HW_VPU_BITCURPC - BIT Current PC
 * - HW_VPU_BITCODECBUSY - BIT CODEC Busy
 *
 * hw_vpu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_VPU_BASE
#define REGS_VPU_BASE (0x02040000) //!< Base address for VPU.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_CODERUN - BIT Processor run start (WO)
 *
 * See the figure below for illustration of valid bits in VPU Code Run Register and the table below
 * for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VPU : 1; //!< VPU_CodeRun. BIT processor run start bit.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_vpu_coderun_t;
#endif

/*
 * constants & macros for entire VPU_CODERUN register
 */
#define HW_VPU_CODERUN_ADDR      (REGS_VPU_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODERUN           (*(volatile hw_vpu_coderun_t *) HW_VPU_CODERUN_ADDR)
#define HW_VPU_CODERUN_WR(v)     (HW_VPU_CODERUN.U = (v))
#endif

/*
 * constants & macros for individual VPU_CODERUN bitfields
 */

/* --- Register HW_VPU_CODERUN, field VPU (WO)
 *
 * VPU_CodeRun. BIT processor run start bit.
 *
 * Values:
 * 0 - BIT Processor stop execution.
 * 1 - BIT Processor start execution.
 */

#define BP_VPU_CODERUN_VPU      0
#define BM_VPU_CODERUN_VPU      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODERUN_VPU(v)   ((((reg32_t) v) << 0) & BM_VPU_CODERUN_VPU)
#else
#define BF_VPU_CODERUN_VPU(v)   (((v) << 0) & BM_VPU_CODERUN_VPU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPU field to a new value.
#define BW_VPU_CODERUN_VPU(v)   BF_CS1(VPU_CODERUN, VPU, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_CODEDOWN - BIT Boot Code Download Data register (WO)
 *
 * See the figure below for illustration of valid bits in VPU BIT Boot Code Download Data Register
 * and the following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CODEDATA : 16; //!< CodeData[15:0] Download data of VPU BIT boot code.
        unsigned CODEADDR : 13; //!< CodeAddr[12:0] Download address of VPU BIT boot code, which is VPU internal address of BIT processor.
        unsigned RESERVED0 : 3; //!< Reserved
    } B;
} hw_vpu_codedown_t;
#endif

/*
 * constants & macros for entire VPU_CODEDOWN register
 */
#define HW_VPU_CODEDOWN_ADDR      (REGS_VPU_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODEDOWN           (*(volatile hw_vpu_codedown_t *) HW_VPU_CODEDOWN_ADDR)
#define HW_VPU_CODEDOWN_WR(v)     (HW_VPU_CODEDOWN.U = (v))
#endif

/*
 * constants & macros for individual VPU_CODEDOWN bitfields
 */

/* --- Register HW_VPU_CODEDOWN, field CODEDATA (WO)
 *
 * CodeData[15:0] Download data of VPU BIT boot code.
 */

#define BP_VPU_CODEDOWN_CODEDATA      0
#define BM_VPU_CODEDOWN_CODEDATA      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODEDOWN_CODEDATA(v)   ((((reg32_t) v) << 0) & BM_VPU_CODEDOWN_CODEDATA)
#else
#define BF_VPU_CODEDOWN_CODEDATA(v)   (((v) << 0) & BM_VPU_CODEDOWN_CODEDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CODEDATA field to a new value.
#define BW_VPU_CODEDOWN_CODEDATA(v)   BF_CS1(VPU_CODEDOWN, CODEDATA, v)
#endif

/* --- Register HW_VPU_CODEDOWN, field CODEADDR (WO)
 *
 * CodeAddr[12:0] Download address of VPU BIT boot code, which is VPU internal address of BIT
 * processor.
 */

#define BP_VPU_CODEDOWN_CODEADDR      16
#define BM_VPU_CODEDOWN_CODEADDR      0x1fff0000

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODEDOWN_CODEADDR(v)   ((((reg32_t) v) << 16) & BM_VPU_CODEDOWN_CODEADDR)
#else
#define BF_VPU_CODEDOWN_CODEADDR(v)   (((v) << 16) & BM_VPU_CODEDOWN_CODEADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CODEADDR field to a new value.
#define BW_VPU_CODEDOWN_CODEADDR(v)   BF_CS1(VPU_CODEDOWN, CODEADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT (WO)
 *
 * See the figure below for illustration of valid bits in VPU Host Interrupt Request Register and
 * the following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INTREQ : 1; //!< IntReq. The host interrupt request bit.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_vpu_hostintreq_t;
#endif

/*
 * constants & macros for entire VPU_HOSTINTREQ register
 */
#define HW_VPU_HOSTINTREQ_ADDR      (REGS_VPU_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_HOSTINTREQ           (*(volatile hw_vpu_hostintreq_t *) HW_VPU_HOSTINTREQ_ADDR)
#define HW_VPU_HOSTINTREQ_WR(v)     (HW_VPU_HOSTINTREQ.U = (v))
#endif

/*
 * constants & macros for individual VPU_HOSTINTREQ bitfields
 */

/* --- Register HW_VPU_HOSTINTREQ, field INTREQ (WO)
 *
 * IntReq. The host interrupt request bit.
 *
 * Values:
 * 0 - No host interrupt is requested.
 * 1 - The host processor request interrupt to the BIT processor.
 */

#define BP_VPU_HOSTINTREQ_INTREQ      0
#define BM_VPU_HOSTINTREQ_INTREQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_HOSTINTREQ_INTREQ(v)   ((((reg32_t) v) << 0) & BM_VPU_HOSTINTREQ_INTREQ)
#else
#define BF_VPU_HOSTINTREQ_INTREQ(v)   (((v) << 0) & BM_VPU_HOSTINTREQ_INTREQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTREQ field to a new value.
#define BW_VPU_HOSTINTREQ_INTREQ(v)   BF_CS1(VPU_HOSTINTREQ, INTREQ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITINTCLEAR - BIT Interrupt Clear (WO)
 *
 * See the figure below for illustration of valid bits in VPU BIT Interrupt Clear Register and the
 * following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INTCLEAR : 1; //!< IntClear. BIT interrupt clear bit.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_vpu_bitintclear_t;
#endif

/*
 * constants & macros for entire VPU_BITINTCLEAR register
 */
#define HW_VPU_BITINTCLEAR_ADDR      (REGS_VPU_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTCLEAR           (*(volatile hw_vpu_bitintclear_t *) HW_VPU_BITINTCLEAR_ADDR)
#define HW_VPU_BITINTCLEAR_WR(v)     (HW_VPU_BITINTCLEAR.U = (v))
#endif

/*
 * constants & macros for individual VPU_BITINTCLEAR bitfields
 */

/* --- Register HW_VPU_BITINTCLEAR, field INTCLEAR (WO)
 *
 * IntClear. BIT interrupt clear bit.
 *
 * Values:
 * 0 - No operation is issued.
 * 1 - Clear the BIT interrupt to the host.
 */

#define BP_VPU_BITINTCLEAR_INTCLEAR      0
#define BM_VPU_BITINTCLEAR_INTCLEAR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_BITINTCLEAR_INTCLEAR(v)   ((((reg32_t) v) << 0) & BM_VPU_BITINTCLEAR_INTCLEAR)
#else
#define BF_VPU_BITINTCLEAR_INTCLEAR(v)   (((v) << 0) & BM_VPU_BITINTCLEAR_INTCLEAR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTCLEAR field to a new value.
#define BW_VPU_BITINTCLEAR_INTCLEAR(v)   BF_CS1(VPU_BITINTCLEAR, INTCLEAR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITINTSTS - BIT Interrupt Status (RO)
 *
 * See the figure below for illustration of valid bits in VPU BIT Interrupt Status Register and the
 * following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INTSTS : 1; //!< IntSts. BIT interrupt status bit.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_vpu_bitintsts_t;
#endif

/*
 * constants & macros for entire VPU_BITINTSTS register
 */
#define HW_VPU_BITINTSTS_ADDR      (REGS_VPU_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTSTS           (*(volatile hw_vpu_bitintsts_t *) HW_VPU_BITINTSTS_ADDR)
#define HW_VPU_BITINTSTS_RD()      (HW_VPU_BITINTSTS.U)
#endif

/*
 * constants & macros for individual VPU_BITINTSTS bitfields
 */

/* --- Register HW_VPU_BITINTSTS, field INTSTS (RO)
 *
 * IntSts. BIT interrupt status bit.
 *
 * Values:
 * 0 - No BIT interrupt is asserted.
 * 1 - The BIT interrupt is asserted to the host. It is cleared when the host processor write "1" to
 *     VPU_BitIntClear register.
 */

#define BP_VPU_BITINTSTS_INTSTS      0
#define BM_VPU_BITINTSTS_INTSTS      0x00000001


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITCURPC - BIT Current PC (RO)
 *
 * See the figure below for illustration of valid bits in VPU BIT Current PC Register and the
 * following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CURPC : 14; //!< CurPc[13:0]. BIT current PC value. Returns the current program counter of BIT processor by reading this register.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_vpu_bitcurpc_t;
#endif

/*
 * constants & macros for entire VPU_BITCURPC register
 */
#define HW_VPU_BITCURPC_ADDR      (REGS_VPU_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCURPC           (*(volatile hw_vpu_bitcurpc_t *) HW_VPU_BITCURPC_ADDR)
#define HW_VPU_BITCURPC_RD()      (HW_VPU_BITCURPC.U)
#endif

/*
 * constants & macros for individual VPU_BITCURPC bitfields
 */

/* --- Register HW_VPU_BITCURPC, field CURPC (RO)
 *
 * CurPc[13:0]. BIT current PC value. Returns the current program counter of BIT processor by
 * reading this register.
 */

#define BP_VPU_BITCURPC_CURPC      0
#define BM_VPU_BITCURPC_CURPC      0x00003fff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITCODECBUSY - BIT CODEC Busy (RO)
 *
 * See the figure below for illustration of valid bits in VPU BIT Codec Busy Register and the
 * following table for description of the bit fields in the register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CODECBUSY : 1; //!< Codec busy flag for Bit processor.BIT processor write "1"to this register when the processor is running."0"means processor is waiting for a command.This value is connected to the o_vpu_idle.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_vpu_bitcodecbusy_t;
#endif

/*
 * constants & macros for entire VPU_BITCODECBUSY register
 */
#define HW_VPU_BITCODECBUSY_ADDR      (REGS_VPU_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCODECBUSY           (*(volatile hw_vpu_bitcodecbusy_t *) HW_VPU_BITCODECBUSY_ADDR)
#define HW_VPU_BITCODECBUSY_RD()      (HW_VPU_BITCODECBUSY.U)
#endif

/*
 * constants & macros for individual VPU_BITCODECBUSY bitfields
 */

/* --- Register HW_VPU_BITCODECBUSY, field CODECBUSY (RO)
 *
 * Codec busy flag for Bit processor.BIT processor write "1"to this register when the processor is
 * running."0"means processor is waiting for a command.This value is connected to the o_vpu_idle.
 */

#define BP_VPU_BITCODECBUSY_CODECBUSY      0
#define BM_VPU_BITCODECBUSY_CODECBUSY      0x00000001


/*!
 * @brief All VPU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_vpu_coderun_t CODERUN; //!< BIT Processor run start
    volatile hw_vpu_codedown_t CODEDOWN; //!< BIT Boot Code Download Data register
    volatile hw_vpu_hostintreq_t HOSTINTREQ; //!< Host Interrupt Request to BIT
    volatile hw_vpu_bitintclear_t BITINTCLEAR; //!< BIT Interrupt Clear
    volatile hw_vpu_bitintsts_t BITINTSTS; //!< BIT Interrupt Status
    reg32_t _reserved0;
    volatile hw_vpu_bitcurpc_t BITCURPC; //!< BIT Current PC
    reg32_t _reserved1;
    volatile hw_vpu_bitcodecbusy_t BITCODECBUSY; //!< BIT CODEC Busy
} hw_vpu_t
#endif

//! @brief Macro to access all VPU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_VPU(0)</code>.
#define HW_VPU     (*(volatile hw_vpu_t *) REGS_VPU_BASE)


#endif // _VPU_H
