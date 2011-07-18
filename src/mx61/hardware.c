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

extern void AUDMUXRoute(int intPort, int extPort, int Master);  // defined in ssi.c driver
extern void init_clock(u32 rate);
extern int board_id;
extern sata_phy_ref_clk_t sata_phy_clk_sel;

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
const struct fixed_pll_mfd fixed_mfd[REF_IN_CLK_NUM] = {
    {0, 0},                     // reserved
    {0, 0},                     // reserved
    {FREQ_24MHZ, 24 * 16},      // 384
    {0, 0},                     // reserved
};

static volatile u32 *pll_base[] = {
    REG32_PTR(PLL1_BASE_ADDR),
    REG32_PTR(PLL2_BASE_ADDR),
    REG32_PTR(PLL3_BASE_ADDR),
    REG32_PTR(PLL4_BASE_ADDR),
};

/* Boot mode status registers in the SRC */
struct soc_sbmr1 {
    unsigned int boot_cfg1:8, boot_cfg2:8, boot_cfg3:8, boot_cfg4:8;
} __attribute__ ((packed));
struct soc_sbmr1 *soc_sbmr1 = (struct soc_sbmr1 *)(SRC_BASE_ADDR + 0x4);

struct soc_sbmr2 {
    unsigned int sec_config:2,
        rsv0:1, dir_bt_dis:1, bt_fuse_sel:1, rsv1:19, bmod:2, rsv2:1, test_mode:3, rsv3:2;
} __attribute__ ((packed));
struct soc_sbmr2 *soc_sbmr2 = (struct soc_sbmr2 *)(SRC_BASE_ADDR + 0x1C);

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
 * This function returns the low power audio clock.
 */
u32 get_lp_apm(void)
{
    u32 ret_val = 0;
    u32 ccsr = readl(CCM_BASE_ADDR + CLKCTL_CCSR);

    if (((ccsr >> 10) & 1) == 0) {
        ret_val = FREQ_24MHZ;
    } else {
        ret_val = pll_clock(PLL4);
    }

    return ret_val;
}

/*!
 * This function returns the periph_clk.
 */
u32 get_periph_clk(void)
{
    u32 ret_val = 0, clk_sel;
    u32 cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    u32 cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);

    if (((cbcdr >> 25) & 1) == 0) {
        ret_val = pll_clock(PLL2);
    } else {
        clk_sel = (cbcmr >> 12) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1);
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL3);
        } else if (clk_sel == 2) {
            ret_val = get_lp_apm();
        }
    }

    return ret_val;
}

/*!
 * This function returns the PLL output value in Hz based on pll.
 */
u32 pll_clock(enum plls pll)
{
    u64 mfi, mfn, mfd, pdf, ref_clk, pll_out, sign;
    u64 dp_ctrl, dp_op, dp_mfd, dp_mfn, clk_sel;
    u8 dbl = 0;
    dp_ctrl = pll_base[pll][PLL_DP_CTL >> 2];
    clk_sel = MXC_GET_FIELD(dp_ctrl, 2, 8);
    ref_clk = fixed_mfd[clk_sel].ref_clk_hz;

    if ((pll_base[pll][PLL_DP_CTL >> 2] & 0x80) == 0) {
        dp_op = pll_base[pll][PLL_DP_OP >> 2];
        dp_mfd = pll_base[pll][PLL_DP_MFD >> 2];
        dp_mfn = pll_base[pll][PLL_DP_MFN >> 2];
    } else {
        dp_op = pll_base[pll][PLL_DP_HFS_OP >> 2];
        dp_mfd = pll_base[pll][PLL_DP_HFS_MFD >> 2];
        dp_mfn = pll_base[pll][PLL_DP_HFS_MFN >> 2];
    }

    pdf = dp_op & 0xF;
    mfi = (dp_op >> 4) & 0xF;
    mfi = (mfi <= 5) ? 5 : mfi;
    mfd = dp_mfd & 0x07FFFFFF;
    mfn = dp_mfn & 0x07FFFFFF;
    sign = (mfn < 0x4000000) ? 0 : 1;
    mfn = (mfn <= 0x4000000) ? mfn : (0x8000000 - mfn);
    dbl = ((dp_ctrl >> 12) & 0x1) + 1;
    dbl = dbl * 2;

    if (sign == 0) {
        pll_out = (dbl * ref_clk * mfi + ((dbl * ref_clk * mfn) / (mfd + 1))) / (pdf + 1);
    } else {
        pll_out = (dbl * ref_clk * mfi - ((dbl * ref_clk * mfn) / (mfd + 1))) / (pdf + 1);
    }

    return (u32) pll_out;
}

/*!
 * This function returns the emi_core_clk_root clock.
 */
u32 get_emi_core_clk(void)
{
    u32 cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    u32 clk_sel = 0, max_pdf = 0, peri_clk = 0, ahb_clk = 0;
    u32 ret_val = 0;
    max_pdf = (cbcdr >> 10) & 0x7;
    peri_clk = get_periph_clk();
    ahb_clk = peri_clk / (max_pdf + 1);
    clk_sel = (cbcdr >> 26) & 1;

    if (clk_sel == 0) {
        ret_val = peri_clk;
    } else {
        ret_val = ahb_clk;
    }

    return ret_val;
}

/*!
 * This function returns the main clock value in Hz.
 */
u32 get_main_clock(enum main_clocks clk)
{
    u32 pdf, max_pdf, ipg_pdf, nfc_pdf, clk_sel;
    u32 pll, ret_val = 0;
    u32 cacrr = readl(CCM_BASE_ADDR + CLKCTL_CACRR);
    u32 cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    u32 cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);
    u32 cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    u32 cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);

    switch (clk) {
    case CPU_CLK:
        pdf = cacrr & 0x7;
        pll = pll_clock(PLL1);
        ret_val = pll / (pdf + 1);
        break;
    case AHB_CLK:
        max_pdf = (cbcdr >> 10) & 0x7;
        pll = get_periph_clk();
        ret_val = pll / (max_pdf + 1);
        break;
    case IPG_CLK:
        max_pdf = (cbcdr >> 10) & 0x7;
        ipg_pdf = (cbcdr >> 8) & 0x3;
        pll = get_periph_clk();
        ret_val = pll / ((max_pdf + 1) * (ipg_pdf + 1));
        break;
    case IPG_PER_CLK:
        clk_sel = cbcmr & 1;

        if (clk_sel == 0) {
            clk_sel = (cbcmr >> 1) & 1;
            pdf = (((cbcdr >> 6) & 3) + 1) * (((cbcdr >> 3) & 7) + 1) * ((cbcdr & 7) + 1);

            if (clk_sel == 0) {
                ret_val = get_periph_clk() / pdf;
            } else {
                ret_val = get_lp_apm() / pdf;
            }
        } else {
            /* Same as IPG_CLK */
            max_pdf = (cbcdr >> 10) & 0x7;
            ipg_pdf = (cbcdr >> 8) & 0x3;
            pll = get_periph_clk();
            ret_val = pll / ((max_pdf + 1) * (ipg_pdf + 1));
        }

        break;
    case DDR_CLK:
        clk_sel = (cbcmr >> 10) & 3;
        pll = get_periph_clk();

        if (clk_sel == 0) {
            /* AXI A */
            pdf = (cbcdr >> 16) & 0x7;
        } else if (clk_sel == 1) {
            /* AXI B */
            pdf = (cbcdr >> 19) & 0x7;
        } else if (clk_sel == 2) {
            /* EMI SLOW CLOCK ROOT */
            pll = get_emi_core_clk();
            pdf = (cbcdr >> 22) & 0x7;
        } else if (clk_sel == 3) {
            /* AHB CLOCK */
            pdf = (cbcdr >> 10) & 0x7;
        }

        ret_val = pll / (pdf + 1);
        break;
    case NFC_CLK:
        pdf = (cbcdr >> 22) & 0x7;
        nfc_pdf = (cbcdr >> 13) & 0x7;
        pll = get_emi_core_clk();
        ret_val = pll / ((pdf + 1) * (nfc_pdf + 1));
        break;
    case USB_CLK:
        clk_sel = (cscmr1 >> 22) & 3;

        if (clk_sel == 0) {
            pll = pll_clock(PLL1);
        } else if (clk_sel == 1) {
            pll = pll_clock(PLL2);
        } else if (clk_sel == 2) {
            pll = pll_clock(PLL3);
        } else if (clk_sel == 3) {
            pll = get_lp_apm();
        }

        pdf = (cscdr1 >> 8) & 0x7;
        max_pdf = (cscdr1 >> 6) & 0x3;
        ret_val = pll / ((pdf + 1) * (max_pdf + 1));
        break;
    case VPU_CLK:
        clk_sel = (cbcmr >> 14) & 3;
        pll = get_periph_clk();

        if (clk_sel == 0) {
            /* AXI A */
            pdf = (cbcdr >> 16) & 0x7;
        } else if (clk_sel == 1) {
            /* AXI B */
            pdf = (cbcdr >> 19) & 0x7;
        } else if (clk_sel == 2) {
            /* EMI SLOW CLOCK ROOT */
            pll = get_emi_core_clk();
            pdf = (cbcdr >> 22) & 0x7;
        } else if (clk_sel == 3) {
            /* AHB CLOCK */
            pdf = (cbcdr >> 10) & 0x7;
        }

        ret_val = pll / (pdf + 1);
        break;
    default:
        printf("Unknown clock: %d\n", clk);
        break;
    }

    return ret_val;
}

/*!
 * This function returns the peripheral clock value in Hz.
 */
u32 get_peri_clock(enum peri_clocks clk)
{
    u32 ret_val = 0, pdf, pre_pdf, clk_sel;
    u32 cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    u32 cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);
    u32 cscdr2 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR2);
    u32 cs1cdr = readl(CCM_BASE_ADDR + CLKCTL_CS1CDR);
    u32 cs2cdr = readl(CCM_BASE_ADDR + CLKCTL_CS2CDR);

    switch (clk) {
    case UART1_BAUD:
    case UART2_BAUD:
    case UART3_BAUD:
        pre_pdf = (cscdr1 >> 3) & 0x7;
        pdf = cscdr1 & 0x7;
        clk_sel = (cscmr1 >> 24) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = get_lp_apm() / ((pre_pdf + 1) * (pdf + 1));
        }

        break;
    case UART4_BAUD:           // NEED TO FIX THIS LATER
        ret_val = 80000000;
    case SSI1_BAUD:
        pre_pdf = (cs1cdr >> 6) & 0x7;
        pdf = cs1cdr & 0x3F;
        clk_sel = (cscmr1 >> 14) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = CKIH / ((pre_pdf + 1) * (pdf + 1));
        }

        break;
    case SSI2_BAUD:
        pre_pdf = (cs2cdr >> 6) & 0x7;
        pdf = cs2cdr & 0x3F;
        clk_sel = (cscmr1 >> 12) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 0x2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = CKIH / ((pre_pdf + 1) * (pdf + 1));
        }

        break;
    case SPI1_CLK:
    case SPI2_CLK:
#ifndef MX61_ARD
        pre_pdf = (cscdr2 >> 25) & 0x7;
        pdf = (cscdr2 >> 19) & 0x3F;
        clk_sel = (cscmr1 >> 4) & 3;

        if (clk_sel == 0) {
            ret_val = pll_clock(PLL1) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 1) {
            ret_val = pll_clock(PLL2) / ((pre_pdf + 1) * (pdf + 1));
        } else if (clk_sel == 2) {
            ret_val = pll_clock(PLL3) / ((pre_pdf + 1) * (pdf + 1));
        } else {
            ret_val = get_lp_apm() / ((pre_pdf + 1) * (pdf + 1));
        }
#else
        //TODO
        pdf = (cscdr2 >> 19) & 0x3F;
        ret_val = 60000000 / (pdf + 1);
#endif
        break;
    default:
        printf("%s(): This clock: %d not supported yet \n", __FUNCTION__, clk);
        break;
    }

    return ret_val;
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
        return 0;
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
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
        writel(0x100B1, IOMUXC_SW_PAD_CTL_PAD_EIM_D18);
        writel(0x00, IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT);

        // MISO
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
        writel(0x100B1, IOMUXC_SW_PAD_CTL_PAD_EIM_D17);
        writel(0x00, IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT);

        if (dev->ss == 0) {
            // de-select SS1
            writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
            writel(0x1B0B0, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
            // Select mux mode: ALT1 for SS0
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_EB2);
            writel(0x100B1, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);
            writel(0x00, IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT);
        } else if (dev->ss == 1) {
            // de-select SS0
            writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB2);
            writel(0x1B0B0, IOMUXC_SW_PAD_CTL_PAD_EIM_EB2);
            // Select mux mode: ALT4 for SS1
            writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
            writel(0x100B1, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
            writel(0x00, IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT);
        }
        // SCLK
        writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_EIM_D16);
        writel(0x100B1, IOMUXC_SW_PAD_CTL_PAD_EIM_D16);
        writel(0x00, IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT);

        break;
    case ECSPI2_BASE_ADDR:
    default:
        break;
    }
}

/*
 *set up the clock for nand
 */

void gpmi_nand_clk_setup(void)
{
    *(volatile u32 *)(HW_ANADIG_PFD_528_RW) &= ~(0x00800000);
    *(volatile u32 *)(CCM_CCGR4) &= ~(0xff000000);
    *(volatile u32 *)(CCM_CS2CDR) &= ~(0x00030000);
    *(volatile u32 *)(CCM_CS2CDR) |= 0x00020000;
    *(volatile u32 *)(CCM_CS2CDR) &= ~(0x07fc0000);
    *(volatile u32 *)(CCM_CS2CDR) |= ((u32) (4 << 18) | (3 << 21));
    *(volatile u32 *)(CCM_CCGR4) |= 0xff000000;
    *(volatile u32 *)(CCM_CCGR6) |= 0x000003c0;
    *(volatile u32 *)(CCM_CCGR0) |= 0x00000030;
}

/*!
  * Set up the IOMUX for NAND
  */
void gpmi_nand_pinmux_config(void)
{
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B);
    /*RE_N, WR_N */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_CLK);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_CLK);
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_CMD);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_CMD);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0);
    writel(0xf0e0, IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3);
    /*nand D0-D7  */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D0);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D1);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D1);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D2);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D2);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D3);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D3);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D4);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D4);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D5);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D5);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D6);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D6);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_NANDF_D7);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_NANDF_D7);
    /*NAND D8~D15, may not used */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT0);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT1);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT3);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT4);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT4);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT5);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT5);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT6);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT6);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT7);
    writel(0x100b1, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT7);
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

/* Power up the SGTL and initialize it's clock if necessary */
void SGTL5000PowerUp_and_clockinit(void)
{
    unsigned int val = 0;

    if (board_id == BOARD_ID_MX53_SBRTH_SMD) {
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
int SSI_iomux(void)
{
    /* Select ALT2 mode of KEY_ROW1 for AUD5_RXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW1);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT);    //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW1);
    /* Select ALT2 mode of KEY_ROW0 for AUD5_TXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0);
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0);
    /* Select ALT2 mode of KEY_COL0 for AUD5_TXC */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_COL0);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT); //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_COL0);
    /* Select ALT2 mode of KEY_COL1 for AUD5_TXFS */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_COL1);
    writel(0x0, IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT);  //daisy chain
    writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_KEY_COL1);
    return 0;
}

/* Configure iomux for ESAI */
void esai_iomux(void)
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

#ifdef NO_NEED_FOR_SDK
/*USB_OTG_PWR and OC iomux configurations*/
void usb_io_config(void)
{
    //EIM_D31 for USBH1_PWR(GPIO3_30). DNP
    //EIM_D30 for USBH1_OC(GPIO3_31), DNP
    //EIM_D22 for OTG_PWR(GPIO3_22) or PORT3_P66
    //EIM_D21 for OTG_OC(GPIO3_21) or PORT3_P68

}

void usbh_set_to_ulpi_mode(usb_base_addr)
{
    // allow some time for the USB host to settle on new ULPI settings
    Wait100Ms();
}

/*  Enable/disable power to USB OTG port */
void usb_otg_set_power(int state)
{
    //EIM_D22 for OTG_PWR
}

/* USB host2 - PHY reset control */
void usb_host2_phy_rst(int state)
{
}

/*!
  * Check to see if UTMI clock is ready
  */
int is_utmi_clk_ready(void)
{
    //check UTMI PHY Clock Valid in USB HOST1 UTMI PHY Control register 0 bit 31
    while (!((*(volatile u32 *)(USBOH3_USB_BASE_ADDR + 0x81c)) & (0x1 << 31))) ;    //host1 utmi clock is not OK?
    return 1;
}
#endif

/* GPS iomux configuration */
void gps_io_config(void)
{
#ifdef GPS_SUPPORT
    /* Select ALT3 mode of PATA_BUFFER_EN for UART2_RX */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_BUFFER_EN);
    /* Select ALT3 mode of PATA_DMARQ for UART2_TX */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DMARQ);
    /* Select ALT3 mode of PATA_DIOR for UART2_RTS */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DIOR);
    /* Select ALT3 mode of PATA_INTRQ for UART2_CTS */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_INTRQ);
    /* Select ALT1 mode of PATA_DATA5 for GPIO2_5 - GPS_PWREN */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5);
    gpio_dir_config(GPIO_PORT2, 5, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT2, 5, GPIO_HIGH_LEVEL);
    /* Select ALT1 mode of PATA_DATA6 for GPIO2_6 - GPS_INT_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6);
    gpio_dir_config(GPIO_PORT2, 6, GPIO_GDIR_INPUT);
    /* _TO_DO_ : set trigger mode for this IRQ */
    /* _TO_DO_ : add GPS_RST_B through I/O expander and a function to control it */
    /* _TO_DO_ : add clock 32k output to the GPS module */
#endif
}

/* MLB iomux configuration */
void mlb_io_config(void)
{
#ifdef MLB_SUPPORT
    /* default board will use I2C3, but might be I2C2 */
    io_cfg_i2c(OS81050_I2C_BASE);
    /* Select ALT3 mode of FEC_MDC for MLB_DAT */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_FEC_MDC);
    /* Select ALT3 mode of FEC_TXD1 for MLB_CLK */
    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_FEC_TXD1);
    /* Select ALT7 mode of GPIO_6 for MLB_SIG */
    writel(ALT7, IOMUXC_SW_MUX_CTL_PAD_GPIO_6);
    /* MLB_PWRDN input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT15);
    gpio_dir_config(GPIO_PORT5, 9, GPIO_GDIR_INPUT);
#endif
}

/* CAN1 iomux configuration */
void can1_io_config(void)
{
#ifdef CAN1_IO_SUPPORT
    /* Select ALT2 mode of KEY_COL2 for CAN1_TXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    /* Select ALT2 mode of KEY_ROW2 for CAN1_RXD */
    writel(ALT2, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2);
    /* Select ALT1 mode of PATA_DATA0 for GPIO2_0 - CAN1_NERR_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0);
    gpio_dir_config(GPIO_PORT2, 0, GPIO_GDIR_INPUT);
    /* Select ALT1 mode of PATA_DA_0 for GPIO7_6 - CAN_EN */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0);
    gpio_dir_config(GPIO_PORT7, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT7, 0, GPIO_HIGH_LEVEL);
    /* Select ALT1 mode of KEY_ROW4 for GPIO4_15 - CAN_STBY */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4);
    gpio_dir_config(GPIO_PORT4, 15, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT4, 15, GPIO_HIGH_LEVEL);
#endif
}

/* CAN2 iomux configuration */
void can2_io_config(void)
{
#ifdef CAN2_IO_SUPPORT
    /* Select ALT4 mode of PATA_RST_B for CAN2_TXD */
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_PATA_RESET_B);
    /* Select ALT4 mode of PATA_IORDY for CAN2_RXD */
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_PATA_IORDY);
    /* Select ALT1 mode of PATA_DATA1 for GPIO2_1 - CAN2_NERR_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1);
    gpio_dir_config(GPIO_PORT2, 1, GPIO_GDIR_INPUT);
#endif
}

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
    //VOL-_(SD3_RST_GPI7_8)
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD3_RST, ALT5);   //GPIO7[8]
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD3_RST, 0x00E0); // pull-up enabled at pad
}

/* CSI iomux configurations from deserializer*/
void csi_iomux_config(void)
{
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_PIXCLK);
    /* ATL0 is actually CSI0_HSYNC */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_MCLK);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_VSYNC);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT4);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT5);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT6);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT7);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT8);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT9);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT10);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT11);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT12);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT13);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT14);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT15);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT16);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT17);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT18);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_CSI0_DAT19);
}

/*  I/O config for the DS90UR124QVS - LVDS camera in */
void deserializer_io_config(void)
{
    /* REN and RPWDB controlled by ADV7180 configured in the driver */
    csi_iomux_config();
}

#ifdef VIDEO_IN_SUPPORT
/*  I/O config for the ADV7180 - video in */
void video_in_io_config(void)
{
    /* Interrupt signal from controller */
    /* Select ALT1 mode of GPIO_7 for GPIO1_7 */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_GPIO_7);
    gpio_dir_config(GPIO_PORT1, 7, GPIO_GDIR_INPUT);

    /* Power down - use PATA_DATA2 as active low output */
    /* Select ALT1 mode of PATA_DATA2 for GPIO2_2 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2);
    gpio_dir_config(GPIO_PORT2, 2, GPIO_GDIR_OUTPUT);
    /* Keep ADV7180 powered, as it is after board power up */
    gpio_write_data(GPIO_PORT2, 2, GPIO_HIGH_LEVEL);

    csi_iomux_config();
}

/*  Enable/disable power to ADV7180 - video in */
void video_in_set_power(int state)
{
    /* Power down - active low output */
    gpio_write_data(GPIO_PORT2, 2, state);
}
#endif

/* WEIM iomux configurations for NOR flash */
// hysteresis en, PU 100k, speed 100Mhz, DS 40ohm, fast slew rate
#define PAD_CTL_WEIM_DATA 0x1B0B1
// PU 100k, speed 100Mhz, DS 40ohm, fast slew rate
#define PAD_CTL_WEIM_ADDR 0xB0B1
// PU 100k, speed 100Mhz, DS 40ohm, fast slew rate
#define PAD_CTL_WEIM_CTRL 0xB0B1
void weim_iomux_config(void)
{
    /* Data bus */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA0);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA0);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA1);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA1);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA2);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA2);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA3);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA3);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA4);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA4);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA5);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA5);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA6);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA6);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA7);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA7);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA8);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA8);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA9);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA9);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA10);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA10);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA11);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA11);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA12);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA12);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA13);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA13);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA14);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA14);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_DA15);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_DA15);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D16);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D16);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D17);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D17);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D18);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D18);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D19);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D19);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D20);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D20);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D21);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D21);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D22);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D22);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D23);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D23);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D24);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D24);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D25);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D25);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D26);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D26);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D27);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D27);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D28);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D28);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D29);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D29);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D30);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D30);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_D31);
    writel(PAD_CTL_WEIM_DATA, IOMUXC_SW_PAD_CTL_PAD_EIM_D31);
    /* Address bus */
    /* Address from 0 to 15 configured with NFC */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A16);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A16);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A17);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A17);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A18);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A18);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A19);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A19);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A20);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A20);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A21);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A21);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A22);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A22);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_A23);
    writel(PAD_CTL_WEIM_ADDR, IOMUXC_SW_PAD_CTL_PAD_EIM_A23);
    /* Control signals */
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_OE);
    writel(PAD_CTL_WEIM_CTRL, IOMUXC_SW_PAD_CTL_PAD_EIM_OE);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_RW);
    writel(PAD_CTL_WEIM_CTRL, IOMUXC_SW_PAD_CTL_PAD_EIM_RW);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT);
    writel(PAD_CTL_WEIM_CTRL, IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT);
    writel(ALT0, IOMUXC_SW_MUX_CTL_PAD_EIM_CS0);
    writel(PAD_CTL_WEIM_CTRL, IOMUXC_SW_PAD_CTL_PAD_EIM_CS0);
}

/* set up the chip select registers for the weim "parallel" nor flash*/
void weim_nor_flash_cs_setup(void)
{
    /* DSIZ=010 (map 16-bit to D[31:16], csen=1 */
    writel(0x00020001, WEIM_REGISTERS_BASE_ADDR + 0x000);

    /* CS0 Read Config reg1 */
    /* RWCS=11, OEA=2, OEN=1 */
    writel(0x0B002100, WEIM_REGISTERS_BASE_ADDR + 0x008);

    /* CS0 Write Config Reg 1 */
    /* WWCS=11, WEA=2, WEN=1 */
    writel(0x0B000440, WEIM_REGISTERS_BASE_ADDR + 0x010);
}

/*!
 * ldb iomux configurations
 */
void ldb_iomux_config(void)
{
    //no iomux for LDB on i.Mx6q
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

/* ENET iomux config */
void imx_enet_iomux(void)
{
    /*ENET_MDIO */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_KEY_COL1);
    writel(0x10870, IOMUXC_SW_PAD_CTL_PAD_KEY_COL1);
    writel(0x0, IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT);
    /*ENET_MDC */
    writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    writel(0x10870, IOMUXC_SW_PAD_CTL_PAD_KEY_COL2);
    /* ENET RDATA[0] */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_RXD0);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_RXD0);
    writel(0x1, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT);
    /* ENET RDATA[1] */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_RXD1);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_RXD1);
    writel(0x1, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT);
    /* ENET CRS_DV */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV);
    writel(0x1, IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT);
    /* ENET TDATA[0] */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_TXD0);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_TXD0);
    /* ENET TDATA[1] */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_TXD1);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_TXD1);
    /* ENET TX_EN */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_TX_EN);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_TX_EN);
    /* ENET REF_CLK */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK);
    /* ENET RX_ER */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER);
    writel(0x1B0B1, IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER);
}

void imx_ar8031_iomux()
{
    /*ENET_MDC */
    writel(0x4, 0x020e0208 /*IOMUXC_SW_MUX_CTL_PAD_KEY_COL2 */ );
    writel(0xb0, 0x020e05d8 /*IOMUXC_SW_PAD_CTL_PAD_KEY_COL2 */ );

    /*ENET_MDIO */
    writel(0x1, 0x020e0200 /*IOMUXC_SW_MUX_CTL_PAD_KEY_COL1 */ );
    writel(0x1b0b0, 0x020e05d0 /*IOMUXC_SW_PAD_CTL_PAD_KEY_COL1 */ );
    writel(0x1, 0x020e0840 /*IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT */ );

    /*RGMII_TXC */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TXC);
    /*RGMII_TD0 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TD0);
    /*RGMII_TD1 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TD1);
    /*RGMII_TD2 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TD2);
    /*RGMII_TD3 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TD3);
    /*RGMII_TX_CTL */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_TX_CTL);

    /*RGMII_RXC */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RXC);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXCLK_SELECT_INPUT);
    /*RGMII_RD0 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RD0);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT);
    /*RGMII_RD1 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RD1);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT);
    /*RGMII_RD2 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RD2);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_2_SELECT_INPUT);
    /*RGMII_RD3 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RD3);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT);
    /*RGMII_RX_CTL */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_RGMII_RX_CTL);
    writel(0, IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT);

    reg32_write(IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK, ALT1);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK, 0x000190F0);

    reg32_write(IOMUXC_SW_PAD_CTL_GRP_DDR_TYPE_RGMII, 0xc0000);

}

/*CPU_PER_RST_B low to high*/
void imx_ar8031_reset(void)
{
    //max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    //hal_delay_us(1000000);
    //max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
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
 *  For mx61 arik sd4 io configure
 */
void mxc_mmc_init(unsigned int base_address)
{
    switch (base_address) {
    case USDHC1_BASE_ADDR:
        printf("Configure SD1 io - do nothing\n");
        break;

    case USDHC2_BASE_ADDR:
        printf("Configure SD2 io - do nothing\n");
        break;

    case USDHC3_BASE_ADDR:
        printf("Configure SD3 io\n");

        /* CMD */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_CMD);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_CMD);

        /* CLK */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_CLK);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_CLK);

        /* DATA0 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0);

        /* DATA1 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1);

        /* DATA2 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2);

        /* DATA3 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3);

        /* DATA4 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT4);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT4);

        /* DATA5 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT5);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT5);

        /* DATA6 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT6);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT6);

        /* DATA7 */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD3_DAT7);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD3_DAT7);
        break;

    case USDHC4_BASE_ADDR:
        printf("Configure SD4 io\n");

        /* CMD */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_CMD);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_CMD);

        /* CLK */
        writel(0x10 | ALT0, IOMUXC_SW_MUX_CTL_PAD_SD4_CLK);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_CLK);

        /* DATA0 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT0);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT0);

        /* DATA1 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT1);

        /* DATA2 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2);

        /* DATA3 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT3);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT3);

        /* DATA4 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT4);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT4);

        /* DATA5 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT5);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT5);

        /* DATA6 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT6);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT6);

        /* DATA7 */
        writel(0x10 | ALT1, IOMUXC_SW_MUX_CTL_PAD_SD4_DAT7);
        writel(0x1F4, IOMUXC_SW_PAD_CTL_PAD_SD4_DAT7);
        break;

    default:
        printf("MMC slot is not supported.\n");
        break;
    }
}

/*IOMUX configuration for CSI port0*/
void mxc_csi_port0_iomux_config(void)
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

#ifdef NO_NEED_FOR_SDK
/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
}

/*!
 * USB module clock enable function
 */
void usb_clock_enable(void)
{
    //*(volatile u32 *)(CCM_CCGR2) |= 0x3C000000; //enable USBOH3_IPG_AHB, USBOH3_60M
    //*(volatile u32 *)(CCM_CCGR4) |= 0x00003C00; //enable PHY1 and PHY2 clock
}

/*!
 * USB VBUS power on, PATA_DA_2(GPIO7_8)
 */
void usb_vbus_power_on(void)
{

}
#endif

#ifdef NO_NEED_FOR_SDK
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
#endif

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
    unsigned int val = 0;

    init_clock(32768);
    /* set up debug UART iomux */
    debug_uart_iomux();

#ifdef NO_NEED_FOR_SDK
    /* Set up the digital audio mux here.   */
// to verify for i.MX61
    //AUDMUXRoute(2, 5, 0);

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
 *  Display boot switch information
 */
void show_boot_switch_info(void)
{
    printf("========== BOOT configuration \n");
    printf("Security config: ");

    if (soc_sbmr2->sec_config == 0) {
        printf("FAB (Open)\n");
    } else if (soc_sbmr2->sec_config == 0x1) {
        printf("Open -allows any code to be flashed & executed (even without valid signature)\n");
    } else {
        printf("Closed (Security On)\n");
    }

    printf("Boot From: ");

    switch ((soc_sbmr1->boot_cfg1 >> 4) & 0xF) {
    case 0x0:
        printf("WEIM: ");
        if ((soc_sbmr1->boot_cfg1 & 0x08) == 0)
            printf("NOR");
        else
            printf("ONE NAND");
        break;
    case 0x1:
        printf("Reserved !!!");
        break;
    case 0x2:
        printf("SATA Hard drive: ");
        if ((soc_sbmr1->boot_cfg2 & 0x4) == 0)
            printf("GEN 2 (3.0Gbps)");
        else
            printf("GEN 1 (1.5Gbps)");
        break;
    case 0x3:
        printf("Serial ROM: ");
        if ((soc_sbmr1->boot_cfg1 & 0x2) == 0)
            printf("I2C EEPROM: ");
        else
            printf("SPI NOR: CS#%d ", (soc_sbmr1->boot_cfg4 >> 4) & 0x3);
        switch (soc_sbmr1->boot_cfg4 & 0x7) {
        case 0x0:
            printf("on eCSPI1");
            break;
        case 0x1:
            printf("on eCSPI2");
            break;
        case 0x2:
            printf("on eCSPI3");
            break;
        case 0x3:
            printf("on eCSPI4");
            break;
        case 0x4:
            printf("on eCSPI5");
            break;
        case 0x5:
            printf("on I2C-1");
            break;
        case 0x6:
            printf("on I2C-2");
            break;
        case 0x7:
            printf("on I2C-3");
            break;
        }
        break;
    case 0x4:
    case 0x5:
        printf("SD/eSD/SDXC: ");
        if ((soc_sbmr1->boot_cfg1 & 0x10) == 0)
            printf("normal boot: ");
        else
            printf("fast boot: ");
        printf("speed ");
        if ((soc_sbmr1->boot_cfg1 & 0x0C) == 0)
            printf("SDR12: ");
        else if ((soc_sbmr1->boot_cfg1 & 0x0C) == 0x04)
            printf("SDR25: ");
        else if ((soc_sbmr1->boot_cfg1 & 0x0C) == 0x08)
            printf("SDR50: ");
        else
            printf("SDR104: ");
        printf("bus width ");
        if ((soc_sbmr1->boot_cfg2 & 0xE0) == 0)
            printf("1-bit on ");
        else
            printf("4-bit on ");
        if ((soc_sbmr1->boot_cfg2 & 0x18) == 0)
            printf("USDHC1");
        else if ((soc_sbmr1->boot_cfg2 & 0x18) == 0x8)
            printf("USDHC2");
        else if ((soc_sbmr1->boot_cfg2 & 0x18) == 0x10)
            printf("USDHC3");
        else
            printf("USDHC4");
        break;
    case 0x6:
    case 0x7:
        printf("MMC/eMMC: ");
        if ((soc_sbmr1->boot_cfg1 & 0x10) == 0)
            printf("normal boot: ");
        else
            printf("fast boot: ");
        if ((soc_sbmr1->boot_cfg1 & 0x08) == 0)
            printf("normal speed: ");
        else
            printf("fast speed: ");
        printf("bus width ");
        if ((soc_sbmr1->boot_cfg1 & 0xE0) == 0)
            printf("1-bit on ");
        else if ((soc_sbmr1->boot_cfg1 & 0xE0) == 0x20)
            printf("4-bit on ");
        else if ((soc_sbmr1->boot_cfg1 & 0xE0) == 0x40)
            printf("8-bit on ");
        else if ((soc_sbmr1->boot_cfg1 & 0xE0) == 0xA0)
            printf("4-bit DDR on ");
        else if ((soc_sbmr1->boot_cfg1 & 0xE0) == 0xC0)
            printf("8-bit DDR on ");
        else
            printf("reserved on ");
        if ((soc_sbmr1->boot_cfg2 & 0x18) == 0)
            printf("USDHC1");
        else if ((soc_sbmr1->boot_cfg2 & 0x18) == 0x8)
            printf("USDHC2");
        else if ((soc_sbmr1->boot_cfg2 & 0x18) == 0x10)
            printf("USDHC3");
        else
            printf("USDHC4");
        break;
    case 0x8:
    default:
        printf("NAND: ADDR CYCLES %d: ", (soc_sbmr1->boot_cfg1 & 0x3) + 3);
        printf("%d device: ", 2 ^ ((soc_sbmr1->boot_cfg1 & 0xC) >> 2));
        if ((soc_sbmr1->boot_cfg2 & 0x06) == 0)
            printf("128 ");
        else if ((soc_sbmr1->boot_cfg2 & 0x06) == 0x2)
            printf("64 ");
        else if ((soc_sbmr1->boot_cfg2 & 0x06) == 0x4)
            printf("32 ");
        else
            printf("256 ");
        printf("page per blocks");
        break;
    }

    printf("\n==================================\n\n");
}

/*!
 * Program the board ID fuse
 * Note, if there is more than one board revision per ID, update the code
 * to prompt the user to enter the board revision number.
 *
 * @return  0 if successful; non-zero otherwise
 */
int board_id_fuse_program(void)
{
    int bank = 0;
    int row_id = 31;
    u32 temp;

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(ON);  // turn on fuse vdd voltage
#endif

    /* First, allow fuse programming in the CCM CGPR register by setting the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp |= 0x00000010;         // set bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    /* blow the fuse */
/*    fuse_blow_row(bank, row_id, BOARD_TYPE_ID);
    if (sense_fuse(bank, row_id) != BOARD_TYPE_ID) {
        printf("  ** Fuse read-back-verify failed, read back 0x%x, should be 0x%x\n",
               sense_fuse(bank, row_id), BOARD_TYPE_ID);
        return -1;
    }
*/
    /* Disable fuse programming in the CCM CGPR register by clearing the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp &= ~(0x00000010);      // clear bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(OFF); // turn off fuse vdd voltage
#endif

    printf("   Fuse programming successful \n");

    return 0;
}

/*!
 * Program the board revision efuse
 * Note, if there is more than one board revision per ID, update the code
 * to prompt the user to enter the board revision number.
 *
 * @return  0 if successful; non-zero otherwise
 */
int board_rev_fuse_program(void)
{
    int bank = 0;
    int row_rev = 30;
    unsigned int temp;

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(ON);  // turn on fuse vdd voltage
#endif

    /* First, allow fuse programming in the CCM CGPR register by setting the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp |= 0x00000010;         // set bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    /* blow the fuse */
/*    fuse_blow_row(bank, row_rev, BOARD_VERSION_ID);
    if (sense_fuse(bank, row_rev) != BOARD_VERSION_ID) {
        printf("  ** Fuse read-back-verify failed, read back 0x%x, should be: 0x%x\n",
               sense_fuse(bank, row_rev), BOARD_VERSION_ID);
        return -1;
    }
*/
    /* Disable fuse programming in the CCM CGPR register by clearing the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp &= ~(0x00000010);      // clear bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(OFF); // turn off fuse vdd voltage
#endif

    printf("   Fuse programming successful \n");

    return 0;
}

/*! Read the ENET MAC address fuses
 *
 * @param mac_data pointer to an array to store mac address read from the fuses
 *
 * @return  0 if successful; non-zero otherwise
 */
int read_mac(u8 * mac_data)
{
    mac_data[0] = readb(IIM_BASE_ADDR + 0xC24);
    mac_data[1] = readb(IIM_BASE_ADDR + 0xC28);
    mac_data[2] = readb(IIM_BASE_ADDR + 0xC2C);
    mac_data[3] = readb(IIM_BASE_ADDR + 0xC30);
    mac_data[4] = readb(IIM_BASE_ADDR + 0xC34);
    mac_data[5] = readb(IIM_BASE_ADDR + 0xC38);

    return 0;
}

/*! Program the ENET MAC address value to the hardware fuses
 *
 * @param   fuse_data pointer to an array with mac address to program to fuses
 *
 * @return  0 if successful; non-zero otherwise
 */
int program_mac(u8 * fuse_data)
{
    unsigned int temp;
    u32 bank_mac = 1;
    u32 row_mac = 9;
    int failcount = 0, i = 0;

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(ON);  // turn on fuse vdd voltage
#endif

    /* First, allow fuse programming in the CCM CGPR register by setting the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp |= 0x00000010;         // set bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    /* Proceed to program the MAC addr fuses */
    for (i = 0; i < 6; i++) {
//        fuse_blow_row(bank_mac, i + row_mac, fuse_data[i]);
    }
    /* Now sense the fuses to confirm the fuses were programmed correctly */
    for (i = 0; i <= 5; i++) {
/*        if (sense_fuse(bank_mac, row_mac + i) != fuse_data[i]) {
            printf("MAC%d doesn't match, it read 0x%02x, but it should be 0x%02x, \n", i,
                   sense_fuse(bank_mac, row_mac + 1), fuse_data[i]);
            failcount++;
            break;
        } else {
            printf("MAC%d programmed correctly \n", i);
        }
*/
    }

    /* Disable fuse programming in the CCM CGPR register by clearing the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp &= ~(0x00000010);      // clear bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(OFF); // turn off fuse vdd voltage
#endif

    if (failcount != 0)
        return 1;               // return failure

    return 0;
}

#ifdef NO_NEED_FOR_SDK
/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(char *panel_name)
{
#ifdef MX61_ARD
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_dir_config(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef MX61_SMD
    /*3.3V power supply through the load switch FDC6331L */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_D19, ALT5);
    gpio_dir_config(GPIO_PORT3, 19, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT3, 19, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_D0, ALT5);
    gpio_dir_config(GPIO_PORT2, 0, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT2, 0, GPIO_HIGH_LEVEL);
#endif
}
#endif

#ifdef MX61_SMD
void camera_power_on(unsigned int a_vdd, unsigned int do_vdd, unsigned int d_vdd)
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

/* dummy empty function for compatibility between i.MX53 and i.MX61 OBDS */
void hdmi_power_on(void)
{
}

/*! Turn on or off  the fuse VDD LDO voltage on the Linear LTC3589
 *
 * @param on_off - either ON or OFF
 *
*/
#ifdef NO_NEED_FOR_SDK
void ltc3589_fuse_vdd_power_on_off(int on_off)
{
    int temp;

    i2c_init(PMIC_LTC3589_I2C_BASE, 170000);

    if (on_off == 0) {          // fuse vdd off
        temp = ltc3589_reg_read(0x10);
        temp &= ~(0x40);        // clear bit 6 (OVEN[6]) to turn off LDO4
        ltc3589_reg_write(0x10, temp);
    } else {                    // fuse vdd on
        // set LDO4 to 3.2V
        temp = ltc3589_reg_read(0x33);
        temp |= 0x60;
        ltc3589_reg_write(0x33, temp);
        // enable LDO4
        temp = ltc3589_reg_read(0x10);
        temp |= 0x40;           // set bit 6 (OVEN[6]) to turn on LDO4
        ltc3589_reg_write(0x10, temp);
    }
}
#endif

#ifdef TO_REMOVE
/* SPI NOR reset signal can't be a GPIO as this is EIM_D19
   hence the SPI NOR and NOR flash can't coexist on the board */

/*! Enable or disable the SPI NOR on ARD only
 *   Note, ARD SPI NOR signasl are mux'd with WEIM data bus
 *   Hence, the SPI NOR needs to be disabled (tri-stated) or enabled
 *   depending on desired usage.
 *
 * @param   en_dis enable or disable spi nor by setting GPIo control to low or high
 */
void ard_spi_nor_control(int en_dis)
{
    // set DI0_PIN2 mux control for GPIO4_18 usage
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2);
    // configure GPIO4_18 as output
    gpio_dir_config(4, 18, GPIO_GDIR_OUTPUT);   // port=4, pin=18, dir=output
    // write GPIO4_18 as low (enable spi nor) or high (disable spi nor)
    gpio_write_data(4, 18, en_dis); // port=4, pin=18, en_dis (low or high)
}
#endif

/*!
 * Provide the power for TFT LCD backlight
 */
void tftlcd_backlight_en(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
        /*GPIO to provide backlight */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_dir_config(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
        gpio_write_data(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
    } else {
        printf("Error: unknown tft lcd type!\n");
    }
}

/*!
 * Reset the TFT LCD
 */
void tftlcd_reset(char *panel_name)
{
    if (!strcmp(panel_name, "SEIKO 70WVW1TZ3")) {
        /*do nothing */
    } else if (!strcmp(panel_name, "CLAA 070VC01")) {
#ifdef MX61_ARD
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
        gpio_dir_config(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_write_data(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_write_data(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
#ifdef MX61_SMD
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0, 0x1B0B0);
        gpio_dir_config(GPIO_PORT6, 11, GPIO_GDIR_OUTPUT);
        gpio_write_data(GPIO_PORT6, 11, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_write_data(GPIO_PORT6, 11, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
    }
}

/*!
 * Disable the display panel
 */
void disable_para_panel(void)
{
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
    gpio_dir_config(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_write_data(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol CEC
 * port including CEC_LINE
 */
void hdmi_tx_cec_pgm_iomux()
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
void hdmi_tx_ddc_pgm_iomux()
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
void hdmi_tx_phydtb_pgm_iomux()
{
    // config SD1_DAT1 pad for hdmi_tx instance OPHYDTB[0] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1, ALT6);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1, 0x000b1);

    // config SD1_DAT0 pad for hdmi_tx instance OPHYDTB[1] port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT0, ALT6);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_SD1_DAT0, 0x000b1);

}

void hdmi_pgm_iomux(void)
{
    unsigned int regval = 0;
    hdmi_tx_cec_pgm_iomux();
    hdmi_tx_ddc_pgm_iomux();
    hdmi_tx_phydtb_pgm_iomux();

    /*select ipu1 di0 as hdmi input */
    regval = reg32_read(IOMUXC_GPR3);
    reg32_write(IOMUXC_GPR3, regval & 0xFFFFFFF0);
}

/*!
 * Power no esai codec.
 * 
 */
int esai_codec_power_on(void)
{
    //No need do anything for mx61_ard
    return 0;
}
