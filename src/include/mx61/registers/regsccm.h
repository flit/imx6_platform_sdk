/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CCM_H
#define _CCM_H

#include "regs.h"

#ifndef REGS_CCM_BASE
#define REGS_CCM_BASE (REGS_BASE + 0x020c4000)
#endif


/*!
 * @brief HW_CCM_CCR - CCM Control Register
 *
 * The figure below represents the CCM Control Register (CCR), which
 * contains bits to control general operation of CCM. The table below
 * provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OSCNT : 8; //!< Oscillator ready counter value. These bits define value of 32KHz counter, that serve as counter for oscillator lock time. This is used for oscillator lock time. Current estimation is ~5ms. This counter will be used in ignition sequence and in wake from stop sequence if sbyos bit was defined, to notify that on chip oscillator output is ready for the dpll_ip to use and only then the gate in dpll_ip can be opened.
        unsigned RESERVED : 4; //!< Reserved
        unsigned COSC_EN : 1; //!< On chip oscillator enable bit - this bit value is reflected on the output cosc_en. The system will start with on chip oscillator enabled to supply source for the PLL's. Software can change this bit if a transition to the bypass PLL clocks was performed for all the PLLs. In cases that this bit is changed from '0' to '1' then CCM will enable the on chip oscillator and after counting oscnt ckil clock cycles it will notify that on chip oscillator is ready by a interrupt cosc_ready and by status bit cosc_ready. The cosc_en bit should be changed only when on chip oscillator is not chosen as the clock source.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned WB_COUNT : 3; //!< Well Bias counter. Delay, defined by this value, counted by CKIL clock will be applied till well ties are enabled at exit from wait or stop low power mode. Counter will be used if wb_core_at_lpm or wb_per_at_lpm bits are set. Should be zeroed and reconfigured after exit from low power mode.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REG_BYPASS_COUNT : 6; //!< Counter for anatop_reg_bypass signal assertion after standby voltage request by pmic_vstby_req. Should be zeroed and reconfigured after exit from low power mode.
        unsigned RBC_EN : 1; //!< Enable for REG_BYPASS_COUNTER. If enabled, anatop_reg_bypass signal will be asserted after REG_BYPASS_COUNT clocks of CKIL, after standby voltage is requested. If standby voltage is not requested anatop_reg_bypass won't be asserted, event if counter is enabled.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_ccm_ccr_t;
#endif

/*
 * constants & macros for entire CCM_CCR register
 */
#define HW_CCM_CCR_ADDR      (REGS_CCM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCR           (*(volatile hw_ccm_ccr_t *) HW_CCM_CCR_ADDR)
#define HW_CCM_CCR_RD()      (HW_CCM_CCR.U)
#define HW_CCM_CCR_WR(v)     (HW_CCM_CCR.U = (v))
#define HW_CCM_CCR_SET(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() |  (v)))
#define HW_CCM_CCR_CLR(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() & ~(v)))
#define HW_CCM_CCR_TOG(v)    (HW_CCM_CCR_WR(HW_CCM_CCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCR bitfields
 */

/* --- Register HW_CCM_CCR, field OSCNT
 *
 * Oscillator ready counter value. These bits define value of 32KHz
 * counter, that serve as counter for oscillator lock time. This is
 * used for oscillator lock time. Current estimation is ~5ms. This
 * counter will be used in ignition sequence and in wake from stop
 * sequence if sbyos bit was defined, to notify that on chip oscillator
 * output is ready for the dpll_ip to use and only then the gate in
 * dpll_ip can be opened.
 */

#define BP_CCM_CCR_OSCNT      0
#define BM_CCM_CCR_OSCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_OSCNT(v)   ((((reg32_t) v) << 0) & BM_CCM_CCR_OSCNT)
#else
#define BF_CCM_CCR_OSCNT(v)   (((v) << 0) & BM_CCM_CCR_OSCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_OSCNT(v)   BF_CS1(CCM_CCR, OSCNT, v)
#endif

/* --- Register HW_CCM_CCR, field RESERVED
 *
 * Reserved
 */

#define BP_CCM_CCR_RESERVED      8
#define BM_CCM_CCR_RESERVED      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_RESERVED(v)   ((((reg32_t) v) << 8) & BM_CCM_CCR_RESERVED)
#else
#define BF_CCM_CCR_RESERVED(v)   (((v) << 8) & BM_CCM_CCR_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_RESERVED(v)   BF_CS1(CCM_CCR, RESERVED, v)
#endif

/* --- Register HW_CCM_CCR, field COSC_EN
 *
 * On chip oscillator enable bit - this bit value is reflected on the
 * output cosc_en. The system will start with on chip oscillator
 * enabled to supply source for the PLL's. Software can change this bit
 * if a transition to the bypass PLL clocks was performed for all the
 * PLLs. In cases that this bit is changed from '0' to '1' then CCM
 * will enable the on chip oscillator and after counting oscnt ckil
 * clock cycles it will notify that on chip oscillator is ready by a
 * interrupt cosc_ready and by status bit cosc_ready. The cosc_en bit
 * should be changed only when on chip oscillator is not chosen as the
 * clock source.
 */

#define BP_CCM_CCR_COSC_EN      12
#define BM_CCM_CCR_COSC_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_COSC_EN(v)   ((((reg32_t) v) << 12) & BM_CCM_CCR_COSC_EN)
#else
#define BF_CCM_CCR_COSC_EN(v)   (((v) << 12) & BM_CCM_CCR_COSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_COSC_EN(v)   BF_CS1(CCM_CCR, COSC_EN, v)
#endif

/* --- Register HW_CCM_CCR, field WB_COUNT
 *
 * Well Bias counter. Delay, defined by this value, counted by CKIL clock will be applied till well
 * ties are enabled at exit from wait or stop low power mode. Counter will be used if wb_core_at_lpm
 * or wb_per_at_lpm bits are set. Should be zeroed and reconfigured after exit from low power mode.
 */

#define BP_CCM_CCR_WB_COUNT      16
#define BM_CCM_CCR_WB_COUNT      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_WB_COUNT(v)   ((((reg32_t) v) << 16) & BM_CCM_CCR_WB_COUNT)
#else
#define BF_CCM_CCR_WB_COUNT(v)   (((v) << 16) & BM_CCM_CCR_WB_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_WB_COUNT(v)   BF_CS1(CCM_CCR, WB_COUNT, v)
#endif

/* --- Register HW_CCM_CCR, field REG_BYPASS_COUNT
 *
 * Counter for anatop_reg_bypass signal assertion after standby voltage request by pmic_vstby_req.
 * Should be zeroed and reconfigured after exit from low power mode.
 */

#define BP_CCM_CCR_REG_BYPASS_COUNT      21
#define BM_CCM_CCR_REG_BYPASS_COUNT      0x07e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   ((((reg32_t) v) << 21) & BM_CCM_CCR_REG_BYPASS_COUNT)
#else
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   (((v) << 21) & BM_CCM_CCR_REG_BYPASS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_REG_BYPASS_COUNT(v)   BF_CS1(CCM_CCR, REG_BYPASS_COUNT, v)
#endif

/* --- Register HW_CCM_CCR, field RBC_EN
 *
 * Enable for REG_BYPASS_COUNTER. If enabled, anatop_reg_bypass signal
 * will be asserted after REG_BYPASS_COUNT clocks of CKIL, after
 * standby voltage is requested. If standby voltage is not requested
 * anatop_reg_bypass won't be asserted, event if counter is                                 enabled.
 */

#define BP_CCM_CCR_RBC_EN      27
#define BM_CCM_CCR_RBC_EN      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCR_RBC_EN(v)   ((((reg32_t) v) << 27) & BM_CCM_CCR_RBC_EN)
#else
#define BF_CCM_CCR_RBC_EN(v)   (((v) << 27) & BM_CCM_CCR_RBC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCR_RBC_EN(v)   BF_CS1(CCM_CCR, RBC_EN, v)
#endif

/*!
 * @brief HW_CCM_CCDR - CCM Control Divider Register
 *
 * The figure below represents the CCM Control Divider Register (CCDR),
 * which contains bits that control the loading of the dividers that need
 * handshake with the modules they affect. The table below provides its
 * field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned MMDC_CH1_MASK : 1; //!< During divider ratio mmdc_ch1_axi_podf change or sync mux periph2_clk_sel change (but not jtag) or SRC request during warm reset, mask handshake with mmdc_ch1 module.
        unsigned MMDC_CH0_MASK : 1; //!< During divider ratio mmdc_ch0_axi_podf change or sync mux periph_clk_sel change (but not jtag) or SRC request during warm reset, mask handshake with mmdc_ch0 module.
        unsigned RESERVED1 : 14; //!< Reserved
    } B;
} hw_ccm_ccdr_t;
#endif

/*
 * constants & macros for entire CCM_CCDR register
 */
#define HW_CCM_CCDR_ADDR      (REGS_CCM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCDR           (*(volatile hw_ccm_ccdr_t *) HW_CCM_CCDR_ADDR)
#define HW_CCM_CCDR_RD()      (HW_CCM_CCDR.U)
#define HW_CCM_CCDR_WR(v)     (HW_CCM_CCDR.U = (v))
#define HW_CCM_CCDR_SET(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() |  (v)))
#define HW_CCM_CCDR_CLR(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() & ~(v)))
#define HW_CCM_CCDR_TOG(v)    (HW_CCM_CCDR_WR(HW_CCM_CCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCDR bitfields
 */

/* --- Register HW_CCM_CCDR, field MMDC_CH1_MASK
 *
 * During divider ratio mmdc_ch1_axi_podf change or sync mux
 * periph2_clk_sel change (but not jtag) or SRC request during warm
 * reset, mask handshake with mmdc_ch1 module.
 */

#define BP_CCM_CCDR_MMDC_CH1_MASK      16
#define BM_CCM_CCDR_MMDC_CH1_MASK      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   ((((reg32_t) v) << 16) & BM_CCM_CCDR_MMDC_CH1_MASK)
#else
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   (((v) << 16) & BM_CCM_CCDR_MMDC_CH1_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCDR_MMDC_CH1_MASK(v)   BF_CS1(CCM_CCDR, MMDC_CH1_MASK, v)
#endif

/* --- Register HW_CCM_CCDR, field MMDC_CH0_MASK
 *
 * During divider ratio mmdc_ch0_axi_podf change or sync mux
 * periph_clk_sel change (but not jtag) or SRC request during warm
 * reset, mask handshake with mmdc_ch0 module.
 */

#define BP_CCM_CCDR_MMDC_CH0_MASK      17
#define BM_CCM_CCDR_MMDC_CH0_MASK      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   ((((reg32_t) v) << 17) & BM_CCM_CCDR_MMDC_CH0_MASK)
#else
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   (((v) << 17) & BM_CCM_CCDR_MMDC_CH0_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCDR_MMDC_CH0_MASK(v)   BF_CS1(CCM_CCDR, MMDC_CH0_MASK, v)
#endif

/*!
 * @brief HW_CCM_CSR - CCM Status Register
 *
 * The figure below represents the CCM status Register (CSR). The status
 * bits are read only bits. The table below provides its field
 * descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned REF_EN_B : 1; //!< Status of the value of ref_en_b output of ccm
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned COSC_READY : 1; //!< Status indication of on board oscillator. This bit will be asserted if on chip oscillator is enabled and on chip oscillator is not powered down, and if oscnt counter has finished counting.
        unsigned RESERVED2 : 26; //!< Reserved
    } B;
} hw_ccm_csr_t;
#endif

/*
 * constants & macros for entire CCM_CSR register
 */
#define HW_CCM_CSR_ADDR      (REGS_CCM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSR           (*(volatile hw_ccm_csr_t *) HW_CCM_CSR_ADDR)
#define HW_CCM_CSR_RD()      (HW_CCM_CSR.U)
#define HW_CCM_CSR_WR(v)     (HW_CCM_CSR.U = (v))
#define HW_CCM_CSR_SET(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() |  (v)))
#define HW_CCM_CSR_CLR(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() & ~(v)))
#define HW_CCM_CSR_TOG(v)    (HW_CCM_CSR_WR(HW_CCM_CSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSR bitfields
 */

/* --- Register HW_CCM_CSR, field REF_EN_B
 *
 * Status of the value of ref_en_b output of ccm
 */

#define BP_CCM_CSR_REF_EN_B      0
#define BM_CCM_CSR_REF_EN_B      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSR_REF_EN_B(v)   ((((reg32_t) v) << 0) & BM_CCM_CSR_REF_EN_B)
#else
#define BF_CCM_CSR_REF_EN_B(v)   (((v) << 0) & BM_CCM_CSR_REF_EN_B)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSR_REF_EN_B(v)   BF_CS1(CCM_CSR, REF_EN_B, v)
#endif

/* --- Register HW_CCM_CSR, field COSC_READY
 *
 * Status indication of on board oscillator. This bit will be asserted
 * if on chip oscillator is enabled and on chip oscillator is not
 * powered down, and if oscnt counter has finished counting.
 */

#define BP_CCM_CSR_COSC_READY      5
#define BM_CCM_CSR_COSC_READY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSR_COSC_READY(v)   ((((reg32_t) v) << 5) & BM_CCM_CSR_COSC_READY)
#else
#define BF_CCM_CSR_COSC_READY(v)   (((v) << 5) & BM_CCM_CSR_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSR_COSC_READY(v)   BF_CS1(CCM_CSR, COSC_READY, v)
#endif

/*!
 * @brief HW_CCM_CCSR - CCM Clock Swither Register
 *
 * The figure below represents the CCM Clock Switcher register (CCSR). The
 * CCSR register contains bits to control the switcher sub module dividers
 * and multiplexers. The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PLL3_SW_CLK_SEL : 1; //!< Selects source to generate pll3_sw_clk. This bit should only be used for testing purposes.  Note: this bit will be ored with pll_bypass_en3 signal. If one of the sources requests to move to pll3 bypass clk (pll3_sw_clk=1 or pll_bypass_en3=1) then the pll3_sw_clk will be pll3 bypass clk. Only if both sources request pll3_main_clk (pll3_sw_clk=0 and pll_bypass_en3=0) then the pll3_sw_clk will be pll3_main_clk.
        unsigned PLL2_SW_CLK_SEL : 1; //!< Selects source to generate pll2_sw_clk. This bit should only be used for testing purposes.  Note: this bit will be ored with pll_bypass_en2 signal. If one of the sources requests to move to pll2 bypass clk (pll2_sw_clk=1 or pll_bypass_en2=1) then the pll2_sw_clk will be pll2 bypass clk. Only if both sources request pll2_main_clk (pll2_sw_clk=0 and pll_bypass_en2=0) then the pll2_sw_clk will be pll2_main_clk.
        unsigned PLL1_SW_CLK_SEL : 1; //!< Selects source to generate pll1_sw_clk.  Note: this bit will be ored with pll_bypass_en1 signal and dvfs_control signal. If one of the sources requests to move to step_clk (pll1_sw_clk=1 or pll_bypass_en1=1 or dvfs_control=1) then the pll1_sw_clk will be step_clk. Only if both sources request pll1_main_clk (pll1_sw_clk=0 and pll_bypass_en1=0 and dvfs_control=0) then the pll1_sw_clk will be pll1_main_clk.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned STEP_SEL : 1; //!< Selects the option to be chosen for the step frequency when shifting ARM frequency. this will control the step_clk.  Note: this mux is allowed to be changed only if its output is not used, i.e. ARM uses the output of pll1, and step_clk is not used.
        unsigned PDF_396M_DIS_MASK : 1; //!< Mask of 396M PFD auto-disable.
        unsigned PDF_352M_DIS_MASK : 1; //!< Mask of 352M PFD auto-disable.
        unsigned PDF_594M_DIS_MASK : 1; //!< Mask of 594M PFD auto-disable.
        unsigned PDF_508M_DIS_MASK : 1; //!< Mask of 508M PFD auto-disable.
        unsigned PDF_454M_DIS_MASK : 1; //!< Mask of 454M PFD auto-disable.
        unsigned PDF_720M_DIS_MASK : 1; //!< Mask of 720M PFD auto-disable.
        unsigned PDF_540M_DIS_MASK : 1; //!< Mask of 540M PFD auto-disable.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_ccm_ccsr_t;
#endif

/*
 * constants & macros for entire CCM_CCSR register
 */
#define HW_CCM_CCSR_ADDR      (REGS_CCM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCSR           (*(volatile hw_ccm_ccsr_t *) HW_CCM_CCSR_ADDR)
#define HW_CCM_CCSR_RD()      (HW_CCM_CCSR.U)
#define HW_CCM_CCSR_WR(v)     (HW_CCM_CCSR.U = (v))
#define HW_CCM_CCSR_SET(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() |  (v)))
#define HW_CCM_CCSR_CLR(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() & ~(v)))
#define HW_CCM_CCSR_TOG(v)    (HW_CCM_CCSR_WR(HW_CCM_CCSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCSR bitfields
 */

/* --- Register HW_CCM_CCSR, field PLL3_SW_CLK_SEL
 *
 * Selects source to generate pll3_sw_clk. This bit should only be used
 * for testing purposes.  Note: this bit will be ored with pll_bypass_en3 signal. If one of the
 * sources requests to move to pll3 bypass clk (pll3_sw_clk=1 or
 * pll_bypass_en3=1) then the pll3_sw_clk will be pll3 bypass clk. Only
 * if both sources request pll3_main_clk (pll3_sw_clk=0 and
 * pll_bypass_en3=0) then the pll3_sw_clk will be pll3_main_clk.
 */

#define BP_CCM_CCSR_PLL3_SW_CLK_SEL      0
#define BM_CCM_CCSR_PLL3_SW_CLK_SEL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   (((v) << 0) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL3_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL3_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PLL2_SW_CLK_SEL
 *
 * Selects source to generate pll2_sw_clk. This bit should only be used
 * for testing purposes.  Note: this bit will be ored with pll_bypass_en2 signal. If one of the
 * sources requests to move to pll2 bypass clk (pll2_sw_clk=1 or
 * pll_bypass_en2=1) then the pll2_sw_clk will be pll2 bypass clk. Only
 * if both sources request pll2_main_clk (pll2_sw_clk=0 and
 * pll_bypass_en2=0) then the pll2_sw_clk will be pll2_main_clk.
 */

#define BP_CCM_CCSR_PLL2_SW_CLK_SEL      1
#define BM_CCM_CCSR_PLL2_SW_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   (((v) << 1) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL2_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL2_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PLL1_SW_CLK_SEL
 *
 * Selects source to generate pll1_sw_clk.  Note: this bit will be ored with pll_bypass_en1 signal
 * and                                 dvfs_control signal. If one of the sources requests to move
 * to                                 step_clk (pll1_sw_clk=1 or pll_bypass_en1=1 or dvfs_control=1)
 * then                                 the pll1_sw_clk will be step_clk. Only if both sources
 * request                                 pll1_main_clk (pll1_sw_clk=0 and pll_bypass_en1=0 and
 * dvfs_control=0) then the pll1_sw_clk will be pll1_main_clk.
 */

#define BP_CCM_CCSR_PLL1_SW_CLK_SEL      2
#define BM_CCM_CCSR_PLL1_SW_CLK_SEL      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   ((((reg32_t) v) << 2) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#else
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   (((v) << 2) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PLL1_SW_CLK_SEL(v)   BF_CS1(CCM_CCSR, PLL1_SW_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field STEP_SEL
 *
 * Selects the option to be chosen for the step frequency when shifting
 * ARM frequency. this will control the step_clk.  Note: this mux is allowed to be changed only if
 * its output is not                                 used, i.e. ARM uses the output of pll1, and
 * step_clk is not                                 used.
 */

#define BP_CCM_CCSR_STEP_SEL      8
#define BM_CCM_CCSR_STEP_SEL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_STEP_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CCSR_STEP_SEL)
#else
#define BF_CCM_CCSR_STEP_SEL(v)   (((v) << 8) & BM_CCM_CCSR_STEP_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_STEP_SEL(v)   BF_CS1(CCM_CCSR, STEP_SEL, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_396M_DIS_MASK
 *
 * Mask of 396M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_396M_DIS_MASK      9
#define BM_CCM_CCSR_PDF_396M_DIS_MASK      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   ((((reg32_t) v) << 9) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   (((v) << 9) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_396M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_396M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_352M_DIS_MASK
 *
 * Mask of 352M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_352M_DIS_MASK      10
#define BM_CCM_CCSR_PDF_352M_DIS_MASK      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   ((((reg32_t) v) << 10) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   (((v) << 10) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_352M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_352M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_594M_DIS_MASK
 *
 * Mask of 594M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_594M_DIS_MASK      11
#define BM_CCM_CCSR_PDF_594M_DIS_MASK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   ((((reg32_t) v) << 11) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   (((v) << 11) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_594M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_594M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_508M_DIS_MASK
 *
 * Mask of 508M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_508M_DIS_MASK      12
#define BM_CCM_CCSR_PDF_508M_DIS_MASK      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   ((((reg32_t) v) << 12) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   (((v) << 12) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_508M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_508M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_454M_DIS_MASK
 *
 * Mask of 454M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_454M_DIS_MASK      13
#define BM_CCM_CCSR_PDF_454M_DIS_MASK      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   ((((reg32_t) v) << 13) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   (((v) << 13) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_454M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_454M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_720M_DIS_MASK
 *
 * Mask of 720M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_720M_DIS_MASK      14
#define BM_CCM_CCSR_PDF_720M_DIS_MASK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   ((((reg32_t) v) << 14) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   (((v) << 14) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_720M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_720M_DIS_MASK, v)
#endif

/* --- Register HW_CCM_CCSR, field PDF_540M_DIS_MASK
 *
 * Mask of 540M PFD auto-disable.
 */

#define BP_CCM_CCSR_PDF_540M_DIS_MASK      15
#define BM_CCM_CCSR_PDF_540M_DIS_MASK      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   ((((reg32_t) v) << 15) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#else
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   (((v) << 15) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCSR_PDF_540M_DIS_MASK(v)   BF_CS1(CCM_CCSR, PDF_540M_DIS_MASK, v)
#endif

/*!
 * @brief HW_CCM_CACRR - CCM Arm Clock Root Register
 *
 * The figure below represents the CCM Arm Clock Root register (CACRR). The
 * CACRR register contains bits to control the ARM clock root generation.
 * The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ARM_PODF_ : 3; //!< Divider for ARM clock root. Note: if arm_freq_shift_divider is set to '1' then any new write to arm_podf will be held until arm_clk_switch_req signal is asserted.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_ccm_cacrr_t;
#endif

/*
 * constants & macros for entire CCM_CACRR register
 */
#define HW_CCM_CACRR_ADDR      (REGS_CCM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CACRR           (*(volatile hw_ccm_cacrr_t *) HW_CCM_CACRR_ADDR)
#define HW_CCM_CACRR_RD()      (HW_CCM_CACRR.U)
#define HW_CCM_CACRR_WR(v)     (HW_CCM_CACRR.U = (v))
#define HW_CCM_CACRR_SET(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() |  (v)))
#define HW_CCM_CACRR_CLR(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() & ~(v)))
#define HW_CCM_CACRR_TOG(v)    (HW_CCM_CACRR_WR(HW_CCM_CACRR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CACRR bitfields
 */

/* --- Register HW_CCM_CACRR, field ARM_PODF_
 *
 * Divider for ARM clock root. Note: if arm_freq_shift_divider is set to
 * '1' then any new write to arm_podf will be held until
 * arm_clk_switch_req signal is asserted.
 */

#define BP_CCM_CACRR_ARM_PODF_      0
#define BM_CCM_CACRR_ARM_PODF_      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CACRR_ARM_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CACRR_ARM_PODF_)
#else
#define BF_CCM_CACRR_ARM_PODF_(v)   (((v) << 0) & BM_CCM_CACRR_ARM_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CACRR_ARM_PODF_(v)   BF_CS1(CCM_CACRR, ARM_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CBCDR - CCM Bus Clock Divider Register
 *
 * The figure below represents the CCM Bus Clock Divider Register (CBCDR).
 * The CBCDR register contains bits to control the clock generation sub
 * module dividers. The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERIPH2_CLK2_PODF_ : 3; //!< Divider for periph2_clk2 podf.  Note: Divider should be updated when output clock is gated.
        unsigned MMDC_CH1_AXI_PODF : 3; //!< Divider for mmdc_ch1_axi podf.   Note: This design implementation does not use MMDC_CH1_AXI_CLK_ROOT as a clock source to the MMDC. Only MMDC_CH0_AXI_CLK_ROOT is used.
        unsigned AXI_SEL : 1; //!< AXI clock source select
        unsigned AXI_ALT_SEL : 1; //!< AXI alternative clock select
        unsigned IPG_PODF_ : 2; //!< Divider for ipg podf.  Note: IEEE_RTC module will not support ratio of 1:3 for ahb_clk:ipg_clk. In case IEEE_RTC is used, then those ratios should not be used.  Note: SDMA module will not support ratio of 1:3 and 1:4 for ahb_clk:ipg_clk. In case SDMA is used, then those ratios should not be used.
        unsigned AHB_PODF_ : 3; //!< Divider for ahb podf.  Note: any change of this divider might involve handshake with EMI and IPU. See CDHIPR register for the handshake busy bits.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned AXI_PODF_ : 3; //!< Divider for axi podf.  Note: any change of this divider might involve handshake with EMI and IPU. See CDHIPR register for the handshake busy bits.
        unsigned MMDC_CH0_AXI_PODF_ : 3; //!< Divider for mmdc_ch0_axi podf.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned PERIPH_CLK_SEL : 1; //!< Selector for peripheral main clock (source of mmdc_ch0_axi_clk_root). Note: alternative clock source should be used when PLL is relocked. For PLL relock procedure pls refer PLL chapter
        unsigned PERIPH2_CLK_SEL : 1; //!< Selector for peripheral2 main clock (source of mmdc_ch1_axi_clk_root mmdc_root_axi_clk_root ).
        unsigned PERIPH_CLK2_PODF : 3; //!< Divider for periph2 clock podf.
        unsigned RESERVED2 : 2; //!< Reserved
    } B;
} hw_ccm_cbcdr_t;
#endif

/*
 * constants & macros for entire CCM_CBCDR register
 */
#define HW_CCM_CBCDR_ADDR      (REGS_CCM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CBCDR           (*(volatile hw_ccm_cbcdr_t *) HW_CCM_CBCDR_ADDR)
#define HW_CCM_CBCDR_RD()      (HW_CCM_CBCDR.U)
#define HW_CCM_CBCDR_WR(v)     (HW_CCM_CBCDR.U = (v))
#define HW_CCM_CBCDR_SET(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() |  (v)))
#define HW_CCM_CBCDR_CLR(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() & ~(v)))
#define HW_CCM_CBCDR_TOG(v)    (HW_CCM_CBCDR_WR(HW_CCM_CBCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CBCDR bitfields
 */

/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK2_PODF_
 *
 * Divider for periph2_clk2 podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CBCDR_PERIPH2_CLK2_PODF_      0
#define BM_CCM_CBCDR_PERIPH2_CLK2_PODF_      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF_)
#else
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF_(v)   (((v) << 0) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH2_CLK2_PODF_(v)   BF_CS1(CCM_CBCDR, PERIPH2_CLK2_PODF_, v)
#endif

/* --- Register HW_CCM_CBCDR, field MMDC_CH1_AXI_PODF
 *
 * Divider for mmdc_ch1_axi podf.   Note: This design implementation does not use
 * MMDC_CH1_AXI_CLK_ROOT as a clock source to the MMDC.                                   Only
 * MMDC_CH0_AXI_CLK_ROOT is used.
 */

#define BP_CCM_CBCDR_MMDC_CH1_AXI_PODF      3
#define BM_CCM_CBCDR_MMDC_CH1_AXI_PODF      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   ((((reg32_t) v) << 3) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#else
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   (((v) << 3) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   BF_CS1(CCM_CBCDR, MMDC_CH1_AXI_PODF, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_SEL
 *
 * AXI clock source select
 */

#define BP_CCM_CBCDR_AXI_SEL      6
#define BM_CCM_CBCDR_AXI_SEL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CBCDR_AXI_SEL)
#else
#define BF_CCM_CBCDR_AXI_SEL(v)   (((v) << 6) & BM_CCM_CBCDR_AXI_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_SEL(v)   BF_CS1(CCM_CBCDR, AXI_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_ALT_SEL
 *
 * AXI alternative clock select
 */

#define BP_CCM_CBCDR_AXI_ALT_SEL      7
#define BM_CCM_CBCDR_AXI_ALT_SEL      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   ((((reg32_t) v) << 7) & BM_CCM_CBCDR_AXI_ALT_SEL)
#else
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   (((v) << 7) & BM_CCM_CBCDR_AXI_ALT_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_ALT_SEL(v)   BF_CS1(CCM_CBCDR, AXI_ALT_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field IPG_PODF_
 *
 * Divider for ipg podf.  Note: IEEE_RTC module will not support ratio of 1:3 for
 * ahb_clk:ipg_clk. In case IEEE_RTC is used, then those ratios should
 * not be used.  Note: SDMA module will not support ratio of 1:3 and 1:4 for
 * ahb_clk:ipg_clk. In case SDMA is used, then those ratios should not
 * be used.
 */

#define BP_CCM_CBCDR_IPG_PODF_      8
#define BM_CCM_CBCDR_IPG_PODF_      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_IPG_PODF_(v)   ((((reg32_t) v) << 8) & BM_CCM_CBCDR_IPG_PODF_)
#else
#define BF_CCM_CBCDR_IPG_PODF_(v)   (((v) << 8) & BM_CCM_CBCDR_IPG_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_IPG_PODF_(v)   BF_CS1(CCM_CBCDR, IPG_PODF_, v)
#endif

/* --- Register HW_CCM_CBCDR, field AHB_PODF_
 *
 * Divider for ahb podf.  Note: any change of this divider might involve handshake with EMI and
 * IPU. See CDHIPR register for the handshake busy bits.
 */

#define BP_CCM_CBCDR_AHB_PODF_      10
#define BM_CCM_CBCDR_AHB_PODF_      0x00001c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AHB_PODF_(v)   ((((reg32_t) v) << 10) & BM_CCM_CBCDR_AHB_PODF_)
#else
#define BF_CCM_CBCDR_AHB_PODF_(v)   (((v) << 10) & BM_CCM_CBCDR_AHB_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AHB_PODF_(v)   BF_CS1(CCM_CBCDR, AHB_PODF_, v)
#endif

/* --- Register HW_CCM_CBCDR, field AXI_PODF_
 *
 * Divider for axi podf.  Note: any change of this divider might involve handshake with EMI and
 * IPU. See CDHIPR register for the handshake busy bits.
 */

#define BP_CCM_CBCDR_AXI_PODF_      16
#define BM_CCM_CBCDR_AXI_PODF_      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_AXI_PODF_(v)   ((((reg32_t) v) << 16) & BM_CCM_CBCDR_AXI_PODF_)
#else
#define BF_CCM_CBCDR_AXI_PODF_(v)   (((v) << 16) & BM_CCM_CBCDR_AXI_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_AXI_PODF_(v)   BF_CS1(CCM_CBCDR, AXI_PODF_, v)
#endif

/* --- Register HW_CCM_CBCDR, field MMDC_CH0_AXI_PODF_
 *
 * Divider for mmdc_ch0_axi podf.
 */

#define BP_CCM_CBCDR_MMDC_CH0_AXI_PODF_      19
#define BM_CCM_CBCDR_MMDC_CH0_AXI_PODF_      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF_(v)   ((((reg32_t) v) << 19) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF_)
#else
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF_(v)   (((v) << 19) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_MMDC_CH0_AXI_PODF_(v)   BF_CS1(CCM_CBCDR, MMDC_CH0_AXI_PODF_, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH_CLK_SEL
 *
 * Selector for peripheral main clock (source of mmdc_ch0_axi_clk_root). Note: alternative clock
 * source should be used when PLL is relocked. For PLL relock procedure pls refer PLL chapter
 */

#define BP_CCM_CBCDR_PERIPH_CLK_SEL      25
#define BM_CCM_CBCDR_PERIPH_CLK_SEL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   ((((reg32_t) v) << 25) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#else
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   (((v) << 25) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH_CLK_SEL(v)   BF_CS1(CCM_CBCDR, PERIPH_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK_SEL
 *
 * Selector for peripheral2 main clock (source of mmdc_ch1_axi_clk_root mmdc_root_axi_clk_root ).
 */

#define BP_CCM_CBCDR_PERIPH2_CLK_SEL      26
#define BM_CCM_CBCDR_PERIPH2_CLK_SEL      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << 26) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#else
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   (((v) << 26) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH2_CLK_SEL(v)   BF_CS1(CCM_CBCDR, PERIPH2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCDR, field PERIPH_CLK2_PODF
 *
 * Divider for periph2 clock podf.
 */

#define BP_CCM_CBCDR_PERIPH_CLK2_PODF      27
#define BM_CCM_CBCDR_PERIPH_CLK2_PODF      0x38000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   ((((reg32_t) v) << 27) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#else
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   (((v) << 27) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCDR_PERIPH_CLK2_PODF(v)   BF_CS1(CCM_CBCDR, PERIPH_CLK2_PODF, v)
#endif

/*!
 * @brief HW_CCM_CBCMR - CCM Bus Clock Multiplexer Register
 *
 * The figure below represents the CCM Bus Clock Multiplexer Register
 * (CBCMR). The CBCMR register contains bits to control the multiplexers
 * that generate the bus clocks. The table below provides its field
 * descriptions.  Note: Any change on the above multiplexer will have to be done while the
 * module that its clock is affected is not functional and the respective
 * clock is gated in LPCG. If the change will be done during operation of
 * the module, then it is not guaranteed that the modules operation will
 * not be harmed.  The change for arm_axi_clk_sel should be done through sdma so that ARM
 * will not use this clock during the change and the clock will be gated in
 * LPCG.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPU2D_AXI_CLK_SEL : 1; //!< Selector for gpu2d_axi clock multiplexer
        unsigned GPU3D_AXI_CLK_SEL : 1; //!< Selector for gpu3d_axi clock multiplexer
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned GPU3D_CORE_CLK_SEL_ : 2; //!< Selector for gpu3d_core clock multiplexer
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned GPU3D_SHADER_CLK_SEL_ : 2; //!< Selector for gpu3d_shader clock multiplexer
        unsigned PCIE_AXI_CLK_SEL : 1; //!< Selector for pcie_axi clock multiplexer
        unsigned VDOAXI_CLK_SEL : 1; //!< Selector for vdoaxi clock multiplexer
        unsigned PERIPH_CLK2_SEL_ : 2; //!< Selector for peripheral clk2 clock multiplexer
        unsigned VPU_AXI_CLK_SEL : 2; //!< Selector for VPU axi clock multiplexer
        unsigned GPU2D_CLK_SEL_ : 2; //!< Selector for open vg clock multiplexer
        unsigned PRE_PERIPH_CLK_SEL_ : 2; //!< Selector for pre_periph clock multiplexer
        unsigned PERIPH2_CLK2_SEL : 1; //!< Selector for periph2_clk2 clock multiplexer
        unsigned PRE_PERIPH2_CLK_SEL : 2; //!< Selector for pre_periph2 clock multiplexer
        unsigned GPU2D_CORE_CLK_PODF : 3; //!< Divider for gpu2d_core clock.  Note: Divider should be updated when output clock is gated.
        unsigned GPU3D_CORE_PODF : 3; //!< Divider for gpu3d_core clock.  Note: Divider should be updated when output clock is gated.
        unsigned GPU3D_SHADER_PODF : 3; //!< Divider for gpu3d_shader clock.  Note: Divider should be updated when output clock is gated.
    } B;
} hw_ccm_cbcmr_t;
#endif

/*
 * constants & macros for entire CCM_CBCMR register
 */
#define HW_CCM_CBCMR_ADDR      (REGS_CCM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CBCMR           (*(volatile hw_ccm_cbcmr_t *) HW_CCM_CBCMR_ADDR)
#define HW_CCM_CBCMR_RD()      (HW_CCM_CBCMR.U)
#define HW_CCM_CBCMR_WR(v)     (HW_CCM_CBCMR.U = (v))
#define HW_CCM_CBCMR_SET(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() |  (v)))
#define HW_CCM_CBCMR_CLR(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() & ~(v)))
#define HW_CCM_CBCMR_TOG(v)    (HW_CCM_CBCMR_WR(HW_CCM_CBCMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CBCMR bitfields
 */

/* --- Register HW_CCM_CBCMR, field GPU2D_AXI_CLK_SEL
 *
 * Selector for gpu2d_axi clock multiplexer
 */

#define BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL      0
#define BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   (((v) << 0) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU2D_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_AXI_CLK_SEL
 *
 * Selector for gpu3d_axi clock multiplexer
 */

#define BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL      1
#define BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   ((((reg32_t) v) << 1) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   (((v) << 1) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, GPU3D_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_CLK_SEL_
 *
 * Selector for gpu3d_core clock multiplexer
 */

#define BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL_      4
#define BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL_      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL_(v)   ((((reg32_t) v) << 4) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL_)
#else
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL_(v)   (((v) << 4) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_CORE_CLK_SEL_(v)   BF_CS1(CCM_CBCMR, GPU3D_CORE_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_CLK_SEL_
 *
 * Selector for gpu3d_shader clock multiplexer
 */

#define BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_      8
#define BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_(v)   ((((reg32_t) v) << 8) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_)
#else
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_(v)   (((v) << 8) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_SHADER_CLK_SEL_(v)   BF_CS1(CCM_CBCMR, GPU3D_SHADER_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CBCMR, field PCIE_AXI_CLK_SEL
 *
 * Selector for pcie_axi clock multiplexer
 */

#define BP_CCM_CBCMR_PCIE_AXI_CLK_SEL      10
#define BM_CCM_CBCMR_PCIE_AXI_CLK_SEL      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   ((((reg32_t) v) << 10) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   (((v) << 10) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, PCIE_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field VDOAXI_CLK_SEL
 *
 * Selector for vdoaxi clock multiplexer
 */

#define BP_CCM_CBCMR_VDOAXI_CLK_SEL      11
#define BM_CCM_CBCMR_VDOAXI_CLK_SEL      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   ((((reg32_t) v) << 11) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   (((v) << 11) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_VDOAXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, VDOAXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PERIPH_CLK2_SEL_
 *
 * Selector for peripheral clk2 clock multiplexer
 */

#define BP_CCM_CBCMR_PERIPH_CLK2_SEL_      12
#define BM_CCM_CBCMR_PERIPH_CLK2_SEL_      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL_(v)   ((((reg32_t) v) << 12) & BM_CCM_CBCMR_PERIPH_CLK2_SEL_)
#else
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL_(v)   (((v) << 12) & BM_CCM_CBCMR_PERIPH_CLK2_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PERIPH_CLK2_SEL_(v)   BF_CS1(CCM_CBCMR, PERIPH_CLK2_SEL_, v)
#endif

/* --- Register HW_CCM_CBCMR, field VPU_AXI_CLK_SEL
 *
 * Selector for VPU axi clock multiplexer
 */

#define BP_CCM_CBCMR_VPU_AXI_CLK_SEL      14
#define BM_CCM_CBCMR_VPU_AXI_CLK_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   ((((reg32_t) v) << 14) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#else
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   (((v) << 14) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   BF_CS1(CCM_CBCMR, VPU_AXI_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU2D_CLK_SEL_
 *
 * Selector for open vg clock multiplexer
 */

#define BP_CCM_CBCMR_GPU2D_CLK_SEL_      16
#define BM_CCM_CBCMR_GPU2D_CLK_SEL_      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_CLK_SEL_(v)   ((((reg32_t) v) << 16) & BM_CCM_CBCMR_GPU2D_CLK_SEL_)
#else
#define BF_CCM_CBCMR_GPU2D_CLK_SEL_(v)   (((v) << 16) & BM_CCM_CBCMR_GPU2D_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_CLK_SEL_(v)   BF_CS1(CCM_CBCMR, GPU2D_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CBCMR, field PRE_PERIPH_CLK_SEL_
 *
 * Selector for pre_periph clock multiplexer
 */

#define BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL_      18
#define BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL_      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL_(v)   ((((reg32_t) v) << 18) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL_)
#else
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL_(v)   (((v) << 18) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PRE_PERIPH_CLK_SEL_(v)   BF_CS1(CCM_CBCMR, PRE_PERIPH_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CBCMR, field PERIPH2_CLK2_SEL
 *
 * Selector for periph2_clk2 clock multiplexer
 */

#define BP_CCM_CBCMR_PERIPH2_CLK2_SEL      20
#define BM_CCM_CBCMR_PERIPH2_CLK2_SEL      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   ((((reg32_t) v) << 20) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#else
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   (((v) << 20) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   BF_CS1(CCM_CBCMR, PERIPH2_CLK2_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field PRE_PERIPH2_CLK_SEL
 *
 * Selector for pre_periph2 clock multiplexer
 */

#define BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      21
#define BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      0x00600000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << 21) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#else
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   (((v) << 21) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   BF_CS1(CCM_CBCMR, PRE_PERIPH2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU2D_CORE_CLK_PODF
 *
 * Divider for gpu2d_core clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF      23
#define BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   ((((reg32_t) v) << 23) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#else
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   (((v) << 23) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   BF_CS1(CCM_CBCMR, GPU2D_CORE_CLK_PODF, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_PODF
 *
 * Divider for gpu3d_core clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CBCMR_GPU3D_CORE_PODF      26
#define BM_CCM_CBCMR_GPU3D_CORE_PODF      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   ((((reg32_t) v) << 26) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#else
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   (((v) << 26) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_CORE_PODF(v)   BF_CS1(CCM_CBCMR, GPU3D_CORE_PODF, v)
#endif

/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_PODF
 *
 * Divider for gpu3d_shader clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CBCMR_GPU3D_SHADER_PODF      29
#define BM_CCM_CBCMR_GPU3D_SHADER_PODF      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   ((((reg32_t) v) << 29) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#else
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   (((v) << 29) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CBCMR_GPU3D_SHADER_PODF(v)   BF_CS1(CCM_CBCMR, GPU3D_SHADER_PODF, v)
#endif

/*!
 * @brief HW_CCM_CSCMR1 - CCM Serial Clock Multiplexer Register 1
 *
 * The figure below represents the CCM Serial Clock Multiplexer Register 1
 * (CSCMR1). The CSCMR1 register contains bits to control the multiplexers
 * that generate the serial clocks. The table below provides its field
 * descriptions.  Note: Any change on the above multiplexer will have to be done while the
 * module that its clock is affected is not functional and the clock is
 * gated. If the change will be done during operation of the module, then
 * it is not guaranteed that the modules operation will not be harmed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERCLK_PODF_ : 6; //!< Divider for perclk podf.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned SSI1_CLK_SEL : 2; //!< Selector for ssi1 clock multiplexer
        unsigned SSI2_CLK_SEL : 2; //!< Selector for ssi2 clock multiplexer
        unsigned SSI3_CLK_SEL : 2; //!< Selector for ssi3 clock multiplexer
        unsigned USDHC1_CLK_SEL : 1; //!< Selector for usdhc1 clock multiplexer
        unsigned USDHC2_CLK_SEL : 1; //!< Selector for usdhc2 clock multiplexer
        unsigned USDHC3_CLK_SEL : 1; //!< Selector for usdhc3 clock multiplexer
        unsigned USDHC4_CLK_SEL : 1; //!< Selector for usdhc4 clock multiplexer
        unsigned ACLK_EMI_PODF : 3; //!< Divider for aclk_emi clock root.
        unsigned ACLK_EMI_SLOW_PODF : 3; //!< Divider for aclk_emi_slow clock root.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ACLK_EMI_SEL : 2; //!< Selector for aclk_emi root clock multiplexer
        unsigned ACLK_EMI_SLOW_SEL : 2; //!< Selector for aclk_emi_slow root clock multiplexer
        unsigned RESERVED2 : 1; //!< Reserved.
    } B;
} hw_ccm_cscmr1_t;
#endif

/*
 * constants & macros for entire CCM_CSCMR1 register
 */
#define HW_CCM_CSCMR1_ADDR      (REGS_CCM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCMR1           (*(volatile hw_ccm_cscmr1_t *) HW_CCM_CSCMR1_ADDR)
#define HW_CCM_CSCMR1_RD()      (HW_CCM_CSCMR1.U)
#define HW_CCM_CSCMR1_WR(v)     (HW_CCM_CSCMR1.U = (v))
#define HW_CCM_CSCMR1_SET(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() |  (v)))
#define HW_CCM_CSCMR1_CLR(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() & ~(v)))
#define HW_CCM_CSCMR1_TOG(v)    (HW_CCM_CSCMR1_WR(HW_CCM_CSCMR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCMR1 bitfields
 */

/* --- Register HW_CCM_CSCMR1, field PERCLK_PODF_
 *
 * Divider for perclk podf.
 */

#define BP_CCM_CSCMR1_PERCLK_PODF_      0
#define BM_CCM_CSCMR1_PERCLK_PODF_      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_PERCLK_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCMR1_PERCLK_PODF_)
#else
#define BF_CCM_CSCMR1_PERCLK_PODF_(v)   (((v) << 0) & BM_CCM_CSCMR1_PERCLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_PERCLK_PODF_(v)   BF_CS1(CCM_CSCMR1, PERCLK_PODF_, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI1_CLK_SEL
 *
 * Selector for ssi1 clock multiplexer
 */

#define BP_CCM_CSCMR1_SSI1_CLK_SEL      10
#define BM_CCM_CSCMR1_SSI1_CLK_SEL      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   ((((reg32_t) v) << 10) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   (((v) << 10) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI1_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI2_CLK_SEL
 *
 * Selector for ssi2 clock multiplexer
 */

#define BP_CCM_CSCMR1_SSI2_CLK_SEL      12
#define BM_CCM_CSCMR1_SSI2_CLK_SEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   ((((reg32_t) v) << 12) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   (((v) << 12) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI2_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field SSI3_CLK_SEL
 *
 * Selector for ssi3 clock multiplexer
 */

#define BP_CCM_CSCMR1_SSI3_CLK_SEL      14
#define BM_CCM_CSCMR1_SSI3_CLK_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   ((((reg32_t) v) << 14) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#else
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   (((v) << 14) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_SSI3_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, SSI3_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC1_CLK_SEL
 *
 * Selector for usdhc1 clock multiplexer
 */

#define BP_CCM_CSCMR1_USDHC1_CLK_SEL      16
#define BM_CCM_CSCMR1_USDHC1_CLK_SEL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   (((v) << 16) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC1_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC2_CLK_SEL
 *
 * Selector for usdhc2 clock multiplexer
 */

#define BP_CCM_CSCMR1_USDHC2_CLK_SEL      17
#define BM_CCM_CSCMR1_USDHC2_CLK_SEL      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   ((((reg32_t) v) << 17) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   (((v) << 17) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC2_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC2_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC3_CLK_SEL
 *
 * Selector for usdhc3 clock multiplexer
 */

#define BP_CCM_CSCMR1_USDHC3_CLK_SEL      18
#define BM_CCM_CSCMR1_USDHC3_CLK_SEL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   ((((reg32_t) v) << 18) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   (((v) << 18) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC3_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC3_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field USDHC4_CLK_SEL
 *
 * Selector for usdhc4 clock multiplexer
 */

#define BP_CCM_CSCMR1_USDHC4_CLK_SEL      19
#define BM_CCM_CSCMR1_USDHC4_CLK_SEL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#else
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   (((v) << 19) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_USDHC4_CLK_SEL(v)   BF_CS1(CCM_CSCMR1, USDHC4_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_PODF
 *
 * Divider for aclk_emi clock root.
 */

#define BP_CCM_CSCMR1_ACLK_EMI_PODF      20
#define BM_CCM_CSCMR1_ACLK_EMI_PODF      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   ((((reg32_t) v) << 20) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   (((v) << 20) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_PODF(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_PODF
 *
 * Divider for aclk_emi_slow clock root.
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      23
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   ((((reg32_t) v) << 23) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   (((v) << 23) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SLOW_PODF, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SEL
 *
 * Selector for aclk_emi root clock multiplexer
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SEL      27
#define BM_CCM_CSCMR1_ACLK_EMI_SEL      0x18000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   ((((reg32_t) v) << 27) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   (((v) << 27) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SEL(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SEL, v)
#endif

/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_SEL
 *
 * Selector for aclk_emi_slow root clock multiplexer
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      29
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      0x60000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   ((((reg32_t) v) << 29) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#else
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   (((v) << 29) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   BF_CS1(CCM_CSCMR1, ACLK_EMI_SLOW_SEL, v)
#endif

/*!
 * @brief HW_CCM_CSCMR2 - CCM Serial Clock Multiplexer Register 2
 *
 * The figure below represents the CCM Serial Clock Multiplexer Register 2
 * (CSCMR2). The CSCMR2 register contains bits to control the multiplexers
 * that generate the serial clocks. The table below provides its field
 * descriptions.  Note: Any change on the above multiplexer will have to be done while the
 * module that its clock is affected is not functional and the clock is
 * gated. If the change will be done during operation of the module, then
 * it is not guaranteed that the modules operation will not be harmed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned CAN_CLK_PODF_ : 6; //!< Divider for can clock podf.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned LDB_DI0_IPU_DIV : 1; //!< Control for divider of ldb clock for IPU di0
        unsigned LDB_DI1_IPU_DIV : 1; //!< Control for divider of ldb clock for IPU di1
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned ESAI_CLK_SEL : 2; //!< Selector for esai clock multiplexer
        unsigned RESERVED3 : 11; //!< Reserved
    } B;
} hw_ccm_cscmr2_t;
#endif

/*
 * constants & macros for entire CCM_CSCMR2 register
 */
#define HW_CCM_CSCMR2_ADDR      (REGS_CCM_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCMR2           (*(volatile hw_ccm_cscmr2_t *) HW_CCM_CSCMR2_ADDR)
#define HW_CCM_CSCMR2_RD()      (HW_CCM_CSCMR2.U)
#define HW_CCM_CSCMR2_WR(v)     (HW_CCM_CSCMR2.U = (v))
#define HW_CCM_CSCMR2_SET(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() |  (v)))
#define HW_CCM_CSCMR2_CLR(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() & ~(v)))
#define HW_CCM_CSCMR2_TOG(v)    (HW_CCM_CSCMR2_WR(HW_CCM_CSCMR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCMR2 bitfields
 */

/* --- Register HW_CCM_CSCMR2, field CAN_CLK_PODF_
 *
 * Divider for can clock podf.
 */

#define BP_CCM_CSCMR2_CAN_CLK_PODF_      2
#define BM_CCM_CSCMR2_CAN_CLK_PODF_      0x000000fc

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_CAN_CLK_PODF_(v)   ((((reg32_t) v) << 2) & BM_CCM_CSCMR2_CAN_CLK_PODF_)
#else
#define BF_CCM_CSCMR2_CAN_CLK_PODF_(v)   (((v) << 2) & BM_CCM_CSCMR2_CAN_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_CAN_CLK_PODF_(v)   BF_CS1(CCM_CSCMR2, CAN_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CSCMR2, field LDB_DI0_IPU_DIV
 *
 * Control for divider of ldb clock for IPU di0
 */

#define BP_CCM_CSCMR2_LDB_DI0_IPU_DIV      10
#define BM_CCM_CSCMR2_LDB_DI0_IPU_DIV      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   ((((reg32_t) v) << 10) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#else
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   (((v) << 10) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   BF_CS1(CCM_CSCMR2, LDB_DI0_IPU_DIV, v)
#endif

/* --- Register HW_CCM_CSCMR2, field LDB_DI1_IPU_DIV
 *
 * Control for divider of ldb clock for IPU di1
 */

#define BP_CCM_CSCMR2_LDB_DI1_IPU_DIV      11
#define BM_CCM_CSCMR2_LDB_DI1_IPU_DIV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#else
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   (((v) << 11) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   BF_CS1(CCM_CSCMR2, LDB_DI1_IPU_DIV, v)
#endif

/* --- Register HW_CCM_CSCMR2, field ESAI_CLK_SEL
 *
 * Selector for esai clock multiplexer
 */

#define BP_CCM_CSCMR2_ESAI_CLK_SEL      19
#define BM_CCM_CSCMR2_ESAI_CLK_SEL      0x00180000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#else
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   (((v) << 19) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCMR2_ESAI_CLK_SEL(v)   BF_CS1(CCM_CSCMR2, ESAI_CLK_SEL, v)
#endif

/*!
 * @brief HW_CCM_CSCDR1 - CCM Serial Clock Divider Register 1
 *
 * The figure below represents the CCM Serial Clock Divider Register 1
 * (CSCDR1). The CSCDR1 register contains bits to control the clock
 * generation sub module dividers. The table below provides its field
 * descriptions.  Note: Any change on the above dividers will have to be done while the
 * module that its clock is affected is not functional and the affected
 * clock is gated. If the change will be done during operation of the
 * module, then it is not guaranteed that the modules operation will not be
 * harmed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UART_CLK_PODF_ : 6; //!< Divider for uart clock podf.
        unsigned RESERVED0 : 5; //!< Reserved.
        unsigned USDHC1_PODF : 3; //!< Divider for usdhc1 clock podf.  Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned USDHC2_PODF_ : 3; //!< Divider for usdhc2 clock.  Note: Divider should be updated when output clock is gated.
        unsigned USDHC3_PODF : 3; //!< Divider for usdhc3 clock podf.  Note: Divider should be updated when output clock is gated.
        unsigned USDHC4_PODF_ : 3; //!< Divider for esdhc4 clock pred.  Note: Divider should be updated when output clock is gated.
        unsigned VPU_AXI_PODF : 3; //!< Divider for vpu axi clock podf.  Note: Divider should be updated when output clock is gated.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_ccm_cscdr1_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR1 register
 */
#define HW_CCM_CSCDR1_ADDR      (REGS_CCM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR1           (*(volatile hw_ccm_cscdr1_t *) HW_CCM_CSCDR1_ADDR)
#define HW_CCM_CSCDR1_RD()      (HW_CCM_CSCDR1.U)
#define HW_CCM_CSCDR1_WR(v)     (HW_CCM_CSCDR1.U = (v))
#define HW_CCM_CSCDR1_SET(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() |  (v)))
#define HW_CCM_CSCDR1_CLR(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() & ~(v)))
#define HW_CCM_CSCDR1_TOG(v)    (HW_CCM_CSCDR1_WR(HW_CCM_CSCDR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR1 bitfields
 */

/* --- Register HW_CCM_CSCDR1, field UART_CLK_PODF_
 *
 * Divider for uart clock podf.
 */

#define BP_CCM_CSCDR1_UART_CLK_PODF_      0
#define BM_CCM_CSCDR1_UART_CLK_PODF_      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_UART_CLK_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCDR1_UART_CLK_PODF_)
#else
#define BF_CCM_CSCDR1_UART_CLK_PODF_(v)   (((v) << 0) & BM_CCM_CSCDR1_UART_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_UART_CLK_PODF_(v)   BF_CS1(CCM_CSCDR1, UART_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC1_PODF
 *
 * Divider for usdhc1 clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR1_USDHC1_PODF      11
#define BM_CCM_CSCDR1_USDHC1_PODF      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCDR1_USDHC1_PODF)
#else
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   (((v) << 11) & BM_CCM_CSCDR1_USDHC1_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC1_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC1_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC2_PODF_
 *
 * Divider for usdhc2 clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR1_USDHC2_PODF_      16
#define BM_CCM_CSCDR1_USDHC2_PODF_      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC2_PODF_(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCDR1_USDHC2_PODF_)
#else
#define BF_CCM_CSCDR1_USDHC2_PODF_(v)   (((v) << 16) & BM_CCM_CSCDR1_USDHC2_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC2_PODF_(v)   BF_CS1(CCM_CSCDR1, USDHC2_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC3_PODF
 *
 * Divider for usdhc3 clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR1_USDHC3_PODF      19
#define BM_CCM_CSCDR1_USDHC3_PODF      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCDR1_USDHC3_PODF)
#else
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   (((v) << 19) & BM_CCM_CSCDR1_USDHC3_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC3_PODF(v)   BF_CS1(CCM_CSCDR1, USDHC3_PODF, v)
#endif

/* --- Register HW_CCM_CSCDR1, field USDHC4_PODF_
 *
 * Divider for esdhc4 clock pred.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR1_USDHC4_PODF_      22
#define BM_CCM_CSCDR1_USDHC4_PODF_      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_USDHC4_PODF_(v)   ((((reg32_t) v) << 22) & BM_CCM_CSCDR1_USDHC4_PODF_)
#else
#define BF_CCM_CSCDR1_USDHC4_PODF_(v)   (((v) << 22) & BM_CCM_CSCDR1_USDHC4_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_USDHC4_PODF_(v)   BF_CS1(CCM_CSCDR1, USDHC4_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR1, field VPU_AXI_PODF
 *
 * Divider for vpu axi clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR1_VPU_AXI_PODF      25
#define BM_CCM_CSCDR1_VPU_AXI_PODF      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   ((((reg32_t) v) << 25) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#else
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   (((v) << 25) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR1_VPU_AXI_PODF(v)   BF_CS1(CCM_CSCDR1, VPU_AXI_PODF, v)
#endif

/*!
 * @brief HW_CCM_CS1CDR - CCM SSI1 Clock Divider Register
 *
 * The figure below represents the CCM SSI1, SSI3, ESAI Clock Divider
 * Register (CS1CDR). The CS1CDR register contains bits to control the ssi1
 * clock generation dividers. The table below provides its field
 * descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SSI1_CLK_PODF_ : 6; //!< Divider for ssi1 clock podf.  The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI1_CLK_PRED : 3; //!< Divider for ssi1 clock pred.
        unsigned ESAI_CLK_PRED : 3; //!< Divider for esai clock pred.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned SSI3_CLK_PODF_ : 6; //!< Divider for ssi3 clock podf.  The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI3_CLK_PRED : 3; //!< Divider for ssi3 clock pred.
        unsigned ESAI_CLK_PODF_ : 3; //!< Divider for esai clock podf.
        unsigned RESERVED1 : 4; //!< Reserved
    } B;
} hw_ccm_cs1cdr_t;
#endif

/*
 * constants & macros for entire CCM_CS1CDR register
 */
#define HW_CCM_CS1CDR_ADDR      (REGS_CCM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CS1CDR           (*(volatile hw_ccm_cs1cdr_t *) HW_CCM_CS1CDR_ADDR)
#define HW_CCM_CS1CDR_RD()      (HW_CCM_CS1CDR.U)
#define HW_CCM_CS1CDR_WR(v)     (HW_CCM_CS1CDR.U = (v))
#define HW_CCM_CS1CDR_SET(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() |  (v)))
#define HW_CCM_CS1CDR_CLR(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() & ~(v)))
#define HW_CCM_CS1CDR_TOG(v)    (HW_CCM_CS1CDR_WR(HW_CCM_CS1CDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CS1CDR bitfields
 */

/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PODF_
 *
 * Divider for ssi1 clock podf.  The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 */

#define BP_CCM_CS1CDR_SSI1_CLK_PODF_      0
#define BM_CCM_CS1CDR_SSI1_CLK_PODF_      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI1_CLK_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CS1CDR_SSI1_CLK_PODF_)
#else
#define BF_CCM_CS1CDR_SSI1_CLK_PODF_(v)   (((v) << 0) & BM_CCM_CS1CDR_SSI1_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI1_CLK_PODF_(v)   BF_CS1(CCM_CS1CDR, SSI1_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PRED
 *
 * Divider for ssi1 clock pred.
 */

#define BP_CCM_CS1CDR_SSI1_CLK_PRED      6
#define BM_CCM_CS1CDR_SSI1_CLK_PRED      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   ((((reg32_t) v) << 6) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#else
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   (((v) << 6) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI1_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, SSI1_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PRED
 *
 * Divider for esai clock pred.
 */

#define BP_CCM_CS1CDR_ESAI_CLK_PRED      9
#define BM_CCM_CS1CDR_ESAI_CLK_PRED      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   ((((reg32_t) v) << 9) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#else
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   (((v) << 9) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_ESAI_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, ESAI_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PODF_
 *
 * Divider for ssi3 clock podf.  The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 */

#define BP_CCM_CS1CDR_SSI3_CLK_PODF_      16
#define BM_CCM_CS1CDR_SSI3_CLK_PODF_      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI3_CLK_PODF_(v)   ((((reg32_t) v) << 16) & BM_CCM_CS1CDR_SSI3_CLK_PODF_)
#else
#define BF_CCM_CS1CDR_SSI3_CLK_PODF_(v)   (((v) << 16) & BM_CCM_CS1CDR_SSI3_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI3_CLK_PODF_(v)   BF_CS1(CCM_CS1CDR, SSI3_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PRED
 *
 * Divider for ssi3 clock pred.
 */

#define BP_CCM_CS1CDR_SSI3_CLK_PRED      22
#define BM_CCM_CS1CDR_SSI3_CLK_PRED      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   ((((reg32_t) v) << 22) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#else
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   (((v) << 22) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_SSI3_CLK_PRED(v)   BF_CS1(CCM_CS1CDR, SSI3_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PODF_
 *
 * Divider for esai clock podf.
 */

#define BP_CCM_CS1CDR_ESAI_CLK_PODF_      25
#define BM_CCM_CS1CDR_ESAI_CLK_PODF_      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS1CDR_ESAI_CLK_PODF_(v)   ((((reg32_t) v) << 25) & BM_CCM_CS1CDR_ESAI_CLK_PODF_)
#else
#define BF_CCM_CS1CDR_ESAI_CLK_PODF_(v)   (((v) << 25) & BM_CCM_CS1CDR_ESAI_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS1CDR_ESAI_CLK_PODF_(v)   BF_CS1(CCM_CS1CDR, ESAI_CLK_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CS2CDR - CCM SSI2 Clock Divider Register
 *
 * The figure below represents the CCM SSI2, LDB Clock Divider Register
 * (CS2CDR). The CS2CDR register contains bits to control the ssi2 clock
 * generation dividers, and ldb serial clocks select. The table below
 * provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SSI2_CLK_PODF_ : 6; //!< Divider for ssi2 clock podf.  The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI2_CLK_PRED : 3; //!< Divider for ssi2 clock pred.
        unsigned LDB_DI0_CLK_SEL_ : 3; //!< Selector for ldb_di1 clock multiplexer
        unsigned LDB_DI1_CLK_SEL_ : 3; //!< Selector for ldb_di1 clock multiplexer
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ENFC_CLK_SEL_ : 2; //!< Selector for enfc clock multiplexer
        unsigned ENFC_CLK_PRED_ : 3; //!< Divider for enfc clock pred divider.
        unsigned ENFC_CLK_PODF_ : 6; //!< Divider for enfc clock divider.
        unsigned RESERVED1 : 5; //!< Reserved
    } B;
} hw_ccm_cs2cdr_t;
#endif

/*
 * constants & macros for entire CCM_CS2CDR register
 */
#define HW_CCM_CS2CDR_ADDR      (REGS_CCM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CS2CDR           (*(volatile hw_ccm_cs2cdr_t *) HW_CCM_CS2CDR_ADDR)
#define HW_CCM_CS2CDR_RD()      (HW_CCM_CS2CDR.U)
#define HW_CCM_CS2CDR_WR(v)     (HW_CCM_CS2CDR.U = (v))
#define HW_CCM_CS2CDR_SET(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() |  (v)))
#define HW_CCM_CS2CDR_CLR(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() & ~(v)))
#define HW_CCM_CS2CDR_TOG(v)    (HW_CCM_CS2CDR_WR(HW_CCM_CS2CDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CS2CDR bitfields
 */

/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PODF_
 *
 * Divider for ssi2 clock podf.  The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 */

#define BP_CCM_CS2CDR_SSI2_CLK_PODF_      0
#define BM_CCM_CS2CDR_SSI2_CLK_PODF_      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_SSI2_CLK_PODF_(v)   ((((reg32_t) v) << 0) & BM_CCM_CS2CDR_SSI2_CLK_PODF_)
#else
#define BF_CCM_CS2CDR_SSI2_CLK_PODF_(v)   (((v) << 0) & BM_CCM_CS2CDR_SSI2_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_SSI2_CLK_PODF_(v)   BF_CS1(CCM_CS2CDR, SSI2_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PRED
 *
 * Divider for ssi2 clock pred.
 */

#define BP_CCM_CS2CDR_SSI2_CLK_PRED      6
#define BM_CCM_CS2CDR_SSI2_CLK_PRED      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   ((((reg32_t) v) << 6) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#else
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   (((v) << 6) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_SSI2_CLK_PRED(v)   BF_CS1(CCM_CS2CDR, SSI2_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CS2CDR, field LDB_DI0_CLK_SEL_
 *
 * Selector for ldb_di1 clock multiplexer
 */

#define BP_CCM_CS2CDR_LDB_DI0_CLK_SEL_      9
#define BM_CCM_CS2CDR_LDB_DI0_CLK_SEL_      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL_(v)   ((((reg32_t) v) << 9) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL_)
#else
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL_(v)   (((v) << 9) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_LDB_DI0_CLK_SEL_(v)   BF_CS1(CCM_CS2CDR, LDB_DI0_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CS2CDR, field LDB_DI1_CLK_SEL_
 *
 * Selector for ldb_di1 clock multiplexer
 */

#define BP_CCM_CS2CDR_LDB_DI1_CLK_SEL_      12
#define BM_CCM_CS2CDR_LDB_DI1_CLK_SEL_      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL_(v)   ((((reg32_t) v) << 12) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL_)
#else
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL_(v)   (((v) << 12) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_LDB_DI1_CLK_SEL_(v)   BF_CS1(CCM_CS2CDR, LDB_DI1_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_SEL_
 *
 * Selector for enfc clock multiplexer
 */

#define BP_CCM_CS2CDR_ENFC_CLK_SEL_      16
#define BM_CCM_CS2CDR_ENFC_CLK_SEL_      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_SEL_(v)   ((((reg32_t) v) << 16) & BM_CCM_CS2CDR_ENFC_CLK_SEL_)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_SEL_(v)   (((v) << 16) & BM_CCM_CS2CDR_ENFC_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_SEL_(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PRED_
 *
 * Divider for enfc clock pred divider.
 */

#define BP_CCM_CS2CDR_ENFC_CLK_PRED_      18
#define BM_CCM_CS2CDR_ENFC_CLK_PRED_      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_PRED_(v)   ((((reg32_t) v) << 18) & BM_CCM_CS2CDR_ENFC_CLK_PRED_)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_PRED_(v)   (((v) << 18) & BM_CCM_CS2CDR_ENFC_CLK_PRED_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_PRED_(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_PRED_, v)
#endif

/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PODF_
 *
 * Divider for enfc clock divider.
 */

#define BP_CCM_CS2CDR_ENFC_CLK_PODF_      21
#define BM_CCM_CS2CDR_ENFC_CLK_PODF_      0x07e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CS2CDR_ENFC_CLK_PODF_(v)   ((((reg32_t) v) << 21) & BM_CCM_CS2CDR_ENFC_CLK_PODF_)
#else
#define BF_CCM_CS2CDR_ENFC_CLK_PODF_(v)   (((v) << 21) & BM_CCM_CS2CDR_ENFC_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CS2CDR_ENFC_CLK_PODF_(v)   BF_CS1(CCM_CS2CDR, ENFC_CLK_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CDCDR - CCM D1 Clock Divider Register
 *
 * The figure below represents the CCM DI Clock Divider Register (CDCDR).
 * The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned SPDIF1_CLK_SEL : 2; //!< Selector for spdif1 clock multiplexer
        unsigned SPDIF1_CLK_PODF_ : 3; //!< Divider for spdif1 clock podf.  Note: Divider should be updated when output clock is gated.
        unsigned SPDIF1_CLK_PRED : 3; //!< Divider for spdif1 clock pred.  Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 4; //!< Reserved
        unsigned SPDIF0_CLK_SEL : 2; //!< Selector for spdif0 clock multiplexer
        unsigned SPDIF0_CLK_PODF_ : 3; //!< Divider for spdif0 clock podf.  Note: Divider should be updated when output clock is gated.
        unsigned SPDIF0_CLK_PRED : 3; //!< Divider for spdif0 clock pred.  Note: Divider should be updated when output clock is gated.
        unsigned HSI_TX_CLK_SEL : 1; //!< Selector for hsi_tx clock multiplexer
        unsigned HSI_TX_PODF_ : 3; //!< Divider for hsi_tx clock podf.  Note: Divider should be updated when output clock is gated.
    } B;
} hw_ccm_cdcdr_t;
#endif

/*
 * constants & macros for entire CCM_CDCDR register
 */
#define HW_CCM_CDCDR_ADDR      (REGS_CCM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CDCDR           (*(volatile hw_ccm_cdcdr_t *) HW_CCM_CDCDR_ADDR)
#define HW_CCM_CDCDR_RD()      (HW_CCM_CDCDR.U)
#define HW_CCM_CDCDR_WR(v)     (HW_CCM_CDCDR.U = (v))
#define HW_CCM_CDCDR_SET(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() |  (v)))
#define HW_CCM_CDCDR_CLR(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() & ~(v)))
#define HW_CCM_CDCDR_TOG(v)    (HW_CCM_CDCDR_WR(HW_CCM_CDCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CDCDR bitfields
 */

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_SEL
 *
 * Selector for spdif1 clock multiplexer
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_SEL      7
#define BM_CCM_CDCDR_SPDIF1_CLK_SEL      0x00000180

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   ((((reg32_t) v) << 7) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   (((v) << 7) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_SEL(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PODF_
 *
 * Divider for spdif1 clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_PODF_      9
#define BM_CCM_CDCDR_SPDIF1_CLK_PODF_      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF_(v)   ((((reg32_t) v) << 9) & BM_CCM_CDCDR_SPDIF1_CLK_PODF_)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF_(v)   (((v) << 9) & BM_CCM_CDCDR_SPDIF1_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_PODF_(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PRED
 *
 * Divider for spdif1 clock pred.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_PRED      12
#define BM_CCM_CDCDR_SPDIF1_CLK_PRED      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   ((((reg32_t) v) << 12) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#else
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   (((v) << 12) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF1_CLK_PRED(v)   BF_CS1(CCM_CDCDR, SPDIF1_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_SEL
 *
 * Selector for spdif0 clock multiplexer
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_SEL      20
#define BM_CCM_CDCDR_SPDIF0_CLK_SEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   ((((reg32_t) v) << 20) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   (((v) << 20) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_SEL(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PODF_
 *
 * Divider for spdif0 clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_PODF_      22
#define BM_CCM_CDCDR_SPDIF0_CLK_PODF_      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF_(v)   ((((reg32_t) v) << 22) & BM_CCM_CDCDR_SPDIF0_CLK_PODF_)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF_(v)   (((v) << 22) & BM_CCM_CDCDR_SPDIF0_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_PODF_(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_PODF_, v)
#endif

/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PRED
 *
 * Divider for spdif0 clock pred.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_PRED      25
#define BM_CCM_CDCDR_SPDIF0_CLK_PRED      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   ((((reg32_t) v) << 25) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#else
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   (((v) << 25) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_SPDIF0_CLK_PRED(v)   BF_CS1(CCM_CDCDR, SPDIF0_CLK_PRED, v)
#endif

/* --- Register HW_CCM_CDCDR, field HSI_TX_CLK_SEL
 *
 * Selector for hsi_tx clock multiplexer
 */

#define BP_CCM_CDCDR_HSI_TX_CLK_SEL      28
#define BM_CCM_CDCDR_HSI_TX_CLK_SEL      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   ((((reg32_t) v) << 28) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#else
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   (((v) << 28) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_HSI_TX_CLK_SEL(v)   BF_CS1(CCM_CDCDR, HSI_TX_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CDCDR, field HSI_TX_PODF_
 *
 * Divider for hsi_tx clock podf.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CDCDR_HSI_TX_PODF_      29
#define BM_CCM_CDCDR_HSI_TX_PODF_      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDCDR_HSI_TX_PODF_(v)   ((((reg32_t) v) << 29) & BM_CCM_CDCDR_HSI_TX_PODF_)
#else
#define BF_CCM_CDCDR_HSI_TX_PODF_(v)   (((v) << 29) & BM_CCM_CDCDR_HSI_TX_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDCDR_HSI_TX_PODF_(v)   BF_CS1(CCM_CDCDR, HSI_TX_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CHSCCDR - CCM HSC Clock Divider Register
 *
 * The figure below represents the CCM IPU1 DI Clock Divider Register
 * (CHSCCDR). The CHSCCDR register contains bits to control the ipu di
 * clock generation dividers. The table below provides its field
 * descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPU1_DI0_CLK_SEL : 3; //!< Selector for ipu1 di0 root clock multiplexer
        unsigned IPU1_DI0_PODF_ : 3; //!< Divider for ipu1_di0 clock divider.  Note: Divider should be updated when output clock is gated.
        unsigned IPU1_DI0_PRE_CLK_SEL : 3; //!< Selector for ipu1 di0 root clock pre-multiplexer
        unsigned IPU1_DI1_CLK_SEL : 3; //!< Selector for ipu1 di1 root clock multiplexer
        unsigned IPU1_DI1_PODF_ : 3; //!< Divider for ipu1_di clock divider.  Note: Divider should be updated when output clock is gated.
        unsigned IPU1_DI1_PRE_CLK_SEL : 3; //!< Selector for ipu1 di1 root clock pre-multiplexer
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_ccm_chsccdr_t;
#endif

/*
 * constants & macros for entire CCM_CHSCCDR register
 */
#define HW_CCM_CHSCCDR_ADDR      (REGS_CCM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CHSCCDR           (*(volatile hw_ccm_chsccdr_t *) HW_CCM_CHSCCDR_ADDR)
#define HW_CCM_CHSCCDR_RD()      (HW_CCM_CHSCCDR.U)
#define HW_CCM_CHSCCDR_WR(v)     (HW_CCM_CHSCCDR.U = (v))
#define HW_CCM_CHSCCDR_SET(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() |  (v)))
#define HW_CCM_CHSCCDR_CLR(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() & ~(v)))
#define HW_CCM_CHSCCDR_TOG(v)    (HW_CCM_CHSCCDR_WR(HW_CCM_CHSCCDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CHSCCDR bitfields
 */

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_CLK_SEL
 *
 * Selector for ipu1 di0 root clock multiplexer
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      0
#define BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   (((v) << 0) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PODF_
 *
 * Divider for ipu1_di0 clock divider.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_PODF_      3
#define BM_CCM_CHSCCDR_IPU1_DI0_PODF_      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF_(v)   ((((reg32_t) v) << 3) & BM_CCM_CHSCCDR_IPU1_DI0_PODF_)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF_(v)   (((v) << 3) & BM_CCM_CHSCCDR_IPU1_DI0_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_PODF_(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_PODF_, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PRE_CLK_SEL
 *
 * Selector for ipu1 di0 root clock pre-multiplexer
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      6
#define BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   (((v) << 6) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI0_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_CLK_SEL
 *
 * Selector for ipu1 di1 root clock multiplexer
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      9
#define BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   (((v) << 9) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PODF_
 *
 * Divider for ipu1_di clock divider.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_PODF_      12
#define BM_CCM_CHSCCDR_IPU1_DI1_PODF_      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF_(v)   ((((reg32_t) v) << 12) & BM_CCM_CHSCCDR_IPU1_DI1_PODF_)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF_(v)   (((v) << 12) & BM_CCM_CHSCCDR_IPU1_DI1_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_PODF_(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_PODF_, v)
#endif

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PRE_CLK_SEL
 *
 * Selector for ipu1 di1 root clock pre-multiplexer
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      15
#define BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << 15) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#else
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   (((v) << 15) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   BF_CS1(CCM_CHSCCDR, IPU1_DI1_PRE_CLK_SEL, v)
#endif

/*!
 * @brief HW_CCM_CSCDR2 - CCM Serial Clock Divider Register 2
 *
 * The figure below represents the CCM Serial Clock Divider Register
 * 2(CSCDR2). The CSCDR2 register contains bits to control the clock
 * generation sub module dividers. The table below provides its field
 * descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPU2_DI0_CLK_SEL : 3; //!< Selector for ipu2 di0 root clock multiplexer
        unsigned IPU2_DI0_PODF_ : 3; //!< Divider for ipu2_di0 clock divider.  Note: Divider should be updated when output clock is gated.
        unsigned IPU2_DI0_PRE_CLK_SEL : 3; //!< Selector for ipu2 di0 root clock pre-multiplexer
        unsigned IPU2_DI1_CLK_SEL : 3; //!< Selector for ipu1 di2 root clock multiplexer
        unsigned IPU2_DI1_PODF_ : 3; //!< Divider for ipu2_di1 clock divider.  Note: Divider should be updated when output clock is gated.
        unsigned IPU2_DI1_PRE_CLK_SEL : 3; //!< Selector for ipu2 di1 root clock pre-multiplexer
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ECSPI_CLK_PODF_ : 6; //!< Divider for ecspi clock podf.  Note: Divider should be updated when output clock is gated.  Note: The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned RESERVED1 : 6; //!< Reserved
        unsigned RESERVED2 : 1; //!< Reserved
    } B;
} hw_ccm_cscdr2_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR2 register
 */
#define HW_CCM_CSCDR2_ADDR      (REGS_CCM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR2           (*(volatile hw_ccm_cscdr2_t *) HW_CCM_CSCDR2_ADDR)
#define HW_CCM_CSCDR2_RD()      (HW_CCM_CSCDR2.U)
#define HW_CCM_CSCDR2_WR(v)     (HW_CCM_CSCDR2.U = (v))
#define HW_CCM_CSCDR2_SET(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() |  (v)))
#define HW_CCM_CSCDR2_CLR(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() & ~(v)))
#define HW_CCM_CSCDR2_TOG(v)    (HW_CCM_CSCDR2_WR(HW_CCM_CSCDR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR2 bitfields
 */

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_CLK_SEL
 *
 * Selector for ipu2 di0 root clock multiplexer
 */

#define BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL      0
#define BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   (((v) << 0) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PODF_
 *
 * Divider for ipu2_di0 clock divider.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR2_IPU2_DI0_PODF_      3
#define BM_CCM_CSCDR2_IPU2_DI0_PODF_      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_PODF_(v)   ((((reg32_t) v) << 3) & BM_CCM_CSCDR2_IPU2_DI0_PODF_)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_PODF_(v)   (((v) << 3) & BM_CCM_CSCDR2_IPU2_DI0_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_PODF_(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PRE_CLK_SEL
 *
 * Selector for ipu2 di0 root clock pre-multiplexer
 */

#define BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      6
#define BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << 6) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   (((v) << 6) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI0_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_CLK_SEL
 *
 * Selector for ipu1 di2 root clock multiplexer
 */

#define BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL      9
#define BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   ((((reg32_t) v) << 9) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   (((v) << 9) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PODF_
 *
 * Divider for ipu2_di1 clock divider.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR2_IPU2_DI1_PODF_      12
#define BM_CCM_CSCDR2_IPU2_DI1_PODF_      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_PODF_(v)   ((((reg32_t) v) << 12) & BM_CCM_CSCDR2_IPU2_DI1_PODF_)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_PODF_(v)   (((v) << 12) & BM_CCM_CSCDR2_IPU2_DI1_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_PODF_(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PRE_CLK_SEL
 *
 * Selector for ipu2 di1 root clock pre-multiplexer
 */

#define BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      15
#define BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << 15) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#else
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   (((v) << 15) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   BF_CS1(CCM_CSCDR2, IPU2_DI1_PRE_CLK_SEL, v)
#endif

/* --- Register HW_CCM_CSCDR2, field ECSPI_CLK_PODF_
 *
 * Divider for ecspi clock podf.  Note: Divider should be updated when output clock is gated.  Note:
 * The input clock to this divider should be lower than 300Mhz,                                 the
 * predivider can be used to achieve this.
 */

#define BP_CCM_CSCDR2_ECSPI_CLK_PODF_      19
#define BM_CCM_CSCDR2_ECSPI_CLK_PODF_      0x01f80000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF_(v)   ((((reg32_t) v) << 19) & BM_CCM_CSCDR2_ECSPI_CLK_PODF_)
#else
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF_(v)   (((v) << 19) & BM_CCM_CSCDR2_ECSPI_CLK_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR2_ECSPI_CLK_PODF_(v)   BF_CS1(CCM_CSCDR2, ECSPI_CLK_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CSCDR3 - CCM Serial Clock Divider Register 3
 *
 * The figure below represents the CCM Serial Clock Divider Register
 * 3(CSCDR3). The CSCDR3 register contains bits to control the clock
 * generation sub module dividers. The table below provides its field
 * descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 9; //!< Reserved
        unsigned IPU1_HSP_CLK_SEL_ : 2; //!< Selector for ipu1_hsp clock multiplexer
        unsigned IPU1_HSP_PODF_ : 3; //!< Divider for ipu1_hsp clock.  Note: Divider should be updated when output clock is gated.
        unsigned IPU2_HSP_CLK_SEL_ : 2; //!< Selector for ipu2_hsp clock multiplexer
        unsigned IPU2_HSP_PODF_ : 3; //!< Divider for ipu2_hsp clock.  Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 13; //!< Reserved
    } B;
} hw_ccm_cscdr3_t;
#endif

/*
 * constants & macros for entire CCM_CSCDR3 register
 */
#define HW_CCM_CSCDR3_ADDR      (REGS_CCM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CSCDR3           (*(volatile hw_ccm_cscdr3_t *) HW_CCM_CSCDR3_ADDR)
#define HW_CCM_CSCDR3_RD()      (HW_CCM_CSCDR3.U)
#define HW_CCM_CSCDR3_WR(v)     (HW_CCM_CSCDR3.U = (v))
#define HW_CCM_CSCDR3_SET(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() |  (v)))
#define HW_CCM_CSCDR3_CLR(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() & ~(v)))
#define HW_CCM_CSCDR3_TOG(v)    (HW_CCM_CSCDR3_WR(HW_CCM_CSCDR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CSCDR3 bitfields
 */

/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_CLK_SEL_
 *
 * Selector for ipu1_hsp clock multiplexer
 */

#define BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL_      9
#define BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL_      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL_(v)   ((((reg32_t) v) << 9) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL_)
#else
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL_(v)   (((v) << 9) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU1_HSP_CLK_SEL_(v)   BF_CS1(CCM_CSCDR3, IPU1_HSP_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_PODF_
 *
 * Divider for ipu1_hsp clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR3_IPU1_HSP_PODF_      11
#define BM_CCM_CSCDR3_IPU1_HSP_PODF_      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU1_HSP_PODF_(v)   ((((reg32_t) v) << 11) & BM_CCM_CSCDR3_IPU1_HSP_PODF_)
#else
#define BF_CCM_CSCDR3_IPU1_HSP_PODF_(v)   (((v) << 11) & BM_CCM_CSCDR3_IPU1_HSP_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU1_HSP_PODF_(v)   BF_CS1(CCM_CSCDR3, IPU1_HSP_PODF_, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_CLK_SEL_
 *
 * Selector for ipu2_hsp clock multiplexer
 */

#define BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL_      14
#define BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL_      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL_(v)   ((((reg32_t) v) << 14) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL_)
#else
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL_(v)   (((v) << 14) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU2_HSP_CLK_SEL_(v)   BF_CS1(CCM_CSCDR3, IPU2_HSP_CLK_SEL_, v)
#endif

/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_PODF_
 *
 * Divider for ipu2_hsp clock.  Note: Divider should be updated when output clock is gated.
 */

#define BP_CCM_CSCDR3_IPU2_HSP_PODF_      16
#define BM_CCM_CSCDR3_IPU2_HSP_PODF_      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CSCDR3_IPU2_HSP_PODF_(v)   ((((reg32_t) v) << 16) & BM_CCM_CSCDR3_IPU2_HSP_PODF_)
#else
#define BF_CCM_CSCDR3_IPU2_HSP_PODF_(v)   (((v) << 16) & BM_CCM_CSCDR3_IPU2_HSP_PODF_)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CSCDR3_IPU2_HSP_PODF_(v)   BF_CS1(CCM_CSCDR3, IPU2_HSP_PODF_, v)
#endif

/*!
 * @brief HW_CCM_CWDR - CCM Wakeup Detector Register
 *
 * The figure below represents the CCM Wakeup Detector Register (CWDR). The
 * CWDR register contains reserved, read-only bits.The table below provides
 * its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Reserved
    } B;
} hw_ccm_cwdr_t;
#endif

/*
 * constants & macros for entire CCM_CWDR register
 */
#define HW_CCM_CWDR_ADDR      (REGS_CCM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CWDR           (*(volatile hw_ccm_cwdr_t *) HW_CCM_CWDR_ADDR)
#define HW_CCM_CWDR_RD()      (HW_CCM_CWDR.U)
#define HW_CCM_CWDR_WR(v)     (HW_CCM_CWDR.U = (v))
#define HW_CCM_CWDR_SET(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() |  (v)))
#define HW_CCM_CWDR_CLR(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() & ~(v)))
#define HW_CCM_CWDR_TOG(v)    (HW_CCM_CWDR_WR(HW_CCM_CWDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CWDR bitfields
 */

/*!
 * @brief HW_CCM_CDHIPR - CCM Divider Handshake In-Process Register
 *
 * The figure below represents the CCM Divider Handshake In-Process
 * Register (CDHIPR). The CDHIPR register contains read only bits that
 * indicate that CCM is in the process of updating dividers or muxes that might
 * need handshake with modules.  bit 16: This bit corresponds to the arm_podf divider only if ARM
 * dvfs                             operation is done through arm_podf change
 * (arm_freq_shift_divider =                             '1'). In this case, writing to arm_podf
 * will commence only after                             assertion of arm_clk_switch_req from GPC.
 * During this period, bit 16                             (arm_podf_busy) will assert to indicate
 * that arm_podf is during process                             of change. Software should not write
 * new values to arm_podf during this                             period. any reads of arm_podf
 * during this period will result the next                             value of arm_podf and not the
 * actual dividers value. To read the actual                             dividers value , software
 * should wait until arm_podf_busy deasserts.                             Once the value of the
 * indication bit changes from '1' to '0', ccm can                             also generate
 * interrupt, if its not masked (refer to CIMR). This bit                             will not
 * assert if its not a arm dvfs operation, i.e. if
 * arm_freq_shift_divider = '0'. In this case the write to arm_podf will
 * commence once the divider is written with the new value.  bits [8-0]: The dividers in this group
 * are axi_a_podf, axi_b_podf,                             emi_slow_podf, ahb_podf and nfc_podf. The
 * muxes control in this group                             are periph_clk_sel and emi_clk_sel. For
 * each of those dividers and muxes                             control, CDHIPR holds a busy
 * indication bit. If this bit is equal to 1,                             then ccm is in process of
 * updating the divider or mux. The corresponding                             bit will assert to '1'
 * once the CBCDR register is updated and a                             handshake is indeed needed
 * for the update. The corresponding bit will                             deassert to '0' once the
 * handshake has completed and the divider or mux                             is loaded with the new
 * values. Software reads of the divider or mux                             control bits, during the
 * time that these bits are 1, will represent the                             next value of the
 * divider or mux to be loaded. If software wants to read                             the actual
 * divider value, it should wait until the value of the                             indicator bit is
 * equal 0. Once the value of the indication bit changes                             from '1' to
 * '0', ccm can also generate interrupt, if its not masked                             (refer to
 * CIMR). The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AXI_PODF_BUSY : 1; //!< Busy indicator for axi_podf.
        unsigned AHB_PODF_BUSY : 1; //!< Busy indicator for ahb_podf.
        unsigned MMDC_CH1_PODF_BUSY : 1; //!< Busy indicator for mmdc_ch1_axi_podf.
        unsigned PERIPH2_CLK_SEL_BUSY : 1; //!< Busy indicator for periph2_clk_sel mux control.
        unsigned MMDC_CH0_PODF_BUSY : 1; //!< Busy indicator for mmdc_ch0_axi_podf.
        unsigned PERIPH_CLK_SEL_BUSY : 1; //!< Busy indicator for periph_clk_sel mux control.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned ARM_PODF_BUSY : 1; //!< Busy indicator for arm_podf.
        unsigned RESERVED1 : 15; //!< Reserved
    } B;
} hw_ccm_cdhipr_t;
#endif

/*
 * constants & macros for entire CCM_CDHIPR register
 */
#define HW_CCM_CDHIPR_ADDR      (REGS_CCM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CDHIPR           (*(volatile hw_ccm_cdhipr_t *) HW_CCM_CDHIPR_ADDR)
#define HW_CCM_CDHIPR_RD()      (HW_CCM_CDHIPR.U)
#define HW_CCM_CDHIPR_WR(v)     (HW_CCM_CDHIPR.U = (v))
#define HW_CCM_CDHIPR_SET(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() |  (v)))
#define HW_CCM_CDHIPR_CLR(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() & ~(v)))
#define HW_CCM_CDHIPR_TOG(v)    (HW_CCM_CDHIPR_WR(HW_CCM_CDHIPR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CDHIPR bitfields
 */

/* --- Register HW_CCM_CDHIPR, field AXI_PODF_BUSY
 *
 * Busy indicator for axi_podf.
 */

#define BP_CCM_CDHIPR_AXI_PODF_BUSY      0
#define BM_CCM_CDHIPR_AXI_PODF_BUSY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_AXI_PODF_BUSY(v)   ((((reg32_t) v) << 0) & BM_CCM_CDHIPR_AXI_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_AXI_PODF_BUSY(v)   (((v) << 0) & BM_CCM_CDHIPR_AXI_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_AXI_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, AXI_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field AHB_PODF_BUSY
 *
 * Busy indicator for ahb_podf.
 */

#define BP_CCM_CDHIPR_AHB_PODF_BUSY      1
#define BM_CCM_CDHIPR_AHB_PODF_BUSY      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_AHB_PODF_BUSY(v)   ((((reg32_t) v) << 1) & BM_CCM_CDHIPR_AHB_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_AHB_PODF_BUSY(v)   (((v) << 1) & BM_CCM_CDHIPR_AHB_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_AHB_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, AHB_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field MMDC_CH1_PODF_BUSY
 *
 * Busy indicator for mmdc_ch1_axi_podf.
 */

#define BP_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      2
#define BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   ((((reg32_t) v) << 2) & BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   (((v) << 2) & BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, MMDC_CH1_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field PERIPH2_CLK_SEL_BUSY
 *
 * Busy indicator for periph2_clk_sel mux control.
 */

#define BP_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      3
#define BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   ((((reg32_t) v) << 3) & BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY)
#else
#define BF_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   (((v) << 3) & BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(v)   BF_CS1(CCM_CDHIPR, PERIPH2_CLK_SEL_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field MMDC_CH0_PODF_BUSY
 *
 * Busy indicator for mmdc_ch0_axi_podf.
 */

#define BP_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      4
#define BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   ((((reg32_t) v) << 4) & BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   (((v) << 4) & BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, MMDC_CH0_PODF_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field PERIPH_CLK_SEL_BUSY
 *
 * Busy indicator for periph_clk_sel mux control.
 */

#define BP_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      5
#define BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   ((((reg32_t) v) << 5) & BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY)
#else
#define BF_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   (((v) << 5) & BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(v)   BF_CS1(CCM_CDHIPR, PERIPH_CLK_SEL_BUSY, v)
#endif

/* --- Register HW_CCM_CDHIPR, field ARM_PODF_BUSY
 *
 * Busy indicator for arm_podf.
 */

#define BP_CCM_CDHIPR_ARM_PODF_BUSY      16
#define BM_CCM_CDHIPR_ARM_PODF_BUSY      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CDHIPR_ARM_PODF_BUSY(v)   ((((reg32_t) v) << 16) & BM_CCM_CDHIPR_ARM_PODF_BUSY)
#else
#define BF_CCM_CDHIPR_ARM_PODF_BUSY(v)   (((v) << 16) & BM_CCM_CDHIPR_ARM_PODF_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CDHIPR_ARM_PODF_BUSY(v)   BF_CS1(CCM_CDHIPR, ARM_PODF_BUSY, v)
#endif

/*!
 * @brief HW_CCM_CTOR - CCM Testing Observability Register
 *
 * The figure below represents the CCM Testing Observability Register
 * (CTOR). CCM includes three muxes to mux between different critical
 * signals for testing observability. The output of the three muxes is
 * generated on the three output signals obs_output_0, obs_output_1 and
 * obs_output_2. Those three output signals can be generated on the IC pads
 * by configuring the IOMUXC. The CTOR register contains bits to control
 * the data generated for observability on the three output signals above.
 * The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned OBS_SPARE_OUTPUT_2_SEL : 4; //!< Selection of the signal to be generated on obs_output_2 (output of CCM) for observability on the pads.
        unsigned OBS_SPARE_OUTPUT_1_SEL : 4; //!< Selection of the signal to be generated on obs_output_1 (output of CCM) for observability on the pads.
        unsigned OBS_SPARE_OUTPUT_0_SEL : 5; //!< Selection of the signal to be generated on obs_output_0 (output of CCM) for observability on the pads.
        unsigned OBS_EN : 1; //!< observability enable bit. this bit enables the output of the three observability muxes.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_ccm_ctor_t;
#endif

/*
 * constants & macros for entire CCM_CTOR register
 */
#define HW_CCM_CTOR_ADDR      (REGS_CCM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CTOR           (*(volatile hw_ccm_ctor_t *) HW_CCM_CTOR_ADDR)
#define HW_CCM_CTOR_RD()      (HW_CCM_CTOR.U)
#define HW_CCM_CTOR_WR(v)     (HW_CCM_CTOR.U = (v))
#define HW_CCM_CTOR_SET(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() |  (v)))
#define HW_CCM_CTOR_CLR(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() & ~(v)))
#define HW_CCM_CTOR_TOG(v)    (HW_CCM_CTOR_WR(HW_CCM_CTOR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CTOR bitfields
 */

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_2_SEL
 *
 * Selection of the signal to be generated on obs_output_2 (output of
 * CCM) for observability on the pads.
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      0
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   (((v) << 0) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_2_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_1_SEL
 *
 * Selection of the signal to be generated on obs_output_1 (output of
 * CCM) for observability on the pads.
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      4
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   ((((reg32_t) v) << 4) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   (((v) << 4) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_1_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_0_SEL
 *
 * Selection of the signal to be generated on obs_output_0 (output of
 * CCM) for observability on the pads.
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      8
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#else
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   (((v) << 8) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   BF_CS1(CCM_CTOR, OBS_SPARE_OUTPUT_0_SEL, v)
#endif

/* --- Register HW_CCM_CTOR, field OBS_EN
 *
 * observability enable bit. this bit enables the output of the three
 * observability muxes.
 */

#define BP_CCM_CTOR_OBS_EN      13
#define BM_CCM_CTOR_OBS_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CTOR_OBS_EN(v)   ((((reg32_t) v) << 13) & BM_CCM_CTOR_OBS_EN)
#else
#define BF_CCM_CTOR_OBS_EN(v)   (((v) << 13) & BM_CCM_CTOR_OBS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CTOR_OBS_EN(v)   BF_CS1(CCM_CTOR, OBS_EN, v)
#endif

/*!
 * @brief HW_CCM_CLPCR - CCM Low Power Control Register
 *
 * The figure below represents the CCM Low Power Control Register (CLPCR).
 * The CLPCR register contains bits to control the low power modes
 * operation.The table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LPM : 2; //!< Setting the low power mode that system will enter on next assertion of dsm_request signal.
        unsigned BYPASS_PMIC_VFUNCTIONAL_READY : 1; //!< By asserting this bit CCM will bypass waiting for pmic_vfunctional_ready signal when coming out of STOP mode. This should be used for PMIC's that don't support the pmic_vfunctional_ready signal.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned ARM_CLK_DIS_ON_LPM : 1; //!< Define if ARM clocks (arm_clk, soc_mxclk, soc_pclk, soc_dbg_pclk, vl_wrck) will be disabled on wait mode. This is useful for debug mode, when the user still wants to simulate entering wait mode and still keep ARM clock functioning.  Note: software should not enable ARM power gating in wait mode if this bit is cleared.
        unsigned SBYOS : 1; //!< Standby clock oscillator bit. This bit defines if cosc_pwrdown, which power down the on chip oscillator, will be asserted in stop mode. This bit is discarded if cosc_pwrdown='1' for the on chip oscillator.
        unsigned DIS_REF_OSC : 1; //!< dis_ref_osc - in run mode, software can manually control closing of external reference oscillator clock, i.e. generating '1' on ref_en_b signal. If software closed manually the external reference clock, then sbyos functionality will be bypassed.  The manual closing of external reference oscilator should be performed only in case the reference oscilator is not the source of any clock generation.  Note: When returning from stop mode, the PMIC_VSTBY_REQ will be deasserted (if it was asserted when entering stop mode), and CCM will wait for indication that functional voltage is ready (by sampling the assertion of pmic_vfuncional_ready) before continuing the process of exiting from stop mode. Please refer to stby_count bits.
        unsigned VSTBY : 1; //!< Voltage standby request bit. This bit defines if PMIC_VSTBY_REQ pin, which notifies external power management IC to move from functional voltage to standby voltage, will be asserted in stop mode.
        unsigned STBY_COUNT : 2; //!< Standby counter definition. These two bits define, in the case of stop exit (if vstby bit was set), the amount of time CCM will wait between PMIC_VSTBY_REQ negation and the check of assertion of PMIC_VFUNCIONAL_READY .  *NOTE: clock cycles ratio depends on pmic_delay_scaler, defined by CGPR[0] bit.
        unsigned COSC_PWRDOWN : 1; //!< In run mode, software can manually control powering down of on chip oscillator, i.e. generating '1' on cosc_pwrdown signal. If software manually powered down the on chip oscillator, then sbyos functionality for on chip oscillator will be bypassed.  The manual closing of onchip oscillator should be performed only in case the reference oscilator is not the source of all the clocks generation.
        unsigned RESERVED1 : 4; //!< Reserved
        unsigned WB_PER_AT_LPM : 1; //!< Enable periphery charge pump for well biasign at low power mode (stop or wait)
        unsigned WB_CORE_AT_LPM : 1; //!< Enable core charge pump for well biasign at low power mode (stop or wait)
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned BYPASS_MMDC_CH0_LPM_HS : 1; //!< Bypass handshake with mmdc_ch0 on next entrance to low power mode (wait or stop mode). CCM does not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to gate fast mmdc_ch0 clock.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned BYPASS_MMDC_CH1_LPM_HS : 1; //!< Bypass handshake with mmdc_ch1 on next entrance to low power mode (wait or stop mode). CCM does not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to gate fast mmdc_ch1 clock.
        unsigned MASK_CORE0_WFI : 1; //!< Mask WFI of core0 for entering low power mode  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE1_WFI : 1; //!< Mask WFI of core1 for entering low power mode  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE2_WFI : 1; //!< Mask WFI of core2 for entering low power mode  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE3_WFI : 1; //!< Mask WFI of core3 for entering low power mode  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_SCU_IDLE : 1; //!< Mask SCU IDLE for entering low power mode  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_L2CC_IDLE : 1; //!< Mask L2CC IDLE for entering low power mode.  Note: assertion of all bits[27:22] will generate low power mode request
        unsigned RESERVED4 : 4; //!< Reserved
    } B;
} hw_ccm_clpcr_t;
#endif

/*
 * constants & macros for entire CCM_CLPCR register
 */
#define HW_CCM_CLPCR_ADDR      (REGS_CCM_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CLPCR           (*(volatile hw_ccm_clpcr_t *) HW_CCM_CLPCR_ADDR)
#define HW_CCM_CLPCR_RD()      (HW_CCM_CLPCR.U)
#define HW_CCM_CLPCR_WR(v)     (HW_CCM_CLPCR.U = (v))
#define HW_CCM_CLPCR_SET(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() |  (v)))
#define HW_CCM_CLPCR_CLR(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() & ~(v)))
#define HW_CCM_CLPCR_TOG(v)    (HW_CCM_CLPCR_WR(HW_CCM_CLPCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CLPCR bitfields
 */

/* --- Register HW_CCM_CLPCR, field LPM
 *
 * Setting the low power mode that system will enter on next assertion
 * of dsm_request signal.
 */

#define BP_CCM_CLPCR_LPM      0
#define BM_CCM_CLPCR_LPM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_LPM(v)   ((((reg32_t) v) << 0) & BM_CCM_CLPCR_LPM)
#else
#define BF_CCM_CLPCR_LPM(v)   (((v) << 0) & BM_CCM_CLPCR_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_LPM(v)   BF_CS1(CCM_CLPCR, LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_PMIC_VFUNCTIONAL_READY
 *
 * By asserting this bit CCM will bypass waiting for
 * pmic_vfunctional_ready signal when coming out of STOP mode. This
 * should be used for PMIC's that don't support the
 * pmic_vfunctional_ready signal.
 */

#define BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      2
#define BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   ((((reg32_t) v) << 2) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#else
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   (((v) << 2) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   BF_CS1(CCM_CLPCR, BYPASS_PMIC_VFUNCTIONAL_READY, v)
#endif

/* --- Register HW_CCM_CLPCR, field ARM_CLK_DIS_ON_LPM
 *
 * Define if ARM clocks (arm_clk, soc_mxclk, soc_pclk, soc_dbg_pclk,
 * vl_wrck) will be disabled on wait mode. This is useful for debug
 * mode, when the user still wants to simulate entering wait mode and
 * still keep ARM clock functioning.  Note: software should not enable ARM power gating in wait mode
 * if                                 this bit is cleared.
 */

#define BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      5
#define BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   ((((reg32_t) v) << 5) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#else
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   (((v) << 5) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   BF_CS1(CCM_CLPCR, ARM_CLK_DIS_ON_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field SBYOS
 *
 * Standby clock oscillator bit. This bit defines if cosc_pwrdown, which
 * power down the on chip oscillator, will be asserted in stop mode.
 * This bit is discarded if cosc_pwrdown='1' for the on chip
 * oscillator.
 */

#define BP_CCM_CLPCR_SBYOS      6
#define BM_CCM_CLPCR_SBYOS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_SBYOS(v)   ((((reg32_t) v) << 6) & BM_CCM_CLPCR_SBYOS)
#else
#define BF_CCM_CLPCR_SBYOS(v)   (((v) << 6) & BM_CCM_CLPCR_SBYOS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_SBYOS(v)   BF_CS1(CCM_CLPCR, SBYOS, v)
#endif

/* --- Register HW_CCM_CLPCR, field DIS_REF_OSC
 *
 * dis_ref_osc - in run mode, software can manually control closing of
 * external reference oscillator clock, i.e. generating '1' on ref_en_b
 * signal. If software closed manually the external reference clock,
 * then sbyos functionality will be bypassed.  The manual closing of external reference oscilator
 * should be                                 performed only in case the reference oscilator is not
 * the source of                                 any clock generation.  Note: When returning from
 * stop mode, the PMIC_VSTBY_REQ will be                                 deasserted (if it was
 * asserted when entering stop mode), and CCM                                 will wait for
 * indication that functional voltage is ready (by                                 sampling the
 * assertion of pmic_vfuncional_ready) before continuing                                 the process
 * of exiting from stop mode. Please refer to stby_count                                 bits.
 */

#define BP_CCM_CLPCR_DIS_REF_OSC      7
#define BM_CCM_CLPCR_DIS_REF_OSC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   ((((reg32_t) v) << 7) & BM_CCM_CLPCR_DIS_REF_OSC)
#else
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   (((v) << 7) & BM_CCM_CLPCR_DIS_REF_OSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_DIS_REF_OSC(v)   BF_CS1(CCM_CLPCR, DIS_REF_OSC, v)
#endif

/* --- Register HW_CCM_CLPCR, field VSTBY
 *
 * Voltage standby request bit. This bit defines if PMIC_VSTBY_REQ pin,
 * which notifies external power management IC to move from functional
 * voltage to standby voltage, will be asserted in stop mode.
 */

#define BP_CCM_CLPCR_VSTBY      8
#define BM_CCM_CLPCR_VSTBY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_VSTBY(v)   ((((reg32_t) v) << 8) & BM_CCM_CLPCR_VSTBY)
#else
#define BF_CCM_CLPCR_VSTBY(v)   (((v) << 8) & BM_CCM_CLPCR_VSTBY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_VSTBY(v)   BF_CS1(CCM_CLPCR, VSTBY, v)
#endif

/* --- Register HW_CCM_CLPCR, field STBY_COUNT
 *
 * Standby counter definition. These two bits define, in the case of
 * stop exit (if vstby bit was set), the amount of time CCM will wait
 * between PMIC_VSTBY_REQ negation and the check of assertion of
 * PMIC_VFUNCIONAL_READY .  *NOTE: clock cycles ratio depends on pmic_delay_scaler, defined by
 * CGPR[0] bit.
 */

#define BP_CCM_CLPCR_STBY_COUNT      9
#define BM_CCM_CLPCR_STBY_COUNT      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_STBY_COUNT(v)   ((((reg32_t) v) << 9) & BM_CCM_CLPCR_STBY_COUNT)
#else
#define BF_CCM_CLPCR_STBY_COUNT(v)   (((v) << 9) & BM_CCM_CLPCR_STBY_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_STBY_COUNT(v)   BF_CS1(CCM_CLPCR, STBY_COUNT, v)
#endif

/* --- Register HW_CCM_CLPCR, field COSC_PWRDOWN
 *
 * In run mode, software can manually control powering down of on chip
 * oscillator, i.e. generating '1' on cosc_pwrdown signal. If software
 * manually powered down the on chip oscillator, then sbyos
 * functionality for on chip oscillator will be bypassed.  The manual closing of onchip oscillator
 * should be performed only in                                 case the reference oscilator is not
 * the source of all the clocks                                 generation.
 */

#define BP_CCM_CLPCR_COSC_PWRDOWN      11
#define BM_CCM_CLPCR_COSC_PWRDOWN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   ((((reg32_t) v) << 11) & BM_CCM_CLPCR_COSC_PWRDOWN)
#else
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   (((v) << 11) & BM_CCM_CLPCR_COSC_PWRDOWN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_COSC_PWRDOWN(v)   BF_CS1(CCM_CLPCR, COSC_PWRDOWN, v)
#endif

/* --- Register HW_CCM_CLPCR, field WB_PER_AT_LPM
 *
 * Enable periphery charge pump for well biasign at low power mode (stop
 * or wait)
 */

#define BP_CCM_CLPCR_WB_PER_AT_LPM      16
#define BM_CCM_CLPCR_WB_PER_AT_LPM      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   ((((reg32_t) v) << 16) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#else
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   (((v) << 16) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_WB_PER_AT_LPM(v)   BF_CS1(CCM_CLPCR, WB_PER_AT_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field WB_CORE_AT_LPM
 *
 * Enable core charge pump for well biasign at low power mode (stop or
 * wait)
 */

#define BP_CCM_CLPCR_WB_CORE_AT_LPM      17
#define BM_CCM_CLPCR_WB_CORE_AT_LPM      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   ((((reg32_t) v) << 17) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#else
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   (((v) << 17) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_WB_CORE_AT_LPM(v)   BF_CS1(CCM_CLPCR, WB_CORE_AT_LPM, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH0_LPM_HS
 *
 * Bypass handshake with mmdc_ch0 on next entrance to low power mode
 * (wait or stop mode). CCM does not wait for the module's acknowledge.
 * Handshake also will be bypassed, if CGR3 CG10 is set to gate fast
 * mmdc_ch0 clock.
 */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      19
#define BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   ((((reg32_t) v) << 19) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#else
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   (((v) << 19) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   BF_CS1(CCM_CLPCR, BYPASS_MMDC_CH0_LPM_HS, v)
#endif

/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH1_LPM_HS
 *
 * Bypass handshake with mmdc_ch1 on next entrance to low power mode
 * (wait or stop mode). CCM does not wait for the module's acknowledge.
 * Handshake also will be bypassed, if CGR3 CG10 is set to gate fast
 * mmdc_ch1 clock.
 */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      21
#define BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   ((((reg32_t) v) << 21) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#else
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   (((v) << 21) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   BF_CS1(CCM_CLPCR, BYPASS_MMDC_CH1_LPM_HS, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE0_WFI
 *
 * Mask WFI of core0 for entering low power mode  Note: assertion of all bits[27:22] will generate
 * low power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_CORE0_WFI      22
#define BM_CCM_CLPCR_MASK_CORE0_WFI      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   ((((reg32_t) v) << 22) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   (((v) << 22) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE0_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE0_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE1_WFI
 *
 * Mask WFI of core1 for entering low power mode  Note: assertion of all bits[27:22] will generate
 * low power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_CORE1_WFI      23
#define BM_CCM_CLPCR_MASK_CORE1_WFI      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   ((((reg32_t) v) << 23) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   (((v) << 23) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE1_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE1_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE2_WFI
 *
 * Mask WFI of core2 for entering low power mode  Note: assertion of all bits[27:22] will generate
 * low power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_CORE2_WFI      24
#define BM_CCM_CLPCR_MASK_CORE2_WFI      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   ((((reg32_t) v) << 24) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   (((v) << 24) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE2_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE2_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_CORE3_WFI
 *
 * Mask WFI of core3 for entering low power mode  Note: assertion of all bits[27:22] will generate
 * low power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_CORE3_WFI      25
#define BM_CCM_CLPCR_MASK_CORE3_WFI      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   ((((reg32_t) v) << 25) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#else
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   (((v) << 25) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_CORE3_WFI(v)   BF_CS1(CCM_CLPCR, MASK_CORE3_WFI, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_SCU_IDLE
 *
 * Mask SCU IDLE for entering low power mode  Note: assertion of all bits[27:22] will generate low
 * power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_SCU_IDLE      26
#define BM_CCM_CLPCR_MASK_SCU_IDLE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   ((((reg32_t) v) << 26) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#else
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   (((v) << 26) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_SCU_IDLE(v)   BF_CS1(CCM_CLPCR, MASK_SCU_IDLE, v)
#endif

/* --- Register HW_CCM_CLPCR, field MASK_L2CC_IDLE
 *
 * Mask L2CC IDLE for entering low power mode.  Note: assertion of all bits[27:22] will generate low
 * power mode                                 request
 */

#define BP_CCM_CLPCR_MASK_L2CC_IDLE      27
#define BM_CCM_CLPCR_MASK_L2CC_IDLE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   ((((reg32_t) v) << 27) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#else
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   (((v) << 27) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CLPCR_MASK_L2CC_IDLE(v)   BF_CS1(CCM_CLPCR, MASK_L2CC_IDLE, v)
#endif

/*!
 * @brief HW_CCM_CISR - CCM Interrupt Status Register
 *
 * The figure below represents the CCM Interrupt Status Register (CISR).
 * This is a write one to clear register. Once a interrupt is generated,
 * software should write one to clear it. The table below provides its
 * field descriptions.  * Note: ipi_int_1 can be masked by ipi_int_1_mask bit. ipi_int_2 can be
 * masked by ipi_int_2_mask bit.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LRF_PLL : 1; //!< Interrupt ipi_int_2 generated due to lock of all enabled and not bypaseed pll's
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned COSC_READY : 1; //!< Interrupt ipi_int_2 generated due to on board oscillator ready, i.e. oscnt has finished counting.
        unsigned RESERVED1 : 10; //!< Reserved
        unsigned AXI_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of axi_a_podf
        unsigned AXI_B_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of axi_b_podf
        unsigned PERIPH2_CLK_SEL_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of periph2_clk_sel
        unsigned AHB_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of ahb_podf
        unsigned MMDC_CH1_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of mmdc_ch0_podf_ loaded
        unsigned PERIPH_CLK_SEL_LOADED : 1; //!< Interrupt ipi_int_1 generated due to update of periph_clk_sel.
        unsigned MMDC_CH0_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to update of mmdc_ch0_axi_podf.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned ARM_PODF_LOADED : 1; //!< Interrupt ipi_int_1 generated due to frequency change of arm_podf. The interrupt will commence only if arm_podf is loaded during a arm dvfs operation.
        unsigned RESERVED3 : 5; //!< Reserved
    } B;
} hw_ccm_cisr_t;
#endif

/*
 * constants & macros for entire CCM_CISR register
 */
#define HW_CCM_CISR_ADDR      (REGS_CCM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CISR           (*(volatile hw_ccm_cisr_t *) HW_CCM_CISR_ADDR)
#define HW_CCM_CISR_RD()      (HW_CCM_CISR.U)
#define HW_CCM_CISR_WR(v)     (HW_CCM_CISR.U = (v))
#define HW_CCM_CISR_SET(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() |  (v)))
#define HW_CCM_CISR_CLR(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() & ~(v)))
#define HW_CCM_CISR_TOG(v)    (HW_CCM_CISR_WR(HW_CCM_CISR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CISR bitfields
 */

/* --- Register HW_CCM_CISR, field LRF_PLL
 *
 * Interrupt ipi_int_2 generated due to lock of all enabled and not
 * bypaseed pll's
 */

#define BP_CCM_CISR_LRF_PLL      0
#define BM_CCM_CISR_LRF_PLL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_LRF_PLL(v)   ((((reg32_t) v) << 0) & BM_CCM_CISR_LRF_PLL)
#else
#define BF_CCM_CISR_LRF_PLL(v)   (((v) << 0) & BM_CCM_CISR_LRF_PLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_LRF_PLL(v)   BF_CS1(CCM_CISR, LRF_PLL, v)
#endif

/* --- Register HW_CCM_CISR, field COSC_READY
 *
 * Interrupt ipi_int_2 generated due to on board oscillator ready, i.e.
 * oscnt has finished counting.
 */

#define BP_CCM_CISR_COSC_READY      6
#define BM_CCM_CISR_COSC_READY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_COSC_READY(v)   ((((reg32_t) v) << 6) & BM_CCM_CISR_COSC_READY)
#else
#define BF_CCM_CISR_COSC_READY(v)   (((v) << 6) & BM_CCM_CISR_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_COSC_READY(v)   BF_CS1(CCM_CISR, COSC_READY, v)
#endif

/* --- Register HW_CCM_CISR, field AXI_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of
 * axi_a_podf
 */

#define BP_CCM_CISR_AXI_PODF_LOADED      17
#define BM_CCM_CISR_AXI_PODF_LOADED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   ((((reg32_t) v) << 17) & BM_CCM_CISR_AXI_PODF_LOADED)
#else
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   (((v) << 17) & BM_CCM_CISR_AXI_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AXI_PODF_LOADED(v)   BF_CS1(CCM_CISR, AXI_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field AXI_B_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of
 * axi_b_podf
 */

#define BP_CCM_CISR_AXI_B_PODF_LOADED      18
#define BM_CCM_CISR_AXI_B_PODF_LOADED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AXI_B_PODF_LOADED(v)   ((((reg32_t) v) << 18) & BM_CCM_CISR_AXI_B_PODF_LOADED)
#else
#define BF_CCM_CISR_AXI_B_PODF_LOADED(v)   (((v) << 18) & BM_CCM_CISR_AXI_B_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AXI_B_PODF_LOADED(v)   BF_CS1(CCM_CISR, AXI_B_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field PERIPH2_CLK_SEL_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of
 * periph2_clk_sel
 */

#define BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED      19
#define BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 19) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#else
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   (((v) << 19) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   BF_CS1(CCM_CISR, PERIPH2_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field AHB_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of ahb_podf
 */

#define BP_CCM_CISR_AHB_PODF_LOADED      20
#define BM_CCM_CISR_AHB_PODF_LOADED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   ((((reg32_t) v) << 20) & BM_CCM_CISR_AHB_PODF_LOADED)
#else
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   (((v) << 20) & BM_CCM_CISR_AHB_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_AHB_PODF_LOADED(v)   BF_CS1(CCM_CISR, AHB_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field MMDC_CH1_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of
 * mmdc_ch0_podf_ loaded
 */

#define BP_CCM_CISR_MMDC_CH1_PODF_LOADED      21
#define BM_CCM_CISR_MMDC_CH1_PODF_LOADED      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << 21) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#else
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   (((v) << 21) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   BF_CS1(CCM_CISR, MMDC_CH1_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field PERIPH_CLK_SEL_LOADED
 *
 * Interrupt ipi_int_1 generated due to update of periph_clk_sel.
 */

#define BP_CCM_CISR_PERIPH_CLK_SEL_LOADED      22
#define BM_CCM_CISR_PERIPH_CLK_SEL_LOADED      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 22) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#else
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   (((v) << 22) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   BF_CS1(CCM_CISR, PERIPH_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field MMDC_CH0_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to update of mmdc_ch0_axi_podf.
 */

#define BP_CCM_CISR_MMDC_CH0_PODF_LOADED      23
#define BM_CCM_CISR_MMDC_CH0_PODF_LOADED      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << 23) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#else
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   (((v) << 23) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   BF_CS1(CCM_CISR, MMDC_CH0_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CISR, field ARM_PODF_LOADED
 *
 * Interrupt ipi_int_1 generated due to frequency change of arm_podf.
 * The interrupt will commence only if arm_podf is loaded during a arm
 * dvfs operation.
 */

#define BP_CCM_CISR_ARM_PODF_LOADED      26
#define BM_CCM_CISR_ARM_PODF_LOADED      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << 26) & BM_CCM_CISR_ARM_PODF_LOADED)
#else
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   (((v) << 26) & BM_CCM_CISR_ARM_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CISR_ARM_PODF_LOADED(v)   BF_CS1(CCM_CISR, ARM_PODF_LOADED, v)
#endif

/*!
 * @brief HW_CCM_CIMR - CCM Interrupt Mask Register
 *
 * The figure below represents the CCM Interrupt Mask Register (CIMR). The
 * table below provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MASK_LRF_PLL : 1; //!< mask interrupt generation due to lrf of pll's
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned MASK_COSC_READY : 1; //!< mask interrupt generation due to on board oscillator ready
        unsigned RESERVED1 : 10; //!< Reserved
        unsigned MASK_AXI_PODF_LOADED : 1; //!< mask interrupt generation due to frequency change of axi_podf
        unsigned MASK_AXI_B_PODF_LOADED : 1; //!< mask interrupt generation due to frequency change of axi_b_podf
        unsigned MASK_PERIPH2_CLK_SEL_LOADED : 1; //!< mask interrupt generation due to update of periph2_clk_sel.
        unsigned MASK_AHB_PODF_LOADED : 1; //!< mask interrupt generation due to frequency change of ahb_podf
        unsigned MASK_MMDC_CH1_PODF_LOADED : 1; //!< mask interrupt generation due to update of mask_mmdc_ch1_podf
        unsigned MASK_PERIPH_CLK_SEL_LOADED : 1; //!< mask interrupt generation due to update of periph_clk_sel.
        unsigned MASK_MMDC_CH0_PODF_LOADED : 1; //!< mask interrupt generation due to update of mask_mmdc_ch0_podf
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned ARM_PODF_LOADED : 1; //!< mask interrupt generation due to frequency change of arm_podf
        unsigned RESERVED3 : 5; //!< Reserved
    } B;
} hw_ccm_cimr_t;
#endif

/*
 * constants & macros for entire CCM_CIMR register
 */
#define HW_CCM_CIMR_ADDR      (REGS_CCM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CIMR           (*(volatile hw_ccm_cimr_t *) HW_CCM_CIMR_ADDR)
#define HW_CCM_CIMR_RD()      (HW_CCM_CIMR.U)
#define HW_CCM_CIMR_WR(v)     (HW_CCM_CIMR.U = (v))
#define HW_CCM_CIMR_SET(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() |  (v)))
#define HW_CCM_CIMR_CLR(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() & ~(v)))
#define HW_CCM_CIMR_TOG(v)    (HW_CCM_CIMR_WR(HW_CCM_CIMR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CIMR bitfields
 */

/* --- Register HW_CCM_CIMR, field MASK_LRF_PLL
 *
 * mask interrupt generation due to lrf of pll's
 */

#define BP_CCM_CIMR_MASK_LRF_PLL      0
#define BM_CCM_CIMR_MASK_LRF_PLL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   ((((reg32_t) v) << 0) & BM_CCM_CIMR_MASK_LRF_PLL)
#else
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   (((v) << 0) & BM_CCM_CIMR_MASK_LRF_PLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_LRF_PLL(v)   BF_CS1(CCM_CIMR, MASK_LRF_PLL, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_COSC_READY
 *
 * mask interrupt generation due to on board oscillator ready
 */

#define BP_CCM_CIMR_MASK_COSC_READY      6
#define BM_CCM_CIMR_MASK_COSC_READY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_COSC_READY(v)   ((((reg32_t) v) << 6) & BM_CCM_CIMR_MASK_COSC_READY)
#else
#define BF_CCM_CIMR_MASK_COSC_READY(v)   (((v) << 6) & BM_CCM_CIMR_MASK_COSC_READY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_COSC_READY(v)   BF_CS1(CCM_CIMR, MASK_COSC_READY, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AXI_PODF_LOADED
 *
 * mask interrupt generation due to frequency change of axi_podf
 */

#define BP_CCM_CIMR_MASK_AXI_PODF_LOADED      17
#define BM_CCM_CIMR_MASK_AXI_PODF_LOADED      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   ((((reg32_t) v) << 17) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   (((v) << 17) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AXI_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AXI_B_PODF_LOADED
 *
 * mask interrupt generation due to frequency change of axi_b_podf
 */

#define BP_CCM_CIMR_MASK_AXI_B_PODF_LOADED      18
#define BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   ((((reg32_t) v) << 18) & BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   (((v) << 18) & BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AXI_B_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AXI_B_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_PERIPH2_CLK_SEL_LOADED
 *
 * mask interrupt generation due to update of periph2_clk_sel.
 */

#define BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      19
#define BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 19) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#else
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   (((v) << 19) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   BF_CS1(CCM_CIMR, MASK_PERIPH2_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_AHB_PODF_LOADED
 *
 * mask interrupt generation due to frequency change of ahb_podf
 */

#define BP_CCM_CIMR_MASK_AHB_PODF_LOADED      20
#define BM_CCM_CIMR_MASK_AHB_PODF_LOADED      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   ((((reg32_t) v) << 20) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   (((v) << 20) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_AHB_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH1_PODF_LOADED
 *
 * mask interrupt generation due to update of mask_mmdc_ch1_podf
 */

#define BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      21
#define BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << 21) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   (((v) << 21) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_MMDC_CH1_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_PERIPH_CLK_SEL_LOADED
 *
 * mask interrupt generation due to update of periph_clk_sel.
 */

#define BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      22
#define BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << 22) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#else
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   (((v) << 22) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   BF_CS1(CCM_CIMR, MASK_PERIPH_CLK_SEL_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH0_PODF_LOADED
 *
 * mask interrupt generation due to update of mask_mmdc_ch0_podf
 */

#define BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      23
#define BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << 23) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#else
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   (((v) << 23) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   BF_CS1(CCM_CIMR, MASK_MMDC_CH0_PODF_LOADED, v)
#endif

/* --- Register HW_CCM_CIMR, field ARM_PODF_LOADED
 *
 * mask interrupt generation due to frequency change of arm_podf
 */

#define BP_CCM_CIMR_ARM_PODF_LOADED      26
#define BM_CCM_CIMR_ARM_PODF_LOADED      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << 26) & BM_CCM_CIMR_ARM_PODF_LOADED)
#else
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   (((v) << 26) & BM_CCM_CIMR_ARM_PODF_LOADED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CIMR_ARM_PODF_LOADED(v)   BF_CS1(CCM_CIMR, ARM_PODF_LOADED, v)
#endif

/*!
 * @brief HW_CCM_CCOSR - CCM Clock Output Source Register
 *
 * The figure below represents the CCM Clock Output Source Register (CCOSR).
 * The CCOSR register contains bits to control the clocks that will be
 * generated on the output ipp_do_clko1 and ipp_do_clko2.The table below
 * provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CKO1_SEL : 4; //!< Selection of the clock to be generated on cko1
        unsigned CKO1_DIV : 3; //!< Setting the divider of CKO1
        unsigned CKO1_EN : 1; //!< Enable of CKO1 clock
        unsigned CKO1_CKO2_SEL : 1; //!< CKO1 output to reflect cko1 or cko2 clocks
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned CKO2_SEL : 5; //!< Selection of the clock to be generated on cko2
        unsigned CKO2_DIV : 3; //!< Setting the divider of CKO2
        unsigned CKO2_EN : 1; //!< Enable of CKO2 clock
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_ccm_ccosr_t;
#endif

/*
 * constants & macros for entire CCM_CCOSR register
 */
#define HW_CCM_CCOSR_ADDR      (REGS_CCM_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCOSR           (*(volatile hw_ccm_ccosr_t *) HW_CCM_CCOSR_ADDR)
#define HW_CCM_CCOSR_RD()      (HW_CCM_CCOSR.U)
#define HW_CCM_CCOSR_WR(v)     (HW_CCM_CCOSR.U = (v))
#define HW_CCM_CCOSR_SET(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() |  (v)))
#define HW_CCM_CCOSR_CLR(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() & ~(v)))
#define HW_CCM_CCOSR_TOG(v)    (HW_CCM_CCOSR_WR(HW_CCM_CCOSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCOSR bitfields
 */

/* --- Register HW_CCM_CCOSR, field CKO1_SEL
 *
 * Selection of the clock to be generated on cko1
 */

#define BP_CCM_CCOSR_CKO1_SEL      0
#define BM_CCM_CCOSR_CKO1_SEL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_SEL(v)   ((((reg32_t) v) << 0) & BM_CCM_CCOSR_CKO1_SEL)
#else
#define BF_CCM_CCOSR_CKO1_SEL(v)   (((v) << 0) & BM_CCM_CCOSR_CKO1_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_SEL(v)   BF_CS1(CCM_CCOSR, CKO1_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_DIV
 *
 * Setting the divider of CKO1
 */

#define BP_CCM_CCOSR_CKO1_DIV      4
#define BM_CCM_CCOSR_CKO1_DIV      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_DIV(v)   ((((reg32_t) v) << 4) & BM_CCM_CCOSR_CKO1_DIV)
#else
#define BF_CCM_CCOSR_CKO1_DIV(v)   (((v) << 4) & BM_CCM_CCOSR_CKO1_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_DIV(v)   BF_CS1(CCM_CCOSR, CKO1_DIV, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_EN
 *
 * Enable of CKO1 clock
 */

#define BP_CCM_CCOSR_CKO1_EN      7
#define BM_CCM_CCOSR_CKO1_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_EN(v)   ((((reg32_t) v) << 7) & BM_CCM_CCOSR_CKO1_EN)
#else
#define BF_CCM_CCOSR_CKO1_EN(v)   (((v) << 7) & BM_CCM_CCOSR_CKO1_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_EN(v)   BF_CS1(CCM_CCOSR, CKO1_EN, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO1_CKO2_SEL
 *
 * CKO1 output to reflect cko1 or cko2 clocks
 */

#define BP_CCM_CCOSR_CKO1_CKO2_SEL      8
#define BM_CCM_CCOSR_CKO1_CKO2_SEL      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   ((((reg32_t) v) << 8) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#else
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   (((v) << 8) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO1_CKO2_SEL(v)   BF_CS1(CCM_CCOSR, CKO1_CKO2_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_SEL
 *
 * Selection of the clock to be generated on cko2
 */

#define BP_CCM_CCOSR_CKO2_SEL      16
#define BM_CCM_CCOSR_CKO2_SEL      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_SEL(v)   ((((reg32_t) v) << 16) & BM_CCM_CCOSR_CKO2_SEL)
#else
#define BF_CCM_CCOSR_CKO2_SEL(v)   (((v) << 16) & BM_CCM_CCOSR_CKO2_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_SEL(v)   BF_CS1(CCM_CCOSR, CKO2_SEL, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_DIV
 *
 * Setting the divider of CKO2
 */

#define BP_CCM_CCOSR_CKO2_DIV      21
#define BM_CCM_CCOSR_CKO2_DIV      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_DIV(v)   ((((reg32_t) v) << 21) & BM_CCM_CCOSR_CKO2_DIV)
#else
#define BF_CCM_CCOSR_CKO2_DIV(v)   (((v) << 21) & BM_CCM_CCOSR_CKO2_DIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_DIV(v)   BF_CS1(CCM_CCOSR, CKO2_DIV, v)
#endif

/* --- Register HW_CCM_CCOSR, field CKO2_EN
 *
 * Enable of CKO2 clock
 */

#define BP_CCM_CCOSR_CKO2_EN      24
#define BM_CCM_CCOSR_CKO2_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCOSR_CKO2_EN(v)   ((((reg32_t) v) << 24) & BM_CCM_CCOSR_CKO2_EN)
#else
#define BF_CCM_CCOSR_CKO2_EN(v)   (((v) << 24) & BM_CCM_CCOSR_CKO2_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCOSR_CKO2_EN(v)   BF_CS1(CCM_CCOSR, CKO2_EN, v)
#endif

/*!
 * @brief HW_CCM_CGPR - CCM General Purpose Register
 *
 * Fast PLL enable. Can be used to engage PLL faster after STOP mode, if 24MHz OSC was active
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PMIC_DELAY_SCALER : 1; //!< Defines clock dividion of clock for stby_count (pmic delay counter)
        unsigned RESERVED0 : 1; //!< Reserved for future use. Bits are connected to ccm output cgpr_dout[31-5]
        unsigned MMDC_EXT_CLK_DIS : 1; //!< Disable external clock driver of MMDC during STOP mode
        unsigned RESERVED1 : 1; //!< Reserved for future use. Bits are connected to ccm output cgpr_dout[31-5]
        unsigned EFUSE_PROG_SUPPLY_GATE : 1; //!< Defines the value of the output signal cgpr_dout[4]. Gate of programe supply for efuse programing
        unsigned RESERVED2 : 2; //!< Reserved.
        unsigned RESERVED3 : 2; //!< Reserved.
        unsigned RESERVED4 : 7; //!< Reserved.
        unsigned FPL : 1; //!< 
        unsigned RESERVED5 : 15; //!< Reserved for future use. Those bits are connected to ccm output cgpr_dout[31-17]
    } B;
} hw_ccm_cgpr_t;
#endif

/*
 * constants & macros for entire CCM_CGPR register
 */
#define HW_CCM_CGPR_ADDR      (REGS_CCM_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CGPR           (*(volatile hw_ccm_cgpr_t *) HW_CCM_CGPR_ADDR)
#define HW_CCM_CGPR_RD()      (HW_CCM_CGPR.U)
#define HW_CCM_CGPR_WR(v)     (HW_CCM_CGPR.U = (v))
#define HW_CCM_CGPR_SET(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() |  (v)))
#define HW_CCM_CGPR_CLR(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() & ~(v)))
#define HW_CCM_CGPR_TOG(v)    (HW_CCM_CGPR_WR(HW_CCM_CGPR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CGPR bitfields
 */

/* --- Register HW_CCM_CGPR, field PMIC_DELAY_SCALER
 *
 * Defines clock dividion of clock for stby_count (pmic delay
 * counter)
 */

#define BP_CCM_CGPR_PMIC_DELAY_SCALER      0
#define BM_CCM_CGPR_PMIC_DELAY_SCALER      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   ((((reg32_t) v) << 0) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#else
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   (((v) << 0) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_PMIC_DELAY_SCALER(v)   BF_CS1(CCM_CGPR, PMIC_DELAY_SCALER, v)
#endif

/* --- Register HW_CCM_CGPR, field MMDC_EXT_CLK_DIS
 *
 * Disable external clock driver of MMDC during STOP mode
 */

#define BP_CCM_CGPR_MMDC_EXT_CLK_DIS      2
#define BM_CCM_CGPR_MMDC_EXT_CLK_DIS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   ((((reg32_t) v) << 2) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#else
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   (((v) << 2) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   BF_CS1(CCM_CGPR, MMDC_EXT_CLK_DIS, v)
#endif

/* --- Register HW_CCM_CGPR, field EFUSE_PROG_SUPPLY_GATE
 *
 * Defines the value of the output signal cgpr_dout[4]. Gate of programe
 * supply for efuse programing
 */

#define BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      4
#define BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   ((((reg32_t) v) << 4) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#else
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   (((v) << 4) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   BF_CS1(CCM_CGPR, EFUSE_PROG_SUPPLY_GATE, v)
#endif

/* --- Register HW_CCM_CGPR, field FPL
 *

 */

#define BP_CCM_CGPR_FPL      16
#define BM_CCM_CGPR_FPL      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CGPR_FPL(v)   ((((reg32_t) v) << 16) & BM_CCM_CGPR_FPL)
#else
#define BF_CCM_CGPR_FPL(v)   (((v) << 16) & BM_CCM_CGPR_FPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CGPR_FPL(v)   BF_CS1(CCM_CGPR, FPL, v)
#endif

/*!
 * @brief HW_CCM_CCGR0 - CCM Clock Gating Register 0
 *
 * The figure below represents the CCM Clock Gating Register 0 (CCM_CCGR0).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< aips_tz1 clocks (aips_tz1_clk_enable)
        unsigned CG1 : 2; //!< aips_tz2 clocks (aips_tz2_clk_enable)
        unsigned CG2 : 2; //!< apbhdma hclk clock (apbhdma_hclk_enable)
        unsigned CG3 : 2; //!< asrc clock (asrc_clk_enable)
        unsigned CG4 : 2; //!< caam_secure_mem clock (caam_secure_mem_clk_enable)
        unsigned CG5 : 2; //!< caam_wrapper_aclk clock (caam_wrapper_aclk_enable)
        unsigned CG6 : 2; //!< caam_wrapper_ipg clock (caam_wrapper_ipg_enable)
        unsigned CG7 : 2; //!< can1 clock (can1_clk_enable)
        unsigned CG8 : 2; //!< can1_serial clock (can1_serial_clk_enable)
        unsigned CG9 : 2; //!< can2 clock (can2_clk_enable)
        unsigned CG10 : 2; //!< can2_serial clock (can2_serial_clk_enable)
        unsigned CG11 : 2; //!< CPU debug clocks (cheetah_dbg_clk_enable)
        unsigned CG12 : 2; //!< dcic 1 clocks (dcic1_clk_enable)
        unsigned CG13 : 2; //!< dcic2 clocks (dcic2_clk_enable)
        unsigned CG14 : 2; //!< dtcp clocks (dtcp_dtcp_clk_enable)
        unsigned CG15 : 2; //!< Reserved
    } B;
} hw_ccm_ccgr0_t;
#endif

/*
 * constants & macros for entire CCM_CCGR0 register
 */
#define HW_CCM_CCGR0_ADDR      (REGS_CCM_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR0           (*(volatile hw_ccm_ccgr0_t *) HW_CCM_CCGR0_ADDR)
#define HW_CCM_CCGR0_RD()      (HW_CCM_CCGR0.U)
#define HW_CCM_CCGR0_WR(v)     (HW_CCM_CCGR0.U = (v))
#define HW_CCM_CCGR0_SET(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() |  (v)))
#define HW_CCM_CCGR0_CLR(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() & ~(v)))
#define HW_CCM_CCGR0_TOG(v)    (HW_CCM_CCGR0_WR(HW_CCM_CCGR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR0 bitfields
 */

/* --- Register HW_CCM_CCGR0, field CG0
 *
 * aips_tz1 clocks (aips_tz1_clk_enable)
 */

#define BP_CCM_CCGR0_CG0      0
#define BM_CCM_CCGR0_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR0_CG0)
#else
#define BF_CCM_CCGR0_CG0(v)   (((v) << 0) & BM_CCM_CCGR0_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG0(v)   BF_CS1(CCM_CCGR0, CG0, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG1
 *
 * aips_tz2 clocks (aips_tz2_clk_enable)
 */

#define BP_CCM_CCGR0_CG1      2
#define BM_CCM_CCGR0_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR0_CG1)
#else
#define BF_CCM_CCGR0_CG1(v)   (((v) << 2) & BM_CCM_CCGR0_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG1(v)   BF_CS1(CCM_CCGR0, CG1, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG2
 *
 * apbhdma hclk clock (apbhdma_hclk_enable)
 */

#define BP_CCM_CCGR0_CG2      4
#define BM_CCM_CCGR0_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR0_CG2)
#else
#define BF_CCM_CCGR0_CG2(v)   (((v) << 4) & BM_CCM_CCGR0_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG2(v)   BF_CS1(CCM_CCGR0, CG2, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG3
 *
 * asrc clock (asrc_clk_enable)
 */

#define BP_CCM_CCGR0_CG3      6
#define BM_CCM_CCGR0_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR0_CG3)
#else
#define BF_CCM_CCGR0_CG3(v)   (((v) << 6) & BM_CCM_CCGR0_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG3(v)   BF_CS1(CCM_CCGR0, CG3, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG4
 *
 * caam_secure_mem clock (caam_secure_mem_clk_enable)
 */

#define BP_CCM_CCGR0_CG4      8
#define BM_CCM_CCGR0_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR0_CG4)
#else
#define BF_CCM_CCGR0_CG4(v)   (((v) << 8) & BM_CCM_CCGR0_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG4(v)   BF_CS1(CCM_CCGR0, CG4, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG5
 *
 * caam_wrapper_aclk clock (caam_wrapper_aclk_enable)
 */

#define BP_CCM_CCGR0_CG5      10
#define BM_CCM_CCGR0_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR0_CG5)
#else
#define BF_CCM_CCGR0_CG5(v)   (((v) << 10) & BM_CCM_CCGR0_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG5(v)   BF_CS1(CCM_CCGR0, CG5, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG6
 *
 * caam_wrapper_ipg clock (caam_wrapper_ipg_enable)
 */

#define BP_CCM_CCGR0_CG6      12
#define BM_CCM_CCGR0_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR0_CG6)
#else
#define BF_CCM_CCGR0_CG6(v)   (((v) << 12) & BM_CCM_CCGR0_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG6(v)   BF_CS1(CCM_CCGR0, CG6, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG7
 *
 * can1 clock (can1_clk_enable)
 */

#define BP_CCM_CCGR0_CG7      14
#define BM_CCM_CCGR0_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR0_CG7)
#else
#define BF_CCM_CCGR0_CG7(v)   (((v) << 14) & BM_CCM_CCGR0_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG7(v)   BF_CS1(CCM_CCGR0, CG7, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG8
 *
 * can1_serial clock (can1_serial_clk_enable)
 */

#define BP_CCM_CCGR0_CG8      16
#define BM_CCM_CCGR0_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR0_CG8)
#else
#define BF_CCM_CCGR0_CG8(v)   (((v) << 16) & BM_CCM_CCGR0_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG8(v)   BF_CS1(CCM_CCGR0, CG8, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG9
 *
 * can2 clock (can2_clk_enable)
 */

#define BP_CCM_CCGR0_CG9      18
#define BM_CCM_CCGR0_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR0_CG9)
#else
#define BF_CCM_CCGR0_CG9(v)   (((v) << 18) & BM_CCM_CCGR0_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG9(v)   BF_CS1(CCM_CCGR0, CG9, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG10
 *
 * can2_serial clock (can2_serial_clk_enable)
 */

#define BP_CCM_CCGR0_CG10      20
#define BM_CCM_CCGR0_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR0_CG10)
#else
#define BF_CCM_CCGR0_CG10(v)   (((v) << 20) & BM_CCM_CCGR0_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG10(v)   BF_CS1(CCM_CCGR0, CG10, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG11
 *
 * CPU debug clocks (cheetah_dbg_clk_enable)
 */

#define BP_CCM_CCGR0_CG11      22
#define BM_CCM_CCGR0_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR0_CG11)
#else
#define BF_CCM_CCGR0_CG11(v)   (((v) << 22) & BM_CCM_CCGR0_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG11(v)   BF_CS1(CCM_CCGR0, CG11, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG12
 *
 * dcic 1 clocks (dcic1_clk_enable)
 */

#define BP_CCM_CCGR0_CG12      24
#define BM_CCM_CCGR0_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR0_CG12)
#else
#define BF_CCM_CCGR0_CG12(v)   (((v) << 24) & BM_CCM_CCGR0_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG12(v)   BF_CS1(CCM_CCGR0, CG12, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG13
 *
 * dcic2 clocks (dcic2_clk_enable)
 */

#define BP_CCM_CCGR0_CG13      26
#define BM_CCM_CCGR0_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR0_CG13)
#else
#define BF_CCM_CCGR0_CG13(v)   (((v) << 26) & BM_CCM_CCGR0_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG13(v)   BF_CS1(CCM_CCGR0, CG13, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG14
 *
 * dtcp clocks (dtcp_dtcp_clk_enable)
 */

#define BP_CCM_CCGR0_CG14      28
#define BM_CCM_CCGR0_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR0_CG14)
#else
#define BF_CCM_CCGR0_CG14(v)   (((v) << 28) & BM_CCM_CCGR0_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG14(v)   BF_CS1(CCM_CCGR0, CG14, v)
#endif

/* --- Register HW_CCM_CCGR0, field CG15
 *
 * Reserved
 */

#define BP_CCM_CCGR0_CG15      30
#define BM_CCM_CCGR0_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR0_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR0_CG15)
#else
#define BF_CCM_CCGR0_CG15(v)   (((v) << 30) & BM_CCM_CCGR0_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR0_CG15(v)   BF_CS1(CCM_CCGR0, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR1 - CCM Clock Gating Register 1
 *
 * The figure below represents the CCM Clock Gating Register 1(CCM_CCGR1).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< ecspi1 clocks (ecspi1_clk_enable)
        unsigned CG1 : 2; //!< ecspi2 clocks (ecspi2_clk_enable)
        unsigned CG2 : 2; //!< ecspi3 clocks (ecspi3_clk_enable)
        unsigned CG3 : 2; //!< ecspi4 clocks (ecspi4_clk_enable)
        unsigned CG4 : 2; //!< ecspi5 clocks (ecspi5_clk_enable)
        unsigned CG5 : 2; //!< clock (enet_clk_enable)
        unsigned CG6 : 2; //!< epit1 clocks (epit1_clk_enable)
        unsigned CG7 : 2; //!< epit2 clocks (epit2_clk_enable)
        unsigned CG8 : 2; //!< esai clocks (esai_clk_enable) (extern_audio_clk_enable)
        unsigned CG9 : 2; //!< Reserved
        unsigned CG10 : 2; //!< gpt bus clock (gpt_clk_enable)
        unsigned CG11 : 2; //!< gpt serial clock (gpt_serial_clk_enable)
        unsigned CG12 : 2; //!< gpu2d clock (gpu2d_clk_enable)
        unsigned CG13 : 2; //!< gpu3d clock (gpu3d_clk_enable)
        unsigned CG14 : 2; //!< Reserved
        unsigned CG15 : 2; //!< Reserved
    } B;
} hw_ccm_ccgr1_t;
#endif

/*
 * constants & macros for entire CCM_CCGR1 register
 */
#define HW_CCM_CCGR1_ADDR      (REGS_CCM_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR1           (*(volatile hw_ccm_ccgr1_t *) HW_CCM_CCGR1_ADDR)
#define HW_CCM_CCGR1_RD()      (HW_CCM_CCGR1.U)
#define HW_CCM_CCGR1_WR(v)     (HW_CCM_CCGR1.U = (v))
#define HW_CCM_CCGR1_SET(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() |  (v)))
#define HW_CCM_CCGR1_CLR(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() & ~(v)))
#define HW_CCM_CCGR1_TOG(v)    (HW_CCM_CCGR1_WR(HW_CCM_CCGR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR1 bitfields
 */

/* --- Register HW_CCM_CCGR1, field CG0
 *
 * ecspi1 clocks (ecspi1_clk_enable)
 */

#define BP_CCM_CCGR1_CG0      0
#define BM_CCM_CCGR1_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR1_CG0)
#else
#define BF_CCM_CCGR1_CG0(v)   (((v) << 0) & BM_CCM_CCGR1_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG0(v)   BF_CS1(CCM_CCGR1, CG0, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG1
 *
 * ecspi2 clocks (ecspi2_clk_enable)
 */

#define BP_CCM_CCGR1_CG1      2
#define BM_CCM_CCGR1_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR1_CG1)
#else
#define BF_CCM_CCGR1_CG1(v)   (((v) << 2) & BM_CCM_CCGR1_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG1(v)   BF_CS1(CCM_CCGR1, CG1, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG2
 *
 * ecspi3 clocks (ecspi3_clk_enable)
 */

#define BP_CCM_CCGR1_CG2      4
#define BM_CCM_CCGR1_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR1_CG2)
#else
#define BF_CCM_CCGR1_CG2(v)   (((v) << 4) & BM_CCM_CCGR1_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG2(v)   BF_CS1(CCM_CCGR1, CG2, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG3
 *
 * ecspi4 clocks (ecspi4_clk_enable)
 */

#define BP_CCM_CCGR1_CG3      6
#define BM_CCM_CCGR1_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR1_CG3)
#else
#define BF_CCM_CCGR1_CG3(v)   (((v) << 6) & BM_CCM_CCGR1_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG3(v)   BF_CS1(CCM_CCGR1, CG3, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG4
 *
 * ecspi5 clocks (ecspi5_clk_enable)
 */

#define BP_CCM_CCGR1_CG4      8
#define BM_CCM_CCGR1_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR1_CG4)
#else
#define BF_CCM_CCGR1_CG4(v)   (((v) << 8) & BM_CCM_CCGR1_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG4(v)   BF_CS1(CCM_CCGR1, CG4, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG5
 *
 * clock (enet_clk_enable)
 */

#define BP_CCM_CCGR1_CG5      10
#define BM_CCM_CCGR1_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR1_CG5)
#else
#define BF_CCM_CCGR1_CG5(v)   (((v) << 10) & BM_CCM_CCGR1_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG5(v)   BF_CS1(CCM_CCGR1, CG5, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG6
 *
 * epit1 clocks (epit1_clk_enable)
 */

#define BP_CCM_CCGR1_CG6      12
#define BM_CCM_CCGR1_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR1_CG6)
#else
#define BF_CCM_CCGR1_CG6(v)   (((v) << 12) & BM_CCM_CCGR1_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG6(v)   BF_CS1(CCM_CCGR1, CG6, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG7
 *
 * epit2 clocks (epit2_clk_enable)
 */

#define BP_CCM_CCGR1_CG7      14
#define BM_CCM_CCGR1_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR1_CG7)
#else
#define BF_CCM_CCGR1_CG7(v)   (((v) << 14) & BM_CCM_CCGR1_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG7(v)   BF_CS1(CCM_CCGR1, CG7, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG8
 *
 * esai clocks (esai_clk_enable) (extern_audio_clk_enable)
 */

#define BP_CCM_CCGR1_CG8      16
#define BM_CCM_CCGR1_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR1_CG8)
#else
#define BF_CCM_CCGR1_CG8(v)   (((v) << 16) & BM_CCM_CCGR1_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG8(v)   BF_CS1(CCM_CCGR1, CG8, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG9
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG9      18
#define BM_CCM_CCGR1_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR1_CG9)
#else
#define BF_CCM_CCGR1_CG9(v)   (((v) << 18) & BM_CCM_CCGR1_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG9(v)   BF_CS1(CCM_CCGR1, CG9, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG10
 *
 * gpt bus clock (gpt_clk_enable)
 */

#define BP_CCM_CCGR1_CG10      20
#define BM_CCM_CCGR1_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR1_CG10)
#else
#define BF_CCM_CCGR1_CG10(v)   (((v) << 20) & BM_CCM_CCGR1_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG10(v)   BF_CS1(CCM_CCGR1, CG10, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG11
 *
 * gpt serial clock (gpt_serial_clk_enable)
 */

#define BP_CCM_CCGR1_CG11      22
#define BM_CCM_CCGR1_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR1_CG11)
#else
#define BF_CCM_CCGR1_CG11(v)   (((v) << 22) & BM_CCM_CCGR1_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG11(v)   BF_CS1(CCM_CCGR1, CG11, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG12
 *
 * gpu2d clock (gpu2d_clk_enable)
 */

#define BP_CCM_CCGR1_CG12      24
#define BM_CCM_CCGR1_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR1_CG12)
#else
#define BF_CCM_CCGR1_CG12(v)   (((v) << 24) & BM_CCM_CCGR1_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG12(v)   BF_CS1(CCM_CCGR1, CG12, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG13
 *
 * gpu3d clock (gpu3d_clk_enable)
 */

#define BP_CCM_CCGR1_CG13      26
#define BM_CCM_CCGR1_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR1_CG13)
#else
#define BF_CCM_CCGR1_CG13(v)   (((v) << 26) & BM_CCM_CCGR1_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG13(v)   BF_CS1(CCM_CCGR1, CG13, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG14
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG14      28
#define BM_CCM_CCGR1_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR1_CG14)
#else
#define BF_CCM_CCGR1_CG14(v)   (((v) << 28) & BM_CCM_CCGR1_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG14(v)   BF_CS1(CCM_CCGR1, CG14, v)
#endif

/* --- Register HW_CCM_CCGR1, field CG15
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG15      30
#define BM_CCM_CCGR1_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR1_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR1_CG15)
#else
#define BF_CCM_CCGR1_CG15(v)   (((v) << 30) & BM_CCM_CCGR1_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR1_CG15(v)   BF_CS1(CCM_CCGR1, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR2 - CCM Clock Gating Register 2
 *
 * The figure below represents the CCM Clock Gating Register 2 (CCM_CCGR2).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< hdmi_tx_iahbclk, hdmi_tx_ihclk clock (hdmi_tx_iahbclk_enable)
        unsigned CG1 : 2; //!< Reserved
        unsigned CG2 : 2; //!< hdmi_tx_isfrclk clock (hdmi_tx_isfrclk_enable)
        unsigned CG3 : 2; //!< i2c1_serial clock (i2c1_serial_clk_enable)
        unsigned CG4 : 2; //!< i2c2_serial clock (i2c2_serial_clk_enable)
        unsigned CG5 : 2; //!< i2c3_serial clock (i2c3_serial_clk_enable)
        unsigned CG6 : 2; //!< OCOTP_CTRL clock (iim_clk_enable)
        unsigned CG7 : 2; //!< iomux_ipt_clk_io clock (iomux_ipt_clk_io_enable)
        unsigned CG8 : 2; //!< ipmux1 clock (ipmux1_clk_enable)
        unsigned CG9 : 2; //!< ipmux2 clock (ipmux2_clk_enable)
        unsigned CG10 : 2; //!< ipmux3 clock (ipmux3_clk_enable)
        unsigned CG11 : 2; //!< ipsync_ip2apb_tzasc1_ipg clocks (ipsync_ip2apb_tzasc2_ipg_master_clk_enable)
        unsigned CG12 : 2; //!< ipsync_vdoa_ipg clocks (ipsync_ip2apb_tzasc2_ipg clocks)
        unsigned CG13 : 2; //!< ipsync_vdoa_ipg clocks (ipsync_vdoa_ipg_master_clk_enable)
        unsigned CG14 : 2; //!< Reserved
        unsigned CG15 : 2; //!< Reserved
    } B;
} hw_ccm_ccgr2_t;
#endif

/*
 * constants & macros for entire CCM_CCGR2 register
 */
#define HW_CCM_CCGR2_ADDR      (REGS_CCM_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR2           (*(volatile hw_ccm_ccgr2_t *) HW_CCM_CCGR2_ADDR)
#define HW_CCM_CCGR2_RD()      (HW_CCM_CCGR2.U)
#define HW_CCM_CCGR2_WR(v)     (HW_CCM_CCGR2.U = (v))
#define HW_CCM_CCGR2_SET(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() |  (v)))
#define HW_CCM_CCGR2_CLR(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() & ~(v)))
#define HW_CCM_CCGR2_TOG(v)    (HW_CCM_CCGR2_WR(HW_CCM_CCGR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR2 bitfields
 */

/* --- Register HW_CCM_CCGR2, field CG0
 *
 * hdmi_tx_iahbclk, hdmi_tx_ihclk clock (hdmi_tx_iahbclk_enable)
 */

#define BP_CCM_CCGR2_CG0      0
#define BM_CCM_CCGR2_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR2_CG0)
#else
#define BF_CCM_CCGR2_CG0(v)   (((v) << 0) & BM_CCM_CCGR2_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG0(v)   BF_CS1(CCM_CCGR2, CG0, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG1
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG1      2
#define BM_CCM_CCGR2_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR2_CG1)
#else
#define BF_CCM_CCGR2_CG1(v)   (((v) << 2) & BM_CCM_CCGR2_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG1(v)   BF_CS1(CCM_CCGR2, CG1, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG2
 *
 * hdmi_tx_isfrclk clock (hdmi_tx_isfrclk_enable)
 */

#define BP_CCM_CCGR2_CG2      4
#define BM_CCM_CCGR2_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR2_CG2)
#else
#define BF_CCM_CCGR2_CG2(v)   (((v) << 4) & BM_CCM_CCGR2_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG2(v)   BF_CS1(CCM_CCGR2, CG2, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG3
 *
 * i2c1_serial clock (i2c1_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG3      6
#define BM_CCM_CCGR2_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR2_CG3)
#else
#define BF_CCM_CCGR2_CG3(v)   (((v) << 6) & BM_CCM_CCGR2_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG3(v)   BF_CS1(CCM_CCGR2, CG3, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG4
 *
 * i2c2_serial clock (i2c2_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG4      8
#define BM_CCM_CCGR2_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR2_CG4)
#else
#define BF_CCM_CCGR2_CG4(v)   (((v) << 8) & BM_CCM_CCGR2_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG4(v)   BF_CS1(CCM_CCGR2, CG4, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG5
 *
 * i2c3_serial clock (i2c3_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG5      10
#define BM_CCM_CCGR2_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR2_CG5)
#else
#define BF_CCM_CCGR2_CG5(v)   (((v) << 10) & BM_CCM_CCGR2_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG5(v)   BF_CS1(CCM_CCGR2, CG5, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG6
 *
 * OCOTP_CTRL clock (iim_clk_enable)
 */

#define BP_CCM_CCGR2_CG6      12
#define BM_CCM_CCGR2_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR2_CG6)
#else
#define BF_CCM_CCGR2_CG6(v)   (((v) << 12) & BM_CCM_CCGR2_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG6(v)   BF_CS1(CCM_CCGR2, CG6, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG7
 *
 * iomux_ipt_clk_io clock (iomux_ipt_clk_io_enable)
 */

#define BP_CCM_CCGR2_CG7      14
#define BM_CCM_CCGR2_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR2_CG7)
#else
#define BF_CCM_CCGR2_CG7(v)   (((v) << 14) & BM_CCM_CCGR2_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG7(v)   BF_CS1(CCM_CCGR2, CG7, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG8
 *
 * ipmux1 clock (ipmux1_clk_enable)
 */

#define BP_CCM_CCGR2_CG8      16
#define BM_CCM_CCGR2_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR2_CG8)
#else
#define BF_CCM_CCGR2_CG8(v)   (((v) << 16) & BM_CCM_CCGR2_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG8(v)   BF_CS1(CCM_CCGR2, CG8, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG9
 *
 * ipmux2 clock (ipmux2_clk_enable)
 */

#define BP_CCM_CCGR2_CG9      18
#define BM_CCM_CCGR2_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR2_CG9)
#else
#define BF_CCM_CCGR2_CG9(v)   (((v) << 18) & BM_CCM_CCGR2_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG9(v)   BF_CS1(CCM_CCGR2, CG9, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG10
 *
 * ipmux3 clock (ipmux3_clk_enable)
 */

#define BP_CCM_CCGR2_CG10      20
#define BM_CCM_CCGR2_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR2_CG10)
#else
#define BF_CCM_CCGR2_CG10(v)   (((v) << 20) & BM_CCM_CCGR2_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG10(v)   BF_CS1(CCM_CCGR2, CG10, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG11
 *
 * ipsync_ip2apb_tzasc1_ipg clocks
 * (ipsync_ip2apb_tzasc2_ipg_master_clk_enable)
 */

#define BP_CCM_CCGR2_CG11      22
#define BM_CCM_CCGR2_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR2_CG11)
#else
#define BF_CCM_CCGR2_CG11(v)   (((v) << 22) & BM_CCM_CCGR2_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG11(v)   BF_CS1(CCM_CCGR2, CG11, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG12
 *
 * ipsync_vdoa_ipg clocks (ipsync_ip2apb_tzasc2_ipg clocks)
 */

#define BP_CCM_CCGR2_CG12      24
#define BM_CCM_CCGR2_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR2_CG12)
#else
#define BF_CCM_CCGR2_CG12(v)   (((v) << 24) & BM_CCM_CCGR2_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG12(v)   BF_CS1(CCM_CCGR2, CG12, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG13
 *
 * ipsync_vdoa_ipg clocks (ipsync_vdoa_ipg_master_clk_enable)
 */

#define BP_CCM_CCGR2_CG13      26
#define BM_CCM_CCGR2_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR2_CG13)
#else
#define BF_CCM_CCGR2_CG13(v)   (((v) << 26) & BM_CCM_CCGR2_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG13(v)   BF_CS1(CCM_CCGR2, CG13, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG14
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG14      28
#define BM_CCM_CCGR2_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR2_CG14)
#else
#define BF_CCM_CCGR2_CG14(v)   (((v) << 28) & BM_CCM_CCGR2_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG14(v)   BF_CS1(CCM_CCGR2, CG14, v)
#endif

/* --- Register HW_CCM_CCGR2, field CG15
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG15      30
#define BM_CCM_CCGR2_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR2_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR2_CG15)
#else
#define BF_CCM_CCGR2_CG15(v)   (((v) << 30) & BM_CCM_CCGR2_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR2_CG15(v)   BF_CS1(CCM_CCGR2, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR3 - CCM Clock Gating Register 3
 *
 * The figure below represents the CCM Clock Gating Register 3 (CCM_CCGR3).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< ipu1_ipu clock (ipu1_ipu_clk_enable)
        unsigned CG1 : 2; //!< ipu1_ipu_di0 clock (ipu1_ipu_di0_clk_enable)
        unsigned CG2 : 2; //!< ipu1_ipu_di1 clock (ipu1_ipu_di1_clk_enable)
        unsigned CG3 : 2; //!< ipu2_ipu clock (ipu2_ipu_clk_enable)
        unsigned CG4 : 2; //!< ipu2_ipu_di0 clock (ipu2_ipu_di0_clk_enable)
        unsigned CG5 : 2; //!< ipu2_ipu_di1 clock (ipu2_ipu_di1_clk_enable)
        unsigned CG6 : 2; //!< ldb_di0 clock (ldb_di0_clk_enable)
        unsigned CG7 : 2; //!< ldb_di1 clock (ldb_di1_clk_enable)
        unsigned CG8 : 2; //!< mipi_core_cfg clock (mipi_core_cfg_clk_enable)
        unsigned CG9 : 2; //!< mlb clock (mlb_clk_enable)
        unsigned CG10 : 2; //!< mmdc_core_aclk_fast_core_p0 clock (mmdc_core_aclk_fast_core_p0_enable)
        unsigned CG11 : 2; //!< mmdc_core_aclk_fast_core_p1 clock (mmdc_core_aclk_fast_core_p1_enable)
        unsigned CG12 : 2; //!< mmdc_core_ipg_clk_p0 clock (mmdc_core_ipg_clk_p0_enable)
        unsigned CG13 : 2; //!< mmdc_core_ipg_clk_p1 clock (mmdc_core_ipg_clk_p1_enable)
        unsigned CG14 : 2; //!< ocram clock (ocram_clk_enable)
        unsigned CG15 : 2; //!< openvgaxiclk clock (openvgaxiclk_clk_root_enable)
    } B;
} hw_ccm_ccgr3_t;
#endif

/*
 * constants & macros for entire CCM_CCGR3 register
 */
#define HW_CCM_CCGR3_ADDR      (REGS_CCM_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR3           (*(volatile hw_ccm_ccgr3_t *) HW_CCM_CCGR3_ADDR)
#define HW_CCM_CCGR3_RD()      (HW_CCM_CCGR3.U)
#define HW_CCM_CCGR3_WR(v)     (HW_CCM_CCGR3.U = (v))
#define HW_CCM_CCGR3_SET(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() |  (v)))
#define HW_CCM_CCGR3_CLR(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() & ~(v)))
#define HW_CCM_CCGR3_TOG(v)    (HW_CCM_CCGR3_WR(HW_CCM_CCGR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR3 bitfields
 */

/* --- Register HW_CCM_CCGR3, field CG0
 *
 * ipu1_ipu clock (ipu1_ipu_clk_enable)
 */

#define BP_CCM_CCGR3_CG0      0
#define BM_CCM_CCGR3_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR3_CG0)
#else
#define BF_CCM_CCGR3_CG0(v)   (((v) << 0) & BM_CCM_CCGR3_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG0(v)   BF_CS1(CCM_CCGR3, CG0, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG1
 *
 * ipu1_ipu_di0 clock (ipu1_ipu_di0_clk_enable)
 */

#define BP_CCM_CCGR3_CG1      2
#define BM_CCM_CCGR3_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR3_CG1)
#else
#define BF_CCM_CCGR3_CG1(v)   (((v) << 2) & BM_CCM_CCGR3_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG1(v)   BF_CS1(CCM_CCGR3, CG1, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG2
 *
 * ipu1_ipu_di1 clock (ipu1_ipu_di1_clk_enable)
 */

#define BP_CCM_CCGR3_CG2      4
#define BM_CCM_CCGR3_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR3_CG2)
#else
#define BF_CCM_CCGR3_CG2(v)   (((v) << 4) & BM_CCM_CCGR3_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG2(v)   BF_CS1(CCM_CCGR3, CG2, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG3
 *
 * ipu2_ipu clock (ipu2_ipu_clk_enable)
 */

#define BP_CCM_CCGR3_CG3      6
#define BM_CCM_CCGR3_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR3_CG3)
#else
#define BF_CCM_CCGR3_CG3(v)   (((v) << 6) & BM_CCM_CCGR3_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG3(v)   BF_CS1(CCM_CCGR3, CG3, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG4
 *
 * ipu2_ipu_di0 clock (ipu2_ipu_di0_clk_enable)
 */

#define BP_CCM_CCGR3_CG4      8
#define BM_CCM_CCGR3_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR3_CG4)
#else
#define BF_CCM_CCGR3_CG4(v)   (((v) << 8) & BM_CCM_CCGR3_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG4(v)   BF_CS1(CCM_CCGR3, CG4, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG5
 *
 * ipu2_ipu_di1 clock (ipu2_ipu_di1_clk_enable)
 */

#define BP_CCM_CCGR3_CG5      10
#define BM_CCM_CCGR3_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR3_CG5)
#else
#define BF_CCM_CCGR3_CG5(v)   (((v) << 10) & BM_CCM_CCGR3_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG5(v)   BF_CS1(CCM_CCGR3, CG5, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG6
 *
 * ldb_di0 clock (ldb_di0_clk_enable)
 */

#define BP_CCM_CCGR3_CG6      12
#define BM_CCM_CCGR3_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR3_CG6)
#else
#define BF_CCM_CCGR3_CG6(v)   (((v) << 12) & BM_CCM_CCGR3_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG6(v)   BF_CS1(CCM_CCGR3, CG6, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG7
 *
 * ldb_di1 clock (ldb_di1_clk_enable)
 */

#define BP_CCM_CCGR3_CG7      14
#define BM_CCM_CCGR3_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR3_CG7)
#else
#define BF_CCM_CCGR3_CG7(v)   (((v) << 14) & BM_CCM_CCGR3_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG7(v)   BF_CS1(CCM_CCGR3, CG7, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG8
 *
 * mipi_core_cfg clock (mipi_core_cfg_clk_enable)
 */

#define BP_CCM_CCGR3_CG8      16
#define BM_CCM_CCGR3_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR3_CG8)
#else
#define BF_CCM_CCGR3_CG8(v)   (((v) << 16) & BM_CCM_CCGR3_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG8(v)   BF_CS1(CCM_CCGR3, CG8, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG9
 *
 * mlb clock (mlb_clk_enable)
 */

#define BP_CCM_CCGR3_CG9      18
#define BM_CCM_CCGR3_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR3_CG9)
#else
#define BF_CCM_CCGR3_CG9(v)   (((v) << 18) & BM_CCM_CCGR3_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG9(v)   BF_CS1(CCM_CCGR3, CG9, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG10
 *
 * mmdc_core_aclk_fast_core_p0 clock
 * (mmdc_core_aclk_fast_core_p0_enable)
 */

#define BP_CCM_CCGR3_CG10      20
#define BM_CCM_CCGR3_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR3_CG10)
#else
#define BF_CCM_CCGR3_CG10(v)   (((v) << 20) & BM_CCM_CCGR3_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG10(v)   BF_CS1(CCM_CCGR3, CG10, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG11
 *
 * mmdc_core_aclk_fast_core_p1 clock
 * (mmdc_core_aclk_fast_core_p1_enable)
 */

#define BP_CCM_CCGR3_CG11      22
#define BM_CCM_CCGR3_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR3_CG11)
#else
#define BF_CCM_CCGR3_CG11(v)   (((v) << 22) & BM_CCM_CCGR3_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG11(v)   BF_CS1(CCM_CCGR3, CG11, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG12
 *
 * mmdc_core_ipg_clk_p0 clock (mmdc_core_ipg_clk_p0_enable)
 */

#define BP_CCM_CCGR3_CG12      24
#define BM_CCM_CCGR3_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR3_CG12)
#else
#define BF_CCM_CCGR3_CG12(v)   (((v) << 24) & BM_CCM_CCGR3_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG12(v)   BF_CS1(CCM_CCGR3, CG12, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG13
 *
 * mmdc_core_ipg_clk_p1 clock (mmdc_core_ipg_clk_p1_enable)
 */

#define BP_CCM_CCGR3_CG13      26
#define BM_CCM_CCGR3_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR3_CG13)
#else
#define BF_CCM_CCGR3_CG13(v)   (((v) << 26) & BM_CCM_CCGR3_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG13(v)   BF_CS1(CCM_CCGR3, CG13, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG14
 *
 * ocram clock (ocram_clk_enable)
 */

#define BP_CCM_CCGR3_CG14      28
#define BM_CCM_CCGR3_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR3_CG14)
#else
#define BF_CCM_CCGR3_CG14(v)   (((v) << 28) & BM_CCM_CCGR3_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG14(v)   BF_CS1(CCM_CCGR3, CG14, v)
#endif

/* --- Register HW_CCM_CCGR3, field CG15
 *
 * openvgaxiclk clock (openvgaxiclk_clk_root_enable)
 */

#define BP_CCM_CCGR3_CG15      30
#define BM_CCM_CCGR3_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR3_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR3_CG15)
#else
#define BF_CCM_CCGR3_CG15(v)   (((v) << 30) & BM_CCM_CCGR3_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR3_CG15(v)   BF_CS1(CCM_CCGR3, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR4 - CCM Clock Gating Register 4
 *
 * The figure below represents the CCM Clock Gating Register 4 (CCM_CCGR4).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< pcie clocks (pcie_root_enable)
        unsigned CG1 : 2; //!< perfmon1 clocks (perfmon1_apb_clk_enable)  Reserved.
        unsigned CG2 : 2; //!< perfmon2 clock (perfmon2_apb_clk_enable)  Reserved.
        unsigned CG3 : 2; //!< perfmon3 clocks (perfmon3_apb_clk_enable)  Reserved.
        unsigned CG4 : 2; //!< pl301_mx6qfast1_s133 clock (pl301_mx6qfast1_s133clk_enable)
        unsigned CG5 : 2; //!< Reserved
        unsigned CG6 : 2; //!< pl301_mx6qper1_bch clocks (pl301_mx6qper1_bchclk_enable)
        unsigned CG7 : 2; //!< pl301_mx6qper2_mainclk_enable (pl301_mx6qper2_mainclk_enable)
        unsigned CG8 : 2; //!< pwm1 clocks (pwm1_clk_enable)
        unsigned CG9 : 2; //!< pwm2 clocks (pwm2_clk_enable)
        unsigned CG10 : 2; //!< pwm3 clocks (pwm3_clk_enable)
        unsigned CG11 : 2; //!< pwm4 clocks (pwm4_clk_enable)
        unsigned CG12 : 2; //!< rawnand_u_bch_input_apb clock (rawnand_u_bch_input_apb_clk_enable)
        unsigned CG13 : 2; //!< rawnand_u_gpmi_bch_input_bch clock (rawnand_u_gpmi_bch_input_bch_clk_enable)
        unsigned CG14 : 2; //!< rawnand_u_gpmi_bch_input_gpmi_io clock (rawnand_u_gpmi_bch_input_gpmi_io_clk_enable)
        unsigned CG15 : 2; //!< rawnand_u_gpmi_input_apb clock rawnand_u_gpmi_input_apb_clk_enable)
    } B;
} hw_ccm_ccgr4_t;
#endif

/*
 * constants & macros for entire CCM_CCGR4 register
 */
#define HW_CCM_CCGR4_ADDR      (REGS_CCM_BASE + 0x78)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR4           (*(volatile hw_ccm_ccgr4_t *) HW_CCM_CCGR4_ADDR)
#define HW_CCM_CCGR4_RD()      (HW_CCM_CCGR4.U)
#define HW_CCM_CCGR4_WR(v)     (HW_CCM_CCGR4.U = (v))
#define HW_CCM_CCGR4_SET(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() |  (v)))
#define HW_CCM_CCGR4_CLR(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() & ~(v)))
#define HW_CCM_CCGR4_TOG(v)    (HW_CCM_CCGR4_WR(HW_CCM_CCGR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR4 bitfields
 */

/* --- Register HW_CCM_CCGR4, field CG0
 *
 * pcie clocks (pcie_root_enable)
 */

#define BP_CCM_CCGR4_CG0      0
#define BM_CCM_CCGR4_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR4_CG0)
#else
#define BF_CCM_CCGR4_CG0(v)   (((v) << 0) & BM_CCM_CCGR4_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG0(v)   BF_CS1(CCM_CCGR4, CG0, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG1
 *
 * perfmon1 clocks (perfmon1_apb_clk_enable)  Reserved.
 */

#define BP_CCM_CCGR4_CG1      2
#define BM_CCM_CCGR4_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR4_CG1)
#else
#define BF_CCM_CCGR4_CG1(v)   (((v) << 2) & BM_CCM_CCGR4_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG1(v)   BF_CS1(CCM_CCGR4, CG1, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG2
 *
 * perfmon2 clock (perfmon2_apb_clk_enable)  Reserved.
 */

#define BP_CCM_CCGR4_CG2      4
#define BM_CCM_CCGR4_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR4_CG2)
#else
#define BF_CCM_CCGR4_CG2(v)   (((v) << 4) & BM_CCM_CCGR4_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG2(v)   BF_CS1(CCM_CCGR4, CG2, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG3
 *
 * perfmon3 clocks (perfmon3_apb_clk_enable)  Reserved.
 */

#define BP_CCM_CCGR4_CG3      6
#define BM_CCM_CCGR4_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR4_CG3)
#else
#define BF_CCM_CCGR4_CG3(v)   (((v) << 6) & BM_CCM_CCGR4_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG3(v)   BF_CS1(CCM_CCGR4, CG3, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG4
 *
 * pl301_mx6qfast1_s133 clock (pl301_mx6qfast1_s133clk_enable)
 */

#define BP_CCM_CCGR4_CG4      8
#define BM_CCM_CCGR4_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR4_CG4)
#else
#define BF_CCM_CCGR4_CG4(v)   (((v) << 8) & BM_CCM_CCGR4_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG4(v)   BF_CS1(CCM_CCGR4, CG4, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG5
 *
 * Reserved
 */

#define BP_CCM_CCGR4_CG5      10
#define BM_CCM_CCGR4_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR4_CG5)
#else
#define BF_CCM_CCGR4_CG5(v)   (((v) << 10) & BM_CCM_CCGR4_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG5(v)   BF_CS1(CCM_CCGR4, CG5, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG6
 *
 * pl301_mx6qper1_bch clocks (pl301_mx6qper1_bchclk_enable)
 */

#define BP_CCM_CCGR4_CG6      12
#define BM_CCM_CCGR4_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR4_CG6)
#else
#define BF_CCM_CCGR4_CG6(v)   (((v) << 12) & BM_CCM_CCGR4_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG6(v)   BF_CS1(CCM_CCGR4, CG6, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG7
 *
 * pl301_mx6qper2_mainclk_enable (pl301_mx6qper2_mainclk_enable)
 */

#define BP_CCM_CCGR4_CG7      14
#define BM_CCM_CCGR4_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR4_CG7)
#else
#define BF_CCM_CCGR4_CG7(v)   (((v) << 14) & BM_CCM_CCGR4_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG7(v)   BF_CS1(CCM_CCGR4, CG7, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG8
 *
 * pwm1 clocks (pwm1_clk_enable)
 */

#define BP_CCM_CCGR4_CG8      16
#define BM_CCM_CCGR4_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR4_CG8)
#else
#define BF_CCM_CCGR4_CG8(v)   (((v) << 16) & BM_CCM_CCGR4_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG8(v)   BF_CS1(CCM_CCGR4, CG8, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG9
 *
 * pwm2 clocks (pwm2_clk_enable)
 */

#define BP_CCM_CCGR4_CG9      18
#define BM_CCM_CCGR4_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR4_CG9)
#else
#define BF_CCM_CCGR4_CG9(v)   (((v) << 18) & BM_CCM_CCGR4_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG9(v)   BF_CS1(CCM_CCGR4, CG9, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG10
 *
 * pwm3 clocks (pwm3_clk_enable)
 */

#define BP_CCM_CCGR4_CG10      20
#define BM_CCM_CCGR4_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR4_CG10)
#else
#define BF_CCM_CCGR4_CG10(v)   (((v) << 20) & BM_CCM_CCGR4_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG10(v)   BF_CS1(CCM_CCGR4, CG10, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG11
 *
 * pwm4 clocks (pwm4_clk_enable)
 */

#define BP_CCM_CCGR4_CG11      22
#define BM_CCM_CCGR4_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR4_CG11)
#else
#define BF_CCM_CCGR4_CG11(v)   (((v) << 22) & BM_CCM_CCGR4_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG11(v)   BF_CS1(CCM_CCGR4, CG11, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG12
 *
 * rawnand_u_bch_input_apb clock
 * (rawnand_u_bch_input_apb_clk_enable)
 */

#define BP_CCM_CCGR4_CG12      24
#define BM_CCM_CCGR4_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR4_CG12)
#else
#define BF_CCM_CCGR4_CG12(v)   (((v) << 24) & BM_CCM_CCGR4_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG12(v)   BF_CS1(CCM_CCGR4, CG12, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG13
 *
 * rawnand_u_gpmi_bch_input_bch clock
 * (rawnand_u_gpmi_bch_input_bch_clk_enable)
 */

#define BP_CCM_CCGR4_CG13      26
#define BM_CCM_CCGR4_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR4_CG13)
#else
#define BF_CCM_CCGR4_CG13(v)   (((v) << 26) & BM_CCM_CCGR4_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG13(v)   BF_CS1(CCM_CCGR4, CG13, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG14
 *
 * rawnand_u_gpmi_bch_input_gpmi_io clock
 * (rawnand_u_gpmi_bch_input_gpmi_io_clk_enable)
 */

#define BP_CCM_CCGR4_CG14      28
#define BM_CCM_CCGR4_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR4_CG14)
#else
#define BF_CCM_CCGR4_CG14(v)   (((v) << 28) & BM_CCM_CCGR4_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG14(v)   BF_CS1(CCM_CCGR4, CG14, v)
#endif

/* --- Register HW_CCM_CCGR4, field CG15
 *
 * rawnand_u_gpmi_input_apb clock
 * rawnand_u_gpmi_input_apb_clk_enable)
 */

#define BP_CCM_CCGR4_CG15      30
#define BM_CCM_CCGR4_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR4_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR4_CG15)
#else
#define BF_CCM_CCGR4_CG15(v)   (((v) << 30) & BM_CCM_CCGR4_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR4_CG15(v)   BF_CS1(CCM_CCGR4, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR5 - CCM Clock Gating Register 5
 *
 * The figure below represents the CCM Clock Gating Register 5 (CCM_CCGR5).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< rom clock (rom_clk_enable)
        unsigned CG1 : 2; //!< Reserved
        unsigned CG2 : 2; //!< sata clock (sata_clk_enable)
        unsigned CG3 : 2; //!< sdma clock (sdma_clk_enable)
        unsigned CG4 : 2; //!< Reserved
        unsigned CG5 : 2; //!< Reserved
        unsigned CG6 : 2; //!< spba clock (spba_clk_enable)
        unsigned CG7 : 2; //!< spdif clock (spdif_clk_enable)
        unsigned CG8 : 2; //!< Reserved
        unsigned CG9 : 2; //!< ssi1 clocks (ssi1_clk_enable)
        unsigned CG10 : 2; //!< ssi2 clocks (ssi2_clk_enable)
        unsigned CG11 : 2; //!< ssi3 clocks (ssi3_clk_enable)
        unsigned CG12 : 2; //!< uart clock (uart_clk_enable)
        unsigned CG13 : 2; //!< uart_serial clock (uart_serial_clk_enable)
        unsigned CG14 : 2; //!< Reserved
        unsigned CG15 : 2; //!< Reserved
    } B;
} hw_ccm_ccgr5_t;
#endif

/*
 * constants & macros for entire CCM_CCGR5 register
 */
#define HW_CCM_CCGR5_ADDR      (REGS_CCM_BASE + 0x7c)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR5           (*(volatile hw_ccm_ccgr5_t *) HW_CCM_CCGR5_ADDR)
#define HW_CCM_CCGR5_RD()      (HW_CCM_CCGR5.U)
#define HW_CCM_CCGR5_WR(v)     (HW_CCM_CCGR5.U = (v))
#define HW_CCM_CCGR5_SET(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() |  (v)))
#define HW_CCM_CCGR5_CLR(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() & ~(v)))
#define HW_CCM_CCGR5_TOG(v)    (HW_CCM_CCGR5_WR(HW_CCM_CCGR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR5 bitfields
 */

/* --- Register HW_CCM_CCGR5, field CG0
 *
 * rom clock (rom_clk_enable)
 */

#define BP_CCM_CCGR5_CG0      0
#define BM_CCM_CCGR5_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR5_CG0)
#else
#define BF_CCM_CCGR5_CG0(v)   (((v) << 0) & BM_CCM_CCGR5_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG0(v)   BF_CS1(CCM_CCGR5, CG0, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG1
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG1      2
#define BM_CCM_CCGR5_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR5_CG1)
#else
#define BF_CCM_CCGR5_CG1(v)   (((v) << 2) & BM_CCM_CCGR5_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG1(v)   BF_CS1(CCM_CCGR5, CG1, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG2
 *
 * sata clock (sata_clk_enable)
 */

#define BP_CCM_CCGR5_CG2      4
#define BM_CCM_CCGR5_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR5_CG2)
#else
#define BF_CCM_CCGR5_CG2(v)   (((v) << 4) & BM_CCM_CCGR5_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG2(v)   BF_CS1(CCM_CCGR5, CG2, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG3
 *
 * sdma clock (sdma_clk_enable)
 */

#define BP_CCM_CCGR5_CG3      6
#define BM_CCM_CCGR5_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR5_CG3)
#else
#define BF_CCM_CCGR5_CG3(v)   (((v) << 6) & BM_CCM_CCGR5_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG3(v)   BF_CS1(CCM_CCGR5, CG3, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG4
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG4      8
#define BM_CCM_CCGR5_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR5_CG4)
#else
#define BF_CCM_CCGR5_CG4(v)   (((v) << 8) & BM_CCM_CCGR5_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG4(v)   BF_CS1(CCM_CCGR5, CG4, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG5
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG5      10
#define BM_CCM_CCGR5_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR5_CG5)
#else
#define BF_CCM_CCGR5_CG5(v)   (((v) << 10) & BM_CCM_CCGR5_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG5(v)   BF_CS1(CCM_CCGR5, CG5, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG6
 *
 * spba clock (spba_clk_enable)
 */

#define BP_CCM_CCGR5_CG6      12
#define BM_CCM_CCGR5_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR5_CG6)
#else
#define BF_CCM_CCGR5_CG6(v)   (((v) << 12) & BM_CCM_CCGR5_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG6(v)   BF_CS1(CCM_CCGR5, CG6, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG7
 *
 * spdif clock (spdif_clk_enable)
 */

#define BP_CCM_CCGR5_CG7      14
#define BM_CCM_CCGR5_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR5_CG7)
#else
#define BF_CCM_CCGR5_CG7(v)   (((v) << 14) & BM_CCM_CCGR5_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG7(v)   BF_CS1(CCM_CCGR5, CG7, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG8
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG8      16
#define BM_CCM_CCGR5_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR5_CG8)
#else
#define BF_CCM_CCGR5_CG8(v)   (((v) << 16) & BM_CCM_CCGR5_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG8(v)   BF_CS1(CCM_CCGR5, CG8, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG9
 *
 * ssi1 clocks (ssi1_clk_enable)
 */

#define BP_CCM_CCGR5_CG9      18
#define BM_CCM_CCGR5_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR5_CG9)
#else
#define BF_CCM_CCGR5_CG9(v)   (((v) << 18) & BM_CCM_CCGR5_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG9(v)   BF_CS1(CCM_CCGR5, CG9, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG10
 *
 * ssi2 clocks (ssi2_clk_enable)
 */

#define BP_CCM_CCGR5_CG10      20
#define BM_CCM_CCGR5_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR5_CG10)
#else
#define BF_CCM_CCGR5_CG10(v)   (((v) << 20) & BM_CCM_CCGR5_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG10(v)   BF_CS1(CCM_CCGR5, CG10, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG11
 *
 * ssi3 clocks (ssi3_clk_enable)
 */

#define BP_CCM_CCGR5_CG11      22
#define BM_CCM_CCGR5_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR5_CG11)
#else
#define BF_CCM_CCGR5_CG11(v)   (((v) << 22) & BM_CCM_CCGR5_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG11(v)   BF_CS1(CCM_CCGR5, CG11, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG12
 *
 * uart clock (uart_clk_enable)
 */

#define BP_CCM_CCGR5_CG12      24
#define BM_CCM_CCGR5_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR5_CG12)
#else
#define BF_CCM_CCGR5_CG12(v)   (((v) << 24) & BM_CCM_CCGR5_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG12(v)   BF_CS1(CCM_CCGR5, CG12, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG13
 *
 * uart_serial clock (uart_serial_clk_enable)
 */

#define BP_CCM_CCGR5_CG13      26
#define BM_CCM_CCGR5_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR5_CG13)
#else
#define BF_CCM_CCGR5_CG13(v)   (((v) << 26) & BM_CCM_CCGR5_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG13(v)   BF_CS1(CCM_CCGR5, CG13, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG14
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG14      28
#define BM_CCM_CCGR5_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR5_CG14)
#else
#define BF_CCM_CCGR5_CG14(v)   (((v) << 28) & BM_CCM_CCGR5_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG14(v)   BF_CS1(CCM_CCGR5, CG14, v)
#endif

/* --- Register HW_CCM_CCGR5, field CG15
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG15      30
#define BM_CCM_CCGR5_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR5_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR5_CG15)
#else
#define BF_CCM_CCGR5_CG15(v)   (((v) << 30) & BM_CCM_CCGR5_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR5_CG15(v)   BF_CS1(CCM_CCGR5, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR6 - CCM Clock Gating Register 6
 *
 * The figure below represents the CCM Clock Gating Register 6 (CCM_CCGR6).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< usboh3 clock (usboh3_clk_enable)
        unsigned CG1 : 2; //!< usdhc1 clocks (usdhc1_clk_enable)
        unsigned CG2 : 2; //!< usdhc2 clocks (usdhc2_clk_enable)
        unsigned CG3 : 2; //!< usdhc3 clocks (usdhc3_clk_enable)
        unsigned CG4 : 2; //!< usdhc4 clocks (usdhc4_clk_enable)
        unsigned CG5 : 2; //!< emi_slow clocks (emi_slow_clk_enable)
        unsigned CG6 : 2; //!< vdoaxiclk root clock (vdoaxiclk_clk_enable)
        unsigned CG7 : 2; //!< vpu clocks (vpu_clk_enable)
        unsigned CG8 : 2; //!< Reserved
        unsigned CG9 : 2; //!< Reserved
        unsigned CG10 : 2; //!< Reserved
        unsigned CG11 : 2; //!< Reserved
        unsigned CG12 : 2; //!< Reserved
        unsigned CG13 : 2; //!< Reserved
        unsigned CG14 : 2; //!< Reserved
        unsigned CG15 : 2; //!< Reserved
    } B;
} hw_ccm_ccgr6_t;
#endif

/*
 * constants & macros for entire CCM_CCGR6 register
 */
#define HW_CCM_CCGR6_ADDR      (REGS_CCM_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR6           (*(volatile hw_ccm_ccgr6_t *) HW_CCM_CCGR6_ADDR)
#define HW_CCM_CCGR6_RD()      (HW_CCM_CCGR6.U)
#define HW_CCM_CCGR6_WR(v)     (HW_CCM_CCGR6.U = (v))
#define HW_CCM_CCGR6_SET(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() |  (v)))
#define HW_CCM_CCGR6_CLR(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() & ~(v)))
#define HW_CCM_CCGR6_TOG(v)    (HW_CCM_CCGR6_WR(HW_CCM_CCGR6_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR6 bitfields
 */

/* --- Register HW_CCM_CCGR6, field CG0
 *
 * usboh3 clock (usboh3_clk_enable)
 */

#define BP_CCM_CCGR6_CG0      0
#define BM_CCM_CCGR6_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR6_CG0)
#else
#define BF_CCM_CCGR6_CG0(v)   (((v) << 0) & BM_CCM_CCGR6_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG0(v)   BF_CS1(CCM_CCGR6, CG0, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG1
 *
 * usdhc1 clocks (usdhc1_clk_enable)
 */

#define BP_CCM_CCGR6_CG1      2
#define BM_CCM_CCGR6_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR6_CG1)
#else
#define BF_CCM_CCGR6_CG1(v)   (((v) << 2) & BM_CCM_CCGR6_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG1(v)   BF_CS1(CCM_CCGR6, CG1, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG2
 *
 * usdhc2 clocks (usdhc2_clk_enable)
 */

#define BP_CCM_CCGR6_CG2      4
#define BM_CCM_CCGR6_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR6_CG2)
#else
#define BF_CCM_CCGR6_CG2(v)   (((v) << 4) & BM_CCM_CCGR6_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG2(v)   BF_CS1(CCM_CCGR6, CG2, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG3
 *
 * usdhc3 clocks (usdhc3_clk_enable)
 */

#define BP_CCM_CCGR6_CG3      6
#define BM_CCM_CCGR6_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR6_CG3)
#else
#define BF_CCM_CCGR6_CG3(v)   (((v) << 6) & BM_CCM_CCGR6_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG3(v)   BF_CS1(CCM_CCGR6, CG3, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG4
 *
 * usdhc4 clocks (usdhc4_clk_enable)
 */

#define BP_CCM_CCGR6_CG4      8
#define BM_CCM_CCGR6_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR6_CG4)
#else
#define BF_CCM_CCGR6_CG4(v)   (((v) << 8) & BM_CCM_CCGR6_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG4(v)   BF_CS1(CCM_CCGR6, CG4, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG5
 *
 * emi_slow clocks (emi_slow_clk_enable)
 */

#define BP_CCM_CCGR6_CG5      10
#define BM_CCM_CCGR6_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR6_CG5)
#else
#define BF_CCM_CCGR6_CG5(v)   (((v) << 10) & BM_CCM_CCGR6_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG5(v)   BF_CS1(CCM_CCGR6, CG5, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG6
 *
 * vdoaxiclk root clock (vdoaxiclk_clk_enable)
 */

#define BP_CCM_CCGR6_CG6      12
#define BM_CCM_CCGR6_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR6_CG6)
#else
#define BF_CCM_CCGR6_CG6(v)   (((v) << 12) & BM_CCM_CCGR6_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG6(v)   BF_CS1(CCM_CCGR6, CG6, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG7
 *
 * vpu clocks (vpu_clk_enable)
 */

#define BP_CCM_CCGR6_CG7      14
#define BM_CCM_CCGR6_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR6_CG7)
#else
#define BF_CCM_CCGR6_CG7(v)   (((v) << 14) & BM_CCM_CCGR6_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG7(v)   BF_CS1(CCM_CCGR6, CG7, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG8
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG8      16
#define BM_CCM_CCGR6_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR6_CG8)
#else
#define BF_CCM_CCGR6_CG8(v)   (((v) << 16) & BM_CCM_CCGR6_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG8(v)   BF_CS1(CCM_CCGR6, CG8, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG9
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG9      18
#define BM_CCM_CCGR6_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR6_CG9)
#else
#define BF_CCM_CCGR6_CG9(v)   (((v) << 18) & BM_CCM_CCGR6_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG9(v)   BF_CS1(CCM_CCGR6, CG9, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG10
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG10      20
#define BM_CCM_CCGR6_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR6_CG10)
#else
#define BF_CCM_CCGR6_CG10(v)   (((v) << 20) & BM_CCM_CCGR6_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG10(v)   BF_CS1(CCM_CCGR6, CG10, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG11
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG11      22
#define BM_CCM_CCGR6_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR6_CG11)
#else
#define BF_CCM_CCGR6_CG11(v)   (((v) << 22) & BM_CCM_CCGR6_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG11(v)   BF_CS1(CCM_CCGR6, CG11, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG12
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG12      24
#define BM_CCM_CCGR6_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR6_CG12)
#else
#define BF_CCM_CCGR6_CG12(v)   (((v) << 24) & BM_CCM_CCGR6_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG12(v)   BF_CS1(CCM_CCGR6, CG12, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG13
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG13      26
#define BM_CCM_CCGR6_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR6_CG13)
#else
#define BF_CCM_CCGR6_CG13(v)   (((v) << 26) & BM_CCM_CCGR6_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG13(v)   BF_CS1(CCM_CCGR6, CG13, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG14
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG14      28
#define BM_CCM_CCGR6_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR6_CG14)
#else
#define BF_CCM_CCGR6_CG14(v)   (((v) << 28) & BM_CCM_CCGR6_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG14(v)   BF_CS1(CCM_CCGR6, CG14, v)
#endif

/* --- Register HW_CCM_CCGR6, field CG15
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG15      30
#define BM_CCM_CCGR6_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR6_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR6_CG15)
#else
#define BF_CCM_CCGR6_CG15(v)   (((v) << 30) & BM_CCM_CCGR6_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR6_CG15(v)   BF_CS1(CCM_CCGR6, CG15, v)
#endif

/*!
 * @brief HW_CCM_CCGR7 - CCM Clock Gating Register 7
 *
 * The figure below represents the CCM Clock Gating Register 7 (CCM_CCGR7).
 * The clock gating Registers define the clock gating for power reduction
 * of each clock (CG(i) bits). There are 8 CGR registers. The number of
 * registers required is according to the number of peripherals in the
 * system.  CG(i) bits CCGR 0-7  This bits are used to turn on/off the clock to each module
 * independently.The following table details the possible clock activity
 * conditions for each module         CGR value    Clock Activity
 * Description        00    clock is off during all modes. stop
 * enter hardware handshake is disabled.      01    clock is on in run mode, but off in
 * wait and stop modes      10    Not applicable
 * (Reserved).      11    clock is on during all modes,
 * except stop mode.       : Module should be stopped, before set it's bits to "0", since clocks to
 * the module will be stopped immediately.  The tables above show the register mapings for the
 * different CGR's. The                             clock connectivity table should be used to match
 * the "CCM output                             affected" to the actual clocks going into the
 * modules.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CG0 : 2; //!< CG0
        unsigned CG1 : 2; //!< CG1
        unsigned CG2 : 2; //!< CG2
        unsigned CG3 : 2; //!< CG3
        unsigned CG4 : 2; //!< CG4
        unsigned CG5 : 2; //!< CG5
        unsigned CG6 : 2; //!< CG6
        unsigned CG7 : 2; //!< CG7
        unsigned CG8 : 2; //!< CG8
        unsigned CG9 : 2; //!< CG9
        unsigned CG10 : 2; //!< CG10
        unsigned CG11 : 2; //!< CG11
        unsigned CG12 : 2; //!< CG12
        unsigned CG13 : 2; //!< CG13
        unsigned CG14 : 2; //!< CG14
        unsigned CG15 : 2; //!< CG15
    } B;
} hw_ccm_ccgr7_t;
#endif

/*
 * constants & macros for entire CCM_CCGR7 register
 */
#define HW_CCM_CCGR7_ADDR      (REGS_CCM_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CCGR7           (*(volatile hw_ccm_ccgr7_t *) HW_CCM_CCGR7_ADDR)
#define HW_CCM_CCGR7_RD()      (HW_CCM_CCGR7.U)
#define HW_CCM_CCGR7_WR(v)     (HW_CCM_CCGR7.U = (v))
#define HW_CCM_CCGR7_SET(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() |  (v)))
#define HW_CCM_CCGR7_CLR(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() & ~(v)))
#define HW_CCM_CCGR7_TOG(v)    (HW_CCM_CCGR7_WR(HW_CCM_CCGR7_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CCGR7 bitfields
 */

/* --- Register HW_CCM_CCGR7, field CG0
 *
 * CG0
 */

#define BP_CCM_CCGR7_CG0      0
#define BM_CCM_CCGR7_CG0      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG0(v)   ((((reg32_t) v) << 0) & BM_CCM_CCGR7_CG0)
#else
#define BF_CCM_CCGR7_CG0(v)   (((v) << 0) & BM_CCM_CCGR7_CG0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG0(v)   BF_CS1(CCM_CCGR7, CG0, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG1
 *
 * CG1
 */

#define BP_CCM_CCGR7_CG1      2
#define BM_CCM_CCGR7_CG1      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG1(v)   ((((reg32_t) v) << 2) & BM_CCM_CCGR7_CG1)
#else
#define BF_CCM_CCGR7_CG1(v)   (((v) << 2) & BM_CCM_CCGR7_CG1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG1(v)   BF_CS1(CCM_CCGR7, CG1, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG2
 *
 * CG2
 */

#define BP_CCM_CCGR7_CG2      4
#define BM_CCM_CCGR7_CG2      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG2(v)   ((((reg32_t) v) << 4) & BM_CCM_CCGR7_CG2)
#else
#define BF_CCM_CCGR7_CG2(v)   (((v) << 4) & BM_CCM_CCGR7_CG2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG2(v)   BF_CS1(CCM_CCGR7, CG2, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG3
 *
 * CG3
 */

#define BP_CCM_CCGR7_CG3      6
#define BM_CCM_CCGR7_CG3      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG3(v)   ((((reg32_t) v) << 6) & BM_CCM_CCGR7_CG3)
#else
#define BF_CCM_CCGR7_CG3(v)   (((v) << 6) & BM_CCM_CCGR7_CG3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG3(v)   BF_CS1(CCM_CCGR7, CG3, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG4
 *
 * CG4
 */

#define BP_CCM_CCGR7_CG4      8
#define BM_CCM_CCGR7_CG4      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG4(v)   ((((reg32_t) v) << 8) & BM_CCM_CCGR7_CG4)
#else
#define BF_CCM_CCGR7_CG4(v)   (((v) << 8) & BM_CCM_CCGR7_CG4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG4(v)   BF_CS1(CCM_CCGR7, CG4, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG5
 *
 * CG5
 */

#define BP_CCM_CCGR7_CG5      10
#define BM_CCM_CCGR7_CG5      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG5(v)   ((((reg32_t) v) << 10) & BM_CCM_CCGR7_CG5)
#else
#define BF_CCM_CCGR7_CG5(v)   (((v) << 10) & BM_CCM_CCGR7_CG5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG5(v)   BF_CS1(CCM_CCGR7, CG5, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG6
 *
 * CG6
 */

#define BP_CCM_CCGR7_CG6      12
#define BM_CCM_CCGR7_CG6      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG6(v)   ((((reg32_t) v) << 12) & BM_CCM_CCGR7_CG6)
#else
#define BF_CCM_CCGR7_CG6(v)   (((v) << 12) & BM_CCM_CCGR7_CG6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG6(v)   BF_CS1(CCM_CCGR7, CG6, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG7
 *
 * CG7
 */

#define BP_CCM_CCGR7_CG7      14
#define BM_CCM_CCGR7_CG7      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG7(v)   ((((reg32_t) v) << 14) & BM_CCM_CCGR7_CG7)
#else
#define BF_CCM_CCGR7_CG7(v)   (((v) << 14) & BM_CCM_CCGR7_CG7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG7(v)   BF_CS1(CCM_CCGR7, CG7, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG8
 *
 * CG8
 */

#define BP_CCM_CCGR7_CG8      16
#define BM_CCM_CCGR7_CG8      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG8(v)   ((((reg32_t) v) << 16) & BM_CCM_CCGR7_CG8)
#else
#define BF_CCM_CCGR7_CG8(v)   (((v) << 16) & BM_CCM_CCGR7_CG8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG8(v)   BF_CS1(CCM_CCGR7, CG8, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG9
 *
 * CG9
 */

#define BP_CCM_CCGR7_CG9      18
#define BM_CCM_CCGR7_CG9      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG9(v)   ((((reg32_t) v) << 18) & BM_CCM_CCGR7_CG9)
#else
#define BF_CCM_CCGR7_CG9(v)   (((v) << 18) & BM_CCM_CCGR7_CG9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG9(v)   BF_CS1(CCM_CCGR7, CG9, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG10
 *
 * CG10
 */

#define BP_CCM_CCGR7_CG10      20
#define BM_CCM_CCGR7_CG10      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG10(v)   ((((reg32_t) v) << 20) & BM_CCM_CCGR7_CG10)
#else
#define BF_CCM_CCGR7_CG10(v)   (((v) << 20) & BM_CCM_CCGR7_CG10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG10(v)   BF_CS1(CCM_CCGR7, CG10, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG11
 *
 * CG11
 */

#define BP_CCM_CCGR7_CG11      22
#define BM_CCM_CCGR7_CG11      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG11(v)   ((((reg32_t) v) << 22) & BM_CCM_CCGR7_CG11)
#else
#define BF_CCM_CCGR7_CG11(v)   (((v) << 22) & BM_CCM_CCGR7_CG11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG11(v)   BF_CS1(CCM_CCGR7, CG11, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG12
 *
 * CG12
 */

#define BP_CCM_CCGR7_CG12      24
#define BM_CCM_CCGR7_CG12      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG12(v)   ((((reg32_t) v) << 24) & BM_CCM_CCGR7_CG12)
#else
#define BF_CCM_CCGR7_CG12(v)   (((v) << 24) & BM_CCM_CCGR7_CG12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG12(v)   BF_CS1(CCM_CCGR7, CG12, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG13
 *
 * CG13
 */

#define BP_CCM_CCGR7_CG13      26
#define BM_CCM_CCGR7_CG13      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG13(v)   ((((reg32_t) v) << 26) & BM_CCM_CCGR7_CG13)
#else
#define BF_CCM_CCGR7_CG13(v)   (((v) << 26) & BM_CCM_CCGR7_CG13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG13(v)   BF_CS1(CCM_CCGR7, CG13, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG14
 *
 * CG14
 */

#define BP_CCM_CCGR7_CG14      28
#define BM_CCM_CCGR7_CG14      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG14(v)   ((((reg32_t) v) << 28) & BM_CCM_CCGR7_CG14)
#else
#define BF_CCM_CCGR7_CG14(v)   (((v) << 28) & BM_CCM_CCGR7_CG14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG14(v)   BF_CS1(CCM_CCGR7, CG14, v)
#endif

/* --- Register HW_CCM_CCGR7, field CG15
 *
 * CG15
 */

#define BP_CCM_CCGR7_CG15      30
#define BM_CCM_CCGR7_CG15      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CCGR7_CG15(v)   ((((reg32_t) v) << 30) & BM_CCM_CCGR7_CG15)
#else
#define BF_CCM_CCGR7_CG15(v)   (((v) << 30) & BM_CCM_CCGR7_CG15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CCGR7_CG15(v)   BF_CS1(CCM_CCGR7, CG15, v)
#endif

/*!
 * @brief HW_CCM_CMEOR - CCM Module Enable Overide Register
 *
 * The follow figure represents the CCM Module Enable Override Register
 * (CMEOR). The CMEOR register contains bits to override the clock enable
 * signal from the module. This should be used in case that it is decided
 * to bypass the clock enable signals from the modules. This bit will be
 * applicable only for module that their clock enable signal is used. The
 * following table provides its field descriptions.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned MOD_EN_OV_VDOA : 1; //!< overide clock enable signal from vdoa - clock will not be gated based on vdoa signal.
        unsigned MOD_EN_OV_GPT : 1; //!< overide clock enable signal from gpt - clock will not be gated based on gpt's signal 'ipg_enable_clk' .
        unsigned MOD_EN_OV_EPIT : 1; //!< overide clock enable signal from epit - clock will not be gated based on epit's signal 'ipg_enable_clk' .
        unsigned MOD_EN_USDHC : 1; //!< overide clock enable signal from usdhc.
        unsigned MOD_EN_OV_DAP : 1; //!< overide clock enable signal from dap- clock will not be gated based on dap's signal 'dap_dbgen' .
        unsigned MOD_EN_OV_VPU : 1; //!< overide clock enable signal from vpu- clock will not be gated based on vpu's signal 'vpu_idle' .
        unsigned MOD_EN_OV_GPU2D : 1; //!< overide clock enable signal from gpu2d - clock will not be gated based on gpu2d's signal 'gpu2d_busy' .
        unsigned MOD_EN_OV_GPU3D : 1; //!< overide clock enable signal from gpu3d - clock will not be gated based on gpu3d's signal.
        unsigned RESERVED1 : 16; //!< Reserved
        unsigned MOD_EN_OV_CAN2_CPI : 1; //!< overide clock enable signal from can2 - clock will not be gated based on can's signal 'enable_clk_cpi'.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned MOD_EN_OV_CAN1_CPI : 1; //!< overide clock enable signal from can1 - clock will not be gated based on can's signal 'enable_clk_cpi'.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_ccm_cmeor_t;
#endif

/*
 * constants & macros for entire CCM_CMEOR register
 */
#define HW_CCM_CMEOR_ADDR      (REGS_CCM_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_CMEOR           (*(volatile hw_ccm_cmeor_t *) HW_CCM_CMEOR_ADDR)
#define HW_CCM_CMEOR_RD()      (HW_CCM_CMEOR.U)
#define HW_CCM_CMEOR_WR(v)     (HW_CCM_CMEOR.U = (v))
#define HW_CCM_CMEOR_SET(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() |  (v)))
#define HW_CCM_CMEOR_CLR(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() & ~(v)))
#define HW_CCM_CMEOR_TOG(v)    (HW_CCM_CMEOR_WR(HW_CCM_CMEOR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual CCM_CMEOR bitfields
 */

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VDOA
 *
 * overide clock enable signal from vdoa - clock will not be gated based
 * on vdoa signal.
 */

#define BP_CCM_CMEOR_MOD_EN_OV_VDOA      4
#define BM_CCM_CMEOR_MOD_EN_OV_VDOA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   ((((reg32_t) v) << 4) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   (((v) << 4) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_VDOA(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_VDOA, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPT
 *
 * overide clock enable signal from gpt - clock will not be gated based
 * on gpt's signal 'ipg_enable_clk' .
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPT      5
#define BM_CCM_CMEOR_MOD_EN_OV_GPT      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   ((((reg32_t) v) << 5) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   (((v) << 5) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPT(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPT, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_EPIT
 *
 * overide clock enable signal from epit - clock will not be gated based
 * on epit's signal 'ipg_enable_clk' .
 */

#define BP_CCM_CMEOR_MOD_EN_OV_EPIT      6
#define BM_CCM_CMEOR_MOD_EN_OV_EPIT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   ((((reg32_t) v) << 6) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   (((v) << 6) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_EPIT(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_EPIT, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_USDHC
 *
 * overide clock enable signal from usdhc.
 */

#define BP_CCM_CMEOR_MOD_EN_USDHC      7
#define BM_CCM_CMEOR_MOD_EN_USDHC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   ((((reg32_t) v) << 7) & BM_CCM_CMEOR_MOD_EN_USDHC)
#else
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   (((v) << 7) & BM_CCM_CMEOR_MOD_EN_USDHC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_USDHC(v)   BF_CS1(CCM_CMEOR, MOD_EN_USDHC, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_DAP
 *
 * overide clock enable signal from dap- clock will not be gated based
 * on dap's signal 'dap_dbgen' .
 */

#define BP_CCM_CMEOR_MOD_EN_OV_DAP      8
#define BM_CCM_CMEOR_MOD_EN_OV_DAP      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   ((((reg32_t) v) << 8) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   (((v) << 8) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_DAP(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_DAP, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VPU
 *
 * overide clock enable signal from vpu- clock will not be gated based
 * on vpu's signal 'vpu_idle' .
 */

#define BP_CCM_CMEOR_MOD_EN_OV_VPU      9
#define BM_CCM_CMEOR_MOD_EN_OV_VPU      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   ((((reg32_t) v) << 9) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   (((v) << 9) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_VPU(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_VPU, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU2D
 *
 * overide clock enable signal from gpu2d - clock will not be gated
 * based on gpu2d's signal 'gpu2d_busy' .
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU2D      10
#define BM_CCM_CMEOR_MOD_EN_OV_GPU2D      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   ((((reg32_t) v) << 10) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   (((v) << 10) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPU2D, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU3D
 *
 * overide clock enable signal from gpu3d - clock will not be gated
 * based on gpu3d's signal.
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU3D      11
#define BM_CCM_CMEOR_MOD_EN_OV_GPU3D      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   ((((reg32_t) v) << 11) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   (((v) << 11) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_GPU3D, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN2_CPI
 *
 * overide clock enable signal from can2 - clock will not be gated based
 * on can's signal 'enable_clk_cpi'.
 */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      28
#define BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   ((((reg32_t) v) << 28) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   (((v) << 28) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_CAN2_CPI, v)
#endif

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN1_CPI
 *
 * overide clock enable signal from can1 - clock will not be gated based
 * on can's signal 'enable_clk_cpi'.
 */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      30
#define BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   ((((reg32_t) v) << 30) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#else
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   (((v) << 30) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   BF_CS1(CCM_CMEOR, MOD_EN_OV_CAN1_CPI, v)
#endif



/*!
 * @brief All CCM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_ccm_ccr_t CCR; //!< CCM Control Register
    volatile hw_ccm_ccdr_t CCDR; //!< CCM Control Divider Register
    volatile hw_ccm_csr_t CSR; //!< CCM Status Register
    volatile hw_ccm_ccsr_t CCSR; //!< CCM Clock Swither Register
    volatile hw_ccm_cacrr_t CACRR; //!< CCM Arm Clock Root Register
    volatile hw_ccm_cbcdr_t CBCDR; //!< CCM Bus Clock Divider Register
    volatile hw_ccm_cbcmr_t CBCMR; //!< CCM Bus Clock Multiplexer Register
    volatile hw_ccm_cscmr1_t CSCMR1; //!< CCM Serial Clock Multiplexer Register 1
    volatile hw_ccm_cscmr2_t CSCMR2; //!< CCM Serial Clock Multiplexer Register 2
    volatile hw_ccm_cscdr1_t CSCDR1; //!< CCM Serial Clock Divider Register 1
    volatile hw_ccm_cs1cdr_t CS1CDR; //!< CCM SSI1 Clock Divider Register
    volatile hw_ccm_cs2cdr_t CS2CDR; //!< CCM SSI2 Clock Divider Register
    volatile hw_ccm_cdcdr_t CDCDR; //!< CCM D1 Clock Divider Register
    volatile hw_ccm_chsccdr_t CHSCCDR; //!< CCM HSC Clock Divider Register
    volatile hw_ccm_cscdr2_t CSCDR2; //!< CCM Serial Clock Divider Register 2
    volatile hw_ccm_cscdr3_t CSCDR3; //!< CCM Serial Clock Divider Register 3
    reg32_t _reserved0;
    volatile hw_ccm_cwdr_t CWDR; //!< CCM Wakeup Detector Register
    volatile hw_ccm_cdhipr_t CDHIPR; //!< CCM Divider Handshake In-Process Register
    reg32_t _reserved1;
    volatile hw_ccm_ctor_t CTOR; //!< CCM Testing Observability Register
    volatile hw_ccm_clpcr_t CLPCR; //!< CCM Low Power Control Register
    volatile hw_ccm_cisr_t CISR; //!< CCM Interrupt Status Register
    volatile hw_ccm_cimr_t CIMR; //!< CCM Interrupt Mask Register
    volatile hw_ccm_ccosr_t CCOSR; //!< CCM Clock Output Source Register
    volatile hw_ccm_cgpr_t CGPR; //!< CCM General Purpose Register
    volatile hw_ccm_ccgr0_t CCGR0; //!< CCM Clock Gating Register 0
    volatile hw_ccm_ccgr1_t CCGR1; //!< CCM Clock Gating Register 1
    volatile hw_ccm_ccgr2_t CCGR2; //!< CCM Clock Gating Register 2
    volatile hw_ccm_ccgr3_t CCGR3; //!< CCM Clock Gating Register 3
    volatile hw_ccm_ccgr4_t CCGR4; //!< CCM Clock Gating Register 4
    volatile hw_ccm_ccgr5_t CCGR5; //!< CCM Clock Gating Register 5
    volatile hw_ccm_ccgr6_t CCGR6; //!< CCM Clock Gating Register 6
    volatile hw_ccm_ccgr7_t CCGR7; //!< CCM Clock Gating Register 7
    volatile hw_ccm_cmeor_t CMEOR; //!< CCM Module Enable Overide Register
} hw_ccm_t
#endif

//! @brief Macro to access all CCM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM(0)</code>.
#define HW_CCM     (*(volatile hw_ccm_t *) REGS_CCM_BASE)


#endif // _CCM_H
