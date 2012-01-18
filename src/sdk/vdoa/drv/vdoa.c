/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vdoa.h"
#include "hardware.h"

void vdoa_setup(int width, int height, int vpu_sl, int ipu_sl, int interlaced,
                int ipu_sel, int bandLines, int pfs)
{
    uint32_t data;

    /* set BNDM - number of lines in a band */
    data = (bandLines == 32) ? 2 : ((bandLines == 16) ? 1 : 0);
    /* set bits NF (number of frames) and SO (scan order) if interlaced */
    data |= interlaced ? 0x14 : 0;
    /* set bit SYNC */
    data |= 0;
    /* pixel format: 0 - 4:2:0 partial interleaved, 1 - 4:2:2 interleaved */
    data |= pfs << 5;
    /* select IPU */
    data |= ipu_sel << 6;
    writel(data, VDOA_VDOAC);

    /* VDOA frame parameters register */
    writel((height << 16) | width, VDOA_VDOAFP);

    /* VDOA stride line register */
    writel((vpu_sl << 16) | ipu_sl, VDOA_VDOASL);
}

void vdoa_start(uint32_t src, uint32_t vubo, uint32_t dst, uint32_t iubo)
{
    /*set the source */
    vdoa_set_vpu_buffer(src);
    vdoa_set_vpu_ubo(vubo);

    vdoa_set_ipu_buffer(dst);
    vdoa_set_ipu_ubo(iubo);

    /*start transfer */
    vdoa_start_transfer();
}

void vdoa_set_vpu_buffer(uint32_t vbuf)
{
    if (!(readl(VDOA_VDOAC) & 0x8))
        writel(vbuf, VDOA_VDOAVEBA0);
}

void vdoa_set_ipu_buffer(uint32_t ibuf)
{
    writel(ibuf, VDOA_VDOAIEBA0_0);
}

void vdoa_set_vpu_ubo(uint32_t vubo)
{
    writel(vubo, VDOA_VDOAVUBO);
}

void vdoa_set_ipu_ubo(uint32_t iubo)
{
    writel(iubo, VDOA_VDOAIUBO);
}

void vdoa_start_transfer(void)
{
    writel(0x2, VDOA_VDOASRR);
}

void vdoa_enable_interrupt(void)
{
    writel(0x1, VDOA_VDOAIE);
}

void vdoa_disable_interrupt(void)
{
    writel(0x0, VDOA_VDOAIE);
}

void vdoa_clear_interrupt(void)
{
    writel(0x1, VDOA_VDOAIST);
}

uint32_t vdoa_check_tx_eot(void)
{
    return readl(VDOA_VDOAIST) & 0x01;
}
