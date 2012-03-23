/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_WDOG_REGISTERS_H__
#define __HW_WDOG_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL WDOG registers defined in this header file.
 *
 * - HW_WDOG_WCR - Watchdog Control Register
 * - HW_WDOG_WSR - Watchdog Service Register
 * - HW_WDOG_WRSR - Watchdog Reset Status Register
 * - HW_WDOG_WICR - Watchdog Interrupt Control Register
 * - HW_WDOG_WMCR - Watchdog Miscellaneous Control Register
 *
 * - hw_wdog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_WDOG_BASE
#define HW_WDOG_INSTANCE_COUNT (2) //!< Number of instances of the WDOG module.
#define REGS_WDOG1_BASE (0x020bc000) //!< Base address for WDOG instance number 1.
#define REGS_WDOG2_BASE (0x020c0000) //!< Base address for WDOG instance number 2.

//! @brief Get the base address of WDOG by instance number.
//! @param x WDOG instance number, from 0 through 2.
#define REGS_WDOG_BASE(x) ( x == 1 ? REGS_WDOG1_BASE : x == 2 ? REGS_WDOG2_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WCR - Watchdog Control Register (RW)
 *
 * Reset value: 0x00000030
 *
 * The Watchdog Control Register (WDOG_WCR) controls the WDOG-1 operation.    WDZST, WDBG , WRE and
 * WDW bits are write-once only bits. Once the software does a write access to these bits, all these
 * bits will get locked and cannot be reprogrammed till the next system reset assertion.  WDZST,
 * WDBG and WRE bits are write-once only bits. Once the software does a write access to these bits,
 * all these bits will get locked and cannot be reprogrammed till the next system reset assertion.
 * WDE is a write one once only bit. Once software performs a write "1" operation to this bit it
 * cannot be reset/cleared till the next system reset.  WDT is also a write one once only bit. Once
 * software performs a write "1" operation to this bit it cannot be reset/cleared till the next POR
 * (Power-on Reset). This bit does not gets reset/cleared due to any system reset.
 */
typedef union _hw_wdog_wcr
{
    reg16_t U;
    struct _hw_wdog_wcr_bitfields
    {
        unsigned short WDZST : 1; //!< [0] Watchdog Low Power. Determines the operation of the WDOG-1 during low-power modes. This bit is write once-only. The WDOG-1 can continue/suspend the timer operation in the low-power modes (STOP , WAIT and DOZE mode).
        unsigned short WDBG : 1; //!< [1] Watchdog DEBUG Enable. Determines the operation of the WDOG-1 during DEBUG mode. This bit is write once-only.
        unsigned short WDE : 1; //!< [2] Watchdog Enable. Enables or disables the WDOG-1 block. This is a write one once only bit. It is not possible to clear this bit by a software write, once the bit is set. This bit can be set/reset in debug mode (exception).
        unsigned short WDT : 1; //!< [3] WDOG (ipp_wdog) Time-out assertion. Determines if the WDOG (ipp_wdog) gets asserted upon a Watchdog Time-out Event. This is a write-one once only bit. There is no effect on wdog_rst (WDOG Reset) upon writing on this bit. WDOG (ipp_wdog) gets asserted along with wdog_rst if this bit is set.
        unsigned short SRS : 1; //!< [4] Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal wdog_rst . This bit automatically resets to "1" after it has been asserted to "0". This bit does not generate the software reset to the block. The Peripheral Clock (ipg_clk) must be on to write to this bit.
        unsigned short WDA : 1; //!< [5] WDOG (ipp_wdog) assertion. Controls the software assertion of the WDOG ( ipp_wdog ) signal.
        unsigned short SRE : 1; //!< [6] adopt a new way to generate a more robust software reset. This bit can be set/clear with IP bus and will be reset with power-on reset .
        unsigned short WDW : 1; //!< [7] Watchdog Disable for Wait. This bit determines the operation of WDOG-1 during Low Power WAIT mode. This is a write once only bit.
        unsigned short WT : 8; //!< [15:8] Watchdog Time-out Field. This 8-bit field contains the time-out value that is loaded into the Watchdog counter after the service routine has been performed or after the Watchdog is enabled. After reset, WT[7:0] must have a value written to it before enabling the Watchdog otherwise count value of zero which is 0.5 seconds is loaded into the counter. The time-out value can be written at any point of time but it is loaded to the counter at the time when WDOG-1 is enabled or after the service routine has been performed. For more information see .
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

/* --- Register HW_WDOG_WCR, field WDZST[0] (RW)
 *
 * Watchdog Low Power. Determines the operation of the WDOG-1 during low-power modes. This bit is
 * write once-only. The WDOG-1 can continue/suspend the timer operation in the low-power modes (STOP
 * , WAIT and DOZE mode).
 *
 * Values:
 * 0 - Continue timer operation (Default).
 * 1 - Suspend the watchdog timer.
 */

#define BP_WDOG_WCR_WDZST      (0)      //!< Bit position for WDOG_WCR_WDZST.
#define BM_WDOG_WCR_WDZST      (0x00000001)  //!< Bit mask for WDOG_WCR_WDZST.

//! @brief Get value of WDOG_WCR_WDZST from a register value.
#define BG_WDOG_WCR_WDZST(r)   (((r) & BM_WDOG_WCR_WDZST) >> BP_WDOG_WCR_WDZST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDZST.
#define BF_WDOG_WCR_WDZST(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDZST) & BM_WDOG_WCR_WDZST)
#else
//! @brief Format value for bitfield WDOG_WCR_WDZST.
#define BF_WDOG_WCR_WDZST(v)   (((v) << BP_WDOG_WCR_WDZST) & BM_WDOG_WCR_WDZST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDZST field to a new value.
#define BW_WDOG_WCR_WDZST(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDZST) | BF_WDOG_WCR_WDZST(v)))
#endif


/* --- Register HW_WDOG_WCR, field WDBG[1] (RW)
 *
 * Watchdog DEBUG Enable. Determines the operation of the WDOG-1 during DEBUG mode. This bit is
 * write once-only.
 *
 * Values:
 * 0 - Continue WDOG-1 timer operation (Default).
 * 1 - Suspend the watchdog timer.
 */

#define BP_WDOG_WCR_WDBG      (1)      //!< Bit position for WDOG_WCR_WDBG.
#define BM_WDOG_WCR_WDBG      (0x00000002)  //!< Bit mask for WDOG_WCR_WDBG.

//! @brief Get value of WDOG_WCR_WDBG from a register value.
#define BG_WDOG_WCR_WDBG(r)   (((r) & BM_WDOG_WCR_WDBG) >> BP_WDOG_WCR_WDBG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDBG.
#define BF_WDOG_WCR_WDBG(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDBG) & BM_WDOG_WCR_WDBG)
#else
//! @brief Format value for bitfield WDOG_WCR_WDBG.
#define BF_WDOG_WCR_WDBG(v)   (((v) << BP_WDOG_WCR_WDBG) & BM_WDOG_WCR_WDBG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDBG field to a new value.
#define BW_WDOG_WCR_WDBG(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDBG) | BF_WDOG_WCR_WDBG(v)))
#endif


/* --- Register HW_WDOG_WCR, field WDE[2] (RW)
 *
 * Watchdog Enable. Enables or disables the WDOG-1 block. This is a write one once only bit. It is
 * not possible to clear this bit by a software write, once the bit is set. This bit can be
 * set/reset in debug mode (exception).
 *
 * Values:
 * 0 - Disable the Watchdog (Default).
 * 1 - Enable the Watchdog.
 */

#define BP_WDOG_WCR_WDE      (2)      //!< Bit position for WDOG_WCR_WDE.
#define BM_WDOG_WCR_WDE      (0x00000004)  //!< Bit mask for WDOG_WCR_WDE.

//! @brief Get value of WDOG_WCR_WDE from a register value.
#define BG_WDOG_WCR_WDE(r)   (((r) & BM_WDOG_WCR_WDE) >> BP_WDOG_WCR_WDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDE.
#define BF_WDOG_WCR_WDE(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDE) & BM_WDOG_WCR_WDE)
#else
//! @brief Format value for bitfield WDOG_WCR_WDE.
#define BF_WDOG_WCR_WDE(v)   (((v) << BP_WDOG_WCR_WDE) & BM_WDOG_WCR_WDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDE field to a new value.
#define BW_WDOG_WCR_WDE(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDE) | BF_WDOG_WCR_WDE(v)))
#endif


/* --- Register HW_WDOG_WCR, field WDT[3] (RW)
 *
 * WDOG (ipp_wdog) Time-out assertion. Determines if the WDOG (ipp_wdog) gets asserted upon a
 * Watchdog Time-out Event. This is a write-one once only bit. There is no effect on wdog_rst (WDOG
 * Reset) upon writing on this bit. WDOG (ipp_wdog) gets asserted along with wdog_rst if this bit is
 * set.
 *
 * Values:
 * 0 - No effect on WDOG   (ipp_wdog)  (Default).
 * 1 - Assert WDOG   (ipp_wdog)  upon a Watchdog Time-out event.
 */

#define BP_WDOG_WCR_WDT      (3)      //!< Bit position for WDOG_WCR_WDT.
#define BM_WDOG_WCR_WDT      (0x00000008)  //!< Bit mask for WDOG_WCR_WDT.

//! @brief Get value of WDOG_WCR_WDT from a register value.
#define BG_WDOG_WCR_WDT(r)   (((r) & BM_WDOG_WCR_WDT) >> BP_WDOG_WCR_WDT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDT.
#define BF_WDOG_WCR_WDT(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDT) & BM_WDOG_WCR_WDT)
#else
//! @brief Format value for bitfield WDOG_WCR_WDT.
#define BF_WDOG_WCR_WDT(v)   (((v) << BP_WDOG_WCR_WDT) & BM_WDOG_WCR_WDT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDT field to a new value.
#define BW_WDOG_WCR_WDT(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDT) | BF_WDOG_WCR_WDT(v)))
#endif


/* --- Register HW_WDOG_WCR, field SRS[4] (RW)
 *
 * Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal
 * wdog_rst . This bit automatically resets to "1" after it has been asserted to "0". This bit does
 * not generate the software reset to the block. The Peripheral Clock (ipg_clk) must be on to write
 * to this bit.
 *
 * Values:
 * 0 - Assert system reset signal.
 * 1 - No effect on the system (Default).
 */

#define BP_WDOG_WCR_SRS      (4)      //!< Bit position for WDOG_WCR_SRS.
#define BM_WDOG_WCR_SRS      (0x00000010)  //!< Bit mask for WDOG_WCR_SRS.

//! @brief Get value of WDOG_WCR_SRS from a register value.
#define BG_WDOG_WCR_SRS(r)   (((r) & BM_WDOG_WCR_SRS) >> BP_WDOG_WCR_SRS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_SRS.
#define BF_WDOG_WCR_SRS(v)   ((((reg16_t) v) << BP_WDOG_WCR_SRS) & BM_WDOG_WCR_SRS)
#else
//! @brief Format value for bitfield WDOG_WCR_SRS.
#define BF_WDOG_WCR_SRS(v)   (((v) << BP_WDOG_WCR_SRS) & BM_WDOG_WCR_SRS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRS field to a new value.
#define BW_WDOG_WCR_SRS(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_SRS) | BF_WDOG_WCR_SRS(v)))
#endif


/* --- Register HW_WDOG_WCR, field WDA[5] (RW)
 *
 * WDOG (ipp_wdog) assertion. Controls the software assertion of the WDOG ( ipp_wdog ) signal.
 *
 * Values:
 * 0 - Assert WDOG   (ipp_wdog)  output.
 * 1 - No effect on system (Default).
 */

#define BP_WDOG_WCR_WDA      (5)      //!< Bit position for WDOG_WCR_WDA.
#define BM_WDOG_WCR_WDA      (0x00000020)  //!< Bit mask for WDOG_WCR_WDA.

//! @brief Get value of WDOG_WCR_WDA from a register value.
#define BG_WDOG_WCR_WDA(r)   (((r) & BM_WDOG_WCR_WDA) >> BP_WDOG_WCR_WDA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDA.
#define BF_WDOG_WCR_WDA(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDA) & BM_WDOG_WCR_WDA)
#else
//! @brief Format value for bitfield WDOG_WCR_WDA.
#define BF_WDOG_WCR_WDA(v)   (((v) << BP_WDOG_WCR_WDA) & BM_WDOG_WCR_WDA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDA field to a new value.
#define BW_WDOG_WCR_WDA(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDA) | BF_WDOG_WCR_WDA(v)))
#endif


/* --- Register HW_WDOG_WCR, field SRE[6] (RW)
 *
 * adopt a new way to generate a more robust software reset. This bit can be set/clear with IP bus
 * and will be reset with power-on reset .
 *
 * Values:
 * 0 - using original way to generate software reset (default)
 * 1 - using new way to generate software reset.
 */

#define BP_WDOG_WCR_SRE      (6)      //!< Bit position for WDOG_WCR_SRE.
#define BM_WDOG_WCR_SRE      (0x00000040)  //!< Bit mask for WDOG_WCR_SRE.

//! @brief Get value of WDOG_WCR_SRE from a register value.
#define BG_WDOG_WCR_SRE(r)   (((r) & BM_WDOG_WCR_SRE) >> BP_WDOG_WCR_SRE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_SRE.
#define BF_WDOG_WCR_SRE(v)   ((((reg16_t) v) << BP_WDOG_WCR_SRE) & BM_WDOG_WCR_SRE)
#else
//! @brief Format value for bitfield WDOG_WCR_SRE.
#define BF_WDOG_WCR_SRE(v)   (((v) << BP_WDOG_WCR_SRE) & BM_WDOG_WCR_SRE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_WDOG_WCR_SRE(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_SRE) | BF_WDOG_WCR_SRE(v)))
#endif


/* --- Register HW_WDOG_WCR, field WDW[7] (RW)
 *
 * Watchdog Disable for Wait. This bit determines the operation of WDOG-1 during Low Power WAIT
 * mode. This is a write once only bit.
 *
 * Values:
 * 0 - Continue WDOG-1 timer operation (Default).
 * 1 - Suspend WDOG-1 timer operation.
 */

#define BP_WDOG_WCR_WDW      (7)      //!< Bit position for WDOG_WCR_WDW.
#define BM_WDOG_WCR_WDW      (0x00000080)  //!< Bit mask for WDOG_WCR_WDW.

//! @brief Get value of WDOG_WCR_WDW from a register value.
#define BG_WDOG_WCR_WDW(r)   (((r) & BM_WDOG_WCR_WDW) >> BP_WDOG_WCR_WDW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WDW.
#define BF_WDOG_WCR_WDW(v)   ((((reg16_t) v) << BP_WDOG_WCR_WDW) & BM_WDOG_WCR_WDW)
#else
//! @brief Format value for bitfield WDOG_WCR_WDW.
#define BF_WDOG_WCR_WDW(v)   (((v) << BP_WDOG_WCR_WDW) & BM_WDOG_WCR_WDW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDW field to a new value.
#define BW_WDOG_WCR_WDW(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDW) | BF_WDOG_WCR_WDW(v)))
#endif


/* --- Register HW_WDOG_WCR, field WT[15:8] (RW)
 *
 * Watchdog Time-out Field. This 8-bit field contains the time-out value that is loaded into the
 * Watchdog counter after the service routine has been performed or after the Watchdog is enabled.
 * After reset, WT[7:0] must have a value written to it before enabling the Watchdog otherwise count
 * value of zero which is 0.5 seconds is loaded into the counter. The time-out value can be written
 * at any point of time but it is loaded to the counter at the time when WDOG-1 is enabled or after
 * the service routine has been performed. For more information see .
 *
 * Values:
 * 0x00 - - 0.5 Seconds (Default).
 * 0x01 - - 1.0 Seconds.
 * 0x02 - - 1.5 Seconds.
 * 0x03 - - 2.0 Seconds.
 * 0xff - - 128 Seconds.
 */

#define BP_WDOG_WCR_WT      (8)      //!< Bit position for WDOG_WCR_WT.
#define BM_WDOG_WCR_WT      (0x0000ff00)  //!< Bit mask for WDOG_WCR_WT.

//! @brief Get value of WDOG_WCR_WT from a register value.
#define BG_WDOG_WCR_WT(r)   (((r) & BM_WDOG_WCR_WT) >> BP_WDOG_WCR_WT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WCR_WT.
#define BF_WDOG_WCR_WT(v)   ((((reg16_t) v) << BP_WDOG_WCR_WT) & BM_WDOG_WCR_WT)
#else
//! @brief Format value for bitfield WDOG_WCR_WT.
#define BF_WDOG_WCR_WT(v)   (((v) << BP_WDOG_WCR_WT) & BM_WDOG_WCR_WT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WT field to a new value.
#define BW_WDOG_WCR_WT(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WT) | BF_WDOG_WCR_WT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WSR - Watchdog Service Register (RW)
 *
 * Reset value: 0x00000000
 *
 * When enabled, the WDOG-1 requires that a service sequence be written to the Watchdog Service
 * Register (WSR) to prevent the time-out condition. The write access to this register is with one
 * wait state, provided that the write data is 0xaaaa.   Executing the service sequence will reload
 * the WDOG-1 time out counter.
 */
typedef union _hw_wdog_wsr
{
    reg16_t U;
    struct _hw_wdog_wsr_bitfields
    {
        unsigned short WSR : 16; //!< [15:0] Watchdog Service Register. This 16-bit field contains the Watchdog service sequence. Both writes must occur in the order listed prior to the time-out, but any number of instructions can be executed between the two writes. The service sequence must be performed as follows:
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

/* --- Register HW_WDOG_WSR, field WSR[15:0] (RW)
 *
 * Watchdog Service Register. This 16-bit field contains the Watchdog service sequence. Both writes
 * must occur in the order listed prior to the time-out, but any number of instructions can be
 * executed between the two writes. The service sequence must be performed as follows:
 *
 * Values:
 * 0x5555 - Write to the Watchdog Service Register (WDOG_WSR).
 * 0xAAAA - Write to the Watchdog Service Register (WDOG_WSR).
 */

#define BP_WDOG_WSR_WSR      (0)      //!< Bit position for WDOG_WSR_WSR.
#define BM_WDOG_WSR_WSR      (0x0000ffff)  //!< Bit mask for WDOG_WSR_WSR.

//! @brief Get value of WDOG_WSR_WSR from a register value.
#define BG_WDOG_WSR_WSR(r)   (((r) & BM_WDOG_WSR_WSR) >> BP_WDOG_WSR_WSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WSR_WSR.
#define BF_WDOG_WSR_WSR(v)   ((((reg16_t) v) << BP_WDOG_WSR_WSR) & BM_WDOG_WSR_WSR)
#else
//! @brief Format value for bitfield WDOG_WSR_WSR.
#define BF_WDOG_WSR_WSR(v)   (((v) << BP_WDOG_WSR_WSR) & BM_WDOG_WSR_WSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WSR field to a new value.
#define BW_WDOG_WSR_WSR(x, v)   (HW_WDOG_WSR_WR(x, (HW_WDOG_WSR_RD(x) & ~BM_WDOG_WSR_WSR) | BF_WDOG_WSR_WSR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WRSR - Watchdog Reset Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The WRSR is a read-only register that records the source of the output reset assertion. It is not
 * cleared by a hard reset. Therefore, only one bit in the WRSR will always be asserted high. The
 * register will always indicate the source of the last reset generated due to WDOG-1. Read access
 * to this register is with one wait state. Any write performed on this register will generate a
 * Peripheral Bus Error ( ips_xfr_err ) .  A reset can be generated by the following sources, as
 * listed in priority from highest to lowest:   Power On Reset  Watchdog Time-out  Software Reset
 */
typedef union _hw_wdog_wrsr
{
    reg16_t U;
    struct _hw_wdog_wrsr_bitfields
    {
        unsigned short SFTW : 1; //!< [0] Software Reset. Indicates whether the reset is the result of a WDOG-1 software reset by asserting SRS bit
        unsigned short TOUT : 1; //!< [1] Time-out. Indicates whether the reset is the result of a WDOG-1 time-out.
        unsigned short RESERVED0 : 2; //!< [3:2] Reserved.
        unsigned short POR : 1; //!< [4] Power On Reset. Indicates whether the reset is the result of a power on reset.
        unsigned short RESERVED1 : 11; //!< [15:5] Reserved.
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
#endif

/*
 * constants & macros for individual WDOG_WRSR bitfields
 */

/* --- Register HW_WDOG_WRSR, field SFTW[0] (RO)
 *
 * Software Reset. Indicates whether the reset is the result of a WDOG-1 software reset by asserting
 * SRS bit
 *
 * Values:
 * 0 - Reset is not the result of a software reset.
 * 1 - Reset is the result of a software reset.
 */

#define BP_WDOG_WRSR_SFTW      (0)      //!< Bit position for WDOG_WRSR_SFTW.
#define BM_WDOG_WRSR_SFTW      (0x00000001)  //!< Bit mask for WDOG_WRSR_SFTW.

//! @brief Get value of WDOG_WRSR_SFTW from a register value.
#define BG_WDOG_WRSR_SFTW(r)   (((r) & BM_WDOG_WRSR_SFTW) >> BP_WDOG_WRSR_SFTW)


/* --- Register HW_WDOG_WRSR, field TOUT[1] (RO)
 *
 * Time-out. Indicates whether the reset is the result of a WDOG-1 time-out.
 *
 * Values:
 * 0 - Reset is not the result of a WDOG-1 time-out.
 * 1 - Reset is the result of a WDOG-1 time-out.
 */

#define BP_WDOG_WRSR_TOUT      (1)      //!< Bit position for WDOG_WRSR_TOUT.
#define BM_WDOG_WRSR_TOUT      (0x00000002)  //!< Bit mask for WDOG_WRSR_TOUT.

//! @brief Get value of WDOG_WRSR_TOUT from a register value.
#define BG_WDOG_WRSR_TOUT(r)   (((r) & BM_WDOG_WRSR_TOUT) >> BP_WDOG_WRSR_TOUT)


/* --- Register HW_WDOG_WRSR, field POR[4] (RO)
 *
 * Power On Reset. Indicates whether the reset is the result of a power on reset.
 *
 * Values:
 * 0 - Reset is not the result of a power on reset.
 * 1 - Reset is the result of a power on reset.
 */

#define BP_WDOG_WRSR_POR      (4)      //!< Bit position for WDOG_WRSR_POR.
#define BM_WDOG_WRSR_POR      (0x00000010)  //!< Bit mask for WDOG_WRSR_POR.

//! @brief Get value of WDOG_WRSR_POR from a register value.
#define BG_WDOG_WRSR_POR(r)   (((r) & BM_WDOG_WRSR_POR) >> BP_WDOG_WRSR_POR)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WICR - Watchdog Interrupt Control Register (RW)
 *
 * Reset value: 0x00000004
 *
 * The WDOG_WICR controls the WDOG-1 interrupt generation.
 */
typedef union _hw_wdog_wicr
{
    reg16_t U;
    struct _hw_wdog_wicr_bitfields
    {
        unsigned short WICT : 8; //!< [7:0] Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter time-out must the interrupt occur. The reset value is 0x04 implies interrupt will occur 2 seconds before time-out. The maximum value that can be programmed to WICT field is 127.5 seconds with a resolution of 0.5 seconds. This field is write once only. Once the software does a write access to this field, it will get locked and cannot be reprogrammed till the next system reset assertion.
        unsigned short RESERVED0 : 6; //!< [13:8] Reserved.
        unsigned short WTIS : 1; //!< [14] Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether interrupt has occurred or not.Once the interrupt has been triggered software must clear this bit by writing 1 to it.
        unsigned short WIE : 1; //!< [15] Watchdog Timer Interrupt enable bit. Reset value is 0. This bit is a write once only bit. Once the software does a write access to this bit, it will get locked and cannot be reprogrammed till the next system reset assertion
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

/* --- Register HW_WDOG_WICR, field WICT[7:0] (RW)
 *
 * Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter time-out
 * must the interrupt occur. The reset value is 0x04 implies interrupt will occur 2 seconds before
 * time-out. The maximum value that can be programmed to WICT field is 127.5 seconds with a
 * resolution of 0.5 seconds. This field is write once only. Once the software does a write access
 * to this field, it will get locked and cannot be reprogrammed till the next system reset
 * assertion.
 *
 * Values:
 * 0x00 - WICT[7:0] = Time duration between interrupt and time-out is 0 seconds.
 * 0x01 - WICT[7:0] = Time duration between interrupt and time-out is 0.5 seconds.
 * 0x04 - WICT[7:0] = Time duration between interrupt and time-out is 2 seconds (Default).
 * 0xff - WICT[7:0] = Time duration between interrupt and time-out is 127.5 seconds.
 */

#define BP_WDOG_WICR_WICT      (0)      //!< Bit position for WDOG_WICR_WICT.
#define BM_WDOG_WICR_WICT      (0x000000ff)  //!< Bit mask for WDOG_WICR_WICT.

//! @brief Get value of WDOG_WICR_WICT from a register value.
#define BG_WDOG_WICR_WICT(r)   (((r) & BM_WDOG_WICR_WICT) >> BP_WDOG_WICR_WICT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WICR_WICT.
#define BF_WDOG_WICR_WICT(v)   ((((reg16_t) v) << BP_WDOG_WICR_WICT) & BM_WDOG_WICR_WICT)
#else
//! @brief Format value for bitfield WDOG_WICR_WICT.
#define BF_WDOG_WICR_WICT(v)   (((v) << BP_WDOG_WICR_WICT) & BM_WDOG_WICR_WICT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WICT field to a new value.
#define BW_WDOG_WICR_WICT(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WICT) | BF_WDOG_WICR_WICT(v)))
#endif


/* --- Register HW_WDOG_WICR, field WTIS[14] (W1C)
 *
 * Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether interrupt
 * has occurred or not.Once the interrupt has been triggered software must clear this bit by writing
 * 1 to it.
 *
 * Values:
 * 0 - No interrupt has occurred (Default).
 * 1 - Interrupt has occurred
 */

#define BP_WDOG_WICR_WTIS      (14)      //!< Bit position for WDOG_WICR_WTIS.
#define BM_WDOG_WICR_WTIS      (0x00004000)  //!< Bit mask for WDOG_WICR_WTIS.

//! @brief Get value of WDOG_WICR_WTIS from a register value.
#define BG_WDOG_WICR_WTIS(r)   (((r) & BM_WDOG_WICR_WTIS) >> BP_WDOG_WICR_WTIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WICR_WTIS.
#define BF_WDOG_WICR_WTIS(v)   ((((reg16_t) v) << BP_WDOG_WICR_WTIS) & BM_WDOG_WICR_WTIS)
#else
//! @brief Format value for bitfield WDOG_WICR_WTIS.
#define BF_WDOG_WICR_WTIS(v)   (((v) << BP_WDOG_WICR_WTIS) & BM_WDOG_WICR_WTIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WTIS field to a new value.
#define BW_WDOG_WICR_WTIS(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WTIS) | BF_WDOG_WICR_WTIS(v)))
#endif


/* --- Register HW_WDOG_WICR, field WIE[15] (RW)
 *
 * Watchdog Timer Interrupt enable bit. Reset value is 0. This bit is a write once only bit. Once
 * the software does a write access to this bit, it will get locked and cannot be reprogrammed till
 * the next system reset assertion
 *
 * Values:
 * 0 - Disable Interrupt (Default).
 * 1 - Enable Interrupt.
 */

#define BP_WDOG_WICR_WIE      (15)      //!< Bit position for WDOG_WICR_WIE.
#define BM_WDOG_WICR_WIE      (0x00008000)  //!< Bit mask for WDOG_WICR_WIE.

//! @brief Get value of WDOG_WICR_WIE from a register value.
#define BG_WDOG_WICR_WIE(r)   (((r) & BM_WDOG_WICR_WIE) >> BP_WDOG_WICR_WIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WICR_WIE.
#define BF_WDOG_WICR_WIE(v)   ((((reg16_t) v) << BP_WDOG_WICR_WIE) & BM_WDOG_WICR_WIE)
#else
//! @brief Format value for bitfield WDOG_WICR_WIE.
#define BF_WDOG_WICR_WIE(v)   (((v) << BP_WDOG_WICR_WIE) & BM_WDOG_WICR_WIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_WDOG_WICR_WIE(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WIE) | BF_WDOG_WICR_WIE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WMCR - Watchdog Miscellaneous Control Register (RW)
 *
 * Reset value: 0x00000001
 *
 * WDOG_WMCR Controls the Power Down counter operation.
 */
typedef union _hw_wdog_wmcr
{
    reg16_t U;
    struct _hw_wdog_wmcr_bitfields
    {
        unsigned short PDE : 1; //!< [0] Power Down Enable bit. Reset value of this bit is 1, which means the power down counter inside the WDOG-1 is enabled after reset. The software must write 0 to this bit to disable the counter within 16 seconds of reset de-assertion. Once disabled this counter cannot be enabled again. See for operation of this counter. This bit is write-one once only bit. Once software sets this bit it cannot be reset till the next system reset.
        unsigned short RESERVED0 : 15; //!< [15:1] Reserved.
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

/* --- Register HW_WDOG_WMCR, field PDE[0] (RW)
 *
 * Power Down Enable bit. Reset value of this bit is 1, which means the power down counter inside
 * the WDOG-1 is enabled after reset. The software must write 0 to this bit to disable the counter
 * within 16 seconds of reset de-assertion. Once disabled this counter cannot be enabled again. See
 * for operation of this counter. This bit is write-one once only bit. Once software sets this bit
 * it cannot be reset till the next system reset.
 *
 * Values:
 * 0 - Power Down Counter of WDOG-1 is disabled.
 * 1 - Power Down Counter of WDOG-1 is enabled (Default).
 */

#define BP_WDOG_WMCR_PDE      (0)      //!< Bit position for WDOG_WMCR_PDE.
#define BM_WDOG_WMCR_PDE      (0x00000001)  //!< Bit mask for WDOG_WMCR_PDE.

//! @brief Get value of WDOG_WMCR_PDE from a register value.
#define BG_WDOG_WMCR_PDE(r)   (((r) & BM_WDOG_WMCR_PDE) >> BP_WDOG_WMCR_PDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield WDOG_WMCR_PDE.
#define BF_WDOG_WMCR_PDE(v)   ((((reg16_t) v) << BP_WDOG_WMCR_PDE) & BM_WDOG_WMCR_PDE)
#else
//! @brief Format value for bitfield WDOG_WMCR_PDE.
#define BF_WDOG_WMCR_PDE(v)   (((v) << BP_WDOG_WMCR_PDE) & BM_WDOG_WMCR_PDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDE field to a new value.
#define BW_WDOG_WMCR_PDE(x, v)   (HW_WDOG_WMCR_WR(x, (HW_WDOG_WMCR_RD(x) & ~BM_WDOG_WMCR_PDE) | BF_WDOG_WMCR_PDE(v)))
#endif



/*!
 * @brief All WDOG module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_wdog
{
    volatile hw_wdog_wcr_t WCR; //!< Watchdog Control Register
    volatile hw_wdog_wsr_t WSR; //!< Watchdog Service Register
    volatile hw_wdog_wrsr_t WRSR; //!< Watchdog Reset Status Register
    volatile hw_wdog_wicr_t WICR; //!< Watchdog Interrupt Control Register
    volatile hw_wdog_wmcr_t WMCR; //!< Watchdog Miscellaneous Control Register
} hw_wdog_t;
#pragma pack()

//! @brief Macro to access all WDOG registers.
//! @param x WDOG instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_WDOG(0)</code>.
#define HW_WDOG(x)     (*(volatile hw_wdog_t *) REGS_WDOG_BASE(x))

#endif


#endif // __HW_WDOG_REGISTERS_H__
