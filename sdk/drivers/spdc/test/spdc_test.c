/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "spdc/spdc_regs.h"
#include "spdc/spdc.h"

#define	WORKMODE	M0
extern void sipix_epd_clock_setting(int freq);

static int spdc_initialized = 0;
int spdc_test_enable = 1;
extern unsigned int fsl_gray_600x230[];

void image_convert_8bpp_to_4bpp(int width, int height, uint8_t * in, uint8_t * out)
{
    uint8_t pixel_y8[4];
    int i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i < (width / 4); i++) {
            pixel_y8[0] = *(in + j * width + i * 4);
            pixel_y8[1] = *(in + j * width + i * 4 + 1);
            pixel_y8[2] = *(in + j * width + i * 4 + 2);
            pixel_y8[3] = *(in + j * width + i * 4 + 3);

            *(out + j * SPDC_HSIZE / 2 + i * 2) = ((pixel_y8[3] >> 4) & 0xF) | (pixel_y8[2] & 0xF0);
            *(out + j * SPDC_HSIZE / 2 + i * 2 + 1) =
                ((pixel_y8[1] >> 4) & 0xF) | (pixel_y8[0] & 0xF0);
        }
}

void spdc_update_image(int pos_x, int pos_y, int width, int height)
{
    uint8_t *img = (uint8_t *) EPD_NEXT_BUF_ADDR + pos_y * SPDC_HSIZE / 2 + pos_x / 2;

    reg32_write(SPDC_EPD_UPDATE_X_Y, (((pos_x & (~0x3)) + 1) << 16) | ((pos_y & (~0x3)) + 1));
    reg32_write(SPDC_EPD_UPDATE_W_H, (width << 16) | height);

    image_convert_8bpp_to_4bpp(width, height, (uint8_t *) fsl_gray_600x230, img);
}

void epd_set_buffers(void)
{
    reg32_write(SPDC_EPD_NEXT_BUF, EPD_NEXT_BUF_ADDR);
    reg32_write(SPDC_EPD_CURRENT_BUF, EPD_CUR_BUF_ADDR);
    reg32_write(SPDC_EPD_PREVIOUS_BUF, EPD_PREV_BUF_ADDR);
    reg32_write(SPDC_EPD_FRM_CNT_BUF, EPD_FRM_CNT_BUF_ADDR);
}

extern unsigned int auo_lut[];
extern int auo_lut_size;
void epd_load_wv_lut(unsigned int lut[], unsigned int load_addr)
{
    memcpy((void *)load_addr, lut, auo_lut_size);
    /*the LUT download will start automatically once the register is configured */
    reg32_write(SPDC_EPD_LUT_BUF, load_addr);
}

void epd_power_up(void)
{
    int i = 0;

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_D10, 0x5);
    gpio_set_direction(GPIO_PORT1, 17, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 17, GPIO_LOW_LEVEL);

    /* Using the MAX17135 as the power supplier 
     * Panel connector are using the AXT334124
     *
     * Power Sequence:
     * VDD_Panel -> VEE -> VGG -> VDNS -> VDPS -> Vcom
     * 
     * Pin Connections:
     * Name         Pin# of MAX17135        Pin# of AXT334124   Comment
     * VDD_Panel:   3V15(from mainboard)    5,7                 default enabled, comming from DCDC3V15
     * VEE          6(DGVEE)                27,29
     * VGG          4(DGVDD)                23,25
     * VDNS         23(POS)                 1,3
     * VDPS         24(NEG)                 2,4
     * Vcom:        22(VCOM)                22,24
     */
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EPDC_PWRCTRL0, 0x5);
    gpio_set_direction(GPIO_PORT2, 7, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 7, GPIO_HIGH_LEVEL);

    //EN : pmic_wakeup gpio2.14
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRWAKEUP, 0x05);    //  gpio2.GPIO[31]
    gpio_set_direction(GPIO_PORT2, 14, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 14, GPIO_HIGH_LEVEL);

    //CEN : pmic_vcom gpio2.3 
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_VCOM0, 0x05);    //  gpio3.GPIO[17]
    gpio_set_direction(GPIO_PORT2, 3, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 3, GPIO_HIGH_LEVEL);

    while (i++ < 10000)
        __asm("nop");

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_D10, 0x5);
    gpio_set_direction(GPIO_PORT1, 17, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 17, GPIO_HIGH_LEVEL);
}

void epd_clock_gate(int on)
{
    if (on) {
        reg32_write(SPDC_EPD_SW_GATE_CLK, 1);   //close all the clock
    } else {
        reg32_write(SPDC_EPD_SW_GATE_CLK, 0);   //turn on all the clock
    }
}

void epd_panel_init_set(int resolution, int hburst_len_en, int rgbw_mode_en, int pwr_ready,
                        int data_filt_en, int rl, int ud, int dual_gate, int yoe_pol)
{
    unsigned int val =
        (hburst_len_en << 13) | (rgbw_mode_en << 11) | (pwr_ready << 10) | (data_filt_en << 9)
        | (rl << 8) | (ud << 7) | (resolution << 2) | (dual_gate << 1) | yoe_pol;
    reg32_write(SPDC_EPD_PANEL_INIT_SET, val);
}

void epd_temperature_set(float degrade)
{
    int tmp = (int)(degrade * 2);
    if (tmp < 0) {
        tmp = (1 << 8) | (((~tmp) + 1) & 0xFF);
    } else {
        tmp = tmp & 0xFF;
    }
    reg32_write(SPDC_EPD_TEMPER_SETTING, tmp);
}

void epd_operation_start(int opt)
{
    switch (opt) {
    case SW_TCON_RESET:
        reg32_write(SPDC_EPD_OPERATE, 1 << 31);
        break;
    case DISP_RESET:
        reg32_write(SPDC_EPD_OPERATE, 1 << 2);
        break;
    case DEEP_REFRESH:
        reg32_write(SPDC_EPD_OPERATE, 1 << 1);
        break;
    case DISP_REFRESH:
        reg32_write(SPDC_EPD_OPERATE, 1 << 0);
        break;
    default:
        printf("Error:  unkown operation !!\n");
    }
}

int spdc_display_test(void)
{
    int ret = 0;

    char recvCh = NONE_CHAR;
    if (!spdc_test_enable) {
        return TEST_NOT_PRESENT;
    }
    PROMPT_RUN_TEST("Sipix EINK display test", NULL);

    spdc_iomux_config();

    /*turn on the SPDC clock */
    epd_clock_gate(0);

    /*confgure the spdc system clock, 40MHz for 800*600@50Hz refresh rate */
    sipix_epd_clock_setting(40);

    reg32_write(SPDC_EPD_INT_EN, 0xF);  //enable all interrupts

    epd_temperature_set(25);

    if (spdc_initialized == 0) {
        /*step1: cofnigure the wroking memory */
        epd_set_buffers();

        /*step2: configure the waveform LUT */
        epd_load_wv_lut(auo_lut, EPD_LUT_BUF_ADDR);
        while ((reg32_read(SPDC_EPD_INT_ST_CLR) & 0x4) != 0x4) ;    //wait for LUT download finished
        reg32_write(SPDC_EPD_INT_ST_CLR, 0x4);

        /*step3: configure the power sequence
         * SHD_N -> PWR0 -> PWR1 -> PWR2 ->PWR3*/
        epd_power_up();

        /*step4: send the basic initial setting to SPDC */
        epd_panel_init_set(0,   //resolution is 800*600 landscape
                           1,   //disable HBURST
                           0,   //gray mode
                           1,   //set power ready and trigger display
                           0,   //enable auto data filter
                           0,   //RL
                           0,   //UD
                           0,   //single gate
                           0    //low enable
            );
        while ((reg32_read(SPDC_EPD_INT_ST_CLR) & 0x02) != 0x2) ;   //wait for tcon init finished
        reg32_write(SPDC_EPD_INT_ST_CLR, 0x2);

        spdc_initialized = 1;
    }
#if 1
    epd_operation_start(DISP_RESET);
    while ((reg32_read(SPDC_EPD_INT_ST_CLR) & 0x1) != 0x1) ;
    reg32_write(SPDC_EPD_INT_ST_CLR, 0x1);
#endif

    spdc_update_image((SPDC_HSIZE - 600) / 2, (SPDC_VSIZE - 240) / 2, 600, 240);
#if defined(MODE0)
    reg32_write(SPDC_EPD_DISP_TRIGGER, 0x00000001); // mode0 + trig 
#elif defined(MODE1)
    reg32_write(SPDC_EPD_DISP_TRIGGER, 0x00000003); // mode1 + trig
#elif defined(MODE2)
    reg32_write(SPDC_EPD_DISP_TRIGGER, 0x00000005); // mode2 + trig
#elif defined(MODE3)
    reg32_write(SPDC_EPD_DISP_TRIGGER, 0x00000009); // mode4 + trig
#endif
    while ((reg32_read(SPDC_EPD_INT_ST_CLR) & 0x1) != 0x1) ;
    reg32_write(SPDC_EPD_INT_ST_CLR, 0x1);

    printf
        ("Do you see Freescale logo displayed on the sipix e-ink panel?(Y/y for yes, other for no)\n");

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

//RUN_TEST_INTERACTIVE("Sipix EINK Display Test", spdc_display_test)
