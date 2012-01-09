/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "vpu_test.h"

static int fb_index;
static struct frame_buf *fbarray[NUM_FRAME_BUFS];
static struct frame_buf fbpool[NUM_FRAME_BUFS];
vdec_frame_buffer_t gDecFifo[NUM_FRAME_BUFS];
uint32_t gBsBuffer[NUM_FRAME_BUFS];

void framebuf_init(void)
{
    int i;

    for (i = 0; i < NUM_FRAME_BUFS; i++) {
        fbarray[i] = &fbpool[i];
    }
}

struct frame_buf *get_framebuf(void)
{
    struct frame_buf *fb;

    fb = fbarray[fb_index];
    fbarray[fb_index] = 0;

    ++fb_index;
    fb_index &= FB_INDEX_MASK;

    return fb;
}

void put_framebuf(struct frame_buf *fb)
{
    --fb_index;
    fb_index &= FB_INDEX_MASK;

    fbarray[fb_index] = fb;
}

void dec_fifo_init(vdec_frame_buffer_t * fifo, int size)
{
    fifo->size = size;
    fifo->wrptr = 0;
    fifo->rdptr = 0;
    fifo->full = 0;
    fifo->popCnt = 0;
}

int dec_fifo_is_full(vdec_frame_buffer_t * fifo)
{
    return (fifo->full);
}

int dec_fifo_is_empty(vdec_frame_buffer_t * fifo)
{
    return ((fifo->rdptr == fifo->wrptr) && !(fifo->full));
}

/*one frame is in-queued*/
int dec_fifo_push(vdec_frame_buffer_t * fifo, uint32_t frame)
{
    if (fifo->full)
        return -1;

    fifo->frames[fifo->wrptr] = frame;

    if (++fifo->wrptr == fifo->size)
        fifo->wrptr = 0;

    if (fifo->wrptr == fifo->rdptr)
        fifo->full = 1;

    return 0;
}

/*one frame is dequeued*/
int dec_fifo_pop(vdec_frame_buffer_t * fifo, uint32_t * frame, uint32_t * id)
{
    if ((fifo->rdptr == fifo->wrptr) && !(fifo->full))
        return -1;

    *frame = fifo->frames[fifo->rdptr];
    *id = fifo->popCnt++;

    if (++fifo->rdptr == fifo->size)
        fifo->rdptr = 0;

    if (fifo->full)
        fifo->full = 0;

    return 0;
}

struct frame_buf *framebuf_alloc(int stdMode, int format, int strideY, int height)
{
    struct frame_buf *fb;
    int err;
    int divX, divY;

    /*Add by Ray, for direct display on display panel */
    strideY = FRAME_MAX_WIDTH;
    height = FRAME_MAX_HEIGHT;

    fb = get_framebuf();
    if (fb == NULL)
        return NULL;

    divX = (format == MODE420 || format == MODE422) ? 2 : 1;
    divY = (format == MODE420 || format == MODE224) ? 2 : 1;

    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
    fb->desc.size = (strideY * height + strideY / divX * height / divY * 2);
    fb->desc.size += strideY / divX * height / divY;

    err = IOGetMem(&fb->desc);
    if (err) {
        printf("Frame buffer allocation failure\n");
        memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
        return NULL;
    }

    fb->addrY = fb->desc.phy_addr;
    fb->addrCb = fb->addrY + strideY * height;
    fb->addrCr = fb->addrCb + strideY / divX * height / divY;
    fb->strideY = strideY;
    fb->strideC = strideY / divX;

    /*set the background to black */
    memset((void *)fb->addrY, 0x10, strideY * height);
    memset((void *)fb->addrCr, 0x80, strideY * height >> 2);
    memset((void *)fb->addrCb, 0x80, strideY * height >> 2);

    fb->mvColBuf = fb->addrCr + strideY / divX * height / divY;

    return fb;
}

struct frame_buf *tiled_framebuf_alloc(int stdMode, int format, int strideY, int height)
{
    struct frame_buf *fb;
    int err;
    int divX, divY;
    uint32_t lum_top_base, lum_bot_base, chr_top_base, chr_bot_base;
    uint32_t lum_top_20bits, lum_bot_20bits, chr_top_20bits, chr_bot_20bits;
    int luma_aligned_size, chroma_aligned_size;

    fb = get_framebuf();
    if (fb == NULL)
        return NULL;

    divX = (format == MODE420 || format == MODE422) ? 2 : 1;
    divY = (format == MODE420 || format == MODE224) ? 2 : 1;

    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));

    /*
     * The buffers is luma top, chroma top, luma bottom and chroma bottom for
     * tiled map type, and only 20bits for the address description, so we need
     * to do 4K page align for each buffer.
     */
    luma_aligned_size = (((strideY * height / 2 + 4095) >> 12) << 12) * 2;
    chroma_aligned_size = ((strideY / divX * height / divY + 4095) >> 12) << 12;
    fb->desc.size = luma_aligned_size + chroma_aligned_size * 2;
    fb->desc.size += strideY / divX * height / divY;

    err = IOGetMem(&fb->desc);
    if (err) {
        printf("Frame buffer allocation failure\n");
        memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
        return NULL;
    }

    lum_top_base = fb->desc.phy_addr;
    lum_bot_base = lum_top_base + luma_aligned_size / 2;
    chr_top_base = lum_top_base + luma_aligned_size;
    chr_bot_base = chr_top_base + chroma_aligned_size;

    lum_top_20bits = lum_top_base >> 12;
    lum_bot_20bits = lum_bot_base >> 12;
    chr_top_20bits = chr_top_base >> 12;
    chr_bot_20bits = chr_bot_base >> 12;

    fb->addrY = (lum_top_20bits << 12) + (chr_top_20bits >> 8);
    fb->addrCb = (chr_top_20bits << 24) + (lum_bot_20bits << 4) + (chr_bot_20bits >> 16);
    fb->addrCr = chr_bot_20bits << 16;
    fb->strideY = strideY;
    fb->strideC = strideY / divX;
    fb->mvColBuf = chr_bot_base + chroma_aligned_size;

    return fb;
}

void framebuf_free(struct frame_buf *fb)
{
    if (fb->desc.virt_uaddr) {
        IOFreeMem(&fb->desc);
    }

    if (fb->desc.phy_addr) {
        IOFreeMem(&fb->desc);
    }

    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
    put_framebuf(fb);
}
