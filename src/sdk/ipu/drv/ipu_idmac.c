/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_idmac.c
 * @brief IPU IDMAC configuration
 * @ingroup diag_ipu
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
    return temp1;
}

/*!
 * set the ipu channel buffer ready signal
 *
 * @param 	ipu_index: 	ipu index
 * @param 	channel: IPU dma channel index
 * @param 	buf: choose the buffer number, 0 or 1
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

/*!
 * set the ipu channel buffer mode, single or double
 *
 * @param 	ipu_index:      ipu index
 * @param 	channel:        IPU dma channel index
 * @param 	double_buf_en:  enable double buffer 
 *
 */
void ipu_idmac_channel_mode_sel(int ipu_index, int channel, int double_buf_en)
{
    int idx = channel / 32;
    int offset = channel % 32;
    ipu_write_field(ipu_index, IPU_IPU_CH_DB_MODE_SEL_0__ADDR + idx * 4, 1 << offset,
                    double_buf_en);
}

/*!
 * set the ipu channel buffer mode, single or double
 *
 * @param 	ipu_index:  ipu index
 * @param 	channel:    IPU dma channel index
 * @param 	enable:     enable channel  
 *
 */
void ipu_idmac_channel_enable(int ipu_index, int channel, int enable)
{
    int idx = channel / 32;
    int offset = channel % 32;
    ipu_write_field(ipu_index, IPU_IDMAC_CH_EN_1__ADDR + idx * 4, 1 << offset, enable);
}

/*!
 * query the ipu channel buffer busy status
 *
 * @param 	ipu_index:  ipu index
 * @param 	channel:    IPU dma channel index
 *
 * @return 	1 for busy, 0 for idle
 */
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

/*!
 * IPU background display DMA channel config (CH23)
 *
 * @param	ipu_index:  ipu index
 * @param	width:		background width
 * @param	height:		background height
 * @param	pixel_format:   background pixel format
 */
void ipu_disp_bg_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                              uint32_t pixel_format)
{
    uint32_t channel = MEM_TO_DP_BG_CH23;
    uint32_t sl, ubo;

    if (pixel_format == INTERLEAVED_RGB) {
        sl = 2 * width - 1;
        ubo = 0;
    } else {
        sl = width - 1;
        ubo = width * height;
    }

    ipu_idmac_channel_enable(ipu_index, channel, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel), 0, sizeof(ipu_cpmem_t));

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA0, CH23_EBA0 / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA1, CH23_EBA1 / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_FW, width - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_FH, height - 1);

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_PFS, pixel_format);
    ipu_idma_pixel_format_config(ipu_index, channel, pixel_format, sl, ubo);

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_NPB, 15);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_SO, 0);

    ipu_idmac_channel_mode_sel(ipu_index, channel, IDMAC_SINGLE_BUFFER);
    ipu_channel_buf_ready(ipu_index, channel, 0);
    ipu_channel_buf_ready(ipu_index, channel, 1);
    ipu_idmac_channel_enable(ipu_index, channel, 1);
}

void ipu_dma_update_buffer(uint32_t ipu_index, uint32_t channel, uint32_t buffer_index,
                           uint32_t buffer_addr)
{
    if (buffer_index == 0)
        ipu_cpmem_mod_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA0, buffer_addr / 8);
    else if (buffer_index == 1)
        ipu_cpmem_mod_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA1, buffer_addr / 8);
    else {
        printf("Wrong buffer index input!!!\n");
    }

}

int ipu_idmac_chan_cur_buff(uint32_t ipu_index, uint32_t channel)
{
    int idx, offset, cur_buf = 0;
    idx = channel / 32;
    offset = channel % 32;
    if (ipu_index == 0) {
        cur_buf =
            (readl(IPU1_CTRL_BASE_ADDR + IPU_IPU_CUR_BUF_0__ADDR + 4 * idx) & (1 << offset)) >>
            offset;
    } else if (ipu_index == 1) {
        cur_buf =
            (readl(IPU2_CTRL_BASE_ADDR + IPU_IPU_CUR_BUF_0__ADDR + 4 * idx) & (1 << offset)) >>
            offset;
    }
    return cur_buf;
}

/*!
 * IPU background display DMA channel config (CH23)
 *
 * @param	ipu_index:  ipu index
 * @param	width:		background width
 * @param	height:		background height
 * @param	pixel_format:   background pixel format
 */
void ipu_disp_fg_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                              uint32_t pixel_format)
{
    uint32_t channel = MEM_TO_DP_FG_CH27;
    uint32_t sl, ubo;

    if (pixel_format < INTERLEAVED_RGB) {
        sl = width - 1;
        ubo = width * height;
    } else {
        sl = 2 * width - 1;
        ubo = 0;
    }

    ipu_idmac_channel_enable(ipu_index, channel, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel), 0, sizeof(ipu_cpmem_t));

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA0, CH27_EBA0 / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_EBA1, CH27_EBA1 / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_FW, width - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_FH, height - 1);

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_PFS, pixel_format);
    ipu_idma_pixel_format_config(ipu_index, channel, pixel_format, sl, ubo);

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_NPB, 15);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_SO, 0);

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_ALU, 0);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), CPMEM_ALBM, 0);

    ipu_idmac_channel_mode_sel(ipu_index, channel, IDMAC_SINGLE_BUFFER);
    ipu_channel_buf_ready(ipu_index, channel, 0);
    ipu_idmac_channel_enable(ipu_index, channel, 1);
}

void ipu_rotate_idmac_config(uint32_t ipu_index, uint32_t channel_in, uint32_t channel_out,
                             ipu_rot_info_t rot_info)
{
    //input channel
    ipu_idmac_channel_enable(ipu_index, channel_in, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel_in), 0, sizeof(ipu_cpmem_t));
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_EBA0, rot_info.addr0_in / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_EBA1, rot_info.addr1_in / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_FW, rot_info.width_in - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_FH, rot_info.height_in - 1);

    //set pixel format
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_PFS, rot_info.pixel_format_in);
    ipu_idma_pixel_format_config(ipu_index, channel_in, rot_info.pixel_format_in,
                                 rot_info.strideline_in, rot_info.ubo_in);

    //number of pixels per burst
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_NPB, 7);   // for rotate operation, npb must be equal 7

    //enable rotate and block mode
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_ROT, rot_info.rot);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_BM, 1);

    if ((void *)rot_info.addr1_in == NULL)
        ipu_idmac_channel_mode_sel(ipu_index, channel_in, IDMAC_SINGLE_BUFFER);
    else
        ipu_idmac_channel_mode_sel(ipu_index, channel_in, IDMAC_DOUBLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, channel_in, 1);

    //output channel
    ipu_idmac_channel_enable(ipu_index, channel_out, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel_out), 0, sizeof(ipu_cpmem_t));
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_EBA0, rot_info.addr0_out / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_EBA1, rot_info.addr1_out / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_FW, rot_info.width_out - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_FH, rot_info.height_out - 1);

    //set pixel format
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_PFS,
                        rot_info.pixel_format_out);
    ipu_idma_pixel_format_config(ipu_index, channel_out, rot_info.pixel_format_out,
                                 rot_info.strideline_out, rot_info.ubo_out);

    //number of pixels per burst
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_NPB, 7);

    //enable hf/vf and block mode
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_BM, 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_ROT, 0);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_HF, rot_info.hf);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_VF, rot_info.vf);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_ID, 0);

    if ((void *)rot_info.addr1_out == NULL)
        ipu_idmac_channel_mode_sel(ipu_index, channel_out, IDMAC_SINGLE_BUFFER);
    else
        ipu_idmac_channel_mode_sel(ipu_index, channel_out, IDMAC_DOUBLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, channel_out, 1);
}

void ipu_resize_idmac_config(uint32_t ipu_index, uint32_t channel_in, uint32_t channel_out,
                             ipu_res_info_t res_info)
{
    //input channel
    ipu_idmac_channel_enable(ipu_index, channel_in, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel_in), 0, sizeof(ipu_cpmem_t));
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_EBA0, res_info.addr0_in / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_EBA1, res_info.addr1_in / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_FW, res_info.width_in - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_FH, res_info.height_in - 1);

    //set pixel format
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_PFS, res_info.pixel_format_in);
    ipu_idma_pixel_format_config(ipu_index, channel_in, res_info.pixel_format_in,
                                 res_info.strideline_in, res_info.u_offset_in);

    //number of pixels per burst
    if (res_info.width_in % 16 == 0)
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_NPB, 15);
    else
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_in), CPMEM_NPB, 7);

    if ((void *)res_info.addr1_in == NULL)
        ipu_idmac_channel_mode_sel(ipu_index, channel_in, IDMAC_SINGLE_BUFFER);
    else
        ipu_idmac_channel_mode_sel(ipu_index, channel_in, IDMAC_DOUBLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, channel_in, 1);

    //output channel
    ipu_idmac_channel_enable(ipu_index, channel_out, 0);
    memset((void *)ipu_cpmem_addr(ipu_index, channel_out), 0, sizeof(ipu_cpmem_t));

    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_EBA0, res_info.addr0_out / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_EBA1, res_info.addr1_out / 8);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_FW, res_info.width_out - 1);
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_FH, res_info.height_out - 1);

    //set pixel format
    ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_PFS,
                        res_info.pixel_format_out);
    ipu_idma_pixel_format_config(ipu_index, channel_out, res_info.pixel_format_out,
                                 res_info.strideline_out, res_info.u_offset_out);

    //number of pixels per burst
    if (res_info.width_out % 16 == 0)
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_NPB, 15);
    else
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel_out), CPMEM_NPB, 7);

    if ((void *)res_info.addr1_out == NULL)
        ipu_idmac_channel_mode_sel(ipu_index, channel_out, IDMAC_SINGLE_BUFFER);
    else
        ipu_idmac_channel_mode_sel(ipu_index, channel_out, IDMAC_DOUBLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, channel_out, 1);
}

void ipu_idma_pixel_format_config(uint32_t ipu_index, uint32_t channel, uint32_t pixel_format,
                                  uint32_t sl, uint32_t ubo)
{
    switch (pixel_format) {
    case NON_INTERLEAVED_YUV444:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_UBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_VBO, ubo * 2 / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLY, sl);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLUV, sl);
        break;
    case NON_INTERLEAVED_YUV422:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_UBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_VBO, ubo * 3 / 16);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLY, sl);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLUV,
                            (sl + 1) / 2 - 1);
        break;
    case NON_INTERLEAVED_YUV420:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_UBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_VBO, ubo * 5 / 32);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLY, sl);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLUV,
                            (sl + 1) / 2 - 1);
        break;
    case PARTIAL_INTERLEAVED_YUV422:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_UBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_VBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLY, sl);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLUV, sl);
        break;
    case PARTIAL_INTERLEAVED_YUV420:
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_UBO, ubo / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_VBO, ubo * 2 / 8);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLY, sl);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), NON_INTERLEAVED_SLUV, sl);
        break;
    case INTERLEAVED_LUT:
        break;
    case INTERLEAVED_GENERIC:
        break;
    case INTERLEAVED_RGB:      //default INTERLEAVED_RGB: RGB565
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_BPP, 0x3);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_WID0, 5 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_WID1, 6 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_WID2, 5 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_WID3, 0 - 1);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_OFF0, 0);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_OFF1, 5);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_OFF2, 11);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_OFF3, 16);
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, channel), INTERLEAVED_SL, sl);
        break;
    case INTERLEAVED_Y1U1Y2V1:
        break;
    case INTERLEAVED_Y2U1Y1V1:
        break;
    case INTERLEAVED_U1Y1V1Y2:
        break;
    case INTERLEAVED_U1Y2V1Y1:
        break;
    default:
        printf("Invalid pixel format!\n");
        break;
    }
}
