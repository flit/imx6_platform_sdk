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

#ifndef _PXP_REGS_H_
#define _PXP_REGS_H_

#include "sdk.h"           // Hardware definitions

#define PXP_BASE_ADDR				EPXP_BASE_ADDR

#define HW_PXP_CTRL 				(PXP_BASE_ADDR + 0x000)
#define HW_PXP_CTRL_SET 			(PXP_BASE_ADDR + 0x004)
#define HW_PXP_CTRL_CLR 			(PXP_BASE_ADDR + 0x008)
#define HW_PXP_CTRL_TOG 			(PXP_BASE_ADDR + 0x00C)
#define HW_PXP_STAT 				(PXP_BASE_ADDR + 0x010)
#define HW_PXP_STAT_SET 			(PXP_BASE_ADDR + 0x014)
#define HW_PXP_STAT_CLR 			(PXP_BASE_ADDR + 0x018)
#define HW_PXP_STAT_TOG 			(PXP_BASE_ADDR + 0x01C)

#define HW_PXP_OUT_CTRL				(PXP_BASE_ADDR + 0x020)
#define HW_PXP_OUT_CTRL_SET			(PXP_BASE_ADDR + 0x024)
#define HW_PXP_OUT_CTRL_CLR			(PXP_BASE_ADDR + 0x028)
#define HW_PXP_OUT_CTRL_TOG			(PXP_BASE_ADDR + 0x02C)
#define HW_PXP_OUT_BUF				(PXP_BASE_ADDR + 0x030)
#define HW_PXP_OUT_BUF2				(PXP_BASE_ADDR + 0x040)
#define HW_PXP_OUT_PITCH_WR			(PXP_BASE_ADDR + 0x050)
#define HW_PXP_OUT_LRC				(PXP_BASE_ADDR + 0x060)
#define HW_PXP_OUT_PS_ULC			(PXP_BASE_ADDR + 0x070)
#define HW_PXP_OUT_PS_LRC			(PXP_BASE_ADDR + 0x080)
#define HW_PXP_OUT_AS_ULC			(PXP_BASE_ADDR + 0x090)
#define HW_PXP_OUT_AS_LRC			(PXP_BASE_ADDR + 0x0A0)

#define HW_PXP_PS_CTRL				(PXP_BASE_ADDR + 0x0B0)
#define HW_PXP_PS_CTRL_SET			(PXP_BASE_ADDR + 0x0B4)
#define HW_PXP_PS_CTRL_CLR			(PXP_BASE_ADDR + 0x0B8)
#define HW_PXP_PS_CTRL_TOG			(PXP_BASE_ADDR + 0x0BC)
#define HW_PXP_PS_BUF				(PXP_BASE_ADDR + 0x0C0)
#define HW_PXP_PS_UBUF				(PXP_BASE_ADDR + 0x0D0)
#define HW_PXP_PS_VBUF				(PXP_BASE_ADDR + 0x0E0)
#define HW_PXP_PS_PITCH				(PXP_BASE_ADDR + 0x0F0)
#define HW_PXP_PS_BACKGROUND		(PXP_BASE_ADDR + 0x100)
#define HW_PXP_PS_SCALE				(PXP_BASE_ADDR + 0x110)
#define HW_PXP_PS_OFFSET			(PXP_BASE_ADDR + 0x120)
#define HW_PXP_PS_CLRKEYLOW			(PXP_BASE_ADDR + 0x130)
#define HW_PXP_PS_CLRKEYHIGH		(PXP_BASE_ADDR + 0x140)

#define HW_PXP_AS_CTRL				(PXP_BASE_ADDR + 0x150)
#define HW_PXP_AS_BUF				(PXP_BASE_ADDR + 0x160)
#define HW_PXP_AS_PITCH				(PXP_BASE_ADDR + 0x170)
#define HW_PXP_AS_CLRKEYLOW			(PXP_BASE_ADDR + 0x180)
#define HW_PXP_AS_CLRKEYHIGH		(PXP_BASE_ADDR + 0x190)

#define HW_PXP_CSC1_COEF0			(PXP_BASE_ADDR + 0x1A0)
#define HW_PXP_CSC1_COEF1			(PXP_BASE_ADDR + 0x1B0)
#define HW_PXP_CSC1_COEF2			(PXP_BASE_ADDR + 0x1C0)
#define HW_PXP_CSC2_CTRL			(PXP_BASE_ADDR + 0x1D0)
#define HW_PXP_CSC2_COEF0			(PXP_BASE_ADDR + 0x1E0)
#define HW_PXP_CSC2_COEF1			(PXP_BASE_ADDR + 0x1F0)
#define HW_PXP_CSC2_COEF2			(PXP_BASE_ADDR + 0x200)
#define HW_PXP_CSC2_COEF3			(PXP_BASE_ADDR + 0x210)
#define HW_PXP_CSC2_COEF4			(PXP_BASE_ADDR + 0x220)
#define HW_PXP_CSC2_COEF5			(PXP_BASE_ADDR + 0x230)

#define HW_PXP_LUT_CTRL				(PXP_BASE_ADDR + 0x240)
#define HW_PXP_LUT_ADDR				(PXP_BASE_ADDR + 0x250)
#define HW_PXP_LUT_DATA				(PXP_BASE_ADDR + 0x260)
#define HW_PXP_LUT_EXTMEM			(PXP_BASE_ADDR + 0x270)

#define HW_PXP_CFA					(PXP_BASE_ADDR + 0x280)
#define HW_PXP_HIST_CTRL			(PXP_BASE_ADDR + 0x290)
#define HW_PXP_HIST2_PARAM			(PXP_BASE_ADDR + 0x2A0)
#define HW_PXP_HIST4_PARAM			(PXP_BASE_ADDR + 0x2B0)
#define HW_PXP_HIST8_PARAM0			(PXP_BASE_ADDR + 0x2C0)
#define HW_PXP_HIST8_PARAM1			(PXP_BASE_ADDR + 0x2D0)
#define HW_PXP_HIST16_PARAM0		(PXP_BASE_ADDR + 0x2E0)
#define HW_PXP_HIST16_PARAM1		(PXP_BASE_ADDR + 0x2F0)
#define HW_PXP_HIST16_PARAM2		(PXP_BASE_ADDR + 0x300)
#define HW_PXP_HIST16_PARAM3		(PXP_BASE_ADDR + 0x310)

#define HW_PXP_POWER				(PXP_BASE_ADDR + 0x320)
#define HW_PXP_NEXT					(PXP_BASE_ADDR + 0x330)

#endif
