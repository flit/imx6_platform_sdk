/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include <stdio.h>
#include "hardware.h"

#define PERFMON_TEST_BUF_SIZE   4096
#define LOW_OFFSET_TRAP_TEST   PERFMON_TEST_BUF_SIZE / 2
#define HIGH_OFFSET_TRAP_TEST  PERFMON_TEST_BUF_SIZE

#define MEM_WRITE           0x00
#define MEM_WRITE_AND_TRAP  0x0F
#define MEM_WRITE_AND_LATT  0xFF

static void monitor_memory_write(uint8_t test_mode);

/*!
 * Performance monitor unit test.
 *
 * @return  0
 */
int32_t perfmon_test(void)
{
    uint8_t sel;

    printf("Start performance monitor unit tests:");

    do {
        printf("\n  To monitor the performances of:\n");
        printf("  1 - a core memory write.\n");
        printf("  2 - a core memory write with address trap mode enabled.\n");
        printf("  3 - a core memory write with latency threshold enabled.\n");
        printf("  x - to exit.\n\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        if (sel == '1')
            monitor_memory_write(MEM_WRITE);
        if (sel == '2')
            monitor_memory_write(MEM_WRITE_AND_TRAP);
        if (sel == '3')
            monitor_memory_write(MEM_WRITE_AND_LATT);

    } while(1);

    return 0;
}

void monitor_memory_write(uint8_t test_mode)
{
    perfmon_res_t res, res_end;
    uint32_t i, *perfmon_test_buffer;
#ifdef bla
//    .macro disable_L1_cache
    __asm(
        "mrc p15, 0, r0, c1, c0, 0;"
        "bic r0, r0, #(0x1<<12);"
        "bic r0, r0, #(0x1<<11);"
        "bic r0, r0, #(0x1<<2);"
        "bic r0, r0, #(0x1<<0);"
        "mcr p15, 0, r0, c1, c0, 0;"
        );

//    .macro disable_L2_cache
    __asm(
        "ldr     r1, =0x00A02100;"
        "mov     r0,#0;"
        "str     r0,[r1];"
        );
#endif
    perfmon_test_buffer = malloc(PERFMON_TEST_BUF_SIZE*sizeof(uint32_t));

    /* initialize the performance monitor 3 to observe cores transfers */
    perfmon_open(PERFMON_ID3);

    if(test_mode == MEM_WRITE_AND_LATT)
    {
    /* program the perfmon to generate an interrupt
     *  when max latency reaches 3.
     */
        perfmon_set_latency_mode(PERFMON_ID3, 2);
    }

    if(test_mode == MEM_WRITE_AND_TRAP)
    {
    /* program the perfmon to generate an interrupt
     *  when address goes outside
     *  perfmon_test_buffer -> perfmon_test_buffer+512.
     */
        perfmon_set_trap_mode(PERFMON_ID3,
                             (uint32_t) (perfmon_test_buffer + LOW_OFFSET_TRAP_TEST),
                             (uint32_t)(perfmon_test_buffer + HIGH_OFFSET_TRAP_TEST),
                             IN_RANGE);
     }

    /* start the monitoring */
    perfmon_start(PERFMON_ID3, PERFMON_MID0, WRITE_TRANS);

    /* do the memory write */
    for (i = 0; i < PERFMON_TEST_BUF_SIZE; i++) {
    perfmon_test_buffer[i] = (uint32_t) &perfmon_test_buffer[i];
    }

    /* get the monitored result when the interrupt occurred...
     * if it did.
     */
    perfmon_get_performance(PERFMON_ID3, &res, FALSE, FALSE);

    /* stop the monitoring and get the final result */
    perfmon_stop(PERFMON_ID3, &res_end);

    free(perfmon_test_buffer);

    if(res.status & TRAP_EVENT)
    {
        printf("An address trap event occurred in\n");
        printf("0x%X -> 0x%X\n",(uint32_t) (perfmon_test_buffer + LOW_OFFSET_TRAP_TEST),
              (uint32_t)(perfmon_test_buffer + HIGH_OFFSET_TRAP_TEST));
    }
    if(res.status & LATENCY_EVENT)
        printf("A latency threshold event occurred.\n");
    if(res.status & (TRAP_EVENT | LATENCY_EVENT))
    {
        printf("Monitored results captured during that event:\n");
        printf("\tActive cycle: %d\n", res.total_active_cycle);
        printf("\tTotal transaction: %d\n", res.total_trans);
        printf("\tTotal data: %d\n", res.total_data);
        printf("\tTotal latency: %d\n", res.total_lat_cnt);
        printf("\tMax latency: %d\n", res.max_latency.fields.count);
    }

    printf("Monitored results at the end:\n");
    printf("\tActive cycle: %d\n", res_end.total_active_cycle);
    printf("\tTotal transaction: %d\n", res_end.total_trans);
    printf("\tTotal data: %d\n", res_end.total_data);
    printf("\tTotal latency: %d\n", res_end.total_lat_cnt);
    printf("\tMax latency: %d\n", res_end.max_latency.fields.count);

    perfmon_close(PERFMON_ID3);

    return;
}
