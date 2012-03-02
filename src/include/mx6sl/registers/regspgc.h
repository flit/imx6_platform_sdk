/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PGC_H
#define _PGC_H

#include "regs.h"

/*
 * i.MX6SL PGC registers defined in this header file.
 *
 * - HW_PGC_CTRL - PGC Control REgister
 * - HW_PGC_PUPSCR - Power Up Sequence Control Register
 * - HW_PGC_PDNSCR - Pull Down Sequence Control Register
 * - HW_PGC_SR - Power Gating Controller Status Register
 *
 * hw_pgc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PGC_BASE
#define REGS_PGC_BASE (0x00000000) //!< Base address for PGC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_CTRL - PGC Control REgister (RW)
 *
 * Reset value: 0x00000000
 *
 * The PGCR enables the response to a power-down request.
 */
typedef union _hw_pgc_ctrl
{
    reg32_t U;
    struct _hw_pgc_ctrl_bitfields
    {
        unsigned PCR : 1; //!< [0] Power Control PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_ctrl_t;
#endif

/*
 * constants & macros for entire PGC_CTRL register
 */
#define HW_PGC_CTRL_ADDR      (REGS_PGC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_CTRL           (*(volatile hw_pgc_ctrl_t *) HW_PGC_CTRL_ADDR)
#define HW_PGC_CTRL_RD()      (HW_PGC_CTRL.U)
#define HW_PGC_CTRL_WR(v)     (HW_PGC_CTRL.U = (v))
#define HW_PGC_CTRL_SET(v)    (HW_PGC_CTRL_WR(HW_PGC_CTRL_RD() |  (v)))
#define HW_PGC_CTRL_CLR(v)    (HW_PGC_CTRL_WR(HW_PGC_CTRL_RD() & ~(v)))
#define HW_PGC_CTRL_TOG(v)    (HW_PGC_CTRL_WR(HW_PGC_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_CTRL bitfields
 */

/* --- Register HW_PGC_CTRL, field PCR[0] (RW)
 *
 * Power Control PCR must not change from power-down request (pdn_req) assertion until the target
 * subsystem is completely powered up.
 *
 * Values:
 * 0 - Do not switch off power even if pdn_req is asserted.
 * 1 - Switch off power when pdn_req is asserted.
 */

#define BP_PGC_CTRL_PCR      (0)      //!< Bit position for PGC_CTRL_PCR.
#define BM_PGC_CTRL_PCR      (0x00000001)  //!< Bit mask for PGC_CTRL_PCR.

//! @brief Get value of PGC_CTRL_PCR from a register value.
#define BG_PGC_CTRL_PCR(r)   (((r) & BM_PGC_CTRL_PCR) >> BP_PGC_CTRL_PCR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_CTRL_PCR.
#define BF_PGC_CTRL_PCR(v)   ((((reg32_t) v) << BP_PGC_CTRL_PCR) & BM_PGC_CTRL_PCR)
#else
//! @brief Format value for bitfield PGC_CTRL_PCR.
#define BF_PGC_CTRL_PCR(v)   (((v) << BP_PGC_CTRL_PCR) & BM_PGC_CTRL_PCR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCR field to a new value.
#define BW_PGC_CTRL_PCR(v)   (HW_PGC_CTRL_WR((HW_PGC_CTRL_RD() & ~BM_PGC_CTRL_PCR) | BF_PGC_CTRL_PCR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_PUPSCR - Power Up Sequence Control Register (RW)
 *
 * Reset value: 0x00000f01
 *
 * The PUPSCR contains the power-up timing parameters. See .
 */
typedef union _hw_pgc_pupscr
{
    reg32_t U;
    struct _hw_pgc_pupscr_bitfields
    {
        unsigned SW : 6; //!< [5:0] After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value of SW before asserting switch_b. SW must not be programmed to zero. A zero value could cause a glitch on switch_b if pup_req is asserted immediately after negation of switch_b.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned SW2ISO : 6; //!< [13:8] After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before negating isolation. SW2ISO must not be programmed to zero.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_pupscr_t;
#endif

/*
 * constants & macros for entire PGC_PUPSCR register
 */
#define HW_PGC_PUPSCR_ADDR      (REGS_PGC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_PUPSCR           (*(volatile hw_pgc_pupscr_t *) HW_PGC_PUPSCR_ADDR)
#define HW_PGC_PUPSCR_RD()      (HW_PGC_PUPSCR.U)
#define HW_PGC_PUPSCR_WR(v)     (HW_PGC_PUPSCR.U = (v))
#define HW_PGC_PUPSCR_SET(v)    (HW_PGC_PUPSCR_WR(HW_PGC_PUPSCR_RD() |  (v)))
#define HW_PGC_PUPSCR_CLR(v)    (HW_PGC_PUPSCR_WR(HW_PGC_PUPSCR_RD() & ~(v)))
#define HW_PGC_PUPSCR_TOG(v)    (HW_PGC_PUPSCR_WR(HW_PGC_PUPSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_PUPSCR bitfields
 */

/* --- Register HW_PGC_PUPSCR, field SW[5:0] (RW)
 *
 * After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value
 * of SW before asserting switch_b. SW must not be programmed to zero. A zero value could cause a
 * glitch on switch_b if pup_req is asserted immediately after negation of switch_b.
 */

#define BP_PGC_PUPSCR_SW      (0)      //!< Bit position for PGC_PUPSCR_SW.
#define BM_PGC_PUPSCR_SW      (0x0000003f)  //!< Bit mask for PGC_PUPSCR_SW.

//! @brief Get value of PGC_PUPSCR_SW from a register value.
#define BG_PGC_PUPSCR_SW(r)   (((r) & BM_PGC_PUPSCR_SW) >> BP_PGC_PUPSCR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_PUPSCR_SW.
#define BF_PGC_PUPSCR_SW(v)   ((((reg32_t) v) << BP_PGC_PUPSCR_SW) & BM_PGC_PUPSCR_SW)
#else
//! @brief Format value for bitfield PGC_PUPSCR_SW.
#define BF_PGC_PUPSCR_SW(v)   (((v) << BP_PGC_PUPSCR_SW) & BM_PGC_PUPSCR_SW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_PGC_PUPSCR_SW(v)   (HW_PGC_PUPSCR_WR((HW_PGC_PUPSCR_RD() & ~BM_PGC_PUPSCR_SW) | BF_PGC_PUPSCR_SW(v)))
#endif

/* --- Register HW_PGC_PUPSCR, field SW2ISO[13:8] (RW)
 *
 * After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before
 * negating isolation. SW2ISO must not be programmed to zero.
 */

#define BP_PGC_PUPSCR_SW2ISO      (8)      //!< Bit position for PGC_PUPSCR_SW2ISO.
#define BM_PGC_PUPSCR_SW2ISO      (0x00003f00)  //!< Bit mask for PGC_PUPSCR_SW2ISO.

//! @brief Get value of PGC_PUPSCR_SW2ISO from a register value.
#define BG_PGC_PUPSCR_SW2ISO(r)   (((r) & BM_PGC_PUPSCR_SW2ISO) >> BP_PGC_PUPSCR_SW2ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_PUPSCR_SW2ISO.
#define BF_PGC_PUPSCR_SW2ISO(v)   ((((reg32_t) v) << BP_PGC_PUPSCR_SW2ISO) & BM_PGC_PUPSCR_SW2ISO)
#else
//! @brief Format value for bitfield PGC_PUPSCR_SW2ISO.
#define BF_PGC_PUPSCR_SW2ISO(v)   (((v) << BP_PGC_PUPSCR_SW2ISO) & BM_PGC_PUPSCR_SW2ISO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW2ISO field to a new value.
#define BW_PGC_PUPSCR_SW2ISO(v)   (HW_PGC_PUPSCR_WR((HW_PGC_PUPSCR_RD() & ~BM_PGC_PUPSCR_SW2ISO) | BF_PGC_PUPSCR_SW2ISO(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_PDNSCR - Pull Down Sequence Control Register (RW)
 *
 * Reset value: 0x00000101
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_pdnscr
{
    reg32_t U;
    struct _hw_pgc_pdnscr_bitfields
    {
        unsigned ISO : 6; //!< [5:0] After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the value of ISO before asserting isolation. ISO must not be programmed to zero.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned ISO2SW : 6; //!< [13:8] After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before negating switch_b. ISO2SW must not be programmed to zero.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_pdnscr_t;
#endif

/*
 * constants & macros for entire PGC_PDNSCR register
 */
#define HW_PGC_PDNSCR_ADDR      (REGS_PGC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_PDNSCR           (*(volatile hw_pgc_pdnscr_t *) HW_PGC_PDNSCR_ADDR)
#define HW_PGC_PDNSCR_RD()      (HW_PGC_PDNSCR.U)
#define HW_PGC_PDNSCR_WR(v)     (HW_PGC_PDNSCR.U = (v))
#define HW_PGC_PDNSCR_SET(v)    (HW_PGC_PDNSCR_WR(HW_PGC_PDNSCR_RD() |  (v)))
#define HW_PGC_PDNSCR_CLR(v)    (HW_PGC_PDNSCR_WR(HW_PGC_PDNSCR_RD() & ~(v)))
#define HW_PGC_PDNSCR_TOG(v)    (HW_PGC_PDNSCR_WR(HW_PGC_PDNSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_PDNSCR bitfields
 */

/* --- Register HW_PGC_PDNSCR, field ISO[5:0] (RW)
 *
 * After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the
 * value of ISO before asserting isolation. ISO must not be programmed to zero.
 */

#define BP_PGC_PDNSCR_ISO      (0)      //!< Bit position for PGC_PDNSCR_ISO.
#define BM_PGC_PDNSCR_ISO      (0x0000003f)  //!< Bit mask for PGC_PDNSCR_ISO.

//! @brief Get value of PGC_PDNSCR_ISO from a register value.
#define BG_PGC_PDNSCR_ISO(r)   (((r) & BM_PGC_PDNSCR_ISO) >> BP_PGC_PDNSCR_ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_PDNSCR_ISO.
#define BF_PGC_PDNSCR_ISO(v)   ((((reg32_t) v) << BP_PGC_PDNSCR_ISO) & BM_PGC_PDNSCR_ISO)
#else
//! @brief Format value for bitfield PGC_PDNSCR_ISO.
#define BF_PGC_PDNSCR_ISO(v)   (((v) << BP_PGC_PDNSCR_ISO) & BM_PGC_PDNSCR_ISO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO field to a new value.
#define BW_PGC_PDNSCR_ISO(v)   (HW_PGC_PDNSCR_WR((HW_PGC_PDNSCR_RD() & ~BM_PGC_PDNSCR_ISO) | BF_PGC_PDNSCR_ISO(v)))
#endif

/* --- Register HW_PGC_PDNSCR, field ISO2SW[13:8] (RW)
 *
 * After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before
 * negating switch_b. ISO2SW must not be programmed to zero.
 */

#define BP_PGC_PDNSCR_ISO2SW      (8)      //!< Bit position for PGC_PDNSCR_ISO2SW.
#define BM_PGC_PDNSCR_ISO2SW      (0x00003f00)  //!< Bit mask for PGC_PDNSCR_ISO2SW.

//! @brief Get value of PGC_PDNSCR_ISO2SW from a register value.
#define BG_PGC_PDNSCR_ISO2SW(r)   (((r) & BM_PGC_PDNSCR_ISO2SW) >> BP_PGC_PDNSCR_ISO2SW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_PDNSCR_ISO2SW.
#define BF_PGC_PDNSCR_ISO2SW(v)   ((((reg32_t) v) << BP_PGC_PDNSCR_ISO2SW) & BM_PGC_PDNSCR_ISO2SW)
#else
//! @brief Format value for bitfield PGC_PDNSCR_ISO2SW.
#define BF_PGC_PDNSCR_ISO2SW(v)   (((v) << BP_PGC_PDNSCR_ISO2SW) & BM_PGC_PDNSCR_ISO2SW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO2SW field to a new value.
#define BW_PGC_PDNSCR_ISO2SW(v)   (HW_PGC_PDNSCR_WR((HW_PGC_PDNSCR_RD() & ~BM_PGC_PDNSCR_ISO2SW) | BF_PGC_PDNSCR_ISO2SW(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_SR - Power Gating Controller Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_sr
{
    reg32_t U;
    struct _hw_pgc_sr_bitfields
    {
        unsigned PSR : 1; //!< [0] Power status. When in functional (or software-controlled debug) mode, PGC hardware sets PSR as soon as any of the power control output changes its state to one. Write one to clear this bit. Software should clear this bit after power up; otherwise, PSR continues to reflect the power status of the initial power down.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_sr_t;
#endif

/*
 * constants & macros for entire PGC_SR register
 */
#define HW_PGC_SR_ADDR      (REGS_PGC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_SR           (*(volatile hw_pgc_sr_t *) HW_PGC_SR_ADDR)
#define HW_PGC_SR_RD()      (HW_PGC_SR.U)
#define HW_PGC_SR_WR(v)     (HW_PGC_SR.U = (v))
#define HW_PGC_SR_SET(v)    (HW_PGC_SR_WR(HW_PGC_SR_RD() |  (v)))
#define HW_PGC_SR_CLR(v)    (HW_PGC_SR_WR(HW_PGC_SR_RD() & ~(v)))
#define HW_PGC_SR_TOG(v)    (HW_PGC_SR_WR(HW_PGC_SR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_SR bitfields
 */

/* --- Register HW_PGC_SR, field PSR[0] (RW)
 *
 * Power status. When in functional (or software-controlled debug) mode, PGC hardware sets PSR as
 * soon as any of the power control output changes its state to one. Write one to clear this bit.
 * Software should clear this bit after power up; otherwise, PSR continues to reflect the power
 * status of the initial power down.
 *
 * Values:
 * 0 - The target subsystem was not powered down for the previous power-down request.
 * 1 - The target subsystem was powered down for the previous power-down request.
 */

#define BP_PGC_SR_PSR      (0)      //!< Bit position for PGC_SR_PSR.
#define BM_PGC_SR_PSR      (0x00000001)  //!< Bit mask for PGC_SR_PSR.

//! @brief Get value of PGC_SR_PSR from a register value.
#define BG_PGC_SR_PSR(r)   (((r) & BM_PGC_SR_PSR) >> BP_PGC_SR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield PGC_SR_PSR.
#define BF_PGC_SR_PSR(v)   ((((reg32_t) v) << BP_PGC_SR_PSR) & BM_PGC_SR_PSR)
#else
//! @brief Format value for bitfield PGC_SR_PSR.
#define BF_PGC_SR_PSR(v)   (((v) << BP_PGC_SR_PSR) & BM_PGC_SR_PSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_PGC_SR_PSR(v)   (HW_PGC_SR_WR((HW_PGC_SR_RD() & ~BM_PGC_SR_PSR) | BF_PGC_SR_PSR(v)))
#endif



/*!
 * @brief All PGC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pgc
{
    volatile hw_pgc_ctrl_t CTRL; //!< PGC Control REgister
    volatile hw_pgc_pupscr_t PUPSCR; //!< Power Up Sequence Control Register
    volatile hw_pgc_pdnscr_t PDNSCR; //!< Pull Down Sequence Control Register
    volatile hw_pgc_sr_t SR; //!< Power Gating Controller Status Register
} hw_pgc_t;
#pragma pack()
#endif

//! @brief Macro to access all PGC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PGC(0)</code>.
#define HW_PGC     (*(volatile hw_pgc_t *) REGS_PGC_BASE)


#endif // _PGC_H
