/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_PMU_REGISTERS_H__
#define __HW_PMU_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL PMU registers defined in this header file.
 *
 * - HW_PMU_REG_1P1 - Regulator 1P1 Register
 * - HW_PMU_REG_3P0 - Regulator 3P0 Register
 * - HW_PMU_REG_2P5 - Regulator 2P5 Register
 * - HW_PMU_REG_CORE - Digital Regulator Core Register
 * - HW_PMU_MISC0 - Miscellaneous Register 0
 * - HW_PMU_REG_MISC1 - Miscellaneous Register 1
 * - HW_PMU_REG_MISC2 - Miscellaneous Register 2
 *
 * - hw_pmu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PMU_BASE
#define HW_PMU_INSTANCE_COUNT (1) //!< Number of instances of the PMU module.
#define REGS_PMU_BASE (0x020c8000) //!< Base address for PMU.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_1P1 - Regulator 1P1 Register (RW)
 *
 * Reset value: 0x00001073
 *
 * This register defines the control and status bits for the 1.1V regulator. This regulator is
 * designed to power the digital portions of the analog cells.
 */
typedef union _hw_pmu_reg_1p1
{
    reg32_t U;
    struct _hw_pmu_reg_1p1_bitfields
    {
        unsigned ENABLE_LINREG : 1; //!< [0] Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< [1] Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< [2] Control bit to enable the current-limit circuitry in the regulator.
        unsigned ENABLE_PULLDOWN : 1; //!< [3] Control bit to enable the pull-down circuitry in the regulator
        unsigned BO_OFFSET : 3; //!< [6:4] Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned RESERVED0 : 1; //!< [7] Reserved.
        unsigned OUTPUT_TRG : 5; //!< [12:8] Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved.
        unsigned BO_VDD1P1 : 1; //!< [16] Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD1P1 : 1; //!< [17] Status bit that signals when the regulator output is ok.
        unsigned RESERVED2 : 14; //!< [31:18] Reserved.
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

/* --- Register HW_PMU_REG_1P1, field ENABLE_LINREG[0] (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_1P1_ENABLE_LINREG      (0)      //!< Bit position for PMU_REG_1P1_ENABLE_LINREG.
#define BM_PMU_REG_1P1_ENABLE_LINREG      (0x00000001)  //!< Bit mask for PMU_REG_1P1_ENABLE_LINREG.

//! @brief Get value of PMU_REG_1P1_ENABLE_LINREG from a register value.
#define BG_PMU_REG_1P1_ENABLE_LINREG(r)   (((r) & BM_PMU_REG_1P1_ENABLE_LINREG) >> BP_PMU_REG_1P1_ENABLE_LINREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_LINREG.
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_ENABLE_LINREG) & BM_PMU_REG_1P1_ENABLE_LINREG)
#else
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_LINREG.
#define BF_PMU_REG_1P1_ENABLE_LINREG(v)   (((v) << BP_PMU_REG_1P1_ENABLE_LINREG) & BM_PMU_REG_1P1_ENABLE_LINREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_1P1_ENABLE_LINREG(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_ENABLE_LINREG) | BF_PMU_REG_1P1_ENABLE_LINREG(v)))
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_BO[1] (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_1P1_ENABLE_BO      (1)      //!< Bit position for PMU_REG_1P1_ENABLE_BO.
#define BM_PMU_REG_1P1_ENABLE_BO      (0x00000002)  //!< Bit mask for PMU_REG_1P1_ENABLE_BO.

//! @brief Get value of PMU_REG_1P1_ENABLE_BO from a register value.
#define BG_PMU_REG_1P1_ENABLE_BO(r)   (((r) & BM_PMU_REG_1P1_ENABLE_BO) >> BP_PMU_REG_1P1_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_BO.
#define BF_PMU_REG_1P1_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_ENABLE_BO) & BM_PMU_REG_1P1_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_BO.
#define BF_PMU_REG_1P1_ENABLE_BO(v)   (((v) << BP_PMU_REG_1P1_ENABLE_BO) & BM_PMU_REG_1P1_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_1P1_ENABLE_BO(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_ENABLE_BO) | BF_PMU_REG_1P1_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_ILIMIT[2] (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_1P1_ENABLE_ILIMIT      (2)      //!< Bit position for PMU_REG_1P1_ENABLE_ILIMIT.
#define BM_PMU_REG_1P1_ENABLE_ILIMIT      (0x00000004)  //!< Bit mask for PMU_REG_1P1_ENABLE_ILIMIT.

//! @brief Get value of PMU_REG_1P1_ENABLE_ILIMIT from a register value.
#define BG_PMU_REG_1P1_ENABLE_ILIMIT(r)   (((r) & BM_PMU_REG_1P1_ENABLE_ILIMIT) >> BP_PMU_REG_1P1_ENABLE_ILIMIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_ILIMIT.
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_ENABLE_ILIMIT) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#else
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_ILIMIT.
#define BF_PMU_REG_1P1_ENABLE_ILIMIT(v)   (((v) << BP_PMU_REG_1P1_ENABLE_ILIMIT) & BM_PMU_REG_1P1_ENABLE_ILIMIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_1P1_ENABLE_ILIMIT(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_ENABLE_ILIMIT) | BF_PMU_REG_1P1_ENABLE_ILIMIT(v)))
#endif

/* --- Register HW_PMU_REG_1P1, field ENABLE_PULLDOWN[3] (RW)
 *
 * Control bit to enable the pull-down circuitry in the regulator
 */

#define BP_PMU_REG_1P1_ENABLE_PULLDOWN      (3)      //!< Bit position for PMU_REG_1P1_ENABLE_PULLDOWN.
#define BM_PMU_REG_1P1_ENABLE_PULLDOWN      (0x00000008)  //!< Bit mask for PMU_REG_1P1_ENABLE_PULLDOWN.

//! @brief Get value of PMU_REG_1P1_ENABLE_PULLDOWN from a register value.
#define BG_PMU_REG_1P1_ENABLE_PULLDOWN(r)   (((r) & BM_PMU_REG_1P1_ENABLE_PULLDOWN) >> BP_PMU_REG_1P1_ENABLE_PULLDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_PULLDOWN.
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_ENABLE_PULLDOWN) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#else
//! @brief Format value for bitfield PMU_REG_1P1_ENABLE_PULLDOWN.
#define BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)   (((v) << BP_PMU_REG_1P1_ENABLE_PULLDOWN) & BM_PMU_REG_1P1_ENABLE_PULLDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PULLDOWN field to a new value.
#define BW_PMU_REG_1P1_ENABLE_PULLDOWN(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_ENABLE_PULLDOWN) | BF_PMU_REG_1P1_ENABLE_PULLDOWN(v)))
#endif

/* --- Register HW_PMU_REG_1P1, field BO_OFFSET[6:4] (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_1P1_BO_OFFSET      (4)      //!< Bit position for PMU_REG_1P1_BO_OFFSET.
#define BM_PMU_REG_1P1_BO_OFFSET      (0x00000070)  //!< Bit mask for PMU_REG_1P1_BO_OFFSET.

//! @brief Get value of PMU_REG_1P1_BO_OFFSET from a register value.
#define BG_PMU_REG_1P1_BO_OFFSET(r)   (((r) & BM_PMU_REG_1P1_BO_OFFSET) >> BP_PMU_REG_1P1_BO_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_BO_OFFSET.
#define BF_PMU_REG_1P1_BO_OFFSET(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_BO_OFFSET) & BM_PMU_REG_1P1_BO_OFFSET)
#else
//! @brief Format value for bitfield PMU_REG_1P1_BO_OFFSET.
#define BF_PMU_REG_1P1_BO_OFFSET(v)   (((v) << BP_PMU_REG_1P1_BO_OFFSET) & BM_PMU_REG_1P1_BO_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_1P1_BO_OFFSET(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_BO_OFFSET) | BF_PMU_REG_1P1_BO_OFFSET(v)))
#endif

/* --- Register HW_PMU_REG_1P1, field OUTPUT_TRG[12:8] (RW)
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

#define BP_PMU_REG_1P1_OUTPUT_TRG      (8)      //!< Bit position for PMU_REG_1P1_OUTPUT_TRG.
#define BM_PMU_REG_1P1_OUTPUT_TRG      (0x00001f00)  //!< Bit mask for PMU_REG_1P1_OUTPUT_TRG.

//! @brief Get value of PMU_REG_1P1_OUTPUT_TRG from a register value.
#define BG_PMU_REG_1P1_OUTPUT_TRG(r)   (((r) & BM_PMU_REG_1P1_OUTPUT_TRG) >> BP_PMU_REG_1P1_OUTPUT_TRG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_1P1_OUTPUT_TRG.
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   ((((reg32_t) v) << BP_PMU_REG_1P1_OUTPUT_TRG) & BM_PMU_REG_1P1_OUTPUT_TRG)
#else
//! @brief Format value for bitfield PMU_REG_1P1_OUTPUT_TRG.
#define BF_PMU_REG_1P1_OUTPUT_TRG(v)   (((v) << BP_PMU_REG_1P1_OUTPUT_TRG) & BM_PMU_REG_1P1_OUTPUT_TRG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_1P1_OUTPUT_TRG(v)   (HW_PMU_REG_1P1_WR((HW_PMU_REG_1P1_RD() & ~BM_PMU_REG_1P1_OUTPUT_TRG) | BF_PMU_REG_1P1_OUTPUT_TRG(v)))
#endif


/* --- Register HW_PMU_REG_1P1, field BO_VDD1P1[16] (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_1P1_BO_VDD1P1      (16)      //!< Bit position for PMU_REG_1P1_BO_VDD1P1.
#define BM_PMU_REG_1P1_BO_VDD1P1      (0x00010000)  //!< Bit mask for PMU_REG_1P1_BO_VDD1P1.

//! @brief Get value of PMU_REG_1P1_BO_VDD1P1 from a register value.
#define BG_PMU_REG_1P1_BO_VDD1P1(r)   (((r) & BM_PMU_REG_1P1_BO_VDD1P1) >> BP_PMU_REG_1P1_BO_VDD1P1)

/* --- Register HW_PMU_REG_1P1, field OK_VDD1P1[17] (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_1P1_OK_VDD1P1      (17)      //!< Bit position for PMU_REG_1P1_OK_VDD1P1.
#define BM_PMU_REG_1P1_OK_VDD1P1      (0x00020000)  //!< Bit mask for PMU_REG_1P1_OK_VDD1P1.

//! @brief Get value of PMU_REG_1P1_OK_VDD1P1 from a register value.
#define BG_PMU_REG_1P1_OK_VDD1P1(r)   (((r) & BM_PMU_REG_1P1_OK_VDD1P1) >> BP_PMU_REG_1P1_OK_VDD1P1)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_3P0 - Regulator 3P0 Register (RW)
 *
 * Reset value: 0x00000f74
 *
 * This register defines the control and status bits for the 3.0V regulator powered by the host USB
 * VBUS pin.
 */
typedef union _hw_pmu_reg_3p0
{
    reg32_t U;
    struct _hw_pmu_reg_3p0_bitfields
    {
        unsigned ENABLE_LINREG : 1; //!< [0] Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< [1] Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< [2] Control bit to enable the current-limit circuitry in the regulator.
        unsigned RESERVED0 : 1; //!< [3] Reserved
        unsigned BO_OFFSET : 3; //!< [6:4] Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned REG_3P0_VBUS_SEL : 1; //!< [7] Reserved.
        unsigned OUTPUT_TRG : 5; //!< [12:8] Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved.
        unsigned BO_VDD3P0 : 1; //!< [16] Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD3P0 : 1; //!< [17] Status bit that signals when the regulator output is ok.
        unsigned RESERVED2 : 14; //!< [31:18] Reserved.
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

/* --- Register HW_PMU_REG_3P0, field ENABLE_LINREG[0] (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_3P0_ENABLE_LINREG      (0)      //!< Bit position for PMU_REG_3P0_ENABLE_LINREG.
#define BM_PMU_REG_3P0_ENABLE_LINREG      (0x00000001)  //!< Bit mask for PMU_REG_3P0_ENABLE_LINREG.

//! @brief Get value of PMU_REG_3P0_ENABLE_LINREG from a register value.
#define BG_PMU_REG_3P0_ENABLE_LINREG(r)   (((r) & BM_PMU_REG_3P0_ENABLE_LINREG) >> BP_PMU_REG_3P0_ENABLE_LINREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_LINREG.
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_ENABLE_LINREG) & BM_PMU_REG_3P0_ENABLE_LINREG)
#else
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_LINREG.
#define BF_PMU_REG_3P0_ENABLE_LINREG(v)   (((v) << BP_PMU_REG_3P0_ENABLE_LINREG) & BM_PMU_REG_3P0_ENABLE_LINREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_3P0_ENABLE_LINREG(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_ENABLE_LINREG) | BF_PMU_REG_3P0_ENABLE_LINREG(v)))
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_BO[1] (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_3P0_ENABLE_BO      (1)      //!< Bit position for PMU_REG_3P0_ENABLE_BO.
#define BM_PMU_REG_3P0_ENABLE_BO      (0x00000002)  //!< Bit mask for PMU_REG_3P0_ENABLE_BO.

//! @brief Get value of PMU_REG_3P0_ENABLE_BO from a register value.
#define BG_PMU_REG_3P0_ENABLE_BO(r)   (((r) & BM_PMU_REG_3P0_ENABLE_BO) >> BP_PMU_REG_3P0_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_BO.
#define BF_PMU_REG_3P0_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_ENABLE_BO) & BM_PMU_REG_3P0_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_BO.
#define BF_PMU_REG_3P0_ENABLE_BO(v)   (((v) << BP_PMU_REG_3P0_ENABLE_BO) & BM_PMU_REG_3P0_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_3P0_ENABLE_BO(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_ENABLE_BO) | BF_PMU_REG_3P0_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_3P0, field ENABLE_ILIMIT[2] (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_3P0_ENABLE_ILIMIT      (2)      //!< Bit position for PMU_REG_3P0_ENABLE_ILIMIT.
#define BM_PMU_REG_3P0_ENABLE_ILIMIT      (0x00000004)  //!< Bit mask for PMU_REG_3P0_ENABLE_ILIMIT.

//! @brief Get value of PMU_REG_3P0_ENABLE_ILIMIT from a register value.
#define BG_PMU_REG_3P0_ENABLE_ILIMIT(r)   (((r) & BM_PMU_REG_3P0_ENABLE_ILIMIT) >> BP_PMU_REG_3P0_ENABLE_ILIMIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_ILIMIT.
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_ENABLE_ILIMIT) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#else
//! @brief Format value for bitfield PMU_REG_3P0_ENABLE_ILIMIT.
#define BF_PMU_REG_3P0_ENABLE_ILIMIT(v)   (((v) << BP_PMU_REG_3P0_ENABLE_ILIMIT) & BM_PMU_REG_3P0_ENABLE_ILIMIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_3P0_ENABLE_ILIMIT(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_ENABLE_ILIMIT) | BF_PMU_REG_3P0_ENABLE_ILIMIT(v)))
#endif

/* --- Register HW_PMU_REG_3P0, field BO_OFFSET[6:4] (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_3P0_BO_OFFSET      (4)      //!< Bit position for PMU_REG_3P0_BO_OFFSET.
#define BM_PMU_REG_3P0_BO_OFFSET      (0x00000070)  //!< Bit mask for PMU_REG_3P0_BO_OFFSET.

//! @brief Get value of PMU_REG_3P0_BO_OFFSET from a register value.
#define BG_PMU_REG_3P0_BO_OFFSET(r)   (((r) & BM_PMU_REG_3P0_BO_OFFSET) >> BP_PMU_REG_3P0_BO_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_BO_OFFSET.
#define BF_PMU_REG_3P0_BO_OFFSET(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_BO_OFFSET) & BM_PMU_REG_3P0_BO_OFFSET)
#else
//! @brief Format value for bitfield PMU_REG_3P0_BO_OFFSET.
#define BF_PMU_REG_3P0_BO_OFFSET(v)   (((v) << BP_PMU_REG_3P0_BO_OFFSET) & BM_PMU_REG_3P0_BO_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_3P0_BO_OFFSET(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_BO_OFFSET) | BF_PMU_REG_3P0_BO_OFFSET(v)))
#endif

/* --- Register HW_PMU_REG_3P0, field REG_3P0_VBUS_SEL[7] (RW)
 *
 * Reserved.
 *
 * Values:
 * 0 - Utilize host power
 * 1 - Utilize OTG power
 */

#define BP_PMU_REG_3P0_REG_3P0_VBUS_SEL      (7)      //!< Bit position for PMU_REG_3P0_REG_3P0_VBUS_SEL.
#define BM_PMU_REG_3P0_REG_3P0_VBUS_SEL      (0x00000080)  //!< Bit mask for PMU_REG_3P0_REG_3P0_VBUS_SEL.

//! @brief Get value of PMU_REG_3P0_REG_3P0_VBUS_SEL from a register value.
#define BG_PMU_REG_3P0_REG_3P0_VBUS_SEL(r)   (((r) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL) >> BP_PMU_REG_3P0_REG_3P0_VBUS_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_REG_3P0_VBUS_SEL.
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_REG_3P0_VBUS_SEL) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#else
//! @brief Format value for bitfield PMU_REG_3P0_REG_3P0_VBUS_SEL.
#define BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   (((v) << BP_PMU_REG_3P0_REG_3P0_VBUS_SEL) & BM_PMU_REG_3P0_REG_3P0_VBUS_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG_3P0_VBUS_SEL field to a new value.
#define BW_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_REG_3P0_VBUS_SEL) | BF_PMU_REG_3P0_REG_3P0_VBUS_SEL(v)))
#endif


/* --- Register HW_PMU_REG_3P0, field OUTPUT_TRG[12:8] (RW)
 *
 * Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip
 * functionality at the extremes of the programming range.
 *
 * Values:
 * 0000 - 2.625V
 * 0111 - 3.000V
 * 1111 - 3.400V
 */

#define BP_PMU_REG_3P0_OUTPUT_TRG      (8)      //!< Bit position for PMU_REG_3P0_OUTPUT_TRG.
#define BM_PMU_REG_3P0_OUTPUT_TRG      (0x00001f00)  //!< Bit mask for PMU_REG_3P0_OUTPUT_TRG.

//! @brief Get value of PMU_REG_3P0_OUTPUT_TRG from a register value.
#define BG_PMU_REG_3P0_OUTPUT_TRG(r)   (((r) & BM_PMU_REG_3P0_OUTPUT_TRG) >> BP_PMU_REG_3P0_OUTPUT_TRG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_3P0_OUTPUT_TRG.
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   ((((reg32_t) v) << BP_PMU_REG_3P0_OUTPUT_TRG) & BM_PMU_REG_3P0_OUTPUT_TRG)
#else
//! @brief Format value for bitfield PMU_REG_3P0_OUTPUT_TRG.
#define BF_PMU_REG_3P0_OUTPUT_TRG(v)   (((v) << BP_PMU_REG_3P0_OUTPUT_TRG) & BM_PMU_REG_3P0_OUTPUT_TRG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_3P0_OUTPUT_TRG(v)   (HW_PMU_REG_3P0_WR((HW_PMU_REG_3P0_RD() & ~BM_PMU_REG_3P0_OUTPUT_TRG) | BF_PMU_REG_3P0_OUTPUT_TRG(v)))
#endif


/* --- Register HW_PMU_REG_3P0, field BO_VDD3P0[16] (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_3P0_BO_VDD3P0      (16)      //!< Bit position for PMU_REG_3P0_BO_VDD3P0.
#define BM_PMU_REG_3P0_BO_VDD3P0      (0x00010000)  //!< Bit mask for PMU_REG_3P0_BO_VDD3P0.

//! @brief Get value of PMU_REG_3P0_BO_VDD3P0 from a register value.
#define BG_PMU_REG_3P0_BO_VDD3P0(r)   (((r) & BM_PMU_REG_3P0_BO_VDD3P0) >> BP_PMU_REG_3P0_BO_VDD3P0)

/* --- Register HW_PMU_REG_3P0, field OK_VDD3P0[17] (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_3P0_OK_VDD3P0      (17)      //!< Bit position for PMU_REG_3P0_OK_VDD3P0.
#define BM_PMU_REG_3P0_OK_VDD3P0      (0x00020000)  //!< Bit mask for PMU_REG_3P0_OK_VDD3P0.

//! @brief Get value of PMU_REG_3P0_OK_VDD3P0 from a register value.
#define BG_PMU_REG_3P0_OK_VDD3P0(r)   (((r) & BM_PMU_REG_3P0_OK_VDD3P0) >> BP_PMU_REG_3P0_OK_VDD3P0)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_2P5 - Regulator 2P5 Register (RW)
 *
 * Reset value: 0x00004211
 *
 * This register defines the control and status bits for the 2.5V regulator.
 */
typedef union _hw_pmu_reg_2p5
{
    reg32_t U;
    struct _hw_pmu_reg_2p5_bitfields
    {
        unsigned ENABLE_LINREG : 1; //!< [0] Control bit to enable the regulator output.
        unsigned ENABLE_BO : 1; //!< [1] Control bit to enable the brown-out circuitry in the regulator.
        unsigned ENABLE_ILIMIT : 1; //!< [2] Control bit to enable the current-limit circuitry in the regulator.
        unsigned ENABLE_PULLDOWN : 1; //!< [3] Control bit to enable the pull-down circuitry in the regulator
        unsigned BO_OFFSET : 3; //!< [6:4] Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is 75mV below the programmed target code.
        unsigned RESERVED0 : 1; //!< [7] Reserved.
        unsigned OUTPUT_TRG : 5; //!< [12:8] Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip functionality at the extremes of the programming range.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved.
        unsigned BO_VDD2P5 : 1; //!< [16] Status bit that signals when a brown-out is detected on the regulator output.
        unsigned OK_VDD2P5 : 1; //!< [17] Status bit that signals when the regulator output is ok.
        unsigned ENABLE_WEAK_LINREG : 1; //!< [18] Enables the weak 2p5 regulator. This regulator is used when the main 2p5 regulator is disabled to keep the 2.5V output roughly at 2.5V. Depends directly on the value of VDDIO.
        unsigned RESERVED2 : 13; //!< [31:19] Reserved.
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

/* --- Register HW_PMU_REG_2P5, field ENABLE_LINREG[0] (RW)
 *
 * Control bit to enable the regulator output.
 */

#define BP_PMU_REG_2P5_ENABLE_LINREG      (0)      //!< Bit position for PMU_REG_2P5_ENABLE_LINREG.
#define BM_PMU_REG_2P5_ENABLE_LINREG      (0x00000001)  //!< Bit mask for PMU_REG_2P5_ENABLE_LINREG.

//! @brief Get value of PMU_REG_2P5_ENABLE_LINREG from a register value.
#define BG_PMU_REG_2P5_ENABLE_LINREG(r)   (((r) & BM_PMU_REG_2P5_ENABLE_LINREG) >> BP_PMU_REG_2P5_ENABLE_LINREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_LINREG.
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_ENABLE_LINREG) & BM_PMU_REG_2P5_ENABLE_LINREG)
#else
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_LINREG.
#define BF_PMU_REG_2P5_ENABLE_LINREG(v)   (((v) << BP_PMU_REG_2P5_ENABLE_LINREG) & BM_PMU_REG_2P5_ENABLE_LINREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_LINREG field to a new value.
#define BW_PMU_REG_2P5_ENABLE_LINREG(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_ENABLE_LINREG) | BF_PMU_REG_2P5_ENABLE_LINREG(v)))
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_BO[1] (RW)
 *
 * Control bit to enable the brown-out circuitry in the regulator.
 */

#define BP_PMU_REG_2P5_ENABLE_BO      (1)      //!< Bit position for PMU_REG_2P5_ENABLE_BO.
#define BM_PMU_REG_2P5_ENABLE_BO      (0x00000002)  //!< Bit mask for PMU_REG_2P5_ENABLE_BO.

//! @brief Get value of PMU_REG_2P5_ENABLE_BO from a register value.
#define BG_PMU_REG_2P5_ENABLE_BO(r)   (((r) & BM_PMU_REG_2P5_ENABLE_BO) >> BP_PMU_REG_2P5_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_BO.
#define BF_PMU_REG_2P5_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_ENABLE_BO) & BM_PMU_REG_2P5_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_BO.
#define BF_PMU_REG_2P5_ENABLE_BO(v)   (((v) << BP_PMU_REG_2P5_ENABLE_BO) & BM_PMU_REG_2P5_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_BO field to a new value.
#define BW_PMU_REG_2P5_ENABLE_BO(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_ENABLE_BO) | BF_PMU_REG_2P5_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_ILIMIT[2] (RW)
 *
 * Control bit to enable the current-limit circuitry in the regulator.
 */

#define BP_PMU_REG_2P5_ENABLE_ILIMIT      (2)      //!< Bit position for PMU_REG_2P5_ENABLE_ILIMIT.
#define BM_PMU_REG_2P5_ENABLE_ILIMIT      (0x00000004)  //!< Bit mask for PMU_REG_2P5_ENABLE_ILIMIT.

//! @brief Get value of PMU_REG_2P5_ENABLE_ILIMIT from a register value.
#define BG_PMU_REG_2P5_ENABLE_ILIMIT(r)   (((r) & BM_PMU_REG_2P5_ENABLE_ILIMIT) >> BP_PMU_REG_2P5_ENABLE_ILIMIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_ILIMIT.
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_ENABLE_ILIMIT) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#else
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_ILIMIT.
#define BF_PMU_REG_2P5_ENABLE_ILIMIT(v)   (((v) << BP_PMU_REG_2P5_ENABLE_ILIMIT) & BM_PMU_REG_2P5_ENABLE_ILIMIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_ILIMIT field to a new value.
#define BW_PMU_REG_2P5_ENABLE_ILIMIT(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_ENABLE_ILIMIT) | BF_PMU_REG_2P5_ENABLE_ILIMIT(v)))
#endif

/* --- Register HW_PMU_REG_2P5, field ENABLE_PULLDOWN[3] (RW)
 *
 * Control bit to enable the pull-down circuitry in the regulator
 */

#define BP_PMU_REG_2P5_ENABLE_PULLDOWN      (3)      //!< Bit position for PMU_REG_2P5_ENABLE_PULLDOWN.
#define BM_PMU_REG_2P5_ENABLE_PULLDOWN      (0x00000008)  //!< Bit mask for PMU_REG_2P5_ENABLE_PULLDOWN.

//! @brief Get value of PMU_REG_2P5_ENABLE_PULLDOWN from a register value.
#define BG_PMU_REG_2P5_ENABLE_PULLDOWN(r)   (((r) & BM_PMU_REG_2P5_ENABLE_PULLDOWN) >> BP_PMU_REG_2P5_ENABLE_PULLDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_PULLDOWN.
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_ENABLE_PULLDOWN) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#else
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_PULLDOWN.
#define BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)   (((v) << BP_PMU_REG_2P5_ENABLE_PULLDOWN) & BM_PMU_REG_2P5_ENABLE_PULLDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PULLDOWN field to a new value.
#define BW_PMU_REG_2P5_ENABLE_PULLDOWN(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_ENABLE_PULLDOWN) | BF_PMU_REG_2P5_ENABLE_PULLDOWN(v)))
#endif

/* --- Register HW_PMU_REG_2P5, field BO_OFFSET[6:4] (RW)
 *
 * Control bits to adjust the regulator brown-out offset voltage in 25mV steps. The brown-offset is
 * 75mV below the programmed target code.
 */

#define BP_PMU_REG_2P5_BO_OFFSET      (4)      //!< Bit position for PMU_REG_2P5_BO_OFFSET.
#define BM_PMU_REG_2P5_BO_OFFSET      (0x00000070)  //!< Bit mask for PMU_REG_2P5_BO_OFFSET.

//! @brief Get value of PMU_REG_2P5_BO_OFFSET from a register value.
#define BG_PMU_REG_2P5_BO_OFFSET(r)   (((r) & BM_PMU_REG_2P5_BO_OFFSET) >> BP_PMU_REG_2P5_BO_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_BO_OFFSET.
#define BF_PMU_REG_2P5_BO_OFFSET(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_BO_OFFSET) & BM_PMU_REG_2P5_BO_OFFSET)
#else
//! @brief Format value for bitfield PMU_REG_2P5_BO_OFFSET.
#define BF_PMU_REG_2P5_BO_OFFSET(v)   (((v) << BP_PMU_REG_2P5_BO_OFFSET) & BM_PMU_REG_2P5_BO_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BO_OFFSET field to a new value.
#define BW_PMU_REG_2P5_BO_OFFSET(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_BO_OFFSET) | BF_PMU_REG_2P5_BO_OFFSET(v)))
#endif

/* --- Register HW_PMU_REG_2P5, field OUTPUT_TRG[12:8] (RW)
 *
 * Control bits to adjust the regulator output voltage in 25mV steps. There may be reduced chip
 * functionality at the extremes of the programming range.
 *
 * Values:
 * 0000 - 2.00V
 * 1110 - 2.50V
 * 1111 - 2.75V
 */

#define BP_PMU_REG_2P5_OUTPUT_TRG      (8)      //!< Bit position for PMU_REG_2P5_OUTPUT_TRG.
#define BM_PMU_REG_2P5_OUTPUT_TRG      (0x00001f00)  //!< Bit mask for PMU_REG_2P5_OUTPUT_TRG.

//! @brief Get value of PMU_REG_2P5_OUTPUT_TRG from a register value.
#define BG_PMU_REG_2P5_OUTPUT_TRG(r)   (((r) & BM_PMU_REG_2P5_OUTPUT_TRG) >> BP_PMU_REG_2P5_OUTPUT_TRG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_OUTPUT_TRG.
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_OUTPUT_TRG) & BM_PMU_REG_2P5_OUTPUT_TRG)
#else
//! @brief Format value for bitfield PMU_REG_2P5_OUTPUT_TRG.
#define BF_PMU_REG_2P5_OUTPUT_TRG(v)   (((v) << BP_PMU_REG_2P5_OUTPUT_TRG) & BM_PMU_REG_2P5_OUTPUT_TRG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTPUT_TRG field to a new value.
#define BW_PMU_REG_2P5_OUTPUT_TRG(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_OUTPUT_TRG) | BF_PMU_REG_2P5_OUTPUT_TRG(v)))
#endif


/* --- Register HW_PMU_REG_2P5, field BO_VDD2P5[16] (RO)
 *
 * Status bit that signals when a brown-out is detected on the regulator output.
 */

#define BP_PMU_REG_2P5_BO_VDD2P5      (16)      //!< Bit position for PMU_REG_2P5_BO_VDD2P5.
#define BM_PMU_REG_2P5_BO_VDD2P5      (0x00010000)  //!< Bit mask for PMU_REG_2P5_BO_VDD2P5.

//! @brief Get value of PMU_REG_2P5_BO_VDD2P5 from a register value.
#define BG_PMU_REG_2P5_BO_VDD2P5(r)   (((r) & BM_PMU_REG_2P5_BO_VDD2P5) >> BP_PMU_REG_2P5_BO_VDD2P5)

/* --- Register HW_PMU_REG_2P5, field OK_VDD2P5[17] (RO)
 *
 * Status bit that signals when the regulator output is ok.
 */

#define BP_PMU_REG_2P5_OK_VDD2P5      (17)      //!< Bit position for PMU_REG_2P5_OK_VDD2P5.
#define BM_PMU_REG_2P5_OK_VDD2P5      (0x00020000)  //!< Bit mask for PMU_REG_2P5_OK_VDD2P5.

//! @brief Get value of PMU_REG_2P5_OK_VDD2P5 from a register value.
#define BG_PMU_REG_2P5_OK_VDD2P5(r)   (((r) & BM_PMU_REG_2P5_OK_VDD2P5) >> BP_PMU_REG_2P5_OK_VDD2P5)

/* --- Register HW_PMU_REG_2P5, field ENABLE_WEAK_LINREG[18] (RW)
 *
 * Enables the weak 2p5 regulator. This regulator is used when the main 2p5 regulator is disabled to
 * keep the 2.5V output roughly at 2.5V. Depends directly on the value of VDDIO.
 */

#define BP_PMU_REG_2P5_ENABLE_WEAK_LINREG      (18)      //!< Bit position for PMU_REG_2P5_ENABLE_WEAK_LINREG.
#define BM_PMU_REG_2P5_ENABLE_WEAK_LINREG      (0x00040000)  //!< Bit mask for PMU_REG_2P5_ENABLE_WEAK_LINREG.

//! @brief Get value of PMU_REG_2P5_ENABLE_WEAK_LINREG from a register value.
#define BG_PMU_REG_2P5_ENABLE_WEAK_LINREG(r)   (((r) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG) >> BP_PMU_REG_2P5_ENABLE_WEAK_LINREG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_WEAK_LINREG.
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   ((((reg32_t) v) << BP_PMU_REG_2P5_ENABLE_WEAK_LINREG) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#else
//! @brief Format value for bitfield PMU_REG_2P5_ENABLE_WEAK_LINREG.
#define BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   (((v) << BP_PMU_REG_2P5_ENABLE_WEAK_LINREG) & BM_PMU_REG_2P5_ENABLE_WEAK_LINREG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_WEAK_LINREG field to a new value.
#define BW_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)   (HW_PMU_REG_2P5_WR((HW_PMU_REG_2P5_RD() & ~BM_PMU_REG_2P5_ENABLE_WEAK_LINREG) | BF_PMU_REG_2P5_ENABLE_WEAK_LINREG(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_CORE - Digital Regulator Core Register (RW)
 *
 * Reset value: 0x00402010
 *
 * This register defines the function of the digital regulators
 */
typedef union _hw_pmu_reg_core
{
    reg32_t U;
    struct _hw_pmu_reg_core_bitfields
    {
        unsigned REG0_TRIG : 5; //!< [4:0] This bitfield defines the target voltage for the arm core power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG0_ADJ : 4; //!< [8:5] This bitfield defines the adjustment bits to calibrate the target value of REG1 (ARM_CORE). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned REG1_TRIG : 5; //!< [13:9] This bitfield defines the target voltage for the VPU/GPU power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG1_ADJ : 4; //!< [17:14] This bitfield defines the adjustment bits to calibrate the target value of REG1 (REG_PU). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned REG2_TRIG : 5; //!< [22:18] This bitfield defines the target voltage for the SOC power domain. Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG2_ADJ : 4; //!< [26:23] This bitfield defines the adjustment bits to calibrate the target value of REG2 (REG_SOC). The adjustment is applied on top of any adjustment applied to the global reference in the MISC0 Register.
        unsigned RAMP_RATE : 2; //!< [28:27] Regulator voltage ramp rate.
        unsigned FET_ODRIVE : 1; //!< [29] If set, increases the gate drive on power gating fets to reduce leakage in the off state. Care must be taken to only apply this bit when the input supply voltage to the power fet is less than 1.1V. This bit should only be used in low power modes where the external input supply voltage is nominally 0.9V.
        unsigned RESERVED0 : 2; //!< [31:30] Reserved.
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

/* --- Register HW_PMU_REG_CORE, field REG0_TRIG[4:0] (RW)
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

#define BP_PMU_REG_CORE_REG0_TRIG      (0)      //!< Bit position for PMU_REG_CORE_REG0_TRIG.
#define BM_PMU_REG_CORE_REG0_TRIG      (0x0000001f)  //!< Bit mask for PMU_REG_CORE_REG0_TRIG.

//! @brief Get value of PMU_REG_CORE_REG0_TRIG from a register value.
#define BG_PMU_REG_CORE_REG0_TRIG(r)   (((r) & BM_PMU_REG_CORE_REG0_TRIG) >> BP_PMU_REG_CORE_REG0_TRIG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG0_TRIG.
#define BF_PMU_REG_CORE_REG0_TRIG(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG0_TRIG) & BM_PMU_REG_CORE_REG0_TRIG)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG0_TRIG.
#define BF_PMU_REG_CORE_REG0_TRIG(v)   (((v) << BP_PMU_REG_CORE_REG0_TRIG) & BM_PMU_REG_CORE_REG0_TRIG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG0_TRIG(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG0_TRIG) | BF_PMU_REG_CORE_REG0_TRIG(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field REG0_ADJ[8:5] (RW)
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

#define BP_PMU_REG_CORE_REG0_ADJ      (5)      //!< Bit position for PMU_REG_CORE_REG0_ADJ.
#define BM_PMU_REG_CORE_REG0_ADJ      (0x000001e0)  //!< Bit mask for PMU_REG_CORE_REG0_ADJ.

//! @brief Get value of PMU_REG_CORE_REG0_ADJ from a register value.
#define BG_PMU_REG_CORE_REG0_ADJ(r)   (((r) & BM_PMU_REG_CORE_REG0_ADJ) >> BP_PMU_REG_CORE_REG0_ADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG0_ADJ.
#define BF_PMU_REG_CORE_REG0_ADJ(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG0_ADJ) & BM_PMU_REG_CORE_REG0_ADJ)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG0_ADJ.
#define BF_PMU_REG_CORE_REG0_ADJ(v)   (((v) << BP_PMU_REG_CORE_REG0_ADJ) & BM_PMU_REG_CORE_REG0_ADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG0_ADJ(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG0_ADJ) | BF_PMU_REG_CORE_REG0_ADJ(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field REG1_TRIG[13:9] (RW)
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

#define BP_PMU_REG_CORE_REG1_TRIG      (9)      //!< Bit position for PMU_REG_CORE_REG1_TRIG.
#define BM_PMU_REG_CORE_REG1_TRIG      (0x00003e00)  //!< Bit mask for PMU_REG_CORE_REG1_TRIG.

//! @brief Get value of PMU_REG_CORE_REG1_TRIG from a register value.
#define BG_PMU_REG_CORE_REG1_TRIG(r)   (((r) & BM_PMU_REG_CORE_REG1_TRIG) >> BP_PMU_REG_CORE_REG1_TRIG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG1_TRIG.
#define BF_PMU_REG_CORE_REG1_TRIG(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG1_TRIG) & BM_PMU_REG_CORE_REG1_TRIG)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG1_TRIG.
#define BF_PMU_REG_CORE_REG1_TRIG(v)   (((v) << BP_PMU_REG_CORE_REG1_TRIG) & BM_PMU_REG_CORE_REG1_TRIG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG1_TRIG(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG1_TRIG) | BF_PMU_REG_CORE_REG1_TRIG(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field REG1_ADJ[17:14] (RW)
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

#define BP_PMU_REG_CORE_REG1_ADJ      (14)      //!< Bit position for PMU_REG_CORE_REG1_ADJ.
#define BM_PMU_REG_CORE_REG1_ADJ      (0x0003c000)  //!< Bit mask for PMU_REG_CORE_REG1_ADJ.

//! @brief Get value of PMU_REG_CORE_REG1_ADJ from a register value.
#define BG_PMU_REG_CORE_REG1_ADJ(r)   (((r) & BM_PMU_REG_CORE_REG1_ADJ) >> BP_PMU_REG_CORE_REG1_ADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG1_ADJ.
#define BF_PMU_REG_CORE_REG1_ADJ(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG1_ADJ) & BM_PMU_REG_CORE_REG1_ADJ)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG1_ADJ.
#define BF_PMU_REG_CORE_REG1_ADJ(v)   (((v) << BP_PMU_REG_CORE_REG1_ADJ) & BM_PMU_REG_CORE_REG1_ADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG1_ADJ(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG1_ADJ) | BF_PMU_REG_CORE_REG1_ADJ(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field REG2_TRIG[22:18] (RW)
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

#define BP_PMU_REG_CORE_REG2_TRIG      (18)      //!< Bit position for PMU_REG_CORE_REG2_TRIG.
#define BM_PMU_REG_CORE_REG2_TRIG      (0x007c0000)  //!< Bit mask for PMU_REG_CORE_REG2_TRIG.

//! @brief Get value of PMU_REG_CORE_REG2_TRIG from a register value.
#define BG_PMU_REG_CORE_REG2_TRIG(r)   (((r) & BM_PMU_REG_CORE_REG2_TRIG) >> BP_PMU_REG_CORE_REG2_TRIG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG2_TRIG.
#define BF_PMU_REG_CORE_REG2_TRIG(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG2_TRIG) & BM_PMU_REG_CORE_REG2_TRIG)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG2_TRIG.
#define BF_PMU_REG_CORE_REG2_TRIG(v)   (((v) << BP_PMU_REG_CORE_REG2_TRIG) & BM_PMU_REG_CORE_REG2_TRIG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_TRIG field to a new value.
#define BW_PMU_REG_CORE_REG2_TRIG(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG2_TRIG) | BF_PMU_REG_CORE_REG2_TRIG(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field REG2_ADJ[26:23] (RW)
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

#define BP_PMU_REG_CORE_REG2_ADJ      (23)      //!< Bit position for PMU_REG_CORE_REG2_ADJ.
#define BM_PMU_REG_CORE_REG2_ADJ      (0x07800000)  //!< Bit mask for PMU_REG_CORE_REG2_ADJ.

//! @brief Get value of PMU_REG_CORE_REG2_ADJ from a register value.
#define BG_PMU_REG_CORE_REG2_ADJ(r)   (((r) & BM_PMU_REG_CORE_REG2_ADJ) >> BP_PMU_REG_CORE_REG2_ADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_REG2_ADJ.
#define BF_PMU_REG_CORE_REG2_ADJ(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_REG2_ADJ) & BM_PMU_REG_CORE_REG2_ADJ)
#else
//! @brief Format value for bitfield PMU_REG_CORE_REG2_ADJ.
#define BF_PMU_REG_CORE_REG2_ADJ(v)   (((v) << BP_PMU_REG_CORE_REG2_ADJ) & BM_PMU_REG_CORE_REG2_ADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_ADJ field to a new value.
#define BW_PMU_REG_CORE_REG2_ADJ(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_REG2_ADJ) | BF_PMU_REG_CORE_REG2_ADJ(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field RAMP_RATE[28:27] (RW)
 *
 * Regulator voltage ramp rate.
 *
 * Values:
 * 00 - Fast
 * 01 - Medium Fast
 * 10 - Medium Slow
 * 11 - Slow
 */

#define BP_PMU_REG_CORE_RAMP_RATE      (27)      //!< Bit position for PMU_REG_CORE_RAMP_RATE.
#define BM_PMU_REG_CORE_RAMP_RATE      (0x18000000)  //!< Bit mask for PMU_REG_CORE_RAMP_RATE.

//! @brief Get value of PMU_REG_CORE_RAMP_RATE from a register value.
#define BG_PMU_REG_CORE_RAMP_RATE(r)   (((r) & BM_PMU_REG_CORE_RAMP_RATE) >> BP_PMU_REG_CORE_RAMP_RATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_RAMP_RATE.
#define BF_PMU_REG_CORE_RAMP_RATE(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_RAMP_RATE) & BM_PMU_REG_CORE_RAMP_RATE)
#else
//! @brief Format value for bitfield PMU_REG_CORE_RAMP_RATE.
#define BF_PMU_REG_CORE_RAMP_RATE(v)   (((v) << BP_PMU_REG_CORE_RAMP_RATE) & BM_PMU_REG_CORE_RAMP_RATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RAMP_RATE field to a new value.
#define BW_PMU_REG_CORE_RAMP_RATE(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_RAMP_RATE) | BF_PMU_REG_CORE_RAMP_RATE(v)))
#endif


/* --- Register HW_PMU_REG_CORE, field FET_ODRIVE[29] (RW)
 *
 * If set, increases the gate drive on power gating fets to reduce leakage in the off state. Care
 * must be taken to only apply this bit when the input supply voltage to the power fet is less than
 * 1.1V. This bit should only be used in low power modes where the external input supply voltage is
 * nominally 0.9V.
 */

#define BP_PMU_REG_CORE_FET_ODRIVE      (29)      //!< Bit position for PMU_REG_CORE_FET_ODRIVE.
#define BM_PMU_REG_CORE_FET_ODRIVE      (0x20000000)  //!< Bit mask for PMU_REG_CORE_FET_ODRIVE.

//! @brief Get value of PMU_REG_CORE_FET_ODRIVE from a register value.
#define BG_PMU_REG_CORE_FET_ODRIVE(r)   (((r) & BM_PMU_REG_CORE_FET_ODRIVE) >> BP_PMU_REG_CORE_FET_ODRIVE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_CORE_FET_ODRIVE.
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   ((((reg32_t) v) << BP_PMU_REG_CORE_FET_ODRIVE) & BM_PMU_REG_CORE_FET_ODRIVE)
#else
//! @brief Format value for bitfield PMU_REG_CORE_FET_ODRIVE.
#define BF_PMU_REG_CORE_FET_ODRIVE(v)   (((v) << BP_PMU_REG_CORE_FET_ODRIVE) & BM_PMU_REG_CORE_FET_ODRIVE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FET_ODRIVE field to a new value.
#define BW_PMU_REG_CORE_FET_ODRIVE(v)   (HW_PMU_REG_CORE_WR((HW_PMU_REG_CORE_RD() & ~BM_PMU_REG_CORE_FET_ODRIVE) | BF_PMU_REG_CORE_FET_ODRIVE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_MISC0 - Miscellaneous Register 0 (RW)
 *
 * Reset value: 0x04000000
 *
 * This register defines the control and status bits for miscellaneous analog blocks.
 */
typedef union _hw_pmu_misc0
{
    reg32_t U;
    struct _hw_pmu_misc0_bitfields
    {
        unsigned REFTOP_PWD : 1; //!< [0] Control bit to power-down the analog bandgap reference circuitry. A note of caution, the bandgap is necessary for correct operation of most of the LDO, pll, and other analog functions on the die.
        unsigned RESERVED0 : 2; //!< [2:1] Reserved
        unsigned REFTOP_SELFBIASOFF : 1; //!< [3] Control bit to disable the self-bias circuit in the analog bandgap. The self-bias circuit is used by the bandgap during startup. This bit should be set after the bandgap has stabilized and is necessary for best noise performance of analog blocks using the outputs of the bandgap. Value should be returned to zero before removing vddhigh_in or asserting bit 0 of this register (REFTOP_PWD) to assure proper restart of the circuit.
        unsigned REFTOP_VBGADJ : 3; //!< [6:4] 
        unsigned REFTOP_VBGUP : 1; //!< [7] Status bit which signals that the analog bandgap voltage is up and stable. 1 - Stable. Not related to PMU.
        unsigned RESERVED1 : 4; //!< [11:8] Reserved
        unsigned STOP_MODE_CONFIG : 1; //!< [12] Configure the analog behavior in stop mode. Not related to PMU.
        unsigned RESERVED2 : 1; //!< [13] Reserved
        unsigned OSC_I : 2; //!< [15:14] This bit field determines the bias current in the 24MHz oscillator. The idea is to start up with the highest bias current which can be decreased after startup if determined to be acceptable. Not related to PMU.
        unsigned OSC_XTALOK : 1; //!< [16] Status bit which signals that the output of the 24MHz crystal oscillator is stable. Generated from a timer and active detection of the actual frequency. Not related to PMU.
        unsigned OSC_XTALOK_EN : 1; //!< [17] Not related to PMU.
        unsigned WBCP_VPW_THRESH : 2; //!< [19:18] This signal alters the voltage that the pwell is charged pumped to. Not related to PMU.
        unsigned RESERVED3 : 5; //!< [24:20] Reserved. Always set to zero.
        unsigned CLKGATE_CTRL : 1; //!< [25] This bit allows disabling the clock gate (always un-gated) for the xtal 24MHz clock that clocks the digital logic in the analog block. Do not change the field during a low power event. This is not a field that the user would normally need to modify Not related to PMU.
        unsigned CLKGATE_DELAY : 3; //!< [28:26] This field specifies the delay between powering up the XTAL 24MHz clock and release the clock to the digital logic inside the analog block. Do not change the field during a low power event. This is not a field that the user would normally need to modify Not related to PMU.
        unsigned RESERVED4 : 3; //!< [31:29] Reserved
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

/* --- Register HW_PMU_MISC0, field REFTOP_PWD[0] (RW)
 *
 * Control bit to power-down the analog bandgap reference circuitry. A note of caution, the bandgap
 * is necessary for correct operation of most of the LDO, pll, and other analog functions on the
 * die.
 */

#define BP_PMU_MISC0_REFTOP_PWD      (0)      //!< Bit position for PMU_MISC0_REFTOP_PWD.
#define BM_PMU_MISC0_REFTOP_PWD      (0x00000001)  //!< Bit mask for PMU_MISC0_REFTOP_PWD.

//! @brief Get value of PMU_MISC0_REFTOP_PWD from a register value.
#define BG_PMU_MISC0_REFTOP_PWD(r)   (((r) & BM_PMU_MISC0_REFTOP_PWD) >> BP_PMU_MISC0_REFTOP_PWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_REFTOP_PWD.
#define BF_PMU_MISC0_REFTOP_PWD(v)   ((((reg32_t) v) << BP_PMU_MISC0_REFTOP_PWD) & BM_PMU_MISC0_REFTOP_PWD)
#else
//! @brief Format value for bitfield PMU_MISC0_REFTOP_PWD.
#define BF_PMU_MISC0_REFTOP_PWD(v)   (((v) << BP_PMU_MISC0_REFTOP_PWD) & BM_PMU_MISC0_REFTOP_PWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_PWD field to a new value.
#define BW_PMU_MISC0_REFTOP_PWD(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_REFTOP_PWD) | BF_PMU_MISC0_REFTOP_PWD(v)))
#endif

/* --- Register HW_PMU_MISC0, field REFTOP_SELFBIASOFF[3] (RW)
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

#define BP_PMU_MISC0_REFTOP_SELFBIASOFF      (3)      //!< Bit position for PMU_MISC0_REFTOP_SELFBIASOFF.
#define BM_PMU_MISC0_REFTOP_SELFBIASOFF      (0x00000008)  //!< Bit mask for PMU_MISC0_REFTOP_SELFBIASOFF.

//! @brief Get value of PMU_MISC0_REFTOP_SELFBIASOFF from a register value.
#define BG_PMU_MISC0_REFTOP_SELFBIASOFF(r)   (((r) & BM_PMU_MISC0_REFTOP_SELFBIASOFF) >> BP_PMU_MISC0_REFTOP_SELFBIASOFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_REFTOP_SELFBIASOFF.
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   ((((reg32_t) v) << BP_PMU_MISC0_REFTOP_SELFBIASOFF) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#else
//! @brief Format value for bitfield PMU_MISC0_REFTOP_SELFBIASOFF.
#define BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)   (((v) << BP_PMU_MISC0_REFTOP_SELFBIASOFF) & BM_PMU_MISC0_REFTOP_SELFBIASOFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_SELFBIASOFF field to a new value.
#define BW_PMU_MISC0_REFTOP_SELFBIASOFF(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_REFTOP_SELFBIASOFF) | BF_PMU_MISC0_REFTOP_SELFBIASOFF(v)))
#endif


/* --- Register HW_PMU_MISC0, field REFTOP_VBGADJ[6:4] (RW)
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

#define BP_PMU_MISC0_REFTOP_VBGADJ      (4)      //!< Bit position for PMU_MISC0_REFTOP_VBGADJ.
#define BM_PMU_MISC0_REFTOP_VBGADJ      (0x00000070)  //!< Bit mask for PMU_MISC0_REFTOP_VBGADJ.

//! @brief Get value of PMU_MISC0_REFTOP_VBGADJ from a register value.
#define BG_PMU_MISC0_REFTOP_VBGADJ(r)   (((r) & BM_PMU_MISC0_REFTOP_VBGADJ) >> BP_PMU_MISC0_REFTOP_VBGADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_REFTOP_VBGADJ.
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   ((((reg32_t) v) << BP_PMU_MISC0_REFTOP_VBGADJ) & BM_PMU_MISC0_REFTOP_VBGADJ)
#else
//! @brief Format value for bitfield PMU_MISC0_REFTOP_VBGADJ.
#define BF_PMU_MISC0_REFTOP_VBGADJ(v)   (((v) << BP_PMU_MISC0_REFTOP_VBGADJ) & BM_PMU_MISC0_REFTOP_VBGADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_VBGADJ field to a new value.
#define BW_PMU_MISC0_REFTOP_VBGADJ(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_REFTOP_VBGADJ) | BF_PMU_MISC0_REFTOP_VBGADJ(v)))
#endif


/* --- Register HW_PMU_MISC0, field REFTOP_VBGUP[7] (RW)
 *
 * Status bit which signals that the analog bandgap voltage is up and stable. 1 - Stable. Not
 * related to PMU.
 */

#define BP_PMU_MISC0_REFTOP_VBGUP      (7)      //!< Bit position for PMU_MISC0_REFTOP_VBGUP.
#define BM_PMU_MISC0_REFTOP_VBGUP      (0x00000080)  //!< Bit mask for PMU_MISC0_REFTOP_VBGUP.

//! @brief Get value of PMU_MISC0_REFTOP_VBGUP from a register value.
#define BG_PMU_MISC0_REFTOP_VBGUP(r)   (((r) & BM_PMU_MISC0_REFTOP_VBGUP) >> BP_PMU_MISC0_REFTOP_VBGUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_REFTOP_VBGUP.
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   ((((reg32_t) v) << BP_PMU_MISC0_REFTOP_VBGUP) & BM_PMU_MISC0_REFTOP_VBGUP)
#else
//! @brief Format value for bitfield PMU_MISC0_REFTOP_VBGUP.
#define BF_PMU_MISC0_REFTOP_VBGUP(v)   (((v) << BP_PMU_MISC0_REFTOP_VBGUP) & BM_PMU_MISC0_REFTOP_VBGUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFTOP_VBGUP field to a new value.
#define BW_PMU_MISC0_REFTOP_VBGUP(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_REFTOP_VBGUP) | BF_PMU_MISC0_REFTOP_VBGUP(v)))
#endif

/* --- Register HW_PMU_MISC0, field STOP_MODE_CONFIG[12] (RW)
 *
 * Configure the analog behavior in stop mode. Not related to PMU.
 *
 * Values:
 * 0 - All analog except rtc powered down on stop mode assertion
 * 1 - Certain analog functions such as certain regulators left up
 */

#define BP_PMU_MISC0_STOP_MODE_CONFIG      (12)      //!< Bit position for PMU_MISC0_STOP_MODE_CONFIG.
#define BM_PMU_MISC0_STOP_MODE_CONFIG      (0x00001000)  //!< Bit mask for PMU_MISC0_STOP_MODE_CONFIG.

//! @brief Get value of PMU_MISC0_STOP_MODE_CONFIG from a register value.
#define BG_PMU_MISC0_STOP_MODE_CONFIG(r)   (((r) & BM_PMU_MISC0_STOP_MODE_CONFIG) >> BP_PMU_MISC0_STOP_MODE_CONFIG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_STOP_MODE_CONFIG.
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   ((((reg32_t) v) << BP_PMU_MISC0_STOP_MODE_CONFIG) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#else
//! @brief Format value for bitfield PMU_MISC0_STOP_MODE_CONFIG.
#define BF_PMU_MISC0_STOP_MODE_CONFIG(v)   (((v) << BP_PMU_MISC0_STOP_MODE_CONFIG) & BM_PMU_MISC0_STOP_MODE_CONFIG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP_MODE_CONFIG field to a new value.
#define BW_PMU_MISC0_STOP_MODE_CONFIG(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_STOP_MODE_CONFIG) | BF_PMU_MISC0_STOP_MODE_CONFIG(v)))
#endif


/* --- Register HW_PMU_MISC0, field OSC_I[15:14] (RW)
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

#define BP_PMU_MISC0_OSC_I      (14)      //!< Bit position for PMU_MISC0_OSC_I.
#define BM_PMU_MISC0_OSC_I      (0x0000c000)  //!< Bit mask for PMU_MISC0_OSC_I.

//! @brief Get value of PMU_MISC0_OSC_I from a register value.
#define BG_PMU_MISC0_OSC_I(r)   (((r) & BM_PMU_MISC0_OSC_I) >> BP_PMU_MISC0_OSC_I)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_OSC_I.
#define BF_PMU_MISC0_OSC_I(v)   ((((reg32_t) v) << BP_PMU_MISC0_OSC_I) & BM_PMU_MISC0_OSC_I)
#else
//! @brief Format value for bitfield PMU_MISC0_OSC_I.
#define BF_PMU_MISC0_OSC_I(v)   (((v) << BP_PMU_MISC0_OSC_I) & BM_PMU_MISC0_OSC_I)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSC_I field to a new value.
#define BW_PMU_MISC0_OSC_I(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_OSC_I) | BF_PMU_MISC0_OSC_I(v)))
#endif


/* --- Register HW_PMU_MISC0, field OSC_XTALOK[16] (RO)
 *
 * Status bit which signals that the output of the 24MHz crystal oscillator is stable. Generated
 * from a timer and active detection of the actual frequency. Not related to PMU.
 */

#define BP_PMU_MISC0_OSC_XTALOK      (16)      //!< Bit position for PMU_MISC0_OSC_XTALOK.
#define BM_PMU_MISC0_OSC_XTALOK      (0x00010000)  //!< Bit mask for PMU_MISC0_OSC_XTALOK.

//! @brief Get value of PMU_MISC0_OSC_XTALOK from a register value.
#define BG_PMU_MISC0_OSC_XTALOK(r)   (((r) & BM_PMU_MISC0_OSC_XTALOK) >> BP_PMU_MISC0_OSC_XTALOK)

/* --- Register HW_PMU_MISC0, field OSC_XTALOK_EN[17] (RW)
 *
 * Not related to PMU.
 */

#define BP_PMU_MISC0_OSC_XTALOK_EN      (17)      //!< Bit position for PMU_MISC0_OSC_XTALOK_EN.
#define BM_PMU_MISC0_OSC_XTALOK_EN      (0x00020000)  //!< Bit mask for PMU_MISC0_OSC_XTALOK_EN.

//! @brief Get value of PMU_MISC0_OSC_XTALOK_EN from a register value.
#define BG_PMU_MISC0_OSC_XTALOK_EN(r)   (((r) & BM_PMU_MISC0_OSC_XTALOK_EN) >> BP_PMU_MISC0_OSC_XTALOK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_OSC_XTALOK_EN.
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   ((((reg32_t) v) << BP_PMU_MISC0_OSC_XTALOK_EN) & BM_PMU_MISC0_OSC_XTALOK_EN)
#else
//! @brief Format value for bitfield PMU_MISC0_OSC_XTALOK_EN.
#define BF_PMU_MISC0_OSC_XTALOK_EN(v)   (((v) << BP_PMU_MISC0_OSC_XTALOK_EN) & BM_PMU_MISC0_OSC_XTALOK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSC_XTALOK_EN field to a new value.
#define BW_PMU_MISC0_OSC_XTALOK_EN(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_OSC_XTALOK_EN) | BF_PMU_MISC0_OSC_XTALOK_EN(v)))
#endif

/* --- Register HW_PMU_MISC0, field WBCP_VPW_THRESH[19:18] (RW)
 *
 * This signal alters the voltage that the pwell is charged pumped to. Not related to PMU.
 *
 * Values:
 * 00 - Nominal output pwell bias voltage.
 * 01 - Increase pwell output voltage by 25mV.
 * 10 - Decrease pwell output pwell voltage by 25mV.
 * 11 - Decrease pwell output pwell voltage by 50mV.
 */

#define BP_PMU_MISC0_WBCP_VPW_THRESH      (18)      //!< Bit position for PMU_MISC0_WBCP_VPW_THRESH.
#define BM_PMU_MISC0_WBCP_VPW_THRESH      (0x000c0000)  //!< Bit mask for PMU_MISC0_WBCP_VPW_THRESH.

//! @brief Get value of PMU_MISC0_WBCP_VPW_THRESH from a register value.
#define BG_PMU_MISC0_WBCP_VPW_THRESH(r)   (((r) & BM_PMU_MISC0_WBCP_VPW_THRESH) >> BP_PMU_MISC0_WBCP_VPW_THRESH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_WBCP_VPW_THRESH.
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   ((((reg32_t) v) << BP_PMU_MISC0_WBCP_VPW_THRESH) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#else
//! @brief Format value for bitfield PMU_MISC0_WBCP_VPW_THRESH.
#define BF_PMU_MISC0_WBCP_VPW_THRESH(v)   (((v) << BP_PMU_MISC0_WBCP_VPW_THRESH) & BM_PMU_MISC0_WBCP_VPW_THRESH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCP_VPW_THRESH field to a new value.
#define BW_PMU_MISC0_WBCP_VPW_THRESH(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_WBCP_VPW_THRESH) | BF_PMU_MISC0_WBCP_VPW_THRESH(v)))
#endif


/* --- Register HW_PMU_MISC0, field CLKGATE_CTRL[25] (RW)
 *
 * This bit allows disabling the clock gate (always un-gated) for the xtal 24MHz clock that clocks
 * the digital logic in the analog block. Do not change the field during a low power event. This is
 * not a field that the user would normally need to modify Not related to PMU.
 *
 * Values:
 * 0 - Allow the logic to automatically gate the clock when the XTAL is powered down.
 * 1 - Prevent the logic from ever gating off the clock.
 */

#define BP_PMU_MISC0_CLKGATE_CTRL      (25)      //!< Bit position for PMU_MISC0_CLKGATE_CTRL.
#define BM_PMU_MISC0_CLKGATE_CTRL      (0x02000000)  //!< Bit mask for PMU_MISC0_CLKGATE_CTRL.

//! @brief Get value of PMU_MISC0_CLKGATE_CTRL from a register value.
#define BG_PMU_MISC0_CLKGATE_CTRL(r)   (((r) & BM_PMU_MISC0_CLKGATE_CTRL) >> BP_PMU_MISC0_CLKGATE_CTRL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_CLKGATE_CTRL.
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   ((((reg32_t) v) << BP_PMU_MISC0_CLKGATE_CTRL) & BM_PMU_MISC0_CLKGATE_CTRL)
#else
//! @brief Format value for bitfield PMU_MISC0_CLKGATE_CTRL.
#define BF_PMU_MISC0_CLKGATE_CTRL(v)   (((v) << BP_PMU_MISC0_CLKGATE_CTRL) & BM_PMU_MISC0_CLKGATE_CTRL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE_CTRL field to a new value.
#define BW_PMU_MISC0_CLKGATE_CTRL(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_CLKGATE_CTRL) | BF_PMU_MISC0_CLKGATE_CTRL(v)))
#endif


/* --- Register HW_PMU_MISC0, field CLKGATE_DELAY[28:26] (RW)
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

#define BP_PMU_MISC0_CLKGATE_DELAY      (26)      //!< Bit position for PMU_MISC0_CLKGATE_DELAY.
#define BM_PMU_MISC0_CLKGATE_DELAY      (0x1c000000)  //!< Bit mask for PMU_MISC0_CLKGATE_DELAY.

//! @brief Get value of PMU_MISC0_CLKGATE_DELAY from a register value.
#define BG_PMU_MISC0_CLKGATE_DELAY(r)   (((r) & BM_PMU_MISC0_CLKGATE_DELAY) >> BP_PMU_MISC0_CLKGATE_DELAY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_MISC0_CLKGATE_DELAY.
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   ((((reg32_t) v) << BP_PMU_MISC0_CLKGATE_DELAY) & BM_PMU_MISC0_CLKGATE_DELAY)
#else
//! @brief Format value for bitfield PMU_MISC0_CLKGATE_DELAY.
#define BF_PMU_MISC0_CLKGATE_DELAY(v)   (((v) << BP_PMU_MISC0_CLKGATE_DELAY) & BM_PMU_MISC0_CLKGATE_DELAY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE_DELAY field to a new value.
#define BW_PMU_MISC0_CLKGATE_DELAY(v)   (HW_PMU_MISC0_WR((HW_PMU_MISC0_RD() & ~BM_PMU_MISC0_CLKGATE_DELAY) | BF_PMU_MISC0_CLKGATE_DELAY(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC1 - Miscellaneous Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines the control and status bits for miscellaneous analog blocks. The lvds1 and
 * lvds2 controls below control the behavior of the anaclk1/1b and anaclk2/2b lvds IO's.
 */
typedef union _hw_pmu_reg_misc1
{
    reg32_t U;
    struct _hw_pmu_reg_misc1_bitfields
    {
        unsigned LVDS1_CLK_SEL : 5; //!< [4:0] This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDS2_CLK_SEL : 5; //!< [9:5] This field selects the clk to be routed to anaclk2/2b. Not related to PMU.
        unsigned LVDSCLK1_OBEN : 1; //!< [10] This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_OBEN : 1; //!< [11] This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK1_IBEN : 1; //!< [12] This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned LVDSCLK2_IBEN : 1; //!< [13] This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers simutaneously. Not related to PMU.
        unsigned RESERVED0 : 15; //!< [28:14] Reserved
        unsigned IRQ_TEMPSENSE : 1; //!< [29] This status bit is set to one when when the temperature sensor interrupt asserts. Not related to PMU.
        unsigned IRQ_ANA_BO : 1; //!< [30] This status bit is set to one when when any of the analog regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
        unsigned IRQ_DIG_BO : 1; //!< [31] This status bit is set to one when when any of the digital regulator brownout interrupts assert. Check the regulator status bits to discover which regulator interrupt asserted.
    } B;
} hw_pmu_reg_misc1_t;
#endif

/*
 * constants & macros for entire PMU_REG_MISC1 register
 */
#define HW_PMU_REG_MISC1_ADDR      (REGS_PMU_BASE + 0x160)
#define HW_PMU_REG_MISC1_SET_ADDR  (HW_PMU_REG_MISC1_ADDR + 0x4)
#define HW_PMU_REG_MISC1_CLR_ADDR  (HW_PMU_REG_MISC1_ADDR + 0x8)
#define HW_PMU_REG_MISC1_TOG_ADDR  (HW_PMU_REG_MISC1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_PMU_REG_MISC1           (*(volatile hw_pmu_reg_misc1_t *) HW_PMU_REG_MISC1_ADDR)
#define HW_PMU_REG_MISC1_RD()      (HW_PMU_REG_MISC1.U)
#define HW_PMU_REG_MISC1_WR(v)     (HW_PMU_REG_MISC1.U = (v))
#define HW_PMU_REG_MISC1_SET(v)    ((*(volatile reg32_t *) HW_PMU_REG_MISC1_SET_ADDR) = (v))
#define HW_PMU_REG_MISC1_CLR(v)    ((*(volatile reg32_t *) HW_PMU_REG_MISC1_CLR_ADDR) = (v))
#define HW_PMU_REG_MISC1_TOG(v)    ((*(volatile reg32_t *) HW_PMU_REG_MISC1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual PMU_REG_MISC1 bitfields
 */

/* --- Register HW_PMU_REG_MISC1, field LVDS1_CLK_SEL[4:0] (RW)
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

#define BP_PMU_REG_MISC1_LVDS1_CLK_SEL      (0)      //!< Bit position for PMU_REG_MISC1_LVDS1_CLK_SEL.
#define BM_PMU_REG_MISC1_LVDS1_CLK_SEL      (0x0000001f)  //!< Bit mask for PMU_REG_MISC1_LVDS1_CLK_SEL.

//! @brief Get value of PMU_REG_MISC1_LVDS1_CLK_SEL from a register value.
#define BG_PMU_REG_MISC1_LVDS1_CLK_SEL(r)   (((r) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL) >> BP_PMU_REG_MISC1_LVDS1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDS1_CLK_SEL.
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDS1_CLK_SEL) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDS1_CLK_SEL.
#define BF_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   (((v) << BP_PMU_REG_MISC1_LVDS1_CLK_SEL) & BM_PMU_REG_MISC1_LVDS1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS1_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_LVDS1_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS1_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1, field LVDS2_CLK_SEL[9:5] (RW)
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

#define BP_PMU_REG_MISC1_LVDS2_CLK_SEL      (5)      //!< Bit position for PMU_REG_MISC1_LVDS2_CLK_SEL.
#define BM_PMU_REG_MISC1_LVDS2_CLK_SEL      (0x000003e0)  //!< Bit mask for PMU_REG_MISC1_LVDS2_CLK_SEL.

//! @brief Get value of PMU_REG_MISC1_LVDS2_CLK_SEL from a register value.
#define BG_PMU_REG_MISC1_LVDS2_CLK_SEL(r)   (((r) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL) >> BP_PMU_REG_MISC1_LVDS2_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDS2_CLK_SEL.
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDS2_CLK_SEL) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDS2_CLK_SEL.
#define BF_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   (((v) << BP_PMU_REG_MISC1_LVDS2_CLK_SEL) & BM_PMU_REG_MISC1_LVDS2_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS2_CLK_SEL field to a new value.
#define BW_PMU_REG_MISC1_LVDS2_CLK_SEL(v)   BF_CS1(PMU_REG_MISC1, LVDS2_CLK_SEL, v)
#endif


/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_OBEN[10] (RW)
 *
 * This enables the lvds output buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK1_OBEN      (10)      //!< Bit position for PMU_REG_MISC1_LVDSCLK1_OBEN.
#define BM_PMU_REG_MISC1_LVDSCLK1_OBEN      (0x00000400)  //!< Bit mask for PMU_REG_MISC1_LVDSCLK1_OBEN.

//! @brief Get value of PMU_REG_MISC1_LVDSCLK1_OBEN from a register value.
#define BG_PMU_REG_MISC1_LVDSCLK1_OBEN(r)   (((r) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN) >> BP_PMU_REG_MISC1_LVDSCLK1_OBEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK1_OBEN.
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDSCLK1_OBEN) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK1_OBEN.
#define BF_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   (((v) << BP_PMU_REG_MISC1_LVDSCLK1_OBEN) & BM_PMU_REG_MISC1_LVDSCLK1_OBEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_OBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK1_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_OBEN[11] (RW)
 *
 * This enables the lvds output buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK2_OBEN      (11)      //!< Bit position for PMU_REG_MISC1_LVDSCLK2_OBEN.
#define BM_PMU_REG_MISC1_LVDSCLK2_OBEN      (0x00000800)  //!< Bit mask for PMU_REG_MISC1_LVDSCLK2_OBEN.

//! @brief Get value of PMU_REG_MISC1_LVDSCLK2_OBEN from a register value.
#define BG_PMU_REG_MISC1_LVDSCLK2_OBEN(r)   (((r) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN) >> BP_PMU_REG_MISC1_LVDSCLK2_OBEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK2_OBEN.
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDSCLK2_OBEN) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK2_OBEN.
#define BF_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   (((v) << BP_PMU_REG_MISC1_LVDSCLK2_OBEN) & BM_PMU_REG_MISC1_LVDSCLK2_OBEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_OBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK2_OBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_OBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK1_IBEN[12] (RW)
 *
 * This enables the lvds input buffer for anaclk1/1b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK1_IBEN      (12)      //!< Bit position for PMU_REG_MISC1_LVDSCLK1_IBEN.
#define BM_PMU_REG_MISC1_LVDSCLK1_IBEN      (0x00001000)  //!< Bit mask for PMU_REG_MISC1_LVDSCLK1_IBEN.

//! @brief Get value of PMU_REG_MISC1_LVDSCLK1_IBEN from a register value.
#define BG_PMU_REG_MISC1_LVDSCLK1_IBEN(r)   (((r) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN) >> BP_PMU_REG_MISC1_LVDSCLK1_IBEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK1_IBEN.
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDSCLK1_IBEN) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK1_IBEN.
#define BF_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   (((v) << BP_PMU_REG_MISC1_LVDSCLK1_IBEN) & BM_PMU_REG_MISC1_LVDSCLK1_IBEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK1_IBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK1_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK1_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field LVDSCLK2_IBEN[13] (RW)
 *
 * This enables the lvds input buffer for anaclk2/2b. Do not enable input and output buffers
 * simutaneously. Not related to PMU.
 */

#define BP_PMU_REG_MISC1_LVDSCLK2_IBEN      (13)      //!< Bit position for PMU_REG_MISC1_LVDSCLK2_IBEN.
#define BM_PMU_REG_MISC1_LVDSCLK2_IBEN      (0x00002000)  //!< Bit mask for PMU_REG_MISC1_LVDSCLK2_IBEN.

//! @brief Get value of PMU_REG_MISC1_LVDSCLK2_IBEN from a register value.
#define BG_PMU_REG_MISC1_LVDSCLK2_IBEN(r)   (((r) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN) >> BP_PMU_REG_MISC1_LVDSCLK2_IBEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK2_IBEN.
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_LVDSCLK2_IBEN) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_LVDSCLK2_IBEN.
#define BF_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   (((v) << BP_PMU_REG_MISC1_LVDSCLK2_IBEN) & BM_PMU_REG_MISC1_LVDSCLK2_IBEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDSCLK2_IBEN field to a new value.
#define BW_PMU_REG_MISC1_LVDSCLK2_IBEN(v)   BF_CS1(PMU_REG_MISC1, LVDSCLK2_IBEN, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_TEMPSENSE[29] (W1C)
 *
 * This status bit is set to one when when the temperature sensor interrupt asserts. Not related to
 * PMU.
 */

#define BP_PMU_REG_MISC1_IRQ_TEMPSENSE      (29)      //!< Bit position for PMU_REG_MISC1_IRQ_TEMPSENSE.
#define BM_PMU_REG_MISC1_IRQ_TEMPSENSE      (0x20000000)  //!< Bit mask for PMU_REG_MISC1_IRQ_TEMPSENSE.

//! @brief Get value of PMU_REG_MISC1_IRQ_TEMPSENSE from a register value.
#define BG_PMU_REG_MISC1_IRQ_TEMPSENSE(r)   (((r) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE) >> BP_PMU_REG_MISC1_IRQ_TEMPSENSE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_TEMPSENSE.
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_IRQ_TEMPSENSE) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_TEMPSENSE.
#define BF_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   (((v) << BP_PMU_REG_MISC1_IRQ_TEMPSENSE) & BM_PMU_REG_MISC1_IRQ_TEMPSENSE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_TEMPSENSE field to a new value.
#define BW_PMU_REG_MISC1_IRQ_TEMPSENSE(v)   BF_CS1(PMU_REG_MISC1, IRQ_TEMPSENSE, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_ANA_BO[30] (W1C)
 *
 * This status bit is set to one when when any of the analog regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_IRQ_ANA_BO      (30)      //!< Bit position for PMU_REG_MISC1_IRQ_ANA_BO.
#define BM_PMU_REG_MISC1_IRQ_ANA_BO      (0x40000000)  //!< Bit mask for PMU_REG_MISC1_IRQ_ANA_BO.

//! @brief Get value of PMU_REG_MISC1_IRQ_ANA_BO from a register value.
#define BG_PMU_REG_MISC1_IRQ_ANA_BO(r)   (((r) & BM_PMU_REG_MISC1_IRQ_ANA_BO) >> BP_PMU_REG_MISC1_IRQ_ANA_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_ANA_BO.
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_IRQ_ANA_BO) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_ANA_BO.
#define BF_PMU_REG_MISC1_IRQ_ANA_BO(v)   (((v) << BP_PMU_REG_MISC1_IRQ_ANA_BO) & BM_PMU_REG_MISC1_IRQ_ANA_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ANA_BO field to a new value.
#define BW_PMU_REG_MISC1_IRQ_ANA_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_ANA_BO, v)
#endif

/* --- Register HW_PMU_REG_MISC1, field IRQ_DIG_BO[31] (W1C)
 *
 * This status bit is set to one when when any of the digital regulator brownout interrupts assert.
 * Check the regulator status bits to discover which regulator interrupt asserted.
 */

#define BP_PMU_REG_MISC1_IRQ_DIG_BO      (31)      //!< Bit position for PMU_REG_MISC1_IRQ_DIG_BO.
#define BM_PMU_REG_MISC1_IRQ_DIG_BO      (0x80000000)  //!< Bit mask for PMU_REG_MISC1_IRQ_DIG_BO.

//! @brief Get value of PMU_REG_MISC1_IRQ_DIG_BO from a register value.
#define BG_PMU_REG_MISC1_IRQ_DIG_BO(r)   (((r) & BM_PMU_REG_MISC1_IRQ_DIG_BO) >> BP_PMU_REG_MISC1_IRQ_DIG_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_DIG_BO.
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   ((((reg32_t) v) << BP_PMU_REG_MISC1_IRQ_DIG_BO) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#else
//! @brief Format value for bitfield PMU_REG_MISC1_IRQ_DIG_BO.
#define BF_PMU_REG_MISC1_IRQ_DIG_BO(v)   (((v) << BP_PMU_REG_MISC1_IRQ_DIG_BO) & BM_PMU_REG_MISC1_IRQ_DIG_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_DIG_BO field to a new value.
#define BW_PMU_REG_MISC1_IRQ_DIG_BO(v)   BF_CS1(PMU_REG_MISC1, IRQ_DIG_BO, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PMU_REG_MISC2 - Miscellaneous Register 2 (RW)
 *
 * Reset value: 0x00272727
 *
 * This register defines the basic controls for the temperature sensor minus the frequency of
 * automatic sampling which is defined in TEMPSENSE_1.
 */
typedef union _hw_pmu_reg_misc2
{
    reg32_t U;
    struct _hw_pmu_reg_misc2_bitfields
    {
        unsigned REG0_BO_OFFSET : 3; //!< [2:0] This bit field defines the brown out voltage offset for the CORE power domain. Ana_irq1 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG0_BO_STATUS : 1; //!< [3] Reg0 brownout status bit.
        unsigned RESERVED0 : 1; //!< [4] Reserved.
        unsigned REG0_ENABLE_BO : 1; //!< [5] Enables the brownout detection.
        unsigned RESERVED1 : 1; //!< [6] Reserved
        unsigned CONTROL0 : 1; //!< [7] Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode.
        unsigned REG1_BO_OFFSET : 3; //!< [10:8] This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG1_BO_STATUS : 1; //!< [11] Reg1 brownout status bit.
        unsigned RESERVED2 : 1; //!< [12] Reserved.
        unsigned REG1_ENABLE_BO : 1; //!< [13] Enables the brownout detection.
        unsigned RESERVED3 : 2; //!< [15:14] Reserved.
        unsigned REG2_BO_OFFSET : 3; //!< [18:16] This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
        unsigned REG2_BO_STATUS : 1; //!< [19] Reg2 brownout status bit.
        unsigned RESERVED4 : 1; //!< [20] Reserved.
        unsigned REG2_ENABLE_BO : 1; //!< [21] Enables the brownout detection.
        unsigned REG2_OK : 1; //!< [22] Signals that the voltage is above the brownout level for the SOC supply.
        unsigned RESERVED5 : 1; //!< [23] Reserved
        unsigned REG0_STEP_TIME : 2; //!< [25:24] Number of clock periods (24MHz clock).
        unsigned REG1_STEP_TIME : 2; //!< [27:26] Number of clock periods (24MHz clock).
        unsigned REG2_STEP_TIME : 2; //!< [29:28] Number of clock periods (24MHz clock).
        unsigned CONTROL3 : 2; //!< [31:30] Post-divider for video PLL. The output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
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

/* --- Register HW_PMU_REG_MISC2, field REG0_BO_OFFSET[2:0] (RO)
 *
 * This bit field defines the brown out voltage offset for the CORE power domain. Ana_irq1 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG0_BO_OFFSET      (0)      //!< Bit position for PMU_REG_MISC2_REG0_BO_OFFSET.
#define BM_PMU_REG_MISC2_REG0_BO_OFFSET      (0x00000007)  //!< Bit mask for PMU_REG_MISC2_REG0_BO_OFFSET.

//! @brief Get value of PMU_REG_MISC2_REG0_BO_OFFSET from a register value.
#define BG_PMU_REG_MISC2_REG0_BO_OFFSET(r)   (((r) & BM_PMU_REG_MISC2_REG0_BO_OFFSET) >> BP_PMU_REG_MISC2_REG0_BO_OFFSET)


/* --- Register HW_PMU_REG_MISC2, field REG0_BO_STATUS[3] (RO)
 *
 * Reg0 brownout status bit.
 *
 * Values:
 * 1 - Brownout, supply is below target minus brownout offset.
 */

#define BP_PMU_REG_MISC2_REG0_BO_STATUS      (3)      //!< Bit position for PMU_REG_MISC2_REG0_BO_STATUS.
#define BM_PMU_REG_MISC2_REG0_BO_STATUS      (0x00000008)  //!< Bit mask for PMU_REG_MISC2_REG0_BO_STATUS.

//! @brief Get value of PMU_REG_MISC2_REG0_BO_STATUS from a register value.
#define BG_PMU_REG_MISC2_REG0_BO_STATUS(r)   (((r) & BM_PMU_REG_MISC2_REG0_BO_STATUS) >> BP_PMU_REG_MISC2_REG0_BO_STATUS)


/* --- Register HW_PMU_REG_MISC2, field REG0_ENABLE_BO[5] (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG0_ENABLE_BO      (5)      //!< Bit position for PMU_REG_MISC2_REG0_ENABLE_BO.
#define BM_PMU_REG_MISC2_REG0_ENABLE_BO      (0x00000020)  //!< Bit mask for PMU_REG_MISC2_REG0_ENABLE_BO.

//! @brief Get value of PMU_REG_MISC2_REG0_ENABLE_BO from a register value.
#define BG_PMU_REG_MISC2_REG0_ENABLE_BO(r)   (((r) & BM_PMU_REG_MISC2_REG0_ENABLE_BO) >> BP_PMU_REG_MISC2_REG0_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG0_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG0_ENABLE_BO) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG0_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)   (((v) << BP_PMU_REG_MISC2_REG0_ENABLE_BO) & BM_PMU_REG_MISC2_REG0_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG0_ENABLE_BO(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG0_ENABLE_BO) | BF_PMU_REG_MISC2_REG0_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_MISC2, field CONTROL0[7] (RW)
 *
 * Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode.
 */

#define BP_PMU_REG_MISC2_CONTROL0      (7)      //!< Bit position for PMU_REG_MISC2_CONTROL0.
#define BM_PMU_REG_MISC2_CONTROL0      (0x00000080)  //!< Bit mask for PMU_REG_MISC2_CONTROL0.

//! @brief Get value of PMU_REG_MISC2_CONTROL0 from a register value.
#define BG_PMU_REG_MISC2_CONTROL0(r)   (((r) & BM_PMU_REG_MISC2_CONTROL0) >> BP_PMU_REG_MISC2_CONTROL0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_CONTROL0.
#define BF_PMU_REG_MISC2_CONTROL0(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_CONTROL0) & BM_PMU_REG_MISC2_CONTROL0)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_CONTROL0.
#define BF_PMU_REG_MISC2_CONTROL0(v)   (((v) << BP_PMU_REG_MISC2_CONTROL0) & BM_PMU_REG_MISC2_CONTROL0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONTROL0 field to a new value.
#define BW_PMU_REG_MISC2_CONTROL0(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_CONTROL0) | BF_PMU_REG_MISC2_CONTROL0(v)))
#endif

/* --- Register HW_PMU_REG_MISC2, field REG1_BO_OFFSET[10:8] (RO)
 *
 * This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG1_BO_OFFSET      (8)      //!< Bit position for PMU_REG_MISC2_REG1_BO_OFFSET.
#define BM_PMU_REG_MISC2_REG1_BO_OFFSET      (0x00000700)  //!< Bit mask for PMU_REG_MISC2_REG1_BO_OFFSET.

//! @brief Get value of PMU_REG_MISC2_REG1_BO_OFFSET from a register value.
#define BG_PMU_REG_MISC2_REG1_BO_OFFSET(r)   (((r) & BM_PMU_REG_MISC2_REG1_BO_OFFSET) >> BP_PMU_REG_MISC2_REG1_BO_OFFSET)


/* --- Register HW_PMU_REG_MISC2, field REG1_BO_STATUS[11] (RO)
 *
 * Reg1 brownout status bit.
 *
 * Values:
 * 1 - Brownout, supply is below target minus brownout offset.
 */

#define BP_PMU_REG_MISC2_REG1_BO_STATUS      (11)      //!< Bit position for PMU_REG_MISC2_REG1_BO_STATUS.
#define BM_PMU_REG_MISC2_REG1_BO_STATUS      (0x00000800)  //!< Bit mask for PMU_REG_MISC2_REG1_BO_STATUS.

//! @brief Get value of PMU_REG_MISC2_REG1_BO_STATUS from a register value.
#define BG_PMU_REG_MISC2_REG1_BO_STATUS(r)   (((r) & BM_PMU_REG_MISC2_REG1_BO_STATUS) >> BP_PMU_REG_MISC2_REG1_BO_STATUS)


/* --- Register HW_PMU_REG_MISC2, field REG1_ENABLE_BO[13] (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG1_ENABLE_BO      (13)      //!< Bit position for PMU_REG_MISC2_REG1_ENABLE_BO.
#define BM_PMU_REG_MISC2_REG1_ENABLE_BO      (0x00002000)  //!< Bit mask for PMU_REG_MISC2_REG1_ENABLE_BO.

//! @brief Get value of PMU_REG_MISC2_REG1_ENABLE_BO from a register value.
#define BG_PMU_REG_MISC2_REG1_ENABLE_BO(r)   (((r) & BM_PMU_REG_MISC2_REG1_ENABLE_BO) >> BP_PMU_REG_MISC2_REG1_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG1_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG1_ENABLE_BO) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG1_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)   (((v) << BP_PMU_REG_MISC2_REG1_ENABLE_BO) & BM_PMU_REG_MISC2_REG1_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG1_ENABLE_BO(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG1_ENABLE_BO) | BF_PMU_REG_MISC2_REG1_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_BO_OFFSET[18:16] (RO)
 *
 * This bit field defines the brown out voltage offset for the xPU power domain. Ana_irq2 is also
 * asserted. Single bit increments reflect 25mV brownout voltage steps. Not all steps will make
 * sense to use either because of input supply limitations or load operation.
 *
 * Values:
 * 000 - Brownout voltage = 0.725V
 * 111 - Brownout voltage = 0.875V
 */

#define BP_PMU_REG_MISC2_REG2_BO_OFFSET      (16)      //!< Bit position for PMU_REG_MISC2_REG2_BO_OFFSET.
#define BM_PMU_REG_MISC2_REG2_BO_OFFSET      (0x00070000)  //!< Bit mask for PMU_REG_MISC2_REG2_BO_OFFSET.

//! @brief Get value of PMU_REG_MISC2_REG2_BO_OFFSET from a register value.
#define BG_PMU_REG_MISC2_REG2_BO_OFFSET(r)   (((r) & BM_PMU_REG_MISC2_REG2_BO_OFFSET) >> BP_PMU_REG_MISC2_REG2_BO_OFFSET)


/* --- Register HW_PMU_REG_MISC2, field REG2_BO_STATUS[19] (RO)
 *
 * Reg2 brownout status bit.
 */

#define BP_PMU_REG_MISC2_REG2_BO_STATUS      (19)      //!< Bit position for PMU_REG_MISC2_REG2_BO_STATUS.
#define BM_PMU_REG_MISC2_REG2_BO_STATUS      (0x00080000)  //!< Bit mask for PMU_REG_MISC2_REG2_BO_STATUS.

//! @brief Get value of PMU_REG_MISC2_REG2_BO_STATUS from a register value.
#define BG_PMU_REG_MISC2_REG2_BO_STATUS(r)   (((r) & BM_PMU_REG_MISC2_REG2_BO_STATUS) >> BP_PMU_REG_MISC2_REG2_BO_STATUS)

/* --- Register HW_PMU_REG_MISC2, field REG2_ENABLE_BO[21] (RW)
 *
 * Enables the brownout detection.
 */

#define BP_PMU_REG_MISC2_REG2_ENABLE_BO      (21)      //!< Bit position for PMU_REG_MISC2_REG2_ENABLE_BO.
#define BM_PMU_REG_MISC2_REG2_ENABLE_BO      (0x00200000)  //!< Bit mask for PMU_REG_MISC2_REG2_ENABLE_BO.

//! @brief Get value of PMU_REG_MISC2_REG2_ENABLE_BO from a register value.
#define BG_PMU_REG_MISC2_REG2_ENABLE_BO(r)   (((r) & BM_PMU_REG_MISC2_REG2_ENABLE_BO) >> BP_PMU_REG_MISC2_REG2_ENABLE_BO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG2_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG2_ENABLE_BO) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG2_ENABLE_BO.
#define BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)   (((v) << BP_PMU_REG_MISC2_REG2_ENABLE_BO) & BM_PMU_REG_MISC2_REG2_ENABLE_BO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_ENABLE_BO field to a new value.
#define BW_PMU_REG_MISC2_REG2_ENABLE_BO(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG2_ENABLE_BO) | BF_PMU_REG_MISC2_REG2_ENABLE_BO(v)))
#endif

/* --- Register HW_PMU_REG_MISC2, field REG2_OK[22] (RO)
 *
 * Signals that the voltage is above the brownout level for the SOC supply.
 */

#define BP_PMU_REG_MISC2_REG2_OK      (22)      //!< Bit position for PMU_REG_MISC2_REG2_OK.
#define BM_PMU_REG_MISC2_REG2_OK      (0x00400000)  //!< Bit mask for PMU_REG_MISC2_REG2_OK.

//! @brief Get value of PMU_REG_MISC2_REG2_OK from a register value.
#define BG_PMU_REG_MISC2_REG2_OK(r)   (((r) & BM_PMU_REG_MISC2_REG2_OK) >> BP_PMU_REG_MISC2_REG2_OK)

/* --- Register HW_PMU_REG_MISC2, field REG0_STEP_TIME[25:24] (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG0_STEP_TIME      (24)      //!< Bit position for PMU_REG_MISC2_REG0_STEP_TIME.
#define BM_PMU_REG_MISC2_REG0_STEP_TIME      (0x03000000)  //!< Bit mask for PMU_REG_MISC2_REG0_STEP_TIME.

//! @brief Get value of PMU_REG_MISC2_REG0_STEP_TIME from a register value.
#define BG_PMU_REG_MISC2_REG0_STEP_TIME(r)   (((r) & BM_PMU_REG_MISC2_REG0_STEP_TIME) >> BP_PMU_REG_MISC2_REG0_STEP_TIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG0_STEP_TIME.
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG0_STEP_TIME) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG0_STEP_TIME.
#define BF_PMU_REG_MISC2_REG0_STEP_TIME(v)   (((v) << BP_PMU_REG_MISC2_REG0_STEP_TIME) & BM_PMU_REG_MISC2_REG0_STEP_TIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG0_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG0_STEP_TIME(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG0_STEP_TIME) | BF_PMU_REG_MISC2_REG0_STEP_TIME(v)))
#endif


/* --- Register HW_PMU_REG_MISC2, field REG1_STEP_TIME[27:26] (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG1_STEP_TIME      (26)      //!< Bit position for PMU_REG_MISC2_REG1_STEP_TIME.
#define BM_PMU_REG_MISC2_REG1_STEP_TIME      (0x0c000000)  //!< Bit mask for PMU_REG_MISC2_REG1_STEP_TIME.

//! @brief Get value of PMU_REG_MISC2_REG1_STEP_TIME from a register value.
#define BG_PMU_REG_MISC2_REG1_STEP_TIME(r)   (((r) & BM_PMU_REG_MISC2_REG1_STEP_TIME) >> BP_PMU_REG_MISC2_REG1_STEP_TIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG1_STEP_TIME.
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG1_STEP_TIME) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG1_STEP_TIME.
#define BF_PMU_REG_MISC2_REG1_STEP_TIME(v)   (((v) << BP_PMU_REG_MISC2_REG1_STEP_TIME) & BM_PMU_REG_MISC2_REG1_STEP_TIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG1_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG1_STEP_TIME(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG1_STEP_TIME) | BF_PMU_REG_MISC2_REG1_STEP_TIME(v)))
#endif


/* --- Register HW_PMU_REG_MISC2, field REG2_STEP_TIME[29:28] (RW)
 *
 * Number of clock periods (24MHz clock).
 *
 * Values:
 * 00 - 64
 * 01 - 128
 * 10 - 256
 * 11 - 512
 */

#define BP_PMU_REG_MISC2_REG2_STEP_TIME      (28)      //!< Bit position for PMU_REG_MISC2_REG2_STEP_TIME.
#define BM_PMU_REG_MISC2_REG2_STEP_TIME      (0x30000000)  //!< Bit mask for PMU_REG_MISC2_REG2_STEP_TIME.

//! @brief Get value of PMU_REG_MISC2_REG2_STEP_TIME from a register value.
#define BG_PMU_REG_MISC2_REG2_STEP_TIME(r)   (((r) & BM_PMU_REG_MISC2_REG2_STEP_TIME) >> BP_PMU_REG_MISC2_REG2_STEP_TIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_REG2_STEP_TIME.
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_REG2_STEP_TIME) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_REG2_STEP_TIME.
#define BF_PMU_REG_MISC2_REG2_STEP_TIME(v)   (((v) << BP_PMU_REG_MISC2_REG2_STEP_TIME) & BM_PMU_REG_MISC2_REG2_STEP_TIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG2_STEP_TIME field to a new value.
#define BW_PMU_REG_MISC2_REG2_STEP_TIME(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_REG2_STEP_TIME) | BF_PMU_REG_MISC2_REG2_STEP_TIME(v)))
#endif


/* --- Register HW_PMU_REG_MISC2, field CONTROL3[31:30] (RW)
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

#define BP_PMU_REG_MISC2_CONTROL3      (30)      //!< Bit position for PMU_REG_MISC2_CONTROL3.
#define BM_PMU_REG_MISC2_CONTROL3      (0xc0000000)  //!< Bit mask for PMU_REG_MISC2_CONTROL3.

//! @brief Get value of PMU_REG_MISC2_CONTROL3 from a register value.
#define BG_PMU_REG_MISC2_CONTROL3(r)   (((r) & BM_PMU_REG_MISC2_CONTROL3) >> BP_PMU_REG_MISC2_CONTROL3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PMU_REG_MISC2_CONTROL3.
#define BF_PMU_REG_MISC2_CONTROL3(v)   ((((reg32_t) v) << BP_PMU_REG_MISC2_CONTROL3) & BM_PMU_REG_MISC2_CONTROL3)
#else
//! @brief Format value for bitfield PMU_REG_MISC2_CONTROL3.
#define BF_PMU_REG_MISC2_CONTROL3(v)   (((v) << BP_PMU_REG_MISC2_CONTROL3) & BM_PMU_REG_MISC2_CONTROL3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONTROL3 field to a new value.
#define BW_PMU_REG_MISC2_CONTROL3(v)   (HW_PMU_REG_MISC2_WR((HW_PMU_REG_MISC2_RD() & ~BM_PMU_REG_MISC2_CONTROL3) | BF_PMU_REG_MISC2_CONTROL3(v)))
#endif



/*!
 * @brief All PMU module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pmu
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
    volatile reg32_t REG_MISC1_SET; //!< Miscellaneous Register 1 Set
    volatile reg32_t REG_MISC1_CLR; //!< Miscellaneous Register 1 Clear
    volatile reg32_t REG_MISC1_TOG; //!< Miscellaneous Register 1 Toggle
    volatile hw_pmu_reg_misc2_t REG_MISC2; //!< Miscellaneous Register 2
} hw_pmu_t;
#pragma pack()

//! @brief Macro to access all PMU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PMU(0)</code>.
#define HW_PMU     (*(volatile hw_pmu_t *) REGS_PMU_BASE)

#endif


#endif // __HW_PMU_REGISTERS_H__
