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

#ifndef _EPDC_H_
#define _EPDC_H_

#define TRUE 1
#define FALSE 0

/*
 * Enable this define to have a default panel
 * loaded during driver initialization
 */
//#define DEFAULT_PANEL_HW_INIT

#define NUM_SCREENS	2
#define EPDC_NUM_LUTS 16
#define EPDC_MAX_NUM_UPDATES 32
#define INVALID_LUT -1
#define TEMP_USE_DEFAULT 8
#define INIT_UPDATE_MARKER 0x12345678
#define PAN_UPDATE_MARKER 0x12345679

#define LUT_UPDATE_NONE			0
#define LUT_UPDATE_NEW			1
#define LUT_UPDATE_COLLISION	2

#define POWER_STATE_OFF			0
#define POWER_STATE_ON			1

// Use waves for B077 panel
#define EPDC_B077_4BIT_WV_DATA
#define WV_SIZE 214136

#define EPDC_HSIZE 800
#define EPDC_VSIZE 600

// We need a 20MHz pixclk to achieve 50Hz display refresh
#define EPDC_PIXCLK_FRAC 27
#define EPDC_PIXCLK_PRE_DIV  2
#define EPDC_PIXCLK_POST_DIV 8

// Set Axi clock to 200MHz
#define EPDC_AXICLK_FRAC 22
#define EPDC_AXICLK_PRE_DIV 2
#define EPDC_AXICLK_POST_DIV 1


#define EPDC_UPD_UPDATE_MODE__PARTIAL  0x0
#define EPDC_UPD_UPDATE_MODE__FULL     0x1

#define 	EPDC_WV_MODE__INIT 	0
#define 	EPDC_WV_MODE__DU 		1   // black and white
#define 	EPDC_WV_MODE__GC16	2   // 16 level
#define 	EPDC_WV_MODE__GC4		3   // 4 level, low fidelity


/*EPDC memory map*/
#if defined(CHIP_MX6SDL)
#define WV_DATA_ADDR           0x23000000
#define WB_DATA_ADDR           0x23100000
#define UPD_BUFFER_MODE_0_ADDR 0x23200000
#define IMAGE_STORE_0_ADDR     0x23400000
#elif defined(CHIP_MX6SL)
#define WV_DATA_ADDR           0x93000000
#define WB_DATA_ADDR           0x93100000
#define UPD_BUFFER_MODE_0_ADDR 0x93200000
#define IMAGE_STORE_0_ADDR     0x93400000
#else
#define WV_DATA_ADDR           0x73000000
#define WB_DATA_ADDR           0x73100000
#define UPD_BUFFER_MODE_0_ADDR 0x73200000
#define IMAGE_STORE_0_ADDR     0x73400000
#endif

struct waveform_data_header {
    unsigned int wi0;
    unsigned int wi1;
    unsigned int wi2;
    unsigned int wi3;
    unsigned int wi4;
    unsigned int wi5;
    unsigned int wi6;
    unsigned int xwia:24;
    unsigned int cs1:8;
    unsigned int wmta:24;
    unsigned int fvsn:8;
    unsigned int luts:8;
    unsigned int mc:8;
    unsigned int trc:8;
    unsigned int reserved0_0:8;
    unsigned int eb:8;
    unsigned int sb:8;
    unsigned int reserved0_1:8;
    unsigned int reserved0_2:8;
    unsigned int reserved0_3:8;
    unsigned int reserved0_4:8;
    unsigned int reserved0_5:8;
    unsigned int cs2:8;
};

struct mxc_waveform_data_file {
    struct waveform_data_header wdh;
    unsigned int *data;         /* Temperature Range Table + Waveform Data */
};

typedef struct {
    struct {
        int x;
        int y;
    } coordinate;
    struct {
        int width;
        int height;
    } size;
} epdc_upd_area_t;

typedef struct eink_panel_info {
    char name[32];
    unsigned int name_flag;
    unsigned int refresh;
    unsigned int width;
    unsigned int height;
    unsigned int pixel_clock;
    unsigned int hsync_start_width;
    unsigned int hsync_width;
    unsigned int hsync_end_width;
    unsigned int vsync_start_width;
    unsigned int vsync_width;
    unsigned int vsync_end_width;
    unsigned int delay_h2v;
    unsigned int interlaced;
    unsigned int data_format;
} eink_panel_info_t;

enum eink_panel_flag {
    EINK_ED060SC4,
};

enum epdc_lut {
    EPDC_LUT0 = 0,
    EPDC_LUT1 = 1,
    EPDC_LUT2 = 2,
    EPDC_LUT3 = 3,
    EPDC_LUT4 = 4,
    EPDC_LUT5 = 5,
    EPDC_LUT6 = 6,
    EPDC_LUT7 = 7,
    EPDC_LUT8 = 8,
    EPDC_LUT9 = 9,
    EPDC_LUT10 = 10,
    EPDC_LUT11 = 11,
    EPDC_LUT12 = 12,
    EPDC_LUT13 = 13,
    EPDC_LUT14 = 14,
    EPDC_LUT15 = 15,
};

#endif /*_EPDC_H_*/
