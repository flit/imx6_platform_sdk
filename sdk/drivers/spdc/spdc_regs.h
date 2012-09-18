/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _SPDC_REGS_H_
#define _SPDC_REGS_H_

#include <hardware.h>           // Hardware definitions

#if !defined(SPDC_BASE_ADDR)
#if defined(CHIP_MX6SL)
#define SPDC_BASE_ADDR 0x020E8000
#else
#error	SPDC is not supported on the platform!!!
#endif 
#endif

//*************************************
// Register addresses
//*************************************

/*
 * Register field definitions
 */
#define SPDC_EPD_DISP_TRIGGER		(SPDC_BASE_ADDR + 0x00)
#define SPDC_EPD_UPDATE_X_Y			(SPDC_BASE_ADDR + 0x04)
#define SPDC_EPD_UPDATE_W_H			(SPDC_BASE_ADDR + 0x08)
#define SPDC_EPD_LUT_PARA_UPDATE	(SPDC_BASE_ADDR + 0x0C)
#define SPDC_EPD_OPERATE			(SPDC_BASE_ADDR + 0x10)
#define SPDC_EPD_PANEL_INIT_SET		(SPDC_BASE_ADDR + 0x14)
#define SPDC_EPD_TEMPER_SETTING		(SPDC_BASE_ADDR + 0x18)
#define SPDC_EPD_NEXT_BUF			(SPDC_BASE_ADDR + 0x1C)
#define SPDC_EPD_CURRENT_BUF		(SPDC_BASE_ADDR + 0x20)
#define SPDC_EPD_PREVIOUS_BUF		(SPDC_BASE_ADDR + 0x24)
#define SPDC_EPD_FRM_CNT_BUF		(SPDC_BASE_ADDR + 0x28)
#define SPDC_EPD_LUT_BUF			(SPDC_BASE_ADDR + 0x2C)
#define SPDC_EPD_INT_EN				(SPDC_BASE_ADDR + 0x30)
#define SPDC_EPD_INT_ST_CLR			(SPDC_BASE_ADDR + 0x34)
#define SPDC_EPD_INT_STATUS			(SPDC_BASE_ADDR + 0x38)
#define SPDC_EPD_STATUS				(SPDC_BASE_ADDR + 0x3C)
#define SPDC_EPD_PANEL_TYPE_VER		(SPDC_BASE_ADDR + 0x40)
#define SPDC_EPD_TCON_VER			(SPDC_BASE_ADDR + 0x44)
#define SPDC_EPD_SW_GATE_CLK		(SPDC_BASE_ADDR + 0x48)

#endif // _SPDC_REGS_H_
