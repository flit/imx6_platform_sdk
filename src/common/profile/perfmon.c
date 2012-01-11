/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "io.h"
#include "soc_memory_map.h"
#include "perfmon.h"

int perfmon_start(uint32_t base, uint32_t mid, perfmon_trans_e trans)
{
    reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_SFTRST | BM_PERFMON_CTRL_CLKGATE);

    // clear all counters
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_CLR);
    while (reg32_read(base + HW_PERFMON_CTRL) & BM_PERFMON_CTRL_CLR) ;

    if (PERFMON_TRANS_READ == trans) {
        reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_READ_EN);
    } else {
        reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_READ_EN);
    }
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

    res->total_trans = reg32_read(base + HW_PERFMON_TRANSFER_COUNT);
    res->total_datas = reg32_read(base + HW_PERFMON_DATA_COUNT);
    res->max_latency.u = reg32_read(base + HW_PERFMON_MAX_LATENCY);
    res->total_lat_cnt = reg32_read(base + HW_PERFMON_TOTAL_LATENCY);

    reg32_write(base + HW_PERFMON_CTRL_CLR, BM_PERFMON_CTRL_RUN);
    reg32_write(base + HW_PERFMON_CTRL_SET, BM_PERFMON_CTRL_CLKGATE);

    return 0;
}

/* 
 * All the routines and variables are platform specific. They will be 
 * moved to somewhere else.
 */
#define TEST_PERFMON	0
#if TEST_PERFMON
typedef enum {
    MASTER_GPU3D_M_B_0,
    MASTER_GPU2D_M_B_0,
    MASTER_VDOA_M_B_2,
    MASTER_M_C,
    MASTER_OPENVG,
    MASTER_CORES,
    MASTER_GPU,

    MASTER_MAX,
} master_to_prof_e;

typedef struct {
    char *name;
    uint32_t master_to_prof;
    uint32_t perfmon;
    uint32_t mid;
    uint32_t mux;
    void (*mux_func) (uint32_t perfmon, uint32_t mux);
} perfmon_plt_data_t, *perfmon_plt_data_p;

extern int perfmon_clk_cfg(uint32_t base, uint32_t enable);
int perfmon_test(void)
{
    perfmon_res_t res;
    uint32_t i, *ptr;
    uint8_t ch;

    ptr = (uint32_t *) 0x88000000;
    printf("Perfmon test. Press \"y\" or \"Y\" to continue.\n");

    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);
    if ((ch != 'y') && (ch != 'Y'))
        return -1;

    perfmon_clk_cfg(IP2APB_PERFMON3_BASE_ADDR, 1);

    perfmon_start(IP2APB_PERFMON3_BASE_ADDR, PERFMON_MID0,  //| PERFMON_MID1 | PERFMON_MID2 | PERFMON_MID3, 
                  PERFMON_TRANS_WRITE);

    for (i = 0; i < 1024; i++, ptr++) {
        *ptr = (uint32_t) ptr;
    }

    perfmon_stop(IP2APB_PERFMON3_BASE_ADDR, &res);

    printf("Dump the perfmon result:\n");
    printf("\tTotally transaction: %d\n", res.total_trans);
    printf("\tTotal data: %d\n", res.total_datas);
    printf("\tTotal latency: %d\n", res.total_lat_cnt);
    printf("\tMax latency: 0x%08x\n", res.max_latency.u);

    return 0;
}
#endif
