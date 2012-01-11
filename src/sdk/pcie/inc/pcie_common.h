/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PCIE_COMMON_H__
#define __PCIE_COMMON_H__

#include "io.h"
#include "../inc/pcie_regs.h"
#include "../inc/pcie_phy_regs.h"

#define SZ_1K	0x400
#define SZ_2K	0x800
#define SZ_4K	0x1000
#define SZ_8K	0x2000
#define SZ_16K	0x4000
#define SZ_32K	0x8000
#define SZ_64K	0x10000

#define PCIE_DBI_BASE_ADDR 		0x01FFC000
#define PCIE_DBI_ADDR_END		0x01FFFFFF
#define PCIE_ARB_BASE_ADDR		0x01000000
#define PCIE_ARB_ADDR_END		0x01FFBFFF

typedef struct {
    uint32_t addr;              // field register address 
    uint32_t mask;              // field mask
    uint32_t offset;            //field offset
} pcie_iomux_gpr_field_t, *pcie_iomux_gpr_field_p;

typedef enum {
    apps_pm_xmt_pme,
    device_type,
    diag_status_bus_select,
    sys_int,
    apps_pm_xmt_turnoff,
    app_ltssm_enable,
    app_init_rst,
    ref_ssp_en,
    diag_ctrl_bus,
    app_req_entr_l1,
    app_ready_entr_l23,
    app_req_exit_l1,
    app_clk_req_n,
    cfg_l1_clk_removal_en,
    phy_test_powerdown,
    los_level,
    tx_deemph_gen1,
    tx_deemph_gen2_3p5db,
    tx_deemph_gen2_6db,
    tx_swing_full,
    tx_swing_low
} pcie_iomux_gpr_field_type_e;

typedef enum {
    TLP_TYPE_MemRdWr = 0,
    TLP_TYPE_MemRdLk = 1,
    TLP_TYPE_IORdWr = 2,
    TLP_TYPE_CfgRdWr0 = 4,
    TLP_TYPE_CfgRdWr1 = 5
} pcie_tlp_type_e;

typedef enum {
    PCIE_IATU_VP_DIR_INBOUND,
    PCIE_IATU_VP_DIR_OUTBOUND,
    PCIE_IATU_VP_DIR_MAX,
} pcie_iatu_vp_dir_e;

typedef enum {
    PCIE_IATU_VIEWPORT_0,
    PCIE_IATU_VIEWPORT_1,
    PCIE_IATU_VIEWPORT_2,
    PCIE_IATU_VIEWPORT_3,

    PCIE_IATU_VIEWPORT_MAX,
} pcie_iatu_vp_e;

typedef enum {
    NO_LINK,
    GEN1_LINK,
    GEN2_LINK,
    GEN3_LINK,
} pcie_link_type_e;

typedef enum {
    CONFIG_HEADER_TYPE0,
    CONFIG_HEADER_TYPE1,
} pcie_config_header_type_e;

typedef enum {
    PCIE_DM_MODE_EP = 0,
    PCIE_DM_MODE_RC = 0x4,
} pcie_dm_mode_e;

typedef enum {
    PCIE_SPACE_TYPE_CFG,
    PCIE_SPACE_TYPE_MEM,
    PCIE_SPACE_TYPE_IO,
} pcie_space_type_e;

typedef enum {
    PCIE_MEM_PROT_BIT_32 = 0x00 << 1,
    PCIE_MEM_PROT_BIT_64 = 0x10 << 1,
    PCIE_MEM_PROT_PREFETCH_YES = 0x01 << 3,
    PCIE_MEM_PROT_PREFETCH_NO = 0x00 << 3,
} pcie_space_prot_e;

int pcie_init(pcie_dm_mode_e dev_mode);
uint32_t pcie_map_space(uint32_t viewport,
                        uint32_t tlp_type,
                        uint32_t addr_base_cpu_side, uint32_t addr_base_pcie_side, uint32_t size);

#endif // PCIE_H
