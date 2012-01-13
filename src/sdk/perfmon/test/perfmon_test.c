/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include <stdio.h>
#include "io.h"
#include "soc_memory_map.h"
#include "../inc/perfmon.h"

#define ARRAY_SIZE(x)	(sizeof(x)/sizeof((x)[0]))

#define PERFMON_TEST_BUF_SIZE	0x1000

extern int perfmon_clk_cfg(uint32_t base, uint32_t enable);
/* The buffer is supposed to be in DDR and un-cacheable*/
static uint32_t perfmon_test_buffer[PERFMON_TEST_BUF_SIZE];

int perfmon_test(void)
{
    perfmon_res_t res;
    uint32_t i, *ptr;
    uint8_t ch;

    ptr = perfmon_test_buffer;
    printf("Perfmon test. Press \"y\" or \"Y\" to continue.\n");

    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);
    if ((ch != 'y') && (ch != 'Y'))
        return -1;

    perfmon_clk_cfg(IP2APB_PERFMON3_BASE_ADDR, 1);

    perfmon_start(IP2APB_PERFMON3_BASE_ADDR, PERFMON_MID0,  //| PERFMON_MID1 | PERFMON_MID2 | PERFMON_MID3, 
                  PERFMON_TRANS_WRITE);

    for (i = 0; i < ARRAY_SIZE(perfmon_test_buffer); i++, ptr++) {
        *ptr = (uint32_t) ptr;
    }

    perfmon_stop(IP2APB_PERFMON3_BASE_ADDR, &res);

    printf("Dump the perfmon result:\n");
    printf("\tActive cycle: %d\n", res.total_active_cycle);
    printf("\tTotal transaction: %d\n", res.total_trans);
    printf("\tTotal data: %d\n", res.total_datas);
    printf("\tTotal latency: %d\n", res.total_lat_cnt);
    printf("\tMax latency: 0x%08x\n", res.max_latency.u);

    return 0;
}
