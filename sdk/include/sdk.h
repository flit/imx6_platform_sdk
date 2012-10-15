/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sdk.h
 * @brief       Basic defines
 *
 * @ingroup diag_init
 */
#ifndef __SDK_H__
#define __SDK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sdk_types.h"
#include "io.h"

#include "soc_memory_map.h"
#include "registers.h"
#include "iomux_config.h"
#include "iomux_define.h"
#include "iomux_register.h"
#include "utility/system_util.h"
#include "gpio/gpio.h"
#include "core/interrupt.h"
#include "gic/gic.h"
#include "ccm_pll.h"
#include "ioexpander/max7310.h"
#include "i2c/imx_i2c.h"
#include "uart/imx_uart.h"
#include "timer/timer.h"
#include "usb/usb.h"
#include "keypad/keypad_port.h"
#include "spi/ecspi_ifc.h"
#include "enet/enet.h"
#include "board_id/board_id.h"

#include "buffers.h"

#include "board_io_expanders.h"
#include "board_i2c.h"

#if defined(CHIP_MX6DQ)
#include "sata/imx_sata.h"
#endif

#endif // __SDK_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
