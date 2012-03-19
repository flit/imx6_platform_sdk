/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "sdma/inc/sdma.h"
#include "sdma_test.h"
#include "hardware.h"

#define MEM2MEM_TEST_BUF_SZ 		1024*8

/* Uncacheable & unbufferable area startes */
static unsigned int src_buf[2][MEM2MEM_TEST_BUF_SZ];
static unsigned int dst_buf[2][MEM2MEM_TEST_BUF_SZ];

static sdma_bd_t bd[2];
static char env_buffer[SDMA_ENV_BUF_SIZE];
/* Uncacheable & unbufferable area endes */

int mem_2_mem_test(void)
{
    int idx, channel;
    sdma_chan_desc_t chan_desc;

    printf("Memory to memory test starts.\n");

    MEM_VIRTUAL_2_PHYSICAL(src_buf, sizeof(src_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(dst_buf, sizeof(dst_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(env_buf, sizeof(env_buffer), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(bd, sizeof(bd), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);

    /* Initialize buffer for testing */
    memset(src_buf[0], 0x5A, MEM2MEM_TEST_BUF_SZ * 4);
    memset(src_buf[1], 0xA5, MEM2MEM_TEST_BUF_SZ * 4);

    memset(dst_buf[0], 0x00, MEM2MEM_TEST_BUF_SZ * 4);
    memset(dst_buf[1], 0x00, MEM2MEM_TEST_BUF_SZ * 4);

    /* Initialize SDMA */
    printf("Initialize SDMA environment.\n");
    if (SDMA_RETV_SUCCESS != sdma_init((unsigned int *)env_buffer, SDMA_IPS_HOST_BASE_ADDR)) {
        printf("SDMA initialization failed.\n");
        return FALSE;
    }

    unsigned int script_addr;
    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_AP_2_AP, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }
    chan_desc.script_addr = script_addr;
    chan_desc.dma_mask[0] = chan_desc.dma_mask[1] = 0;
    chan_desc.priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc.gpr[idx] = 0;
    }

    /* Setup buffer descriptors */
    bd[0].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_CONT | (MEM2MEM_TEST_BUF_SZ << 2);
    bd[0].buf_addr = (unsigned int)src_buf[0];
    bd[0].ext_buf_addr = (unsigned int)dst_buf[0];

    bd[1].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | (MEM2MEM_TEST_BUF_SZ << 2);
    bd[1].buf_addr = (unsigned int)src_buf[1];
    bd[1].ext_buf_addr = (unsigned int)dst_buf[1];

    /* Open channel */
    printf("Open SDMA channel for transfer.\n");
    channel = sdma_channel_request(&chan_desc, (sdma_bd_p) bd);
    if (channel < 0) {
        printf("Channel open failed.\n");
        return FALSE;
    }

    /* Start channel */
    printf("Channel %d opened, starting transfer...\n", channel);
    sdma_channel_start(channel);

    unsigned int perf_cnt = 0;

    StartPerfCounter();
    /* Wait channel stop */
    unsigned int status;
    do {
        sdma_channel_status(channel, &status);
    } while (!(status & SDMA_CHANNEL_STATUS_DONE));
    perf_cnt = StopPerfCounter();

    float interval = ((float)(perf_cnt)) / ((float)GetCPUFreq());
    float speed = (float)(MEM2MEM_TEST_BUF_SZ * 2 * 4) / 1024.0f / interval;
    printf("mem-2-mem speed: %d KB/s\n", (int)speed);

    /* Stop channel */
    printf("Transfer completed. Stop channel.\n");
    sdma_channel_stop(channel);
    sdma_channel_release(channel);
    sdma_deinit();

    /* Check data transfered */
    printf("Verify data transfered.\n");
    for (idx = 0; idx < MEM2MEM_TEST_BUF_SZ; idx++) {
        if (src_buf[0][idx] != dst_buf[0][idx]) {
            printf("Word %d mismatch: 0x%x, 0x%x\n", idx + 1, src_buf[0][idx], dst_buf[0][idx]);
            return FALSE;
        }

        if (src_buf[1][idx] != dst_buf[1][idx]) {
            printf("Word %d mismatch: 0x%x, 0x%x\n", idx + 1, src_buf[1][idx], dst_buf[1][idx]);
            return FALSE;
        }
    }

    return TRUE;
}
