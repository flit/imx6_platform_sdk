/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_RNGB_REGISTERS_H__
#define __HW_RNGB_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL RNGB registers defined in this header file.
 *
 * - HW_RNGB_VER - RNGB Version ID Register
 * - HW_RNGB_CMD - RNGB Command Register
 * - HW_RNGB_CR - RNGB Control Register
 * - HW_RNGB_SR - RNGB Status Register
 * - HW_RNGB_ESR - RNGB Error Status Register
 * - HW_RNGB_OUT - RNGB Output FIFO
 *
 * - hw_rngb_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_RNGB_BASE
#define HW_RNGB_INSTANCE_COUNT (0) //!< Number of instances of the RNGB module.
#define REGS_RNGB_BASE (0x00000000) //!< Base address for RNGB.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_VER - RNGB Version ID Register (RO)
 *
 * Reset value: 0x10000280
 *
 * The read-only RNG_VER register contains the current version of the RNGB. It consists of the RNG
 * type and major and minor revision numbers.
 */
typedef union _hw_rngb_ver
{
    reg32_t U;
    struct _hw_rngb_ver_bitfields
    {
        unsigned MINOR : 8; //!< [7:0] Subjiect to change.
        unsigned MAJOR : 8; //!< [15:8] This field is always set to 0x02.
        unsigned RESERVED0 : 12; //!< [27:16] Reserved, must be cleared.
        unsigned TYPE : 4; //!< [31:28] 
    } B;
} hw_rngb_ver_t;
#endif

/*
 * constants & macros for entire RNGB_VER register
 */
#define HW_RNGB_VER_ADDR      (REGS_RNGB_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_VER           (*(volatile hw_rngb_ver_t *) HW_RNGB_VER_ADDR)
#define HW_RNGB_VER_RD()      (HW_RNGB_VER.U)
#endif

/*
 * constants & macros for individual RNGB_VER bitfields
 */

/* --- Register HW_RNGB_VER, field MINOR[7:0] (RO)
 *
 * Subjiect to change.
 */

#define BP_RNGB_VER_MINOR      (0)      //!< Bit position for RNGB_VER_MINOR.
#define BM_RNGB_VER_MINOR      (0x000000ff)  //!< Bit mask for RNGB_VER_MINOR.

//! @brief Get value of RNGB_VER_MINOR from a register value.
#define BG_RNGB_VER_MINOR(r)   (((r) & BM_RNGB_VER_MINOR) >> BP_RNGB_VER_MINOR)

/* --- Register HW_RNGB_VER, field MAJOR[15:8] (RO)
 *
 * This field is always set to 0x02.
 */

#define BP_RNGB_VER_MAJOR      (8)      //!< Bit position for RNGB_VER_MAJOR.
#define BM_RNGB_VER_MAJOR      (0x0000ff00)  //!< Bit mask for RNGB_VER_MAJOR.

//! @brief Get value of RNGB_VER_MAJOR from a register value.
#define BG_RNGB_VER_MAJOR(r)   (((r) & BM_RNGB_VER_MAJOR) >> BP_RNGB_VER_MAJOR)

/* --- Register HW_RNGB_VER, field TYPE[31:28] (RO)
 *

 *
 * Values:
 * 0000 - RNGA
 * 0001 - RNGB (This is the type used in this module)
 * 0010 - RNGC
 * Else - Reserved
 */

#define BP_RNGB_VER_TYPE      (28)      //!< Bit position for RNGB_VER_TYPE.
#define BM_RNGB_VER_TYPE      (0xf0000000)  //!< Bit mask for RNGB_VER_TYPE.

//! @brief Get value of RNGB_VER_TYPE from a register value.
#define BG_RNGB_VER_TYPE(r)   (((r) & BM_RNGB_VER_TYPE) >> BP_RNGB_VER_TYPE)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_CMD - RNGB Command Register (RW)
 *
 * Reset value: 0x00000000
 *
 * RNG_CMD controls the RNG's operating modes and interrupt status.
 */
typedef union _hw_rngb_cmd
{
    reg32_t U;
    struct _hw_rngb_cmd_bitfields
    {
        unsigned ST : 1; //!< [0] Initiates a self test of the RNGB's internal logic. The self-test starts When RNG_SR[BUSY] is cleared, or If set simultaneously with GS, self test takes precedence and is completed first. When self test completes, this bit automatically clears and an interrupt may be generated if all requested operations are complete.
        unsigned GS : 1; //!< [1] Initiates the seed generation process. Seed generation starts When RNG_SR[BUSY] is cleared If set simultaneously with ST, after self-test When the seed generation process completes, this bit automatically clears and an interrupt may be generated if all requested operations are complete.
        unsigned RESERVED0 : 2; //!< [3:2] Reserved, must be cleared.
        unsigned CI : 1; //!< [4] Clears the RNGB interrupt if an error is not present. This bit is self-clearing.
        unsigned CE : 1; //!< [5] Clears the errors in the RNG_ESR register and the RNGB interrupt.This bit is self-clearing.
        unsigned SR : 1; //!< [6] Performs a software reset of the RNGB. This bit is self-clearing.
        unsigned RESERVED1 : 25; //!< [31:7] Reserved, must be cleared.
    } B;
} hw_rngb_cmd_t;
#endif

/*
 * constants & macros for entire RNGB_CMD register
 */
#define HW_RNGB_CMD_ADDR      (REGS_RNGB_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_CMD           (*(volatile hw_rngb_cmd_t *) HW_RNGB_CMD_ADDR)
#define HW_RNGB_CMD_RD()      (HW_RNGB_CMD.U)
#define HW_RNGB_CMD_WR(v)     (HW_RNGB_CMD.U = (v))
#define HW_RNGB_CMD_SET(v)    (HW_RNGB_CMD_WR(HW_RNGB_CMD_RD() |  (v)))
#define HW_RNGB_CMD_CLR(v)    (HW_RNGB_CMD_WR(HW_RNGB_CMD_RD() & ~(v)))
#define HW_RNGB_CMD_TOG(v)    (HW_RNGB_CMD_WR(HW_RNGB_CMD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual RNGB_CMD bitfields
 */

/* --- Register HW_RNGB_CMD, field ST[0] (RW)
 *
 * Initiates a self test of the RNGB's internal logic. The self-test starts When RNG_SR[BUSY] is
 * cleared, or If set simultaneously with GS, self test takes precedence and is completed first.
 * When self test completes, this bit automatically clears and an interrupt may be generated if all
 * requested operations are complete.
 *
 * Values:
 * 0 - Not in self test mode.
 * 1 - Self test mode.
 */

#define BP_RNGB_CMD_ST      (0)      //!< Bit position for RNGB_CMD_ST.
#define BM_RNGB_CMD_ST      (0x00000001)  //!< Bit mask for RNGB_CMD_ST.

//! @brief Get value of RNGB_CMD_ST from a register value.
#define BG_RNGB_CMD_ST(r)   (((r) & BM_RNGB_CMD_ST) >> BP_RNGB_CMD_ST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CMD_ST.
#define BF_RNGB_CMD_ST(v)   ((((reg32_t) v) << BP_RNGB_CMD_ST) & BM_RNGB_CMD_ST)
#else
//! @brief Format value for bitfield RNGB_CMD_ST.
#define BF_RNGB_CMD_ST(v)   (((v) << BP_RNGB_CMD_ST) & BM_RNGB_CMD_ST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ST field to a new value.
#define BW_RNGB_CMD_ST(v)   (HW_RNGB_CMD_WR((HW_RNGB_CMD_RD() & ~BM_RNGB_CMD_ST) | BF_RNGB_CMD_ST(v)))
#endif


/* --- Register HW_RNGB_CMD, field GS[1] (RW)
 *
 * Initiates the seed generation process. Seed generation starts When RNG_SR[BUSY] is cleared If set
 * simultaneously with ST, after self-test When the seed generation process completes, this bit
 * automatically clears and an interrupt may be generated if all requested operations are complete.
 *
 * Values:
 * 0 - Not in seed generation mode.
 * 1 - Generate seed mode.
 */

#define BP_RNGB_CMD_GS      (1)      //!< Bit position for RNGB_CMD_GS.
#define BM_RNGB_CMD_GS      (0x00000002)  //!< Bit mask for RNGB_CMD_GS.

//! @brief Get value of RNGB_CMD_GS from a register value.
#define BG_RNGB_CMD_GS(r)   (((r) & BM_RNGB_CMD_GS) >> BP_RNGB_CMD_GS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CMD_GS.
#define BF_RNGB_CMD_GS(v)   ((((reg32_t) v) << BP_RNGB_CMD_GS) & BM_RNGB_CMD_GS)
#else
//! @brief Format value for bitfield RNGB_CMD_GS.
#define BF_RNGB_CMD_GS(v)   (((v) << BP_RNGB_CMD_GS) & BM_RNGB_CMD_GS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GS field to a new value.
#define BW_RNGB_CMD_GS(v)   (HW_RNGB_CMD_WR((HW_RNGB_CMD_RD() & ~BM_RNGB_CMD_GS) | BF_RNGB_CMD_GS(v)))
#endif


/* --- Register HW_RNGB_CMD, field CI[4] (WORZ)
 *
 * Clears the RNGB interrupt if an error is not present. This bit is self-clearing.
 *
 * Values:
 * 0 - Do not clear interrupt.
 * 1 - Clear interrupt.
 */

#define BP_RNGB_CMD_CI      (4)      //!< Bit position for RNGB_CMD_CI.
#define BM_RNGB_CMD_CI      (0x00000010)  //!< Bit mask for RNGB_CMD_CI.

//! @brief Get value of RNGB_CMD_CI from a register value.
#define BG_RNGB_CMD_CI(r)   (((r) & BM_RNGB_CMD_CI) >> BP_RNGB_CMD_CI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CMD_CI.
#define BF_RNGB_CMD_CI(v)   ((((reg32_t) v) << BP_RNGB_CMD_CI) & BM_RNGB_CMD_CI)
#else
//! @brief Format value for bitfield RNGB_CMD_CI.
#define BF_RNGB_CMD_CI(v)   (((v) << BP_RNGB_CMD_CI) & BM_RNGB_CMD_CI)
#endif


/* --- Register HW_RNGB_CMD, field CE[5] (WORZ)
 *
 * Clears the errors in the RNG_ESR register and the RNGB interrupt.This bit is self-clearing.
 *
 * Values:
 * 0 - Do not clear errors and interrupt.
 * 1 - Clear errors and interrupt.
 */

#define BP_RNGB_CMD_CE      (5)      //!< Bit position for RNGB_CMD_CE.
#define BM_RNGB_CMD_CE      (0x00000020)  //!< Bit mask for RNGB_CMD_CE.

//! @brief Get value of RNGB_CMD_CE from a register value.
#define BG_RNGB_CMD_CE(r)   (((r) & BM_RNGB_CMD_CE) >> BP_RNGB_CMD_CE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CMD_CE.
#define BF_RNGB_CMD_CE(v)   ((((reg32_t) v) << BP_RNGB_CMD_CE) & BM_RNGB_CMD_CE)
#else
//! @brief Format value for bitfield RNGB_CMD_CE.
#define BF_RNGB_CMD_CE(v)   (((v) << BP_RNGB_CMD_CE) & BM_RNGB_CMD_CE)
#endif


/* --- Register HW_RNGB_CMD, field SR[6] (WORZ)
 *
 * Performs a software reset of the RNGB. This bit is self-clearing.
 *
 * Values:
 * 0 - Do not perform a software reset.
 * 1 - Software reset.
 */

#define BP_RNGB_CMD_SR      (6)      //!< Bit position for RNGB_CMD_SR.
#define BM_RNGB_CMD_SR      (0x00000040)  //!< Bit mask for RNGB_CMD_SR.

//! @brief Get value of RNGB_CMD_SR from a register value.
#define BG_RNGB_CMD_SR(r)   (((r) & BM_RNGB_CMD_SR) >> BP_RNGB_CMD_SR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CMD_SR.
#define BF_RNGB_CMD_SR(v)   ((((reg32_t) v) << BP_RNGB_CMD_SR) & BM_RNGB_CMD_SR)
#else
//! @brief Format value for bitfield RNGB_CMD_SR.
#define BF_RNGB_CMD_SR(v)   (((v) << BP_RNGB_CMD_SR) & BM_RNGB_CMD_SR)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_CR - RNGB Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Through use of this register, the RNGB can be programmed to provide slightly different
 * functionality based on its desired use. The RNGB can also be placed into deterministic
 * verification mode, if the RNGB is not in secure mode, through manipulation of bits in this
 * register.
 */
typedef union _hw_rngb_cr
{
    reg32_t U;
    struct _hw_rngb_cr_bitfields
    {
        unsigned FUFMOD : 2; //!< [1:0] Controls the RNGB's response to a FIFO underflow condition.
        unsigned RESERVED0 : 2; //!< [3:2] Reserved, must be cleared.
        unsigned AR : 1; //!< [4] Setting this bit allows the RNGB to automatically generate a new seed whenever one is needed. This allows software to never use the RNG_CMD[GS], although it is still possible. A new seed is needed whenever the RNG_SR[RS] is set.
        unsigned MASKDONE : 1; //!< [5] Masks interrupts generated upon completion of seed and self test modes. The status of these jobs can be viewed by: Reading RNG_SR and viewing the seed done and self test done bits (RNG_SR[SDN, STDN]) Viewing RNG_CMD for generate seed or self test bits (RNG_CMD[GS,ST]) being set, indicating that the operation is still taking place.
        unsigned MASKERR : 1; //!< [6] Masks interrupts generated by errors in the RNGB. These errors can still be viewed in RNG_ESR. Since masked errors do not interrupt the operation of the RNGB and thus hide potentially fatal errors or conditions that could result in corrupted results, it is strongly recommended that errors only be masked while debugging. All errors are considered fatal, requiring the RNGB to be reset. Until the a reset occurs, the RNGB does not service any random data.
        unsigned RESERVED1 : 25; //!< [31:7] Reserved.
    } B;
} hw_rngb_cr_t;
#endif

/*
 * constants & macros for entire RNGB_CR register
 */
#define HW_RNGB_CR_ADDR      (REGS_RNGB_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_CR           (*(volatile hw_rngb_cr_t *) HW_RNGB_CR_ADDR)
#define HW_RNGB_CR_RD()      (HW_RNGB_CR.U)
#define HW_RNGB_CR_WR(v)     (HW_RNGB_CR.U = (v))
#define HW_RNGB_CR_SET(v)    (HW_RNGB_CR_WR(HW_RNGB_CR_RD() |  (v)))
#define HW_RNGB_CR_CLR(v)    (HW_RNGB_CR_WR(HW_RNGB_CR_RD() & ~(v)))
#define HW_RNGB_CR_TOG(v)    (HW_RNGB_CR_WR(HW_RNGB_CR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual RNGB_CR bitfields
 */

/* --- Register HW_RNGB_CR, field FUFMOD[1:0] (RW)
 *
 * Controls the RNGB's response to a FIFO underflow condition.
 *
 * Values:
 * 00 - Return all zeros and set RNG_ESR[FUFE]
 * 01 - Return all zeros and set RNG_ESR[FUFE]
 * 10 - Generate bus transfer error (xfr_err) on the IP Skyblue Bus
 * 11 - Generate interrupt and return all zeros (Overrides RNG_CR[MASKERR])
 */

#define BP_RNGB_CR_FUFMOD      (0)      //!< Bit position for RNGB_CR_FUFMOD.
#define BM_RNGB_CR_FUFMOD      (0x00000003)  //!< Bit mask for RNGB_CR_FUFMOD.

//! @brief Get value of RNGB_CR_FUFMOD from a register value.
#define BG_RNGB_CR_FUFMOD(r)   (((r) & BM_RNGB_CR_FUFMOD) >> BP_RNGB_CR_FUFMOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CR_FUFMOD.
#define BF_RNGB_CR_FUFMOD(v)   ((((reg32_t) v) << BP_RNGB_CR_FUFMOD) & BM_RNGB_CR_FUFMOD)
#else
//! @brief Format value for bitfield RNGB_CR_FUFMOD.
#define BF_RNGB_CR_FUFMOD(v)   (((v) << BP_RNGB_CR_FUFMOD) & BM_RNGB_CR_FUFMOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FUFMOD field to a new value.
#define BW_RNGB_CR_FUFMOD(v)   (HW_RNGB_CR_WR((HW_RNGB_CR_RD() & ~BM_RNGB_CR_FUFMOD) | BF_RNGB_CR_FUFMOD(v)))
#endif


/* --- Register HW_RNGB_CR, field AR[4] (RW)
 *
 * Setting this bit allows the RNGB to automatically generate a new seed whenever one is needed.
 * This allows software to never use the RNG_CMD[GS], although it is still possible. A new seed is
 * needed whenever the RNG_SR[RS] is set.
 *
 * Values:
 * 0 - Do not enable automatic reseeding.
 * 1 - Enable automatic reseeding.
 */

#define BP_RNGB_CR_AR      (4)      //!< Bit position for RNGB_CR_AR.
#define BM_RNGB_CR_AR      (0x00000010)  //!< Bit mask for RNGB_CR_AR.

//! @brief Get value of RNGB_CR_AR from a register value.
#define BG_RNGB_CR_AR(r)   (((r) & BM_RNGB_CR_AR) >> BP_RNGB_CR_AR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CR_AR.
#define BF_RNGB_CR_AR(v)   ((((reg32_t) v) << BP_RNGB_CR_AR) & BM_RNGB_CR_AR)
#else
//! @brief Format value for bitfield RNGB_CR_AR.
#define BF_RNGB_CR_AR(v)   (((v) << BP_RNGB_CR_AR) & BM_RNGB_CR_AR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AR field to a new value.
#define BW_RNGB_CR_AR(v)   (HW_RNGB_CR_WR((HW_RNGB_CR_RD() & ~BM_RNGB_CR_AR) | BF_RNGB_CR_AR(v)))
#endif


/* --- Register HW_RNGB_CR, field MASKDONE[5] (RW)
 *
 * Masks interrupts generated upon completion of seed and self test modes. The status of these jobs
 * can be viewed by: Reading RNG_SR and viewing the seed done and self test done bits (RNG_SR[SDN,
 * STDN]) Viewing RNG_CMD for generate seed or self test bits (RNG_CMD[GS,ST]) being set, indicating
 * that the operation is still taking place.
 *
 * Values:
 * 0 - No mask applied.
 * 1 - Mask applied.
 */

#define BP_RNGB_CR_MASKDONE      (5)      //!< Bit position for RNGB_CR_MASKDONE.
#define BM_RNGB_CR_MASKDONE      (0x00000020)  //!< Bit mask for RNGB_CR_MASKDONE.

//! @brief Get value of RNGB_CR_MASKDONE from a register value.
#define BG_RNGB_CR_MASKDONE(r)   (((r) & BM_RNGB_CR_MASKDONE) >> BP_RNGB_CR_MASKDONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CR_MASKDONE.
#define BF_RNGB_CR_MASKDONE(v)   ((((reg32_t) v) << BP_RNGB_CR_MASKDONE) & BM_RNGB_CR_MASKDONE)
#else
//! @brief Format value for bitfield RNGB_CR_MASKDONE.
#define BF_RNGB_CR_MASKDONE(v)   (((v) << BP_RNGB_CR_MASKDONE) & BM_RNGB_CR_MASKDONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASKDONE field to a new value.
#define BW_RNGB_CR_MASKDONE(v)   (HW_RNGB_CR_WR((HW_RNGB_CR_RD() & ~BM_RNGB_CR_MASKDONE) | BF_RNGB_CR_MASKDONE(v)))
#endif


/* --- Register HW_RNGB_CR, field MASKERR[6] (RW)
 *
 * Masks interrupts generated by errors in the RNGB. These errors can still be viewed in RNG_ESR.
 * Since masked errors do not interrupt the operation of the RNGB and thus hide potentially fatal
 * errors or conditions that could result in corrupted results, it is strongly recommended that
 * errors only be masked while debugging. All errors are considered fatal, requiring the RNGB to be
 * reset. Until the a reset occurs, the RNGB does not service any random data.
 *
 * Values:
 * 0 - No mask applied.
 * 1 - Mask applied to the error interrupt.
 */

#define BP_RNGB_CR_MASKERR      (6)      //!< Bit position for RNGB_CR_MASKERR.
#define BM_RNGB_CR_MASKERR      (0x00000040)  //!< Bit mask for RNGB_CR_MASKERR.

//! @brief Get value of RNGB_CR_MASKERR from a register value.
#define BG_RNGB_CR_MASKERR(r)   (((r) & BM_RNGB_CR_MASKERR) >> BP_RNGB_CR_MASKERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield RNGB_CR_MASKERR.
#define BF_RNGB_CR_MASKERR(v)   ((((reg32_t) v) << BP_RNGB_CR_MASKERR) & BM_RNGB_CR_MASKERR)
#else
//! @brief Format value for bitfield RNGB_CR_MASKERR.
#define BF_RNGB_CR_MASKERR(v)   (((v) << BP_RNGB_CR_MASKERR) & BM_RNGB_CR_MASKERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASKERR field to a new value.
#define BW_RNGB_CR_MASKERR(v)   (HW_RNGB_CR_WR((HW_RNGB_CR_RD() & ~BM_RNGB_CR_MASKERR) | BF_RNGB_CR_MASKERR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_SR - RNGB Status Register (RO)
 *
 * Reset value: 0x0000500d
 *
 * The RNGBSR is a read-only register which reflects the internal status of the RNGB.
 */
typedef union _hw_rngb_sr
{
    reg32_t U;
    struct _hw_rngb_sr_bitfields
    {
        unsigned RESERVED0 : 1; //!< [0] Reserved, must be set.
        unsigned BUSY : 1; //!< [1] Reflects the current state of RNGB. If RNGB is currently seeding, generating the next seed, creating a new random number, or performing a self test, this bit is set.
        unsigned SLP : 1; //!< [2] Indicates if the RNGB is in sleep mode. When set, the RNGB is in sleep mode and all internal clocks are disabled. While in this mode, the IP bus interface is still enabled and access to the FIFO is allowed. Once the FIFO is empty, the RNGB fills the FIFO and then enters sleep mode again.
        unsigned RS : 1; //!< [3] Indicates the RNGB needs to be reseeded. This is done by setting RNG_CMD[GS], or automatically if RNG_CR[AR] is set.
        unsigned STDN : 1; //!< [4] Indicates the self test is complete. This bit is cleared by hardware reset or a new self test is initiated by setting RNG_CMD[ST].
        unsigned SDN : 1; //!< [5] Indicates the RNG has generated the first seed.
        unsigned NSDN : 1; //!< [6] Indicates that a new seed is ready for use during the next seed generation process.
        unsigned RESERVED1 : 1; //!< [7] 
        unsigned FIFO_LVL : 4; //!< [11:8] Indicates the number of random words currently in the output FIFO. The bits should be interpreted as an integer.
        unsigned FIFO_SIZE : 4; //!< [15:12] Size of the FIFO, and maximum possible FIFO level. The bits should be interpreted as an integer. This value is set to five on the default version of RNGB .
        unsigned ERR : 1; //!< [16] Indicates an error was detected in the RNGB. Read the RNG_ESR register for details.
        unsigned RESERVED2 : 4; //!< [20:17] 
        unsigned ST_PF : 3; //!< [23:21] Indicates Pass or Fail status of the TRNG, PRNG, and RESEED self tests, Bit 23 - TRNG self test pass/fail Bit 22 - PRNG self test pass/fail Bit 21 - RESEED self test pass/fail
        unsigned STATPF : 8; //!< [31:24] Indicates pass or fail status of the various statistics tests on the last seed generated. Bit 31 - Long run test (>34) Bit 30 - Length 6+ run test Bit 29 - Length 5 run test Bit 28 - Length 4 run test Bit 27 - Length 3 run test Bit 26 - Length 2 run test Bit 25 - Length 1 run test Bit 24 - Monobit test
    } B;
} hw_rngb_sr_t;
#endif

/*
 * constants & macros for entire RNGB_SR register
 */
#define HW_RNGB_SR_ADDR      (REGS_RNGB_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_SR           (*(volatile hw_rngb_sr_t *) HW_RNGB_SR_ADDR)
#define HW_RNGB_SR_RD()      (HW_RNGB_SR.U)
#endif

/*
 * constants & macros for individual RNGB_SR bitfields
 */

/* --- Register HW_RNGB_SR, field BUSY[1] (RO)
 *
 * Reflects the current state of RNGB. If RNGB is currently seeding, generating the next seed,
 * creating a new random number, or performing a self test, this bit is set.
 *
 * Values:
 * 0 - Not busy.
 * 1 - Busy.
 */

#define BP_RNGB_SR_BUSY      (1)      //!< Bit position for RNGB_SR_BUSY.
#define BM_RNGB_SR_BUSY      (0x00000002)  //!< Bit mask for RNGB_SR_BUSY.

//! @brief Get value of RNGB_SR_BUSY from a register value.
#define BG_RNGB_SR_BUSY(r)   (((r) & BM_RNGB_SR_BUSY) >> BP_RNGB_SR_BUSY)


/* --- Register HW_RNGB_SR, field SLP[2] (RO)
 *
 * Indicates if the RNGB is in sleep mode. When set, the RNGB is in sleep mode and all internal
 * clocks are disabled. While in this mode, the IP bus interface is still enabled and access to the
 * FIFO is allowed. Once the FIFO is empty, the RNGB fills the FIFO and then enters sleep mode
 * again.
 *
 * Values:
 * 0 - RNGB is not in sleep mode.
 * 1 - RNGB is in sleep mode.
 */

#define BP_RNGB_SR_SLP      (2)      //!< Bit position for RNGB_SR_SLP.
#define BM_RNGB_SR_SLP      (0x00000004)  //!< Bit mask for RNGB_SR_SLP.

//! @brief Get value of RNGB_SR_SLP from a register value.
#define BG_RNGB_SR_SLP(r)   (((r) & BM_RNGB_SR_SLP) >> BP_RNGB_SR_SLP)


/* --- Register HW_RNGB_SR, field RS[3] (RO)
 *
 * Indicates the RNGB needs to be reseeded. This is done by setting RNG_CMD[GS], or automatically if
 * RNG_CR[AR] is set.
 *
 * Values:
 * 0 - RNGB does not need to be reseeded.
 * 1 - RNGB needs to be reseeded.
 */

#define BP_RNGB_SR_RS      (3)      //!< Bit position for RNGB_SR_RS.
#define BM_RNGB_SR_RS      (0x00000008)  //!< Bit mask for RNGB_SR_RS.

//! @brief Get value of RNGB_SR_RS from a register value.
#define BG_RNGB_SR_RS(r)   (((r) & BM_RNGB_SR_RS) >> BP_RNGB_SR_RS)


/* --- Register HW_RNGB_SR, field STDN[4] (RO)
 *
 * Indicates the self test is complete. This bit is cleared by hardware reset or a new self test is
 * initiated by setting RNG_CMD[ST].
 *
 * Values:
 * 0 - Self test not complete.
 * 1 - Completed a self test since the last reset.
 */

#define BP_RNGB_SR_STDN      (4)      //!< Bit position for RNGB_SR_STDN.
#define BM_RNGB_SR_STDN      (0x00000010)  //!< Bit mask for RNGB_SR_STDN.

//! @brief Get value of RNGB_SR_STDN from a register value.
#define BG_RNGB_SR_STDN(r)   (((r) & BM_RNGB_SR_STDN) >> BP_RNGB_SR_STDN)


/* --- Register HW_RNGB_SR, field SDN[5] (RO)
 *
 * Indicates the RNG has generated the first seed.
 *
 * Values:
 * 0 - Seed generation process not complete.
 * 1 - Completed seed generation since the last reset.
 */

#define BP_RNGB_SR_SDN      (5)      //!< Bit position for RNGB_SR_SDN.
#define BM_RNGB_SR_SDN      (0x00000020)  //!< Bit mask for RNGB_SR_SDN.

//! @brief Get value of RNGB_SR_SDN from a register value.
#define BG_RNGB_SR_SDN(r)   (((r) & BM_RNGB_SR_SDN) >> BP_RNGB_SR_SDN)


/* --- Register HW_RNGB_SR, field NSDN[6] (RO)
 *
 * Indicates that a new seed is ready for use during the next seed generation process.
 */

#define BP_RNGB_SR_NSDN      (6)      //!< Bit position for RNGB_SR_NSDN.
#define BM_RNGB_SR_NSDN      (0x00000040)  //!< Bit mask for RNGB_SR_NSDN.

//! @brief Get value of RNGB_SR_NSDN from a register value.
#define BG_RNGB_SR_NSDN(r)   (((r) & BM_RNGB_SR_NSDN) >> BP_RNGB_SR_NSDN)

/* --- Register HW_RNGB_SR, field FIFO_LVL[11:8] (RO)
 *
 * Indicates the number of random words currently in the output FIFO. The bits should be interpreted
 * as an integer.
 */

#define BP_RNGB_SR_FIFO_LVL      (8)      //!< Bit position for RNGB_SR_FIFO_LVL.
#define BM_RNGB_SR_FIFO_LVL      (0x00000f00)  //!< Bit mask for RNGB_SR_FIFO_LVL.

//! @brief Get value of RNGB_SR_FIFO_LVL from a register value.
#define BG_RNGB_SR_FIFO_LVL(r)   (((r) & BM_RNGB_SR_FIFO_LVL) >> BP_RNGB_SR_FIFO_LVL)

/* --- Register HW_RNGB_SR, field FIFO_SIZE[15:12] (RO)
 *
 * Size of the FIFO, and maximum possible FIFO level. The bits should be interpreted as an integer.
 * This value is set to five on the default version of RNGB .
 */

#define BP_RNGB_SR_FIFO_SIZE      (12)      //!< Bit position for RNGB_SR_FIFO_SIZE.
#define BM_RNGB_SR_FIFO_SIZE      (0x0000f000)  //!< Bit mask for RNGB_SR_FIFO_SIZE.

//! @brief Get value of RNGB_SR_FIFO_SIZE from a register value.
#define BG_RNGB_SR_FIFO_SIZE(r)   (((r) & BM_RNGB_SR_FIFO_SIZE) >> BP_RNGB_SR_FIFO_SIZE)

/* --- Register HW_RNGB_SR, field ERR[16] (RO)
 *
 * Indicates an error was detected in the RNGB. Read the RNG_ESR register for details.
 *
 * Values:
 * 0 - No error.
 * 1 - Error detected.
 */

#define BP_RNGB_SR_ERR      (16)      //!< Bit position for RNGB_SR_ERR.
#define BM_RNGB_SR_ERR      (0x00010000)  //!< Bit mask for RNGB_SR_ERR.

//! @brief Get value of RNGB_SR_ERR from a register value.
#define BG_RNGB_SR_ERR(r)   (((r) & BM_RNGB_SR_ERR) >> BP_RNGB_SR_ERR)


/* --- Register HW_RNGB_SR, field ST_PF[23:21] (RO)
 *
 * Indicates Pass or Fail status of the TRNG, PRNG, and RESEED self tests, Bit 23 - TRNG self test
 * pass/fail Bit 22 - PRNG self test pass/fail Bit 21 - RESEED self test pass/fail
 *
 * Values:
 * 0 - Pass.
 * 1 - Fail.
 */

#define BP_RNGB_SR_ST_PF      (21)      //!< Bit position for RNGB_SR_ST_PF.
#define BM_RNGB_SR_ST_PF      (0x00e00000)  //!< Bit mask for RNGB_SR_ST_PF.

//! @brief Get value of RNGB_SR_ST_PF from a register value.
#define BG_RNGB_SR_ST_PF(r)   (((r) & BM_RNGB_SR_ST_PF) >> BP_RNGB_SR_ST_PF)


/* --- Register HW_RNGB_SR, field STATPF[31:24] (RO)
 *
 * Indicates pass or fail status of the various statistics tests on the last seed generated. Bit 31
 * - Long run test (>34) Bit 30 - Length 6+ run test Bit 29 - Length 5 run test Bit 28 - Length 4
 * run test Bit 27 - Length 3 run test Bit 26 - Length 2 run test Bit 25 - Length 1 run test Bit 24
 * - Monobit test
 *
 * Values:
 * 0 - Pass.
 * 1 - Fail.
 */

#define BP_RNGB_SR_STATPF      (24)      //!< Bit position for RNGB_SR_STATPF.
#define BM_RNGB_SR_STATPF      (0xff000000)  //!< Bit mask for RNGB_SR_STATPF.

//! @brief Get value of RNGB_SR_STATPF from a register value.
#define BG_RNGB_SR_STATPF(r)   (((r) & BM_RNGB_SR_STATPF) >> BP_RNGB_SR_STATPF)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_ESR - RNGB Error Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_rngb_esr
{
    reg32_t U;
    struct _hw_rngb_esr_bitfields
    {
        unsigned LFE : 1; //!< [0] When this bit is set, the interrupt generated was caused by a failure of one of the LFSRs in one of the RNGB's three entropy sources. This bit is sticky and can only be cleared by a software or hardware reset.
        unsigned OSCE : 1; //!< [1] Indicates the oscillator in the RNG may be broken. This bit is sticky and can only be cleared by a software or hardware reset.
        unsigned STE : 1; //!< [2] Indicates the RNGB has failed the most recent self test. This bit is sticky and can only be reset by a hardware reset or by writing one to RNG_CMD[CE].
        unsigned SATE : 1; //!< [3] Indicates if RNGB has failed the statistical tests for the last generated seed. This bit is sticky and is cleared by a hardware or software reset or by writing one to RNG_CMD[CE].
        unsigned FUFE : 1; //!< [4] Indicates the RNGB has experienced a FIFO underflow condition resulting in the last random data read being unreliable. This bit can be masked by RNG_CR[FUFMOD] and is cleared by hardware or software reset or by writing one to RNG_CMD[CE].
        unsigned RESERVED0 : 27; //!< [31:5] Reserved, must be cleared.
    } B;
} hw_rngb_esr_t;
#endif

/*
 * constants & macros for entire RNGB_ESR register
 */
#define HW_RNGB_ESR_ADDR      (REGS_RNGB_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_ESR           (*(volatile hw_rngb_esr_t *) HW_RNGB_ESR_ADDR)
#define HW_RNGB_ESR_RD()      (HW_RNGB_ESR.U)
#endif

/*
 * constants & macros for individual RNGB_ESR bitfields
 */

/* --- Register HW_RNGB_ESR, field LFE[0] (RO)
 *
 * When this bit is set, the interrupt generated was caused by a failure of one of the LFSRs in one
 * of the RNGB's three entropy sources. This bit is sticky and can only be cleared by a software or
 * hardware reset.
 *
 * Values:
 * 0 - LFSRs are working properly.
 * 1 - LFSR failure has occurred.
 */

#define BP_RNGB_ESR_LFE      (0)      //!< Bit position for RNGB_ESR_LFE.
#define BM_RNGB_ESR_LFE      (0x00000001)  //!< Bit mask for RNGB_ESR_LFE.

//! @brief Get value of RNGB_ESR_LFE from a register value.
#define BG_RNGB_ESR_LFE(r)   (((r) & BM_RNGB_ESR_LFE) >> BP_RNGB_ESR_LFE)


/* --- Register HW_RNGB_ESR, field OSCE[1] (RO)
 *
 * Indicates the oscillator in the RNG may be broken. This bit is sticky and can only be cleared by
 * a software or hardware reset.
 *
 * Values:
 * 0 - RNG oscillator is working properly.
 * 1 - Problem detected with the RNG oscillator.
 */

#define BP_RNGB_ESR_OSCE      (1)      //!< Bit position for RNGB_ESR_OSCE.
#define BM_RNGB_ESR_OSCE      (0x00000002)  //!< Bit mask for RNGB_ESR_OSCE.

//! @brief Get value of RNGB_ESR_OSCE from a register value.
#define BG_RNGB_ESR_OSCE(r)   (((r) & BM_RNGB_ESR_OSCE) >> BP_RNGB_ESR_OSCE)


/* --- Register HW_RNGB_ESR, field STE[2] (RO)
 *
 * Indicates the RNGB has failed the most recent self test. This bit is sticky and can only be reset
 * by a hardware reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - RNGB has not failed self test.
 * 1 - RNGB has failed self test.
 */

#define BP_RNGB_ESR_STE      (2)      //!< Bit position for RNGB_ESR_STE.
#define BM_RNGB_ESR_STE      (0x00000004)  //!< Bit mask for RNGB_ESR_STE.

//! @brief Get value of RNGB_ESR_STE from a register value.
#define BG_RNGB_ESR_STE(r)   (((r) & BM_RNGB_ESR_STE) >> BP_RNGB_ESR_STE)


/* --- Register HW_RNGB_ESR, field SATE[3] (RO)
 *
 * Indicates if RNGB has failed the statistical tests for the last generated seed. This bit is
 * sticky and is cleared by a hardware or software reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - RNGB has not failed the statistical tests.
 * 1 - RNGB has failed the statistical tests during initialization.
 */

#define BP_RNGB_ESR_SATE      (3)      //!< Bit position for RNGB_ESR_SATE.
#define BM_RNGB_ESR_SATE      (0x00000008)  //!< Bit mask for RNGB_ESR_SATE.

//! @brief Get value of RNGB_ESR_SATE from a register value.
#define BG_RNGB_ESR_SATE(r)   (((r) & BM_RNGB_ESR_SATE) >> BP_RNGB_ESR_SATE)


/* --- Register HW_RNGB_ESR, field FUFE[4] (RO)
 *
 * Indicates the RNGB has experienced a FIFO underflow condition resulting in the last random data
 * read being unreliable. This bit can be masked by RNG_CR[FUFMOD] and is cleared by hardware or
 * software reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - FIFO underflow has not occurred.
 * 1 - FIFO underflow has occurred
 */

#define BP_RNGB_ESR_FUFE      (4)      //!< Bit position for RNGB_ESR_FUFE.
#define BM_RNGB_ESR_FUFE      (0x00000010)  //!< Bit mask for RNGB_ESR_FUFE.

//! @brief Get value of RNGB_ESR_FUFE from a register value.
#define BG_RNGB_ESR_FUFE(r)   (((r) & BM_RNGB_ESR_FUFE) >> BP_RNGB_ESR_FUFE)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_OUT - RNGB Output FIFO (RO)
 *
 * Reset value: 0x00000000
 *
 * The RNGBOUT provides temporary storage for random data generated by the RNGB. This allows the
 * host user to read multiple random longwords back-to-back. A read of this address when the FIFO is
 * not empty, returns 32 bits of random data. If the FIFO is read when empty, a FIFO underrun
 * response is returned according to RNG_CR[FUFMOD]. For optimal system performance, poll
 * RNG_SR[FIFO_LVL] to ensure random values are present before reading the FIFO.
 */
typedef union _hw_rngb_out
{
    reg32_t U;
    struct _hw_rngb_out_bitfields
    {
        unsigned RANDOUT : 32; //!< [31:0] 
    } B;
} hw_rngb_out_t;
#endif

/*
 * constants & macros for entire RNGB_OUT register
 */
#define HW_RNGB_OUT_ADDR      (REGS_RNGB_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_RNGB_OUT           (*(volatile hw_rngb_out_t *) HW_RNGB_OUT_ADDR)
#define HW_RNGB_OUT_RD()      (HW_RNGB_OUT.U)
#endif

/*
 * constants & macros for individual RNGB_OUT bitfields
 */

/* --- Register HW_RNGB_OUT, field RANDOUT[31:0] (RO)
 *

 */

#define BP_RNGB_OUT_RANDOUT      (0)      //!< Bit position for RNGB_OUT_RANDOUT.
#define BM_RNGB_OUT_RANDOUT      (0xffffffff)  //!< Bit mask for RNGB_OUT_RANDOUT.

//! @brief Get value of RNGB_OUT_RANDOUT from a register value.
#define BG_RNGB_OUT_RANDOUT(r)   (((r) & BM_RNGB_OUT_RANDOUT) >> BP_RNGB_OUT_RANDOUT)


/*!
 * @brief All RNGB module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_rngb
{
    volatile hw_rngb_ver_t VER; //!< RNGB Version ID Register
    volatile hw_rngb_cmd_t CMD; //!< RNGB Command Register
    volatile hw_rngb_cr_t CR; //!< RNGB Control Register
    volatile hw_rngb_sr_t SR; //!< RNGB Status Register
    volatile hw_rngb_esr_t ESR; //!< RNGB Error Status Register
    volatile hw_rngb_out_t OUT; //!< RNGB Output FIFO
} hw_rngb_t;
#pragma pack()

//! @brief Macro to access all RNGB registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_RNGB(0)</code>.
#define HW_RNGB     (*(volatile hw_rngb_t *) REGS_RNGB_BASE)

#endif


#endif // __HW_RNGB_REGISTERS_H__
