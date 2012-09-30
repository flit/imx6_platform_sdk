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
#include "registers/regsccmanalog.h"
#include "registers/regsusbphy.h"
#include "registers/regsusbnoncore.h"
#include "registers/regsusdhc.h"

#define ON 1
#define OFF 0

// ARM core is a special case. Assign 0 to it.
struct hw_module core = {
    "ARM",
    0,
};

// imx6sl UART1 is debug_uart port for EVB
struct hw_module uart1 = {
    "UART1",
    UART1_BASE_ADDR,
};

struct hw_module ddr = {
    "DDR",
    MMDC_BASE_ADDR,
};

struct hw_module *mx6sl_module[] = {
    &core,
    &ddr,
    &uart1,
    NULL,
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
        ret_val = 80000000;
    case UART2_BAUD:
        ret_val = 80000000;
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
#if defined(SABRE_AI)||(!defined(MX6SL) && defined(EVB))||defined(SMART_DEVICE)||defined(SABRE_LITE)
        //TODO
        pdf = (cscdr2 >> 19) & 0x3F;
        ret_val = 60000000 / (pdf + 1);
#else
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
    else if (module_base == MMDC_BASE_ADDR)
        //return get_main_clock(DDR_CLK);
        return 400000000;
    else if (module_base == UART4_BASE_ADDR)
        //return get_peri_clock(UART4_BAUD);
        return 80000000;
    else if (module_base == UART2_BASE_ADDR)
        //return get_peri_clock(UART4_BAUD);
        return 80000000;
    else if (module_base == UART1_BASE_ADDR)
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
    struct hw_module *tmp;

    //ETHNET
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);    /*power down bit */
    reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);    /*enable bit */
    reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);    /*bypass bit */
    reg32_write_mask(HW_ANADIG_PLL_ETH_CTRL, 0x1, 0x3); /*divide bits */
    /* Ungate clocks to all modules */
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR0_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR1_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR2_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR3_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR4_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR5_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR6_OFFSET) = 0xFFFFFFFF;
    *(volatile unsigned int *)(CCM_BASE_ADDR + CCM_CCGR7_OFFSET) = 0xFFFFFFFF;
    // **** NEEDS UPDATE for mx6dq *****  //
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
    for (i = 0; (tmp = mx6sl_module[i]) != NULL; i++) {
        tmp->freq = get_freq(tmp->base);
    }

#if defined(SABRE_AI) && !defined(BOARD_REV_A)  // for audio clock source
    reg32setbit(ANATOP_BASE_ADDR + 0x160, 11);  // CLK2 enable output buffer
    reg32setbit(ANATOP_BASE_ADDR + 0x160, 9);
    reg32setbit(ANATOP_BASE_ADDR + 0x160, 6);   // bits 9,6 select CLK2 extal clock
#endif
}

/*!
 * Display module frequency
 */
void show_freq(void)
{
    int i;
    struct hw_module *tmp;
    printf("========== clock frequencies(HZ)\n");

    for (i = 0; (tmp = mx6sl_module[i]) != NULL; i++) {
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
    u32 temp2, num_banks, ddr_type, lpddr_2ch_enable = 0;
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
    lpddr_2ch_enable = (temp2 & (0x01 << 2)) ? 1 : 0;
    printf("data bits: %d, num_banks: %d \n", dsiz, num_banks);
    printf("row: %d, col: %d \n", row, col);

    if (ddr_type == 1)
        printf("DDR type is DDR2 \n");
    else if (ddr_type == 2) {
        if (lpddr_2ch_enable) {
            printf("DDR type is LPDDR2 in 2-channel mode. Show ch0 info only\n");
        } else {
            printf("DDR type is LPDDR2 in 1-channel mode.\n");
        }
    } else
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
#if defined(SABRE_AI) && !defined(BOARD_REV_A)  // for I2C3 steering
    /* Select ALT5 mode of EIM_A24 for GPIO5_4 - EIMD18_I2C3_STEER(EIM_A24) */
    /* low output to select WEIM NOR option */
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
    gpio_set_direction(GPIO_PORT5, 4, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT5, 4, GPIO_LOW_LEVEL);
#endif

    switch (dev->base) {
    case ECSPI1_BASE_ADDR:
        ecspi1_iomux_config();
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
#if !defined(MX6SL)
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
#endif
}

/*!
  * Set up the IOMUX for I2C
  */
void io_cfg_i2c(u32 module_base)
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
#if defined(SABRE_AI) && !defined(BOARD_REV_A)  // for I2C3 steering
        /* Select ALT5 mode of EIM_A24 for GPIO5_4 - EIMD18_I2C3_STEER(EIM_A24) */
        /* high output to select I2C3 option */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
        gpio_set_direction(GPIO_PORT5, 4, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT5, 4, GPIO_HIGH_LEVEL);
#endif
        break;
    default:
        break;
    }
}

/*!
  * Set up the IOMUX for USDHC
  */
void usdhc_iomux_config(u32 module_base)
{
    switch (module_base) {
    case USDHC1_BASE_ADDR:
        usdhc1_iomux_config();
#if defined(SABRE_AI)
        /* Select ALT5 mode of CSI0_DATA_EN for GPIO5_20 - SDb_WP(CSI0_DATA_EN_GPIO5_20) */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN);
        gpio_set_direction(GPIO_PORT5, 20, GPIO_GDIR_INPUT);
#endif
        break;

    case USDHC2_BASE_ADDR:
        usdhc2_iomux_config();
        break;

    case USDHC3_BASE_ADDR:
        usdhc3_iomux_config();
#if defined(SABRE_AI)
        /* Select ALT5 mode of NANDF_CS2 for GPIO6_15 - SDa_CD_B(GPIO6_15) */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
        gpio_set_direction(GPIO_PORT6, 15, GPIO_GDIR_INPUT);
        /* Select ALT5 mode of SD2_DAT2 for GPIO1_13 - SDa_WP(SD2_DAT2_GPIO1_13) */
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_SD2_DAT2);
        gpio_set_direction(GPIO_PORT1, 13, GPIO_GDIR_INPUT);
#endif
        break;
    case USDHC4_BASE_ADDR:
        usdhc4_iomux_config();
        break;

    default:
        break;
    }
}

bool usdhc_card_detected(unsigned int base_address)
{
    bool ret_val = false;

#if defined(SABRE_AI)
    if (base_address == USDHC1_BASE_ADDR) {
        // SDb_CD_B
        // Bit HIGH == pin LOW == Card Detected.
        if (BG_USDHC_PRES_STATE_CDPL(HW_USDHC_PRES_STATE_RD(REGS_USDHC_INSTANCE(base_address)))) {
            ret_val = true;
        }
    } else if (base_address == USDHC3_BASE_ADDR) {
        // SDa_CD_B using GPIO6_15
        // Bit LOW == pin LOW ==  Card Detected.
        ret_val = gpio_get_level(GPIO_PORT6, 15) == GPIO_LOW_LEVEL;
    }
#else
    if (BG_USDHC_PRES_STATE_CDPL(HW_USDHC_PRES_STATE_RD(REGS_USDHC_INSTANCE(base_address)))) {
        // Bit HIGH == pin LOW ==  Card Detected.
        ret_val = true;
    }
#endif

    return ret_val;
}

bool usdhc_write_protected(unsigned int base_address)
{
    bool ret_val = true;

#if defined(SABRE_AI)
    if (base_address == USDHC1_BASE_ADDR) {
        // SDb_WP (CSI0_DATA_EN_GPIO5_20)
        // Bit HIGH == pin HIGH == Write Protected.
        ret_val = gpio_get_level(GPIO_PORT5, 20) == GPIO_HIGH_LEVEL;
    } else if (base_address == USDHC3_BASE_ADDR) {
        // SDa_WP (SD2_DAT2_GPIO1_13)
        // Bit HIGH == pin HIGH == Write Protected.
        ret_val = gpio_get_level(GPIO_PORT1, 13) == GPIO_HIGH_LEVEL;
    }
#else
    if (BG_USDHC_PRES_STATE_WPSPL(HW_USDHC_PRES_STATE_RD(REGS_USDHC_INSTANCE(base_address)))) {
        // Bit HIGH == pin LOW == NOT Write Protected (Write Enabled).
        ret_val = false;
    }
#endif

    return ret_val;
}

/* Power up the SGTL and initialize it's clock if necessary */
void SGTL5000PowerUp_and_clockinit(void)
{
#if !defined(EVB)
    unsigned int val = 0;

    /* Enable GPIO_2 to turn on the audio oscillator */
    writel(0x1, IOMUXC_SW_MUX_CTL_PAD_GPIO_2);
    writel(0x4, GPIO1_BASE_ADDR + 0x04);    // data direction register, set to output
    writel(0x4, GPIO1_BASE_ADDR + 0x00);    // data register (output 1)

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
#endif
}

/* Configure iomux for AUDMUX output */
int SSI_iomux(void)
{
    audmux_iomux_config();

    return 0;
}

/* Configure iomux for ESAI */
void esai_iomux(void)
{
#if !defined(MX6SL)
    esai_iomux_config();
#endif
}

/*USB_OTG_PWR and OC iomux configurations*/
void usb_io_config(void)
{
    usb_iomux_config();
}

void usbh_set_to_ulpi_mode(int usb_base_addr)
{
    // allow some time for the USB host to settle on new ULPI settings
    hal_delay_us(100000);
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
    //check UTMI PHY Clock Valid in USB OTG UTMI PHY Control register 0 bit 31
    if (!((*(volatile u32 *)(USBOH3_USB_BASE_ADDR + 0x818)) & (0x1 << 31))) // OTG utmi clock is not OK?
        return 0;
    if (!((*(volatile u32 *)(USBOH3_USB_BASE_ADDR + 0x81C)) & (0x1 << 31))) // Host1 utmi clock is not OK?
        return 0;
    return 1;                   // Both UTMI clocks are running
}

/* GPS iomux configuration */
void gps_io_config(void)
{
#ifdef GPS_SUPPORT
    uart2_iomux_config();

    /* Select ALT1 mode of PATA_DATA5 for GPIO2_5 - GPS_PWREN */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5);
    gpio_set_direction(GPIO_PORT2, 5, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 5, GPIO_HIGH_LEVEL);
    /* Select ALT1 mode of PATA_DATA6 for GPIO2_6 - GPS_INT_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6);
    gpio_set_direction(GPIO_PORT2, 6, GPIO_GDIR_INPUT);
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
    mlb_iomux_config();
    /* MLB_PWRDN input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT15);
    gpio_set_direction(GPIO_PORT5, 9, GPIO_GDIR_INPUT);
#endif
}

/* CAN1 iomux configuration */
void can1_io_config(void)
{
#ifdef CAN1_IO_SUPPORT
    can1_iomux_config();
    /* Select ALT1 mode of PATA_DATA0 for GPIO2_0 - CAN1_NERR_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0);
    gpio_set_direction(GPIO_PORT2, 0, GPIO_GDIR_INPUT);
    /* Select ALT1 mode of PATA_DA_0 for GPIO7_6 - CAN_EN */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0);
    gpio_set_direction(GPIO_PORT7, 0, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT7, 0, GPIO_HIGH_LEVEL);
    /* Select ALT1 mode of KEY_ROW4 for GPIO4_15 - CAN_STBY */
    /* active high output */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4);
    gpio_set_direction(GPIO_PORT4, 15, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT4, 15, GPIO_HIGH_LEVEL);
#endif
}

/* CAN2 iomux configuration */
void can2_io_config(void)
{
#ifdef CAN2_IO_SUPPORT
    can2_iomux_config();
    /* Select ALT1 mode of PATA_DATA1 for GPIO2_1 - CAN2_NERR_B */
    /* active low input */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1);
    gpio_set_direction(GPIO_PORT2, 1, GPIO_GDIR_INPUT);
#endif
}

/* IOMUX configuration for the Android_Buttons */
void android_buttons_iomux_config()
{
#if !defined(EVB)
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
#endif
}

/* set up the chip select registers for the weim "parallel" nor flash*/
void weim_nor_flash_cs_setup(void)
{
    /* DSIZ=010 (map 16-bit to D[31:16], csen=1 */
    // writel(0x00020001, WEIM_REGISTERS_BASE_ADDR + 0x000);
    writel(0x00620081, WEIM_REGISTERS_BASE_ADDR + 0x000);

    /* CS0 Read Config reg1 */
    /* RWCS=11, OEA=2, OEN=1 */
    //writel(0x0B002100, WEIM_REGISTERS_BASE_ADDR + 0x008);
    writel(0x1C022000, WEIM_REGISTERS_BASE_ADDR + 0x008);

    /* CS0 Write Config Reg 1 */
    /* WWCS=11, WEA=2, WEN=1 */
    //writel(0x0B000440, WEIM_REGISTERS_BASE_ADDR + 0x010);
    writel(0x0804a240, WEIM_REGISTERS_BASE_ADDR + 0x010);
}

/*!
 * configure the iomux pins for ipu display interface 0
 * choose ipu1 as the source.
 */
void ipu_iomux_config(void)
{
#if !defined(MX6SL)
    ipu1_iomux_config();
#endif
}

/* ENET iomux config */
void imx_enet_iomux(void)
{
#if defined(MX6SL)
    fec_iomux_config();
#else
    enet_iomux_config();
#endif
}

void imx_fec_setup(void)
{
    unsigned int reg;
    imx_enet_iomux();
    /* phy reset: gpio4-21 */
    reg = readl(GPIO4_BASE_ADDR + 0x0);
    reg &= ~(1 << 21);
    writel(reg, GPIO4_BASE_ADDR + 0x0);

    reg = readl(GPIO4_BASE_ADDR + 0x4);
    reg |= 1 << 21;
    writel(reg, GPIO4_BASE_ADDR + 0x4);

    hal_delay_us(500);

    reg = readl(GPIO4_BASE_ADDR + 0x0);
    reg |= 1 << 21;
    writel(reg, GPIO4_BASE_ADDR + 0x0);
}

/*CPU_PER_RST_B low to high*/
void imx_ar8031_reset(void)
{
    //max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    //hal_delay_us(1000000);
    //max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
}

/*CPU_PER_RST_B low to high*/
void imx_KSZ9021RN_reset(void)
{
}

void debug_uart_iomux(void)
{
#if defined(EVB)
    uart1_iomux_config();
#endif
}

/* eCSPI1 iomux - connecting SPI NOR through SS1*/
// Function to config instance ecspi1 of Module ECSPI to Protocol MASTER
// This protocol has next ports:
//  SCLK MOSI SS0 SS1 SS2 SS3 MISO RDY
void ecspi1_master_pgm_iomux(void)
{
#if defined (MX6SL)
    ecspi1_iomux_config();
#else
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
#endif
}

/*!
 * USB HUB reset function
 */
void reset_usb_hub(void)
{
}

/*!
 * USB PHY INIT
 */
void usb_init_phy(void)
{
    /* Init USBPHY1 */

    /* Enable USB1_PLL  */
    HW_CCM_ANALOG_PLL_USB1_SET(BM_CCM_ANALOG_PLL_USB1_POWER);   // Turn-on power.
    while (!HW_CCM_ANALOG_PLL_USB1.B.LOCK) ;    // Wait for PLL to lock
    HW_CCM_ANALOG_PLL_USB1_CLR(BM_CCM_ANALOG_PLL_USB1_BYPASS);  // Clear bypass
    HW_CCM_ANALOG_PLL_USB1_SET(BM_CCM_ANALOG_PLL_USB1_ENABLE);  // Enable USB clocks
    HW_CCM_ANALOG_PLL_USB1_SET(BM_CCM_ANALOG_PLL_USB1_EN_USB_CLKS); // Enable 9-phase PLL output

    /* NOTE !! CLKGATE must be cleared before clearing power down */
    HW_USB_PHY_CTRL_CLR(HW_USB_PHY1, BM_USB_PHY_CTRL_SFTRST);   // clear SFTRST
    HW_USB_PHY_CTRL_CLR(HW_USB_PHY1, BM_USB_PHY_CTRL_CLKGATE);  // clear CLKGATE
    HW_USB_PHY_PWD_WR(HW_USB_PHY1, 0);  // clear all power down bits
    HW_USB_PHY_CTRL_SET(HW_USB_PHY1, BM_USB_PHY_CTRL_ENHOSTDISCONDETECT);   // Enable HostDisconnect detector
    HW_USB_PHY_CTRL_SET(HW_USB_PHY1, BM_USB_PHY_CTRL_ENUTMILEVEL2); // Enable UTMI+ Level 2
    HW_USB_PHY_CTRL_SET(HW_USB_PHY1, BM_USB_PHY_CTRL_ENUTMILEVEL3); // Enable UTMI+ Level 3

    printf("PHY registers check: USBPHY1_PWD %08X, USBPHY1_CTRL %08X\n",
           HW_USB_PHY_PWD_RD(HW_USB_PHY1), HW_USB_PHY_CTRL_RD(HW_USB_PHY1));
    printf("USB1 PLL: %08X\n", HW_CCM_ANALOG_PLL_USB1_RD());

    /* Init USBPHY2 */

    /* Enable USB2_PLL  */
    HW_CCM_ANALOG_PLL_USB2_SET(BM_CCM_ANALOG_PLL_USB2_POWER);   // Turn-on power.
    while (!HW_CCM_ANALOG_PLL_USB2.B.LOCK) ;    // Wait for PLL to lock
    HW_CCM_ANALOG_PLL_USB2_CLR(BM_CCM_ANALOG_PLL_USB2_BYPASS);  // Clear bypass
    HW_CCM_ANALOG_PLL_USB2_SET(BM_CCM_ANALOG_PLL_USB2_ENABLE);  // Enable USB clocks
    HW_CCM_ANALOG_PLL_USB2_SET(BM_CCM_ANALOG_PLL_USB2_EN_USB_CLKS); // Enable 9-phase PLL output

    /* NOTE !! CLKGATE must be cleared before clearing power down */
    HW_USB_PHY_CTRL_CLR(HW_USB_PHY2, BM_USB_PHY_CTRL_SFTRST);   // clear SFTRST
    HW_USB_PHY_CTRL_CLR(HW_USB_PHY2, BM_USB_PHY_CTRL_CLKGATE);  // clear CLKGATE
    HW_USB_PHY_PWD_WR(HW_USB_PHY2, 0);  // clear all power down bits
    HW_USB_PHY_CTRL_SET(HW_USB_PHY2, BM_USB_PHY_CTRL_ENHOSTDISCONDETECT);   // Enable HostDisconnect detector
    HW_USB_PHY_CTRL_SET(HW_USB_PHY2, BM_USB_PHY_CTRL_ENUTMILEVEL2); // Enable UTMI+ Level 2
    HW_USB_PHY_CTRL_SET(HW_USB_PHY2, BM_USB_PHY_CTRL_ENUTMILEVEL3); // Enable UTMI+ Level 3

    printf("PHY registers check: USBPHY2_PWD %08X, USBPHY2_CTRL %08X\n",
           HW_USB_PHY_PWD_RD(HW_USB_PHY2), HW_USB_PHY_CTRL_RD(HW_USB_PHY2));
    printf("USB2 PLL: %08X\n", HW_CCM_ANALOG_PLL_USB2_RD());
}

/*!
 * USB module clock enable function
 */
void usb_clock_enable(void)
{
    //*(volatile u32 *)(CCM_CCGR2) |= 0x3C000000; //enable USBOH3_IPG_AHB, USBOH3_60M
    //*(volatile u32 *)(CCM_CCGR4) |= 0x00003C00; //enable PHY1 and PHY2 clock
    *(volatile u32 *)(CCM_CCGR6) |= 0x00000003; //enable PHY1 and PHY2 clock
}

/*!
 * USB VBUS power on,
 */
void usb_vbus_power_on(void)
{

    // Vbus power is controlled by the USB controller (PORTSC.PP bit)
    // We only configure that I/O mux here to enable that function
    writel(ALT6, IOMUXC_SW_MUX_CTL_PAD_KEY_COL4);   // Configure I/O for USBOTG1 power control
    writel(ALT6, IOMUXC_SW_MUX_CTL_PAD_KEY_COL5);   // Configure I/O for USBOTG2 power control
    HW_USBNC_USB_OTG1_CTRL_SET(BM_USBNC_USB_OTG1_CTRL_PWR_POL); // OTG1 VBUS Power Pin is High active.
    HW_USBNC_USB_OTG2_CTRL_SET(BM_USBNC_USB_OTG2_CTRL_PWR_POL); // OTG2 VBUS Power Pin is High active.

#ifdef SMART_DEVICE
    //  USB_OTG_PWR_EN (EIM_D22)
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_D22);
    gpio_set_direction(GPIO_PORT3, 22, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT3, 22, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT3, 22, GPIO_HIGH_LEVEL);
#endif
}

extern void pf0100_enable_vgen3_1v8(void);
/*!
 * Audio Codec power on
 */
void audio_codec_power_on(void)
{
    //EVK board
    pf0100_enable_vgen3_1v8();

#ifdef SMART_DEVICE
    //  CODEC_PWR_EN, key_col2
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_KEY_COL2);
    gpio_set_direction(GPIO_PORT4, 10, GPIO_GDIR_OUTPUT);

    //For SD RevB board, if CODEC_PWR_EN cleared then set, the board reset. So comment it.      
//    gpio_set_level(GPIO_PORT4, 10, GPIO_LOW_LEVEL);
//    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT4, 10, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * Audio Clock config
 */
void audio_clock_config(void)
{
#if	defined(MX6SDL) && defined(SMART_DEVICE) && defined(BOARD_REV_B)
    unsigned int val = 0;

    ccm_iomux_config();

    val = (0x01 << 24) |        //clko2 en
        (0x05 << 21) |          //div 6
        (0x13 << 16) |          // ssi2 root clk
        (0x01 << 8);            //CKO1 output drives cko2 clock
    writel(val, CCM_CCOSR);
#endif
}

#if !defined(MX6SL)
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
    //enable SATA_CLK in the ENET_PLL register
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
//enable SATA_3V3 and SATA_5V
#ifdef SMART_DEVICE
    // AUX_5V_EN 
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#else
    //enable SATA_3V3 and SATA_5V with MX7310 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * SATA power off
 */
void sata_power_off(void)
{
#ifdef SMART_DEVICE
    // AUX_5V_EN, will also turn off lvds0, can
    gpio_set_level(GPIO_PORT6, 10, GPIO_LOW_LEVEL);
#else
    //disable SATA_3V3 and SATA_5V with MX7310 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_LOW_LEVEL);
#endif
}
#endif

/*!
 * Board initialization and UART IOMUX set up
 */
void board_init(void)
{
    init_clock(32768);
    /* set up debug UART iomux */
    debug_uart_iomux();
    /* Set up the digital audio mux here.   */
#if 0                           //driver not ready
#if defined(SMART_DEVICE)
    AUDMUXRoute(2, 3, 0);
#else
    AUDMUXRoute(2, 5, 0);
#endif
#endif
}

/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(char *panel_name)
{
#if (!defined(MX6SL) && defined(EVB))
    /*LVDS power supply */
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_set_direction(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef SMART_DEVICE
    // 3v3 on by default
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
    // PMIC_5V LVDS1 power on by default
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
#endif

#ifdef SABRE_AI
    /*lvds backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);
#endif
}

/* dummy empty function for compatibility between i.MX53 and i.MX6DQ OBDS */
void camera_power_on(void)
{
    /*set io power high (DOVDD) */
    pf0100_enable_vgen4_1v8();
    hal_delay_us(500000);       /*T0 > 0ms until DOVDD stable */

    /*set analog power high (AVDD) */
    pf0100_enable_vgen6_2v8();
    hal_delay_us(500000);       /*T0 > 0ms until DOVDD stable */

    pf0100_enable_vgen2_1v5();
    hal_delay_us(500000);       /*T0 > 0ms until DOVDD stable */
}

/* dummy empty function for compatibility between i.MX53 and i.MX6DQ OBDS */
void hdmi_power_on(void)
{
}

#ifdef TO_REMOVE
/* SPI NOR reset signal can't be a GPIO as this is EIM_D19
   hence the SPI NOR and NOR flash can't coexist on the board */

/*! Enable or disable the SPI NOR on SABRE AI only
 *   Note, SABRE AI SPI NOR signasl are mux'd with WEIM data bus
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
    gpio_set_direction(4, 18, GPIO_GDIR_OUTPUT);   // port=4, pin=18, dir=output
    // write GPIO4_18 as low (enable spi nor) or high (disable spi nor)
    gpio_set_level(4, 18, en_dis); // port=4, pin=18, en_dis (low or high)
}
#endif

/*!
 * Provide the power for TFT LCD backlight
 */
void tftlcd_backlight_en(char *panel_name)
{
#if !defined(EVB)               // todo: fix this
    /*GPIO to provide backlight */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
    gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
#endif
#if 0
#ifdef SABRE_AI
    /*lvds/parallel display backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_LOW_LEVEL);

    // lcd_contrast conflict with actual BoundaryDev display so seeting to input
    // since TSC not used on SABRE AI
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
    gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_INPUT);
#endif
#ifdef SMART_DEVICE
    /* AUX_3V15 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
#endif

}

/*!
 * Reset the TFT LCD
 */
void tftlcd_reset(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
#if (!defined(MX6SL) && defined(EVB))
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
        gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
#ifdef SMART_DEVICE
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_DA8, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_DA8, 0x1B0B0);
        gpio_set_direction(GPIO_PORT3, 8, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 8, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT3, 8, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
    }
}

/*!
 * Disable the display panel
 */
void disable_para_panel(void)
{
#if !defined(EVB)               // todo: fix this
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
#endif
}

/*!
 * enable mipi backlight
  */
void mipi_backlight_en(void)
{
    //configure pin19 of the mipi dsi/csi connector
#if (!defined(MX6SL) && defined(EVB))
    //set GPIO1_9 to 0 so clear vbus on board
    gpio_set_direction(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef SABRE_AI
    //default be populated by P3V3_DELAYED
#endif

#ifdef SMART_DEVICE
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_D0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_D0, 0x1B0B0);
    gpio_set_direction(GPIO_PORT2, 0, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 0, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * Provide the mipi camera power and reset
 */
void mipi_cam_power_on(void)
{
#if (!defined(MX6SL) && defined(EVB))
    /*reset of camera sensor, pin 27 */
    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);

    /*power supply through pin25 of connector, for cam_pdown, power down and then up */
    max7310_set_gpio_output(0, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
//    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);
#endif

#ifdef SABRE_AI
    /*power supply through pin25 of connector, direct connected to P3V3_DELAY,
       controlled by CPU_PER_RST_B */
    /*reset of camera sensor, together with the reset button */
    max7310_set_gpio_output(0, 2, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    max7310_set_gpio_output(0, 2, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

#endif

#ifdef SMART_DEVICE
    /*power supply through pin25 of connector, for cam_pdown */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);

    /*reset of camera sensor, pin 27 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
}

/*!
 * reset MIPI display
 */
void mipi_display_reset(void)
{
#if (!defined(MX6SL) && defined(EVB))
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT, 0x1b0b0);
    gpio_set_direction(GPIO_PORT5, 0, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT5, 0, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT5, 0, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif

#ifdef SABRE_AI
/*binded with the board reset button*/
#endif

#ifdef SMART_DEVICE
/*pin29 of mipi connector for the LCD reset*/
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0, 0x1b0b0);
    gpio_set_direction(GPIO_PORT6, 11, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 11, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT6, 11, GPIO_HIGH_LEVEL);
    hal_delay_us(1000);
#endif
}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol CEC
 * port including CEC_LINE
 */
void hdmi_tx_cec_pgm_iomux()
{
#if !defined(EVB)               // todo: fix this
    // config EIM_A25 pad for hdmi_tx instance CEC_LINE port
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_A25, ALT6);
    // Pad EIM_A25 is involved in Daisy Chain.
    reg32_write(IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT, 0x0);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_A25, 0x1f8b0);
#endif
}

/*!
 * config instance hdmi_tx of Module HDMI_TX to Protocol DDC
 * ports including DDC_SCL, DDC_SDA.
 */
void hdmi_tx_ddc_pgm_iomux()
{
#if !defined(EVB)               // todo: fix this
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
#endif
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
 * configure the epd display iomux pins
 */
void mxc_epdc_iomux_config(void)
{
    epdc_iomux_config();
}

void epdc_power_supply(void)
{
    int i = 0;

    //EN : pmic_wakeup gpio2.14
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_PWRWAKEUP, 0x05);
    gpio_set_direction(GPIO_PORT2, 14, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 14, GPIO_HIGH_LEVEL);

    //CEN : pmic_vcom gpio2.3 
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EPDC_VCOM0, 0x05);
    gpio_set_direction(GPIO_PORT2, 3, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 3, GPIO_HIGH_LEVEL);

    for (i = 0; i < 1000000; i++)
        __asm("nop");
}

/*!
 * Power no esai codec.
 * 
 */
int esai_codec_power_on(void)
{
    //No need do anything for mx6dq_sabre_ai
    return 0;
}

int ssi_get_sysclk_freq(void)
{
    return 63500000;
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
    gpio_set_direction(GPIO_PORT1, 7, GPIO_GDIR_INPUT);

    /* Power down - use PATA_DATA2 as active low output */
    /* Select ALT1 mode of PATA_DATA2 for GPIO2_2 */
    writel(ALT1, IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2);
    gpio_set_direction(GPIO_PORT2, 2, GPIO_GDIR_OUTPUT);
    /* Keep ADV7180 powered, as it is after board power up */
    gpio_set_level(GPIO_PORT2, 2, GPIO_HIGH_LEVEL);

    csi_iomux_config();
}

/*  Enable/disable power to ADV7180 - video in */
void video_in_set_power(int state)
{
    /* Power down - active low output */
    gpio_set_level(GPIO_PORT2, 2, state);
}
#endif
