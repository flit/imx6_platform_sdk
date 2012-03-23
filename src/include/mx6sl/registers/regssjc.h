/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SJC_REGISTERS_H__
#define __HW_SJC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL SJC registers defined in this header file.
 *
 * - HW_SJC_GPUSR1 - General Purpose Unsecured Status Register 1
 * - HW_SJC_GPUSR2 - General Purpose Unsecured Status Register 2
 * - HW_SJC_GPUSR3 - General Purpose Unsecured Status Register 3
 * - HW_SJC_GPSSR - General Purpose Secured Status Register
 * - HW_SJC_DCR - Debug Control Register
 * - HW_SJC_SSR - Security Status Register
 * - HW_SJC_GPCCR - General Purpose Clocks Control Register
 * - HW_SJC_GPUCR1 - General Purpose Unsecured Control Register n
 * - HW_SJC_GPUCR2 - General Purpose Unsecured Control Register n
 * - HW_SJC_GPUCR3 - General Purpose Unsecured Control Register n
 * - HW_SJC_GPSCR - General Purpose Secured Control Register
 *
 * - hw_sjc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SJC_BASE
#define HW_SJC_INSTANCE_COUNT (1) //!< Number of instances of the SJC module.
#define REGS_SJC_BASE (0x00000000) //!< Base address for SJC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUSR1 - General Purpose Unsecured Status Register 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * The General Purpose Unsecured Status Register 1 is a read only registers used to check the status
 * of the different Cores and of the PLL. The rest of its bits are for general purpose use.
 */
typedef union _hw_sjc_gpusr1
{
    reg32_t U;
    struct _hw_sjc_gpusr1_bitfields
    {
        unsigned A_DBG : 1; //!< [0] ARM core debug status bit Bit 0 is the ARM core DBGACK (debug acknowledge) DBGACK can be overwritten in the ARM core DCR to force a particular DBGACK value. Consequently interpretation of the DBGACK value is highly dependent on the debug sequence. When this bit is HIGH, ARM core is in debug.
        unsigned A_WFI : 1; //!< [1] ARM core wait-for interrupt bit Bit 1 is the ARM core standbywfi (stand by wait-for interrupt). When this bit is HIGH, ARM core is in wait for interrupt mode.
        unsigned S_STAT : 3; //!< [4:2] 3 LSBits of SDMA core statusH.
        unsigned RESERVED0 : 3; //!< [7:5] Reserved.
        unsigned PLL_LOCK : 1; //!< [8] PLL_LOCK A Combined PLL-Lock flag indicator, for all the PLL's.
        unsigned RESERVED1 : 23; //!< [31:9] Reserved.
    } B;
} hw_sjc_gpusr1_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR1 register
 */
#define HW_SJC_GPUSR1_ADDR      (REGS_SJC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR1           (*(volatile hw_sjc_gpusr1_t *) HW_SJC_GPUSR1_ADDR)
#define HW_SJC_GPUSR1_RD()      (HW_SJC_GPUSR1.U)
#endif

/*
 * constants & macros for individual SJC_GPUSR1 bitfields
 */

/* --- Register HW_SJC_GPUSR1, field A_DBG[0] (RO)
 *
 * ARM core debug status bit Bit 0 is the ARM core DBGACK (debug acknowledge) DBGACK can be
 * overwritten in the ARM core DCR to force a particular DBGACK value. Consequently interpretation
 * of the DBGACK value is highly dependent on the debug sequence. When this bit is HIGH, ARM core is
 * in debug.
 */

#define BP_SJC_GPUSR1_A_DBG      (0)      //!< Bit position for SJC_GPUSR1_A_DBG.
#define BM_SJC_GPUSR1_A_DBG      (0x00000001)  //!< Bit mask for SJC_GPUSR1_A_DBG.

//! @brief Get value of SJC_GPUSR1_A_DBG from a register value.
#define BG_SJC_GPUSR1_A_DBG(r)   (((r) & BM_SJC_GPUSR1_A_DBG) >> BP_SJC_GPUSR1_A_DBG)

/* --- Register HW_SJC_GPUSR1, field A_WFI[1] (RO)
 *
 * ARM core wait-for interrupt bit Bit 1 is the ARM core standbywfi (stand by wait-for interrupt).
 * When this bit is HIGH, ARM core is in wait for interrupt mode.
 */

#define BP_SJC_GPUSR1_A_WFI      (1)      //!< Bit position for SJC_GPUSR1_A_WFI.
#define BM_SJC_GPUSR1_A_WFI      (0x00000002)  //!< Bit mask for SJC_GPUSR1_A_WFI.

//! @brief Get value of SJC_GPUSR1_A_WFI from a register value.
#define BG_SJC_GPUSR1_A_WFI(r)   (((r) & BM_SJC_GPUSR1_A_WFI) >> BP_SJC_GPUSR1_A_WFI)

/* --- Register HW_SJC_GPUSR1, field S_STAT[4:2] (RO)
 *
 * 3 LSBits of SDMA core statusH.
 */

#define BP_SJC_GPUSR1_S_STAT      (2)      //!< Bit position for SJC_GPUSR1_S_STAT.
#define BM_SJC_GPUSR1_S_STAT      (0x0000001c)  //!< Bit mask for SJC_GPUSR1_S_STAT.

//! @brief Get value of SJC_GPUSR1_S_STAT from a register value.
#define BG_SJC_GPUSR1_S_STAT(r)   (((r) & BM_SJC_GPUSR1_S_STAT) >> BP_SJC_GPUSR1_S_STAT)

/* --- Register HW_SJC_GPUSR1, field PLL_LOCK[8] (RO)
 *
 * PLL_LOCK A Combined PLL-Lock flag indicator, for all the PLL's.
 */

#define BP_SJC_GPUSR1_PLL_LOCK      (8)      //!< Bit position for SJC_GPUSR1_PLL_LOCK.
#define BM_SJC_GPUSR1_PLL_LOCK      (0x00000100)  //!< Bit mask for SJC_GPUSR1_PLL_LOCK.

//! @brief Get value of SJC_GPUSR1_PLL_LOCK from a register value.
#define BG_SJC_GPUSR1_PLL_LOCK(r)   (((r) & BM_SJC_GPUSR1_PLL_LOCK) >> BP_SJC_GPUSR1_PLL_LOCK)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUSR2 - General Purpose Unsecured Status Register 2 (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_gpusr2
{
    reg32_t U;
    struct _hw_sjc_gpusr2_bitfields
    {
        unsigned STBYWFI : 4; //!< [3:0] STBYWFI[3:0] These bits provide status of "Standby Wait-For-Interrupt" state of all ARM cores.
        unsigned S_STAT : 4; //!< [7:4] S_STAT[3:0] SDMA debug status bits: debug_core_state[3:0]
        unsigned STBYWFE : 4; //!< [11:8] STBYWFE[3:0] Reflecting the "Standby Wait For Event" signals of all cores.
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_sjc_gpusr2_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR2 register
 */
#define HW_SJC_GPUSR2_ADDR      (REGS_SJC_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR2           (*(volatile hw_sjc_gpusr2_t *) HW_SJC_GPUSR2_ADDR)
#define HW_SJC_GPUSR2_RD()      (HW_SJC_GPUSR2.U)
#endif

/*
 * constants & macros for individual SJC_GPUSR2 bitfields
 */

/* --- Register HW_SJC_GPUSR2, field STBYWFI[3:0] (RO)
 *
 * STBYWFI[3:0] These bits provide status of "Standby Wait-For-Interrupt" state of all ARM cores.
 */

#define BP_SJC_GPUSR2_STBYWFI      (0)      //!< Bit position for SJC_GPUSR2_STBYWFI.
#define BM_SJC_GPUSR2_STBYWFI      (0x0000000f)  //!< Bit mask for SJC_GPUSR2_STBYWFI.

//! @brief Get value of SJC_GPUSR2_STBYWFI from a register value.
#define BG_SJC_GPUSR2_STBYWFI(r)   (((r) & BM_SJC_GPUSR2_STBYWFI) >> BP_SJC_GPUSR2_STBYWFI)

/* --- Register HW_SJC_GPUSR2, field S_STAT[7:4] (RO)
 *
 * S_STAT[3:0] SDMA debug status bits: debug_core_state[3:0]
 */

#define BP_SJC_GPUSR2_S_STAT      (4)      //!< Bit position for SJC_GPUSR2_S_STAT.
#define BM_SJC_GPUSR2_S_STAT      (0x000000f0)  //!< Bit mask for SJC_GPUSR2_S_STAT.

//! @brief Get value of SJC_GPUSR2_S_STAT from a register value.
#define BG_SJC_GPUSR2_S_STAT(r)   (((r) & BM_SJC_GPUSR2_S_STAT) >> BP_SJC_GPUSR2_S_STAT)

/* --- Register HW_SJC_GPUSR2, field STBYWFE[11:8] (RO)
 *
 * STBYWFE[3:0] Reflecting the "Standby Wait For Event" signals of all cores.
 */

#define BP_SJC_GPUSR2_STBYWFE      (8)      //!< Bit position for SJC_GPUSR2_STBYWFE.
#define BM_SJC_GPUSR2_STBYWFE      (0x00000f00)  //!< Bit mask for SJC_GPUSR2_STBYWFE.

//! @brief Get value of SJC_GPUSR2_STBYWFE from a register value.
#define BG_SJC_GPUSR2_STBYWFE(r)   (((r) & BM_SJC_GPUSR2_STBYWFE) >> BP_SJC_GPUSR2_STBYWFE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUSR3 - General Purpose Unsecured Status Register 3 (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_gpusr3
{
    reg32_t U;
    struct _hw_sjc_gpusr3_bitfields
    {
        unsigned IPG_WAIT : 1; //!< [0] IPG_WAIT CCM's "ipg_wait" signal indication
        unsigned IPG_STOP : 1; //!< [1] IPG_STOP CCM's "ipg_stop" signal indication
        unsigned SYS_WAIT : 1; //!< [2] System In wait Indication on System in wait mode (from CCM).
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sjc_gpusr3_t;
#endif

/*
 * constants & macros for entire SJC_GPUSR3 register
 */
#define HW_SJC_GPUSR3_ADDR      (REGS_SJC_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUSR3           (*(volatile hw_sjc_gpusr3_t *) HW_SJC_GPUSR3_ADDR)
#define HW_SJC_GPUSR3_RD()      (HW_SJC_GPUSR3.U)
#endif

/*
 * constants & macros for individual SJC_GPUSR3 bitfields
 */

/* --- Register HW_SJC_GPUSR3, field IPG_WAIT[0] (RO)
 *
 * IPG_WAIT CCM's "ipg_wait" signal indication
 */

#define BP_SJC_GPUSR3_IPG_WAIT      (0)      //!< Bit position for SJC_GPUSR3_IPG_WAIT.
#define BM_SJC_GPUSR3_IPG_WAIT      (0x00000001)  //!< Bit mask for SJC_GPUSR3_IPG_WAIT.

//! @brief Get value of SJC_GPUSR3_IPG_WAIT from a register value.
#define BG_SJC_GPUSR3_IPG_WAIT(r)   (((r) & BM_SJC_GPUSR3_IPG_WAIT) >> BP_SJC_GPUSR3_IPG_WAIT)

/* --- Register HW_SJC_GPUSR3, field IPG_STOP[1] (RO)
 *
 * IPG_STOP CCM's "ipg_stop" signal indication
 */

#define BP_SJC_GPUSR3_IPG_STOP      (1)      //!< Bit position for SJC_GPUSR3_IPG_STOP.
#define BM_SJC_GPUSR3_IPG_STOP      (0x00000002)  //!< Bit mask for SJC_GPUSR3_IPG_STOP.

//! @brief Get value of SJC_GPUSR3_IPG_STOP from a register value.
#define BG_SJC_GPUSR3_IPG_STOP(r)   (((r) & BM_SJC_GPUSR3_IPG_STOP) >> BP_SJC_GPUSR3_IPG_STOP)

/* --- Register HW_SJC_GPUSR3, field SYS_WAIT[2] (RO)
 *
 * System In wait Indication on System in wait mode (from CCM).
 */

#define BP_SJC_GPUSR3_SYS_WAIT      (2)      //!< Bit position for SJC_GPUSR3_SYS_WAIT.
#define BM_SJC_GPUSR3_SYS_WAIT      (0x00000004)  //!< Bit mask for SJC_GPUSR3_SYS_WAIT.

//! @brief Get value of SJC_GPUSR3_SYS_WAIT from a register value.
#define BG_SJC_GPUSR3_SYS_WAIT(r)   (((r) & BM_SJC_GPUSR3_SYS_WAIT) >> BP_SJC_GPUSR3_SYS_WAIT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPSSR - General Purpose Secured Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The General Purpose Secured Status Register is a read-only register used to check the status of
 * the different critical information in the SoC. This register cannot be accessed in secure modes.
 */
typedef union _hw_sjc_gpssr
{
    reg32_t U;
    struct _hw_sjc_gpssr_bitfields
    {
        unsigned GPSSR : 32; //!< [31:0] General Purpose Secured Status Register Register is used for testing and debug.
    } B;
} hw_sjc_gpssr_t;
#endif

/*
 * constants & macros for entire SJC_GPSSR register
 */
#define HW_SJC_GPSSR_ADDR      (REGS_SJC_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPSSR           (*(volatile hw_sjc_gpssr_t *) HW_SJC_GPSSR_ADDR)
#define HW_SJC_GPSSR_RD()      (HW_SJC_GPSSR.U)
#endif

/*
 * constants & macros for individual SJC_GPSSR bitfields
 */

/* --- Register HW_SJC_GPSSR, field GPSSR[31:0] (RO)
 *
 * General Purpose Secured Status Register Register is used for testing and debug.
 */

#define BP_SJC_GPSSR_GPSSR      (0)      //!< Bit position for SJC_GPSSR_GPSSR.
#define BM_SJC_GPSSR_GPSSR      (0xffffffff)  //!< Bit mask for SJC_GPSSR_GPSSR.

//! @brief Get value of SJC_GPSSR_GPSSR from a register value.
#define BG_SJC_GPSSR_GPSSR(r)   (((r) & BM_SJC_GPSSR_GPSSR) >> BP_SJC_GPSSR_GPSSR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_DCR - Debug Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to control propagation of debug request from DE_B pad to the cores and
 * debug signals from internal logic to the DE_B pad.
 */
typedef union _hw_sjc_dcr
{
    reg32_t U;
    struct _hw_sjc_dcr_bitfields
    {
        unsigned DE_TO_ARM : 1; //!< [0] ARM platform debug request input propagation This bit controls the propagation of debug request to ARM platform ("dbgreq"), when the JTAG state machine is put in "ENTER_DEBUG" IR instruction.
        unsigned DE_TO_SDMA : 1; //!< [1] SDMA debug request input propagation This bit controls the propagation of debug request to SDMA, when the JTAG state machine is put in "ENTER_DEBUG" IR instruction..
        unsigned RESERVED0 : 1; //!< [2] Reserved
        unsigned DEBUG_OBS : 1; //!< [3] Debug observability This bit controls the propagation of the "system debug" input to SJC For i.MX 6x, the SJC's "system_debug" input is tied to logic HIGH value, therefore, set of "debug_obs" bit, will result in unconditional assertion of DE_B pad.
        unsigned RESERVED1 : 1; //!< [4] Reserved
        unsigned DIRECT_SDMA_REQ_EN : 1; //!< [5] Debug enable of the sdma debug request This bit controls the propagation of debug request DE_B to the sdma.
        unsigned DIRECT_ARM_REQ_EN : 1; //!< [6] Pass Debug Enable event from DE_B pin to ARM platform debug request signal(s). This bit controls the propagation of debug request DE_B to the Arm platform.
        unsigned RESERVED2 : 25; //!< [31:7] Reserved
    } B;
} hw_sjc_dcr_t;
#endif

/*
 * constants & macros for entire SJC_DCR register
 */
#define HW_SJC_DCR_ADDR      (REGS_SJC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_DCR           (*(volatile hw_sjc_dcr_t *) HW_SJC_DCR_ADDR)
#define HW_SJC_DCR_RD()      (HW_SJC_DCR.U)
#define HW_SJC_DCR_WR(v)     (HW_SJC_DCR.U = (v))
#define HW_SJC_DCR_SET(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() |  (v)))
#define HW_SJC_DCR_CLR(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() & ~(v)))
#define HW_SJC_DCR_TOG(v)    (HW_SJC_DCR_WR(HW_SJC_DCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_DCR bitfields
 */

/* --- Register HW_SJC_DCR, field DE_TO_ARM[0] (RW)
 *
 * ARM platform debug request input propagation This bit controls the propagation of debug request
 * to ARM platform ("dbgreq"), when the JTAG state machine is put in "ENTER_DEBUG" IR instruction.
 *
 * Values:
 * 0 - Disable propagation of debug request to ARM platform
 * 1 - Enable propagation of debug request to ARM platform
 */

#define BP_SJC_DCR_DE_TO_ARM      (0)      //!< Bit position for SJC_DCR_DE_TO_ARM.
#define BM_SJC_DCR_DE_TO_ARM      (0x00000001)  //!< Bit mask for SJC_DCR_DE_TO_ARM.

//! @brief Get value of SJC_DCR_DE_TO_ARM from a register value.
#define BG_SJC_DCR_DE_TO_ARM(r)   (((r) & BM_SJC_DCR_DE_TO_ARM) >> BP_SJC_DCR_DE_TO_ARM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_DCR_DE_TO_ARM.
#define BF_SJC_DCR_DE_TO_ARM(v)   ((((reg32_t) v) << BP_SJC_DCR_DE_TO_ARM) & BM_SJC_DCR_DE_TO_ARM)
#else
//! @brief Format value for bitfield SJC_DCR_DE_TO_ARM.
#define BF_SJC_DCR_DE_TO_ARM(v)   (((v) << BP_SJC_DCR_DE_TO_ARM) & BM_SJC_DCR_DE_TO_ARM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DE_TO_ARM field to a new value.
#define BW_SJC_DCR_DE_TO_ARM(v)   (HW_SJC_DCR_WR((HW_SJC_DCR_RD() & ~BM_SJC_DCR_DE_TO_ARM) | BF_SJC_DCR_DE_TO_ARM(v)))
#endif


/* --- Register HW_SJC_DCR, field DE_TO_SDMA[1] (RW)
 *
 * SDMA debug request input propagation This bit controls the propagation of debug request to SDMA,
 * when the JTAG state machine is put in "ENTER_DEBUG" IR instruction..
 *
 * Values:
 * 0 - Disable propagation of debug request to SDMA
 * 1 - Enable propagation of debug request to SDMA
 */

#define BP_SJC_DCR_DE_TO_SDMA      (1)      //!< Bit position for SJC_DCR_DE_TO_SDMA.
#define BM_SJC_DCR_DE_TO_SDMA      (0x00000002)  //!< Bit mask for SJC_DCR_DE_TO_SDMA.

//! @brief Get value of SJC_DCR_DE_TO_SDMA from a register value.
#define BG_SJC_DCR_DE_TO_SDMA(r)   (((r) & BM_SJC_DCR_DE_TO_SDMA) >> BP_SJC_DCR_DE_TO_SDMA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_DCR_DE_TO_SDMA.
#define BF_SJC_DCR_DE_TO_SDMA(v)   ((((reg32_t) v) << BP_SJC_DCR_DE_TO_SDMA) & BM_SJC_DCR_DE_TO_SDMA)
#else
//! @brief Format value for bitfield SJC_DCR_DE_TO_SDMA.
#define BF_SJC_DCR_DE_TO_SDMA(v)   (((v) << BP_SJC_DCR_DE_TO_SDMA) & BM_SJC_DCR_DE_TO_SDMA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DE_TO_SDMA field to a new value.
#define BW_SJC_DCR_DE_TO_SDMA(v)   (HW_SJC_DCR_WR((HW_SJC_DCR_RD() & ~BM_SJC_DCR_DE_TO_SDMA) | BF_SJC_DCR_DE_TO_SDMA(v)))
#endif


/* --- Register HW_SJC_DCR, field DEBUG_OBS[3] (RW)
 *
 * Debug observability This bit controls the propagation of the "system debug" input to SJC For i.MX
 * 6x, the SJC's "system_debug" input is tied to logic HIGH value, therefore, set of "debug_obs"
 * bit, will result in unconditional assertion of DE_B pad.
 *
 * Values:
 * 0 - Disable propagation of system debug to DE pin
 * 1 - unconditional assertion of pad. DE_B
 */

#define BP_SJC_DCR_DEBUG_OBS      (3)      //!< Bit position for SJC_DCR_DEBUG_OBS.
#define BM_SJC_DCR_DEBUG_OBS      (0x00000008)  //!< Bit mask for SJC_DCR_DEBUG_OBS.

//! @brief Get value of SJC_DCR_DEBUG_OBS from a register value.
#define BG_SJC_DCR_DEBUG_OBS(r)   (((r) & BM_SJC_DCR_DEBUG_OBS) >> BP_SJC_DCR_DEBUG_OBS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_DCR_DEBUG_OBS.
#define BF_SJC_DCR_DEBUG_OBS(v)   ((((reg32_t) v) << BP_SJC_DCR_DEBUG_OBS) & BM_SJC_DCR_DEBUG_OBS)
#else
//! @brief Format value for bitfield SJC_DCR_DEBUG_OBS.
#define BF_SJC_DCR_DEBUG_OBS(v)   (((v) << BP_SJC_DCR_DEBUG_OBS) & BM_SJC_DCR_DEBUG_OBS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_OBS field to a new value.
#define BW_SJC_DCR_DEBUG_OBS(v)   (HW_SJC_DCR_WR((HW_SJC_DCR_RD() & ~BM_SJC_DCR_DEBUG_OBS) | BF_SJC_DCR_DEBUG_OBS(v)))
#endif


/* --- Register HW_SJC_DCR, field DIRECT_SDMA_REQ_EN[5] (RW)
 *
 * Debug enable of the sdma debug request This bit controls the propagation of debug request DE_B to
 * the sdma.
 *
 * Values:
 * 0 - Disable propagation of system debug to (DE pin) to sdma.
 * 1 - Enable propagation of system debug to (DE pin) to sdma.
 */

#define BP_SJC_DCR_DIRECT_SDMA_REQ_EN      (5)      //!< Bit position for SJC_DCR_DIRECT_SDMA_REQ_EN.
#define BM_SJC_DCR_DIRECT_SDMA_REQ_EN      (0x00000020)  //!< Bit mask for SJC_DCR_DIRECT_SDMA_REQ_EN.

//! @brief Get value of SJC_DCR_DIRECT_SDMA_REQ_EN from a register value.
#define BG_SJC_DCR_DIRECT_SDMA_REQ_EN(r)   (((r) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN) >> BP_SJC_DCR_DIRECT_SDMA_REQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_DCR_DIRECT_SDMA_REQ_EN.
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   ((((reg32_t) v) << BP_SJC_DCR_DIRECT_SDMA_REQ_EN) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#else
//! @brief Format value for bitfield SJC_DCR_DIRECT_SDMA_REQ_EN.
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   (((v) << BP_SJC_DCR_DIRECT_SDMA_REQ_EN) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIRECT_SDMA_REQ_EN field to a new value.
#define BW_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   (HW_SJC_DCR_WR((HW_SJC_DCR_RD() & ~BM_SJC_DCR_DIRECT_SDMA_REQ_EN) | BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)))
#endif


/* --- Register HW_SJC_DCR, field DIRECT_ARM_REQ_EN[6] (RW)
 *
 * Pass Debug Enable event from DE_B pin to ARM platform debug request signal(s). This bit controls
 * the propagation of debug request DE_B to the Arm platform.
 *
 * Values:
 * 0 - Disable propagation of system debug to (DE pin) to Arm platform.
 * 1 - Enable propagation of system debug to (DE pin) to Arm platform.
 */

#define BP_SJC_DCR_DIRECT_ARM_REQ_EN      (6)      //!< Bit position for SJC_DCR_DIRECT_ARM_REQ_EN.
#define BM_SJC_DCR_DIRECT_ARM_REQ_EN      (0x00000040)  //!< Bit mask for SJC_DCR_DIRECT_ARM_REQ_EN.

//! @brief Get value of SJC_DCR_DIRECT_ARM_REQ_EN from a register value.
#define BG_SJC_DCR_DIRECT_ARM_REQ_EN(r)   (((r) & BM_SJC_DCR_DIRECT_ARM_REQ_EN) >> BP_SJC_DCR_DIRECT_ARM_REQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_DCR_DIRECT_ARM_REQ_EN.
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   ((((reg32_t) v) << BP_SJC_DCR_DIRECT_ARM_REQ_EN) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#else
//! @brief Format value for bitfield SJC_DCR_DIRECT_ARM_REQ_EN.
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   (((v) << BP_SJC_DCR_DIRECT_ARM_REQ_EN) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIRECT_ARM_REQ_EN field to a new value.
#define BW_SJC_DCR_DIRECT_ARM_REQ_EN(v)   (HW_SJC_DCR_WR((HW_SJC_DCR_RD() & ~BM_SJC_DCR_DIRECT_ARM_REQ_EN) | BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_SSR - Security Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_ssr
{
    reg32_t U;
    struct _hw_sjc_ssr_bitfields
    {
        unsigned KTF : 1; //!< [0] Kill Trace Enable fuse value
        unsigned KTA : 1; //!< [1] Kill Trace is active
        unsigned SWF : 1; //!< [2] Software JTAG enable fuse Status of the no SW disable JTAG fuse
        unsigned SWE : 1; //!< [3] SW enable SW JTAG enable status
        unsigned EBF : 1; //!< [4] External Boot fuse Status of the external boot disable fuse
        unsigned EBG : 1; //!< [5] External boot granted External boot enabled, requested and granted
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned FT : 1; //!< [8] Fuse type Fuse type bit - e-fuse or laser fuse
        unsigned SJM : 2; //!< [10:9] SJC Secure mode Secure JTAG mode, as set by external fuses. These bits do not reflect the change due to burn of Bypass Secure JTAG fuse.
        unsigned RSSTAT : 2; //!< [12:11] Response status Response status bits
        unsigned RESERVED1 : 1; //!< [13] Reserved
        unsigned BOOTIND : 1; //!< [14] Boot Indication Inverted Internal Boot indication, i.e inverse of SRC: "src_int_boot" signal
        unsigned RESERVED2 : 17; //!< [31:15] Reserved.
    } B;
} hw_sjc_ssr_t;
#endif

/*
 * constants & macros for entire SJC_SSR register
 */
#define HW_SJC_SSR_ADDR      (REGS_SJC_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_SSR           (*(volatile hw_sjc_ssr_t *) HW_SJC_SSR_ADDR)
#define HW_SJC_SSR_RD()      (HW_SJC_SSR.U)
#endif

/*
 * constants & macros for individual SJC_SSR bitfields
 */

/* --- Register HW_SJC_SSR, field KTF[0] (RO)
 *
 * Kill Trace Enable fuse value
 *
 * Values:
 * 0 - (intact) - kill trace is never active
 * 1 - (burned) - kill trace functionality enabled
 */

#define BP_SJC_SSR_KTF      (0)      //!< Bit position for SJC_SSR_KTF.
#define BM_SJC_SSR_KTF      (0x00000001)  //!< Bit mask for SJC_SSR_KTF.

//! @brief Get value of SJC_SSR_KTF from a register value.
#define BG_SJC_SSR_KTF(r)   (((r) & BM_SJC_SSR_KTF) >> BP_SJC_SSR_KTF)


/* --- Register HW_SJC_SSR, field KTA[1] (RO)
 *
 * Kill Trace is active
 *
 * Values:
 * 0 - not active
 * 1 - active
 */

#define BP_SJC_SSR_KTA      (1)      //!< Bit position for SJC_SSR_KTA.
#define BM_SJC_SSR_KTA      (0x00000002)  //!< Bit mask for SJC_SSR_KTA.

//! @brief Get value of SJC_SSR_KTA from a register value.
#define BG_SJC_SSR_KTA(r)   (((r) & BM_SJC_SSR_KTA) >> BP_SJC_SSR_KTA)


/* --- Register HW_SJC_SSR, field SWF[2] (RO)
 *
 * Software JTAG enable fuse Status of the no SW disable JTAG fuse
 *
 * Values:
 * 0 - (intact) - SW enable possible
 * 1 - (intact) - no SW enable possible
 */

#define BP_SJC_SSR_SWF      (2)      //!< Bit position for SJC_SSR_SWF.
#define BM_SJC_SSR_SWF      (0x00000004)  //!< Bit mask for SJC_SSR_SWF.

//! @brief Get value of SJC_SSR_SWF from a register value.
#define BG_SJC_SSR_SWF(r)   (((r) & BM_SJC_SSR_SWF) >> BP_SJC_SSR_SWF)


/* --- Register HW_SJC_SSR, field SWE[3] (RO)
 *
 * SW enable SW JTAG enable status
 *
 * Values:
 * 0 - disabled
 * 1 - enabled
 */

#define BP_SJC_SSR_SWE      (3)      //!< Bit position for SJC_SSR_SWE.
#define BM_SJC_SSR_SWE      (0x00000008)  //!< Bit mask for SJC_SSR_SWE.

//! @brief Get value of SJC_SSR_SWE from a register value.
#define BG_SJC_SSR_SWE(r)   (((r) & BM_SJC_SSR_SWE) >> BP_SJC_SSR_SWE)


/* --- Register HW_SJC_SSR, field EBF[4] (RO)
 *
 * External Boot fuse Status of the external boot disable fuse
 *
 * Values:
 * 0 - (intact) - external boot is allowed
 * 1 - (burned) - external boot is disabled
 */

#define BP_SJC_SSR_EBF      (4)      //!< Bit position for SJC_SSR_EBF.
#define BM_SJC_SSR_EBF      (0x00000010)  //!< Bit mask for SJC_SSR_EBF.

//! @brief Get value of SJC_SSR_EBF from a register value.
#define BG_SJC_SSR_EBF(r)   (((r) & BM_SJC_SSR_EBF) >> BP_SJC_SSR_EBF)


/* --- Register HW_SJC_SSR, field EBG[5] (RO)
 *
 * External boot granted External boot enabled, requested and granted
 *
 * Values:
 * 0 - not granted
 * 1 - granted
 */

#define BP_SJC_SSR_EBG      (5)      //!< Bit position for SJC_SSR_EBG.
#define BM_SJC_SSR_EBG      (0x00000020)  //!< Bit mask for SJC_SSR_EBG.

//! @brief Get value of SJC_SSR_EBG from a register value.
#define BG_SJC_SSR_EBG(r)   (((r) & BM_SJC_SSR_EBG) >> BP_SJC_SSR_EBG)


/* --- Register HW_SJC_SSR, field FT[8] (RO)
 *
 * Fuse type Fuse type bit - e-fuse or laser fuse
 *
 * Values:
 * 0 - E-fuse technology
 * 1 - Laser fuse technology
 */

#define BP_SJC_SSR_FT      (8)      //!< Bit position for SJC_SSR_FT.
#define BM_SJC_SSR_FT      (0x00000100)  //!< Bit mask for SJC_SSR_FT.

//! @brief Get value of SJC_SSR_FT from a register value.
#define BG_SJC_SSR_FT(r)   (((r) & BM_SJC_SSR_FT) >> BP_SJC_SSR_FT)


/* --- Register HW_SJC_SSR, field SJM[10:9] (RO)
 *
 * SJC Secure mode Secure JTAG mode, as set by external fuses. These bits do not reflect the change
 * due to burn of Bypass Secure JTAG fuse.
 *
 * Values:
 * 00 - No debug (#1)
 * 01 - Secure JTAG (#2)
 * 10 - JTAG enabled (#3)
 * 11 - Reserved
 */

#define BP_SJC_SSR_SJM      (9)      //!< Bit position for SJC_SSR_SJM.
#define BM_SJC_SSR_SJM      (0x00000600)  //!< Bit mask for SJC_SSR_SJM.

//! @brief Get value of SJC_SSR_SJM from a register value.
#define BG_SJC_SSR_SJM(r)   (((r) & BM_SJC_SSR_SJM) >> BP_SJC_SSR_SJM)


/* --- Register HW_SJC_SSR, field RSSTAT[12:11] (RO)
 *
 * Response status Response status bits
 *
 * Values:
 * 00 - Response wasn't entered
 * 01 - Response was entered but not verified
 * 10 - Response was entered and is incorrect
 * 11 - Response is correct
 */

#define BP_SJC_SSR_RSSTAT      (11)      //!< Bit position for SJC_SSR_RSSTAT.
#define BM_SJC_SSR_RSSTAT      (0x00001800)  //!< Bit mask for SJC_SSR_RSSTAT.

//! @brief Get value of SJC_SSR_RSSTAT from a register value.
#define BG_SJC_SSR_RSSTAT(r)   (((r) & BM_SJC_SSR_RSSTAT) >> BP_SJC_SSR_RSSTAT)


/* --- Register HW_SJC_SSR, field BOOTIND[14] (RO)
 *
 * Boot Indication Inverted Internal Boot indication, i.e inverse of SRC: "src_int_boot" signal
 */

#define BP_SJC_SSR_BOOTIND      (14)      //!< Bit position for SJC_SSR_BOOTIND.
#define BM_SJC_SSR_BOOTIND      (0x00004000)  //!< Bit mask for SJC_SSR_BOOTIND.

//! @brief Get value of SJC_SSR_BOOTIND from a register value.
#define BG_SJC_SSR_BOOTIND(r)   (((r) & BM_SJC_SSR_BOOTIND) >> BP_SJC_SSR_BOOTIND)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPCCR - General Purpose Clocks Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to configure clock related modes in SOC, see System Configuration chapter
 * for more information. Those bits are directly connected to JTAG outputs. Bit 0 of GPCCR controls
 * SDMA clocks invocation. When out of reset, the SDMA is in sleep mode with no SDMA clock running.
 * Unlike events, debug requests does not wake SDMA if it is in sleep mode. The debug request is
 * recognized by the SDMA only when it exits sleep mode upon reception of an event. To be able to
 * enter debug mode even if no event is triggered, the SDMA clock on bit needs to be set prior to
 * sending the debug request (clear at reset).
 */
typedef union _hw_sjc_gpccr
{
    reg32_t U;
    struct _hw_sjc_gpccr_bitfields
    {
        unsigned SCLKR : 1; //!< [0] SDMA Clock ON Register - This bit forces the clock on of the SDMA
        unsigned ACLKOFFDIS : 1; //!< [1] Disable/prevent ARM platform clock/power shutdown
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_sjc_gpccr_t;
#endif

/*
 * constants & macros for entire SJC_GPCCR register
 */
#define HW_SJC_GPCCR_ADDR      (REGS_SJC_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPCCR           (*(volatile hw_sjc_gpccr_t *) HW_SJC_GPCCR_ADDR)
#define HW_SJC_GPCCR_RD()      (HW_SJC_GPCCR.U)
#define HW_SJC_GPCCR_WR(v)     (HW_SJC_GPCCR.U = (v))
#define HW_SJC_GPCCR_SET(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() |  (v)))
#define HW_SJC_GPCCR_CLR(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() & ~(v)))
#define HW_SJC_GPCCR_TOG(v)    (HW_SJC_GPCCR_WR(HW_SJC_GPCCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_GPCCR bitfields
 */

/* --- Register HW_SJC_GPCCR, field SCLKR[0] (RW)
 *
 * SDMA Clock ON Register - This bit forces the clock on of the SDMA
 */

#define BP_SJC_GPCCR_SCLKR      (0)      //!< Bit position for SJC_GPCCR_SCLKR.
#define BM_SJC_GPCCR_SCLKR      (0x00000001)  //!< Bit mask for SJC_GPCCR_SCLKR.

//! @brief Get value of SJC_GPCCR_SCLKR from a register value.
#define BG_SJC_GPCCR_SCLKR(r)   (((r) & BM_SJC_GPCCR_SCLKR) >> BP_SJC_GPCCR_SCLKR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_GPCCR_SCLKR.
#define BF_SJC_GPCCR_SCLKR(v)   ((((reg32_t) v) << BP_SJC_GPCCR_SCLKR) & BM_SJC_GPCCR_SCLKR)
#else
//! @brief Format value for bitfield SJC_GPCCR_SCLKR.
#define BF_SJC_GPCCR_SCLKR(v)   (((v) << BP_SJC_GPCCR_SCLKR) & BM_SJC_GPCCR_SCLKR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCLKR field to a new value.
#define BW_SJC_GPCCR_SCLKR(v)   (HW_SJC_GPCCR_WR((HW_SJC_GPCCR_RD() & ~BM_SJC_GPCCR_SCLKR) | BF_SJC_GPCCR_SCLKR(v)))
#endif

/* --- Register HW_SJC_GPCCR, field ACLKOFFDIS[1] (RW)
 *
 * Disable/prevent ARM platform clock/power shutdown
 */

#define BP_SJC_GPCCR_ACLKOFFDIS      (1)      //!< Bit position for SJC_GPCCR_ACLKOFFDIS.
#define BM_SJC_GPCCR_ACLKOFFDIS      (0x00000002)  //!< Bit mask for SJC_GPCCR_ACLKOFFDIS.

//! @brief Get value of SJC_GPCCR_ACLKOFFDIS from a register value.
#define BG_SJC_GPCCR_ACLKOFFDIS(r)   (((r) & BM_SJC_GPCCR_ACLKOFFDIS) >> BP_SJC_GPCCR_ACLKOFFDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SJC_GPCCR_ACLKOFFDIS.
#define BF_SJC_GPCCR_ACLKOFFDIS(v)   ((((reg32_t) v) << BP_SJC_GPCCR_ACLKOFFDIS) & BM_SJC_GPCCR_ACLKOFFDIS)
#else
//! @brief Format value for bitfield SJC_GPCCR_ACLKOFFDIS.
#define BF_SJC_GPCCR_ACLKOFFDIS(v)   (((v) << BP_SJC_GPCCR_ACLKOFFDIS) & BM_SJC_GPCCR_ACLKOFFDIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLKOFFDIS field to a new value.
#define BW_SJC_GPCCR_ACLKOFFDIS(v)   (HW_SJC_GPCCR_WR((HW_SJC_GPCCR_RD() & ~BM_SJC_GPCCR_ACLKOFFDIS) | BF_SJC_GPCCR_ACLKOFFDIS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUCR1 - General Purpose Unsecured Control Register n (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_gpucr1
{
    reg32_t U;
    struct _hw_sjc_gpucr1_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_sjc_gpucr1_t;
#endif

/*
 * constants & macros for entire SJC_GPUCR1 register
 */
#define HW_SJC_GPUCR1_ADDR      (REGS_SJC_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUCR1           (*(volatile hw_sjc_gpucr1_t *) HW_SJC_GPUCR1_ADDR)
#define HW_SJC_GPUCR1_RD()      (HW_SJC_GPUCR1.U)
#define HW_SJC_GPUCR1_WR(v)     (HW_SJC_GPUCR1.U = (v))
#define HW_SJC_GPUCR1_SET(v)    (HW_SJC_GPUCR1_WR(HW_SJC_GPUCR1_RD() |  (v)))
#define HW_SJC_GPUCR1_CLR(v)    (HW_SJC_GPUCR1_WR(HW_SJC_GPUCR1_RD() & ~(v)))
#define HW_SJC_GPUCR1_TOG(v)    (HW_SJC_GPUCR1_WR(HW_SJC_GPUCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_GPUCR1 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUCR2 - General Purpose Unsecured Control Register n (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_gpucr2
{
    reg32_t U;
    struct _hw_sjc_gpucr2_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_sjc_gpucr2_t;
#endif

/*
 * constants & macros for entire SJC_GPUCR2 register
 */
#define HW_SJC_GPUCR2_ADDR      (REGS_SJC_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUCR2           (*(volatile hw_sjc_gpucr2_t *) HW_SJC_GPUCR2_ADDR)
#define HW_SJC_GPUCR2_RD()      (HW_SJC_GPUCR2.U)
#define HW_SJC_GPUCR2_WR(v)     (HW_SJC_GPUCR2.U = (v))
#define HW_SJC_GPUCR2_SET(v)    (HW_SJC_GPUCR2_WR(HW_SJC_GPUCR2_RD() |  (v)))
#define HW_SJC_GPUCR2_CLR(v)    (HW_SJC_GPUCR2_WR(HW_SJC_GPUCR2_RD() & ~(v)))
#define HW_SJC_GPUCR2_TOG(v)    (HW_SJC_GPUCR2_WR(HW_SJC_GPUCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_GPUCR2 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPUCR3 - General Purpose Unsecured Control Register n (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sjc_gpucr3
{
    reg32_t U;
    struct _hw_sjc_gpucr3_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_sjc_gpucr3_t;
#endif

/*
 * constants & macros for entire SJC_GPUCR3 register
 */
#define HW_SJC_GPUCR3_ADDR      (REGS_SJC_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUCR3           (*(volatile hw_sjc_gpucr3_t *) HW_SJC_GPUCR3_ADDR)
#define HW_SJC_GPUCR3_RD()      (HW_SJC_GPUCR3.U)
#define HW_SJC_GPUCR3_WR(v)     (HW_SJC_GPUCR3.U = (v))
#define HW_SJC_GPUCR3_SET(v)    (HW_SJC_GPUCR3_WR(HW_SJC_GPUCR3_RD() |  (v)))
#define HW_SJC_GPUCR3_CLR(v)    (HW_SJC_GPUCR3_WR(HW_SJC_GPUCR3_RD() & ~(v)))
#define HW_SJC_GPUCR3_TOG(v)    (HW_SJC_GPUCR3_WR(HW_SJC_GPUCR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_GPUCR3 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SJC_GPSCR - General Purpose Secured Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to configure JTAG for special test or debug modes. This register is secured
 * (accessible in secure jtag mode #3, #4 and #2 with response entered). Those bits are directly
 * connected to SJC outputs.
 */
typedef union _hw_sjc_gpscr
{
    reg32_t U;
    struct _hw_sjc_gpscr_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_sjc_gpscr_t;
#endif

/*
 * constants & macros for entire SJC_GPSCR register
 */
#define HW_SJC_GPSCR_ADDR      (REGS_SJC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPSCR           (*(volatile hw_sjc_gpscr_t *) HW_SJC_GPSCR_ADDR)
#define HW_SJC_GPSCR_RD()      (HW_SJC_GPSCR.U)
#define HW_SJC_GPSCR_WR(v)     (HW_SJC_GPSCR.U = (v))
#define HW_SJC_GPSCR_SET(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() |  (v)))
#define HW_SJC_GPSCR_CLR(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() & ~(v)))
#define HW_SJC_GPSCR_TOG(v)    (HW_SJC_GPSCR_WR(HW_SJC_GPSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SJC_GPSCR bitfields
 */


/*!
 * @brief All SJC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_sjc
{
    volatile hw_sjc_gpusr1_t GPUSR1; //!< General Purpose Unsecured Status Register 1
    volatile hw_sjc_gpusr2_t GPUSR2; //!< General Purpose Unsecured Status Register 2
    volatile hw_sjc_gpusr3_t GPUSR3; //!< General Purpose Unsecured Status Register 3
    volatile hw_sjc_gpssr_t GPSSR; //!< General Purpose Secured Status Register
    volatile hw_sjc_dcr_t DCR; //!< Debug Control Register
    volatile hw_sjc_ssr_t SSR; //!< Security Status Register
    volatile hw_sjc_gpccr_t GPCCR; //!< General Purpose Clocks Control Register
    volatile hw_sjc_gpucr1_t GPUCR1; //!< General Purpose Unsecured Control Register n
    volatile hw_sjc_gpucr2_t GPUCR2; //!< General Purpose Unsecured Control Register n
    volatile hw_sjc_gpucr3_t GPUCR3; //!< General Purpose Unsecured Control Register n
    volatile hw_sjc_gpscr_t GPSCR; //!< General Purpose Secured Control Register
} hw_sjc_t;
#pragma pack()

//! @brief Macro to access all SJC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SJC(0)</code>.
#define HW_SJC     (*(volatile hw_sjc_t *) REGS_SJC_BASE)

#endif


#endif // __HW_SJC_REGISTERS_H__
