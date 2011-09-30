/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file hardware.c
 * @brief This file contains the module definitions and some init functions.
 *
 * @ingroup diag_init
 */

#include <math.h>
#include "hardware.h"
#include <iomux_config.h>

extern int32_t board_id;

#define ON 1
#define OFF 0

// ARM core.
#define DUMMY_ARM_CORE_BASE_ADDR 0x12345789
struct hw_module arm_core = {
    "Cortex A9 core",
    DUMMY_ARM_CORE_BASE_ADDR,
    792000000,
};

// UART4 is the serial debug/console port
struct hw_module g_debug_uart = {
    "UART4 for debug",
    UART4_BASE_ADDR,
    80000000,
    IMX_INT_UART4,
    &default_interrupt_routine,
};

/* EPIT1 used for time functions */
struct hw_module g_system_timer = {
    "EPIT1 for system timer",
    EPIT1_BASE_ADDR,
    66000000,
    IMX_INT_EPIT1,
    &default_interrupt_routine,
};

struct hw_module ddr = {
    "DDR memory",
    MMDC_P0_BASE_ADDR,
};

struct hw_module *mx61_module[] = {
    &arm_core,
    &ddr,
    &g_debug_uart,
    &g_system_timer,
    NULL,
};

const uint32_t g_mx_gpio_port[MAX_GPIO_PORT] = {
    GPIO1_BASE_ADDR,
    GPIO2_BASE_ADDR,
    GPIO3_BASE_ADDR,
    GPIO4_BASE_ADDR,
    GPIO5_BASE_ADDR,
    GPIO6_BASE_ADDR,
    GPIO7_BASE_ADDR
};

/*!
 * Retrieve the freq info based on the passed in module_base.
 * @param   module_base     the base address of the module
 * @return  frequency in Hz (0 means not a valid module)
 */
uint32_t get_freq(uint32_t module_base)
{
    if (module_base == DUMMY_ARM_CORE_BASE_ADDR)
        return get_main_clock(CPU_CLK);
    else if (module_base == MMDC_P0_BASE_ADDR)
        return get_main_clock(MMDC_CH0_AXI_CLK);
    else if (module_base == g_debug_uart.base)
        return get_peri_clock(UART4_BAUD);
    else if (module_base == g_system_timer.base)
        return g_system_timer.freq;
    else {
        printf("Not a valid module base address \n");
        return 0;
    }
}

/*!
 * Retrieve the clocks based on the hardware configuration and fill in the freq
 * info in each module's structure.
 */
void freq_populate(void)
{
    int32_t i;
    struct hw_module *tmp;

    /* Populate module frequency settings (important for UART driver) */
    for (i = 0; (tmp = mx61_module[i]) != NULL; i++) {
        tmp->freq = get_freq(tmp->base);
    }
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int32_t i;
    struct hw_module *tmp;
    printf("======== Clock frequencies(HZ) =========\n");

    for (i = 0; (tmp = mx61_module[i]) != NULL; i++) {
        printf("%s\t: %d,%03d,%03d\n", tmp->name, tmp->freq / 1000000,
               (tmp->freq % 1000000) / 1000, tmp->freq % 1000);
    }

    printf("========================================\n\n");
}

/*!
 * Display the board's DDR configuration
 */
void show_ddr_config(void)
{
    uint32_t temp1, dsiz, row, col, cs_info;
    uint32_t temp2, num_banks, ddr_type;
    uint32_t density, megabyte;
    uint32_t num_rows = 1, num_cols = 1, num_dsiz = 1, i = 1;
    
    printf("========== DDR configuration ===========\n");

    megabyte = 1024 * 1024;
    /* read ESDCTL and gather information */
    temp1 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x00);
    dsiz = ((temp1 & (0x00030000)) >> 16);
    /*Calculate dsize */
    while (i <= dsiz) {
        num_dsiz *= 2;
        i++;
    }
    dsiz = 16 * num_dsiz;

    row = ((temp1 & (0x07000000)) >> 24) + 11;
    col = ((temp1 & (0x00700000)) >> 20) + 9;
    cs_info = (temp1 & (0xC0000000)) >> 30;
    /* read ESDMISC to get # of BANK info */
    temp2 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x18);
    num_banks = (!((temp2 & (0x00000020)) >> 5)) * 4 + 4;
    ddr_type = (temp2 & (0x00000018)) >> 3;
    printf("data bits: %d, num_banks: %d \n", dsiz, num_banks);
    printf("row: %d, col: %d \n", row, col);

    if (ddr_type == 1)
        printf("DDR type is DDR2 \n");
    else if (ddr_type == 2)
        printf("DDR type is LPDDR2\n");
    else
        printf("DDR type is DDR3 \n");

    if (cs_info == 0)
        printf("No chip select is enabled \n");
    else if (cs_info == 2)
        printf("Chip select CSD0 is used \n");
    else if (cs_info == 1)
        printf("Chip select CSD1 is used  \n");
    else
        printf("Both chip select CSD0 and CSD1 are used  \n");

    /* Now calculate the DDR density per chip select */

    i = 1;
    /* First need to calculate the number of rows and cols 2^row and 2^col */
    while (i <= row) {
        num_rows *= 2;
        i++;
    }

    printf1("num_rows= %d\n", num_rows);
    i = 1;

    while (i <= col) {
        num_cols *= 2;
        i++;
    }

    printf1("num_cols= %d\n", num_cols);
    density = num_rows * num_cols / megabyte;
    density = density * dsiz * num_banks / 8;
    printf("Density per chip select: %dMB \n", density);
    printf("========================================\n\n");
}

extern void uart2_iomux_config();
extern void uart4_iomux_config();

/*!
 * That function calls the board dependent IOMUX configuration functions
 */
void uart_iomux_config(uint32_t module_base_add)
{
    switch (module_base_add) {
    case UART2_BASE_ADDR:
        uart2_iomux_config();
        break;
    case UART4_BASE_ADDR:
        uart4_iomux_config();
        break;

    default:
        break;
    }
}

/*!
  * Set up the IOMUX for I2C
  */
void io_cfg_i2c(uint32_t module_base)
{
    switch (module_base) {
    case I2C1_BASE_ADDR:
        i2c1_iomux_config();

        break;

    case I2C2_BASE_ADDR:
        i2c2_iomux_config();

        break;

    case I2C3_BASE_ADDR:
        i2c3_iomux_config();
        break;
    default:
        break;
    }
}

/*!
 * configure the iomux pins for ipu display interface 0
 * choose ipu1 as the source.
 */
void ipu_iomux_config(void)
{
    ipu1_iomux_config();
}

/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(void)
{
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
}

void ldb_iomux_config(void)
{
}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol CEC
 * port including CEC_LINE
 */
void hdmi_tx_cec_pgm_iomux(void)
{
    // config EIM_A25 pad for hdmi_tx instance CEC_LINE port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_A25, ALT6);
    // Pad EIM_A25 is involved in Daisy Chain.
    reg32_write(IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT, 0x0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_A25, 0x1f8b0);

}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol DDC
 * ports including DDC_SCL, DDC_SDA.
 */
void hdmi_tx_ddc_pgm_iomux(void)
{
    // config KEY_COL3 pad for hdmi_tx instance DDC_SCL port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_COL3, ALT2);
    // Pad KEY_COL3 is involved in Daisy Chain.
    reg32_write(IOMUXC_HDMI_TX_II2C_MSTH13TDDC_SCLIN_SELECT_INPUT, 0x1);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_KEY_COL3, 0x1f8b0);

    // config KEY_ROW3 pad for hdmi_tx instance DDC_SDA port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3, ALT2);
    // Pad KEY_ROW3 is involved in Daisy Chain.
    reg32_write(IOMUXC_HDMI_TX_II2C_MSTH13TDDC_SDAIN_SELECT_INPUT, 0x1);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3, 0x1f8b0);

}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol PHYDTB
 * ports including {OPHYDTB[1]}, {OPHYDTB[0]}
 */
void hdmi_tx_phydtb_pgm_iomux(void)
{
    // config SD1_DAT1 pad for hdmi_tx instance OPHYDTB[0] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1, ALT6);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1, 0x000b1);

    // config SD1_DAT0 pad for hdmi_tx instance OPHYDTB[1] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0, ALT6);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD1_DAT0, 0x000b1);

}

/*!
 * HDMI pin mux and internal connection mux
 * be noted that the HDMI is drivern by the IPU1 di0 here
 */
void hdmi_pgm_iomux(void)
{
    uint32_t regval = 0;
    hdmi_tx_cec_pgm_iomux();
    hdmi_tx_ddc_pgm_iomux();
    hdmi_tx_phydtb_pgm_iomux();

    /*select ipu1 di0 as hdmi input */
    regval = reg32_read(IOMUXC_GPR3);
    reg32_write(IOMUXC_GPR3, regval & 0xFFFFFFF0);
}

/*!
 * uSDHC pin mux and pad configure
 */
void usdhc_iomux_config(uint32_t base_address)
{
    switch (base_address) {
    case USDHC1_BASE_ADDR:
        break;

    case USDHC2_BASE_ADDR:
        break;

    case USDHC3_BASE_ADDR:
        usdhc3_iomux_config();
        break;

    case USDHC4_BASE_ADDR:

        usdhc4_iomux_config();
        break;

    default:
        break;
    }
}

void ssi_io_cfg(void)
{
}

void SGTL5000PowerUp_and_clockinit(void)
{
}

/* Configure iomux for ESAI */
void esai_io_cfg(void)
{
    esai1_iomux_config();
}

void esai_clk_sel_gate_on()
{
    uint32_t val = 0;
#if ((defined MX61_ARD) || (defined MX61_SMD) || (defined MX61_QSB) || (defined MX61_EVB))
    val = readl(CCM_CSCMR2);
    val &= ~(0x03 << 19);
    val |= 0x01 << 19;          //source from PLL3_508
    writel(val, CCM_CSCMR2);

    val = readl(CCM_CCGR1);
    val |= 0x03 << 16;          //Gate on esai_clk
    writel(val, CCM_CCGR1);
#endif
}

/*!
 * Power no esai codec.
 */
int esai_codec_power_on(void)
{
    //No need do anything for mx61_ard
    return 0;
}

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
    // Configure some board signals through I/O expanders
    max7310_i2c_req_array[0].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
    max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    max7310_i2c_req_array[1].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[1].dev_addr = MAX7310_I2C_ID1;    // the I2C DEVICE address
    max7310_init(1, MAX7310_ID1_DEF_DIR, MAX7310_ID1_DEF_VAL);
}

uint32_t GetCPUFreq(void)
{
    return 1000000000;
}
