/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PERFMON_IMX_H__
#define	__PERFMON_IMX_H__

#include "soc_memory_map.h"
#include "irq_numbers.h"

/* Number of performance monitors used in the i.MX6 */
#define PERFMON_INST 3

typedef enum {
    PERFMON_ID1,
    PERFMON_ID2,
    PERFMON_ID3,
} perfmon_id_e;

typedef struct {
    uint32_t base;      /* module base address */
    uint32_t irq_id;    /* ID of its interrupt */
} perfmon_param;

/* used to list the instances of performance monitors */
static const perfmon_param perfmon_list[PERFMON_INST] = {
        {PERFMON1_BASE_ADDR, IMX_INT_PERFMON1},
        {PERFMON2_BASE_ADDR, IMX_INT_PERFMON2},
        {PERFMON3_BASE_ADDR, IMX_INT_PERFMON3},
};

#endif /* __PERFMON_IMX_H__ */
