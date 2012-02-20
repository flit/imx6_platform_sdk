/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USDHC_H
#define _USDHC_H

#include "regs.h"

#ifndef REGS_USDHC_BASE
#define REGS_USDHC0_BASE (REGS_BASE + 0x02190000)
#define REGS_USDHC1_BASE (REGS_BASE + 0x02194000)
#define REGS_USDHC2_BASE (REGS_BASE + 0x02198000)
#define REGS_USDHC3_BASE (REGS_BASE + 0x0219c000)
#define REGS_USDHC_BASE(x) ( x == 0 ? REGS_USDHC0_BASE : x == 1 ? REGS_USDHC1_BASE : x == 2 ? REGS_USDHC2_BASE : x == 3 ? REGS_USDHC3_BASE : 0xffff0000)

#endif


/*
 * HW_USDHC_DS_ADDR - DMA System Address
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned DS_ADDR : 30;

    } B;
} hw_usdhc_ds_addr_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DS_ADDR register
 */
#define HW_USDHC_DS_ADDR_ADDR(x)      (REGS_USDHC_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DS_ADDR(x)           (*(volatile hw_usdhc_ds_addr_t *) HW_USDHC_DS_ADDR_ADDR(x))
#define HW_USDHC_DS_ADDR_RD(x)        (HW_USDHC_DS_ADDR(x).U)
#define HW_USDHC_DS_ADDR_WR(x, v)     (HW_USDHC_DS_ADDR(x).U = (v))
#define HW_USDHC_DS_ADDR_SET(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) |  (v)))
#define HW_USDHC_DS_ADDR_CLR(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) & ~(v)))
#define HW_USDHC_DS_ADDR_TOG(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DS_ADDR bitfields
 */

/* --- Register HW_USDHC_DS_ADDR, field DS_ADDR */

#define BP_USDHC_DS_ADDR_DS_ADDR      2
#define BM_USDHC_DS_ADDR_DS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DS_ADDR_DS_ADDR(v)   ((((reg32_t) v) << 2) & BM_USDHC_DS_ADDR_DS_ADDR)
#else
#define BF_USDHC_DS_ADDR_DS_ADDR(v)   (((v) << 2) & BM_USDHC_DS_ADDR_DS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DS_ADDR_DS_ADDR(v)   BF_CS1(USDHC_DS_ADDR, DS_ADDR, v)
#endif

/*
 * HW_USDHC_BLK_ATT - Block Attributes
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BLKSIZE : 13;
        unsigned RESERVED0 : 3;
        unsigned BLKCNT : 16;

    } B;
} hw_usdhc_blk_att_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_BLK_ATT register
 */
#define HW_USDHC_BLK_ATT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_BLK_ATT(x)           (*(volatile hw_usdhc_blk_att_t *) HW_USDHC_BLK_ATT_ADDR(x))
#define HW_USDHC_BLK_ATT_RD(x)        (HW_USDHC_BLK_ATT(x).U)
#define HW_USDHC_BLK_ATT_WR(x, v)     (HW_USDHC_BLK_ATT(x).U = (v))
#define HW_USDHC_BLK_ATT_SET(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) |  (v)))
#define HW_USDHC_BLK_ATT_CLR(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) & ~(v)))
#define HW_USDHC_BLK_ATT_TOG(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_BLK_ATT bitfields
 */

/* --- Register HW_USDHC_BLK_ATT, field BLKSIZE */

#define BP_USDHC_BLK_ATT_BLKSIZE      0
#define BM_USDHC_BLK_ATT_BLKSIZE      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_BLK_ATT_BLKSIZE(v)   ((((reg32_t) v) << 0) & BM_USDHC_BLK_ATT_BLKSIZE)
#else
#define BF_USDHC_BLK_ATT_BLKSIZE(v)   (((v) << 0) & BM_USDHC_BLK_ATT_BLKSIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_BLK_ATT_BLKSIZE(v)   BF_CS1(USDHC_BLK_ATT, BLKSIZE, v)
#endif

/* --- Register HW_USDHC_BLK_ATT, field BLKCNT */

#define BP_USDHC_BLK_ATT_BLKCNT      16
#define BM_USDHC_BLK_ATT_BLKCNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_BLK_ATT_BLKCNT(v)   ((((reg32_t) v) << 16) & BM_USDHC_BLK_ATT_BLKCNT)
#else
#define BF_USDHC_BLK_ATT_BLKCNT(v)   (((v) << 16) & BM_USDHC_BLK_ATT_BLKCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_BLK_ATT_BLKCNT(v)   BF_CS1(USDHC_BLK_ATT, BLKCNT, v)
#endif

/*
 * HW_USDHC_CMD_ARG - Command Argument
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDARG : 32;

    } B;
} hw_usdhc_cmd_arg_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_ARG register
 */
#define HW_USDHC_CMD_ARG_ADDR(x)      (REGS_USDHC_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_ARG(x)           (*(volatile hw_usdhc_cmd_arg_t *) HW_USDHC_CMD_ARG_ADDR(x))
#define HW_USDHC_CMD_ARG_RD(x)        (HW_USDHC_CMD_ARG(x).U)
#define HW_USDHC_CMD_ARG_WR(x, v)     (HW_USDHC_CMD_ARG(x).U = (v))
#define HW_USDHC_CMD_ARG_SET(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) |  (v)))
#define HW_USDHC_CMD_ARG_CLR(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) & ~(v)))
#define HW_USDHC_CMD_ARG_TOG(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_ARG bitfields
 */

/* --- Register HW_USDHC_CMD_ARG, field CMDARG */

#define BP_USDHC_CMD_ARG_CMDARG      0
#define BM_USDHC_CMD_ARG_CMDARG      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_ARG_CMDARG(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_ARG_CMDARG)
#else
#define BF_USDHC_CMD_ARG_CMDARG(v)   (((v) << 0) & BM_USDHC_CMD_ARG_CMDARG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_ARG_CMDARG(v)   BF_CS1(USDHC_CMD_ARG, CMDARG, v)
#endif

/*
 * HW_USDHC_CMD_XFR_TYP - Command Transfer Type
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RSPTYP : 2;
        unsigned RESERVED1 : 1;
        unsigned CCCEN : 1;
        unsigned CICEN : 1;
        unsigned DPSEL : 1;
        unsigned CMDTYP : 2;
        unsigned CMDINX : 6;
        unsigned RESERVED2 : 2;

    } B;
} hw_usdhc_cmd_xfr_typ_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_XFR_TYP register
 */
#define HW_USDHC_CMD_XFR_TYP_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_XFR_TYP(x)           (*(volatile hw_usdhc_cmd_xfr_typ_t *) HW_USDHC_CMD_XFR_TYP_ADDR(x))
#define HW_USDHC_CMD_XFR_TYP_RD(x)        (HW_USDHC_CMD_XFR_TYP(x).U)
#define HW_USDHC_CMD_XFR_TYP_WR(x, v)     (HW_USDHC_CMD_XFR_TYP(x).U = (v))
#define HW_USDHC_CMD_XFR_TYP_SET(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) |  (v)))
#define HW_USDHC_CMD_XFR_TYP_CLR(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) & ~(v)))
#define HW_USDHC_CMD_XFR_TYP_TOG(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_XFR_TYP bitfields
 */

/* --- Register HW_USDHC_CMD_XFR_TYP, field RSPTYP */

#define BP_USDHC_CMD_XFR_TYP_RSPTYP      16
#define BM_USDHC_CMD_XFR_TYP_RSPTYP      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_RSPTYP(v)   ((((reg32_t) v) << 16) & BM_USDHC_CMD_XFR_TYP_RSPTYP)
#else
#define BF_USDHC_CMD_XFR_TYP_RSPTYP(v)   (((v) << 16) & BM_USDHC_CMD_XFR_TYP_RSPTYP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_RSPTYP(v)   BF_CS1(USDHC_CMD_XFR_TYP, RSPTYP, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CCCEN */

#define BP_USDHC_CMD_XFR_TYP_CCCEN      19
#define BM_USDHC_CMD_XFR_TYP_CCCEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CCCEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_CMD_XFR_TYP_CCCEN)
#else
#define BF_USDHC_CMD_XFR_TYP_CCCEN(v)   (((v) << 19) & BM_USDHC_CMD_XFR_TYP_CCCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CCCEN(v)   BF_CS1(USDHC_CMD_XFR_TYP, CCCEN, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CICEN */

#define BP_USDHC_CMD_XFR_TYP_CICEN      20
#define BM_USDHC_CMD_XFR_TYP_CICEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CICEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_CMD_XFR_TYP_CICEN)
#else
#define BF_USDHC_CMD_XFR_TYP_CICEN(v)   (((v) << 20) & BM_USDHC_CMD_XFR_TYP_CICEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CICEN(v)   BF_CS1(USDHC_CMD_XFR_TYP, CICEN, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field DPSEL */

#define BP_USDHC_CMD_XFR_TYP_DPSEL      21
#define BM_USDHC_CMD_XFR_TYP_DPSEL      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_DPSEL(v)   ((((reg32_t) v) << 21) & BM_USDHC_CMD_XFR_TYP_DPSEL)
#else
#define BF_USDHC_CMD_XFR_TYP_DPSEL(v)   (((v) << 21) & BM_USDHC_CMD_XFR_TYP_DPSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_DPSEL(v)   BF_CS1(USDHC_CMD_XFR_TYP, DPSEL, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CMDTYP */

#define BP_USDHC_CMD_XFR_TYP_CMDTYP      22
#define BM_USDHC_CMD_XFR_TYP_CMDTYP      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CMDTYP(v)   ((((reg32_t) v) << 22) & BM_USDHC_CMD_XFR_TYP_CMDTYP)
#else
#define BF_USDHC_CMD_XFR_TYP_CMDTYP(v)   (((v) << 22) & BM_USDHC_CMD_XFR_TYP_CMDTYP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CMDTYP(v)   BF_CS1(USDHC_CMD_XFR_TYP, CMDTYP, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CMDINX */

#define BP_USDHC_CMD_XFR_TYP_CMDINX      24
#define BM_USDHC_CMD_XFR_TYP_CMDINX      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CMDINX(v)   ((((reg32_t) v) << 24) & BM_USDHC_CMD_XFR_TYP_CMDINX)
#else
#define BF_USDHC_CMD_XFR_TYP_CMDINX(v)   (((v) << 24) & BM_USDHC_CMD_XFR_TYP_CMDINX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CMDINX(v)   BF_CS1(USDHC_CMD_XFR_TYP, CMDINX, v)
#endif

/*
 * HW_USDHC_CMD_RSP0 - Command Response0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP0 : 32;

    } B;
} hw_usdhc_cmd_rsp0_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP0 register
 */
#define HW_USDHC_CMD_RSP0_ADDR(x)      (REGS_USDHC_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP0(x)           (*(volatile hw_usdhc_cmd_rsp0_t *) HW_USDHC_CMD_RSP0_ADDR(x))
#define HW_USDHC_CMD_RSP0_RD(x)        (HW_USDHC_CMD_RSP0(x).U)
#define HW_USDHC_CMD_RSP0_WR(x, v)     (HW_USDHC_CMD_RSP0(x).U = (v))
#define HW_USDHC_CMD_RSP0_SET(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP0_CLR(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP0_TOG(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP0 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP0, field CMDRSP0 */

#define BP_USDHC_CMD_RSP0_CMDRSP0      0
#define BM_USDHC_CMD_RSP0_CMDRSP0      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP0_CMDRSP0(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP0_CMDRSP0)
#else
#define BF_USDHC_CMD_RSP0_CMDRSP0(v)   (((v) << 0) & BM_USDHC_CMD_RSP0_CMDRSP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP0_CMDRSP0(v)   BF_CS1(USDHC_CMD_RSP0, CMDRSP0, v)
#endif

/*
 * HW_USDHC_CMD_RSP1 - Command Response1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP1 : 32;

    } B;
} hw_usdhc_cmd_rsp1_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP1 register
 */
#define HW_USDHC_CMD_RSP1_ADDR(x)      (REGS_USDHC_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP1(x)           (*(volatile hw_usdhc_cmd_rsp1_t *) HW_USDHC_CMD_RSP1_ADDR(x))
#define HW_USDHC_CMD_RSP1_RD(x)        (HW_USDHC_CMD_RSP1(x).U)
#define HW_USDHC_CMD_RSP1_WR(x, v)     (HW_USDHC_CMD_RSP1(x).U = (v))
#define HW_USDHC_CMD_RSP1_SET(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP1_CLR(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP1_TOG(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP1 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP1, field CMDRSP1 */

#define BP_USDHC_CMD_RSP1_CMDRSP1      0
#define BM_USDHC_CMD_RSP1_CMDRSP1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP1_CMDRSP1(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP1_CMDRSP1)
#else
#define BF_USDHC_CMD_RSP1_CMDRSP1(v)   (((v) << 0) & BM_USDHC_CMD_RSP1_CMDRSP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP1_CMDRSP1(v)   BF_CS1(USDHC_CMD_RSP1, CMDRSP1, v)
#endif

/*
 * HW_USDHC_CMD_RSP2 - Command Response2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP2 : 32;

    } B;
} hw_usdhc_cmd_rsp2_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP2 register
 */
#define HW_USDHC_CMD_RSP2_ADDR(x)      (REGS_USDHC_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP2(x)           (*(volatile hw_usdhc_cmd_rsp2_t *) HW_USDHC_CMD_RSP2_ADDR(x))
#define HW_USDHC_CMD_RSP2_RD(x)        (HW_USDHC_CMD_RSP2(x).U)
#define HW_USDHC_CMD_RSP2_WR(x, v)     (HW_USDHC_CMD_RSP2(x).U = (v))
#define HW_USDHC_CMD_RSP2_SET(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP2_CLR(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP2_TOG(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP2 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP2, field CMDRSP2 */

#define BP_USDHC_CMD_RSP2_CMDRSP2      0
#define BM_USDHC_CMD_RSP2_CMDRSP2      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP2_CMDRSP2(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP2_CMDRSP2)
#else
#define BF_USDHC_CMD_RSP2_CMDRSP2(v)   (((v) << 0) & BM_USDHC_CMD_RSP2_CMDRSP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP2_CMDRSP2(v)   BF_CS1(USDHC_CMD_RSP2, CMDRSP2, v)
#endif

/*
 * HW_USDHC_CMD_RSP3 - Command Response3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP3 : 32;

    } B;
} hw_usdhc_cmd_rsp3_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP3 register
 */
#define HW_USDHC_CMD_RSP3_ADDR(x)      (REGS_USDHC_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP3(x)           (*(volatile hw_usdhc_cmd_rsp3_t *) HW_USDHC_CMD_RSP3_ADDR(x))
#define HW_USDHC_CMD_RSP3_RD(x)        (HW_USDHC_CMD_RSP3(x).U)
#define HW_USDHC_CMD_RSP3_WR(x, v)     (HW_USDHC_CMD_RSP3(x).U = (v))
#define HW_USDHC_CMD_RSP3_SET(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP3_CLR(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP3_TOG(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP3 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP3, field CMDRSP3 */

#define BP_USDHC_CMD_RSP3_CMDRSP3      0
#define BM_USDHC_CMD_RSP3_CMDRSP3      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP3_CMDRSP3(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP3_CMDRSP3)
#else
#define BF_USDHC_CMD_RSP3_CMDRSP3(v)   (((v) << 0) & BM_USDHC_CMD_RSP3_CMDRSP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP3_CMDRSP3(v)   BF_CS1(USDHC_CMD_RSP3, CMDRSP3, v)
#endif

/*
 * HW_USDHC_DATA_BUFF_ACC_PORT - Data Buffer Access Port
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATCONT : 32;

    } B;
} hw_usdhc_data_buff_acc_port_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DATA_BUFF_ACC_PORT register
 */
#define HW_USDHC_DATA_BUFF_ACC_PORT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DATA_BUFF_ACC_PORT(x)           (*(volatile hw_usdhc_data_buff_acc_port_t *) HW_USDHC_DATA_BUFF_ACC_PORT_ADDR(x))
#define HW_USDHC_DATA_BUFF_ACC_PORT_RD(x)        (HW_USDHC_DATA_BUFF_ACC_PORT(x).U)
#define HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, v)     (HW_USDHC_DATA_BUFF_ACC_PORT(x).U = (v))
#define HW_USDHC_DATA_BUFF_ACC_PORT_SET(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) |  (v)))
#define HW_USDHC_DATA_BUFF_ACC_PORT_CLR(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) & ~(v)))
#define HW_USDHC_DATA_BUFF_ACC_PORT_TOG(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DATA_BUFF_ACC_PORT bitfields
 */

/* --- Register HW_USDHC_DATA_BUFF_ACC_PORT, field DATCONT */

#define BP_USDHC_DATA_BUFF_ACC_PORT_DATCONT      0
#define BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   ((((reg32_t) v) << 0) & BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT)
#else
#define BF_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   (((v) << 0) & BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   BF_CS1(USDHC_DATA_BUFF_ACC_PORT, DATCONT, v)
#endif

/*
 * HW_USDHC_PRES_STATE - Present State
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CIHB : 1;
        unsigned CDIHB : 1;
        unsigned DLA : 1;
        unsigned SDSTB : 1;
        unsigned IPGOFF : 1;
        unsigned HCKOFF : 1;
        unsigned PEROFF : 1;
        unsigned SDOFF : 1;
        unsigned WTA : 1;
        unsigned RTA : 1;
        unsigned BWEN : 1;
        unsigned BREN : 1;
        unsigned RTR : 1;
        unsigned RESERVED0 : 3;
        unsigned CINST : 1;
        unsigned RESERVED1 : 1;
        unsigned CDPL : 1;
        unsigned WPSPL : 1;
        unsigned RESERVED2 : 3;
        unsigned CLSL : 1;
        unsigned DLSL : 8;

    } B;
} hw_usdhc_pres_state_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_PRES_STATE register
 */
#define HW_USDHC_PRES_STATE_ADDR(x)      (REGS_USDHC_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_PRES_STATE(x)           (*(volatile hw_usdhc_pres_state_t *) HW_USDHC_PRES_STATE_ADDR(x))
#define HW_USDHC_PRES_STATE_RD(x)        (HW_USDHC_PRES_STATE(x).U)
#define HW_USDHC_PRES_STATE_WR(x, v)     (HW_USDHC_PRES_STATE(x).U = (v))
#define HW_USDHC_PRES_STATE_SET(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) |  (v)))
#define HW_USDHC_PRES_STATE_CLR(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) & ~(v)))
#define HW_USDHC_PRES_STATE_TOG(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_PRES_STATE bitfields
 */

/* --- Register HW_USDHC_PRES_STATE, field CIHB */

#define BP_USDHC_PRES_STATE_CIHB      0
#define BM_USDHC_PRES_STATE_CIHB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CIHB(v)   ((((reg32_t) v) << 0) & BM_USDHC_PRES_STATE_CIHB)
#else
#define BF_USDHC_PRES_STATE_CIHB(v)   (((v) << 0) & BM_USDHC_PRES_STATE_CIHB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CIHB(v)   BF_CS1(USDHC_PRES_STATE, CIHB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CDIHB */

#define BP_USDHC_PRES_STATE_CDIHB      1
#define BM_USDHC_PRES_STATE_CDIHB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CDIHB(v)   ((((reg32_t) v) << 1) & BM_USDHC_PRES_STATE_CDIHB)
#else
#define BF_USDHC_PRES_STATE_CDIHB(v)   (((v) << 1) & BM_USDHC_PRES_STATE_CDIHB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CDIHB(v)   BF_CS1(USDHC_PRES_STATE, CDIHB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field DLA */

#define BP_USDHC_PRES_STATE_DLA      2
#define BM_USDHC_PRES_STATE_DLA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_DLA(v)   ((((reg32_t) v) << 2) & BM_USDHC_PRES_STATE_DLA)
#else
#define BF_USDHC_PRES_STATE_DLA(v)   (((v) << 2) & BM_USDHC_PRES_STATE_DLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_DLA(v)   BF_CS1(USDHC_PRES_STATE, DLA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field SDSTB */

#define BP_USDHC_PRES_STATE_SDSTB      3
#define BM_USDHC_PRES_STATE_SDSTB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_SDSTB(v)   ((((reg32_t) v) << 3) & BM_USDHC_PRES_STATE_SDSTB)
#else
#define BF_USDHC_PRES_STATE_SDSTB(v)   (((v) << 3) & BM_USDHC_PRES_STATE_SDSTB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_SDSTB(v)   BF_CS1(USDHC_PRES_STATE, SDSTB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field IPGOFF */

#define BP_USDHC_PRES_STATE_IPGOFF      4
#define BM_USDHC_PRES_STATE_IPGOFF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_IPGOFF(v)   ((((reg32_t) v) << 4) & BM_USDHC_PRES_STATE_IPGOFF)
#else
#define BF_USDHC_PRES_STATE_IPGOFF(v)   (((v) << 4) & BM_USDHC_PRES_STATE_IPGOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_IPGOFF(v)   BF_CS1(USDHC_PRES_STATE, IPGOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field HCKOFF */

#define BP_USDHC_PRES_STATE_HCKOFF      5
#define BM_USDHC_PRES_STATE_HCKOFF      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_HCKOFF(v)   ((((reg32_t) v) << 5) & BM_USDHC_PRES_STATE_HCKOFF)
#else
#define BF_USDHC_PRES_STATE_HCKOFF(v)   (((v) << 5) & BM_USDHC_PRES_STATE_HCKOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_HCKOFF(v)   BF_CS1(USDHC_PRES_STATE, HCKOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field PEROFF */

#define BP_USDHC_PRES_STATE_PEROFF      6
#define BM_USDHC_PRES_STATE_PEROFF      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_PEROFF(v)   ((((reg32_t) v) << 6) & BM_USDHC_PRES_STATE_PEROFF)
#else
#define BF_USDHC_PRES_STATE_PEROFF(v)   (((v) << 6) & BM_USDHC_PRES_STATE_PEROFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_PEROFF(v)   BF_CS1(USDHC_PRES_STATE, PEROFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field SDOFF */

#define BP_USDHC_PRES_STATE_SDOFF      7
#define BM_USDHC_PRES_STATE_SDOFF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_SDOFF(v)   ((((reg32_t) v) << 7) & BM_USDHC_PRES_STATE_SDOFF)
#else
#define BF_USDHC_PRES_STATE_SDOFF(v)   (((v) << 7) & BM_USDHC_PRES_STATE_SDOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_SDOFF(v)   BF_CS1(USDHC_PRES_STATE, SDOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field WTA */

#define BP_USDHC_PRES_STATE_WTA      8
#define BM_USDHC_PRES_STATE_WTA      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_WTA(v)   ((((reg32_t) v) << 8) & BM_USDHC_PRES_STATE_WTA)
#else
#define BF_USDHC_PRES_STATE_WTA(v)   (((v) << 8) & BM_USDHC_PRES_STATE_WTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_WTA(v)   BF_CS1(USDHC_PRES_STATE, WTA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field RTA */

#define BP_USDHC_PRES_STATE_RTA      9
#define BM_USDHC_PRES_STATE_RTA      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_RTA(v)   ((((reg32_t) v) << 9) & BM_USDHC_PRES_STATE_RTA)
#else
#define BF_USDHC_PRES_STATE_RTA(v)   (((v) << 9) & BM_USDHC_PRES_STATE_RTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_RTA(v)   BF_CS1(USDHC_PRES_STATE, RTA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field BWEN */

#define BP_USDHC_PRES_STATE_BWEN      10
#define BM_USDHC_PRES_STATE_BWEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_BWEN(v)   ((((reg32_t) v) << 10) & BM_USDHC_PRES_STATE_BWEN)
#else
#define BF_USDHC_PRES_STATE_BWEN(v)   (((v) << 10) & BM_USDHC_PRES_STATE_BWEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_BWEN(v)   BF_CS1(USDHC_PRES_STATE, BWEN, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field BREN */

#define BP_USDHC_PRES_STATE_BREN      11
#define BM_USDHC_PRES_STATE_BREN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_BREN(v)   ((((reg32_t) v) << 11) & BM_USDHC_PRES_STATE_BREN)
#else
#define BF_USDHC_PRES_STATE_BREN(v)   (((v) << 11) & BM_USDHC_PRES_STATE_BREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_BREN(v)   BF_CS1(USDHC_PRES_STATE, BREN, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field RTR */

#define BP_USDHC_PRES_STATE_RTR      12
#define BM_USDHC_PRES_STATE_RTR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_RTR(v)   ((((reg32_t) v) << 12) & BM_USDHC_PRES_STATE_RTR)
#else
#define BF_USDHC_PRES_STATE_RTR(v)   (((v) << 12) & BM_USDHC_PRES_STATE_RTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_RTR(v)   BF_CS1(USDHC_PRES_STATE, RTR, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CINST */

#define BP_USDHC_PRES_STATE_CINST      16
#define BM_USDHC_PRES_STATE_CINST      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CINST(v)   ((((reg32_t) v) << 16) & BM_USDHC_PRES_STATE_CINST)
#else
#define BF_USDHC_PRES_STATE_CINST(v)   (((v) << 16) & BM_USDHC_PRES_STATE_CINST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CINST(v)   BF_CS1(USDHC_PRES_STATE, CINST, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CDPL */

#define BP_USDHC_PRES_STATE_CDPL      18
#define BM_USDHC_PRES_STATE_CDPL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CDPL(v)   ((((reg32_t) v) << 18) & BM_USDHC_PRES_STATE_CDPL)
#else
#define BF_USDHC_PRES_STATE_CDPL(v)   (((v) << 18) & BM_USDHC_PRES_STATE_CDPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CDPL(v)   BF_CS1(USDHC_PRES_STATE, CDPL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field WPSPL */

#define BP_USDHC_PRES_STATE_WPSPL      19
#define BM_USDHC_PRES_STATE_WPSPL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_WPSPL(v)   ((((reg32_t) v) << 19) & BM_USDHC_PRES_STATE_WPSPL)
#else
#define BF_USDHC_PRES_STATE_WPSPL(v)   (((v) << 19) & BM_USDHC_PRES_STATE_WPSPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_WPSPL(v)   BF_CS1(USDHC_PRES_STATE, WPSPL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CLSL */

#define BP_USDHC_PRES_STATE_CLSL      23
#define BM_USDHC_PRES_STATE_CLSL      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CLSL(v)   ((((reg32_t) v) << 23) & BM_USDHC_PRES_STATE_CLSL)
#else
#define BF_USDHC_PRES_STATE_CLSL(v)   (((v) << 23) & BM_USDHC_PRES_STATE_CLSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CLSL(v)   BF_CS1(USDHC_PRES_STATE, CLSL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field DLSL */

#define BP_USDHC_PRES_STATE_DLSL      24
#define BM_USDHC_PRES_STATE_DLSL      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_DLSL(v)   ((((reg32_t) v) << 24) & BM_USDHC_PRES_STATE_DLSL)
#else
#define BF_USDHC_PRES_STATE_DLSL(v)   (((v) << 24) & BM_USDHC_PRES_STATE_DLSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_DLSL(v)   BF_CS1(USDHC_PRES_STATE, DLSL, v)
#endif

/*
 * HW_USDHC_PROT_CTRL - Protocol Control
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LCTL : 1;
        unsigned DTW : 2;
        unsigned D3CD : 1;
        unsigned EMODE : 2;
        unsigned CDTL : 1;
        unsigned CDSS : 1;
        unsigned DMASEL : 2;
        unsigned RESERVED0 : 6;
        unsigned SABGREQ : 1;
        unsigned CREQ : 1;
        unsigned RWCTL : 1;
        unsigned IABG : 1;
        unsigned RD_DONE_NO_8CLK : 1;
        unsigned RD_WAIT_POINT : 3;
        unsigned WECINT : 1;
        unsigned WECINS : 1;
        unsigned WECRM : 1;
        unsigned BURST_LEN_EN : 3;
        unsigned NON_EXACT_BLK_RD : 1;
        unsigned RD_NO8CLK_EN : 1;

    } B;
} hw_usdhc_prot_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_PROT_CTRL register
 */
#define HW_USDHC_PROT_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_PROT_CTRL(x)           (*(volatile hw_usdhc_prot_ctrl_t *) HW_USDHC_PROT_CTRL_ADDR(x))
#define HW_USDHC_PROT_CTRL_RD(x)        (HW_USDHC_PROT_CTRL(x).U)
#define HW_USDHC_PROT_CTRL_WR(x, v)     (HW_USDHC_PROT_CTRL(x).U = (v))
#define HW_USDHC_PROT_CTRL_SET(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) |  (v)))
#define HW_USDHC_PROT_CTRL_CLR(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) & ~(v)))
#define HW_USDHC_PROT_CTRL_TOG(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_PROT_CTRL bitfields
 */

/* --- Register HW_USDHC_PROT_CTRL, field LCTL */

#define BP_USDHC_PROT_CTRL_LCTL      0
#define BM_USDHC_PROT_CTRL_LCTL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_LCTL(v)   ((((reg32_t) v) << 0) & BM_USDHC_PROT_CTRL_LCTL)
#else
#define BF_USDHC_PROT_CTRL_LCTL(v)   (((v) << 0) & BM_USDHC_PROT_CTRL_LCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_LCTL(v)   BF_CS1(USDHC_PROT_CTRL, LCTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field DTW */

#define BP_USDHC_PROT_CTRL_DTW      1
#define BM_USDHC_PROT_CTRL_DTW      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_DTW(v)   ((((reg32_t) v) << 1) & BM_USDHC_PROT_CTRL_DTW)
#else
#define BF_USDHC_PROT_CTRL_DTW(v)   (((v) << 1) & BM_USDHC_PROT_CTRL_DTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_DTW(v)   BF_CS1(USDHC_PROT_CTRL, DTW, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field D3CD */

#define BP_USDHC_PROT_CTRL_D3CD      3
#define BM_USDHC_PROT_CTRL_D3CD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_D3CD(v)   ((((reg32_t) v) << 3) & BM_USDHC_PROT_CTRL_D3CD)
#else
#define BF_USDHC_PROT_CTRL_D3CD(v)   (((v) << 3) & BM_USDHC_PROT_CTRL_D3CD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_D3CD(v)   BF_CS1(USDHC_PROT_CTRL, D3CD, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field EMODE */

#define BP_USDHC_PROT_CTRL_EMODE      4
#define BM_USDHC_PROT_CTRL_EMODE      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_EMODE(v)   ((((reg32_t) v) << 4) & BM_USDHC_PROT_CTRL_EMODE)
#else
#define BF_USDHC_PROT_CTRL_EMODE(v)   (((v) << 4) & BM_USDHC_PROT_CTRL_EMODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_EMODE(v)   BF_CS1(USDHC_PROT_CTRL, EMODE, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CDTL */

#define BP_USDHC_PROT_CTRL_CDTL      6
#define BM_USDHC_PROT_CTRL_CDTL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CDTL(v)   ((((reg32_t) v) << 6) & BM_USDHC_PROT_CTRL_CDTL)
#else
#define BF_USDHC_PROT_CTRL_CDTL(v)   (((v) << 6) & BM_USDHC_PROT_CTRL_CDTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CDTL(v)   BF_CS1(USDHC_PROT_CTRL, CDTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CDSS */

#define BP_USDHC_PROT_CTRL_CDSS      7
#define BM_USDHC_PROT_CTRL_CDSS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CDSS(v)   ((((reg32_t) v) << 7) & BM_USDHC_PROT_CTRL_CDSS)
#else
#define BF_USDHC_PROT_CTRL_CDSS(v)   (((v) << 7) & BM_USDHC_PROT_CTRL_CDSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CDSS(v)   BF_CS1(USDHC_PROT_CTRL, CDSS, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field DMASEL */

#define BP_USDHC_PROT_CTRL_DMASEL      8
#define BM_USDHC_PROT_CTRL_DMASEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_DMASEL(v)   ((((reg32_t) v) << 8) & BM_USDHC_PROT_CTRL_DMASEL)
#else
#define BF_USDHC_PROT_CTRL_DMASEL(v)   (((v) << 8) & BM_USDHC_PROT_CTRL_DMASEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_DMASEL(v)   BF_CS1(USDHC_PROT_CTRL, DMASEL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field SABGREQ */

#define BP_USDHC_PROT_CTRL_SABGREQ      16
#define BM_USDHC_PROT_CTRL_SABGREQ      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_SABGREQ(v)   ((((reg32_t) v) << 16) & BM_USDHC_PROT_CTRL_SABGREQ)
#else
#define BF_USDHC_PROT_CTRL_SABGREQ(v)   (((v) << 16) & BM_USDHC_PROT_CTRL_SABGREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_SABGREQ(v)   BF_CS1(USDHC_PROT_CTRL, SABGREQ, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CREQ */

#define BP_USDHC_PROT_CTRL_CREQ      17
#define BM_USDHC_PROT_CTRL_CREQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CREQ(v)   ((((reg32_t) v) << 17) & BM_USDHC_PROT_CTRL_CREQ)
#else
#define BF_USDHC_PROT_CTRL_CREQ(v)   (((v) << 17) & BM_USDHC_PROT_CTRL_CREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CREQ(v)   BF_CS1(USDHC_PROT_CTRL, CREQ, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RWCTL */

#define BP_USDHC_PROT_CTRL_RWCTL      18
#define BM_USDHC_PROT_CTRL_RWCTL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RWCTL(v)   ((((reg32_t) v) << 18) & BM_USDHC_PROT_CTRL_RWCTL)
#else
#define BF_USDHC_PROT_CTRL_RWCTL(v)   (((v) << 18) & BM_USDHC_PROT_CTRL_RWCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RWCTL(v)   BF_CS1(USDHC_PROT_CTRL, RWCTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field IABG */

#define BP_USDHC_PROT_CTRL_IABG      19
#define BM_USDHC_PROT_CTRL_IABG      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_IABG(v)   ((((reg32_t) v) << 19) & BM_USDHC_PROT_CTRL_IABG)
#else
#define BF_USDHC_PROT_CTRL_IABG(v)   (((v) << 19) & BM_USDHC_PROT_CTRL_IABG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_IABG(v)   BF_CS1(USDHC_PROT_CTRL, IABG, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_DONE_NO_8CLK */

#define BP_USDHC_PROT_CTRL_RD_DONE_NO_8CLK      20
#define BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   ((((reg32_t) v) << 20) & BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK)
#else
#define BF_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   (((v) << 20) & BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   BF_CS1(USDHC_PROT_CTRL, RD_DONE_NO_8CLK, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_WAIT_POINT */

#define BP_USDHC_PROT_CTRL_RD_WAIT_POINT      21
#define BM_USDHC_PROT_CTRL_RD_WAIT_POINT      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   ((((reg32_t) v) << 21) & BM_USDHC_PROT_CTRL_RD_WAIT_POINT)
#else
#define BF_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   (((v) << 21) & BM_USDHC_PROT_CTRL_RD_WAIT_POINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   BF_CS1(USDHC_PROT_CTRL, RD_WAIT_POINT, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECINT */

#define BP_USDHC_PROT_CTRL_WECINT      24
#define BM_USDHC_PROT_CTRL_WECINT      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECINT(v)   ((((reg32_t) v) << 24) & BM_USDHC_PROT_CTRL_WECINT)
#else
#define BF_USDHC_PROT_CTRL_WECINT(v)   (((v) << 24) & BM_USDHC_PROT_CTRL_WECINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECINT(v)   BF_CS1(USDHC_PROT_CTRL, WECINT, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECINS */

#define BP_USDHC_PROT_CTRL_WECINS      25
#define BM_USDHC_PROT_CTRL_WECINS      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECINS(v)   ((((reg32_t) v) << 25) & BM_USDHC_PROT_CTRL_WECINS)
#else
#define BF_USDHC_PROT_CTRL_WECINS(v)   (((v) << 25) & BM_USDHC_PROT_CTRL_WECINS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECINS(v)   BF_CS1(USDHC_PROT_CTRL, WECINS, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECRM */

#define BP_USDHC_PROT_CTRL_WECRM      26
#define BM_USDHC_PROT_CTRL_WECRM      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECRM(v)   ((((reg32_t) v) << 26) & BM_USDHC_PROT_CTRL_WECRM)
#else
#define BF_USDHC_PROT_CTRL_WECRM(v)   (((v) << 26) & BM_USDHC_PROT_CTRL_WECRM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECRM(v)   BF_CS1(USDHC_PROT_CTRL, WECRM, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field BURST_LEN_EN */

#define BP_USDHC_PROT_CTRL_BURST_LEN_EN      27
#define BM_USDHC_PROT_CTRL_BURST_LEN_EN      0x38000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_BURST_LEN_EN(v)   ((((reg32_t) v) << 27) & BM_USDHC_PROT_CTRL_BURST_LEN_EN)
#else
#define BF_USDHC_PROT_CTRL_BURST_LEN_EN(v)   (((v) << 27) & BM_USDHC_PROT_CTRL_BURST_LEN_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_BURST_LEN_EN(v)   BF_CS1(USDHC_PROT_CTRL, BURST_LEN_EN, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field NON_EXACT_BLK_RD */

#define BP_USDHC_PROT_CTRL_NON_EXACT_BLK_RD      30
#define BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   ((((reg32_t) v) << 30) & BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD)
#else
#define BF_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   (((v) << 30) & BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   BF_CS1(USDHC_PROT_CTRL, NON_EXACT_BLK_RD, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_NO8CLK_EN */

#define BP_USDHC_PROT_CTRL_RD_NO8CLK_EN      31
#define BM_USDHC_PROT_CTRL_RD_NO8CLK_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   ((((reg32_t) v) << 31) & BM_USDHC_PROT_CTRL_RD_NO8CLK_EN)
#else
#define BF_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   (((v) << 31) & BM_USDHC_PROT_CTRL_RD_NO8CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   BF_CS1(USDHC_PROT_CTRL, RD_NO8CLK_EN, v)
#endif

/*
 * HW_USDHC_SYS_CTRL - System Control
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPGEN : 1;
        unsigned HCKEN : 1;
        unsigned PEREN : 1;
        unsigned SDCLKEN : 1;
        unsigned DVS : 4;
        unsigned SDCLKFS : 8;
        unsigned DTOCV : 4;
        unsigned RESERVED0 : 2;
        unsigned RST_FIFO : 1;
        unsigned IPP_RST_N : 1;
        unsigned RSTA : 1;
        unsigned RSTC : 1;
        unsigned RSTD : 1;
        unsigned INITA : 1;
        unsigned RESERVED1 : 4;

    } B;
} hw_usdhc_sys_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_SYS_CTRL register
 */
#define HW_USDHC_SYS_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_SYS_CTRL(x)           (*(volatile hw_usdhc_sys_ctrl_t *) HW_USDHC_SYS_CTRL_ADDR(x))
#define HW_USDHC_SYS_CTRL_RD(x)        (HW_USDHC_SYS_CTRL(x).U)
#define HW_USDHC_SYS_CTRL_WR(x, v)     (HW_USDHC_SYS_CTRL(x).U = (v))
#define HW_USDHC_SYS_CTRL_SET(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) |  (v)))
#define HW_USDHC_SYS_CTRL_CLR(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) & ~(v)))
#define HW_USDHC_SYS_CTRL_TOG(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_SYS_CTRL bitfields
 */

/* --- Register HW_USDHC_SYS_CTRL, field IPGEN */

#define BP_USDHC_SYS_CTRL_IPGEN      0
#define BM_USDHC_SYS_CTRL_IPGEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_IPGEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_SYS_CTRL_IPGEN)
#else
#define BF_USDHC_SYS_CTRL_IPGEN(v)   (((v) << 0) & BM_USDHC_SYS_CTRL_IPGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_IPGEN(v)   BF_CS1(USDHC_SYS_CTRL, IPGEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field HCKEN */

#define BP_USDHC_SYS_CTRL_HCKEN      1
#define BM_USDHC_SYS_CTRL_HCKEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_HCKEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_SYS_CTRL_HCKEN)
#else
#define BF_USDHC_SYS_CTRL_HCKEN(v)   (((v) << 1) & BM_USDHC_SYS_CTRL_HCKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_HCKEN(v)   BF_CS1(USDHC_SYS_CTRL, HCKEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field PEREN */

#define BP_USDHC_SYS_CTRL_PEREN      2
#define BM_USDHC_SYS_CTRL_PEREN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_PEREN(v)   ((((reg32_t) v) << 2) & BM_USDHC_SYS_CTRL_PEREN)
#else
#define BF_USDHC_SYS_CTRL_PEREN(v)   (((v) << 2) & BM_USDHC_SYS_CTRL_PEREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_PEREN(v)   BF_CS1(USDHC_SYS_CTRL, PEREN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field SDCLKEN */

#define BP_USDHC_SYS_CTRL_SDCLKEN      3
#define BM_USDHC_SYS_CTRL_SDCLKEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_SDCLKEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_SYS_CTRL_SDCLKEN)
#else
#define BF_USDHC_SYS_CTRL_SDCLKEN(v)   (((v) << 3) & BM_USDHC_SYS_CTRL_SDCLKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_SDCLKEN(v)   BF_CS1(USDHC_SYS_CTRL, SDCLKEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field DVS */

#define BP_USDHC_SYS_CTRL_DVS      4
#define BM_USDHC_SYS_CTRL_DVS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_DVS(v)   ((((reg32_t) v) << 4) & BM_USDHC_SYS_CTRL_DVS)
#else
#define BF_USDHC_SYS_CTRL_DVS(v)   (((v) << 4) & BM_USDHC_SYS_CTRL_DVS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_DVS(v)   BF_CS1(USDHC_SYS_CTRL, DVS, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field SDCLKFS */

#define BP_USDHC_SYS_CTRL_SDCLKFS      8
#define BM_USDHC_SYS_CTRL_SDCLKFS      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_SDCLKFS(v)   ((((reg32_t) v) << 8) & BM_USDHC_SYS_CTRL_SDCLKFS)
#else
#define BF_USDHC_SYS_CTRL_SDCLKFS(v)   (((v) << 8) & BM_USDHC_SYS_CTRL_SDCLKFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_SDCLKFS(v)   BF_CS1(USDHC_SYS_CTRL, SDCLKFS, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field DTOCV */

#define BP_USDHC_SYS_CTRL_DTOCV      16
#define BM_USDHC_SYS_CTRL_DTOCV      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_DTOCV(v)   ((((reg32_t) v) << 16) & BM_USDHC_SYS_CTRL_DTOCV)
#else
#define BF_USDHC_SYS_CTRL_DTOCV(v)   (((v) << 16) & BM_USDHC_SYS_CTRL_DTOCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_DTOCV(v)   BF_CS1(USDHC_SYS_CTRL, DTOCV, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RST_FIFO */

#define BP_USDHC_SYS_CTRL_RST_FIFO      22
#define BM_USDHC_SYS_CTRL_RST_FIFO      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RST_FIFO(v)   ((((reg32_t) v) << 22) & BM_USDHC_SYS_CTRL_RST_FIFO)
#else
#define BF_USDHC_SYS_CTRL_RST_FIFO(v)   (((v) << 22) & BM_USDHC_SYS_CTRL_RST_FIFO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RST_FIFO(v)   BF_CS1(USDHC_SYS_CTRL, RST_FIFO, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field IPP_RST_N */

#define BP_USDHC_SYS_CTRL_IPP_RST_N      23
#define BM_USDHC_SYS_CTRL_IPP_RST_N      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_IPP_RST_N(v)   ((((reg32_t) v) << 23) & BM_USDHC_SYS_CTRL_IPP_RST_N)
#else
#define BF_USDHC_SYS_CTRL_IPP_RST_N(v)   (((v) << 23) & BM_USDHC_SYS_CTRL_IPP_RST_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_IPP_RST_N(v)   BF_CS1(USDHC_SYS_CTRL, IPP_RST_N, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTA */

#define BP_USDHC_SYS_CTRL_RSTA      24
#define BM_USDHC_SYS_CTRL_RSTA      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTA(v)   ((((reg32_t) v) << 24) & BM_USDHC_SYS_CTRL_RSTA)
#else
#define BF_USDHC_SYS_CTRL_RSTA(v)   (((v) << 24) & BM_USDHC_SYS_CTRL_RSTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTA(v)   BF_CS1(USDHC_SYS_CTRL, RSTA, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTC */

#define BP_USDHC_SYS_CTRL_RSTC      25
#define BM_USDHC_SYS_CTRL_RSTC      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTC(v)   ((((reg32_t) v) << 25) & BM_USDHC_SYS_CTRL_RSTC)
#else
#define BF_USDHC_SYS_CTRL_RSTC(v)   (((v) << 25) & BM_USDHC_SYS_CTRL_RSTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTC(v)   BF_CS1(USDHC_SYS_CTRL, RSTC, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTD */

#define BP_USDHC_SYS_CTRL_RSTD      26
#define BM_USDHC_SYS_CTRL_RSTD      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTD(v)   ((((reg32_t) v) << 26) & BM_USDHC_SYS_CTRL_RSTD)
#else
#define BF_USDHC_SYS_CTRL_RSTD(v)   (((v) << 26) & BM_USDHC_SYS_CTRL_RSTD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTD(v)   BF_CS1(USDHC_SYS_CTRL, RSTD, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field INITA */

#define BP_USDHC_SYS_CTRL_INITA      27
#define BM_USDHC_SYS_CTRL_INITA      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_INITA(v)   ((((reg32_t) v) << 27) & BM_USDHC_SYS_CTRL_INITA)
#else
#define BF_USDHC_SYS_CTRL_INITA(v)   (((v) << 27) & BM_USDHC_SYS_CTRL_INITA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_INITA(v)   BF_CS1(USDHC_SYS_CTRL, INITA, v)
#endif

/*
 * HW_USDHC_INT_STATUS - Interrupt Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CC : 1;
        unsigned TC : 1;
        unsigned BGE : 1;
        unsigned DINT : 1;
        unsigned BWR : 1;
        unsigned BRR : 1;
        unsigned CINS : 1;
        unsigned CRM : 1;
        unsigned CINT : 1;
        unsigned RESERVED0 : 3;
        unsigned RTE : 1;
        unsigned RESERVED1 : 1;
        unsigned TP : 1;
        unsigned RESERVED2 : 1;
        unsigned CTOE : 1;
        unsigned CCE : 1;
        unsigned CEBE : 1;
        unsigned CIE : 1;
        unsigned DTOE : 1;
        unsigned DCE : 1;
        unsigned DEBE : 1;
        unsigned RESERVED3 : 1;
        unsigned AC12E : 1;
        unsigned RESERVED4 : 1;
        unsigned TNE : 1;
        unsigned RESERVED5 : 1;
        unsigned DMAE : 1;
        unsigned RESERVED6 : 3;

    } B;
} hw_usdhc_int_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_STATUS register
 */
#define HW_USDHC_INT_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_STATUS(x)           (*(volatile hw_usdhc_int_status_t *) HW_USDHC_INT_STATUS_ADDR(x))
#define HW_USDHC_INT_STATUS_RD(x)        (HW_USDHC_INT_STATUS(x).U)
#define HW_USDHC_INT_STATUS_WR(x, v)     (HW_USDHC_INT_STATUS(x).U = (v))
#define HW_USDHC_INT_STATUS_SET(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) |  (v)))
#define HW_USDHC_INT_STATUS_CLR(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) & ~(v)))
#define HW_USDHC_INT_STATUS_TOG(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_STATUS bitfields
 */

/* --- Register HW_USDHC_INT_STATUS, field CC */

#define BP_USDHC_INT_STATUS_CC      0
#define BM_USDHC_INT_STATUS_CC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CC(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_STATUS_CC)
#else
#define BF_USDHC_INT_STATUS_CC(v)   (((v) << 0) & BM_USDHC_INT_STATUS_CC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CC(v)   BF_CS1(USDHC_INT_STATUS, CC, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TC */

#define BP_USDHC_INT_STATUS_TC      1
#define BM_USDHC_INT_STATUS_TC      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TC(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_STATUS_TC)
#else
#define BF_USDHC_INT_STATUS_TC(v)   (((v) << 1) & BM_USDHC_INT_STATUS_TC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TC(v)   BF_CS1(USDHC_INT_STATUS, TC, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BGE */

#define BP_USDHC_INT_STATUS_BGE      2
#define BM_USDHC_INT_STATUS_BGE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BGE(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_STATUS_BGE)
#else
#define BF_USDHC_INT_STATUS_BGE(v)   (((v) << 2) & BM_USDHC_INT_STATUS_BGE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BGE(v)   BF_CS1(USDHC_INT_STATUS, BGE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DINT */

#define BP_USDHC_INT_STATUS_DINT      3
#define BM_USDHC_INT_STATUS_DINT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DINT(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_STATUS_DINT)
#else
#define BF_USDHC_INT_STATUS_DINT(v)   (((v) << 3) & BM_USDHC_INT_STATUS_DINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DINT(v)   BF_CS1(USDHC_INT_STATUS, DINT, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BWR */

#define BP_USDHC_INT_STATUS_BWR      4
#define BM_USDHC_INT_STATUS_BWR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BWR(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_STATUS_BWR)
#else
#define BF_USDHC_INT_STATUS_BWR(v)   (((v) << 4) & BM_USDHC_INT_STATUS_BWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BWR(v)   BF_CS1(USDHC_INT_STATUS, BWR, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BRR */

#define BP_USDHC_INT_STATUS_BRR      5
#define BM_USDHC_INT_STATUS_BRR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BRR(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_STATUS_BRR)
#else
#define BF_USDHC_INT_STATUS_BRR(v)   (((v) << 5) & BM_USDHC_INT_STATUS_BRR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BRR(v)   BF_CS1(USDHC_INT_STATUS, BRR, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CINS */

#define BP_USDHC_INT_STATUS_CINS      6
#define BM_USDHC_INT_STATUS_CINS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CINS(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_STATUS_CINS)
#else
#define BF_USDHC_INT_STATUS_CINS(v)   (((v) << 6) & BM_USDHC_INT_STATUS_CINS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CINS(v)   BF_CS1(USDHC_INT_STATUS, CINS, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CRM */

#define BP_USDHC_INT_STATUS_CRM      7
#define BM_USDHC_INT_STATUS_CRM      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CRM(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_STATUS_CRM)
#else
#define BF_USDHC_INT_STATUS_CRM(v)   (((v) << 7) & BM_USDHC_INT_STATUS_CRM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CRM(v)   BF_CS1(USDHC_INT_STATUS, CRM, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CINT */

#define BP_USDHC_INT_STATUS_CINT      8
#define BM_USDHC_INT_STATUS_CINT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CINT(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_STATUS_CINT)
#else
#define BF_USDHC_INT_STATUS_CINT(v)   (((v) << 8) & BM_USDHC_INT_STATUS_CINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CINT(v)   BF_CS1(USDHC_INT_STATUS, CINT, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field RTE */

#define BP_USDHC_INT_STATUS_RTE      12
#define BM_USDHC_INT_STATUS_RTE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_RTE(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_STATUS_RTE)
#else
#define BF_USDHC_INT_STATUS_RTE(v)   (((v) << 12) & BM_USDHC_INT_STATUS_RTE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_RTE(v)   BF_CS1(USDHC_INT_STATUS, RTE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TP */

#define BP_USDHC_INT_STATUS_TP      14
#define BM_USDHC_INT_STATUS_TP      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TP(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_STATUS_TP)
#else
#define BF_USDHC_INT_STATUS_TP(v)   (((v) << 14) & BM_USDHC_INT_STATUS_TP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TP(v)   BF_CS1(USDHC_INT_STATUS, TP, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CTOE */

#define BP_USDHC_INT_STATUS_CTOE      16
#define BM_USDHC_INT_STATUS_CTOE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CTOE(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_STATUS_CTOE)
#else
#define BF_USDHC_INT_STATUS_CTOE(v)   (((v) << 16) & BM_USDHC_INT_STATUS_CTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CTOE(v)   BF_CS1(USDHC_INT_STATUS, CTOE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CCE */

#define BP_USDHC_INT_STATUS_CCE      17
#define BM_USDHC_INT_STATUS_CCE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CCE(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_STATUS_CCE)
#else
#define BF_USDHC_INT_STATUS_CCE(v)   (((v) << 17) & BM_USDHC_INT_STATUS_CCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CCE(v)   BF_CS1(USDHC_INT_STATUS, CCE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CEBE */

#define BP_USDHC_INT_STATUS_CEBE      18
#define BM_USDHC_INT_STATUS_CEBE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CEBE(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_STATUS_CEBE)
#else
#define BF_USDHC_INT_STATUS_CEBE(v)   (((v) << 18) & BM_USDHC_INT_STATUS_CEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CEBE(v)   BF_CS1(USDHC_INT_STATUS, CEBE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CIE */

#define BP_USDHC_INT_STATUS_CIE      19
#define BM_USDHC_INT_STATUS_CIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CIE(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_STATUS_CIE)
#else
#define BF_USDHC_INT_STATUS_CIE(v)   (((v) << 19) & BM_USDHC_INT_STATUS_CIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CIE(v)   BF_CS1(USDHC_INT_STATUS, CIE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DTOE */

#define BP_USDHC_INT_STATUS_DTOE      20
#define BM_USDHC_INT_STATUS_DTOE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DTOE(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_STATUS_DTOE)
#else
#define BF_USDHC_INT_STATUS_DTOE(v)   (((v) << 20) & BM_USDHC_INT_STATUS_DTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DTOE(v)   BF_CS1(USDHC_INT_STATUS, DTOE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DCE */

#define BP_USDHC_INT_STATUS_DCE      21
#define BM_USDHC_INT_STATUS_DCE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DCE(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_STATUS_DCE)
#else
#define BF_USDHC_INT_STATUS_DCE(v)   (((v) << 21) & BM_USDHC_INT_STATUS_DCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DCE(v)   BF_CS1(USDHC_INT_STATUS, DCE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DEBE */

#define BP_USDHC_INT_STATUS_DEBE      22
#define BM_USDHC_INT_STATUS_DEBE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DEBE(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_STATUS_DEBE)
#else
#define BF_USDHC_INT_STATUS_DEBE(v)   (((v) << 22) & BM_USDHC_INT_STATUS_DEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DEBE(v)   BF_CS1(USDHC_INT_STATUS, DEBE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field AC12E */

#define BP_USDHC_INT_STATUS_AC12E      24
#define BM_USDHC_INT_STATUS_AC12E      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_AC12E(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_STATUS_AC12E)
#else
#define BF_USDHC_INT_STATUS_AC12E(v)   (((v) << 24) & BM_USDHC_INT_STATUS_AC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_AC12E(v)   BF_CS1(USDHC_INT_STATUS, AC12E, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TNE */

#define BP_USDHC_INT_STATUS_TNE      26
#define BM_USDHC_INT_STATUS_TNE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TNE(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_STATUS_TNE)
#else
#define BF_USDHC_INT_STATUS_TNE(v)   (((v) << 26) & BM_USDHC_INT_STATUS_TNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TNE(v)   BF_CS1(USDHC_INT_STATUS, TNE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DMAE */

#define BP_USDHC_INT_STATUS_DMAE      28
#define BM_USDHC_INT_STATUS_DMAE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DMAE(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_STATUS_DMAE)
#else
#define BF_USDHC_INT_STATUS_DMAE(v)   (((v) << 28) & BM_USDHC_INT_STATUS_DMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DMAE(v)   BF_CS1(USDHC_INT_STATUS, DMAE, v)
#endif

/*
 * HW_USDHC_INT_STATUS_EN - Interrupt Status Enable
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCSEN : 1;
        unsigned TCSEN : 1;
        unsigned BGESEN : 1;
        unsigned DINTSEN : 1;
        unsigned BWRSEN : 1;
        unsigned BRRSEN : 1;
        unsigned CINSSEN : 1;
        unsigned CRMSEN : 1;
        unsigned CINTSEN : 1;
        unsigned RESERVED0 : 3;
        unsigned RTESEN : 1;
        unsigned RESERVED1 : 1;
        unsigned TPSEN : 1;
        unsigned RESERVED2 : 1;
        unsigned CTOESEN : 1;
        unsigned CCESEN : 1;
        unsigned CEBESEN : 1;
        unsigned CIESEN : 1;
        unsigned DTOESEN : 1;
        unsigned DCESEN : 1;
        unsigned DEBESEN : 1;
        unsigned RESERVED3 : 1;
        unsigned AC12ESEN : 1;
        unsigned RESERVED4 : 1;
        unsigned TNESEN : 1;
        unsigned RESERVED5 : 1;
        unsigned DMAESEN : 1;
        unsigned RESERVED6 : 3;

    } B;
} hw_usdhc_int_status_en_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_STATUS_EN register
 */
#define HW_USDHC_INT_STATUS_EN_ADDR(x)      (REGS_USDHC_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_STATUS_EN(x)           (*(volatile hw_usdhc_int_status_en_t *) HW_USDHC_INT_STATUS_EN_ADDR(x))
#define HW_USDHC_INT_STATUS_EN_RD(x)        (HW_USDHC_INT_STATUS_EN(x).U)
#define HW_USDHC_INT_STATUS_EN_WR(x, v)     (HW_USDHC_INT_STATUS_EN(x).U = (v))
#define HW_USDHC_INT_STATUS_EN_SET(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) |  (v)))
#define HW_USDHC_INT_STATUS_EN_CLR(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) & ~(v)))
#define HW_USDHC_INT_STATUS_EN_TOG(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_STATUS_EN bitfields
 */

/* --- Register HW_USDHC_INT_STATUS_EN, field CCSEN */

#define BP_USDHC_INT_STATUS_EN_CCSEN      0
#define BM_USDHC_INT_STATUS_EN_CCSEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CCSEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_STATUS_EN_CCSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CCSEN(v)   (((v) << 0) & BM_USDHC_INT_STATUS_EN_CCSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CCSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CCSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TCSEN */

#define BP_USDHC_INT_STATUS_EN_TCSEN      1
#define BM_USDHC_INT_STATUS_EN_TCSEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TCSEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_STATUS_EN_TCSEN)
#else
#define BF_USDHC_INT_STATUS_EN_TCSEN(v)   (((v) << 1) & BM_USDHC_INT_STATUS_EN_TCSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TCSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TCSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BGESEN */

#define BP_USDHC_INT_STATUS_EN_BGESEN      2
#define BM_USDHC_INT_STATUS_EN_BGESEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BGESEN(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_STATUS_EN_BGESEN)
#else
#define BF_USDHC_INT_STATUS_EN_BGESEN(v)   (((v) << 2) & BM_USDHC_INT_STATUS_EN_BGESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BGESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BGESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DINTSEN */

#define BP_USDHC_INT_STATUS_EN_DINTSEN      3
#define BM_USDHC_INT_STATUS_EN_DINTSEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DINTSEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_STATUS_EN_DINTSEN)
#else
#define BF_USDHC_INT_STATUS_EN_DINTSEN(v)   (((v) << 3) & BM_USDHC_INT_STATUS_EN_DINTSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DINTSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DINTSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BWRSEN */

#define BP_USDHC_INT_STATUS_EN_BWRSEN      4
#define BM_USDHC_INT_STATUS_EN_BWRSEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BWRSEN(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_STATUS_EN_BWRSEN)
#else
#define BF_USDHC_INT_STATUS_EN_BWRSEN(v)   (((v) << 4) & BM_USDHC_INT_STATUS_EN_BWRSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BWRSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BWRSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BRRSEN */

#define BP_USDHC_INT_STATUS_EN_BRRSEN      5
#define BM_USDHC_INT_STATUS_EN_BRRSEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BRRSEN(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_STATUS_EN_BRRSEN)
#else
#define BF_USDHC_INT_STATUS_EN_BRRSEN(v)   (((v) << 5) & BM_USDHC_INT_STATUS_EN_BRRSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BRRSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BRRSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CINSSEN */

#define BP_USDHC_INT_STATUS_EN_CINSSEN      6
#define BM_USDHC_INT_STATUS_EN_CINSSEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CINSSEN(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_STATUS_EN_CINSSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CINSSEN(v)   (((v) << 6) & BM_USDHC_INT_STATUS_EN_CINSSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CINSSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CINSSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CRMSEN */

#define BP_USDHC_INT_STATUS_EN_CRMSEN      7
#define BM_USDHC_INT_STATUS_EN_CRMSEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CRMSEN(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_STATUS_EN_CRMSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CRMSEN(v)   (((v) << 7) & BM_USDHC_INT_STATUS_EN_CRMSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CRMSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CRMSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CINTSEN */

#define BP_USDHC_INT_STATUS_EN_CINTSEN      8
#define BM_USDHC_INT_STATUS_EN_CINTSEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CINTSEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_STATUS_EN_CINTSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CINTSEN(v)   (((v) << 8) & BM_USDHC_INT_STATUS_EN_CINTSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CINTSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CINTSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field RTESEN */

#define BP_USDHC_INT_STATUS_EN_RTESEN      12
#define BM_USDHC_INT_STATUS_EN_RTESEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_RTESEN(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_STATUS_EN_RTESEN)
#else
#define BF_USDHC_INT_STATUS_EN_RTESEN(v)   (((v) << 12) & BM_USDHC_INT_STATUS_EN_RTESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_RTESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, RTESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TPSEN */

#define BP_USDHC_INT_STATUS_EN_TPSEN      14
#define BM_USDHC_INT_STATUS_EN_TPSEN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TPSEN(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_STATUS_EN_TPSEN)
#else
#define BF_USDHC_INT_STATUS_EN_TPSEN(v)   (((v) << 14) & BM_USDHC_INT_STATUS_EN_TPSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TPSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TPSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CTOESEN */

#define BP_USDHC_INT_STATUS_EN_CTOESEN      16
#define BM_USDHC_INT_STATUS_EN_CTOESEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CTOESEN(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_STATUS_EN_CTOESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CTOESEN(v)   (((v) << 16) & BM_USDHC_INT_STATUS_EN_CTOESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CTOESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CTOESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CCESEN */

#define BP_USDHC_INT_STATUS_EN_CCESEN      17
#define BM_USDHC_INT_STATUS_EN_CCESEN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CCESEN(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_STATUS_EN_CCESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CCESEN(v)   (((v) << 17) & BM_USDHC_INT_STATUS_EN_CCESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CCESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CCESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CEBESEN */

#define BP_USDHC_INT_STATUS_EN_CEBESEN      18
#define BM_USDHC_INT_STATUS_EN_CEBESEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CEBESEN(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_STATUS_EN_CEBESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CEBESEN(v)   (((v) << 18) & BM_USDHC_INT_STATUS_EN_CEBESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CEBESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CEBESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CIESEN */

#define BP_USDHC_INT_STATUS_EN_CIESEN      19
#define BM_USDHC_INT_STATUS_EN_CIESEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CIESEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_STATUS_EN_CIESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CIESEN(v)   (((v) << 19) & BM_USDHC_INT_STATUS_EN_CIESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CIESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CIESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DTOESEN */

#define BP_USDHC_INT_STATUS_EN_DTOESEN      20
#define BM_USDHC_INT_STATUS_EN_DTOESEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DTOESEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_STATUS_EN_DTOESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DTOESEN(v)   (((v) << 20) & BM_USDHC_INT_STATUS_EN_DTOESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DTOESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DTOESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DCESEN */

#define BP_USDHC_INT_STATUS_EN_DCESEN      21
#define BM_USDHC_INT_STATUS_EN_DCESEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DCESEN(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_STATUS_EN_DCESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DCESEN(v)   (((v) << 21) & BM_USDHC_INT_STATUS_EN_DCESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DCESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DCESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DEBESEN */

#define BP_USDHC_INT_STATUS_EN_DEBESEN      22
#define BM_USDHC_INT_STATUS_EN_DEBESEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DEBESEN(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_STATUS_EN_DEBESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DEBESEN(v)   (((v) << 22) & BM_USDHC_INT_STATUS_EN_DEBESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DEBESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DEBESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field AC12ESEN */

#define BP_USDHC_INT_STATUS_EN_AC12ESEN      24
#define BM_USDHC_INT_STATUS_EN_AC12ESEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_AC12ESEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_STATUS_EN_AC12ESEN)
#else
#define BF_USDHC_INT_STATUS_EN_AC12ESEN(v)   (((v) << 24) & BM_USDHC_INT_STATUS_EN_AC12ESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_AC12ESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, AC12ESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TNESEN */

#define BP_USDHC_INT_STATUS_EN_TNESEN      26
#define BM_USDHC_INT_STATUS_EN_TNESEN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TNESEN(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_STATUS_EN_TNESEN)
#else
#define BF_USDHC_INT_STATUS_EN_TNESEN(v)   (((v) << 26) & BM_USDHC_INT_STATUS_EN_TNESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TNESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TNESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DMAESEN */

#define BP_USDHC_INT_STATUS_EN_DMAESEN      28
#define BM_USDHC_INT_STATUS_EN_DMAESEN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DMAESEN(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_STATUS_EN_DMAESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DMAESEN(v)   (((v) << 28) & BM_USDHC_INT_STATUS_EN_DMAESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DMAESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DMAESEN, v)
#endif

/*
 * HW_USDHC_INT_SIGNAL_EN - Interrupt Signal Enable
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCIEN : 1;
        unsigned TCIEN : 1;
        unsigned BGEIEN : 1;
        unsigned DINTIEN : 1;
        unsigned BWRIEN : 1;
        unsigned BRRIEN : 1;
        unsigned CINSIEN : 1;
        unsigned CRMIEN : 1;
        unsigned CINTIEN : 1;
        unsigned RESERVED0 : 3;
        unsigned RTEIEN : 1;
        unsigned RESERVED1 : 1;
        unsigned TPIEN : 1;
        unsigned RESERVED2 : 1;
        unsigned CTOEIEN : 1;
        unsigned CCEIEN : 1;
        unsigned CEBEIEN : 1;
        unsigned CIEIEN : 1;
        unsigned DTOEIEN : 1;
        unsigned DCEIEN : 1;
        unsigned DEBEIEN : 1;
        unsigned RESERVED3 : 1;
        unsigned AC12EIEN : 1;
        unsigned RESERVED4 : 1;
        unsigned TNEIEN : 1;
        unsigned RESERVED5 : 1;
        unsigned DMAEIEN : 1;
        unsigned RESERVED6 : 3;

    } B;
} hw_usdhc_int_signal_en_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_SIGNAL_EN register
 */
#define HW_USDHC_INT_SIGNAL_EN_ADDR(x)      (REGS_USDHC_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_SIGNAL_EN(x)           (*(volatile hw_usdhc_int_signal_en_t *) HW_USDHC_INT_SIGNAL_EN_ADDR(x))
#define HW_USDHC_INT_SIGNAL_EN_RD(x)        (HW_USDHC_INT_SIGNAL_EN(x).U)
#define HW_USDHC_INT_SIGNAL_EN_WR(x, v)     (HW_USDHC_INT_SIGNAL_EN(x).U = (v))
#define HW_USDHC_INT_SIGNAL_EN_SET(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) |  (v)))
#define HW_USDHC_INT_SIGNAL_EN_CLR(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) & ~(v)))
#define HW_USDHC_INT_SIGNAL_EN_TOG(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_SIGNAL_EN bitfields
 */

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CCIEN */

#define BP_USDHC_INT_SIGNAL_EN_CCIEN      0
#define BM_USDHC_INT_SIGNAL_EN_CCIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CCIEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_SIGNAL_EN_CCIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CCIEN(v)   (((v) << 0) & BM_USDHC_INT_SIGNAL_EN_CCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CCIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CCIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TCIEN */

#define BP_USDHC_INT_SIGNAL_EN_TCIEN      1
#define BM_USDHC_INT_SIGNAL_EN_TCIEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TCIEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_SIGNAL_EN_TCIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TCIEN(v)   (((v) << 1) & BM_USDHC_INT_SIGNAL_EN_TCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TCIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TCIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BGEIEN */

#define BP_USDHC_INT_SIGNAL_EN_BGEIEN      2
#define BM_USDHC_INT_SIGNAL_EN_BGEIEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BGEIEN(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_SIGNAL_EN_BGEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BGEIEN(v)   (((v) << 2) & BM_USDHC_INT_SIGNAL_EN_BGEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BGEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BGEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DINTIEN */

#define BP_USDHC_INT_SIGNAL_EN_DINTIEN      3
#define BM_USDHC_INT_SIGNAL_EN_DINTIEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DINTIEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_SIGNAL_EN_DINTIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DINTIEN(v)   (((v) << 3) & BM_USDHC_INT_SIGNAL_EN_DINTIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DINTIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DINTIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BWRIEN */

#define BP_USDHC_INT_SIGNAL_EN_BWRIEN      4
#define BM_USDHC_INT_SIGNAL_EN_BWRIEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BWRIEN(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_SIGNAL_EN_BWRIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BWRIEN(v)   (((v) << 4) & BM_USDHC_INT_SIGNAL_EN_BWRIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BWRIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BWRIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BRRIEN */

#define BP_USDHC_INT_SIGNAL_EN_BRRIEN      5
#define BM_USDHC_INT_SIGNAL_EN_BRRIEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BRRIEN(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_SIGNAL_EN_BRRIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BRRIEN(v)   (((v) << 5) & BM_USDHC_INT_SIGNAL_EN_BRRIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BRRIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BRRIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CINSIEN */

#define BP_USDHC_INT_SIGNAL_EN_CINSIEN      6
#define BM_USDHC_INT_SIGNAL_EN_CINSIEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CINSIEN(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_SIGNAL_EN_CINSIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CINSIEN(v)   (((v) << 6) & BM_USDHC_INT_SIGNAL_EN_CINSIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CINSIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CINSIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CRMIEN */

#define BP_USDHC_INT_SIGNAL_EN_CRMIEN      7
#define BM_USDHC_INT_SIGNAL_EN_CRMIEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CRMIEN(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_SIGNAL_EN_CRMIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CRMIEN(v)   (((v) << 7) & BM_USDHC_INT_SIGNAL_EN_CRMIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CRMIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CRMIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CINTIEN */

#define BP_USDHC_INT_SIGNAL_EN_CINTIEN      8
#define BM_USDHC_INT_SIGNAL_EN_CINTIEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CINTIEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_SIGNAL_EN_CINTIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CINTIEN(v)   (((v) << 8) & BM_USDHC_INT_SIGNAL_EN_CINTIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CINTIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CINTIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field RTEIEN */

#define BP_USDHC_INT_SIGNAL_EN_RTEIEN      12
#define BM_USDHC_INT_SIGNAL_EN_RTEIEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_RTEIEN(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_SIGNAL_EN_RTEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_RTEIEN(v)   (((v) << 12) & BM_USDHC_INT_SIGNAL_EN_RTEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_RTEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, RTEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TPIEN */

#define BP_USDHC_INT_SIGNAL_EN_TPIEN      14
#define BM_USDHC_INT_SIGNAL_EN_TPIEN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TPIEN(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_SIGNAL_EN_TPIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TPIEN(v)   (((v) << 14) & BM_USDHC_INT_SIGNAL_EN_TPIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TPIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TPIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CTOEIEN */

#define BP_USDHC_INT_SIGNAL_EN_CTOEIEN      16
#define BM_USDHC_INT_SIGNAL_EN_CTOEIEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_SIGNAL_EN_CTOEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   (((v) << 16) & BM_USDHC_INT_SIGNAL_EN_CTOEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CTOEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CCEIEN */

#define BP_USDHC_INT_SIGNAL_EN_CCEIEN      17
#define BM_USDHC_INT_SIGNAL_EN_CCEIEN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CCEIEN(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_SIGNAL_EN_CCEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CCEIEN(v)   (((v) << 17) & BM_USDHC_INT_SIGNAL_EN_CCEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CCEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CCEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CEBEIEN */

#define BP_USDHC_INT_SIGNAL_EN_CEBEIEN      18
#define BM_USDHC_INT_SIGNAL_EN_CEBEIEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_SIGNAL_EN_CEBEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   (((v) << 18) & BM_USDHC_INT_SIGNAL_EN_CEBEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CEBEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CIEIEN */

#define BP_USDHC_INT_SIGNAL_EN_CIEIEN      19
#define BM_USDHC_INT_SIGNAL_EN_CIEIEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CIEIEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_SIGNAL_EN_CIEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CIEIEN(v)   (((v) << 19) & BM_USDHC_INT_SIGNAL_EN_CIEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CIEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CIEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DTOEIEN */

#define BP_USDHC_INT_SIGNAL_EN_DTOEIEN      20
#define BM_USDHC_INT_SIGNAL_EN_DTOEIEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_SIGNAL_EN_DTOEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   (((v) << 20) & BM_USDHC_INT_SIGNAL_EN_DTOEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DTOEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DCEIEN */

#define BP_USDHC_INT_SIGNAL_EN_DCEIEN      21
#define BM_USDHC_INT_SIGNAL_EN_DCEIEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DCEIEN(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_SIGNAL_EN_DCEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DCEIEN(v)   (((v) << 21) & BM_USDHC_INT_SIGNAL_EN_DCEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DCEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DCEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DEBEIEN */

#define BP_USDHC_INT_SIGNAL_EN_DEBEIEN      22
#define BM_USDHC_INT_SIGNAL_EN_DEBEIEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_SIGNAL_EN_DEBEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   (((v) << 22) & BM_USDHC_INT_SIGNAL_EN_DEBEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DEBEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field AC12EIEN */

#define BP_USDHC_INT_SIGNAL_EN_AC12EIEN      24
#define BM_USDHC_INT_SIGNAL_EN_AC12EIEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_SIGNAL_EN_AC12EIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   (((v) << 24) & BM_USDHC_INT_SIGNAL_EN_AC12EIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, AC12EIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TNEIEN */

#define BP_USDHC_INT_SIGNAL_EN_TNEIEN      26
#define BM_USDHC_INT_SIGNAL_EN_TNEIEN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TNEIEN(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_SIGNAL_EN_TNEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TNEIEN(v)   (((v) << 26) & BM_USDHC_INT_SIGNAL_EN_TNEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TNEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TNEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DMAEIEN */

#define BP_USDHC_INT_SIGNAL_EN_DMAEIEN      28
#define BM_USDHC_INT_SIGNAL_EN_DMAEIEN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_SIGNAL_EN_DMAEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   (((v) << 28) & BM_USDHC_INT_SIGNAL_EN_DMAEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DMAEIEN, v)
#endif

/*
 * HW_USDHC_AUTOCMD12_ERR_STATUS - Auto CMD12 Error Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AC12NE : 1;
        unsigned AC12TOE : 1;
        unsigned AC12EBE : 1;
        unsigned AC12CE : 1;
        unsigned AC12IE : 1;
        unsigned RESERVED0 : 2;
        unsigned CNIBAC12E : 1;
        unsigned RESERVED1 : 24;

    } B;
} hw_usdhc_autocmd12_err_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_AUTOCMD12_ERR_STATUS register
 */
#define HW_USDHC_AUTOCMD12_ERR_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_AUTOCMD12_ERR_STATUS(x)           (*(volatile hw_usdhc_autocmd12_err_status_t *) HW_USDHC_AUTOCMD12_ERR_STATUS_ADDR(x))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x)        (HW_USDHC_AUTOCMD12_ERR_STATUS(x).U)
#define HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, v)     (HW_USDHC_AUTOCMD12_ERR_STATUS(x).U = (v))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_SET(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) |  (v)))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_CLR(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) & ~(v)))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_TOG(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_AUTOCMD12_ERR_STATUS bitfields
 */

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12NE */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12NE      0
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   ((((reg32_t) v) << 0) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   (((v) << 0) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12NE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12TOE */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE      1
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   ((((reg32_t) v) << 1) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   (((v) << 1) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12TOE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12EBE */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE      2
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   ((((reg32_t) v) << 2) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   (((v) << 2) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12EBE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12CE */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12CE      3
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   ((((reg32_t) v) << 3) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   (((v) << 3) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12CE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12IE */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12IE      4
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   ((((reg32_t) v) << 4) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   (((v) << 4) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12IE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field CNIBAC12E */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E      7
#define BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   ((((reg32_t) v) << 7) & BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   (((v) << 7) & BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, CNIBAC12E, v)
#endif

/*
 * HW_USDHC_HOST_CTRL_CAP - Host Controller Capabilities
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned MBL : 3;
        unsigned RESERVED1 : 1;
        unsigned ADMAS : 1;
        unsigned HSS : 1;
        unsigned DMAS : 1;
        unsigned SRS : 1;
        unsigned VS33 : 1;
        unsigned VS30 : 1;
        unsigned VS18 : 1;
        unsigned RESERVED2 : 5;

    } B;
} hw_usdhc_host_ctrl_cap_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_HOST_CTRL_CAP register
 */
#define HW_USDHC_HOST_CTRL_CAP_ADDR(x)      (REGS_USDHC_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_HOST_CTRL_CAP(x)           (*(volatile hw_usdhc_host_ctrl_cap_t *) HW_USDHC_HOST_CTRL_CAP_ADDR(x))
#define HW_USDHC_HOST_CTRL_CAP_RD(x)        (HW_USDHC_HOST_CTRL_CAP(x).U)
#define HW_USDHC_HOST_CTRL_CAP_WR(x, v)     (HW_USDHC_HOST_CTRL_CAP(x).U = (v))
#define HW_USDHC_HOST_CTRL_CAP_SET(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) |  (v)))
#define HW_USDHC_HOST_CTRL_CAP_CLR(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) & ~(v)))
#define HW_USDHC_HOST_CTRL_CAP_TOG(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_HOST_CTRL_CAP bitfields
 */

/* --- Register HW_USDHC_HOST_CTRL_CAP, field MBL */

#define BP_USDHC_HOST_CTRL_CAP_MBL      16
#define BM_USDHC_HOST_CTRL_CAP_MBL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_MBL(v)   ((((reg32_t) v) << 16) & BM_USDHC_HOST_CTRL_CAP_MBL)
#else
#define BF_USDHC_HOST_CTRL_CAP_MBL(v)   (((v) << 16) & BM_USDHC_HOST_CTRL_CAP_MBL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_MBL(v)   BF_CS1(USDHC_HOST_CTRL_CAP, MBL, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field ADMAS */

#define BP_USDHC_HOST_CTRL_CAP_ADMAS      20
#define BM_USDHC_HOST_CTRL_CAP_ADMAS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_ADMAS(v)   ((((reg32_t) v) << 20) & BM_USDHC_HOST_CTRL_CAP_ADMAS)
#else
#define BF_USDHC_HOST_CTRL_CAP_ADMAS(v)   (((v) << 20) & BM_USDHC_HOST_CTRL_CAP_ADMAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_ADMAS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, ADMAS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field HSS */

#define BP_USDHC_HOST_CTRL_CAP_HSS      21
#define BM_USDHC_HOST_CTRL_CAP_HSS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_HSS(v)   ((((reg32_t) v) << 21) & BM_USDHC_HOST_CTRL_CAP_HSS)
#else
#define BF_USDHC_HOST_CTRL_CAP_HSS(v)   (((v) << 21) & BM_USDHC_HOST_CTRL_CAP_HSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_HSS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, HSS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field DMAS */

#define BP_USDHC_HOST_CTRL_CAP_DMAS      22
#define BM_USDHC_HOST_CTRL_CAP_DMAS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_DMAS(v)   ((((reg32_t) v) << 22) & BM_USDHC_HOST_CTRL_CAP_DMAS)
#else
#define BF_USDHC_HOST_CTRL_CAP_DMAS(v)   (((v) << 22) & BM_USDHC_HOST_CTRL_CAP_DMAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_DMAS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, DMAS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field SRS */

#define BP_USDHC_HOST_CTRL_CAP_SRS      23
#define BM_USDHC_HOST_CTRL_CAP_SRS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_SRS(v)   ((((reg32_t) v) << 23) & BM_USDHC_HOST_CTRL_CAP_SRS)
#else
#define BF_USDHC_HOST_CTRL_CAP_SRS(v)   (((v) << 23) & BM_USDHC_HOST_CTRL_CAP_SRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_SRS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, SRS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS33 */

#define BP_USDHC_HOST_CTRL_CAP_VS33      24
#define BM_USDHC_HOST_CTRL_CAP_VS33      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS33(v)   ((((reg32_t) v) << 24) & BM_USDHC_HOST_CTRL_CAP_VS33)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS33(v)   (((v) << 24) & BM_USDHC_HOST_CTRL_CAP_VS33)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS33(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS33, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS30 */

#define BP_USDHC_HOST_CTRL_CAP_VS30      25
#define BM_USDHC_HOST_CTRL_CAP_VS30      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS30(v)   ((((reg32_t) v) << 25) & BM_USDHC_HOST_CTRL_CAP_VS30)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS30(v)   (((v) << 25) & BM_USDHC_HOST_CTRL_CAP_VS30)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS30(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS30, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS18 */

#define BP_USDHC_HOST_CTRL_CAP_VS18      26
#define BM_USDHC_HOST_CTRL_CAP_VS18      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS18(v)   ((((reg32_t) v) << 26) & BM_USDHC_HOST_CTRL_CAP_VS18)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS18(v)   (((v) << 26) & BM_USDHC_HOST_CTRL_CAP_VS18)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS18(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS18, v)
#endif

/*
 * HW_USDHC_WTMK_LVL - Watermark Level
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_WML : 8;
        unsigned RD_BRST_LEN : 5;
        unsigned RESERVED0 : 3;
        unsigned WR_WML : 8;
        unsigned WR_BRST_LEN : 5;
        unsigned RESERVED1 : 3;

    } B;
} hw_usdhc_wtmk_lvl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_WTMK_LVL register
 */
#define HW_USDHC_WTMK_LVL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_WTMK_LVL(x)           (*(volatile hw_usdhc_wtmk_lvl_t *) HW_USDHC_WTMK_LVL_ADDR(x))
#define HW_USDHC_WTMK_LVL_RD(x)        (HW_USDHC_WTMK_LVL(x).U)
#define HW_USDHC_WTMK_LVL_WR(x, v)     (HW_USDHC_WTMK_LVL(x).U = (v))
#define HW_USDHC_WTMK_LVL_SET(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) |  (v)))
#define HW_USDHC_WTMK_LVL_CLR(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) & ~(v)))
#define HW_USDHC_WTMK_LVL_TOG(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_WTMK_LVL bitfields
 */

/* --- Register HW_USDHC_WTMK_LVL, field RD_WML */

#define BP_USDHC_WTMK_LVL_RD_WML      0
#define BM_USDHC_WTMK_LVL_RD_WML      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_RD_WML(v)   ((((reg32_t) v) << 0) & BM_USDHC_WTMK_LVL_RD_WML)
#else
#define BF_USDHC_WTMK_LVL_RD_WML(v)   (((v) << 0) & BM_USDHC_WTMK_LVL_RD_WML)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_RD_WML(v)   BF_CS1(USDHC_WTMK_LVL, RD_WML, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field RD_BRST_LEN */

#define BP_USDHC_WTMK_LVL_RD_BRST_LEN      8
#define BM_USDHC_WTMK_LVL_RD_BRST_LEN      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_RD_BRST_LEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_WTMK_LVL_RD_BRST_LEN)
#else
#define BF_USDHC_WTMK_LVL_RD_BRST_LEN(v)   (((v) << 8) & BM_USDHC_WTMK_LVL_RD_BRST_LEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_RD_BRST_LEN(v)   BF_CS1(USDHC_WTMK_LVL, RD_BRST_LEN, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field WR_WML */

#define BP_USDHC_WTMK_LVL_WR_WML      16
#define BM_USDHC_WTMK_LVL_WR_WML      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_WR_WML(v)   ((((reg32_t) v) << 16) & BM_USDHC_WTMK_LVL_WR_WML)
#else
#define BF_USDHC_WTMK_LVL_WR_WML(v)   (((v) << 16) & BM_USDHC_WTMK_LVL_WR_WML)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_WR_WML(v)   BF_CS1(USDHC_WTMK_LVL, WR_WML, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field WR_BRST_LEN */

#define BP_USDHC_WTMK_LVL_WR_BRST_LEN      24
#define BM_USDHC_WTMK_LVL_WR_BRST_LEN      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_WR_BRST_LEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_WTMK_LVL_WR_BRST_LEN)
#else
#define BF_USDHC_WTMK_LVL_WR_BRST_LEN(v)   (((v) << 24) & BM_USDHC_WTMK_LVL_WR_BRST_LEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_WR_BRST_LEN(v)   BF_CS1(USDHC_WTMK_LVL, WR_BRST_LEN, v)
#endif

/*
 * HW_USDHC_MIX_CTRL - Mixer Control
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DMAEN : 1;
        unsigned BCEN : 1;
        unsigned AC12EN : 1;
        unsigned DDR_EN : 1;
        unsigned DTDSEL : 1;
        unsigned MSBSEL : 1;
        unsigned NIBBLE_POS : 1;
        unsigned AC23EN : 1;
        unsigned RESERVED0 : 14;
        unsigned EXE_TUNE : 1;
        unsigned SMP_CLK_SEL : 1;
        unsigned AUTO_TUNE_EN : 1;
        unsigned FBCLK_SEL : 1;
        unsigned RESERVED1 : 3;
        unsigned AC12_RD_POINT : 1;
        unsigned CMD_DMY_WAIT_CFG : 1;
        unsigned CMD_DMY_EN : 1;

    } B;
} hw_usdhc_mix_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_MIX_CTRL register
 */
#define HW_USDHC_MIX_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_MIX_CTRL(x)           (*(volatile hw_usdhc_mix_ctrl_t *) HW_USDHC_MIX_CTRL_ADDR(x))
#define HW_USDHC_MIX_CTRL_RD(x)        (HW_USDHC_MIX_CTRL(x).U)
#define HW_USDHC_MIX_CTRL_WR(x, v)     (HW_USDHC_MIX_CTRL(x).U = (v))
#define HW_USDHC_MIX_CTRL_SET(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) |  (v)))
#define HW_USDHC_MIX_CTRL_CLR(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) & ~(v)))
#define HW_USDHC_MIX_CTRL_TOG(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_MIX_CTRL bitfields
 */

/* --- Register HW_USDHC_MIX_CTRL, field DMAEN */

#define BP_USDHC_MIX_CTRL_DMAEN      0
#define BM_USDHC_MIX_CTRL_DMAEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DMAEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_MIX_CTRL_DMAEN)
#else
#define BF_USDHC_MIX_CTRL_DMAEN(v)   (((v) << 0) & BM_USDHC_MIX_CTRL_DMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DMAEN(v)   BF_CS1(USDHC_MIX_CTRL, DMAEN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field BCEN */

#define BP_USDHC_MIX_CTRL_BCEN      1
#define BM_USDHC_MIX_CTRL_BCEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_BCEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_MIX_CTRL_BCEN)
#else
#define BF_USDHC_MIX_CTRL_BCEN(v)   (((v) << 1) & BM_USDHC_MIX_CTRL_BCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_BCEN(v)   BF_CS1(USDHC_MIX_CTRL, BCEN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC12EN */

#define BP_USDHC_MIX_CTRL_AC12EN      2
#define BM_USDHC_MIX_CTRL_AC12EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC12EN(v)   ((((reg32_t) v) << 2) & BM_USDHC_MIX_CTRL_AC12EN)
#else
#define BF_USDHC_MIX_CTRL_AC12EN(v)   (((v) << 2) & BM_USDHC_MIX_CTRL_AC12EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC12EN(v)   BF_CS1(USDHC_MIX_CTRL, AC12EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field DDR_EN */

#define BP_USDHC_MIX_CTRL_DDR_EN      3
#define BM_USDHC_MIX_CTRL_DDR_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DDR_EN(v)   ((((reg32_t) v) << 3) & BM_USDHC_MIX_CTRL_DDR_EN)
#else
#define BF_USDHC_MIX_CTRL_DDR_EN(v)   (((v) << 3) & BM_USDHC_MIX_CTRL_DDR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DDR_EN(v)   BF_CS1(USDHC_MIX_CTRL, DDR_EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field DTDSEL */

#define BP_USDHC_MIX_CTRL_DTDSEL      4
#define BM_USDHC_MIX_CTRL_DTDSEL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DTDSEL(v)   ((((reg32_t) v) << 4) & BM_USDHC_MIX_CTRL_DTDSEL)
#else
#define BF_USDHC_MIX_CTRL_DTDSEL(v)   (((v) << 4) & BM_USDHC_MIX_CTRL_DTDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DTDSEL(v)   BF_CS1(USDHC_MIX_CTRL, DTDSEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field MSBSEL */

#define BP_USDHC_MIX_CTRL_MSBSEL      5
#define BM_USDHC_MIX_CTRL_MSBSEL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_MSBSEL(v)   ((((reg32_t) v) << 5) & BM_USDHC_MIX_CTRL_MSBSEL)
#else
#define BF_USDHC_MIX_CTRL_MSBSEL(v)   (((v) << 5) & BM_USDHC_MIX_CTRL_MSBSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_MSBSEL(v)   BF_CS1(USDHC_MIX_CTRL, MSBSEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field NIBBLE_POS */

#define BP_USDHC_MIX_CTRL_NIBBLE_POS      6
#define BM_USDHC_MIX_CTRL_NIBBLE_POS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_NIBBLE_POS(v)   ((((reg32_t) v) << 6) & BM_USDHC_MIX_CTRL_NIBBLE_POS)
#else
#define BF_USDHC_MIX_CTRL_NIBBLE_POS(v)   (((v) << 6) & BM_USDHC_MIX_CTRL_NIBBLE_POS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_NIBBLE_POS(v)   BF_CS1(USDHC_MIX_CTRL, NIBBLE_POS, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC23EN */

#define BP_USDHC_MIX_CTRL_AC23EN      7
#define BM_USDHC_MIX_CTRL_AC23EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC23EN(v)   ((((reg32_t) v) << 7) & BM_USDHC_MIX_CTRL_AC23EN)
#else
#define BF_USDHC_MIX_CTRL_AC23EN(v)   (((v) << 7) & BM_USDHC_MIX_CTRL_AC23EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC23EN(v)   BF_CS1(USDHC_MIX_CTRL, AC23EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field EXE_TUNE */

#define BP_USDHC_MIX_CTRL_EXE_TUNE      22
#define BM_USDHC_MIX_CTRL_EXE_TUNE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_EXE_TUNE(v)   ((((reg32_t) v) << 22) & BM_USDHC_MIX_CTRL_EXE_TUNE)
#else
#define BF_USDHC_MIX_CTRL_EXE_TUNE(v)   (((v) << 22) & BM_USDHC_MIX_CTRL_EXE_TUNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_EXE_TUNE(v)   BF_CS1(USDHC_MIX_CTRL, EXE_TUNE, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field SMP_CLK_SEL */

#define BP_USDHC_MIX_CTRL_SMP_CLK_SEL      23
#define BM_USDHC_MIX_CTRL_SMP_CLK_SEL      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   ((((reg32_t) v) << 23) & BM_USDHC_MIX_CTRL_SMP_CLK_SEL)
#else
#define BF_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   (((v) << 23) & BM_USDHC_MIX_CTRL_SMP_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   BF_CS1(USDHC_MIX_CTRL, SMP_CLK_SEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AUTO_TUNE_EN */

#define BP_USDHC_MIX_CTRL_AUTO_TUNE_EN      24
#define BM_USDHC_MIX_CTRL_AUTO_TUNE_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   ((((reg32_t) v) << 24) & BM_USDHC_MIX_CTRL_AUTO_TUNE_EN)
#else
#define BF_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   (((v) << 24) & BM_USDHC_MIX_CTRL_AUTO_TUNE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   BF_CS1(USDHC_MIX_CTRL, AUTO_TUNE_EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field FBCLK_SEL */

#define BP_USDHC_MIX_CTRL_FBCLK_SEL      25
#define BM_USDHC_MIX_CTRL_FBCLK_SEL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_FBCLK_SEL(v)   ((((reg32_t) v) << 25) & BM_USDHC_MIX_CTRL_FBCLK_SEL)
#else
#define BF_USDHC_MIX_CTRL_FBCLK_SEL(v)   (((v) << 25) & BM_USDHC_MIX_CTRL_FBCLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_FBCLK_SEL(v)   BF_CS1(USDHC_MIX_CTRL, FBCLK_SEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC12_RD_POINT */

#define BP_USDHC_MIX_CTRL_AC12_RD_POINT      29
#define BM_USDHC_MIX_CTRL_AC12_RD_POINT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC12_RD_POINT(v)   ((((reg32_t) v) << 29) & BM_USDHC_MIX_CTRL_AC12_RD_POINT)
#else
#define BF_USDHC_MIX_CTRL_AC12_RD_POINT(v)   (((v) << 29) & BM_USDHC_MIX_CTRL_AC12_RD_POINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC12_RD_POINT(v)   BF_CS1(USDHC_MIX_CTRL, AC12_RD_POINT, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field CMD_DMY_WAIT_CFG */

#define BP_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG      30
#define BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   ((((reg32_t) v) << 30) & BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG)
#else
#define BF_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   (((v) << 30) & BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   BF_CS1(USDHC_MIX_CTRL, CMD_DMY_WAIT_CFG, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field CMD_DMY_EN */

#define BP_USDHC_MIX_CTRL_CMD_DMY_EN      31
#define BM_USDHC_MIX_CTRL_CMD_DMY_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_CMD_DMY_EN(v)   ((((reg32_t) v) << 31) & BM_USDHC_MIX_CTRL_CMD_DMY_EN)
#else
#define BF_USDHC_MIX_CTRL_CMD_DMY_EN(v)   (((v) << 31) & BM_USDHC_MIX_CTRL_CMD_DMY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_CMD_DMY_EN(v)   BF_CS1(USDHC_MIX_CTRL, CMD_DMY_EN, v)
#endif

/*
 * HW_USDHC_FORCE_EVENT - Force Event
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FEVTAC12NE : 1;
        unsigned FEVTAC12TOE : 1;
        unsigned FEVTAC12CE : 1;
        unsigned FEVTAC12EBE : 1;
        unsigned FEVTAC12IE : 1;
        unsigned RESERVED0 : 2;
        unsigned FEVTCNIBAC12E : 1;
        unsigned RESERVED1 : 8;
        unsigned FEVTCCE : 1;
        unsigned FEVTCCE : 1;
        unsigned FEVTCEBE : 1;
        unsigned FEVTCIE : 1;
        unsigned FEVTDTOE : 1;
        unsigned FEVTDCE : 1;
        unsigned FEVTDEBE : 1;
        unsigned RESERVED2 : 1;
        unsigned FEVTAC12E : 1;
        unsigned RESERVED3 : 1;
        unsigned FEVTTNE : 1;
        unsigned RESERVED4 : 1;
        unsigned FEVTDMAE : 1;
        unsigned RESERVED5 : 2;
        unsigned FEVTCINT : 1;

    } B;
} hw_usdhc_force_event_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_FORCE_EVENT register
 */
#define HW_USDHC_FORCE_EVENT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_FORCE_EVENT(x)           (*(volatile hw_usdhc_force_event_t *) HW_USDHC_FORCE_EVENT_ADDR(x))
#define HW_USDHC_FORCE_EVENT_RD(x)        (HW_USDHC_FORCE_EVENT(x).U)
#define HW_USDHC_FORCE_EVENT_WR(x, v)     (HW_USDHC_FORCE_EVENT(x).U = (v))
#define HW_USDHC_FORCE_EVENT_SET(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) |  (v)))
#define HW_USDHC_FORCE_EVENT_CLR(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) & ~(v)))
#define HW_USDHC_FORCE_EVENT_TOG(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_FORCE_EVENT bitfields
 */

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12NE */

#define BP_USDHC_FORCE_EVENT_FEVTAC12NE      0
#define BM_USDHC_FORCE_EVENT_FEVTAC12NE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12NE(v)   ((((reg32_t) v) << 0) & BM_USDHC_FORCE_EVENT_FEVTAC12NE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12NE(v)   (((v) << 0) & BM_USDHC_FORCE_EVENT_FEVTAC12NE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12NE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12NE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12TOE */

#define BP_USDHC_FORCE_EVENT_FEVTAC12TOE      1
#define BM_USDHC_FORCE_EVENT_FEVTAC12TOE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   ((((reg32_t) v) << 1) & BM_USDHC_FORCE_EVENT_FEVTAC12TOE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   (((v) << 1) & BM_USDHC_FORCE_EVENT_FEVTAC12TOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12TOE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12CE */

#define BP_USDHC_FORCE_EVENT_FEVTAC12CE      2
#define BM_USDHC_FORCE_EVENT_FEVTAC12CE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12CE(v)   ((((reg32_t) v) << 2) & BM_USDHC_FORCE_EVENT_FEVTAC12CE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12CE(v)   (((v) << 2) & BM_USDHC_FORCE_EVENT_FEVTAC12CE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12CE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12CE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12EBE */

#define BP_USDHC_FORCE_EVENT_FEVTAC12EBE      3
#define BM_USDHC_FORCE_EVENT_FEVTAC12EBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   ((((reg32_t) v) << 3) & BM_USDHC_FORCE_EVENT_FEVTAC12EBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   (((v) << 3) & BM_USDHC_FORCE_EVENT_FEVTAC12EBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12EBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12IE */

#define BP_USDHC_FORCE_EVENT_FEVTAC12IE      4
#define BM_USDHC_FORCE_EVENT_FEVTAC12IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12IE(v)   ((((reg32_t) v) << 4) & BM_USDHC_FORCE_EVENT_FEVTAC12IE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12IE(v)   (((v) << 4) & BM_USDHC_FORCE_EVENT_FEVTAC12IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12IE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12IE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCNIBAC12E */

#define BP_USDHC_FORCE_EVENT_FEVTCNIBAC12E      7
#define BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   ((((reg32_t) v) << 7) & BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   (((v) << 7) & BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCNIBAC12E, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCCE */

#define BP_USDHC_FORCE_EVENT_FEVTCCE      16
#define BM_USDHC_FORCE_EVENT_FEVTCCE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   ((((reg32_t) v) << 16) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   (((v) << 16) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCCE */

#define BP_USDHC_FORCE_EVENT_FEVTCCE      17
#define BM_USDHC_FORCE_EVENT_FEVTCCE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   ((((reg32_t) v) << 17) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   (((v) << 17) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCEBE */

#define BP_USDHC_FORCE_EVENT_FEVTCEBE      18
#define BM_USDHC_FORCE_EVENT_FEVTCEBE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCEBE(v)   ((((reg32_t) v) << 18) & BM_USDHC_FORCE_EVENT_FEVTCEBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCEBE(v)   (((v) << 18) & BM_USDHC_FORCE_EVENT_FEVTCEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCEBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCEBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCIE */

#define BP_USDHC_FORCE_EVENT_FEVTCIE      19
#define BM_USDHC_FORCE_EVENT_FEVTCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCIE(v)   ((((reg32_t) v) << 19) & BM_USDHC_FORCE_EVENT_FEVTCIE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCIE(v)   (((v) << 19) & BM_USDHC_FORCE_EVENT_FEVTCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCIE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCIE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDTOE */

#define BP_USDHC_FORCE_EVENT_FEVTDTOE      20
#define BM_USDHC_FORCE_EVENT_FEVTDTOE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDTOE(v)   ((((reg32_t) v) << 20) & BM_USDHC_FORCE_EVENT_FEVTDTOE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDTOE(v)   (((v) << 20) & BM_USDHC_FORCE_EVENT_FEVTDTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDTOE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDTOE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDCE */

#define BP_USDHC_FORCE_EVENT_FEVTDCE      21
#define BM_USDHC_FORCE_EVENT_FEVTDCE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDCE(v)   ((((reg32_t) v) << 21) & BM_USDHC_FORCE_EVENT_FEVTDCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDCE(v)   (((v) << 21) & BM_USDHC_FORCE_EVENT_FEVTDCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDEBE */

#define BP_USDHC_FORCE_EVENT_FEVTDEBE      22
#define BM_USDHC_FORCE_EVENT_FEVTDEBE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDEBE(v)   ((((reg32_t) v) << 22) & BM_USDHC_FORCE_EVENT_FEVTDEBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDEBE(v)   (((v) << 22) & BM_USDHC_FORCE_EVENT_FEVTDEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDEBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDEBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12E */

#define BP_USDHC_FORCE_EVENT_FEVTAC12E      24
#define BM_USDHC_FORCE_EVENT_FEVTAC12E      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12E(v)   ((((reg32_t) v) << 24) & BM_USDHC_FORCE_EVENT_FEVTAC12E)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12E(v)   (((v) << 24) & BM_USDHC_FORCE_EVENT_FEVTAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12E(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12E, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTTNE */

#define BP_USDHC_FORCE_EVENT_FEVTTNE      26
#define BM_USDHC_FORCE_EVENT_FEVTTNE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTTNE(v)   ((((reg32_t) v) << 26) & BM_USDHC_FORCE_EVENT_FEVTTNE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTTNE(v)   (((v) << 26) & BM_USDHC_FORCE_EVENT_FEVTTNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTTNE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTTNE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDMAE */

#define BP_USDHC_FORCE_EVENT_FEVTDMAE      28
#define BM_USDHC_FORCE_EVENT_FEVTDMAE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDMAE(v)   ((((reg32_t) v) << 28) & BM_USDHC_FORCE_EVENT_FEVTDMAE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDMAE(v)   (((v) << 28) & BM_USDHC_FORCE_EVENT_FEVTDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDMAE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDMAE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCINT */

#define BP_USDHC_FORCE_EVENT_FEVTCINT      31
#define BM_USDHC_FORCE_EVENT_FEVTCINT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCINT(v)   ((((reg32_t) v) << 31) & BM_USDHC_FORCE_EVENT_FEVTCINT)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCINT(v)   (((v) << 31) & BM_USDHC_FORCE_EVENT_FEVTCINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCINT(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCINT, v)
#endif

/*
 * HW_USDHC_ADMA_ERR_STATUS - ADMA Error Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADMAES : 2;
        unsigned ADMALME : 1;
        unsigned ADMADCE : 1;
        unsigned RESERVED0 : 28;

    } B;
} hw_usdhc_adma_err_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_ADMA_ERR_STATUS register
 */
#define HW_USDHC_ADMA_ERR_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_ADMA_ERR_STATUS(x)           (*(volatile hw_usdhc_adma_err_status_t *) HW_USDHC_ADMA_ERR_STATUS_ADDR(x))
#define HW_USDHC_ADMA_ERR_STATUS_RD(x)        (HW_USDHC_ADMA_ERR_STATUS(x).U)
#define HW_USDHC_ADMA_ERR_STATUS_WR(x, v)     (HW_USDHC_ADMA_ERR_STATUS(x).U = (v))
#define HW_USDHC_ADMA_ERR_STATUS_SET(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) |  (v)))
#define HW_USDHC_ADMA_ERR_STATUS_CLR(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) & ~(v)))
#define HW_USDHC_ADMA_ERR_STATUS_TOG(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_ADMA_ERR_STATUS bitfields
 */

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMAES */

#define BP_USDHC_ADMA_ERR_STATUS_ADMAES      0
#define BM_USDHC_ADMA_ERR_STATUS_ADMAES      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMAES(v)   ((((reg32_t) v) << 0) & BM_USDHC_ADMA_ERR_STATUS_ADMAES)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMAES(v)   (((v) << 0) & BM_USDHC_ADMA_ERR_STATUS_ADMAES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMAES(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMAES, v)
#endif

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMALME */

#define BP_USDHC_ADMA_ERR_STATUS_ADMALME      2
#define BM_USDHC_ADMA_ERR_STATUS_ADMALME      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMALME(v)   ((((reg32_t) v) << 2) & BM_USDHC_ADMA_ERR_STATUS_ADMALME)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMALME(v)   (((v) << 2) & BM_USDHC_ADMA_ERR_STATUS_ADMALME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMALME(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMALME, v)
#endif

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMADCE */

#define BP_USDHC_ADMA_ERR_STATUS_ADMADCE      3
#define BM_USDHC_ADMA_ERR_STATUS_ADMADCE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   ((((reg32_t) v) << 3) & BM_USDHC_ADMA_ERR_STATUS_ADMADCE)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   (((v) << 3) & BM_USDHC_ADMA_ERR_STATUS_ADMADCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMADCE, v)
#endif

/*
 * HW_USDHC_ADMA_SYS_ADDR - ADMA System Address
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned ADS_ADDR : 30;

    } B;
} hw_usdhc_adma_sys_addr_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_ADMA_SYS_ADDR register
 */
#define HW_USDHC_ADMA_SYS_ADDR_ADDR(x)      (REGS_USDHC_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_ADMA_SYS_ADDR(x)           (*(volatile hw_usdhc_adma_sys_addr_t *) HW_USDHC_ADMA_SYS_ADDR_ADDR(x))
#define HW_USDHC_ADMA_SYS_ADDR_RD(x)        (HW_USDHC_ADMA_SYS_ADDR(x).U)
#define HW_USDHC_ADMA_SYS_ADDR_WR(x, v)     (HW_USDHC_ADMA_SYS_ADDR(x).U = (v))
#define HW_USDHC_ADMA_SYS_ADDR_SET(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) |  (v)))
#define HW_USDHC_ADMA_SYS_ADDR_CLR(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) & ~(v)))
#define HW_USDHC_ADMA_SYS_ADDR_TOG(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_ADMA_SYS_ADDR bitfields
 */

/* --- Register HW_USDHC_ADMA_SYS_ADDR, field ADS_ADDR */

#define BP_USDHC_ADMA_SYS_ADDR_ADS_ADDR      2
#define BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   ((((reg32_t) v) << 2) & BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR)
#else
#define BF_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   (((v) << 2) & BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   BF_CS1(USDHC_ADMA_SYS_ADDR, ADS_ADDR, v)
#endif

/*
 * HW_USDHC_DLL_CTRL - DLL (Delay Line) Control
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLL_CTRL_ENABLE : 1;
        unsigned DLL_CTRL_RESET : 1;
        unsigned DLL_CTRL_SLV_FORCE_UPD : 1;
        unsigned DLL_CTRL_SLV_DLY_TARGET : 4;
        unsigned DLL_CTRL_GATE_UPDATE : 1;
        unsigned DLL_CTRL_SLV_OVERRIDE : 1;
        unsigned DLL_CTRL_SLV_OVERRIDE_VAL : 7;
        unsigned DLL_CTRL_SLV_DLY_TARGET : 3;
        unsigned RESERVED0 : 1;
        unsigned DLL_CTRL_SLV_UPDATE_INT : 8;
        unsigned DLL_CTRL_REF_UPDATE_INT : 4;

    } B;
} hw_usdhc_dll_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DLL_CTRL register
 */
#define HW_USDHC_DLL_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DLL_CTRL(x)           (*(volatile hw_usdhc_dll_ctrl_t *) HW_USDHC_DLL_CTRL_ADDR(x))
#define HW_USDHC_DLL_CTRL_RD(x)        (HW_USDHC_DLL_CTRL(x).U)
#define HW_USDHC_DLL_CTRL_WR(x, v)     (HW_USDHC_DLL_CTRL(x).U = (v))
#define HW_USDHC_DLL_CTRL_SET(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) |  (v)))
#define HW_USDHC_DLL_CTRL_CLR(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) & ~(v)))
#define HW_USDHC_DLL_CTRL_TOG(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DLL_CTRL bitfields
 */

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_ENABLE */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_ENABLE      0
#define BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   (((v) << 0) & BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_ENABLE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_RESET */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_RESET      1
#define BM_USDHC_DLL_CTRL_DLL_CTRL_RESET      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   ((((reg32_t) v) << 1) & BM_USDHC_DLL_CTRL_DLL_CTRL_RESET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   (((v) << 1) & BM_USDHC_DLL_CTRL_DLL_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_RESET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_FORCE_UPD */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD      2
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   ((((reg32_t) v) << 2) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   (((v) << 2) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_FORCE_UPD, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_DLY_TARGET */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      3
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      0x00000078

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   ((((reg32_t) v) << 3) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   (((v) << 3) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_DLY_TARGET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_GATE_UPDATE */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE      7
#define BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   ((((reg32_t) v) << 7) & BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   (((v) << 7) & BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_GATE_UPDATE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_OVERRIDE */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE      8
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   ((((reg32_t) v) << 8) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   (((v) << 8) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_OVERRIDE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_OVERRIDE_VAL */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL      9
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL      0x0000fe00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   ((((reg32_t) v) << 9) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   (((v) << 9) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_OVERRIDE_VAL, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_DLY_TARGET */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      16
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   ((((reg32_t) v) << 16) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   (((v) << 16) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_DLY_TARGET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_UPDATE_INT */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT      20
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT      0x0ff00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   ((((reg32_t) v) << 20) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   (((v) << 20) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_UPDATE_INT, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_REF_UPDATE_INT */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT      28
#define BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   ((((reg32_t) v) << 28) & BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   (((v) << 28) & BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_REF_UPDATE_INT, v)
#endif

/*
 * HW_USDHC_DLL_STATUS - DLL Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLL_STS_SLV_LOCK : 1;
        unsigned DLL_STS_REF_LOCK : 1;
        unsigned DLL_STS_SLV_SEL : 7;
        unsigned DLL_STS_REF_SEL : 7;
        unsigned RESERVED0 : 16;

    } B;
} hw_usdhc_dll_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DLL_STATUS register
 */
#define HW_USDHC_DLL_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DLL_STATUS(x)           (*(volatile hw_usdhc_dll_status_t *) HW_USDHC_DLL_STATUS_ADDR(x))
#define HW_USDHC_DLL_STATUS_RD(x)        (HW_USDHC_DLL_STATUS(x).U)
#define HW_USDHC_DLL_STATUS_WR(x, v)     (HW_USDHC_DLL_STATUS(x).U = (v))
#define HW_USDHC_DLL_STATUS_SET(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) |  (v)))
#define HW_USDHC_DLL_STATUS_CLR(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) & ~(v)))
#define HW_USDHC_DLL_STATUS_TOG(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DLL_STATUS bitfields
 */

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_SLV_LOCK */

#define BP_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK      0
#define BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   ((((reg32_t) v) << 0) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   (((v) << 0) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_SLV_LOCK, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_REF_LOCK */

#define BP_USDHC_DLL_STATUS_DLL_STS_REF_LOCK      1
#define BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   ((((reg32_t) v) << 1) & BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   (((v) << 1) & BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_REF_LOCK, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_SLV_SEL */

#define BP_USDHC_DLL_STATUS_DLL_STS_SLV_SEL      2
#define BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL      0x000001fc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   ((((reg32_t) v) << 2) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   (((v) << 2) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_SLV_SEL, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_REF_SEL */

#define BP_USDHC_DLL_STATUS_DLL_STS_REF_SEL      9
#define BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL      0x0000fe00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   ((((reg32_t) v) << 9) & BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   (((v) << 9) & BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_REF_SEL, v)
#endif

/*
 * HW_USDHC_CLK_TUNE_CTRL_STATUS - CLK Tuning Control and Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_CELL_SET_POST : 4;
        unsigned DLY_CELL_SET_OUT : 4;
        unsigned DLY_CELL_SET_PRE : 7;
        unsigned NXT_ERR : 1;
        unsigned TAP_SEL_POST : 4;
        unsigned TAP_SEL_OUT : 4;
        unsigned TAP_SEL_PRE : 7;
        unsigned PRE_ERR : 1;

    } B;
} hw_usdhc_clk_tune_ctrl_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CLK_TUNE_CTRL_STATUS register
 */
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CLK_TUNE_CTRL_STATUS(x)           (*(volatile hw_usdhc_clk_tune_ctrl_status_t *) HW_USDHC_CLK_TUNE_CTRL_STATUS_ADDR(x))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x)        (HW_USDHC_CLK_TUNE_CTRL_STATUS(x).U)
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, v)     (HW_USDHC_CLK_TUNE_CTRL_STATUS(x).U = (v))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_SET(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) |  (v)))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_CLR(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) & ~(v)))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_TOG(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CLK_TUNE_CTRL_STATUS bitfields
 */

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_POST */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST      0
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   ((((reg32_t) v) << 0) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   (((v) << 0) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_POST, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_OUT */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT      4
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   ((((reg32_t) v) << 4) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   (((v) << 4) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_OUT, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_PRE */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE      8
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   ((((reg32_t) v) << 8) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   (((v) << 8) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_PRE, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field NXT_ERR */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR      15
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   ((((reg32_t) v) << 15) & BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   (((v) << 15) & BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, NXT_ERR, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_POST */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST      16
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   ((((reg32_t) v) << 16) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   (((v) << 16) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_POST, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_OUT */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT      20
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   ((((reg32_t) v) << 20) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   (((v) << 20) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_OUT, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_PRE */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE      24
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   ((((reg32_t) v) << 24) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   (((v) << 24) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_PRE, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field PRE_ERR */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR      31
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   ((((reg32_t) v) << 31) & BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   (((v) << 31) & BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, PRE_ERR, v)
#endif

/*
 * HW_USDHC_VEND_SPEC - Vendor Specific Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EXT_DMA_EN : 1;
        unsigned VSELECT : 1;
        unsigned CONFLICT_CHK_EN : 1;
        unsigned AC12_WR_CHKBUSY_EN : 1;
        unsigned DAT3_CD_POL : 1;
        unsigned CD_POL : 1;
        unsigned WP_POL : 1;
        unsigned CLKONJ_IN_ABORT : 1;
        unsigned FRC_SDCLK_ON : 1;
        unsigned AC12_ISNOT_ABORT : 1;
        unsigned DDREN_ACT_ATONCE : 1;
        unsigned IPG_CLK_SOFT_EN : 1;
        unsigned HCLK_SOFT_EN : 1;
        unsigned IPG_PERCLK_SOFT_EN : 1;
        unsigned RESERVED0 : 1;
        unsigned CRC_CHK_DIS : 1;
        unsigned INT_ST_VAL : 8;
        unsigned DBG_SEL : 4;
        unsigned CMD_OE_PRE_EN : 1;
        unsigned AC12_RD_CHKBUSY_EN : 1;
        unsigned CARD_DET_IN_IDLE_ENJ : 1;
        unsigned RESERVED1 : 1;

    } B;
} hw_usdhc_vend_spec_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_VEND_SPEC register
 */
#define HW_USDHC_VEND_SPEC_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_VEND_SPEC(x)           (*(volatile hw_usdhc_vend_spec_t *) HW_USDHC_VEND_SPEC_ADDR(x))
#define HW_USDHC_VEND_SPEC_RD(x)        (HW_USDHC_VEND_SPEC(x).U)
#define HW_USDHC_VEND_SPEC_WR(x, v)     (HW_USDHC_VEND_SPEC(x).U = (v))
#define HW_USDHC_VEND_SPEC_SET(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) |  (v)))
#define HW_USDHC_VEND_SPEC_CLR(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) & ~(v)))
#define HW_USDHC_VEND_SPEC_TOG(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_VEND_SPEC bitfields
 */

/* --- Register HW_USDHC_VEND_SPEC, field EXT_DMA_EN */

#define BP_USDHC_VEND_SPEC_EXT_DMA_EN      0
#define BM_USDHC_VEND_SPEC_EXT_DMA_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_EXT_DMA_EN(v)   ((((reg32_t) v) << 0) & BM_USDHC_VEND_SPEC_EXT_DMA_EN)
#else
#define BF_USDHC_VEND_SPEC_EXT_DMA_EN(v)   (((v) << 0) & BM_USDHC_VEND_SPEC_EXT_DMA_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_EXT_DMA_EN(v)   BF_CS1(USDHC_VEND_SPEC, EXT_DMA_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field VSELECT */

#define BP_USDHC_VEND_SPEC_VSELECT      1
#define BM_USDHC_VEND_SPEC_VSELECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_VSELECT(v)   ((((reg32_t) v) << 1) & BM_USDHC_VEND_SPEC_VSELECT)
#else
#define BF_USDHC_VEND_SPEC_VSELECT(v)   (((v) << 1) & BM_USDHC_VEND_SPEC_VSELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_VSELECT(v)   BF_CS1(USDHC_VEND_SPEC, VSELECT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CONFLICT_CHK_EN */

#define BP_USDHC_VEND_SPEC_CONFLICT_CHK_EN      2
#define BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   ((((reg32_t) v) << 2) & BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN)
#else
#define BF_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   (((v) << 2) & BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   BF_CS1(USDHC_VEND_SPEC, CONFLICT_CHK_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_WR_CHKBUSY_EN */

#define BP_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN      3
#define BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   ((((reg32_t) v) << 3) & BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN)
#else
#define BF_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   (((v) << 3) & BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   BF_CS1(USDHC_VEND_SPEC, AC12_WR_CHKBUSY_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DAT3_CD_POL */

#define BP_USDHC_VEND_SPEC_DAT3_CD_POL      4
#define BM_USDHC_VEND_SPEC_DAT3_CD_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DAT3_CD_POL(v)   ((((reg32_t) v) << 4) & BM_USDHC_VEND_SPEC_DAT3_CD_POL)
#else
#define BF_USDHC_VEND_SPEC_DAT3_CD_POL(v)   (((v) << 4) & BM_USDHC_VEND_SPEC_DAT3_CD_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DAT3_CD_POL(v)   BF_CS1(USDHC_VEND_SPEC, DAT3_CD_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CD_POL */

#define BP_USDHC_VEND_SPEC_CD_POL      5
#define BM_USDHC_VEND_SPEC_CD_POL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CD_POL(v)   ((((reg32_t) v) << 5) & BM_USDHC_VEND_SPEC_CD_POL)
#else
#define BF_USDHC_VEND_SPEC_CD_POL(v)   (((v) << 5) & BM_USDHC_VEND_SPEC_CD_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CD_POL(v)   BF_CS1(USDHC_VEND_SPEC, CD_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field WP_POL */

#define BP_USDHC_VEND_SPEC_WP_POL      6
#define BM_USDHC_VEND_SPEC_WP_POL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_WP_POL(v)   ((((reg32_t) v) << 6) & BM_USDHC_VEND_SPEC_WP_POL)
#else
#define BF_USDHC_VEND_SPEC_WP_POL(v)   (((v) << 6) & BM_USDHC_VEND_SPEC_WP_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_WP_POL(v)   BF_CS1(USDHC_VEND_SPEC, WP_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CLKONJ_IN_ABORT */

#define BP_USDHC_VEND_SPEC_CLKONJ_IN_ABORT      7
#define BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   ((((reg32_t) v) << 7) & BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT)
#else
#define BF_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   (((v) << 7) & BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   BF_CS1(USDHC_VEND_SPEC, CLKONJ_IN_ABORT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field FRC_SDCLK_ON */

#define BP_USDHC_VEND_SPEC_FRC_SDCLK_ON      8
#define BM_USDHC_VEND_SPEC_FRC_SDCLK_ON      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   ((((reg32_t) v) << 8) & BM_USDHC_VEND_SPEC_FRC_SDCLK_ON)
#else
#define BF_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   (((v) << 8) & BM_USDHC_VEND_SPEC_FRC_SDCLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   BF_CS1(USDHC_VEND_SPEC, FRC_SDCLK_ON, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_ISNOT_ABORT */

#define BP_USDHC_VEND_SPEC_AC12_ISNOT_ABORT      9
#define BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   ((((reg32_t) v) << 9) & BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT)
#else
#define BF_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   (((v) << 9) & BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   BF_CS1(USDHC_VEND_SPEC, AC12_ISNOT_ABORT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DDREN_ACT_ATONCE */

#define BP_USDHC_VEND_SPEC_DDREN_ACT_ATONCE      10
#define BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   ((((reg32_t) v) << 10) & BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE)
#else
#define BF_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   (((v) << 10) & BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   BF_CS1(USDHC_VEND_SPEC, DDREN_ACT_ATONCE, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field IPG_CLK_SOFT_EN */

#define BP_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN      11
#define BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   ((((reg32_t) v) << 11) & BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   (((v) << 11) & BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, IPG_CLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field HCLK_SOFT_EN */

#define BP_USDHC_VEND_SPEC_HCLK_SOFT_EN      12
#define BM_USDHC_VEND_SPEC_HCLK_SOFT_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   ((((reg32_t) v) << 12) & BM_USDHC_VEND_SPEC_HCLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   (((v) << 12) & BM_USDHC_VEND_SPEC_HCLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, HCLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field IPG_PERCLK_SOFT_EN */

#define BP_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN      13
#define BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   ((((reg32_t) v) << 13) & BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   (((v) << 13) & BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, IPG_PERCLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CRC_CHK_DIS */

#define BP_USDHC_VEND_SPEC_CRC_CHK_DIS      15
#define BM_USDHC_VEND_SPEC_CRC_CHK_DIS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   ((((reg32_t) v) << 15) & BM_USDHC_VEND_SPEC_CRC_CHK_DIS)
#else
#define BF_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   (((v) << 15) & BM_USDHC_VEND_SPEC_CRC_CHK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   BF_CS1(USDHC_VEND_SPEC, CRC_CHK_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field INT_ST_VAL */

#define BP_USDHC_VEND_SPEC_INT_ST_VAL      16
#define BM_USDHC_VEND_SPEC_INT_ST_VAL      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_INT_ST_VAL(v)   ((((reg32_t) v) << 16) & BM_USDHC_VEND_SPEC_INT_ST_VAL)
#else
#define BF_USDHC_VEND_SPEC_INT_ST_VAL(v)   (((v) << 16) & BM_USDHC_VEND_SPEC_INT_ST_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_INT_ST_VAL(v)   BF_CS1(USDHC_VEND_SPEC, INT_ST_VAL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DBG_SEL */

#define BP_USDHC_VEND_SPEC_DBG_SEL      24
#define BM_USDHC_VEND_SPEC_DBG_SEL      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DBG_SEL(v)   ((((reg32_t) v) << 24) & BM_USDHC_VEND_SPEC_DBG_SEL)
#else
#define BF_USDHC_VEND_SPEC_DBG_SEL(v)   (((v) << 24) & BM_USDHC_VEND_SPEC_DBG_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DBG_SEL(v)   BF_CS1(USDHC_VEND_SPEC, DBG_SEL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CMD_OE_PRE_EN */

#define BP_USDHC_VEND_SPEC_CMD_OE_PRE_EN      28
#define BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   ((((reg32_t) v) << 28) & BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN)
#else
#define BF_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   (((v) << 28) & BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   BF_CS1(USDHC_VEND_SPEC, CMD_OE_PRE_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_RD_CHKBUSY_EN */

#define BP_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN      29
#define BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   ((((reg32_t) v) << 29) & BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN)
#else
#define BF_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   (((v) << 29) & BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   BF_CS1(USDHC_VEND_SPEC, AC12_RD_CHKBUSY_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CARD_DET_IN_IDLE_ENJ */

#define BP_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ      30
#define BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   ((((reg32_t) v) << 30) & BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ)
#else
#define BF_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   (((v) << 30) & BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   BF_CS1(USDHC_VEND_SPEC, CARD_DET_IN_IDLE_ENJ, v)
#endif

/*
 * HW_USDHC_MMC_BOOT - MMC Boot Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DTOCV_ACK : 4;
        unsigned BOOT_ACK : 1;
        unsigned BOOT_MODE : 1;
        unsigned BOOT_EN : 1;
        unsigned AUTO_SABG_EN : 1;
        unsigned DISABLE_TIME_OUT : 1;
        unsigned RESERVED0 : 7;
        unsigned BOOT_BLK_CNT : 16;

    } B;
} hw_usdhc_mmc_boot_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_MMC_BOOT register
 */
#define HW_USDHC_MMC_BOOT_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_MMC_BOOT(x)           (*(volatile hw_usdhc_mmc_boot_t *) HW_USDHC_MMC_BOOT_ADDR(x))
#define HW_USDHC_MMC_BOOT_RD(x)        (HW_USDHC_MMC_BOOT(x).U)
#define HW_USDHC_MMC_BOOT_WR(x, v)     (HW_USDHC_MMC_BOOT(x).U = (v))
#define HW_USDHC_MMC_BOOT_SET(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) |  (v)))
#define HW_USDHC_MMC_BOOT_CLR(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) & ~(v)))
#define HW_USDHC_MMC_BOOT_TOG(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_MMC_BOOT bitfields
 */

/* --- Register HW_USDHC_MMC_BOOT, field DTOCV_ACK */

#define BP_USDHC_MMC_BOOT_DTOCV_ACK      0
#define BM_USDHC_MMC_BOOT_DTOCV_ACK      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_DTOCV_ACK(v)   ((((reg32_t) v) << 0) & BM_USDHC_MMC_BOOT_DTOCV_ACK)
#else
#define BF_USDHC_MMC_BOOT_DTOCV_ACK(v)   (((v) << 0) & BM_USDHC_MMC_BOOT_DTOCV_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_DTOCV_ACK(v)   BF_CS1(USDHC_MMC_BOOT, DTOCV_ACK, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_ACK */

#define BP_USDHC_MMC_BOOT_BOOT_ACK      4
#define BM_USDHC_MMC_BOOT_BOOT_ACK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_ACK(v)   ((((reg32_t) v) << 4) & BM_USDHC_MMC_BOOT_BOOT_ACK)
#else
#define BF_USDHC_MMC_BOOT_BOOT_ACK(v)   (((v) << 4) & BM_USDHC_MMC_BOOT_BOOT_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_ACK(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_ACK, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_MODE */

#define BP_USDHC_MMC_BOOT_BOOT_MODE      5
#define BM_USDHC_MMC_BOOT_BOOT_MODE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_MODE(v)   ((((reg32_t) v) << 5) & BM_USDHC_MMC_BOOT_BOOT_MODE)
#else
#define BF_USDHC_MMC_BOOT_BOOT_MODE(v)   (((v) << 5) & BM_USDHC_MMC_BOOT_BOOT_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_MODE(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_MODE, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_EN */

#define BP_USDHC_MMC_BOOT_BOOT_EN      6
#define BM_USDHC_MMC_BOOT_BOOT_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_EN(v)   ((((reg32_t) v) << 6) & BM_USDHC_MMC_BOOT_BOOT_EN)
#else
#define BF_USDHC_MMC_BOOT_BOOT_EN(v)   (((v) << 6) & BM_USDHC_MMC_BOOT_BOOT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_EN(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_EN, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field AUTO_SABG_EN */

#define BP_USDHC_MMC_BOOT_AUTO_SABG_EN      7
#define BM_USDHC_MMC_BOOT_AUTO_SABG_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   ((((reg32_t) v) << 7) & BM_USDHC_MMC_BOOT_AUTO_SABG_EN)
#else
#define BF_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   (((v) << 7) & BM_USDHC_MMC_BOOT_AUTO_SABG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   BF_CS1(USDHC_MMC_BOOT, AUTO_SABG_EN, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field DISABLE_TIME_OUT */

#define BP_USDHC_MMC_BOOT_DISABLE_TIME_OUT      8
#define BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   ((((reg32_t) v) << 8) & BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT)
#else
#define BF_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   (((v) << 8) & BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   BF_CS1(USDHC_MMC_BOOT, DISABLE_TIME_OUT, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_BLK_CNT */

#define BP_USDHC_MMC_BOOT_BOOT_BLK_CNT      16
#define BM_USDHC_MMC_BOOT_BOOT_BLK_CNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   ((((reg32_t) v) << 16) & BM_USDHC_MMC_BOOT_BOOT_BLK_CNT)
#else
#define BF_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   (((v) << 16) & BM_USDHC_MMC_BOOT_BOOT_BLK_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_BLK_CNT, v)
#endif

/*
 * HW_USDHC_VEND_SPEC2 - Vendor Specific 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SDR104_TIMING_DIS : 1;
        unsigned SDR104_OE_DIS : 1;
        unsigned SDR104_NSD_DIS : 1;
        unsigned CARD_INT_D3_TEST : 1;
        unsigned TUNING_8BIT_EN : 1;
        unsigned TUNING_1BIT_EN : 1;
        unsigned TUNING_CMD_EN : 1;
        unsigned CARD_INT_AUTO_CLR_DIS : 1;
        unsigned RESERVED0 : 24;

    } B;
} hw_usdhc_vend_spec2_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_VEND_SPEC2 register
 */
#define HW_USDHC_VEND_SPEC2_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc8)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_VEND_SPEC2(x)           (*(volatile hw_usdhc_vend_spec2_t *) HW_USDHC_VEND_SPEC2_ADDR(x))
#define HW_USDHC_VEND_SPEC2_RD(x)        (HW_USDHC_VEND_SPEC2(x).U)
#define HW_USDHC_VEND_SPEC2_WR(x, v)     (HW_USDHC_VEND_SPEC2(x).U = (v))
#define HW_USDHC_VEND_SPEC2_SET(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) |  (v)))
#define HW_USDHC_VEND_SPEC2_CLR(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) & ~(v)))
#define HW_USDHC_VEND_SPEC2_TOG(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_VEND_SPEC2 bitfields
 */

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_TIMING_DIS */

#define BP_USDHC_VEND_SPEC2_SDR104_TIMING_DIS      0
#define BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   ((((reg32_t) v) << 0) & BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   (((v) << 0) & BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_TIMING_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_OE_DIS */

#define BP_USDHC_VEND_SPEC2_SDR104_OE_DIS      1
#define BM_USDHC_VEND_SPEC2_SDR104_OE_DIS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   ((((reg32_t) v) << 1) & BM_USDHC_VEND_SPEC2_SDR104_OE_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   (((v) << 1) & BM_USDHC_VEND_SPEC2_SDR104_OE_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_OE_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_NSD_DIS */

#define BP_USDHC_VEND_SPEC2_SDR104_NSD_DIS      2
#define BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   ((((reg32_t) v) << 2) & BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   (((v) << 2) & BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_NSD_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field CARD_INT_D3_TEST */

#define BP_USDHC_VEND_SPEC2_CARD_INT_D3_TEST      3
#define BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   ((((reg32_t) v) << 3) & BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST)
#else
#define BF_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   (((v) << 3) & BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   BF_CS1(USDHC_VEND_SPEC2, CARD_INT_D3_TEST, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_8BIT_EN */

#define BP_USDHC_VEND_SPEC2_TUNING_8BIT_EN      4
#define BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   ((((reg32_t) v) << 4) & BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   (((v) << 4) & BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_8BIT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_1BIT_EN */

#define BP_USDHC_VEND_SPEC2_TUNING_1BIT_EN      5
#define BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   ((((reg32_t) v) << 5) & BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   (((v) << 5) & BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_1BIT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_CMD_EN */

#define BP_USDHC_VEND_SPEC2_TUNING_CMD_EN      6
#define BM_USDHC_VEND_SPEC2_TUNING_CMD_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   ((((reg32_t) v) << 6) & BM_USDHC_VEND_SPEC2_TUNING_CMD_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   (((v) << 6) & BM_USDHC_VEND_SPEC2_TUNING_CMD_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_CMD_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field CARD_INT_AUTO_CLR_DIS */

#define BP_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS      7
#define BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   ((((reg32_t) v) << 7) & BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS)
#else
#define BF_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   (((v) << 7) & BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, CARD_INT_AUTO_CLR_DIS, v)
#endif

/*
 * HW_USDHC_HOST_CTRL_VER - Host Controller Version
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SVN : 8;
        unsigned VVN : 8;
        unsigned RESERVED0 : 16;

    } B;
} hw_usdhc_host_ctrl_ver_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_HOST_CTRL_VER register
 */
#define HW_USDHC_HOST_CTRL_VER_ADDR(x)      (REGS_USDHC_BASE(x) + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_HOST_CTRL_VER(x)           (*(volatile hw_usdhc_host_ctrl_ver_t *) HW_USDHC_HOST_CTRL_VER_ADDR(x))
#define HW_USDHC_HOST_CTRL_VER_RD(x)        (HW_USDHC_HOST_CTRL_VER(x).U)
#define HW_USDHC_HOST_CTRL_VER_WR(x, v)     (HW_USDHC_HOST_CTRL_VER(x).U = (v))
#define HW_USDHC_HOST_CTRL_VER_SET(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) |  (v)))
#define HW_USDHC_HOST_CTRL_VER_CLR(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) & ~(v)))
#define HW_USDHC_HOST_CTRL_VER_TOG(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_HOST_CTRL_VER bitfields
 */

/* --- Register HW_USDHC_HOST_CTRL_VER, field SVN */

#define BP_USDHC_HOST_CTRL_VER_SVN      0
#define BM_USDHC_HOST_CTRL_VER_SVN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_VER_SVN(v)   ((((reg32_t) v) << 0) & BM_USDHC_HOST_CTRL_VER_SVN)
#else
#define BF_USDHC_HOST_CTRL_VER_SVN(v)   (((v) << 0) & BM_USDHC_HOST_CTRL_VER_SVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_VER_SVN(v)   BF_CS1(USDHC_HOST_CTRL_VER, SVN, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_VER, field VVN */

#define BP_USDHC_HOST_CTRL_VER_VVN      8
#define BM_USDHC_HOST_CTRL_VER_VVN      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_VER_VVN(v)   ((((reg32_t) v) << 8) & BM_USDHC_HOST_CTRL_VER_VVN)
#else
#define BF_USDHC_HOST_CTRL_VER_VVN(v)   (((v) << 8) & BM_USDHC_HOST_CTRL_VER_VVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_VER_VVN(v)   BF_CS1(USDHC_HOST_CTRL_VER, VVN, v)
#endif


#endif // _USDHC_H

