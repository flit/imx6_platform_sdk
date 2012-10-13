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
#if !defined(CHIP_MX6SL)
#include "hdmi_regs.h"
#endif
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


extern hw_module_t g_debug_uart;
extern hw_module_t g_system_timer;



void freq_populate(void);
uint32_t get_freq(uint32_t module_base);




#endif /* __HARDWARE_H__ */
