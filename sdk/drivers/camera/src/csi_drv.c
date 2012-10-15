/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifdef MX6SL

#include "sdk.h"
#include "csi_regs.h"
#include "lcdc/lcdc_common.h"

void csi_setup(void)
{
    volatile uint32_t regval = 0;

    /* Timing control */
    reg32setbit(CSI_CSICR1, 30);    //VSYNC external generated on rising edge
    reg32clrbit(CSI_CSICR1, 1); //Pixel data latched at falling edge of CSI_PIXCLK
    reg32setbit(CSI_CSICR1, 4); //Gated clock mode
    reg32setbit(CSI_CSICR1, 11);    //HSYNC is active high
    reg32clrbit(CSI_CSICR1, 0); //8-bit

    /* FIFO control */
    /* sensor in:       Y0 U0 Y1 V0
     * before Rx FIFO:  Y0U0Y1V0
     * in Rx FIFO:      Y1VV0Y0U0*/
    reg32setbit(CSI_CSICR1, 7); //little endian: pack from LSB first
    reg32setbit(CSI_CSICR1, 31);    //enable 16-bit swapping

    writel(0x25800, CSI_CSIRXCNT);

    /* buffer address: word aligned */
#if 1
    writel(DDR_PXP_PS_BASE1, CSI_CSIDMASA_FB1);
    writel(DDR_PXP_PS_BASE2, CSI_CSIDMASA_FB2);
#else
    writel(DDR_LCD_BASE1, CSI_CSIDMASA_FB1);
    writel(DDR_LCD_BASE2, CSI_CSIDMASA_FB2);
#endif

    /* image format */
    /* frame width * height (in pixel) */
    writel((VGA_FW * 2) << 16 | (VGA_FH * 2), CSI_CSIIMAG_PARA);    //10bit 640*480 (*2pixels)
    /* stride line (in word) */
//    regval = readl(CSI_CSIFBUF_PARA) & (~0xFFFF);
//    regval |= (WVGA_FW - VGA_FW) / 2;
//    writel(regval, CSI_CSIFBUF_PARA);

    /* DMA control */
    regval = readl(CSI_CSICR3) & (~0x70);
    regval |= 0x6 << 4;
    writel(regval, CSI_CSICR3); //RxFIFO full level: 64 words
    reg32setbit(CSI_CSICR3, 12);    //enable DMA_REQ_EN_REF, enable dma request
    reg32setbit(CSI_CSICR3, 14);    //reflash embedded DMA controller
}

#endif
