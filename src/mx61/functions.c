/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "functions.h"

//----------------------------------------------------------------------
//  Write With Mask (write only certain bits)
//----------------------------------------------------------------------
void reg8_write_mask(WORD addr, BYTE wdata, BYTE mask)
{
    BYTE masked_wdata, rdata;

    rdata = reg8_read(addr);
    masked_wdata = (((~mask) & rdata) | (mask & wdata));
    reg8_write(addr, masked_wdata);
}

void reg16_write_mask(WORD addr, HALF wdata, HALF mask)
{
    HALF masked_wdata, rdata;

    rdata = reg16_read(addr);
    masked_wdata = (((~mask) & rdata) | (mask & wdata));
    reg16_write(addr, masked_wdata);
}

void reg32_write_mask(WORD addr, WORD wdata, WORD mask)
{
    WORD masked_wdata, rdata;

    rdata = reg32_read(addr);
    masked_wdata = (((~mask) & rdata) | (mask & wdata));
    reg32_write(addr, masked_wdata);
}
