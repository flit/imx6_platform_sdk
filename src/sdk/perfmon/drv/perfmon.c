/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "perfmon.h"

int perfmon_start(uint32_t base, uint32_t mid, perfmon_trans_e trans)
{
    reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_SFTRST | BM_PERFMON_CTRL_CLKGATE);

    /* clear all counters */
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_CLR);
    while (reg32_read(base + HW_PERFMON_CTRL) & BM_PERFMON_CTRL_CLR) ;

    /* set the monitored direction */
    if (trans == PERFMON_TRANS_READ)
        reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_READ_EN);
    else
        reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_READ_EN);

    // set MID to profile
    reg32_write(base + HW_PERFMON_MASTER_EN, mid & 0xFFFF);

    // run 
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_RUN);

    return 0;
}

int perfmon_stop(uint32_t base, perfmon_res_p res)
{
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_SNAP);
    while (reg32_read(base + HW_PERFMON_CTRL) & BM_PERFMON_CTRL_SNAP) ;

    res->total_active_cycle = reg32_read(base + HW_PERFMON_ACTIVE_CYCLE);
    res->total_trans = reg32_read(base + HW_PERFMON_TRANSFER_COUNT);
    res->total_datas = reg32_read(base + HW_PERFMON_DATA_COUNT);
    res->max_latency.u = reg32_read(base + HW_PERFMON_MAX_LATENCY);
    res->total_lat_cnt = reg32_read(base + HW_PERFMON_TOTAL_LATENCY);

    reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_RUN);
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_CLKGATE);

    return 0;
}

void perfmon_init(uint32_t base)
{
    /* mysterious undefined bit */
    writel(0x10000, IOMUXC_GPR11);

    clock_gating_config(PERFMON3_BASE_ADDR, CLOCK_ON);

    return;
}
