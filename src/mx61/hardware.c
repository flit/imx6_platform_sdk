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

#if  defined(MX61_SABRE_LITE)
// UART2 is the serial debug/console port for sabre_lite board
struct hw_module g_debug_uart = {
    "UART2 for debug",
    UART2_BASE_ADDR,
    80000000,
    IMX_INT_UART2,
    &default_interrupt_routine,
};
#elif defined(MX61_SABRE_TABLET)
// UART1 is the serial debug/console port for sabre_tablet board
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

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
#if defined(MX61_EVB)
    // Configure some board signals through I/O expanders
    max7310_i2c_req_array[0].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[0].dev_addr = MAX7310_I2C_ID0;    // the I2C DEVICE address
    max7310_init(0, MAX7310_ID0_DEF_DIR, MAX7310_ID0_DEF_VAL);
    max7310_i2c_req_array[1].ctl_addr = I2C3_BASE_ADDR; // the I2C controller base address
    max7310_i2c_req_array[1].dev_addr = MAX7310_I2C_ID1;    // the I2C DEVICE address
    max7310_init(1, MAX7310_ID1_DEF_DIR, MAX7310_ID1_DEF_VAL);
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
#ifdef MX61_EVB
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef MX61_ARD
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
#ifdef MX61_EVB
    //set GPIO1_9 to 0 so clear vbus on board
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef MX61_ARD
    //default be populated by P3V3_DELAYED
#endif

#ifdef MX61_SABRE_TABLET
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
#ifdef MX61_EVB
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT, 0x1b0b0);
    gpio_dir_config(GPIO_PORT5, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT5, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_write_data(GPIO_PORT5, 0, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif

#ifdef MX61_ARD
/*binded with the board reset button*/
#endif

#ifdef MX61_SABRE_TABLET
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
 * camera power is always on for MX61 SMD board*/
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
    case ECSPI5_BASE_ADDR:
        ecspi5_iomux_config();
        break;
    default:
        break;
    }
}

/*!
 * board dependent IOMUX configuration functions
 */
void can_iomux_config(uint32_t module_base_add)
{

#ifdef MX61_ARD
    /* CAN_EN active high output */
    max7310_set_gpio_output(1, 7, GPIO_HIGH_LEVEL); //expander b, io7

    /* CAN_STBY active high output */
    max7310_set_gpio_output(1, 6, GPIO_HIGH_LEVEL); //expander b, io6 
#endif

    switch (module_base_add) {
    case CAN1_BASE_ADDR:
        can1_iomux_config();
#ifdef MX61_ARD
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
#ifdef MX61_ARD
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

extern sata_phy_ref_clk_t sata_phy_clk_sel;
/*!
 * SATA power on
 */
void sata_power_on(void)
{
    //enable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0 
    max7310_set_gpio_output(1, 0, GPIO_HIGH_LEVEL);
    sata_phy_clk_sel = ANATOP_ENET_PLL; //dummy. In fact, it is PLL8 for ENET
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
    //No need to do anything for mx61_ard
    return 0;
}

/*!
 *
 * Additional code related to clock configuration
 *
 */

void gpmi_nand_clk_setup(void)
{
    *(volatile uint32_t *)(HW_ANADIG_PFD_528_RW) &= ~(0x00800000);
    *(volatile uint32_t *)(CCM_CCGR4) &= ~(0xff000000);
    *(volatile uint32_t *)(CCM_CS2CDR) &= ~(0x00030000);
    *(volatile uint32_t *)(CCM_CS2CDR) |= 0x00020000;
    *(volatile uint32_t *)(CCM_CS2CDR) &= ~(0x07fc0000);
    *(volatile uint32_t *)(CCM_CS2CDR) |= ((uint32_t) (4 << 18) | (3 << 21));
    *(volatile uint32_t *)(CCM_CCGR4) |= 0xff000000;
    *(volatile uint32_t *)(CCM_CCGR6) |= 0x000003c0;
    *(volatile uint32_t *)(CCM_CCGR0) |= 0x00000030;
}

void esai_clk_sel_gate_on()
{
    uint32_t val = 0;
#if ((defined MX61_ARD) || (defined MX61_SABRE_TABLET) || (defined MX61_SABRE_LITE) || (defined MX61_EVB))
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
 * SATA related clocks enable function
 */
void sata_clock_enable(void)
{
    // Set SATA timings     0x05932046
    reg32_write(0x020E0034, 0x05932044);
    hal_delay_us(1000);

    // Enable SATA PLL
    reg32_write(0x020E0034, 0x05932046);
    hal_delay_us(1000);

    //enable SATA_CLK in CCGR5
    *(volatile u32 *)(CCM_BASE_ADDR + CCM_CCGR5_OFFSET) |= 0x00000030;
    //enable ENET_PLL (PLL8) in ANADIG. done in freq_populate()
    //enale SATA_CLK in the ENET_PLL register
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 20);    /* set ENABLE_SATA */
    //config ENET PLL div_select for SATA - 100MHz 
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x2, 0x3); /* 0b10-100MHz */
}

/*!
 * SATA related clocks dis function
 */
void sata_clock_disable(void)
{
    //disable SATA_CLK in CCGR5. 
    *(volatile u32 *)(CCM_BASE_ADDR + CCM_CCGR5_OFFSET) &= ~(0x00000030);
    //disable ENET_PLL (PLL8) in ANADIG
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 20);    /* clear ENABLE_SATA */
}

/*!
 * SPDIF clock configuration
 * Use the default setting as follow:
 * CDCDR[spdif0_clk_sel](PLL3)->CDCDR[spdif0_clk_pred](div2)->CDCDR[spdif0_clk_podf](div8)-> spdif0_clk_root, so 
 * the freqency of spdif0_clk should be 480/2/8 = 30MHz.
 */
void spdif_clk_cfg(void)
{
    unsigned int val;

    val = readl(CCM_BASE_ADDR + CCM_CDCDR_OFFSET);
    //CDCDR[spdif0_clk_sel](PLL3)
    val &= ~(0x03 << 20);
    val |= 0x03 << 20;
    //CDCDR[spdif0_clk_pred](div2)
    val &= ~(0x07 << 25);
    val |= 0x01 << 25;
    //CDCDR[spdif0_clk_podf](div8)
    val &= ~(0x07 << 22);
    val |= 0x07 << 22;
    writel(val, CCM_BASE_ADDR + CCM_CDCDR_OFFSET);

    val = readl(CCM_BASE_ADDR + CCM_CCGR5_OFFSET);
    val |= 0x03 << 14;          //spdif_clk_enable
    writel(val, CCM_BASE_ADDR + CCM_CCGR5_OFFSET);
}

unsigned int spdif_get_tx_clk_freq(void)
{
    return 30000000;
}

uint32_t GetCPUFreq(void)
{
    return 1000000000;
}

int perfmon_clk_cfg(uint32_t base, uint32_t enable)
{
    uint32_t val, shift = 0, reg;

    //Enable AXI clock for perfmon
    reg32setbit(IOMUXC_GPR11, 16);

    switch (base) {
    case IP2APB_PERFMON1_BASE_ADDR:
        reg = CCM_CCGR4;
        shift = CCM_CCGRx_CG1_OFFSET;
        break;
    case IP2APB_PERFMON2_BASE_ADDR:
        reg = CCM_CCGR4;
        shift = CCM_CCGRx_CG2_OFFSET;
        break;
    case IP2APB_PERFMON3_BASE_ADDR:
        reg = CCM_CCGR4;
        shift = CCM_CCGRx_CG3_OFFSET;
        break;
    default:
        break;
    }

    /* do nothing if shit = 0 <=> no base address match */
    if(shift != 0)
    {
        val = reg32_read(reg);
        if (enable) {
            val |= 0x03 << shift;
        } else {
            val &= ~(0x03 << shift);
        }

        reg32_write(reg, val);
    }

    return 0;
}

/*IOMUX configuration for CSI port0*/
void mxc_csi_port0_iomux_config(void)
{
    /* config CSI0_PIXCLK pad for ipu instance CSI0_PIXCLK port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_PIXCLK, 0x01000);
    /* config CSI0_MCLK pad for ipu instance CSI0_HSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_MCLK, 0x01000);
    /* config CSI0_DATA_EN pad for ipu instance CSI0_DATA_EN port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN, 0x01000);
    /* config CSI0_VSYNC pad for ipu instance CSI0_VSYNC port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_VSYNC, 0x01000);
    /* config CSI0_DAT12 pad for ipu instance CSI0_D[12] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT12, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT12, 0x01000);
    /* config CSI0_DAT13 pad for ipu instance CSI0_D[13] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT13, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT13, 0x01000);
    /* config CSI0_DAT14 pad for ipu instance CSI0_D[14] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT14, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT14, 0x01000);
    /* config CSI0_DAT15 pad for ipu instance CSI0_D[15] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT15, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT15, 0x01000);
    /* config CSI0_DAT16 pad for ipu instance CSI0_D[16] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT16, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT16, 0x01000);
    /* config CSI0_DAT17 pad for ipu instance CSI0_D[17] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT17, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT17, 0x01000);
    /* config CSI0_DAT18 pad for ipu instance CSI0_D[18] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT18, 0x01000);
    /* config CSI0_DAT19 pad for ipu instance CSI0_D[19] port */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19, ALT0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_CSI0_DAT19, 0x01000);
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
