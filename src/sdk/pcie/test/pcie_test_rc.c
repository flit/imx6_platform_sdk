/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "imx_i2c.h"
#include "soc_memory_map.h"
#include "../inc/pcie_common.h"
#include "../inc/pcie_prot.h"

extern int pcie_init(pcie_dm_mode_e dev_mode);

extern void (*pcie_func_clk_setup) (uint32_t enable);
extern void (*pcie_func_pwr_setup) (uint32_t enable);
extern void (*pcie_func_card_pwr_setup) (uint32_t enable);
extern void (*pcie_func_card_ref_clk_setup) (uint32_t enable);
extern void (*pcie_func_card_rst) (void);

/* Board specific routines, should move to hardware.c later.*/
void pcie_clk_setup(uint32_t enable)
{
    uint32_t val;

    if (enable) {
        // gate on pci-e clks
        val = reg32_read(CCM_CCGR4);
        val |= 0x3 << 0;
        reg32_write(CCM_CCGR4, val);

        // clear the powerdown bit
        reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 12);
        // enable pll
        reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 13);
        // wait the pll locked
        while (!(reg32_read(HW_ANADIG_PLL_ETH_CTRL) & (0x01 << 31))) ;
        // Disable bypass
        reg32clrbit(HW_ANADIG_PLL_ETH_CTRL, 16);
        // enable pci-e ref clk
        reg32setbit(HW_ANADIG_PLL_ETH_CTRL, 19);
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
        *ENET_PLL_REG |= ANATOP_SATA_CLK_ENABLE_MASK;

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

/*********************************************************************/
#define UNUSED_VARIABLE(x) (x) = (x);

pcie_resource_t ep1_resources[6];
uint32_t res_num = 6;

int pcie_test(void)
{
    uint32_t i;
    uint8_t ch;

    printf("\n---- Running PCIE test. Type 'y' to continue.\n");

    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);

    if ((ch != 'Y') && (ch != 'y')) {
        printf("\nTest exit.\n");
        return -1;
    }

    printf("Please make sure the mini pcie card inserted. Type\"y\" or \"Y\" to confirm.\n");
    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);

    if ((ch != 'Y') && (ch != 'y')) {
        printf("\nTest exit.\n");
        return -1;
    }

    pcie_func_clk_setup = pcie_clk_setup;
    pcie_func_card_rst = pcie_card_rst;
    pcie_func_card_ref_clk_setup = enable_extrn_100mhz_clk;
    pcie_func_card_pwr_setup = pcie_card_pwr_setup;

    if (0 != pcie_init(PCIE_DM_MODE_RC)) {
        printf("PCIE init failed.\n");
        return -1;
    } else {
        printf("PCIE init succeed. Link setup\n");
    }

    uint32_t phy_jtag_id_hi, phy_jtag_id_lo;

    pcie_phy_cr_read(SSP_CR_SUP_DIG_IDCODE_LO, &phy_jtag_id_lo);
    pcie_phy_cr_read(SSP_CR_SUP_DIG_IDCODE_HI, &phy_jtag_id_hi);

    if ((phy_jtag_id_lo == SSP_JTAG_DR_IDCODE_VAL_LO)
        && (phy_jtag_id_hi == SSP_JTAG_DR_IDCODE_VAL_HI)) {
        printf("Read phy's JTAG ID succeesefully. The ID is 0x%08x.\n",
               (phy_jtag_id_hi << 16) | phy_jtag_id_lo);
    } else {
        printf("Read phy's JTAG ID failed.\n");
        return -1;
    }

    printf("Remap the endpoint's configuration space to arm's memory space.\n");
    uint32_t cfg_hdr_base = pcie_map_space(PCIE_IATU_VIEWPORT_0,
                                           TLP_TYPE_CfgRdWr0,
                                           PCIE_ARB_BASE_ADDR, 0, SZ_64K);

    printf("Dump the endpoint's configuration header.\n");
    pcie_dump_cfg_header((uint32_t *) cfg_hdr_base);

    pcie_enum_resources((uint32_t *) cfg_hdr_base, ep1_resources, &res_num);

    printf("List the endpoint's resource requirement.\n");
    for (i = 0; i < res_num; i++) {
        printf("\tResourse%d\t", i);
        if (ep1_resources[i].type == RESOURCE_TYPE_IO) {
            printf("IO\t");
        } else {
            printf("Memory\t");
        }
        printf("%dbyte\t", ep1_resources[i].size);
        printf("\n");
    }

    printf("Allocate resources for the endpoint.\n");

    uint32_t viewport = PCIE_IATU_VIEWPORT_1;
    uint32_t ep_io_base = 0, ep_mem_base = 0, base_cpu_side = PCIE_ARB_BASE_ADDR + SZ_64K;
    uint32_t tlp_type, size, bar, *ep_base;
    char *str_space[] = { "IO", "Memory" };
    char *str;

    for (i = 0; i < res_num; i++, viewport++) {
        bar = ep1_resources[i].bar;
        size = ep1_resources[i].size;
        if (ep1_resources[i].type == RESOURCE_TYPE_IO) {
            ep_base = &ep_io_base;
            tlp_type = TLP_TYPE_IORdWr;
            str = str_space[0];
            base_cpu_side = (base_cpu_side + 0xFF) & (~0xFF);
        } else if (ep1_resources[i].type == RESOURCE_TYPE_MEM) {
            ep_base = &ep_mem_base;
            tlp_type = TLP_TYPE_MemRdWr;
            str = str_space[1];
            // 4 Kbyre alligned
            base_cpu_side = (base_cpu_side + 0xFFF) & (~0xFFF);
        }

        printf("Map endpoint's bar%d %s space %d byte to CPU memory base 0x%x.\n ", bar, str, size,
               base_cpu_side);
        pcie_cfg_ep_bar(cfg_hdr_base, bar, *ep_base, ~(size - 1));
        ep1_resources[i].base = pcie_map_space(viewport, tlp_type, base_cpu_side, *ep_base, size);
        *ep_base += size;
        base_cpu_side += size;
    }

    printf("Dump configuration header again.\n");
    pcie_dump_cfg_header((uint32_t *) cfg_hdr_base);

#if 0
    printf("Write words to endpoint's memory space and read them back to verified.\n");

    uint8_t *mem_space_base = (uint8_t *) ep1_resources[1].base;

    printf("Write word to 0x%08x\n", (uint32_t) mem_space_base);
    *mem_space_base = 0x12;

    printf("Read back: 0x%08x vs 0x%08x\n", *mem_space_base, 0x12);
#endif

    return 0;
}
