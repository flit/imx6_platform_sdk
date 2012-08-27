/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_dmfc.c
 * @brief IPU common file configuration
 * @ingroup diag_ipu
 */

#include "ipu/ipu_common.h"

void ipu_dmfc_config(uint32_t ipu_index, uint32_t channel)
{
    switch (channel) {          // to support multi-flow, the DMFC is shared between them
    case MEM_TO_DP_BG_CH23:
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5B, 2); //Table of fifo_size 000-2^9,001-2^8,010-2^7,
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5B, 1);    //Table of dmfc_burst_size codes
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5B, 0);   //start address 
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_CLR_5B, 0);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_SET_5B, 0);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_EN_5B, 0);
        ipu_write_field(ipu_index, IPU_DMFC_GENERAL1__WAIT4EOT_5B, 0);
        break;
    case MEM_TO_DP_FG_CH27:
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5F, 2);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5F, 1);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5F, 2);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_CLR_5F, 0);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_SET_5F, 0);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_EN_5F, 0);
        ipu_write_field(ipu_index, IPU_DMFC_GENERAL1__WAIT4EOT_5F, 0);
        break;
    case MEM_TO_DC_CH28:
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_FIFO_SIZE_1, 1);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_BURST_SIZE_1, 1);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_ST_ADDR_1, 4);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_CLR_1, 7);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_SET_1, 2);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_EN_1, 1);
        ipu_write_field(ipu_index, IPU_DMFC_GENERAL1__WAIT4EOT_1, 0);
        break;
    }
}

void ipu_dmfc_alloc(uint32_t ipu_index, uint32_t channel, uint32_t size, uint32_t start_addr,
                    uint32_t burst)
{
    switch (channel) {          // to support multi-flow, the DMFC is shared between them
    case MEM_TO_DP_BG_CH23:
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5B, size);  //Table of fifo_size 000-2^9,001-2^8,010-2^7,
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5B, burst);    //start address 
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5B, start_addr);  //start address 
        break;
    case MEM_TO_DP_FG_CH27:
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5F, size);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5F, burst);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5F, start_addr);
        break;
    case MEM_TO_DC_CH28:
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_FIFO_SIZE_1, size);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_BURST_SIZE_1, burst);
        ipu_write_field(ipu_index, IPU_DMFC_WR_CHAN__DMFC_ST_ADDR_1, start_addr);
        break;
    }

}
