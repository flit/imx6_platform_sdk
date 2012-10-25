/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _LCDC_COMMON_H_
#define _LCDC_COMMON_H_

#define VGA_FW 			640
#define VGA_FH 			480

#define WVGA_FW 		800
#define WVGA_FH 		480

#define SVGA_FW 		800
#define SVGA_FH 		600

#define WQVGA_FW		480
#define WQVGA_FH		272

#define FRAME_WIDTH 	WVGA_FW
#define FRAME_HEIGHT	WVGA_FH

#define is_yuv_format(fmt) (fmt>=0x100) ? 1 : 0
#define PXP_CROP_NEEDED(w,h) (w==FRAME_WIDTH\
	&& h==FRAME_HEIGHT) ? 0 : 1

#define DDR_LCD_BASE1				0x90000000
#define DDR_LCD_BASE2				0x90100000

#define DDR_PXP_PS_BASE1			0x90200000
#define DDR_PXP_PS_BASE2			0x90300000

enum color_space {
    RGB = 0x0,
    GRAY = 0x8,
    RGB565 = 0x10,
    RGB666 = 0x12,
    RGB666H = 0x16,
    RGB888 = 0x18,
    RGBA8888 = 0x20,

    YUV = 0x100,
    YUV888 = 0x118,
    YUV420 = 0x10C,
    YUV420P = 0x20C,
    YUV422 = 0x110,
    YUV422P = 0x210,
    YUVA8888 = 0x120,
};

enum pxp_output_color {
    OARGB8888 = 0x0,
    ORGB888 = 0x1,
    ORGB888P = 0x2,
    OARGB1555 = 0x3,
    ORGB565 = 0x4,
    ORGB555 = 0x5,
    OYUV444 = 0x7,
    OMONOC8 = 0x8,
    OMONOC4 = 0x9,
    OUYVY1P422 = 0xA,
    OVYUY1P422 = 0xB,
    OYUV2P422 = 0xC,
    OYUV2P420 = 0xD,
    OYVU2P422 = 0xE,
};

enum tv_mode {
    TVPAL,
    TVNTSC,
};

enum disp_clk_src {
    CLK_REF = 0,
    CLK_XTAL = 1,
};

struct s0InputYUVBuf {
    unsigned int bufY;
    unsigned int bufU;
    unsigned int bufV;
    unsigned char xOffset;
    unsigned char yOffset;
    unsigned char width;
    unsigned char height;
};
struct s0OutputRGBBuf {
    unsigned int addr;
    unsigned char cropXOffset;
    unsigned char cropYOffset;
    unsigned char cropWidth;
    unsigned char cropHeight;
    unsigned short width;
    unsigned short height;
    unsigned int alpha;
};

struct s0PlaneScale {
    unsigned int s0Background;
    unsigned int s0Xscale;
    unsigned int s0Yscale;
    struct s0InputYUVBuf inputBuf;
    struct s0OutputRGBBuf outputBuf;
};

struct s0OverlayInfo {
    char filename[16];
    unsigned char alpha;
    unsigned char alphaCntl;
    unsigned char colorkeyEnable;
    unsigned char dataFormat;
    unsigned char xOffset;
    unsigned char yOffset;
    unsigned char width;
    unsigned char height;
    unsigned char overlayEnable;
};

typedef struct pxp_s0_proc_params {
    int scaleEnable;
    int cropEnable;

    unsigned int inFormat;
    unsigned int outFormat;

    struct s0PlaneScale s0Plane;
    struct s0OverlayInfo Ol0Plane;
} pxp_s0_proc_params_t;

typedef struct lcdif_sync_waveform {
    unsigned int frameWidth;
    unsigned int frameHeight;
    unsigned int enPresent;
    unsigned int hsyncPol;
    unsigned int vSyncPol;
    unsigned int dotclkPol;
    unsigned int enablePol;
    unsigned int vSyncPulseUnit;
    unsigned int vSyncPeriodUnit;
    unsigned int vSyncPulseWidth;
    unsigned int vSyncPeriod;
    unsigned int hSyncPulseWidth;
    unsigned int hSyncPeriod;

    unsigned int hWaitCount;
    unsigned int vWaitCount;
    unsigned int hValidDataCount;
} lcdif_sync_waveform_t;

void lcdif_power_on(void);
void lcdif_backlight_on(void);
void lcdif_clock_enable(void);
void lcdif_display_delay(int cycles);
void lcdif_display_setup(void);
void image_center_copy(void);

void pxp_csc_process();
void pxp_disable(void);

#endif
