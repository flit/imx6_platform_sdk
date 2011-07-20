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
#include "vpu_bsfile.h"
#include "vpu_golden_data.h"

extern int quitflag;
extern int bsoffset;

/* Our custom header */
struct nethdr {
    int seqno;
    int iframe;
    int len;
};

FILE *fopen(const char *filename, const char *mode)
{
    return (FILE *) 0;
}

int /* Read n bytes from a file descriptor */ freadn(int fd, void *vptr, size_t n)
{

    return (n);
}

int vpu_read(struct cmd_line *cmd, char *buf, int n)
{
    if (cmd->src_scheme == PATH_MEM) {
        /*bitstream is stored in array BS_file */
        int bsleft = 0;
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
     /*TBD*/} else if (cmd->src_scheme == PATH_NET) {
        /*TBD, download the bs from enet or other interface */
    }

}

int vpu_write(struct cmd_line *cmd, char *buf, int n)
{
    if (cmd->dst_scheme == PATH_MEM) {
        /*stored the output to specified memory base */
    } else if (cmd->dst_scheme == PATH_FILE) {
     /*TBD*/} else if (cmd->dst_scheme == PATH_NET) {
        /*TBD, download the bs from enet or other interface */
    }
}

void SaveQpReport(Uint32 * qpReportAddr, int picWidth, int picHeight, int frameIdx, char *fileName)
{
    FILE *fp;
    int i, j;
    int MBx, MBy, MBxof4, MBxof1, MBxx;
    Uint32 *qpAddr;
    Uint32 qp;
    Uint8 lastQp[4];

    if (frameIdx == 0)
        fp = fopen(fileName, "wb");
    else
        fp = fopen(fileName, "a+b");

    if (!fp) {
        err_msg("Can't open %s in SaveQpReport\n", fileName);
        return;
    }

    MBx = picWidth / 16;
    MBxof1 = MBx % 4;
    MBxof4 = MBx - MBxof1;
    MBy = picHeight / 16;
    MBxx = (MBx + 3) / 4 * 4;
    for (i = 0; i < MBy; i++) {
        for (j = 0; j < MBxof4; j = j + 4) {
            dprintf(3, "qpReportAddr = %lx\n", (Uint32) qpReportAddr);
            qpAddr = (Uint32 *) ((Uint32) qpReportAddr + j + MBxx * i);
            qp = *qpAddr;
            fprintf(fp, " %4d %4d %3d \n", frameIdx, MBx * i + j + 0, (Uint8) (qp >> 24));
            fprintf(fp, " %4d %4d %3d \n", frameIdx, MBx * i + j + 1, (Uint8) (qp >> 16));
            fprintf(fp, " %4d %4d %3d \n", frameIdx, MBx * i + j + 2, (Uint8) (qp >> 8));
            fprintf(fp, " %4d %4d %3d \n", frameIdx, MBx * i + j + 3, (Uint8) qp);
        }

        if (MBxof1 > 0) {
            qpAddr = (Uint32 *) ((Uint32) qpReportAddr + MBxx * i + MBxof4);
            qp = *qpAddr;
            lastQp[0] = (Uint8) (qp >> 24);
            lastQp[1] = (Uint8) (qp >> 16);
            lastQp[2] = (Uint8) (qp >> 8);
            lastQp[3] = (Uint8) (qp);
        }

        for (j = 0; j < MBxof1; j++) {
            fprintf(fp, " %4d %4d %3d \n", frameIdx, MBx * i + j + MBxof4, lastQp[j]);
        }
    }

    fclose(fp);
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
