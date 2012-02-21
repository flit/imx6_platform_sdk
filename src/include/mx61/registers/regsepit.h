/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EPIT_H
#define _EPIT_H

#include "regs.h"

#ifndef REGS_EPIT_BASE
#define REGS_EPIT0_BASE (REGS_BASE + 0x020d0000)
#define REGS_EPIT1_BASE (REGS_BASE + 0x020d4000)
#define REGS_EPIT_BASE(x) ( x == 0 ? REGS_EPIT0_BASE : x == 1 ? REGS_EPIT1_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_EPIT_EPITCR - Control register
 *
 * The EPIT control register (EPIT_EPITCR) is used to configure the
 * operating settings of the EPIT. It contains the clock division prescaler
 * value and also the interrupt enable bit. Additionally it contains other
 * control bit which are outlined below.  Peripheral (IP) Bus Write access to EPIT
 * Control Register (EPIT_EPITCR) results in one cycle of the wait state (ips_xfr_wait high for 1
 * cycle) , while other                             valid peripheral (IP) bus accesses are with 0
 * wait state.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EN : 1; //!< This bit enables the EPIT. EPIT counter and prescaler value when EPIT is enabled (EN =1), is dependent upon ENMOD and RLD bit as described for ENMOD bit. It is recommended that all registers be properly programmed before setting this bit. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned ENMOD : 1; //!< EPIT enable mode.  When EPIT is disabled (EN=0), both main counter and prescaler counter freeze their count at current count values. ENMOD bit is a r/w bit that determines the counter value when the EPIT is enabled again by setting EN bit. If ENMOD bit is set, then main counter is loaded with the load value (If RLD=1)/ 0xFFFF_FFFF (If RLD=0) and prescaler counter is reset, when EPIT is enabled (EN=1). If ENMOD is programmed to 0 then both main counter and prescaler counter restart counting from their frozen values when EPIT is enabled (EN=1). If EPIT is programmed to be disabled in a low-power mode (STOP/WAIT/DEBUG /DOZE ), then both the main counter and the prescaler counter freeze at their current count values when EPIT enters low-power mode. When EPIT exits the low-power mode, both main counter and prescaler counter start counting from their frozen values irrespective of the ENMOD bit. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned OCIEN : 1; //!< Output compare interrupt enable.  This bit enables the generation of interrupt on occurrence of compare event.
        unsigned RLD : 1; //!< Counter reload control.  This bit is cleared by hardware reset. It decides the counter functionality, whether to run in free-running mode or set-and-forget mode.
        unsigned PRESCALAR : 12; //!< Counter clock prescaler value. This bit field determines the prescaler value by which the clock is divided before it goes to the counter
        unsigned SWR : 1; //!< Software reset. The EPIT is reset when this bit is set to 1. It is a self clearing bit. This bit is set when the block is in reset state and is cleared when the reset procedure is over. Setting this bit resets all the registers to their reset values, except for the EN, ENMOD, STOPEN , DOZEN , WAITEN and DBGEN bits in this control register
        unsigned IOVW : 1; //!< EPIT counter overwrite enable. This bit controls the counter data when the modulus register is written. When this bit is set, all writes to the load register overwrites the counter contents and the counter starts subsequently counting down from the programmed value.
        unsigned DBGEN : 1; //!< This bit is used to keep the EPIT functional in debug mode. When this bit is cleared, the input clock is gated off in debug mode.This bit is reset by hardware reset. A software reset does not affect this bit.
        unsigned WAITEN : 1; //!< This read/write control bit enables the operation of the EPIT during wait mode. This bit is reset by a hardware reset. A software reset does not affect this bit.
        unsigned RESERVED0 : 1; //!< 
        unsigned STOPEN : 1; //!< EPIT stop mode enable. This read/write control bit enables the operation of the EPIT during stop mode. This bit is reset by a hardware reset and unaffected by software reset.
        unsigned OM : 2; //!< EPIT output mode.This bit field determines the mode of EPIT output on the output pin.
        unsigned CLKSRC : 2; //!< Select clock source  These bits determine which clock input is to be selected for running the counter. This field value should only be changed when the EPIT is disabled by clearing the EN bit in this register. For other programming requirements while changing clock source, refer to .
        unsigned RESERVED1 : 6; //!< Reserved. Writing to these bits does not affect the functionality of EPIT. These bits are always read as zero.
    } B;
} hw_epit_epitcr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCR register
 */
#define HW_EPIT_EPITCR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCR(x)           (*(volatile hw_epit_epitcr_t *) HW_EPIT_EPITCR_ADDR(x))
#define HW_EPIT_EPITCR_RD(x)        (HW_EPIT_EPITCR(x).U)
#define HW_EPIT_EPITCR_WR(x, v)     (HW_EPIT_EPITCR(x).U = (v))
#define HW_EPIT_EPITCR_SET(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) |  (v)))
#define HW_EPIT_EPITCR_CLR(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) & ~(v)))
#define HW_EPIT_EPITCR_TOG(x, v)    (HW_EPIT_EPITCR_WR(x, HW_EPIT_EPITCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCR bitfields
 */

/* --- Register HW_EPIT_EPITCR, field EN
 *
 * This bit enables the EPIT. EPIT counter and prescaler value when EPIT
 * is enabled (EN =1), is dependent upon ENMOD and RLD bit as described
 * for ENMOD bit. It is recommended that all registers be properly
 * programmed before setting this bit. This bit is reset by a hardware
 * reset. A software reset does not affect this bit.
 */

#define BP_EPIT_EPITCR_EN      0
#define BM_EPIT_EPITCR_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_EN(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCR_EN)
#else
#define BF_EPIT_EPITCR_EN(v)   (((v) << 0) & BM_EPIT_EPITCR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_EN(v)   BF_CS1(EPIT_EPITCR, EN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field ENMOD
 *
 * EPIT enable mode.  When EPIT is disabled (EN=0), both main counter and prescaler counter
 * freeze their count at current count values. ENMOD bit is a r/w bit
 * that determines the counter value when the EPIT is enabled again by
 * setting EN bit. If ENMOD bit is set, then main counter is loaded
 * with the load value (If RLD=1)/ 0xFFFF_FFFF (If RLD=0) and prescaler
 * counter is reset, when EPIT is enabled (EN=1). If ENMOD is
 * programmed to 0 then both main counter and prescaler counter restart
 * counting from their frozen values when EPIT is enabled (EN=1). If
 * EPIT is programmed to be disabled in a low-power mode
 * (STOP/WAIT/DEBUG /DOZE ),                                 then both the main counter and the
 * prescaler counter freeze at their                                 current count values when EPIT
 * enters low-power mode. When EPIT                                 exits the low-power mode, both
 * main counter and prescaler counter                                 start counting from their
 * frozen values irrespective of the ENMOD                                 bit. This bit is reset by
 * a hardware reset. A software reset does                                 not affect this bit.
 */

#define BP_EPIT_EPITCR_ENMOD      1
#define BM_EPIT_EPITCR_ENMOD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_ENMOD(v)   ((((reg32_t) v) << 1) & BM_EPIT_EPITCR_ENMOD)
#else
#define BF_EPIT_EPITCR_ENMOD(v)   (((v) << 1) & BM_EPIT_EPITCR_ENMOD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_ENMOD(v)   BF_CS1(EPIT_EPITCR, ENMOD, v)
#endif

/* --- Register HW_EPIT_EPITCR, field OCIEN
 *
 * Output compare interrupt enable.  This bit enables the generation of interrupt on occurrence of
 * compare                                 event.
 */

#define BP_EPIT_EPITCR_OCIEN      2
#define BM_EPIT_EPITCR_OCIEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_OCIEN(v)   ((((reg32_t) v) << 2) & BM_EPIT_EPITCR_OCIEN)
#else
#define BF_EPIT_EPITCR_OCIEN(v)   (((v) << 2) & BM_EPIT_EPITCR_OCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_OCIEN(v)   BF_CS1(EPIT_EPITCR, OCIEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field RLD
 *
 * Counter reload control.  This bit is cleared by hardware reset. It decides the counter
 * functionality, whether to run in free-running mode or set-and-forget
 * mode.
 */

#define BP_EPIT_EPITCR_RLD      3
#define BM_EPIT_EPITCR_RLD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_RLD(v)   ((((reg32_t) v) << 3) & BM_EPIT_EPITCR_RLD)
#else
#define BF_EPIT_EPITCR_RLD(v)   (((v) << 3) & BM_EPIT_EPITCR_RLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_RLD(v)   BF_CS1(EPIT_EPITCR, RLD, v)
#endif

/* --- Register HW_EPIT_EPITCR, field PRESCALAR
 *
 * Counter clock prescaler value. This bit field determines the
 * prescaler value by which the clock is divided before it goes to the
 * counter
 */

#define BP_EPIT_EPITCR_PRESCALAR      4
#define BM_EPIT_EPITCR_PRESCALAR      0x0000fff0

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_PRESCALAR(v)   ((((reg32_t) v) << 4) & BM_EPIT_EPITCR_PRESCALAR)
#else
#define BF_EPIT_EPITCR_PRESCALAR(v)   (((v) << 4) & BM_EPIT_EPITCR_PRESCALAR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_PRESCALAR(v)   BF_CS1(EPIT_EPITCR, PRESCALAR, v)
#endif

/* --- Register HW_EPIT_EPITCR, field SWR
 *
 * Software reset. The EPIT is reset when this bit is set to 1. It is a
 * self clearing bit. This bit is set when the block is in reset state
 * and is cleared when the reset procedure is over. Setting this bit
 * resets all the registers to their reset values, except for the EN,
 * ENMOD, STOPEN , DOZEN , WAITEN                                 and DBGEN bits in this control
 * register
 */

#define BP_EPIT_EPITCR_SWR      16
#define BM_EPIT_EPITCR_SWR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_SWR(v)   ((((reg32_t) v) << 16) & BM_EPIT_EPITCR_SWR)
#else
#define BF_EPIT_EPITCR_SWR(v)   (((v) << 16) & BM_EPIT_EPITCR_SWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_SWR(v)   BF_CS1(EPIT_EPITCR, SWR, v)
#endif

/* --- Register HW_EPIT_EPITCR, field IOVW
 *
 * EPIT counter overwrite enable. This bit controls the counter data
 * when the modulus register is written. When this bit is set, all
 * writes to the load register overwrites the counter contents and the
 * counter starts subsequently counting down from the programmed value.
 */

#define BP_EPIT_EPITCR_IOVW      17
#define BM_EPIT_EPITCR_IOVW      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_IOVW(v)   ((((reg32_t) v) << 17) & BM_EPIT_EPITCR_IOVW)
#else
#define BF_EPIT_EPITCR_IOVW(v)   (((v) << 17) & BM_EPIT_EPITCR_IOVW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_IOVW(v)   BF_CS1(EPIT_EPITCR, IOVW, v)
#endif

/* --- Register HW_EPIT_EPITCR, field DBGEN
 *
 * This bit is used to keep the EPIT functional in debug mode. When this
 * bit is cleared, the input clock is gated off in debug mode.This bit
 * is reset by hardware reset. A software reset does not affect this
 * bit.
 */

#define BP_EPIT_EPITCR_DBGEN      18
#define BM_EPIT_EPITCR_DBGEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_DBGEN(v)   ((((reg32_t) v) << 18) & BM_EPIT_EPITCR_DBGEN)
#else
#define BF_EPIT_EPITCR_DBGEN(v)   (((v) << 18) & BM_EPIT_EPITCR_DBGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_DBGEN(v)   BF_CS1(EPIT_EPITCR, DBGEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field WAITEN
 *
 * This read/write control bit enables the operation of the EPIT during
 * wait mode. This bit is reset by a hardware reset. A software reset
 * does not affect this bit.
 */

#define BP_EPIT_EPITCR_WAITEN      19
#define BM_EPIT_EPITCR_WAITEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_WAITEN(v)   ((((reg32_t) v) << 19) & BM_EPIT_EPITCR_WAITEN)
#else
#define BF_EPIT_EPITCR_WAITEN(v)   (((v) << 19) & BM_EPIT_EPITCR_WAITEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_WAITEN(v)   BF_CS1(EPIT_EPITCR, WAITEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field STOPEN
 *
 * EPIT stop mode enable. This read/write control bit enables the
 * operation of the EPIT during stop mode. This bit is reset by a
 * hardware reset and unaffected by software reset.
 */

#define BP_EPIT_EPITCR_STOPEN      21
#define BM_EPIT_EPITCR_STOPEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_STOPEN(v)   ((((reg32_t) v) << 21) & BM_EPIT_EPITCR_STOPEN)
#else
#define BF_EPIT_EPITCR_STOPEN(v)   (((v) << 21) & BM_EPIT_EPITCR_STOPEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_STOPEN(v)   BF_CS1(EPIT_EPITCR, STOPEN, v)
#endif

/* --- Register HW_EPIT_EPITCR, field OM
 *
 * EPIT output mode.This bit field determines the mode of EPIT output on
 * the output pin.
 */

#define BP_EPIT_EPITCR_OM      22
#define BM_EPIT_EPITCR_OM      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_OM(v)   ((((reg32_t) v) << 22) & BM_EPIT_EPITCR_OM)
#else
#define BF_EPIT_EPITCR_OM(v)   (((v) << 22) & BM_EPIT_EPITCR_OM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_OM(v)   BF_CS1(EPIT_EPITCR, OM, v)
#endif

/* --- Register HW_EPIT_EPITCR, field CLKSRC
 *
 * Select clock source  These bits determine which clock input is to be selected for running
 * the counter. This field value should only be changed when the EPIT
 * is disabled by clearing the EN bit in this register. For other
 * programming requirements while changing clock source, refer to .
 */

#define BP_EPIT_EPITCR_CLKSRC      24
#define BM_EPIT_EPITCR_CLKSRC      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCR_CLKSRC(v)   ((((reg32_t) v) << 24) & BM_EPIT_EPITCR_CLKSRC)
#else
#define BF_EPIT_EPITCR_CLKSRC(v)   (((v) << 24) & BM_EPIT_EPITCR_CLKSRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCR_CLKSRC(v)   BF_CS1(EPIT_EPITCR, CLKSRC, v)
#endif

/*!
 * @brief HW_EPIT_EPITSR - Status register
 *
 * The EPIT status register (EPIT_EPITSR) has a single status bit for the
 * output compare event. The bit is a write 1 to clear bit.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OCIF : 1; //!< Output compare interrupt flag. This bit is the interrupt flag that is set when the content of counter equals the content of the compare register (EPIT_EPITCMPR). The bit is a write 1 to clear bit.
        unsigned RESERVED0 : 31; //!< Reserved. Writing to these bits does not affect the functionality of EPIT. These bits are always read as zero.
    } B;
} hw_epit_epitsr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITSR register
 */
#define HW_EPIT_EPITSR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITSR(x)           (*(volatile hw_epit_epitsr_t *) HW_EPIT_EPITSR_ADDR(x))
#define HW_EPIT_EPITSR_RD(x)        (HW_EPIT_EPITSR(x).U)
#define HW_EPIT_EPITSR_WR(x, v)     (HW_EPIT_EPITSR(x).U = (v))
#define HW_EPIT_EPITSR_SET(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) |  (v)))
#define HW_EPIT_EPITSR_CLR(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) & ~(v)))
#define HW_EPIT_EPITSR_TOG(x, v)    (HW_EPIT_EPITSR_WR(x, HW_EPIT_EPITSR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITSR bitfields
 */

/* --- Register HW_EPIT_EPITSR, field OCIF
 *
 * Output compare interrupt flag. This bit is the interrupt flag that is
 * set when the content of counter equals the content of the compare
 * register (EPIT_EPITCMPR). The bit is a write 1 to clear bit.
 */

#define BP_EPIT_EPITSR_OCIF      0
#define BM_EPIT_EPITSR_OCIF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITSR_OCIF(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITSR_OCIF)
#else
#define BF_EPIT_EPITSR_OCIF(v)   (((v) << 0) & BM_EPIT_EPITSR_OCIF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITSR_OCIF(v)   BF_CS1(EPIT_EPITSR, OCIF, v)
#endif

/*!
 * @brief HW_EPIT_EPITLR - Load register
 *
 * The EPIT load register (EPIT_EPITLR) contains the value that is to be
 * loaded into the counter when EPIT counter reaches zero if the RLD bit in
 * EPIT_EPITCR is set. If the IOVW bit in the EPIT_EPITCR is set then a
 * write to this register overwrites the value of the EPIT counter register
 * in addition to updating this registers value. This overwrite feature is
 * active even if the RLD bit is not set.  IP Bus Write access to EPIT Load Register (EPITLR)
 * results in one cycle of wait state (ips_xfr_wait high for 1 cycle),
 * while other valid IP bus accesses are with 0 wait state.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LOAD : 32; //!< Load value. Value that is loaded into the counter at the start of each count cycle.
    } B;
} hw_epit_epitlr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITLR register
 */
#define HW_EPIT_EPITLR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITLR(x)           (*(volatile hw_epit_epitlr_t *) HW_EPIT_EPITLR_ADDR(x))
#define HW_EPIT_EPITLR_RD(x)        (HW_EPIT_EPITLR(x).U)
#define HW_EPIT_EPITLR_WR(x, v)     (HW_EPIT_EPITLR(x).U = (v))
#define HW_EPIT_EPITLR_SET(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) |  (v)))
#define HW_EPIT_EPITLR_CLR(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) & ~(v)))
#define HW_EPIT_EPITLR_TOG(x, v)    (HW_EPIT_EPITLR_WR(x, HW_EPIT_EPITLR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITLR bitfields
 */

/* --- Register HW_EPIT_EPITLR, field LOAD
 *
 * Load value. Value that is loaded into the counter at the start of
 * each count cycle.
 */

#define BP_EPIT_EPITLR_LOAD      0
#define BM_EPIT_EPITLR_LOAD      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITLR_LOAD(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITLR_LOAD)
#else
#define BF_EPIT_EPITLR_LOAD(v)   (((v) << 0) & BM_EPIT_EPITLR_LOAD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITLR_LOAD(v)   BF_CS1(EPIT_EPITLR, LOAD, v)
#endif

/*!
 * @brief HW_EPIT_EPITCMPR - Compare register
 *
 * The EPIT compare register (EPIT_EPITCMPR) holds the value that determines
 * when a compare event is generated.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COMPARE : 32; //!< Compare Value. When the counter value equals this bit field value a compare event is generated.
    } B;
} hw_epit_epitcmpr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCMPR register
 */
#define HW_EPIT_EPITCMPR_ADDR(x)      (REGS_EPIT_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCMPR(x)           (*(volatile hw_epit_epitcmpr_t *) HW_EPIT_EPITCMPR_ADDR(x))
#define HW_EPIT_EPITCMPR_RD(x)        (HW_EPIT_EPITCMPR(x).U)
#define HW_EPIT_EPITCMPR_WR(x, v)     (HW_EPIT_EPITCMPR(x).U = (v))
#define HW_EPIT_EPITCMPR_SET(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) |  (v)))
#define HW_EPIT_EPITCMPR_CLR(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) & ~(v)))
#define HW_EPIT_EPITCMPR_TOG(x, v)    (HW_EPIT_EPITCMPR_WR(x, HW_EPIT_EPITCMPR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCMPR bitfields
 */

/* --- Register HW_EPIT_EPITCMPR, field COMPARE
 *
 * Compare Value. When the counter value equals this bit field value a
 * compare event is generated.
 */

#define BP_EPIT_EPITCMPR_COMPARE      0
#define BM_EPIT_EPITCMPR_COMPARE      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCMPR_COMPARE(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCMPR_COMPARE)
#else
#define BF_EPIT_EPITCMPR_COMPARE(v)   (((v) << 0) & BM_EPIT_EPITCMPR_COMPARE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCMPR_COMPARE(v)   BF_CS1(EPIT_EPITCMPR, COMPARE, v)
#endif

/*!
 * @brief HW_EPIT_EPITCNR - Counter register
 *
 * The EPIT counter register (EPIT_EPITCNR) contains the current count value
 * and can be read at any time without disturbing the counter. This is a
 * read-only register and any attempt to write into it generates a transfer
 * error. But if the IOVW bit in EPIT_EPITCR is set, the value of this
 * register can be overwritten with a write to EPIT_EPITLR. This change is
 * reflected when this register is subsequently read.  .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned COUNT : 32; //!< Counter value. This contains the current value of the counter.
    } B;
} hw_epit_epitcnr_t;
#endif

/*
 * constants & macros for entire multi-block EPIT_EPITCNR register
 */
#define HW_EPIT_EPITCNR_ADDR(x)      (REGS_EPIT_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EPIT_EPITCNR(x)           (*(volatile hw_epit_epitcnr_t *) HW_EPIT_EPITCNR_ADDR(x))
#define HW_EPIT_EPITCNR_RD(x)        (HW_EPIT_EPITCNR(x).U)
#define HW_EPIT_EPITCNR_WR(x, v)     (HW_EPIT_EPITCNR(x).U = (v))
#define HW_EPIT_EPITCNR_SET(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) |  (v)))
#define HW_EPIT_EPITCNR_CLR(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) & ~(v)))
#define HW_EPIT_EPITCNR_TOG(x, v)    (HW_EPIT_EPITCNR_WR(x, HW_EPIT_EPITCNR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual EPIT_EPITCNR bitfields
 */

/* --- Register HW_EPIT_EPITCNR, field COUNT
 *
 * Counter value. This contains the current value of the counter.
 */

#define BP_EPIT_EPITCNR_COUNT      0
#define BM_EPIT_EPITCNR_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EPIT_EPITCNR_COUNT(v)   ((((reg32_t) v) << 0) & BM_EPIT_EPITCNR_COUNT)
#else
#define BF_EPIT_EPITCNR_COUNT(v)   (((v) << 0) & BM_EPIT_EPITCNR_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EPIT_EPITCNR_COUNT(v)   BF_CS1(EPIT_EPITCNR, COUNT, v)
#endif



/*!
 * @brief All EPIT module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_epit_epitcr_t EPITCR; //!< Control register
    volatile hw_epit_epitsr_t EPITSR; //!< Status register
    volatile hw_epit_epitlr_t EPITLR; //!< Load register
    volatile hw_epit_epitcmpr_t EPITCMPR; //!< Compare register
    volatile hw_epit_epitcnr_t EPITCNR; //!< Counter register
} hw_epit_t
#endif

//! @brief Macro to access all EPIT registers.
//! @param x EPIT instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EPIT(0)</code>.
#define HW_EPIT(x)     (*(volatile hw_epit_t *) REGS_EPIT_BASE(x))


#endif // _EPIT_H
