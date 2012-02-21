/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPT_H
#define _GPT_H

#include "regs.h"

#ifndef REGS_GPT_BASE
#define REGS_GPT_BASE (REGS_BASE + 0x02098000)
#endif


/*!
 * @brief HW_GPT_CR - GPT Control Register
 *
 * The GPT Control Register (GPT_CR) is used to program and configure GPT
 * operations. An IP Bus Write to the GPT Control Register occurs after one
 * cycle of wait state (ips_xfr_wait high for 1 cycle) , while an IP Bus Read occurs after 0 wait
 * states.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1; //!< GPT Enable.  The EN bit is the GPT module enable bit.  Before setting the EN bit , we recommend that all registers be properly programmed .   A hardware reset resets the EN bit.  A software reset does not affect the EN bit.
        unsigned ENMOD : 1; //!< GPT Enable mode.  When the GPT is disabled (EN=0), then both the Main Counter and Prescaler Counter freeze their current count values . The ENMOD bit determines the value of the GPT counter when Counter is enabled again (if the EN bit is set).   If the ENMOD bit is 1, then the Main Counter and Prescaler Counter values are reset to 0 after GPT is enabled (EN=1).  If the ENMOD bit is 0, then the Main Counter and Prescaler Counter restart counting from their frozen values after GPT is enabled (EN=1).    If GPT is programmed to be disabled in a low power mode (STOP/WAIT), then the Main Counter and Prescaler Counter freeze at their current count values when the GPT enters low power mode.  When GPT exits low power mode, the Main Counter and Prescaler Counter start counting from their frozen values, regardless of the ENMOD bit value.  Setting the SWR bit will clear the Main Counter and Prescaler Counter values, regardless of the value of EN or ENMOD bits.    A hardware reset resets the ENMOD bit.  A software reset does not affect the ENMOD bit.
        unsigned DBGEN : 1; //!< GPT debug mode enable.  The DBGEN read/write control bit enables GPT operation during Debug mode .   A hardware reset resets the DBGEN bit.  A software reset does not affect the DBGEN bit.
        unsigned WAITEN : 1; //!< GPT Wait Mode enable.  The WAITEN read/write control bit enables GPT operation during Wait mode .   A hardware reset resets the WAITEN bit.  A software reset does not affect the WAITEN bit.
        unsigned DOZEEN : 1; //!< GPT Doze Mode Enable.   A hardware reset resets the DOZEEN bit.  A software reset does not affect the DOZEEN bit.
        unsigned STOPEN : 1; //!< GPT Stop Mode enable.  The STOPEN read/write control bit enables GPT operation during Stop mode .   A hardware reset resets the STOPEN bit.  A software reset does not affect the STOPEN bit.
        unsigned CLKSRC : 3; //!< Clock Source select.  The CLKSRC bits select which clock will go to the prescaler (and subsequently be used to run the GPT counter).   The CLKSRC bit field value should only be changed after disabling the GPT by clearing the EN bit in this register (GPT_CR).  A software reset does not affect the CLKSRC bit.  For other programming requirements to change the clock source, see section .
        unsigned FRR : 1; //!< Free-Run or Restart mode.  The FFR bit determines the behavior of the GPT when a compare event in channel 1 occurs.   In Restart mode, after a compare event, the counter resets to 0x00000000 and resumes counting (after the occurrence of a compare event).  In Free-Run mode, after a compare event, the counter continues counting until 0xFFFFFFFF and then rolls over to 0.
        unsigned RESERVED0 : 5; //!< Reserved bits.   Writing a value to these reserved bits will not affect GPT operations.  These reserved bits are always read as zero.  It is recommended that all writes to these reserved bits be 0 (for forward compatibility).
        unsigned SWR : 1; //!< Software reset.  This is the software reset of the GPT module. It is a self-clearing bit.   The SWR bit is set when the module is in reset state.  The SWR bit is cleared when the reset procedure finishes.  Setting the SWR bit resets all of the registers to their default reset values, except for the CLKSRC, EN, ENMOD, STOPEN, WAITEN, and DBGEN bits in the GPT Control Register (this control register).
        unsigned IM1 : 2; //!< See IM2
        unsigned IM2 : 2; //!< IM2 (bits 19-18, Input Capture Channel 2 operating mode)  IM1 (bits 17-16, Input Capture Channel 1 operating mode)  The IM n bit field determines the transition on the input pin (for Input capture channel n ), which will trigger a capture event.
        unsigned OM1 : 3; //!< See OM3
        unsigned OM2 : 3; //!< See OM3
        unsigned OM3 : 3; //!< OM3 (bits 28-26) controls the Output Compare Channel 3 operating mode.  OM2 (bits 25-23) controls the Output Compare Channel 2 operating mode.  OM1 (bits 22-20) controls the Output Compare Channel 1 operating mode.  The OM n bits specify the response that a compare event will generate on the output pin of Output Compare Channel n .   The toggle, clear, and set options cause a change on the output pin only if a compare event occurs.  When OM n is programmed as 1xx (active low pulse), the output pin is set to one immediately on the next input clock; a low pulse (that is an input clock in width) occurs when there is a compare event. Note that here, "input clock" refers to the clock selected by the CLKSRC bits of the GPT Control Register.
        unsigned FO1 : 1; //!< See F03
        unsigned FO2 : 1; //!< See F03
        unsigned FO3 : 1; //!< FO3 Force Output Compare Channel 3  FO2 Force Output Compare Channel 2  FO1 Force Output Compare Channel 1  The FO n bit causes the pin action programmed for the timer Output Compare n pin (according to the OM n bits in this register).   The OF n flag (OF3, OF2, OF1) in the status register is not affected .  This bit is self-negating and always read as zero.
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

/* --- Register HW_GPT_CR, field EN
 *
 * GPT Enable.  The EN bit is the GPT module enable bit.  Before setting the EN bit , we recommend
 * that all registers be properly programmed .   A hardware reset resets the EN bit.  A software
 * reset does not affect the EN bit.
 */

#define BP_GPT_CR_EN      0
#define BM_GPT_CR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_EN(v)   ((((reg32_t) v) << 0) & BM_GPT_CR_EN)
#else
#define BF_GPT_CR_EN(v)   (((v) << 0) & BM_GPT_CR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_EN(v)   BF_CS1(GPT_CR, EN, v)
#endif

/* --- Register HW_GPT_CR, field ENMOD
 *
 * GPT Enable mode.  When the GPT is disabled (EN=0), then both the Main Counter and
 * Prescaler Counter freeze their current count values . The                                 ENMOD
 * bit determines the value of the GPT counter when Counter is
 * enabled again (if the EN bit is set).   If the ENMOD bit is 1, then the Main Counter and
 * Prescaler Counter values are reset to 0 after GPT is enabled (EN=1).  If the ENMOD bit is 0, then
 * the Main Counter and Prescaler Counter restart counting from their frozen values after GPT is
 * enabled (EN=1).    If GPT is programmed to be disabled in a low power mode (STOP/WAIT), then the
 * Main Counter and Prescaler Counter freeze at their current count values when the GPT enters low
 * power mode.  When GPT exits low power mode, the Main Counter and Prescaler Counter start counting
 * from their frozen values, regardless of the ENMOD bit value.  Setting the SWR bit will clear the
 * Main Counter and Prescaler Counter values, regardless of the value of EN or ENMOD bits.    A
 * hardware reset resets the ENMOD bit.  A software reset does not affect the ENMOD bit.
 */

#define BP_GPT_CR_ENMOD      1
#define BM_GPT_CR_ENMOD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_ENMOD(v)   ((((reg32_t) v) << 1) & BM_GPT_CR_ENMOD)
#else
#define BF_GPT_CR_ENMOD(v)   (((v) << 1) & BM_GPT_CR_ENMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_ENMOD(v)   BF_CS1(GPT_CR, ENMOD, v)
#endif

/* --- Register HW_GPT_CR, field DBGEN
 *
 * GPT debug mode enable.  The DBGEN read/write control bit enables GPT operation during Debug mode
 * .   A hardware reset resets the DBGEN bit.  A software reset does not affect the DBGEN bit.
 */

#define BP_GPT_CR_DBGEN      2
#define BM_GPT_CR_DBGEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_DBGEN(v)   ((((reg32_t) v) << 2) & BM_GPT_CR_DBGEN)
#else
#define BF_GPT_CR_DBGEN(v)   (((v) << 2) & BM_GPT_CR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_DBGEN(v)   BF_CS1(GPT_CR, DBGEN, v)
#endif

/* --- Register HW_GPT_CR, field WAITEN
 *
 * GPT Wait Mode enable.  The WAITEN read/write control bit enables GPT operation during Wait mode .
 * A hardware reset resets the WAITEN bit.  A software reset does not affect the WAITEN bit.
 */

#define BP_GPT_CR_WAITEN      3
#define BM_GPT_CR_WAITEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_WAITEN(v)   ((((reg32_t) v) << 3) & BM_GPT_CR_WAITEN)
#else
#define BF_GPT_CR_WAITEN(v)   (((v) << 3) & BM_GPT_CR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_WAITEN(v)   BF_CS1(GPT_CR, WAITEN, v)
#endif

/* --- Register HW_GPT_CR, field DOZEEN
 *
 * GPT Doze Mode Enable.   A hardware reset resets the DOZEEN bit.  A software reset does not affect
 * the DOZEEN bit.
 */

#define BP_GPT_CR_DOZEEN      4
#define BM_GPT_CR_DOZEEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_DOZEEN(v)   ((((reg32_t) v) << 4) & BM_GPT_CR_DOZEEN)
#else
#define BF_GPT_CR_DOZEEN(v)   (((v) << 4) & BM_GPT_CR_DOZEEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_DOZEEN(v)   BF_CS1(GPT_CR, DOZEEN, v)
#endif

/* --- Register HW_GPT_CR, field STOPEN
 *
 * GPT Stop Mode enable.  The STOPEN read/write control bit enables GPT operation during Stop mode .
 * A hardware reset resets the STOPEN bit.  A software reset does not affect the STOPEN bit.
 */

#define BP_GPT_CR_STOPEN      5
#define BM_GPT_CR_STOPEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_STOPEN(v)   ((((reg32_t) v) << 5) & BM_GPT_CR_STOPEN)
#else
#define BF_GPT_CR_STOPEN(v)   (((v) << 5) & BM_GPT_CR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_STOPEN(v)   BF_CS1(GPT_CR, STOPEN, v)
#endif

/* --- Register HW_GPT_CR, field CLKSRC
 *
 * Clock Source select.  The CLKSRC bits select which clock will go to the prescaler (and
 * subsequently be used to run the GPT counter).   The CLKSRC bit field value should only be changed
 * after disabling the GPT by clearing the EN bit in this register (GPT_CR).  A software reset does
 * not affect the CLKSRC bit.  For other programming requirements to change the clock source, see
 * section .
 */

#define BP_GPT_CR_CLKSRC      6
#define BM_GPT_CR_CLKSRC      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_CLKSRC(v)   ((((reg32_t) v) << 6) & BM_GPT_CR_CLKSRC)
#else
#define BF_GPT_CR_CLKSRC(v)   (((v) << 6) & BM_GPT_CR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_CLKSRC(v)   BF_CS1(GPT_CR, CLKSRC, v)
#endif

/* --- Register HW_GPT_CR, field FRR
 *
 * Free-Run or Restart mode.  The FFR bit determines the behavior of the GPT when a compare event
 * in channel 1 occurs.   In Restart mode, after a compare event, the counter resets to 0x00000000
 * and resumes counting (after the occurrence of a compare event).  In Free-Run mode, after a
 * compare event, the counter continues counting until 0xFFFFFFFF and then rolls over to 0.
 */

#define BP_GPT_CR_FRR      9
#define BM_GPT_CR_FRR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FRR(v)   ((((reg32_t) v) << 9) & BM_GPT_CR_FRR)
#else
#define BF_GPT_CR_FRR(v)   (((v) << 9) & BM_GPT_CR_FRR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FRR(v)   BF_CS1(GPT_CR, FRR, v)
#endif

/* --- Register HW_GPT_CR, field SWR
 *
 * Software reset.  This is the software reset of the GPT module. It is a self-clearing
 * bit.   The SWR bit is set when the module is in reset state.  The SWR bit is cleared when the
 * reset procedure finishes.  Setting the SWR bit resets all of the registers to their default reset
 * values, except for the CLKSRC, EN, ENMOD, STOPEN, WAITEN, and DBGEN bits in the GPT Control
 * Register (this control register).
 */

#define BP_GPT_CR_SWR      15
#define BM_GPT_CR_SWR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_SWR(v)   ((((reg32_t) v) << 15) & BM_GPT_CR_SWR)
#else
#define BF_GPT_CR_SWR(v)   (((v) << 15) & BM_GPT_CR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_SWR(v)   BF_CS1(GPT_CR, SWR, v)
#endif

/* --- Register HW_GPT_CR, field IM1
 *
 * See IM2
 */

#define BP_GPT_CR_IM1      16
#define BM_GPT_CR_IM1      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_IM1(v)   ((((reg32_t) v) << 16) & BM_GPT_CR_IM1)
#else
#define BF_GPT_CR_IM1(v)   (((v) << 16) & BM_GPT_CR_IM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_IM1(v)   BF_CS1(GPT_CR, IM1, v)
#endif

/* --- Register HW_GPT_CR, field IM2
 *
 * IM2 (bits 19-18, Input Capture Channel 2 operating mode)  IM1 (bits 17-16, Input Capture Channel
 * 1 operating mode)  The IM n bit field determines the transition on the input pin
 * (for Input capture channel n ), which will trigger a capture
 * event.
 */

#define BP_GPT_CR_IM2      18
#define BM_GPT_CR_IM2      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_IM2(v)   ((((reg32_t) v) << 18) & BM_GPT_CR_IM2)
#else
#define BF_GPT_CR_IM2(v)   (((v) << 18) & BM_GPT_CR_IM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_IM2(v)   BF_CS1(GPT_CR, IM2, v)
#endif

/* --- Register HW_GPT_CR, field OM1
 *
 * See OM3
 */

#define BP_GPT_CR_OM1      20
#define BM_GPT_CR_OM1      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM1(v)   ((((reg32_t) v) << 20) & BM_GPT_CR_OM1)
#else
#define BF_GPT_CR_OM1(v)   (((v) << 20) & BM_GPT_CR_OM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM1(v)   BF_CS1(GPT_CR, OM1, v)
#endif

/* --- Register HW_GPT_CR, field OM2
 *
 * See OM3
 */

#define BP_GPT_CR_OM2      23
#define BM_GPT_CR_OM2      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM2(v)   ((((reg32_t) v) << 23) & BM_GPT_CR_OM2)
#else
#define BF_GPT_CR_OM2(v)   (((v) << 23) & BM_GPT_CR_OM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM2(v)   BF_CS1(GPT_CR, OM2, v)
#endif

/* --- Register HW_GPT_CR, field OM3
 *
 * OM3 (bits 28-26) controls the Output Compare Channel 3 operating
 * mode.  OM2 (bits 25-23) controls the Output Compare Channel 2 operating
 * mode.  OM1 (bits 22-20) controls the Output Compare Channel 1 operating
 * mode.  The OM n bits specify the response that a compare event will
 * generate on the output pin of Output Compare Channel n .   The toggle, clear, and set options
 * cause a change on the output pin only if a compare event occurs.  When OM n is programmed as 1xx
 * (active low pulse), the output pin is set to one immediately on the next input clock; a low pulse
 * (that is an input clock in width) occurs when there is a compare event. Note that here, "input
 * clock" refers to the clock selected by the CLKSRC bits of the GPT Control Register.
 */

#define BP_GPT_CR_OM3      26
#define BM_GPT_CR_OM3      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_OM3(v)   ((((reg32_t) v) << 26) & BM_GPT_CR_OM3)
#else
#define BF_GPT_CR_OM3(v)   (((v) << 26) & BM_GPT_CR_OM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_OM3(v)   BF_CS1(GPT_CR, OM3, v)
#endif

/* --- Register HW_GPT_CR, field FO1
 *
 * See F03
 */

#define BP_GPT_CR_FO1      29
#define BM_GPT_CR_FO1      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO1(v)   ((((reg32_t) v) << 29) & BM_GPT_CR_FO1)
#else
#define BF_GPT_CR_FO1(v)   (((v) << 29) & BM_GPT_CR_FO1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO1(v)   BF_CS1(GPT_CR, FO1, v)
#endif

/* --- Register HW_GPT_CR, field FO2
 *
 * See F03
 */

#define BP_GPT_CR_FO2      30
#define BM_GPT_CR_FO2      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO2(v)   ((((reg32_t) v) << 30) & BM_GPT_CR_FO2)
#else
#define BF_GPT_CR_FO2(v)   (((v) << 30) & BM_GPT_CR_FO2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO2(v)   BF_CS1(GPT_CR, FO2, v)
#endif

/* --- Register HW_GPT_CR, field FO3
 *
 * FO3 Force Output Compare Channel 3  FO2 Force Output Compare Channel 2  FO1 Force Output Compare
 * Channel 1  The FO n bit causes the pin action programmed for the
 * timer Output Compare n pin (according to the OM n bits                                 in this
 * register).   The OF n flag (OF3, OF2, OF1) in the status register is not affected .  This bit is
 * self-negating and always read as zero.
 */

#define BP_GPT_CR_FO3      31
#define BM_GPT_CR_FO3      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CR_FO3(v)   ((((reg32_t) v) << 31) & BM_GPT_CR_FO3)
#else
#define BF_GPT_CR_FO3(v)   (((v) << 31) & BM_GPT_CR_FO3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CR_FO3(v)   BF_CS1(GPT_CR, FO3, v)
#endif

/*!
 * @brief HW_GPT_PR - GPT Prescaler Register
 *
 * The GPT Prescaler Register (GPT_PR) contains bits that determine the divide value of the clock
 * that runs the counter.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PRESCALER : 12; //!< Prescaler bits.  The clock selected by the CLKSRC field is divided by [PRESCALER + 1], and then used to run the counter.   A change in the value of the PRESCALER bits cause the Prescaler counter to reset and a new count period to start immediately.  See for the timing diagram.
        unsigned RESERVED0 : 20; //!< Reserved bits.   Writing a value to these reserved bits will not affect GPT operations.  These reserved bits are always read as zero.
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

/* --- Register HW_GPT_PR, field PRESCALER
 *
 * Prescaler bits.  The clock selected by the CLKSRC field is divided by [PRESCALER + 1],
 * and then used to run the counter.   A change in the value of the PRESCALER bits cause the
 * Prescaler counter to reset and a new count period to start immediately.  See for the timing
 * diagram.
 */

#define BP_GPT_PR_PRESCALER      0
#define BM_GPT_PR_PRESCALER      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_PR_PRESCALER(v)   ((((reg32_t) v) << 0) & BM_GPT_PR_PRESCALER)
#else
#define BF_GPT_PR_PRESCALER(v)   (((v) << 0) & BM_GPT_PR_PRESCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_PR_PRESCALER(v)   BF_CS1(GPT_PR, PRESCALER, v)
#endif

/*!
 * @brief HW_GPT_SR - GPT Status Register
 *
 * The GPT Status Register (GPT_SR) contains bits that indicate that a
 * counter has rolled over, and if any event has occurred on the Input
 * Capture and Output Compare channels. The bits are cleared by writing a 1
 * to them.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OF1 : 1; //!< See OF3
        unsigned OF2 : 1; //!< See OF3
        unsigned OF3 : 1; //!< OF3 Output Compare 3 Flag  OF2 Output Compare 2 Flag  OF1 Output Compare 1 Flag  The OF n bit indicates that a compare event has occurred on Output Compare channel n .
        unsigned IF1 : 1; //!< See IF2
        unsigned IF2 : 1; //!< IF2 Input capture 2 Flag  IF1 Input capture 1 Flag  The IF n bit indicates that a capture event has occurred on Input Capture channel n .
        unsigned ROV : 1; //!< Rollover Flag.  The ROV bit indicates that the counter has reached its maximum possible value and rolled over to 0 (from which the counter continues counting). The ROV bit is only set if the counter has reached 0xFFFFFFFF in both Restart and Free-Run modes.
        unsigned RESERVED0 : 26; //!< Reserved bits.   Writing a value to these reserved bits will not affect GPT operations.  These reserved bits are always read as zero.
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

/* --- Register HW_GPT_SR, field OF1
 *
 * See OF3
 */

#define BP_GPT_SR_OF1      0
#define BM_GPT_SR_OF1      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF1(v)   ((((reg32_t) v) << 0) & BM_GPT_SR_OF1)
#else
#define BF_GPT_SR_OF1(v)   (((v) << 0) & BM_GPT_SR_OF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF1(v)   BF_CS1(GPT_SR, OF1, v)
#endif

/* --- Register HW_GPT_SR, field OF2
 *
 * See OF3
 */

#define BP_GPT_SR_OF2      1
#define BM_GPT_SR_OF2      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF2(v)   ((((reg32_t) v) << 1) & BM_GPT_SR_OF2)
#else
#define BF_GPT_SR_OF2(v)   (((v) << 1) & BM_GPT_SR_OF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF2(v)   BF_CS1(GPT_SR, OF2, v)
#endif

/* --- Register HW_GPT_SR, field OF3
 *
 * OF3 Output Compare 3 Flag  OF2 Output Compare 2 Flag  OF1 Output Compare 1 Flag  The OF n bit
 * indicates that a compare event has occurred on                                 Output Compare
 * channel n .
 */

#define BP_GPT_SR_OF3      2
#define BM_GPT_SR_OF3      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_OF3(v)   ((((reg32_t) v) << 2) & BM_GPT_SR_OF3)
#else
#define BF_GPT_SR_OF3(v)   (((v) << 2) & BM_GPT_SR_OF3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_OF3(v)   BF_CS1(GPT_SR, OF3, v)
#endif

/* --- Register HW_GPT_SR, field IF1
 *
 * See IF2
 */

#define BP_GPT_SR_IF1      3
#define BM_GPT_SR_IF1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_IF1(v)   ((((reg32_t) v) << 3) & BM_GPT_SR_IF1)
#else
#define BF_GPT_SR_IF1(v)   (((v) << 3) & BM_GPT_SR_IF1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_IF1(v)   BF_CS1(GPT_SR, IF1, v)
#endif

/* --- Register HW_GPT_SR, field IF2
 *
 * IF2 Input capture 2 Flag  IF1 Input capture 1 Flag  The IF n bit indicates that a capture event
 * has occurred on                                 Input Capture channel n .
 */

#define BP_GPT_SR_IF2      4
#define BM_GPT_SR_IF2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_IF2(v)   ((((reg32_t) v) << 4) & BM_GPT_SR_IF2)
#else
#define BF_GPT_SR_IF2(v)   (((v) << 4) & BM_GPT_SR_IF2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_IF2(v)   BF_CS1(GPT_SR, IF2, v)
#endif

/* --- Register HW_GPT_SR, field ROV
 *
 * Rollover Flag.  The ROV bit indicates that the counter has reached its maximum possible value and
 * rolled over to 0 (from which the                                 counter continues counting). The
 * ROV bit is only set if the counter                                 has reached 0xFFFFFFFF in both
 * Restart and Free-Run modes.
 */

#define BP_GPT_SR_ROV      5
#define BM_GPT_SR_ROV      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_SR_ROV(v)   ((((reg32_t) v) << 5) & BM_GPT_SR_ROV)
#else
#define BF_GPT_SR_ROV(v)   (((v) << 5) & BM_GPT_SR_ROV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_SR_ROV(v)   BF_CS1(GPT_SR, ROV, v)
#endif

/*!
 * @brief HW_GPT_IR - GPT Interrupt Register
 *
 * The GPT Interrupt Register (GPT_IR) contains bits that control whether
 * interrupts are generated after rollover, input capture and output
 * compare events.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OF1IE : 1; //!< See OF3IE
        unsigned OF2IE : 1; //!< See OF3IE
        unsigned OF3IE : 1; //!< OF3IE Output Compare 3 Interrupt Enable  OF2IE Output Compare 2 Interrupt Enable  OF1IE Output Compare 1 Interrupt Enable  The OF n IE bit controls the Output Compare Channel n interrupt.
        unsigned IF1IE : 1; //!< See IF2IE
        unsigned IF2IE : 1; //!< IF2IE Input capture 2 Interrupt Enable  IF1IE Input capture 1 Interrupt Enable  The IF n IE bit controls the IF n IE Input Capture n Interrupt Enable.
        unsigned ROVIE : 1; //!< Rollover Interrupt Enable.  The ROVIE bit controls the Rollover interrupt.
        unsigned RESERVED0 : 26; //!< Reserved bits.   Writing a value to these reserved bits will not affect GPT operations.  These reserved bits are always read as zero.
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

/* --- Register HW_GPT_IR, field OF1IE
 *
 * See OF3IE
 */

#define BP_GPT_IR_OF1IE      0
#define BM_GPT_IR_OF1IE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF1IE(v)   ((((reg32_t) v) << 0) & BM_GPT_IR_OF1IE)
#else
#define BF_GPT_IR_OF1IE(v)   (((v) << 0) & BM_GPT_IR_OF1IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF1IE(v)   BF_CS1(GPT_IR, OF1IE, v)
#endif

/* --- Register HW_GPT_IR, field OF2IE
 *
 * See OF3IE
 */

#define BP_GPT_IR_OF2IE      1
#define BM_GPT_IR_OF2IE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF2IE(v)   ((((reg32_t) v) << 1) & BM_GPT_IR_OF2IE)
#else
#define BF_GPT_IR_OF2IE(v)   (((v) << 1) & BM_GPT_IR_OF2IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF2IE(v)   BF_CS1(GPT_IR, OF2IE, v)
#endif

/* --- Register HW_GPT_IR, field OF3IE
 *
 * OF3IE Output Compare 3 Interrupt Enable  OF2IE Output Compare 2 Interrupt Enable  OF1IE Output
 * Compare 1 Interrupt Enable  The OF n IE bit controls the Output Compare Channel n interrupt.
 */

#define BP_GPT_IR_OF3IE      2
#define BM_GPT_IR_OF3IE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_OF3IE(v)   ((((reg32_t) v) << 2) & BM_GPT_IR_OF3IE)
#else
#define BF_GPT_IR_OF3IE(v)   (((v) << 2) & BM_GPT_IR_OF3IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_OF3IE(v)   BF_CS1(GPT_IR, OF3IE, v)
#endif

/* --- Register HW_GPT_IR, field IF1IE
 *
 * See IF2IE
 */

#define BP_GPT_IR_IF1IE      3
#define BM_GPT_IR_IF1IE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_IF1IE(v)   ((((reg32_t) v) << 3) & BM_GPT_IR_IF1IE)
#else
#define BF_GPT_IR_IF1IE(v)   (((v) << 3) & BM_GPT_IR_IF1IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_IF1IE(v)   BF_CS1(GPT_IR, IF1IE, v)
#endif

/* --- Register HW_GPT_IR, field IF2IE
 *
 * IF2IE Input capture 2 Interrupt Enable  IF1IE Input capture 1 Interrupt Enable  The IF n IE bit
 * controls the IF n IE Input Capture n Interrupt Enable.
 */

#define BP_GPT_IR_IF2IE      4
#define BM_GPT_IR_IF2IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_IF2IE(v)   ((((reg32_t) v) << 4) & BM_GPT_IR_IF2IE)
#else
#define BF_GPT_IR_IF2IE(v)   (((v) << 4) & BM_GPT_IR_IF2IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_IF2IE(v)   BF_CS1(GPT_IR, IF2IE, v)
#endif

/* --- Register HW_GPT_IR, field ROVIE
 *
 * Rollover Interrupt Enable.  The ROVIE bit controls the Rollover interrupt.
 */

#define BP_GPT_IR_ROVIE      5
#define BM_GPT_IR_ROVIE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_GPT_IR_ROVIE(v)   ((((reg32_t) v) << 5) & BM_GPT_IR_ROVIE)
#else
#define BF_GPT_IR_ROVIE(v)   (((v) << 5) & BM_GPT_IR_ROVIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_IR_ROVIE(v)   BF_CS1(GPT_IR, ROVIE, v)
#endif

/*!
 * @brief HW_GPT_OCR1 - GPT Output Compare Register 1
 *
 * The GPT Compare Register 1 (GPT_OCR1) holds the value that determines
 * when a compare event will be generated on Output Compare Channel 1. Any
 * write access to the Compare register of Channel 1 while in Restart mode
 * (FRR=0) will reset the GPT counter.  An IP Bus Write access to the GPT Output Compare Register1
 * (GPT_OCR1)                             occurs after one cycle of wait state (ips_xfr_wait high
 * for 1 cycle) ; an IP Bus Read access occurs immediately (0 wait states).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32; //!< Compare Value.  When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 1.
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

/* --- Register HW_GPT_OCR1, field COMP
 *
 * Compare Value.  When the counter value equals the COMP bit field value, a compare
 * event is generated on Output Compare Channel 1.
 */

#define BP_GPT_OCR1_COMP      0
#define BM_GPT_OCR1_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR1_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR1_COMP)
#else
#define BF_GPT_OCR1_COMP(v)   (((v) << 0) & BM_GPT_OCR1_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR1_COMP(v)   BF_CS1(GPT_OCR1, COMP, v)
#endif

/*!
 * @brief HW_GPT_OCR2 - GPT Output Compare Register 2
 *
 * The GPT Compare Register 2 (GPT_OCR2) holds the value that determines
 * when a compare event will be generated on Output Compare Channel 2.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32; //!< Compare Value.  When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 2.
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

/* --- Register HW_GPT_OCR2, field COMP
 *
 * Compare Value.  When the counter value equals the COMP bit field value, a compare
 * event is generated on Output Compare Channel 2.
 */

#define BP_GPT_OCR2_COMP      0
#define BM_GPT_OCR2_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR2_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR2_COMP)
#else
#define BF_GPT_OCR2_COMP(v)   (((v) << 0) & BM_GPT_OCR2_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR2_COMP(v)   BF_CS1(GPT_OCR2, COMP, v)
#endif

/*!
 * @brief HW_GPT_OCR3 - GPT Output Compare Register 3
 *
 * The GPT Compare Register 3 (GPT_OCR3) holds the value that determines
 * when a compare event will be generated on Output Compare Channel 3.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMP : 32; //!< Compare Value.  When the counter value equals the COMP bit field value, a compare event is generated on Output Compare Channel 3.
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

/* --- Register HW_GPT_OCR3, field COMP
 *
 * Compare Value.  When the counter value equals the COMP bit field value, a compare
 * event is generated on Output Compare Channel 3.
 */

#define BP_GPT_OCR3_COMP      0
#define BM_GPT_OCR3_COMP      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_OCR3_COMP(v)   ((((reg32_t) v) << 0) & BM_GPT_OCR3_COMP)
#else
#define BF_GPT_OCR3_COMP(v)   (((v) << 0) & BM_GPT_OCR3_COMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_OCR3_COMP(v)   BF_CS1(GPT_OCR3, COMP, v)
#endif

/*!
 * @brief HW_GPT_ICR1 - GPT Input Capture Register 1
 *
 * The GPT Input Capture Register 1 (GPT_ICR1) is a read-only register that
 * holds the value that was in the counter during the last capture event on Input Capture Channel 1.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CAPT : 32; //!< Capture Value.  After a capture event on Input Capture Channel 1 occurs, the current value of the counter is loaded into GPT Input Capture Register 1.
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
#define HW_GPT_ICR1_WR(v)     (HW_GPT_ICR1.U = (v))
#define HW_GPT_ICR1_SET(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() |  (v)))
#define HW_GPT_ICR1_CLR(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() & ~(v)))
#define HW_GPT_ICR1_TOG(v)    (HW_GPT_ICR1_WR(HW_GPT_ICR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_ICR1 bitfields
 */

/* --- Register HW_GPT_ICR1, field CAPT
 *
 * Capture Value.  After a capture event on Input Capture Channel 1 occurs, the current
 * value of the counter is loaded into GPT Input Capture Register                                 1.
 */

#define BP_GPT_ICR1_CAPT      0
#define BM_GPT_ICR1_CAPT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_ICR1_CAPT(v)   ((((reg32_t) v) << 0) & BM_GPT_ICR1_CAPT)
#else
#define BF_GPT_ICR1_CAPT(v)   (((v) << 0) & BM_GPT_ICR1_CAPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_ICR1_CAPT(v)   BF_CS1(GPT_ICR1, CAPT, v)
#endif

/*!
 * @brief HW_GPT_ICR2 - GPT Input Capture Register 2
 *
 * The GPT Input capture Register 2 (GPT_ICR2) is a read-only register which
 * holds the value that was in the counter during the last capture event on
 * input capture channel 2.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CAPT : 32; //!< Capture Value.  After a capture event on Input Capture Channel 2 occurs, the current value of the counter is loaded into GPT Input Capture Register 2.
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
#define HW_GPT_ICR2_WR(v)     (HW_GPT_ICR2.U = (v))
#define HW_GPT_ICR2_SET(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() |  (v)))
#define HW_GPT_ICR2_CLR(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() & ~(v)))
#define HW_GPT_ICR2_TOG(v)    (HW_GPT_ICR2_WR(HW_GPT_ICR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_ICR2 bitfields
 */

/* --- Register HW_GPT_ICR2, field CAPT
 *
 * Capture Value.  After a capture event on Input Capture Channel 2 occurs, the current
 * value of the counter is loaded into GPT Input Capture Register                                 2.
 */

#define BP_GPT_ICR2_CAPT      0
#define BM_GPT_ICR2_CAPT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_ICR2_CAPT(v)   ((((reg32_t) v) << 0) & BM_GPT_ICR2_CAPT)
#else
#define BF_GPT_ICR2_CAPT(v)   (((v) << 0) & BM_GPT_ICR2_CAPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_ICR2_CAPT(v)   BF_CS1(GPT_ICR2, CAPT, v)
#endif

/*!
 * @brief HW_GPT_CNT - GPT Counter Register
 *
 * The GPT Counter Register (GPT_CNT) is the main counter's register. GPT_CNT
 * is a read-only register and can be read without affecting the counting process of the GPT.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< Counter Value.  The COUNT bits show the current count value of the GPT counter.
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
#define HW_GPT_CNT_WR(v)     (HW_GPT_CNT.U = (v))
#define HW_GPT_CNT_SET(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() |  (v)))
#define HW_GPT_CNT_CLR(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() & ~(v)))
#define HW_GPT_CNT_TOG(v)    (HW_GPT_CNT_WR(HW_GPT_CNT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual GPT_CNT bitfields
 */

/* --- Register HW_GPT_CNT, field COUNT
 *
 * Counter Value.  The COUNT bits show the current count value of the GPT counter.
 */

#define BP_GPT_CNT_COUNT      0
#define BM_GPT_CNT_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPT_CNT_COUNT(v)   ((((reg32_t) v) << 0) & BM_GPT_CNT_COUNT)
#else
#define BF_GPT_CNT_COUNT(v)   (((v) << 0) & BM_GPT_CNT_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_GPT_CNT_COUNT(v)   BF_CS1(GPT_CNT, COUNT, v)
#endif



/*!
 * @brief All GPT module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
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
} hw_gpt_t
#endif

//! @brief Macro to access all GPT registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPT(0)</code>.
#define HW_GPT     (*(volatile hw_gpt_t *) REGS_GPT_BASE)


#endif // _GPT_H
