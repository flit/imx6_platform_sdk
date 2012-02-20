/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _AUDMUX_H
#define _AUDMUX_H

#include "regs.h"

#ifndef REGS_AUDMUX_BASE
#define REGS_AUDMUX_BASE (REGS_BASE + 0x021d8000)

#endif


/*
 * HW_AUDMUX_PTCR1 - Port Timing Control Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFS : 1;
        unsigned TFSEL : 4;
        unsigned TCLKDIR : 1;
        unsigned TCSEL : 4;
        unsigned RFS : 1;
        unsigned RFSEL : 4;
        unsigned RCLKDIR : 1;
        unsigned RCSEL : 4;
        unsigned SYN : 1;
        unsigned RESERVED0 : 11;

    } B;
} hw_audmux_ptcr1_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR1 register
 */
#define HW_AUDMUX_PTCR1_ADDR      (REGS_AUDMUX_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR1           (*(volatile hw_audmux_ptcr1_t *) HW_AUDMUX_PTCR1_ADDR)
#define HW_AUDMUX_PTCR1_RD()      (HW_AUDMUX_PTCR1.U)
#define HW_AUDMUX_PTCR1_WR(v)     (HW_AUDMUX_PTCR1.U = (v))
#define HW_AUDMUX_PTCR1_SET(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() |  (v)))
#define HW_AUDMUX_PTCR1_CLR(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() & ~(v)))
#define HW_AUDMUX_PTCR1_TOG(v)    (HW_AUDMUX_PTCR1_WR(HW_AUDMUX_PTCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PTCR1 bitfields
 */

/* --- Register HW_AUDMUX_PTCR1, field TFS */

#define BP_AUDMUX_PTCR1_TFS      31
#define BM_AUDMUX_PTCR1_TFS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFS(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR1_TFS)
#else
#define BF_AUDMUX_PTCR1_TFS(v)   (((v) << 31) & BM_AUDMUX_PTCR1_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TFS(v)   BF_CS1(AUDMUX_PTCR1, TFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TFSEL */

#define BP_AUDMUX_PTCR1_TFSEL      27
#define BM_AUDMUX_PTCR1_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#else
#define BF_AUDMUX_PTCR1_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR1_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TFSEL(v)   BF_CS1(AUDMUX_PTCR1, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TCLKDIR */

#define BP_AUDMUX_PTCR1_TCLKDIR      26
#define BM_AUDMUX_PTCR1_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#else
#define BF_AUDMUX_PTCR1_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR1_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field TCSEL */

#define BP_AUDMUX_PTCR1_TCSEL      22
#define BM_AUDMUX_PTCR1_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#else
#define BF_AUDMUX_PTCR1_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR1_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_TCSEL(v)   BF_CS1(AUDMUX_PTCR1, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RFS */

#define BP_AUDMUX_PTCR1_RFS      21
#define BM_AUDMUX_PTCR1_RFS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFS(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR1_RFS)
#else
#define BF_AUDMUX_PTCR1_RFS(v)   (((v) << 21) & BM_AUDMUX_PTCR1_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RFS(v)   BF_CS1(AUDMUX_PTCR1, RFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RFSEL */

#define BP_AUDMUX_PTCR1_RFSEL      17
#define BM_AUDMUX_PTCR1_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#else
#define BF_AUDMUX_PTCR1_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR1_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RFSEL(v)   BF_CS1(AUDMUX_PTCR1, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RCLKDIR */

#define BP_AUDMUX_PTCR1_RCLKDIR      16
#define BM_AUDMUX_PTCR1_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#else
#define BF_AUDMUX_PTCR1_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR1_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR1, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field RCSEL */

#define BP_AUDMUX_PTCR1_RCSEL      12
#define BM_AUDMUX_PTCR1_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#else
#define BF_AUDMUX_PTCR1_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR1_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_RCSEL(v)   BF_CS1(AUDMUX_PTCR1, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR1, field SYN */

#define BP_AUDMUX_PTCR1_SYN      11
#define BM_AUDMUX_PTCR1_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR1_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR1_SYN)
#else
#define BF_AUDMUX_PTCR1_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR1_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR1_SYN(v)   BF_CS1(AUDMUX_PTCR1, SYN, v)
#endif

/*
 * HW_AUDMUX_PTCR2 - Port Timing Control Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFS : 1;
        unsigned TFSEL : 4;
        unsigned TCLKDIR : 1;
        unsigned TCSEL : 4;
        unsigned RFS : 1;
        unsigned RFSEL : 4;
        unsigned RCLKDIR : 1;
        unsigned RCSEL : 4;
        unsigned SYN : 1;
        unsigned RESERVED0 : 11;

    } B;
} hw_audmux_ptcr2_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR2 register
 */
#define HW_AUDMUX_PTCR2_ADDR      (REGS_AUDMUX_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR2           (*(volatile hw_audmux_ptcr2_t *) HW_AUDMUX_PTCR2_ADDR)
#define HW_AUDMUX_PTCR2_RD()      (HW_AUDMUX_PTCR2.U)
#define HW_AUDMUX_PTCR2_WR(v)     (HW_AUDMUX_PTCR2.U = (v))
#define HW_AUDMUX_PTCR2_SET(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() |  (v)))
#define HW_AUDMUX_PTCR2_CLR(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() & ~(v)))
#define HW_AUDMUX_PTCR2_TOG(v)    (HW_AUDMUX_PTCR2_WR(HW_AUDMUX_PTCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PTCR2 bitfields
 */

/* --- Register HW_AUDMUX_PTCR2, field TFS */

#define BP_AUDMUX_PTCR2_TFS      31
#define BM_AUDMUX_PTCR2_TFS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFS(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR2_TFS)
#else
#define BF_AUDMUX_PTCR2_TFS(v)   (((v) << 31) & BM_AUDMUX_PTCR2_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TFS(v)   BF_CS1(AUDMUX_PTCR2, TFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TFSEL */

#define BP_AUDMUX_PTCR2_TFSEL      27
#define BM_AUDMUX_PTCR2_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#else
#define BF_AUDMUX_PTCR2_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR2_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TFSEL(v)   BF_CS1(AUDMUX_PTCR2, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TCLKDIR */

#define BP_AUDMUX_PTCR2_TCLKDIR      26
#define BM_AUDMUX_PTCR2_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#else
#define BF_AUDMUX_PTCR2_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR2_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field TCSEL */

#define BP_AUDMUX_PTCR2_TCSEL      22
#define BM_AUDMUX_PTCR2_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#else
#define BF_AUDMUX_PTCR2_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR2_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_TCSEL(v)   BF_CS1(AUDMUX_PTCR2, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RFS */

#define BP_AUDMUX_PTCR2_RFS      21
#define BM_AUDMUX_PTCR2_RFS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFS(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR2_RFS)
#else
#define BF_AUDMUX_PTCR2_RFS(v)   (((v) << 21) & BM_AUDMUX_PTCR2_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RFS(v)   BF_CS1(AUDMUX_PTCR2, RFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RFSEL */

#define BP_AUDMUX_PTCR2_RFSEL      17
#define BM_AUDMUX_PTCR2_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#else
#define BF_AUDMUX_PTCR2_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR2_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RFSEL(v)   BF_CS1(AUDMUX_PTCR2, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RCLKDIR */

#define BP_AUDMUX_PTCR2_RCLKDIR      16
#define BM_AUDMUX_PTCR2_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#else
#define BF_AUDMUX_PTCR2_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR2_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR2, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field RCSEL */

#define BP_AUDMUX_PTCR2_RCSEL      12
#define BM_AUDMUX_PTCR2_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#else
#define BF_AUDMUX_PTCR2_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR2_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_RCSEL(v)   BF_CS1(AUDMUX_PTCR2, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR2, field SYN */

#define BP_AUDMUX_PTCR2_SYN      11
#define BM_AUDMUX_PTCR2_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR2_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR2_SYN)
#else
#define BF_AUDMUX_PTCR2_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR2_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR2_SYN(v)   BF_CS1(AUDMUX_PTCR2, SYN, v)
#endif

/*
 * HW_AUDMUX_PTCR3 - Port Timing Control Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFS : 1;
        unsigned TFSEL : 4;
        unsigned TCLKDIR : 1;
        unsigned TCSEL : 4;
        unsigned RFS : 1;
        unsigned RFSEL : 4;
        unsigned RCLKDIR : 1;
        unsigned RCSEL : 4;
        unsigned SYN : 1;
        unsigned RESERVED0 : 11;

    } B;
} hw_audmux_ptcr3_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR3 register
 */
#define HW_AUDMUX_PTCR3_ADDR      (REGS_AUDMUX_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR3           (*(volatile hw_audmux_ptcr3_t *) HW_AUDMUX_PTCR3_ADDR)
#define HW_AUDMUX_PTCR3_RD()      (HW_AUDMUX_PTCR3.U)
#define HW_AUDMUX_PTCR3_WR(v)     (HW_AUDMUX_PTCR3.U = (v))
#define HW_AUDMUX_PTCR3_SET(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() |  (v)))
#define HW_AUDMUX_PTCR3_CLR(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() & ~(v)))
#define HW_AUDMUX_PTCR3_TOG(v)    (HW_AUDMUX_PTCR3_WR(HW_AUDMUX_PTCR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PTCR3 bitfields
 */

/* --- Register HW_AUDMUX_PTCR3, field TFS */

#define BP_AUDMUX_PTCR3_TFS      31
#define BM_AUDMUX_PTCR3_TFS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFS(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR3_TFS)
#else
#define BF_AUDMUX_PTCR3_TFS(v)   (((v) << 31) & BM_AUDMUX_PTCR3_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TFS(v)   BF_CS1(AUDMUX_PTCR3, TFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TFSEL */

#define BP_AUDMUX_PTCR3_TFSEL      27
#define BM_AUDMUX_PTCR3_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#else
#define BF_AUDMUX_PTCR3_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR3_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TFSEL(v)   BF_CS1(AUDMUX_PTCR3, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TCLKDIR */

#define BP_AUDMUX_PTCR3_TCLKDIR      26
#define BM_AUDMUX_PTCR3_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#else
#define BF_AUDMUX_PTCR3_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR3_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field TCSEL */

#define BP_AUDMUX_PTCR3_TCSEL      22
#define BM_AUDMUX_PTCR3_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#else
#define BF_AUDMUX_PTCR3_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR3_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_TCSEL(v)   BF_CS1(AUDMUX_PTCR3, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RFS */

#define BP_AUDMUX_PTCR3_RFS      21
#define BM_AUDMUX_PTCR3_RFS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFS(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR3_RFS)
#else
#define BF_AUDMUX_PTCR3_RFS(v)   (((v) << 21) & BM_AUDMUX_PTCR3_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RFS(v)   BF_CS1(AUDMUX_PTCR3, RFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RFSEL */

#define BP_AUDMUX_PTCR3_RFSEL      17
#define BM_AUDMUX_PTCR3_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#else
#define BF_AUDMUX_PTCR3_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR3_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RFSEL(v)   BF_CS1(AUDMUX_PTCR3, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RCLKDIR */

#define BP_AUDMUX_PTCR3_RCLKDIR      16
#define BM_AUDMUX_PTCR3_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#else
#define BF_AUDMUX_PTCR3_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR3_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR3, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field RCSEL */

#define BP_AUDMUX_PTCR3_RCSEL      12
#define BM_AUDMUX_PTCR3_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#else
#define BF_AUDMUX_PTCR3_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR3_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_RCSEL(v)   BF_CS1(AUDMUX_PTCR3, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR3, field SYN */

#define BP_AUDMUX_PTCR3_SYN      11
#define BM_AUDMUX_PTCR3_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR3_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR3_SYN)
#else
#define BF_AUDMUX_PTCR3_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR3_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR3_SYN(v)   BF_CS1(AUDMUX_PTCR3, SYN, v)
#endif

/*
 * HW_AUDMUX_PTCR - Port Timing Control Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TFS : 1;
        unsigned TFSEL : 4;
        unsigned TCLKDIR : 1;
        unsigned TCSEL : 4;
        unsigned RFS : 1;
        unsigned RFSEL : 4;
        unsigned RCLKDIR : 1;
        unsigned RCSEL : 4;
        unsigned SYN : 1;
        unsigned RESERVED0 : 11;

    } B;
} hw_audmux_ptcr_t;
#endif

/*
 * constants & macros for entire AUDMUX_PTCR register
 */
#define HW_AUDMUX_PTCR_ADDR      (REGS_AUDMUX_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PTCR           (*(volatile hw_audmux_ptcr_t *) HW_AUDMUX_PTCR_ADDR)
#define HW_AUDMUX_PTCR_RD()      (HW_AUDMUX_PTCR.U)
#define HW_AUDMUX_PTCR_WR(v)     (HW_AUDMUX_PTCR.U = (v))
#define HW_AUDMUX_PTCR_SET(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() |  (v)))
#define HW_AUDMUX_PTCR_CLR(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() & ~(v)))
#define HW_AUDMUX_PTCR_TOG(v)    (HW_AUDMUX_PTCR_WR(HW_AUDMUX_PTCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PTCR bitfields
 */

/* --- Register HW_AUDMUX_PTCR, field TFS */

#define BP_AUDMUX_PTCR_TFS      31
#define BM_AUDMUX_PTCR_TFS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TFS(v)   ((((reg32_t) v) << 31) & BM_AUDMUX_PTCR_TFS)
#else
#define BF_AUDMUX_PTCR_TFS(v)   (((v) << 31) & BM_AUDMUX_PTCR_TFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TFS(v)   BF_CS1(AUDMUX_PTCR, TFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TFSEL */

#define BP_AUDMUX_PTCR_TFSEL      27
#define BM_AUDMUX_PTCR_TFSEL      0x78000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TFSEL(v)   ((((reg32_t) v) << 27) & BM_AUDMUX_PTCR_TFSEL)
#else
#define BF_AUDMUX_PTCR_TFSEL(v)   (((v) << 27) & BM_AUDMUX_PTCR_TFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TFSEL(v)   BF_CS1(AUDMUX_PTCR, TFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TCLKDIR */

#define BP_AUDMUX_PTCR_TCLKDIR      26
#define BM_AUDMUX_PTCR_TCLKDIR      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TCLKDIR(v)   ((((reg32_t) v) << 26) & BM_AUDMUX_PTCR_TCLKDIR)
#else
#define BF_AUDMUX_PTCR_TCLKDIR(v)   (((v) << 26) & BM_AUDMUX_PTCR_TCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TCLKDIR(v)   BF_CS1(AUDMUX_PTCR, TCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field TCSEL */

#define BP_AUDMUX_PTCR_TCSEL      22
#define BM_AUDMUX_PTCR_TCSEL      0x03c00000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_TCSEL(v)   ((((reg32_t) v) << 22) & BM_AUDMUX_PTCR_TCSEL)
#else
#define BF_AUDMUX_PTCR_TCSEL(v)   (((v) << 22) & BM_AUDMUX_PTCR_TCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_TCSEL(v)   BF_CS1(AUDMUX_PTCR, TCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RFS */

#define BP_AUDMUX_PTCR_RFS      21
#define BM_AUDMUX_PTCR_RFS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RFS(v)   ((((reg32_t) v) << 21) & BM_AUDMUX_PTCR_RFS)
#else
#define BF_AUDMUX_PTCR_RFS(v)   (((v) << 21) & BM_AUDMUX_PTCR_RFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RFS(v)   BF_CS1(AUDMUX_PTCR, RFS, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RFSEL */

#define BP_AUDMUX_PTCR_RFSEL      17
#define BM_AUDMUX_PTCR_RFSEL      0x001e0000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RFSEL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_PTCR_RFSEL)
#else
#define BF_AUDMUX_PTCR_RFSEL(v)   (((v) << 17) & BM_AUDMUX_PTCR_RFSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RFSEL(v)   BF_CS1(AUDMUX_PTCR, RFSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RCLKDIR */

#define BP_AUDMUX_PTCR_RCLKDIR      16
#define BM_AUDMUX_PTCR_RCLKDIR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RCLKDIR(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_PTCR_RCLKDIR)
#else
#define BF_AUDMUX_PTCR_RCLKDIR(v)   (((v) << 16) & BM_AUDMUX_PTCR_RCLKDIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RCLKDIR(v)   BF_CS1(AUDMUX_PTCR, RCLKDIR, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field RCSEL */

#define BP_AUDMUX_PTCR_RCSEL      12
#define BM_AUDMUX_PTCR_RCSEL      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_RCSEL(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PTCR_RCSEL)
#else
#define BF_AUDMUX_PTCR_RCSEL(v)   (((v) << 12) & BM_AUDMUX_PTCR_RCSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_RCSEL(v)   BF_CS1(AUDMUX_PTCR, RCSEL, v)
#endif

/* --- Register HW_AUDMUX_PTCR, field SYN */

#define BP_AUDMUX_PTCR_SYN      11
#define BM_AUDMUX_PTCR_SYN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PTCR_SYN(v)   ((((reg32_t) v) << 11) & BM_AUDMUX_PTCR_SYN)
#else
#define BF_AUDMUX_PTCR_SYN(v)   (((v) << 11) & BM_AUDMUX_PTCR_SYN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PTCR_SYN(v)   BF_CS1(AUDMUX_PTCR, SYN, v)
#endif

/*
 * HW_AUDMUX_PDCR1 - Port Data Control Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr1_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR1 register
 */
#define HW_AUDMUX_PDCR1_ADDR      (REGS_AUDMUX_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR1           (*(volatile hw_audmux_pdcr1_t *) HW_AUDMUX_PDCR1_ADDR)
#define HW_AUDMUX_PDCR1_RD()      (HW_AUDMUX_PDCR1.U)
#define HW_AUDMUX_PDCR1_WR(v)     (HW_AUDMUX_PDCR1.U = (v))
#define HW_AUDMUX_PDCR1_SET(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() |  (v)))
#define HW_AUDMUX_PDCR1_CLR(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() & ~(v)))
#define HW_AUDMUX_PDCR1_TOG(v)    (HW_AUDMUX_PDCR1_WR(HW_AUDMUX_PDCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR1 bitfields
 */

/* --- Register HW_AUDMUX_PDCR1, field RXDSEL */

#define BP_AUDMUX_PDCR1_RXDSEL      13
#define BM_AUDMUX_PDCR1_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR1_RXDSEL)
#else
#define BF_AUDMUX_PDCR1_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR1_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR1_RXDSEL(v)   BF_CS1(AUDMUX_PDCR1, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR1, field TXRXEN */

#define BP_AUDMUX_PDCR1_TXRXEN      12
#define BM_AUDMUX_PDCR1_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR1_TXRXEN)
#else
#define BF_AUDMUX_PDCR1_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR1_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR1_TXRXEN(v)   BF_CS1(AUDMUX_PDCR1, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR1, field MODE */

#define BP_AUDMUX_PDCR1_MODE      8
#define BM_AUDMUX_PDCR1_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR1_MODE)
#else
#define BF_AUDMUX_PDCR1_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR1_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR1_MODE(v)   BF_CS1(AUDMUX_PDCR1, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR1, field MODE */

#define BP_AUDMUX_PDCR1_MODE      8
#define BM_AUDMUX_PDCR1_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR1_MODE)
#else
#define BF_AUDMUX_PDCR1_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR1_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR1_MODE(v)   BF_CS1(AUDMUX_PDCR1, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR1, field INMMASK */

#define BP_AUDMUX_PDCR1_INMMASK      0
#define BM_AUDMUX_PDCR1_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR1_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR1_INMMASK)
#else
#define BF_AUDMUX_PDCR1_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR1_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR1_INMMASK(v)   BF_CS1(AUDMUX_PDCR1, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR2 - Port Data Control Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr2_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR2 register
 */
#define HW_AUDMUX_PDCR2_ADDR      (REGS_AUDMUX_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR2           (*(volatile hw_audmux_pdcr2_t *) HW_AUDMUX_PDCR2_ADDR)
#define HW_AUDMUX_PDCR2_RD()      (HW_AUDMUX_PDCR2.U)
#define HW_AUDMUX_PDCR2_WR(v)     (HW_AUDMUX_PDCR2.U = (v))
#define HW_AUDMUX_PDCR2_SET(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() |  (v)))
#define HW_AUDMUX_PDCR2_CLR(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() & ~(v)))
#define HW_AUDMUX_PDCR2_TOG(v)    (HW_AUDMUX_PDCR2_WR(HW_AUDMUX_PDCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR2 bitfields
 */

/* --- Register HW_AUDMUX_PDCR2, field RXDSEL */

#define BP_AUDMUX_PDCR2_RXDSEL      13
#define BM_AUDMUX_PDCR2_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR2_RXDSEL)
#else
#define BF_AUDMUX_PDCR2_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR2_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR2_RXDSEL(v)   BF_CS1(AUDMUX_PDCR2, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR2, field TXRXEN */

#define BP_AUDMUX_PDCR2_TXRXEN      12
#define BM_AUDMUX_PDCR2_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR2_TXRXEN)
#else
#define BF_AUDMUX_PDCR2_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR2_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR2_TXRXEN(v)   BF_CS1(AUDMUX_PDCR2, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR2, field MODE */

#define BP_AUDMUX_PDCR2_MODE      8
#define BM_AUDMUX_PDCR2_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR2_MODE)
#else
#define BF_AUDMUX_PDCR2_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR2_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR2_MODE(v)   BF_CS1(AUDMUX_PDCR2, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR2, field MODE */

#define BP_AUDMUX_PDCR2_MODE      8
#define BM_AUDMUX_PDCR2_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR2_MODE)
#else
#define BF_AUDMUX_PDCR2_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR2_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR2_MODE(v)   BF_CS1(AUDMUX_PDCR2, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR2, field INMMASK */

#define BP_AUDMUX_PDCR2_INMMASK      0
#define BM_AUDMUX_PDCR2_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR2_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR2_INMMASK)
#else
#define BF_AUDMUX_PDCR2_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR2_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR2_INMMASK(v)   BF_CS1(AUDMUX_PDCR2, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR3 - Port Data Control Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr3_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR3 register
 */
#define HW_AUDMUX_PDCR3_ADDR      (REGS_AUDMUX_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR3           (*(volatile hw_audmux_pdcr3_t *) HW_AUDMUX_PDCR3_ADDR)
#define HW_AUDMUX_PDCR3_RD()      (HW_AUDMUX_PDCR3.U)
#define HW_AUDMUX_PDCR3_WR(v)     (HW_AUDMUX_PDCR3.U = (v))
#define HW_AUDMUX_PDCR3_SET(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() |  (v)))
#define HW_AUDMUX_PDCR3_CLR(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() & ~(v)))
#define HW_AUDMUX_PDCR3_TOG(v)    (HW_AUDMUX_PDCR3_WR(HW_AUDMUX_PDCR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR3 bitfields
 */

/* --- Register HW_AUDMUX_PDCR3, field RXDSEL */

#define BP_AUDMUX_PDCR3_RXDSEL      13
#define BM_AUDMUX_PDCR3_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR3_RXDSEL)
#else
#define BF_AUDMUX_PDCR3_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR3_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR3_RXDSEL(v)   BF_CS1(AUDMUX_PDCR3, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR3, field TXRXEN */

#define BP_AUDMUX_PDCR3_TXRXEN      12
#define BM_AUDMUX_PDCR3_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR3_TXRXEN)
#else
#define BF_AUDMUX_PDCR3_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR3_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR3_TXRXEN(v)   BF_CS1(AUDMUX_PDCR3, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR3, field MODE */

#define BP_AUDMUX_PDCR3_MODE      8
#define BM_AUDMUX_PDCR3_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR3_MODE)
#else
#define BF_AUDMUX_PDCR3_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR3_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR3_MODE(v)   BF_CS1(AUDMUX_PDCR3, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR3, field MODE */

#define BP_AUDMUX_PDCR3_MODE      8
#define BM_AUDMUX_PDCR3_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR3_MODE)
#else
#define BF_AUDMUX_PDCR3_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR3_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR3_MODE(v)   BF_CS1(AUDMUX_PDCR3, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR3, field INMMASK */

#define BP_AUDMUX_PDCR3_INMMASK      0
#define BM_AUDMUX_PDCR3_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR3_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR3_INMMASK)
#else
#define BF_AUDMUX_PDCR3_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR3_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR3_INMMASK(v)   BF_CS1(AUDMUX_PDCR3, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR4 - Port Data Control Register 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr4_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR4 register
 */
#define HW_AUDMUX_PDCR4_ADDR      (REGS_AUDMUX_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR4           (*(volatile hw_audmux_pdcr4_t *) HW_AUDMUX_PDCR4_ADDR)
#define HW_AUDMUX_PDCR4_RD()      (HW_AUDMUX_PDCR4.U)
#define HW_AUDMUX_PDCR4_WR(v)     (HW_AUDMUX_PDCR4.U = (v))
#define HW_AUDMUX_PDCR4_SET(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() |  (v)))
#define HW_AUDMUX_PDCR4_CLR(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() & ~(v)))
#define HW_AUDMUX_PDCR4_TOG(v)    (HW_AUDMUX_PDCR4_WR(HW_AUDMUX_PDCR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR4 bitfields
 */

/* --- Register HW_AUDMUX_PDCR4, field RXDSEL */

#define BP_AUDMUX_PDCR4_RXDSEL      13
#define BM_AUDMUX_PDCR4_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR4_RXDSEL)
#else
#define BF_AUDMUX_PDCR4_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR4_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR4_RXDSEL(v)   BF_CS1(AUDMUX_PDCR4, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR4, field TXRXEN */

#define BP_AUDMUX_PDCR4_TXRXEN      12
#define BM_AUDMUX_PDCR4_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR4_TXRXEN)
#else
#define BF_AUDMUX_PDCR4_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR4_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR4_TXRXEN(v)   BF_CS1(AUDMUX_PDCR4, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR4, field MODE */

#define BP_AUDMUX_PDCR4_MODE      8
#define BM_AUDMUX_PDCR4_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR4_MODE)
#else
#define BF_AUDMUX_PDCR4_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR4_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR4_MODE(v)   BF_CS1(AUDMUX_PDCR4, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR4, field MODE */

#define BP_AUDMUX_PDCR4_MODE      8
#define BM_AUDMUX_PDCR4_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR4_MODE)
#else
#define BF_AUDMUX_PDCR4_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR4_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR4_MODE(v)   BF_CS1(AUDMUX_PDCR4, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR4, field INMMASK */

#define BP_AUDMUX_PDCR4_INMMASK      0
#define BM_AUDMUX_PDCR4_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR4_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR4_INMMASK)
#else
#define BF_AUDMUX_PDCR4_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR4_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR4_INMMASK(v)   BF_CS1(AUDMUX_PDCR4, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR5 - Port Data Control Register 5
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr5_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR5 register
 */
#define HW_AUDMUX_PDCR5_ADDR      (REGS_AUDMUX_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR5           (*(volatile hw_audmux_pdcr5_t *) HW_AUDMUX_PDCR5_ADDR)
#define HW_AUDMUX_PDCR5_RD()      (HW_AUDMUX_PDCR5.U)
#define HW_AUDMUX_PDCR5_WR(v)     (HW_AUDMUX_PDCR5.U = (v))
#define HW_AUDMUX_PDCR5_SET(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() |  (v)))
#define HW_AUDMUX_PDCR5_CLR(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() & ~(v)))
#define HW_AUDMUX_PDCR5_TOG(v)    (HW_AUDMUX_PDCR5_WR(HW_AUDMUX_PDCR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR5 bitfields
 */

/* --- Register HW_AUDMUX_PDCR5, field RXDSEL */

#define BP_AUDMUX_PDCR5_RXDSEL      13
#define BM_AUDMUX_PDCR5_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR5_RXDSEL)
#else
#define BF_AUDMUX_PDCR5_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR5_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR5_RXDSEL(v)   BF_CS1(AUDMUX_PDCR5, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR5, field TXRXEN */

#define BP_AUDMUX_PDCR5_TXRXEN      12
#define BM_AUDMUX_PDCR5_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR5_TXRXEN)
#else
#define BF_AUDMUX_PDCR5_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR5_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR5_TXRXEN(v)   BF_CS1(AUDMUX_PDCR5, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR5, field MODE */

#define BP_AUDMUX_PDCR5_MODE      8
#define BM_AUDMUX_PDCR5_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR5_MODE)
#else
#define BF_AUDMUX_PDCR5_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR5_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR5_MODE(v)   BF_CS1(AUDMUX_PDCR5, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR5, field MODE */

#define BP_AUDMUX_PDCR5_MODE      8
#define BM_AUDMUX_PDCR5_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR5_MODE)
#else
#define BF_AUDMUX_PDCR5_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR5_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR5_MODE(v)   BF_CS1(AUDMUX_PDCR5, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR5, field INMMASK */

#define BP_AUDMUX_PDCR5_INMMASK      0
#define BM_AUDMUX_PDCR5_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR5_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR5_INMMASK)
#else
#define BF_AUDMUX_PDCR5_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR5_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR5_INMMASK(v)   BF_CS1(AUDMUX_PDCR5, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR6 - Port Data Control Register 6
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr6_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR6 register
 */
#define HW_AUDMUX_PDCR6_ADDR      (REGS_AUDMUX_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR6           (*(volatile hw_audmux_pdcr6_t *) HW_AUDMUX_PDCR6_ADDR)
#define HW_AUDMUX_PDCR6_RD()      (HW_AUDMUX_PDCR6.U)
#define HW_AUDMUX_PDCR6_WR(v)     (HW_AUDMUX_PDCR6.U = (v))
#define HW_AUDMUX_PDCR6_SET(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() |  (v)))
#define HW_AUDMUX_PDCR6_CLR(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() & ~(v)))
#define HW_AUDMUX_PDCR6_TOG(v)    (HW_AUDMUX_PDCR6_WR(HW_AUDMUX_PDCR6_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR6 bitfields
 */

/* --- Register HW_AUDMUX_PDCR6, field RXDSEL */

#define BP_AUDMUX_PDCR6_RXDSEL      13
#define BM_AUDMUX_PDCR6_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR6_RXDSEL)
#else
#define BF_AUDMUX_PDCR6_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR6_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR6_RXDSEL(v)   BF_CS1(AUDMUX_PDCR6, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR6, field TXRXEN */

#define BP_AUDMUX_PDCR6_TXRXEN      12
#define BM_AUDMUX_PDCR6_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR6_TXRXEN)
#else
#define BF_AUDMUX_PDCR6_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR6_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR6_TXRXEN(v)   BF_CS1(AUDMUX_PDCR6, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR6, field MODE */

#define BP_AUDMUX_PDCR6_MODE      8
#define BM_AUDMUX_PDCR6_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR6_MODE)
#else
#define BF_AUDMUX_PDCR6_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR6_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR6_MODE(v)   BF_CS1(AUDMUX_PDCR6, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR6, field MODE */

#define BP_AUDMUX_PDCR6_MODE      8
#define BM_AUDMUX_PDCR6_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR6_MODE)
#else
#define BF_AUDMUX_PDCR6_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR6_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR6_MODE(v)   BF_CS1(AUDMUX_PDCR6, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR6, field INMMASK */

#define BP_AUDMUX_PDCR6_INMMASK      0
#define BM_AUDMUX_PDCR6_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR6_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR6_INMMASK)
#else
#define BF_AUDMUX_PDCR6_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR6_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR6_INMMASK(v)   BF_CS1(AUDMUX_PDCR6, INMMASK, v)
#endif

/*
 * HW_AUDMUX_PDCR7 - Port Data Control Register 7
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RXDSEL : 3;
        unsigned TXRXEN : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 2;
        unsigned MODE : 1;
        unsigned MODE : 2;
        unsigned INMMASK : 8;

    } B;
} hw_audmux_pdcr7_t;
#endif

/*
 * constants & macros for entire AUDMUX_PDCR7 register
 */
#define HW_AUDMUX_PDCR7_ADDR      (REGS_AUDMUX_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_PDCR7           (*(volatile hw_audmux_pdcr7_t *) HW_AUDMUX_PDCR7_ADDR)
#define HW_AUDMUX_PDCR7_RD()      (HW_AUDMUX_PDCR7.U)
#define HW_AUDMUX_PDCR7_WR(v)     (HW_AUDMUX_PDCR7.U = (v))
#define HW_AUDMUX_PDCR7_SET(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() |  (v)))
#define HW_AUDMUX_PDCR7_CLR(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() & ~(v)))
#define HW_AUDMUX_PDCR7_TOG(v)    (HW_AUDMUX_PDCR7_WR(HW_AUDMUX_PDCR7_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_PDCR7 bitfields
 */

/* --- Register HW_AUDMUX_PDCR7, field RXDSEL */

#define BP_AUDMUX_PDCR7_RXDSEL      13
#define BM_AUDMUX_PDCR7_RXDSEL      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_RXDSEL(v)   ((((reg32_t) v) << 13) & BM_AUDMUX_PDCR7_RXDSEL)
#else
#define BF_AUDMUX_PDCR7_RXDSEL(v)   (((v) << 13) & BM_AUDMUX_PDCR7_RXDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR7_RXDSEL(v)   BF_CS1(AUDMUX_PDCR7, RXDSEL, v)
#endif

/* --- Register HW_AUDMUX_PDCR7, field TXRXEN */

#define BP_AUDMUX_PDCR7_TXRXEN      12
#define BM_AUDMUX_PDCR7_TXRXEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_TXRXEN(v)   ((((reg32_t) v) << 12) & BM_AUDMUX_PDCR7_TXRXEN)
#else
#define BF_AUDMUX_PDCR7_TXRXEN(v)   (((v) << 12) & BM_AUDMUX_PDCR7_TXRXEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR7_TXRXEN(v)   BF_CS1(AUDMUX_PDCR7, TXRXEN, v)
#endif

/* --- Register HW_AUDMUX_PDCR7, field MODE */

#define BP_AUDMUX_PDCR7_MODE      8
#define BM_AUDMUX_PDCR7_MODE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR7_MODE)
#else
#define BF_AUDMUX_PDCR7_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR7_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR7_MODE(v)   BF_CS1(AUDMUX_PDCR7, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR7, field MODE */

#define BP_AUDMUX_PDCR7_MODE      8
#define BM_AUDMUX_PDCR7_MODE      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_MODE(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_PDCR7_MODE)
#else
#define BF_AUDMUX_PDCR7_MODE(v)   (((v) << 8) & BM_AUDMUX_PDCR7_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR7_MODE(v)   BF_CS1(AUDMUX_PDCR7, MODE, v)
#endif

/* --- Register HW_AUDMUX_PDCR7, field INMMASK */

#define BP_AUDMUX_PDCR7_INMMASK      0
#define BM_AUDMUX_PDCR7_INMMASK      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_PDCR7_INMMASK(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_PDCR7_INMMASK)
#else
#define BF_AUDMUX_PDCR7_INMMASK(v)   (((v) << 0) & BM_AUDMUX_PDCR7_INMMASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_PDCR7_INMMASK(v)   BF_CS1(AUDMUX_PDCR7, INMMASK, v)
#endif

/*
 * HW_AUDMUX_CNMCR - CE Bus Network Mode Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 13;
        unsigned CEN : 1;
        unsigned FSPOL : 1;
        unsigned CLKPOL : 1;
        unsigned CNTHI : 8;
        unsigned CNTLOW : 8;

    } B;
} hw_audmux_cnmcr_t;
#endif

/*
 * constants & macros for entire AUDMUX_CNMCR register
 */
#define HW_AUDMUX_CNMCR_ADDR      (REGS_AUDMUX_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_AUDMUX_CNMCR           (*(volatile hw_audmux_cnmcr_t *) HW_AUDMUX_CNMCR_ADDR)
#define HW_AUDMUX_CNMCR_RD()      (HW_AUDMUX_CNMCR.U)
#define HW_AUDMUX_CNMCR_WR(v)     (HW_AUDMUX_CNMCR.U = (v))
#define HW_AUDMUX_CNMCR_SET(v)    (HW_AUDMUX_CNMCR_WR(HW_AUDMUX_CNMCR_RD() |  (v)))
#define HW_AUDMUX_CNMCR_CLR(v)    (HW_AUDMUX_CNMCR_WR(HW_AUDMUX_CNMCR_RD() & ~(v)))
#define HW_AUDMUX_CNMCR_TOG(v)    (HW_AUDMUX_CNMCR_WR(HW_AUDMUX_CNMCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual AUDMUX_CNMCR bitfields
 */

/* --- Register HW_AUDMUX_CNMCR, field CEN */

#define BP_AUDMUX_CNMCR_CEN      18
#define BM_AUDMUX_CNMCR_CEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_CNMCR_CEN(v)   ((((reg32_t) v) << 18) & BM_AUDMUX_CNMCR_CEN)
#else
#define BF_AUDMUX_CNMCR_CEN(v)   (((v) << 18) & BM_AUDMUX_CNMCR_CEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_CNMCR_CEN(v)   BF_CS1(AUDMUX_CNMCR, CEN, v)
#endif

/* --- Register HW_AUDMUX_CNMCR, field FSPOL */

#define BP_AUDMUX_CNMCR_FSPOL      17
#define BM_AUDMUX_CNMCR_FSPOL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_CNMCR_FSPOL(v)   ((((reg32_t) v) << 17) & BM_AUDMUX_CNMCR_FSPOL)
#else
#define BF_AUDMUX_CNMCR_FSPOL(v)   (((v) << 17) & BM_AUDMUX_CNMCR_FSPOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_CNMCR_FSPOL(v)   BF_CS1(AUDMUX_CNMCR, FSPOL, v)
#endif

/* --- Register HW_AUDMUX_CNMCR, field CLKPOL */

#define BP_AUDMUX_CNMCR_CLKPOL      16
#define BM_AUDMUX_CNMCR_CLKPOL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_CNMCR_CLKPOL(v)   ((((reg32_t) v) << 16) & BM_AUDMUX_CNMCR_CLKPOL)
#else
#define BF_AUDMUX_CNMCR_CLKPOL(v)   (((v) << 16) & BM_AUDMUX_CNMCR_CLKPOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_CNMCR_CLKPOL(v)   BF_CS1(AUDMUX_CNMCR, CLKPOL, v)
#endif

/* --- Register HW_AUDMUX_CNMCR, field CNTHI */

#define BP_AUDMUX_CNMCR_CNTHI      8
#define BM_AUDMUX_CNMCR_CNTHI      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_CNMCR_CNTHI(v)   ((((reg32_t) v) << 8) & BM_AUDMUX_CNMCR_CNTHI)
#else
#define BF_AUDMUX_CNMCR_CNTHI(v)   (((v) << 8) & BM_AUDMUX_CNMCR_CNTHI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_CNMCR_CNTHI(v)   BF_CS1(AUDMUX_CNMCR, CNTHI, v)
#endif

/* --- Register HW_AUDMUX_CNMCR, field CNTLOW */

#define BP_AUDMUX_CNMCR_CNTLOW      0
#define BM_AUDMUX_CNMCR_CNTLOW      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_AUDMUX_CNMCR_CNTLOW(v)   ((((reg32_t) v) << 0) & BM_AUDMUX_CNMCR_CNTLOW)
#else
#define BF_AUDMUX_CNMCR_CNTLOW(v)   (((v) << 0) & BM_AUDMUX_CNMCR_CNTLOW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_AUDMUX_CNMCR_CNTLOW(v)   BF_CS1(AUDMUX_CNMCR, CNTLOW, v)
#endif


#endif // _AUDMUX_H

