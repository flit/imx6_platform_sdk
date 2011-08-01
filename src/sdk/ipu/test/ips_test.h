/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IPS_TEST__
#define __IPS_TEST__

#include "io.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define MEM_PRO_UNCACHEABLE
#define MEM_PRO_UNBUFFERABEL

/*This macro do nothing because the the mmu and cache has beed disabled*/
#define MEM_VIRTUAL_2_PHYSICAL(addr,size,pro)

typedef struct {
    const char *name;
    int (*test) (void);
} ipu_test_t;

extern int ips_display_test(void);
#endif
