/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
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
#include "registers/regsccmanalog.h"
#include "registers/regsflexcan.h"
#include "registers/regsipu.h"
#include "registers/regspmu.h"
#include "registers/regsccm.h"
#include "hardware.h"

#define ON 1
#define OFF 0

extern sata_phy_ref_clk_t sata_phy_clk_sel;
 
struct imx_i2c_request max7310_i2c_req_array[MAX7310_NBR];

// ARM core.
#define DUMMY_ARM_CORE_BASE_ADDR 0x12345789
hw_module_t arm_core = {
    "Cortex A9 core",
    1,
    DUMMY_ARM_CORE_BASE_ADDR,
    792000000,
};

#if  defined(BOARD_SABRE_LITE)
// UART2 is the serial debug/console port for sabre_lite board
hw_module_t g_debug_uart = {
    "UART2 for debug",
    2,
    UART2_BASE_ADDR,
    80000000,
    IMX_INT_UART2,
    &default_interrupt_routine,
};
#elif defined(BOARD_SMART_DEVICE)
// UART1 is the serial debug/console port for smart_device board
hw_module_t g_debug_uart = {
    "UART1 for debug",
    1,
    UART1_BASE_ADDR,
    80000000,
    IMX_INT_UART1,
    &default_interrupt_routine,
};
#else
// UART4 is the serial debug/console port for EVB and ARD
hw_module_t g_debug_uart = {
    "UART4 for debug",
    4,
    UART4_BASE_ADDR,
    80000000,
    IMX_INT_UART4,
    &default_interrupt_routine,
};
#endif

/* EPIT1 used for time functions */
hw_module_t g_system_timer = {
    "EPIT1 for system timer",
    1,
    EPIT1_BASE_ADDR,
    66000000,
    IMX_INT_EPIT1,
    &default_interrupt_routine,
};

hw_module_t ddr = {
    "DDR memory",
    1,
    MMDC_P0_BASE_ADDR,
};

hw_module_t *mx6dq_module[] = {
    &arm_core,
    &ddr,
    &g_debug_uart,
    &g_system_timer,
    NULL,
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
        /* value depends on how the timer is configured, 
           and this is actually initialized in system_time_init() */
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
    hw_module_t *tmp;

    /* Populate module frequency settings (important for UART driver) */
    for (i = 0; (tmp = mx6dq_module[i]) != NULL; i++) {
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
    printf("======== Clock frequencies(HZ) =========\n");

    for (i = 0; (tmp = mx6dq_module[i]) != NULL; i++) {
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

    debug_printf("num_rows= %d\n", num_rows);
    i = 1;

    while (i <= col) {
        num_cols *= 2;
        i++;
    }

    debug_printf("num_cols= %d\n", num_cols);
    density = num_rows * num_cols / megabyte;
    density = density * dsiz * num_banks / 8;
    printf("Density per chip select: %dMB \n", density);
    printf("========================================\n\n");
}

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
#if defined(BOARD_EVB) || defined(BOARD_SABRE_AI)
    // Configure some board signals through I/O expanders
    max7310_i2c_req_array[0].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
    max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    max7310_i2c_req_array[1].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[1].dev_addr = MAX7310_I2C_ID1;    // the I2C DEVICE address
    max7310_init(1, MAX7310_ID1_DEF_DIR, MAX7310_ID1_DEF_VAL);
#endif
#if defined(BOARD_SABRE_AI)
    max7310_i2c_req_array[2].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[2].dev_addr = MAX7310_I2C_ID2;    // the I2C DEVICE address
    max7310_init(2, MAX7310_ID2_DEF_DIR, MAX7310_ID2_DEF_VAL);
#endif
}


/*!
 * eCSPI pin mux and pad configure
 */
void ecspi_iomux_cfg(uint32_t base_address)
{
    switch (base_address) {
    case ECSPI1_BASE_ADDR:
        ecspi1_iomux_config();
        break;
    case ECSPI2_BASE_ADDR:
        ecspi2_iomux_config();
        break;
    case ECSPI3_BASE_ADDR:
        ecspi3_iomux_config();
        break;
    case ECSPI4_BASE_ADDR:
        ecspi4_iomux_config();
        break;
    case ECSPI5_BASE_ADDR:
        ecspi5_iomux_config();
        break;
    default:
        break;
    }
}

/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(void)
{
#if defined(BOARD_EVB)
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_dir_config(HW_GPIO1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SMART_DEVICE
    // 3v3 on by default
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_dir_config(HW_GPIO6, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO6, 10, GPIO_HIGH_LEVEL);
    // PMIC_5V LVDS1 power on by default
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_dir_config(HW_GPIO1, 21, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO1, 21, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SABRE_AI
    /*3.3V power supply through IOexpander */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_dir_config(HW_GPIO2, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO2, 9, GPIO_HIGH_LEVEL);

#endif
}

/*!
 * enable mipi backlight
  */
void mipi_backlight_en(void)
{
    //configure pin19 of the mipi dsi/csi connector
#ifdef BOARD_EVB
    //set GPIO1_9 to 0 so clear vbus on board
    gpio_dir_config(HW_GPIO1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SABRE_AI
    //default be populated by P3V3_DELAYED
#endif

#ifdef BOARD_SMART_DEVICE
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_D0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_D0, 0x1B0B0);
    gpio_dir_config(HW_GPIO2, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO2, 0, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * reset MIPI display
 */
void mipi_display_reset(void)
{
#ifdef BOARD_EVB
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT, 0x1b0b0);
    gpio_dir_config(HW_GPIO5, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO5, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(HW_GPIO5, 0, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif

#ifdef BOARD_SABRE_AI
/*binded with the board reset button*/
#endif

#ifdef BOARD_SMART_DEVICE
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0, 0x1b0b0);
    gpio_dir_config(HW_GPIO6, 11, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO6, 11, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(HW_GPIO6, 11, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif
}

/* dummy empty function for camera_test
 * camera power is always on for MX6DQ SMD board*/
void camera_power_on(void)
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
    ipu1_iomux_config();
    hdmi_tx_cec_pgm_iomux();
    hdmi_tx_ddc_pgm_iomux();
    hdmi_tx_phydtb_pgm_iomux();
}

/*!
 * HDMI power up
 */
void ext_hdmi_transmitter_power_on(void)
{
    /*3.3V for core, default is on */
    /*5V for IO, default is on */
}

/*!
 * board dependent IOMUX configuration functions
 */
void hw_can_iomux_config(uint32_t module_instance)
{

#ifdef BOARD_SABRE_AI
    /* CAN_EN active high output */
    max7310_set_gpio_output(1, 7, GPIO_HIGH_LEVEL); //expander b, io7

    /* CAN_STBY active high output */
    max7310_set_gpio_output(1, 6, GPIO_HIGH_LEVEL); //expander b, io6 
#endif

    can_iomux_config(module_instance);

#ifdef BOARD_SABRE_AI
    switch (module_instance)
    {
    	case HW_FLEXCAN1:
			/* Select CAN, ENET_CAN1_STEER(PORT_EXP_B3) */
			max7310_set_gpio_output(1, 3, GPIO_HIGH_LEVEL); //expander b, io3
			/* Select ALT5 mode of GPIO_4 for GPIO1_4 - CAN1_NERR_B */
			/* active low input */
			writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
			gpio_dir_config(HW_GPIO1, 4, GPIO_GDIR_INPUT);
			break;

    	case HW_FLEXCAN2:
			/* Select ALT5 mode of SD4_DAT3 for GPIO2_11 - CAN2_NERR_B */
			/* active low input */
			writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
			gpio_dir_config(HW_GPIO2, 11, GPIO_GDIR_INPUT);
			break;

    	default:
			printf("ERR: invalid FLEXCAN instance for iomux config\n");
			break;
    }
#endif
}

/*IOMUX configuration for CSI port0*/
void csi_port0_iomux_config(void)
{
    uint32_t tmpVal;

    /* config CSI0_PIXCLK pad for ipu instance CSI0_PIXCLK port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_PIXCLK, 0x130B0);
    /* config CSI0_MCLK pad for ipu instance CSI0_HSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x130B0);
    /* config CSI0_VSYNC pad for ipu instance CSI0_VSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_VSYNC, 0x130B0);
    /* config CSI0_DAT12 pad for ipu instance CSI0_D[12] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT12, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT12, 0x130B0);
    /* config CSI0_DAT13 pad for ipu instance CSI0_D[13] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT13, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT13, 0x130B0);
    /* config CSI0_DAT14 pad for ipu instance CSI0_D[14] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT14, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT14, 0x130B0);
    /* config CSI0_DAT15 pad for ipu instance CSI0_D[15] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT15, 0x130B0);
    /* config CSI0_DAT16 pad for ipu instance CSI0_D[16] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT16, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT16, 0x130B0);
    /* config CSI0_DAT17 pad for ipu instance CSI0_D[17] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT17, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT17, 0x130B0);
    /* config CSI0_DAT18 pad for ipu instance CSI0_D[18] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT18, 0x130B0);
    /* config CSI0_DAT19 pad for ipu instance CSI0_D[19] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT19, 0x130B0);

    /* set GPR1 to enable parallel interface
     * bit 19: 0 - Enable mipi to IPU1 CSI0, virtual channel is fixed to 0
     *         1 - Enable parallel interface to IPU CSI0
     * bit 20: 0 - Enable mipi to IPU2 CSI1, virtual channel is fixed to 3
     *         1 - Enable parallel interface to IPU2 CSI1
     * IPU1 CSI1 directly connect to mipi CSI2, virtual channel is fixed to 1
     * IPU2 CSI0 directly connect to mipi CSI2, virtual channel is fixed to 2
     */
    tmpVal = reg32_read(IOMUXC_GPR1);
    reg32_write(IOMUXC_GPR1, tmpVal | (0x1 << 19));
}

/* ENET iomux config */
void imx_ar8031_iomux()
{
    enet_iomux_config();        // iomux tool output
}

/*CPU_PER_RST_B low to high*/
void imx_ar8031_reset(void)
{
#if defined(BOARD_SMART_DEVICE)
    /* Select ALT5 mode of ENET_CRS-DV for GPIO1_25 - PGMII_NRST */
    /* active low output */
    gpio_dir_config(HW_GPIO1, 25, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO1, 25, GPIO_LOW_LEVEL);
    hal_delay_us(500);
    gpio_write_data(HW_GPIO1, 25, GPIO_HIGH_LEVEL);
#elif defined(BOARD_SABRE_AI) && !defined(BOARD_REV_A)
    /* CPU_PER_RST_B low to high */
//    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
//    hal_delay_us(1000);
//    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
#endif
}

/*CPU_PER_RST_B low to high*/
void imx_KSZ9021RN_reset(void)
{
    //max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    //hal_delay_us(1000000);
    //max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
#ifdef BOARD_SABRE_LITE
    // Config gpio3_GPIO[23] to pad EIM_D23(D25)
    writel((SION_DISABLED & 0x1) << 4 | (ALT5 & 0x7), IOMUXC_SW_MUX_CTL_PAD_EIM_D23);
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_EIM_D23);
    writel((readl(GPIO3_BASE_ADDR + 0x4) | (1 << 23)), GPIO3_BASE_ADDR + 0x4);  /*output */
    writel(readl(GPIO3_BASE_ADDR + 0x0) & ~(1 << 23), GPIO3_BASE_ADDR + 0x0);   // output low
    hal_delay_us(1000000);      // hold in reset for a delay
    writel(readl(GPIO3_BASE_ADDR + 0x0) | (1 << 23), GPIO3_BASE_ADDR + 0x0);
#endif
}

/*!
 * SATA power on
 */
void sata_power_on(void)
{
    //enable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0
#ifdef BOARD_SMART_DEVICE
    //AUX_5V_EN
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_dir_config(HW_GPIO6, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO6, 10, GPIO_HIGH_LEVEL);
#else
    //enable SATA_3V3 and SATA_5V with MX7310 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_HIGH_LEVEL);
    //sata_phy_clk_sel = CCM_PLL_ENET;
#endif
}

/*!
 * SATA power off
 */
void sata_power_off(void)
{
    //disable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_LOW_LEVEL);
}

void SGTL5000PowerUp_and_clockinit(void)
{
}

/*!
 * Power no esai codec.
 */
int esai_codec_power_on(void)
{
    //No need to do anything for BOARD_SABRE_AI
    return 0;
}

/*!
 *
 * Additional code related to clock configuration
 *
 */
unsigned int spdif_get_tx_clk_freq(void)
{
    return 30000000;
}

void pcie_clk_setup(uint32_t enable)
{
    if (enable) {
        // gate on pci-e clks
        HW_CCM_CCGR4.B.CG0 = CLOCK_ON;

        // clear the powerdown bit
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_POWERDOWN);
        // enable pll
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE);
        // wait the pll locked
        while (!HW_CCM_ANALOG_PLL_ENET.B.LOCK) ;
        // Disable bypass
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_BYPASS);
        // enable pci-e ref clk
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_125M);
    }
}

void pcie_card_pwr_setup(uint32_t enable)
{
    i2c_init(I2C3_BASE_ADDR, 100000);

    if (enable) {
        //enable pciemini_3.3v
        max7310_set_gpio_output(1, 2, 1);
    } else {
        max7310_set_gpio_output(1, 2, 0);
    }
}

void enable_extrn_100mhz_clk(uint32_t enable)
{
    if (enable) {
        // Disable SATA clock gating used as external reference
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);

        // Select SATA clock source and switch to output buffer.
        HW_PMU_MISC1_CLR(BM_PMU_MISC1_LVDSCLK1_IBEN);
        HW_PMU_MISC1.B.LVDS1_CLK_SEL = BV_PMU_MISC1_LVDS1_CLK_SEL__SATA_REF;
        HW_PMU_MISC1_SET(BM_PMU_MISC1_LVDSCLK1_OBEN);
    }
}

void enable_extrn_125mhz_clk(uint32_t enable)
{
    if (enable) {
        // Disable SATA clock gating used as external reference
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);

        // Select PCIe clock source and switch to output buffer.
        HW_PMU_MISC1_CLR(BM_PMU_MISC1_LVDSCLK1_IBEN);
        HW_PMU_MISC1.B.LVDS1_CLK_SEL = BV_PMU_MISC1_LVDS1_CLK_SEL__PCIE_REF;
        HW_PMU_MISC1_SET(BM_PMU_MISC1_LVDSCLK1_OBEN);
    }
}

void pcie_card_rst(void)
{
    i2c_init(I2C3_BASE_ADDR, 100000);

    max7310_set_gpio_output(0, 2, 0);

    hal_delay_us(200 * 1000);

    max7310_set_gpio_output(0, 2, 1);
}

//copied from obds
/* IOMUX configuration for the Android_Buttons */
void android_buttons_iomux_config()
{
    //HOME_(SD2_CMD_GPI1_11)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD2_CMD, ALT5);   //GPIO1[11]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD2_CMD, 0x00E0); // pull-up enabled at pad
    //BACK_(SD2_DAT3_GPI1_12)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD2_DAT3, ALT5);  //GPIO1[12]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD2_DAT3, 0x00E0);    // pull-up enabled at pad
    //PROG_(SD4_DAT4_GPI2_12)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT4, ALT5);  //GPIO2[12]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD4_DAT4, 0x00E0);    // pull-up enabled at pad
    //VOL+_(SD4_DAT7_GPI2_15)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT7, ALT5);  //GPIO2[15]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD4_DAT7, 0x00E0);    // pull-up enabled at pad
    //VOL-_(DISP0_DAT20_GPI5_14)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20, ALT5);   //GPIO5[14]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20, 0x00E0); // pull-up enabled at pad
}

//Copied from obds
/* I/O config for the DS90UR124QVS - LVDS camera in */
void deserializer_io_config(void)
{
   // REN and RPWDB controlled by ADV7180 configured in the driver
   csi_port0_iomux_config();
}

//MLB iomux configuration
void mlb_io_config(void)
{
#ifdef MLB_SUPPORT
   //default board will use I2C3, but might be I2C2
   io_cfg_i2c(OS81050_I2C_BASE);
   mlb_iomux_config();
   //MLB_PWRDN input
   writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT15);
   gpio_dir_config(HW_GPIO5, 9, GPIO_GDIR_INPUT);
#endif
}

/*!
 * This function enables Vbus for the given USB port\n
 * The procedure to enable Vbus depends on both the Chip and board hardware\n
 *
 * @param port      USB module to initialize
 */
void usbEnableVbus(usb_module_t * port)
{

    switch (port->controllerID) {
    case OTG:
#ifdef BOARD_SABRE_AI
        // Vbus control is on I2C port expander C1 for the ARD board.
        max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 1);
#endif
#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D22, ALT5);
        gpio_dir_config(HW_GPIO3, 22, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO3, 22, GPIO_HIGH_LEVEL);
#endif

        break;
    case Host1:
#ifdef BOARD_SABRE_AI
        // Vbus control is on I2C port expander B7 for the ARD board.
        max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 1);
#endif

#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D31, ALT5);
        gpio_dir_config(HW_GPIO3, 31, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO3, 31, GPIO_HIGH_LEVEL);
#endif

        break;
    case Host2:
#ifdef BOARD_EVB

#endif
        break;
    case Host3:
        // Nothing to be done here.
        break;
    default:
        // no such controller
        break;
    }
}

/*!
 * This function disables Vbus for the given USB port\n
 * The procedure to enable Vbus depends on both the Chip and board hardware\n
 * This implementation is for the MX6q Sabre-AI board\n
 *
 * @param port      USB module to initialize
 */
void usbDisableVbus(usb_module_t * port)
{
    switch (port->controllerID) {
    case OTG:
#ifdef BOARD_SABRE_AI
        max7310_set_gpio_output(MAX7310_I2C_ID2, 1, 0);
#endif
#ifdef BOARD_EVB
        gpio_write_data(HW_GPIO3, 22, GPIO_LOW_LEVEL);
#endif
        break;
    case Host1:
#ifdef BOARD_SABRE_AI
        max7310_set_gpio_output(MAX7310_I2C_ID1, 7, 0);
#endif
#ifdef BOARD_EVB
        gpio_write_data(HW_GPIO3, 31, GPIO_LOW_LEVEL);
#endif
    case Host2:
#ifdef BOARD_EVB

#endif
        break;
    case Host3:
        // Nothing to be done here.
        break;
    default:
        // no such controller
        break;
    }
}

//copy from OBDS
// Set up the chip select registers for the weim "parallel" nor flash
void weim_nor_flash_cs_setup(void)
{
   //DSIZ=010 (map 16-bit to D[31:16], csen=1
   // writel(0x00020001, WEIM_REGISTERS_BASE_ADDR + 0x000);
   writel(0x00620081, WEIM_REGISTERS_BASE_ADDR + 0x0000);

   // CS0 Read Config reg1
   // RWCS=11, OEA=2, OEN=1
   //writel(0x0B002100, WEIM_REGISTERS_BASE_ADDR + 0x008);
   writel(0x1C022000, WEIM_REGISTERS_BASE_ADDR + 0x0008);

   // CS0 Write Config Reg 1
   // WWCS=11, WEA=2, WEN=1
   //writel(0x0B000440, WEIM_REGISTERS_BASE_ADDR + 0x010);
   writel(0x0804a240, WEIM_REGISTERS_BASE_ADDR + 0x010); 
}

/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
}

/*! Copy from OBDS
 * Provide the power for TFT LCD backlight
 */
void tftlcd_backlight_en(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
        /*GPIO to provide backlight */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_dir_config(HW_GPIO4, 20, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO4, 20, GPIO_HIGH_LEVEL);
    } else if (!strcmp(panel_name, "BoundaryDev WVGA")) {
#if defined (BOARD_REV_A)
        /*lvds/parallel display backlight enable, GPIO2_0 */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
        gpio_dir_config(HW_GPIO2, 9, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO2, 9, GPIO_HIGH_LEVEL);

        // lcd_contrast conflict with actual BoundaryDev display so seeting to input
        // since TSC not used on SABRE AI
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_dir_config(HW_GPIO4, 20, GPIO_GDIR_INPUT);
#elif defined (BOARD_REV_B)
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_dir_config(HW_GPIO4, 20, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO4, 20, GPIO_HIGH_LEVEL);
#endif
    } else {
        printf("Unsupported panel!\n");
    }
#if 0
#ifdef BOARD_SABRE_AI
    /*lvds/parallel display backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_dir_config(HW_GPIO2, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO2, 9, GPIO_LOW_LEVEL);

    // lcd_contrast conflict with actual BoundaryDev display so seeting to input
    // since TSC not used on SABRE AI
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
    gpio_dir_config(HW_GPIO4, 20, GPIO_GDIR_INPUT);
#endif
#ifdef BOARD_SMART_DEVICE
    /* AUX_3V15 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_dir_config(HW_GPIO6, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO6, 9, GPIO_HIGH_LEVEL);
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_dir_config(HW_GPIO1, 21, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO1, 21, GPIO_HIGH_LEVEL);
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_dir_config(HW_GPIO6, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO6, 10, GPIO_HIGH_LEVEL);
#endif
#endif

}

/*! Copy from OBDS
 * Reset the TFT LCD
 */
void tftlcd_reset(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
        gpio_dir_config(HW_GPIO2, 31, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_write_data(HW_GPIO2, 31, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
#ifdef BOARD_SMART_DEVICE
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_DA8, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_DA8, 0x1B0B0);
        gpio_dir_config(HW_GPIO3, 8, GPIO_GDIR_OUTPUT);
        gpio_write_data(HW_GPIO3, 8, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_write_data(HW_GPIO3, 8, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
    }
}

/*! From obds
 * Disable the display panel
 */
void disable_para_panel(void)
{
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
    gpio_dir_config(HW_GPIO2, 31, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO2, 31, GPIO_LOW_LEVEL);
}

/*! From obds
 * ENET iomux config
 */
void imx_enet_iomux(void)
{
    enet_iomux_config();
#ifdef BOARD_SABRE_AI
    /* Select ENET, ENET_CAN1_STEER(PORT_EXP_B3) */
    max7310_set_gpio_output(1, 2, GPIO_LOW_LEVEL);
    /* Select ALT5 mode of GPIO_19 for GPIO4_5 - PGMIT_INT_B */
    /* active low input */
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_GPIO_19);
    gpio_dir_config(HW_GPIO4, 5, GPIO_GDIR_INPUT);
#endif
}

/*! From obds
 * Audio Codec Power on
 */
void audio_codec_power_on (void)
{
#ifdef BOARD_SMART_DEVICE
    //CODEC PWR_EN, key_col12
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    gpio_dir_config(HW_GPIO4, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(HW_GPIO4, 10, GPIO_HIGH_LEVEL);
#endif
}

/*! From obds
 * Audio Clock Config
 */
void audio_clock_config(void)
{
#if defined(CHIP_MX6DQ) && defined(BOARD_SMART_DEVICE) 
    uint32_t val = 0;
    
    ccm_iomux_config();

    val = (0x01 << 24) |      //clko2 en
          (0x05 << 21) |     //div 6
          (0x13 << 16) |     //ssi2 root clk
          (0x01 << 8);       //CKO1 output drives cko2 clock
//    writel(val, CCM_CCOSR);
    writel(val, (CCM_BASE_ADDR + CCM_CCOSR_OFFSET));
#endif
}
