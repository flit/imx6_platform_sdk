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
#include "functions.h"
#include "imx_spi.h"
#include "imx_i2c.h"
#include "imx_sata.h"

extern void init_clock(u32 rate);
extern int board_id;

#define ON 1
#define OFF 0

// ARM core is a special case. Assign 0 to it.
struct hw_module core = {
    "ARM",
    0,
};

// imx61 UART4 is debug_uart port
struct hw_module uart4 = {
    "UART4",
    UART4_BASE_ADDR,
};

struct hw_module ddr = {
    "DDR",
    MMDC_P0_BASE_ADDR,
};

struct hw_module *mx61_module[] = {
    &core,
    &ddr,
    &uart4,
    NULL,
};

unsigned int mx61_gpio[] = {
    GPIO1_BASE_ADDR,
    GPIO2_BASE_ADDR,
    GPIO3_BASE_ADDR,
    GPIO4_BASE_ADDR,
    GPIO5_BASE_ADDR,
    GPIO6_BASE_ADDR,
    GPIO7_BASE_ADDR
};

#define REF_IN_CLK_NUM  4
struct fixed_pll_mfd {
    u32 ref_clk_hz;
    u32 mfd;
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
int gpio_dir_config(int port, int pin, int dir)
{
    unsigned int oldVal = 0, newVal = 0;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    oldVal = readl(mx61_gpio[port] + GPIO_GDIR0_OFFSET);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    writel(newVal, mx61_gpio[port] + GPIO_GDIR0_OFFSET);
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
int gpio_write_data(int port, int pin, unsigned int attr)
{
    int dir;
    unsigned int oldVal = 0, newVal = 0;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(mx61_gpio[port] + GPIO_GDIR0_OFFSET) & (1 << pin)) >> pin;

    if (dir != 1) {
        printf("GPIO%d_%d is not configured to be output!\n", port + 1, pin);
        return -1;
    }

    oldVal = readl(mx61_gpio[port] + GPIO_DR0_OFFSET);

    if (attr == 0)
        newVal = oldVal & (~(1 << pin));
    else if (attr == 1)
        newVal = oldVal | (1 << pin);

    writel(newVal, mx61_gpio[port] + GPIO_DR0_OFFSET);
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
int gpio_read_data(int port, int pin)
{
    int dir;

    if ((port >= 7) || (port < 0)) {
        printf("Wrong GPIO Port[%d] Input! [1~7] Is Allowed!\n", port);
        return -1;
    }

    if ((pin > 31) || (pin < 0)) {
        printf("Wrong GPIO Pin[%d] Input! [1~32] Is Allowed!\n", pin);
        return -1;
    }

    dir = (readl(mx61_gpio[port] + GPIO_GDIR0_OFFSET) & (1 << pin)) >> pin;

    if (dir != 0) {
        printf("GPIO%d_%d is not configured to be input!\n", port + 1, pin);
        return -1;
    }

    return (readl(mx61_gpio[port] + GPIO_DR0_OFFSET) & (1 << pin)) >> pin;
}

/*!
 * Retrieve the freq info based on the passed in module_base.
 * @param   module_base     the base address of the module
 * @return  frequency in hz (0 means not a valid module)
 */
u32 get_freq(u32 module_base)
{
    if (module_base == 0)       // as ARM Core doesn't have a module base per se, it is set to 0
        //return get_main_clock(CPU_CLK);
        return 1000000000;
    else if (module_base == MMDC_P0_BASE_ADDR)
        //return get_main_clock(DDR_CLK);
        return 400000000;
    else if (module_base == UART4_BASE_ADDR)
        //return get_peri_clock(UART4_BAUD);
        return 80000000;
    else {
        printf("Not a valid module base \n");
        return 0;
    }
}

#define HW_ANADIG_PLL_ETH_CTRL        (ANATOP_BASE_ADDR+0x0e0)
/*!
 * Retrieve the clocks based on the hardware configuration and fill in the freq
 * info in each module's structure.
 */
void freq_populate(void)
{
    int i;
    volatile unsigned int temp;
    struct hw_module *tmp;
    //ETHNET
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);    /*power down bit */
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);    /*enable bit */
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);    /*bypass bit */
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x3, 0x3); /*divide bits */
    /* Ungate clocks to all modules */
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR0_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR1_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR2_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR3_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR4_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR5_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR6_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR7_OFFSET) = 0xFFFFFFFF;
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
//    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR);
//    temp &= ~(0x000000C0);
//    temp |= 0x00000040;
//    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR) = temp;
    /* now set perclk_pred1 to div-by-2 */
//    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR);
//    temp &= ~(0x00380000);
//    temp |= 0x00080000;
//    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR) = temp;
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int i;
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
    u32 temp1, dsiz, row, col, cs_info;
    u32 temp2, num_banks, ddr_type;
    u32 density;
    u32 megabyte;
    u32 num_rows = 1, num_cols = 1, num_dsiz = 1, i = 1;
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
void io_cfg_i2c(u32 module_base)
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

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
    unsigned int val = 0;

    init_clock(32768);
    /* set up debug UART iomux */
    debug_uart_iomux();
}
