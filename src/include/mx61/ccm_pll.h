/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _CCM_PLL_H_
#define _CCM_PLL_H_

#include "registers.h"

//#########################################
//# DPLLIP peripheral defines
//#########################################
#define DPLLIP_DP_CTL_OFFSET	0x000
#define DPLLIP_DP_CONFIG_OFFSET	0x004
#define DPLLIP_DP_OP_OFFSET	0x008
#define DPLLIP_DP_MFD_OFFSET	0x00C
#define DPLLIP_DP_MFN_OFFSET	0x010
#define DPLLIP_DP_MFNMINUS_OFFSET	0x014
#define DPLLIP_DP_MFNPLUS_OFFSET	0x018
#define DPLLIP_DP_HFS_OP_OFFSET	0x01C
#define DPLLIP_DP_HFS_MFD_OFFSET	0x020
#define DPLLIP_DP_HFS_MFN_OFFSET	0x024
#define DPLLIP_DP_MFN_TOGC_OFFSET	0x028
#define DPLLIP_DP_DESTAT_OFFSET	0x02C

#define DPLLIP1_DP_CONFIG          DPLLIP1_BASE_ADDR+DPLLIP_DP_CONFIG_OFFSET
#define DPLLIP1_DP_CTL             DPLLIP1_BASE_ADDR+DPLLIP_DP_CTL_OFFSET
#define DPLLIP1_DP_OP              DPLLIP1_BASE_ADDR+DPLLIP_DP_OP_OFFSET
#define DPLLIP1_DP_MFD             DPLLIP1_BASE_ADDR+DPLLIP_DP_MFD_OFFSET
#define DPLLIP1_DP_MFN             DPLLIP1_BASE_ADDR+DPLLIP_DP_MFN_OFFSET

#define DPLLIP2_DP_CONFIG          DPLLIP2_BASE_ADDR+DPLLIP_DP_CONFIG_OFFSET
#define DPLLIP2_DP_CTL             DPLLIP2_BASE_ADDR+DPLLIP_DP_CTL_OFFSET
#define DPLLIP2_DP_OP              DPLLIP2_BASE_ADDR+DPLLIP_DP_OP_OFFSET
#define DPLLIP2_DP_MFD             DPLLIP2_BASE_ADDR+DPLLIP_DP_MFD_OFFSET
#define DPLLIP2_DP_MFN             DPLLIP2_BASE_ADDR+DPLLIP_DP_MFN_OFFSET

#define DPLLIP3_DP_CONFIG          DPLLIP3_BASE_ADDR+DPLLIP_DP_CONFIG_OFFSET
#define DPLLIP3_DP_CTL             DPLLIP3_BASE_ADDR+DPLLIP_DP_CTL_OFFSET
#define DPLLIP3_DP_OP              DPLLIP3_BASE_ADDR+DPLLIP_DP_OP_OFFSET
#define DPLLIP3_DP_MFD             DPLLIP3_BASE_ADDR+DPLLIP_DP_MFD_OFFSET
#define DPLLIP3_DP_MFN             DPLLIP3_BASE_ADDR+DPLLIP_DP_MFN_OFFSET

//#########################################
//# CCM peripheral defines
//#########################################
#define CCM_CCR     CCM_BASE_ADDR+CCM_CCR_OFFSET
#define CCM_CCDR    CCM_BASE_ADDR+CCM_CCDR_OFFSET
#define CCM_CSR     CCM_BASE_ADDR+CCM_CSR_OFFSET
#define CCM_CCSR    CCM_BASE_ADDR+CCM_CCSR_OFFSET
#define CCM_CACRR   CCM_BASE_ADDR+CCM_CACRR_OFFSET
#define CCM_CBCDR   CCM_BASE_ADDR+CCM_CBCDR_OFFSET
#define CCM_CBCMR   CCM_BASE_ADDR+CCM_CBCMR_OFFSET
#define CCM_CSCMR1  CCM_BASE_ADDR+CCM_CSCMR1_OFFSET
#define CCM_CSCMR2  CCM_BASE_ADDR+CCM_CSCMR2_OFFSET
#define CCM_CSCDR1  CCM_BASE_ADDR+CCM_CSCDR1_OFFSET
#define CCM_CS1CDR  CCM_BASE_ADDR+CCM_CS1CDR_OFFSET
#define CCM_CS2CDR  CCM_BASE_ADDR+CCM_CS2CDR_OFFSET
#define CCM_CDCDR   CCM_BASE_ADDR+CCM_CDCDR_OFFSET
#define CCM_CHSCCDR CCM_BASE_ADDR+CCM_CHSCCDR_OFFSET
#define CCM_CSCDR2  CCM_BASE_ADDR+CCM_CSCDR2_OFFSET
#define CCM_CSCDR3  CCM_BASE_ADDR+CCM_CSCDR3_OFFSET
#define CCM_CSCDR4  CCM_BASE_ADDR+CCM_CSCDR4_OFFSET
#define CCM_CWDR    CCM_BASE_ADDR+CCM_CWDR_OFFSET
#define CCM_CDHIPR  CCM_BASE_ADDR+CCM_CDHIPR_OFFSET
#define CCM_CDCR    CCM_BASE_ADDR+CCM_CDCR_OFFSET
#define CCM_CTOR    CCM_BASE_ADDR+CCM_CTOR_OFFSET
#define CCM_CLPCR   CCM_BASE_ADDR+CCM_CLPCR_OFFSET
#define CCM_CISR    CCM_BASE_ADDR+CCM_CISR_OFFSET
#define CCM_CIMR    CCM_BASE_ADDR+CCM_CIMR_OFFSET
#define CCM_CCOSR   CCM_BASE_ADDR+CCM_CCOSR_OFFSET
#define CCM_CGPR    CCM_BASE_ADDR+CCM_CGPR_OFFSET
#define CCM_CCGR0   CCM_BASE_ADDR+CCM_CCGR0_OFFSET
#define CCM_CCGR1   CCM_BASE_ADDR+CCM_CCGR1_OFFSET
#define CCM_CCGR2   CCM_BASE_ADDR+CCM_CCGR2_OFFSET
#define CCM_CCGR3   CCM_BASE_ADDR+CCM_CCGR3_OFFSET
#define CCM_CCGR4   CCM_BASE_ADDR+CCM_CCGR4_OFFSET
#define CCM_CCGR5   CCM_BASE_ADDR+CCM_CCGR5_OFFSET
#define CCM_CCGR6   CCM_BASE_ADDR+CCM_CCGR6_OFFSET
#define CCM_CCGR7   CCM_BASE_ADDR+CCM_CCGR7_OFFSET
#define CCM_CMEOR   CCM_BASE_ADDR+CCM_CMEOR_OFFSET

//#########################################
//# CCM peripheral defines used by prog_pll.c and hardware.c
//#########################################
#define CLKCTL_CCGR1        CCM_CCGR1_OFFSET
#define CLKCTL_CSCMR1       CCM_CSCMR1_OFFSET
#define CLKCTL_CSCDR1       CCM_CSCDR1_OFFSET
#define CLKCTL_CBCMR        CCM_CBCMR_OFFSET
#define CLKCTL_CBCDR        CCM_CBCDR_OFFSET
#define CLKCTL_CCSR         CCM_CCSR_OFFSET
#define CLKCTL_CDHIPR       CCM_CDHIPR_OFFSET
#define CLKCTL_CACRR        CCM_CACRR_OFFSET
#define CLKCTL_CSCDR2       CCM_CSCDR2_OFFSET
#define CLKCTL_CS1CDR       CCM_CS1CDR_OFFSET
#define CLKCTL_CS2CDR       CCM_CS2CDR_OFFSET

#define CLKCTL_CSCMR2       CCM_CSCMR2_OFFSET

#define PLL1_BASE_ADDR      DPLLIP1_BASE_ADDR
#define PLL2_BASE_ADDR      DPLLIP2_BASE_ADDR
#define PLL3_BASE_ADDR      DPLLIP3_BASE_ADDR
#define PLL4_BASE_ADDR      DPLLIP4_BASE_ADDR

#define PLL_DP_CTL          DPLLIP_DP_CTL_OFFSET
#define PLL_DP_CONFIG       DPLLIP_DP_CONFIG_OFFSET
#define PLL_DP_OP           DPLLIP_DP_OP_OFFSET
#define PLL_DP_MFD          DPLLIP_DP_MFD_OFFSET
#define PLL_DP_MFN          DPLLIP_DP_MFN_OFFSET
#define PLL_DP_MFNMINUS     DPLLIP_DP_MFNMINUS_OFFSET
#define PLL_DP_MFNPLUS      DPLLIP_DP_MFNPLUS_OFFSET
#define PLL_DP_HFS_OP       DPLLIP_DP_HFS_OP_OFFSET
#define PLL_DP_HFS_MFD      DPLLIP_DP_HFS_MFD_OFFSET
#define PLL_DP_HFS_MFN      DPLLIP_DP_HFS_MFN_OFFSET
#define PLL_DP_TOGC         DPLLIP_DP_MFN_TOGC_OFFSET
#define PLL_DP_DESTAT       DPLLIP_DP_DESTAT_OFFSET

#define CLK_SRC_32K         32768

/* x=0..15 - CG0 to CG15 */
#define CG(x) (3 << (x*2))
#define CLOCK_ON        0x3
#define CLOCK_ON_RUN    0x1
#define CLOCK_OFF       0x0

/* defines to extract divider or sel value */ 
#define periph_clk2_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 27) + 1)
#define mmdc_ch0_axi_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 19) + 1)
#define axi_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 16) + 1)
#define ahb_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 10) + 1)
#define ipg_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 2, 8) + 1)
#define mmdc_ch1_axi_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 3) + 1)
#define periph2_clk2_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CBCDR), 3, 0) + 1)

#define perclk_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCMR1),6,0) + 1)

#define pre_periph_clk_sel_ GET_FIELD(*(volatile uint32_t *)(CCM_CBCMR),2,18)


#define vpu_axi_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),3,25) + 1)
#define usdhc4_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),3,22) + 1)
#define usdhc3_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),3,19) + 1)
#define usdhc2_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),3,16) + 1)
#define usdhc1_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),3,11) + 1)
#define uart_clk_podf_ (GET_FIELD(*(volatile uint32_t *)(CCM_CSCDR1),6,0) + 1)

enum main_clocks {
    CPU_CLK,
    AXI_CLK,
    MMDC_CH0_AXI_CLK,
    AHB_CLK,
    IPG_CLK,
    IPG_PER_CLK,
    MMDC_CH1_AXI_CLK,
};

enum peri_clocks {
    UART1_BAUD,
    UART2_BAUD,
    UART3_BAUD,
    UART4_BAUD,
    SSI1_BAUD,
    SSI2_BAUD,
    CSI_BAUD,
    MSTICK1_CLK,
    MSTICK2_CLK,
    NFC_CLK,
    USB_CLK,
    VPU_CLK,
    SPI1_CLK = ECSPI1_BASE_ADDR,
    SPI2_CLK = ECSPI2_BASE_ADDR,
};

enum plls {
    PLL1,
    PLL2,
    PLL3,
    PLL4,
    PLL5,
};

static const uint32_t PLL1_OUTPUT = 792000000;
static const uint32_t PLL2_OUTPUT[] = {528000000,396000000,352000000,198000000,594000000};
static const uint32_t PLL3_OUTPUT[] = {480000000,720000000,540000000,508235294,454736842};
static const uint32_t PLL4_OUTPUT = 650000000;
static const uint32_t PLL5_OUTPUT = 650000000;

void clock_gating_config(uint32_t base_address, uint8_t gating_mode);
uint32_t get_main_clock(enum main_clocks clk);
uint32_t get_peri_clock(enum peri_clocks clk);
void ccm_init(void);

#endif
