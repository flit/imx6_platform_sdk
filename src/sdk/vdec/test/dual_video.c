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
#include "hardware.h"
#include "vpu_debug.h"
#include "vpu_util.h"
#include "../../usdhc/inc/usdhc_ifc.h"

tFile files[10];
tVolume *V;
semaphore_t vpu_resource = { 0 };
struct decode *gDecInstance[MAX_NUM_INSTANCE];
struct encode *gEncInstance[MAX_NUM_INSTANCE];
int disp_clr_index[MAX_NUM_INSTANCE];
int trigger_display = 0;

int vdec_test(void)
{
    int err = 0, i, temp = 0;;
    vpu_versioninfo ver;
        DecOutputInfo outinfo;
        DecParam decparam = { 0 };
		
    /*instance attached to display interface */
    config_system_parameters();

    /* initialize SD card and FAT driver */
    enable_L1_cache();

    card_init(SD_PORT_BASE_ADDR, 4);    //SD card must work in 4-bit mode

    /*uSDHC working in POLLING mode */
    init_fat32_device((void *)fat_read_from_usdhc);

    /*now enable the INTERRUPT mode of usdhc */
    SDHC_INTR_mode = 1;
    SDHC_ADMA_mode = 1;
    gCurrentActiveInstance = 0;

    /* initialize VPU */
    framebuf_init();

    err = vpu_Init(NULL);
    if (err) {
        err_msg("VPU Init Failure.\n");
        return -1;
    }

    err = vpu_GetVersionInfo(&ver);
    if (err) {
        err_msg("Cannot get version info\n");
        vpu_UnInit();
        return -1;
    }

    info_msg("VPU firmware version: %d.%d.%d\n", ver.fw_major, ver.fw_minor, ver.fw_release);
    info_msg("VPU library version: %d.%d.%d\n", ver.lib_major, ver.lib_minor, ver.lib_release);

    /* initialize video streams and configure IPUs */
    ips_hannstar_xga_yuv_stream(1);

    vpu_decoder_setup((void *)(&files[0]));
    //vpu_decoder_setup((void *)(&files[1]));

    while (1) {
        static int inst = 0;

        /*get the next active instance */
        for (i = 1; i <= MAX_NUM_INSTANCE; i++) {
            temp = (inst + i) % MAX_NUM_INSTANCE;
            if (vpu_semap->codecInstPool[temp].inUse && vpu_semap->codecInstPool[temp].initDone) {
                inst = temp;
                break;
            }
        }

        if (i == MAX_NUM_INSTANCE) {
            warn_msg("No any Active instance running in the system!! now quiting ...\n");
            break;
        }
        decparam.dispReorderBuf = 0;

        decparam.prescanEnable = gDecInstance[inst]->cmdl->prescan;
        decparam.prescanMode = 0;

        decparam.skipframeMode = 0;
        decparam.skipframeNum = 0;
        decparam.iframeSearchEnable = 0;

        if (!vpu_IsBusy() && !dec_fifo_is_full(&gDecFifo[inst])) {
            vpu_DecStartOneFrame(gDecInstance[inst]->handle, &decparam);
	   while (vpu_IsBusy()) {
	            /*If there is enough space, read the bitstream from the SD card to the bitstream buffer */
	            err =
	                dec_fill_bsbuffer(gDecInstance[inst]->handle, gDecInstance[inst]->cmdl,
	                                  gBsBuffer[inst], gBsBuffer[inst] + STREAM_BUF_SIZE,
	                                  gBsBuffer[inst], STREAM_BUF_SIZE >> 2, NULL, NULL);
	        };

	        vpu_DecGetOutputInfo(gDecInstance[inst]->handle, &outinfo);

	        if (outinfo.indexFrameDisplay >= 0) {
	            /*push the decoded frame into fifo */
	            dec_fifo_push(&gDecFifo[inst],
	                          (uint32_t) (gDecInstance[inst]->pfbpool[outinfo.indexFrameDisplay]->
	                                      addrY), outinfo.indexFrameDisplay);
	        }
      }
		decoder_frame_display();
       
    }

    return 0;
}
