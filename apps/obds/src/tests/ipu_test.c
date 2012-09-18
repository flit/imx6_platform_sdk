/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_ipu IPU Test
 */

/*!
 * @file ipu_test.c
 * @brief ipu test case on different display devices, including TFTLCD, HDMI, LVDS and VGA panels.
 * @ingroup diag_ipu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obds.h"
#include "hardware.h"
#include "gpio_define.h"
#include "logo.h"

#define WVGA_FW      800
#define WVGA_FH      480
#define XGA_FW       1024
#define XGA_FH       768
#define DUALVGA_FW   1280
#define DUALVGA_FH   480
#define SXGA_FW      1280
#define SXGA_FH      1024
#define VGA_FW       640
#define VGA_FH       480
#define HD1080_FW    1920
#define HD1080_FH    1080
#define HD720_FW     1280
#define HD720_FH     720

typedef struct display_device {
    unsigned int type;
    char panel_name[32];
    int width;
    int height;
    int init_status;
} display_device_t;

display_device_t dispDev = { 0 };

int single_image_disp(void);
void ipu_panel_enable(int panel_type_sel, int bit_mode, char *panel_name);
void ldb_config_ipu(int);

//extern void ipu_display_setup(uint32_t ipu_index, uint32_t, uint32_t, uint32_t, ips_dev_panel_t *panel);
extern void ipu_iomux_config(void);
extern void ldb_clock_config(int freq, int ipu_index);
extern void disable_para_panel(void);
extern int ipu_sw_reset(int32_t ipu_index, int32_t timeout);
extern void tftlcd_backlight_en(char *panel_name);
extern void tftlcd_reset(char *panel_name);
extern void lvds_power_on(void);
extern void hdmi_pgm_iomux(void);
extern void hdmi_test(void);
extern void hdmi_clock_set(int ipu_index, uint32_t pclk);
extern void mipi_backlight_en(void);
extern void mipi_display_reset(void);
extern void mipi_clock_set(void);
extern void mipi_csi2_config(void);
extern void mipi_dsi_init(void);
extern void ipu_enable_display(int32_t ipu_index);
/*
#if defined(MX53_EVK)||defined(MX53_SMD)||defined(MX53_LCB)
extern void vga_tve_clk_setting(void);
extern void vga_tve_config(void);
extern void vga_tve_iomux_config(void);
extern void vga_tve_power_setting(void);
// dummy functions added to build i.MX53 OBDS, could we do it differently?

#endif
*/
void ldb_config_ipu(int bit_mode)
{
    char recvCh = NONE_CHAR;

    /*LVDS panel test */
    printf("Please select LVDS port to use:\n");
    printf("\t0 - LVDS port 0\n");
    printf("\t1 - LVDS port 1\n");
    printf("\t2 - LVDS port 0 and port 1\n");
    printf("\t3 - LVDS port 0 and port 1 in split mode\n");

    do {
        recvCh = getchar();

        if (recvCh == '0') {
            /* enable DI0 on LVDS port 0 */
            writel(0x0001 | (bit_mode << 5), IOMUXC_GPR2);
            break;

        } else if (recvCh == '1') {
            /* enable DI0 on LVDS port 1 */
            writel(0x0004 | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '2') {
            /* enable DI0 on both LVDS ports */
            writel(0x0005 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        } else if (recvCh == '3') {
            /* enable DI0 on LVDS port 0 and 1 in split mode */
            writel(0x0015 | (bit_mode << 5) | (bit_mode << 7), IOMUXC_GPR2);
            break;
        }
    }
    while (1);

}

/*!
 * Enable the display panel, basicly reset and provide the backlight
 *
 * @param  	panel_type_sel: choose the display panel type. eg. TFTLCD/HDMI/LVDS/VGA MONITOR
 * @param	bit_mode:		bit per pixel mode for the panel.
 * @param	panel_name:		panel name listed below
 */
void ipu_panel_enable(int panel_type_sel, int bit_mode, char *panel_name)
{
    if (dispDev.init_status & (1 << panel_type_sel)) {
        printf("the panel has been initialized!!\n");
        return;
    } else {
        dispDev.init_status |= (1 << panel_type_sel);
    }

    if (panel_type_sel == DISP_DEV_TFTLCD) {
        tftlcd_reset(panel_name);
        tftlcd_backlight_en(panel_name);
    } else if (panel_type_sel == DISP_DEV_LVDS) {
/*        ldb_iomux_config();
this is not defined for MX6SL and it is an empty function for the other MX6 processors as far as I can tell.
*/
        if (!strcmp(panel_name, "HannStar HSD100PXN1 XGA")) {
            ldb_clock_config(65000000, 0);
            ldb_clock_config(65000000, 1);
        } else {
            printf("unknown panel type!\n");
        }
        lvds_power_on();
        ldb_config_ipu(bit_mode);
    }
#if defined(BOARD_SABRE_AI) || defined(BOARD_SABRE_LITE) || defined(BOARD_SMART_DEVICE) || (!defined(CHIP_MX6SL) && defined(BOARD_EVB))
    else if (panel_type_sel == DISP_DEV_HDMI) {
        hdmi_pgm_iomux();
        hdmi_clock_set(1, 74250000);
        hdmi_test();
    } else if (panel_type_sel == DISP_DEV_MIPI) {
        mipi_backlight_en();
        mipi_display_reset();
        mipi_clock_set();
        mipi_dsi_init();
        hal_delay_us(5000);
    }
#endif
}

/*!
 * Copy the image to center of the panel
 */
void image_center_copy(void)
{
    /*the image is a 313*117 freescale logo */
    int width = 313, height = 117;
    int left_offset = (dispDev.width - width) / 2;
    int top_offset = (dispDev.height - height) / 2;
    int i = 0;

    for (i = 0; i < height; i++) {
        memcpy((void *)(CH23_EBA0 + dispDev.width * (top_offset + i) * 2 + left_offset * 2),
               &gImage_fsl[width * i * 2], width * 2);
    }
}

/*!
 * Display the image and promt to check if it works
 */
int single_image_disp(void)
{
    int ret = TEST_FAILED;

    memset((void *)CH23_EBA0, 0xFF, dispDev.width * dispDev.height * 2);
    image_center_copy();
    printf("Do you see the image displayed on the %s panel?(Y/y for yes, other for no)\n",
           dispDev.panel_name);
    if (is_input_char('y')) {
        ret = TEST_PASSED;
    }
    return ret;
}

/*!
 * IPU display test case
 *
 *@param  disp_dev_type  display panel type
 *
 */
static int ipu_display_test(int disp_dev_type)
{
    char recvCh = NONE_CHAR;
//    uint32_t disp_mem;
//    ips_dev_panel_t *panel = NULL;
    unsigned int bit_mode = LVDS_PANEL_18BITS_MODE;
    ipu_iomux_config();
    ipu_sw_reset(1, 1000);

    dispDev.type = disp_dev_type;
    switch (disp_dev_type) {
    case DISP_DEV_TFTLCD:
        /*TFT LCD test */
        printf("please select tft lcd type:\n");
        printf("\t0 - SEIKO 70WVW1TZ3 WVGA Panel\n");
        printf("\t1 - CHUNHWA CLAA 070VC01 WVGA Panel\n");
        printf("\t2 - BoundaryDev WVGA Panel\n");
        printf("\t3 - SEIKO 43WVF1G WVGA Panel\n");

        recvCh = NONE_CHAR;
        do {
            recvCh = getchar();

            if (recvCh == '0') {
                strcpy(dispDev.panel_name, "SEIKO 70WVW1TZ3");
                dispDev.width = WVGA_FW;
                dispDev.height = WVGA_FH;
                break;
            } else if (recvCh == '1') {
                strcpy(dispDev.panel_name, "CLAA 070VC01");
                dispDev.width = WVGA_FW;
                dispDev.height = WVGA_FH;
                break;
            } else if (recvCh == '2') {
                strcpy(dispDev.panel_name, "BoundaryDev WVGA");
                dispDev.width = WVGA_FW;
                dispDev.height = WVGA_FH;
                break;
            } else if (recvCh == '3') {
                strcpy(dispDev.panel_name, "SEIKO 43WVF1G");
                dispDev.width = WVGA_FW;
                dispDev.height = WVGA_FH;
                break;
            }
        }
        while (1);
        break;
    case DISP_DEV_HDMI:
        strcpy(dispDev.panel_name, "HDMI 720P60");
        dispDev.width = HD720_FW;
        dispDev.height = HD720_FH;
        break;
    case DISP_DEV_LVDS:
        /*LVDS panel test */
        printf("please select lvds panel type:\n");
        printf("\t0 - AUO T150XG01V02 15 Inch XGA Panel\n");
        printf("\t1 - CHIMEI M216H1-L01 21 Inch HD1080 Panel\n");
        printf("\t2 - SHARP 1280x480 Panel\n");
        printf("\t3 - TOSHIBA LT084AC37100 XGA Panel\n");
        printf("\t4 - MITSUBISHI AA084XA03 XGA Panel\n");
        printf("\t5 - HannStar HSD100PXN1 XGA Panel\n");

        recvCh = NONE_CHAR;
        do {
            recvCh = getchar();

            if (recvCh == '0') {
                strcpy(dispDev.panel_name, "AUO T150XG01V02");
                dispDev.width = XGA_FW;
                dispDev.height = XGA_FH;
                bit_mode = LVDS_PANEL_24BITS_MODE;
                break;
            } else if (recvCh == '1') {
                strcpy(dispDev.panel_name, "CHIMEI M216H1-L01");
                dispDev.width = HD1080_FW;
                dispDev.height = HD1080_FH;
                bit_mode = LVDS_PANEL_24BITS_MODE;
                break;
            } else if (recvCh == '2') {
                strcpy(dispDev.panel_name, "SHARP DUAL VGA");
                dispDev.width = DUALVGA_FW;
                dispDev.height = DUALVGA_FH;
                bit_mode = LVDS_PANEL_24BITS_MODE;
                break;
            } else if (recvCh == '3') {
                strcpy(dispDev.panel_name, "TOSHOBA LT084AC37100");
                dispDev.width = XGA_FW;
                dispDev.height = XGA_FH;
                bit_mode = LVDS_PANEL_18BITS_MODE;
                break;
            } else if (recvCh == '4') {
                strcpy(dispDev.panel_name, "MITSUBISHI AA084XA03");
                dispDev.width = XGA_FW;
                dispDev.height = XGA_FH;
                bit_mode = LVDS_PANEL_18BITS_MODE;
                break;
            } else if (recvCh == '5') {
                strcpy(dispDev.panel_name, "HannStar HSD100PXN1 XGA");
                dispDev.width = XGA_FW;
                dispDev.height = XGA_FH;
                bit_mode = LVDS_PANEL_18BITS_MODE;
                break;
            }
        }
        while (1);

        disable_para_panel();
        break;
    case DISP_DEV_VGA:
        strcpy(dispDev.panel_name, "VGA DISPLAY");
        dispDev.width = XGA_FW;
        dispDev.height = XGA_FH;
        break;
    case DISP_DEV_MIPI:
        strcpy(dispDev.panel_name, "MIPI panel");
        dispDev.width = WVGA_FH;
        dispDev.height = WVGA_FW;

        printf("\t run mipi camera first?\n");

        recvCh = NONE_CHAR;
        do {
            recvCh = getchar();
            if (recvCh != NONE_CHAR) {
                if (recvCh == 'y' || recvCh == 'Y') {
                    mipi_csi2_config();

                    break;
                } else
                    break;
            }
        } while (1);
        break;
    default:
        printf("Such kind of display device can not be supportted yet.\n");
        return -1;
    }

    printf("****** testing display %s ******\n", dispDev.panel_name);
//    ipu_setup(1, RGB565, CSC_DISABLE);
//    ipu_display_setup(1, disp_mem, (uint32_t) NULL, INTERLEAVED_RGB, panel);
    ipu_enable_display(1);

    ipu_panel_enable(dispDev.type, bit_mode, dispDev.panel_name);

    return single_image_disp();
}

static const char *display_type_name[] = {
    "NULL",
    "TFTLCD",
    "LVDS",
    "VGA",
    "HDMI",
    "TV",
    "MIPI"
};

int ipu_display_test_enable;
int32_t ipu_display_panel[20];

/*!
 * IPU display test main entry
 *
 * @return  TEST_NOTPRESENT if no IPU tests are enabled for the platform;
 *          TEST_BYPASSED if no IPU test enabled on the platform is chosen to run,
 *                        or no display at all on that platform;
 *          TEST_FAILED if any of the chosen tests fail;
 *          TEST_PASSED if all the chosen tests pass.
 */
int ipu_display_test_main(void)
{
    int i, fail = 0, pass = 0, panel_index;

    if (!ipu_display_test_enable) {
        return TEST_NOTPRESENT;
    }
    for (i = 0;; i++) {
        panel_index = ipu_display_panel[i];
        if (panel_index == DISP_DEV_NULL) {
            break;
        }
        printf("\n---- Running < %s > test\n", display_type_name[panel_index]);
        if (is_input_char('y')) {
            if (ipu_display_test(panel_index) != TEST_PASSED) {
                fail++;
                printf("\t %s test FAILED\n", display_type_name[panel_index]);
            } else {
                pass++;
                printf("\t %s test PASSED\n", display_type_name[panel_index]);
            }
        }
    }
    if (i == 0)
        return TEST_NOTPRESENT;

    if (fail == 0 && pass == 0) {
        printf("WARNING: No display type selected\n");
        return TEST_BYPASSED;
    }

    if (fail != 0) {
        printf("\nFAILED: IPU display %d out of total %d selected tests\n", fail, fail + pass);
        return TEST_FAILED;
    }

    printf("\nPASSED: IPU display %d out of total %d selected tests\n", pass, fail + pass);
    return TEST_PASSED;
}

//RUN_TEST_INTERACTIVE("DISPLAY", ipu_display_test_main)
