/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vpu_test.h"
#include "vpu_debug.h"

extern RtStatus_t Fread_multi_sectors(int32_t, uint8_t *, int32_t);

int32_t vpu_stream_read(struct cmd_line *cmd, char *buf, int32_t n)
{
    if (cmd->src_scheme == PATH_MEM) {
        int32_t bs_left = (bsmem.bs_end - bsmem.bs_start) - bsmem.bs_offset;
        int32_t copy_size = (bs_left > n) ? n : bs_left;
        /*bitstream is stored in memory */
        memcpy(buf, (void *)(bsmem.bs_start + bsmem.bs_offset), copy_size);
        bsmem.bs_offset += copy_size;
        return copy_size;
    } else if (cmd->src_scheme == PATH_FILE) {
        int32_t res, i;

        /* if SD is currently busy, it means that the other video instance has requested a buffer fill, */
        /* return without doing anything, the video driver will request a buffer fill again next frame */
        int usdhc_status = 0;
        card_xfer_result(SD_PORT_BASE_ADDR, &usdhc_status);
        if (usdhc_status != 1)
            return -1;          //now SD card is busy
        res = Fread_FAT(cmd->input, (uint8_t *) buf, n);

        if (res < n) {
            for (i = 0; i < (n - res); i++)
                reg8_write(buf + res + i, 0x0);
        }

        return res;
    }
    return 0;

}

int32_t vpu_stream_write(struct cmd_line *cmd, char *buf, int32_t n)
{
    if (cmd->dst_scheme == PATH_MEM) {
        memcpy((void *)bsmem.bs_end, buf, n);
        bsmem.bs_end += n;
    } else if (cmd->dst_scheme == PATH_FILE) {
        /*TBD, currently the file storage is not supported in the file system */
    }
    return n;
}

int32_t ipu_refresh(uint32_t ipu_index, uint32_t buffer)
{
    ipu_dma_update_buffer(ipu_index, 23, 0, buffer);
    ipu_channel_buf_ready(ipu_index, 23, 0);
    return 0;
}

void config_system_parameters(void)
{
    /* set AxCACHE bits for IPU/VPU/VDOA */
    reg32_write(IOMUXC_GPR4, reg32_read(IOMUXC_GPR4) | 0xFF0000CF);

    /* increase QoS for IPUs, id 0 */
    reg32_write(IOMUXC_GPR6, 0x22272227);
    reg32_write(IOMUXC_GPR7, 0x22272227);
}

#ifdef __NOT_USED__
int32_t video_data_cmp(unsigned char *src, unsigned char *dst, int32_t size)
{
    int32_t i = 0;
    for (i = 0; i < size; i++) {
        if (src[i] != dst[i]) {
            err_msg("comparision failed at %d\n", i);
            return -1;
        }
    }
    return 0;
}

static vpu_frame_timer_t vtimer = { 0 };

void epit2_config(void)
{
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x10000);
    while (reg32_read(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET) & 0x10000) ;

    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITLR_OFFSET, 0xFFFFFFFF);  //30fps
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000e);
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000f);
    vtimer.timer_start = reg32_read(EPIT2_BASE_ADDR + EPIT_EPITCNR_OFFSET);
}

int32_t get_timer_stamp(int32_t periodic)
{
    uint32_t val = reg32_read(EPIT2_BASE_ADDR + EPIT_EPITCNR_OFFSET);
    if (val < vtimer.timer_start) {
        vtimer.timer_elapsed_ms = (vtimer.timer_start - val) / 32;
    } else {
        vtimer.timer_elapsed_ms = ((0xFFFFFFFF - val + vtimer.timer_start)) / 32;
    }

    if (vtimer.timer_elapsed_ms >= 1000 / periodic) {
        vtimer.timer_start = val;
        return 1;
    } else {
        return 0;
    }
}
#endif
