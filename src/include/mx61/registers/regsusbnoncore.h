/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USBNC_H
#define _USBNC_H

#include "regs.h"

#ifndef REGS_USBNC_BASE
#define REGS_USBNC_BASE (REGS_BASE + 0x02184000)

#endif


/*
 * HW_USBNC_USB_OTG_CTRL - USB OTG Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned OVER_CUR_DIS : 1;
        unsigned OVER_CUR_POL : 1;
        unsigned PWR_POL : 1;
        unsigned WIE : 1;
        unsigned RESET : 1;
        unsigned SUSPENDM : 1;
        unsigned UTMI_ON_CLOCK : 1;
        unsigned WKUP_SW_EN : 1;
        unsigned WKUP_SW : 1;
        unsigned WKUP_ID_EN : 1;
        unsigned WKUP_VBUS_EN : 1;
        unsigned RESERVED1 : 13;
        unsigned FLT_DIS : 1;
        unsigned PHY_CLK_JIT : 3;
        unsigned RESERVED2 : 1;
        unsigned FORCE_FS : 1;
        unsigned RESERVED3 : 7;
        unsigned WIR : 1;

    } B;
} hw_usbnc_usb_otg_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG_CTRL register
 */
#define HW_USBNC_USB_OTG_CTRL_ADDR      (REGS_USBNC_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG_CTRL           (*(volatile hw_usbnc_usb_otg_ctrl_t *) HW_USBNC_USB_OTG_CTRL_ADDR)
#define HW_USBNC_USB_OTG_CTRL_RD()      (HW_USBNC_USB_OTG_CTRL.U)
#define HW_USBNC_USB_OTG_CTRL_WR(v)     (HW_USBNC_USB_OTG_CTRL.U = (v))
#define HW_USBNC_USB_OTG_CTRL_SET(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() |  (v)))
#define HW_USBNC_USB_OTG_CTRL_CLR(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_OTG_CTRL_TOG(v)    (HW_USBNC_USB_OTG_CTRL_WR(HW_USBNC_USB_OTG_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_OTG_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_DIS */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      7
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_DIS, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field OVER_CUR_POL */

#define BP_USBNC_USB_OTG_CTRL_OVER_CUR_POL      8
#define BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_OTG_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, OVER_CUR_POL, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field PWR_POL */

#define BP_USBNC_USB_OTG_CTRL_PWR_POL      9
#define BM_USBNC_USB_OTG_CTRL_PWR_POL      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_OTG_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_OTG_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_OTG_CTRL, PWR_POL, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WIE */

#define BP_USBNC_USB_OTG_CTRL_WIE      10
#define BM_USBNC_USB_OTG_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#else
#define BF_USBNC_USB_OTG_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_OTG_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WIE(v)   BF_CS1(USBNC_USB_OTG_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field RESET */

#define BP_USBNC_USB_OTG_CTRL_RESET      11
#define BM_USBNC_USB_OTG_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#else
#define BF_USBNC_USB_OTG_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_OTG_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_RESET(v)   BF_CS1(USBNC_USB_OTG_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field SUSPENDM */

#define BP_USBNC_USB_OTG_CTRL_SUSPENDM      12
#define BM_USBNC_USB_OTG_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_OTG_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_OTG_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_OTG_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field UTMI_ON_CLOCK */

#define BP_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      13
#define BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_OTG_CTRL, UTMI_ON_CLOCK, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW_EN */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_OTG_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_SW */

#define BP_USBNC_USB_OTG_CTRL_WKUP_SW      15
#define BM_USBNC_USB_OTG_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_OTG_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_ID_EN */

#define BP_USBNC_USB_OTG_CTRL_WKUP_ID_EN      16
#define BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_OTG_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_ID_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WKUP_VBUS_EN */

#define BP_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      17
#define BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_OTG_CTRL, WKUP_VBUS_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field FLT_DIS */

#define BP_USBNC_USB_OTG_CTRL_FLT_DIS      18
#define BM_USBNC_USB_OTG_CTRL_FLT_DIS      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_FLT_DIS(v)   ((((reg32_t) v) << 18) & BM_USBNC_USB_OTG_CTRL_FLT_DIS)
#else
#define BF_USBNC_USB_OTG_CTRL_FLT_DIS(v)   (((v) << 18) & BM_USBNC_USB_OTG_CTRL_FLT_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_FLT_DIS(v)   BF_CS1(USBNC_USB_OTG_CTRL, FLT_DIS, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field PHY_CLK_JIT */

#define BP_USBNC_USB_OTG_CTRL_PHY_CLK_JIT      19
#define BM_USBNC_USB_OTG_CTRL_PHY_CLK_JIT      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_PHY_CLK_JIT(v)   ((((reg32_t) v) << 19) & BM_USBNC_USB_OTG_CTRL_PHY_CLK_JIT)
#else
#define BF_USBNC_USB_OTG_CTRL_PHY_CLK_JIT(v)   (((v) << 19) & BM_USBNC_USB_OTG_CTRL_PHY_CLK_JIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_PHY_CLK_JIT(v)   BF_CS1(USBNC_USB_OTG_CTRL, PHY_CLK_JIT, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field FORCE_FS */

#define BP_USBNC_USB_OTG_CTRL_FORCE_FS      23
#define BM_USBNC_USB_OTG_CTRL_FORCE_FS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_FORCE_FS(v)   ((((reg32_t) v) << 23) & BM_USBNC_USB_OTG_CTRL_FORCE_FS)
#else
#define BF_USBNC_USB_OTG_CTRL_FORCE_FS(v)   (((v) << 23) & BM_USBNC_USB_OTG_CTRL_FORCE_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_FORCE_FS(v)   BF_CS1(USBNC_USB_OTG_CTRL, FORCE_FS, v)
#endif

/* --- Register HW_USBNC_USB_OTG_CTRL, field WIR */

#define BP_USBNC_USB_OTG_CTRL_WIR      31
#define BM_USBNC_USB_OTG_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_OTG_CTRL_WIR)
#else
#define BF_USBNC_USB_OTG_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_OTG_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_CTRL_WIR(v)   BF_CS1(USBNC_USB_OTG_CTRL, WIR, v)
#endif

/*
 * HW_USBNC_USB_UH1_CTRL - USB Host1 Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned OVER_CUR_DIS : 1;
        unsigned OVER_CUR_POL : 1;
        unsigned PWR_POL : 1;
        unsigned WIE : 1;
        unsigned RESET : 1;
        unsigned SUSPENDM : 1;
        unsigned UTMI_ON_CLOCK : 1;
        unsigned WKUP_SW_EN : 1;
        unsigned WKUP_SW : 1;
        unsigned WKUP_ID_EN : 1;
        unsigned WKUP_VBUS_EN : 1;
        unsigned RESERVED1 : 13;
        unsigned RESERVED2 : 5;
        unsigned FORCE_FS : 1;
        unsigned RESERVED3 : 7;
        unsigned WIR : 1;

    } B;
} hw_usbnc_usb_uh1_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH1_CTRL register
 */
#define HW_USBNC_USB_UH1_CTRL_ADDR      (REGS_USBNC_BASE + 0x804)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH1_CTRL           (*(volatile hw_usbnc_usb_uh1_ctrl_t *) HW_USBNC_USB_UH1_CTRL_ADDR)
#define HW_USBNC_USB_UH1_CTRL_RD()      (HW_USBNC_USB_UH1_CTRL.U)
#define HW_USBNC_USB_UH1_CTRL_WR(v)     (HW_USBNC_USB_UH1_CTRL.U = (v))
#define HW_USBNC_USB_UH1_CTRL_SET(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH1_CTRL_CLR(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH1_CTRL_TOG(v)    (HW_USBNC_USB_UH1_CTRL_WR(HW_USBNC_USB_UH1_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH1_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_DIS */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      7
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   ((((reg32_t) v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   (((v) << 7) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_DIS(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_DIS, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field OVER_CUR_POL */

#define BP_USBNC_USB_UH1_CTRL_OVER_CUR_POL      8
#define BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   ((((reg32_t) v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   (((v) << 8) & BM_USBNC_USB_UH1_CTRL_OVER_CUR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_OVER_CUR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, OVER_CUR_POL, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field PWR_POL */

#define BP_USBNC_USB_UH1_CTRL_PWR_POL      9
#define BM_USBNC_USB_UH1_CTRL_PWR_POL      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   ((((reg32_t) v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#else
#define BF_USBNC_USB_UH1_CTRL_PWR_POL(v)   (((v) << 9) & BM_USBNC_USB_UH1_CTRL_PWR_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_PWR_POL(v)   BF_CS1(USBNC_USB_UH1_CTRL, PWR_POL, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WIE */

#define BP_USBNC_USB_UH1_CTRL_WIE      10
#define BM_USBNC_USB_UH1_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#else
#define BF_USBNC_USB_UH1_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH1_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH1_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field RESET */

#define BP_USBNC_USB_UH1_CTRL_RESET      11
#define BM_USBNC_USB_UH1_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#else
#define BF_USBNC_USB_UH1_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH1_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH1_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field SUSPENDM */

#define BP_USBNC_USB_UH1_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH1_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH1_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH1_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH1_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field UTMI_ON_CLOCK */

#define BP_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      13
#define BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#else
#define BF_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   (((v) << 13) & BM_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_UTMI_ON_CLOCK(v)   BF_CS1(USBNC_USB_UH1_CTRL, UTMI_ON_CLOCK, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW_EN */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH1_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_SW */

#define BP_USBNC_USB_UH1_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH1_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH1_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_ID_EN */

#define BP_USBNC_USB_UH1_CTRL_WKUP_ID_EN      16
#define BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   (((v) << 16) & BM_USBNC_USB_UH1_CTRL_WKUP_ID_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_ID_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_ID_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WKUP_VBUS_EN */

#define BP_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      17
#define BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   ((((reg32_t) v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#else
#define BF_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   (((v) << 17) & BM_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WKUP_VBUS_EN(v)   BF_CS1(USBNC_USB_UH1_CTRL, WKUP_VBUS_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field FORCE_FS */

#define BP_USBNC_USB_UH1_CTRL_FORCE_FS      23
#define BM_USBNC_USB_UH1_CTRL_FORCE_FS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_FORCE_FS(v)   ((((reg32_t) v) << 23) & BM_USBNC_USB_UH1_CTRL_FORCE_FS)
#else
#define BF_USBNC_USB_UH1_CTRL_FORCE_FS(v)   (((v) << 23) & BM_USBNC_USB_UH1_CTRL_FORCE_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_FORCE_FS(v)   BF_CS1(USBNC_USB_UH1_CTRL, FORCE_FS, v)
#endif

/* --- Register HW_USBNC_USB_UH1_CTRL, field WIR */

#define BP_USBNC_USB_UH1_CTRL_WIR      31
#define BM_USBNC_USB_UH1_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH1_CTRL_WIR)
#else
#define BF_USBNC_USB_UH1_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH1_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH1_CTRL, WIR, v)
#endif

/*
 * HW_USBNC_USB_UH2_CTRL - USB Host2 Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10;
        unsigned WIE : 1;
        unsigned RESET : 1;
        unsigned SUSPENDM : 1;
        unsigned RESERVED1 : 1;
        unsigned WKUP_SW_EN : 1;
        unsigned WKUP_SW : 1;
        unsigned RESERVED2 : 15;
        unsigned WIR : 1;

    } B;
} hw_usbnc_usb_uh2_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_CTRL register
 */
#define HW_USBNC_USB_UH2_CTRL_ADDR      (REGS_USBNC_BASE + 0x808)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_CTRL           (*(volatile hw_usbnc_usb_uh2_ctrl_t *) HW_USBNC_USB_UH2_CTRL_ADDR)
#define HW_USBNC_USB_UH2_CTRL_RD()      (HW_USBNC_USB_UH2_CTRL.U)
#define HW_USBNC_USB_UH2_CTRL_WR(v)     (HW_USBNC_USB_UH2_CTRL.U = (v))
#define HW_USBNC_USB_UH2_CTRL_SET(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH2_CTRL_CLR(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH2_CTRL_TOG(v)    (HW_USBNC_USB_UH2_CTRL_WR(HW_USBNC_USB_UH2_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH2_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH2_CTRL, field WIE */

#define BP_USBNC_USB_UH2_CTRL_WIE      10
#define BM_USBNC_USB_UH2_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#else
#define BF_USBNC_USB_UH2_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH2_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH2_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field RESET */

#define BP_USBNC_USB_UH2_CTRL_RESET      11
#define BM_USBNC_USB_UH2_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#else
#define BF_USBNC_USB_UH2_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH2_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH2_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field SUSPENDM */

#define BP_USBNC_USB_UH2_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH2_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH2_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH2_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH2_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW_EN */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH2_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WKUP_SW */

#define BP_USBNC_USB_UH2_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH2_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH2_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH2_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH2_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH2_CTRL, field WIR */

#define BP_USBNC_USB_UH2_CTRL_WIR      31
#define BM_USBNC_USB_UH2_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH2_CTRL_WIR)
#else
#define BF_USBNC_USB_UH2_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH2_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH2_CTRL, WIR, v)
#endif

/*
 * HW_USBNC_USB_UH3_CTRL - USB Host3 Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10;
        unsigned WIE : 1;
        unsigned RESET : 1;
        unsigned SUSPENDM : 1;
        unsigned RESERVED1 : 1;
        unsigned WKUP_SW_EN : 1;
        unsigned WKUP_SW : 1;
        unsigned RESERVED2 : 15;
        unsigned WIR : 1;

    } B;
} hw_usbnc_usb_uh3_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_CTRL register
 */
#define HW_USBNC_USB_UH3_CTRL_ADDR      (REGS_USBNC_BASE + 0x80c)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_CTRL           (*(volatile hw_usbnc_usb_uh3_ctrl_t *) HW_USBNC_USB_UH3_CTRL_ADDR)
#define HW_USBNC_USB_UH3_CTRL_RD()      (HW_USBNC_USB_UH3_CTRL.U)
#define HW_USBNC_USB_UH3_CTRL_WR(v)     (HW_USBNC_USB_UH3_CTRL.U = (v))
#define HW_USBNC_USB_UH3_CTRL_SET(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH3_CTRL_CLR(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH3_CTRL_TOG(v)    (HW_USBNC_USB_UH3_CTRL_WR(HW_USBNC_USB_UH3_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH3_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH3_CTRL, field WIE */

#define BP_USBNC_USB_UH3_CTRL_WIE      10
#define BM_USBNC_USB_UH3_CTRL_WIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   ((((reg32_t) v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#else
#define BF_USBNC_USB_UH3_CTRL_WIE(v)   (((v) << 10) & BM_USBNC_USB_UH3_CTRL_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WIE(v)   BF_CS1(USBNC_USB_UH3_CTRL, WIE, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field RESET */

#define BP_USBNC_USB_UH3_CTRL_RESET      11
#define BM_USBNC_USB_UH3_CTRL_RESET      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#else
#define BF_USBNC_USB_UH3_CTRL_RESET(v)   (((v) << 11) & BM_USBNC_USB_UH3_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_RESET(v)   BF_CS1(USBNC_USB_UH3_CTRL, RESET, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field SUSPENDM */

#define BP_USBNC_USB_UH3_CTRL_SUSPENDM      12
#define BM_USBNC_USB_UH3_CTRL_SUSPENDM      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#else
#define BF_USBNC_USB_UH3_CTRL_SUSPENDM(v)   (((v) << 12) & BM_USBNC_USB_UH3_CTRL_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_SUSPENDM(v)   BF_CS1(USBNC_USB_UH3_CTRL, SUSPENDM, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW_EN */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW_EN      14
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   (((v) << 14) & BM_USBNC_USB_UH3_CTRL_WKUP_SW_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW_EN(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WKUP_SW */

#define BP_USBNC_USB_UH3_CTRL_WKUP_SW      15
#define BM_USBNC_USB_UH3_CTRL_WKUP_SW      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#else
#define BF_USBNC_USB_UH3_CTRL_WKUP_SW(v)   (((v) << 15) & BM_USBNC_USB_UH3_CTRL_WKUP_SW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WKUP_SW(v)   BF_CS1(USBNC_USB_UH3_CTRL, WKUP_SW, v)
#endif

/* --- Register HW_USBNC_USB_UH3_CTRL, field WIR */

#define BP_USBNC_USB_UH3_CTRL_WIR      31
#define BM_USBNC_USB_UH3_CTRL_WIR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_CTRL_WIR(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH3_CTRL_WIR)
#else
#define BF_USBNC_USB_UH3_CTRL_WIR(v)   (((v) << 31) & BM_USBNC_USB_UH3_CTRL_WIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_CTRL_WIR(v)   BF_CS1(USBNC_USB_UH3_CTRL, WIR, v)
#endif

/*
 * HW_USBNC_USB_UH2_HSIC_CTRL - USB Host2 HSIC Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11;
        unsigned HSIC_CLK_ON : 1;
        unsigned HSIC_EN : 1;
        unsigned RESERVED1 : 18;
        unsigned IDLE_DETECT_OPTION : 1;
        unsigned LOOPBACK_DISABLE : 1;
        unsigned KEEPEN_FORCE : 1;
        unsigned KEEPEN_ASYNC_RST : 1;
        unsigned RESERVED2 : 14;
        unsigned CLK_VLD : 1;

    } B;
} hw_usbnc_usb_uh2_hsic_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_HSIC_CTRL register
 */
#define HW_USBNC_USB_UH2_HSIC_CTRL_ADDR      (REGS_USBNC_BASE + 0x810)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_HSIC_CTRL           (*(volatile hw_usbnc_usb_uh2_hsic_ctrl_t *) HW_USBNC_USB_UH2_HSIC_CTRL_ADDR)
#define HW_USBNC_USB_UH2_HSIC_CTRL_RD()      (HW_USBNC_USB_UH2_HSIC_CTRL.U)
#define HW_USBNC_USB_UH2_HSIC_CTRL_WR(v)     (HW_USBNC_USB_UH2_HSIC_CTRL.U = (v))
#define HW_USBNC_USB_UH2_HSIC_CTRL_SET(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH2_HSIC_CTRL_CLR(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH2_HSIC_CTRL_TOG(v)    (HW_USBNC_USB_UH2_HSIC_CTRL_WR(HW_USBNC_USB_UH2_HSIC_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH2_HSIC_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_CLK_ON */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      11
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_CLK_ON, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field HSIC_EN */

#define BP_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      12
#define BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, HSIC_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field IDLE_DETECT_OPTION */

#define BP_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION      13
#define BM_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION(v)   (((v) << 13) & BM_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_IDLE_DETECT_OPTION(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, IDLE_DETECT_OPTION, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field LOOPBACK_DISABLE */

#define BP_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE      14
#define BM_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE(v)   (((v) << 14) & BM_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_LOOPBACK_DISABLE(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, LOOPBACK_DISABLE, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field KEEPEN_FORCE */

#define BP_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE      15
#define BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE(v)   (((v) << 15) & BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_FORCE(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, KEEPEN_FORCE, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field KEEPEN_ASYNC_RST */

#define BP_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST      16
#define BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   (((v) << 16) & BM_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, KEEPEN_ASYNC_RST, v)
#endif

/* --- Register HW_USBNC_USB_UH2_HSIC_CTRL, field CLK_VLD */

#define BP_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      31
#define BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD)
#else
#define BF_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_CTRL_CLK_VLD(v)   BF_CS1(USBNC_USB_UH2_HSIC_CTRL, CLK_VLD, v)
#endif

/*
 * HW_USBNC_USB_UH3_HSIC_CTRL - USB Host3 HSIC Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11;
        unsigned HSIC_CLK_ON : 1;
        unsigned HSIC_EN : 1;
        unsigned RESERVED1 : 18;
        unsigned IDLE_DETECT_OPTION : 1;
        unsigned LOOPBACK_DISABLE : 1;
        unsigned KEEPEN_FORCE : 1;
        unsigned KEEPEN_ASYNC_RST : 1;
        unsigned RESERVED2 : 14;
        unsigned CLK_VLD : 1;

    } B;
} hw_usbnc_usb_uh3_hsic_ctrl_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_HSIC_CTRL register
 */
#define HW_USBNC_USB_UH3_HSIC_CTRL_ADDR      (REGS_USBNC_BASE + 0x814)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_HSIC_CTRL           (*(volatile hw_usbnc_usb_uh3_hsic_ctrl_t *) HW_USBNC_USB_UH3_HSIC_CTRL_ADDR)
#define HW_USBNC_USB_UH3_HSIC_CTRL_RD()      (HW_USBNC_USB_UH3_HSIC_CTRL.U)
#define HW_USBNC_USB_UH3_HSIC_CTRL_WR(v)     (HW_USBNC_USB_UH3_HSIC_CTRL.U = (v))
#define HW_USBNC_USB_UH3_HSIC_CTRL_SET(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() |  (v)))
#define HW_USBNC_USB_UH3_HSIC_CTRL_CLR(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() & ~(v)))
#define HW_USBNC_USB_UH3_HSIC_CTRL_TOG(v)    (HW_USBNC_USB_UH3_HSIC_CTRL_WR(HW_USBNC_USB_UH3_HSIC_CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH3_HSIC_CTRL bitfields
 */

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_CLK_ON */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      11
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   ((((reg32_t) v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   (((v) << 11) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_CLK_ON(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_CLK_ON, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field HSIC_EN */

#define BP_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      12
#define BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   ((((reg32_t) v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   (((v) << 12) & BM_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_HSIC_EN(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, HSIC_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field IDLE_DETECT_OPTION */

#define BP_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION      13
#define BM_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION(v)   ((((reg32_t) v) << 13) & BM_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION(v)   (((v) << 13) & BM_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_IDLE_DETECT_OPTION(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, IDLE_DETECT_OPTION, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field LOOPBACK_DISABLE */

#define BP_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE      14
#define BM_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE(v)   ((((reg32_t) v) << 14) & BM_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE(v)   (((v) << 14) & BM_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_LOOPBACK_DISABLE(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, LOOPBACK_DISABLE, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field KEEPEN_FORCE */

#define BP_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE      15
#define BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE(v)   ((((reg32_t) v) << 15) & BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE(v)   (((v) << 15) & BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_FORCE(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, KEEPEN_FORCE, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field KEEPEN_ASYNC_RST */

#define BP_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST      16
#define BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   ((((reg32_t) v) << 16) & BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   (((v) << 16) & BM_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_KEEPEN_ASYNC_RST(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, KEEPEN_ASYNC_RST, v)
#endif

/* --- Register HW_USBNC_USB_UH3_HSIC_CTRL, field CLK_VLD */

#define BP_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      31
#define BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD)
#else
#define BF_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_CTRL_CLK_VLD(v)   BF_CS1(USBNC_USB_UH3_HSIC_CTRL, CLK_VLD, v)
#endif

/*
 * HW_USBNC_USB_OTG_PHY_CTRL_0 - OTG UTMI PHY Control 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHRGDET_INT_FLG : 1;
        unsigned RESERVED0 : 3;
        unsigned CHRGDET_INT_EN : 1;
        unsigned CHRGDET : 1;
        unsigned RESERVED1 : 28;
        unsigned UTMI_CLK_VLD : 1;

    } B;
} hw_usbnc_usb_otg_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_OTG_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_OTG_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x818)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_OTG_PHY_CTRL_0           (*(volatile hw_usbnc_usb_otg_phy_ctrl_0_t *) HW_USBNC_USB_OTG_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_OTG_PHY_CTRL_0_RD()      (HW_USBNC_USB_OTG_PHY_CTRL_0.U)
#define HW_USBNC_USB_OTG_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_OTG_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_OTG_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_OTG_PHY_CTRL_0_WR(HW_USBNC_USB_OTG_PHY_CTRL_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_OTG_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field CHRGDET_INT_FLG */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG      0
#define BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG)
#else
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG(v)   (((v) << 0) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_FLG(v)   BF_CS1(USBNC_USB_OTG_PHY_CTRL_0, CHRGDET_INT_FLG, v)
#endif

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field CHRGDET_INT_EN */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN      1
#define BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN(v)   ((((reg32_t) v) << 1) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN)
#else
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN(v)   (((v) << 1) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET_INT_EN(v)   BF_CS1(USBNC_USB_OTG_PHY_CTRL_0, CHRGDET_INT_EN, v)
#endif

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field CHRGDET */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET      2
#define BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET(v)   ((((reg32_t) v) << 2) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET)
#else
#define BF_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET(v)   (((v) << 2) & BM_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_PHY_CTRL_0_CHRGDET(v)   BF_CS1(USBNC_USB_OTG_PHY_CTRL_0, CHRGDET, v)
#endif

/* --- Register HW_USBNC_USB_OTG_PHY_CTRL_0, field UTMI_CLK_VLD */

#define BP_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      31
#define BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD)
#else
#define BF_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_OTG_PHY_CTRL_0_UTMI_CLK_VLD(v)   BF_CS1(USBNC_USB_OTG_PHY_CTRL_0, UTMI_CLK_VLD, v)
#endif

/*
 * HW_USBNC_USB_UH1_PHY_CTRL_0 - Host1 UTMI PHY Control 0 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHRGDET_INT_FLG : 1;
        unsigned RESERVED0 : 3;
        unsigned CHRGDET_INT_EN : 1;
        unsigned CHRGDET : 1;
        unsigned RESERVED1 : 28;
        unsigned UTMI_CLK_VLD : 1;

    } B;
} hw_usbnc_usb_uh1_phy_ctrl_0_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH1_PHY_CTRL_0 register
 */
#define HW_USBNC_USB_UH1_PHY_CTRL_0_ADDR      (REGS_USBNC_BASE + 0x81c)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH1_PHY_CTRL_0           (*(volatile hw_usbnc_usb_uh1_phy_ctrl_0_t *) HW_USBNC_USB_UH1_PHY_CTRL_0_ADDR)
#define HW_USBNC_USB_UH1_PHY_CTRL_0_RD()      (HW_USBNC_USB_UH1_PHY_CTRL_0.U)
#define HW_USBNC_USB_UH1_PHY_CTRL_0_WR(v)     (HW_USBNC_USB_UH1_PHY_CTRL_0.U = (v))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_SET(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() |  (v)))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_CLR(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() & ~(v)))
#define HW_USBNC_USB_UH1_PHY_CTRL_0_TOG(v)    (HW_USBNC_USB_UH1_PHY_CTRL_0_WR(HW_USBNC_USB_UH1_PHY_CTRL_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH1_PHY_CTRL_0 bitfields
 */

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field CHRGDET_INT_FLG */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG      0
#define BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG)
#else
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG(v)   (((v) << 0) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_FLG(v)   BF_CS1(USBNC_USB_UH1_PHY_CTRL_0, CHRGDET_INT_FLG, v)
#endif

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field CHRGDET_INT_EN */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN      1
#define BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN(v)   ((((reg32_t) v) << 1) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN)
#else
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN(v)   (((v) << 1) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET_INT_EN(v)   BF_CS1(USBNC_USB_UH1_PHY_CTRL_0, CHRGDET_INT_EN, v)
#endif

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field CHRGDET */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET      2
#define BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET(v)   ((((reg32_t) v) << 2) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET)
#else
#define BF_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET(v)   (((v) << 2) & BM_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_PHY_CTRL_0_CHRGDET(v)   BF_CS1(USBNC_USB_UH1_PHY_CTRL_0, CHRGDET, v)
#endif

/* --- Register HW_USBNC_USB_UH1_PHY_CTRL_0, field UTMI_CLK_VLD */

#define BP_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      31
#define BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   ((((reg32_t) v) << 31) & BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD)
#else
#define BF_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   (((v) << 31) & BM_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH1_PHY_CTRL_0_UTMI_CLK_VLD(v)   BF_CS1(USBNC_USB_UH1_PHY_CTRL_0, UTMI_CLK_VLD, v)
#endif

/*
 * HW_USBNC_USB_UH2_HSIC_DLL_CFG1 - USB Host2 HSIC DLL Configuration Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh2_hsic_dll_cfg1_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_HSIC_DLL_CFG1 register
 */
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_ADDR      (REGS_USBNC_BASE + 0x820)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1           (*(volatile hw_usbnc_usb_uh2_hsic_dll_cfg1_t *) HW_USBNC_USB_UH2_HSIC_DLL_CFG1_ADDR)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_RD()      (HW_USBNC_USB_UH2_HSIC_DLL_CFG1.U)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_WR(v)     (HW_USBNC_USB_UH2_HSIC_DLL_CFG1.U = (v))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_SET(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG1_RD() |  (v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_CLR(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG1_RD() & ~(v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG1_TOG(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH2_HSIC_DLL_CFG1 bitfields
 */

/* --- Register HW_USBNC_USB_UH2_HSIC_DLL_CFG1, field DLY_SEL */

#define BP_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL      0
#define BM_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL)
#else
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_DLL_CFG1_DLY_SEL(v)   BF_CS1(USBNC_USB_UH2_HSIC_DLL_CFG1, DLY_SEL, v)
#endif

/*
 * HW_USBNC_USB_UH2_HSIC_DLL_CFG2 - USB Host2 HSIC DLL Configuration Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh2_hsic_dll_cfg2_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_HSIC_DLL_CFG2 register
 */
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_ADDR      (REGS_USBNC_BASE + 0x824)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2           (*(volatile hw_usbnc_usb_uh2_hsic_dll_cfg2_t *) HW_USBNC_USB_UH2_HSIC_DLL_CFG2_ADDR)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_RD()      (HW_USBNC_USB_UH2_HSIC_DLL_CFG2.U)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_WR(v)     (HW_USBNC_USB_UH2_HSIC_DLL_CFG2.U = (v))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_SET(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG2_RD() |  (v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_CLR(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG2_RD() & ~(v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG2_TOG(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH2_HSIC_DLL_CFG2 bitfields
 */

/* --- Register HW_USBNC_USB_UH2_HSIC_DLL_CFG2, field DLY_SEL */

#define BP_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL      0
#define BM_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL)
#else
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_DLL_CFG2_DLY_SEL(v)   BF_CS1(USBNC_USB_UH2_HSIC_DLL_CFG2, DLY_SEL, v)
#endif

/*
 * HW_USBNC_USB_UH2_HSIC_DLL_CFG3 - USB Host2 HSIC DLL Configuration Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh2_hsic_dll_cfg3_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH2_HSIC_DLL_CFG3 register
 */
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_ADDR      (REGS_USBNC_BASE + 0x828)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3           (*(volatile hw_usbnc_usb_uh2_hsic_dll_cfg3_t *) HW_USBNC_USB_UH2_HSIC_DLL_CFG3_ADDR)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_RD()      (HW_USBNC_USB_UH2_HSIC_DLL_CFG3.U)
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_WR(v)     (HW_USBNC_USB_UH2_HSIC_DLL_CFG3.U = (v))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_SET(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG3_RD() |  (v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_CLR(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG3_RD() & ~(v)))
#define HW_USBNC_USB_UH2_HSIC_DLL_CFG3_TOG(v)    (HW_USBNC_USB_UH2_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH2_HSIC_DLL_CFG3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH2_HSIC_DLL_CFG3 bitfields
 */

/* --- Register HW_USBNC_USB_UH2_HSIC_DLL_CFG3, field DLY_SEL */

#define BP_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL      0
#define BM_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL)
#else
#define BF_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH2_HSIC_DLL_CFG3_DLY_SEL(v)   BF_CS1(USBNC_USB_UH2_HSIC_DLL_CFG3, DLY_SEL, v)
#endif

/*
 * HW_USBNC_USB_UH3_HSIC_DLL_CFG1 - USB Host3 HSIC DLL Configuration Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh3_hsic_dll_cfg1_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_HSIC_DLL_CFG1 register
 */
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_ADDR      (REGS_USBNC_BASE + 0x830)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1           (*(volatile hw_usbnc_usb_uh3_hsic_dll_cfg1_t *) HW_USBNC_USB_UH3_HSIC_DLL_CFG1_ADDR)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_RD()      (HW_USBNC_USB_UH3_HSIC_DLL_CFG1.U)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_WR(v)     (HW_USBNC_USB_UH3_HSIC_DLL_CFG1.U = (v))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_SET(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG1_RD() |  (v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_CLR(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG1_RD() & ~(v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG1_TOG(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG1_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH3_HSIC_DLL_CFG1 bitfields
 */

/* --- Register HW_USBNC_USB_UH3_HSIC_DLL_CFG1, field DLY_SEL */

#define BP_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL      0
#define BM_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL)
#else
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_DLL_CFG1_DLY_SEL(v)   BF_CS1(USBNC_USB_UH3_HSIC_DLL_CFG1, DLY_SEL, v)
#endif

/*
 * HW_USBNC_USB_UH3_HSIC_DLL_CFG2 - USB Host3 HSIC DLL Configuration Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh3_hsic_dll_cfg2_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_HSIC_DLL_CFG2 register
 */
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_ADDR      (REGS_USBNC_BASE + 0x834)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2           (*(volatile hw_usbnc_usb_uh3_hsic_dll_cfg2_t *) HW_USBNC_USB_UH3_HSIC_DLL_CFG2_ADDR)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_RD()      (HW_USBNC_USB_UH3_HSIC_DLL_CFG2.U)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_WR(v)     (HW_USBNC_USB_UH3_HSIC_DLL_CFG2.U = (v))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_SET(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG2_RD() |  (v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_CLR(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG2_RD() & ~(v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG2_TOG(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG2_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH3_HSIC_DLL_CFG2 bitfields
 */

/* --- Register HW_USBNC_USB_UH3_HSIC_DLL_CFG2, field DLY_SEL */

#define BP_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL      0
#define BM_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL)
#else
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_DLL_CFG2_DLY_SEL(v)   BF_CS1(USBNC_USB_UH3_HSIC_DLL_CFG2, DLY_SEL, v)
#endif

/*
 * HW_USBNC_USB_UH3_HSIC_DLL_CFG3 - USB Host3 HSIC DLL Configuration Register 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_SEL : 32;

    } B;
} hw_usbnc_usb_uh3_hsic_dll_cfg3_t;
#endif

/*
 * constants & macros for entire USBNC_USB_UH3_HSIC_DLL_CFG3 register
 */
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_ADDR      (REGS_USBNC_BASE + 0x838)

#ifndef __LANGUAGE_ASM__
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3           (*(volatile hw_usbnc_usb_uh3_hsic_dll_cfg3_t *) HW_USBNC_USB_UH3_HSIC_DLL_CFG3_ADDR)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_RD()      (HW_USBNC_USB_UH3_HSIC_DLL_CFG3.U)
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_WR(v)     (HW_USBNC_USB_UH3_HSIC_DLL_CFG3.U = (v))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_SET(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG3_RD() |  (v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_CLR(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG3_RD() & ~(v)))
#define HW_USBNC_USB_UH3_HSIC_DLL_CFG3_TOG(v)    (HW_USBNC_USB_UH3_HSIC_DLL_CFG3_WR(HW_USBNC_USB_UH3_HSIC_DLL_CFG3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBNC_USB_UH3_HSIC_DLL_CFG3 bitfields
 */

/* --- Register HW_USBNC_USB_UH3_HSIC_DLL_CFG3, field DLY_SEL */

#define BP_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL      0
#define BM_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL(v)   ((((reg32_t) v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL)
#else
#define BF_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL(v)   (((v) << 0) & BM_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBNC_USB_UH3_HSIC_DLL_CFG3_DLY_SEL(v)   BF_CS1(USBNC_USB_UH3_HSIC_DLL_CFG3, DLY_SEL, v)
#endif


#endif // _USBNC_H

