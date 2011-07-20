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

#ifndef HARDWARE_H_
#define HARDWARE_H_
#include "soc_memory_map.h"
#include "io.h"
#include "iomux_define.h"
#include "iomux_register.h"
#include "gpio_define.h"
#include "ccm_pll_reg_define.h"
#include "iim_fuse.h"
#include "imx_i2c.h"

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
#define HW_ANADIG_PLL_528_DENOM     (ANATOP_BASE_ADDR+0x60) // Denominator of 528MHz PLL Fractional Loop Divider Register
#define HW_ANADIG_PFD_528_RW        (ANATOP_BASE_ADDR+0x100)    // 528MHz Clock Phase Fractional Divider Control Register
#define HW_ANADIG_PLL_SYS_RW        (ANATOP_BASE_ADDR+0x000)    // "System PLL" "CPU PLL" "PLL1"

// Defines needed for existing drivers - TODO: cleanup
#define EPIT_BASE_ADDR      EPIT1_BASE_ADDR

#define CSD0_BASE_ADDR      MMDC0_ARB_BASE_ADDR
#define CSD1_BASE_ADDR      MMDC1_ARB_BASE_ADDR
#define WEIM_CS_BASE_ADDR   0x08000000

#define IPU1_CTRL_BASE_ADDR  IPU1_ARB_BASE_ADDR
#define IPU2_CTRL_BASE_ADDR  IPU2_ARB_BASE_ADDR

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

// MAX7310 I2C settings
/* For the ARD board which has 2 MAX7310 */
#define MAX7310_NBR 2
/* Number 1 controls: BACKLIGHT_ON, PORT3_P114, CPU_PER_RST_B, PORT3_P110,
   PORT3_P105, PORT3_P112, PORT3_P107, PORT3_P109.
*/
#define MAX7310_I2C_BASE_ID0  I2C3_BASE_ADDR
#define MAX7310_I2C_ID0     (0x36 >> 1)
#define MAX7310_ID0_DEF_DIR      0x00   // init direction for the I/O
#define MAX7310_ID0_DEF_VAL      0xFF   // init value for the output
/* Number 1 controls: CTRL_0, CTRL_1, CTRL_2, CTRL_3, CTRL_4, PORT3_P116,
   PORT2_P81, PORT3_P101
*/
#define MAX7310_I2C_BASE_ID1  I2C3_BASE_ADDR
#define MAX7310_I2C_ID1     (0x3E >> 1)
#define MAX7310_ID1_DEF_DIR      0x00   // init direction for the I/O
/*Set the max7310_id1 's default value for ctrl_x */
#define MAX7310_ID1_DEF_VAL      0x09   // init value for the output
/* create an array of I2C requests for all used expanders on the board */
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
#define AT24Cx_I2C_ID		0x50

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

// **** MUST DEFINE for mx61 for their corresponding tests to run
// or remove tests for mx61
#define USBOH3_BASE_ADDR			USBOH3_USB_BASE_ADDR
#define FEC_BASE_ADDR         ENET_BASE_ADDR

#define CSPI_BASE_ADDR        ECSPI1_BASE_ADDR
#define IIM_BASE_ADDR         0x0
#define BOARD_ID_MX53_ARD     0xF1
#define BOARD_ID_MX53_SBRTH_SMD 0xF2
#define BOARD_ID_MX53_SBRTH_LCB 0xF3
#define BOARD_ID_MX53_EVK  0xF4
#define M4IF_REGISTERS_BASE_ADDR 0x0
#define WEIM_REGISTERS_BASE_ADDR 0x0
#define ESDHC1_BASE_ADDR 0x0
#define ESDHC2_BASE_ADDR 0x1
#define ESDHC3_BASE_ADDR 0x2
#define DPLLIP1_BASE_ADDR 0x0
#define DPLLIP2_BASE_ADDR 0x1
#define DPLLIP3_BASE_ADDR 0x2
#define DPLLIP4_BASE_ADDR 0x3

#define USDHC_ADMA_BUFFER 0x00910000
#define ESDCTL_REGISTERS_BASE_ADDR 0x021b0000
// **** 

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
// input CKIL clock
#define __CLK_TCK   32768
#define FREQ_24MHZ               24000000
#define CKIH                            22579200

// I2C specific defines
// For LTC Board ID
#define BOARD_ID_I2C_BASE I2C2_BASE_ADDR

// register defines for the SRTC function of the SNVS
#define SRTC_LPSCMR         (SNVS_BASE_ADDR + 0x50)
#define SRTC_LPSCLR         (SNVS_BASE_ADDR + 0x54)
#define SRTC_LPCR           (SNVS_BASE_ADDR + 0x38)
#define SRTC_HPSCMR          (SNVS_BASE_ADDR + 0x24)
#define SRTC_HPSCLR          (SNVS_BASE_ADDR + 0x28)
#define SRTC_HPCR           (SNVS_BASE_ADDR + 0x08)

//provide macros for test enter and exit outputs
#define TEST_ENTER(name) printf ("Running test: %s\n", name)

#define TEST_EXIT(name)  do {printf (" ..Test: %s\n", name); \
                                                } while (0)
enum main_clocks {
    CPU_CLK,
    AHB_CLK,
    IPG_CLK,
    IPG_PER_CLK,
    DDR_CLK,
    NFC_CLK,
    USB_CLK,
    VPU_CLK,
};

enum peri_clocks {
    UART1_BAUD,
    UART2_BAUD,
    UART3_BAUD,
    UART4_BAUD,
    SSI1_BAUD,
    SSI2_BAUD,
    CSI_BAUD,
    MSTICK1_CLK,
    MSTICK2_CLK,
    SPI1_CLK = ECSPI1_BASE_ADDR,
    SPI2_CLK = ECSPI2_BASE_ADDR,
};

enum plls {
    PLL1,
    PLL2,
    PLL3,
    PLL4,
};

enum display_type {
    DISP_DEV_NULL = 0,
    DISP_DEV_TFTLCD,
    DISP_DEV_LVDS,
    DISP_DEV_VGA,
    DISP_DEV_HDMI,
    DISP_DEV_TV,
};

enum lvds_panel_bit_mode {
    LVDS_PANEL_18BITS_MODE = 0x0,
    LVDS_PANEL_24BITS_MODE = 0x1,
};

u32 pll_clock(enum plls pll);
u32 get_main_clock(enum main_clocks clk);
u32 get_peri_clock(enum peri_clocks clk);
void clock_setup(u32 core_clk, u32 ahb_div);
void io_cfg_i2c(u32 module_base);
void freq_populate(void);
void show_freq(void);
void show_ddr_config(void);
void board_init(void);
void reset_usb_hub(void);
void usb_clock_enable(void);
void imx_enet_setup(void);
void esai_iomux(void);
void gpmi_nand_pinmux_config(void);
void gpmi_nand_clk_setup(void);

extern void hal_delay_us(unsigned int);
extern int max7310_init(unsigned int, unsigned int, unsigned int);
extern void max7310_set_gpio_output(unsigned int, unsigned int, unsigned int);

extern int board_id;
extern int board_rev;
extern int spi_nor_test_enable;
extern int pmic_mc13892_test_enable;
extern imx_spi_init_func_t spi_init_flash;
extern imx_spi_xfer_func_t spi_xfer_flash;
extern struct imx_spi_dev imx_spi_nor;
extern int fec_test_enable;
extern int lan9220_test_enable;
extern int enet_test_enable;
extern int ar8031_test_enable;
extern int ds90ur124_test_enable;
extern int ltc3589_i2c_device_id_test_enable;
extern int adv7180_test_enable;
extern int si476x_test_enable;
extern int esai_test_enable;
extern int weim_nor_flash_test_enable;
extern int max7310_i2c_device_id_test_enable;
extern int sata_test_enable;
extern int nand_test_enable;
extern int usbh_ulpi_phy_read_test_enable;
extern u32 usbh_ulpi_phy_read_test_base;
extern int usbh_dev_enum_test_enable;
extern u32 usbh_dev_enum_test_base;
extern int usbh_hub251x_test_enable;
extern u32 usbh_hub251x_test_base;
extern int i2s_audio_output_test_enable;
extern int gps_test_enable;
extern int gpio_keyboard_test_enable;
extern int smbus_test_enable;
extern int camera_test_enable;
extern int touch_screen_test_enable;
extern int ipu_display_test_enable;
extern int ipu_display_panel[];
extern int ddr_test_enable;
extern u32 ddr_density, ddr_num_of_cs;
extern int mlb_os81050_test_enable;
extern int i2c_id_check_test_enable;
extern int i2c_device_id_check_DA9053_test_enable;
extern int i2c_device_id_check_mag3112_test_enable;
extern int i2c_device_id_check_isl29023_test_enable;
extern int i2c_device_id_check_mma8451_test_enable;
extern int mmcsd_test_enable;
extern u32 mmcsd_bus_width, mmc_sd_base_address;
extern int eeprom_test_enable;
extern void gpio_backlight_lvds_en(void);
extern int android_buttons_test_enable;
//extern u32 AT45DB321D;
//extern u32 M25P32;

/* Board ID */
#define BOARD_ID_DEFAULT        0x0
#define BOARD_ID_MX61_ARD       0x1
#define BOARD_ID_MX61_SMD       0x2

/* Board version */
#define BOARD_VERSION_DEFAULT	0x0
#define BOARD_VERSION_1	0x1
#define BOARD_VERSION_2	0x2
#define BOARD_VERSION_3	0x1
#define BOARD_VERSION_4	0x2
#define BOARD_VERSION_5	0x1

#define PMIC_MC13892_I2C_BASE       I2C2_BASE_ADDR
#define PMIC_LTC3589_I2C_BASE       I2C2_BASE_ADDR
#define PMIC_DA9053_I2C_BASE        I2C1_BASE_ADDR

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
#else
#error Need to define a board type
#endif

#endif /*HARDWARE_H_ */
