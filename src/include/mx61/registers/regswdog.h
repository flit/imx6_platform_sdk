/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _WDOG_H
#define _WDOG_H

#include "regs.h"

#ifndef REGS_WDOG_BASE
#define REGS_WDOG0_BASE (REGS_BASE + 0x020bc000)
#define REGS_WDOG1_BASE (REGS_BASE + 0x020c0000)
#define REGS_WDOG_BASE(x) ( x == 0 ? REGS_WDOG0_BASE : x == 1 ? REGS_WDOG1_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_WDOG_WCR - Watchdog Control Register
 *
 * The Watchdog Control Register (WDOG_WCR) controls the WDOG-1 operation.    WDZST, WDBG , WRE and
 * WDW bits                                     are write-once only bits. Once the software does a
 * write access to these bits, all                                     these bits will get locked
 * and cannot be reprogrammed till the next system reset
 * assertion.  WDZST, WDBG and WRE bits are write-once only bits. Once the
 * software does a write access to these bits, all these bits will get locked and
 * cannot be reprogrammed till the next system reset assertion.  WDE is a write one once only bit.
 * Once software performs a write "1" operation to this                                 bit it
 * cannot be reset/cleared till the next system reset.  WDT is also a write one once only bit. Once
 * software performs a write "1" operation to this bit it cannot be reset/cleared till
 * the next POR (Power-on Reset). This bit does not gets reset/cleared due to any
 * system reset.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WDZST : 1; //!< Watchdog Low Power. Determines the operation of the WDOG-1 during low-power modes. This bit is write once-only.  The WDOG-1 can continue/suspend the timer operation in the low-power modes (STOP , WAIT  and DOZE mode).
        unsigned short WDBG : 1; //!< Watchdog DEBUG Enable. Determines the operation of the WDOG-1 during DEBUG mode. This bit is write once-only.
        unsigned short WDE : 1; //!< Watchdog Enable. Enables or disables the WDOG-1 block. This is a write one once only bit. It is not possible to clear this bit by a software write, once the bit is set.  This bit can be set/reset in debug mode (exception).
        unsigned short RESERVED0 : 1; //!< 
        unsigned short SRS : 1; //!< Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal wdog_rst . This bit automatically resets to "1" after it has been asserted to "0".  This bit does not generate the software reset to the block. The Peripheral Clock  (ipg_clk)  must be on to write to this bit.
        unsigned short WDA : 1; //!< WDOG   (ipp_wdog)  assertion. Controls the software assertion of the WDOG  ( ipp_wdog ) signal.
        unsigned short RESERVED1 : 2; //!< 
        unsigned short WT : 8; //!< Watchdog Time-out Field. This 8-bit field contains the time-out value that is loaded into the Watchdog counter after the service routine has been performed or after the Watchdog is enabled. After reset, WT[7:0] must have a value written to it before enabling the Watchdog otherwise count value of zero which is 0.5 seconds is loaded into the counter.  The time-out value can be written at any point of time but it is loaded to the counter at the time when WDOG-1 is enabled or after the service routine has been performed. For more information see .
    } B;
} hw_wdog_wcr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WCR register
 */
#define HW_WDOG_WCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WCR(x)           (*(volatile hw_wdog_wcr_t *) HW_WDOG_WCR_ADDR(x))
#define HW_WDOG_WCR_RD(x)        (HW_WDOG_WCR(x).U)
#define HW_WDOG_WCR_WR(x, v)     (HW_WDOG_WCR(x).U = (v))
#define HW_WDOG_WCR_SET(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) |  (v)))
#define HW_WDOG_WCR_CLR(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) & ~(v)))
#define HW_WDOG_WCR_TOG(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WCR bitfields
 */

/* --- Register HW_WDOG_WCR, field WDZST
 *
 * Watchdog Low Power. Determines the operation of the WDOG-1 during low-power modes. This
 * bit is write once-only.  The WDOG-1 can continue/suspend the timer operation in the low-power
 * modes (STOP , WAIT  and DOZE mode).
 */

#define BP_WDOG_WCR_WDZST      0
#define BM_WDOG_WCR_WDZST      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDZST(v)   ((((reg32_t) v) << 0) & BM_WDOG_WCR_WDZST)
#else
#define BF_WDOG_WCR_WDZST(v)   (((v) << 0) & BM_WDOG_WCR_WDZST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDZST(v)   BF_CS1(WDOG_WCR, WDZST, v)
#endif

/* --- Register HW_WDOG_WCR, field WDBG
 *
 * Watchdog DEBUG Enable. Determines the operation of the WDOG-1 during DEBUG mode. This bit
 * is write once-only.
 */

#define BP_WDOG_WCR_WDBG      1
#define BM_WDOG_WCR_WDBG      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDBG(v)   ((((reg32_t) v) << 1) & BM_WDOG_WCR_WDBG)
#else
#define BF_WDOG_WCR_WDBG(v)   (((v) << 1) & BM_WDOG_WCR_WDBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDBG(v)   BF_CS1(WDOG_WCR, WDBG, v)
#endif

/* --- Register HW_WDOG_WCR, field WDE
 *
 * Watchdog Enable. Enables or disables the WDOG-1 block. This is a write one once only bit.
 * It is not possible to clear this bit by a software write, once the bit is set.  This bit can be
 * set/reset in debug mode (exception).
 */

#define BP_WDOG_WCR_WDE      2
#define BM_WDOG_WCR_WDE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDE(v)   ((((reg32_t) v) << 2) & BM_WDOG_WCR_WDE)
#else
#define BF_WDOG_WCR_WDE(v)   (((v) << 2) & BM_WDOG_WCR_WDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDE(v)   BF_CS1(WDOG_WCR, WDE, v)
#endif

/* --- Register HW_WDOG_WCR, field SRS
 *
 * Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal
 * wdog_rst . This bit automatically resets to "1" after it has                                 been
 * asserted to "0".  This bit does not generate the software reset to the block. The Peripheral
 * Clock  (ipg_clk)  must be on to write to this                                 bit.
 */

#define BP_WDOG_WCR_SRS      4
#define BM_WDOG_WCR_SRS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_SRS(v)   ((((reg32_t) v) << 4) & BM_WDOG_WCR_SRS)
#else
#define BF_WDOG_WCR_SRS(v)   (((v) << 4) & BM_WDOG_WCR_SRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_SRS(v)   BF_CS1(WDOG_WCR, SRS, v)
#endif

/* --- Register HW_WDOG_WCR, field WDA
 *
 * WDOG   (ipp_wdog)  assertion. Controls the software assertion                                 of
 * the WDOG  ( ipp_wdog ) signal.
 */

#define BP_WDOG_WCR_WDA      5
#define BM_WDOG_WCR_WDA      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDA(v)   ((((reg32_t) v) << 5) & BM_WDOG_WCR_WDA)
#else
#define BF_WDOG_WCR_WDA(v)   (((v) << 5) & BM_WDOG_WCR_WDA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDA(v)   BF_CS1(WDOG_WCR, WDA, v)
#endif

/* --- Register HW_WDOG_WCR, field WT
 *
 * Watchdog Time-out Field. This 8-bit field contains the time-out value that is loaded into
 * the Watchdog counter after the service routine has been performed or after the Watchdog
 * is enabled. After reset, WT[7:0] must have a value written to it before enabling the
 * Watchdog otherwise count value of zero which is 0.5 seconds is loaded into the
 * counter.  The time-out value can be written at any point of time but it is loaded to the counter
 * at the time when WDOG-1 is enabled or after the service routine has been performed. For
 * more information see .
 */

#define BP_WDOG_WCR_WT      8
#define BM_WDOG_WCR_WT      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WT(v)   ((((reg32_t) v) << 8) & BM_WDOG_WCR_WT)
#else
#define BF_WDOG_WCR_WT(v)   (((v) << 8) & BM_WDOG_WCR_WT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WT(v)   BF_CS1(WDOG_WCR, WT, v)
#endif

/*!
 * @brief HW_WDOG_WSR - Watchdog Service Register
 *
 * When enabled, the WDOG-1 requires that a service sequence be written to the Watchdog Service
 * Register (WSR) to prevent the time-out condition. The write access to this register is with
 * one wait state, provided that the write data is 0xaaaa.   Executing the service sequence will
 * reload the WDOG-1 time out counter.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WSR : 16; //!< Watchdog Service Register. This 16-bit field contains the Watchdog service sequence. Both writes must occur in the order listed prior to the time-out, but any number of instructions can be executed between the two writes. The service sequence must be performed as follows:
    } B;
} hw_wdog_wsr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WSR register
 */
#define HW_WDOG_WSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WSR(x)           (*(volatile hw_wdog_wsr_t *) HW_WDOG_WSR_ADDR(x))
#define HW_WDOG_WSR_RD(x)        (HW_WDOG_WSR(x).U)
#define HW_WDOG_WSR_WR(x, v)     (HW_WDOG_WSR(x).U = (v))
#define HW_WDOG_WSR_SET(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) |  (v)))
#define HW_WDOG_WSR_CLR(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) & ~(v)))
#define HW_WDOG_WSR_TOG(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WSR bitfields
 */

/* --- Register HW_WDOG_WSR, field WSR
 *
 * Watchdog Service Register. This 16-bit field contains the Watchdog service sequence. Both
 * writes must occur in the order listed prior to the time-out, but any number of
 * instructions can be executed between the two writes. The service sequence must be
 * performed as follows:
 */

#define BP_WDOG_WSR_WSR      0
#define BM_WDOG_WSR_WSR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WSR_WSR(v)   ((((reg32_t) v) << 0) & BM_WDOG_WSR_WSR)
#else
#define BF_WDOG_WSR_WSR(v)   (((v) << 0) & BM_WDOG_WSR_WSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WSR_WSR(v)   BF_CS1(WDOG_WSR, WSR, v)
#endif

/*!
 * @brief HW_WDOG_WRSR - Watchdog Reset Status Register
 *
 * The WRSR is a read-only register that records the source of the output reset assertion. It is
 * not cleared by a hard reset. Therefore, only one bit in the WRSR will always be asserted
 * high. The register will always indicate the source of the last reset generated due to
 * WDOG-1. Read                                 access to this register is with one wait state. Any
 * write performed on this                             register will generate a Peripheral Bus Error
 * ( ips_xfr_err ) .  A reset can be generated by the following sources, as listed in priority from
 * highest to                             lowest:   Power On Reset  Watchdog Time-out  Software
 * Reset
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short SFTW : 1; //!< Software Reset. Indicates whether the reset is the result of a WDOG-1 software reset by asserting SRS bit
        unsigned short TOUT : 1; //!< Time-out. Indicates whether the reset is the result of a WDOG-1 time-out.
        unsigned short RESERVED0 : 2; //!< Reserved.
        unsigned short POR : 1; //!< Power On Reset. Indicates whether the reset is the result of a power on reset.
        unsigned short RESERVED1 : 11; //!< Reserved.
    } B;
} hw_wdog_wrsr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WRSR register
 */
#define HW_WDOG_WRSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WRSR(x)           (*(volatile hw_wdog_wrsr_t *) HW_WDOG_WRSR_ADDR(x))
#define HW_WDOG_WRSR_RD(x)        (HW_WDOG_WRSR(x).U)
#define HW_WDOG_WRSR_WR(x, v)     (HW_WDOG_WRSR(x).U = (v))
#define HW_WDOG_WRSR_SET(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) |  (v)))
#define HW_WDOG_WRSR_CLR(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) & ~(v)))
#define HW_WDOG_WRSR_TOG(x, v)    (HW_WDOG_WRSR_WR(x, HW_WDOG_WRSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WRSR bitfields
 */

/* --- Register HW_WDOG_WRSR, field SFTW
 *
 * Software Reset. Indicates whether the reset is the result of a WDOG-1 software reset by
 * asserting SRS bit
 */

#define BP_WDOG_WRSR_SFTW      0
#define BM_WDOG_WRSR_SFTW      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_SFTW(v)   ((((reg32_t) v) << 0) & BM_WDOG_WRSR_SFTW)
#else
#define BF_WDOG_WRSR_SFTW(v)   (((v) << 0) & BM_WDOG_WRSR_SFTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_SFTW(v)   BF_CS1(WDOG_WRSR, SFTW, v)
#endif

/* --- Register HW_WDOG_WRSR, field TOUT
 *
 * Time-out. Indicates whether the reset is the result of a WDOG-1 time-out.
 */

#define BP_WDOG_WRSR_TOUT      1
#define BM_WDOG_WRSR_TOUT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_TOUT(v)   ((((reg32_t) v) << 1) & BM_WDOG_WRSR_TOUT)
#else
#define BF_WDOG_WRSR_TOUT(v)   (((v) << 1) & BM_WDOG_WRSR_TOUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_TOUT(v)   BF_CS1(WDOG_WRSR, TOUT, v)
#endif

/* --- Register HW_WDOG_WRSR, field POR
 *
 * Power On Reset. Indicates whether the reset is the result of a power on reset.
 */

#define BP_WDOG_WRSR_POR      4
#define BM_WDOG_WRSR_POR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WRSR_POR(v)   ((((reg32_t) v) << 4) & BM_WDOG_WRSR_POR)
#else
#define BF_WDOG_WRSR_POR(v)   (((v) << 4) & BM_WDOG_WRSR_POR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WRSR_POR(v)   BF_CS1(WDOG_WRSR, POR, v)
#endif



/*!
 * @brief All WDOG module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_wdog_wcr_t WCR; //!< Watchdog Control Register
    volatile hw_wdog_wsr_t WSR; //!< Watchdog Service Register
    volatile hw_wdog_wrsr_t WRSR; //!< Watchdog Reset Status Register
} hw_wdog_t
#endif

//! @brief Macro to access all WDOG registers.
//! @param x WDOG instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_WDOG(0)</code>.
#define HW_WDOG(x)     (*(volatile hw_wdog_t *) REGS_WDOG_BASE(x))


#endif // _WDOG_H
