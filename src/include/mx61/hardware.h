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
#include "registers.h"
#include "io.h"
#include "system_util.h"
#include "iomux_config.h"
#include "iomux_define.h"
#include "iomux_register.h"
#include "gpio.h"
#include "interrupt.h"
#include "gic.h"
#include "ccm_pll.h"
#include "imx_i2c.h"
#include "imx_uart.h"
#include "imx_spi.h"
#include "imx_sata.h"
#include "epit.h"
#include "gpt.h"
#include "timer.h"
#include "hdmi_regs.h"
#include "buffers.h"

// Android_Buttons test defines
#define HOME_BUTTON_GOPIO_BASE	GPIO1_BASE_ADDR
#define HOME_BUTTON_GPIO_NUM	11
#define BACK_BUTTON_GOPIO_BASE	GPIO1_BASE_ADDR
#define BACK_BUTTON_GPIO_NUM	12
#define PROG_BUTTON_GOPIO_BASE	GPIO2_BASE_ADDR
#define PROG_BUTTON_GPIO_NUM	12
#define VOLPLUS_BUTTON_GOPIO_BASE	GPIO2_BASE_ADDR
#define VOLPLUS_BUTTON_GPIO_NUM		15
#define VOLNEG_BUTTON_GOPIO_BASE	GPIO7_BASE_ADDR
#define VOLNEG_BUTTON_GPIO_NUM		8

// PLL definitions
#define HW_ANADIG_USB1_PLL_480_CTRL_RW  (ANATOP_BASE_ADDR+0x30) // Anadig 480MHz PLL Control0 Register
#define HW_ANADIG_PLL_528_RW    (ANATOP_BASE_ADDR+0x30) // Anadig 528MHz PLL Control register
#define HW_ANADIG_PLL_528_NUM   (ANATOP_BASE_ADDR+0x50) // Numerator of 528MHz PLL Fractional Loop Divider Register
#define HW_ANADIG_PLL_528_DENOM (ANATOP_BASE_ADDR+0x60) // Denominator of 528MHz PLL Fractional Loop Divider Register
#define HW_ANADIG_PFD_528_RW    (ANATOP_BASE_ADDR+0x100)    // 528MHz Clock Phase Fractional Divider Control Register
#define HW_ANADIG_PLL_SYS_RW    (ANATOP_BASE_ADDR+0x000)    // "System PLL" "CPU PLL" "PLL1"
#define HW_ANADIG_PLL_ETH_CTRL  (ANATOP_BASE_ADDR+0x0e0)

#define WEIM_REGISTERS_BASE_ADDR WEIM_BASE_ADDR
#define WEIM_CS_BASE_ADDR   0x08000000

#if defined(MX61_EVB) || defined(MX61_SMD) || defined(MX61_QSB)
#define MMDC0_BASE_ADDR			0x10000000
#define MMDC0_END_ADDR			0x4FFFFFFF
/*For smd and qsb, there is no DDR_cs1, just define them to avoid build error. And the memory region can not be accessed*/
#define MMDC1_BASE_ADDR			0x50000000
#define MMDC1_END_ADDR			0x8FFFFFFF
#endif
#if defined(MX61_ARD)
#define MMDC0_BASE_ADDR			0x10000000
#define MMDC0_END_ADDR			0x8FFFFFFF  //Maybe should be modified according the ddr init file.
/*Acturally, ard has no DDR_cs1, just define them to avoid build error. And the memory region can not be accessed*/
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

/*******************************************************
 *      I/O expander MAX7310 I2C settings
 *******************************************************/
/* For the ARD board which has 3 MAX7310 */
#ifdef MX61_ARD
#define MAX7310_NBR 3
/* I/O expander A */
#define MAX7310_I2C_BASE_ID0  I2C3_BASE_ADDR
#define MAX7310_I2C_ID0          (0x30 >> 1)
#define MAX7310_ID0_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xFF   // init value for the output

/* I/O expander B */
#define MAX7310_I2C_BASE_ID1  I2C3_BASE_ADDR
#define MAX7310_I2C_ID1          (0x32 >> 1)
#define MAX7310_ID1_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID1_DEF_VAL      0xE7   // init value for the output

/* I/O expander C */
#define MAX7310_I2C_BASE_ID2  I2C3_BASE_ADDR
#define MAX7310_I2C_ID2          (0x34 >> 1)
#define MAX7310_ID2_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID2_DEF_VAL      0x57   // init value for the output
#endif

#ifdef MX61_EVB
/* For the EVB board which has 2 MAX7310 */
#define MAX7310_NBR 2
/* Number 1 controls: BACKLIGHT_ON, PORT3_P114, CPU_PER_RST_B, PORT3_P110,
   PORT3_P105, PORT3_P112, PORT3_P107, PORT3_P109.
*/
#define MAX7310_I2C_BASE_ID0  I2C3_BASE_ADDR
#define MAX7310_I2C_ID0     (0x36 >> 1)
#define MAX7310_ID0_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xFF   // init value for the output
/* Number 2 controls: CTRL_0, CTRL_1, CTRL_2, CTRL_3, CTRL_4, PORT3_P116,
   PORT2_P81, PORT3_P101
*/
#define MAX7310_I2C_BASE_ID1  I2C3_BASE_ADDR
#define MAX7310_I2C_ID1     (0x3E >> 1)
#define MAX7310_ID1_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID1_DEF_VAL      0x09   // init value for the output
#endif

struct imx_i2c_request max7310_i2c_req_array[MAX7310_NBR];

#define MMA8450_I2C_ID      0x1C
#define MMA8451_I2C_ID      0x1C
#define MAG3112_I2C_ID      0x1D
#define ISL29023_I2C_ID	    0x44

#define MAX11801_I2C_BASE	I2C3_BASE_ADDR
#define MAX11801_I2C_ID     (0x90 >> 1)

#define CS42888_I2C_BASE	I2C1_BASE_ADDR
#define CS42888_I2C_ID      (0x90 >> 1)

#define AT24Cx_I2C_BASE		I2C3_BASE_ADDR
#define AT24Cx_I2C_ID		(0xA0 >> 1)

// For LTC2495 Board ID
#define LTC2495_I2C_BASE    I2C2_BASE_ADDR
#define LTC2495_I2C_ID      (0x28 >> 1)

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

#define FEC_BASE_ADDR         ENET_BASE_ADDR
// **** MUST DEFINE for mx61 for their corresponding tests to run
// or remove tests for mx61
/*#define USBOH3_BASE_ADDR			USBOH3_USB_BASE_ADDR

#define CSPI_BASE_ADDR        ECSPI1_BASE_ADDR
#define IIM_BASE_ADDR         0x0
#define M4IF_REGISTERS_BASE_ADDR 0x0
#define WEIM_REGISTERS_BASE_ADDR 0x0
#define ESDHC1_BASE_ADDR 0x0
#define ESDHC2_BASE_ADDR 0x1
#define ESDHC3_BASE_ADDR 0x2
#define DPLLIP1_BASE_ADDR 0x0
#define DPLLIP2_BASE_ADDR 0x1
#define DPLLIP3_BASE_ADDR 0x2
#define DPLLIP4_BASE_ADDR 0x3
*/

#define ESDCTL_REGISTERS_BASE_ADDR 0x021b0000

//0x00907000 D IRAM_FREE_SPACE_START
//0x00937FFC D IRAM_FREE_SPACE_END

/*qh and td pointers defintion*/
#define QH_BUFFER               0x00908000  // internal RAM
#define TD_BUFFER               0x00908100  // internal RAM

// SATA test defines
#define SATA_RW_TEST 1
#define SATA_CONTRLLER_BASE_PHYSICAL_ADDR  0x02200000   //SATA Phyical Address
#define SATA_CONTRLLER_BASE_ADDR  SATA_CONTRLLER_BASE_PHYSICAL_ADDR

#define SATA_PROTOCOL_BUFFER_BASE 0x0090a000
#define SATA_PROTOCOL_BUFFER_SIZE 0x1000
#define SATA_TRANSFER_BUFFER_BASE 0x0090c000

// input clocks
#define CKIL        32768
#define FREQ_24MHZ  24000000
#define CKIH        22579200

// register defines for the SRTC function of the SNVS
#define SRTC_LPSCMR     (SNVS_BASE_ADDR + 0x50)
#define SRTC_LPSCLR     (SNVS_BASE_ADDR + 0x54)
#define SRTC_LPCR       (SNVS_BASE_ADDR + 0x38)
#define SRTC_HPSCMR     (SNVS_BASE_ADDR + 0x24)
#define SRTC_HPSCLR     (SNVS_BASE_ADDR + 0x28)
#define SRTC_HPCR       (SNVS_BASE_ADDR + 0x08)

/* uSDHC specific defines */
#define ESDHC_IDENT_FREQ   ((unsigned int)0x00002080)
#define ESDHC_OPERT_FREQ   ((unsigned int)0x00000130)
#define ESDHC_HS_FREQ      ((unsigned int)0x00000110)

extern uint32_t spi_nor_flash_type; // Flag decides the SPI-NOR device
/* SPI-NOR defines */
#define AT45DB321D  1
#define M25P32      2

enum display_type {
    DISP_DEV_NULL = 0,
    DISP_DEV_TFTLCD,
    DISP_DEV_LVDS,
    DISP_DEV_VGA,
    DISP_DEV_HDMI,
    DISP_DEV_TV,
};

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
void imx_enet_setup(void);
void esai_iomux(void);
void gpmi_nand_pinmux_config(void);
void gpmi_nand_clk_setup(void);
void usdhc_iomux_config(uint32_t);
void ecspi_iomux_cfg(uint32_t);
void can_iomux_config(uint32_t module_base_add);

#define MAX_GPIO_PORT   7
const uint32_t g_mx_gpio_port[MAX_GPIO_PORT];

struct hw_module g_debug_uart;
struct hw_module g_system_timer;

extern int32_t max7310_init(uint32_t, uint32_t, uint32_t);
extern void max7310_set_gpio_output(uint32_t, uint32_t, uint32_t);

extern void platform_init(void);
extern int32_t board_id;
extern int32_t board_rev;
extern imx_spi_init_func_t spi_init_flash;
extern imx_spi_xfer_func_t spi_xfer_flash;
extern struct imx_spi_dev imx_spi_nor;
extern int32_t ipu_display_panel[];
extern uint32_t ddr_density, ddr_num_of_cs;
extern void gpio_backlight_lvds_en(void);
extern void StartPerfCounter(void);
extern uint32_t StopPerfCounter(void);
extern int32_t is_input_char(uint8_t);

/* Board ID */
#define BOARD_ID_DEFAULT        0x0
#define BOARD_ID_MX61_ARD       0x1
#define BOARD_ID_MX61_SMD       0x2
#define BOARD_ID_MX61_EVB       0x3
#define BOARD_ID_MX61_QSB       0x4

/* Board version */
#define BOARD_VERSION_DEFAULT	0x0
#define BOARD_VERSION_1	0x1
#define BOARD_VERSION_2	0x2
#define BOARD_VERSION_3	0x1
#define BOARD_VERSION_4	0x2
#define BOARD_VERSION_5	0x1

#if defined(BOARD_VERSION2)
#define BOARD_VERSION_ID        BOARD_VERSION_2
#elif defined(BOARD_VERSION1)
#define BOARD_VERSION_ID        BOARD_VERSION_1
#else
#error Need to define a board revision
#endif

#if defined(MX61_ARD)
#define BOARD_TYPE_ID           BOARD_ID_MX61_ARD
#elif defined(MX61_SMD)
#define BOARD_TYPE_ID           BOARD_ID_MX61_SMD
#elif defined(MX61_EVB)
#define BOARD_TYPE_ID           BOARD_ID_MX61_EVB
#elif defined(MX61_QSB)
#define BOARD_TYPE_ID           BOARD_ID_MX61_QSB
#else
#error Need to define a board type
#endif

#endif /* __HARDWARE_H__ */
