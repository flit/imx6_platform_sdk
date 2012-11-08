/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vpu_test.h"
#include "vpu/vpu_debug.h"

int32_t vpu_stream_read(struct codec_control *cmd, char *buf, int32_t n)
{
    if (cmd->src_scheme == PATH_MEM) {
        int32_t bs_left = (g_bs_memory.bs_end - g_bs_memory.bs_start) - g_bs_memory.bs_offset;
        int32_t copy_size = (bs_left > n) ? n : bs_left;
        /*bitstream is stored in memory */
        memcpy(buf, (void *)(g_bs_memory.bs_start + g_bs_memory.bs_offset), copy_size);
        g_bs_memory.bs_offset += copy_size;
        return copy_size;
    } else if (cmd->src_scheme == PATH_FILE) {
        int32_t res;

        /* if SD is currently busy, it means that the other video instance has requested a buffer fill, */
        /* return without doing anything, the video driver will request a buffer fill again next frame */
        int usdhc_status = 0;
        card_xfer_result(g_usdhc_instance, &usdhc_status);
        if (usdhc_status != 1)
            return -1;          //now SD card is busy
        res = Fread_FAT(cmd->input, (uint8_t *) buf, n);
        if (res < n) {
            memset(buf + res, 0x0, n - res);
            if (cmd->read_mode == ENDLESS_LOOP_PLAY)
                Fseek(cmd->input, 0, 0);    //seek to start
        }

        return res;
    }
    return 0;

}

int32_t vpu_stream_write(struct codec_control * cmd, char *buf, int32_t n)
{
    if (cmd->dst_scheme == PATH_MEM) {
        memcpy((void *)g_bs_memory.bs_end, buf, n);
        g_bs_memory.bs_end += n;
    } else if (cmd->dst_scheme == PATH_FILE) {
        Fwrite_FAT(cmd->output, (uint8_t *) buf, n);
    }
    return n;
}

int32_t ipu_render_refresh(uint32_t ipu_index, uint32_t buffer)
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
