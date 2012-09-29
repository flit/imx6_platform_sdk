/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_lcd LCD Test
 */

#include "lcdc/lcdc_common.h"
#include "lcdc/lcdc_regs.h"
#include "hardware.h"
#include "functions.h"
#include "logo.h"

extern void lcdif_clock_enable(void);
static int lcdif_initialized = 0;

void lcdif_display_delay(int cycles)
{
    while (cycles > 0) {
        cycles--;
        __asm("nop");
    }
}

/* turn on lcdif backlight power supply:
 * 3V3_LCD_CONTRAST (pin 112) controls LED+ and LED- on imx28lcd board */
void lcdif_backlight_on(void)
{
#if defined CHIP_MX6SL
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_PWM1, 0x10);  //GPIO3_23
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_PWM1, 0x5);   //GPIO3_23
    reg32setbit(GPIO3_BASE_ADDR + 0x4, 23); //set GPIO3_23 as output
    reg32setbit(GPIO3_BASE_ADDR, 23);   //set high
#else
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP_BUSY, 0x10); //GPIO2_18
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP_BUSY, 0x1);  //GPIO2_18
    reg32setbit(GPIO2_BASE_ADDR + 0x4, 18); //set GPIO2_18 as output
    reg32setbit(GPIO2_BASE_ADDR, 18);   //set high
#endif
}

/*!
 * Configure color space conversion(CSC) parameter, from RGB to YUV
 *
 * @param   enable		enable or disable the CSC process
 */
void lcdif_csc_config(int enable)
{
    if (enable) {
        /*CSC control, from RGB to YUV */
        writel(0x00410002, HW_LCDIF_CSC_COEFF0);
        writel(0x00190081, HW_LCDIF_CSC_COEFF1);
        writel(0x03B603DB, HW_LCDIF_CSC_COEFF2);
        writel(0x00700070, HW_LCDIF_CSC_COEFF3);
        writel(0x03EE03A2, HW_LCDIF_CSC_COEFF4);
        writel(0x00800010, HW_LCDIF_CSC_OFFSET);
        writel(0x10F010EB, HW_LCDIF_CSC_LIMIT);

        writel(enable << 7, HW_LCDIF_CTRL_SET);
    } else {
        writel(enable << 7, HW_LCDIF_CTRL_CLR);
    }
}

/*!
 * Reset the LCD controller by Software Mode
 */
int lcdif_sw_reset(void)
{
    writel(0x80000000, HW_LCDIF_CTRL);  //reset the LCDIF module
    lcdif_display_delay(0x100000);
    writel(0xC0000000, HW_LCDIF_CTRL_CLR);

    return 0;
}

/*!
 * Set the LCD controller waveforms to driven the panel
 *
 * @param   sync_waveform		lcd waveform setting, including hsync/vsync/drdy
 *													and blanking parameters
 */
int lcdif_waveform_setting(lcdif_sync_waveform_t sync_waveform)
{
    writel((sync_waveform.frameHeight << 16) | sync_waveform.frameWidth, HW_LCDIF_TRANSFER_COUNT);  //480*800 resolution
    writel(0x01010101, HW_LCDIF_TIMING);    // timeing setting

    writel(sync_waveform.enPresent << 28 | sync_waveform.vSyncPol << 27 | sync_waveform.hsyncPol << 26 | sync_waveform.dotclkPol << 25 | sync_waveform.enablePol << 24 | sync_waveform.vSyncPeriodUnit << 21 | sync_waveform.vSyncPulseUnit << 20 | sync_waveform.vSyncPulseWidth, HW_LCDIF_VDCTRL0);   // VSYNC setting
    writel(sync_waveform.vSyncPeriod, HW_LCDIF_VDCTRL1);    // total v width

    writel(sync_waveform.hSyncPulseWidth << 18 | sync_waveform.hSyncPeriod, HW_LCDIF_VDCTRL2);  // HSYNC setting

    writel(sync_waveform.hWaitCount << 16 | sync_waveform.vWaitCount, HW_LCDIF_VDCTRL3);
    writel(0x1 << 18 | sync_waveform.hValidDataCount, HW_LCDIF_VDCTRL4);
    return 0;
}

void lcdif_disp_init(void)
{
    lcdif_clock_enable();
    lcdif_backlight_on();

    /* pin muxing for LCD */
    if (lcdif_initialized == 0) {
        lcdif_iomux_config();

        lcdif_sw_reset();

        writel(0x00200000, HW_LCDIF_CTRL1);

        lcdif_initialized = 1;
    }
}

void setup_panel_params(lcdif_sync_waveform_t * syncWave)
{
    syncWave->frameWidth = WVGA_FW;
    syncWave->frameHeight = WVGA_FH;

    syncWave->enPresent = 1;
    syncWave->dotclkPol = 0;
    syncWave->hsyncPol = 0;
    syncWave->vSyncPol = 0;
    syncWave->enablePol = 1;
    syncWave->vSyncPeriodUnit = 1;
    syncWave->vSyncPulseUnit = 1;
    syncWave->vSyncPulseWidth = 10;

    syncWave->vSyncPeriod = 523;

    syncWave->hSyncPulseWidth = 10;
    syncWave->hSyncPeriod = 1063;

    syncWave->hWaitCount = 99;
    syncWave->vWaitCount = 33;

    syncWave->hValidDataCount = 800;
}

/* the default output format is RGB */
void lcdif_display_setup(void)
{
    lcdif_sync_waveform_t syncWave = { 0 };
    char recvCh = NONE_CHAR;

    memset((void *)DDR_LCD_BASE1, 0xFF, FRAME_WIDTH * FRAME_HEIGHT * 2);

    /* initilization for LCD */
    lcdif_disp_init();

    /* LCDIF control registers setting */
    writel(0x010F2301, HW_LCDIF_CTRL1);
    writel(DDR_LCD_BASE1, HW_LCDIF_CUR_BUF);    //frame buffer start address
    writel(DDR_LCD_BASE1, HW_LCDIF_NEXT_BUF);

    /*DOTCLK or VSYNC mode control */
    setup_panel_params(&syncWave);
    lcdif_waveform_setting(syncWave);

    printf("Please select the LCD panel type: \n");
    printf("\t0 - SEIKO 70WVW1TZ3 WVGA Panel (MX28LCD 24-bit)\n");
    printf("\t1 - CHUNHWA CLAA 070VC01 WVGA Panel (MX51LCD 16-bit)\n");
    do {
        recvCh = getchar();
    } while (recvCh == NONE_CHAR);

    if (recvCh == '0') {
        /*RGB888(24bit) in dotclk mode transfer */
        writel(0x000B0C21, HW_LCDIF_CTRL);
    } else if (recvCh == '1') {
        /*RGB565(16bit) in dotclk mode transfer */
        writel(0x000B0021, HW_LCDIF_CTRL);
    } else {
        printf("Wrong panel type!\n");
    }
}

void image_center_copy(void)
{
    int width = 313, height = 117;
    int left_offset = (FRAME_WIDTH - width) / 2;
    int top_offset = (FRAME_HEIGHT - height) / 2;
    int i = 0;

    memset((void *)DDR_LCD_BASE1, 0xFF, FRAME_WIDTH * FRAME_HEIGHT * 2);

    for (i = 0; i < height; i++) {
        memcpy((void *)(DDR_LCD_BASE1 + FRAME_WIDTH * (top_offset + i) * 2 + left_offset * 2),
               &gImage_fsl[width * i * 2], width * 2);
    }
}

int lcd_test_enable;
int lcd_display_test(void)
{
    int ret = 0;
    char recvCh = NONE_CHAR;

    if (!lcd_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("LCD WVGA Display test", NULL);

    lcdif_display_setup();

    image_center_copy();

    hal_delay_us(10000000);

    memset((void *)DDR_LCD_BASE1, 0xFF, FRAME_WIDTH * FRAME_HEIGHT * 2);

    hal_delay_us(10000000);

    image_center_copy();

    printf("Do you see Freescale logo displayed on the WVGA panel?(Y/y for yes, other for no)\n");

    do {
        recvCh = getchar();
    }
    while (recvCh == NONE_CHAR);

    printf("%c\n", recvCh);

    if (recvCh == 'Y' || recvCh == 'y') {
        ret = 0;
    } else {
        ret = -1;
    }

    return ret;
}

//RUN_TEST_INTERACTIVE("LCDC Display Test", lcd_display_test)
