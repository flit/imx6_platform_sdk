/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file hardware.h
 * @brief header file with chip defines to be included by all the tests/utils
 *
 * @ingroup diag_init
 */

#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include "sdk_types.h"
#include "soc_memory_map.h"
#include "irq_numbers.h"
#include "registers.h"
#include "sdk.h"
#include "utility/system_util.h"
#include "iomux_config.h"
#include "iomux_define.h"
#include "iomux_register.h"
#include "gpio/gpio.h"
#include "core/interrupt.h"
#include "gic/gic.h"
#include "ccm_pll.h"
#include "i2c/imx_i2c.h"
#include "uart/imx_uart.h"
#if defined(CHIP_MX6DQ)
#include "sata/imx_sata.h"
#endif
#include "timer/timer.h"
#include "hdmi_regs.h"
#include "buffers.h"
#include "usb/usb.h"
#include "keypad/keypad_port.h"
#include "ioexpander/max7310.h"
#include "board_io_expanders.h"
#include "board_i2c.h"

//Add for obds tests
#include "spi/ecspi_ifc.h"
#include "enet/enet.h"
#include "board_id/board_id.h"



// Android_Buttons test defines
#define HOME_BUTTON_GPIO_INST     GPIO_PORT1
#define HOME_BUTTON_GPIO_NUM      11
#define BACK_BUTTON_GPIO_INST     GPIO_PORT1
#define BACK_BUTTON_GPIO_NUM      12
#define PROG_BUTTON_GPIO_INST     GPIO_PORT2
#define PROG_BUTTON_GPIO_NUM      12
#define VOLPLUS_BUTTON_GPIO_INST  GPIO_PORT2
#define VOLPLUS_BUTTON_GPIO_NUM   15
#define VOLMINUS_BUTTON_GPIO_INST GPIO_PORT7
#define VOLMINUS_BUTTON_GPIO_NUM  8




// input clocks
#define CKIL        32768
#define FREQ_24MHZ  24000000
#define CKIH        22579200


extern hw_module_t g_debug_uart;
extern hw_module_t g_system_timer;



void freq_populate(void);
uint32_t get_freq(uint32_t module_base);

void reset_usb_hub(void);
void usb_clock_enable(void);

void imx_enet_setup(void);

void gpmi_nand_clk_setup(void);

void hw_can_iomux_config(uint32_t module_instance);

//OBDS-SDK Merge, add according to hardware.c
void deserializer_io_config(void);
void mlb_io_config(void);
void weim_nor_flash_cs_setup(void);
void audio_codec_power_on(void);
void audio_clock_config(void);

void gpio_backlight_lvds_en(void);

void camera_power_on(void);
void csi_port0_iomux_config(void);




#endif /* __HARDWARE_H__ */
