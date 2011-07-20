/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
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
#include "hardware.h"
#include "vpu_debug.h"
#include "vpu_util.h"

int quitflag;

static int instance;

semaphore_t vpu_resource = { 0 };

extern int decode_test(void *arg);
extern int encode_test(void *arg);
//extern int encdec_test(void *arg);

int vpu_test(int argc, char *argv[])
{
    int err, ret = 0;
    char testmode = 0xFF;
    vpu_versioninfo ver;

    info_msg("VPU test program built on %s %s\n", __DATE__, __TIME__);

    memset((void *)&vpu_resource, 0, sizeof(semaphore_t));
    vpu_semap = &vpu_resource;

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

    while (quitflag == 0) {
        info_msg("Please select test mode:\n\
				0 -- decode test;\n\
				1 -- encode test;\n\
				2 -- codec test;\n\
				q -- for quit.\n");
        testmode = 0xFF;

        while (testmode == 0xFF)
            testmode = receive_char();

        switch (testmode) {
        case '0':
            decode_test((void *)0);
            break;
        case '1':
            encode_test((void *)0);
            break;
        case '2':
            //encdec_test();
            break;
        case 'q':
            quitflag = 1;
            break;
        default:
            err_msg("unkonw test mode input. please confirm!\n");
        }
    }

    vpu_UnInit();
    return ret;
}
