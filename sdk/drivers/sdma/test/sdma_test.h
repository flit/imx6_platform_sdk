/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __SDMA_TEST__
#define __SDMA_TEST__

#include "hardware.h"

#define MEM_PRO_UNCACHEABLE
#define MEM_PRO_UNBUFFERABEL

/*This macro do nothing because the mmu and cache have been disabled*/
#define MEM_VIRTUAL_2_PHYSICAL(addr,size,pro)

typedef struct {
    const char *name;
    int (*test) (void);
} sdma_test_t;

extern int mem_2_mem_test(void);
extern int ecspi_shp_test(void);
extern int ecspi_app_test(void);
extern int uart_app_test(void);
extern int uart_shp_test(void);
extern int uart_app_interrupt_test(void);
#endif
