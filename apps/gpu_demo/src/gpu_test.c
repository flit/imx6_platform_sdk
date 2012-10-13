/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "mmu.h"
#include "version.h"
#include "hardware.h"
#include "cortex_a9.h"
#include "iomux_config.h"
#include "platform_init.h"

#include "texture.h"
#include "gpu_test_common.h"
#include "sdk_gpu_utilities.h"
#include "ipu/ipu_common.h"

#include "registers/regsipu.h"
#include "registers/regscsu.h"
#include "registers/regsiomuxc.h"
#include "registers/regsgpu3d.h"

#define GPU_DEMO_WIDTH  	1024
#define GPU_DEMO_HEIGHT 	768
#define BG_BUFFER_ADDR      0x24000000
#define FG_BUFFER_ADDR0     0x18000000
#define FG_BUFFER_ADDR1     0x18800000

int gpu_test(void);

int width = GPU_DEMO_WIDTH;
int height = GPU_DEMO_HEIGHT;
int pixel_format = 4;           //2 - 16 bit; 4 - 32 bit
int depth_format = 4;           //2 - 16 bit; 4 - 32 bit 2 not work now 4 is fixed
int lcd_pixel_format = 4;       //2 - 16 bit; 4 - 32 bit

floatint new_width;
floatint new_height;
floatint new_half_width;
floatint new_half_height;
floatint neg_new_half_height;

int SAVE_BMP, ENABLEZC = 1, HZ;
int USE_FAST_CLEAR = 1;

volatile int gpu_new_frame;
static int panel_init = 0;

int main(void)
{
    enable_neon_fpu();

#if defined(BOARD_EVB)||defined(BOARD_SMART_DEVICE)
    system_memory_arrange();
    disable_strict_align_check();
#endif

    platform_init();

    print_version();

    gpu_test();

    _sys_exit(0);

    return 0;
}

int gpu_test(void)
{
    printf("\nRunning GPU test, please connect the Hannstar LVDS panel to the LVDS0\n");

    new_width.f = (float)width;
    new_height.f = (float)height;
    new_half_width.f = ((float)width) / 2.0f;
    new_half_height.f = ((float)height) / 2.0f;
    neg_new_half_height.f = -new_half_height.f;

    // enable GPU to access MMDC
    HW_CSU_CSLn_SET(25, 0xFF);

    //IPU2 QoS
    HW_IOMUXC_GPR7_SET(0xFFFFFFFF);

    //Lower GPU frequency
    BW_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(1);
    BW_GPU3D_AQH_CLK_CTRL_FSCALE_VAL(0x60);
    BW_GPU3D_AQH_CLK_CTRL_FSCALE_CMD_LOAD(0);

    /*initialize the display device */
    if (panel_init == 0) {
        int32_t ipu_index = 2;
        ipu_sw_reset(ipu_index, 1000000);
        ips_dev_panel_t *panel = search_panel("HannStar XGA LVDS");
        panel->panel_init(&ipu_index);
        ipu_dual_display_setup(ipu_index, panel, INTERLEAVED_ARGB8888, width, height, 0, 0, 0x0);
        ipu_dma_update_buffer(ipu_index, 23, 0, BG_BUFFER_ADDR);
		memset((void *)BG_BUFFER_ADDR, 0x00, width * height * pixel_format);
		ipu_dma_update_buffer(ipu_index, 27, 0, FG_BUFFER_ADDR0);
		memset((void *)FG_BUFFER_ADDR0, 0x00, width * height * pixel_format);
        ipu_dma_update_buffer(ipu_index, 27, 1, FG_BUFFER_ADDR1);
		memset((void *)FG_BUFFER_ADDR1, 0x00, width * height * pixel_format);
        ipu_enable_display(ipu_index);
        panel_init = 1;
    }

    runTexture(CMD_BUFFER_ADDR, 0);

    printf("GPU test running, press any key to exit.\n");
    while (1) {
        if (getchar() != (uint8_t) 0xFF) {
            printf("GPU test exits.\n");
            break;
        }
        rotateTexture(CMD_BUFFER_ADDR);
    }

    return 0;
}
