/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSI2IPU_H
#define _CSI2IPU_H

#include "regs.h"

#ifndef REGS_CSI2IPU_BASE
#define REGS_CSI2IPU_BASE (REGS_BASE + 0x021dc000)

#endif


/*
 * HW_CSI2IPU_SW_RST - CSI 2 IPU Gasket Software Reset
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SW_RST : 1;
        unsigned CLK_SEL : 1;
        unsigned YUV422_8BIT_FM : 1;
        unsigned RGB444_FM : 1;
        unsigned RESERVED0 : 28;

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

/* --- Register HW_CSI2IPU_SW_RST, field SW_RST */

#define BP_CSI2IPU_SW_RST_SW_RST      0
#define BM_CSI2IPU_SW_RST_SW_RST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_SW_RST(v)   ((((reg32_t) v) << 0) & BM_CSI2IPU_SW_RST_SW_RST)
#else
#define BF_CSI2IPU_SW_RST_SW_RST(v)   (((v) << 0) & BM_CSI2IPU_SW_RST_SW_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSI2IPU_SW_RST_SW_RST(v)   BF_CS1(CSI2IPU_SW_RST, SW_RST, v)
#endif

/* --- Register HW_CSI2IPU_SW_RST, field CLK_SEL */

#define BP_CSI2IPU_SW_RST_CLK_SEL      1
#define BM_CSI2IPU_SW_RST_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CSI2IPU_SW_RST_CLK_SEL)
#else
#define BF_CSI2IPU_SW_RST_CLK_SEL(v)   (((v) << 1) & BM_CSI2IPU_SW_RST_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSI2IPU_SW_RST_CLK_SEL(v)   BF_CS1(CSI2IPU_SW_RST, CLK_SEL, v)
#endif

/* --- Register HW_CSI2IPU_SW_RST, field YUV422_8BIT_FM */

#define BP_CSI2IPU_SW_RST_YUV422_8BIT_FM      2
#define BM_CSI2IPU_SW_RST_YUV422_8BIT_FM      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   ((((reg32_t) v) << 2) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#else
#define BF_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   (((v) << 2) & BM_CSI2IPU_SW_RST_YUV422_8BIT_FM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSI2IPU_SW_RST_YUV422_8BIT_FM(v)   BF_CS1(CSI2IPU_SW_RST, YUV422_8BIT_FM, v)
#endif

/* --- Register HW_CSI2IPU_SW_RST, field RGB444_FM */

#define BP_CSI2IPU_SW_RST_RGB444_FM      3
#define BM_CSI2IPU_SW_RST_RGB444_FM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   ((((reg32_t) v) << 3) & BM_CSI2IPU_SW_RST_RGB444_FM)
#else
#define BF_CSI2IPU_SW_RST_RGB444_FM(v)   (((v) << 3) & BM_CSI2IPU_SW_RST_RGB444_FM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CSI2IPU_SW_RST_RGB444_FM(v)   BF_CS1(CSI2IPU_SW_RST, RGB444_FM, v)
#endif


#endif // _CSI2IPU_H

