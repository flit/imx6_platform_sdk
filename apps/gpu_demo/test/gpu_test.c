/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdk.h"
#include "soc_memory_map.h"
#include "hardware.h"
#include "gpu_test_common.h"
#include "sdk_gpu_utilities.h"
#include "texture.h"
#include "iomux_config.h"
#include "registers/regsipu.h"
#include "ipu/ipu_common.h"
#include "cortex_a9.h"
#include "mmu.h"
#include "version.h"
#include "hardware.h"

#define GPU_DEMO_WIDTH  	1024
#define GPU_DEMO_HEIGHT 	768

extern hw_module_t g_debug_uart;
extern uint8_t uart_getchar(struct hw_module *port);
extern void ipu_dma_update_buffer(uint32_t ipu_index, uint32_t channel, uint32_t buffer_index,
       uint32_t buffer_addr);
extern void enable_L1_cache(void);
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
    volatile uint8_t ch;
    uint32_t val;

    printf
        ("\nRunning GPU test, please connect the panel to the LVDS0, type 'y' or 'Y' to comfirm.\n");
    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);

    if (('Y' != ch) && ('y' != ch)) {
        return -1;
    }

    printf("GPU test running, press any key to exit.\n");

    new_width.f = (float)width;
    new_height.f = (float)height;
    new_half_width.f = ((float)width) / 2.0f;
    new_half_height.f = ((float)height) / 2.0f;
    neg_new_half_height.f = -new_half_height.f;

    // enable GPU to access MMDC
    val = reg32_read(CSU_BASE_ADDR + 0x64);
    val |= 0xff;
    reg32_write(CSU_BASE_ADDR + 0x64, val);

    //IPU2 QoS
    reg32_write(IOMUXC_GPR7, 0xffffffff);

    //Lower GPU frequency
    val = reg32_read(GPU_3D_BASE_ADDR + 0x0);
    val &= 0xfffffc03;
    val |= 0x280;
    reg32_write(GPU_3D_BASE_ADDR + 0x0, val);
    val &= 0xfffffdff;
    reg32_write(GPU_3D_BASE_ADDR + 0x0, val);
	
	/*initialize the display device*/
	if(panel_init == 0) {
		int32_t ipu_index = 2;
		ipu_sw_reset(ipu_index, 1000000);
		ips_dev_panel_t *panel = search_panel("HannStar XGA LVDS");
		panel->panel_init(&ipu_index);
		ipu_dual_display_setup(ipu_index, panel, INTERLEAVED_ARGB8888, width, height, 0, 0, 0x0);
		ipu_dma_update_buffer(ipu_index, 23, 0, 0x24000000);
		ipu_dma_update_buffer(ipu_index, 27, 0, 0x18000000);
		ipu_dma_update_buffer(ipu_index, 27, 1, 0x18800000);
		ipu_enable_display(ipu_index);
		panel_init = 1;
	}
   
    runTexture(CMD_BUFFER_ADDR, 0);
    while (1) {
        ch = uart_getchar(&g_debug_uart);
        if (ch != (uint8_t) 0xFF) {
            printf("GPU test exits.\n");
            break;
        }
        rotateTexture(CMD_BUFFER_ADDR);
    }

    return 0;
}
