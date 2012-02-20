/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ASRC_H
#define _ASRC_H

#include "regs.h"

#ifndef REGS_ASRC_BASE
#define REGS_ASRC_BASE (REGS_BASE + 0x02034000)

#endif


/*
 * HW_ASRC_ASRCTR - ASRC Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ASDBG : 1;
        unsigned RESERVED1 : 1;
        unsigned ATSC : 1;
        unsigned ATSB : 1;
        unsigned ATSA : 1;
        unsigned SD1R0 : 1;
        unsigned RESERVED2 : 1;
        unsigned USRC : 1;
        unsigned IDRC : 1;
        unsigned USRB : 1;
        unsigned IDRB : 1;
        unsigned USRA : 1;
        unsigned IDRA : 1;
        unsigned SHIRC : 1;
        unsigned SHIRB : 1;
        unsigned SHIRA : 1;
        unsigned WINDC : 1;
        unsigned WINDB : 1;
        unsigned WINDA : 1;
        unsigned RESERVED3 : 2;
        unsigned RESERVED4 : 8;
        unsigned SRST : 1;
        unsigned ASREC : 1;
        unsigned ASREB : 1;
        unsigned ASREA : 1;
        unsigned ASRCEN : 1;

    } B;
} hw_asrc_asrctr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCTR register
 */
#define HW_ASRC_ASRCTR_ADDR      (REGS_ASRC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCTR           (*(volatile hw_asrc_asrctr_t *) HW_ASRC_ASRCTR_ADDR)
#define HW_ASRC_ASRCTR_RD()      (HW_ASRC_ASRCTR.U)
#define HW_ASRC_ASRCTR_WR(v)     (HW_ASRC_ASRCTR.U = (v))
#define HW_ASRC_ASRCTR_SET(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() |  (v)))
#define HW_ASRC_ASRCTR_CLR(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() & ~(v)))
#define HW_ASRC_ASRCTR_TOG(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCTR bitfields
 */

/* --- Register HW_ASRC_ASRCTR, field ASDBG */

#define BP_ASRC_ASRCTR_ASDBG      23
#define BM_ASRC_ASRCTR_ASDBG      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ASDBG(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRCTR_ASDBG)
#else
#define BF_ASRC_ASRCTR_ASDBG(v)   (((v) << 23) & BM_ASRC_ASRCTR_ASDBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ASDBG(v)   BF_CS1(ASRC_ASRCTR, ASDBG, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSC */

#define BP_ASRC_ASRCTR_ATSC      22
#define BM_ASRC_ASRCTR_ATSC      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ATSC(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRCTR_ATSC)
#else
#define BF_ASRC_ASRCTR_ATSC(v)   (((v) << 22) & BM_ASRC_ASRCTR_ATSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ATSC(v)   BF_CS1(ASRC_ASRCTR, ATSC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSB */

#define BP_ASRC_ASRCTR_ATSB      21
#define BM_ASRC_ASRCTR_ATSB      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ATSB(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRCTR_ATSB)
#else
#define BF_ASRC_ASRCTR_ATSB(v)   (((v) << 21) & BM_ASRC_ASRCTR_ATSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ATSB(v)   BF_CS1(ASRC_ASRCTR, ATSB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSA */

#define BP_ASRC_ASRCTR_ATSA      20
#define BM_ASRC_ASRCTR_ATSA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ATSA(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRCTR_ATSA)
#else
#define BF_ASRC_ASRCTR_ATSA(v)   (((v) << 20) & BM_ASRC_ASRCTR_ATSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ATSA(v)   BF_CS1(ASRC_ASRCTR, ATSA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field SD1R0 */

#define BP_ASRC_ASRCTR_SD1R0      19
#define BM_ASRC_ASRCTR_SD1R0      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_SD1R0(v)   ((((reg32_t) v) << 19) & BM_ASRC_ASRCTR_SD1R0)
#else
#define BF_ASRC_ASRCTR_SD1R0(v)   (((v) << 19) & BM_ASRC_ASRCTR_SD1R0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_SD1R0(v)   BF_CS1(ASRC_ASRCTR, SD1R0, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field USRC */

#define BP_ASRC_ASRCTR_USRC      18
#define BM_ASRC_ASRCTR_USRC      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_USRC(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRCTR_USRC)
#else
#define BF_ASRC_ASRCTR_USRC(v)   (((v) << 18) & BM_ASRC_ASRCTR_USRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_USRC(v)   BF_CS1(ASRC_ASRCTR, USRC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field IDRC */

#define BP_ASRC_ASRCTR_IDRC      17
#define BM_ASRC_ASRCTR_IDRC      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_IDRC(v)   ((((reg32_t) v) << 17) & BM_ASRC_ASRCTR_IDRC)
#else
#define BF_ASRC_ASRCTR_IDRC(v)   (((v) << 17) & BM_ASRC_ASRCTR_IDRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_IDRC(v)   BF_CS1(ASRC_ASRCTR, IDRC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field USRB */

#define BP_ASRC_ASRCTR_USRB      16
#define BM_ASRC_ASRCTR_USRB      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_USRB(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRCTR_USRB)
#else
#define BF_ASRC_ASRCTR_USRB(v)   (((v) << 16) & BM_ASRC_ASRCTR_USRB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_USRB(v)   BF_CS1(ASRC_ASRCTR, USRB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field IDRB */

#define BP_ASRC_ASRCTR_IDRB      15
#define BM_ASRC_ASRCTR_IDRB      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_IDRB(v)   ((((reg32_t) v) << 15) & BM_ASRC_ASRCTR_IDRB)
#else
#define BF_ASRC_ASRCTR_IDRB(v)   (((v) << 15) & BM_ASRC_ASRCTR_IDRB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_IDRB(v)   BF_CS1(ASRC_ASRCTR, IDRB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field USRA */

#define BP_ASRC_ASRCTR_USRA      14
#define BM_ASRC_ASRCTR_USRA      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_USRA(v)   ((((reg32_t) v) << 14) & BM_ASRC_ASRCTR_USRA)
#else
#define BF_ASRC_ASRCTR_USRA(v)   (((v) << 14) & BM_ASRC_ASRCTR_USRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_USRA(v)   BF_CS1(ASRC_ASRCTR, USRA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field IDRA */

#define BP_ASRC_ASRCTR_IDRA      13
#define BM_ASRC_ASRCTR_IDRA      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_IDRA(v)   ((((reg32_t) v) << 13) & BM_ASRC_ASRCTR_IDRA)
#else
#define BF_ASRC_ASRCTR_IDRA(v)   (((v) << 13) & BM_ASRC_ASRCTR_IDRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_IDRA(v)   BF_CS1(ASRC_ASRCTR, IDRA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field SHIRC */

#define BP_ASRC_ASRCTR_SHIRC      12
#define BM_ASRC_ASRCTR_SHIRC      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_SHIRC(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRCTR_SHIRC)
#else
#define BF_ASRC_ASRCTR_SHIRC(v)   (((v) << 12) & BM_ASRC_ASRCTR_SHIRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_SHIRC(v)   BF_CS1(ASRC_ASRCTR, SHIRC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field SHIRB */

#define BP_ASRC_ASRCTR_SHIRB      11
#define BM_ASRC_ASRCTR_SHIRB      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_SHIRB(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRCTR_SHIRB)
#else
#define BF_ASRC_ASRCTR_SHIRB(v)   (((v) << 11) & BM_ASRC_ASRCTR_SHIRB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_SHIRB(v)   BF_CS1(ASRC_ASRCTR, SHIRB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field SHIRA */

#define BP_ASRC_ASRCTR_SHIRA      10
#define BM_ASRC_ASRCTR_SHIRA      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_SHIRA(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRCTR_SHIRA)
#else
#define BF_ASRC_ASRCTR_SHIRA(v)   (((v) << 10) & BM_ASRC_ASRCTR_SHIRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_SHIRA(v)   BF_CS1(ASRC_ASRCTR, SHIRA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field WINDC */

#define BP_ASRC_ASRCTR_WINDC      9
#define BM_ASRC_ASRCTR_WINDC      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_WINDC(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRCTR_WINDC)
#else
#define BF_ASRC_ASRCTR_WINDC(v)   (((v) << 9) & BM_ASRC_ASRCTR_WINDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_WINDC(v)   BF_CS1(ASRC_ASRCTR, WINDC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field WINDB */

#define BP_ASRC_ASRCTR_WINDB      8
#define BM_ASRC_ASRCTR_WINDB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_WINDB(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRCTR_WINDB)
#else
#define BF_ASRC_ASRCTR_WINDB(v)   (((v) << 8) & BM_ASRC_ASRCTR_WINDB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_WINDB(v)   BF_CS1(ASRC_ASRCTR, WINDB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field WINDA */

#define BP_ASRC_ASRCTR_WINDA      7
#define BM_ASRC_ASRCTR_WINDA      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_WINDA(v)   ((((reg32_t) v) << 7) & BM_ASRC_ASRCTR_WINDA)
#else
#define BF_ASRC_ASRCTR_WINDA(v)   (((v) << 7) & BM_ASRC_ASRCTR_WINDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_WINDA(v)   BF_CS1(ASRC_ASRCTR, WINDA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field SRST */

#define BP_ASRC_ASRCTR_SRST      4
#define BM_ASRC_ASRCTR_SRST      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_SRST(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRCTR_SRST)
#else
#define BF_ASRC_ASRCTR_SRST(v)   (((v) << 4) & BM_ASRC_ASRCTR_SRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_SRST(v)   BF_CS1(ASRC_ASRCTR, SRST, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREC */

#define BP_ASRC_ASRCTR_ASREC      3
#define BM_ASRC_ASRCTR_ASREC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ASREC(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRCTR_ASREC)
#else
#define BF_ASRC_ASRCTR_ASREC(v)   (((v) << 3) & BM_ASRC_ASRCTR_ASREC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ASREC(v)   BF_CS1(ASRC_ASRCTR, ASREC, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREB */

#define BP_ASRC_ASRCTR_ASREB      2
#define BM_ASRC_ASRCTR_ASREB      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ASREB(v)   ((((reg32_t) v) << 2) & BM_ASRC_ASRCTR_ASREB)
#else
#define BF_ASRC_ASRCTR_ASREB(v)   (((v) << 2) & BM_ASRC_ASRCTR_ASREB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ASREB(v)   BF_CS1(ASRC_ASRCTR, ASREB, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREA */

#define BP_ASRC_ASRCTR_ASREA      1
#define BM_ASRC_ASRCTR_ASREA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ASREA(v)   ((((reg32_t) v) << 1) & BM_ASRC_ASRCTR_ASREA)
#else
#define BF_ASRC_ASRCTR_ASREA(v)   (((v) << 1) & BM_ASRC_ASRCTR_ASREA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ASREA(v)   BF_CS1(ASRC_ASRCTR, ASREA, v)
#endif

/* --- Register HW_ASRC_ASRCTR, field ASRCEN */

#define BP_ASRC_ASRCTR_ASRCEN      0
#define BM_ASRC_ASRCTR_ASRCEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCTR_ASRCEN(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCTR_ASRCEN)
#else
#define BF_ASRC_ASRCTR_ASRCEN(v)   (((v) << 0) & BM_ASRC_ASRCTR_ASRCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCTR_ASRCEN(v)   BF_CS1(ASRC_ASRCTR, ASRCEN, v)
#endif

/*
 * HW_ASRC_ASRIER - ASRC Interrupt Enable Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 16;
        unsigned AFPWE : 1;
        unsigned AOLIE : 1;
        unsigned ADOEC : 1;
        unsigned ADOEB : 1;
        unsigned ADOEA : 1;
        unsigned ADIEC : 1;
        unsigned ADIEB : 1;
        unsigned ADIEA : 1;

    } B;
} hw_asrc_asrier_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIER register
 */
#define HW_ASRC_ASRIER_ADDR      (REGS_ASRC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIER           (*(volatile hw_asrc_asrier_t *) HW_ASRC_ASRIER_ADDR)
#define HW_ASRC_ASRIER_RD()      (HW_ASRC_ASRIER.U)
#define HW_ASRC_ASRIER_WR(v)     (HW_ASRC_ASRIER.U = (v))
#define HW_ASRC_ASRIER_SET(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() |  (v)))
#define HW_ASRC_ASRIER_CLR(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() & ~(v)))
#define HW_ASRC_ASRIER_TOG(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIER bitfields
 */

/* --- Register HW_ASRC_ASRIER, field AFPWE */

#define BP_ASRC_ASRIER_AFPWE      7
#define BM_ASRC_ASRIER_AFPWE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_AFPWE(v)   ((((reg32_t) v) << 7) & BM_ASRC_ASRIER_AFPWE)
#else
#define BF_ASRC_ASRIER_AFPWE(v)   (((v) << 7) & BM_ASRC_ASRIER_AFPWE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_AFPWE(v)   BF_CS1(ASRC_ASRIER, AFPWE, v)
#endif

/* --- Register HW_ASRC_ASRIER, field AOLIE */

#define BP_ASRC_ASRIER_AOLIE      6
#define BM_ASRC_ASRIER_AOLIE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_AOLIE(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRIER_AOLIE)
#else
#define BF_ASRC_ASRIER_AOLIE(v)   (((v) << 6) & BM_ASRC_ASRIER_AOLIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_AOLIE(v)   BF_CS1(ASRC_ASRIER, AOLIE, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADOEC */

#define BP_ASRC_ASRIER_ADOEC      5
#define BM_ASRC_ASRIER_ADOEC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADOEC(v)   ((((reg32_t) v) << 5) & BM_ASRC_ASRIER_ADOEC)
#else
#define BF_ASRC_ASRIER_ADOEC(v)   (((v) << 5) & BM_ASRC_ASRIER_ADOEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADOEC(v)   BF_CS1(ASRC_ASRIER, ADOEC, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADOEB */

#define BP_ASRC_ASRIER_ADOEB      4
#define BM_ASRC_ASRIER_ADOEB      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADOEB(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRIER_ADOEB)
#else
#define BF_ASRC_ASRIER_ADOEB(v)   (((v) << 4) & BM_ASRC_ASRIER_ADOEB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADOEB(v)   BF_CS1(ASRC_ASRIER, ADOEB, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADOEA */

#define BP_ASRC_ASRIER_ADOEA      3
#define BM_ASRC_ASRIER_ADOEA      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADOEA(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRIER_ADOEA)
#else
#define BF_ASRC_ASRIER_ADOEA(v)   (((v) << 3) & BM_ASRC_ASRIER_ADOEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADOEA(v)   BF_CS1(ASRC_ASRIER, ADOEA, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADIEC */

#define BP_ASRC_ASRIER_ADIEC      2
#define BM_ASRC_ASRIER_ADIEC      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADIEC(v)   ((((reg32_t) v) << 2) & BM_ASRC_ASRIER_ADIEC)
#else
#define BF_ASRC_ASRIER_ADIEC(v)   (((v) << 2) & BM_ASRC_ASRIER_ADIEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADIEC(v)   BF_CS1(ASRC_ASRIER, ADIEC, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADIEB */

#define BP_ASRC_ASRIER_ADIEB      1
#define BM_ASRC_ASRIER_ADIEB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADIEB(v)   ((((reg32_t) v) << 1) & BM_ASRC_ASRIER_ADIEB)
#else
#define BF_ASRC_ASRIER_ADIEB(v)   (((v) << 1) & BM_ASRC_ASRIER_ADIEB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADIEB(v)   BF_CS1(ASRC_ASRIER, ADIEB, v)
#endif

/* --- Register HW_ASRC_ASRIER, field ADIEA */

#define BP_ASRC_ASRIER_ADIEA      0
#define BM_ASRC_ASRIER_ADIEA      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIER_ADIEA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIER_ADIEA)
#else
#define BF_ASRC_ASRIER_ADIEA(v)   (((v) << 0) & BM_ASRC_ASRIER_ADIEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIER_ADIEA(v)   BF_CS1(ASRC_ASRIER, ADIEA, v)
#endif

/*
 * HW_ASRC_ASRCNCR - ASRC Channel Number Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 15;
        unsigned ANCC : 3;
        unsigned ANCB : 3;
        unsigned ANCA : 3;

    } B;
} hw_asrc_asrcncr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCNCR register
 */
#define HW_ASRC_ASRCNCR_ADDR      (REGS_ASRC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCNCR           (*(volatile hw_asrc_asrcncr_t *) HW_ASRC_ASRCNCR_ADDR)
#define HW_ASRC_ASRCNCR_RD()      (HW_ASRC_ASRCNCR.U)
#define HW_ASRC_ASRCNCR_WR(v)     (HW_ASRC_ASRCNCR.U = (v))
#define HW_ASRC_ASRCNCR_SET(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() |  (v)))
#define HW_ASRC_ASRCNCR_CLR(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() & ~(v)))
#define HW_ASRC_ASRCNCR_TOG(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCNCR bitfields
 */

/* --- Register HW_ASRC_ASRCNCR, field ANCC */

#define BP_ASRC_ASRCNCR_ANCC      6
#define BM_ASRC_ASRCNCR_ANCC      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCNCR_ANCC(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRCNCR_ANCC)
#else
#define BF_ASRC_ASRCNCR_ANCC(v)   (((v) << 6) & BM_ASRC_ASRCNCR_ANCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCNCR_ANCC(v)   BF_CS1(ASRC_ASRCNCR, ANCC, v)
#endif

/* --- Register HW_ASRC_ASRCNCR, field ANCB */

#define BP_ASRC_ASRCNCR_ANCB      3
#define BM_ASRC_ASRCNCR_ANCB      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCNCR_ANCB(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRCNCR_ANCB)
#else
#define BF_ASRC_ASRCNCR_ANCB(v)   (((v) << 3) & BM_ASRC_ASRCNCR_ANCB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCNCR_ANCB(v)   BF_CS1(ASRC_ASRCNCR, ANCB, v)
#endif

/* --- Register HW_ASRC_ASRCNCR, field ANCA */

#define BP_ASRC_ASRCNCR_ANCA      0
#define BM_ASRC_ASRCNCR_ANCA      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCNCR_ANCA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCNCR_ANCA)
#else
#define BF_ASRC_ASRCNCR_ANCA(v)   (((v) << 0) & BM_ASRC_ASRCNCR_ANCA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCNCR_ANCA(v)   BF_CS1(ASRC_ASRCNCR, ANCA, v)
#endif

/*
 * HW_ASRC_ASRCFG - ASRC Filter Configuration Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned INIRQC : 1;
        unsigned INIRQB : 1;
        unsigned INIRQA : 1;
        unsigned NDPRC : 1;
        unsigned NDPRB : 1;
        unsigned NDPRA : 1;
        unsigned POSTMODC : 2;
        unsigned PREMODC : 2;
        unsigned POSTMODB : 2;
        unsigned PREMODB : 2;
        unsigned POSTMODA : 2;
        unsigned PREMODA : 2;
        unsigned HFC : 2;
        unsigned HFB : 2;
        unsigned HFA : 2;
        unsigned RESERVED1 : 6;

    } B;
} hw_asrc_asrcfg_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCFG register
 */
#define HW_ASRC_ASRCFG_ADDR      (REGS_ASRC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCFG           (*(volatile hw_asrc_asrcfg_t *) HW_ASRC_ASRCFG_ADDR)
#define HW_ASRC_ASRCFG_RD()      (HW_ASRC_ASRCFG.U)
#define HW_ASRC_ASRCFG_WR(v)     (HW_ASRC_ASRCFG.U = (v))
#define HW_ASRC_ASRCFG_SET(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() |  (v)))
#define HW_ASRC_ASRCFG_CLR(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() & ~(v)))
#define HW_ASRC_ASRCFG_TOG(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCFG bitfields
 */

/* --- Register HW_ASRC_ASRCFG, field INIRQC */

#define BP_ASRC_ASRCFG_INIRQC      23
#define BM_ASRC_ASRCFG_INIRQC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_INIRQC(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRCFG_INIRQC)
#else
#define BF_ASRC_ASRCFG_INIRQC(v)   (((v) << 23) & BM_ASRC_ASRCFG_INIRQC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_INIRQC(v)   BF_CS1(ASRC_ASRCFG, INIRQC, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field INIRQB */

#define BP_ASRC_ASRCFG_INIRQB      22
#define BM_ASRC_ASRCFG_INIRQB      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_INIRQB(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRCFG_INIRQB)
#else
#define BF_ASRC_ASRCFG_INIRQB(v)   (((v) << 22) & BM_ASRC_ASRCFG_INIRQB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_INIRQB(v)   BF_CS1(ASRC_ASRCFG, INIRQB, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field INIRQA */

#define BP_ASRC_ASRCFG_INIRQA      21
#define BM_ASRC_ASRCFG_INIRQA      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_INIRQA(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRCFG_INIRQA)
#else
#define BF_ASRC_ASRCFG_INIRQA(v)   (((v) << 21) & BM_ASRC_ASRCFG_INIRQA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_INIRQA(v)   BF_CS1(ASRC_ASRCFG, INIRQA, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field NDPRC */

#define BP_ASRC_ASRCFG_NDPRC      20
#define BM_ASRC_ASRCFG_NDPRC      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_NDPRC(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRCFG_NDPRC)
#else
#define BF_ASRC_ASRCFG_NDPRC(v)   (((v) << 20) & BM_ASRC_ASRCFG_NDPRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_NDPRC(v)   BF_CS1(ASRC_ASRCFG, NDPRC, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field NDPRB */

#define BP_ASRC_ASRCFG_NDPRB      19
#define BM_ASRC_ASRCFG_NDPRB      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_NDPRB(v)   ((((reg32_t) v) << 19) & BM_ASRC_ASRCFG_NDPRB)
#else
#define BF_ASRC_ASRCFG_NDPRB(v)   (((v) << 19) & BM_ASRC_ASRCFG_NDPRB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_NDPRB(v)   BF_CS1(ASRC_ASRCFG, NDPRB, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field NDPRA */

#define BP_ASRC_ASRCFG_NDPRA      18
#define BM_ASRC_ASRCFG_NDPRA      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_NDPRA(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRCFG_NDPRA)
#else
#define BF_ASRC_ASRCFG_NDPRA(v)   (((v) << 18) & BM_ASRC_ASRCFG_NDPRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_NDPRA(v)   BF_CS1(ASRC_ASRCFG, NDPRA, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field POSTMODC */

#define BP_ASRC_ASRCFG_POSTMODC      16
#define BM_ASRC_ASRCFG_POSTMODC      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_POSTMODC(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRCFG_POSTMODC)
#else
#define BF_ASRC_ASRCFG_POSTMODC(v)   (((v) << 16) & BM_ASRC_ASRCFG_POSTMODC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_POSTMODC(v)   BF_CS1(ASRC_ASRCFG, POSTMODC, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field PREMODC */

#define BP_ASRC_ASRCFG_PREMODC      14
#define BM_ASRC_ASRCFG_PREMODC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_PREMODC(v)   ((((reg32_t) v) << 14) & BM_ASRC_ASRCFG_PREMODC)
#else
#define BF_ASRC_ASRCFG_PREMODC(v)   (((v) << 14) & BM_ASRC_ASRCFG_PREMODC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_PREMODC(v)   BF_CS1(ASRC_ASRCFG, PREMODC, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field POSTMODB */

#define BP_ASRC_ASRCFG_POSTMODB      12
#define BM_ASRC_ASRCFG_POSTMODB      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_POSTMODB(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRCFG_POSTMODB)
#else
#define BF_ASRC_ASRCFG_POSTMODB(v)   (((v) << 12) & BM_ASRC_ASRCFG_POSTMODB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_POSTMODB(v)   BF_CS1(ASRC_ASRCFG, POSTMODB, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field PREMODB */

#define BP_ASRC_ASRCFG_PREMODB      10
#define BM_ASRC_ASRCFG_PREMODB      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_PREMODB(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRCFG_PREMODB)
#else
#define BF_ASRC_ASRCFG_PREMODB(v)   (((v) << 10) & BM_ASRC_ASRCFG_PREMODB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_PREMODB(v)   BF_CS1(ASRC_ASRCFG, PREMODB, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field POSTMODA */

#define BP_ASRC_ASRCFG_POSTMODA      8
#define BM_ASRC_ASRCFG_POSTMODA      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_POSTMODA(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRCFG_POSTMODA)
#else
#define BF_ASRC_ASRCFG_POSTMODA(v)   (((v) << 8) & BM_ASRC_ASRCFG_POSTMODA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_POSTMODA(v)   BF_CS1(ASRC_ASRCFG, POSTMODA, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field PREMODA */

#define BP_ASRC_ASRCFG_PREMODA      6
#define BM_ASRC_ASRCFG_PREMODA      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_PREMODA(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRCFG_PREMODA)
#else
#define BF_ASRC_ASRCFG_PREMODA(v)   (((v) << 6) & BM_ASRC_ASRCFG_PREMODA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_PREMODA(v)   BF_CS1(ASRC_ASRCFG, PREMODA, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field HFC */

#define BP_ASRC_ASRCFG_HFC      4
#define BM_ASRC_ASRCFG_HFC      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_HFC(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRCFG_HFC)
#else
#define BF_ASRC_ASRCFG_HFC(v)   (((v) << 4) & BM_ASRC_ASRCFG_HFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_HFC(v)   BF_CS1(ASRC_ASRCFG, HFC, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field HFB */

#define BP_ASRC_ASRCFG_HFB      2
#define BM_ASRC_ASRCFG_HFB      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_HFB(v)   ((((reg32_t) v) << 2) & BM_ASRC_ASRCFG_HFB)
#else
#define BF_ASRC_ASRCFG_HFB(v)   (((v) << 2) & BM_ASRC_ASRCFG_HFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_HFB(v)   BF_CS1(ASRC_ASRCFG, HFB, v)
#endif

/* --- Register HW_ASRC_ASRCFG, field HFA */

#define BP_ASRC_ASRCFG_HFA      0
#define BM_ASRC_ASRCFG_HFA      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCFG_HFA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCFG_HFA)
#else
#define BF_ASRC_ASRCFG_HFA(v)   (((v) << 0) & BM_ASRC_ASRCFG_HFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCFG_HFA(v)   BF_CS1(ASRC_ASRCFG, HFA, v)
#endif

/*
 * HW_ASRC_ASRCSR - ASRC Clock Source Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned AOCSC : 4;
        unsigned AOCSB : 4;
        unsigned AOCSA : 4;
        unsigned AICSC : 4;
        unsigned AICSB : 4;
        unsigned AICSA : 4;

    } B;
} hw_asrc_asrcsr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCSR register
 */
#define HW_ASRC_ASRCSR_ADDR      (REGS_ASRC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCSR           (*(volatile hw_asrc_asrcsr_t *) HW_ASRC_ASRCSR_ADDR)
#define HW_ASRC_ASRCSR_RD()      (HW_ASRC_ASRCSR.U)
#define HW_ASRC_ASRCSR_WR(v)     (HW_ASRC_ASRCSR.U = (v))
#define HW_ASRC_ASRCSR_SET(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() |  (v)))
#define HW_ASRC_ASRCSR_CLR(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() & ~(v)))
#define HW_ASRC_ASRCSR_TOG(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCSR bitfields
 */

/* --- Register HW_ASRC_ASRCSR, field AOCSC */

#define BP_ASRC_ASRCSR_AOCSC      20
#define BM_ASRC_ASRCSR_AOCSC      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AOCSC(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRCSR_AOCSC)
#else
#define BF_ASRC_ASRCSR_AOCSC(v)   (((v) << 20) & BM_ASRC_ASRCSR_AOCSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AOCSC(v)   BF_CS1(ASRC_ASRCSR, AOCSC, v)
#endif

/* --- Register HW_ASRC_ASRCSR, field AOCSB */

#define BP_ASRC_ASRCSR_AOCSB      16
#define BM_ASRC_ASRCSR_AOCSB      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AOCSB(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRCSR_AOCSB)
#else
#define BF_ASRC_ASRCSR_AOCSB(v)   (((v) << 16) & BM_ASRC_ASRCSR_AOCSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AOCSB(v)   BF_CS1(ASRC_ASRCSR, AOCSB, v)
#endif

/* --- Register HW_ASRC_ASRCSR, field AOCSA */

#define BP_ASRC_ASRCSR_AOCSA      12
#define BM_ASRC_ASRCSR_AOCSA      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AOCSA(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRCSR_AOCSA)
#else
#define BF_ASRC_ASRCSR_AOCSA(v)   (((v) << 12) & BM_ASRC_ASRCSR_AOCSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AOCSA(v)   BF_CS1(ASRC_ASRCSR, AOCSA, v)
#endif

/* --- Register HW_ASRC_ASRCSR, field AICSC */

#define BP_ASRC_ASRCSR_AICSC      8
#define BM_ASRC_ASRCSR_AICSC      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AICSC(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRCSR_AICSC)
#else
#define BF_ASRC_ASRCSR_AICSC(v)   (((v) << 8) & BM_ASRC_ASRCSR_AICSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AICSC(v)   BF_CS1(ASRC_ASRCSR, AICSC, v)
#endif

/* --- Register HW_ASRC_ASRCSR, field AICSB */

#define BP_ASRC_ASRCSR_AICSB      4
#define BM_ASRC_ASRCSR_AICSB      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AICSB(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRCSR_AICSB)
#else
#define BF_ASRC_ASRCSR_AICSB(v)   (((v) << 4) & BM_ASRC_ASRCSR_AICSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AICSB(v)   BF_CS1(ASRC_ASRCSR, AICSB, v)
#endif

/* --- Register HW_ASRC_ASRCSR, field AICSA */

#define BP_ASRC_ASRCSR_AICSA      0
#define BM_ASRC_ASRCSR_AICSA      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCSR_AICSA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCSR_AICSA)
#else
#define BF_ASRC_ASRCSR_AICSA(v)   (((v) << 0) & BM_ASRC_ASRCSR_AICSA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCSR_AICSA(v)   BF_CS1(ASRC_ASRCSR, AICSA, v)
#endif

/*
 * HW_ASRC_ASRCDR1 - ASRC Clock Divider Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned AOCDB : 3;
        unsigned AOCPB : 3;
        unsigned AOCDA : 3;
        unsigned AOCPA : 3;
        unsigned AICDB : 3;
        unsigned AICPB : 3;
        unsigned AICDA : 3;
        unsigned AICPA : 3;

    } B;
} hw_asrc_asrcdr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCDR1 register
 */
#define HW_ASRC_ASRCDR1_ADDR      (REGS_ASRC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCDR1           (*(volatile hw_asrc_asrcdr1_t *) HW_ASRC_ASRCDR1_ADDR)
#define HW_ASRC_ASRCDR1_RD()      (HW_ASRC_ASRCDR1.U)
#define HW_ASRC_ASRCDR1_WR(v)     (HW_ASRC_ASRCDR1.U = (v))
#define HW_ASRC_ASRCDR1_SET(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() |  (v)))
#define HW_ASRC_ASRCDR1_CLR(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() & ~(v)))
#define HW_ASRC_ASRCDR1_TOG(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCDR1 bitfields
 */

/* --- Register HW_ASRC_ASRCDR1, field AOCDB */

#define BP_ASRC_ASRCDR1_AOCDB      21
#define BM_ASRC_ASRCDR1_AOCDB      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AOCDB(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRCDR1_AOCDB)
#else
#define BF_ASRC_ASRCDR1_AOCDB(v)   (((v) << 21) & BM_ASRC_ASRCDR1_AOCDB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AOCDB(v)   BF_CS1(ASRC_ASRCDR1, AOCDB, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCPB */

#define BP_ASRC_ASRCDR1_AOCPB      18
#define BM_ASRC_ASRCDR1_AOCPB      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AOCPB(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRCDR1_AOCPB)
#else
#define BF_ASRC_ASRCDR1_AOCPB(v)   (((v) << 18) & BM_ASRC_ASRCDR1_AOCPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AOCPB(v)   BF_CS1(ASRC_ASRCDR1, AOCPB, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCDA */

#define BP_ASRC_ASRCDR1_AOCDA      15
#define BM_ASRC_ASRCDR1_AOCDA      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AOCDA(v)   ((((reg32_t) v) << 15) & BM_ASRC_ASRCDR1_AOCDA)
#else
#define BF_ASRC_ASRCDR1_AOCDA(v)   (((v) << 15) & BM_ASRC_ASRCDR1_AOCDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AOCDA(v)   BF_CS1(ASRC_ASRCDR1, AOCDA, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCPA */

#define BP_ASRC_ASRCDR1_AOCPA      12
#define BM_ASRC_ASRCDR1_AOCPA      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AOCPA(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRCDR1_AOCPA)
#else
#define BF_ASRC_ASRCDR1_AOCPA(v)   (((v) << 12) & BM_ASRC_ASRCDR1_AOCPA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AOCPA(v)   BF_CS1(ASRC_ASRCDR1, AOCPA, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICDB */

#define BP_ASRC_ASRCDR1_AICDB      9
#define BM_ASRC_ASRCDR1_AICDB      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AICDB(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRCDR1_AICDB)
#else
#define BF_ASRC_ASRCDR1_AICDB(v)   (((v) << 9) & BM_ASRC_ASRCDR1_AICDB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AICDB(v)   BF_CS1(ASRC_ASRCDR1, AICDB, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICPB */

#define BP_ASRC_ASRCDR1_AICPB      6
#define BM_ASRC_ASRCDR1_AICPB      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AICPB(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRCDR1_AICPB)
#else
#define BF_ASRC_ASRCDR1_AICPB(v)   (((v) << 6) & BM_ASRC_ASRCDR1_AICPB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AICPB(v)   BF_CS1(ASRC_ASRCDR1, AICPB, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICDA */

#define BP_ASRC_ASRCDR1_AICDA      3
#define BM_ASRC_ASRCDR1_AICDA      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AICDA(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRCDR1_AICDA)
#else
#define BF_ASRC_ASRCDR1_AICDA(v)   (((v) << 3) & BM_ASRC_ASRCDR1_AICDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AICDA(v)   BF_CS1(ASRC_ASRCDR1, AICDA, v)
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICPA */

#define BP_ASRC_ASRCDR1_AICPA      0
#define BM_ASRC_ASRCDR1_AICPA      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR1_AICPA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCDR1_AICPA)
#else
#define BF_ASRC_ASRCDR1_AICPA(v)   (((v) << 0) & BM_ASRC_ASRCDR1_AICPA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR1_AICPA(v)   BF_CS1(ASRC_ASRCDR1, AICPA, v)
#endif

/*
 * HW_ASRC_ASRCDR2 - ASRC Clock Divider Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 12;
        unsigned AOCDC : 3;
        unsigned AOCPC : 3;
        unsigned AICDC : 3;
        unsigned AICPC : 3;

    } B;
} hw_asrc_asrcdr2_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCDR2 register
 */
#define HW_ASRC_ASRCDR2_ADDR      (REGS_ASRC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCDR2           (*(volatile hw_asrc_asrcdr2_t *) HW_ASRC_ASRCDR2_ADDR)
#define HW_ASRC_ASRCDR2_RD()      (HW_ASRC_ASRCDR2.U)
#define HW_ASRC_ASRCDR2_WR(v)     (HW_ASRC_ASRCDR2.U = (v))
#define HW_ASRC_ASRCDR2_SET(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() |  (v)))
#define HW_ASRC_ASRCDR2_CLR(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() & ~(v)))
#define HW_ASRC_ASRCDR2_TOG(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCDR2 bitfields
 */

/* --- Register HW_ASRC_ASRCDR2, field AOCDC */

#define BP_ASRC_ASRCDR2_AOCDC      9
#define BM_ASRC_ASRCDR2_AOCDC      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR2_AOCDC(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRCDR2_AOCDC)
#else
#define BF_ASRC_ASRCDR2_AOCDC(v)   (((v) << 9) & BM_ASRC_ASRCDR2_AOCDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR2_AOCDC(v)   BF_CS1(ASRC_ASRCDR2, AOCDC, v)
#endif

/* --- Register HW_ASRC_ASRCDR2, field AOCPC */

#define BP_ASRC_ASRCDR2_AOCPC      6
#define BM_ASRC_ASRCDR2_AOCPC      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR2_AOCPC(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRCDR2_AOCPC)
#else
#define BF_ASRC_ASRCDR2_AOCPC(v)   (((v) << 6) & BM_ASRC_ASRCDR2_AOCPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR2_AOCPC(v)   BF_CS1(ASRC_ASRCDR2, AOCPC, v)
#endif

/* --- Register HW_ASRC_ASRCDR2, field AICDC */

#define BP_ASRC_ASRCDR2_AICDC      3
#define BM_ASRC_ASRCDR2_AICDC      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR2_AICDC(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRCDR2_AICDC)
#else
#define BF_ASRC_ASRCDR2_AICDC(v)   (((v) << 3) & BM_ASRC_ASRCDR2_AICDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR2_AICDC(v)   BF_CS1(ASRC_ASRCDR2, AICDC, v)
#endif

/* --- Register HW_ASRC_ASRCDR2, field AICPC */

#define BP_ASRC_ASRCDR2_AICPC      0
#define BM_ASRC_ASRCDR2_AICPC      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCDR2_AICPC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCDR2_AICPC)
#else
#define BF_ASRC_ASRCDR2_AICPC(v)   (((v) << 0) & BM_ASRC_ASRCDR2_AICPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCDR2_AICPC(v)   BF_CS1(ASRC_ASRCDR2, AICPC, v)
#endif

/*
 * HW_ASRC_ASRSTR - ASRC Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 2;
        unsigned DSLCNT : 1;
        unsigned ATQOL : 1;
        unsigned AOOLC : 1;
        unsigned AOOLB : 1;
        unsigned AOOLA : 1;
        unsigned AIOLC : 1;
        unsigned AIOLB : 1;
        unsigned AIOLA : 1;
        unsigned AODOC : 1;
        unsigned AODOB : 1;
        unsigned AODOA : 1;
        unsigned AIDUC : 1;
        unsigned AIDUB : 1;
        unsigned AIDUA : 1;
        unsigned FPWT : 1;
        unsigned AOLE : 1;
        unsigned AODFC : 1;
        unsigned AODFB : 1;
        unsigned AODFA : 1;
        unsigned AIDEC : 1;
        unsigned AIDEB : 1;
        unsigned AIDEA : 1;

    } B;
} hw_asrc_asrstr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRSTR register
 */
#define HW_ASRC_ASRSTR_ADDR      (REGS_ASRC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRSTR           (*(volatile hw_asrc_asrstr_t *) HW_ASRC_ASRSTR_ADDR)
#define HW_ASRC_ASRSTR_RD()      (HW_ASRC_ASRSTR.U)
#define HW_ASRC_ASRSTR_WR(v)     (HW_ASRC_ASRSTR.U = (v))
#define HW_ASRC_ASRSTR_SET(v)    (HW_ASRC_ASRSTR_WR(HW_ASRC_ASRSTR_RD() |  (v)))
#define HW_ASRC_ASRSTR_CLR(v)    (HW_ASRC_ASRSTR_WR(HW_ASRC_ASRSTR_RD() & ~(v)))
#define HW_ASRC_ASRSTR_TOG(v)    (HW_ASRC_ASRSTR_WR(HW_ASRC_ASRSTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRSTR bitfields
 */

/* --- Register HW_ASRC_ASRSTR, field DSLCNT */

#define BP_ASRC_ASRSTR_DSLCNT      21
#define BM_ASRC_ASRSTR_DSLCNT      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_DSLCNT(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRSTR_DSLCNT)
#else
#define BF_ASRC_ASRSTR_DSLCNT(v)   (((v) << 21) & BM_ASRC_ASRSTR_DSLCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_DSLCNT(v)   BF_CS1(ASRC_ASRSTR, DSLCNT, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field ATQOL */

#define BP_ASRC_ASRSTR_ATQOL      20
#define BM_ASRC_ASRSTR_ATQOL      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_ATQOL(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRSTR_ATQOL)
#else
#define BF_ASRC_ASRSTR_ATQOL(v)   (((v) << 20) & BM_ASRC_ASRSTR_ATQOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_ATQOL(v)   BF_CS1(ASRC_ASRSTR, ATQOL, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AOOLC */

#define BP_ASRC_ASRSTR_AOOLC      19
#define BM_ASRC_ASRSTR_AOOLC      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AOOLC(v)   ((((reg32_t) v) << 19) & BM_ASRC_ASRSTR_AOOLC)
#else
#define BF_ASRC_ASRSTR_AOOLC(v)   (((v) << 19) & BM_ASRC_ASRSTR_AOOLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AOOLC(v)   BF_CS1(ASRC_ASRSTR, AOOLC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AOOLB */

#define BP_ASRC_ASRSTR_AOOLB      18
#define BM_ASRC_ASRSTR_AOOLB      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AOOLB(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRSTR_AOOLB)
#else
#define BF_ASRC_ASRSTR_AOOLB(v)   (((v) << 18) & BM_ASRC_ASRSTR_AOOLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AOOLB(v)   BF_CS1(ASRC_ASRSTR, AOOLB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AOOLA */

#define BP_ASRC_ASRSTR_AOOLA      17
#define BM_ASRC_ASRSTR_AOOLA      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AOOLA(v)   ((((reg32_t) v) << 17) & BM_ASRC_ASRSTR_AOOLA)
#else
#define BF_ASRC_ASRSTR_AOOLA(v)   (((v) << 17) & BM_ASRC_ASRSTR_AOOLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AOOLA(v)   BF_CS1(ASRC_ASRSTR, AOOLA, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIOLC */

#define BP_ASRC_ASRSTR_AIOLC      16
#define BM_ASRC_ASRSTR_AIOLC      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIOLC(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRSTR_AIOLC)
#else
#define BF_ASRC_ASRSTR_AIOLC(v)   (((v) << 16) & BM_ASRC_ASRSTR_AIOLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIOLC(v)   BF_CS1(ASRC_ASRSTR, AIOLC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIOLB */

#define BP_ASRC_ASRSTR_AIOLB      15
#define BM_ASRC_ASRSTR_AIOLB      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIOLB(v)   ((((reg32_t) v) << 15) & BM_ASRC_ASRSTR_AIOLB)
#else
#define BF_ASRC_ASRSTR_AIOLB(v)   (((v) << 15) & BM_ASRC_ASRSTR_AIOLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIOLB(v)   BF_CS1(ASRC_ASRSTR, AIOLB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIOLA */

#define BP_ASRC_ASRSTR_AIOLA      14
#define BM_ASRC_ASRSTR_AIOLA      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIOLA(v)   ((((reg32_t) v) << 14) & BM_ASRC_ASRSTR_AIOLA)
#else
#define BF_ASRC_ASRSTR_AIOLA(v)   (((v) << 14) & BM_ASRC_ASRSTR_AIOLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIOLA(v)   BF_CS1(ASRC_ASRSTR, AIOLA, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODOC */

#define BP_ASRC_ASRSTR_AODOC      13
#define BM_ASRC_ASRSTR_AODOC      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODOC(v)   ((((reg32_t) v) << 13) & BM_ASRC_ASRSTR_AODOC)
#else
#define BF_ASRC_ASRSTR_AODOC(v)   (((v) << 13) & BM_ASRC_ASRSTR_AODOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODOC(v)   BF_CS1(ASRC_ASRSTR, AODOC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODOB */

#define BP_ASRC_ASRSTR_AODOB      12
#define BM_ASRC_ASRSTR_AODOB      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODOB(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRSTR_AODOB)
#else
#define BF_ASRC_ASRSTR_AODOB(v)   (((v) << 12) & BM_ASRC_ASRSTR_AODOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODOB(v)   BF_CS1(ASRC_ASRSTR, AODOB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODOA */

#define BP_ASRC_ASRSTR_AODOA      11
#define BM_ASRC_ASRSTR_AODOA      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODOA(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRSTR_AODOA)
#else
#define BF_ASRC_ASRSTR_AODOA(v)   (((v) << 11) & BM_ASRC_ASRSTR_AODOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODOA(v)   BF_CS1(ASRC_ASRSTR, AODOA, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDUC */

#define BP_ASRC_ASRSTR_AIDUC      10
#define BM_ASRC_ASRSTR_AIDUC      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDUC(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRSTR_AIDUC)
#else
#define BF_ASRC_ASRSTR_AIDUC(v)   (((v) << 10) & BM_ASRC_ASRSTR_AIDUC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDUC(v)   BF_CS1(ASRC_ASRSTR, AIDUC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDUB */

#define BP_ASRC_ASRSTR_AIDUB      9
#define BM_ASRC_ASRSTR_AIDUB      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDUB(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRSTR_AIDUB)
#else
#define BF_ASRC_ASRSTR_AIDUB(v)   (((v) << 9) & BM_ASRC_ASRSTR_AIDUB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDUB(v)   BF_CS1(ASRC_ASRSTR, AIDUB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDUA */

#define BP_ASRC_ASRSTR_AIDUA      8
#define BM_ASRC_ASRSTR_AIDUA      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDUA(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRSTR_AIDUA)
#else
#define BF_ASRC_ASRSTR_AIDUA(v)   (((v) << 8) & BM_ASRC_ASRSTR_AIDUA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDUA(v)   BF_CS1(ASRC_ASRSTR, AIDUA, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field FPWT */

#define BP_ASRC_ASRSTR_FPWT      7
#define BM_ASRC_ASRSTR_FPWT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_FPWT(v)   ((((reg32_t) v) << 7) & BM_ASRC_ASRSTR_FPWT)
#else
#define BF_ASRC_ASRSTR_FPWT(v)   (((v) << 7) & BM_ASRC_ASRSTR_FPWT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_FPWT(v)   BF_CS1(ASRC_ASRSTR, FPWT, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AOLE */

#define BP_ASRC_ASRSTR_AOLE      6
#define BM_ASRC_ASRSTR_AOLE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AOLE(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRSTR_AOLE)
#else
#define BF_ASRC_ASRSTR_AOLE(v)   (((v) << 6) & BM_ASRC_ASRSTR_AOLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AOLE(v)   BF_CS1(ASRC_ASRSTR, AOLE, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODFC */

#define BP_ASRC_ASRSTR_AODFC      5
#define BM_ASRC_ASRSTR_AODFC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODFC(v)   ((((reg32_t) v) << 5) & BM_ASRC_ASRSTR_AODFC)
#else
#define BF_ASRC_ASRSTR_AODFC(v)   (((v) << 5) & BM_ASRC_ASRSTR_AODFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODFC(v)   BF_CS1(ASRC_ASRSTR, AODFC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODFB */

#define BP_ASRC_ASRSTR_AODFB      4
#define BM_ASRC_ASRSTR_AODFB      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODFB(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRSTR_AODFB)
#else
#define BF_ASRC_ASRSTR_AODFB(v)   (((v) << 4) & BM_ASRC_ASRSTR_AODFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODFB(v)   BF_CS1(ASRC_ASRSTR, AODFB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AODFA */

#define BP_ASRC_ASRSTR_AODFA      3
#define BM_ASRC_ASRSTR_AODFA      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AODFA(v)   ((((reg32_t) v) << 3) & BM_ASRC_ASRSTR_AODFA)
#else
#define BF_ASRC_ASRSTR_AODFA(v)   (((v) << 3) & BM_ASRC_ASRSTR_AODFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AODFA(v)   BF_CS1(ASRC_ASRSTR, AODFA, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDEC */

#define BP_ASRC_ASRSTR_AIDEC      2
#define BM_ASRC_ASRSTR_AIDEC      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDEC(v)   ((((reg32_t) v) << 2) & BM_ASRC_ASRSTR_AIDEC)
#else
#define BF_ASRC_ASRSTR_AIDEC(v)   (((v) << 2) & BM_ASRC_ASRSTR_AIDEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDEC(v)   BF_CS1(ASRC_ASRSTR, AIDEC, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDEB */

#define BP_ASRC_ASRSTR_AIDEB      1
#define BM_ASRC_ASRSTR_AIDEB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDEB(v)   ((((reg32_t) v) << 1) & BM_ASRC_ASRSTR_AIDEB)
#else
#define BF_ASRC_ASRSTR_AIDEB(v)   (((v) << 1) & BM_ASRC_ASRSTR_AIDEB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDEB(v)   BF_CS1(ASRC_ASRSTR, AIDEB, v)
#endif

/* --- Register HW_ASRC_ASRSTR, field AIDEA */

#define BP_ASRC_ASRSTR_AIDEA      0
#define BM_ASRC_ASRSTR_AIDEA      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRSTR_AIDEA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRSTR_AIDEA)
#else
#define BF_ASRC_ASRSTR_AIDEA(v)   (((v) << 0) & BM_ASRC_ASRSTR_AIDEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRSTR_AIDEA(v)   BF_CS1(ASRC_ASRSTR, AIDEA, v)
#endif

/*
 * HW_ASRC_ASRRA - Ratio Register Part A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ASRRA : 24;

    } B;
} hw_asrc_asrra_t;
#endif

/*
 * constants & macros for entire ASRC_ASRRA register
 */
#define HW_ASRC_ASRRA_ADDR      (REGS_ASRC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRRA           (*(volatile hw_asrc_asrra_t *) HW_ASRC_ASRRA_ADDR)
#define HW_ASRC_ASRRA_RD()      (HW_ASRC_ASRRA.U)
#define HW_ASRC_ASRRA_WR(v)     (HW_ASRC_ASRRA.U = (v))
#define HW_ASRC_ASRRA_SET(v)    (HW_ASRC_ASRRA_WR(HW_ASRC_ASRRA_RD() |  (v)))
#define HW_ASRC_ASRRA_CLR(v)    (HW_ASRC_ASRRA_WR(HW_ASRC_ASRRA_RD() & ~(v)))
#define HW_ASRC_ASRRA_TOG(v)    (HW_ASRC_ASRRA_WR(HW_ASRC_ASRRA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRRA bitfields
 */

/* --- Register HW_ASRC_ASRRA, field ASRRA */

#define BP_ASRC_ASRRA_ASRRA      0
#define BM_ASRC_ASRRA_ASRRA      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRRA_ASRRA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRRA_ASRRA)
#else
#define BF_ASRC_ASRRA_ASRRA(v)   (((v) << 0) & BM_ASRC_ASRRA_ASRRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRRA_ASRRA(v)   BF_CS1(ASRC_ASRRA, ASRRA, v)
#endif

/*
 * HW_ASRC_ASRDCMD - ASRC Debug Command Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned INTACT : 1;
        unsigned SDCMD : 1;
        unsigned DBGCMD : 3;
        unsigned BKPACT : 1;
        unsigned RESERVED1 : 9;
        unsigned PMAB : 9;

    } B;
} hw_asrc_asrdcmd_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDCMD register
 */
#define HW_ASRC_ASRDCMD_ADDR      (REGS_ASRC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDCMD           (*(volatile hw_asrc_asrdcmd_t *) HW_ASRC_ASRDCMD_ADDR)
#define HW_ASRC_ASRDCMD_RD()      (HW_ASRC_ASRDCMD.U)
#define HW_ASRC_ASRDCMD_WR(v)     (HW_ASRC_ASRDCMD.U = (v))
#define HW_ASRC_ASRDCMD_SET(v)    (HW_ASRC_ASRDCMD_WR(HW_ASRC_ASRDCMD_RD() |  (v)))
#define HW_ASRC_ASRDCMD_CLR(v)    (HW_ASRC_ASRDCMD_WR(HW_ASRC_ASRDCMD_RD() & ~(v)))
#define HW_ASRC_ASRDCMD_TOG(v)    (HW_ASRC_ASRDCMD_WR(HW_ASRC_ASRDCMD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDCMD bitfields
 */

/* --- Register HW_ASRC_ASRDCMD, field INTACT */

#define BP_ASRC_ASRDCMD_INTACT      23
#define BM_ASRC_ASRDCMD_INTACT      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCMD_INTACT(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRDCMD_INTACT)
#else
#define BF_ASRC_ASRDCMD_INTACT(v)   (((v) << 23) & BM_ASRC_ASRDCMD_INTACT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCMD_INTACT(v)   BF_CS1(ASRC_ASRDCMD, INTACT, v)
#endif

/* --- Register HW_ASRC_ASRDCMD, field SDCMD */

#define BP_ASRC_ASRDCMD_SDCMD      22
#define BM_ASRC_ASRDCMD_SDCMD      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCMD_SDCMD(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRDCMD_SDCMD)
#else
#define BF_ASRC_ASRDCMD_SDCMD(v)   (((v) << 22) & BM_ASRC_ASRDCMD_SDCMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCMD_SDCMD(v)   BF_CS1(ASRC_ASRDCMD, SDCMD, v)
#endif

/* --- Register HW_ASRC_ASRDCMD, field DBGCMD */

#define BP_ASRC_ASRDCMD_DBGCMD      19
#define BM_ASRC_ASRDCMD_DBGCMD      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCMD_DBGCMD(v)   ((((reg32_t) v) << 19) & BM_ASRC_ASRDCMD_DBGCMD)
#else
#define BF_ASRC_ASRDCMD_DBGCMD(v)   (((v) << 19) & BM_ASRC_ASRDCMD_DBGCMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCMD_DBGCMD(v)   BF_CS1(ASRC_ASRDCMD, DBGCMD, v)
#endif

/* --- Register HW_ASRC_ASRDCMD, field BKPACT */

#define BP_ASRC_ASRDCMD_BKPACT      18
#define BM_ASRC_ASRDCMD_BKPACT      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCMD_BKPACT(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRDCMD_BKPACT)
#else
#define BF_ASRC_ASRDCMD_BKPACT(v)   (((v) << 18) & BM_ASRC_ASRDCMD_BKPACT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCMD_BKPACT(v)   BF_CS1(ASRC_ASRDCMD, BKPACT, v)
#endif

/* --- Register HW_ASRC_ASRDCMD, field PMAB */

#define BP_ASRC_ASRDCMD_PMAB      0
#define BM_ASRC_ASRDCMD_PMAB      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCMD_PMAB(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDCMD_PMAB)
#else
#define BF_ASRC_ASRDCMD_PMAB(v)   (((v) << 0) & BM_ASRC_ASRDCMD_PMAB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCMD_PMAB(v)   BF_CS1(ASRC_ASRDCMD, PMAB, v)
#endif

/*
 * HW_ASRC_ASRRB - Ratio Register Part B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 2;
        unsigned ASRRA : 6;
        unsigned RESERVED2 : 2;
        unsigned IPSFT : 6;
        unsigned RESERVED3 : 2;
        unsigned ASRRC : 6;

    } B;
} hw_asrc_asrrb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRRB register
 */
#define HW_ASRC_ASRRB_ADDR      (REGS_ASRC_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRRB           (*(volatile hw_asrc_asrrb_t *) HW_ASRC_ASRRB_ADDR)
#define HW_ASRC_ASRRB_RD()      (HW_ASRC_ASRRB.U)
#define HW_ASRC_ASRRB_WR(v)     (HW_ASRC_ASRRB.U = (v))
#define HW_ASRC_ASRRB_SET(v)    (HW_ASRC_ASRRB_WR(HW_ASRC_ASRRB_RD() |  (v)))
#define HW_ASRC_ASRRB_CLR(v)    (HW_ASRC_ASRRB_WR(HW_ASRC_ASRRB_RD() & ~(v)))
#define HW_ASRC_ASRRB_TOG(v)    (HW_ASRC_ASRRB_WR(HW_ASRC_ASRRB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRRB bitfields
 */

/* --- Register HW_ASRC_ASRRB, field ASRRA */

#define BP_ASRC_ASRRB_ASRRA      16
#define BM_ASRC_ASRRB_ASRRA      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRRB_ASRRA(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRRB_ASRRA)
#else
#define BF_ASRC_ASRRB_ASRRA(v)   (((v) << 16) & BM_ASRC_ASRRB_ASRRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRRB_ASRRA(v)   BF_CS1(ASRC_ASRRB, ASRRA, v)
#endif

/* --- Register HW_ASRC_ASRRB, field IPSFT */

#define BP_ASRC_ASRRB_IPSFT      8
#define BM_ASRC_ASRRB_IPSFT      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRRB_IPSFT(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRRB_IPSFT)
#else
#define BF_ASRC_ASRRB_IPSFT(v)   (((v) << 8) & BM_ASRC_ASRRB_IPSFT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRRB_IPSFT(v)   BF_CS1(ASRC_ASRRB, IPSFT, v)
#endif

/* --- Register HW_ASRC_ASRRB, field ASRRC */

#define BP_ASRC_ASRRB_ASRRC      0
#define BM_ASRC_ASRRB_ASRRC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRRB_ASRRC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRRB_ASRRC)
#else
#define BF_ASRC_ASRRB_ASRRC(v)   (((v) << 0) & BM_ASRC_ASRRB_ASRRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRRB_ASRRC(v)   BF_CS1(ASRC_ASRRB, ASRRC, v)
#endif

/*
 * HW_ASRC_ASRDINSTH - ASRC Debug Instruction Register High
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ASRDINSTH : 24;

    } B;
} hw_asrc_asrdinsth_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDINSTH register
 */
#define HW_ASRC_ASRDINSTH_ADDR      (REGS_ASRC_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDINSTH           (*(volatile hw_asrc_asrdinsth_t *) HW_ASRC_ASRDINSTH_ADDR)
#define HW_ASRC_ASRDINSTH_RD()      (HW_ASRC_ASRDINSTH.U)
#define HW_ASRC_ASRDINSTH_WR(v)     (HW_ASRC_ASRDINSTH.U = (v))
#define HW_ASRC_ASRDINSTH_SET(v)    (HW_ASRC_ASRDINSTH_WR(HW_ASRC_ASRDINSTH_RD() |  (v)))
#define HW_ASRC_ASRDINSTH_CLR(v)    (HW_ASRC_ASRDINSTH_WR(HW_ASRC_ASRDINSTH_RD() & ~(v)))
#define HW_ASRC_ASRDINSTH_TOG(v)    (HW_ASRC_ASRDINSTH_WR(HW_ASRC_ASRDINSTH_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDINSTH bitfields
 */

/* --- Register HW_ASRC_ASRDINSTH, field ASRDINSTH */

#define BP_ASRC_ASRDINSTH_ASRDINSTH      0
#define BM_ASRC_ASRDINSTH_ASRDINSTH      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDINSTH_ASRDINSTH(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDINSTH_ASRDINSTH)
#else
#define BF_ASRC_ASRDINSTH_ASRDINSTH(v)   (((v) << 0) & BM_ASRC_ASRDINSTH_ASRDINSTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDINSTH_ASRDINSTH(v)   BF_CS1(ASRC_ASRDINSTH, ASRDINSTH, v)
#endif

/*
 * HW_ASRC_ASRRC - Ratio Register Part C
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ASRRC : 24;

    } B;
} hw_asrc_asrrc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRRC register
 */
#define HW_ASRC_ASRRC_ADDR      (REGS_ASRC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRRC           (*(volatile hw_asrc_asrrc_t *) HW_ASRC_ASRRC_ADDR)
#define HW_ASRC_ASRRC_RD()      (HW_ASRC_ASRRC.U)
#define HW_ASRC_ASRRC_WR(v)     (HW_ASRC_ASRRC.U = (v))
#define HW_ASRC_ASRRC_SET(v)    (HW_ASRC_ASRRC_WR(HW_ASRC_ASRRC_RD() |  (v)))
#define HW_ASRC_ASRRC_CLR(v)    (HW_ASRC_ASRRC_WR(HW_ASRC_ASRRC_RD() & ~(v)))
#define HW_ASRC_ASRRC_TOG(v)    (HW_ASRC_ASRRC_WR(HW_ASRC_ASRRC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRRC bitfields
 */

/* --- Register HW_ASRC_ASRRC, field ASRRC */

#define BP_ASRC_ASRRC_ASRRC      0
#define BM_ASRC_ASRRC_ASRRC      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRRC_ASRRC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRRC_ASRRC)
#else
#define BF_ASRC_ASRRC_ASRRC(v)   (((v) << 0) & BM_ASRC_ASRRC_ASRRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRRC_ASRRC(v)   BF_CS1(ASRC_ASRRC, ASRRC, v)
#endif

/*
 * HW_ASRC_ASRDINSTL - ASRC Debug Instruction Register Low
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ASRDINSTL : 24;

    } B;
} hw_asrc_asrdinstl_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDINSTL register
 */
#define HW_ASRC_ASRDINSTL_ADDR      (REGS_ASRC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDINSTL           (*(volatile hw_asrc_asrdinstl_t *) HW_ASRC_ASRDINSTL_ADDR)
#define HW_ASRC_ASRDINSTL_RD()      (HW_ASRC_ASRDINSTL.U)
#define HW_ASRC_ASRDINSTL_WR(v)     (HW_ASRC_ASRDINSTL.U = (v))
#define HW_ASRC_ASRDINSTL_SET(v)    (HW_ASRC_ASRDINSTL_WR(HW_ASRC_ASRDINSTL_RD() |  (v)))
#define HW_ASRC_ASRDINSTL_CLR(v)    (HW_ASRC_ASRDINSTL_WR(HW_ASRC_ASRDINSTL_RD() & ~(v)))
#define HW_ASRC_ASRDINSTL_TOG(v)    (HW_ASRC_ASRDINSTL_WR(HW_ASRC_ASRDINSTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDINSTL bitfields
 */

/* --- Register HW_ASRC_ASRDINSTL, field ASRDINSTL */

#define BP_ASRC_ASRDINSTL_ASRDINSTL      0
#define BM_ASRC_ASRDINSTL_ASRDINSTL      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDINSTL_ASRDINSTL(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDINSTL_ASRDINSTL)
#else
#define BF_ASRC_ASRDINSTL_ASRDINSTL(v)   (((v) << 0) & BM_ASRC_ASRDINSTL_ASRDINSTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDINSTL_ASRDINSTL(v)   BF_CS1(ASRC_ASRDINSTL, ASRDINSTL, v)
#endif

/*
 * HW_ASRC_ASRMAA - ASRC Memory Access Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned MEMOPT : 2;
        unsigned RESERVED1 : 9;
        unsigned ADDR : 13;

    } B;
} hw_asrc_asrmaa_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMAA register
 */
#define HW_ASRC_ASRMAA_ADDR      (REGS_ASRC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMAA           (*(volatile hw_asrc_asrmaa_t *) HW_ASRC_ASRMAA_ADDR)
#define HW_ASRC_ASRMAA_RD()      (HW_ASRC_ASRMAA.U)
#define HW_ASRC_ASRMAA_WR(v)     (HW_ASRC_ASRMAA.U = (v))
#define HW_ASRC_ASRMAA_SET(v)    (HW_ASRC_ASRMAA_WR(HW_ASRC_ASRMAA_RD() |  (v)))
#define HW_ASRC_ASRMAA_CLR(v)    (HW_ASRC_ASRMAA_WR(HW_ASRC_ASRMAA_RD() & ~(v)))
#define HW_ASRC_ASRMAA_TOG(v)    (HW_ASRC_ASRMAA_WR(HW_ASRC_ASRMAA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMAA bitfields
 */

/* --- Register HW_ASRC_ASRMAA, field MEMOPT */

#define BP_ASRC_ASRMAA_MEMOPT      22
#define BM_ASRC_ASRMAA_MEMOPT      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMAA_MEMOPT(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRMAA_MEMOPT)
#else
#define BF_ASRC_ASRMAA_MEMOPT(v)   (((v) << 22) & BM_ASRC_ASRMAA_MEMOPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMAA_MEMOPT(v)   BF_CS1(ASRC_ASRMAA, MEMOPT, v)
#endif

/* --- Register HW_ASRC_ASRMAA, field ADDR */

#define BP_ASRC_ASRMAA_ADDR      0
#define BM_ASRC_ASRMAA_ADDR      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMAA_ADDR(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMAA_ADDR)
#else
#define BF_ASRC_ASRMAA_ADDR(v)   (((v) << 0) & BM_ASRC_ASRMAA_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMAA_ADDR(v)   BF_CS1(ASRC_ASRMAA, ADDR, v)
#endif

/*
 * HW_ASRC_ASRMAD - ASRC Memory Access Data Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned DATA : 24;

    } B;
} hw_asrc_asrmad_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMAD register
 */
#define HW_ASRC_ASRMAD_ADDR      (REGS_ASRC_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMAD           (*(volatile hw_asrc_asrmad_t *) HW_ASRC_ASRMAD_ADDR)
#define HW_ASRC_ASRMAD_RD()      (HW_ASRC_ASRMAD.U)
#define HW_ASRC_ASRMAD_WR(v)     (HW_ASRC_ASRMAD.U = (v))
#define HW_ASRC_ASRMAD_SET(v)    (HW_ASRC_ASRMAD_WR(HW_ASRC_ASRMAD_RD() |  (v)))
#define HW_ASRC_ASRMAD_CLR(v)    (HW_ASRC_ASRMAD_WR(HW_ASRC_ASRMAD_RD() & ~(v)))
#define HW_ASRC_ASRMAD_TOG(v)    (HW_ASRC_ASRMAD_WR(HW_ASRC_ASRMAD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMAD bitfields
 */

/* --- Register HW_ASRC_ASRMAD, field DATA */

#define BP_ASRC_ASRMAD_DATA      0
#define BM_ASRC_ASRMAD_DATA      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMAD_DATA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMAD_DATA)
#else
#define BF_ASRC_ASRMAD_DATA(v)   (((v) << 0) & BM_ASRC_ASRMAD_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMAD_DATA(v)   BF_CS1(ASRC_ASRMAD, DATA, v)
#endif

/*
 * HW_ASRC_ASRDCR - ASRC Debug Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned CNTCLRC : 1;
        unsigned CNTCLRB : 1;
        unsigned CNTCLRA : 1;
        unsigned SFFOC : 1;
        unsigned SFFOB : 1;
        unsigned SFFOA : 1;
        unsigned TSKQE : 1;
        unsigned PFWPT : 5;
        unsigned CPAIR : 2;
        unsigned INCLK : 1;
        unsigned OUTCLK : 1;
        unsigned RESERVED1 : 2;
        unsigned DSL_TKO : 6;

    } B;
} hw_asrc_asrdcr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDCR register
 */
#define HW_ASRC_ASRDCR_ADDR      (REGS_ASRC_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDCR           (*(volatile hw_asrc_asrdcr_t *) HW_ASRC_ASRDCR_ADDR)
#define HW_ASRC_ASRDCR_RD()      (HW_ASRC_ASRDCR.U)
#define HW_ASRC_ASRDCR_WR(v)     (HW_ASRC_ASRDCR.U = (v))
#define HW_ASRC_ASRDCR_SET(v)    (HW_ASRC_ASRDCR_WR(HW_ASRC_ASRDCR_RD() |  (v)))
#define HW_ASRC_ASRDCR_CLR(v)    (HW_ASRC_ASRDCR_WR(HW_ASRC_ASRDCR_RD() & ~(v)))
#define HW_ASRC_ASRDCR_TOG(v)    (HW_ASRC_ASRDCR_WR(HW_ASRC_ASRDCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDCR bitfields
 */

/* --- Register HW_ASRC_ASRDCR, field CNTCLRC */

#define BP_ASRC_ASRDCR_CNTCLRC      23
#define BM_ASRC_ASRDCR_CNTCLRC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_CNTCLRC(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRDCR_CNTCLRC)
#else
#define BF_ASRC_ASRDCR_CNTCLRC(v)   (((v) << 23) & BM_ASRC_ASRDCR_CNTCLRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_CNTCLRC(v)   BF_CS1(ASRC_ASRDCR, CNTCLRC, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field CNTCLRB */

#define BP_ASRC_ASRDCR_CNTCLRB      22
#define BM_ASRC_ASRDCR_CNTCLRB      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_CNTCLRB(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRDCR_CNTCLRB)
#else
#define BF_ASRC_ASRDCR_CNTCLRB(v)   (((v) << 22) & BM_ASRC_ASRDCR_CNTCLRB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_CNTCLRB(v)   BF_CS1(ASRC_ASRDCR, CNTCLRB, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field CNTCLRA */

#define BP_ASRC_ASRDCR_CNTCLRA      21
#define BM_ASRC_ASRDCR_CNTCLRA      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_CNTCLRA(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRDCR_CNTCLRA)
#else
#define BF_ASRC_ASRDCR_CNTCLRA(v)   (((v) << 21) & BM_ASRC_ASRDCR_CNTCLRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_CNTCLRA(v)   BF_CS1(ASRC_ASRDCR, CNTCLRA, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field SFFOC */

#define BP_ASRC_ASRDCR_SFFOC      20
#define BM_ASRC_ASRDCR_SFFOC      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_SFFOC(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRDCR_SFFOC)
#else
#define BF_ASRC_ASRDCR_SFFOC(v)   (((v) << 20) & BM_ASRC_ASRDCR_SFFOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_SFFOC(v)   BF_CS1(ASRC_ASRDCR, SFFOC, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field SFFOB */

#define BP_ASRC_ASRDCR_SFFOB      19
#define BM_ASRC_ASRDCR_SFFOB      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_SFFOB(v)   ((((reg32_t) v) << 19) & BM_ASRC_ASRDCR_SFFOB)
#else
#define BF_ASRC_ASRDCR_SFFOB(v)   (((v) << 19) & BM_ASRC_ASRDCR_SFFOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_SFFOB(v)   BF_CS1(ASRC_ASRDCR, SFFOB, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field SFFOA */

#define BP_ASRC_ASRDCR_SFFOA      18
#define BM_ASRC_ASRDCR_SFFOA      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_SFFOA(v)   ((((reg32_t) v) << 18) & BM_ASRC_ASRDCR_SFFOA)
#else
#define BF_ASRC_ASRDCR_SFFOA(v)   (((v) << 18) & BM_ASRC_ASRDCR_SFFOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_SFFOA(v)   BF_CS1(ASRC_ASRDCR, SFFOA, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field TSKQE */

#define BP_ASRC_ASRDCR_TSKQE      17
#define BM_ASRC_ASRDCR_TSKQE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_TSKQE(v)   ((((reg32_t) v) << 17) & BM_ASRC_ASRDCR_TSKQE)
#else
#define BF_ASRC_ASRDCR_TSKQE(v)   (((v) << 17) & BM_ASRC_ASRDCR_TSKQE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_TSKQE(v)   BF_CS1(ASRC_ASRDCR, TSKQE, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field PFWPT */

#define BP_ASRC_ASRDCR_PFWPT      12
#define BM_ASRC_ASRDCR_PFWPT      0x0001f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_PFWPT(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRDCR_PFWPT)
#else
#define BF_ASRC_ASRDCR_PFWPT(v)   (((v) << 12) & BM_ASRC_ASRDCR_PFWPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_PFWPT(v)   BF_CS1(ASRC_ASRDCR, PFWPT, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field CPAIR */

#define BP_ASRC_ASRDCR_CPAIR      10
#define BM_ASRC_ASRDCR_CPAIR      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_CPAIR(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRDCR_CPAIR)
#else
#define BF_ASRC_ASRDCR_CPAIR(v)   (((v) << 10) & BM_ASRC_ASRDCR_CPAIR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_CPAIR(v)   BF_CS1(ASRC_ASRDCR, CPAIR, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field INCLK */

#define BP_ASRC_ASRDCR_INCLK      9
#define BM_ASRC_ASRDCR_INCLK      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_INCLK(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRDCR_INCLK)
#else
#define BF_ASRC_ASRDCR_INCLK(v)   (((v) << 9) & BM_ASRC_ASRDCR_INCLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_INCLK(v)   BF_CS1(ASRC_ASRDCR, INCLK, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field OUTCLK */

#define BP_ASRC_ASRDCR_OUTCLK      8
#define BM_ASRC_ASRDCR_OUTCLK      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_OUTCLK(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRDCR_OUTCLK)
#else
#define BF_ASRC_ASRDCR_OUTCLK(v)   (((v) << 8) & BM_ASRC_ASRDCR_OUTCLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_OUTCLK(v)   BF_CS1(ASRC_ASRDCR, OUTCLK, v)
#endif

/* --- Register HW_ASRC_ASRDCR, field DSL_TKO */

#define BP_ASRC_ASRDCR_DSL_TKO      0
#define BM_ASRC_ASRDCR_DSL_TKO      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR_DSL_TKO(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDCR_DSL_TKO)
#else
#define BF_ASRC_ASRDCR_DSL_TKO(v)   (((v) << 0) & BM_ASRC_ASRDCR_DSL_TKO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR_DSL_TKO(v)   BF_CS1(ASRC_ASRDCR, DSL_TKO, v)
#endif

/*
 * HW_ASRC_ASRDCR1 - ASRC Debug Control Register -1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned DSL_TKO : 24;

    } B;
} hw_asrc_asrdcr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDCR1 register
 */
#define HW_ASRC_ASRDCR1_ADDR      (REGS_ASRC_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDCR1           (*(volatile hw_asrc_asrdcr1_t *) HW_ASRC_ASRDCR1_ADDR)
#define HW_ASRC_ASRDCR1_RD()      (HW_ASRC_ASRDCR1.U)
#define HW_ASRC_ASRDCR1_WR(v)     (HW_ASRC_ASRDCR1.U = (v))
#define HW_ASRC_ASRDCR1_SET(v)    (HW_ASRC_ASRDCR1_WR(HW_ASRC_ASRDCR1_RD() |  (v)))
#define HW_ASRC_ASRDCR1_CLR(v)    (HW_ASRC_ASRDCR1_WR(HW_ASRC_ASRDCR1_RD() & ~(v)))
#define HW_ASRC_ASRDCR1_TOG(v)    (HW_ASRC_ASRDCR1_WR(HW_ASRC_ASRDCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDCR1 bitfields
 */

/* --- Register HW_ASRC_ASRDCR1, field DSL_TKO */

#define BP_ASRC_ASRDCR1_DSL_TKO      0
#define BM_ASRC_ASRDCR1_DSL_TKO      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDCR1_DSL_TKO(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDCR1_DSL_TKO)
#else
#define BF_ASRC_ASRDCR1_DSL_TKO(v)   (((v) << 0) & BM_ASRC_ASRDCR1_DSL_TKO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDCR1_DSL_TKO(v)   BF_CS1(ASRC_ASRDCR1, DSL_TKO, v)
#endif

/*
 * HW_ASRC_ASRPMN - ASRC Parameter Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned PARAMETER_VALUE : 24;

    } B;
} hw_asrc_asrpmn_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN register
 */
#define HW_ASRC_ASRPMN_ADDR      (REGS_ASRC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN           (*(volatile hw_asrc_asrpmn_t *) HW_ASRC_ASRPMN_ADDR)
#define HW_ASRC_ASRPMN_RD()      (HW_ASRC_ASRPMN.U)
#define HW_ASRC_ASRPMN_WR(v)     (HW_ASRC_ASRPMN.U = (v))
#define HW_ASRC_ASRPMN_SET(v)    (HW_ASRC_ASRPMN_WR(HW_ASRC_ASRPMN_RD() |  (v)))
#define HW_ASRC_ASRPMN_CLR(v)    (HW_ASRC_ASRPMN_WR(HW_ASRC_ASRPMN_RD() & ~(v)))
#define HW_ASRC_ASRPMN_TOG(v)    (HW_ASRC_ASRPMN_WR(HW_ASRC_ASRPMN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRPMN bitfields
 */

/* --- Register HW_ASRC_ASRPMN, field PARAMETER_VALUE */

#define BP_ASRC_ASRPMN_PARAMETER_VALUE      0
#define BM_ASRC_ASRPMN_PARAMETER_VALUE      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRPMN_PARAMETER_VALUE(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRPMN_PARAMETER_VALUE)
#else
#define BF_ASRC_ASRPMN_PARAMETER_VALUE(v)   (((v) << 0) & BM_ASRC_ASRPMN_PARAMETER_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRPMN_PARAMETER_VALUE(v)   BF_CS1(ASRC_ASRPMN, PARAMETER_VALUE, v)
#endif

/*
 * HW_ASRC_ASRTFR1 - ASRC ASRC Task Queue FIFO Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 4;
        unsigned TF_FILL : 7;
        unsigned TF_BASE : 7;
        unsigned RESERVED2 : 6;

    } B;
} hw_asrc_asrtfr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRTFR1 register
 */
#define HW_ASRC_ASRTFR1_ADDR      (REGS_ASRC_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRTFR1           (*(volatile hw_asrc_asrtfr1_t *) HW_ASRC_ASRTFR1_ADDR)
#define HW_ASRC_ASRTFR1_RD()      (HW_ASRC_ASRTFR1.U)
#define HW_ASRC_ASRTFR1_WR(v)     (HW_ASRC_ASRTFR1.U = (v))
#define HW_ASRC_ASRTFR1_SET(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() |  (v)))
#define HW_ASRC_ASRTFR1_CLR(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() & ~(v)))
#define HW_ASRC_ASRTFR1_TOG(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRTFR1 bitfields
 */

/* --- Register HW_ASRC_ASRTFR1, field TF_FILL */

#define BP_ASRC_ASRTFR1_TF_FILL      13
#define BM_ASRC_ASRTFR1_TF_FILL      0x000fe000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR1_TF_FILL(v)   ((((reg32_t) v) << 13) & BM_ASRC_ASRTFR1_TF_FILL)
#else
#define BF_ASRC_ASRTFR1_TF_FILL(v)   (((v) << 13) & BM_ASRC_ASRTFR1_TF_FILL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR1_TF_FILL(v)   BF_CS1(ASRC_ASRTFR1, TF_FILL, v)
#endif

/* --- Register HW_ASRC_ASRTFR1, field TF_BASE */

#define BP_ASRC_ASRTFR1_TF_BASE      6
#define BM_ASRC_ASRTFR1_TF_BASE      0x00001fc0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR1_TF_BASE(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRTFR1_TF_BASE)
#else
#define BF_ASRC_ASRTFR1_TF_BASE(v)   (((v) << 6) & BM_ASRC_ASRTFR1_TF_BASE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR1_TF_BASE(v)   BF_CS1(ASRC_ASRTFR1, TF_BASE, v)
#endif

/*
 * HW_ASRC_ASRTFR2 - ASRC Task queue FIFO Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned DSLC_FIFO_PT : 4;
        unsigned DSLB_FIFO_PT : 4;
        unsigned DSLA_FIFO_PT : 4;
        unsigned TF_RD_PTR : 6;
        unsigned TF_WR_PTR : 6;

    } B;
} hw_asrc_asrtfr2_t;
#endif

/*
 * constants & macros for entire ASRC_ASRTFR2 register
 */
#define HW_ASRC_ASRTFR2_ADDR      (REGS_ASRC_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRTFR2           (*(volatile hw_asrc_asrtfr2_t *) HW_ASRC_ASRTFR2_ADDR)
#define HW_ASRC_ASRTFR2_RD()      (HW_ASRC_ASRTFR2.U)
#define HW_ASRC_ASRTFR2_WR(v)     (HW_ASRC_ASRTFR2.U = (v))
#define HW_ASRC_ASRTFR2_SET(v)    (HW_ASRC_ASRTFR2_WR(HW_ASRC_ASRTFR2_RD() |  (v)))
#define HW_ASRC_ASRTFR2_CLR(v)    (HW_ASRC_ASRTFR2_WR(HW_ASRC_ASRTFR2_RD() & ~(v)))
#define HW_ASRC_ASRTFR2_TOG(v)    (HW_ASRC_ASRTFR2_WR(HW_ASRC_ASRTFR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRTFR2 bitfields
 */

/* --- Register HW_ASRC_ASRTFR2, field DSLC_FIFO_PT */

#define BP_ASRC_ASRTFR2_DSLC_FIFO_PT      20
#define BM_ASRC_ASRTFR2_DSLC_FIFO_PT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR2_DSLC_FIFO_PT(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRTFR2_DSLC_FIFO_PT)
#else
#define BF_ASRC_ASRTFR2_DSLC_FIFO_PT(v)   (((v) << 20) & BM_ASRC_ASRTFR2_DSLC_FIFO_PT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR2_DSLC_FIFO_PT(v)   BF_CS1(ASRC_ASRTFR2, DSLC_FIFO_PT, v)
#endif

/* --- Register HW_ASRC_ASRTFR2, field DSLB_FIFO_PT */

#define BP_ASRC_ASRTFR2_DSLB_FIFO_PT      16
#define BM_ASRC_ASRTFR2_DSLB_FIFO_PT      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR2_DSLB_FIFO_PT(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRTFR2_DSLB_FIFO_PT)
#else
#define BF_ASRC_ASRTFR2_DSLB_FIFO_PT(v)   (((v) << 16) & BM_ASRC_ASRTFR2_DSLB_FIFO_PT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR2_DSLB_FIFO_PT(v)   BF_CS1(ASRC_ASRTFR2, DSLB_FIFO_PT, v)
#endif

/* --- Register HW_ASRC_ASRTFR2, field DSLA_FIFO_PT */

#define BP_ASRC_ASRTFR2_DSLA_FIFO_PT      12
#define BM_ASRC_ASRTFR2_DSLA_FIFO_PT      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR2_DSLA_FIFO_PT(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRTFR2_DSLA_FIFO_PT)
#else
#define BF_ASRC_ASRTFR2_DSLA_FIFO_PT(v)   (((v) << 12) & BM_ASRC_ASRTFR2_DSLA_FIFO_PT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR2_DSLA_FIFO_PT(v)   BF_CS1(ASRC_ASRTFR2, DSLA_FIFO_PT, v)
#endif

/* --- Register HW_ASRC_ASRTFR2, field TF_RD_PTR */

#define BP_ASRC_ASRTFR2_TF_RD_PTR      6
#define BM_ASRC_ASRTFR2_TF_RD_PTR      0x00000fc0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR2_TF_RD_PTR(v)   ((((reg32_t) v) << 6) & BM_ASRC_ASRTFR2_TF_RD_PTR)
#else
#define BF_ASRC_ASRTFR2_TF_RD_PTR(v)   (((v) << 6) & BM_ASRC_ASRTFR2_TF_RD_PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR2_TF_RD_PTR(v)   BF_CS1(ASRC_ASRTFR2, TF_RD_PTR, v)
#endif

/* --- Register HW_ASRC_ASRTFR2, field TF_WR_PTR */

#define BP_ASRC_ASRTFR2_TF_WR_PTR      0
#define BM_ASRC_ASRTFR2_TF_WR_PTR      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRTFR2_TF_WR_PTR(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRTFR2_TF_WR_PTR)
#else
#define BF_ASRC_ASRTFR2_TF_WR_PTR(v)   (((v) << 0) & BM_ASRC_ASRTFR2_TF_WR_PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRTFR2_TF_WR_PTR(v)   BF_CS1(ASRC_ASRTFR2, TF_WR_PTR, v)
#endif

/*
 * HW_ASRC_ASRCCR - ASRC Channel Counter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ACOC : 4;
        unsigned ACOB : 4;
        unsigned ACOA : 4;
        unsigned ACIC : 4;
        unsigned ACIB : 4;
        unsigned ACIA : 4;

    } B;
} hw_asrc_asrccr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCCR register
 */
#define HW_ASRC_ASRCCR_ADDR      (REGS_ASRC_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCCR           (*(volatile hw_asrc_asrccr_t *) HW_ASRC_ASRCCR_ADDR)
#define HW_ASRC_ASRCCR_RD()      (HW_ASRC_ASRCCR.U)
#define HW_ASRC_ASRCCR_WR(v)     (HW_ASRC_ASRCCR.U = (v))
#define HW_ASRC_ASRCCR_SET(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() |  (v)))
#define HW_ASRC_ASRCCR_CLR(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() & ~(v)))
#define HW_ASRC_ASRCCR_TOG(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRCCR bitfields
 */

/* --- Register HW_ASRC_ASRCCR, field ACOC */

#define BP_ASRC_ASRCCR_ACOC      20
#define BM_ASRC_ASRCCR_ACOC      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACOC(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRCCR_ACOC)
#else
#define BF_ASRC_ASRCCR_ACOC(v)   (((v) << 20) & BM_ASRC_ASRCCR_ACOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACOC(v)   BF_CS1(ASRC_ASRCCR, ACOC, v)
#endif

/* --- Register HW_ASRC_ASRCCR, field ACOB */

#define BP_ASRC_ASRCCR_ACOB      16
#define BM_ASRC_ASRCCR_ACOB      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACOB(v)   ((((reg32_t) v) << 16) & BM_ASRC_ASRCCR_ACOB)
#else
#define BF_ASRC_ASRCCR_ACOB(v)   (((v) << 16) & BM_ASRC_ASRCCR_ACOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACOB(v)   BF_CS1(ASRC_ASRCCR, ACOB, v)
#endif

/* --- Register HW_ASRC_ASRCCR, field ACOA */

#define BP_ASRC_ASRCCR_ACOA      12
#define BM_ASRC_ASRCCR_ACOA      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACOA(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRCCR_ACOA)
#else
#define BF_ASRC_ASRCCR_ACOA(v)   (((v) << 12) & BM_ASRC_ASRCCR_ACOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACOA(v)   BF_CS1(ASRC_ASRCCR, ACOA, v)
#endif

/* --- Register HW_ASRC_ASRCCR, field ACIC */

#define BP_ASRC_ASRCCR_ACIC      8
#define BM_ASRC_ASRCCR_ACIC      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACIC(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRCCR_ACIC)
#else
#define BF_ASRC_ASRCCR_ACIC(v)   (((v) << 8) & BM_ASRC_ASRCCR_ACIC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACIC(v)   BF_CS1(ASRC_ASRCCR, ACIC, v)
#endif

/* --- Register HW_ASRC_ASRCCR, field ACIB */

#define BP_ASRC_ASRCCR_ACIB      4
#define BM_ASRC_ASRCCR_ACIB      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACIB(v)   ((((reg32_t) v) << 4) & BM_ASRC_ASRCCR_ACIB)
#else
#define BF_ASRC_ASRCCR_ACIB(v)   (((v) << 4) & BM_ASRC_ASRCCR_ACIB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACIB(v)   BF_CS1(ASRC_ASRCCR, ACIB, v)
#endif

/* --- Register HW_ASRC_ASRCCR, field ACIA */

#define BP_ASRC_ASRCCR_ACIA      0
#define BM_ASRC_ASRCCR_ACIA      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRCCR_ACIA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRCCR_ACIA)
#else
#define BF_ASRC_ASRCCR_ACIA(v)   (((v) << 0) & BM_ASRC_ASRCCR_ACIA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRCCR_ACIA(v)   BF_CS1(ASRC_ASRCCR, ACIA, v)
#endif

/*
 * HW_ASRC_ASRDI - ASRC Data Input Register for Pair 
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned DATA : 24;

    } B;
} hw_asrc_asrdi_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDI register
 */
#define HW_ASRC_ASRDI_ADDR      (REGS_ASRC_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDI           (*(volatile hw_asrc_asrdi_t *) HW_ASRC_ASRDI_ADDR)
#define HW_ASRC_ASRDI_RD()      (HW_ASRC_ASRDI.U)
#define HW_ASRC_ASRDI_WR(v)     (HW_ASRC_ASRDI.U = (v))
#define HW_ASRC_ASRDI_SET(v)    (HW_ASRC_ASRDI_WR(HW_ASRC_ASRDI_RD() |  (v)))
#define HW_ASRC_ASRDI_CLR(v)    (HW_ASRC_ASRDI_WR(HW_ASRC_ASRDI_RD() & ~(v)))
#define HW_ASRC_ASRDI_TOG(v)    (HW_ASRC_ASRDI_WR(HW_ASRC_ASRDI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDI bitfields
 */

/* --- Register HW_ASRC_ASRDI, field DATA */

#define BP_ASRC_ASRDI_DATA      0
#define BM_ASRC_ASRDI_DATA      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDI_DATA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDI_DATA)
#else
#define BF_ASRC_ASRDI_DATA(v)   (((v) << 0) & BM_ASRC_ASRDI_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDI_DATA(v)   BF_CS1(ASRC_ASRDI, DATA, v)
#endif

/*
 * HW_ASRC_ASRDO - ASRC Data Output Register for Pair 
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned DATA : 24;

    } B;
} hw_asrc_asrdo_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDO register
 */
#define HW_ASRC_ASRDO_ADDR      (REGS_ASRC_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDO           (*(volatile hw_asrc_asrdo_t *) HW_ASRC_ASRDO_ADDR)
#define HW_ASRC_ASRDO_RD()      (HW_ASRC_ASRDO.U)
#define HW_ASRC_ASRDO_WR(v)     (HW_ASRC_ASRDO.U = (v))
#define HW_ASRC_ASRDO_SET(v)    (HW_ASRC_ASRDO_WR(HW_ASRC_ASRDO_RD() |  (v)))
#define HW_ASRC_ASRDO_CLR(v)    (HW_ASRC_ASRDO_WR(HW_ASRC_ASRDO_RD() & ~(v)))
#define HW_ASRC_ASRDO_TOG(v)    (HW_ASRC_ASRDO_WR(HW_ASRC_ASRDO_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRDO bitfields
 */

/* --- Register HW_ASRC_ASRDO, field DATA */

#define BP_ASRC_ASRDO_DATA      0
#define BM_ASRC_ASRDO_DATA      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRDO_DATA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRDO_DATA)
#else
#define BF_ASRC_ASRDO_DATA(v)   (((v) << 0) & BM_ASRC_ASRDO_DATA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRDO_DATA(v)   BF_CS1(ASRC_ASRDO, DATA, v)
#endif

/*
 * HW_ASRC_ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 16;
        unsigned IDRATIOA : 8;

    } B;
} hw_asrc_asridrha_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHA register
 */
#define HW_ASRC_ASRIDRHA_ADDR      (REGS_ASRC_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHA           (*(volatile hw_asrc_asridrha_t *) HW_ASRC_ASRIDRHA_ADDR)
#define HW_ASRC_ASRIDRHA_RD()      (HW_ASRC_ASRIDRHA.U)
#define HW_ASRC_ASRIDRHA_WR(v)     (HW_ASRC_ASRIDRHA.U = (v))
#define HW_ASRC_ASRIDRHA_SET(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() |  (v)))
#define HW_ASRC_ASRIDRHA_CLR(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() & ~(v)))
#define HW_ASRC_ASRIDRHA_TOG(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRHA bitfields
 */

/* --- Register HW_ASRC_ASRIDRHA, field IDRATIOA */

#define BP_ASRC_ASRIDRHA_IDRATIOA      0
#define BM_ASRC_ASRIDRHA_IDRATIOA      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRHA_IDRATIOA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRHA_IDRATIOA)
#else
#define BF_ASRC_ASRIDRHA_IDRATIOA(v)   (((v) << 0) & BM_ASRC_ASRIDRHA_IDRATIOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRHA_IDRATIOA(v)   BF_CS1(ASRC_ASRIDRHA, IDRATIOA, v)
#endif

/*
 * HW_ASRC_ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned IDRATIOA : 24;

    } B;
} hw_asrc_asridrla_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLA register
 */
#define HW_ASRC_ASRIDRLA_ADDR      (REGS_ASRC_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLA           (*(volatile hw_asrc_asridrla_t *) HW_ASRC_ASRIDRLA_ADDR)
#define HW_ASRC_ASRIDRLA_RD()      (HW_ASRC_ASRIDRLA.U)
#define HW_ASRC_ASRIDRLA_WR(v)     (HW_ASRC_ASRIDRLA.U = (v))
#define HW_ASRC_ASRIDRLA_SET(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() |  (v)))
#define HW_ASRC_ASRIDRLA_CLR(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() & ~(v)))
#define HW_ASRC_ASRIDRLA_TOG(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRLA bitfields
 */

/* --- Register HW_ASRC_ASRIDRLA, field IDRATIOA */

#define BP_ASRC_ASRIDRLA_IDRATIOA      0
#define BM_ASRC_ASRIDRLA_IDRATIOA      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRLA_IDRATIOA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRLA_IDRATIOA)
#else
#define BF_ASRC_ASRIDRLA_IDRATIOA(v)   (((v) << 0) & BM_ASRC_ASRIDRLA_IDRATIOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRLA_IDRATIOA(v)   BF_CS1(ASRC_ASRIDRLA, IDRATIOA, v)
#endif

/*
 * HW_ASRC_ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 16;
        unsigned IDRATIOB : 8;

    } B;
} hw_asrc_asridrhb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHB register
 */
#define HW_ASRC_ASRIDRHB_ADDR      (REGS_ASRC_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHB           (*(volatile hw_asrc_asridrhb_t *) HW_ASRC_ASRIDRHB_ADDR)
#define HW_ASRC_ASRIDRHB_RD()      (HW_ASRC_ASRIDRHB.U)
#define HW_ASRC_ASRIDRHB_WR(v)     (HW_ASRC_ASRIDRHB.U = (v))
#define HW_ASRC_ASRIDRHB_SET(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() |  (v)))
#define HW_ASRC_ASRIDRHB_CLR(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() & ~(v)))
#define HW_ASRC_ASRIDRHB_TOG(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRHB bitfields
 */

/* --- Register HW_ASRC_ASRIDRHB, field IDRATIOB */

#define BP_ASRC_ASRIDRHB_IDRATIOB      0
#define BM_ASRC_ASRIDRHB_IDRATIOB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRHB_IDRATIOB(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRHB_IDRATIOB)
#else
#define BF_ASRC_ASRIDRHB_IDRATIOB(v)   (((v) << 0) & BM_ASRC_ASRIDRHB_IDRATIOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRHB_IDRATIOB(v)   BF_CS1(ASRC_ASRIDRHB, IDRATIOB, v)
#endif

/*
 * HW_ASRC_ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned IDRATIOB : 24;

    } B;
} hw_asrc_asridrlb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLB register
 */
#define HW_ASRC_ASRIDRLB_ADDR      (REGS_ASRC_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLB           (*(volatile hw_asrc_asridrlb_t *) HW_ASRC_ASRIDRLB_ADDR)
#define HW_ASRC_ASRIDRLB_RD()      (HW_ASRC_ASRIDRLB.U)
#define HW_ASRC_ASRIDRLB_WR(v)     (HW_ASRC_ASRIDRLB.U = (v))
#define HW_ASRC_ASRIDRLB_SET(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() |  (v)))
#define HW_ASRC_ASRIDRLB_CLR(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() & ~(v)))
#define HW_ASRC_ASRIDRLB_TOG(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRLB bitfields
 */

/* --- Register HW_ASRC_ASRIDRLB, field IDRATIOB */

#define BP_ASRC_ASRIDRLB_IDRATIOB      0
#define BM_ASRC_ASRIDRLB_IDRATIOB      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRLB_IDRATIOB(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRLB_IDRATIOB)
#else
#define BF_ASRC_ASRIDRLB_IDRATIOB(v)   (((v) << 0) & BM_ASRC_ASRIDRLB_IDRATIOB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRLB_IDRATIOB(v)   BF_CS1(ASRC_ASRIDRLB, IDRATIOB, v)
#endif

/*
 * HW_ASRC_ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 16;
        unsigned IDRATIOC : 8;

    } B;
} hw_asrc_asridrhc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHC register
 */
#define HW_ASRC_ASRIDRHC_ADDR      (REGS_ASRC_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHC           (*(volatile hw_asrc_asridrhc_t *) HW_ASRC_ASRIDRHC_ADDR)
#define HW_ASRC_ASRIDRHC_RD()      (HW_ASRC_ASRIDRHC.U)
#define HW_ASRC_ASRIDRHC_WR(v)     (HW_ASRC_ASRIDRHC.U = (v))
#define HW_ASRC_ASRIDRHC_SET(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() |  (v)))
#define HW_ASRC_ASRIDRHC_CLR(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() & ~(v)))
#define HW_ASRC_ASRIDRHC_TOG(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRHC bitfields
 */

/* --- Register HW_ASRC_ASRIDRHC, field IDRATIOC */

#define BP_ASRC_ASRIDRHC_IDRATIOC      0
#define BM_ASRC_ASRIDRHC_IDRATIOC      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRHC_IDRATIOC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRHC_IDRATIOC)
#else
#define BF_ASRC_ASRIDRHC_IDRATIOC(v)   (((v) << 0) & BM_ASRC_ASRIDRHC_IDRATIOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRHC_IDRATIOC(v)   BF_CS1(ASRC_ASRIDRHC, IDRATIOC, v)
#endif

/*
 * HW_ASRC_ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned IDRATIOC : 24;

    } B;
} hw_asrc_asridrlc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLC register
 */
#define HW_ASRC_ASRIDRLC_ADDR      (REGS_ASRC_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLC           (*(volatile hw_asrc_asridrlc_t *) HW_ASRC_ASRIDRLC_ADDR)
#define HW_ASRC_ASRIDRLC_RD()      (HW_ASRC_ASRIDRLC.U)
#define HW_ASRC_ASRIDRLC_WR(v)     (HW_ASRC_ASRIDRLC.U = (v))
#define HW_ASRC_ASRIDRLC_SET(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() |  (v)))
#define HW_ASRC_ASRIDRLC_CLR(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() & ~(v)))
#define HW_ASRC_ASRIDRLC_TOG(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRIDRLC bitfields
 */

/* --- Register HW_ASRC_ASRIDRLC, field IDRATIOC */

#define BP_ASRC_ASRIDRLC_IDRATIOC      0
#define BM_ASRC_ASRIDRLC_IDRATIOC      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRIDRLC_IDRATIOC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRIDRLC_IDRATIOC)
#else
#define BF_ASRC_ASRIDRLC_IDRATIOC(v)   (((v) << 0) & BM_ASRC_ASRIDRLC_IDRATIOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRIDRLC_IDRATIOC(v)   BF_CS1(ASRC_ASRIDRLC, IDRATIOC, v)
#endif

/*
 * HW_ASRC_ASR76K - ASRC 76kHz Period in terms of ASRC processing
                        clock
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 7;
        unsigned ASR76K : 17;

    } B;
} hw_asrc_asr76k_t;
#endif

/*
 * constants & macros for entire ASRC_ASR76K register
 */
#define HW_ASRC_ASR76K_ADDR      (REGS_ASRC_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASR76K           (*(volatile hw_asrc_asr76k_t *) HW_ASRC_ASR76K_ADDR)
#define HW_ASRC_ASR76K_RD()      (HW_ASRC_ASR76K.U)
#define HW_ASRC_ASR76K_WR(v)     (HW_ASRC_ASR76K.U = (v))
#define HW_ASRC_ASR76K_SET(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() |  (v)))
#define HW_ASRC_ASR76K_CLR(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() & ~(v)))
#define HW_ASRC_ASR76K_TOG(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASR76K bitfields
 */

/* --- Register HW_ASRC_ASR76K, field ASR76K */

#define BP_ASRC_ASR76K_ASR76K      0
#define BM_ASRC_ASR76K_ASR76K      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASR76K_ASR76K(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASR76K_ASR76K)
#else
#define BF_ASRC_ASR76K_ASR76K(v)   (((v) << 0) & BM_ASRC_ASR76K_ASR76K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASR76K_ASR76K(v)   BF_CS1(ASRC_ASR76K, ASR76K, v)
#endif

/*
 * HW_ASRC_ASR56K - ASRC 56kHz Period in terms of ASRC processing
                        clock
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 7;
        unsigned ASR56K : 17;

    } B;
} hw_asrc_asr56k_t;
#endif

/*
 * constants & macros for entire ASRC_ASR56K register
 */
#define HW_ASRC_ASR56K_ADDR      (REGS_ASRC_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASR56K           (*(volatile hw_asrc_asr56k_t *) HW_ASRC_ASR56K_ADDR)
#define HW_ASRC_ASR56K_RD()      (HW_ASRC_ASR56K.U)
#define HW_ASRC_ASR56K_WR(v)     (HW_ASRC_ASR56K.U = (v))
#define HW_ASRC_ASR56K_SET(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() |  (v)))
#define HW_ASRC_ASR56K_CLR(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() & ~(v)))
#define HW_ASRC_ASR56K_TOG(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASR56K bitfields
 */

/* --- Register HW_ASRC_ASR56K, field ASR56K */

#define BP_ASRC_ASR56K_ASR56K      0
#define BM_ASRC_ASR56K_ASR56K      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASR56K_ASR56K(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASR56K_ASR56K)
#else
#define BF_ASRC_ASR56K_ASR56K(v)   (((v) << 0) & BM_ASRC_ASR56K_ASR56K)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASR56K_ASR56K(v)   BF_CS1(ASRC_ASR56K, ASR56K, v)
#endif

/*
 * HW_ASRC_ASRMCRA - ASRC Misc Control Register for Pair A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ZEROBUFA : 1;
        unsigned EXTTHRSHA : 1;
        unsigned BUFSTALLA : 1;
        unsigned BYPASSPOLYA : 1;
        unsigned RESERVED1 : 2;
        unsigned OUTFIFO_THRESHOLDA : 6;
        unsigned RSYNIFA : 1;
        unsigned RSYNOFA : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_THRESHOLDA : 6;

    } B;
} hw_asrc_asrmcra_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRA register
 */
#define HW_ASRC_ASRMCRA_ADDR      (REGS_ASRC_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRA           (*(volatile hw_asrc_asrmcra_t *) HW_ASRC_ASRMCRA_ADDR)
#define HW_ASRC_ASRMCRA_RD()      (HW_ASRC_ASRMCRA.U)
#define HW_ASRC_ASRMCRA_WR(v)     (HW_ASRC_ASRMCRA.U = (v))
#define HW_ASRC_ASRMCRA_SET(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() |  (v)))
#define HW_ASRC_ASRMCRA_CLR(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() & ~(v)))
#define HW_ASRC_ASRMCRA_TOG(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMCRA bitfields
 */

/* --- Register HW_ASRC_ASRMCRA, field ZEROBUFA */

#define BP_ASRC_ASRMCRA_ZEROBUFA      23
#define BM_ASRC_ASRMCRA_ZEROBUFA      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_ZEROBUFA(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRMCRA_ZEROBUFA)
#else
#define BF_ASRC_ASRMCRA_ZEROBUFA(v)   (((v) << 23) & BM_ASRC_ASRMCRA_ZEROBUFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_ZEROBUFA(v)   BF_CS1(ASRC_ASRMCRA, ZEROBUFA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field EXTTHRSHA */

#define BP_ASRC_ASRMCRA_EXTTHRSHA      22
#define BM_ASRC_ASRMCRA_EXTTHRSHA      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_EXTTHRSHA(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRMCRA_EXTTHRSHA)
#else
#define BF_ASRC_ASRMCRA_EXTTHRSHA(v)   (((v) << 22) & BM_ASRC_ASRMCRA_EXTTHRSHA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_EXTTHRSHA(v)   BF_CS1(ASRC_ASRMCRA, EXTTHRSHA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field BUFSTALLA */

#define BP_ASRC_ASRMCRA_BUFSTALLA      21
#define BM_ASRC_ASRMCRA_BUFSTALLA      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_BUFSTALLA(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRMCRA_BUFSTALLA)
#else
#define BF_ASRC_ASRMCRA_BUFSTALLA(v)   (((v) << 21) & BM_ASRC_ASRMCRA_BUFSTALLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_BUFSTALLA(v)   BF_CS1(ASRC_ASRMCRA, BUFSTALLA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field BYPASSPOLYA */

#define BP_ASRC_ASRMCRA_BYPASSPOLYA      20
#define BM_ASRC_ASRMCRA_BYPASSPOLYA      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_BYPASSPOLYA(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRMCRA_BYPASSPOLYA)
#else
#define BF_ASRC_ASRMCRA_BYPASSPOLYA(v)   (((v) << 20) & BM_ASRC_ASRMCRA_BYPASSPOLYA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_BYPASSPOLYA(v)   BF_CS1(ASRC_ASRMCRA, BYPASSPOLYA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field OUTFIFO_THRESHOLDA */

#define BP_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA      12
#define BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA      0x0003f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA)
#else
#define BF_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)   (((v) << 12) & BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)   BF_CS1(ASRC_ASRMCRA, OUTFIFO_THRESHOLDA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field RSYNIFA */

#define BP_ASRC_ASRMCRA_RSYNIFA      11
#define BM_ASRC_ASRMCRA_RSYNIFA      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_RSYNIFA(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRMCRA_RSYNIFA)
#else
#define BF_ASRC_ASRMCRA_RSYNIFA(v)   (((v) << 11) & BM_ASRC_ASRMCRA_RSYNIFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_RSYNIFA(v)   BF_CS1(ASRC_ASRMCRA, RSYNIFA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field RSYNOFA */

#define BP_ASRC_ASRMCRA_RSYNOFA      10
#define BM_ASRC_ASRMCRA_RSYNOFA      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_RSYNOFA(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRMCRA_RSYNOFA)
#else
#define BF_ASRC_ASRMCRA_RSYNOFA(v)   (((v) << 10) & BM_ASRC_ASRMCRA_RSYNOFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_RSYNOFA(v)   BF_CS1(ASRC_ASRMCRA, RSYNOFA, v)
#endif

/* --- Register HW_ASRC_ASRMCRA, field INFIFO_THRESHOLDA */

#define BP_ASRC_ASRMCRA_INFIFO_THRESHOLDA      0
#define BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA)
#else
#define BF_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)   (((v) << 0) & BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)   BF_CS1(ASRC_ASRMCRA, INFIFO_THRESHOLDA, v)
#endif

/*
 * HW_ASRC_ASRFSTA - ASRC FIFO Status Register for Pair A
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned OAFA : 1;
        unsigned RESERVED1 : 4;
        unsigned OUTFIFO_FILLA : 7;
        unsigned IAEA : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_FILLA : 7;

    } B;
} hw_asrc_asrfsta_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTA register
 */
#define HW_ASRC_ASRFSTA_ADDR      (REGS_ASRC_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTA           (*(volatile hw_asrc_asrfsta_t *) HW_ASRC_ASRFSTA_ADDR)
#define HW_ASRC_ASRFSTA_RD()      (HW_ASRC_ASRFSTA.U)
#define HW_ASRC_ASRFSTA_WR(v)     (HW_ASRC_ASRFSTA.U = (v))
#define HW_ASRC_ASRFSTA_SET(v)    (HW_ASRC_ASRFSTA_WR(HW_ASRC_ASRFSTA_RD() |  (v)))
#define HW_ASRC_ASRFSTA_CLR(v)    (HW_ASRC_ASRFSTA_WR(HW_ASRC_ASRFSTA_RD() & ~(v)))
#define HW_ASRC_ASRFSTA_TOG(v)    (HW_ASRC_ASRFSTA_WR(HW_ASRC_ASRFSTA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRFSTA bitfields
 */

/* --- Register HW_ASRC_ASRFSTA, field OAFA */

#define BP_ASRC_ASRFSTA_OAFA      23
#define BM_ASRC_ASRFSTA_OAFA      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTA_OAFA(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRFSTA_OAFA)
#else
#define BF_ASRC_ASRFSTA_OAFA(v)   (((v) << 23) & BM_ASRC_ASRFSTA_OAFA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTA_OAFA(v)   BF_CS1(ASRC_ASRFSTA, OAFA, v)
#endif

/* --- Register HW_ASRC_ASRFSTA, field OUTFIFO_FILLA */

#define BP_ASRC_ASRFSTA_OUTFIFO_FILLA      12
#define BM_ASRC_ASRFSTA_OUTFIFO_FILLA      0x0007f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTA_OUTFIFO_FILLA(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRFSTA_OUTFIFO_FILLA)
#else
#define BF_ASRC_ASRFSTA_OUTFIFO_FILLA(v)   (((v) << 12) & BM_ASRC_ASRFSTA_OUTFIFO_FILLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTA_OUTFIFO_FILLA(v)   BF_CS1(ASRC_ASRFSTA, OUTFIFO_FILLA, v)
#endif

/* --- Register HW_ASRC_ASRFSTA, field IAEA */

#define BP_ASRC_ASRFSTA_IAEA      11
#define BM_ASRC_ASRFSTA_IAEA      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTA_IAEA(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRFSTA_IAEA)
#else
#define BF_ASRC_ASRFSTA_IAEA(v)   (((v) << 11) & BM_ASRC_ASRFSTA_IAEA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTA_IAEA(v)   BF_CS1(ASRC_ASRFSTA, IAEA, v)
#endif

/* --- Register HW_ASRC_ASRFSTA, field INFIFO_FILLA */

#define BP_ASRC_ASRFSTA_INFIFO_FILLA      0
#define BM_ASRC_ASRFSTA_INFIFO_FILLA      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTA_INFIFO_FILLA(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRFSTA_INFIFO_FILLA)
#else
#define BF_ASRC_ASRFSTA_INFIFO_FILLA(v)   (((v) << 0) & BM_ASRC_ASRFSTA_INFIFO_FILLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTA_INFIFO_FILLA(v)   BF_CS1(ASRC_ASRFSTA, INFIFO_FILLA, v)
#endif

/*
 * HW_ASRC_ASRMCRB - ASRC Misc Control Register for Pair B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ZEROBUFB : 1;
        unsigned EXTTHRSHB : 1;
        unsigned BUFSTALLB : 1;
        unsigned BYPASSPOLYB : 1;
        unsigned RESERVED1 : 2;
        unsigned OUTFIFO_THRESHOLDB : 6;
        unsigned RSYNIFB : 1;
        unsigned RSYNOFB : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_THRESHOLDB : 6;

    } B;
} hw_asrc_asrmcrb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRB register
 */
#define HW_ASRC_ASRMCRB_ADDR      (REGS_ASRC_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRB           (*(volatile hw_asrc_asrmcrb_t *) HW_ASRC_ASRMCRB_ADDR)
#define HW_ASRC_ASRMCRB_RD()      (HW_ASRC_ASRMCRB.U)
#define HW_ASRC_ASRMCRB_WR(v)     (HW_ASRC_ASRMCRB.U = (v))
#define HW_ASRC_ASRMCRB_SET(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() |  (v)))
#define HW_ASRC_ASRMCRB_CLR(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() & ~(v)))
#define HW_ASRC_ASRMCRB_TOG(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMCRB bitfields
 */

/* --- Register HW_ASRC_ASRMCRB, field ZEROBUFB */

#define BP_ASRC_ASRMCRB_ZEROBUFB      23
#define BM_ASRC_ASRMCRB_ZEROBUFB      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_ZEROBUFB(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRMCRB_ZEROBUFB)
#else
#define BF_ASRC_ASRMCRB_ZEROBUFB(v)   (((v) << 23) & BM_ASRC_ASRMCRB_ZEROBUFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_ZEROBUFB(v)   BF_CS1(ASRC_ASRMCRB, ZEROBUFB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field EXTTHRSHB */

#define BP_ASRC_ASRMCRB_EXTTHRSHB      22
#define BM_ASRC_ASRMCRB_EXTTHRSHB      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_EXTTHRSHB(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRMCRB_EXTTHRSHB)
#else
#define BF_ASRC_ASRMCRB_EXTTHRSHB(v)   (((v) << 22) & BM_ASRC_ASRMCRB_EXTTHRSHB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_EXTTHRSHB(v)   BF_CS1(ASRC_ASRMCRB, EXTTHRSHB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field BUFSTALLB */

#define BP_ASRC_ASRMCRB_BUFSTALLB      21
#define BM_ASRC_ASRMCRB_BUFSTALLB      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_BUFSTALLB(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRMCRB_BUFSTALLB)
#else
#define BF_ASRC_ASRMCRB_BUFSTALLB(v)   (((v) << 21) & BM_ASRC_ASRMCRB_BUFSTALLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_BUFSTALLB(v)   BF_CS1(ASRC_ASRMCRB, BUFSTALLB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field BYPASSPOLYB */

#define BP_ASRC_ASRMCRB_BYPASSPOLYB      20
#define BM_ASRC_ASRMCRB_BYPASSPOLYB      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_BYPASSPOLYB(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRMCRB_BYPASSPOLYB)
#else
#define BF_ASRC_ASRMCRB_BYPASSPOLYB(v)   (((v) << 20) & BM_ASRC_ASRMCRB_BYPASSPOLYB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_BYPASSPOLYB(v)   BF_CS1(ASRC_ASRMCRB, BYPASSPOLYB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field OUTFIFO_THRESHOLDB */

#define BP_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB      12
#define BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB      0x0003f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB)
#else
#define BF_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)   (((v) << 12) & BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)   BF_CS1(ASRC_ASRMCRB, OUTFIFO_THRESHOLDB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field RSYNIFB */

#define BP_ASRC_ASRMCRB_RSYNIFB      11
#define BM_ASRC_ASRMCRB_RSYNIFB      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_RSYNIFB(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRMCRB_RSYNIFB)
#else
#define BF_ASRC_ASRMCRB_RSYNIFB(v)   (((v) << 11) & BM_ASRC_ASRMCRB_RSYNIFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_RSYNIFB(v)   BF_CS1(ASRC_ASRMCRB, RSYNIFB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field RSYNOFB */

#define BP_ASRC_ASRMCRB_RSYNOFB      10
#define BM_ASRC_ASRMCRB_RSYNOFB      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_RSYNOFB(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRMCRB_RSYNOFB)
#else
#define BF_ASRC_ASRMCRB_RSYNOFB(v)   (((v) << 10) & BM_ASRC_ASRMCRB_RSYNOFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_RSYNOFB(v)   BF_CS1(ASRC_ASRMCRB, RSYNOFB, v)
#endif

/* --- Register HW_ASRC_ASRMCRB, field INFIFO_THRESHOLDB */

#define BP_ASRC_ASRMCRB_INFIFO_THRESHOLDB      0
#define BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB)
#else
#define BF_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)   (((v) << 0) & BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)   BF_CS1(ASRC_ASRMCRB, INFIFO_THRESHOLDB, v)
#endif

/*
 * HW_ASRC_ASRFSTB - ASRC FIFO Status Register for Pair B
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned OAFB : 1;
        unsigned RESERVED1 : 4;
        unsigned OUTFIFO_FILLB : 7;
        unsigned IAEB : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_FILLB : 7;

    } B;
} hw_asrc_asrfstb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTB register
 */
#define HW_ASRC_ASRFSTB_ADDR      (REGS_ASRC_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTB           (*(volatile hw_asrc_asrfstb_t *) HW_ASRC_ASRFSTB_ADDR)
#define HW_ASRC_ASRFSTB_RD()      (HW_ASRC_ASRFSTB.U)
#define HW_ASRC_ASRFSTB_WR(v)     (HW_ASRC_ASRFSTB.U = (v))
#define HW_ASRC_ASRFSTB_SET(v)    (HW_ASRC_ASRFSTB_WR(HW_ASRC_ASRFSTB_RD() |  (v)))
#define HW_ASRC_ASRFSTB_CLR(v)    (HW_ASRC_ASRFSTB_WR(HW_ASRC_ASRFSTB_RD() & ~(v)))
#define HW_ASRC_ASRFSTB_TOG(v)    (HW_ASRC_ASRFSTB_WR(HW_ASRC_ASRFSTB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRFSTB bitfields
 */

/* --- Register HW_ASRC_ASRFSTB, field OAFB */

#define BP_ASRC_ASRFSTB_OAFB      23
#define BM_ASRC_ASRFSTB_OAFB      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTB_OAFB(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRFSTB_OAFB)
#else
#define BF_ASRC_ASRFSTB_OAFB(v)   (((v) << 23) & BM_ASRC_ASRFSTB_OAFB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTB_OAFB(v)   BF_CS1(ASRC_ASRFSTB, OAFB, v)
#endif

/* --- Register HW_ASRC_ASRFSTB, field OUTFIFO_FILLB */

#define BP_ASRC_ASRFSTB_OUTFIFO_FILLB      12
#define BM_ASRC_ASRFSTB_OUTFIFO_FILLB      0x0007f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTB_OUTFIFO_FILLB(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRFSTB_OUTFIFO_FILLB)
#else
#define BF_ASRC_ASRFSTB_OUTFIFO_FILLB(v)   (((v) << 12) & BM_ASRC_ASRFSTB_OUTFIFO_FILLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTB_OUTFIFO_FILLB(v)   BF_CS1(ASRC_ASRFSTB, OUTFIFO_FILLB, v)
#endif

/* --- Register HW_ASRC_ASRFSTB, field IAEB */

#define BP_ASRC_ASRFSTB_IAEB      11
#define BM_ASRC_ASRFSTB_IAEB      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTB_IAEB(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRFSTB_IAEB)
#else
#define BF_ASRC_ASRFSTB_IAEB(v)   (((v) << 11) & BM_ASRC_ASRFSTB_IAEB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTB_IAEB(v)   BF_CS1(ASRC_ASRFSTB, IAEB, v)
#endif

/* --- Register HW_ASRC_ASRFSTB, field INFIFO_FILLB */

#define BP_ASRC_ASRFSTB_INFIFO_FILLB      0
#define BM_ASRC_ASRFSTB_INFIFO_FILLB      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTB_INFIFO_FILLB(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRFSTB_INFIFO_FILLB)
#else
#define BF_ASRC_ASRFSTB_INFIFO_FILLB(v)   (((v) << 0) & BM_ASRC_ASRFSTB_INFIFO_FILLB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTB_INFIFO_FILLB(v)   BF_CS1(ASRC_ASRFSTB, INFIFO_FILLB, v)
#endif

/*
 * HW_ASRC_ASRMCRC - ASRC Misc Control Register for Pair C
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned ZEROBUFC : 1;
        unsigned EXTTHRSHC : 1;
        unsigned BUFSTALLC : 1;
        unsigned BYPASSPOLYC : 1;
        unsigned RESERVED1 : 2;
        unsigned OUTFIFO_THRESHOLDC : 6;
        unsigned RSYNIFC : 1;
        unsigned RSYNOFC : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_THRESHOLDC : 6;

    } B;
} hw_asrc_asrmcrc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRC register
 */
#define HW_ASRC_ASRMCRC_ADDR      (REGS_ASRC_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRC           (*(volatile hw_asrc_asrmcrc_t *) HW_ASRC_ASRMCRC_ADDR)
#define HW_ASRC_ASRMCRC_RD()      (HW_ASRC_ASRMCRC.U)
#define HW_ASRC_ASRMCRC_WR(v)     (HW_ASRC_ASRMCRC.U = (v))
#define HW_ASRC_ASRMCRC_SET(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() |  (v)))
#define HW_ASRC_ASRMCRC_CLR(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() & ~(v)))
#define HW_ASRC_ASRMCRC_TOG(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMCRC bitfields
 */

/* --- Register HW_ASRC_ASRMCRC, field ZEROBUFC */

#define BP_ASRC_ASRMCRC_ZEROBUFC      23
#define BM_ASRC_ASRMCRC_ZEROBUFC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_ZEROBUFC(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRMCRC_ZEROBUFC)
#else
#define BF_ASRC_ASRMCRC_ZEROBUFC(v)   (((v) << 23) & BM_ASRC_ASRMCRC_ZEROBUFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_ZEROBUFC(v)   BF_CS1(ASRC_ASRMCRC, ZEROBUFC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field EXTTHRSHC */

#define BP_ASRC_ASRMCRC_EXTTHRSHC      22
#define BM_ASRC_ASRMCRC_EXTTHRSHC      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_EXTTHRSHC(v)   ((((reg32_t) v) << 22) & BM_ASRC_ASRMCRC_EXTTHRSHC)
#else
#define BF_ASRC_ASRMCRC_EXTTHRSHC(v)   (((v) << 22) & BM_ASRC_ASRMCRC_EXTTHRSHC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_EXTTHRSHC(v)   BF_CS1(ASRC_ASRMCRC, EXTTHRSHC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field BUFSTALLC */

#define BP_ASRC_ASRMCRC_BUFSTALLC      21
#define BM_ASRC_ASRMCRC_BUFSTALLC      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_BUFSTALLC(v)   ((((reg32_t) v) << 21) & BM_ASRC_ASRMCRC_BUFSTALLC)
#else
#define BF_ASRC_ASRMCRC_BUFSTALLC(v)   (((v) << 21) & BM_ASRC_ASRMCRC_BUFSTALLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_BUFSTALLC(v)   BF_CS1(ASRC_ASRMCRC, BUFSTALLC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field BYPASSPOLYC */

#define BP_ASRC_ASRMCRC_BYPASSPOLYC      20
#define BM_ASRC_ASRMCRC_BYPASSPOLYC      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_BYPASSPOLYC(v)   ((((reg32_t) v) << 20) & BM_ASRC_ASRMCRC_BYPASSPOLYC)
#else
#define BF_ASRC_ASRMCRC_BYPASSPOLYC(v)   (((v) << 20) & BM_ASRC_ASRMCRC_BYPASSPOLYC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_BYPASSPOLYC(v)   BF_CS1(ASRC_ASRMCRC, BYPASSPOLYC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field OUTFIFO_THRESHOLDC */

#define BP_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC      12
#define BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC      0x0003f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC)
#else
#define BF_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)   (((v) << 12) & BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)   BF_CS1(ASRC_ASRMCRC, OUTFIFO_THRESHOLDC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field RSYNIFC */

#define BP_ASRC_ASRMCRC_RSYNIFC      11
#define BM_ASRC_ASRMCRC_RSYNIFC      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_RSYNIFC(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRMCRC_RSYNIFC)
#else
#define BF_ASRC_ASRMCRC_RSYNIFC(v)   (((v) << 11) & BM_ASRC_ASRMCRC_RSYNIFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_RSYNIFC(v)   BF_CS1(ASRC_ASRMCRC, RSYNIFC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field RSYNOFC */

#define BP_ASRC_ASRMCRC_RSYNOFC      10
#define BM_ASRC_ASRMCRC_RSYNOFC      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_RSYNOFC(v)   ((((reg32_t) v) << 10) & BM_ASRC_ASRMCRC_RSYNOFC)
#else
#define BF_ASRC_ASRMCRC_RSYNOFC(v)   (((v) << 10) & BM_ASRC_ASRMCRC_RSYNOFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_RSYNOFC(v)   BF_CS1(ASRC_ASRMCRC, RSYNOFC, v)
#endif

/* --- Register HW_ASRC_ASRMCRC, field INFIFO_THRESHOLDC */

#define BP_ASRC_ASRMCRC_INFIFO_THRESHOLDC      0
#define BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC)
#else
#define BF_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)   (((v) << 0) & BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)   BF_CS1(ASRC_ASRMCRC, INFIFO_THRESHOLDC, v)
#endif

/*
 * HW_ASRC_ASRFSTC - ASRC FIFO Status Register for Pair C
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned OAFC : 1;
        unsigned RESERVED1 : 4;
        unsigned OUTFIFO_FILLC : 7;
        unsigned IAEC : 1;
        unsigned RESERVED2 : 4;
        unsigned INFIFO_FILLC : 7;

    } B;
} hw_asrc_asrfstc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTC register
 */
#define HW_ASRC_ASRFSTC_ADDR      (REGS_ASRC_BASE + 0xb4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTC           (*(volatile hw_asrc_asrfstc_t *) HW_ASRC_ASRFSTC_ADDR)
#define HW_ASRC_ASRFSTC_RD()      (HW_ASRC_ASRFSTC.U)
#define HW_ASRC_ASRFSTC_WR(v)     (HW_ASRC_ASRFSTC.U = (v))
#define HW_ASRC_ASRFSTC_SET(v)    (HW_ASRC_ASRFSTC_WR(HW_ASRC_ASRFSTC_RD() |  (v)))
#define HW_ASRC_ASRFSTC_CLR(v)    (HW_ASRC_ASRFSTC_WR(HW_ASRC_ASRFSTC_RD() & ~(v)))
#define HW_ASRC_ASRFSTC_TOG(v)    (HW_ASRC_ASRFSTC_WR(HW_ASRC_ASRFSTC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRFSTC bitfields
 */

/* --- Register HW_ASRC_ASRFSTC, field OAFC */

#define BP_ASRC_ASRFSTC_OAFC      23
#define BM_ASRC_ASRFSTC_OAFC      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTC_OAFC(v)   ((((reg32_t) v) << 23) & BM_ASRC_ASRFSTC_OAFC)
#else
#define BF_ASRC_ASRFSTC_OAFC(v)   (((v) << 23) & BM_ASRC_ASRFSTC_OAFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTC_OAFC(v)   BF_CS1(ASRC_ASRFSTC, OAFC, v)
#endif

/* --- Register HW_ASRC_ASRFSTC, field OUTFIFO_FILLC */

#define BP_ASRC_ASRFSTC_OUTFIFO_FILLC      12
#define BM_ASRC_ASRFSTC_OUTFIFO_FILLC      0x0007f000

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTC_OUTFIFO_FILLC(v)   ((((reg32_t) v) << 12) & BM_ASRC_ASRFSTC_OUTFIFO_FILLC)
#else
#define BF_ASRC_ASRFSTC_OUTFIFO_FILLC(v)   (((v) << 12) & BM_ASRC_ASRFSTC_OUTFIFO_FILLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTC_OUTFIFO_FILLC(v)   BF_CS1(ASRC_ASRFSTC, OUTFIFO_FILLC, v)
#endif

/* --- Register HW_ASRC_ASRFSTC, field IAEC */

#define BP_ASRC_ASRFSTC_IAEC      11
#define BM_ASRC_ASRFSTC_IAEC      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTC_IAEC(v)   ((((reg32_t) v) << 11) & BM_ASRC_ASRFSTC_IAEC)
#else
#define BF_ASRC_ASRFSTC_IAEC(v)   (((v) << 11) & BM_ASRC_ASRFSTC_IAEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTC_IAEC(v)   BF_CS1(ASRC_ASRFSTC, IAEC, v)
#endif

/* --- Register HW_ASRC_ASRFSTC, field INFIFO_FILLC */

#define BP_ASRC_ASRFSTC_INFIFO_FILLC      0
#define BM_ASRC_ASRFSTC_INFIFO_FILLC      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRFSTC_INFIFO_FILLC(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRFSTC_INFIFO_FILLC)
#else
#define BF_ASRC_ASRFSTC_INFIFO_FILLC(v)   (((v) << 0) & BM_ASRC_ASRFSTC_INFIFO_FILLC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRFSTC_INFIFO_FILLC(v)   BF_CS1(ASRC_ASRFSTC, INFIFO_FILLC, v)
#endif

/*
 * HW_ASRC_ASRMCR1 - ASRC Misc Control Register 1 for Pair X
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8;
        unsigned RESERVED1 : 12;
        unsigned IWD : 3;
        unsigned IMSB : 1;
        unsigned RESERVED2 : 5;
        unsigned OMSB : 1;
        unsigned OSGN : 1;
        unsigned OW16 : 1;

    } B;
} hw_asrc_asrmcr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCR1 register
 */
#define HW_ASRC_ASRMCR1_ADDR      (REGS_ASRC_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCR1           (*(volatile hw_asrc_asrmcr1_t *) HW_ASRC_ASRMCR1_ADDR)
#define HW_ASRC_ASRMCR1_RD()      (HW_ASRC_ASRMCR1.U)
#define HW_ASRC_ASRMCR1_WR(v)     (HW_ASRC_ASRMCR1.U = (v))
#define HW_ASRC_ASRMCR1_SET(v)    (HW_ASRC_ASRMCR1_WR(HW_ASRC_ASRMCR1_RD() |  (v)))
#define HW_ASRC_ASRMCR1_CLR(v)    (HW_ASRC_ASRMCR1_WR(HW_ASRC_ASRMCR1_RD() & ~(v)))
#define HW_ASRC_ASRMCR1_TOG(v)    (HW_ASRC_ASRMCR1_WR(HW_ASRC_ASRMCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual ASRC_ASRMCR1 bitfields
 */

/* --- Register HW_ASRC_ASRMCR1, field IWD */

#define BP_ASRC_ASRMCR1_IWD      9
#define BM_ASRC_ASRMCR1_IWD      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCR1_IWD(v)   ((((reg32_t) v) << 9) & BM_ASRC_ASRMCR1_IWD)
#else
#define BF_ASRC_ASRMCR1_IWD(v)   (((v) << 9) & BM_ASRC_ASRMCR1_IWD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCR1_IWD(v)   BF_CS1(ASRC_ASRMCR1, IWD, v)
#endif

/* --- Register HW_ASRC_ASRMCR1, field IMSB */

#define BP_ASRC_ASRMCR1_IMSB      8
#define BM_ASRC_ASRMCR1_IMSB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCR1_IMSB(v)   ((((reg32_t) v) << 8) & BM_ASRC_ASRMCR1_IMSB)
#else
#define BF_ASRC_ASRMCR1_IMSB(v)   (((v) << 8) & BM_ASRC_ASRMCR1_IMSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCR1_IMSB(v)   BF_CS1(ASRC_ASRMCR1, IMSB, v)
#endif

/* --- Register HW_ASRC_ASRMCR1, field OMSB */

#define BP_ASRC_ASRMCR1_OMSB      2
#define BM_ASRC_ASRMCR1_OMSB      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCR1_OMSB(v)   ((((reg32_t) v) << 2) & BM_ASRC_ASRMCR1_OMSB)
#else
#define BF_ASRC_ASRMCR1_OMSB(v)   (((v) << 2) & BM_ASRC_ASRMCR1_OMSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCR1_OMSB(v)   BF_CS1(ASRC_ASRMCR1, OMSB, v)
#endif

/* --- Register HW_ASRC_ASRMCR1, field OSGN */

#define BP_ASRC_ASRMCR1_OSGN      1
#define BM_ASRC_ASRMCR1_OSGN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCR1_OSGN(v)   ((((reg32_t) v) << 1) & BM_ASRC_ASRMCR1_OSGN)
#else
#define BF_ASRC_ASRMCR1_OSGN(v)   (((v) << 1) & BM_ASRC_ASRMCR1_OSGN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCR1_OSGN(v)   BF_CS1(ASRC_ASRMCR1, OSGN, v)
#endif

/* --- Register HW_ASRC_ASRMCR1, field OW16 */

#define BP_ASRC_ASRMCR1_OW16      0
#define BM_ASRC_ASRMCR1_OW16      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ASRC_ASRMCR1_OW16(v)   ((((reg32_t) v) << 0) & BM_ASRC_ASRMCR1_OW16)
#else
#define BF_ASRC_ASRMCR1_OW16(v)   (((v) << 0) & BM_ASRC_ASRMCR1_OW16)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_ASRC_ASRMCR1_OW16(v)   BF_CS1(ASRC_ASRMCR1, OW16, v)
#endif


#endif // _ASRC_H

