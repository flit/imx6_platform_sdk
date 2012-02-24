/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _GPIO_H
#define _GPIO_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_GPIO_DR - GPIO data register
 * - HW_GPIO_GDIR - GPIO direction register
 * - HW_GPIO_PSR - GPIO pad status register
 * - HW_GPIO_ICR1 - GPIO interrupt configuration register1
 * - HW_GPIO_ICR2 - GPIO interrupt configuration register2
 * - HW_GPIO_IMR - GPIO interrupt mask register
 * - HW_GPIO_ISR - GPIO interrupt status register
 * - HW_GPIO_EDGE_SEL - GPIO edge select register
 *
 * hw_gpio_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_GPIO_BASE
#define REGS_GPIO0_BASE (0x0209c000) //!< Base address for GPIO instance number 0.
#define REGS_GPIO1_BASE (0x020a0000) //!< Base address for GPIO instance number 1.
#define REGS_GPIO2_BASE (0x020a4000) //!< Base address for GPIO instance number 2.
#define REGS_GPIO3_BASE (0x020a8000) //!< Base address for GPIO instance number 3.
#define REGS_GPIO4_BASE (0x020ac000) //!< Base address for GPIO instance number 4.
#define REGS_GPIO5_BASE (0x020b0000) //!< Base address for GPIO instance number 5.
#define REGS_GPIO6_BASE (0x020b4000) //!< Base address for GPIO instance number 6.

//! @brief Get the base address of GPIO by instance number.
//! @param x GPIO instance number, from 0 through 7.
#define REGS_GPIO_BASE(x) ( x == 0 ? REGS_GPIO0_BASE : x == 1 ? REGS_GPIO1_BASE : x == 2 ? REGS_GPIO2_BASE : x == 3 ? REGS_GPIO3_BASE : x == 4 ? REGS_GPIO4_BASE : x == 5 ? REGS_GPIO5_BASE : x == 6 ? REGS_GPIO6_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_DR - GPIO data register (RW)
 *
 * The 32-bit GPIO_DR register stores data that is ready to be driven to the output lines. If the
 * IOMUXC is in GPIO mode and a given GPIO direction bit is set, then the corresponding DR bit is
 * driven to the output. If a given GPIO direction bit is cleared, then a read of GPIO_DR reflects
 * the value of the corresponding signal.Two wait states are required in read access for
 * synchronization.  The results of a read of a DR bit depends on the IOMUXC input mode settings and
 * the corresponding GDIR bit as follows:   If GDIR[ n ] is set and IOMUXC input mode is GPIO, then
 * reading DR[ n ] returns the contents of DR[ n ].  If GDIR[ n ] is cleared and IOMUXC input mode
 * is GPIO, then reading DR[ n ] returns the corresponding input signal's value.  If GDIR[ n ] is
 * set and IOMUXC input mode is not GPIO, then reading DR[ n ] returns the contents of DR[ n ].  If
 * GDIR[ n ] is cleared and IOMUXC input mode is not GPIO, then reading DR[ n ] always returns zero.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DR : 32; //!< Data bits. This register defines the value of the GPIO output when the signal is configured as an output (GDIR[n]=1). Writes to this register are stored in a register. Reading GPIO_DR returns the value stored in the register if the signal is configured as an output (GDIR[n]=1), or the input signal's value if configured as an input (GDIR[n]=0). The I/O multiplexer must be configured to GPIO mode for the GPIO_DR value to connect with the signal. Reading the data register with the input path disabled always returns a zero value.
    } B;
} hw_gpio_dr_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_DR register
 */
#define HW_GPIO_DR_ADDR(x)      (REGS_GPIO_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_DR(x)           (*(volatile hw_gpio_dr_t *) HW_GPIO_DR_ADDR(x))
#define HW_GPIO_DR_RD(x)        (HW_GPIO_DR(x).U)
#define HW_GPIO_DR_WR(x, v)     (HW_GPIO_DR(x).U = (v))
#define HW_GPIO_DR_SET(x, v)    (HW_GPIO_DR_WR(x, HW_GPIO_DR_RD(x) |  (v)))
#define HW_GPIO_DR_CLR(x, v)    (HW_GPIO_DR_WR(x, HW_GPIO_DR_RD(x) & ~(v)))
#define HW_GPIO_DR_TOG(x, v)    (HW_GPIO_DR_WR(x, HW_GPIO_DR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_DR bitfields
 */

/* --- Register HW_GPIO_DR, field DR (RW)
 *
 * Data bits. This register defines the value of the GPIO output when the signal is configured as an
 * output (GDIR[n]=1). Writes to this register are stored in a register. Reading GPIO_DR returns the
 * value stored in the register if the signal is configured as an output (GDIR[n]=1), or the input
 * signal's value if configured as an input (GDIR[n]=0). The I/O multiplexer must be configured to
 * GPIO mode for the GPIO_DR value to connect with the signal. Reading the data register with the
 * input path disabled always returns a zero value.
 */

#define BP_GPIO_DR_DR      0
#define BM_GPIO_DR_DR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_DR_DR(v)   ((((reg32_t) v) << 0) & BM_GPIO_DR_DR)
#else
#define BF_GPIO_DR_DR(v)   (((v) << 0) & BM_GPIO_DR_DR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DR field to a new value.
#define BW_GPIO_DR_DR(v)   BF_CS1(GPIO_DR, DR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_GDIR - GPIO direction register (RW)
 *
 * GPIO_GDIR functions as direction control when the IOMUXC is in GPIO mode. Each bit specifies the
 * direction of a one-bit signal. The mapping of each DIR bit to a corresponding SoC signal is
 * determined by the SoC's pin assignment and the IOMUX table-for more details consult the IOMUXC
 * chapter.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GDIR : 32; //!< GPIO direction bits. Bit n of this register defines the direction of the GPIO[n] signal. GPIO_GDIR affects only the direction of the I/O signal when the corresponding bit in the I/O MUX is configured for GPIO.
    } B;
} hw_gpio_gdir_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_GDIR register
 */
#define HW_GPIO_GDIR_ADDR(x)      (REGS_GPIO_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_GDIR(x)           (*(volatile hw_gpio_gdir_t *) HW_GPIO_GDIR_ADDR(x))
#define HW_GPIO_GDIR_RD(x)        (HW_GPIO_GDIR(x).U)
#define HW_GPIO_GDIR_WR(x, v)     (HW_GPIO_GDIR(x).U = (v))
#define HW_GPIO_GDIR_SET(x, v)    (HW_GPIO_GDIR_WR(x, HW_GPIO_GDIR_RD(x) |  (v)))
#define HW_GPIO_GDIR_CLR(x, v)    (HW_GPIO_GDIR_WR(x, HW_GPIO_GDIR_RD(x) & ~(v)))
#define HW_GPIO_GDIR_TOG(x, v)    (HW_GPIO_GDIR_WR(x, HW_GPIO_GDIR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_GDIR bitfields
 */

/* --- Register HW_GPIO_GDIR, field GDIR (RW)
 *
 * GPIO direction bits. Bit n of this register defines the direction of the GPIO[n] signal.
 * GPIO_GDIR affects only the direction of the I/O signal when the corresponding bit in the I/O MUX
 * is configured for GPIO.
 *
 * Values:
 * 0 - GPIO is configured as input.
 * 1 - GPIO is configured as output.
 */

#define BP_GPIO_GDIR_GDIR      0
#define BM_GPIO_GDIR_GDIR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_GDIR_GDIR(v)   ((((reg32_t) v) << 0) & BM_GPIO_GDIR_GDIR)
#else
#define BF_GPIO_GDIR_GDIR(v)   (((v) << 0) & BM_GPIO_GDIR_GDIR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GDIR field to a new value.
#define BW_GPIO_GDIR_GDIR(v)   BF_CS1(GPIO_GDIR, GDIR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_PSR - GPIO pad status register (RO)
 *
 * GPIO_PSR is a read-only register. Each bit stores the value of the corresponding input signal (as
 * configured in the IOMUX). This register is clocked with the ipg_clk_s clock, meaning that the
 * input signal is sampled only when accessing this location. Two wait states are required any time
 * this register is accessed for synchronization.  PSR[i]-pad sample
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PSR : 32; //!< GPIO pad status bits (status bits). Reading GPIO_PSR returns the state of the corresponding input signal. Settings: The I/O multiplexer must be configured to GPIO mode for GPIO_PSR to reflect the state of the corresponding signal. [What happens if the IOMUX is not configured to GPIO mode? Does it return 0?-- cpt]
    } B;
} hw_gpio_psr_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_PSR register
 */
#define HW_GPIO_PSR_ADDR(x)      (REGS_GPIO_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_PSR(x)           (*(volatile hw_gpio_psr_t *) HW_GPIO_PSR_ADDR(x))
#define HW_GPIO_PSR_RD(x)        (HW_GPIO_PSR(x).U)
#endif

/*
 * constants & macros for individual GPIO_PSR bitfields
 */

/* --- Register HW_GPIO_PSR, field PSR (RO)
 *
 * GPIO pad status bits (status bits). Reading GPIO_PSR returns the state of the corresponding input
 * signal. Settings: The I/O multiplexer must be configured to GPIO mode for GPIO_PSR to reflect the
 * state of the corresponding signal. [What happens if the IOMUX is not configured to GPIO mode?
 * Does it return 0?-- cpt]
 */

#define BP_GPIO_PSR_PSR      0
#define BM_GPIO_PSR_PSR      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_ICR1 - GPIO interrupt configuration register1 (RW)
 *
 * GPIO_ICR1 contains 16 two-bit fields, where each field specifies the interrupt configuration for
 * a different input signal.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ICR0 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR1 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR2 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR3 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR4 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR5 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR6 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR7 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR8 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR9 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR10 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR11 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR12 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR13 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR14 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR15 : 2; //!< Interrupt configuration 1 fields. This register controls the active condition of the interrupt function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
    } B;
} hw_gpio_icr1_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_ICR1 register
 */
#define HW_GPIO_ICR1_ADDR(x)      (REGS_GPIO_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_ICR1(x)           (*(volatile hw_gpio_icr1_t *) HW_GPIO_ICR1_ADDR(x))
#define HW_GPIO_ICR1_RD(x)        (HW_GPIO_ICR1(x).U)
#define HW_GPIO_ICR1_WR(x, v)     (HW_GPIO_ICR1(x).U = (v))
#define HW_GPIO_ICR1_SET(x, v)    (HW_GPIO_ICR1_WR(x, HW_GPIO_ICR1_RD(x) |  (v)))
#define HW_GPIO_ICR1_CLR(x, v)    (HW_GPIO_ICR1_WR(x, HW_GPIO_ICR1_RD(x) & ~(v)))
#define HW_GPIO_ICR1_TOG(x, v)    (HW_GPIO_ICR1_WR(x, HW_GPIO_ICR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_ICR1 bitfields
 */

/* --- Register HW_GPIO_ICR1, field ICR0 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR0      0
#define BM_GPIO_ICR1_ICR0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR0(v)   ((((reg32_t) v) << 0) & BM_GPIO_ICR1_ICR0)
#else
#define BF_GPIO_ICR1_ICR0(v)   (((v) << 0) & BM_GPIO_ICR1_ICR0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR0 field to a new value.
#define BW_GPIO_ICR1_ICR0(v)   BF_CS1(GPIO_ICR1, ICR0, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR1 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR1      2
#define BM_GPIO_ICR1_ICR1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR1(v)   ((((reg32_t) v) << 2) & BM_GPIO_ICR1_ICR1)
#else
#define BF_GPIO_ICR1_ICR1(v)   (((v) << 2) & BM_GPIO_ICR1_ICR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR1 field to a new value.
#define BW_GPIO_ICR1_ICR1(v)   BF_CS1(GPIO_ICR1, ICR1, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR2 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR2      4
#define BM_GPIO_ICR1_ICR2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR2(v)   ((((reg32_t) v) << 4) & BM_GPIO_ICR1_ICR2)
#else
#define BF_GPIO_ICR1_ICR2(v)   (((v) << 4) & BM_GPIO_ICR1_ICR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR2 field to a new value.
#define BW_GPIO_ICR1_ICR2(v)   BF_CS1(GPIO_ICR1, ICR2, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR3 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR3      6
#define BM_GPIO_ICR1_ICR3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR3(v)   ((((reg32_t) v) << 6) & BM_GPIO_ICR1_ICR3)
#else
#define BF_GPIO_ICR1_ICR3(v)   (((v) << 6) & BM_GPIO_ICR1_ICR3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR3 field to a new value.
#define BW_GPIO_ICR1_ICR3(v)   BF_CS1(GPIO_ICR1, ICR3, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR4 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR4      8
#define BM_GPIO_ICR1_ICR4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR4(v)   ((((reg32_t) v) << 8) & BM_GPIO_ICR1_ICR4)
#else
#define BF_GPIO_ICR1_ICR4(v)   (((v) << 8) & BM_GPIO_ICR1_ICR4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR4 field to a new value.
#define BW_GPIO_ICR1_ICR4(v)   BF_CS1(GPIO_ICR1, ICR4, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR5 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR5      10
#define BM_GPIO_ICR1_ICR5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR5(v)   ((((reg32_t) v) << 10) & BM_GPIO_ICR1_ICR5)
#else
#define BF_GPIO_ICR1_ICR5(v)   (((v) << 10) & BM_GPIO_ICR1_ICR5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR5 field to a new value.
#define BW_GPIO_ICR1_ICR5(v)   BF_CS1(GPIO_ICR1, ICR5, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR6 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR6      12
#define BM_GPIO_ICR1_ICR6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR6(v)   ((((reg32_t) v) << 12) & BM_GPIO_ICR1_ICR6)
#else
#define BF_GPIO_ICR1_ICR6(v)   (((v) << 12) & BM_GPIO_ICR1_ICR6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR6 field to a new value.
#define BW_GPIO_ICR1_ICR6(v)   BF_CS1(GPIO_ICR1, ICR6, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR7 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR7      14
#define BM_GPIO_ICR1_ICR7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR7(v)   ((((reg32_t) v) << 14) & BM_GPIO_ICR1_ICR7)
#else
#define BF_GPIO_ICR1_ICR7(v)   (((v) << 14) & BM_GPIO_ICR1_ICR7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR7 field to a new value.
#define BW_GPIO_ICR1_ICR7(v)   BF_CS1(GPIO_ICR1, ICR7, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR8 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR8      16
#define BM_GPIO_ICR1_ICR8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR8(v)   ((((reg32_t) v) << 16) & BM_GPIO_ICR1_ICR8)
#else
#define BF_GPIO_ICR1_ICR8(v)   (((v) << 16) & BM_GPIO_ICR1_ICR8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR8 field to a new value.
#define BW_GPIO_ICR1_ICR8(v)   BF_CS1(GPIO_ICR1, ICR8, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR9 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR9      18
#define BM_GPIO_ICR1_ICR9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR9(v)   ((((reg32_t) v) << 18) & BM_GPIO_ICR1_ICR9)
#else
#define BF_GPIO_ICR1_ICR9(v)   (((v) << 18) & BM_GPIO_ICR1_ICR9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR9 field to a new value.
#define BW_GPIO_ICR1_ICR9(v)   BF_CS1(GPIO_ICR1, ICR9, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR10 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR10      20
#define BM_GPIO_ICR1_ICR10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR10(v)   ((((reg32_t) v) << 20) & BM_GPIO_ICR1_ICR10)
#else
#define BF_GPIO_ICR1_ICR10(v)   (((v) << 20) & BM_GPIO_ICR1_ICR10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR10 field to a new value.
#define BW_GPIO_ICR1_ICR10(v)   BF_CS1(GPIO_ICR1, ICR10, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR11 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR11      22
#define BM_GPIO_ICR1_ICR11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR11(v)   ((((reg32_t) v) << 22) & BM_GPIO_ICR1_ICR11)
#else
#define BF_GPIO_ICR1_ICR11(v)   (((v) << 22) & BM_GPIO_ICR1_ICR11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR11 field to a new value.
#define BW_GPIO_ICR1_ICR11(v)   BF_CS1(GPIO_ICR1, ICR11, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR12 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR12      24
#define BM_GPIO_ICR1_ICR12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR12(v)   ((((reg32_t) v) << 24) & BM_GPIO_ICR1_ICR12)
#else
#define BF_GPIO_ICR1_ICR12(v)   (((v) << 24) & BM_GPIO_ICR1_ICR12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR12 field to a new value.
#define BW_GPIO_ICR1_ICR12(v)   BF_CS1(GPIO_ICR1, ICR12, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR13 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR13      26
#define BM_GPIO_ICR1_ICR13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR13(v)   ((((reg32_t) v) << 26) & BM_GPIO_ICR1_ICR13)
#else
#define BF_GPIO_ICR1_ICR13(v)   (((v) << 26) & BM_GPIO_ICR1_ICR13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR13 field to a new value.
#define BW_GPIO_ICR1_ICR13(v)   BF_CS1(GPIO_ICR1, ICR13, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR14 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR14      28
#define BM_GPIO_ICR1_ICR14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR14(v)   ((((reg32_t) v) << 28) & BM_GPIO_ICR1_ICR14)
#else
#define BF_GPIO_ICR1_ICR14(v)   (((v) << 28) & BM_GPIO_ICR1_ICR14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR14 field to a new value.
#define BW_GPIO_ICR1_ICR14(v)   BF_CS1(GPIO_ICR1, ICR14, v)
#endif


/* --- Register HW_GPIO_ICR1, field ICR15 (RW)
 *
 * Interrupt configuration 1 fields. This register controls the active condition of the interrupt
 * function for lines 15 to 0. Settings: Bits ICRn[1:0] determine the interrupt condition for signal
 * n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR1_ICR15      30
#define BM_GPIO_ICR1_ICR15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR1_ICR15(v)   ((((reg32_t) v) << 30) & BM_GPIO_ICR1_ICR15)
#else
#define BF_GPIO_ICR1_ICR15(v)   (((v) << 30) & BM_GPIO_ICR1_ICR15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR15 field to a new value.
#define BW_GPIO_ICR1_ICR15(v)   BF_CS1(GPIO_ICR1, ICR15, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_ICR2 - GPIO interrupt configuration register2 (RW)
 *
 * GPIO_ICR2 contains 16 two-bit fields, where each field specifies the interrupt configuration for
 * a different input signal.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ICR16 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR17 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR18 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR19 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR20 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR21 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR22 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR23 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR24 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR25 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR26 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR27 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR28 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR29 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR30 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
        unsigned ICR31 : 2; //!< Interrupt configuration 2 fields. This register controls the active condition of the interrupt function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for signal n as follows:
    } B;
} hw_gpio_icr2_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_ICR2 register
 */
#define HW_GPIO_ICR2_ADDR(x)      (REGS_GPIO_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_ICR2(x)           (*(volatile hw_gpio_icr2_t *) HW_GPIO_ICR2_ADDR(x))
#define HW_GPIO_ICR2_RD(x)        (HW_GPIO_ICR2(x).U)
#define HW_GPIO_ICR2_WR(x, v)     (HW_GPIO_ICR2(x).U = (v))
#define HW_GPIO_ICR2_SET(x, v)    (HW_GPIO_ICR2_WR(x, HW_GPIO_ICR2_RD(x) |  (v)))
#define HW_GPIO_ICR2_CLR(x, v)    (HW_GPIO_ICR2_WR(x, HW_GPIO_ICR2_RD(x) & ~(v)))
#define HW_GPIO_ICR2_TOG(x, v)    (HW_GPIO_ICR2_WR(x, HW_GPIO_ICR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_ICR2 bitfields
 */

/* --- Register HW_GPIO_ICR2, field ICR16 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR16      0
#define BM_GPIO_ICR2_ICR16      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR16(v)   ((((reg32_t) v) << 0) & BM_GPIO_ICR2_ICR16)
#else
#define BF_GPIO_ICR2_ICR16(v)   (((v) << 0) & BM_GPIO_ICR2_ICR16)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR16 field to a new value.
#define BW_GPIO_ICR2_ICR16(v)   BF_CS1(GPIO_ICR2, ICR16, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR17 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR17      2
#define BM_GPIO_ICR2_ICR17      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR17(v)   ((((reg32_t) v) << 2) & BM_GPIO_ICR2_ICR17)
#else
#define BF_GPIO_ICR2_ICR17(v)   (((v) << 2) & BM_GPIO_ICR2_ICR17)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR17 field to a new value.
#define BW_GPIO_ICR2_ICR17(v)   BF_CS1(GPIO_ICR2, ICR17, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR18 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR18      4
#define BM_GPIO_ICR2_ICR18      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR18(v)   ((((reg32_t) v) << 4) & BM_GPIO_ICR2_ICR18)
#else
#define BF_GPIO_ICR2_ICR18(v)   (((v) << 4) & BM_GPIO_ICR2_ICR18)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR18 field to a new value.
#define BW_GPIO_ICR2_ICR18(v)   BF_CS1(GPIO_ICR2, ICR18, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR19 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR19      6
#define BM_GPIO_ICR2_ICR19      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR19(v)   ((((reg32_t) v) << 6) & BM_GPIO_ICR2_ICR19)
#else
#define BF_GPIO_ICR2_ICR19(v)   (((v) << 6) & BM_GPIO_ICR2_ICR19)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR19 field to a new value.
#define BW_GPIO_ICR2_ICR19(v)   BF_CS1(GPIO_ICR2, ICR19, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR20 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR20      8
#define BM_GPIO_ICR2_ICR20      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR20(v)   ((((reg32_t) v) << 8) & BM_GPIO_ICR2_ICR20)
#else
#define BF_GPIO_ICR2_ICR20(v)   (((v) << 8) & BM_GPIO_ICR2_ICR20)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR20 field to a new value.
#define BW_GPIO_ICR2_ICR20(v)   BF_CS1(GPIO_ICR2, ICR20, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR21 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR21      10
#define BM_GPIO_ICR2_ICR21      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR21(v)   ((((reg32_t) v) << 10) & BM_GPIO_ICR2_ICR21)
#else
#define BF_GPIO_ICR2_ICR21(v)   (((v) << 10) & BM_GPIO_ICR2_ICR21)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR21 field to a new value.
#define BW_GPIO_ICR2_ICR21(v)   BF_CS1(GPIO_ICR2, ICR21, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR22 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR22      12
#define BM_GPIO_ICR2_ICR22      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR22(v)   ((((reg32_t) v) << 12) & BM_GPIO_ICR2_ICR22)
#else
#define BF_GPIO_ICR2_ICR22(v)   (((v) << 12) & BM_GPIO_ICR2_ICR22)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR22 field to a new value.
#define BW_GPIO_ICR2_ICR22(v)   BF_CS1(GPIO_ICR2, ICR22, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR23 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR23      14
#define BM_GPIO_ICR2_ICR23      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR23(v)   ((((reg32_t) v) << 14) & BM_GPIO_ICR2_ICR23)
#else
#define BF_GPIO_ICR2_ICR23(v)   (((v) << 14) & BM_GPIO_ICR2_ICR23)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR23 field to a new value.
#define BW_GPIO_ICR2_ICR23(v)   BF_CS1(GPIO_ICR2, ICR23, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR24 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR24      16
#define BM_GPIO_ICR2_ICR24      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR24(v)   ((((reg32_t) v) << 16) & BM_GPIO_ICR2_ICR24)
#else
#define BF_GPIO_ICR2_ICR24(v)   (((v) << 16) & BM_GPIO_ICR2_ICR24)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR24 field to a new value.
#define BW_GPIO_ICR2_ICR24(v)   BF_CS1(GPIO_ICR2, ICR24, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR25 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR25      18
#define BM_GPIO_ICR2_ICR25      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR25(v)   ((((reg32_t) v) << 18) & BM_GPIO_ICR2_ICR25)
#else
#define BF_GPIO_ICR2_ICR25(v)   (((v) << 18) & BM_GPIO_ICR2_ICR25)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR25 field to a new value.
#define BW_GPIO_ICR2_ICR25(v)   BF_CS1(GPIO_ICR2, ICR25, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR26 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR26      20
#define BM_GPIO_ICR2_ICR26      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR26(v)   ((((reg32_t) v) << 20) & BM_GPIO_ICR2_ICR26)
#else
#define BF_GPIO_ICR2_ICR26(v)   (((v) << 20) & BM_GPIO_ICR2_ICR26)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR26 field to a new value.
#define BW_GPIO_ICR2_ICR26(v)   BF_CS1(GPIO_ICR2, ICR26, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR27 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR27      22
#define BM_GPIO_ICR2_ICR27      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR27(v)   ((((reg32_t) v) << 22) & BM_GPIO_ICR2_ICR27)
#else
#define BF_GPIO_ICR2_ICR27(v)   (((v) << 22) & BM_GPIO_ICR2_ICR27)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR27 field to a new value.
#define BW_GPIO_ICR2_ICR27(v)   BF_CS1(GPIO_ICR2, ICR27, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR28 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR28      24
#define BM_GPIO_ICR2_ICR28      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR28(v)   ((((reg32_t) v) << 24) & BM_GPIO_ICR2_ICR28)
#else
#define BF_GPIO_ICR2_ICR28(v)   (((v) << 24) & BM_GPIO_ICR2_ICR28)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR28 field to a new value.
#define BW_GPIO_ICR2_ICR28(v)   BF_CS1(GPIO_ICR2, ICR28, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR29 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR29      26
#define BM_GPIO_ICR2_ICR29      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR29(v)   ((((reg32_t) v) << 26) & BM_GPIO_ICR2_ICR29)
#else
#define BF_GPIO_ICR2_ICR29(v)   (((v) << 26) & BM_GPIO_ICR2_ICR29)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR29 field to a new value.
#define BW_GPIO_ICR2_ICR29(v)   BF_CS1(GPIO_ICR2, ICR29, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR30 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR30      28
#define BM_GPIO_ICR2_ICR30      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR30(v)   ((((reg32_t) v) << 28) & BM_GPIO_ICR2_ICR30)
#else
#define BF_GPIO_ICR2_ICR30(v)   (((v) << 28) & BM_GPIO_ICR2_ICR30)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR30 field to a new value.
#define BW_GPIO_ICR2_ICR30(v)   BF_CS1(GPIO_ICR2, ICR30, v)
#endif


/* --- Register HW_GPIO_ICR2, field ICR31 (RW)
 *
 * Interrupt configuration 2 fields. This register controls the active condition of the interrupt
 * function for lines 31 to 16. Settings: Bits ICRn[1:0] determine the interrupt condition for
 * signal n as follows:
 *
 * Values:
 * 00 - Interrupt n is low-level sensitive.
 * 01 - Interrupt n is high-level sensitive.
 * 10 - Interrupt n is rising-edge sensitive.
 * 11 - Interrupt n is falling-edge sensitive.
 */

#define BP_GPIO_ICR2_ICR31      30
#define BM_GPIO_ICR2_ICR31      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ICR2_ICR31(v)   ((((reg32_t) v) << 30) & BM_GPIO_ICR2_ICR31)
#else
#define BF_GPIO_ICR2_ICR31(v)   (((v) << 30) & BM_GPIO_ICR2_ICR31)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ICR31 field to a new value.
#define BW_GPIO_ICR2_ICR31(v)   BF_CS1(GPIO_ICR2, ICR31, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_IMR - GPIO interrupt mask register (RW)
 *
 * GPIO_IMR contains masking bits for each interrupt line.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IMR : 32; //!< Interrupt Mask bits. This register is used to enable or disable the interrupt function on each of the 32 GPIO signals. Settings: Bit IMR[n] (n=0...31) controls interrupt n as follows:
    } B;
} hw_gpio_imr_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_IMR register
 */
#define HW_GPIO_IMR_ADDR(x)      (REGS_GPIO_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_IMR(x)           (*(volatile hw_gpio_imr_t *) HW_GPIO_IMR_ADDR(x))
#define HW_GPIO_IMR_RD(x)        (HW_GPIO_IMR(x).U)
#define HW_GPIO_IMR_WR(x, v)     (HW_GPIO_IMR(x).U = (v))
#define HW_GPIO_IMR_SET(x, v)    (HW_GPIO_IMR_WR(x, HW_GPIO_IMR_RD(x) |  (v)))
#define HW_GPIO_IMR_CLR(x, v)    (HW_GPIO_IMR_WR(x, HW_GPIO_IMR_RD(x) & ~(v)))
#define HW_GPIO_IMR_TOG(x, v)    (HW_GPIO_IMR_WR(x, HW_GPIO_IMR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_IMR bitfields
 */

/* --- Register HW_GPIO_IMR, field IMR (RW)
 *
 * Interrupt Mask bits. This register is used to enable or disable the interrupt function on each of
 * the 32 GPIO signals. Settings: Bit IMR[n] (n=0...31) controls interrupt n as follows:
 *
 * Values:
 * 0 - Interrupt n is disabled.
 * 1 - Interrupt n is enabled.
 */

#define BP_GPIO_IMR_IMR      0
#define BM_GPIO_IMR_IMR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_IMR_IMR(v)   ((((reg32_t) v) << 0) & BM_GPIO_IMR_IMR)
#else
#define BF_GPIO_IMR_IMR(v)   (((v) << 0) & BM_GPIO_IMR_IMR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IMR field to a new value.
#define BW_GPIO_IMR_IMR(v)   BF_CS1(GPIO_IMR, IMR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_ISR - GPIO interrupt status register (W1C)
 *
 * The GPIO_ISR functions as an interrupt status indicator. Each bit indicates whether an interrupt
 * condition has been met for the corresponding input signal. When an interrupt condition is met (as
 * determined by the corresponding interrupt condition register field), the corresponding bit in
 * this register is set. Two wait states are required in read access for synchronization. One wait
 * state is required for reset.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ISR : 32; //!< Interrupt status bits - Bit n of this register is asserted (active high) when the active condition (as determined by the corresponding ICR bit) is detected on the GPIO input and is waiting for service. The value of this register is independent of the value in GPIO_IMR. When the active condition has been detected, the corresponding bit remains set until cleared by software. Status flags are cleared by writing a 1 to the corresponding bit position.
    } B;
} hw_gpio_isr_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_ISR register
 */
#define HW_GPIO_ISR_ADDR(x)      (REGS_GPIO_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_ISR(x)           (*(volatile hw_gpio_isr_t *) HW_GPIO_ISR_ADDR(x))
#define HW_GPIO_ISR_RD(x)        (HW_GPIO_ISR(x).U)
#define HW_GPIO_ISR_WR(x, v)     (HW_GPIO_ISR(x).U = (v))
#define HW_GPIO_ISR_SET(x, v)    (HW_GPIO_ISR_WR(x, HW_GPIO_ISR_RD(x) |  (v)))
#define HW_GPIO_ISR_CLR(x, v)    (HW_GPIO_ISR_WR(x, HW_GPIO_ISR_RD(x) & ~(v)))
#define HW_GPIO_ISR_TOG(x, v)    (HW_GPIO_ISR_WR(x, HW_GPIO_ISR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_ISR bitfields
 */

/* --- Register HW_GPIO_ISR, field ISR (W1C)
 *
 * Interrupt status bits - Bit n of this register is asserted (active high) when the active
 * condition (as determined by the corresponding ICR bit) is detected on the GPIO input and is
 * waiting for service. The value of this register is independent of the value in GPIO_IMR. When the
 * active condition has been detected, the corresponding bit remains set until cleared by software.
 * Status flags are cleared by writing a 1 to the corresponding bit position.
 */

#define BP_GPIO_ISR_ISR      0
#define BM_GPIO_ISR_ISR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_ISR_ISR(v)   ((((reg32_t) v) << 0) & BM_GPIO_ISR_ISR)
#else
#define BF_GPIO_ISR_ISR(v)   (((v) << 0) & BM_GPIO_ISR_ISR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ISR field to a new value.
#define BW_GPIO_ISR_ISR(v)   BF_CS1(GPIO_ISR, ISR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_GPIO_EDGE_SEL - GPIO edge select register (RW)
 *
 * GPIO_EDGE_SEL may be used to override the ICR registers' configuration. If the GPIO_EDGE_SEL bit
 * is set, then a rising edge or falling edge in the corresponding signal generates an interrupt.
 * This register provides backward compatibility. On reset all bits are cleared (ICR is not
 * overridden). [Is this single EDGE_SEL register valid for all the GPIO's on the SoC? If so, should
 * mention this -- CThron]
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPIO_EDGE_SEL : 32; //!< Edge select. When GPIO_EDGE_SEL[ n ] is set, the GPIO disregards the ICR[ n ] setting, and detects any edge on the corresponding input signal.
    } B;
} hw_gpio_edge_sel_t;
#endif

/*
 * constants & macros for entire multi-block GPIO_EDGE_SEL register
 */
#define HW_GPIO_EDGE_SEL_ADDR(x)      (REGS_GPIO_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_GPIO_EDGE_SEL(x)           (*(volatile hw_gpio_edge_sel_t *) HW_GPIO_EDGE_SEL_ADDR(x))
#define HW_GPIO_EDGE_SEL_RD(x)        (HW_GPIO_EDGE_SEL(x).U)
#define HW_GPIO_EDGE_SEL_WR(x, v)     (HW_GPIO_EDGE_SEL(x).U = (v))
#define HW_GPIO_EDGE_SEL_SET(x, v)    (HW_GPIO_EDGE_SEL_WR(x, HW_GPIO_EDGE_SEL_RD(x) |  (v)))
#define HW_GPIO_EDGE_SEL_CLR(x, v)    (HW_GPIO_EDGE_SEL_WR(x, HW_GPIO_EDGE_SEL_RD(x) & ~(v)))
#define HW_GPIO_EDGE_SEL_TOG(x, v)    (HW_GPIO_EDGE_SEL_WR(x, HW_GPIO_EDGE_SEL_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual GPIO_EDGE_SEL bitfields
 */

/* --- Register HW_GPIO_EDGE_SEL, field GPIO_EDGE_SEL (RW)
 *
 * Edge select. When GPIO_EDGE_SEL[ n ] is set, the GPIO disregards the ICR[ n ] setting, and
 * detects any edge on the corresponding input signal.
 */

#define BP_GPIO_EDGE_SEL_GPIO_EDGE_SEL      0
#define BM_GPIO_EDGE_SEL_GPIO_EDGE_SEL      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_GPIO_EDGE_SEL_GPIO_EDGE_SEL(v)   ((((reg32_t) v) << 0) & BM_GPIO_EDGE_SEL_GPIO_EDGE_SEL)
#else
#define BF_GPIO_EDGE_SEL_GPIO_EDGE_SEL(v)   (((v) << 0) & BM_GPIO_EDGE_SEL_GPIO_EDGE_SEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPIO_EDGE_SEL field to a new value.
#define BW_GPIO_EDGE_SEL_GPIO_EDGE_SEL(v)   BF_CS1(GPIO_EDGE_SEL, GPIO_EDGE_SEL, v)
#endif


/*!
 * @brief All GPIO module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_gpio_dr_t DR; //!< GPIO data register
    volatile hw_gpio_gdir_t GDIR; //!< GPIO direction register
    volatile hw_gpio_psr_t PSR; //!< GPIO pad status register
    volatile hw_gpio_icr1_t ICR1; //!< GPIO interrupt configuration register1
    volatile hw_gpio_icr2_t ICR2; //!< GPIO interrupt configuration register2
    volatile hw_gpio_imr_t IMR; //!< GPIO interrupt mask register
    volatile hw_gpio_isr_t ISR; //!< GPIO interrupt status register
    volatile hw_gpio_edge_sel_t EDGE_SEL; //!< GPIO edge select register
} hw_gpio_t;
#endif

//! @brief Macro to access all GPIO registers.
//! @param x GPIO instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_GPIO(0)</code>.
#define HW_GPIO(x)     (*(volatile hw_gpio_t *) REGS_GPIO_BASE(x))


#endif // _GPIO_H
