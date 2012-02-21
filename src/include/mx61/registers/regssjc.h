/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SJC_H
#define _SJC_H

#include "regs.h"

#ifndef REGS_SJC_BASE
#define REGS_SJC_BASE (REGS_BASE + 0x00000000)
#endif


/*!
 * @brief HW_SJC_GPUSR1 - General Purpose Unsecured Status Register 1
 *
 * The General Purpose Unsecured Status Register 1 is a read only registers
 * used to check the status of the different Cores and of the PLL. The rest
 * of its bits are for general purpose use.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned A_DBG : 1; //!< ARM core debug status bit  Bit 0 is the ARM core DBGACK (debug acknowledge)  DBGACK can be overwritten in the ARM core DCR to force a particular DBGACK value. Consequently interpretation of the DBGACK value is highly dependent on the debug sequence. When this bit is HIGH, ARM core is in debug.
        unsigned A_WFI : 1; //!< ARM core wait-for interrupt bit  Bit 1 is the ARM core standbywfi (stand by wait-for interrupt). When this bit is HIGH, ARM core is in wait for interrupt mode.
        unsigned S_STAT : 3; //!< 3 LSBits of SDMA core statusH.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PLL_LOCK : 1; //!< PLL_LOCK  A Combined PLL-Lock flag indicator, for all the PLL's.
        unsigned RESERVED2 : 23; //!< Reserved.
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
#define HW_SJC_GPUSR1_WR(v)     (HW_SJC_GPUSR1.U = (v))
#define HW_SJC_GPUSR1_SET(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() |  (v)))
#define HW_SJC_GPUSR1_CLR(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() & ~(v)))
#define HW_SJC_GPUSR1_TOG(v)    (HW_SJC_GPUSR1_WR(HW_SJC_GPUSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR1 bitfields
 */

/* --- Register HW_SJC_GPUSR1, field A_DBG
 *
 * ARM core debug status bit  Bit 0 is the ARM core DBGACK (debug acknowledge)  DBGACK can be
 * overwritten in the ARM core DCR to force a particular                                 DBGACK
 * value. Consequently interpretation of the DBGACK value is                                 highly
 * dependent on the debug sequence. When this bit is HIGH, ARM                                 core
 * is in debug.
 */

#define BP_SJC_GPUSR1_A_DBG      0
#define BM_SJC_GPUSR1_A_DBG      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_A_DBG(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR1_A_DBG)
#else
#define BF_SJC_GPUSR1_A_DBG(v)   (((v) << 0) & BM_SJC_GPUSR1_A_DBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_A_DBG(v)   BF_CS1(SJC_GPUSR1, A_DBG, v)
#endif

/* --- Register HW_SJC_GPUSR1, field A_WFI
 *
 * ARM core wait-for interrupt bit  Bit 1 is the ARM core standbywfi (stand by wait-for interrupt).
 * When                                 this bit is HIGH, ARM core is in wait for interrupt mode.
 */

#define BP_SJC_GPUSR1_A_WFI      1
#define BM_SJC_GPUSR1_A_WFI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_A_WFI(v)   ((((reg32_t) v) << 1) & BM_SJC_GPUSR1_A_WFI)
#else
#define BF_SJC_GPUSR1_A_WFI(v)   (((v) << 1) & BM_SJC_GPUSR1_A_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_A_WFI(v)   BF_CS1(SJC_GPUSR1, A_WFI, v)
#endif

/* --- Register HW_SJC_GPUSR1, field S_STAT
 *
 * 3 LSBits of SDMA core statusH.
 */

#define BP_SJC_GPUSR1_S_STAT      2
#define BM_SJC_GPUSR1_S_STAT      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_S_STAT(v)   ((((reg32_t) v) << 2) & BM_SJC_GPUSR1_S_STAT)
#else
#define BF_SJC_GPUSR1_S_STAT(v)   (((v) << 2) & BM_SJC_GPUSR1_S_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_S_STAT(v)   BF_CS1(SJC_GPUSR1, S_STAT, v)
#endif

/* --- Register HW_SJC_GPUSR1, field PLL_LOCK
 *
 * PLL_LOCK  A Combined PLL-Lock flag indicator, for all the PLL's.
 */

#define BP_SJC_GPUSR1_PLL_LOCK      8
#define BM_SJC_GPUSR1_PLL_LOCK      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR1_PLL_LOCK(v)   ((((reg32_t) v) << 8) & BM_SJC_GPUSR1_PLL_LOCK)
#else
#define BF_SJC_GPUSR1_PLL_LOCK(v)   (((v) << 8) & BM_SJC_GPUSR1_PLL_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR1_PLL_LOCK(v)   BF_CS1(SJC_GPUSR1, PLL_LOCK, v)
#endif

/*!
 * @brief HW_SJC_GPUSR2 - General Purpose Unsecured Status Register 2
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned STBYWFI : 4; //!< STBYWFI[3:0]  These bits provide status of "Standby Wait-For-Interrupt" state of all ARM cores.
        unsigned S_STAT : 4; //!< S_STAT[3:0]  SDMA debug status bits: debug_core_state[3:0]
        unsigned STBYWFE : 4; //!< STBYWFE[3:0]  Reflecting the "Standby Wait For Event" signals of all cores.
        unsigned RESERVED0 : 20; //!< Reserved
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
#define HW_SJC_GPUSR2_WR(v)     (HW_SJC_GPUSR2.U = (v))
#define HW_SJC_GPUSR2_SET(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() |  (v)))
#define HW_SJC_GPUSR2_CLR(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() & ~(v)))
#define HW_SJC_GPUSR2_TOG(v)    (HW_SJC_GPUSR2_WR(HW_SJC_GPUSR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR2 bitfields
 */

/* --- Register HW_SJC_GPUSR2, field STBYWFI
 *
 * STBYWFI[3:0]  These bits provide status of "Standby Wait-For-Interrupt" state of all ARM cores.
 */

#define BP_SJC_GPUSR2_STBYWFI      0
#define BM_SJC_GPUSR2_STBYWFI      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_STBYWFI(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR2_STBYWFI)
#else
#define BF_SJC_GPUSR2_STBYWFI(v)   (((v) << 0) & BM_SJC_GPUSR2_STBYWFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_STBYWFI(v)   BF_CS1(SJC_GPUSR2, STBYWFI, v)
#endif

/* --- Register HW_SJC_GPUSR2, field S_STAT
 *
 * S_STAT[3:0]  SDMA debug status bits: debug_core_state[3:0]
 */

#define BP_SJC_GPUSR2_S_STAT      4
#define BM_SJC_GPUSR2_S_STAT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_S_STAT(v)   ((((reg32_t) v) << 4) & BM_SJC_GPUSR2_S_STAT)
#else
#define BF_SJC_GPUSR2_S_STAT(v)   (((v) << 4) & BM_SJC_GPUSR2_S_STAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_S_STAT(v)   BF_CS1(SJC_GPUSR2, S_STAT, v)
#endif

/* --- Register HW_SJC_GPUSR2, field STBYWFE
 *
 * STBYWFE[3:0]  Reflecting the "Standby Wait For Event" signals of all cores.
 */

#define BP_SJC_GPUSR2_STBYWFE      8
#define BM_SJC_GPUSR2_STBYWFE      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR2_STBYWFE(v)   ((((reg32_t) v) << 8) & BM_SJC_GPUSR2_STBYWFE)
#else
#define BF_SJC_GPUSR2_STBYWFE(v)   (((v) << 8) & BM_SJC_GPUSR2_STBYWFE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR2_STBYWFE(v)   BF_CS1(SJC_GPUSR2, STBYWFE, v)
#endif

/*!
 * @brief HW_SJC_GPUSR3 - General Purpose Unsecured Status Register 3
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPG_WAIT : 1; //!< IPG_WAIT  CCM's "ipg_wait" signal indication
        unsigned IPG_STOP : 1; //!< IPG_STOP  CCM's "ipg_stop" signal indication
        unsigned SYS_WAIT : 1; //!< System In wait  Indication on System in wait mode (from CCM).
        unsigned RESERVED0 : 29; //!< Reserved
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
#define HW_SJC_GPUSR3_WR(v)     (HW_SJC_GPUSR3.U = (v))
#define HW_SJC_GPUSR3_SET(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() |  (v)))
#define HW_SJC_GPUSR3_CLR(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() & ~(v)))
#define HW_SJC_GPUSR3_TOG(v)    (HW_SJC_GPUSR3_WR(HW_SJC_GPUSR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUSR3 bitfields
 */

/* --- Register HW_SJC_GPUSR3, field IPG_WAIT
 *
 * IPG_WAIT  CCM's "ipg_wait" signal indication
 */

#define BP_SJC_GPUSR3_IPG_WAIT      0
#define BM_SJC_GPUSR3_IPG_WAIT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_IPG_WAIT(v)   ((((reg32_t) v) << 0) & BM_SJC_GPUSR3_IPG_WAIT)
#else
#define BF_SJC_GPUSR3_IPG_WAIT(v)   (((v) << 0) & BM_SJC_GPUSR3_IPG_WAIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_IPG_WAIT(v)   BF_CS1(SJC_GPUSR3, IPG_WAIT, v)
#endif

/* --- Register HW_SJC_GPUSR3, field IPG_STOP
 *
 * IPG_STOP  CCM's "ipg_stop" signal indication
 */

#define BP_SJC_GPUSR3_IPG_STOP      1
#define BM_SJC_GPUSR3_IPG_STOP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_IPG_STOP(v)   ((((reg32_t) v) << 1) & BM_SJC_GPUSR3_IPG_STOP)
#else
#define BF_SJC_GPUSR3_IPG_STOP(v)   (((v) << 1) & BM_SJC_GPUSR3_IPG_STOP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_IPG_STOP(v)   BF_CS1(SJC_GPUSR3, IPG_STOP, v)
#endif

/* --- Register HW_SJC_GPUSR3, field SYS_WAIT
 *
 * System In wait  Indication on System in wait mode (from CCM).
 */

#define BP_SJC_GPUSR3_SYS_WAIT      2
#define BM_SJC_GPUSR3_SYS_WAIT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPUSR3_SYS_WAIT(v)   ((((reg32_t) v) << 2) & BM_SJC_GPUSR3_SYS_WAIT)
#else
#define BF_SJC_GPUSR3_SYS_WAIT(v)   (((v) << 2) & BM_SJC_GPUSR3_SYS_WAIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPUSR3_SYS_WAIT(v)   BF_CS1(SJC_GPUSR3, SYS_WAIT, v)
#endif

/*!
 * @brief HW_SJC_GPSSR - General Purpose Secured Status Register
 *
 * The General Purpose Secured Status Register is a read-only register used
 * to check the status of the different critical information in the SoC.
 * This register cannot be accessed in secure modes.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPSSR : 32; //!< General Purpose Secured Status Register  Register is used for testing and debug.
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
#define HW_SJC_GPSSR_WR(v)     (HW_SJC_GPSSR.U = (v))
#define HW_SJC_GPSSR_SET(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() |  (v)))
#define HW_SJC_GPSSR_CLR(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() & ~(v)))
#define HW_SJC_GPSSR_TOG(v)    (HW_SJC_GPSSR_WR(HW_SJC_GPSSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPSSR bitfields
 */

/* --- Register HW_SJC_GPSSR, field GPSSR
 *
 * General Purpose Secured Status Register  Register is used for testing and debug.
 */

#define BP_SJC_GPSSR_GPSSR      0
#define BM_SJC_GPSSR_GPSSR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SJC_GPSSR_GPSSR(v)   ((((reg32_t) v) << 0) & BM_SJC_GPSSR_GPSSR)
#else
#define BF_SJC_GPSSR_GPSSR(v)   (((v) << 0) & BM_SJC_GPSSR_GPSSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_GPSSR_GPSSR(v)   BF_CS1(SJC_GPSSR, GPSSR, v)
#endif

/*!
 * @brief HW_SJC_DCR - Debug Control Register
 *
 * This register is used to control propagation of debug request from DE_B pad to the cores and
 * debug signals from internal logic to the DE_B pad.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DE_TO_ARM : 1; //!< ARM platform debug request input propagation  This bit controls the propagation of debug request to ARM platform ("dbgreq"), when the JTAG state machine is put in "ENTER_DEBUG" IR instruction.
        unsigned DE_TO_SDMA : 1; //!< SDMA debug request input propagation  This bit controls the propagation of debug request to SDMA, when the JTAG state machine is put in "ENTER_DEBUG" IR instruction..
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DEBUG_OBS : 1; //!< Debug observability  This bit controls the propagation of the "system debug" input to SJC  For i.MX 6x, the SJC's "system_debug" input is tied to logic HIGH value, therefore, set of "debug_obs" bit, will result in unconditional assertion of DE_B pad.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned DIRECT_SDMA_REQ_EN : 1; //!< Debug enable of the sdma debug request  This bit controls the propagation of debug request DE_B to the sdma.
        unsigned DIRECT_ARM_REQ_EN : 1; //!< Pass Debug Enable event from DE_B pin to ARM platform debug request signal(s).  This bit controls the propagation of debug request DE_B to the Arm platform.
        unsigned RESERVED2 : 25; //!< Reserved
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

/* --- Register HW_SJC_DCR, field DE_TO_ARM
 *
 * ARM platform debug request input propagation  This bit controls the propagation of debug request
 * to ARM platform ("dbgreq"), when the JTAG state machine is put in "ENTER_DEBUG" IR
 * instruction.
 */

#define BP_SJC_DCR_DE_TO_ARM      0
#define BM_SJC_DCR_DE_TO_ARM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DE_TO_ARM(v)   ((((reg32_t) v) << 0) & BM_SJC_DCR_DE_TO_ARM)
#else
#define BF_SJC_DCR_DE_TO_ARM(v)   (((v) << 0) & BM_SJC_DCR_DE_TO_ARM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DE_TO_ARM(v)   BF_CS1(SJC_DCR, DE_TO_ARM, v)
#endif

/* --- Register HW_SJC_DCR, field DE_TO_SDMA
 *
 * SDMA debug request input propagation  This bit controls the propagation of debug request to SDMA,
 * when the JTAG state machine is put in "ENTER_DEBUG" IR
 * instruction..
 */

#define BP_SJC_DCR_DE_TO_SDMA      1
#define BM_SJC_DCR_DE_TO_SDMA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DE_TO_SDMA(v)   ((((reg32_t) v) << 1) & BM_SJC_DCR_DE_TO_SDMA)
#else
#define BF_SJC_DCR_DE_TO_SDMA(v)   (((v) << 1) & BM_SJC_DCR_DE_TO_SDMA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DE_TO_SDMA(v)   BF_CS1(SJC_DCR, DE_TO_SDMA, v)
#endif

/* --- Register HW_SJC_DCR, field DEBUG_OBS
 *
 * Debug observability  This bit controls the propagation of the "system debug" input to SJC  For
 * i.MX 6x, the SJC's "system_debug" input is tied to logic HIGH value, therefore, set of
 * "debug_obs" bit, will result in unconditional assertion of DE_B pad.
 */

#define BP_SJC_DCR_DEBUG_OBS      3
#define BM_SJC_DCR_DEBUG_OBS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DEBUG_OBS(v)   ((((reg32_t) v) << 3) & BM_SJC_DCR_DEBUG_OBS)
#else
#define BF_SJC_DCR_DEBUG_OBS(v)   (((v) << 3) & BM_SJC_DCR_DEBUG_OBS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DEBUG_OBS(v)   BF_CS1(SJC_DCR, DEBUG_OBS, v)
#endif

/* --- Register HW_SJC_DCR, field DIRECT_SDMA_REQ_EN
 *
 * Debug enable of the sdma debug request  This bit controls the propagation of debug request DE_B
 * to the                                 sdma.
 */

#define BP_SJC_DCR_DIRECT_SDMA_REQ_EN      5
#define BM_SJC_DCR_DIRECT_SDMA_REQ_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   ((((reg32_t) v) << 5) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#else
#define BF_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   (((v) << 5) & BM_SJC_DCR_DIRECT_SDMA_REQ_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DIRECT_SDMA_REQ_EN(v)   BF_CS1(SJC_DCR, DIRECT_SDMA_REQ_EN, v)
#endif

/* --- Register HW_SJC_DCR, field DIRECT_ARM_REQ_EN
 *
 * Pass Debug Enable event from DE_B pin to ARM platform debug request signal(s).  This bit controls
 * the propagation of debug request DE_B to the                                 Arm platform.
 */

#define BP_SJC_DCR_DIRECT_ARM_REQ_EN      6
#define BM_SJC_DCR_DIRECT_ARM_REQ_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   ((((reg32_t) v) << 6) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#else
#define BF_SJC_DCR_DIRECT_ARM_REQ_EN(v)   (((v) << 6) & BM_SJC_DCR_DIRECT_ARM_REQ_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_DCR_DIRECT_ARM_REQ_EN(v)   BF_CS1(SJC_DCR, DIRECT_ARM_REQ_EN, v)
#endif

/*!
 * @brief HW_SJC_SSR - Security Status Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned KTF : 1; //!< Kill Trace Enable fuse value
        unsigned KTA : 1; //!< Kill Trace is active
        unsigned SWF : 1; //!< Software JTAG enable fuse  Status of the no SW disable JTAG fuse
        unsigned SWE : 1; //!< SW enable  SW JTAG enable status
        unsigned EBF : 1; //!< External Boot fuse  Status of the external boot disable fuse
        unsigned EBG : 1; //!< External boot granted  External boot enabled, requested and granted
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned FT : 1; //!< Fuse type  Fuse type bit - e-fuse or laser fuse
        unsigned SJM : 2; //!< SJC Secure mode  Secure JTAG mode, as set by external fuses. These bits do not reflect the change due to burn of Bypass Secure JTAG fuse.
        unsigned RSSTAT : 2; //!< Response status  Response status bits
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned BOOTIND : 1; //!< Boot Indication  Inverted Internal Boot indication, i.e inverse of SRC:  "src_int_boot" signal
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned RESERVED4 : 15; //!< Reserved.
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
#define HW_SJC_SSR_WR(v)     (HW_SJC_SSR.U = (v))
#define HW_SJC_SSR_SET(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() |  (v)))
#define HW_SJC_SSR_CLR(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() & ~(v)))
#define HW_SJC_SSR_TOG(v)    (HW_SJC_SSR_WR(HW_SJC_SSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_SSR bitfields
 */

/* --- Register HW_SJC_SSR, field KTF
 *
 * Kill Trace Enable fuse value
 */

#define BP_SJC_SSR_KTF      0
#define BM_SJC_SSR_KTF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_KTF(v)   ((((reg32_t) v) << 0) & BM_SJC_SSR_KTF)
#else
#define BF_SJC_SSR_KTF(v)   (((v) << 0) & BM_SJC_SSR_KTF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_KTF(v)   BF_CS1(SJC_SSR, KTF, v)
#endif

/* --- Register HW_SJC_SSR, field KTA
 *
 * Kill Trace is active
 */

#define BP_SJC_SSR_KTA      1
#define BM_SJC_SSR_KTA      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_KTA(v)   ((((reg32_t) v) << 1) & BM_SJC_SSR_KTA)
#else
#define BF_SJC_SSR_KTA(v)   (((v) << 1) & BM_SJC_SSR_KTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_KTA(v)   BF_CS1(SJC_SSR, KTA, v)
#endif

/* --- Register HW_SJC_SSR, field SWF
 *
 * Software JTAG enable fuse  Status of the no SW disable JTAG fuse
 */

#define BP_SJC_SSR_SWF      2
#define BM_SJC_SSR_SWF      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SWF(v)   ((((reg32_t) v) << 2) & BM_SJC_SSR_SWF)
#else
#define BF_SJC_SSR_SWF(v)   (((v) << 2) & BM_SJC_SSR_SWF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SWF(v)   BF_CS1(SJC_SSR, SWF, v)
#endif

/* --- Register HW_SJC_SSR, field SWE
 *
 * SW enable  SW JTAG enable status
 */

#define BP_SJC_SSR_SWE      3
#define BM_SJC_SSR_SWE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SWE(v)   ((((reg32_t) v) << 3) & BM_SJC_SSR_SWE)
#else
#define BF_SJC_SSR_SWE(v)   (((v) << 3) & BM_SJC_SSR_SWE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SWE(v)   BF_CS1(SJC_SSR, SWE, v)
#endif

/* --- Register HW_SJC_SSR, field EBF
 *
 * External Boot fuse  Status of the external boot disable fuse
 */

#define BP_SJC_SSR_EBF      4
#define BM_SJC_SSR_EBF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_EBF(v)   ((((reg32_t) v) << 4) & BM_SJC_SSR_EBF)
#else
#define BF_SJC_SSR_EBF(v)   (((v) << 4) & BM_SJC_SSR_EBF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_EBF(v)   BF_CS1(SJC_SSR, EBF, v)
#endif

/* --- Register HW_SJC_SSR, field EBG
 *
 * External boot granted  External boot enabled, requested and granted
 */

#define BP_SJC_SSR_EBG      5
#define BM_SJC_SSR_EBG      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_EBG(v)   ((((reg32_t) v) << 5) & BM_SJC_SSR_EBG)
#else
#define BF_SJC_SSR_EBG(v)   (((v) << 5) & BM_SJC_SSR_EBG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_EBG(v)   BF_CS1(SJC_SSR, EBG, v)
#endif

/* --- Register HW_SJC_SSR, field FT
 *
 * Fuse type  Fuse type bit - e-fuse or laser fuse
 */

#define BP_SJC_SSR_FT      8
#define BM_SJC_SSR_FT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_FT(v)   ((((reg32_t) v) << 8) & BM_SJC_SSR_FT)
#else
#define BF_SJC_SSR_FT(v)   (((v) << 8) & BM_SJC_SSR_FT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_FT(v)   BF_CS1(SJC_SSR, FT, v)
#endif

/* --- Register HW_SJC_SSR, field SJM
 *
 * SJC Secure mode  Secure JTAG mode, as set by external fuses. These bits do not reflect the change
 * due to burn of Bypass Secure JTAG fuse.
 */

#define BP_SJC_SSR_SJM      9
#define BM_SJC_SSR_SJM      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_SJM(v)   ((((reg32_t) v) << 9) & BM_SJC_SSR_SJM)
#else
#define BF_SJC_SSR_SJM(v)   (((v) << 9) & BM_SJC_SSR_SJM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_SJM(v)   BF_CS1(SJC_SSR, SJM, v)
#endif

/* --- Register HW_SJC_SSR, field RSSTAT
 *
 * Response status  Response status bits
 */

#define BP_SJC_SSR_RSSTAT      11
#define BM_SJC_SSR_RSSTAT      0x00001800

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_RSSTAT(v)   ((((reg32_t) v) << 11) & BM_SJC_SSR_RSSTAT)
#else
#define BF_SJC_SSR_RSSTAT(v)   (((v) << 11) & BM_SJC_SSR_RSSTAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_RSSTAT(v)   BF_CS1(SJC_SSR, RSSTAT, v)
#endif

/* --- Register HW_SJC_SSR, field BOOTIND
 *
 * Boot Indication  Inverted Internal Boot indication, i.e inverse of SRC:  "src_int_boot" signal
 */

#define BP_SJC_SSR_BOOTIND      14
#define BM_SJC_SSR_BOOTIND      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SJC_SSR_BOOTIND(v)   ((((reg32_t) v) << 14) & BM_SJC_SSR_BOOTIND)
#else
#define BF_SJC_SSR_BOOTIND(v)   (((v) << 14) & BM_SJC_SSR_BOOTIND)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SJC_SSR_BOOTIND(v)   BF_CS1(SJC_SSR, BOOTIND, v)
#endif

/*!
 * @brief HW_SJC_GPCCR - General Purpose Clocks Control Register
 *
 * This register is used to configure clock                                 related modes in SOC,
 * see System Configuration chapter for more                                 information. Those bits
 * are directly                                 connected to JTAG outputs. Bit 0 of GPCCR controls
 * SDMA clocks                                 invocation. When out of reset, the SDMA is in sleep
 * mode with no                                 SDMA clock running. Unlike events, debug requests
 * does not wake SDMA                                 if it is in sleep mode. The debug request is
 * recognized by the SDMA                                 only when it exits sleep mode upon
 * reception of an event. To be able                                 to enter debug mode even if no
 * event is triggered, the SDMA clock on                                 bit needs to be set prior
 * to sending the debug request (clear at                                 reset).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< 
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

/*!
 * @brief HW_SJC_GPUCR - General Purpose Unsecured Control Register n
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Reserved.
    } B;
} hw_sjc_gpucr_t;
#endif

/*
 * constants & macros for entire SJC_GPUCR register
 */
#define HW_SJC_GPUCR_ADDR      (REGS_SJC_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SJC_GPUCR           (*(volatile hw_sjc_gpucr_t *) HW_SJC_GPUCR_ADDR)
#define HW_SJC_GPUCR_RD()      (HW_SJC_GPUCR.U)
#define HW_SJC_GPUCR_WR(v)     (HW_SJC_GPUCR.U = (v))
#define HW_SJC_GPUCR_SET(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() |  (v)))
#define HW_SJC_GPUCR_CLR(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() & ~(v)))
#define HW_SJC_GPUCR_TOG(v)    (HW_SJC_GPUCR_WR(HW_SJC_GPUCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SJC_GPUCR bitfields
 */

/*!
 * @brief HW_SJC_GPSCR - General Purpose Secured Control Register
 *
 * This register is used to configure JTAG for special test or debug modes.
 * This register is secured (accessible in secure jtag mode #3, #4 and #2
 * with response entered). Those bits are directly connected to SJC
 * outputs.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Reserved.
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
typedef struct
{
    volatile hw_sjc_gpusr1_t GPUSR1; //!< General Purpose Unsecured Status Register 1
    volatile hw_sjc_gpusr2_t GPUSR2; //!< General Purpose Unsecured Status Register 2
    volatile hw_sjc_gpusr3_t GPUSR3; //!< General Purpose Unsecured Status Register 3
    volatile hw_sjc_gpssr_t GPSSR; //!< General Purpose Secured Status Register
    volatile hw_sjc_dcr_t DCR; //!< Debug Control Register
    volatile hw_sjc_ssr_t SSR; //!< Security Status Register
    volatile hw_sjc_gpccr_t GPCCR; //!< General Purpose Clocks Control Register
    volatile hw_sjc_gpucr_t GPUCR; //!< General Purpose Unsecured Control Register n
    volatile hw_sjc_gpscr_t GPSCR; //!< General Purpose Secured Control Register
} hw_sjc_t
#endif

//! @brief Macro to access all SJC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SJC(0)</code>.
#define HW_SJC     (*(volatile hw_sjc_t *) REGS_SJC_BASE)


#endif // _SJC_H
