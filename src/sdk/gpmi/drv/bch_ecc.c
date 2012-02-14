/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "bch_ecc.h"
#include "regsbch.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void bch_init()
{
    bch_enable();
}

void bch_enable(void)
{
    // Remove the clock gate.
    HW_BCH_CTRL_CLR( BM_BCH_CTRL_CLKGATE);

    // Poll until clock is in the NON-gated state.
    while (HW_BCH_CTRL.B.CLKGATE)
    {
        ; // busy wait
    }

    // Remove Soft Reset.
    HW_BCH_CTRL_CLR( BM_BCH_CTRL_SFTRST );

    // Poll until soft reset is clear.
    while (HW_BCH_CTRL.B.SFTRST)
    {
        ; // busy wait
    }
}

void bch_disable(void)
{
    // Gate the BCH block
    HW_BCH_CTRL_SET( BM_BCH_CTRL_CLKGATE );
}

void bch_set_erase_threshold(unsigned threshold)
{
}

void bch_set_layout(uint32_t u32NandDeviceNumber, const BchEccLayout_t * ecc)
{
}

int bch_calculate_best_level(uint32_t pageDataSize, uint32_t pageMetadataSize, BchEccLayout_t * resultEcc)
{
    return 2;
}

void bch_clear_complete_irq()
{
    HW_BCH_CTRL_CLR(BM_BCH_CTRL_COMPLETE_IRQ);
}

void bch_read_correction_status(const uint8_t * auxBuffer, BchEccCorrectionInfo_t * correctionInfo)
{
}

uint16_t bch_get_buffer_mask(bool isWrite, uint32_t dataSize, const BchEccLayout_t * ecc)
{
    return kBchBufferMask_Page;
}

// EOF
