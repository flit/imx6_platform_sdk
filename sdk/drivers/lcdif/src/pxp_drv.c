/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
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

#include "lcdif/lcdif_common.h"
#include "lcdif/pxp_regs.h"
#include "sdk.h"
//#include "functions.h"

int pxp_sw_reset(void)
{
    writel(0x80000000, HW_PXP_CTRL);
    lcdif_display_delay(0x1000);
    writel(0x00000000, HW_PXP_CTRL);

    return 0;
}

void pxp_proc_timeout(int time)
{
    while ((readl(HW_PXP_STAT) & 0x1) == 0) {
        time--;
        if (time == 0)
            break;
    };
    writel(0x1, HW_PXP_STAT_CLR);
}

void pxp_clock_enable(void)
{
    /* always on MX6SL */
}

void pxp_disable(void)
{
    writel(0x1, HW_PXP_CTRL_CLR);
}

void pxp_csc_process(void)
{
    pxp_clock_enable();
    pxp_sw_reset();

    writel(DDR_PXP_PS_BASE1, HW_PXP_PS_BUF);
    writel(VGA_FW * 2, HW_PXP_PS_PITCH);    // bytes between two vertically adj pixels
    writel(0xFFFFFF, HW_PXP_PS_BACKGROUND); //background is white
    writel(0x10001000, HW_PXP_PS_SCALE);    //1:1 scale

    writel(DDR_LCD_BASE1, HW_PXP_OUT_BUF);
    writel(FRAME_WIDTH * 2, HW_PXP_OUT_PITCH_WR);
    writel(((FRAME_WIDTH - 1) << 16) | (FRAME_HEIGHT - 1), HW_PXP_OUT_LRC);
    writel(0x0, HW_PXP_OUT_PS_ULC); //left upper corner (0, 0)
    writel(((VGA_FW - 1) << 16) | (VGA_FH - 1), HW_PXP_OUT_PS_LRC); //low right corner (width-1, height-1)

    writel(0x1F, HW_PXP_PS_CTRL_CLR);
    writel(0x12, HW_PXP_PS_CTRL_SET);   /*U0Y0V0Y1 */

    writel(0x1F, HW_PXP_OUT_CTRL_CLR);
    writel(0xE, HW_PXP_OUT_CTRL_SET);   /*RGB565 */

    // YCbCr->RGB coefficients
    writel(0x84AB01F0, HW_PXP_CSC1_COEF0);
    writel(0x01980204, HW_PXP_CSC1_COEF1);
    writel(0x0730079C, HW_PXP_CSC1_COEF2);

    writel(0x10000001, HW_PXP_CTRL_SET);
}
