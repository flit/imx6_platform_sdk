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

#ifndef _SPDC_H_
#define _SPDC_H_

#include "sdk_types.h"

#define TRUE 1
#define FALSE 0

#define MODE0 //Gray refresh mode with flashing
#define MODE1 //Gray refresh mdoe without flashing
#define MODE2 //Text mode
#define MODE3 //hand writing mode

/*
 * Enable this define to have a default panel
 * loaded during driver initialization
 */
//#define DEFAULT_PANEL_HW_INIT

#define SPDC_HSIZE 800
#define SPDC_VSIZE 600

/*SPDC memory map*/
#if defined(CHIP_MX6SL)
#define WV_DATA_ADDR			0x93000000
#define EPD_NEXT_BUF_ADDR		0x93100000
#define EPD_CUR_BUF_ADDR		0x93200000
#define EPD_PREV_BUF_ADDR		0x93300000
#define EPD_FRM_CNT_BUF_ADDR	0x93400000
#define EPD_LUT_BUF_ADDR		0x93500000
#else
#error SPDC is not supported on the platform
#endif


enum epd_operation {
	SW_TCON_RESET,
	DISP_RESET,
	DEEP_REFRESH,
	DISP_REFRESH,
};

#endif /*_SPDC_H_*/
