/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SATAPHY_CLOCK_H
#define _SATAPHY_CLOCK_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT - Creg Compare Upper Limit Register
 * - HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT - Creg Compare Lower Limit Register
 * - HW_SATAPHY_CLOCK_CRCMP_MASK - Creg Compare Mask Register
 * - HW_SATAPHY_CLOCK_CRCMP_CTL - Creg Compare Control Register
 * - HW_SATAPHY_CLOCK_CRCMP_STAT - Creg Compare Status Register
 * - HW_SATAPHY_CLOCK_SCOPE_SAMPLES - Scope Sample Count Register
 * - HW_SATAPHY_CLOCK_SCOPE_COUNT - Scope Count Result Register
 * - HW_SATAPHY_CLOCK_DAC_CTL - DAC Control Register
 * - HW_SATAPHY_CLOCK_RTUNE_CTL - Resistor Tuning Control Register
 * - HW_SATAPHY_CLOCK_ADC_OUT - ADC Output Register
 * - HW_SATAPHY_CLOCK_SS_PHASE - Spread Spectrum Phase Register
 * - HW_SATAPHY_CLOCK_CHIP_ID_HI - JTAG Chip ID (High Bits) Register
 * - HW_SATAPHY_CLOCK_CHIP_ID_LOW - JTAG Chip ID (Low Bits) Register
 * - HW_SATAPHY_CLOCK_FREQ_STAT - Frequency Status Register
 * - HW_SATAPHY_CLOCK_CTL_STAT - Control Status Register
 * - HW_SATAPHY_CLOCK_LVL-STAT - Level Status Register
 * - HW_SATAPHY_CLOCK_CREG_STAT - Creg Status Register
 * - HW_SATAPHY_CLOCK_FREW_OVRD - Frequency Override Register
 * - HW_SATAPHY_CLOCK_CTL_OVRD - Control Override Register
 * - HW_SATAPHY_CLOCK_LVL_OVRD - Level Override Register
 * - HW_SATAPHY_CLOCK_CREG_OVRD - Creg Override Register
 * - HW_SATAPHY_CLOCK_MPLL_CTL - MPLL Control Register
 * - HW_SATAPHY_CLOCK_MPLL_TEST - MPLL Test Register
 * - HW_SATAPHY_CLOCK_SS_FREQ - Spread Spectrum Frequency Register
 * - HW_SATAPHY_CLOCK_SEL_STAT - Clock Select Status Register
 * - HW_SATAPHY_CLOCK_SEL_OVRD - Clock Select Override Register
 * - HW_SATAPHY_CLOCK_RESET - Reset Register
 *
 * hw_sataphy_clock_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SATAPHY_CLOCK_BASE
#define REGS_SATAPHY_CLOCK_BASE (0x00000000) //!< Base address for SATAPHY_CLOCK.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT - Creg Compare Upper Limit Register (RW)
 *
 * Address: 0x0001  Reset value: 16'b 0000 0000 0000 0000  This register contains the less-than-
 * limit compare point.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CRCMP_LT_LIMIT : 16; //!< Less-than-limit compare point
    } B;
} hw_sataphy_clock_crcmp_lt_limit_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_LT_LIMIT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT           (*(volatile hw_sataphy_clock_crcmp_lt_limit_t *) HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_ADDR)
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_RD()      (HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT.U)
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_WR(v)     (HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT.U = (v))
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_SET(v)    (HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CLR(v)    (HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_TOG(v)    (HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_LT_LIMIT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT, field CRCMP_LT_LIMIT (RW)
 *
 * Less-than-limit compare point
 */

#define BP_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT      0
#define BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT)
#else
#define BF_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRCMP_LT_LIMIT field to a new value.
#define BW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT(v)   BF_CS1(SATAPHY_CLOCK_CRCMP_LT_LIMIT, CRCMP_LT_LIMIT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT - Creg Compare Lower Limit Register (RW)
 *
 * Address: 0x0002  Reset value: 16'b 1111 1111 1111 1111  This register contains the greater-than-
 * limit compare point.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CRCMP_GT_LIMIT : 16; //!< Greater-than-limit compare point
    } B;
} hw_sataphy_clock_crcmp_gt_limit_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_GT_LIMIT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT           (*(volatile hw_sataphy_clock_crcmp_gt_limit_t *) HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_ADDR)
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_RD()      (HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT.U)
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_WR(v)     (HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT.U = (v))
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_SET(v)    (HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CLR(v)    (HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_TOG(v)    (HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_WR(HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_GT_LIMIT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT, field CRCMP_GT_LIMIT (RW)
 *
 * Greater-than-limit compare point
 */

#define BP_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT      0
#define BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT)
#else
#define BF_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRCMP_GT_LIMIT field to a new value.
#define BW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT(v)   BF_CS1(SATAPHY_CLOCK_CRCMP_GT_LIMIT, CRCMP_GT_LIMIT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_MASK - Creg Compare Mask Register (RW)
 *
 * Address: 0x0003  Reset value: 16'b 1111 1111 1111 1111  This register contains the
 * compare/scratch value mask.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CRCMP_MASK : 16; //!< Mask for comparisons
    } B;
} hw_sataphy_clock_crcmp_mask_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_MASK register
 */
#define HW_SATAPHY_CLOCK_CRCMP_MASK_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_MASK           (*(volatile hw_sataphy_clock_crcmp_mask_t *) HW_SATAPHY_CLOCK_CRCMP_MASK_ADDR)
#define HW_SATAPHY_CLOCK_CRCMP_MASK_RD()      (HW_SATAPHY_CLOCK_CRCMP_MASK.U)
#define HW_SATAPHY_CLOCK_CRCMP_MASK_WR(v)     (HW_SATAPHY_CLOCK_CRCMP_MASK.U = (v))
#define HW_SATAPHY_CLOCK_CRCMP_MASK_SET(v)    (HW_SATAPHY_CLOCK_CRCMP_MASK_WR(HW_SATAPHY_CLOCK_CRCMP_MASK_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CRCMP_MASK_CLR(v)    (HW_SATAPHY_CLOCK_CRCMP_MASK_WR(HW_SATAPHY_CLOCK_CRCMP_MASK_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CRCMP_MASK_TOG(v)    (HW_SATAPHY_CLOCK_CRCMP_MASK_WR(HW_SATAPHY_CLOCK_CRCMP_MASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_MASK bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_MASK, field CRCMP_MASK (RW)
 *
 * Mask for comparisons
 */

#define BP_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK      0
#define BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK)
#else
#define BF_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRCMP_MASK field to a new value.
#define BW_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK(v)   BF_CS1(SATAPHY_CLOCK_CRCMP_MASK, CRCMP_MASK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_CTL - Creg Compare Control Register (RW)
 *
 * Address: 0x0004  Reset value: 16'b 0000 0000 0000 0000  This register contains the scratch space
 * control bits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HOLD_SCRATCH0 : 1; //!< Scratch0 is not updated on register reads.
        unsigned short HOLD_SCRATCH1 : 1; //!< Scratch1 is not updated on register reads.
        unsigned short RESERVED0 : 14; //!< Reserved
    } B;
} hw_sataphy_clock_crcmp_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_CTL register
 */
#define HW_SATAPHY_CLOCK_CRCMP_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_CTL           (*(volatile hw_sataphy_clock_crcmp_ctl_t *) HW_SATAPHY_CLOCK_CRCMP_CTL_ADDR)
#define HW_SATAPHY_CLOCK_CRCMP_CTL_RD()      (HW_SATAPHY_CLOCK_CRCMP_CTL.U)
#define HW_SATAPHY_CLOCK_CRCMP_CTL_WR(v)     (HW_SATAPHY_CLOCK_CRCMP_CTL.U = (v))
#define HW_SATAPHY_CLOCK_CRCMP_CTL_SET(v)    (HW_SATAPHY_CLOCK_CRCMP_CTL_WR(HW_SATAPHY_CLOCK_CRCMP_CTL_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CRCMP_CTL_CLR(v)    (HW_SATAPHY_CLOCK_CRCMP_CTL_WR(HW_SATAPHY_CLOCK_CRCMP_CTL_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CRCMP_CTL_TOG(v)    (HW_SATAPHY_CLOCK_CRCMP_CTL_WR(HW_SATAPHY_CLOCK_CRCMP_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_CTL, field HOLD_SCRATCH0 (RW)
 *
 * Scratch0 is not updated on register reads.
 */

#define BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0      0
#define BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0)
#else
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_SCRATCH0 field to a new value.
#define BW_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0(v)   BF_CS1(SATAPHY_CLOCK_CRCMP_CTL, HOLD_SCRATCH0, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CRCMP_CTL, field HOLD_SCRATCH1 (RW)
 *
 * Scratch1 is not updated on register reads.
 */

#define BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1      1
#define BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1)
#else
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1(v)   (((v) << 1) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_SCRATCH1 field to a new value.
#define BW_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1(v)   BF_CS1(SATAPHY_CLOCK_CRCMP_CTL, HOLD_SCRATCH1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_STAT - Creg Compare Status Register (RO)
 *
 * Address: 0x0005  Reset value: 16'b xxxx xxxx xxxx xxxx  This register contains the results of
 * scratch register comparisons to various limits.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short S0_LOW : 1; //!< Masked Scratch0 is lower than CRCMP_LT_LIMIT
        unsigned short S0_HIGH : 1; //!< Masked Scratch0 is higher than CRCMP_HT_LIMIT.
        unsigned short S1_S0_LOW : 1; //!< Masked (Scratch1 - Scratch0) is lower than CRCMP_LT_LIMIT.
        unsigned short S1_S0_HIGH : 1; //!< Masked (Scratch1 - Scratch0) is higher than CRCMP_HT_LIMIT.
        unsigned short S0_OUTSIDE : 1; //!< Logical OR of S0_LOW and S0_HIGH Useful for determining if the value is near signed zero.
        unsigned short S1_S0_OUTSIDE : 1; //!< Logical OR of S1_S0_LOW and S1_S0_HIGH Useful for determining if the difference is near signed zero.
        unsigned short RESERVED0 : 10; //!< Reserved
    } B;
} hw_sataphy_clock_crcmp_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_STAT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_STAT           (*(volatile hw_sataphy_clock_crcmp_stat_t *) HW_SATAPHY_CLOCK_CRCMP_STAT_ADDR)
#define HW_SATAPHY_CLOCK_CRCMP_STAT_RD()      (HW_SATAPHY_CLOCK_CRCMP_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_LOW (RO)
 *
 * Masked Scratch0 is lower than CRCMP_LT_LIMIT
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW      0
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW      0x00000001

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_HIGH (RO)
 *
 * Masked Scratch0 is higher than CRCMP_HT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH      1
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH      0x00000002

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_LOW (RO)
 *
 * Masked (Scratch1 - Scratch0) is lower than CRCMP_LT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW      2
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW      0x00000004

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_HIGH (RO)
 *
 * Masked (Scratch1 - Scratch0) is higher than CRCMP_HT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH      3
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH      0x00000008

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_OUTSIDE (RO)
 *
 * Logical OR of S0_LOW and S0_HIGH Useful for determining if the value is near signed zero.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE      4
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE      0x00000010

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_OUTSIDE (RO)
 *
 * Logical OR of S1_S0_LOW and S1_S0_HIGH Useful for determining if the difference is near signed
 * zero.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE      5
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE      0x00000020

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SCOPE_SAMPLES - Scope Sample Count Register (RW)
 *
 * Address: 0x0006  Reset value: 16'b 0000 0001 0000 0000  This register specifies the number of
 * samples to count.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SCOPE_SAMPLES : 16; //!< The number of samples to count
    } B;
} hw_sataphy_clock_scope_samples_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SCOPE_SAMPLES register
 */
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES           (*(volatile hw_sataphy_clock_scope_samples_t *) HW_SATAPHY_CLOCK_SCOPE_SAMPLES_ADDR)
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_RD()      (HW_SATAPHY_CLOCK_SCOPE_SAMPLES.U)
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_WR(v)     (HW_SATAPHY_CLOCK_SCOPE_SAMPLES.U = (v))
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_SET(v)    (HW_SATAPHY_CLOCK_SCOPE_SAMPLES_WR(HW_SATAPHY_CLOCK_SCOPE_SAMPLES_RD() |  (v)))
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_CLR(v)    (HW_SATAPHY_CLOCK_SCOPE_SAMPLES_WR(HW_SATAPHY_CLOCK_SCOPE_SAMPLES_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_TOG(v)    (HW_SATAPHY_CLOCK_SCOPE_SAMPLES_WR(HW_SATAPHY_CLOCK_SCOPE_SAMPLES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SCOPE_SAMPLES bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SCOPE_SAMPLES, field SCOPE_SAMPLES (RW)
 *
 * The number of samples to count
 */

#define BP_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES      0
#define BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES)
#else
#define BF_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES(v)   (((v) << 0) & BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SCOPE_SAMPLES field to a new value.
#define BW_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES(v)   BF_CS1(SATAPHY_CLOCK_SCOPE_SAMPLES, SCOPE_SAMPLES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SCOPE_COUNT - Scope Count Result Register (RO)
 *
 * Address: 0x0007  Reset value: 16'b xxxx xxxx xxxx xxxx  This register provides the results of
 * scope counting. A write to this register starts the counting process. A value of FFFF indicates
 * that the count is still in progress.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short SCOPE_COUNT : 16; //!< Results of scope counting
    } B;
} hw_sataphy_clock_scope_count_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SCOPE_COUNT register
 */
#define HW_SATAPHY_CLOCK_SCOPE_COUNT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SCOPE_COUNT           (*(volatile hw_sataphy_clock_scope_count_t *) HW_SATAPHY_CLOCK_SCOPE_COUNT_ADDR)
#define HW_SATAPHY_CLOCK_SCOPE_COUNT_RD()      (HW_SATAPHY_CLOCK_SCOPE_COUNT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SCOPE_COUNT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SCOPE_COUNT, field SCOPE_COUNT (RO)
 *
 * Results of scope counting
 */

#define BP_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT      0
#define BM_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_DAC_CTL - DAC Control Register (RW)
 *
 * Reset value: 16'b x000 0001 1111 1111  This register supports DAC values and controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DAC_VAL : 10; //!< Digital value to be used for DAC
        unsigned short OVRD_RTUNE_TX : 1; //!< Writes DAC_VAL[5:0] to the Tx rtune bus
        unsigned short OVRD_RTUNE_RX : 1; //!< Writes DAC_VAL[5:0] to the Rx rtune bus
        unsigned short DAC_MODE : 3; //!< DAC output mode:
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_clock_dac_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_DAC_CTL register
 */
#define HW_SATAPHY_CLOCK_DAC_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_DAC_CTL           (*(volatile hw_sataphy_clock_dac_ctl_t *) HW_SATAPHY_CLOCK_DAC_CTL_ADDR)
#define HW_SATAPHY_CLOCK_DAC_CTL_RD()      (HW_SATAPHY_CLOCK_DAC_CTL.U)
#define HW_SATAPHY_CLOCK_DAC_CTL_WR(v)     (HW_SATAPHY_CLOCK_DAC_CTL.U = (v))
#define HW_SATAPHY_CLOCK_DAC_CTL_SET(v)    (HW_SATAPHY_CLOCK_DAC_CTL_WR(HW_SATAPHY_CLOCK_DAC_CTL_RD() |  (v)))
#define HW_SATAPHY_CLOCK_DAC_CTL_CLR(v)    (HW_SATAPHY_CLOCK_DAC_CTL_WR(HW_SATAPHY_CLOCK_DAC_CTL_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_DAC_CTL_TOG(v)    (HW_SATAPHY_CLOCK_DAC_CTL_WR(HW_SATAPHY_CLOCK_DAC_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_DAC_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field DAC_VAL (RW)
 *
 * Digital value to be used for DAC
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_DAC_VAL      0
#define BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_VAL(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL)
#else
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_VAL(v)   (((v) << 0) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAC_VAL field to a new value.
#define BW_SATAPHY_CLOCK_DAC_CTL_DAC_VAL(v)   BF_CS1(SATAPHY_CLOCK_DAC_CTL, DAC_VAL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field OVRD_RTUNE_TX (RW)
 *
 * Writes DAC_VAL[5:0] to the Tx rtune bus
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX      10
#define BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX)
#else
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX(v)   (((v) << 10) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_RTUNE_TX field to a new value.
#define BW_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX(v)   BF_CS1(SATAPHY_CLOCK_DAC_CTL, OVRD_RTUNE_TX, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field OVRD_RTUNE_RX (RW)
 *
 * Writes DAC_VAL[5:0] to the Rx rtune bus
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX      11
#define BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX(v)   ((((reg32_t) v) << 11) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX)
#else
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX(v)   (((v) << 11) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_RTUNE_RX field to a new value.
#define BW_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX(v)   BF_CS1(SATAPHY_CLOCK_DAC_CTL, OVRD_RTUNE_RX, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field DAC_MODE (RW)
 *
 * DAC output mode:
 *
 * Values:
 * 000 - Powers down DAC
 * 001 - Reserved
 * 010 - High-range margining (VP25 x 418e-6 res)
 * 011 - Low-range margining (VP25 x 279e-6 res)
 * 100 - 100% range DAC, 0% offset
 * 101 - 36% range DAC, 0% offset
 * 110 - 36% range DAC, 33% offset
 * 111 - 36% range DAC, 66% offset
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_DAC_MODE      12
#define BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_MODE(v)   ((((reg32_t) v) << 12) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE)
#else
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_MODE(v)   (((v) << 12) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAC_MODE field to a new value.
#define BW_SATAPHY_CLOCK_DAC_CTL_DAC_MODE(v)   BF_CS1(SATAPHY_CLOCK_DAC_CTL, DAC_MODE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_RTUNE_CTL - Resistor Tuning Control Register (RW)
 *
 * Reset value: 16'b xxxx x000 0010 0000  This register contains resistor tuning controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MODE : 2; //!< Resistor tune SAR mode:
        unsigned short FRC_PWRON : 1; //!< Overrides internal power-on
        unsigned short PWRON_LCL : 1; //!< Value of power-on to force
        unsigned short SEL_ATBP : 1; //!< Selects atb_s_p for A/D measurement
        unsigned short RSC_X4 : 1; //!< Sets x4 in rescal circuitry
        unsigned short DAC_CHOP : 1; //!< Polarity of chop control for DAC
        unsigned short CMP_INVERT : 1; //!< Inverts output of comparator (to reverse successive approximation register (SAR) feedback loop)
        unsigned short RTUNE_DIS : 1; //!< Disables automatic resistor recalibrations
        unsigned short RTUNE_TRIG : 1; //!< Triggers manual resistor calibration
        unsigned short ADC_TRIG : 1; //!< Triggers ADC conversion
        unsigned short RESERVED0 : 5; //!< Reserved
    } B;
} hw_sataphy_clock_rtune_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_RTUNE_CTL register
 */
#define HW_SATAPHY_CLOCK_RTUNE_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_RTUNE_CTL           (*(volatile hw_sataphy_clock_rtune_ctl_t *) HW_SATAPHY_CLOCK_RTUNE_CTL_ADDR)
#define HW_SATAPHY_CLOCK_RTUNE_CTL_RD()      (HW_SATAPHY_CLOCK_RTUNE_CTL.U)
#define HW_SATAPHY_CLOCK_RTUNE_CTL_WR(v)     (HW_SATAPHY_CLOCK_RTUNE_CTL.U = (v))
#define HW_SATAPHY_CLOCK_RTUNE_CTL_SET(v)    (HW_SATAPHY_CLOCK_RTUNE_CTL_WR(HW_SATAPHY_CLOCK_RTUNE_CTL_RD() |  (v)))
#define HW_SATAPHY_CLOCK_RTUNE_CTL_CLR(v)    (HW_SATAPHY_CLOCK_RTUNE_CTL_WR(HW_SATAPHY_CLOCK_RTUNE_CTL_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_RTUNE_CTL_TOG(v)    (HW_SATAPHY_CLOCK_RTUNE_CTL_WR(HW_SATAPHY_CLOCK_RTUNE_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_RTUNE_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field MODE (RW)
 *
 * Resistor tune SAR mode:
 *
 * Values:
 * 00 - Normal restune
 * 01 - ADC
 * 10 - Rx Resistor test
 * 11 - Tx Resistor test
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_MODE      0
#define BM_SATAPHY_CLOCK_RTUNE_CTL_MODE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_MODE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_RTUNE_CTL_MODE)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_MODE(v)   (((v) << 0) & BM_SATAPHY_CLOCK_RTUNE_CTL_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_MODE(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, MODE, v)
#endif


/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field FRC_PWRON (RW)
 *
 * Overrides internal power-on
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON      2
#define BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON(v)   (((v) << 2) & BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRC_PWRON field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, FRC_PWRON, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field PWRON_LCL (RW)
 *
 * Value of power-on to force
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL      3
#define BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL(v)   (((v) << 3) & BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PWRON_LCL field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, PWRON_LCL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field SEL_ATBP (RW)
 *
 * Selects atb_s_p for A/D measurement
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP      4
#define BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP(v)   (((v) << 4) & BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEL_ATBP field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, SEL_ATBP, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RSC_X4 (RW)
 *
 * Sets x4 in rescal circuitry
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4      5
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4(v)   (((v) << 5) & BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RSC_X4 field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, RSC_X4, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field DAC_CHOP (RW)
 *
 * Polarity of chop control for DAC
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP      6
#define BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP(v)   (((v) << 6) & BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAC_CHOP field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, DAC_CHOP, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field CMP_INVERT (RW)
 *
 * Inverts output of comparator (to reverse successive approximation register (SAR) feedback loop)
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT      7
#define BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT(v)   (((v) << 7) & BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CMP_INVERT field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, CMP_INVERT, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RTUNE_DIS (RW)
 *
 * Disables automatic resistor recalibrations
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS      8
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS(v)   (((v) << 8) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_DIS field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, RTUNE_DIS, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RTUNE_TRIG (RW)
 *
 * Triggers manual resistor calibration
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG      9
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG(v)   ((((reg32_t) v) << 9) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG(v)   (((v) << 9) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_TRIG field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, RTUNE_TRIG, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field ADC_TRIG (RW)
 *
 * Triggers ADC conversion
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG      10
#define BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG)
#else
#define BF_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG(v)   (((v) << 10) & BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADC_TRIG field to a new value.
#define BW_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG(v)   BF_CS1(SATAPHY_CLOCK_RTUNE_CTL, ADC_TRIG, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_ADC_OUT - ADC Output Register (RO)
 *
 * Address: 0x000A  Reset value: 16'b xxxx xxxx xxxx xxxx  This register contains the results of the
 * ADC process. A read from this register starts a new A/D conversion.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short VALUE : 10; //!< A/D conversion result Based on RTUNE_CTL.MODE, this value is the result of either the last conversion (MODES 0 or 1) or the current Tx/Rx cal value (MODES 3/2).
        unsigned short FRESH : 1; //!< Flag indicates that a new A/D conversion result is present.
        unsigned short RESERVED0 : 5; //!< Reserved
    } B;
} hw_sataphy_clock_adc_out_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_ADC_OUT register
 */
#define HW_SATAPHY_CLOCK_ADC_OUT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_ADC_OUT           (*(volatile hw_sataphy_clock_adc_out_t *) HW_SATAPHY_CLOCK_ADC_OUT_ADDR)
#define HW_SATAPHY_CLOCK_ADC_OUT_RD()      (HW_SATAPHY_CLOCK_ADC_OUT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_ADC_OUT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_ADC_OUT, field VALUE (RO)
 *
 * A/D conversion result Based on RTUNE_CTL.MODE, this value is the result of either the last
 * conversion (MODES 0 or 1) or the current Tx/Rx cal value (MODES 3/2).
 */

#define BP_SATAPHY_CLOCK_ADC_OUT_VALUE      0
#define BM_SATAPHY_CLOCK_ADC_OUT_VALUE      0x000003ff

/* --- Register HW_SATAPHY_CLOCK_ADC_OUT, field FRESH (RO)
 *
 * Flag indicates that a new A/D conversion result is present.
 */

#define BP_SATAPHY_CLOCK_ADC_OUT_FRESH      10
#define BM_SATAPHY_CLOCK_ADC_OUT_FRESH      0x00000400

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SS_PHASE - Spread Spectrum Phase Register (RW)
 *
 * Address: 0x000B  Reset value: 16'b xxx0 0000 0000 0000  This register contains the current MPLL
 * phase selector value.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DTHR : 2; //!< Bits below the useful resolution
        unsigned short VAL : 10; //!< Phase value from zero reference
        unsigned short ZERO_FREQ : 1; //!< Zero frequency register Must be set for PHASE writes to not be immediately overwritten.
        unsigned short RESERVED0 : 3; //!< Reserved
    } B;
} hw_sataphy_clock_ss_phase_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SS_PHASE register
 */
#define HW_SATAPHY_CLOCK_SS_PHASE_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SS_PHASE           (*(volatile hw_sataphy_clock_ss_phase_t *) HW_SATAPHY_CLOCK_SS_PHASE_ADDR)
#define HW_SATAPHY_CLOCK_SS_PHASE_RD()      (HW_SATAPHY_CLOCK_SS_PHASE.U)
#define HW_SATAPHY_CLOCK_SS_PHASE_WR(v)     (HW_SATAPHY_CLOCK_SS_PHASE.U = (v))
#define HW_SATAPHY_CLOCK_SS_PHASE_SET(v)    (HW_SATAPHY_CLOCK_SS_PHASE_WR(HW_SATAPHY_CLOCK_SS_PHASE_RD() |  (v)))
#define HW_SATAPHY_CLOCK_SS_PHASE_CLR(v)    (HW_SATAPHY_CLOCK_SS_PHASE_WR(HW_SATAPHY_CLOCK_SS_PHASE_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_SS_PHASE_TOG(v)    (HW_SATAPHY_CLOCK_SS_PHASE_WR(HW_SATAPHY_CLOCK_SS_PHASE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SS_PHASE bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field DTHR (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_DTHR      0
#define BM_SATAPHY_CLOCK_SS_PHASE_DTHR      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_PHASE_DTHR(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_SS_PHASE_DTHR)
#else
#define BF_SATAPHY_CLOCK_SS_PHASE_DTHR(v)   (((v) << 0) & BM_SATAPHY_CLOCK_SS_PHASE_DTHR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTHR field to a new value.
#define BW_SATAPHY_CLOCK_SS_PHASE_DTHR(v)   BF_CS1(SATAPHY_CLOCK_SS_PHASE, DTHR, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field VAL (RW)
 *
 * Phase value from zero reference
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_VAL      2
#define BM_SATAPHY_CLOCK_SS_PHASE_VAL      0x00000ffc

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_PHASE_VAL(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_SS_PHASE_VAL)
#else
#define BF_SATAPHY_CLOCK_SS_PHASE_VAL(v)   (((v) << 2) & BM_SATAPHY_CLOCK_SS_PHASE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VAL field to a new value.
#define BW_SATAPHY_CLOCK_SS_PHASE_VAL(v)   BF_CS1(SATAPHY_CLOCK_SS_PHASE, VAL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field ZERO_FREQ (RW)
 *
 * Zero frequency register Must be set for PHASE writes to not be immediately overwritten.
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ      12
#define BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ(v)   ((((reg32_t) v) << 12) & BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ)
#else
#define BF_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ(v)   (((v) << 12) & BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_FREQ field to a new value.
#define BW_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ(v)   BF_CS1(SATAPHY_CLOCK_SS_PHASE, ZERO_FREQ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CHIP_ID_HI - JTAG Chip ID (High Bits) Register (RO)
 *
 * Address: 0x000C  Reset value: See value for ID_VAL_HI in .  This register contains the internal
 * chip ID (high 16 bits) of the JTAG interface.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CHIP_ID_HI : 16; //!< Internal chip ID (high 16 bits)
    } B;
} hw_sataphy_clock_chip_id_hi_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CHIP_ID_HI register
 */
#define HW_SATAPHY_CLOCK_CHIP_ID_HI_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CHIP_ID_HI           (*(volatile hw_sataphy_clock_chip_id_hi_t *) HW_SATAPHY_CLOCK_CHIP_ID_HI_ADDR)
#define HW_SATAPHY_CLOCK_CHIP_ID_HI_RD()      (HW_SATAPHY_CLOCK_CHIP_ID_HI.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CHIP_ID_HI bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CHIP_ID_HI, field CHIP_ID_HI (RO)
 *
 * Internal chip ID (high 16 bits)
 */

#define BP_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI      0
#define BM_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CHIP_ID_LOW - JTAG Chip ID (Low Bits) Register (RO)
 *
 * Address: 0x000D  Reset value: See value for ID_VAL_LO in .  This register contains the internal
 * chip ID (low 16 bits) of the JTAG interface.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CHIP_ID_LO : 16; //!< Internal chip ID (low 16 bits)
    } B;
} hw_sataphy_clock_chip_id_low_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CHIP_ID_LOW register
 */
#define HW_SATAPHY_CLOCK_CHIP_ID_LOW_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CHIP_ID_LOW           (*(volatile hw_sataphy_clock_chip_id_low_t *) HW_SATAPHY_CLOCK_CHIP_ID_LOW_ADDR)
#define HW_SATAPHY_CLOCK_CHIP_ID_LOW_RD()      (HW_SATAPHY_CLOCK_CHIP_ID_LOW.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CHIP_ID_LOW bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CHIP_ID_LOW, field CHIP_ID_LO (RO)
 *
 * Internal chip ID (low 16 bits)
 */

#define BP_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO      0
#define BM_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO      0x0000ffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_FREQ_STAT - Frequency Status Register (RO)
 *
 * Address: 0x000E  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of frequency control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short PROP_CTL : 3; //!< Proportional charge pump control
        unsigned short INT_CTL : 3; //!< Integral charge pump control
        unsigned short NCY5 : 2; //!< Divide-by-5 control
        unsigned short NCY : 5; //!< Divide-by-4 cycle control
        unsigned short PRESCALE : 2; //!< Prescaler control
        unsigned short RESERVED : 1; //!< Always reads as 1
    } B;
} hw_sataphy_clock_freq_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_FREQ_STAT register
 */
#define HW_SATAPHY_CLOCK_FREQ_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_FREQ_STAT           (*(volatile hw_sataphy_clock_freq_stat_t *) HW_SATAPHY_CLOCK_FREQ_STAT_ADDR)
#define HW_SATAPHY_CLOCK_FREQ_STAT_RD()      (HW_SATAPHY_CLOCK_FREQ_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_FREQ_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field PROP_CTL (RO)
 *
 * Proportional charge pump control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL      0
#define BM_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL      0x00000007

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field INT_CTL (RO)
 *
 * Integral charge pump control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_INT_CTL      3
#define BM_SATAPHY_CLOCK_FREQ_STAT_INT_CTL      0x00000038

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field NCY5 (RO)
 *
 * Divide-by-5 control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_NCY5      6
#define BM_SATAPHY_CLOCK_FREQ_STAT_NCY5      0x000000c0

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field NCY (RO)
 *
 * Divide-by-4 cycle control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_NCY      8
#define BM_SATAPHY_CLOCK_FREQ_STAT_NCY      0x00001f00

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field PRESCALE (RO)
 *
 * Prescaler control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_PRESCALE      13
#define BM_SATAPHY_CLOCK_FREQ_STAT_PRESCALE      0x00006000

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field RESERVED (RO)
 *
 * Always reads as 1
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_RESERVED      15
#define BM_SATAPHY_CLOCK_FREQ_STAT_RESERVED      0x00008000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CTL_STAT - Control Status Register (RO)
 *
 * Address: 0x000F  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of various control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short USE_REFCLK_ALT : 1; //!< Alternate refclk is used
        unsigned short MPLL_CLK_OFF : 1; //!< Reference clock is off
        unsigned short MPLL_PWRON : 1; //!< MPLL power-on control
        unsigned short MPLL_SS_EN : 1; //!< Spread spectrum enable
        unsigned short CKO_ALIVE_CON : 2; //!< cko_alive MUX control
        unsigned short CKO_WORD_CON : 3; //!< cko_word MUX control
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short RTUNE_DO_TUNE : 1; //!< Manual resistor tune control
        unsigned short WIDE_XFACE : 1; //!< Wide interface control
        unsigned short VPH_IS_3P3 : 1; //!< High voltage supply is 3.3 V
        unsigned short VP_IS_1P2 : 1; //!< Low voltage supply is 1.2 V
        unsigned short FAST_TECH : 1; //!< Technology is fast
        unsigned short RESERVED1 : 1; //!< Reserved
    } B;
} hw_sataphy_clock_ctl_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CTL_STAT register
 */
#define HW_SATAPHY_CLOCK_CTL_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CTL_STAT           (*(volatile hw_sataphy_clock_ctl_stat_t *) HW_SATAPHY_CLOCK_CTL_STAT_ADDR)
#define HW_SATAPHY_CLOCK_CTL_STAT_RD()      (HW_SATAPHY_CLOCK_CTL_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CTL_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field USE_REFCLK_ALT (RO)
 *
 * Alternate refclk is used
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT      0
#define BM_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT      0x00000001

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_CLK_OFF (RO)
 *
 * Reference clock is off
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF      1
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF      0x00000002

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_PWRON (RO)
 *
 * MPLL power-on control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON      2
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON      0x00000004

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_SS_EN (RO)
 *
 * Spread spectrum enable
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN      3
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN      0x00000008

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field CKO_ALIVE_CON (RO)
 *
 * cko_alive MUX control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON      4
#define BM_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON      0x00000030

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field CKO_WORD_CON (RO)
 *
 * cko_word MUX control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON      6
#define BM_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON      0x000001c0

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field RTUNE_DO_TUNE (RO)
 *
 * Manual resistor tune control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE      10
#define BM_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE      0x00000400

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field WIDE_XFACE (RO)
 *
 * Wide interface control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE      11
#define BM_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE      0x00000800

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field VPH_IS_3P3 (RO)
 *
 * High voltage supply is 3.3 V
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3      12
#define BM_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3      0x00001000

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field VP_IS_1P2 (RO)
 *
 * Low voltage supply is 1.2 V
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2      13
#define BM_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2      0x00002000

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field FAST_TECH (RO)
 *
 * Technology is fast
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_FAST_TECH      14
#define BM_SATAPHY_CLOCK_CTL_STAT_FAST_TECH      0x00004000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_LVL-STAT - Level Status Register (RO)
 *
 * Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register indicates the status of
 * level control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ACJT_LVL : 5; //!< ACJTAG comparator level
        unsigned short LOS_LVL : 5; //!< Loss of Signal Detector level
        unsigned short TX_LVL : 5; //!< Transmit level
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_clock_lvl-stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_LVL-STAT register
 */
#define HW_SATAPHY_CLOCK_LVL-STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_LVL-STAT           (*(volatile hw_sataphy_clock_lvl-stat_t *) HW_SATAPHY_CLOCK_LVL-STAT_ADDR)
#define HW_SATAPHY_CLOCK_LVL-STAT_RD()      (HW_SATAPHY_CLOCK_LVL-STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_LVL-STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_LVL-STAT, field ACJT_LVL (RO)
 *
 * ACJTAG comparator level
 */

#define BP_SATAPHY_CLOCK_LVL-STAT_ACJT_LVL      0
#define BM_SATAPHY_CLOCK_LVL-STAT_ACJT_LVL      0x0000001f

/* --- Register HW_SATAPHY_CLOCK_LVL-STAT, field LOS_LVL (RO)
 *
 * Loss of Signal Detector level
 */

#define BP_SATAPHY_CLOCK_LVL-STAT_LOS_LVL      5
#define BM_SATAPHY_CLOCK_LVL-STAT_LOS_LVL      0x000003e0

/* --- Register HW_SATAPHY_CLOCK_LVL-STAT, field TX_LVL (RO)
 *
 * Transmit level
 */

#define BP_SATAPHY_CLOCK_LVL-STAT_TX_LVL      10
#define BM_SATAPHY_CLOCK_LVL-STAT_TX_LVL      0x00007c00

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CREG_STAT - Creg Status Register (RO)
 *
 * Address: 0x0011  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of creg control I/O.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CR_READ : 1; //!< Read request
        unsigned short CR_WRITE : 1; //!< Write request
        unsigned short CR_CAP_DATA : 1; //!< Captures data request
        unsigned short CR_CAP_ADDR : 1; //!< Captures address request
        unsigned short RESERVED0 : 1; //!< Reserved
        unsigned short CR_ACK : 1; //!< Creg request acknowledgement
        unsigned short POWER_GOOD : 1; //!< Power good output
        unsigned short OP_DONE : 1; //!< Operation is complete output
        unsigned short RESERVED1 : 8; //!< Reserved
    } B;
} hw_sataphy_clock_creg_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CREG_STAT register
 */
#define HW_SATAPHY_CLOCK_CREG_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CREG_STAT           (*(volatile hw_sataphy_clock_creg_stat_t *) HW_SATAPHY_CLOCK_CREG_STAT_ADDR)
#define HW_SATAPHY_CLOCK_CREG_STAT_RD()      (HW_SATAPHY_CLOCK_CREG_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CREG_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_READ (RO)
 *
 * Read request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_READ      0
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_READ      0x00000001

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_WRITE (RO)
 *
 * Write request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_WRITE      1
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_WRITE      0x00000002

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_CAP_DATA (RO)
 *
 * Captures data request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA      2
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA      0x00000004

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_CAP_ADDR (RO)
 *
 * Captures address request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR      3
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR      0x00000008

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_ACK (RO)
 *
 * Creg request acknowledgement
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_ACK      5
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_ACK      0x00000020

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field POWER_GOOD (RO)
 *
 * Power good output
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD      6
#define BM_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD      0x00000040

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field OP_DONE (RO)
 *
 * Operation is complete output
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_OP_DONE      7
#define BM_SATAPHY_CLOCK_CREG_STAT_OP_DONE      0x00000080

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_FREW_OVRD - Frequency Override Register (RW)
 *
 * Reset value: 16'b 0100 0101 0100 0111  This register contains the override of frequency control
 * inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short PROP_CTL : 3; //!< Proportional charge pump control Proportional current = (n + 1) / 8 x full_scale
        unsigned short INT_CTL : 3; //!< Integral charge pump control Integral current = (n + 1) / 8 x full_scale
        unsigned short NCY5 : 2; //!< Divide-by-5 control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY
        unsigned short NCY : 5; //!< Divide-by-4 cycle control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY.
        unsigned short PRESCALE : 2; //!< Prescaler control:
        unsigned short OVRD : 1; //!< Enables override of all bits in this register
    } B;
} hw_sataphy_clock_frew_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_FREW_OVRD register
 */
#define HW_SATAPHY_CLOCK_FREW_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x12)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_FREW_OVRD           (*(volatile hw_sataphy_clock_frew_ovrd_t *) HW_SATAPHY_CLOCK_FREW_OVRD_ADDR)
#define HW_SATAPHY_CLOCK_FREW_OVRD_RD()      (HW_SATAPHY_CLOCK_FREW_OVRD.U)
#define HW_SATAPHY_CLOCK_FREW_OVRD_WR(v)     (HW_SATAPHY_CLOCK_FREW_OVRD.U = (v))
#define HW_SATAPHY_CLOCK_FREW_OVRD_SET(v)    (HW_SATAPHY_CLOCK_FREW_OVRD_WR(HW_SATAPHY_CLOCK_FREW_OVRD_RD() |  (v)))
#define HW_SATAPHY_CLOCK_FREW_OVRD_CLR(v)    (HW_SATAPHY_CLOCK_FREW_OVRD_WR(HW_SATAPHY_CLOCK_FREW_OVRD_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_FREW_OVRD_TOG(v)    (HW_SATAPHY_CLOCK_FREW_OVRD_WR(HW_SATAPHY_CLOCK_FREW_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_FREW_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field PROP_CTL (RW)
 *
 * Proportional charge pump control Proportional current = (n + 1) / 8 x full_scale
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL      0
#define BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL(v)   (((v) << 0) & BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_CTL field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, PROP_CTL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field INT_CTL (RW)
 *
 * Integral charge pump control Integral current = (n + 1) / 8 x full_scale
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_INT_CTL      3
#define BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_INT_CTL(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_INT_CTL(v)   (((v) << 3) & BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_CTL field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_INT_CTL(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, INT_CTL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field NCY5 (RW)
 *
 * Divide-by-5 control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_NCY5      6
#define BM_SATAPHY_CLOCK_FREW_OVRD_NCY5      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY5(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY5)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY5(v)   (((v) << 6) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NCY5 field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_NCY5(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, NCY5, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field NCY (RW)
 *
 * Divide-by-4 cycle control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY.
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_NCY      8
#define BM_SATAPHY_CLOCK_FREW_OVRD_NCY      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY(v)   (((v) << 8) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NCY field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_NCY(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, NCY, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field PRESCALE (RW)
 *
 * Prescaler control:
 *
 * Values:
 * 00 - No scaling
 * 01 - Doubles refclk frequency
 * 10 - Halves refclk frequency
 * 11 - Reserved
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_PRESCALE      13
#define BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_PRESCALE(v)   ((((reg32_t) v) << 13) & BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_PRESCALE(v)   (((v) << 13) & BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESCALE field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_PRESCALE(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, PRESCALE, v)
#endif


/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field OVRD (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_OVRD      15
#define BM_SATAPHY_CLOCK_FREW_OVRD_OVRD      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_FREW_OVRD_OVRD(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_CLOCK_FREW_OVRD_OVRD)
#else
#define BF_SATAPHY_CLOCK_FREW_OVRD_OVRD(v)   (((v) << 15) & BM_SATAPHY_CLOCK_FREW_OVRD_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD field to a new value.
#define BW_SATAPHY_CLOCK_FREW_OVRD_OVRD(v)   BF_CS1(SATAPHY_CLOCK_FREW_OVRD, OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CTL_OVRD - Control Override Register (RW)
 *
 * Reset value: 16'b 0000 1000 0101 0100  This register contains the override of various control
 * inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short USE_REFCLK_ALT : 1; //!< Uses alternate refclk
        unsigned short MPLL_CLK_OFF : 1; //!< Reference clock is off
        unsigned short MPLL_PWRON : 1; //!< MPLL power-on control
        unsigned short MPLL_SS_EN : 1; //!< Spread spectrum enable
        unsigned short CKO_ALIVE_CON : 2; //!< cko_alive mux control
        unsigned short CKO_WORD_CON : 3; //!< cko_word mux control
        unsigned short OVRD_CLK : 1; //!< Overrides clock controls (bits [8:0])
        unsigned short RTUNE_DO_TUNE : 1; //!< Manual resistor tune control
        unsigned short WIDE_XFACE : 1; //!< Wide interface control
        unsigned short VPH_IS_3P3 : 1; //!< High-voltage supply is 3.3 V
        unsigned short VP_IS_1P2 : 1; //!< Low-voltage supply is 1.2 V
        unsigned short FAST_TECH : 1; //!< Technology is fast
        unsigned short OVRD_STATIC : 1; //!< Overrides static controls (bits [14:10])
    } B;
} hw_sataphy_clock_ctl_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CTL_OVRD register
 */
#define HW_SATAPHY_CLOCK_CTL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x13)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CTL_OVRD           (*(volatile hw_sataphy_clock_ctl_ovrd_t *) HW_SATAPHY_CLOCK_CTL_OVRD_ADDR)
#define HW_SATAPHY_CLOCK_CTL_OVRD_RD()      (HW_SATAPHY_CLOCK_CTL_OVRD.U)
#define HW_SATAPHY_CLOCK_CTL_OVRD_WR(v)     (HW_SATAPHY_CLOCK_CTL_OVRD.U = (v))
#define HW_SATAPHY_CLOCK_CTL_OVRD_SET(v)    (HW_SATAPHY_CLOCK_CTL_OVRD_WR(HW_SATAPHY_CLOCK_CTL_OVRD_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CTL_OVRD_CLR(v)    (HW_SATAPHY_CLOCK_CTL_OVRD_WR(HW_SATAPHY_CLOCK_CTL_OVRD_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CTL_OVRD_TOG(v)    (HW_SATAPHY_CLOCK_CTL_OVRD_WR(HW_SATAPHY_CLOCK_CTL_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CTL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field USE_REFCLK_ALT (RW)
 *
 * Uses alternate refclk
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT      0
#define BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the USE_REFCLK_ALT field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, USE_REFCLK_ALT, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_CLK_OFF (RW)
 *
 * Reference clock is off
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF      1
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF(v)   (((v) << 1) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_CLK_OFF field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, MPLL_CLK_OFF, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_PWRON (RW)
 *
 * MPLL power-on control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON      2
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON(v)   (((v) << 2) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_PWRON field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, MPLL_PWRON, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_SS_EN (RW)
 *
 * Spread spectrum enable
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN      3
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN(v)   (((v) << 3) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_SS_EN field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, MPLL_SS_EN, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field CKO_ALIVE_CON (RW)
 *
 * cko_alive mux control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON      4
#define BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON(v)   (((v) << 4) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO_ALIVE_CON field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, CKO_ALIVE_CON, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field CKO_WORD_CON (RW)
 *
 * cko_word mux control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON      6
#define BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON(v)   (((v) << 6) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO_WORD_CON field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, CKO_WORD_CON, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field OVRD_CLK (RW)
 *
 * Overrides clock controls (bits [8:0])
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK      9
#define BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK(v)   ((((reg32_t) v) << 9) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK(v)   (((v) << 9) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_CLK field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, OVRD_CLK, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field RTUNE_DO_TUNE (RW)
 *
 * Manual resistor tune control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE      10
#define BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE(v)   (((v) << 10) & BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RTUNE_DO_TUNE field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, RTUNE_DO_TUNE, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field WIDE_XFACE (RW)
 *
 * Wide interface control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE      11
#define BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE(v)   ((((reg32_t) v) << 11) & BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE(v)   (((v) << 11) & BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WIDE_XFACE field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, WIDE_XFACE, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field VPH_IS_3P3 (RW)
 *
 * High-voltage supply is 3.3 V
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3      12
#define BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3(v)   ((((reg32_t) v) << 12) & BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3(v)   (((v) << 12) & BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VPH_IS_3P3 field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, VPH_IS_3P3, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field VP_IS_1P2 (RW)
 *
 * Low-voltage supply is 1.2 V
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2      13
#define BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2(v)   ((((reg32_t) v) << 13) & BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2(v)   (((v) << 13) & BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VP_IS_1P2 field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, VP_IS_1P2, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field FAST_TECH (RW)
 *
 * Technology is fast
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH      14
#define BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH(v)   ((((reg32_t) v) << 14) & BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH(v)   (((v) << 14) & BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_TECH field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, FAST_TECH, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field OVRD_STATIC (RW)
 *
 * Overrides static controls (bits [14:10])
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC      15
#define BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC)
#else
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC(v)   (((v) << 15) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_STATIC field to a new value.
#define BW_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC(v)   BF_CS1(SATAPHY_CLOCK_CTL_OVRD, OVRD_STATIC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_LVL_OVRD - Level Override Register (RW)
 *
 * Address: 0x0014  Reset value: 16'b 0100 0010 0001 0000  This register contains the override of
 * level control inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ACJT_LVL : 5; //!< ACJTAG comparator level
        unsigned short LOS_LVL : 5; //!< Loss of Signal Detector
        unsigned short LEVEL_TX_LVL : 5; //!< Transmit level
        unsigned short OVRD : 1; //!< Overrides all level controls
    } B;
} hw_sataphy_clock_lvl_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_LVL_OVRD register
 */
#define HW_SATAPHY_CLOCK_LVL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_LVL_OVRD           (*(volatile hw_sataphy_clock_lvl_ovrd_t *) HW_SATAPHY_CLOCK_LVL_OVRD_ADDR)
#define HW_SATAPHY_CLOCK_LVL_OVRD_RD()      (HW_SATAPHY_CLOCK_LVL_OVRD.U)
#define HW_SATAPHY_CLOCK_LVL_OVRD_WR(v)     (HW_SATAPHY_CLOCK_LVL_OVRD.U = (v))
#define HW_SATAPHY_CLOCK_LVL_OVRD_SET(v)    (HW_SATAPHY_CLOCK_LVL_OVRD_WR(HW_SATAPHY_CLOCK_LVL_OVRD_RD() |  (v)))
#define HW_SATAPHY_CLOCK_LVL_OVRD_CLR(v)    (HW_SATAPHY_CLOCK_LVL_OVRD_WR(HW_SATAPHY_CLOCK_LVL_OVRD_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_LVL_OVRD_TOG(v)    (HW_SATAPHY_CLOCK_LVL_OVRD_WR(HW_SATAPHY_CLOCK_LVL_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_LVL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field ACJT_LVL (RW)
 *
 * ACJTAG comparator level
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL      0
#define BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL)
#else
#define BF_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL(v)   (((v) << 0) & BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACJT_LVL field to a new value.
#define BW_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL(v)   BF_CS1(SATAPHY_CLOCK_LVL_OVRD, ACJT_LVL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field LOS_LVL (RW)
 *
 * Loss of Signal Detector
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL      5
#define BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL)
#else
#define BF_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL(v)   (((v) << 5) & BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOS_LVL field to a new value.
#define BW_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL(v)   BF_CS1(SATAPHY_CLOCK_LVL_OVRD, LOS_LVL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field LEVEL_TX_LVL (RW)
 *
 * Transmit level
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL      10
#define BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL      0x00007c00

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL)
#else
#define BF_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL(v)   (((v) << 10) & BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LEVEL_TX_LVL field to a new value.
#define BW_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL(v)   BF_CS1(SATAPHY_CLOCK_LVL_OVRD, LEVEL_TX_LVL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field OVRD (RW)
 *
 * Overrides all level controls
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_OVRD      15
#define BM_SATAPHY_CLOCK_LVL_OVRD_OVRD      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_LVL_OVRD_OVRD(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_CLOCK_LVL_OVRD_OVRD)
#else
#define BF_SATAPHY_CLOCK_LVL_OVRD_OVRD(v)   (((v) << 15) & BM_SATAPHY_CLOCK_LVL_OVRD_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD field to a new value.
#define BW_SATAPHY_CLOCK_LVL_OVRD_OVRD(v)   BF_CS1(SATAPHY_CLOCK_LVL_OVRD, OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CREG_OVRD - Creg Override Register (RW)
 *
 * Address: 0x0015 Reset value: 16'b xxxx xxx0 0100 0000 This register contains the override of creg
 * control I/O.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CR_READ : 1; //!< Reads request
        unsigned short CR_WRITE : 1; //!< Writes request
        unsigned short CR_CAP_DATA : 1; //!< Captures data request
        unsigned short CR_CAP_ADDR : 1; //!< Captures address request
        unsigned short OVRD_IN : 1; //!< Overrides inputs (bits [3:0])
        unsigned short CR_ACK : 1; //!< Creg request acknowledgement
        unsigned short POWER_GOOD : 1; //!< Power good output
        unsigned short OP_DONE : 1; //!< Operation is complete output
        unsigned short OVRD_OUT : 1; //!< Overrides outputs (bits [7:5])
        unsigned short RESERVED0 : 7; //!< Reserved
    } B;
} hw_sataphy_clock_creg_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CREG_OVRD register
 */
#define HW_SATAPHY_CLOCK_CREG_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CREG_OVRD           (*(volatile hw_sataphy_clock_creg_ovrd_t *) HW_SATAPHY_CLOCK_CREG_OVRD_ADDR)
#define HW_SATAPHY_CLOCK_CREG_OVRD_RD()      (HW_SATAPHY_CLOCK_CREG_OVRD.U)
#define HW_SATAPHY_CLOCK_CREG_OVRD_WR(v)     (HW_SATAPHY_CLOCK_CREG_OVRD.U = (v))
#define HW_SATAPHY_CLOCK_CREG_OVRD_SET(v)    (HW_SATAPHY_CLOCK_CREG_OVRD_WR(HW_SATAPHY_CLOCK_CREG_OVRD_RD() |  (v)))
#define HW_SATAPHY_CLOCK_CREG_OVRD_CLR(v)    (HW_SATAPHY_CLOCK_CREG_OVRD_WR(HW_SATAPHY_CLOCK_CREG_OVRD_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_CREG_OVRD_TOG(v)    (HW_SATAPHY_CLOCK_CREG_OVRD_WR(HW_SATAPHY_CLOCK_CREG_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CREG_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_READ (RW)
 *
 * Reads request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_READ      0
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_READ(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_READ(v)   (((v) << 0) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_READ field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_CR_READ(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, CR_READ, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_WRITE (RW)
 *
 * Writes request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE      1
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE(v)   (((v) << 1) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_WRITE field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, CR_WRITE, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_CAP_DATA (RW)
 *
 * Captures data request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA      2
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA(v)   (((v) << 2) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_CAP_DATA field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, CR_CAP_DATA, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_CAP_ADDR (RW)
 *
 * Captures address request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR      3
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR(v)   (((v) << 3) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_CAP_ADDR field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, CR_CAP_ADDR, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OVRD_IN (RW)
 *
 * Overrides inputs (bits [3:0])
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN      4
#define BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN(v)   (((v) << 4) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_IN field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, OVRD_IN, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_ACK (RW)
 *
 * Creg request acknowledgement
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_ACK      5
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_ACK(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_ACK(v)   (((v) << 5) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_ACK field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_CR_ACK(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, CR_ACK, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field POWER_GOOD (RW)
 *
 * Power good output
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD      6
#define BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD(v)   ((((reg32_t) v) << 6) & BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD(v)   (((v) << 6) & BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_GOOD field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, POWER_GOOD, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OP_DONE (RW)
 *
 * Operation is complete output
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OP_DONE      7
#define BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_OP_DONE(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_OP_DONE(v)   (((v) << 7) & BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OP_DONE field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_OP_DONE(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, OP_DONE, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OVRD_OUT (RW)
 *
 * Overrides outputs (bits [7:5])
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT      8
#define BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT(v)   ((((reg32_t) v) << 8) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT)
#else
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT(v)   (((v) << 8) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_OUT field to a new value.
#define BW_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT(v)   BF_CS1(SATAPHY_CLOCK_CREG_OVRD, OVRD_OUT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_MPLL_CTL - MPLL Control Register (RW)
 *
 * Reset value: 16'b xxxx xx00 0000 0000  This register contains MPLL controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short CLKDRV_ANA : 1; //!< Value for analog clock drivers
        unsigned short CLKDRV_DIG : 1; //!< Value for digital clock drivers
        unsigned short OVRD_CLKDRV : 1; //!< Overrides clock driver controls
        unsigned short DIS_PARA_CREG : 1; //!< Disables parallel creg interface
        unsigned short REFCLK_DELAY : 1; //!< Delays refclk output of prescaler
        unsigned short DTB_SEL0 : 5; //!< Selects wire to drive onto DTB bit 0: All other bits: Disabled
        unsigned short DTB_SEL1 : 5; //!< Selects wire to drive onto DTB bit 1: All other bits: Disabled
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_clock_mpll_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_MPLL_CTL register
 */
#define HW_SATAPHY_CLOCK_MPLL_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x16)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_MPLL_CTL           (*(volatile hw_sataphy_clock_mpll_ctl_t *) HW_SATAPHY_CLOCK_MPLL_CTL_ADDR)
#define HW_SATAPHY_CLOCK_MPLL_CTL_RD()      (HW_SATAPHY_CLOCK_MPLL_CTL.U)
#define HW_SATAPHY_CLOCK_MPLL_CTL_WR(v)     (HW_SATAPHY_CLOCK_MPLL_CTL.U = (v))
#define HW_SATAPHY_CLOCK_MPLL_CTL_SET(v)    (HW_SATAPHY_CLOCK_MPLL_CTL_WR(HW_SATAPHY_CLOCK_MPLL_CTL_RD() |  (v)))
#define HW_SATAPHY_CLOCK_MPLL_CTL_CLR(v)    (HW_SATAPHY_CLOCK_MPLL_CTL_WR(HW_SATAPHY_CLOCK_MPLL_CTL_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_MPLL_CTL_TOG(v)    (HW_SATAPHY_CLOCK_MPLL_CTL_WR(HW_SATAPHY_CLOCK_MPLL_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_MPLL_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field CLKDRV_ANA (RW)
 *
 * Value for analog clock drivers
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA      0
#define BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA(v)   (((v) << 0) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKDRV_ANA field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, CLKDRV_ANA, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field CLKDRV_DIG (RW)
 *
 * Value for digital clock drivers
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG      1
#define BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG(v)   (((v) << 1) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKDRV_DIG field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, CLKDRV_DIG, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field OVRD_CLKDRV (RW)
 *
 * Overrides clock driver controls
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV      2
#define BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV(v)   (((v) << 2) & BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_CLKDRV field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, OVRD_CLKDRV, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DIS_PARA_CREG (RW)
 *
 * Disables parallel creg interface
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG      3
#define BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG(v)   ((((reg32_t) v) << 3) & BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG(v)   (((v) << 3) & BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS_PARA_CREG field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, DIS_PARA_CREG, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field REFCLK_DELAY (RW)
 *
 * Delays refclk output of prescaler
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY      4
#define BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY(v)   ((((reg32_t) v) << 4) & BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY(v)   (((v) << 4) & BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFCLK_DELAY field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, REFCLK_DELAY, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DTB_SEL0 (RW)
 *
 * Selects wire to drive onto DTB bit 0: All other bits: Disabled
 *
 * Values:
 * 00000 - Disabled
 * 00001 - mpll_gear_shift
 * 00010 - mpll_reset
 * 00011 - mpll_pwron (at analog boundary)
 * 00100 - reset_n
 * 00101 - cr_ack
 * 00110 - power_good
 * 00111 - op_done
 * 01000 - cr_read
 * 01001 - cr_write
 * 01010 - cr_cap_data
 * 01011 - cr_cap_addr
 * 01100 - rtune_do_tune
 * 01101 - cko_alive_con[0]
 * 01110 - cko_alive_con[1]
 * 01111 - cko_word_con[0]
 * 10000 - cko_word_con[1]
 * 10001 - cko_word_con[2]
 * 10010 - mpll_pwron (ASIC control)
 * 10011 - mpll_ck_off
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0      5
#define BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0(v)   ((((reg32_t) v) << 5) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0(v)   (((v) << 5) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL0 field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, DTB_SEL0, v)
#endif


/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DTB_SEL1 (RW)
 *
 * Selects wire to drive onto DTB bit 1: All other bits: Disabled
 *
 * Values:
 * 00000 - Disabled
 * 00001 - mpll_gear_shift
 * 00010 - mpll_reset
 * 00011 - mpll_pwron (at analog boundary)
 * 00100 - reset_n
 * 00101 - cr_ack
 * 00110 - power_good
 * 00111 - op_done
 * 01000 - cr_read
 * 01001 - cr_write
 * 01010 - cr_cap_data
 * 01011 - cr_cap_addr
 * 01100 - rtune_do_tune
 * 01101 - cko_alive_con[0]
 * 01110 - cko_alive_con[1]
 * 01111 - cko_word_con[0]
 * 10000 - cko_word_con[1]
 * 10001 - cko_word_con[2]
 * 10010 - mpll_pwron (ASIC control)
 * 10011 - mpll_ck_off
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1      10
#define BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1      0x00007c00

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1)
#else
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1(v)   (((v) << 10) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DTB_SEL1 field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1(v)   BF_CS1(SATAPHY_CLOCK_MPLL_CTL, DTB_SEL1, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_MPLL_TEST - MPLL Test Register (RW)
 *
 * Address: 0x0017  Reset value: 16'b 0000 0000 0000 0000  This register contains MPLL test
 * controls.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short ATB_SENSE : 1; //!< Hooks up ATB sense lines
        unsigned short MEAS_GD : 1; //!< Measures Ground For correct measurements, this field must be set when various meas_iv bits are set.
        unsigned short MEAS_IV : 11; //!< Measures various MPLL controls: Bit 2: Measures dcc_vcntrl_p on atb_sense_p Bit 3: Measures dcc_vcntrl_m on atb_sense_m Bit 4: Measures 1-V supply voltage on atb_sense_m Bit 5: Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m Bit 6: Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m Bit 7: Measures clock tree supply voltage on atb_sense_p; gd on atb_sense_m Bit 8: Measures vp16 on atb_sense_p; gd on atb_sense_m Bit 9: Measures vref on atb_sense_p; gd on atb_sense_m Bit 10: Measures vcntrl on atb_sense_m Bit 11: Measures copy of bias current in oscillator on atb_force_m Bit 12: Enables phase linearity testing of phase interpolator and VCO
        unsigned short RESET_VAL : 1; //!< Value to override for mpll_reset
        unsigned short GEARSHIFT_VAL : 1; //!< Value to override for mpll_gearshift
        unsigned short OVRD_CTL : 1; //!< Overrides MPLL reset and gearshift controls
    } B;
} hw_sataphy_clock_mpll_test_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_MPLL_TEST register
 */
#define HW_SATAPHY_CLOCK_MPLL_TEST_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_MPLL_TEST           (*(volatile hw_sataphy_clock_mpll_test_t *) HW_SATAPHY_CLOCK_MPLL_TEST_ADDR)
#define HW_SATAPHY_CLOCK_MPLL_TEST_RD()      (HW_SATAPHY_CLOCK_MPLL_TEST.U)
#define HW_SATAPHY_CLOCK_MPLL_TEST_WR(v)     (HW_SATAPHY_CLOCK_MPLL_TEST.U = (v))
#define HW_SATAPHY_CLOCK_MPLL_TEST_SET(v)    (HW_SATAPHY_CLOCK_MPLL_TEST_WR(HW_SATAPHY_CLOCK_MPLL_TEST_RD() |  (v)))
#define HW_SATAPHY_CLOCK_MPLL_TEST_CLR(v)    (HW_SATAPHY_CLOCK_MPLL_TEST_WR(HW_SATAPHY_CLOCK_MPLL_TEST_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_MPLL_TEST_TOG(v)    (HW_SATAPHY_CLOCK_MPLL_TEST_WR(HW_SATAPHY_CLOCK_MPLL_TEST_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_MPLL_TEST bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field ATB_SENSE (RW)
 *
 * Hooks up ATB sense lines
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE      0
#define BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE(v)   (((v) << 0) & BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATB_SENSE field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, ATB_SENSE, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field MEAS_GD (RW)
 *
 * Measures Ground For correct measurements, this field must be set when various meas_iv bits are
 * set.
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD      1
#define BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD(v)   ((((reg32_t) v) << 1) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD(v)   (((v) << 1) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_GD field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, MEAS_GD, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field MEAS_IV (RW)
 *
 * Measures various MPLL controls: Bit 2: Measures dcc_vcntrl_p on atb_sense_p Bit 3: Measures
 * dcc_vcntrl_m on atb_sense_m Bit 4: Measures 1-V supply voltage on atb_sense_m Bit 5: Measures
 * vp_cp voltage on atb_sense_p; gd on atb_sense_m Bit 6: Measures VCO supply voltage on
 * atb_sense_p; gd on atb_sense_m Bit 7: Measures clock tree supply voltage on atb_sense_p; gd on
 * atb_sense_m Bit 8: Measures vp16 on atb_sense_p; gd on atb_sense_m Bit 9: Measures vref on
 * atb_sense_p; gd on atb_sense_m Bit 10: Measures vcntrl on atb_sense_m Bit 11: Measures copy of
 * bias current in oscillator on atb_force_m Bit 12: Enables phase linearity testing of phase
 * interpolator and VCO
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV      2
#define BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV      0x00001ffc

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV(v)   (((v) << 2) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MEAS_IV field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, MEAS_IV, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field RESET_VAL (RW)
 *
 * Value to override for mpll_reset
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL      13
#define BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL(v)   ((((reg32_t) v) << 13) & BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL(v)   (((v) << 13) & BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET_VAL field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, RESET_VAL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field GEARSHIFT_VAL (RW)
 *
 * Value to override for mpll_gearshift
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL      14
#define BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL(v)   ((((reg32_t) v) << 14) & BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL(v)   (((v) << 14) & BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEARSHIFT_VAL field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, GEARSHIFT_VAL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field OVRD_CTL (RW)
 *
 * Overrides MPLL reset and gearshift controls
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL      15
#define BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL(v)   ((((reg32_t) v) << 15) & BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL)
#else
#define BF_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL(v)   (((v) << 15) & BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OVRD_CTL field to a new value.
#define BW_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL(v)   BF_CS1(SATAPHY_CLOCK_MPLL_TEST, OVRD_CTL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SS_FREQ - Spread Spectrum Frequency Register (RW)
 *
 * Address: 0x0018  Reset value: 16'b x011 0011 0010 1111  This register contains the frequency
 * register override, peak frequency value, and frequency counter step values.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short FREQ_CNT_INIT : 7; //!< Frequency counter step value. Note: This value is independent of the freq_pk value.
        unsigned short FREQ_PK : 7; //!< Peak frequency value
        unsigned short FREQ_REG_OVRD : 1; //!< Override control, indicating that overridden value is active
        unsigned short RESERVED0 : 1; //!< Reserved
    } B;
} hw_sataphy_clock_ss_freq_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SS_FREQ register
 */
#define HW_SATAPHY_CLOCK_SS_FREQ_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SS_FREQ           (*(volatile hw_sataphy_clock_ss_freq_t *) HW_SATAPHY_CLOCK_SS_FREQ_ADDR)
#define HW_SATAPHY_CLOCK_SS_FREQ_RD()      (HW_SATAPHY_CLOCK_SS_FREQ.U)
#define HW_SATAPHY_CLOCK_SS_FREQ_WR(v)     (HW_SATAPHY_CLOCK_SS_FREQ.U = (v))
#define HW_SATAPHY_CLOCK_SS_FREQ_SET(v)    (HW_SATAPHY_CLOCK_SS_FREQ_WR(HW_SATAPHY_CLOCK_SS_FREQ_RD() |  (v)))
#define HW_SATAPHY_CLOCK_SS_FREQ_CLR(v)    (HW_SATAPHY_CLOCK_SS_FREQ_WR(HW_SATAPHY_CLOCK_SS_FREQ_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_SS_FREQ_TOG(v)    (HW_SATAPHY_CLOCK_SS_FREQ_WR(HW_SATAPHY_CLOCK_SS_FREQ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SS_FREQ bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_CNT_INIT (RW)
 *
 * Frequency counter step value. Note: This value is independent of the freq_pk value.
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT      0
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT)
#else
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT(v)   (((v) << 0) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_CNT_INIT field to a new value.
#define BW_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT(v)   BF_CS1(SATAPHY_CLOCK_SS_FREQ, FREQ_CNT_INIT, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_PK (RW)
 *
 * Peak frequency value
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_PK      7
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK      0x00003f80

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_PK(v)   ((((reg32_t) v) << 7) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK)
#else
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_PK(v)   (((v) << 7) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_PK field to a new value.
#define BW_SATAPHY_CLOCK_SS_FREQ_FREQ_PK(v)   BF_CS1(SATAPHY_CLOCK_SS_FREQ, FREQ_PK, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_REG_OVRD (RW)
 *
 * Override control, indicating that overridden value is active
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD      14
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD(v)   ((((reg32_t) v) << 14) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD)
#else
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD(v)   (((v) << 14) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FREQ_REG_OVRD field to a new value.
#define BW_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD(v)   BF_CS1(SATAPHY_CLOCK_SS_FREQ, FREQ_REG_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SEL_STAT - Clock Select Status Register (RO)
 *
 * Address: 0x0019  Reset value: 16'bxxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of the ref_clk_sel and mpll_ss_sel inputs.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MPLL_SS_SEL : 2; //!< MPLL spread spectrum select input
        unsigned short REF_CLK_SEL : 8; //!< Reference clock select input
        unsigned short RESERVED0 : 6; //!< Reserved
    } B;
} hw_sataphy_clock_sel_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SEL_STAT register
 */
#define HW_SATAPHY_CLOCK_SEL_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SEL_STAT           (*(volatile hw_sataphy_clock_sel_stat_t *) HW_SATAPHY_CLOCK_SEL_STAT_ADDR)
#define HW_SATAPHY_CLOCK_SEL_STAT_RD()      (HW_SATAPHY_CLOCK_SEL_STAT.U)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SEL_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SEL_STAT, field MPLL_SS_SEL (RO)
 *
 * MPLL spread spectrum select input
 */

#define BP_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL      0
#define BM_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL      0x00000003

/* --- Register HW_SATAPHY_CLOCK_SEL_STAT, field REF_CLK_SEL (RO)
 *
 * Reference clock select input
 */

#define BP_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL      2
#define BM_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL      0x000003fc

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SEL_OVRD - Clock Select Override Register (RW)
 *
 * Address: 0x001A  Reset value: 16'b0000 0000 0000 0000  This register contains the clock select
 * override, the ref_clk_sel override value, and the mpll_ss_sel override value.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short MPLL_SS_SEL : 2; //!< MPLL spread spectrum select
        unsigned short REF_CLK_SEL : 8; //!< Reference clock select
        unsigned short CLK_SEL_OVRD : 1; //!< Override control, indicating that the overridden value is active
        unsigned short RESERVED0 : 5; //!< Reserved
    } B;
} hw_sataphy_clock_sel_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SEL_OVRD register
 */
#define HW_SATAPHY_CLOCK_SEL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SEL_OVRD           (*(volatile hw_sataphy_clock_sel_ovrd_t *) HW_SATAPHY_CLOCK_SEL_OVRD_ADDR)
#define HW_SATAPHY_CLOCK_SEL_OVRD_RD()      (HW_SATAPHY_CLOCK_SEL_OVRD.U)
#define HW_SATAPHY_CLOCK_SEL_OVRD_WR(v)     (HW_SATAPHY_CLOCK_SEL_OVRD.U = (v))
#define HW_SATAPHY_CLOCK_SEL_OVRD_SET(v)    (HW_SATAPHY_CLOCK_SEL_OVRD_WR(HW_SATAPHY_CLOCK_SEL_OVRD_RD() |  (v)))
#define HW_SATAPHY_CLOCK_SEL_OVRD_CLR(v)    (HW_SATAPHY_CLOCK_SEL_OVRD_WR(HW_SATAPHY_CLOCK_SEL_OVRD_RD() & ~(v)))
#define HW_SATAPHY_CLOCK_SEL_OVRD_TOG(v)    (HW_SATAPHY_CLOCK_SEL_OVRD_WR(HW_SATAPHY_CLOCK_SEL_OVRD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SEL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field MPLL_SS_SEL (RW)
 *
 * MPLL spread spectrum select
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL      0
#define BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL)
#else
#define BF_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL(v)   (((v) << 0) & BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MPLL_SS_SEL field to a new value.
#define BW_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL(v)   BF_CS1(SATAPHY_CLOCK_SEL_OVRD, MPLL_SS_SEL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field REF_CLK_SEL (RW)
 *
 * Reference clock select
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL      2
#define BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL      0x000003fc

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL(v)   ((((reg32_t) v) << 2) & BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL)
#else
#define BF_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL(v)   (((v) << 2) & BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REF_CLK_SEL field to a new value.
#define BW_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL(v)   BF_CS1(SATAPHY_CLOCK_SEL_OVRD, REF_CLK_SEL, v)
#endif

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field CLK_SEL_OVRD (RW)
 *
 * Override control, indicating that the overridden value is active
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD      10
#define BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD(v)   ((((reg32_t) v) << 10) & BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD)
#else
#define BF_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD(v)   (((v) << 10) & BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_SEL_OVRD field to a new value.
#define BW_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD(v)   BF_CS1(SATAPHY_CLOCK_SEL_OVRD, CLK_SEL_OVRD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_RESET - Reset Register (WO)
 *
 * Address: 0x7F3F  Reset value: 16'b xxxx xxxx xxxx xxx0  This register is a write-only register
 * (not a real register) that resets the SATA2 PHY.  Upon writing the PHY reset bit in the reset
 * register, the internal PHY reset is active immediately. Since the reset also affects the control
 * register state machine, there will not be an acknowledgement of the write; that is, cr_ack will
 * not be asserted.  Diagnostic code should treat the lack of an acknowledgment of the write as a
 * successful write; alternatively, it should treat the PHY acknowledging a write of the reset as a
 * write failure . This is the opposite expectation of all other registers, where the lack is a
 * failure and the acknowledge is successful.  It is sufficient to wait 20 ref_clock cycles in order
 * to determine that the acknowledgement has not occurred.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short RESET : 1; //!< Writing a 1 to this field resets the SATA2 PHY.
        unsigned short RESERVED0 : 15; //!< Reserved
    } B;
} hw_sataphy_clock_reset_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_RESET register
 */
#define HW_SATAPHY_CLOCK_RESET_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x7f3f)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_RESET           (*(volatile hw_sataphy_clock_reset_t *) HW_SATAPHY_CLOCK_RESET_ADDR)
#define HW_SATAPHY_CLOCK_RESET_WR(v)     (HW_SATAPHY_CLOCK_RESET.U = (v))
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_RESET bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_RESET, field RESET (WO)
 *
 * Writing a 1 to this field resets the SATA2 PHY.
 */

#define BP_SATAPHY_CLOCK_RESET_RESET      0
#define BM_SATAPHY_CLOCK_RESET_RESET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SATAPHY_CLOCK_RESET_RESET(v)   ((((reg32_t) v) << 0) & BM_SATAPHY_CLOCK_RESET_RESET)
#else
#define BF_SATAPHY_CLOCK_RESET_RESET(v)   (((v) << 0) & BM_SATAPHY_CLOCK_RESET_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_SATAPHY_CLOCK_RESET_RESET(v)   BF_CS1(SATAPHY_CLOCK_RESET, RESET, v)
#endif


/*!
 * @brief All SATAPHY_CLOCK module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg8_t _reserved0;
    volatile hw_sataphy_clock_crcmp_lt_limit_t CRCMP_LT_LIMIT; //!< Creg Compare Upper Limit Register
    volatile hw_sataphy_clock_crcmp_gt_limit_t CRCMP_GT_LIMIT; //!< Creg Compare Lower Limit Register
    volatile hw_sataphy_clock_crcmp_mask_t CRCMP_MASK; //!< Creg Compare Mask Register
    volatile hw_sataphy_clock_crcmp_ctl_t CRCMP_CTL; //!< Creg Compare Control Register
    volatile hw_sataphy_clock_crcmp_stat_t CRCMP_STAT; //!< Creg Compare Status Register
    volatile hw_sataphy_clock_scope_samples_t SCOPE_SAMPLES; //!< Scope Sample Count Register
    volatile hw_sataphy_clock_scope_count_t SCOPE_COUNT; //!< Scope Count Result Register
    volatile hw_sataphy_clock_dac_ctl_t DAC_CTL; //!< DAC Control Register
    volatile hw_sataphy_clock_rtune_ctl_t RTUNE_CTL; //!< Resistor Tuning Control Register
    volatile hw_sataphy_clock_adc_out_t ADC_OUT; //!< ADC Output Register
    volatile hw_sataphy_clock_ss_phase_t SS_PHASE; //!< Spread Spectrum Phase Register
    volatile hw_sataphy_clock_chip_id_hi_t CHIP_ID_HI; //!< JTAG Chip ID (High Bits) Register
    volatile hw_sataphy_clock_chip_id_low_t CHIP_ID_LOW; //!< JTAG Chip ID (Low Bits) Register
    volatile hw_sataphy_clock_freq_stat_t FREQ_STAT; //!< Frequency Status Register
    volatile hw_sataphy_clock_ctl_stat_t CTL_STAT; //!< Control Status Register
    volatile hw_sataphy_clock_lvl-stat_t LVL-STAT; //!< Level Status Register
    volatile hw_sataphy_clock_creg_stat_t CREG_STAT; //!< Creg Status Register
    volatile hw_sataphy_clock_frew_ovrd_t FREW_OVRD; //!< Frequency Override Register
    volatile hw_sataphy_clock_ctl_ovrd_t CTL_OVRD; //!< Control Override Register
    volatile hw_sataphy_clock_lvl_ovrd_t LVL_OVRD; //!< Level Override Register
    volatile hw_sataphy_clock_creg_ovrd_t CREG_OVRD; //!< Creg Override Register
    volatile hw_sataphy_clock_mpll_ctl_t MPLL_CTL; //!< MPLL Control Register
    volatile hw_sataphy_clock_mpll_test_t MPLL_TEST; //!< MPLL Test Register
    volatile hw_sataphy_clock_ss_freq_t SS_FREQ; //!< Spread Spectrum Frequency Register
    volatile hw_sataphy_clock_sel_stat_t SEL_STAT; //!< Clock Select Status Register
    volatile hw_sataphy_clock_sel_ovrd_t SEL_OVRD; //!< Clock Select Override Register
    reg16_t _reserved1[16261];
    volatile hw_sataphy_clock_reset_t RESET; //!< Reset Register
} hw_sataphy_clock_t
#endif

//! @brief Macro to access all SATAPHY_CLOCK registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SATAPHY_CLOCK(0)</code>.
#define HW_SATAPHY_CLOCK     (*(volatile hw_sataphy_clock_t *) REGS_SATAPHY_CLOCK_BASE)


#endif // _SATAPHY_CLOCK_H
