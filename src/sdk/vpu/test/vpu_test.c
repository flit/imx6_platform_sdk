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
vpu_resource_t vpu_resource = { 0 };
struct decode *gDecInstance[MAX_NUM_INSTANCE];
struct encode *gEncInstance[MAX_NUM_INSTANCE];
int disp_clr_index[MAX_NUM_INSTANCE];
int multi_instance = 1;

static vpu_test_t vpu_tests[] = {
    {"VPU DECODER TEST", decode_test},
    {"VPU ENCODER TEST", encode_test},
};

int vpu_test(void)
{
    int err = 0, i = 0;
    vpu_versioninfo ver;
    uint8_t revchar;
    int test_num = sizeof(vpu_tests) / sizeof(vpu_test_t);

    /*instance attached to display interface */
    config_system_parameters();

    /* initialize SD card and FAT driver */
    enable_L1_cache();

    card_init(SD_PORT_BASE_ADDR, 4);    //SD card must work in 4-bit mode

    /*uSDHC working in POLLING mode */
    init_fat32_device((void *)fat_read_from_usdhc);

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

    do {
        for (i = 0; i < test_num; i++)
            printf("\t%d - %s\n", i, vpu_tests[i].name);
        printf("\tx - to exit.\n");
        revchar = 0xFF;

        do {
            revchar = getchar();
        } while (revchar == (uint8_t) 0xFF);
        if (revchar == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        i = revchar - '0';
        if ((i >= 0) && (i < test_num)) {
            printf("\n");
            err = vpu_tests[i].test(NULL);
        }
    } while (1);

    return 0;
}
