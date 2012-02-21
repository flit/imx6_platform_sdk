/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PWM_H
#define _PWM_H

#include "regs.h"

#ifndef REGS_PWM_BASE
#define REGS_PWM0_BASE (REGS_BASE + 0x02080000)
#define REGS_PWM1_BASE (REGS_BASE + 0x02084000)
#define REGS_PWM2_BASE (REGS_BASE + 0x02088000)
#define REGS_PWM3_BASE (REGS_BASE + 0x0208c000)
#define REGS_PWM_BASE(x) ( x == 0 ? REGS_PWM0_BASE : x == 1 ? REGS_PWM1_BASE : x == 2 ? REGS_PWM2_BASE : x == 3 ? REGS_PWM3_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_PWM_PWMCR - PWM Control Register
 *
 * The PWM control register (PWM_PWMCR) is used to configure the operating
 * settings of the PWM. It contains the prescaler for the clock
 * division.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1; //!< PWM Enable. This bit enables the PWM. If this bit is not enabled, the clock prescaler and the counter is reset. When the PWM is enabled, it begins a new period, the output pin is set to start a new period while the prescaler and counter are released and counting begins.
        unsigned REPEAT : 2; //!< Sample Repeat. This bit field determines the number of times each sample from the FIFO is to be used.
        unsigned SWR : 1; //!< Software Reset. PWM is reset when this bit is set to 1. It is a self clearing bit. A write 1 to this bit is a single wait state write cycle. When the block is in reset state this bit is set and is cleared when the reset procedure is over. Setting this bit resets all the registers to their reset values except for the STOPEN, DOZEN, WAITEN, and DBGEN bits in this control register Technically, the previous tagging isn't correct as "DBGEN" should be tagged as feature="pwm_debug_yes".-JC .
        unsigned PRESCALER : 12; //!< Counter Clock Prescaler Value. This bit field determines the value by which the clock will be divided before it goes to the counter.
        unsigned CLKSRC : 2; //!< Select Clock Source. These bits determine which clock input will be selected for running the counter. After reset the system functional clock is selected. The input clock can also be turned off if these bits are set to 00. This field value should only be changed when the PWM is disabled
        unsigned POUTC : 2; //!< PWM Output Configuration. This bit field determines the mode of PWM output on the output pin.
        unsigned HCTR : 1; //!< Half-word Data Swap Control. This bit determines which half word data from the 32-bit IP Bus interface is written into the lower 16 bits of the sample register.
        unsigned BCTR : 1; //!< Byte Data Swap Control. This bit determines the byte ordering of the 16-bit data when it goes into the FIFO from the sample register.
        unsigned RESERVED0 : 4; //!< 
        unsigned FWM : 2; //!< FIFO Water Mark. These bits are used to set the data level at which the FIFO empty flag will be set and the corresponding interrupt generated
        unsigned RESERVED : 4; //!< Reserved. These reserved bits are always read as zero.
    } B;
} hw_pwm_pwmcr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMCR register
 */
#define HW_PWM_PWMCR_ADDR(x)      (REGS_PWM_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMCR(x)           (*(volatile hw_pwm_pwmcr_t *) HW_PWM_PWMCR_ADDR(x))
#define HW_PWM_PWMCR_RD(x)        (HW_PWM_PWMCR(x).U)
#define HW_PWM_PWMCR_WR(x, v)     (HW_PWM_PWMCR(x).U = (v))
#define HW_PWM_PWMCR_SET(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) |  (v)))
#define HW_PWM_PWMCR_CLR(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) & ~(v)))
#define HW_PWM_PWMCR_TOG(x, v)    (HW_PWM_PWMCR_WR(x, HW_PWM_PWMCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMCR bitfields
 */

/* --- Register HW_PWM_PWMCR, field EN
 *
 * PWM Enable. This bit enables the PWM. If this bit is not enabled, the
 * clock prescaler and the counter is reset. When the PWM is enabled,
 * it begins a new period, the output pin is set to start a new period
 * while the prescaler and counter are released and counting                                 begins.
 */

#define BP_PWM_PWMCR_EN      0
#define BM_PWM_PWMCR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_EN(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMCR_EN)
#else
#define BF_PWM_PWMCR_EN(v)   (((v) << 0) & BM_PWM_PWMCR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_EN(v)   BF_CS1(PWM_PWMCR, EN, v)
#endif

/* --- Register HW_PWM_PWMCR, field REPEAT
 *
 * Sample Repeat. This bit field determines the number of times each
 * sample from the FIFO is to be used.
 */

#define BP_PWM_PWMCR_REPEAT      1
#define BM_PWM_PWMCR_REPEAT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_REPEAT(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMCR_REPEAT)
#else
#define BF_PWM_PWMCR_REPEAT(v)   (((v) << 1) & BM_PWM_PWMCR_REPEAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_REPEAT(v)   BF_CS1(PWM_PWMCR, REPEAT, v)
#endif

/* --- Register HW_PWM_PWMCR, field SWR
 *
 * Software Reset. PWM is reset when this bit is set to 1. It is a self
 * clearing bit. A write 1 to this bit is a single wait state write
 * cycle. When the block is in reset state this bit is set and is
 * cleared when the reset procedure is over. Setting this bit resets
 * all the registers to their reset values except for the STOPEN,
 * DOZEN, WAITEN, and DBGEN bits in this control register Technically, the previous tagging isn't
 * correct as "DBGEN" should be tagged as feature="pwm_debug_yes".-JC .
 */

#define BP_PWM_PWMCR_SWR      3
#define BM_PWM_PWMCR_SWR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_SWR(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMCR_SWR)
#else
#define BF_PWM_PWMCR_SWR(v)   (((v) << 3) & BM_PWM_PWMCR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_SWR(v)   BF_CS1(PWM_PWMCR, SWR, v)
#endif

/* --- Register HW_PWM_PWMCR, field PRESCALER
 *
 * Counter Clock Prescaler Value. This bit field determines the value by
 * which the clock will be divided before it goes to the counter.
 */

#define BP_PWM_PWMCR_PRESCALER      4
#define BM_PWM_PWMCR_PRESCALER      0x0000fff0

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_PRESCALER(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMCR_PRESCALER)
#else
#define BF_PWM_PWMCR_PRESCALER(v)   (((v) << 4) & BM_PWM_PWMCR_PRESCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_PRESCALER(v)   BF_CS1(PWM_PWMCR, PRESCALER, v)
#endif

/* --- Register HW_PWM_PWMCR, field CLKSRC
 *
 * Select Clock Source. These bits determine which clock input will be
 * selected for running the counter. After reset the system functional
 * clock is selected. The input clock can also be turned off if these
 * bits are set to 00. This field value should only be changed when the
 * PWM is disabled
 */

#define BP_PWM_PWMCR_CLKSRC      16
#define BM_PWM_PWMCR_CLKSRC      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_CLKSRC(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMCR_CLKSRC)
#else
#define BF_PWM_PWMCR_CLKSRC(v)   (((v) << 16) & BM_PWM_PWMCR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_CLKSRC(v)   BF_CS1(PWM_PWMCR, CLKSRC, v)
#endif

/* --- Register HW_PWM_PWMCR, field POUTC
 *
 * PWM Output Configuration. This bit field determines the mode of PWM
 * output on the output pin.
 */

#define BP_PWM_PWMCR_POUTC      18
#define BM_PWM_PWMCR_POUTC      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_POUTC(v)   ((((reg32_t) v) << 18) & BM_PWM_PWMCR_POUTC)
#else
#define BF_PWM_PWMCR_POUTC(v)   (((v) << 18) & BM_PWM_PWMCR_POUTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_POUTC(v)   BF_CS1(PWM_PWMCR, POUTC, v)
#endif

/* --- Register HW_PWM_PWMCR, field HCTR
 *
 * Half-word Data Swap Control. This bit determines which half word data
 * from the 32-bit IP Bus interface is written into the lower 16 bits
 * of the sample register.
 */

#define BP_PWM_PWMCR_HCTR      20
#define BM_PWM_PWMCR_HCTR      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_HCTR(v)   ((((reg32_t) v) << 20) & BM_PWM_PWMCR_HCTR)
#else
#define BF_PWM_PWMCR_HCTR(v)   (((v) << 20) & BM_PWM_PWMCR_HCTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_HCTR(v)   BF_CS1(PWM_PWMCR, HCTR, v)
#endif

/* --- Register HW_PWM_PWMCR, field BCTR
 *
 * Byte Data Swap Control. This bit determines the byte ordering of the
 * 16-bit data when it goes into the FIFO from the sample register.
 */

#define BP_PWM_PWMCR_BCTR      21
#define BM_PWM_PWMCR_BCTR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_BCTR(v)   ((((reg32_t) v) << 21) & BM_PWM_PWMCR_BCTR)
#else
#define BF_PWM_PWMCR_BCTR(v)   (((v) << 21) & BM_PWM_PWMCR_BCTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_BCTR(v)   BF_CS1(PWM_PWMCR, BCTR, v)
#endif

/* --- Register HW_PWM_PWMCR, field FWM
 *
 * FIFO Water Mark. These bits are used to set the data level at which
 * the FIFO empty flag will be set and the corresponding interrupt
 * generated
 */

#define BP_PWM_PWMCR_FWM      26
#define BM_PWM_PWMCR_FWM      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_FWM(v)   ((((reg32_t) v) << 26) & BM_PWM_PWMCR_FWM)
#else
#define BF_PWM_PWMCR_FWM(v)   (((v) << 26) & BM_PWM_PWMCR_FWM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_FWM(v)   BF_CS1(PWM_PWMCR, FWM, v)
#endif

/* --- Register HW_PWM_PWMCR, field RESERVED
 *
 * Reserved. These reserved bits are always read as zero.
 */

#define BP_PWM_PWMCR_RESERVED      28
#define BM_PWM_PWMCR_RESERVED      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_RESERVED(v)   ((((reg32_t) v) << 28) & BM_PWM_PWMCR_RESERVED)
#else
#define BF_PWM_PWMCR_RESERVED(v)   (((v) << 28) & BM_PWM_PWMCR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCR_RESERVED(v)   BF_CS1(PWM_PWMCR, RESERVED, v)
#endif

/*!
 * @brief HW_PWM_PWMSR - PWM Status Register
 *
 * The PWM status register (PWM_PWMSR) contains seven bits which display the
 * state of the FIFO and the occurrence of rollover and compare events. The
 * FIFOAV bit is read-only but the other four bits can be cleared by
 * writing 1 to them. The FE, ROV, and CMP bits are associated with
 * FIFO-Empty, Roll-over, and Compare interrupts, respectively.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FIFOAV : 3; //!< FIFO Available. These read-only bits indicate the data level remaining in the FIFO. An attempted write to these bits will not affect their value and no transfer error is generated.
        unsigned FE : 1; //!< FIFO Empty Status Bit. This bit indicates the FIFO data level in comparison to the water level set by FWM field in the control register.
        unsigned ROV : 1; //!< Roll-over Status. This bit shows that a roll-over event has occurred.
        unsigned CMP : 1; //!< Compare Status. This bit shows that a compare event has occurred.
        unsigned FWE : 1; //!< FIFO Write Error Status. This bit shows that an attempt has been made to write FIFO when it is full.
        unsigned RESERVED : 25; //!< Reserved. These reserved bits are always read as zero.
    } B;
} hw_pwm_pwmsr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMSR register
 */
#define HW_PWM_PWMSR_ADDR(x)      (REGS_PWM_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMSR(x)           (*(volatile hw_pwm_pwmsr_t *) HW_PWM_PWMSR_ADDR(x))
#define HW_PWM_PWMSR_RD(x)        (HW_PWM_PWMSR(x).U)
#define HW_PWM_PWMSR_WR(x, v)     (HW_PWM_PWMSR(x).U = (v))
#define HW_PWM_PWMSR_SET(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) |  (v)))
#define HW_PWM_PWMSR_CLR(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) & ~(v)))
#define HW_PWM_PWMSR_TOG(x, v)    (HW_PWM_PWMSR_WR(x, HW_PWM_PWMSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMSR bitfields
 */

/* --- Register HW_PWM_PWMSR, field FIFOAV
 *
 * FIFO Available. These read-only bits indicate the data level
 * remaining in the FIFO. An attempted write to these bits will not
 * affect their value and no transfer error is generated.
 */

#define BP_PWM_PWMSR_FIFOAV      0
#define BM_PWM_PWMSR_FIFOAV      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FIFOAV(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMSR_FIFOAV)
#else
#define BF_PWM_PWMSR_FIFOAV(v)   (((v) << 0) & BM_PWM_PWMSR_FIFOAV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FIFOAV(v)   BF_CS1(PWM_PWMSR, FIFOAV, v)
#endif

/* --- Register HW_PWM_PWMSR, field FE
 *
 * FIFO Empty Status Bit. This bit indicates the FIFO data level in
 * comparison to the water level set by FWM field in the control
 * register.
 */

#define BP_PWM_PWMSR_FE      3
#define BM_PWM_PWMSR_FE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FE(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMSR_FE)
#else
#define BF_PWM_PWMSR_FE(v)   (((v) << 3) & BM_PWM_PWMSR_FE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FE(v)   BF_CS1(PWM_PWMSR, FE, v)
#endif

/* --- Register HW_PWM_PWMSR, field ROV
 *
 * Roll-over Status. This bit shows that a roll-over event has occurred.
 */

#define BP_PWM_PWMSR_ROV      4
#define BM_PWM_PWMSR_ROV      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_ROV(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMSR_ROV)
#else
#define BF_PWM_PWMSR_ROV(v)   (((v) << 4) & BM_PWM_PWMSR_ROV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_ROV(v)   BF_CS1(PWM_PWMSR, ROV, v)
#endif

/* --- Register HW_PWM_PWMSR, field CMP
 *
 * Compare Status. This bit shows that a compare event has occurred.
 */

#define BP_PWM_PWMSR_CMP      5
#define BM_PWM_PWMSR_CMP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_CMP(v)   ((((reg32_t) v) << 5) & BM_PWM_PWMSR_CMP)
#else
#define BF_PWM_PWMSR_CMP(v)   (((v) << 5) & BM_PWM_PWMSR_CMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_CMP(v)   BF_CS1(PWM_PWMSR, CMP, v)
#endif

/* --- Register HW_PWM_PWMSR, field FWE
 *
 * FIFO Write Error Status. This bit shows that an attempt has been made
 * to write FIFO when it is full.
 */

#define BP_PWM_PWMSR_FWE      6
#define BM_PWM_PWMSR_FWE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FWE(v)   ((((reg32_t) v) << 6) & BM_PWM_PWMSR_FWE)
#else
#define BF_PWM_PWMSR_FWE(v)   (((v) << 6) & BM_PWM_PWMSR_FWE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_FWE(v)   BF_CS1(PWM_PWMSR, FWE, v)
#endif

/* --- Register HW_PWM_PWMSR, field RESERVED
 *
 * Reserved. These reserved bits are always read as zero.
 */

#define BP_PWM_PWMSR_RESERVED      7
#define BM_PWM_PWMSR_RESERVED      0xffffff80

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_RESERVED(v)   ((((reg32_t) v) << 7) & BM_PWM_PWMSR_RESERVED)
#else
#define BF_PWM_PWMSR_RESERVED(v)   (((v) << 7) & BM_PWM_PWMSR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSR_RESERVED(v)   BF_CS1(PWM_PWMSR, RESERVED, v)
#endif

/*!
 * @brief HW_PWM_PWMIR - PWM Interrupt Register
 *
 * The PWM Interrupt register (PWM_PWMIR) contains three bits which control
 * the generation of the compare, rollover and FIFO empty interrupts.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FIE : 1; //!< FIFO Empty Interrupt Enable. This bit controls the generation of the FIFO Empty interrupt.
        unsigned RIE : 1; //!< Roll-over Interrupt Enable. This bit controls the generation of the Rollover interrupt.
        unsigned CIE : 1; //!< Compare Interrupt Enable. This bit controls the generation of the Compare interrupt.
        unsigned RESERVED : 29; //!< Reserved. These reserved bits are always read as zero.
    } B;
} hw_pwm_pwmir_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMIR register
 */
#define HW_PWM_PWMIR_ADDR(x)      (REGS_PWM_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMIR(x)           (*(volatile hw_pwm_pwmir_t *) HW_PWM_PWMIR_ADDR(x))
#define HW_PWM_PWMIR_RD(x)        (HW_PWM_PWMIR(x).U)
#define HW_PWM_PWMIR_WR(x, v)     (HW_PWM_PWMIR(x).U = (v))
#define HW_PWM_PWMIR_SET(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) |  (v)))
#define HW_PWM_PWMIR_CLR(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) & ~(v)))
#define HW_PWM_PWMIR_TOG(x, v)    (HW_PWM_PWMIR_WR(x, HW_PWM_PWMIR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMIR bitfields
 */

/* --- Register HW_PWM_PWMIR, field FIE
 *
 * FIFO Empty Interrupt Enable. This bit controls the generation of the
 * FIFO Empty interrupt.
 */

#define BP_PWM_PWMIR_FIE      0
#define BM_PWM_PWMIR_FIE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_FIE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMIR_FIE)
#else
#define BF_PWM_PWMIR_FIE(v)   (((v) << 0) & BM_PWM_PWMIR_FIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_FIE(v)   BF_CS1(PWM_PWMIR, FIE, v)
#endif

/* --- Register HW_PWM_PWMIR, field RIE
 *
 * Roll-over Interrupt Enable. This bit controls the generation of the
 * Rollover interrupt.
 */

#define BP_PWM_PWMIR_RIE      1
#define BM_PWM_PWMIR_RIE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_RIE(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMIR_RIE)
#else
#define BF_PWM_PWMIR_RIE(v)   (((v) << 1) & BM_PWM_PWMIR_RIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_RIE(v)   BF_CS1(PWM_PWMIR, RIE, v)
#endif

/* --- Register HW_PWM_PWMIR, field CIE
 *
 * Compare Interrupt Enable. This bit controls the generation of the
 * Compare interrupt.
 */

#define BP_PWM_PWMIR_CIE      2
#define BM_PWM_PWMIR_CIE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_CIE(v)   ((((reg32_t) v) << 2) & BM_PWM_PWMIR_CIE)
#else
#define BF_PWM_PWMIR_CIE(v)   (((v) << 2) & BM_PWM_PWMIR_CIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_CIE(v)   BF_CS1(PWM_PWMIR, CIE, v)
#endif

/* --- Register HW_PWM_PWMIR, field RESERVED
 *
 * Reserved. These reserved bits are always read as zero.
 */

#define BP_PWM_PWMIR_RESERVED      3
#define BM_PWM_PWMIR_RESERVED      0xfffffff8

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_RESERVED(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMIR_RESERVED)
#else
#define BF_PWM_PWMIR_RESERVED(v)   (((v) << 3) & BM_PWM_PWMIR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMIR_RESERVED(v)   BF_CS1(PWM_PWMIR, RESERVED, v)
#endif

/*!
 * @brief HW_PWM_PWMSAR - PWM Sample Register
 *
 * The PWM sample register (PWM_PWMSAR) is the input to the FIFO. 16-bit
 * words are loaded into the FIFO. The FIFO can be written and read when
 * the PWM is disabled The FIFO can be written at any time, but can be read only when the PWM is
 * enabled.   The PWM will run at the last set duty-cycle setting                             if all
 * the values of the FIFO has been utilized, until the FIFO is                             reloaded
 * or the PWM is disabled. When a new value is written, the duty                             cycle
 * changes after the current period is over.  A value of zero in the sample register will result in
 * the ipp_pwm_pwmo                             output signal always being low/high (POUTC = 00 it
 * will be low and POUTC                             = 01 it will be high), and no output waveform
 * will be produced. If the                             value in this register is higher than the
 * PERIOD + 1, the output will                             never be set/reset depending on POUTC
 * value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SAMPLE : 16; //!< Sample Value. This is the input to the 4x16 FIFO. The value in this register denotes the value of the sample being currently used.
        unsigned RESERVED : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
    } B;
} hw_pwm_pwmsar_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMSAR register
 */
#define HW_PWM_PWMSAR_ADDR(x)      (REGS_PWM_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMSAR(x)           (*(volatile hw_pwm_pwmsar_t *) HW_PWM_PWMSAR_ADDR(x))
#define HW_PWM_PWMSAR_RD(x)        (HW_PWM_PWMSAR(x).U)
#define HW_PWM_PWMSAR_WR(x, v)     (HW_PWM_PWMSAR(x).U = (v))
#define HW_PWM_PWMSAR_SET(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) |  (v)))
#define HW_PWM_PWMSAR_CLR(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) & ~(v)))
#define HW_PWM_PWMSAR_TOG(x, v)    (HW_PWM_PWMSAR_WR(x, HW_PWM_PWMSAR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMSAR bitfields
 */

/* --- Register HW_PWM_PWMSAR, field SAMPLE
 *
 * Sample Value. This is the input to the 4x16 FIFO. The value in this
 * register denotes the value of the sample being currently used.
 */

#define BP_PWM_PWMSAR_SAMPLE      0
#define BM_PWM_PWMSAR_SAMPLE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSAR_SAMPLE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#else
#define BF_PWM_PWMSAR_SAMPLE(v)   (((v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSAR_SAMPLE(v)   BF_CS1(PWM_PWMSAR, SAMPLE, v)
#endif

/* --- Register HW_PWM_PWMSAR, field RESERVED
 *
 * These are reserved bits and writing a value will not affect the
 * functionality of PWM and are always read as zero.
 */

#define BP_PWM_PWMSAR_RESERVED      16
#define BM_PWM_PWMSAR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSAR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMSAR_RESERVED)
#else
#define BF_PWM_PWMSAR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMSAR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMSAR_RESERVED(v)   BF_CS1(PWM_PWMSAR, RESERVED, v)
#endif

/*!
 * @brief HW_PWM_PWMPR - PWM Period Register
 *
 * The PWM period register (PWM_PWMPR) determines the period of the PWM
 * output signal. After the counter value matches PERIOD + 1, the counter
 * is reset to start another period.  PWMO (Hz) = PCLK(Hz) / (period +2)  A value of zero in the
 * PWM_PWMPR will result in a period of two clock                             cycles for the output
 * signal. Writing 0xFFFF to this register will                             achieve the same result
 * as writing 0xFFFE.  A change in the period value due to a write in PWM_PWMPR results in the
 * counter being reset to zero and the start of a new count period.  Settings PWM_PWMPR to 0xFFFF
 * when PWMx_PWMCR REPEAT bits are set to non-zero values is not allowed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERIOD : 16; //!< Period Value. These bits determine the Period of the count cycle. The counter counts up to [Period Value] +1 and is then reset to 0x0000.
        unsigned RESERVED : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
    } B;
} hw_pwm_pwmpr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMPR register
 */
#define HW_PWM_PWMPR_ADDR(x)      (REGS_PWM_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMPR(x)           (*(volatile hw_pwm_pwmpr_t *) HW_PWM_PWMPR_ADDR(x))
#define HW_PWM_PWMPR_RD(x)        (HW_PWM_PWMPR(x).U)
#define HW_PWM_PWMPR_WR(x, v)     (HW_PWM_PWMPR(x).U = (v))
#define HW_PWM_PWMPR_SET(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) |  (v)))
#define HW_PWM_PWMPR_CLR(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) & ~(v)))
#define HW_PWM_PWMPR_TOG(x, v)    (HW_PWM_PWMPR_WR(x, HW_PWM_PWMPR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMPR bitfields
 */

/* --- Register HW_PWM_PWMPR, field PERIOD
 *
 * Period Value. These bits determine the Period of the count cycle. The
 * counter counts up to [Period Value] +1 and is then reset to
 * 0x0000.
 */

#define BP_PWM_PWMPR_PERIOD      0
#define BM_PWM_PWMPR_PERIOD      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMPR_PERIOD(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMPR_PERIOD)
#else
#define BF_PWM_PWMPR_PERIOD(v)   (((v) << 0) & BM_PWM_PWMPR_PERIOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMPR_PERIOD(v)   BF_CS1(PWM_PWMPR, PERIOD, v)
#endif

/* --- Register HW_PWM_PWMPR, field RESERVED
 *
 * These are reserved bits and writing a value will not affect the
 * functionality of PWM and are always read as zero.
 */

#define BP_PWM_PWMPR_RESERVED      16
#define BM_PWM_PWMPR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMPR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMPR_RESERVED)
#else
#define BF_PWM_PWMPR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMPR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMPR_RESERVED(v)   BF_CS1(PWM_PWMPR, RESERVED, v)
#endif

/*!
 * @brief HW_PWM_PWMCNR - PWM Counter Register
 *
 * The read-only pulse-width modulator counter register (PWM_PWMCNR)
 * contains the current count value and can be read at any time without
 * disturbing the counter.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 16; //!< Counter Value. These bits are the counter register value and denotes the current count state the counter register is in.
        unsigned RESERVED : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
    } B;
} hw_pwm_pwmcnr_t;
#endif

/*
 * constants & macros for entire multi-block PWM_PWMCNR register
 */
#define HW_PWM_PWMCNR_ADDR(x)      (REGS_PWM_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_PWM_PWMCNR(x)           (*(volatile hw_pwm_pwmcnr_t *) HW_PWM_PWMCNR_ADDR(x))
#define HW_PWM_PWMCNR_RD(x)        (HW_PWM_PWMCNR(x).U)
#define HW_PWM_PWMCNR_WR(x, v)     (HW_PWM_PWMCNR(x).U = (v))
#define HW_PWM_PWMCNR_SET(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) |  (v)))
#define HW_PWM_PWMCNR_CLR(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) & ~(v)))
#define HW_PWM_PWMCNR_TOG(x, v)    (HW_PWM_PWMCNR_WR(x, HW_PWM_PWMCNR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual PWM_PWMCNR bitfields
 */

/* --- Register HW_PWM_PWMCNR, field COUNT
 *
 * Counter Value. These bits are the counter register value and denotes
 * the current count state the counter register is in.
 */

#define BP_PWM_PWMCNR_COUNT      0
#define BM_PWM_PWMCNR_COUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCNR_COUNT(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMCNR_COUNT)
#else
#define BF_PWM_PWMCNR_COUNT(v)   (((v) << 0) & BM_PWM_PWMCNR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCNR_COUNT(v)   BF_CS1(PWM_PWMCNR, COUNT, v)
#endif

/* --- Register HW_PWM_PWMCNR, field RESERVED
 *
 * These are reserved bits and writing a value will not affect the
 * functionality of PWM and are always read as zero.
 */

#define BP_PWM_PWMCNR_RESERVED      16
#define BM_PWM_PWMCNR_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCNR_RESERVED(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMCNR_RESERVED)
#else
#define BF_PWM_PWMCNR_RESERVED(v)   (((v) << 16) & BM_PWM_PWMCNR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PWM_PWMCNR_RESERVED(v)   BF_CS1(PWM_PWMCNR, RESERVED, v)
#endif



/*!
 * @brief All PWM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_pwm_pwmcr_t PWMCR; //!< PWM Control Register
    volatile hw_pwm_pwmsr_t PWMSR; //!< PWM Status Register
    volatile hw_pwm_pwmir_t PWMIR; //!< PWM Interrupt Register
    volatile hw_pwm_pwmsar_t PWMSAR; //!< PWM Sample Register
    volatile hw_pwm_pwmpr_t PWMPR; //!< PWM Period Register
    volatile hw_pwm_pwmcnr_t PWMCNR; //!< PWM Counter Register
} hw_pwm_t
#endif

//! @brief Macro to access all PWM registers.
//! @param x PWM instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PWM(0)</code>.
#define HW_PWM(x)     (*(volatile hw_pwm_t *) REGS_PWM_BASE(x))


#endif // _PWM_H
