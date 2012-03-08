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

#if  defined(MX6SDL_SABRE_LITE)
// UART2 is the serial debug/console port for sabre_lite board
struct hw_module g_debug_uart = {
    "UART2 for debug",
    UART2_BASE_ADDR,
    80000000,
    IMX_INT_UART2,
    &default_interrupt_routine,
};
#elif defined(MX6SDL_SMART_DEVICE)
// UART1 is the serial debug/console port for smart_device board
struct hw_module g_debug_uart = {
    "UART1 for debug",
    UART1_BASE_ADDR,
    80000000,
    IMX_INT_UART1,
    &default_interrupt_routine,
};
#else
// UART4 is the serial debug/console port for EVB and ARD
struct hw_module g_debug_uart = {
    "UART4 for debug",
    UART4_BASE_ADDR,
    80000000,
    IMX_INT_UART4,
    &default_interrupt_routine,
};
#endif

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

struct hw_module *mx6sdl_module[] = {
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
    struct hw_module *tmp;

    /* Populate module frequency settings (important for UART driver) */
    for (i = 0; (tmp = mx6sdl_module[i]) != NULL; i++) {
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

    for (i = 0; (tmp = mx6sdl_module[i]) != NULL; i++) {
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

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
#if defined(MX6SDL_EVB) || defined(MX6SDL_ARD)
    // Configure some board signals through I/O expanders
    max7310_i2c_req_array[0].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
    max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    max7310_i2c_req_array[1].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[1].dev_addr = MAX7310_I2C_ID1;    // the I2C DEVICE address
    max7310_init(1, MAX7310_ID1_DEF_DIR, MAX7310_ID1_DEF_VAL);
#if defined(MX6SDL_ARD)
    max7310_i2c_req_array[2].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[2].dev_addr = MAX7310_I2C_ID2;    // the I2C DEVICE address
    max7310_init(2, MAX7310_ID2_DEF_DIR, MAX7310_ID2_DEF_VAL);
#endif
#endif

}

/*!
 *
 * Complementary code related to IOMUX configuration
 *
 */

/*!
 * That function calls the board dependent UART IOMUX configuration functions.
 */
void uart_iomux_config(uint32_t module_base_add)
{
    switch (module_base_add) {
    case UART1_BASE_ADDR:
        uart1_iomux_config();
        break;
    case UART2_BASE_ADDR:
        uart2_iomux_config();
        break;
    case UART3_BASE_ADDR:
        uart3_iomux_config();
        break;
    case UART4_BASE_ADDR:
        uart4_iomux_config();
        break;
    case UART5_BASE_ADDR:
        uart5_iomux_config();
        break;
    default:
        break;
    }
}

/*!
 * That function calls the board dependent I2C IOMUX configuration functions.
 */
void i2c_iomux_config(uint32_t module_base)
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
 * uSDHC pin mux and pad configure
 */
void usdhc_iomux_config(uint32_t base_address)
{
    switch (base_address) {
    case USDHC1_BASE_ADDR:
        usdhc1_iomux_config();
        break;
    case USDHC2_BASE_ADDR:
        usdhc2_iomux_config();
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
#if defined(MX6SDL_EVB)
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef MX6SDL_SMART_DEVICE
    // 3v3 on by default
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_dir_config(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
    // PMIC_5V LVDS1 power on by default
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_dir_config(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
#endif

#ifdef MX6SDL_ARD
    /*3.3V power supply through IOexpander */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_dir_config(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);

#endif
}

/*!
 * enable mipi backlight
  */
void mipi_backlight_en(void)
{
    //configure pin19 of the mipi dsi/csi connector
#ifdef MX6SDL_EVB
    //set GPIO1_9 to 0 so clear vbus on board
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef MX6SDL_ARD
    //default be populated by P3V3_DELAYED
#endif

#ifdef MX6SDL_SMART_DEVICE
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_D0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_D0, 0x1B0B0);
    gpio_dir_config(GPIO_PORT2, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT2, 0, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * reset MIPI display
 */
void mipi_display_reset(void)
{
#ifdef MX6SDL_EVB
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT, 0x1b0b0);
    gpio_dir_config(GPIO_PORT5, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT5, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(GPIO_PORT5, 0, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif

#ifdef MX6SDL_ARD
/*binded with the board reset button*/
#endif

#ifdef MX6SDL_SMART_DEVICE
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0, 0x1b0b0);
    gpio_dir_config(GPIO_PORT6, 11, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT6, 11, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(GPIO_PORT6, 11, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif
}

void mipi_clock_set(void)
{
    /*change back to default value, why?? */
    reg32_write(ANATOP_BASE_ADDR + 0xF8, 0x00003F00);
    reg32_write(ANATOP_BASE_ADDR + 0xF4, 0x00001000);
}

/* dummy empty function for camera_test
 * camera power is always on for MX6SDL SMD board*/
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
    hdmi_tx_cec_pgm_iomux();
    hdmi_tx_ddc_pgm_iomux();
    hdmi_tx_phydtb_pgm_iomux();
}

/*!
 * HDMI power up
 */
void sii9022_power_on(void)
{
    /*3.3V for core, default is on */
    /*5V for IO, default is on */
}

/*!
 * board dependent IOMUX configuration functions
 */
void can_iomux_config(uint32_t module_base_add)
{

#ifdef MX6SDL_ARD
    /* CAN_EN active high output */
    max7310_set_gpio_output(1, 7, GPIO_HIGH_LEVEL); //expander b, io7

    /* CAN_STBY active high output */
    max7310_set_gpio_output(1, 6, GPIO_HIGH_LEVEL); //expander b, io6 
#endif

    switch (module_base_add) {
    case CAN1_BASE_ADDR:
        can1_iomux_config();
#ifdef MX6SDL_ARD
        /* Select CAN, ENET_CAN1_STEER(PORT_EXP_B3) */
        max7310_set_gpio_output(1, 3, GPIO_HIGH_LEVEL); //expander b, io3 
        /* Select ALT5 mode of GPIO_4 for GPIO1_4 - CAN1_NERR_B */
        /* active low input */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_GPIO_4);
        gpio_dir_config(GPIO_PORT1, 4, GPIO_GDIR_INPUT);
#endif
        break;
    case CAN2_BASE_ADDR:
        can2_iomux_config();
#ifdef MX6SDL_ARD
        /* Select ALT5 mode of SD4_DAT3 for GPIO2_11 - CAN2_NERR_B */
        /* active low input */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
        gpio_dir_config(GPIO_PORT2, 11, GPIO_GDIR_INPUT);
#endif
        break;
    default:
        printf("ERR: invalid CAN base address for iomux config\n");
        break;
    }
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
    /* config CSI0_DATA_EN pad for ipu instance CSI0_DATA_EN port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN, 0x130B0);
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
}

/*!
 * SATA power on
 */
void sata_power_on(void)
{
    //enable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_HIGH_LEVEL);
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
    //No need to do anything for mx6sdl_ard
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

uint32_t GetCPUFreq(void)
{
    return 1000000000;
}

void pcie_clk_setup(uint32_t enable)
{
    uint32_t val;

    if (enable) {
        // gate on pci-e clks
        val = reg32_read(CCM_CCGR4);
        val |= 0x3 << 0;
        reg32_write(CCM_CCGR4, val);

        // clear the powerdown bit
//         reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_POWERDOWN);
        // enable pll
//         reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE);
        // wait the pll locked
//         while (!(reg32_read(HW_ANADIG_PLL_ETH_CTRL) & (0x01 << 31))) ;
        while (!HW_CCM_ANALOG_PLL_ENET.B.LOCK);
        // Disable bypass
//         reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);
        HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_BYPASS);
        // enable pci-e ref clk
//         reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 19);
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_PCIE);
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

#define ANATOP_PLL_ENABLE_MASK          0x00002000
#define ANATOP_PLL_BYPASS_MASK          0x00010000
#define ANATOP_PLL_LOCK                 0x80000000
#define ANATOP_PLL_PWDN_MASK            0x00001000
#define ANATOP_PLL_HOLD_RING_OFF_MASK   0x00000800
#define ANATOP_PCIE_CLK_ENABLE_MASK     0x00080000
#define ANATOP_SATA_CLK_ENABLE_MASK     0x00100000
#define ANATOP_BYPASS_SRC_LVDS1         0x00004000

#define ENET_PLL_REG ((volatile uint32_t *)(ANATOP_BASE_ADDR + (0xE << 4)))
#define ANA_MISC1_REG ((volatile uint32_t *)(ANATOP_BASE_ADDR + (0x16 << 4)))
#define ANATOP_LVDS_CLK1_SRC_PCIE       0xA
#define ANATOP_LVDS_CLK1_SRC_SATA       0xB
#define ANATOP_LVDS_CLK1_OBEN_MASK       0x400
#define ANATOP_LVDS_CLK1_IBEN_MASK       0x1000

void enable_extrn_100mhz_clk(uint32_t enable)
{
    if (enable) {
        /* Disable SATS clock gating used has external reference */
//         *ENET_PLL_REG |= ANATOP_SATA_CLK_ENABLE_MASK;
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_SATA);

        *ANA_MISC1_REG &= ~ANATOP_LVDS_CLK1_IBEN_MASK;
        *ANA_MISC1_REG |= ANATOP_LVDS_CLK1_SRC_SATA;
        *ANA_MISC1_REG |= ANATOP_LVDS_CLK1_OBEN_MASK;
    }
}

void enable_extrn_125mhz_clk(uint32_t enable)
{
    if (enable) {
        /* Disable SATS clock gating used has external reference */
        *ENET_PLL_REG |= ANATOP_SATA_CLK_ENABLE_MASK;

        *ANA_MISC1_REG &= ~ANATOP_LVDS_CLK1_IBEN_MASK;
        *ANA_MISC1_REG |= ANATOP_LVDS_CLK1_SRC_PCIE;
        *ANA_MISC1_REG |= ANATOP_LVDS_CLK1_OBEN_MASK;
    }
}

void pcie_card_rst(void)
{
    i2c_init(I2C3_BASE_ADDR, 100000);

    max7310_set_gpio_output(0, 2, 0);

    hal_delay_us(200 * 1000);

    max7310_set_gpio_output(0, 2, 1);
}
