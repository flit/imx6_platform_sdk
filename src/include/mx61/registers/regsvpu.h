/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VPU_H
#define _VPU_H

#include "regs.h"

#ifndef REGS_VPU_BASE
#define REGS_VPU_BASE (REGS_BASE + 0x02040000)

#endif


/*
 * HW_VPU_CODERUN - BIT Processor run start
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned VPU : 1;

    } B;
} hw_vpu_coderun_t;
#endif

/*
 * constants & macros for entire VPU_CODERUN register
 */
#define HW_VPU_CODERUN_ADDR      (REGS_VPU_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODERUN           (*(volatile hw_vpu_coderun_t *) HW_VPU_CODERUN_ADDR)
#define HW_VPU_CODERUN_RD()      (HW_VPU_CODERUN.U)
#define HW_VPU_CODERUN_WR(v)     (HW_VPU_CODERUN.U = (v))
#define HW_VPU_CODERUN_SET(v)    (HW_VPU_CODERUN_WR(HW_VPU_CODERUN_RD() |  (v)))
#define HW_VPU_CODERUN_CLR(v)    (HW_VPU_CODERUN_WR(HW_VPU_CODERUN_RD() & ~(v)))
#define HW_VPU_CODERUN_TOG(v)    (HW_VPU_CODERUN_WR(HW_VPU_CODERUN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_CODERUN bitfields
 */

/* --- Register HW_VPU_CODERUN, field VPU */

#define BP_VPU_CODERUN_VPU      0
#define BM_VPU_CODERUN_VPU      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODERUN_VPU(v)   ((((reg32_t) v) << 0) & BM_VPU_CODERUN_VPU)
#else
#define BF_VPU_CODERUN_VPU(v)   (((v) << 0) & BM_VPU_CODERUN_VPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_CODERUN_VPU(v)   BF_CS1(VPU_CODERUN, VPU, v)
#endif

/*
 * HW_VPU_CODEDOWN - BIT Boot Code Download Data register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 3;
        unsigned CODEADDR : 13;
        unsigned CODEDATA : 16;

    } B;
} hw_vpu_codedown_t;
#endif

/*
 * constants & macros for entire VPU_CODEDOWN register
 */
#define HW_VPU_CODEDOWN_ADDR      (REGS_VPU_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODEDOWN           (*(volatile hw_vpu_codedown_t *) HW_VPU_CODEDOWN_ADDR)
#define HW_VPU_CODEDOWN_RD()      (HW_VPU_CODEDOWN.U)
#define HW_VPU_CODEDOWN_WR(v)     (HW_VPU_CODEDOWN.U = (v))
#define HW_VPU_CODEDOWN_SET(v)    (HW_VPU_CODEDOWN_WR(HW_VPU_CODEDOWN_RD() |  (v)))
#define HW_VPU_CODEDOWN_CLR(v)    (HW_VPU_CODEDOWN_WR(HW_VPU_CODEDOWN_RD() & ~(v)))
#define HW_VPU_CODEDOWN_TOG(v)    (HW_VPU_CODEDOWN_WR(HW_VPU_CODEDOWN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_CODEDOWN bitfields
 */

/* --- Register HW_VPU_CODEDOWN, field CODEADDR */

#define BP_VPU_CODEDOWN_CODEADDR      16
#define BM_VPU_CODEDOWN_CODEADDR      0x1fff0000

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODEDOWN_CODEADDR(v)   ((((reg32_t) v) << 16) & BM_VPU_CODEDOWN_CODEADDR)
#else
#define BF_VPU_CODEDOWN_CODEADDR(v)   (((v) << 16) & BM_VPU_CODEDOWN_CODEADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_CODEDOWN_CODEADDR(v)   BF_CS1(VPU_CODEDOWN, CODEADDR, v)
#endif

/* --- Register HW_VPU_CODEDOWN, field CODEDATA */

#define BP_VPU_CODEDOWN_CODEDATA      0
#define BM_VPU_CODEDOWN_CODEDATA      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_VPU_CODEDOWN_CODEDATA(v)   ((((reg32_t) v) << 0) & BM_VPU_CODEDOWN_CODEDATA)
#else
#define BF_VPU_CODEDOWN_CODEDATA(v)   (((v) << 0) & BM_VPU_CODEDOWN_CODEDATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_CODEDOWN_CODEDATA(v)   BF_CS1(VPU_CODEDOWN, CODEDATA, v)
#endif

/*
 * HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned INTREQ : 1;

    } B;
} hw_vpu_hostintreq_t;
#endif

/*
 * constants & macros for entire VPU_HOSTINTREQ register
 */
#define HW_VPU_HOSTINTREQ_ADDR      (REGS_VPU_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_HOSTINTREQ           (*(volatile hw_vpu_hostintreq_t *) HW_VPU_HOSTINTREQ_ADDR)
#define HW_VPU_HOSTINTREQ_RD()      (HW_VPU_HOSTINTREQ.U)
#define HW_VPU_HOSTINTREQ_WR(v)     (HW_VPU_HOSTINTREQ.U = (v))
#define HW_VPU_HOSTINTREQ_SET(v)    (HW_VPU_HOSTINTREQ_WR(HW_VPU_HOSTINTREQ_RD() |  (v)))
#define HW_VPU_HOSTINTREQ_CLR(v)    (HW_VPU_HOSTINTREQ_WR(HW_VPU_HOSTINTREQ_RD() & ~(v)))
#define HW_VPU_HOSTINTREQ_TOG(v)    (HW_VPU_HOSTINTREQ_WR(HW_VPU_HOSTINTREQ_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_HOSTINTREQ bitfields
 */

/* --- Register HW_VPU_HOSTINTREQ, field INTREQ */

#define BP_VPU_HOSTINTREQ_INTREQ      0
#define BM_VPU_HOSTINTREQ_INTREQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_HOSTINTREQ_INTREQ(v)   ((((reg32_t) v) << 0) & BM_VPU_HOSTINTREQ_INTREQ)
#else
#define BF_VPU_HOSTINTREQ_INTREQ(v)   (((v) << 0) & BM_VPU_HOSTINTREQ_INTREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_HOSTINTREQ_INTREQ(v)   BF_CS1(VPU_HOSTINTREQ, INTREQ, v)
#endif

/*
 * HW_VPU_BITINTCLEAR - BIT Interrupt Clear
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned INTCLEAR : 1;

    } B;
} hw_vpu_bitintclear_t;
#endif

/*
 * constants & macros for entire VPU_BITINTCLEAR register
 */
#define HW_VPU_BITINTCLEAR_ADDR      (REGS_VPU_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTCLEAR           (*(volatile hw_vpu_bitintclear_t *) HW_VPU_BITINTCLEAR_ADDR)
#define HW_VPU_BITINTCLEAR_RD()      (HW_VPU_BITINTCLEAR.U)
#define HW_VPU_BITINTCLEAR_WR(v)     (HW_VPU_BITINTCLEAR.U = (v))
#define HW_VPU_BITINTCLEAR_SET(v)    (HW_VPU_BITINTCLEAR_WR(HW_VPU_BITINTCLEAR_RD() |  (v)))
#define HW_VPU_BITINTCLEAR_CLR(v)    (HW_VPU_BITINTCLEAR_WR(HW_VPU_BITINTCLEAR_RD() & ~(v)))
#define HW_VPU_BITINTCLEAR_TOG(v)    (HW_VPU_BITINTCLEAR_WR(HW_VPU_BITINTCLEAR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_BITINTCLEAR bitfields
 */

/* --- Register HW_VPU_BITINTCLEAR, field INTCLEAR */

#define BP_VPU_BITINTCLEAR_INTCLEAR      0
#define BM_VPU_BITINTCLEAR_INTCLEAR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_BITINTCLEAR_INTCLEAR(v)   ((((reg32_t) v) << 0) & BM_VPU_BITINTCLEAR_INTCLEAR)
#else
#define BF_VPU_BITINTCLEAR_INTCLEAR(v)   (((v) << 0) & BM_VPU_BITINTCLEAR_INTCLEAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_BITINTCLEAR_INTCLEAR(v)   BF_CS1(VPU_BITINTCLEAR, INTCLEAR, v)
#endif

/*
 * HW_VPU_BITINTSTS - BIT Interrupt Status
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned INTSTS : 1;

    } B;
} hw_vpu_bitintsts_t;
#endif

/*
 * constants & macros for entire VPU_BITINTSTS register
 */
#define HW_VPU_BITINTSTS_ADDR      (REGS_VPU_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTSTS           (*(volatile hw_vpu_bitintsts_t *) HW_VPU_BITINTSTS_ADDR)
#define HW_VPU_BITINTSTS_RD()      (HW_VPU_BITINTSTS.U)
#define HW_VPU_BITINTSTS_WR(v)     (HW_VPU_BITINTSTS.U = (v))
#define HW_VPU_BITINTSTS_SET(v)    (HW_VPU_BITINTSTS_WR(HW_VPU_BITINTSTS_RD() |  (v)))
#define HW_VPU_BITINTSTS_CLR(v)    (HW_VPU_BITINTSTS_WR(HW_VPU_BITINTSTS_RD() & ~(v)))
#define HW_VPU_BITINTSTS_TOG(v)    (HW_VPU_BITINTSTS_WR(HW_VPU_BITINTSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_BITINTSTS bitfields
 */

/* --- Register HW_VPU_BITINTSTS, field INTSTS */

#define BP_VPU_BITINTSTS_INTSTS      0
#define BM_VPU_BITINTSTS_INTSTS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_BITINTSTS_INTSTS(v)   ((((reg32_t) v) << 0) & BM_VPU_BITINTSTS_INTSTS)
#else
#define BF_VPU_BITINTSTS_INTSTS(v)   (((v) << 0) & BM_VPU_BITINTSTS_INTSTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_BITINTSTS_INTSTS(v)   BF_CS1(VPU_BITINTSTS, INTSTS, v)
#endif

/*
 * HW_VPU_BITCURPC - BIT Current PC
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned CURPC : 14;

    } B;
} hw_vpu_bitcurpc_t;
#endif

/*
 * constants & macros for entire VPU_BITCURPC register
 */
#define HW_VPU_BITCURPC_ADDR      (REGS_VPU_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCURPC           (*(volatile hw_vpu_bitcurpc_t *) HW_VPU_BITCURPC_ADDR)
#define HW_VPU_BITCURPC_RD()      (HW_VPU_BITCURPC.U)
#define HW_VPU_BITCURPC_WR(v)     (HW_VPU_BITCURPC.U = (v))
#define HW_VPU_BITCURPC_SET(v)    (HW_VPU_BITCURPC_WR(HW_VPU_BITCURPC_RD() |  (v)))
#define HW_VPU_BITCURPC_CLR(v)    (HW_VPU_BITCURPC_WR(HW_VPU_BITCURPC_RD() & ~(v)))
#define HW_VPU_BITCURPC_TOG(v)    (HW_VPU_BITCURPC_WR(HW_VPU_BITCURPC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_BITCURPC bitfields
 */

/* --- Register HW_VPU_BITCURPC, field CURPC */

#define BP_VPU_BITCURPC_CURPC      0
#define BM_VPU_BITCURPC_CURPC      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_VPU_BITCURPC_CURPC(v)   ((((reg32_t) v) << 0) & BM_VPU_BITCURPC_CURPC)
#else
#define BF_VPU_BITCURPC_CURPC(v)   (((v) << 0) & BM_VPU_BITCURPC_CURPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_BITCURPC_CURPC(v)   BF_CS1(VPU_BITCURPC, CURPC, v)
#endif

/*
 * HW_VPU_BITCODECBUSY - BIT CODEC Busy
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned CODECBUSY : 1;

    } B;
} hw_vpu_bitcodecbusy_t;
#endif

/*
 * constants & macros for entire VPU_BITCODECBUSY register
 */
#define HW_VPU_BITCODECBUSY_ADDR      (REGS_VPU_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCODECBUSY           (*(volatile hw_vpu_bitcodecbusy_t *) HW_VPU_BITCODECBUSY_ADDR)
#define HW_VPU_BITCODECBUSY_RD()      (HW_VPU_BITCODECBUSY.U)
#define HW_VPU_BITCODECBUSY_WR(v)     (HW_VPU_BITCODECBUSY.U = (v))
#define HW_VPU_BITCODECBUSY_SET(v)    (HW_VPU_BITCODECBUSY_WR(HW_VPU_BITCODECBUSY_RD() |  (v)))
#define HW_VPU_BITCODECBUSY_CLR(v)    (HW_VPU_BITCODECBUSY_WR(HW_VPU_BITCODECBUSY_RD() & ~(v)))
#define HW_VPU_BITCODECBUSY_TOG(v)    (HW_VPU_BITCODECBUSY_WR(HW_VPU_BITCODECBUSY_RD() ^  (v)))
#endif


/*
 * constants & macros for individual VPU_BITCODECBUSY bitfields
 */

/* --- Register HW_VPU_BITCODECBUSY, field CODECBUSY */

#define BP_VPU_BITCODECBUSY_CODECBUSY      0
#define BM_VPU_BITCODECBUSY_CODECBUSY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_VPU_BITCODECBUSY_CODECBUSY(v)   ((((reg32_t) v) << 0) & BM_VPU_BITCODECBUSY_CODECBUSY)
#else
#define BF_VPU_BITCODECBUSY_CODECBUSY(v)   (((v) << 0) & BM_VPU_BITCODECBUSY_CODECBUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_VPU_BITCODECBUSY_CODECBUSY(v)   BF_CS1(VPU_BITCODECBUSY, CODECBUSY, v)
#endif


#endif // _VPU_H

