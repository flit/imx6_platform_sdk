/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "../inc/pcie_common.h"
#include "../inc/pcie_prot.h"

#define FIELD_OFFSET(type, fld)	((uint32_t)(&(((type*)0)->fld)))
#define FIELD_ADDRESS(var, type, fld)	((uint32_t)(&var + FIELD_OFFSET))

static int pcie_dump_cfg_hdr_type0(pcie_cfg_hdr_type0_p header)
{
    printf("Vendor ID: 0x%04x\n", header->vendor_id);
    printf("Device ID: 0x%04x\n", header->dev_id);
    printf("Header Type: %d\n", header->hdr_type);
    printf("BAR0: 0x%08x\n", header->bar0);
    printf("BAR1: 0x%08x\n", header->bar1);
    printf("BAR2: 0x%08x\n", header->bar2);
    printf("BAR3: 0x%08x\n", header->bar3);
    printf("BAR4: 0x%08x\n", header->bar4);
    printf("BAR5: 0x%08x\n", header->bar5);

    return 0;
}

static int pcie_dump_cfg_hdr_type1(pcie_cfg_hdr_type1_p header)
{
    printf("Vendor ID: 0x%04x\n", header->vendor_id);
    printf("Device ID: 0x%04x\n", header->dev_id);
    printf("Header Type: %d\n", header->hdr_type);
    printf("BAR0: 0x%08x\n", header->bar0);
    printf("BAR1: 0x%08x\n", header->bar1);

    return 0;
}

int pcie_dump_cfg_header(uint32_t * header_base)
{
    pcie_cfg_hdr_type0_p tmp_hdr = (pcie_cfg_hdr_type0_p) header_base;

    if (tmp_hdr->hdr_type == 0x00) {
        pcie_dump_cfg_hdr_type0(tmp_hdr);
    } else if (tmp_hdr->hdr_type == 0x01) {
        pcie_dump_cfg_hdr_type1((pcie_cfg_hdr_type1_p) header_base);
    } else {
        return -1;
    }

    return 0;
}

int pcie_enum_resources(uint32_t * header_base, pcie_resource_t res[], uint32_t * num)
{
    uint32_t index = 0, i, j, size, tmp_val;
    pcie_cfg_hdr_type0_p tmp_hdr = (pcie_cfg_hdr_type0_p) header_base;
    uint32_t bar_off = FIELD_OFFSET(pcie_cfg_hdr_type0_t, bar0);
    volatile uint32_t *bar = (uint32_t *) ((uint32_t) header_base + bar_off);

    if (tmp_hdr->hdr_type == 0x00) {
        for (i = 0; i < *num; i++, bar++) {
            size = 0;
            *bar = 0xFFFFFFFF;
            tmp_val = *bar;
            if (0 != tmp_val) {
                res[index].bar = i;
                if (tmp_val & 0x01) {
                    res[index].type = RESOURCE_TYPE_IO;
                    j = 2;
                } else {
                    res[index].type = RESOURCE_TYPE_MEM;
                    j = 4;
                }
                for (; j < 32; j++) {
                    if (tmp_val & (0x01 << j))
                        break;
                }
                res[index].size = 0x01 << j;

                index++;
            }
        }
    }

    *num = index;

    return 0;
}

uint32_t pcie_cfg_ep_bar(uint32_t header_base, uint32_t bar, uint32_t base, uint32_t base_msk)
{
    uint32_t bar_off = FIELD_OFFSET(pcie_cfg_hdr_type0_t, bar0);
    volatile uint32_t *bar_ptr = (uint32_t *) ((uint32_t) header_base + bar_off);

    bar_ptr += bar;

    *bar_ptr = (base & base_msk);

    return (base & base_msk);
}
