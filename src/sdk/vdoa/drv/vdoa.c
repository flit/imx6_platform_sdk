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
#include "registers/regsvdoa.h"

void vdoa_setup(int width, int height, int vpu_sl, int ipu_sl, int interlaced,
                int ipu_sel, int bandLines, int pfs)
{
    // Set control register
    uint32_t value = BF_VDOA_VDOAC_PFS(pfs)
                        | BF_VDOA_VDOAC_ISEL(ipu_sel);
    
    switch (bandLines)
    {
        case 32:
            value |= BF_VDOA_VDOAC_BNDM(2);
            break;
        case 16:
            value |= BF_VDOA_VDOAC_BNDM(1);
            break;
        default:
            value |= BF_VDOA_VDOAC_BNDM(0);
            break;
    }
    
    if (interlaced)
    {
        value |= BM_VDOA_VDOAC_NF | BM_VDOA_VDOAC_SO;
    }
    
    HW_VDOA_VDOAC_WR(value);

    // VDOA frame parameters register
    HW_VDOA_VDOAFP_WR(  BF_VDOA_VDOAFP_FW(width)
                        | BF_VDOA_VDOAFP_FH(height));

    // VDOA stride line register
    HW_VDOA_VDOASL_WR(  BF_VDOA_VDOASL_ISLY(ipu_sl)
                        | BF_VDOA_VDOASL_VSLY(vpu_sl));
}

void vdoa_start(uint32_t src, uint32_t vubo, uint32_t dst, uint32_t iubo)
{
    // set the source
    vdoa_set_vpu_buffer(src);
    vdoa_set_vpu_ubo(vubo);

    vdoa_set_ipu_buffer(dst);
    vdoa_set_ipu_ubo(iubo);

    // start transfer
    vdoa_start_transfer();
}

void vdoa_set_vpu_buffer(uint32_t vbuf)
{
    if (!HW_VDOA_VDOAC.B.SYNC)
    {
        HW_VDOA_VDOAVEBA0_WR(vbuf);
    }
}

void vdoa_set_ipu_buffer(uint32_t ibuf)
{
    HW_VDOA_VDOAIEBA00_WR(ibuf);
}

void vdoa_set_vpu_ubo(uint32_t vubo)
{
    HW_VDOA_VDOAVUBO_WR(vubo);
}

void vdoa_set_ipu_ubo(uint32_t iubo)
{
    HW_VDOA_VDOAIUBO_WR(iubo);
}

void vdoa_start_transfer(void)
{
    HW_VDOA_VDOASRR.B.START = 1;
}

void vdoa_enable_interrupt(void)
{
    HW_VDOA_VDOAIE.B.EIEOT = 1;
}

void vdoa_disable_interrupt(void)
{
    HW_VDOA_VDOAIE.B.EIEOT = 0;
}

void vdoa_clear_interrupt(void)
{
    HW_VDOA_VDOAIST.B.EOT = 1;
}

bool vdoa_check_tx_eot(void)
{
    return (HW_VDOA_VDOAIST.B.EOT == 1);
}
