/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PCIE_PROT__
#define __PCIE_PROT__

#include "io.h"

typedef struct {
    uint16_t vendor_id;
    uint16_t dev_id;

    uint16_t cmd;
    uint16_t status;

    uint8_t rev_id;
    uint8_t cls_id[3];

    uint8_t cache_line_size;
    uint8_t latency_timer;
    uint8_t hdr_type;
    uint8_t bist;

    uint32_t bar0;
    uint32_t bar1;
    uint32_t bar2;
    uint32_t bar3;
    uint32_t bar4;
    uint32_t bar5;
    uint32_t cardbus_cis_ptr;

    uint16_t subsys_vendor_id;
    uint16_t sybsys_id;

    uint32_t exp_rom_base;

    uint8_t cap_ptr;
    uint8_t rsv0[3];

    uint8_t rsv1[4];

    uint8_t interrupt_line;
    uint8_t interrupt_pin;
    uint8_t min_grant;
    uint8_t max_latency;
} __attribute__ ((packed)) pcie_cfg_hdr_type0_t, *pcie_cfg_hdr_type0_p;

typedef struct {
    uint16_t vendor_id;
    uint16_t dev_id;

    uint16_t cmd;
    uint16_t status;

    uint8_t rev_id;
    uint8_t cls_id[3];

    uint8_t cache_line_size;
    uint8_t latency_timer;
    uint8_t hdr_type;
    uint8_t bist;

    uint32_t bar0;
    uint32_t bar1;

    uint8_t primary_bus;
    uint8_t snd_pus;
    uint8_t sub_bus;
    uint8_t snd_latency_timer;

    uint8_t io_base;
    uint8_t io_limit;
    uint16_t snd_status;

    uint16_t mem_base;
    uint16_t mem_limit;

    uint16_t prefetch_mem_base;
    uint16_t prefetch_mem_limit;

    uint32_t prefetch_base_upper;
    uint32_t prefetch_limit_upper;

    uint8_t cap_ptr;
    uint8_t rsv0[3];

    uint32_t exp_rom_base;

    uint8_t interrupt_line;
    uint8_t interrupt_pin;
    uint16_t bridge_ctrl;
} __attribute__ ((packed)) pcie_cfg_hdr_type1_t, *pcie_cfg_hdr_type1_p;

typedef enum {
    RESOURCE_TYPE_IO,
    RESOURCE_TYPE_MEM,
    RESOURCE_TYPE_INIT,
} resource_type_e;

typedef enum {
    PCIE_BAR_0,
    PCIE_BAR_1,
    PCIE_BAR_2,
    PCIE_BAR_3,
    PCIE_BAR_4,
    PCIE_BAR_5,
} pcie_bar_e;

typedef struct {
    pcie_bar_e bar;
    resource_type_e type;
    uint32_t base;
    uint32_t size;
} pcie_resource_t, *pcie_resource_p;

int pcie_dump_cfg_header(uint32_t * header_base);
int pcie_enum_resources(uint32_t * header_base, pcie_resource_t res[], uint32_t * num);
uint32_t pcie_cfg_ep_bar(uint32_t header_base, uint32_t bar, uint32_t base, uint32_t base_msk);

#endif
