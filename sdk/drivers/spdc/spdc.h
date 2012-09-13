/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _SPDC_H_
#define _SPDC_H_

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
//#if defined(MX6SL)
#define WV_DATA_ADDR			0x93000000
#define EPD_NEXT_BUF_ADDR		0x93100000
#define EPD_CUR_BUF_ADDR		0x93200000
#define EPD_PREV_BUF_ADDR		0x93300000
#define EPD_FRM_CNT_BUF_ADDR	0x93400000
#define EPD_LUT_BUF_ADDR		0x93500000
//#else
//#error SPDC is not supported on the platform
//#endif


enum epd_operation {
	SW_TCON_RESET,
	DISP_RESET,
	DEEP_REFRESH,
	DISP_REFRESH,
};

#endif /*_SPDC_H_*/
