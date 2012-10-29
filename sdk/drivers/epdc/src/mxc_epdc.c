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

#include "epdc/epdc_regs.h"
#include "epdc/epdc.h"
#include "epdc/waveform_data.h"
#include "epdc/fsl_image.h"
#include "sdk.h"
//#include "functions.h"

void check_waveform(unsigned int *wv_buf_orig, unsigned int *wv_buf_cur, unsigned int wv_buf_size)
{
    int i;
    int is_mismatch = FALSE;

    for (i = 0; i < wv_buf_size; i++) {
        if (wv_buf_orig[i] != wv_buf_cur[i]) {
            is_mismatch = TRUE;
            printf("Waveform mismatch - wv_buf_orig[%d] = 0x%x, wv_buf_cur[%d] = 0x%x\n",
                   i, wv_buf_orig[i], i, wv_buf_cur[i]);
        }
    }

    if (!is_mismatch)
        printf("No mismatches!\n");
}

/********************************************************
 * Start Low-Level EPDC Functions
 ********************************************************/

void epdc_clk_gate(int on_off)
{
    /* zero for normal operation */
    if (on_off) {
        // Enable clock gating (clear to enable)
        writel(EPDC_CTRL_CLKGATE, EPDC_CTRL_CLEAR);
    } else {
        // Disable clock gating
        writel(EPDC_CTRL_CLKGATE, EPDC_CTRL_SET);
    }
}

void epdc_reset(void)
{
    writel(EPDC_CTRL_SFTRST, EPDC_CTRL_SET);

    while (!(readl(EPDC_CTRL) & EPDC_CTRL_CLKGATE)) ;

    writel(EPDC_CTRL_SFTRST, EPDC_CTRL_CLEAR);  // clear the soft reset

    epdc_clk_gate(TRUE);

    while (readl(EPDC_CTRL) & (EPDC_CTRL_SFTRST | EPDC_CTRL_CLKGATE)) ;

}

void epdc_set_update_swizzle(unsigned int upd_swizzle)
{
    unsigned int val = readl(EPDC_CTRL);

    val &= ~EPDC_CTRL_UPD_DATA_SWIZZLE_MASK;
    val |= upd_swizzle;
    writel(val, EPDC_CTRL_SET);
}

void epdc_set_lut_swizzle(unsigned int lut_swizzle)
{
    unsigned int val = readl(EPDC_CTRL);

    val &= ~EPDC_CTRL_LUT_DATA_SWIZZLE_MASK;
    val |= lut_swizzle;
    writel(val, EPDC_CTRL_SET);
}

void epdc_lut_complete_intr(unsigned int lut_num, int enable)
{
    if (enable)
        writel(1 << lut_num, EPDC_IRQ_MASK_SET);
    else
        writel(1 << lut_num, EPDC_IRQ_MASK_CLEAR);
}

void epdc_lut_collision_intr(int enable)
{
    if (enable)
        writel(EPDC_IRQ_LUT_COL_IRQ, EPDC_IRQ_MASK_SET);
    else
        writel(EPDC_IRQ_LUT_COL_IRQ, EPDC_IRQ_MASK_CLEAR);
}

void epdc_working_buf_intr(int enable)
{
    if (enable)
        writel(EPDC_IRQ_WB_CMPLT_IRQ, EPDC_IRQ_MASK_SET);
    else
        writel(EPDC_IRQ_WB_CMPLT_IRQ, EPDC_IRQ_MASK_CLEAR);
}

void epdc_clear_working_buf_irq(void)
{
    writel(EPDC_IRQ_WB_CMPLT_IRQ | EPDC_IRQ_LUT_COL_IRQ, EPDC_IRQ_CLEAR);
}

void epdc_set_waveform_addr(unsigned int addr)
{
    writel(addr, EPDC_WV_ADDR);
}

void epdc_set_temp(unsigned int temp)
{
    writel(temp, EPDC_TEMP);
}

void epdc_set_screen_res(unsigned int width, unsigned int height)
{
    unsigned int val = (height << EPDC_RES_VERTICAL_OFFSET) | width;
    writel(val, EPDC_RES);
}

void epdc_set_working_buf_addr(unsigned int addr)
{
    writel(addr, EPDC_WB_ADDR);
#ifdef CHIP_MX6SL
	writel(addr, EPDC_PIGEON_16_1);
#endif
}

void epdc_set_update_addr(unsigned int addr)
{
    writel(addr, EPDC_UPD_ADDR);
}

void epdc_set_update_coord(unsigned int x, unsigned int y)
{
    unsigned int val = (y << EPDC_UPD_CORD_YCORD_OFFSET) | x;
    writel(val, EPDC_UPD_CORD);
}

void epdc_set_update_dimensions(unsigned int width, unsigned int height)
{
    unsigned int val = (height << EPDC_UPD_SIZE_HEIGHT_OFFSET) | width;
    writel(val, EPDC_UPD_SIZE);
}

void epdc_submit_update(unsigned int lut_num, unsigned int waveform_mode,
                        unsigned int update_mode, int use_test_mode, unsigned int np_val)
{
    unsigned int reg_val = 0;

    if (use_test_mode) {
        reg_val |=
            ((np_val << EPDC_UPD_FIXED_FIXNP_OFFSET) &
             EPDC_UPD_FIXED_FIXNP_MASK) | EPDC_UPD_FIXED_FIXNP_EN;

        writel(reg_val, EPDC_UPD_FIXED);

        reg_val = EPDC_UPD_CTRL_USE_FIXED;
    } else {
        reg_val = 0;

        writel(reg_val, EPDC_UPD_FIXED);
    }

    reg_val |=
        ((lut_num << EPDC_UPD_CTRL_LUT_SEL_OFFSET) &
         EPDC_UPD_CTRL_LUT_SEL_MASK) |
        ((waveform_mode << EPDC_UPD_CTRL_WAVEFORM_MODE_OFFSET) &
         EPDC_UPD_CTRL_WAVEFORM_MODE_MASK) | update_mode;

    writel(reg_val, EPDC_UPD_CTRL);
}

int epdc_is_lut_complete(unsigned int lut_num)
{
    unsigned int val = readl(EPDC_IRQ);
    int is_compl = val & (1 << lut_num) ? TRUE : FALSE;

    return is_compl;
}

void epdc_clear_lut_complete_irq(unsigned int lut_num)
{
    writel(1 << lut_num, EPDC_IRQ_CLEAR);
}

int epdc_is_lut_active(unsigned int lut_num)
{
    unsigned int val = readl(EPDC_STATUS_LUTS);
    int is_active = val & (1 << lut_num) ? TRUE : FALSE;

    return is_active;
}

int epdc_any_luts_active(void)
{
    int any_active = readl(EPDC_STATUS_LUTS) ? TRUE : FALSE;

    return any_active;
}

int epdc_any_luts_available(void)
{
    int luts_available =
        (readl(EPDC_STATUS_NEXTLUT) & EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID) ? TRUE : FALSE;
    return luts_available;
}

int epdc_get_next_lut(void)
{
    unsigned int val = readl(EPDC_STATUS_NEXTLUT) & EPDC_STATUS_NEXTLUT_NEXT_LUT_MASK;
    return val;
}

int epdc_is_working_buffer_busy(void)
{
    unsigned int val = readl(EPDC_STATUS);
    int is_busy = (val & EPDC_STATUS_WB_BUSY) ? TRUE : FALSE;

    return is_busy;
}

int epdc_is_working_buffer_complete(void)
{
    unsigned int val = readl(EPDC_IRQ);
    int is_compl = (val & EPDC_IRQ_WB_CMPLT_IRQ) ? TRUE : FALSE;

    return is_compl;
}

int epdc_is_collision(void)
{
    unsigned int val = readl(EPDC_IRQ);
    int is_compl = (val & EPDC_IRQ_LUT_COL_IRQ) ? TRUE : FALSE;

    return is_compl;
}

int epdc_get_colliding_luts(void)
{
    unsigned int val = readl(EPDC_STATUS_COL);
    return val;
}

void epdc_dump_registers(void)
{
    unsigned int reg = EPDC_BASE_ADDR;

    for (reg = EPDC_BASE_ADDR; reg < EPDC_BASE_ADDR + 0x800; reg += 0x10)
        printf("reg %08x : %08x\n", reg, readl(reg));
}

void epdc_set_horizontal_timing(unsigned int horiz_start, unsigned int horiz_end,
                                unsigned int hsync_width, unsigned int hsync_line_length)
{
    unsigned int reg_val =
        ((hsync_width << EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_OFFSET) &
         EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_MASK)
        | ((hsync_line_length << EPDC_TCE_HSCAN1_LINE_SYNC_OFFSET) &
           EPDC_TCE_HSCAN1_LINE_SYNC_MASK);
    writel(reg_val, EPDC_TCE_HSCAN1);

    reg_val = ((horiz_start << EPDC_TCE_HSCAN2_LINE_BEGIN_OFFSET) & EPDC_TCE_HSCAN2_LINE_BEGIN_MASK)
        | ((horiz_end << EPDC_TCE_HSCAN2_LINE_END_OFFSET) & EPDC_TCE_HSCAN2_LINE_END_MASK);
    writel(reg_val, EPDC_TCE_HSCAN2);
}

void epdc_set_vertical_timing(unsigned int vert_start, unsigned int vert_end,
                              unsigned int vsync_width)
{
    unsigned int reg_val =
        ((vert_start << EPDC_TCE_VSCAN_FRAME_BEGIN_OFFSET) & EPDC_TCE_VSCAN_FRAME_BEGIN_MASK)
        | ((vert_end << EPDC_TCE_VSCAN_FRAME_END_OFFSET) & EPDC_TCE_VSCAN_FRAME_END_MASK)
        | ((vsync_width << EPDC_TCE_VSCAN_FRAME_SYNC_OFFSET) & EPDC_TCE_VSCAN_FRAME_SYNC_MASK);
    writel(reg_val, EPDC_TCE_VSCAN);
}

void epdc_init_settings(void)
{
    unsigned int reg_val;
	int left_margin, right_margin, xres, yres, upper_margin, lower_margin, hsync_len, vsync_len;
	int vscan_holdoff, sdoed_width, sdoed_delay, sdoez_width, sdoez_delay, gdclk_hp_offs, gdsp_offs, gdoe_offs, gdclk_offs, num_ce;

	/*set timming for E060 panel, fresh rate is 85, pclk is 26.667MHz*/
	left_margin = 8;
	right_margin = 100;
	upper_margin = 4;
	lower_margin = 8;
	hsync_len = 4;
	vsync_len = 1;
	xres = EPDC_HSIZE;
	yres = EPDC_VSIZE;

	/*set scan mode*/
	vscan_holdoff = 4;
	sdoed_width = 10;
	sdoed_delay = 20;
	sdoez_width = 10;
	sdoez_delay = 20;
	gdclk_hp_offs = 419;
	gdsp_offs = 20;
	gdoe_offs = 0;
	gdclk_offs = 5;
	num_ce = 1;

    /* Reset */
    epdc_reset();

    /* EPDC_CTRL, set data format, no data swizzle */
    epdc_set_update_swizzle(EPDC_CTRL_UPD_DATA_SWIZZLE_ALL_BYTES_SWAP);
    epdc_set_lut_swizzle(EPDC_CTRL_LUT_DATA_SWIZZLE_NO_SWAP);

    /* EPDC_FORMAT - 2bit TFT and 4bit Buf pixel format, truncate data */
    reg_val = EPDC_FORMAT_TFT_PIXEL_FORMAT_2BIT
        | EPDC_FORMAT_BUF_PIXEL_FORMAT_P4N
        | ((0x0 << EPDC_FORMAT_DEFAULT_TFT_PIXEL_OFFSET) & EPDC_FORMAT_DEFAULT_TFT_PIXEL_MASK);
    writel(reg_val, EPDC_FORMAT);

    /* EPDC_FIFOCTRL (disabled) */
    reg_val = ((100 << EPDC_FIFOCTRL_FIFO_INIT_LEVEL_OFFSET) & EPDC_FIFOCTRL_FIFO_INIT_LEVEL_MASK)
        | ((200 << EPDC_FIFOCTRL_FIFO_H_LEVEL_OFFSET) & EPDC_FIFOCTRL_FIFO_H_LEVEL_MASK)
        | ((100 << EPDC_FIFOCTRL_FIFO_L_LEVEL_OFFSET) & EPDC_FIFOCTRL_FIFO_L_LEVEL_MASK);
    writel(reg_val, EPDC_FIFOCTRL);

    /* EPDC_TEMP - 8 for room temperature */
    epdc_set_temp(8);

    /* EPDC_RES */
    epdc_set_screen_res(EPDC_HSIZE, EPDC_VSIZE);

    /* EPDC_WB_ADDR */
    epdc_set_working_buf_addr(WB_DATA_ADDR);

    /* EPDC_WV_ADDR */
    epdc_set_waveform_addr(WV_DATA_ADDR);

    /*
     * EPDC_TCE_CTRL
     * VSCAN_HOLDOFF = 4
     * VCOM_MODE = MANUAL
     * VCOM_VAL = 0
     * DDR_MODE = DISABLED
     * LVDS_MODE_CE = DISABLED
     * LVDS_MODE = DISABLED
     * DUAL_SCAN = DISABLED
     * SDDO_WIDTH = 8bit
     * PIXELS_PER_SDCLK = 4
     */
    reg_val = ((4 << EPDC_TCE_CTRL_VSCAN_HOLDOFF_OFFSET) & EPDC_TCE_CTRL_VSCAN_HOLDOFF_MASK)
        | EPDC_TCE_CTRL_PIXELS_PER_SDCLK_4;
    writel(reg_val, EPDC_TCE_CTRL);

    /* EPDC_TCE_HSCAN */
    epdc_set_horizontal_timing(left_margin, right_margin, hsync_len, hsync_len);

    /* EPDC_TCE_VSCAN */
    epdc_set_vertical_timing(upper_margin, lower_margin, vsync_len);

    /* EPDC_TCE_OE */
    reg_val = ((sdoed_width << EPDC_TCE_OE_SDOED_WIDTH_OFFSET) & EPDC_TCE_OE_SDOED_WIDTH_MASK)
        | ((sdoed_delay << EPDC_TCE_OE_SDOED_DLY_OFFSET) & EPDC_TCE_OE_SDOED_DLY_MASK)
        | ((sdoez_width << EPDC_TCE_OE_SDOEZ_WIDTH_OFFSET) & EPDC_TCE_OE_SDOEZ_WIDTH_MASK)
        | ((sdoez_delay << EPDC_TCE_OE_SDOEZ_DLY_OFFSET) & EPDC_TCE_OE_SDOEZ_DLY_MASK);
    writel(reg_val, EPDC_TCE_OE);

    /* EPDC_TCE_TIMING1 */
    writel(0x0, EPDC_TCE_TIMING1);

    /* EPDC_TCE_TIMING2 */
    reg_val = ((gdclk_hp_offs << EPDC_TCE_TIMING2_GDCLK_HP_OFFSET) & EPDC_TCE_TIMING2_GDCLK_HP_MASK)
        | ((gdsp_offs << EPDC_TCE_TIMING2_GDSP_OFFSET_OFFSET) & EPDC_TCE_TIMING2_GDSP_OFFSET_MASK);
    writel(reg_val, EPDC_TCE_TIMING2);

    /* EPDC_TCE_TIMING3 */
    reg_val = ((gdoe_offs << EPDC_TCE_TIMING3_GDOE_OFFSET_OFFSET) & EPDC_TCE_TIMING3_GDOE_OFFSET_MASK)
        | ((gdclk_offs << EPDC_TCE_TIMING3_GDCLK_OFFSET_OFFSET) & EPDC_TCE_TIMING3_GDCLK_OFFSET_MASK);
    writel(reg_val, EPDC_TCE_TIMING3);

    /*
     * EPDC_TCE_SDCFG
     * SDCLK_HOLD = 1
     * SDSHR = 1
     * NUM_CE = 1
     * SDDO_REFORMAT = FLIP_PIXELS
     * SDDO_INVERT = DISABLED
     * PIXELS_PER_CE = display horizontal resolution
     */
    reg_val = EPDC_TCE_SDCFG_SDCLK_HOLD | EPDC_TCE_SDCFG_SDSHR
        | ((num_ce << EPDC_TCE_SDCFG_NUM_CE_OFFSET) & EPDC_TCE_SDCFG_NUM_CE_MASK)
        | EPDC_TCE_SDCFG_SDDO_REFORMAT_FLIP_PIXELS
        | ((EPDC_HSIZE << EPDC_TCE_SDCFG_PIXELS_PER_CE_OFFSET) & EPDC_TCE_SDCFG_PIXELS_PER_CE_MASK);
    writel(reg_val, EPDC_TCE_SDCFG);

    /*
     * EPDC_TCE_GDCFG
     * GDRL = 1
     * GDOE_MODE = 0;
     * GDSP_MODE = 0;
     */
    reg_val = EPDC_TCE_SDCFG_GDRL;
    writel(reg_val, EPDC_TCE_GDCFG);

    /*
     * EPDC_TCE_POLARITY
     * SDCE_POL = ACTIVE LOW
     * SDLE_POL = ACTIVE HIGH
     * SDOE_POL = ACTIVE HIGH
     * GDOE_POL = ACTIVE HIGH
     * GDSP_POL = ACTIVE LOW
     */
    reg_val = EPDC_TCE_POLARITY_SDLE_POL_ACTIVE_HIGH
        | EPDC_TCE_POLARITY_SDOE_POL_ACTIVE_HIGH | EPDC_TCE_POLARITY_GDOE_POL_ACTIVE_HIGH;
    writel(reg_val, EPDC_TCE_POLARITY);

    /* EPDC_IRQ_MASK */
    writel(0x0007FFFF, EPDC_IRQ_MASK);

    /*
     * EPDC_GPIO
     * PWRCOM = ?
     * PWRCTRL = ?
     * BDR = ?
     */
    reg_val = ((0 << EPDC_GPIO_PWRCTRL_OFFSET) & EPDC_GPIO_PWRCTRL_MASK)
        | ((0 << EPDC_GPIO_BDR_OFFSET) & EPDC_GPIO_BDR_MASK);
    writel(reg_val, EPDC_GPIO);
}


void epdc_buffer_init(void)
{
    memcpy((void *)WV_DATA_ADDR, wv_data, WV_SIZE * 4);

    memset((void *)WB_DATA_ADDR, 0x00, EPDC_VSIZE * EPDC_HSIZE / 2 * 4);

    memset((void *)UPD_BUFFER_MODE_0_ADDR, 0xFF, EPDC_VSIZE * EPDC_HSIZE / 2 * 4);
}

void epdc_load_image(void)
{
    memcpy((void *)IMAGE_STORE_0_ADDR, fsl_gray_600x230, 600 * 230);
}
