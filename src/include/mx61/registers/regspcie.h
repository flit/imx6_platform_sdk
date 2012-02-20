/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _PCIE_H
#define _PCIE_H

#include "regs.h"

#ifndef REGS_PCIE_BASE
#define REGS_PCIE_BASE (REGS_BASE + 0x01000000)

#endif


/*
 * HW_PCIE_DEVICEID - Device ID and Vendor ID Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned RESERVED1 : 16;
        unsigned CX_DEVICE_ID_N : 16;
        unsigned CX_VENDOR_ID_N : 16;

    } B;
} hw_pcie_deviceid_t;
#endif

/*
 * constants & macros for entire PCIE_DEVICEID register
 */
#define HW_PCIE_DEVICEID_ADDR      (REGS_PCIE_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_DEVICEID           (*(volatile hw_pcie_deviceid_t *) HW_PCIE_DEVICEID_ADDR)
#define HW_PCIE_DEVICEID_RD()      (HW_PCIE_DEVICEID.U)
#define HW_PCIE_DEVICEID_WR(v)     (HW_PCIE_DEVICEID.U = (v))
#define HW_PCIE_DEVICEID_SET(v)    (HW_PCIE_DEVICEID_WR(HW_PCIE_DEVICEID_RD() |  (v)))
#define HW_PCIE_DEVICEID_CLR(v)    (HW_PCIE_DEVICEID_WR(HW_PCIE_DEVICEID_RD() & ~(v)))
#define HW_PCIE_DEVICEID_TOG(v)    (HW_PCIE_DEVICEID_WR(HW_PCIE_DEVICEID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_DEVICEID bitfields
 */

/* --- Register HW_PCIE_DEVICEID, field CX_DEVICE_ID_N */

#define BP_PCIE_DEVICEID_CX_DEVICE_ID_N      16
#define BM_PCIE_DEVICEID_CX_DEVICE_ID_N      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DEVICEID_CX_DEVICE_ID_N(v)   ((((reg32_t) v) << 16) & BM_PCIE_DEVICEID_CX_DEVICE_ID_N)
#else
#define BF_PCIE_DEVICEID_CX_DEVICE_ID_N(v)   (((v) << 16) & BM_PCIE_DEVICEID_CX_DEVICE_ID_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DEVICEID_CX_DEVICE_ID_N(v)   BF_CS1(PCIE_DEVICEID, CX_DEVICE_ID_N, v)
#endif

/* --- Register HW_PCIE_DEVICEID, field CX_VENDOR_ID_N */

#define BP_PCIE_DEVICEID_CX_VENDOR_ID_N      0
#define BM_PCIE_DEVICEID_CX_VENDOR_ID_N      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DEVICEID_CX_VENDOR_ID_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_DEVICEID_CX_VENDOR_ID_N)
#else
#define BF_PCIE_DEVICEID_CX_VENDOR_ID_N(v)   (((v) << 0) & BM_PCIE_DEVICEID_CX_VENDOR_ID_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DEVICEID_CX_VENDOR_ID_N(v)   BF_CS1(PCIE_DEVICEID, CX_VENDOR_ID_N, v)
#endif

/*
 * HW_PCIE_COMMAND - Command and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SIGNALED_SYSTEM_ERROR : 1;
        unsigned DETECTED_PARITY_ERROR : 1;
        unsigned RECEIVED_MASTER_ABORT : 1;
        unsigned RECEIVED_TARGET_ABORT : 1;
        unsigned SIGNALED_TARGET_ABORT : 1;
        unsigned DEVSEL_TIMING : 2;
        unsigned MASTER_DATA_PARITY_ERROR : 1;
        unsigned FAST_BACK_TO_BACK_CAPABLE : 1;
        unsigned RESERVED0 : 1;
        unsigned SIXTYSIX_MHZ_CAPABLE : 1;
        unsigned CAPABILITIES_LIST : 1;
        unsigned INTX_STATUS : 1;
        unsigned RESERVED1 : 3;
        unsigned RESERVED2 : 5;
        unsigned INTX_ASSERTION_DISABLE : 1;
        unsigned FAST_BACK_TO_BACK_ENABLE : 1;
        unsigned SERR_ENABLE : 1;
        unsigned IDSEL_STEPPING : 1;
        unsigned PARITY_ERROR_RESPONSE : 1;
        unsigned VGA_PALETTE_SNOOP : 1;
        unsigned MEMORY_WRITE_AND_INVALIDATE : 1;
        unsigned SPECIAL_CYCLE_ENABLE : 1;
        unsigned BUS_MASTER_ENABLE : 1;
        unsigned MEMORY_SPACE_ENABLE : 1;
        unsigned I_O_SPACE_ENABLE : 1;

    } B;
} hw_pcie_command_t;
#endif

/*
 * constants & macros for entire PCIE_COMMAND register
 */
#define HW_PCIE_COMMAND_ADDR      (REGS_PCIE_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_COMMAND           (*(volatile hw_pcie_command_t *) HW_PCIE_COMMAND_ADDR)
#define HW_PCIE_COMMAND_RD()      (HW_PCIE_COMMAND.U)
#define HW_PCIE_COMMAND_WR(v)     (HW_PCIE_COMMAND.U = (v))
#define HW_PCIE_COMMAND_SET(v)    (HW_PCIE_COMMAND_WR(HW_PCIE_COMMAND_RD() |  (v)))
#define HW_PCIE_COMMAND_CLR(v)    (HW_PCIE_COMMAND_WR(HW_PCIE_COMMAND_RD() & ~(v)))
#define HW_PCIE_COMMAND_TOG(v)    (HW_PCIE_COMMAND_WR(HW_PCIE_COMMAND_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_COMMAND bitfields
 */

/* --- Register HW_PCIE_COMMAND, field SIGNALED_SYSTEM_ERROR */

#define BP_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR      31
#define BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)   ((((reg32_t) v) << 31) & BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR)
#else
#define BF_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)   (((v) << 31) & BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)   BF_CS1(PCIE_COMMAND, SIGNALED_SYSTEM_ERROR, v)
#endif

/* --- Register HW_PCIE_COMMAND, field DETECTED_PARITY_ERROR */

#define BP_PCIE_COMMAND_DETECTED_PARITY_ERROR      30
#define BM_PCIE_COMMAND_DETECTED_PARITY_ERROR      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)   ((((reg32_t) v) << 30) & BM_PCIE_COMMAND_DETECTED_PARITY_ERROR)
#else
#define BF_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)   (((v) << 30) & BM_PCIE_COMMAND_DETECTED_PARITY_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)   BF_CS1(PCIE_COMMAND, DETECTED_PARITY_ERROR, v)
#endif

/* --- Register HW_PCIE_COMMAND, field RECEIVED_MASTER_ABORT */

#define BP_PCIE_COMMAND_RECEIVED_MASTER_ABORT      29
#define BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)   ((((reg32_t) v) << 29) & BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT)
#else
#define BF_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)   (((v) << 29) & BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)   BF_CS1(PCIE_COMMAND, RECEIVED_MASTER_ABORT, v)
#endif

/* --- Register HW_PCIE_COMMAND, field RECEIVED_TARGET_ABORT */

#define BP_PCIE_COMMAND_RECEIVED_TARGET_ABORT      28
#define BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)   ((((reg32_t) v) << 28) & BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT)
#else
#define BF_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)   (((v) << 28) & BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)   BF_CS1(PCIE_COMMAND, RECEIVED_TARGET_ABORT, v)
#endif

/* --- Register HW_PCIE_COMMAND, field SIGNALED_TARGET_ABORT */

#define BP_PCIE_COMMAND_SIGNALED_TARGET_ABORT      27
#define BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)   ((((reg32_t) v) << 27) & BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT)
#else
#define BF_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)   (((v) << 27) & BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)   BF_CS1(PCIE_COMMAND, SIGNALED_TARGET_ABORT, v)
#endif

/* --- Register HW_PCIE_COMMAND, field DEVSEL_TIMING */

#define BP_PCIE_COMMAND_DEVSEL_TIMING      25
#define BM_PCIE_COMMAND_DEVSEL_TIMING      0x06000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_DEVSEL_TIMING(v)   ((((reg32_t) v) << 25) & BM_PCIE_COMMAND_DEVSEL_TIMING)
#else
#define BF_PCIE_COMMAND_DEVSEL_TIMING(v)   (((v) << 25) & BM_PCIE_COMMAND_DEVSEL_TIMING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_DEVSEL_TIMING(v)   BF_CS1(PCIE_COMMAND, DEVSEL_TIMING, v)
#endif

/* --- Register HW_PCIE_COMMAND, field MASTER_DATA_PARITY_ERROR */

#define BP_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR      24
#define BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)   ((((reg32_t) v) << 24) & BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR)
#else
#define BF_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)   (((v) << 24) & BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)   BF_CS1(PCIE_COMMAND, MASTER_DATA_PARITY_ERROR, v)
#endif

/* --- Register HW_PCIE_COMMAND, field FAST_BACK_TO_BACK_CAPABLE */

#define BP_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE      23
#define BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)   ((((reg32_t) v) << 23) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE)
#else
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)   (((v) << 23) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)   BF_CS1(PCIE_COMMAND, FAST_BACK_TO_BACK_CAPABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field SIXTYSIX_MHZ_CAPABLE */

#define BP_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE      21
#define BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)   ((((reg32_t) v) << 21) & BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE)
#else
#define BF_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)   (((v) << 21) & BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)   BF_CS1(PCIE_COMMAND, SIXTYSIX_MHZ_CAPABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field CAPABILITIES_LIST */

#define BP_PCIE_COMMAND_CAPABILITIES_LIST      20
#define BM_PCIE_COMMAND_CAPABILITIES_LIST      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_CAPABILITIES_LIST(v)   ((((reg32_t) v) << 20) & BM_PCIE_COMMAND_CAPABILITIES_LIST)
#else
#define BF_PCIE_COMMAND_CAPABILITIES_LIST(v)   (((v) << 20) & BM_PCIE_COMMAND_CAPABILITIES_LIST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_CAPABILITIES_LIST(v)   BF_CS1(PCIE_COMMAND, CAPABILITIES_LIST, v)
#endif

/* --- Register HW_PCIE_COMMAND, field INTX_STATUS */

#define BP_PCIE_COMMAND_INTX_STATUS      19
#define BM_PCIE_COMMAND_INTX_STATUS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_INTX_STATUS(v)   ((((reg32_t) v) << 19) & BM_PCIE_COMMAND_INTX_STATUS)
#else
#define BF_PCIE_COMMAND_INTX_STATUS(v)   (((v) << 19) & BM_PCIE_COMMAND_INTX_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_INTX_STATUS(v)   BF_CS1(PCIE_COMMAND, INTX_STATUS, v)
#endif

/* --- Register HW_PCIE_COMMAND, field INTX_ASSERTION_DISABLE */

#define BP_PCIE_COMMAND_INTX_ASSERTION_DISABLE      10
#define BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)   ((((reg32_t) v) << 10) & BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE)
#else
#define BF_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)   (((v) << 10) & BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)   BF_CS1(PCIE_COMMAND, INTX_ASSERTION_DISABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field FAST_BACK_TO_BACK_ENABLE */

#define BP_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE      9
#define BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)   ((((reg32_t) v) << 9) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE)
#else
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)   (((v) << 9) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)   BF_CS1(PCIE_COMMAND, FAST_BACK_TO_BACK_ENABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field SERR_ENABLE */

#define BP_PCIE_COMMAND_SERR_ENABLE      8
#define BM_PCIE_COMMAND_SERR_ENABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_SERR_ENABLE(v)   ((((reg32_t) v) << 8) & BM_PCIE_COMMAND_SERR_ENABLE)
#else
#define BF_PCIE_COMMAND_SERR_ENABLE(v)   (((v) << 8) & BM_PCIE_COMMAND_SERR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_SERR_ENABLE(v)   BF_CS1(PCIE_COMMAND, SERR_ENABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field IDSEL_STEPPING */

#define BP_PCIE_COMMAND_IDSEL_STEPPING      7
#define BM_PCIE_COMMAND_IDSEL_STEPPING      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_IDSEL_STEPPING(v)   ((((reg32_t) v) << 7) & BM_PCIE_COMMAND_IDSEL_STEPPING)
#else
#define BF_PCIE_COMMAND_IDSEL_STEPPING(v)   (((v) << 7) & BM_PCIE_COMMAND_IDSEL_STEPPING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_IDSEL_STEPPING(v)   BF_CS1(PCIE_COMMAND, IDSEL_STEPPING, v)
#endif

/* --- Register HW_PCIE_COMMAND, field PARITY_ERROR_RESPONSE */

#define BP_PCIE_COMMAND_PARITY_ERROR_RESPONSE      6
#define BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)   ((((reg32_t) v) << 6) & BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE)
#else
#define BF_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)   (((v) << 6) & BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)   BF_CS1(PCIE_COMMAND, PARITY_ERROR_RESPONSE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field VGA_PALETTE_SNOOP */

#define BP_PCIE_COMMAND_VGA_PALETTE_SNOOP      5
#define BM_PCIE_COMMAND_VGA_PALETTE_SNOOP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)   ((((reg32_t) v) << 5) & BM_PCIE_COMMAND_VGA_PALETTE_SNOOP)
#else
#define BF_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)   (((v) << 5) & BM_PCIE_COMMAND_VGA_PALETTE_SNOOP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)   BF_CS1(PCIE_COMMAND, VGA_PALETTE_SNOOP, v)
#endif

/* --- Register HW_PCIE_COMMAND, field MEMORY_WRITE_AND_INVALIDATE */

#define BP_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE      4
#define BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)   ((((reg32_t) v) << 4) & BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE)
#else
#define BF_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)   (((v) << 4) & BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)   BF_CS1(PCIE_COMMAND, MEMORY_WRITE_AND_INVALIDATE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field SPECIAL_CYCLE_ENABLE */

#define BP_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE      3
#define BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)   ((((reg32_t) v) << 3) & BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE)
#else
#define BF_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)   (((v) << 3) & BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)   BF_CS1(PCIE_COMMAND, SPECIAL_CYCLE_ENABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field BUS_MASTER_ENABLE */

#define BP_PCIE_COMMAND_BUS_MASTER_ENABLE      2
#define BM_PCIE_COMMAND_BUS_MASTER_ENABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_BUS_MASTER_ENABLE(v)   ((((reg32_t) v) << 2) & BM_PCIE_COMMAND_BUS_MASTER_ENABLE)
#else
#define BF_PCIE_COMMAND_BUS_MASTER_ENABLE(v)   (((v) << 2) & BM_PCIE_COMMAND_BUS_MASTER_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_BUS_MASTER_ENABLE(v)   BF_CS1(PCIE_COMMAND, BUS_MASTER_ENABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field MEMORY_SPACE_ENABLE */

#define BP_PCIE_COMMAND_MEMORY_SPACE_ENABLE      1
#define BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)   ((((reg32_t) v) << 1) & BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE)
#else
#define BF_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)   (((v) << 1) & BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)   BF_CS1(PCIE_COMMAND, MEMORY_SPACE_ENABLE, v)
#endif

/* --- Register HW_PCIE_COMMAND, field I_O_SPACE_ENABLE */

#define BP_PCIE_COMMAND_I_O_SPACE_ENABLE      0
#define BM_PCIE_COMMAND_I_O_SPACE_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_COMMAND_I_O_SPACE_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_COMMAND_I_O_SPACE_ENABLE)
#else
#define BF_PCIE_COMMAND_I_O_SPACE_ENABLE(v)   (((v) << 0) & BM_PCIE_COMMAND_I_O_SPACE_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_COMMAND_I_O_SPACE_ENABLE(v)   BF_CS1(PCIE_COMMAND, I_O_SPACE_ENABLE, v)
#endif

/*
 * HW_PCIE_REVID - Revision ID and Class Code Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BASE_CLASS_CODE_N : 8;
        unsigned SUB_CLASS_CODE_N : 8;
        unsigned IF_CODE_N : 8;
        unsigned CX_REVISION_ID_N : 8;

    } B;
} hw_pcie_revid_t;
#endif

/*
 * constants & macros for entire PCIE_REVID register
 */
#define HW_PCIE_REVID_ADDR      (REGS_PCIE_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_REVID           (*(volatile hw_pcie_revid_t *) HW_PCIE_REVID_ADDR)
#define HW_PCIE_REVID_RD()      (HW_PCIE_REVID.U)
#define HW_PCIE_REVID_WR(v)     (HW_PCIE_REVID.U = (v))
#define HW_PCIE_REVID_SET(v)    (HW_PCIE_REVID_WR(HW_PCIE_REVID_RD() |  (v)))
#define HW_PCIE_REVID_CLR(v)    (HW_PCIE_REVID_WR(HW_PCIE_REVID_RD() & ~(v)))
#define HW_PCIE_REVID_TOG(v)    (HW_PCIE_REVID_WR(HW_PCIE_REVID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_REVID bitfields
 */

/* --- Register HW_PCIE_REVID, field BASE_CLASS_CODE_N */

#define BP_PCIE_REVID_BASE_CLASS_CODE_N      24
#define BM_PCIE_REVID_BASE_CLASS_CODE_N      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_REVID_BASE_CLASS_CODE_N(v)   ((((reg32_t) v) << 24) & BM_PCIE_REVID_BASE_CLASS_CODE_N)
#else
#define BF_PCIE_REVID_BASE_CLASS_CODE_N(v)   (((v) << 24) & BM_PCIE_REVID_BASE_CLASS_CODE_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_REVID_BASE_CLASS_CODE_N(v)   BF_CS1(PCIE_REVID, BASE_CLASS_CODE_N, v)
#endif

/* --- Register HW_PCIE_REVID, field SUB_CLASS_CODE_N */

#define BP_PCIE_REVID_SUB_CLASS_CODE_N      16
#define BM_PCIE_REVID_SUB_CLASS_CODE_N      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_REVID_SUB_CLASS_CODE_N(v)   ((((reg32_t) v) << 16) & BM_PCIE_REVID_SUB_CLASS_CODE_N)
#else
#define BF_PCIE_REVID_SUB_CLASS_CODE_N(v)   (((v) << 16) & BM_PCIE_REVID_SUB_CLASS_CODE_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_REVID_SUB_CLASS_CODE_N(v)   BF_CS1(PCIE_REVID, SUB_CLASS_CODE_N, v)
#endif

/* --- Register HW_PCIE_REVID, field IF_CODE_N */

#define BP_PCIE_REVID_IF_CODE_N      8
#define BM_PCIE_REVID_IF_CODE_N      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_REVID_IF_CODE_N(v)   ((((reg32_t) v) << 8) & BM_PCIE_REVID_IF_CODE_N)
#else
#define BF_PCIE_REVID_IF_CODE_N(v)   (((v) << 8) & BM_PCIE_REVID_IF_CODE_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_REVID_IF_CODE_N(v)   BF_CS1(PCIE_REVID, IF_CODE_N, v)
#endif

/* --- Register HW_PCIE_REVID, field CX_REVISION_ID_N */

#define BP_PCIE_REVID_CX_REVISION_ID_N      0
#define BM_PCIE_REVID_CX_REVISION_ID_N      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_REVID_CX_REVISION_ID_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_REVID_CX_REVISION_ID_N)
#else
#define BF_PCIE_REVID_CX_REVISION_ID_N(v)   (((v) << 0) & BM_PCIE_REVID_CX_REVISION_ID_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_REVID_CX_REVISION_ID_N(v)   BF_CS1(PCIE_REVID, CX_REVISION_ID_N, v)
#endif

/*
 * HW_PCIE_BIST - BIST Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NOT_SUPPORTED_BY__CORE : 8;
        unsigned MULTI_FUNCTION_DEVICE : 1;
        unsigned CONFIGURATION_HEADER_FORMAT : 7;
        unsigned MASTER_LATENCY_TIMER : 8;
        unsigned CACHE_LINE_SIZE : 8;

    } B;
} hw_pcie_bist_t;
#endif

/*
 * constants & macros for entire PCIE_BIST register
 */
#define HW_PCIE_BIST_ADDR      (REGS_PCIE_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BIST           (*(volatile hw_pcie_bist_t *) HW_PCIE_BIST_ADDR)
#define HW_PCIE_BIST_RD()      (HW_PCIE_BIST.U)
#define HW_PCIE_BIST_WR(v)     (HW_PCIE_BIST.U = (v))
#define HW_PCIE_BIST_SET(v)    (HW_PCIE_BIST_WR(HW_PCIE_BIST_RD() |  (v)))
#define HW_PCIE_BIST_CLR(v)    (HW_PCIE_BIST_WR(HW_PCIE_BIST_RD() & ~(v)))
#define HW_PCIE_BIST_TOG(v)    (HW_PCIE_BIST_WR(HW_PCIE_BIST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BIST bitfields
 */

/* --- Register HW_PCIE_BIST, field NOT_SUPPORTED_BY__CORE */

#define BP_PCIE_BIST_NOT_SUPPORTED_BY__CORE      24
#define BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)   ((((reg32_t) v) << 24) & BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE)
#else
#define BF_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)   (((v) << 24) & BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)   BF_CS1(PCIE_BIST, NOT_SUPPORTED_BY__CORE, v)
#endif

/* --- Register HW_PCIE_BIST, field MULTI_FUNCTION_DEVICE */

#define BP_PCIE_BIST_MULTI_FUNCTION_DEVICE      23
#define BM_PCIE_BIST_MULTI_FUNCTION_DEVICE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)   ((((reg32_t) v) << 23) & BM_PCIE_BIST_MULTI_FUNCTION_DEVICE)
#else
#define BF_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)   (((v) << 23) & BM_PCIE_BIST_MULTI_FUNCTION_DEVICE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)   BF_CS1(PCIE_BIST, MULTI_FUNCTION_DEVICE, v)
#endif

/* --- Register HW_PCIE_BIST, field CONFIGURATION_HEADER_FORMAT */

#define BP_PCIE_BIST_CONFIGURATION_HEADER_FORMAT      16
#define BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)   ((((reg32_t) v) << 16) & BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT)
#else
#define BF_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)   (((v) << 16) & BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)   BF_CS1(PCIE_BIST, CONFIGURATION_HEADER_FORMAT, v)
#endif

/* --- Register HW_PCIE_BIST, field MASTER_LATENCY_TIMER */

#define BP_PCIE_BIST_MASTER_LATENCY_TIMER      8
#define BM_PCIE_BIST_MASTER_LATENCY_TIMER      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BIST_MASTER_LATENCY_TIMER(v)   ((((reg32_t) v) << 8) & BM_PCIE_BIST_MASTER_LATENCY_TIMER)
#else
#define BF_PCIE_BIST_MASTER_LATENCY_TIMER(v)   (((v) << 8) & BM_PCIE_BIST_MASTER_LATENCY_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BIST_MASTER_LATENCY_TIMER(v)   BF_CS1(PCIE_BIST, MASTER_LATENCY_TIMER, v)
#endif

/* --- Register HW_PCIE_BIST, field CACHE_LINE_SIZE */

#define BP_PCIE_BIST_CACHE_LINE_SIZE      0
#define BM_PCIE_BIST_CACHE_LINE_SIZE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BIST_CACHE_LINE_SIZE(v)   ((((reg32_t) v) << 0) & BM_PCIE_BIST_CACHE_LINE_SIZE)
#else
#define BF_PCIE_BIST_CACHE_LINE_SIZE(v)   (((v) << 0) & BM_PCIE_BIST_CACHE_LINE_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BIST_CACHE_LINE_SIZE(v)   BF_CS1(PCIE_BIST, CACHE_LINE_SIZE, v)
#endif

/*
 * HW_PCIE_BAR0 - Base Address 0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 28;
        unsigned PREF : 1;
        unsigned TYPE : 2;
        unsigned MEM_I_O : 1;

    } B;
} hw_pcie_bar0_t;
#endif

/*
 * constants & macros for entire PCIE_BAR0 register
 */
#define HW_PCIE_BAR0_ADDR      (REGS_PCIE_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR0           (*(volatile hw_pcie_bar0_t *) HW_PCIE_BAR0_ADDR)
#define HW_PCIE_BAR0_RD()      (HW_PCIE_BAR0.U)
#define HW_PCIE_BAR0_WR(v)     (HW_PCIE_BAR0.U = (v))
#define HW_PCIE_BAR0_SET(v)    (HW_PCIE_BAR0_WR(HW_PCIE_BAR0_RD() |  (v)))
#define HW_PCIE_BAR0_CLR(v)    (HW_PCIE_BAR0_WR(HW_PCIE_BAR0_RD() & ~(v)))
#define HW_PCIE_BAR0_TOG(v)    (HW_PCIE_BAR0_WR(HW_PCIE_BAR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR0 bitfields
 */

/* --- Register HW_PCIE_BAR0, field ADDRESS */

#define BP_PCIE_BAR0_ADDRESS      4
#define BM_PCIE_BAR0_ADDRESS      0xfffffff0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR0_ADDRESS(v)   ((((reg32_t) v) << 4) & BM_PCIE_BAR0_ADDRESS)
#else
#define BF_PCIE_BAR0_ADDRESS(v)   (((v) << 4) & BM_PCIE_BAR0_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR0_ADDRESS(v)   BF_CS1(PCIE_BAR0, ADDRESS, v)
#endif

/* --- Register HW_PCIE_BAR0, field PREF */

#define BP_PCIE_BAR0_PREF      3
#define BM_PCIE_BAR0_PREF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR0_PREF(v)   ((((reg32_t) v) << 3) & BM_PCIE_BAR0_PREF)
#else
#define BF_PCIE_BAR0_PREF(v)   (((v) << 3) & BM_PCIE_BAR0_PREF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR0_PREF(v)   BF_CS1(PCIE_BAR0, PREF, v)
#endif

/* --- Register HW_PCIE_BAR0, field TYPE */

#define BP_PCIE_BAR0_TYPE      1
#define BM_PCIE_BAR0_TYPE      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR0_TYPE(v)   ((((reg32_t) v) << 1) & BM_PCIE_BAR0_TYPE)
#else
#define BF_PCIE_BAR0_TYPE(v)   (((v) << 1) & BM_PCIE_BAR0_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR0_TYPE(v)   BF_CS1(PCIE_BAR0, TYPE, v)
#endif

/* --- Register HW_PCIE_BAR0, field MEM_I_O */

#define BP_PCIE_BAR0_MEM_I_O      0
#define BM_PCIE_BAR0_MEM_I_O      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR0_MEM_I_O(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR0_MEM_I_O)
#else
#define BF_PCIE_BAR0_MEM_I_O(v)   (((v) << 0) & BM_PCIE_BAR0_MEM_I_O)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR0_MEM_I_O(v)   BF_CS1(PCIE_BAR0, MEM_I_O, v)
#endif

/*
 * HW_PCIE_BAR1 - Base Address 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 32;

    } B;
} hw_pcie_bar1_t;
#endif

/*
 * constants & macros for entire PCIE_BAR1 register
 */
#define HW_PCIE_BAR1_ADDR      (REGS_PCIE_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR1           (*(volatile hw_pcie_bar1_t *) HW_PCIE_BAR1_ADDR)
#define HW_PCIE_BAR1_RD()      (HW_PCIE_BAR1.U)
#define HW_PCIE_BAR1_WR(v)     (HW_PCIE_BAR1.U = (v))
#define HW_PCIE_BAR1_SET(v)    (HW_PCIE_BAR1_WR(HW_PCIE_BAR1_RD() |  (v)))
#define HW_PCIE_BAR1_CLR(v)    (HW_PCIE_BAR1_WR(HW_PCIE_BAR1_RD() & ~(v)))
#define HW_PCIE_BAR1_TOG(v)    (HW_PCIE_BAR1_WR(HW_PCIE_BAR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR1 bitfields
 */

/* --- Register HW_PCIE_BAR1, field ADDRESS */

#define BP_PCIE_BAR1_ADDRESS      0
#define BM_PCIE_BAR1_ADDRESS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR1_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR1_ADDRESS)
#else
#define BF_PCIE_BAR1_ADDRESS(v)   (((v) << 0) & BM_PCIE_BAR1_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR1_ADDRESS(v)   BF_CS1(PCIE_BAR1, ADDRESS, v)
#endif

/*
 * HW_PCIE_BAR2 - Base Address 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 28;
        unsigned PREF : 1;
        unsigned TYPE : 2;
        unsigned MEM_I_O : 1;

    } B;
} hw_pcie_bar2_t;
#endif

/*
 * constants & macros for entire PCIE_BAR2 register
 */
#define HW_PCIE_BAR2_ADDR      (REGS_PCIE_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR2           (*(volatile hw_pcie_bar2_t *) HW_PCIE_BAR2_ADDR)
#define HW_PCIE_BAR2_RD()      (HW_PCIE_BAR2.U)
#define HW_PCIE_BAR2_WR(v)     (HW_PCIE_BAR2.U = (v))
#define HW_PCIE_BAR2_SET(v)    (HW_PCIE_BAR2_WR(HW_PCIE_BAR2_RD() |  (v)))
#define HW_PCIE_BAR2_CLR(v)    (HW_PCIE_BAR2_WR(HW_PCIE_BAR2_RD() & ~(v)))
#define HW_PCIE_BAR2_TOG(v)    (HW_PCIE_BAR2_WR(HW_PCIE_BAR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR2 bitfields
 */

/* --- Register HW_PCIE_BAR2, field ADDRESS */

#define BP_PCIE_BAR2_ADDRESS      4
#define BM_PCIE_BAR2_ADDRESS      0xfffffff0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR2_ADDRESS(v)   ((((reg32_t) v) << 4) & BM_PCIE_BAR2_ADDRESS)
#else
#define BF_PCIE_BAR2_ADDRESS(v)   (((v) << 4) & BM_PCIE_BAR2_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR2_ADDRESS(v)   BF_CS1(PCIE_BAR2, ADDRESS, v)
#endif

/* --- Register HW_PCIE_BAR2, field PREF */

#define BP_PCIE_BAR2_PREF      3
#define BM_PCIE_BAR2_PREF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR2_PREF(v)   ((((reg32_t) v) << 3) & BM_PCIE_BAR2_PREF)
#else
#define BF_PCIE_BAR2_PREF(v)   (((v) << 3) & BM_PCIE_BAR2_PREF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR2_PREF(v)   BF_CS1(PCIE_BAR2, PREF, v)
#endif

/* --- Register HW_PCIE_BAR2, field TYPE */

#define BP_PCIE_BAR2_TYPE      1
#define BM_PCIE_BAR2_TYPE      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR2_TYPE(v)   ((((reg32_t) v) << 1) & BM_PCIE_BAR2_TYPE)
#else
#define BF_PCIE_BAR2_TYPE(v)   (((v) << 1) & BM_PCIE_BAR2_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR2_TYPE(v)   BF_CS1(PCIE_BAR2, TYPE, v)
#endif

/* --- Register HW_PCIE_BAR2, field MEM_I_O */

#define BP_PCIE_BAR2_MEM_I_O      0
#define BM_PCIE_BAR2_MEM_I_O      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR2_MEM_I_O(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR2_MEM_I_O)
#else
#define BF_PCIE_BAR2_MEM_I_O(v)   (((v) << 0) & BM_PCIE_BAR2_MEM_I_O)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR2_MEM_I_O(v)   BF_CS1(PCIE_BAR2, MEM_I_O, v)
#endif

/*
 * HW_PCIE_BAR3 - Base Address 3
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 32;

    } B;
} hw_pcie_bar3_t;
#endif

/*
 * constants & macros for entire PCIE_BAR3 register
 */
#define HW_PCIE_BAR3_ADDR      (REGS_PCIE_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR3           (*(volatile hw_pcie_bar3_t *) HW_PCIE_BAR3_ADDR)
#define HW_PCIE_BAR3_RD()      (HW_PCIE_BAR3.U)
#define HW_PCIE_BAR3_WR(v)     (HW_PCIE_BAR3.U = (v))
#define HW_PCIE_BAR3_SET(v)    (HW_PCIE_BAR3_WR(HW_PCIE_BAR3_RD() |  (v)))
#define HW_PCIE_BAR3_CLR(v)    (HW_PCIE_BAR3_WR(HW_PCIE_BAR3_RD() & ~(v)))
#define HW_PCIE_BAR3_TOG(v)    (HW_PCIE_BAR3_WR(HW_PCIE_BAR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR3 bitfields
 */

/* --- Register HW_PCIE_BAR3, field ADDRESS */

#define BP_PCIE_BAR3_ADDRESS      0
#define BM_PCIE_BAR3_ADDRESS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR3_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR3_ADDRESS)
#else
#define BF_PCIE_BAR3_ADDRESS(v)   (((v) << 0) & BM_PCIE_BAR3_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR3_ADDRESS(v)   BF_CS1(PCIE_BAR3, ADDRESS, v)
#endif

/*
 * HW_PCIE_BAR4 - Base Address 4
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 28;
        unsigned PREF : 1;
        unsigned TYPE : 2;
        unsigned MEM_I_O : 1;

    } B;
} hw_pcie_bar4_t;
#endif

/*
 * constants & macros for entire PCIE_BAR4 register
 */
#define HW_PCIE_BAR4_ADDR      (REGS_PCIE_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR4           (*(volatile hw_pcie_bar4_t *) HW_PCIE_BAR4_ADDR)
#define HW_PCIE_BAR4_RD()      (HW_PCIE_BAR4.U)
#define HW_PCIE_BAR4_WR(v)     (HW_PCIE_BAR4.U = (v))
#define HW_PCIE_BAR4_SET(v)    (HW_PCIE_BAR4_WR(HW_PCIE_BAR4_RD() |  (v)))
#define HW_PCIE_BAR4_CLR(v)    (HW_PCIE_BAR4_WR(HW_PCIE_BAR4_RD() & ~(v)))
#define HW_PCIE_BAR4_TOG(v)    (HW_PCIE_BAR4_WR(HW_PCIE_BAR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR4 bitfields
 */

/* --- Register HW_PCIE_BAR4, field ADDRESS */

#define BP_PCIE_BAR4_ADDRESS      4
#define BM_PCIE_BAR4_ADDRESS      0xfffffff0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR4_ADDRESS(v)   ((((reg32_t) v) << 4) & BM_PCIE_BAR4_ADDRESS)
#else
#define BF_PCIE_BAR4_ADDRESS(v)   (((v) << 4) & BM_PCIE_BAR4_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR4_ADDRESS(v)   BF_CS1(PCIE_BAR4, ADDRESS, v)
#endif

/* --- Register HW_PCIE_BAR4, field PREF */

#define BP_PCIE_BAR4_PREF      3
#define BM_PCIE_BAR4_PREF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR4_PREF(v)   ((((reg32_t) v) << 3) & BM_PCIE_BAR4_PREF)
#else
#define BF_PCIE_BAR4_PREF(v)   (((v) << 3) & BM_PCIE_BAR4_PREF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR4_PREF(v)   BF_CS1(PCIE_BAR4, PREF, v)
#endif

/* --- Register HW_PCIE_BAR4, field TYPE */

#define BP_PCIE_BAR4_TYPE      1
#define BM_PCIE_BAR4_TYPE      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR4_TYPE(v)   ((((reg32_t) v) << 1) & BM_PCIE_BAR4_TYPE)
#else
#define BF_PCIE_BAR4_TYPE(v)   (((v) << 1) & BM_PCIE_BAR4_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR4_TYPE(v)   BF_CS1(PCIE_BAR4, TYPE, v)
#endif

/* --- Register HW_PCIE_BAR4, field MEM_I_O */

#define BP_PCIE_BAR4_MEM_I_O      0
#define BM_PCIE_BAR4_MEM_I_O      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR4_MEM_I_O(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR4_MEM_I_O)
#else
#define BF_PCIE_BAR4_MEM_I_O(v)   (((v) << 0) & BM_PCIE_BAR4_MEM_I_O)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR4_MEM_I_O(v)   BF_CS1(PCIE_BAR4, MEM_I_O, v)
#endif

/*
 * HW_PCIE_BAR5 - Base Address 5
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 32;

    } B;
} hw_pcie_bar5_t;
#endif

/*
 * constants & macros for entire PCIE_BAR5 register
 */
#define HW_PCIE_BAR5_ADDR      (REGS_PCIE_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_BAR5           (*(volatile hw_pcie_bar5_t *) HW_PCIE_BAR5_ADDR)
#define HW_PCIE_BAR5_RD()      (HW_PCIE_BAR5.U)
#define HW_PCIE_BAR5_WR(v)     (HW_PCIE_BAR5.U = (v))
#define HW_PCIE_BAR5_SET(v)    (HW_PCIE_BAR5_WR(HW_PCIE_BAR5_RD() |  (v)))
#define HW_PCIE_BAR5_CLR(v)    (HW_PCIE_BAR5_WR(HW_PCIE_BAR5_RD() & ~(v)))
#define HW_PCIE_BAR5_TOG(v)    (HW_PCIE_BAR5_WR(HW_PCIE_BAR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_BAR5 bitfields
 */

/* --- Register HW_PCIE_BAR5, field ADDRESS */

#define BP_PCIE_BAR5_ADDRESS      0
#define BM_PCIE_BAR5_ADDRESS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_BAR5_ADDRESS(v)   ((((reg32_t) v) << 0) & BM_PCIE_BAR5_ADDRESS)
#else
#define BF_PCIE_BAR5_ADDRESS(v)   (((v) << 0) & BM_PCIE_BAR5_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_BAR5_ADDRESS(v)   BF_CS1(PCIE_BAR5, ADDRESS, v)
#endif

/*
 * HW_PCIE_MASK0 - BAR 0 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK : 31;
        unsigned ENABLE : 1;

    } B;
} hw_pcie_mask0_t;
#endif

/*
 * constants & macros for entire PCIE_MASK0 register
 */
#define HW_PCIE_MASK0_ADDR      (REGS_PCIE_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK0           (*(volatile hw_pcie_mask0_t *) HW_PCIE_MASK0_ADDR)
#define HW_PCIE_MASK0_RD()      (HW_PCIE_MASK0.U)
#define HW_PCIE_MASK0_WR(v)     (HW_PCIE_MASK0.U = (v))
#define HW_PCIE_MASK0_SET(v)    (HW_PCIE_MASK0_WR(HW_PCIE_MASK0_RD() |  (v)))
#define HW_PCIE_MASK0_CLR(v)    (HW_PCIE_MASK0_WR(HW_PCIE_MASK0_RD() & ~(v)))
#define HW_PCIE_MASK0_TOG(v)    (HW_PCIE_MASK0_WR(HW_PCIE_MASK0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK0 bitfields
 */

/* --- Register HW_PCIE_MASK0, field MASK */

#define BP_PCIE_MASK0_MASK      1
#define BM_PCIE_MASK0_MASK      0xfffffffe

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK0_MASK(v)   ((((reg32_t) v) << 1) & BM_PCIE_MASK0_MASK)
#else
#define BF_PCIE_MASK0_MASK(v)   (((v) << 1) & BM_PCIE_MASK0_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK0_MASK(v)   BF_CS1(PCIE_MASK0, MASK, v)
#endif

/* --- Register HW_PCIE_MASK0, field ENABLE */

#define BP_PCIE_MASK0_ENABLE      0
#define BM_PCIE_MASK0_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK0_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK0_ENABLE)
#else
#define BF_PCIE_MASK0_ENABLE(v)   (((v) << 0) & BM_PCIE_MASK0_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK0_ENABLE(v)   BF_CS1(PCIE_MASK0, ENABLE, v)
#endif

/*
 * HW_PCIE_MASK1 - BAR 1 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK : 32;

    } B;
} hw_pcie_mask1_t;
#endif

/*
 * constants & macros for entire PCIE_MASK1 register
 */
#define HW_PCIE_MASK1_ADDR      (REGS_PCIE_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK1           (*(volatile hw_pcie_mask1_t *) HW_PCIE_MASK1_ADDR)
#define HW_PCIE_MASK1_RD()      (HW_PCIE_MASK1.U)
#define HW_PCIE_MASK1_WR(v)     (HW_PCIE_MASK1.U = (v))
#define HW_PCIE_MASK1_SET(v)    (HW_PCIE_MASK1_WR(HW_PCIE_MASK1_RD() |  (v)))
#define HW_PCIE_MASK1_CLR(v)    (HW_PCIE_MASK1_WR(HW_PCIE_MASK1_RD() & ~(v)))
#define HW_PCIE_MASK1_TOG(v)    (HW_PCIE_MASK1_WR(HW_PCIE_MASK1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK1 bitfields
 */

/* --- Register HW_PCIE_MASK1, field MASK */

#define BP_PCIE_MASK1_MASK      0
#define BM_PCIE_MASK1_MASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK1_MASK(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK1_MASK)
#else
#define BF_PCIE_MASK1_MASK(v)   (((v) << 0) & BM_PCIE_MASK1_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK1_MASK(v)   BF_CS1(PCIE_MASK1, MASK, v)
#endif

/*
 * HW_PCIE_MASK2 - BAR 2 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BAR2_MASK_N : 31;
        unsigned BAR2_ENABLED_N : 1;

    } B;
} hw_pcie_mask2_t;
#endif

/*
 * constants & macros for entire PCIE_MASK2 register
 */
#define HW_PCIE_MASK2_ADDR      (REGS_PCIE_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK2           (*(volatile hw_pcie_mask2_t *) HW_PCIE_MASK2_ADDR)
#define HW_PCIE_MASK2_RD()      (HW_PCIE_MASK2.U)
#define HW_PCIE_MASK2_WR(v)     (HW_PCIE_MASK2.U = (v))
#define HW_PCIE_MASK2_SET(v)    (HW_PCIE_MASK2_WR(HW_PCIE_MASK2_RD() |  (v)))
#define HW_PCIE_MASK2_CLR(v)    (HW_PCIE_MASK2_WR(HW_PCIE_MASK2_RD() & ~(v)))
#define HW_PCIE_MASK2_TOG(v)    (HW_PCIE_MASK2_WR(HW_PCIE_MASK2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK2 bitfields
 */

/* --- Register HW_PCIE_MASK2, field BAR2_MASK_N */

#define BP_PCIE_MASK2_BAR2_MASK_N      1
#define BM_PCIE_MASK2_BAR2_MASK_N      0xfffffffe

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK2_BAR2_MASK_N(v)   ((((reg32_t) v) << 1) & BM_PCIE_MASK2_BAR2_MASK_N)
#else
#define BF_PCIE_MASK2_BAR2_MASK_N(v)   (((v) << 1) & BM_PCIE_MASK2_BAR2_MASK_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK2_BAR2_MASK_N(v)   BF_CS1(PCIE_MASK2, BAR2_MASK_N, v)
#endif

/* --- Register HW_PCIE_MASK2, field BAR2_ENABLED_N */

#define BP_PCIE_MASK2_BAR2_ENABLED_N      0
#define BM_PCIE_MASK2_BAR2_ENABLED_N      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK2_BAR2_ENABLED_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK2_BAR2_ENABLED_N)
#else
#define BF_PCIE_MASK2_BAR2_ENABLED_N(v)   (((v) << 0) & BM_PCIE_MASK2_BAR2_ENABLED_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK2_BAR2_ENABLED_N(v)   BF_CS1(PCIE_MASK2, BAR2_ENABLED_N, v)
#endif

/*
 * HW_PCIE_MASK3 - BAR 3 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK : 32;

    } B;
} hw_pcie_mask3_t;
#endif

/*
 * constants & macros for entire PCIE_MASK3 register
 */
#define HW_PCIE_MASK3_ADDR      (REGS_PCIE_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK3           (*(volatile hw_pcie_mask3_t *) HW_PCIE_MASK3_ADDR)
#define HW_PCIE_MASK3_RD()      (HW_PCIE_MASK3.U)
#define HW_PCIE_MASK3_WR(v)     (HW_PCIE_MASK3.U = (v))
#define HW_PCIE_MASK3_SET(v)    (HW_PCIE_MASK3_WR(HW_PCIE_MASK3_RD() |  (v)))
#define HW_PCIE_MASK3_CLR(v)    (HW_PCIE_MASK3_WR(HW_PCIE_MASK3_RD() & ~(v)))
#define HW_PCIE_MASK3_TOG(v)    (HW_PCIE_MASK3_WR(HW_PCIE_MASK3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK3 bitfields
 */

/* --- Register HW_PCIE_MASK3, field MASK */

#define BP_PCIE_MASK3_MASK      0
#define BM_PCIE_MASK3_MASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK3_MASK(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK3_MASK)
#else
#define BF_PCIE_MASK3_MASK(v)   (((v) << 0) & BM_PCIE_MASK3_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK3_MASK(v)   BF_CS1(PCIE_MASK3, MASK, v)
#endif

/*
 * HW_PCIE_MASK4 - BAR 4 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 31;
        unsigned BAR4_ENABLED_N : 1;

    } B;
} hw_pcie_mask4_t;
#endif

/*
 * constants & macros for entire PCIE_MASK4 register
 */
#define HW_PCIE_MASK4_ADDR      (REGS_PCIE_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK4           (*(volatile hw_pcie_mask4_t *) HW_PCIE_MASK4_ADDR)
#define HW_PCIE_MASK4_RD()      (HW_PCIE_MASK4.U)
#define HW_PCIE_MASK4_WR(v)     (HW_PCIE_MASK4.U = (v))
#define HW_PCIE_MASK4_SET(v)    (HW_PCIE_MASK4_WR(HW_PCIE_MASK4_RD() |  (v)))
#define HW_PCIE_MASK4_CLR(v)    (HW_PCIE_MASK4_WR(HW_PCIE_MASK4_RD() & ~(v)))
#define HW_PCIE_MASK4_TOG(v)    (HW_PCIE_MASK4_WR(HW_PCIE_MASK4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK4 bitfields
 */

/* --- Register HW_PCIE_MASK4, field BAR4_ENABLED_N */

#define BP_PCIE_MASK4_BAR4_ENABLED_N      0
#define BM_PCIE_MASK4_BAR4_ENABLED_N      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK4_BAR4_ENABLED_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK4_BAR4_ENABLED_N)
#else
#define BF_PCIE_MASK4_BAR4_ENABLED_N(v)   (((v) << 0) & BM_PCIE_MASK4_BAR4_ENABLED_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK4_BAR4_ENABLED_N(v)   BF_CS1(PCIE_MASK4, BAR4_ENABLED_N, v)
#endif

/*
 * HW_PCIE_MASK5 - BAR 5 Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK : 32;

    } B;
} hw_pcie_mask5_t;
#endif

/*
 * constants & macros for entire PCIE_MASK5 register
 */
#define HW_PCIE_MASK5_ADDR      (REGS_PCIE_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_MASK5           (*(volatile hw_pcie_mask5_t *) HW_PCIE_MASK5_ADDR)
#define HW_PCIE_MASK5_RD()      (HW_PCIE_MASK5.U)
#define HW_PCIE_MASK5_WR(v)     (HW_PCIE_MASK5.U = (v))
#define HW_PCIE_MASK5_SET(v)    (HW_PCIE_MASK5_WR(HW_PCIE_MASK5_RD() |  (v)))
#define HW_PCIE_MASK5_CLR(v)    (HW_PCIE_MASK5_WR(HW_PCIE_MASK5_RD() & ~(v)))
#define HW_PCIE_MASK5_TOG(v)    (HW_PCIE_MASK5_WR(HW_PCIE_MASK5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_MASK5 bitfields
 */

/* --- Register HW_PCIE_MASK5, field MASK */

#define BP_PCIE_MASK5_MASK      0
#define BM_PCIE_MASK5_MASK      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_MASK5_MASK(v)   ((((reg32_t) v) << 0) & BM_PCIE_MASK5_MASK)
#else
#define BF_PCIE_MASK5_MASK(v)   (((v) << 0) & BM_PCIE_MASK5_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_MASK5_MASK(v)   BF_CS1(PCIE_MASK5, MASK, v)
#endif

/*
 * HW_PCIE_CISP - CardBus CIS Pointer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;
        unsigned CARDBUS_CIS_PTR_N : 32;

    } B;
} hw_pcie_cisp_t;
#endif

/*
 * constants & macros for entire PCIE_CISP register
 */
#define HW_PCIE_CISP_ADDR      (REGS_PCIE_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_CISP           (*(volatile hw_pcie_cisp_t *) HW_PCIE_CISP_ADDR)
#define HW_PCIE_CISP_RD()      (HW_PCIE_CISP.U)
#define HW_PCIE_CISP_WR(v)     (HW_PCIE_CISP.U = (v))
#define HW_PCIE_CISP_SET(v)    (HW_PCIE_CISP_WR(HW_PCIE_CISP_RD() |  (v)))
#define HW_PCIE_CISP_CLR(v)    (HW_PCIE_CISP_WR(HW_PCIE_CISP_RD() & ~(v)))
#define HW_PCIE_CISP_TOG(v)    (HW_PCIE_CISP_WR(HW_PCIE_CISP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_CISP bitfields
 */

/* --- Register HW_PCIE_CISP, field CARDBUS_CIS_PTR_N */

#define BP_PCIE_CISP_CARDBUS_CIS_PTR_N      0
#define BM_PCIE_CISP_CARDBUS_CIS_PTR_N      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CISP_CARDBUS_CIS_PTR_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_CISP_CARDBUS_CIS_PTR_N)
#else
#define BF_PCIE_CISP_CARDBUS_CIS_PTR_N(v)   (((v) << 0) & BM_PCIE_CISP_CARDBUS_CIS_PTR_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CISP_CARDBUS_CIS_PTR_N(v)   BF_CS1(PCIE_CISP, CARDBUS_CIS_PTR_N, v)
#endif

/*
 * HW_PCIE_SSID - Subsystem ID and Subsystem Vendor ID Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;
        unsigned SUBSYS_DEV_ID_N : 16;
        unsigned SUBSYS_VENDOR_ID_N : 16;

    } B;
} hw_pcie_ssid_t;
#endif

/*
 * constants & macros for entire PCIE_SSID register
 */
#define HW_PCIE_SSID_ADDR      (REGS_PCIE_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_SSID           (*(volatile hw_pcie_ssid_t *) HW_PCIE_SSID_ADDR)
#define HW_PCIE_SSID_RD()      (HW_PCIE_SSID.U)
#define HW_PCIE_SSID_WR(v)     (HW_PCIE_SSID.U = (v))
#define HW_PCIE_SSID_SET(v)    (HW_PCIE_SSID_WR(HW_PCIE_SSID_RD() |  (v)))
#define HW_PCIE_SSID_CLR(v)    (HW_PCIE_SSID_WR(HW_PCIE_SSID_RD() & ~(v)))
#define HW_PCIE_SSID_TOG(v)    (HW_PCIE_SSID_WR(HW_PCIE_SSID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_SSID bitfields
 */

/* --- Register HW_PCIE_SSID, field SUBSYS_DEV_ID_N */

#define BP_PCIE_SSID_SUBSYS_DEV_ID_N      16
#define BM_PCIE_SSID_SUBSYS_DEV_ID_N      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SSID_SUBSYS_DEV_ID_N(v)   ((((reg32_t) v) << 16) & BM_PCIE_SSID_SUBSYS_DEV_ID_N)
#else
#define BF_PCIE_SSID_SUBSYS_DEV_ID_N(v)   (((v) << 16) & BM_PCIE_SSID_SUBSYS_DEV_ID_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SSID_SUBSYS_DEV_ID_N(v)   BF_CS1(PCIE_SSID, SUBSYS_DEV_ID_N, v)
#endif

/* --- Register HW_PCIE_SSID, field SUBSYS_VENDOR_ID_N */

#define BP_PCIE_SSID_SUBSYS_VENDOR_ID_N      0
#define BM_PCIE_SSID_SUBSYS_VENDOR_ID_N      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SSID_SUBSYS_VENDOR_ID_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_SSID_SUBSYS_VENDOR_ID_N)
#else
#define BF_PCIE_SSID_SUBSYS_VENDOR_ID_N(v)   (((v) << 0) & BM_PCIE_SSID_SUBSYS_VENDOR_ID_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SSID_SUBSYS_VENDOR_ID_N(v)   BF_CS1(PCIE_SSID, SUBSYS_VENDOR_ID_N, v)
#endif

/*
 * HW_PCIE_EROMBAR - Expansion ROM Base Address Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADDRESS : 21;
        unsigned RESERVED0 : 10;
        unsigned ENABLE : 1;

    } B;
} hw_pcie_erombar_t;
#endif

/*
 * constants & macros for entire PCIE_EROMBAR register
 */
#define HW_PCIE_EROMBAR_ADDR      (REGS_PCIE_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_EROMBAR           (*(volatile hw_pcie_erombar_t *) HW_PCIE_EROMBAR_ADDR)
#define HW_PCIE_EROMBAR_RD()      (HW_PCIE_EROMBAR.U)
#define HW_PCIE_EROMBAR_WR(v)     (HW_PCIE_EROMBAR.U = (v))
#define HW_PCIE_EROMBAR_SET(v)    (HW_PCIE_EROMBAR_WR(HW_PCIE_EROMBAR_RD() |  (v)))
#define HW_PCIE_EROMBAR_CLR(v)    (HW_PCIE_EROMBAR_WR(HW_PCIE_EROMBAR_RD() & ~(v)))
#define HW_PCIE_EROMBAR_TOG(v)    (HW_PCIE_EROMBAR_WR(HW_PCIE_EROMBAR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_EROMBAR bitfields
 */

/* --- Register HW_PCIE_EROMBAR, field ADDRESS */

#define BP_PCIE_EROMBAR_ADDRESS      11
#define BM_PCIE_EROMBAR_ADDRESS      0xfffff800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_EROMBAR_ADDRESS(v)   ((((reg32_t) v) << 11) & BM_PCIE_EROMBAR_ADDRESS)
#else
#define BF_PCIE_EROMBAR_ADDRESS(v)   (((v) << 11) & BM_PCIE_EROMBAR_ADDRESS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_EROMBAR_ADDRESS(v)   BF_CS1(PCIE_EROMBAR, ADDRESS, v)
#endif

/* --- Register HW_PCIE_EROMBAR, field ENABLE */

#define BP_PCIE_EROMBAR_ENABLE      0
#define BM_PCIE_EROMBAR_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_EROMBAR_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_EROMBAR_ENABLE)
#else
#define BF_PCIE_EROMBAR_ENABLE(v)   (((v) << 0) & BM_PCIE_EROMBAR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_EROMBAR_ENABLE(v)   BF_CS1(PCIE_EROMBAR, ENABLE, v)
#endif

/*
 * HW_PCIE_EROMMASK - Expansion ROM BAR Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ROM_MASK_N : 31;
        unsigned ROM_BAR_ENABLED_N : 1;

    } B;
} hw_pcie_erommask_t;
#endif

/*
 * constants & macros for entire PCIE_EROMMASK register
 */
#define HW_PCIE_EROMMASK_ADDR      (REGS_PCIE_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_EROMMASK           (*(volatile hw_pcie_erommask_t *) HW_PCIE_EROMMASK_ADDR)
#define HW_PCIE_EROMMASK_RD()      (HW_PCIE_EROMMASK.U)
#define HW_PCIE_EROMMASK_WR(v)     (HW_PCIE_EROMMASK.U = (v))
#define HW_PCIE_EROMMASK_SET(v)    (HW_PCIE_EROMMASK_WR(HW_PCIE_EROMMASK_RD() |  (v)))
#define HW_PCIE_EROMMASK_CLR(v)    (HW_PCIE_EROMMASK_WR(HW_PCIE_EROMMASK_RD() & ~(v)))
#define HW_PCIE_EROMMASK_TOG(v)    (HW_PCIE_EROMMASK_WR(HW_PCIE_EROMMASK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_EROMMASK bitfields
 */

/* --- Register HW_PCIE_EROMMASK, field ROM_MASK_N */

#define BP_PCIE_EROMMASK_ROM_MASK_N      1
#define BM_PCIE_EROMMASK_ROM_MASK_N      0xfffffffe

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_EROMMASK_ROM_MASK_N(v)   ((((reg32_t) v) << 1) & BM_PCIE_EROMMASK_ROM_MASK_N)
#else
#define BF_PCIE_EROMMASK_ROM_MASK_N(v)   (((v) << 1) & BM_PCIE_EROMMASK_ROM_MASK_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_EROMMASK_ROM_MASK_N(v)   BF_CS1(PCIE_EROMMASK, ROM_MASK_N, v)
#endif

/* --- Register HW_PCIE_EROMMASK, field ROM_BAR_ENABLED_N */

#define BP_PCIE_EROMMASK_ROM_BAR_ENABLED_N      0
#define BM_PCIE_EROMMASK_ROM_BAR_ENABLED_N      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_EROMMASK_ROM_BAR_ENABLED_N(v)   ((((reg32_t) v) << 0) & BM_PCIE_EROMMASK_ROM_BAR_ENABLED_N)
#else
#define BF_PCIE_EROMMASK_ROM_BAR_ENABLED_N(v)   (((v) << 0) & BM_PCIE_EROMMASK_ROM_BAR_ENABLED_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_EROMMASK_ROM_BAR_ENABLED_N(v)   BF_CS1(PCIE_EROMMASK, ROM_BAR_ENABLED_N, v)
#endif

/*
 * HW_PCIE_CAPPR - Capability Pointer Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 24;
        unsigned CFG_NEXT_PTR : 8;

    } B;
} hw_pcie_cappr_t;
#endif

/*
 * constants & macros for entire PCIE_CAPPR register
 */
#define HW_PCIE_CAPPR_ADDR      (REGS_PCIE_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_CAPPR           (*(volatile hw_pcie_cappr_t *) HW_PCIE_CAPPR_ADDR)
#define HW_PCIE_CAPPR_RD()      (HW_PCIE_CAPPR.U)
#define HW_PCIE_CAPPR_WR(v)     (HW_PCIE_CAPPR.U = (v))
#define HW_PCIE_CAPPR_SET(v)    (HW_PCIE_CAPPR_WR(HW_PCIE_CAPPR_RD() |  (v)))
#define HW_PCIE_CAPPR_CLR(v)    (HW_PCIE_CAPPR_WR(HW_PCIE_CAPPR_RD() & ~(v)))
#define HW_PCIE_CAPPR_TOG(v)    (HW_PCIE_CAPPR_WR(HW_PCIE_CAPPR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_CAPPR bitfields
 */

/* --- Register HW_PCIE_CAPPR, field CFG_NEXT_PTR */

#define BP_PCIE_CAPPR_CFG_NEXT_PTR      0
#define BM_PCIE_CAPPR_CFG_NEXT_PTR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CAPPR_CFG_NEXT_PTR(v)   ((((reg32_t) v) << 0) & BM_PCIE_CAPPR_CFG_NEXT_PTR)
#else
#define BF_PCIE_CAPPR_CFG_NEXT_PTR(v)   (((v) << 0) & BM_PCIE_CAPPR_CFG_NEXT_PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CAPPR_CFG_NEXT_PTR(v)   BF_CS1(PCIE_CAPPR, CFG_NEXT_PTR, v)
#endif

/*
 * HW_PCIE_ILR - Interrupt Line and Pin Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16;
        unsigned INT_PIN_MAPPING_N : 8;
        unsigned INTERRUPT_LINE : 8;

    } B;
} hw_pcie_ilr_t;
#endif

/*
 * constants & macros for entire PCIE_ILR register
 */
#define HW_PCIE_ILR_ADDR      (REGS_PCIE_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_ILR           (*(volatile hw_pcie_ilr_t *) HW_PCIE_ILR_ADDR)
#define HW_PCIE_ILR_RD()      (HW_PCIE_ILR.U)
#define HW_PCIE_ILR_WR(v)     (HW_PCIE_ILR.U = (v))
#define HW_PCIE_ILR_SET(v)    (HW_PCIE_ILR_WR(HW_PCIE_ILR_RD() |  (v)))
#define HW_PCIE_ILR_CLR(v)    (HW_PCIE_ILR_WR(HW_PCIE_ILR_RD() & ~(v)))
#define HW_PCIE_ILR_TOG(v)    (HW_PCIE_ILR_WR(HW_PCIE_ILR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_ILR bitfields
 */

/* --- Register HW_PCIE_ILR, field INT_PIN_MAPPING_N */

#define BP_PCIE_ILR_INT_PIN_MAPPING_N      8
#define BM_PCIE_ILR_INT_PIN_MAPPING_N      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ILR_INT_PIN_MAPPING_N(v)   ((((reg32_t) v) << 8) & BM_PCIE_ILR_INT_PIN_MAPPING_N)
#else
#define BF_PCIE_ILR_INT_PIN_MAPPING_N(v)   (((v) << 8) & BM_PCIE_ILR_INT_PIN_MAPPING_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ILR_INT_PIN_MAPPING_N(v)   BF_CS1(PCIE_ILR, INT_PIN_MAPPING_N, v)
#endif

/* --- Register HW_PCIE_ILR, field INTERRUPT_LINE */

#define BP_PCIE_ILR_INTERRUPT_LINE      0
#define BM_PCIE_ILR_INTERRUPT_LINE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ILR_INTERRUPT_LINE(v)   ((((reg32_t) v) << 0) & BM_PCIE_ILR_INTERRUPT_LINE)
#else
#define BF_PCIE_ILR_INTERRUPT_LINE(v)   (((v) << 0) & BM_PCIE_ILR_INTERRUPT_LINE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ILR_INTERRUPT_LINE(v)   BF_CS1(PCIE_ILR, INTERRUPT_LINE, v)
#endif

/*
 * HW_PCIE_PMCR - Power Management Capability Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PME_SUPPORT : 5;
        unsigned D2_SUPPORT : 1;
        unsigned D1_SUPPORT : 1;
        unsigned AUX_CURRENT : 3;
        unsigned DSI : 1;
        unsigned RESERVED0 : 1;
        unsigned PME_CLOCK : 1;
        unsigned POWER_MANAGEMENT_SPECIFICATION_VERSION : 3;
        unsigned NEXT_CAPABILITY_POINTER : 8;
        unsigned POWER_MANAGEMENT_CAPABILITY_ID : 8;

    } B;
} hw_pcie_pmcr_t;
#endif

/*
 * constants & macros for entire PCIE_PMCR register
 */
#define HW_PCIE_PMCR_ADDR      (REGS_PCIE_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PMCR           (*(volatile hw_pcie_pmcr_t *) HW_PCIE_PMCR_ADDR)
#define HW_PCIE_PMCR_RD()      (HW_PCIE_PMCR.U)
#define HW_PCIE_PMCR_WR(v)     (HW_PCIE_PMCR.U = (v))
#define HW_PCIE_PMCR_SET(v)    (HW_PCIE_PMCR_WR(HW_PCIE_PMCR_RD() |  (v)))
#define HW_PCIE_PMCR_CLR(v)    (HW_PCIE_PMCR_WR(HW_PCIE_PMCR_RD() & ~(v)))
#define HW_PCIE_PMCR_TOG(v)    (HW_PCIE_PMCR_WR(HW_PCIE_PMCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_PMCR bitfields
 */

/* --- Register HW_PCIE_PMCR, field PME_SUPPORT */

#define BP_PCIE_PMCR_PME_SUPPORT      27
#define BM_PCIE_PMCR_PME_SUPPORT      0xf8000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_PME_SUPPORT(v)   ((((reg32_t) v) << 27) & BM_PCIE_PMCR_PME_SUPPORT)
#else
#define BF_PCIE_PMCR_PME_SUPPORT(v)   (((v) << 27) & BM_PCIE_PMCR_PME_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_PME_SUPPORT(v)   BF_CS1(PCIE_PMCR, PME_SUPPORT, v)
#endif

/* --- Register HW_PCIE_PMCR, field D2_SUPPORT */

#define BP_PCIE_PMCR_D2_SUPPORT      26
#define BM_PCIE_PMCR_D2_SUPPORT      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_D2_SUPPORT(v)   ((((reg32_t) v) << 26) & BM_PCIE_PMCR_D2_SUPPORT)
#else
#define BF_PCIE_PMCR_D2_SUPPORT(v)   (((v) << 26) & BM_PCIE_PMCR_D2_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_D2_SUPPORT(v)   BF_CS1(PCIE_PMCR, D2_SUPPORT, v)
#endif

/* --- Register HW_PCIE_PMCR, field D1_SUPPORT */

#define BP_PCIE_PMCR_D1_SUPPORT      25
#define BM_PCIE_PMCR_D1_SUPPORT      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_D1_SUPPORT(v)   ((((reg32_t) v) << 25) & BM_PCIE_PMCR_D1_SUPPORT)
#else
#define BF_PCIE_PMCR_D1_SUPPORT(v)   (((v) << 25) & BM_PCIE_PMCR_D1_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_D1_SUPPORT(v)   BF_CS1(PCIE_PMCR, D1_SUPPORT, v)
#endif

/* --- Register HW_PCIE_PMCR, field AUX_CURRENT */

#define BP_PCIE_PMCR_AUX_CURRENT      22
#define BM_PCIE_PMCR_AUX_CURRENT      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_AUX_CURRENT(v)   ((((reg32_t) v) << 22) & BM_PCIE_PMCR_AUX_CURRENT)
#else
#define BF_PCIE_PMCR_AUX_CURRENT(v)   (((v) << 22) & BM_PCIE_PMCR_AUX_CURRENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_AUX_CURRENT(v)   BF_CS1(PCIE_PMCR, AUX_CURRENT, v)
#endif

/* --- Register HW_PCIE_PMCR, field DSI */

#define BP_PCIE_PMCR_DSI      21
#define BM_PCIE_PMCR_DSI      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_DSI(v)   ((((reg32_t) v) << 21) & BM_PCIE_PMCR_DSI)
#else
#define BF_PCIE_PMCR_DSI(v)   (((v) << 21) & BM_PCIE_PMCR_DSI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_DSI(v)   BF_CS1(PCIE_PMCR, DSI, v)
#endif

/* --- Register HW_PCIE_PMCR, field PME_CLOCK */

#define BP_PCIE_PMCR_PME_CLOCK      19
#define BM_PCIE_PMCR_PME_CLOCK      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_PME_CLOCK(v)   ((((reg32_t) v) << 19) & BM_PCIE_PMCR_PME_CLOCK)
#else
#define BF_PCIE_PMCR_PME_CLOCK(v)   (((v) << 19) & BM_PCIE_PMCR_PME_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_PME_CLOCK(v)   BF_CS1(PCIE_PMCR, PME_CLOCK, v)
#endif

/* --- Register HW_PCIE_PMCR, field POWER_MANAGEMENT_SPECIFICATION_VERSION */

#define BP_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION      16
#define BM_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION(v)   ((((reg32_t) v) << 16) & BM_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION)
#else
#define BF_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION(v)   (((v) << 16) & BM_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION(v)   BF_CS1(PCIE_PMCR, POWER_MANAGEMENT_SPECIFICATION_VERSION, v)
#endif

/* --- Register HW_PCIE_PMCR, field NEXT_CAPABILITY_POINTER */

#define BP_PCIE_PMCR_NEXT_CAPABILITY_POINTER      8
#define BM_PCIE_PMCR_NEXT_CAPABILITY_POINTER      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_NEXT_CAPABILITY_POINTER(v)   ((((reg32_t) v) << 8) & BM_PCIE_PMCR_NEXT_CAPABILITY_POINTER)
#else
#define BF_PCIE_PMCR_NEXT_CAPABILITY_POINTER(v)   (((v) << 8) & BM_PCIE_PMCR_NEXT_CAPABILITY_POINTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_NEXT_CAPABILITY_POINTER(v)   BF_CS1(PCIE_PMCR, NEXT_CAPABILITY_POINTER, v)
#endif

/* --- Register HW_PCIE_PMCR, field POWER_MANAGEMENT_CAPABILITY_ID */

#define BP_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID      0
#define BM_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID(v)   ((((reg32_t) v) << 0) & BM_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID)
#else
#define BF_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID(v)   (((v) << 0) & BM_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID(v)   BF_CS1(PCIE_PMCR, POWER_MANAGEMENT_CAPABILITY_ID, v)
#endif

/*
 * HW_PCIE_PMCSR - Power Management Control and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATA_REGISTER_FOR_ADDITIONAL_INFORMATION : 8;
        unsigned BUS_POWER_CLOCK_CONTROL_ENABLE : 1;
        unsigned B2_B3_SUPPORT : 1;
        unsigned RESERVED0 : 6;
        unsigned PME_STATUS : 1;
        unsigned DATA_SCALE : 2;
        unsigned DATA_SELECT : 4;
        unsigned PME_ENABLE : 1;
        unsigned RESERVED1 : 4;
        unsigned NO_SOFT_RESET : 1;
        unsigned RESERVED2 : 1;
        unsigned POWER_STATE : 2;

    } B;
} hw_pcie_pmcsr_t;
#endif

/*
 * constants & macros for entire PCIE_PMCSR register
 */
#define HW_PCIE_PMCSR_ADDR      (REGS_PCIE_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PMCSR           (*(volatile hw_pcie_pmcsr_t *) HW_PCIE_PMCSR_ADDR)
#define HW_PCIE_PMCSR_RD()      (HW_PCIE_PMCSR.U)
#define HW_PCIE_PMCSR_WR(v)     (HW_PCIE_PMCSR.U = (v))
#define HW_PCIE_PMCSR_SET(v)    (HW_PCIE_PMCSR_WR(HW_PCIE_PMCSR_RD() |  (v)))
#define HW_PCIE_PMCSR_CLR(v)    (HW_PCIE_PMCSR_WR(HW_PCIE_PMCSR_RD() & ~(v)))
#define HW_PCIE_PMCSR_TOG(v)    (HW_PCIE_PMCSR_WR(HW_PCIE_PMCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_PMCSR bitfields
 */

/* --- Register HW_PCIE_PMCSR, field DATA_REGISTER_FOR_ADDITIONAL_INFORMATION */

#define BP_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION      24
#define BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)   ((((reg32_t) v) << 24) & BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION)
#else
#define BF_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)   (((v) << 24) & BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)   BF_CS1(PCIE_PMCSR, DATA_REGISTER_FOR_ADDITIONAL_INFORMATION, v)
#endif

/* --- Register HW_PCIE_PMCSR, field BUS_POWER_CLOCK_CONTROL_ENABLE */

#define BP_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE      23
#define BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)   ((((reg32_t) v) << 23) & BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE)
#else
#define BF_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)   (((v) << 23) & BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)   BF_CS1(PCIE_PMCSR, BUS_POWER_CLOCK_CONTROL_ENABLE, v)
#endif

/* --- Register HW_PCIE_PMCSR, field B2_B3_SUPPORT */

#define BP_PCIE_PMCSR_B2_B3_SUPPORT      22
#define BM_PCIE_PMCSR_B2_B3_SUPPORT      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_B2_B3_SUPPORT(v)   ((((reg32_t) v) << 22) & BM_PCIE_PMCSR_B2_B3_SUPPORT)
#else
#define BF_PCIE_PMCSR_B2_B3_SUPPORT(v)   (((v) << 22) & BM_PCIE_PMCSR_B2_B3_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_B2_B3_SUPPORT(v)   BF_CS1(PCIE_PMCSR, B2_B3_SUPPORT, v)
#endif

/* --- Register HW_PCIE_PMCSR, field PME_STATUS */

#define BP_PCIE_PMCSR_PME_STATUS      15
#define BM_PCIE_PMCSR_PME_STATUS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_PME_STATUS(v)   ((((reg32_t) v) << 15) & BM_PCIE_PMCSR_PME_STATUS)
#else
#define BF_PCIE_PMCSR_PME_STATUS(v)   (((v) << 15) & BM_PCIE_PMCSR_PME_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_PME_STATUS(v)   BF_CS1(PCIE_PMCSR, PME_STATUS, v)
#endif

/* --- Register HW_PCIE_PMCSR, field DATA_SCALE */

#define BP_PCIE_PMCSR_DATA_SCALE      13
#define BM_PCIE_PMCSR_DATA_SCALE      0x00006000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_DATA_SCALE(v)   ((((reg32_t) v) << 13) & BM_PCIE_PMCSR_DATA_SCALE)
#else
#define BF_PCIE_PMCSR_DATA_SCALE(v)   (((v) << 13) & BM_PCIE_PMCSR_DATA_SCALE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_DATA_SCALE(v)   BF_CS1(PCIE_PMCSR, DATA_SCALE, v)
#endif

/* --- Register HW_PCIE_PMCSR, field DATA_SELECT */

#define BP_PCIE_PMCSR_DATA_SELECT      9
#define BM_PCIE_PMCSR_DATA_SELECT      0x00001e00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_DATA_SELECT(v)   ((((reg32_t) v) << 9) & BM_PCIE_PMCSR_DATA_SELECT)
#else
#define BF_PCIE_PMCSR_DATA_SELECT(v)   (((v) << 9) & BM_PCIE_PMCSR_DATA_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_DATA_SELECT(v)   BF_CS1(PCIE_PMCSR, DATA_SELECT, v)
#endif

/* --- Register HW_PCIE_PMCSR, field PME_ENABLE */

#define BP_PCIE_PMCSR_PME_ENABLE      8
#define BM_PCIE_PMCSR_PME_ENABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_PME_ENABLE(v)   ((((reg32_t) v) << 8) & BM_PCIE_PMCSR_PME_ENABLE)
#else
#define BF_PCIE_PMCSR_PME_ENABLE(v)   (((v) << 8) & BM_PCIE_PMCSR_PME_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_PME_ENABLE(v)   BF_CS1(PCIE_PMCSR, PME_ENABLE, v)
#endif

/* --- Register HW_PCIE_PMCSR, field NO_SOFT_RESET */

#define BP_PCIE_PMCSR_NO_SOFT_RESET      3
#define BM_PCIE_PMCSR_NO_SOFT_RESET      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_NO_SOFT_RESET(v)   ((((reg32_t) v) << 3) & BM_PCIE_PMCSR_NO_SOFT_RESET)
#else
#define BF_PCIE_PMCSR_NO_SOFT_RESET(v)   (((v) << 3) & BM_PCIE_PMCSR_NO_SOFT_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_NO_SOFT_RESET(v)   BF_CS1(PCIE_PMCSR, NO_SOFT_RESET, v)
#endif

/* --- Register HW_PCIE_PMCSR, field POWER_STATE */

#define BP_PCIE_PMCSR_POWER_STATE      0
#define BM_PCIE_PMCSR_POWER_STATE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PMCSR_POWER_STATE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PMCSR_POWER_STATE)
#else
#define BF_PCIE_PMCSR_POWER_STATE(v)   (((v) << 0) & BM_PCIE_PMCSR_POWER_STATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PMCSR_POWER_STATE(v)   BF_CS1(PCIE_PMCSR, POWER_STATE, v)
#endif

/*
 * HW_PCIE_AER - AER Capability Header
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NEXT_CAPABILITY_OFFSET : 12;
        unsigned CAPABILITY_VERSION : 4;
        unsigned PCI_EXPRESS_EXTENDED_CAPABILITY_ID : 16;

    } B;
} hw_pcie_aer_t;
#endif

/*
 * constants & macros for entire PCIE_AER register
 */
#define HW_PCIE_AER_ADDR      (REGS_PCIE_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_AER           (*(volatile hw_pcie_aer_t *) HW_PCIE_AER_ADDR)
#define HW_PCIE_AER_RD()      (HW_PCIE_AER.U)
#define HW_PCIE_AER_WR(v)     (HW_PCIE_AER.U = (v))
#define HW_PCIE_AER_SET(v)    (HW_PCIE_AER_WR(HW_PCIE_AER_RD() |  (v)))
#define HW_PCIE_AER_CLR(v)    (HW_PCIE_AER_WR(HW_PCIE_AER_RD() & ~(v)))
#define HW_PCIE_AER_TOG(v)    (HW_PCIE_AER_WR(HW_PCIE_AER_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_AER bitfields
 */

/* --- Register HW_PCIE_AER, field NEXT_CAPABILITY_OFFSET */

#define BP_PCIE_AER_NEXT_CAPABILITY_OFFSET      20
#define BM_PCIE_AER_NEXT_CAPABILITY_OFFSET      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)   ((((reg32_t) v) << 20) & BM_PCIE_AER_NEXT_CAPABILITY_OFFSET)
#else
#define BF_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)   (((v) << 20) & BM_PCIE_AER_NEXT_CAPABILITY_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)   BF_CS1(PCIE_AER, NEXT_CAPABILITY_OFFSET, v)
#endif

/* --- Register HW_PCIE_AER, field CAPABILITY_VERSION */

#define BP_PCIE_AER_CAPABILITY_VERSION      16
#define BM_PCIE_AER_CAPABILITY_VERSION      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_AER_CAPABILITY_VERSION(v)   ((((reg32_t) v) << 16) & BM_PCIE_AER_CAPABILITY_VERSION)
#else
#define BF_PCIE_AER_CAPABILITY_VERSION(v)   (((v) << 16) & BM_PCIE_AER_CAPABILITY_VERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_AER_CAPABILITY_VERSION(v)   BF_CS1(PCIE_AER, CAPABILITY_VERSION, v)
#endif

/* --- Register HW_PCIE_AER, field PCI_EXPRESS_EXTENDED_CAPABILITY_ID */

#define BP_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID      0
#define BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)   ((((reg32_t) v) << 0) & BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID)
#else
#define BF_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)   (((v) << 0) & BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)   BF_CS1(PCIE_AER, PCI_EXPRESS_EXTENDED_CAPABILITY_ID, v)
#endif

/*
 * HW_PCIE_CIDR - PCI Express Capability ID Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2;
        unsigned INTERRUPT_MESSAGE_NUMBER : 5;
        unsigned SLOT_IMPLEMENTED : 1;
        unsigned DEVICE_PORT_TYPE : 4;
        unsigned PCI_EXPRESS_CAPABILITY_VERSION : 4;
        unsigned NEXT_CAPABILITY_POINTER : 8;
        unsigned PCI_EXPRESS_CAPABILITY_ID : 8;

    } B;
} hw_pcie_cidr_t;
#endif

/*
 * constants & macros for entire PCIE_CIDR register
 */
#define HW_PCIE_CIDR_ADDR      (REGS_PCIE_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_CIDR           (*(volatile hw_pcie_cidr_t *) HW_PCIE_CIDR_ADDR)
#define HW_PCIE_CIDR_RD()      (HW_PCIE_CIDR.U)
#define HW_PCIE_CIDR_WR(v)     (HW_PCIE_CIDR.U = (v))
#define HW_PCIE_CIDR_SET(v)    (HW_PCIE_CIDR_WR(HW_PCIE_CIDR_RD() |  (v)))
#define HW_PCIE_CIDR_CLR(v)    (HW_PCIE_CIDR_WR(HW_PCIE_CIDR_RD() & ~(v)))
#define HW_PCIE_CIDR_TOG(v)    (HW_PCIE_CIDR_WR(HW_PCIE_CIDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_CIDR bitfields
 */

/* --- Register HW_PCIE_CIDR, field INTERRUPT_MESSAGE_NUMBER */

#define BP_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER      25
#define BM_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER      0x3e000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER(v)   ((((reg32_t) v) << 25) & BM_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER)
#else
#define BF_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER(v)   (((v) << 25) & BM_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER(v)   BF_CS1(PCIE_CIDR, INTERRUPT_MESSAGE_NUMBER, v)
#endif

/* --- Register HW_PCIE_CIDR, field SLOT_IMPLEMENTED */

#define BP_PCIE_CIDR_SLOT_IMPLEMENTED      24
#define BM_PCIE_CIDR_SLOT_IMPLEMENTED      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_SLOT_IMPLEMENTED(v)   ((((reg32_t) v) << 24) & BM_PCIE_CIDR_SLOT_IMPLEMENTED)
#else
#define BF_PCIE_CIDR_SLOT_IMPLEMENTED(v)   (((v) << 24) & BM_PCIE_CIDR_SLOT_IMPLEMENTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_SLOT_IMPLEMENTED(v)   BF_CS1(PCIE_CIDR, SLOT_IMPLEMENTED, v)
#endif

/* --- Register HW_PCIE_CIDR, field DEVICE_PORT_TYPE */

#define BP_PCIE_CIDR_DEVICE_PORT_TYPE      20
#define BM_PCIE_CIDR_DEVICE_PORT_TYPE      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_DEVICE_PORT_TYPE(v)   ((((reg32_t) v) << 20) & BM_PCIE_CIDR_DEVICE_PORT_TYPE)
#else
#define BF_PCIE_CIDR_DEVICE_PORT_TYPE(v)   (((v) << 20) & BM_PCIE_CIDR_DEVICE_PORT_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_DEVICE_PORT_TYPE(v)   BF_CS1(PCIE_CIDR, DEVICE_PORT_TYPE, v)
#endif

/* --- Register HW_PCIE_CIDR, field PCI_EXPRESS_CAPABILITY_VERSION */

#define BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION      16
#define BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION(v)   ((((reg32_t) v) << 16) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION)
#else
#define BF_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION(v)   (((v) << 16) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION(v)   BF_CS1(PCIE_CIDR, PCI_EXPRESS_CAPABILITY_VERSION, v)
#endif

/* --- Register HW_PCIE_CIDR, field NEXT_CAPABILITY_POINTER */

#define BP_PCIE_CIDR_NEXT_CAPABILITY_POINTER      8
#define BM_PCIE_CIDR_NEXT_CAPABILITY_POINTER      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_NEXT_CAPABILITY_POINTER(v)   ((((reg32_t) v) << 8) & BM_PCIE_CIDR_NEXT_CAPABILITY_POINTER)
#else
#define BF_PCIE_CIDR_NEXT_CAPABILITY_POINTER(v)   (((v) << 8) & BM_PCIE_CIDR_NEXT_CAPABILITY_POINTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_NEXT_CAPABILITY_POINTER(v)   BF_CS1(PCIE_CIDR, NEXT_CAPABILITY_POINTER, v)
#endif

/* --- Register HW_PCIE_CIDR, field PCI_EXPRESS_CAPABILITY_ID */

#define BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID      0
#define BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID(v)   ((((reg32_t) v) << 0) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID)
#else
#define BF_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID(v)   (((v) << 0) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID(v)   BF_CS1(PCIE_CIDR, PCI_EXPRESS_CAPABILITY_ID, v)
#endif

/*
 * HW_PCIE_DCR - Device Capabilities Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4;
        unsigned CAPTURED_SLOT_POWER_LIMIT_SCALE : 2;
        unsigned CAPTURED_SLOT_POWER_LIMIT_VALUE : 8;
        unsigned RESERVED1 : 2;
        unsigned ROLE : 1;
        unsigned RESERVED2 : 1;
        unsigned RESERVED3 : 1;
        unsigned RESERVED4 : 1;
        unsigned ENDPOINT_L1_ACCEPTABLE_LATENCY : 3;
        unsigned ENDPOINT_L0S_ACCEPTABLE_LATENCY : 3;
        unsigned EXTENDED_TAG_FIELD_SUPPORTED : 1;
        unsigned PHANTOM_FUNCTION_SUPPORTED : 2;
        unsigned MAX_PAYLOAD_SIZE_SUPPORTED : 3;

    } B;
} hw_pcie_dcr_t;
#endif

/*
 * constants & macros for entire PCIE_DCR register
 */
#define HW_PCIE_DCR_ADDR      (REGS_PCIE_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_DCR           (*(volatile hw_pcie_dcr_t *) HW_PCIE_DCR_ADDR)
#define HW_PCIE_DCR_RD()      (HW_PCIE_DCR.U)
#define HW_PCIE_DCR_WR(v)     (HW_PCIE_DCR.U = (v))
#define HW_PCIE_DCR_SET(v)    (HW_PCIE_DCR_WR(HW_PCIE_DCR_RD() |  (v)))
#define HW_PCIE_DCR_CLR(v)    (HW_PCIE_DCR_WR(HW_PCIE_DCR_RD() & ~(v)))
#define HW_PCIE_DCR_TOG(v)    (HW_PCIE_DCR_WR(HW_PCIE_DCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_DCR bitfields
 */

/* --- Register HW_PCIE_DCR, field CAPTURED_SLOT_POWER_LIMIT_SCALE */

#define BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE      26
#define BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)   ((((reg32_t) v) << 26) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE)
#else
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)   (((v) << 26) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)   BF_CS1(PCIE_DCR, CAPTURED_SLOT_POWER_LIMIT_SCALE, v)
#endif

/* --- Register HW_PCIE_DCR, field CAPTURED_SLOT_POWER_LIMIT_VALUE */

#define BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE      18
#define BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE      0x03fc0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)   ((((reg32_t) v) << 18) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE)
#else
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)   (((v) << 18) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)   BF_CS1(PCIE_DCR, CAPTURED_SLOT_POWER_LIMIT_VALUE, v)
#endif

/* --- Register HW_PCIE_DCR, field ROLE */

#define BP_PCIE_DCR_ROLE      15
#define BM_PCIE_DCR_ROLE      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_ROLE(v)   ((((reg32_t) v) << 15) & BM_PCIE_DCR_ROLE)
#else
#define BF_PCIE_DCR_ROLE(v)   (((v) << 15) & BM_PCIE_DCR_ROLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_ROLE(v)   BF_CS1(PCIE_DCR, ROLE, v)
#endif

/* --- Register HW_PCIE_DCR, field ENDPOINT_L1_ACCEPTABLE_LATENCY */

#define BP_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY      9
#define BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)   ((((reg32_t) v) << 9) & BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY)
#else
#define BF_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)   (((v) << 9) & BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)   BF_CS1(PCIE_DCR, ENDPOINT_L1_ACCEPTABLE_LATENCY, v)
#endif

/* --- Register HW_PCIE_DCR, field ENDPOINT_L0S_ACCEPTABLE_LATENCY */

#define BP_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY      6
#define BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)   ((((reg32_t) v) << 6) & BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY)
#else
#define BF_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)   (((v) << 6) & BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)   BF_CS1(PCIE_DCR, ENDPOINT_L0S_ACCEPTABLE_LATENCY, v)
#endif

/* --- Register HW_PCIE_DCR, field EXTENDED_TAG_FIELD_SUPPORTED */

#define BP_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED      5
#define BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)   ((((reg32_t) v) << 5) & BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED)
#else
#define BF_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)   (((v) << 5) & BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)   BF_CS1(PCIE_DCR, EXTENDED_TAG_FIELD_SUPPORTED, v)
#endif

/* --- Register HW_PCIE_DCR, field PHANTOM_FUNCTION_SUPPORTED */

#define BP_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED      3
#define BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)   ((((reg32_t) v) << 3) & BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED)
#else
#define BF_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)   (((v) << 3) & BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)   BF_CS1(PCIE_DCR, PHANTOM_FUNCTION_SUPPORTED, v)
#endif

/* --- Register HW_PCIE_DCR, field MAX_PAYLOAD_SIZE_SUPPORTED */

#define BP_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED      0
#define BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)   ((((reg32_t) v) << 0) & BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED)
#else
#define BF_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)   (((v) << 0) & BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)   BF_CS1(PCIE_DCR, MAX_PAYLOAD_SIZE_SUPPORTED, v)
#endif

/*
 * HW_PCIE_DCONR - Device Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10;
        unsigned TRANSACTION_PENDING : 1;
        unsigned AUX_POWER_DETECTED : 1;
        unsigned UNSUPPORTED_REQUEST_DETECTED : 1;
        unsigned FATAL_ERROR_DETECTED : 1;
        unsigned NON_FATAL_ERROR_DETECTED : 1;
        unsigned CORRECTABLE_ERROR_DETECTED : 1;
        unsigned RESERVED1 : 1;
        unsigned MAX_READ_REQUEST_SIZE : 3;
        unsigned ENABLE_NO_SNOOP : 1;
        unsigned AUX_POWER_PM_ENABLE : 1;
        unsigned PHANTOM_FUNCTION_ENABLE : 1;
        unsigned EXTENDED_TAG_FIELD_ENABLE : 1;
        unsigned MAX_PAYLOAD_SIZE : 3;
        unsigned ENABLE_RELAXED_ORDERING : 1;
        unsigned UNSUPPORTED_REQUEST_REPORTING_ENABLE : 1;
        unsigned FATAL_ERROR_REPORTING_ENABLE : 1;
        unsigned NON_FATAL_ERROR_REPORTING_ENABLE : 1;
        unsigned CORRECTABLE_ERROR_REPORTING_ENABLE : 1;

    } B;
} hw_pcie_dconr_t;
#endif

/*
 * constants & macros for entire PCIE_DCONR register
 */
#define HW_PCIE_DCONR_ADDR      (REGS_PCIE_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_DCONR           (*(volatile hw_pcie_dconr_t *) HW_PCIE_DCONR_ADDR)
#define HW_PCIE_DCONR_RD()      (HW_PCIE_DCONR.U)
#define HW_PCIE_DCONR_WR(v)     (HW_PCIE_DCONR.U = (v))
#define HW_PCIE_DCONR_SET(v)    (HW_PCIE_DCONR_WR(HW_PCIE_DCONR_RD() |  (v)))
#define HW_PCIE_DCONR_CLR(v)    (HW_PCIE_DCONR_WR(HW_PCIE_DCONR_RD() & ~(v)))
#define HW_PCIE_DCONR_TOG(v)    (HW_PCIE_DCONR_WR(HW_PCIE_DCONR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_DCONR bitfields
 */

/* --- Register HW_PCIE_DCONR, field TRANSACTION_PENDING */

#define BP_PCIE_DCONR_TRANSACTION_PENDING      21
#define BM_PCIE_DCONR_TRANSACTION_PENDING      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_TRANSACTION_PENDING(v)   ((((reg32_t) v) << 21) & BM_PCIE_DCONR_TRANSACTION_PENDING)
#else
#define BF_PCIE_DCONR_TRANSACTION_PENDING(v)   (((v) << 21) & BM_PCIE_DCONR_TRANSACTION_PENDING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_TRANSACTION_PENDING(v)   BF_CS1(PCIE_DCONR, TRANSACTION_PENDING, v)
#endif

/* --- Register HW_PCIE_DCONR, field AUX_POWER_DETECTED */

#define BP_PCIE_DCONR_AUX_POWER_DETECTED      20
#define BM_PCIE_DCONR_AUX_POWER_DETECTED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_AUX_POWER_DETECTED(v)   ((((reg32_t) v) << 20) & BM_PCIE_DCONR_AUX_POWER_DETECTED)
#else
#define BF_PCIE_DCONR_AUX_POWER_DETECTED(v)   (((v) << 20) & BM_PCIE_DCONR_AUX_POWER_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_AUX_POWER_DETECTED(v)   BF_CS1(PCIE_DCONR, AUX_POWER_DETECTED, v)
#endif

/* --- Register HW_PCIE_DCONR, field UNSUPPORTED_REQUEST_DETECTED */

#define BP_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED      19
#define BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)   ((((reg32_t) v) << 19) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED)
#else
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)   (((v) << 19) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)   BF_CS1(PCIE_DCONR, UNSUPPORTED_REQUEST_DETECTED, v)
#endif

/* --- Register HW_PCIE_DCONR, field FATAL_ERROR_DETECTED */

#define BP_PCIE_DCONR_FATAL_ERROR_DETECTED      18
#define BM_PCIE_DCONR_FATAL_ERROR_DETECTED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_FATAL_ERROR_DETECTED(v)   ((((reg32_t) v) << 18) & BM_PCIE_DCONR_FATAL_ERROR_DETECTED)
#else
#define BF_PCIE_DCONR_FATAL_ERROR_DETECTED(v)   (((v) << 18) & BM_PCIE_DCONR_FATAL_ERROR_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_FATAL_ERROR_DETECTED(v)   BF_CS1(PCIE_DCONR, FATAL_ERROR_DETECTED, v)
#endif

/* --- Register HW_PCIE_DCONR, field NON_FATAL_ERROR_DETECTED */

#define BP_PCIE_DCONR_NON_FATAL_ERROR_DETECTED      17
#define BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)   ((((reg32_t) v) << 17) & BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED)
#else
#define BF_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)   (((v) << 17) & BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)   BF_CS1(PCIE_DCONR, NON_FATAL_ERROR_DETECTED, v)
#endif

/* --- Register HW_PCIE_DCONR, field CORRECTABLE_ERROR_DETECTED */

#define BP_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED      16
#define BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)   ((((reg32_t) v) << 16) & BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED)
#else
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)   (((v) << 16) & BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)   BF_CS1(PCIE_DCONR, CORRECTABLE_ERROR_DETECTED, v)
#endif

/* --- Register HW_PCIE_DCONR, field MAX_READ_REQUEST_SIZE */

#define BP_PCIE_DCONR_MAX_READ_REQUEST_SIZE      12
#define BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)   ((((reg32_t) v) << 12) & BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE)
#else
#define BF_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)   (((v) << 12) & BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)   BF_CS1(PCIE_DCONR, MAX_READ_REQUEST_SIZE, v)
#endif

/* --- Register HW_PCIE_DCONR, field ENABLE_NO_SNOOP */

#define BP_PCIE_DCONR_ENABLE_NO_SNOOP      11
#define BM_PCIE_DCONR_ENABLE_NO_SNOOP      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_ENABLE_NO_SNOOP(v)   ((((reg32_t) v) << 11) & BM_PCIE_DCONR_ENABLE_NO_SNOOP)
#else
#define BF_PCIE_DCONR_ENABLE_NO_SNOOP(v)   (((v) << 11) & BM_PCIE_DCONR_ENABLE_NO_SNOOP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_ENABLE_NO_SNOOP(v)   BF_CS1(PCIE_DCONR, ENABLE_NO_SNOOP, v)
#endif

/* --- Register HW_PCIE_DCONR, field AUX_POWER_PM_ENABLE */

#define BP_PCIE_DCONR_AUX_POWER_PM_ENABLE      10
#define BM_PCIE_DCONR_AUX_POWER_PM_ENABLE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)   ((((reg32_t) v) << 10) & BM_PCIE_DCONR_AUX_POWER_PM_ENABLE)
#else
#define BF_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)   (((v) << 10) & BM_PCIE_DCONR_AUX_POWER_PM_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)   BF_CS1(PCIE_DCONR, AUX_POWER_PM_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field PHANTOM_FUNCTION_ENABLE */

#define BP_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE      9
#define BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)   ((((reg32_t) v) << 9) & BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE)
#else
#define BF_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)   (((v) << 9) & BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)   BF_CS1(PCIE_DCONR, PHANTOM_FUNCTION_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field EXTENDED_TAG_FIELD_ENABLE */

#define BP_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE      8
#define BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)   ((((reg32_t) v) << 8) & BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE)
#else
#define BF_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)   (((v) << 8) & BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)   BF_CS1(PCIE_DCONR, EXTENDED_TAG_FIELD_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field MAX_PAYLOAD_SIZE */

#define BP_PCIE_DCONR_MAX_PAYLOAD_SIZE      5
#define BM_PCIE_DCONR_MAX_PAYLOAD_SIZE      0x000000e0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)   ((((reg32_t) v) << 5) & BM_PCIE_DCONR_MAX_PAYLOAD_SIZE)
#else
#define BF_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)   (((v) << 5) & BM_PCIE_DCONR_MAX_PAYLOAD_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)   BF_CS1(PCIE_DCONR, MAX_PAYLOAD_SIZE, v)
#endif

/* --- Register HW_PCIE_DCONR, field ENABLE_RELAXED_ORDERING */

#define BP_PCIE_DCONR_ENABLE_RELAXED_ORDERING      4
#define BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)   ((((reg32_t) v) << 4) & BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING)
#else
#define BF_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)   (((v) << 4) & BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)   BF_CS1(PCIE_DCONR, ENABLE_RELAXED_ORDERING, v)
#endif

/* --- Register HW_PCIE_DCONR, field UNSUPPORTED_REQUEST_REPORTING_ENABLE */

#define BP_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE      3
#define BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)   ((((reg32_t) v) << 3) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE)
#else
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)   (((v) << 3) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)   BF_CS1(PCIE_DCONR, UNSUPPORTED_REQUEST_REPORTING_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field FATAL_ERROR_REPORTING_ENABLE */

#define BP_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE      2
#define BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 2) & BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)   (((v) << 2) & BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_DCONR, FATAL_ERROR_REPORTING_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field NON_FATAL_ERROR_REPORTING_ENABLE */

#define BP_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE      1
#define BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 1) & BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   (((v) << 1) & BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_DCONR, NON_FATAL_ERROR_REPORTING_ENABLE, v)
#endif

/* --- Register HW_PCIE_DCONR, field CORRECTABLE_ERROR_REPORTING_ENABLE */

#define BP_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE      0
#define BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   (((v) << 0) & BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_DCONR, CORRECTABLE_ERROR_REPORTING_ENABLE, v)
#endif

/*
 * HW_PCIE_LCR - Link Capabilities Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PORT_NUMBER : 8;
        unsigned RESERVED0 : 2;
        unsigned LINK_BANDWIDTH_NOTIFICATION_CAPABILITY : 1;
        unsigned DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE : 1;
        unsigned SURPRISE_DOWN_ERROR_REPORTING_CAPABLE : 1;
        unsigned CLOCK_POWER_MANAGEMENT : 1;
        unsigned L1_EXIT_LATENCY : 3;
        unsigned L0S_EXIT_LATENCY : 3;
        unsigned ACTIVE_STATE_LINK_PM_SUPPORT : 2;
        unsigned MAXIMUM_LINK_WIDTH : 6;
        unsigned MAX_LINK_SPEEDS : 4;

    } B;
} hw_pcie_lcr_t;
#endif

/*
 * constants & macros for entire PCIE_LCR register
 */
#define HW_PCIE_LCR_ADDR      (REGS_PCIE_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_LCR           (*(volatile hw_pcie_lcr_t *) HW_PCIE_LCR_ADDR)
#define HW_PCIE_LCR_RD()      (HW_PCIE_LCR.U)
#define HW_PCIE_LCR_WR(v)     (HW_PCIE_LCR.U = (v))
#define HW_PCIE_LCR_SET(v)    (HW_PCIE_LCR_WR(HW_PCIE_LCR_RD() |  (v)))
#define HW_PCIE_LCR_CLR(v)    (HW_PCIE_LCR_WR(HW_PCIE_LCR_RD() & ~(v)))
#define HW_PCIE_LCR_TOG(v)    (HW_PCIE_LCR_WR(HW_PCIE_LCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_LCR bitfields
 */

/* --- Register HW_PCIE_LCR, field PORT_NUMBER */

#define BP_PCIE_LCR_PORT_NUMBER      24
#define BM_PCIE_LCR_PORT_NUMBER      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_PORT_NUMBER(v)   ((((reg32_t) v) << 24) & BM_PCIE_LCR_PORT_NUMBER)
#else
#define BF_PCIE_LCR_PORT_NUMBER(v)   (((v) << 24) & BM_PCIE_LCR_PORT_NUMBER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_PORT_NUMBER(v)   BF_CS1(PCIE_LCR, PORT_NUMBER, v)
#endif

/* --- Register HW_PCIE_LCR, field LINK_BANDWIDTH_NOTIFICATION_CAPABILITY */

#define BP_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY      21
#define BM_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY(v)   ((((reg32_t) v) << 21) & BM_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY)
#else
#define BF_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY(v)   (((v) << 21) & BM_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY(v)   BF_CS1(PCIE_LCR, LINK_BANDWIDTH_NOTIFICATION_CAPABILITY, v)
#endif

/* --- Register HW_PCIE_LCR, field DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE */

#define BP_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE      20
#define BM_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE(v)   ((((reg32_t) v) << 20) & BM_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE)
#else
#define BF_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE(v)   (((v) << 20) & BM_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE(v)   BF_CS1(PCIE_LCR, DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE, v)
#endif

/* --- Register HW_PCIE_LCR, field SURPRISE_DOWN_ERROR_REPORTING_CAPABLE */

#define BP_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE      19
#define BM_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE(v)   ((((reg32_t) v) << 19) & BM_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE)
#else
#define BF_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE(v)   (((v) << 19) & BM_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE(v)   BF_CS1(PCIE_LCR, SURPRISE_DOWN_ERROR_REPORTING_CAPABLE, v)
#endif

/* --- Register HW_PCIE_LCR, field CLOCK_POWER_MANAGEMENT */

#define BP_PCIE_LCR_CLOCK_POWER_MANAGEMENT      18
#define BM_PCIE_LCR_CLOCK_POWER_MANAGEMENT      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_CLOCK_POWER_MANAGEMENT(v)   ((((reg32_t) v) << 18) & BM_PCIE_LCR_CLOCK_POWER_MANAGEMENT)
#else
#define BF_PCIE_LCR_CLOCK_POWER_MANAGEMENT(v)   (((v) << 18) & BM_PCIE_LCR_CLOCK_POWER_MANAGEMENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_CLOCK_POWER_MANAGEMENT(v)   BF_CS1(PCIE_LCR, CLOCK_POWER_MANAGEMENT, v)
#endif

/* --- Register HW_PCIE_LCR, field L1_EXIT_LATENCY */

#define BP_PCIE_LCR_L1_EXIT_LATENCY      15
#define BM_PCIE_LCR_L1_EXIT_LATENCY      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_L1_EXIT_LATENCY(v)   ((((reg32_t) v) << 15) & BM_PCIE_LCR_L1_EXIT_LATENCY)
#else
#define BF_PCIE_LCR_L1_EXIT_LATENCY(v)   (((v) << 15) & BM_PCIE_LCR_L1_EXIT_LATENCY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_L1_EXIT_LATENCY(v)   BF_CS1(PCIE_LCR, L1_EXIT_LATENCY, v)
#endif

/* --- Register HW_PCIE_LCR, field L0S_EXIT_LATENCY */

#define BP_PCIE_LCR_L0S_EXIT_LATENCY      12
#define BM_PCIE_LCR_L0S_EXIT_LATENCY      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_L0S_EXIT_LATENCY(v)   ((((reg32_t) v) << 12) & BM_PCIE_LCR_L0S_EXIT_LATENCY)
#else
#define BF_PCIE_LCR_L0S_EXIT_LATENCY(v)   (((v) << 12) & BM_PCIE_LCR_L0S_EXIT_LATENCY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_L0S_EXIT_LATENCY(v)   BF_CS1(PCIE_LCR, L0S_EXIT_LATENCY, v)
#endif

/* --- Register HW_PCIE_LCR, field ACTIVE_STATE_LINK_PM_SUPPORT */

#define BP_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT      10
#define BM_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT(v)   ((((reg32_t) v) << 10) & BM_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT)
#else
#define BF_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT(v)   (((v) << 10) & BM_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT(v)   BF_CS1(PCIE_LCR, ACTIVE_STATE_LINK_PM_SUPPORT, v)
#endif

/* --- Register HW_PCIE_LCR, field MAXIMUM_LINK_WIDTH */

#define BP_PCIE_LCR_MAXIMUM_LINK_WIDTH      4
#define BM_PCIE_LCR_MAXIMUM_LINK_WIDTH      0x000003f0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_MAXIMUM_LINK_WIDTH(v)   ((((reg32_t) v) << 4) & BM_PCIE_LCR_MAXIMUM_LINK_WIDTH)
#else
#define BF_PCIE_LCR_MAXIMUM_LINK_WIDTH(v)   (((v) << 4) & BM_PCIE_LCR_MAXIMUM_LINK_WIDTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_MAXIMUM_LINK_WIDTH(v)   BF_CS1(PCIE_LCR, MAXIMUM_LINK_WIDTH, v)
#endif

/* --- Register HW_PCIE_LCR, field MAX_LINK_SPEEDS */

#define BP_PCIE_LCR_MAX_LINK_SPEEDS      0
#define BM_PCIE_LCR_MAX_LINK_SPEEDS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR_MAX_LINK_SPEEDS(v)   ((((reg32_t) v) << 0) & BM_PCIE_LCR_MAX_LINK_SPEEDS)
#else
#define BF_PCIE_LCR_MAX_LINK_SPEEDS(v)   (((v) << 0) & BM_PCIE_LCR_MAX_LINK_SPEEDS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR_MAX_LINK_SPEEDS(v)   BF_CS1(PCIE_LCR, MAX_LINK_SPEEDS, v)
#endif

/*
 * HW_PCIE_LCSR - Link Control and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LINK_AUTONOMOUS_BANDWIDTH_STATUS : 1;
        unsigned LINK_BANDWIDTH_MANAGEMENT_STATUS : 1;
        unsigned DATA_LINK_LAYER_ACTIVE : 1;
        unsigned SLOT_CLOCK_CONFIGURATION : 1;
        unsigned LINK_TRAINING : 1;
        unsigned RESERVED0 : 1;
        unsigned NEGOTIATED_LINK_WIDTH : 6;
        unsigned LINK_SPEED : 4;
        unsigned RESERVED1 : 4;
        unsigned LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE : 1;
        unsigned LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE : 1;
        unsigned HARDWARE_AUTONOMOUS_WIDTH_DISABLE : 1;
        unsigned ENABLE_CLOCK_POWER_MANAGEMENT : 1;
        unsigned EXTENDED_SYNCH : 1;
        unsigned COMMON_CLOCK_CONFIGURATION : 1;
        unsigned RETRAIN_LINK : 1;
        unsigned LINK_DISABLE : 1;
        unsigned RCB : 1;
        unsigned RESERVED2 : 1;
        unsigned ACTIVE_STATE_LINK_PM_CONTROL : 2;

    } B;
} hw_pcie_lcsr_t;
#endif

/*
 * constants & macros for entire PCIE_LCSR register
 */
#define HW_PCIE_LCSR_ADDR      (REGS_PCIE_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_LCSR           (*(volatile hw_pcie_lcsr_t *) HW_PCIE_LCSR_ADDR)
#define HW_PCIE_LCSR_RD()      (HW_PCIE_LCSR.U)
#define HW_PCIE_LCSR_WR(v)     (HW_PCIE_LCSR.U = (v))
#define HW_PCIE_LCSR_SET(v)    (HW_PCIE_LCSR_WR(HW_PCIE_LCSR_RD() |  (v)))
#define HW_PCIE_LCSR_CLR(v)    (HW_PCIE_LCSR_WR(HW_PCIE_LCSR_RD() & ~(v)))
#define HW_PCIE_LCSR_TOG(v)    (HW_PCIE_LCSR_WR(HW_PCIE_LCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_LCSR bitfields
 */

/* --- Register HW_PCIE_LCSR, field LINK_AUTONOMOUS_BANDWIDTH_STATUS */

#define BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS      31
#define BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)   ((((reg32_t) v) << 31) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS)
#else
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)   (((v) << 31) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)   BF_CS1(PCIE_LCSR, LINK_AUTONOMOUS_BANDWIDTH_STATUS, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_BANDWIDTH_MANAGEMENT_STATUS */

#define BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS      30
#define BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)   ((((reg32_t) v) << 30) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS)
#else
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)   (((v) << 30) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)   BF_CS1(PCIE_LCSR, LINK_BANDWIDTH_MANAGEMENT_STATUS, v)
#endif

/* --- Register HW_PCIE_LCSR, field DATA_LINK_LAYER_ACTIVE */

#define BP_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE      29
#define BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)   ((((reg32_t) v) << 29) & BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE)
#else
#define BF_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)   (((v) << 29) & BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)   BF_CS1(PCIE_LCSR, DATA_LINK_LAYER_ACTIVE, v)
#endif

/* --- Register HW_PCIE_LCSR, field SLOT_CLOCK_CONFIGURATION */

#define BP_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION      28
#define BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)   ((((reg32_t) v) << 28) & BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION)
#else
#define BF_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)   (((v) << 28) & BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)   BF_CS1(PCIE_LCSR, SLOT_CLOCK_CONFIGURATION, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_TRAINING */

#define BP_PCIE_LCSR_LINK_TRAINING      27
#define BM_PCIE_LCSR_LINK_TRAINING      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_TRAINING(v)   ((((reg32_t) v) << 27) & BM_PCIE_LCSR_LINK_TRAINING)
#else
#define BF_PCIE_LCSR_LINK_TRAINING(v)   (((v) << 27) & BM_PCIE_LCSR_LINK_TRAINING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_TRAINING(v)   BF_CS1(PCIE_LCSR, LINK_TRAINING, v)
#endif

/* --- Register HW_PCIE_LCSR, field NEGOTIATED_LINK_WIDTH */

#define BP_PCIE_LCSR_NEGOTIATED_LINK_WIDTH      20
#define BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH      0x03f00000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)   ((((reg32_t) v) << 20) & BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH)
#else
#define BF_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)   (((v) << 20) & BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)   BF_CS1(PCIE_LCSR, NEGOTIATED_LINK_WIDTH, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_SPEED */

#define BP_PCIE_LCSR_LINK_SPEED      16
#define BM_PCIE_LCSR_LINK_SPEED      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_SPEED(v)   ((((reg32_t) v) << 16) & BM_PCIE_LCSR_LINK_SPEED)
#else
#define BF_PCIE_LCSR_LINK_SPEED(v)   (((v) << 16) & BM_PCIE_LCSR_LINK_SPEED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_SPEED(v)   BF_CS1(PCIE_LCSR, LINK_SPEED, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE */

#define BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE      11
#define BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 11) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE)
#else
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)   (((v) << 11) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)   BF_CS1(PCIE_LCSR, LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE */

#define BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE      10
#define BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 10) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE)
#else
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)   (((v) << 10) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)   BF_CS1(PCIE_LCSR, LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE, v)
#endif

/* --- Register HW_PCIE_LCSR, field HARDWARE_AUTONOMOUS_WIDTH_DISABLE */

#define BP_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE      9
#define BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)   ((((reg32_t) v) << 9) & BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE)
#else
#define BF_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)   (((v) << 9) & BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)   BF_CS1(PCIE_LCSR, HARDWARE_AUTONOMOUS_WIDTH_DISABLE, v)
#endif

/* --- Register HW_PCIE_LCSR, field ENABLE_CLOCK_POWER_MANAGEMENT */

#define BP_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT      8
#define BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)   ((((reg32_t) v) << 8) & BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT)
#else
#define BF_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)   (((v) << 8) & BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)   BF_CS1(PCIE_LCSR, ENABLE_CLOCK_POWER_MANAGEMENT, v)
#endif

/* --- Register HW_PCIE_LCSR, field EXTENDED_SYNCH */

#define BP_PCIE_LCSR_EXTENDED_SYNCH      7
#define BM_PCIE_LCSR_EXTENDED_SYNCH      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_EXTENDED_SYNCH(v)   ((((reg32_t) v) << 7) & BM_PCIE_LCSR_EXTENDED_SYNCH)
#else
#define BF_PCIE_LCSR_EXTENDED_SYNCH(v)   (((v) << 7) & BM_PCIE_LCSR_EXTENDED_SYNCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_EXTENDED_SYNCH(v)   BF_CS1(PCIE_LCSR, EXTENDED_SYNCH, v)
#endif

/* --- Register HW_PCIE_LCSR, field COMMON_CLOCK_CONFIGURATION */

#define BP_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION      6
#define BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)   ((((reg32_t) v) << 6) & BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION)
#else
#define BF_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)   (((v) << 6) & BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)   BF_CS1(PCIE_LCSR, COMMON_CLOCK_CONFIGURATION, v)
#endif

/* --- Register HW_PCIE_LCSR, field RETRAIN_LINK */

#define BP_PCIE_LCSR_RETRAIN_LINK      5
#define BM_PCIE_LCSR_RETRAIN_LINK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_RETRAIN_LINK(v)   ((((reg32_t) v) << 5) & BM_PCIE_LCSR_RETRAIN_LINK)
#else
#define BF_PCIE_LCSR_RETRAIN_LINK(v)   (((v) << 5) & BM_PCIE_LCSR_RETRAIN_LINK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_RETRAIN_LINK(v)   BF_CS1(PCIE_LCSR, RETRAIN_LINK, v)
#endif

/* --- Register HW_PCIE_LCSR, field LINK_DISABLE */

#define BP_PCIE_LCSR_LINK_DISABLE      4
#define BM_PCIE_LCSR_LINK_DISABLE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_LINK_DISABLE(v)   ((((reg32_t) v) << 4) & BM_PCIE_LCSR_LINK_DISABLE)
#else
#define BF_PCIE_LCSR_LINK_DISABLE(v)   (((v) << 4) & BM_PCIE_LCSR_LINK_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_LINK_DISABLE(v)   BF_CS1(PCIE_LCSR, LINK_DISABLE, v)
#endif

/* --- Register HW_PCIE_LCSR, field RCB */

#define BP_PCIE_LCSR_RCB      3
#define BM_PCIE_LCSR_RCB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_RCB(v)   ((((reg32_t) v) << 3) & BM_PCIE_LCSR_RCB)
#else
#define BF_PCIE_LCSR_RCB(v)   (((v) << 3) & BM_PCIE_LCSR_RCB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_RCB(v)   BF_CS1(PCIE_LCSR, RCB, v)
#endif

/* --- Register HW_PCIE_LCSR, field ACTIVE_STATE_LINK_PM_CONTROL */

#define BP_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL      0
#define BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)   ((((reg32_t) v) << 0) & BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL)
#else
#define BF_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)   (((v) << 0) & BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)   BF_CS1(PCIE_LCSR, ACTIVE_STATE_LINK_PM_CONTROL, v)
#endif

/*
 * HW_PCIE_SCR - Slot Capabilities Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PHYSICAL_SLOT_NUMBER : 13;
        unsigned NO_COMMAND_COMPLETE_SUPPORT : 1;
        unsigned ELECTROMECHANICAL_INTERLOCK_PRESENT : 1;
        unsigned SLOT_POWER_LIMIT_SCALE : 2;
        unsigned SLOT_POWER_LIMIT_VALUE : 8;
        unsigned HOT_PLUG_CAPABLE : 1;
        unsigned HOT_PLUG_SURPRISE : 1;
        unsigned POWER_INDICATOR_PRESENT : 1;
        unsigned ATTENTION_INDICATOR_PRESENT : 1;
        unsigned MRL_SENSOR_PRESENT : 1;
        unsigned POWER_CONTROLLER_PRESENT : 1;
        unsigned ATTENTION_INDICATOR_PRESENT : 1;

    } B;
} hw_pcie_scr_t;
#endif

/*
 * constants & macros for entire PCIE_SCR register
 */
#define HW_PCIE_SCR_ADDR      (REGS_PCIE_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_SCR           (*(volatile hw_pcie_scr_t *) HW_PCIE_SCR_ADDR)
#define HW_PCIE_SCR_RD()      (HW_PCIE_SCR.U)
#define HW_PCIE_SCR_WR(v)     (HW_PCIE_SCR.U = (v))
#define HW_PCIE_SCR_SET(v)    (HW_PCIE_SCR_WR(HW_PCIE_SCR_RD() |  (v)))
#define HW_PCIE_SCR_CLR(v)    (HW_PCIE_SCR_WR(HW_PCIE_SCR_RD() & ~(v)))
#define HW_PCIE_SCR_TOG(v)    (HW_PCIE_SCR_WR(HW_PCIE_SCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_SCR bitfields
 */

/* --- Register HW_PCIE_SCR, field PHYSICAL_SLOT_NUMBER */

#define BP_PCIE_SCR_PHYSICAL_SLOT_NUMBER      19
#define BM_PCIE_SCR_PHYSICAL_SLOT_NUMBER      0xfff80000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_PHYSICAL_SLOT_NUMBER(v)   ((((reg32_t) v) << 19) & BM_PCIE_SCR_PHYSICAL_SLOT_NUMBER)
#else
#define BF_PCIE_SCR_PHYSICAL_SLOT_NUMBER(v)   (((v) << 19) & BM_PCIE_SCR_PHYSICAL_SLOT_NUMBER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_PHYSICAL_SLOT_NUMBER(v)   BF_CS1(PCIE_SCR, PHYSICAL_SLOT_NUMBER, v)
#endif

/* --- Register HW_PCIE_SCR, field NO_COMMAND_COMPLETE_SUPPORT */

#define BP_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT      18
#define BM_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT(v)   ((((reg32_t) v) << 18) & BM_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT)
#else
#define BF_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT(v)   (((v) << 18) & BM_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT(v)   BF_CS1(PCIE_SCR, NO_COMMAND_COMPLETE_SUPPORT, v)
#endif

/* --- Register HW_PCIE_SCR, field ELECTROMECHANICAL_INTERLOCK_PRESENT */

#define BP_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT      17
#define BM_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT(v)   ((((reg32_t) v) << 17) & BM_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT)
#else
#define BF_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT(v)   (((v) << 17) & BM_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT(v)   BF_CS1(PCIE_SCR, ELECTROMECHANICAL_INTERLOCK_PRESENT, v)
#endif

/* --- Register HW_PCIE_SCR, field SLOT_POWER_LIMIT_SCALE */

#define BP_PCIE_SCR_SLOT_POWER_LIMIT_SCALE      15
#define BM_PCIE_SCR_SLOT_POWER_LIMIT_SCALE      0x00018000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_SLOT_POWER_LIMIT_SCALE(v)   ((((reg32_t) v) << 15) & BM_PCIE_SCR_SLOT_POWER_LIMIT_SCALE)
#else
#define BF_PCIE_SCR_SLOT_POWER_LIMIT_SCALE(v)   (((v) << 15) & BM_PCIE_SCR_SLOT_POWER_LIMIT_SCALE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_SLOT_POWER_LIMIT_SCALE(v)   BF_CS1(PCIE_SCR, SLOT_POWER_LIMIT_SCALE, v)
#endif

/* --- Register HW_PCIE_SCR, field SLOT_POWER_LIMIT_VALUE */

#define BP_PCIE_SCR_SLOT_POWER_LIMIT_VALUE      7
#define BM_PCIE_SCR_SLOT_POWER_LIMIT_VALUE      0x00007f80

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_SLOT_POWER_LIMIT_VALUE(v)   ((((reg32_t) v) << 7) & BM_PCIE_SCR_SLOT_POWER_LIMIT_VALUE)
#else
#define BF_PCIE_SCR_SLOT_POWER_LIMIT_VALUE(v)   (((v) << 7) & BM_PCIE_SCR_SLOT_POWER_LIMIT_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_SLOT_POWER_LIMIT_VALUE(v)   BF_CS1(PCIE_SCR, SLOT_POWER_LIMIT_VALUE, v)
#endif

/* --- Register HW_PCIE_SCR, field HOT_PLUG_CAPABLE */

#define BP_PCIE_SCR_HOT_PLUG_CAPABLE      6
#define BM_PCIE_SCR_HOT_PLUG_CAPABLE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_HOT_PLUG_CAPABLE(v)   ((((reg32_t) v) << 6) & BM_PCIE_SCR_HOT_PLUG_CAPABLE)
#else
#define BF_PCIE_SCR_HOT_PLUG_CAPABLE(v)   (((v) << 6) & BM_PCIE_SCR_HOT_PLUG_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_HOT_PLUG_CAPABLE(v)   BF_CS1(PCIE_SCR, HOT_PLUG_CAPABLE, v)
#endif

/* --- Register HW_PCIE_SCR, field HOT_PLUG_SURPRISE */

#define BP_PCIE_SCR_HOT_PLUG_SURPRISE      5
#define BM_PCIE_SCR_HOT_PLUG_SURPRISE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_HOT_PLUG_SURPRISE(v)   ((((reg32_t) v) << 5) & BM_PCIE_SCR_HOT_PLUG_SURPRISE)
#else
#define BF_PCIE_SCR_HOT_PLUG_SURPRISE(v)   (((v) << 5) & BM_PCIE_SCR_HOT_PLUG_SURPRISE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_HOT_PLUG_SURPRISE(v)   BF_CS1(PCIE_SCR, HOT_PLUG_SURPRISE, v)
#endif

/* --- Register HW_PCIE_SCR, field POWER_INDICATOR_PRESENT */

#define BP_PCIE_SCR_POWER_INDICATOR_PRESENT      4
#define BM_PCIE_SCR_POWER_INDICATOR_PRESENT      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_POWER_INDICATOR_PRESENT(v)   ((((reg32_t) v) << 4) & BM_PCIE_SCR_POWER_INDICATOR_PRESENT)
#else
#define BF_PCIE_SCR_POWER_INDICATOR_PRESENT(v)   (((v) << 4) & BM_PCIE_SCR_POWER_INDICATOR_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_POWER_INDICATOR_PRESENT(v)   BF_CS1(PCIE_SCR, POWER_INDICATOR_PRESENT, v)
#endif

/* --- Register HW_PCIE_SCR, field ATTENTION_INDICATOR_PRESENT */

#define BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      3
#define BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   ((((reg32_t) v) << 3) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT)
#else
#define BF_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   (((v) << 3) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   BF_CS1(PCIE_SCR, ATTENTION_INDICATOR_PRESENT, v)
#endif

/* --- Register HW_PCIE_SCR, field MRL_SENSOR_PRESENT */

#define BP_PCIE_SCR_MRL_SENSOR_PRESENT      2
#define BM_PCIE_SCR_MRL_SENSOR_PRESENT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_MRL_SENSOR_PRESENT(v)   ((((reg32_t) v) << 2) & BM_PCIE_SCR_MRL_SENSOR_PRESENT)
#else
#define BF_PCIE_SCR_MRL_SENSOR_PRESENT(v)   (((v) << 2) & BM_PCIE_SCR_MRL_SENSOR_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_MRL_SENSOR_PRESENT(v)   BF_CS1(PCIE_SCR, MRL_SENSOR_PRESENT, v)
#endif

/* --- Register HW_PCIE_SCR, field POWER_CONTROLLER_PRESENT */

#define BP_PCIE_SCR_POWER_CONTROLLER_PRESENT      1
#define BM_PCIE_SCR_POWER_CONTROLLER_PRESENT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_POWER_CONTROLLER_PRESENT(v)   ((((reg32_t) v) << 1) & BM_PCIE_SCR_POWER_CONTROLLER_PRESENT)
#else
#define BF_PCIE_SCR_POWER_CONTROLLER_PRESENT(v)   (((v) << 1) & BM_PCIE_SCR_POWER_CONTROLLER_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_POWER_CONTROLLER_PRESENT(v)   BF_CS1(PCIE_SCR, POWER_CONTROLLER_PRESENT, v)
#endif

/* --- Register HW_PCIE_SCR, field ATTENTION_INDICATOR_PRESENT */

#define BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      0
#define BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   ((((reg32_t) v) << 0) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT)
#else
#define BF_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   (((v) << 0) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(v)   BF_CS1(PCIE_SCR, ATTENTION_INDICATOR_PRESENT, v)
#endif

/*
 * HW_PCIE_SCSR - Slot Control and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7;
        unsigned DATA_LINK_LAYER_STATE_CHANGED : 1;
        unsigned ELECTROMECHANICAL_INTERLOCK_STATUS : 1;
        unsigned PRESENCE_DETECT_STATE : 1;
        unsigned MRL_SENSOR_STATE : 1;
        unsigned COMMAND_COMPLETED : 1;
        unsigned PRESENCE_DETECT_CHANGED : 1;
        unsigned MRL_SENSOR_CHANGED : 1;
        unsigned POWER_FAULT_DETECTED : 1;
        unsigned ATTENTION_BUTTON_PRESSED : 1;
        unsigned RESERVED1 : 3;
        unsigned DATA_LINK_LAYER_STATE_CHANGED_ENABLE : 1;
        unsigned ELECTROMECHANICAL_INTERLOCK_CONTROL : 1;
        unsigned POWER_CONTROLLER_CONTROL : 1;
        unsigned POWER_INDICATOR_CONTROL : 2;
        unsigned ATTENTION_INDICATOR_CONTROL : 2;
        unsigned HOT_PLUG_INTERRUPT_ENABLE : 1;
        unsigned COMMAND_COMPLETED_INTERRUPT_ENABLE : 1;
        unsigned PRESENCE_DETECT_CHANGED_ENABLE : 1;
        unsigned MRL_SENSOR_CHANGED_ENABLE : 1;
        unsigned POWER : 1;
        unsigned ATTENTION : 1;

    } B;
} hw_pcie_scsr_t;
#endif

/*
 * constants & macros for entire PCIE_SCSR register
 */
#define HW_PCIE_SCSR_ADDR      (REGS_PCIE_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_SCSR           (*(volatile hw_pcie_scsr_t *) HW_PCIE_SCSR_ADDR)
#define HW_PCIE_SCSR_RD()      (HW_PCIE_SCSR.U)
#define HW_PCIE_SCSR_WR(v)     (HW_PCIE_SCSR.U = (v))
#define HW_PCIE_SCSR_SET(v)    (HW_PCIE_SCSR_WR(HW_PCIE_SCSR_RD() |  (v)))
#define HW_PCIE_SCSR_CLR(v)    (HW_PCIE_SCSR_WR(HW_PCIE_SCSR_RD() & ~(v)))
#define HW_PCIE_SCSR_TOG(v)    (HW_PCIE_SCSR_WR(HW_PCIE_SCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_SCSR bitfields
 */

/* --- Register HW_PCIE_SCSR, field DATA_LINK_LAYER_STATE_CHANGED */

#define BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED      24
#define BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)   ((((reg32_t) v) << 24) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED)
#else
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)   (((v) << 24) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)   BF_CS1(PCIE_SCSR, DATA_LINK_LAYER_STATE_CHANGED, v)
#endif

/* --- Register HW_PCIE_SCSR, field ELECTROMECHANICAL_INTERLOCK_STATUS */

#define BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS      23
#define BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)   ((((reg32_t) v) << 23) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS)
#else
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)   (((v) << 23) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)   BF_CS1(PCIE_SCSR, ELECTROMECHANICAL_INTERLOCK_STATUS, v)
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_STATE */

#define BP_PCIE_SCSR_PRESENCE_DETECT_STATE      22
#define BM_PCIE_SCSR_PRESENCE_DETECT_STATE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_PRESENCE_DETECT_STATE(v)   ((((reg32_t) v) << 22) & BM_PCIE_SCSR_PRESENCE_DETECT_STATE)
#else
#define BF_PCIE_SCSR_PRESENCE_DETECT_STATE(v)   (((v) << 22) & BM_PCIE_SCSR_PRESENCE_DETECT_STATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_PRESENCE_DETECT_STATE(v)   BF_CS1(PCIE_SCSR, PRESENCE_DETECT_STATE, v)
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_STATE */

#define BP_PCIE_SCSR_MRL_SENSOR_STATE      21
#define BM_PCIE_SCSR_MRL_SENSOR_STATE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_MRL_SENSOR_STATE(v)   ((((reg32_t) v) << 21) & BM_PCIE_SCSR_MRL_SENSOR_STATE)
#else
#define BF_PCIE_SCSR_MRL_SENSOR_STATE(v)   (((v) << 21) & BM_PCIE_SCSR_MRL_SENSOR_STATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_MRL_SENSOR_STATE(v)   BF_CS1(PCIE_SCSR, MRL_SENSOR_STATE, v)
#endif

/* --- Register HW_PCIE_SCSR, field COMMAND_COMPLETED */

#define BP_PCIE_SCSR_COMMAND_COMPLETED      20
#define BM_PCIE_SCSR_COMMAND_COMPLETED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_COMMAND_COMPLETED(v)   ((((reg32_t) v) << 20) & BM_PCIE_SCSR_COMMAND_COMPLETED)
#else
#define BF_PCIE_SCSR_COMMAND_COMPLETED(v)   (((v) << 20) & BM_PCIE_SCSR_COMMAND_COMPLETED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_COMMAND_COMPLETED(v)   BF_CS1(PCIE_SCSR, COMMAND_COMPLETED, v)
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_CHANGED */

#define BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED      19
#define BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)   ((((reg32_t) v) << 19) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED)
#else
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)   (((v) << 19) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)   BF_CS1(PCIE_SCSR, PRESENCE_DETECT_CHANGED, v)
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_CHANGED */

#define BP_PCIE_SCSR_MRL_SENSOR_CHANGED      18
#define BM_PCIE_SCSR_MRL_SENSOR_CHANGED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED(v)   ((((reg32_t) v) << 18) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED)
#else
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED(v)   (((v) << 18) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_MRL_SENSOR_CHANGED(v)   BF_CS1(PCIE_SCSR, MRL_SENSOR_CHANGED, v)
#endif

/* --- Register HW_PCIE_SCSR, field POWER_FAULT_DETECTED */

#define BP_PCIE_SCSR_POWER_FAULT_DETECTED      17
#define BM_PCIE_SCSR_POWER_FAULT_DETECTED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_POWER_FAULT_DETECTED(v)   ((((reg32_t) v) << 17) & BM_PCIE_SCSR_POWER_FAULT_DETECTED)
#else
#define BF_PCIE_SCSR_POWER_FAULT_DETECTED(v)   (((v) << 17) & BM_PCIE_SCSR_POWER_FAULT_DETECTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_POWER_FAULT_DETECTED(v)   BF_CS1(PCIE_SCSR, POWER_FAULT_DETECTED, v)
#endif

/* --- Register HW_PCIE_SCSR, field ATTENTION_BUTTON_PRESSED */

#define BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED      16
#define BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)   ((((reg32_t) v) << 16) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED)
#else
#define BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)   (((v) << 16) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)   BF_CS1(PCIE_SCSR, ATTENTION_BUTTON_PRESSED, v)
#endif

/* --- Register HW_PCIE_SCSR, field DATA_LINK_LAYER_STATE_CHANGED_ENABLE */

#define BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE      12
#define BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)   ((((reg32_t) v) << 12) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE)
#else
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)   (((v) << 12) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)   BF_CS1(PCIE_SCSR, DATA_LINK_LAYER_STATE_CHANGED_ENABLE, v)
#endif

/* --- Register HW_PCIE_SCSR, field ELECTROMECHANICAL_INTERLOCK_CONTROL */

#define BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL      11
#define BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)   ((((reg32_t) v) << 11) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL)
#else
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)   (((v) << 11) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)   BF_CS1(PCIE_SCSR, ELECTROMECHANICAL_INTERLOCK_CONTROL, v)
#endif

/* --- Register HW_PCIE_SCSR, field POWER_CONTROLLER_CONTROL */

#define BP_PCIE_SCSR_POWER_CONTROLLER_CONTROL      10
#define BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)   ((((reg32_t) v) << 10) & BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL)
#else
#define BF_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)   (((v) << 10) & BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)   BF_CS1(PCIE_SCSR, POWER_CONTROLLER_CONTROL, v)
#endif

/* --- Register HW_PCIE_SCSR, field POWER_INDICATOR_CONTROL */

#define BP_PCIE_SCSR_POWER_INDICATOR_CONTROL      8
#define BM_PCIE_SCSR_POWER_INDICATOR_CONTROL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)   ((((reg32_t) v) << 8) & BM_PCIE_SCSR_POWER_INDICATOR_CONTROL)
#else
#define BF_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)   (((v) << 8) & BM_PCIE_SCSR_POWER_INDICATOR_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)   BF_CS1(PCIE_SCSR, POWER_INDICATOR_CONTROL, v)
#endif

/* --- Register HW_PCIE_SCSR, field ATTENTION_INDICATOR_CONTROL */

#define BP_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL      6
#define BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)   ((((reg32_t) v) << 6) & BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL)
#else
#define BF_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)   (((v) << 6) & BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)   BF_CS1(PCIE_SCSR, ATTENTION_INDICATOR_CONTROL, v)
#endif

/* --- Register HW_PCIE_SCSR, field HOT_PLUG_INTERRUPT_ENABLE */

#define BP_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE      5
#define BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 5) & BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE)
#else
#define BF_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)   (((v) << 5) & BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)   BF_CS1(PCIE_SCSR, HOT_PLUG_INTERRUPT_ENABLE, v)
#endif

/* --- Register HW_PCIE_SCSR, field COMMAND_COMPLETED_INTERRUPT_ENABLE */

#define BP_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE      4
#define BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 4) & BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE)
#else
#define BF_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)   (((v) << 4) & BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)   BF_CS1(PCIE_SCSR, COMMAND_COMPLETED_INTERRUPT_ENABLE, v)
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_CHANGED_ENABLE */

#define BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE      3
#define BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)   ((((reg32_t) v) << 3) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE)
#else
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)   (((v) << 3) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)   BF_CS1(PCIE_SCSR, PRESENCE_DETECT_CHANGED_ENABLE, v)
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_CHANGED_ENABLE */

#define BP_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE      2
#define BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)   ((((reg32_t) v) << 2) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE)
#else
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)   (((v) << 2) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)   BF_CS1(PCIE_SCSR, MRL_SENSOR_CHANGED_ENABLE, v)
#endif

/* --- Register HW_PCIE_SCSR, field POWER */

#define BP_PCIE_SCSR_POWER      1
#define BM_PCIE_SCSR_POWER      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_POWER(v)   ((((reg32_t) v) << 1) & BM_PCIE_SCSR_POWER)
#else
#define BF_PCIE_SCSR_POWER(v)   (((v) << 1) & BM_PCIE_SCSR_POWER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_POWER(v)   BF_CS1(PCIE_SCSR, POWER, v)
#endif

/* --- Register HW_PCIE_SCSR, field ATTENTION */

#define BP_PCIE_SCSR_ATTENTION      0
#define BM_PCIE_SCSR_ATTENTION      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_SCSR_ATTENTION(v)   ((((reg32_t) v) << 0) & BM_PCIE_SCSR_ATTENTION)
#else
#define BF_PCIE_SCSR_ATTENTION(v)   (((v) << 0) & BM_PCIE_SCSR_ATTENTION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_SCSR_ATTENTION(v)   BF_CS1(PCIE_SCSR, ATTENTION, v)
#endif

/*
 * HW_PCIE_RCCR - Root Control and Capabilities Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 15;
        unsigned CRS_SOFTWARE_VISIBILITY : 1;
        unsigned RESERVED1 : 11;
        unsigned CRS_SOFTWARE_VISIBILITY_ENABLE : 1;
        unsigned PME_INTERRUPT_ENABLE : 1;
        unsigned SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE : 1;
        unsigned SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE : 1;
        unsigned SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE : 1;

    } B;
} hw_pcie_rccr_t;
#endif

/*
 * constants & macros for entire PCIE_RCCR register
 */
#define HW_PCIE_RCCR_ADDR      (REGS_PCIE_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_RCCR           (*(volatile hw_pcie_rccr_t *) HW_PCIE_RCCR_ADDR)
#define HW_PCIE_RCCR_RD()      (HW_PCIE_RCCR.U)
#define HW_PCIE_RCCR_WR(v)     (HW_PCIE_RCCR.U = (v))
#define HW_PCIE_RCCR_SET(v)    (HW_PCIE_RCCR_WR(HW_PCIE_RCCR_RD() |  (v)))
#define HW_PCIE_RCCR_CLR(v)    (HW_PCIE_RCCR_WR(HW_PCIE_RCCR_RD() & ~(v)))
#define HW_PCIE_RCCR_TOG(v)    (HW_PCIE_RCCR_WR(HW_PCIE_RCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_RCCR bitfields
 */

/* --- Register HW_PCIE_RCCR, field CRS_SOFTWARE_VISIBILITY */

#define BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY      16
#define BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)   ((((reg32_t) v) << 16) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY)
#else
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)   (((v) << 16) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)   BF_CS1(PCIE_RCCR, CRS_SOFTWARE_VISIBILITY, v)
#endif

/* --- Register HW_PCIE_RCCR, field CRS_SOFTWARE_VISIBILITY_ENABLE */

#define BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE      4
#define BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)   ((((reg32_t) v) << 4) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE)
#else
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)   (((v) << 4) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)   BF_CS1(PCIE_RCCR, CRS_SOFTWARE_VISIBILITY_ENABLE, v)
#endif

/* --- Register HW_PCIE_RCCR, field PME_INTERRUPT_ENABLE */

#define BP_PCIE_RCCR_PME_INTERRUPT_ENABLE      3
#define BM_PCIE_RCCR_PME_INTERRUPT_ENABLE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 3) & BM_PCIE_RCCR_PME_INTERRUPT_ENABLE)
#else
#define BF_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)   (((v) << 3) & BM_PCIE_RCCR_PME_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)   BF_CS1(PCIE_RCCR, PME_INTERRUPT_ENABLE, v)
#endif

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE      2
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)   ((((reg32_t) v) << 2) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE)
#else
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)   (((v) << 2) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)   BF_CS1(PCIE_RCCR, SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE, v)
#endif

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE      1
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)   ((((reg32_t) v) << 1) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE)
#else
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)   (((v) << 1) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)   BF_CS1(PCIE_RCCR, SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE, v)
#endif

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE      0
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE)
#else
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)   (((v) << 0) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)   BF_CS1(PCIE_RCCR, SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE, v)
#endif

/*
 * HW_PCIE_RSR - Root Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned PME_PENDING : 1;
        unsigned PME_STATUS : 1;
        unsigned PME_REQUESTER_ID : 16;

    } B;
} hw_pcie_rsr_t;
#endif

/*
 * constants & macros for entire PCIE_RSR register
 */
#define HW_PCIE_RSR_ADDR      (REGS_PCIE_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_RSR           (*(volatile hw_pcie_rsr_t *) HW_PCIE_RSR_ADDR)
#define HW_PCIE_RSR_RD()      (HW_PCIE_RSR.U)
#define HW_PCIE_RSR_WR(v)     (HW_PCIE_RSR.U = (v))
#define HW_PCIE_RSR_SET(v)    (HW_PCIE_RSR_WR(HW_PCIE_RSR_RD() |  (v)))
#define HW_PCIE_RSR_CLR(v)    (HW_PCIE_RSR_WR(HW_PCIE_RSR_RD() & ~(v)))
#define HW_PCIE_RSR_TOG(v)    (HW_PCIE_RSR_WR(HW_PCIE_RSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_RSR bitfields
 */

/* --- Register HW_PCIE_RSR, field PME_PENDING */

#define BP_PCIE_RSR_PME_PENDING      17
#define BM_PCIE_RSR_PME_PENDING      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RSR_PME_PENDING(v)   ((((reg32_t) v) << 17) & BM_PCIE_RSR_PME_PENDING)
#else
#define BF_PCIE_RSR_PME_PENDING(v)   (((v) << 17) & BM_PCIE_RSR_PME_PENDING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RSR_PME_PENDING(v)   BF_CS1(PCIE_RSR, PME_PENDING, v)
#endif

/* --- Register HW_PCIE_RSR, field PME_STATUS */

#define BP_PCIE_RSR_PME_STATUS      16
#define BM_PCIE_RSR_PME_STATUS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RSR_PME_STATUS(v)   ((((reg32_t) v) << 16) & BM_PCIE_RSR_PME_STATUS)
#else
#define BF_PCIE_RSR_PME_STATUS(v)   (((v) << 16) & BM_PCIE_RSR_PME_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RSR_PME_STATUS(v)   BF_CS1(PCIE_RSR, PME_STATUS, v)
#endif

/* --- Register HW_PCIE_RSR, field PME_REQUESTER_ID */

#define BP_PCIE_RSR_PME_REQUESTER_ID      0
#define BM_PCIE_RSR_PME_REQUESTER_ID      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RSR_PME_REQUESTER_ID(v)   ((((reg32_t) v) << 0) & BM_PCIE_RSR_PME_REQUESTER_ID)
#else
#define BF_PCIE_RSR_PME_REQUESTER_ID(v)   (((v) << 0) & BM_PCIE_RSR_PME_REQUESTER_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RSR_PME_REQUESTER_ID(v)   BF_CS1(PCIE_RSR, PME_REQUESTER_ID, v)
#endif

/*
 * HW_PCIE_DCR2 - Device Capabilities 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 27;
        unsigned COMPLETION_TIMEOUT_DISABLE_SUPPORTED : 1;
        unsigned COMPLETION_TIMEOUT_RANGES_SUPPORTED : 4;

    } B;
} hw_pcie_dcr2_t;
#endif

/*
 * constants & macros for entire PCIE_DCR2 register
 */
#define HW_PCIE_DCR2_ADDR      (REGS_PCIE_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_DCR2           (*(volatile hw_pcie_dcr2_t *) HW_PCIE_DCR2_ADDR)
#define HW_PCIE_DCR2_RD()      (HW_PCIE_DCR2.U)
#define HW_PCIE_DCR2_WR(v)     (HW_PCIE_DCR2.U = (v))
#define HW_PCIE_DCR2_SET(v)    (HW_PCIE_DCR2_WR(HW_PCIE_DCR2_RD() |  (v)))
#define HW_PCIE_DCR2_CLR(v)    (HW_PCIE_DCR2_WR(HW_PCIE_DCR2_RD() & ~(v)))
#define HW_PCIE_DCR2_TOG(v)    (HW_PCIE_DCR2_WR(HW_PCIE_DCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_DCR2 bitfields
 */

/* --- Register HW_PCIE_DCR2, field COMPLETION_TIMEOUT_DISABLE_SUPPORTED */

#define BP_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED      4
#define BM_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED(v)   ((((reg32_t) v) << 4) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED)
#else
#define BF_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED(v)   (((v) << 4) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED(v)   BF_CS1(PCIE_DCR2, COMPLETION_TIMEOUT_DISABLE_SUPPORTED, v)
#endif

/* --- Register HW_PCIE_DCR2, field COMPLETION_TIMEOUT_RANGES_SUPPORTED */

#define BP_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED      0
#define BM_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED(v)   ((((reg32_t) v) << 0) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED)
#else
#define BF_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED(v)   (((v) << 0) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED(v)   BF_CS1(PCIE_DCR2, COMPLETION_TIMEOUT_RANGES_SUPPORTED, v)
#endif

/*
 * HW_PCIE_DCSR2 - Device Control and Status 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 27;
        unsigned COMPLETION_TIMEOUT_DISABLE : 1;
        unsigned COMPLETION_TIMEOUT_VALUE : 4;

    } B;
} hw_pcie_dcsr2_t;
#endif

/*
 * constants & macros for entire PCIE_DCSR2 register
 */
#define HW_PCIE_DCSR2_ADDR      (REGS_PCIE_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_DCSR2           (*(volatile hw_pcie_dcsr2_t *) HW_PCIE_DCSR2_ADDR)
#define HW_PCIE_DCSR2_RD()      (HW_PCIE_DCSR2.U)
#define HW_PCIE_DCSR2_WR(v)     (HW_PCIE_DCSR2.U = (v))
#define HW_PCIE_DCSR2_SET(v)    (HW_PCIE_DCSR2_WR(HW_PCIE_DCSR2_RD() |  (v)))
#define HW_PCIE_DCSR2_CLR(v)    (HW_PCIE_DCSR2_WR(HW_PCIE_DCSR2_RD() & ~(v)))
#define HW_PCIE_DCSR2_TOG(v)    (HW_PCIE_DCSR2_WR(HW_PCIE_DCSR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_DCSR2 bitfields
 */

/* --- Register HW_PCIE_DCSR2, field COMPLETION_TIMEOUT_DISABLE */

#define BP_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE      4
#define BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)   ((((reg32_t) v) << 4) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE)
#else
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)   (((v) << 4) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)   BF_CS1(PCIE_DCSR2, COMPLETION_TIMEOUT_DISABLE, v)
#endif

/* --- Register HW_PCIE_DCSR2, field COMPLETION_TIMEOUT_VALUE */

#define BP_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE      0
#define BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)   ((((reg32_t) v) << 0) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE)
#else
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)   (((v) << 0) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)   BF_CS1(PCIE_DCSR2, COMPLETION_TIMEOUT_VALUE, v)
#endif

/*
 * HW_PCIE_LCR2 - Link Capabilities 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 23;
        unsigned CROSSLINK_SUPPORTED : 1;
        unsigned SUPPORTED_LINK_SPEEDS_VECTOR : 7;
        unsigned RESERVED1 : 1;

    } B;
} hw_pcie_lcr2_t;
#endif

/*
 * constants & macros for entire PCIE_LCR2 register
 */
#define HW_PCIE_LCR2_ADDR      (REGS_PCIE_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_LCR2           (*(volatile hw_pcie_lcr2_t *) HW_PCIE_LCR2_ADDR)
#define HW_PCIE_LCR2_RD()      (HW_PCIE_LCR2.U)
#define HW_PCIE_LCR2_WR(v)     (HW_PCIE_LCR2.U = (v))
#define HW_PCIE_LCR2_SET(v)    (HW_PCIE_LCR2_WR(HW_PCIE_LCR2_RD() |  (v)))
#define HW_PCIE_LCR2_CLR(v)    (HW_PCIE_LCR2_WR(HW_PCIE_LCR2_RD() & ~(v)))
#define HW_PCIE_LCR2_TOG(v)    (HW_PCIE_LCR2_WR(HW_PCIE_LCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_LCR2 bitfields
 */

/* --- Register HW_PCIE_LCR2, field CROSSLINK_SUPPORTED */

#define BP_PCIE_LCR2_CROSSLINK_SUPPORTED      8
#define BM_PCIE_LCR2_CROSSLINK_SUPPORTED      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR2_CROSSLINK_SUPPORTED(v)   ((((reg32_t) v) << 8) & BM_PCIE_LCR2_CROSSLINK_SUPPORTED)
#else
#define BF_PCIE_LCR2_CROSSLINK_SUPPORTED(v)   (((v) << 8) & BM_PCIE_LCR2_CROSSLINK_SUPPORTED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR2_CROSSLINK_SUPPORTED(v)   BF_CS1(PCIE_LCR2, CROSSLINK_SUPPORTED, v)
#endif

/* --- Register HW_PCIE_LCR2, field SUPPORTED_LINK_SPEEDS_VECTOR */

#define BP_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR      1
#define BM_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR      0x000000fe

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR(v)   ((((reg32_t) v) << 1) & BM_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR)
#else
#define BF_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR(v)   (((v) << 1) & BM_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR(v)   BF_CS1(PCIE_LCR2, SUPPORTED_LINK_SPEEDS_VECTOR, v)
#endif

/*
 * HW_PCIE_LCSR2 - Link Control and Status 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 10;
        unsigned LINK_EQUALIZATION_REQUEST : 1;
        unsigned EQUALIZATION_PHASE_3_SUCCESSFUL : 1;
        unsigned EQUALIZATION_PHASE_2_SUCCESSFUL : 1;
        unsigned EQUALIZATION_PHASE_1_SUCCESSFUL : 1;
        unsigned EQUALIZATION_COMPLETE : 1;
        unsigned CURRENT_DEEMPHASIS_LEVEL : 1;
        unsigned COMPLIANCE_PRE_SET_DEEMPHASIS : 4;
        unsigned COMPLIANCE_SOS : 1;
        unsigned ENTER_MODIFIED_COMPLIANCE : 1;
        unsigned TRANSMIT_MARGIN : 3;
        unsigned SELECTABLE_DEEMPHASIS : 1;
        unsigned HARDWARE_AUTONOMOUS_SPEED_DISABLE : 1;
        unsigned ENTER_COMPLIANCE : 1;
        unsigned TARGET_LINK_SPEED : 4;

    } B;
} hw_pcie_lcsr2_t;
#endif

/*
 * constants & macros for entire PCIE_LCSR2 register
 */
#define HW_PCIE_LCSR2_ADDR      (REGS_PCIE_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_LCSR2           (*(volatile hw_pcie_lcsr2_t *) HW_PCIE_LCSR2_ADDR)
#define HW_PCIE_LCSR2_RD()      (HW_PCIE_LCSR2.U)
#define HW_PCIE_LCSR2_WR(v)     (HW_PCIE_LCSR2.U = (v))
#define HW_PCIE_LCSR2_SET(v)    (HW_PCIE_LCSR2_WR(HW_PCIE_LCSR2_RD() |  (v)))
#define HW_PCIE_LCSR2_CLR(v)    (HW_PCIE_LCSR2_WR(HW_PCIE_LCSR2_RD() & ~(v)))
#define HW_PCIE_LCSR2_TOG(v)    (HW_PCIE_LCSR2_WR(HW_PCIE_LCSR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_LCSR2 bitfields
 */

/* --- Register HW_PCIE_LCSR2, field LINK_EQUALIZATION_REQUEST */

#define BP_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST      21
#define BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)   ((((reg32_t) v) << 21) & BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST)
#else
#define BF_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)   (((v) << 21) & BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)   BF_CS1(PCIE_LCSR2, LINK_EQUALIZATION_REQUEST, v)
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_3_SUCCESSFUL */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL      20
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)   ((((reg32_t) v) << 20) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL)
#else
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)   (((v) << 20) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)   BF_CS1(PCIE_LCSR2, EQUALIZATION_PHASE_3_SUCCESSFUL, v)
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_2_SUCCESSFUL */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL      19
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)   ((((reg32_t) v) << 19) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL)
#else
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)   (((v) << 19) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)   BF_CS1(PCIE_LCSR2, EQUALIZATION_PHASE_2_SUCCESSFUL, v)
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_1_SUCCESSFUL */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL      18
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)   ((((reg32_t) v) << 18) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL)
#else
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)   (((v) << 18) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)   BF_CS1(PCIE_LCSR2, EQUALIZATION_PHASE_1_SUCCESSFUL, v)
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_COMPLETE */

#define BP_PCIE_LCSR2_EQUALIZATION_COMPLETE      17
#define BM_PCIE_LCSR2_EQUALIZATION_COMPLETE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)   ((((reg32_t) v) << 17) & BM_PCIE_LCSR2_EQUALIZATION_COMPLETE)
#else
#define BF_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)   (((v) << 17) & BM_PCIE_LCSR2_EQUALIZATION_COMPLETE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)   BF_CS1(PCIE_LCSR2, EQUALIZATION_COMPLETE, v)
#endif

/* --- Register HW_PCIE_LCSR2, field CURRENT_DEEMPHASIS_LEVEL */

#define BP_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL      16
#define BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)   ((((reg32_t) v) << 16) & BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL)
#else
#define BF_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)   (((v) << 16) & BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)   BF_CS1(PCIE_LCSR2, CURRENT_DEEMPHASIS_LEVEL, v)
#endif

/* --- Register HW_PCIE_LCSR2, field COMPLIANCE_PRE_SET_DEEMPHASIS */

#define BP_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS      12
#define BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)   ((((reg32_t) v) << 12) & BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS)
#else
#define BF_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)   (((v) << 12) & BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)   BF_CS1(PCIE_LCSR2, COMPLIANCE_PRE_SET_DEEMPHASIS, v)
#endif

/* --- Register HW_PCIE_LCSR2, field COMPLIANCE_SOS */

#define BP_PCIE_LCSR2_COMPLIANCE_SOS      11
#define BM_PCIE_LCSR2_COMPLIANCE_SOS      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_COMPLIANCE_SOS(v)   ((((reg32_t) v) << 11) & BM_PCIE_LCSR2_COMPLIANCE_SOS)
#else
#define BF_PCIE_LCSR2_COMPLIANCE_SOS(v)   (((v) << 11) & BM_PCIE_LCSR2_COMPLIANCE_SOS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_COMPLIANCE_SOS(v)   BF_CS1(PCIE_LCSR2, COMPLIANCE_SOS, v)
#endif

/* --- Register HW_PCIE_LCSR2, field ENTER_MODIFIED_COMPLIANCE */

#define BP_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE      10
#define BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)   ((((reg32_t) v) << 10) & BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE)
#else
#define BF_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)   (((v) << 10) & BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)   BF_CS1(PCIE_LCSR2, ENTER_MODIFIED_COMPLIANCE, v)
#endif

/* --- Register HW_PCIE_LCSR2, field TRANSMIT_MARGIN */

#define BP_PCIE_LCSR2_TRANSMIT_MARGIN      7
#define BM_PCIE_LCSR2_TRANSMIT_MARGIN      0x00000380

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_TRANSMIT_MARGIN(v)   ((((reg32_t) v) << 7) & BM_PCIE_LCSR2_TRANSMIT_MARGIN)
#else
#define BF_PCIE_LCSR2_TRANSMIT_MARGIN(v)   (((v) << 7) & BM_PCIE_LCSR2_TRANSMIT_MARGIN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_TRANSMIT_MARGIN(v)   BF_CS1(PCIE_LCSR2, TRANSMIT_MARGIN, v)
#endif

/* --- Register HW_PCIE_LCSR2, field SELECTABLE_DEEMPHASIS */

#define BP_PCIE_LCSR2_SELECTABLE_DEEMPHASIS      6
#define BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)   ((((reg32_t) v) << 6) & BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS)
#else
#define BF_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)   (((v) << 6) & BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)   BF_CS1(PCIE_LCSR2, SELECTABLE_DEEMPHASIS, v)
#endif

/* --- Register HW_PCIE_LCSR2, field HARDWARE_AUTONOMOUS_SPEED_DISABLE */

#define BP_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE      5
#define BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)   ((((reg32_t) v) << 5) & BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE)
#else
#define BF_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)   (((v) << 5) & BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)   BF_CS1(PCIE_LCSR2, HARDWARE_AUTONOMOUS_SPEED_DISABLE, v)
#endif

/* --- Register HW_PCIE_LCSR2, field ENTER_COMPLIANCE */

#define BP_PCIE_LCSR2_ENTER_COMPLIANCE      4
#define BM_PCIE_LCSR2_ENTER_COMPLIANCE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_ENTER_COMPLIANCE(v)   ((((reg32_t) v) << 4) & BM_PCIE_LCSR2_ENTER_COMPLIANCE)
#else
#define BF_PCIE_LCSR2_ENTER_COMPLIANCE(v)   (((v) << 4) & BM_PCIE_LCSR2_ENTER_COMPLIANCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_ENTER_COMPLIANCE(v)   BF_CS1(PCIE_LCSR2, ENTER_COMPLIANCE, v)
#endif

/* --- Register HW_PCIE_LCSR2, field TARGET_LINK_SPEED */

#define BP_PCIE_LCSR2_TARGET_LINK_SPEED      0
#define BM_PCIE_LCSR2_TARGET_LINK_SPEED      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_LCSR2_TARGET_LINK_SPEED(v)   ((((reg32_t) v) << 0) & BM_PCIE_LCSR2_TARGET_LINK_SPEED)
#else
#define BF_PCIE_LCSR2_TARGET_LINK_SPEED(v)   (((v) << 0) & BM_PCIE_LCSR2_TARGET_LINK_SPEED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_LCSR2_TARGET_LINK_SPEED(v)   BF_CS1(PCIE_LCSR2, TARGET_LINK_SPEED, v)
#endif

/*
 * HW_PCIE_UESR - Uncorrectable Error Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11;
        unsigned UNSUPPORTED_REQUEST_ERROR_STATUS : 1;
        unsigned ECRC_ERROR_STATUS : 1;
        unsigned MALFORMED_TLP_STATUS : 1;
        unsigned RECEIVER_OVERFLOW_STATUS : 1;
        unsigned UNEXPECTED_COMPLETION_STATUS : 1;
        unsigned COMPLETER_ABORT_STATUS : 1;
        unsigned COMPLETION_TIMEOUT_STATUS : 1;
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_STATUS : 1;
        unsigned POISONED_TLP_STATUS : 1;
        unsigned RESERVED1 : 6;
        unsigned SURPRISE_DOWN_ERROR_STATUS_ : 1;
        unsigned DATA_LINK_PROTOCOL_ERROR_STATUS : 1;
        unsigned RESERVED2 : 3;
        unsigned UNDEFINED : 1;

    } B;
} hw_pcie_uesr_t;
#endif

/*
 * constants & macros for entire PCIE_UESR register
 */
#define HW_PCIE_UESR_ADDR      (REGS_PCIE_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_UESR           (*(volatile hw_pcie_uesr_t *) HW_PCIE_UESR_ADDR)
#define HW_PCIE_UESR_RD()      (HW_PCIE_UESR.U)
#define HW_PCIE_UESR_WR(v)     (HW_PCIE_UESR.U = (v))
#define HW_PCIE_UESR_SET(v)    (HW_PCIE_UESR_WR(HW_PCIE_UESR_RD() |  (v)))
#define HW_PCIE_UESR_CLR(v)    (HW_PCIE_UESR_WR(HW_PCIE_UESR_RD() & ~(v)))
#define HW_PCIE_UESR_TOG(v)    (HW_PCIE_UESR_WR(HW_PCIE_UESR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_UESR bitfields
 */

/* --- Register HW_PCIE_UESR, field UNSUPPORTED_REQUEST_ERROR_STATUS */

#define BP_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS      20
#define BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)   ((((reg32_t) v) << 20) & BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS)
#else
#define BF_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)   (((v) << 20) & BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)   BF_CS1(PCIE_UESR, UNSUPPORTED_REQUEST_ERROR_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field ECRC_ERROR_STATUS */

#define BP_PCIE_UESR_ECRC_ERROR_STATUS      19
#define BM_PCIE_UESR_ECRC_ERROR_STATUS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_ECRC_ERROR_STATUS(v)   ((((reg32_t) v) << 19) & BM_PCIE_UESR_ECRC_ERROR_STATUS)
#else
#define BF_PCIE_UESR_ECRC_ERROR_STATUS(v)   (((v) << 19) & BM_PCIE_UESR_ECRC_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_ECRC_ERROR_STATUS(v)   BF_CS1(PCIE_UESR, ECRC_ERROR_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field MALFORMED_TLP_STATUS */

#define BP_PCIE_UESR_MALFORMED_TLP_STATUS      18
#define BM_PCIE_UESR_MALFORMED_TLP_STATUS      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_MALFORMED_TLP_STATUS(v)   ((((reg32_t) v) << 18) & BM_PCIE_UESR_MALFORMED_TLP_STATUS)
#else
#define BF_PCIE_UESR_MALFORMED_TLP_STATUS(v)   (((v) << 18) & BM_PCIE_UESR_MALFORMED_TLP_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_MALFORMED_TLP_STATUS(v)   BF_CS1(PCIE_UESR, MALFORMED_TLP_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field RECEIVER_OVERFLOW_STATUS */

#define BP_PCIE_UESR_RECEIVER_OVERFLOW_STATUS      17
#define BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)   ((((reg32_t) v) << 17) & BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS)
#else
#define BF_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)   (((v) << 17) & BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)   BF_CS1(PCIE_UESR, RECEIVER_OVERFLOW_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field UNEXPECTED_COMPLETION_STATUS */

#define BP_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS      16
#define BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)   ((((reg32_t) v) << 16) & BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS)
#else
#define BF_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)   (((v) << 16) & BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)   BF_CS1(PCIE_UESR, UNEXPECTED_COMPLETION_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field COMPLETER_ABORT_STATUS */

#define BP_PCIE_UESR_COMPLETER_ABORT_STATUS      15
#define BM_PCIE_UESR_COMPLETER_ABORT_STATUS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_COMPLETER_ABORT_STATUS(v)   ((((reg32_t) v) << 15) & BM_PCIE_UESR_COMPLETER_ABORT_STATUS)
#else
#define BF_PCIE_UESR_COMPLETER_ABORT_STATUS(v)   (((v) << 15) & BM_PCIE_UESR_COMPLETER_ABORT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_COMPLETER_ABORT_STATUS(v)   BF_CS1(PCIE_UESR, COMPLETER_ABORT_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field COMPLETION_TIMEOUT_STATUS */

#define BP_PCIE_UESR_COMPLETION_TIMEOUT_STATUS      14
#define BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)   ((((reg32_t) v) << 14) & BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS)
#else
#define BF_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)   (((v) << 14) & BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)   BF_CS1(PCIE_UESR, COMPLETION_TIMEOUT_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field FLOW_CONTROL_PROTOCOL_ERROR_STATUS */

#define BP_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS      13
#define BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)   ((((reg32_t) v) << 13) & BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS)
#else
#define BF_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)   (((v) << 13) & BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)   BF_CS1(PCIE_UESR, FLOW_CONTROL_PROTOCOL_ERROR_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field POISONED_TLP_STATUS */

#define BP_PCIE_UESR_POISONED_TLP_STATUS      12
#define BM_PCIE_UESR_POISONED_TLP_STATUS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_POISONED_TLP_STATUS(v)   ((((reg32_t) v) << 12) & BM_PCIE_UESR_POISONED_TLP_STATUS)
#else
#define BF_PCIE_UESR_POISONED_TLP_STATUS(v)   (((v) << 12) & BM_PCIE_UESR_POISONED_TLP_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_POISONED_TLP_STATUS(v)   BF_CS1(PCIE_UESR, POISONED_TLP_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field SURPRISE_DOWN_ERROR_STATUS_ */

#define BP_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_      5
#define BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_(v)   ((((reg32_t) v) << 5) & BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_)
#else
#define BF_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_(v)   (((v) << 5) & BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS_(v)   BF_CS1(PCIE_UESR, SURPRISE_DOWN_ERROR_STATUS_, v)
#endif

/* --- Register HW_PCIE_UESR, field DATA_LINK_PROTOCOL_ERROR_STATUS */

#define BP_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS      4
#define BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)   ((((reg32_t) v) << 4) & BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS)
#else
#define BF_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)   (((v) << 4) & BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)   BF_CS1(PCIE_UESR, DATA_LINK_PROTOCOL_ERROR_STATUS, v)
#endif

/* --- Register HW_PCIE_UESR, field UNDEFINED */

#define BP_PCIE_UESR_UNDEFINED      0
#define BM_PCIE_UESR_UNDEFINED      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESR_UNDEFINED(v)   ((((reg32_t) v) << 0) & BM_PCIE_UESR_UNDEFINED)
#else
#define BF_PCIE_UESR_UNDEFINED(v)   (((v) << 0) & BM_PCIE_UESR_UNDEFINED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESR_UNDEFINED(v)   BF_CS1(PCIE_UESR, UNDEFINED, v)
#endif

/*
 * HW_PCIE_UEMR - Uncorrectable Error Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11;
        unsigned UNSUPPORTED_REQUEST_ERROR_MASK : 1;
        unsigned ECRC_ERROR_MASK : 1;
        unsigned MALFORMED_TLP_MASK : 1;
        unsigned RECEIVER_OVERFLOW_MASK : 1;
        unsigned UNEXPECTED_COMPLETION_MASK : 1;
        unsigned COMPLETER_ABORT_MASK : 1;
        unsigned COMPLETION_TIMEOUT_MASK : 1;
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_MASK : 1;
        unsigned POISONED_TLP_MASK : 1;
        unsigned RESERVED1 : 6;
        unsigned SURPRISE_DOWN_ERROR_MASK : 1;
        unsigned DATA_LINK_PROTOCOL_ERROR_MASK : 1;
        unsigned RESERVED2 : 3;
        unsigned UNDEFINED : 1;

    } B;
} hw_pcie_uemr_t;
#endif

/*
 * constants & macros for entire PCIE_UEMR register
 */
#define HW_PCIE_UEMR_ADDR      (REGS_PCIE_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_UEMR           (*(volatile hw_pcie_uemr_t *) HW_PCIE_UEMR_ADDR)
#define HW_PCIE_UEMR_RD()      (HW_PCIE_UEMR.U)
#define HW_PCIE_UEMR_WR(v)     (HW_PCIE_UEMR.U = (v))
#define HW_PCIE_UEMR_SET(v)    (HW_PCIE_UEMR_WR(HW_PCIE_UEMR_RD() |  (v)))
#define HW_PCIE_UEMR_CLR(v)    (HW_PCIE_UEMR_WR(HW_PCIE_UEMR_RD() & ~(v)))
#define HW_PCIE_UEMR_TOG(v)    (HW_PCIE_UEMR_WR(HW_PCIE_UEMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_UEMR bitfields
 */

/* --- Register HW_PCIE_UEMR, field UNSUPPORTED_REQUEST_ERROR_MASK */

#define BP_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK      20
#define BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)   ((((reg32_t) v) << 20) & BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK)
#else
#define BF_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)   (((v) << 20) & BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)   BF_CS1(PCIE_UEMR, UNSUPPORTED_REQUEST_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field ECRC_ERROR_MASK */

#define BP_PCIE_UEMR_ECRC_ERROR_MASK      19
#define BM_PCIE_UEMR_ECRC_ERROR_MASK      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_ECRC_ERROR_MASK(v)   ((((reg32_t) v) << 19) & BM_PCIE_UEMR_ECRC_ERROR_MASK)
#else
#define BF_PCIE_UEMR_ECRC_ERROR_MASK(v)   (((v) << 19) & BM_PCIE_UEMR_ECRC_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_ECRC_ERROR_MASK(v)   BF_CS1(PCIE_UEMR, ECRC_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field MALFORMED_TLP_MASK */

#define BP_PCIE_UEMR_MALFORMED_TLP_MASK      18
#define BM_PCIE_UEMR_MALFORMED_TLP_MASK      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_MALFORMED_TLP_MASK(v)   ((((reg32_t) v) << 18) & BM_PCIE_UEMR_MALFORMED_TLP_MASK)
#else
#define BF_PCIE_UEMR_MALFORMED_TLP_MASK(v)   (((v) << 18) & BM_PCIE_UEMR_MALFORMED_TLP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_MALFORMED_TLP_MASK(v)   BF_CS1(PCIE_UEMR, MALFORMED_TLP_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field RECEIVER_OVERFLOW_MASK */

#define BP_PCIE_UEMR_RECEIVER_OVERFLOW_MASK      17
#define BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)   ((((reg32_t) v) << 17) & BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK)
#else
#define BF_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)   (((v) << 17) & BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)   BF_CS1(PCIE_UEMR, RECEIVER_OVERFLOW_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field UNEXPECTED_COMPLETION_MASK */

#define BP_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK      16
#define BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)   ((((reg32_t) v) << 16) & BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK)
#else
#define BF_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)   (((v) << 16) & BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)   BF_CS1(PCIE_UEMR, UNEXPECTED_COMPLETION_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field COMPLETER_ABORT_MASK */

#define BP_PCIE_UEMR_COMPLETER_ABORT_MASK      15
#define BM_PCIE_UEMR_COMPLETER_ABORT_MASK      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_COMPLETER_ABORT_MASK(v)   ((((reg32_t) v) << 15) & BM_PCIE_UEMR_COMPLETER_ABORT_MASK)
#else
#define BF_PCIE_UEMR_COMPLETER_ABORT_MASK(v)   (((v) << 15) & BM_PCIE_UEMR_COMPLETER_ABORT_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_COMPLETER_ABORT_MASK(v)   BF_CS1(PCIE_UEMR, COMPLETER_ABORT_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field COMPLETION_TIMEOUT_MASK */

#define BP_PCIE_UEMR_COMPLETION_TIMEOUT_MASK      14
#define BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)   ((((reg32_t) v) << 14) & BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK)
#else
#define BF_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)   (((v) << 14) & BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)   BF_CS1(PCIE_UEMR, COMPLETION_TIMEOUT_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field FLOW_CONTROL_PROTOCOL_ERROR_MASK */

#define BP_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK      13
#define BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)   ((((reg32_t) v) << 13) & BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK)
#else
#define BF_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)   (((v) << 13) & BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)   BF_CS1(PCIE_UEMR, FLOW_CONTROL_PROTOCOL_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field POISONED_TLP_MASK */

#define BP_PCIE_UEMR_POISONED_TLP_MASK      12
#define BM_PCIE_UEMR_POISONED_TLP_MASK      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_POISONED_TLP_MASK(v)   ((((reg32_t) v) << 12) & BM_PCIE_UEMR_POISONED_TLP_MASK)
#else
#define BF_PCIE_UEMR_POISONED_TLP_MASK(v)   (((v) << 12) & BM_PCIE_UEMR_POISONED_TLP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_POISONED_TLP_MASK(v)   BF_CS1(PCIE_UEMR, POISONED_TLP_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field SURPRISE_DOWN_ERROR_MASK */

#define BP_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK      5
#define BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)   ((((reg32_t) v) << 5) & BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK)
#else
#define BF_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)   (((v) << 5) & BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)   BF_CS1(PCIE_UEMR, SURPRISE_DOWN_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field DATA_LINK_PROTOCOL_ERROR_MASK */

#define BP_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK      4
#define BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)   ((((reg32_t) v) << 4) & BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK)
#else
#define BF_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)   (((v) << 4) & BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)   BF_CS1(PCIE_UEMR, DATA_LINK_PROTOCOL_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_UEMR, field UNDEFINED */

#define BP_PCIE_UEMR_UNDEFINED      0
#define BM_PCIE_UEMR_UNDEFINED      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UEMR_UNDEFINED(v)   ((((reg32_t) v) << 0) & BM_PCIE_UEMR_UNDEFINED)
#else
#define BF_PCIE_UEMR_UNDEFINED(v)   (((v) << 0) & BM_PCIE_UEMR_UNDEFINED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UEMR_UNDEFINED(v)   BF_CS1(PCIE_UEMR, UNDEFINED, v)
#endif

/*
 * HW_PCIE_UESEVR - Uncorrectable Error Severity Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11;
        unsigned UNSUPPORTED_REQUEST_ERROR_SEVERITY : 1;
        unsigned ECRC_ERROR_SEVERITY : 1;
        unsigned MALFORMED_TLP_SEVERITY : 1;
        unsigned RECEIVER_OVERFLOW_SEVERITY : 1;
        unsigned UNEXPECTED_COMPLETION_SEVERITY : 1;
        unsigned COMPLETER_ABORT_SEVERITY : 1;
        unsigned COMPLETION_TIMEOUT_SEVERITY : 1;
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY : 1;
        unsigned POISONED_TLP_SEVERITY : 1;
        unsigned RESERVED1 : 6;
        unsigned SURPRISE_DOWN_ERROR_SEVERITY : 1;
        unsigned DATA_LINK_PROTOCOL_ERROR_SEVERITY : 1;
        unsigned RESERVED2 : 3;
        unsigned UNDEFINED : 1;

    } B;
} hw_pcie_uesevr_t;
#endif

/*
 * constants & macros for entire PCIE_UESEVR register
 */
#define HW_PCIE_UESEVR_ADDR      (REGS_PCIE_BASE + 0x10c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_UESEVR           (*(volatile hw_pcie_uesevr_t *) HW_PCIE_UESEVR_ADDR)
#define HW_PCIE_UESEVR_RD()      (HW_PCIE_UESEVR.U)
#define HW_PCIE_UESEVR_WR(v)     (HW_PCIE_UESEVR.U = (v))
#define HW_PCIE_UESEVR_SET(v)    (HW_PCIE_UESEVR_WR(HW_PCIE_UESEVR_RD() |  (v)))
#define HW_PCIE_UESEVR_CLR(v)    (HW_PCIE_UESEVR_WR(HW_PCIE_UESEVR_RD() & ~(v)))
#define HW_PCIE_UESEVR_TOG(v)    (HW_PCIE_UESEVR_WR(HW_PCIE_UESEVR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_UESEVR bitfields
 */

/* --- Register HW_PCIE_UESEVR, field UNSUPPORTED_REQUEST_ERROR_SEVERITY */

#define BP_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY      20
#define BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)   ((((reg32_t) v) << 20) & BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY)
#else
#define BF_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)   (((v) << 20) & BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)   BF_CS1(PCIE_UESEVR, UNSUPPORTED_REQUEST_ERROR_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field ECRC_ERROR_SEVERITY */

#define BP_PCIE_UESEVR_ECRC_ERROR_SEVERITY      19
#define BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)   ((((reg32_t) v) << 19) & BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY)
#else
#define BF_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)   (((v) << 19) & BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)   BF_CS1(PCIE_UESEVR, ECRC_ERROR_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field MALFORMED_TLP_SEVERITY */

#define BP_PCIE_UESEVR_MALFORMED_TLP_SEVERITY      18
#define BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)   ((((reg32_t) v) << 18) & BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY)
#else
#define BF_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)   (((v) << 18) & BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)   BF_CS1(PCIE_UESEVR, MALFORMED_TLP_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field RECEIVER_OVERFLOW_SEVERITY */

#define BP_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY      17
#define BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)   ((((reg32_t) v) << 17) & BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY)
#else
#define BF_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)   (((v) << 17) & BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)   BF_CS1(PCIE_UESEVR, RECEIVER_OVERFLOW_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field UNEXPECTED_COMPLETION_SEVERITY */

#define BP_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY      16
#define BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)   ((((reg32_t) v) << 16) & BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY)
#else
#define BF_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)   (((v) << 16) & BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)   BF_CS1(PCIE_UESEVR, UNEXPECTED_COMPLETION_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field COMPLETER_ABORT_SEVERITY */

#define BP_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY      15
#define BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)   ((((reg32_t) v) << 15) & BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY)
#else
#define BF_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)   (((v) << 15) & BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)   BF_CS1(PCIE_UESEVR, COMPLETER_ABORT_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field COMPLETION_TIMEOUT_SEVERITY */

#define BP_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY      14
#define BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)   ((((reg32_t) v) << 14) & BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY)
#else
#define BF_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)   (((v) << 14) & BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)   BF_CS1(PCIE_UESEVR, COMPLETION_TIMEOUT_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY */

#define BP_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY      13
#define BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)   ((((reg32_t) v) << 13) & BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY)
#else
#define BF_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)   (((v) << 13) & BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)   BF_CS1(PCIE_UESEVR, FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field POISONED_TLP_SEVERITY */

#define BP_PCIE_UESEVR_POISONED_TLP_SEVERITY      12
#define BM_PCIE_UESEVR_POISONED_TLP_SEVERITY      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)   ((((reg32_t) v) << 12) & BM_PCIE_UESEVR_POISONED_TLP_SEVERITY)
#else
#define BF_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)   (((v) << 12) & BM_PCIE_UESEVR_POISONED_TLP_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)   BF_CS1(PCIE_UESEVR, POISONED_TLP_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field SURPRISE_DOWN_ERROR_SEVERITY */

#define BP_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY      5
#define BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)   ((((reg32_t) v) << 5) & BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY)
#else
#define BF_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)   (((v) << 5) & BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)   BF_CS1(PCIE_UESEVR, SURPRISE_DOWN_ERROR_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field DATA_LINK_PROTOCOL_ERROR_SEVERITY */

#define BP_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY      4
#define BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)   ((((reg32_t) v) << 4) & BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY)
#else
#define BF_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)   (((v) << 4) & BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)   BF_CS1(PCIE_UESEVR, DATA_LINK_PROTOCOL_ERROR_SEVERITY, v)
#endif

/* --- Register HW_PCIE_UESEVR, field UNDEFINED */

#define BP_PCIE_UESEVR_UNDEFINED      0
#define BM_PCIE_UESEVR_UNDEFINED      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_UESEVR_UNDEFINED(v)   ((((reg32_t) v) << 0) & BM_PCIE_UESEVR_UNDEFINED)
#else
#define BF_PCIE_UESEVR_UNDEFINED(v)   (((v) << 0) & BM_PCIE_UESEVR_UNDEFINED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_UESEVR_UNDEFINED(v)   BF_CS1(PCIE_UESEVR, UNDEFINED, v)
#endif

/*
 * HW_PCIE_CESR - Correctable Error Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned ADVISORY_NON_FATAL_ERROR_STATUS : 1;
        unsigned REPLY_TIMER_TIMEOUT_STATUS : 1;
        unsigned RESERVED1 : 3;
        unsigned REPLAY_NUM_ROLLOVER_STATUS : 1;
        unsigned BAD_DLLP_STATUS : 1;
        unsigned BAD_TLP_STATUS : 1;
        unsigned RESERVED2 : 5;
        unsigned RECEIVER_ERROR_STATUS : 1;

    } B;
} hw_pcie_cesr_t;
#endif

/*
 * constants & macros for entire PCIE_CESR register
 */
#define HW_PCIE_CESR_ADDR      (REGS_PCIE_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_CESR           (*(volatile hw_pcie_cesr_t *) HW_PCIE_CESR_ADDR)
#define HW_PCIE_CESR_RD()      (HW_PCIE_CESR.U)
#define HW_PCIE_CESR_WR(v)     (HW_PCIE_CESR.U = (v))
#define HW_PCIE_CESR_SET(v)    (HW_PCIE_CESR_WR(HW_PCIE_CESR_RD() |  (v)))
#define HW_PCIE_CESR_CLR(v)    (HW_PCIE_CESR_WR(HW_PCIE_CESR_RD() & ~(v)))
#define HW_PCIE_CESR_TOG(v)    (HW_PCIE_CESR_WR(HW_PCIE_CESR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_CESR bitfields
 */

/* --- Register HW_PCIE_CESR, field ADVISORY_NON_FATAL_ERROR_STATUS */

#define BP_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS      13
#define BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)   ((((reg32_t) v) << 13) & BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS)
#else
#define BF_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)   (((v) << 13) & BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)   BF_CS1(PCIE_CESR, ADVISORY_NON_FATAL_ERROR_STATUS, v)
#endif

/* --- Register HW_PCIE_CESR, field REPLY_TIMER_TIMEOUT_STATUS */

#define BP_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS      12
#define BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)   ((((reg32_t) v) << 12) & BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS)
#else
#define BF_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)   (((v) << 12) & BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)   BF_CS1(PCIE_CESR, REPLY_TIMER_TIMEOUT_STATUS, v)
#endif

/* --- Register HW_PCIE_CESR, field REPLAY_NUM_ROLLOVER_STATUS */

#define BP_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS      8
#define BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)   ((((reg32_t) v) << 8) & BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS)
#else
#define BF_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)   (((v) << 8) & BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)   BF_CS1(PCIE_CESR, REPLAY_NUM_ROLLOVER_STATUS, v)
#endif

/* --- Register HW_PCIE_CESR, field BAD_DLLP_STATUS */

#define BP_PCIE_CESR_BAD_DLLP_STATUS      7
#define BM_PCIE_CESR_BAD_DLLP_STATUS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_BAD_DLLP_STATUS(v)   ((((reg32_t) v) << 7) & BM_PCIE_CESR_BAD_DLLP_STATUS)
#else
#define BF_PCIE_CESR_BAD_DLLP_STATUS(v)   (((v) << 7) & BM_PCIE_CESR_BAD_DLLP_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_BAD_DLLP_STATUS(v)   BF_CS1(PCIE_CESR, BAD_DLLP_STATUS, v)
#endif

/* --- Register HW_PCIE_CESR, field BAD_TLP_STATUS */

#define BP_PCIE_CESR_BAD_TLP_STATUS      6
#define BM_PCIE_CESR_BAD_TLP_STATUS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_BAD_TLP_STATUS(v)   ((((reg32_t) v) << 6) & BM_PCIE_CESR_BAD_TLP_STATUS)
#else
#define BF_PCIE_CESR_BAD_TLP_STATUS(v)   (((v) << 6) & BM_PCIE_CESR_BAD_TLP_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_BAD_TLP_STATUS(v)   BF_CS1(PCIE_CESR, BAD_TLP_STATUS, v)
#endif

/* --- Register HW_PCIE_CESR, field RECEIVER_ERROR_STATUS */

#define BP_PCIE_CESR_RECEIVER_ERROR_STATUS      0
#define BM_PCIE_CESR_RECEIVER_ERROR_STATUS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CESR_RECEIVER_ERROR_STATUS(v)   ((((reg32_t) v) << 0) & BM_PCIE_CESR_RECEIVER_ERROR_STATUS)
#else
#define BF_PCIE_CESR_RECEIVER_ERROR_STATUS(v)   (((v) << 0) & BM_PCIE_CESR_RECEIVER_ERROR_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CESR_RECEIVER_ERROR_STATUS(v)   BF_CS1(PCIE_CESR, RECEIVER_ERROR_STATUS, v)
#endif

/*
 * HW_PCIE_CEMR - Correctable Error Mask Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 18;
        unsigned ADVISORY_NON_FATAL_ERROR_MASK : 1;
        unsigned REPLY_TIMER_TIMEOUT_MASK : 1;
        unsigned RESERVED1 : 3;
        unsigned REPLAY_NUM_ROLLOVER_MASK : 1;
        unsigned BAD_DLLP_MASK : 1;
        unsigned BAD_TLP_MASK : 1;
        unsigned RESERVED2 : 5;
        unsigned RECEIVER_ERROR_MASK : 1;

    } B;
} hw_pcie_cemr_t;
#endif

/*
 * constants & macros for entire PCIE_CEMR register
 */
#define HW_PCIE_CEMR_ADDR      (REGS_PCIE_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_CEMR           (*(volatile hw_pcie_cemr_t *) HW_PCIE_CEMR_ADDR)
#define HW_PCIE_CEMR_RD()      (HW_PCIE_CEMR.U)
#define HW_PCIE_CEMR_WR(v)     (HW_PCIE_CEMR.U = (v))
#define HW_PCIE_CEMR_SET(v)    (HW_PCIE_CEMR_WR(HW_PCIE_CEMR_RD() |  (v)))
#define HW_PCIE_CEMR_CLR(v)    (HW_PCIE_CEMR_WR(HW_PCIE_CEMR_RD() & ~(v)))
#define HW_PCIE_CEMR_TOG(v)    (HW_PCIE_CEMR_WR(HW_PCIE_CEMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_CEMR bitfields
 */

/* --- Register HW_PCIE_CEMR, field ADVISORY_NON_FATAL_ERROR_MASK */

#define BP_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK      13
#define BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)   ((((reg32_t) v) << 13) & BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK)
#else
#define BF_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)   (((v) << 13) & BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)   BF_CS1(PCIE_CEMR, ADVISORY_NON_FATAL_ERROR_MASK, v)
#endif

/* --- Register HW_PCIE_CEMR, field REPLY_TIMER_TIMEOUT_MASK */

#define BP_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK      12
#define BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)   ((((reg32_t) v) << 12) & BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK)
#else
#define BF_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)   (((v) << 12) & BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)   BF_CS1(PCIE_CEMR, REPLY_TIMER_TIMEOUT_MASK, v)
#endif

/* --- Register HW_PCIE_CEMR, field REPLAY_NUM_ROLLOVER_MASK */

#define BP_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK      8
#define BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)   ((((reg32_t) v) << 8) & BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK)
#else
#define BF_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)   (((v) << 8) & BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)   BF_CS1(PCIE_CEMR, REPLAY_NUM_ROLLOVER_MASK, v)
#endif

/* --- Register HW_PCIE_CEMR, field BAD_DLLP_MASK */

#define BP_PCIE_CEMR_BAD_DLLP_MASK      7
#define BM_PCIE_CEMR_BAD_DLLP_MASK      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_BAD_DLLP_MASK(v)   ((((reg32_t) v) << 7) & BM_PCIE_CEMR_BAD_DLLP_MASK)
#else
#define BF_PCIE_CEMR_BAD_DLLP_MASK(v)   (((v) << 7) & BM_PCIE_CEMR_BAD_DLLP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_BAD_DLLP_MASK(v)   BF_CS1(PCIE_CEMR, BAD_DLLP_MASK, v)
#endif

/* --- Register HW_PCIE_CEMR, field BAD_TLP_MASK */

#define BP_PCIE_CEMR_BAD_TLP_MASK      6
#define BM_PCIE_CEMR_BAD_TLP_MASK      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_BAD_TLP_MASK(v)   ((((reg32_t) v) << 6) & BM_PCIE_CEMR_BAD_TLP_MASK)
#else
#define BF_PCIE_CEMR_BAD_TLP_MASK(v)   (((v) << 6) & BM_PCIE_CEMR_BAD_TLP_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_BAD_TLP_MASK(v)   BF_CS1(PCIE_CEMR, BAD_TLP_MASK, v)
#endif

/* --- Register HW_PCIE_CEMR, field RECEIVER_ERROR_MASK */

#define BP_PCIE_CEMR_RECEIVER_ERROR_MASK      0
#define BM_PCIE_CEMR_RECEIVER_ERROR_MASK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_CEMR_RECEIVER_ERROR_MASK(v)   ((((reg32_t) v) << 0) & BM_PCIE_CEMR_RECEIVER_ERROR_MASK)
#else
#define BF_PCIE_CEMR_RECEIVER_ERROR_MASK(v)   (((v) << 0) & BM_PCIE_CEMR_RECEIVER_ERROR_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_CEMR_RECEIVER_ERROR_MASK(v)   BF_CS1(PCIE_CEMR, RECEIVER_ERROR_MASK, v)
#endif

/*
 * HW_PCIE_ACCR - Advanced Capabilities and Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 23;
        unsigned ECRC_CHECK_ENABLE : 1;
        unsigned ECRC_CHECK_CAPABLE : 1;
        unsigned ECRC_GENERATION_ENABLE : 1;
        unsigned ECRC_GENERATION_CAPABILITY : 1;
        unsigned FIRST_ERROR_POINTER : 5;

    } B;
} hw_pcie_accr_t;
#endif

/*
 * constants & macros for entire PCIE_ACCR register
 */
#define HW_PCIE_ACCR_ADDR      (REGS_PCIE_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_ACCR           (*(volatile hw_pcie_accr_t *) HW_PCIE_ACCR_ADDR)
#define HW_PCIE_ACCR_RD()      (HW_PCIE_ACCR.U)
#define HW_PCIE_ACCR_WR(v)     (HW_PCIE_ACCR.U = (v))
#define HW_PCIE_ACCR_SET(v)    (HW_PCIE_ACCR_WR(HW_PCIE_ACCR_RD() |  (v)))
#define HW_PCIE_ACCR_CLR(v)    (HW_PCIE_ACCR_WR(HW_PCIE_ACCR_RD() & ~(v)))
#define HW_PCIE_ACCR_TOG(v)    (HW_PCIE_ACCR_WR(HW_PCIE_ACCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_ACCR bitfields
 */

/* --- Register HW_PCIE_ACCR, field ECRC_CHECK_ENABLE */

#define BP_PCIE_ACCR_ECRC_CHECK_ENABLE      8
#define BM_PCIE_ACCR_ECRC_CHECK_ENABLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ACCR_ECRC_CHECK_ENABLE(v)   ((((reg32_t) v) << 8) & BM_PCIE_ACCR_ECRC_CHECK_ENABLE)
#else
#define BF_PCIE_ACCR_ECRC_CHECK_ENABLE(v)   (((v) << 8) & BM_PCIE_ACCR_ECRC_CHECK_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ACCR_ECRC_CHECK_ENABLE(v)   BF_CS1(PCIE_ACCR, ECRC_CHECK_ENABLE, v)
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_CHECK_CAPABLE */

#define BP_PCIE_ACCR_ECRC_CHECK_CAPABLE      7
#define BM_PCIE_ACCR_ECRC_CHECK_CAPABLE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)   ((((reg32_t) v) << 7) & BM_PCIE_ACCR_ECRC_CHECK_CAPABLE)
#else
#define BF_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)   (((v) << 7) & BM_PCIE_ACCR_ECRC_CHECK_CAPABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)   BF_CS1(PCIE_ACCR, ECRC_CHECK_CAPABLE, v)
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_GENERATION_ENABLE */

#define BP_PCIE_ACCR_ECRC_GENERATION_ENABLE      6
#define BM_PCIE_ACCR_ECRC_GENERATION_ENABLE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)   ((((reg32_t) v) << 6) & BM_PCIE_ACCR_ECRC_GENERATION_ENABLE)
#else
#define BF_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)   (((v) << 6) & BM_PCIE_ACCR_ECRC_GENERATION_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)   BF_CS1(PCIE_ACCR, ECRC_GENERATION_ENABLE, v)
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_GENERATION_CAPABILITY */

#define BP_PCIE_ACCR_ECRC_GENERATION_CAPABILITY      5
#define BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)   ((((reg32_t) v) << 5) & BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY)
#else
#define BF_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)   (((v) << 5) & BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)   BF_CS1(PCIE_ACCR, ECRC_GENERATION_CAPABILITY, v)
#endif

/* --- Register HW_PCIE_ACCR, field FIRST_ERROR_POINTER */

#define BP_PCIE_ACCR_FIRST_ERROR_POINTER      0
#define BM_PCIE_ACCR_FIRST_ERROR_POINTER      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ACCR_FIRST_ERROR_POINTER(v)   ((((reg32_t) v) << 0) & BM_PCIE_ACCR_FIRST_ERROR_POINTER)
#else
#define BF_PCIE_ACCR_FIRST_ERROR_POINTER(v)   (((v) << 0) & BM_PCIE_ACCR_FIRST_ERROR_POINTER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ACCR_FIRST_ERROR_POINTER(v)   BF_CS1(PCIE_ACCR, FIRST_ERROR_POINTER, v)
#endif

/*
 * HW_PCIE_HLR - Header Log Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32;

    } B;
} hw_pcie_hlr_t;
#endif

/*
 * constants & macros for entire PCIE_HLR register
 */
#define HW_PCIE_HLR_ADDR      (REGS_PCIE_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_HLR           (*(volatile hw_pcie_hlr_t *) HW_PCIE_HLR_ADDR)
#define HW_PCIE_HLR_RD()      (HW_PCIE_HLR.U)
#define HW_PCIE_HLR_WR(v)     (HW_PCIE_HLR.U = (v))
#define HW_PCIE_HLR_SET(v)    (HW_PCIE_HLR_WR(HW_PCIE_HLR_RD() |  (v)))
#define HW_PCIE_HLR_CLR(v)    (HW_PCIE_HLR_WR(HW_PCIE_HLR_RD() & ~(v)))
#define HW_PCIE_HLR_TOG(v)    (HW_PCIE_HLR_WR(HW_PCIE_HLR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_HLR bitfields
 */

/*
 * HW_PCIE_RECR - Root Error Command Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 29;
        unsigned FATAL_ERROR_REPORTING_ENABLE : 1;
        unsigned NON_FATAL_ERROR_REPORTING_ENABLE : 1;
        unsigned CORRECTABLE_ERROR_REPORTING_ENABLE : 1;

    } B;
} hw_pcie_recr_t;
#endif

/*
 * constants & macros for entire PCIE_RECR register
 */
#define HW_PCIE_RECR_ADDR      (REGS_PCIE_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_RECR           (*(volatile hw_pcie_recr_t *) HW_PCIE_RECR_ADDR)
#define HW_PCIE_RECR_RD()      (HW_PCIE_RECR.U)
#define HW_PCIE_RECR_WR(v)     (HW_PCIE_RECR.U = (v))
#define HW_PCIE_RECR_SET(v)    (HW_PCIE_RECR_WR(HW_PCIE_RECR_RD() |  (v)))
#define HW_PCIE_RECR_CLR(v)    (HW_PCIE_RECR_WR(HW_PCIE_RECR_RD() & ~(v)))
#define HW_PCIE_RECR_TOG(v)    (HW_PCIE_RECR_WR(HW_PCIE_RECR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_RECR bitfields
 */

/* --- Register HW_PCIE_RECR, field FATAL_ERROR_REPORTING_ENABLE */

#define BP_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE      2
#define BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 2) & BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)   (((v) << 2) & BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_RECR, FATAL_ERROR_REPORTING_ENABLE, v)
#endif

/* --- Register HW_PCIE_RECR, field NON_FATAL_ERROR_REPORTING_ENABLE */

#define BP_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE      1
#define BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 1) & BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   (((v) << 1) & BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_RECR, NON_FATAL_ERROR_REPORTING_ENABLE, v)
#endif

/* --- Register HW_PCIE_RECR, field CORRECTABLE_ERROR_REPORTING_ENABLE */

#define BP_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE      0
#define BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE)
#else
#define BF_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   (((v) << 0) & BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   BF_CS1(PCIE_RECR, CORRECTABLE_ERROR_REPORTING_ENABLE, v)
#endif

/*
 * HW_PCIE_RESR - Root Error Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER : 5;
        unsigned RESERVED0 : 20;
        unsigned FATAL_ERROR_MESSAGES_RECEIVED : 1;
        unsigned NON_FATAL_ERROR_MESSAGES_RECEIVED : 1;
        unsigned FIRST_UNCORRECTABLE_FATAL : 1;
        unsigned MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED : 1;
        unsigned ERR_FATAL_NONFATAL_RECEIVED : 1;
        unsigned MULTIPLE_ERR_COR_RECEIVED : 1;
        unsigned ERR_COR_RECEIVED : 1;

    } B;
} hw_pcie_resr_t;
#endif

/*
 * constants & macros for entire PCIE_RESR register
 */
#define HW_PCIE_RESR_ADDR      (REGS_PCIE_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_RESR           (*(volatile hw_pcie_resr_t *) HW_PCIE_RESR_ADDR)
#define HW_PCIE_RESR_RD()      (HW_PCIE_RESR.U)
#define HW_PCIE_RESR_WR(v)     (HW_PCIE_RESR.U = (v))
#define HW_PCIE_RESR_SET(v)    (HW_PCIE_RESR_WR(HW_PCIE_RESR_RD() |  (v)))
#define HW_PCIE_RESR_CLR(v)    (HW_PCIE_RESR_WR(HW_PCIE_RESR_RD() & ~(v)))
#define HW_PCIE_RESR_TOG(v)    (HW_PCIE_RESR_WR(HW_PCIE_RESR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_RESR bitfields
 */

/* --- Register HW_PCIE_RESR, field ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER */

#define BP_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER      27
#define BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER      0xf8000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)   ((((reg32_t) v) << 27) & BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER)
#else
#define BF_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)   (((v) << 27) & BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)   BF_CS1(PCIE_RESR, ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER, v)
#endif

/* --- Register HW_PCIE_RESR, field FATAL_ERROR_MESSAGES_RECEIVED */

#define BP_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED      6
#define BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)   ((((reg32_t) v) << 6) & BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED)
#else
#define BF_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)   (((v) << 6) & BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)   BF_CS1(PCIE_RESR, FATAL_ERROR_MESSAGES_RECEIVED, v)
#endif

/* --- Register HW_PCIE_RESR, field NON_FATAL_ERROR_MESSAGES_RECEIVED */

#define BP_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED      5
#define BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)   ((((reg32_t) v) << 5) & BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED)
#else
#define BF_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)   (((v) << 5) & BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)   BF_CS1(PCIE_RESR, NON_FATAL_ERROR_MESSAGES_RECEIVED, v)
#endif

/* --- Register HW_PCIE_RESR, field FIRST_UNCORRECTABLE_FATAL */

#define BP_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL      4
#define BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)   ((((reg32_t) v) << 4) & BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL)
#else
#define BF_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)   (((v) << 4) & BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)   BF_CS1(PCIE_RESR, FIRST_UNCORRECTABLE_FATAL, v)
#endif

/* --- Register HW_PCIE_RESR, field MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED */

#define BP_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED      3
#define BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)   ((((reg32_t) v) << 3) & BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED)
#else
#define BF_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)   (((v) << 3) & BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)   BF_CS1(PCIE_RESR, MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED, v)
#endif

/* --- Register HW_PCIE_RESR, field ERR_FATAL_NONFATAL_RECEIVED */

#define BP_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED      2
#define BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)   ((((reg32_t) v) << 2) & BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED)
#else
#define BF_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)   (((v) << 2) & BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)   BF_CS1(PCIE_RESR, ERR_FATAL_NONFATAL_RECEIVED, v)
#endif

/* --- Register HW_PCIE_RESR, field MULTIPLE_ERR_COR_RECEIVED */

#define BP_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED      1
#define BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)   ((((reg32_t) v) << 1) & BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED)
#else
#define BF_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)   (((v) << 1) & BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)   BF_CS1(PCIE_RESR, MULTIPLE_ERR_COR_RECEIVED, v)
#endif

/* --- Register HW_PCIE_RESR, field ERR_COR_RECEIVED */

#define BP_PCIE_RESR_ERR_COR_RECEIVED      0
#define BM_PCIE_RESR_ERR_COR_RECEIVED      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_RESR_ERR_COR_RECEIVED(v)   ((((reg32_t) v) << 0) & BM_PCIE_RESR_ERR_COR_RECEIVED)
#else
#define BF_PCIE_RESR_ERR_COR_RECEIVED(v)   (((v) << 0) & BM_PCIE_RESR_ERR_COR_RECEIVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_RESR_ERR_COR_RECEIVED(v)   BF_CS1(PCIE_RESR, ERR_COR_RECEIVED, v)
#endif

/*
 * HW_PCIE_ESIR - Error Source Identification Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERR_FATAL_NONFATAL_SID : 16;
        unsigned ERR_COR_SID : 16;

    } B;
} hw_pcie_esir_t;
#endif

/*
 * constants & macros for entire PCIE_ESIR register
 */
#define HW_PCIE_ESIR_ADDR      (REGS_PCIE_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_ESIR           (*(volatile hw_pcie_esir_t *) HW_PCIE_ESIR_ADDR)
#define HW_PCIE_ESIR_RD()      (HW_PCIE_ESIR.U)
#define HW_PCIE_ESIR_WR(v)     (HW_PCIE_ESIR.U = (v))
#define HW_PCIE_ESIR_SET(v)    (HW_PCIE_ESIR_WR(HW_PCIE_ESIR_RD() |  (v)))
#define HW_PCIE_ESIR_CLR(v)    (HW_PCIE_ESIR_WR(HW_PCIE_ESIR_RD() & ~(v)))
#define HW_PCIE_ESIR_TOG(v)    (HW_PCIE_ESIR_WR(HW_PCIE_ESIR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_ESIR bitfields
 */

/* --- Register HW_PCIE_ESIR, field ERR_FATAL_NONFATAL_SID */

#define BP_PCIE_ESIR_ERR_FATAL_NONFATAL_SID      16
#define BM_PCIE_ESIR_ERR_FATAL_NONFATAL_SID      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ESIR_ERR_FATAL_NONFATAL_SID(v)   ((((reg32_t) v) << 16) & BM_PCIE_ESIR_ERR_FATAL_NONFATAL_SID)
#else
#define BF_PCIE_ESIR_ERR_FATAL_NONFATAL_SID(v)   (((v) << 16) & BM_PCIE_ESIR_ERR_FATAL_NONFATAL_SID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ESIR_ERR_FATAL_NONFATAL_SID(v)   BF_CS1(PCIE_ESIR, ERR_FATAL_NONFATAL_SID, v)
#endif

/* --- Register HW_PCIE_ESIR, field ERR_COR_SID */

#define BP_PCIE_ESIR_ERR_COR_SID      0
#define BM_PCIE_ESIR_ERR_COR_SID      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_ESIR_ERR_COR_SID(v)   ((((reg32_t) v) << 0) & BM_PCIE_ESIR_ERR_COR_SID)
#else
#define BF_PCIE_ESIR_ERR_COR_SID(v)   (((v) << 0) & BM_PCIE_ESIR_ERR_COR_SID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_ESIR_ERR_COR_SID(v)   BF_CS1(PCIE_ESIR, ERR_COR_SID, v)
#endif

/*
 * HW_PCIE_VCECHR - VC Extended Capability Header
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NEXT_CAPABILITY_OFFSET : 12;
        unsigned CAPABILITY_VERSION : 4;
        unsigned EXTENDED_CAPABILITY : 16;

    } B;
} hw_pcie_vcechr_t;
#endif

/*
 * constants & macros for entire PCIE_VCECHR register
 */
#define HW_PCIE_VCECHR_ADDR      (REGS_PCIE_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_VCECHR           (*(volatile hw_pcie_vcechr_t *) HW_PCIE_VCECHR_ADDR)
#define HW_PCIE_VCECHR_RD()      (HW_PCIE_VCECHR.U)
#define HW_PCIE_VCECHR_WR(v)     (HW_PCIE_VCECHR.U = (v))
#define HW_PCIE_VCECHR_SET(v)    (HW_PCIE_VCECHR_WR(HW_PCIE_VCECHR_RD() |  (v)))
#define HW_PCIE_VCECHR_CLR(v)    (HW_PCIE_VCECHR_WR(HW_PCIE_VCECHR_RD() & ~(v)))
#define HW_PCIE_VCECHR_TOG(v)    (HW_PCIE_VCECHR_WR(HW_PCIE_VCECHR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_VCECHR bitfields
 */

/* --- Register HW_PCIE_VCECHR, field NEXT_CAPABILITY_OFFSET */

#define BP_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET      20
#define BM_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET      0xfff00000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET(v)   ((((reg32_t) v) << 20) & BM_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET)
#else
#define BF_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET(v)   (((v) << 20) & BM_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET(v)   BF_CS1(PCIE_VCECHR, NEXT_CAPABILITY_OFFSET, v)
#endif

/* --- Register HW_PCIE_VCECHR, field CAPABILITY_VERSION */

#define BP_PCIE_VCECHR_CAPABILITY_VERSION      16
#define BM_PCIE_VCECHR_CAPABILITY_VERSION      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCECHR_CAPABILITY_VERSION(v)   ((((reg32_t) v) << 16) & BM_PCIE_VCECHR_CAPABILITY_VERSION)
#else
#define BF_PCIE_VCECHR_CAPABILITY_VERSION(v)   (((v) << 16) & BM_PCIE_VCECHR_CAPABILITY_VERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCECHR_CAPABILITY_VERSION(v)   BF_CS1(PCIE_VCECHR, CAPABILITY_VERSION, v)
#endif

/* --- Register HW_PCIE_VCECHR, field EXTENDED_CAPABILITY */

#define BP_PCIE_VCECHR_EXTENDED_CAPABILITY      0
#define BM_PCIE_VCECHR_EXTENDED_CAPABILITY      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCECHR_EXTENDED_CAPABILITY(v)   ((((reg32_t) v) << 0) & BM_PCIE_VCECHR_EXTENDED_CAPABILITY)
#else
#define BF_PCIE_VCECHR_EXTENDED_CAPABILITY(v)   (((v) << 0) & BM_PCIE_VCECHR_EXTENDED_CAPABILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCECHR_EXTENDED_CAPABILITY(v)   BF_CS1(PCIE_VCECHR, EXTENDED_CAPABILITY, v)
#endif

/*
 * HW_PCIE_PVCCR1 - Port VC Capability Register 1
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 20;
        unsigned PORT_ARBITRATION_TABLE_ENTRY_SIZE : 2;
        unsigned REFERENCE_CLOCK : 2;
        unsigned RESERVED1 : 1;
        unsigned LOW_PRIORITY_EXTENDED_VC_COUNT : 3;
        unsigned RESERVED2 : 1;
        unsigned EXTENDED_VC_COUNT : 3;

    } B;
} hw_pcie_pvccr1_t;
#endif

/*
 * constants & macros for entire PCIE_PVCCR1 register
 */
#define HW_PCIE_PVCCR1_ADDR      (REGS_PCIE_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PVCCR1           (*(volatile hw_pcie_pvccr1_t *) HW_PCIE_PVCCR1_ADDR)
#define HW_PCIE_PVCCR1_RD()      (HW_PCIE_PVCCR1.U)
#define HW_PCIE_PVCCR1_WR(v)     (HW_PCIE_PVCCR1.U = (v))
#define HW_PCIE_PVCCR1_SET(v)    (HW_PCIE_PVCCR1_WR(HW_PCIE_PVCCR1_RD() |  (v)))
#define HW_PCIE_PVCCR1_CLR(v)    (HW_PCIE_PVCCR1_WR(HW_PCIE_PVCCR1_RD() & ~(v)))
#define HW_PCIE_PVCCR1_TOG(v)    (HW_PCIE_PVCCR1_WR(HW_PCIE_PVCCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_PVCCR1 bitfields
 */

/* --- Register HW_PCIE_PVCCR1, field PORT_ARBITRATION_TABLE_ENTRY_SIZE */

#define BP_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE      10
#define BM_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE(v)   ((((reg32_t) v) << 10) & BM_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE)
#else
#define BF_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE(v)   (((v) << 10) & BM_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE(v)   BF_CS1(PCIE_PVCCR1, PORT_ARBITRATION_TABLE_ENTRY_SIZE, v)
#endif

/* --- Register HW_PCIE_PVCCR1, field REFERENCE_CLOCK */

#define BP_PCIE_PVCCR1_REFERENCE_CLOCK      8
#define BM_PCIE_PVCCR1_REFERENCE_CLOCK      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR1_REFERENCE_CLOCK(v)   ((((reg32_t) v) << 8) & BM_PCIE_PVCCR1_REFERENCE_CLOCK)
#else
#define BF_PCIE_PVCCR1_REFERENCE_CLOCK(v)   (((v) << 8) & BM_PCIE_PVCCR1_REFERENCE_CLOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR1_REFERENCE_CLOCK(v)   BF_CS1(PCIE_PVCCR1, REFERENCE_CLOCK, v)
#endif

/* --- Register HW_PCIE_PVCCR1, field LOW_PRIORITY_EXTENDED_VC_COUNT */

#define BP_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT      4
#define BM_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT(v)   ((((reg32_t) v) << 4) & BM_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT)
#else
#define BF_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT(v)   (((v) << 4) & BM_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT(v)   BF_CS1(PCIE_PVCCR1, LOW_PRIORITY_EXTENDED_VC_COUNT, v)
#endif

/* --- Register HW_PCIE_PVCCR1, field EXTENDED_VC_COUNT */

#define BP_PCIE_PVCCR1_EXTENDED_VC_COUNT      0
#define BM_PCIE_PVCCR1_EXTENDED_VC_COUNT      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR1_EXTENDED_VC_COUNT(v)   ((((reg32_t) v) << 0) & BM_PCIE_PVCCR1_EXTENDED_VC_COUNT)
#else
#define BF_PCIE_PVCCR1_EXTENDED_VC_COUNT(v)   (((v) << 0) & BM_PCIE_PVCCR1_EXTENDED_VC_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR1_EXTENDED_VC_COUNT(v)   BF_CS1(PCIE_PVCCR1, EXTENDED_VC_COUNT, v)
#endif

/*
 * HW_PCIE_PVCCR2 - Port VC Capability Register 2
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VC_ARBITRATION_TABLE_OFFSET : 8;
        unsigned RESERVED0 : 16;
        unsigned VC_ARBITRATION_CAPABILITY : 8;

    } B;
} hw_pcie_pvccr2_t;
#endif

/*
 * constants & macros for entire PCIE_PVCCR2 register
 */
#define HW_PCIE_PVCCR2_ADDR      (REGS_PCIE_BASE + 0x148)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PVCCR2           (*(volatile hw_pcie_pvccr2_t *) HW_PCIE_PVCCR2_ADDR)
#define HW_PCIE_PVCCR2_RD()      (HW_PCIE_PVCCR2.U)
#define HW_PCIE_PVCCR2_WR(v)     (HW_PCIE_PVCCR2.U = (v))
#define HW_PCIE_PVCCR2_SET(v)    (HW_PCIE_PVCCR2_WR(HW_PCIE_PVCCR2_RD() |  (v)))
#define HW_PCIE_PVCCR2_CLR(v)    (HW_PCIE_PVCCR2_WR(HW_PCIE_PVCCR2_RD() & ~(v)))
#define HW_PCIE_PVCCR2_TOG(v)    (HW_PCIE_PVCCR2_WR(HW_PCIE_PVCCR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_PVCCR2 bitfields
 */

/* --- Register HW_PCIE_PVCCR2, field VC_ARBITRATION_TABLE_OFFSET */

#define BP_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET      24
#define BM_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET(v)   ((((reg32_t) v) << 24) & BM_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET)
#else
#define BF_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET(v)   (((v) << 24) & BM_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET(v)   BF_CS1(PCIE_PVCCR2, VC_ARBITRATION_TABLE_OFFSET, v)
#endif

/* --- Register HW_PCIE_PVCCR2, field VC_ARBITRATION_CAPABILITY */

#define BP_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY      0
#define BM_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY(v)   ((((reg32_t) v) << 0) & BM_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY)
#else
#define BF_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY(v)   (((v) << 0) & BM_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY(v)   BF_CS1(PCIE_PVCCR2, VC_ARBITRATION_CAPABILITY, v)
#endif

/*
 * HW_PCIE_PVCCSR - Port VC Control and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 15;
        unsigned ARBITRATION_TABLE_STATUS : 1;
        unsigned RESERVED1 : 12;
        unsigned VC_ARBITRATION_SELECT : 3;
        unsigned LOAD_VC_ARBITRATION_TABLE : 1;

    } B;
} hw_pcie_pvccsr_t;
#endif

/*
 * constants & macros for entire PCIE_PVCCSR register
 */
#define HW_PCIE_PVCCSR_ADDR      (REGS_PCIE_BASE + 0x14c)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_PVCCSR           (*(volatile hw_pcie_pvccsr_t *) HW_PCIE_PVCCSR_ADDR)
#define HW_PCIE_PVCCSR_RD()      (HW_PCIE_PVCCSR.U)
#define HW_PCIE_PVCCSR_WR(v)     (HW_PCIE_PVCCSR.U = (v))
#define HW_PCIE_PVCCSR_SET(v)    (HW_PCIE_PVCCSR_WR(HW_PCIE_PVCCSR_RD() |  (v)))
#define HW_PCIE_PVCCSR_CLR(v)    (HW_PCIE_PVCCSR_WR(HW_PCIE_PVCCSR_RD() & ~(v)))
#define HW_PCIE_PVCCSR_TOG(v)    (HW_PCIE_PVCCSR_WR(HW_PCIE_PVCCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_PVCCSR bitfields
 */

/* --- Register HW_PCIE_PVCCSR, field ARBITRATION_TABLE_STATUS */

#define BP_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS      16
#define BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)   ((((reg32_t) v) << 16) & BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS)
#else
#define BF_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)   (((v) << 16) & BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)   BF_CS1(PCIE_PVCCSR, ARBITRATION_TABLE_STATUS, v)
#endif

/* --- Register HW_PCIE_PVCCSR, field VC_ARBITRATION_SELECT */

#define BP_PCIE_PVCCSR_VC_ARBITRATION_SELECT      1
#define BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT      0x0000000e

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)   ((((reg32_t) v) << 1) & BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT)
#else
#define BF_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)   (((v) << 1) & BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)   BF_CS1(PCIE_PVCCSR, VC_ARBITRATION_SELECT, v)
#endif

/* --- Register HW_PCIE_PVCCSR, field LOAD_VC_ARBITRATION_TABLE */

#define BP_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE      0
#define BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)   ((((reg32_t) v) << 0) & BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE)
#else
#define BF_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)   (((v) << 0) & BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)   BF_CS1(PCIE_PVCCSR, LOAD_VC_ARBITRATION_TABLE, v)
#endif

/*
 * HW_PCIE_VCRCR - VC Resource Capability Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PORT_ARBITRATION_TABLE_OFFSET : 8;
        unsigned RESERVED0 : 1;
        unsigned MAXIMUM_TIME_SLOTS : 7;
        unsigned REJECT_SNOOP_TRANSACTIONS : 1;
        unsigned UNDEFINED : 1;
        unsigned RESERVED1 : 6;
        unsigned PORT_ARBITRATION_CAPABILITY : 8;

    } B;
} hw_pcie_vcrcr_t;
#endif

/*
 * constants & macros for entire PCIE_VCRCR register
 */
#define HW_PCIE_VCRCR_ADDR      (REGS_PCIE_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_VCRCR           (*(volatile hw_pcie_vcrcr_t *) HW_PCIE_VCRCR_ADDR)
#define HW_PCIE_VCRCR_RD()      (HW_PCIE_VCRCR.U)
#define HW_PCIE_VCRCR_WR(v)     (HW_PCIE_VCRCR.U = (v))
#define HW_PCIE_VCRCR_SET(v)    (HW_PCIE_VCRCR_WR(HW_PCIE_VCRCR_RD() |  (v)))
#define HW_PCIE_VCRCR_CLR(v)    (HW_PCIE_VCRCR_WR(HW_PCIE_VCRCR_RD() & ~(v)))
#define HW_PCIE_VCRCR_TOG(v)    (HW_PCIE_VCRCR_WR(HW_PCIE_VCRCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_VCRCR bitfields
 */

/* --- Register HW_PCIE_VCRCR, field PORT_ARBITRATION_TABLE_OFFSET */

#define BP_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET      24
#define BM_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET(v)   ((((reg32_t) v) << 24) & BM_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET)
#else
#define BF_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET(v)   (((v) << 24) & BM_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET(v)   BF_CS1(PCIE_VCRCR, PORT_ARBITRATION_TABLE_OFFSET, v)
#endif

/* --- Register HW_PCIE_VCRCR, field MAXIMUM_TIME_SLOTS */

#define BP_PCIE_VCRCR_MAXIMUM_TIME_SLOTS      16
#define BM_PCIE_VCRCR_MAXIMUM_TIME_SLOTS      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCR_MAXIMUM_TIME_SLOTS(v)   ((((reg32_t) v) << 16) & BM_PCIE_VCRCR_MAXIMUM_TIME_SLOTS)
#else
#define BF_PCIE_VCRCR_MAXIMUM_TIME_SLOTS(v)   (((v) << 16) & BM_PCIE_VCRCR_MAXIMUM_TIME_SLOTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCR_MAXIMUM_TIME_SLOTS(v)   BF_CS1(PCIE_VCRCR, MAXIMUM_TIME_SLOTS, v)
#endif

/* --- Register HW_PCIE_VCRCR, field REJECT_SNOOP_TRANSACTIONS */

#define BP_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS      15
#define BM_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS(v)   ((((reg32_t) v) << 15) & BM_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS)
#else
#define BF_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS(v)   (((v) << 15) & BM_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS(v)   BF_CS1(PCIE_VCRCR, REJECT_SNOOP_TRANSACTIONS, v)
#endif

/* --- Register HW_PCIE_VCRCR, field UNDEFINED */

#define BP_PCIE_VCRCR_UNDEFINED      14
#define BM_PCIE_VCRCR_UNDEFINED      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCR_UNDEFINED(v)   ((((reg32_t) v) << 14) & BM_PCIE_VCRCR_UNDEFINED)
#else
#define BF_PCIE_VCRCR_UNDEFINED(v)   (((v) << 14) & BM_PCIE_VCRCR_UNDEFINED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCR_UNDEFINED(v)   BF_CS1(PCIE_VCRCR, UNDEFINED, v)
#endif

/* --- Register HW_PCIE_VCRCR, field PORT_ARBITRATION_CAPABILITY */

#define BP_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY      0
#define BM_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY(v)   ((((reg32_t) v) << 0) & BM_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY)
#else
#define BF_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY(v)   (((v) << 0) & BM_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY(v)   BF_CS1(PCIE_VCRCR, PORT_ARBITRATION_CAPABILITY, v)
#endif

/*
 * HW_PCIE_VCRCONR - VC Resource Control Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VC_ENABLE : 1;
        unsigned RESERVED0 : 4;
        unsigned VC_ID : 3;
        unsigned RESERVED1 : 4;
        unsigned PORT_ARBITRATION_SELECT : 3;
        unsigned LOAD_PORT_ARBITRATION_TABLE : 1;
        unsigned RESERVED2 : 8;
        unsigned TC_VC_MAP : 8;

    } B;
} hw_pcie_vcrconr_t;
#endif

/*
 * constants & macros for entire PCIE_VCRCONR register
 */
#define HW_PCIE_VCRCONR_ADDR      (REGS_PCIE_BASE + 0x154)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_VCRCONR           (*(volatile hw_pcie_vcrconr_t *) HW_PCIE_VCRCONR_ADDR)
#define HW_PCIE_VCRCONR_RD()      (HW_PCIE_VCRCONR.U)
#define HW_PCIE_VCRCONR_WR(v)     (HW_PCIE_VCRCONR.U = (v))
#define HW_PCIE_VCRCONR_SET(v)    (HW_PCIE_VCRCONR_WR(HW_PCIE_VCRCONR_RD() |  (v)))
#define HW_PCIE_VCRCONR_CLR(v)    (HW_PCIE_VCRCONR_WR(HW_PCIE_VCRCONR_RD() & ~(v)))
#define HW_PCIE_VCRCONR_TOG(v)    (HW_PCIE_VCRCONR_WR(HW_PCIE_VCRCONR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_VCRCONR bitfields
 */

/* --- Register HW_PCIE_VCRCONR, field VC_ENABLE */

#define BP_PCIE_VCRCONR_VC_ENABLE      31
#define BM_PCIE_VCRCONR_VC_ENABLE      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCONR_VC_ENABLE(v)   ((((reg32_t) v) << 31) & BM_PCIE_VCRCONR_VC_ENABLE)
#else
#define BF_PCIE_VCRCONR_VC_ENABLE(v)   (((v) << 31) & BM_PCIE_VCRCONR_VC_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCONR_VC_ENABLE(v)   BF_CS1(PCIE_VCRCONR, VC_ENABLE, v)
#endif

/* --- Register HW_PCIE_VCRCONR, field VC_ID */

#define BP_PCIE_VCRCONR_VC_ID      24
#define BM_PCIE_VCRCONR_VC_ID      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCONR_VC_ID(v)   ((((reg32_t) v) << 24) & BM_PCIE_VCRCONR_VC_ID)
#else
#define BF_PCIE_VCRCONR_VC_ID(v)   (((v) << 24) & BM_PCIE_VCRCONR_VC_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCONR_VC_ID(v)   BF_CS1(PCIE_VCRCONR, VC_ID, v)
#endif

/* --- Register HW_PCIE_VCRCONR, field PORT_ARBITRATION_SELECT */

#define BP_PCIE_VCRCONR_PORT_ARBITRATION_SELECT      17
#define BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)   ((((reg32_t) v) << 17) & BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT)
#else
#define BF_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)   (((v) << 17) & BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)   BF_CS1(PCIE_VCRCONR, PORT_ARBITRATION_SELECT, v)
#endif

/* --- Register HW_PCIE_VCRCONR, field LOAD_PORT_ARBITRATION_TABLE */

#define BP_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE      16
#define BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)   ((((reg32_t) v) << 16) & BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE)
#else
#define BF_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)   (((v) << 16) & BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)   BF_CS1(PCIE_VCRCONR, LOAD_PORT_ARBITRATION_TABLE, v)
#endif

/* --- Register HW_PCIE_VCRCONR, field TC_VC_MAP */

#define BP_PCIE_VCRCONR_TC_VC_MAP      0
#define BM_PCIE_VCRCONR_TC_VC_MAP      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRCONR_TC_VC_MAP(v)   ((((reg32_t) v) << 0) & BM_PCIE_VCRCONR_TC_VC_MAP)
#else
#define BF_PCIE_VCRCONR_TC_VC_MAP(v)   (((v) << 0) & BM_PCIE_VCRCONR_TC_VC_MAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRCONR_TC_VC_MAP(v)   BF_CS1(PCIE_VCRCONR, TC_VC_MAP, v)
#endif

/*
 * HW_PCIE_VCRSR - VC Resource Status Register n
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 14;
        unsigned VC_NEGOTIATION_PENDING : 1;
        unsigned PORT_ARBITRATION_TABLE_STATUS : 1;
        unsigned RESERVED1 : 16;

    } B;
} hw_pcie_vcrsr_t;
#endif

/*
 * constants & macros for entire PCIE_VCRSR register
 */
#define HW_PCIE_VCRSR_ADDR      (REGS_PCIE_BASE + 0x158)

#ifndef __LANGUAGE_ASM__
#define HW_PCIE_VCRSR           (*(volatile hw_pcie_vcrsr_t *) HW_PCIE_VCRSR_ADDR)
#define HW_PCIE_VCRSR_RD()      (HW_PCIE_VCRSR.U)
#define HW_PCIE_VCRSR_WR(v)     (HW_PCIE_VCRSR.U = (v))
#define HW_PCIE_VCRSR_SET(v)    (HW_PCIE_VCRSR_WR(HW_PCIE_VCRSR_RD() |  (v)))
#define HW_PCIE_VCRSR_CLR(v)    (HW_PCIE_VCRSR_WR(HW_PCIE_VCRSR_RD() & ~(v)))
#define HW_PCIE_VCRSR_TOG(v)    (HW_PCIE_VCRSR_WR(HW_PCIE_VCRSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual PCIE_VCRSR bitfields
 */

/* --- Register HW_PCIE_VCRSR, field VC_NEGOTIATION_PENDING */

#define BP_PCIE_VCRSR_VC_NEGOTIATION_PENDING      17
#define BM_PCIE_VCRSR_VC_NEGOTIATION_PENDING      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRSR_VC_NEGOTIATION_PENDING(v)   ((((reg32_t) v) << 17) & BM_PCIE_VCRSR_VC_NEGOTIATION_PENDING)
#else
#define BF_PCIE_VCRSR_VC_NEGOTIATION_PENDING(v)   (((v) << 17) & BM_PCIE_VCRSR_VC_NEGOTIATION_PENDING)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRSR_VC_NEGOTIATION_PENDING(v)   BF_CS1(PCIE_VCRSR, VC_NEGOTIATION_PENDING, v)
#endif

/* --- Register HW_PCIE_VCRSR, field PORT_ARBITRATION_TABLE_STATUS */

#define BP_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS      16
#define BM_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS(v)   ((((reg32_t) v) << 16) & BM_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS)
#else
#define BF_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS(v)   (((v) << 16) & BM_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS(v)   BF_CS1(PCIE_VCRSR, PORT_ARBITRATION_TABLE_STATUS, v)
#endif


#endif // _PCIE_H

