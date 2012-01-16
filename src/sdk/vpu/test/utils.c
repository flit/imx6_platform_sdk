/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vpu_test.h"
#include "vpu_debug.h"
#include "vpu_bsfile.h"

extern int bsoffset;

FILE *fopen(const char *filename, const char *mode)
{
    return (FILE *) 0;
}

int freadn(int fd, void *vptr, size_t n)
{

    return (n);
}

int fat_read_from_usdhc(uint32_t sd_addr, uint32_t sd_size, void *buffer, int fast_flag)
{
    card_data_read(SD_PORT_BASE_ADDR, buffer, sd_size, sd_addr);
    return 1;
}

void init_fat32_device(void *blkreq_func)
{
    /*in initilization stage, set the usdhc to polling mode */
    SDHC_INTR_mode = 0;
    SDHC_ADMA_mode = 1;

    V = (tVolume *) FAT_DRIVER_BUFFER;

    V->blkreq = blkreq_func;
    V->buffer = (char *)(FAT_DRIVER_BUFFER + 0x00100000);

    fat_mount(V);
}

void fat_search_files(char *ext, int num)
{
    int fnum, i;
    fnum = fat_scan_root(V, files, num, 1, ext);

    for (i = 0; i < num; i++) {
        printf("File %d is %s\n", i, files[i].fname);
        fat_open_file(V, &(files[i]));
        files[i].file_size &= 0xfff80000;
    }
}

int vpu_stream_read(struct cmd_line *cmd, char *buf, int n)
{
    if (cmd->src_scheme == PATH_MEM) {
        /*bitstream is stored in array BS_file */
        int bsleft = 0;
        printf("size of BS file is %d\n", sizeof(BS_file));
        bsleft = sizeof(BS_file) / sizeof(BS_file[0]) - bsoffset;
        if (bsleft == 0) {
            info_msg("bitstream file copied to end!\n");
            return 0;
        }

        if (bsleft > n) {
            memcpy(buf, &BS_file[bsoffset], n);
            bsoffset += n;
            return n;
        } else {
            memcpy(buf, &BS_file[bsoffset], bsleft);
            bsoffset += bsleft;
            return bsleft;
        }

    } else if (cmd->src_scheme == PATH_FILE) {
        int res, i;

        /* if SD is currently busy, it means that the other video instance has requested a buffer fill, */
        /* return without doing anything, the video driver will request a buffer fill again next frame */
        int usdhc_status = 0;
        card_xfer_result(SD_PORT_BASE_ADDR, &usdhc_status);
        if (usdhc_status != 1)
            return -1;          //now SD card is busy
        res = fat_read_file(V, cmd->input, (char *)buf, n);

        if (res < n) {
            for (i = 0; i < (n - res); i++)
                reg8_write(buf + res + i, 0x0);
        }

        return res;
    }
    return 0;

}

int vpu_stream_write(struct cmd_line *cmd, char *buf, int n)
{
    if (cmd->dst_scheme == PATH_MEM) {
        //stored the output to specified memory base
    } else if (cmd->dst_scheme == PATH_FILE) {
        //TBD
    } else if (cmd->dst_scheme == PATH_NET) {
        //TBD, download the bs from enet or other interface
    }
    return 0;
}

int video_data_cmp(unsigned char *src, unsigned char *dst, int size)
{
    int i = 0;
    for (i = 0; i < size; i++) {
        if (src[i] != dst[i]) {
            err_msg("comparision failed at %d\n", i);
            return -1;
        }
    }
    return 0;
}

int ipu_refresh(int ipu_index, uint32_t buffer)
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

void epit2_config(int periodic)
{
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x10000);
    while (reg32_read(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET) & 0x10000) ;

    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITLR_OFFSET, 32768 / periodic);    //30fps
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000e);
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000f);
}
