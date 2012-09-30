/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "epdc/epdc_regs.h"
#include "epdc/epdc.h"

void epdc_pvi_svga_sdr_init(void);
void epdc_pvi_svga_sdr_test(void);
void epdc_send_mode0_to_black_update(void);
void epdc_update_image(int width, int height, unsigned int img_base);
void epdc_send_image_update(unsigned int lut, epdc_upd_area_t upzone, unsigned int image_addr);
void epdc_send_erase_to_color(unsigned int lut, unsigned int mode,
                              epdc_upd_area_t upzone, int color);

extern void epdc_dump_registers(void);
extern void mxc_epdc_iomux_config(void);
extern void epdc_clock_setting(int freq_mhz);
extern void epdc_load_image(void);
extern void epdc_power_supply(void);
extern void epdc_reset(void);
extern void epdc_buffer_init(void);
extern void epdc_init_settings(void);
extern bool epdc_is_working_buffer_busy(void);

extern void epdc_set_update_addr(unsigned int addr);
extern void epdc_set_update_coord(unsigned int x, unsigned int y);
extern void epdc_set_update_dimensions(unsigned int width, unsigned int height);
extern void epdc_submit_update(unsigned int lut_num, unsigned int waveform_mode,
                               unsigned int update_mode, bool use_test_mode, unsigned int np_val);
extern int epdc_get_next_lut(void);
extern bool epdc_is_lut_active(unsigned int lut_num);
static int epdc_initialized = 0;

int epd_test_enable;
int epd_display_test(void)
{
    int ret = 0;

    char recvCh = NONE_CHAR;
    if (!epd_test_enable) {
        return TEST_NOT_PRESENT;
    }
    PROMPT_RUN_TEST("EINK display test", NULL);

    if (epdc_initialized == 0) {
        mxc_epdc_iomux_config();

        epdc_clock_setting(27);

        epdc_power_supply();    // max17135 setting

        epdc_reset();

        epdc_pvi_svga_sdr_init();

        epdc_initialized = 1;
    }

    epdc_update_image(600, 230, IMAGE_STORE_0_ADDR);

    printf("Do you see Freescale logo displayed on the e-ink panel?(Y/y for yes, other for no)\n");

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

void epdc_pvi_svga_sdr_init(void)
{
    epdc_buffer_init();

    epdc_init_settings();

    epdc_load_image();

    //epdc_dump_registers();
    
	/* Start commands */
    epdc_send_mode0_to_black_update();
}

void epdc_update_image(int width, int height, unsigned int img_base)
{
    // Send FSL across the screen
    int lut = 15;
    epdc_upd_area_t upz;

    if (width > EPDC_HSIZE || height > EPDC_VSIZE) {
        width = EPDC_HSIZE;
        height = EPDC_VSIZE;
    }

    upz.coordinate.x = (EPDC_HSIZE - width) / 2;
    upz.coordinate.y = (EPDC_VSIZE - height) / 2;
    upz.size.width = width;
    upz.size.height = height;

    lut = epdc_get_next_lut();
    epdc_send_erase_to_color(lut, EPDC_WV_MODE__GC16, upz, 0xF);

    while (epdc_is_lut_active(lut)) ;

    lut = epdc_get_next_lut();
    epdc_send_image_update(lut, upz, img_base);

    while (epdc_is_lut_active(lut)) ;
}

void epdc_send_mode0_to_black_update(void)
{
    int lut = 15;

    /* wait for working buffer to be idle */
    while (epdc_is_working_buffer_busy()) ;

    lut = epdc_get_next_lut();
    /* UPD update */
    epdc_set_update_addr(UPD_BUFFER_MODE_0_ADDR);
    epdc_set_update_coord(0, 0);
    epdc_set_update_dimensions(EPDC_HSIZE, EPDC_VSIZE);
    epdc_submit_update(lut, EPDC_WV_MODE__INIT, EPDC_UPD_UPDATE_MODE__FULL, 0x0, 0x0);

    /* Wait for LUT to finish */
    while (epdc_is_lut_active(lut)) ;
}

void epdc_send_image_update(unsigned int lut, epdc_upd_area_t upzone, unsigned int image_addr)
{
    while (epdc_is_working_buffer_busy()) ;

    /* UPD update */
    epdc_set_update_addr(image_addr);
    epdc_set_update_coord(upzone.coordinate.x, upzone.coordinate.y);
    epdc_set_update_dimensions(upzone.size.width, upzone.size.height);  // 600x230
    epdc_submit_update(lut, EPDC_WV_MODE__GC16, EPDC_UPD_UPDATE_MODE__PARTIAL, 0x0, 0x0);
}

void epdc_send_erase_to_color(unsigned int lut, unsigned int mode,
                              epdc_upd_area_t upzone, int color)
{
    while (epdc_is_working_buffer_busy()) ;

    /* UPD update */
    epdc_set_update_addr(UPD_BUFFER_MODE_0_ADDR);
    epdc_set_update_coord(upzone.coordinate.x, upzone.coordinate.y);
    epdc_set_update_dimensions(upzone.size.width, upzone.size.height);  // 600x230
    epdc_submit_update(lut, mode, EPDC_UPD_UPDATE_MODE__PARTIAL, 0x1, color);   //0xf0
}

//RUN_TEST_INTERACTIVE("EINK Display Test", epd_display_test)
