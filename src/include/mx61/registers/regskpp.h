/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _KPP_H
#define _KPP_H

#include "regs.h"

#ifndef REGS_KPP_BASE
#define REGS_KPP_BASE (REGS_BASE + 0x020b8000)
#endif


/*!
 * @brief HW_KPP_KPCR - Keypad Control Register
 *
 * The Keypad Control Register determines which of the eight possible column
 * strobes are to be open drain when configured as outputs, and which of
 * the eight row sense lines are considered in generating an interrupt to
 * the core.  It is up to the programmer to ensure that pins being used for functions
 * other than the keypad are properly disabled. The KPP_KPCR register is
 * byte- or half-word-addressable.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KRE : 8; //!< Keypad Row Enable. Setting a row enable control bit in this register enables the corresponding row line to participate in interrupt generation. Likewise, clearing a bit disables that row from being used to generate an interrupt. This register is cleared by a reset, disabling all rows. The row-enable logic is independent of the programmed direction of the pin. Writing a "0" to the data register of the pins configured as outputs will cause a keypad interrupt to be generated if the row enable associated with that bit is set.
        unsigned short KCO : 8; //!< Keypad Column Strobe Open-Drain Enable. Setting a column open-drain enable bit (KCO7-KCO0) disables the pull-up driver on that pin. Clearing the bit allows the pin to drive to the high state. This bit has no effect when the pin is configured as an input.  Configuration of external port control logic (for example, IOMUX) should be done properly so that the KPP controls an open-drain enable of the pin.
    } B;
} hw_kpp_kpcr_t;
#endif

/*
 * constants & macros for entire KPP_KPCR register
 */
#define HW_KPP_KPCR_ADDR      (REGS_KPP_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPCR           (*(volatile hw_kpp_kpcr_t *) HW_KPP_KPCR_ADDR)
#define HW_KPP_KPCR_RD()      (HW_KPP_KPCR.U)
#define HW_KPP_KPCR_WR(v)     (HW_KPP_KPCR.U = (v))
#define HW_KPP_KPCR_SET(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() |  (v)))
#define HW_KPP_KPCR_CLR(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() & ~(v)))
#define HW_KPP_KPCR_TOG(v)    (HW_KPP_KPCR_WR(HW_KPP_KPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPCR bitfields
 */

/* --- Register HW_KPP_KPCR, field KRE
 *
 * Keypad Row Enable. Setting a row enable control bit in this register
 * enables the corresponding row line to participate in interrupt
 * generation. Likewise, clearing a bit disables that row from being
 * used to generate an interrupt. This register is cleared by a reset,
 * disabling all rows. The row-enable logic is independent of the
 * programmed direction of the pin. Writing a "0" to the data register
 * of the pins configured as outputs will cause a keypad interrupt to
 * be generated if the row enable associated with that bit is set.
 */

#define BP_KPP_KPCR_KRE      0
#define BM_KPP_KPCR_KRE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPCR_KRE(v)   ((((reg32_t) v) << 0) & BM_KPP_KPCR_KRE)
#else
#define BF_KPP_KPCR_KRE(v)   (((v) << 0) & BM_KPP_KPCR_KRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPCR_KRE(v)   BF_CS1(KPP_KPCR, KRE, v)
#endif

/* --- Register HW_KPP_KPCR, field KCO
 *
 * Keypad Column Strobe Open-Drain Enable. Setting a column open-drain
 * enable bit (KCO7-KCO0) disables the pull-up driver on that pin.
 * Clearing the bit allows the pin to drive to the high state. This bit
 * has no effect when the pin is configured as an input.  Configuration of external port control
 * logic (for example, IOMUX)                                 should be done properly so that the
 * KPP controls an open-drain                                 enable of the pin.
 */

#define BP_KPP_KPCR_KCO      8
#define BM_KPP_KPCR_KCO      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPCR_KCO(v)   ((((reg32_t) v) << 8) & BM_KPP_KPCR_KCO)
#else
#define BF_KPP_KPCR_KCO(v)   (((v) << 8) & BM_KPP_KPCR_KCO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPCR_KCO(v)   BF_CS1(KPP_KPCR, KCO, v)
#endif

/*!
 * @brief HW_KPP_KPSR - Keypad Status Register
 *
 * The Keypad Status Register reflects the state of the key press detect
 * circuit. The KPP_KPSR register is byte- or half-word-addressable.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KPKD : 1; //!< Keypad Key Depress. The keypad key depress (KPKD) status bit is set when one or more enabled rows are detected low after synchronization. The KPKD status bit remains set until cleared by the software. The KPKD bit may be used to generate a maskable key depress interrupt. If desired, the software may clear the key press synchronizer chain to allow a repeated interrupt to be generated while a key remains pressed. In this case, a new interrupt will be generated after the synchronizer delay (4 cycles of the low frequency reference clock (ipg_clk_32k) elapses if a key remains pressed. This functionality can be used to detect a long key press. This allows detection of additional key presses of the same key or other keys.  Due to the logic function of the release and depress synchronizer chains, it is possible to see the re-assertion of a status flag (KPKD or KPKR) if it is cleared by the software prior to the system exiting the state it represents.
        unsigned short KPKR : 1; //!< Keypad Key Release. The keypad key release (KPKR) status bit is set when all enabled rows are detected high after synchronization (the KPKR status bit will be set when cleared by a reset). The KPKR bit may be used to generate a maskable key release interrupt. The key release synchronizer may be set high by software after scanning the keypad to ensure a known state. Due to the logic function of the release and depress synchronizer chains, it is possible to see the re-assertion of a status flag (KPKD or KPKR) if it is cleared by software prior to the system exiting the state it represents.  Reset value of register is "0" as long as reset is asserted. However when reset is de-asserted, the value of the register depends upon the external row pins and can become "1".
        unsigned short KDSC : 1; //!< Key Depress Synchronizer Clear. Self-clear bit. The Key depress synchronizer is cleared by writing a logic "1" into this bit.  Reads return a value of "0".
        unsigned short KPP : 1; //!< Key Release Synchronizer Set. Self-clear bit. The Key release synchronizer is set by writing a logic one into this bit.  Reads return a value of "0".
        unsigned short RESERVED0 : 4; //!< Reserved, should be cleared
        unsigned short KDIE : 1; //!< Keypad Key Depress Interrupt Enable. Software should ensure that the interrupt for a Key Release event is masked until it has entered the key pressed state, and vice-versa, unless this activity is desired (as might be the case when a repeated interrupt is to be generated). The synchronizer chains are capable of being initialized to detect repeated key presses or releases. If they are not initialized when the corresponding event flag is cleared, false interrupts may be generated for depress (or release) events shorter than the length of the corresponding chain.
        unsigned short KRIE : 1; //!< Keypad Release Interrupt Enable. The software should ensure that the interrupt for a Key Release event is masked until it has entered the key pressed state, and vice versa, unless this activity is desired (as might be the case when a repeated interrupt is to be generated). The synchronizer chains are capable of being initialized to detect repeated key presses or releases. If they are not initialized when the corresponding event flag is cleared, false interrupts may be generated for depress (or release) events shorter than the length of the corresponding chain.
        unsigned short RESERVED1 : 6; //!< Reserved
    } B;
} hw_kpp_kpsr_t;
#endif

/*
 * constants & macros for entire KPP_KPSR register
 */
#define HW_KPP_KPSR_ADDR      (REGS_KPP_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPSR           (*(volatile hw_kpp_kpsr_t *) HW_KPP_KPSR_ADDR)
#define HW_KPP_KPSR_RD()      (HW_KPP_KPSR.U)
#define HW_KPP_KPSR_WR(v)     (HW_KPP_KPSR.U = (v))
#define HW_KPP_KPSR_SET(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() |  (v)))
#define HW_KPP_KPSR_CLR(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() & ~(v)))
#define HW_KPP_KPSR_TOG(v)    (HW_KPP_KPSR_WR(HW_KPP_KPSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPSR bitfields
 */

/* --- Register HW_KPP_KPSR, field KPKD
 *
 * Keypad Key Depress. The keypad key depress (KPKD) status bit is set
 * when one or more enabled rows are detected low after
 * synchronization. The KPKD status bit remains set until cleared by
 * the software. The KPKD bit may be used to generate a maskable key
 * depress interrupt. If desired, the software may clear the key press
 * synchronizer chain to allow a repeated interrupt to be generated
 * while a key remains pressed. In this case, a new interrupt will be
 * generated after the synchronizer delay (4 cycles of the low
 * frequency reference clock (ipg_clk_32k) elapses if a key remains pressed. This functionality can
 * be                                 used to detect a long key press. This allows detection of
 * additional                                 key presses of the same key or other keys.  Due to the
 * logic function of the release and depress synchronizer                                 chains, it
 * is possible to see the re-assertion of a status flag                                 (KPKD or
 * KPKR) if it is cleared by the software prior to the system
 * exiting the state it represents.
 */

#define BP_KPP_KPSR_KPKD      0
#define BM_KPP_KPSR_KPKD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPKD(v)   ((((reg32_t) v) << 0) & BM_KPP_KPSR_KPKD)
#else
#define BF_KPP_KPSR_KPKD(v)   (((v) << 0) & BM_KPP_KPSR_KPKD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPKD(v)   BF_CS1(KPP_KPSR, KPKD, v)
#endif

/* --- Register HW_KPP_KPSR, field KPKR
 *
 * Keypad Key Release. The keypad key release (KPKR) status bit is set
 * when all enabled rows are detected high after synchronization (the
 * KPKR status bit will be set when cleared by a reset). The KPKR bit
 * may be used to generate a maskable key release interrupt. The key
 * release synchronizer may be set high by software after scanning the
 * keypad to ensure a known state. Due to the logic function of the
 * release and depress synchronizer chains, it is possible to see the
 * re-assertion of a status flag (KPKD or KPKR) if it is cleared by
 * software prior to the system exiting the state it represents.  Reset value of register is "0" as
 * long as reset is asserted. However                                 when reset is de-asserted, the
 * value of the register depends upon                                 the external row pins and can
 * become "1".
 */

#define BP_KPP_KPSR_KPKR      1
#define BM_KPP_KPSR_KPKR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPKR(v)   ((((reg32_t) v) << 1) & BM_KPP_KPSR_KPKR)
#else
#define BF_KPP_KPSR_KPKR(v)   (((v) << 1) & BM_KPP_KPSR_KPKR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPKR(v)   BF_CS1(KPP_KPSR, KPKR, v)
#endif

/* --- Register HW_KPP_KPSR, field KDSC
 *
 * Key Depress Synchronizer Clear. Self-clear bit. The Key depress
 * synchronizer is cleared by writing a logic "1" into this bit.  Reads return a value of "0".
 */

#define BP_KPP_KPSR_KDSC      2
#define BM_KPP_KPSR_KDSC      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KDSC(v)   ((((reg32_t) v) << 2) & BM_KPP_KPSR_KDSC)
#else
#define BF_KPP_KPSR_KDSC(v)   (((v) << 2) & BM_KPP_KPSR_KDSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KDSC(v)   BF_CS1(KPP_KPSR, KDSC, v)
#endif

/* --- Register HW_KPP_KPSR, field KPP
 *
 * Key Release Synchronizer Set. Self-clear bit. The Key release
 * synchronizer is set by writing a logic one into this bit.  Reads return a value of "0".
 */

#define BP_KPP_KPSR_KPP      3
#define BM_KPP_KPSR_KPP      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KPP(v)   ((((reg32_t) v) << 3) & BM_KPP_KPSR_KPP)
#else
#define BF_KPP_KPSR_KPP(v)   (((v) << 3) & BM_KPP_KPSR_KPP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KPP(v)   BF_CS1(KPP_KPSR, KPP, v)
#endif

/* --- Register HW_KPP_KPSR, field KDIE
 *
 * Keypad Key Depress Interrupt Enable. Software should ensure that the
 * interrupt for a Key Release event is masked until it has entered the
 * key pressed state, and vice-versa, unless this activity is desired
 * (as might be the case when a repeated interrupt is to be generated).
 * The synchronizer chains are capable of being initialized to detect
 * repeated key presses or releases. If they are not initialized when
 * the corresponding event flag is cleared, false interrupts may be
 * generated for depress (or release) events shorter than the length of
 * the corresponding chain.
 */

#define BP_KPP_KPSR_KDIE      8
#define BM_KPP_KPSR_KDIE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KDIE(v)   ((((reg32_t) v) << 8) & BM_KPP_KPSR_KDIE)
#else
#define BF_KPP_KPSR_KDIE(v)   (((v) << 8) & BM_KPP_KPSR_KDIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KDIE(v)   BF_CS1(KPP_KPSR, KDIE, v)
#endif

/* --- Register HW_KPP_KPSR, field KRIE
 *
 * Keypad Release Interrupt Enable. The software should ensure that the
 * interrupt for a Key Release event is masked until it has entered the
 * key pressed state, and vice versa, unless this activity is desired
 * (as might be the case when a repeated interrupt is to be generated).
 * The synchronizer chains are capable of being initialized to detect
 * repeated key presses or releases. If they are not initialized when
 * the corresponding event flag is cleared, false interrupts may be
 * generated for depress (or release) events shorter than the length of
 * the corresponding chain.
 */

#define BP_KPP_KPSR_KRIE      9
#define BM_KPP_KPSR_KRIE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPSR_KRIE(v)   ((((reg32_t) v) << 9) & BM_KPP_KPSR_KRIE)
#else
#define BF_KPP_KPSR_KRIE(v)   (((v) << 9) & BM_KPP_KPSR_KRIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPSR_KRIE(v)   BF_CS1(KPP_KPSR, KRIE, v)
#endif

/*!
 * @brief HW_KPP_KDDR - Keypad Data Direction Register
 *
 * The bits in the KPP_KDDR control the direction of the keypad port pins.
 * The upper eight bits in the register affect the pins designated as
 * column strobes, while the lower eight bits affect the row sense pins.
 * Setting any bit in this register configures the corresponding pin as an
 * output. Clearing any bit in this register configures the corresponding
 * port pin as an input. For the Keypad Row DDR, an internal pull-up is
 * enabled if the corresponding bit is clear. This register is cleared by a
 * reset, configuring all pins as inputs. The KPP_KDDR register is byte- or
 * half-word addressable.  When a pin is used as row pin for keypad purposes, all corresponding
 * pull-ups should be enabled at the upper level (for example, IOMUX) when
 * the bit in row DDR is cleared.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KRDD : 8; //!< Keypad Row Data Direction. Setting a bit configures the corresponding ROW n pin as an output (where n = 7 through 0).
        unsigned short KCDD : 8; //!< Keypad Column Data Direction Register. Setting a bit configures the corresponding COL n pin as an output (where n = 7 through 0).
    } B;
} hw_kpp_kddr_t;
#endif

/*
 * constants & macros for entire KPP_KDDR register
 */
#define HW_KPP_KDDR_ADDR      (REGS_KPP_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KDDR           (*(volatile hw_kpp_kddr_t *) HW_KPP_KDDR_ADDR)
#define HW_KPP_KDDR_RD()      (HW_KPP_KDDR.U)
#define HW_KPP_KDDR_WR(v)     (HW_KPP_KDDR.U = (v))
#define HW_KPP_KDDR_SET(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() |  (v)))
#define HW_KPP_KDDR_CLR(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() & ~(v)))
#define HW_KPP_KDDR_TOG(v)    (HW_KPP_KDDR_WR(HW_KPP_KDDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KDDR bitfields
 */

/* --- Register HW_KPP_KDDR, field KRDD
 *
 * Keypad Row Data Direction. Setting a bit configures the corresponding
 * ROW n pin as an output (where n = 7 through 0).
 */

#define BP_KPP_KDDR_KRDD      0
#define BM_KPP_KDDR_KRDD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KDDR_KRDD(v)   ((((reg32_t) v) << 0) & BM_KPP_KDDR_KRDD)
#else
#define BF_KPP_KDDR_KRDD(v)   (((v) << 0) & BM_KPP_KDDR_KRDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KDDR_KRDD(v)   BF_CS1(KPP_KDDR, KRDD, v)
#endif

/* --- Register HW_KPP_KDDR, field KCDD
 *
 * Keypad Column Data Direction Register. Setting a bit configures the
 * corresponding COL n pin as an output (where n = 7                                 through 0).
 */

#define BP_KPP_KDDR_KCDD      8
#define BM_KPP_KDDR_KCDD      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KDDR_KCDD(v)   ((((reg32_t) v) << 8) & BM_KPP_KDDR_KCDD)
#else
#define BF_KPP_KDDR_KCDD(v)   (((v) << 8) & BM_KPP_KDDR_KCDD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KDDR_KCDD(v)   BF_CS1(KPP_KDDR, KCDD, v)
#endif

/*!
 * @brief HW_KPP_KPDR - Keypad Data Register
 *
 * This 16-bit register is used to access the column and row data. Data
 * written to this register is stored in an internal latch, and for each
 * pin configured as an output, the stored data is driven onto the pin. A
 * read of this register returns the value on the pin for those bits
 * configured as inputs. Otherwise, the value read is the value stored in
 * the register.  The KPP_KPDR register is byte- or half-word addressable. This register is
 * not initialized by a reset. Valid data should be written to this
 * register before any bits are configured as outputs.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short KRD : 8; //!< Keypad Row Data. A read of these bits returns the value on the pin for those bits configured as inputs. Otherwise, the value read is the value stored in the register.  0 Read/Write "0" from/to row ports  1 Read/Write "1" from/to row ports
        unsigned short KCD : 8; //!< Keypad Column Data. A read of these bits returns the value on the pin for those bits configured as inputs. Otherwise, the value read is the value stored in the register.  0 Read/Write "0" from/to column ports  1 Read/Write "1" from/to column ports
    } B;
} hw_kpp_kpdr_t;
#endif

/*
 * constants & macros for entire KPP_KPDR register
 */
#define HW_KPP_KPDR_ADDR      (REGS_KPP_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_KPP_KPDR           (*(volatile hw_kpp_kpdr_t *) HW_KPP_KPDR_ADDR)
#define HW_KPP_KPDR_RD()      (HW_KPP_KPDR.U)
#define HW_KPP_KPDR_WR(v)     (HW_KPP_KPDR.U = (v))
#define HW_KPP_KPDR_SET(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() |  (v)))
#define HW_KPP_KPDR_CLR(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() & ~(v)))
#define HW_KPP_KPDR_TOG(v)    (HW_KPP_KPDR_WR(HW_KPP_KPDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual KPP_KPDR bitfields
 */

/* --- Register HW_KPP_KPDR, field KRD
 *
 * Keypad Row Data. A read of these bits returns the value on the pin
 * for those bits configured as inputs. Otherwise, the value read is
 * the value stored in the register.  0 Read/Write "0" from/to row ports  1 Read/Write "1" from/to
 * row ports
 */

#define BP_KPP_KPDR_KRD      0
#define BM_KPP_KPDR_KRD      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPDR_KRD(v)   ((((reg32_t) v) << 0) & BM_KPP_KPDR_KRD)
#else
#define BF_KPP_KPDR_KRD(v)   (((v) << 0) & BM_KPP_KPDR_KRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPDR_KRD(v)   BF_CS1(KPP_KPDR, KRD, v)
#endif

/* --- Register HW_KPP_KPDR, field KCD
 *
 * Keypad Column Data. A read of these bits returns the value on the pin
 * for those bits configured as inputs. Otherwise, the value read is
 * the value stored in the register.  0 Read/Write "0" from/to column ports  1 Read/Write "1"
 * from/to column ports
 */

#define BP_KPP_KPDR_KCD      8
#define BM_KPP_KPDR_KCD      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_KPP_KPDR_KCD(v)   ((((reg32_t) v) << 8) & BM_KPP_KPDR_KCD)
#else
#define BF_KPP_KPDR_KCD(v)   (((v) << 8) & BM_KPP_KPDR_KCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_KPP_KPDR_KCD(v)   BF_CS1(KPP_KPDR, KCD, v)
#endif



/*!
 * @brief All KPP module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_kpp_kpcr_t KPCR; //!< Keypad Control Register
    volatile hw_kpp_kpsr_t KPSR; //!< Keypad Status Register
    volatile hw_kpp_kddr_t KDDR; //!< Keypad Data Direction Register
    volatile hw_kpp_kpdr_t KPDR; //!< Keypad Data Register
} hw_kpp_t
#endif

//! @brief Macro to access all KPP registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_KPP(0)</code>.
#define HW_KPP     (*(volatile hw_kpp_t *) REGS_KPP_BASE)


#endif // _KPP_H
