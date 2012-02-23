/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ROMC_H
#define _ROMC_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_ROMC_ROMPATCHD - ROMC Data Registers
 * - HW_ROMC_ROMPATCHCNTL - ROMC Control Register
 * - HW_ROMC_ROMPATCHENH - ROMC Enable Register High
 * - HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
 * - HW_ROMC_ROMPATCHA - ROMC Address Registers
 * - HW_ROMC_ROMPATCHSR - ROMC Status Register
 *
 * hw_romc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ROMC_BASE
#define REGS_ROMC_BASE (0x021ac000) //!< Base address for ROMC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD - ROMC Data Registers (RW)
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATAX : 32; //!< Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored within these registers do not affect the writes to the memory system. They are selected over the read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace the entire word. The word is word address aligned.
    } B;
} hw_romc_rompatchd_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD register
 */
#define HW_ROMC_ROMPATCHD_ADDR      (REGS_ROMC_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD           (*(volatile hw_romc_rompatchd_t *) HW_ROMC_ROMPATCHD_ADDR)
#define HW_ROMC_ROMPATCHD_RD()      (HW_ROMC_ROMPATCHD.U)
#define HW_ROMC_ROMPATCHD_WR(v)     (HW_ROMC_ROMPATCHD.U = (v))
#define HW_ROMC_ROMPATCHD_SET(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() |  (v)))
#define HW_ROMC_ROMPATCHD_CLR(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD_TOG(v)    (HW_ROMC_ROMPATCHD_WR(HW_ROMC_ROMPATCHD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD, field DATAX (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD_DATAX      0
#define BM_ROMC_ROMPATCHD_DATAX      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD_DATAX)
#else
#define BF_ROMC_ROMPATCHD_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD_DATAX(v)   BF_CS1(ROMC_ROMPATCHD, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHCNTL - ROMC Control Register (RW)
 *
 * The ROMC control register (ROMC_ROMPATCHCNTL) contains the block disable bit and the data fix
 * enable bits. The block disable bit provides a means to disable the ROMC data fix and opcode
 * patching functions, even when the address comparators are enabled. The External Boot feature is
 * not affected by this bit. The eight data fix enable bits (0 through 7), when set, assign the
 * associated address comparators to data fix operations  Bits 27 and 22 always read as 1s.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATAFIX : 8; //!< Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for code patch routine.
        unsigned RESERVED0 : 21; //!< Reserved
        unsigned DIS : 1; //!< ROMC Disable -- This bit, when set, disables all ROMC operations. This bit is used to enable secure operations.
        unsigned RESERVED1 : 2; //!< Reserved
    } B;
} hw_romc_rompatchcntl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHCNTL register
 */
#define HW_ROMC_ROMPATCHCNTL_ADDR      (REGS_ROMC_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHCNTL           (*(volatile hw_romc_rompatchcntl_t *) HW_ROMC_ROMPATCHCNTL_ADDR)
#define HW_ROMC_ROMPATCHCNTL_RD()      (HW_ROMC_ROMPATCHCNTL.U)
#define HW_ROMC_ROMPATCHCNTL_WR(v)     (HW_ROMC_ROMPATCHCNTL.U = (v))
#define HW_ROMC_ROMPATCHCNTL_SET(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() |  (v)))
#define HW_ROMC_ROMPATCHCNTL_CLR(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHCNTL_TOG(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHCNTL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHCNTL, field DATAFIX (RW)
 *
 * Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for
 * code patch routine.
 *
 * Values:
 * 0 - Address comparator triggers a opcode patch
 * 1 - Address comparator triggers a data fix
 */

#define BP_ROMC_ROMPATCHCNTL_DATAFIX      0
#define BM_ROMC_ROMPATCHCNTL_DATAFIX      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#else
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   (((v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAFIX field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DATAFIX(v)   BF_CS1(ROMC_ROMPATCHCNTL, DATAFIX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHCNTL, field DIS (RW)
 *
 * ROMC Disable -- This bit, when set, disables all ROMC operations. This bit is used to enable
 * secure operations.
 *
 * Values:
 * 0 - Does not affect any ROMC functions (default)
 * 1 - Disable all ROMC functions: data fixing, and opcode patching
 */

#define BP_ROMC_ROMPATCHCNTL_DIS      29
#define BM_ROMC_ROMPATCHCNTL_DIS      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   ((((reg32_t) v) << 29) & BM_ROMC_ROMPATCHCNTL_DIS)
#else
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   (((v) << 29) & BM_ROMC_ROMPATCHCNTL_DIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DIS(v)   BF_CS1(ROMC_ROMPATCHCNTL, DIS, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENH - ROMC Enable Register High (RO)
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_OMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Reserved
    } B;
} hw_romc_rompatchenh_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENH register
 */
#define HW_ROMC_ROMPATCHENH_ADDR      (REGS_ROMC_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENH           (*(volatile hw_romc_rompatchenh_t *) HW_ROMC_ROMPATCHENH_ADDR)
#define HW_ROMC_ROMPATCHENH_RD()      (HW_ROMC_ROMPATCHENH.U)
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHENH bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENL - ROMC Enable Register Low (RW)
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_ROMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE : 16; //!< Enable Address Comparator - This bit enables the corresponding address comparator to trigger an event.
        unsigned RESERVED : 16; //!< 
    } B;
} hw_romc_rompatchenl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENL register
 */
#define HW_ROMC_ROMPATCHENL_ADDR      (REGS_ROMC_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENL           (*(volatile hw_romc_rompatchenl_t *) HW_ROMC_ROMPATCHENL_ADDR)
#define HW_ROMC_ROMPATCHENL_RD()      (HW_ROMC_ROMPATCHENL.U)
#define HW_ROMC_ROMPATCHENL_WR(v)     (HW_ROMC_ROMPATCHENL.U = (v))
#define HW_ROMC_ROMPATCHENL_SET(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() |  (v)))
#define HW_ROMC_ROMPATCHENL_CLR(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHENL_TOG(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHENL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHENL, field ENABLE (RW)
 *
 * Enable Address Comparator - This bit enables the corresponding address comparator to trigger an
 * event.
 *
 * Values:
 * 0 - Address comparator disabled
 * 1 - Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the
 *     associated address
 */

#define BP_ROMC_ROMPATCHENL_ENABLE      0
#define BM_ROMC_ROMPATCHENL_ENABLE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#else
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   (((v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_ROMC_ROMPATCHENL_ENABLE(v)   BF_CS1(ROMC_ROMPATCHENL, ENABLE, v)
#endif


/* --- Register HW_ROMC_ROMPATCHENL, field RESERVED (RU)
 *

 *
 * Values:
 *  - 
 *  - 
 */

#define BP_ROMC_ROMPATCHENL_RESERVED      16
#define BM_ROMC_ROMPATCHENL_RESERVED      0xffff0000


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA - ROMC Address Registers (RW)
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned THUMBX : 1; //!< THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all data fixes are 1-word data fixes.
        unsigned ADDRX : 22; //!< Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can be used for code patch address comparison. Only the first 8 registers can be used for a 1-word data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
        unsigned RESERVED0 : 9; //!< Reserved
    } B;
} hw_romc_rompatcha_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA register
 */
#define HW_ROMC_ROMPATCHA_ADDR      (REGS_ROMC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA           (*(volatile hw_romc_rompatcha_t *) HW_ROMC_ROMPATCHA_ADDR)
#define HW_ROMC_ROMPATCHA_RD()      (HW_ROMC_ROMPATCHA.U)
#define HW_ROMC_ROMPATCHA_WR(v)     (HW_ROMC_ROMPATCHA.U = (v))
#define HW_ROMC_ROMPATCHA_SET(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() |  (v)))
#define HW_ROMC_ROMPATCHA_CLR(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA_TOG(v)    (HW_ROMC_ROMPATCHA_WR(HW_ROMC_ROMPATCHA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA, field THUMBX (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA_THUMBX      0
#define BM_ROMC_ROMPATCHA_THUMBX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA_THUMBX)
#else
#define BF_ROMC_ROMPATCHA_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA, field ADDRX (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA_ADDRX      1
#define BM_ROMC_ROMPATCHA_ADDRX      0x007ffffe

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA_ADDRX)
#else
#define BF_ROMC_ROMPATCHA_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHSR - ROMC Status Register (W1C)
 *
 * The ROMC status register (ROMC_ROMPATCHSR) indicates the current state of the ROMC and the source
 * number of the most recent address comparator event.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SOURCE : 6; //!< ROMC Source Number - Binary encoding of the number of the address comparator which has an address match in the most recent patch event on ROMC AHB. If multiple matches occurred, the highest priority source number is used.
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned SW : 1; //!< ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address comparator matches occurred. Writing a 1 to this bit will clear this it.
        unsigned RESERVED1 : 14; //!< Reserved
    } B;
} hw_romc_rompatchsr_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHSR register
 */
#define HW_ROMC_ROMPATCHSR_ADDR      (REGS_ROMC_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHSR           (*(volatile hw_romc_rompatchsr_t *) HW_ROMC_ROMPATCHSR_ADDR)
#define HW_ROMC_ROMPATCHSR_RD()      (HW_ROMC_ROMPATCHSR.U)
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHSR bitfields
 */

/* --- Register HW_ROMC_ROMPATCHSR, field SOURCE (RO)
 *
 * ROMC Source Number - Binary encoding of the number of the address comparator which has an address
 * match in the most recent patch event on ROMC AHB. If multiple matches occurred, the highest
 * priority source number is used.
 *
 * Values:
 * 0 - Address Comparator 0 matched
 * 1 - Address Comparator 1 matched
 * 15 - Address Comparator 15 matched
 */

#define BP_ROMC_ROMPATCHSR_SOURCE      0
#define BM_ROMC_ROMPATCHSR_SOURCE      0x0000003f


/* --- Register HW_ROMC_ROMPATCHSR, field SW (W1C)
 *
 * ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address
 * comparator matches occurred. Writing a 1 to this bit will clear this it.
 *
 * Values:
 * 0 - no event or comparator collisions
 * 1 - a collision has occurred
 */

#define BP_ROMC_ROMPATCHSR_SW      17
#define BM_ROMC_ROMPATCHSR_SW      0x00020000



/*!
 * @brief All ROMC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[53];
    volatile hw_romc_rompatchd_t ROMPATCHD; //!< ROMC Data Registers
    reg32_t _reserved1[7];
    volatile hw_romc_rompatchcntl_t ROMPATCHCNTL; //!< ROMC Control Register
    volatile hw_romc_rompatchenh_t ROMPATCHENH; //!< ROMC Enable Register High
    volatile hw_romc_rompatchenl_t ROMPATCHENL; //!< ROMC Enable Register Low
    volatile hw_romc_rompatcha_t ROMPATCHA; //!< ROMC Address Registers
    reg32_t _reserved2[65];
    volatile hw_romc_rompatchsr_t ROMPATCHSR; //!< ROMC Status Register
} hw_romc_t
#endif

//! @brief Macro to access all ROMC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ROMC(0)</code>.
#define HW_ROMC     (*(volatile hw_romc_t *) REGS_ROMC_BASE)


#endif // _ROMC_H
