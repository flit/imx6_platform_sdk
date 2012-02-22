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
        unsigned short WDT : 1; //!< WDOG   (ipp_wdog)  Time-out assertion. Determines if the WDOG   (ipp_wdog)  gets asserted upon a Watchdog Time-out Event. This is a write-one once only bit.  There is no effect on wdog_rst (WDOG Reset) upon writing on this bit. WDOG   (ipp_wdog)  gets asserted along with wdog_rst if this bit is set.
        unsigned short SRS : 1; //!< Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal wdog_rst . This bit automatically resets to "1" after it has been asserted to "0".  This bit does not generate the software reset to the block. The Peripheral Clock  (ipg_clk)  must be on to write to this bit.
        unsigned short WDA : 1; //!< WDOG   (ipp_wdog)  assertion. Controls the software assertion of the WDOG  ( ipp_wdog ) signal.
        unsigned short RESERVED0 : 1; //!< 
        unsigned short WDW : 1; //!< Watchdog Disable for Wait. This bit determines the operation of WDOG-1 during Low Power WAIT mode. This is a write once only bit.
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

/* --- Register HW_WDOG_WCR, field WDT
 *
 * WDOG   (ipp_wdog)  Time-out assertion. Determines if the WDOG   (ipp_wdog)  gets asserted upon a
 * Watchdog Time-out                                 Event. This is a write-one once only bit.
 * There is no effect on wdog_rst (WDOG Reset) upon writing on                                 this
 * bit. WDOG   (ipp_wdog)  gets asserted along with wdog_rst if this bit is set.
 */

#define BP_WDOG_WCR_WDT      3
#define BM_WDOG_WCR_WDT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDT(v)   ((((reg32_t) v) << 3) & BM_WDOG_WCR_WDT)
#else
#define BF_WDOG_WCR_WDT(v)   (((v) << 3) & BM_WDOG_WCR_WDT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDT(v)   BF_CS1(WDOG_WCR, WDT, v)
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

/* --- Register HW_WDOG_WCR, field WDW
 *
 * Watchdog Disable for Wait. This bit determines the operation of WDOG-1 during Low Power
 * WAIT mode. This is a write once only bit.
 */

#define BP_WDOG_WCR_WDW      7
#define BM_WDOG_WCR_WDW      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WCR_WDW(v)   ((((reg32_t) v) << 7) & BM_WDOG_WCR_WDW)
#else
#define BF_WDOG_WCR_WDW(v)   (((v) << 7) & BM_WDOG_WCR_WDW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WCR_WDW(v)   BF_CS1(WDOG_WCR, WDW, v)
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
 * @brief HW_WDOG_WICR - Watchdog Interrupt Control Register
 *
 * The WDOG_WICR controls the WDOG-1 interrupt generation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short WICT : 8; //!< Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter time-out must the interrupt occur. The reset value is 0x04 implies interrupt will occur 2 seconds before time-out. The maximum value that can be programmed to WICT field is 127.5 seconds with a resolution of 0.5 seconds.  This field is write once only. Once the software does a write access to this field, it will get locked and cannot be reprogrammed till the next system reset assertion.
        unsigned short RESERVED0 : 6; //!< Reserved.
        unsigned short WTIS : 1; //!< Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether interrupt has occurred or not.Once the interrupt has been triggered software must clear this bit by writing 1 to it.
        unsigned short WIE : 1; //!< Watchdog Timer Interrupt enable bit. Reset value is 0.   This bit is a write once only bit. Once the software does a write access to this bit, it will get locked and cannot be reprogrammed till the next system reset assertion
    } B;
} hw_wdog_wicr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WICR register
 */
#define HW_WDOG_WICR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WICR(x)           (*(volatile hw_wdog_wicr_t *) HW_WDOG_WICR_ADDR(x))
#define HW_WDOG_WICR_RD(x)        (HW_WDOG_WICR(x).U)
#define HW_WDOG_WICR_WR(x, v)     (HW_WDOG_WICR(x).U = (v))
#define HW_WDOG_WICR_SET(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) |  (v)))
#define HW_WDOG_WICR_CLR(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) & ~(v)))
#define HW_WDOG_WICR_TOG(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WICR bitfields
 */

/* --- Register HW_WDOG_WICR, field WICT
 *
 * Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter
 * time-out must the interrupt occur. The reset value is 0x04 implies interrupt will occur
 * 2 seconds before time-out. The maximum value that can be programmed to WICT field is
 * 127.5 seconds with a resolution of 0.5 seconds.  This field is write once only. Once the software
 * does a write access to this field, it                                 will get locked and cannot
 * be reprogrammed till the next system reset assertion.
 */

#define BP_WDOG_WICR_WICT      0
#define BM_WDOG_WICR_WICT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WICT(v)   ((((reg32_t) v) << 0) & BM_WDOG_WICR_WICT)
#else
#define BF_WDOG_WICR_WICT(v)   (((v) << 0) & BM_WDOG_WICR_WICT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WICT(v)   BF_CS1(WDOG_WICR, WICT, v)
#endif

/* --- Register HW_WDOG_WICR, field WTIS
 *
 * Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether
 * interrupt has occurred or not.Once the interrupt has been triggered software must clear
 * this bit by writing 1 to it.
 */

#define BP_WDOG_WICR_WTIS      14
#define BM_WDOG_WICR_WTIS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WTIS(v)   ((((reg32_t) v) << 14) & BM_WDOG_WICR_WTIS)
#else
#define BF_WDOG_WICR_WTIS(v)   (((v) << 14) & BM_WDOG_WICR_WTIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WTIS(v)   BF_CS1(WDOG_WICR, WTIS, v)
#endif

/* --- Register HW_WDOG_WICR, field WIE
 *
 * Watchdog Timer Interrupt enable bit. Reset value is 0.   This bit is a write once only bit. Once
 * the software does a write access to this bit,                                 it will get locked
 * and cannot be reprogrammed till the next system reset                                 assertion
 */

#define BP_WDOG_WICR_WIE      15
#define BM_WDOG_WICR_WIE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WICR_WIE(v)   ((((reg32_t) v) << 15) & BM_WDOG_WICR_WIE)
#else
#define BF_WDOG_WICR_WIE(v)   (((v) << 15) & BM_WDOG_WICR_WIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WICR_WIE(v)   BF_CS1(WDOG_WICR, WIE, v)
#endif

/*!
 * @brief HW_WDOG_WMCR - Watchdog Miscellaneous Control Register
 *
 * WDOG_WMCR Controls the Power Down counter operation.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short PDE : 1; //!< Power Down Enable bit. Reset value of this bit is 1, which means the power down counter inside the WDOG-1 is enabled after reset. The software must write 0 to this bit to disable the counter within 16 seconds of reset de-assertion. Once disabled this counter cannot be enabled again. See for operation of this counter.  This bit is write-one once only bit. Once software sets this bit it cannot be reset till the next system reset.
        unsigned short RESERVED0 : 15; //!< Reserved.
    } B;
} hw_wdog_wmcr_t;
#endif

/*
 * constants & macros for entire multi-block WDOG_WMCR register
 */
#define HW_WDOG_WMCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WMCR(x)           (*(volatile hw_wdog_wmcr_t *) HW_WDOG_WMCR_ADDR(x))
#define HW_WDOG_WMCR_RD(x)        (HW_WDOG_WMCR(x).U)
#define HW_WDOG_WMCR_WR(x, v)     (HW_WDOG_WMCR(x).U = (v))
#define HW_WDOG_WMCR_SET(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) |  (v)))
#define HW_WDOG_WMCR_CLR(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) & ~(v)))
#define HW_WDOG_WMCR_TOG(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual WDOG_WMCR bitfields
 */

/* --- Register HW_WDOG_WMCR, field PDE
 *
 * Power Down Enable bit. Reset value of this bit is 1, which means the power down counter
 * inside the WDOG-1 is enabled after reset. The software must write 0 to this bit to
 * disable the counter within 16 seconds of reset de-assertion. Once disabled this counter
 * cannot be enabled again. See for operation of this counter.  This bit is write-one once only bit.
 * Once software sets this bit it cannot be reset                                 till the next
 * system reset.
 */

#define BP_WDOG_WMCR_PDE      0
#define BM_WDOG_WMCR_PDE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_WDOG_WMCR_PDE(v)   ((((reg32_t) v) << 0) & BM_WDOG_WMCR_PDE)
#else
#define BF_WDOG_WMCR_PDE(v)   (((v) << 0) & BM_WDOG_WMCR_PDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_WDOG_WMCR_PDE(v)   BF_CS1(WDOG_WMCR, PDE, v)
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
    volatile hw_wdog_wicr_t WICR; //!< Watchdog Interrupt Control Register
    volatile hw_wdog_wmcr_t WMCR; //!< Watchdog Miscellaneous Control Register
} hw_wdog_t
#endif

//! @brief Macro to access all WDOG registers.
//! @param x WDOG instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_WDOG(0)</code>.
#define HW_WDOG(x)     (*(volatile hw_wdog_t *) REGS_WDOG_BASE(x))


#endif // _WDOG_H
