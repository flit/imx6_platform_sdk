/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PMU_H
#define _PMU_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_PMU_REG_1P1 - Regulator 1P1 Register
 * - HW_PMU_REG_3P0 - Regulator 3P0 Register
 * - HW_PMU_REG_2P5 - Regulator 2P5 Register
 * - HW_PMU_REG_CORE - Digital Regulator Core Register
 * - HW_PMU_MISC0 - Miscellaneous Register 0
 * - HW_PMU_REG_MISC1 - Miscellaneous Register 1
 * - HW_PMU_REG_MISC1_SET - Miscellaneous Register 1 _SET
 * - HW_PMU_REG_MISC1_CLR - Miscellaneous Register 1 _CLR
 * - HW_PMU_REG_MISC1_TOG - Miscellaneous Register 1 _TOG
 * - HW_PMU_REG_MISC2 - Miscellaneous Register 2
 *
 * hw_pmu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PMU_BASE
#define REGS_PMU_BASE (0x020c8000) //!< Base address for PMU.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_1P1 - Regulator 1P1 Register (RW)
 *
 * This register defines the control and status bits for the 1.1V regulator. This regulator is
 * designed to power the digital portions of the analog cells.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE_LINREG : 1; //!< Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< Control bit to enable the current-limit circuitry in the regulator.
        unsigned ENABLE_PULLDOWN : 1; //!< Control bit to enable the pull-down circuitry in the regulator
        unsigned BO_OFFSET : 3; //!< Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned OUTPUT_TRG : 5; //!< Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned BO_VDD1P1 : 1; //!< Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD1P1 : 1; //!< Status bit that signals when the regulator output is ok.
        unsigned RESERVED2 : 14; //!< Reserved.
    } B;
} hw_pmu_reg_1p1_t;
#endif

/*
 * constants & macros for entire PMU_REG_1P1 register
 */
#define HW_PMU_REG_1P1_ADDR      (REGS_PMU_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_1P1           (*(volatile hw_pmu_reg_1p1_t *) HW_PMU_REG_1P1_ADDR)
#define HW_PMU_REG_1P1_RD()      (HW_PMU_REG_1P1.U)
#define HW_PMU_REG_1P1_WR(v)     (HW_PMU_REG_1P1.U = (v))
#define HW_PMU_REG_1P1_SET(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() |  (v)))
#define HW_PMU_REG_1P1_CLR(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() & ~(v)))
#define HW_PMU_REG_1P1_TOG(v)    (HW_PMU_REG_1P1_WR(HW_PMU_REG_1P1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_1P1 bitfields
 */

/* --- Register HW_PMU_REG_1P1, field ENABLE_LINREG (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_1P1_ENABLE_LINREG      0
#define BM_PMU_REG_1P1_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_1P1_ENABLE_LINREG)
#else
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_1P1_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_1P1_ENABLE_LINREG(v)   BF_CS1(PMU_REG_1P1, ENABLE_LINREG, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_BO (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_1P1_ENABLE_BO      1
#define BM_PMU_REG_1P1_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_1P1_ENABLE_BO)
#else
#define BF_PMU_REG_1P1_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_1P1_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_1P1_ENABLE_BO(v)   BF_CS1(PMU_REG_1P1, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_ILIMIT (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_1P1_ENABLE_ILIMIT      2
#define BM_PMU_REG_1P1_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_1P1_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_1P1, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_PULLDOWN (RW)
 *
 * Control bit to enable the pull-down circuitry in the regulator
 */

#define BP_PMU_REG_1P1_ENABLE_PULLDOWN      3
#define BM_PMU_REG_1P1_ENABLE_PULLDOWN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << 3) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#else
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   (((v) << 3) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PULLDOWN field to a new value.
#define BW_PMU_REG_1P1_ENABLE_PULLDOWN(v)   BF_CS1(PMU_REG_1P1, ENABLE_PULLDOWN, v)
#endif

/* --- Register HW_PMU_REG_1P1, field BO_OFFSET (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_1P1_BO_OFFSET      4
#define BM_PMU_REG_1P1_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_1P1_BO_OFFSET)
#else
#define BF_PMU_REG_1P1_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_1P1_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_1P1_BO_OFFSET(v)   BF_CS1(PMU_REG_1P1, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_1P1, field OUTPUT_TRG (RW)
 *
 * Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip
 * functionality at the extremes of the programming range.
 *
 * Values:
 * 0100 - 0.8V
 * 1010 - 1.1V
 * 1011 - 1.375V
 * 1100 - Burn-in voltage
 * 1101 - Output trig 0x3
 */

#define BP_PMU_REG_1P1_OUTPUT_TRG      8
#define BM_PMU_REG_1P1_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_1P1_OUTPUT_TRG)
#else
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_1P1_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_1P1_OUTPUT_TRG(v)   BF_CS1(PMU_REG_1P1, OUTPUT_TRG, v)
#endif


/* --- Register HW_PMU_REG_1P1, field BO_VDD1P1 (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_1P1_BO_VDD1P1      16
#define BM_PMU_REG_1P1_BO_VDD1P1      0x00010000

/* --- Register HW_PMU_REG_1P1, field OK_VDD1P1 (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_1P1_OK_VDD1P1      17
#define BM_PMU_REG_1P1_OK_VDD1P1      0x00020000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_3P0 - Regulator 3P0 Register (RW)
 *
 * This register defines the control and status bits for the 3.0V regulator powered by the host USB
 * VBUS pin.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE_LINREG : 1; //!< Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< Control bit to enable the current-limit circuitry in the regulator.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned BO_OFFSET : 3; //!< Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned REG_3P0_VBUS_SEL : 1; //!< Reserved.
        unsigned OUTPUT_TRG : 5; //!< Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned BO_VDD3P0 : 1; //!< Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD3P0 : 1; //!< Status bit that signals when the regulator output is ok.
        unsigned RESERVED2 : 14; //!< Reserved.
    } B;
} hw_pmu_reg_3p0_t;
#endif

/*
 * constants & macros for entire PMU_REG_3P0 register
 */
#define HW_PMU_REG_3P0_ADDR      (REGS_PMU_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_3P0           (*(volatile hw_pmu_reg_3p0_t *) HW_PMU_REG_3P0_ADDR)
#define HW_PMU_REG_3P0_RD()      (HW_PMU_REG_3P0.U)
#define HW_PMU_REG_3P0_WR(v)     (HW_PMU_REG_3P0.U = (v))
#define HW_PMU_REG_3P0_SET(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() |  (v)))
#define HW_PMU_REG_3P0_CLR(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() & ~(v)))
#define HW_PMU_REG_3P0_TOG(v)    (HW_PMU_REG_3P0_WR(HW_PMU_REG_3P0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_3P0 bitfields
 */

/* --- Register HW_PMU_REG_3P0, field ENABLE_LINREG (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_3P0_ENABLE_LINREG      0
#define BM_PMU_REG_3P0_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_3P0_ENABLE_LINREG)
#else
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_3P0_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_3P0_ENABLE_LINREG(v)   BF_CS1(PMU_REG_3P0, ENABLE_LINREG, v)
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_BO (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_3P0_ENABLE_BO      1
#define BM_PMU_REG_3P0_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_3P0_ENABLE_BO)
#else
#define BF_PMU_REG_3P0_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_3P0_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_3P0_ENABLE_BO(v)   BF_CS1(PMU_REG_3P0, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_ILIMIT (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_3P0_ENABLE_ILIMIT      2
#define BM_PMU_REG_3P0_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_3P0_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_3P0, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_3P0, field BO_OFFSET (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_3P0_BO_OFFSET      4
#define BM_PMU_REG_3P0_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_3P0_BO_OFFSET)
#else
#define BF_PMU_REG_3P0_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_3P0_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_3P0_BO_OFFSET(v)   BF_CS1(PMU_REG_3P0, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_3P0, field REG_3P0_VBUS_SEL (RW)
 *
 * Reserved.
 *
 * Values:
 * 0 - Utilize host power
 * 1 - Utilize OTG power
 */

#define BP_PMU_REG_3P0_REG_3P0_VBUS_SEL      7
#define BM_PMU_REG_3P0_REG_3P0_VBUS_SEL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   ((((reg32_t) v) << 7) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#else
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   (((v) << 7) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG_3P0_VBUS_SEL field to a new value.
#define BW_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   BF_CS1(PMU_REG_3P0, REG_3P0_VBUS_SEL, v)
#endif


/* --- Register HW_PMU_REG_3P0, field OUTPUT_TRG (RW)
 *
 * Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip
 * functionality at the extremes of the programming range.
 *
 * Values:
 * 0000 - 2.625V
 * 0111 - 3.000V
 * 1111 - 3.400V
 */

#define BP_PMU_REG_3P0_OUTPUT_TRG      8
#define BM_PMU_REG_3P0_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_3P0_OUTPUT_TRG)
#else
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_3P0_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_3P0_OUTPUT_TRG(v)   BF_CS1(PMU_REG_3P0, OUTPUT_TRG, v)
#endif


/* --- Register HW_PMU_REG_3P0, field BO_VDD3P0 (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_3P0_BO_VDD3P0      16
#define BM_PMU_REG_3P0_BO_VDD3P0      0x00010000

/* --- Register HW_PMU_REG_3P0, field OK_VDD3P0 (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_3P0_OK_VDD3P0      17
#define BM_PMU_REG_3P0_OK_VDD3P0      0x00020000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_2P5 - Regulator 2P5 Register (RW)
 *
 * This register defines the control and status bits for the 2.5V regulator.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE_LINREG : 1; //!< Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< Control bit to enable the current-limit circuitry in the regulator.
        unsigned ENABLE_PULLDOWN : 1; //!< Control bit to enable the pull-down circuitry in the regulator
        unsigned BO_OFFSET : 3; //!< Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned OUTPUT_TRG : 5; //!< Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< Reserved.
        unsigned BO_VDD2P5 : 1; //!< Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD2P5 : 1; //!< Status bit that signals when the regulator output is ok.
        unsigned ENABLE_WEAK_LINREG : 1; //!< Enables the weak 2p5 regulator. This regulator is used when the main 2p5 regulator is disabled to keep the 2.5V output roughly at 2.5V. Depends directly on the value of VDDIO.
        unsigned RESERVED2 : 14; //!< Reserved.
    } B;
} hw_pmu_reg_2p5_t;
#endif

/*
 * constants & macros for entire PMU_REG_2P5 register
 */
#define HW_PMU_REG_2P5_ADDR      (REGS_PMU_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_2P5           (*(volatile hw_pmu_reg_2p5_t *) HW_PMU_REG_2P5_ADDR)
#define HW_PMU_REG_2P5_RD()      (HW_PMU_REG_2P5.U)
#define HW_PMU_REG_2P5_WR(v)     (HW_PMU_REG_2P5.U = (v))
#define HW_PMU_REG_2P5_SET(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() |  (v)))
#define HW_PMU_REG_2P5_CLR(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() & ~(v)))
#define HW_PMU_REG_2P5_TOG(v)    (HW_PMU_REG_2P5_WR(HW_PMU_REG_2P5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_2P5 bitfields
 */

/* --- Register HW_PMU_REG_2P5, field ENABLE_LINREG (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_2P5_ENABLE_LINREG      0
#define BM_PMU_REG_2P5_ENABLE_LINREG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_2P5_ENABLE_LINREG)
#else
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   (((v) << 0) & BM_PMU_REG_2P5_ENABLE_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_2P5_ENABLE_LINREG(v)   BF_CS1(PMU_REG_2P5, ENABLE_LINREG, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_BO (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_2P5_ENABLE_BO      1
#define BM_PMU_REG_2P5_ENABLE_BO      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_BO(v)   ((((reg32_t) v) << 1) & BM_PMU_REG_2P5_ENABLE_BO)
#else
#define BF_PMU_REG_2P5_ENABLE_BO(v)   (((v) << 1) & BM_PMU_REG_2P5_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_2P5_ENABLE_BO(v)   BF_CS1(PMU_REG_2P5, ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_ILIMIT (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_2P5_ENABLE_ILIMIT      2
#define BM_PMU_REG_2P5_ENABLE_ILIMIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   ((((reg32_t) v) << 2) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#else
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   (((v) << 2) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_2P5_ENABLE_ILIMIT(v)   BF_CS1(PMU_REG_2P5, ENABLE_ILIMIT, v)
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_PULLDOWN (RW)
 *
 * Control bit to enable the pull-down circuitry in the regulator
 */

#define BP_PMU_REG_2P5_ENABLE_PULLDOWN      3
#define BM_PMU_REG_2P5_ENABLE_PULLDOWN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << 3) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#else
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   (((v) << 3) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PULLDOWN field to a new value.
#define BW_PMU_REG_2P5_ENABLE_PULLDOWN(v)   BF_CS1(PMU_REG_2P5, ENABLE_PULLDOWN, v)
#endif

/* --- Register HW_PMU_REG_2P5, field BO_OFFSET (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_2P5_BO_OFFSET      4
#define BM_PMU_REG_2P5_BO_OFFSET      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_BO_OFFSET(v)   ((((reg32_t) v) << 4) & BM_PMU_REG_2P5_BO_OFFSET)
#else
#define BF_PMU_REG_2P5_BO_OFFSET(v)   (((v) << 4) & BM_PMU_REG_2P5_BO_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_2P5_BO_OFFSET(v)   BF_CS1(PMU_REG_2P5, BO_OFFSET, v)
#endif

/* --- Register HW_PMU_REG_2P5, field OUTPUT_TRG (RW)
 *
 * Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip
 * functionality at the extremes of the programming range.
 *
 * Values:
 * 0000 - 2.00V
 * 1110 - 2.50V
 * 1111 - 2.75V
 */

#define BP_PMU_REG_2P5_OUTPUT_TRG      8
#define BM_PMU_REG_2P5_OUTPUT_TRG      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   ((((reg32_t) v) << 8) & BM_PMU_REG_2P5_OUTPUT_TRG)
#else
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   (((v) << 8) & BM_PMU_REG_2P5_OUTPUT_TRG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_2P5_OUTPUT_TRG(v)   BF_CS1(PMU_REG_2P5, OUTPUT_TRG, v)
#endif


/* --- Register HW_PMU_REG_2P5, field BO_VDD2P5 (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_2P5_BO_VDD2P5      16
#define BM_PMU_REG_2P5_BO_VDD2P5      0x00010000

/* --- Register HW_PMU_REG_2P5, field OK_VDD2P5 (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_2P5_OK_VDD2P5      17
#define BM_PMU_REG_2P5_OK_VDD2P5      0x00020000

/* --- Register HW_PMU_REG_2P5, field ENABLE_WEAK_LINREG (RW)
 *
 * Enables the weak 2p5 regulator. This regulator is used when the main 2p5 regulator is disabled to
 * keep the 2.5V output roughly at 2.5V. Depends directly on the value of VDDIO.
 */

#define BP_PMU_REG_2P5_ENABLE_WEAK_LINREG      18
#define BM_PMU_REG_2P5_ENABLE_WEAK_LINREG      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   ((((reg32_t) v) << 18) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#else
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   (((v) << 18) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_WEAK_LINREG field to a new value.
#define BW_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   BF_CS1(PMU_REG_2P5, ENABLE_WEAK_LINREG, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_CORE - Digital Regulator Core Register (RW)
 *
 * This register defines the function of the digital regulators
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned REG0_TRIG : 5; //!< This bitfield defines the target voltage for the arm core power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG0_ADJ : 4; //!< This bitfield defines the adjustment bits to calibrate the target value of REG1 (ARM_CORE). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned REG1_TRIG : 5; //!< This bitfield defines the target voltage for the VPU/GPU power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG1_ADJ : 4; //!< This bitfield defines the adjustment bits to calibrate the target value of REG1 (REG_PU). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned REG2_TRIG : 5; //!< This bitfield defines the target voltage for the SOC power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG2_ADJ : 4; //!< This bitfield defines the adjustment bits to calibrate the target value of REG2 (REG_SOC). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned RAMP_RATE : 2; //!< Regulator voltage ramp rate.
        unsigned FET_ODRIVE : 1; //!< If set, increases the gate drive on power gating fets to reduce leakage in the off state. Care must be taken to only apply this bit when the input supply voltage to the power fet is less than 1.1V. This bit should only be used in low power modes where the external input supply voltage is nominally 0.9V.
        unsigned RESERVED0 : 2; //!< Reserved.
    } B;
} hw_pmu_reg_core_t;
#endif

/*
 * constants & macros for entire PMU_REG_CORE register
 */
#define HW_PMU_REG_CORE_ADDR      (REGS_PMU_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_CORE           (*(volatile hw_pmu_reg_core_t *) HW_PMU_REG_CORE_ADDR)
#define HW_PMU_REG_CORE_RD()      (HW_PMU_REG_CORE.U)
#define HW_PMU_REG_CORE_WR(v)     (HW_PMU_REG_CORE.U = (v))
#define HW_PMU_REG_CORE_SET(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() |  (v)))
#define HW_PMU_REG_CORE_CLR(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() & ~(v)))
#define HW_PMU_REG_CORE_TOG(v)    (HW_PMU_REG_CORE_WR(HW_PMU_REG_CORE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_CORE bitfields
 */

/* --- Register HW_PMU_REG_CORE, field REG0_TRIG (RW)
 *
 * This bitfield defines the target voltage for the arm core power domain. Single bit increments
 * reflect 25mV core voltage steps. Not all steps will make sense to use either because of input
 * supply limitations or load operation.
 *
 * Values:
 * 00000 - Power gated off
 * 00001 - Target core voltage = 0.725V
 * 10000 - Target core voltage = 1.100V
 * 11110 - Target core voltage = 1.450V
 * 11111 - Power FET switched full on. No regulation.
 */

#define BP_PMU_REG_CORE_REG0_TRIG      0
#define BM_PMU_REG_CORE_REG0_TRIG      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG0_TRIG(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_CORE_REG0_TRIG)
#else
#define BF_PMU_REG_CORE_REG0_TRIG(v)   (((v) << 0) & BM_PMU_REG_CORE_REG0_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG0_TRIG(v)   BF_CS1(PMU_REG_CORE, REG0_TRIG, v)
#endif


/* --- Register HW_PMU_REG_CORE, field REG0_ADJ (RW)
 *
 * This bitfield defines the adjustment bits to calibrate the target value of REG1 (ARM_CORE). The
 * adjustment is applied on top of any adjustment applied to the global reference in the MISC0
 * Register.
 *
 * Values:
 * 0000 - No adjustment
 * 0001 - +/- 0.25%
 * 0010 - +/- 0.50%
 * 0011 - +/- 0.75%
 * 0100 - +/- 1.00%
 * 0101 - +/- 1.25%
 * 0110 - +/- 1.50%
 * 0111 - +/- 1.75%
 * 1000 - +/- 0.25%
 * 1001 - +/- 0.50%
 * 1010 - +/- 0.75%
 * 1011 - +/- 1.00%
 * 1100 - +/- 1.25%
 * 1101 - +/- 1.50%
 * 1110 - +/- 1.75%
 * 1111 - +/- 2.00%
 */

#define BP_PMU_REG_CORE_REG0_ADJ      5
#define BM_PMU_REG_CORE_REG0_ADJ      0x000001e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG0_ADJ(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_CORE_REG0_ADJ)
#else
#define BF_PMU_REG_CORE_REG0_ADJ(v)   (((v) << 5) & BM_PMU_REG_CORE_REG0_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG0_ADJ(v)   BF_CS1(PMU_REG_CORE, REG0_ADJ, v)
#endif


/* --- Register HW_PMU_REG_CORE, field REG1_TRIG (RW)
 *
 * This bitfield defines the target voltage for the VPU/GPU power domain. Single bit increments
 * reflect 25mV core voltage steps. Not all steps will make sense to use either because of input
 * supply limitations or load operation.
 *
 * Values:
 * 00000 - Power gated off
 * 00001 - Target core voltage = 0.725V
 * 10000 - Target core voltage = 1.100V
 * 11110 - Target core voltage = 1.450V
 * 11111 - Power FET switched full on. No regulation.
 */

#define BP_PMU_REG_CORE_REG1_TRIG      9
#define BM_PMU_REG_CORE_REG1_TRIG      0x00003e00

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG1_TRIG(v)   ((((reg32_t) v) << 9) & BM_PMU_REG_CORE_REG1_TRIG)
#else
#define BF_PMU_REG_CORE_REG1_TRIG(v)   (((v) << 9) & BM_PMU_REG_CORE_REG1_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG1_TRIG(v)   BF_CS1(PMU_REG_CORE, REG1_TRIG, v)
#endif


/* --- Register HW_PMU_REG_CORE, field REG1_ADJ (RW)
 *
 * This bitfield defines the adjustment bits to calibrate the target value of REG1 (REG_PU). The
 * adjustment is applied on top of any adjustment applied to the global reference in the MISC0
 * Register.
 *
 * Values:
 * 0000 - No adjustment
 * 0001 - +/- 0.25%
 * 0010 - +/- 0.50%
 * 0011 - +/- 0.75%
 * 0100 - +/- 1.00%
 * 0101 - +/- 1.25%
 * 0110 - +/- 1.50%
 * 0111 - +/- 1.75%
 * 1000 - +/- 0.25%
 * 1001 - +/- 0.50%
 * 1010 - +/- 0.75%
 * 1011 - +/- 1.00%
 * 1100 - +/- 1.25%
 * 1101 - +/- 1.50%
 * 1110 - +/- 1.75%
 * 1111 - +/- 2.00%
 */

#define BP_PMU_REG_CORE_REG1_ADJ      14
#define BM_PMU_REG_CORE_REG1_ADJ      0x0003c000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG1_ADJ(v)   ((((reg32_t) v) << 14) & BM_PMU_REG_CORE_REG1_ADJ)
#else
#define BF_PMU_REG_CORE_REG1_ADJ(v)   (((v) << 14) & BM_PMU_REG_CORE_REG1_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG1_ADJ(v)   BF_CS1(PMU_REG_CORE, REG1_ADJ, v)
#endif


/* --- Register HW_PMU_REG_CORE, field REG2_TRIG (RW)
 *
 * This bitfield defines the target voltage for the SOC power domain. Single bit increments reflect
 * 25mV core voltage steps. Not all steps will make sense to use either because of input supply
 * limitations or load operation.
 *
 * Values:
 * 00000 - Power gated off
 * 00001 - Target core voltage = 0.725V
 * 10000 - Target core voltage = 1.100V
 * 11110 - Target core voltage = 1.450V
 * 11111 - Power FET switched full on. No regulation.
 */

#define BP_PMU_REG_CORE_REG2_TRIG      18
#define BM_PMU_REG_CORE_REG2_TRIG      0x007c0000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG2_TRIG(v)   ((((reg32_t) v) << 18) & BM_PMU_REG_CORE_REG2_TRIG)
#else
#define BF_PMU_REG_CORE_REG2_TRIG(v)   (((v) << 18) & BM_PMU_REG_CORE_REG2_TRIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG2_TRIG(v)   BF_CS1(PMU_REG_CORE, REG2_TRIG, v)
#endif


/* --- Register HW_PMU_REG_CORE, field REG2_ADJ (RW)
 *
 * This bitfield defines the adjustment bits to calibrate the target value of REG2 (REG_SOC). The
 * adjustment is applied on top of any adjustment applied to the global reference in the MISC0
 * Register.
 *
 * Values:
 * 0000 - No adjustment
 * 0001 - +/- 0.25%
 * 0010 - +/- 0.50%
 * 0011 - +/- 0.75%
 * 0100 - +/- 1.00%
 * 0101 - +/- 1.25%
 * 0110 - +/- 1.50%
 * 0111 - +/- 1.75%
 * 1000 - +/- 0.25%
 * 1001 - +/- 0.50%
 * 1010 - +/- 0.75%
 * 1011 - +/- 1.00%
 * 1100 - +/- 1.25%
 * 1101 - +/- 1.50%
 * 1110 - +/- 1.75%
 * 1111 - +/- 2.00%
 */

#define BP_PMU_REG_CORE_REG2_ADJ      23
#define BM_PMU_REG_CORE_REG2_ADJ      0x07800000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_REG2_ADJ(v)   ((((reg32_t) v) << 23) & BM_PMU_REG_CORE_REG2_ADJ)
#else
#define BF_PMU_REG_CORE_REG2_ADJ(v)   (((v) << 23) & BM_PMU_REG_CORE_REG2_ADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG2_ADJ(v)   BF_CS1(PMU_REG_CORE, REG2_ADJ, v)
#endif


/* --- Register HW_PMU_REG_CORE, field RAMP_RATE (RW)
 *
 * Regulator voltage ramp rate.
 *
 * Values:
 * 00 - Fast
 * 01 - Medium Fast
 * 10 - Medium Slow
 * 11 - Slow
 */

#define BP_PMU_REG_CORE_RAMP_RATE      27
#define BM_PMU_REG_CORE_RAMP_RATE      0x18000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_RAMP_RATE(v)   ((((reg32_t) v) << 27) & BM_PMU_REG_CORE_RAMP_RATE)
#else
#define BF_PMU_REG_CORE_RAMP_RATE(v)   (((v) << 27) & BM_PMU_REG_CORE_RAMP_RATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAMP_RATE field to a new value.
#define BW_PMU_REG_CORE_RAMP_RATE(v)   BF_CS1(PMU_REG_CORE, RAMP_RATE, v)
#endif


/* --- Register HW_PMU_REG_CORE, field FET_ODRIVE (RW)
 *
 * If set, increases the gate drive on power gating fets to reduce leakage in the off state. Care
 * must be taken to only apply this bit when the input supply voltage to the power fet is less than
 * 1.1V. This bit should only be used in low power modes where the external input supply voltage is
 * nominally 0.9V.
 */

#define BP_PMU_REG_CORE_FET_ODRIVE      29
#define BM_PMU_REG_CORE_FET_ODRIVE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_CORE_FET_ODRIVE)
#else
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   (((v) << 29) & BM_PMU_REG_CORE_FET_ODRIVE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FET_ODRIVE field to a new value.
#define BW_PMU_REG_CORE_FET_ODRIVE(v)   BF_CS1(PMU_REG_CORE, FET_ODRIVE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_MISC0 - Miscellaneous Register 0 (RW)
 *
 * This register defines the control and status bits for miscellaneous analog blocks.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned REFTOP_PWD : 1; //!< Control bit to power-down the analog bandgap reference circuitry. A note of caution, the bandgap is necessary for correct operation of most of the LDO, pll, and other analog functions on the die.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned REFTOP_SELFBIASOFF : 1; //!< Control bit to disable the self-bias circuit in the analog bandgap. The self-bias circuit is used by the bandgap during startup. This bit should be set after the bandgap has stabilized and is necessary for best noise performance of analog blocks using the outputs of the bandgap. Value should be returned to zero before removing vddhigh_in or asserting bit 0 of this register (REFTOP_PWD) to assure proper restart of the circuit.
        unsigned REFTOP_VBGADJ : 3; //!< 
        unsigned REFTOP_VBGUP : 1; //!< Status bit which signals that the analog bandgap voltage is up and stable. 1 - Stable. Not related to PMU.
        unsigned RESERVED1 : 4; //!< Reserved
        unsigned STOP_MODE_CONFIG : 1; //!< Configure the analog behavior in stop mode. Not related to PMU.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned OSC_I : 2; //!< This bit field determines the bias current in the 24MHz oscillator. The idea is to start up with the highest bias current which can be decreased after startup if determined to be acceptable. Not related to PMU.
        unsigned OSC_XTALOK : 1; //!< Status bit which signals that the output of the 24MHz crystal oscillator is stable. Generated from a timer and active detection of the actual frequency. Not related to PMU.
        unsigned OSC_XTALOK_EN : 1; //!< Not related to PMU.
        unsigned WBCP_VPW_THRESH : 2; //!< This signal alters the voltage that the pwell is charged pumped to. Not related to PMU.
        unsigned RESERVED3 : 5; //!< Reserved. Always set to zero.
        unsigned CLKGATE_CTRL : 1; //!< This bit allows disabling the clock gate (always un-gated) for the xtal 24MHz clock that clocks the digital logic in the analog block. Do not change the field during a low power event. This is not a field that the user would normally need to modify Not related to PMU.
        unsigned CLKGATE_DELAY : 3; //!< This field specifies the delay between powering up the XTAL 24MHz clock and release the clock to the digital logic inside the analog block. Do not change the field during a low power event. This is not a field that the user would normally need to modify Not related to PMU.
        unsigned RESERVED4 : 3; //!< Reserved
    } B;
} hw_pmu_misc0_t;
#endif

/*
 * constants & macros for entire PMU_MISC0 register
 */
#define HW_PMU_MISC0_ADDR      (REGS_PMU_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_MISC0           (*(volatile hw_pmu_misc0_t *) HW_PMU_MISC0_ADDR)
#define HW_PMU_MISC0_RD()      (HW_PMU_MISC0.U)
#define HW_PMU_MISC0_WR(v)     (HW_PMU_MISC0.U = (v))
#define HW_PMU_MISC0_SET(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() |  (v)))
#define HW_PMU_MISC0_CLR(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() & ~(v)))
#define HW_PMU_MISC0_TOG(v)    (HW_PMU_MISC0_WR(HW_PMU_MISC0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_MISC0 bitfields
 */

/* --- Register HW_PMU_MISC0, field REFTOP_PWD (RW)
 *
 * Control bit to power-down the analog bandgap reference circuitry. A note of caution, the bandgap
 * is necessary for correct operation of most of the LDO, pll, and other analog functions on the
 * die.
 */

#define BP_PMU_MISC0_REFTOP_PWD      0
#define BM_PMU_MISC0_REFTOP_PWD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_PWD(v)   ((((reg32_t) v) << 0) & BM_PMU_MISC0_REFTOP_PWD)
#else
#define BF_PMU_MISC0_REFTOP_PWD(v)   (((v) << 0) & BM_PMU_MISC0_REFTOP_PWD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_PWD field to a new value.
#define BW_PMU_MISC0_REFTOP_PWD(v)   BF_CS1(PMU_MISC0, REFTOP_PWD, v)
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_SELFBIASOFF (RW)
 *
 * Control bit to disable the self-bias circuit in the analog bandgap. The self-bias circuit is used
 * by the bandgap during startup. This bit should be set after the bandgap has stabilized and is
 * necessary for best noise performance of analog blocks using the outputs of the bandgap. Value
 * should be returned to zero before removing vddhigh_in or asserting bit 0 of this register
 * (REFTOP_PWD) to assure proper restart of the circuit.
 *
 * Values:
 * 0 - Uses coarse bias currents for startup
 * 1 - Uses bandgap based bias currents for best performance.
 */

#define BP_PMU_MISC0_REFTOP_SELFBIASOFF      3
#define BM_PMU_MISC0_REFTOP_SELFBIASOFF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   ((((reg32_t) v) << 3) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#else
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   (((v) << 3) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_SELFBIASOFF field to a new value.
#define BW_PMU_MISC0_REFTOP_SELFBIASOFF(v)   BF_CS1(PMU_MISC0, REFTOP_SELFBIASOFF, v)
#endif


/* --- Register HW_PMU_MISC0, field REFTOP_VBGADJ (RW)
 *

 *
 * Values:
 * 000 - Nominal VBG
 * 001 - VBG+0.78%
 * 010 - VBG+1.56%
 * 011 - VBG+2.34%
 * 100 - VBG+0.78%
 * 101 - VBG+1.56%
 * 110 - VBG+2.34%
 * 111 - VBG+3.12%
 */

#define BP_PMU_MISC0_REFTOP_VBGADJ      4
#define BM_PMU_MISC0_REFTOP_VBGADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   ((((reg32_t) v) << 4) & BM_PMU_MISC0_REFTOP_VBGADJ)
#else
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   (((v) << 4) & BM_PMU_MISC0_REFTOP_VBGADJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_VBGADJ field to a new value.
#define BW_PMU_MISC0_REFTOP_VBGADJ(v)   BF_CS1(PMU_MISC0, REFTOP_VBGADJ, v)
#endif


/* --- Register HW_PMU_MISC0, field REFTOP_VBGUP (RW)
 *
 * Status bit which signals that the analog bandgap voltage is up and stable. 1 - Stable. Not
 * related to PMU.
 */

#define BP_PMU_MISC0_REFTOP_VBGUP      7
#define BM_PMU_MISC0_REFTOP_VBGUP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   ((((reg32_t) v) << 7) & BM_PMU_MISC0_REFTOP_VBGUP)
#else
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   (((v) << 7) & BM_PMU_MISC0_REFTOP_VBGUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_VBGUP field to a new value.
#define BW_PMU_MISC0_REFTOP_VBGUP(v)   BF_CS1(PMU_MISC0, REFTOP_VBGUP, v)
#endif

/* --- Register HW_PMU_MISC0, field STOP_MODE_CONFIG (RW)
 *
 * Configure the analog behavior in stop mode. Not related to PMU.
 *
 * Values:
 * 0 - All analog except rtc powered down on stop mode assertion
 * 1 - Certain analog functions such as certain regulators left up
 */

#define BP_PMU_MISC0_STOP_MODE_CONFIG      12
#define BM_PMU_MISC0_STOP_MODE_CONFIG      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   ((((reg32_t) v) << 12) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#else
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   (((v) << 12) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP_MODE_CONFIG field to a new value.
#define BW_PMU_MISC0_STOP_MODE_CONFIG(v)   BF_CS1(PMU_MISC0, STOP_MODE_CONFIG, v)
#endif


/* --- Register HW_PMU_MISC0, field OSC_I (RW)
 *
 * This bit field determines the bias current in the 24MHz oscillator. The idea is to start up with
 * the highest bias current which can be decreased after startup if determined to be acceptable. Not
 * related to PMU.
 *
 * Values:
 * 00 - Nominal
 * 01 - Decrease current by 12.5%
 * 10 - Decrease current by 25.0%
 * 11 - Decrease current by 37.5%
 */

#define BP_PMU_MISC0_OSC_I      14
#define BM_PMU_MISC0_OSC_I      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_OSC_I(v)   ((((reg32_t) v) << 14) & BM_PMU_MISC0_OSC_I)
#else
#define BF_PMU_MISC0_OSC_I(v)   (((v) << 14) & BM_PMU_MISC0_OSC_I)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OSC_I field to a new value.
#define BW_PMU_MISC0_OSC_I(v)   BF_CS1(PMU_MISC0, OSC_I, v)
#endif


/* --- Register HW_PMU_MISC0, field OSC_XTALOK (RO)
 *
 * Status bit which signals that the output of the 24MHz crystal oscillator is stable. Generated
 * from a timer and active detection of the actual frequency. Not related to PMU.
 */

#define BP_PMU_MISC0_OSC_XTALOK      16
#define BM_PMU_MISC0_OSC_XTALOK      0x00010000

/* --- Register HW_PMU_MISC0, field OSC_XTALOK_EN (RW)
 *
 * Not related to PMU.
 */

#define BP_PMU_MISC0_OSC_XTALOK_EN      17
#define BM_PMU_MISC0_OSC_XTALOK_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   ((((reg32_t) v) << 17) & BM_PMU_MISC0_OSC_XTALOK_EN)
#else
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   (((v) << 17) & BM_PMU_MISC0_OSC_XTALOK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OSC_XTALOK_EN field to a new value.
#define BW_PMU_MISC0_OSC_XTALOK_EN(v)   BF_CS1(PMU_MISC0, OSC_XTALOK_EN, v)
#endif

/* --- Register HW_PMU_MISC0, field WBCP_VPW_THRESH (RW)
 *
 * This signal alters the voltage that the pwell is charged pumped to. Not related to PMU.
 *
 * Values:
 * 00 - Nominal output pwell bias voltage.
 * 01 - Increase pwell output voltage by 25mV.
 * 10 - Decrease pwell output pwell voltage by 25mV.
 * 11 - Decrease pwell output pwell voltage by 50mV.
 */

#define BP_PMU_MISC0_WBCP_VPW_THRESH      18
#define BM_PMU_MISC0_WBCP_VPW_THRESH      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   ((((reg32_t) v) << 18) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#else
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   (((v) << 18) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCP_VPW_THRESH field to a new value.
#define BW_PMU_MISC0_WBCP_VPW_THRESH(v)   BF_CS1(PMU_MISC0, WBCP_VPW_THRESH, v)
#endif


/* --- Register HW_PMU_MISC0, field CLKGATE_CTRL (RW)
 *
 * This bit allows disabling the clock gate (always un-gated) for the xtal 24MHz clock that clocks
 * the digital logic in the analog block. Do not change the field during a low power event. This is
 * not a field that the user would normally need to modify Not related to PMU.
 *
 * Values:
 * 0 - Allow the logic to automatically gate the clock when the XTAL is powered down.
 * 1 - Prevent the logic from ever gating off the clock.
 */

#define BP_PMU_MISC0_CLKGATE_CTRL      25
#define BM_PMU_MISC0_CLKGATE_CTRL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   ((((reg32_t) v) << 25) & BM_PMU_MISC0_CLKGATE_CTRL)
#else
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   (((v) << 25) & BM_PMU_MISC0_CLKGATE_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE_CTRL field to a new value.
#define BW_PMU_MISC0_CLKGATE_CTRL(v)   BF_CS1(PMU_MISC0, CLKGATE_CTRL, v)
#endif


/* --- Register HW_PMU_MISC0, field CLKGATE_DELAY (RW)
 *
 * This field specifies the delay between powering up the XTAL 24MHz clock and release the clock to
 * the digital logic inside the analog block. Do not change the field during a low power event. This
 * is not a field that the user would normally need to modify Not related to PMU.
 *
 * Values:
 * 000 - 0.5ms
 * 001 - 1.0ms
 * 010 - 2.0ms
 * 011 - 3.0ms
 * 100 - 4.0ms
 * 101 - 5.0ms
 * 110 - 6.0ms
 * 111 - 7.0ms
 */

#define BP_PMU_MISC0_CLKGATE_DELAY      26
#define BM_PMU_MISC0_CLKGATE_DELAY      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   ((((reg32_t) v) << 26) & BM_PMU_MISC0_CLKGATE_DELAY)
#else
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   (((v) << 26) & BM_PMU_MISC0_CLKGATE_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE_DELAY field to a new value.
#define BW_PMU_MISC0_CLKGATE_DELAY(v)   BF_CS1(PMU_MISC0, CLKGATE_DELAY, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC1 - Miscellaneous Register 1 (RW)
 *
 * This register defines the control and status bits for miscellaneous analog blocks. The lvds1 and
 * lvds2 controls below control the behavior of the anaclk1/1b and anaclk2/2b lvds IO's.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LVDS1_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDS2_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDSCLK1_OBEN : 1; //!< This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_OBEN : 1; //!< This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK1_IBEN : 1; //!< This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_IBEN : 1; //!< This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned RESERVED0 : 15; //!< Reserved
        unsigned IRQ_TEMPSENSE : 1; //!< This status bit is set to one when when the temperature sensor interrupt asserts. Not related to PMU.
        unsigned IRQ_ANA_BO : 1; //!< This status bit is set to one when when any of the analog regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
        unsigned IRQ_DIG_BO : 1; //!< This status bit is set to one when when any of the digital regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
    } B;
} hw_pmu_reg_misc1_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1 register
 */
#define HW_PMU_REG_MISC1_ADDR      (REGS_PMU_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1           (*(volatile hw_pmu_reg_misc1_t *) HW_PMU_REG_MISC1_ADDR)
#define HW_PMU_REG_MISC1_RD()      (HW_PMU_REG_MISC1.U)
#define HW_PMU_REG_MISC1_WR(v)     (HW_PMU_REG_MISC1.U = (v))
#define HW_PMU_REG_MISC1_SET(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() |  (v)))
#define HW_PMU_REG_MISC1_CLR(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() & ~(v)))
#define HW_PMU_REG_MISC1_TOG(v)    (HW_PMU_REG_MISC1_WR(HW_PMU_REG_MISC1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_MISC1 bitfields
 */

/* --- Register HW_PMU_REG_MISC1, field LVDS1_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (not useful)
 * 10100 - lvds2 (loopback)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_LVDS1_CLK_SEL      0
#define BM_PMU_REG_MISC1_LVDS1_CLK_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   (((v) << 0) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS1_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS1_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1, field LVDS2_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (loopback)
 * 10100 - lvds2 (not useful)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_LVDS2_CLK_SEL      5
#define BM_PMU_REG_MISC1_LVDS2_CLK_SEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   (((v) << 5) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS2_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS2_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK1_OBEN      10
#define BM_PMU_REG_MISC1_LVDSCLK1_OBEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << 10) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   (((v) << 10) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_OBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK2_OBEN      11
#define BM_PMU_REG_MISC1_LVDSCLK2_OBEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   (((v) << 11) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_OBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK1_IBEN      12
#define BM_PMU_REG_MISC1_LVDSCLK1_IBEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << 12) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   (((v) << 12) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_IBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK2_IBEN      13
#define BM_PMU_REG_MISC1_LVDSCLK2_IBEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#else
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   (((v) << 13) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_IBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_TEMPSENSE (W1C)
 *
 * This status bit is set to one when when the temperature sensor interrupt asserts. Not related to
 * PMU.
 */

#define BP_PMU_REG_MISC1_IRQ_TEMPSENSE      29
#define BM_PMU_REG_MISC1_IRQ_TEMPSENSE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#else
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   (((v) << 29) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_TEMPSENSE field to a new value.
#define BW_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_ANA_BO (W1C)
 *
 * This status bit is set to one when when any of the analog regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_IRQ_ANA_BO      30
#define BM_PMU_REG_MISC1_IRQ_ANA_BO      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#else
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   (((v) << 30) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ANA_BO field to a new value.
#define BW_PMU_REG_MISC1_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_DIG_BO (W1C)
 *
 * This status bit is set to one when when any of the digital regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_IRQ_DIG_BO      31
#define BM_PMU_REG_MISC1_IRQ_DIG_BO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#else
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   (((v) << 31) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_DIG_BO field to a new value.
#define BW_PMU_REG_MISC1_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_DIG_BO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC1_SET - Miscellaneous Register 1 _SET (RW)
 *
 * This register defines the control and status bits for miscellaneous analog blocks. The lvds1 and
 * lvds2 controls below control the behavior of the anaclk1/1b and anaclk2/2b lvds IO's.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LVDS1_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDS2_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDSCLK1_OBEN : 1; //!< This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_OBEN : 1; //!< This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK1_IBEN : 1; //!< This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_IBEN : 1; //!< This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned RESERVED0 : 15; //!< Reserved
        unsigned IRQ_TEMPSENSE : 1; //!< This status bit is set to one when when the temperature sensor interrupt asserts. Not related to PMU.
        unsigned IRQ_ANA_BO : 1; //!< This status bit is set to one when when any of the analog regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
        unsigned IRQ_DIG_BO : 1; //!< This status bit is set to one when when any of the digital regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
    } B;
} hw_pmu_reg_misc1_set_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1_SET register
 */
#define HW_PMU_REG_MISC1_SET_ADDR      (REGS_PMU_BASE + 0x164)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1_SET           (*(volatile hw_pmu_reg_misc1_set_t *) HW_PMU_REG_MISC1_SET_ADDR)
#define HW_PMU_REG_MISC1_SET_RD()      (HW_PMU_REG_MISC1_SET.U)
#define HW_PMU_REG_MISC1_SET_WR(v)     (HW_PMU_REG_MISC1_SET.U = (v))
#define HW_PMU_REG_MISC1_SET_SET(v)    (HW_PMU_REG_MISC1_SET_WR(HW_PMU_REG_MISC1_SET_RD() |  (v)))
#define HW_PMU_REG_MISC1_SET_CLR(v)    (HW_PMU_REG_MISC1_SET_WR(HW_PMU_REG_MISC1_SET_RD() & ~(v)))
#define HW_PMU_REG_MISC1_SET_TOG(v)    (HW_PMU_REG_MISC1_SET_WR(HW_PMU_REG_MISC1_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_MISC1_SET bitfields
 */

/* --- Register HW_PMU_REG_MISC1_SET, field LVDS1_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (not useful)
 * 10100 - lvds2 (loopback)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_SET_LVDS1_CLK_SEL      0
#define BM_PMU_REG_MISC1_SET_LVDS1_CLK_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC1_SET_LVDS1_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_SET_LVDS1_CLK_SEL(v)   (((v) << 0) & BM_PMU_REG_MISC1_SET_LVDS1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS1_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_SET, LVDS1_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_SET, field LVDS2_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (loopback)
 * 10100 - lvds2 (not useful)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_SET_LVDS2_CLK_SEL      5
#define BM_PMU_REG_MISC1_SET_LVDS2_CLK_SEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC1_SET_LVDS2_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_SET_LVDS2_CLK_SEL(v)   (((v) << 5) & BM_PMU_REG_MISC1_SET_LVDS2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS2_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_SET, LVDS2_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_SET, field LVDSCLK1_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_SET_LVDSCLK1_OBEN      10
#define BM_PMU_REG_MISC1_SET_LVDSCLK1_OBEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << 10) & BM_PMU_REG_MISC1_SET_LVDSCLK1_OBEN)
#else
#define BF_PMU_REG_MISC1_SET_LVDSCLK1_OBEN(v)   (((v) << 10) & BM_PMU_REG_MISC1_SET_LVDSCLK1_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_OBEN field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1_SET, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field LVDSCLK2_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_SET_LVDSCLK2_OBEN      11
#define BM_PMU_REG_MISC1_SET_LVDSCLK2_OBEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC1_SET_LVDSCLK2_OBEN)
#else
#define BF_PMU_REG_MISC1_SET_LVDSCLK2_OBEN(v)   (((v) << 11) & BM_PMU_REG_MISC1_SET_LVDSCLK2_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_OBEN field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1_SET, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field LVDSCLK1_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_SET_LVDSCLK1_IBEN      12
#define BM_PMU_REG_MISC1_SET_LVDSCLK1_IBEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << 12) & BM_PMU_REG_MISC1_SET_LVDSCLK1_IBEN)
#else
#define BF_PMU_REG_MISC1_SET_LVDSCLK1_IBEN(v)   (((v) << 12) & BM_PMU_REG_MISC1_SET_LVDSCLK1_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_IBEN field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1_SET, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field LVDSCLK2_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_SET_LVDSCLK2_IBEN      13
#define BM_PMU_REG_MISC1_SET_LVDSCLK2_IBEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC1_SET_LVDSCLK2_IBEN)
#else
#define BF_PMU_REG_MISC1_SET_LVDSCLK2_IBEN(v)   (((v) << 13) & BM_PMU_REG_MISC1_SET_LVDSCLK2_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_IBEN field to a new value.
#define BW_PMU_REG_MISC1_SET_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1_SET, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field IRQ_TEMPSENSE (W1C)
 *
 * This status bit is set to one when when the temperature sensor interrupt asserts. Not related to
 * PMU.
 */

#define BP_PMU_REG_MISC1_SET_IRQ_TEMPSENSE      29
#define BM_PMU_REG_MISC1_SET_IRQ_TEMPSENSE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_MISC1_SET_IRQ_TEMPSENSE)
#else
#define BF_PMU_REG_MISC1_SET_IRQ_TEMPSENSE(v)   (((v) << 29) & BM_PMU_REG_MISC1_SET_IRQ_TEMPSENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_TEMPSENSE field to a new value.
#define BW_PMU_REG_MISC1_SET_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1_SET, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field IRQ_ANA_BO (W1C)
 *
 * This status bit is set to one when when any of the analog regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_SET_IRQ_ANA_BO      30
#define BM_PMU_REG_MISC1_SET_IRQ_ANA_BO      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_IRQ_ANA_BO(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC1_SET_IRQ_ANA_BO)
#else
#define BF_PMU_REG_MISC1_SET_IRQ_ANA_BO(v)   (((v) << 30) & BM_PMU_REG_MISC1_SET_IRQ_ANA_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ANA_BO field to a new value.
#define BW_PMU_REG_MISC1_SET_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1_SET, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1_SET, field IRQ_DIG_BO (W1C)
 *
 * This status bit is set to one when when any of the digital regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_SET_IRQ_DIG_BO      31
#define BM_PMU_REG_MISC1_SET_IRQ_DIG_BO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_SET_IRQ_DIG_BO(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_MISC1_SET_IRQ_DIG_BO)
#else
#define BF_PMU_REG_MISC1_SET_IRQ_DIG_BO(v)   (((v) << 31) & BM_PMU_REG_MISC1_SET_IRQ_DIG_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_DIG_BO field to a new value.
#define BW_PMU_REG_MISC1_SET_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1_SET, IRQ_DIG_BO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC1_CLR - Miscellaneous Register 1 _CLR (RW)
 *
 * This register defines the control and status bits for miscellaneous analog blocks. The lvds1 and
 * lvds2 controls below control the behavior of the anaclk1/1b and anaclk2/2b lvds IO's.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LVDS1_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDS2_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDSCLK1_OBEN : 1; //!< This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_OBEN : 1; //!< This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK1_IBEN : 1; //!< This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_IBEN : 1; //!< This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned RESERVED0 : 15; //!< Reserved
        unsigned IRQ_TEMPSENSE : 1; //!< This status bit is set to one when when the temperature sensor interrupt asserts. Not related to PMU.
        unsigned IRQ_ANA_BO : 1; //!< This status bit is set to one when when any of the analog regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
        unsigned IRQ_DIG_BO : 1; //!< This status bit is set to one when when any of the digital regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
    } B;
} hw_pmu_reg_misc1_clr_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1_CLR register
 */
#define HW_PMU_REG_MISC1_CLR_ADDR      (REGS_PMU_BASE + 0x168)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1_CLR           (*(volatile hw_pmu_reg_misc1_clr_t *) HW_PMU_REG_MISC1_CLR_ADDR)
#define HW_PMU_REG_MISC1_CLR_RD()      (HW_PMU_REG_MISC1_CLR.U)
#define HW_PMU_REG_MISC1_CLR_WR(v)     (HW_PMU_REG_MISC1_CLR.U = (v))
#define HW_PMU_REG_MISC1_CLR_SET(v)    (HW_PMU_REG_MISC1_CLR_WR(HW_PMU_REG_MISC1_CLR_RD() |  (v)))
#define HW_PMU_REG_MISC1_CLR_CLR(v)    (HW_PMU_REG_MISC1_CLR_WR(HW_PMU_REG_MISC1_CLR_RD() & ~(v)))
#define HW_PMU_REG_MISC1_CLR_TOG(v)    (HW_PMU_REG_MISC1_CLR_WR(HW_PMU_REG_MISC1_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_MISC1_CLR bitfields
 */

/* --- Register HW_PMU_REG_MISC1_CLR, field LVDS1_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (not useful)
 * 10100 - lvds2 (loopback)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL      0
#define BM_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL(v)   (((v) << 0) & BM_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS1_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDS1_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_CLR, field LVDS2_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (loopback)
 * 10100 - lvds2 (not useful)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL      5
#define BM_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL(v)   (((v) << 5) & BM_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS2_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDS2_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_CLR, field LVDSCLK1_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN      10
#define BM_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << 10) & BM_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN)
#else
#define BF_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN(v)   (((v) << 10) & BM_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_OBEN field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field LVDSCLK2_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN      11
#define BM_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN)
#else
#define BF_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN(v)   (((v) << 11) & BM_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_OBEN field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field LVDSCLK1_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN      12
#define BM_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << 12) & BM_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN)
#else
#define BF_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN(v)   (((v) << 12) & BM_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_IBEN field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field LVDSCLK2_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN      13
#define BM_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN)
#else
#define BF_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN(v)   (((v) << 13) & BM_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_IBEN field to a new value.
#define BW_PMU_REG_MISC1_CLR_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1_CLR, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field IRQ_TEMPSENSE (W1C)
 *
 * This status bit is set to one when when the temperature sensor interrupt asserts. Not related to
 * PMU.
 */

#define BP_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE      29
#define BM_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE)
#else
#define BF_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE(v)   (((v) << 29) & BM_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_TEMPSENSE field to a new value.
#define BW_PMU_REG_MISC1_CLR_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1_CLR, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field IRQ_ANA_BO (W1C)
 *
 * This status bit is set to one when when any of the analog regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_CLR_IRQ_ANA_BO      30
#define BM_PMU_REG_MISC1_CLR_IRQ_ANA_BO      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_IRQ_ANA_BO(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC1_CLR_IRQ_ANA_BO)
#else
#define BF_PMU_REG_MISC1_CLR_IRQ_ANA_BO(v)   (((v) << 30) & BM_PMU_REG_MISC1_CLR_IRQ_ANA_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ANA_BO field to a new value.
#define BW_PMU_REG_MISC1_CLR_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1_CLR, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1_CLR, field IRQ_DIG_BO (W1C)
 *
 * This status bit is set to one when when any of the digital regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_CLR_IRQ_DIG_BO      31
#define BM_PMU_REG_MISC1_CLR_IRQ_DIG_BO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_CLR_IRQ_DIG_BO(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_MISC1_CLR_IRQ_DIG_BO)
#else
#define BF_PMU_REG_MISC1_CLR_IRQ_DIG_BO(v)   (((v) << 31) & BM_PMU_REG_MISC1_CLR_IRQ_DIG_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_DIG_BO field to a new value.
#define BW_PMU_REG_MISC1_CLR_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1_CLR, IRQ_DIG_BO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC1_TOG - Miscellaneous Register 1 _TOG (RW)
 *
 * This register defines the control and status bits for miscellaneous analog blocks. The lvds1 and
 * lvds2 controls below control the behavior of the anaclk1/1b and anaclk2/2b lvds IO's.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LVDS1_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDS2_CLK_SEL : 5; //!< This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDSCLK1_OBEN : 1; //!< This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_OBEN : 1; //!< This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK1_IBEN : 1; //!< This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_IBEN : 1; //!< This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned RESERVED0 : 15; //!< Reserved
        unsigned IRQ_TEMPSENSE : 1; //!< This status bit is set to one when when the temperature sensor interrupt asserts. Not related to PMU.
        unsigned IRQ_ANA_BO : 1; //!< This status bit is set to one when when any of the analog regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
        unsigned IRQ_DIG_BO : 1; //!< This status bit is set to one when when any of the digital regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
    } B;
} hw_pmu_reg_misc1_tog_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1_TOG register
 */
#define HW_PMU_REG_MISC1_TOG_ADDR      (REGS_PMU_BASE + 0x16c)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1_TOG           (*(volatile hw_pmu_reg_misc1_tog_t *) HW_PMU_REG_MISC1_TOG_ADDR)
#define HW_PMU_REG_MISC1_TOG_RD()      (HW_PMU_REG_MISC1_TOG.U)
#define HW_PMU_REG_MISC1_TOG_WR(v)     (HW_PMU_REG_MISC1_TOG.U = (v))
#define HW_PMU_REG_MISC1_TOG_SET(v)    (HW_PMU_REG_MISC1_TOG_WR(HW_PMU_REG_MISC1_TOG_RD() |  (v)))
#define HW_PMU_REG_MISC1_TOG_CLR(v)    (HW_PMU_REG_MISC1_TOG_WR(HW_PMU_REG_MISC1_TOG_RD() & ~(v)))
#define HW_PMU_REG_MISC1_TOG_TOG(v)    (HW_PMU_REG_MISC1_TOG_WR(HW_PMU_REG_MISC1_TOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_MISC1_TOG bitfields
 */

/* --- Register HW_PMU_REG_MISC1_TOG, field LVDS1_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (not useful)
 * 10100 - lvds2 (loopback)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL      0
#define BM_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL(v)   (((v) << 0) & BM_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS1_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDS1_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_TOG, field LVDS2_CLK_SEL (RW)
 *
 * This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
 *
 * Values:
 * 00000 - Arm PLL
 * 00001 - 528 PLL
 * 00010 - pfd4
 * 00011 - pfd5
 * 00100 - pfd6
 * 00101 - pfd7
 * 00110 - Audio PLL
 * 00111 - Video PLL
 * 01000 - MLB PLL
 * 01001 - ethernet ref clock
 * 01010 - PCIe ref clock
 * 01011 - SATA ref clock
 * 01100 - USB1 PLL clock
 * 01101 - USB2 PLL clock
 * 01110 - pfd0
 * 01111 - pfd1
 * 10000 - pfd2
 * 10001 - pfd3
 * 10010 - xtal
 * 10011 - lvds1 (loopback)
 * 10100 - lvds2 (not useful)
 * 10101 to 11111 - pfd7
 */

#define BP_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL      5
#define BM_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL      0x000003e0

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL)
#else
#define BF_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL(v)   (((v) << 5) & BM_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS2_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDS2_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1_TOG, field LVDSCLK1_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN      10
#define BM_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << 10) & BM_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN)
#else
#define BF_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN(v)   (((v) << 10) & BM_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_OBEN field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field LVDSCLK2_OBEN (RW)
 *
 * This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN      11
#define BM_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << 11) & BM_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN)
#else
#define BF_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN(v)   (((v) << 11) & BM_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_OBEN field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field LVDSCLK1_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN      12
#define BM_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << 12) & BM_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN)
#else
#define BF_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN(v)   (((v) << 12) & BM_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_IBEN field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field LVDSCLK2_IBEN (RW)
 *
 * This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN      13
#define BM_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN)
#else
#define BF_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN(v)   (((v) << 13) & BM_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_IBEN field to a new value.
#define BW_PMU_REG_MISC1_TOG_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1_TOG, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field IRQ_TEMPSENSE (W1C)
 *
 * This status bit is set to one when when the temperature sensor interrupt asserts. Not related to
 * PMU.
 */

#define BP_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE      29
#define BM_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << 29) & BM_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE)
#else
#define BF_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE(v)   (((v) << 29) & BM_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_TEMPSENSE field to a new value.
#define BW_PMU_REG_MISC1_TOG_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1_TOG, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field IRQ_ANA_BO (W1C)
 *
 * This status bit is set to one when when any of the analog regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_TOG_IRQ_ANA_BO      30
#define BM_PMU_REG_MISC1_TOG_IRQ_ANA_BO      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_IRQ_ANA_BO(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC1_TOG_IRQ_ANA_BO)
#else
#define BF_PMU_REG_MISC1_TOG_IRQ_ANA_BO(v)   (((v) << 30) & BM_PMU_REG_MISC1_TOG_IRQ_ANA_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ANA_BO field to a new value.
#define BW_PMU_REG_MISC1_TOG_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1_TOG, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1_TOG, field IRQ_DIG_BO (W1C)
 *
 * This status bit is set to one when when any of the digital regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_TOG_IRQ_DIG_BO      31
#define BM_PMU_REG_MISC1_TOG_IRQ_DIG_BO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC1_TOG_IRQ_DIG_BO(v)   ((((reg32_t) v) << 31) & BM_PMU_REG_MISC1_TOG_IRQ_DIG_BO)
#else
#define BF_PMU_REG_MISC1_TOG_IRQ_DIG_BO(v)   (((v) << 31) & BM_PMU_REG_MISC1_TOG_IRQ_DIG_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_DIG_BO field to a new value.
#define BW_PMU_REG_MISC1_TOG_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1_TOG, IRQ_DIG_BO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC2 - Miscellaneous Register 2 (RW)
 *
 * This register defines the basic controls for the temperature sensor minus the frequency of
 * automatic sampling which is defined in TEMPSENSE_1.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned REG0_BO_OFFSET : 3; //!< This bit field defines the brown out voltage offset for the CORE power domain. Ana_irq1 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG1_BO_STATUS : 1; //!< Reg0 brownout status bit.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned REG0_ENABLE_BO : 1; //!< Enables the brownout detection.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned CONTROL0 : 1; //!< Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode.
        unsigned REG1_BO_OFFSET : 3; //!< This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG1_BO_STATUS1 : 1; //!< Reg1 brownout status bit.
        unsigned RESERVED2 : 1; //!< Reserved.
        unsigned REG1_ENABLE_BO : 1; //!< Enables the brownout detection.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned REG2_BO_OFFSET : 3; //!< This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG2_BO_STATUS : 1; //!< Reg2 brownout status bit.
        unsigned RESERVED5 : 1; //!< Reserved.
        unsigned REG2_ENABLE_BO : 1; //!< Enables the brownout detection.
        unsigned REG2_OK : 1; //!< Signals that the voltage is above the brownout level for the SOC supply.
        unsigned RESERVED6 : 1; //!< Reserved
        unsigned REG0_STEP_TIME : 2; //!< Number of clock periods (24MHz clock).
        unsigned REG1_STEP_TIME : 2; //!< Number of clock periods (24MHz clock).
        unsigned REG2_STEP_TIME : 2; //!< Number of clock periods (24MHz clock).
        unsigned CONTROL3 : 2; //!< Post-divider for video PLL. The output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
    } B;
} hw_pmu_reg_misc2_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC2 register
 */
#define HW_PMU_REG_MISC2_ADDR      (REGS_PMU_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC2           (*(volatile hw_pmu_reg_misc2_t *) HW_PMU_REG_MISC2_ADDR)
#define HW_PMU_REG_MISC2_RD()      (HW_PMU_REG_MISC2.U)
#define HW_PMU_REG_MISC2_WR(v)     (HW_PMU_REG_MISC2.U = (v))
#define HW_PMU_REG_MISC2_SET(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() |  (v)))
#define HW_PMU_REG_MISC2_CLR(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() & ~(v)))
#define HW_PMU_REG_MISC2_TOG(v)    (HW_PMU_REG_MISC2_WR(HW_PMU_REG_MISC2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PMU_REG_MISC2 bitfields
 */

/* --- Register HW_PMU_REG_MISC2, field REG0_BO_OFFSET (RO)
 *
 * This bit field defines the brown out voltage offset for the CORE power domain. Ana_irq1 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG0_BO_OFFSET      0
#define BM_PMU_REG_MISC2_REG0_BO_OFFSET      0x00000007


/* --- Register HW_PMU_REG_MISC2, field REG1_BO_STATUS (RO)
 *
 * Reg0 brownout status bit.
 *
 * Values:
 * 1 - Brownout, supply is below target minus brownout offset.
 */

#define BP_PMU_REG_MISC2_REG1_BO_STATUS      3
#define BM_PMU_REG_MISC2_REG1_BO_STATUS      0x00000008


/* --- Register HW_PMU_REG_MISC2, field REG0_ENABLE_BO (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG0_ENABLE_BO      5
#define BM_PMU_REG_MISC2_REG0_ENABLE_BO      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   ((((reg32_t) v) << 5) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   (((v) << 5) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG0_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG0_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field CONTROL0 (RW)
 *
 * Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode.
 */

#define BP_PMU_REG_MISC2_CONTROL0      7
#define BM_PMU_REG_MISC2_CONTROL0      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL0(v)   ((((reg32_t) v) << 7) & BM_PMU_REG_MISC2_CONTROL0)
#else
#define BF_PMU_REG_MISC2_CONTROL0(v)   (((v) << 7) & BM_PMU_REG_MISC2_CONTROL0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONTROL0 field to a new value.
#define BW_PMU_REG_MISC2_CONTROL0(v)   BF_CS1(PMU_REG_MISC2, CONTROL0, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_BO_OFFSET (RO)
 *
 * This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG1_BO_OFFSET      8
#define BM_PMU_REG_MISC2_REG1_BO_OFFSET      0x00000700


/* --- Register HW_PMU_REG_MISC2, field REG1_BO_STATUS1 (RO)
 *
 * Reg1 brownout status bit.
 *
 * Values:
 * 1 - Brownout, supply is below target minus brownout offset.
 */

#define BP_PMU_REG_MISC2_REG1_BO_STATUS1      11
#define BM_PMU_REG_MISC2_REG1_BO_STATUS1      0x00000800


/* --- Register HW_PMU_REG_MISC2, field REG1_ENABLE_BO (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG1_ENABLE_BO      13
#define BM_PMU_REG_MISC2_REG1_ENABLE_BO      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   ((((reg32_t) v) << 13) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   (((v) << 13) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG1_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG1_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_BO_OFFSET (RO)
 *
 * This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG2_BO_OFFSET      16
#define BM_PMU_REG_MISC2_REG2_BO_OFFSET      0x00070000


/* --- Register HW_PMU_REG_MISC2, field REG2_BO_STATUS (RO)
 *
 * Reg2 brownout status bit.
 */

#define BP_PMU_REG_MISC2_REG2_BO_STATUS      19
#define BM_PMU_REG_MISC2_REG2_BO_STATUS      0x00080000

/* --- Register HW_PMU_REG_MISC2, field REG2_ENABLE_BO (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG2_ENABLE_BO      21
#define BM_PMU_REG_MISC2_REG2_ENABLE_BO      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   ((((reg32_t) v) << 21) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#else
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   (((v) << 21) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG2_ENABLE_BO(v)   BF_CS1(PMU_REG_MISC2, REG2_ENABLE_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_OK (RO)
 *
 * Signals that the voltage is above the brownout level for the SOC supply.
 */

#define BP_PMU_REG_MISC2_REG2_OK      22
#define BM_PMU_REG_MISC2_REG2_OK      0x00400000

/* --- Register HW_PMU_REG_MISC2, field REG0_STEP_TIME (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG0_STEP_TIME      24
#define BM_PMU_REG_MISC2_REG0_STEP_TIME      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   ((((reg32_t) v) << 24) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   (((v) << 24) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG0_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG0_STEP_TIME, v)
#endif


/* --- Register HW_PMU_REG_MISC2, field REG1_STEP_TIME (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG1_STEP_TIME      26
#define BM_PMU_REG_MISC2_REG1_STEP_TIME      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   ((((reg32_t) v) << 26) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   (((v) << 26) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG1_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG1_STEP_TIME, v)
#endif


/* --- Register HW_PMU_REG_MISC2, field REG2_STEP_TIME (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG2_STEP_TIME      28
#define BM_PMU_REG_MISC2_REG2_STEP_TIME      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   ((((reg32_t) v) << 28) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#else
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   (((v) << 28) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG2_STEP_TIME(v)   BF_CS1(PMU_REG_MISC2, REG2_STEP_TIME, v)
#endif


/* --- Register HW_PMU_REG_MISC2, field CONTROL3 (RW)
 *
 * Post-divider for video PLL. The output clock of the video PLL should be gated prior to changing
 * this divider to prevent glitches.
 *
 * Values:
 * 00 - div-by-1(default)
 * 01 - div-by-2
 * 10 - div-by-1
 * 11 - div-by-4
 */

#define BP_PMU_REG_MISC2_CONTROL3      30
#define BM_PMU_REG_MISC2_CONTROL3      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_PMU_REG_MISC2_CONTROL3(v)   ((((reg32_t) v) << 30) & BM_PMU_REG_MISC2_CONTROL3)
#else
#define BF_PMU_REG_MISC2_CONTROL3(v)   (((v) << 30) & BM_PMU_REG_MISC2_CONTROL3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CONTROL3 field to a new value.
#define BW_PMU_REG_MISC2_CONTROL3(v)   BF_CS1(PMU_REG_MISC2, CONTROL3, v)
#endif



/*!
 * @brief All PMU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[68];
    volatile hw_pmu_reg_1p1_t REG_1P1; //!< Regulator 1P1 Register
    reg32_t _reserved1[3];
    volatile hw_pmu_reg_3p0_t REG_3P0; //!< Regulator 3P0 Register
    reg32_t _reserved2[3];
    volatile hw_pmu_reg_2p5_t REG_2P5; //!< Regulator 2P5 Register
    reg32_t _reserved3[3];
    volatile hw_pmu_reg_core_t REG_CORE; //!< Digital Regulator Core Register
    reg32_t _reserved4[3];
    volatile hw_pmu_misc0_t MISC0; //!< Miscellaneous Register 0
    reg32_t _reserved5[3];
    volatile hw_pmu_reg_misc1_t REG_MISC1; //!< Miscellaneous Register 1
    volatile hw_pmu_reg_misc1_set_t REG_MISC1_SET; //!< Miscellaneous Register 1 _SET
    volatile hw_pmu_reg_misc1_clr_t REG_MISC1_CLR; //!< Miscellaneous Register 1 _CLR
    volatile hw_pmu_reg_misc1_tog_t REG_MISC1_TOG; //!< Miscellaneous Register 1 _TOG
    volatile hw_pmu_reg_misc2_t REG_MISC2; //!< Miscellaneous Register 2
} hw_pmu_t;
#endif

//! @brief Macro to access all PMU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PMU(0)</code>.
#define HW_PMU     (*(volatile hw_pmu_t *) REGS_PMU_BASE)


#endif // _PMU_H
