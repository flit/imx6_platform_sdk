/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "vdoa.h"

void vdoa_setup(int width, int height, int ipu_sl, int vpu_sl, int iubo, int vubo, int sync,
                int ipu_sel)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    /* VDOA control register:
     * BNDM (band size) = 01 - 16 lines
     * NF (number of frames) = 0 - one frame
     * SO (scan order) = 0 - progressive 
     * PFS (pixel format select) = 0 - partially interleaved 4:2:0 */
    vdoa->vdoac = 0x1 | (sync << 3) | (ipu_sel << 6);

    /* VDOA frame parameters register */
    vdoa->vdoafp = (height << 16) | width;

    /* VDOA stride line register */
    vdoa->vdoasl = (vpu_sl << 16) | ipu_sl;

    /* VDOA IPU chroma buffer offset */
    vdoa->vdoaiubo = iubo;

    /* VDOA VPU chroma buffer offset */
    vdoa->vdoavubo = vubo;
}

void vdoa_start(uint32_t src, uint32_t dst)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaveba0 = src;
    vdoa->vdoaieba00 = dst;
    vdoa->vdoasrr = 0x2;
}

void vdoa_setVPUBuffer(uint32_t buffer)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaveba0 = buffer;
}

void vdoa_setIPUBuffer(uint32_t buffer)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaieba00 = buffer;
}

void vdoa_enable_interrupt(void)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaie = 0x1;
}

void vdoa_disable_interrupt(void)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaie = 0x0;
}

void vdoa_clear_interrupt(void)
{
    vdoaRegs vdoa = (vdoaRegs) (VDOA_BASE_ADDR);

    vdoa->vdoaist = 0x1;
}
