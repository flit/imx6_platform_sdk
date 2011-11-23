/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef VIDEO_H_
#define VIDEO_H_

#include "hardware.h"
#include "vpu_api.h"

#define MAX_FIFO_SIZE 		(32)
#define MAX_INSTANCES		(4)

typedef struct {
    uint32_t u_offset;
    uint32_t v_offset;
    int y_strideline;
    int uv_strideline;
    int frame_width;
    int frame_height;
    int data_format;
} video_params;

typedef struct {
    uint32_t frames[MAX_FIFO_SIZE];
    uint32_t id[MAX_FIFO_SIZE];
    uint32_t timeStamp[MAX_FIFO_SIZE];
    int wrptr;
    int rdptr;
    int size;
    int full;
    uint32_t popCnt;
} VPUframesFifo;

#define VDOA_DIS            (0)
#define VDOA_EN             (1)

#define EPIT_EPITCR_OFFSET	0x00    //  32bit timer 3 control reg
#define EPIT_EPITSR_OFFSET	0x04    //  32bit timer 3 prescaler reg
#define EPIT_EPITLR_OFFSET	0x08    //  32bit timer 3 compare reg
#define EPIT_EPITCMPR_OFFSET	0x0C    //  32bit timer 3 capture reg
#define EPIT_EPITCNR_OFFSET	0x10    //  32bit timer 3 counter reg

void video_setup(int inst, int use_vdoa, uint32_t buffers_base, video_params * vpu_params);
#endif
