/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSI2IPU_H
#define _CSI2IPU_H

#include "regs.h"

/*
 * i.MX6DQ CSI2IPU registers defined in this header file.
 *
 * - HW_CSI2IPU_SW_RST - CSI 2 IPU Gasket Software Reset
 *
 * hw_csi2ipu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CSI2IPU_BASE
#define REGS_CSI2IPU_BASE (0x021dc000) //!< Base address for CSI2IPU.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI2IPU_SW_RST - CSI 2 IPU Gasket Software Reset (RW)
 *
 * Reset value: 0x00000000
 *
 * This register describes the IPU interface signals.
 */
typedef union _hw_csi2ipu_sw_rst
{
    reg32_t U;
    struct _hw_csi2ipu_sw_rst_bitfields
    {
        unsigned SW_RST : 1; //!< [0] Software Reset
        unsigned CLK_SEL : 1; //!< [1] Clock mode selection
        unsigned YUV422_8BIT_FM : 1; //!< [2] YUV422 8-bit mode selection
        unsigned RGB444_FM : 1; //!< [3] Rgb888 mode selection
        unsigned RESERVED0 : 28; //!< [31:4] Reserved.
    } B;
} hw_csi2ipu_sw_rst_t;
#endif

/*
 * constants & macros for entire CSI2IPU_SW_RST register
 */
#define HW_CSI2IPU_SW_RST_ADDR      (REGS_CSI2IPU_BASE + 0xf00)

#ifndef __LANGUAGE_ASM__
#define HW_CSI2IPU_SW_RST           (*(volatile hw_csi2ipu_sw_rst_t *) HW_CSI2IPU_SW_RST_ADDR)
#define HW_CSI2IPU_SW_RST_RD()      (HW_CSI2IPU_SW_RST.U)
#define HW_CSI2IPU_SW_RST_WR(v)     (HW_CSI2IPU_SW_RST.U = (v))
#define HW_CSI2IPU_SW_RST_SET(v)    (HW_CSI2IPU_SW_RST_WR(HW_CSI2IPU_SW_RST_RD() |  (v)))
#define HW_CSI2IPU_SW_RST_CLR(v)    (HW_CSI2IPU_SW_RST_WR(HW_CSI2IPU_SW_RST_RD() & ~(v)))
#define HW_CSI2IPU_SW_RST_TOG(v)    (HW_CSI2IPU_SW_RST_WR(HW_CSI2IPU_SW_RST_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI2IPU_SW_RST bitfields
 */

/* --- Register HW_CSI2IPU_SW_RST, field SW_RST[0] (RW)
 *
 * Software Reset
 *
 * Values:
 * 0 - Software Reset Disable
 * 1 - Software Reset Enable
 */

#define BP_CSI2IPU_SW_RST_SW_RST      (0)      //!< Bit position for CSI2IPU_SW_RST_SW_RST.
#define BM_CSI2IPU_SW_RST_SW_RST      (0x00000001)  //!< Bit mask for CSI2IPU_SW_RST_SW_RST.

//! @brief Get value of CSI2IPU_SW_RST_SW_RST from a register value.
#define BG_CSI2IPU_SW_RST_SW_RST(r)   (((r) & BM_CSI2IPU_SW_RST_SW_RST) >> BP_CSI2IPU_SW_RST_SW_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI2IPU_SW_RST_SW_RST.
#define BF_CSI2IPU_SW_RST_SW_RST(v)   ((((reg32_t) v) << BP_CSI2IPU_SW_RST_SW_RST) & BM_CSI2IPU_SW_RST_SW_RST)
#else
//! @brief Format value for bitfield CSI2IPU_SW_RST_SW_RST.
#define BF_CSI2IPU_SW_RST_SW_RST(v)   (((v) << BP_CSI2IPU_SW_RST_SW_RST) & BM_CSI2IPU_SW_RST_SW_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_RST field to a new value.
#define BW_CSI2IPU_SW_RST_SW_RST(v)   (HW_CSI2IPU_SW_RST_WR((HW_CSI2IPU_SW_RST_RD() & ~BM_CSI2IPU_SW_RST_SW_RST) | BF_CSI2IPU_SW_RST_SW_RST(v)))
#endif


/* --- Register HW_CSI2IPU_SW_RST, field CLK_SEL[1] (RW)
 *
 * Clock mode selection
 *
 * Values:
 * 0 - Gated Mode
 * 1 - Non-Gated Mode
 */

#define BP_CSI2IPU_SW_RST_CLK_SEL      (1)      //!< Bit position for CSI2IPU_SW_RST_CLK_SEL.
#define BM_CSI2IPU_SW_RST_CLK_SEL      (0x00000002)  //!< Bit mask for CSI2IPU_SW_RST_CLK_SEL.

//! @brief Get value of CSI2IPU_SW_RST_CLK_SEL from a register value.
#define BG_CSI2IPU_SW_RST_CLK_SEL(r)   (((r) & BM_CSI2IPU_SW_RST_CLK_SEL) >> BP_CSI2IPU_SW_RST_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI2IPU_SW_RST_CLK_SEL.
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   ((((reg32_t) v) << BP_CSI2IPU_SW_RST_CLK_SEL) & BM_CSI2IPU_SW_RST_CLK_SEL)
#else
//! @brief Format value for bitfield CSI2IPU_SW_RST_CLK_SEL.
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   (((v) << BP_CSI2IPU_SW_RST_CLK_SEL) & BM_CSI2IPU_SW_RST_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_SEL field to a new value.
#define BW_CSI2IPU_SW_RST_CLK_SEL(v)   (HW_CSI2IPU_SW_RST_WR((HW_CSI2IPU_SW_RST_RD() & ~BM_CSI2IPU_SW_RST_CLK_SEL) | BF_CSI2IPU_SW_RST_CLK_SEL(v)))
#endif


/* --- Register HW_CSI2IPU_SW_RST, field YUV422_8BIT_FM[2] (RW)
 *
 * YUV422 8-bit mode selection
 *
 * Values:
 * 0 - YUYV
 * 1 - UYVY
 */

#define BP_CSI2IPU_SW_RST_YUV422_8BIT_FM      (2)      //!< Bit position for CSI2IPU_SW_RST_YUV422_8BIT_FM.
#define BM_CSI2IPU_SW_RST_YUV422_8BIT_FM      (0x00000004)  //!< Bit mask for CSI2IPU_SW_RST_YUV422_8BIT_FM.

//! @brief Get value of CSI2IPU_SW_RST_YUV422_8BIT_FM from a register value.
#define BG_CSI2IPU_SW_RST_YUV422_8BIT_FM(r)   (((r) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM) >> BP_CSI2IPU_SW_RST_YUV422_8BIT_FM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI2IPU_SW_RST_YUV422_8BIT_FM.
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   ((((reg32_t) v) << BP_CSI2IPU_SW_RST_YUV422_8BIT_FM) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#else
//! @brief Format value for bitfield CSI2IPU_SW_RST_YUV422_8BIT_FM.
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   (((v) << BP_CSI2IPU_SW_RST_YUV422_8BIT_FM) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the YUV422_8BIT_FM field to a new value.
#define BW_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   (HW_CSI2IPU_SW_RST_WR((HW_CSI2IPU_SW_RST_RD() & ~BM_CSI2IPU_SW_RST_YUV422_8BIT_FM) | BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)))
#endif


/* --- Register HW_CSI2IPU_SW_RST, field RGB444_FM[3] (RW)
 *
 * Rgb888 mode selection
 *
 * Values:
 * 0 - {4’h0,r4b4g4}
 * 1 - {r4,1’b0,g4,2’b00,b4,1’b0}
 */

#define BP_CSI2IPU_SW_RST_RGB444_FM      (3)      //!< Bit position for CSI2IPU_SW_RST_RGB444_FM.
#define BM_CSI2IPU_SW_RST_RGB444_FM      (0x00000008)  //!< Bit mask for CSI2IPU_SW_RST_RGB444_FM.

//! @brief Get value of CSI2IPU_SW_RST_RGB444_FM from a register value.
#define BG_CSI2IPU_SW_RST_RGB444_FM(r)   (((r) & BM_CSI2IPU_SW_RST_RGB444_FM) >> BP_CSI2IPU_SW_RST_RGB444_FM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI2IPU_SW_RST_RGB444_FM.
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   ((((reg32_t) v) << BP_CSI2IPU_SW_RST_RGB444_FM) & BM_CSI2IPU_SW_RST_RGB444_FM)
#else
//! @brief Format value for bitfield CSI2IPU_SW_RST_RGB444_FM.
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   (((v) << BP_CSI2IPU_SW_RST_RGB444_FM) & BM_CSI2IPU_SW_RST_RGB444_FM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RGB444_FM field to a new value.
#define BW_CSI2IPU_SW_RST_RGB444_FM(v)   (HW_CSI2IPU_SW_RST_WR((HW_CSI2IPU_SW_RST_RD() & ~BM_CSI2IPU_SW_RST_RGB444_FM) | BF_CSI2IPU_SW_RST_RGB444_FM(v)))
#endif



/*!
 * @brief All CSI2IPU module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_csi2ipu
{
    reg32_t _reserved0[960];
    volatile hw_csi2ipu_sw_rst_t SW_RST; //!< CSI 2 IPU Gasket Software Reset
} hw_csi2ipu_t;
#pragma pack()
#endif

//! @brief Macro to access all CSI2IPU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSI2IPU(0)</code>.
#define HW_CSI2IPU     (*(volatile hw_csi2ipu_t *) REGS_CSI2IPU_BASE)


#endif // _CSI2IPU_H
