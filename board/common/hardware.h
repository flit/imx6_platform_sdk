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
#include "sata/imx_sata.h"
#include "timer/timer.h"
#include "hdmi_regs.h"
#include "buffers.h"
#include "usb/usb.h"
#include "keypad/keypad_port.h"
#include "ioexpander/max7310.h"
#include "board_io_expanders.h"

//Add for obds tests
#include "audio/audio.h"
#include "audio/imx-audmux.h"
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

#define WEIM_REGISTERS_BASE_ADDR WEIM_BASE_ADDR
#define WEIM_CS_BASE_ADDR   0x08000000

#if defined(BOARD_EVB) || defined(BOARD_SMART_DEVICE) || defined(BOARD_SABRE_LITE)
#define MMDC0_BASE_ADDR			0x10000000
#define MMDC0_END_ADDR			0x4FFFFFFF
/*For SMD and QSB, there is no DDR_CS1, just define them to avoid build error, but the memory region can not be accessed */
#define MMDC1_BASE_ADDR			0x50000000
#define MMDC1_END_ADDR			0x8FFFFFFF
#endif
#if defined(BOARD_SABRE_AI)
#define MMDC0_BASE_ADDR			0x10000000
#define MMDC0_END_ADDR			0x8FFFFFFF  //Maybe should be modified according the ddr init file.
/*Actually, ARD has no DDR_CS1, just define them to avoid build error, but the memory region can not be accessed */
#define MMDC1_BASE_ADDR			0x90000000
#define MMDC1_END_ADDR			0xFFFFFFFF
#endif

#define CSD0_BASE_ADDR      MMDC0_BASE_ADDR
#define CSD1_BASE_ADDR      MMDC1_BASE_ADDR

#define IPU1_CTRL_BASE_ADDR  IPU1_BASE_ADDR
#define IPU2_CTRL_BASE_ADDR  IPU2_BASE_ADDR

#define ESDCTL_ESDSCR_OFFSET  0x1C

// audio defines
#define WM8958_I2C_DEV_ADDR 		(0x34>>1)
#define WM8958_I2C_BASE_ADDR		I2C2_BASE_ADDR

#define WM8962_I2C_DEV_ADDR             (0x34>>1)
#define WM8962_I2C_BASE_ADDR            I2C1_BASE_ADDR

#define SGTL5000_I2C_BASE   I2C2_BASE_ADDR  // audio codec on i2c2
#define SGTL5000_I2C_ID     0x0A

#define SI476x_I2C_BASE    I2C2_BASE_ADDR
#define SI476x_I2C_ID      (0xC6 >> 1)

#define OS81050_I2C_BASE    I2C3_BASE_ADDR
#define OS81050_I2C_ID      (0x40 >> 1)

#define ADV7180_I2C_ID      (0x42 >> 1)
#if defined (BOARD_EVB)
#define ADV7180_I2C_BASE 	I2C1_BASE_ADDR
#else
#define ADV7180_I2C_BASE    I2C3_BASE_ADDR
#endif




#define MMA8450_I2C_ID      0x1C
#define MMA8451_I2C_ID      0x1C
#define MAG3112_I2C_ID      0x1D
#define ISL29023_I2C_ID	    0x44
#define MAG3110_I2C_ID      0x0E

#define MAX11801_I2C_BASE	I2C3_BASE_ADDR
#define MAX11801_I2C_ID     (0x90 >> 1)

#define CS42888_I2C_BASE	I2C1_BASE_ADDR
#define CS42888_I2C_ID      (0x90 >> 1)

#define AT24Cx_I2C_BASE		I2C3_BASE_ADDR
#define AT24Cx_I2C_ID		(0xA0 >> 1)

// For LTC2495 Board ID
#define LTC2495_I2C_BASE    I2C2_BASE_ADDR
#define LTC2495_I2C_ID      (0x28 >> 1)

//copied from OBDS
#if defined(BOARD_SABRE_LITE)
#define P1003_TSC_I2C_BASE   I2C3_BASE_ADDR
#else
#define P1003_TSC_I2C_BASE   I2C2_BASE_ADDR
#endif
#define P1003_TSC_I2C_ID     4

// USB test defines
#define MX53_USBH1_BASE_ADDR    0x53F80200
#define MX53_USBH2_BASE_ADDR    0x53F80400
#define MX53_USBH3_BASE_ADDR    0x53F80600
#define USBH1_BASE_ADDR          MX53_USBH1_BASE_ADDR
#define USBH2_BASE_ADDR         MX53_USBH2_BASE_ADDR
#define USB_OTG_MIRROR_REG  (USBOH3_BASE_ADDR+0x804)
#define USB_CLKONOFF_CTRL          (USBOH3_BASE_ADDR+0x824)
#define USBH2_VIEWPORT      (USBH2_BASE_ADDR + 0x170)
#define USB_CTRL_1      (USBOH3_BASE_ADDR + 0x810)
#define UH2_PORTSC1 (USBH2_BASE_ADDR + 0x184)

#define USBOH3_BASE_ADDR      USBOH3_USB_BASE_ADDR


#define FEC_BASE_ADDR         ENET_BASE_ADDR

//0x00907000 D IRAM_FREE_SPACE_START
//0x00937FFC D IRAM_FREE_SPACE_END

/*qh and td pointers definition*/
#define QH_BUFFER               0x00908000  // internal RAM
#define TD_BUFFER               0x00908100  // internal RAM

#define SATA_PROTOCOL_BUFFER_BASE 0x0090a000
#define SATA_PROTOCOL_BUFFER_SIZE 0x1000
#define SATA_TRANSFER_BUFFER_BASE 0x0090c000

// input clocks
#define CKIL        32768
#define FREQ_24MHZ  24000000
#define CKIH        22579200


extern hw_module_t g_debug_uart;
extern hw_module_t g_system_timer;



void freq_populate(void);
uint32_t get_freq(uint32_t module_base);
void board_init(void);
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


//Copy from obds
#define PMIC_MC13892_I2C_BASE      I2C2_BASE_ADDR
#define PMIC_LTC3589_I2C_BASE      I2C2_BASE_ADDR
#define PMIC_DA9053_I2C_BASE       I2C1_BASE_ADDR
#define PMIC_PF0100_I2C_BASE       I2C2_BASE_ADDR 
#define PMIC_MAX17135_I2C_BASE     I2C1_BASE_ADDR


#endif /* __HARDWARE_H__ */
