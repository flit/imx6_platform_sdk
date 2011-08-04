/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "ipu_common.h"

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
    unsigned int ipu_base_addr = IPU1_CTRL_BASE_ADDR;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else if (ipu_index == 2)
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;
    else {
        printf("wrong ipu index !!\n");
        return;
    }
    idx = channel / 32;
    offset = channel % 32;
    return ((readl(ipu_base_addr + IPU_IDMAC_CH_BUSY_1__ADDR + 4 * idx) & (1 << offset)) >> offset);
}

void ipu_idmac_config(int ipu_index, ips_image_stream_t * ims)
{
    uint32_t w0_d0 = 0, w0_d1 = 0, w0_d2 = 0, w0_d3 = 0, w0_d4 = 0, w1_d0 = 0, w1_d1 = 0, w1_d2 =
        0, w1_d3 = 0, w1_d4 = 0;
    uint32_t ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    ipu_channel_parameter_t ipu_channel_params = { 0 };

    memset((void *)&ipu_channel_params, 0, sizeof(ipu_channel_parameter_t));

    ipu_channel_params.fw = ims->width;
    ipu_channel_params.fh = ims->height;
    ipu_channel_params.so = ims->scan_interface;
    ipu_channel_params.eba0 = 0;    //need to update later
    ipu_channel_params.eba1 = 0;
    ipu_channel_params.pfs = ims->pixel_format;
    ipu_channel_params.channel = ims->channel;
    switch (ims->pixel_format) {
    case NON_INTERLEAVED_YUV444:
        ipu_channel_params.ubo = ims->width * ims->height >> 3;
        ipu_channel_params.vbo = ims->width * ims->height * 2 >> 3;
        ipu_channel_params.npb = 15;
        ipu_channel_params.sly = ims->width;
        ipu_channel_params.sluv = ims->width;
        goto non_interleaved_config;

    case NON_INTERLEAVED_YUV422:
        ipu_channel_params.ubo = ims->width * ims->height >> 3;
        ipu_channel_params.vbo = ims->width * ims->height * 3 >> 4;
        ipu_channel_params.npb = 15;
        ipu_channel_params.sly = ims->width;
        ipu_channel_params.sluv = ims->width >> 1;
        goto non_interleaved_config;

    case NON_INTERLEAVED_YUV420:
        ipu_channel_params.ubo = ims->width * ims->height >> 3;
        ipu_channel_params.vbo = ims->width * ims->height * 5 >> 5;
        ipu_channel_params.npb = 31;
        ipu_channel_params.sly = ims->width;
        ipu_channel_params.sluv = ims->width >> 2;
        goto non_interleaved_config;

    case PARTIAL_INTERLEAVED_YUV422:
        ipu_channel_params.ubo = ims->width * ims->height >> 3;
        ipu_channel_params.vbo = ims->width * ims->height >> 3;
        ipu_channel_params.npb = 31;
        ipu_channel_params.sly = ims->width;
        ipu_channel_params.sluv = ims->width;
        goto non_interleaved_config;

    case PARTIAL_INTERLEAVED_YUV420:
        ipu_channel_params.ubo = ims->width * ims->height >> 3;
        ipu_channel_params.vbo = ims->width * ims->height >> 3;
        ipu_channel_params.npb = 31;
        ipu_channel_params.sly = ims->width;
        ipu_channel_params.sluv = ims->width;
      non_interleaved_config:
        w0_d0 = ipu_channel_params.xb << 19 | ipu_channel_params.yv << 10 | ipu_channel_params.xv;
        w0_d1 =
            ipu_channel_params.ubo << 14 | ipu_channel_params.
            cf << 13 | ipu_channel_params.nsb_b << 12 | ipu_channel_params.yb;
        w0_d2 = ipu_channel_params.vbo << 4 | ipu_channel_params.ubo >> 18;
        w0_d3 =
            ipu_channel_params.fw << 29 | ipu_channel_params.
            cae << 28 | ipu_channel_params.cap << 27 | ipu_channel_params.
            the << 26 | ipu_channel_params.vf << 25 | ipu_channel_params.
            hf << 24 | ipu_channel_params.rot << 23 | ipu_channel_params.
            bm << 21 | ipu_channel_params.bndm << 18 | ipu_channel_params.so << 17;
        w0_d4 = ipu_channel_params.fh << 10 | ipu_channel_params.fw >> 3;

        w1_d0 = ipu_channel_params.eba1 << 29 | ipu_channel_params.eba0;
        w1_d1 = ipu_channel_params.ilo << 26 | ipu_channel_params.eba1 >> 3;
        w1_d2 =
            ipu_channel_params.th << 31 | ipu_channel_params.
            id << 29 | ipu_channel_params.albm << 26 | ipu_channel_params.
            alu << 25 | ipu_channel_params.pfs << 21 | ipu_channel_params.
            npb << 14 | ipu_channel_params.ilo >> 6;
        w1_d3 =
            ipu_channel_params.wid3 << 29 | ipu_channel_params.sly << 6 | ipu_channel_params.
            th >> 1;
        w1_d4 = ipu_channel_params.sluv;
        break;
    case INTERLEAVED_LUT:
         /*TBD*/ goto interleaved_config;
    case INTERLEAVED_GENERIC:
         /*TBD*/ goto interleaved_config;
    case INTERLEAVED_Y1U1Y2V1:
        ipu_channel_params.npb = 15;
        ipu_channel_params.bpp = 0x3;
        ipu_channel_params.sl = ims->width * 2 - 1;
        goto interleaved_config;

    case INTERLEAVED_Y2U1Y1V1:
        ipu_channel_params.npb = 15;
        ipu_channel_params.bpp = 0x3;
        ipu_channel_params.sl = ims->width * 2 - 1;
        goto interleaved_config;

    case INTERLEAVED_U1Y1V1Y2:
        ipu_channel_params.npb = 15;
        ipu_channel_params.bpp = 0x3;
        ipu_channel_params.sl = ims->width * 2 - 1;
        goto interleaved_config;

    case INTERLEAVED_U1Y2V1Y1:
        ipu_channel_params.npb = 15;
        ipu_channel_params.bpp = 0x3;
        ipu_channel_params.sl = ims->width * 2 - 1;
      interleaved_config:
        w0_d0 = ipu_channel_params.xb << 19 | ipu_channel_params.yv << 10 | ipu_channel_params.xv;
        w0_d1 =
            ipu_channel_params.sy << 26 | ipu_channel_params.
            sx << 14 | ipu_channel_params.cf << 13 | ipu_channel_params.
            nsb_b << 12 | ipu_channel_params.yb;
        w0_d2 =
            ipu_channel_params.sm << 22 | ipu_channel_params.
            sdx << 15 | ipu_channel_params.ns << 5 | ipu_channel_params.sy >> 6;
        w0_d3 =
            ipu_channel_params.fw << 29 | ipu_channel_params.
            cae << 28 | ipu_channel_params.cap << 27 | ipu_channel_params.
            the << 26 | ipu_channel_params.vf << 25 | ipu_channel_params.
            hf << 24 | ipu_channel_params.rot << 23 | ipu_channel_params.
            bm << 21 | ipu_channel_params.bndm << 18 | ipu_channel_params.
            so << 17 | ipu_channel_params.dim << 16 | ipu_channel_params.
            dec_sel << 14 | ipu_channel_params.bpp << 11 | ipu_channel_params.
            sdry << 10 | ipu_channel_params.sdrx << 9 | ipu_channel_params.
            sdy << 2 | ipu_channel_params.sce << 1 | ipu_channel_params.scc;
        w0_d4 = ipu_channel_params.fh << 10 | ipu_channel_params.fw >> 3;

        w1_d0 = ipu_channel_params.eba1 << 29 | ipu_channel_params.eba0;
        w1_d1 = ipu_channel_params.ilo << 26 | ipu_channel_params.eba1 >> 3;
        w1_d2 =
            ipu_channel_params.th << 31 | ipu_channel_params.
            id << 29 | ipu_channel_params.albm << 26 | ipu_channel_params.
            alu << 25 | ipu_channel_params.pfs << 21 | ipu_channel_params.
            npb << 14 | ipu_channel_params.ilo >> 6;
        w1_d3 =
            ipu_channel_params.wid3 << 29 | ipu_channel_params.
            wid2 << 26 | ipu_channel_params.wid1 << 23 | ipu_channel_params.
            wid0 << 20 | ipu_channel_params.sl << 6 | ipu_channel_params.th >> 1;
        w1_d4 =
            ipu_channel_params.ofs3 << 15 | ipu_channel_params.
            ofs2 << 10 | ipu_channel_params.ofs1 << 5 | ipu_channel_params.ofs0;
        break;
    default:
        printf("Wrong data format input for IDMAC!!\n");
        return;
    }

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else if (ipu_index == 2)
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;
    else {
        printf("wrong ipu index !!\n");
        return;
    }

    reg32_write(ipu_base_addr + CPMEM_WORD0_DATA0_INT__ADDR +
                (ipu_channel_params.channel << 6), w0_d0);
    reg32_write(ipu_base_addr + CPMEM_WORD0_DATA1_INT__ADDR +
                (ipu_channel_params.channel << 6), w0_d1);
    reg32_write(ipu_base_addr + CPMEM_WORD0_DATA2_INT__ADDR +
                (ipu_channel_params.channel << 6), w0_d2);
    reg32_write(ipu_base_addr + CPMEM_WORD0_DATA3_INT__ADDR +
                (ipu_channel_params.channel << 6), w0_d3);
    reg32_write(ipu_base_addr + CPMEM_WORD0_DATA4_INT__ADDR +
                (ipu_channel_params.channel << 6), w0_d4);

    reg32_write(ipu_base_addr + CPMEM_WORD1_DATA0_INT__ADDR +
                (ipu_channel_params.channel << 6), w1_d0);
    reg32_write(ipu_base_addr + CPMEM_WORD1_DATA1_INT__ADDR +
                (ipu_channel_params.channel << 6), w1_d1);
    reg32_write(ipu_base_addr + CPMEM_WORD1_DATA2_INT__ADDR +
                (ipu_channel_params.channel << 6), w1_d2);
    reg32_write(ipu_base_addr + CPMEM_WORD1_DATA3_INT__ADDR +
                (ipu_channel_params.channel << 6), w1_d3);
    reg32_write(ipu_base_addr + CPMEM_WORD1_DATA4_INT__ADDR +
                (ipu_channel_params.channel << 6), w1_d4);
    ipu_idmac_channel_mode_sel(ipu_index, ipu_channel_params.channel, IDMAC_SINGLE_BUFFER);
    ipu_idmac_channel_enable(ipu_index, ipu_channel_params.channel, 1);
}
