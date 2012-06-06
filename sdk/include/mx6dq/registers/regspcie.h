/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_PCIE_REGISTERS_H__
#define __HW_PCIE_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ PCIE registers defined in this header file.
 *
 * - HW_PCIE_DEVICEID - Device ID and Vendor ID Register
 * - HW_PCIE_COMMAND - Command and Status Register
 * - HW_PCIE_REVID - Revision ID and Class Code Register
 * - HW_PCIE_BIST - BIST Register
 * - HW_PCIE_BAR0 - Base Address 0
 * - HW_PCIE_BAR1 - Base Address 1
 * - HW_PCIE_BAR2 - Base Address 2
 * - HW_PCIE_BAR3 - Base Address 3
 * - HW_PCIE_BAR4 - Base Address 4
 * - HW_PCIE_BAR5 - Base Address 5
 * - HW_PCIE_CISP - CardBus CIS Pointer Register
 * - HW_PCIE_SSID - Subsystem ID and Subsystem Vendor ID Register
 * - HW_PCIE_EROMBAR - Expansion ROM Base Address Register
 * - HW_PCIE_CAPPR - Capability Pointer Register
 * - HW_PCIE_ILR - Interrupt Line and Pin Register
 * - HW_PCIE_PMCR - Power Management Capability Register
 * - HW_PCIE_PMCSR - Power Management Control and Status Register
 * - HW_PCIE_CIDR - PCI Express Capability ID Register
 * - HW_PCIE_DCR - Device Capabilities Register
 * - HW_PCIE_DCONR - Device Control Register
 * - HW_PCIE_LCR - Link Capabilities Register
 * - HW_PCIE_LCSR - Link Control and Status Register
 * - HW_PCIE_SCR - Slot Capabilities Register
 * - HW_PCIE_SCSR - Slot Control and Status Register
 * - HW_PCIE_RCCR - Root Control and Capabilities Register
 * - HW_PCIE_RSR - Root Status Register
 * - HW_PCIE_DCR2 - Device Capabilities 2 Register
 * - HW_PCIE_DCSR2 - Device Control and Status 2 Register
 * - HW_PCIE_LCR2 - Link Capabilities 2 Register
 * - HW_PCIE_LCSR2 - Link Control and Status 2 Register
 * - HW_PCIE_AER - AER Capability Header
 * - HW_PCIE_UESR - Uncorrectable Error Status Register
 * - HW_PCIE_UEMR - Uncorrectable Error Mask Register
 * - HW_PCIE_UESEVR - Uncorrectable Error Severity Register
 * - HW_PCIE_CESR - Correctable Error Status Register
 * - HW_PCIE_CEMR - Correctable Error Mask Register
 * - HW_PCIE_ACCR - Advanced Capabilities and Control Register
 * - HW_PCIE_HLR - Header Log Register
 * - HW_PCIE_RECR - Root Error Command Register
 * - HW_PCIE_RESR - Root Error Status Register
 * - HW_PCIE_ESIR - Error Source Identification Register
 * - HW_PCIE_VCECHR - VC Extended Capability Header
 * - HW_PCIE_PVCCR1 - Port VC Capability Register 1
 * - HW_PCIE_PVCCR2 - Port VC Capability Register 2
 * - HW_PCIE_PVCCSR - Port VC Control and Status Register
 * - HW_PCIE_VCRCR - VC Resource Capability Register n
 * - HW_PCIE_VCRCONR - VC Resource Control Register n
 * - HW_PCIE_VCRSR - VC Resource Status Register n
 *
 * - hw_pcie_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PCIE_BASE
#define HW_PCIE_INSTANCE_COUNT (1) //!< Number of instances of the PCIE module.
#define REGS_PCIE_BASE (0x01000000) //!< Base address for PCIE.
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_PCIE_DEVICEID - Device ID and Vendor ID Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_DEVICEID - Device ID and Vendor ID Register (RO)
 *
 * Reset value: 0xabcd16c3
 *
 * Offset : 0x00  The default values of both Device ID and Vendor ID are hardware configuration
 * parameters. The application can overwrite the default values of both Device ID and Vendor ID
 * through the DBI.
 */
typedef union _hw_pcie_deviceid
{
    reg32_t U;
    struct _hw_pcie_deviceid_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
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
#endif

/*
 * constants & macros for individual PCIE_DEVICEID bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_PCIE_COMMAND - Command and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_COMMAND - Command and Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset : 0x04  Bytes : 0-1
 */
typedef union _hw_pcie_command
{
    reg32_t U;
    struct _hw_pcie_command_bitfields
    {
        unsigned I_O_SPACE_ENABLE : 1; //!< [0] I/O Space Enable
        unsigned MEMORY_SPACE_ENABLE : 1; //!< [1] Memory Space Enable
        unsigned BUS_MASTER_ENABLE : 1; //!< [2] Bus Master Enable
        unsigned SPECIAL_CYCLE_ENABLE : 1; //!< [3] Special Cycle Enable Not applicable for PCI Express.
        unsigned MEMORY_WRITE_AND_INVALIDATE : 1; //!< [4] Memory Write and Invalidate Not applicable for PCI Express.
        unsigned VGA_PALETTE_SNOOP : 1; //!< [5] VGA Palette Snoop Not applicable for PCI Express.
        unsigned PARITY_ERROR_RESPONSE : 1; //!< [6] Parity Error Response
        unsigned IDSEL_STEPPING : 1; //!< [7] IDSEL Stepping/Wait Cycle Control Not applicable for PCI Express.
        unsigned SERR_ENABLE : 1; //!< [8] SERR# Enable
        unsigned FAST_BACK_TO_BACK_ENABLE : 1; //!< [9] Fast Back-to-Back Enable Not applicable for PCI Express.
        unsigned INTX_ASSERTION_DISABLE : 1; //!< [10] INTx Assertion Disable
        unsigned RESERVED0 : 8; //!< [18:11] Reserved.
        unsigned INTX_STATUS : 1; //!< [19] INTx Status
        unsigned CAPABILITIES_LIST : 1; //!< [20] Capabilities List Indicates presence of an extended capability item.
        unsigned SIXTYSIX_MHZ_CAPABLE : 1; //!< [21] 66 MHz Capable Not applicable for PCI Express.
        unsigned RESERVED1 : 1; //!< [22] Reserved
        unsigned FAST_BACK_TO_BACK_CAPABLE : 1; //!< [23] Fast Back-to-Back Capable Not applicable for PCI Express.
        unsigned MASTER_DATA_PARITY_ERROR : 1; //!< [24] Master Data Parity Error
        unsigned DEVSEL_TIMING : 2; //!< [26:25] DEVSEL Timing Not applicable for PCI Express.
        unsigned SIGNALED_TARGET_ABORT : 1; //!< [27] Signaled Target Abort
        unsigned RECEIVED_TARGET_ABORT : 1; //!< [28] Received Target Abort
        unsigned RECEIVED_MASTER_ABORT : 1; //!< [29] Received Master Abort
        unsigned DETECTED_PARITY_ERROR : 1; //!< [30] Detected Parity Error
        unsigned SIGNALED_SYSTEM_ERROR : 1; //!< [31] Signaled System Error
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

/* --- Register HW_PCIE_COMMAND, field I_O_SPACE_ENABLE[0] (RW)
 *
 * I/O Space Enable
 */

#define BP_PCIE_COMMAND_I_O_SPACE_ENABLE      (0)      //!< Bit position for PCIE_COMMAND_I_O_SPACE_ENABLE.
#define BM_PCIE_COMMAND_I_O_SPACE_ENABLE      (0x00000001)  //!< Bit mask for PCIE_COMMAND_I_O_SPACE_ENABLE.

//! @brief Get value of PCIE_COMMAND_I_O_SPACE_ENABLE from a register value.
#define BG_PCIE_COMMAND_I_O_SPACE_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_I_O_SPACE_ENABLE) >> BP_PCIE_COMMAND_I_O_SPACE_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_I_O_SPACE_ENABLE.
#define BF_PCIE_COMMAND_I_O_SPACE_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_I_O_SPACE_ENABLE) & BM_PCIE_COMMAND_I_O_SPACE_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the I_O_SPACE_ENABLE field to a new value.
#define BW_PCIE_COMMAND_I_O_SPACE_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_I_O_SPACE_ENABLE) | BF_PCIE_COMMAND_I_O_SPACE_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field MEMORY_SPACE_ENABLE[1] (RW)
 *
 * Memory Space Enable
 */

#define BP_PCIE_COMMAND_MEMORY_SPACE_ENABLE      (1)      //!< Bit position for PCIE_COMMAND_MEMORY_SPACE_ENABLE.
#define BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE      (0x00000002)  //!< Bit mask for PCIE_COMMAND_MEMORY_SPACE_ENABLE.

//! @brief Get value of PCIE_COMMAND_MEMORY_SPACE_ENABLE from a register value.
#define BG_PCIE_COMMAND_MEMORY_SPACE_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE) >> BP_PCIE_COMMAND_MEMORY_SPACE_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_MEMORY_SPACE_ENABLE.
#define BF_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_MEMORY_SPACE_ENABLE) & BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEMORY_SPACE_ENABLE field to a new value.
#define BW_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_MEMORY_SPACE_ENABLE) | BF_PCIE_COMMAND_MEMORY_SPACE_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field BUS_MASTER_ENABLE[2] (RW)
 *
 * Bus Master Enable
 */

#define BP_PCIE_COMMAND_BUS_MASTER_ENABLE      (2)      //!< Bit position for PCIE_COMMAND_BUS_MASTER_ENABLE.
#define BM_PCIE_COMMAND_BUS_MASTER_ENABLE      (0x00000004)  //!< Bit mask for PCIE_COMMAND_BUS_MASTER_ENABLE.

//! @brief Get value of PCIE_COMMAND_BUS_MASTER_ENABLE from a register value.
#define BG_PCIE_COMMAND_BUS_MASTER_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_BUS_MASTER_ENABLE) >> BP_PCIE_COMMAND_BUS_MASTER_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_BUS_MASTER_ENABLE.
#define BF_PCIE_COMMAND_BUS_MASTER_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_BUS_MASTER_ENABLE) & BM_PCIE_COMMAND_BUS_MASTER_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUS_MASTER_ENABLE field to a new value.
#define BW_PCIE_COMMAND_BUS_MASTER_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_BUS_MASTER_ENABLE) | BF_PCIE_COMMAND_BUS_MASTER_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field SPECIAL_CYCLE_ENABLE[3] (RW)
 *
 * Special Cycle Enable Not applicable for PCI Express. Must be hardwired to 0.
 */

#define BP_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE      (3)      //!< Bit position for PCIE_COMMAND_SPECIAL_CYCLE_ENABLE.
#define BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE      (0x00000008)  //!< Bit mask for PCIE_COMMAND_SPECIAL_CYCLE_ENABLE.

//! @brief Get value of PCIE_COMMAND_SPECIAL_CYCLE_ENABLE from a register value.
#define BG_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE) >> BP_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_SPECIAL_CYCLE_ENABLE.
#define BF_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE) & BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPECIAL_CYCLE_ENABLE field to a new value.
#define BW_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE) | BF_PCIE_COMMAND_SPECIAL_CYCLE_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field MEMORY_WRITE_AND_INVALIDATE[4] (RW)
 *
 * Memory Write and Invalidate Not applicable for PCI Express. Must be hardwired to 0.
 */

#define BP_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE      (4)      //!< Bit position for PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE.
#define BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE      (0x00000010)  //!< Bit mask for PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE.

//! @brief Get value of PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE from a register value.
#define BG_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE) >> BP_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE)

//! @brief Format value for bitfield PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE.
#define BF_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE) & BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEMORY_WRITE_AND_INVALIDATE field to a new value.
#define BW_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE) | BF_PCIE_COMMAND_MEMORY_WRITE_AND_INVALIDATE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field VGA_PALETTE_SNOOP[5] (RW)
 *
 * VGA Palette Snoop Not applicable for PCI Express. Must be hardwired to 0.
 */

#define BP_PCIE_COMMAND_VGA_PALETTE_SNOOP      (5)      //!< Bit position for PCIE_COMMAND_VGA_PALETTE_SNOOP.
#define BM_PCIE_COMMAND_VGA_PALETTE_SNOOP      (0x00000020)  //!< Bit mask for PCIE_COMMAND_VGA_PALETTE_SNOOP.

//! @brief Get value of PCIE_COMMAND_VGA_PALETTE_SNOOP from a register value.
#define BG_PCIE_COMMAND_VGA_PALETTE_SNOOP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_VGA_PALETTE_SNOOP) >> BP_PCIE_COMMAND_VGA_PALETTE_SNOOP)

//! @brief Format value for bitfield PCIE_COMMAND_VGA_PALETTE_SNOOP.
#define BF_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_VGA_PALETTE_SNOOP) & BM_PCIE_COMMAND_VGA_PALETTE_SNOOP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VGA_PALETTE_SNOOP field to a new value.
#define BW_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_VGA_PALETTE_SNOOP) | BF_PCIE_COMMAND_VGA_PALETTE_SNOOP(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field PARITY_ERROR_RESPONSE[6] (RW)
 *
 * Parity Error Response
 */

#define BP_PCIE_COMMAND_PARITY_ERROR_RESPONSE      (6)      //!< Bit position for PCIE_COMMAND_PARITY_ERROR_RESPONSE.
#define BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE      (0x00000040)  //!< Bit mask for PCIE_COMMAND_PARITY_ERROR_RESPONSE.

//! @brief Get value of PCIE_COMMAND_PARITY_ERROR_RESPONSE from a register value.
#define BG_PCIE_COMMAND_PARITY_ERROR_RESPONSE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE) >> BP_PCIE_COMMAND_PARITY_ERROR_RESPONSE)

//! @brief Format value for bitfield PCIE_COMMAND_PARITY_ERROR_RESPONSE.
#define BF_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_PARITY_ERROR_RESPONSE) & BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARITY_ERROR_RESPONSE field to a new value.
#define BW_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_PARITY_ERROR_RESPONSE) | BF_PCIE_COMMAND_PARITY_ERROR_RESPONSE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field IDSEL_STEPPING[7] (RW)
 *
 * IDSEL Stepping/Wait Cycle Control Not applicable for PCI Express. Must be hardwired to 0
 */

#define BP_PCIE_COMMAND_IDSEL_STEPPING      (7)      //!< Bit position for PCIE_COMMAND_IDSEL_STEPPING.
#define BM_PCIE_COMMAND_IDSEL_STEPPING      (0x00000080)  //!< Bit mask for PCIE_COMMAND_IDSEL_STEPPING.

//! @brief Get value of PCIE_COMMAND_IDSEL_STEPPING from a register value.
#define BG_PCIE_COMMAND_IDSEL_STEPPING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_IDSEL_STEPPING) >> BP_PCIE_COMMAND_IDSEL_STEPPING)

//! @brief Format value for bitfield PCIE_COMMAND_IDSEL_STEPPING.
#define BF_PCIE_COMMAND_IDSEL_STEPPING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_IDSEL_STEPPING) & BM_PCIE_COMMAND_IDSEL_STEPPING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDSEL_STEPPING field to a new value.
#define BW_PCIE_COMMAND_IDSEL_STEPPING(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_IDSEL_STEPPING) | BF_PCIE_COMMAND_IDSEL_STEPPING(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field SERR_ENABLE[8] (RW)
 *
 * SERR# Enable
 */

#define BP_PCIE_COMMAND_SERR_ENABLE      (8)      //!< Bit position for PCIE_COMMAND_SERR_ENABLE.
#define BM_PCIE_COMMAND_SERR_ENABLE      (0x00000100)  //!< Bit mask for PCIE_COMMAND_SERR_ENABLE.

//! @brief Get value of PCIE_COMMAND_SERR_ENABLE from a register value.
#define BG_PCIE_COMMAND_SERR_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_SERR_ENABLE) >> BP_PCIE_COMMAND_SERR_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_SERR_ENABLE.
#define BF_PCIE_COMMAND_SERR_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_SERR_ENABLE) & BM_PCIE_COMMAND_SERR_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SERR_ENABLE field to a new value.
#define BW_PCIE_COMMAND_SERR_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_SERR_ENABLE) | BF_PCIE_COMMAND_SERR_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field FAST_BACK_TO_BACK_ENABLE[9] (RW)
 *
 * Fast Back-to-Back Enable Not applicable for PCI Express. Must be hardwired to 0.
 */

#define BP_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE      (9)      //!< Bit position for PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE.
#define BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE      (0x00000200)  //!< Bit mask for PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE.

//! @brief Get value of PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE from a register value.
#define BG_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE) >> BP_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE)

//! @brief Format value for bitfield PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE.
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_BACK_TO_BACK_ENABLE field to a new value.
#define BW_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE) | BF_PCIE_COMMAND_FAST_BACK_TO_BACK_ENABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field INTX_ASSERTION_DISABLE[10] (RW)
 *
 * INTx Assertion Disable
 */

#define BP_PCIE_COMMAND_INTX_ASSERTION_DISABLE      (10)      //!< Bit position for PCIE_COMMAND_INTX_ASSERTION_DISABLE.
#define BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE      (0x00000400)  //!< Bit mask for PCIE_COMMAND_INTX_ASSERTION_DISABLE.

//! @brief Get value of PCIE_COMMAND_INTX_ASSERTION_DISABLE from a register value.
#define BG_PCIE_COMMAND_INTX_ASSERTION_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE) >> BP_PCIE_COMMAND_INTX_ASSERTION_DISABLE)

//! @brief Format value for bitfield PCIE_COMMAND_INTX_ASSERTION_DISABLE.
#define BF_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_INTX_ASSERTION_DISABLE) & BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INTX_ASSERTION_DISABLE field to a new value.
#define BW_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_INTX_ASSERTION_DISABLE) | BF_PCIE_COMMAND_INTX_ASSERTION_DISABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field INTX_STATUS[19] (RW)
 *
 * INTx Status
 */

#define BP_PCIE_COMMAND_INTX_STATUS      (19)      //!< Bit position for PCIE_COMMAND_INTX_STATUS.
#define BM_PCIE_COMMAND_INTX_STATUS      (0x00080000)  //!< Bit mask for PCIE_COMMAND_INTX_STATUS.

//! @brief Get value of PCIE_COMMAND_INTX_STATUS from a register value.
#define BG_PCIE_COMMAND_INTX_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_INTX_STATUS) >> BP_PCIE_COMMAND_INTX_STATUS)

//! @brief Format value for bitfield PCIE_COMMAND_INTX_STATUS.
#define BF_PCIE_COMMAND_INTX_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_INTX_STATUS) & BM_PCIE_COMMAND_INTX_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INTX_STATUS field to a new value.
#define BW_PCIE_COMMAND_INTX_STATUS(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_INTX_STATUS) | BF_PCIE_COMMAND_INTX_STATUS(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field CAPABILITIES_LIST[20] (RW)
 *
 * Capabilities List Indicates presence of an extended capability item. Hardwired to 1.
 */

#define BP_PCIE_COMMAND_CAPABILITIES_LIST      (20)      //!< Bit position for PCIE_COMMAND_CAPABILITIES_LIST.
#define BM_PCIE_COMMAND_CAPABILITIES_LIST      (0x00100000)  //!< Bit mask for PCIE_COMMAND_CAPABILITIES_LIST.

//! @brief Get value of PCIE_COMMAND_CAPABILITIES_LIST from a register value.
#define BG_PCIE_COMMAND_CAPABILITIES_LIST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_CAPABILITIES_LIST) >> BP_PCIE_COMMAND_CAPABILITIES_LIST)

//! @brief Format value for bitfield PCIE_COMMAND_CAPABILITIES_LIST.
#define BF_PCIE_COMMAND_CAPABILITIES_LIST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_CAPABILITIES_LIST) & BM_PCIE_COMMAND_CAPABILITIES_LIST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPABILITIES_LIST field to a new value.
#define BW_PCIE_COMMAND_CAPABILITIES_LIST(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_CAPABILITIES_LIST) | BF_PCIE_COMMAND_CAPABILITIES_LIST(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field SIXTYSIX_MHZ_CAPABLE[21] (RW)
 *
 * 66 MHz Capable Not applicable for PCI Express. Hardwired to 0.
 */

#define BP_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE      (21)      //!< Bit position for PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE.
#define BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE      (0x00200000)  //!< Bit mask for PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE.

//! @brief Get value of PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE from a register value.
#define BG_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE) >> BP_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE)

//! @brief Format value for bitfield PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE.
#define BF_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE) & BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIXTYSIX_MHZ_CAPABLE field to a new value.
#define BW_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE) | BF_PCIE_COMMAND_SIXTYSIX_MHZ_CAPABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field FAST_BACK_TO_BACK_CAPABLE[23] (RW)
 *
 * Fast Back-to-Back Capable Not applicable for PCI Express. Hardwired to 0.
 */

#define BP_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE      (23)      //!< Bit position for PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE.
#define BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE      (0x00800000)  //!< Bit mask for PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE.

//! @brief Get value of PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE from a register value.
#define BG_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE) >> BP_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE)

//! @brief Format value for bitfield PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE.
#define BF_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE) & BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FAST_BACK_TO_BACK_CAPABLE field to a new value.
#define BW_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE) | BF_PCIE_COMMAND_FAST_BACK_TO_BACK_CAPABLE(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field MASTER_DATA_PARITY_ERROR[24] (RW)
 *
 * Master Data Parity Error
 */

#define BP_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR      (24)      //!< Bit position for PCIE_COMMAND_MASTER_DATA_PARITY_ERROR.
#define BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR      (0x01000000)  //!< Bit mask for PCIE_COMMAND_MASTER_DATA_PARITY_ERROR.

//! @brief Get value of PCIE_COMMAND_MASTER_DATA_PARITY_ERROR from a register value.
#define BG_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR) >> BP_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR)

//! @brief Format value for bitfield PCIE_COMMAND_MASTER_DATA_PARITY_ERROR.
#define BF_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR) & BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASTER_DATA_PARITY_ERROR field to a new value.
#define BW_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR) | BF_PCIE_COMMAND_MASTER_DATA_PARITY_ERROR(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field DEVSEL_TIMING[26:25] (RW)
 *
 * DEVSEL Timing Not applicable for PCI Express. Hardwired to 0.
 */

#define BP_PCIE_COMMAND_DEVSEL_TIMING      (25)      //!< Bit position for PCIE_COMMAND_DEVSEL_TIMING.
#define BM_PCIE_COMMAND_DEVSEL_TIMING      (0x06000000)  //!< Bit mask for PCIE_COMMAND_DEVSEL_TIMING.

//! @brief Get value of PCIE_COMMAND_DEVSEL_TIMING from a register value.
#define BG_PCIE_COMMAND_DEVSEL_TIMING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_DEVSEL_TIMING) >> BP_PCIE_COMMAND_DEVSEL_TIMING)

//! @brief Format value for bitfield PCIE_COMMAND_DEVSEL_TIMING.
#define BF_PCIE_COMMAND_DEVSEL_TIMING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_DEVSEL_TIMING) & BM_PCIE_COMMAND_DEVSEL_TIMING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVSEL_TIMING field to a new value.
#define BW_PCIE_COMMAND_DEVSEL_TIMING(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_DEVSEL_TIMING) | BF_PCIE_COMMAND_DEVSEL_TIMING(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field SIGNALED_TARGET_ABORT[27] (RW)
 *
 * Signaled Target Abort
 */

#define BP_PCIE_COMMAND_SIGNALED_TARGET_ABORT      (27)      //!< Bit position for PCIE_COMMAND_SIGNALED_TARGET_ABORT.
#define BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT      (0x08000000)  //!< Bit mask for PCIE_COMMAND_SIGNALED_TARGET_ABORT.

//! @brief Get value of PCIE_COMMAND_SIGNALED_TARGET_ABORT from a register value.
#define BG_PCIE_COMMAND_SIGNALED_TARGET_ABORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT) >> BP_PCIE_COMMAND_SIGNALED_TARGET_ABORT)

//! @brief Format value for bitfield PCIE_COMMAND_SIGNALED_TARGET_ABORT.
#define BF_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_SIGNALED_TARGET_ABORT) & BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIGNALED_TARGET_ABORT field to a new value.
#define BW_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_SIGNALED_TARGET_ABORT) | BF_PCIE_COMMAND_SIGNALED_TARGET_ABORT(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field RECEIVED_TARGET_ABORT[28] (RW)
 *
 * Received Target Abort
 */

#define BP_PCIE_COMMAND_RECEIVED_TARGET_ABORT      (28)      //!< Bit position for PCIE_COMMAND_RECEIVED_TARGET_ABORT.
#define BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT      (0x10000000)  //!< Bit mask for PCIE_COMMAND_RECEIVED_TARGET_ABORT.

//! @brief Get value of PCIE_COMMAND_RECEIVED_TARGET_ABORT from a register value.
#define BG_PCIE_COMMAND_RECEIVED_TARGET_ABORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT) >> BP_PCIE_COMMAND_RECEIVED_TARGET_ABORT)

//! @brief Format value for bitfield PCIE_COMMAND_RECEIVED_TARGET_ABORT.
#define BF_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_RECEIVED_TARGET_ABORT) & BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVED_TARGET_ABORT field to a new value.
#define BW_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_RECEIVED_TARGET_ABORT) | BF_PCIE_COMMAND_RECEIVED_TARGET_ABORT(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field RECEIVED_MASTER_ABORT[29] (RW)
 *
 * Received Master Abort
 */

#define BP_PCIE_COMMAND_RECEIVED_MASTER_ABORT      (29)      //!< Bit position for PCIE_COMMAND_RECEIVED_MASTER_ABORT.
#define BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT      (0x20000000)  //!< Bit mask for PCIE_COMMAND_RECEIVED_MASTER_ABORT.

//! @brief Get value of PCIE_COMMAND_RECEIVED_MASTER_ABORT from a register value.
#define BG_PCIE_COMMAND_RECEIVED_MASTER_ABORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT) >> BP_PCIE_COMMAND_RECEIVED_MASTER_ABORT)

//! @brief Format value for bitfield PCIE_COMMAND_RECEIVED_MASTER_ABORT.
#define BF_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_RECEIVED_MASTER_ABORT) & BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVED_MASTER_ABORT field to a new value.
#define BW_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_RECEIVED_MASTER_ABORT) | BF_PCIE_COMMAND_RECEIVED_MASTER_ABORT(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field DETECTED_PARITY_ERROR[30] (RW)
 *
 * Detected Parity Error
 */

#define BP_PCIE_COMMAND_DETECTED_PARITY_ERROR      (30)      //!< Bit position for PCIE_COMMAND_DETECTED_PARITY_ERROR.
#define BM_PCIE_COMMAND_DETECTED_PARITY_ERROR      (0x40000000)  //!< Bit mask for PCIE_COMMAND_DETECTED_PARITY_ERROR.

//! @brief Get value of PCIE_COMMAND_DETECTED_PARITY_ERROR from a register value.
#define BG_PCIE_COMMAND_DETECTED_PARITY_ERROR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_DETECTED_PARITY_ERROR) >> BP_PCIE_COMMAND_DETECTED_PARITY_ERROR)

//! @brief Format value for bitfield PCIE_COMMAND_DETECTED_PARITY_ERROR.
#define BF_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_DETECTED_PARITY_ERROR) & BM_PCIE_COMMAND_DETECTED_PARITY_ERROR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DETECTED_PARITY_ERROR field to a new value.
#define BW_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_DETECTED_PARITY_ERROR) | BF_PCIE_COMMAND_DETECTED_PARITY_ERROR(v)))
#endif

/* --- Register HW_PCIE_COMMAND, field SIGNALED_SYSTEM_ERROR[31] (RW)
 *
 * Signaled System Error
 */

#define BP_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR      (31)      //!< Bit position for PCIE_COMMAND_SIGNALED_SYSTEM_ERROR.
#define BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR      (0x80000000)  //!< Bit mask for PCIE_COMMAND_SIGNALED_SYSTEM_ERROR.

//! @brief Get value of PCIE_COMMAND_SIGNALED_SYSTEM_ERROR from a register value.
#define BG_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR) >> BP_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR)

//! @brief Format value for bitfield PCIE_COMMAND_SIGNALED_SYSTEM_ERROR.
#define BF_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR) & BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SIGNALED_SYSTEM_ERROR field to a new value.
#define BW_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)   (HW_PCIE_COMMAND_WR((HW_PCIE_COMMAND_RD() & ~BM_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR) | BF_PCIE_COMMAND_SIGNALED_SYSTEM_ERROR(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_REVID - Revision ID and Class Code Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_REVID - Revision ID and Class Code Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x08  Byte: 0
 */
typedef union _hw_pcie_revid
{
    reg32_t U;
    struct _hw_pcie_revid_bitfields
    {
        unsigned CX_REVISION_ID_N : 8; //!< [7:0] Revision ID, writable through the DBI
        unsigned IF_CODE_N : 8; //!< [15:8] Programming Interface, writable through the DBI
        unsigned SUB_CLASS_CODE_N : 8; //!< [23:16] Subclass Code, writable through the DBI
        unsigned BASE_CLASS_CODE_N : 8; //!< [31:24] Base Class Code, writable through the DBI
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
#endif

/*
 * constants & macros for individual PCIE_REVID bitfields
 */

/* --- Register HW_PCIE_REVID, field CX_REVISION_ID_N[7:0] (RO)
 *
 * Revision ID, writable through the DBI
 */

#define BP_PCIE_REVID_CX_REVISION_ID_N      (0)      //!< Bit position for PCIE_REVID_CX_REVISION_ID_N.
#define BM_PCIE_REVID_CX_REVISION_ID_N      (0x000000ff)  //!< Bit mask for PCIE_REVID_CX_REVISION_ID_N.

//! @brief Get value of PCIE_REVID_CX_REVISION_ID_N from a register value.
#define BG_PCIE_REVID_CX_REVISION_ID_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_REVID_CX_REVISION_ID_N) >> BP_PCIE_REVID_CX_REVISION_ID_N)

/* --- Register HW_PCIE_REVID, field IF_CODE_N[15:8] (RO)
 *
 * Programming Interface, writable through the DBI
 */

#define BP_PCIE_REVID_IF_CODE_N      (8)      //!< Bit position for PCIE_REVID_IF_CODE_N.
#define BM_PCIE_REVID_IF_CODE_N      (0x0000ff00)  //!< Bit mask for PCIE_REVID_IF_CODE_N.

//! @brief Get value of PCIE_REVID_IF_CODE_N from a register value.
#define BG_PCIE_REVID_IF_CODE_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_REVID_IF_CODE_N) >> BP_PCIE_REVID_IF_CODE_N)

/* --- Register HW_PCIE_REVID, field SUB_CLASS_CODE_N[23:16] (RO)
 *
 * Subclass Code, writable through the DBI
 */

#define BP_PCIE_REVID_SUB_CLASS_CODE_N      (16)      //!< Bit position for PCIE_REVID_SUB_CLASS_CODE_N.
#define BM_PCIE_REVID_SUB_CLASS_CODE_N      (0x00ff0000)  //!< Bit mask for PCIE_REVID_SUB_CLASS_CODE_N.

//! @brief Get value of PCIE_REVID_SUB_CLASS_CODE_N from a register value.
#define BG_PCIE_REVID_SUB_CLASS_CODE_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_REVID_SUB_CLASS_CODE_N) >> BP_PCIE_REVID_SUB_CLASS_CODE_N)

/* --- Register HW_PCIE_REVID, field BASE_CLASS_CODE_N[31:24] (RO)
 *
 * Base Class Code, writable through the DBI
 */

#define BP_PCIE_REVID_BASE_CLASS_CODE_N      (24)      //!< Bit position for PCIE_REVID_BASE_CLASS_CODE_N.
#define BM_PCIE_REVID_BASE_CLASS_CODE_N      (0xff000000)  //!< Bit mask for PCIE_REVID_BASE_CLASS_CODE_N.

//! @brief Get value of PCIE_REVID_BASE_CLASS_CODE_N from a register value.
#define BG_PCIE_REVID_BASE_CLASS_CODE_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_REVID_BASE_CLASS_CODE_N) >> BP_PCIE_REVID_BASE_CLASS_CODE_N)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BIST - BIST Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BIST - BIST Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x0C  Byte: 0
 */
typedef union _hw_pcie_bist
{
    reg32_t U;
    struct _hw_pcie_bist_bitfields
    {
        unsigned CACHE_LINE_SIZE : 8; //!< [7:0] Cache Line Size The Cache Line Size register is RW for legacy compatibility purposes and is not applicable to PCI Express device functionality.
        unsigned MASTER_LATENCY_TIMER : 8; //!< [15:8] Master Latency Timer Not applicable for PCI Express, hardwired to 0.
        unsigned CONFIGURATION_HEADER_FORMAT : 7; //!< [22:16] Configuration Header Format Hardwired to 0 for type 0.
        unsigned MULTI_FUNCTION_DEVICE : 1; //!< [23] Multi Function Device The default value is 0 for a single function device (`CX_NFUNC = 1) or 1 for a multi-function device (`CX_NFUNC != 1).
        unsigned NOT_SUPPORTED_BY__CORE : 8; //!< [31:24] The BIST register functions are not supported by the core.
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

/* --- Register HW_PCIE_BIST, field CACHE_LINE_SIZE[7:0] (RW)
 *
 * Cache Line Size The Cache Line Size register is RW for legacy compatibility purposes and is not
 * applicable to PCI Express device functionality. Writing to the Cache Line Size register does not
 * impact functionality of the core.
 */

#define BP_PCIE_BIST_CACHE_LINE_SIZE      (0)      //!< Bit position for PCIE_BIST_CACHE_LINE_SIZE.
#define BM_PCIE_BIST_CACHE_LINE_SIZE      (0x000000ff)  //!< Bit mask for PCIE_BIST_CACHE_LINE_SIZE.

//! @brief Get value of PCIE_BIST_CACHE_LINE_SIZE from a register value.
#define BG_PCIE_BIST_CACHE_LINE_SIZE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BIST_CACHE_LINE_SIZE) >> BP_PCIE_BIST_CACHE_LINE_SIZE)

//! @brief Format value for bitfield PCIE_BIST_CACHE_LINE_SIZE.
#define BF_PCIE_BIST_CACHE_LINE_SIZE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_BIST_CACHE_LINE_SIZE) & BM_PCIE_BIST_CACHE_LINE_SIZE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CACHE_LINE_SIZE field to a new value.
#define BW_PCIE_BIST_CACHE_LINE_SIZE(v)   (HW_PCIE_BIST_WR((HW_PCIE_BIST_RD() & ~BM_PCIE_BIST_CACHE_LINE_SIZE) | BF_PCIE_BIST_CACHE_LINE_SIZE(v)))
#endif

/* --- Register HW_PCIE_BIST, field MASTER_LATENCY_TIMER[15:8] (RW)
 *
 * Master Latency Timer Not applicable for PCI Express, hardwired to 0.
 */

#define BP_PCIE_BIST_MASTER_LATENCY_TIMER      (8)      //!< Bit position for PCIE_BIST_MASTER_LATENCY_TIMER.
#define BM_PCIE_BIST_MASTER_LATENCY_TIMER      (0x0000ff00)  //!< Bit mask for PCIE_BIST_MASTER_LATENCY_TIMER.

//! @brief Get value of PCIE_BIST_MASTER_LATENCY_TIMER from a register value.
#define BG_PCIE_BIST_MASTER_LATENCY_TIMER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BIST_MASTER_LATENCY_TIMER) >> BP_PCIE_BIST_MASTER_LATENCY_TIMER)

//! @brief Format value for bitfield PCIE_BIST_MASTER_LATENCY_TIMER.
#define BF_PCIE_BIST_MASTER_LATENCY_TIMER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_BIST_MASTER_LATENCY_TIMER) & BM_PCIE_BIST_MASTER_LATENCY_TIMER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASTER_LATENCY_TIMER field to a new value.
#define BW_PCIE_BIST_MASTER_LATENCY_TIMER(v)   (HW_PCIE_BIST_WR((HW_PCIE_BIST_RD() & ~BM_PCIE_BIST_MASTER_LATENCY_TIMER) | BF_PCIE_BIST_MASTER_LATENCY_TIMER(v)))
#endif

/* --- Register HW_PCIE_BIST, field CONFIGURATION_HEADER_FORMAT[22:16] (RW)
 *
 * Configuration Header Format Hardwired to 0 for type 0.
 */

#define BP_PCIE_BIST_CONFIGURATION_HEADER_FORMAT      (16)      //!< Bit position for PCIE_BIST_CONFIGURATION_HEADER_FORMAT.
#define BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT      (0x007f0000)  //!< Bit mask for PCIE_BIST_CONFIGURATION_HEADER_FORMAT.

//! @brief Get value of PCIE_BIST_CONFIGURATION_HEADER_FORMAT from a register value.
#define BG_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT) >> BP_PCIE_BIST_CONFIGURATION_HEADER_FORMAT)

//! @brief Format value for bitfield PCIE_BIST_CONFIGURATION_HEADER_FORMAT.
#define BF_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_BIST_CONFIGURATION_HEADER_FORMAT) & BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CONFIGURATION_HEADER_FORMAT field to a new value.
#define BW_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)   (HW_PCIE_BIST_WR((HW_PCIE_BIST_RD() & ~BM_PCIE_BIST_CONFIGURATION_HEADER_FORMAT) | BF_PCIE_BIST_CONFIGURATION_HEADER_FORMAT(v)))
#endif

/* --- Register HW_PCIE_BIST, field MULTI_FUNCTION_DEVICE[23] (RW)
 *
 * Multi Function Device The default value is 0 for a single function device (`CX_NFUNC = 1) or 1
 * for a multi-function device (`CX_NFUNC != 1). The Multi Function Device bit is writable through
 * the DBI.
 */

#define BP_PCIE_BIST_MULTI_FUNCTION_DEVICE      (23)      //!< Bit position for PCIE_BIST_MULTI_FUNCTION_DEVICE.
#define BM_PCIE_BIST_MULTI_FUNCTION_DEVICE      (0x00800000)  //!< Bit mask for PCIE_BIST_MULTI_FUNCTION_DEVICE.

//! @brief Get value of PCIE_BIST_MULTI_FUNCTION_DEVICE from a register value.
#define BG_PCIE_BIST_MULTI_FUNCTION_DEVICE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BIST_MULTI_FUNCTION_DEVICE) >> BP_PCIE_BIST_MULTI_FUNCTION_DEVICE)

//! @brief Format value for bitfield PCIE_BIST_MULTI_FUNCTION_DEVICE.
#define BF_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_BIST_MULTI_FUNCTION_DEVICE) & BM_PCIE_BIST_MULTI_FUNCTION_DEVICE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MULTI_FUNCTION_DEVICE field to a new value.
#define BW_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)   (HW_PCIE_BIST_WR((HW_PCIE_BIST_RD() & ~BM_PCIE_BIST_MULTI_FUNCTION_DEVICE) | BF_PCIE_BIST_MULTI_FUNCTION_DEVICE(v)))
#endif

/* --- Register HW_PCIE_BIST, field NOT_SUPPORTED_BY__CORE[31:24] (RW)
 *
 * The BIST register functions are not supported by the core. All 8 bits of the BIST register are
 * hardwired to 0.
 */

#define BP_PCIE_BIST_NOT_SUPPORTED_BY__CORE      (24)      //!< Bit position for PCIE_BIST_NOT_SUPPORTED_BY__CORE.
#define BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE      (0xff000000)  //!< Bit mask for PCIE_BIST_NOT_SUPPORTED_BY__CORE.

//! @brief Get value of PCIE_BIST_NOT_SUPPORTED_BY__CORE from a register value.
#define BG_PCIE_BIST_NOT_SUPPORTED_BY__CORE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE) >> BP_PCIE_BIST_NOT_SUPPORTED_BY__CORE)

//! @brief Format value for bitfield PCIE_BIST_NOT_SUPPORTED_BY__CORE.
#define BF_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_BIST_NOT_SUPPORTED_BY__CORE) & BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NOT_SUPPORTED_BY__CORE field to a new value.
#define BW_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)   (HW_PCIE_BIST_WR((HW_PCIE_BIST_RD() & ~BM_PCIE_BIST_NOT_SUPPORTED_BY__CORE) | BF_PCIE_BIST_NOT_SUPPORTED_BY__CORE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR0 - Base Address 0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR0 - Base Address 0 (RO)
 *
 * Reset value: 0x0000000c
 *
 * Offset: 0x10-0x24  The core provides three pairs of 32-bit BARs for each implemented function.
 * Each pair (BARs 0 and 1, BARs 2 and 3, BARs 4 and 5) can be configured as follows:   One 64-bit
 * BAR: For example, BARs 0 and 1 are combined to form a single 64-bit BAR.  Two 32-bit BARs: For
 * example, BARs 0 and 1 are two independent 32-bit BARs.  One 32-bit BAR: For example, BAR 0 is a
 * 32-bit BAR and BAR 1 is either disabled or removed from the core altogether to reduce gate count.
 * In addition, you can configure each BAR to have its incoming Requests routed to either:   RTRGT1
 * The following sections describe how to set up the BAR types and sizes by programming values into
 * the base address registers. For more information about routing Requests to either RTRGT1 on a
 * BAR-by- BAR basis, see îReceive Filteringî on page 85.  The contents of the six BARs determine
 * the BAR configuration. The reset values of the BARs are determined by hardware configuration
 * options.  At runtime, application software can overwrite the BAR contents to reconfigure the BARs
 * (unless the affected BAR is removed during hardware configuration). Application software must
 * observe the rules listed below when writing to the BARs.  The rules for BAR configuration are the
 * same for all three pairs. Using BARs 0 and 1 as the example pair, the rules for BAR configuration
 * are:   Any pair (for example, BARs 0 and 1) can be configured as one 64-bit BAR, two 32-bit BARs,
 * or one 32-bit BAR.  BAR pairs cannot overlap to form a 64-bit BAR. For example, you cannot
 * combine BARs 1 and 2 to form a 64-bit BAR.    An I/O BAR must be a 32-bit BAR and cannot be
 * prefetchable.  If the device is configured as a PCI Express Endpoint (not a Legacy Endpoint),
 * then any memory that is configured as prefetchable must be a 64-bit memory BAR.  If BAR 0 is
 * configured as a 64-bit BAR:    BAR 1 is the upper 32 bits of the combined 64-bit BAR formed by
 * BARs 0 and 1. Therefore, BAR 1 must be disabled and cannot be configured independently.  BAR 0
 * must be a memory BAR and can be either prefetchable or non-prefetchable.  The contents of the BAR
 * 0 Mask register determine the number of writable bits in the 64-bit BAR, subject to the
 * restrictions described in îBAR Mask Registersî on page 536. The BAR 1 Mask register contains the
 * upper 32 bits of the BAR 0 Mask value.  BAR 0 can be disabled by writing 0 to bit 0 of the BAR 0
 * Mask register    If BAR 0 is configured as a 32-bit BAR:    You can configure BAR 1 as an
 * independent 32-bit BAR  BAR 0 can be configured as a memory BAR or an I/O BAR.  The contents of
 * the BAR 0 Mask register determine the number of writable bits in the 32-bit BAR 0, subject to the
 * restrictions described in îBAR Mask Registersî on page 536.  BAR 0 can be disabled by writing 0
 * to bit 0 of the BAR 0 Mask register    When BAR 0 is configured as a 32-bit BAR, BAR 1 is
 * available as an independent 32-bit BAR according to the following rules:    BAR 1 can be
 * configured as a memory BAR or an I/O BAR.  The contents of the BAR 1 Mask register determine the
 * number of writable bits in the 32-bit BAR 1, subject to the restrictions described in îBAR Mask
 * Registersî on page 536.       The same rules apply for pairs 2/3 and 4/5.  Offset: 0x10 (if
 * included in the core hardware configuration)
 */
typedef union _hw_pcie_bar0
{
    reg32_t U;
    struct _hw_pcie_bar0_bitfields
    {
        unsigned MEM_I_O : 1; //!< [0] Bits [3:0] are writable through the DBI.
        unsigned TYPE : 2; //!< [2:1] If BAR 0 is an I/O BAR, bit 2 the least significant bit of the base address and bit 1 is 0.
        unsigned PREF : 1; //!< [3] If BAR 0 is an I/O BAR, bit 3 is the second least significant bit of the base address.
        unsigned ADDRESS : 28; //!< [31:4] BAR 0 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 1).
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
#endif

/*
 * constants & macros for individual PCIE_BAR0 bitfields
 */

/* --- Register HW_PCIE_BAR0, field MEM_I_O[0] (RO)
 *
 * Bits [3:0] are writable through the DBI.
 *
 * Values:
 * 0 - = BAR 0 is a memory BAR
 * 1 - = BAR 0 is an I/O BAR
 */

#define BP_PCIE_BAR0_MEM_I_O      (0)      //!< Bit position for PCIE_BAR0_MEM_I_O.
#define BM_PCIE_BAR0_MEM_I_O      (0x00000001)  //!< Bit mask for PCIE_BAR0_MEM_I_O.

//! @brief Get value of PCIE_BAR0_MEM_I_O from a register value.
#define BG_PCIE_BAR0_MEM_I_O(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR0_MEM_I_O) >> BP_PCIE_BAR0_MEM_I_O)


/* --- Register HW_PCIE_BAR0, field TYPE[2:1] (RO)
 *
 * If BAR 0 is an I/O BAR, bit 2 the least significant bit of the base address and bit 1 is 0. Bits
 * [3:0] are writable through the DBI. If BAR 0 is a memory BAR, bits [2:1] determine the BAR type:
 *
 * Values:
 * 00 - = 32-bit BAR
 * 10 - = 64-bit BAR
 */

#define BP_PCIE_BAR0_TYPE      (1)      //!< Bit position for PCIE_BAR0_TYPE.
#define BM_PCIE_BAR0_TYPE      (0x00000006)  //!< Bit mask for PCIE_BAR0_TYPE.

//! @brief Get value of PCIE_BAR0_TYPE from a register value.
#define BG_PCIE_BAR0_TYPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR0_TYPE) >> BP_PCIE_BAR0_TYPE)


/* --- Register HW_PCIE_BAR0, field PREF[3] (RO)
 *
 * If BAR 0 is an I/O BAR, bit 3 is the second least significant bit of the base address. Bits [3:0]
 * are writable through the DBI. If BAR 0 is a memory BAR, bit 3 indicates if the memory region is
 * prefetchable:
 *
 * Values:
 * 0 - = Non-prefetchable
 * 1 - = Prefetchable
 */

#define BP_PCIE_BAR0_PREF      (3)      //!< Bit position for PCIE_BAR0_PREF.
#define BM_PCIE_BAR0_PREF      (0x00000008)  //!< Bit mask for PCIE_BAR0_PREF.

//! @brief Get value of PCIE_BAR0_PREF from a register value.
#define BG_PCIE_BAR0_PREF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR0_PREF) >> BP_PCIE_BAR0_PREF)


/* --- Register HW_PCIE_BAR0, field ADDRESS[31:4] (RO)
 *
 * BAR 0 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 1). The
 * BAR 0 Mask value determines which address bits are masked.
 */

#define BP_PCIE_BAR0_ADDRESS      (4)      //!< Bit position for PCIE_BAR0_ADDRESS.
#define BM_PCIE_BAR0_ADDRESS      (0xfffffff0)  //!< Bit mask for PCIE_BAR0_ADDRESS.

//! @brief Get value of PCIE_BAR0_ADDRESS from a register value.
#define BG_PCIE_BAR0_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR0_ADDRESS) >> BP_PCIE_BAR0_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR1 - Base Address 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR1 - Base Address 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x14
 */
typedef union _hw_pcie_bar1
{
    reg32_t U;
    struct _hw_pcie_bar1_bitfields
    {
        unsigned ADDRESS : 32; //!< [31:0] BAR 1 contains the upper 32 bits of the BAR 0 base address (bits [63:32]).
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
#endif

/*
 * constants & macros for individual PCIE_BAR1 bitfields
 */

/* --- Register HW_PCIE_BAR1, field ADDRESS[31:0] (RO)
 *
 * BAR 1 contains the upper 32 bits of the BAR 0 base address (bits [63:32]).
 */

#define BP_PCIE_BAR1_ADDRESS      (0)      //!< Bit position for PCIE_BAR1_ADDRESS.
#define BM_PCIE_BAR1_ADDRESS      (0xffffffff)  //!< Bit mask for PCIE_BAR1_ADDRESS.

//! @brief Get value of PCIE_BAR1_ADDRESS from a register value.
#define BG_PCIE_BAR1_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR1_ADDRESS) >> BP_PCIE_BAR1_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR2 - Base Address 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR2 - Base Address 2 (RO)
 *
 * Reset value: 0x00000008
 *
 * Offset: 0x18 (if included in the core hardware configuration)
 */
typedef union _hw_pcie_bar2
{
    reg32_t U;
    struct _hw_pcie_bar2_bitfields
    {
        unsigned MEM_I_O : 1; //!< [0] Bits [3:0] are writable through the DBI.
        unsigned TYPE : 2; //!< [2:1] If BAR 2 is an I/O BAR, bit 2 the least significant bit of the base address and bit 1 is 0.
        unsigned PREF : 1; //!< [3] If BAR 2 is an I/O BAR, bit 3 is the second least significant bit of the base address.
        unsigned ADDRESS : 28; //!< [31:4] BAR 2 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 3).
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
#endif

/*
 * constants & macros for individual PCIE_BAR2 bitfields
 */

/* --- Register HW_PCIE_BAR2, field MEM_I_O[0] (RO)
 *
 * Bits [3:0] are writable through the DBI.
 *
 * Values:
 * 0 - = BAR 2 is a memory BAR
 * 1 - = BAR 2 is an I/O BAR
 */

#define BP_PCIE_BAR2_MEM_I_O      (0)      //!< Bit position for PCIE_BAR2_MEM_I_O.
#define BM_PCIE_BAR2_MEM_I_O      (0x00000001)  //!< Bit mask for PCIE_BAR2_MEM_I_O.

//! @brief Get value of PCIE_BAR2_MEM_I_O from a register value.
#define BG_PCIE_BAR2_MEM_I_O(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR2_MEM_I_O) >> BP_PCIE_BAR2_MEM_I_O)


/* --- Register HW_PCIE_BAR2, field TYPE[2:1] (RO)
 *
 * If BAR 2 is an I/O BAR, bit 2 the least significant bit of the base address and bit 1 is 0. Bits
 * [3:0] are Writable through the DBI. If BAR 2 is a memory BAR, bits [2:1] determine the BAR type:
 *
 * Values:
 * 00 - = 32-bit BAR
 * 10 - = 64-bit BAR
 */

#define BP_PCIE_BAR2_TYPE      (1)      //!< Bit position for PCIE_BAR2_TYPE.
#define BM_PCIE_BAR2_TYPE      (0x00000006)  //!< Bit mask for PCIE_BAR2_TYPE.

//! @brief Get value of PCIE_BAR2_TYPE from a register value.
#define BG_PCIE_BAR2_TYPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR2_TYPE) >> BP_PCIE_BAR2_TYPE)


/* --- Register HW_PCIE_BAR2, field PREF[3] (RO)
 *
 * If BAR 2 is an I/O BAR, bit 3 is the second least significant bit of the base address. Bits [3:0]
 * are writable through the DBI. If BAR 2 is a memory BAR, bit 3 indicates if the memory region is
 * prefetchable:
 *
 * Values:
 * 0 - = Non-prefetchable
 * 1 - = Prefetchable
 */

#define BP_PCIE_BAR2_PREF      (3)      //!< Bit position for PCIE_BAR2_PREF.
#define BM_PCIE_BAR2_PREF      (0x00000008)  //!< Bit mask for PCIE_BAR2_PREF.

//! @brief Get value of PCIE_BAR2_PREF from a register value.
#define BG_PCIE_BAR2_PREF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR2_PREF) >> BP_PCIE_BAR2_PREF)


/* --- Register HW_PCIE_BAR2, field ADDRESS[31:4] (RO)
 *
 * BAR 2 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 3). The
 * BAR 2 Mask value determines which address bits are masked.
 */

#define BP_PCIE_BAR2_ADDRESS      (4)      //!< Bit position for PCIE_BAR2_ADDRESS.
#define BM_PCIE_BAR2_ADDRESS      (0xfffffff0)  //!< Bit mask for PCIE_BAR2_ADDRESS.

//! @brief Get value of PCIE_BAR2_ADDRESS from a register value.
#define BG_PCIE_BAR2_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR2_ADDRESS) >> BP_PCIE_BAR2_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR3 - Base Address 3
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR3 - Base Address 3 (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x1C (if included in the core hardware configuration)
 */
typedef union _hw_pcie_bar3
{
    reg32_t U;
    struct _hw_pcie_bar3_bitfields
    {
        unsigned ADDRESS : 32; //!< [31:0] BAR 3 bit definitions are the same as the BAR 2 bit definitions.
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
#endif

/*
 * constants & macros for individual PCIE_BAR3 bitfields
 */

/* --- Register HW_PCIE_BAR3, field ADDRESS[31:0] (RO)
 *
 * BAR 3 bit definitions are the same as the BAR 2 bit definitions.
 */

#define BP_PCIE_BAR3_ADDRESS      (0)      //!< Bit position for PCIE_BAR3_ADDRESS.
#define BM_PCIE_BAR3_ADDRESS      (0xffffffff)  //!< Bit mask for PCIE_BAR3_ADDRESS.

//! @brief Get value of PCIE_BAR3_ADDRESS from a register value.
#define BG_PCIE_BAR3_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR3_ADDRESS) >> BP_PCIE_BAR3_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR4 - Base Address 4
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR4 - Base Address 4 (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x20 (if included in the core hardware configuration)
 */
typedef union _hw_pcie_bar4
{
    reg32_t U;
    struct _hw_pcie_bar4_bitfields
    {
        unsigned MEM_I_O : 1; //!< [0] MEM4_SPACE_DECODER_N Bits [3:0] are writable through the DBI.
        unsigned TYPE : 2; //!< [2:1] BAR4_TYPE_N for memory BAR If BAR 4 is an I/O BAR, bit 2 the least significant bit of the base address and bit 1 is 0.
        unsigned PREF : 1; //!< [3] PREFETCHABLE4_N for memory BAR 0 for I/O BAR If BAR 4 is an I/O BAR, bit 3 is the second least significant bit of the base address.
        unsigned ADDRESS : 28; //!< [31:4] BAR 4 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 5).
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
#endif

/*
 * constants & macros for individual PCIE_BAR4 bitfields
 */

/* --- Register HW_PCIE_BAR4, field MEM_I_O[0] (RO)
 *
 * MEM4_SPACE_DECODER_N Bits [3:0] are writable through the DBI.
 *
 * Values:
 * 0 - = BAR 4 is a memory BAR
 * 1 - = BAR 4 is an I/O BAR
 */

#define BP_PCIE_BAR4_MEM_I_O      (0)      //!< Bit position for PCIE_BAR4_MEM_I_O.
#define BM_PCIE_BAR4_MEM_I_O      (0x00000001)  //!< Bit mask for PCIE_BAR4_MEM_I_O.

//! @brief Get value of PCIE_BAR4_MEM_I_O from a register value.
#define BG_PCIE_BAR4_MEM_I_O(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR4_MEM_I_O) >> BP_PCIE_BAR4_MEM_I_O)


/* --- Register HW_PCIE_BAR4, field TYPE[2:1] (RO)
 *
 * BAR4_TYPE_N for memory BAR If BAR 4 is an I/O BAR, bit 2 the least significant bit of the base
 * address and bit 1 is 0. Bits [3:0] are writable through the DBI. If BAR 4 is a memory BAR, bits
 * [2:1] determine the BAR type:
 *
 * Values:
 * 00 - = 32-bit BAR
 * 10 - = 64-bit BAR
 */

#define BP_PCIE_BAR4_TYPE      (1)      //!< Bit position for PCIE_BAR4_TYPE.
#define BM_PCIE_BAR4_TYPE      (0x00000006)  //!< Bit mask for PCIE_BAR4_TYPE.

//! @brief Get value of PCIE_BAR4_TYPE from a register value.
#define BG_PCIE_BAR4_TYPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR4_TYPE) >> BP_PCIE_BAR4_TYPE)


/* --- Register HW_PCIE_BAR4, field PREF[3] (RO)
 *
 * PREFETCHABLE4_N for memory BAR 0 for I/O BAR If BAR 4 is an I/O BAR, bit 3 is the second least
 * significant bit of the base address. Bits [3:0] are writable through the DBI. If BAR 4 is a
 * memory BAR, bit 3 indicates if the memory region is prefetchable:
 *
 * Values:
 * 0 - = Non-prefetchable
 * 1 - = Prefetchable
 */

#define BP_PCIE_BAR4_PREF      (3)      //!< Bit position for PCIE_BAR4_PREF.
#define BM_PCIE_BAR4_PREF      (0x00000008)  //!< Bit mask for PCIE_BAR4_PREF.

//! @brief Get value of PCIE_BAR4_PREF from a register value.
#define BG_PCIE_BAR4_PREF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR4_PREF) >> BP_PCIE_BAR4_PREF)


/* --- Register HW_PCIE_BAR4, field ADDRESS[31:4] (RO)
 *
 * BAR 4 base address bits (for a 64-bit BAR, the remaining upper address bits are in BAR 5). The
 * BAR 4 Mask value determines which address bits are masked.
 */

#define BP_PCIE_BAR4_ADDRESS      (4)      //!< Bit position for PCIE_BAR4_ADDRESS.
#define BM_PCIE_BAR4_ADDRESS      (0xfffffff0)  //!< Bit mask for PCIE_BAR4_ADDRESS.

//! @brief Get value of PCIE_BAR4_ADDRESS from a register value.
#define BG_PCIE_BAR4_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR4_ADDRESS) >> BP_PCIE_BAR4_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_BAR5 - Base Address 5
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_BAR5 - Base Address 5 (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x24 (if included in the core hardware configuration)
 */
typedef union _hw_pcie_bar5
{
    reg32_t U;
    struct _hw_pcie_bar5_bitfields
    {
        unsigned ADDRESS : 32; //!< [31:0] Configuration- dependent If BAR 4 is a 64-bit BAR, BAR 5 contains the upper 32 bits of the BAR 4 base address (bits 63:32).
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
#endif

/*
 * constants & macros for individual PCIE_BAR5 bitfields
 */

/* --- Register HW_PCIE_BAR5, field ADDRESS[31:0] (RO)
 *
 * Configuration- dependent If BAR 4 is a 64-bit BAR, BAR 5 contains the upper 32 bits of the BAR 4
 * base address (bits 63:32). If BAR 4 is a 32-bit BAR, BAR 5 can be independently programmed as an
 * additional 32-bit BAR or can be excluded from the core hardware configuration. If programmed as
 * an independent 32-bit BAR, the BAR 5 bit definitions are the same as the BAR 4 bit definitions.
 */

#define BP_PCIE_BAR5_ADDRESS      (0)      //!< Bit position for PCIE_BAR5_ADDRESS.
#define BM_PCIE_BAR5_ADDRESS      (0xffffffff)  //!< Bit mask for PCIE_BAR5_ADDRESS.

//! @brief Get value of PCIE_BAR5_ADDRESS from a register value.
#define BG_PCIE_BAR5_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_BAR5_ADDRESS) >> BP_PCIE_BAR5_ADDRESS)

//-------------------------------------------------------------------------------------------
// HW_PCIE_CISP - CardBus CIS Pointer Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_CISP - CardBus CIS Pointer Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x28
 */
typedef union _hw_pcie_cisp
{
    reg32_t U;
    struct _hw_pcie_cisp_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_CISP bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_PCIE_SSID - Subsystem ID and Subsystem Vendor ID Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_SSID - Subsystem ID and Subsystem Vendor ID Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x2C
 */
typedef union _hw_pcie_ssid
{
    reg32_t U;
    struct _hw_pcie_ssid_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_SSID bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_PCIE_EROMBAR - Expansion ROM Base Address Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_EROMBAR - Expansion ROM Base Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x30
 */
typedef union _hw_pcie_erombar
{
    reg32_t U;
    struct _hw_pcie_erombar_bitfields
    {
        unsigned ENABLE : 1; //!< [0] Expansion ROM Enable
        unsigned RESERVED0 : 10; //!< [10:1] Reserved
        unsigned ADDRESS : 21; //!< [31:11] Expansion ROM Address
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

/* --- Register HW_PCIE_EROMBAR, field ENABLE[0] (RW)
 *
 * Expansion ROM Enable
 */

#define BP_PCIE_EROMBAR_ENABLE      (0)      //!< Bit position for PCIE_EROMBAR_ENABLE.
#define BM_PCIE_EROMBAR_ENABLE      (0x00000001)  //!< Bit mask for PCIE_EROMBAR_ENABLE.

//! @brief Get value of PCIE_EROMBAR_ENABLE from a register value.
#define BG_PCIE_EROMBAR_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_EROMBAR_ENABLE) >> BP_PCIE_EROMBAR_ENABLE)

//! @brief Format value for bitfield PCIE_EROMBAR_ENABLE.
#define BF_PCIE_EROMBAR_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_EROMBAR_ENABLE) & BM_PCIE_EROMBAR_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_PCIE_EROMBAR_ENABLE(v)   (HW_PCIE_EROMBAR_WR((HW_PCIE_EROMBAR_RD() & ~BM_PCIE_EROMBAR_ENABLE) | BF_PCIE_EROMBAR_ENABLE(v)))
#endif

/* --- Register HW_PCIE_EROMBAR, field ADDRESS[31:11] (RW)
 *
 * Expansion ROM Address
 */

#define BP_PCIE_EROMBAR_ADDRESS      (11)      //!< Bit position for PCIE_EROMBAR_ADDRESS.
#define BM_PCIE_EROMBAR_ADDRESS      (0xfffff800)  //!< Bit mask for PCIE_EROMBAR_ADDRESS.

//! @brief Get value of PCIE_EROMBAR_ADDRESS from a register value.
#define BG_PCIE_EROMBAR_ADDRESS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_EROMBAR_ADDRESS) >> BP_PCIE_EROMBAR_ADDRESS)

//! @brief Format value for bitfield PCIE_EROMBAR_ADDRESS.
#define BF_PCIE_EROMBAR_ADDRESS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_EROMBAR_ADDRESS) & BM_PCIE_EROMBAR_ADDRESS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRESS field to a new value.
#define BW_PCIE_EROMBAR_ADDRESS(v)   (HW_PCIE_EROMBAR_WR((HW_PCIE_EROMBAR_RD() & ~BM_PCIE_EROMBAR_ADDRESS) | BF_PCIE_EROMBAR_ADDRESS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_CAPPR - Capability Pointer Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_CAPPR - Capability Pointer Register (RO)
 *
 * Reset value: 0x00000040
 *
 * Offset: 0x34  Byte: 0
 */
typedef union _hw_pcie_cappr
{
    reg32_t U;
    struct _hw_pcie_cappr_bitfields
    {
        unsigned CFG_NEXT_PTR : 8; //!< [7:0] First Capability Pointer.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_CAPPR bitfields
 */

/* --- Register HW_PCIE_CAPPR, field CFG_NEXT_PTR[7:0] (RO)
 *
 * First Capability Pointer. See Tables 5-2 and 5-3 on page 510.
 */

#define BP_PCIE_CAPPR_CFG_NEXT_PTR      (0)      //!< Bit position for PCIE_CAPPR_CFG_NEXT_PTR.
#define BM_PCIE_CAPPR_CFG_NEXT_PTR      (0x000000ff)  //!< Bit mask for PCIE_CAPPR_CFG_NEXT_PTR.

//! @brief Get value of PCIE_CAPPR_CFG_NEXT_PTR from a register value.
#define BG_PCIE_CAPPR_CFG_NEXT_PTR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CAPPR_CFG_NEXT_PTR) >> BP_PCIE_CAPPR_CFG_NEXT_PTR)

//-------------------------------------------------------------------------------------------
// HW_PCIE_ILR - Interrupt Line and Pin Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_ILR - Interrupt Line and Pin Register (RW)
 *
 * Reset value: 0x000001ff
 *
 * Offset: 0x3C  Byte: 0
 */
typedef union _hw_pcie_ilr
{
    reg32_t U;
    struct _hw_pcie_ilr_bitfields
    {
        unsigned INTERRUPT_LINE : 8; //!< [7:0] Interrupt Line Value in this register is system architecture specific.
        unsigned INT_PIN_MAPPING_N : 8; //!< [15:8] Interrupt Pin Identifies the legacy interrupt Message that the device (or device function) uses.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
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

/* --- Register HW_PCIE_ILR, field INTERRUPT_LINE[7:0] (RW)
 *
 * Interrupt Line Value in this register is system architecture specific. POST software will write
 * the routing information into this register as it initializes and configures the system.
 */

#define BP_PCIE_ILR_INTERRUPT_LINE      (0)      //!< Bit position for PCIE_ILR_INTERRUPT_LINE.
#define BM_PCIE_ILR_INTERRUPT_LINE      (0x000000ff)  //!< Bit mask for PCIE_ILR_INTERRUPT_LINE.

//! @brief Get value of PCIE_ILR_INTERRUPT_LINE from a register value.
#define BG_PCIE_ILR_INTERRUPT_LINE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ILR_INTERRUPT_LINE) >> BP_PCIE_ILR_INTERRUPT_LINE)

//! @brief Format value for bitfield PCIE_ILR_INTERRUPT_LINE.
#define BF_PCIE_ILR_INTERRUPT_LINE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ILR_INTERRUPT_LINE) & BM_PCIE_ILR_INTERRUPT_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INTERRUPT_LINE field to a new value.
#define BW_PCIE_ILR_INTERRUPT_LINE(v)   (HW_PCIE_ILR_WR((HW_PCIE_ILR_RD() & ~BM_PCIE_ILR_INTERRUPT_LINE) | BF_PCIE_ILR_INTERRUPT_LINE(v)))
#endif

/* --- Register HW_PCIE_ILR, field INT_PIN_MAPPING_N[15:8] (RW)
 *
 * Interrupt Pin Identifies the legacy interrupt Message that the device (or device function) uses.
 * In a single-function configuration, the core only uses INTA. The Interrupt Pin register is
 * writable through the DBI. Valid values are:
 *
 * Values:
 * 0x00 - The device (or function) does not use legacy interrupt
 * 0x01 - The device (or function) uses INTA
 * 0x02 - The device (or function) uses INTB
 * 0x03 - The device (or function) uses INTC
 * 0x04 - The device (or function) uses INTD
 */

#define BP_PCIE_ILR_INT_PIN_MAPPING_N      (8)      //!< Bit position for PCIE_ILR_INT_PIN_MAPPING_N.
#define BM_PCIE_ILR_INT_PIN_MAPPING_N      (0x0000ff00)  //!< Bit mask for PCIE_ILR_INT_PIN_MAPPING_N.

//! @brief Get value of PCIE_ILR_INT_PIN_MAPPING_N from a register value.
#define BG_PCIE_ILR_INT_PIN_MAPPING_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ILR_INT_PIN_MAPPING_N) >> BP_PCIE_ILR_INT_PIN_MAPPING_N)

//! @brief Format value for bitfield PCIE_ILR_INT_PIN_MAPPING_N.
#define BF_PCIE_ILR_INT_PIN_MAPPING_N(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ILR_INT_PIN_MAPPING_N) & BM_PCIE_ILR_INT_PIN_MAPPING_N)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INT_PIN_MAPPING_N field to a new value.
#define BW_PCIE_ILR_INT_PIN_MAPPING_N(v)   (HW_PCIE_ILR_WR((HW_PCIE_ILR_RD() & ~BM_PCIE_ILR_INT_PIN_MAPPING_N) | BF_PCIE_ILR_INT_PIN_MAPPING_N(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PCIE_PMCR - Power Management Capability Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PMCR - Power Management Capability Register (RO)
 *
 * Reset value: 0xdbc35001
 *
 * The core implements power management capabilities. The Capability Pointer field in the
 * configuration header points to the PCI Power Management registers as the first extended
 * capability by default.  The extent of the power management implementation in the core includes:
 * Power Management register space  Link state information (provided to both the application logic
 * and PHY interfaces)  Power management-ready clock and reset implementation   The following
 * sections describe the PCI Power Management registers implemented in the core. See the PCI Power
 * Management specification and the PCI Express 3.0 Specification for more details.  Offset:
 * `CFG_PM_CAP
 */
typedef union _hw_pcie_pmcr
{
    reg32_t U;
    struct _hw_pcie_pmcr_bitfields
    {
        unsigned POWER_MANAGEMENT_CAPABILITY_ID : 8; //!< [7:0] Power Management Capability ID
        unsigned NEXT_CAPABILITY_POINTER : 8; //!< [15:8] Next Capability Pointer See and .
        unsigned POWER_MANAGEMENT_SPECIFICATION_VERSION : 3; //!< [18:16] Power Management specification version, writable through the DBI
        unsigned PME_CLOCK : 1; //!< [19] PME Clock, hardwired to 0
        unsigned RESERVED0 : 1; //!< [20] Reserved
        unsigned DSI : 1; //!< [21] Device Specific Initialization (DSI), writable through the DBI
        unsigned AUX_CURRENT : 3; //!< [24:22] AUX Current, writable through the DBI
        unsigned D1_SUPPORT : 1; //!< [25] D1 Support, writable through the DBI
        unsigned D2_SUPPORT : 1; //!< [26] D2 Support, writable through the DBI
        unsigned PME_SUPPORT : 5; //!< [31:27] PME_Support Identifies the power states from which the core can generate PME Messages.
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
#endif

/*
 * constants & macros for individual PCIE_PMCR bitfields
 */

/* --- Register HW_PCIE_PMCR, field POWER_MANAGEMENT_CAPABILITY_ID[7:0] (RO)
 *
 * Power Management Capability ID
 */

#define BP_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID      (0)      //!< Bit position for PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID.
#define BM_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID      (0x000000ff)  //!< Bit mask for PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID.

//! @brief Get value of PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID from a register value.
#define BG_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID) >> BP_PCIE_PMCR_POWER_MANAGEMENT_CAPABILITY_ID)

/* --- Register HW_PCIE_PMCR, field NEXT_CAPABILITY_POINTER[15:8] (RO)
 *
 * Next Capability Pointer See and .
 */

#define BP_PCIE_PMCR_NEXT_CAPABILITY_POINTER      (8)      //!< Bit position for PCIE_PMCR_NEXT_CAPABILITY_POINTER.
#define BM_PCIE_PMCR_NEXT_CAPABILITY_POINTER      (0x0000ff00)  //!< Bit mask for PCIE_PMCR_NEXT_CAPABILITY_POINTER.

//! @brief Get value of PCIE_PMCR_NEXT_CAPABILITY_POINTER from a register value.
#define BG_PCIE_PMCR_NEXT_CAPABILITY_POINTER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_NEXT_CAPABILITY_POINTER) >> BP_PCIE_PMCR_NEXT_CAPABILITY_POINTER)

/* --- Register HW_PCIE_PMCR, field POWER_MANAGEMENT_SPECIFICATION_VERSION[18:16] (RO)
 *
 * Power Management specification version, writable through the DBI
 */

#define BP_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION      (16)      //!< Bit position for PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION.
#define BM_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION      (0x00070000)  //!< Bit mask for PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION.

//! @brief Get value of PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION from a register value.
#define BG_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION) >> BP_PCIE_PMCR_POWER_MANAGEMENT_SPECIFICATION_VERSION)

/* --- Register HW_PCIE_PMCR, field PME_CLOCK[19] (RO)
 *
 * PME Clock, hardwired to 0
 */

#define BP_PCIE_PMCR_PME_CLOCK      (19)      //!< Bit position for PCIE_PMCR_PME_CLOCK.
#define BM_PCIE_PMCR_PME_CLOCK      (0x00080000)  //!< Bit mask for PCIE_PMCR_PME_CLOCK.

//! @brief Get value of PCIE_PMCR_PME_CLOCK from a register value.
#define BG_PCIE_PMCR_PME_CLOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_PME_CLOCK) >> BP_PCIE_PMCR_PME_CLOCK)

/* --- Register HW_PCIE_PMCR, field DSI[21] (RO)
 *
 * Device Specific Initialization (DSI), writable through the DBI
 */

#define BP_PCIE_PMCR_DSI      (21)      //!< Bit position for PCIE_PMCR_DSI.
#define BM_PCIE_PMCR_DSI      (0x00200000)  //!< Bit mask for PCIE_PMCR_DSI.

//! @brief Get value of PCIE_PMCR_DSI from a register value.
#define BG_PCIE_PMCR_DSI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_DSI) >> BP_PCIE_PMCR_DSI)

/* --- Register HW_PCIE_PMCR, field AUX_CURRENT[24:22] (RO)
 *
 * AUX Current, writable through the DBI
 */

#define BP_PCIE_PMCR_AUX_CURRENT      (22)      //!< Bit position for PCIE_PMCR_AUX_CURRENT.
#define BM_PCIE_PMCR_AUX_CURRENT      (0x01c00000)  //!< Bit mask for PCIE_PMCR_AUX_CURRENT.

//! @brief Get value of PCIE_PMCR_AUX_CURRENT from a register value.
#define BG_PCIE_PMCR_AUX_CURRENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_AUX_CURRENT) >> BP_PCIE_PMCR_AUX_CURRENT)

/* --- Register HW_PCIE_PMCR, field D1_SUPPORT[25] (RO)
 *
 * D1 Support, writable through the DBI
 */

#define BP_PCIE_PMCR_D1_SUPPORT      (25)      //!< Bit position for PCIE_PMCR_D1_SUPPORT.
#define BM_PCIE_PMCR_D1_SUPPORT      (0x02000000)  //!< Bit mask for PCIE_PMCR_D1_SUPPORT.

//! @brief Get value of PCIE_PMCR_D1_SUPPORT from a register value.
#define BG_PCIE_PMCR_D1_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_D1_SUPPORT) >> BP_PCIE_PMCR_D1_SUPPORT)

/* --- Register HW_PCIE_PMCR, field D2_SUPPORT[26] (RO)
 *
 * D2 Support, writable through the DBI
 */

#define BP_PCIE_PMCR_D2_SUPPORT      (26)      //!< Bit position for PCIE_PMCR_D2_SUPPORT.
#define BM_PCIE_PMCR_D2_SUPPORT      (0x04000000)  //!< Bit mask for PCIE_PMCR_D2_SUPPORT.

//! @brief Get value of PCIE_PMCR_D2_SUPPORT from a register value.
#define BG_PCIE_PMCR_D2_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_D2_SUPPORT) >> BP_PCIE_PMCR_D2_SUPPORT)

/* --- Register HW_PCIE_PMCR, field PME_SUPPORT[31:27] (RO)
 *
 * PME_Support Identifies the power states from which the core can generate PME Messages. A value of
 * 0 for any bit indicates that the device (or function) is not capable of generating PME Messages
 * while in that power state: Bit 11: If set, PME Messages can be generated from D0 Bit 12: If set,
 * PME Messages can be generated from D1 Bit 13: If set, PME Messages can be generated from D2 Bit
 * 14: If set, PME Messages can be generated from D3 hot Bit 15: If set, PME Messages can be
 * generated from D3 cold The PME_Support field is writable through the DBI.
 */

#define BP_PCIE_PMCR_PME_SUPPORT      (27)      //!< Bit position for PCIE_PMCR_PME_SUPPORT.
#define BM_PCIE_PMCR_PME_SUPPORT      (0xf8000000)  //!< Bit mask for PCIE_PMCR_PME_SUPPORT.

//! @brief Get value of PCIE_PMCR_PME_SUPPORT from a register value.
#define BG_PCIE_PMCR_PME_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCR_PME_SUPPORT) >> BP_PCIE_PMCR_PME_SUPPORT)

//-------------------------------------------------------------------------------------------
// HW_PCIE_PMCSR - Power Management Control and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PMCSR - Power Management Control and Status Register (RW)
 *
 * Reset value: 0x00000004
 *
 * Offset: `CFG_PM_CAP + 0x04
 */
typedef union _hw_pcie_pmcsr
{
    reg32_t U;
    struct _hw_pcie_pmcsr_bitfields
    {
        unsigned POWER_STATE : 2; //!< [1:0] Power State The written value is ignored if the specific state is not supported.
        unsigned RESERVED0 : 1; //!< [2] Reserved
        unsigned NO_SOFT_RESET : 1; //!< [3] No Soft Reset, writable through the DBI
        unsigned RESERVED1 : 4; //!< [7:4] Reserved
        unsigned PME_ENABLE : 1; //!< [8] PME Enable (sticky bit) A value of 1 indicates that the device is enabled to generate PME.
        unsigned DATA_SELECT : 4; //!< [12:9] Data Select (not supported)
        unsigned DATA_SCALE : 2; //!< [14:13] Data Scale (not supported)
        unsigned PME_STATUS : 1; //!< [15] PME Status Indicates if a previously enabled PME event occurred or not.
        unsigned RESERVED2 : 6; //!< [21:16] Reserved
        unsigned B2_B3_SUPPORT : 1; //!< [22] B2/B3 Support, hardwired to 0
        unsigned BUS_POWER_CLOCK_CONTROL_ENABLE : 1; //!< [23] Bus Power/Clock Control Enable, hardwired to 0
        unsigned DATA_REGISTER_FOR_ADDITIONAL_INFORMATION : 8; //!< [31:24] Data register for additional information (not supported)
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

/* --- Register HW_PCIE_PMCSR, field POWER_STATE[1:0] (RW)
 *
 * Power State The written value is ignored if the specific state is not supported. Controls the
 * device power state:
 *
 * Values:
 * 00 - D0
 * 01 - D1
 * 10 - D2
 * 11 - D3
 */

#define BP_PCIE_PMCSR_POWER_STATE      (0)      //!< Bit position for PCIE_PMCSR_POWER_STATE.
#define BM_PCIE_PMCSR_POWER_STATE      (0x00000003)  //!< Bit mask for PCIE_PMCSR_POWER_STATE.

//! @brief Get value of PCIE_PMCSR_POWER_STATE from a register value.
#define BG_PCIE_PMCSR_POWER_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_POWER_STATE) >> BP_PCIE_PMCSR_POWER_STATE)

//! @brief Format value for bitfield PCIE_PMCSR_POWER_STATE.
#define BF_PCIE_PMCSR_POWER_STATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_POWER_STATE) & BM_PCIE_PMCSR_POWER_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_STATE field to a new value.
#define BW_PCIE_PMCSR_POWER_STATE(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_POWER_STATE) | BF_PCIE_PMCSR_POWER_STATE(v)))
#endif


/* --- Register HW_PCIE_PMCSR, field NO_SOFT_RESET[3] (RW)
 *
 * No Soft Reset, writable through the DBI
 */

#define BP_PCIE_PMCSR_NO_SOFT_RESET      (3)      //!< Bit position for PCIE_PMCSR_NO_SOFT_RESET.
#define BM_PCIE_PMCSR_NO_SOFT_RESET      (0x00000008)  //!< Bit mask for PCIE_PMCSR_NO_SOFT_RESET.

//! @brief Get value of PCIE_PMCSR_NO_SOFT_RESET from a register value.
#define BG_PCIE_PMCSR_NO_SOFT_RESET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_NO_SOFT_RESET) >> BP_PCIE_PMCSR_NO_SOFT_RESET)

//! @brief Format value for bitfield PCIE_PMCSR_NO_SOFT_RESET.
#define BF_PCIE_PMCSR_NO_SOFT_RESET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_NO_SOFT_RESET) & BM_PCIE_PMCSR_NO_SOFT_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NO_SOFT_RESET field to a new value.
#define BW_PCIE_PMCSR_NO_SOFT_RESET(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_NO_SOFT_RESET) | BF_PCIE_PMCSR_NO_SOFT_RESET(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field PME_ENABLE[8] (RW)
 *
 * PME Enable (sticky bit) A value of 1 indicates that the device is enabled to generate PME.
 */

#define BP_PCIE_PMCSR_PME_ENABLE      (8)      //!< Bit position for PCIE_PMCSR_PME_ENABLE.
#define BM_PCIE_PMCSR_PME_ENABLE      (0x00000100)  //!< Bit mask for PCIE_PMCSR_PME_ENABLE.

//! @brief Get value of PCIE_PMCSR_PME_ENABLE from a register value.
#define BG_PCIE_PMCSR_PME_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_PME_ENABLE) >> BP_PCIE_PMCSR_PME_ENABLE)

//! @brief Format value for bitfield PCIE_PMCSR_PME_ENABLE.
#define BF_PCIE_PMCSR_PME_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_PME_ENABLE) & BM_PCIE_PMCSR_PME_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_ENABLE field to a new value.
#define BW_PCIE_PMCSR_PME_ENABLE(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_PME_ENABLE) | BF_PCIE_PMCSR_PME_ENABLE(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field DATA_SELECT[12:9] (RW)
 *
 * Data Select (not supported)
 */

#define BP_PCIE_PMCSR_DATA_SELECT      (9)      //!< Bit position for PCIE_PMCSR_DATA_SELECT.
#define BM_PCIE_PMCSR_DATA_SELECT      (0x00001e00)  //!< Bit mask for PCIE_PMCSR_DATA_SELECT.

//! @brief Get value of PCIE_PMCSR_DATA_SELECT from a register value.
#define BG_PCIE_PMCSR_DATA_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_DATA_SELECT) >> BP_PCIE_PMCSR_DATA_SELECT)

//! @brief Format value for bitfield PCIE_PMCSR_DATA_SELECT.
#define BF_PCIE_PMCSR_DATA_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_DATA_SELECT) & BM_PCIE_PMCSR_DATA_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_SELECT field to a new value.
#define BW_PCIE_PMCSR_DATA_SELECT(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_DATA_SELECT) | BF_PCIE_PMCSR_DATA_SELECT(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field DATA_SCALE[14:13] (RW)
 *
 * Data Scale (not supported)
 */

#define BP_PCIE_PMCSR_DATA_SCALE      (13)      //!< Bit position for PCIE_PMCSR_DATA_SCALE.
#define BM_PCIE_PMCSR_DATA_SCALE      (0x00006000)  //!< Bit mask for PCIE_PMCSR_DATA_SCALE.

//! @brief Get value of PCIE_PMCSR_DATA_SCALE from a register value.
#define BG_PCIE_PMCSR_DATA_SCALE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_DATA_SCALE) >> BP_PCIE_PMCSR_DATA_SCALE)

//! @brief Format value for bitfield PCIE_PMCSR_DATA_SCALE.
#define BF_PCIE_PMCSR_DATA_SCALE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_DATA_SCALE) & BM_PCIE_PMCSR_DATA_SCALE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_SCALE field to a new value.
#define BW_PCIE_PMCSR_DATA_SCALE(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_DATA_SCALE) | BF_PCIE_PMCSR_DATA_SCALE(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field PME_STATUS[15] (RW)
 *
 * PME Status Indicates if a previously enabled PME event occurred or not.
 */

#define BP_PCIE_PMCSR_PME_STATUS      (15)      //!< Bit position for PCIE_PMCSR_PME_STATUS.
#define BM_PCIE_PMCSR_PME_STATUS      (0x00008000)  //!< Bit mask for PCIE_PMCSR_PME_STATUS.

//! @brief Get value of PCIE_PMCSR_PME_STATUS from a register value.
#define BG_PCIE_PMCSR_PME_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_PME_STATUS) >> BP_PCIE_PMCSR_PME_STATUS)

//! @brief Format value for bitfield PCIE_PMCSR_PME_STATUS.
#define BF_PCIE_PMCSR_PME_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_PME_STATUS) & BM_PCIE_PMCSR_PME_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_STATUS field to a new value.
#define BW_PCIE_PMCSR_PME_STATUS(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_PME_STATUS) | BF_PCIE_PMCSR_PME_STATUS(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field B2_B3_SUPPORT[22] (RW)
 *
 * B2/B3 Support, hardwired to 0
 */

#define BP_PCIE_PMCSR_B2_B3_SUPPORT      (22)      //!< Bit position for PCIE_PMCSR_B2_B3_SUPPORT.
#define BM_PCIE_PMCSR_B2_B3_SUPPORT      (0x00400000)  //!< Bit mask for PCIE_PMCSR_B2_B3_SUPPORT.

//! @brief Get value of PCIE_PMCSR_B2_B3_SUPPORT from a register value.
#define BG_PCIE_PMCSR_B2_B3_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_B2_B3_SUPPORT) >> BP_PCIE_PMCSR_B2_B3_SUPPORT)

//! @brief Format value for bitfield PCIE_PMCSR_B2_B3_SUPPORT.
#define BF_PCIE_PMCSR_B2_B3_SUPPORT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_B2_B3_SUPPORT) & BM_PCIE_PMCSR_B2_B3_SUPPORT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the B2_B3_SUPPORT field to a new value.
#define BW_PCIE_PMCSR_B2_B3_SUPPORT(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_B2_B3_SUPPORT) | BF_PCIE_PMCSR_B2_B3_SUPPORT(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field BUS_POWER_CLOCK_CONTROL_ENABLE[23] (RW)
 *
 * Bus Power/Clock Control Enable, hardwired to 0
 */

#define BP_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE      (23)      //!< Bit position for PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE.
#define BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE      (0x00800000)  //!< Bit mask for PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE.

//! @brief Get value of PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE from a register value.
#define BG_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE) >> BP_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE)

//! @brief Format value for bitfield PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE.
#define BF_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE) & BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUS_POWER_CLOCK_CONTROL_ENABLE field to a new value.
#define BW_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE) | BF_PCIE_PMCSR_BUS_POWER_CLOCK_CONTROL_ENABLE(v)))
#endif

/* --- Register HW_PCIE_PMCSR, field DATA_REGISTER_FOR_ADDITIONAL_INFORMATION[31:24] (RW)
 *
 * Data register for additional information (not supported)
 */

#define BP_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION      (24)      //!< Bit position for PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION.
#define BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION      (0xff000000)  //!< Bit mask for PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION.

//! @brief Get value of PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION from a register value.
#define BG_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION) >> BP_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION)

//! @brief Format value for bitfield PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION.
#define BF_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION) & BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_REGISTER_FOR_ADDITIONAL_INFORMATION field to a new value.
#define BW_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)   (HW_PCIE_PMCSR_WR((HW_PCIE_PMCSR_RD() & ~BM_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION) | BF_PCIE_PMCSR_DATA_REGISTER_FOR_ADDITIONAL_INFORMATION(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_CIDR - PCI Express Capability ID Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_CIDR - PCI Express Capability ID Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The core implements the PCI Express Capability Structure as defined in the PCI Express 3.0
 * Specification.  Offset: CFG_PCIE_CAP + 0x00
 */
typedef union _hw_pcie_cidr
{
    reg32_t U;
    struct _hw_pcie_cidr_bitfields
    {
        unsigned PCI_EXPRESS_CAPABILITY_ID : 8; //!< [7:0] PCI Express Capability ID
        unsigned NEXT_CAPABILITY_POINTER : 8; //!< [15:8] Next Capability Pointer See Tables 5-214 and 5-215 on page 638.
        unsigned PCI_EXPRESS_CAPABILITY_VERSION : 4; //!< [19:16] PCI Express Capability Version
        unsigned DEVICE_PORT_TYPE : 4; //!< [23:20] Device/Port Type Indicates the specific type of this PCI Express Function.
        unsigned SLOT_IMPLEMENTED : 1; //!< [24] Slot Implemented, writable through the DBI
        unsigned INTERRUPT_MESSAGE_NUMBER : 5; //!< [29:25] Interrupt Message Number Updated by hardware, writable through the DBI.
        unsigned RESERVED0 : 2; //!< [31:30] RsvdP
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
#endif

/*
 * constants & macros for individual PCIE_CIDR bitfields
 */

/* --- Register HW_PCIE_CIDR, field PCI_EXPRESS_CAPABILITY_ID[7:0] (RO)
 *
 * PCI Express Capability ID
 */

#define BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID      (0)      //!< Bit position for PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID.
#define BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID      (0x000000ff)  //!< Bit mask for PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID.

//! @brief Get value of PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID from a register value.
#define BG_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID) >> BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_ID)

/* --- Register HW_PCIE_CIDR, field NEXT_CAPABILITY_POINTER[15:8] (RO)
 *
 * Next Capability Pointer See Tables 5-214 and 5-215 on page 638.
 */

#define BP_PCIE_CIDR_NEXT_CAPABILITY_POINTER      (8)      //!< Bit position for PCIE_CIDR_NEXT_CAPABILITY_POINTER.
#define BM_PCIE_CIDR_NEXT_CAPABILITY_POINTER      (0x0000ff00)  //!< Bit mask for PCIE_CIDR_NEXT_CAPABILITY_POINTER.

//! @brief Get value of PCIE_CIDR_NEXT_CAPABILITY_POINTER from a register value.
#define BG_PCIE_CIDR_NEXT_CAPABILITY_POINTER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_NEXT_CAPABILITY_POINTER) >> BP_PCIE_CIDR_NEXT_CAPABILITY_POINTER)

/* --- Register HW_PCIE_CIDR, field PCI_EXPRESS_CAPABILITY_VERSION[19:16] (RO)
 *
 * PCI Express Capability Version
 */

#define BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION      (16)      //!< Bit position for PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION.
#define BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION      (0x000f0000)  //!< Bit mask for PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION.

//! @brief Get value of PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION from a register value.
#define BG_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION) >> BP_PCIE_CIDR_PCI_EXPRESS_CAPABILITY_VERSION)

/* --- Register HW_PCIE_CIDR, field DEVICE_PORT_TYPE[23:20] (RO)
 *
 * Device/Port Type Indicates the specific type of this PCI Express Function. Supported encodings
 * for RC and DM(RC mode) are: •4'b0100: Root Port of PCI Express Root Complex Note: All other
 * encodings (including those for PCI/PCI-X bridges and RC Integrated Endpoint) are NOT supported.
 */

#define BP_PCIE_CIDR_DEVICE_PORT_TYPE      (20)      //!< Bit position for PCIE_CIDR_DEVICE_PORT_TYPE.
#define BM_PCIE_CIDR_DEVICE_PORT_TYPE      (0x00f00000)  //!< Bit mask for PCIE_CIDR_DEVICE_PORT_TYPE.

//! @brief Get value of PCIE_CIDR_DEVICE_PORT_TYPE from a register value.
#define BG_PCIE_CIDR_DEVICE_PORT_TYPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_DEVICE_PORT_TYPE) >> BP_PCIE_CIDR_DEVICE_PORT_TYPE)

/* --- Register HW_PCIE_CIDR, field SLOT_IMPLEMENTED[24] (RO)
 *
 * Slot Implemented, writable through the DBI
 */

#define BP_PCIE_CIDR_SLOT_IMPLEMENTED      (24)      //!< Bit position for PCIE_CIDR_SLOT_IMPLEMENTED.
#define BM_PCIE_CIDR_SLOT_IMPLEMENTED      (0x01000000)  //!< Bit mask for PCIE_CIDR_SLOT_IMPLEMENTED.

//! @brief Get value of PCIE_CIDR_SLOT_IMPLEMENTED from a register value.
#define BG_PCIE_CIDR_SLOT_IMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_SLOT_IMPLEMENTED) >> BP_PCIE_CIDR_SLOT_IMPLEMENTED)

/* --- Register HW_PCIE_CIDR, field INTERRUPT_MESSAGE_NUMBER[29:25] (RO)
 *
 * Interrupt Message Number Updated by hardware, writable through the DBI.
 */

#define BP_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER      (25)      //!< Bit position for PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER.
#define BM_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER      (0x3e000000)  //!< Bit mask for PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER.

//! @brief Get value of PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER from a register value.
#define BG_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER) >> BP_PCIE_CIDR_INTERRUPT_MESSAGE_NUMBER)

//-------------------------------------------------------------------------------------------
// HW_PCIE_DCR - Device Capabilities Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_DCR - Device Capabilities Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x04
 */
typedef union _hw_pcie_dcr
{
    reg32_t U;
    struct _hw_pcie_dcr_bitfields
    {
        unsigned MAX_PAYLOAD_SIZE_SUPPORTED : 3; //!< [2:0] Max_Payload_Size Supported, writable through the DBI
        unsigned PHANTOM_FUNCTION_SUPPORTED : 2; //!< [4:3] Phantom Function Supported This field is writable through the DBI.
        unsigned EXTENDED_TAG_FIELD_SUPPORTED : 1; //!< [5] Extended Tag Field Supported This bit is writable through the DBI.
        unsigned ENDPOINT_L0S_ACCEPTABLE_LATENCY : 3; //!< [8:6] Endpoint L0s Acceptable Latency Must be 0x0 for non-Endpoint devices.
        unsigned ENDPOINT_L1_ACCEPTABLE_LATENCY : 3; //!< [11:9] Endpoint L1 Acceptable Latency Must be 0x0 for non-Endpoint devices.
        unsigned RESERVED0 : 3; //!< [14:12] Reserved.
        unsigned ROLE_BASED_ERROR_REPORTING : 1; //!< [15] Role-Based Error Reporting, writable through the DBI.
        unsigned RESERVED1 : 2; //!< [17:16] Reserved
        unsigned CAPTURED_SLOT_POWER_LIMIT_VALUE : 8; //!< [25:18] Captured Slot Power Limit Value Upstream port only.
        unsigned CAPTURED_SLOT_POWER_LIMIT_SCALE : 2; //!< [27:26] Captured Slot Power Limit Scale Upstream port only.
        unsigned RESERVED2 : 4; //!< [31:28] Reserved
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

/* --- Register HW_PCIE_DCR, field MAX_PAYLOAD_SIZE_SUPPORTED[2:0] (RW)
 *
 * Max_Payload_Size Supported, writable through the DBI
 */

#define BP_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED      (0)      //!< Bit position for PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED.
#define BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED      (0x00000007)  //!< Bit mask for PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED.

//! @brief Get value of PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED from a register value.
#define BG_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED) >> BP_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED)

//! @brief Format value for bitfield PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED.
#define BF_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED) & BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_PAYLOAD_SIZE_SUPPORTED field to a new value.
#define BW_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED) | BF_PCIE_DCR_MAX_PAYLOAD_SIZE_SUPPORTED(v)))
#endif

/* --- Register HW_PCIE_DCR, field PHANTOM_FUNCTION_SUPPORTED[4:3] (RW)
 *
 * Phantom Function Supported This field is writable through the DBI. However, Phantom Function is
 * not supported. Therefore, the application must not write any value other than 0x0 to this field.
 */

#define BP_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED      (3)      //!< Bit position for PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED.
#define BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED      (0x00000018)  //!< Bit mask for PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED.

//! @brief Get value of PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED from a register value.
#define BG_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED) >> BP_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED)

//! @brief Format value for bitfield PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED.
#define BF_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED) & BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHANTOM_FUNCTION_SUPPORTED field to a new value.
#define BW_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED) | BF_PCIE_DCR_PHANTOM_FUNCTION_SUPPORTED(v)))
#endif

/* --- Register HW_PCIE_DCR, field EXTENDED_TAG_FIELD_SUPPORTED[5] (RW)
 *
 * Extended Tag Field Supported This bit is writable through the DBI. However, if the core supports
 * only 5 bits of TAG, then the application must not write a 1 to this field because the hardware to
 * support more than 32 tags are not implemented.
 */

#define BP_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED      (5)      //!< Bit position for PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED.
#define BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED      (0x00000020)  //!< Bit mask for PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED.

//! @brief Get value of PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED from a register value.
#define BG_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED) >> BP_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED)

//! @brief Format value for bitfield PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED.
#define BF_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED) & BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTENDED_TAG_FIELD_SUPPORTED field to a new value.
#define BW_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED) | BF_PCIE_DCR_EXTENDED_TAG_FIELD_SUPPORTED(v)))
#endif

/* --- Register HW_PCIE_DCR, field ENDPOINT_L0S_ACCEPTABLE_LATENCY[8:6] (RW)
 *
 * Endpoint L0s Acceptable Latency Must be 0x0 for non-Endpoint devices.
 */

#define BP_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY      (6)      //!< Bit position for PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY.
#define BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY      (0x000001c0)  //!< Bit mask for PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY.

//! @brief Get value of PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY from a register value.
#define BG_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY) >> BP_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY)

//! @brief Format value for bitfield PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY.
#define BF_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY) & BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPOINT_L0S_ACCEPTABLE_LATENCY field to a new value.
#define BW_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY) | BF_PCIE_DCR_ENDPOINT_L0S_ACCEPTABLE_LATENCY(v)))
#endif

/* --- Register HW_PCIE_DCR, field ENDPOINT_L1_ACCEPTABLE_LATENCY[11:9] (RW)
 *
 * Endpoint L1 Acceptable Latency Must be 0x0 for non-Endpoint devices.
 */

#define BP_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY      (9)      //!< Bit position for PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY.
#define BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY      (0x00000e00)  //!< Bit mask for PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY.

//! @brief Get value of PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY from a register value.
#define BG_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY) >> BP_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY)

//! @brief Format value for bitfield PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY.
#define BF_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY) & BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPOINT_L1_ACCEPTABLE_LATENCY field to a new value.
#define BW_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY) | BF_PCIE_DCR_ENDPOINT_L1_ACCEPTABLE_LATENCY(v)))
#endif

/* --- Register HW_PCIE_DCR, field ROLE_BASED_ERROR_REPORTING[15] (RW)
 *
 * Role-Based Error Reporting, writable through the DBI. Required to be set for device compliant to
 * 1.1 spec and later.
 */

#define BP_PCIE_DCR_ROLE_BASED_ERROR_REPORTING      (15)      //!< Bit position for PCIE_DCR_ROLE_BASED_ERROR_REPORTING.
#define BM_PCIE_DCR_ROLE_BASED_ERROR_REPORTING      (0x00008000)  //!< Bit mask for PCIE_DCR_ROLE_BASED_ERROR_REPORTING.

//! @brief Get value of PCIE_DCR_ROLE_BASED_ERROR_REPORTING from a register value.
#define BG_PCIE_DCR_ROLE_BASED_ERROR_REPORTING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_ROLE_BASED_ERROR_REPORTING) >> BP_PCIE_DCR_ROLE_BASED_ERROR_REPORTING)

//! @brief Format value for bitfield PCIE_DCR_ROLE_BASED_ERROR_REPORTING.
#define BF_PCIE_DCR_ROLE_BASED_ERROR_REPORTING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_ROLE_BASED_ERROR_REPORTING) & BM_PCIE_DCR_ROLE_BASED_ERROR_REPORTING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROLE_BASED_ERROR_REPORTING field to a new value.
#define BW_PCIE_DCR_ROLE_BASED_ERROR_REPORTING(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_ROLE_BASED_ERROR_REPORTING) | BF_PCIE_DCR_ROLE_BASED_ERROR_REPORTING(v)))
#endif

/* --- Register HW_PCIE_DCR, field CAPTURED_SLOT_POWER_LIMIT_VALUE[25:18] (RW)
 *
 * Captured Slot Power Limit Value Upstream port only.
 */

#define BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE      (18)      //!< Bit position for PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE.
#define BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE      (0x03fc0000)  //!< Bit mask for PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE.

//! @brief Get value of PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE from a register value.
#define BG_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE) >> BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE)

//! @brief Format value for bitfield PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE.
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPTURED_SLOT_POWER_LIMIT_VALUE field to a new value.
#define BW_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE) | BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_VALUE(v)))
#endif

/* --- Register HW_PCIE_DCR, field CAPTURED_SLOT_POWER_LIMIT_SCALE[27:26] (RW)
 *
 * Captured Slot Power Limit Scale Upstream port only.
 */

#define BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE      (26)      //!< Bit position for PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE.
#define BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE      (0x0c000000)  //!< Bit mask for PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE.

//! @brief Get value of PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE from a register value.
#define BG_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE) >> BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE)

//! @brief Format value for bitfield PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE.
#define BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE) & BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPTURED_SLOT_POWER_LIMIT_SCALE field to a new value.
#define BW_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)   (HW_PCIE_DCR_WR((HW_PCIE_DCR_RD() & ~BM_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE) | BF_PCIE_DCR_CAPTURED_SLOT_POWER_LIMIT_SCALE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_DCONR - Device Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_DCONR - Device Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x08
 */
typedef union _hw_pcie_dconr
{
    reg32_t U;
    struct _hw_pcie_dconr_bitfields
    {
        unsigned CORRECTABLE_ERROR_REPORTING_ENABLE : 1; //!< [0] Correctable Error Reporting Enable
        unsigned NON_FATAL_ERROR_REPORTING_ENABLE : 1; //!< [1] Non-Fatal Error Reporting Enable
        unsigned FATAL_ERROR_REPORTING_ENABLE : 1; //!< [2] Fatal Error Reporting Enable
        unsigned UNSUPPORTED_REQUEST_REPORTING_ENABLE : 1; //!< [3] Unsupported Request Reporting Enable
        unsigned ENABLE_RELAXED_ORDERING : 1; //!< [4] Enable Relaxed Ordering
        unsigned MAX_PAYLOAD_SIZE : 3; //!< [7:5] Max_Payload_Size
        unsigned EXTENDED_TAG_FIELD_ENABLE : 1; //!< [8] Extended Tag Field Enable
        unsigned PHANTOM_FUNCTION_ENABLE : 1; //!< [9] Phantom Function Enable
        unsigned AUX_POWER_PM_ENABLE : 1; //!< [10] AUX Power PM Enable
        unsigned ENABLE_NO_SNOOP : 1; //!< [11] Enable No Snoop
        unsigned MAX_READ_REQUEST_SIZE : 3; //!< [14:12] Max_Read_Request_Size
        unsigned RESERVED0 : 1; //!< [15] Reserved
        unsigned CORRECTABLE_ERROR_DETECTED : 1; //!< [16] Correctable Error Detected Errors are logged in this register regardless of whether error reporting is enabled in the Device Control register.
        unsigned NON_FATAL_ERROR_DETECTED : 1; //!< [17] Non-Fatal Error detected Errors are logged in this register regardless of whether error reporting is enabled in the Device Control register.
        unsigned FATAL_ERROR_DETECTED : 1; //!< [18] Fatal Error Detected Errors are logged in this register regardless of whether error reporting is enabled in the Device Control register.
        unsigned UNSUPPORTED_REQUEST_DETECTED : 1; //!< [19] Unsupported Request Detected Errors are logged in this register regardless of whether error reporting is enabled in the Device Control register.
        unsigned AUX_POWER_DETECTED : 1; //!< [20] Aux Power Detected From sys_aux_pwr_det input port.
        unsigned TRANSACTION_PENDING : 1; //!< [21] Transaction Pending Hard-wired to 0.
        unsigned RESERVED1 : 10; //!< [31:22] Reserved
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

/* --- Register HW_PCIE_DCONR, field CORRECTABLE_ERROR_REPORTING_ENABLE[0] (RW)
 *
 * Correctable Error Reporting Enable
 */

#define BP_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE      (0)      //!< Bit position for PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE.
#define BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE      (0x00000001)  //!< Bit mask for PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE) >> BP_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE.
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE) & BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORRECTABLE_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE) | BF_PCIE_DCONR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field NON_FATAL_ERROR_REPORTING_ENABLE[1] (RW)
 *
 * Non-Fatal Error Reporting Enable
 */

#define BP_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE      (1)      //!< Bit position for PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE.
#define BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE      (0x00000002)  //!< Bit mask for PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE) >> BP_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE.
#define BF_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE) & BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NON_FATAL_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE) | BF_PCIE_DCONR_NON_FATAL_ERROR_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field FATAL_ERROR_REPORTING_ENABLE[2] (RW)
 *
 * Fatal Error Reporting Enable
 */

#define BP_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE      (2)      //!< Bit position for PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE.
#define BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE      (0x00000004)  //!< Bit mask for PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE) >> BP_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE.
#define BF_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE) & BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FATAL_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE) | BF_PCIE_DCONR_FATAL_ERROR_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field UNSUPPORTED_REQUEST_REPORTING_ENABLE[3] (RW)
 *
 * Unsupported Request Reporting Enable
 */

#define BP_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE      (3)      //!< Bit position for PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE.
#define BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE      (0x00000008)  //!< Bit mask for PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE.

//! @brief Get value of PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE from a register value.
#define BG_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE) >> BP_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE.
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNSUPPORTED_REQUEST_REPORTING_ENABLE field to a new value.
#define BW_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE) | BF_PCIE_DCONR_UNSUPPORTED_REQUEST_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field ENABLE_RELAXED_ORDERING[4] (RW)
 *
 * Enable Relaxed Ordering
 */

#define BP_PCIE_DCONR_ENABLE_RELAXED_ORDERING      (4)      //!< Bit position for PCIE_DCONR_ENABLE_RELAXED_ORDERING.
#define BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING      (0x00000010)  //!< Bit mask for PCIE_DCONR_ENABLE_RELAXED_ORDERING.

//! @brief Get value of PCIE_DCONR_ENABLE_RELAXED_ORDERING from a register value.
#define BG_PCIE_DCONR_ENABLE_RELAXED_ORDERING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING) >> BP_PCIE_DCONR_ENABLE_RELAXED_ORDERING)

//! @brief Format value for bitfield PCIE_DCONR_ENABLE_RELAXED_ORDERING.
#define BF_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_ENABLE_RELAXED_ORDERING) & BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_RELAXED_ORDERING field to a new value.
#define BW_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_ENABLE_RELAXED_ORDERING) | BF_PCIE_DCONR_ENABLE_RELAXED_ORDERING(v)))
#endif

/* --- Register HW_PCIE_DCONR, field MAX_PAYLOAD_SIZE[7:5] (RW)
 *
 * Max_Payload_Size
 */

#define BP_PCIE_DCONR_MAX_PAYLOAD_SIZE      (5)      //!< Bit position for PCIE_DCONR_MAX_PAYLOAD_SIZE.
#define BM_PCIE_DCONR_MAX_PAYLOAD_SIZE      (0x000000e0)  //!< Bit mask for PCIE_DCONR_MAX_PAYLOAD_SIZE.

//! @brief Get value of PCIE_DCONR_MAX_PAYLOAD_SIZE from a register value.
#define BG_PCIE_DCONR_MAX_PAYLOAD_SIZE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_MAX_PAYLOAD_SIZE) >> BP_PCIE_DCONR_MAX_PAYLOAD_SIZE)

//! @brief Format value for bitfield PCIE_DCONR_MAX_PAYLOAD_SIZE.
#define BF_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_MAX_PAYLOAD_SIZE) & BM_PCIE_DCONR_MAX_PAYLOAD_SIZE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_PAYLOAD_SIZE field to a new value.
#define BW_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_MAX_PAYLOAD_SIZE) | BF_PCIE_DCONR_MAX_PAYLOAD_SIZE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field EXTENDED_TAG_FIELD_ENABLE[8] (RW)
 *
 * Extended Tag Field Enable
 */

#define BP_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE      (8)      //!< Bit position for PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE.
#define BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE      (0x00000100)  //!< Bit mask for PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE.

//! @brief Get value of PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE from a register value.
#define BG_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE) >> BP_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE.
#define BF_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE) & BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTENDED_TAG_FIELD_ENABLE field to a new value.
#define BW_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE) | BF_PCIE_DCONR_EXTENDED_TAG_FIELD_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field PHANTOM_FUNCTION_ENABLE[9] (RW)
 *
 * Phantom Function Enable
 */

#define BP_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE      (9)      //!< Bit position for PCIE_DCONR_PHANTOM_FUNCTION_ENABLE.
#define BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE      (0x00000200)  //!< Bit mask for PCIE_DCONR_PHANTOM_FUNCTION_ENABLE.

//! @brief Get value of PCIE_DCONR_PHANTOM_FUNCTION_ENABLE from a register value.
#define BG_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE) >> BP_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_PHANTOM_FUNCTION_ENABLE.
#define BF_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE) & BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PHANTOM_FUNCTION_ENABLE field to a new value.
#define BW_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE) | BF_PCIE_DCONR_PHANTOM_FUNCTION_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field AUX_POWER_PM_ENABLE[10] (RW)
 *
 * AUX Power PM Enable
 */

#define BP_PCIE_DCONR_AUX_POWER_PM_ENABLE      (10)      //!< Bit position for PCIE_DCONR_AUX_POWER_PM_ENABLE.
#define BM_PCIE_DCONR_AUX_POWER_PM_ENABLE      (0x00000400)  //!< Bit mask for PCIE_DCONR_AUX_POWER_PM_ENABLE.

//! @brief Get value of PCIE_DCONR_AUX_POWER_PM_ENABLE from a register value.
#define BG_PCIE_DCONR_AUX_POWER_PM_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_AUX_POWER_PM_ENABLE) >> BP_PCIE_DCONR_AUX_POWER_PM_ENABLE)

//! @brief Format value for bitfield PCIE_DCONR_AUX_POWER_PM_ENABLE.
#define BF_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_AUX_POWER_PM_ENABLE) & BM_PCIE_DCONR_AUX_POWER_PM_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUX_POWER_PM_ENABLE field to a new value.
#define BW_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_AUX_POWER_PM_ENABLE) | BF_PCIE_DCONR_AUX_POWER_PM_ENABLE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field ENABLE_NO_SNOOP[11] (RW)
 *
 * Enable No Snoop
 */

#define BP_PCIE_DCONR_ENABLE_NO_SNOOP      (11)      //!< Bit position for PCIE_DCONR_ENABLE_NO_SNOOP.
#define BM_PCIE_DCONR_ENABLE_NO_SNOOP      (0x00000800)  //!< Bit mask for PCIE_DCONR_ENABLE_NO_SNOOP.

//! @brief Get value of PCIE_DCONR_ENABLE_NO_SNOOP from a register value.
#define BG_PCIE_DCONR_ENABLE_NO_SNOOP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_ENABLE_NO_SNOOP) >> BP_PCIE_DCONR_ENABLE_NO_SNOOP)

//! @brief Format value for bitfield PCIE_DCONR_ENABLE_NO_SNOOP.
#define BF_PCIE_DCONR_ENABLE_NO_SNOOP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_ENABLE_NO_SNOOP) & BM_PCIE_DCONR_ENABLE_NO_SNOOP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_NO_SNOOP field to a new value.
#define BW_PCIE_DCONR_ENABLE_NO_SNOOP(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_ENABLE_NO_SNOOP) | BF_PCIE_DCONR_ENABLE_NO_SNOOP(v)))
#endif

/* --- Register HW_PCIE_DCONR, field MAX_READ_REQUEST_SIZE[14:12] (RW)
 *
 * Max_Read_Request_Size
 */

#define BP_PCIE_DCONR_MAX_READ_REQUEST_SIZE      (12)      //!< Bit position for PCIE_DCONR_MAX_READ_REQUEST_SIZE.
#define BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE      (0x00007000)  //!< Bit mask for PCIE_DCONR_MAX_READ_REQUEST_SIZE.

//! @brief Get value of PCIE_DCONR_MAX_READ_REQUEST_SIZE from a register value.
#define BG_PCIE_DCONR_MAX_READ_REQUEST_SIZE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE) >> BP_PCIE_DCONR_MAX_READ_REQUEST_SIZE)

//! @brief Format value for bitfield PCIE_DCONR_MAX_READ_REQUEST_SIZE.
#define BF_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_MAX_READ_REQUEST_SIZE) & BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_READ_REQUEST_SIZE field to a new value.
#define BW_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_MAX_READ_REQUEST_SIZE) | BF_PCIE_DCONR_MAX_READ_REQUEST_SIZE(v)))
#endif

/* --- Register HW_PCIE_DCONR, field CORRECTABLE_ERROR_DETECTED[16] (RW)
 *
 * Correctable Error Detected Errors are logged in this register regardless of whether error
 * reporting is enabled in the Device Control register.
 */

#define BP_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED      (16)      //!< Bit position for PCIE_DCONR_CORRECTABLE_ERROR_DETECTED.
#define BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED      (0x00010000)  //!< Bit mask for PCIE_DCONR_CORRECTABLE_ERROR_DETECTED.

//! @brief Get value of PCIE_DCONR_CORRECTABLE_ERROR_DETECTED from a register value.
#define BG_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED) >> BP_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED)

//! @brief Format value for bitfield PCIE_DCONR_CORRECTABLE_ERROR_DETECTED.
#define BF_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED) & BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORRECTABLE_ERROR_DETECTED field to a new value.
#define BW_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED) | BF_PCIE_DCONR_CORRECTABLE_ERROR_DETECTED(v)))
#endif

/* --- Register HW_PCIE_DCONR, field NON_FATAL_ERROR_DETECTED[17] (RW)
 *
 * Non-Fatal Error detected Errors are logged in this register regardless of whether error reporting
 * is enabled in the Device Control register.
 */

#define BP_PCIE_DCONR_NON_FATAL_ERROR_DETECTED      (17)      //!< Bit position for PCIE_DCONR_NON_FATAL_ERROR_DETECTED.
#define BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED      (0x00020000)  //!< Bit mask for PCIE_DCONR_NON_FATAL_ERROR_DETECTED.

//! @brief Get value of PCIE_DCONR_NON_FATAL_ERROR_DETECTED from a register value.
#define BG_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED) >> BP_PCIE_DCONR_NON_FATAL_ERROR_DETECTED)

//! @brief Format value for bitfield PCIE_DCONR_NON_FATAL_ERROR_DETECTED.
#define BF_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_NON_FATAL_ERROR_DETECTED) & BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NON_FATAL_ERROR_DETECTED field to a new value.
#define BW_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_NON_FATAL_ERROR_DETECTED) | BF_PCIE_DCONR_NON_FATAL_ERROR_DETECTED(v)))
#endif

/* --- Register HW_PCIE_DCONR, field FATAL_ERROR_DETECTED[18] (RW)
 *
 * Fatal Error Detected Errors are logged in this register regardless of whether error reporting is
 * enabled in the Device Control register.
 */

#define BP_PCIE_DCONR_FATAL_ERROR_DETECTED      (18)      //!< Bit position for PCIE_DCONR_FATAL_ERROR_DETECTED.
#define BM_PCIE_DCONR_FATAL_ERROR_DETECTED      (0x00040000)  //!< Bit mask for PCIE_DCONR_FATAL_ERROR_DETECTED.

//! @brief Get value of PCIE_DCONR_FATAL_ERROR_DETECTED from a register value.
#define BG_PCIE_DCONR_FATAL_ERROR_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_FATAL_ERROR_DETECTED) >> BP_PCIE_DCONR_FATAL_ERROR_DETECTED)

//! @brief Format value for bitfield PCIE_DCONR_FATAL_ERROR_DETECTED.
#define BF_PCIE_DCONR_FATAL_ERROR_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_FATAL_ERROR_DETECTED) & BM_PCIE_DCONR_FATAL_ERROR_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FATAL_ERROR_DETECTED field to a new value.
#define BW_PCIE_DCONR_FATAL_ERROR_DETECTED(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_FATAL_ERROR_DETECTED) | BF_PCIE_DCONR_FATAL_ERROR_DETECTED(v)))
#endif

/* --- Register HW_PCIE_DCONR, field UNSUPPORTED_REQUEST_DETECTED[19] (RW)
 *
 * Unsupported Request Detected Errors are logged in this register regardless of whether error
 * reporting is enabled in the Device Control register.
 */

#define BP_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED      (19)      //!< Bit position for PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED.
#define BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED      (0x00080000)  //!< Bit mask for PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED.

//! @brief Get value of PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED from a register value.
#define BG_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED) >> BP_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED)

//! @brief Format value for bitfield PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED.
#define BF_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED) & BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNSUPPORTED_REQUEST_DETECTED field to a new value.
#define BW_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED) | BF_PCIE_DCONR_UNSUPPORTED_REQUEST_DETECTED(v)))
#endif

/* --- Register HW_PCIE_DCONR, field AUX_POWER_DETECTED[20] (RW)
 *
 * Aux Power Detected From sys_aux_pwr_det input port.
 */

#define BP_PCIE_DCONR_AUX_POWER_DETECTED      (20)      //!< Bit position for PCIE_DCONR_AUX_POWER_DETECTED.
#define BM_PCIE_DCONR_AUX_POWER_DETECTED      (0x00100000)  //!< Bit mask for PCIE_DCONR_AUX_POWER_DETECTED.

//! @brief Get value of PCIE_DCONR_AUX_POWER_DETECTED from a register value.
#define BG_PCIE_DCONR_AUX_POWER_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_AUX_POWER_DETECTED) >> BP_PCIE_DCONR_AUX_POWER_DETECTED)

//! @brief Format value for bitfield PCIE_DCONR_AUX_POWER_DETECTED.
#define BF_PCIE_DCONR_AUX_POWER_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_AUX_POWER_DETECTED) & BM_PCIE_DCONR_AUX_POWER_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUX_POWER_DETECTED field to a new value.
#define BW_PCIE_DCONR_AUX_POWER_DETECTED(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_AUX_POWER_DETECTED) | BF_PCIE_DCONR_AUX_POWER_DETECTED(v)))
#endif

/* --- Register HW_PCIE_DCONR, field TRANSACTION_PENDING[21] (RW)
 *
 * Transaction Pending Hard-wired to 0.
 */

#define BP_PCIE_DCONR_TRANSACTION_PENDING      (21)      //!< Bit position for PCIE_DCONR_TRANSACTION_PENDING.
#define BM_PCIE_DCONR_TRANSACTION_PENDING      (0x00200000)  //!< Bit mask for PCIE_DCONR_TRANSACTION_PENDING.

//! @brief Get value of PCIE_DCONR_TRANSACTION_PENDING from a register value.
#define BG_PCIE_DCONR_TRANSACTION_PENDING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCONR_TRANSACTION_PENDING) >> BP_PCIE_DCONR_TRANSACTION_PENDING)

//! @brief Format value for bitfield PCIE_DCONR_TRANSACTION_PENDING.
#define BF_PCIE_DCONR_TRANSACTION_PENDING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCONR_TRANSACTION_PENDING) & BM_PCIE_DCONR_TRANSACTION_PENDING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRANSACTION_PENDING field to a new value.
#define BW_PCIE_DCONR_TRANSACTION_PENDING(v)   (HW_PCIE_DCONR_WR((HW_PCIE_DCONR_RD() & ~BM_PCIE_DCONR_TRANSACTION_PENDING) | BF_PCIE_DCONR_TRANSACTION_PENDING(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_LCR - Link Capabilities Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_LCR - Link Capabilities Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x0C
 */
typedef union _hw_pcie_lcr
{
    reg32_t U;
    struct _hw_pcie_lcr_bitfields
    {
        unsigned MAX_LINK_SPEEDS : 4; //!< [3:0] Max Link Speeds Indicates the supported maximum Link speeds of the associated Port.
        unsigned MAXIMUM_LINK_WIDTH : 6; //!< [9:4] Maximum Link Width Writable through the DBI.
        unsigned ACTIVE_STATE_LINK_PM_SUPPORT : 2; //!< [11:10] Active State Link PM Support The default value is the value you specify during core configuration, writable through the DBI.
        unsigned L0S_EXIT_LATENCY : 3; //!< [14:12] L0s Exit Latency Writable through the DBI.
        unsigned L1_EXIT_LATENCY : 3; //!< [17:15] L1 Exit Latency Writable through the DBI.
        unsigned CLOCK_POWER_MANAGEMENT : 1; //!< [18] Clock Power Management Component can tolerate the removal of refclk via CLKREQ# (if supported).
        unsigned SURPRISE_DOWN_ERROR_REPORTING_CAPABLE : 1; //!< [19] Surprise Down Error Reporting Capable Not supported, hardwired to 0x0.
        unsigned DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE : 1; //!< [20] Data Link Layer Active Reporting Capable Hardwired to 1 for Downstream Ports and 0 for Upstream Ports.
        unsigned LINK_BANDWIDTH_NOTIFICATION_CAPABILITY : 1; //!< [21] Link Bandwidth Notification Capability Hardwired to 1 for Downstream Ports and 0 for Upstream Ports.
        unsigned RESERVED0 : 2; //!< [23:22] Reserved
        unsigned PORT_NUMBER : 8; //!< [31:24] Port Number
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
#endif

/*
 * constants & macros for individual PCIE_LCR bitfields
 */

/* --- Register HW_PCIE_LCR, field MAX_LINK_SPEEDS[3:0] (RO)
 *
 * Max Link Speeds Indicates the supported maximum Link speeds of the associated Port. The encoding
 * is the binary value of the bit location in the Supported Link Speeds Vector (in the Link
 * Capabilities 2 register) that corresponds to the maximum Link speed. This field is writable
 * through the DBI.
 */

#define BP_PCIE_LCR_MAX_LINK_SPEEDS      (0)      //!< Bit position for PCIE_LCR_MAX_LINK_SPEEDS.
#define BM_PCIE_LCR_MAX_LINK_SPEEDS      (0x0000000f)  //!< Bit mask for PCIE_LCR_MAX_LINK_SPEEDS.

//! @brief Get value of PCIE_LCR_MAX_LINK_SPEEDS from a register value.
#define BG_PCIE_LCR_MAX_LINK_SPEEDS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_MAX_LINK_SPEEDS) >> BP_PCIE_LCR_MAX_LINK_SPEEDS)

/* --- Register HW_PCIE_LCR, field MAXIMUM_LINK_WIDTH[9:4] (RO)
 *
 * Maximum Link Width Writable through the DBI.
 */

#define BP_PCIE_LCR_MAXIMUM_LINK_WIDTH      (4)      //!< Bit position for PCIE_LCR_MAXIMUM_LINK_WIDTH.
#define BM_PCIE_LCR_MAXIMUM_LINK_WIDTH      (0x000003f0)  //!< Bit mask for PCIE_LCR_MAXIMUM_LINK_WIDTH.

//! @brief Get value of PCIE_LCR_MAXIMUM_LINK_WIDTH from a register value.
#define BG_PCIE_LCR_MAXIMUM_LINK_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_MAXIMUM_LINK_WIDTH) >> BP_PCIE_LCR_MAXIMUM_LINK_WIDTH)

/* --- Register HW_PCIE_LCR, field ACTIVE_STATE_LINK_PM_SUPPORT[11:10] (RO)
 *
 * Active State Link PM Support The default value is the value you specify during core
 * configuration, writable through the DBI.
 */

#define BP_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT      (10)      //!< Bit position for PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT.
#define BM_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT      (0x00000c00)  //!< Bit mask for PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT.

//! @brief Get value of PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT from a register value.
#define BG_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT) >> BP_PCIE_LCR_ACTIVE_STATE_LINK_PM_SUPPORT)

/* --- Register HW_PCIE_LCR, field L0S_EXIT_LATENCY[14:12] (RO)
 *
 * L0s Exit Latency Writable through the DBI.
 */

#define BP_PCIE_LCR_L0S_EXIT_LATENCY      (12)      //!< Bit position for PCIE_LCR_L0S_EXIT_LATENCY.
#define BM_PCIE_LCR_L0S_EXIT_LATENCY      (0x00007000)  //!< Bit mask for PCIE_LCR_L0S_EXIT_LATENCY.

//! @brief Get value of PCIE_LCR_L0S_EXIT_LATENCY from a register value.
#define BG_PCIE_LCR_L0S_EXIT_LATENCY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_L0S_EXIT_LATENCY) >> BP_PCIE_LCR_L0S_EXIT_LATENCY)

/* --- Register HW_PCIE_LCR, field L1_EXIT_LATENCY[17:15] (RO)
 *
 * L1 Exit Latency Writable through the DBI.
 */

#define BP_PCIE_LCR_L1_EXIT_LATENCY      (15)      //!< Bit position for PCIE_LCR_L1_EXIT_LATENCY.
#define BM_PCIE_LCR_L1_EXIT_LATENCY      (0x00038000)  //!< Bit mask for PCIE_LCR_L1_EXIT_LATENCY.

//! @brief Get value of PCIE_LCR_L1_EXIT_LATENCY from a register value.
#define BG_PCIE_LCR_L1_EXIT_LATENCY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_L1_EXIT_LATENCY) >> BP_PCIE_LCR_L1_EXIT_LATENCY)

/* --- Register HW_PCIE_LCR, field CLOCK_POWER_MANAGEMENT[18] (RO)
 *
 * Clock Power Management Component can tolerate the removal of refclk via CLKREQ# (if supported).
 * Hardwired to 0 for downstream ports. Writable through the DBI.
 */

#define BP_PCIE_LCR_CLOCK_POWER_MANAGEMENT      (18)      //!< Bit position for PCIE_LCR_CLOCK_POWER_MANAGEMENT.
#define BM_PCIE_LCR_CLOCK_POWER_MANAGEMENT      (0x00040000)  //!< Bit mask for PCIE_LCR_CLOCK_POWER_MANAGEMENT.

//! @brief Get value of PCIE_LCR_CLOCK_POWER_MANAGEMENT from a register value.
#define BG_PCIE_LCR_CLOCK_POWER_MANAGEMENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_CLOCK_POWER_MANAGEMENT) >> BP_PCIE_LCR_CLOCK_POWER_MANAGEMENT)

/* --- Register HW_PCIE_LCR, field SURPRISE_DOWN_ERROR_REPORTING_CAPABLE[19] (RO)
 *
 * Surprise Down Error Reporting Capable Not supported, hardwired to 0x0.
 */

#define BP_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE      (19)      //!< Bit position for PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE.
#define BM_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE      (0x00080000)  //!< Bit mask for PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE.

//! @brief Get value of PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE from a register value.
#define BG_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE) >> BP_PCIE_LCR_SURPRISE_DOWN_ERROR_REPORTING_CAPABLE)

/* --- Register HW_PCIE_LCR, field DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE[20] (RO)
 *
 * Data Link Layer Active Reporting Capable Hardwired to 1 for Downstream Ports and 0 for Upstream
 * Ports.
 */

#define BP_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE      (20)      //!< Bit position for PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE.
#define BM_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE      (0x00100000)  //!< Bit mask for PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE.

//! @brief Get value of PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE from a register value.
#define BG_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE) >> BP_PCIE_LCR_DATA_LINK_LAYER_ACTIVE_REPORTING_CAPABLE)

/* --- Register HW_PCIE_LCR, field LINK_BANDWIDTH_NOTIFICATION_CAPABILITY[21] (RO)
 *
 * Link Bandwidth Notification Capability Hardwired to 1 for Downstream Ports and 0 for Upstream
 * Ports.
 */

#define BP_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY      (21)      //!< Bit position for PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY.
#define BM_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY      (0x00200000)  //!< Bit mask for PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY.

//! @brief Get value of PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY from a register value.
#define BG_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY) >> BP_PCIE_LCR_LINK_BANDWIDTH_NOTIFICATION_CAPABILITY)

/* --- Register HW_PCIE_LCR, field PORT_NUMBER[31:24] (RO)
 *
 * Port Number
 */

#define BP_PCIE_LCR_PORT_NUMBER      (24)      //!< Bit position for PCIE_LCR_PORT_NUMBER.
#define BM_PCIE_LCR_PORT_NUMBER      (0xff000000)  //!< Bit mask for PCIE_LCR_PORT_NUMBER.

//! @brief Get value of PCIE_LCR_PORT_NUMBER from a register value.
#define BG_PCIE_LCR_PORT_NUMBER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR_PORT_NUMBER) >> BP_PCIE_LCR_PORT_NUMBER)

//-------------------------------------------------------------------------------------------
// HW_PCIE_LCSR - Link Control and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_LCSR - Link Control and Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x10
 */
typedef union _hw_pcie_lcsr
{
    reg32_t U;
    struct _hw_pcie_lcsr_bitfields
    {
        unsigned ACTIVE_STATE_LINK_PM_CONTROL : 2; //!< [1:0] Active State Link PM Control
        unsigned RESERVED0 : 1; //!< [2] Reserved
        unsigned RCB : 1; //!< [3] Read Completion Boundary (RCB) RC: Writable through DBI
        unsigned LINK_DISABLE : 1; //!< [4] Link Disable This bit is reserved for PCI Express-to-PCI/PCI-X bridges.
        unsigned RETRAIN_LINK : 1; //!< [5] Retrain Link This bit is reserved for PCI Express-to-PCI/PCI-X bridges.
        unsigned COMMON_CLOCK_CONFIGURATION : 1; //!< [6] Common Clock Configuration
        unsigned EXTENDED_SYNCH : 1; //!< [7] Extended Synch
        unsigned ENABLE_CLOCK_POWER_MANAGEMENT : 1; //!< [8] Enable Clock Power Management Hardwired to 0 if Clock Power Management is disabled in the Link Capabilities register.
        unsigned HARDWARE_AUTONOMOUS_WIDTH_DISABLE : 1; //!< [9] Hardware Autonomous Width Disable Not supported, hardwired to 0.
        unsigned LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE : 1; //!< [10] Link Bandwidth Management Interrupt Enable When set, this bit enables the generation of an interrupt to indicate that the Link Bandwidth Management Status bit has been set.
        unsigned LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE : 1; //!< [11] Link Autonomous Bandwidth Interrupt Enable When set, this bit enables the generation of an interrupt to indicate that the Link Autonomous Bandwidth Status bit has been set.
        unsigned RESERVED1 : 4; //!< [15:12] Reserved
        unsigned LINK_SPEED : 4; //!< [19:16] Link Speed Indicates the negotiated Link speed.
        unsigned NEGOTIATED_LINK_WIDTH : 6; //!< [25:20] Negotiated Link Width Set automatically by hardware after Link initialization.
        unsigned RESERVED2 : 1; //!< [26] Reserved Undefined for PCI Express 1.1 (Was Training Error for PCI Express 1.0a)
        unsigned LINK_TRAINING : 1; //!< [27] Link Training This bit is not applicable and is reserved for Endpoints, PCI Express to PCI/PCI-X bridges.
        unsigned SLOT_CLOCK_CONFIGURATION : 1; //!< [28] Slot Clock Configuration Indicates that the component uses the same physical reference clock that the platform provides on the connector.
        unsigned DATA_LINK_LAYER_ACTIVE : 1; //!< [29] Data Link Layer Active This bit must be implemented if the corresponding Data Link Layer Link Active Reporting capability bit is implemented.
        unsigned LINK_BANDWIDTH_MANAGEMENT_STATUS : 1; //!< [30] Link Bandwidth Management Status This bit is set by hardware to indicate that either of the following has occurred without the Port transitioning through DL_Down status: •A Link retraining has completed following a write of 1b to the Retrain Link bit.
        unsigned LINK_AUTONOMOUS_BANDWIDTH_STATUS : 1; //!< [31] Link Autonomous Bandwidth Status This bit is set by hardware to indicate that hardware has autonomously changed Link speed or width, without the Port transitioning through DL_Down status, for reasons other than to attempt to correct unreliable Link operation.
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

/* --- Register HW_PCIE_LCSR, field ACTIVE_STATE_LINK_PM_CONTROL[1:0] (RW)
 *
 * Active State Link PM Control
 */

#define BP_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL      (0)      //!< Bit position for PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL.
#define BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL      (0x00000003)  //!< Bit mask for PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL.

//! @brief Get value of PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL from a register value.
#define BG_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL) >> BP_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL)

//! @brief Format value for bitfield PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL.
#define BF_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL) & BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACTIVE_STATE_LINK_PM_CONTROL field to a new value.
#define BW_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL) | BF_PCIE_LCSR_ACTIVE_STATE_LINK_PM_CONTROL(v)))
#endif

/* --- Register HW_PCIE_LCSR, field RCB[3] (RW)
 *
 * Read Completion Boundary (RCB) RC: Writable through DBI
 */

#define BP_PCIE_LCSR_RCB      (3)      //!< Bit position for PCIE_LCSR_RCB.
#define BM_PCIE_LCSR_RCB      (0x00000008)  //!< Bit mask for PCIE_LCSR_RCB.

//! @brief Get value of PCIE_LCSR_RCB from a register value.
#define BG_PCIE_LCSR_RCB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_RCB) >> BP_PCIE_LCSR_RCB)

//! @brief Format value for bitfield PCIE_LCSR_RCB.
#define BF_PCIE_LCSR_RCB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_RCB) & BM_PCIE_LCSR_RCB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCB field to a new value.
#define BW_PCIE_LCSR_RCB(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_RCB) | BF_PCIE_LCSR_RCB(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_DISABLE[4] (RW)
 *
 * Link Disable This bit is reserved for PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_LINK_DISABLE      (4)      //!< Bit position for PCIE_LCSR_LINK_DISABLE.
#define BM_PCIE_LCSR_LINK_DISABLE      (0x00000010)  //!< Bit mask for PCIE_LCSR_LINK_DISABLE.

//! @brief Get value of PCIE_LCSR_LINK_DISABLE from a register value.
#define BG_PCIE_LCSR_LINK_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_DISABLE) >> BP_PCIE_LCSR_LINK_DISABLE)

//! @brief Format value for bitfield PCIE_LCSR_LINK_DISABLE.
#define BF_PCIE_LCSR_LINK_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_DISABLE) & BM_PCIE_LCSR_LINK_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_DISABLE field to a new value.
#define BW_PCIE_LCSR_LINK_DISABLE(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_DISABLE) | BF_PCIE_LCSR_LINK_DISABLE(v)))
#endif

/* --- Register HW_PCIE_LCSR, field RETRAIN_LINK[5] (RW)
 *
 * Retrain Link This bit is reserved for PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_RETRAIN_LINK      (5)      //!< Bit position for PCIE_LCSR_RETRAIN_LINK.
#define BM_PCIE_LCSR_RETRAIN_LINK      (0x00000020)  //!< Bit mask for PCIE_LCSR_RETRAIN_LINK.

//! @brief Get value of PCIE_LCSR_RETRAIN_LINK from a register value.
#define BG_PCIE_LCSR_RETRAIN_LINK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_RETRAIN_LINK) >> BP_PCIE_LCSR_RETRAIN_LINK)

//! @brief Format value for bitfield PCIE_LCSR_RETRAIN_LINK.
#define BF_PCIE_LCSR_RETRAIN_LINK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_RETRAIN_LINK) & BM_PCIE_LCSR_RETRAIN_LINK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RETRAIN_LINK field to a new value.
#define BW_PCIE_LCSR_RETRAIN_LINK(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_RETRAIN_LINK) | BF_PCIE_LCSR_RETRAIN_LINK(v)))
#endif

/* --- Register HW_PCIE_LCSR, field COMMON_CLOCK_CONFIGURATION[6] (RW)
 *
 * Common Clock Configuration
 */

#define BP_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION      (6)      //!< Bit position for PCIE_LCSR_COMMON_CLOCK_CONFIGURATION.
#define BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION      (0x00000040)  //!< Bit mask for PCIE_LCSR_COMMON_CLOCK_CONFIGURATION.

//! @brief Get value of PCIE_LCSR_COMMON_CLOCK_CONFIGURATION from a register value.
#define BG_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION) >> BP_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION)

//! @brief Format value for bitfield PCIE_LCSR_COMMON_CLOCK_CONFIGURATION.
#define BF_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION) & BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMMON_CLOCK_CONFIGURATION field to a new value.
#define BW_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION) | BF_PCIE_LCSR_COMMON_CLOCK_CONFIGURATION(v)))
#endif

/* --- Register HW_PCIE_LCSR, field EXTENDED_SYNCH[7] (RW)
 *
 * Extended Synch
 */

#define BP_PCIE_LCSR_EXTENDED_SYNCH      (7)      //!< Bit position for PCIE_LCSR_EXTENDED_SYNCH.
#define BM_PCIE_LCSR_EXTENDED_SYNCH      (0x00000080)  //!< Bit mask for PCIE_LCSR_EXTENDED_SYNCH.

//! @brief Get value of PCIE_LCSR_EXTENDED_SYNCH from a register value.
#define BG_PCIE_LCSR_EXTENDED_SYNCH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_EXTENDED_SYNCH) >> BP_PCIE_LCSR_EXTENDED_SYNCH)

//! @brief Format value for bitfield PCIE_LCSR_EXTENDED_SYNCH.
#define BF_PCIE_LCSR_EXTENDED_SYNCH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_EXTENDED_SYNCH) & BM_PCIE_LCSR_EXTENDED_SYNCH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTENDED_SYNCH field to a new value.
#define BW_PCIE_LCSR_EXTENDED_SYNCH(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_EXTENDED_SYNCH) | BF_PCIE_LCSR_EXTENDED_SYNCH(v)))
#endif

/* --- Register HW_PCIE_LCSR, field ENABLE_CLOCK_POWER_MANAGEMENT[8] (RW)
 *
 * Enable Clock Power Management Hardwired to 0 if Clock Power Management is disabled in the Link
 * Capabilities register.
 */

#define BP_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT      (8)      //!< Bit position for PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT.
#define BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT      (0x00000100)  //!< Bit mask for PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT.

//! @brief Get value of PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT from a register value.
#define BG_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT) >> BP_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT)

//! @brief Format value for bitfield PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT.
#define BF_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT) & BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_CLOCK_POWER_MANAGEMENT field to a new value.
#define BW_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT) | BF_PCIE_LCSR_ENABLE_CLOCK_POWER_MANAGEMENT(v)))
#endif

/* --- Register HW_PCIE_LCSR, field HARDWARE_AUTONOMOUS_WIDTH_DISABLE[9] (RW)
 *
 * Hardware Autonomous Width Disable Not supported, hardwired to 0.
 */

#define BP_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE      (9)      //!< Bit position for PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE.
#define BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE      (0x00000200)  //!< Bit mask for PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE.

//! @brief Get value of PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE from a register value.
#define BG_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE) >> BP_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE)

//! @brief Format value for bitfield PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE.
#define BF_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE) & BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HARDWARE_AUTONOMOUS_WIDTH_DISABLE field to a new value.
#define BW_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE) | BF_PCIE_LCSR_HARDWARE_AUTONOMOUS_WIDTH_DISABLE(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE[10] (RW)
 *
 * Link Bandwidth Management Interrupt Enable When set, this bit enables the generation of an
 * interrupt to indicate that the Link Bandwidth Management Status bit has been set. This bit is not
 * applicable and is reserved for Endpoints, PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE      (10)      //!< Bit position for PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE.
#define BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE      (0x00000400)  //!< Bit mask for PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE.

//! @brief Get value of PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE from a register value.
#define BG_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE) >> BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE)

//! @brief Format value for bitfield PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE.
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE field to a new value.
#define BW_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE) | BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_INTERRUPT_ENABLE(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE[11] (RW)
 *
 * Link Autonomous Bandwidth Interrupt Enable When set, this bit enables the generation of an
 * interrupt to indicate that the Link Autonomous Bandwidth Status bit has been set. This bit is not
 * applicable and is reserved for Endpoints, PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE      (11)      //!< Bit position for PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE.
#define BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE      (0x00000800)  //!< Bit mask for PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE.

//! @brief Get value of PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE from a register value.
#define BG_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE) >> BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE)

//! @brief Format value for bitfield PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE.
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE field to a new value.
#define BW_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE) | BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_INTERRUPT_ENABLE(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_SPEED[19:16] (RW)
 *
 * Link Speed Indicates the negotiated Link speed. The encoding is the binary value of the bit
 * location in the Supported Link Speeds Vector (in the Link Capabilities 2 register) that
 * corresponds to the current Link speed. Possible values are:
 *
 * Values:
 * 0001 - Gen1 2.5 GT/s
 * 0010 - Gen2 5.0 GT/s
 * 0100 - Gen3 8.0 GT/s
 */

#define BP_PCIE_LCSR_LINK_SPEED      (16)      //!< Bit position for PCIE_LCSR_LINK_SPEED.
#define BM_PCIE_LCSR_LINK_SPEED      (0x000f0000)  //!< Bit mask for PCIE_LCSR_LINK_SPEED.

//! @brief Get value of PCIE_LCSR_LINK_SPEED from a register value.
#define BG_PCIE_LCSR_LINK_SPEED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_SPEED) >> BP_PCIE_LCSR_LINK_SPEED)

//! @brief Format value for bitfield PCIE_LCSR_LINK_SPEED.
#define BF_PCIE_LCSR_LINK_SPEED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_SPEED) & BM_PCIE_LCSR_LINK_SPEED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_SPEED field to a new value.
#define BW_PCIE_LCSR_LINK_SPEED(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_SPEED) | BF_PCIE_LCSR_LINK_SPEED(v)))
#endif


/* --- Register HW_PCIE_LCSR, field NEGOTIATED_LINK_WIDTH[25:20] (RW)
 *
 * Negotiated Link Width Set automatically by hardware after Link initialization. The value is
 * undefined when link is not up.
 */

#define BP_PCIE_LCSR_NEGOTIATED_LINK_WIDTH      (20)      //!< Bit position for PCIE_LCSR_NEGOTIATED_LINK_WIDTH.
#define BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH      (0x03f00000)  //!< Bit mask for PCIE_LCSR_NEGOTIATED_LINK_WIDTH.

//! @brief Get value of PCIE_LCSR_NEGOTIATED_LINK_WIDTH from a register value.
#define BG_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH) >> BP_PCIE_LCSR_NEGOTIATED_LINK_WIDTH)

//! @brief Format value for bitfield PCIE_LCSR_NEGOTIATED_LINK_WIDTH.
#define BF_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_NEGOTIATED_LINK_WIDTH) & BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NEGOTIATED_LINK_WIDTH field to a new value.
#define BW_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_NEGOTIATED_LINK_WIDTH) | BF_PCIE_LCSR_NEGOTIATED_LINK_WIDTH(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_TRAINING[27] (RW)
 *
 * Link Training This bit is not applicable and is reserved for Endpoints, PCI Express to PCI/PCI-X
 * bridges.
 */

#define BP_PCIE_LCSR_LINK_TRAINING      (27)      //!< Bit position for PCIE_LCSR_LINK_TRAINING.
#define BM_PCIE_LCSR_LINK_TRAINING      (0x08000000)  //!< Bit mask for PCIE_LCSR_LINK_TRAINING.

//! @brief Get value of PCIE_LCSR_LINK_TRAINING from a register value.
#define BG_PCIE_LCSR_LINK_TRAINING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_TRAINING) >> BP_PCIE_LCSR_LINK_TRAINING)

//! @brief Format value for bitfield PCIE_LCSR_LINK_TRAINING.
#define BF_PCIE_LCSR_LINK_TRAINING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_TRAINING) & BM_PCIE_LCSR_LINK_TRAINING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_TRAINING field to a new value.
#define BW_PCIE_LCSR_LINK_TRAINING(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_TRAINING) | BF_PCIE_LCSR_LINK_TRAINING(v)))
#endif

/* --- Register HW_PCIE_LCSR, field SLOT_CLOCK_CONFIGURATION[28] (RW)
 *
 * Slot Clock Configuration Indicates that the component uses the same physical reference clock that
 * the platform provides on the connector. The default value is the value you select during hardware
 * configuration, writable through the DBI.
 */

#define BP_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION      (28)      //!< Bit position for PCIE_LCSR_SLOT_CLOCK_CONFIGURATION.
#define BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION      (0x10000000)  //!< Bit mask for PCIE_LCSR_SLOT_CLOCK_CONFIGURATION.

//! @brief Get value of PCIE_LCSR_SLOT_CLOCK_CONFIGURATION from a register value.
#define BG_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION) >> BP_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION)

//! @brief Format value for bitfield PCIE_LCSR_SLOT_CLOCK_CONFIGURATION.
#define BF_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION) & BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLOT_CLOCK_CONFIGURATION field to a new value.
#define BW_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION) | BF_PCIE_LCSR_SLOT_CLOCK_CONFIGURATION(v)))
#endif

/* --- Register HW_PCIE_LCSR, field DATA_LINK_LAYER_ACTIVE[29] (RW)
 *
 * Data Link Layer Active This bit must be implemented if the corresponding Data Link Layer Link
 * Active Reporting capability bit is implemented. Otherwise, this bit must be hardwired to 0b.
 */

#define BP_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE      (29)      //!< Bit position for PCIE_LCSR_DATA_LINK_LAYER_ACTIVE.
#define BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE      (0x20000000)  //!< Bit mask for PCIE_LCSR_DATA_LINK_LAYER_ACTIVE.

//! @brief Get value of PCIE_LCSR_DATA_LINK_LAYER_ACTIVE from a register value.
#define BG_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE) >> BP_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE)

//! @brief Format value for bitfield PCIE_LCSR_DATA_LINK_LAYER_ACTIVE.
#define BF_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE) & BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_LAYER_ACTIVE field to a new value.
#define BW_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE) | BF_PCIE_LCSR_DATA_LINK_LAYER_ACTIVE(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_BANDWIDTH_MANAGEMENT_STATUS[30] (RW)
 *
 * Link Bandwidth Management Status This bit is set by hardware to indicate that either of the
 * following has occurred without the Port transitioning through DL_Down status: •A Link retraining
 * has completed following a write of 1b to the Retrain Link bit. •Hardware has changed Link speed
 * or width to attempt to correct unreliable Link operation, either through an LTSSM timeout or a
 * higher level process. This bit must be set if the Physical Layer reports a speed or width change
 * was initiated by the Downstream component that was not indicated as an autonomous change. : This
 * bit is set following any write of 1b to the Retrain Link bit, including when the Link is in the
 * process of retraining for some other reason. This bit is not applicable and is reserved for
 * Endpoints, PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS      (30)      //!< Bit position for PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS.
#define BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS      (0x40000000)  //!< Bit mask for PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS.

//! @brief Get value of PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS from a register value.
#define BG_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS) >> BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS)

//! @brief Format value for bitfield PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS.
#define BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS) & BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_BANDWIDTH_MANAGEMENT_STATUS field to a new value.
#define BW_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS) | BF_PCIE_LCSR_LINK_BANDWIDTH_MANAGEMENT_STATUS(v)))
#endif

/* --- Register HW_PCIE_LCSR, field LINK_AUTONOMOUS_BANDWIDTH_STATUS[31] (RW)
 *
 * Link Autonomous Bandwidth Status This bit is set by hardware to indicate that hardware has
 * autonomously changed Link speed or width, without the Port transitioning through DL_Down status,
 * for reasons other than to attempt to correct unreliable Link operation. This bit must be set if
 * the Physical Layer reports a speed or a width change was initiated by the Downstream component
 * that was indicated as an autonomous change. This bit is not applicable and is reserved for
 * Endpoints, PCI Express-to-PCI/PCI-X bridges.
 */

#define BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS      (31)      //!< Bit position for PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS.
#define BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS      (0x80000000)  //!< Bit mask for PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS.

//! @brief Get value of PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS from a register value.
#define BG_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS) >> BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS)

//! @brief Format value for bitfield PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS.
#define BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS) & BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_AUTONOMOUS_BANDWIDTH_STATUS field to a new value.
#define BW_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)   (HW_PCIE_LCSR_WR((HW_PCIE_LCSR_RD() & ~BM_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS) | BF_PCIE_LCSR_LINK_AUTONOMOUS_BANDWIDTH_STATUS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_SCR - Slot Capabilities Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_SCR - Slot Capabilities Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This section applies only to Downstream Ports (for example, RC.  Offset: `CFG_PCIE_CAP + 0x14
 */
typedef union _hw_pcie_scr
{
    reg32_t U;
    struct _hw_pcie_scr_bitfields
    {
        unsigned ATTENTION_INDICATOR_PRESENT : 1; //!< [0] Attention Indicator Present, writable through the DBI
        unsigned POWER_CONTROLLER_PRESENT : 1; //!< [1] Power Controller Present, writable through the DBI
        unsigned MRL_SENSOR_PRESENT : 1; //!< [2] MRL Sensor Present, writable through the DBI
        unsigned ATTENTION_INDICATOR_PRESENT1 : 1; //!< [3] Attention Indicator Present, writable through the DBI
        unsigned POWER_INDICATOR_PRESENT : 1; //!< [4] Power Indicator Present, writable through the DBI
        unsigned HOT_PLUG_SURPRISE : 1; //!< [5] Hot-Plug Surprise, writable through the DBI
        unsigned HOT_PLUG_CAPABLE : 1; //!< [6] Hot-Plug Capable, writable through the DBI
        unsigned SLOT_POWER_LIMIT_VALUE : 8; //!< [14:7] Slot Power Limit Value, writable through the DBI
        unsigned SLOT_POWER_LIMIT_SCALE : 2; //!< [16:15] Slot Power Limit Scale, writable through the DBI
        unsigned ELECTROMECHANICAL_INTERLOCK_PRESENT : 1; //!< [17] Electromechanical Interlock Present, writable through the DBI
        unsigned NO_COMMAND_COMPLETE_SUPPORT : 1; //!< [18] No Command Complete Support, writable through the DBI
        unsigned PHYSICAL_SLOT_NUMBER : 13; //!< [31:19] Physical Slot Number, writable through the DBI
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
#endif

/*
 * constants & macros for individual PCIE_SCR bitfields
 */

/* --- Register HW_PCIE_SCR, field ATTENTION_INDICATOR_PRESENT[0] (RO)
 *
 * Attention Indicator Present, writable through the DBI
 */

#define BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      (0)      //!< Bit position for PCIE_SCR_ATTENTION_INDICATOR_PRESENT.
#define BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT      (0x00000001)  //!< Bit mask for PCIE_SCR_ATTENTION_INDICATOR_PRESENT.

//! @brief Get value of PCIE_SCR_ATTENTION_INDICATOR_PRESENT from a register value.
#define BG_PCIE_SCR_ATTENTION_INDICATOR_PRESENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT) >> BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT)

/* --- Register HW_PCIE_SCR, field POWER_CONTROLLER_PRESENT[1] (RO)
 *
 * Power Controller Present, writable through the DBI
 */

#define BP_PCIE_SCR_POWER_CONTROLLER_PRESENT      (1)      //!< Bit position for PCIE_SCR_POWER_CONTROLLER_PRESENT.
#define BM_PCIE_SCR_POWER_CONTROLLER_PRESENT      (0x00000002)  //!< Bit mask for PCIE_SCR_POWER_CONTROLLER_PRESENT.

//! @brief Get value of PCIE_SCR_POWER_CONTROLLER_PRESENT from a register value.
#define BG_PCIE_SCR_POWER_CONTROLLER_PRESENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_POWER_CONTROLLER_PRESENT) >> BP_PCIE_SCR_POWER_CONTROLLER_PRESENT)

/* --- Register HW_PCIE_SCR, field MRL_SENSOR_PRESENT[2] (RO)
 *
 * MRL Sensor Present, writable through the DBI
 */

#define BP_PCIE_SCR_MRL_SENSOR_PRESENT      (2)      //!< Bit position for PCIE_SCR_MRL_SENSOR_PRESENT.
#define BM_PCIE_SCR_MRL_SENSOR_PRESENT      (0x00000004)  //!< Bit mask for PCIE_SCR_MRL_SENSOR_PRESENT.

//! @brief Get value of PCIE_SCR_MRL_SENSOR_PRESENT from a register value.
#define BG_PCIE_SCR_MRL_SENSOR_PRESENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_MRL_SENSOR_PRESENT) >> BP_PCIE_SCR_MRL_SENSOR_PRESENT)

/* --- Register HW_PCIE_SCR, field ATTENTION_INDICATOR_PRESENT1[3] (RO)
 *
 * Attention Indicator Present, writable through the DBI
 */

#define BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT1      (3)      //!< Bit position for PCIE_SCR_ATTENTION_INDICATOR_PRESENT1.
#define BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT1      (0x00000008)  //!< Bit mask for PCIE_SCR_ATTENTION_INDICATOR_PRESENT1.

//! @brief Get value of PCIE_SCR_ATTENTION_INDICATOR_PRESENT1 from a register value.
#define BG_PCIE_SCR_ATTENTION_INDICATOR_PRESENT1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_ATTENTION_INDICATOR_PRESENT1) >> BP_PCIE_SCR_ATTENTION_INDICATOR_PRESENT1)

/* --- Register HW_PCIE_SCR, field POWER_INDICATOR_PRESENT[4] (RO)
 *
 * Power Indicator Present, writable through the DBI
 */

#define BP_PCIE_SCR_POWER_INDICATOR_PRESENT      (4)      //!< Bit position for PCIE_SCR_POWER_INDICATOR_PRESENT.
#define BM_PCIE_SCR_POWER_INDICATOR_PRESENT      (0x00000010)  //!< Bit mask for PCIE_SCR_POWER_INDICATOR_PRESENT.

//! @brief Get value of PCIE_SCR_POWER_INDICATOR_PRESENT from a register value.
#define BG_PCIE_SCR_POWER_INDICATOR_PRESENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_POWER_INDICATOR_PRESENT) >> BP_PCIE_SCR_POWER_INDICATOR_PRESENT)

/* --- Register HW_PCIE_SCR, field HOT_PLUG_SURPRISE[5] (RO)
 *
 * Hot-Plug Surprise, writable through the DBI
 */

#define BP_PCIE_SCR_HOT_PLUG_SURPRISE      (5)      //!< Bit position for PCIE_SCR_HOT_PLUG_SURPRISE.
#define BM_PCIE_SCR_HOT_PLUG_SURPRISE      (0x00000020)  //!< Bit mask for PCIE_SCR_HOT_PLUG_SURPRISE.

//! @brief Get value of PCIE_SCR_HOT_PLUG_SURPRISE from a register value.
#define BG_PCIE_SCR_HOT_PLUG_SURPRISE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_HOT_PLUG_SURPRISE) >> BP_PCIE_SCR_HOT_PLUG_SURPRISE)

/* --- Register HW_PCIE_SCR, field HOT_PLUG_CAPABLE[6] (RO)
 *
 * Hot-Plug Capable, writable through the DBI
 */

#define BP_PCIE_SCR_HOT_PLUG_CAPABLE      (6)      //!< Bit position for PCIE_SCR_HOT_PLUG_CAPABLE.
#define BM_PCIE_SCR_HOT_PLUG_CAPABLE      (0x00000040)  //!< Bit mask for PCIE_SCR_HOT_PLUG_CAPABLE.

//! @brief Get value of PCIE_SCR_HOT_PLUG_CAPABLE from a register value.
#define BG_PCIE_SCR_HOT_PLUG_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_HOT_PLUG_CAPABLE) >> BP_PCIE_SCR_HOT_PLUG_CAPABLE)

/* --- Register HW_PCIE_SCR, field SLOT_POWER_LIMIT_VALUE[14:7] (RO)
 *
 * Slot Power Limit Value, writable through the DBI
 */

#define BP_PCIE_SCR_SLOT_POWER_LIMIT_VALUE      (7)      //!< Bit position for PCIE_SCR_SLOT_POWER_LIMIT_VALUE.
#define BM_PCIE_SCR_SLOT_POWER_LIMIT_VALUE      (0x00007f80)  //!< Bit mask for PCIE_SCR_SLOT_POWER_LIMIT_VALUE.

//! @brief Get value of PCIE_SCR_SLOT_POWER_LIMIT_VALUE from a register value.
#define BG_PCIE_SCR_SLOT_POWER_LIMIT_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_SLOT_POWER_LIMIT_VALUE) >> BP_PCIE_SCR_SLOT_POWER_LIMIT_VALUE)

/* --- Register HW_PCIE_SCR, field SLOT_POWER_LIMIT_SCALE[16:15] (RO)
 *
 * Slot Power Limit Scale, writable through the DBI
 */

#define BP_PCIE_SCR_SLOT_POWER_LIMIT_SCALE      (15)      //!< Bit position for PCIE_SCR_SLOT_POWER_LIMIT_SCALE.
#define BM_PCIE_SCR_SLOT_POWER_LIMIT_SCALE      (0x00018000)  //!< Bit mask for PCIE_SCR_SLOT_POWER_LIMIT_SCALE.

//! @brief Get value of PCIE_SCR_SLOT_POWER_LIMIT_SCALE from a register value.
#define BG_PCIE_SCR_SLOT_POWER_LIMIT_SCALE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_SLOT_POWER_LIMIT_SCALE) >> BP_PCIE_SCR_SLOT_POWER_LIMIT_SCALE)

/* --- Register HW_PCIE_SCR, field ELECTROMECHANICAL_INTERLOCK_PRESENT[17] (RO)
 *
 * Electromechanical Interlock Present, writable through the DBI
 */

#define BP_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT      (17)      //!< Bit position for PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT.
#define BM_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT      (0x00020000)  //!< Bit mask for PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT.

//! @brief Get value of PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT from a register value.
#define BG_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT) >> BP_PCIE_SCR_ELECTROMECHANICAL_INTERLOCK_PRESENT)

/* --- Register HW_PCIE_SCR, field NO_COMMAND_COMPLETE_SUPPORT[18] (RO)
 *
 * No Command Complete Support, writable through the DBI
 */

#define BP_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT      (18)      //!< Bit position for PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT.
#define BM_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT      (0x00040000)  //!< Bit mask for PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT.

//! @brief Get value of PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT from a register value.
#define BG_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT) >> BP_PCIE_SCR_NO_COMMAND_COMPLETE_SUPPORT)

/* --- Register HW_PCIE_SCR, field PHYSICAL_SLOT_NUMBER[31:19] (RO)
 *
 * Physical Slot Number, writable through the DBI
 */

#define BP_PCIE_SCR_PHYSICAL_SLOT_NUMBER      (19)      //!< Bit position for PCIE_SCR_PHYSICAL_SLOT_NUMBER.
#define BM_PCIE_SCR_PHYSICAL_SLOT_NUMBER      (0xfff80000)  //!< Bit mask for PCIE_SCR_PHYSICAL_SLOT_NUMBER.

//! @brief Get value of PCIE_SCR_PHYSICAL_SLOT_NUMBER from a register value.
#define BG_PCIE_SCR_PHYSICAL_SLOT_NUMBER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCR_PHYSICAL_SLOT_NUMBER) >> BP_PCIE_SCR_PHYSICAL_SLOT_NUMBER)

//-------------------------------------------------------------------------------------------
// HW_PCIE_SCSR - Slot Control and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_SCSR - Slot Control and Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This section applies only to Downstream Ports (for example, RC.  Offset: `CFG_PCIE_CAP + 0x18
 */
typedef union _hw_pcie_scsr
{
    reg32_t U;
    struct _hw_pcie_scsr_bitfields
    {
        unsigned ATTENTION_BUTTON_PRESSED_ENABLE : 1; //!< [0] Attention Button Pressed Enable
        unsigned POWER_FAULT_DETECTED_ENABLE : 1; //!< [1] Power Fault Detected Enable
        unsigned MRL_SENSOR_CHANGED_ENABLE : 1; //!< [2] MRL Sensor Changed Enable
        unsigned PRESENCE_DETECT_CHANGED_ENABLE : 1; //!< [3] Presence Detect Changed Enable
        unsigned COMMAND_COMPLETED_INTERRUPT_ENABLE : 1; //!< [4] Command Completed Interrupt Enable
        unsigned HOT_PLUG_INTERRUPT_ENABLE : 1; //!< [5] Hot-Plug Interrupt Enable
        unsigned ATTENTION_INDICATOR_CONTROL : 2; //!< [7:6] Attention Indicator Control
        unsigned POWER_INDICATOR_CONTROL : 2; //!< [9:8] Power Indicator Control
        unsigned POWER_CONTROLLER_CONTROL : 1; //!< [10] Power Controller Control
        unsigned ELECTROMECHANICAL_INTERLOCK_CONTROL : 1; //!< [11] Electromechanical Interlock Control
        unsigned DATA_LINK_LAYER_STATE_CHANGED_ENABLE : 1; //!< [12] Data Link Layer State Changed Enable
        unsigned RESERVED0 : 3; //!< [15:13] Reserved
        unsigned ATTENTION_BUTTON_PRESSED : 1; //!< [16] Attention Button Pressed
        unsigned POWER_FAULT_DETECTED : 1; //!< [17] Power Fault Detected
        unsigned MRL_SENSOR_CHANGED : 1; //!< [18] MRL Sensor Changed
        unsigned PRESENCE_DETECT_CHANGED : 1; //!< [19] Presence Detect Changed
        unsigned COMMAND_COMPLETED : 1; //!< [20] Command Completed
        unsigned MRL_SENSOR_STATE : 1; //!< [21] MRL Sensor State
        unsigned PRESENCE_DETECT_STATE : 1; //!< [22] Presence Detect State
        unsigned ELECTROMECHANICAL_INTERLOCK_STATUS : 1; //!< [23] Electromechanical Interlock Status
        unsigned DATA_LINK_LAYER_STATE_CHANGED : 1; //!< [24] Data Link Layer State Changed
        unsigned RESERVED1 : 7; //!< [31:25] Reserved
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

/* --- Register HW_PCIE_SCSR, field ATTENTION_BUTTON_PRESSED_ENABLE[0] (RW)
 *
 * Attention Button Pressed Enable
 */

#define BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE      (0)      //!< Bit position for PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE.
#define BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE      (0x00000001)  //!< Bit mask for PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE.

//! @brief Get value of PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE from a register value.
#define BG_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE) >> BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE.
#define BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATTENTION_BUTTON_PRESSED_ENABLE field to a new value.
#define BW_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE) | BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field POWER_FAULT_DETECTED_ENABLE[1] (RW)
 *
 * Power Fault Detected Enable
 */

#define BP_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE      (1)      //!< Bit position for PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE.
#define BM_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE      (0x00000002)  //!< Bit mask for PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE.

//! @brief Get value of PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE from a register value.
#define BG_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE) >> BP_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE.
#define BF_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE) & BM_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_FAULT_DETECTED_ENABLE field to a new value.
#define BW_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE) | BF_PCIE_SCSR_POWER_FAULT_DETECTED_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_CHANGED_ENABLE[2] (RW)
 *
 * MRL Sensor Changed Enable
 */

#define BP_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE      (2)      //!< Bit position for PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE.
#define BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE      (0x00000004)  //!< Bit mask for PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE.

//! @brief Get value of PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE from a register value.
#define BG_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE) >> BP_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE.
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MRL_SENSOR_CHANGED_ENABLE field to a new value.
#define BW_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE) | BF_PCIE_SCSR_MRL_SENSOR_CHANGED_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_CHANGED_ENABLE[3] (RW)
 *
 * Presence Detect Changed Enable
 */

#define BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE      (3)      //!< Bit position for PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE.
#define BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE      (0x00000008)  //!< Bit mask for PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE.

//! @brief Get value of PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE from a register value.
#define BG_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE) >> BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE.
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESENCE_DETECT_CHANGED_ENABLE field to a new value.
#define BW_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE) | BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field COMMAND_COMPLETED_INTERRUPT_ENABLE[4] (RW)
 *
 * Command Completed Interrupt Enable
 */

#define BP_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE      (4)      //!< Bit position for PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE.
#define BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE      (0x00000010)  //!< Bit mask for PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE.

//! @brief Get value of PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE from a register value.
#define BG_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE) >> BP_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE.
#define BF_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE) & BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMMAND_COMPLETED_INTERRUPT_ENABLE field to a new value.
#define BW_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE) | BF_PCIE_SCSR_COMMAND_COMPLETED_INTERRUPT_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field HOT_PLUG_INTERRUPT_ENABLE[5] (RW)
 *
 * Hot-Plug Interrupt Enable
 */

#define BP_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE      (5)      //!< Bit position for PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE.
#define BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE      (0x00000020)  //!< Bit mask for PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE.

//! @brief Get value of PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE from a register value.
#define BG_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE) >> BP_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE.
#define BF_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE) & BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOT_PLUG_INTERRUPT_ENABLE field to a new value.
#define BW_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE) | BF_PCIE_SCSR_HOT_PLUG_INTERRUPT_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field ATTENTION_INDICATOR_CONTROL[7:6] (RW)
 *
 * Attention Indicator Control
 */

#define BP_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL      (6)      //!< Bit position for PCIE_SCSR_ATTENTION_INDICATOR_CONTROL.
#define BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL      (0x000000c0)  //!< Bit mask for PCIE_SCSR_ATTENTION_INDICATOR_CONTROL.

//! @brief Get value of PCIE_SCSR_ATTENTION_INDICATOR_CONTROL from a register value.
#define BG_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL) >> BP_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL)

//! @brief Format value for bitfield PCIE_SCSR_ATTENTION_INDICATOR_CONTROL.
#define BF_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL) & BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATTENTION_INDICATOR_CONTROL field to a new value.
#define BW_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL) | BF_PCIE_SCSR_ATTENTION_INDICATOR_CONTROL(v)))
#endif

/* --- Register HW_PCIE_SCSR, field POWER_INDICATOR_CONTROL[9:8] (RW)
 *
 * Power Indicator Control
 */

#define BP_PCIE_SCSR_POWER_INDICATOR_CONTROL      (8)      //!< Bit position for PCIE_SCSR_POWER_INDICATOR_CONTROL.
#define BM_PCIE_SCSR_POWER_INDICATOR_CONTROL      (0x00000300)  //!< Bit mask for PCIE_SCSR_POWER_INDICATOR_CONTROL.

//! @brief Get value of PCIE_SCSR_POWER_INDICATOR_CONTROL from a register value.
#define BG_PCIE_SCSR_POWER_INDICATOR_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_POWER_INDICATOR_CONTROL) >> BP_PCIE_SCSR_POWER_INDICATOR_CONTROL)

//! @brief Format value for bitfield PCIE_SCSR_POWER_INDICATOR_CONTROL.
#define BF_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_POWER_INDICATOR_CONTROL) & BM_PCIE_SCSR_POWER_INDICATOR_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_INDICATOR_CONTROL field to a new value.
#define BW_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_POWER_INDICATOR_CONTROL) | BF_PCIE_SCSR_POWER_INDICATOR_CONTROL(v)))
#endif

/* --- Register HW_PCIE_SCSR, field POWER_CONTROLLER_CONTROL[10] (RW)
 *
 * Power Controller Control
 */

#define BP_PCIE_SCSR_POWER_CONTROLLER_CONTROL      (10)      //!< Bit position for PCIE_SCSR_POWER_CONTROLLER_CONTROL.
#define BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL      (0x00000400)  //!< Bit mask for PCIE_SCSR_POWER_CONTROLLER_CONTROL.

//! @brief Get value of PCIE_SCSR_POWER_CONTROLLER_CONTROL from a register value.
#define BG_PCIE_SCSR_POWER_CONTROLLER_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL) >> BP_PCIE_SCSR_POWER_CONTROLLER_CONTROL)

//! @brief Format value for bitfield PCIE_SCSR_POWER_CONTROLLER_CONTROL.
#define BF_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_POWER_CONTROLLER_CONTROL) & BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_CONTROLLER_CONTROL field to a new value.
#define BW_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_POWER_CONTROLLER_CONTROL) | BF_PCIE_SCSR_POWER_CONTROLLER_CONTROL(v)))
#endif

/* --- Register HW_PCIE_SCSR, field ELECTROMECHANICAL_INTERLOCK_CONTROL[11] (RW)
 *
 * Electromechanical Interlock Control
 */

#define BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL      (11)      //!< Bit position for PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL.
#define BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL      (0x00000800)  //!< Bit mask for PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL.

//! @brief Get value of PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL from a register value.
#define BG_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL) >> BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL)

//! @brief Format value for bitfield PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL.
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ELECTROMECHANICAL_INTERLOCK_CONTROL field to a new value.
#define BW_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL) | BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_CONTROL(v)))
#endif

/* --- Register HW_PCIE_SCSR, field DATA_LINK_LAYER_STATE_CHANGED_ENABLE[12] (RW)
 *
 * Data Link Layer State Changed Enable
 */

#define BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE      (12)      //!< Bit position for PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE.
#define BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE      (0x00001000)  //!< Bit mask for PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE.

//! @brief Get value of PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE from a register value.
#define BG_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE) >> BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE)

//! @brief Format value for bitfield PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE.
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_LAYER_STATE_CHANGED_ENABLE field to a new value.
#define BW_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE) | BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED_ENABLE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field ATTENTION_BUTTON_PRESSED[16] (RW)
 *
 * Attention Button Pressed
 */

#define BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED      (16)      //!< Bit position for PCIE_SCSR_ATTENTION_BUTTON_PRESSED.
#define BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED      (0x00010000)  //!< Bit mask for PCIE_SCSR_ATTENTION_BUTTON_PRESSED.

//! @brief Get value of PCIE_SCSR_ATTENTION_BUTTON_PRESSED from a register value.
#define BG_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED) >> BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED)

//! @brief Format value for bitfield PCIE_SCSR_ATTENTION_BUTTON_PRESSED.
#define BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_ATTENTION_BUTTON_PRESSED) & BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATTENTION_BUTTON_PRESSED field to a new value.
#define BW_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_ATTENTION_BUTTON_PRESSED) | BF_PCIE_SCSR_ATTENTION_BUTTON_PRESSED(v)))
#endif

/* --- Register HW_PCIE_SCSR, field POWER_FAULT_DETECTED[17] (RW)
 *
 * Power Fault Detected
 */

#define BP_PCIE_SCSR_POWER_FAULT_DETECTED      (17)      //!< Bit position for PCIE_SCSR_POWER_FAULT_DETECTED.
#define BM_PCIE_SCSR_POWER_FAULT_DETECTED      (0x00020000)  //!< Bit mask for PCIE_SCSR_POWER_FAULT_DETECTED.

//! @brief Get value of PCIE_SCSR_POWER_FAULT_DETECTED from a register value.
#define BG_PCIE_SCSR_POWER_FAULT_DETECTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_POWER_FAULT_DETECTED) >> BP_PCIE_SCSR_POWER_FAULT_DETECTED)

//! @brief Format value for bitfield PCIE_SCSR_POWER_FAULT_DETECTED.
#define BF_PCIE_SCSR_POWER_FAULT_DETECTED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_POWER_FAULT_DETECTED) & BM_PCIE_SCSR_POWER_FAULT_DETECTED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_FAULT_DETECTED field to a new value.
#define BW_PCIE_SCSR_POWER_FAULT_DETECTED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_POWER_FAULT_DETECTED) | BF_PCIE_SCSR_POWER_FAULT_DETECTED(v)))
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_CHANGED[18] (RW)
 *
 * MRL Sensor Changed
 */

#define BP_PCIE_SCSR_MRL_SENSOR_CHANGED      (18)      //!< Bit position for PCIE_SCSR_MRL_SENSOR_CHANGED.
#define BM_PCIE_SCSR_MRL_SENSOR_CHANGED      (0x00040000)  //!< Bit mask for PCIE_SCSR_MRL_SENSOR_CHANGED.

//! @brief Get value of PCIE_SCSR_MRL_SENSOR_CHANGED from a register value.
#define BG_PCIE_SCSR_MRL_SENSOR_CHANGED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED) >> BP_PCIE_SCSR_MRL_SENSOR_CHANGED)

//! @brief Format value for bitfield PCIE_SCSR_MRL_SENSOR_CHANGED.
#define BF_PCIE_SCSR_MRL_SENSOR_CHANGED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_MRL_SENSOR_CHANGED) & BM_PCIE_SCSR_MRL_SENSOR_CHANGED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MRL_SENSOR_CHANGED field to a new value.
#define BW_PCIE_SCSR_MRL_SENSOR_CHANGED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_MRL_SENSOR_CHANGED) | BF_PCIE_SCSR_MRL_SENSOR_CHANGED(v)))
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_CHANGED[19] (RW)
 *
 * Presence Detect Changed
 */

#define BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED      (19)      //!< Bit position for PCIE_SCSR_PRESENCE_DETECT_CHANGED.
#define BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED      (0x00080000)  //!< Bit mask for PCIE_SCSR_PRESENCE_DETECT_CHANGED.

//! @brief Get value of PCIE_SCSR_PRESENCE_DETECT_CHANGED from a register value.
#define BG_PCIE_SCSR_PRESENCE_DETECT_CHANGED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED) >> BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED)

//! @brief Format value for bitfield PCIE_SCSR_PRESENCE_DETECT_CHANGED.
#define BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_PRESENCE_DETECT_CHANGED) & BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESENCE_DETECT_CHANGED field to a new value.
#define BW_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_PRESENCE_DETECT_CHANGED) | BF_PCIE_SCSR_PRESENCE_DETECT_CHANGED(v)))
#endif

/* --- Register HW_PCIE_SCSR, field COMMAND_COMPLETED[20] (RW)
 *
 * Command Completed
 */

#define BP_PCIE_SCSR_COMMAND_COMPLETED      (20)      //!< Bit position for PCIE_SCSR_COMMAND_COMPLETED.
#define BM_PCIE_SCSR_COMMAND_COMPLETED      (0x00100000)  //!< Bit mask for PCIE_SCSR_COMMAND_COMPLETED.

//! @brief Get value of PCIE_SCSR_COMMAND_COMPLETED from a register value.
#define BG_PCIE_SCSR_COMMAND_COMPLETED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_COMMAND_COMPLETED) >> BP_PCIE_SCSR_COMMAND_COMPLETED)

//! @brief Format value for bitfield PCIE_SCSR_COMMAND_COMPLETED.
#define BF_PCIE_SCSR_COMMAND_COMPLETED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_COMMAND_COMPLETED) & BM_PCIE_SCSR_COMMAND_COMPLETED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMMAND_COMPLETED field to a new value.
#define BW_PCIE_SCSR_COMMAND_COMPLETED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_COMMAND_COMPLETED) | BF_PCIE_SCSR_COMMAND_COMPLETED(v)))
#endif

/* --- Register HW_PCIE_SCSR, field MRL_SENSOR_STATE[21] (RW)
 *
 * MRL Sensor State
 */

#define BP_PCIE_SCSR_MRL_SENSOR_STATE      (21)      //!< Bit position for PCIE_SCSR_MRL_SENSOR_STATE.
#define BM_PCIE_SCSR_MRL_SENSOR_STATE      (0x00200000)  //!< Bit mask for PCIE_SCSR_MRL_SENSOR_STATE.

//! @brief Get value of PCIE_SCSR_MRL_SENSOR_STATE from a register value.
#define BG_PCIE_SCSR_MRL_SENSOR_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_MRL_SENSOR_STATE) >> BP_PCIE_SCSR_MRL_SENSOR_STATE)

//! @brief Format value for bitfield PCIE_SCSR_MRL_SENSOR_STATE.
#define BF_PCIE_SCSR_MRL_SENSOR_STATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_MRL_SENSOR_STATE) & BM_PCIE_SCSR_MRL_SENSOR_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MRL_SENSOR_STATE field to a new value.
#define BW_PCIE_SCSR_MRL_SENSOR_STATE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_MRL_SENSOR_STATE) | BF_PCIE_SCSR_MRL_SENSOR_STATE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field PRESENCE_DETECT_STATE[22] (RW)
 *
 * Presence Detect State
 */

#define BP_PCIE_SCSR_PRESENCE_DETECT_STATE      (22)      //!< Bit position for PCIE_SCSR_PRESENCE_DETECT_STATE.
#define BM_PCIE_SCSR_PRESENCE_DETECT_STATE      (0x00400000)  //!< Bit mask for PCIE_SCSR_PRESENCE_DETECT_STATE.

//! @brief Get value of PCIE_SCSR_PRESENCE_DETECT_STATE from a register value.
#define BG_PCIE_SCSR_PRESENCE_DETECT_STATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_PRESENCE_DETECT_STATE) >> BP_PCIE_SCSR_PRESENCE_DETECT_STATE)

//! @brief Format value for bitfield PCIE_SCSR_PRESENCE_DETECT_STATE.
#define BF_PCIE_SCSR_PRESENCE_DETECT_STATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_PRESENCE_DETECT_STATE) & BM_PCIE_SCSR_PRESENCE_DETECT_STATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESENCE_DETECT_STATE field to a new value.
#define BW_PCIE_SCSR_PRESENCE_DETECT_STATE(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_PRESENCE_DETECT_STATE) | BF_PCIE_SCSR_PRESENCE_DETECT_STATE(v)))
#endif

/* --- Register HW_PCIE_SCSR, field ELECTROMECHANICAL_INTERLOCK_STATUS[23] (RW)
 *
 * Electromechanical Interlock Status
 */

#define BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS      (23)      //!< Bit position for PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS.
#define BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS      (0x00800000)  //!< Bit mask for PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS.

//! @brief Get value of PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS from a register value.
#define BG_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS) >> BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS)

//! @brief Format value for bitfield PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS.
#define BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS) & BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ELECTROMECHANICAL_INTERLOCK_STATUS field to a new value.
#define BW_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS) | BF_PCIE_SCSR_ELECTROMECHANICAL_INTERLOCK_STATUS(v)))
#endif

/* --- Register HW_PCIE_SCSR, field DATA_LINK_LAYER_STATE_CHANGED[24] (RW)
 *
 * Data Link Layer State Changed
 */

#define BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED      (24)      //!< Bit position for PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED.
#define BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED      (0x01000000)  //!< Bit mask for PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED.

//! @brief Get value of PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED from a register value.
#define BG_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED) >> BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED)

//! @brief Format value for bitfield PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED.
#define BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED) & BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_LAYER_STATE_CHANGED field to a new value.
#define BW_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)   (HW_PCIE_SCSR_WR((HW_PCIE_SCSR_RD() & ~BM_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED) | BF_PCIE_SCSR_DATA_LINK_LAYER_STATE_CHANGED(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_RCCR - Root Control and Capabilities Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_RCCR - Root Control and Capabilities Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x1C
 */
typedef union _hw_pcie_rccr
{
    reg32_t U;
    struct _hw_pcie_rccr_bitfields
    {
        unsigned SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE : 1; //!< [0] System Error on Correctable Error Enable
        unsigned SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE : 1; //!< [1] System Error on Non-fatal Error Enable
        unsigned SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE : 1; //!< [2] System Error on Fatal Error Enable
        unsigned PME_INTERRUPT_ENABLE : 1; //!< [3] PME Interrupt Enable
        unsigned CRS_SOFTWARE_VISIBILITY_ENABLE : 1; //!< [4] CRS Software Visibility Enable Not supported, hardwired to 0x0.
        unsigned RESERVED0 : 11; //!< [15:5] Reserved
        unsigned CRS_SOFTWARE_VISIBILITY : 1; //!< [16] CRS Software Visibility Not supported, hardwired to 0x0.
        unsigned RESERVED1 : 15; //!< [31:17] Reserved
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

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE[0] (RW)
 *
 * System Error on Correctable Error Enable
 */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE      (0)      //!< Bit position for PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE.
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE      (0x00000001)  //!< Bit mask for PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE.

//! @brief Get value of PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE from a register value.
#define BG_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE) >> BP_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE)

//! @brief Format value for bitfield PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE.
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE field to a new value.
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE) | BF_PCIE_RCCR_SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE[1] (RW)
 *
 * System Error on Non-fatal Error Enable
 */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE      (1)      //!< Bit position for PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE.
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE      (0x00000002)  //!< Bit mask for PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE.

//! @brief Get value of PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE from a register value.
#define BG_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE) >> BP_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE)

//! @brief Format value for bitfield PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE.
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE field to a new value.
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE) | BF_PCIE_RCCR_SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RCCR, field SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE[2] (RW)
 *
 * System Error on Fatal Error Enable
 */

#define BP_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE      (2)      //!< Bit position for PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE.
#define BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE      (0x00000004)  //!< Bit mask for PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE.

//! @brief Get value of PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE from a register value.
#define BG_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE) >> BP_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE)

//! @brief Format value for bitfield PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE.
#define BF_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE) & BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE field to a new value.
#define BW_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE) | BF_PCIE_RCCR_SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RCCR, field PME_INTERRUPT_ENABLE[3] (RW)
 *
 * PME Interrupt Enable
 */

#define BP_PCIE_RCCR_PME_INTERRUPT_ENABLE      (3)      //!< Bit position for PCIE_RCCR_PME_INTERRUPT_ENABLE.
#define BM_PCIE_RCCR_PME_INTERRUPT_ENABLE      (0x00000008)  //!< Bit mask for PCIE_RCCR_PME_INTERRUPT_ENABLE.

//! @brief Get value of PCIE_RCCR_PME_INTERRUPT_ENABLE from a register value.
#define BG_PCIE_RCCR_PME_INTERRUPT_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_PME_INTERRUPT_ENABLE) >> BP_PCIE_RCCR_PME_INTERRUPT_ENABLE)

//! @brief Format value for bitfield PCIE_RCCR_PME_INTERRUPT_ENABLE.
#define BF_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_PME_INTERRUPT_ENABLE) & BM_PCIE_RCCR_PME_INTERRUPT_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_INTERRUPT_ENABLE field to a new value.
#define BW_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_PME_INTERRUPT_ENABLE) | BF_PCIE_RCCR_PME_INTERRUPT_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RCCR, field CRS_SOFTWARE_VISIBILITY_ENABLE[4] (RW)
 *
 * CRS Software Visibility Enable Not supported, hardwired to 0x0.
 */

#define BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE      (4)      //!< Bit position for PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE.
#define BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE      (0x00000010)  //!< Bit mask for PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE.

//! @brief Get value of PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE from a register value.
#define BG_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE) >> BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE)

//! @brief Format value for bitfield PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE.
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRS_SOFTWARE_VISIBILITY_ENABLE field to a new value.
#define BW_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE) | BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RCCR, field CRS_SOFTWARE_VISIBILITY[16] (RW)
 *
 * CRS Software Visibility Not supported, hardwired to 0x0.
 */

#define BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY      (16)      //!< Bit position for PCIE_RCCR_CRS_SOFTWARE_VISIBILITY.
#define BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY      (0x00010000)  //!< Bit mask for PCIE_RCCR_CRS_SOFTWARE_VISIBILITY.

//! @brief Get value of PCIE_RCCR_CRS_SOFTWARE_VISIBILITY from a register value.
#define BG_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY) >> BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY)

//! @brief Format value for bitfield PCIE_RCCR_CRS_SOFTWARE_VISIBILITY.
#define BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY) & BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRS_SOFTWARE_VISIBILITY field to a new value.
#define BW_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)   (HW_PCIE_RCCR_WR((HW_PCIE_RCCR_RD() & ~BM_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY) | BF_PCIE_RCCR_CRS_SOFTWARE_VISIBILITY(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_RSR - Root Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_RSR - Root Status Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x20
 */
typedef union _hw_pcie_rsr
{
    reg32_t U;
    struct _hw_pcie_rsr_bitfields
    {
        unsigned PME_REQUESTER_ID : 16; //!< [15:0] PME Requester ID
        unsigned PME_STATUS : 1; //!< [16] PME Status
        unsigned PME_PENDING : 1; //!< [17] PME Pending
        unsigned RESERVED0 : 14; //!< [31:18] Reserved
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

/* --- Register HW_PCIE_RSR, field PME_REQUESTER_ID[15:0] (W1C)
 *
 * PME Requester ID
 */

#define BP_PCIE_RSR_PME_REQUESTER_ID      (0)      //!< Bit position for PCIE_RSR_PME_REQUESTER_ID.
#define BM_PCIE_RSR_PME_REQUESTER_ID      (0x0000ffff)  //!< Bit mask for PCIE_RSR_PME_REQUESTER_ID.

//! @brief Get value of PCIE_RSR_PME_REQUESTER_ID from a register value.
#define BG_PCIE_RSR_PME_REQUESTER_ID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RSR_PME_REQUESTER_ID) >> BP_PCIE_RSR_PME_REQUESTER_ID)

//! @brief Format value for bitfield PCIE_RSR_PME_REQUESTER_ID.
#define BF_PCIE_RSR_PME_REQUESTER_ID(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RSR_PME_REQUESTER_ID) & BM_PCIE_RSR_PME_REQUESTER_ID)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_REQUESTER_ID field to a new value.
#define BW_PCIE_RSR_PME_REQUESTER_ID(v)   (HW_PCIE_RSR_WR((HW_PCIE_RSR_RD() & ~BM_PCIE_RSR_PME_REQUESTER_ID) | BF_PCIE_RSR_PME_REQUESTER_ID(v)))
#endif

/* --- Register HW_PCIE_RSR, field PME_STATUS[16] (W1C)
 *
 * PME Status
 */

#define BP_PCIE_RSR_PME_STATUS      (16)      //!< Bit position for PCIE_RSR_PME_STATUS.
#define BM_PCIE_RSR_PME_STATUS      (0x00010000)  //!< Bit mask for PCIE_RSR_PME_STATUS.

//! @brief Get value of PCIE_RSR_PME_STATUS from a register value.
#define BG_PCIE_RSR_PME_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RSR_PME_STATUS) >> BP_PCIE_RSR_PME_STATUS)

//! @brief Format value for bitfield PCIE_RSR_PME_STATUS.
#define BF_PCIE_RSR_PME_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RSR_PME_STATUS) & BM_PCIE_RSR_PME_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_STATUS field to a new value.
#define BW_PCIE_RSR_PME_STATUS(v)   (HW_PCIE_RSR_WR((HW_PCIE_RSR_RD() & ~BM_PCIE_RSR_PME_STATUS) | BF_PCIE_RSR_PME_STATUS(v)))
#endif

/* --- Register HW_PCIE_RSR, field PME_PENDING[17] (W1C)
 *
 * PME Pending
 */

#define BP_PCIE_RSR_PME_PENDING      (17)      //!< Bit position for PCIE_RSR_PME_PENDING.
#define BM_PCIE_RSR_PME_PENDING      (0x00020000)  //!< Bit mask for PCIE_RSR_PME_PENDING.

//! @brief Get value of PCIE_RSR_PME_PENDING from a register value.
#define BG_PCIE_RSR_PME_PENDING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RSR_PME_PENDING) >> BP_PCIE_RSR_PME_PENDING)

//! @brief Format value for bitfield PCIE_RSR_PME_PENDING.
#define BF_PCIE_RSR_PME_PENDING(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RSR_PME_PENDING) & BM_PCIE_RSR_PME_PENDING)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PME_PENDING field to a new value.
#define BW_PCIE_RSR_PME_PENDING(v)   (HW_PCIE_RSR_WR((HW_PCIE_RSR_RD() & ~BM_PCIE_RSR_PME_PENDING) | BF_PCIE_RSR_PME_PENDING(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_DCR2 - Device Capabilities 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_DCR2 - Device Capabilities 2 Register (RO)
 *
 * Reset value: 0x0000001f
 *
 * Offset: `CFG_PCIE_CAP + 0x24
 */
typedef union _hw_pcie_dcr2
{
    reg32_t U;
    struct _hw_pcie_dcr2_bitfields
    {
        unsigned COMPLETION_TIMEOUT_RANGES_SUPPORTED : 4; //!< [3:0] Completion Timeout Ranges Supported This field is applicable only to Root Ports, Endpoints that issue Requests on their own behalf, and PCI Express to PCI/PCI-X Bridges that take ownership of Requests issued on PCI Express.
        unsigned COMPLETION_TIMEOUT_DISABLE_SUPPORTED : 1; //!< [4] Completion Timeout Disable Supported
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_DCR2 bitfields
 */

/* --- Register HW_PCIE_DCR2, field COMPLETION_TIMEOUT_RANGES_SUPPORTED[3:0] (RO)
 *
 * Completion Timeout Ranges Supported This field is applicable only to Root Ports, Endpoints that
 * issue Requests on their own behalf, and PCI Express to PCI/PCI-X Bridges that take ownership of
 * Requests issued on PCI Express. the default value is 0xf (A, B, C and D ranges supported) If
 * `CX_CPL_TO_RANGES_ENABLE is not defined, the default value is 0x0.
 */

#define BP_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED      (0)      //!< Bit position for PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED.
#define BM_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED      (0x0000000f)  //!< Bit mask for PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED.

//! @brief Get value of PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED from a register value.
#define BG_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED) >> BP_PCIE_DCR2_COMPLETION_TIMEOUT_RANGES_SUPPORTED)

/* --- Register HW_PCIE_DCR2, field COMPLETION_TIMEOUT_DISABLE_SUPPORTED[4] (RO)
 *
 * Completion Timeout Disable Supported
 */

#define BP_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED      (4)      //!< Bit position for PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED.
#define BM_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED      (0x00000010)  //!< Bit mask for PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED.

//! @brief Get value of PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED from a register value.
#define BG_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED) >> BP_PCIE_DCR2_COMPLETION_TIMEOUT_DISABLE_SUPPORTED)

//-------------------------------------------------------------------------------------------
// HW_PCIE_DCSR2 - Device Control and Status 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_DCSR2 - Device Control and Status 2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x28
 */
typedef union _hw_pcie_dcsr2
{
    reg32_t U;
    struct _hw_pcie_dcsr2_bitfields
    {
        unsigned COMPLETION_TIMEOUT_VALUE : 4; //!< [3:0] Completion Timeout Value If the default range is chosen, the core will have a timeout in the range of 16ms to 55ms.
        unsigned COMPLETION_TIMEOUT_DISABLE : 1; //!< [4] Completion Timeout Disable
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
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

/* --- Register HW_PCIE_DCSR2, field COMPLETION_TIMEOUT_VALUE[3:0] (RW)
 *
 * Completion Timeout Value If the default range is chosen, the core will have a timeout in the
 * range of 16ms to 55ms. . following encodings apply: Values not defined below are reserved.
 *
 * Values:
 * 0000 - Default range: 50 ìs to 50 ms
 * 0001 - 50 ìs to 100 ìs
 * 0010 - 1 ms to 10 ms
 * 0101 - 16 ms to 55 ms
 * 0110 - 65 ms to 210 ms
 * 1001 - 260 ms to 900 ms
 * 1010 - 1 s to 3.5 s
 * 1101 - 4 s to 13 s
 * 1110 - 17 s to 64 s
 */

#define BP_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE      (0)      //!< Bit position for PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE.
#define BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE      (0x0000000f)  //!< Bit mask for PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE.

//! @brief Get value of PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE from a register value.
#define BG_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE) >> BP_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE)

//! @brief Format value for bitfield PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE.
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETION_TIMEOUT_VALUE field to a new value.
#define BW_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)   (HW_PCIE_DCSR2_WR((HW_PCIE_DCSR2_RD() & ~BM_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE) | BF_PCIE_DCSR2_COMPLETION_TIMEOUT_VALUE(v)))
#endif


/* --- Register HW_PCIE_DCSR2, field COMPLETION_TIMEOUT_DISABLE[4] (RW)
 *
 * Completion Timeout Disable
 */

#define BP_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE      (4)      //!< Bit position for PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE.
#define BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE      (0x00000010)  //!< Bit mask for PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE.

//! @brief Get value of PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE from a register value.
#define BG_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE) >> BP_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE)

//! @brief Format value for bitfield PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE.
#define BF_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE) & BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETION_TIMEOUT_DISABLE field to a new value.
#define BW_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)   (HW_PCIE_DCSR2_WR((HW_PCIE_DCSR2_RD() & ~BM_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE) | BF_PCIE_DCSR2_COMPLETION_TIMEOUT_DISABLE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_LCR2 - Link Capabilities 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_LCR2 - Link Capabilities 2 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 0x2C
 */
typedef union _hw_pcie_lcr2
{
    reg32_t U;
    struct _hw_pcie_lcr2_bitfields
    {
        unsigned RESERVED0 : 1; //!< [0] Reserved
        unsigned SUPPORTED_LINK_SPEEDS_VECTOR : 7; //!< [7:1] Supported Link Speeds Vector Indicates the supported Link speeds of the associated Port.
        unsigned CROSSLINK_SUPPORTED : 1; //!< [8] Crosslink Supported
        unsigned RESERVED1 : 23; //!< [31:9] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_LCR2 bitfields
 */

/* --- Register HW_PCIE_LCR2, field SUPPORTED_LINK_SPEEDS_VECTOR[7:1] (RO)
 *
 * Supported Link Speeds Vector Indicates the supported Link speeds of the associated Port. For each
 * bit, a value of 1b indicates that the corresponding Link speed is supported; otherwise, the Link
 * speed is not supported. Bit definitions are: Bit 1 2.5 GT/s Bit 2 5.0 GT/s Bit 3 8.0 GT/s Bits
 * 7:4 reserved This field is writable through the DBI.
 */

#define BP_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR      (1)      //!< Bit position for PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR.
#define BM_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR      (0x000000fe)  //!< Bit mask for PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR.

//! @brief Get value of PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR from a register value.
#define BG_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR) >> BP_PCIE_LCR2_SUPPORTED_LINK_SPEEDS_VECTOR)

/* --- Register HW_PCIE_LCR2, field CROSSLINK_SUPPORTED[8] (RO)
 *
 * Crosslink Supported
 */

#define BP_PCIE_LCR2_CROSSLINK_SUPPORTED      (8)      //!< Bit position for PCIE_LCR2_CROSSLINK_SUPPORTED.
#define BM_PCIE_LCR2_CROSSLINK_SUPPORTED      (0x00000100)  //!< Bit mask for PCIE_LCR2_CROSSLINK_SUPPORTED.

//! @brief Get value of PCIE_LCR2_CROSSLINK_SUPPORTED from a register value.
#define BG_PCIE_LCR2_CROSSLINK_SUPPORTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCR2_CROSSLINK_SUPPORTED) >> BP_PCIE_LCR2_CROSSLINK_SUPPORTED)

//-------------------------------------------------------------------------------------------
// HW_PCIE_LCSR2 - Link Control and Status 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_LCSR2 - Link Control and Status 2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: `CFG_PCIE_CAP + 30
 */
typedef union _hw_pcie_lcsr2
{
    reg32_t U;
    struct _hw_pcie_lcsr2_bitfields
    {
        unsigned TARGET_LINK_SPEED : 4; //!< [3:0] Target Link Speed For Downstream ports, this field sets an upper limit on link operational speed by restricting the values advertised by the upstream component in its training sequences: The encoding is the binary value of the bit in the Supported Link Speeds Vector (in the Link Capabilities 2 register) that corresponds to the desired target Link speed.
        unsigned ENTER_COMPLIANCE : 1; //!< [4] Enter Compliance Software is permitted to force a link to enter Compliance mode at the speed indicated in the Target Link Speed field by setting this bit to 1b in both components on a link and then initiating a hot reset on the link.
        unsigned HARDWARE_AUTONOMOUS_SPEED_DISABLE : 1; //!< [5] Hardware Autonomous Speed Disable When cfg_hw_auto_sp_dis signal is asserted, the application must disable hardware from changing the Link speed for device-specific reasons other than attempting to correct unreliable Link operation by reducing Link speed.
        unsigned SELECTABLE_DEEMPHASIS : 1; //!< [6] Selectable De-emphasis When the Link is operating at 2.5 GT/s speed, the setting of this bit has no effect.
        unsigned TRANSMIT_MARGIN : 3; //!< [9:7] Transmit Margin This field is reset to 000b on entry to the LTSSM Polling.
        unsigned ENTER_MODIFIED_COMPLIANCE : 1; //!< [10] Enter Modified Compliance When this bit is set to 1b, the device transmits modified compliance pattern if the LTSSM enters Polling.
        unsigned COMPLIANCE_SOS : 1; //!< [11] Compliance SOS When set to 1b, the LTSSM is required to send SKP Ordered Sets periodically in between the (modified) compliance patterns.
        unsigned COMPLIANCE_PRE_SET_DEEMPHASIS : 4; //!< [15:12] Compliance Pre-set/ De-emphasis
        unsigned CURRENT_DEEMPHASIS_LEVEL : 1; //!< [16] Current De-emphasis Level
        unsigned EQUALIZATION_COMPLETE : 1; //!< [17] Equalization Complete
        unsigned EQUALIZATION_PHASE_1_SUCCESSFUL : 1; //!< [18] Equalization Phase 1 Successful
        unsigned EQUALIZATION_PHASE_2_SUCCESSFUL : 1; //!< [19] Equalization Phase 2 Successful
        unsigned EQUALIZATION_PHASE_3_SUCCESSFUL : 1; //!< [20] Equalization Phase 3 Successful
        unsigned LINK_EQUALIZATION_REQUEST : 1; //!< [21] Link Equalization Request
        unsigned RESERVED0 : 10; //!< [31:22] Reserved
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

/* --- Register HW_PCIE_LCSR2, field TARGET_LINK_SPEED[3:0] (RW)
 *
 * Target Link Speed For Downstream ports, this field sets an upper limit on link operational speed
 * by restricting the values advertised by the upstream component in its training sequences: The
 * encoding is the binary value of the bit in the Supported Link Speeds Vector (in the Link
 * Capabilities 2 register) that corresponds to the desired target Link speed. If a value is written
 * to this field that does not correspond to a speed included in the Supported Link Speeds field,
 * the result is undefined. The default value of this field is the highest link speed supported by
 * the component (as reported in the Max Link Speed field of the Link Capabilities Register) unless
 * the corresponding platform / form factor requires a different default value. Components that
 * support only the 2.5 GT/s speed are permitted to hardwire this field to 0000b. All other
 * encodings are reserved.
 *
 * Values:
 * 0000001 - Gen1 2.5 GT/s
 * 0000010 - Gen2 5.0 GT/s
 * 0000100 - Gen3 8.0 GT/s
 */

#define BP_PCIE_LCSR2_TARGET_LINK_SPEED      (0)      //!< Bit position for PCIE_LCSR2_TARGET_LINK_SPEED.
#define BM_PCIE_LCSR2_TARGET_LINK_SPEED      (0x0000000f)  //!< Bit mask for PCIE_LCSR2_TARGET_LINK_SPEED.

//! @brief Get value of PCIE_LCSR2_TARGET_LINK_SPEED from a register value.
#define BG_PCIE_LCSR2_TARGET_LINK_SPEED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_TARGET_LINK_SPEED) >> BP_PCIE_LCSR2_TARGET_LINK_SPEED)

//! @brief Format value for bitfield PCIE_LCSR2_TARGET_LINK_SPEED.
#define BF_PCIE_LCSR2_TARGET_LINK_SPEED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_TARGET_LINK_SPEED) & BM_PCIE_LCSR2_TARGET_LINK_SPEED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TARGET_LINK_SPEED field to a new value.
#define BW_PCIE_LCSR2_TARGET_LINK_SPEED(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_TARGET_LINK_SPEED) | BF_PCIE_LCSR2_TARGET_LINK_SPEED(v)))
#endif


/* --- Register HW_PCIE_LCSR2, field ENTER_COMPLIANCE[4] (RW)
 *
 * Enter Compliance Software is permitted to force a link to enter Compliance mode at the speed
 * indicated in the Target Link Speed field by setting this bit to 1b in both components on a link
 * and then initiating a hot reset on the link. The default value of this field following
 * Fundamental Reset is 0b.
 */

#define BP_PCIE_LCSR2_ENTER_COMPLIANCE      (4)      //!< Bit position for PCIE_LCSR2_ENTER_COMPLIANCE.
#define BM_PCIE_LCSR2_ENTER_COMPLIANCE      (0x00000010)  //!< Bit mask for PCIE_LCSR2_ENTER_COMPLIANCE.

//! @brief Get value of PCIE_LCSR2_ENTER_COMPLIANCE from a register value.
#define BG_PCIE_LCSR2_ENTER_COMPLIANCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_ENTER_COMPLIANCE) >> BP_PCIE_LCSR2_ENTER_COMPLIANCE)

//! @brief Format value for bitfield PCIE_LCSR2_ENTER_COMPLIANCE.
#define BF_PCIE_LCSR2_ENTER_COMPLIANCE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_ENTER_COMPLIANCE) & BM_PCIE_LCSR2_ENTER_COMPLIANCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTER_COMPLIANCE field to a new value.
#define BW_PCIE_LCSR2_ENTER_COMPLIANCE(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_ENTER_COMPLIANCE) | BF_PCIE_LCSR2_ENTER_COMPLIANCE(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field HARDWARE_AUTONOMOUS_SPEED_DISABLE[5] (RW)
 *
 * Hardware Autonomous Speed Disable When cfg_hw_auto_sp_dis signal is asserted, the application
 * must disable hardware from changing the Link speed for device-specific reasons other than
 * attempting to correct unreliable Link operation by reducing Link speed. Initial transition to the
 * highest supported common link speed is not blocked by this signal.
 */

#define BP_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE      (5)      //!< Bit position for PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE.
#define BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE      (0x00000020)  //!< Bit mask for PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE.

//! @brief Get value of PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE from a register value.
#define BG_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE) >> BP_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE)

//! @brief Format value for bitfield PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE.
#define BF_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE) & BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HARDWARE_AUTONOMOUS_SPEED_DISABLE field to a new value.
#define BW_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE) | BF_PCIE_LCSR2_HARDWARE_AUTONOMOUS_SPEED_DISABLE(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field SELECTABLE_DEEMPHASIS[6] (RW)
 *
 * Selectable De-emphasis When the Link is operating at 2.5 GT/s speed, the setting of this bit has
 * no effect. Components that support only the 2.5 GT/s speed are permitted to hardwire this bit to
 * 0b. Default value is implementation-specific, unless a specific value is required for a selected
 * form factor or platform. When the Link is operating at 5.0 GT/s speed, selects the level of de-
 * emphasis:
 *
 * Values:
 * 0 - -6 dB
 * 1 - -3.5 dB
 */

#define BP_PCIE_LCSR2_SELECTABLE_DEEMPHASIS      (6)      //!< Bit position for PCIE_LCSR2_SELECTABLE_DEEMPHASIS.
#define BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS      (0x00000040)  //!< Bit mask for PCIE_LCSR2_SELECTABLE_DEEMPHASIS.

//! @brief Get value of PCIE_LCSR2_SELECTABLE_DEEMPHASIS from a register value.
#define BG_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS) >> BP_PCIE_LCSR2_SELECTABLE_DEEMPHASIS)

//! @brief Format value for bitfield PCIE_LCSR2_SELECTABLE_DEEMPHASIS.
#define BF_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_SELECTABLE_DEEMPHASIS) & BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SELECTABLE_DEEMPHASIS field to a new value.
#define BW_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_SELECTABLE_DEEMPHASIS) | BF_PCIE_LCSR2_SELECTABLE_DEEMPHASIS(v)))
#endif


/* --- Register HW_PCIE_LCSR2, field TRANSMIT_MARGIN[9:7] (RW)
 *
 * Transmit Margin This field is reset to 000b on entry to the LTSSM Polling. Compliance substate.
 * Components that support only the 2.5 GT/s speed are permitted to hard-wire this bit to 0b. When
 * operating in 5.0 GT/s mode with full swing, the de-emphasis ratio must be maintained within +/- 1
 * dB from the specification-defined operational value (either -3.5 or -6 dB). This field controls
 * the value of the non-de-emphasized voltage level at the Transmitter pins:
 *
 * Values:
 * 000 - 800-1200 mV for full swing 400-600 mV for half- swing
 * 011 - 200-400 mV for full-swing and 100-200 mV for halfswing
 * 001-010 - values must be monotonic with a non-zero slope
 * 100-111 - reserved
 */

#define BP_PCIE_LCSR2_TRANSMIT_MARGIN      (7)      //!< Bit position for PCIE_LCSR2_TRANSMIT_MARGIN.
#define BM_PCIE_LCSR2_TRANSMIT_MARGIN      (0x00000380)  //!< Bit mask for PCIE_LCSR2_TRANSMIT_MARGIN.

//! @brief Get value of PCIE_LCSR2_TRANSMIT_MARGIN from a register value.
#define BG_PCIE_LCSR2_TRANSMIT_MARGIN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_TRANSMIT_MARGIN) >> BP_PCIE_LCSR2_TRANSMIT_MARGIN)

//! @brief Format value for bitfield PCIE_LCSR2_TRANSMIT_MARGIN.
#define BF_PCIE_LCSR2_TRANSMIT_MARGIN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_TRANSMIT_MARGIN) & BM_PCIE_LCSR2_TRANSMIT_MARGIN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRANSMIT_MARGIN field to a new value.
#define BW_PCIE_LCSR2_TRANSMIT_MARGIN(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_TRANSMIT_MARGIN) | BF_PCIE_LCSR2_TRANSMIT_MARGIN(v)))
#endif


/* --- Register HW_PCIE_LCSR2, field ENTER_MODIFIED_COMPLIANCE[10] (RW)
 *
 * Enter Modified Compliance When this bit is set to 1b, the device transmits modified compliance
 * pattern if the LTSSM enters Polling. Compliance state. Components that support only the 2.5 GT/s
 * speed are permitted to hard-wire this bit to 0b.
 */

#define BP_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE      (10)      //!< Bit position for PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE.
#define BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE      (0x00000400)  //!< Bit mask for PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE.

//! @brief Get value of PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE from a register value.
#define BG_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE) >> BP_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE)

//! @brief Format value for bitfield PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE.
#define BF_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE) & BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTER_MODIFIED_COMPLIANCE field to a new value.
#define BW_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE) | BF_PCIE_LCSR2_ENTER_MODIFIED_COMPLIANCE(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field COMPLIANCE_SOS[11] (RW)
 *
 * Compliance SOS When set to 1b, the LTSSM is required to send SKP Ordered Sets periodically in
 * between the (modified) compliance patterns. GT/s speed are permitted to hardwire this bit to 0b.
 * When the Link is operating at 2.5 GT/s, the setting of this bit has no effect. Components that
 * support only 2.5
 */

#define BP_PCIE_LCSR2_COMPLIANCE_SOS      (11)      //!< Bit position for PCIE_LCSR2_COMPLIANCE_SOS.
#define BM_PCIE_LCSR2_COMPLIANCE_SOS      (0x00000800)  //!< Bit mask for PCIE_LCSR2_COMPLIANCE_SOS.

//! @brief Get value of PCIE_LCSR2_COMPLIANCE_SOS from a register value.
#define BG_PCIE_LCSR2_COMPLIANCE_SOS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_COMPLIANCE_SOS) >> BP_PCIE_LCSR2_COMPLIANCE_SOS)

//! @brief Format value for bitfield PCIE_LCSR2_COMPLIANCE_SOS.
#define BF_PCIE_LCSR2_COMPLIANCE_SOS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_COMPLIANCE_SOS) & BM_PCIE_LCSR2_COMPLIANCE_SOS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLIANCE_SOS field to a new value.
#define BW_PCIE_LCSR2_COMPLIANCE_SOS(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_COMPLIANCE_SOS) | BF_PCIE_LCSR2_COMPLIANCE_SOS(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field COMPLIANCE_PRE_SET_DEEMPHASIS[15:12] (RW)
 *
 * Compliance Pre-set/ De-emphasis
 */

#define BP_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS      (12)      //!< Bit position for PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS.
#define BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS      (0x0000f000)  //!< Bit mask for PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS.

//! @brief Get value of PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS from a register value.
#define BG_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS) >> BP_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS)

//! @brief Format value for bitfield PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS.
#define BF_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS) & BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLIANCE_PRE_SET_DEEMPHASIS field to a new value.
#define BW_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS) | BF_PCIE_LCSR2_COMPLIANCE_PRE_SET_DEEMPHASIS(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field CURRENT_DEEMPHASIS_LEVEL[16] (RW)
 *
 * Current De-emphasis Level
 */

#define BP_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL      (16)      //!< Bit position for PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL.
#define BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL      (0x00010000)  //!< Bit mask for PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL.

//! @brief Get value of PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL from a register value.
#define BG_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL) >> BP_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL)

//! @brief Format value for bitfield PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL.
#define BF_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL) & BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CURRENT_DEEMPHASIS_LEVEL field to a new value.
#define BW_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL) | BF_PCIE_LCSR2_CURRENT_DEEMPHASIS_LEVEL(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_COMPLETE[17] (RW)
 *
 * Equalization Complete
 */

#define BP_PCIE_LCSR2_EQUALIZATION_COMPLETE      (17)      //!< Bit position for PCIE_LCSR2_EQUALIZATION_COMPLETE.
#define BM_PCIE_LCSR2_EQUALIZATION_COMPLETE      (0x00020000)  //!< Bit mask for PCIE_LCSR2_EQUALIZATION_COMPLETE.

//! @brief Get value of PCIE_LCSR2_EQUALIZATION_COMPLETE from a register value.
#define BG_PCIE_LCSR2_EQUALIZATION_COMPLETE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_EQUALIZATION_COMPLETE) >> BP_PCIE_LCSR2_EQUALIZATION_COMPLETE)

//! @brief Format value for bitfield PCIE_LCSR2_EQUALIZATION_COMPLETE.
#define BF_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_EQUALIZATION_COMPLETE) & BM_PCIE_LCSR2_EQUALIZATION_COMPLETE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EQUALIZATION_COMPLETE field to a new value.
#define BW_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_EQUALIZATION_COMPLETE) | BF_PCIE_LCSR2_EQUALIZATION_COMPLETE(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_1_SUCCESSFUL[18] (RW)
 *
 * Equalization Phase 1 Successful
 */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL      (18)      //!< Bit position for PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL.
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL      (0x00040000)  //!< Bit mask for PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL.

//! @brief Get value of PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL from a register value.
#define BG_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL) >> BP_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL)

//! @brief Format value for bitfield PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL.
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EQUALIZATION_PHASE_1_SUCCESSFUL field to a new value.
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL) | BF_PCIE_LCSR2_EQUALIZATION_PHASE_1_SUCCESSFUL(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_2_SUCCESSFUL[19] (RW)
 *
 * Equalization Phase 2 Successful
 */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL      (19)      //!< Bit position for PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL.
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL      (0x00080000)  //!< Bit mask for PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL.

//! @brief Get value of PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL from a register value.
#define BG_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL) >> BP_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL)

//! @brief Format value for bitfield PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL.
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EQUALIZATION_PHASE_2_SUCCESSFUL field to a new value.
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL) | BF_PCIE_LCSR2_EQUALIZATION_PHASE_2_SUCCESSFUL(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field EQUALIZATION_PHASE_3_SUCCESSFUL[20] (RW)
 *
 * Equalization Phase 3 Successful
 */

#define BP_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL      (20)      //!< Bit position for PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL.
#define BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL      (0x00100000)  //!< Bit mask for PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL.

//! @brief Get value of PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL from a register value.
#define BG_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL) >> BP_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL)

//! @brief Format value for bitfield PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL.
#define BF_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL) & BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EQUALIZATION_PHASE_3_SUCCESSFUL field to a new value.
#define BW_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL) | BF_PCIE_LCSR2_EQUALIZATION_PHASE_3_SUCCESSFUL(v)))
#endif

/* --- Register HW_PCIE_LCSR2, field LINK_EQUALIZATION_REQUEST[21] (RW)
 *
 * Link Equalization Request
 */

#define BP_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST      (21)      //!< Bit position for PCIE_LCSR2_LINK_EQUALIZATION_REQUEST.
#define BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST      (0x00200000)  //!< Bit mask for PCIE_LCSR2_LINK_EQUALIZATION_REQUEST.

//! @brief Get value of PCIE_LCSR2_LINK_EQUALIZATION_REQUEST from a register value.
#define BG_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST) >> BP_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST)

//! @brief Format value for bitfield PCIE_LCSR2_LINK_EQUALIZATION_REQUEST.
#define BF_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST) & BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINK_EQUALIZATION_REQUEST field to a new value.
#define BW_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)   (HW_PCIE_LCSR2_WR((HW_PCIE_LCSR2_RD() & ~BM_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST) | BF_PCIE_LCSR2_LINK_EQUALIZATION_REQUEST(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_AER - AER Capability Header
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_AER - AER Capability Header (RW)
 *
 * Reset value: 0x00000000
 *
 * The core implements the following PCI Express Extended Capabilities registers:  ? Advanced Error
 * Reporting Capability register set  ? Virtual Channel Capability register set -  Address: 0x100
 */
typedef union _hw_pcie_aer
{
    reg32_t U;
    struct _hw_pcie_aer_bitfields
    {
        unsigned PCI_EXPRESS_EXTENDED_CAPABILITY_ID : 16; //!< [15:0] PCI Express Extended Capability ID Value is 0x1 for Advanced Error Reporting.
        unsigned CAPABILITY_VERSION : 4; //!< [19:16] Capability Version
        unsigned NEXT_CAPABILITY_OFFSET : 12; //!< [31:20] Next Capability Offset See Table 5-222 on page 641.
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

/* --- Register HW_PCIE_AER, field PCI_EXPRESS_EXTENDED_CAPABILITY_ID[15:0] (RW)
 *
 * PCI Express Extended Capability ID Value is 0x1 for Advanced Error Reporting.
 */

#define BP_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID      (0)      //!< Bit position for PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID.
#define BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID      (0x0000ffff)  //!< Bit mask for PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID.

//! @brief Get value of PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID from a register value.
#define BG_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID) >> BP_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID)

//! @brief Format value for bitfield PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID.
#define BF_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID) & BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCI_EXPRESS_EXTENDED_CAPABILITY_ID field to a new value.
#define BW_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)   (HW_PCIE_AER_WR((HW_PCIE_AER_RD() & ~BM_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID) | BF_PCIE_AER_PCI_EXPRESS_EXTENDED_CAPABILITY_ID(v)))
#endif

/* --- Register HW_PCIE_AER, field CAPABILITY_VERSION[19:16] (RW)
 *
 * Capability Version
 */

#define BP_PCIE_AER_CAPABILITY_VERSION      (16)      //!< Bit position for PCIE_AER_CAPABILITY_VERSION.
#define BM_PCIE_AER_CAPABILITY_VERSION      (0x000f0000)  //!< Bit mask for PCIE_AER_CAPABILITY_VERSION.

//! @brief Get value of PCIE_AER_CAPABILITY_VERSION from a register value.
#define BG_PCIE_AER_CAPABILITY_VERSION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_AER_CAPABILITY_VERSION) >> BP_PCIE_AER_CAPABILITY_VERSION)

//! @brief Format value for bitfield PCIE_AER_CAPABILITY_VERSION.
#define BF_PCIE_AER_CAPABILITY_VERSION(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_AER_CAPABILITY_VERSION) & BM_PCIE_AER_CAPABILITY_VERSION)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPABILITY_VERSION field to a new value.
#define BW_PCIE_AER_CAPABILITY_VERSION(v)   (HW_PCIE_AER_WR((HW_PCIE_AER_RD() & ~BM_PCIE_AER_CAPABILITY_VERSION) | BF_PCIE_AER_CAPABILITY_VERSION(v)))
#endif

/* --- Register HW_PCIE_AER, field NEXT_CAPABILITY_OFFSET[31:20] (RW)
 *
 * Next Capability Offset See Table 5-222 on page 641.
 */

#define BP_PCIE_AER_NEXT_CAPABILITY_OFFSET      (20)      //!< Bit position for PCIE_AER_NEXT_CAPABILITY_OFFSET.
#define BM_PCIE_AER_NEXT_CAPABILITY_OFFSET      (0xfff00000)  //!< Bit mask for PCIE_AER_NEXT_CAPABILITY_OFFSET.

//! @brief Get value of PCIE_AER_NEXT_CAPABILITY_OFFSET from a register value.
#define BG_PCIE_AER_NEXT_CAPABILITY_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_AER_NEXT_CAPABILITY_OFFSET) >> BP_PCIE_AER_NEXT_CAPABILITY_OFFSET)

//! @brief Format value for bitfield PCIE_AER_NEXT_CAPABILITY_OFFSET.
#define BF_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_AER_NEXT_CAPABILITY_OFFSET) & BM_PCIE_AER_NEXT_CAPABILITY_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NEXT_CAPABILITY_OFFSET field to a new value.
#define BW_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)   (HW_PCIE_AER_WR((HW_PCIE_AER_RD() & ~BM_PCIE_AER_NEXT_CAPABILITY_OFFSET) | BF_PCIE_AER_NEXT_CAPABILITY_OFFSET(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_UESR - Uncorrectable Error Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_UESR - Uncorrectable Error Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x04
 */
typedef union _hw_pcie_uesr
{
    reg32_t U;
    struct _hw_pcie_uesr_bitfields
    {
        unsigned RESERVED0 : 4; //!< [3:0] Reserved.
        unsigned DATA_LINK_PROTOCOL_ERROR_STATUS : 1; //!< [4] Data Link Protocol Error Status
        unsigned SURPRISE_DOWN_ERROR_STATUS : 1; //!< [5] Surprise Down Error Status (not supported)
        unsigned RESERVED1 : 6; //!< [11:6] Reserved
        unsigned POISONED_TLP_STATUS : 1; //!< [12] Poisoned TLP Status
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_STATUS : 1; //!< [13] Flow Control Protocol Error Status
        unsigned COMPLETION_TIMEOUT_STATUS : 1; //!< [14] Completion Timeout Status
        unsigned COMPLETER_ABORT_STATUS : 1; //!< [15] Completer Abort Status
        unsigned UNEXPECTED_COMPLETION_STATUS : 1; //!< [16] Unexpected Completion Status
        unsigned RECEIVER_OVERFLOW_STATUS : 1; //!< [17] Receiver Overflow Status
        unsigned MALFORMED_TLP_STATUS : 1; //!< [18] Malformed TLP Status
        unsigned ECRC_ERROR_STATUS : 1; //!< [19] ECRC Error Status
        unsigned UNSUPPORTED_REQUEST_ERROR_STATUS : 1; //!< [20] Unsupported Request Error Status
        unsigned RESERVED2 : 11; //!< [31:21] Reserved
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

/* --- Register HW_PCIE_UESR, field DATA_LINK_PROTOCOL_ERROR_STATUS[4] (RW)
 *
 * Data Link Protocol Error Status
 */

#define BP_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS      (4)      //!< Bit position for PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS.
#define BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS      (0x00000010)  //!< Bit mask for PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS.

//! @brief Get value of PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS from a register value.
#define BG_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS) >> BP_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS.
#define BF_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS) & BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_PROTOCOL_ERROR_STATUS field to a new value.
#define BW_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS) | BF_PCIE_UESR_DATA_LINK_PROTOCOL_ERROR_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field SURPRISE_DOWN_ERROR_STATUS[5] (RW)
 *
 * Surprise Down Error Status (not supported)
 */

#define BP_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS      (5)      //!< Bit position for PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS.
#define BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS      (0x00000020)  //!< Bit mask for PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS.

//! @brief Get value of PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS from a register value.
#define BG_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS) >> BP_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS.
#define BF_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS) & BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SURPRISE_DOWN_ERROR_STATUS field to a new value.
#define BW_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS) | BF_PCIE_UESR_SURPRISE_DOWN_ERROR_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field POISONED_TLP_STATUS[12] (RW)
 *
 * Poisoned TLP Status
 */

#define BP_PCIE_UESR_POISONED_TLP_STATUS      (12)      //!< Bit position for PCIE_UESR_POISONED_TLP_STATUS.
#define BM_PCIE_UESR_POISONED_TLP_STATUS      (0x00001000)  //!< Bit mask for PCIE_UESR_POISONED_TLP_STATUS.

//! @brief Get value of PCIE_UESR_POISONED_TLP_STATUS from a register value.
#define BG_PCIE_UESR_POISONED_TLP_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_POISONED_TLP_STATUS) >> BP_PCIE_UESR_POISONED_TLP_STATUS)

//! @brief Format value for bitfield PCIE_UESR_POISONED_TLP_STATUS.
#define BF_PCIE_UESR_POISONED_TLP_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_POISONED_TLP_STATUS) & BM_PCIE_UESR_POISONED_TLP_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POISONED_TLP_STATUS field to a new value.
#define BW_PCIE_UESR_POISONED_TLP_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_POISONED_TLP_STATUS) | BF_PCIE_UESR_POISONED_TLP_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field FLOW_CONTROL_PROTOCOL_ERROR_STATUS[13] (RW)
 *
 * Flow Control Protocol Error Status
 */

#define BP_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS      (13)      //!< Bit position for PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS.
#define BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS      (0x00002000)  //!< Bit mask for PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS.

//! @brief Get value of PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS from a register value.
#define BG_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS) >> BP_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS.
#define BF_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS) & BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLOW_CONTROL_PROTOCOL_ERROR_STATUS field to a new value.
#define BW_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS) | BF_PCIE_UESR_FLOW_CONTROL_PROTOCOL_ERROR_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field COMPLETION_TIMEOUT_STATUS[14] (RW)
 *
 * Completion Timeout Status
 */

#define BP_PCIE_UESR_COMPLETION_TIMEOUT_STATUS      (14)      //!< Bit position for PCIE_UESR_COMPLETION_TIMEOUT_STATUS.
#define BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS      (0x00004000)  //!< Bit mask for PCIE_UESR_COMPLETION_TIMEOUT_STATUS.

//! @brief Get value of PCIE_UESR_COMPLETION_TIMEOUT_STATUS from a register value.
#define BG_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS) >> BP_PCIE_UESR_COMPLETION_TIMEOUT_STATUS)

//! @brief Format value for bitfield PCIE_UESR_COMPLETION_TIMEOUT_STATUS.
#define BF_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_COMPLETION_TIMEOUT_STATUS) & BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETION_TIMEOUT_STATUS field to a new value.
#define BW_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_COMPLETION_TIMEOUT_STATUS) | BF_PCIE_UESR_COMPLETION_TIMEOUT_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field COMPLETER_ABORT_STATUS[15] (RW)
 *
 * Completer Abort Status
 */

#define BP_PCIE_UESR_COMPLETER_ABORT_STATUS      (15)      //!< Bit position for PCIE_UESR_COMPLETER_ABORT_STATUS.
#define BM_PCIE_UESR_COMPLETER_ABORT_STATUS      (0x00008000)  //!< Bit mask for PCIE_UESR_COMPLETER_ABORT_STATUS.

//! @brief Get value of PCIE_UESR_COMPLETER_ABORT_STATUS from a register value.
#define BG_PCIE_UESR_COMPLETER_ABORT_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_COMPLETER_ABORT_STATUS) >> BP_PCIE_UESR_COMPLETER_ABORT_STATUS)

//! @brief Format value for bitfield PCIE_UESR_COMPLETER_ABORT_STATUS.
#define BF_PCIE_UESR_COMPLETER_ABORT_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_COMPLETER_ABORT_STATUS) & BM_PCIE_UESR_COMPLETER_ABORT_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETER_ABORT_STATUS field to a new value.
#define BW_PCIE_UESR_COMPLETER_ABORT_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_COMPLETER_ABORT_STATUS) | BF_PCIE_UESR_COMPLETER_ABORT_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field UNEXPECTED_COMPLETION_STATUS[16] (RW)
 *
 * Unexpected Completion Status
 */

#define BP_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS      (16)      //!< Bit position for PCIE_UESR_UNEXPECTED_COMPLETION_STATUS.
#define BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS      (0x00010000)  //!< Bit mask for PCIE_UESR_UNEXPECTED_COMPLETION_STATUS.

//! @brief Get value of PCIE_UESR_UNEXPECTED_COMPLETION_STATUS from a register value.
#define BG_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS) >> BP_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS)

//! @brief Format value for bitfield PCIE_UESR_UNEXPECTED_COMPLETION_STATUS.
#define BF_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS) & BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNEXPECTED_COMPLETION_STATUS field to a new value.
#define BW_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS) | BF_PCIE_UESR_UNEXPECTED_COMPLETION_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field RECEIVER_OVERFLOW_STATUS[17] (RW)
 *
 * Receiver Overflow Status
 */

#define BP_PCIE_UESR_RECEIVER_OVERFLOW_STATUS      (17)      //!< Bit position for PCIE_UESR_RECEIVER_OVERFLOW_STATUS.
#define BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS      (0x00020000)  //!< Bit mask for PCIE_UESR_RECEIVER_OVERFLOW_STATUS.

//! @brief Get value of PCIE_UESR_RECEIVER_OVERFLOW_STATUS from a register value.
#define BG_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS) >> BP_PCIE_UESR_RECEIVER_OVERFLOW_STATUS)

//! @brief Format value for bitfield PCIE_UESR_RECEIVER_OVERFLOW_STATUS.
#define BF_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_RECEIVER_OVERFLOW_STATUS) & BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVER_OVERFLOW_STATUS field to a new value.
#define BW_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_RECEIVER_OVERFLOW_STATUS) | BF_PCIE_UESR_RECEIVER_OVERFLOW_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field MALFORMED_TLP_STATUS[18] (RW)
 *
 * Malformed TLP Status
 */

#define BP_PCIE_UESR_MALFORMED_TLP_STATUS      (18)      //!< Bit position for PCIE_UESR_MALFORMED_TLP_STATUS.
#define BM_PCIE_UESR_MALFORMED_TLP_STATUS      (0x00040000)  //!< Bit mask for PCIE_UESR_MALFORMED_TLP_STATUS.

//! @brief Get value of PCIE_UESR_MALFORMED_TLP_STATUS from a register value.
#define BG_PCIE_UESR_MALFORMED_TLP_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_MALFORMED_TLP_STATUS) >> BP_PCIE_UESR_MALFORMED_TLP_STATUS)

//! @brief Format value for bitfield PCIE_UESR_MALFORMED_TLP_STATUS.
#define BF_PCIE_UESR_MALFORMED_TLP_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_MALFORMED_TLP_STATUS) & BM_PCIE_UESR_MALFORMED_TLP_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MALFORMED_TLP_STATUS field to a new value.
#define BW_PCIE_UESR_MALFORMED_TLP_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_MALFORMED_TLP_STATUS) | BF_PCIE_UESR_MALFORMED_TLP_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field ECRC_ERROR_STATUS[19] (RW)
 *
 * ECRC Error Status
 */

#define BP_PCIE_UESR_ECRC_ERROR_STATUS      (19)      //!< Bit position for PCIE_UESR_ECRC_ERROR_STATUS.
#define BM_PCIE_UESR_ECRC_ERROR_STATUS      (0x00080000)  //!< Bit mask for PCIE_UESR_ECRC_ERROR_STATUS.

//! @brief Get value of PCIE_UESR_ECRC_ERROR_STATUS from a register value.
#define BG_PCIE_UESR_ECRC_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_ECRC_ERROR_STATUS) >> BP_PCIE_UESR_ECRC_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_UESR_ECRC_ERROR_STATUS.
#define BF_PCIE_UESR_ECRC_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_ECRC_ERROR_STATUS) & BM_PCIE_UESR_ECRC_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_ERROR_STATUS field to a new value.
#define BW_PCIE_UESR_ECRC_ERROR_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_ECRC_ERROR_STATUS) | BF_PCIE_UESR_ECRC_ERROR_STATUS(v)))
#endif

/* --- Register HW_PCIE_UESR, field UNSUPPORTED_REQUEST_ERROR_STATUS[20] (RW)
 *
 * Unsupported Request Error Status
 */

#define BP_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS      (20)      //!< Bit position for PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS.
#define BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS      (0x00100000)  //!< Bit mask for PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS.

//! @brief Get value of PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS from a register value.
#define BG_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS) >> BP_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS.
#define BF_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS) & BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNSUPPORTED_REQUEST_ERROR_STATUS field to a new value.
#define BW_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)   (HW_PCIE_UESR_WR((HW_PCIE_UESR_RD() & ~BM_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS) | BF_PCIE_UESR_UNSUPPORTED_REQUEST_ERROR_STATUS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_UEMR - Uncorrectable Error Mask Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_UEMR - Uncorrectable Error Mask Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x08
 */
typedef union _hw_pcie_uemr
{
    reg32_t U;
    struct _hw_pcie_uemr_bitfields
    {
        unsigned RESERVED0 : 4; //!< [3:0] Reserved.
        unsigned DATA_LINK_PROTOCOL_ERROR_MASK : 1; //!< [4] Data Link Protocol Error Mask
        unsigned SURPRISE_DOWN_ERROR_MASK : 1; //!< [5] Surprise Down Error Mask (not supported)
        unsigned RESERVED1 : 6; //!< [11:6] Reserved
        unsigned POISONED_TLP_MASK : 1; //!< [12] Poisoned TLP Mask
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_MASK : 1; //!< [13] Flow Control Protocol Error Mask
        unsigned COMPLETION_TIMEOUT_MASK : 1; //!< [14] Completion Timeout Mask
        unsigned COMPLETER_ABORT_MASK : 1; //!< [15] Completer Abort Mask
        unsigned UNEXPECTED_COMPLETION_MASK : 1; //!< [16] Unexpected Completion Mask
        unsigned RECEIVER_OVERFLOW_MASK : 1; //!< [17] Receiver Overflow Mask
        unsigned MALFORMED_TLP_MASK : 1; //!< [18] Malformed TLP Mask
        unsigned ECRC_ERROR_MASK : 1; //!< [19] ECRC Error Mask
        unsigned UNSUPPORTED_REQUEST_ERROR_MASK : 1; //!< [20] Unsupported Request Error Mask
        unsigned RESERVED2 : 11; //!< [31:21] Reserved
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

/* --- Register HW_PCIE_UEMR, field DATA_LINK_PROTOCOL_ERROR_MASK[4] (RW)
 *
 * Data Link Protocol Error Mask
 */

#define BP_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK      (4)      //!< Bit position for PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK.
#define BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK      (0x00000010)  //!< Bit mask for PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK.

//! @brief Get value of PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK from a register value.
#define BG_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK) >> BP_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK)

//! @brief Format value for bitfield PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK.
#define BF_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK) & BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_PROTOCOL_ERROR_MASK field to a new value.
#define BW_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK) | BF_PCIE_UEMR_DATA_LINK_PROTOCOL_ERROR_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field SURPRISE_DOWN_ERROR_MASK[5] (RW)
 *
 * Surprise Down Error Mask (not supported)
 */

#define BP_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK      (5)      //!< Bit position for PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK.
#define BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK      (0x00000020)  //!< Bit mask for PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK.

//! @brief Get value of PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK from a register value.
#define BG_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK) >> BP_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK)

//! @brief Format value for bitfield PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK.
#define BF_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK) & BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SURPRISE_DOWN_ERROR_MASK field to a new value.
#define BW_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK) | BF_PCIE_UEMR_SURPRISE_DOWN_ERROR_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field POISONED_TLP_MASK[12] (RW)
 *
 * Poisoned TLP Mask
 */

#define BP_PCIE_UEMR_POISONED_TLP_MASK      (12)      //!< Bit position for PCIE_UEMR_POISONED_TLP_MASK.
#define BM_PCIE_UEMR_POISONED_TLP_MASK      (0x00001000)  //!< Bit mask for PCIE_UEMR_POISONED_TLP_MASK.

//! @brief Get value of PCIE_UEMR_POISONED_TLP_MASK from a register value.
#define BG_PCIE_UEMR_POISONED_TLP_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_POISONED_TLP_MASK) >> BP_PCIE_UEMR_POISONED_TLP_MASK)

//! @brief Format value for bitfield PCIE_UEMR_POISONED_TLP_MASK.
#define BF_PCIE_UEMR_POISONED_TLP_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_POISONED_TLP_MASK) & BM_PCIE_UEMR_POISONED_TLP_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POISONED_TLP_MASK field to a new value.
#define BW_PCIE_UEMR_POISONED_TLP_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_POISONED_TLP_MASK) | BF_PCIE_UEMR_POISONED_TLP_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field FLOW_CONTROL_PROTOCOL_ERROR_MASK[13] (RW)
 *
 * Flow Control Protocol Error Mask
 */

#define BP_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK      (13)      //!< Bit position for PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK.
#define BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK      (0x00002000)  //!< Bit mask for PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK.

//! @brief Get value of PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK from a register value.
#define BG_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK) >> BP_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK)

//! @brief Format value for bitfield PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK.
#define BF_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK) & BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLOW_CONTROL_PROTOCOL_ERROR_MASK field to a new value.
#define BW_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK) | BF_PCIE_UEMR_FLOW_CONTROL_PROTOCOL_ERROR_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field COMPLETION_TIMEOUT_MASK[14] (RW)
 *
 * Completion Timeout Mask
 */

#define BP_PCIE_UEMR_COMPLETION_TIMEOUT_MASK      (14)      //!< Bit position for PCIE_UEMR_COMPLETION_TIMEOUT_MASK.
#define BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK      (0x00004000)  //!< Bit mask for PCIE_UEMR_COMPLETION_TIMEOUT_MASK.

//! @brief Get value of PCIE_UEMR_COMPLETION_TIMEOUT_MASK from a register value.
#define BG_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK) >> BP_PCIE_UEMR_COMPLETION_TIMEOUT_MASK)

//! @brief Format value for bitfield PCIE_UEMR_COMPLETION_TIMEOUT_MASK.
#define BF_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_COMPLETION_TIMEOUT_MASK) & BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETION_TIMEOUT_MASK field to a new value.
#define BW_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_COMPLETION_TIMEOUT_MASK) | BF_PCIE_UEMR_COMPLETION_TIMEOUT_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field COMPLETER_ABORT_MASK[15] (RW)
 *
 * Completer Abort Mask
 */

#define BP_PCIE_UEMR_COMPLETER_ABORT_MASK      (15)      //!< Bit position for PCIE_UEMR_COMPLETER_ABORT_MASK.
#define BM_PCIE_UEMR_COMPLETER_ABORT_MASK      (0x00008000)  //!< Bit mask for PCIE_UEMR_COMPLETER_ABORT_MASK.

//! @brief Get value of PCIE_UEMR_COMPLETER_ABORT_MASK from a register value.
#define BG_PCIE_UEMR_COMPLETER_ABORT_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_COMPLETER_ABORT_MASK) >> BP_PCIE_UEMR_COMPLETER_ABORT_MASK)

//! @brief Format value for bitfield PCIE_UEMR_COMPLETER_ABORT_MASK.
#define BF_PCIE_UEMR_COMPLETER_ABORT_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_COMPLETER_ABORT_MASK) & BM_PCIE_UEMR_COMPLETER_ABORT_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETER_ABORT_MASK field to a new value.
#define BW_PCIE_UEMR_COMPLETER_ABORT_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_COMPLETER_ABORT_MASK) | BF_PCIE_UEMR_COMPLETER_ABORT_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field UNEXPECTED_COMPLETION_MASK[16] (RW)
 *
 * Unexpected Completion Mask
 */

#define BP_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK      (16)      //!< Bit position for PCIE_UEMR_UNEXPECTED_COMPLETION_MASK.
#define BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK      (0x00010000)  //!< Bit mask for PCIE_UEMR_UNEXPECTED_COMPLETION_MASK.

//! @brief Get value of PCIE_UEMR_UNEXPECTED_COMPLETION_MASK from a register value.
#define BG_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK) >> BP_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK)

//! @brief Format value for bitfield PCIE_UEMR_UNEXPECTED_COMPLETION_MASK.
#define BF_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK) & BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNEXPECTED_COMPLETION_MASK field to a new value.
#define BW_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK) | BF_PCIE_UEMR_UNEXPECTED_COMPLETION_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field RECEIVER_OVERFLOW_MASK[17] (RW)
 *
 * Receiver Overflow Mask
 */

#define BP_PCIE_UEMR_RECEIVER_OVERFLOW_MASK      (17)      //!< Bit position for PCIE_UEMR_RECEIVER_OVERFLOW_MASK.
#define BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK      (0x00020000)  //!< Bit mask for PCIE_UEMR_RECEIVER_OVERFLOW_MASK.

//! @brief Get value of PCIE_UEMR_RECEIVER_OVERFLOW_MASK from a register value.
#define BG_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK) >> BP_PCIE_UEMR_RECEIVER_OVERFLOW_MASK)

//! @brief Format value for bitfield PCIE_UEMR_RECEIVER_OVERFLOW_MASK.
#define BF_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_RECEIVER_OVERFLOW_MASK) & BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVER_OVERFLOW_MASK field to a new value.
#define BW_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_RECEIVER_OVERFLOW_MASK) | BF_PCIE_UEMR_RECEIVER_OVERFLOW_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field MALFORMED_TLP_MASK[18] (RW)
 *
 * Malformed TLP Mask
 */

#define BP_PCIE_UEMR_MALFORMED_TLP_MASK      (18)      //!< Bit position for PCIE_UEMR_MALFORMED_TLP_MASK.
#define BM_PCIE_UEMR_MALFORMED_TLP_MASK      (0x00040000)  //!< Bit mask for PCIE_UEMR_MALFORMED_TLP_MASK.

//! @brief Get value of PCIE_UEMR_MALFORMED_TLP_MASK from a register value.
#define BG_PCIE_UEMR_MALFORMED_TLP_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_MALFORMED_TLP_MASK) >> BP_PCIE_UEMR_MALFORMED_TLP_MASK)

//! @brief Format value for bitfield PCIE_UEMR_MALFORMED_TLP_MASK.
#define BF_PCIE_UEMR_MALFORMED_TLP_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_MALFORMED_TLP_MASK) & BM_PCIE_UEMR_MALFORMED_TLP_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MALFORMED_TLP_MASK field to a new value.
#define BW_PCIE_UEMR_MALFORMED_TLP_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_MALFORMED_TLP_MASK) | BF_PCIE_UEMR_MALFORMED_TLP_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field ECRC_ERROR_MASK[19] (RW)
 *
 * ECRC Error Mask
 */

#define BP_PCIE_UEMR_ECRC_ERROR_MASK      (19)      //!< Bit position for PCIE_UEMR_ECRC_ERROR_MASK.
#define BM_PCIE_UEMR_ECRC_ERROR_MASK      (0x00080000)  //!< Bit mask for PCIE_UEMR_ECRC_ERROR_MASK.

//! @brief Get value of PCIE_UEMR_ECRC_ERROR_MASK from a register value.
#define BG_PCIE_UEMR_ECRC_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_ECRC_ERROR_MASK) >> BP_PCIE_UEMR_ECRC_ERROR_MASK)

//! @brief Format value for bitfield PCIE_UEMR_ECRC_ERROR_MASK.
#define BF_PCIE_UEMR_ECRC_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_ECRC_ERROR_MASK) & BM_PCIE_UEMR_ECRC_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_ERROR_MASK field to a new value.
#define BW_PCIE_UEMR_ECRC_ERROR_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_ECRC_ERROR_MASK) | BF_PCIE_UEMR_ECRC_ERROR_MASK(v)))
#endif

/* --- Register HW_PCIE_UEMR, field UNSUPPORTED_REQUEST_ERROR_MASK[20] (RW)
 *
 * Unsupported Request Error Mask
 */

#define BP_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK      (20)      //!< Bit position for PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK.
#define BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK      (0x00100000)  //!< Bit mask for PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK.

//! @brief Get value of PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK from a register value.
#define BG_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK) >> BP_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK)

//! @brief Format value for bitfield PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK.
#define BF_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK) & BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNSUPPORTED_REQUEST_ERROR_MASK field to a new value.
#define BW_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)   (HW_PCIE_UEMR_WR((HW_PCIE_UEMR_RD() & ~BM_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK) | BF_PCIE_UEMR_UNSUPPORTED_REQUEST_ERROR_MASK(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_UESEVR - Uncorrectable Error Severity Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_UESEVR - Uncorrectable Error Severity Register (RW)
 *
 * Reset value: 0x000c2031
 *
 * Offset: 0x0C
 */
typedef union _hw_pcie_uesevr
{
    reg32_t U;
    struct _hw_pcie_uesevr_bitfields
    {
        unsigned RESERVED0 : 4; //!< [3:0] Reserved.
        unsigned DATA_LINK_PROTOCOL_ERROR_SEVERITY : 1; //!< [4] Data Link Protocol Error Severity
        unsigned SURPRISE_DOWN_ERROR_SEVERITY : 1; //!< [5] Surprise Down Error Severity (not supported)
        unsigned RESERVED1 : 6; //!< [11:6] Reserved
        unsigned POISONED_TLP_SEVERITY : 1; //!< [12] Poisoned TLP Severity
        unsigned FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY : 1; //!< [13] Flow Control Protocol Error Severity
        unsigned COMPLETION_TIMEOUT_SEVERITY : 1; //!< [14] Completion Timeout Severity
        unsigned COMPLETER_ABORT_SEVERITY : 1; //!< [15] Completer Abort Severity
        unsigned UNEXPECTED_COMPLETION_SEVERITY : 1; //!< [16] Unexpected Completion Severity
        unsigned RECEIVER_OVERFLOW_SEVERITY : 1; //!< [17] Receiver Overflow Severity
        unsigned MALFORMED_TLP_SEVERITY : 1; //!< [18] Malformed TLP Severity
        unsigned ECRC_ERROR_SEVERITY : 1; //!< [19] ECRC Error Severity
        unsigned UNSUPPORTED_REQUEST_ERROR_SEVERITY : 1; //!< [20] Unsupported Request Error Severity
        unsigned RESERVED2 : 11; //!< [31:21] Reserved
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

/* --- Register HW_PCIE_UESEVR, field DATA_LINK_PROTOCOL_ERROR_SEVERITY[4] (RW)
 *
 * Data Link Protocol Error Severity
 */

#define BP_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY      (4)      //!< Bit position for PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY.
#define BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY      (0x00000010)  //!< Bit mask for PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY.

//! @brief Get value of PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY from a register value.
#define BG_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY) >> BP_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY.
#define BF_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY) & BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_LINK_PROTOCOL_ERROR_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY) | BF_PCIE_UESEVR_DATA_LINK_PROTOCOL_ERROR_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field SURPRISE_DOWN_ERROR_SEVERITY[5] (RW)
 *
 * Surprise Down Error Severity (not supported)
 */

#define BP_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY      (5)      //!< Bit position for PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY.
#define BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY      (0x00000020)  //!< Bit mask for PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY.

//! @brief Get value of PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY from a register value.
#define BG_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY) >> BP_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY.
#define BF_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY) & BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SURPRISE_DOWN_ERROR_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY) | BF_PCIE_UESEVR_SURPRISE_DOWN_ERROR_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field POISONED_TLP_SEVERITY[12] (RW)
 *
 * Poisoned TLP Severity
 */

#define BP_PCIE_UESEVR_POISONED_TLP_SEVERITY      (12)      //!< Bit position for PCIE_UESEVR_POISONED_TLP_SEVERITY.
#define BM_PCIE_UESEVR_POISONED_TLP_SEVERITY      (0x00001000)  //!< Bit mask for PCIE_UESEVR_POISONED_TLP_SEVERITY.

//! @brief Get value of PCIE_UESEVR_POISONED_TLP_SEVERITY from a register value.
#define BG_PCIE_UESEVR_POISONED_TLP_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_POISONED_TLP_SEVERITY) >> BP_PCIE_UESEVR_POISONED_TLP_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_POISONED_TLP_SEVERITY.
#define BF_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_POISONED_TLP_SEVERITY) & BM_PCIE_UESEVR_POISONED_TLP_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POISONED_TLP_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_POISONED_TLP_SEVERITY) | BF_PCIE_UESEVR_POISONED_TLP_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY[13] (RW)
 *
 * Flow Control Protocol Error Severity
 */

#define BP_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY      (13)      //!< Bit position for PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY.
#define BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY      (0x00002000)  //!< Bit mask for PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY.

//! @brief Get value of PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY from a register value.
#define BG_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY) >> BP_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY.
#define BF_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY) & BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY) | BF_PCIE_UESEVR_FLOW_CONTROL_PROTOCOL_ERROR_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field COMPLETION_TIMEOUT_SEVERITY[14] (RW)
 *
 * Completion Timeout Severity
 */

#define BP_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY      (14)      //!< Bit position for PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY.
#define BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY      (0x00004000)  //!< Bit mask for PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY.

//! @brief Get value of PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY from a register value.
#define BG_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY) >> BP_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY.
#define BF_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY) & BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETION_TIMEOUT_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY) | BF_PCIE_UESEVR_COMPLETION_TIMEOUT_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field COMPLETER_ABORT_SEVERITY[15] (RW)
 *
 * Completer Abort Severity
 */

#define BP_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY      (15)      //!< Bit position for PCIE_UESEVR_COMPLETER_ABORT_SEVERITY.
#define BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY      (0x00008000)  //!< Bit mask for PCIE_UESEVR_COMPLETER_ABORT_SEVERITY.

//! @brief Get value of PCIE_UESEVR_COMPLETER_ABORT_SEVERITY from a register value.
#define BG_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY) >> BP_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_COMPLETER_ABORT_SEVERITY.
#define BF_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY) & BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMPLETER_ABORT_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY) | BF_PCIE_UESEVR_COMPLETER_ABORT_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field UNEXPECTED_COMPLETION_SEVERITY[16] (RW)
 *
 * Unexpected Completion Severity
 */

#define BP_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY      (16)      //!< Bit position for PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY.
#define BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY      (0x00010000)  //!< Bit mask for PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY.

//! @brief Get value of PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY from a register value.
#define BG_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY) >> BP_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY.
#define BF_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY) & BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNEXPECTED_COMPLETION_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY) | BF_PCIE_UESEVR_UNEXPECTED_COMPLETION_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field RECEIVER_OVERFLOW_SEVERITY[17] (RW)
 *
 * Receiver Overflow Severity
 */

#define BP_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY      (17)      //!< Bit position for PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY.
#define BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY      (0x00020000)  //!< Bit mask for PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY.

//! @brief Get value of PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY from a register value.
#define BG_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY) >> BP_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY.
#define BF_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY) & BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVER_OVERFLOW_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY) | BF_PCIE_UESEVR_RECEIVER_OVERFLOW_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field MALFORMED_TLP_SEVERITY[18] (RW)
 *
 * Malformed TLP Severity
 */

#define BP_PCIE_UESEVR_MALFORMED_TLP_SEVERITY      (18)      //!< Bit position for PCIE_UESEVR_MALFORMED_TLP_SEVERITY.
#define BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY      (0x00040000)  //!< Bit mask for PCIE_UESEVR_MALFORMED_TLP_SEVERITY.

//! @brief Get value of PCIE_UESEVR_MALFORMED_TLP_SEVERITY from a register value.
#define BG_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY) >> BP_PCIE_UESEVR_MALFORMED_TLP_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_MALFORMED_TLP_SEVERITY.
#define BF_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_MALFORMED_TLP_SEVERITY) & BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MALFORMED_TLP_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_MALFORMED_TLP_SEVERITY) | BF_PCIE_UESEVR_MALFORMED_TLP_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field ECRC_ERROR_SEVERITY[19] (RW)
 *
 * ECRC Error Severity
 */

#define BP_PCIE_UESEVR_ECRC_ERROR_SEVERITY      (19)      //!< Bit position for PCIE_UESEVR_ECRC_ERROR_SEVERITY.
#define BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY      (0x00080000)  //!< Bit mask for PCIE_UESEVR_ECRC_ERROR_SEVERITY.

//! @brief Get value of PCIE_UESEVR_ECRC_ERROR_SEVERITY from a register value.
#define BG_PCIE_UESEVR_ECRC_ERROR_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY) >> BP_PCIE_UESEVR_ECRC_ERROR_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_ECRC_ERROR_SEVERITY.
#define BF_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_ECRC_ERROR_SEVERITY) & BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_ERROR_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_ECRC_ERROR_SEVERITY) | BF_PCIE_UESEVR_ECRC_ERROR_SEVERITY(v)))
#endif

/* --- Register HW_PCIE_UESEVR, field UNSUPPORTED_REQUEST_ERROR_SEVERITY[20] (RW)
 *
 * Unsupported Request Error Severity
 */

#define BP_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY      (20)      //!< Bit position for PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY.
#define BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY      (0x00100000)  //!< Bit mask for PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY.

//! @brief Get value of PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY from a register value.
#define BG_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY) >> BP_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY)

//! @brief Format value for bitfield PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY.
#define BF_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY) & BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNSUPPORTED_REQUEST_ERROR_SEVERITY field to a new value.
#define BW_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)   (HW_PCIE_UESEVR_WR((HW_PCIE_UESEVR_RD() & ~BM_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY) | BF_PCIE_UESEVR_UNSUPPORTED_REQUEST_ERROR_SEVERITY(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_CESR - Correctable Error Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_CESR - Correctable Error Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x10
 */
typedef union _hw_pcie_cesr
{
    reg32_t U;
    struct _hw_pcie_cesr_bitfields
    {
        unsigned RECEIVER_ERROR_STATUS : 1; //!< [0] Receiver Error Status
        unsigned RESERVED0 : 5; //!< [5:1] Reserved
        unsigned BAD_TLP_STATUS : 1; //!< [6] Bad TLP Status
        unsigned BAD_DLLP_STATUS : 1; //!< [7] Bad DLLP Status
        unsigned REPLAY_NUM_ROLLOVER_STATUS : 1; //!< [8] REPLAY_NUM Rollover Status
        unsigned RESERVED1 : 3; //!< [11:9] Reserved
        unsigned REPLY_TIMER_TIMEOUT_STATUS : 1; //!< [12] Reply Timer Timeout Status
        unsigned ADVISORY_NON_FATAL_ERROR_STATUS : 1; //!< [13] Advisory Non-Fatal Error Status
        unsigned RESERVED2 : 18; //!< [31:14] Reserved
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

/* --- Register HW_PCIE_CESR, field RECEIVER_ERROR_STATUS[0] (RW)
 *
 * Receiver Error Status
 */

#define BP_PCIE_CESR_RECEIVER_ERROR_STATUS      (0)      //!< Bit position for PCIE_CESR_RECEIVER_ERROR_STATUS.
#define BM_PCIE_CESR_RECEIVER_ERROR_STATUS      (0x00000001)  //!< Bit mask for PCIE_CESR_RECEIVER_ERROR_STATUS.

//! @brief Get value of PCIE_CESR_RECEIVER_ERROR_STATUS from a register value.
#define BG_PCIE_CESR_RECEIVER_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_RECEIVER_ERROR_STATUS) >> BP_PCIE_CESR_RECEIVER_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_CESR_RECEIVER_ERROR_STATUS.
#define BF_PCIE_CESR_RECEIVER_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_RECEIVER_ERROR_STATUS) & BM_PCIE_CESR_RECEIVER_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVER_ERROR_STATUS field to a new value.
#define BW_PCIE_CESR_RECEIVER_ERROR_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_RECEIVER_ERROR_STATUS) | BF_PCIE_CESR_RECEIVER_ERROR_STATUS(v)))
#endif

/* --- Register HW_PCIE_CESR, field BAD_TLP_STATUS[6] (RW)
 *
 * Bad TLP Status
 */

#define BP_PCIE_CESR_BAD_TLP_STATUS      (6)      //!< Bit position for PCIE_CESR_BAD_TLP_STATUS.
#define BM_PCIE_CESR_BAD_TLP_STATUS      (0x00000040)  //!< Bit mask for PCIE_CESR_BAD_TLP_STATUS.

//! @brief Get value of PCIE_CESR_BAD_TLP_STATUS from a register value.
#define BG_PCIE_CESR_BAD_TLP_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_BAD_TLP_STATUS) >> BP_PCIE_CESR_BAD_TLP_STATUS)

//! @brief Format value for bitfield PCIE_CESR_BAD_TLP_STATUS.
#define BF_PCIE_CESR_BAD_TLP_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_BAD_TLP_STATUS) & BM_PCIE_CESR_BAD_TLP_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BAD_TLP_STATUS field to a new value.
#define BW_PCIE_CESR_BAD_TLP_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_BAD_TLP_STATUS) | BF_PCIE_CESR_BAD_TLP_STATUS(v)))
#endif

/* --- Register HW_PCIE_CESR, field BAD_DLLP_STATUS[7] (RW)
 *
 * Bad DLLP Status
 */

#define BP_PCIE_CESR_BAD_DLLP_STATUS      (7)      //!< Bit position for PCIE_CESR_BAD_DLLP_STATUS.
#define BM_PCIE_CESR_BAD_DLLP_STATUS      (0x00000080)  //!< Bit mask for PCIE_CESR_BAD_DLLP_STATUS.

//! @brief Get value of PCIE_CESR_BAD_DLLP_STATUS from a register value.
#define BG_PCIE_CESR_BAD_DLLP_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_BAD_DLLP_STATUS) >> BP_PCIE_CESR_BAD_DLLP_STATUS)

//! @brief Format value for bitfield PCIE_CESR_BAD_DLLP_STATUS.
#define BF_PCIE_CESR_BAD_DLLP_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_BAD_DLLP_STATUS) & BM_PCIE_CESR_BAD_DLLP_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BAD_DLLP_STATUS field to a new value.
#define BW_PCIE_CESR_BAD_DLLP_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_BAD_DLLP_STATUS) | BF_PCIE_CESR_BAD_DLLP_STATUS(v)))
#endif

/* --- Register HW_PCIE_CESR, field REPLAY_NUM_ROLLOVER_STATUS[8] (RW)
 *
 * REPLAY_NUM Rollover Status
 */

#define BP_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS      (8)      //!< Bit position for PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS.
#define BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS      (0x00000100)  //!< Bit mask for PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS.

//! @brief Get value of PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS from a register value.
#define BG_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS) >> BP_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS)

//! @brief Format value for bitfield PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS.
#define BF_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS) & BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the REPLAY_NUM_ROLLOVER_STATUS field to a new value.
#define BW_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS) | BF_PCIE_CESR_REPLAY_NUM_ROLLOVER_STATUS(v)))
#endif

/* --- Register HW_PCIE_CESR, field REPLY_TIMER_TIMEOUT_STATUS[12] (RW)
 *
 * Reply Timer Timeout Status
 */

#define BP_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS      (12)      //!< Bit position for PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS.
#define BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS      (0x00001000)  //!< Bit mask for PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS.

//! @brief Get value of PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS from a register value.
#define BG_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS) >> BP_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS)

//! @brief Format value for bitfield PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS.
#define BF_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS) & BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the REPLY_TIMER_TIMEOUT_STATUS field to a new value.
#define BW_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS) | BF_PCIE_CESR_REPLY_TIMER_TIMEOUT_STATUS(v)))
#endif

/* --- Register HW_PCIE_CESR, field ADVISORY_NON_FATAL_ERROR_STATUS[13] (RW)
 *
 * Advisory Non-Fatal Error Status
 */

#define BP_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS      (13)      //!< Bit position for PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS.
#define BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS      (0x00002000)  //!< Bit mask for PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS.

//! @brief Get value of PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS from a register value.
#define BG_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS) >> BP_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS)

//! @brief Format value for bitfield PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS.
#define BF_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS) & BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADVISORY_NON_FATAL_ERROR_STATUS field to a new value.
#define BW_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)   (HW_PCIE_CESR_WR((HW_PCIE_CESR_RD() & ~BM_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS) | BF_PCIE_CESR_ADVISORY_NON_FATAL_ERROR_STATUS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_CEMR - Correctable Error Mask Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_CEMR - Correctable Error Mask Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x14
 */
typedef union _hw_pcie_cemr
{
    reg32_t U;
    struct _hw_pcie_cemr_bitfields
    {
        unsigned RECEIVER_ERROR_MASK : 1; //!< [0] Receiver Error Mask
        unsigned RESERVED0 : 5; //!< [5:1] Reserved
        unsigned BAD_TLP_MASK : 1; //!< [6] Bad TLP Mask
        unsigned BAD_DLLP_MASK : 1; //!< [7] Bad DLLP Mask
        unsigned REPLAY_NUM_ROLLOVER_MASK : 1; //!< [8] REPLAY_NUM Rollover Mask
        unsigned RESERVED1 : 3; //!< [11:9] Reserved
        unsigned REPLY_TIMER_TIMEOUT_MASK : 1; //!< [12] Reply Timer Timeout Mask
        unsigned ADVISORY_NON_FATAL_ERROR_MASK : 1; //!< [13] Advisory Non-Fatal Error Mask
        unsigned RESERVED2 : 18; //!< [31:14] Reserved
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

/* --- Register HW_PCIE_CEMR, field RECEIVER_ERROR_MASK[0] (RW)
 *
 * Receiver Error Mask
 */

#define BP_PCIE_CEMR_RECEIVER_ERROR_MASK      (0)      //!< Bit position for PCIE_CEMR_RECEIVER_ERROR_MASK.
#define BM_PCIE_CEMR_RECEIVER_ERROR_MASK      (0x00000001)  //!< Bit mask for PCIE_CEMR_RECEIVER_ERROR_MASK.

//! @brief Get value of PCIE_CEMR_RECEIVER_ERROR_MASK from a register value.
#define BG_PCIE_CEMR_RECEIVER_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_RECEIVER_ERROR_MASK) >> BP_PCIE_CEMR_RECEIVER_ERROR_MASK)

//! @brief Format value for bitfield PCIE_CEMR_RECEIVER_ERROR_MASK.
#define BF_PCIE_CEMR_RECEIVER_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_RECEIVER_ERROR_MASK) & BM_PCIE_CEMR_RECEIVER_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECEIVER_ERROR_MASK field to a new value.
#define BW_PCIE_CEMR_RECEIVER_ERROR_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_RECEIVER_ERROR_MASK) | BF_PCIE_CEMR_RECEIVER_ERROR_MASK(v)))
#endif

/* --- Register HW_PCIE_CEMR, field BAD_TLP_MASK[6] (RW)
 *
 * Bad TLP Mask
 */

#define BP_PCIE_CEMR_BAD_TLP_MASK      (6)      //!< Bit position for PCIE_CEMR_BAD_TLP_MASK.
#define BM_PCIE_CEMR_BAD_TLP_MASK      (0x00000040)  //!< Bit mask for PCIE_CEMR_BAD_TLP_MASK.

//! @brief Get value of PCIE_CEMR_BAD_TLP_MASK from a register value.
#define BG_PCIE_CEMR_BAD_TLP_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_BAD_TLP_MASK) >> BP_PCIE_CEMR_BAD_TLP_MASK)

//! @brief Format value for bitfield PCIE_CEMR_BAD_TLP_MASK.
#define BF_PCIE_CEMR_BAD_TLP_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_BAD_TLP_MASK) & BM_PCIE_CEMR_BAD_TLP_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BAD_TLP_MASK field to a new value.
#define BW_PCIE_CEMR_BAD_TLP_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_BAD_TLP_MASK) | BF_PCIE_CEMR_BAD_TLP_MASK(v)))
#endif

/* --- Register HW_PCIE_CEMR, field BAD_DLLP_MASK[7] (RW)
 *
 * Bad DLLP Mask
 */

#define BP_PCIE_CEMR_BAD_DLLP_MASK      (7)      //!< Bit position for PCIE_CEMR_BAD_DLLP_MASK.
#define BM_PCIE_CEMR_BAD_DLLP_MASK      (0x00000080)  //!< Bit mask for PCIE_CEMR_BAD_DLLP_MASK.

//! @brief Get value of PCIE_CEMR_BAD_DLLP_MASK from a register value.
#define BG_PCIE_CEMR_BAD_DLLP_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_BAD_DLLP_MASK) >> BP_PCIE_CEMR_BAD_DLLP_MASK)

//! @brief Format value for bitfield PCIE_CEMR_BAD_DLLP_MASK.
#define BF_PCIE_CEMR_BAD_DLLP_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_BAD_DLLP_MASK) & BM_PCIE_CEMR_BAD_DLLP_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BAD_DLLP_MASK field to a new value.
#define BW_PCIE_CEMR_BAD_DLLP_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_BAD_DLLP_MASK) | BF_PCIE_CEMR_BAD_DLLP_MASK(v)))
#endif

/* --- Register HW_PCIE_CEMR, field REPLAY_NUM_ROLLOVER_MASK[8] (RW)
 *
 * REPLAY_NUM Rollover Mask
 */

#define BP_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK      (8)      //!< Bit position for PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK.
#define BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK      (0x00000100)  //!< Bit mask for PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK.

//! @brief Get value of PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK from a register value.
#define BG_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK) >> BP_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK)

//! @brief Format value for bitfield PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK.
#define BF_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK) & BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the REPLAY_NUM_ROLLOVER_MASK field to a new value.
#define BW_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK) | BF_PCIE_CEMR_REPLAY_NUM_ROLLOVER_MASK(v)))
#endif

/* --- Register HW_PCIE_CEMR, field REPLY_TIMER_TIMEOUT_MASK[12] (RW)
 *
 * Reply Timer Timeout Mask
 */

#define BP_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK      (12)      //!< Bit position for PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK.
#define BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK      (0x00001000)  //!< Bit mask for PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK.

//! @brief Get value of PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK from a register value.
#define BG_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK) >> BP_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK)

//! @brief Format value for bitfield PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK.
#define BF_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK) & BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the REPLY_TIMER_TIMEOUT_MASK field to a new value.
#define BW_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK) | BF_PCIE_CEMR_REPLY_TIMER_TIMEOUT_MASK(v)))
#endif

/* --- Register HW_PCIE_CEMR, field ADVISORY_NON_FATAL_ERROR_MASK[13] (RW)
 *
 * Advisory Non-Fatal Error Mask
 */

#define BP_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK      (13)      //!< Bit position for PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK.
#define BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK      (0x00002000)  //!< Bit mask for PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK.

//! @brief Get value of PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK from a register value.
#define BG_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK) >> BP_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK)

//! @brief Format value for bitfield PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK.
#define BF_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK) & BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADVISORY_NON_FATAL_ERROR_MASK field to a new value.
#define BW_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)   (HW_PCIE_CEMR_WR((HW_PCIE_CEMR_RD() & ~BM_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK) | BF_PCIE_CEMR_ADVISORY_NON_FATAL_ERROR_MASK(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_ACCR - Advanced Capabilities and Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_ACCR - Advanced Capabilities and Control Register (RW)
 *
 * Reset value: 0x000000a0
 *
 * Offset: 0x18
 */
typedef union _hw_pcie_accr
{
    reg32_t U;
    struct _hw_pcie_accr_bitfields
    {
        unsigned FIRST_ERROR_POINTER : 5; //!< [4:0] First Error Pointer
        unsigned ECRC_GENERATION_CAPABILITY : 1; //!< [5] ECRC Generation Capability
        unsigned ECRC_GENERATION_ENABLE : 1; //!< [6] ECRC Generation Enable
        unsigned ECRC_CHECK_CAPABLE : 1; //!< [7] ECRC Check Capable
        unsigned ECRC_CHECK_ENABLE : 1; //!< [8] ECRC Check Enable
        unsigned RESERVED0 : 23; //!< [31:9] Reserved
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

/* --- Register HW_PCIE_ACCR, field FIRST_ERROR_POINTER[4:0] (RW)
 *
 * First Error Pointer
 */

#define BP_PCIE_ACCR_FIRST_ERROR_POINTER      (0)      //!< Bit position for PCIE_ACCR_FIRST_ERROR_POINTER.
#define BM_PCIE_ACCR_FIRST_ERROR_POINTER      (0x0000001f)  //!< Bit mask for PCIE_ACCR_FIRST_ERROR_POINTER.

//! @brief Get value of PCIE_ACCR_FIRST_ERROR_POINTER from a register value.
#define BG_PCIE_ACCR_FIRST_ERROR_POINTER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ACCR_FIRST_ERROR_POINTER) >> BP_PCIE_ACCR_FIRST_ERROR_POINTER)

//! @brief Format value for bitfield PCIE_ACCR_FIRST_ERROR_POINTER.
#define BF_PCIE_ACCR_FIRST_ERROR_POINTER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ACCR_FIRST_ERROR_POINTER) & BM_PCIE_ACCR_FIRST_ERROR_POINTER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIRST_ERROR_POINTER field to a new value.
#define BW_PCIE_ACCR_FIRST_ERROR_POINTER(v)   (HW_PCIE_ACCR_WR((HW_PCIE_ACCR_RD() & ~BM_PCIE_ACCR_FIRST_ERROR_POINTER) | BF_PCIE_ACCR_FIRST_ERROR_POINTER(v)))
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_GENERATION_CAPABILITY[5] (RW)
 *
 * ECRC Generation Capability
 */

#define BP_PCIE_ACCR_ECRC_GENERATION_CAPABILITY      (5)      //!< Bit position for PCIE_ACCR_ECRC_GENERATION_CAPABILITY.
#define BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY      (0x00000020)  //!< Bit mask for PCIE_ACCR_ECRC_GENERATION_CAPABILITY.

//! @brief Get value of PCIE_ACCR_ECRC_GENERATION_CAPABILITY from a register value.
#define BG_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY) >> BP_PCIE_ACCR_ECRC_GENERATION_CAPABILITY)

//! @brief Format value for bitfield PCIE_ACCR_ECRC_GENERATION_CAPABILITY.
#define BF_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ACCR_ECRC_GENERATION_CAPABILITY) & BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_GENERATION_CAPABILITY field to a new value.
#define BW_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)   (HW_PCIE_ACCR_WR((HW_PCIE_ACCR_RD() & ~BM_PCIE_ACCR_ECRC_GENERATION_CAPABILITY) | BF_PCIE_ACCR_ECRC_GENERATION_CAPABILITY(v)))
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_GENERATION_ENABLE[6] (RW)
 *
 * ECRC Generation Enable
 */

#define BP_PCIE_ACCR_ECRC_GENERATION_ENABLE      (6)      //!< Bit position for PCIE_ACCR_ECRC_GENERATION_ENABLE.
#define BM_PCIE_ACCR_ECRC_GENERATION_ENABLE      (0x00000040)  //!< Bit mask for PCIE_ACCR_ECRC_GENERATION_ENABLE.

//! @brief Get value of PCIE_ACCR_ECRC_GENERATION_ENABLE from a register value.
#define BG_PCIE_ACCR_ECRC_GENERATION_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ACCR_ECRC_GENERATION_ENABLE) >> BP_PCIE_ACCR_ECRC_GENERATION_ENABLE)

//! @brief Format value for bitfield PCIE_ACCR_ECRC_GENERATION_ENABLE.
#define BF_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ACCR_ECRC_GENERATION_ENABLE) & BM_PCIE_ACCR_ECRC_GENERATION_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_GENERATION_ENABLE field to a new value.
#define BW_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)   (HW_PCIE_ACCR_WR((HW_PCIE_ACCR_RD() & ~BM_PCIE_ACCR_ECRC_GENERATION_ENABLE) | BF_PCIE_ACCR_ECRC_GENERATION_ENABLE(v)))
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_CHECK_CAPABLE[7] (RW)
 *
 * ECRC Check Capable
 */

#define BP_PCIE_ACCR_ECRC_CHECK_CAPABLE      (7)      //!< Bit position for PCIE_ACCR_ECRC_CHECK_CAPABLE.
#define BM_PCIE_ACCR_ECRC_CHECK_CAPABLE      (0x00000080)  //!< Bit mask for PCIE_ACCR_ECRC_CHECK_CAPABLE.

//! @brief Get value of PCIE_ACCR_ECRC_CHECK_CAPABLE from a register value.
#define BG_PCIE_ACCR_ECRC_CHECK_CAPABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ACCR_ECRC_CHECK_CAPABLE) >> BP_PCIE_ACCR_ECRC_CHECK_CAPABLE)

//! @brief Format value for bitfield PCIE_ACCR_ECRC_CHECK_CAPABLE.
#define BF_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ACCR_ECRC_CHECK_CAPABLE) & BM_PCIE_ACCR_ECRC_CHECK_CAPABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_CHECK_CAPABLE field to a new value.
#define BW_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)   (HW_PCIE_ACCR_WR((HW_PCIE_ACCR_RD() & ~BM_PCIE_ACCR_ECRC_CHECK_CAPABLE) | BF_PCIE_ACCR_ECRC_CHECK_CAPABLE(v)))
#endif

/* --- Register HW_PCIE_ACCR, field ECRC_CHECK_ENABLE[8] (RW)
 *
 * ECRC Check Enable
 */

#define BP_PCIE_ACCR_ECRC_CHECK_ENABLE      (8)      //!< Bit position for PCIE_ACCR_ECRC_CHECK_ENABLE.
#define BM_PCIE_ACCR_ECRC_CHECK_ENABLE      (0x00000100)  //!< Bit mask for PCIE_ACCR_ECRC_CHECK_ENABLE.

//! @brief Get value of PCIE_ACCR_ECRC_CHECK_ENABLE from a register value.
#define BG_PCIE_ACCR_ECRC_CHECK_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ACCR_ECRC_CHECK_ENABLE) >> BP_PCIE_ACCR_ECRC_CHECK_ENABLE)

//! @brief Format value for bitfield PCIE_ACCR_ECRC_CHECK_ENABLE.
#define BF_PCIE_ACCR_ECRC_CHECK_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_ACCR_ECRC_CHECK_ENABLE) & BM_PCIE_ACCR_ECRC_CHECK_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECRC_CHECK_ENABLE field to a new value.
#define BW_PCIE_ACCR_ECRC_CHECK_ENABLE(v)   (HW_PCIE_ACCR_WR((HW_PCIE_ACCR_RD() & ~BM_PCIE_ACCR_ECRC_CHECK_ENABLE) | BF_PCIE_ACCR_ECRC_CHECK_ENABLE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_HLR - Header Log Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_HLR - Header Log Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x1C  The Header Log registers collect the header for the TLP corresponding to a detected
 * error. See the PCI Express 3.0 Specification for details. Each of the Header Log registers is
 * type ROS; the default reset value of each Header Log register is 0x00000000.
 */
typedef union _hw_pcie_hlr
{
    reg32_t U;
    struct _hw_pcie_hlr_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Header Log Register (nth DWORD)
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
#endif

/*
 * constants & macros for individual PCIE_HLR bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_PCIE_RECR - Root Error Command Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_RECR - Root Error Command Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x100 + 0x2C
 */
typedef union _hw_pcie_recr
{
    reg32_t U;
    struct _hw_pcie_recr_bitfields
    {
        unsigned CORRECTABLE_ERROR_REPORTING_ENABLE : 1; //!< [0] Correctable Error Reporting Enable
        unsigned NON_FATAL_ERROR_REPORTING_ENABLE : 1; //!< [1] Non-Fatal Error Reporting Enable
        unsigned FATAL_ERROR_REPORTING_ENABLE : 1; //!< [2] Fatal Error Reporting Enable
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
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

/* --- Register HW_PCIE_RECR, field CORRECTABLE_ERROR_REPORTING_ENABLE[0] (RW)
 *
 * Correctable Error Reporting Enable
 */

#define BP_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE      (0)      //!< Bit position for PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE.
#define BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE      (0x00000001)  //!< Bit mask for PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE) >> BP_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE.
#define BF_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE) & BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORRECTABLE_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_RECR_WR((HW_PCIE_RECR_RD() & ~BM_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE) | BF_PCIE_RECR_CORRECTABLE_ERROR_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RECR, field NON_FATAL_ERROR_REPORTING_ENABLE[1] (RW)
 *
 * Non-Fatal Error Reporting Enable
 */

#define BP_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE      (1)      //!< Bit position for PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE.
#define BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE      (0x00000002)  //!< Bit mask for PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE) >> BP_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE.
#define BF_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE) & BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NON_FATAL_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_RECR_WR((HW_PCIE_RECR_RD() & ~BM_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE) | BF_PCIE_RECR_NON_FATAL_ERROR_REPORTING_ENABLE(v)))
#endif

/* --- Register HW_PCIE_RECR, field FATAL_ERROR_REPORTING_ENABLE[2] (RW)
 *
 * Fatal Error Reporting Enable
 */

#define BP_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE      (2)      //!< Bit position for PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE.
#define BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE      (0x00000004)  //!< Bit mask for PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE.

//! @brief Get value of PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE from a register value.
#define BG_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE) >> BP_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE)

//! @brief Format value for bitfield PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE.
#define BF_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE) & BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FATAL_ERROR_REPORTING_ENABLE field to a new value.
#define BW_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)   (HW_PCIE_RECR_WR((HW_PCIE_RECR_RD() & ~BM_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE) | BF_PCIE_RECR_FATAL_ERROR_REPORTING_ENABLE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_RESR - Root Error Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_RESR - Root Error Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x100 + 0x30
 */
typedef union _hw_pcie_resr
{
    reg32_t U;
    struct _hw_pcie_resr_bitfields
    {
        unsigned ERR_COR_RECEIVED : 1; //!< [0] ERR_COR Received
        unsigned MULTIPLE_ERR_COR_RECEIVED : 1; //!< [1] Multiple ERR_COR Received
        unsigned ERR_FATAL_NONFATAL_RECEIVED : 1; //!< [2] ERR_FATAL/NONFATAL Received
        unsigned MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED : 1; //!< [3] Multiple ERR_FATAL/NONFATAL Received
        unsigned FIRST_UNCORRECTABLE_FATAL : 1; //!< [4] First Uncorrectable Fatal
        unsigned NON_FATAL_ERROR_MESSAGES_RECEIVED : 1; //!< [5] Non-Fatal Error Messages Received
        unsigned FATAL_ERROR_MESSAGES_RECEIVED : 1; //!< [6] Fatal Error Messages Received
        unsigned RESERVED0 : 20; //!< [26:7] Reserved
        unsigned ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER : 5; //!< [31:27] Advanced Error Interrupt Message Number, writable through the DBI
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

/* --- Register HW_PCIE_RESR, field ERR_COR_RECEIVED[0] (RW)
 *
 * ERR_COR Received
 */

#define BP_PCIE_RESR_ERR_COR_RECEIVED      (0)      //!< Bit position for PCIE_RESR_ERR_COR_RECEIVED.
#define BM_PCIE_RESR_ERR_COR_RECEIVED      (0x00000001)  //!< Bit mask for PCIE_RESR_ERR_COR_RECEIVED.

//! @brief Get value of PCIE_RESR_ERR_COR_RECEIVED from a register value.
#define BG_PCIE_RESR_ERR_COR_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_ERR_COR_RECEIVED) >> BP_PCIE_RESR_ERR_COR_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_ERR_COR_RECEIVED.
#define BF_PCIE_RESR_ERR_COR_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_ERR_COR_RECEIVED) & BM_PCIE_RESR_ERR_COR_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_COR_RECEIVED field to a new value.
#define BW_PCIE_RESR_ERR_COR_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_ERR_COR_RECEIVED) | BF_PCIE_RESR_ERR_COR_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field MULTIPLE_ERR_COR_RECEIVED[1] (RW)
 *
 * Multiple ERR_COR Received
 */

#define BP_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED      (1)      //!< Bit position for PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED.
#define BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED      (0x00000002)  //!< Bit mask for PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED.

//! @brief Get value of PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED from a register value.
#define BG_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED) >> BP_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED.
#define BF_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED) & BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MULTIPLE_ERR_COR_RECEIVED field to a new value.
#define BW_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED) | BF_PCIE_RESR_MULTIPLE_ERR_COR_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field ERR_FATAL_NONFATAL_RECEIVED[2] (RW)
 *
 * ERR_FATAL/NONFATAL Received
 */

#define BP_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED      (2)      //!< Bit position for PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED.
#define BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED      (0x00000004)  //!< Bit mask for PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED.

//! @brief Get value of PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED from a register value.
#define BG_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED) >> BP_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED.
#define BF_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED) & BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_FATAL_NONFATAL_RECEIVED field to a new value.
#define BW_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED) | BF_PCIE_RESR_ERR_FATAL_NONFATAL_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED[3] (RW)
 *
 * Multiple ERR_FATAL/NONFATAL Received
 */

#define BP_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED      (3)      //!< Bit position for PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED.
#define BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED      (0x00000008)  //!< Bit mask for PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED.

//! @brief Get value of PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED from a register value.
#define BG_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED) >> BP_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED.
#define BF_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED) & BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED field to a new value.
#define BW_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED) | BF_PCIE_RESR_MULTIPLE_ERR_FATAL_NONFATAL_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field FIRST_UNCORRECTABLE_FATAL[4] (RW)
 *
 * First Uncorrectable Fatal
 */

#define BP_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL      (4)      //!< Bit position for PCIE_RESR_FIRST_UNCORRECTABLE_FATAL.
#define BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL      (0x00000010)  //!< Bit mask for PCIE_RESR_FIRST_UNCORRECTABLE_FATAL.

//! @brief Get value of PCIE_RESR_FIRST_UNCORRECTABLE_FATAL from a register value.
#define BG_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL) >> BP_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL)

//! @brief Format value for bitfield PCIE_RESR_FIRST_UNCORRECTABLE_FATAL.
#define BF_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL) & BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIRST_UNCORRECTABLE_FATAL field to a new value.
#define BW_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL) | BF_PCIE_RESR_FIRST_UNCORRECTABLE_FATAL(v)))
#endif

/* --- Register HW_PCIE_RESR, field NON_FATAL_ERROR_MESSAGES_RECEIVED[5] (RW)
 *
 * Non-Fatal Error Messages Received
 */

#define BP_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED      (5)      //!< Bit position for PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED.
#define BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED      (0x00000020)  //!< Bit mask for PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED.

//! @brief Get value of PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED from a register value.
#define BG_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED) >> BP_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED.
#define BF_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED) & BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NON_FATAL_ERROR_MESSAGES_RECEIVED field to a new value.
#define BW_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED) | BF_PCIE_RESR_NON_FATAL_ERROR_MESSAGES_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field FATAL_ERROR_MESSAGES_RECEIVED[6] (RW)
 *
 * Fatal Error Messages Received
 */

#define BP_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED      (6)      //!< Bit position for PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED.
#define BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED      (0x00000040)  //!< Bit mask for PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED.

//! @brief Get value of PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED from a register value.
#define BG_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED) >> BP_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED)

//! @brief Format value for bitfield PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED.
#define BF_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED) & BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FATAL_ERROR_MESSAGES_RECEIVED field to a new value.
#define BW_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED) | BF_PCIE_RESR_FATAL_ERROR_MESSAGES_RECEIVED(v)))
#endif

/* --- Register HW_PCIE_RESR, field ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER[31:27] (RW)
 *
 * Advanced Error Interrupt Message Number, writable through the DBI
 */

#define BP_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER      (27)      //!< Bit position for PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER.
#define BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER      (0xf8000000)  //!< Bit mask for PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER.

//! @brief Get value of PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER from a register value.
#define BG_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER) >> BP_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER)

//! @brief Format value for bitfield PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER.
#define BF_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER) & BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER field to a new value.
#define BW_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)   (HW_PCIE_RESR_WR((HW_PCIE_RESR_RD() & ~BM_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER) | BF_PCIE_RESR_ADVANCED_ERROR_INTERRUPT_MESSAGE_NUMBER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_ESIR - Error Source Identification Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_ESIR - Error Source Identification Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x100 + 0x34
 */
typedef union _hw_pcie_esir
{
    reg32_t U;
    struct _hw_pcie_esir_bitfields
    {
        unsigned ERR_COR_SID : 16; //!< [15:0] ERR_COR Source Identification
        unsigned ERR_FATAL_NONFATAL_SID : 16; //!< [31:16] ERR_FATAL/NONFATAL Source Identification
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
#endif

/*
 * constants & macros for individual PCIE_ESIR bitfields
 */

/* --- Register HW_PCIE_ESIR, field ERR_COR_SID[15:0] (RO)
 *
 * ERR_COR Source Identification
 */

#define BP_PCIE_ESIR_ERR_COR_SID      (0)      //!< Bit position for PCIE_ESIR_ERR_COR_SID.
#define BM_PCIE_ESIR_ERR_COR_SID      (0x0000ffff)  //!< Bit mask for PCIE_ESIR_ERR_COR_SID.

//! @brief Get value of PCIE_ESIR_ERR_COR_SID from a register value.
#define BG_PCIE_ESIR_ERR_COR_SID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ESIR_ERR_COR_SID) >> BP_PCIE_ESIR_ERR_COR_SID)

/* --- Register HW_PCIE_ESIR, field ERR_FATAL_NONFATAL_SID[31:16] (RO)
 *
 * ERR_FATAL/NONFATAL Source Identification
 */

#define BP_PCIE_ESIR_ERR_FATAL_NONFATAL_SID      (16)      //!< Bit position for PCIE_ESIR_ERR_FATAL_NONFATAL_SID.
#define BM_PCIE_ESIR_ERR_FATAL_NONFATAL_SID      (0xffff0000)  //!< Bit mask for PCIE_ESIR_ERR_FATAL_NONFATAL_SID.

//! @brief Get value of PCIE_ESIR_ERR_FATAL_NONFATAL_SID from a register value.
#define BG_PCIE_ESIR_ERR_FATAL_NONFATAL_SID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_ESIR_ERR_FATAL_NONFATAL_SID) >> BP_PCIE_ESIR_ERR_FATAL_NONFATAL_SID)

//-------------------------------------------------------------------------------------------
// HW_PCIE_VCECHR - VC Extended Capability Header
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_VCECHR - VC Extended Capability Header (RO)
 *
 * Reset value: 0x00000012
 *
 * Offset: 0x140
 */
typedef union _hw_pcie_vcechr
{
    reg32_t U;
    struct _hw_pcie_vcechr_bitfields
    {
        unsigned EXTENDED_CAPABILITY : 16; //!< [15:0] PCI Express Extended Capability The default value is 0x2 for VC Capability.
        unsigned CAPABILITY_VERSION : 4; //!< [19:16] Capability Version
        unsigned NEXT_CAPABILITY_OFFSET : 12; //!< [31:20] Next Capability Offset See Table 5-222 on page 641.
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
#endif

/*
 * constants & macros for individual PCIE_VCECHR bitfields
 */

/* --- Register HW_PCIE_VCECHR, field EXTENDED_CAPABILITY[15:0] (RO)
 *
 * PCI Express Extended Capability The default value is 0x2 for VC Capability.
 */

#define BP_PCIE_VCECHR_EXTENDED_CAPABILITY      (0)      //!< Bit position for PCIE_VCECHR_EXTENDED_CAPABILITY.
#define BM_PCIE_VCECHR_EXTENDED_CAPABILITY      (0x0000ffff)  //!< Bit mask for PCIE_VCECHR_EXTENDED_CAPABILITY.

//! @brief Get value of PCIE_VCECHR_EXTENDED_CAPABILITY from a register value.
#define BG_PCIE_VCECHR_EXTENDED_CAPABILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCECHR_EXTENDED_CAPABILITY) >> BP_PCIE_VCECHR_EXTENDED_CAPABILITY)

/* --- Register HW_PCIE_VCECHR, field CAPABILITY_VERSION[19:16] (RO)
 *
 * Capability Version
 */

#define BP_PCIE_VCECHR_CAPABILITY_VERSION      (16)      //!< Bit position for PCIE_VCECHR_CAPABILITY_VERSION.
#define BM_PCIE_VCECHR_CAPABILITY_VERSION      (0x000f0000)  //!< Bit mask for PCIE_VCECHR_CAPABILITY_VERSION.

//! @brief Get value of PCIE_VCECHR_CAPABILITY_VERSION from a register value.
#define BG_PCIE_VCECHR_CAPABILITY_VERSION(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCECHR_CAPABILITY_VERSION) >> BP_PCIE_VCECHR_CAPABILITY_VERSION)

/* --- Register HW_PCIE_VCECHR, field NEXT_CAPABILITY_OFFSET[31:20] (RO)
 *
 * Next Capability Offset See Table 5-222 on page 641.
 */

#define BP_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET      (20)      //!< Bit position for PCIE_VCECHR_NEXT_CAPABILITY_OFFSET.
#define BM_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET      (0xfff00000)  //!< Bit mask for PCIE_VCECHR_NEXT_CAPABILITY_OFFSET.

//! @brief Get value of PCIE_VCECHR_NEXT_CAPABILITY_OFFSET from a register value.
#define BG_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET) >> BP_PCIE_VCECHR_NEXT_CAPABILITY_OFFSET)

//-------------------------------------------------------------------------------------------
// HW_PCIE_PVCCR1 - Port VC Capability Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PVCCR1 - Port VC Capability Register 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0x4
 */
typedef union _hw_pcie_pvccr1
{
    reg32_t U;
    struct _hw_pcie_pvccr1_bitfields
    {
        unsigned EXTENDED_VC_COUNT : 3; //!< [2:0] Extended VC Count The default value is the one less than the number of VCs that
        unsigned RESERVED0 : 1; //!< [3] Reserved
        unsigned LOW_PRIORITY_EXTENDED_VC_COUNT : 3; //!< [6:4] Low Priority Extended VC Count, writable through the DBI
        unsigned RESERVED1 : 1; //!< [7] Reserved
        unsigned REFERENCE_CLOCK : 2; //!< [9:8] Reference Clock
        unsigned PORT_ARBITRATION_TABLE_ENTRY_SIZE : 2; //!< [11:10] Port Arbitration Table Entry Size
        unsigned RESERVED2 : 20; //!< [31:12] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_PVCCR1 bitfields
 */

/* --- Register HW_PCIE_PVCCR1, field EXTENDED_VC_COUNT[2:0] (RO)
 *
 * Extended VC Count The default value is the one less than the number of VCs that
 */

#define BP_PCIE_PVCCR1_EXTENDED_VC_COUNT      (0)      //!< Bit position for PCIE_PVCCR1_EXTENDED_VC_COUNT.
#define BM_PCIE_PVCCR1_EXTENDED_VC_COUNT      (0x00000007)  //!< Bit mask for PCIE_PVCCR1_EXTENDED_VC_COUNT.

//! @brief Get value of PCIE_PVCCR1_EXTENDED_VC_COUNT from a register value.
#define BG_PCIE_PVCCR1_EXTENDED_VC_COUNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR1_EXTENDED_VC_COUNT) >> BP_PCIE_PVCCR1_EXTENDED_VC_COUNT)

/* --- Register HW_PCIE_PVCCR1, field LOW_PRIORITY_EXTENDED_VC_COUNT[6:4] (RO)
 *
 * Low Priority Extended VC Count, writable through the DBI
 */

#define BP_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT      (4)      //!< Bit position for PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT.
#define BM_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT      (0x00000070)  //!< Bit mask for PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT.

//! @brief Get value of PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT from a register value.
#define BG_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT) >> BP_PCIE_PVCCR1_LOW_PRIORITY_EXTENDED_VC_COUNT)

/* --- Register HW_PCIE_PVCCR1, field REFERENCE_CLOCK[9:8] (RO)
 *
 * Reference Clock
 */

#define BP_PCIE_PVCCR1_REFERENCE_CLOCK      (8)      //!< Bit position for PCIE_PVCCR1_REFERENCE_CLOCK.
#define BM_PCIE_PVCCR1_REFERENCE_CLOCK      (0x00000300)  //!< Bit mask for PCIE_PVCCR1_REFERENCE_CLOCK.

//! @brief Get value of PCIE_PVCCR1_REFERENCE_CLOCK from a register value.
#define BG_PCIE_PVCCR1_REFERENCE_CLOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR1_REFERENCE_CLOCK) >> BP_PCIE_PVCCR1_REFERENCE_CLOCK)

/* --- Register HW_PCIE_PVCCR1, field PORT_ARBITRATION_TABLE_ENTRY_SIZE[11:10] (RO)
 *
 * Port Arbitration Table Entry Size
 */

#define BP_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE      (10)      //!< Bit position for PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE.
#define BM_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE      (0x00000c00)  //!< Bit mask for PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE.

//! @brief Get value of PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE from a register value.
#define BG_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE) >> BP_PCIE_PVCCR1_PORT_ARBITRATION_TABLE_ENTRY_SIZE)

//-------------------------------------------------------------------------------------------
// HW_PCIE_PVCCR2 - Port VC Capability Register 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PVCCR2 - Port VC Capability Register 2 (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0x8
 */
typedef union _hw_pcie_pvccr2
{
    reg32_t U;
    struct _hw_pcie_pvccr2_bitfields
    {
        unsigned VC_ARBITRATION_CAPABILITY : 8; //!< [7:0] VC Arbitration Capability Indicates which VC arbitration mode(s) the device supports, writable through the DBI: •Bit 0: Device supports hardware fixed arbitration scheme.
        unsigned RESERVED0 : 16; //!< [23:8] Reserved
        unsigned VC_ARBITRATION_TABLE_OFFSET : 8; //!< [31:24] VC Arbitration Table Offset (not supported) The default value is 0x00 (no arbitration table present).
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
#endif

/*
 * constants & macros for individual PCIE_PVCCR2 bitfields
 */

/* --- Register HW_PCIE_PVCCR2, field VC_ARBITRATION_CAPABILITY[7:0] (RO)
 *
 * VC Arbitration Capability Indicates which VC arbitration mode(s) the device supports, writable
 * through the DBI: •Bit 0: Device supports hardware fixed arbitration scheme. For the core, the
 * scheme is 16-phase weighted round robin (WRR). •Bit 1: Device supports 32-phase WRR •Bit 2:
 * Device supports 64-phase WRR •Bit 3: Device supports 128-phase WRR •Bits 4-7: Reserved
 */

#define BP_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY      (0)      //!< Bit position for PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY.
#define BM_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY      (0x000000ff)  //!< Bit mask for PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY.

//! @brief Get value of PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY from a register value.
#define BG_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY) >> BP_PCIE_PVCCR2_VC_ARBITRATION_CAPABILITY)

/* --- Register HW_PCIE_PVCCR2, field VC_ARBITRATION_TABLE_OFFSET[31:24] (RO)
 *
 * VC Arbitration Table Offset (not supported) The default value is 0x00 (no arbitration table
 * present).
 */

#define BP_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET      (24)      //!< Bit position for PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET.
#define BM_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET      (0xff000000)  //!< Bit mask for PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET.

//! @brief Get value of PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET from a register value.
#define BG_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET) >> BP_PCIE_PVCCR2_VC_ARBITRATION_TABLE_OFFSET)

//-------------------------------------------------------------------------------------------
// HW_PCIE_PVCCSR - Port VC Control and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_PVCCSR - Port VC Control and Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0xC  Bytes: 0-1
 */
typedef union _hw_pcie_pvccsr
{
    reg32_t U;
    struct _hw_pcie_pvccsr_bitfields
    {
        unsigned LOAD_VC_ARBITRATION_TABLE : 1; //!< [0] Load VC Arbitration Table
        unsigned VC_ARBITRATION_SELECT : 3; //!< [3:1] VC Arbitration Select
        unsigned RESERVED0 : 12; //!< [15:4] Reserved
        unsigned ARBITRATION_TABLE_STATUS : 1; //!< [16] Arbitration Table Status
        unsigned RESERVED1 : 15; //!< [31:17] Reserved
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

/* --- Register HW_PCIE_PVCCSR, field LOAD_VC_ARBITRATION_TABLE[0] (RW)
 *
 * Load VC Arbitration Table
 */

#define BP_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE      (0)      //!< Bit position for PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE.
#define BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE      (0x00000001)  //!< Bit mask for PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE.

//! @brief Get value of PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE from a register value.
#define BG_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE) >> BP_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE)

//! @brief Format value for bitfield PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE.
#define BF_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE) & BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOAD_VC_ARBITRATION_TABLE field to a new value.
#define BW_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)   (HW_PCIE_PVCCSR_WR((HW_PCIE_PVCCSR_RD() & ~BM_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE) | BF_PCIE_PVCCSR_LOAD_VC_ARBITRATION_TABLE(v)))
#endif

/* --- Register HW_PCIE_PVCCSR, field VC_ARBITRATION_SELECT[3:1] (RW)
 *
 * VC Arbitration Select
 */

#define BP_PCIE_PVCCSR_VC_ARBITRATION_SELECT      (1)      //!< Bit position for PCIE_PVCCSR_VC_ARBITRATION_SELECT.
#define BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT      (0x0000000e)  //!< Bit mask for PCIE_PVCCSR_VC_ARBITRATION_SELECT.

//! @brief Get value of PCIE_PVCCSR_VC_ARBITRATION_SELECT from a register value.
#define BG_PCIE_PVCCSR_VC_ARBITRATION_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT) >> BP_PCIE_PVCCSR_VC_ARBITRATION_SELECT)

//! @brief Format value for bitfield PCIE_PVCCSR_VC_ARBITRATION_SELECT.
#define BF_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PVCCSR_VC_ARBITRATION_SELECT) & BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VC_ARBITRATION_SELECT field to a new value.
#define BW_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)   (HW_PCIE_PVCCSR_WR((HW_PCIE_PVCCSR_RD() & ~BM_PCIE_PVCCSR_VC_ARBITRATION_SELECT) | BF_PCIE_PVCCSR_VC_ARBITRATION_SELECT(v)))
#endif

/* --- Register HW_PCIE_PVCCSR, field ARBITRATION_TABLE_STATUS[16] (RW)
 *
 * Arbitration Table Status
 */

#define BP_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS      (16)      //!< Bit position for PCIE_PVCCSR_ARBITRATION_TABLE_STATUS.
#define BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS      (0x00010000)  //!< Bit mask for PCIE_PVCCSR_ARBITRATION_TABLE_STATUS.

//! @brief Get value of PCIE_PVCCSR_ARBITRATION_TABLE_STATUS from a register value.
#define BG_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS) >> BP_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS)

//! @brief Format value for bitfield PCIE_PVCCSR_ARBITRATION_TABLE_STATUS.
#define BF_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS) & BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARBITRATION_TABLE_STATUS field to a new value.
#define BW_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)   (HW_PCIE_PVCCSR_WR((HW_PCIE_PVCCSR_RD() & ~BM_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS) | BF_PCIE_PVCCSR_ARBITRATION_TABLE_STATUS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_VCRCR - VC Resource Capability Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_VCRCR - VC Resource Capability Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0x10
 */
typedef union _hw_pcie_vcrcr
{
    reg32_t U;
    struct _hw_pcie_vcrcr_bitfields
    {
        unsigned PORT_ARBITRATION_CAPABILITY : 8; //!< [7:0] Port Arbitration Capability
        unsigned RESERVED0 : 7; //!< [14:8] Reserved.
        unsigned REJECT_SNOOP_TRANSACTIONS : 1; //!< [15] Reject Snoop Transactions
        unsigned MAXIMUM_TIME_SLOTS : 7; //!< [22:16] Maximum Time Slots
        unsigned RESERVED1 : 1; //!< [23] Reserved
        unsigned PORT_ARBITRATION_TABLE_OFFSET : 8; //!< [31:24] Port Arbitration Table Offset
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
#endif

/*
 * constants & macros for individual PCIE_VCRCR bitfields
 */

/* --- Register HW_PCIE_VCRCR, field PORT_ARBITRATION_CAPABILITY[7:0] (RO)
 *
 * Port Arbitration Capability
 */

#define BP_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY      (0)      //!< Bit position for PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY.
#define BM_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY      (0x000000ff)  //!< Bit mask for PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY.

//! @brief Get value of PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY from a register value.
#define BG_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY) >> BP_PCIE_VCRCR_PORT_ARBITRATION_CAPABILITY)

/* --- Register HW_PCIE_VCRCR, field REJECT_SNOOP_TRANSACTIONS[15] (RO)
 *
 * Reject Snoop Transactions
 */

#define BP_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS      (15)      //!< Bit position for PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS.
#define BM_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS      (0x00008000)  //!< Bit mask for PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS.

//! @brief Get value of PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS from a register value.
#define BG_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS) >> BP_PCIE_VCRCR_REJECT_SNOOP_TRANSACTIONS)

/* --- Register HW_PCIE_VCRCR, field MAXIMUM_TIME_SLOTS[22:16] (RO)
 *
 * Maximum Time Slots
 */

#define BP_PCIE_VCRCR_MAXIMUM_TIME_SLOTS      (16)      //!< Bit position for PCIE_VCRCR_MAXIMUM_TIME_SLOTS.
#define BM_PCIE_VCRCR_MAXIMUM_TIME_SLOTS      (0x007f0000)  //!< Bit mask for PCIE_VCRCR_MAXIMUM_TIME_SLOTS.

//! @brief Get value of PCIE_VCRCR_MAXIMUM_TIME_SLOTS from a register value.
#define BG_PCIE_VCRCR_MAXIMUM_TIME_SLOTS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCR_MAXIMUM_TIME_SLOTS) >> BP_PCIE_VCRCR_MAXIMUM_TIME_SLOTS)

/* --- Register HW_PCIE_VCRCR, field PORT_ARBITRATION_TABLE_OFFSET[31:24] (RO)
 *
 * Port Arbitration Table Offset
 */

#define BP_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET      (24)      //!< Bit position for PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET.
#define BM_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET      (0xff000000)  //!< Bit mask for PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET.

//! @brief Get value of PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET from a register value.
#define BG_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET) >> BP_PCIE_VCRCR_PORT_ARBITRATION_TABLE_OFFSET)

//-------------------------------------------------------------------------------------------
// HW_PCIE_VCRCONR - VC Resource Control Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_VCRCONR - VC Resource Control Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0x14
 */
typedef union _hw_pcie_vcrconr
{
    reg32_t U;
    struct _hw_pcie_vcrconr_bitfields
    {
        unsigned TC_VC_MAP : 8; //!< [7:0] TC/VC Map Bit 0 is hardwired to 1; bits 7:1 are RW.
        unsigned RESERVED0 : 8; //!< [15:8] Reserved
        unsigned LOAD_PORT_ARBITRATION_TABLE : 1; //!< [16] Load Port Arbitration Table
        unsigned PORT_ARBITRATION_SELECT : 3; //!< [19:17] Port Arbitration Select
        unsigned RESERVED1 : 4; //!< [23:20] Reserved
        unsigned VC_ID : 3; //!< [26:24] VC ID Hardwired to 0 for VC0.
        unsigned RESERVED2 : 4; //!< [30:27] Reserved
        unsigned VC_ENABLE : 1; //!< [31] VC Enable Hardwired to 1 for the first VC.
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

/* --- Register HW_PCIE_VCRCONR, field TC_VC_MAP[7:0] (RW)
 *
 * TC/VC Map Bit 0 is hardwired to 1; bits 7:1 are RW.
 */

#define BP_PCIE_VCRCONR_TC_VC_MAP      (0)      //!< Bit position for PCIE_VCRCONR_TC_VC_MAP.
#define BM_PCIE_VCRCONR_TC_VC_MAP      (0x000000ff)  //!< Bit mask for PCIE_VCRCONR_TC_VC_MAP.

//! @brief Get value of PCIE_VCRCONR_TC_VC_MAP from a register value.
#define BG_PCIE_VCRCONR_TC_VC_MAP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCONR_TC_VC_MAP) >> BP_PCIE_VCRCONR_TC_VC_MAP)

//! @brief Format value for bitfield PCIE_VCRCONR_TC_VC_MAP.
#define BF_PCIE_VCRCONR_TC_VC_MAP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_VCRCONR_TC_VC_MAP) & BM_PCIE_VCRCONR_TC_VC_MAP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TC_VC_MAP field to a new value.
#define BW_PCIE_VCRCONR_TC_VC_MAP(v)   (HW_PCIE_VCRCONR_WR((HW_PCIE_VCRCONR_RD() & ~BM_PCIE_VCRCONR_TC_VC_MAP) | BF_PCIE_VCRCONR_TC_VC_MAP(v)))
#endif

/* --- Register HW_PCIE_VCRCONR, field LOAD_PORT_ARBITRATION_TABLE[16] (RW)
 *
 * Load Port Arbitration Table
 */

#define BP_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE      (16)      //!< Bit position for PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE.
#define BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE      (0x00010000)  //!< Bit mask for PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE.

//! @brief Get value of PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE from a register value.
#define BG_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE) >> BP_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE)

//! @brief Format value for bitfield PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE.
#define BF_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE) & BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOAD_PORT_ARBITRATION_TABLE field to a new value.
#define BW_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)   (HW_PCIE_VCRCONR_WR((HW_PCIE_VCRCONR_RD() & ~BM_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE) | BF_PCIE_VCRCONR_LOAD_PORT_ARBITRATION_TABLE(v)))
#endif

/* --- Register HW_PCIE_VCRCONR, field PORT_ARBITRATION_SELECT[19:17] (RW)
 *
 * Port Arbitration Select
 */

#define BP_PCIE_VCRCONR_PORT_ARBITRATION_SELECT      (17)      //!< Bit position for PCIE_VCRCONR_PORT_ARBITRATION_SELECT.
#define BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT      (0x000e0000)  //!< Bit mask for PCIE_VCRCONR_PORT_ARBITRATION_SELECT.

//! @brief Get value of PCIE_VCRCONR_PORT_ARBITRATION_SELECT from a register value.
#define BG_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT) >> BP_PCIE_VCRCONR_PORT_ARBITRATION_SELECT)

//! @brief Format value for bitfield PCIE_VCRCONR_PORT_ARBITRATION_SELECT.
#define BF_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_VCRCONR_PORT_ARBITRATION_SELECT) & BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PORT_ARBITRATION_SELECT field to a new value.
#define BW_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)   (HW_PCIE_VCRCONR_WR((HW_PCIE_VCRCONR_RD() & ~BM_PCIE_VCRCONR_PORT_ARBITRATION_SELECT) | BF_PCIE_VCRCONR_PORT_ARBITRATION_SELECT(v)))
#endif

/* --- Register HW_PCIE_VCRCONR, field VC_ID[26:24] (RW)
 *
 * VC ID Hardwired to 0 for VC0.
 */

#define BP_PCIE_VCRCONR_VC_ID      (24)      //!< Bit position for PCIE_VCRCONR_VC_ID.
#define BM_PCIE_VCRCONR_VC_ID      (0x07000000)  //!< Bit mask for PCIE_VCRCONR_VC_ID.

//! @brief Get value of PCIE_VCRCONR_VC_ID from a register value.
#define BG_PCIE_VCRCONR_VC_ID(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCONR_VC_ID) >> BP_PCIE_VCRCONR_VC_ID)

//! @brief Format value for bitfield PCIE_VCRCONR_VC_ID.
#define BF_PCIE_VCRCONR_VC_ID(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_VCRCONR_VC_ID) & BM_PCIE_VCRCONR_VC_ID)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VC_ID field to a new value.
#define BW_PCIE_VCRCONR_VC_ID(v)   (HW_PCIE_VCRCONR_WR((HW_PCIE_VCRCONR_RD() & ~BM_PCIE_VCRCONR_VC_ID) | BF_PCIE_VCRCONR_VC_ID(v)))
#endif

/* --- Register HW_PCIE_VCRCONR, field VC_ENABLE[31] (RW)
 *
 * VC Enable Hardwired to 1 for the first VC.
 */

#define BP_PCIE_VCRCONR_VC_ENABLE      (31)      //!< Bit position for PCIE_VCRCONR_VC_ENABLE.
#define BM_PCIE_VCRCONR_VC_ENABLE      (0x80000000)  //!< Bit mask for PCIE_VCRCONR_VC_ENABLE.

//! @brief Get value of PCIE_VCRCONR_VC_ENABLE from a register value.
#define BG_PCIE_VCRCONR_VC_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRCONR_VC_ENABLE) >> BP_PCIE_VCRCONR_VC_ENABLE)

//! @brief Format value for bitfield PCIE_VCRCONR_VC_ENABLE.
#define BF_PCIE_VCRCONR_VC_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PCIE_VCRCONR_VC_ENABLE) & BM_PCIE_VCRCONR_VC_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VC_ENABLE field to a new value.
#define BW_PCIE_VCRCONR_VC_ENABLE(v)   (HW_PCIE_VCRCONR_WR((HW_PCIE_VCRCONR_RD() & ~BM_PCIE_VCRCONR_VC_ENABLE) | BF_PCIE_VCRCONR_VC_ENABLE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PCIE_VCRSR - VC Resource Status Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PCIE_VCRSR - VC Resource Status Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * Offset: 0x140 + 0x18
 */
typedef union _hw_pcie_vcrsr
{
    reg32_t U;
    struct _hw_pcie_vcrsr_bitfields
    {
        unsigned RESERVED0 : 16; //!< [15:0] Reserved
        unsigned PORT_ARBITRATION_TABLE_STATUS : 1; //!< [16] Port Arbitration Table Status
        unsigned VC_NEGOTIATION_PENDING : 1; //!< [17] VC Negotiation Pending
        unsigned RESERVED1 : 14; //!< [31:18] Reserved
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
#endif

/*
 * constants & macros for individual PCIE_VCRSR bitfields
 */

/* --- Register HW_PCIE_VCRSR, field PORT_ARBITRATION_TABLE_STATUS[16] (RO)
 *
 * Port Arbitration Table Status
 */

#define BP_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS      (16)      //!< Bit position for PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS.
#define BM_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS      (0x00010000)  //!< Bit mask for PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS.

//! @brief Get value of PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS from a register value.
#define BG_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS) >> BP_PCIE_VCRSR_PORT_ARBITRATION_TABLE_STATUS)

/* --- Register HW_PCIE_VCRSR, field VC_NEGOTIATION_PENDING[17] (RO)
 *
 * VC Negotiation Pending
 */

#define BP_PCIE_VCRSR_VC_NEGOTIATION_PENDING      (17)      //!< Bit position for PCIE_VCRSR_VC_NEGOTIATION_PENDING.
#define BM_PCIE_VCRSR_VC_NEGOTIATION_PENDING      (0x00020000)  //!< Bit mask for PCIE_VCRSR_VC_NEGOTIATION_PENDING.

//! @brief Get value of PCIE_VCRSR_VC_NEGOTIATION_PENDING from a register value.
#define BG_PCIE_VCRSR_VC_NEGOTIATION_PENDING(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PCIE_VCRSR_VC_NEGOTIATION_PENDING) >> BP_PCIE_VCRSR_VC_NEGOTIATION_PENDING)


/*!
 * @brief All PCIE module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pcie
{
    volatile hw_pcie_deviceid_t DEVICEID; //!< Device ID and Vendor ID Register
    volatile hw_pcie_command_t COMMAND; //!< Command and Status Register
    volatile hw_pcie_revid_t REVID; //!< Revision ID and Class Code Register
    volatile hw_pcie_bist_t BIST; //!< BIST Register
    volatile hw_pcie_bar0_t BAR0; //!< Base Address 0
    volatile hw_pcie_bar1_t BAR1; //!< Base Address 1
    volatile hw_pcie_bar2_t BAR2; //!< Base Address 2
    volatile hw_pcie_bar3_t BAR3; //!< Base Address 3
    volatile hw_pcie_bar4_t BAR4; //!< Base Address 4
    volatile hw_pcie_bar5_t BAR5; //!< Base Address 5
    volatile hw_pcie_cisp_t CISP; //!< CardBus CIS Pointer Register
    volatile hw_pcie_ssid_t SSID; //!< Subsystem ID and Subsystem Vendor ID Register
    volatile hw_pcie_erombar_t EROMBAR; //!< Expansion ROM Base Address Register
    volatile hw_pcie_cappr_t CAPPR; //!< Capability Pointer Register
    reg32_t _reserved0;
    volatile hw_pcie_ilr_t ILR; //!< Interrupt Line and Pin Register
    volatile hw_pcie_pmcr_t PMCR; //!< Power Management Capability Register
    volatile hw_pcie_pmcsr_t PMCSR; //!< Power Management Control and Status Register
    reg32_t _reserved1[10];
    volatile hw_pcie_cidr_t CIDR; //!< PCI Express Capability ID Register
    volatile hw_pcie_dcr_t DCR; //!< Device Capabilities Register
    volatile hw_pcie_dconr_t DCONR; //!< Device Control Register
    volatile hw_pcie_lcr_t LCR; //!< Link Capabilities Register
    volatile hw_pcie_lcsr_t LCSR; //!< Link Control and Status Register
    volatile hw_pcie_scr_t SCR; //!< Slot Capabilities Register
    volatile hw_pcie_scsr_t SCSR; //!< Slot Control and Status Register
    volatile hw_pcie_rccr_t RCCR; //!< Root Control and Capabilities Register
    volatile hw_pcie_rsr_t RSR; //!< Root Status Register
    volatile hw_pcie_dcr2_t DCR2; //!< Device Capabilities 2 Register
    volatile hw_pcie_dcsr2_t DCSR2; //!< Device Control and Status 2 Register
    volatile hw_pcie_lcr2_t LCR2; //!< Link Capabilities 2 Register
    volatile hw_pcie_lcsr2_t LCSR2; //!< Link Control and Status 2 Register
    reg32_t _reserved2[23];
    volatile hw_pcie_aer_t AER; //!< AER Capability Header
    volatile hw_pcie_uesr_t UESR; //!< Uncorrectable Error Status Register
    volatile hw_pcie_uemr_t UEMR; //!< Uncorrectable Error Mask Register
    volatile hw_pcie_uesevr_t UESEVR; //!< Uncorrectable Error Severity Register
    volatile hw_pcie_cesr_t CESR; //!< Correctable Error Status Register
    volatile hw_pcie_cemr_t CEMR; //!< Correctable Error Mask Register
    volatile hw_pcie_accr_t ACCR; //!< Advanced Capabilities and Control Register
    volatile hw_pcie_hlr_t HLR; //!< Header Log Register
    reg32_t _reserved3[3];
    volatile hw_pcie_recr_t RECR; //!< Root Error Command Register
    volatile hw_pcie_resr_t RESR; //!< Root Error Status Register
    volatile hw_pcie_esir_t ESIR; //!< Error Source Identification Register
    reg32_t _reserved4[2];
    volatile hw_pcie_vcechr_t VCECHR; //!< VC Extended Capability Header
    volatile hw_pcie_pvccr1_t PVCCR1; //!< Port VC Capability Register 1
    volatile hw_pcie_pvccr2_t PVCCR2; //!< Port VC Capability Register 2
    volatile hw_pcie_pvccsr_t PVCCSR; //!< Port VC Control and Status Register
    volatile hw_pcie_vcrcr_t VCRCR; //!< VC Resource Capability Register n
    volatile hw_pcie_vcrconr_t VCRCONR; //!< VC Resource Control Register n
    volatile hw_pcie_vcrsr_t VCRSR; //!< VC Resource Status Register n
} hw_pcie_t;
#pragma pack()

//! @brief Macro to access all PCIE registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PCIE(0)</code>.
#define HW_PCIE     (*(volatile hw_pcie_t *) REGS_PCIE_BASE)

#endif


#endif // __HW_PCIE_REGISTERS_H__
