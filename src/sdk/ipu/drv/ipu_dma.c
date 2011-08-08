/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "ipu_common.h"

inline void ipu_cpmem_set_field(uint32_t base, int w, int bit, int size, uint32_t v)
{
    int i = (bit) / 32;
    int off = (bit) % 32;
    _param_word(base, w)[i] |= (v) << off;
    if (((bit) + (size) - 1) / 32 > i) {
        _param_word(base, w)[i + 1] |= (v) >> (off ? (32 - off) : 0);
    }
}

inline void ipu_cpmem_mod_field(uint32_t base, int w, int bit, int size, uint32_t v)
{
    int i = (bit) / 32;
    int off = (bit) % 32;
    uint32_t mask = (1UL << size) - 1;
    uint32_t temp = _param_word(base, w)[i];
    temp &= ~(mask << off);
    _param_word(base, w)[i] = temp | (v) << off;
    if (((bit) + (size) - 1) / 32 > i) {
        temp = _param_word(base, w)[i + 1];
        temp &= ~(mask >> (32 - off));
        _param_word(base, w)[i + 1] = temp | ((v) >> (off ? (32 - off) : 0));
    }
}

inline uint32_t ipu_cpmem_read_field(uint32_t base, int w, int bit, int size)
{
    uint32_t temp2;
    int i = (bit) / 32;
    int off = (bit) % 32;
    uint32_t mask = (1UL << size) - 1;
    uint32_t temp1 = _param_word(base, w)[i];
    temp1 = mask & (temp1 >> off);
    if (((bit) + (size) - 1) / 32 > i) {
        temp2 = _param_word(base, w)[i + 1];
        temp2 &= mask >> (off ? (32 - off) : 0);
        temp1 |= temp2 << (off ? (32 - off) : 0);
    }

}

/*!
 * set the ipu channel buffer ready signal
 *
 * @param 	ipu_index: 	ipu index
 * @param 	channel: IPU dma channel index
 * @param 	buf: choose the buffer number, 0 or 1
 *
 */
void ipu_channel_buf_ready(int ipu_index, int channel, int buf)
{
    int idx = channel / 32;
    int offset = channel % 32;

    if (idx) {
        if (buf) {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF1_RDY1_CLR, 0);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF1_RDY1__ADDR, 1 << offset, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF0_RDY1_CLR, 0);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF0_RDY1__ADDR, 1 << offset, 1);
        }
    } else {
        if (buf) {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF1_RDY0_CLR, 0);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF1_RDY0__ADDR, 1 << offset, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF0_RDY0_CLR, 0);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF0_RDY0__ADDR, 1 << offset, 1);
        }
    }
}

/*!
 * unset the ipu channel buffer ready signal
 *
 * @param 	ipu_index: 	ipu index
 * @param 	channel: IPU dma channel index
 * @param 	buf: choose the buffer number, 0 or 1
 */
void ipu_channel_buf_not_ready(int ipu_index, int channel, int buf)
{
    int idx = channel / 32;
    int offset = channel % 32;

    if (idx) {
        if (buf) {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF1_RDY1_CLR, 1);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF1_RDY1__ADDR, 1 << offset, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF0_RDY1_CLR, 1);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF0_RDY1__ADDR, 1 << offset, 1);
        }
    } else {
        if (buf) {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF1_RDY0_CLR, 1);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF1_RDY0__ADDR, 1 << offset, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IPU_GPR__IPU_CH_BUF0_RDY0_CLR, 1);
            ipu_write_field(ipu_index, IPU_IPU_CH_BUF0_RDY0__ADDR, 1 << offset, 1);
        }
    }
}

void ipu_idmac_channel_mode_sel(int ipu_index, int channel, int double_buf_en)
{
    int idx = channel / 32;
    int offset = channel % 32;
    ipu_write_field(ipu_index, IPU_IPU_CH_DB_MODE_SEL_0__ADDR + idx * 4, 1 << offset,
                    double_buf_en);
}

void ipu_idmac_channel_enable(int ipu_index, int channel, int enable)
{
    int idx = channel / 32;
    int offset = channel % 32;
    ipu_write_field(ipu_index, IPU_IDMAC_CH_EN_1__ADDR + idx * 4, 1 << offset, enable);
}

int ipu_idmac_channel_busy(int ipu_index, int channel)
{
    int idx, offset;
    uint32_t ipu_base_addr = IPU1_CTRL_BASE_ADDR;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else if (ipu_index == 2)
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;
    else {
        printf("wrong ipu index !!\n");
        return false;
    }
    idx = channel / 32;
    offset = channel % 32;
    return ((readl(ipu_base_addr + IPU_IDMAC_CH_BUSY_1__ADDR + 4 * idx) & (1 << offset)) >> offset);
}

void ipu_idmac_config(int ipu_index, ips_image_stream_t * ims)
{
    memset((void *)ipu_cpmem_addr(ipu_index, ims->channel), 0, sizeof(ipu_cpmem_t));

    switch (ims->pixel_format) {
    case NON_INTERLEAVED_YUV444:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_UBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_VBO,
                            ims->width * ims->height * 2 / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLY,
                            ims->width - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLUY,
                            ims->width - 1);
        break;

    case NON_INTERLEAVED_YUV422:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_UBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_VBO,
                            ims->width * ims->height * 3 / 16);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLY,
                            ims->width - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLUY,
                            ims->width / 2 - 1);
        break;

    case NON_INTERLEAVED_YUV420:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_UBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_VBO,
                            ims->width * ims->height * 5 / 32);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLY,
                            ims->width - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLUY,
                            ims->width / 4 - 1);
        break;

    case PARTIAL_INTERLEAVED_YUV422:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_UBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_VBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLY,
                            ims->width - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLUY,
                            ims->width - 1);
        break;

    case PARTIAL_INTERLEAVED_YUV420:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_UBO,
                            ims->width * ims->height / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_VBO,
                            ims->width * ims->height * 2 / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLY,
                            ims->width - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SLUY,
                            ims->width - 1);

        break;

    case INTERLEAVED_LUT:
        break;
    case INTERLEAVED_GENERIC:
        break;
    case INTERLEAVED_RGB:      //test RGB565
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_SL,
                            ims->width * 2 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_WID0, 5 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_OFF0, 0);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_WID1, 6 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_OFF1, 5);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_WID2, 5 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_OFF2, 11);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_WID3, 0);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_OFF3, 16);
        break;
    case INTERLEAVED_Y1U1Y2V1:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_SL,
                            ims->width * 2 - 1);
        break;

    case INTERLEAVED_Y2U1Y1V1:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_SL,
                            ims->width * 2 - 1);
        break;

    case INTERLEAVED_U1Y1V1Y2:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_SL,
                            ims->width * 2 - 1);
        break;

    case INTERLEAVED_U1Y2V1Y1:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_NPB, 15);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), INTERLEAVED_SL,
                            ims->width * 2 - 1);
        break;
    default:
        printf("Wrong data format input for IDMAC!!\n");
        return;
    }
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_FW,
                        ims->width - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_FH,
                        ims->height - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_SO,
                        ims->scan_interface);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_EBA0,
                        CSD0_BASE_ADDR);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_EBA1,
                        CSD0_BASE_ADDR);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_PFS,
                        ims->pixel_format);

    ipu_idmac_channel_mode_sel(ipu_index, ims->channel, IDMAC_SINGLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, ims->channel, 1);

    switch (ims->channel) {
    case MEM_TO_DP_BG_CH23:
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5B, 2); //Table of fifo_size 000-2^9,001-2^8,010-2^7,
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5B, 1);    //Table of dmfc_burst_size codes
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5B, 0);   //start address 
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5B, 2);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5B, 1);
        ipu_write_field(ipu_index, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5B, 0);
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
