/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PWM_H
#define _PWM_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_PWM_PWMCR - PWM Control Register
 * - HW_PWM_PWMSR - PWM Status Register
 * - HW_PWM_PWMIR - PWM Interrupt Register
 * - HW_PWM_PWMSAR - PWM Sample Register
 * - HW_PWM_PWMPR - PWM Period Register
 * - HW_PWM_PWMCNR - PWM Counter Register
 *
 * hw_pwm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PWM_BASE
#define REGS_PWM0_BASE (0x02080000) //!< Base address for PWM instance number 0.
#define REGS_PWM1_BASE (0x02084000) //!< Base address for PWM instance number 1.
#define REGS_PWM2_BASE (0x02088000) //!< Base address for PWM instance number 2.
#define REGS_PWM3_BASE (0x0208c000) //!< Base address for PWM instance number 3.

//! @brief Get the base address of PWM by instance number.
//! @param x PWM instance number, from 0 through 4.
#define REGS_PWM_BASE(x) ( x == 0 ? REGS_PWM0_BASE : x == 1 ? REGS_PWM1_BASE : x == 2 ? REGS_PWM2_BASE : x == 3 ? REGS_PWM3_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMCR - PWM Control Register (RW)
 *
 * The PWM control register (PWM_PWMCR) is used to configure the operating settings of the PWM. It
 * contains the prescaler for the clock division.
 */
typedef union
{
    reg32_t U;
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
        unsigned DBGEN : 1; //!< Debug Mode Enable. This bit keeps the PWM functional in debug mode. When this bit is cleared, the input clock is gated off in debug mode. This bit is not affected by software reset. It is cleared by hardware reset.
        unsigned WAITEN : 1; //!< Wait Mode Enable. This bit keeps the PWM functional in wait mode. When this bit is cleared, the input clock is gated off in wait mode. This bit is not affected by software reset. It is cleared by hardware reset.
        unsigned DOZEN : 1; //!< Doze Mode Enable. This bit keeps the PWM functional in doze mode. When this bit is cleared, the input clock is gated off in doze mode. This bit is not affected by software reset. It is cleared by hardware reset.
        unsigned STOPEN : 1; //!< Stop Mode Enable. This bit keeps the PWM functional while in stop mode. When this bit is cleared, the input clock is gated off in stop mode. This bit is not affected by software reset. It is cleared by hardware reset.
        unsigned FWM : 2; //!< FIFO Water Mark. These bits are used to set the data level at which the FIFO empty flag will be set and the corresponding interrupt generated
        unsigned RESERVED0 : 4; //!< Reserved. These reserved bits are always read as zero.
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

/* --- Register HW_PWM_PWMCR, field EN (RW)
 *
 * PWM Enable. This bit enables the PWM. If this bit is not enabled, the clock prescaler and the
 * counter is reset. When the PWM is enabled, it begins a new period, the output pin is set to start
 * a new period while the prescaler and counter are released and counting begins.
 *
 * Values:
 * 0 - PWM disabled
 * 1 - PWM enabled
 */

#define BP_PWM_PWMCR_EN      0
#define BM_PWM_PWMCR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_EN(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMCR_EN)
#else
#define BF_PWM_PWMCR_EN(v)   (((v) << 0) & BM_PWM_PWMCR_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_PWM_PWMCR_EN(v)   BF_CS1(PWM_PWMCR, EN, v)
#endif


/* --- Register HW_PWM_PWMCR, field REPEAT (RW)
 *
 * Sample Repeat. This bit field determines the number of times each sample from the FIFO is to be
 * used.
 *
 * Values:
 * 00 - Use each sample once
 * 01 - Use each sample twice
 * 10 - Use each sample four times
 * 11 - Use each sample eight times
 */

#define BP_PWM_PWMCR_REPEAT      1
#define BM_PWM_PWMCR_REPEAT      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_REPEAT(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMCR_REPEAT)
#else
#define BF_PWM_PWMCR_REPEAT(v)   (((v) << 1) & BM_PWM_PWMCR_REPEAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the REPEAT field to a new value.
#define BW_PWM_PWMCR_REPEAT(v)   BF_CS1(PWM_PWMCR, REPEAT, v)
#endif


/* --- Register HW_PWM_PWMCR, field SWR (RW)
 *
 * Software Reset. PWM is reset when this bit is set to 1. It is a self clearing bit. A write 1 to
 * this bit is a single wait state write cycle. When the block is in reset state this bit is set and
 * is cleared when the reset procedure is over. Setting this bit resets all the registers to their
 * reset values except for the STOPEN, DOZEN, WAITEN, and DBGEN bits in this control register
 * Technically, the previous tagging isn't correct as "DBGEN" should be tagged as
 * feature="pwm_debug_yes".-JC .
 *
 * Values:
 * 0 - PWM is out of reset
 * 1 - PWM is undergoing reset
 */

#define BP_PWM_PWMCR_SWR      3
#define BM_PWM_PWMCR_SWR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_SWR(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMCR_SWR)
#else
#define BF_PWM_PWMCR_SWR(v)   (((v) << 3) & BM_PWM_PWMCR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_PWM_PWMCR_SWR(v)   BF_CS1(PWM_PWMCR, SWR, v)
#endif


/* --- Register HW_PWM_PWMCR, field PRESCALER (RW)
 *
 * Counter Clock Prescaler Value. This bit field determines the value by which the clock will be
 * divided before it goes to the counter.
 *
 * Values:
 * 0x000 - Divide by 1
 * 0x001 - Divide by 2
 * 0xfff - Divide by 4096
 */

#define BP_PWM_PWMCR_PRESCALER      4
#define BM_PWM_PWMCR_PRESCALER      0x0000fff0

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_PRESCALER(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMCR_PRESCALER)
#else
#define BF_PWM_PWMCR_PRESCALER(v)   (((v) << 4) & BM_PWM_PWMCR_PRESCALER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESCALER field to a new value.
#define BW_PWM_PWMCR_PRESCALER(v)   BF_CS1(PWM_PWMCR, PRESCALER, v)
#endif


/* --- Register HW_PWM_PWMCR, field CLKSRC (RW)
 *
 * Select Clock Source. These bits determine which clock input will be selected for running the
 * counter. After reset the system functional clock is selected. The input clock can also be turned
 * off if these bits are set to 00. This field value should only be changed when the PWM is disabled
 *
 * Values:
 * 00 - Clock is off
 * 01 - ipg_clk
 * 10 - ipg_clk_highfreq Clock is off
 * 11 - ipg_clk_32k Clock is off
 */

#define BP_PWM_PWMCR_CLKSRC      16
#define BM_PWM_PWMCR_CLKSRC      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_CLKSRC(v)   ((((reg32_t) v) << 16) & BM_PWM_PWMCR_CLKSRC)
#else
#define BF_PWM_PWMCR_CLKSRC(v)   (((v) << 16) & BM_PWM_PWMCR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKSRC field to a new value.
#define BW_PWM_PWMCR_CLKSRC(v)   BF_CS1(PWM_PWMCR, CLKSRC, v)
#endif


/* --- Register HW_PWM_PWMCR, field POUTC (RW)
 *
 * PWM Output Configuration. This bit field determines the mode of PWM output on the output pin.
 *
 * Values:
 * 00 - Output pin is set at rollover and cleared at comparison
 * 01 - Output pin is cleared at rollover and set at comparison
 * 10 - PWM output is disconnected
 * 11 - PWM output is disconnected
 */

#define BP_PWM_PWMCR_POUTC      18
#define BM_PWM_PWMCR_POUTC      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_POUTC(v)   ((((reg32_t) v) << 18) & BM_PWM_PWMCR_POUTC)
#else
#define BF_PWM_PWMCR_POUTC(v)   (((v) << 18) & BM_PWM_PWMCR_POUTC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the POUTC field to a new value.
#define BW_PWM_PWMCR_POUTC(v)   BF_CS1(PWM_PWMCR, POUTC, v)
#endif


/* --- Register HW_PWM_PWMCR, field HCTR (RW)
 *
 * Half-word Data Swap Control. This bit determines which half word data from the 32-bit IP Bus
 * interface is written into the lower 16 bits of the sample register.
 *
 * Values:
 * 0 - Half word swapping does not take place
 * 1 - Half words from write data bus are swapped
 */

#define BP_PWM_PWMCR_HCTR      20
#define BM_PWM_PWMCR_HCTR      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_HCTR(v)   ((((reg32_t) v) << 20) & BM_PWM_PWMCR_HCTR)
#else
#define BF_PWM_PWMCR_HCTR(v)   (((v) << 20) & BM_PWM_PWMCR_HCTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCTR field to a new value.
#define BW_PWM_PWMCR_HCTR(v)   BF_CS1(PWM_PWMCR, HCTR, v)
#endif


/* --- Register HW_PWM_PWMCR, field BCTR (RW)
 *
 * Byte Data Swap Control. This bit determines the byte ordering of the 16-bit data when it goes
 * into the FIFO from the sample register.
 *
 * Values:
 * 0 - byte ordering remains the same
 * 1 - byte ordering is reversed
 */

#define BP_PWM_PWMCR_BCTR      21
#define BM_PWM_PWMCR_BCTR      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_BCTR(v)   ((((reg32_t) v) << 21) & BM_PWM_PWMCR_BCTR)
#else
#define BF_PWM_PWMCR_BCTR(v)   (((v) << 21) & BM_PWM_PWMCR_BCTR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCTR field to a new value.
#define BW_PWM_PWMCR_BCTR(v)   BF_CS1(PWM_PWMCR, BCTR, v)
#endif


/* --- Register HW_PWM_PWMCR, field DBGEN (RW)
 *
 * Debug Mode Enable. This bit keeps the PWM functional in debug mode. When this bit is cleared, the
 * input clock is gated off in debug mode. This bit is not affected by software reset. It is cleared
 * by hardware reset.
 *
 * Values:
 * 0 - Inactive in debug mode
 * 1 - Active in debug mode
 */

#define BP_PWM_PWMCR_DBGEN      22
#define BM_PWM_PWMCR_DBGEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_DBGEN(v)   ((((reg32_t) v) << 22) & BM_PWM_PWMCR_DBGEN)
#else
#define BF_PWM_PWMCR_DBGEN(v)   (((v) << 22) & BM_PWM_PWMCR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_PWM_PWMCR_DBGEN(v)   BF_CS1(PWM_PWMCR, DBGEN, v)
#endif


/* --- Register HW_PWM_PWMCR, field WAITEN (RW)
 *
 * Wait Mode Enable. This bit keeps the PWM functional in wait mode. When this bit is cleared, the
 * input clock is gated off in wait mode. This bit is not affected by software reset. It is cleared
 * by hardware reset.
 *
 * Values:
 * 0 - Inactive in wait mode
 * 1 - Active in wait mode
 */

#define BP_PWM_PWMCR_WAITEN      23
#define BM_PWM_PWMCR_WAITEN      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_WAITEN(v)   ((((reg32_t) v) << 23) & BM_PWM_PWMCR_WAITEN)
#else
#define BF_PWM_PWMCR_WAITEN(v)   (((v) << 23) & BM_PWM_PWMCR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAITEN field to a new value.
#define BW_PWM_PWMCR_WAITEN(v)   BF_CS1(PWM_PWMCR, WAITEN, v)
#endif


/* --- Register HW_PWM_PWMCR, field DOZEN (RW)
 *
 * Doze Mode Enable. This bit keeps the PWM functional in doze mode. When this bit is cleared, the
 * input clock is gated off in doze mode. This bit is not affected by software reset. It is cleared
 * by hardware reset.
 *
 * Values:
 * 0 - Inactive in doze mode
 * 1 - Active in doze mode
 */

#define BP_PWM_PWMCR_DOZEN      24
#define BM_PWM_PWMCR_DOZEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_DOZEN(v)   ((((reg32_t) v) << 24) & BM_PWM_PWMCR_DOZEN)
#else
#define BF_PWM_PWMCR_DOZEN(v)   (((v) << 24) & BM_PWM_PWMCR_DOZEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DOZEN field to a new value.
#define BW_PWM_PWMCR_DOZEN(v)   BF_CS1(PWM_PWMCR, DOZEN, v)
#endif


/* --- Register HW_PWM_PWMCR, field STOPEN (RW)
 *
 * Stop Mode Enable. This bit keeps the PWM functional while in stop mode. When this bit is cleared,
 * the input clock is gated off in stop mode. This bit is not affected by software reset. It is
 * cleared by hardware reset.
 *
 * Values:
 * 0 - Inactive in stop mode
 * 1 - Active in stop mode
 */

#define BP_PWM_PWMCR_STOPEN      25
#define BM_PWM_PWMCR_STOPEN      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_STOPEN(v)   ((((reg32_t) v) << 25) & BM_PWM_PWMCR_STOPEN)
#else
#define BF_PWM_PWMCR_STOPEN(v)   (((v) << 25) & BM_PWM_PWMCR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STOPEN field to a new value.
#define BW_PWM_PWMCR_STOPEN(v)   BF_CS1(PWM_PWMCR, STOPEN, v)
#endif


/* --- Register HW_PWM_PWMCR, field FWM (RW)
 *
 * FIFO Water Mark. These bits are used to set the data level at which the FIFO empty flag will be
 * set and the corresponding interrupt generated
 *
 * Values:
 * 00 - FIFO empty flag is set when there are more than or equal to 1 empty slots in FIFO
 * 01 - FIFO empty flag is set when there are more than or equal to 2 empty slots in FIFO
 * 10 - FIFO empty flag is set when there are more than or equal to 3 empty slots in FIFO
 * 11 - FIFO empty flag is set when there are more than or equal to 4 empty slots in FIFO
 */

#define BP_PWM_PWMCR_FWM      26
#define BM_PWM_PWMCR_FWM      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMCR_FWM(v)   ((((reg32_t) v) << 26) & BM_PWM_PWMCR_FWM)
#else
#define BF_PWM_PWMCR_FWM(v)   (((v) << 26) & BM_PWM_PWMCR_FWM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FWM field to a new value.
#define BW_PWM_PWMCR_FWM(v)   BF_CS1(PWM_PWMCR, FWM, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMSR - PWM Status Register (W1C)
 *
 * The PWM status register (PWM_PWMSR) contains seven bits which display the state of the FIFO and
 * the occurrence of rollover and compare events. The FIFOAV bit is read-only but the other four
 * bits can be cleared by writing 1 to them. The FE, ROV, and CMP bits are associated with FIFO-
 * Empty, Roll-over, and Compare interrupts, respectively.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FIFOAV : 3; //!< FIFO Available. These read-only bits indicate the data level remaining in the FIFO. An attempted write to these bits will not affect their value and no transfer error is generated.
        unsigned FE : 1; //!< FIFO Empty Status Bit. This bit indicates the FIFO data level in comparison to the water level set by FWM field in the control register.
        unsigned ROV : 1; //!< Roll-over Status. This bit shows that a roll-over event has occurred.
        unsigned CMP : 1; //!< Compare Status. This bit shows that a compare event has occurred.
        unsigned FWE : 1; //!< FIFO Write Error Status. This bit shows that an attempt has been made to write FIFO when it is full.
        unsigned RESERVED0 : 25; //!< Reserved. These reserved bits are always read as zero.
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

/* --- Register HW_PWM_PWMSR, field FIFOAV (RO)
 *
 * FIFO Available. These read-only bits indicate the data level remaining in the FIFO. An attempted
 * write to these bits will not affect their value and no transfer error is generated.
 *
 * Values:
 * 000 - No data available
 * 001 - 1 word of data in FIFO
 * 010 - 2 words of data in FIFO
 * 011 - 3 words of data in FIFO
 * 100 - 4 words of data in FIFO
 * 101 - unused
 * 110 - unused
 * 111 - unused
 */

#define BP_PWM_PWMSR_FIFOAV      0
#define BM_PWM_PWMSR_FIFOAV      0x00000007


/* --- Register HW_PWM_PWMSR, field FE (W1C)
 *
 * FIFO Empty Status Bit. This bit indicates the FIFO data level in comparison to the water level
 * set by FWM field in the control register.
 *
 * Values:
 * 0 - Data level is above water mark
 * 1 - When the data level falls below the mark set by FWM field
 */

#define BP_PWM_PWMSR_FE      3
#define BM_PWM_PWMSR_FE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FE(v)   ((((reg32_t) v) << 3) & BM_PWM_PWMSR_FE)
#else
#define BF_PWM_PWMSR_FE(v)   (((v) << 3) & BM_PWM_PWMSR_FE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FE field to a new value.
#define BW_PWM_PWMSR_FE(v)   BF_CS1(PWM_PWMSR, FE, v)
#endif


/* --- Register HW_PWM_PWMSR, field ROV (W1C)
 *
 * Roll-over Status. This bit shows that a roll-over event has occurred.
 *
 * Values:
 * 0 - Roll-over event not occurred
 * 1 - Roll-over event occurred
 */

#define BP_PWM_PWMSR_ROV      4
#define BM_PWM_PWMSR_ROV      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_ROV(v)   ((((reg32_t) v) << 4) & BM_PWM_PWMSR_ROV)
#else
#define BF_PWM_PWMSR_ROV(v)   (((v) << 4) & BM_PWM_PWMSR_ROV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ROV field to a new value.
#define BW_PWM_PWMSR_ROV(v)   BF_CS1(PWM_PWMSR, ROV, v)
#endif


/* --- Register HW_PWM_PWMSR, field CMP (W1C)
 *
 * Compare Status. This bit shows that a compare event has occurred.
 *
 * Values:
 * 0 - Compare event not occurred
 * 1 - Compare event occurred
 */

#define BP_PWM_PWMSR_CMP      5
#define BM_PWM_PWMSR_CMP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_CMP(v)   ((((reg32_t) v) << 5) & BM_PWM_PWMSR_CMP)
#else
#define BF_PWM_PWMSR_CMP(v)   (((v) << 5) & BM_PWM_PWMSR_CMP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CMP field to a new value.
#define BW_PWM_PWMSR_CMP(v)   BF_CS1(PWM_PWMSR, CMP, v)
#endif


/* --- Register HW_PWM_PWMSR, field FWE (W1C)
 *
 * FIFO Write Error Status. This bit shows that an attempt has been made to write FIFO when it is
 * full.
 *
 * Values:
 * 0 - FIFO write error not occurred
 * 1 - FIFO write error occurred
 */

#define BP_PWM_PWMSR_FWE      6
#define BM_PWM_PWMSR_FWE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSR_FWE(v)   ((((reg32_t) v) << 6) & BM_PWM_PWMSR_FWE)
#else
#define BF_PWM_PWMSR_FWE(v)   (((v) << 6) & BM_PWM_PWMSR_FWE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FWE field to a new value.
#define BW_PWM_PWMSR_FWE(v)   BF_CS1(PWM_PWMSR, FWE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMIR - PWM Interrupt Register (RW)
 *
 * The PWM Interrupt register (PWM_PWMIR) contains three bits which control the generation of the
 * compare, rollover and FIFO empty interrupts.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FIE : 1; //!< FIFO Empty Interrupt Enable. This bit controls the generation of the FIFO Empty interrupt.
        unsigned RIE : 1; //!< Roll-over Interrupt Enable. This bit controls the generation of the Rollover interrupt.
        unsigned CIE : 1; //!< Compare Interrupt Enable. This bit controls the generation of the Compare interrupt.
        unsigned RESERVED0 : 29; //!< Reserved. These reserved bits are always read as zero.
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

/* --- Register HW_PWM_PWMIR, field FIE (RW)
 *
 * FIFO Empty Interrupt Enable. This bit controls the generation of the FIFO Empty interrupt.
 *
 * Values:
 * 0 - FIFO Empty interrupt disabled
 * 1 - FIFO Empty interrupt enabled
 */

#define BP_PWM_PWMIR_FIE      0
#define BM_PWM_PWMIR_FIE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_FIE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMIR_FIE)
#else
#define BF_PWM_PWMIR_FIE(v)   (((v) << 0) & BM_PWM_PWMIR_FIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FIE field to a new value.
#define BW_PWM_PWMIR_FIE(v)   BF_CS1(PWM_PWMIR, FIE, v)
#endif


/* --- Register HW_PWM_PWMIR, field RIE (RW)
 *
 * Roll-over Interrupt Enable. This bit controls the generation of the Rollover interrupt.
 *
 * Values:
 * 0 - Roll-over interrupt not enabled
 * 1 - Roll-over Interrupt enabled
 */

#define BP_PWM_PWMIR_RIE      1
#define BM_PWM_PWMIR_RIE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_RIE(v)   ((((reg32_t) v) << 1) & BM_PWM_PWMIR_RIE)
#else
#define BF_PWM_PWMIR_RIE(v)   (((v) << 1) & BM_PWM_PWMIR_RIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RIE field to a new value.
#define BW_PWM_PWMIR_RIE(v)   BF_CS1(PWM_PWMIR, RIE, v)
#endif


/* --- Register HW_PWM_PWMIR, field CIE (RW)
 *
 * Compare Interrupt Enable. This bit controls the generation of the Compare interrupt.
 *
 * Values:
 * 0 - Compare Interrupt not enabled
 * 1 - Compare Interrupt enabled
 */

#define BP_PWM_PWMIR_CIE      2
#define BM_PWM_PWMIR_CIE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMIR_CIE(v)   ((((reg32_t) v) << 2) & BM_PWM_PWMIR_CIE)
#else
#define BF_PWM_PWMIR_CIE(v)   (((v) << 2) & BM_PWM_PWMIR_CIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CIE field to a new value.
#define BW_PWM_PWMIR_CIE(v)   BF_CS1(PWM_PWMIR, CIE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMSAR - PWM Sample Register (RW)
 *
 * The PWM sample register (PWM_PWMSAR) is the input to the FIFO. 16-bit words are loaded into the
 * FIFO. The FIFO can be written and read when the PWM is disabled The FIFO can be written at any
 * time, but can be read only when the PWM is enabled. The PWM will run at the last set duty-cycle
 * setting if all the values of the FIFO has been utilized, until the FIFO is reloaded or the PWM is
 * disabled. When a new value is written, the duty cycle changes after the current period is over.
 * A value of zero in the sample register will result in the ipp_pwm_pwmo output signal always being
 * low/high (POUTC = 00 it will be low and POUTC = 01 it will be high), and no output waveform will
 * be produced. If the value in this register is higher than the PERIOD + 1, the output will never
 * be set/reset depending on POUTC value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SAMPLE : 16; //!< Sample Value. This is the input to the 4x16 FIFO. The value in this register denotes the value of the sample being currently used.
        unsigned RESERVED0 : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
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

/* --- Register HW_PWM_PWMSAR, field SAMPLE (RW)
 *
 * Sample Value. This is the input to the 4x16 FIFO. The value in this register denotes the value of
 * the sample being currently used.
 */

#define BP_PWM_PWMSAR_SAMPLE      0
#define BM_PWM_PWMSAR_SAMPLE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMSAR_SAMPLE(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#else
#define BF_PWM_PWMSAR_SAMPLE(v)   (((v) << 0) & BM_PWM_PWMSAR_SAMPLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SAMPLE field to a new value.
#define BW_PWM_PWMSAR_SAMPLE(v)   BF_CS1(PWM_PWMSAR, SAMPLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMPR - PWM Period Register (RW)
 *
 * The PWM period register (PWM_PWMPR) determines the period of the PWM output signal. After the
 * counter value matches PERIOD + 1, the counter is reset to start another period.  PWMO (Hz) =
 * PCLK(Hz) / (period +2)  A value of zero in the PWM_PWMPR will result in a period of two clock
 * cycles for the output signal. Writing 0xFFFF to this register will achieve the same result as
 * writing 0xFFFE.  A change in the period value due to a write in PWM_PWMPR results in the counter
 * being reset to zero and the start of a new count period.  Settings PWM_PWMPR to 0xFFFF when
 * PWMx_PWMCR REPEAT bits are set to non-zero values is not allowed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PERIOD : 16; //!< Period Value. These bits determine the Period of the count cycle. The counter counts up to [Period Value] +1 and is then reset to 0x0000.
        unsigned RESERVED0 : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
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

/* --- Register HW_PWM_PWMPR, field PERIOD (RW)
 *
 * Period Value. These bits determine the Period of the count cycle. The counter counts up to
 * [Period Value] +1 and is then reset to 0x0000.
 */

#define BP_PWM_PWMPR_PERIOD      0
#define BM_PWM_PWMPR_PERIOD      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PWM_PWMPR_PERIOD(v)   ((((reg32_t) v) << 0) & BM_PWM_PWMPR_PERIOD)
#else
#define BF_PWM_PWMPR_PERIOD(v)   (((v) << 0) & BM_PWM_PWMPR_PERIOD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIOD field to a new value.
#define BW_PWM_PWMPR_PERIOD(v)   BF_CS1(PWM_PWMPR, PERIOD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PWM_PWMCNR - PWM Counter Register (RO)
 *
 * The read-only pulse-width modulator counter register (PWM_PWMCNR) contains the current count
 * value and can be read at any time without disturbing the counter.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned COUNT : 16; //!< Counter Value. These bits are the counter register value and denotes the current count state the counter register is in.
        unsigned RESERVED0 : 16; //!< These are reserved bits and writing a value will not affect the functionality of PWM and are always read as zero.
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
#endif

/*
 * constants & macros for individual PWM_PWMCNR bitfields
 */

/* --- Register HW_PWM_PWMCNR, field COUNT (RO)
 *
 * Counter Value. These bits are the counter register value and denotes the current count state the
 * counter register is in.
 */

#define BP_PWM_PWMCNR_COUNT      0
#define BM_PWM_PWMCNR_COUNT      0x0000ffff


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
} hw_pwm_t;
#endif

//! @brief Macro to access all PWM registers.
//! @param x PWM instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PWM(0)</code>.
#define HW_PWM(x)     (*(volatile hw_pwm_t *) REGS_PWM_BASE(x))


#endif // _PWM_H
