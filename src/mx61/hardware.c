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

/* That function calls the board dependent IOMUX configuration functions */
void iomux_config(uint32_t module_base_add)
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
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT9, ALT4 | 0x10);
        reg32_write(IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT, 0x1);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT9, 0x1b8b0);

        reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT8, ALT4 | 0x10);
        reg32_write(IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT, 0x1);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT8, 0x1b8b0);

        break;

    case I2C2_BASE_ADDR:
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_COL3, ALT4 | 0x10);
        reg32_write(IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT, 0x1);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_KEY_COL3, 0x1b8b0);

        reg32_write(IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3, ALT4 | 0x10);
        reg32_write(IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT, 0x1);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3, 0x1b8b0);

        break;

    case I2C3_BASE_ADDR:
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_5, ALT6 | 0x10);
        reg32_write(IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT, 0x2);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_GPIO_5, 0x1b8b0);

        reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_16, ALT6 | 0x10);
        reg32_write(IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT, 0x2);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_GPIO_16, 0x1b8b0);
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
    // config DI0_DISP_CLK pad for ipu1 instance DI0_DISP_CLK port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_DISP_CLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DI0_DISP_CLK, 0x000b1);

    // config DI0_PIN15 pad for ipu1 instance DI0_PIN15 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DI0_PIN15, 0x000b1);

    // config DI0_PIN2 pad for ipu1 instance DI0_PIN2 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2, 0x000b1);

    // config DI0_PIN3 pad for ipu1 instance DI0_PIN3 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN3, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DI0_PIN3, 0x000b1);

    // config DI0_PIN4 pad for ipu1 instance DI0_PIN4 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DI0_PIN4, 0x000b1);

    // config DISP0_DAT0 pad for ipu1 instance DISP0_DAT[0] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT0, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT0, 0x010b1);

    // config DISP0_DAT1 pad for ipu1 instance DISP0_DAT[1] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT1, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT1, 0x010b1);

    // config DISP0_DAT2 pad for ipu1 instance DISP0_DAT[2] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT2, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT2, 0x010b1);

    // config DISP0_DAT3 pad for ipu1 instance DISP0_DAT[3] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT3, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT3, 0x010b1);

    // config DISP0_DAT4 pad for ipu1 instance DISP0_DAT[4] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT4, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT4, 0x010b1);

    // config DISP0_DAT5 pad for ipu1 instance DISP0_DAT[5] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT5, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT5, 0x010b1);

    // config DISP0_DAT6 pad for ipu1 instance DISP0_DAT[6] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT6, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT6, 0x010b1);

    // config DISP0_DAT7 pad for ipu1 instance DISP0_DAT[7] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT7, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT7, 0x010b1);

    // config DISP0_DAT8 pad for ipu1 instance DISP0_DAT[8] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT8, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT8, 0x010b1);

    // config DISP0_DAT9 pad for ipu1 instance DISP0_DAT[9] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT9, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT9, 0x010b1);

    // config DISP0_DAT10 pad for ipu1 instance DISP0_DAT[10] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT10, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT10, 0x010b1);

    // config DISP0_DAT11 pad for ipu1 instance DISP0_DAT[11] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT11, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT11, 0x010b1);

    // config DISP0_DAT12 pad for ipu1 instance DISP0_DAT[12] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT12, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT12, 0x010b1);

    // config DISP0_DAT13 pad for ipu1 instance DISP0_DAT[13] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT13, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT13, 0x010b1);

    // config DISP0_DAT14 pad for ipu1 instance DISP0_DAT[14] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT14, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT14, 0x010b1);

    // config DISP0_DAT15 pad for ipu1 instance DISP0_DAT[15] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT15, 0x010b1);

    // config DISP0_DAT16 pad for ipu1 instance DISP0_DAT[16] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT16, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT16, 0x010b1);

    // config DISP0_DAT17 pad for ipu1 instance DISP0_DAT[17] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT17, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT17, 0x010b1);

    // config DISP0_DAT18 pad for ipu1 instance DISP0_DAT[18] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT18, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT18, 0x010b1);

    // config DISP0_DAT19 pad for ipu1 instance DISP0_DAT[19] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT19, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT19, 0x010b1);

    // config DISP0_DAT20 pad for ipu1 instance DISP0_DAT[20] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20, 0x010b1);

    // config DISP0_DAT21 pad for ipu1 instance DISP0_DAT[21] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21, 0x010b1);

    // config DISP0_DAT22 pad for ipu1 instance DISP0_DAT[22] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22, 0x010b1);

    // config DISP0_DAT23 pad for ipu1 instance DISP0_DAT[23] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23, 0x010b1);

    // config EIM_D16 pad for ipu1 instance DI0_PIN5 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D16, ALT2);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D16, 0x000b1);

    // config EIM_D17 pad for ipu1 instance DI0_PIN6 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D17, ALT2);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D17, 0x000b1);

    // config EIM_D18 pad for ipu1 instance DI0_PIN7 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D18, ALT2);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D18, 0x000b1);

    // config EIM_D19 pad for ipu1 instance DI0_PIN8 port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D19, ALT2);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D19, 0x000b1);
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

        /* CMD */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_CMD);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_CMD);

        /* CLK */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_CLK);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_CLK);

        /* DATA0 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0);

        /* DATA1 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1);

        /* DATA2 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2);

        /* DATA3 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3);

        /* DATA4 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT4);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT4);

        /* DATA5 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT5);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT5);

        /* DATA6 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT6);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT6);

        /* DATA7 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT7);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT7);
        break;

    case USDHC4_BASE_ADDR:

        /* CMD */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_CMD);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_CMD);

        /* CLK */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_CLK);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_CLK);

        /* DATA0 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT0);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT0);

        /* DATA1 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT1);

        /* DATA2 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2);

        /* DATA3 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT3);

        /* DATA4 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT4);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT4);

        /* DATA5 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT5);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT5);

        /* DATA6 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT6);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT6);

        /* DATA7 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT7);
        writel(0x70F0, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT7);
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
#ifdef MX61_ARD
    /* Select ALT2 mode of FEC_REF_CLK for ESAI1_FSR */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_FSR_SELECT_INPUT);

    /* Select ALT2 mode of FEC_RXD1 for ESAI1_FST */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_RXD1);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_FST_SELECT_INPUT);

    /* Select ALT2 mode of FEC_RXD0 for ESAI1_HCKT */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_RXD0);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_HCKT_SELECT_INPUT);

    /* Select ALT2 mode of FEC_MDIO for ESAI1_SCKR */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_MDIO);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SCKR_SELECT_INPUT);

    /* Select ALT2 mode of FEC_CRS_DV for ESAI1_SCKT */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SCKT_SELECT_INPUT);

    /* Select ALT2 mode of NANDF_CS2 for ESAI1_TX0 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    writel(0x1, IOMUXC_ESAI1_IPP_IND_SDO0_SELECT_INPUT);    //daisy chain

    /* Select ALT2 mode of NANDF_CS2 for ESAI1_TX1 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    writel(0x1, IOMUXC_ESAI1_IPP_IND_SDO1_SELECT_INPUT);    //daisy chain

    /* Select ALT0 mode of GPIO_5 for ESAI1_TX2_RX3 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_TXD1);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO2_SDI3_SELECT_INPUT);

    /* Select ALT2 mode of FEC_TXEN for ESAI1_TX3_RX2 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_TX_EN);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO3_SDI2_SELECT_INPUT);

    /* Select ALT2 mode of FEC_TXD0 for ESAI1_TX4_RX1 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_TXD0);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO4_SDI1_SELECT_INPUT);
    /* Select ALT0 mode of ENET_TXD0 for ESAI1_TX5_RX0 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_MDC);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO5_SDI0_SELECT_INPUT);
#else
    /* Select ALT2 mode of FEC_RXD0 for ESAI1_HCKT */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_RXD0);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_HCKT_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_RXD0);    // default at reset

    /* Select ALT2 mode of FEC_RXD1 for ESAI1_FST */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_RXD1);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_FST_SELECT_INPUT); //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_RXD1);    // default at reset

    /* Select ALT2 mode of FEC_TXEN for ESAI1_TX3_RX2 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_TX_EN);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO3_SDI2_SELECT_INPUT);   //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_TX_EN);   // default at reset

    /* Select ALT2 mode of FEC_TXD0 for ESAI1_TX4_RX1 */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_TXD0);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO4_SDI1_SELECT_INPUT);   //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_TXD0);    // default at reset

    /* Select ALT2 mode of FEC_MDIO for ESAI1_SCKR */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_MDIO);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SCKR_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_MDIO);    // default at reset

    /* Select ALT2 mode of FEC_REF_CLK for ESAI1_FSR */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_REF_CLK);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_FSR_SELECT_INPUT); //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_REF_CLK); // default at reset

    /* Select ALT0 mode of GPIO_8 for ESAI1_TX5_RX0 */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_GPIO_8);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO5_SDI0_SELECT_INPUT);   //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_8);  // default at reset

    /* Select ALT0 mode of GPIO_5 for ESAI1_TX2_RX3 */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_GPIO_5);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO2_SDI3_SELECT_INPUT);   //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_5);  // default at reset
    /* Select ALT2 mode of FEC_CRS_DV for ESAI1_SCKT */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_FEC_CRS_DV);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SCKT_SELECT_INPUT);    //daisy chain

    /* Select ALT3 mode of NANDF_CS2 for ESAI1_TX0 */
    if (BOARD_ID_MX61_ARD == board_id) {
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    } else {
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    }
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO0_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2);   // default at reset

    /* Select ALT3 mode of NANDF_CS3 for ESAI1_TX1 */
    if (BOARD_ID_MX61_ARD == board_id) {
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    } else {
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    }
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO1_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3);   // default at reset

    if (BOARD_ID_MX61_ARD == board_id) {
        /* Select ALT2 mode of ENET_RX_ER for GPIO - ESAI_HCKR */
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER);
        writel(0x0, IOMUXC_ESAI1_IPP_IND_HCKR_SELECT_INPUT);    //daisy chain
    } else {
        /* Select ALT1 mode of PATA_DATA4 for GPIO2_0 -ESAI_INT */
        /* active high input */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4);
    }
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4);
    gpio_dir_config(GPIO_PORT2, 0, GPIO_GDIR_INPUT);

#endif
}

void esai_clk_sel_gate_on()
{
    uint32_t val = 0;
#ifdef MX61_ARD
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
