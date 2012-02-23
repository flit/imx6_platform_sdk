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
 * Registers defined in this header file.
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
 * This register describes the IPU interface signals.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SW_RST : 1; //!< Software Reset
        unsigned CLK_SEL : 1; //!< Clock mode selection
        unsigned YUV422_8BIT_FM : 1; //!< YUV422 8-bit mode selection
        unsigned RGB444_FM : 1; //!< Rgb888 mode selection
        unsigned RESERVED0 : 28; //!< Reserved.
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

/* --- Register HW_CSI2IPU_SW_RST, field SW_RST (RW)
 *
 * Software Reset
 *
 * Values:
 * 0 - Software Reset Disable
 * 1 - Software Reset Enable
 */

#define BP_CSI2IPU_SW_RST_SW_RST      0
#define BM_CSI2IPU_SW_RST_SW_RST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_SW_RST(v)   ((((reg32_t) v) << 0) & BM_CSI2IPU_SW_RST_SW_RST)
#else
#define BF_CSI2IPU_SW_RST_SW_RST(v)   (((v) << 0) & BM_CSI2IPU_SW_RST_SW_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_RST field to a new value.
#define BW_CSI2IPU_SW_RST_SW_RST(v)   BF_CS1(CSI2IPU_SW_RST, SW_RST, v)
#endif


/* --- Register HW_CSI2IPU_SW_RST, field CLK_SEL (RW)
 *
 * Clock mode selection
 *
 * Values:
 * 0 - Gated Mode
 * 1 - Non-Gated Mode
 */

#define BP_CSI2IPU_SW_RST_CLK_SEL      1
#define BM_CSI2IPU_SW_RST_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CSI2IPU_SW_RST_CLK_SEL)
#else
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   (((v) << 1) & BM_CSI2IPU_SW_RST_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_SEL field to a new value.
#define BW_CSI2IPU_SW_RST_CLK_SEL(v)   BF_CS1(CSI2IPU_SW_RST, CLK_SEL, v)
#endif


/* --- Register HW_CSI2IPU_SW_RST, field YUV422_8BIT_FM (RW)
 *
 * YUV422 8-bit mode selection
 *
 * Values:
 * 0 - YUYV
 * 1 - UYVY
 */

#define BP_CSI2IPU_SW_RST_YUV422_8BIT_FM      2
#define BM_CSI2IPU_SW_RST_YUV422_8BIT_FM      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   ((((reg32_t) v) << 2) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#else
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   (((v) << 2) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the YUV422_8BIT_FM field to a new value.
#define BW_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   BF_CS1(CSI2IPU_SW_RST, YUV422_8BIT_FM, v)
#endif


/* --- Register HW_CSI2IPU_SW_RST, field RGB444_FM (RW)
 *
 * Rgb888 mode selection
 *
 * Values:
 * 0 - {4’h0,r4b4g4}
 * 1 - {r4,1’b0,g4,2’b00,b4,1’b0}
 */

#define BP_CSI2IPU_SW_RST_RGB444_FM      3
#define BM_CSI2IPU_SW_RST_RGB444_FM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   ((((reg32_t) v) << 3) & BM_CSI2IPU_SW_RST_RGB444_FM)
#else
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   (((v) << 3) & BM_CSI2IPU_SW_RST_RGB444_FM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RGB444_FM field to a new value.
#define BW_CSI2IPU_SW_RST_RGB444_FM(v)   BF_CS1(CSI2IPU_SW_RST, RGB444_FM, v)
#endif



/*!
 * @brief All CSI2IPU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[960];
    volatile hw_csi2ipu_sw_rst_t SW_RST; //!< CSI 2 IPU Gasket Software Reset
} hw_csi2ipu_t
#endif

//! @brief Macro to access all CSI2IPU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSI2IPU(0)</code>.
#define HW_CSI2IPU     (*(volatile hw_csi2ipu_t *) REGS_CSI2IPU_BASE)


#endif // _CSI2IPU_H
