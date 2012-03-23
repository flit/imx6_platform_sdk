/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_GPT_REGISTERS_H__
#define __HW_GPT_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ GPT registers defined in this header file.
 *
 * - HW_GPT_CR - GPT Control Register
 * - HW_GPT_PR - GPT Prescaler Register
 * - HW_GPT_SR - GPT Status Register
 * - HW_GPT_IR - GPT Interrupt Register
 * - HW_GPT_OCR1 - GPT Output Compare Register 1
 * - HW_GPT_OCR2 - GPT Output Compare Register 2
 * - HW_GPT_OCR3 - GPT Output Compare Register 3
 * - HW_GPT_ICR1 - GPT Input Capture Register 1
 * - HW_GPT_ICR2 - GPT Input Capture Register 2
 * - HW_GPT_CNT - GPT Counter Register
 *
 * - hw_gpt_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_GPT_BASE
#define HW_GPT_INSTANCE_COUNT (1) //!< Number of instances of the GPT module.
#define REGS_GPT_BASE (0x02098000) //!< Base address for GPT.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_CR - GPT Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The GPT Control Register (GPT_CR) is used to program and configure GPT operations. An IP Bus
 * Write to the GPT Control Register occurs after one cycle of wait state (ips_xfr_wait high for 1
 * cycle) , while an IP Bus Read occurs after 0 wait states.
 */
typedef union _hw_gpt_cr
{
    reg32_t U;
    struct _hw_gpt_cr_bitfields
    {
        unsigned EN : 1; //!< [0] GPT Enable. The EN bit is the GPT module enable bit. Before setting the EN bit , we recommend that all registers be properly programmed . A hardware reset resets the EN bit. A software reset does not affect the EN bit.
        unsigned ENMOD : 1; //!< [1] GPT Enable mode. When the GPT is disabled (EN=0), then both the Main Counter and Prescaler Counter freeze their current count values . The ENMOD bit determines the value of the GPT counter when Counter is enabled again (if the EN bit is set). If the ENMOD bit is 1, then the Main Counter and Prescaler Counter values are reset to 0 after GPT is enabled (EN=1). If the ENMOD bit is 0, then the Main Counter and Prescaler Counter restart counting from their frozen values after GPT is enabled (EN=1). If GPT is programmed to be disabled in a low power mode (STOP/WAIT), then the Main Counter and Prescaler Counter freeze at their current count values when the GPT enters low power mode. When GPT exits low power mode, the Main Counter and Prescaler Counter start counting from their frozen values, regardless of the ENMOD bit value. Setting the SWR bit will clear the Main Counter and Prescaler Counter values, regardless of the value of EN or ENMOD bits. A hardware reset resets the ENMOD bit. A software reset does not affect the ENMOD bit.
        unsigned DBGEN : 1; //!< [2] GPT debug mode enable. The DBGEN read/write control bit enables GPT operation during Debug mode . A hardware reset resets the DBGEN bit. A software reset does not affect the DBGEN bit.
        unsigned WAITEN : 1; //!< [3] GPT Wait Mode enable. The WAITEN read/write control bit enables GPT operation during Wait mode . A hardware reset resets the WAITEN bit. A software reset does not affect the WAITEN bit.
        unsigned DOZEEN : 1; //!< [4] GPT Doze Mode Enable. A hardware reset resets the DOZEEN bit. A software reset does not affect the DOZEEN bit.
        unsigned STOPEN : 1; //!< [5] GPT Stop Mode enable. The STOPEN read/write control bit enables GPT operation during Stop mode . A hardware reset resets the STOPEN bit. A software reset does not affect the STOPEN bit.
        unsigned CLKSRC : 3; //!< [8:6] Clock Source select. The CLKSRC bits select which clock will go to the prescaler (and subsequently be used to run the GPT counter). The CLKSRC bit field value should only be changed after disabling the GPT by clearing the EN bit in this register (GPT_CR). A software reset does not affect the CLKSRC bit. For other programming requirements to change the clock source, see section .
        unsigned FRR : 1; //!< [9] Free-Run or Restart mode. The FFR bit determines the behavior of the GPT when a compare event in channel 1 occurs. In Restart mode, after a compare event, the counter resets to 0x00000000 and resumes counting (after the occurrence of a compare event). In Free-Run mode, after a compare event, the counter continues counting until 0xFFFFFFFF and then rolls over to 0.
        unsigned RESERVED0 : 5; //!< [14:10] Reserved bits. Writing a value to these reserved bits will not affect GPT operations. These reserved bits are always read as zero. It is recommended that all writes to these reserved bits be 0 (for forward compatibility).
        unsigned SWR : 1; //!< [15] Software reset. This is the software reset of the GPT module. It is a self-clearing bit. The SWR bit is set when the module is in reset state. The SWR bit is cleared when the reset procedure finishes. Setting the SWR bit resets all of the registers to their default reset values, except for the CLKSRC, EN, ENMOD, STOPEN, WAITEN, and DBGEN bits in the GPT Control Register (this control register).
        unsigned IM1 : 2; //!< [17:16] See IM2
        unsigned IM2 : 2; //!< [19:18] IM2 (bits 19-18, Input Capture Channel 2 operating mode) IM1 (bits 17-16, Input Capture Channel 1 operating mode) The IM n bit field determines the transition on the input pin (for Input capture channel n ), which will trigger a capture event.
        unsigned OM1 : 3; //!< [22:20] See OM3
        unsigned OM2 : 3; //!< [25:23] See OM3
        unsigned OM3 : 3; //!< [28:26] OM3 (bits 28-26) controls the Output Compare Channel 3 operating mode. OM2 (bits 25-23) controls the Output Compare Channel 2 operating mode. OM1 (bits 22-20) controls the Output Compare Channel 1 operating mode. The OM n bits specify the response that a compare event will generate on the output pin of Output Compare Channel n . The toggle, clear, and set options cause a change on the output pin only if a compare event occurs. When OM n is programmed as 1xx (active low pulse), the output pin is set to one immediately on the next input clock; a low pulse (that is an input clock in width) occurs when there is a compare event. Note that here, "input clock" refers to the clock selected by the CLKSRC bits of the GPT Control Register.
        unsigned FO1 : 1; //!< [29] See F03
        unsigned FO2 : 1; //!< [30] See F03
        unsigned FO3 : 1; //!< [31] FO3 Force Output Compare Channel 3 FO2 Force Output Compare Channel 2 FO1 Force Output Compare Channel 1 The FO n bit causes the pin action programmed for the timer Output Compare n pin (according to the OM n bits in this register). The OF n flag (OF3, OF2, OF1) in the status register is not affected . This bit is self-negating and always read as zero.
    } B;
} hw_gpt_cr_t;
#endif

/*
 * constants & macros for entire GPT_CR register
 */
#define HW_GPT_CR_ADDR      (REGS_GPT_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_CR           (*(volatile hw_gpt_cr_t *) HW_GPT_CR_ADDR)
#define HW_GPT_CR_RD()      (HW_GPT_CR.U)
#define HW_GPT_CR_WR(v)     (HW_GPT_CR.U = (v))
#define HW_GPT_CR_SET(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() |  (v)))
#define HW_GPT_CR_CLR(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() & ~(v)))
#define HW_GPT_CR_TOG(v)    (HW_GPT_CR_WR(HW_GPT_CR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_CR bitfields
 */

/* --- Register HW_GPT_CR, field EN[0] (RW)
 *
 * GPT Enable. The EN bit is the GPT module enable bit. Before setting the EN bit , we recommend
 * that all registers be properly programmed . A hardware reset resets the EN bit. A software reset
 * does not affect the EN bit.
 *
 * Values:
 * 0 - GPT is disabled.
 * 1 - GPT is enabled.
 */

#define BP_GPT_CR_EN      (0)      //!< Bit position for GPT_CR_EN.
#define BM_GPT_CR_EN      (0x00000001)  //!< Bit mask for GPT_CR_EN.

//! @brief Get value of GPT_CR_EN from a register value.
#define BG_GPT_CR_EN(r)   (((r) & BM_GPT_CR_EN) >> BP_GPT_CR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_EN.
#define BF_GPT_CR_EN(v)   ((((reg32_t) v) << BP_GPT_CR_EN) & BM_GPT_CR_EN)
#else
//! @brief Format value for bitfield GPT_CR_EN.
#define BF_GPT_CR_EN(v)   (((v) << BP_GPT_CR_EN) & BM_GPT_CR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_GPT_CR_EN(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_EN) | BF_GPT_CR_EN(v)))
#endif


/* --- Register HW_GPT_CR, field ENMOD[1] (RW)
 *
 * GPT Enable mode. When the GPT is disabled (EN=0), then both the Main Counter and Prescaler
 * Counter freeze their current count values . The ENMOD bit determines the value of the GPT counter
 * when Counter is enabled again (if the EN bit is set). If the ENMOD bit is 1, then the Main
 * Counter and Prescaler Counter values are reset to 0 after GPT is enabled (EN=1). If the ENMOD bit
 * is 0, then the Main Counter and Prescaler Counter restart counting from their frozen values after
 * GPT is enabled (EN=1). If GPT is programmed to be disabled in a low power mode (STOP/WAIT), then
 * the Main Counter and Prescaler Counter freeze at their current count values when the GPT enters
 * low power mode. When GPT exits low power mode, the Main Counter and Prescaler Counter start
 * counting from their frozen values, regardless of the ENMOD bit value. Setting the SWR bit will
 * clear the Main Counter and Prescaler Counter values, regardless of the value of EN or ENMOD bits.
 * A hardware reset resets the ENMOD bit. A software reset does not affect the ENMOD bit.
 *
 * Values:
 * 0 - GPT counter will retain its value when it is disabled.
 * 1 - GPT counter value is reset to 0 when it is disabled.
 */

#define BP_GPT_CR_ENMOD      (1)      //!< Bit position for GPT_CR_ENMOD.
#define BM_GPT_CR_ENMOD      (0x00000002)  //!< Bit mask for GPT_CR_ENMOD.

//! @brief Get value of GPT_CR_ENMOD from a register value.
#define BG_GPT_CR_ENMOD(r)   (((r) & BM_GPT_CR_ENMOD) >> BP_GPT_CR_ENMOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_ENMOD.
#define BF_GPT_CR_ENMOD(v)   ((((reg32_t) v) << BP_GPT_CR_ENMOD) & BM_GPT_CR_ENMOD)
#else
//! @brief Format value for bitfield GPT_CR_ENMOD.
#define BF_GPT_CR_ENMOD(v)   (((v) << BP_GPT_CR_ENMOD) & BM_GPT_CR_ENMOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENMOD field to a new value.
#define BW_GPT_CR_ENMOD(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_ENMOD) | BF_GPT_CR_ENMOD(v)))
#endif


/* --- Register HW_GPT_CR, field DBGEN[2] (RW)
 *
 * GPT debug mode enable. The DBGEN read/write control bit enables GPT operation during Debug mode .
 * A hardware reset resets the DBGEN bit. A software reset does not affect the DBGEN bit.
 *
 * Values:
 * 0 - GPT is disabled in debug mode.
 * 1 - GPT is enabled in debug mode.
 */

#define BP_GPT_CR_DBGEN      (2)      //!< Bit position for GPT_CR_DBGEN.
#define BM_GPT_CR_DBGEN      (0x00000004)  //!< Bit mask for GPT_CR_DBGEN.

//! @brief Get value of GPT_CR_DBGEN from a register value.
#define BG_GPT_CR_DBGEN(r)   (((r) & BM_GPT_CR_DBGEN) >> BP_GPT_CR_DBGEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_DBGEN.
#define BF_GPT_CR_DBGEN(v)   ((((reg32_t) v) << BP_GPT_CR_DBGEN) & BM_GPT_CR_DBGEN)
#else
//! @brief Format value for bitfield GPT_CR_DBGEN.
#define BF_GPT_CR_DBGEN(v)   (((v) << BP_GPT_CR_DBGEN) & BM_GPT_CR_DBGEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_GPT_CR_DBGEN(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_DBGEN) | BF_GPT_CR_DBGEN(v)))
#endif


/* --- Register HW_GPT_CR, field WAITEN[3] (RW)
 *
 * GPT Wait Mode enable. The WAITEN read/write control bit enables GPT operation during Wait mode .
 * A hardware reset resets the WAITEN bit. A software reset does not affect the WAITEN bit.
 *
 * Values:
 * 0 - GPT is disabled in wait mode.
 * 1 - GPT is enabled in wait mode.
 */

#define BP_GPT_CR_WAITEN      (3)      //!< Bit position for GPT_CR_WAITEN.
#define BM_GPT_CR_WAITEN      (0x00000008)  //!< Bit mask for GPT_CR_WAITEN.

//! @brief Get value of GPT_CR_WAITEN from a register value.
#define BG_GPT_CR_WAITEN(r)   (((r) & BM_GPT_CR_WAITEN) >> BP_GPT_CR_WAITEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_WAITEN.
#define BF_GPT_CR_WAITEN(v)   ((((reg32_t) v) << BP_GPT_CR_WAITEN) & BM_GPT_CR_WAITEN)
#else
//! @brief Format value for bitfield GPT_CR_WAITEN.
#define BF_GPT_CR_WAITEN(v)   (((v) << BP_GPT_CR_WAITEN) & BM_GPT_CR_WAITEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAITEN field to a new value.
#define BW_GPT_CR_WAITEN(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_WAITEN) | BF_GPT_CR_WAITEN(v)))
#endif


/* --- Register HW_GPT_CR, field DOZEEN[4] (RW)
 *
 * GPT Doze Mode Enable. A hardware reset resets the DOZEEN bit. A software reset does not affect
 * the DOZEEN bit.
 *
 * Values:
 * 0 - GPT is disabled in doze mode.
 * 1 - GPT is enabled in doze mode.
 */

#define BP_GPT_CR_DOZEEN      (4)      //!< Bit position for GPT_CR_DOZEEN.
#define BM_GPT_CR_DOZEEN      (0x00000010)  //!< Bit mask for GPT_CR_DOZEEN.

//! @brief Get value of GPT_CR_DOZEEN from a register value.
#define BG_GPT_CR_DOZEEN(r)   (((r) & BM_GPT_CR_DOZEEN) >> BP_GPT_CR_DOZEEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_DOZEEN.
#define BF_GPT_CR_DOZEEN(v)   ((((reg32_t) v) << BP_GPT_CR_DOZEEN) & BM_GPT_CR_DOZEEN)
#else
//! @brief Format value for bitfield GPT_CR_DOZEEN.
#define BF_GPT_CR_DOZEEN(v)   (((v) << BP_GPT_CR_DOZEEN) & BM_GPT_CR_DOZEEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOZEEN field to a new value.
#define BW_GPT_CR_DOZEEN(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_DOZEEN) | BF_GPT_CR_DOZEEN(v)))
#endif


/* --- Register HW_GPT_CR, field STOPEN[5] (RW)
 *
 * GPT Stop Mode enable. The STOPEN read/write control bit enables GPT operation during Stop mode .
 * A hardware reset resets the STOPEN bit. A software reset does not affect the STOPEN bit.
 *
 * Values:
 * 0 - GPT is disabled in Stop mode.
 * 1 - GPT is enabled in Stop mode.
 */

#define BP_GPT_CR_STOPEN      (5)      //!< Bit position for GPT_CR_STOPEN.
#define BM_GPT_CR_STOPEN      (0x00000020)  //!< Bit mask for GPT_CR_STOPEN.

//! @brief Get value of GPT_CR_STOPEN from a register value.
#define BG_GPT_CR_STOPEN(r)   (((r) & BM_GPT_CR_STOPEN) >> BP_GPT_CR_STOPEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_STOPEN.
#define BF_GPT_CR_STOPEN(v)   ((((reg32_t) v) << BP_GPT_CR_STOPEN) & BM_GPT_CR_STOPEN)
#else
//! @brief Format value for bitfield GPT_CR_STOPEN.
#define BF_GPT_CR_STOPEN(v)   (((v) << BP_GPT_CR_STOPEN) & BM_GPT_CR_STOPEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOPEN field to a new value.
#define BW_GPT_CR_STOPEN(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_STOPEN) | BF_GPT_CR_STOPEN(v)))
#endif


/* --- Register HW_GPT_CR, field CLKSRC[8:6] (RW)
 *
 * Clock Source select. The CLKSRC bits select which clock will go to the prescaler (and
 * subsequently be used to run the GPT counter). The CLKSRC bit field value should only be changed
 * after disabling the GPT by clearing the EN bit in this register (GPT_CR). A software reset does
 * not affect the CLKSRC bit. For other programming requirements to change the clock source, see
 * section .
 *
 * Values:
 * 000 - No clock
 * 001 - Peripheral Clock (ipg_clk)
 * 010 - High Frequency Reference Clock (ipg_clk_highfreq)
 * 011 - External Clock ( IND_ CLKIN) (ipp_ind_clkin, external clock from pad)
 * 100 - Low Frequency Reference Clock (ipg_clk_32k)
 * 101 - Crystal oscillator divided by 8 as Reference Clock (ipg_clk_24M)
 * 111 - Crystal oscillator as Reference Clock (ipg_clk_24M)
 * others - Reserved
 */

#define BP_GPT_CR_CLKSRC      (6)      //!< Bit position for GPT_CR_CLKSRC.
#define BM_GPT_CR_CLKSRC      (0x000001c0)  //!< Bit mask for GPT_CR_CLKSRC.

//! @brief Get value of GPT_CR_CLKSRC from a register value.
#define BG_GPT_CR_CLKSRC(r)   (((r) & BM_GPT_CR_CLKSRC) >> BP_GPT_CR_CLKSRC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_CLKSRC.
#define BF_GPT_CR_CLKSRC(v)   ((((reg32_t) v) << BP_GPT_CR_CLKSRC) & BM_GPT_CR_CLKSRC)
#else
//! @brief Format value for bitfield GPT_CR_CLKSRC.
#define BF_GPT_CR_CLKSRC(v)   (((v) << BP_GPT_CR_CLKSRC) & BM_GPT_CR_CLKSRC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKSRC field to a new value.
#define BW_GPT_CR_CLKSRC(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_CLKSRC) | BF_GPT_CR_CLKSRC(v)))
#endif


/* --- Register HW_GPT_CR, field FRR[9] (RW)
 *
 * Free-Run or Restart mode. The FFR bit determines the behavior of the GPT when a compare event in
 * channel 1 occurs. In Restart mode, after a compare event, the counter resets to 0x00000000 and
 * resumes counting (after the occurrence of a compare event). In Free-Run mode, after a compare
 * event, the counter continues counting until 0xFFFFFFFF and then rolls over to 0.
 *
 * Values:
 * 0 - Restart mode
 * 1 - Free-Run mode
 */

#define BP_GPT_CR_FRR      (9)      //!< Bit position for GPT_CR_FRR.
#define BM_GPT_CR_FRR      (0x00000200)  //!< Bit mask for GPT_CR_FRR.

//! @brief Get value of GPT_CR_FRR from a register value.
#define BG_GPT_CR_FRR(r)   (((r) & BM_GPT_CR_FRR) >> BP_GPT_CR_FRR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_FRR.
#define BF_GPT_CR_FRR(v)   ((((reg32_t) v) << BP_GPT_CR_FRR) & BM_GPT_CR_FRR)
#else
//! @brief Format value for bitfield GPT_CR_FRR.
#define BF_GPT_CR_FRR(v)   (((v) << BP_GPT_CR_FRR) & BM_GPT_CR_FRR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRR field to a new value.
#define BW_GPT_CR_FRR(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_FRR) | BF_GPT_CR_FRR(v)))
#endif


/* --- Register HW_GPT_CR, field SWR[15] (RW)
 *
 * Software reset. This is the software reset of the GPT module. It is a self-clearing bit. The SWR
 * bit is set when the module is in reset state. The SWR bit is cleared when the reset procedure
 * finishes. Setting the SWR bit resets all of the registers to their default reset values, except
 * for the CLKSRC, EN, ENMOD, STOPEN, WAITEN, and DBGEN bits in the GPT Control Register (this
 * control register).
 *
 * Values:
 * 0 - GPT is not in reset state
 * 1 - GPT is in reset state
 */

#define BP_GPT_CR_SWR      (15)      //!< Bit position for GPT_CR_SWR.
#define BM_GPT_CR_SWR      (0x00008000)  //!< Bit mask for GPT_CR_SWR.

//! @brief Get value of GPT_CR_SWR from a register value.
#define BG_GPT_CR_SWR(r)   (((r) & BM_GPT_CR_SWR) >> BP_GPT_CR_SWR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_SWR.
#define BF_GPT_CR_SWR(v)   ((((reg32_t) v) << BP_GPT_CR_SWR) & BM_GPT_CR_SWR)
#else
//! @brief Format value for bitfield GPT_CR_SWR.
#define BF_GPT_CR_SWR(v)   (((v) << BP_GPT_CR_SWR) & BM_GPT_CR_SWR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_GPT_CR_SWR(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_SWR) | BF_GPT_CR_SWR(v)))
#endif


/* --- Register HW_GPT_CR, field IM1[17:16] (RW)
 *
 * See IM2
 */

#define BP_GPT_CR_IM1      (16)      //!< Bit position for GPT_CR_IM1.
#define BM_GPT_CR_IM1      (0x00030000)  //!< Bit mask for GPT_CR_IM1.

//! @brief Get value of GPT_CR_IM1 from a register value.
#define BG_GPT_CR_IM1(r)   (((r) & BM_GPT_CR_IM1) >> BP_GPT_CR_IM1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_IM1.
#define BF_GPT_CR_IM1(v)   ((((reg32_t) v) << BP_GPT_CR_IM1) & BM_GPT_CR_IM1)
#else
//! @brief Format value for bitfield GPT_CR_IM1.
#define BF_GPT_CR_IM1(v)   (((v) << BP_GPT_CR_IM1) & BM_GPT_CR_IM1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IM1 field to a new value.
#define BW_GPT_CR_IM1(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_IM1) | BF_GPT_CR_IM1(v)))
#endif

/* --- Register HW_GPT_CR, field IM2[19:18] (RW)
 *
 * IM2 (bits 19-18, Input Capture Channel 2 operating mode) IM1 (bits 17-16, Input Capture Channel 1
 * operating mode) The IM n bit field determines the transition on the input pin (for Input capture
 * channel n ), which will trigger a capture event.
 *
 * Values:
 * 00 - capture disabled
 * 01 - capture on rising edge only
 * 10 - capture on falling edge only
 * 11 - capture on both edges
 */

#define BP_GPT_CR_IM2      (18)      //!< Bit position for GPT_CR_IM2.
#define BM_GPT_CR_IM2      (0x000c0000)  //!< Bit mask for GPT_CR_IM2.

//! @brief Get value of GPT_CR_IM2 from a register value.
#define BG_GPT_CR_IM2(r)   (((r) & BM_GPT_CR_IM2) >> BP_GPT_CR_IM2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_IM2.
#define BF_GPT_CR_IM2(v)   ((((reg32_t) v) << BP_GPT_CR_IM2) & BM_GPT_CR_IM2)
#else
//! @brief Format value for bitfield GPT_CR_IM2.
#define BF_GPT_CR_IM2(v)   (((v) << BP_GPT_CR_IM2) & BM_GPT_CR_IM2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IM2 field to a new value.
#define BW_GPT_CR_IM2(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_IM2) | BF_GPT_CR_IM2(v)))
#endif


/* --- Register HW_GPT_CR, field OM1[22:20] (RW)
 *
 * See OM3
 */

#define BP_GPT_CR_OM1      (20)      //!< Bit position for GPT_CR_OM1.
#define BM_GPT_CR_OM1      (0x00700000)  //!< Bit mask for GPT_CR_OM1.

//! @brief Get value of GPT_CR_OM1 from a register value.
#define BG_GPT_CR_OM1(r)   (((r) & BM_GPT_CR_OM1) >> BP_GPT_CR_OM1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_OM1.
#define BF_GPT_CR_OM1(v)   ((((reg32_t) v) << BP_GPT_CR_OM1) & BM_GPT_CR_OM1)
#else
//! @brief Format value for bitfield GPT_CR_OM1.
#define BF_GPT_CR_OM1(v)   (((v) << BP_GPT_CR_OM1) & BM_GPT_CR_OM1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OM1 field to a new value.
#define BW_GPT_CR_OM1(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_OM1) | BF_GPT_CR_OM1(v)))
#endif

/* --- Register HW_GPT_CR, field OM2[25:23] (RW)
 *
 * See OM3
 */

#define BP_GPT_CR_OM2      (23)      //!< Bit position for GPT_CR_OM2.
#define BM_GPT_CR_OM2      (0x03800000)  //!< Bit mask for GPT_CR_OM2.

//! @brief Get value of GPT_CR_OM2 from a register value.
#define BG_GPT_CR_OM2(r)   (((r) & BM_GPT_CR_OM2) >> BP_GPT_CR_OM2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_OM2.
#define BF_GPT_CR_OM2(v)   ((((reg32_t) v) << BP_GPT_CR_OM2) & BM_GPT_CR_OM2)
#else
//! @brief Format value for bitfield GPT_CR_OM2.
#define BF_GPT_CR_OM2(v)   (((v) << BP_GPT_CR_OM2) & BM_GPT_CR_OM2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OM2 field to a new value.
#define BW_GPT_CR_OM2(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_OM2) | BF_GPT_CR_OM2(v)))
#endif

/* --- Register HW_GPT_CR, field OM3[28:26] (RW)
 *
 * OM3 (bits 28-26) controls the Output Compare Channel 3 operating mode. OM2 (bits 25-23) controls
 * the Output Compare Channel 2 operating mode. OM1 (bits 22-20) controls the Output Compare Channel
 * 1 operating mode. The OM n bits specify the response that a compare event will generate on the
 * output pin of Output Compare Channel n . The toggle, clear, and set options cause a change on the
 * output pin only if a compare event occurs. When OM n is programmed as 1xx (active low pulse), the
 * output pin is set to one immediately on the next input clock; a low pulse (that is an input clock
 * in width) occurs when there is a compare event. Note that here, "input clock" refers to the clock
 * selected by the CLKSRC bits of the GPT Control Register.
 *
 * Values:
 * 000 - Output disconnected. No response on pin.
 * 001 - Toggle output pin
 * 010 - Clear output pin
 * 011 - Set output pin
 * 1xx - Generate an active low pulse (that is one input clock wide) on the output pin.
 */

#define BP_GPT_CR_OM3      (26)      //!< Bit position for GPT_CR_OM3.
#define BM_GPT_CR_OM3      (0x1c000000)  //!< Bit mask for GPT_CR_OM3.

//! @brief Get value of GPT_CR_OM3 from a register value.
#define BG_GPT_CR_OM3(r)   (((r) & BM_GPT_CR_OM3) >> BP_GPT_CR_OM3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_OM3.
#define BF_GPT_CR_OM3(v)   ((((reg32_t) v) << BP_GPT_CR_OM3) & BM_GPT_CR_OM3)
#else
//! @brief Format value for bitfield GPT_CR_OM3.
#define BF_GPT_CR_OM3(v)   (((v) << BP_GPT_CR_OM3) & BM_GPT_CR_OM3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OM3 field to a new value.
#define BW_GPT_CR_OM3(v)   (HW_GPT_CR_WR((HW_GPT_CR_RD() & ~BM_GPT_CR_OM3) | BF_GPT_CR_OM3(v)))
#endif


/* --- Register HW_GPT_CR, field FO1[29] (WORZ)
 *
 * See F03
 */

#define BP_GPT_CR_FO1      (29)      //!< Bit position for GPT_CR_FO1.
#define BM_GPT_CR_FO1      (0x20000000)  //!< Bit mask for GPT_CR_FO1.

//! @brief Get value of GPT_CR_FO1 from a register value.
#define BG_GPT_CR_FO1(r)   (((r) & BM_GPT_CR_FO1) >> BP_GPT_CR_FO1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_FO1.
#define BF_GPT_CR_FO1(v)   ((((reg32_t) v) << BP_GPT_CR_FO1) & BM_GPT_CR_FO1)
#else
//! @brief Format value for bitfield GPT_CR_FO1.
#define BF_GPT_CR_FO1(v)   (((v) << BP_GPT_CR_FO1) & BM_GPT_CR_FO1)
#endif

/* --- Register HW_GPT_CR, field FO2[30] (WORZ)
 *
 * See F03
 */

#define BP_GPT_CR_FO2      (30)      //!< Bit position for GPT_CR_FO2.
#define BM_GPT_CR_FO2      (0x40000000)  //!< Bit mask for GPT_CR_FO2.

//! @brief Get value of GPT_CR_FO2 from a register value.
#define BG_GPT_CR_FO2(r)   (((r) & BM_GPT_CR_FO2) >> BP_GPT_CR_FO2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_FO2.
#define BF_GPT_CR_FO2(v)   ((((reg32_t) v) << BP_GPT_CR_FO2) & BM_GPT_CR_FO2)
#else
//! @brief Format value for bitfield GPT_CR_FO2.
#define BF_GPT_CR_FO2(v)   (((v) << BP_GPT_CR_FO2) & BM_GPT_CR_FO2)
#endif

/* --- Register HW_GPT_CR, field FO3[31] (WORZ)
 *
 * FO3 Force Output Compare Channel 3 FO2 Force Output Compare Channel 2 FO1 Force Output Compare
 * Channel 1 The FO n bit causes the pin action programmed for the timer Output Compare n pin
 * (according to the OM n bits in this register). The OF n flag (OF3, OF2, OF1) in the status
 * register is not affected . This bit is self-negating and always read as zero.
 *
 * Values:
 * 0 - Writing a 0 has no effect.
 * 1 - Causes the programmed pin action on the timer Output Compare n pin; the OF n flag is not set.
 */

#define BP_GPT_CR_FO3      (31)      //!< Bit position for GPT_CR_FO3.
#define BM_GPT_CR_FO3      (0x80000000)  //!< Bit mask for GPT_CR_FO3.

//! @brief Get value of GPT_CR_FO3 from a register value.
#define BG_GPT_CR_FO3(r)   (((r) & BM_GPT_CR_FO3) >> BP_GPT_CR_FO3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_CR_FO3.
#define BF_GPT_CR_FO3(v)   ((((reg32_t) v) << BP_GPT_CR_FO3) & BM_GPT_CR_FO3)
#else
//! @brief Format value for bitfield GPT_CR_FO3.
#define BF_GPT_CR_FO3(v)   (((v) << BP_GPT_CR_FO3) & BM_GPT_CR_FO3)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_PR - GPT Prescaler Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The GPT Prescaler Register (GPT_PR) contains bits that determine the divide value of the clock
 * that runs the counter.
 */
typedef union _hw_gpt_pr
{
    reg32_t U;
    struct _hw_gpt_pr_bitfields
    {
        unsigned PRESCALER : 12; //!< [11:0] Prescaler bits. The clock selected by the CLKSRC field is divided by [PRESCALER + 1], and then used to run the counter. A change in the value of the PRESCALER bits cause the Prescaler counter to reset and a new count period to start immediately. See for the timing diagram.
        unsigned RESERVED0 : 20; //!< [31:12] Reserved bits. Writing a value to these reserved bits will not affect GPT operations. These reserved bits are always read as zero.
    } B;
} hw_gpt_pr_t;
#endif

/*
 * constants & macros for entire GPT_PR register
 */
#define HW_GPT_PR_ADDR      (REGS_GPT_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_PR           (*(volatile hw_gpt_pr_t *) HW_GPT_PR_ADDR)
#define HW_GPT_PR_RD()      (HW_GPT_PR.U)
#define HW_GPT_PR_WR(v)     (HW_GPT_PR.U = (v))
#define HW_GPT_PR_SET(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() |  (v)))
#define HW_GPT_PR_CLR(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() & ~(v)))
#define HW_GPT_PR_TOG(v)    (HW_GPT_PR_WR(HW_GPT_PR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_PR bitfields
 */

/* --- Register HW_GPT_PR, field PRESCALER[11:0] (RW)
 *
 * Prescaler bits. The clock selected by the CLKSRC field is divided by [PRESCALER + 1], and then
 * used to run the counter. A change in the value of the PRESCALER bits cause the Prescaler counter
 * to reset and a new count period to start immediately. See for the timing diagram.
 *
 * Values:
 * 0x000 - Divide by 1
 * ... - ...
 * 0x001 - Divide by 2
 * 0xFFF - Divide by 4096
 */

#define BP_GPT_PR_PRESCALER      (0)      //!< Bit position for GPT_PR_PRESCALER.
#define BM_GPT_PR_PRESCALER      (0x00000fff)  //!< Bit mask for GPT_PR_PRESCALER.

//! @brief Get value of GPT_PR_PRESCALER from a register value.
#define BG_GPT_PR_PRESCALER(r)   (((r) & BM_GPT_PR_PRESCALER) >> BP_GPT_PR_PRESCALER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_PR_PRESCALER.
#define BF_GPT_PR_PRESCALER(v)   ((((reg32_t) v) << BP_GPT_PR_PRESCALER) & BM_GPT_PR_PRESCALER)
#else
//! @brief Format value for bitfield GPT_PR_PRESCALER.
#define BF_GPT_PR_PRESCALER(v)   (((v) << BP_GPT_PR_PRESCALER) & BM_GPT_PR_PRESCALER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESCALER field to a new value.
#define BW_GPT_PR_PRESCALER(v)   (HW_GPT_PR_WR((HW_GPT_PR_RD() & ~BM_GPT_PR_PRESCALER) | BF_GPT_PR_PRESCALER(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_SR - GPT Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The GPT Status Register (GPT_SR) contains bits that indicate that a counter has rolled over, and
 * if any event has occurred on the Input Capture and Output Compare channels. The bits are cleared
 * by writing a 1 to them.
 */
typedef union _hw_gpt_sr
{
    reg32_t U;
    struct _hw_gpt_sr_bitfields
    {
        unsigned OF1 : 1; //!< [0] See OF3
        unsigned OF2 : 1; //!< [1] See OF3
        unsigned OF3 : 1; //!< [2] OF3 Output Compare 3 Flag OF2 Output Compare 2 Flag OF1 Output Compare 1 Flag The OF n bit indicates that a compare event has occurred on Output Compare channel n .
        unsigned IF1 : 1; //!< [3] See IF2
        unsigned IF2 : 1; //!< [4] IF2 Input capture 2 Flag IF1 Input capture 1 Flag The IF n bit indicates that a capture event has occurred on Input Capture channel n .
        unsigned ROV : 1; //!< [5] Rollover Flag. The ROV bit indicates that the counter has reached its maximum possible value and rolled over to 0 (from which the counter continues counting). The ROV bit is only set if the counter has reached 0xFFFFFFFF in both Restart and Free-Run modes.
        unsigned RESERVED0 : 26; //!< [31:6] Reserved bits. Writing a value to these reserved bits will not affect GPT operations. These reserved bits are always read as zero.
    } B;
} hw_gpt_sr_t;
#endif

/*
 * constants & macros for entire GPT_SR register
 */
#define HW_GPT_SR_ADDR      (REGS_GPT_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_SR           (*(volatile hw_gpt_sr_t *) HW_GPT_SR_ADDR)
#define HW_GPT_SR_RD()      (HW_GPT_SR.U)
#define HW_GPT_SR_WR(v)     (HW_GPT_SR.U = (v))
#define HW_GPT_SR_SET(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() |  (v)))
#define HW_GPT_SR_CLR(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() & ~(v)))
#define HW_GPT_SR_TOG(v)    (HW_GPT_SR_WR(HW_GPT_SR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_SR bitfields
 */

/* --- Register HW_GPT_SR, field OF1[0] (W1C)
 *
 * See OF3
 */

#define BP_GPT_SR_OF1      (0)      //!< Bit position for GPT_SR_OF1.
#define BM_GPT_SR_OF1      (0x00000001)  //!< Bit mask for GPT_SR_OF1.

//! @brief Get value of GPT_SR_OF1 from a register value.
#define BG_GPT_SR_OF1(r)   (((r) & BM_GPT_SR_OF1) >> BP_GPT_SR_OF1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_OF1.
#define BF_GPT_SR_OF1(v)   ((((reg32_t) v) << BP_GPT_SR_OF1) & BM_GPT_SR_OF1)
#else
//! @brief Format value for bitfield GPT_SR_OF1.
#define BF_GPT_SR_OF1(v)   (((v) << BP_GPT_SR_OF1) & BM_GPT_SR_OF1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF1 field to a new value.
#define BW_GPT_SR_OF1(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_OF1) | BF_GPT_SR_OF1(v)))
#endif

/* --- Register HW_GPT_SR, field OF2[1] (W1C)
 *
 * See OF3
 */

#define BP_GPT_SR_OF2      (1)      //!< Bit position for GPT_SR_OF2.
#define BM_GPT_SR_OF2      (0x00000002)  //!< Bit mask for GPT_SR_OF2.

//! @brief Get value of GPT_SR_OF2 from a register value.
#define BG_GPT_SR_OF2(r)   (((r) & BM_GPT_SR_OF2) >> BP_GPT_SR_OF2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_OF2.
#define BF_GPT_SR_OF2(v)   ((((reg32_t) v) << BP_GPT_SR_OF2) & BM_GPT_SR_OF2)
#else
//! @brief Format value for bitfield GPT_SR_OF2.
#define BF_GPT_SR_OF2(v)   (((v) << BP_GPT_SR_OF2) & BM_GPT_SR_OF2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF2 field to a new value.
#define BW_GPT_SR_OF2(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_OF2) | BF_GPT_SR_OF2(v)))
#endif

/* --- Register HW_GPT_SR, field OF3[2] (W1C)
 *
 * OF3 Output Compare 3 Flag OF2 Output Compare 2 Flag OF1 Output Compare 1 Flag The OF n bit
 * indicates that a compare event has occurred on Output Compare channel n .
 *
 * Values:
 * 0 - Compare event has not occurred.
 * 1 - Compare event has occurred.
 */

#define BP_GPT_SR_OF3      (2)      //!< Bit position for GPT_SR_OF3.
#define BM_GPT_SR_OF3      (0x00000004)  //!< Bit mask for GPT_SR_OF3.

//! @brief Get value of GPT_SR_OF3 from a register value.
#define BG_GPT_SR_OF3(r)   (((r) & BM_GPT_SR_OF3) >> BP_GPT_SR_OF3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_OF3.
#define BF_GPT_SR_OF3(v)   ((((reg32_t) v) << BP_GPT_SR_OF3) & BM_GPT_SR_OF3)
#else
//! @brief Format value for bitfield GPT_SR_OF3.
#define BF_GPT_SR_OF3(v)   (((v) << BP_GPT_SR_OF3) & BM_GPT_SR_OF3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF3 field to a new value.
#define BW_GPT_SR_OF3(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_OF3) | BF_GPT_SR_OF3(v)))
#endif


/* --- Register HW_GPT_SR, field IF1[3] (W1C)
 *
 * See IF2
 */

#define BP_GPT_SR_IF1      (3)      //!< Bit position for GPT_SR_IF1.
#define BM_GPT_SR_IF1      (0x00000008)  //!< Bit mask for GPT_SR_IF1.

//! @brief Get value of GPT_SR_IF1 from a register value.
#define BG_GPT_SR_IF1(r)   (((r) & BM_GPT_SR_IF1) >> BP_GPT_SR_IF1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_IF1.
#define BF_GPT_SR_IF1(v)   ((((reg32_t) v) << BP_GPT_SR_IF1) & BM_GPT_SR_IF1)
#else
//! @brief Format value for bitfield GPT_SR_IF1.
#define BF_GPT_SR_IF1(v)   (((v) << BP_GPT_SR_IF1) & BM_GPT_SR_IF1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IF1 field to a new value.
#define BW_GPT_SR_IF1(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_IF1) | BF_GPT_SR_IF1(v)))
#endif

/* --- Register HW_GPT_SR, field IF2[4] (W1C)
 *
 * IF2 Input capture 2 Flag IF1 Input capture 1 Flag The IF n bit indicates that a capture event has
 * occurred on Input Capture channel n .
 *
 * Values:
 * 0 - Capture event has not occurred.
 * 1 - Capture event has occurred.
 */

#define BP_GPT_SR_IF2      (4)      //!< Bit position for GPT_SR_IF2.
#define BM_GPT_SR_IF2      (0x00000010)  //!< Bit mask for GPT_SR_IF2.

//! @brief Get value of GPT_SR_IF2 from a register value.
#define BG_GPT_SR_IF2(r)   (((r) & BM_GPT_SR_IF2) >> BP_GPT_SR_IF2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_IF2.
#define BF_GPT_SR_IF2(v)   ((((reg32_t) v) << BP_GPT_SR_IF2) & BM_GPT_SR_IF2)
#else
//! @brief Format value for bitfield GPT_SR_IF2.
#define BF_GPT_SR_IF2(v)   (((v) << BP_GPT_SR_IF2) & BM_GPT_SR_IF2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IF2 field to a new value.
#define BW_GPT_SR_IF2(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_IF2) | BF_GPT_SR_IF2(v)))
#endif


/* --- Register HW_GPT_SR, field ROV[5] (W1C)
 *
 * Rollover Flag. The ROV bit indicates that the counter has reached its maximum possible value and
 * rolled over to 0 (from which the counter continues counting). The ROV bit is only set if the
 * counter has reached 0xFFFFFFFF in both Restart and Free-Run modes.
 *
 * Values:
 * 0 - Rollover has not occurred.
 * 1 - Rollover has occurred.
 */

#define BP_GPT_SR_ROV      (5)      //!< Bit position for GPT_SR_ROV.
#define BM_GPT_SR_ROV      (0x00000020)  //!< Bit mask for GPT_SR_ROV.

//! @brief Get value of GPT_SR_ROV from a register value.
#define BG_GPT_SR_ROV(r)   (((r) & BM_GPT_SR_ROV) >> BP_GPT_SR_ROV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_SR_ROV.
#define BF_GPT_SR_ROV(v)   ((((reg32_t) v) << BP_GPT_SR_ROV) & BM_GPT_SR_ROV)
#else
//! @brief Format value for bitfield GPT_SR_ROV.
#define BF_GPT_SR_ROV(v)   (((v) << BP_GPT_SR_ROV) & BM_GPT_SR_ROV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROV field to a new value.
#define BW_GPT_SR_ROV(v)   (HW_GPT_SR_WR((HW_GPT_SR_RD() & ~BM_GPT_SR_ROV) | BF_GPT_SR_ROV(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_IR - GPT Interrupt Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The GPT Interrupt Register (GPT_IR) contains bits that control whether interrupts are generated
 * after rollover, input capture and output compare events.
 */
typedef union _hw_gpt_ir
{
    reg32_t U;
    struct _hw_gpt_ir_bitfields
    {
        unsigned OF1IE : 1; //!< [0] See OF3IE
        unsigned OF2IE : 1; //!< [1] See OF3IE
        unsigned OF3IE : 1; //!< [2] OF3IE Output Compare 3 Interrupt Enable OF2IE Output Compare 2 Interrupt Enable OF1IE Output Compare 1 Interrupt Enable The OF n IE bit controls the Output Compare Channel n interrupt.
        unsigned IF1IE : 1; //!< [3] See IF2IE
        unsigned IF2IE : 1; //!< [4] IF2IE Input capture 2 Interrupt Enable IF1IE Input capture 1 Interrupt Enable The IF n IE bit controls the IF n IE Input Capture n Interrupt Enable.
        unsigned ROVIE : 1; //!< [5] Rollover Interrupt Enable. The ROVIE bit controls the Rollover interrupt.
        unsigned RESERVED0 : 26; //!< [31:6] Reserved bits. Writing a value to these reserved bits will not affect GPT operations. These reserved bits are always read as zero.
    } B;
} hw_gpt_ir_t;
#endif

/*
 * constants & macros for entire GPT_IR register
 */
#define HW_GPT_IR_ADDR      (REGS_GPT_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_IR           (*(volatile hw_gpt_ir_t *) HW_GPT_IR_ADDR)
#define HW_GPT_IR_RD()      (HW_GPT_IR.U)
#define HW_GPT_IR_WR(v)     (HW_GPT_IR.U = (v))
#define HW_GPT_IR_SET(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() |  (v)))
#define HW_GPT_IR_CLR(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() & ~(v)))
#define HW_GPT_IR_TOG(v)    (HW_GPT_IR_WR(HW_GPT_IR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_IR bitfields
 */

/* --- Register HW_GPT_IR, field OF1IE[0] (RW)
 *
 * See OF3IE
 */

#define BP_GPT_IR_OF1IE      (0)      //!< Bit position for GPT_IR_OF1IE.
#define BM_GPT_IR_OF1IE      (0x00000001)  //!< Bit mask for GPT_IR_OF1IE.

//! @brief Get value of GPT_IR_OF1IE from a register value.
#define BG_GPT_IR_OF1IE(r)   (((r) & BM_GPT_IR_OF1IE) >> BP_GPT_IR_OF1IE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_OF1IE.
#define BF_GPT_IR_OF1IE(v)   ((((reg32_t) v) << BP_GPT_IR_OF1IE) & BM_GPT_IR_OF1IE)
#else
//! @brief Format value for bitfield GPT_IR_OF1IE.
#define BF_GPT_IR_OF1IE(v)   (((v) << BP_GPT_IR_OF1IE) & BM_GPT_IR_OF1IE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF1IE field to a new value.
#define BW_GPT_IR_OF1IE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_OF1IE) | BF_GPT_IR_OF1IE(v)))
#endif

/* --- Register HW_GPT_IR, field OF2IE[1] (RW)
 *
 * See OF3IE
 */

#define BP_GPT_IR_OF2IE      (1)      //!< Bit position for GPT_IR_OF2IE.
#define BM_GPT_IR_OF2IE      (0x00000002)  //!< Bit mask for GPT_IR_OF2IE.

//! @brief Get value of GPT_IR_OF2IE from a register value.
#define BG_GPT_IR_OF2IE(r)   (((r) & BM_GPT_IR_OF2IE) >> BP_GPT_IR_OF2IE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_OF2IE.
#define BF_GPT_IR_OF2IE(v)   ((((reg32_t) v) << BP_GPT_IR_OF2IE) & BM_GPT_IR_OF2IE)
#else
//! @brief Format value for bitfield GPT_IR_OF2IE.
#define BF_GPT_IR_OF2IE(v)   (((v) << BP_GPT_IR_OF2IE) & BM_GPT_IR_OF2IE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF2IE field to a new value.
#define BW_GPT_IR_OF2IE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_OF2IE) | BF_GPT_IR_OF2IE(v)))
#endif

/* --- Register HW_GPT_IR, field OF3IE[2] (RW)
 *
 * OF3IE Output Compare 3 Interrupt Enable OF2IE Output Compare 2 Interrupt Enable OF1IE Output
 * Compare 1 Interrupt Enable The OF n IE bit controls the Output Compare Channel n interrupt.
 *
 * Values:
 * 0 - Output Compare Channel n interrupt is disabled.
 * 1 - Output Compare Channel n interrupt is enabled.
 */

#define BP_GPT_IR_OF3IE      (2)      //!< Bit position for GPT_IR_OF3IE.
#define BM_GPT_IR_OF3IE      (0x00000004)  //!< Bit mask for GPT_IR_OF3IE.

//! @brief Get value of GPT_IR_OF3IE from a register value.
#define BG_GPT_IR_OF3IE(r)   (((r) & BM_GPT_IR_OF3IE) >> BP_GPT_IR_OF3IE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_OF3IE.
#define BF_GPT_IR_OF3IE(v)   ((((reg32_t) v) << BP_GPT_IR_OF3IE) & BM_GPT_IR_OF3IE)
#else
//! @brief Format value for bitfield GPT_IR_OF3IE.
#define BF_GPT_IR_OF3IE(v)   (((v) << BP_GPT_IR_OF3IE) & BM_GPT_IR_OF3IE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF3IE field to a new value.
#define BW_GPT_IR_OF3IE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_OF3IE) | BF_GPT_IR_OF3IE(v)))
#endif


/* --- Register HW_GPT_IR, field IF1IE[3] (RW)
 *
 * See IF2IE
 */

#define BP_GPT_IR_IF1IE      (3)      //!< Bit position for GPT_IR_IF1IE.
#define BM_GPT_IR_IF1IE      (0x00000008)  //!< Bit mask for GPT_IR_IF1IE.

//! @brief Get value of GPT_IR_IF1IE from a register value.
#define BG_GPT_IR_IF1IE(r)   (((r) & BM_GPT_IR_IF1IE) >> BP_GPT_IR_IF1IE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_IF1IE.
#define BF_GPT_IR_IF1IE(v)   ((((reg32_t) v) << BP_GPT_IR_IF1IE) & BM_GPT_IR_IF1IE)
#else
//! @brief Format value for bitfield GPT_IR_IF1IE.
#define BF_GPT_IR_IF1IE(v)   (((v) << BP_GPT_IR_IF1IE) & BM_GPT_IR_IF1IE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IF1IE field to a new value.
#define BW_GPT_IR_IF1IE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_IF1IE) | BF_GPT_IR_IF1IE(v)))
#endif

/* --- Register HW_GPT_IR, field IF2IE[4] (RW)
 *
 * IF2IE Input capture 2 Interrupt Enable IF1IE Input capture 1 Interrupt Enable The IF n IE bit
 * controls the IF n IE Input Capture n Interrupt Enable.
 *
 * Values:
 * 0 - IF2IE Input Capture n Interrupt Enable is disabled.
 * 1 - IF2IE Input Capture n Interrupt Enable is enabled.
 */

#define BP_GPT_IR_IF2IE      (4)      //!< Bit position for GPT_IR_IF2IE.
#define BM_GPT_IR_IF2IE      (0x00000010)  //!< Bit mask for GPT_IR_IF2IE.

//! @brief Get value of GPT_IR_IF2IE from a register value.
#define BG_GPT_IR_IF2IE(r)   (((r) & BM_GPT_IR_IF2IE) >> BP_GPT_IR_IF2IE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_IF2IE.
#define BF_GPT_IR_IF2IE(v)   ((((reg32_t) v) << BP_GPT_IR_IF2IE) & BM_GPT_IR_IF2IE)
#else
//! @brief Format value for bitfield GPT_IR_IF2IE.
#define BF_GPT_IR_IF2IE(v)   (((v) << BP_GPT_IR_IF2IE) & BM_GPT_IR_IF2IE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IF2IE field to a new value.
#define BW_GPT_IR_IF2IE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_IF2IE) | BF_GPT_IR_IF2IE(v)))
#endif


/* --- Register HW_GPT_IR, field ROVIE[5] (RW)
 *
 * Rollover Interrupt Enable. The ROVIE bit controls the Rollover interrupt.
 *
 * Values:
 * 0 - Rollover interrupt is disabled.
 * 1 - Rollover interrupt enabled.
 */

#define BP_GPT_IR_ROVIE      (5)      //!< Bit position for GPT_IR_ROVIE.
#define BM_GPT_IR_ROVIE      (0x00000020)  //!< Bit mask for GPT_IR_ROVIE.

//! @brief Get value of GPT_IR_ROVIE from a register value.
#define BG_GPT_IR_ROVIE(r)   (((r) & BM_GPT_IR_ROVIE) >> BP_GPT_IR_ROVIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_IR_ROVIE.
#define BF_GPT_IR_ROVIE(v)   ((((reg32_t) v) << BP_GPT_IR_ROVIE) & BM_GPT_IR_ROVIE)
#else
//! @brief Format value for bitfield GPT_IR_ROVIE.
#define BF_GPT_IR_ROVIE(v)   (((v) << BP_GPT_IR_ROVIE) & BM_GPT_IR_ROVIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROVIE field to a new value.
#define BW_GPT_IR_ROVIE(v)   (HW_GPT_IR_WR((HW_GPT_IR_RD() & ~BM_GPT_IR_ROVIE) | BF_GPT_IR_ROVIE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_OCR1 - GPT Output Compare Register 1 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The GPT Compare Register 1 (GPT_OCR1) holds the value that determines when a compare event will
 * be generated on Output Compare Channel 1. Any write access to the Compare register of Channel 1
 * while in Restart mode (FRR=0) will reset the GPT counter.  An IP Bus Write access to the GPT
 * Output Compare Register1 (GPT_OCR1) occurs after one cycle of wait state (ips_xfr_wait high for 1
 * cycle) ; an IP Bus Read access occurs immediately (0 wait states).
 */
typedef union _hw_gpt_ocr1
{
    reg32_t U;
    struct _hw_gpt_ocr1_bitfields
    {
        unsigned COMP : 32; //!< [31:0] Compare Value. When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 1.
    } B;
} hw_gpt_ocr1_t;
#endif

/*
 * constants & macros for entire GPT_OCR1 register
 */
#define HW_GPT_OCR1_ADDR      (REGS_GPT_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR1           (*(volatile hw_gpt_ocr1_t *) HW_GPT_OCR1_ADDR)
#define HW_GPT_OCR1_RD()      (HW_GPT_OCR1.U)
#define HW_GPT_OCR1_WR(v)     (HW_GPT_OCR1.U = (v))
#define HW_GPT_OCR1_SET(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() |  (v)))
#define HW_GPT_OCR1_CLR(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() & ~(v)))
#define HW_GPT_OCR1_TOG(v)    (HW_GPT_OCR1_WR(HW_GPT_OCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_OCR1 bitfields
 */

/* --- Register HW_GPT_OCR1, field COMP[31:0] (RW)
 *
 * Compare Value. When the counter value equals the COMP bit field value, a compare event is
 * generated on Output Compare Channel 1.
 */

#define BP_GPT_OCR1_COMP      (0)      //!< Bit position for GPT_OCR1_COMP.
#define BM_GPT_OCR1_COMP      (0xffffffff)  //!< Bit mask for GPT_OCR1_COMP.

//! @brief Get value of GPT_OCR1_COMP from a register value.
#define BG_GPT_OCR1_COMP(r)   (((r) & BM_GPT_OCR1_COMP) >> BP_GPT_OCR1_COMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_OCR1_COMP.
#define BF_GPT_OCR1_COMP(v)   ((((reg32_t) v) << BP_GPT_OCR1_COMP) & BM_GPT_OCR1_COMP)
#else
//! @brief Format value for bitfield GPT_OCR1_COMP.
#define BF_GPT_OCR1_COMP(v)   (((v) << BP_GPT_OCR1_COMP) & BM_GPT_OCR1_COMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMP field to a new value.
#define BW_GPT_OCR1_COMP(v)   (HW_GPT_OCR1_WR((HW_GPT_OCR1_RD() & ~BM_GPT_OCR1_COMP) | BF_GPT_OCR1_COMP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_OCR2 - GPT Output Compare Register 2 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The GPT Compare Register 2 (GPT_OCR2) holds the value that determines when a compare event will
 * be generated on Output Compare Channel 2.
 */
typedef union _hw_gpt_ocr2
{
    reg32_t U;
    struct _hw_gpt_ocr2_bitfields
    {
        unsigned COMP : 32; //!< [31:0] Compare Value. When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 2.
    } B;
} hw_gpt_ocr2_t;
#endif

/*
 * constants & macros for entire GPT_OCR2 register
 */
#define HW_GPT_OCR2_ADDR      (REGS_GPT_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR2           (*(volatile hw_gpt_ocr2_t *) HW_GPT_OCR2_ADDR)
#define HW_GPT_OCR2_RD()      (HW_GPT_OCR2.U)
#define HW_GPT_OCR2_WR(v)     (HW_GPT_OCR2.U = (v))
#define HW_GPT_OCR2_SET(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() |  (v)))
#define HW_GPT_OCR2_CLR(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() & ~(v)))
#define HW_GPT_OCR2_TOG(v)    (HW_GPT_OCR2_WR(HW_GPT_OCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_OCR2 bitfields
 */

/* --- Register HW_GPT_OCR2, field COMP[31:0] (RW)
 *
 * Compare Value. When the counter value equals the COMP bit field value, a compare event is
 * generated on Output Compare Channel 2.
 */

#define BP_GPT_OCR2_COMP      (0)      //!< Bit position for GPT_OCR2_COMP.
#define BM_GPT_OCR2_COMP      (0xffffffff)  //!< Bit mask for GPT_OCR2_COMP.

//! @brief Get value of GPT_OCR2_COMP from a register value.
#define BG_GPT_OCR2_COMP(r)   (((r) & BM_GPT_OCR2_COMP) >> BP_GPT_OCR2_COMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_OCR2_COMP.
#define BF_GPT_OCR2_COMP(v)   ((((reg32_t) v) << BP_GPT_OCR2_COMP) & BM_GPT_OCR2_COMP)
#else
//! @brief Format value for bitfield GPT_OCR2_COMP.
#define BF_GPT_OCR2_COMP(v)   (((v) << BP_GPT_OCR2_COMP) & BM_GPT_OCR2_COMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMP field to a new value.
#define BW_GPT_OCR2_COMP(v)   (HW_GPT_OCR2_WR((HW_GPT_OCR2_RD() & ~BM_GPT_OCR2_COMP) | BF_GPT_OCR2_COMP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_OCR3 - GPT Output Compare Register 3 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The GPT Compare Register 3 (GPT_OCR3) holds the value that determines when a compare event will
 * be generated on Output Compare Channel 3.
 */
typedef union _hw_gpt_ocr3
{
    reg32_t U;
    struct _hw_gpt_ocr3_bitfields
    {
        unsigned COMP : 32; //!< [31:0] Compare Value. When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 3.
    } B;
} hw_gpt_ocr3_t;
#endif

/*
 * constants & macros for entire GPT_OCR3 register
 */
#define HW_GPT_OCR3_ADDR      (REGS_GPT_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_OCR3           (*(volatile hw_gpt_ocr3_t *) HW_GPT_OCR3_ADDR)
#define HW_GPT_OCR3_RD()      (HW_GPT_OCR3.U)
#define HW_GPT_OCR3_WR(v)     (HW_GPT_OCR3.U = (v))
#define HW_GPT_OCR3_SET(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() |  (v)))
#define HW_GPT_OCR3_CLR(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() & ~(v)))
#define HW_GPT_OCR3_TOG(v)    (HW_GPT_OCR3_WR(HW_GPT_OCR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual GPT_OCR3 bitfields
 */

/* --- Register HW_GPT_OCR3, field COMP[31:0] (RW)
 *
 * Compare Value. When the counter value equals the COMP bit field value, a compare event is
 * generated on Output Compare Channel 3.
 */

#define BP_GPT_OCR3_COMP      (0)      //!< Bit position for GPT_OCR3_COMP.
#define BM_GPT_OCR3_COMP      (0xffffffff)  //!< Bit mask for GPT_OCR3_COMP.

//! @brief Get value of GPT_OCR3_COMP from a register value.
#define BG_GPT_OCR3_COMP(r)   (((r) & BM_GPT_OCR3_COMP) >> BP_GPT_OCR3_COMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield GPT_OCR3_COMP.
#define BF_GPT_OCR3_COMP(v)   ((((reg32_t) v) << BP_GPT_OCR3_COMP) & BM_GPT_OCR3_COMP)
#else
//! @brief Format value for bitfield GPT_OCR3_COMP.
#define BF_GPT_OCR3_COMP(v)   (((v) << BP_GPT_OCR3_COMP) & BM_GPT_OCR3_COMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMP field to a new value.
#define BW_GPT_OCR3_COMP(v)   (HW_GPT_OCR3_WR((HW_GPT_OCR3_RD() & ~BM_GPT_OCR3_COMP) | BF_GPT_OCR3_COMP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_ICR1 - GPT Input Capture Register 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * The GPT Input Capture Register 1 (GPT_ICR1) is a read-only register that holds the value that was
 * in the counter during the last capture event on Input Capture Channel 1.
 */
typedef union _hw_gpt_icr1
{
    reg32_t U;
    struct _hw_gpt_icr1_bitfields
    {
        unsigned CAPT : 32; //!< [31:0] Capture Value. After a capture event on Input Capture Channel 1 occurs, the current value of the counter is loaded into GPT Input Capture Register 1.
    } B;
} hw_gpt_icr1_t;
#endif

/*
 * constants & macros for entire GPT_ICR1 register
 */
#define HW_GPT_ICR1_ADDR      (REGS_GPT_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_ICR1           (*(volatile hw_gpt_icr1_t *) HW_GPT_ICR1_ADDR)
#define HW_GPT_ICR1_RD()      (HW_GPT_ICR1.U)
#endif

/*
 * constants & macros for individual GPT_ICR1 bitfields
 */

/* --- Register HW_GPT_ICR1, field CAPT[31:0] (RO)
 *
 * Capture Value. After a capture event on Input Capture Channel 1 occurs, the current value of the
 * counter is loaded into GPT Input Capture Register 1.
 */

#define BP_GPT_ICR1_CAPT      (0)      //!< Bit position for GPT_ICR1_CAPT.
#define BM_GPT_ICR1_CAPT      (0xffffffff)  //!< Bit mask for GPT_ICR1_CAPT.

//! @brief Get value of GPT_ICR1_CAPT from a register value.
#define BG_GPT_ICR1_CAPT(r)   (((r) & BM_GPT_ICR1_CAPT) >> BP_GPT_ICR1_CAPT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_ICR2 - GPT Input Capture Register 2 (RO)
 *
 * Reset value: 0x00000000
 *
 * The GPT Input capture Register 2 (GPT_ICR2) is a read-only register which holds the value that
 * was in the counter during the last capture event on input capture channel 2.
 */
typedef union _hw_gpt_icr2
{
    reg32_t U;
    struct _hw_gpt_icr2_bitfields
    {
        unsigned CAPT : 32; //!< [31:0] Capture Value. After a capture event on Input Capture Channel 2 occurs, the current value of the counter is loaded into GPT Input Capture Register 2.
    } B;
} hw_gpt_icr2_t;
#endif

/*
 * constants & macros for entire GPT_ICR2 register
 */
#define HW_GPT_ICR2_ADDR      (REGS_GPT_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_ICR2           (*(volatile hw_gpt_icr2_t *) HW_GPT_ICR2_ADDR)
#define HW_GPT_ICR2_RD()      (HW_GPT_ICR2.U)
#endif

/*
 * constants & macros for individual GPT_ICR2 bitfields
 */

/* --- Register HW_GPT_ICR2, field CAPT[31:0] (RO)
 *
 * Capture Value. After a capture event on Input Capture Channel 2 occurs, the current value of the
 * counter is loaded into GPT Input Capture Register 2.
 */

#define BP_GPT_ICR2_CAPT      (0)      //!< Bit position for GPT_ICR2_CAPT.
#define BM_GPT_ICR2_CAPT      (0xffffffff)  //!< Bit mask for GPT_ICR2_CAPT.

//! @brief Get value of GPT_ICR2_CAPT from a register value.
#define BG_GPT_ICR2_CAPT(r)   (((r) & BM_GPT_ICR2_CAPT) >> BP_GPT_ICR2_CAPT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPT_CNT - GPT Counter Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The GPT Counter Register (GPT_CNT) is the main counter's register. GPT_CNT is a read-only
 * register and can be read without affecting the counting process of the GPT.
 */
typedef union _hw_gpt_cnt
{
    reg32_t U;
    struct _hw_gpt_cnt_bitfields
    {
        unsigned COUNT : 32; //!< [31:0] Counter Value. The COUNT bits show the current count value of the GPT counter.
    } B;
} hw_gpt_cnt_t;
#endif

/*
 * constants & macros for entire GPT_CNT register
 */
#define HW_GPT_CNT_ADDR      (REGS_GPT_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_GPT_CNT           (*(volatile hw_gpt_cnt_t *) HW_GPT_CNT_ADDR)
#define HW_GPT_CNT_RD()      (HW_GPT_CNT.U)
#endif

/*
 * constants & macros for individual GPT_CNT bitfields
 */

/* --- Register HW_GPT_CNT, field COUNT[31:0] (RO)
 *
 * Counter Value. The COUNT bits show the current count value of the GPT counter.
 */

#define BP_GPT_CNT_COUNT      (0)      //!< Bit position for GPT_CNT_COUNT.
#define BM_GPT_CNT_COUNT      (0xffffffff)  //!< Bit mask for GPT_CNT_COUNT.

//! @brief Get value of GPT_CNT_COUNT from a register value.
#define BG_GPT_CNT_COUNT(r)   (((r) & BM_GPT_CNT_COUNT) >> BP_GPT_CNT_COUNT)


/*!
 * @brief All GPT module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_gpt
{
    volatile hw_gpt_cr_t CR; //!< GPT Control Register
    volatile hw_gpt_pr_t PR; //!< GPT Prescaler Register
    volatile hw_gpt_sr_t SR; //!< GPT Status Register
    volatile hw_gpt_ir_t IR; //!< GPT Interrupt Register
    volatile hw_gpt_ocr1_t OCR1; //!< GPT Output Compare Register 1
    volatile hw_gpt_ocr2_t OCR2; //!< GPT Output Compare Register 2
    volatile hw_gpt_ocr3_t OCR3; //!< GPT Output Compare Register 3
    volatile hw_gpt_icr1_t ICR1; //!< GPT Input Capture Register 1
    volatile hw_gpt_icr2_t ICR2; //!< GPT Input Capture Register 2
    volatile hw_gpt_cnt_t CNT; //!< GPT Counter Register
} hw_gpt_t;
#pragma pack()

//! @brief Macro to access all GPT registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPT(0)</code>.
#define HW_GPT     (*(volatile hw_gpt_t *) REGS_GPT_BASE)

#endif


#endif // __HW_GPT_REGISTERS_H__
