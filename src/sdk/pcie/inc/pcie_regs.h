/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PCI_REGS_H__
#define __PCI_REGS_H__

/*
 * ABSTRACT : Register definition header file for 
 */
#define PCI_CONFIG_HEADER_BaseAddress 0x0

/* Register ID */
/* Device and Vendor ID */
#define PCIE_ID (PCI_CONFIG_HEADER_BaseAddress + 0x0)
#define ID_RegisterSize 32
#define ID_RegisterResetValue 0xabcd16c3    // DG 0x0
#define ID_RegisterResetMask 0xffffffff

/* Register Field information for ID */

/* Register ID field VendorID */
/* Vendor ID */
#define ID_VendorID_BitAddressOffset 0
#define ID_VendorID_RegisterSize 16

/* Register ID field DeviceID */
/* Device ID */
#define ID_DeviceID_BitAddressOffset 16
#define ID_DeviceID_RegisterSize 16

/* End of Register Definition for ID */

/* Register STS_CMD_RGSTR */
/* Status and Command registers */
#define STS_CMD_RGSTR (PCI_CONFIG_HEADER_BaseAddress + 0x4)
#define STS_CMD_RGSTR_RegisterSize 32
#define STS_CMD_RGSTR_RegisterResetValue 0x00100000 // 0x0
#define STS_CMD_RGSTR_RegisterResetMask 0xffffffff

/* Register Field information for STS_CMD_RGSTR */

/* Register STS_CMD_RGSTR field CMD_RGSTR */
/* Command Register */
#define STS_CMD_RGSTR_CMD_RGSTR_BitAddressOffset 0
#define STS_CMD_RGSTR_CMD_RGSTR_RegisterSize 16

/* Register STS_CMD_RGSTR field STS_RGSTR */
/* Status Register */
#define STS_CMD_RGSTR_STS_RGSTR_BitAddressOffset 16
#define STS_CMD_RGSTR_STS_RGSTR_RegisterSize 16

/* End of Register Definition for STS_CMD_RGSTR */

/* Register CLS_REV_ID */
/* Class code and Revision ID */
#define CLS_REV_ID (PCI_CONFIG_HEADER_BaseAddress + 0x8)
#define CLS_REV_ID_RegisterSize 32
#define CLS_REV_ID_RegisterResetValue 0x1   // DG 0x0
#define CLS_REV_ID_RegisterResetMask 0xffffffff

/* Register Field information for CLS_REV_ID */

/* Register CLS_REV_ID field RevID */
/* Revision ID */
#define CLS_REV_ID_RevID_BitAddressOffset 0
#define CLS_REV_ID_RevID_RegisterSize 8

/* Register CLS_REV_ID field CLS_CD */
/* Class Code */
#define CLS_REV_ID_CLS_CD_BitAddressOffset 8
#define CLS_REV_ID_CLS_CD_RegisterSize 24

/* End of Register Definition for CLS_REV_ID */

/* Register BIST_HEAD_LAT_CACH */
/* BIST, Header Type, Latency Timer, Cache Line Size */
#define BIST_HEAD_LAT_CACH (PCI_CONFIG_HEADER_BaseAddress + 0xc)
#define BIST_HEAD_LAT_CACH_RegisterSize 32
#define BIST_HEAD_LAT_CACH_RegisterResetValue 0x00010000    //DG 0x0
#define BIST_HEAD_LAT_CACH_RegisterResetMask 0xffffffff

/* Register Field information for BIST_HEAD_LAT_CACH */

/* Register BIST_HEAD_LAT_CACH field CACH_LN_SZE */
/* Cache Line Size */
#define BIST_HEAD_LAT_CACH_CACH_LN_SZE_BitAddressOffset 0
#define BIST_HEAD_LAT_CACH_CACH_LN_SZE_RegisterSize 8

/* Register BIST_HEAD_LAT_CACH field LAT_TIM */
/* Latency Timer */
#define BIST_HEAD_LAT_CACH_LAT_TIM_BitAddressOffset 8
#define BIST_HEAD_LAT_CACH_LAT_TIM_RegisterSize 8

/* Register BIST_HEAD_LAT_CACH field HEAD_TYP */
/* Header Type */
#define BIST_HEAD_LAT_CACH_HEAD_TYP_BitAddressOffset 16
#define BIST_HEAD_LAT_CACH_HEAD_TYP_RegisterSize 8

/* Register BIST_HEAD_LAT_CACH field BIST */
/* BIST */
#define BIST_HEAD_LAT_CACH_BIST_BitAddressOffset 24
#define BIST_HEAD_LAT_CACH_BIST_RegisterSize 8

/* End of Register Definition for BIST_HEAD_LAT_CACH */

/* Register BAS_ADR_0 */
/* Base Address Register 0 */
#define BAS_ADR_0 (PCI_CONFIG_HEADER_BaseAddress + 0x10)
#define BAS_ADR_0_RegisterSize 32
#define BAS_ADR_0_RegisterResetValue 0xC    // DG 0x0
#define BAS_ADR_0_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_0 */

/* Register BAS_ADR_1 */
/* Base Address Register 1 */
#define BAS_ADR_1 (PCI_CONFIG_HEADER_BaseAddress + 0x14)
#define BAS_ADR_1_RegisterSize 32
#define BAS_ADR_1_RegisterResetValue 0x0
#define BAS_ADR_1_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_1 */

/* Register LT_SP_BUS_N */
/* Latency Timer, Secondary and Primary Bus Number */
#define LT_SP_BUS_N (PCI_CONFIG_HEADER_BaseAddress + 0x18)
#define LT_SP_BUS_N_RegisterSize 32
#define LT_SP_BUS_N_RegisterResetValue 0x0
#define LT_SP_BUS_N_RegisterResetMask 0xffffffff

/* Register Field information for LT_SP_BUS_N */

/* Register LT_SP_BUS_N field PRIM_BUS_N */
/* Primary Bus Number */
#define LT_SP_BUS_N_PRIM_BUS_N_BitAddressOffset 0
#define LT_SP_BUS_N_PRIM_BUS_N_RegisterSize 8

/* Register LT_SP_BUS_N field SEC_BUS_N */
/* Secondary Bus Number */
#define LT_SP_BUS_N_SEC_BUS_N_BitAddressOffset 8
#define LT_SP_BUS_N_SEC_BUS_N_RegisterSize 8

/* Register LT_SP_BUS_N field SUB_BUS_N */
/* Subordinate Bus Number */
#define LT_SP_BUS_N_SUB_BUS_N_BitAddressOffset 16
#define LT_SP_BUS_N_SUB_BUS_N_RegisterSize 8

/* Register LT_SP_BUS_N field SEC_LT */
/* Secondary Latency Timer */
#define LT_SP_BUS_N_SEC_LT_BitAddressOffset 24
#define LT_SP_BUS_N_SEC_LT_RegisterSize 8

/* End of Register Definition for LT_SP_BUS_N */

/* Register SS_IO_LT_BAS */
/* Secondary Status and I/O Limit and Base */
#define SS_IO_LT_BAS (PCI_CONFIG_HEADER_BaseAddress + 0x1c)
#define SS_IO_LT_BAS_RegisterSize 32
#define SS_IO_LT_BAS_RegisterResetValue 0x0
#define SS_IO_LT_BAS_RegisterResetMask 0xffffffff

/* Register Field information for SS_IO_LT_BAS */

/* Register SS_IO_LT_BAS field IO_BAS */
/* I/O Base */
#define SS_IO_LT_BAS_IO_BAS_BitAddressOffset 0
#define SS_IO_LT_BAS_IO_BAS_RegisterSize 8

/* Register SS_IO_LT_BAS field IO_LT */
/* I/O Limit */
#define SS_IO_LT_BAS_IO_LT_BitAddressOffset 8
#define SS_IO_LT_BAS_IO_LT_RegisterSize 8

/* Register SS_IO_LT_BAS field SEC_STS */
/* Secondary Status */
#define SS_IO_LT_BAS_SEC_STS_BitAddressOffset 16
#define SS_IO_LT_BAS_SEC_STS_RegisterSize 16

/* End of Register Definition for SS_IO_LT_BAS */

/* Register MEM_LT_BAS */
/* Memory Limit and Base */
#define MEM_LT_BAS (PCI_CONFIG_HEADER_BaseAddress + 0x20)
#define MEM_LT_BAS_RegisterSize 32
#define MEM_LT_BAS_RegisterResetValue 0x0
#define MEM_LT_BAS_RegisterResetMask 0xffffffff

/* Register Field information for MEM_LT_BAS */

/* Register MEM_LT_BAS field MEM_BAS */
/* Memory Base */
#define MEM_LT_BAS_MEM_BAS_BitAddressOffset 0
#define MEM_LT_BAS_MEM_BAS_RegisterSize 16

/* Register MEM_LT_BAS field MEM_LT */
/* Memory Limit */
#define MEM_LT_BAS_MEM_LT_BitAddressOffset 16
#define MEM_LT_BAS_MEM_LT_RegisterSize 16

/* End of Register Definition for MEM_LT_BAS */

/* Register PF_MEM_LT_BAS */
/* Prefetchable Memory Limit and Base */
#define PF_MEM_LT_BAS (PCI_CONFIG_HEADER_BaseAddress + 0x24)
#define PF_MEM_LT_BAS_RegisterSize 32
#define PF_MEM_LT_BAS_RegisterResetValue 0x0
#define PF_MEM_LT_BAS_RegisterResetMask 0xffffffff

/* Register Field information for PF_MEM_LT_BAS */

/* Register PF_MEM_LT_BAS field PF_MEM_BAS */
/* Prefetchable Memory Base */
#define PF_MEM_LT_BAS_PF_MEM_BAS_BitAddressOffset 0
#define PF_MEM_LT_BAS_PF_MEM_BAS_RegisterSize 16

/* Register PF_MEM_LT_BAS field PF_MEM_LT */
/* Prefetchable Memory Limit */
#define PF_MEM_LT_BAS_PF_MEM_LT_BitAddressOffset 16
#define PF_MEM_LT_BAS_PF_MEM_LT_RegisterSize 16

/* End of Register Definition for PF_MEM_LT_BAS */

/* Register PF_BAS_U32 */
/* Prefetchable Base Upper 32 Bits */
#define PF_BAS_U32 (PCI_CONFIG_HEADER_BaseAddress + 0x28)
#define PF_BAS_U32_RegisterSize 32
#define PF_BAS_U32_RegisterResetValue 0x0
#define PF_BAS_U32_RegisterResetMask 0xffffffff

/* End of Register Definition for PF_BAS_U32 */

/* Register PF_LT_U32 */
/* Prefetchable Limit Upper 32 Bits */
#define PF_LT_U32 (PCI_CONFIG_HEADER_BaseAddress + 0x2c)
#define PF_LT_U32_RegisterSize 32
#define PF_LT_U32_RegisterResetValue 0x0
#define PF_LT_U32_RegisterResetMask 0xffffffff

/* End of Register Definition for PF_LT_U32 */

/* Register IO_LT_BAS */
/* I/O Limit Base Upper 32 Bits */
#define IO_LT_BAS (PCI_CONFIG_HEADER_BaseAddress + 0x30)
#define IO_LT_BAS_RegisterSize 32
#define IO_LT_BAS_RegisterResetValue 0x0
#define IO_LT_BAS_RegisterResetMask 0xffffffff

/* Register Field information for IO_LT_BAS */

/* Register IO_LT_BAS field IO_BAS_32 */
/* I/O Base Upper 32Bits */
#define IO_LT_BAS_IO_BAS_32_BitAddressOffset 0
#define IO_LT_BAS_IO_BAS_32_RegisterSize 16

/* Register IO_LT_BAS field IO_LT_32 */
/* I/O Limit Upper 32Bits */
#define IO_LT_BAS_IO_LT_32_BitAddressOffset 16
#define IO_LT_BAS_IO_LT_32_RegisterSize 16

/* End of Register Definition for IO_LT_BAS */

/* Register CAPPTR */
/* CapPtr */
#define CAPPTR (PCI_CONFIG_HEADER_BaseAddress + 0x34)
#define CAPPTR_RegisterSize 32
#define CAPPTR_RegisterResetValue 0x40  //DG 0x0
#define CAPPTR_RegisterResetMask 0xffffffff

/* Register Field information for CAPPTR */

/* Register CAPPTR field Captr */
/* CapPtr */
#define CAPPTR_Captr_BitAddressOffset 0
#define CAPPTR_Captr_RegisterSize 8

/* Register CAPPTR field RESERVE1 */
/* Reserved */
#define CAPPTR_RESERVE1_BitAddressOffset 8
#define CAPPTR_RESERVE1_RegisterSize 24

/* End of Register Definition for CAPPTR */

/* Register EXP_ROM_ADDR */
/* Expansion ROM Base Address */
#define EXP_ROM_ADDR (PCI_CONFIG_HEADER_BaseAddress + 0x38)
#define EXP_ROM_ADDR_RegisterSize 32
#define EXP_ROM_ADDR_RegisterResetValue 0x0
#define EXP_ROM_ADDR_RegisterResetMask 0xffffffff

/* End of Register Definition for EXP_ROM_ADDR */

/* Register BRDG_INT */
/* Bridge Control, Int Pin and line */
#define BRDG_INT (PCI_CONFIG_HEADER_BaseAddress + 0x3c)
#define BRDG_INT_RegisterSize 32
#define BRDG_INT_RegisterResetValue 0x1ff   // DG 0x0
#define BRDG_INT_RegisterResetMask 0xffffffff

/* Register Field information for BRDG_INT */

// EP view
/* Register BAS_ADR_2 */
/* Base Address Register 2 */
#define BAS_ADR_2 (PCI_CONFIG_HEADER_BaseAddress + 0x18)
#define BAS_ADR_2_RegisterSize 32
#define BAS_ADR_2_RegisterResetValue 0x0
#define BAS_ADR_2_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_2 */

/* Register BAS_ADR_3 */
/* Base Address Register 3 */
#define BAS_ADR_3 (PCI_CONFIG_HEADER_BaseAddress + 0x1c)
#define BAS_ADR_3_RegisterSize 32
#define BAS_ADR_3_RegisterResetValue 0x0
#define BAS_ADR_3_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_3 */

/* Register BAS_ADR_4 */
/* Base Address Register 4 */
#define BAS_ADR_4 (PCI_CONFIG_HEADER_BaseAddress + 0x20)
#define BAS_ADR_4_RegisterSize 32
#define BAS_ADR_4_RegisterResetValue 0x0
#define BAS_ADR_4_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_4 */

/* Register BAS_ADR_5 */
/* Base Address Register 5 */
#define BAS_ADR_5 (PCI_CONFIG_HEADER_BaseAddress + 0x24)
#define BAS_ADR_5_RegisterSize 32
#define BAS_ADR_5_RegisterResetValue 0x0
#define BAS_ADR_5_RegisterResetMask 0xffffffff

/* End of Register Definition for BAS_ADR_5 */

#define PCI_CONFIG_CS2_BaseAddress (PCI_CONFIG_HEADER_BaseAddress + (1<<12))
#define MSK_ADR_0 (PCI_CONFIG_CS2_BaseAddress + 0x10)
#define MSK_ADR_1 (PCI_CONFIG_CS2_BaseAddress + 0x14)
#define MSK_ADR_2 (PCI_CONFIG_CS2_BaseAddress + 0x18)
#define MSK_ADR_3 (PCI_CONFIG_CS2_BaseAddress + 0x1c)
#define MSK_ADR_4 (PCI_CONFIG_CS2_BaseAddress + 0x20)
#define MSK_ADR_5 (PCI_CONFIG_CS2_BaseAddress + 0x24)

/* Register CardBusCISPTR */
/* Prefetchable Base Upper 32 Bits */
#define CardBusCISPTR (PCI_CONFIG_HEADER_BaseAddress + 0x28)
#define CardBusCISPTR_RegisterSize 32
#define CardBusCISPTR_RegisterResetValue 0x0
#define CardBusCISPTR_RegisterResetMask 0xffffffff

/* Sub System and Sub System Vendor ID */
#define SubSysID (PCI_CONFIG_HEADER_BaseAddress + 0x2c)
#define SubSysID_RegisterSize 32
#define SubSysID_RegisterResetValue 0xabcd16c3  // DG 0x0
#define SubSysID_RegisterResetMask 0xffffffff

/* Register Field information for ID */

/* Register ID field VendorID */
/* Vendor ID */
#define SubSys_VendorID_BitAddressOffset 0
#define SubSys_VendorID_RegisterSize 16

/* Register ID field DeviceID */
/* Device ID */
#define SubSysID_BitAddressOffset 16
//#define SubSysID_RegisterSize 16

/* End of Register Definition for ID */
/* Register EXP_ROM_ADDR */
/* Expansion ROM Base Address */
//#define EXP_ROM_ADDR (PCI_CONFIG_HEADER_BaseAddress + 0x30)
#define EXP_ROM_ADDR_RegisterSize 32
#define EXP_ROM_ADDR_RegisterResetValue 0x0
#define EXP_ROM_ADDR_RegisterResetMask 0xffffffff

/* End of Register Definition for EXP_ROM_ADDR */

/* Register CAPPTR */
/* CapPtr */
#define CAPPTR (PCI_CONFIG_HEADER_BaseAddress + 0x34)
#define CAPPTR_RegisterSize 32
#define CAPPTR_RegisterResetValue 0x40  //DG 0x0
#define CAPPTR_RegisterResetMask 0xffffffff

/* Register Field information for CAPPTR */

/* Register CAPPTR field Captr */
/* CapPtr */
#define CAPPTR_Captr_BitAddressOffset 0
#define CAPPTR_Captr_RegisterSize 8

/* Register CAPPTR field RESERVE1 */
/* Reserved */
#define CAPPTR_RESERVE1_BitAddressOffset 8
#define CAPPTR_RESERVE1_RegisterSize 24

/* End of Register Definition for CAPPTR */

/* Register BRDG_INT field INT_LIN */
/* Interrupt Line */
#define BRDG_INT_INT_LIN_BitAddressOffset 0
#define BRDG_INT_INT_LIN_RegisterSize 8

/* Register BRDG_INT field INT_PIN */
/* Interrupt Pin */
#define BRDG_INT_INT_PIN_BitAddressOffset 8
#define BRDG_INT_INT_PIN_RegisterSize 8

/* Register BRDG_INT field BRDG_CTRL */
/* Bridge Control */
#define BRDG_INT_BRDG_CTRL_BitAddressOffset 16
#define BRDG_INT_BRDG_CTRL_RegisterSize 16

/* End of Register Definition for BRDG_INT */

#define PWR_MAG_STRUC_BaseAddress 0x40

/* Register CFG_PWR_CAP */
/* Power, ID */
#define CFG_PWR_CAP (PWR_MAG_STRUC_BaseAddress + 0x0)
#define CFG_PWR_CAP_RegisterSize 32
#define CFG_PWR_CAP_RegisterResetValue 0xdbc35001   //DG 0x0
#define CFG_PWR_CAP_RegisterResetMask 0xffffffff

/* Register Field information for CFG_PWR_CAP */

/* Register CFG_PWR_CAP field CAP_ID */
/* Capability ID */
#define CFG_PWR_CAP_CAP_ID_BitAddressOffset 0
#define CFG_PWR_CAP_CAP_ID_RegisterSize 8

/* Register CFG_PWR_CAP field PM_NX_PTR */
/* Next Capability Pointer */
#define CFG_PWR_CAP_PM_NX_PTR_BitAddressOffset 8
#define CFG_PWR_CAP_PM_NX_PTR_RegisterSize 8

/* Register CFG_PWR_CAP field PMC */
/* Power Management Capablities PMC */
#define CFG_PWR_CAP_PMC_BitAddressOffset 16
#define CFG_PWR_CAP_PMC_RegisterSize 16

/* End of Register Definition for CFG_PWR_CAP */

/* Register PWR_CSR */
/* PM Control Status */
#define PWR_CSR (PWR_MAG_STRUC_BaseAddress + 0x4)
#define PWR_CSR_RegisterSize 32
#define PWR_CSR_RegisterResetValue 0x0
#define PWR_CSR_RegisterResetMask 0xffffffff

/* Register Field information for PWR_CSR */

/* Register PWR_CSR field PMCSR */
/* PM Control Status Register */
#define PWR_CSR_PMCSR_BitAddressOffset 0
#define PWR_CSR_PMCSR_RegisterSize 16

/* Register PWR_CSR field PM_BSE */
/* PMCSR_BSE Bride Extention */
#define PWR_CSR_PM_BSE_BitAddressOffset 16
#define PWR_CSR_PM_BSE_RegisterSize 8

/* Register PWR_CSR field Data1 */
/* Data */
#define PWR_CSR_Data1_BitAddressOffset 24
#define PWR_CSR_Data1_RegisterSize 8

/* End of Register Definition for PWR_CSR */

#define MSI_STRUC_BaseAddress 0x50

/* Register MSG_CTR */
/* MSI cap structure */
#define MSG_CTR (MSI_STRUC_BaseAddress + 0x0)
#define MSG_CTR_RegisterSize 32
#define MSG_CTR_RegisterResetValue 0x01807005   // DG 0x0
#define MSG_CTR_RegisterResetMask 0xffffffff

/* Register Field information for MSG_CTR */

/* Register MSG_CTR field CAP_ID */
/* Capability ID */
#define MSG_CTR_CAP_ID_BitAddressOffset 0
#define MSG_CTR_CAP_ID_RegisterSize 8

/* Register MSG_CTR field MSI_NX_PTR */
/* Next Capability Pointer */
#define MSG_CTR_MSI_NX_PTR_BitAddressOffset 8
#define MSG_CTR_MSI_NX_PTR_RegisterSize 8

/* Register MSG_CTR field MSG_CTR_RGS */
/* Message Control Register */
#define MSG_CTR_MSG_CTR_RGS_BitAddressOffset 16
#define MSG_CTR_MSG_CTR_RGS_RegisterSize 16

/* End of Register Definition for MSG_CTR */

/* Register MSI_L32 */
/* MSI Lower 32-bit address register */
#define MSI_L32 (MSI_STRUC_BaseAddress + 0x4)
#define MSI_L32_RegisterSize 32
#define MSI_L32_RegisterResetValue 0x0
#define MSI_L32_RegisterResetMask 0xffffffff

/* End of Register Definition for MSI_L32 */

/* Register MSI_U32 */
/* MSI Upper 32-bit address register */
#define MSI_U32 (MSI_STRUC_BaseAddress + 0x8)
#define MSI_U32_RegisterSize 32
#define MSI_U32_RegisterResetValue 0x0
#define MSI_U32_RegisterResetMask 0xffffffff

/* End of Register Definition for MSI_U32 */

/* Register MSI_DATA */
/* MSI Data */
#define MSI_DATA (MSI_STRUC_BaseAddress + 0xc)
#define MSI_DATA_RegisterSize 32
#define MSI_DATA_RegisterResetValue 0x0
#define MSI_DATA_RegisterResetMask 0xffffffff

/* Register Field information for MSI_DATA */

/* Register MSI_DATA field MSI_DATA_F */
/* MSI Data */
#define MSI_DATA_MSI_DATA_F_BitAddressOffset 0
#define MSI_DATA_MSI_DATA_F_RegisterSize 16

/* End of Register Definition for MSI_DATA */

#define PCIE_CAP_STRUC_BaseAddress 0x70

/* Register PCIE_CAP */
/* PCIE cap structure */
#define PCIE_CAP (PCIE_CAP_STRUC_BaseAddress + 0x0)
#define PCIE_CAP_RegisterSize 32
#define PCIE_CAP_RegisterResetValue 0x00420010  // 0x0 for EP 0x00420010
#define PCIE_CAP_RegisterResetMask 0xffffffff

/* Register Field information for PCIE_CAP */

/* Register PCIE_CAP field CAP_ID */
/* Capability ID */
#define PCIE_CAP_CAP_ID_BitAddressOffset 0
#define PCIE_CAP_CAP_ID_RegisterSize 8

/* Register PCIE_CAP field PCIE_NX_PTR */
/* Next Capability Pointer */
#define PCIE_CAP_PCIE_NX_PTR_BitAddressOffset 8
#define PCIE_CAP_PCIE_NX_PTR_RegisterSize 8

/* Register PCIE_CAP field PCIE_CAP_R */
/* PCIE Capability Register */
#define PCIE_CAP_PCIE_CAP_R_BitAddressOffset 16
#define PCIE_CAP_PCIE_CAP_R_RegisterSize 16

/* End of Register Definition for PCIE_CAP */

/* Register DEV_CAP */
/* PCIE Device cap */
#define DEV_CAP (PCIE_CAP_STRUC_BaseAddress + 0x4)
#define DEV_CAP_RegisterSize 32
#define DEV_CAP_RegisterResetValue 0x8000   // DG 0x0
#define DEV_CAP_RegisterResetMask 0xffffffff

/* End of Register Definition for DEV_CAP */

/* Register DEV_STS_CTRL */
/* PCIE cap Device status and control */
#define DEV_STS_CTRL (PCIE_CAP_STRUC_BaseAddress + 0x8)
#define DEV_STS_CTRL_RegisterSize 32
#define DEV_STS_CTRL_RegisterResetValue 0x00102010  // DG 0x0
#define DEV_STS_CTRL_RegisterResetMask 0xffffffff

/* Register Field information for DEV_STS_CTRL */

/* Register DEV_STS_CTRL field DEV_CTRL */
/* PCIE Capability Device Control */
#define DEV_STS_CTRL_DEV_CTRL_BitAddressOffset 0
#define DEV_STS_CTRL_DEV_CTRL_RegisterSize 16

/* Register DEV_STS_CTRL field DEV_STS */
/* PCIE Capability Device Status */
#define DEV_STS_CTRL_DEV_STS_BitAddressOffset 16
#define DEV_STS_CTRL_DEV_STS_RegisterSize 16

/* End of Register Definition for DEV_STS_CTRL */

/* Register LNK_CAP */
/* PCIE Link cap */
#define LNK_CAP (PCIE_CAP_STRUC_BaseAddress + 0xc)
#define LNK_CAP_RegisterSize 32
#define LNK_CAP_RegisterResetValue 0x011cc12    // DG 0x0
#define LNK_CAP_RegisterResetMask 0xffffffff

/* End of Register Definition for LNK_CAP */

/* Register LNK_STS_CTRL */
/* PCIE cap Link status and control */
#define LNK_STS_CTRL (PCIE_CAP_STRUC_BaseAddress + 0x10)
#define LNK_STS_CTRL_RegisterSize 32
#define LNK_STS_CTRL_RegisterResetValue 0x0
#define LNK_STS_CTRL_RegisterResetMask 0x0000ffff   // DG0xffffffff

/* Register Field information for LNK_STS_CTRL */

/* Register LNK_STS_CTRL field LNK_CTRL */
/* PCIE Capability Link Control */
#define LNK_STS_CTRL_LNK_CTRL_BitAddressOffset 0
#define LNK_STS_CTRL_LNK_CTRL_RegisterSize 16

/* Register LNK_STS_CTRL field LNK_STS */
/* PCIE Capability Link Status */
#define LNK_STS_CTRL_LNK_STS_BitAddressOffset 16
#define LNK_STS_CTRL_LNK_STS_RegisterSize 16

/* End of Register Definition for LNK_STS_CTRL */

/* Register SLT_CAP */
/* PCIE Slot cap */
#define SLT_CAP (PCIE_CAP_STRUC_BaseAddress + 0x14)
#define SLT_CAP_RegisterSize 32
#define SLT_CAP_RegisterResetValue 0x0
#define SLT_CAP_RegisterResetMask 0xffffffff

/* End of Register Definition for SLT_CAP */

/* Register SLT_STS_CTRL */
/* PCIE cap Slot status and control */
#define SLT_STS_CTRL (PCIE_CAP_STRUC_BaseAddress + 0x18)
#define SLT_STS_CTRL_RegisterSize 32
#define SLT_STS_CTRL_RegisterResetValue 0x004003c0  // DG 0x0
#define SLT_STS_CTRL_RegisterResetMask 0xffffffff

/* Register Field information for SLT_STS_CTRL */

/* Register SLT_STS_CTRL field SLT_CTRL */
/* PCIE Capability Slot Control */
#define SLT_STS_CTRL_SLT_CTRL_BitAddressOffset 0
#define SLT_STS_CTRL_SLT_CTRL_RegisterSize 16

/* Register SLT_STS_CTRL field SLT_STS */
/* PCIE Capability Slot Status */
#define SLT_STS_CTRL_SLT_STS_BitAddressOffset 16
#define SLT_STS_CTRL_SLT_STS_RegisterSize 16

/* End of Register Definition for SLT_STS_CTRL */

/* Register RC_CAP_CTRL */
/* Root Capability and Control */
#define RC_CAP_CTRL (PCIE_CAP_STRUC_BaseAddress + 0x1c)
#define RC_CAP_CTRL_RegisterSize 32
#define RC_CAP_CTRL_RegisterResetValue 0x0
#define RC_CAP_CTRL_RegisterResetMask 0xffffffff

/* Register Field information for RC_CAP_CTRL */

/* Register RC_CAP_CTRL field RC_CTRL */
/* Root Control */
#define RC_CAP_CTRL_RC_CTRL_BitAddressOffset 0
#define RC_CAP_CTRL_RC_CTRL_RegisterSize 16

/* Register RC_CAP_CTRL field RC_CAP */
/* Root Capability */
#define RC_CAP_CTRL_RC_CAP_BitAddressOffset 16
#define RC_CAP_CTRL_RC_CAP_RegisterSize 16

/* End of Register Definition for RC_CAP_CTRL */

/* Register RC_STS */
/* Root Status */
#define RC_STS (PCIE_CAP_STRUC_BaseAddress + 0x20)
#define RC_STS_RegisterSize 32
#define RC_STS_RegisterResetValue 0x0
#define RC_STS_RegisterResetMask 0xffffffff
/* End of Register Definition for RC_STS */

/* Register DEV_CAP2 */
/* PCIE Device cap2 */
#define DEV_CAP2 (PCIE_CAP_STRUC_BaseAddress + 0x24)
#define DEV_CAP2_RegisterSize 32
#define DEV_CAP2_RegisterResetValue 0x11    // DG 0x0
#define DEV_CAP2_RegisterResetMask 0xffffffff

/* End of Register Definition for DEV_CAP */

/* Register DEV_STS_CTRL */
/* PCIE cap Device status and control */
#define DEV_STS2_CTRL (PCIE_CAP_STRUC_BaseAddress + 0x28)
#define DEV_STS2_CTRL_RegisterSize 32
#define DEV_STS2_CTRL_RegisterResetValue 0x0
#define DEV_STS2_CTRL_RegisterResetMask 0xffffffff

/* Register Field information for DEV_STS_CTRL */

/* Register DEV_STS_CTRL field DEV_CTRL */
/* PCIE Capability Device Control */
#define DEV_STS_CTRL2_DEV_CTRL_BitAddressOffset 0
#define DEV_STS_CTRL2_DEV_CTRL_RegisterSize 16

/* Register DEV_STS_CTRL field DEV_STS */
/* PCIE Capability Device Status */
#define DEV_STS_CTRL2_DEV_STS_BitAddressOffset 16
#define DEV_STS_CTRL2_DEV_STS_RegisterSize 16

/* End of Register Definition for DEV_STS_CTRL */

/* Register LNK_CAP */
/* PCIE Link cap */
#define LNK_CAP2 (PCIE_CAP_STRUC_BaseAddress + 0x2c)
#define LNK_CAP2_RegisterSize 32
#define LNK_CAP2_RegisterResetValue 0x06    // DG 0x0
#define LNK_CAP2_RegisterResetMask 0xffffffff

/* End of Register Definition for LNK_CAP */

/* Register LNK_STS_CTRL */
/* PCIE cap Link status and control */
#define LNK_STS_CTRL2 (PCIE_CAP_STRUC_BaseAddress + 0x30)
#define LNK_STS_CTRL2_RegisterSize 32
#define LNK_STS_CTRL2_RegisterResetValue 0x2
#define LNK_STS_CTRL2_RegisterResetMask 0x0000ffff  // DG0xffffffff

/* Register Field information for LNK_STS_CTRL */

/* Register LNK_STS_CTRL field LNK_CTRL */
/* PCIE Capability Link Control */
#define LNK_STS_CTRL2_LNK_CTRL_BitAddressOffset 0
#define LNK_STS_CTRL2_LNK_CTRL_RegisterSize 16

/* Register LNK_STS_CTRL field LNK_STS */
/* PCIE Capability Link Status */
#define LNK_STS_CTRL2_LNK_STS_BitAddressOffset 16
#define LNK_STS_CTRL2_LNK_STS_RegisterSize 16

/* End of Register Definition for LNK_STS_CTRL */

///* Register SLT_CAP */
///* PCIE Slot cap */
//#define SLT_CAP2 (PCIE_CAP_STRUC_BaseAddress + 0x34)
//#define SLT_CAP2_RegisterSize 32
//#define SLT_CAP2_RegisterResetValue 0x0
//#define SLT_CAP2_RegisterResetMask 0xffffffff
//
///* End of Register Definition for SLT_CAP */
//
///* Register SLT_STS_CTRL */
///* PCIE cap Slot status and control */
//#define SLT_STS_CTRL2 (PCIE_CAP_STRUC_BaseAddress + 0x38)
//#define SLT_STS_CTRL2_RegisterSize 32
//#define SLT_STS_CTRL2_RegisterResetValue 0x004003c0 // DG 0x0
//#define SLT_STS_CTRL2_RegisterResetMask 0xffffffff

/* Register Field information for SLT_STS_CTRL */

/* Register SLT_STS_CTRL field SLT_CTRL */
/* PCIE Capability Slot Control */
#define SLT_STS_CTRL2_SLT_CTRL_BitAddressOffset 0
#define SLT_STS_CTRL2_SLT_CTRL_RegisterSize 16

/* Register SLT_STS_CTRL field SLT_STS */
/* PCIE Capability Slot Status */
#define SLT_STS_CTRL2_SLT_STS_BitAddressOffset 16
#define SLT_STS_CTRL2_SLT_STS_RegisterSize 16

/* End of Register Definition for SLT_STS_CTRL */

/* Register RC_CAP_CTRL */
/* Root Capability and Control */
#define RC_CAP_CTRL2 (PCIE_CAP_STRUC_BaseAddress + 0x3c)
#define RC_CAP_CTRL2_RegisterSize 32
#define RC_CAP_CTRL2_RegisterResetValue 0x0
#define RC_CAP_CTRL2_RegisterResetMask 0xffffffff

/* Register Field information for RC_CAP_CTRL */
/* End of Register Definition for RC_STS */

// DG #define MSIX_STRUC_BaseAddress 0xb0
// DG 
// DG /* Register MSIX_CTR */
// DG /* MSI-X cap structure */
// DG #define MSIX_CTR (MSIX_STRUC_BaseAddress + 0x0)
// DG #define MSIX_CTR_RegisterSize 32
// DG #define MSIX_CTR_RegisterResetValue 0x011 // DG 0x0
// DG #define MSIX_CTR_RegisterResetMask 0xffffffff
// DG 
// DG /* Register Field information for MSIX_CTR */
// DG 
// DG /* Register MSIX_CTR field CAP_ID */
// DG /* Capability ID */
// DG #define MSIX_CTR_CAP_ID_BitAddressOffset 0
// DG #define MSIX_CTR_CAP_ID_RegisterSize 8
// DG 
// DG /* Register MSIX_CTR field MSIX_NX_PTR */
// DG /* Next Capability Pointer */
// DG #define MSIX_CTR_MSIX_NX_PTR_BitAddressOffset 8
// DG #define MSIX_CTR_MSIX_NX_PTR_RegisterSize 8
// DG 
// DG /* Register MSIX_CTR field MSIX_CTR_RGS */
// DG /* MSI-X Control Register */
// DG #define MSIX_CTR_MSIX_CTR_RGS_BitAddressOffset 16
// DG #define MSIX_CTR_MSIX_CTR_RGS_RegisterSize 16
// DG 
// DG /* End of Register Definition for MSIX_CTR */
// DG 
// DG /* Register MSIX_TBL */
// DG /* MSI-X Table Offset */
// DG #define MSIX_TBL (MSIX_STRUC_BaseAddress + 0x4)
// DG #define MSIX_TBL_RegisterSize 32
// DG #define MSIX_TBL_RegisterResetValue 0x0
// DG #define MSIX_TBL_RegisterResetMask 0xffffffff
// DG 
// DG /* End of Register Definition for MSIX_TBL */
// DG 
// DG /* Register MSIX_PBA */
// DG /* MSI-X PBA Offset */
// DG #define MSIX_PBA (MSIX_STRUC_BaseAddress + 0x8)
// DG #define MSIX_PBA_RegisterSize 32
// DG #define MSIX_PBA_RegisterResetValue 0x0
// DG #define MSIX_PBA_RegisterResetMask 0xffffffff
// DG 
// DG /* End of Register Definition for MSIX_PBA */

//#define VPD_STRUC_BaseAddress 0xd0
//
///* Register VPD_CAP */
///* VPD Control and Capability Register */
//#define VPD_CAP (VPD_STRUC_BaseAddress + 0x0)
//#define VPD_CAP_RegisterSize 32
//#define VPD_CAP_RegisterResetValue 0x3 // DG 0x0
//#define VPD_CAP_RegisterResetMask 0xffffffff
//
///* End of Register Definition for VPD_CAP */
//
///* Register VPD_DATA */
///* VPD Data Register */
//#define VPD_DATA (VPD_STRUC_BaseAddress + 0x4)
//#define VPD_DATA_RegisterSize 32
//#define VPD_DATA_RegisterResetValue 0x0
//#define VPD_DATA_RegisterResetMask 0xffffffff

/* End of Register Definition for VPD_DATA */

#define ADERR_STRUC_BaseAddress 0x100

/* Register PCIE_AER_CAP */
/* PCIE Express enhanced Cap Header */
#define PCIE_AER_CAP (ADERR_STRUC_BaseAddress + 0x0)
#define PCIE_AER_CAP_RegisterSize 32
#define PCIE_AER_CAP_RegisterResetValue 0x14010001  // DG0x0
#define PCIE_AER_CAP_RegisterResetMask 0xffffffff

/* End of Register Definition for PCIE_AER_CAP */

/* Register UN_ERR_ST_R */
/* Uncorrectable Error Status Register */
#define UN_ERR_ST_R (ADERR_STRUC_BaseAddress + 0x4)
#define UN_ERR_ST_R_RegisterSize 32
#define UN_ERR_ST_R_RegisterResetValue 0x0
#define UN_ERR_ST_R_RegisterResetMask 0xffffffff

/* End of Register Definition for UN_ERR_ST_R */

/* Register UN_ERR_MS_R */
/* Uncorrectable Error Mask Register */
#define UN_ERR_MS_R (ADERR_STRUC_BaseAddress + 0x8)
#define UN_ERR_MS_R_RegisterSize 32
#define UN_ERR_MS_R_RegisterResetValue 0x0
#define UN_ERR_MS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for UN_ERR_MS_R */

/* Register UN_ERR_SV_R */
/* Uncorrectable Error Severity Register */
#define UN_ERR_SV_R (ADERR_STRUC_BaseAddress + 0xc)
#define UN_ERR_SV_R_RegisterSize 32
#define UN_ERR_SV_R_RegisterResetValue 0x00062030   // DG 0x0
#define UN_ERR_SV_R_RegisterResetMask 0xffffffff

/* End of Register Definition for UN_ERR_SV_R */

/* Register CO_ERR_ST_R */
/* Correctable Error Status Register */
#define CO_ERR_ST_R (ADERR_STRUC_BaseAddress + 0x10)
#define CO_ERR_ST_R_RegisterSize 32
#define CO_ERR_ST_R_RegisterResetValue 0x0
#define CO_ERR_ST_R_RegisterResetMask 0xffffffff

/* End of Register Definition for CO_ERR_ST_R */

/* Register CO_ERR_MS_R */
/* Correctable Error Mask Register */
#define CO_ERR_MS_R (ADERR_STRUC_BaseAddress + 0x14)
#define CO_ERR_MS_R_RegisterSize 32
#define CO_ERR_MS_R_RegisterResetValue 0x2000   // DG 0x0
#define CO_ERR_MS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for CO_ERR_MS_R */

/* Register ADERR_CAP_CR */
/* Advanced Error Capabilities and Control Register */
#define ADERR_CAP_CR (ADERR_STRUC_BaseAddress + 0x18)
#define ADERR_CAP_CR_RegisterSize 32
#define ADERR_CAP_CR_RegisterResetValue 0xa0    // DG 0x0
#define ADERR_CAP_CR_RegisterResetMask 0xffffffff

/* End of Register Definition for ADERR_CAP_CR */

/* Register HD_L_R0 */
/* Header Log Registers 0 */
#define HD_L_R0 (ADERR_STRUC_BaseAddress + 0x1c)
#define HD_L_R0_RegisterSize 32
#define HD_L_R0_RegisterResetValue 0x0
#define HD_L_R0_RegisterResetMask 0xffffffff

/* End of Register Definition for HD_L_R0 */

/* Register HD_L_R4 */
/* Header Log Registers 4 */
#define HD_L_R4 (ADERR_STRUC_BaseAddress + 0x20)
#define HD_L_R4_RegisterSize 32
#define HD_L_R4_RegisterResetValue 0x0
#define HD_L_R4_RegisterResetMask 0xffffffff

/* End of Register Definition for HD_L_R4 */

/* Register HD_L_R8 */
/* Header Log Registers 8 */
#define HD_L_R8 (ADERR_STRUC_BaseAddress + 0x24)
#define HD_L_R8_RegisterSize 32
#define HD_L_R8_RegisterResetValue 0x0
#define HD_L_R8_RegisterResetMask 0xffffffff

/* End of Register Definition for HD_L_R8 */

/* Register HD_L_R12 */
/* Header Log Registers 12 */
#define HD_L_R12 (ADERR_STRUC_BaseAddress + 0x28)
#define HD_L_R12_RegisterSize 32
#define HD_L_R12_RegisterResetValue 0x0
#define HD_L_R12_RegisterResetMask 0xffffffff

/* End of Register Definition for HD_L_R12 */

/* Register RT_ERR_CMD_R */
/* Root Error Command Register */
#define RT_ERR_CMD_R (ADERR_STRUC_BaseAddress + 0x2c)
#define RT_ERR_CMD_R_RegisterSize 32
#define RT_ERR_CMD_R_RegisterResetValue 0x0
#define RT_ERR_CMD_R_RegisterResetMask 0xffffffff

/* End of Register Definition for RT_ERR_CMD_R */

/* Register RT_ERR_STS_R */
/* Root Error Status Register */
#define RT_ERR_STS_R (ADERR_STRUC_BaseAddress + 0x30)
#define RT_ERR_STS_R_RegisterSize 32
#define RT_ERR_STS_R_RegisterResetValue 0x0
#define RT_ERR_STS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for RT_ERR_STS_R */

/* Register ERR_SRC_ID_R */
/* Error Source Identification Register */
#define ERR_SRC_ID_R (ADERR_STRUC_BaseAddress + 0x34)
#define ERR_SRC_ID_R_RegisterSize 32
#define ERR_SRC_ID_R_RegisterResetValue 0x0
#define ERR_SRC_ID_R_RegisterResetMask 0xffffffff

/* End of Register Definition for ERR_SRC_ID_R */

#define VC_CAP_STRUC_BaseAddress 0x140

/* Register PCIE_EN_CAP */
/* PCIE Express enhanced Cap Header */
#define PCIE_EN_CAP (VC_CAP_STRUC_BaseAddress + 0x0)
#define PCIE_EN_CAP_RegisterSize 32
#define PCIE_EN_CAP_RegisterResetValue 0x10002  // DG 0x0
#define PCIE_EN_CAP_RegisterResetMask 0xffffffff

/* End of Register Definition for PCIE_EN_CAP */

/* Register PVC_CAP_R1 */
/* Port VC Capability Register 1 */
#define PVC_CAP_R1 (VC_CAP_STRUC_BaseAddress + 0x4)
#define PVC_CAP_R1_RegisterSize 32
#define PVC_CAP_R1_RegisterResetValue 0x0
#define PVC_CAP_R1_RegisterResetMask 0xffffffff

/* End of Register Definition for PVC_CAP_R1 */

/* Register P_CAP_R2 */
/* Port Capability Register 2 */
#define P_CAP_R2 (VC_CAP_STRUC_BaseAddress + 0x8)
#define P_CAP_R2_RegisterSize 32
#define P_CAP_R2_RegisterResetValue 0x0
#define P_CAP_R2_RegisterResetMask 0xffffffff

/* End of Register Definition for P_CAP_R2 */

/* Register PVC_STS_CTRL */
/* Port VC status and control */
#define PVC_STS_CTRL (VC_CAP_STRUC_BaseAddress + 0xc)
#define PVC_STS_CTRL_RegisterSize 32
#define PVC_STS_CTRL_RegisterResetValue 0x0
#define PVC_STS_CTRL_RegisterResetMask 0xffffffff

/* Register Field information for PVC_STS_CTRL */

/* Register PVC_STS_CTRL field PVC_CTRL */
/* Port VC Control Register */
#define PVC_STS_CTRL_PVC_CTRL_BitAddressOffset 0
#define PVC_STS_CTRL_PVC_CTRL_RegisterSize 16

/* Register PVC_STS_CTRL field PVC_STS */
/* Port VC Status Register */
#define PVC_STS_CTRL_PVC_STS_BitAddressOffset 16
#define PVC_STS_CTRL_PVC_STS_RegisterSize 16

/* End of Register Definition for PVC_STS_CTRL */

/* Register VC_CAP_R */
/* VC Resource Capability Register */
#define VC_CAP_R (VC_CAP_STRUC_BaseAddress + 0x10)
#define VC_CAP_R_RegisterSize 32
#define VC_CAP_R_RegisterResetValue 0x0
#define VC_CAP_R_RegisterResetMask 0xffffffff

/* End of Register Definition for VC_CAP_R */

/* Register VC_CTL_R */
/* VC Resource Control Register */
#define VC_CTL_R (VC_CAP_STRUC_BaseAddress + 0x14)
#define VC_CTL_R_RegisterSize 32
#define VC_CTL_R_RegisterResetValue 0x800000ff  // DG 0x0
#define VC_CTL_R_RegisterResetMask 0xffffffff

/* End of Register Definition for VC_CTL_R */

/* Register VC_STS_RSV */
/* VC Resource status and RsvdP */
#define VC_STS_RSV (VC_CAP_STRUC_BaseAddress + 0x18)
#define VC_STS_RSV_RegisterSize 32
#define VC_STS_RSV_RegisterResetValue 0x20000   // DG 0x0
#define VC_STS_RSV_RegisterResetMask 0xffffffff

/* Register Field information for VC_STS_RSV */

/* Register VC_STS_RSV field RSVDP */
/* RSVDP */
#define VC_STS_RSV_RSVDP_BitAddressOffset 0
#define VC_STS_RSV_RSVDP_RegisterSize 16

/* Register VC_STS_RSV field VC_STS */
/* VC Resource Status Register */
#define VC_STS_RSV_VC_STS_BitAddressOffset 16
#define VC_STS_RSV_VC_STS_RegisterSize 16

/* End of Register Definition for VC_STS_RSV */

/* Register VCR_CAP_R1 */
/* VC Resource Capability Register 1 */
#define VCR_CAP_R1 (VC_CAP_STRUC_BaseAddress + 0x1c)
#define VCR_CAP_R1_RegisterSize 32
#define VCR_CAP_R1_RegisterResetValue 0x0
#define VCR_CAP_R1_RegisterResetMask 0xffffffff

/* End of Register Definition for VCR_CAP_R1 */

/* Register VCR_CTRL_R1 */
/* VC Resource Control Register 1 */
#define VCR_CTRL_R1 (VC_CAP_STRUC_BaseAddress + 0x20)
#define VCR_CTRL_R1_RegisterSize 32
#define VCR_CTRL_R1_RegisterResetValue 0x0
#define VCR_CTRL_R1_RegisterResetMask 0xffffffff

/* End of Register Definition for VCR_CTRL_R1 */

/* Register VCR_STS_R1 */
/* VC Resource Status Register 1 */
#define VCR_STS_R1 (VC_CAP_STRUC_BaseAddress + 0x24)
#define VCR_STS_R1_RegisterSize 32
#define VCR_STS_R1_RegisterResetValue 0x0
#define VCR_STS_R1_RegisterResetMask 0xffffffff

/* Register Field information for VCR_STS_R1 */

/* Register VCR_STS_R1 field RSVDP1 */
/* RSVDP 1 */
#define VCR_STS_R1_RSVDP1_BitAddressOffset 0
#define VCR_STS_R1_RSVDP1_RegisterSize 16

/* Register VCR_STS_R1 field VC_STS1 */
/* VC Resource Status Register 1 */
#define VCR_STS_R1_VC_STS1_BitAddressOffset 16
#define VCR_STS_R1_VC_STS1_RegisterSize 16

/* End of Register Definition for VCR_STS_R1 */

// #define DEV_SR_CAP_R_BaseAddress 0x300
// 
// /* Register DEV_EN_CAP */
// /* Device Serial Number enhanced Cap Header */
// #define DEV_EN_CAP (DEV_SR_CAP_R_BaseAddress + 0x0)
// #define DEV_EN_CAP_RegisterSize 32
// #define DEV_EN_CAP_RegisterResetValue 0x0
// #define DEV_EN_CAP_RegisterResetMask 0xffffffff
// 
// /* End of Register Definition for DEV_EN_CAP */
// 
// /* Register SN_R1 */
// /* Serial Number Register 1st DWORD */
// #define SN_R1 (DEV_SR_CAP_R_BaseAddress + 0x4)
// #define SN_R1_RegisterSize 32
// #define SN_R1_RegisterResetValue 0x0
// #define SN_R1_RegisterResetMask 0xffffffff
// 
// /* End of Register Definition for SN_R1 */
// 
// /* Register SN_R2 */
// /* Serial Number Register 2nd DWORD */
// #define SN_R2 (DEV_SR_CAP_R_BaseAddress + 0x8)
// #define SN_R2_RegisterSize 32
// #define SN_R2_RegisterResetValue 0x0
// #define SN_R2_RegisterResetMask 0xffffffff

/* End of Register Definition for SN_R2 */

#define PRT_LOG_R_BaseAddress 0x700

/* Register LAT_REL_TIM */
/* Ack Latency and Replay Timer Register */
#define LAT_REL_TIM (PRT_LOG_R_BaseAddress + 0x0)
#define LAT_REL_TIM_RegisterSize 32
#define LAT_REL_TIM_RegisterResetValue 0x01630076   // DG 0x0
#define LAT_REL_TIM_RegisterResetMask 0xffffffff

/* End of Register Definition for LAT_REL_TIM */

/* Register OT_MSG_R */
/* Other Message Register */
#define OT_MSG_R (PRT_LOG_R_BaseAddress + 0x4)
#define OT_MSG_R_RegisterSize 32
#define OT_MSG_R_RegisterResetValue 0xffffffff  // 0x0
#define OT_MSG_R_RegisterResetMask 0xffffffff

/* End of Register Definition for OT_MSG_R */

/* Register PT_LNK_R */
/* Port Force Link Register */
#define PT_LNK_R (PRT_LOG_R_BaseAddress + 0x8)
#define PT_LNK_R_RegisterSize 32
#define PT_LNK_R_RegisterResetValue 0x07000004  // 0x0
#define PT_LNK_R_RegisterResetMask 0xffffffff

/* End of Register Definition for PT_LNK_R */

/* Register ACk_FREQ_R */
/* Ack Frequency Register */
#define ACk_FREQ_R (PRT_LOG_R_BaseAddress + 0xc)
#define ACk_FREQ_R_RegisterSize 32
#define ACk_FREQ_R_RegisterResetValue 0x1b2c2c00    // DG 0x0
#define ACk_FREQ_R_RegisterResetMask 0xffffffff

/* End of Register Definition for ACk_FREQ_R */

/* Register PT_LNK_CTRL_R */
/* Port Link Control Register */
#define PT_LNK_CTRL_R (PRT_LOG_R_BaseAddress + 0x10)
#define PT_LNK_CTRL_R_RegisterSize 32
#define PT_LNK_CTRL_R_RegisterResetValue 0x00010120 //0x0
#define PT_LNK_CTRL_R_RegisterResetMask 0xffffff7f  // ignore fast link mode since it is written be me

/* End of Register Definition for PT_LNK_CTRL_R */

/* Register LN_SKW_R */
/* Lane Skew Register */
#define LN_SKW_R (PRT_LOG_R_BaseAddress + 0x14)
#define LN_SKW_R_RegisterSize 32
#define LN_SKW_R_RegisterResetValue 0x0
#define LN_SKW_R_RegisterResetMask 0xffffffff

/* End of Register Definition for LN_SKW_R */

/* Register SYMB_N_R */
/* Symbol Number Register */
#define SYMB_N_R (PRT_LOG_R_BaseAddress + 0x18)
#define SYMB_N_R_RegisterSize 32
#define SYMB_N_R_RegisterResetValue 0x8000  // DG 0x0
#define SYMB_N_R_RegisterResetMask 0xffffffff

/* End of Register Definition for SYMB_N_R */

/* Register SYMB_T_R */
/* Symbol Timer and Filter Mask Register 1 */
#define SYMB_T_R (PRT_LOG_R_BaseAddress + 0x1c)
#define SYMB_T_R_RegisterSize 32
#define SYMB_T_R_RegisterResetValue 0x280   // DG 0x0
#define SYMB_T_R_RegisterResetMask 0xffffffff

/* End of Register Definition for SYMB_T_R */

/* Register FL_MSK_R2 */
/* Filter Mask Register 2 */
#define FL_MSK_R2 (PRT_LOG_R_BaseAddress + 0x20)
#define FL_MSK_R2_RegisterSize 32
#define FL_MSK_R2_RegisterResetValue 0x0
#define FL_MSK_R2_RegisterResetMask 0xffffffff

/* End of Register Definition for FL_MSK_R2 */
/* Register AMBA_MODNSR_VNT */
/* AMBA Multiple Outbound Decomposed NP Sub Request Control Register*/
#define AMBA_MODNSR_VNT (PRT_LOG_R_BaseAddress + 0x24)
#define AMBA_MODNSR_VNT_RegisterSize 32
#define AMBA_MODNSR_VNT_RegisterResetValue 0x1  // DG 0x0
#define AMBA_MODNSR_VNT_RegisterResetMask 0xffffffff

/* End of Register Definition for FL_MSK_R2 */

/* Register DB_R0 */
/* Debug Register 0 */
#define DB_R0 (PRT_LOG_R_BaseAddress + 0x28)
#define DB_R0_RegisterSize 32
#define DB_R0_RegisterResetValue 0x0
#define DB_R0_RegisterResetMask 0xffffffff

/* End of Register Definition for DB_R0 */

/* Register DB_R1 */
/* Debug Register 1 */
#define DB_R1 (PRT_LOG_R_BaseAddress + 0x2c)
#define DB_R1_RegisterSize 32
#define DB_R1_RegisterResetValue 0x0
#define DB_R1_RegisterResetMask 0xffffffff

/* End of Register Definition for DB_R1 */

/* Register TR_P_STS_R */
/* Transmit Posted FC Credit Status Register */
#define TR_P_STS_R (PRT_LOG_R_BaseAddress + 0x30)
#define TR_P_STS_R_RegisterSize 32
#define TR_P_STS_R_RegisterResetValue 0x0
#define TR_P_STS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for TR_P_STS_R */

/* Register TR_NP_STS_R */
/* Transmit Non-Posted FC Credit Status Register */
#define TR_NP_STS_R (PRT_LOG_R_BaseAddress + 0x34)
#define TR_NP_STS_R_RegisterSize 32
#define TR_NP_STS_R_RegisterResetValue 0x0
#define TR_NP_STS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for TR_NP_STS_R */

/* Register TR_C_STS_R */
/* Transmit Completion FC Credit Status Register */
#define TR_C_STS_R (PRT_LOG_R_BaseAddress + 0x38)
#define TR_C_STS_R_RegisterSize 32
#define TR_C_STS_R_RegisterResetValue 0xfffff   // DG 0x0
#define TR_C_STS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for TR_C_STS_R */

/* Register Q_STS_R */
/* Queue Status Register */
#define Q_STS_R (PRT_LOG_R_BaseAddress + 0x3c)
#define Q_STS_R_RegisterSize 32
#define Q_STS_R_RegisterResetValue 0x0
#define Q_STS_R_RegisterResetMask 0xfffffff8    // DG 0xffffffff

/* End of Register Definition for Q_STS_R */

/* Register VC_TR_A_R1 */
/* VC Transmit Arbitration Register 1 */
#define VC_TR_A_R1 (PRT_LOG_R_BaseAddress + 0x40)
#define VC_TR_A_R1_RegisterSize 32
#define VC_TR_A_R1_RegisterResetValue 0xf   // DG 0x0
#define VC_TR_A_R1_RegisterResetMask 0xffffffff

/* End of Register Definition for VC_TR_A_R1 */

/* Register VC_TR_A_R2 */
/* VC Transmit Arbitration Register 2 */
#define VC_TR_A_R2 (PRT_LOG_R_BaseAddress + 0x44)
#define VC_TR_A_R2_RegisterSize 32
#define VC_TR_A_R2_RegisterResetValue 0x0
#define VC_TR_A_R2_RegisterResetMask 0xffffffff

/* End of Register Definition for VC_TR_A_R2 */

/* Register VC0_PR_Q_C */
/* VC0 Posted Receive Queue Control */
#define VC0_PR_Q_C (PRT_LOG_R_BaseAddress + 0x48)
#define VC0_PR_Q_C_RegisterSize 32
#define VC0_PR_Q_C_RegisterResetValue 0x20c019  // DG 0x0
#define VC0_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_PR_Q_C */

/* Register VC0_NPR_Q_C */
/* VC0 Non-Posted Receive Queue Control */
#define VC0_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x4c)
#define VC0_NPR_Q_C_RegisterSize 32
#define VC0_NPR_Q_C_RegisterResetValue 0x20c003 // 0x0
#define VC0_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_NPR_Q_C */

/* Register VC0_CR_Q_C */
/* VC0 Completion Receive Queue Control */
#define VC0_CR_Q_C (PRT_LOG_R_BaseAddress + 0x50)
#define VC0_CR_Q_C_RegisterSize 32
#define VC0_CR_Q_C_RegisterResetValue 0x800000  // DG 0x0
#define VC0_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_CR_Q_C */

/* Register VC1_PR_Q_C */
/* VC1 Posted Receive Queue Control */
#define VC1_PR_Q_C (PRT_LOG_R_BaseAddress + 0x54)
#define VC1_PR_Q_C_RegisterSize 32
#define VC1_PR_Q_C_RegisterResetValue 0x0
#define VC1_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_PR_Q_C */

/* Register VC1_NPR_Q_C */
/* VC1 Non-Posted Receive Queue Control */
#define VC1_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x58)
#define VC1_NPR_Q_C_RegisterSize 32
#define VC1_NPR_Q_C_RegisterResetValue 0x0
#define VC1_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_NPR_Q_C */

/* Register VC1_CR_Q_C */
/* VC1 Completion Receive Queue Control */
#define VC1_CR_Q_C (PRT_LOG_R_BaseAddress + 0x5c)
#define VC1_CR_Q_C_RegisterSize 32
#define VC1_CR_Q_C_RegisterResetValue 0x0
#define VC1_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_CR_Q_C */

/* Register VC2_PR_Q_C */
/* VC2 Posted Receive Queue Control */
#define VC2_PR_Q_C (PRT_LOG_R_BaseAddress + 0x60)
#define VC2_PR_Q_C_RegisterSize 32
#define VC2_PR_Q_C_RegisterResetValue 0x0
#define VC2_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_PR_Q_C */

/* Register VC2_NPR_Q_C */
/* VC2 Non-Posted Receive Queue Control */
#define VC2_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x64)
#define VC2_NPR_Q_C_RegisterSize 32
#define VC2_NPR_Q_C_RegisterResetValue 0x0
#define VC2_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_NPR_Q_C */

/* Register VC2_CR_Q_C */
/* VC2 Completion Receive Queue Control */
#define VC2_CR_Q_C (PRT_LOG_R_BaseAddress + 0x68)
#define VC2_CR_Q_C_RegisterSize 32
#define VC2_CR_Q_C_RegisterResetValue 0x0
#define VC2_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_CR_Q_C */

/* Register VC3_PR_Q_C */
/* VC3 Posted Receive Queue Control */
#define VC3_PR_Q_C (PRT_LOG_R_BaseAddress + 0x6c)
#define VC3_PR_Q_C_RegisterSize 32
#define VC3_PR_Q_C_RegisterResetValue 0x0
#define VC3_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_PR_Q_C */

/* Register VC3_NPR_Q_C */
/* VC3 Non-Posted Receive Queue Control */
#define VC3_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x70)
#define VC3_NPR_Q_C_RegisterSize 32
#define VC3_NPR_Q_C_RegisterResetValue 0x0
#define VC3_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_NPR_Q_C */

/* Register VC3_CR_Q_C */
/* VC3 Completion Receive Queue Control */
#define VC3_CR_Q_C (PRT_LOG_R_BaseAddress + 0x74)
#define VC3_CR_Q_C_RegisterSize 32
#define VC3_CR_Q_C_RegisterResetValue 0x0
#define VC3_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_CR_Q_C */

/* Register VC4_PR_Q_C */
/* VC4 Posted Receive Queue Control */
#define VC4_PR_Q_C (PRT_LOG_R_BaseAddress + 0x78)
#define VC4_PR_Q_C_RegisterSize 32
#define VC4_PR_Q_C_RegisterResetValue 0x0
#define VC4_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_PR_Q_C */

/* Register VC4_NPR_Q_C */
/* VC4 Non-Posted Receive Queue Control */
#define VC4_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x7c)
#define VC4_NPR_Q_C_RegisterSize 32
#define VC4_NPR_Q_C_RegisterResetValue 0x0
#define VC4_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_NPR_Q_C */

/* Register VC4_CR_Q_C */
/* VC4 Completion Receive Queue Control */
#define VC4_CR_Q_C (PRT_LOG_R_BaseAddress + 0x80)
#define VC4_CR_Q_C_RegisterSize 32
#define VC4_CR_Q_C_RegisterResetValue 0x0
#define VC4_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_CR_Q_C */

/* Register VC5_PR_Q_C */
/* VC5 Posted Receive Queue Control */
#define VC5_PR_Q_C (PRT_LOG_R_BaseAddress + 0x84)
#define VC5_PR_Q_C_RegisterSize 32
#define VC5_PR_Q_C_RegisterResetValue 0x0
#define VC5_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_PR_Q_C */

/* Register VC5_NPR_Q_C */
/* VC5 Non-Posted Receive Queue Control */
#define VC5_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x88)
#define VC5_NPR_Q_C_RegisterSize 32
#define VC5_NPR_Q_C_RegisterResetValue 0x0
#define VC5_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_NPR_Q_C */

/* Register VC5_CR_Q_C */
/* VC5 Completion Receive Queue Control */
#define VC5_CR_Q_C (PRT_LOG_R_BaseAddress + 0x8c)
#define VC5_CR_Q_C_RegisterSize 32
#define VC5_CR_Q_C_RegisterResetValue 0x0
#define VC5_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_CR_Q_C */

/* Register VC6_PR_Q_C */
/* VC6 Posted Receive Queue Control */
#define VC6_PR_Q_C (PRT_LOG_R_BaseAddress + 0x90)
#define VC6_PR_Q_C_RegisterSize 32
#define VC6_PR_Q_C_RegisterResetValue 0x0
#define VC6_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_PR_Q_C */

/* Register VC6_NPR_Q_C */
/* VC6 Non-Posted Receive Queue Control */
#define VC6_NPR_Q_C (PRT_LOG_R_BaseAddress + 0x94)
#define VC6_NPR_Q_C_RegisterSize 32
#define VC6_NPR_Q_C_RegisterResetValue 0x0
#define VC6_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_NPR_Q_C */

/* Register VC6_CR_Q_C */
/* VC6 Completion Receive Queue Control */
#define VC6_CR_Q_C (PRT_LOG_R_BaseAddress + 0x98)
#define VC6_CR_Q_C_RegisterSize 32
#define VC6_CR_Q_C_RegisterResetValue 0x0
#define VC6_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_CR_Q_C */

/* Register VC7_PR_Q_C */
/* VC7 Posted Receive Queue Control */
#define VC7_PR_Q_C (PRT_LOG_R_BaseAddress + 0x9c)
#define VC7_PR_Q_C_RegisterSize 32
#define VC7_PR_Q_C_RegisterResetValue 0x0
#define VC7_PR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_PR_Q_C */

/* Register VC7_NPR_Q_C */
/* VC7 Non-Posted Receive Queue Control */
#define VC7_NPR_Q_C (PRT_LOG_R_BaseAddress + 0xa0)
#define VC7_NPR_Q_C_RegisterSize 32
#define VC7_NPR_Q_C_RegisterResetValue 0x0
#define VC7_NPR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_NPR_Q_C */

/* Register VC7_CR_Q_C */
/* VC7 Completion Receive Queue Control */
#define VC7_CR_Q_C (PRT_LOG_R_BaseAddress + 0xa4)
#define VC7_CR_Q_C_RegisterSize 32
#define VC7_CR_Q_C_RegisterResetValue 0x0
#define VC7_CR_Q_C_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_CR_Q_C */

/* Register VC0_PB_D */
/* VC0 Posted Buffer Depth */
#define VC0_PB_D (PRT_LOG_R_BaseAddress + 0xa8)
#define VC0_PB_D_RegisterSize 32
#define VC0_PB_D_RegisterResetValue 0x0
#define VC0_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_PB_D */

/* Register VC0_NPB_D */
/* VC0 Non-Posted Buffer Depth */
#define VC0_NPB_D (PRT_LOG_R_BaseAddress + 0xac)
#define VC0_NPB_D_RegisterSize 32
#define VC0_NPB_D_RegisterResetValue 0x0
#define VC0_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_NPB_D */

/* Register VC0_CB_D */
/* VC0 Completion Buffer Depth */
#define VC0_CB_D (PRT_LOG_R_BaseAddress + 0xb0)
#define VC0_CB_D_RegisterSize 32
#define VC0_CB_D_RegisterResetValue 0x0
#define VC0_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC0_CB_D */

/* Register VC1_PB_D */
/* VC1 Posted Buffer Depth */
#define VC1_PB_D (PRT_LOG_R_BaseAddress + 0xb4)
#define VC1_PB_D_RegisterSize 32
#define VC1_PB_D_RegisterResetValue 0x0
#define VC1_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_PB_D */

/* Register VC1_NPB_D */
/* VC1 Non-Posted Buffer Depth */
#define VC1_NPB_D (PRT_LOG_R_BaseAddress + 0xb8)
#define VC1_NPB_D_RegisterSize 32
#define VC1_NPB_D_RegisterResetValue 0x0
#define VC1_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_NPB_D */

/* Register VC1_CB_D */
/* VC1 Completion Buffer Depth */
#define VC1_CB_D (PRT_LOG_R_BaseAddress + 0xbc)
#define VC1_CB_D_RegisterSize 32
#define VC1_CB_D_RegisterResetValue 0x0
#define VC1_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC1_CB_D */

/* Register VC2_PB_D */
/* VC2 Posted Buffer Depth */
#define VC2_PB_D (PRT_LOG_R_BaseAddress + 0xc0)
#define VC2_PB_D_RegisterSize 32
#define VC2_PB_D_RegisterResetValue 0x0
#define VC2_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_PB_D */

/* Register VC2_NPB_D */
/* VC2 Non-Posted Buffer Depth */
#define VC2_NPB_D (PRT_LOG_R_BaseAddress + 0xc4)
#define VC2_NPB_D_RegisterSize 32
#define VC2_NPB_D_RegisterResetValue 0x0
#define VC2_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_NPB_D */

/* Register VC2_CB_D */
/* VC2 Completion Buffer Depth */
#define VC2_CB_D (PRT_LOG_R_BaseAddress + 0xc8)
#define VC2_CB_D_RegisterSize 32
#define VC2_CB_D_RegisterResetValue 0x0
#define VC2_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC2_CB_D */

/* Register VC3_PB_D */
/* VC3 Posted Buffer Depth */
#define VC3_PB_D (PRT_LOG_R_BaseAddress + 0xcc)
#define VC3_PB_D_RegisterSize 32
#define VC3_PB_D_RegisterResetValue 0x0
#define VC3_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_PB_D */

/* Register VC3_NPB_D */
/* VC3 Non-Posted Buffer Depth */
#define VC3_NPB_D (PRT_LOG_R_BaseAddress + 0xd0)
#define VC3_NPB_D_RegisterSize 32
#define VC3_NPB_D_RegisterResetValue 0x0
#define VC3_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_NPB_D */

/* Register VC3_CB_D */
/* VC3 Completion Buffer Depth */
#define VC3_CB_D (PRT_LOG_R_BaseAddress + 0xd4)
#define VC3_CB_D_RegisterSize 32
#define VC3_CB_D_RegisterResetValue 0x0
#define VC3_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC3_CB_D */

/* Register VC4_PB_D */
/* VC4 Posted Buffer Depth */
#define VC4_PB_D (PRT_LOG_R_BaseAddress + 0xd8)
#define VC4_PB_D_RegisterSize 32
#define VC4_PB_D_RegisterResetValue 0x0
#define VC4_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_PB_D */

/* Register VC4_NPB_D */
/* VC4 Non-Posted Buffer Depth */
#define VC4_NPB_D (PRT_LOG_R_BaseAddress + 0xdc)
#define VC4_NPB_D_RegisterSize 32
#define VC4_NPB_D_RegisterResetValue 0x0
#define VC4_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_NPB_D */

/* Register VC4_CB_D */
/* VC4 Completion Buffer Depth */
#define VC4_CB_D (PRT_LOG_R_BaseAddress + 0xe0)
#define VC4_CB_D_RegisterSize 32
#define VC4_CB_D_RegisterResetValue 0x0
#define VC4_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC4_CB_D */

/* Register VC5_PB_D */
/* VC5 Posted Buffer Depth */
#define VC5_PB_D (PRT_LOG_R_BaseAddress + 0xe4)
#define VC5_PB_D_RegisterSize 32
#define VC5_PB_D_RegisterResetValue 0x0
#define VC5_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_PB_D */

/* Register VC5_NPB_D */
/* VC5 Non-Posted Buffer Depth */
#define VC5_NPB_D (PRT_LOG_R_BaseAddress + 0xe8)
#define VC5_NPB_D_RegisterSize 32
#define VC5_NPB_D_RegisterResetValue 0x0
#define VC5_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_NPB_D */

/* Register VC5_CB_D */
/* VC5 Completion Buffer Depth */
#define VC5_CB_D (PRT_LOG_R_BaseAddress + 0xec)
#define VC5_CB_D_RegisterSize 32
#define VC5_CB_D_RegisterResetValue 0x0
#define VC5_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC5_CB_D */

/* Register VC6_PB_D */
/* VC6 Posted Buffer Depth */
#define VC6_PB_D (PRT_LOG_R_BaseAddress + 0xf0)
#define VC6_PB_D_RegisterSize 32
#define VC6_PB_D_RegisterResetValue 0x0
#define VC6_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_PB_D */

/* Register VC6_NPB_D */
/* VC6 Non-Posted Buffer Depth */
#define VC6_NPB_D (PRT_LOG_R_BaseAddress + 0xf4)
#define VC6_NPB_D_RegisterSize 32
#define VC6_NPB_D_RegisterResetValue 0x0
#define VC6_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_NPB_D */

/* Register VC6_CB_D */
/* VC6 Completion Buffer Depth */
#define VC6_CB_D (PRT_LOG_R_BaseAddress + 0xf8)
#define VC6_CB_D_RegisterSize 32
#define VC6_CB_D_RegisterResetValue 0x0
#define VC6_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC6_CB_D */

/* Register VC7_PB_D */
/* VC7 Posted Buffer Depth */
#define VC7_PB_D (PRT_LOG_R_BaseAddress + 0xfc)
#define VC7_PB_D_RegisterSize 32
#define VC7_PB_D_RegisterResetValue 0x0
#define VC7_PB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_PB_D */

/* Register VC7_NPB_D */
/* VC7 Non-Posted Buffer Depth */
#define VC7_NPB_D (PRT_LOG_R_BaseAddress + 0x100)
#define VC7_NPB_D_RegisterSize 32
#define VC7_NPB_D_RegisterResetValue 0x0
#define VC7_NPB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_NPB_D */

/* Register VC7_CB_D */
/* VC7 Completion Buffer Depth */
#define VC7_CB_D (PRT_LOG_R_BaseAddress + 0x104)
#define VC7_CB_D_RegisterSize 32
#define VC7_CB_D_RegisterResetValue 0x0
#define VC7_CB_D_RegisterResetMask 0xffffffff

/* End of Register Definition for VC7_CB_D */

/* Register GEN2 */
/* Gen2 */
#define GEN2 (PRT_LOG_R_BaseAddress + 0x10c)
#define GEN2_RegisterSize 32
#define GEN2_RegisterResetValue 0x012c  // DG 0x0
#define GEN2_RegisterResetMask 0xffffffff

/* End of Register Definition for GEN2 */

/* Register PHY_STS_R */
/* PHY Status Register */
#define PHY_STS_R (PRT_LOG_R_BaseAddress + 0x110)
#define PHY_STS_R_RegisterSize 32
#define PHY_STS_R_RegisterResetValue 0x0
#define PHY_STS_R_RegisterResetMask 0xffffffff

/* End of Register Definition for PHY_STS_R */

/* Register PHY_CTRL_R */
/* PHY Control Register */
#define PHY_CTRL_R (PRT_LOG_R_BaseAddress + 0x114)
#define PHY_CTRL_R_RegisterSize 32
#define PHY_CTRL_R_RegisterResetValue 0x0
#define PHY_CTRL_R_RegisterResetMask 0xffffffff

/* End of Register Definition for PHY_CTRL_R */

/* Register MASTER_RES_COM_CTRL0_R */
/* Master Response Composer Control Register 0*/
#define MASTER_RES_COM_CTRL0_R (PRT_LOG_R_BaseAddress + 0x118)
#define MASTER_RES_COM_CTRL0_R_RegisterSize 32
#define MASTER_RES_COM_CTRL0_R_RegisterResetValue 0x0302    // DG 0x0
#define MASTER_RES_COM_CTRL0_R_RegisterResetMask 0xffffffff

/* End of Register Definition for MASTER_RES_COM_CTRL0_R */

/* Register MASTER_RES_COM_CTRL1_R */
/*  ReResponse Composer Control Register 1*/
#define MASTER_RES_COM_CTRL1_R (PRT_LOG_R_BaseAddress + 0x11c)
#define MASTER_RES_COM_CTRL1_R_RegisterSize 32
#define MASTER_RES_COM_CTRL1_R_RegisterResetValue 0x0
#define MASTER_RES_COM_CTRL1_R_RegisterResetMask 0xffffffff

/* End of Register Definition for MASTER_RES_COM_CTRL_R */

#define MSI_R_BaseAddress 0x820
#define MSI_CTRL_ADDR_R (MSI_R_BaseAddress + 0x0)
#define MSI_CTRL_ADDR_R_RegisterSize 32
#define MSI_CTRL_ADDR_R_RegisterResetValue 0x0
#define MSI_CTRL_ADDR_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_UADDR_R (MSI_R_BaseAddress + 0x4)
#define MSI_CTRL_UADDR_R_RegisterSize 32
#define MSI_CTRL_UADDR_R_RegisterResetValue 0x0
#define MSI_CTRL_UADDR_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT0_EN_R (MSI_R_BaseAddress + 0x8)
#define MSI_CTRL_INT0_EN_R_RegisterSize 32
#define MSI_CTRL_INT0_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT0_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT0_MASK_R (MSI_R_BaseAddress + 0xc)
#define MSI_CTRL_INT0_MASK_R_RegisterSize 32
#define MSI_CTRL_INT0_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT0_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT0_STAT_R (MSI_R_BaseAddress + 0x10)
#define MSI_CTRL_INT0_STAT_R_RegisterSize 32
#define MSI_CTRL_INT0_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT0_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT1_EN_R (MSI_R_BaseAddress + 0x14)
#define MSI_CTRL_INT1_EN_R_RegisterSize 32
#define MSI_CTRL_INT1_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT1_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT1_MASK_R (MSI_R_BaseAddress + 0x18)
#define MSI_CTRL_INT1_MASK_R_RegisterSize 32
#define MSI_CTRL_INT1_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT1_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT1_STAT_R (MSI_R_BaseAddress + 0x1c)
#define MSI_CTRL_INT1_STAT_R_RegisterSize 32
#define MSI_CTRL_INT1_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT1_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT2_EN_R (MSI_R_BaseAddress + 0x20)
#define MSI_CTRL_INT2_EN_R_RegisterSize 32
#define MSI_CTRL_INT2_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT2_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT2_MASK_R (MSI_R_BaseAddress + 0x24)
#define MSI_CTRL_INT2_MASK_R_RegisterSize 32
#define MSI_CTRL_INT2_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT2_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT2_STAT_R (MSI_R_BaseAddress + 0x28)
#define MSI_CTRL_INT2_STAT_R_RegisterSize 32
#define MSI_CTRL_INT2_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT2_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT3_EN_R (MSI_R_BaseAddress + 0x2c)
#define MSI_CTRL_INT3_EN_R_RegisterSize 32
#define MSI_CTRL_INT3_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT3_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT3_MASK_R (MSI_R_BaseAddress + 0x30)
#define MSI_CTRL_INT3_MASK_R_RegisterSize 32
#define MSI_CTRL_INT3_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT3_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT3_STAT_R (MSI_R_BaseAddress + 0x34)
#define MSI_CTRL_INT3_STAT_R_RegisterSize 32
#define MSI_CTRL_INT3_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT3_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT4_EN_R (MSI_R_BaseAddress + 0x38)
#define MSI_CTRL_INT4_EN_R_RegisterSize 32
#define MSI_CTRL_INT4_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT4_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT4_MASK_R (MSI_R_BaseAddress + 0x3c)
#define MSI_CTRL_INT4_MASK_R_RegisterSize 32
#define MSI_CTRL_INT4_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT4_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT4_STAT_R (MSI_R_BaseAddress + 0x40)
#define MSI_CTRL_INT4_STAT_R_RegisterSize 32
#define MSI_CTRL_INT4_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT4_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT5_EN_R (MSI_R_BaseAddress + 0x44)
#define MSI_CTRL_INT5_EN_R_RegisterSize 32
#define MSI_CTRL_INT5_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT5_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT5_MASK_R (MSI_R_BaseAddress + 0x48)
#define MSI_CTRL_INT5_MASK_R_RegisterSize 32
#define MSI_CTRL_INT5_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT5_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT5_STAT_R (MSI_R_BaseAddress + 0x4c)
#define MSI_CTRL_INT5_STAT_R_RegisterSize 32
#define MSI_CTRL_INT5_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT5_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT6_EN_R (MSI_R_BaseAddress + 0x50)
#define MSI_CTRL_INT6_EN_R_RegisterSize 32
#define MSI_CTRL_INT6_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT6_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT6_MASK_R (MSI_R_BaseAddress + 0x54)
#define MSI_CTRL_INT6_MASK_R_RegisterSize 32
#define MSI_CTRL_INT6_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT6_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT6_STAT_R (MSI_R_BaseAddress + 0x58)
#define MSI_CTRL_INT6_STAT_R_RegisterSize 32
#define MSI_CTRL_INT6_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT6_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT7_EN_R (MSI_R_BaseAddress + 0x5c)
#define MSI_CTRL_INT7_EN_R_RegisterSize 32
#define MSI_CTRL_INT7_EN_R_RegisterResetValue 0x0
#define MSI_CTRL_INT7_EN_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT7_MASK_R (MSI_R_BaseAddress + 0x60)
#define MSI_CTRL_INT7_MASK_R_RegisterSize 32
#define MSI_CTRL_INT7_MASK_R_RegisterResetValue 0x0
#define MSI_CTRL_INT7_MASK_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_INT7_STAT_R (MSI_R_BaseAddress + 0x64)
#define MSI_CTRL_INT7_STAT_R_RegisterSize 32
#define MSI_CTRL_INT7_STAT_R_RegisterResetValue 0x0
#define MSI_CTRL_INT7_STAT_R_RegisterResetMask 0xffffffff
#define MSI_CTRL_GPIO_R (MSI_R_BaseAddress + 0x68)
#define MSI_CTRL_GPIO_R_RegisterSize 32
#define MSI_CTRL_GPIO_R_RegisterResetValue 0x0
#define MSI_CTRL_GPIO_R_RegisterResetMask 0xffffffff

#define ATU_R_BaseAddress 0x900
#define ATU_VIEWPORT_R (ATU_R_BaseAddress + 0x0)
#define ATU_VIEWPORT_R_RegisterSize 32
#define ATU_VIEWPORT_R_RegisterResetValue 0x0
#define ATU_VIEWPORT_R_RegisterResetMask 0xffffffff
#define ATU_REGION_CTRL1_R (ATU_R_BaseAddress + 0x4)
#define ATU_REGION_CTRL1_R_RegisterSize 32
#define ATU_REGION_CTRL1_R_RegisterResetValue 0x0
#define ATU_REGION_CTRL1_R_RegisterResetMask 0xffffffff
#define ATU_REGION_CTRL2_R (ATU_R_BaseAddress + 0x8)
#define ATU_REGION_CTRL2_R_RegisterSize 32
#define ATU_REGION_CTRL2_R_RegisterResetValue 0x0
#define ATU_REGION_CTRL2_R_RegisterResetMask 0xffffffff
#define ATU_REGION_LOWBASE_R (ATU_R_BaseAddress + 0xc)
#define ATU_REGION_LOWBASE_R_RegisterSize 32
#define ATU_REGION_LOWBASE_R_RegisterResetValue 0x0
#define ATU_REGION_LOWBASE_R_RegisterResetMask 0xffffffff
#define ATU_REGION_UPBASE_R (ATU_R_BaseAddress + 0x10)
#define ATU_REGION_UPBASE_R_RegisterSize 32
#define ATU_REGION_UPBASE_R_RegisterResetValue 0x0
#define ATU_REGION_UPBASE_R_RegisterResetMask 0xffffffff
#define ATU_REGION_LIMIT_ADDR_R (ATU_R_BaseAddress + 0x14)
#define ATU_REGION_LIMIT_ADDR_R_RegisterSize 32
#define ATU_REGION_LIMIT_ADDR_R_RegisterResetValue 0xffff   // DG 0x0
#define ATU_REGION_LIMIT_ADDR_R_RegisterResetMask 0xffffffff
#define ATU_REGION_LOW_TRGT_ADDR_R (ATU_R_BaseAddress + 0x18)
#define ATU_REGION_LOW_TRGT_ADDR_R_RegisterSize 32
#define ATU_REGION_LOW_TRGT_ADDR_R_RegisterResetValue 0x0
#define ATU_REGION_LOW_TRGT_ADDR_R_RegisterResetMask 0xffffffff
#define ATU_REGION_UP_TRGT_ADDR_R (ATU_R_BaseAddress + 0x1c)
#define ATU_REGION_UP_TRGT_ADDR_R_RegisterSize 32
#define ATU_REGION_UP_TRGT_ADDR_R_RegisterResetValue 0x0
#define ATU_REGION_UP_TRGT_ADDR_R_RegisterResetMask 0xffffffff

/*****************************************************************/
// phy control bus bit definition
#define PCIE_CR_CTL_DATA_LOC 0
#define PCIE_CR_CTL_CAP_ADR_LOC 16
#define PCIE_CR_CTL_CAP_DAT_LOC 17
#define PCIE_CR_CTL_WR_LOC 18
#define PCIE_CR_CTL_RD_LOC 19
#define PCIE_CR_STAT_DATA_LOC 0
#define PCIE_CR_STAT_ACK_LOC 16

#endif //__PCI_REGS_H__
