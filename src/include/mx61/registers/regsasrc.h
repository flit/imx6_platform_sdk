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


/*!
 * @brief HW_ASRC_ASRCTR - ASRC Control Register
 *
 * The ASRC control register (ASRCTR) is a 24-bit read/write register that
 * controls the ASRC operations.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ASRCEN : 1; //!< ASRC Enable  Enable the operation of ASRC.
        unsigned ASREA : 1; //!< ASRC Enable A  Enable the operation of the conversion A of ASRC. When ASREA is cleared, operation of conversion A is disabled.
        unsigned ASREB : 1; //!< ASRC Enable B  Enable the operation of the conversion B of ASRC. When ASREB is cleared, operation of conversion B is disabled.
        unsigned ASREC : 1; //!< ASRC Enable C  Enable the operation of the conversion C of ASRC. When ASREC is cleared, operation of conversion C is disabled.
        unsigned SRST : 1; //!< Software Reset  This bit is self-clear bit. Once it is been written as 1, it will generate a software reset signal inside ASRC. After 9 cycles of the ASRC processing clock, this reset process will stop, and this bit will be cleared automatically.
        unsigned RESERVED0 : 8; //!< Reserved. Should be written as zero for compatibility.
        unsigned IDRA : 1; //!< Use Ideal Ratio for Pair A  When USRA=0, this bit has no usage.  When USRA=1 and IDRA=0, ASRC internal measured ratio will be used.  When USRA=1 and IDRA=1, the idea ratio from the interface register ASRIDRHA, ASRIDRLA will be used. It is suggested to manually set ASRCFG:POSTMODA, ASRCFG:PREMODA according to in this case.
        unsigned USRA : 1; //!< Use Ratio for Pair A  Use ratio as the input to ASRC. This bit is used in conjunction with IDRA control bit.
        unsigned IDRB : 1; //!< Use Ideal Ratio for Pair B  When USRB=0, this bit has no usage.  When USRB=1 and IDRB=0, ASRC internal measured ratio will be used.  When USRB=1 and IDRB=1, the idea ratio from the interface register ASRIDRHB, ASRIDRLB will be used.It is suggested to manually set ASRCFG:POSTMODB, ASRCFG:PREMODB according to in this case.
        unsigned USRB : 1; //!< Use Ratio for Pair B  Use ratio as the input to ASRC. This bit is used in conjunction with IDRB control bit.
        unsigned IDRC : 1; //!< Use Ideal Ratio for Pair C  When USRC=0, this bit has no usage.  When USRC=1 and IDRC=0, ASRC internal measured ratio will be used.  When USRC=1 and IDRC=1, the idea ratio from the interface register ASRIDRHC, ASRIDRLC will be used. It is suggested to manually set ASRCFG:POSTMODC, ASRCFG:PREMODC according to in this case.
        unsigned USRC : 1; //!< Use Ratio for Pair C  Use ratio as the input to ASRC. This bit is used in conjunction with IDRC control bit.
        unsigned RESERVED1 : 1; //!< Reserved. Should be written as zero for compatibility.
        unsigned ATSA : 1; //!< ASRC Pair A Automatic Selection For Processing Options  When this bit is 1, pair A will automatic update its pre-processing and post-processing options (ASRCFG: PREMODA, ASRCFG:POSTMODA , ASRCFG:HFA see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ).  When this bit is 0, the user is responsible for choosing the proper processing options for pair A.  This bit should be disabled when {USRA, IDRA}={1,1}.
        unsigned ATSB : 1; //!< ASRC Pair B Automatic Selection For Processing Options  When this bit is 1, pair B will automatic update its pre-processing and post-processing options (ASRCFG: PREMODB, ASRCFG:POSTMODB , ASRCFG:HFB see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ).  When this bit is 0, the user is responsible for choosing the proper processing options for pair B.  This bit should be disabled when {USRB, IDRB}={1,1}.
        unsigned ATSC : 1; //!< ASRC Pair C Automatic Selection For Processing Options  When this bit is 1, pair C will automatic update its pre-processing and post-processing options (ASRCFG: PREMODC, ASRCFG:POSTMODC , ASRCFG:HFC see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ).  When this bit is 0, the user is responsible for choosing the proper processing options for pair C. This bit should be disabled when {USRC, IDRC}={1,1}.
        unsigned RESERVED2 : 1; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED3 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCTR, field ASRCEN
 *
 * ASRC Enable  Enable the operation of ASRC.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ASREA
 *
 * ASRC Enable A  Enable the operation of the conversion A of ASRC. When ASREA is
 * cleared, operation of conversion A is disabled.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ASREB
 *
 * ASRC Enable B  Enable the operation of the conversion B of ASRC. When ASREB is
 * cleared, operation of conversion B is disabled.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ASREC
 *
 * ASRC Enable C  Enable the operation of the conversion C of ASRC. When ASREC is
 * cleared, operation of conversion C is disabled.
 */

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

/* --- Register HW_ASRC_ASRCTR, field SRST
 *
 * Software Reset  This bit is self-clear bit. Once it is been written as 1, it will
 * generate a software reset signal inside ASRC. After 9 cycles of the
 * ASRC processing clock, this reset process will stop, and this bit
 * will be cleared automatically.
 */

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

/* --- Register HW_ASRC_ASRCTR, field IDRA
 *
 * Use Ideal Ratio for Pair A  When USRA=0, this bit has no usage.  When USRA=1 and IDRA=0, ASRC
 * internal measured ratio will be                                 used.  When USRA=1 and IDRA=1,
 * the idea ratio from the interface register                                 ASRIDRHA, ASRIDRLA
 * will be used. It is suggested to manually set                                 ASRCFG:POSTMODA,
 * ASRCFG:PREMODA according to in this case.
 */

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

/* --- Register HW_ASRC_ASRCTR, field USRA
 *
 * Use Ratio for Pair A  Use ratio as the input to ASRC. This bit is used in conjunction with
 * IDRA control bit.
 */

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

/* --- Register HW_ASRC_ASRCTR, field IDRB
 *
 * Use Ideal Ratio for Pair B  When USRB=0, this bit has no usage.  When USRB=1 and IDRB=0, ASRC
 * internal measured ratio will be                                 used.  When USRB=1 and IDRB=1,
 * the idea ratio from the interface register                                 ASRIDRHB, ASRIDRLB
 * will be used.It is suggested to manually set                                 ASRCFG:POSTMODB,
 * ASRCFG:PREMODB according to in this case.
 */

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

/* --- Register HW_ASRC_ASRCTR, field USRB
 *
 * Use Ratio for Pair B  Use ratio as the input to ASRC. This bit is used in conjunction with
 * IDRB control bit.
 */

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

/* --- Register HW_ASRC_ASRCTR, field IDRC
 *
 * Use Ideal Ratio for Pair C  When USRC=0, this bit has no usage.  When USRC=1 and IDRC=0, ASRC
 * internal measured ratio will be                                 used.  When USRC=1 and IDRC=1,
 * the idea ratio from the interface register                                 ASRIDRHC, ASRIDRLC
 * will be used. It is suggested to manually set                                 ASRCFG:POSTMODC,
 * ASRCFG:PREMODC according to in this case.
 */

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

/* --- Register HW_ASRC_ASRCTR, field USRC
 *
 * Use Ratio for Pair C  Use ratio as the input to ASRC. This bit is used in conjunction with
 * IDRC control bit.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ATSA
 *
 * ASRC Pair A Automatic Selection For Processing Options  When this bit is 1, pair A will automatic
 * update its pre-processing                                 and post-processing options (ASRCFG:
 * PREMODA, ASRCFG:POSTMODA , ASRCFG:HFA see ASRC Misc Control Register 1
 * for Pair C ) based on the frequencies it detected. To use this option, the two
 * parameter registers(ASR76K and ASR56K) should be set correctly
 * (see ASRC Misc Control                                         Register 1 for Pair C and ASRC
 * Misc Control Register                                         1 for Pair C ).  When this bit is
 * 0, the user is responsible for choosing the proper                                 processing
 * options for pair A.  This bit should be disabled when                                 {USRA,
 * IDRA}={1,1}.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ATSB
 *
 * ASRC Pair B Automatic Selection For Processing Options  When this bit is 1, pair B will automatic
 * update its pre-processing                                 and post-processing options (ASRCFG:
 * PREMODB, ASRCFG:POSTMODB , ASRCFG:HFB see ASRC Misc Control Register 1
 * for Pair C ) based on the frequencies it detected. To use                                 this
 * option, the two parameter registers(ASR76K and ASR56K) should                                 be
 * set correctly (see ASRC                                     Misc Control Register 1 for Pair C
 * and ASRC Misc Control Register 1                                     for Pair C ).  When this bit
 * is 0, the user is responsible for choosing the proper                                 processing
 * options for pair B.  This bit should be disabled when {USRB, IDRB}={1,1}.
 */

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

/* --- Register HW_ASRC_ASRCTR, field ATSC
 *
 * ASRC Pair C Automatic Selection For Processing Options  When this bit is 1, pair C will automatic
 * update its pre-processing                                 and post-processing options (ASRCFG:
 * PREMODC, ASRCFG:POSTMODC , ASRCFG:HFC see ASRC Misc Control Register 1
 * for Pair C ) based on the frequencies it detected. To use                                 this
 * option, the two parameter registers(ASR76K and ASR56K) should                                 be
 * set correctly (see ASRC                                     Misc Control Register 1 for Pair C
 * and ASRC Misc Control Register 1                                     for Pair C ).  When this bit
 * is 0, the user is responsible for choosing the proper                                 processing
 * options for pair C. This bit should be disabled when                             {USRC,
 * IDRC}={1,1}.
 */

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

/*!
 * @brief HW_ASRC_ASRIER - ASRC Interrupt Enable Register
 *
 * These 8 bits combined with corresponding 8 LSBs                                 in ASRSTR
 * register can generate interrupt requests.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADIEA : 1; //!< Data Input A Interrupt Enable  Enables the data input A Interrupt.
        unsigned ADIEB : 1; //!< Data Input B Interrupt Enable  Enables the data input B interrupt.
        unsigned ADIEC : 1; //!< Data Input C Interrupt Enable  Enables the data input C interrupt.
        unsigned ADOEA : 1; //!< Data Output A Interrupt Enable  Enables the data output A interrupt.
        unsigned ADOEB : 1; //!< Data Output B Interrupt Enable  Enables the data output B interrupt.
        unsigned ADOEC : 1; //!< Data Output C Interrupt Enable  Enables the data output C interrupt.
        unsigned AOLIE : 1; //!< Overload Interrupt Enable  Enables the overload interrupt.
        unsigned AFPWE : 1; //!< FP in Wait State Interrupt Enable  Enables the FP in wait state interrupt.
        unsigned RESERVED0 : 16; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIER, field ADIEA
 *
 * Data Input A Interrupt Enable  Enables the data input A Interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field ADIEB
 *
 * Data Input B Interrupt Enable  Enables the data input B interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field ADIEC
 *
 * Data Input C Interrupt Enable  Enables the data input C interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field ADOEA
 *
 * Data Output A Interrupt Enable  Enables the data output A interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field ADOEB
 *
 * Data Output B Interrupt Enable  Enables the data output B interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field ADOEC
 *
 * Data Output C Interrupt Enable  Enables the data output C interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field AOLIE
 *
 * Overload Interrupt Enable  Enables the overload interrupt.
 */

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

/* --- Register HW_ASRC_ASRIER, field AFPWE
 *
 * FP in Wait State Interrupt Enable  Enables the FP in wait state interrupt.
 */

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

/*!
 * @brief HW_ASRC_ASRCNCR - ASRC Channel Number Configuration Register
 *
 * The ASRC channel number configuration register (ASRCNCR) is a 24-bit
 * read/write register that sets the number of channels used by each ASRC
 * conversion pair.  There are 10 channels available for distribution among 3 conversion
 * pairs, they are ordered as 0,1,...,9. The bottom [0, ANCA-1] channels
 * are used for pair A, the top [10-ANCC, 9] channels are used for pair C,
 * and the [ANCA, ANCA+ANCB-1] channels are allocated for pair B. In case
 * that ANCA=0, then the [0, ANCB-1] channels are assigned for pair B.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ANCA : 3; //!< Number of A Channels
        unsigned ANCB : 3; //!< Number of B Channels
        unsigned ANCC : 3; //!< Number of C Channels ANCC+ANCB+ANCA<=10. Hardware is not checking the constraint. Programmer should take the responsibility to ensure the constraint is satisfied.
        unsigned RESERVED0 : 15; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCNCR, field ANCA
 *
 * Number of A Channels
 */

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

/* --- Register HW_ASRC_ASRCNCR, field ANCB
 *
 * Number of B Channels
 */

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

/* --- Register HW_ASRC_ASRCNCR, field ANCC
 *
 * Number of C Channels ANCC+ANCB+ANCA<=10. Hardware is not
 * checking the constraint. Programmer should take the
 * responsibility to ensure the constraint is satisfied.
 */

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

/*!
 * @brief HW_ASRC_ASRCFG - ASRC Filter Configuration Status Register
 *
 * The ASRC configuration status register (ASRCFG) is a 24-bit read/write
 * register that sets and/or automatically senses the ASRC operations.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6; //!< Reserved. Should be written as zero for compatibility.
        unsigned PREMODA : 2; //!< Pre-Processing Configuration for Conversion Pair A  These bits will be read/write by user if ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODA : 2; //!< Post-Processing Configuration for Conversion Pair A  These bits will be read/write by user if ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned PREMODB : 2; //!< Pre-Processing Configuration for Conversion Pair B  These bits will be read/write by user if ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODB : 2; //!< Post-Processing Configuration for Conversion Pair B  These bits will be read/write by user if ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned PREMODC : 2; //!< Pre-Processing Configuration for Conversion Pair C  These bits will be read/write by user if ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODC : 2; //!< Post-Processing Configuration for Conversion Pair C  These bits will be read/write by user if ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned NDPRA : 1; //!< Not Use Default Parameters for RAM-stored Parameters For Conversion Pair A
        unsigned NDPRB : 1; //!< Not Use Default Parameters for RAM-stored Parameters For Conversion Pair B
        unsigned NDPRC : 1; //!< Not Use Default Parameters for RAM-stored Parameters For Conversion Pair C
        unsigned INIRQA : 1; //!< Initialization for Conversion Pair A is served  When this bit is 1, it means the initialization for conversion pair A is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREA=0 or ASRCTR:ASRCEN=0).
        unsigned INIRQB : 1; //!< Initialization for Conversion Pair B is served  When this bit is 1, it means the initialization for conversion pair B is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREB=0 or ASRCTR:ASRCEN=0).
        unsigned INIRQC : 1; //!< Initialization for Conversion Pair C is served  When this bit is 1, it means the initialization for conversion pair C is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREC=0 or ASRCTR:ASRCEN=0).
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCFG, field PREMODA
 *
 * Pre-Processing Configuration for Conversion Pair A  These bits will be read/write by user if
 * ASRCTR:ATSA=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSA=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the pre-
 * processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field POSTMODA
 *
 * Post-Processing Configuration for Conversion Pair A  These bits will be read/write by user if
 * ASRCTR:ATSA=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSA=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the
 * post-processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field PREMODB
 *
 * Pre-Processing Configuration for Conversion Pair B  These bits will be read/write by user if
 * ASRCTR:ATSB=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSB=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the pre-
 * processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field POSTMODB
 *
 * Post-Processing Configuration for Conversion Pair B  These bits will be read/write by user if
 * ASRCTR:ATSB=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSB=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the
 * post-processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field PREMODC
 *
 * Pre-Processing Configuration for Conversion Pair C  These bits will be read/write by user if
 * ASRCTR:ATSC=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSC=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the pre-
 * processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field POSTMODC
 *
 * Post-Processing Configuration for Conversion Pair C  These bits will be read/write by user if
 * ASRCTR:ATSC=0, and can also                                 be automatically updated by the ASRC
 * internal logic if ASRCTR:ATSC=1                                 (see ASRC Misc Control
 * Register 1 for Pair C ). These bits set the selection of                                 the
 * post-processing configuration.
 */

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

/* --- Register HW_ASRC_ASRCFG, field NDPRA
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion
 * Pair A
 */

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

/* --- Register HW_ASRC_ASRCFG, field NDPRB
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion
 * Pair B
 */

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

/* --- Register HW_ASRC_ASRCFG, field NDPRC
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion
 * Pair C
 */

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

/* --- Register HW_ASRC_ASRCFG, field INIRQA
 *
 * Initialization for Conversion Pair A is served  When this bit is 1, it means the initialization
 * for conversion pair A                                 is served. This bit is cleared by disabling
 * the ASRC conversion pair                                 (ASRCTR:ASREA=0 or ASRCTR:ASRCEN=0).
 */

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

/* --- Register HW_ASRC_ASRCFG, field INIRQB
 *
 * Initialization for Conversion Pair B is served  When this bit is 1, it means the initialization
 * for conversion pair B                                 is served. This bit is cleared by disabling
 * the ASRC conversion pair                                 (ASRCTR:ASREB=0 or ASRCTR:ASRCEN=0).
 */

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

/* --- Register HW_ASRC_ASRCFG, field INIRQC
 *
 * Initialization for Conversion Pair C is served  When this bit is 1, it means the initialization
 * for conversion pair C                                 is served. This bit is cleared by disabling
 * the ASRC conversion pair                                 (ASRCTR:ASREC=0 or ASRCTR:ASRCEN=0).
 */

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

/*!
 * @brief HW_ASRC_ASRCSR - ASRC Clock Source Register
 *
 * The ASRC clock source register (ASRCSR) is a 24-bit read/write register
 * that controls the sources of the input and output clocks of the ASRC.  The clock connections are
 * shown in ASRC Misc Control Register 1 for Pair C , also shown in :   Bit Clock Definitions
 * Bit Clk Name  Definitions      0  ESAI RX clock    1  SSI-1 RX clock    2  SSI-2 RX clock    3
 * SSI-3 RX clock    4  SPDIF RX clock    5  MLB Bit clock    6  bit clock 6 should connect to one
 * of the three pads: KEY_ROW3,GPIO_0,GPIO_18, which is configured by register
 * IOMUXC_IOMUXC_ASRC_ASRCK_CLOCK_6_SELECT_INPUT    7  tied to zero    8  ESAI TX clock    9  SSI-1
 * TX clock    a  SSI-2 TX clock    b  SSI-3 TX clock    c  SPDIF TX clock    d  bit clock d is
 * configured by spdif1_clk_pred and spdif1_clk_podf in CCM_CDCDR, but it is better to describe it
 * also in CCM spec.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AICSA : 4; //!< Input Clock Source A
        unsigned AICSB : 4; //!< Input Clock Source B
        unsigned AICSC : 4; //!< Input Clock Source C
        unsigned AOCSA : 4; //!< Output Clock Source A
        unsigned AOCSB : 4; //!< Output Clock Source B
        unsigned AOCSC : 4; //!< Output Clock Source C
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCSR, field AICSA
 *
 * Input Clock Source A
 */

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

/* --- Register HW_ASRC_ASRCSR, field AICSB
 *
 * Input Clock Source B
 */

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

/* --- Register HW_ASRC_ASRCSR, field AICSC
 *
 * Input Clock Source C
 */

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

/* --- Register HW_ASRC_ASRCSR, field AOCSA
 *
 * Output Clock Source A
 */

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

/* --- Register HW_ASRC_ASRCSR, field AOCSB
 *
 * Output Clock Source B
 */

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

/* --- Register HW_ASRC_ASRCSR, field AOCSC
 *
 * Output Clock Source C
 */

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

/*!
 * @brief HW_ASRC_ASRCDR1 - ASRC Clock Divider Register 1
 *
 * The ASRC clock divider register (ASRCDR1) is a two 24-bit read/write
 * register that controls the division factors of the ASRC input and output
 * clock sources.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AICPA : 3; //!< Input Clock Prescaler A  Specify the prescaling factor of the input prescaler A. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDA : 3; //!< Input Clock Divider A  Specify the divide ratio of the input clock divider A. The divide ratio may range from 1 to 8 (AICDA[2:0] = 000 to 111).
        unsigned AICPB : 3; //!< Input Clock Prescaler B  Specify the prescaling factor of the input prescaler B. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDB : 3; //!< Input Clock Divider B  Specify the divide ratio of the input clock divider B. The divide ratio may range from 1 to 8 (AICDB[2:0] = 000 to 111).
        unsigned AOCPA : 3; //!< Output Clock Prescaler A  Specify the prescaling factor of the output prescaler A. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDA : 3; //!< Output Clock Divider A  Specify the divide ratio of the output clock divider A. The divide ratio may range from 1 to 8 (AOCDA[2:0] = 000 to 111).
        unsigned AOCPB : 3; //!< Output Clock Prescaler B  Specify the prescaling factor of the output prescaler B. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDB : 3; //!< Output Clock Divider B  Specify the divide ratio of the output clock divider B. The divide ratio may range from 1 to 8 (AOCDB[2:0] = 000 to 111).
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCDR1, field AICPA
 *
 * Input Clock Prescaler A  Specify the prescaling factor of the input prescaler A. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AICDA
 *
 * Input Clock Divider A  Specify the divide ratio of the input clock divider A. The divide
 * ratio may range from 1 to 8 (AICDA[2:0] = 000 to 111).
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AICPB
 *
 * Input Clock Prescaler B  Specify the prescaling factor of the input prescaler B. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AICDB
 *
 * Input Clock Divider B  Specify the divide ratio of the input clock divider B. The divide
 * ratio may range from 1 to 8 (AICDB[2:0] = 000 to 111).
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AOCPA
 *
 * Output Clock Prescaler A  Specify the prescaling factor of the output prescaler A. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AOCDA
 *
 * Output Clock Divider A  Specify the divide ratio of the output clock divider A. The divide
 * ratio may range from 1 to 8 (AOCDA[2:0] = 000 to 111).
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AOCPB
 *
 * Output Clock Prescaler B  Specify the prescaling factor of the output prescaler B. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR1, field AOCDB
 *
 * Output Clock Divider B  Specify the divide ratio of the output clock divider B. The divide
 * ratio may range from 1 to 8 (AOCDB[2:0] = 000 to 111).
 */

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

/*!
 * @brief HW_ASRC_ASRCDR2 - ASRC Clock Divider Register 2
 *
 * The ASRC clock divider register (ASRCDR2) is a two 24-bit read/write
 * register that controls the division factors of the ASRC input and output
 * clock sources.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AICPC : 3; //!< Input Clock Prescaler C  Specify the prescaling factor of the input prescaler C. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDC : 3; //!< Input Clock Divider C  Specify the divide ratio of the input clock divider C. The divide ratio may range from 1 to 8 (AICDC[2:0] = 000 to 111).
        unsigned AOCPC : 3; //!< Output Clock Prescaler C  Specify the prescaling factor of the output prescaler C. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDC : 3; //!< Output Clock Divider C  Specify the divide ratio of the output clock divider C. The divide ratio may range from 1 to 8 (AOCDC[2:0] = 000 to 111).
        unsigned RESERVED0 : 12; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCDR2, field AICPC
 *
 * Input Clock Prescaler C  Specify the prescaling factor of the input prescaler C. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR2, field AICDC
 *
 * Input Clock Divider C  Specify the divide ratio of the input clock divider C. The divide
 * ratio may range from 1 to 8 (AICDC[2:0] = 000 to 111).
 */

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

/* --- Register HW_ASRC_ASRCDR2, field AOCPC
 *
 * Output Clock Prescaler C  Specify the prescaling factor of the output prescaler C. The
 * prescaling ratio may be any power of 2 from 1 to 128.
 */

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

/* --- Register HW_ASRC_ASRCDR2, field AOCDC
 *
 * Output Clock Divider C  Specify the divide ratio of the output clock divider C. The divide
 * ratio may range from 1 to 8 (AOCDC[2:0] = 000 to 111).
 */

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

/*!
 * @brief HW_ASRC_ASRSTR - ASRC Status Register
 *
 * The ASRC status register (ASRSTR) is a 24-bit read-write register used by
 * the processor core to examine the status of the ASRC block and clear the
 * overload interrupt request and AOLE flag bit. Read the status register
 * will return the current state of ASRC.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AIDEA : 1; //!< Number of data in Input Data Buffer A is less than threshold  When set, this bit indicates that number of data still available in ASRDIRA is less than threshold and the processor can write data to ASRDIRA. When AIDEA is set, the ASRC generates data input A interrupt request to the processor, if enabled (that is, ASRCTR:ADIEA = 1). A DMA request is always generated when the AIDEA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AIDEB : 1; //!< Number of data in Input Data Buffer B is less than threshold  When set, this bit indicates that number of data still available in ASRDIRB is less than threshold and the processor can write data to ASRDIRB. When AIDEB is set, the ASRC generates data input B interrupt request to the processor, if enabled (that is, ASRCTR:ADIEB = 1). A DMA request is always generated when the AIDEB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AIDEC : 1; //!< Number of data in Input Data Buffer C is less than threshold  When set, this bit indicates that number of data still available in ASRDIRC is less than threshold and the processor can write data to ASRDIRC. When AIDEC is set, the ASRC generates data input C interrupt request to the processor, if enabled (that is, ASRCTR:ADIEC = 1). A DMA request is always generated when the AIDEC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFA : 1; //!< Number of data in Output Data Buffer A is greater than threshold  When set, this bit indicates that number of data already existing in ASRDORA is greater than threshold and the processor can read data from ASRDORA. When AODFA is set, the ASRC generates data output A interrupt request to the processor, if enabled (that is, ASRCTR:ADOEA = 1). A DMA request is always generated when the AODFA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFB : 1; //!< Number of data in Output Data Buffer B is greater than threshold  When set, this bit indicates that number of data already existing in ASRDORB is greater than threshold and the processor can read data from ASRDORB. When AODFB is set, the ASRC generates data output B interrupt request to the processor, if enabled (that is, ASRCTR:ADOEB = 1). A DMA request is always generated when the AODFB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFC : 1; //!< Number of data in Output Data Buffer C is greater than threshold  When set, this bit indicates that number of data already existing in ASRDORC is greater than threshold and the processor can read data from ASRDORC. When AODFC is set, the ASRC generates data output C interrupt request to the processor, if enabled (that is, ASRCTR:ADOEC = 1). A DMA request is always generated when the AODFC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AOLE : 1; //!< Overload Error Flag  When set, this bit indicates that the task rate is too high for the ASRC to handle. The reasons for overload may be:  - too high input clock frequency,  - too high output clock frequency,  - incorrect selection of the pre-filter,  - low ASRC processing clock,  - too many channels,  - underrun,  - or any combination of the reasons above.  Since the ASRC uses the same hardware resources to perform various tasks, the real reason for the overload is not straight forward, and it should be carefully analyzed by the programmer.  If ASRCTR:AOLIE=1, an interrupt will be proposed when this bit is set.  Write any value with this bit set as one into the status register will clear this bit and the interrupt request proposed by this bit.
        unsigned FPWT : 1; //!< FP is in wait states  This bit is for debug only.  When set, this bit indicates that ASRC is in wait states.  When clear, this bit indicates that ASRC is not in wait states.  If ASRCTR:AFPWE=1 and ASRCTR:ASDBG=1, an interrupt will be proposed when this bit is set.
        unsigned AIDUA : 1; //!< Input Data Buffer A has underflowed  When set, this bit indicates that input data buffer A has underflowed.  When clear, this bit indicates that input data buffer A has not underflowed.
        unsigned AIDUB : 1; //!< Input Data Buffer B has underflowed  When set, this bit indicates that input data buffer B has underflowed.  When clear, this bit indicates that input data buffer B has not underflowed.
        unsigned AIDUC : 1; //!< Input Data Buffer C has underflowed  When set, this bit indicates that input data buffer C has underflowed.  When clear, this bit indicates that input data buffer C has not underflowed.
        unsigned AODOA : 1; //!< Output Data Buffer A has overflowed  When set, this bit indicates that output data buffer A has overflowed. When clear, this bit indicates that output data buffer A has not overflowed
        unsigned AODOB : 1; //!< Output Data Buffer B has overflowed  When set, this bit indicates that output data buffer B has overflowed. When clear, this bit indicates that output data buffer B has not overflowed
        unsigned AODOC : 1; //!< Output Data Buffer C has overflowed  When set, this bit indicates that output data buffer C has overflowed. When clear, this bit indicates that output data buffer C has not overflowed
        unsigned AIOLA : 1; //!< Pair A Input Task Overload  When set, this bit indicates that pair A input task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AIOLB : 1; //!< Pair B Input Task Overload  When set, this bit indicates that pair B input task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AIOLC : 1; //!< Pair C Input Task Overload  When set, this bit indicates that pair C input task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLA : 1; //!< Pair A Output Task Overload  When set, this bit indicates that pair A output task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLB : 1; //!< Pair B Output Task Overload  When set, this bit indicates that pair B output task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLC : 1; //!< Pair C Output Task Overload  When set, this bit indicates that pair C output task is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned ATQOL : 1; //!< Task Queue FIFO overload  When set, this bit indicates that task queue FIFO logic is oveloaded. This may help to check the reason why overload interrupt happens.  The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned DSLCNT : 1; //!< DSL Counter Input to FIFO ready  When set, this bit indicates that new DSL counter information is stored in the internal ASRC FIFO. When clear, this bit indicates that new DSL counter information is in the process of storage into the internal ASRC FIFO.  When ASRIER:AFPWE=1, the rising edge of this signal will propose an interrupt request.  Writing any value with this bit set will clear the interrupt request proposed by the rising edge of this bit.
        unsigned RESERVED0 : 2; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRSTR, field AIDEA
 *
 * Number of data in Input Data Buffer A is less than threshold  When set, this bit indicates that
 * number of data still available in                                 ASRDIRA is less than threshold
 * and the processor can write data to                                 ASRDIRA. When AIDEA is set,
 * the ASRC generates data input A                                 interrupt request to the
 * processor, if enabled (that is,                                 ASRCTR:ADIEA = 1). A DMA request
 * is always generated when the AIDEA                                 bit is set, but a DMA transfer
 * takes place only if a DMA channel is                                 active and triggered by this
 * event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIDEB
 *
 * Number of data in Input Data Buffer B is less than threshold  When set, this bit indicates that
 * number of data still available in                                 ASRDIRB is less than threshold
 * and the processor can write data to                                 ASRDIRB. When AIDEB is set,
 * the ASRC generates data input B                                 interrupt request to the
 * processor, if enabled (that is,                                 ASRCTR:ADIEB = 1). A DMA request
 * is always generated when the AIDEB                                 bit is set, but a DMA transfer
 * takes place only if a DMA channel is                                 active and triggered by this
 * event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIDEC
 *
 * Number of data in Input Data Buffer C is less than threshold  When set, this bit indicates that
 * number of data still available in                                 ASRDIRC is less than threshold
 * and the processor can write data to                                 ASRDIRC. When AIDEC is set,
 * the ASRC generates data input C                                 interrupt request to the
 * processor, if enabled (that is,                                 ASRCTR:ADIEC = 1). A DMA request
 * is always generated when the AIDEC                                 bit is set, but a DMA transfer
 * takes place only if a DMA channel is                                 active and triggered by this
 * event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODFA
 *
 * Number of data in Output Data Buffer A is greater than threshold  When set, this bit indicates
 * that number of data already existing in                                 ASRDORA is greater than
 * threshold and the processor can read data                                 from ASRDORA. When
 * AODFA is set, the ASRC generates data output A                                 interrupt request
 * to the processor, if enabled (that is,                                 ASRCTR:ADOEA = 1). A DMA
 * request is always generated when the AODFA                                 bit is set, but a DMA
 * transfer takes place only if a DMA channel is                                 active and
 * triggered by this event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODFB
 *
 * Number of data in Output Data Buffer B is greater than threshold  When set, this bit indicates
 * that number of data already existing in                                 ASRDORB is greater than
 * threshold and the processor can read data                                 from ASRDORB. When
 * AODFB is set, the ASRC generates data output B                                 interrupt request
 * to the processor, if enabled (that is,                                 ASRCTR:ADOEB = 1). A DMA
 * request is always generated when the AODFB                                 bit is set, but a DMA
 * transfer takes place only if a DMA channel is                                 active and
 * triggered by this event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODFC
 *
 * Number of data in Output Data Buffer C is greater than threshold  When set, this bit indicates
 * that number of data already existing in                                 ASRDORC is greater than
 * threshold and the processor can read data                                 from ASRDORC. When
 * AODFC is set, the ASRC generates data output C                                 interrupt request
 * to the processor, if enabled (that is,                                 ASRCTR:ADOEC = 1). A DMA
 * request is always generated when the AODFC                                 bit is set, but a DMA
 * transfer takes place only if a DMA channel is                                 active and
 * triggered by this event.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AOLE
 *
 * Overload Error Flag  When set, this bit indicates that the task rate is too high for the
 * ASRC to handle. The reasons for overload may be:  - too high input clock frequency,  - too high
 * output clock frequency,  - incorrect selection of the pre-filter,  - low ASRC processing clock,
 * - too many channels,  - underrun,  - or any combination of the reasons above.  Since the ASRC
 * uses the same hardware resources to perform various                                 tasks, the
 * real reason for the overload is not straight forward, and                                 it
 * should be carefully analyzed by the programmer.  If ASRCTR:AOLIE=1, an interrupt will be proposed
 * when this bit is                                 set.  Write any value with this bit set as one
 * into the status register                                 will clear this bit and the interrupt
 * request proposed by this                                 bit.
 */

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

/* --- Register HW_ASRC_ASRSTR, field FPWT
 *
 * FP is in wait states  This bit is for debug only.  When set, this bit indicates that ASRC is in
 * wait states.  When clear, this bit indicates that ASRC is not in wait states.  If ASRCTR:AFPWE=1
 * and ASRCTR:ASDBG=1, an interrupt will be proposed                                 when this bit
 * is set.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIDUA
 *
 * Input Data Buffer A has underflowed  When set, this bit indicates that input data buffer A has
 * underflowed.  When clear, this bit indicates that input data buffer A has not
 * underflowed.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIDUB
 *
 * Input Data Buffer B has underflowed  When set, this bit indicates that input data buffer B has
 * underflowed.  When clear, this bit indicates that input data buffer B has not
 * underflowed.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIDUC
 *
 * Input Data Buffer C has underflowed  When set, this bit indicates that input data buffer C has
 * underflowed.  When clear, this bit indicates that input data buffer C has not
 * underflowed.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODOA
 *
 * Output Data Buffer A has overflowed  When set, this bit indicates that output data buffer A has
 * overflowed. When clear, this bit indicates that output data buffer A
 * has not overflowed
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODOB
 *
 * Output Data Buffer B has overflowed  When set, this bit indicates that output data buffer B has
 * overflowed. When clear, this bit indicates that output data buffer B
 * has not overflowed
 */

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

/* --- Register HW_ASRC_ASRSTR, field AODOC
 *
 * Output Data Buffer C has overflowed  When set, this bit indicates that output data buffer C has
 * overflowed. When clear, this bit indicates that output data buffer C
 * has not overflowed
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIOLA
 *
 * Pair A Input Task Overload  When set, this bit indicates that pair A input task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIOLB
 *
 * Pair B Input Task Overload  When set, this bit indicates that pair B input task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AIOLC
 *
 * Pair C Input Task Overload  When set, this bit indicates that pair C input task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AOOLA
 *
 * Pair A Output Task Overload  When set, this bit indicates that pair A output task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AOOLB
 *
 * Pair B Output Task Overload  When set, this bit indicates that pair B output task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field AOOLC
 *
 * Pair C Output Task Overload  When set, this bit indicates that pair C output task is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field ATQOL
 *
 * Task Queue FIFO overload  When set, this bit indicates that task queue FIFO logic is oveloaded.
 * This may help to check the reason why overload interrupt                                 happens.
 * The bit is cleared when writing ASRCTR:AOLIE as 1.
 */

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

/* --- Register HW_ASRC_ASRSTR, field DSLCNT
 *
 * DSL Counter Input to FIFO ready  When set, this bit indicates that new DSL counter information is
 * stored in the internal ASRC FIFO. When clear, this bit indicates that
 * new DSL counter information is in the process of storage into the
 * internal ASRC FIFO.  When ASRIER:AFPWE=1, the rising edge of this signal will propose an
 * interrupt request.  Writing any value with this bit set will clear the interrupt request
 * proposed by the rising edge of this bit.
 */

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

/*!
 * @brief HW_ASRC_ASRPMN - ASRC Parameter Register n
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is                             enabled. Recommended values
 * are given in ASRC Misc Control Register 1 for                                 Pair C below,
 * ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset  Access  Reset Value
 * Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2  0x44  R/W  0x00_0000
 * 0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W  0x00_0000  0xff7280
 * asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PARAMETER_VALUE : 24; //!< See recommended values table.
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRPMN, field PARAMETER_VALUE
 *
 * See recommended values table.
 */

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

/*!
 * @brief HW_ASRC_ASRTFR1 - ASRC ASRC Task Queue FIFO Register 1
 *
 * These registers define and show The register defines and                                 shows
 * the parameters for ASRC inner task queue FIFOs.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 6; //!< Reserved. Should be written as zero for compatibility.
        unsigned TF_BASE : 7; //!< Base address for task queue FIFO. Set to 0x7C.
        unsigned TF_FILL : 7; //!< Current number of entries in task queue FIFO.
        unsigned RESERVED1 : 4; //!< Reserved. Should be written as zero for compatibility.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRTFR1, field TF_BASE
 *
 * Base address for task queue FIFO. Set to 0x7C.
 */

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

/* --- Register HW_ASRC_ASRTFR1, field TF_FILL
 *
 * Current number of entries in task queue FIFO.
 */

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

/*!
 * @brief HW_ASRC_ASRCCR - ASRC Channel Counter Register
 *
 * The ASRC channel counter register (ASRCCR) is a 24-bit read/write
 * register that sets and reflects the current specific input/output FIFO
 * being accessed through shared peripheral bus for each ASRC conversion
 * pair.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ACIA : 4; //!< The channel counter for Pair A's input FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair A's input FIFO's usage. The value can be any value between [0, ANCA-1]
        unsigned ACIB : 4; //!< The channel counter for Pair B's input FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair B's input FIFO's usage. The value can be any value between [0, ANCB-1]
        unsigned ACIC : 4; //!< The channel counter for Pair C's input FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair C's input FIFO's usage. The value can be any value between [0, ANCC-1]
        unsigned ACOA : 4; //!< The channel counter for Pair A's output FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair A's output FIFO's usage. The value can be any value between [0, ANCA-1]
        unsigned ACOB : 4; //!< The channel counter for Pair B's output FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair B's output FIFO's usage. The value can be any value between [0, ANCB-1]
        unsigned ACOC : 4; //!< The channel counter for Pair C's output FIFO  These bits stand for the current channel being accessed through shared peripheral bus for Pair C's output FIFO's usage. The value can be any value between [0, ANCC-1]
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRCCR, field ACIA
 *
 * The channel counter for Pair A's input FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair A's input FIFO's
 * usage. The value can                                 be any value between [0, ANCA-1]
 */

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

/* --- Register HW_ASRC_ASRCCR, field ACIB
 *
 * The channel counter for Pair B's input FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair B's input FIFO's
 * usage. The value can                                 be any value between [0, ANCB-1]
 */

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

/* --- Register HW_ASRC_ASRCCR, field ACIC
 *
 * The channel counter for Pair C's input FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair C's input FIFO's
 * usage. The value can                                 be any value between [0, ANCC-1]
 */

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

/* --- Register HW_ASRC_ASRCCR, field ACOA
 *
 * The channel counter for Pair A's output FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair A's output FIFO's
 * usage. The value                                 can be any value between [0, ANCA-1]
 */

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

/* --- Register HW_ASRC_ASRCCR, field ACOB
 *
 * The channel counter for Pair B's output FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair B's output FIFO's
 * usage. The value                                 can be any value between [0, ANCB-1]
 */

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

/* --- Register HW_ASRC_ASRCCR, field ACOC
 *
 * The channel counter for Pair C's output FIFO  These bits stand for the current channel being
 * accessed through                                 shared peripheral bus for Pair C's output FIFO's
 * usage. The value                                 can be any value between [0, ANCC-1]
 */

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

/*!
 * @brief HW_ASRC_ASRDI - ASRC Data Input Register for Pair
 *
 * These registers are the interface registers for the audio data input of
 * pair A,B,C respectively. They are backed by FIFOs.  The usage of these registers is shown in
 * "xref to                             56898: Heading5: 1.2.3.2.1 Data Input Modes"
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATA : 24; //!< Audio data input
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRDI, field DATA
 *
 * Audio data input
 */

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

/*!
 * @brief HW_ASRC_ASRDO - ASRC Data Output Register for Pair
 *
 * These registers are the interface registers for the audio data output of
 * pair A,B,C respectively. They are backed by FIFOs.  The usage of these registers is shown in xref
 * to                             "Data Output modes."
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATA : 24; //!< Audio data output
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRDO, field DATA
 *
 * Audio data output
 */

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

/*!
 * @brief HW_ASRC_ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part
 *
 * The ideal ratio registers                             (ASRIDRHA, ASRIDRLA) hold the ratio value
 * IDRATIOA. IDRATIOA =                                 Fs inA /Fs outA = Ts outA /Ts inA is a
 * 32-bit fixed point value with 26 fractional bits. This value                             is only
 * useful when ASRCTR:{USRA, IDRA}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOA : 8; //!< IDRATIOA[31:24]. High part of ideal ratio value for pair A
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRHA, field IDRATIOA
 *
 * IDRATIOA[31:24]. High part of ideal ratio value for pair A
 */

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

/*!
 * @brief HW_ASRC_ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part
 *
 * The ideal ratio registers                             (ASRIDRHA, ASRIDRLA) hold the ratio value
 * IDRATIOA. IDRATIOA =                                 Fs inA /Fs outA = Ts outA /Ts inA is a
 * 32-bit fixed point value with 26 fractional bits. This value                             is only
 * useful when ASRCTR:{USRA, IDRA}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOA : 24; //!< IDRATIOA[23:0]. Low part of ideal ratio value for pair A
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRLA, field IDRATIOA
 *
 * IDRATIOA[23:0]. Low part of ideal ratio value for pair A
 */

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

/*!
 * @brief HW_ASRC_ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part
 *
 * The ideal ratio registers (ASRIDRHB, ASRIDRLB) hold the ratio value
 * IDRATIOB. IDRATIOB = Fs inB /Fs outB =                                 Ts outB /Ts inB is a
 * 32-bit fixed point value                             with 26 fractional bits. This value is only
 * useful when ASRCTR:{USRB,                             IDRB}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOB : 8; //!< IDRATIOB[31:24]. High part of ideal ratio value for pair B.
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRHB, field IDRATIOB
 *
 * IDRATIOB[31:24]. High part of ideal ratio value for pair B.
 */

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

/*!
 * @brief HW_ASRC_ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part
 *
 * The ideal ratio registers (ASRIDRHB, ASRIDRLB) hold the ratio value
 * IDRATIOB. IDRATIOB = Fs inB /Fs outB =                                 Ts outB /Ts inB is a
 * 32-bit fixed point value                             with 26 fractional bits. This value is only
 * useful when ASRCTR:{USRB,                             IDRB}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOB : 24; //!< IDRATIOB[23:0]. Low part of ideal ratio value for pair B.
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRLB, field IDRATIOB
 *
 * IDRATIOB[23:0]. Low part of ideal ratio value for pair B.
 */

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

/*!
 * @brief HW_ASRC_ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part
 *
 * The ideal ratio registers (ASRIDRHC, ASRIDRLC) hold the ratio value
 * IDRATIOC. IDRATIOC = Fs inC /Fs outC =                                 Ts outC /Ts inC is a
 * 32-bit fixed point value                             with 26 fractional bits. This value is only
 * useful when ASRCTR:{USRC,                             IDRC}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOC : 8; //!< IDRATIOC[31:24]. High part of ideal ratio value for pair C.
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRHC, field IDRATIOC
 *
 * IDRATIOC[31:24]. High part of ideal ratio value for pair C.
 */

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

/*!
 * @brief HW_ASRC_ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part
 *
 * The ideal ratio registers (ASRIDRHC, ASRIDRLC) hold the ratio value
 * IDRATIOC. IDRATIOC = Fs inC /Fs outC =                                 Ts outC /Ts inC is a
 * 32-bit fixed point value                             with 26 fractional bits. This value is only
 * useful when ASRCTR:{USRC,                             IDRC}=2'b11.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IDRATIOC : 24; //!< IDRATIOC[23:0]. Low part of ideal ratio value for pair C.
        unsigned RESERVED0 : 8; //!< 
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

/* --- Register HW_ASRC_ASRIDRLC, field IDRATIOC
 *
 * IDRATIOC[23:0]. Low part of ideal ratio value for pair C.
 */

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

/*!
 * @brief HW_ASRC_ASR76K - ASRC 76kHz Period in terms of ASRC processing                        clock
 *
 * The register (ASR76K) holds the period of the 76kHz sampling clock in
 * terms of the ASRC processing clock with frequency Fs ASRC .                             ASR76K =
 * Fs ASRC /Fs 76k . Reset value is 0x0A47 which                             assumes that Fs ASRC
 * =200MHz. This register is used to help the                             ASRC internal logic to
 * decide the pre-processing and the post-processing                             options
 * automatically (see ASRC                                 Misc Control Register 1 for Pair C and
 * ASRC Misc Control Register 1 for                                 Pair C ). In a system when Fs
 * ASRC =133MHz, the value                             should be assigned explicitly as 0x06D6 in
 * user application code.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ASR76K : 17; //!< Value for the period of the 76kHz sampling clock.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASR76K, field ASR76K
 *
 * Value for the period of the 76kHz sampling clock.
 */

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

/*!
 * @brief HW_ASRC_ASR56K - ASRC 56kHz Period in terms of ASRC processing                        clock
 *
 * The register (ASR56K) holds the period of the 56kHz sampling clock in
 * terms of the ASRC processing clock with frequency Fs ASRC .                             ASR56K =
 * Fs ASRC /Fs 56k . Reset value is 0x0DF3 which                             assumes that Fs ASRC
 * =200MHz. This register is used to help the                             ASRC internal logic to
 * decide the pre-processing and the post-processing                             options
 * automatically (see ASRC                                 Misc Control Register 1 for Pair C and
 * ASRC Misc Control Register 1 for                                 Pair C ). In a system when Fs
 * ASRC =133MHz, the value                             should be assigned explicitly as 0x0947 in
 * user application code.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ASR56K : 17; //!< Value for the period of the 56kHz sampling clock
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned RESERVED1 : 8; //!< 
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

/* --- Register HW_ASRC_ASR56K, field ASR56K
 *
 * Value for the period of the 56kHz sampling clock
 */

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

/*!
 * @brief HW_ASRC_ASRMCRA - ASRC Misc Control Register for Pair A
 *
 * The register (ASRMCRA) is used to control Pair A internal logic.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_THRESHOLDA : 6; //!< The threshold for Pair A's input FIFO per channel  These bits stand for the threshold for Pair A's input FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set;  when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFA : 1; //!< Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOA=0. If bit clear, untouch ASRCCR:ACOA.
        unsigned RSYNIFA : 1; //!< Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIA=0. If bit clear, untouch ASRCCR:ACIA.
        unsigned OUTFIFO_THRESHOLDA : 6; //!< The threshold for Pair A's output FIFO per channel  These bits stand for the threshold for Pair A's output FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set;  when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYA : 1; //!< Bypass Polyphase Filtering for Pair A  This bit will determine whether the polyphase filtering part of Pair A conversion will be bypassed.
        unsigned BUFSTALLA : 1; //!< Stall Pair A conversion in case of Buffer Near Empty/Full Condition  This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair A. This option can only work when external ratio is used.  Near empty condition is the condition when input FIFO has less than 4 useful samples per channel.  Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHA : 1; //!< Use external thresholds for FIFO control of Pair A  This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair A.
        unsigned ZEROBUFA : 1; //!< Initialize buf of Pair A when pair A is enabled. Always clear option.  This bit is used to control whether the buffer is to be zeroized when pair A is enabled.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRMCRA, field INFIFO_THRESHOLDA
 *
 * The threshold for Pair A's input FIFO per channel  These bits stand for the threshold for Pair
 * A's input FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of input FIFO fillings of the pair is less than n
 * samples per channel, the input data needed flag is set;  when the number of input FIFO fillings
 * of the pair is greater than or                                 equal to n samples per channel,
 * the input data needed flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field RSYNOFA
 *
 * Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOA=0. If bit clear, untouch
 * ASRCCR:ACOA.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field RSYNIFA
 *
 * Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIA=0. If bit clear, untouch
 * ASRCCR:ACIA.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field OUTFIFO_THRESHOLDA
 *
 * The threshold for Pair A's output FIFO per channel  These bits stand for the threshold for Pair
 * A's output FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n
 * samples per channel, the output data ready flag is set;  when the number of output FIFO fillings
 * of the pair is less than or                                 equal to n samples per channel, the
 * output data ready flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field BYPASSPOLYA
 *
 * Bypass Polyphase Filtering for Pair A  This bit will determine whether the polyphase filtering
 * part of Pair                                 A conversion will be bypassed.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field BUFSTALLA
 *
 * Stall Pair A conversion in case of Buffer Near Empty/Full
 * Condition  This bit will determine whether the near empty/full FIFO condition
 * will stall the rate conversion for pair A. This option can only work
 * when external ratio is used.  Near empty condition is the condition when input FIFO has less than
 * 4                                 useful samples per channel.  Near full condition is the
 * condition when the output FIFO has less                                 than 4 vacant sample
 * words to fill per channel.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field EXTTHRSHA
 *
 * Use external thresholds for FIFO control of Pair A  This bit will determine whether the FIFO
 * thresholds externally                                 defined in this register is used to control
 * ASRC internal FIFO logic                                 for pair A.
 */

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

/* --- Register HW_ASRC_ASRMCRA, field ZEROBUFA
 *
 * Initialize buf of Pair A when pair A is enabled. Always clear
 * option.  This bit is used to control whether the buffer is to be zeroized when
 * pair A is enabled.
 */

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

/*!
 * @brief HW_ASRC_ASRFSTA - ASRC FIFO Status Register for Pair A
 *
 * The register (ASRFSTA) is used to show Pair A internal FIFO
 * conditions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_FILLA : 7; //!< The fillings for Pair A's input FIFO per channel  These bits stand for the fillings for Pair A's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned IAEA : 1; //!< Input FIFO is near Empty for Pair A  This bit is to indicate whether the input FIFO of Pair A is near empty.
        unsigned OUTFIFO_FILLA : 7; //!< The fillings for Pair A's output FIFO per channel  These bits stand for the fillings for Pair A's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned OAFA : 1; //!< Output FIFO is near Full for Pair A  This bit is to indicate whether the output FIFO of Pair A is near full.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRFSTA, field INFIFO_FILLA
 *
 * The fillings for Pair A's input FIFO per channel  These bits stand for the fillings for Pair A's
 * input FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTA, field IAEA
 *
 * Input FIFO is near Empty for Pair A  This bit is to indicate whether the input FIFO of Pair A is
 * near                                 empty.
 */

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

/* --- Register HW_ASRC_ASRFSTA, field OUTFIFO_FILLA
 *
 * The fillings for Pair A's output FIFO per channel  These bits stand for the fillings for Pair A's
 * output FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTA, field OAFA
 *
 * Output FIFO is near Full for Pair A  This bit is to indicate whether the output FIFO of Pair A is
 * near                                 full.
 */

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

/*!
 * @brief HW_ASRC_ASRMCRB - ASRC Misc Control Register for Pair B
 *
 * The register (ASRMCRB) is used to control Pair B internal logic.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_THRESHOLDB : 6; //!< The threshold for Pair B's input FIFO per channel  These bits stand for the threshold for Pair B's input FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set;  when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFB : 1; //!< Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOB=0. If bit clear, untouch ASRCCR:ACOB.
        unsigned RSYNIFB : 1; //!< Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIB=0. If bit clear, untouch ASRCCR:ACIB.
        unsigned OUTFIFO_THRESHOLDB : 6; //!< The threshold for Pair B's output FIFO per channel  These bits stand for the threshold for Pair B's output FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set;  when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYB : 1; //!< Bypass Polyphase Filtering for Pair B  This bit will determine whether the polyphase filtering part of Pair B conversion will be bypassed.
        unsigned BUFSTALLB : 1; //!< Stall Pair B conversion in case of Buffer Near Empty/Full Condition  This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair B. This option can only work when external ratio is used.  Near empty condition is the condition when input FIFO has less than 4 useful samples per channel.  Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHB : 1; //!< Use external thresholds for FIFO control of Pair B  This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair B.
        unsigned ZEROBUFB : 1; //!< Initialize buf of Pair B when pair B is enabled  This bit is used to control whether the buffer is to be zeroized when pair B is enabled.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRMCRB, field INFIFO_THRESHOLDB
 *
 * The threshold for Pair B's input FIFO per channel  These bits stand for the threshold for Pair
 * B's input FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of input FIFO fillings of the pair is less than n
 * samples per channel, the input data needed flag is set;  when the number of input FIFO fillings
 * of the pair is greater than or                                 equal to n samples per channel,
 * the input data needed flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field RSYNOFB
 *
 * Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOB=0. If bit clear, untouch
 * ASRCCR:ACOB.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field RSYNIFB
 *
 * Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIB=0. If bit clear, untouch
 * ASRCCR:ACIB.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field OUTFIFO_THRESHOLDB
 *
 * The threshold for Pair B's output FIFO per channel  These bits stand for the threshold for Pair
 * B's output FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n
 * samples per channel, the output data ready flag is set;  when the number of output FIFO fillings
 * of the pair is less than or                                 equal to n samples per channel, the
 * output data ready flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field BYPASSPOLYB
 *
 * Bypass Polyphase Filtering for Pair B  This bit will determine whether the polyphase filtering
 * part of Pair                                 B conversion will be bypassed.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field BUFSTALLB
 *
 * Stall Pair B conversion in case of Buffer Near Empty/Full
 * Condition  This bit will determine whether the near empty/full FIFO condition
 * will stall the rate conversion for pair B. This option can only work
 * when external ratio is used.  Near empty condition is the condition when input FIFO has less than
 * 4                                 useful samples per channel.  Near full condition is the
 * condition when the output FIFO has less                                 than 4 vacant sample
 * words to fill per channel.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field EXTTHRSHB
 *
 * Use external thresholds for FIFO control of Pair B  This bit will determine whether the FIFO
 * thresholds externally                                 defined in this register is used to control
 * ASRC internal FIFO logic                                 for pair B.
 */

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

/* --- Register HW_ASRC_ASRMCRB, field ZEROBUFB
 *
 * Initialize buf of Pair B when pair B is enabled  This bit is used to control whether the buffer
 * is to be zeroized when                                 pair B is enabled.
 */

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

/*!
 * @brief HW_ASRC_ASRFSTB - ASRC FIFO Status Register for Pair B
 *
 * The register (ASRFSTB) is used to show Pair B internal FIFO
 * conditions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_FILLB : 7; //!< The fillings for Pair B's input FIFO per channel  These bits stand for the fillings for Pair B's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned IAEB : 1; //!< Input FIFO is near Empty for Pair B  This bit is to indicate whether the input FIFO of Pair B is near empty.
        unsigned OUTFIFO_FILLB : 7; //!< The fillings for Pair B's output FIFO per channel  These bits stand for the fillings for Pair B's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned OAFB : 1; //!< Output FIFO is near Full for Pair B  This bit is to indicate whether the output FIFO of Pair B is near full.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRFSTB, field INFIFO_FILLB
 *
 * The fillings for Pair B's input FIFO per channel  These bits stand for the fillings for Pair B's
 * input FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTB, field IAEB
 *
 * Input FIFO is near Empty for Pair B  This bit is to indicate whether the input FIFO of Pair B is
 * near                                 empty.
 */

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

/* --- Register HW_ASRC_ASRFSTB, field OUTFIFO_FILLB
 *
 * The fillings for Pair B's output FIFO per channel  These bits stand for the fillings for Pair B's
 * output FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTB, field OAFB
 *
 * Output FIFO is near Full for Pair B  This bit is to indicate whether the output FIFO of Pair B is
 * near                                 full.
 */

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

/*!
 * @brief HW_ASRC_ASRMCRC - ASRC Misc Control Register for Pair C
 *
 * The register (ASRMCRC) is used to control Pair C internal logic.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_THRESHOLDC : 6; //!< The threshold for Pair C's input FIFO per channel  These bits stand for the threshold for Pair C's input FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set;  when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFC : 1; //!< Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOC=0. If bit clear, untouch ASRCCR:ACOC.
        unsigned RSYNIFC : 1; //!< Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIC=0. If bit clear, untouch ASRCCR:ACIC.
        unsigned OUTFIFO_THRESHOLDC : 6; //!< The threshold for Pair C's output FIFO per channel  These bits stand for the threshold for Pair C's output FIFO per channel. Possible range is [0,63].  When the value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set;  when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYC : 1; //!< Bypass Polyphase Filtering for Pair C  This bit will determine whether the polyphase filtering part of Pair C conversion will be bypassed.
        unsigned BUFSTALLC : 1; //!< Stall Pair C conversion in case of Buffer Near Empty/Full Condition  This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair C. This option can only work when external ratio is used.  Near empty condition is the condition when input FIFO has less than 4 useful samples per channel.  Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHC : 1; //!< Use external thresholds for FIFO control of Pair C  This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair C.
        unsigned ZEROBUFC : 1; //!< Initialize buf of Pair C when pair C is enabled  This bit is used to control whether the buffer is to be zeroized when pair C is enabled.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRMCRC, field INFIFO_THRESHOLDC
 *
 * The threshold for Pair C's input FIFO per channel  These bits stand for the threshold for Pair
 * C's input FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of input FIFO fillings of the pair is less than n
 * samples per channel, the input data needed flag is set;  when the number of input FIFO fillings
 * of the pair is greater than or                                 equal to n samples per channel,
 * the input data needed flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field RSYNOFC
 *
 * Re-sync Output FIFO Channel Counter  If bit set, force ASRCCR:ACOC=0. If bit clear, untouch
 * ASRCCR:ACOC.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field RSYNIFC
 *
 * Re-sync Input FIFO Channel Counter  If bit set, force ASRCCR:ACIC=0. If bit clear, untouch
 * ASRCCR:ACIC.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field OUTFIFO_THRESHOLDC
 *
 * The threshold for Pair C's output FIFO per channel  These bits stand for the threshold for Pair
 * C's output FIFO per                                 channel. Possible range is [0,63].  When the
 * value is n, it means that:  when the number of output FIFO fillings of the pair is greater than n
 * samples per channel, the output data ready flag is set;  when the number of output FIFO fillings
 * of the pair is less than or                                 equal to n samples per channel, the
 * output data ready flag is                                 automatically cleared.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field BYPASSPOLYC
 *
 * Bypass Polyphase Filtering for Pair C  This bit will determine whether the polyphase filtering
 * part of Pair                                 C conversion will be bypassed.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field BUFSTALLC
 *
 * Stall Pair C conversion in case of Buffer Near Empty/Full
 * Condition  This bit will determine whether the near empty/full FIFO condition
 * will stall the rate conversion for pair C. This option can only work
 * when external ratio is used.  Near empty condition is the condition when input FIFO has less than
 * 4                                 useful samples per channel.  Near full condition is the
 * condition when the output FIFO has less                                 than 4 vacant sample
 * words to fill per channel.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field EXTTHRSHC
 *
 * Use external thresholds for FIFO control of Pair C  This bit will determine whether the FIFO
 * thresholds externally                                 defined in this register is used to control
 * ASRC internal FIFO logic                                 for pair C.
 */

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

/* --- Register HW_ASRC_ASRMCRC, field ZEROBUFC
 *
 * Initialize buf of Pair C when pair C is enabled  This bit is used to control whether the buffer
 * is to be zeroized when                                 pair C is enabled.
 */

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

/*!
 * @brief HW_ASRC_ASRFSTC - ASRC FIFO Status Register for Pair C
 *
 * The register (ASRFSTC) is used to show Pair C internal FIFO
 * conditions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned INFIFO_FILLC : 7; //!< The fillings for Pair C's input FIFO per channel  These bits stand for the fillings for Pair C's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned IAEC : 1; //!< Input FIFO is near Empty for Pair C  This bit is to indicate whether the input FIFO of Pair C is near empty.
        unsigned OUTFIFO_FILLC : 7; //!< The fillings for Pair C's output FIFO per channel  These bits stand for the fillings for Pair C's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< Reserved. Should be written as zero for future compatibility.
        unsigned OAFC : 1; //!< Output FIFO is near Full for Pair C  This bit is to indicate whether the output FIFO of Pair C is near full.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRFSTC, field INFIFO_FILLC
 *
 * The fillings for Pair C's input FIFO per channel  These bits stand for the fillings for Pair C's
 * input FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTC, field IAEC
 *
 * Input FIFO is near Empty for Pair C  This bit is to indicate whether the input FIFO of Pair C is
 * near                                 empty.
 */

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

/* --- Register HW_ASRC_ASRFSTC, field OUTFIFO_FILLC
 *
 * The fillings for Pair C's output FIFO per channel  These bits stand for the fillings for Pair C's
 * output FIFO per                                 channel. Possible range is [0,64].
 */

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

/* --- Register HW_ASRC_ASRFSTC, field OAFC
 *
 * Output FIFO is near Full for Pair C  This bit is to indicate whether the output FIFO of Pair C is
 * near                                 full.
 */

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

/*!
 * @brief HW_ASRC_ASRMCR1 - ASRC Misc Control Register 1 for Pair X
 *
 * The register (ASRMCR1A) is used to control Pair x internal logic                             (for
 * data alignment etc.).  The bit assignment for all the input data formats is the same as that
 * supported by the SSI.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OW16 : 1; //!< Bit Width Option of the output FIFO  This bit will determine the bit width option of the output FIFO.
        unsigned OSGN : 1; //!< Sign Extension Option of the output FIFO  This bit will determine the sign extension option of the output FIFO.
        unsigned OMSB : 1; //!< Data Alignment of the output FIFO  This bit will determine the data alignment of the output FIFO.
        unsigned RESERVED0 : 5; //!< Reserved. Should be written as zero for future compatibility.
        unsigned IMSB : 1; //!< Data Alignment of the input FIFO  This bit will determine the data alignment of the input FIFO.
        unsigned IWD : 3; //!< Data Width of the input FIFO  These three bits will determine the bitwidth for the audio data into ASRC  All other settings not shown are reserved.  3'b000 24-bit audio data.  3'b001 16-bit audio data.  3'b010 8-bit audio data.
        unsigned RESERVED1 : 12; //!< Reserved. Should be written as zero for future compatibility.
        unsigned RESERVED2 : 8; //!< 
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

/* --- Register HW_ASRC_ASRMCR1, field OW16
 *
 * Bit Width Option of the output FIFO  This bit will determine the bit width option of the output
 * FIFO.
 */

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

/* --- Register HW_ASRC_ASRMCR1, field OSGN
 *
 * Sign Extension Option of the output FIFO  This bit will determine the sign extension option of
 * the output                                 FIFO.
 */

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

/* --- Register HW_ASRC_ASRMCR1, field OMSB
 *
 * Data Alignment of the output FIFO  This bit will determine the data alignment of the output FIFO.
 */

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

/* --- Register HW_ASRC_ASRMCR1, field IMSB
 *
 * Data Alignment of the input FIFO  This bit will determine the data alignment of the input FIFO.
 */

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

/* --- Register HW_ASRC_ASRMCR1, field IWD
 *
 * Data Width of the input FIFO  These three bits will determine the bitwidth for the audio data
 * into                                 ASRC  All other settings not shown are reserved.  3'b000
 * 24-bit audio data.  3'b001 16-bit audio data.  3'b010 8-bit audio data.
 */

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



/*!
 * @brief All ASRC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_asrc_asrctr_t ASRCTR; //!< ASRC Control Register
    volatile hw_asrc_asrier_t ASRIER; //!< ASRC Interrupt Enable Register
    reg32_t _reserved0;
    volatile hw_asrc_asrcncr_t ASRCNCR; //!< ASRC Channel Number Configuration Register
    volatile hw_asrc_asrcfg_t ASRCFG; //!< ASRC Filter Configuration Status Register
    volatile hw_asrc_asrcsr_t ASRCSR; //!< ASRC Clock Source Register
    volatile hw_asrc_asrcdr1_t ASRCDR1; //!< ASRC Clock Divider Register 1
    volatile hw_asrc_asrcdr2_t ASRCDR2; //!< ASRC Clock Divider Register 2
    volatile hw_asrc_asrstr_t ASRSTR; //!< ASRC Status Register
    reg32_t _reserved1[7];
    volatile hw_asrc_asrpmn_t ASRPMN; //!< ASRC Parameter Register n
    reg32_t _reserved2[4];
    volatile hw_asrc_asrtfr1_t ASRTFR1; //!< ASRC ASRC Task Queue FIFO Register 1
    reg32_t _reserved3;
    volatile hw_asrc_asrccr_t ASRCCR; //!< ASRC Channel Counter Register
    volatile hw_asrc_asrdi_t ASRDI; //!< ASRC Data Input Register for Pair
    volatile hw_asrc_asrdo_t ASRDO; //!< ASRC Data Output Register for Pair
    reg32_t _reserved4[6];
    volatile hw_asrc_asridrha_t ASRIDRHA; //!< ASRC Ideal Ratio for Pair A-High Part
    volatile hw_asrc_asridrla_t ASRIDRLA; //!< ASRC Ideal Ratio for Pair A -Low Part
    volatile hw_asrc_asridrhb_t ASRIDRHB; //!< ASRC Ideal Ratio for Pair B-High Part
    volatile hw_asrc_asridrlb_t ASRIDRLB; //!< ASRC Ideal Ratio for Pair B-Low Part
    volatile hw_asrc_asridrhc_t ASRIDRHC; //!< ASRC Ideal Ratio for Pair C-High Part
    volatile hw_asrc_asridrlc_t ASRIDRLC; //!< ASRC Ideal Ratio for Pair C-Low Part
    volatile hw_asrc_asr76k_t ASR76K; //!< ASRC 76kHz Period in terms of ASRC processing                        clock
    volatile hw_asrc_asr56k_t ASR56K; //!< ASRC 56kHz Period in terms of ASRC processing                        clock
    volatile hw_asrc_asrmcra_t ASRMCRA; //!< ASRC Misc Control Register for Pair A
    volatile hw_asrc_asrfsta_t ASRFSTA; //!< ASRC FIFO Status Register for Pair A
    volatile hw_asrc_asrmcrb_t ASRMCRB; //!< ASRC Misc Control Register for Pair B
    volatile hw_asrc_asrfstb_t ASRFSTB; //!< ASRC FIFO Status Register for Pair B
    volatile hw_asrc_asrmcrc_t ASRMCRC; //!< ASRC Misc Control Register for Pair C
    volatile hw_asrc_asrfstc_t ASRFSTC; //!< ASRC FIFO Status Register for Pair C
    reg32_t _reserved5[2];
    volatile hw_asrc_asrmcr1_t ASRMCR1; //!< ASRC Misc Control Register 1 for Pair X
} hw_asrc_t
#endif

//! @brief Macro to access all ASRC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ASRC(0)</code>.
#define HW_ASRC     (*(volatile hw_asrc_t *) REGS_ASRC_BASE)


#endif // _ASRC_H
