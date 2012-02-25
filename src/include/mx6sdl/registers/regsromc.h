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
 * - HW_ROMC_ROMPATCHD0 - ROMC Data Registers 0
 * - HW_ROMC_ROMPATCHD1 - ROMC Data Registers 1
 * - HW_ROMC_ROMPATCHD2 - ROMC Data Registers 2
 * - HW_ROMC_ROMPATCHD3 - ROMC Data Registers 3
 * - HW_ROMC_ROMPATCHD4 - ROMC Data Registers 4
 * - HW_ROMC_ROMPATCHD5 - ROMC Data Registers 5
 * - HW_ROMC_ROMPATCHD6 - ROMC Data Registers 6
 * - HW_ROMC_ROMPATCHD7 - ROMC Data Registers 7
 * - HW_ROMC_ROMPATCHCNTL - ROMC Control Register
 * - HW_ROMC_ROMPATCHENH - ROMC Enable Register High
 * - HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
 * - HW_ROMC_ROMPATCHA0 - ROMC Address Registers 0
 * - HW_ROMC_ROMPATCHA1 - ROMC Address Registers 1
 * - HW_ROMC_ROMPATCHA2 - ROMC Address Registers 2
 * - HW_ROMC_ROMPATCHA3 - ROMC Address Registers 3
 * - HW_ROMC_ROMPATCHA4 - ROMC Address Registers 4
 * - HW_ROMC_ROMPATCHA5 - ROMC Address Registers 5
 * - HW_ROMC_ROMPATCHA6 - ROMC Address Registers 6
 * - HW_ROMC_ROMPATCHA7 - ROMC Address Registers 7
 * - HW_ROMC_ROMPATCHA8 - ROMC Address Registers 8
 * - HW_ROMC_ROMPATCHA9 - ROMC Address Registers 9
 * - HW_ROMC_ROMPATCHA10 - ROMC Address Registers 10
 * - HW_ROMC_ROMPATCHA11 - ROMC Address Registers 11
 * - HW_ROMC_ROMPATCHA12 - ROMC Address Registers 12
 * - HW_ROMC_ROMPATCHA13 - ROMC Address Registers 13
 * - HW_ROMC_ROMPATCHA14 - ROMC Address Registers 14
 * - HW_ROMC_ROMPATCHA15 - ROMC Address Registers 15
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
 * @brief HW_ROMC_ROMPATCHD0 - ROMC Data Registers 0 (RW)
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
} hw_romc_rompatchd0_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD0 register
 */
#define HW_ROMC_ROMPATCHD0_ADDR      (REGS_ROMC_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD0           (*(volatile hw_romc_rompatchd0_t *) HW_ROMC_ROMPATCHD0_ADDR)
#define HW_ROMC_ROMPATCHD0_RD()      (HW_ROMC_ROMPATCHD0.U)
#define HW_ROMC_ROMPATCHD0_WR(v)     (HW_ROMC_ROMPATCHD0.U = (v))
#define HW_ROMC_ROMPATCHD0_SET(v)    (HW_ROMC_ROMPATCHD0_WR(HW_ROMC_ROMPATCHD0_RD() |  (v)))
#define HW_ROMC_ROMPATCHD0_CLR(v)    (HW_ROMC_ROMPATCHD0_WR(HW_ROMC_ROMPATCHD0_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD0_TOG(v)    (HW_ROMC_ROMPATCHD0_WR(HW_ROMC_ROMPATCHD0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD0 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD0, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD0_DATAX      (0)
#define BM_ROMC_ROMPATCHD0_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD0_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD0_DATAX)
#else
#define BF_ROMC_ROMPATCHD0_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD0_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD0_DATAX(v)   BF_CS1(ROMC_ROMPATCHD0, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD1 - ROMC Data Registers 1 (RW)
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
} hw_romc_rompatchd1_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD1 register
 */
#define HW_ROMC_ROMPATCHD1_ADDR      (REGS_ROMC_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD1           (*(volatile hw_romc_rompatchd1_t *) HW_ROMC_ROMPATCHD1_ADDR)
#define HW_ROMC_ROMPATCHD1_RD()      (HW_ROMC_ROMPATCHD1.U)
#define HW_ROMC_ROMPATCHD1_WR(v)     (HW_ROMC_ROMPATCHD1.U = (v))
#define HW_ROMC_ROMPATCHD1_SET(v)    (HW_ROMC_ROMPATCHD1_WR(HW_ROMC_ROMPATCHD1_RD() |  (v)))
#define HW_ROMC_ROMPATCHD1_CLR(v)    (HW_ROMC_ROMPATCHD1_WR(HW_ROMC_ROMPATCHD1_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD1_TOG(v)    (HW_ROMC_ROMPATCHD1_WR(HW_ROMC_ROMPATCHD1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD1 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD1, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD1_DATAX      (0)
#define BM_ROMC_ROMPATCHD1_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD1_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD1_DATAX)
#else
#define BF_ROMC_ROMPATCHD1_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD1_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD1_DATAX(v)   BF_CS1(ROMC_ROMPATCHD1, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD2 - ROMC Data Registers 2 (RW)
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
} hw_romc_rompatchd2_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD2 register
 */
#define HW_ROMC_ROMPATCHD2_ADDR      (REGS_ROMC_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD2           (*(volatile hw_romc_rompatchd2_t *) HW_ROMC_ROMPATCHD2_ADDR)
#define HW_ROMC_ROMPATCHD2_RD()      (HW_ROMC_ROMPATCHD2.U)
#define HW_ROMC_ROMPATCHD2_WR(v)     (HW_ROMC_ROMPATCHD2.U = (v))
#define HW_ROMC_ROMPATCHD2_SET(v)    (HW_ROMC_ROMPATCHD2_WR(HW_ROMC_ROMPATCHD2_RD() |  (v)))
#define HW_ROMC_ROMPATCHD2_CLR(v)    (HW_ROMC_ROMPATCHD2_WR(HW_ROMC_ROMPATCHD2_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD2_TOG(v)    (HW_ROMC_ROMPATCHD2_WR(HW_ROMC_ROMPATCHD2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD2 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD2, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD2_DATAX      (0)
#define BM_ROMC_ROMPATCHD2_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD2_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD2_DATAX)
#else
#define BF_ROMC_ROMPATCHD2_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD2_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD2_DATAX(v)   BF_CS1(ROMC_ROMPATCHD2, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD3 - ROMC Data Registers 3 (RW)
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
} hw_romc_rompatchd3_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD3 register
 */
#define HW_ROMC_ROMPATCHD3_ADDR      (REGS_ROMC_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD3           (*(volatile hw_romc_rompatchd3_t *) HW_ROMC_ROMPATCHD3_ADDR)
#define HW_ROMC_ROMPATCHD3_RD()      (HW_ROMC_ROMPATCHD3.U)
#define HW_ROMC_ROMPATCHD3_WR(v)     (HW_ROMC_ROMPATCHD3.U = (v))
#define HW_ROMC_ROMPATCHD3_SET(v)    (HW_ROMC_ROMPATCHD3_WR(HW_ROMC_ROMPATCHD3_RD() |  (v)))
#define HW_ROMC_ROMPATCHD3_CLR(v)    (HW_ROMC_ROMPATCHD3_WR(HW_ROMC_ROMPATCHD3_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD3_TOG(v)    (HW_ROMC_ROMPATCHD3_WR(HW_ROMC_ROMPATCHD3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD3 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD3, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD3_DATAX      (0)
#define BM_ROMC_ROMPATCHD3_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD3_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD3_DATAX)
#else
#define BF_ROMC_ROMPATCHD3_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD3_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD3_DATAX(v)   BF_CS1(ROMC_ROMPATCHD3, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD4 - ROMC Data Registers 4 (RW)
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
} hw_romc_rompatchd4_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD4 register
 */
#define HW_ROMC_ROMPATCHD4_ADDR      (REGS_ROMC_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD4           (*(volatile hw_romc_rompatchd4_t *) HW_ROMC_ROMPATCHD4_ADDR)
#define HW_ROMC_ROMPATCHD4_RD()      (HW_ROMC_ROMPATCHD4.U)
#define HW_ROMC_ROMPATCHD4_WR(v)     (HW_ROMC_ROMPATCHD4.U = (v))
#define HW_ROMC_ROMPATCHD4_SET(v)    (HW_ROMC_ROMPATCHD4_WR(HW_ROMC_ROMPATCHD4_RD() |  (v)))
#define HW_ROMC_ROMPATCHD4_CLR(v)    (HW_ROMC_ROMPATCHD4_WR(HW_ROMC_ROMPATCHD4_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD4_TOG(v)    (HW_ROMC_ROMPATCHD4_WR(HW_ROMC_ROMPATCHD4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD4 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD4, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD4_DATAX      (0)
#define BM_ROMC_ROMPATCHD4_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD4_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD4_DATAX)
#else
#define BF_ROMC_ROMPATCHD4_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD4_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD4_DATAX(v)   BF_CS1(ROMC_ROMPATCHD4, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD5 - ROMC Data Registers 5 (RW)
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
} hw_romc_rompatchd5_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD5 register
 */
#define HW_ROMC_ROMPATCHD5_ADDR      (REGS_ROMC_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD5           (*(volatile hw_romc_rompatchd5_t *) HW_ROMC_ROMPATCHD5_ADDR)
#define HW_ROMC_ROMPATCHD5_RD()      (HW_ROMC_ROMPATCHD5.U)
#define HW_ROMC_ROMPATCHD5_WR(v)     (HW_ROMC_ROMPATCHD5.U = (v))
#define HW_ROMC_ROMPATCHD5_SET(v)    (HW_ROMC_ROMPATCHD5_WR(HW_ROMC_ROMPATCHD5_RD() |  (v)))
#define HW_ROMC_ROMPATCHD5_CLR(v)    (HW_ROMC_ROMPATCHD5_WR(HW_ROMC_ROMPATCHD5_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD5_TOG(v)    (HW_ROMC_ROMPATCHD5_WR(HW_ROMC_ROMPATCHD5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD5 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD5, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD5_DATAX      (0)
#define BM_ROMC_ROMPATCHD5_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD5_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD5_DATAX)
#else
#define BF_ROMC_ROMPATCHD5_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD5_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD5_DATAX(v)   BF_CS1(ROMC_ROMPATCHD5, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD6 - ROMC Data Registers 6 (RW)
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
} hw_romc_rompatchd6_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD6 register
 */
#define HW_ROMC_ROMPATCHD6_ADDR      (REGS_ROMC_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD6           (*(volatile hw_romc_rompatchd6_t *) HW_ROMC_ROMPATCHD6_ADDR)
#define HW_ROMC_ROMPATCHD6_RD()      (HW_ROMC_ROMPATCHD6.U)
#define HW_ROMC_ROMPATCHD6_WR(v)     (HW_ROMC_ROMPATCHD6.U = (v))
#define HW_ROMC_ROMPATCHD6_SET(v)    (HW_ROMC_ROMPATCHD6_WR(HW_ROMC_ROMPATCHD6_RD() |  (v)))
#define HW_ROMC_ROMPATCHD6_CLR(v)    (HW_ROMC_ROMPATCHD6_WR(HW_ROMC_ROMPATCHD6_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD6_TOG(v)    (HW_ROMC_ROMPATCHD6_WR(HW_ROMC_ROMPATCHD6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD6 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD6, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD6_DATAX      (0)
#define BM_ROMC_ROMPATCHD6_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD6_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD6_DATAX)
#else
#define BF_ROMC_ROMPATCHD6_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD6_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD6_DATAX(v)   BF_CS1(ROMC_ROMPATCHD6, DATAX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHD7 - ROMC Data Registers 7 (RW)
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
} hw_romc_rompatchd7_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHD7 register
 */
#define HW_ROMC_ROMPATCHD7_ADDR      (REGS_ROMC_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHD7           (*(volatile hw_romc_rompatchd7_t *) HW_ROMC_ROMPATCHD7_ADDR)
#define HW_ROMC_ROMPATCHD7_RD()      (HW_ROMC_ROMPATCHD7.U)
#define HW_ROMC_ROMPATCHD7_WR(v)     (HW_ROMC_ROMPATCHD7.U = (v))
#define HW_ROMC_ROMPATCHD7_SET(v)    (HW_ROMC_ROMPATCHD7_WR(HW_ROMC_ROMPATCHD7_RD() |  (v)))
#define HW_ROMC_ROMPATCHD7_CLR(v)    (HW_ROMC_ROMPATCHD7_WR(HW_ROMC_ROMPATCHD7_RD() & ~(v)))
#define HW_ROMC_ROMPATCHD7_TOG(v)    (HW_ROMC_ROMPATCHD7_WR(HW_ROMC_ROMPATCHD7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHD7 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHD7, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCHD7_DATAX      (0)
#define BM_ROMC_ROMPATCHD7_DATAX      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHD7_DATAX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHD7_DATAX)
#else
#define BF_ROMC_ROMPATCHD7_DATAX(v)   (((v) << 0) & BM_ROMC_ROMPATCHD7_DATAX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHD7_DATAX(v)   BF_CS1(ROMC_ROMPATCHD7, DATAX, v)
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

/* --- Register HW_ROMC_ROMPATCHCNTL, field DATAFIX[7:0] (RW)
 *
 * Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for
 * code patch routine.
 *
 * Values:
 * 0 - Address comparator triggers a opcode patch
 * 1 - Address comparator triggers a data fix
 */

#define BP_ROMC_ROMPATCHCNTL_DATAFIX      (0)
#define BM_ROMC_ROMPATCHCNTL_DATAFIX      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#else
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   (((v) << 0) & BM_ROMC_ROMPATCHCNTL_DATAFIX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAFIX field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DATAFIX(v)   BF_CS1(ROMC_ROMPATCHCNTL, DATAFIX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHCNTL, field DIS[29:29] (RW)
 *
 * ROMC Disable -- This bit, when set, disables all ROMC operations. This bit is used to enable
 * secure operations.
 *
 * Values:
 * 0 - Does not affect any ROMC functions (default)
 * 1 - Disable all ROMC functions: data fixing, and opcode patching
 */

#define BP_ROMC_ROMPATCHCNTL_DIS      (29)
#define BM_ROMC_ROMPATCHCNTL_DIS      (0x20000000)

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
        unsigned RESERVED0 : 16; //!< 
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

/* --- Register HW_ROMC_ROMPATCHENL, field ENABLE[15:0] (RW)
 *
 * Enable Address Comparator - This bit enables the corresponding address comparator to trigger an
 * event.
 *
 * Values:
 * 0 - Address comparator disabled
 * 1 - Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the
 *     associated address
 */

#define BP_ROMC_ROMPATCHENL_ENABLE      (0)
#define BM_ROMC_ROMPATCHENL_ENABLE      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#else
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   (((v) << 0) & BM_ROMC_ROMPATCHENL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_ROMC_ROMPATCHENL_ENABLE(v)   BF_CS1(ROMC_ROMPATCHENL, ENABLE, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA0 - ROMC Address Registers 0 (RW)
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
} hw_romc_rompatcha0_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA0 register
 */
#define HW_ROMC_ROMPATCHA0_ADDR      (REGS_ROMC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA0           (*(volatile hw_romc_rompatcha0_t *) HW_ROMC_ROMPATCHA0_ADDR)
#define HW_ROMC_ROMPATCHA0_RD()      (HW_ROMC_ROMPATCHA0.U)
#define HW_ROMC_ROMPATCHA0_WR(v)     (HW_ROMC_ROMPATCHA0.U = (v))
#define HW_ROMC_ROMPATCHA0_SET(v)    (HW_ROMC_ROMPATCHA0_WR(HW_ROMC_ROMPATCHA0_RD() |  (v)))
#define HW_ROMC_ROMPATCHA0_CLR(v)    (HW_ROMC_ROMPATCHA0_WR(HW_ROMC_ROMPATCHA0_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA0_TOG(v)    (HW_ROMC_ROMPATCHA0_WR(HW_ROMC_ROMPATCHA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA0 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA0, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA0_THUMBX      (0)
#define BM_ROMC_ROMPATCHA0_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA0_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA0_THUMBX)
#else
#define BF_ROMC_ROMPATCHA0_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA0_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA0_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA0, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA0, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA0_ADDRX      (1)
#define BM_ROMC_ROMPATCHA0_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA0_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA0_ADDRX)
#else
#define BF_ROMC_ROMPATCHA0_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA0_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA0_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA0, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA1 - ROMC Address Registers 1 (RW)
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
} hw_romc_rompatcha1_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA1 register
 */
#define HW_ROMC_ROMPATCHA1_ADDR      (REGS_ROMC_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA1           (*(volatile hw_romc_rompatcha1_t *) HW_ROMC_ROMPATCHA1_ADDR)
#define HW_ROMC_ROMPATCHA1_RD()      (HW_ROMC_ROMPATCHA1.U)
#define HW_ROMC_ROMPATCHA1_WR(v)     (HW_ROMC_ROMPATCHA1.U = (v))
#define HW_ROMC_ROMPATCHA1_SET(v)    (HW_ROMC_ROMPATCHA1_WR(HW_ROMC_ROMPATCHA1_RD() |  (v)))
#define HW_ROMC_ROMPATCHA1_CLR(v)    (HW_ROMC_ROMPATCHA1_WR(HW_ROMC_ROMPATCHA1_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA1_TOG(v)    (HW_ROMC_ROMPATCHA1_WR(HW_ROMC_ROMPATCHA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA1 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA1, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA1_THUMBX      (0)
#define BM_ROMC_ROMPATCHA1_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA1_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA1_THUMBX)
#else
#define BF_ROMC_ROMPATCHA1_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA1_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA1_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA1, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA1, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA1_ADDRX      (1)
#define BM_ROMC_ROMPATCHA1_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA1_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA1_ADDRX)
#else
#define BF_ROMC_ROMPATCHA1_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA1_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA1_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA1, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA2 - ROMC Address Registers 2 (RW)
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
} hw_romc_rompatcha2_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA2 register
 */
#define HW_ROMC_ROMPATCHA2_ADDR      (REGS_ROMC_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA2           (*(volatile hw_romc_rompatcha2_t *) HW_ROMC_ROMPATCHA2_ADDR)
#define HW_ROMC_ROMPATCHA2_RD()      (HW_ROMC_ROMPATCHA2.U)
#define HW_ROMC_ROMPATCHA2_WR(v)     (HW_ROMC_ROMPATCHA2.U = (v))
#define HW_ROMC_ROMPATCHA2_SET(v)    (HW_ROMC_ROMPATCHA2_WR(HW_ROMC_ROMPATCHA2_RD() |  (v)))
#define HW_ROMC_ROMPATCHA2_CLR(v)    (HW_ROMC_ROMPATCHA2_WR(HW_ROMC_ROMPATCHA2_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA2_TOG(v)    (HW_ROMC_ROMPATCHA2_WR(HW_ROMC_ROMPATCHA2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA2 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA2, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA2_THUMBX      (0)
#define BM_ROMC_ROMPATCHA2_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA2_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA2_THUMBX)
#else
#define BF_ROMC_ROMPATCHA2_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA2_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA2_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA2, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA2, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA2_ADDRX      (1)
#define BM_ROMC_ROMPATCHA2_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA2_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA2_ADDRX)
#else
#define BF_ROMC_ROMPATCHA2_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA2_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA2_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA2, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA3 - ROMC Address Registers 3 (RW)
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
} hw_romc_rompatcha3_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA3 register
 */
#define HW_ROMC_ROMPATCHA3_ADDR      (REGS_ROMC_BASE + 0x10c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA3           (*(volatile hw_romc_rompatcha3_t *) HW_ROMC_ROMPATCHA3_ADDR)
#define HW_ROMC_ROMPATCHA3_RD()      (HW_ROMC_ROMPATCHA3.U)
#define HW_ROMC_ROMPATCHA3_WR(v)     (HW_ROMC_ROMPATCHA3.U = (v))
#define HW_ROMC_ROMPATCHA3_SET(v)    (HW_ROMC_ROMPATCHA3_WR(HW_ROMC_ROMPATCHA3_RD() |  (v)))
#define HW_ROMC_ROMPATCHA3_CLR(v)    (HW_ROMC_ROMPATCHA3_WR(HW_ROMC_ROMPATCHA3_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA3_TOG(v)    (HW_ROMC_ROMPATCHA3_WR(HW_ROMC_ROMPATCHA3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA3 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA3, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA3_THUMBX      (0)
#define BM_ROMC_ROMPATCHA3_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA3_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA3_THUMBX)
#else
#define BF_ROMC_ROMPATCHA3_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA3_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA3_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA3, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA3, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA3_ADDRX      (1)
#define BM_ROMC_ROMPATCHA3_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA3_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA3_ADDRX)
#else
#define BF_ROMC_ROMPATCHA3_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA3_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA3_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA3, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA4 - ROMC Address Registers 4 (RW)
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
} hw_romc_rompatcha4_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA4 register
 */
#define HW_ROMC_ROMPATCHA4_ADDR      (REGS_ROMC_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA4           (*(volatile hw_romc_rompatcha4_t *) HW_ROMC_ROMPATCHA4_ADDR)
#define HW_ROMC_ROMPATCHA4_RD()      (HW_ROMC_ROMPATCHA4.U)
#define HW_ROMC_ROMPATCHA4_WR(v)     (HW_ROMC_ROMPATCHA4.U = (v))
#define HW_ROMC_ROMPATCHA4_SET(v)    (HW_ROMC_ROMPATCHA4_WR(HW_ROMC_ROMPATCHA4_RD() |  (v)))
#define HW_ROMC_ROMPATCHA4_CLR(v)    (HW_ROMC_ROMPATCHA4_WR(HW_ROMC_ROMPATCHA4_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA4_TOG(v)    (HW_ROMC_ROMPATCHA4_WR(HW_ROMC_ROMPATCHA4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA4 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA4, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA4_THUMBX      (0)
#define BM_ROMC_ROMPATCHA4_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA4_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA4_THUMBX)
#else
#define BF_ROMC_ROMPATCHA4_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA4_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA4_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA4, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA4, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA4_ADDRX      (1)
#define BM_ROMC_ROMPATCHA4_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA4_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA4_ADDRX)
#else
#define BF_ROMC_ROMPATCHA4_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA4_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA4_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA4, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA5 - ROMC Address Registers 5 (RW)
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
} hw_romc_rompatcha5_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA5 register
 */
#define HW_ROMC_ROMPATCHA5_ADDR      (REGS_ROMC_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA5           (*(volatile hw_romc_rompatcha5_t *) HW_ROMC_ROMPATCHA5_ADDR)
#define HW_ROMC_ROMPATCHA5_RD()      (HW_ROMC_ROMPATCHA5.U)
#define HW_ROMC_ROMPATCHA5_WR(v)     (HW_ROMC_ROMPATCHA5.U = (v))
#define HW_ROMC_ROMPATCHA5_SET(v)    (HW_ROMC_ROMPATCHA5_WR(HW_ROMC_ROMPATCHA5_RD() |  (v)))
#define HW_ROMC_ROMPATCHA5_CLR(v)    (HW_ROMC_ROMPATCHA5_WR(HW_ROMC_ROMPATCHA5_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA5_TOG(v)    (HW_ROMC_ROMPATCHA5_WR(HW_ROMC_ROMPATCHA5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA5 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA5, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA5_THUMBX      (0)
#define BM_ROMC_ROMPATCHA5_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA5_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA5_THUMBX)
#else
#define BF_ROMC_ROMPATCHA5_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA5_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA5_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA5, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA5, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA5_ADDRX      (1)
#define BM_ROMC_ROMPATCHA5_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA5_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA5_ADDRX)
#else
#define BF_ROMC_ROMPATCHA5_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA5_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA5_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA5, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA6 - ROMC Address Registers 6 (RW)
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
} hw_romc_rompatcha6_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA6 register
 */
#define HW_ROMC_ROMPATCHA6_ADDR      (REGS_ROMC_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA6           (*(volatile hw_romc_rompatcha6_t *) HW_ROMC_ROMPATCHA6_ADDR)
#define HW_ROMC_ROMPATCHA6_RD()      (HW_ROMC_ROMPATCHA6.U)
#define HW_ROMC_ROMPATCHA6_WR(v)     (HW_ROMC_ROMPATCHA6.U = (v))
#define HW_ROMC_ROMPATCHA6_SET(v)    (HW_ROMC_ROMPATCHA6_WR(HW_ROMC_ROMPATCHA6_RD() |  (v)))
#define HW_ROMC_ROMPATCHA6_CLR(v)    (HW_ROMC_ROMPATCHA6_WR(HW_ROMC_ROMPATCHA6_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA6_TOG(v)    (HW_ROMC_ROMPATCHA6_WR(HW_ROMC_ROMPATCHA6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA6 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA6, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA6_THUMBX      (0)
#define BM_ROMC_ROMPATCHA6_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA6_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA6_THUMBX)
#else
#define BF_ROMC_ROMPATCHA6_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA6_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA6_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA6, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA6, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA6_ADDRX      (1)
#define BM_ROMC_ROMPATCHA6_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA6_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA6_ADDRX)
#else
#define BF_ROMC_ROMPATCHA6_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA6_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA6_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA6, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA7 - ROMC Address Registers 7 (RW)
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
} hw_romc_rompatcha7_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA7 register
 */
#define HW_ROMC_ROMPATCHA7_ADDR      (REGS_ROMC_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA7           (*(volatile hw_romc_rompatcha7_t *) HW_ROMC_ROMPATCHA7_ADDR)
#define HW_ROMC_ROMPATCHA7_RD()      (HW_ROMC_ROMPATCHA7.U)
#define HW_ROMC_ROMPATCHA7_WR(v)     (HW_ROMC_ROMPATCHA7.U = (v))
#define HW_ROMC_ROMPATCHA7_SET(v)    (HW_ROMC_ROMPATCHA7_WR(HW_ROMC_ROMPATCHA7_RD() |  (v)))
#define HW_ROMC_ROMPATCHA7_CLR(v)    (HW_ROMC_ROMPATCHA7_WR(HW_ROMC_ROMPATCHA7_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA7_TOG(v)    (HW_ROMC_ROMPATCHA7_WR(HW_ROMC_ROMPATCHA7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA7 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA7, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA7_THUMBX      (0)
#define BM_ROMC_ROMPATCHA7_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA7_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA7_THUMBX)
#else
#define BF_ROMC_ROMPATCHA7_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA7_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA7_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA7, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA7, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA7_ADDRX      (1)
#define BM_ROMC_ROMPATCHA7_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA7_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA7_ADDRX)
#else
#define BF_ROMC_ROMPATCHA7_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA7_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA7_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA7, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA8 - ROMC Address Registers 8 (RW)
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
} hw_romc_rompatcha8_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA8 register
 */
#define HW_ROMC_ROMPATCHA8_ADDR      (REGS_ROMC_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA8           (*(volatile hw_romc_rompatcha8_t *) HW_ROMC_ROMPATCHA8_ADDR)
#define HW_ROMC_ROMPATCHA8_RD()      (HW_ROMC_ROMPATCHA8.U)
#define HW_ROMC_ROMPATCHA8_WR(v)     (HW_ROMC_ROMPATCHA8.U = (v))
#define HW_ROMC_ROMPATCHA8_SET(v)    (HW_ROMC_ROMPATCHA8_WR(HW_ROMC_ROMPATCHA8_RD() |  (v)))
#define HW_ROMC_ROMPATCHA8_CLR(v)    (HW_ROMC_ROMPATCHA8_WR(HW_ROMC_ROMPATCHA8_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA8_TOG(v)    (HW_ROMC_ROMPATCHA8_WR(HW_ROMC_ROMPATCHA8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA8 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA8, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA8_THUMBX      (0)
#define BM_ROMC_ROMPATCHA8_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA8_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA8_THUMBX)
#else
#define BF_ROMC_ROMPATCHA8_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA8_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA8_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA8, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA8, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA8_ADDRX      (1)
#define BM_ROMC_ROMPATCHA8_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA8_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA8_ADDRX)
#else
#define BF_ROMC_ROMPATCHA8_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA8_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA8_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA8, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA9 - ROMC Address Registers 9 (RW)
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
} hw_romc_rompatcha9_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA9 register
 */
#define HW_ROMC_ROMPATCHA9_ADDR      (REGS_ROMC_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA9           (*(volatile hw_romc_rompatcha9_t *) HW_ROMC_ROMPATCHA9_ADDR)
#define HW_ROMC_ROMPATCHA9_RD()      (HW_ROMC_ROMPATCHA9.U)
#define HW_ROMC_ROMPATCHA9_WR(v)     (HW_ROMC_ROMPATCHA9.U = (v))
#define HW_ROMC_ROMPATCHA9_SET(v)    (HW_ROMC_ROMPATCHA9_WR(HW_ROMC_ROMPATCHA9_RD() |  (v)))
#define HW_ROMC_ROMPATCHA9_CLR(v)    (HW_ROMC_ROMPATCHA9_WR(HW_ROMC_ROMPATCHA9_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA9_TOG(v)    (HW_ROMC_ROMPATCHA9_WR(HW_ROMC_ROMPATCHA9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA9 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA9, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA9_THUMBX      (0)
#define BM_ROMC_ROMPATCHA9_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA9_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA9_THUMBX)
#else
#define BF_ROMC_ROMPATCHA9_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA9_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA9_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA9, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA9, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA9_ADDRX      (1)
#define BM_ROMC_ROMPATCHA9_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA9_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA9_ADDRX)
#else
#define BF_ROMC_ROMPATCHA9_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA9_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA9_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA9, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA10 - ROMC Address Registers 10 (RW)
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
} hw_romc_rompatcha10_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA10 register
 */
#define HW_ROMC_ROMPATCHA10_ADDR      (REGS_ROMC_BASE + 0x128)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA10           (*(volatile hw_romc_rompatcha10_t *) HW_ROMC_ROMPATCHA10_ADDR)
#define HW_ROMC_ROMPATCHA10_RD()      (HW_ROMC_ROMPATCHA10.U)
#define HW_ROMC_ROMPATCHA10_WR(v)     (HW_ROMC_ROMPATCHA10.U = (v))
#define HW_ROMC_ROMPATCHA10_SET(v)    (HW_ROMC_ROMPATCHA10_WR(HW_ROMC_ROMPATCHA10_RD() |  (v)))
#define HW_ROMC_ROMPATCHA10_CLR(v)    (HW_ROMC_ROMPATCHA10_WR(HW_ROMC_ROMPATCHA10_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA10_TOG(v)    (HW_ROMC_ROMPATCHA10_WR(HW_ROMC_ROMPATCHA10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA10 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA10, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA10_THUMBX      (0)
#define BM_ROMC_ROMPATCHA10_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA10_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA10_THUMBX)
#else
#define BF_ROMC_ROMPATCHA10_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA10_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA10_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA10, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA10, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA10_ADDRX      (1)
#define BM_ROMC_ROMPATCHA10_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA10_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA10_ADDRX)
#else
#define BF_ROMC_ROMPATCHA10_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA10_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA10_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA10, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA11 - ROMC Address Registers 11 (RW)
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
} hw_romc_rompatcha11_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA11 register
 */
#define HW_ROMC_ROMPATCHA11_ADDR      (REGS_ROMC_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA11           (*(volatile hw_romc_rompatcha11_t *) HW_ROMC_ROMPATCHA11_ADDR)
#define HW_ROMC_ROMPATCHA11_RD()      (HW_ROMC_ROMPATCHA11.U)
#define HW_ROMC_ROMPATCHA11_WR(v)     (HW_ROMC_ROMPATCHA11.U = (v))
#define HW_ROMC_ROMPATCHA11_SET(v)    (HW_ROMC_ROMPATCHA11_WR(HW_ROMC_ROMPATCHA11_RD() |  (v)))
#define HW_ROMC_ROMPATCHA11_CLR(v)    (HW_ROMC_ROMPATCHA11_WR(HW_ROMC_ROMPATCHA11_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA11_TOG(v)    (HW_ROMC_ROMPATCHA11_WR(HW_ROMC_ROMPATCHA11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA11 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA11, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA11_THUMBX      (0)
#define BM_ROMC_ROMPATCHA11_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA11_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA11_THUMBX)
#else
#define BF_ROMC_ROMPATCHA11_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA11_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA11_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA11, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA11, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA11_ADDRX      (1)
#define BM_ROMC_ROMPATCHA11_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA11_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA11_ADDRX)
#else
#define BF_ROMC_ROMPATCHA11_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA11_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA11_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA11, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA12 - ROMC Address Registers 12 (RW)
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
} hw_romc_rompatcha12_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA12 register
 */
#define HW_ROMC_ROMPATCHA12_ADDR      (REGS_ROMC_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA12           (*(volatile hw_romc_rompatcha12_t *) HW_ROMC_ROMPATCHA12_ADDR)
#define HW_ROMC_ROMPATCHA12_RD()      (HW_ROMC_ROMPATCHA12.U)
#define HW_ROMC_ROMPATCHA12_WR(v)     (HW_ROMC_ROMPATCHA12.U = (v))
#define HW_ROMC_ROMPATCHA12_SET(v)    (HW_ROMC_ROMPATCHA12_WR(HW_ROMC_ROMPATCHA12_RD() |  (v)))
#define HW_ROMC_ROMPATCHA12_CLR(v)    (HW_ROMC_ROMPATCHA12_WR(HW_ROMC_ROMPATCHA12_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA12_TOG(v)    (HW_ROMC_ROMPATCHA12_WR(HW_ROMC_ROMPATCHA12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA12 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA12, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA12_THUMBX      (0)
#define BM_ROMC_ROMPATCHA12_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA12_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA12_THUMBX)
#else
#define BF_ROMC_ROMPATCHA12_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA12_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA12_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA12, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA12, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA12_ADDRX      (1)
#define BM_ROMC_ROMPATCHA12_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA12_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA12_ADDRX)
#else
#define BF_ROMC_ROMPATCHA12_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA12_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA12_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA12, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA13 - ROMC Address Registers 13 (RW)
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
} hw_romc_rompatcha13_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA13 register
 */
#define HW_ROMC_ROMPATCHA13_ADDR      (REGS_ROMC_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA13           (*(volatile hw_romc_rompatcha13_t *) HW_ROMC_ROMPATCHA13_ADDR)
#define HW_ROMC_ROMPATCHA13_RD()      (HW_ROMC_ROMPATCHA13.U)
#define HW_ROMC_ROMPATCHA13_WR(v)     (HW_ROMC_ROMPATCHA13.U = (v))
#define HW_ROMC_ROMPATCHA13_SET(v)    (HW_ROMC_ROMPATCHA13_WR(HW_ROMC_ROMPATCHA13_RD() |  (v)))
#define HW_ROMC_ROMPATCHA13_CLR(v)    (HW_ROMC_ROMPATCHA13_WR(HW_ROMC_ROMPATCHA13_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA13_TOG(v)    (HW_ROMC_ROMPATCHA13_WR(HW_ROMC_ROMPATCHA13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA13 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA13, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA13_THUMBX      (0)
#define BM_ROMC_ROMPATCHA13_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA13_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA13_THUMBX)
#else
#define BF_ROMC_ROMPATCHA13_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA13_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA13_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA13, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA13, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA13_ADDRX      (1)
#define BM_ROMC_ROMPATCHA13_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA13_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA13_ADDRX)
#else
#define BF_ROMC_ROMPATCHA13_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA13_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA13_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA13, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA14 - ROMC Address Registers 14 (RW)
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
} hw_romc_rompatcha14_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA14 register
 */
#define HW_ROMC_ROMPATCHA14_ADDR      (REGS_ROMC_BASE + 0x138)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA14           (*(volatile hw_romc_rompatcha14_t *) HW_ROMC_ROMPATCHA14_ADDR)
#define HW_ROMC_ROMPATCHA14_RD()      (HW_ROMC_ROMPATCHA14.U)
#define HW_ROMC_ROMPATCHA14_WR(v)     (HW_ROMC_ROMPATCHA14.U = (v))
#define HW_ROMC_ROMPATCHA14_SET(v)    (HW_ROMC_ROMPATCHA14_WR(HW_ROMC_ROMPATCHA14_RD() |  (v)))
#define HW_ROMC_ROMPATCHA14_CLR(v)    (HW_ROMC_ROMPATCHA14_WR(HW_ROMC_ROMPATCHA14_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA14_TOG(v)    (HW_ROMC_ROMPATCHA14_WR(HW_ROMC_ROMPATCHA14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA14 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA14, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA14_THUMBX      (0)
#define BM_ROMC_ROMPATCHA14_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA14_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA14_THUMBX)
#else
#define BF_ROMC_ROMPATCHA14_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA14_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA14_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA14, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA14, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA14_ADDRX      (1)
#define BM_ROMC_ROMPATCHA14_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA14_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA14_ADDRX)
#else
#define BF_ROMC_ROMPATCHA14_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA14_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA14_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA14, ADDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHA15 - ROMC Address Registers 15 (RW)
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
} hw_romc_rompatcha15_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHA15 register
 */
#define HW_ROMC_ROMPATCHA15_ADDR      (REGS_ROMC_BASE + 0x13c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHA15           (*(volatile hw_romc_rompatcha15_t *) HW_ROMC_ROMPATCHA15_ADDR)
#define HW_ROMC_ROMPATCHA15_RD()      (HW_ROMC_ROMPATCHA15.U)
#define HW_ROMC_ROMPATCHA15_WR(v)     (HW_ROMC_ROMPATCHA15.U = (v))
#define HW_ROMC_ROMPATCHA15_SET(v)    (HW_ROMC_ROMPATCHA15_WR(HW_ROMC_ROMPATCHA15_RD() |  (v)))
#define HW_ROMC_ROMPATCHA15_CLR(v)    (HW_ROMC_ROMPATCHA15_WR(HW_ROMC_ROMPATCHA15_RD() & ~(v)))
#define HW_ROMC_ROMPATCHA15_TOG(v)    (HW_ROMC_ROMPATCHA15_WR(HW_ROMC_ROMPATCHA15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHA15 bitfields
 */

/* --- Register HW_ROMC_ROMPATCHA15, field THUMBX[0:0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCHA15_THUMBX      (0)
#define BM_ROMC_ROMPATCHA15_THUMBX      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA15_THUMBX(v)   ((((reg32_t) v) << 0) & BM_ROMC_ROMPATCHA15_THUMBX)
#else
#define BF_ROMC_ROMPATCHA15_THUMBX(v)   (((v) << 0) & BM_ROMC_ROMPATCHA15_THUMBX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHA15_THUMBX(v)   BF_CS1(ROMC_ROMPATCHA15, THUMBX, v)
#endif


/* --- Register HW_ROMC_ROMPATCHA15, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCHA15_ADDRX      (1)
#define BM_ROMC_ROMPATCHA15_ADDRX      (0x007ffffe)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHA15_ADDRX(v)   ((((reg32_t) v) << 1) & BM_ROMC_ROMPATCHA15_ADDRX)
#else
#define BF_ROMC_ROMPATCHA15_ADDRX(v)   (((v) << 1) & BM_ROMC_ROMPATCHA15_ADDRX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHA15_ADDRX(v)   BF_CS1(ROMC_ROMPATCHA15, ADDRX, v)
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
#define HW_ROMC_ROMPATCHSR_WR(v)     (HW_ROMC_ROMPATCHSR.U = (v))
#define HW_ROMC_ROMPATCHSR_SET(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() |  (v)))
#define HW_ROMC_ROMPATCHSR_CLR(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() & ~(v)))
#define HW_ROMC_ROMPATCHSR_TOG(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHSR bitfields
 */

/* --- Register HW_ROMC_ROMPATCHSR, field SOURCE[5:0] (RO)
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

#define BP_ROMC_ROMPATCHSR_SOURCE      (0)
#define BM_ROMC_ROMPATCHSR_SOURCE      (0x0000003f)


/* --- Register HW_ROMC_ROMPATCHSR, field SW[17:17] (W1C)
 *
 * ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address
 * comparator matches occurred. Writing a 1 to this bit will clear this it.
 *
 * Values:
 * 0 - no event or comparator collisions
 * 1 - a collision has occurred
 */

#define BP_ROMC_ROMPATCHSR_SW      (17)
#define BM_ROMC_ROMPATCHSR_SW      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_ROMC_ROMPATCHSR_SW(v)   ((((reg32_t) v) << 17) & BM_ROMC_ROMPATCHSR_SW)
#else
#define BF_ROMC_ROMPATCHSR_SW(v)   (((v) << 17) & BM_ROMC_ROMPATCHSR_SW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_ROMC_ROMPATCHSR_SW(v)   BF_CS1(ROMC_ROMPATCHSR, SW, v)
#endif



/*!
 * @brief All ROMC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[53];
    volatile hw_romc_rompatchd0_t ROMPATCHD0; //!< ROMC Data Registers 0
    volatile hw_romc_rompatchd1_t ROMPATCHD1; //!< ROMC Data Registers 1
    volatile hw_romc_rompatchd2_t ROMPATCHD2; //!< ROMC Data Registers 2
    volatile hw_romc_rompatchd3_t ROMPATCHD3; //!< ROMC Data Registers 3
    volatile hw_romc_rompatchd4_t ROMPATCHD4; //!< ROMC Data Registers 4
    volatile hw_romc_rompatchd5_t ROMPATCHD5; //!< ROMC Data Registers 5
    volatile hw_romc_rompatchd6_t ROMPATCHD6; //!< ROMC Data Registers 6
    volatile hw_romc_rompatchd7_t ROMPATCHD7; //!< ROMC Data Registers 7
    volatile hw_romc_rompatchcntl_t ROMPATCHCNTL; //!< ROMC Control Register
    volatile hw_romc_rompatchenh_t ROMPATCHENH; //!< ROMC Enable Register High
    volatile hw_romc_rompatchenl_t ROMPATCHENL; //!< ROMC Enable Register Low
    volatile hw_romc_rompatcha0_t ROMPATCHA0; //!< ROMC Address Registers 0
    volatile hw_romc_rompatcha1_t ROMPATCHA1; //!< ROMC Address Registers 1
    volatile hw_romc_rompatcha2_t ROMPATCHA2; //!< ROMC Address Registers 2
    volatile hw_romc_rompatcha3_t ROMPATCHA3; //!< ROMC Address Registers 3
    volatile hw_romc_rompatcha4_t ROMPATCHA4; //!< ROMC Address Registers 4
    volatile hw_romc_rompatcha5_t ROMPATCHA5; //!< ROMC Address Registers 5
    volatile hw_romc_rompatcha6_t ROMPATCHA6; //!< ROMC Address Registers 6
    volatile hw_romc_rompatcha7_t ROMPATCHA7; //!< ROMC Address Registers 7
    volatile hw_romc_rompatcha8_t ROMPATCHA8; //!< ROMC Address Registers 8
    volatile hw_romc_rompatcha9_t ROMPATCHA9; //!< ROMC Address Registers 9
    volatile hw_romc_rompatcha10_t ROMPATCHA10; //!< ROMC Address Registers 10
    volatile hw_romc_rompatcha11_t ROMPATCHA11; //!< ROMC Address Registers 11
    volatile hw_romc_rompatcha12_t ROMPATCHA12; //!< ROMC Address Registers 12
    volatile hw_romc_rompatcha13_t ROMPATCHA13; //!< ROMC Address Registers 13
    volatile hw_romc_rompatcha14_t ROMPATCHA14; //!< ROMC Address Registers 14
    volatile hw_romc_rompatcha15_t ROMPATCHA15; //!< ROMC Address Registers 15
    reg32_t _reserved1[50];
    volatile hw_romc_rompatchsr_t ROMPATCHSR; //!< ROMC Status Register
} hw_romc_t;
#endif

//! @brief Macro to access all ROMC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ROMC(0)</code>.
#define HW_ROMC     (*(volatile hw_romc_t *) REGS_ROMC_BASE)


#endif // _ROMC_H
