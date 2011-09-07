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

// ARM core is a special case. Assign 0 to it.
struct hw_module core = {
    "ARM",
    0,
};

// UART4 is the serial debug/console port
struct hw_module g_debug_uart = {
    "UART4 for debug",
    UART4_BASE_ADDR,
    27000000,
    IMX_INT_UART4,
    &default_interrupt_routine,
};

/* EPIT1 used for time functions */
struct hw_module g_system_timer = {
    "EPIT1 used as system timer",
    EPIT1_BASE_ADDR,
    27000000,
    IMX_INT_EPIT1,
    &default_interrupt_routine,
};

struct hw_module ddr = {
    "DDR",
    MMDC_P0_BASE_ADDR,
};

struct hw_module *mx61_module[] = {
    &core,
    &ddr,
    &g_debug_uart,
    &g_system_timer,
    NULL,
};

uint32_t mx61_gpio[] = {
    GPIO1_BASE_ADDR,
    GPIO2_BASE_ADDR,
    GPIO3_BASE_ADDR,
    GPIO4_BASE_ADDR,
    GPIO5_BASE_ADDR,
    GPIO6_BASE_ADDR,
    GPIO7_BASE_ADDR
};

/*!
 * Sets the GPIO direction for the specified pin.
 *
 * @param	port: 	GPIO module instance, 0 to 6.
 * @param 	pin:	GPIO pin 0 to 31.
 * @param 	dir:	direction for the pin. in or out.
 *
 * @return:  -1 means failed to set the pin
 *
 */
int32_t gpio_dir_config(int32_t port, int32_t pin, int32_t dir)
{
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    oldVal = readl(mx61_gpio[port] + GPIO_GDIR_OFFSET);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    writel(newVal, mx61_gpio[port] + GPIO_GDIR_OFFSET);
    return 0;
}

/*!
Function:
	gpio_write_data()
Description:
	Sets the GPIO attributte(high or low) for the specified pin.
Parameters:
    @port: 	GPIO module instance, 0 to 6.
	@pin:	GPIO pin 0 to 31.
    @attr:	attributte for the pin. high/low
Returns:
    Return the value, -1 means failed to set the pin
*/
int32_t gpio_write_data(int32_t port, int32_t pin, uint32_t attr)
{
    int32_t dir;
    uint32_t oldVal = 0, newVal = 0;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(mx61_gpio[port] + GPIO_GDIR_OFFSET) & (1 << pin)) >> pin;

    if (dir != 1) {
        printf("GPIO%d_%d is not configured to be output!\n", port + 1, pin);
        return -1;
    }

    oldVal = readl(mx61_gpio[port] + GPIO_DR_OFFSET);

    if (attr == 0)
        newVal = oldVal & (~(1 << pin));
    else if (attr == 1)
        newVal = oldVal | (1 << pin);

    writel(newVal, mx61_gpio[port] + GPIO_DR_OFFSET);
    return 0;
}

/*!
Function:
	gpio_read_data()
Description:
	Gets the GPIO attributte(high or low) for the specified pin.
Parameters:
    @port: 	GPIO module instance, 0 to 6.
	@pin:	GPIO pin 0 to 31.
Returns:
    Return the value, -1 means failed to get the value
*/
int32_t gpio_read_data(int32_t port, int32_t pin)
{
    int32_t dir;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(mx61_gpio[port] + GPIO_GDIR_OFFSET) & (1 << pin)) >> pin;

    if (dir != 0) {
        printf("GPIO%d_%d is not configured to be input!\n", port + 1, pin);
        return -1;
    }

    return (readl(mx61_gpio[port] + GPIO_DR_OFFSET) & (1 << pin)) >> pin;
}

/*!
 * Retrieve the freq info based on the passed in module_base.
 * @param   module_base     the base address of the module
 * @return  frequency in Hz (0 means not a valid module)
 */
uint32_t get_freq(uint32_t module_base)
{
    if (module_base == 0)       // as ARM Core doesn't have a module base per se, it is set to 0
        //return get_main_clock(CPU_CLK);
        return 1000000000;
    else if (module_base == MMDC_P0_BASE_ADDR)
        //return get_main_clock(DDR_CLK);
        return 400000000;
    else if (module_base == g_debug_uart.base)
        //return get_peri_clock(UART4_BAUD);
        return 80000000;
    else if (module_base == g_system_timer.base)
        //return get_peri_clock(EPIT1_CLK);
        return 66000000;
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
    int32_t i;
    struct hw_module *tmp;

    //ETHNET
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);    /*power down bit */
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);    /*enable bit */
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);    /*bypass bit */
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x3, 0x3); /*divide bits */

    /* Ungate clocks to all modules */
    *(volatile uint32_t *)(CCM_CCGR0) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR1) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR2) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR3) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR4) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR5) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR6) = 0xFFFFFFFF;
    *(volatile uint32_t *)(CCM_CCGR7) = 0xFFFFFFFF;

    // **** NEEDS UPDATE for mx61 *****  //
    /* 
     * UART clock tree: PLL3 (480MHz) div-by-6: 80MHz
     * 80MHz uart_clk_podf (div-by-1) = 80MHz (UART module clock input)
     */

    /* Power up 480MHz PLL */
//    reg32_write_mask(HW_ANADIG_USB1_PLL_480_CTRL_RW, 0x00001000, 0x00001000);

    /* Enable 480MHz PLL */
//    reg32_write_mask(HW_ANADIG_USB1_PLL_480_CTRL_RW, 0x00002000, 0x00002000);

    /* UART clock is sourced from PLL3_80M 
     *   PLL3_80M is div-by-6 from PLL3 480MHz
     *   However, even though this is the default
     *   make sure div-by-6 is set 
     *   It appears that these dividers are not programmable
     */

    /*  UART clock is divided down from PLL3_80M
     * Defalut is div-by-1, but set to make sure
     *   CSCDR1: uart_clk_podf
     */
    reg32_write_mask(CCM_CSCDR1, 0x00000000, 0x0000003F);

    /* Ensure UART clock is not gated, bits[27:26] and bits[25:24] of CCGR5 */
    reg32_write_mask(CCM_CCGR5, 0x0F000000, 0x0F000000);

    /* Populate module frequency settings (important for UART driver) */
    for (i = 0; (tmp = mx61_module[i]) != NULL; i++) {
        tmp->freq = get_freq(tmp->base);
    }

    /* config IPU hsp clock, derived from AXI B */
//    temp = *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCMR);
//    temp &= ~(0x000000C0);
//    temp |= 0x00000040;
//    *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCMR) = temp;
    /* now set perclk_pred1 to div-by-2 */
//    temp = *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCDR);
//    temp &= ~(0x00380000);
//    temp |= 0x00080000;
//    *(volatile uint32_t *)(CCM_BASE_ADDR + CLKCTL_CBCDR) = temp;
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int32_t i;
    struct hw_module *tmp;
    printf("========== clock frequencies(HZ)\n");

    for (i = 0; (tmp = mx61_module[i]) != NULL; i++) {
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
    uint32_t num_rows = 1, num_cols = 1, num_dsiz = 1, i = 1;
    printf("========== DDR configuration \n");
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
    printf("==================================\n\n");
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
 /*NA*/}

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

void debug_uart_iomux(void)
{
    // iMX6x uses UART4
    if (BOARD_TYPE_ID == BOARD_ID_MX61_ARD) {
        // UART4 mux'd on txd->KEY_COL0 and rxd<-KEY_ROW0 ALT4
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_KEY_COL0);
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0);
        // daisy chain setup
        writel(0x1, IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT);
    } else {                    //SMD_BOARD
        // UART1 mux'd on CSI0_DAT10<=>TXD and CSI0_DAT11<=>RXD
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT10);
        writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT11);
        // daisy chain setup
        writel(0x1, IOMUXC_UART1_IPP_UART_RXD_MUX_SELECT_INPUT);
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
    unsigned int val = 0;
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
    /* set up debug UART iomux */
    debug_uart_iomux();
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
