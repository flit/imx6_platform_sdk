/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IPS_TEST__
#define __IPS_TEST__

#include "hardware.h"
#include "ipu_common.h"

#define MEM_PRO_UNCACHEABLE
#define MEM_PRO_UNBUFFERABEL

/*This macro do nothing because the the mmu and cache has beed disabled*/
#define MEM_VIRTUAL_2_PHYSICAL(addr,size,pro)

typedef struct {
    const char *name;
    int (*test) (ips_dev_panel_t *);
} ipu_test_t;

int ips_display_test(ips_dev_panel_t * panel);
int ips_csc_test(ips_dev_panel_t * panel);
int ips_combiner_test(ips_dev_panel_t * panel);
int ips_rotate_test(ips_dev_panel_t * panel);
int ips_resize_test(ips_dev_panel_t * panel);

#endif
