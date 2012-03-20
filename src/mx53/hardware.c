/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

extern void AUDMUXRoute(int32_t intPort, int32_t extPort, int32_t Master);  // defined in ssi.c driver
extern uint8_t da9053_i2c_reg(uint32_t reg, uint8_t val, uint32_t dir);
extern int32_t board_id;
extern sata_phy_ref_clk_t sata_phy_clk_sel;

#define ON 1
#define OFF 0

// ARM core.
#define DUMMY_ARM_CORE_BASE_ADDR 0x12345789
hw_module_t arm_core = {
    "Cortex A9 core",
    1,
    DUMMY_ARM_CORE_BASE_ADDR,
    800000000,
};

// UART1 is the serial debug/console port
hw_module_t g_debug_uart = {
    "UART1 for debug",
    1,
    UART1_BASE_ADDR,
    27000000,
    IMX_INT_UART1,
    &default_interrupt_routine,
};

/* EPIT1 used for system time functions */
hw_module_t g_system_timer = {
    "EPIT1 used as system timer",
    1,
    EPIT1_BASE_ADDR,
    27000000,
    IMX_INT_EPIT1,
    &default_interrupt_routine,
};

hw_module_t ddr = {
    "DDR",
    1,
    ESDCTL_REGISTERS_BASE_ADDR,
};

hw_module_t *mx53_module[] = {
    &arm_core,
    &ddr,
    &g_debug_uart,
    &g_system_timer,
    NULL,
};

uint32_t ipu_hw_instance[4] = {
    0, 0, 0, 0
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

struct soc_sbmr {
    uint32_t bt_mmu_enable:1,
        bt_freq:1,
        boot_cfg1:6,
        hab_type:2,
        boot_cfg2:6, dir_bt_dis:1, boot_cfg3:7, bmod:2, bt_fuse_sel:1, test_mode:3, rsv0:2;
} __attribute__ ((packed));
struct soc_sbmr *soc_sbmr = (struct soc_sbmr *)(SRC_BASE_ADDR + 0x4);

/*!
 * Retrieve the freq info based on the passed in module_base.
 * @param   module_base     the base address of the module
 * @return  frequency in hz (0 means not a valid module)
 */
uint32_t get_freq(uint32_t module_base)
{
    if (module_base == DUMMY_ARM_CORE_BASE_ADDR)
        return get_main_clock(CPU_CLK);
    else if (module_base == ESDCTL_REGISTERS_BASE_ADDR)
        return get_main_clock(DDR_CLK);
    else if (module_base == g_debug_uart.base)
        return get_peri_clock(UART1_BAUD);
    else if (module_base == g_system_timer.base)
//        return get_peri_clock(EPIT1_CLK); // this clock is not necessary the source used by the counter
        return g_system_timer.freq;
    else {
        printf("Not a valid module base \n");
        return 0;
    }
}

/*!
 * Retrieve the clocks based on the hardware configuration and fill in the freq
 * info in each module's structure.
 */
void freq_populate(void)
{
    hw_module_t *tmp;
    int32_t i;

    for (i = 0; (tmp = mx53_module[i]) != NULL; i++) {
        tmp->freq = get_freq(tmp->base);
    }
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int32_t i;
    hw_module_t *tmp;
    printf("========== clock frequencies(HZ)\n");

    for (i = 0; (tmp = mx53_module[i]) != NULL; i++) {
        printf("%s\t: %d,%03d,%03d\n", tmp->name, tmp->freq / 1000000,
               (tmp->freq % 1000000) / 1000, tmp->freq % 1000);
    }

    printf("==================================\n\n");
}

/*!
 * Display the board's DDR configuration
 */
void show_ddr_config(void)
{
    uint32_t temp1, dsiz, row, col, cs_info;
    uint32_t temp2, num_banks, ddr_type;
    uint32_t density;
    uint32_t megabyte;
    uint32_t num_rows = 1, num_cols = 1, i = 1;
    printf("========== DDR configuration \n");
    megabyte = 1024 * 1024;
    /* read ESDCTL and gather information */
    temp1 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x00);
    dsiz = ((temp1 & (0x00010000)) >> 16) * 16 + 16;
    row = ((temp1 & (0x07000000)) >> 24) + 11;
    col = ((temp1 & (0x00300000)) >> 20) + 9;
    cs_info = (temp1 & (0xC0000000)) >> 30;
    /* read ESDMISC to get # of BANK info */
    temp2 = readl(ESDCTL_REGISTERS_BASE_ADDR + 0x18);
    num_banks = (!((temp2 & (0x00000020)) >> 5)) * 4 + 4;
    ddr_type = (temp2 & (0x00000010)) >> 4;
    printf("data bits: %d, num_banks: %d \n", dsiz, num_banks);
    printf("row: %d, col: %d \n", row, col);

    if (ddr_type == 1)
        printf("DDR type is DDR2 \n");
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
    printf("==================================\n\n");
}

/*! Enable or disable the SPI NOR on ARD only
 *   Note, ARD SPI NOR signals are mux'd with WEIM data bus
 *   Hence, the SPI NOR needs to be disabled (tri-stated) or enabled
 *   depending on desired usage.
 *
 * @param   en_dis enable or disable spi nor by setting GPIo control to low or high
 */
void ard_spi_nor_control(uint32_t en_dis)
{
    // set DI0_PIN2 mux control for GPIO4_18 usage
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2);
    // configure GPIO4_18 as output
    gpio_dir_config(4, 18, GPIO_GDIR_OUTPUT);   // port=4, pin=18, dir=output
    // write GPIO4_18 as low (enable spi nor) or high (disable spi nor)
    gpio_write_data(4, 18, en_dis); // port=4, pin=18, en_dis (low or high)
}

/*!
  * Set up the IOMUX for SPI
  */
void io_cfg_spi(struct imx_spi_dev *dev)
{
    switch (dev->base) {
    case ECSPI1_BASE_ADDR:

        if (BOARD_TYPE_ID == BOARD_ID_MX53_ARD) {
            ard_spi_nor_control(0); // by setting to 0, this enables the spi nor
        }
        // MOSI
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
        writel(0x104, IOMUXC_SW_PAD_CTL_PAD_EIM_D18);
        writel(0x3, IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT);

        // MISO
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
        writel(0x104, IOMUXC_SW_PAD_CTL_PAD_EIM_D17);
        writel(0x3, IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT);

        if (dev->ss == 0) {
            // de-select SS1
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
            writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
            // Select mux mode: ALT4 for SS0
            writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_EB2);
            writel(0x104, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);
            writel(0x3, IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT);
        } else if (dev->ss == 1) {
            // de-select SS0
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_EB2);
            writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);
            // Select mux mode: ALT4 for SS1
            writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
            writel(0x104, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
            writel(0x2, IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT);
        }
        // SCLK
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D16);
        writel(0x104, IOMUXC_SW_PAD_CTL_PAD_EIM_D16);
        writel(0x3, IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT);

        break;
    case ECSPI2_BASE_ADDR:
    default:
        break;
    }
}

/*!
  * Set up the IOMUX for NAND
  */
void io_cfg_nand(void)
{
    volatile uint32_t reg;
    // Set NAND data pins to be MUXed over the WEIM bus
    writel(0x0, M4IF_REGISTERS_BASE_ADDR + 0xC);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x4);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x4);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x1C);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x1C);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x34);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x34);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x4C);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x4C);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x64);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x64);
    reg = readl(WEIM_REGISTERS_BASE_ADDR + 0x7C);
    reg &= ~(1 << 12);
    writel(reg, WEIM_REGISTERS_BASE_ADDR + 0x7C);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE);
    writel(0x4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE);
    writel(0x4, IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B);
    writel(0xe4, IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_WE_B);
    writel(0x4, IOMUXC_SW_PAD_CTL_PAD_NANDF_WE_B);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_RE_B);
    writel(0x4, IOMUXC_SW_PAD_CTL_PAD_NANDF_RE_B);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0);
    writel(0xe0, IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0);
    writel(0x4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA0);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA1);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA1);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA2);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA2);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA3);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA3);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA4);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA4);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA5);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA5);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA6);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA6);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA7);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA7);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA8);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA8);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA9);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA9);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA10);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA10);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA11);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA11);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA12);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA12);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA13);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA13);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA14);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA14);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA15);
    writel(0xa4, IOMUXC_SW_PAD_CTL_PAD_EIM_DA15);
}

/*!
  * Set up the IOMUX for I2C
  */
void i2c_iomux_config(uint32_t module_base)
{
    switch (module_base) {
    case I2C1_BASE_ADDR:
        if (BOARD_TYPE_ID != BOARD_ID_MX53_ARD) {
            /* I2C1 mux'd out on CSI0_DAT8 and CSI0_DAT9 pads */
            /* I2C1_SDA ALT5 on CSI0_DAT8 IOMUX setup */
            writel(0x10 | ALT5, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT8);
            /* I2C1_SDA is involved in the Daisy Chain */
            writel(0x0, IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT);
            writel(0x1EC, IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT8);
            /* I2C1_SCL ALT5 on CSI0_DAT8 IOMUX setup */
            writel(0x10 | ALT5, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT9);
            /* I2C1_SCL is involved in the Daisy Chain */
            writel(0x0, IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT);
            writel(0x1EC, IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT9);
        } else {
            /* I2C1 not used on the i.MX53 ARD */
            printf("I2C1 not supported on the i.MX53 ARD \n");
        }

        break;

    case I2C2_BASE_ADDR:
        if (BOARD_TYPE_ID != BOARD_ID_MX53_ARD) {
            /* On the EVK I2C2 is mux'd on the KEY_COL3 and KEY_ROW3 signals */
            /* Select ALT4 mode for KEY_COL3 for I2C2 SCL */
            writel(0x10 | ALT4, IOMUXC_SW_MUX_CTL_PAD_KEY_COL3);    // ALT4 and SION bit set
            /* I2C2 SCL is involved in the Daisy Chain */
            writel(0x0, IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT);   // select KEY_COL3 for I2C SCL input
            writel(0x1EC, IOMUXC_SW_PAD_CTL_PAD_KEY_COL3);  /* KEY_COL3/I2C2_CLK */
            hal_delay_us(1000);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_KEY_COL3);  /* KEY_COL3/I2C2_CLK */
        } else {
            /* On the ARD I2C2 is mux'd on the EIM_EB2 and KEY_ROW3 signals */
            /* Select ALT5 mode of EIM_EB2 for I2C2 SCL */
            writel(0x10 | ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB2); // ALT5 and SION bit set
            /* I2C2 SCL is involved in the Daisy Chain */
            writel(0x1, IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT);   // select EIM_EB2 for I2C SCL input
//        writel(0x1EC, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);    /* EIM_EB2/I2C2_CLK */
//        hal_delay_us(1000);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);   /* EIM_EB2/I2C2_CLK */
        }

        /* Select ALT4 mode for KEY_ROW3 for I2C2 SDA */
        writel(0x10 | ALT4, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3);    // ALT4 and SION bit set
        /* I2C2 SDA is involved in the Daisy Chain */
        writel(0x0, IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT);   // select KEY_ROW3 for I2C SDA input
        writel(0x1EC, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3);  /* KEY_ROW3/I2C2_DAT */
        hal_delay_us(1000);
        writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3);  /* KEY_ROW3/I2C2_DAT */
        break;

    case I2C3_BASE_ADDR:
        if (BOARD_TYPE_ID == BOARD_ID_MX53_ARD) {
            /* On the ARD I2C3 is mux'd on the GPIO_3 and GPIO_16 signals */
            /* Select ALT2 mode of GPIO_3 for I2C3 SCL */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_GPIO_3);  // ALT2 and SION bit set
            /* I2C3 SCL is involved in the Daisy Chain */
            writel(0x1, IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_GPIO_3);
            /* Select ALT6 mode of GPIO_16 for I2C3 SDA */
            writel(0x10 | ALT6, IOMUXC_SW_MUX_CTL_PAD_GPIO_16); // ALT6 and SION bit set
            /* I2C3 SDA is involved in the Daisy Chain */
            writel(0x2, IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_GPIO_16);
        } else if (BOARD_TYPE_ID == BOARD_ID_MX53_SMD) {
            /* On the ARD I2C3 is mux'd on the GPIO_3 and GPIO_16 signals */
            /* Select ALT2 mode of GPIO_3 for I2C3 SCL */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_GPIO_3);  // ALT2 and SION bit set
            /* I2C3 SCL is involved in the Daisy Chain */
            writel(0x1, IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_GPIO_3);
            /* Select ALT6 mode of GPIO_6 for I2C3 SDA */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_GPIO_6);  // ALT2 and SION bit set
            /* I2C3 SDA is involved in the Daisy Chain */
            writel(0x1, IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT);
            writel(0x16C, IOMUXC_SW_PAD_CTL_PAD_GPIO_6);
        } else {
            /* I2C1 not used on other hardware */
            printf("I2C1 not supported for this hardware \n");
        }
        break;
    default:
        break;
    }
}

/* Power up the SGTL and initialize it's clock if necessary */
void SGTL5000PowerUp_and_clockinit(void)
{
    uint32_t val = 0;

    if (board_id == BOARD_ID_MX53_SMD) {
        /* Enable NANDF_CS0 to turn on the audio oscillator */
        writel(0x1, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0);   //GPI0[11] of GPIO6
        val = readl(GPIO6_BASE_ADDR + 0x04);
        val |= (0x1 << 11);
        writel(val, GPIO6_BASE_ADDR + 0x04);    // data direction register, set to output
        val = readl(GPIO6_BASE_ADDR + 0x00);
        val |= (0x1 << 11);
        writel(val, GPIO6_BASE_ADDR + 0x00);    // data register (output 1)
        /*Un-standby the audio amplier TS4984 */
        writel(0x1, IOMUXC_SW_MUX_CTL_PAD_EIM_DA2); //GPI0[2] of GPIO3
        val = readl(GPIO3_BASE_ADDR + 0x04);
        val |= (0x1 << 2);
        writel(val, GPIO3_BASE_ADDR + 0x04);    // data direction register, set to output
        val = readl(GPIO3_BASE_ADDR + 0x00);
        val |= (0x1 << 2);
        writel(val, GPIO3_BASE_ADDR + 0x00);    // data register (output 1)

    } else {
        /* Enable GPIO_2 to turn on the audio oscillator */
        writel(0x1, IOMUXC_SW_MUX_CTL_PAD_GPIO_2);
        writel(0x4, GPIO1_BASE_ADDR + 0x04);    // data direction register, set to output
        writel(0x4, GPIO1_BASE_ADDR + 0x00);    // data register (output 1)
    }

    // CLKO->mclk
    writel(0x0, IOMUXC_BASE_ADDR + 0x314);
    writel(0x1F4, IOMUXC_BASE_ADDR + 0x6A4);

    // Set CLKO1(CLKO)
    // Source from pll3
    val = readl(CCM_BASE_ADDR + 0x60);
    val &= ~0xff;
    val |= (0x1 << 7) | (0x1 << 4) | (0x8); // di is 216MHz, div 2
//    val |= (0x1 << 7) | (0x7 << 4) | (0x3); // Pll3 is 216MHz, div 8
    writel(val, CCM_BASE_ADDR + 0x60);
}

/* Configure iomux for AUDMUX output */
void audmux_iomux_config(void)
{
    /* Select ALT2 mode of KEY_ROW1 for AUD5_RXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT);    //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1);
    /* Select ALT2 mode of KEY_ROW0 for AUD5_TXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT);    //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0);
    /* Select ALT2 mode of KEY_COL0 for AUD5_TXC */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_COL0);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT); //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_COL0);
    /* Select ALT2 mode of KEY_COL1 for AUD5_TXFS */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_COL1);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT);  //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_COL1);
}

/* Configure iomux for ESAI */
void esai_iomux_config(void)
{
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
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_FEC_CRS_DV);  // default at reset
    /* Select ALT3 mode of NANDF_CS2 for ESAI1_TX0 */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO0_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2);   // default at reset
    /* Select ALT3 mode of NANDF_CS3 for ESAI1_TX1 */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    writel(0x0, IOMUXC_ESAI1_IPP_IND_SDO1_SELECT_INPUT);    //daisy chain
//    writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3);   // default at reset
    /* Select ALT1 mode of PATA_DATA4 for GPIO2_0 -ESAI_INT */
    /* active high input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4);
    gpio_dir_config(GPIO_PORT2, 0, GPIO_GDIR_INPUT);
}

/*USB_OTG_PWR and OC iomux configurations*/
void usb_io_config(void)
{
    if ((board_id != BOARD_ID_MX53_SMD)
        && (board_id != BOARD_ID_MX53_LCB)) {
        /* Select ALT1 mode of EIM_A25 for GPIO5_2 - USB_OTG_PWR */
        /* active high output */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_A25);
        gpio_dir_config(GPIO_PORT5, 2, GPIO_GDIR_OUTPUT);
        gpio_write_data(GPIO_PORT5, 2, GPIO_LOW_LEVEL);
        /* Select ALT1 mode of EIM_A24 for GPIO5_4 - USB_OTG_OC */
        /* active low input */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
//      writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_EIM_A24);   // default at reset
        gpio_dir_config(GPIO_PORT5, 4, GPIO_GDIR_INPUT);
    } else {
        /* Select ALT1 mode of PATA_DA_2 for GPIO7_8 - USB_OTG_PWR_EN */
        /* active high output. it is enabled in usb_vbus_power_on() later */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DA_2);
        gpio_dir_config(GPIO_PORT7, 8, GPIO_GDIR_OUTPUT);
        gpio_write_data(GPIO_PORT7, 8, GPIO_LOW_LEVEL);
        /* Select ALT1 mode of EIM_DA12 for GPIO3_12 - USB_OTG_OC */
        /* active low input */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_DA12);
        gpio_dir_config(GPIO_PORT3, 12, GPIO_GDIR_INPUT);
    }

    if ((board_id != BOARD_ID_MX53_SMD)
        && (board_id != BOARD_ID_MX53_LCB)) {
        /* USB HOST1 iomux configuration for USB_H1_OC */
        /* Select ALT0 mode of GPIO_11 for GPIO4_1 - USB_H1_OC_B */
        /* active low input */
        writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_GPIO_11);
        gpio_dir_config(GPIO_PORT4, 1, GPIO_GDIR_INPUT);
        /* _TO_DO_ : set trigger mode for this IRQ */

        /* USB host2 iomux configuration */
        /* Select ALT1 mode of KEY_COL4 for GPIO4_14 - USB_H2_PHY_RST_B */
        /* active low output */
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_KEY_COL4);
        gpio_dir_config(GPIO_PORT4, 14, GPIO_GDIR_OUTPUT);
        /* keep PHY in reset during I/O init */
        gpio_write_data(GPIO_PORT4, 14, GPIO_LOW_LEVEL);
        hal_delay_us(10);

        /* Select ALT3 mode of DISP0_DAT0 for USBH2_DATA[0] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT0);
        /* Select ALT3 mode of DISP0_DAT1 for USBH2_DATA[1] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT1);
        /* Select ALT3 mode of DISP0_DAT2 for USBH2_DATA[2] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT2);
        /* Select ALT3 mode of DISP0_DAT3 for USBH2_DATA[3] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT3);
        /* Select ALT3 mode of DISP0_DAT4 for USBH2_DATA[4] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT4);
        /* Select ALT3 mode of DISP0_DAT5 for USBH2_DATA[5] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT5);
        /* Select ALT3 mode of DISP0_DAT6 for USBH2_DATA[6] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT6);
        /* Select ALT3 mode of DISP0_DAT7 for USBH2_DATA[7] */
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT7);
        /* Select ALT2 mode of DISP0_DAT11 for USBH2_NXT */
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT11);
        /* Select ALT2 mode of DISP0_DAT12 for USBH2_CLK */
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT12);
        /* Select ALT2 mode of DI0_DISP_CLK for USBH2_DIR */
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_DI0_DISP_CLK);
        /* Select ALT2 mode of DISP0_DAT10 for USBH2_STP */
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT10);
        /* Select ALT0 mode of GPIO_12 for GPIO4_2 - USB_H2_OC_B */
        /* active low input */
        writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_GPIO_12);
        gpio_dir_config(GPIO_PORT4, 2, GPIO_GDIR_INPUT);
        /* _TO_DO_ : set trigger mode for this IRQ */

        /* set PHY out of reset */
        gpio_write_data(GPIO_PORT4, 14, GPIO_HIGH_LEVEL);
    }
}

/*ldb iomux configurations*/
void ldb_iomux_config(void)
{
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS0_TX0_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS0_TX1_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS0_TX2_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS0_CLK_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS0_TX3_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS1_TX0_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS1_TX1_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS1_CLK_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS1_TX2_P);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_LVDS1_TX3_P);
}

/*tve output iomux config*/
void vga_tve_iomux_config(void)
{
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_OE);
    writel(0xC2, IOMUXC_SW_PAD_CTL_PAD_EIM_OE);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_RW);
    writel(0xC2, IOMUXC_SW_PAD_CTL_PAD_EIM_RW);
    /*enable di1 output */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA9);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA8);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA7);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA6);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA5);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA4);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA3);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA2);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA1);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA0);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_EB1);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_EB0);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A17);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A18);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A19);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A20);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A21);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A22);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A23);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_D31);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_D30);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_D26);
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_D27);
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_EIM_A16);    // disp clk
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA11);   // vsync
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA12);   // hsync
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_EIM_DA10);   // drdy
}

/*!
function:
	ipu_iomux_config()
description:
	configure the iomux pins for ipu display interface 0
params:
	null
return:
	null
 */
void ipu_iomux_config(void)
{
    // configure display0 data0~23 for parallel panel for mx53 evk board
    writel(0x0, IOMUXC_BASE_ADDR + 0x4c);   // di0 display clock
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0378);
    writel(0x0, IOMUXC_BASE_ADDR + 0x50);   // di0 pin15, for DRDY
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x037c);
    writel(0x0, IOMUXC_BASE_ADDR + 0x54);   // di0 pin2, for HSYNC
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0380);
    writel(0x0, IOMUXC_BASE_ADDR + 0x58);   // di0 pin3, for VSYNC
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0384);
    writel(0x0, IOMUXC_BASE_ADDR + 0x60);   // di0 data0
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x038c);
    writel(0x0, IOMUXC_BASE_ADDR + 0x64);   // di0 data1
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0390);
    writel(0x0, IOMUXC_BASE_ADDR + 0x68);   // di0 data2
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0394);
    writel(0x0, IOMUXC_BASE_ADDR + 0x6c);   // di0 data3
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x0398);
    writel(0x0, IOMUXC_BASE_ADDR + 0x70);   // di0 data4
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x039c);
    writel(0x0, IOMUXC_BASE_ADDR + 0x74);   // di0 data5
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03a0);
    writel(0x0, IOMUXC_BASE_ADDR + 0x78);   // di0 data6
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03a4);
    writel(0x0, IOMUXC_BASE_ADDR + 0x7c);   // di0 data7
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03a8);
    writel(0x0, IOMUXC_BASE_ADDR + 0x80);   // di0 data8
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03ac);
    writel(0x0, IOMUXC_BASE_ADDR + 0x84);   // di0 data9
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03b0);
    writel(0x0, IOMUXC_BASE_ADDR + 0x88);   // di0 data10
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03b4);
    writel(0x0, IOMUXC_BASE_ADDR + 0x8c);   // di0 data11
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03b8);
    writel(0x0, IOMUXC_BASE_ADDR + 0x90);   // di0 data12
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03bc);
    writel(0x0, IOMUXC_BASE_ADDR + 0x94);   // di0 data13
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03c0);
    writel(0x0, IOMUXC_BASE_ADDR + 0x98);   // di0 data14
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03c4);
    writel(0x0, IOMUXC_BASE_ADDR + 0x9c);   // di0 data15
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03c8);
    writel(0x0, IOMUXC_BASE_ADDR + 0xa0);   // di0 data16
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03cc);
    writel(0x0, IOMUXC_BASE_ADDR + 0xa4);   // di0 data17
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03d0);
    writel(0x0, IOMUXC_BASE_ADDR + 0xa8);   // di0 data18
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03d4);
    writel(0x0, IOMUXC_BASE_ADDR + 0xac);   // di0 data19
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03d8);
    writel(0x0, IOMUXC_BASE_ADDR + 0xb0);   // di0 data20
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03dc);
    writel(0x0, IOMUXC_BASE_ADDR + 0xb4);   // di0 data21
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03e0);
    writel(0x0, IOMUXC_BASE_ADDR + 0xb8);   // di0 data22
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03e4);
    writel(0x0, IOMUXC_BASE_ADDR + 0xbc);   // di0 data23
    writel(0x5E5, IOMUXC_BASE_ADDR + 0x03e8);
}

/* FEC iomux config */
// setup iomux, power and clock for FEC
void imx_fec_setup(void)
{
    /*FEC_MDIO */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_MDIO);
    writel(0x1FC, IOMUXC_SW_PAD_CTL_PAD_FEC_MDIO);
    writel(0x1, IOMUXC_FEC_FEC_MDI_SELECT_INPUT);
    /*FEC_MDC */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_MDC);
    writel(0x0004, IOMUXC_SW_PAD_CTL_PAD_FEC_MDC);
    /* FEC RDATA[1] */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_RXD1);
    writel(0x180, IOMUXC_SW_PAD_CTL_PAD_FEC_RXD1);
    /* FEC RDATA[0] */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_RXD0);
    writel(0x180, IOMUXC_SW_PAD_CTL_PAD_FEC_RXD0);
    /* FEC TDATA[1] */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_TXD1);
    writel(0x0004, IOMUXC_SW_PAD_CTL_PAD_FEC_TXD1);
    /* FEC TDATA[0] */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_TXD0);
    writel(0x0004, IOMUXC_SW_PAD_CTL_PAD_FEC_TXD0);
    /* FEC TX_EN */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_TX_EN);
    writel(0x0004, IOMUXC_SW_PAD_CTL_PAD_FEC_TX_EN);
    /* FEC TX_CLK */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_REF_CLK);
    writel(0x180, IOMUXC_SW_PAD_CTL_PAD_FEC_REF_CLK);
    /* FEC RX_ER */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_RX_ER);
    writel(0x180, IOMUXC_SW_PAD_CTL_PAD_FEC_RX_ER);
    /* FEC CRS */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_FEC_CRS_DV);
    writel(0x180, IOMUXC_SW_PAD_CTL_PAD_FEC_CRS_DV);
}

void lvds_power_on(void)
{
    printf("Backlight Enabled for the Panel\n");
    /* Enable backlight to the panel, mux'd on GPIO_1 */
    writel(0x1, IOMUXC_SW_MUX_CTL_PAD_GPIO_1);
    writel(0x1c4, IOMUXC_SW_PAD_CTL_PAD_GPIO_1);
    /* Configure GPIO1_1 as an output high */
    gpio_dir_config(GPIO_PORT1, 1, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 1, 1);
}

void esai_codec_power_on(void)
{
    /*TO avoid build error for mx53 */
}

void esai_clk_sel_gate_on(void)
{
    /*TO avoid build error for mx53 */
}

void debug_uart_iomux(void)
{
    if (BOARD_TYPE_ID != BOARD_ID_MX53_ARD) {
        // UART1 mux'd on CSI0_DAT10 and CSI0_DAT11
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT10);
        writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT11);
        // daisy chain setup
        writel(0x1, IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    } else {
        // UART1 mux'd on PATA_DIOW<=>TXD and PATA_DMACK<=>RXD
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DIOW);
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DMACK);
        // daisy chain setup
        writel(0x3, IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
    }
}

/*!
 * That function calls the board dependent IOMUX configuration functions
 */
void uart_iomux_config(uint32_t module_base_add)
{
    switch (module_base_add) {
    case UART1_BASE_ADDR:
        debug_uart_iomux();
        break;
    default:
        break;
    }
}


/* eCSPI1 iomux - connecting SPI NOR through SS1*/
// Function to config instance ecspi1 of Module ECSPI to Protocol MASTER
// This protocol has next ports:
//  SCLK MOSI SS0 SS1 SS2 SS3 MISO RDY
void ecspi1_master_pgm_iomux(void)
{
    // config EIM_D19 pad for ecspi1 instance SS1 port
    // config_pad_mode(EIM_D19, ALT4);
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
    // Pad DISP0_DAT15 is involved in Daisy Chain.
    writel(0x2, IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT);
    // CONSTANT SETTINGS:
    // test_ts to Disabled
    // dse test to regular
    // strength mode to 4_LEVEL
    // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
    // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
    // CONFIGURED SETTINGS:
    // Hyst. Enable to Enabled (Binary: 1)
    // Pull / Keep Enable to Disabled (Binary: 0)
    // Open Drain Enable to Disabled (Binary: 0)
    // Drive Strength to CFG(High) (Binary: 10)
    // config_pad_settings(EIM_D19, 0x0104);
    writel(0x0104, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
    // config EIM_D16 pad for ecspi1 instance SCLK port
    // config_pad_mode(EIM_D19, ALT4);
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D16);
    // Pad EIM_D16 is involved in Daisy Chain.
    writel(0x3, IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT);
    // CONSTANT SETTINGS:
    // test_ts to Disabled
    // dse test to regular
    // strength mode to 4_LEVEL
    // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
    // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
    // CONFIGURED SETTINGS:
    // Hyst. Enable to Enabled (Binary: 1)
    // Pull / Keep Enable to Disabled (Binary: 0)
    // Open Drain Enable to Disabled (Binary: 0)
    // Drive Strength to CFG(High) (Binary: 10)
    // config_pad_settings(EIM_D16, 0x0104);
    writel(0x0104, IOMUXC_SW_PAD_CTL_PAD_EIM_D16);
    // config EIM_D18 pad for ecspi1 instance MOSI port
    // config_pad_mode(EIM_D18, ALT4);
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
    // Pad EIM_D18 is involved in Daisy Chain.
    writel(0x3, IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT);
    // CONSTANT SETTINGS:
    // test_ts to Disabled
    // dse test to regular
    // strength mode to 4_LEVEL
    // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
    // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
    // CONFIGURED SETTINGS:
    // Hyst. Enable to Enabled (Binary: 1)
    // Pull / Keep Enable to Disabled (Binary: 0)
    // Open Drain Enable to Disabled (Binary: 0)
    // Drive Strength to CFG(High) (Binary: 10)
    // config_pad_settings(EIM_D18, 0x0104);
    writel(0x0104, IOMUXC_SW_PAD_CTL_PAD_EIM_D18);
    // config EIM_D17 pad for ecspi1 instance MISO port
    // config_pad_mode(EIM_D17, ALT4);
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
    // EIM_D17 is involved in Daisy Chain.
    writel(0x3, IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT);
    // CONSTANT SETTINGS:
    // test_ts to Disabled
    // dse test to regular
    // strength mode to 4_LEVEL
    // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
    // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
    // CONFIGURED SETTINGS:
    // Hyst. Enable to Enabled (Binary: 1)
    // Pull / Keep Enable to Disabled (Binary: 0)
    // Open Drain Enable to Disabled (Binary: 0)
    // Drive Strength to CFG(High) (Binary: 10)
    // config_pad_settings(EIM_D17, 0x0104);
    writel(0x0104, IOMUXC_SW_PAD_CTL_PAD_EIM_D17);
    /*
       // config DISP0_DAT23 pad for ecspi1 instance SS0 port
       // config_pad_mode(DISP0_DAT23, ALT2);
       reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23, ALT2);
       // Pad DISP0_DAT23 is involved in Daisy Chain.
       reg32_write(IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT, 0x1);
       // CONSTANT SETTINGS:
       // test_ts to Disabled
       // dse test to regular
       // strength mode to 4_LEVEL
       // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
       // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
       // CONFIGURED SETTINGS:
       // Hyst. Enable to Enabled (Binary: 1)
       // Pull / Keep Enable to Disabled (Binary: 0)
       // Open Drain Enable to Disabled (Binary: 0)
       // Drive Strength to CFG(High) (Binary: 10)
       // Slew Rate to CFG(FAST) (Binary: 1)
       // config_pad_settings(DISP0_DAT23, 0x0105);
       reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23, 0x0105);

       // config EIM_D24 pad for ecspi1 instance SS2 port
       // config_pad_mode(EIM_D24, ALT3);
       reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D24, ALT3);
       // Pad EIM_D24 is involved in Daisy Chain.
       reg32_write(IOMUXC_ECSPI1_IPP_IND_SS_B_2_SELECT_INPUT, 0x1);
       // CONSTANT SETTINGS:
       // low/high output voltage to NA
       // test_ts to Disabled
       // dse test to regular
       // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
       // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
       // CONFIGURED SETTINGS:
       // Hyst. Enable to Enabled (Binary: 1)
       // Pull / Keep Enable to Disabled (Binary: 0)
       // Open Drain Enable to Disabled (Binary: 0)
       // Drive Strength to CFG(High) (Binary: 10)
       // config_pad_settings(EIM_D24, 0x0104);
       reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D24, 0x0104);

       // config EIM_D25 pad for ecspi1 instance SS3 port
       // config_pad_mode(EIM_D25, ALT3);
       reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D25, ALT3);
       // Pad EIM_D25 is involved in Daisy Chain.
       reg32_write(IOMUXC_ECSPI1_IPP_IND_SS_B_3_SELECT_INPUT, 0x1);
       // CONSTANT SETTINGS:
       // low/high output voltage to NA
       // test_ts to Disabled
       // dse test to regular
       // Pull / Keep Select to NA (CFG in SoC Level however NA in Module Level)
       // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
       // CONFIGURED SETTINGS:
       // Hyst. Enable to Enabled (Binary: 1)
       // Pull / Keep Enable to Disabled (Binary: 0)
       // Open Drain Enable to Disabled (Binary: 0)
       // Drive Strength to CFG(High) (Binary: 10)
       // config_pad_settings(EIM_D25, 0x0104);
       reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_D25, 0x0104);

       // config GPIO_19 pad for ecspi1 instance RDY port
       // config_pad_mode(GPIO_19, ALT5);
       reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_19, ALT5);
       // CONSTANT SETTINGS:
       // low/high output voltage to NA
       // test_ts to Disabled
       // dse test to regular
       // Pull Up / Down Config. to NA (CFG in SoC Level however NA in Module Level)
       // Open Drain Enable to NA (CFG in SoC Level however NA in Module Level)
       // CONFIGURED SETTINGS:
       // Hyst. Enable to Enabled (Binary: 1)
       // Pull / Keep Enable to Enabled (Binary: 1)
       // Pull / Keep Select to Keep (Binary: 0)
       // Drive Strength to LOW (Binary: 00)
       // config_pad_settings(GPIO_19, 0x0180);
       reg32_write(IOMUXC_SW_PAD_CTL_PAD_GPIO_19, 0x0180);
     */
}

/*!
 *  eSDHC I/O muxing configuration
 */
void esdhc_iomux_config(uint32_t base_address)
{
    switch (base_address) {
    case ESDHC1_BASE_ADDR:
        printf("Configure SD1 io\n");
        /* SD1 CMD, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_CMD);
        /* Configure CMD SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_CMD);
        /* SD1 CLK, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_CLK);
        /* Configure CLK SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_CLK);
        /* SD1 DAT0, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0);
        /* Configure DAT0 SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0);
        /* SD1 DAT1, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA1);
        /* Configure DAT1 SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_DATA1);
        /* SD1 DAT2, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA2);
        /* Configure DAT2 SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_DATA2);
        /* SD1 DAT3, SION bit */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD1_DATA3);
        /* Configure DAT3 SW PAD */
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3);

        if (board_id == BOARD_ID_MX53_ARD) {
            /* Select ALT2+SION mode for PATA_DATA8 bit for SD1 DAT4 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA8);
            /* Configure PATA_DATA8 SW PAD for SD1_DAT4 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA8);
            /* Select ALT2+SION mode for PATA_DATA9 bit for SD1 DAT5 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA9);
            /* Configure PATA_DATA9 SW PAD for SD1_DAT5 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA9);
            /* Select ALT2+SION mode for PATA_DATA10 bit for SD1 DAT6 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA10);
            /* Configure PATA_DATA10 SW PAD for SD1_DAT6 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA10);
            /* Select ALT2+SION mode for PATA_DATA11 bit for SD1 DAT7 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA11);
            /* Configure PATA_DATA11 SW PAD for SD1_DAT7 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA11);
            /* Card detect: use GPIO_1 as active low input */
            /* Select ALT1 mode of GPIO_1 */
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_1);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_1);    // default at reset
            gpio_dir_config(GPIO_PORT1, 1, GPIO_GDIR_INPUT);
            /* Write protect: use GPIO_9 as active low input */
            /* Select ALT1 mode of GPIO_9 */
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_9);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_9);    // default at reset
            gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_INPUT);
            /* Status LED: use GPIO_18 as active high output */
            /* Select ALT1 mode of GPIO_18 */
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_9);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_9);    // default at reset
            gpio_dir_config(GPIO_PORT7, 13, GPIO_GDIR_OUTPUT);
            gpio_write_data(GPIO_PORT7, 13, GPIO_LOW_LEVEL);
        }

        break;
    case ESDHC2_BASE_ADDR:

        if (board_id != BOARD_ID_MX53_ARD) {
            printf("Configure SD2 io - doing nothing now\n");
        } else {
            printf("Configure SD2 io\n");
            /* SD2 CMD, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_CMD);
            /* Configure CMD SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_CMD);
            /* SD2 CLK, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_CLK);
            /* Configure CLK SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_CLK);
            /* SD2 DAT0, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_DATA0);
            /* Configure DAT0 SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_DATA0);
            /* SD2 DAT1, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_DATA1);
            /* Configure DAT1 SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_DATA1);
            /* SD2 DAT2, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_DATA2);
            /* Configure DAT2 SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_DATA2);
            /* SD2 DAT3, SION bit */
            writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD2_DATA3);
            /* Configure DAT3 SW PAD */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD2_DATA3);
            /* Select ALT2+SION mode for PATA_DATA12 bit for SD2 DAT4 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA12);
            /* Configure PATA_DATA12 SW PAD for SD2_DAT4 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA12);
            /* Select ALT2+SION  mode for PATA_DATA13bit for SD2 DAT5 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA13);
            /* Configure PATA_DATA13 SW PAD for SD2_DAT5 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA13);
            /* Select ALT2+SION mode for PATA_DATA14 bit for SD2 DAT6 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA14);
            /* Configure PATA_DATA14 SW PAD for SD2_DAT6 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA14);
            /* Select ALT2+SION mode for PATA_DATA15 bit for SD2 DAT7 */
            writel(0x10 | ALT2, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA15);
            /* Configure PATA_DATA15 SW PAD for SD2_DAT7 */
            writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_PATA_DATA15);
            /* Card detect: use GPIO_4 as active low input */
            /* Select ALT1 mode of GPIO_4 */
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_4);    // default at reset
            gpio_dir_config(GPIO_PORT1, 4, GPIO_GDIR_INPUT);
            /* Write protect: use GPIO_2 as active low input */
            /* Select ALT1 mode of GPIO_2 */
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_2);
//  writel(0x1E4, IOMUXC_SW_PAD_CTL_PAD_GPIO_2);    // default at reset
            gpio_dir_config(GPIO_PORT1, 2, GPIO_GDIR_INPUT);
        }

        break;
    case ESDHC3_BASE_ADDR:

        if (board_id != BOARD_ID_MX53_ARD) {
            printf("Configure SD3(eSDHC3) io\n");
            /* SD3 CMD, muxed with PATA_RESET_B */
            writel(0x02, IOMUXC_BASE_ADDR + 0x288);
            /* Configure CMD SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x608);
            /* SD3 CLK, muxed with PATA_IORDY */
            writel(0x02, IOMUXC_BASE_ADDR + 0x28C);
            /* Configure CLK SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x60C);
            /* SD3 DAT0, muxed with PATA_DATA8 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2C4);
            /* Configure DAT0 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x648);
            /* SD3 DAT1, muxed with PATA_DATA9 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2C8);
            /* Configure DAT1 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x64C);
            /* SD3 DAT2, muxed with PATA_DATA10 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2CC);
            /* Configure DAT2 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x650);
            /* SD3 DAT3, muxed with PATA_DATA11 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2D0);
            /* Configure DAT3 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x654);
            /* SD3 DAT4~DAT7, mux with PATA */
            /* SD3 DAT4, muxed with PATA_DATA0 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2A4);
            /* Configure DAT4 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x628);
            /* SD3 DAT5, muxed with PATA_DATA1 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2A8);
            /* Configure DAT5 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x62C);
            /* SD3 DAT6, muxed with PATA_DATA2 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2AC);
            /* Configure DAT6 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x630);
            /* SD3 DAT7, muxed with PATA_DATA3 */
            writel(0x04, IOMUXC_BASE_ADDR + 0x2B0);
            /* Configure DAT7 SW PAD */
            writel(0x1F4, IOMUXC_BASE_ADDR + 0x634);
        } else {
            printf("Configure SD3 io - doing nothing now\n");
        }

        break;
    default:
        printf("MMC slot is not supported.\n");
        break;
    }
}

/*IOMUX configuration for CSI port0*/
void csi_port0_iomux_config(void)
{
    /* config CSI0_PIXCLK pad for ipu instance CSI0_PIXCLK port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_PIXCLK, 0x0080);
    /* config CSI0_MCLK pad for ipu instance CSI0_HSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x0080);
    /* config CSI0_DATA_EN pad for ipu instance CSI0_DATA_EN port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN, 0x0080);
    /* config CSI0_VSYNC pad for ipu instance CSI0_VSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_VSYNC, 0x0080);
    /* config CSI0_DAT12 pad for ipu instance CSI0_D[12] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT12, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT12, 0x0080);
    /* config CSI0_DAT13 pad for ipu instance CSI0_D[13] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT13, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT13, 0x0080);
    /* config CSI0_DAT14 pad for ipu instance CSI0_D[14] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT14, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT14, 0x0080);
    /* config CSI0_DAT15 pad for ipu instance CSI0_D[15] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT15, 0x0080);
    /* config CSI0_DAT16 pad for ipu instance CSI0_D[16] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT16, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT16, 0x0080);
    /* config CSI0_DAT17 pad for ipu instance CSI0_D[17] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT17, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT17, 0x0080);
    /* config CSI0_DAT18 pad for ipu instance CSI0_D[18] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT18, 0x0080);
    /* config CSI0_DAT19 pad for ipu instance CSI0_D[19] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT19, 0x0080);
}

/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
    if (board_id != BOARD_ID_MX53_ARD) {
        if ((board_id != BOARD_ID_MX53_SMD)) {
            /* Use GPIO5_20 to reset the USB HUB */
            uint32_t temp;
            /* set GPIO5_20 to low, this is the reset to the HUBs */
            writel((ALT1 | (0x1 << 4)), IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN);    //force input path as CEI0_DATA_EN,Alt1 as GPIO5_20
            temp = readl(GPIO5_BASE_ADDR + GPIO_DR_OFFSET);
            temp &= ~(0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_DR_OFFSET));   // set GPIO5_20 low
            temp = readl(GPIO5_BASE_ADDR + GPIO_GDIR_OFFSET);
            temp |= (0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_GDIR_OFFSET)); // set GPIO5_20 to output
            hal_delay_us(1000);
            temp = readl(GPIO5_BASE_ADDR + GPIO_DR_OFFSET);
            temp |= (0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_DR_OFFSET));   // set GPIO5_20 high
        } else {
            /* for the SMD, use GPIO3_14 to reset the USB_HUB */
            uint32_t temp;
            /* set GPIO3_14 to low, this is the reset to the HUBs */
            writel((ALT1 | (0x1 << 4)), IOMUXC_SW_MUX_CTL_PAD_EIM_DA14);    //force input path, ALT1 as GPIO3_14
            temp = readl(GPIO3_BASE_ADDR + GPIO_DR_OFFSET);
            temp &= ~(0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_DR_OFFSET));   //set GPIO3_14 low
            temp = readl(GPIO3_BASE_ADDR + GPIO_GDIR_OFFSET);
            temp |= (0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_GDIR_OFFSET)); // set GPIO3_14 to output
            hal_delay_us(1000);
            temp = readl(GPIO3_BASE_ADDR + GPIO_DR_OFFSET);
            temp |= (0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_DR_OFFSET));   //set GPIO3_14 high
        }
    }
}

/*!
 * USB module clock enable function
 */
void usb_clock_enable(void)
{
    *(volatile uint32_t *)(CCM_CCGR2) |= 0x3C000000;    //enable USBOH3_IPG_AHB, USBOH3_60M
    *(volatile uint32_t *)(CCM_CCGR4) |= 0x00003C00;    //enable PHY1 and PHY2 clock
}

/*!
 * USB VBUS power on, PATA_DA_2(GPIO7_8)
 */
void usb_vbus_power_on(void)
{
    uint32_t v;

    if ((board_id == BOARD_ID_MX53_SMD) || (board_id == BOARD_ID_MX53_LCB)) {
        /*Pull USB_PWR_EN(PATA_DA_2, also GPIO7_8) to high level */
        //Set GPIO7_8 as GPIO
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DA_2);
        //Set GPIO7_8 as output
        v = readl(GPIO7_GDIR);
        v |= (0x1 << 8);
        writel(v, GPIO7_GDIR);
        //Set GPIO7_8 as high
        v = readl(GPIO7_DR);
        v |= (0x1 << 8);
        writel(v, GPIO7_DR);
    } else {
        // on ARD, USBH1 power is enabled by pad GPIO_13 (function GPIO4_3)
        /* USB HOST1 iomux configuration for USB_H1_PWR */
        /* Select ALT0 mode of GPIO_11 for GPIO4_3 - USB_H1_PWR */
        /* active high output */
        writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_GPIO_11);
        writel(0x5e5, IOMUXC_SW_PAD_CTL_PAD_GPIO_13);   // disable open drain
        // enable GPIO4_3 as output and high
        reg32_write_mask(GPIO4_BASE_ADDR, 0x00000004, 0x00000004);  // GPIO data register, set bit 3
        reg32_write_mask(GPIO4_BASE_ADDR + 0x4, 0x00000004, 0x00000004);    // GPIO data direction register, set bit 3 for output

        // ARD has a ULPI phy, the first step is to "wake up" the ULPI via the viewport
        writel(0x80000000, USBH2_VIEWPORT);

    }
}

/*!
 * SATA related clocks enable function
 */
void sata_clock_enable(void)
{
    uint32_t v;
    /*module clocks gated on */
    writel(0xFFFFFFFF, CCM_CCGR6);
    writel(0xFFFFFFFF, CCM_CCGR5);
    writel(0xFFFFFFFF, CCM_CCGR0);
    v = readl(CCM_CCGR4);
    v |= (0x3 << 2);
    writel(v, CCM_CCGR4);
    /*Pull SATA_CLK_GPEN(GPIO1_4) to high level */
    //Set GPIO1_4 as GPIO
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
    //Set GPIO1_4 as output
    v = readl(GPIO1_GDIR);
    v |= (0x1 << 4);
    writel(v, GPIO1_GDIR);
    //Set GPIO1_4 as high
    v = readl(GPIO1_DR);
    v |= (0x1 << 4);
    writel(v, GPIO1_DR);
}

/*!
 * SATA related clocks dis function
 */
void sata_clock_disable(void)
{
    uint32_t v;
    /*Pull SATA_CLK_GPEN(GPIO1_4) to high level */
    //Set GPIO1_4 as GPIO
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
    //Set GPIO1_4 as output
    v = readl(GPIO1_GDIR);
    v |= (0x1 << 4);
    writel(v, GPIO1_GDIR);
    //Set GPIO1_4 as high
    v = readl(GPIO1_DR);
    v &= ~(0x1 << 4);
    writel(v, GPIO1_DR);
}

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
    uint32_t val = 0;

    /* Configure the memory map of the WEIM */
    /* Activates CS0 and CS1 with 64MB each in IOMUXC_GPR1 */
    val = readl(0x53FA8000 + 0x4);
    val &= ~(0x1F);
    val |= 0x1B;
    writel(val, 0x53FA8000 + 0x4);
    // Configure peripherals reset through io expander
    if (BOARD_ID_MX53_ARD == BOARD_TYPE_ID) {
        max7310_i2c_req_array[0].ctl_addr = MAX7310_I2C_BASE_ID0;   // the I2C controller base address
        max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
        max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    }
    if (BOARD_ID_MX53_SMD == BOARD_TYPE_ID) {
        /* Assert dcdc1v8_en */
        writel(1, IOMUXC_SW_MUX_CTL_PAD_EIM_DA1);

        val = readl(GPIO3_GDIR);
        val |= 0x01 << 1;
        writel(val, GPIO3_GDIR);

        val = readl(GPIO3_DR);
        val |= 0x01 << 1;
        writel(val, GPIO3_DR);
    }
}

/*!
 *  Display boot switch information
 */
void show_boot_switch_info(void)
{
    printf("========== BOOT configuration \n");
    printf("HAB Type: ");

    if (soc_sbmr->bmod == 0) {
        printf("FAB (Open)\n");
    } else if (soc_sbmr->bmod == 0x1) {
        printf("Open -allows any code to be flashed & executed (even without valid signature)\n");
    } else {
        printf("Closed (Security On)\n");
    }

    printf("Boot From: ");

    if ((soc_sbmr->boot_cfg1 & 0x3C) == 0) {
        printf("WEIM: ");

        if ((soc_sbmr->boot_cfg1 & 0x2) == 0) {
            printf("NOR");
        } else {
            printf("ONE NAND");
        }
    } else if (soc_sbmr->boot_cfg1 & 0x20) {
        printf("NAND: ADDR CYCLES:");

        if ((soc_sbmr->boot_cfg1 & 0x3) == 0) {
            printf("3: ");
        } else if ((soc_sbmr->boot_cfg1 & 0x3) == 1) {
            printf("4: ");
        } else if ((soc_sbmr->boot_cfg1 & 0x3) == 2) {
            printf("5: ");
        } else {
            printf("6: ");
        }

        if ((soc_sbmr->boot_cfg1 & 0xC) == 0) {
            printf("No interleave: ");
        } else if ((soc_sbmr->boot_cfg1 & 0xC) == 0x4) {
            printf("2 device: ");
        } else if ((soc_sbmr->boot_cfg1 & 0xC) == 0x8) {
            printf("4 device: ");
        } else {
            printf("UNKNOWN: ");
        }

        printf("PAGE SIZE: ");

        if ((soc_sbmr->boot_cfg2 & 0x30) == 0) {
            printf("512 + 16Bytes (4-Bit ECC): ");
        } else {
            if ((soc_sbmr->boot_cfg2 & 0x30) == 0x10) {
                printf("2K + 64Bytes: ");
            } else if ((soc_sbmr->boot_cfg2 & 0x30) == 0x20) {
                printf("4K + 128Bytes: ");
            } else {
                printf("4K + 218Bytes: ");
            }

            if ((soc_sbmr->boot_cfg3 & 0xC) == 0) {
                printf("4-bit ECC: ");
            } else if ((soc_sbmr->boot_cfg3 & 0xC) == 0x4) {
                printf("8-bit ECC: ");
            } else if ((soc_sbmr->boot_cfg3 & 0xC) == 0x8) {
                printf("16-bit ECC: ");
            } else {
                printf("ECC OFF: ");
            }
        }

        printf("BUS WIDTH: ");

        if ((soc_sbmr->boot_cfg2 & 0x8) == 0) {
            printf("8");
        } else {
            printf("16");
        }
    } else if ((soc_sbmr->boot_cfg1 & 0x3C) == 0x08) {
        printf("HD: ");

        if ((soc_sbmr->boot_cfg1 & 0x2) == 0) {
            printf("PATA");
        } else {
            printf("SATA");
        }
    } else if ((soc_sbmr->boot_cfg1 & 0x3C) == 0x0C) {
        printf("Serial: ");

        if ((soc_sbmr->boot_cfg1 & 0x2) == 0) {
            printf("I2C-NOR: ");

            if ((soc_sbmr->boot_cfg3 & 0x18) == 0) {
                printf("I2C-1");
            } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x8) {
                printf("I2C-2");
            } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x10) {
                printf("I2C-3");
            } else {
                printf("UNKNOWN");
            }
        } else {
            printf("SPI-NOR: ");

            if ((soc_sbmr->boot_cfg3 & 0x18) == 0) {
                printf("eCSPI1");
            } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x8) {
                printf("eCSPI2");
            } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x10) {
                printf("CSPI");
            } else {
                printf("UNKNOWN");
            }
        }
    } else if ((soc_sbmr->boot_cfg1 & 0x30) == 0x10) {
        if ((soc_sbmr->boot_cfg1 & 0x8) == 0) {
            printf("SD: ");
        } else {
            printf("MMC: ");
        }

        if ((soc_sbmr->boot_cfg3 & 0x18) == 0) {
            printf("eSDHC1");
        } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x8) {
            printf("eSDHC2");
        } else if ((soc_sbmr->boot_cfg3 & 0x18) == 0x10) {
            printf("eSDHC3");
        } else {
            printf("eSDHC4");
        }
    } else {
        printf("UNKNOWN");
    }

    printf("\n==================================\n\n");
}

/*! Read the FEC MAC address fuses
 *
 * @param mac_data pointer to an array to store mac address read from the fuses
 *
 * @return  0 if successful; non-zero otherwise
 */
int32_t read_mac(uint8_t * mac_data)
{
    mac_data[0] = readb(IIM_BASE_ADDR + 0xC24);
    mac_data[1] = readb(IIM_BASE_ADDR + 0xC28);
    mac_data[2] = readb(IIM_BASE_ADDR + 0xC2C);
    mac_data[3] = readb(IIM_BASE_ADDR + 0xC30);
    mac_data[4] = readb(IIM_BASE_ADDR + 0xC34);
    mac_data[5] = readb(IIM_BASE_ADDR + 0xC38);

    return 0;
}

void backlight_power_en(void)
{
    /* Write to R73 with value of 0xAF */
    da9053_i2c_reg(73, 0xAF, I2C_WRITE);

    /* Write to R74 with value of 0xAF */
    da9053_i2c_reg(74, 0xAF, I2C_WRITE);

    /* Write to R75 with value of 0xAF */
    da9053_i2c_reg(75, 0xAF, I2C_WRITE);

    /* Write to R70 with value of 0x3F to enable */
    da9053_i2c_reg(70, 0x3F, I2C_WRITE);
}

void tve_power_on(void)
{
    /* Write to R56 for 2V75 LDO7 output */
    da9053_i2c_reg(56, 0x5F, I2C_WRITE);
}

#ifdef MX53_SMD
void camera_power_on(uint32_t a_vdd, uint32_t do_vdd, uint32_t d_vdd)
{
    /* Write to R56 for LDO7 output AVDD */
    da9053_i2c_reg(56, a_vdd, I2C_WRITE);

    /* Enable DCDC1V8 power to output DOVDD */
    writel(0x01, IOMUXC_BASE_ADDR + 0x1A0);

    /* Write to R58 for LDO9 output DVDD */
    da9053_i2c_reg(58, d_vdd, I2C_WRITE);
}
#else
void camera_power_on(void)
{
    /* Write to R56 for 2V75 LDO7 output */
    da9053_i2c_reg(56, 0x5F, I2C_WRITE);

    /* Write to R57 for 1V8 LDO8 output */
    da9053_i2c_reg(57, 0x4C, I2C_WRITE);

    /* Write to R58 for 1V5 LDO9 output */
    da9053_i2c_reg(58, 0x45, I2C_WRITE);
}
#endif

void hdmi_power_on(void)
{
    if (board_id == BOARD_ID_MX53_SMD) {
        /* Write to R51 for 1V2 LDO2 output */
        da9053_i2c_reg(51, 0x58, I2C_WRITE);
    } else {
        /* Write to R55 for 1V2 LDO6 output */
        da9053_i2c_reg(55, 0x40, I2C_WRITE);
    }
}

/****************************************************************/
/* list of functions for build compatibility with i.MX6 platlib */
/****************************************************************/
void hdmi_pgm_iomux(void){}

void sii9022_power_on(void){}

unsigned int spdif_get_tx_clk_freq(void){
    return 0;
}

void spdif_iomux_config(void){}

void spdif_clk_cfg(void){}

void mipi_backlight_en(void){}

void mipi_display_reset(void){}

void mipi_clock_set(void){}

uint32_t GetCPUFreq(void)
{
    return 800000000;
}
