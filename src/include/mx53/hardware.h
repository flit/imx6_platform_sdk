/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
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
#include "soc_memory_map.h"
#include "io.h"
#include "system_util.h"
#include "iomux_define.h"
#include "iomux_register.h"
#include "gpio.h"
#include "interrupt.h"
#include "ccm_pll.h"
#include "iim_fuse.h"
#include "imx_i2c.h"
#include "imx_uart.h"
#include "imx_spi.h"
#include "imx_sata.h"
#include "epit.h"
#include "gpt.h"
#include "timer.h"

// Defines needed for existing drivers - TODO: cleanup
#define CSD0_BASE_ADDR      CSD0_DDR_BASE_ADDR
#define CSD1_BASE_ADDR      CSD1_DDR_BASE_ADDR
#define WEIM_CS_BASE_ADDR   0xF0000000

#define IPU1_CTRL_BASE_ADDR  0
#define IPU2_CTRL_BASE_ADDR  0

#define ESDCTL_ESDSCR_OFFSET  0x1C

// audio defines
#define SGTL5000_I2C_BASE   I2C2_BASE_ADDR  // audio codec on i2c2
#define SGTL5000_I2C_ID     0x0A
// SGTL5000 specific register values
#define CHIP_REF_CTRL_REG_VALUE 0x01FF  // VDDA/2
#define CHIP_LINE_OUT_CTRL_REG_VALUE 0x0322 // VDDIO/2
#define CHIP_LINE_OUT_VOL_REG_VALUE 0x0F0F  // based on VDDA and VDDIO values
#define CHIP_CLK_TOP_CTRL_REG_VALUE 0   // pass through, Input OSC 13.5MHz, default configuration for sample rate, 48KHz
#define CHIP_PLL_CTRL_REG_VALUE ((14 << 11) | (1154))
#define CHIP_CLK_CTRL_REG_VALUE ((0x2 << 2) | (0x3))
#define CHIP_CLK_CTRL_REG_MCLK_FREQ_VALUE 0x3   /*12MHz =256*Fs */
#define CHIP_PLL_CTRL_REG_VALUE2     ((16 << 11) | (786))   // for CodecInit2

#define SI476x_I2C_BASE    I2C2_BASE_ADDR
#define SI476x_I2C_ID      (0xC6 >> 1)

#define OS81050_I2C_BASE    I2C3_BASE_ADDR
#define OS81050_I2C_ID      (0x40 >> 1)

#define ADV7180_I2C_BASE    I2C3_BASE_ADDR
#define ADV7180_I2C_ID      (0x42 >> 1)

// MAX7310 I2C settings
/* For the ARD board which has 1 MAX7310 */
#define MAX7310_NBR 1
/* Number 0 controls: BACKLITE_ON, SAT_SHUTDN_B, CPU_PER_RST_B, MAIN_PER_RST_B,
   IPOD_RST_B, MLB_RST_B, SSI_STEERING, GPS_RST_B.
*/
#define MAX7310_I2C_BASE_ID0  I2C3_BASE_ADDR
#define MAX7310_I2C_ID0     (0x30 >> 1)
#define MAX7310_ID0_DEF_DIR      0x0    // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xC    // init value for the output
/* create an array of I2C requests for all used expanders on the board */
struct imx_i2c_request max7310_i2c_req_array[MAX7310_NBR];

#define MMA8450_I2C_ID      0x1C
#define MMA8451_I2C_ID      0x1C
#define MAG3112_I2C_ID      0x1D
#define ISL29023_I2C_ID	    0x44

#define MAX11801_I2C_ID     (0x92 >> 1)
#define CS42888_I2C_BASE	I2C1_BASE_ADDR
#define CS42888_I2C_ID      (0x90 >> 1)

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

/*qh and td pointers defintion*/
#define QH_BUFFER               0xF8006000  // internal RAM
#define TD_BUFFER               0xF8006100  // internal RAM

// SATA test defines
#define SATA_CONTRLLER_BASE_PHYSICAL_ADDR  0x10000000   //SATA Phyical Address
#define SATA_CONTRLLER_BASE_VIRTUAL_ADDR   0xF9200000
#define SATA_CONTRLLER_BASE_ADDR  SATA_CONTRLLER_BASE_PHYSICAL_ADDR //SATA_CONTRLLER_BASE_VIRTUAL_ADDR

#define SATA_PROTOCOL_BUFFER_BASE 0xF8006000
#define SATA_PROTOCOL_BUFFER_SIZE 0x1000
#define SATA_TRANSFER_BUFFER_BASE 0xF8002000
// input CKIL clock
#define CKIL        32768
#define FREQ_24MHZ  24000000
#define CKIH        22579200

// SRTC defines
#define SRTC_LPSCMR         (SRTC_BASE_ADDR + 0x00)
#define SRTC_LPSCLR         (SRTC_BASE_ADDR + 0x04)
#define SRTC_LPCR           (SRTC_BASE_ADDR + 0x10)
#define SRTC_HPSCMR         (SRTC_BASE_ADDR + 0x20)
#define SRTC_HPSCLR         (SRTC_BASE_ADDR + 0x24)
#define SRTC_HPCR           (SRTC_BASE_ADDR + 0x30)

// I2C specific defines
// For LTC Board ID
#define BOARD_ID_I2C_BASE I2C2_BASE_ADDR

//provide macros for test enter and exit outputs
#define TEST_ENTER(name) printf ("Running test: %s\n", name)

#define TEST_EXIT(name)  do {printf (" ..Test: %s\n", name); \
                                                } while (0)

enum display_type {
    DISP_DEV_NULL = 0,
    DISP_DEV_TFTLCD,
    DISP_DEV_LVDS,
    DISP_DEV_VGA,
    DISP_DEV_HDMI,
    DISP_DEV_TV,
};

uint32_t get_main_clock(enum main_clocks clk);
uint32_t get_peri_clock(enum peri_clocks clk);
void clock_setup(uint32_t core_clk, uint32_t ahb_div);
void uart_iomux_config(uint32_t module_base_add);
void i2c_iomux_config(uint32_t module_base);
void freq_populate(void);
void show_freq(void);
uint32_t get_freq(uint32_t module_base);
uint32_t GetCPUFreq(void);
void show_ddr_config(void);
void board_init(void);
void reset_usb_hub(void);
void usb_clock_enable(void);
void imx_fec_setup(void);
void esai_iomux(void);
void audmux_iomux_config(void);

struct hw_module g_debug_uart;
struct hw_module g_system_timer;

#define MAX_GPIO_PORT   7
const uint32_t g_mx_gpio_port[MAX_GPIO_PORT];

extern void platform_init(void);
extern int32_t board_id;
extern int32_t board_rev;
extern int32_t max7310_init(uint32_t, uint32_t, uint32_t);
extern imx_spi_init_func_t spi_init_flash;
extern imx_spi_xfer_func_t spi_xfer_flash;
extern struct imx_spi_dev imx_spi_nor;
extern int32_t ipu_display_panel[];
extern uint32_t ddr_density, ddr_num_of_cs;
extern uint32_t mmcsd_bus_width, mmc_sd_base_address;
extern void gpio_backlight_lvds_en(void);
extern void StartPerfCounter(void);
extern uint32_t StopPerfCounter(void);
extern int32_t is_input_char(uint8_t c);

/* Board ID */
#define BOARD_ID_DEFAULT        0x0
#define BOARD_ID_MX53_EVK       0x1
#define BOARD_ID_MX53_CPU2      0x2
#define BOARD_ID_MX53_CPU3      0x3
#define BOARD_ID_MX53_ARD       0x7
#define BOARD_ID_MX53_LCB       0xC
#define BOARD_ID_MX53_SMD       0x9

/* Board version */
#define BOARD_VERSION_DEFAULT	0x0
#define BOARD_VERSION_1	0x1
#define BOARD_VERSION_2	0x2
#define BOARD_VERSION_3	0x1
#define BOARD_VERSION_4	0x2
#define BOARD_VERSION_5	0x1

typedef uint32_t(*pmic_mc13892_reg_t) (uint32_t reg, uint32_t val, uint32_t write);

#define PMIC_MC13892_I2C_BASE       I2C2_BASE_ADDR
#define PMIC_LT3589_I2C_BASE        I2C2_BASE_ADDR
#define PMIC_DA9053_I2C_BASE        I2C1_BASE_ADDR

#if defined(BOARD_VERSION2)
#define BOARD_VERSION_ID        BOARD_VERSION_2
#elif defined(BOARD_VERSION1)
#define BOARD_VERSION_ID        BOARD_VERSION_1
#else
#error Need to define a board revision
#endif

#if defined(MX53_EVK)
#define BOARD_TYPE_ID           BOARD_ID_MX53_EVK
#elif defined(MX53_ARD)
#define BOARD_TYPE_ID           BOARD_ID_MX53_ARD
#elif defined(MX53_LCB)
#define BOARD_TYPE_ID           BOARD_ID_MX53_LCB
#elif defined(MX53_SMD)
#define BOARD_TYPE_ID           BOARD_ID_MX53_SMD
#else
#error Need to define a board type
#endif

#endif /* __HARDWARE_H__ */
