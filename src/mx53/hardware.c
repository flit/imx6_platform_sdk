/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
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
extern void init_clock(uint32_t rate);
extern unsigned char da9053_i2c_reg(unsigned int reg, unsigned char val, unsigned int dir);
extern int board_id;
extern sata_phy_ref_clk_t sata_phy_clk_sel;

#define ON 1
#define OFF 0

// ARM core is a special case. Assign 0 to it.
struct hw_module core = {
    "ARM",
    0,
};

struct hw_module uart1 = {
    "UART1",
    UART1_BASE_ADDR,
};

struct hw_module ddr = {
    "DDR",
    ESDCTL_REGISTERS_BASE_ADDR,
};

struct hw_module *mx53_module[] = {
    &core,
    &ddr,
    &uart1,
    NULL,
};

unsigned int mx53_gpio[] = {
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
    uint32_t ref_clk_hz;
    uint32_t mfd;
};
const struct fixed_pll_mfd fixed_mfd[REF_IN_CLK_NUM] = {
    {0, 0},                     // reserved
    {0, 0},                     // reserved
    {FREQ_24MHZ, 24 * 16},      // 384
    {0, 0},                     // reserved
};

static volatile uint32_t *pll_base[] = {
    REG32_PTR(PLL1_BASE_ADDR),
    REG32_PTR(PLL2_BASE_ADDR),
    REG32_PTR(PLL3_BASE_ADDR),
    REG32_PTR(PLL4_BASE_ADDR),
};

struct soc_sbmr {
    unsigned int bt_mmu_enable:1,
        bt_freq:1,
        boot_cfg1:6,
        hab_type:2,
        boot_cfg2:6, dir_bt_dis:1, boot_cfg3:7, bmod:2, bt_fuse_sel:1, test_mode:3, rsv0:2;
} __attribute__ ((packed));
struct soc_sbmr *soc_sbmr = (struct soc_sbmr *)(SRC_BASE_ADDR + 0x4);

/*!
 *	Sets the GPIO direction for the specified pin.
 *  @param 	port: 	GPIO module instance, 0 to 6.
 *	@param	pin:	GPIO pin 0 to 31.
 *  @param	dir:	direction for the pin. in or out.
 *  @return -1 means failed to set the pin
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

    oldVal = readl(mx53_gpio[port] + GPIO_GDIR0_OFFSET);

    if (dir == GPIO_GDIR_INPUT)
        newVal = oldVal & (~(1 << pin));
    else
        newVal = oldVal | (1 << pin);

    writel(newVal, mx53_gpio[port] + GPIO_GDIR0_OFFSET);
    return 0;
}

/*!
 *	Sets the GPIO attributte(high or low) for the specified pin.
 *  @param  port: 	GPIO module instance, 0 to 6.
 *	@param  pin:	GPIO pin 0 to 31.
 *  @param  attr:	attributte for the pin. high/low
 *  @return  -1 means failed to set the pin
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

    dir = (readl(mx53_gpio[port] + GPIO_GDIR0_OFFSET) & (1 << pin)) >> pin;

    if (dir != 1) {
        printf("GPIO%d_%d is not configured to be output!\n", port + 1, pin);
        return -1;
    }

    oldVal = readl(mx53_gpio[port] + GPIO_DR0_OFFSET);

    if (attr == 0)
        newVal = oldVal & (~(1 << pin));
    else if (attr == 1)
        newVal = oldVal | (1 << pin);

    writel(newVal, mx53_gpio[port] + GPIO_DR0_OFFSET);
    return 0;
}

/*!
 *	Gets the GPIO attributte(high or low) for the specified pin.
 *  @param	port: 	GPIO module instance, 0 to 6.
 *	@param	pin:	GPIO pin 0 to 31.
 *  @return	-1 means failed to get the value
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

    dir = (readl(mx53_gpio[port] + GPIO_GDIR0_OFFSET) & (1 << pin)) >> pin;

    if (dir != 0) {
        printf("GPIO%d_%d is not configured to be input!\n", port + 1, pin);
        return -1;
    }

    return (readl(mx53_gpio[port] + GPIO_DR0_OFFSET) & (1 << pin)) >> pin;
}

/*!
 * This function returns the low power audio clock.
 */
uint32_t get_lp_apm(void)
{
    uint32_t ret_val = 0;
    uint32_t ccsr = readl(CCM_BASE_ADDR + CLKCTL_CCSR);

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
uint32_t get_periph_clk(void)
{
    uint32_t ret_val = 0, clk_sel;
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);

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
uint32_t pll_clock(enum plls pll)
{
    uint64_t mfi, mfn, mfd, pdf, ref_clk, pll_out, sign;
    uint64_t dp_ctrl, dp_op, dp_mfd, dp_mfn, clk_sel;
    uint8_t dbl = 0;
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

    return (uint32_t) pll_out;
}

/*!
 * This function returns the emi_core_clk_root clock.
 */
uint32_t get_emi_core_clk(void)
{
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t clk_sel = 0, max_pdf = 0, peri_clk = 0, ahb_clk = 0;
    uint32_t ret_val = 0;
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
uint32_t get_main_clock(enum main_clocks clk)
{
    uint32_t pdf, max_pdf, ipg_pdf, nfc_pdf, clk_sel;
    uint32_t pll, ret_val = 0;
    uint32_t cacrr = readl(CCM_BASE_ADDR + CLKCTL_CACRR);
    uint32_t cbcdr = readl(CCM_BASE_ADDR + CLKCTL_CBCDR);
    uint32_t cbcmr = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);
    uint32_t cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    uint32_t cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);

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
uint32_t get_peri_clock(enum peri_clocks clk)
{
    uint32_t ret_val = 0, pdf, pre_pdf, clk_sel;
    uint32_t cscmr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    uint32_t cscdr1 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR1);
    uint32_t cscdr2 = readl(CCM_BASE_ADDR + CLKCTL_CSCDR2);
    uint32_t cs1cdr = readl(CCM_BASE_ADDR + CLKCTL_CS1CDR);
    uint32_t cs2cdr = readl(CCM_BASE_ADDR + CLKCTL_CS2CDR);

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
uint32_t get_freq(uint32_t module_base)
{
    if (module_base == 0)       // as ARM Core doesn't have a module base per se, it is set to 0
        return get_main_clock(CPU_CLK);
    else if (module_base == ESDCTL_REGISTERS_BASE_ADDR)
        return get_main_clock(DDR_CLK);
    else if (module_base == UART1_BASE_ADDR)
        return get_peri_clock(UART1_BAUD);
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
    int i;
    volatile unsigned int temp;
    struct hw_module *tmp;
    /* Ungate clocks to all modules */
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR0_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR1_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR2_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR3_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR4_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR5_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR6_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR7_OFFSET) = 0xFFFFFFFF;
    /* For MX53, set UART clock source to PLL3 (216MHz) and set dividers to div-by-4 to get 54MHz */
    /* CSCMR1 - to select PLL3 source. uart_clk_sel[1:0] = 10 (bits 25 and 24)
       CSCDR1 - to select divide values */
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CSCMR1);
    temp &= ~(0x03000000);      // clear bits 25 and 24
    temp |= 0x02000000;         // set bits 25 and 24 to 10
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CSCMR1) = temp;
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CSCDR1);
    temp &= ~(0x0000003F);      // clear bits 5 to 0
    temp |= 0x00000018;         // set bits 5 to 3 to 011 (div-by-4); bits 3 to 0 set to 000 (div-by-1)
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CSCDR1) = temp;
    /* To align with operating systems such as WinCE and Linux, configure PERCLK to be sourced
     * from lp_apm with a divider set to DIV-BY-3 to achieve 8MHz on PERCLK*/
    /* first choose lp_apm as the clock source to PERCLK */
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR);
    temp |= 0x00000002;         // set bit 1, perclk_lp_apm_sel
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR) = temp;
    /* now set perclk_pred1 to div-by-3 */
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR);
    temp &= ~(0x000000FF);
    temp |= 0x00000080;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR) = temp;

    for (i = 0; (tmp = mx53_module[i]) != NULL; i++) {
        tmp->freq = get_freq(tmp->base);
    }

    /* config IPU hsp clock, derived from AXI B */
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR);
    temp &= ~(0x000000C0);
    temp |= 0x00000040;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCMR) = temp;
    /* now set perclk_pred1 to div-by-2 */
    temp = *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR);
    temp &= ~(0x00380000);
    temp |= 0x00080000;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CLKCTL_CBCDR) = temp;
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int i;
    struct hw_module *tmp;
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

/*!
  * Set up the IOMUX for SPI
  */
void io_cfg_spi(struct imx_spi_dev *dev)
{
    switch (dev->base) {
    case ECSPI1_BASE_ADDR:

        if (BOARD_TYPE_ID == BOARD_ID_MX53_ARD) {
            ard_spi_nor_control_(0);    // by setting to 0, this enables the spi nor
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
    volatile unsigned int reg;
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
void io_cfg_i2c(uint32_t module_base)
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
        } else if (BOARD_TYPE_ID == BOARD_ID_MX53_SBRTH_SMD) {
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
    return 0;
}

/* Configure iomux for ESAI */
void esai_iomux(void)
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
    if ((board_id != BOARD_ID_MX53_SBRTH_SMD)
        && (board_id != BOARD_ID_MX53_SBRTH_LCB)) {
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

    if ((board_id != BOARD_ID_MX53_SBRTH_SMD)
        && (board_id != BOARD_ID_MX53_SBRTH_LCB)) {
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
 *  For mx53 rita sd1 io configure
 */
void mxc_mmc_init(unsigned int base_address)
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

/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
    if (board_id != BOARD_ID_MX53_ARD) {
        if ((board_id != BOARD_ID_MX53_SBRTH_SMD)) {
            /* Use GPIO5_20 to reset the USB HUB */
            uint32_t temp;
            /* set GPIO5_20 to low, this is the reset to the HUBs */
            writel((ALT1 | (0x1 << 4)), IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN);    //force input path as CEI0_DATA_EN,Alt1 as GPIO5_20
            temp = readl(GPIO5_BASE_ADDR + GPIO_DR0_OFFSET);
            temp &= ~(0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_DR0_OFFSET));  // set GPIO5_20 low
            temp = readl(GPIO5_BASE_ADDR + GPIO_GDIR0_OFFSET);
            temp |= (0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_GDIR0_OFFSET));    // set GPIO5_20 to output
            hal_delay_us(1000);
            temp = readl(GPIO5_BASE_ADDR + GPIO_DR0_OFFSET);
            temp |= (0x1 << 20);
            writel(temp, (GPIO5_BASE_ADDR + GPIO_DR0_OFFSET));  // set GPIO5_20 high
        } else {
            /* for SBRTH_SMD, use GPIO3_14 to reset the USB_HUB */
            uint32_t temp;
            /* set GPIO3_14 to low, this is the reset to the HUBs */
            writel((ALT1 | (0x1 << 4)), IOMUXC_SW_MUX_CTL_PAD_EIM_DA14);    //force input path, ALT1 as GPIO3_14
            temp = readl(GPIO3_BASE_ADDR + GPIO_DR0_OFFSET);
            temp &= ~(0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_DR0_OFFSET));  //set GPIO3_14 low
            temp = readl(GPIO3_BASE_ADDR + GPIO_GDIR0_OFFSET);
            temp |= (0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_GDIR0_OFFSET));    // set GPIO3_14 to output
            hal_delay_us(1000);
            temp = readl(GPIO3_BASE_ADDR + GPIO_DR0_OFFSET);
            temp |= (0x1 << 14);
            writel(temp, (GPIO3_BASE_ADDR + GPIO_DR0_OFFSET));  //set GPIO3_14 high
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

    if ((board_id == BOARD_ID_MX53_SBRTH_SMD) || (board_id == BOARD_ID_MX53_SBRTH_LCB)) {
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
 * EVK Power initialization
 */
void evk_power_init(void)
{
    /*    imx_pmic_init(); */
    /* TO DO:
       read PMIC AAPL ID
       Set up AAPL to output specific voltages
     */
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
    /* Set up on board PMIC and read device ID */
//    evk_power_init();

    /* Configure the memory map of the WEIM */
    /* Activates CS0 and CS1 with 64MB each in IOMUXC_GPR1 */
    val = readl(0x53FA8000 + 0x4);
    val &= ~(0x1F);
    val |= 0x1B;
    writel(val, 0x53FA8000 + 0x4);
    // Configure peripherals reset through io expander
    if (BOARD_ID_MX53_ARD == BOARD_TYPE_ID) {
        max7310_init();
    }
    if (BOARD_ID_MX53_SBRTH_SMD == BOARD_TYPE_ID) {
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
    uint32_t temp;

#if defined (MX53_ARD) && defined (BOARD_VERSION2)
    ltc3589_fuse_vdd_power_on_off(ON);  // turn on fuse vdd voltage
#endif

    /* First, allow fuse programming in the CCM CGPR register by setting the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp |= 0x00000010;         // set bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    /* blow the fuse */
    fuse_blow_row(bank, row_id, BOARD_TYPE_ID);
    if (sense_fuse(bank, row_id) != BOARD_TYPE_ID) {
        printf("  ** Fuse read-back-verify failed, read back 0x%x, should be 0x%x\n",
               sense_fuse(bank, row_id), BOARD_TYPE_ID);
        return -1;
    }

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
    fuse_blow_row(bank, row_rev, BOARD_VERSION_ID);
    if (sense_fuse(bank, row_rev) != BOARD_VERSION_ID) {
        printf("  ** Fuse read-back-verify failed, read back 0x%x, should be: 0x%x\n",
               sense_fuse(bank, row_rev), BOARD_VERSION_ID);
        return -1;
    }
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

/*! Read the FEC MAC address fuses
 *
 * @param mac_data pointer to an array to store mac address read from the fuses
 *
 * @return  0 if successful; non-zero otherwise
 */
int read_mac(uint8_t * mac_data)
{
    mac_data[0] = readb(IIM_BASE_ADDR + 0xC24);
    mac_data[1] = readb(IIM_BASE_ADDR + 0xC28);
    mac_data[2] = readb(IIM_BASE_ADDR + 0xC2C);
    mac_data[3] = readb(IIM_BASE_ADDR + 0xC30);
    mac_data[4] = readb(IIM_BASE_ADDR + 0xC34);
    mac_data[5] = readb(IIM_BASE_ADDR + 0xC38);

    return 0;
}

/*! Program the FEC MAC address value to the hardware fuses
 *
 * @param   fuse_data pointer to an array with mac address to program to fuses
 *
 * @return  0 if successful; non-zero otherwise
 */
int program_mac(uint8_t * fuse_data)
{
    unsigned int temp;
    uint32_t bank_mac = 1;
    uint32_t row_mac = 9;
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
        fuse_blow_row(bank_mac, i + row_mac, fuse_data[i]);
    }
    /* Now sense the fuses to confirm the fuses were programmed correctly */
    for (i = 0; i <= 5; i++) {
        if (sense_fuse(bank_mac, row_mac + i) != fuse_data[i]) {
            printf("MAC%d doesn't match, it read 0x%02x, but it should be 0x%02x, \n", i,
                   sense_fuse(bank_mac, row_mac + 1), fuse_data[i]);
            failcount++;
            break;
        } else {
            printf("MAC%d programmed correctly \n", i);
        }
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

#ifdef MX53_SBRTH_SMD
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

void hdmi_power_on(void)
{
    if (board_id == BOARD_ID_MX53_SBRTH_SMD) {
        /* Write to R51 for 1V2 LDO2 output */
        da9053_i2c_reg(51, 0x58, I2C_WRITE);
    } else {
        /* Write to R55 for 1V2 LDO6 output */
        da9053_i2c_reg(55, 0x40, I2C_WRITE);
    }
}
