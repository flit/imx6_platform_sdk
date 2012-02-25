/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _RNGB_H
#define _RNGB_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_RNGB_VER - RNGB Version ID Register
 * - HW_RNGB_CMD - RNGB Command Register
 * - HW_RNGB_CR - RNGB Control Register
 * - HW_RNGB_SR - RNGB Status Register
 * - HW_RNGB_ESR - RNGB Error Status Register
 * - HW_RNGB_OUT - RNGB Output FIFO
 *
 * hw_rngb_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_RNGB_BASE
#define REGS_RNGB_BASE (0x00000000) //!< Base address for RNGB.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_VER - RNGB Version ID Register (RO)
 *
 * The read-only RNG_VER register contains the current version of the RNGB. It consists of the RNG
 * type and major and minor revision numbers.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MINOR : 8; //!< Subjiect to change.
        unsigned MAJOR : 8; //!< This field is always set to 0x02.
        unsigned RESERVED0 : 12; //!< Reserved, must be cleared.
        unsigned TYPE : 4; //!< 
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

#define BP_RNGB_VER_MINOR      (0)
#define BM_RNGB_VER_MINOR      (0x000000ff)

/* --- Register HW_RNGB_VER, field MAJOR[15:8] (RO)
 *
 * This field is always set to 0x02.
 */

#define BP_RNGB_VER_MAJOR      (8)
#define BM_RNGB_VER_MAJOR      (0x0000ff00)

/* --- Register HW_RNGB_VER, field TYPE[31:28] (RO)
 *

 *
 * Values:
 * 0000 - RNGA
 * 0001 - RNGB (This is the type used in this module)
 * 0010 - RNGC
 * Else - Reserved
 */

#define BP_RNGB_VER_TYPE      (28)
#define BM_RNGB_VER_TYPE      (0xf0000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_CMD - RNGB Command Register (RW)
 *
 * RNG_CMD controls the RNG's operating modes and interrupt status.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ST : 1; //!< Initiates a self test of the RNGB's internal logic. The self-test starts When RNG_SR[BUSY] is cleared, or If set simultaneously with GS, self test takes precedence and is completed first. When self test completes, this bit automatically clears and an interrupt may be generated if all requested operations are complete.
        unsigned GS : 1; //!< Initiates the seed generation process. Seed generation starts When RNG_SR[BUSY] is cleared If set simultaneously with ST, after self-test When the seed generation process completes, this bit automatically clears and an interrupt may be generated if all requested operations are complete.
        unsigned RESERVED0 : 2; //!< Reserved, must be cleared.
        unsigned CI : 1; //!< Clears the RNGB interrupt if an error is not present. This bit is self-clearing.
        unsigned CE : 1; //!< Clears the errors in the RNG_ESR register and the RNGB interrupt.This bit is self-clearing.
        unsigned SR : 1; //!< Performs a software reset of the RNGB. This bit is self-clearing.
        unsigned RESERVED1 : 25; //!< Reserved, must be cleared.
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

/* --- Register HW_RNGB_CMD, field ST[0:0] (RW)
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

#define BP_RNGB_CMD_ST      (0)
#define BM_RNGB_CMD_ST      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CMD_ST(v)   ((((reg32_t) v) << 0) & BM_RNGB_CMD_ST)
#else
#define BF_RNGB_CMD_ST(v)   (((v) << 0) & BM_RNGB_CMD_ST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ST field to a new value.
#define BW_RNGB_CMD_ST(v)   BF_CS1(RNGB_CMD, ST, v)
#endif


/* --- Register HW_RNGB_CMD, field GS[1:1] (RW)
 *
 * Initiates the seed generation process. Seed generation starts When RNG_SR[BUSY] is cleared If set
 * simultaneously with ST, after self-test When the seed generation process completes, this bit
 * automatically clears and an interrupt may be generated if all requested operations are complete.
 *
 * Values:
 * 0 - Not in seed generation mode.
 * 1 - Generate seed mode.
 */

#define BP_RNGB_CMD_GS      (1)
#define BM_RNGB_CMD_GS      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CMD_GS(v)   ((((reg32_t) v) << 1) & BM_RNGB_CMD_GS)
#else
#define BF_RNGB_CMD_GS(v)   (((v) << 1) & BM_RNGB_CMD_GS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GS field to a new value.
#define BW_RNGB_CMD_GS(v)   BF_CS1(RNGB_CMD, GS, v)
#endif


/* --- Register HW_RNGB_CMD, field CI[4:4] (WORZ)
 *
 * Clears the RNGB interrupt if an error is not present. This bit is self-clearing.
 *
 * Values:
 * 0 - Do not clear interrupt.
 * 1 - Clear interrupt.
 */

#define BP_RNGB_CMD_CI      (4)
#define BM_RNGB_CMD_CI      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CMD_CI(v)   ((((reg32_t) v) << 4) & BM_RNGB_CMD_CI)
#else
#define BF_RNGB_CMD_CI(v)   (((v) << 4) & BM_RNGB_CMD_CI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CI field to a new value.
#define BW_RNGB_CMD_CI(v)   BF_CS1(RNGB_CMD, CI, v)
#endif


/* --- Register HW_RNGB_CMD, field CE[5:5] (WORZ)
 *
 * Clears the errors in the RNG_ESR register and the RNGB interrupt.This bit is self-clearing.
 *
 * Values:
 * 0 - Do not clear errors and interrupt.
 * 1 - Clear errors and interrupt.
 */

#define BP_RNGB_CMD_CE      (5)
#define BM_RNGB_CMD_CE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CMD_CE(v)   ((((reg32_t) v) << 5) & BM_RNGB_CMD_CE)
#else
#define BF_RNGB_CMD_CE(v)   (((v) << 5) & BM_RNGB_CMD_CE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CE field to a new value.
#define BW_RNGB_CMD_CE(v)   BF_CS1(RNGB_CMD, CE, v)
#endif


/* --- Register HW_RNGB_CMD, field SR[6:6] (WORZ)
 *
 * Performs a software reset of the RNGB. This bit is self-clearing.
 *
 * Values:
 * 0 - Do not perform a software reset.
 * 1 - Software reset.
 */

#define BP_RNGB_CMD_SR      (6)
#define BM_RNGB_CMD_SR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CMD_SR(v)   ((((reg32_t) v) << 6) & BM_RNGB_CMD_SR)
#else
#define BF_RNGB_CMD_SR(v)   (((v) << 6) & BM_RNGB_CMD_SR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SR field to a new value.
#define BW_RNGB_CMD_SR(v)   BF_CS1(RNGB_CMD, SR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_CR - RNGB Control Register (RW)
 *
 * Through use of this register, the RNGB can be programmed to provide slightly different
 * functionality based on its desired use. The RNGB can also be placed into deterministic
 * verification mode, if the RNGB is not in secure mode, through manipulation of bits in this
 * register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FUFMOD : 2; //!< Controls the RNGB's response to a FIFO underflow condition.
        unsigned RESERVED0 : 2; //!< Reserved, must be cleared.
        unsigned AR : 1; //!< Setting this bit allows the RNGB to automatically generate a new seed whenever one is needed. This allows software to never use the RNG_CMD[GS], although it is still possible. A new seed is needed whenever the RNG_SR[RS] is set.
        unsigned MASKDONE : 1; //!< Masks interrupts generated upon completion of seed and self test modes. The status of these jobs can be viewed by: Reading RNG_SR and viewing the seed done and self test done bits (RNG_SR[SDN, STDN]) Viewing RNG_CMD for generate seed or self test bits (RNG_CMD[GS,ST]) being set, indicating that the operation is still taking place.
        unsigned MASKERR : 1; //!< Masks interrupts generated by errors in the RNGB. These errors can still be viewed in RNG_ESR. Since masked errors do not interrupt the operation of the RNGB and thus hide potentially fatal errors or conditions that could result in corrupted results, it is strongly recommended that errors only be masked while debugging. All errors are considered fatal, requiring the RNGB to be reset. Until the a reset occurs, the RNGB does not service any random data.
        unsigned RESERVED1 : 3; //!< Reserved, must be cleared.
        unsigned RESERVED2 : 22; //!< Reserved, must be cleared.
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

#define BP_RNGB_CR_FUFMOD      (0)
#define BM_RNGB_CR_FUFMOD      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CR_FUFMOD(v)   ((((reg32_t) v) << 0) & BM_RNGB_CR_FUFMOD)
#else
#define BF_RNGB_CR_FUFMOD(v)   (((v) << 0) & BM_RNGB_CR_FUFMOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FUFMOD field to a new value.
#define BW_RNGB_CR_FUFMOD(v)   BF_CS1(RNGB_CR, FUFMOD, v)
#endif


/* --- Register HW_RNGB_CR, field AR[4:4] (RW)
 *
 * Setting this bit allows the RNGB to automatically generate a new seed whenever one is needed.
 * This allows software to never use the RNG_CMD[GS], although it is still possible. A new seed is
 * needed whenever the RNG_SR[RS] is set.
 *
 * Values:
 * 0 - Do not enable automatic reseeding.
 * 1 - Enable automatic reseeding.
 */

#define BP_RNGB_CR_AR      (4)
#define BM_RNGB_CR_AR      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CR_AR(v)   ((((reg32_t) v) << 4) & BM_RNGB_CR_AR)
#else
#define BF_RNGB_CR_AR(v)   (((v) << 4) & BM_RNGB_CR_AR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AR field to a new value.
#define BW_RNGB_CR_AR(v)   BF_CS1(RNGB_CR, AR, v)
#endif


/* --- Register HW_RNGB_CR, field MASKDONE[5:5] (RW)
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

#define BP_RNGB_CR_MASKDONE      (5)
#define BM_RNGB_CR_MASKDONE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CR_MASKDONE(v)   ((((reg32_t) v) << 5) & BM_RNGB_CR_MASKDONE)
#else
#define BF_RNGB_CR_MASKDONE(v)   (((v) << 5) & BM_RNGB_CR_MASKDONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASKDONE field to a new value.
#define BW_RNGB_CR_MASKDONE(v)   BF_CS1(RNGB_CR, MASKDONE, v)
#endif


/* --- Register HW_RNGB_CR, field MASKERR[6:6] (RW)
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

#define BP_RNGB_CR_MASKERR      (6)
#define BM_RNGB_CR_MASKERR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_RNGB_CR_MASKERR(v)   ((((reg32_t) v) << 6) & BM_RNGB_CR_MASKERR)
#else
#define BF_RNGB_CR_MASKERR(v)   (((v) << 6) & BM_RNGB_CR_MASKERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASKERR field to a new value.
#define BW_RNGB_CR_MASKERR(v)   BF_CS1(RNGB_CR, MASKERR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_SR - RNGB Status Register (RO)
 *
 * The RNGBSR is a read-only register which reflects the internal status of the RNGB.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reserved, must be set.
        unsigned BUSY : 1; //!< Reflects the current state of RNGB. If RNGB is currently seeding, generating the next seed, creating a new random number, or performing a self test, this bit is set.
        unsigned SLP : 1; //!< Indicates if the RNGB is in sleep mode. When set, the RNGB is in sleep mode and all internal clocks are disabled. While in this mode, the IP bus interface is still enabled and access to the FIFO is allowed. Once the FIFO is empty, the RNGB fills the FIFO and then enters sleep mode again.
        unsigned RS : 1; //!< Indicates the RNGB needs to be reseeded. This is done by setting RNG_CMD[GS], or automatically if RNG_CR[AR] is set.
        unsigned STDN : 1; //!< Indicates the self test is complete. This bit is cleared by hardware reset or a new self test is initiated by setting RNG_CMD[ST].
        unsigned SDN : 1; //!< Indicates the RNG has generated the first seed.
        unsigned NSDN : 1; //!< Indicates that a new seed is ready for use during the next seed generation process.
        unsigned RESERVED1 : 1; //!< 
        unsigned FIFO_LVL : 4; //!< Indicates the number of random words currently in the output FIFO. The bits should be interpreted as an integer.
        unsigned FIFO_SIZE : 4; //!< Size of the FIFO, and maximum possible FIFO level. The bits should be interpreted as an integer. This value is set to five on the default version of RNGB .
        unsigned ERR : 1; //!< Indicates an error was detected in the RNGB. Read the RNG_ESR register for details.
        unsigned RESERVED2 : 4; //!< 
        unsigned ST_PF : 3; //!< Indicates Pass or Fail status of the TRNG, PRNG, and RESEED self tests, Bit 23 - TRNG self test pass/fail Bit 22 - PRNG self test pass/fail Bit 21 - RESEED self test pass/fail
        unsigned STATPF : 8; //!< Indicates pass or fail status of the various statistics tests on the last seed generated. Bit 31 - Long run test (>34) Bit 30 - Length 6+ run test Bit 29 - Length 5 run test Bit 28 - Length 4 run test Bit 27 - Length 3 run test Bit 26 - Length 2 run test Bit 25 - Length 1 run test Bit 24 - Monobit test
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

/* --- Register HW_RNGB_SR, field BUSY[1:1] (RO)
 *
 * Reflects the current state of RNGB. If RNGB is currently seeding, generating the next seed,
 * creating a new random number, or performing a self test, this bit is set.
 *
 * Values:
 * 0 - Not busy.
 * 1 - Busy.
 */

#define BP_RNGB_SR_BUSY      (1)
#define BM_RNGB_SR_BUSY      (0x00000002)


/* --- Register HW_RNGB_SR, field SLP[2:2] (RO)
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

#define BP_RNGB_SR_SLP      (2)
#define BM_RNGB_SR_SLP      (0x00000004)


/* --- Register HW_RNGB_SR, field RS[3:3] (RO)
 *
 * Indicates the RNGB needs to be reseeded. This is done by setting RNG_CMD[GS], or automatically if
 * RNG_CR[AR] is set.
 *
 * Values:
 * 0 - RNGB does not need to be reseeded.
 * 1 - RNGB needs to be reseeded.
 */

#define BP_RNGB_SR_RS      (3)
#define BM_RNGB_SR_RS      (0x00000008)


/* --- Register HW_RNGB_SR, field STDN[4:4] (RO)
 *
 * Indicates the self test is complete. This bit is cleared by hardware reset or a new self test is
 * initiated by setting RNG_CMD[ST].
 *
 * Values:
 * 0 - Self test not complete.
 * 1 - Completed a self test since the last reset.
 */

#define BP_RNGB_SR_STDN      (4)
#define BM_RNGB_SR_STDN      (0x00000010)


/* --- Register HW_RNGB_SR, field SDN[5:5] (RO)
 *
 * Indicates the RNG has generated the first seed.
 *
 * Values:
 * 0 - Seed generation process not complete.
 * 1 - Completed seed generation since the last reset.
 */

#define BP_RNGB_SR_SDN      (5)
#define BM_RNGB_SR_SDN      (0x00000020)


/* --- Register HW_RNGB_SR, field NSDN[6:6] (RO)
 *
 * Indicates that a new seed is ready for use during the next seed generation process.
 */

#define BP_RNGB_SR_NSDN      (6)
#define BM_RNGB_SR_NSDN      (0x00000040)

/* --- Register HW_RNGB_SR, field FIFO_LVL[11:8] (RO)
 *
 * Indicates the number of random words currently in the output FIFO. The bits should be interpreted
 * as an integer.
 */

#define BP_RNGB_SR_FIFO_LVL      (8)
#define BM_RNGB_SR_FIFO_LVL      (0x00000f00)

/* --- Register HW_RNGB_SR, field FIFO_SIZE[15:12] (RO)
 *
 * Size of the FIFO, and maximum possible FIFO level. The bits should be interpreted as an integer.
 * This value is set to five on the default version of RNGB .
 */

#define BP_RNGB_SR_FIFO_SIZE      (12)
#define BM_RNGB_SR_FIFO_SIZE      (0x0000f000)

/* --- Register HW_RNGB_SR, field ERR[16:16] (RO)
 *
 * Indicates an error was detected in the RNGB. Read the RNG_ESR register for details.
 *
 * Values:
 * 0 - No error.
 * 1 - Error detected.
 */

#define BP_RNGB_SR_ERR      (16)
#define BM_RNGB_SR_ERR      (0x00010000)


/* --- Register HW_RNGB_SR, field ST_PF[23:21] (RO)
 *
 * Indicates Pass or Fail status of the TRNG, PRNG, and RESEED self tests, Bit 23 - TRNG self test
 * pass/fail Bit 22 - PRNG self test pass/fail Bit 21 - RESEED self test pass/fail
 *
 * Values:
 * 0 - Pass.
 * 1 - Fail.
 */

#define BP_RNGB_SR_ST_PF      (21)
#define BM_RNGB_SR_ST_PF      (0x00e00000)


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

#define BP_RNGB_SR_STATPF      (24)
#define BM_RNGB_SR_STATPF      (0xff000000)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_ESR - RNGB Error Status Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LFE : 1; //!< When this bit is set, the interrupt generated was caused by a failure of one of the LFSRs in one of the RNGB's three entropy sources. This bit is sticky and can only be cleared by a software or hardware reset.
        unsigned OSCE : 1; //!< Indicates the oscillator in the RNG may be broken. This bit is sticky and can only be cleared by a software or hardware reset.
        unsigned STE : 1; //!< Indicates the RNGB has failed the most recent self test. This bit is sticky and can only be reset by a hardware reset or by writing one to RNG_CMD[CE].
        unsigned SATE : 1; //!< Indicates if RNGB has failed the statistical tests for the last generated seed. This bit is sticky and is cleared by a hardware or software reset or by writing one to RNG_CMD[CE].
        unsigned FUFE : 1; //!< Indicates the RNGB has experienced a FIFO underflow condition resulting in the last random data read being unreliable. This bit can be masked by RNG_CR[FUFMOD] and is cleared by hardware or software reset or by writing one to RNG_CMD[CE].
        unsigned RESERVED0 : 27; //!< Reserved, must be cleared.
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

/* --- Register HW_RNGB_ESR, field LFE[0:0] (RO)
 *
 * When this bit is set, the interrupt generated was caused by a failure of one of the LFSRs in one
 * of the RNGB's three entropy sources. This bit is sticky and can only be cleared by a software or
 * hardware reset.
 *
 * Values:
 * 0 - LFSRs are working properly.
 * 1 - LFSR failure has occurred.
 */

#define BP_RNGB_ESR_LFE      (0)
#define BM_RNGB_ESR_LFE      (0x00000001)


/* --- Register HW_RNGB_ESR, field OSCE[1:1] (RO)
 *
 * Indicates the oscillator in the RNG may be broken. This bit is sticky and can only be cleared by
 * a software or hardware reset.
 *
 * Values:
 * 0 - RNG oscillator is working properly.
 * 1 - Problem detected with the RNG oscillator.
 */

#define BP_RNGB_ESR_OSCE      (1)
#define BM_RNGB_ESR_OSCE      (0x00000002)


/* --- Register HW_RNGB_ESR, field STE[2:2] (RO)
 *
 * Indicates the RNGB has failed the most recent self test. This bit is sticky and can only be reset
 * by a hardware reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - RNGB has not failed self test.
 * 1 - RNGB has failed self test.
 */

#define BP_RNGB_ESR_STE      (2)
#define BM_RNGB_ESR_STE      (0x00000004)


/* --- Register HW_RNGB_ESR, field SATE[3:3] (RO)
 *
 * Indicates if RNGB has failed the statistical tests for the last generated seed. This bit is
 * sticky and is cleared by a hardware or software reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - RNGB has not failed the statistical tests.
 * 1 - RNGB has failed the statistical tests during initialization.
 */

#define BP_RNGB_ESR_SATE      (3)
#define BM_RNGB_ESR_SATE      (0x00000008)


/* --- Register HW_RNGB_ESR, field FUFE[4:4] (RO)
 *
 * Indicates the RNGB has experienced a FIFO underflow condition resulting in the last random data
 * read being unreliable. This bit can be masked by RNG_CR[FUFMOD] and is cleared by hardware or
 * software reset or by writing one to RNG_CMD[CE].
 *
 * Values:
 * 0 - FIFO underflow has not occurred.
 * 1 - FIFO underflow has occurred
 */

#define BP_RNGB_ESR_FUFE      (4)
#define BM_RNGB_ESR_FUFE      (0x00000010)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RNGB_OUT - RNGB Output FIFO (RO)
 *
 * The RNGBOUT provides temporary storage for random data generated by the RNGB. This allows the
 * host user to read multiple random longwords back-to-back. A read of this address when the FIFO is
 * not empty, returns 32 bits of random data. If the FIFO is read when empty, a FIFO underrun
 * response is returned according to RNG_CR[FUFMOD]. For optimal system performance, poll
 * RNG_SR[FIFO_LVL] to ensure random values are present before reading the FIFO.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RANDOUT : 32; //!< 
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

#define BP_RNGB_OUT_RANDOUT      (0)
#define BM_RNGB_OUT_RANDOUT      (0xffffffff)


/*!
 * @brief All RNGB module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_rngb_ver_t VER; //!< RNGB Version ID Register
    volatile hw_rngb_cmd_t CMD; //!< RNGB Command Register
    volatile hw_rngb_cr_t CR; //!< RNGB Control Register
    volatile hw_rngb_sr_t SR; //!< RNGB Status Register
    volatile hw_rngb_esr_t ESR; //!< RNGB Error Status Register
    volatile hw_rngb_out_t OUT; //!< RNGB Output FIFO
} hw_rngb_t;
#endif

//! @brief Macro to access all RNGB registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_RNGB(0)</code>.
#define HW_RNGB     (*(volatile hw_rngb_t *) REGS_RNGB_BASE)


#endif // _RNGB_H
