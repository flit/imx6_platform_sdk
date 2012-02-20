/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USB_PHY_H
#define _USB_PHY_H

#include "regs.h"

#ifndef REGS_USB_PHY_BASE
#define REGS_USB_PHY0_BASE (REGS_BASE + 0x020c9000)
#define REGS_USB_PHY1_BASE (REGS_BASE + 0x020ca000)
#define REGS_USB_PHY_BASE(x) ( x == 0 ? REGS_USB_PHY0_BASE : x == 1 ? REGS_USB_PHY1_BASE : 0xffff0000)

#endif


/*
 * HW_USB_PHY_PWD - USB PHY Power-Down Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD2 : 11;
        unsigned RXPWDRX : 1;
        unsigned RXPWDDIFF : 1;
        unsigned RXPWD1PT1 : 1;
        unsigned RXPWDENV : 1;
        unsigned RSVD1 : 4;
        unsigned TXPWDV2I : 1;
        unsigned TXPWDIBIAS : 1;
        unsigned TXPWDFS : 1;
        unsigned RSVD0 : 10;

    } B;
} hw_usb_phy_pwd_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD register
 */
#define HW_USB_PHY_PWD_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD(x)           (*(volatile hw_usb_phy_pwd_t *) HW_USB_PHY_PWD_ADDR(x))
#define HW_USB_PHY_PWD_RD(x)        (HW_USB_PHY_PWD(x).U)
#define HW_USB_PHY_PWD_WR(x, v)     (HW_USB_PHY_PWD(x).U = (v))
#define HW_USB_PHY_PWD_SET(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) |  (v)))
#define HW_USB_PHY_PWD_CLR(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) & ~(v)))
#define HW_USB_PHY_PWD_TOG(x, v)    (HW_USB_PHY_PWD_WR(x, HW_USB_PHY_PWD_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_PWD bitfields
 */

/* --- Register HW_USB_PHY_PWD, field RSVD2 */

#define BP_USB_PHY_PWD_RSVD2      21
#define BM_USB_PHY_PWD_RSVD2      0xffe00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD2(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_PWD_RSVD2)
#else
#define BF_USB_PHY_PWD_RSVD2(v)   (((v) << 21) & BM_USB_PHY_PWD_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD2(v)   BF_CS1(USB_PHY_PWD, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDRX */

#define BP_USB_PHY_PWD_RXPWDRX      20
#define BM_USB_PHY_PWD_RXPWDRX      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDRX(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#else
#define BF_USB_PHY_PWD_RXPWDRX(v)   (((v) << 20) & BM_USB_PHY_PWD_RXPWDRX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWDRX(v)   BF_CS1(USB_PHY_PWD, RXPWDRX, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDDIFF */

#define BP_USB_PHY_PWD_RXPWDDIFF      19
#define BM_USB_PHY_PWD_RXPWDDIFF      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#else
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   (((v) << 19) & BM_USB_PHY_PWD_RXPWDDIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWDDIFF(v)   BF_CS1(USB_PHY_PWD, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWD1PT1 */

#define BP_USB_PHY_PWD_RXPWD1PT1      18
#define BM_USB_PHY_PWD_RXPWD1PT1      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#else
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   (((v) << 18) & BM_USB_PHY_PWD_RXPWD1PT1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWD1PT1(v)   BF_CS1(USB_PHY_PWD, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDENV */

#define BP_USB_PHY_PWD_RXPWDENV      17
#define BM_USB_PHY_PWD_RXPWDENV      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RXPWDENV(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_PWD_RXPWDENV)
#else
#define BF_USB_PHY_PWD_RXPWDENV(v)   (((v) << 17) & BM_USB_PHY_PWD_RXPWDENV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RXPWDENV(v)   BF_CS1(USB_PHY_PWD, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RSVD1 */

#define BP_USB_PHY_PWD_RSVD1      13
#define BM_USB_PHY_PWD_RSVD1      0x0001e000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD1(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_PWD_RSVD1)
#else
#define BF_USB_PHY_PWD_RSVD1(v)   (((v) << 13) & BM_USB_PHY_PWD_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD1(v)   BF_CS1(USB_PHY_PWD, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDV2I */

#define BP_USB_PHY_PWD_TXPWDV2I      12
#define BM_USB_PHY_PWD_TXPWDV2I      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDV2I(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_PWD_TXPWDV2I)
#else
#define BF_USB_PHY_PWD_TXPWDV2I(v)   (((v) << 12) & BM_USB_PHY_PWD_TXPWDV2I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_TXPWDV2I(v)   BF_CS1(USB_PHY_PWD, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDIBIAS */

#define BP_USB_PHY_PWD_TXPWDIBIAS      11
#define BM_USB_PHY_PWD_TXPWDIBIAS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_PWD_TXPWDIBIAS)
#else
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   (((v) << 11) & BM_USB_PHY_PWD_TXPWDIBIAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_TXPWDIBIAS(v)   BF_CS1(USB_PHY_PWD, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDFS */

#define BP_USB_PHY_PWD_TXPWDFS      10
#define BM_USB_PHY_PWD_TXPWDFS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_TXPWDFS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_PWD_TXPWDFS)
#else
#define BF_USB_PHY_PWD_TXPWDFS(v)   (((v) << 10) & BM_USB_PHY_PWD_TXPWDFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_TXPWDFS(v)   BF_CS1(USB_PHY_PWD, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RSVD0 */

#define BP_USB_PHY_PWD_RSVD0      0
#define BM_USB_PHY_PWD_RSVD0      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_PWD_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_PWD_RSVD0)
#else
#define BF_USB_PHY_PWD_RSVD0(v)   (((v) << 0) & BM_USB_PHY_PWD_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_PWD_RSVD0(v)   BF_CS1(USB_PHY_PWD, RSVD0, v)
#endif

/*
 * HW_USB_PHY_TX - USB PHY Transmitter Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD5 : 3;
        unsigned RSVD2 : 12;
        unsigned USBPHY_TX_EDGECTRL : 3;
        unsigned USBPHY_TX_SYNC_INVERT : 1;
        unsigned USBPHY_TX_SYNC_MUX : 1;
        unsigned RSVD4 : 2;
        unsigned TXENCAL45DP : 1;
        unsigned RSVD3 : 1;
        unsigned TXCAL45DP : 4;
        unsigned RSVD1 : 4;
        unsigned RSVD2 : 2;
        unsigned TXENCAL45DN : 1;
        unsigned RSVD1 : 1;
        unsigned TXCAL45DN : 4;
        unsigned RSVD0 : 4;
        unsigned D_CAL : 4;

    } B;
} hw_usb_phy_tx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX register
 */
#define HW_USB_PHY_TX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX(x)           (*(volatile hw_usb_phy_tx_t *) HW_USB_PHY_TX_ADDR(x))
#define HW_USB_PHY_TX_RD(x)        (HW_USB_PHY_TX(x).U)
#define HW_USB_PHY_TX_WR(x, v)     (HW_USB_PHY_TX(x).U = (v))
#define HW_USB_PHY_TX_SET(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) |  (v)))
#define HW_USB_PHY_TX_CLR(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) & ~(v)))
#define HW_USB_PHY_TX_TOG(x, v)    (HW_USB_PHY_TX_WR(x, HW_USB_PHY_TX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_TX bitfields
 */

/* --- Register HW_USB_PHY_TX, field RSVD5 */

#define BP_USB_PHY_TX_RSVD5      29
#define BM_USB_PHY_TX_RSVD5      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD5(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_TX_RSVD5)
#else
#define BF_USB_PHY_TX_RSVD5(v)   (((v) << 29) & BM_USB_PHY_TX_RSVD5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD5(v)   BF_CS1(USB_PHY_TX, RSVD5, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD2 */

#define BP_USB_PHY_TX_RSVD2      20
#define BM_USB_PHY_TX_RSVD2      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD2(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_TX_RSVD2)
#else
#define BF_USB_PHY_TX_RSVD2(v)   (((v) << 20) & BM_USB_PHY_TX_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD2(v)   BF_CS1(USB_PHY_TX, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_TX, field USBPHY_TX_EDGECTRL */

#define BP_USB_PHY_TX_USBPHY_TX_EDGECTRL      26
#define BM_USB_PHY_TX_USBPHY_TX_EDGECTRL      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_USBPHY_TX_EDGECTRL(v)   ((((reg32_t) v) << 26) & BM_USB_PHY_TX_USBPHY_TX_EDGECTRL)
#else
#define BF_USB_PHY_TX_USBPHY_TX_EDGECTRL(v)   (((v) << 26) & BM_USB_PHY_TX_USBPHY_TX_EDGECTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_USBPHY_TX_EDGECTRL(v)   BF_CS1(USB_PHY_TX, USBPHY_TX_EDGECTRL, v)
#endif

/* --- Register HW_USB_PHY_TX, field USBPHY_TX_SYNC_INVERT */

#define BP_USB_PHY_TX_USBPHY_TX_SYNC_INVERT      25
#define BM_USB_PHY_TX_USBPHY_TX_SYNC_INVERT      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_USBPHY_TX_SYNC_INVERT(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_TX_USBPHY_TX_SYNC_INVERT)
#else
#define BF_USB_PHY_TX_USBPHY_TX_SYNC_INVERT(v)   (((v) << 25) & BM_USB_PHY_TX_USBPHY_TX_SYNC_INVERT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_USBPHY_TX_SYNC_INVERT(v)   BF_CS1(USB_PHY_TX, USBPHY_TX_SYNC_INVERT, v)
#endif

/* --- Register HW_USB_PHY_TX, field USBPHY_TX_SYNC_MUX */

#define BP_USB_PHY_TX_USBPHY_TX_SYNC_MUX      24
#define BM_USB_PHY_TX_USBPHY_TX_SYNC_MUX      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_USBPHY_TX_SYNC_MUX(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_TX_USBPHY_TX_SYNC_MUX)
#else
#define BF_USB_PHY_TX_USBPHY_TX_SYNC_MUX(v)   (((v) << 24) & BM_USB_PHY_TX_USBPHY_TX_SYNC_MUX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_USBPHY_TX_SYNC_MUX(v)   BF_CS1(USB_PHY_TX, USBPHY_TX_SYNC_MUX, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD4 */

#define BP_USB_PHY_TX_RSVD4      22
#define BM_USB_PHY_TX_RSVD4      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD4(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_TX_RSVD4)
#else
#define BF_USB_PHY_TX_RSVD4(v)   (((v) << 22) & BM_USB_PHY_TX_RSVD4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD4(v)   BF_CS1(USB_PHY_TX, RSVD4, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXENCAL45DP */

#define BP_USB_PHY_TX_TXENCAL45DP      21
#define BM_USB_PHY_TX_TXENCAL45DP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXENCAL45DP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_TX_TXENCAL45DP)
#else
#define BF_USB_PHY_TX_TXENCAL45DP(v)   (((v) << 21) & BM_USB_PHY_TX_TXENCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_TXENCAL45DP(v)   BF_CS1(USB_PHY_TX, TXENCAL45DP, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD3 */

#define BP_USB_PHY_TX_RSVD3      20
#define BM_USB_PHY_TX_RSVD3      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD3(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_TX_RSVD3)
#else
#define BF_USB_PHY_TX_RSVD3(v)   (((v) << 20) & BM_USB_PHY_TX_RSVD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD3(v)   BF_CS1(USB_PHY_TX, RSVD3, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DP */

#define BP_USB_PHY_TX_TXCAL45DP      16
#define BM_USB_PHY_TX_TXCAL45DP      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXCAL45DP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_TX_TXCAL45DP)
#else
#define BF_USB_PHY_TX_TXCAL45DP(v)   (((v) << 16) & BM_USB_PHY_TX_TXCAL45DP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_TXCAL45DP(v)   BF_CS1(USB_PHY_TX, TXCAL45DP, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD1 */

#define BP_USB_PHY_TX_RSVD1      12
#define BM_USB_PHY_TX_RSVD1      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD1(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_TX_RSVD1)
#else
#define BF_USB_PHY_TX_RSVD1(v)   (((v) << 12) & BM_USB_PHY_TX_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD1(v)   BF_CS1(USB_PHY_TX, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD2 */

#define BP_USB_PHY_TX_RSVD2      14
#define BM_USB_PHY_TX_RSVD2      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_TX_RSVD2)
#else
#define BF_USB_PHY_TX_RSVD2(v)   (((v) << 14) & BM_USB_PHY_TX_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD2(v)   BF_CS1(USB_PHY_TX, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXENCAL45DN */

#define BP_USB_PHY_TX_TXENCAL45DN      13
#define BM_USB_PHY_TX_TXENCAL45DN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXENCAL45DN(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_TX_TXENCAL45DN)
#else
#define BF_USB_PHY_TX_TXENCAL45DN(v)   (((v) << 13) & BM_USB_PHY_TX_TXENCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_TXENCAL45DN(v)   BF_CS1(USB_PHY_TX, TXENCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD1 */

#define BP_USB_PHY_TX_RSVD1      12
#define BM_USB_PHY_TX_RSVD1      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD1(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_TX_RSVD1)
#else
#define BF_USB_PHY_TX_RSVD1(v)   (((v) << 12) & BM_USB_PHY_TX_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD1(v)   BF_CS1(USB_PHY_TX, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DN */

#define BP_USB_PHY_TX_TXCAL45DN      8
#define BM_USB_PHY_TX_TXCAL45DN      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_TXCAL45DN(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_TX_TXCAL45DN)
#else
#define BF_USB_PHY_TX_TXCAL45DN(v)   (((v) << 8) & BM_USB_PHY_TX_TXCAL45DN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_TXCAL45DN(v)   BF_CS1(USB_PHY_TX, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX, field RSVD0 */

#define BP_USB_PHY_TX_RSVD0      4
#define BM_USB_PHY_TX_RSVD0      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_RSVD0(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_TX_RSVD0)
#else
#define BF_USB_PHY_TX_RSVD0(v)   (((v) << 4) & BM_USB_PHY_TX_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_RSVD0(v)   BF_CS1(USB_PHY_TX, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_TX, field D_CAL */

#define BP_USB_PHY_TX_D_CAL      0
#define BM_USB_PHY_TX_D_CAL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_TX_D_CAL(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_TX_D_CAL)
#else
#define BF_USB_PHY_TX_D_CAL(v)   (((v) << 0) & BM_USB_PHY_TX_D_CAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_TX_D_CAL(v)   BF_CS1(USB_PHY_TX, D_CAL, v)
#endif

/*
 * HW_USB_PHY_RX - USB PHY Receiver Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD2 : 9;
        unsigned RXDBYPASS : 1;
        unsigned RSVD1 : 15;
        unsigned DISCONADJ : 3;
        unsigned RSVD0 : 1;
        unsigned ENVADJ : 3;

    } B;
} hw_usb_phy_rx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX register
 */
#define HW_USB_PHY_RX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX(x)           (*(volatile hw_usb_phy_rx_t *) HW_USB_PHY_RX_ADDR(x))
#define HW_USB_PHY_RX_RD(x)        (HW_USB_PHY_RX(x).U)
#define HW_USB_PHY_RX_WR(x, v)     (HW_USB_PHY_RX(x).U = (v))
#define HW_USB_PHY_RX_SET(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) |  (v)))
#define HW_USB_PHY_RX_CLR(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) & ~(v)))
#define HW_USB_PHY_RX_TOG(x, v)    (HW_USB_PHY_RX_WR(x, HW_USB_PHY_RX_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_RX bitfields
 */

/* --- Register HW_USB_PHY_RX, field RSVD2 */

#define BP_USB_PHY_RX_RSVD2      23
#define BM_USB_PHY_RX_RSVD2      0xff800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD2(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_RX_RSVD2)
#else
#define BF_USB_PHY_RX_RSVD2(v)   (((v) << 23) & BM_USB_PHY_RX_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD2(v)   BF_CS1(USB_PHY_RX, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_RX, field RXDBYPASS */

#define BP_USB_PHY_RX_RXDBYPASS      22
#define BM_USB_PHY_RX_RXDBYPASS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RXDBYPASS(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#else
#define BF_USB_PHY_RX_RXDBYPASS(v)   (((v) << 22) & BM_USB_PHY_RX_RXDBYPASS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RXDBYPASS(v)   BF_CS1(USB_PHY_RX, RXDBYPASS, v)
#endif

/* --- Register HW_USB_PHY_RX, field RSVD1 */

#define BP_USB_PHY_RX_RSVD1      7
#define BM_USB_PHY_RX_RSVD1      0x003fff80

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD1(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_RX_RSVD1)
#else
#define BF_USB_PHY_RX_RSVD1(v)   (((v) << 7) & BM_USB_PHY_RX_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD1(v)   BF_CS1(USB_PHY_RX, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_RX, field DISCONADJ */

#define BP_USB_PHY_RX_DISCONADJ      4
#define BM_USB_PHY_RX_DISCONADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_DISCONADJ(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#else
#define BF_USB_PHY_RX_DISCONADJ(v)   (((v) << 4) & BM_USB_PHY_RX_DISCONADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_DISCONADJ(v)   BF_CS1(USB_PHY_RX, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field RSVD0 */

#define BP_USB_PHY_RX_RSVD0      3
#define BM_USB_PHY_RX_RSVD0      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_RSVD0(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_RX_RSVD0)
#else
#define BF_USB_PHY_RX_RSVD0(v)   (((v) << 3) & BM_USB_PHY_RX_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_RSVD0(v)   BF_CS1(USB_PHY_RX, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_RX, field ENVADJ */

#define BP_USB_PHY_RX_ENVADJ      0
#define BM_USB_PHY_RX_ENVADJ      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_RX_ENVADJ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_RX_ENVADJ)
#else
#define BF_USB_PHY_RX_ENVADJ(v)   (((v) << 0) & BM_USB_PHY_RX_ENVADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_RX_ENVADJ(v)   BF_CS1(USB_PHY_RX, ENVADJ, v)
#endif

/*
 * HW_USB_PHY_CTRL - USB PHY General Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SFTRST : 1;
        unsigned CLKGATE : 1;
        unsigned UTMI_SUSPENDM : 1;
        unsigned HOST_FORCE_LS_SE0 : 1;
        unsigned OTG_ID_VALUE : 1;
        unsigned RSVD1 : 2;
        unsigned FSDLL_RST_EN : 1;
        unsigned ENVBUSCHG_WKUP : 1;
        unsigned ENIDCHG_WKUP : 1;
        unsigned ENDPDMCHG_WKUP : 1;
        unsigned ENAUTOCLR_PHY_PWD : 1;
        unsigned ENAUTOCLR_CLKGATE : 1;
        unsigned RSVD0 : 1;
        unsigned WAKEUP_IRQ : 1;
        unsigned ENIRQWAKEUP : 1;
        unsigned ENUTMILEVEL3 : 1;
        unsigned ENUTMILEVEL2 : 1;
        unsigned DATA_ON_LRADC : 1;
        unsigned DEVPLUGIN_IRQ : 1;
        unsigned ENIRQDEVPLUGIN : 1;
        unsigned RESUME_IRQ : 1;
        unsigned ENIRQRESUMEDETECT : 1;
        unsigned RESUMEIRQSTICKY : 1;
        unsigned ENOTGIDDETECT : 1;
        unsigned OTG_ID_CHG_IRQ : 1;
        unsigned DEVPLUGIN_POLARITY : 1;
        unsigned ENDEVPLUGINDETECT : 1;
        unsigned HOSTDISCONDETECT_IRQ : 1;
        unsigned ENIRQHOSTDISCON : 1;
        unsigned ENHOSTDISCONDETECT : 1;
        unsigned ENOTG_ID_CHG_IRQ : 1;

    } B;
} hw_usb_phy_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL register
 */
#define HW_USB_PHY_CTRL_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL(x)           (*(volatile hw_usb_phy_ctrl_t *) HW_USB_PHY_CTRL_ADDR(x))
#define HW_USB_PHY_CTRL_RD(x)        (HW_USB_PHY_CTRL(x).U)
#define HW_USB_PHY_CTRL_WR(x, v)     (HW_USB_PHY_CTRL(x).U = (v))
#define HW_USB_PHY_CTRL_SET(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) |  (v)))
#define HW_USB_PHY_CTRL_CLR(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) & ~(v)))
#define HW_USB_PHY_CTRL_TOG(x, v)    (HW_USB_PHY_CTRL_WR(x, HW_USB_PHY_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_CTRL bitfields
 */

/* --- Register HW_USB_PHY_CTRL, field SFTRST */

#define BP_USB_PHY_CTRL_SFTRST      31
#define BM_USB_PHY_CTRL_SFTRST      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_CTRL_SFTRST)
#else
#define BF_USB_PHY_CTRL_SFTRST(v)   (((v) << 31) & BM_USB_PHY_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_SFTRST(v)   BF_CS1(USB_PHY_CTRL, SFTRST, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field CLKGATE */

#define BP_USB_PHY_CTRL_CLKGATE      30
#define BM_USB_PHY_CTRL_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_CTRL_CLKGATE)
#else
#define BF_USB_PHY_CTRL_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field UTMI_SUSPENDM */

#define BP_USB_PHY_CTRL_UTMI_SUSPENDM      29
#define BM_USB_PHY_CTRL_UTMI_SUSPENDM      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_UTMI_SUSPENDM(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_CTRL_UTMI_SUSPENDM)
#else
#define BF_USB_PHY_CTRL_UTMI_SUSPENDM(v)   (((v) << 29) & BM_USB_PHY_CTRL_UTMI_SUSPENDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_UTMI_SUSPENDM(v)   BF_CS1(USB_PHY_CTRL, UTMI_SUSPENDM, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOST_FORCE_LS_SE0 */

#define BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0      28
#define BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << 28) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#else
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   (((v) << 28) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   BF_CS1(USB_PHY_CTRL, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_VALUE */

#define BP_USB_PHY_CTRL_OTG_ID_VALUE      27
#define BM_USB_PHY_CTRL_OTG_ID_VALUE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_OTG_ID_VALUE(v)   ((((reg32_t) v) << 27) & BM_USB_PHY_CTRL_OTG_ID_VALUE)
#else
#define BF_USB_PHY_CTRL_OTG_ID_VALUE(v)   (((v) << 27) & BM_USB_PHY_CTRL_OTG_ID_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_OTG_ID_VALUE(v)   BF_CS1(USB_PHY_CTRL, OTG_ID_VALUE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RSVD1 */

#define BP_USB_PHY_CTRL_RSVD1      25
#define BM_USB_PHY_CTRL_RSVD1      0x06000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RSVD1(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_CTRL_RSVD1)
#else
#define BF_USB_PHY_CTRL_RSVD1(v)   (((v) << 25) & BM_USB_PHY_CTRL_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RSVD1(v)   BF_CS1(USB_PHY_CTRL, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field FSDLL_RST_EN */

#define BP_USB_PHY_CTRL_FSDLL_RST_EN      24
#define BM_USB_PHY_CTRL_FSDLL_RST_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#else
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   (((v) << 24) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_FSDLL_RST_EN(v)   BF_CS1(USB_PHY_CTRL, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENVBUSCHG_WKUP */

#define BP_USB_PHY_CTRL_ENVBUSCHG_WKUP      23
#define BM_USB_PHY_CTRL_ENVBUSCHG_WKUP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   (((v) << 23) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIDCHG_WKUP */

#define BP_USB_PHY_CTRL_ENIDCHG_WKUP      22
#define BM_USB_PHY_CTRL_ENIDCHG_WKUP      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   ((((reg32_t) v) << 22) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   (((v) << 22) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENIDCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDPDMCHG_WKUP */

#define BP_USB_PHY_CTRL_ENDPDMCHG_WKUP      21
#define BM_USB_PHY_CTRL_ENDPDMCHG_WKUP      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#else
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   (((v) << 21) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   BF_CS1(USB_PHY_CTRL, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_PHY_PWD */

#define BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      20
#define BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << 20) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#else
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   (((v) << 20) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_CLKGATE */

#define BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      19
#define BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#else
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   (((v) << 19) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   BF_CS1(USB_PHY_CTRL, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RSVD0 */

#define BP_USB_PHY_CTRL_RSVD0      18
#define BM_USB_PHY_CTRL_RSVD0      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RSVD0(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_CTRL_RSVD0)
#else
#define BF_USB_PHY_CTRL_RSVD0(v)   (((v) << 18) & BM_USB_PHY_CTRL_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RSVD0(v)   BF_CS1(USB_PHY_CTRL, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field WAKEUP_IRQ */

#define BP_USB_PHY_CTRL_WAKEUP_IRQ      17
#define BM_USB_PHY_CTRL_WAKEUP_IRQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#else
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   (((v) << 17) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_WAKEUP_IRQ(v)   BF_CS1(USB_PHY_CTRL, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQWAKEUP */

#define BP_USB_PHY_CTRL_ENIRQWAKEUP      16
#define BM_USB_PHY_CTRL_ENIRQWAKEUP      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#else
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   (((v) << 16) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENIRQWAKEUP(v)   BF_CS1(USB_PHY_CTRL, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL3 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL3      15
#define BM_USB_PHY_CTRL_ENUTMILEVEL3      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#else
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   (((v) << 15) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENUTMILEVEL3(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL2 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL2      14
#define BM_USB_PHY_CTRL_ENUTMILEVEL2      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   ((((reg32_t) v) << 14) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#else
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   (((v) << 14) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENUTMILEVEL2(v)   BF_CS1(USB_PHY_CTRL, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DATA_ON_LRADC */

#define BP_USB_PHY_CTRL_DATA_ON_LRADC      13
#define BM_USB_PHY_CTRL_DATA_ON_LRADC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#else
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   (((v) << 13) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_DATA_ON_LRADC(v)   BF_CS1(USB_PHY_CTRL, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_IRQ */

#define BP_USB_PHY_CTRL_DEVPLUGIN_IRQ      12
#define BM_USB_PHY_CTRL_DEVPLUGIN_IRQ      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#else
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   (((v) << 12) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQDEVPLUGIN */

#define BP_USB_PHY_CTRL_ENIRQDEVPLUGIN      11
#define BM_USB_PHY_CTRL_ENIRQDEVPLUGIN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#else
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   (((v) << 11) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   BF_CS1(USB_PHY_CTRL, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUME_IRQ */

#define BP_USB_PHY_CTRL_RESUME_IRQ      10
#define BM_USB_PHY_CTRL_RESUME_IRQ      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_CTRL_RESUME_IRQ)
#else
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   (((v) << 10) & BM_USB_PHY_CTRL_RESUME_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RESUME_IRQ(v)   BF_CS1(USB_PHY_CTRL, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQRESUMEDETECT */

#define BP_USB_PHY_CTRL_ENIRQRESUMEDETECT      9
#define BM_USB_PHY_CTRL_ENIRQRESUMEDETECT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#else
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   (((v) << 9) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   BF_CS1(USB_PHY_CTRL, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUMEIRQSTICKY */

#define BP_USB_PHY_CTRL_RESUMEIRQSTICKY      8
#define BM_USB_PHY_CTRL_RESUMEIRQSTICKY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#else
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   (((v) << 8) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   BF_CS1(USB_PHY_CTRL, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENOTGIDDETECT */

#define BP_USB_PHY_CTRL_ENOTGIDDETECT      7
#define BM_USB_PHY_CTRL_ENOTGIDDETECT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#else
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   (((v) << 7) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENOTGIDDETECT(v)   BF_CS1(USB_PHY_CTRL, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_CHG_IRQ */

#define BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ      6
#define BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   (((v) << 6) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_POLARITY */

#define BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY      5
#define BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << 5) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#else
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   (((v) << 5) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   BF_CS1(USB_PHY_CTRL, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDEVPLUGINDETECT */

#define BP_USB_PHY_CTRL_ENDEVPLUGINDETECT      4
#define BM_USB_PHY_CTRL_ENDEVPLUGINDETECT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#else
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   (((v) << 4) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   BF_CS1(USB_PHY_CTRL, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOSTDISCONDETECT_IRQ */

#define BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      3
#define BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#else
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   (((v) << 3) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   BF_CS1(USB_PHY_CTRL, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQHOSTDISCON */

#define BP_USB_PHY_CTRL_ENIRQHOSTDISCON      2
#define BM_USB_PHY_CTRL_ENIRQHOSTDISCON      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#else
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   (((v) << 2) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   BF_CS1(USB_PHY_CTRL, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENHOSTDISCONDETECT */

#define BP_USB_PHY_CTRL_ENHOSTDISCONDETECT      1
#define BM_USB_PHY_CTRL_ENHOSTDISCONDETECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#else
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   (((v) << 1) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   BF_CS1(USB_PHY_CTRL, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENOTG_ID_CHG_IRQ */

#define BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      0
#define BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#else
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   (((v) << 0) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   BF_CS1(USB_PHY_CTRL, ENOTG_ID_CHG_IRQ, v)
#endif

/*
 * HW_USB_PHY_STATUS - USB PHY Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD4 : 21;
        unsigned RESUME_STATUS : 1;
        unsigned RSVD3 : 1;
        unsigned OTGID_STATUS : 1;
        unsigned RSVD2 : 1;
        unsigned DEVPLUGIN_STATUS : 1;
        unsigned RSVD1 : 2;
        unsigned HOSTDISCONDETECT_STATUS : 1;
        unsigned RSVD0 : 3;

    } B;
} hw_usb_phy_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_STATUS register
 */
#define HW_USB_PHY_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_STATUS(x)           (*(volatile hw_usb_phy_status_t *) HW_USB_PHY_STATUS_ADDR(x))
#define HW_USB_PHY_STATUS_RD(x)        (HW_USB_PHY_STATUS(x).U)
#define HW_USB_PHY_STATUS_WR(x, v)     (HW_USB_PHY_STATUS(x).U = (v))
#define HW_USB_PHY_STATUS_SET(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) |  (v)))
#define HW_USB_PHY_STATUS_CLR(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) & ~(v)))
#define HW_USB_PHY_STATUS_TOG(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_STATUS bitfields
 */

/* --- Register HW_USB_PHY_STATUS, field RSVD4 */

#define BP_USB_PHY_STATUS_RSVD4      11
#define BM_USB_PHY_STATUS_RSVD4      0xfffff800

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD4(v)   ((((reg32_t) v) << 11) & BM_USB_PHY_STATUS_RSVD4)
#else
#define BF_USB_PHY_STATUS_RSVD4(v)   (((v) << 11) & BM_USB_PHY_STATUS_RSVD4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD4(v)   BF_CS1(USB_PHY_STATUS, RSVD4, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RESUME_STATUS */

#define BP_USB_PHY_STATUS_RESUME_STATUS      10
#define BM_USB_PHY_STATUS_RESUME_STATUS      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RESUME_STATUS(v)   ((((reg32_t) v) << 10) & BM_USB_PHY_STATUS_RESUME_STATUS)
#else
#define BF_USB_PHY_STATUS_RESUME_STATUS(v)   (((v) << 10) & BM_USB_PHY_STATUS_RESUME_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RESUME_STATUS(v)   BF_CS1(USB_PHY_STATUS, RESUME_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD3 */

#define BP_USB_PHY_STATUS_RSVD3      9
#define BM_USB_PHY_STATUS_RSVD3      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD3(v)   ((((reg32_t) v) << 9) & BM_USB_PHY_STATUS_RSVD3)
#else
#define BF_USB_PHY_STATUS_RSVD3(v)   (((v) << 9) & BM_USB_PHY_STATUS_RSVD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD3(v)   BF_CS1(USB_PHY_STATUS, RSVD3, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field OTGID_STATUS */

#define BP_USB_PHY_STATUS_OTGID_STATUS      8
#define BM_USB_PHY_STATUS_OTGID_STATUS      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_STATUS_OTGID_STATUS)
#else
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   (((v) << 8) & BM_USB_PHY_STATUS_OTGID_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_OTGID_STATUS(v)   BF_CS1(USB_PHY_STATUS, OTGID_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD2 */

#define BP_USB_PHY_STATUS_RSVD2      7
#define BM_USB_PHY_STATUS_RSVD2      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD2(v)   ((((reg32_t) v) << 7) & BM_USB_PHY_STATUS_RSVD2)
#else
#define BF_USB_PHY_STATUS_RSVD2(v)   (((v) << 7) & BM_USB_PHY_STATUS_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD2(v)   BF_CS1(USB_PHY_STATUS, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field DEVPLUGIN_STATUS */

#define BP_USB_PHY_STATUS_DEVPLUGIN_STATUS      6
#define BM_USB_PHY_STATUS_DEVPLUGIN_STATUS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_STATUS_DEVPLUGIN_STATUS)
#else
#define BF_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   (((v) << 6) & BM_USB_PHY_STATUS_DEVPLUGIN_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_DEVPLUGIN_STATUS(v)   BF_CS1(USB_PHY_STATUS, DEVPLUGIN_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD1 */

#define BP_USB_PHY_STATUS_RSVD1      4
#define BM_USB_PHY_STATUS_RSVD1      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD1(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_STATUS_RSVD1)
#else
#define BF_USB_PHY_STATUS_RSVD1(v)   (((v) << 4) & BM_USB_PHY_STATUS_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD1(v)   BF_CS1(USB_PHY_STATUS, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field HOSTDISCONDETECT_STATUS */

#define BP_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      3
#define BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS)
#else
#define BF_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   (((v) << 3) & BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(v)   BF_CS1(USB_PHY_STATUS, HOSTDISCONDETECT_STATUS, v)
#endif

/* --- Register HW_USB_PHY_STATUS, field RSVD0 */

#define BP_USB_PHY_STATUS_RSVD0      0
#define BM_USB_PHY_STATUS_RSVD0      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_STATUS_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_STATUS_RSVD0)
#else
#define BF_USB_PHY_STATUS_RSVD0(v)   (((v) << 0) & BM_USB_PHY_STATUS_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_STATUS_RSVD0(v)   BF_CS1(USB_PHY_STATUS, RSVD0, v)
#endif

/*
 * HW_USB_PHY_DEBUG - USB PHY Debug Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD3 : 1;
        unsigned CLKGATE : 1;
        unsigned HOST_RESUME_DEBUG : 1;
        unsigned SQUELCHRESETLENGTH : 4;
        unsigned ENSQUELCHRESET : 1;
        unsigned RSVD2 : 3;
        unsigned SQUELCHRESETCOUNT : 5;
        unsigned RSVD1 : 3;
        unsigned ENTX2RXCOUNT : 1;
        unsigned TX2RXCOUNT : 4;
        unsigned RSVD0 : 2;
        unsigned ENHSTPULLDOWN : 2;
        unsigned HSTPULLDOWN : 2;
        unsigned DEBUG_INTERFACE_HOLD : 1;
        unsigned OTGIDPIOLOCK : 1;

    } B;
} hw_usb_phy_debug_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG register
 */
#define HW_USB_PHY_DEBUG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG(x)           (*(volatile hw_usb_phy_debug_t *) HW_USB_PHY_DEBUG_ADDR(x))
#define HW_USB_PHY_DEBUG_RD(x)        (HW_USB_PHY_DEBUG(x).U)
#define HW_USB_PHY_DEBUG_WR(x, v)     (HW_USB_PHY_DEBUG(x).U = (v))
#define HW_USB_PHY_DEBUG_SET(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG_CLR(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG_TOG(x, v)    (HW_USB_PHY_DEBUG_WR(x, HW_USB_PHY_DEBUG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_DEBUG bitfields
 */

/* --- Register HW_USB_PHY_DEBUG, field RSVD3 */

#define BP_USB_PHY_DEBUG_RSVD3      31
#define BM_USB_PHY_DEBUG_RSVD3      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD3(v)   ((((reg32_t) v) << 31) & BM_USB_PHY_DEBUG_RSVD3)
#else
#define BF_USB_PHY_DEBUG_RSVD3(v)   (((v) << 31) & BM_USB_PHY_DEBUG_RSVD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD3(v)   BF_CS1(USB_PHY_DEBUG, RSVD3, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field CLKGATE */

#define BP_USB_PHY_DEBUG_CLKGATE      30
#define BM_USB_PHY_DEBUG_CLKGATE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#else
#define BF_USB_PHY_DEBUG_CLKGATE(v)   (((v) << 30) & BM_USB_PHY_DEBUG_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_CLKGATE(v)   BF_CS1(USB_PHY_DEBUG, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HOST_RESUME_DEBUG */

#define BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG      29
#define BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << 29) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#else
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   (((v) << 29) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   BF_CS1(USB_PHY_DEBUG, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETLENGTH */

#define BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH      25
#define BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH      0x1e000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#else
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   (((v) << 25) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENSQUELCHRESET */

#define BP_USB_PHY_DEBUG_ENSQUELCHRESET      24
#define BM_USB_PHY_DEBUG_ENSQUELCHRESET      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#else
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   (((v) << 24) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_ENSQUELCHRESET(v)   BF_CS1(USB_PHY_DEBUG, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD2 */

#define BP_USB_PHY_DEBUG_RSVD2      21
#define BM_USB_PHY_DEBUG_RSVD2      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD2(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_DEBUG_RSVD2)
#else
#define BF_USB_PHY_DEBUG_RSVD2(v)   (((v) << 21) & BM_USB_PHY_DEBUG_RSVD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD2(v)   BF_CS1(USB_PHY_DEBUG, RSVD2, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETCOUNT */

#define BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT      16
#define BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#else
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   BF_CS1(USB_PHY_DEBUG, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD1 */

#define BP_USB_PHY_DEBUG_RSVD1      13
#define BM_USB_PHY_DEBUG_RSVD1      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD1(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG_RSVD1)
#else
#define BF_USB_PHY_DEBUG_RSVD1(v)   (((v) << 13) & BM_USB_PHY_DEBUG_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD1(v)   BF_CS1(USB_PHY_DEBUG, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENTX2RXCOUNT */

#define BP_USB_PHY_DEBUG_ENTX2RXCOUNT      12
#define BM_USB_PHY_DEBUG_ENTX2RXCOUNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   (((v) << 12) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field TX2RXCOUNT */

#define BP_USB_PHY_DEBUG_TX2RXCOUNT      8
#define BM_USB_PHY_DEBUG_TX2RXCOUNT      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   ((((reg32_t) v) << 8) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#else
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   (((v) << 8) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_TX2RXCOUNT(v)   BF_CS1(USB_PHY_DEBUG, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field RSVD0 */

#define BP_USB_PHY_DEBUG_RSVD0      6
#define BM_USB_PHY_DEBUG_RSVD0      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_RSVD0(v)   ((((reg32_t) v) << 6) & BM_USB_PHY_DEBUG_RSVD0)
#else
#define BF_USB_PHY_DEBUG_RSVD0(v)   (((v) << 6) & BM_USB_PHY_DEBUG_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_RSVD0(v)   BF_CS1(USB_PHY_DEBUG, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENHSTPULLDOWN */

#define BP_USB_PHY_DEBUG_ENHSTPULLDOWN      4
#define BM_USB_PHY_DEBUG_ENHSTPULLDOWN      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   (((v) << 4) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HSTPULLDOWN */

#define BP_USB_PHY_DEBUG_HSTPULLDOWN      2
#define BM_USB_PHY_DEBUG_HSTPULLDOWN      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#else
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   (((v) << 2) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_HSTPULLDOWN(v)   BF_CS1(USB_PHY_DEBUG, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field DEBUG_INTERFACE_HOLD */

#define BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      1
#define BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#else
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   (((v) << 1) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   BF_CS1(USB_PHY_DEBUG, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field OTGIDPIOLOCK */

#define BP_USB_PHY_DEBUG_OTGIDPIOLOCK      0
#define BM_USB_PHY_DEBUG_OTGIDPIOLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#else
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   (((v) << 0) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   BF_CS1(USB_PHY_DEBUG, OTGIDPIOLOCK, v)
#endif

/*
 * HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SQUELCH_COUNT : 6;
        unsigned UTMI_RXERROR_FAIL_COUNT : 10;
        unsigned LOOP_BACK_FAIL_COUNT : 16;

    } B;
} hw_usb_phy_debug0_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG0_STATUS register
 */
#define HW_USB_PHY_DEBUG0_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG0_STATUS(x)           (*(volatile hw_usb_phy_debug0_status_t *) HW_USB_PHY_DEBUG0_STATUS_ADDR(x))
#define HW_USB_PHY_DEBUG0_STATUS_RD(x)        (HW_USB_PHY_DEBUG0_STATUS(x).U)
#define HW_USB_PHY_DEBUG0_STATUS_WR(x, v)     (HW_USB_PHY_DEBUG0_STATUS(x).U = (v))
#define HW_USB_PHY_DEBUG0_STATUS_SET(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG0_STATUS_CLR(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG0_STATUS_TOG(x, v)    (HW_USB_PHY_DEBUG0_STATUS_WR(x, HW_USB_PHY_DEBUG0_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_DEBUG0_STATUS bitfields
 */

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field SQUELCH_COUNT */

#define BP_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      26
#define BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      0xfc000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   ((((reg32_t) v) << 26) & BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   (((v) << 26) & BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, SQUELCH_COUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field UTMI_RXERROR_FAIL_COUNT */

#define BP_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      16
#define BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      0x03ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   (((v) << 16) & BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, UTMI_RXERROR_FAIL_COUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field LOOP_BACK_FAIL_COUNT */

#define BP_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0
#define BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)
#else
#define BF_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   (((v) << 0) & BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)   BF_CS1(USB_PHY_DEBUG0_STATUS, LOOP_BACK_FAIL_COUNT, v)
#endif

/*
 * HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD1 : 17;
        unsigned ENTAILADJVD : 2;
        unsigned RSVD0 : 13;
        unsigned ENTX2TX : 1;
        unsigned RSVD0 : 8;
        unsigned DBG_ADDRESS : 4;

    } B;
} hw_usb_phy_debug1_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1 register
 */
#define HW_USB_PHY_DEBUG1_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1(x)           (*(volatile hw_usb_phy_debug1_t *) HW_USB_PHY_DEBUG1_ADDR(x))
#define HW_USB_PHY_DEBUG1_RD(x)        (HW_USB_PHY_DEBUG1(x).U)
#define HW_USB_PHY_DEBUG1_WR(x, v)     (HW_USB_PHY_DEBUG1(x).U = (v))
#define HW_USB_PHY_DEBUG1_SET(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) |  (v)))
#define HW_USB_PHY_DEBUG1_CLR(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) & ~(v)))
#define HW_USB_PHY_DEBUG1_TOG(x, v)    (HW_USB_PHY_DEBUG1_WR(x, HW_USB_PHY_DEBUG1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_DEBUG1 bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1, field RSVD1 */

#define BP_USB_PHY_DEBUG1_RSVD1      15
#define BM_USB_PHY_DEBUG1_RSVD1      0xffff8000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_RSVD1(v)   ((((reg32_t) v) << 15) & BM_USB_PHY_DEBUG1_RSVD1)
#else
#define BF_USB_PHY_DEBUG1_RSVD1(v)   (((v) << 15) & BM_USB_PHY_DEBUG1_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_RSVD1(v)   BF_CS1(USB_PHY_DEBUG1, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field ENTAILADJVD */

#define BP_USB_PHY_DEBUG1_ENTAILADJVD      13
#define BM_USB_PHY_DEBUG1_ENTAILADJVD      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   ((((reg32_t) v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#else
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   (((v) << 13) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_ENTAILADJVD(v)   BF_CS1(USB_PHY_DEBUG1, ENTAILADJVD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field RSVD0 */

#define BP_USB_PHY_DEBUG1_RSVD0      0
#define BM_USB_PHY_DEBUG1_RSVD0      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_RSVD0(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG1_RSVD0)
#else
#define BF_USB_PHY_DEBUG1_RSVD0(v)   (((v) << 0) & BM_USB_PHY_DEBUG1_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_RSVD0(v)   BF_CS1(USB_PHY_DEBUG1, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field ENTX2TX */

#define BP_USB_PHY_DEBUG1_ENTX2TX      12
#define BM_USB_PHY_DEBUG1_ENTX2TX      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_ENTX2TX(v)   ((((reg32_t) v) << 12) & BM_USB_PHY_DEBUG1_ENTX2TX)
#else
#define BF_USB_PHY_DEBUG1_ENTX2TX(v)   (((v) << 12) & BM_USB_PHY_DEBUG1_ENTX2TX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_ENTX2TX(v)   BF_CS1(USB_PHY_DEBUG1, ENTX2TX, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field RSVD0 */

#define BP_USB_PHY_DEBUG1_RSVD0      4
#define BM_USB_PHY_DEBUG1_RSVD0      0x00000ff0

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_RSVD0(v)   ((((reg32_t) v) << 4) & BM_USB_PHY_DEBUG1_RSVD0)
#else
#define BF_USB_PHY_DEBUG1_RSVD0(v)   (((v) << 4) & BM_USB_PHY_DEBUG1_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_RSVD0(v)   BF_CS1(USB_PHY_DEBUG1, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_DEBUG1, field DBG_ADDRESS */

#define BP_USB_PHY_DEBUG1_DBG_ADDRESS      0
#define BM_USB_PHY_DEBUG1_DBG_ADDRESS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_DEBUG1_DBG_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_DEBUG1_DBG_ADDRESS)
#else
#define BF_USB_PHY_DEBUG1_DBG_ADDRESS(v)   (((v) << 0) & BM_USB_PHY_DEBUG1_DBG_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_DEBUG1_DBG_ADDRESS(v)   BF_CS1(USB_PHY_DEBUG1, DBG_ADDRESS, v)
#endif

/*
 * HW_USB_PHY_VERSION - UTMI RTL Version
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MAJOR : 8;
        unsigned MINOR : 8;
        unsigned STEP : 16;

    } B;
} hw_usb_phy_version_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_VERSION register
 */
#define HW_USB_PHY_VERSION_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_VERSION(x)           (*(volatile hw_usb_phy_version_t *) HW_USB_PHY_VERSION_ADDR(x))
#define HW_USB_PHY_VERSION_RD(x)        (HW_USB_PHY_VERSION(x).U)
#define HW_USB_PHY_VERSION_WR(x, v)     (HW_USB_PHY_VERSION(x).U = (v))
#define HW_USB_PHY_VERSION_SET(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) |  (v)))
#define HW_USB_PHY_VERSION_CLR(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) & ~(v)))
#define HW_USB_PHY_VERSION_TOG(x, v)    (HW_USB_PHY_VERSION_WR(x, HW_USB_PHY_VERSION_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_VERSION bitfields
 */

/* --- Register HW_USB_PHY_VERSION, field MAJOR */

#define BP_USB_PHY_VERSION_MAJOR      24
#define BM_USB_PHY_VERSION_MAJOR      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_MAJOR(v)   ((((reg32_t) v) << 24) & BM_USB_PHY_VERSION_MAJOR)
#else
#define BF_USB_PHY_VERSION_MAJOR(v)   (((v) << 24) & BM_USB_PHY_VERSION_MAJOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_MAJOR(v)   BF_CS1(USB_PHY_VERSION, MAJOR, v)
#endif

/* --- Register HW_USB_PHY_VERSION, field MINOR */

#define BP_USB_PHY_VERSION_MINOR      16
#define BM_USB_PHY_VERSION_MINOR      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_MINOR(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_VERSION_MINOR)
#else
#define BF_USB_PHY_VERSION_MINOR(v)   (((v) << 16) & BM_USB_PHY_VERSION_MINOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_MINOR(v)   BF_CS1(USB_PHY_VERSION, MINOR, v)
#endif

/* --- Register HW_USB_PHY_VERSION, field STEP */

#define BP_USB_PHY_VERSION_STEP      0
#define BM_USB_PHY_VERSION_STEP      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_VERSION_STEP(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_VERSION_STEP)
#else
#define BF_USB_PHY_VERSION_STEP(v)   (((v) << 0) & BM_USB_PHY_VERSION_STEP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_VERSION_STEP(v)   BF_CS1(USB_PHY_VERSION, STEP, v)
#endif

/*
 * HW_USB_PHY_IP - USB PHY IP Block Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RSVD1 : 7;
        unsigned DIV_SEL : 2;
        unsigned LFR_SEL : 2;
        unsigned CP_SEL : 2;
        unsigned RSVD1 : 13;
        unsigned TSTI_TX_DP : 1;
        unsigned TSTI_TX_DM : 1;
        unsigned ANALOG_TESTMODE : 1;
        unsigned RSVD0 : 13;
        unsigned EN_USB_CLKS : 1;
        unsigned PLL_LOCKED : 1;
        unsigned PLL_POWER : 1;

    } B;
} hw_usb_phy_ip_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_IP register
 */
#define HW_USB_PHY_IP_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_IP(x)           (*(volatile hw_usb_phy_ip_t *) HW_USB_PHY_IP_ADDR(x))
#define HW_USB_PHY_IP_RD(x)        (HW_USB_PHY_IP(x).U)
#define HW_USB_PHY_IP_WR(x, v)     (HW_USB_PHY_IP(x).U = (v))
#define HW_USB_PHY_IP_SET(x, v)    (HW_USB_PHY_IP_WR(x, HW_USB_PHY_IP_RD(x) |  (v)))
#define HW_USB_PHY_IP_CLR(x, v)    (HW_USB_PHY_IP_WR(x, HW_USB_PHY_IP_RD(x) & ~(v)))
#define HW_USB_PHY_IP_TOG(x, v)    (HW_USB_PHY_IP_WR(x, HW_USB_PHY_IP_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USB_PHY_IP bitfields
 */

/* --- Register HW_USB_PHY_IP, field RSVD1 */

#define BP_USB_PHY_IP_RSVD1      25
#define BM_USB_PHY_IP_RSVD1      0xfe000000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_RSVD1(v)   ((((reg32_t) v) << 25) & BM_USB_PHY_IP_RSVD1)
#else
#define BF_USB_PHY_IP_RSVD1(v)   (((v) << 25) & BM_USB_PHY_IP_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_RSVD1(v)   BF_CS1(USB_PHY_IP, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_IP, field DIV_SEL */

#define BP_USB_PHY_IP_DIV_SEL      23
#define BM_USB_PHY_IP_DIV_SEL      0x01800000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_DIV_SEL(v)   ((((reg32_t) v) << 23) & BM_USB_PHY_IP_DIV_SEL)
#else
#define BF_USB_PHY_IP_DIV_SEL(v)   (((v) << 23) & BM_USB_PHY_IP_DIV_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_DIV_SEL(v)   BF_CS1(USB_PHY_IP, DIV_SEL, v)
#endif

#define BV_USB_PHY_IP_DIV_SEL__DEFAULT    0x0
#define BV_USB_PHY_IP_DIV_SEL__LOWER    0x1
#define BV_USB_PHY_IP_DIV_SEL__LOWEST    0x2
#define BV_USB_PHY_IP_DIV_SEL__UNDEFINED    0x3

/* --- Register HW_USB_PHY_IP, field LFR_SEL */

#define BP_USB_PHY_IP_LFR_SEL      21
#define BM_USB_PHY_IP_LFR_SEL      0x00600000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_LFR_SEL(v)   ((((reg32_t) v) << 21) & BM_USB_PHY_IP_LFR_SEL)
#else
#define BF_USB_PHY_IP_LFR_SEL(v)   (((v) << 21) & BM_USB_PHY_IP_LFR_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_LFR_SEL(v)   BF_CS1(USB_PHY_IP, LFR_SEL, v)
#endif

#define BV_USB_PHY_IP_LFR_SEL__DEFAULT    0x0
#define BV_USB_PHY_IP_LFR_SEL__TIMES_2    0x1
#define BV_USB_PHY_IP_LFR_SEL__TIMES_05    0x2
#define BV_USB_PHY_IP_LFR_SEL__UNDEFINED    0x3

/* --- Register HW_USB_PHY_IP, field CP_SEL */

#define BP_USB_PHY_IP_CP_SEL      19
#define BM_USB_PHY_IP_CP_SEL      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_CP_SEL(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_IP_CP_SEL)
#else
#define BF_USB_PHY_IP_CP_SEL(v)   (((v) << 19) & BM_USB_PHY_IP_CP_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_CP_SEL(v)   BF_CS1(USB_PHY_IP, CP_SEL, v)
#endif

#define BV_USB_PHY_IP_CP_SEL__DEFAULT    0x0
#define BV_USB_PHY_IP_CP_SEL__TIMES_2    0x1
#define BV_USB_PHY_IP_CP_SEL__TIMES_05    0x2
#define BV_USB_PHY_IP_CP_SEL__UNDEFINED    0x3

/* --- Register HW_USB_PHY_IP, field RSVD1 */

#define BP_USB_PHY_IP_RSVD1      19
#define BM_USB_PHY_IP_RSVD1      0xfff80000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_RSVD1(v)   ((((reg32_t) v) << 19) & BM_USB_PHY_IP_RSVD1)
#else
#define BF_USB_PHY_IP_RSVD1(v)   (((v) << 19) & BM_USB_PHY_IP_RSVD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_RSVD1(v)   BF_CS1(USB_PHY_IP, RSVD1, v)
#endif

/* --- Register HW_USB_PHY_IP, field TSTI_TX_DP */

#define BP_USB_PHY_IP_TSTI_TX_DP      18
#define BM_USB_PHY_IP_TSTI_TX_DP      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_TSTI_TX_DP(v)   ((((reg32_t) v) << 18) & BM_USB_PHY_IP_TSTI_TX_DP)
#else
#define BF_USB_PHY_IP_TSTI_TX_DP(v)   (((v) << 18) & BM_USB_PHY_IP_TSTI_TX_DP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_TSTI_TX_DP(v)   BF_CS1(USB_PHY_IP, TSTI_TX_DP, v)
#endif

/* --- Register HW_USB_PHY_IP, field TSTI_TX_DM */

#define BP_USB_PHY_IP_TSTI_TX_DM      17
#define BM_USB_PHY_IP_TSTI_TX_DM      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_TSTI_TX_DM(v)   ((((reg32_t) v) << 17) & BM_USB_PHY_IP_TSTI_TX_DM)
#else
#define BF_USB_PHY_IP_TSTI_TX_DM(v)   (((v) << 17) & BM_USB_PHY_IP_TSTI_TX_DM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_TSTI_TX_DM(v)   BF_CS1(USB_PHY_IP, TSTI_TX_DM, v)
#endif

/* --- Register HW_USB_PHY_IP, field ANALOG_TESTMODE */

#define BP_USB_PHY_IP_ANALOG_TESTMODE      16
#define BM_USB_PHY_IP_ANALOG_TESTMODE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_ANALOG_TESTMODE(v)   ((((reg32_t) v) << 16) & BM_USB_PHY_IP_ANALOG_TESTMODE)
#else
#define BF_USB_PHY_IP_ANALOG_TESTMODE(v)   (((v) << 16) & BM_USB_PHY_IP_ANALOG_TESTMODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_ANALOG_TESTMODE(v)   BF_CS1(USB_PHY_IP, ANALOG_TESTMODE, v)
#endif

/* --- Register HW_USB_PHY_IP, field RSVD0 */

#define BP_USB_PHY_IP_RSVD0      3
#define BM_USB_PHY_IP_RSVD0      0x0000fff8

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_RSVD0(v)   ((((reg32_t) v) << 3) & BM_USB_PHY_IP_RSVD0)
#else
#define BF_USB_PHY_IP_RSVD0(v)   (((v) << 3) & BM_USB_PHY_IP_RSVD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_RSVD0(v)   BF_CS1(USB_PHY_IP, RSVD0, v)
#endif

/* --- Register HW_USB_PHY_IP, field EN_USB_CLKS */

#define BP_USB_PHY_IP_EN_USB_CLKS      2
#define BM_USB_PHY_IP_EN_USB_CLKS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_EN_USB_CLKS(v)   ((((reg32_t) v) << 2) & BM_USB_PHY_IP_EN_USB_CLKS)
#else
#define BF_USB_PHY_IP_EN_USB_CLKS(v)   (((v) << 2) & BM_USB_PHY_IP_EN_USB_CLKS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_EN_USB_CLKS(v)   BF_CS1(USB_PHY_IP, EN_USB_CLKS, v)
#endif

/* --- Register HW_USB_PHY_IP, field PLL_LOCKED */

#define BP_USB_PHY_IP_PLL_LOCKED      1
#define BM_USB_PHY_IP_PLL_LOCKED      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_PLL_LOCKED(v)   ((((reg32_t) v) << 1) & BM_USB_PHY_IP_PLL_LOCKED)
#else
#define BF_USB_PHY_IP_PLL_LOCKED(v)   (((v) << 1) & BM_USB_PHY_IP_PLL_LOCKED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_PLL_LOCKED(v)   BF_CS1(USB_PHY_IP, PLL_LOCKED, v)
#endif

/* --- Register HW_USB_PHY_IP, field PLL_POWER */

#define BP_USB_PHY_IP_PLL_POWER      0
#define BM_USB_PHY_IP_PLL_POWER      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USB_PHY_IP_PLL_POWER(v)   ((((reg32_t) v) << 0) & BM_USB_PHY_IP_PLL_POWER)
#else
#define BF_USB_PHY_IP_PLL_POWER(v)   (((v) << 0) & BM_USB_PHY_IP_PLL_POWER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USB_PHY_IP_PLL_POWER(v)   BF_CS1(USB_PHY_IP, PLL_POWER, v)
#endif


#endif // _USB_PHY_H

