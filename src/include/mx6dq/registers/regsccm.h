/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_CCM_REGISTERS_H__
#define __HW_CCM_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ CCM registers defined in this header file.
 *
 * - HW_CCM_CCR - CCM Control Register
 * - HW_CCM_CCDR - CCM Control Divider Register
 * - HW_CCM_CSR - CCM Status Register
 * - HW_CCM_CCSR - CCM Clock Swither Register
 * - HW_CCM_CACRR - CCM Arm Clock Root Register
 * - HW_CCM_CBCDR - CCM Bus Clock Divider Register
 * - HW_CCM_CBCMR - CCM Bus Clock Multiplexer Register
 * - HW_CCM_CSCMR1 - CCM Serial Clock Multiplexer Register 1
 * - HW_CCM_CSCMR2 - CCM Serial Clock Multiplexer Register 2
 * - HW_CCM_CSCDR1 - CCM Serial Clock Divider Register 1
 * - HW_CCM_CS1CDR - CCM SSI1 Clock Divider Register
 * - HW_CCM_CS2CDR - CCM SSI2 Clock Divider Register
 * - HW_CCM_CDCDR - CCM D1 Clock Divider Register
 * - HW_CCM_CHSCCDR - CCM HSC Clock Divider Register
 * - HW_CCM_CSCDR2 - CCM Serial Clock Divider Register 2
 * - HW_CCM_CSCDR3 - CCM Serial Clock Divider Register 3
 * - HW_CCM_CWDR - CCM Wakeup Detector Register
 * - HW_CCM_CDHIPR - CCM Divider Handshake In-Process Register
 * - HW_CCM_CTOR - CCM Testing Observability Register
 * - HW_CCM_CLPCR - CCM Low Power Control Register
 * - HW_CCM_CISR - CCM Interrupt Status Register
 * - HW_CCM_CIMR - CCM Interrupt Mask Register
 * - HW_CCM_CCOSR - CCM Clock Output Source Register
 * - HW_CCM_CGPR - CCM General Purpose Register
 * - HW_CCM_CCGR0 - CCM Clock Gating Register 0
 * - HW_CCM_CCGR1 - CCM Clock Gating Register 1
 * - HW_CCM_CCGR2 - CCM Clock Gating Register 2
 * - HW_CCM_CCGR3 - CCM Clock Gating Register 3
 * - HW_CCM_CCGR4 - CCM Clock Gating Register 4
 * - HW_CCM_CCGR5 - CCM Clock Gating Register 5
 * - HW_CCM_CCGR6 - CCM Clock Gating Register 6
 * - HW_CCM_CCGR7 - CCM Clock Gating Register 7
 * - HW_CCM_CMEOR - CCM Module Enable Overide Register
 *
 * - hw_ccm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CCM_BASE
#define HW_CCM_INSTANCE_COUNT (1) //!< Number of instances of the CCM module.
#define REGS_CCM_BASE (0x020c4000) //!< Base address for CCM.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCR - CCM Control Register (RW)
 *
 * Reset value: 0x040116ff
 *
 * The figure below represents the CCM Control Register (CCR), which contains bits to control
 * general operation of CCM. The table below provides its field descriptions.
 */
typedef union _hw_ccm_ccr
{
    reg32_t U;
    struct _hw_ccm_ccr_bitfields
    {
        unsigned OSCNT : 8; //!< [7:0] Oscillator ready counter value. These bits define value of 32KHz counter, that serve as counter for oscillator lock time. This is used for oscillator lock time. Current estimation is ~5ms. This counter will be used in ignition sequence and in wake from stop sequence if sbyos bit was defined, to notify that on chip oscillator output is ready for the dpll_ip to use and only then the gate in dpll_ip can be opened.
        unsigned RESERVED0 : 4; //!< [11:8] Reserved
        unsigned COSC_EN : 1; //!< [12] On chip oscillator enable bit - this bit value is reflected on the output cosc_en. The system will start with on chip oscillator enabled to supply source for the PLL's. Software can change this bit if a transition to the bypass PLL clocks was performed for all the PLLs. In cases that this bit is changed from '0' to '1' then CCM will enable the on chip oscillator and after counting oscnt ckil clock cycles it will notify that on chip oscillator is ready by a interrupt cosc_ready and by status bit cosc_ready. The cosc_en bit should be changed only when on chip oscillator is not chosen as the clock source.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved
        unsigned WB_COUNT : 3; //!< [18:16] Well Bias counter. Delay, defined by this value, counted by CKIL clock will be applied till well ties are enabled at exit from wait or stop low power mode. Counter will be used if wb_core_at_lpm or wb_per_at_lpm bits are set. Should be zeroed and reconfigured after exit from low power mode.
        unsigned RESERVED2 : 2; //!< [20:19] Reserved
        unsigned REG_BYPASS_COUNT : 6; //!< [26:21] Counter for anatop_reg_bypass signal assertion after standby voltage request by pmic_vstby_req. Should be zeroed and reconfigured after exit from low power mode.
        unsigned RBC_EN : 1; //!< [27] Enable for REG_BYPASS_COUNTER. If enabled, anatop_reg_bypass signal will be asserted after REG_BYPASS_COUNT clocks of CKIL, after standby voltage is requested. If standby voltage is not requested anatop_reg_bypass won't be asserted, event if counter is enabled.
        unsigned RESERVED3 : 4; //!< [31:28] Reserved
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

/* --- Register HW_CCM_CCR, field OSCNT[7:0] (RW)
 *
 * Oscillator ready counter value. These bits define value of 32KHz counter, that serve as counter
 * for oscillator lock time. This is used for oscillator lock time. Current estimation is ~5ms. This
 * counter will be used in ignition sequence and in wake from stop sequence if sbyos bit was
 * defined, to notify that on chip oscillator output is ready for the dpll_ip to use and only then
 * the gate in dpll_ip can be opened.
 *
 * Values:
 * 00000000 - count 1 ckil
 * 11111111 - count 256 ckil's (Default)
 */

#define BP_CCM_CCR_OSCNT      (0)      //!< Bit position for CCM_CCR_OSCNT.
#define BM_CCM_CCR_OSCNT      (0x000000ff)  //!< Bit mask for CCM_CCR_OSCNT.

//! @brief Get value of CCM_CCR_OSCNT from a register value.
#define BG_CCM_CCR_OSCNT(r)   (((r) & BM_CCM_CCR_OSCNT) >> BP_CCM_CCR_OSCNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCR_OSCNT.
#define BF_CCM_CCR_OSCNT(v)   ((((reg32_t) v) << BP_CCM_CCR_OSCNT) & BM_CCM_CCR_OSCNT)
#else
//! @brief Format value for bitfield CCM_CCR_OSCNT.
#define BF_CCM_CCR_OSCNT(v)   (((v) << BP_CCM_CCR_OSCNT) & BM_CCM_CCR_OSCNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSCNT field to a new value.
#define BW_CCM_CCR_OSCNT(v)   (HW_CCM_CCR_WR((HW_CCM_CCR_RD() & ~BM_CCM_CCR_OSCNT) | BF_CCM_CCR_OSCNT(v)))
#endif


/* --- Register HW_CCM_CCR, field COSC_EN[12] (RW)
 *
 * On chip oscillator enable bit - this bit value is reflected on the output cosc_en. The system
 * will start with on chip oscillator enabled to supply source for the PLL's. Software can change
 * this bit if a transition to the bypass PLL clocks was performed for all the PLLs. In cases that
 * this bit is changed from '0' to '1' then CCM will enable the on chip oscillator and after
 * counting oscnt ckil clock cycles it will notify that on chip oscillator is ready by a interrupt
 * cosc_ready and by status bit cosc_ready. The cosc_en bit should be changed only when on chip
 * oscillator is not chosen as the clock source.
 *
 * Values:
 * 0 - disable on chip oscillator
 * 1 - enable on chip oscillator
 */

#define BP_CCM_CCR_COSC_EN      (12)      //!< Bit position for CCM_CCR_COSC_EN.
#define BM_CCM_CCR_COSC_EN      (0x00001000)  //!< Bit mask for CCM_CCR_COSC_EN.

//! @brief Get value of CCM_CCR_COSC_EN from a register value.
#define BG_CCM_CCR_COSC_EN(r)   (((r) & BM_CCM_CCR_COSC_EN) >> BP_CCM_CCR_COSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCR_COSC_EN.
#define BF_CCM_CCR_COSC_EN(v)   ((((reg32_t) v) << BP_CCM_CCR_COSC_EN) & BM_CCM_CCR_COSC_EN)
#else
//! @brief Format value for bitfield CCM_CCR_COSC_EN.
#define BF_CCM_CCR_COSC_EN(v)   (((v) << BP_CCM_CCR_COSC_EN) & BM_CCM_CCR_COSC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COSC_EN field to a new value.
#define BW_CCM_CCR_COSC_EN(v)   (HW_CCM_CCR_WR((HW_CCM_CCR_RD() & ~BM_CCM_CCR_COSC_EN) | BF_CCM_CCR_COSC_EN(v)))
#endif


/* --- Register HW_CCM_CCR, field WB_COUNT[18:16] (RW)
 *
 * Well Bias counter. Delay, defined by this value, counted by CKIL clock will be applied till well
 * ties are enabled at exit from wait or stop low power mode. Counter will be used if wb_core_at_lpm
 * or wb_per_at_lpm bits are set. Should be zeroed and reconfigured after exit from low power mode.
 *
 * Values:
 * 000 - no delay
 * 001 - 1 CKIL clock delay
 * 111 - 7 CKIL clocks delay
 */

#define BP_CCM_CCR_WB_COUNT      (16)      //!< Bit position for CCM_CCR_WB_COUNT.
#define BM_CCM_CCR_WB_COUNT      (0x00070000)  //!< Bit mask for CCM_CCR_WB_COUNT.

//! @brief Get value of CCM_CCR_WB_COUNT from a register value.
#define BG_CCM_CCR_WB_COUNT(r)   (((r) & BM_CCM_CCR_WB_COUNT) >> BP_CCM_CCR_WB_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCR_WB_COUNT.
#define BF_CCM_CCR_WB_COUNT(v)   ((((reg32_t) v) << BP_CCM_CCR_WB_COUNT) & BM_CCM_CCR_WB_COUNT)
#else
//! @brief Format value for bitfield CCM_CCR_WB_COUNT.
#define BF_CCM_CCR_WB_COUNT(v)   (((v) << BP_CCM_CCR_WB_COUNT) & BM_CCM_CCR_WB_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_COUNT field to a new value.
#define BW_CCM_CCR_WB_COUNT(v)   (HW_CCM_CCR_WR((HW_CCM_CCR_RD() & ~BM_CCM_CCR_WB_COUNT) | BF_CCM_CCR_WB_COUNT(v)))
#endif


/* --- Register HW_CCM_CCR, field REG_BYPASS_COUNT[26:21] (RW)
 *
 * Counter for anatop_reg_bypass signal assertion after standby voltage request by pmic_vstby_req.
 * Should be zeroed and reconfigured after exit from low power mode.
 *
 * Values:
 * 000000 - no delay
 * 000001 - 1 CKIL clock period delay
 * 111111 - 63 CKIL clock periods delay
 */

#define BP_CCM_CCR_REG_BYPASS_COUNT      (21)      //!< Bit position for CCM_CCR_REG_BYPASS_COUNT.
#define BM_CCM_CCR_REG_BYPASS_COUNT      (0x07e00000)  //!< Bit mask for CCM_CCR_REG_BYPASS_COUNT.

//! @brief Get value of CCM_CCR_REG_BYPASS_COUNT from a register value.
#define BG_CCM_CCR_REG_BYPASS_COUNT(r)   (((r) & BM_CCM_CCR_REG_BYPASS_COUNT) >> BP_CCM_CCR_REG_BYPASS_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCR_REG_BYPASS_COUNT.
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   ((((reg32_t) v) << BP_CCM_CCR_REG_BYPASS_COUNT) & BM_CCM_CCR_REG_BYPASS_COUNT)
#else
//! @brief Format value for bitfield CCM_CCR_REG_BYPASS_COUNT.
#define BF_CCM_CCR_REG_BYPASS_COUNT(v)   (((v) << BP_CCM_CCR_REG_BYPASS_COUNT) & BM_CCM_CCR_REG_BYPASS_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REG_BYPASS_COUNT field to a new value.
#define BW_CCM_CCR_REG_BYPASS_COUNT(v)   (HW_CCM_CCR_WR((HW_CCM_CCR_RD() & ~BM_CCM_CCR_REG_BYPASS_COUNT) | BF_CCM_CCR_REG_BYPASS_COUNT(v)))
#endif


/* --- Register HW_CCM_CCR, field RBC_EN[27] (RW)
 *
 * Enable for REG_BYPASS_COUNTER. If enabled, anatop_reg_bypass signal will be asserted after
 * REG_BYPASS_COUNT clocks of CKIL, after standby voltage is requested. If standby voltage is not
 * requested anatop_reg_bypass won't be asserted, event if counter is enabled.
 *
 * Values:
 * 0 - REG_BYPASS_COUNTER disabled
 * 1 - REG_BYPASS_COUNTER enabled.
 */

#define BP_CCM_CCR_RBC_EN      (27)      //!< Bit position for CCM_CCR_RBC_EN.
#define BM_CCM_CCR_RBC_EN      (0x08000000)  //!< Bit mask for CCM_CCR_RBC_EN.

//! @brief Get value of CCM_CCR_RBC_EN from a register value.
#define BG_CCM_CCR_RBC_EN(r)   (((r) & BM_CCM_CCR_RBC_EN) >> BP_CCM_CCR_RBC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCR_RBC_EN.
#define BF_CCM_CCR_RBC_EN(v)   ((((reg32_t) v) << BP_CCM_CCR_RBC_EN) & BM_CCM_CCR_RBC_EN)
#else
//! @brief Format value for bitfield CCM_CCR_RBC_EN.
#define BF_CCM_CCR_RBC_EN(v)   (((v) << BP_CCM_CCR_RBC_EN) & BM_CCM_CCR_RBC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RBC_EN field to a new value.
#define BW_CCM_CCR_RBC_EN(v)   (HW_CCM_CCR_WR((HW_CCM_CCR_RD() & ~BM_CCM_CCR_RBC_EN) | BF_CCM_CCR_RBC_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCDR - CCM Control Divider Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Control Divider Register (CCDR), which contains bits that
 * control the loading of the dividers that need handshake with the modules they affect. The table
 * below provides its field descriptions.
 */
typedef union _hw_ccm_ccdr
{
    reg32_t U;
    struct _hw_ccm_ccdr_bitfields
    {
        unsigned RESERVED0 : 16; //!< [15:0] Reserved
        unsigned MMDC_CH1_MASK : 1; //!< [16] During divider ratio mmdc_ch1_axi_podf change or sync mux periph2_clk_sel change (but not jtag) or SRC request during warm reset, mask handshake with mmdc_ch1 module.
        unsigned MMDC_CH0_MASK : 1; //!< [17] During divider ratio mmdc_ch0_axi_podf change or sync mux periph_clk_sel change (but not jtag) or SRC request during warm reset, mask handshake with mmdc_ch0 module.
        unsigned RESERVED1 : 14; //!< [31:18] Reserved
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

/* --- Register HW_CCM_CCDR, field MMDC_CH1_MASK[16] (RW)
 *
 * During divider ratio mmdc_ch1_axi_podf change or sync mux periph2_clk_sel change (but not jtag)
 * or SRC request during warm reset, mask handshake with mmdc_ch1 module.
 *
 * Values:
 * 0 - allow handshake with mmdc_ch1 module
 * 1 - mask handshake with mmdc_ch1. Request signal will not be generated.
 */

#define BP_CCM_CCDR_MMDC_CH1_MASK      (16)      //!< Bit position for CCM_CCDR_MMDC_CH1_MASK.
#define BM_CCM_CCDR_MMDC_CH1_MASK      (0x00010000)  //!< Bit mask for CCM_CCDR_MMDC_CH1_MASK.

//! @brief Get value of CCM_CCDR_MMDC_CH1_MASK from a register value.
#define BG_CCM_CCDR_MMDC_CH1_MASK(r)   (((r) & BM_CCM_CCDR_MMDC_CH1_MASK) >> BP_CCM_CCDR_MMDC_CH1_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCDR_MMDC_CH1_MASK.
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   ((((reg32_t) v) << BP_CCM_CCDR_MMDC_CH1_MASK) & BM_CCM_CCDR_MMDC_CH1_MASK)
#else
//! @brief Format value for bitfield CCM_CCDR_MMDC_CH1_MASK.
#define BF_CCM_CCDR_MMDC_CH1_MASK(v)   (((v) << BP_CCM_CCDR_MMDC_CH1_MASK) & BM_CCM_CCDR_MMDC_CH1_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH1_MASK field to a new value.
#define BW_CCM_CCDR_MMDC_CH1_MASK(v)   (HW_CCM_CCDR_WR((HW_CCM_CCDR_RD() & ~BM_CCM_CCDR_MMDC_CH1_MASK) | BF_CCM_CCDR_MMDC_CH1_MASK(v)))
#endif


/* --- Register HW_CCM_CCDR, field MMDC_CH0_MASK[17] (RW)
 *
 * During divider ratio mmdc_ch0_axi_podf change or sync mux periph_clk_sel change (but not jtag) or
 * SRC request during warm reset, mask handshake with mmdc_ch0 module.
 *
 * Values:
 * 0 - allow handshake with mmdc_ch0 module
 * 1 - mask handshake with mmdc_ch0. Request signal will not be generated.
 */

#define BP_CCM_CCDR_MMDC_CH0_MASK      (17)      //!< Bit position for CCM_CCDR_MMDC_CH0_MASK.
#define BM_CCM_CCDR_MMDC_CH0_MASK      (0x00020000)  //!< Bit mask for CCM_CCDR_MMDC_CH0_MASK.

//! @brief Get value of CCM_CCDR_MMDC_CH0_MASK from a register value.
#define BG_CCM_CCDR_MMDC_CH0_MASK(r)   (((r) & BM_CCM_CCDR_MMDC_CH0_MASK) >> BP_CCM_CCDR_MMDC_CH0_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCDR_MMDC_CH0_MASK.
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   ((((reg32_t) v) << BP_CCM_CCDR_MMDC_CH0_MASK) & BM_CCM_CCDR_MMDC_CH0_MASK)
#else
//! @brief Format value for bitfield CCM_CCDR_MMDC_CH0_MASK.
#define BF_CCM_CCDR_MMDC_CH0_MASK(v)   (((v) << BP_CCM_CCDR_MMDC_CH0_MASK) & BM_CCM_CCDR_MMDC_CH0_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH0_MASK field to a new value.
#define BW_CCM_CCDR_MMDC_CH0_MASK(v)   (HW_CCM_CCDR_WR((HW_CCM_CCDR_RD() & ~BM_CCM_CCDR_MMDC_CH0_MASK) | BF_CCM_CCDR_MMDC_CH0_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSR - CCM Status Register (RO)
 *
 * Reset value: 0x00000010
 *
 * The figure below represents the CCM status Register (CSR). The status bits are read only bits.
 * The table below provides its field descriptions.
 */
typedef union _hw_ccm_csr
{
    reg32_t U;
    struct _hw_ccm_csr_bitfields
    {
        unsigned REF_EN_B : 1; //!< [0] Status of the value of ref_en_b output of ccm
        unsigned RESERVED0 : 4; //!< [4:1] Reserved.
        unsigned COSC_READY : 1; //!< [5] Status indication of on board oscillator. This bit will be asserted if on chip oscillator is enabled and on chip oscillator is not powered down, and if oscnt counter has finished counting.
        unsigned RESERVED1 : 26; //!< [31:6] Reserved
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
#endif

/*
 * constants & macros for individual CCM_CSR bitfields
 */

/* --- Register HW_CCM_CSR, field REF_EN_B[0] (RO)
 *
 * Status of the value of ref_en_b output of ccm
 *
 * Values:
 * 0 - value of ref_en_b is '0'
 * 1 - value of ref_en_b is '1'
 */

#define BP_CCM_CSR_REF_EN_B      (0)      //!< Bit position for CCM_CSR_REF_EN_B.
#define BM_CCM_CSR_REF_EN_B      (0x00000001)  //!< Bit mask for CCM_CSR_REF_EN_B.

//! @brief Get value of CCM_CSR_REF_EN_B from a register value.
#define BG_CCM_CSR_REF_EN_B(r)   (((r) & BM_CCM_CSR_REF_EN_B) >> BP_CCM_CSR_REF_EN_B)


/* --- Register HW_CCM_CSR, field COSC_READY[5] (RO)
 *
 * Status indication of on board oscillator. This bit will be asserted if on chip oscillator is
 * enabled and on chip oscillator is not powered down, and if oscnt counter has finished counting.
 *
 * Values:
 * 0 - on board oscillator is not ready.
 * 1 - on board oscillator is ready.
 */

#define BP_CCM_CSR_COSC_READY      (5)      //!< Bit position for CCM_CSR_COSC_READY.
#define BM_CCM_CSR_COSC_READY      (0x00000020)  //!< Bit mask for CCM_CSR_COSC_READY.

//! @brief Get value of CCM_CSR_COSC_READY from a register value.
#define BG_CCM_CSR_COSC_READY(r)   (((r) & BM_CCM_CSR_COSC_READY) >> BP_CCM_CSR_COSC_READY)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCSR - CCM Clock Swither Register (RW)
 *
 * Reset value: 0x00000100
 *
 * The figure below represents the CCM Clock Switcher register (CCSR). The CCSR register contains
 * bits to control the switcher sub module dividers and multiplexers. The table below provides its
 * field descriptions.
 */
typedef union _hw_ccm_ccsr
{
    reg32_t U;
    struct _hw_ccm_ccsr_bitfields
    {
        unsigned PLL3_SW_CLK_SEL : 1; //!< [0] Selects source to generate pll3_sw_clk. This bit should only be used for testing purposes. Note: this bit will be ored with pll_bypass_en3 signal. If one of the sources requests to move to pll3 bypass clk (pll3_sw_clk=1 or pll_bypass_en3=1) then the pll3_sw_clk will be pll3 bypass clk. Only if both sources request pll3_main_clk (pll3_sw_clk=0 and pll_bypass_en3=0) then the pll3_sw_clk will be pll3_main_clk.
        unsigned PLL2_SW_CLK_SEL : 1; //!< [1] Selects source to generate pll2_sw_clk. This bit should only be used for testing purposes. Note: this bit will be ored with pll_bypass_en2 signal. If one of the sources requests to move to pll2 bypass clk (pll2_sw_clk=1 or pll_bypass_en2=1) then the pll2_sw_clk will be pll2 bypass clk. Only if both sources request pll2_main_clk (pll2_sw_clk=0 and pll_bypass_en2=0) then the pll2_sw_clk will be pll2_main_clk.
        unsigned PLL1_SW_CLK_SEL : 1; //!< [2] Selects source to generate pll1_sw_clk. Note: this bit will be ored with pll_bypass_en1 signal and dvfs_control signal. If one of the sources requests to move to step_clk (pll1_sw_clk=1 or pll_bypass_en1=1 or dvfs_control=1) then the pll1_sw_clk will be step_clk. Only if both sources request pll1_main_clk (pll1_sw_clk=0 and pll_bypass_en1=0 and dvfs_control=0) then the pll1_sw_clk will be pll1_main_clk.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved
        unsigned STEP_SEL : 1; //!< [8] Selects the option to be chosen for the step frequency when shifting ARM frequency. this will control the step_clk. Note: this mux is allowed to be changed only if its output is not used, i.e. ARM uses the output of pll1, and step_clk is not used.
        unsigned PDF_396M_DIS_MASK : 1; //!< [9] Mask of 396M PFD auto-disable.
        unsigned PDF_352M_DIS_MASK : 1; //!< [10] Mask of 352M PFD auto-disable.
        unsigned PDF_594M_DIS_MASK : 1; //!< [11] Mask of 594M PFD auto-disable.
        unsigned PDF_508M_DIS_MASK : 1; //!< [12] Mask of 508M PFD auto-disable.
        unsigned PDF_454M_DIS_MASK : 1; //!< [13] Mask of 454M PFD auto-disable.
        unsigned PDF_720M_DIS_MASK : 1; //!< [14] Mask of 720M PFD auto-disable.
        unsigned PDF_540M_DIS_MASK : 1; //!< [15] Mask of 540M PFD auto-disable.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
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

/* --- Register HW_CCM_CCSR, field PLL3_SW_CLK_SEL[0] (RW)
 *
 * Selects source to generate pll3_sw_clk. This bit should only be used for testing purposes. Note:
 * this bit will be ored with pll_bypass_en3 signal. If one of the sources requests to move to pll3
 * bypass clk (pll3_sw_clk=1 or pll_bypass_en3=1) then the pll3_sw_clk will be pll3 bypass clk. Only
 * if both sources request pll3_main_clk (pll3_sw_clk=0 and pll_bypass_en3=0) then the pll3_sw_clk
 * will be pll3_main_clk.
 *
 * Values:
 * 0 - pll3_main_clk(Default)
 * 1 - pll3 bypass clock
 */

#define BP_CCM_CCSR_PLL3_SW_CLK_SEL      (0)      //!< Bit position for CCM_CCSR_PLL3_SW_CLK_SEL.
#define BM_CCM_CCSR_PLL3_SW_CLK_SEL      (0x00000001)  //!< Bit mask for CCM_CCSR_PLL3_SW_CLK_SEL.

//! @brief Get value of CCM_CCSR_PLL3_SW_CLK_SEL from a register value.
#define BG_CCM_CCSR_PLL3_SW_CLK_SEL(r)   (((r) & BM_CCM_CCSR_PLL3_SW_CLK_SEL) >> BP_CCM_CCSR_PLL3_SW_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PLL3_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CCSR_PLL3_SW_CLK_SEL) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CCSR_PLL3_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)   (((v) << BP_CCM_CCSR_PLL3_SW_CLK_SEL) & BM_CCM_CCSR_PLL3_SW_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL3_SW_CLK_SEL field to a new value.
#define BW_CCM_CCSR_PLL3_SW_CLK_SEL(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PLL3_SW_CLK_SEL) | BF_CCM_CCSR_PLL3_SW_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CCSR, field PLL2_SW_CLK_SEL[1] (RW)
 *
 * Selects source to generate pll2_sw_clk. This bit should only be used for testing purposes. Note:
 * this bit will be ored with pll_bypass_en2 signal. If one of the sources requests to move to pll2
 * bypass clk (pll2_sw_clk=1 or pll_bypass_en2=1) then the pll2_sw_clk will be pll2 bypass clk. Only
 * if both sources request pll2_main_clk (pll2_sw_clk=0 and pll_bypass_en2=0) then the pll2_sw_clk
 * will be pll2_main_clk.
 *
 * Values:
 * 0 - pll2_main_clk(Default)
 * 1 - pll2 bypass clock
 */

#define BP_CCM_CCSR_PLL2_SW_CLK_SEL      (1)      //!< Bit position for CCM_CCSR_PLL2_SW_CLK_SEL.
#define BM_CCM_CCSR_PLL2_SW_CLK_SEL      (0x00000002)  //!< Bit mask for CCM_CCSR_PLL2_SW_CLK_SEL.

//! @brief Get value of CCM_CCSR_PLL2_SW_CLK_SEL from a register value.
#define BG_CCM_CCSR_PLL2_SW_CLK_SEL(r)   (((r) & BM_CCM_CCSR_PLL2_SW_CLK_SEL) >> BP_CCM_CCSR_PLL2_SW_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PLL2_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CCSR_PLL2_SW_CLK_SEL) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CCSR_PLL2_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)   (((v) << BP_CCM_CCSR_PLL2_SW_CLK_SEL) & BM_CCM_CCSR_PLL2_SW_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL2_SW_CLK_SEL field to a new value.
#define BW_CCM_CCSR_PLL2_SW_CLK_SEL(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PLL2_SW_CLK_SEL) | BF_CCM_CCSR_PLL2_SW_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CCSR, field PLL1_SW_CLK_SEL[2] (RW)
 *
 * Selects source to generate pll1_sw_clk. Note: this bit will be ored with pll_bypass_en1 signal
 * and dvfs_control signal. If one of the sources requests to move to step_clk (pll1_sw_clk=1 or
 * pll_bypass_en1=1 or dvfs_control=1) then the pll1_sw_clk will be step_clk. Only if both sources
 * request pll1_main_clk (pll1_sw_clk=0 and pll_bypass_en1=0 and dvfs_control=0) then the
 * pll1_sw_clk will be pll1_main_clk.
 *
 * Values:
 * 0 - pll1_main_clk(Default)
 * 1 - step_clk
 */

#define BP_CCM_CCSR_PLL1_SW_CLK_SEL      (2)      //!< Bit position for CCM_CCSR_PLL1_SW_CLK_SEL.
#define BM_CCM_CCSR_PLL1_SW_CLK_SEL      (0x00000004)  //!< Bit mask for CCM_CCSR_PLL1_SW_CLK_SEL.

//! @brief Get value of CCM_CCSR_PLL1_SW_CLK_SEL from a register value.
#define BG_CCM_CCSR_PLL1_SW_CLK_SEL(r)   (((r) & BM_CCM_CCSR_PLL1_SW_CLK_SEL) >> BP_CCM_CCSR_PLL1_SW_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PLL1_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CCSR_PLL1_SW_CLK_SEL) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CCSR_PLL1_SW_CLK_SEL.
#define BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)   (((v) << BP_CCM_CCSR_PLL1_SW_CLK_SEL) & BM_CCM_CCSR_PLL1_SW_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL1_SW_CLK_SEL field to a new value.
#define BW_CCM_CCSR_PLL1_SW_CLK_SEL(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PLL1_SW_CLK_SEL) | BF_CCM_CCSR_PLL1_SW_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CCSR, field STEP_SEL[8] (RW)
 *
 * Selects the option to be chosen for the step frequency when shifting ARM frequency. this will
 * control the step_clk. Note: this mux is allowed to be changed only if its output is not used,
 * i.e. ARM uses the output of pll1, and step_clk is not used.
 *
 * Values:
 * 0 - clock source 4 - source for lp_apm. (Default)
 * 1 - pll2 PDF clock
 */

#define BP_CCM_CCSR_STEP_SEL      (8)      //!< Bit position for CCM_CCSR_STEP_SEL.
#define BM_CCM_CCSR_STEP_SEL      (0x00000100)  //!< Bit mask for CCM_CCSR_STEP_SEL.

//! @brief Get value of CCM_CCSR_STEP_SEL from a register value.
#define BG_CCM_CCSR_STEP_SEL(r)   (((r) & BM_CCM_CCSR_STEP_SEL) >> BP_CCM_CCSR_STEP_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_STEP_SEL.
#define BF_CCM_CCSR_STEP_SEL(v)   ((((reg32_t) v) << BP_CCM_CCSR_STEP_SEL) & BM_CCM_CCSR_STEP_SEL)
#else
//! @brief Format value for bitfield CCM_CCSR_STEP_SEL.
#define BF_CCM_CCSR_STEP_SEL(v)   (((v) << BP_CCM_CCSR_STEP_SEL) & BM_CCM_CCSR_STEP_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STEP_SEL field to a new value.
#define BW_CCM_CCSR_STEP_SEL(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_STEP_SEL) | BF_CCM_CCSR_STEP_SEL(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_396M_DIS_MASK[9] (RW)
 *
 * Mask of 396M PFD auto-disable.
 *
 * Values:
 * 0 - 396M PFD disable=0 (PFD always on)
 * 1 - 396M PFD disable is managed by associated dividers disable. If all 396M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_396M_DIS_MASK      (9)      //!< Bit position for CCM_CCSR_PDF_396M_DIS_MASK.
#define BM_CCM_CCSR_PDF_396M_DIS_MASK      (0x00000200)  //!< Bit mask for CCM_CCSR_PDF_396M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_396M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_396M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_396M_DIS_MASK) >> BP_CCM_CCSR_PDF_396M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_396M_DIS_MASK.
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_396M_DIS_MASK) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_396M_DIS_MASK.
#define BF_CCM_CCSR_PDF_396M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_396M_DIS_MASK) & BM_CCM_CCSR_PDF_396M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_396M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_396M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_396M_DIS_MASK) | BF_CCM_CCSR_PDF_396M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_352M_DIS_MASK[10] (RW)
 *
 * Mask of 352M PFD auto-disable.
 *
 * Values:
 * 0 - 352M PFD disable=0 (PFD always on)
 * 1 - 352M PFD disable is managed by associated dividers disable. If all 352M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_352M_DIS_MASK      (10)      //!< Bit position for CCM_CCSR_PDF_352M_DIS_MASK.
#define BM_CCM_CCSR_PDF_352M_DIS_MASK      (0x00000400)  //!< Bit mask for CCM_CCSR_PDF_352M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_352M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_352M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_352M_DIS_MASK) >> BP_CCM_CCSR_PDF_352M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_352M_DIS_MASK.
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_352M_DIS_MASK) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_352M_DIS_MASK.
#define BF_CCM_CCSR_PDF_352M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_352M_DIS_MASK) & BM_CCM_CCSR_PDF_352M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_352M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_352M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_352M_DIS_MASK) | BF_CCM_CCSR_PDF_352M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_594M_DIS_MASK[11] (RW)
 *
 * Mask of 594M PFD auto-disable.
 *
 * Values:
 * 0 - 594M PFD disable=0 (PFD always on)
 * 1 - 594M PFD disable is managed by associated dividers disable. If all 594M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_594M_DIS_MASK      (11)      //!< Bit position for CCM_CCSR_PDF_594M_DIS_MASK.
#define BM_CCM_CCSR_PDF_594M_DIS_MASK      (0x00000800)  //!< Bit mask for CCM_CCSR_PDF_594M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_594M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_594M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_594M_DIS_MASK) >> BP_CCM_CCSR_PDF_594M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_594M_DIS_MASK.
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_594M_DIS_MASK) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_594M_DIS_MASK.
#define BF_CCM_CCSR_PDF_594M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_594M_DIS_MASK) & BM_CCM_CCSR_PDF_594M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_594M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_594M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_594M_DIS_MASK) | BF_CCM_CCSR_PDF_594M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_508M_DIS_MASK[12] (RW)
 *
 * Mask of 508M PFD auto-disable.
 *
 * Values:
 * 0 - 508M PFD disable=0 (PFD always on)
 * 1 - 508M PFD disable is managed by associated dividers disable. If all 508M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_508M_DIS_MASK      (12)      //!< Bit position for CCM_CCSR_PDF_508M_DIS_MASK.
#define BM_CCM_CCSR_PDF_508M_DIS_MASK      (0x00001000)  //!< Bit mask for CCM_CCSR_PDF_508M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_508M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_508M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_508M_DIS_MASK) >> BP_CCM_CCSR_PDF_508M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_508M_DIS_MASK.
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_508M_DIS_MASK) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_508M_DIS_MASK.
#define BF_CCM_CCSR_PDF_508M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_508M_DIS_MASK) & BM_CCM_CCSR_PDF_508M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_508M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_508M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_508M_DIS_MASK) | BF_CCM_CCSR_PDF_508M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_454M_DIS_MASK[13] (RW)
 *
 * Mask of 454M PFD auto-disable.
 *
 * Values:
 * 0 - 454M PFD disable=0 (PFD always on)
 * 1 - 454M PFD disable is managed by associated dividers disable. If all 454M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_454M_DIS_MASK      (13)      //!< Bit position for CCM_CCSR_PDF_454M_DIS_MASK.
#define BM_CCM_CCSR_PDF_454M_DIS_MASK      (0x00002000)  //!< Bit mask for CCM_CCSR_PDF_454M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_454M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_454M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_454M_DIS_MASK) >> BP_CCM_CCSR_PDF_454M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_454M_DIS_MASK.
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_454M_DIS_MASK) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_454M_DIS_MASK.
#define BF_CCM_CCSR_PDF_454M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_454M_DIS_MASK) & BM_CCM_CCSR_PDF_454M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_454M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_454M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_454M_DIS_MASK) | BF_CCM_CCSR_PDF_454M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_720M_DIS_MASK[14] (RW)
 *
 * Mask of 720M PFD auto-disable.
 *
 * Values:
 * 0 - 720M PFD disable=0 (PFD always on)
 * 1 - 720M PFD disable is managed by associated dividers disable. If all 720M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_720M_DIS_MASK      (14)      //!< Bit position for CCM_CCSR_PDF_720M_DIS_MASK.
#define BM_CCM_CCSR_PDF_720M_DIS_MASK      (0x00004000)  //!< Bit mask for CCM_CCSR_PDF_720M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_720M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_720M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_720M_DIS_MASK) >> BP_CCM_CCSR_PDF_720M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_720M_DIS_MASK.
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_720M_DIS_MASK) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_720M_DIS_MASK.
#define BF_CCM_CCSR_PDF_720M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_720M_DIS_MASK) & BM_CCM_CCSR_PDF_720M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_720M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_720M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_720M_DIS_MASK) | BF_CCM_CCSR_PDF_720M_DIS_MASK(v)))
#endif


/* --- Register HW_CCM_CCSR, field PDF_540M_DIS_MASK[15] (RW)
 *
 * Mask of 540M PFD auto-disable.
 *
 * Values:
 * 0 - - 540M PFD disable=0 (PFD always on)
 * 1 - 540M PFD disable is managed by associated dividers disable. If all 540M-driven dividers are closed,
 *     PDF is disabled.
 */

#define BP_CCM_CCSR_PDF_540M_DIS_MASK      (15)      //!< Bit position for CCM_CCSR_PDF_540M_DIS_MASK.
#define BM_CCM_CCSR_PDF_540M_DIS_MASK      (0x00008000)  //!< Bit mask for CCM_CCSR_PDF_540M_DIS_MASK.

//! @brief Get value of CCM_CCSR_PDF_540M_DIS_MASK from a register value.
#define BG_CCM_CCSR_PDF_540M_DIS_MASK(r)   (((r) & BM_CCM_CCSR_PDF_540M_DIS_MASK) >> BP_CCM_CCSR_PDF_540M_DIS_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCSR_PDF_540M_DIS_MASK.
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   ((((reg32_t) v) << BP_CCM_CCSR_PDF_540M_DIS_MASK) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#else
//! @brief Format value for bitfield CCM_CCSR_PDF_540M_DIS_MASK.
#define BF_CCM_CCSR_PDF_540M_DIS_MASK(v)   (((v) << BP_CCM_CCSR_PDF_540M_DIS_MASK) & BM_CCM_CCSR_PDF_540M_DIS_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDF_540M_DIS_MASK field to a new value.
#define BW_CCM_CCSR_PDF_540M_DIS_MASK(v)   (HW_CCM_CCSR_WR((HW_CCM_CCSR_RD() & ~BM_CCM_CCSR_PDF_540M_DIS_MASK) | BF_CCM_CCSR_PDF_540M_DIS_MASK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CACRR - CCM Arm Clock Root Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Arm Clock Root register (CACRR). The CACRR register contains
 * bits to control the ARM clock root generation. The table below provides its field descriptions.
 */
typedef union _hw_ccm_cacrr
{
    reg32_t U;
    struct _hw_ccm_cacrr_bitfields
    {
        unsigned ARM_PODF : 3; //!< [2:0] Divider for ARM clock root. Note: if arm_freq_shift_divider is set to '1' then any new write to arm_podf will be held until arm_clk_switch_req signal is asserted.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
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

/* --- Register HW_CCM_CACRR, field ARM_PODF[2:0] (RW)
 *
 * Divider for ARM clock root. Note: if arm_freq_shift_divider is set to '1' then any new write to
 * arm_podf will be held until arm_clk_switch_req signal is asserted.
 *
 * Values:
 * 000 - divide by 1(Default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CACRR_ARM_PODF      (0)      //!< Bit position for CCM_CACRR_ARM_PODF.
#define BM_CCM_CACRR_ARM_PODF      (0x00000007)  //!< Bit mask for CCM_CACRR_ARM_PODF.

//! @brief Get value of CCM_CACRR_ARM_PODF from a register value.
#define BG_CCM_CACRR_ARM_PODF(r)   (((r) & BM_CCM_CACRR_ARM_PODF) >> BP_CCM_CACRR_ARM_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CACRR_ARM_PODF.
#define BF_CCM_CACRR_ARM_PODF(v)   ((((reg32_t) v) << BP_CCM_CACRR_ARM_PODF) & BM_CCM_CACRR_ARM_PODF)
#else
//! @brief Format value for bitfield CCM_CACRR_ARM_PODF.
#define BF_CCM_CACRR_ARM_PODF(v)   (((v) << BP_CCM_CACRR_ARM_PODF) & BM_CCM_CACRR_ARM_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARM_PODF field to a new value.
#define BW_CCM_CACRR_ARM_PODF(v)   (HW_CCM_CACRR_WR((HW_CCM_CACRR_RD() & ~BM_CCM_CACRR_ARM_PODF) | BF_CCM_CACRR_ARM_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CBCDR - CCM Bus Clock Divider Register (RW)
 *
 * Reset value: 0x00018d40
 *
 * The figure below represents the CCM Bus Clock Divider Register (CBCDR). The CBCDR register
 * contains bits to control the clock generation sub module dividers. The table below provides its
 * field descriptions.
 */
typedef union _hw_ccm_cbcdr
{
    reg32_t U;
    struct _hw_ccm_cbcdr_bitfields
    {
        unsigned PERIPH2_CLK2_PODF : 3; //!< [2:0] Divider for periph2_clk2 podf. Note: Divider should be updated when output clock is gated.
        unsigned MMDC_CH1_AXI_PODF : 3; //!< [5:3] Divider for mmdc_ch1_axi podf. Note: This design implementation does not use MMDC_CH1_AXI_CLK_ROOT as a clock source to the MMDC. Only MMDC_CH0_AXI_CLK_ROOT is used.
        unsigned AXI_SEL : 1; //!< [6] AXI clock source select
        unsigned AXI_ALT_SEL : 1; //!< [7] AXI alternative clock select
        unsigned IPG_PODF : 2; //!< [9:8] Divider for ipg podf. Note: IEEE_RTC module will not support ratio of 1:3 for ahb_clk:ipg_clk. In case IEEE_RTC is used, then those ratios should not be used. Note: SDMA module will not support ratio of 1:3 and 1:4 for ahb_clk:ipg_clk. In case SDMA is used, then those ratios should not be used.
        unsigned AHB_PODF : 3; //!< [12:10] Divider for ahb podf. Note: any change of this divider might involve handshake with EMI and IPU. See CDHIPR register for the handshake busy bits.
        unsigned RESERVED0 : 3; //!< [15:13] Reserved
        unsigned AXI_PODF : 3; //!< [18:16] Divider for axi podf. Note: any change of this divider might involve handshake with EMI and IPU. See CDHIPR register for the handshake busy bits.
        unsigned MMDC_CH0_AXI_PODF : 3; //!< [21:19] Divider for mmdc_ch0_axi podf.
        unsigned RESERVED1 : 3; //!< [24:22] Reserved
        unsigned PERIPH_CLK_SEL : 1; //!< [25] Selector for peripheral main clock (source of mmdc_ch0_axi_clk_root). Note: alternative clock source should be used when PLL is relocked. For PLL relock procedure pls refer PLL chapter
        unsigned PERIPH2_CLK_SEL : 1; //!< [26] Selector for peripheral2 main clock (source of mmdc_ch1_axi_clk_root mmdc_root_axi_clk_root ).
        unsigned PERIPH_CLK2_PODF : 3; //!< [29:27] Divider for periph2 clock podf.
        unsigned RESERVED2 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK2_PODF[2:0] (RW)
 *
 * Divider for periph2_clk2 podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_PERIPH2_CLK2_PODF      (0)      //!< Bit position for CCM_CBCDR_PERIPH2_CLK2_PODF.
#define BM_CCM_CBCDR_PERIPH2_CLK2_PODF      (0x00000007)  //!< Bit mask for CCM_CBCDR_PERIPH2_CLK2_PODF.

//! @brief Get value of CCM_CBCDR_PERIPH2_CLK2_PODF from a register value.
#define BG_CCM_CBCDR_PERIPH2_CLK2_PODF(r)   (((r) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF) >> BP_CCM_CBCDR_PERIPH2_CLK2_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_PERIPH2_CLK2_PODF.
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_PERIPH2_CLK2_PODF) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_PERIPH2_CLK2_PODF.
#define BF_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   (((v) << BP_CCM_CBCDR_PERIPH2_CLK2_PODF) & BM_CCM_CBCDR_PERIPH2_CLK2_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH2_CLK2_PODF field to a new value.
#define BW_CCM_CBCDR_PERIPH2_CLK2_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_PERIPH2_CLK2_PODF) | BF_CCM_CBCDR_PERIPH2_CLK2_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field MMDC_CH1_AXI_PODF[5:3] (RW)
 *
 * Divider for mmdc_ch1_axi podf. Note: This design implementation does not use
 * MMDC_CH1_AXI_CLK_ROOT as a clock source to the MMDC. Only MMDC_CH0_AXI_CLK_ROOT is used.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_MMDC_CH1_AXI_PODF      (3)      //!< Bit position for CCM_CBCDR_MMDC_CH1_AXI_PODF.
#define BM_CCM_CBCDR_MMDC_CH1_AXI_PODF      (0x00000038)  //!< Bit mask for CCM_CBCDR_MMDC_CH1_AXI_PODF.

//! @brief Get value of CCM_CBCDR_MMDC_CH1_AXI_PODF from a register value.
#define BG_CCM_CBCDR_MMDC_CH1_AXI_PODF(r)   (((r) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF) >> BP_CCM_CBCDR_MMDC_CH1_AXI_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_MMDC_CH1_AXI_PODF.
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_MMDC_CH1_AXI_PODF) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_MMDC_CH1_AXI_PODF.
#define BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   (((v) << BP_CCM_CBCDR_MMDC_CH1_AXI_PODF) & BM_CCM_CBCDR_MMDC_CH1_AXI_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH1_AXI_PODF field to a new value.
#define BW_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_MMDC_CH1_AXI_PODF) | BF_CCM_CBCDR_MMDC_CH1_AXI_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field AXI_SEL[6] (RW)
 *
 * AXI clock source select
 *
 * Values:
 * 0 - Periph_clk output will be used as AXI clock root
 * 1 - AXI alternative clock will be used as AXI clock root
 */

#define BP_CCM_CBCDR_AXI_SEL      (6)      //!< Bit position for CCM_CBCDR_AXI_SEL.
#define BM_CCM_CBCDR_AXI_SEL      (0x00000040)  //!< Bit mask for CCM_CBCDR_AXI_SEL.

//! @brief Get value of CCM_CBCDR_AXI_SEL from a register value.
#define BG_CCM_CBCDR_AXI_SEL(r)   (((r) & BM_CCM_CBCDR_AXI_SEL) >> BP_CCM_CBCDR_AXI_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_AXI_SEL.
#define BF_CCM_CBCDR_AXI_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCDR_AXI_SEL) & BM_CCM_CBCDR_AXI_SEL)
#else
//! @brief Format value for bitfield CCM_CBCDR_AXI_SEL.
#define BF_CCM_CBCDR_AXI_SEL(v)   (((v) << BP_CCM_CBCDR_AXI_SEL) & BM_CCM_CBCDR_AXI_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_SEL field to a new value.
#define BW_CCM_CBCDR_AXI_SEL(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_AXI_SEL) | BF_CCM_CBCDR_AXI_SEL(v)))
#endif


/* --- Register HW_CCM_CBCDR, field AXI_ALT_SEL[7] (RW)
 *
 * AXI alternative clock select
 *
 * Values:
 * 0 - pll2 396MHz PFD will be selected as alternative clock for AXI root clock
 * 1 - pll3 540MHz PFD will be selected as alternative clock for AXI root clock
 */

#define BP_CCM_CBCDR_AXI_ALT_SEL      (7)      //!< Bit position for CCM_CBCDR_AXI_ALT_SEL.
#define BM_CCM_CBCDR_AXI_ALT_SEL      (0x00000080)  //!< Bit mask for CCM_CBCDR_AXI_ALT_SEL.

//! @brief Get value of CCM_CBCDR_AXI_ALT_SEL from a register value.
#define BG_CCM_CBCDR_AXI_ALT_SEL(r)   (((r) & BM_CCM_CBCDR_AXI_ALT_SEL) >> BP_CCM_CBCDR_AXI_ALT_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_AXI_ALT_SEL.
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCDR_AXI_ALT_SEL) & BM_CCM_CBCDR_AXI_ALT_SEL)
#else
//! @brief Format value for bitfield CCM_CBCDR_AXI_ALT_SEL.
#define BF_CCM_CBCDR_AXI_ALT_SEL(v)   (((v) << BP_CCM_CBCDR_AXI_ALT_SEL) & BM_CCM_CBCDR_AXI_ALT_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_ALT_SEL field to a new value.
#define BW_CCM_CBCDR_AXI_ALT_SEL(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_AXI_ALT_SEL) | BF_CCM_CBCDR_AXI_ALT_SEL(v)))
#endif


/* --- Register HW_CCM_CBCDR, field IPG_PODF[9:8] (RW)
 *
 * Divider for ipg podf. Note: IEEE_RTC module will not support ratio of 1:3 for ahb_clk:ipg_clk. In
 * case IEEE_RTC is used, then those ratios should not be used. Note: SDMA module will not support
 * ratio of 1:3 and 1:4 for ahb_clk:ipg_clk. In case SDMA is used, then those ratios should not be
 * used.
 *
 * Values:
 * 00 - divide by 1
 * 01 - divide by 2 (Default)
 * 10 - divide by 3
 * 11 - divide by 4
 */

#define BP_CCM_CBCDR_IPG_PODF      (8)      //!< Bit position for CCM_CBCDR_IPG_PODF.
#define BM_CCM_CBCDR_IPG_PODF      (0x00000300)  //!< Bit mask for CCM_CBCDR_IPG_PODF.

//! @brief Get value of CCM_CBCDR_IPG_PODF from a register value.
#define BG_CCM_CBCDR_IPG_PODF(r)   (((r) & BM_CCM_CBCDR_IPG_PODF) >> BP_CCM_CBCDR_IPG_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_IPG_PODF.
#define BF_CCM_CBCDR_IPG_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_IPG_PODF) & BM_CCM_CBCDR_IPG_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_IPG_PODF.
#define BF_CCM_CBCDR_IPG_PODF(v)   (((v) << BP_CCM_CBCDR_IPG_PODF) & BM_CCM_CBCDR_IPG_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPG_PODF field to a new value.
#define BW_CCM_CBCDR_IPG_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_IPG_PODF) | BF_CCM_CBCDR_IPG_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field AHB_PODF[12:10] (RW)
 *
 * Divider for ahb podf. Note: any change of this divider might involve handshake with EMI and IPU.
 * See CDHIPR register for the handshake busy bits.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4 (Default)
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_AHB_PODF      (10)      //!< Bit position for CCM_CBCDR_AHB_PODF.
#define BM_CCM_CBCDR_AHB_PODF      (0x00001c00)  //!< Bit mask for CCM_CBCDR_AHB_PODF.

//! @brief Get value of CCM_CBCDR_AHB_PODF from a register value.
#define BG_CCM_CBCDR_AHB_PODF(r)   (((r) & BM_CCM_CBCDR_AHB_PODF) >> BP_CCM_CBCDR_AHB_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_AHB_PODF.
#define BF_CCM_CBCDR_AHB_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_AHB_PODF) & BM_CCM_CBCDR_AHB_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_AHB_PODF.
#define BF_CCM_CBCDR_AHB_PODF(v)   (((v) << BP_CCM_CBCDR_AHB_PODF) & BM_CCM_CBCDR_AHB_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AHB_PODF field to a new value.
#define BW_CCM_CBCDR_AHB_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_AHB_PODF) | BF_CCM_CBCDR_AHB_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field AXI_PODF[18:16] (RW)
 *
 * Divider for axi podf. Note: any change of this divider might involve handshake with EMI and IPU.
 * See CDHIPR register for the handshake busy bits.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_AXI_PODF      (16)      //!< Bit position for CCM_CBCDR_AXI_PODF.
#define BM_CCM_CBCDR_AXI_PODF      (0x00070000)  //!< Bit mask for CCM_CBCDR_AXI_PODF.

//! @brief Get value of CCM_CBCDR_AXI_PODF from a register value.
#define BG_CCM_CBCDR_AXI_PODF(r)   (((r) & BM_CCM_CBCDR_AXI_PODF) >> BP_CCM_CBCDR_AXI_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_AXI_PODF.
#define BF_CCM_CBCDR_AXI_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_AXI_PODF) & BM_CCM_CBCDR_AXI_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_AXI_PODF.
#define BF_CCM_CBCDR_AXI_PODF(v)   (((v) << BP_CCM_CBCDR_AXI_PODF) & BM_CCM_CBCDR_AXI_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_PODF field to a new value.
#define BW_CCM_CBCDR_AXI_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_AXI_PODF) | BF_CCM_CBCDR_AXI_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field MMDC_CH0_AXI_PODF[21:19] (RW)
 *
 * Divider for mmdc_ch0_axi podf.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_MMDC_CH0_AXI_PODF      (19)      //!< Bit position for CCM_CBCDR_MMDC_CH0_AXI_PODF.
#define BM_CCM_CBCDR_MMDC_CH0_AXI_PODF      (0x00380000)  //!< Bit mask for CCM_CBCDR_MMDC_CH0_AXI_PODF.

//! @brief Get value of CCM_CBCDR_MMDC_CH0_AXI_PODF from a register value.
#define BG_CCM_CBCDR_MMDC_CH0_AXI_PODF(r)   (((r) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF) >> BP_CCM_CBCDR_MMDC_CH0_AXI_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_MMDC_CH0_AXI_PODF.
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_MMDC_CH0_AXI_PODF) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_MMDC_CH0_AXI_PODF.
#define BF_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   (((v) << BP_CCM_CBCDR_MMDC_CH0_AXI_PODF) & BM_CCM_CBCDR_MMDC_CH0_AXI_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH0_AXI_PODF field to a new value.
#define BW_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_MMDC_CH0_AXI_PODF) | BF_CCM_CBCDR_MMDC_CH0_AXI_PODF(v)))
#endif


/* --- Register HW_CCM_CBCDR, field PERIPH_CLK_SEL[25] (RW)
 *
 * Selector for peripheral main clock (source of mmdc_ch0_axi_clk_root). Note: alternative clock
 * source should be used when PLL is relocked. For PLL relock procedure pls refer PLL chapter
 *
 * Values:
 * 0 - derive clock from pll2_sw_clk muxed clock source.
 * 1 - derive clock from periph_clk2_clk clock source.
 */

#define BP_CCM_CBCDR_PERIPH_CLK_SEL      (25)      //!< Bit position for CCM_CBCDR_PERIPH_CLK_SEL.
#define BM_CCM_CBCDR_PERIPH_CLK_SEL      (0x02000000)  //!< Bit mask for CCM_CBCDR_PERIPH_CLK_SEL.

//! @brief Get value of CCM_CBCDR_PERIPH_CLK_SEL from a register value.
#define BG_CCM_CBCDR_PERIPH_CLK_SEL(r)   (((r) & BM_CCM_CBCDR_PERIPH_CLK_SEL) >> BP_CCM_CBCDR_PERIPH_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_PERIPH_CLK_SEL.
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCDR_PERIPH_CLK_SEL) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCDR_PERIPH_CLK_SEL.
#define BF_CCM_CBCDR_PERIPH_CLK_SEL(v)   (((v) << BP_CCM_CBCDR_PERIPH_CLK_SEL) & BM_CCM_CBCDR_PERIPH_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH_CLK_SEL field to a new value.
#define BW_CCM_CBCDR_PERIPH_CLK_SEL(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_PERIPH_CLK_SEL) | BF_CCM_CBCDR_PERIPH_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCDR, field PERIPH2_CLK_SEL[26] (RW)
 *
 * Selector for peripheral2 main clock (source of mmdc_ch1_axi_clk_root mmdc_root_axi_clk_root ).
 *
 * Values:
 * 0 - derive clock from pll2_sw_clk muxed clock source.
 * 1 - derive clock from periph_clk2_clk clock source.
 */

#define BP_CCM_CBCDR_PERIPH2_CLK_SEL      (26)      //!< Bit position for CCM_CBCDR_PERIPH2_CLK_SEL.
#define BM_CCM_CBCDR_PERIPH2_CLK_SEL      (0x04000000)  //!< Bit mask for CCM_CBCDR_PERIPH2_CLK_SEL.

//! @brief Get value of CCM_CBCDR_PERIPH2_CLK_SEL from a register value.
#define BG_CCM_CBCDR_PERIPH2_CLK_SEL(r)   (((r) & BM_CCM_CBCDR_PERIPH2_CLK_SEL) >> BP_CCM_CBCDR_PERIPH2_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_PERIPH2_CLK_SEL.
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCDR_PERIPH2_CLK_SEL) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCDR_PERIPH2_CLK_SEL.
#define BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)   (((v) << BP_CCM_CBCDR_PERIPH2_CLK_SEL) & BM_CCM_CBCDR_PERIPH2_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH2_CLK_SEL field to a new value.
#define BW_CCM_CBCDR_PERIPH2_CLK_SEL(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_PERIPH2_CLK_SEL) | BF_CCM_CBCDR_PERIPH2_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCDR, field PERIPH_CLK2_PODF[29:27] (RW)
 *
 * Divider for periph2 clock podf.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCDR_PERIPH_CLK2_PODF      (27)      //!< Bit position for CCM_CBCDR_PERIPH_CLK2_PODF.
#define BM_CCM_CBCDR_PERIPH_CLK2_PODF      (0x38000000)  //!< Bit mask for CCM_CBCDR_PERIPH_CLK2_PODF.

//! @brief Get value of CCM_CBCDR_PERIPH_CLK2_PODF from a register value.
#define BG_CCM_CBCDR_PERIPH_CLK2_PODF(r)   (((r) & BM_CCM_CBCDR_PERIPH_CLK2_PODF) >> BP_CCM_CBCDR_PERIPH_CLK2_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCDR_PERIPH_CLK2_PODF.
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCDR_PERIPH_CLK2_PODF) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#else
//! @brief Format value for bitfield CCM_CBCDR_PERIPH_CLK2_PODF.
#define BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)   (((v) << BP_CCM_CBCDR_PERIPH_CLK2_PODF) & BM_CCM_CBCDR_PERIPH_CLK2_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH_CLK2_PODF field to a new value.
#define BW_CCM_CBCDR_PERIPH_CLK2_PODF(v)   (HW_CCM_CBCDR_WR((HW_CCM_CBCDR_RD() & ~BM_CCM_CBCDR_PERIPH_CLK2_PODF) | BF_CCM_CBCDR_PERIPH_CLK2_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CBCMR - CCM Bus Clock Multiplexer Register (RW)
 *
 * Reset value: 0x00022324
 *
 * The figure below represents the CCM Bus Clock Multiplexer Register (CBCMR). The CBCMR register
 * contains bits to control the multiplexers that generate the bus clocks. The table below provides
 * its field descriptions.  Note: Any change on the above multiplexer will have to be done while the
 * module that its clock is affected is not functional and the respective clock is gated in LPCG. If
 * the change will be done during operation of the module, then it is not guaranteed that the
 * modules operation will not be harmed.  The change for arm_axi_clk_sel should be done through sdma
 * so that ARM will not use this clock during the change and the clock will be gated in LPCG.
 */
typedef union _hw_ccm_cbcmr
{
    reg32_t U;
    struct _hw_ccm_cbcmr_bitfields
    {
        unsigned GPU2D_AXI_CLK_SEL : 1; //!< [0] Selector for gpu2d_axi clock multiplexer
        unsigned GPU3D_AXI_CLK_SEL : 1; //!< [1] Selector for gpu3d_axi clock multiplexer
        unsigned RESERVED0 : 2; //!< [3:2] Reserved
        unsigned GPU3D_CORE_CLK_SEL : 2; //!< [5:4] Selector for gpu3d_core clock multiplexer
        unsigned RESERVED1 : 2; //!< [7:6] Reserved
        unsigned GPU3D_SHADER_CLK_SEL : 2; //!< [9:8] Selector for gpu3d_shader clock multiplexer
        unsigned PCIE_AXI_CLK_SEL : 1; //!< [10] Selector for pcie_axi clock multiplexer
        unsigned VDOAXI_CLK_SEL : 1; //!< [11] Selector for vdoaxi clock multiplexer
        unsigned PERIPH_CLK2_SEL : 2; //!< [13:12] Selector for peripheral clk2 clock multiplexer
        unsigned VPU_AXI_CLK_SEL : 2; //!< [15:14] Selector for VPU axi clock multiplexer
        unsigned GPU2D_CLK_SEL : 2; //!< [17:16] Selector for open vg clock multiplexer
        unsigned PRE_PERIPH_CLK_SEL : 2; //!< [19:18] Selector for pre_periph clock multiplexer
        unsigned PERIPH2_CLK2_SEL : 1; //!< [20] Selector for periph2_clk2 clock multiplexer
        unsigned PRE_PERIPH2_CLK_SEL : 2; //!< [22:21] Selector for pre_periph2 clock multiplexer
        unsigned GPU2D_CORE_CLK_PODF : 3; //!< [25:23] Divider for gpu2d_core clock. Note: Divider should be updated when output clock is gated.
        unsigned GPU3D_CORE_PODF : 3; //!< [28:26] Divider for gpu3d_core clock. Note: Divider should be updated when output clock is gated.
        unsigned GPU3D_SHADER_PODF : 3; //!< [31:29] Divider for gpu3d_shader clock. Note: Divider should be updated when output clock is gated.
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

/* --- Register HW_CCM_CBCMR, field GPU2D_AXI_CLK_SEL[0] (RW)
 *
 * Selector for gpu2d_axi clock multiplexer
 *
 * Values:
 * 0 - derive clock from axi (Default)
 * 1 - derive clock from system_133M_clk
 */

#define BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL      (0)      //!< Bit position for CCM_CBCMR_GPU2D_AXI_CLK_SEL.
#define BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL      (0x00000001)  //!< Bit mask for CCM_CBCMR_GPU2D_AXI_CLK_SEL.

//! @brief Get value of CCM_CBCMR_GPU2D_AXI_CLK_SEL from a register value.
#define BG_CCM_CBCMR_GPU2D_AXI_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL) >> BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_AXI_CLK_SEL.
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_AXI_CLK_SEL.
#define BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_GPU2D_AXI_CLK_SEL) & BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU2D_AXI_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU2D_AXI_CLK_SEL) | BF_CCM_CBCMR_GPU2D_AXI_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU3D_AXI_CLK_SEL[1] (RW)
 *
 * Selector for gpu3d_axi clock multiplexer
 *
 * Values:
 * 0 - derive clock from axi (Default)
 * 1 - derive clock from system_133M_clk
 */

#define BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL      (1)      //!< Bit position for CCM_CBCMR_GPU3D_AXI_CLK_SEL.
#define BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL      (0x00000002)  //!< Bit mask for CCM_CBCMR_GPU3D_AXI_CLK_SEL.

//! @brief Get value of CCM_CBCMR_GPU3D_AXI_CLK_SEL from a register value.
#define BG_CCM_CBCMR_GPU3D_AXI_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL) >> BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_AXI_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_AXI_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_GPU3D_AXI_CLK_SEL) & BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU3D_AXI_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU3D_AXI_CLK_SEL) | BF_CCM_CBCMR_GPU3D_AXI_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_CLK_SEL[5:4] (RW)
 *
 * Selector for gpu3d_core clock multiplexer
 *
 * Values:
 * 00 - derive clock from mmdc_ch0
 * 01 - derive clock from pll3
 * 10 - derive clock from 594M 528M PFD (Default)
 * 11 - derive clock from 396M PFD
 */

#define BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL      (4)      //!< Bit position for CCM_CBCMR_GPU3D_CORE_CLK_SEL.
#define BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL      (0x00000030)  //!< Bit mask for CCM_CBCMR_GPU3D_CORE_CLK_SEL.

//! @brief Get value of CCM_CBCMR_GPU3D_CORE_CLK_SEL from a register value.
#define BG_CCM_CBCMR_GPU3D_CORE_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL) >> BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_CORE_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_CORE_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_GPU3D_CORE_CLK_SEL) & BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU3D_CORE_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU3D_CORE_CLK_SEL) | BF_CCM_CBCMR_GPU3D_CORE_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_CLK_SEL[9:8] (RW)
 *
 * Selector for gpu3d_shader clock multiplexer
 *
 * Values:
 * 00 - derive clock from mmdc_ch0 clk
 * 01 - derive clock from pll3
 * 10 - derive clock from 594M 528M PFD
 * 11 - derive clock from 720M PFD
 */

#define BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL      (8)      //!< Bit position for CCM_CBCMR_GPU3D_SHADER_CLK_SEL.
#define BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL      (0x00000300)  //!< Bit mask for CCM_CBCMR_GPU3D_SHADER_CLK_SEL.

//! @brief Get value of CCM_CBCMR_GPU3D_SHADER_CLK_SEL from a register value.
#define BG_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL) >> BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_SHADER_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_SHADER_CLK_SEL.
#define BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_GPU3D_SHADER_CLK_SEL) & BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU3D_SHADER_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU3D_SHADER_CLK_SEL) | BF_CCM_CBCMR_GPU3D_SHADER_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field PCIE_AXI_CLK_SEL[10] (RW)
 *
 * Selector for pcie_axi clock multiplexer
 *
 * Values:
 * 0 - derive clock from axi clk (default)
 * 1 - derive clock from system_133M clk
 */

#define BP_CCM_CBCMR_PCIE_AXI_CLK_SEL      (10)      //!< Bit position for CCM_CBCMR_PCIE_AXI_CLK_SEL.
#define BM_CCM_CBCMR_PCIE_AXI_CLK_SEL      (0x00000400)  //!< Bit mask for CCM_CBCMR_PCIE_AXI_CLK_SEL.

//! @brief Get value of CCM_CBCMR_PCIE_AXI_CLK_SEL from a register value.
#define BG_CCM_CBCMR_PCIE_AXI_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL) >> BP_CCM_CBCMR_PCIE_AXI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_PCIE_AXI_CLK_SEL.
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_PCIE_AXI_CLK_SEL) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_PCIE_AXI_CLK_SEL.
#define BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_PCIE_AXI_CLK_SEL) & BM_CCM_CBCMR_PCIE_AXI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCIE_AXI_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_PCIE_AXI_CLK_SEL) | BF_CCM_CBCMR_PCIE_AXI_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field VDOAXI_CLK_SEL[11] (RW)
 *
 * Selector for vdoaxi clock multiplexer
 *
 * Values:
 * 0 - derive clock from axi clk (default)
 * 1 - derive clock from 132M clock
 */

#define BP_CCM_CBCMR_VDOAXI_CLK_SEL      (11)      //!< Bit position for CCM_CBCMR_VDOAXI_CLK_SEL.
#define BM_CCM_CBCMR_VDOAXI_CLK_SEL      (0x00000800)  //!< Bit mask for CCM_CBCMR_VDOAXI_CLK_SEL.

//! @brief Get value of CCM_CBCMR_VDOAXI_CLK_SEL from a register value.
#define BG_CCM_CBCMR_VDOAXI_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_VDOAXI_CLK_SEL) >> BP_CCM_CBCMR_VDOAXI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_VDOAXI_CLK_SEL.
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_VDOAXI_CLK_SEL) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_VDOAXI_CLK_SEL.
#define BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_VDOAXI_CLK_SEL) & BM_CCM_CBCMR_VDOAXI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VDOAXI_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_VDOAXI_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_VDOAXI_CLK_SEL) | BF_CCM_CBCMR_VDOAXI_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field PERIPH_CLK2_SEL[13:12] (RW)
 *
 * Selector for peripheral clk2 clock multiplexer
 *
 * Values:
 * 00 - derive clock from pll3_sw_clk
 * 01 - derive clock from pll1_ref_clk
 * 10 - derive clock from pll2_burn_in_clk (default)
 * 11 - reserved
 */

#define BP_CCM_CBCMR_PERIPH_CLK2_SEL      (12)      //!< Bit position for CCM_CBCMR_PERIPH_CLK2_SEL.
#define BM_CCM_CBCMR_PERIPH_CLK2_SEL      (0x00003000)  //!< Bit mask for CCM_CBCMR_PERIPH_CLK2_SEL.

//! @brief Get value of CCM_CBCMR_PERIPH_CLK2_SEL from a register value.
#define BG_CCM_CBCMR_PERIPH_CLK2_SEL(r)   (((r) & BM_CCM_CBCMR_PERIPH_CLK2_SEL) >> BP_CCM_CBCMR_PERIPH_CLK2_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_PERIPH_CLK2_SEL.
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_PERIPH_CLK2_SEL) & BM_CCM_CBCMR_PERIPH_CLK2_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_PERIPH_CLK2_SEL.
#define BF_CCM_CBCMR_PERIPH_CLK2_SEL(v)   (((v) << BP_CCM_CBCMR_PERIPH_CLK2_SEL) & BM_CCM_CBCMR_PERIPH_CLK2_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH_CLK2_SEL field to a new value.
#define BW_CCM_CBCMR_PERIPH_CLK2_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_PERIPH_CLK2_SEL) | BF_CCM_CBCMR_PERIPH_CLK2_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field VPU_AXI_CLK_SEL[15:14] (RW)
 *
 * Selector for VPU axi clock multiplexer
 *
 * Values:
 * 00 - derive clock from AXI
 * 01 - derive clock from 396M PFD
 * 10 - derive clock from 352M 307M PFD (default)
 * 11 - Restricted
 */

#define BP_CCM_CBCMR_VPU_AXI_CLK_SEL      (14)      //!< Bit position for CCM_CBCMR_VPU_AXI_CLK_SEL.
#define BM_CCM_CBCMR_VPU_AXI_CLK_SEL      (0x0000c000)  //!< Bit mask for CCM_CBCMR_VPU_AXI_CLK_SEL.

//! @brief Get value of CCM_CBCMR_VPU_AXI_CLK_SEL from a register value.
#define BG_CCM_CBCMR_VPU_AXI_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL) >> BP_CCM_CBCMR_VPU_AXI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_VPU_AXI_CLK_SEL.
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_VPU_AXI_CLK_SEL) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_VPU_AXI_CLK_SEL.
#define BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_VPU_AXI_CLK_SEL) & BM_CCM_CBCMR_VPU_AXI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VPU_AXI_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_VPU_AXI_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_VPU_AXI_CLK_SEL) | BF_CCM_CBCMR_VPU_AXI_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU2D_CLK_SEL[17:16] (RW)
 *
 * Selector for open vg clock multiplexer
 *
 * Values:
 * 00 - derive clock from axi
 * 01 - derive clock from pll3
 * 10 - 352M 307M PFD
 * 11 - derive clock from 396M PFD
 */

#define BP_CCM_CBCMR_GPU2D_CLK_SEL      (16)      //!< Bit position for CCM_CBCMR_GPU2D_CLK_SEL.
#define BM_CCM_CBCMR_GPU2D_CLK_SEL      (0x00030000)  //!< Bit mask for CCM_CBCMR_GPU2D_CLK_SEL.

//! @brief Get value of CCM_CBCMR_GPU2D_CLK_SEL from a register value.
#define BG_CCM_CBCMR_GPU2D_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_GPU2D_CLK_SEL) >> BP_CCM_CBCMR_GPU2D_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_CLK_SEL.
#define BF_CCM_CBCMR_GPU2D_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU2D_CLK_SEL) & BM_CCM_CBCMR_GPU2D_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_CLK_SEL.
#define BF_CCM_CBCMR_GPU2D_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_GPU2D_CLK_SEL) & BM_CCM_CBCMR_GPU2D_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU2D_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_GPU2D_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU2D_CLK_SEL) | BF_CCM_CBCMR_GPU2D_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field PRE_PERIPH_CLK_SEL[19:18] (RW)
 *
 * Selector for pre_periph clock multiplexer
 *
 * Values:
 * 00 - derive clock from PLL2 main 528MHz clock
 * 01 - derive clock from 396MHz PLL2 PFD (default)
 * 10 - derive clock from 352M 307M PFD
 * 11 - derive clock from 198MHz clock (divided 396MHz PLL2 PFD)
 */

#define BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL      (18)      //!< Bit position for CCM_CBCMR_PRE_PERIPH_CLK_SEL.
#define BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL      (0x000c0000)  //!< Bit mask for CCM_CBCMR_PRE_PERIPH_CLK_SEL.

//! @brief Get value of CCM_CBCMR_PRE_PERIPH_CLK_SEL from a register value.
#define BG_CCM_CBCMR_PRE_PERIPH_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL) >> BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_PRE_PERIPH_CLK_SEL.
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_PRE_PERIPH_CLK_SEL.
#define BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_PRE_PERIPH_CLK_SEL) & BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRE_PERIPH_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_PRE_PERIPH_CLK_SEL) | BF_CCM_CBCMR_PRE_PERIPH_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field PERIPH2_CLK2_SEL[20] (RW)
 *
 * Selector for periph2_clk2 clock multiplexer
 *
 * Values:
 * 0 - derive clock from pll3_sw_clk (default)
 * 1 - derive clock from pll1_ref_clk
 */

#define BP_CCM_CBCMR_PERIPH2_CLK2_SEL      (20)      //!< Bit position for CCM_CBCMR_PERIPH2_CLK2_SEL.
#define BM_CCM_CBCMR_PERIPH2_CLK2_SEL      (0x00100000)  //!< Bit mask for CCM_CBCMR_PERIPH2_CLK2_SEL.

//! @brief Get value of CCM_CBCMR_PERIPH2_CLK2_SEL from a register value.
#define BG_CCM_CBCMR_PERIPH2_CLK2_SEL(r)   (((r) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL) >> BP_CCM_CBCMR_PERIPH2_CLK2_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_PERIPH2_CLK2_SEL.
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_PERIPH2_CLK2_SEL) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_PERIPH2_CLK2_SEL.
#define BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   (((v) << BP_CCM_CBCMR_PERIPH2_CLK2_SEL) & BM_CCM_CBCMR_PERIPH2_CLK2_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH2_CLK2_SEL field to a new value.
#define BW_CCM_CBCMR_PERIPH2_CLK2_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_PERIPH2_CLK2_SEL) | BF_CCM_CBCMR_PERIPH2_CLK2_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field PRE_PERIPH2_CLK_SEL[22:21] (RW)
 *
 * Selector for pre_periph2 clock multiplexer
 *
 * Values:
 * 00 - derive clock from PLL2 main 528MHz clock
 * 01 - derive clock from 396MHz PLL2 PFD (default)
 * 10 - derive clock from 352M 307M PFD
 * 11 - derive clock from 198MHz clock (divided 396MHz PLL2 PFD)
 */

#define BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      (21)      //!< Bit position for CCM_CBCMR_PRE_PERIPH2_CLK_SEL.
#define BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL      (0x00600000)  //!< Bit mask for CCM_CBCMR_PRE_PERIPH2_CLK_SEL.

//! @brief Get value of CCM_CBCMR_PRE_PERIPH2_CLK_SEL from a register value.
#define BG_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(r)   (((r) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL) >> BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_PRE_PERIPH2_CLK_SEL.
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CBCMR_PRE_PERIPH2_CLK_SEL.
#define BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   (((v) << BP_CCM_CBCMR_PRE_PERIPH2_CLK_SEL) & BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRE_PERIPH2_CLK_SEL field to a new value.
#define BW_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_PRE_PERIPH2_CLK_SEL) | BF_CCM_CBCMR_PRE_PERIPH2_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU2D_CORE_CLK_PODF[25:23] (RW)
 *
 * Divider for gpu2d_core clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF      (23)      //!< Bit position for CCM_CBCMR_GPU2D_CORE_CLK_PODF.
#define BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF      (0x03800000)  //!< Bit mask for CCM_CBCMR_GPU2D_CORE_CLK_PODF.

//! @brief Get value of CCM_CBCMR_GPU2D_CORE_CLK_PODF from a register value.
#define BG_CCM_CBCMR_GPU2D_CORE_CLK_PODF(r)   (((r) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF) >> BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_CORE_CLK_PODF.
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU2D_CORE_CLK_PODF.
#define BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   (((v) << BP_CCM_CBCMR_GPU2D_CORE_CLK_PODF) & BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU2D_CORE_CLK_PODF field to a new value.
#define BW_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU2D_CORE_CLK_PODF) | BF_CCM_CBCMR_GPU2D_CORE_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU3D_CORE_PODF[28:26] (RW)
 *
 * Divider for gpu3d_core clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCMR_GPU3D_CORE_PODF      (26)      //!< Bit position for CCM_CBCMR_GPU3D_CORE_PODF.
#define BM_CCM_CBCMR_GPU3D_CORE_PODF      (0x1c000000)  //!< Bit mask for CCM_CBCMR_GPU3D_CORE_PODF.

//! @brief Get value of CCM_CBCMR_GPU3D_CORE_PODF from a register value.
#define BG_CCM_CBCMR_GPU3D_CORE_PODF(r)   (((r) & BM_CCM_CBCMR_GPU3D_CORE_PODF) >> BP_CCM_CBCMR_GPU3D_CORE_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_CORE_PODF.
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU3D_CORE_PODF) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_CORE_PODF.
#define BF_CCM_CBCMR_GPU3D_CORE_PODF(v)   (((v) << BP_CCM_CBCMR_GPU3D_CORE_PODF) & BM_CCM_CBCMR_GPU3D_CORE_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU3D_CORE_PODF field to a new value.
#define BW_CCM_CBCMR_GPU3D_CORE_PODF(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU3D_CORE_PODF) | BF_CCM_CBCMR_GPU3D_CORE_PODF(v)))
#endif


/* --- Register HW_CCM_CBCMR, field GPU3D_SHADER_PODF[31:29] (RW)
 *
 * Divider for gpu3d_shader clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CBCMR_GPU3D_SHADER_PODF      (29)      //!< Bit position for CCM_CBCMR_GPU3D_SHADER_PODF.
#define BM_CCM_CBCMR_GPU3D_SHADER_PODF      (0xe0000000)  //!< Bit mask for CCM_CBCMR_GPU3D_SHADER_PODF.

//! @brief Get value of CCM_CBCMR_GPU3D_SHADER_PODF from a register value.
#define BG_CCM_CBCMR_GPU3D_SHADER_PODF(r)   (((r) & BM_CCM_CBCMR_GPU3D_SHADER_PODF) >> BP_CCM_CBCMR_GPU3D_SHADER_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_SHADER_PODF.
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   ((((reg32_t) v) << BP_CCM_CBCMR_GPU3D_SHADER_PODF) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#else
//! @brief Format value for bitfield CCM_CBCMR_GPU3D_SHADER_PODF.
#define BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)   (((v) << BP_CCM_CBCMR_GPU3D_SHADER_PODF) & BM_CCM_CBCMR_GPU3D_SHADER_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GPU3D_SHADER_PODF field to a new value.
#define BW_CCM_CBCMR_GPU3D_SHADER_PODF(v)   (HW_CCM_CBCMR_WR((HW_CCM_CBCMR_RD() & ~BM_CCM_CBCMR_GPU3D_SHADER_PODF) | BF_CCM_CBCMR_GPU3D_SHADER_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSCMR1 - CCM Serial Clock Multiplexer Register 1 (RW)
 *
 * Reset value: 0x00f00000
 *
 * The figure below represents the CCM Serial Clock Multiplexer Register 1 (CSCMR1). The CSCMR1
 * register contains bits to control the multiplexers that generate the serial clocks. The table
 * below provides its field descriptions.  Note: Any change on the above multiplexer will have to be
 * done while the module that its clock is affected is not functional and the clock is gated. If the
 * change will be done during operation of the module, then it is not guaranteed that the modules
 * operation will not be harmed.
 */
typedef union _hw_ccm_cscmr1
{
    reg32_t U;
    struct _hw_ccm_cscmr1_bitfields
    {
        unsigned PERCLK_PODF : 6; //!< [5:0] Divider for perclk podf.
        unsigned RESERVED0 : 4; //!< [9:6] Reserved
        unsigned SSI1_CLK_SEL : 2; //!< [11:10] Selector for ssi1 clock multiplexer
        unsigned SSI2_CLK_SEL : 2; //!< [13:12] Selector for ssi2 clock multiplexer
        unsigned SSI3_CLK_SEL : 2; //!< [15:14] Selector for ssi3 clock multiplexer
        unsigned USDHC1_CLK_SEL : 1; //!< [16] Selector for usdhc1 clock multiplexer
        unsigned USDHC2_CLK_SEL : 1; //!< [17] Selector for usdhc2 clock multiplexer
        unsigned USDHC3_CLK_SEL : 1; //!< [18] Selector for usdhc3 clock multiplexer
        unsigned USDHC4_CLK_SEL : 1; //!< [19] Selector for usdhc4 clock multiplexer
        unsigned ACLK_EMI_PODF : 3; //!< [22:20] Divider for aclk_emi clock root.
        unsigned ACLK_EMI_SLOW_PODF : 3; //!< [25:23] Divider for aclk_emi_slow clock root.
        unsigned RESERVED1 : 1; //!< [26] Reserved
        unsigned ACLK_EMI_SEL : 2; //!< [28:27] Selector for aclk_emi root clock multiplexer
        unsigned ACLK_EMI_SLOW_SEL : 2; //!< [30:29] Selector for aclk_emi_slow root clock multiplexer
        unsigned RESERVED2 : 1; //!< [31] Reserved.
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

/* --- Register HW_CCM_CSCMR1, field PERCLK_PODF[5:0] (RW)
 *
 * Divider for perclk podf.
 *
 * Values:
 * 000 - divide by 1 (default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCMR1_PERCLK_PODF      (0)      //!< Bit position for CCM_CSCMR1_PERCLK_PODF.
#define BM_CCM_CSCMR1_PERCLK_PODF      (0x0000003f)  //!< Bit mask for CCM_CSCMR1_PERCLK_PODF.

//! @brief Get value of CCM_CSCMR1_PERCLK_PODF from a register value.
#define BG_CCM_CSCMR1_PERCLK_PODF(r)   (((r) & BM_CCM_CSCMR1_PERCLK_PODF) >> BP_CCM_CSCMR1_PERCLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_PERCLK_PODF.
#define BF_CCM_CSCMR1_PERCLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_PERCLK_PODF) & BM_CCM_CSCMR1_PERCLK_PODF)
#else
//! @brief Format value for bitfield CCM_CSCMR1_PERCLK_PODF.
#define BF_CCM_CSCMR1_PERCLK_PODF(v)   (((v) << BP_CCM_CSCMR1_PERCLK_PODF) & BM_CCM_CSCMR1_PERCLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERCLK_PODF field to a new value.
#define BW_CCM_CSCMR1_PERCLK_PODF(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_PERCLK_PODF) | BF_CCM_CSCMR1_PERCLK_PODF(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field SSI1_CLK_SEL[11:10] (RW)
 *
 * Selector for ssi1 clock multiplexer
 *
 * Values:
 * 00 - derive clock from 508.2M PFD (Default)
 * 01 - derive clock from 454.7M PFD
 * 10 - derive clock from pll4
 * 11 - Restricted
 */

#define BP_CCM_CSCMR1_SSI1_CLK_SEL      (10)      //!< Bit position for CCM_CSCMR1_SSI1_CLK_SEL.
#define BM_CCM_CSCMR1_SSI1_CLK_SEL      (0x00000c00)  //!< Bit mask for CCM_CSCMR1_SSI1_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_SSI1_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_SSI1_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_SSI1_CLK_SEL) >> BP_CCM_CSCMR1_SSI1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_SSI1_CLK_SEL.
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_SSI1_CLK_SEL) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_SSI1_CLK_SEL.
#define BF_CCM_CSCMR1_SSI1_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_SSI1_CLK_SEL) & BM_CCM_CSCMR1_SSI1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI1_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_SSI1_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_SSI1_CLK_SEL) | BF_CCM_CSCMR1_SSI1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field SSI2_CLK_SEL[13:12] (RW)
 *
 * Selector for ssi2 clock multiplexer
 *
 * Values:
 * 00 - derive clock from 508.2M PFD (Default)
 * 01 - derive clock from 454.7M PFD
 * 10 - derive clock from pll4
 * 11 - Restricted
 */

#define BP_CCM_CSCMR1_SSI2_CLK_SEL      (12)      //!< Bit position for CCM_CSCMR1_SSI2_CLK_SEL.
#define BM_CCM_CSCMR1_SSI2_CLK_SEL      (0x00003000)  //!< Bit mask for CCM_CSCMR1_SSI2_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_SSI2_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_SSI2_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_SSI2_CLK_SEL) >> BP_CCM_CSCMR1_SSI2_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_SSI2_CLK_SEL.
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_SSI2_CLK_SEL) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_SSI2_CLK_SEL.
#define BF_CCM_CSCMR1_SSI2_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_SSI2_CLK_SEL) & BM_CCM_CSCMR1_SSI2_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI2_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_SSI2_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_SSI2_CLK_SEL) | BF_CCM_CSCMR1_SSI2_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field SSI3_CLK_SEL[15:14] (RW)
 *
 * Selector for ssi3 clock multiplexer
 *
 * Values:
 * 00 - derive clock from 508.2M PFD (Default)
 * 01 - derive clock from 454.7M PFD
 * 10 - derive clock from pll4
 * 11 - Restricted
 */

#define BP_CCM_CSCMR1_SSI3_CLK_SEL      (14)      //!< Bit position for CCM_CSCMR1_SSI3_CLK_SEL.
#define BM_CCM_CSCMR1_SSI3_CLK_SEL      (0x0000c000)  //!< Bit mask for CCM_CSCMR1_SSI3_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_SSI3_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_SSI3_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_SSI3_CLK_SEL) >> BP_CCM_CSCMR1_SSI3_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_SSI3_CLK_SEL.
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_SSI3_CLK_SEL) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_SSI3_CLK_SEL.
#define BF_CCM_CSCMR1_SSI3_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_SSI3_CLK_SEL) & BM_CCM_CSCMR1_SSI3_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI3_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_SSI3_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_SSI3_CLK_SEL) | BF_CCM_CSCMR1_SSI3_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field USDHC1_CLK_SEL[16] (RW)
 *
 * Selector for usdhc1 clock multiplexer
 *
 * Values:
 * 0 - derive clock from 396M PFD
 * 1 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_USDHC1_CLK_SEL      (16)      //!< Bit position for CCM_CSCMR1_USDHC1_CLK_SEL.
#define BM_CCM_CSCMR1_USDHC1_CLK_SEL      (0x00010000)  //!< Bit mask for CCM_CSCMR1_USDHC1_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_USDHC1_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_USDHC1_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_USDHC1_CLK_SEL) >> BP_CCM_CSCMR1_USDHC1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_USDHC1_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_USDHC1_CLK_SEL) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_USDHC1_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_USDHC1_CLK_SEL) & BM_CCM_CSCMR1_USDHC1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC1_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_USDHC1_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_USDHC1_CLK_SEL) | BF_CCM_CSCMR1_USDHC1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field USDHC2_CLK_SEL[17] (RW)
 *
 * Selector for usdhc2 clock multiplexer
 *
 * Values:
 * 0 - derive clock from 396M PFD
 * 1 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_USDHC2_CLK_SEL      (17)      //!< Bit position for CCM_CSCMR1_USDHC2_CLK_SEL.
#define BM_CCM_CSCMR1_USDHC2_CLK_SEL      (0x00020000)  //!< Bit mask for CCM_CSCMR1_USDHC2_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_USDHC2_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_USDHC2_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_USDHC2_CLK_SEL) >> BP_CCM_CSCMR1_USDHC2_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_USDHC2_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_USDHC2_CLK_SEL) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_USDHC2_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_USDHC2_CLK_SEL) & BM_CCM_CSCMR1_USDHC2_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC2_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_USDHC2_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_USDHC2_CLK_SEL) | BF_CCM_CSCMR1_USDHC2_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field USDHC3_CLK_SEL[18] (RW)
 *
 * Selector for usdhc3 clock multiplexer
 *
 * Values:
 * 0 - derive clock from 396M PFD
 * 1 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_USDHC3_CLK_SEL      (18)      //!< Bit position for CCM_CSCMR1_USDHC3_CLK_SEL.
#define BM_CCM_CSCMR1_USDHC3_CLK_SEL      (0x00040000)  //!< Bit mask for CCM_CSCMR1_USDHC3_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_USDHC3_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_USDHC3_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_USDHC3_CLK_SEL) >> BP_CCM_CSCMR1_USDHC3_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_USDHC3_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_USDHC3_CLK_SEL) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_USDHC3_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_USDHC3_CLK_SEL) & BM_CCM_CSCMR1_USDHC3_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC3_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_USDHC3_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_USDHC3_CLK_SEL) | BF_CCM_CSCMR1_USDHC3_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field USDHC4_CLK_SEL[19] (RW)
 *
 * Selector for usdhc4 clock multiplexer
 *
 * Values:
 * 0 - derive clock from 396M PFD
 * 1 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_USDHC4_CLK_SEL      (19)      //!< Bit position for CCM_CSCMR1_USDHC4_CLK_SEL.
#define BM_CCM_CSCMR1_USDHC4_CLK_SEL      (0x00080000)  //!< Bit mask for CCM_CSCMR1_USDHC4_CLK_SEL.

//! @brief Get value of CCM_CSCMR1_USDHC4_CLK_SEL from a register value.
#define BG_CCM_CSCMR1_USDHC4_CLK_SEL(r)   (((r) & BM_CCM_CSCMR1_USDHC4_CLK_SEL) >> BP_CCM_CSCMR1_USDHC4_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_USDHC4_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_USDHC4_CLK_SEL) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_USDHC4_CLK_SEL.
#define BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)   (((v) << BP_CCM_CSCMR1_USDHC4_CLK_SEL) & BM_CCM_CSCMR1_USDHC4_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC4_CLK_SEL field to a new value.
#define BW_CCM_CSCMR1_USDHC4_CLK_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_USDHC4_CLK_SEL) | BF_CCM_CSCMR1_USDHC4_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_PODF[22:20] (RW)
 *
 * Divider for aclk_emi clock root.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 111 - divide by 8 (default)
 */

#define BP_CCM_CSCMR1_ACLK_EMI_PODF      (20)      //!< Bit position for CCM_CSCMR1_ACLK_EMI_PODF.
#define BM_CCM_CSCMR1_ACLK_EMI_PODF      (0x00700000)  //!< Bit mask for CCM_CSCMR1_ACLK_EMI_PODF.

//! @brief Get value of CCM_CSCMR1_ACLK_EMI_PODF from a register value.
#define BG_CCM_CSCMR1_ACLK_EMI_PODF(r)   (((r) & BM_CCM_CSCMR1_ACLK_EMI_PODF) >> BP_CCM_CSCMR1_ACLK_EMI_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_PODF.
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_ACLK_EMI_PODF) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#else
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_PODF.
#define BF_CCM_CSCMR1_ACLK_EMI_PODF(v)   (((v) << BP_CCM_CSCMR1_ACLK_EMI_PODF) & BM_CCM_CSCMR1_ACLK_EMI_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLK_EMI_PODF field to a new value.
#define BW_CCM_CSCMR1_ACLK_EMI_PODF(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_ACLK_EMI_PODF) | BF_CCM_CSCMR1_ACLK_EMI_PODF(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_PODF[25:23] (RW)
 *
 * Divider for aclk_emi_slow clock root.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (default)
 * 111 - divide by 8
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      (23)      //!< Bit position for CCM_CSCMR1_ACLK_EMI_SLOW_PODF.
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF      (0x03800000)  //!< Bit mask for CCM_CSCMR1_ACLK_EMI_SLOW_PODF.

//! @brief Get value of CCM_CSCMR1_ACLK_EMI_SLOW_PODF from a register value.
#define BG_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(r)   (((r) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF) >> BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SLOW_PODF.
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#else
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SLOW_PODF.
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   (((v) << BP_CCM_CSCMR1_ACLK_EMI_SLOW_PODF) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLK_EMI_SLOW_PODF field to a new value.
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_ACLK_EMI_SLOW_PODF) | BF_CCM_CSCMR1_ACLK_EMI_SLOW_PODF(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SEL[28:27] (RW)
 *
 * Selector for aclk_emi root clock multiplexer
 *
 * Values:
 * 00 - derive clock from 396M PFD (default)
 * 01 - derive clock from PLL3
 * 10 - derive clock from AXI clk root
 * 11 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SEL      (27)      //!< Bit position for CCM_CSCMR1_ACLK_EMI_SEL.
#define BM_CCM_CSCMR1_ACLK_EMI_SEL      (0x18000000)  //!< Bit mask for CCM_CSCMR1_ACLK_EMI_SEL.

//! @brief Get value of CCM_CSCMR1_ACLK_EMI_SEL from a register value.
#define BG_CCM_CSCMR1_ACLK_EMI_SEL(r)   (((r) & BM_CCM_CSCMR1_ACLK_EMI_SEL) >> BP_CCM_CSCMR1_ACLK_EMI_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SEL.
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_ACLK_EMI_SEL) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SEL.
#define BF_CCM_CSCMR1_ACLK_EMI_SEL(v)   (((v) << BP_CCM_CSCMR1_ACLK_EMI_SEL) & BM_CCM_CSCMR1_ACLK_EMI_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLK_EMI_SEL field to a new value.
#define BW_CCM_CSCMR1_ACLK_EMI_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_ACLK_EMI_SEL) | BF_CCM_CSCMR1_ACLK_EMI_SEL(v)))
#endif


/* --- Register HW_CCM_CSCMR1, field ACLK_EMI_SLOW_SEL[30:29] (RW)
 *
 * Selector for aclk_emi_slow root clock multiplexer
 *
 * Values:
 * 00 - derive clock from AXI clk root (default)
 * 01 - derive clock from PLL3
 * 10 - derive clock from 396M PFD
 * 11 - derive clock from 352M 307M PFD
 */

#define BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      (29)      //!< Bit position for CCM_CSCMR1_ACLK_EMI_SLOW_SEL.
#define BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL      (0x60000000)  //!< Bit mask for CCM_CSCMR1_ACLK_EMI_SLOW_SEL.

//! @brief Get value of CCM_CSCMR1_ACLK_EMI_SLOW_SEL from a register value.
#define BG_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(r)   (((r) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL) >> BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SLOW_SEL.
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR1_ACLK_EMI_SLOW_SEL.
#define BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   (((v) << BP_CCM_CSCMR1_ACLK_EMI_SLOW_SEL) & BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLK_EMI_SLOW_SEL field to a new value.
#define BW_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)   (HW_CCM_CSCMR1_WR((HW_CCM_CSCMR1_RD() & ~BM_CCM_CSCMR1_ACLK_EMI_SLOW_SEL) | BF_CCM_CSCMR1_ACLK_EMI_SLOW_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSCMR2 - CCM Serial Clock Multiplexer Register 2 (RW)
 *
 * Reset value: 0x02b92f06
 *
 * The figure below represents the CCM Serial Clock Multiplexer Register 2 (CSCMR2). The CSCMR2
 * register contains bits to control the multiplexers that generate the serial clocks. The table
 * below provides its field descriptions.  Note: Any change on the above multiplexer will have to be
 * done while the module that its clock is affected is not functional and the clock is gated. If the
 * change will be done during operation of the module, then it is not guaranteed that the modules
 * operation will not be harmed.
 */
typedef union _hw_ccm_cscmr2
{
    reg32_t U;
    struct _hw_ccm_cscmr2_bitfields
    {
        unsigned RESERVED0 : 2; //!< [1:0] Reserved
        unsigned CAN_CLK_PODF : 6; //!< [7:2] Divider for can clock podf.
        unsigned RESERVED1 : 2; //!< [9:8] Reserved
        unsigned LDB_DI0_IPU_DIV : 1; //!< [10] Control for divider of ldb clock for IPU di0
        unsigned LDB_DI1_IPU_DIV : 1; //!< [11] Control for divider of ldb clock for IPU di1
        unsigned RESERVED2 : 7; //!< [18:12] Reserved
        unsigned ESAI_CLK_SEL : 2; //!< [20:19] Selector for esai clock multiplexer
        unsigned RESERVED3 : 11; //!< [31:21] Reserved
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

/* --- Register HW_CCM_CSCMR2, field CAN_CLK_PODF[7:2] (RW)
 *
 * Divider for can clock podf.
 *
 * Values:
 * 000000 - divide by 1
 * 000111 - divide by 8
 * 111111 - divide by 2^6
 */

#define BP_CCM_CSCMR2_CAN_CLK_PODF      (2)      //!< Bit position for CCM_CSCMR2_CAN_CLK_PODF.
#define BM_CCM_CSCMR2_CAN_CLK_PODF      (0x000000fc)  //!< Bit mask for CCM_CSCMR2_CAN_CLK_PODF.

//! @brief Get value of CCM_CSCMR2_CAN_CLK_PODF from a register value.
#define BG_CCM_CSCMR2_CAN_CLK_PODF(r)   (((r) & BM_CCM_CSCMR2_CAN_CLK_PODF) >> BP_CCM_CSCMR2_CAN_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR2_CAN_CLK_PODF.
#define BF_CCM_CSCMR2_CAN_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCMR2_CAN_CLK_PODF) & BM_CCM_CSCMR2_CAN_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CSCMR2_CAN_CLK_PODF.
#define BF_CCM_CSCMR2_CAN_CLK_PODF(v)   (((v) << BP_CCM_CSCMR2_CAN_CLK_PODF) & BM_CCM_CSCMR2_CAN_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAN_CLK_PODF field to a new value.
#define BW_CCM_CSCMR2_CAN_CLK_PODF(v)   (HW_CCM_CSCMR2_WR((HW_CCM_CSCMR2_RD() & ~BM_CCM_CSCMR2_CAN_CLK_PODF) | BF_CCM_CSCMR2_CAN_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CSCMR2, field LDB_DI0_IPU_DIV[10] (RW)
 *
 * Control for divider of ldb clock for IPU di0
 *
 * Values:
 * 0 - divide by 3.5
 * 1 - divide by 7(Default)
 */

#define BP_CCM_CSCMR2_LDB_DI0_IPU_DIV      (10)      //!< Bit position for CCM_CSCMR2_LDB_DI0_IPU_DIV.
#define BM_CCM_CSCMR2_LDB_DI0_IPU_DIV      (0x00000400)  //!< Bit mask for CCM_CSCMR2_LDB_DI0_IPU_DIV.

//! @brief Get value of CCM_CSCMR2_LDB_DI0_IPU_DIV from a register value.
#define BG_CCM_CSCMR2_LDB_DI0_IPU_DIV(r)   (((r) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV) >> BP_CCM_CSCMR2_LDB_DI0_IPU_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR2_LDB_DI0_IPU_DIV.
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   ((((reg32_t) v) << BP_CCM_CSCMR2_LDB_DI0_IPU_DIV) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#else
//! @brief Format value for bitfield CCM_CSCMR2_LDB_DI0_IPU_DIV.
#define BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   (((v) << BP_CCM_CSCMR2_LDB_DI0_IPU_DIV) & BM_CCM_CSCMR2_LDB_DI0_IPU_DIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LDB_DI0_IPU_DIV field to a new value.
#define BW_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)   (HW_CCM_CSCMR2_WR((HW_CCM_CSCMR2_RD() & ~BM_CCM_CSCMR2_LDB_DI0_IPU_DIV) | BF_CCM_CSCMR2_LDB_DI0_IPU_DIV(v)))
#endif


/* --- Register HW_CCM_CSCMR2, field LDB_DI1_IPU_DIV[11] (RW)
 *
 * Control for divider of ldb clock for IPU di1
 *
 * Values:
 * 0 - divide by 3.5
 * 1 - divide by 7(Default)
 */

#define BP_CCM_CSCMR2_LDB_DI1_IPU_DIV      (11)      //!< Bit position for CCM_CSCMR2_LDB_DI1_IPU_DIV.
#define BM_CCM_CSCMR2_LDB_DI1_IPU_DIV      (0x00000800)  //!< Bit mask for CCM_CSCMR2_LDB_DI1_IPU_DIV.

//! @brief Get value of CCM_CSCMR2_LDB_DI1_IPU_DIV from a register value.
#define BG_CCM_CSCMR2_LDB_DI1_IPU_DIV(r)   (((r) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV) >> BP_CCM_CSCMR2_LDB_DI1_IPU_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR2_LDB_DI1_IPU_DIV.
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   ((((reg32_t) v) << BP_CCM_CSCMR2_LDB_DI1_IPU_DIV) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#else
//! @brief Format value for bitfield CCM_CSCMR2_LDB_DI1_IPU_DIV.
#define BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   (((v) << BP_CCM_CSCMR2_LDB_DI1_IPU_DIV) & BM_CCM_CSCMR2_LDB_DI1_IPU_DIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LDB_DI1_IPU_DIV field to a new value.
#define BW_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)   (HW_CCM_CSCMR2_WR((HW_CCM_CSCMR2_RD() & ~BM_CCM_CSCMR2_LDB_DI1_IPU_DIV) | BF_CCM_CSCMR2_LDB_DI1_IPU_DIV(v)))
#endif


/* --- Register HW_CCM_CSCMR2, field ESAI_CLK_SEL[20:19] (RW)
 *
 * Selector for esai clock multiplexer
 *
 * Values:
 * 00 - derive clock from pll4 divided clock
 * 01 - derive clock from 508M PFD clock
 * 10 - derive clock from 454M PFD clock
 * 11 - derive clock from pll3 clock
 */

#define BP_CCM_CSCMR2_ESAI_CLK_SEL      (19)      //!< Bit position for CCM_CSCMR2_ESAI_CLK_SEL.
#define BM_CCM_CSCMR2_ESAI_CLK_SEL      (0x00180000)  //!< Bit mask for CCM_CSCMR2_ESAI_CLK_SEL.

//! @brief Get value of CCM_CSCMR2_ESAI_CLK_SEL from a register value.
#define BG_CCM_CSCMR2_ESAI_CLK_SEL(r)   (((r) & BM_CCM_CSCMR2_ESAI_CLK_SEL) >> BP_CCM_CSCMR2_ESAI_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCMR2_ESAI_CLK_SEL.
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCMR2_ESAI_CLK_SEL) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCMR2_ESAI_CLK_SEL.
#define BF_CCM_CSCMR2_ESAI_CLK_SEL(v)   (((v) << BP_CCM_CSCMR2_ESAI_CLK_SEL) & BM_CCM_CSCMR2_ESAI_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESAI_CLK_SEL field to a new value.
#define BW_CCM_CSCMR2_ESAI_CLK_SEL(v)   (HW_CCM_CSCMR2_WR((HW_CCM_CSCMR2_RD() & ~BM_CCM_CSCMR2_ESAI_CLK_SEL) | BF_CCM_CSCMR2_ESAI_CLK_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSCDR1 - CCM Serial Clock Divider Register 1 (RW)
 *
 * Reset value: 0x00490b00
 *
 * The figure below represents the CCM Serial Clock Divider Register 1 (CSCDR1). The CSCDR1 register
 * contains bits to control the clock generation sub module dividers. The table below provides its
 * field descriptions.  Note: Any change on the above dividers will have to be done while the module
 * that its clock is affected is not functional and the affected clock is gated. If the change will
 * be done during operation of the module, then it is not guaranteed that the modules operation will
 * not be harmed.
 */
typedef union _hw_ccm_cscdr1
{
    reg32_t U;
    struct _hw_ccm_cscdr1_bitfields
    {
        unsigned UART_CLK_PODF : 6; //!< [5:0] Divider for uart clock podf.
        unsigned RESERVED0 : 5; //!< [10:6] Reserved.
        unsigned USDHC1_PODF : 3; //!< [13:11] Divider for usdhc1 clock podf. Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 2; //!< [15:14] Reserved
        unsigned USDHC2_PODF : 3; //!< [18:16] Divider for usdhc2 clock. Note: Divider should be updated when output clock is gated.
        unsigned USDHC3_PODF : 3; //!< [21:19] Divider for usdhc3 clock podf. Note: Divider should be updated when output clock is gated.
        unsigned USDHC4_PODF : 3; //!< [24:22] Divider for esdhc4 clock pred. Note: Divider should be updated when output clock is gated.
        unsigned VPU_AXI_PODF : 3; //!< [27:25] Divider for vpu axi clock podf. Note: Divider should be updated when output clock is gated.
        unsigned RESERVED2 : 4; //!< [31:28] Reserved
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

/* --- Register HW_CCM_CSCDR1, field UART_CLK_PODF[5:0] (RW)
 *
 * Divider for uart clock podf.
 *
 * Values:
 * 000000 - divide by 1 (Default)
 * 111111 - divide by 2^6
 */

#define BP_CCM_CSCDR1_UART_CLK_PODF      (0)      //!< Bit position for CCM_CSCDR1_UART_CLK_PODF.
#define BM_CCM_CSCDR1_UART_CLK_PODF      (0x0000003f)  //!< Bit mask for CCM_CSCDR1_UART_CLK_PODF.

//! @brief Get value of CCM_CSCDR1_UART_CLK_PODF from a register value.
#define BG_CCM_CSCDR1_UART_CLK_PODF(r)   (((r) & BM_CCM_CSCDR1_UART_CLK_PODF) >> BP_CCM_CSCDR1_UART_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_UART_CLK_PODF.
#define BF_CCM_CSCDR1_UART_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_UART_CLK_PODF) & BM_CCM_CSCDR1_UART_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_UART_CLK_PODF.
#define BF_CCM_CSCDR1_UART_CLK_PODF(v)   (((v) << BP_CCM_CSCDR1_UART_CLK_PODF) & BM_CCM_CSCDR1_UART_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UART_CLK_PODF field to a new value.
#define BW_CCM_CSCDR1_UART_CLK_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_UART_CLK_PODF) | BF_CCM_CSCDR1_UART_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR1, field USDHC1_PODF[13:11] (RW)
 *
 * Divider for usdhc1 clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR1_USDHC1_PODF      (11)      //!< Bit position for CCM_CSCDR1_USDHC1_PODF.
#define BM_CCM_CSCDR1_USDHC1_PODF      (0x00003800)  //!< Bit mask for CCM_CSCDR1_USDHC1_PODF.

//! @brief Get value of CCM_CSCDR1_USDHC1_PODF from a register value.
#define BG_CCM_CSCDR1_USDHC1_PODF(r)   (((r) & BM_CCM_CSCDR1_USDHC1_PODF) >> BP_CCM_CSCDR1_USDHC1_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_USDHC1_PODF.
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_USDHC1_PODF) & BM_CCM_CSCDR1_USDHC1_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_USDHC1_PODF.
#define BF_CCM_CSCDR1_USDHC1_PODF(v)   (((v) << BP_CCM_CSCDR1_USDHC1_PODF) & BM_CCM_CSCDR1_USDHC1_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC1_PODF field to a new value.
#define BW_CCM_CSCDR1_USDHC1_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_USDHC1_PODF) | BF_CCM_CSCDR1_USDHC1_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR1, field USDHC2_PODF[18:16] (RW)
 *
 * Divider for usdhc2 clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR1_USDHC2_PODF      (16)      //!< Bit position for CCM_CSCDR1_USDHC2_PODF.
#define BM_CCM_CSCDR1_USDHC2_PODF      (0x00070000)  //!< Bit mask for CCM_CSCDR1_USDHC2_PODF.

//! @brief Get value of CCM_CSCDR1_USDHC2_PODF from a register value.
#define BG_CCM_CSCDR1_USDHC2_PODF(r)   (((r) & BM_CCM_CSCDR1_USDHC2_PODF) >> BP_CCM_CSCDR1_USDHC2_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_USDHC2_PODF.
#define BF_CCM_CSCDR1_USDHC2_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_USDHC2_PODF) & BM_CCM_CSCDR1_USDHC2_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_USDHC2_PODF.
#define BF_CCM_CSCDR1_USDHC2_PODF(v)   (((v) << BP_CCM_CSCDR1_USDHC2_PODF) & BM_CCM_CSCDR1_USDHC2_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC2_PODF field to a new value.
#define BW_CCM_CSCDR1_USDHC2_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_USDHC2_PODF) | BF_CCM_CSCDR1_USDHC2_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR1, field USDHC3_PODF[21:19] (RW)
 *
 * Divider for usdhc3 clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR1_USDHC3_PODF      (19)      //!< Bit position for CCM_CSCDR1_USDHC3_PODF.
#define BM_CCM_CSCDR1_USDHC3_PODF      (0x00380000)  //!< Bit mask for CCM_CSCDR1_USDHC3_PODF.

//! @brief Get value of CCM_CSCDR1_USDHC3_PODF from a register value.
#define BG_CCM_CSCDR1_USDHC3_PODF(r)   (((r) & BM_CCM_CSCDR1_USDHC3_PODF) >> BP_CCM_CSCDR1_USDHC3_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_USDHC3_PODF.
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_USDHC3_PODF) & BM_CCM_CSCDR1_USDHC3_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_USDHC3_PODF.
#define BF_CCM_CSCDR1_USDHC3_PODF(v)   (((v) << BP_CCM_CSCDR1_USDHC3_PODF) & BM_CCM_CSCDR1_USDHC3_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC3_PODF field to a new value.
#define BW_CCM_CSCDR1_USDHC3_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_USDHC3_PODF) | BF_CCM_CSCDR1_USDHC3_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR1, field USDHC4_PODF[24:22] (RW)
 *
 * Divider for esdhc4 clock pred. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR1_USDHC4_PODF      (22)      //!< Bit position for CCM_CSCDR1_USDHC4_PODF.
#define BM_CCM_CSCDR1_USDHC4_PODF      (0x01c00000)  //!< Bit mask for CCM_CSCDR1_USDHC4_PODF.

//! @brief Get value of CCM_CSCDR1_USDHC4_PODF from a register value.
#define BG_CCM_CSCDR1_USDHC4_PODF(r)   (((r) & BM_CCM_CSCDR1_USDHC4_PODF) >> BP_CCM_CSCDR1_USDHC4_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_USDHC4_PODF.
#define BF_CCM_CSCDR1_USDHC4_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_USDHC4_PODF) & BM_CCM_CSCDR1_USDHC4_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_USDHC4_PODF.
#define BF_CCM_CSCDR1_USDHC4_PODF(v)   (((v) << BP_CCM_CSCDR1_USDHC4_PODF) & BM_CCM_CSCDR1_USDHC4_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the USDHC4_PODF field to a new value.
#define BW_CCM_CSCDR1_USDHC4_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_USDHC4_PODF) | BF_CCM_CSCDR1_USDHC4_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR1, field VPU_AXI_PODF[27:25] (RW)
 *
 * Divider for vpu axi clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (Default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR1_VPU_AXI_PODF      (25)      //!< Bit position for CCM_CSCDR1_VPU_AXI_PODF.
#define BM_CCM_CSCDR1_VPU_AXI_PODF      (0x0e000000)  //!< Bit mask for CCM_CSCDR1_VPU_AXI_PODF.

//! @brief Get value of CCM_CSCDR1_VPU_AXI_PODF from a register value.
#define BG_CCM_CSCDR1_VPU_AXI_PODF(r)   (((r) & BM_CCM_CSCDR1_VPU_AXI_PODF) >> BP_CCM_CSCDR1_VPU_AXI_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR1_VPU_AXI_PODF.
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR1_VPU_AXI_PODF) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR1_VPU_AXI_PODF.
#define BF_CCM_CSCDR1_VPU_AXI_PODF(v)   (((v) << BP_CCM_CSCDR1_VPU_AXI_PODF) & BM_CCM_CSCDR1_VPU_AXI_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VPU_AXI_PODF field to a new value.
#define BW_CCM_CSCDR1_VPU_AXI_PODF(v)   (HW_CCM_CSCDR1_WR((HW_CCM_CSCDR1_RD() & ~BM_CCM_CSCDR1_VPU_AXI_PODF) | BF_CCM_CSCDR1_VPU_AXI_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CS1CDR - CCM SSI1 Clock Divider Register (RW)
 *
 * Reset value: 0x0ec102c1
 *
 * The figure below represents the CCM SSI1, SSI3, ESAI Clock Divider Register (CS1CDR). The CS1CDR
 * register contains bits to control the ssi1 clock generation dividers. The table below provides
 * its field descriptions.
 */
typedef union _hw_ccm_cs1cdr
{
    reg32_t U;
    struct _hw_ccm_cs1cdr_bitfields
    {
        unsigned SSI1_CLK_PODF : 6; //!< [5:0] Divider for ssi1 clock podf. The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI1_CLK_PRED : 3; //!< [8:6] Divider for ssi1 clock pred.
        unsigned ESAI_CLK_PRED : 3; //!< [11:9] Divider for esai clock pred.
        unsigned RESERVED0 : 4; //!< [15:12] Reserved
        unsigned SSI3_CLK_PODF : 6; //!< [21:16] Divider for ssi3 clock podf. The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI3_CLK_PRED : 3; //!< [24:22] Divider for ssi3 clock pred.
        unsigned ESAI_CLK_PODF : 3; //!< [27:25] Divider for esai clock podf.
        unsigned RESERVED1 : 4; //!< [31:28] Reserved
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

/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PODF[5:0] (RW)
 *
 * Divider for ssi1 clock podf. The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 *
 * Values:
 * 000000 - divide by 1
 * 111111 - divide by 2^6
 */

#define BP_CCM_CS1CDR_SSI1_CLK_PODF      (0)      //!< Bit position for CCM_CS1CDR_SSI1_CLK_PODF.
#define BM_CCM_CS1CDR_SSI1_CLK_PODF      (0x0000003f)  //!< Bit mask for CCM_CS1CDR_SSI1_CLK_PODF.

//! @brief Get value of CCM_CS1CDR_SSI1_CLK_PODF from a register value.
#define BG_CCM_CS1CDR_SSI1_CLK_PODF(r)   (((r) & BM_CCM_CS1CDR_SSI1_CLK_PODF) >> BP_CCM_CS1CDR_SSI1_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_SSI1_CLK_PODF.
#define BF_CCM_CS1CDR_SSI1_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_SSI1_CLK_PODF) & BM_CCM_CS1CDR_SSI1_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CS1CDR_SSI1_CLK_PODF.
#define BF_CCM_CS1CDR_SSI1_CLK_PODF(v)   (((v) << BP_CCM_CS1CDR_SSI1_CLK_PODF) & BM_CCM_CS1CDR_SSI1_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI1_CLK_PODF field to a new value.
#define BW_CCM_CS1CDR_SSI1_CLK_PODF(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_SSI1_CLK_PODF) | BF_CCM_CS1CDR_SSI1_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CS1CDR, field SSI1_CLK_PRED[8:6] (RW)
 *
 * Divider for ssi1 clock pred.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS1CDR_SSI1_CLK_PRED      (6)      //!< Bit position for CCM_CS1CDR_SSI1_CLK_PRED.
#define BM_CCM_CS1CDR_SSI1_CLK_PRED      (0x000001c0)  //!< Bit mask for CCM_CS1CDR_SSI1_CLK_PRED.

//! @brief Get value of CCM_CS1CDR_SSI1_CLK_PRED from a register value.
#define BG_CCM_CS1CDR_SSI1_CLK_PRED(r)   (((r) & BM_CCM_CS1CDR_SSI1_CLK_PRED) >> BP_CCM_CS1CDR_SSI1_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_SSI1_CLK_PRED.
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_SSI1_CLK_PRED) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CS1CDR_SSI1_CLK_PRED.
#define BF_CCM_CS1CDR_SSI1_CLK_PRED(v)   (((v) << BP_CCM_CS1CDR_SSI1_CLK_PRED) & BM_CCM_CS1CDR_SSI1_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI1_CLK_PRED field to a new value.
#define BW_CCM_CS1CDR_SSI1_CLK_PRED(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_SSI1_CLK_PRED) | BF_CCM_CS1CDR_SSI1_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PRED[11:9] (RW)
 *
 * Divider for esai clock pred.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS1CDR_ESAI_CLK_PRED      (9)      //!< Bit position for CCM_CS1CDR_ESAI_CLK_PRED.
#define BM_CCM_CS1CDR_ESAI_CLK_PRED      (0x00000e00)  //!< Bit mask for CCM_CS1CDR_ESAI_CLK_PRED.

//! @brief Get value of CCM_CS1CDR_ESAI_CLK_PRED from a register value.
#define BG_CCM_CS1CDR_ESAI_CLK_PRED(r)   (((r) & BM_CCM_CS1CDR_ESAI_CLK_PRED) >> BP_CCM_CS1CDR_ESAI_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_ESAI_CLK_PRED.
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_ESAI_CLK_PRED) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CS1CDR_ESAI_CLK_PRED.
#define BF_CCM_CS1CDR_ESAI_CLK_PRED(v)   (((v) << BP_CCM_CS1CDR_ESAI_CLK_PRED) & BM_CCM_CS1CDR_ESAI_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESAI_CLK_PRED field to a new value.
#define BW_CCM_CS1CDR_ESAI_CLK_PRED(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_ESAI_CLK_PRED) | BF_CCM_CS1CDR_ESAI_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PODF[21:16] (RW)
 *
 * Divider for ssi3 clock podf. The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 *
 * Values:
 * 000000 - divide by 1
 * 111111 - divide by 2^6
 */

#define BP_CCM_CS1CDR_SSI3_CLK_PODF      (16)      //!< Bit position for CCM_CS1CDR_SSI3_CLK_PODF.
#define BM_CCM_CS1CDR_SSI3_CLK_PODF      (0x003f0000)  //!< Bit mask for CCM_CS1CDR_SSI3_CLK_PODF.

//! @brief Get value of CCM_CS1CDR_SSI3_CLK_PODF from a register value.
#define BG_CCM_CS1CDR_SSI3_CLK_PODF(r)   (((r) & BM_CCM_CS1CDR_SSI3_CLK_PODF) >> BP_CCM_CS1CDR_SSI3_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_SSI3_CLK_PODF.
#define BF_CCM_CS1CDR_SSI3_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_SSI3_CLK_PODF) & BM_CCM_CS1CDR_SSI3_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CS1CDR_SSI3_CLK_PODF.
#define BF_CCM_CS1CDR_SSI3_CLK_PODF(v)   (((v) << BP_CCM_CS1CDR_SSI3_CLK_PODF) & BM_CCM_CS1CDR_SSI3_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI3_CLK_PODF field to a new value.
#define BW_CCM_CS1CDR_SSI3_CLK_PODF(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_SSI3_CLK_PODF) | BF_CCM_CS1CDR_SSI3_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CS1CDR, field SSI3_CLK_PRED[24:22] (RW)
 *
 * Divider for ssi3 clock pred.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS1CDR_SSI3_CLK_PRED      (22)      //!< Bit position for CCM_CS1CDR_SSI3_CLK_PRED.
#define BM_CCM_CS1CDR_SSI3_CLK_PRED      (0x01c00000)  //!< Bit mask for CCM_CS1CDR_SSI3_CLK_PRED.

//! @brief Get value of CCM_CS1CDR_SSI3_CLK_PRED from a register value.
#define BG_CCM_CS1CDR_SSI3_CLK_PRED(r)   (((r) & BM_CCM_CS1CDR_SSI3_CLK_PRED) >> BP_CCM_CS1CDR_SSI3_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_SSI3_CLK_PRED.
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_SSI3_CLK_PRED) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CS1CDR_SSI3_CLK_PRED.
#define BF_CCM_CS1CDR_SSI3_CLK_PRED(v)   (((v) << BP_CCM_CS1CDR_SSI3_CLK_PRED) & BM_CCM_CS1CDR_SSI3_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI3_CLK_PRED field to a new value.
#define BW_CCM_CS1CDR_SSI3_CLK_PRED(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_SSI3_CLK_PRED) | BF_CCM_CS1CDR_SSI3_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CS1CDR, field ESAI_CLK_PODF[27:25] (RW)
 *
 * Divider for esai clock podf.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS1CDR_ESAI_CLK_PODF      (25)      //!< Bit position for CCM_CS1CDR_ESAI_CLK_PODF.
#define BM_CCM_CS1CDR_ESAI_CLK_PODF      (0x0e000000)  //!< Bit mask for CCM_CS1CDR_ESAI_CLK_PODF.

//! @brief Get value of CCM_CS1CDR_ESAI_CLK_PODF from a register value.
#define BG_CCM_CS1CDR_ESAI_CLK_PODF(r)   (((r) & BM_CCM_CS1CDR_ESAI_CLK_PODF) >> BP_CCM_CS1CDR_ESAI_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS1CDR_ESAI_CLK_PODF.
#define BF_CCM_CS1CDR_ESAI_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CS1CDR_ESAI_CLK_PODF) & BM_CCM_CS1CDR_ESAI_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CS1CDR_ESAI_CLK_PODF.
#define BF_CCM_CS1CDR_ESAI_CLK_PODF(v)   (((v) << BP_CCM_CS1CDR_ESAI_CLK_PODF) & BM_CCM_CS1CDR_ESAI_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESAI_CLK_PODF field to a new value.
#define BW_CCM_CS1CDR_ESAI_CLK_PODF(v)   (HW_CCM_CS1CDR_WR((HW_CCM_CS1CDR_RD() & ~BM_CCM_CS1CDR_ESAI_CLK_PODF) | BF_CCM_CS1CDR_ESAI_CLK_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CS2CDR - CCM SSI2 Clock Divider Register (RW)
 *
 * Reset value: 0x000736c1
 *
 * The figure below represents the CCM SSI2, LDB Clock Divider Register (CS2CDR). The CS2CDR
 * register contains bits to control the ssi2 clock generation dividers, and ldb serial clocks
 * select. The table below provides its field descriptions.
 */
typedef union _hw_ccm_cs2cdr
{
    reg32_t U;
    struct _hw_ccm_cs2cdr_bitfields
    {
        unsigned SSI2_CLK_PODF : 6; //!< [5:0] Divider for ssi2 clock podf. The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned SSI2_CLK_PRED : 3; //!< [8:6] Divider for ssi2 clock pred.
        unsigned LDB_DI0_CLK_SEL : 3; //!< [11:9] Selector for ldb_di1 clock multiplexer
        unsigned LDB_DI1_CLK_SEL : 3; //!< [14:12] Selector for ldb_di1 clock multiplexer
        unsigned RESERVED0 : 1; //!< [15] Reserved
        unsigned ENFC_CLK_SEL : 2; //!< [17:16] Selector for enfc clock multiplexer
        unsigned ENFC_CLK_PRED : 3; //!< [20:18] Divider for enfc clock pred divider.
        unsigned ENFC_CLK_PODF : 6; //!< [26:21] Divider for enfc clock divider.
        unsigned RESERVED1 : 5; //!< [31:27] Reserved
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

/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PODF[5:0] (RW)
 *
 * Divider for ssi2 clock podf. The input clock to this divider should be lower than 300Mhz, the
 * predivider can be used to achieve this.
 *
 * Values:
 * 000000 - divide by 1
 * 111111 - divide by 2^6
 */

#define BP_CCM_CS2CDR_SSI2_CLK_PODF      (0)      //!< Bit position for CCM_CS2CDR_SSI2_CLK_PODF.
#define BM_CCM_CS2CDR_SSI2_CLK_PODF      (0x0000003f)  //!< Bit mask for CCM_CS2CDR_SSI2_CLK_PODF.

//! @brief Get value of CCM_CS2CDR_SSI2_CLK_PODF from a register value.
#define BG_CCM_CS2CDR_SSI2_CLK_PODF(r)   (((r) & BM_CCM_CS2CDR_SSI2_CLK_PODF) >> BP_CCM_CS2CDR_SSI2_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_SSI2_CLK_PODF.
#define BF_CCM_CS2CDR_SSI2_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_SSI2_CLK_PODF) & BM_CCM_CS2CDR_SSI2_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CS2CDR_SSI2_CLK_PODF.
#define BF_CCM_CS2CDR_SSI2_CLK_PODF(v)   (((v) << BP_CCM_CS2CDR_SSI2_CLK_PODF) & BM_CCM_CS2CDR_SSI2_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI2_CLK_PODF field to a new value.
#define BW_CCM_CS2CDR_SSI2_CLK_PODF(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_SSI2_CLK_PODF) | BF_CCM_CS2CDR_SSI2_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field SSI2_CLK_PRED[8:6] (RW)
 *
 * Divider for ssi2 clock pred.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS2CDR_SSI2_CLK_PRED      (6)      //!< Bit position for CCM_CS2CDR_SSI2_CLK_PRED.
#define BM_CCM_CS2CDR_SSI2_CLK_PRED      (0x000001c0)  //!< Bit mask for CCM_CS2CDR_SSI2_CLK_PRED.

//! @brief Get value of CCM_CS2CDR_SSI2_CLK_PRED from a register value.
#define BG_CCM_CS2CDR_SSI2_CLK_PRED(r)   (((r) & BM_CCM_CS2CDR_SSI2_CLK_PRED) >> BP_CCM_CS2CDR_SSI2_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_SSI2_CLK_PRED.
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_SSI2_CLK_PRED) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CS2CDR_SSI2_CLK_PRED.
#define BF_CCM_CS2CDR_SSI2_CLK_PRED(v)   (((v) << BP_CCM_CS2CDR_SSI2_CLK_PRED) & BM_CCM_CS2CDR_SSI2_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSI2_CLK_PRED field to a new value.
#define BW_CCM_CS2CDR_SSI2_CLK_PRED(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_SSI2_CLK_PRED) | BF_CCM_CS2CDR_SSI2_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field LDB_DI0_CLK_SEL[11:9] (RW)
 *
 * Selector for ldb_di1 clock multiplexer
 *
 * Values:
 * 000 - pll5 clock
 * 001 - pll2 352M 307M PFD (default)
 * 010 - pll2 396M PFD
 * 011 - MMDC_CH1 clock
 * 100 - pll3 clock
 * 101 - 111 Resrticted
 */

#define BP_CCM_CS2CDR_LDB_DI0_CLK_SEL      (9)      //!< Bit position for CCM_CS2CDR_LDB_DI0_CLK_SEL.
#define BM_CCM_CS2CDR_LDB_DI0_CLK_SEL      (0x00000e00)  //!< Bit mask for CCM_CS2CDR_LDB_DI0_CLK_SEL.

//! @brief Get value of CCM_CS2CDR_LDB_DI0_CLK_SEL from a register value.
#define BG_CCM_CS2CDR_LDB_DI0_CLK_SEL(r)   (((r) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL) >> BP_CCM_CS2CDR_LDB_DI0_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_LDB_DI0_CLK_SEL.
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_LDB_DI0_CLK_SEL) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CS2CDR_LDB_DI0_CLK_SEL.
#define BF_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   (((v) << BP_CCM_CS2CDR_LDB_DI0_CLK_SEL) & BM_CCM_CS2CDR_LDB_DI0_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LDB_DI0_CLK_SEL field to a new value.
#define BW_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_LDB_DI0_CLK_SEL) | BF_CCM_CS2CDR_LDB_DI0_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field LDB_DI1_CLK_SEL[14:12] (RW)
 *
 * Selector for ldb_di1 clock multiplexer
 *
 * Values:
 * 000 - pll5 clock
 * 001 - pll2 352M 307M PFD (default)
 * 010 - pll2 396M PFD
 * 011 - MMDC_CH1 clock
 * 100 - pll3 clock
 * 101 - 111 Resrticted
 */

#define BP_CCM_CS2CDR_LDB_DI1_CLK_SEL      (12)      //!< Bit position for CCM_CS2CDR_LDB_DI1_CLK_SEL.
#define BM_CCM_CS2CDR_LDB_DI1_CLK_SEL      (0x00007000)  //!< Bit mask for CCM_CS2CDR_LDB_DI1_CLK_SEL.

//! @brief Get value of CCM_CS2CDR_LDB_DI1_CLK_SEL from a register value.
#define BG_CCM_CS2CDR_LDB_DI1_CLK_SEL(r)   (((r) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL) >> BP_CCM_CS2CDR_LDB_DI1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_LDB_DI1_CLK_SEL.
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_LDB_DI1_CLK_SEL) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CS2CDR_LDB_DI1_CLK_SEL.
#define BF_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   (((v) << BP_CCM_CS2CDR_LDB_DI1_CLK_SEL) & BM_CCM_CS2CDR_LDB_DI1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LDB_DI1_CLK_SEL field to a new value.
#define BW_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_LDB_DI1_CLK_SEL) | BF_CCM_CS2CDR_LDB_DI1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_SEL[17:16] (RW)
 *
 * Selector for enfc clock multiplexer
 *
 * Values:
 * 00 - pll2 352M 307M PDF (Default)
 * 01 - pll2 clock
 * 10 - pll3 clock
 * 11 - pll2 396M PFD
 */

#define BP_CCM_CS2CDR_ENFC_CLK_SEL      (16)      //!< Bit position for CCM_CS2CDR_ENFC_CLK_SEL.
#define BM_CCM_CS2CDR_ENFC_CLK_SEL      (0x00030000)  //!< Bit mask for CCM_CS2CDR_ENFC_CLK_SEL.

//! @brief Get value of CCM_CS2CDR_ENFC_CLK_SEL from a register value.
#define BG_CCM_CS2CDR_ENFC_CLK_SEL(r)   (((r) & BM_CCM_CS2CDR_ENFC_CLK_SEL) >> BP_CCM_CS2CDR_ENFC_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_SEL.
#define BF_CCM_CS2CDR_ENFC_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_ENFC_CLK_SEL) & BM_CCM_CS2CDR_ENFC_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_SEL.
#define BF_CCM_CS2CDR_ENFC_CLK_SEL(v)   (((v) << BP_CCM_CS2CDR_ENFC_CLK_SEL) & BM_CCM_CS2CDR_ENFC_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENFC_CLK_SEL field to a new value.
#define BW_CCM_CS2CDR_ENFC_CLK_SEL(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_ENFC_CLK_SEL) | BF_CCM_CS2CDR_ENFC_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PRED[20:18] (RW)
 *
 * Divider for enfc clock pred divider.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CS2CDR_ENFC_CLK_PRED      (18)      //!< Bit position for CCM_CS2CDR_ENFC_CLK_PRED.
#define BM_CCM_CS2CDR_ENFC_CLK_PRED      (0x001c0000)  //!< Bit mask for CCM_CS2CDR_ENFC_CLK_PRED.

//! @brief Get value of CCM_CS2CDR_ENFC_CLK_PRED from a register value.
#define BG_CCM_CS2CDR_ENFC_CLK_PRED(r)   (((r) & BM_CCM_CS2CDR_ENFC_CLK_PRED) >> BP_CCM_CS2CDR_ENFC_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_PRED.
#define BF_CCM_CS2CDR_ENFC_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_ENFC_CLK_PRED) & BM_CCM_CS2CDR_ENFC_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_PRED.
#define BF_CCM_CS2CDR_ENFC_CLK_PRED(v)   (((v) << BP_CCM_CS2CDR_ENFC_CLK_PRED) & BM_CCM_CS2CDR_ENFC_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENFC_CLK_PRED field to a new value.
#define BW_CCM_CS2CDR_ENFC_CLK_PRED(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_ENFC_CLK_PRED) | BF_CCM_CS2CDR_ENFC_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CS2CDR, field ENFC_CLK_PODF[26:21] (RW)
 *
 * Divider for enfc clock divider.
 *
 * Values:
 * 000000 - divide by 1
 * 000001 - divide by 2 (Default)
 * 111111 - divide by 2^6
 */

#define BP_CCM_CS2CDR_ENFC_CLK_PODF      (21)      //!< Bit position for CCM_CS2CDR_ENFC_CLK_PODF.
#define BM_CCM_CS2CDR_ENFC_CLK_PODF      (0x07e00000)  //!< Bit mask for CCM_CS2CDR_ENFC_CLK_PODF.

//! @brief Get value of CCM_CS2CDR_ENFC_CLK_PODF from a register value.
#define BG_CCM_CS2CDR_ENFC_CLK_PODF(r)   (((r) & BM_CCM_CS2CDR_ENFC_CLK_PODF) >> BP_CCM_CS2CDR_ENFC_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_PODF.
#define BF_CCM_CS2CDR_ENFC_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CS2CDR_ENFC_CLK_PODF) & BM_CCM_CS2CDR_ENFC_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CS2CDR_ENFC_CLK_PODF.
#define BF_CCM_CS2CDR_ENFC_CLK_PODF(v)   (((v) << BP_CCM_CS2CDR_ENFC_CLK_PODF) & BM_CCM_CS2CDR_ENFC_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENFC_CLK_PODF field to a new value.
#define BW_CCM_CS2CDR_ENFC_CLK_PODF(v)   (HW_CCM_CS2CDR_WR((HW_CCM_CS2CDR_RD() & ~BM_CCM_CS2CDR_ENFC_CLK_PODF) | BF_CCM_CS2CDR_ENFC_CLK_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CDCDR - CCM D1 Clock Divider Register (RW)
 *
 * Reset value: 0x33f71f92
 *
 * The figure below represents the CCM DI Clock Divider Register (CDCDR). The table below provides
 * its field descriptions.
 */
typedef union _hw_ccm_cdcdr
{
    reg32_t U;
    struct _hw_ccm_cdcdr_bitfields
    {
        unsigned RESERVED0 : 7; //!< [6:0] Reserved
        unsigned SPDIF1_CLK_SEL : 2; //!< [8:7] Selector for spdif1 clock multiplexer
        unsigned SPDIF1_CLK_PODF : 3; //!< [11:9] Divider for spdif1 clock podf. Note: Divider should be updated when output clock is gated.
        unsigned SPDIF1_CLK_PRED : 3; //!< [14:12] Divider for spdif1 clock pred. Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 5; //!< [19:15] Reserved.
        unsigned SPDIF0_CLK_SEL : 2; //!< [21:20] Selector for spdif0 clock multiplexer
        unsigned SPDIF0_CLK_PODF : 3; //!< [24:22] Divider for spdif0 clock podf. Note: Divider should be updated when output clock is gated.
        unsigned SPDIF0_CLK_PRED : 3; //!< [27:25] Divider for spdif0 clock pred. Note: Divider should be updated when output clock is gated.
        unsigned HSI_TX_CLK_SEL : 1; //!< [28] Selector for hsi_tx clock multiplexer
        unsigned HSI_TX_PODF : 3; //!< [31:29] Divider for hsi_tx clock podf. Note: Divider should be updated when output clock is gated.
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

/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_SEL[8:7] (RW)
 *
 * Selector for spdif1 clock multiplexer
 *
 * Values:
 * 00 - derive clock from pll4 divided clock
 * 01 - derive clock from 508M PFD clock
 * 10 - derive clock from 454M PFD clock
 * 11 - derive clock from pll3 clock
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_SEL      (7)      //!< Bit position for CCM_CDCDR_SPDIF1_CLK_SEL.
#define BM_CCM_CDCDR_SPDIF1_CLK_SEL      (0x00000180)  //!< Bit mask for CCM_CDCDR_SPDIF1_CLK_SEL.

//! @brief Get value of CCM_CDCDR_SPDIF1_CLK_SEL from a register value.
#define BG_CCM_CDCDR_SPDIF1_CLK_SEL(r)   (((r) & BM_CCM_CDCDR_SPDIF1_CLK_SEL) >> BP_CCM_CDCDR_SPDIF1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_SEL.
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF1_CLK_SEL) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_SEL.
#define BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)   (((v) << BP_CCM_CDCDR_SPDIF1_CLK_SEL) & BM_CCM_CDCDR_SPDIF1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF1_CLK_SEL field to a new value.
#define BW_CCM_CDCDR_SPDIF1_CLK_SEL(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF1_CLK_SEL) | BF_CCM_CDCDR_SPDIF1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PODF[11:9] (RW)
 *
 * Divider for spdif1 clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 111 - divide by 8
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_PODF      (9)      //!< Bit position for CCM_CDCDR_SPDIF1_CLK_PODF.
#define BM_CCM_CDCDR_SPDIF1_CLK_PODF      (0x00000e00)  //!< Bit mask for CCM_CDCDR_SPDIF1_CLK_PODF.

//! @brief Get value of CCM_CDCDR_SPDIF1_CLK_PODF from a register value.
#define BG_CCM_CDCDR_SPDIF1_CLK_PODF(r)   (((r) & BM_CCM_CDCDR_SPDIF1_CLK_PODF) >> BP_CCM_CDCDR_SPDIF1_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_PODF.
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF1_CLK_PODF) & BM_CCM_CDCDR_SPDIF1_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_PODF.
#define BF_CCM_CDCDR_SPDIF1_CLK_PODF(v)   (((v) << BP_CCM_CDCDR_SPDIF1_CLK_PODF) & BM_CCM_CDCDR_SPDIF1_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF1_CLK_PODF field to a new value.
#define BW_CCM_CDCDR_SPDIF1_CLK_PODF(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF1_CLK_PODF) | BF_CCM_CDCDR_SPDIF1_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CDCDR, field SPDIF1_CLK_PRED[14:12] (RW)
 *
 * Divider for spdif1 clock pred. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (do not use with high input frequencies)
 * 001 - divide by 2
 * 010 - divide by 3(Default)
 * 111 - divide by 8
 */

#define BP_CCM_CDCDR_SPDIF1_CLK_PRED      (12)      //!< Bit position for CCM_CDCDR_SPDIF1_CLK_PRED.
#define BM_CCM_CDCDR_SPDIF1_CLK_PRED      (0x00007000)  //!< Bit mask for CCM_CDCDR_SPDIF1_CLK_PRED.

//! @brief Get value of CCM_CDCDR_SPDIF1_CLK_PRED from a register value.
#define BG_CCM_CDCDR_SPDIF1_CLK_PRED(r)   (((r) & BM_CCM_CDCDR_SPDIF1_CLK_PRED) >> BP_CCM_CDCDR_SPDIF1_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_PRED.
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF1_CLK_PRED) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF1_CLK_PRED.
#define BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)   (((v) << BP_CCM_CDCDR_SPDIF1_CLK_PRED) & BM_CCM_CDCDR_SPDIF1_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF1_CLK_PRED field to a new value.
#define BW_CCM_CDCDR_SPDIF1_CLK_PRED(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF1_CLK_PRED) | BF_CCM_CDCDR_SPDIF1_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_SEL[21:20] (RW)
 *
 * Selector for spdif0 clock multiplexer
 *
 * Values:
 * 00 - derive clock from pll4 divided clock
 * 01 - derive clock from 508M PFD clock
 * 10 - derive clock from 454M PFD clock
 * 11 - derive clock from pll3 clock
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_SEL      (20)      //!< Bit position for CCM_CDCDR_SPDIF0_CLK_SEL.
#define BM_CCM_CDCDR_SPDIF0_CLK_SEL      (0x00300000)  //!< Bit mask for CCM_CDCDR_SPDIF0_CLK_SEL.

//! @brief Get value of CCM_CDCDR_SPDIF0_CLK_SEL from a register value.
#define BG_CCM_CDCDR_SPDIF0_CLK_SEL(r)   (((r) & BM_CCM_CDCDR_SPDIF0_CLK_SEL) >> BP_CCM_CDCDR_SPDIF0_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_SEL.
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF0_CLK_SEL) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_SEL.
#define BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)   (((v) << BP_CCM_CDCDR_SPDIF0_CLK_SEL) & BM_CCM_CDCDR_SPDIF0_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF0_CLK_SEL field to a new value.
#define BW_CCM_CDCDR_SPDIF0_CLK_SEL(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF0_CLK_SEL) | BF_CCM_CDCDR_SPDIF0_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PODF[24:22] (RW)
 *
 * Divider for spdif0 clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 111 - divide by 8
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_PODF      (22)      //!< Bit position for CCM_CDCDR_SPDIF0_CLK_PODF.
#define BM_CCM_CDCDR_SPDIF0_CLK_PODF      (0x01c00000)  //!< Bit mask for CCM_CDCDR_SPDIF0_CLK_PODF.

//! @brief Get value of CCM_CDCDR_SPDIF0_CLK_PODF from a register value.
#define BG_CCM_CDCDR_SPDIF0_CLK_PODF(r)   (((r) & BM_CCM_CDCDR_SPDIF0_CLK_PODF) >> BP_CCM_CDCDR_SPDIF0_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_PODF.
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF0_CLK_PODF) & BM_CCM_CDCDR_SPDIF0_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_PODF.
#define BF_CCM_CDCDR_SPDIF0_CLK_PODF(v)   (((v) << BP_CCM_CDCDR_SPDIF0_CLK_PODF) & BM_CCM_CDCDR_SPDIF0_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF0_CLK_PODF field to a new value.
#define BW_CCM_CDCDR_SPDIF0_CLK_PODF(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF0_CLK_PODF) | BF_CCM_CDCDR_SPDIF0_CLK_PODF(v)))
#endif


/* --- Register HW_CCM_CDCDR, field SPDIF0_CLK_PRED[27:25] (RW)
 *
 * Divider for spdif0 clock pred. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1 (do not use with high input frequencies)
 * 001 - divide by 2
 * 010 - divide by 3(Default)
 * 111 - divide by 8
 */

#define BP_CCM_CDCDR_SPDIF0_CLK_PRED      (25)      //!< Bit position for CCM_CDCDR_SPDIF0_CLK_PRED.
#define BM_CCM_CDCDR_SPDIF0_CLK_PRED      (0x0e000000)  //!< Bit mask for CCM_CDCDR_SPDIF0_CLK_PRED.

//! @brief Get value of CCM_CDCDR_SPDIF0_CLK_PRED from a register value.
#define BG_CCM_CDCDR_SPDIF0_CLK_PRED(r)   (((r) & BM_CCM_CDCDR_SPDIF0_CLK_PRED) >> BP_CCM_CDCDR_SPDIF0_CLK_PRED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_PRED.
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   ((((reg32_t) v) << BP_CCM_CDCDR_SPDIF0_CLK_PRED) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#else
//! @brief Format value for bitfield CCM_CDCDR_SPDIF0_CLK_PRED.
#define BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)   (((v) << BP_CCM_CDCDR_SPDIF0_CLK_PRED) & BM_CCM_CDCDR_SPDIF0_CLK_PRED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPDIF0_CLK_PRED field to a new value.
#define BW_CCM_CDCDR_SPDIF0_CLK_PRED(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_SPDIF0_CLK_PRED) | BF_CCM_CDCDR_SPDIF0_CLK_PRED(v)))
#endif


/* --- Register HW_CCM_CDCDR, field HSI_TX_CLK_SEL[28] (RW)
 *
 * Selector for hsi_tx clock multiplexer
 *
 * Values:
 * 0 - derive from pll3 120M clock (default)
 * 1 - derive from pll2 396M PDF
 */

#define BP_CCM_CDCDR_HSI_TX_CLK_SEL      (28)      //!< Bit position for CCM_CDCDR_HSI_TX_CLK_SEL.
#define BM_CCM_CDCDR_HSI_TX_CLK_SEL      (0x10000000)  //!< Bit mask for CCM_CDCDR_HSI_TX_CLK_SEL.

//! @brief Get value of CCM_CDCDR_HSI_TX_CLK_SEL from a register value.
#define BG_CCM_CDCDR_HSI_TX_CLK_SEL(r)   (((r) & BM_CCM_CDCDR_HSI_TX_CLK_SEL) >> BP_CCM_CDCDR_HSI_TX_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_HSI_TX_CLK_SEL.
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CDCDR_HSI_TX_CLK_SEL) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CDCDR_HSI_TX_CLK_SEL.
#define BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)   (((v) << BP_CCM_CDCDR_HSI_TX_CLK_SEL) & BM_CCM_CDCDR_HSI_TX_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSI_TX_CLK_SEL field to a new value.
#define BW_CCM_CDCDR_HSI_TX_CLK_SEL(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_HSI_TX_CLK_SEL) | BF_CCM_CDCDR_HSI_TX_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CDCDR, field HSI_TX_PODF[31:29] (RW)
 *
 * Divider for hsi_tx clock podf. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4 (default)
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CDCDR_HSI_TX_PODF      (29)      //!< Bit position for CCM_CDCDR_HSI_TX_PODF.
#define BM_CCM_CDCDR_HSI_TX_PODF      (0xe0000000)  //!< Bit mask for CCM_CDCDR_HSI_TX_PODF.

//! @brief Get value of CCM_CDCDR_HSI_TX_PODF from a register value.
#define BG_CCM_CDCDR_HSI_TX_PODF(r)   (((r) & BM_CCM_CDCDR_HSI_TX_PODF) >> BP_CCM_CDCDR_HSI_TX_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CDCDR_HSI_TX_PODF.
#define BF_CCM_CDCDR_HSI_TX_PODF(v)   ((((reg32_t) v) << BP_CCM_CDCDR_HSI_TX_PODF) & BM_CCM_CDCDR_HSI_TX_PODF)
#else
//! @brief Format value for bitfield CCM_CDCDR_HSI_TX_PODF.
#define BF_CCM_CDCDR_HSI_TX_PODF(v)   (((v) << BP_CCM_CDCDR_HSI_TX_PODF) & BM_CCM_CDCDR_HSI_TX_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSI_TX_PODF field to a new value.
#define BW_CCM_CDCDR_HSI_TX_PODF(v)   (HW_CCM_CDCDR_WR((HW_CCM_CDCDR_RD() & ~BM_CCM_CDCDR_HSI_TX_PODF) | BF_CCM_CDCDR_HSI_TX_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CHSCCDR - CCM HSC Clock Divider Register (RW)
 *
 * Reset value: 0x0002a150
 *
 * The figure below represents the CCM IPU1 DI Clock Divider Register (CHSCCDR). The CHSCCDR
 * register contains bits to control the ipu di clock generation dividers. The table below provides
 * its field descriptions.
 */
typedef union _hw_ccm_chsccdr
{
    reg32_t U;
    struct _hw_ccm_chsccdr_bitfields
    {
        unsigned IPU1_DI0_CLK_SEL : 3; //!< [2:0] Selector for ipu1 di0 root clock multiplexer
        unsigned IPU1_DI0_PODF : 3; //!< [5:3] Divider for ipu1_di0 clock divider. Note: Divider should be updated when output clock is gated.
        unsigned IPU1_DI0_PRE_CLK_SEL : 3; //!< [8:6] Selector for ipu1 di0 root clock pre-multiplexer
        unsigned IPU1_DI1_CLK_SEL : 3; //!< [11:9] Selector for ipu1 di1 root clock multiplexer
        unsigned IPU1_DI1_PODF : 3; //!< [14:12] Divider for ipu1_di clock divider. Note: Divider should be updated when output clock is gated.
        unsigned IPU1_DI1_PRE_CLK_SEL : 3; //!< [17:15] Selector for ipu1 di1 root clock pre-multiplexer
        unsigned RESERVED0 : 14; //!< [31:18] Reserved
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

/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_CLK_SEL[2:0] (RW)
 *
 * Selector for ipu1 di0 root clock multiplexer
 *
 * Values:
 * 000 - derive clock from divided pre-muxed ipu1 di0 clock (Default)
 * 001 - derive clock from ipp_di0_clk
 * 010 - derive clock from ipp_di1_clk
 * 011 - derive clock from ldb_di0_clk
 * 100 - derive clock from ldb_di1_clk
 * 101-111 - Restricted
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      (0)      //!< Bit position for CCM_CHSCCDR_IPU1_DI0_CLK_SEL.
#define BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL      (0x00000007)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI0_CLK_SEL.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI0_CLK_SEL from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL) >> BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI0_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI0_CLK_SEL field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI0_CLK_SEL) | BF_CCM_CHSCCDR_IPU1_DI0_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PODF[5:3] (RW)
 *
 * Divider for ipu1_di0 clock divider. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3 (Default)
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_PODF      (3)      //!< Bit position for CCM_CHSCCDR_IPU1_DI0_PODF.
#define BM_CCM_CHSCCDR_IPU1_DI0_PODF      (0x00000038)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI0_PODF.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI0_PODF from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI0_PODF(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI0_PODF) >> BP_CCM_CHSCCDR_IPU1_DI0_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_PODF.
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI0_PODF) & BM_CCM_CHSCCDR_IPU1_DI0_PODF)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_PODF.
#define BF_CCM_CHSCCDR_IPU1_DI0_PODF(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI0_PODF) & BM_CCM_CHSCCDR_IPU1_DI0_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI0_PODF field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI0_PODF(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI0_PODF) | BF_CCM_CHSCCDR_IPU1_DI0_PODF(v)))
#endif


/* --- Register HW_CCM_CHSCCDR, field IPU1_DI0_PRE_CLK_SEL[8:6] (RW)
 *
 * Selector for ipu1 di0 root clock pre-multiplexer
 *
 * Values:
 * 000 - derive clock from mmdc_ch0 clock
 * 001 - derive clock from pll3
 * 010 - derive clock from pll5
 * 011 - derive clock from 352M 307M PFD
 * 100 - derive clock from 396M PFD
 * 101 - derive clock from 540M PFD
 * 110-111 - Restricted
 */

#define BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      (6)      //!< Bit position for CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL.
#define BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL      (0x000001c0)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL) >> BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI0_PRE_CLK_SEL field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL) | BF_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_CLK_SEL[11:9] (RW)
 *
 * Selector for ipu1 di1 root clock multiplexer
 *
 * Values:
 * 000 - derive clock from divided pre-muxed ipu1 di1 clock (Default)
 * 001 - derive clock from ipp_di0_clk
 * 010 - derive clock from ipp_di1_clk
 * 011 - derive clock from ldb_di0_clk
 * 100 - derive clock from ldb_di1_clk
 * 101-111 - Restricted
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      (9)      //!< Bit position for CCM_CHSCCDR_IPU1_DI1_CLK_SEL.
#define BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL      (0x00000e00)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI1_CLK_SEL.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI1_CLK_SEL from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL) >> BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI1_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI1_CLK_SEL field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI1_CLK_SEL) | BF_CCM_CHSCCDR_IPU1_DI1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PODF[14:12] (RW)
 *
 * Divider for ipu1_di clock divider. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3 (Default)
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_PODF      (12)      //!< Bit position for CCM_CHSCCDR_IPU1_DI1_PODF.
#define BM_CCM_CHSCCDR_IPU1_DI1_PODF      (0x00007000)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI1_PODF.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI1_PODF from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI1_PODF(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI1_PODF) >> BP_CCM_CHSCCDR_IPU1_DI1_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_PODF.
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI1_PODF) & BM_CCM_CHSCCDR_IPU1_DI1_PODF)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_PODF.
#define BF_CCM_CHSCCDR_IPU1_DI1_PODF(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI1_PODF) & BM_CCM_CHSCCDR_IPU1_DI1_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI1_PODF field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI1_PODF(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI1_PODF) | BF_CCM_CHSCCDR_IPU1_DI1_PODF(v)))
#endif


/* --- Register HW_CCM_CHSCCDR, field IPU1_DI1_PRE_CLK_SEL[17:15] (RW)
 *
 * Selector for ipu1 di1 root clock pre-multiplexer
 *
 * Values:
 * 000 - derive clock from mmdc_ch0 clock
 * 001 - derive clock from pll3
 * 010 - derive clock from pll5
 * 011 - derive clock from 352M 307M PFD
 * 100 - derive clock from 396M PFD
 * 101 - derive clock from 540M PFD
 * 110-111 - Restricted
 */

#define BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      (15)      //!< Bit position for CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL.
#define BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL      (0x00038000)  //!< Bit mask for CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL.

//! @brief Get value of CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL from a register value.
#define BG_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(r)   (((r) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL) >> BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL.
#define BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   (((v) << BP_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL) & BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_DI1_PRE_CLK_SEL field to a new value.
#define BW_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)   (HW_CCM_CHSCCDR_WR((HW_CCM_CHSCCDR_RD() & ~BM_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL) | BF_CCM_CHSCCDR_IPU1_DI1_PRE_CLK_SEL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSCDR2 - CCM Serial Clock Divider Register 2 (RW)
 *
 * Reset value: 0x0002a150
 *
 * The figure below represents the CCM Serial Clock Divider Register 2(CSCDR2). The CSCDR2 register
 * contains bits to control the clock generation sub module dividers. The table below provides its
 * field descriptions.
 */
typedef union _hw_ccm_cscdr2
{
    reg32_t U;
    struct _hw_ccm_cscdr2_bitfields
    {
        unsigned IPU2_DI0_CLK_SEL : 3; //!< [2:0] Selector for ipu2 di0 root clock multiplexer
        unsigned IPU2_DI0_PODF : 3; //!< [5:3] Divider for ipu2_di0 clock divider. Note: Divider should be updated when output clock is gated.
        unsigned IPU2_DI0_PRE_CLK_SEL : 3; //!< [8:6] Selector for ipu2 di0 root clock pre-multiplexer
        unsigned IPU2_DI1_CLK_SEL : 3; //!< [11:9] Selector for ipu1 di2 root clock multiplexer
        unsigned IPU2_DI1_PODF : 3; //!< [14:12] Divider for ipu2_di1 clock divider. Note: Divider should be updated when output clock is gated.
        unsigned IPU2_DI1_PRE_CLK_SEL : 3; //!< [17:15] Selector for ipu2 di1 root clock pre-multiplexer
        unsigned RESERVED0 : 1; //!< [18] Reserved
        unsigned ECSPI_CLK_PODF : 6; //!< [24:19] Divider for ecspi clock podf. Note: Divider should be updated when output clock is gated. Note: The input clock to this divider should be lower than 300Mhz, the predivider can be used to achieve this.
        unsigned RESERVED1 : 7; //!< [31:25] Reserved.
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

/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_CLK_SEL[2:0] (RW)
 *
 * Selector for ipu2 di0 root clock multiplexer
 *
 * Values:
 * 000 - derive clock from divided pre-muxed ipu1 di0 clock (Default)
 * 001 - derive clock from ipp_di0_clk
 * 010 - derive clock from ipp_di1_clk
 * 011 - derive clock from ldb_di0_clk
 * 100 - derive clock from ldb_di1_clk
 * 101-111 - Restricted
 */

#define BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL      (0)      //!< Bit position for CCM_CSCDR2_IPU2_DI0_CLK_SEL.
#define BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL      (0x00000007)  //!< Bit mask for CCM_CSCDR2_IPU2_DI0_CLK_SEL.

//! @brief Get value of CCM_CSCDR2_IPU2_DI0_CLK_SEL from a register value.
#define BG_CCM_CSCDR2_IPU2_DI0_CLK_SEL(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL) >> BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI0_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI0_CLK_SEL field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI0_CLK_SEL) | BF_CCM_CSCDR2_IPU2_DI0_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PODF[5:3] (RW)
 *
 * Divider for ipu2_di0 clock divider. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8 (default)
 */

#define BP_CCM_CSCDR2_IPU2_DI0_PODF      (3)      //!< Bit position for CCM_CSCDR2_IPU2_DI0_PODF.
#define BM_CCM_CSCDR2_IPU2_DI0_PODF      (0x00000038)  //!< Bit mask for CCM_CSCDR2_IPU2_DI0_PODF.

//! @brief Get value of CCM_CSCDR2_IPU2_DI0_PODF from a register value.
#define BG_CCM_CSCDR2_IPU2_DI0_PODF(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI0_PODF) >> BP_CCM_CSCDR2_IPU2_DI0_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_PODF.
#define BF_CCM_CSCDR2_IPU2_DI0_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI0_PODF) & BM_CCM_CSCDR2_IPU2_DI0_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_PODF.
#define BF_CCM_CSCDR2_IPU2_DI0_PODF(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI0_PODF) & BM_CCM_CSCDR2_IPU2_DI0_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI0_PODF field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI0_PODF(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI0_PODF) | BF_CCM_CSCDR2_IPU2_DI0_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field IPU2_DI0_PRE_CLK_SEL[8:6] (RW)
 *
 * Selector for ipu2 di0 root clock pre-multiplexer
 *
 * Values:
 * 000 - derive clock from mmdc_ch0 clock
 * 001 - derive clock from pll3 (default)
 * 010 - derive clock from pll5
 * 011 - derive clock from 352M 307M PFD
 * 100 - derive clock from 396M PFD
 * 101 - derive clock from 540M PFD
 * 110-111 - Restricted
 */

#define BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      (6)      //!< Bit position for CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL.
#define BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL      (0x000001c0)  //!< Bit mask for CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL.

//! @brief Get value of CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL from a register value.
#define BG_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL) >> BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI0_PRE_CLK_SEL field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL) | BF_CCM_CSCDR2_IPU2_DI0_PRE_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_CLK_SEL[11:9] (RW)
 *
 * Selector for ipu1 di2 root clock multiplexer
 *
 * Values:
 * 000 - derive clock from divided pre-muxed ipu1 di1 clock (Default)
 * 001 - derive clock from ipp_di0_clk
 * 010 - derive clock from ipp_di1_clk
 * 011 - derive clock from ldb_di0_clk
 * 100 - derive clock from ldb_di1_clk
 * 101-111 - Restricted
 */

#define BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL      (9)      //!< Bit position for CCM_CSCDR2_IPU2_DI1_CLK_SEL.
#define BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL      (0x00000e00)  //!< Bit mask for CCM_CSCDR2_IPU2_DI1_CLK_SEL.

//! @brief Get value of CCM_CSCDR2_IPU2_DI1_CLK_SEL from a register value.
#define BG_CCM_CSCDR2_IPU2_DI1_CLK_SEL(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL) >> BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI1_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI1_CLK_SEL field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI1_CLK_SEL) | BF_CCM_CSCDR2_IPU2_DI1_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PODF[14:12] (RW)
 *
 * Divider for ipu2_di1 clock divider. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8 (default)
 */

#define BP_CCM_CSCDR2_IPU2_DI1_PODF      (12)      //!< Bit position for CCM_CSCDR2_IPU2_DI1_PODF.
#define BM_CCM_CSCDR2_IPU2_DI1_PODF      (0x00007000)  //!< Bit mask for CCM_CSCDR2_IPU2_DI1_PODF.

//! @brief Get value of CCM_CSCDR2_IPU2_DI1_PODF from a register value.
#define BG_CCM_CSCDR2_IPU2_DI1_PODF(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI1_PODF) >> BP_CCM_CSCDR2_IPU2_DI1_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_PODF.
#define BF_CCM_CSCDR2_IPU2_DI1_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI1_PODF) & BM_CCM_CSCDR2_IPU2_DI1_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_PODF.
#define BF_CCM_CSCDR2_IPU2_DI1_PODF(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI1_PODF) & BM_CCM_CSCDR2_IPU2_DI1_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI1_PODF field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI1_PODF(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI1_PODF) | BF_CCM_CSCDR2_IPU2_DI1_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field IPU2_DI1_PRE_CLK_SEL[17:15] (RW)
 *
 * Selector for ipu2 di1 root clock pre-multiplexer
 *
 * Values:
 * 000 - derive clock from mmdc_ch0 clock
 * 001 - derive clock from pll3
 * 010 - derive clock from pll5
 * 011 - derive clock from 352M 307M PFD
 * 100 - derive clock from 396M PFD
 * 101 - derive clock from 540M PFD
 * 110-111 - Restricted
 */

#define BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      (15)      //!< Bit position for CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL.
#define BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL      (0x00038000)  //!< Bit mask for CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL.

//! @brief Get value of CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL from a register value.
#define BG_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(r)   (((r) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL) >> BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL.
#define BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   (((v) << BP_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL) & BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_DI1_PRE_CLK_SEL field to a new value.
#define BW_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL) | BF_CCM_CSCDR2_IPU2_DI1_PRE_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR2, field ECSPI_CLK_PODF[24:19] (RW)
 *
 * Divider for ecspi clock podf. Note: Divider should be updated when output clock is gated. Note:
 * The input clock to this divider should be lower than 300Mhz, the predivider can be used to
 * achieve this.
 *
 * Values:
 * 000000 - divide by 1
 * 111111 - divide by 2^6
 */

#define BP_CCM_CSCDR2_ECSPI_CLK_PODF      (19)      //!< Bit position for CCM_CSCDR2_ECSPI_CLK_PODF.
#define BM_CCM_CSCDR2_ECSPI_CLK_PODF      (0x01f80000)  //!< Bit mask for CCM_CSCDR2_ECSPI_CLK_PODF.

//! @brief Get value of CCM_CSCDR2_ECSPI_CLK_PODF from a register value.
#define BG_CCM_CSCDR2_ECSPI_CLK_PODF(r)   (((r) & BM_CCM_CSCDR2_ECSPI_CLK_PODF) >> BP_CCM_CSCDR2_ECSPI_CLK_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR2_ECSPI_CLK_PODF.
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR2_ECSPI_CLK_PODF) & BM_CCM_CSCDR2_ECSPI_CLK_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR2_ECSPI_CLK_PODF.
#define BF_CCM_CSCDR2_ECSPI_CLK_PODF(v)   (((v) << BP_CCM_CSCDR2_ECSPI_CLK_PODF) & BM_CCM_CSCDR2_ECSPI_CLK_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECSPI_CLK_PODF field to a new value.
#define BW_CCM_CSCDR2_ECSPI_CLK_PODF(v)   (HW_CCM_CSCDR2_WR((HW_CCM_CSCDR2_RD() & ~BM_CCM_CSCDR2_ECSPI_CLK_PODF) | BF_CCM_CSCDR2_ECSPI_CLK_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CSCDR3 - CCM Serial Clock Divider Register 3 (RW)
 *
 * Reset value: 0x00014841
 *
 * The figure below represents the CCM Serial Clock Divider Register 3(CSCDR3). The CSCDR3 register
 * contains bits to control the clock generation sub module dividers. The table below provides its
 * field descriptions.
 */
typedef union _hw_ccm_cscdr3
{
    reg32_t U;
    struct _hw_ccm_cscdr3_bitfields
    {
        unsigned RESERVED0 : 9; //!< [8:0] Reserved
        unsigned IPU1_HSP_CLK_SEL : 2; //!< [10:9] Selector for ipu1_hsp clock multiplexer
        unsigned IPU1_HSP_PODF : 3; //!< [13:11] Divider for ipu1_hsp clock. Note: Divider should be updated when output clock is gated.
        unsigned IPU2_HSP_CLK_SEL : 2; //!< [15:14] Selector for ipu2_hsp clock multiplexer
        unsigned IPU2_HSP_PODF : 3; //!< [18:16] Divider for ipu2_hsp clock. Note: Divider should be updated when output clock is gated.
        unsigned RESERVED1 : 13; //!< [31:19] Reserved
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

/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_CLK_SEL[10:9] (RW)
 *
 * Selector for ipu1_hsp clock multiplexer
 *
 * Values:
 * 00 - derive clock from mmdc_ch0 clock (default)
 * 01 - derive clock from 396M PFD
 * 10 - derive clock from 120M
 * 11 - derive clock from 540M PFD
 */

#define BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL      (9)      //!< Bit position for CCM_CSCDR3_IPU1_HSP_CLK_SEL.
#define BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL      (0x00000600)  //!< Bit mask for CCM_CSCDR3_IPU1_HSP_CLK_SEL.

//! @brief Get value of CCM_CSCDR3_IPU1_HSP_CLK_SEL from a register value.
#define BG_CCM_CSCDR3_IPU1_HSP_CLK_SEL(r)   (((r) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL) >> BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR3_IPU1_HSP_CLK_SEL.
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR3_IPU1_HSP_CLK_SEL.
#define BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   (((v) << BP_CCM_CSCDR3_IPU1_HSP_CLK_SEL) & BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_HSP_CLK_SEL field to a new value.
#define BW_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)   (HW_CCM_CSCDR3_WR((HW_CCM_CSCDR3_RD() & ~BM_CCM_CSCDR3_IPU1_HSP_CLK_SEL) | BF_CCM_CSCDR3_IPU1_HSP_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR3, field IPU1_HSP_PODF[13:11] (RW)
 *
 * Divider for ipu1_hsp clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR3_IPU1_HSP_PODF      (11)      //!< Bit position for CCM_CSCDR3_IPU1_HSP_PODF.
#define BM_CCM_CSCDR3_IPU1_HSP_PODF      (0x00003800)  //!< Bit mask for CCM_CSCDR3_IPU1_HSP_PODF.

//! @brief Get value of CCM_CSCDR3_IPU1_HSP_PODF from a register value.
#define BG_CCM_CSCDR3_IPU1_HSP_PODF(r)   (((r) & BM_CCM_CSCDR3_IPU1_HSP_PODF) >> BP_CCM_CSCDR3_IPU1_HSP_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR3_IPU1_HSP_PODF.
#define BF_CCM_CSCDR3_IPU1_HSP_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR3_IPU1_HSP_PODF) & BM_CCM_CSCDR3_IPU1_HSP_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR3_IPU1_HSP_PODF.
#define BF_CCM_CSCDR3_IPU1_HSP_PODF(v)   (((v) << BP_CCM_CSCDR3_IPU1_HSP_PODF) & BM_CCM_CSCDR3_IPU1_HSP_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU1_HSP_PODF field to a new value.
#define BW_CCM_CSCDR3_IPU1_HSP_PODF(v)   (HW_CCM_CSCDR3_WR((HW_CCM_CSCDR3_RD() & ~BM_CCM_CSCDR3_IPU1_HSP_PODF) | BF_CCM_CSCDR3_IPU1_HSP_PODF(v)))
#endif


/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_CLK_SEL[15:14] (RW)
 *
 * Selector for ipu2_hsp clock multiplexer
 *
 * Values:
 * 00 - derive clock from mmdc_ch0 clock (default)
 * 01 - derive clock from 396M PFD
 * 10 - derive clock from 120M
 * 11 - derive clock from 540M PFD
 */

#define BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL      (14)      //!< Bit position for CCM_CSCDR3_IPU2_HSP_CLK_SEL.
#define BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL      (0x0000c000)  //!< Bit mask for CCM_CSCDR3_IPU2_HSP_CLK_SEL.

//! @brief Get value of CCM_CSCDR3_IPU2_HSP_CLK_SEL from a register value.
#define BG_CCM_CSCDR3_IPU2_HSP_CLK_SEL(r)   (((r) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL) >> BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR3_IPU2_HSP_CLK_SEL.
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   ((((reg32_t) v) << BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL)
#else
//! @brief Format value for bitfield CCM_CSCDR3_IPU2_HSP_CLK_SEL.
#define BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   (((v) << BP_CCM_CSCDR3_IPU2_HSP_CLK_SEL) & BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_HSP_CLK_SEL field to a new value.
#define BW_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)   (HW_CCM_CSCDR3_WR((HW_CCM_CSCDR3_RD() & ~BM_CCM_CSCDR3_IPU2_HSP_CLK_SEL) | BF_CCM_CSCDR3_IPU2_HSP_CLK_SEL(v)))
#endif


/* --- Register HW_CCM_CSCDR3, field IPU2_HSP_PODF[18:16] (RW)
 *
 * Divider for ipu2_hsp clock. Note: Divider should be updated when output clock is gated.
 *
 * Values:
 * 000 - divide by 1
 * 001 - divide by 2 (Default)
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CSCDR3_IPU2_HSP_PODF      (16)      //!< Bit position for CCM_CSCDR3_IPU2_HSP_PODF.
#define BM_CCM_CSCDR3_IPU2_HSP_PODF      (0x00070000)  //!< Bit mask for CCM_CSCDR3_IPU2_HSP_PODF.

//! @brief Get value of CCM_CSCDR3_IPU2_HSP_PODF from a register value.
#define BG_CCM_CSCDR3_IPU2_HSP_PODF(r)   (((r) & BM_CCM_CSCDR3_IPU2_HSP_PODF) >> BP_CCM_CSCDR3_IPU2_HSP_PODF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CSCDR3_IPU2_HSP_PODF.
#define BF_CCM_CSCDR3_IPU2_HSP_PODF(v)   ((((reg32_t) v) << BP_CCM_CSCDR3_IPU2_HSP_PODF) & BM_CCM_CSCDR3_IPU2_HSP_PODF)
#else
//! @brief Format value for bitfield CCM_CSCDR3_IPU2_HSP_PODF.
#define BF_CCM_CSCDR3_IPU2_HSP_PODF(v)   (((v) << BP_CCM_CSCDR3_IPU2_HSP_PODF) & BM_CCM_CSCDR3_IPU2_HSP_PODF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPU2_HSP_PODF field to a new value.
#define BW_CCM_CSCDR3_IPU2_HSP_PODF(v)   (HW_CCM_CSCDR3_WR((HW_CCM_CSCDR3_RD() & ~BM_CCM_CSCDR3_IPU2_HSP_PODF) | BF_CCM_CSCDR3_IPU2_HSP_PODF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CWDR - CCM Wakeup Detector Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Wakeup Detector Register (CWDR). The CWDR register contains
 * reserved, read-only bits.The table below provides its field descriptions.
 */
typedef union _hw_ccm_cwdr
{
    reg32_t U;
    struct _hw_ccm_cwdr_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved
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

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CDHIPR - CCM Divider Handshake In-Process Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Divider Handshake In-Process Register (CDHIPR). The CDHIPR
 * register contains read only bits that indicate that CCM is in the process of updating dividers or
 * muxes that might need handshake with modules.  bit 16: This bit corresponds to the arm_podf
 * divider only if ARM dvfs operation is done through arm_podf change (arm_freq_shift_divider =
 * '1'). In this case, writing to arm_podf will commence only after assertion of arm_clk_switch_req
 * from GPC. During this period, bit 16 (arm_podf_busy) will assert to indicate that arm_podf is
 * during process of change. Software should not write new values to arm_podf during this period.
 * any reads of arm_podf during this period will result the next value of arm_podf and not the
 * actual dividers value. To read the actual dividers value , software should wait until
 * arm_podf_busy deasserts. Once the value of the indication bit changes from '1' to '0', ccm can
 * also generate interrupt, if its not masked (refer to CIMR). This bit will not assert if its not a
 * arm dvfs operation, i.e. if arm_freq_shift_divider = '0'. In this case the write to arm_podf will
 * commence once the divider is written with the new value.  bits [8-0]: The dividers in this group
 * are axi_a_podf, axi_b_podf, emi_slow_podf, ahb_podf and nfc_podf. The muxes control in this group
 * are periph_clk_sel and emi_clk_sel. For each of those dividers and muxes control, CDHIPR holds a
 * busy indication bit. If this bit is equal to 1, then ccm is in process of updating the divider or
 * mux. The corresponding bit will assert to '1' once the CBCDR register is updated and a handshake
 * is indeed needed for the update. The corresponding bit will deassert to '0' once the handshake
 * has completed and the divider or mux is loaded with the new values. Software reads of the divider
 * or mux control bits, during the time that these bits are 1, will represent the next value of the
 * divider or mux to be loaded. If software wants to read the actual divider value, it should wait
 * until the value of the indicator bit is equal 0. Once the value of the indication bit changes
 * from '1' to '0', ccm can also generate interrupt, if its not masked (refer to CIMR). The table
 * below provides its field descriptions.
 */
typedef union _hw_ccm_cdhipr
{
    reg32_t U;
    struct _hw_ccm_cdhipr_bitfields
    {
        unsigned AXI_PODF_BUSY : 1; //!< [0] Busy indicator for axi_podf.
        unsigned AHB_PODF_BUSY : 1; //!< [1] Busy indicator for ahb_podf.
        unsigned MMDC_CH1_PODF_BUSY : 1; //!< [2] Busy indicator for mmdc_ch1_axi_podf.
        unsigned PERIPH2_CLK_SEL_BUSY : 1; //!< [3] Busy indicator for periph2_clk_sel mux control.
        unsigned MMDC_CH0_PODF_BUSY : 1; //!< [4] Busy indicator for mmdc_ch0_axi_podf.
        unsigned PERIPH_CLK_SEL_BUSY : 1; //!< [5] Busy indicator for periph_clk_sel mux control.
        unsigned RESERVED0 : 10; //!< [15:6] Reserved
        unsigned ARM_PODF_BUSY : 1; //!< [16] Busy indicator for arm_podf.
        unsigned RESERVED1 : 15; //!< [31:17] Reserved
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
#endif

/*
 * constants & macros for individual CCM_CDHIPR bitfields
 */

/* --- Register HW_CCM_CDHIPR, field AXI_PODF_BUSY[0] (RO)
 *
 * Busy indicator for axi_podf.
 *
 * Values:
 * 0 - divider is not busy and its value represents the actual division.
 * 1 - divider is busy with handshake process with module. The value read in the divider represents the
 *     previous value odivision factor, and after the handshake the written value of the axi_podf
 *     will be applied.
 */

#define BP_CCM_CDHIPR_AXI_PODF_BUSY      (0)      //!< Bit position for CCM_CDHIPR_AXI_PODF_BUSY.
#define BM_CCM_CDHIPR_AXI_PODF_BUSY      (0x00000001)  //!< Bit mask for CCM_CDHIPR_AXI_PODF_BUSY.

//! @brief Get value of CCM_CDHIPR_AXI_PODF_BUSY from a register value.
#define BG_CCM_CDHIPR_AXI_PODF_BUSY(r)   (((r) & BM_CCM_CDHIPR_AXI_PODF_BUSY) >> BP_CCM_CDHIPR_AXI_PODF_BUSY)


/* --- Register HW_CCM_CDHIPR, field AHB_PODF_BUSY[1] (RO)
 *
 * Busy indicator for ahb_podf.
 *
 * Values:
 * 0 - divider is not busy and its value represents the actual division.
 * 1 - divider is busy with handshake process with module. The value read in the divider represents the
 *     previous value odivision factor, and after the handshake the written value of the ahb_podf
 *     will be applied.
 */

#define BP_CCM_CDHIPR_AHB_PODF_BUSY      (1)      //!< Bit position for CCM_CDHIPR_AHB_PODF_BUSY.
#define BM_CCM_CDHIPR_AHB_PODF_BUSY      (0x00000002)  //!< Bit mask for CCM_CDHIPR_AHB_PODF_BUSY.

//! @brief Get value of CCM_CDHIPR_AHB_PODF_BUSY from a register value.
#define BG_CCM_CDHIPR_AHB_PODF_BUSY(r)   (((r) & BM_CCM_CDHIPR_AHB_PODF_BUSY) >> BP_CCM_CDHIPR_AHB_PODF_BUSY)


/* --- Register HW_CCM_CDHIPR, field MMDC_CH1_PODF_BUSY[2] (RO)
 *
 * Busy indicator for mmdc_ch1_axi_podf.
 *
 * Values:
 * 0 - divider is not busy and its value represents the actual division.
 * 1 - divider is busy with handshake process with module. The value read in the divider represents the
 *     previous value odivision factor, and after the handshake the written value of the
 *     mmdc_ch1_axi_podf will be applied.
 */

#define BP_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      (2)      //!< Bit position for CCM_CDHIPR_MMDC_CH1_PODF_BUSY.
#define BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY      (0x00000004)  //!< Bit mask for CCM_CDHIPR_MMDC_CH1_PODF_BUSY.

//! @brief Get value of CCM_CDHIPR_MMDC_CH1_PODF_BUSY from a register value.
#define BG_CCM_CDHIPR_MMDC_CH1_PODF_BUSY(r)   (((r) & BM_CCM_CDHIPR_MMDC_CH1_PODF_BUSY) >> BP_CCM_CDHIPR_MMDC_CH1_PODF_BUSY)


/* --- Register HW_CCM_CDHIPR, field PERIPH2_CLK_SEL_BUSY[3] (RO)
 *
 * Busy indicator for periph2_clk_sel mux control.
 *
 * Values:
 * 0 - mux is not busy and its value represents the actual division.
 * 1 - mux is busy with handshake process with module. The value read in the periph2_clk_sel represents the
 *     previous value of select, and after the handshake periph2_clk_sel value will be applied.
 */

#define BP_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      (3)      //!< Bit position for CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY.
#define BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY      (0x00000008)  //!< Bit mask for CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY.

//! @brief Get value of CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY from a register value.
#define BG_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY(r)   (((r) & BM_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY) >> BP_CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY)


/* --- Register HW_CCM_CDHIPR, field MMDC_CH0_PODF_BUSY[4] (RO)
 *
 * Busy indicator for mmdc_ch0_axi_podf.
 *
 * Values:
 * 0 - divider is not busy and its value represents the actual division.
 * 1 - divider is busy with handshake process with module. The value read in the divider represents the
 *     previous value odivision factor, and after the handshake the written value of the
 *     mmdc_ch0_axi_podf will be applied.
 */

#define BP_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      (4)      //!< Bit position for CCM_CDHIPR_MMDC_CH0_PODF_BUSY.
#define BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY      (0x00000010)  //!< Bit mask for CCM_CDHIPR_MMDC_CH0_PODF_BUSY.

//! @brief Get value of CCM_CDHIPR_MMDC_CH0_PODF_BUSY from a register value.
#define BG_CCM_CDHIPR_MMDC_CH0_PODF_BUSY(r)   (((r) & BM_CCM_CDHIPR_MMDC_CH0_PODF_BUSY) >> BP_CCM_CDHIPR_MMDC_CH0_PODF_BUSY)


/* --- Register HW_CCM_CDHIPR, field PERIPH_CLK_SEL_BUSY[5] (RO)
 *
 * Busy indicator for periph_clk_sel mux control.
 *
 * Values:
 * 0 - mux is not busy and its value represents the actual division.
 * 1 - mux is busy with handshake process with module. The value read in the periph_clk_sel represents the
 *     previous value of select, and after the handshake periph_clk_sel value will be applied.
 */

#define BP_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      (5)      //!< Bit position for CCM_CDHIPR_PERIPH_CLK_SEL_BUSY.
#define BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY      (0x00000020)  //!< Bit mask for CCM_CDHIPR_PERIPH_CLK_SEL_BUSY.

//! @brief Get value of CCM_CDHIPR_PERIPH_CLK_SEL_BUSY from a register value.
#define BG_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY(r)   (((r) & BM_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY) >> BP_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY)


/* --- Register HW_CCM_CDHIPR, field ARM_PODF_BUSY[16] (RO)
 *
 * Busy indicator for arm_podf.
 *
 * Values:
 * 0 - divider is not busy and its value represents the actual division.
 * 1 - divider is busy with handshake process with module. The value read in the divider represents the
 *     previous value odivision factor, and after the handshake the written value of the arm_podf
 *     will be applied.
 */

#define BP_CCM_CDHIPR_ARM_PODF_BUSY      (16)      //!< Bit position for CCM_CDHIPR_ARM_PODF_BUSY.
#define BM_CCM_CDHIPR_ARM_PODF_BUSY      (0x00010000)  //!< Bit mask for CCM_CDHIPR_ARM_PODF_BUSY.

//! @brief Get value of CCM_CDHIPR_ARM_PODF_BUSY from a register value.
#define BG_CCM_CDHIPR_ARM_PODF_BUSY(r)   (((r) & BM_CCM_CDHIPR_ARM_PODF_BUSY) >> BP_CCM_CDHIPR_ARM_PODF_BUSY)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CTOR - CCM Testing Observability Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Testing Observability Register (CTOR). CCM includes three
 * muxes to mux between different critical signals for testing observability. The output of the
 * three muxes is generated on the three output signals obs_output_0, obs_output_1 and obs_output_2.
 * Those three output signals can be generated on the IC pads by configuring the IOMUXC. The CTOR
 * register contains bits to control the data generated for observability on the three output
 * signals above. The table below provides its field descriptions.
 */
typedef union _hw_ccm_ctor
{
    reg32_t U;
    struct _hw_ccm_ctor_bitfields
    {
        unsigned OBS_SPARE_OUTPUT_2_SEL : 4; //!< [3:0] Selection of the signal to be generated on obs_output_2 (output of CCM) for observability on the pads.
        unsigned OBS_SPARE_OUTPUT_1_SEL : 4; //!< [7:4] Selection of the signal to be generated on obs_output_1 (output of CCM) for observability on the pads.
        unsigned OBS_SPARE_OUTPUT_0_SEL : 5; //!< [12:8] Selection of the signal to be generated on obs_output_0 (output of CCM) for observability on the pads.
        unsigned OBS_EN : 1; //!< [13] observability enable bit. this bit enables the output of the three observability muxes.
        unsigned RESERVED0 : 18; //!< [31:14] Reserved
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

/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_2_SEL[3:0] (RW)
 *
 * Selection of the signal to be generated on obs_output_2 (output of CCM) for observability on the
 * pads.
 *
 * Values:
 * 0000 - ccm_int_mem_ipg_stop
 * 0001 - lpm_current_state[2]
 * 0010 - hndsk_current_state[2]
 * 0011 - shd_current_state[1]
 * 0100 - Reserved
 * 0101 - src_clock_ready
 * 0110 - ref_clk_en_dpllip
 * 0111 - ccm_pup_req
 * 1000 - mmdc_ch0_stop_ack (lpack)
 * 1001 - mmdc_ch1_stop_ack (lpack):
 * 1010 - Reserved
 * 1011 - Reserved
 * 1100 - src_power_gating_reset_done
 * 1101 - tzic_dsm_wakeup
 * 1110 - gpc_pdn_ack
 * 1111 - pll_lrf_sticky3
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      (0)      //!< Bit position for CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL.
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL      (0x0000000f)  //!< Bit mask for CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL.

//! @brief Get value of CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL from a register value.
#define BG_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(r)   (((r) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL) >> BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   ((((reg32_t) v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#else
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   (((v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OBS_SPARE_OUTPUT_2_SEL field to a new value.
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)   (HW_CCM_CTOR_WR((HW_CCM_CTOR_RD() & ~BM_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL) | BF_CCM_CTOR_OBS_SPARE_OUTPUT_2_SEL(v)))
#endif


/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_1_SEL[7:4] (RW)
 *
 * Selection of the signal to be generated on obs_output_1 (output of CCM) for observability on the
 * pads.
 *
 * Values:
 * 0000 - ccm_system_in_wait_mode
 * 0001 - lpm_current_state[1]
 * 0010 - hndsk_current_state[1]
 * 0011 - Reserved
 * 0100 - ccm_ipg_wait
 * 0101 - Reserved
 * 0110 - dpll_en_dpllip
 * 0111 - ccm_pdn_4all_req
 * 1000 - emi_freq_change_ack
 * 1001 - ipu_freq_change_ack
 * 1010 - pll_lrf_sticky4
 * 1011 - Reserved
 * 1100 - arm_dsm_request
 * 1101 - Reserved
 * 1110 - gpc_pup_ack
 * 1111 - pll_lrf_sticky2
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      (4)      //!< Bit position for CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL.
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL      (0x000000f0)  //!< Bit mask for CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL.

//! @brief Get value of CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL from a register value.
#define BG_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(r)   (((r) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL) >> BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   ((((reg32_t) v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#else
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   (((v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OBS_SPARE_OUTPUT_1_SEL field to a new value.
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)   (HW_CCM_CTOR_WR((HW_CCM_CTOR_RD() & ~BM_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL) | BF_CCM_CTOR_OBS_SPARE_OUTPUT_1_SEL(v)))
#endif


/* --- Register HW_CCM_CTOR, field OBS_SPARE_OUTPUT_0_SEL[12:8] (RW)
 *
 * Selection of the signal to be generated on obs_output_0 (output of CCM) for observability on the
 * pads.
 *
 * Values:
 * 00000 - ccm_system_in_stop_mode
 * 00001 - lpm_current_state[0]
 * 00010 - hndsk_current_state[0]
 * 00011 - shd_current_state[0]
 * 00100 - ccm_ipg_stop
 * 00101 - ccm_pdn_4arm_req
 * 00110 - mmdc_ch0_clk_change_req
 * 00111 - mmdc_ch1_clk_change_req
 * 01000 - Reserved
 * 01001 - Reserved
 * 01010 - pll_lrf_sticky1
 * 01011 - Reserved
 * 01100 - clk_src_on
 * 01101 - ipu_lpsr_wakeup_ack
 * 01110 - src_warm_dvfs_req
 * 01111 - Reserved
 * 10000 - Reserved
 * 10001 - Reserved
 * 10010 - Reserved
 * 10011 - mmdc_ch0/1_lpmd
 * 10100 - Reserved
 * 10101 - Reserved
 * 10110 - Reserved
 * 10111 - Reserved
 * 11000 - Reserved
 * 11001 - obs_input_6
 * 11010 - obs_input_0
 * 11011 - obs_input_1
 * 11100 - obs_input_2
 * 11101 - obs_input_3
 * 11110 - obs_input_4
 * 11111 - obs_input_5
 */

#define BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      (8)      //!< Bit position for CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL.
#define BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL      (0x00001f00)  //!< Bit mask for CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL.

//! @brief Get value of CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL from a register value.
#define BG_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(r)   (((r) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL) >> BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   ((((reg32_t) v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#else
//! @brief Format value for bitfield CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL.
#define BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   (((v) << BP_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL) & BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OBS_SPARE_OUTPUT_0_SEL field to a new value.
#define BW_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)   (HW_CCM_CTOR_WR((HW_CCM_CTOR_RD() & ~BM_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL) | BF_CCM_CTOR_OBS_SPARE_OUTPUT_0_SEL(v)))
#endif


/* --- Register HW_CCM_CTOR, field OBS_EN[13] (RW)
 *
 * observability enable bit. this bit enables the output of the three observability muxes.
 *
 * Values:
 * 0 - Observability mux disabled.
 * 1 - Observability mux enabled.
 */

#define BP_CCM_CTOR_OBS_EN      (13)      //!< Bit position for CCM_CTOR_OBS_EN.
#define BM_CCM_CTOR_OBS_EN      (0x00002000)  //!< Bit mask for CCM_CTOR_OBS_EN.

//! @brief Get value of CCM_CTOR_OBS_EN from a register value.
#define BG_CCM_CTOR_OBS_EN(r)   (((r) & BM_CCM_CTOR_OBS_EN) >> BP_CCM_CTOR_OBS_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CTOR_OBS_EN.
#define BF_CCM_CTOR_OBS_EN(v)   ((((reg32_t) v) << BP_CCM_CTOR_OBS_EN) & BM_CCM_CTOR_OBS_EN)
#else
//! @brief Format value for bitfield CCM_CTOR_OBS_EN.
#define BF_CCM_CTOR_OBS_EN(v)   (((v) << BP_CCM_CTOR_OBS_EN) & BM_CCM_CTOR_OBS_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OBS_EN field to a new value.
#define BW_CCM_CTOR_OBS_EN(v)   (HW_CCM_CTOR_WR((HW_CCM_CTOR_RD() & ~BM_CCM_CTOR_OBS_EN) | BF_CCM_CTOR_OBS_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CLPCR - CCM Low Power Control Register (RW)
 *
 * Reset value: 0x00000079
 *
 * The figure below represents the CCM Low Power Control Register (CLPCR). The CLPCR register
 * contains bits to control the low power modes operation.The table below provides its field
 * descriptions.
 */
typedef union _hw_ccm_clpcr
{
    reg32_t U;
    struct _hw_ccm_clpcr_bitfields
    {
        unsigned LPM : 2; //!< [1:0] Setting the low power mode that system will enter on next assertion of dsm_request signal.
        unsigned BYPASS_PMIC_VFUNCTIONAL_READY : 1; //!< [2] By asserting this bit CCM will bypass waiting for pmic_vfunctional_ready signal when coming out of STOP mode. This should be used for PMIC's that don't support the pmic_vfunctional_ready signal.
        unsigned RESERVED0 : 2; //!< [4:3] Reserved
        unsigned ARM_CLK_DIS_ON_LPM : 1; //!< [5] Define if ARM clocks (arm_clk, soc_mxclk, soc_pclk, soc_dbg_pclk, vl_wrck) will be disabled on wait mode. This is useful for debug mode, when the user still wants to simulate entering wait mode and still keep ARM clock functioning. Note: software should not enable ARM power gating in wait mode if this bit is cleared.
        unsigned SBYOS : 1; //!< [6] Standby clock oscillator bit. This bit defines if cosc_pwrdown, which power down the on chip oscillator, will be asserted in stop mode. This bit is discarded if cosc_pwrdown='1' for the on chip oscillator.
        unsigned DIS_REF_OSC : 1; //!< [7] dis_ref_osc - in run mode, software can manually control closing of external reference oscillator clock, i.e. generating '1' on ref_en_b signal. If software closed manually the external reference clock, then sbyos functionality will be bypassed. The manual closing of external reference oscilator should be performed only in case the reference oscilator is not the source of any clock generation. Note: When returning from stop mode, the PMIC_VSTBY_REQ will be deasserted (if it was asserted when entering stop mode), and CCM will wait for indication that functional voltage is ready (by sampling the assertion of pmic_vfuncional_ready) before continuing the process of exiting from stop mode. Please refer to stby_count bits.
        unsigned VSTBY : 1; //!< [8] Voltage standby request bit. This bit defines if PMIC_VSTBY_REQ pin, which notifies external power management IC to move from functional voltage to standby voltage, will be asserted in stop mode.
        unsigned STBY_COUNT : 2; //!< [10:9] Standby counter definition. These two bits define, in the case of stop exit (if vstby bit was set), the amount of time CCM will wait between PMIC_VSTBY_REQ negation and the check of assertion of PMIC_VFUNCIONAL_READY . *NOTE: clock cycles ratio depends on pmic_delay_scaler, defined by CGPR[0] bit.
        unsigned COSC_PWRDOWN : 1; //!< [11] In run mode, software can manually control powering down of on chip oscillator, i.e. generating '1' on cosc_pwrdown signal. If software manually powered down the on chip oscillator, then sbyos functionality for on chip oscillator will be bypassed. The manual closing of onchip oscillator should be performed only in case the reference oscilator is not the source of all the clocks generation.
        unsigned RESERVED1 : 4; //!< [15:12] Reserved
        unsigned WB_PER_AT_LPM : 1; //!< [16] Enable periphery charge pump for well biasign at low power mode (stop or wait)
        unsigned WB_CORE_AT_LPM : 1; //!< [17] Enable core charge pump for well biasign at low power mode (stop or wait)
        unsigned RESERVED2 : 1; //!< [18] Reserved
        unsigned BYPASS_MMDC_CH0_LPM_HS : 1; //!< [19] Bypass handshake with mmdc_ch0 on next entrance to low power mode (wait or stop mode). CCM does not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to gate fast mmdc_ch0 clock.
        unsigned RESERVED3 : 1; //!< [20] Reserved
        unsigned BYPASS_MMDC_CH1_LPM_HS : 1; //!< [21] Bypass handshake with mmdc_ch1 on next entrance to low power mode (wait or stop mode). CCM does not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to gate fast mmdc_ch1 clock.
        unsigned MASK_CORE0_WFI : 1; //!< [22] Mask WFI of core0 for entering low power mode Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE1_WFI : 1; //!< [23] Mask WFI of core1 for entering low power mode Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE2_WFI : 1; //!< [24] Mask WFI of core2 for entering low power mode Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_CORE3_WFI : 1; //!< [25] Mask WFI of core3 for entering low power mode Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_SCU_IDLE : 1; //!< [26] Mask SCU IDLE for entering low power mode Note: assertion of all bits[27:22] will generate low power mode request
        unsigned MASK_L2CC_IDLE : 1; //!< [27] Mask L2CC IDLE for entering low power mode. Note: assertion of all bits[27:22] will generate low power mode request
        unsigned RESERVED4 : 4; //!< [31:28] Reserved
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

/* --- Register HW_CCM_CLPCR, field LPM[1:0] (RW)
 *
 * Setting the low power mode that system will enter on next assertion of dsm_request signal.
 *
 * Values:
 * 00 - Remain in run mode
 * 01 - Transfer to wait mode
 * 10 - Transfer to stop mode
 * 11 - Reserved
 */

#define BP_CCM_CLPCR_LPM      (0)      //!< Bit position for CCM_CLPCR_LPM.
#define BM_CCM_CLPCR_LPM      (0x00000003)  //!< Bit mask for CCM_CLPCR_LPM.

//! @brief Get value of CCM_CLPCR_LPM from a register value.
#define BG_CCM_CLPCR_LPM(r)   (((r) & BM_CCM_CLPCR_LPM) >> BP_CCM_CLPCR_LPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_LPM.
#define BF_CCM_CLPCR_LPM(v)   ((((reg32_t) v) << BP_CCM_CLPCR_LPM) & BM_CCM_CLPCR_LPM)
#else
//! @brief Format value for bitfield CCM_CLPCR_LPM.
#define BF_CCM_CLPCR_LPM(v)   (((v) << BP_CCM_CLPCR_LPM) & BM_CCM_CLPCR_LPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPM field to a new value.
#define BW_CCM_CLPCR_LPM(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_LPM) | BF_CCM_CLPCR_LPM(v)))
#endif


/* --- Register HW_CCM_CLPCR, field BYPASS_PMIC_VFUNCTIONAL_READY[2] (RW)
 *
 * By asserting this bit CCM will bypass waiting for pmic_vfunctional_ready signal when coming out
 * of STOP mode. This should be used for PMIC's that don't support the pmic_vfunctional_ready
 * signal.
 *
 * Values:
 * 0 - Don't bypass the pmic_vfunctional_ready signal - CCM will wait for it's assertion during exit of low
 *     power mode if stadby voltage was enabled.
 * 1 - bypass the pmic_vfunctional_ready signal - CCM will not wait for it's assertion during exit of low
 *     power mode if stadby voltage was enabled.
 */

#define BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      (2)      //!< Bit position for CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY.
#define BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY      (0x00000004)  //!< Bit mask for CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY.

//! @brief Get value of CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY from a register value.
#define BG_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(r)   (((r) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY) >> BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY.
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   ((((reg32_t) v) << BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#else
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY.
#define BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   (((v) << BP_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY) & BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_PMIC_VFUNCTIONAL_READY field to a new value.
#define BW_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY) | BF_CCM_CLPCR_BYPASS_PMIC_VFUNCTIONAL_READY(v)))
#endif


/* --- Register HW_CCM_CLPCR, field ARM_CLK_DIS_ON_LPM[5] (RW)
 *
 * Define if ARM clocks (arm_clk, soc_mxclk, soc_pclk, soc_dbg_pclk, vl_wrck) will be disabled on
 * wait mode. This is useful for debug mode, when the user still wants to simulate entering wait
 * mode and still keep ARM clock functioning. Note: software should not enable ARM power gating in
 * wait mode if this bit is cleared.
 *
 * Values:
 * 0 - ARM clock enabled on wait mode.
 * 1 - ARM clock disabled on wait mode. (default).
 */

#define BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      (5)      //!< Bit position for CCM_CLPCR_ARM_CLK_DIS_ON_LPM.
#define BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM      (0x00000020)  //!< Bit mask for CCM_CLPCR_ARM_CLK_DIS_ON_LPM.

//! @brief Get value of CCM_CLPCR_ARM_CLK_DIS_ON_LPM from a register value.
#define BG_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(r)   (((r) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM) >> BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_ARM_CLK_DIS_ON_LPM.
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   ((((reg32_t) v) << BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#else
//! @brief Format value for bitfield CCM_CLPCR_ARM_CLK_DIS_ON_LPM.
#define BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   (((v) << BP_CCM_CLPCR_ARM_CLK_DIS_ON_LPM) & BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARM_CLK_DIS_ON_LPM field to a new value.
#define BW_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_ARM_CLK_DIS_ON_LPM) | BF_CCM_CLPCR_ARM_CLK_DIS_ON_LPM(v)))
#endif


/* --- Register HW_CCM_CLPCR, field SBYOS[6] (RW)
 *
 * Standby clock oscillator bit. This bit defines if cosc_pwrdown, which power down the on chip
 * oscillator, will be asserted in stop mode. This bit is discarded if cosc_pwrdown='1' for the on
 * chip oscillator.
 *
 * Values:
 * 0 - on chip oscillator will not be powered down, after next entrance to stop mode. (ref_en_b will remain
 *     asserted - '0' and cosc_pwrdown will remain de asserted - '0')
 * 1 - on chip oscillator will be powered down, after next entrance to stop mode. (ref_en_b will be
 *     deasserted - '1' and cosc_pwrdown will be asserted - '1'). (default). When returning from
 *     stop mode, external oscillator will be enabled again, on chip oscillator will return to
 *     oscillator mode , and after oscnt count ccm will continue with the exit from stop mode
 *     process.
 */

#define BP_CCM_CLPCR_SBYOS      (6)      //!< Bit position for CCM_CLPCR_SBYOS.
#define BM_CCM_CLPCR_SBYOS      (0x00000040)  //!< Bit mask for CCM_CLPCR_SBYOS.

//! @brief Get value of CCM_CLPCR_SBYOS from a register value.
#define BG_CCM_CLPCR_SBYOS(r)   (((r) & BM_CCM_CLPCR_SBYOS) >> BP_CCM_CLPCR_SBYOS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_SBYOS.
#define BF_CCM_CLPCR_SBYOS(v)   ((((reg32_t) v) << BP_CCM_CLPCR_SBYOS) & BM_CCM_CLPCR_SBYOS)
#else
//! @brief Format value for bitfield CCM_CLPCR_SBYOS.
#define BF_CCM_CLPCR_SBYOS(v)   (((v) << BP_CCM_CLPCR_SBYOS) & BM_CCM_CLPCR_SBYOS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SBYOS field to a new value.
#define BW_CCM_CLPCR_SBYOS(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_SBYOS) | BF_CCM_CLPCR_SBYOS(v)))
#endif


/* --- Register HW_CCM_CLPCR, field DIS_REF_OSC[7] (RW)
 *
 * dis_ref_osc - in run mode, software can manually control closing of external reference oscillator
 * clock, i.e. generating '1' on ref_en_b signal. If software closed manually the external reference
 * clock, then sbyos functionality will be bypassed. The manual closing of external reference
 * oscilator should be performed only in case the reference oscilator is not the source of any clock
 * generation. Note: When returning from stop mode, the PMIC_VSTBY_REQ will be deasserted (if it was
 * asserted when entering stop mode), and CCM will wait for indication that functional voltage is
 * ready (by sampling the assertion of pmic_vfuncional_ready) before continuing the process of
 * exiting from stop mode. Please refer to stby_count bits.
 *
 * Values:
 * 0 - external high frequency oscillator will be enabled, i.e. ref_en_b = '0'.(default)
 * 1 - external high frequency oscillator will be disabled, i.e. ref_en_b = '1'
 */

#define BP_CCM_CLPCR_DIS_REF_OSC      (7)      //!< Bit position for CCM_CLPCR_DIS_REF_OSC.
#define BM_CCM_CLPCR_DIS_REF_OSC      (0x00000080)  //!< Bit mask for CCM_CLPCR_DIS_REF_OSC.

//! @brief Get value of CCM_CLPCR_DIS_REF_OSC from a register value.
#define BG_CCM_CLPCR_DIS_REF_OSC(r)   (((r) & BM_CCM_CLPCR_DIS_REF_OSC) >> BP_CCM_CLPCR_DIS_REF_OSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_DIS_REF_OSC.
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   ((((reg32_t) v) << BP_CCM_CLPCR_DIS_REF_OSC) & BM_CCM_CLPCR_DIS_REF_OSC)
#else
//! @brief Format value for bitfield CCM_CLPCR_DIS_REF_OSC.
#define BF_CCM_CLPCR_DIS_REF_OSC(v)   (((v) << BP_CCM_CLPCR_DIS_REF_OSC) & BM_CCM_CLPCR_DIS_REF_OSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS_REF_OSC field to a new value.
#define BW_CCM_CLPCR_DIS_REF_OSC(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_DIS_REF_OSC) | BF_CCM_CLPCR_DIS_REF_OSC(v)))
#endif


/* --- Register HW_CCM_CLPCR, field VSTBY[8] (RW)
 *
 * Voltage standby request bit. This bit defines if PMIC_VSTBY_REQ pin, which notifies external
 * power management IC to move from functional voltage to standby voltage, will be asserted in stop
 * mode.
 *
 * Values:
 * 0 - voltage will not be changed to standby voltage after next entrance to stop mode. ( PMIC_VSTBY_REQ
 *     will remain negated - '0')
 * 1 - voltage will be requested to change to standby voltage after next entrance to stop mode. (
 *     PMIC_VSTBY_REQ will be asserted - '1').
 */

#define BP_CCM_CLPCR_VSTBY      (8)      //!< Bit position for CCM_CLPCR_VSTBY.
#define BM_CCM_CLPCR_VSTBY      (0x00000100)  //!< Bit mask for CCM_CLPCR_VSTBY.

//! @brief Get value of CCM_CLPCR_VSTBY from a register value.
#define BG_CCM_CLPCR_VSTBY(r)   (((r) & BM_CCM_CLPCR_VSTBY) >> BP_CCM_CLPCR_VSTBY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_VSTBY.
#define BF_CCM_CLPCR_VSTBY(v)   ((((reg32_t) v) << BP_CCM_CLPCR_VSTBY) & BM_CCM_CLPCR_VSTBY)
#else
//! @brief Format value for bitfield CCM_CLPCR_VSTBY.
#define BF_CCM_CLPCR_VSTBY(v)   (((v) << BP_CCM_CLPCR_VSTBY) & BM_CCM_CLPCR_VSTBY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSTBY field to a new value.
#define BW_CCM_CLPCR_VSTBY(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_VSTBY) | BF_CCM_CLPCR_VSTBY(v)))
#endif


/* --- Register HW_CCM_CLPCR, field STBY_COUNT[10:9] (RW)
 *
 * Standby counter definition. These two bits define, in the case of stop exit (if vstby bit was
 * set), the amount of time CCM will wait between PMIC_VSTBY_REQ negation and the check of assertion
 * of PMIC_VFUNCIONAL_READY . *NOTE: clock cycles ratio depends on pmic_delay_scaler, defined by
 * CGPR[0] bit.
 *
 * Values:
 * 00 - CCM will wait (1*pmic_delay_scaler)+1 ckil clock cycles
 * 01 - CCM will wait (3*pmic_delay_scaler)+1 ckil clock cycles
 * 10 - CCM will wait (7*pmic_delay_scaler)+1 ckil clock cycles
 * 11 - CCM will wait (15*pmic_delay_scaler)+1 ckil clock cycles
 */

#define BP_CCM_CLPCR_STBY_COUNT      (9)      //!< Bit position for CCM_CLPCR_STBY_COUNT.
#define BM_CCM_CLPCR_STBY_COUNT      (0x00000600)  //!< Bit mask for CCM_CLPCR_STBY_COUNT.

//! @brief Get value of CCM_CLPCR_STBY_COUNT from a register value.
#define BG_CCM_CLPCR_STBY_COUNT(r)   (((r) & BM_CCM_CLPCR_STBY_COUNT) >> BP_CCM_CLPCR_STBY_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_STBY_COUNT.
#define BF_CCM_CLPCR_STBY_COUNT(v)   ((((reg32_t) v) << BP_CCM_CLPCR_STBY_COUNT) & BM_CCM_CLPCR_STBY_COUNT)
#else
//! @brief Format value for bitfield CCM_CLPCR_STBY_COUNT.
#define BF_CCM_CLPCR_STBY_COUNT(v)   (((v) << BP_CCM_CLPCR_STBY_COUNT) & BM_CCM_CLPCR_STBY_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STBY_COUNT field to a new value.
#define BW_CCM_CLPCR_STBY_COUNT(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_STBY_COUNT) | BF_CCM_CLPCR_STBY_COUNT(v)))
#endif


/* --- Register HW_CCM_CLPCR, field COSC_PWRDOWN[11] (RW)
 *
 * In run mode, software can manually control powering down of on chip oscillator, i.e. generating
 * '1' on cosc_pwrdown signal. If software manually powered down the on chip oscillator, then sbyos
 * functionality for on chip oscillator will be bypassed. The manual closing of onchip oscillator
 * should be performed only in case the reference oscilator is not the source of all the clocks
 * generation.
 *
 * Values:
 * 0 - On chip oscillator will not be powered down, i.e. cosc_pwrdown = '0'.(default)
 * 1 - On chip oscillator will be powered down, i.e. cosc_pwrdown = '1'.
 */

#define BP_CCM_CLPCR_COSC_PWRDOWN      (11)      //!< Bit position for CCM_CLPCR_COSC_PWRDOWN.
#define BM_CCM_CLPCR_COSC_PWRDOWN      (0x00000800)  //!< Bit mask for CCM_CLPCR_COSC_PWRDOWN.

//! @brief Get value of CCM_CLPCR_COSC_PWRDOWN from a register value.
#define BG_CCM_CLPCR_COSC_PWRDOWN(r)   (((r) & BM_CCM_CLPCR_COSC_PWRDOWN) >> BP_CCM_CLPCR_COSC_PWRDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_COSC_PWRDOWN.
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   ((((reg32_t) v) << BP_CCM_CLPCR_COSC_PWRDOWN) & BM_CCM_CLPCR_COSC_PWRDOWN)
#else
//! @brief Format value for bitfield CCM_CLPCR_COSC_PWRDOWN.
#define BF_CCM_CLPCR_COSC_PWRDOWN(v)   (((v) << BP_CCM_CLPCR_COSC_PWRDOWN) & BM_CCM_CLPCR_COSC_PWRDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COSC_PWRDOWN field to a new value.
#define BW_CCM_CLPCR_COSC_PWRDOWN(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_COSC_PWRDOWN) | BF_CCM_CLPCR_COSC_PWRDOWN(v)))
#endif


/* --- Register HW_CCM_CLPCR, field WB_PER_AT_LPM[16] (RW)
 *
 * Enable periphery charge pump for well biasign at low power mode (stop or wait)
 *
 * Values:
 * 0 - Periphery charge pump won't be enabled at stop or wait low power mode
 * 1 - Periphery charge pump will be enabled at stop or wait low power mode
 */

#define BP_CCM_CLPCR_WB_PER_AT_LPM      (16)      //!< Bit position for CCM_CLPCR_WB_PER_AT_LPM.
#define BM_CCM_CLPCR_WB_PER_AT_LPM      (0x00010000)  //!< Bit mask for CCM_CLPCR_WB_PER_AT_LPM.

//! @brief Get value of CCM_CLPCR_WB_PER_AT_LPM from a register value.
#define BG_CCM_CLPCR_WB_PER_AT_LPM(r)   (((r) & BM_CCM_CLPCR_WB_PER_AT_LPM) >> BP_CCM_CLPCR_WB_PER_AT_LPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_WB_PER_AT_LPM.
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   ((((reg32_t) v) << BP_CCM_CLPCR_WB_PER_AT_LPM) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#else
//! @brief Format value for bitfield CCM_CLPCR_WB_PER_AT_LPM.
#define BF_CCM_CLPCR_WB_PER_AT_LPM(v)   (((v) << BP_CCM_CLPCR_WB_PER_AT_LPM) & BM_CCM_CLPCR_WB_PER_AT_LPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_PER_AT_LPM field to a new value.
#define BW_CCM_CLPCR_WB_PER_AT_LPM(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_WB_PER_AT_LPM) | BF_CCM_CLPCR_WB_PER_AT_LPM(v)))
#endif


/* --- Register HW_CCM_CLPCR, field WB_CORE_AT_LPM[17] (RW)
 *
 * Enable core charge pump for well biasign at low power mode (stop or wait)
 *
 * Values:
 * 0 - Core charge pump won't be enabled at stop or wait low power mode
 * 1 - Core charge pump will be enabled at stop or wait low power mode
 */

#define BP_CCM_CLPCR_WB_CORE_AT_LPM      (17)      //!< Bit position for CCM_CLPCR_WB_CORE_AT_LPM.
#define BM_CCM_CLPCR_WB_CORE_AT_LPM      (0x00020000)  //!< Bit mask for CCM_CLPCR_WB_CORE_AT_LPM.

//! @brief Get value of CCM_CLPCR_WB_CORE_AT_LPM from a register value.
#define BG_CCM_CLPCR_WB_CORE_AT_LPM(r)   (((r) & BM_CCM_CLPCR_WB_CORE_AT_LPM) >> BP_CCM_CLPCR_WB_CORE_AT_LPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_WB_CORE_AT_LPM.
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   ((((reg32_t) v) << BP_CCM_CLPCR_WB_CORE_AT_LPM) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#else
//! @brief Format value for bitfield CCM_CLPCR_WB_CORE_AT_LPM.
#define BF_CCM_CLPCR_WB_CORE_AT_LPM(v)   (((v) << BP_CCM_CLPCR_WB_CORE_AT_LPM) & BM_CCM_CLPCR_WB_CORE_AT_LPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WB_CORE_AT_LPM field to a new value.
#define BW_CCM_CLPCR_WB_CORE_AT_LPM(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_WB_CORE_AT_LPM) | BF_CCM_CLPCR_WB_CORE_AT_LPM(v)))
#endif


/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH0_LPM_HS[19] (RW)
 *
 * Bypass handshake with mmdc_ch0 on next entrance to low power mode (wait or stop mode). CCM does
 * not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to
 * gate fast mmdc_ch0 clock.
 *
 * Values:
 * 0 - handshake with mmdc_ch0 on next entrance to low power mode will be performed. (default).
 * 1 - handshake with mmdc_ch0 on next entrance to low power mode will be bypassed.
 */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      (19)      //!< Bit position for CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS.
#define BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS      (0x00080000)  //!< Bit mask for CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS.

//! @brief Get value of CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS from a register value.
#define BG_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(r)   (((r) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS) >> BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS.
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   ((((reg32_t) v) << BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#else
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS.
#define BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   (((v) << BP_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS) & BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_MMDC_CH0_LPM_HS field to a new value.
#define BW_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS) | BF_CCM_CLPCR_BYPASS_MMDC_CH0_LPM_HS(v)))
#endif


/* --- Register HW_CCM_CLPCR, field BYPASS_MMDC_CH1_LPM_HS[21] (RW)
 *
 * Bypass handshake with mmdc_ch1 on next entrance to low power mode (wait or stop mode). CCM does
 * not wait for the module's acknowledge. Handshake also will be bypassed, if CGR3 CG10 is set to
 * gate fast mmdc_ch1 clock.
 *
 * Values:
 * 0 - handshake with mmdc_ch1 on next entrance to low power mode will be performed. (default).
 * 1 - handshake with mmdc_ch1 on next entrance to low power mode will be bypassed.
 */

#define BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      (21)      //!< Bit position for CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS.
#define BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS      (0x00200000)  //!< Bit mask for CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS.

//! @brief Get value of CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS from a register value.
#define BG_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(r)   (((r) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS) >> BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS.
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   ((((reg32_t) v) << BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#else
//! @brief Format value for bitfield CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS.
#define BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   (((v) << BP_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS) & BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_MMDC_CH1_LPM_HS field to a new value.
#define BW_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS) | BF_CCM_CLPCR_BYPASS_MMDC_CH1_LPM_HS(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_CORE0_WFI[22] (RW)
 *
 * Mask WFI of core0 for entering low power mode Note: assertion of all bits[27:22] will generate
 * low power mode request
 *
 * Values:
 * 0 - WFI of core0 is not masked
 * 1 - WFI of core0 is masked
 */

#define BP_CCM_CLPCR_MASK_CORE0_WFI      (22)      //!< Bit position for CCM_CLPCR_MASK_CORE0_WFI.
#define BM_CCM_CLPCR_MASK_CORE0_WFI      (0x00400000)  //!< Bit mask for CCM_CLPCR_MASK_CORE0_WFI.

//! @brief Get value of CCM_CLPCR_MASK_CORE0_WFI from a register value.
#define BG_CCM_CLPCR_MASK_CORE0_WFI(r)   (((r) & BM_CCM_CLPCR_MASK_CORE0_WFI) >> BP_CCM_CLPCR_MASK_CORE0_WFI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE0_WFI.
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_CORE0_WFI) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE0_WFI.
#define BF_CCM_CLPCR_MASK_CORE0_WFI(v)   (((v) << BP_CCM_CLPCR_MASK_CORE0_WFI) & BM_CCM_CLPCR_MASK_CORE0_WFI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CORE0_WFI field to a new value.
#define BW_CCM_CLPCR_MASK_CORE0_WFI(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_CORE0_WFI) | BF_CCM_CLPCR_MASK_CORE0_WFI(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_CORE1_WFI[23] (RW)
 *
 * Mask WFI of core1 for entering low power mode Note: assertion of all bits[27:22] will generate
 * low power mode request
 *
 * Values:
 * 0 - WFI of core1 is not masked
 * 1 - WFI of core1 is masked
 */

#define BP_CCM_CLPCR_MASK_CORE1_WFI      (23)      //!< Bit position for CCM_CLPCR_MASK_CORE1_WFI.
#define BM_CCM_CLPCR_MASK_CORE1_WFI      (0x00800000)  //!< Bit mask for CCM_CLPCR_MASK_CORE1_WFI.

//! @brief Get value of CCM_CLPCR_MASK_CORE1_WFI from a register value.
#define BG_CCM_CLPCR_MASK_CORE1_WFI(r)   (((r) & BM_CCM_CLPCR_MASK_CORE1_WFI) >> BP_CCM_CLPCR_MASK_CORE1_WFI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE1_WFI.
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_CORE1_WFI) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE1_WFI.
#define BF_CCM_CLPCR_MASK_CORE1_WFI(v)   (((v) << BP_CCM_CLPCR_MASK_CORE1_WFI) & BM_CCM_CLPCR_MASK_CORE1_WFI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CORE1_WFI field to a new value.
#define BW_CCM_CLPCR_MASK_CORE1_WFI(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_CORE1_WFI) | BF_CCM_CLPCR_MASK_CORE1_WFI(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_CORE2_WFI[24] (RW)
 *
 * Mask WFI of core2 for entering low power mode Note: assertion of all bits[27:22] will generate
 * low power mode request
 *
 * Values:
 * 0 - WFI of core2 is not masked
 * 1 - WFI of core2 is masked
 */

#define BP_CCM_CLPCR_MASK_CORE2_WFI      (24)      //!< Bit position for CCM_CLPCR_MASK_CORE2_WFI.
#define BM_CCM_CLPCR_MASK_CORE2_WFI      (0x01000000)  //!< Bit mask for CCM_CLPCR_MASK_CORE2_WFI.

//! @brief Get value of CCM_CLPCR_MASK_CORE2_WFI from a register value.
#define BG_CCM_CLPCR_MASK_CORE2_WFI(r)   (((r) & BM_CCM_CLPCR_MASK_CORE2_WFI) >> BP_CCM_CLPCR_MASK_CORE2_WFI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE2_WFI.
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_CORE2_WFI) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE2_WFI.
#define BF_CCM_CLPCR_MASK_CORE2_WFI(v)   (((v) << BP_CCM_CLPCR_MASK_CORE2_WFI) & BM_CCM_CLPCR_MASK_CORE2_WFI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CORE2_WFI field to a new value.
#define BW_CCM_CLPCR_MASK_CORE2_WFI(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_CORE2_WFI) | BF_CCM_CLPCR_MASK_CORE2_WFI(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_CORE3_WFI[25] (RW)
 *
 * Mask WFI of core3 for entering low power mode Note: assertion of all bits[27:22] will generate
 * low power mode request
 *
 * Values:
 * 0 - WFI of core3 is not masked
 * 1 - WFI of core3 is masked
 */

#define BP_CCM_CLPCR_MASK_CORE3_WFI      (25)      //!< Bit position for CCM_CLPCR_MASK_CORE3_WFI.
#define BM_CCM_CLPCR_MASK_CORE3_WFI      (0x02000000)  //!< Bit mask for CCM_CLPCR_MASK_CORE3_WFI.

//! @brief Get value of CCM_CLPCR_MASK_CORE3_WFI from a register value.
#define BG_CCM_CLPCR_MASK_CORE3_WFI(r)   (((r) & BM_CCM_CLPCR_MASK_CORE3_WFI) >> BP_CCM_CLPCR_MASK_CORE3_WFI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE3_WFI.
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_CORE3_WFI) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_CORE3_WFI.
#define BF_CCM_CLPCR_MASK_CORE3_WFI(v)   (((v) << BP_CCM_CLPCR_MASK_CORE3_WFI) & BM_CCM_CLPCR_MASK_CORE3_WFI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_CORE3_WFI field to a new value.
#define BW_CCM_CLPCR_MASK_CORE3_WFI(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_CORE3_WFI) | BF_CCM_CLPCR_MASK_CORE3_WFI(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_SCU_IDLE[26] (RW)
 *
 * Mask SCU IDLE for entering low power mode Note: assertion of all bits[27:22] will generate low
 * power mode request
 *
 * Values:
 * 0 - SCU IDLE is not masked
 * 1 - SCU IDLE is masked
 */

#define BP_CCM_CLPCR_MASK_SCU_IDLE      (26)      //!< Bit position for CCM_CLPCR_MASK_SCU_IDLE.
#define BM_CCM_CLPCR_MASK_SCU_IDLE      (0x04000000)  //!< Bit mask for CCM_CLPCR_MASK_SCU_IDLE.

//! @brief Get value of CCM_CLPCR_MASK_SCU_IDLE from a register value.
#define BG_CCM_CLPCR_MASK_SCU_IDLE(r)   (((r) & BM_CCM_CLPCR_MASK_SCU_IDLE) >> BP_CCM_CLPCR_MASK_SCU_IDLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_SCU_IDLE.
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_SCU_IDLE) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_SCU_IDLE.
#define BF_CCM_CLPCR_MASK_SCU_IDLE(v)   (((v) << BP_CCM_CLPCR_MASK_SCU_IDLE) & BM_CCM_CLPCR_MASK_SCU_IDLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_SCU_IDLE field to a new value.
#define BW_CCM_CLPCR_MASK_SCU_IDLE(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_SCU_IDLE) | BF_CCM_CLPCR_MASK_SCU_IDLE(v)))
#endif


/* --- Register HW_CCM_CLPCR, field MASK_L2CC_IDLE[27] (RW)
 *
 * Mask L2CC IDLE for entering low power mode. Note: assertion of all bits[27:22] will generate low
 * power mode request
 *
 * Values:
 * 0 - L2CC IDLE is not masked
 * 1 - L2CC IDLE is masked
 */

#define BP_CCM_CLPCR_MASK_L2CC_IDLE      (27)      //!< Bit position for CCM_CLPCR_MASK_L2CC_IDLE.
#define BM_CCM_CLPCR_MASK_L2CC_IDLE      (0x08000000)  //!< Bit mask for CCM_CLPCR_MASK_L2CC_IDLE.

//! @brief Get value of CCM_CLPCR_MASK_L2CC_IDLE from a register value.
#define BG_CCM_CLPCR_MASK_L2CC_IDLE(r)   (((r) & BM_CCM_CLPCR_MASK_L2CC_IDLE) >> BP_CCM_CLPCR_MASK_L2CC_IDLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CLPCR_MASK_L2CC_IDLE.
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   ((((reg32_t) v) << BP_CCM_CLPCR_MASK_L2CC_IDLE) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#else
//! @brief Format value for bitfield CCM_CLPCR_MASK_L2CC_IDLE.
#define BF_CCM_CLPCR_MASK_L2CC_IDLE(v)   (((v) << BP_CCM_CLPCR_MASK_L2CC_IDLE) & BM_CCM_CLPCR_MASK_L2CC_IDLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_L2CC_IDLE field to a new value.
#define BW_CCM_CLPCR_MASK_L2CC_IDLE(v)   (HW_CCM_CLPCR_WR((HW_CCM_CLPCR_RD() & ~BM_CCM_CLPCR_MASK_L2CC_IDLE) | BF_CCM_CLPCR_MASK_L2CC_IDLE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CISR - CCM Interrupt Status Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * The figure below represents the CCM Interrupt Status Register (CISR). This is a write one to
 * clear register. Once a interrupt is generated, software should write one to clear it. The table
 * below provides its field descriptions.  * Note: ipi_int_1 can be masked by ipi_int_1_mask bit.
 * ipi_int_2 can be masked by ipi_int_2_mask bit.
 */
typedef union _hw_ccm_cisr
{
    reg32_t U;
    struct _hw_ccm_cisr_bitfields
    {
        unsigned LRF_PLL : 1; //!< [0] Interrupt ipi_int_2 generated due to lock of all enabled and not bypaseed pll's
        unsigned RESERVED0 : 5; //!< [5:1] Reserved
        unsigned COSC_READY : 1; //!< [6] Interrupt ipi_int_2 generated due to on board oscillator ready, i.e. oscnt has finished counting.
        unsigned RESERVED1 : 10; //!< [16:7] Reserved
        unsigned AXI_PODF_LOADED : 1; //!< [17] Interrupt ipi_int_1 generated due to frequency change of axi_a_podf
        unsigned AXI_B_PODF_LOADED : 1; //!< [18] Interrupt ipi_int_1 generated due to frequency change of axi_b_podf
        unsigned PERIPH2_CLK_SEL_LOADED : 1; //!< [19] Interrupt ipi_int_1 generated due to frequency change of periph2_clk_sel
        unsigned AHB_PODF_LOADED : 1; //!< [20] Interrupt ipi_int_1 generated due to frequency change of ahb_podf
        unsigned MMDC_CH1_PODF_LOADED : 1; //!< [21] Interrupt ipi_int_1 generated due to frequency change of mmdc_ch0_podf_ loaded
        unsigned PERIPH_CLK_SEL_LOADED : 1; //!< [22] Interrupt ipi_int_1 generated due to update of periph_clk_sel.
        unsigned MMDC_CH0_PODF_LOADED : 1; //!< [23] Interrupt ipi_int_1 generated due to update of mmdc_ch0_axi_podf.
        unsigned RESERVED2 : 2; //!< [25:24] Reserved
        unsigned ARM_PODF_LOADED : 1; //!< [26] Interrupt ipi_int_1 generated due to frequency change of arm_podf. The interrupt will commence only if arm_podf is loaded during a arm dvfs operation.
        unsigned RESERVED3 : 5; //!< [31:27] Reserved
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

/* --- Register HW_CCM_CISR, field LRF_PLL[0] (W1C)
 *
 * Interrupt ipi_int_2 generated due to lock of all enabled and not bypaseed pll's
 *
 * Values:
 * 0 - interrupt is not genrerated due to lock ready of all enabled and not bypaseed pll's
 * 1 - interrupt genrerated due to lock ready of all enabled and not bypaseed pll's
 */

#define BP_CCM_CISR_LRF_PLL      (0)      //!< Bit position for CCM_CISR_LRF_PLL.
#define BM_CCM_CISR_LRF_PLL      (0x00000001)  //!< Bit mask for CCM_CISR_LRF_PLL.

//! @brief Get value of CCM_CISR_LRF_PLL from a register value.
#define BG_CCM_CISR_LRF_PLL(r)   (((r) & BM_CCM_CISR_LRF_PLL) >> BP_CCM_CISR_LRF_PLL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_LRF_PLL.
#define BF_CCM_CISR_LRF_PLL(v)   ((((reg32_t) v) << BP_CCM_CISR_LRF_PLL) & BM_CCM_CISR_LRF_PLL)
#else
//! @brief Format value for bitfield CCM_CISR_LRF_PLL.
#define BF_CCM_CISR_LRF_PLL(v)   (((v) << BP_CCM_CISR_LRF_PLL) & BM_CCM_CISR_LRF_PLL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LRF_PLL field to a new value.
#define BW_CCM_CISR_LRF_PLL(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_LRF_PLL) | BF_CCM_CISR_LRF_PLL(v)))
#endif


/* --- Register HW_CCM_CISR, field COSC_READY[6] (W1C)
 *
 * Interrupt ipi_int_2 generated due to on board oscillator ready, i.e. oscnt has finished counting.
 *
 * Values:
 * 0 - interrupt is not genrerated due to on board oscillator ready
 * 1 - interrupt genrerated due to on board oscillator ready
 */

#define BP_CCM_CISR_COSC_READY      (6)      //!< Bit position for CCM_CISR_COSC_READY.
#define BM_CCM_CISR_COSC_READY      (0x00000040)  //!< Bit mask for CCM_CISR_COSC_READY.

//! @brief Get value of CCM_CISR_COSC_READY from a register value.
#define BG_CCM_CISR_COSC_READY(r)   (((r) & BM_CCM_CISR_COSC_READY) >> BP_CCM_CISR_COSC_READY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_COSC_READY.
#define BF_CCM_CISR_COSC_READY(v)   ((((reg32_t) v) << BP_CCM_CISR_COSC_READY) & BM_CCM_CISR_COSC_READY)
#else
//! @brief Format value for bitfield CCM_CISR_COSC_READY.
#define BF_CCM_CISR_COSC_READY(v)   (((v) << BP_CCM_CISR_COSC_READY) & BM_CCM_CISR_COSC_READY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COSC_READY field to a new value.
#define BW_CCM_CISR_COSC_READY(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_COSC_READY) | BF_CCM_CISR_COSC_READY(v)))
#endif


/* --- Register HW_CCM_CISR, field AXI_PODF_LOADED[17] (W1C)
 *
 * Interrupt ipi_int_1 generated due to frequency change of axi_a_podf
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of axi_a_podf
 * 1 - interrupt genrerated due to frequency change of axi_a_podf
 */

#define BP_CCM_CISR_AXI_PODF_LOADED      (17)      //!< Bit position for CCM_CISR_AXI_PODF_LOADED.
#define BM_CCM_CISR_AXI_PODF_LOADED      (0x00020000)  //!< Bit mask for CCM_CISR_AXI_PODF_LOADED.

//! @brief Get value of CCM_CISR_AXI_PODF_LOADED from a register value.
#define BG_CCM_CISR_AXI_PODF_LOADED(r)   (((r) & BM_CCM_CISR_AXI_PODF_LOADED) >> BP_CCM_CISR_AXI_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_AXI_PODF_LOADED.
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_AXI_PODF_LOADED) & BM_CCM_CISR_AXI_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_AXI_PODF_LOADED.
#define BF_CCM_CISR_AXI_PODF_LOADED(v)   (((v) << BP_CCM_CISR_AXI_PODF_LOADED) & BM_CCM_CISR_AXI_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AXI_PODF_LOADED field to a new value.
#define BW_CCM_CISR_AXI_PODF_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_AXI_PODF_LOADED) | BF_CCM_CISR_AXI_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field AXI_B_PODF_LOADED[18] (ROZ)
 *
 * Interrupt ipi_int_1 generated due to frequency change of axi_b_podf
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of axi_b_podf
 * 1 - interrupt genrerated due to frequency change of axi_b_podf
 */

#define BP_CCM_CISR_AXI_B_PODF_LOADED      (18)      //!< Bit position for CCM_CISR_AXI_B_PODF_LOADED.
#define BM_CCM_CISR_AXI_B_PODF_LOADED      (0x00040000)  //!< Bit mask for CCM_CISR_AXI_B_PODF_LOADED.

//! @brief Get value of CCM_CISR_AXI_B_PODF_LOADED from a register value.
#define BG_CCM_CISR_AXI_B_PODF_LOADED(r)   (((r) & BM_CCM_CISR_AXI_B_PODF_LOADED) >> BP_CCM_CISR_AXI_B_PODF_LOADED)


/* --- Register HW_CCM_CISR, field PERIPH2_CLK_SEL_LOADED[19] (W1C)
 *
 * Interrupt ipi_int_1 generated due to frequency change of periph2_clk_sel
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of periph2_clk_sel
 * 1 - interrupt genrerated due to frequency change of periph2_clk_sel
 */

#define BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED      (19)      //!< Bit position for CCM_CISR_PERIPH2_CLK_SEL_LOADED.
#define BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED      (0x00080000)  //!< Bit mask for CCM_CISR_PERIPH2_CLK_SEL_LOADED.

//! @brief Get value of CCM_CISR_PERIPH2_CLK_SEL_LOADED from a register value.
#define BG_CCM_CISR_PERIPH2_CLK_SEL_LOADED(r)   (((r) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED) >> BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_PERIPH2_CLK_SEL_LOADED.
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_PERIPH2_CLK_SEL_LOADED.
#define BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   (((v) << BP_CCM_CISR_PERIPH2_CLK_SEL_LOADED) & BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH2_CLK_SEL_LOADED field to a new value.
#define BW_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_PERIPH2_CLK_SEL_LOADED) | BF_CCM_CISR_PERIPH2_CLK_SEL_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field AHB_PODF_LOADED[20] (W1C)
 *
 * Interrupt ipi_int_1 generated due to frequency change of ahb_podf
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of ahb_podf
 * 1 - interrupt genrerated due to frequency change of ahb_podf
 */

#define BP_CCM_CISR_AHB_PODF_LOADED      (20)      //!< Bit position for CCM_CISR_AHB_PODF_LOADED.
#define BM_CCM_CISR_AHB_PODF_LOADED      (0x00100000)  //!< Bit mask for CCM_CISR_AHB_PODF_LOADED.

//! @brief Get value of CCM_CISR_AHB_PODF_LOADED from a register value.
#define BG_CCM_CISR_AHB_PODF_LOADED(r)   (((r) & BM_CCM_CISR_AHB_PODF_LOADED) >> BP_CCM_CISR_AHB_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_AHB_PODF_LOADED.
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_AHB_PODF_LOADED) & BM_CCM_CISR_AHB_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_AHB_PODF_LOADED.
#define BF_CCM_CISR_AHB_PODF_LOADED(v)   (((v) << BP_CCM_CISR_AHB_PODF_LOADED) & BM_CCM_CISR_AHB_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AHB_PODF_LOADED field to a new value.
#define BW_CCM_CISR_AHB_PODF_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_AHB_PODF_LOADED) | BF_CCM_CISR_AHB_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field MMDC_CH1_PODF_LOADED[21] (W1C)
 *
 * Interrupt ipi_int_1 generated due to frequency change of mmdc_ch0_podf_ loaded
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of mmdc_ch0_podf_ loaded
 * 1 - interrupt genrerated due to frequency change of mmdc_ch0_podf_ loaded
 */

#define BP_CCM_CISR_MMDC_CH1_PODF_LOADED      (21)      //!< Bit position for CCM_CISR_MMDC_CH1_PODF_LOADED.
#define BM_CCM_CISR_MMDC_CH1_PODF_LOADED      (0x00200000)  //!< Bit mask for CCM_CISR_MMDC_CH1_PODF_LOADED.

//! @brief Get value of CCM_CISR_MMDC_CH1_PODF_LOADED from a register value.
#define BG_CCM_CISR_MMDC_CH1_PODF_LOADED(r)   (((r) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED) >> BP_CCM_CISR_MMDC_CH1_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_MMDC_CH1_PODF_LOADED.
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_MMDC_CH1_PODF_LOADED) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_MMDC_CH1_PODF_LOADED.
#define BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   (((v) << BP_CCM_CISR_MMDC_CH1_PODF_LOADED) & BM_CCM_CISR_MMDC_CH1_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH1_PODF_LOADED field to a new value.
#define BW_CCM_CISR_MMDC_CH1_PODF_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_MMDC_CH1_PODF_LOADED) | BF_CCM_CISR_MMDC_CH1_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field PERIPH_CLK_SEL_LOADED[22] (W1C)
 *
 * Interrupt ipi_int_1 generated due to update of periph_clk_sel.
 *
 * Values:
 * 0 - interrupt is not genrerated due to update of periph_clk_sel.
 * 1 - interrupt genrerated due to update of periph_clk_sel.
 */

#define BP_CCM_CISR_PERIPH_CLK_SEL_LOADED      (22)      //!< Bit position for CCM_CISR_PERIPH_CLK_SEL_LOADED.
#define BM_CCM_CISR_PERIPH_CLK_SEL_LOADED      (0x00400000)  //!< Bit mask for CCM_CISR_PERIPH_CLK_SEL_LOADED.

//! @brief Get value of CCM_CISR_PERIPH_CLK_SEL_LOADED from a register value.
#define BG_CCM_CISR_PERIPH_CLK_SEL_LOADED(r)   (((r) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED) >> BP_CCM_CISR_PERIPH_CLK_SEL_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_PERIPH_CLK_SEL_LOADED.
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_PERIPH_CLK_SEL_LOADED) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_PERIPH_CLK_SEL_LOADED.
#define BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   (((v) << BP_CCM_CISR_PERIPH_CLK_SEL_LOADED) & BM_CCM_CISR_PERIPH_CLK_SEL_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIPH_CLK_SEL_LOADED field to a new value.
#define BW_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_PERIPH_CLK_SEL_LOADED) | BF_CCM_CISR_PERIPH_CLK_SEL_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field MMDC_CH0_PODF_LOADED[23] (W1C)
 *
 * Interrupt ipi_int_1 generated due to update of mmdc_ch0_axi_podf.
 *
 * Values:
 * 0 - interrupt is not genrerated due to update of mmdc_ch0_axi_podf.
 * 1 - interrupt genrerated due to update of mmdc_ch0_axi_podf*
 */

#define BP_CCM_CISR_MMDC_CH0_PODF_LOADED      (23)      //!< Bit position for CCM_CISR_MMDC_CH0_PODF_LOADED.
#define BM_CCM_CISR_MMDC_CH0_PODF_LOADED      (0x00800000)  //!< Bit mask for CCM_CISR_MMDC_CH0_PODF_LOADED.

//! @brief Get value of CCM_CISR_MMDC_CH0_PODF_LOADED from a register value.
#define BG_CCM_CISR_MMDC_CH0_PODF_LOADED(r)   (((r) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED) >> BP_CCM_CISR_MMDC_CH0_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_MMDC_CH0_PODF_LOADED.
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_MMDC_CH0_PODF_LOADED) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_MMDC_CH0_PODF_LOADED.
#define BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   (((v) << BP_CCM_CISR_MMDC_CH0_PODF_LOADED) & BM_CCM_CISR_MMDC_CH0_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_CH0_PODF_LOADED field to a new value.
#define BW_CCM_CISR_MMDC_CH0_PODF_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_MMDC_CH0_PODF_LOADED) | BF_CCM_CISR_MMDC_CH0_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CISR, field ARM_PODF_LOADED[26] (W1C)
 *
 * Interrupt ipi_int_1 generated due to frequency change of arm_podf. The interrupt will commence
 * only if arm_podf is loaded during a arm dvfs operation.
 *
 * Values:
 * 0 - interrupt is not genrerated due to frequency change of arm_podf
 * 1 - interrupt genrerated due to frequency change of arm_podf
 */

#define BP_CCM_CISR_ARM_PODF_LOADED      (26)      //!< Bit position for CCM_CISR_ARM_PODF_LOADED.
#define BM_CCM_CISR_ARM_PODF_LOADED      (0x04000000)  //!< Bit mask for CCM_CISR_ARM_PODF_LOADED.

//! @brief Get value of CCM_CISR_ARM_PODF_LOADED from a register value.
#define BG_CCM_CISR_ARM_PODF_LOADED(r)   (((r) & BM_CCM_CISR_ARM_PODF_LOADED) >> BP_CCM_CISR_ARM_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CISR_ARM_PODF_LOADED.
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CISR_ARM_PODF_LOADED) & BM_CCM_CISR_ARM_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CISR_ARM_PODF_LOADED.
#define BF_CCM_CISR_ARM_PODF_LOADED(v)   (((v) << BP_CCM_CISR_ARM_PODF_LOADED) & BM_CCM_CISR_ARM_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARM_PODF_LOADED field to a new value.
#define BW_CCM_CISR_ARM_PODF_LOADED(v)   (HW_CCM_CISR_WR((HW_CCM_CISR_RD() & ~BM_CCM_CISR_ARM_PODF_LOADED) | BF_CCM_CISR_ARM_PODF_LOADED(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CIMR - CCM Interrupt Mask Register (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Interrupt Mask Register (CIMR). The table below provides its
 * field descriptions.
 */
typedef union _hw_ccm_cimr
{
    reg32_t U;
    struct _hw_ccm_cimr_bitfields
    {
        unsigned MASK_LRF_PLL : 1; //!< [0] mask interrupt generation due to lrf of pll's
        unsigned RESERVED0 : 5; //!< [5:1] Reserved
        unsigned MASK_COSC_READY : 1; //!< [6] mask interrupt generation due to on board oscillator ready
        unsigned RESERVED1 : 10; //!< [16:7] Reserved
        unsigned MASK_AXI_PODF_LOADED : 1; //!< [17] mask interrupt generation due to frequency change of axi_podf
        unsigned MASK_AXI_B_PODF_LOADED : 1; //!< [18] mask interrupt generation due to frequency change of axi_b_podf
        unsigned MASK_PERIPH2_CLK_SEL_LOADED : 1; //!< [19] mask interrupt generation due to update of periph2_clk_sel.
        unsigned MASK_AHB_PODF_LOADED : 1; //!< [20] mask interrupt generation due to frequency change of ahb_podf
        unsigned MASK_MMDC_CH1_PODF_LOADED : 1; //!< [21] mask interrupt generation due to update of mask_mmdc_ch1_podf
        unsigned MASK_PERIPH_CLK_SEL_LOADED : 1; //!< [22] mask interrupt generation due to update of periph_clk_sel.
        unsigned MASK_MMDC_CH0_PODF_LOADED : 1; //!< [23] mask interrupt generation due to update of mask_mmdc_ch0_podf
        unsigned RESERVED2 : 2; //!< [25:24] Reserved
        unsigned ARM_PODF_LOADED : 1; //!< [26] mask interrupt generation due to frequency change of arm_podf
        unsigned RESERVED3 : 5; //!< [31:27] Reserved
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

/* --- Register HW_CCM_CIMR, field MASK_LRF_PLL[0] (RW)
 *
 * mask interrupt generation due to lrf of pll's
 *
 * Values:
 * 0 - don't mask interrupt due to lrf of pll's - interrupt will be created
 * 1 - mask interrupt due to lrf of pll's
 */

#define BP_CCM_CIMR_MASK_LRF_PLL      (0)      //!< Bit position for CCM_CIMR_MASK_LRF_PLL.
#define BM_CCM_CIMR_MASK_LRF_PLL      (0x00000001)  //!< Bit mask for CCM_CIMR_MASK_LRF_PLL.

//! @brief Get value of CCM_CIMR_MASK_LRF_PLL from a register value.
#define BG_CCM_CIMR_MASK_LRF_PLL(r)   (((r) & BM_CCM_CIMR_MASK_LRF_PLL) >> BP_CCM_CIMR_MASK_LRF_PLL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_LRF_PLL.
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_LRF_PLL) & BM_CCM_CIMR_MASK_LRF_PLL)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_LRF_PLL.
#define BF_CCM_CIMR_MASK_LRF_PLL(v)   (((v) << BP_CCM_CIMR_MASK_LRF_PLL) & BM_CCM_CIMR_MASK_LRF_PLL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_LRF_PLL field to a new value.
#define BW_CCM_CIMR_MASK_LRF_PLL(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_LRF_PLL) | BF_CCM_CIMR_MASK_LRF_PLL(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_COSC_READY[6] (RW)
 *
 * mask interrupt generation due to on board oscillator ready
 *
 * Values:
 * 0 - don't mask interrupt due to on board oscillator ready - interrupt will be created
 * 1 - mask interrupt due to on board oscillator ready
 */

#define BP_CCM_CIMR_MASK_COSC_READY      (6)      //!< Bit position for CCM_CIMR_MASK_COSC_READY.
#define BM_CCM_CIMR_MASK_COSC_READY      (0x00000040)  //!< Bit mask for CCM_CIMR_MASK_COSC_READY.

//! @brief Get value of CCM_CIMR_MASK_COSC_READY from a register value.
#define BG_CCM_CIMR_MASK_COSC_READY(r)   (((r) & BM_CCM_CIMR_MASK_COSC_READY) >> BP_CCM_CIMR_MASK_COSC_READY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_COSC_READY.
#define BF_CCM_CIMR_MASK_COSC_READY(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_COSC_READY) & BM_CCM_CIMR_MASK_COSC_READY)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_COSC_READY.
#define BF_CCM_CIMR_MASK_COSC_READY(v)   (((v) << BP_CCM_CIMR_MASK_COSC_READY) & BM_CCM_CIMR_MASK_COSC_READY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_COSC_READY field to a new value.
#define BW_CCM_CIMR_MASK_COSC_READY(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_COSC_READY) | BF_CCM_CIMR_MASK_COSC_READY(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_AXI_PODF_LOADED[17] (RW)
 *
 * mask interrupt generation due to frequency change of axi_podf
 *
 * Values:
 * 0 - don't mask interrupt due to frequency change of axi_podf - interrupt will be created
 * 1 - mask interrupt due to frequency change of axi_podf
 */

#define BP_CCM_CIMR_MASK_AXI_PODF_LOADED      (17)      //!< Bit position for CCM_CIMR_MASK_AXI_PODF_LOADED.
#define BM_CCM_CIMR_MASK_AXI_PODF_LOADED      (0x00020000)  //!< Bit mask for CCM_CIMR_MASK_AXI_PODF_LOADED.

//! @brief Get value of CCM_CIMR_MASK_AXI_PODF_LOADED from a register value.
#define BG_CCM_CIMR_MASK_AXI_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED) >> BP_CCM_CIMR_MASK_AXI_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_AXI_PODF_LOADED.
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_AXI_PODF_LOADED) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_AXI_PODF_LOADED.
#define BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_AXI_PODF_LOADED) & BM_CCM_CIMR_MASK_AXI_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_AXI_PODF_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_AXI_PODF_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_AXI_PODF_LOADED) | BF_CCM_CIMR_MASK_AXI_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_AXI_B_PODF_LOADED[18] (RO)
 *
 * mask interrupt generation due to frequency change of axi_b_podf
 *
 * Values:
 * 0 - don't mask interrupt due to frequency change of axi_b_podf - interrupt will be created
 * 1 - mask interrupt due to frequency change of axi_b_podf
 */

#define BP_CCM_CIMR_MASK_AXI_B_PODF_LOADED      (18)      //!< Bit position for CCM_CIMR_MASK_AXI_B_PODF_LOADED.
#define BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED      (0x00040000)  //!< Bit mask for CCM_CIMR_MASK_AXI_B_PODF_LOADED.

//! @brief Get value of CCM_CIMR_MASK_AXI_B_PODF_LOADED from a register value.
#define BG_CCM_CIMR_MASK_AXI_B_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_AXI_B_PODF_LOADED) >> BP_CCM_CIMR_MASK_AXI_B_PODF_LOADED)


/* --- Register HW_CCM_CIMR, field MASK_PERIPH2_CLK_SEL_LOADED[19] (RW)
 *
 * mask interrupt generation due to update of periph2_clk_sel.
 *
 * Values:
 * 0 - don't mask interrupt due to update of periph2_clk_sel - interrupt will be created
 * 1 - mask interrupt due to update of periph2_clk_sel
 */

#define BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      (19)      //!< Bit position for CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED.
#define BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED      (0x00080000)  //!< Bit mask for CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED.

//! @brief Get value of CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED from a register value.
#define BG_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED) >> BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED.
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED.
#define BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED) & BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PERIPH2_CLK_SEL_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED) | BF_CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_AHB_PODF_LOADED[20] (RW)
 *
 * mask interrupt generation due to frequency change of ahb_podf
 *
 * Values:
 * 0 - don't mask interrupt due to frequency change of ahb_podf - interrupt will be created
 * 1 - mask interrupt due to frequency change of ahb_podf
 */

#define BP_CCM_CIMR_MASK_AHB_PODF_LOADED      (20)      //!< Bit position for CCM_CIMR_MASK_AHB_PODF_LOADED.
#define BM_CCM_CIMR_MASK_AHB_PODF_LOADED      (0x00100000)  //!< Bit mask for CCM_CIMR_MASK_AHB_PODF_LOADED.

//! @brief Get value of CCM_CIMR_MASK_AHB_PODF_LOADED from a register value.
#define BG_CCM_CIMR_MASK_AHB_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED) >> BP_CCM_CIMR_MASK_AHB_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_AHB_PODF_LOADED.
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_AHB_PODF_LOADED) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_AHB_PODF_LOADED.
#define BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_AHB_PODF_LOADED) & BM_CCM_CIMR_MASK_AHB_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_AHB_PODF_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_AHB_PODF_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_AHB_PODF_LOADED) | BF_CCM_CIMR_MASK_AHB_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH1_PODF_LOADED[21] (RW)
 *
 * mask interrupt generation due to update of mask_mmdc_ch1_podf
 *
 * Values:
 * 0 - don't mask interrupt due to update of mask_mmdc_ch1_podf - interrupt will be created
 * 1 - mask interrupt due to update of mask_mmdc_ch1_podf
 */

#define BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      (21)      //!< Bit position for CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED.
#define BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED      (0x00200000)  //!< Bit mask for CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED.

//! @brief Get value of CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED from a register value.
#define BG_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED) >> BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED.
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED.
#define BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED) & BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_MMDC_CH1_PODF_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED) | BF_CCM_CIMR_MASK_MMDC_CH1_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_PERIPH_CLK_SEL_LOADED[22] (RW)
 *
 * mask interrupt generation due to update of periph_clk_sel.
 *
 * Values:
 * 0 - don't mask interrupt due to update of periph_clk_sel - interrupt will be created
 * 1 - mask interrupt due to update of periph_clk_sel
 */

#define BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      (22)      //!< Bit position for CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED.
#define BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED      (0x00400000)  //!< Bit mask for CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED.

//! @brief Get value of CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED from a register value.
#define BG_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED) >> BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED.
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED.
#define BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED) & BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PERIPH_CLK_SEL_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED) | BF_CCM_CIMR_MASK_PERIPH_CLK_SEL_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field MASK_MMDC_CH0_PODF_LOADED[23] (RW)
 *
 * mask interrupt generation due to update of mask_mmdc_ch0_podf
 *
 * Values:
 * 0 - don't mask interrupt due to update of mask_mmdc_ch0_podf - interrupt will be created
 * 1 - mask interrupt due to update of mask_mmdc_ch0_podf
 */

#define BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      (23)      //!< Bit position for CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED.
#define BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED      (0x00800000)  //!< Bit mask for CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED.

//! @brief Get value of CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED from a register value.
#define BG_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED) >> BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED.
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED.
#define BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   (((v) << BP_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED) & BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_MMDC_CH0_PODF_LOADED field to a new value.
#define BW_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED) | BF_CCM_CIMR_MASK_MMDC_CH0_PODF_LOADED(v)))
#endif


/* --- Register HW_CCM_CIMR, field ARM_PODF_LOADED[26] (RW)
 *
 * mask interrupt generation due to frequency change of arm_podf
 *
 * Values:
 * 0 - don't mask interrupt due to frequency change of arm_podf - interrupt will be created
 * 1 - mask interrupt due to frequency change of arm_podf
 */

#define BP_CCM_CIMR_ARM_PODF_LOADED      (26)      //!< Bit position for CCM_CIMR_ARM_PODF_LOADED.
#define BM_CCM_CIMR_ARM_PODF_LOADED      (0x04000000)  //!< Bit mask for CCM_CIMR_ARM_PODF_LOADED.

//! @brief Get value of CCM_CIMR_ARM_PODF_LOADED from a register value.
#define BG_CCM_CIMR_ARM_PODF_LOADED(r)   (((r) & BM_CCM_CIMR_ARM_PODF_LOADED) >> BP_CCM_CIMR_ARM_PODF_LOADED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CIMR_ARM_PODF_LOADED.
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   ((((reg32_t) v) << BP_CCM_CIMR_ARM_PODF_LOADED) & BM_CCM_CIMR_ARM_PODF_LOADED)
#else
//! @brief Format value for bitfield CCM_CIMR_ARM_PODF_LOADED.
#define BF_CCM_CIMR_ARM_PODF_LOADED(v)   (((v) << BP_CCM_CIMR_ARM_PODF_LOADED) & BM_CCM_CIMR_ARM_PODF_LOADED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ARM_PODF_LOADED field to a new value.
#define BW_CCM_CIMR_ARM_PODF_LOADED(v)   (HW_CCM_CIMR_WR((HW_CCM_CIMR_RD() & ~BM_CCM_CIMR_ARM_PODF_LOADED) | BF_CCM_CIMR_ARM_PODF_LOADED(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCOSR - CCM Clock Output Source Register (RW)
 *
 * Reset value: 0x000a0001
 *
 * The figure below represents the CCM Clock Output Source Register (CCOSR). The CCOSR register
 * contains bits to control the clocks that will be generated on the output ipp_do_clko1 and
 * ipp_do_clko2.The table below provides its field descriptions.
 */
typedef union _hw_ccm_ccosr
{
    reg32_t U;
    struct _hw_ccm_ccosr_bitfields
    {
        unsigned CKO1_SEL : 4; //!< [3:0] Selection of the clock to be generated on cko1
        unsigned CKO1_DIV : 3; //!< [6:4] Setting the divider of CKO1
        unsigned CKO1_EN : 1; //!< [7] Enable of CKO1 clock
        unsigned CKO1_CKO2_SEL : 1; //!< [8] CKO1 output to reflect cko1 or cko2 clocks
        unsigned RESERVED0 : 7; //!< [15:9] Reserved
        unsigned CKO2_SEL : 5; //!< [20:16] Selection of the clock to be generated on cko2
        unsigned CKO2_DIV : 3; //!< [23:21] Setting the divider of CKO2
        unsigned CKO2_EN : 1; //!< [24] Enable of CKO2 clock
        unsigned RESERVED1 : 7; //!< [31:25] Reserved
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

/* --- Register HW_CCM_CCOSR, field CKO1_SEL[3:0] (RW)
 *
 * Selection of the clock to be generated on cko1
 *
 * Values:
 * 0000 - pll3_sw_clk (this inputs has additional constant division /2)
 * 0001 - pll2_main_clk (Default) (this inputs has additional constant division /2)
 * 0010 - pll1_main_clk (this inputs has additional constant division /2)
 * 0011 - pll5_main_clk (this inputs has additional constant division /2)
 * 0100 - video_27M_clk_root
 * 0101 - axi_clk_root
 * 0110 - enfc_clk_root
 * 0111 - ipu1_di0_clk_root
 * 1000 - ipu1_di1_clk_root
 * 1001 - ipu2_di0_clk_root
 * 1010 - ipu2_di1_clk_root
 * 1011 - ahb_clk_root
 * 1100 - ipg_clk_root
 * 1101 - perclk_root
 * 1110 - ckil_sync_clk_root
 * 1111 - pll4_main_clk
 */

#define BP_CCM_CCOSR_CKO1_SEL      (0)      //!< Bit position for CCM_CCOSR_CKO1_SEL.
#define BM_CCM_CCOSR_CKO1_SEL      (0x0000000f)  //!< Bit mask for CCM_CCOSR_CKO1_SEL.

//! @brief Get value of CCM_CCOSR_CKO1_SEL from a register value.
#define BG_CCM_CCOSR_CKO1_SEL(r)   (((r) & BM_CCM_CCOSR_CKO1_SEL) >> BP_CCM_CCOSR_CKO1_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO1_SEL.
#define BF_CCM_CCOSR_CKO1_SEL(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO1_SEL) & BM_CCM_CCOSR_CKO1_SEL)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO1_SEL.
#define BF_CCM_CCOSR_CKO1_SEL(v)   (((v) << BP_CCM_CCOSR_CKO1_SEL) & BM_CCM_CCOSR_CKO1_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO1_SEL field to a new value.
#define BW_CCM_CCOSR_CKO1_SEL(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO1_SEL) | BF_CCM_CCOSR_CKO1_SEL(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO1_DIV[6:4] (RW)
 *
 * Setting the divider of CKO1
 *
 * Values:
 * 000 - divide by 1(Default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CCOSR_CKO1_DIV      (4)      //!< Bit position for CCM_CCOSR_CKO1_DIV.
#define BM_CCM_CCOSR_CKO1_DIV      (0x00000070)  //!< Bit mask for CCM_CCOSR_CKO1_DIV.

//! @brief Get value of CCM_CCOSR_CKO1_DIV from a register value.
#define BG_CCM_CCOSR_CKO1_DIV(r)   (((r) & BM_CCM_CCOSR_CKO1_DIV) >> BP_CCM_CCOSR_CKO1_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO1_DIV.
#define BF_CCM_CCOSR_CKO1_DIV(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO1_DIV) & BM_CCM_CCOSR_CKO1_DIV)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO1_DIV.
#define BF_CCM_CCOSR_CKO1_DIV(v)   (((v) << BP_CCM_CCOSR_CKO1_DIV) & BM_CCM_CCOSR_CKO1_DIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO1_DIV field to a new value.
#define BW_CCM_CCOSR_CKO1_DIV(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO1_DIV) | BF_CCM_CCOSR_CKO1_DIV(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO1_EN[7] (RW)
 *
 * Enable of CKO1 clock
 *
 * Values:
 * 0 - CKO1 disabled.
 * 1 - CKO1 enabled.
 */

#define BP_CCM_CCOSR_CKO1_EN      (7)      //!< Bit position for CCM_CCOSR_CKO1_EN.
#define BM_CCM_CCOSR_CKO1_EN      (0x00000080)  //!< Bit mask for CCM_CCOSR_CKO1_EN.

//! @brief Get value of CCM_CCOSR_CKO1_EN from a register value.
#define BG_CCM_CCOSR_CKO1_EN(r)   (((r) & BM_CCM_CCOSR_CKO1_EN) >> BP_CCM_CCOSR_CKO1_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO1_EN.
#define BF_CCM_CCOSR_CKO1_EN(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO1_EN) & BM_CCM_CCOSR_CKO1_EN)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO1_EN.
#define BF_CCM_CCOSR_CKO1_EN(v)   (((v) << BP_CCM_CCOSR_CKO1_EN) & BM_CCM_CCOSR_CKO1_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO1_EN field to a new value.
#define BW_CCM_CCOSR_CKO1_EN(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO1_EN) | BF_CCM_CCOSR_CKO1_EN(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO1_CKO2_SEL[8] (RW)
 *
 * CKO1 output to reflect cko1 or cko2 clocks
 *
 * Values:
 * 0 - CKO1 output drives cko1 clock
 * 1 - CKO1 output drives cko2 clock
 */

#define BP_CCM_CCOSR_CKO1_CKO2_SEL      (8)      //!< Bit position for CCM_CCOSR_CKO1_CKO2_SEL.
#define BM_CCM_CCOSR_CKO1_CKO2_SEL      (0x00000100)  //!< Bit mask for CCM_CCOSR_CKO1_CKO2_SEL.

//! @brief Get value of CCM_CCOSR_CKO1_CKO2_SEL from a register value.
#define BG_CCM_CCOSR_CKO1_CKO2_SEL(r)   (((r) & BM_CCM_CCOSR_CKO1_CKO2_SEL) >> BP_CCM_CCOSR_CKO1_CKO2_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO1_CKO2_SEL.
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO1_CKO2_SEL) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO1_CKO2_SEL.
#define BF_CCM_CCOSR_CKO1_CKO2_SEL(v)   (((v) << BP_CCM_CCOSR_CKO1_CKO2_SEL) & BM_CCM_CCOSR_CKO1_CKO2_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO1_CKO2_SEL field to a new value.
#define BW_CCM_CCOSR_CKO1_CKO2_SEL(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO1_CKO2_SEL) | BF_CCM_CCOSR_CKO1_CKO2_SEL(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO2_SEL[20:16] (RW)
 *
 * Selection of the clock to be generated on cko2
 *
 * Values:
 * 00000 - mmdc_ch0_axi_clk_root
 * 00001 - mmdc_ch1_axi_clk_root
 * 00010 - usdhc4_clk_root
 * 00011 - usdhc1_clk_root
 * 00100 - gpu2d_axi_clk_root
 * 00101 - wrck_clk_root
 * 00110 - ecspi_clk_root
 * 00111 - gpu3d_axi_clk_root
 * 01000 - usdhc3_clk_root
 * 01001 - pcie_clk_root
 * 01010 - arm_axi_clk_root (Default)
 * 01011 - ipu1_hsp_clk_root
 * 01100 - ipu2_hsp_clk_root
 * 01101 - vdo_axi_clk_root
 * 01110 - osc_clk
 * 01111 - gpu2d_core_clk_root
 * 10000 - gpu3d_core_clk_root
 * 10001 - usdhc2_clk_root
 * 10010 - ssi1_clk_root
 * 10011 - ssi2_clk_root
 * 10100 - ssi3_clk_root
 * 10101 - gpu3d_shader_clk_root
 * 10110 - vpu_axi_clk_root
 * 10111 - can_clk_root
 * 11000 - ldb_di0_serial_clk_root
 * 11001 - ldb_di1_serial_clk_root
 * 11010 - esai_clk_root
 * 11011 - aclk_emi_slow_clk_root
 * 11100 - uart_clk_root
 * 11101 - spdif0_clk_root
 * 11110 - spdif1_clk_root
 * 11111 - hsi_tx_clk_root
 */

#define BP_CCM_CCOSR_CKO2_SEL      (16)      //!< Bit position for CCM_CCOSR_CKO2_SEL.
#define BM_CCM_CCOSR_CKO2_SEL      (0x001f0000)  //!< Bit mask for CCM_CCOSR_CKO2_SEL.

//! @brief Get value of CCM_CCOSR_CKO2_SEL from a register value.
#define BG_CCM_CCOSR_CKO2_SEL(r)   (((r) & BM_CCM_CCOSR_CKO2_SEL) >> BP_CCM_CCOSR_CKO2_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO2_SEL.
#define BF_CCM_CCOSR_CKO2_SEL(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO2_SEL) & BM_CCM_CCOSR_CKO2_SEL)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO2_SEL.
#define BF_CCM_CCOSR_CKO2_SEL(v)   (((v) << BP_CCM_CCOSR_CKO2_SEL) & BM_CCM_CCOSR_CKO2_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO2_SEL field to a new value.
#define BW_CCM_CCOSR_CKO2_SEL(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO2_SEL) | BF_CCM_CCOSR_CKO2_SEL(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO2_DIV[23:21] (RW)
 *
 * Setting the divider of CKO2
 *
 * Values:
 * 000 - divide by 1(Default)
 * 001 - divide by 2
 * 010 - divide by 3
 * 011 - divide by 4
 * 100 - divide by 5
 * 101 - divide by 6
 * 110 - divide by 7
 * 111 - divide by 8
 */

#define BP_CCM_CCOSR_CKO2_DIV      (21)      //!< Bit position for CCM_CCOSR_CKO2_DIV.
#define BM_CCM_CCOSR_CKO2_DIV      (0x00e00000)  //!< Bit mask for CCM_CCOSR_CKO2_DIV.

//! @brief Get value of CCM_CCOSR_CKO2_DIV from a register value.
#define BG_CCM_CCOSR_CKO2_DIV(r)   (((r) & BM_CCM_CCOSR_CKO2_DIV) >> BP_CCM_CCOSR_CKO2_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO2_DIV.
#define BF_CCM_CCOSR_CKO2_DIV(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO2_DIV) & BM_CCM_CCOSR_CKO2_DIV)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO2_DIV.
#define BF_CCM_CCOSR_CKO2_DIV(v)   (((v) << BP_CCM_CCOSR_CKO2_DIV) & BM_CCM_CCOSR_CKO2_DIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO2_DIV field to a new value.
#define BW_CCM_CCOSR_CKO2_DIV(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO2_DIV) | BF_CCM_CCOSR_CKO2_DIV(v)))
#endif


/* --- Register HW_CCM_CCOSR, field CKO2_EN[24] (RW)
 *
 * Enable of CKO2 clock
 *
 * Values:
 * 0 - CKO2 disabled.
 * 1 - CKO2 enabled.
 */

#define BP_CCM_CCOSR_CKO2_EN      (24)      //!< Bit position for CCM_CCOSR_CKO2_EN.
#define BM_CCM_CCOSR_CKO2_EN      (0x01000000)  //!< Bit mask for CCM_CCOSR_CKO2_EN.

//! @brief Get value of CCM_CCOSR_CKO2_EN from a register value.
#define BG_CCM_CCOSR_CKO2_EN(r)   (((r) & BM_CCM_CCOSR_CKO2_EN) >> BP_CCM_CCOSR_CKO2_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCOSR_CKO2_EN.
#define BF_CCM_CCOSR_CKO2_EN(v)   ((((reg32_t) v) << BP_CCM_CCOSR_CKO2_EN) & BM_CCM_CCOSR_CKO2_EN)
#else
//! @brief Format value for bitfield CCM_CCOSR_CKO2_EN.
#define BF_CCM_CCOSR_CKO2_EN(v)   (((v) << BP_CCM_CCOSR_CKO2_EN) & BM_CCM_CCOSR_CKO2_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CKO2_EN field to a new value.
#define BW_CCM_CCOSR_CKO2_EN(v)   (HW_CCM_CCOSR_WR((HW_CCM_CCOSR_RD() & ~BM_CCM_CCOSR_CKO2_EN) | BF_CCM_CCOSR_CKO2_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CGPR - CCM General Purpose Register (RW)
 *
 * Reset value: 0x0000fe62
 *
 * Fast PLL enable. Can be used to engage PLL faster after STOP mode, if 24MHz OSC was active
 */
typedef union _hw_ccm_cgpr
{
    reg32_t U;
    struct _hw_ccm_cgpr_bitfields
    {
        unsigned PMIC_DELAY_SCALER : 1; //!< [0] Defines clock dividion of clock for stby_count (pmic delay counter)
        unsigned RESERVED0 : 1; //!< [1] Reserved for future use. Bits are connected to ccm output cgpr_dout[31-5]
        unsigned MMDC_EXT_CLK_DIS : 1; //!< [2] Disable external clock driver of MMDC during STOP mode
        unsigned RESERVED1 : 1; //!< [3] Reserved for future use. Bits are connected to ccm output cgpr_dout[31-5]
        unsigned EFUSE_PROG_SUPPLY_GATE : 1; //!< [4] Defines the value of the output signal cgpr_dout[4]. Gate of programe supply for efuse programing
        unsigned RESERVED2 : 11; //!< [15:5] Reserved.
        unsigned FPL : 1; //!< [16] 
        unsigned RESERVED3 : 15; //!< [31:17] Reserved for future use. Those bits are connected to ccm output cgpr_dout[31-17]
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

/* --- Register HW_CCM_CGPR, field PMIC_DELAY_SCALER[0] (RW)
 *
 * Defines clock dividion of clock for stby_count (pmic delay counter)
 *
 * Values:
 * 0 - clock is not divided
 * 1 - clock is divided /8
 */

#define BP_CCM_CGPR_PMIC_DELAY_SCALER      (0)      //!< Bit position for CCM_CGPR_PMIC_DELAY_SCALER.
#define BM_CCM_CGPR_PMIC_DELAY_SCALER      (0x00000001)  //!< Bit mask for CCM_CGPR_PMIC_DELAY_SCALER.

//! @brief Get value of CCM_CGPR_PMIC_DELAY_SCALER from a register value.
#define BG_CCM_CGPR_PMIC_DELAY_SCALER(r)   (((r) & BM_CCM_CGPR_PMIC_DELAY_SCALER) >> BP_CCM_CGPR_PMIC_DELAY_SCALER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CGPR_PMIC_DELAY_SCALER.
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   ((((reg32_t) v) << BP_CCM_CGPR_PMIC_DELAY_SCALER) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#else
//! @brief Format value for bitfield CCM_CGPR_PMIC_DELAY_SCALER.
#define BF_CCM_CGPR_PMIC_DELAY_SCALER(v)   (((v) << BP_CCM_CGPR_PMIC_DELAY_SCALER) & BM_CCM_CGPR_PMIC_DELAY_SCALER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PMIC_DELAY_SCALER field to a new value.
#define BW_CCM_CGPR_PMIC_DELAY_SCALER(v)   (HW_CCM_CGPR_WR((HW_CCM_CGPR_RD() & ~BM_CCM_CGPR_PMIC_DELAY_SCALER) | BF_CCM_CGPR_PMIC_DELAY_SCALER(v)))
#endif


/* --- Register HW_CCM_CGPR, field MMDC_EXT_CLK_DIS[2] (RW)
 *
 * Disable external clock driver of MMDC during STOP mode
 *
 * Values:
 * 0 - don't disable during stop mode.
 * 1 - disable during stop mode
 */

#define BP_CCM_CGPR_MMDC_EXT_CLK_DIS      (2)      //!< Bit position for CCM_CGPR_MMDC_EXT_CLK_DIS.
#define BM_CCM_CGPR_MMDC_EXT_CLK_DIS      (0x00000004)  //!< Bit mask for CCM_CGPR_MMDC_EXT_CLK_DIS.

//! @brief Get value of CCM_CGPR_MMDC_EXT_CLK_DIS from a register value.
#define BG_CCM_CGPR_MMDC_EXT_CLK_DIS(r)   (((r) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS) >> BP_CCM_CGPR_MMDC_EXT_CLK_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CGPR_MMDC_EXT_CLK_DIS.
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   ((((reg32_t) v) << BP_CCM_CGPR_MMDC_EXT_CLK_DIS) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#else
//! @brief Format value for bitfield CCM_CGPR_MMDC_EXT_CLK_DIS.
#define BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   (((v) << BP_CCM_CGPR_MMDC_EXT_CLK_DIS) & BM_CCM_CGPR_MMDC_EXT_CLK_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MMDC_EXT_CLK_DIS field to a new value.
#define BW_CCM_CGPR_MMDC_EXT_CLK_DIS(v)   (HW_CCM_CGPR_WR((HW_CCM_CGPR_RD() & ~BM_CCM_CGPR_MMDC_EXT_CLK_DIS) | BF_CCM_CGPR_MMDC_EXT_CLK_DIS(v)))
#endif


/* --- Register HW_CCM_CGPR, field EFUSE_PROG_SUPPLY_GATE[4] (RW)
 *
 * Defines the value of the output signal cgpr_dout[4]. Gate of programe supply for efuse programing
 *
 * Values:
 * 0 - fuse programing supply voltage is gated off to the efuse module
 * 1 - allow fuse programing.
 */

#define BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      (4)      //!< Bit position for CCM_CGPR_EFUSE_PROG_SUPPLY_GATE.
#define BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE      (0x00000010)  //!< Bit mask for CCM_CGPR_EFUSE_PROG_SUPPLY_GATE.

//! @brief Get value of CCM_CGPR_EFUSE_PROG_SUPPLY_GATE from a register value.
#define BG_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(r)   (((r) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE) >> BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CGPR_EFUSE_PROG_SUPPLY_GATE.
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   ((((reg32_t) v) << BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#else
//! @brief Format value for bitfield CCM_CGPR_EFUSE_PROG_SUPPLY_GATE.
#define BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   (((v) << BP_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE) & BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EFUSE_PROG_SUPPLY_GATE field to a new value.
#define BW_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)   (HW_CCM_CGPR_WR((HW_CCM_CGPR_RD() & ~BM_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE) | BF_CCM_CGPR_EFUSE_PROG_SUPPLY_GATE(v)))
#endif


/* --- Register HW_CCM_CGPR, field FPL[16] (RW)
 *

 *
 * Values:
 * 0 - Engage PLL enable default way.
 * 1 - Engage PLL enable 3 CKIL clocks earlier at exiting low power mode (STOP). Should be used only if
 *     24MHz OSC was active in low power mode.
 */

#define BP_CCM_CGPR_FPL      (16)      //!< Bit position for CCM_CGPR_FPL.
#define BM_CCM_CGPR_FPL      (0x00010000)  //!< Bit mask for CCM_CGPR_FPL.

//! @brief Get value of CCM_CGPR_FPL from a register value.
#define BG_CCM_CGPR_FPL(r)   (((r) & BM_CCM_CGPR_FPL) >> BP_CCM_CGPR_FPL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CGPR_FPL.
#define BF_CCM_CGPR_FPL(v)   ((((reg32_t) v) << BP_CCM_CGPR_FPL) & BM_CCM_CGPR_FPL)
#else
//! @brief Format value for bitfield CCM_CGPR_FPL.
#define BF_CCM_CGPR_FPL(v)   (((v) << BP_CCM_CGPR_FPL) & BM_CCM_CGPR_FPL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FPL field to a new value.
#define BW_CCM_CGPR_FPL(v)   (HW_CCM_CGPR_WR((HW_CCM_CGPR_RD() & ~BM_CCM_CGPR_FPL) | BF_CCM_CGPR_FPL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR0 - CCM Clock Gating Register 0 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 0 (CCM_CCGR0). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr0
{
    reg32_t U;
    struct _hw_ccm_ccgr0_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] aips_tz1 clocks (aips_tz1_clk_enable)
        unsigned CG1 : 2; //!< [3:2] aips_tz2 clocks (aips_tz2_clk_enable)
        unsigned CG2 : 2; //!< [5:4] apbhdma hclk clock (apbhdma_hclk_enable)
        unsigned CG3 : 2; //!< [7:6] asrc clock (asrc_clk_enable)
        unsigned CG4 : 2; //!< [9:8] caam_secure_mem clock (caam_secure_mem_clk_enable)
        unsigned CG5 : 2; //!< [11:10] caam_wrapper_aclk clock (caam_wrapper_aclk_enable)
        unsigned CG6 : 2; //!< [13:12] caam_wrapper_ipg clock (caam_wrapper_ipg_enable)
        unsigned CG7 : 2; //!< [15:14] can1 clock (can1_clk_enable)
        unsigned CG8 : 2; //!< [17:16] can1_serial clock (can1_serial_clk_enable)
        unsigned CG9 : 2; //!< [19:18] can2 clock (can2_clk_enable)
        unsigned CG10 : 2; //!< [21:20] can2_serial clock (can2_serial_clk_enable)
        unsigned CG11 : 2; //!< [23:22] CPU debug clocks (cheetah_dbg_clk_enable)
        unsigned CG12 : 2; //!< [25:24] dcic 1 clocks (dcic1_clk_enable)
        unsigned CG13 : 2; //!< [27:26] dcic2 clocks (dcic2_clk_enable)
        unsigned CG14 : 2; //!< [29:28] dtcp clocks (dtcp_dtcp_clk_enable)
        unsigned CG15 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CCGR0, field CG0[1:0] (RW)
 *
 * aips_tz1 clocks (aips_tz1_clk_enable)
 */

#define BP_CCM_CCGR0_CG0      (0)      //!< Bit position for CCM_CCGR0_CG0.
#define BM_CCM_CCGR0_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR0_CG0.

//! @brief Get value of CCM_CCGR0_CG0 from a register value.
#define BG_CCM_CCGR0_CG0(r)   (((r) & BM_CCM_CCGR0_CG0) >> BP_CCM_CCGR0_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG0.
#define BF_CCM_CCGR0_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG0) & BM_CCM_CCGR0_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG0.
#define BF_CCM_CCGR0_CG0(v)   (((v) << BP_CCM_CCGR0_CG0) & BM_CCM_CCGR0_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR0_CG0(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG0) | BF_CCM_CCGR0_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG1[3:2] (RW)
 *
 * aips_tz2 clocks (aips_tz2_clk_enable)
 */

#define BP_CCM_CCGR0_CG1      (2)      //!< Bit position for CCM_CCGR0_CG1.
#define BM_CCM_CCGR0_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR0_CG1.

//! @brief Get value of CCM_CCGR0_CG1 from a register value.
#define BG_CCM_CCGR0_CG1(r)   (((r) & BM_CCM_CCGR0_CG1) >> BP_CCM_CCGR0_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG1.
#define BF_CCM_CCGR0_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG1) & BM_CCM_CCGR0_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG1.
#define BF_CCM_CCGR0_CG1(v)   (((v) << BP_CCM_CCGR0_CG1) & BM_CCM_CCGR0_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR0_CG1(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG1) | BF_CCM_CCGR0_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG2[5:4] (RW)
 *
 * apbhdma hclk clock (apbhdma_hclk_enable)
 */

#define BP_CCM_CCGR0_CG2      (4)      //!< Bit position for CCM_CCGR0_CG2.
#define BM_CCM_CCGR0_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR0_CG2.

//! @brief Get value of CCM_CCGR0_CG2 from a register value.
#define BG_CCM_CCGR0_CG2(r)   (((r) & BM_CCM_CCGR0_CG2) >> BP_CCM_CCGR0_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG2.
#define BF_CCM_CCGR0_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG2) & BM_CCM_CCGR0_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG2.
#define BF_CCM_CCGR0_CG2(v)   (((v) << BP_CCM_CCGR0_CG2) & BM_CCM_CCGR0_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR0_CG2(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG2) | BF_CCM_CCGR0_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG3[7:6] (RW)
 *
 * asrc clock (asrc_clk_enable)
 */

#define BP_CCM_CCGR0_CG3      (6)      //!< Bit position for CCM_CCGR0_CG3.
#define BM_CCM_CCGR0_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR0_CG3.

//! @brief Get value of CCM_CCGR0_CG3 from a register value.
#define BG_CCM_CCGR0_CG3(r)   (((r) & BM_CCM_CCGR0_CG3) >> BP_CCM_CCGR0_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG3.
#define BF_CCM_CCGR0_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG3) & BM_CCM_CCGR0_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG3.
#define BF_CCM_CCGR0_CG3(v)   (((v) << BP_CCM_CCGR0_CG3) & BM_CCM_CCGR0_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR0_CG3(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG3) | BF_CCM_CCGR0_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG4[9:8] (RW)
 *
 * caam_secure_mem clock (caam_secure_mem_clk_enable)
 */

#define BP_CCM_CCGR0_CG4      (8)      //!< Bit position for CCM_CCGR0_CG4.
#define BM_CCM_CCGR0_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR0_CG4.

//! @brief Get value of CCM_CCGR0_CG4 from a register value.
#define BG_CCM_CCGR0_CG4(r)   (((r) & BM_CCM_CCGR0_CG4) >> BP_CCM_CCGR0_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG4.
#define BF_CCM_CCGR0_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG4) & BM_CCM_CCGR0_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG4.
#define BF_CCM_CCGR0_CG4(v)   (((v) << BP_CCM_CCGR0_CG4) & BM_CCM_CCGR0_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR0_CG4(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG4) | BF_CCM_CCGR0_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG5[11:10] (RW)
 *
 * caam_wrapper_aclk clock (caam_wrapper_aclk_enable)
 */

#define BP_CCM_CCGR0_CG5      (10)      //!< Bit position for CCM_CCGR0_CG5.
#define BM_CCM_CCGR0_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR0_CG5.

//! @brief Get value of CCM_CCGR0_CG5 from a register value.
#define BG_CCM_CCGR0_CG5(r)   (((r) & BM_CCM_CCGR0_CG5) >> BP_CCM_CCGR0_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG5.
#define BF_CCM_CCGR0_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG5) & BM_CCM_CCGR0_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG5.
#define BF_CCM_CCGR0_CG5(v)   (((v) << BP_CCM_CCGR0_CG5) & BM_CCM_CCGR0_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR0_CG5(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG5) | BF_CCM_CCGR0_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG6[13:12] (RW)
 *
 * caam_wrapper_ipg clock (caam_wrapper_ipg_enable)
 */

#define BP_CCM_CCGR0_CG6      (12)      //!< Bit position for CCM_CCGR0_CG6.
#define BM_CCM_CCGR0_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR0_CG6.

//! @brief Get value of CCM_CCGR0_CG6 from a register value.
#define BG_CCM_CCGR0_CG6(r)   (((r) & BM_CCM_CCGR0_CG6) >> BP_CCM_CCGR0_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG6.
#define BF_CCM_CCGR0_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG6) & BM_CCM_CCGR0_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG6.
#define BF_CCM_CCGR0_CG6(v)   (((v) << BP_CCM_CCGR0_CG6) & BM_CCM_CCGR0_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR0_CG6(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG6) | BF_CCM_CCGR0_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG7[15:14] (RW)
 *
 * can1 clock (can1_clk_enable)
 */

#define BP_CCM_CCGR0_CG7      (14)      //!< Bit position for CCM_CCGR0_CG7.
#define BM_CCM_CCGR0_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR0_CG7.

//! @brief Get value of CCM_CCGR0_CG7 from a register value.
#define BG_CCM_CCGR0_CG7(r)   (((r) & BM_CCM_CCGR0_CG7) >> BP_CCM_CCGR0_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG7.
#define BF_CCM_CCGR0_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG7) & BM_CCM_CCGR0_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG7.
#define BF_CCM_CCGR0_CG7(v)   (((v) << BP_CCM_CCGR0_CG7) & BM_CCM_CCGR0_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR0_CG7(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG7) | BF_CCM_CCGR0_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG8[17:16] (RW)
 *
 * can1_serial clock (can1_serial_clk_enable)
 */

#define BP_CCM_CCGR0_CG8      (16)      //!< Bit position for CCM_CCGR0_CG8.
#define BM_CCM_CCGR0_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR0_CG8.

//! @brief Get value of CCM_CCGR0_CG8 from a register value.
#define BG_CCM_CCGR0_CG8(r)   (((r) & BM_CCM_CCGR0_CG8) >> BP_CCM_CCGR0_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG8.
#define BF_CCM_CCGR0_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG8) & BM_CCM_CCGR0_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG8.
#define BF_CCM_CCGR0_CG8(v)   (((v) << BP_CCM_CCGR0_CG8) & BM_CCM_CCGR0_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR0_CG8(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG8) | BF_CCM_CCGR0_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG9[19:18] (RW)
 *
 * can2 clock (can2_clk_enable)
 */

#define BP_CCM_CCGR0_CG9      (18)      //!< Bit position for CCM_CCGR0_CG9.
#define BM_CCM_CCGR0_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR0_CG9.

//! @brief Get value of CCM_CCGR0_CG9 from a register value.
#define BG_CCM_CCGR0_CG9(r)   (((r) & BM_CCM_CCGR0_CG9) >> BP_CCM_CCGR0_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG9.
#define BF_CCM_CCGR0_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG9) & BM_CCM_CCGR0_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG9.
#define BF_CCM_CCGR0_CG9(v)   (((v) << BP_CCM_CCGR0_CG9) & BM_CCM_CCGR0_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR0_CG9(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG9) | BF_CCM_CCGR0_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG10[21:20] (RW)
 *
 * can2_serial clock (can2_serial_clk_enable)
 */

#define BP_CCM_CCGR0_CG10      (20)      //!< Bit position for CCM_CCGR0_CG10.
#define BM_CCM_CCGR0_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR0_CG10.

//! @brief Get value of CCM_CCGR0_CG10 from a register value.
#define BG_CCM_CCGR0_CG10(r)   (((r) & BM_CCM_CCGR0_CG10) >> BP_CCM_CCGR0_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG10.
#define BF_CCM_CCGR0_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG10) & BM_CCM_CCGR0_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG10.
#define BF_CCM_CCGR0_CG10(v)   (((v) << BP_CCM_CCGR0_CG10) & BM_CCM_CCGR0_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR0_CG10(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG10) | BF_CCM_CCGR0_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG11[23:22] (RW)
 *
 * CPU debug clocks (cheetah_dbg_clk_enable)
 */

#define BP_CCM_CCGR0_CG11      (22)      //!< Bit position for CCM_CCGR0_CG11.
#define BM_CCM_CCGR0_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR0_CG11.

//! @brief Get value of CCM_CCGR0_CG11 from a register value.
#define BG_CCM_CCGR0_CG11(r)   (((r) & BM_CCM_CCGR0_CG11) >> BP_CCM_CCGR0_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG11.
#define BF_CCM_CCGR0_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG11) & BM_CCM_CCGR0_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG11.
#define BF_CCM_CCGR0_CG11(v)   (((v) << BP_CCM_CCGR0_CG11) & BM_CCM_CCGR0_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR0_CG11(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG11) | BF_CCM_CCGR0_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG12[25:24] (RW)
 *
 * dcic 1 clocks (dcic1_clk_enable)
 */

#define BP_CCM_CCGR0_CG12      (24)      //!< Bit position for CCM_CCGR0_CG12.
#define BM_CCM_CCGR0_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR0_CG12.

//! @brief Get value of CCM_CCGR0_CG12 from a register value.
#define BG_CCM_CCGR0_CG12(r)   (((r) & BM_CCM_CCGR0_CG12) >> BP_CCM_CCGR0_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG12.
#define BF_CCM_CCGR0_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG12) & BM_CCM_CCGR0_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG12.
#define BF_CCM_CCGR0_CG12(v)   (((v) << BP_CCM_CCGR0_CG12) & BM_CCM_CCGR0_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR0_CG12(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG12) | BF_CCM_CCGR0_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG13[27:26] (RW)
 *
 * dcic2 clocks (dcic2_clk_enable)
 */

#define BP_CCM_CCGR0_CG13      (26)      //!< Bit position for CCM_CCGR0_CG13.
#define BM_CCM_CCGR0_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR0_CG13.

//! @brief Get value of CCM_CCGR0_CG13 from a register value.
#define BG_CCM_CCGR0_CG13(r)   (((r) & BM_CCM_CCGR0_CG13) >> BP_CCM_CCGR0_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG13.
#define BF_CCM_CCGR0_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG13) & BM_CCM_CCGR0_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG13.
#define BF_CCM_CCGR0_CG13(v)   (((v) << BP_CCM_CCGR0_CG13) & BM_CCM_CCGR0_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR0_CG13(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG13) | BF_CCM_CCGR0_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG14[29:28] (RW)
 *
 * dtcp clocks (dtcp_dtcp_clk_enable)
 */

#define BP_CCM_CCGR0_CG14      (28)      //!< Bit position for CCM_CCGR0_CG14.
#define BM_CCM_CCGR0_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR0_CG14.

//! @brief Get value of CCM_CCGR0_CG14 from a register value.
#define BG_CCM_CCGR0_CG14(r)   (((r) & BM_CCM_CCGR0_CG14) >> BP_CCM_CCGR0_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG14.
#define BF_CCM_CCGR0_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG14) & BM_CCM_CCGR0_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG14.
#define BF_CCM_CCGR0_CG14(v)   (((v) << BP_CCM_CCGR0_CG14) & BM_CCM_CCGR0_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR0_CG14(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG14) | BF_CCM_CCGR0_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR0, field CG15[31:30] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR0_CG15      (30)      //!< Bit position for CCM_CCGR0_CG15.
#define BM_CCM_CCGR0_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR0_CG15.

//! @brief Get value of CCM_CCGR0_CG15 from a register value.
#define BG_CCM_CCGR0_CG15(r)   (((r) & BM_CCM_CCGR0_CG15) >> BP_CCM_CCGR0_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR0_CG15.
#define BF_CCM_CCGR0_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR0_CG15) & BM_CCM_CCGR0_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR0_CG15.
#define BF_CCM_CCGR0_CG15(v)   (((v) << BP_CCM_CCGR0_CG15) & BM_CCM_CCGR0_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR0_CG15(v)   (HW_CCM_CCGR0_WR((HW_CCM_CCGR0_RD() & ~BM_CCM_CCGR0_CG15) | BF_CCM_CCGR0_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR1 - CCM Clock Gating Register 1 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 1(CCM_CCGR1). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr1
{
    reg32_t U;
    struct _hw_ccm_ccgr1_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] ecspi1 clocks (ecspi1_clk_enable)
        unsigned CG1 : 2; //!< [3:2] ecspi2 clocks (ecspi2_clk_enable)
        unsigned CG2 : 2; //!< [5:4] ecspi3 clocks (ecspi3_clk_enable)
        unsigned CG3 : 2; //!< [7:6] ecspi4 clocks (ecspi4_clk_enable)
        unsigned CG4 : 2; //!< [9:8] ecspi5 clocks (ecspi5_clk_enable)
        unsigned CG5 : 2; //!< [11:10] clock (enet_clk_enable)
        unsigned CG6 : 2; //!< [13:12] epit1 clocks (epit1_clk_enable)
        unsigned CG7 : 2; //!< [15:14] epit2 clocks (epit2_clk_enable)
        unsigned CG8 : 2; //!< [17:16] esai clocks (esai_clk_enable) (extern_audio_clk_enable)
        unsigned CG9 : 2; //!< [19:18] Reserved
        unsigned CG10 : 2; //!< [21:20] gpt bus clock (gpt_clk_enable)
        unsigned CG11 : 2; //!< [23:22] gpt serial clock (gpt_serial_clk_enable)
        unsigned CG12 : 2; //!< [25:24] gpu2d clock (gpu2d_clk_enable)
        unsigned CG13 : 2; //!< [27:26] gpu3d clock (gpu3d_clk_enable)
        unsigned CG14 : 2; //!< [29:28] Reserved
        unsigned CG15 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CCGR1, field CG0[1:0] (RW)
 *
 * ecspi1 clocks (ecspi1_clk_enable)
 */

#define BP_CCM_CCGR1_CG0      (0)      //!< Bit position for CCM_CCGR1_CG0.
#define BM_CCM_CCGR1_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR1_CG0.

//! @brief Get value of CCM_CCGR1_CG0 from a register value.
#define BG_CCM_CCGR1_CG0(r)   (((r) & BM_CCM_CCGR1_CG0) >> BP_CCM_CCGR1_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG0.
#define BF_CCM_CCGR1_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG0) & BM_CCM_CCGR1_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG0.
#define BF_CCM_CCGR1_CG0(v)   (((v) << BP_CCM_CCGR1_CG0) & BM_CCM_CCGR1_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR1_CG0(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG0) | BF_CCM_CCGR1_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG1[3:2] (RW)
 *
 * ecspi2 clocks (ecspi2_clk_enable)
 */

#define BP_CCM_CCGR1_CG1      (2)      //!< Bit position for CCM_CCGR1_CG1.
#define BM_CCM_CCGR1_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR1_CG1.

//! @brief Get value of CCM_CCGR1_CG1 from a register value.
#define BG_CCM_CCGR1_CG1(r)   (((r) & BM_CCM_CCGR1_CG1) >> BP_CCM_CCGR1_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG1.
#define BF_CCM_CCGR1_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG1) & BM_CCM_CCGR1_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG1.
#define BF_CCM_CCGR1_CG1(v)   (((v) << BP_CCM_CCGR1_CG1) & BM_CCM_CCGR1_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR1_CG1(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG1) | BF_CCM_CCGR1_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG2[5:4] (RW)
 *
 * ecspi3 clocks (ecspi3_clk_enable)
 */

#define BP_CCM_CCGR1_CG2      (4)      //!< Bit position for CCM_CCGR1_CG2.
#define BM_CCM_CCGR1_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR1_CG2.

//! @brief Get value of CCM_CCGR1_CG2 from a register value.
#define BG_CCM_CCGR1_CG2(r)   (((r) & BM_CCM_CCGR1_CG2) >> BP_CCM_CCGR1_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG2.
#define BF_CCM_CCGR1_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG2) & BM_CCM_CCGR1_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG2.
#define BF_CCM_CCGR1_CG2(v)   (((v) << BP_CCM_CCGR1_CG2) & BM_CCM_CCGR1_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR1_CG2(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG2) | BF_CCM_CCGR1_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG3[7:6] (RW)
 *
 * ecspi4 clocks (ecspi4_clk_enable)
 */

#define BP_CCM_CCGR1_CG3      (6)      //!< Bit position for CCM_CCGR1_CG3.
#define BM_CCM_CCGR1_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR1_CG3.

//! @brief Get value of CCM_CCGR1_CG3 from a register value.
#define BG_CCM_CCGR1_CG3(r)   (((r) & BM_CCM_CCGR1_CG3) >> BP_CCM_CCGR1_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG3.
#define BF_CCM_CCGR1_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG3) & BM_CCM_CCGR1_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG3.
#define BF_CCM_CCGR1_CG3(v)   (((v) << BP_CCM_CCGR1_CG3) & BM_CCM_CCGR1_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR1_CG3(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG3) | BF_CCM_CCGR1_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG4[9:8] (RW)
 *
 * ecspi5 clocks (ecspi5_clk_enable)
 */

#define BP_CCM_CCGR1_CG4      (8)      //!< Bit position for CCM_CCGR1_CG4.
#define BM_CCM_CCGR1_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR1_CG4.

//! @brief Get value of CCM_CCGR1_CG4 from a register value.
#define BG_CCM_CCGR1_CG4(r)   (((r) & BM_CCM_CCGR1_CG4) >> BP_CCM_CCGR1_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG4.
#define BF_CCM_CCGR1_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG4) & BM_CCM_CCGR1_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG4.
#define BF_CCM_CCGR1_CG4(v)   (((v) << BP_CCM_CCGR1_CG4) & BM_CCM_CCGR1_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR1_CG4(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG4) | BF_CCM_CCGR1_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG5[11:10] (RW)
 *
 * clock (enet_clk_enable)
 */

#define BP_CCM_CCGR1_CG5      (10)      //!< Bit position for CCM_CCGR1_CG5.
#define BM_CCM_CCGR1_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR1_CG5.

//! @brief Get value of CCM_CCGR1_CG5 from a register value.
#define BG_CCM_CCGR1_CG5(r)   (((r) & BM_CCM_CCGR1_CG5) >> BP_CCM_CCGR1_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG5.
#define BF_CCM_CCGR1_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG5) & BM_CCM_CCGR1_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG5.
#define BF_CCM_CCGR1_CG5(v)   (((v) << BP_CCM_CCGR1_CG5) & BM_CCM_CCGR1_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR1_CG5(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG5) | BF_CCM_CCGR1_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG6[13:12] (RW)
 *
 * epit1 clocks (epit1_clk_enable)
 */

#define BP_CCM_CCGR1_CG6      (12)      //!< Bit position for CCM_CCGR1_CG6.
#define BM_CCM_CCGR1_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR1_CG6.

//! @brief Get value of CCM_CCGR1_CG6 from a register value.
#define BG_CCM_CCGR1_CG6(r)   (((r) & BM_CCM_CCGR1_CG6) >> BP_CCM_CCGR1_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG6.
#define BF_CCM_CCGR1_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG6) & BM_CCM_CCGR1_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG6.
#define BF_CCM_CCGR1_CG6(v)   (((v) << BP_CCM_CCGR1_CG6) & BM_CCM_CCGR1_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR1_CG6(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG6) | BF_CCM_CCGR1_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG7[15:14] (RW)
 *
 * epit2 clocks (epit2_clk_enable)
 */

#define BP_CCM_CCGR1_CG7      (14)      //!< Bit position for CCM_CCGR1_CG7.
#define BM_CCM_CCGR1_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR1_CG7.

//! @brief Get value of CCM_CCGR1_CG7 from a register value.
#define BG_CCM_CCGR1_CG7(r)   (((r) & BM_CCM_CCGR1_CG7) >> BP_CCM_CCGR1_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG7.
#define BF_CCM_CCGR1_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG7) & BM_CCM_CCGR1_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG7.
#define BF_CCM_CCGR1_CG7(v)   (((v) << BP_CCM_CCGR1_CG7) & BM_CCM_CCGR1_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR1_CG7(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG7) | BF_CCM_CCGR1_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG8[17:16] (RW)
 *
 * esai clocks (esai_clk_enable) (extern_audio_clk_enable)
 */

#define BP_CCM_CCGR1_CG8      (16)      //!< Bit position for CCM_CCGR1_CG8.
#define BM_CCM_CCGR1_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR1_CG8.

//! @brief Get value of CCM_CCGR1_CG8 from a register value.
#define BG_CCM_CCGR1_CG8(r)   (((r) & BM_CCM_CCGR1_CG8) >> BP_CCM_CCGR1_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG8.
#define BF_CCM_CCGR1_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG8) & BM_CCM_CCGR1_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG8.
#define BF_CCM_CCGR1_CG8(v)   (((v) << BP_CCM_CCGR1_CG8) & BM_CCM_CCGR1_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR1_CG8(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG8) | BF_CCM_CCGR1_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG9[19:18] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG9      (18)      //!< Bit position for CCM_CCGR1_CG9.
#define BM_CCM_CCGR1_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR1_CG9.

//! @brief Get value of CCM_CCGR1_CG9 from a register value.
#define BG_CCM_CCGR1_CG9(r)   (((r) & BM_CCM_CCGR1_CG9) >> BP_CCM_CCGR1_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG9.
#define BF_CCM_CCGR1_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG9) & BM_CCM_CCGR1_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG9.
#define BF_CCM_CCGR1_CG9(v)   (((v) << BP_CCM_CCGR1_CG9) & BM_CCM_CCGR1_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR1_CG9(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG9) | BF_CCM_CCGR1_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG10[21:20] (RW)
 *
 * gpt bus clock (gpt_clk_enable)
 */

#define BP_CCM_CCGR1_CG10      (20)      //!< Bit position for CCM_CCGR1_CG10.
#define BM_CCM_CCGR1_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR1_CG10.

//! @brief Get value of CCM_CCGR1_CG10 from a register value.
#define BG_CCM_CCGR1_CG10(r)   (((r) & BM_CCM_CCGR1_CG10) >> BP_CCM_CCGR1_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG10.
#define BF_CCM_CCGR1_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG10) & BM_CCM_CCGR1_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG10.
#define BF_CCM_CCGR1_CG10(v)   (((v) << BP_CCM_CCGR1_CG10) & BM_CCM_CCGR1_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR1_CG10(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG10) | BF_CCM_CCGR1_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG11[23:22] (RW)
 *
 * gpt serial clock (gpt_serial_clk_enable)
 */

#define BP_CCM_CCGR1_CG11      (22)      //!< Bit position for CCM_CCGR1_CG11.
#define BM_CCM_CCGR1_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR1_CG11.

//! @brief Get value of CCM_CCGR1_CG11 from a register value.
#define BG_CCM_CCGR1_CG11(r)   (((r) & BM_CCM_CCGR1_CG11) >> BP_CCM_CCGR1_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG11.
#define BF_CCM_CCGR1_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG11) & BM_CCM_CCGR1_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG11.
#define BF_CCM_CCGR1_CG11(v)   (((v) << BP_CCM_CCGR1_CG11) & BM_CCM_CCGR1_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR1_CG11(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG11) | BF_CCM_CCGR1_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG12[25:24] (RW)
 *
 * gpu2d clock (gpu2d_clk_enable)
 */

#define BP_CCM_CCGR1_CG12      (24)      //!< Bit position for CCM_CCGR1_CG12.
#define BM_CCM_CCGR1_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR1_CG12.

//! @brief Get value of CCM_CCGR1_CG12 from a register value.
#define BG_CCM_CCGR1_CG12(r)   (((r) & BM_CCM_CCGR1_CG12) >> BP_CCM_CCGR1_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG12.
#define BF_CCM_CCGR1_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG12) & BM_CCM_CCGR1_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG12.
#define BF_CCM_CCGR1_CG12(v)   (((v) << BP_CCM_CCGR1_CG12) & BM_CCM_CCGR1_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR1_CG12(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG12) | BF_CCM_CCGR1_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG13[27:26] (RW)
 *
 * gpu3d clock (gpu3d_clk_enable)
 */

#define BP_CCM_CCGR1_CG13      (26)      //!< Bit position for CCM_CCGR1_CG13.
#define BM_CCM_CCGR1_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR1_CG13.

//! @brief Get value of CCM_CCGR1_CG13 from a register value.
#define BG_CCM_CCGR1_CG13(r)   (((r) & BM_CCM_CCGR1_CG13) >> BP_CCM_CCGR1_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG13.
#define BF_CCM_CCGR1_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG13) & BM_CCM_CCGR1_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG13.
#define BF_CCM_CCGR1_CG13(v)   (((v) << BP_CCM_CCGR1_CG13) & BM_CCM_CCGR1_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR1_CG13(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG13) | BF_CCM_CCGR1_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG14[29:28] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG14      (28)      //!< Bit position for CCM_CCGR1_CG14.
#define BM_CCM_CCGR1_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR1_CG14.

//! @brief Get value of CCM_CCGR1_CG14 from a register value.
#define BG_CCM_CCGR1_CG14(r)   (((r) & BM_CCM_CCGR1_CG14) >> BP_CCM_CCGR1_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG14.
#define BF_CCM_CCGR1_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG14) & BM_CCM_CCGR1_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG14.
#define BF_CCM_CCGR1_CG14(v)   (((v) << BP_CCM_CCGR1_CG14) & BM_CCM_CCGR1_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR1_CG14(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG14) | BF_CCM_CCGR1_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR1, field CG15[31:30] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR1_CG15      (30)      //!< Bit position for CCM_CCGR1_CG15.
#define BM_CCM_CCGR1_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR1_CG15.

//! @brief Get value of CCM_CCGR1_CG15 from a register value.
#define BG_CCM_CCGR1_CG15(r)   (((r) & BM_CCM_CCGR1_CG15) >> BP_CCM_CCGR1_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR1_CG15.
#define BF_CCM_CCGR1_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR1_CG15) & BM_CCM_CCGR1_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR1_CG15.
#define BF_CCM_CCGR1_CG15(v)   (((v) << BP_CCM_CCGR1_CG15) & BM_CCM_CCGR1_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR1_CG15(v)   (HW_CCM_CCGR1_WR((HW_CCM_CCGR1_RD() & ~BM_CCM_CCGR1_CG15) | BF_CCM_CCGR1_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR2 - CCM Clock Gating Register 2 (RW)
 *
 * Reset value: 0xfc3fffff
 *
 * The figure below represents the CCM Clock Gating Register 2 (CCM_CCGR2). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr2
{
    reg32_t U;
    struct _hw_ccm_ccgr2_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] hdmi_tx_iahbclk, hdmi_tx_ihclk clock (hdmi_tx_iahbclk_enable)
        unsigned CG1 : 2; //!< [3:2] Reserved
        unsigned CG2 : 2; //!< [5:4] hdmi_tx_isfrclk clock (hdmi_tx_isfrclk_enable)
        unsigned CG3 : 2; //!< [7:6] i2c1_serial clock (i2c1_serial_clk_enable)
        unsigned CG4 : 2; //!< [9:8] i2c2_serial clock (i2c2_serial_clk_enable)
        unsigned CG5 : 2; //!< [11:10] i2c3_serial clock (i2c3_serial_clk_enable)
        unsigned CG6 : 2; //!< [13:12] OCOTP_CTRL clock (iim_clk_enable)
        unsigned CG7 : 2; //!< [15:14] iomux_ipt_clk_io clock (iomux_ipt_clk_io_enable)
        unsigned CG8 : 2; //!< [17:16] ipmux1 clock (ipmux1_clk_enable)
        unsigned CG9 : 2; //!< [19:18] ipmux2 clock (ipmux2_clk_enable)
        unsigned CG10 : 2; //!< [21:20] ipmux3 clock (ipmux3_clk_enable)
        unsigned CG11 : 2; //!< [23:22] ipsync_ip2apb_tzasc1_ipg clocks (ipsync_ip2apb_tzasc2_ipg_master_clk_enable)
        unsigned CG12 : 2; //!< [25:24] ipsync_vdoa_ipg clocks (ipsync_ip2apb_tzasc2_ipg clocks)
        unsigned CG13 : 2; //!< [27:26] ipsync_vdoa_ipg clocks (ipsync_vdoa_ipg_master_clk_enable)
        unsigned CG14 : 2; //!< [29:28] Reserved
        unsigned CG15 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CCGR2, field CG0[1:0] (RW)
 *
 * hdmi_tx_iahbclk, hdmi_tx_ihclk clock (hdmi_tx_iahbclk_enable)
 */

#define BP_CCM_CCGR2_CG0      (0)      //!< Bit position for CCM_CCGR2_CG0.
#define BM_CCM_CCGR2_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR2_CG0.

//! @brief Get value of CCM_CCGR2_CG0 from a register value.
#define BG_CCM_CCGR2_CG0(r)   (((r) & BM_CCM_CCGR2_CG0) >> BP_CCM_CCGR2_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG0.
#define BF_CCM_CCGR2_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG0) & BM_CCM_CCGR2_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG0.
#define BF_CCM_CCGR2_CG0(v)   (((v) << BP_CCM_CCGR2_CG0) & BM_CCM_CCGR2_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR2_CG0(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG0) | BF_CCM_CCGR2_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG1[3:2] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG1      (2)      //!< Bit position for CCM_CCGR2_CG1.
#define BM_CCM_CCGR2_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR2_CG1.

//! @brief Get value of CCM_CCGR2_CG1 from a register value.
#define BG_CCM_CCGR2_CG1(r)   (((r) & BM_CCM_CCGR2_CG1) >> BP_CCM_CCGR2_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG1.
#define BF_CCM_CCGR2_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG1) & BM_CCM_CCGR2_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG1.
#define BF_CCM_CCGR2_CG1(v)   (((v) << BP_CCM_CCGR2_CG1) & BM_CCM_CCGR2_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR2_CG1(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG1) | BF_CCM_CCGR2_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG2[5:4] (RW)
 *
 * hdmi_tx_isfrclk clock (hdmi_tx_isfrclk_enable)
 */

#define BP_CCM_CCGR2_CG2      (4)      //!< Bit position for CCM_CCGR2_CG2.
#define BM_CCM_CCGR2_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR2_CG2.

//! @brief Get value of CCM_CCGR2_CG2 from a register value.
#define BG_CCM_CCGR2_CG2(r)   (((r) & BM_CCM_CCGR2_CG2) >> BP_CCM_CCGR2_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG2.
#define BF_CCM_CCGR2_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG2) & BM_CCM_CCGR2_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG2.
#define BF_CCM_CCGR2_CG2(v)   (((v) << BP_CCM_CCGR2_CG2) & BM_CCM_CCGR2_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR2_CG2(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG2) | BF_CCM_CCGR2_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG3[7:6] (RW)
 *
 * i2c1_serial clock (i2c1_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG3      (6)      //!< Bit position for CCM_CCGR2_CG3.
#define BM_CCM_CCGR2_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR2_CG3.

//! @brief Get value of CCM_CCGR2_CG3 from a register value.
#define BG_CCM_CCGR2_CG3(r)   (((r) & BM_CCM_CCGR2_CG3) >> BP_CCM_CCGR2_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG3.
#define BF_CCM_CCGR2_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG3) & BM_CCM_CCGR2_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG3.
#define BF_CCM_CCGR2_CG3(v)   (((v) << BP_CCM_CCGR2_CG3) & BM_CCM_CCGR2_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR2_CG3(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG3) | BF_CCM_CCGR2_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG4[9:8] (RW)
 *
 * i2c2_serial clock (i2c2_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG4      (8)      //!< Bit position for CCM_CCGR2_CG4.
#define BM_CCM_CCGR2_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR2_CG4.

//! @brief Get value of CCM_CCGR2_CG4 from a register value.
#define BG_CCM_CCGR2_CG4(r)   (((r) & BM_CCM_CCGR2_CG4) >> BP_CCM_CCGR2_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG4.
#define BF_CCM_CCGR2_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG4) & BM_CCM_CCGR2_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG4.
#define BF_CCM_CCGR2_CG4(v)   (((v) << BP_CCM_CCGR2_CG4) & BM_CCM_CCGR2_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR2_CG4(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG4) | BF_CCM_CCGR2_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG5[11:10] (RW)
 *
 * i2c3_serial clock (i2c3_serial_clk_enable)
 */

#define BP_CCM_CCGR2_CG5      (10)      //!< Bit position for CCM_CCGR2_CG5.
#define BM_CCM_CCGR2_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR2_CG5.

//! @brief Get value of CCM_CCGR2_CG5 from a register value.
#define BG_CCM_CCGR2_CG5(r)   (((r) & BM_CCM_CCGR2_CG5) >> BP_CCM_CCGR2_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG5.
#define BF_CCM_CCGR2_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG5) & BM_CCM_CCGR2_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG5.
#define BF_CCM_CCGR2_CG5(v)   (((v) << BP_CCM_CCGR2_CG5) & BM_CCM_CCGR2_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR2_CG5(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG5) | BF_CCM_CCGR2_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG6[13:12] (RW)
 *
 * OCOTP_CTRL clock (iim_clk_enable)
 */

#define BP_CCM_CCGR2_CG6      (12)      //!< Bit position for CCM_CCGR2_CG6.
#define BM_CCM_CCGR2_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR2_CG6.

//! @brief Get value of CCM_CCGR2_CG6 from a register value.
#define BG_CCM_CCGR2_CG6(r)   (((r) & BM_CCM_CCGR2_CG6) >> BP_CCM_CCGR2_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG6.
#define BF_CCM_CCGR2_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG6) & BM_CCM_CCGR2_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG6.
#define BF_CCM_CCGR2_CG6(v)   (((v) << BP_CCM_CCGR2_CG6) & BM_CCM_CCGR2_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR2_CG6(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG6) | BF_CCM_CCGR2_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG7[15:14] (RW)
 *
 * iomux_ipt_clk_io clock (iomux_ipt_clk_io_enable)
 */

#define BP_CCM_CCGR2_CG7      (14)      //!< Bit position for CCM_CCGR2_CG7.
#define BM_CCM_CCGR2_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR2_CG7.

//! @brief Get value of CCM_CCGR2_CG7 from a register value.
#define BG_CCM_CCGR2_CG7(r)   (((r) & BM_CCM_CCGR2_CG7) >> BP_CCM_CCGR2_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG7.
#define BF_CCM_CCGR2_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG7) & BM_CCM_CCGR2_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG7.
#define BF_CCM_CCGR2_CG7(v)   (((v) << BP_CCM_CCGR2_CG7) & BM_CCM_CCGR2_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR2_CG7(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG7) | BF_CCM_CCGR2_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG8[17:16] (RW)
 *
 * ipmux1 clock (ipmux1_clk_enable)
 */

#define BP_CCM_CCGR2_CG8      (16)      //!< Bit position for CCM_CCGR2_CG8.
#define BM_CCM_CCGR2_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR2_CG8.

//! @brief Get value of CCM_CCGR2_CG8 from a register value.
#define BG_CCM_CCGR2_CG8(r)   (((r) & BM_CCM_CCGR2_CG8) >> BP_CCM_CCGR2_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG8.
#define BF_CCM_CCGR2_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG8) & BM_CCM_CCGR2_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG8.
#define BF_CCM_CCGR2_CG8(v)   (((v) << BP_CCM_CCGR2_CG8) & BM_CCM_CCGR2_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR2_CG8(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG8) | BF_CCM_CCGR2_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG9[19:18] (RW)
 *
 * ipmux2 clock (ipmux2_clk_enable)
 */

#define BP_CCM_CCGR2_CG9      (18)      //!< Bit position for CCM_CCGR2_CG9.
#define BM_CCM_CCGR2_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR2_CG9.

//! @brief Get value of CCM_CCGR2_CG9 from a register value.
#define BG_CCM_CCGR2_CG9(r)   (((r) & BM_CCM_CCGR2_CG9) >> BP_CCM_CCGR2_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG9.
#define BF_CCM_CCGR2_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG9) & BM_CCM_CCGR2_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG9.
#define BF_CCM_CCGR2_CG9(v)   (((v) << BP_CCM_CCGR2_CG9) & BM_CCM_CCGR2_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR2_CG9(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG9) | BF_CCM_CCGR2_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG10[21:20] (RW)
 *
 * ipmux3 clock (ipmux3_clk_enable)
 */

#define BP_CCM_CCGR2_CG10      (20)      //!< Bit position for CCM_CCGR2_CG10.
#define BM_CCM_CCGR2_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR2_CG10.

//! @brief Get value of CCM_CCGR2_CG10 from a register value.
#define BG_CCM_CCGR2_CG10(r)   (((r) & BM_CCM_CCGR2_CG10) >> BP_CCM_CCGR2_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG10.
#define BF_CCM_CCGR2_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG10) & BM_CCM_CCGR2_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG10.
#define BF_CCM_CCGR2_CG10(v)   (((v) << BP_CCM_CCGR2_CG10) & BM_CCM_CCGR2_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR2_CG10(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG10) | BF_CCM_CCGR2_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG11[23:22] (RW)
 *
 * ipsync_ip2apb_tzasc1_ipg clocks (ipsync_ip2apb_tzasc2_ipg_master_clk_enable)
 */

#define BP_CCM_CCGR2_CG11      (22)      //!< Bit position for CCM_CCGR2_CG11.
#define BM_CCM_CCGR2_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR2_CG11.

//! @brief Get value of CCM_CCGR2_CG11 from a register value.
#define BG_CCM_CCGR2_CG11(r)   (((r) & BM_CCM_CCGR2_CG11) >> BP_CCM_CCGR2_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG11.
#define BF_CCM_CCGR2_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG11) & BM_CCM_CCGR2_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG11.
#define BF_CCM_CCGR2_CG11(v)   (((v) << BP_CCM_CCGR2_CG11) & BM_CCM_CCGR2_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR2_CG11(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG11) | BF_CCM_CCGR2_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG12[25:24] (RW)
 *
 * ipsync_vdoa_ipg clocks (ipsync_ip2apb_tzasc2_ipg clocks)
 */

#define BP_CCM_CCGR2_CG12      (24)      //!< Bit position for CCM_CCGR2_CG12.
#define BM_CCM_CCGR2_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR2_CG12.

//! @brief Get value of CCM_CCGR2_CG12 from a register value.
#define BG_CCM_CCGR2_CG12(r)   (((r) & BM_CCM_CCGR2_CG12) >> BP_CCM_CCGR2_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG12.
#define BF_CCM_CCGR2_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG12) & BM_CCM_CCGR2_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG12.
#define BF_CCM_CCGR2_CG12(v)   (((v) << BP_CCM_CCGR2_CG12) & BM_CCM_CCGR2_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR2_CG12(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG12) | BF_CCM_CCGR2_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG13[27:26] (RW)
 *
 * ipsync_vdoa_ipg clocks (ipsync_vdoa_ipg_master_clk_enable)
 */

#define BP_CCM_CCGR2_CG13      (26)      //!< Bit position for CCM_CCGR2_CG13.
#define BM_CCM_CCGR2_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR2_CG13.

//! @brief Get value of CCM_CCGR2_CG13 from a register value.
#define BG_CCM_CCGR2_CG13(r)   (((r) & BM_CCM_CCGR2_CG13) >> BP_CCM_CCGR2_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG13.
#define BF_CCM_CCGR2_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG13) & BM_CCM_CCGR2_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG13.
#define BF_CCM_CCGR2_CG13(v)   (((v) << BP_CCM_CCGR2_CG13) & BM_CCM_CCGR2_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR2_CG13(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG13) | BF_CCM_CCGR2_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG14[29:28] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG14      (28)      //!< Bit position for CCM_CCGR2_CG14.
#define BM_CCM_CCGR2_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR2_CG14.

//! @brief Get value of CCM_CCGR2_CG14 from a register value.
#define BG_CCM_CCGR2_CG14(r)   (((r) & BM_CCM_CCGR2_CG14) >> BP_CCM_CCGR2_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG14.
#define BF_CCM_CCGR2_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG14) & BM_CCM_CCGR2_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG14.
#define BF_CCM_CCGR2_CG14(v)   (((v) << BP_CCM_CCGR2_CG14) & BM_CCM_CCGR2_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR2_CG14(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG14) | BF_CCM_CCGR2_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR2, field CG15[31:30] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR2_CG15      (30)      //!< Bit position for CCM_CCGR2_CG15.
#define BM_CCM_CCGR2_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR2_CG15.

//! @brief Get value of CCM_CCGR2_CG15 from a register value.
#define BG_CCM_CCGR2_CG15(r)   (((r) & BM_CCM_CCGR2_CG15) >> BP_CCM_CCGR2_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR2_CG15.
#define BF_CCM_CCGR2_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR2_CG15) & BM_CCM_CCGR2_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR2_CG15.
#define BF_CCM_CCGR2_CG15(v)   (((v) << BP_CCM_CCGR2_CG15) & BM_CCM_CCGR2_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR2_CG15(v)   (HW_CCM_CCGR2_WR((HW_CCM_CCGR2_RD() & ~BM_CCM_CCGR2_CG15) | BF_CCM_CCGR2_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR3 - CCM Clock Gating Register 3 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 3 (CCM_CCGR3). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr3
{
    reg32_t U;
    struct _hw_ccm_ccgr3_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] ipu1_ipu clock (ipu1_ipu_clk_enable)
        unsigned CG1 : 2; //!< [3:2] ipu1_ipu_di0 clock (ipu1_ipu_di0_clk_enable)
        unsigned CG2 : 2; //!< [5:4] ipu1_ipu_di1 clock (ipu1_ipu_di1_clk_enable)
        unsigned CG3 : 2; //!< [7:6] ipu2_ipu clock (ipu2_ipu_clk_enable) epdc/lcdif/pxp clock (epdc_axi_clk_enable)
        unsigned CG4 : 2; //!< [9:8] ipu2_ipu_di0 clock (ipu2_ipu_di0_clk_enable) lcdif_pix clock (lcdif_pix_clk_enable)
        unsigned CG5 : 2; //!< [11:10] ipu2_ipu_di1 clock (ipu2_ipu_di1_clk_enable) epdc_pix clock (epdc_pix_clk_enable)
        unsigned CG6 : 2; //!< [13:12] ldb_di0 clock (ldb_di0_clk_enable)
        unsigned CG7 : 2; //!< [15:14] ldb_di1 clock (ldb_di1_clk_enable)
        unsigned CG8 : 2; //!< [17:16] mipi_core_cfg clock (mipi_core_cfg_clk_enable)
        unsigned CG9 : 2; //!< [19:18] mlb clock (mlb_clk_enable)
        unsigned CG10 : 2; //!< [21:20] mmdc_core_aclk_fast_core_p0 clock (mmdc_core_aclk_fast_core_p0_enable)
        unsigned CG11 : 2; //!< [23:22] mmdc_core_aclk_fast_core_p1 clock (mmdc_core_aclk_fast_core_p1_enable)
        unsigned CG12 : 2; //!< [25:24] mmdc_core_ipg_clk_p0 clock (mmdc_core_ipg_clk_p0_enable)
        unsigned CG13 : 2; //!< [27:26] mmdc_core_ipg_clk_p1 clock (mmdc_core_ipg_clk_p1_enable)
        unsigned CG14 : 2; //!< [29:28] ocram clock (ocram_clk_enable)
        unsigned CG15 : 2; //!< [31:30] openvgaxiclk clock (openvgaxiclk_clk_root_enable)
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

/* --- Register HW_CCM_CCGR3, field CG0[1:0] (RW)
 *
 * ipu1_ipu clock (ipu1_ipu_clk_enable)
 */

#define BP_CCM_CCGR3_CG0      (0)      //!< Bit position for CCM_CCGR3_CG0.
#define BM_CCM_CCGR3_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR3_CG0.

//! @brief Get value of CCM_CCGR3_CG0 from a register value.
#define BG_CCM_CCGR3_CG0(r)   (((r) & BM_CCM_CCGR3_CG0) >> BP_CCM_CCGR3_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG0.
#define BF_CCM_CCGR3_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG0) & BM_CCM_CCGR3_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG0.
#define BF_CCM_CCGR3_CG0(v)   (((v) << BP_CCM_CCGR3_CG0) & BM_CCM_CCGR3_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR3_CG0(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG0) | BF_CCM_CCGR3_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG1[3:2] (RW)
 *
 * ipu1_ipu_di0 clock (ipu1_ipu_di0_clk_enable)
 */

#define BP_CCM_CCGR3_CG1      (2)      //!< Bit position for CCM_CCGR3_CG1.
#define BM_CCM_CCGR3_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR3_CG1.

//! @brief Get value of CCM_CCGR3_CG1 from a register value.
#define BG_CCM_CCGR3_CG1(r)   (((r) & BM_CCM_CCGR3_CG1) >> BP_CCM_CCGR3_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG1.
#define BF_CCM_CCGR3_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG1) & BM_CCM_CCGR3_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG1.
#define BF_CCM_CCGR3_CG1(v)   (((v) << BP_CCM_CCGR3_CG1) & BM_CCM_CCGR3_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR3_CG1(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG1) | BF_CCM_CCGR3_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG2[5:4] (RW)
 *
 * ipu1_ipu_di1 clock (ipu1_ipu_di1_clk_enable)
 */

#define BP_CCM_CCGR3_CG2      (4)      //!< Bit position for CCM_CCGR3_CG2.
#define BM_CCM_CCGR3_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR3_CG2.

//! @brief Get value of CCM_CCGR3_CG2 from a register value.
#define BG_CCM_CCGR3_CG2(r)   (((r) & BM_CCM_CCGR3_CG2) >> BP_CCM_CCGR3_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG2.
#define BF_CCM_CCGR3_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG2) & BM_CCM_CCGR3_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG2.
#define BF_CCM_CCGR3_CG2(v)   (((v) << BP_CCM_CCGR3_CG2) & BM_CCM_CCGR3_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR3_CG2(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG2) | BF_CCM_CCGR3_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG3[7:6] (RW)
 *
 * ipu2_ipu clock (ipu2_ipu_clk_enable) epdc/lcdif/pxp clock (epdc_axi_clk_enable)
 */

#define BP_CCM_CCGR3_CG3      (6)      //!< Bit position for CCM_CCGR3_CG3.
#define BM_CCM_CCGR3_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR3_CG3.

//! @brief Get value of CCM_CCGR3_CG3 from a register value.
#define BG_CCM_CCGR3_CG3(r)   (((r) & BM_CCM_CCGR3_CG3) >> BP_CCM_CCGR3_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG3.
#define BF_CCM_CCGR3_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG3) & BM_CCM_CCGR3_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG3.
#define BF_CCM_CCGR3_CG3(v)   (((v) << BP_CCM_CCGR3_CG3) & BM_CCM_CCGR3_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR3_CG3(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG3) | BF_CCM_CCGR3_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG4[9:8] (RW)
 *
 * ipu2_ipu_di0 clock (ipu2_ipu_di0_clk_enable) lcdif_pix clock (lcdif_pix_clk_enable)
 */

#define BP_CCM_CCGR3_CG4      (8)      //!< Bit position for CCM_CCGR3_CG4.
#define BM_CCM_CCGR3_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR3_CG4.

//! @brief Get value of CCM_CCGR3_CG4 from a register value.
#define BG_CCM_CCGR3_CG4(r)   (((r) & BM_CCM_CCGR3_CG4) >> BP_CCM_CCGR3_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG4.
#define BF_CCM_CCGR3_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG4) & BM_CCM_CCGR3_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG4.
#define BF_CCM_CCGR3_CG4(v)   (((v) << BP_CCM_CCGR3_CG4) & BM_CCM_CCGR3_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR3_CG4(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG4) | BF_CCM_CCGR3_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG5[11:10] (RW)
 *
 * ipu2_ipu_di1 clock (ipu2_ipu_di1_clk_enable) epdc_pix clock (epdc_pix_clk_enable)
 */

#define BP_CCM_CCGR3_CG5      (10)      //!< Bit position for CCM_CCGR3_CG5.
#define BM_CCM_CCGR3_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR3_CG5.

//! @brief Get value of CCM_CCGR3_CG5 from a register value.
#define BG_CCM_CCGR3_CG5(r)   (((r) & BM_CCM_CCGR3_CG5) >> BP_CCM_CCGR3_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG5.
#define BF_CCM_CCGR3_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG5) & BM_CCM_CCGR3_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG5.
#define BF_CCM_CCGR3_CG5(v)   (((v) << BP_CCM_CCGR3_CG5) & BM_CCM_CCGR3_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR3_CG5(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG5) | BF_CCM_CCGR3_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG6[13:12] (RW)
 *
 * ldb_di0 clock (ldb_di0_clk_enable)
 */

#define BP_CCM_CCGR3_CG6      (12)      //!< Bit position for CCM_CCGR3_CG6.
#define BM_CCM_CCGR3_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR3_CG6.

//! @brief Get value of CCM_CCGR3_CG6 from a register value.
#define BG_CCM_CCGR3_CG6(r)   (((r) & BM_CCM_CCGR3_CG6) >> BP_CCM_CCGR3_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG6.
#define BF_CCM_CCGR3_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG6) & BM_CCM_CCGR3_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG6.
#define BF_CCM_CCGR3_CG6(v)   (((v) << BP_CCM_CCGR3_CG6) & BM_CCM_CCGR3_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR3_CG6(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG6) | BF_CCM_CCGR3_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG7[15:14] (RW)
 *
 * ldb_di1 clock (ldb_di1_clk_enable)
 */

#define BP_CCM_CCGR3_CG7      (14)      //!< Bit position for CCM_CCGR3_CG7.
#define BM_CCM_CCGR3_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR3_CG7.

//! @brief Get value of CCM_CCGR3_CG7 from a register value.
#define BG_CCM_CCGR3_CG7(r)   (((r) & BM_CCM_CCGR3_CG7) >> BP_CCM_CCGR3_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG7.
#define BF_CCM_CCGR3_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG7) & BM_CCM_CCGR3_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG7.
#define BF_CCM_CCGR3_CG7(v)   (((v) << BP_CCM_CCGR3_CG7) & BM_CCM_CCGR3_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR3_CG7(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG7) | BF_CCM_CCGR3_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG8[17:16] (RW)
 *
 * mipi_core_cfg clock (mipi_core_cfg_clk_enable)
 */

#define BP_CCM_CCGR3_CG8      (16)      //!< Bit position for CCM_CCGR3_CG8.
#define BM_CCM_CCGR3_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR3_CG8.

//! @brief Get value of CCM_CCGR3_CG8 from a register value.
#define BG_CCM_CCGR3_CG8(r)   (((r) & BM_CCM_CCGR3_CG8) >> BP_CCM_CCGR3_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG8.
#define BF_CCM_CCGR3_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG8) & BM_CCM_CCGR3_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG8.
#define BF_CCM_CCGR3_CG8(v)   (((v) << BP_CCM_CCGR3_CG8) & BM_CCM_CCGR3_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR3_CG8(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG8) | BF_CCM_CCGR3_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG9[19:18] (RW)
 *
 * mlb clock (mlb_clk_enable)
 */

#define BP_CCM_CCGR3_CG9      (18)      //!< Bit position for CCM_CCGR3_CG9.
#define BM_CCM_CCGR3_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR3_CG9.

//! @brief Get value of CCM_CCGR3_CG9 from a register value.
#define BG_CCM_CCGR3_CG9(r)   (((r) & BM_CCM_CCGR3_CG9) >> BP_CCM_CCGR3_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG9.
#define BF_CCM_CCGR3_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG9) & BM_CCM_CCGR3_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG9.
#define BF_CCM_CCGR3_CG9(v)   (((v) << BP_CCM_CCGR3_CG9) & BM_CCM_CCGR3_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR3_CG9(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG9) | BF_CCM_CCGR3_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG10[21:20] (RW)
 *
 * mmdc_core_aclk_fast_core_p0 clock (mmdc_core_aclk_fast_core_p0_enable)
 */

#define BP_CCM_CCGR3_CG10      (20)      //!< Bit position for CCM_CCGR3_CG10.
#define BM_CCM_CCGR3_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR3_CG10.

//! @brief Get value of CCM_CCGR3_CG10 from a register value.
#define BG_CCM_CCGR3_CG10(r)   (((r) & BM_CCM_CCGR3_CG10) >> BP_CCM_CCGR3_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG10.
#define BF_CCM_CCGR3_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG10) & BM_CCM_CCGR3_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG10.
#define BF_CCM_CCGR3_CG10(v)   (((v) << BP_CCM_CCGR3_CG10) & BM_CCM_CCGR3_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR3_CG10(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG10) | BF_CCM_CCGR3_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG11[23:22] (RW)
 *
 * mmdc_core_aclk_fast_core_p1 clock (mmdc_core_aclk_fast_core_p1_enable)
 */

#define BP_CCM_CCGR3_CG11      (22)      //!< Bit position for CCM_CCGR3_CG11.
#define BM_CCM_CCGR3_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR3_CG11.

//! @brief Get value of CCM_CCGR3_CG11 from a register value.
#define BG_CCM_CCGR3_CG11(r)   (((r) & BM_CCM_CCGR3_CG11) >> BP_CCM_CCGR3_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG11.
#define BF_CCM_CCGR3_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG11) & BM_CCM_CCGR3_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG11.
#define BF_CCM_CCGR3_CG11(v)   (((v) << BP_CCM_CCGR3_CG11) & BM_CCM_CCGR3_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR3_CG11(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG11) | BF_CCM_CCGR3_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG12[25:24] (RW)
 *
 * mmdc_core_ipg_clk_p0 clock (mmdc_core_ipg_clk_p0_enable)
 */

#define BP_CCM_CCGR3_CG12      (24)      //!< Bit position for CCM_CCGR3_CG12.
#define BM_CCM_CCGR3_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR3_CG12.

//! @brief Get value of CCM_CCGR3_CG12 from a register value.
#define BG_CCM_CCGR3_CG12(r)   (((r) & BM_CCM_CCGR3_CG12) >> BP_CCM_CCGR3_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG12.
#define BF_CCM_CCGR3_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG12) & BM_CCM_CCGR3_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG12.
#define BF_CCM_CCGR3_CG12(v)   (((v) << BP_CCM_CCGR3_CG12) & BM_CCM_CCGR3_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR3_CG12(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG12) | BF_CCM_CCGR3_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG13[27:26] (RW)
 *
 * mmdc_core_ipg_clk_p1 clock (mmdc_core_ipg_clk_p1_enable)
 */

#define BP_CCM_CCGR3_CG13      (26)      //!< Bit position for CCM_CCGR3_CG13.
#define BM_CCM_CCGR3_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR3_CG13.

//! @brief Get value of CCM_CCGR3_CG13 from a register value.
#define BG_CCM_CCGR3_CG13(r)   (((r) & BM_CCM_CCGR3_CG13) >> BP_CCM_CCGR3_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG13.
#define BF_CCM_CCGR3_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG13) & BM_CCM_CCGR3_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG13.
#define BF_CCM_CCGR3_CG13(v)   (((v) << BP_CCM_CCGR3_CG13) & BM_CCM_CCGR3_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR3_CG13(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG13) | BF_CCM_CCGR3_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG14[29:28] (RW)
 *
 * ocram clock (ocram_clk_enable)
 */

#define BP_CCM_CCGR3_CG14      (28)      //!< Bit position for CCM_CCGR3_CG14.
#define BM_CCM_CCGR3_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR3_CG14.

//! @brief Get value of CCM_CCGR3_CG14 from a register value.
#define BG_CCM_CCGR3_CG14(r)   (((r) & BM_CCM_CCGR3_CG14) >> BP_CCM_CCGR3_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG14.
#define BF_CCM_CCGR3_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG14) & BM_CCM_CCGR3_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG14.
#define BF_CCM_CCGR3_CG14(v)   (((v) << BP_CCM_CCGR3_CG14) & BM_CCM_CCGR3_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR3_CG14(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG14) | BF_CCM_CCGR3_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR3, field CG15[31:30] (RW)
 *
 * openvgaxiclk clock (openvgaxiclk_clk_root_enable)
 */

#define BP_CCM_CCGR3_CG15      (30)      //!< Bit position for CCM_CCGR3_CG15.
#define BM_CCM_CCGR3_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR3_CG15.

//! @brief Get value of CCM_CCGR3_CG15 from a register value.
#define BG_CCM_CCGR3_CG15(r)   (((r) & BM_CCM_CCGR3_CG15) >> BP_CCM_CCGR3_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR3_CG15.
#define BF_CCM_CCGR3_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR3_CG15) & BM_CCM_CCGR3_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR3_CG15.
#define BF_CCM_CCGR3_CG15(v)   (((v) << BP_CCM_CCGR3_CG15) & BM_CCM_CCGR3_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR3_CG15(v)   (HW_CCM_CCGR3_WR((HW_CCM_CCGR3_RD() & ~BM_CCM_CCGR3_CG15) | BF_CCM_CCGR3_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR4 - CCM Clock Gating Register 4 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 4 (CCM_CCGR4). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr4
{
    reg32_t U;
    struct _hw_ccm_ccgr4_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] pcie clocks (pcie_root_enable)
        unsigned CG1 : 2; //!< [3:2] perfmon1 clocks (perfmon1_apb_clk_enable) Reserved.
        unsigned CG2 : 2; //!< [5:4] perfmon2 clock (perfmon2_apb_clk_enable) Reserved.
        unsigned CG3 : 2; //!< [7:6] perfmon3 clocks (perfmon3_apb_clk_enable) Reserved.
        unsigned CG4 : 2; //!< [9:8] pl301_mx6qfast1_s133 clock (pl301_mx6qfast1_s133clk_enable)
        unsigned CG5 : 2; //!< [11:10] Reserved
        unsigned CG6 : 2; //!< [13:12] pl301_mx6qper1_bch clocks (pl301_mx6qper1_bchclk_enable)
        unsigned CG7 : 2; //!< [15:14] pl301_mx6qper2_mainclk_enable (pl301_mx6qper2_mainclk_enable)
        unsigned CG8 : 2; //!< [17:16] pwm1 clocks (pwm1_clk_enable)
        unsigned CG9 : 2; //!< [19:18] pwm2 clocks (pwm2_clk_enable)
        unsigned CG10 : 2; //!< [21:20] pwm3 clocks (pwm3_clk_enable)
        unsigned CG11 : 2; //!< [23:22] pwm4 clocks (pwm4_clk_enable)
        unsigned CG12 : 2; //!< [25:24] rawnand_u_bch_input_apb clock (rawnand_u_bch_input_apb_clk_enable)
        unsigned CG13 : 2; //!< [27:26] rawnand_u_gpmi_bch_input_bch clock (rawnand_u_gpmi_bch_input_bch_clk_enable)
        unsigned CG14 : 2; //!< [29:28] rawnand_u_gpmi_bch_input_gpmi_io clock (rawnand_u_gpmi_bch_input_gpmi_io_clk_enable)
        unsigned CG15 : 2; //!< [31:30] rawnand_u_gpmi_input_apb clock rawnand_u_gpmi_input_apb_clk_enable)
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

/* --- Register HW_CCM_CCGR4, field CG0[1:0] (RW)
 *
 * pcie clocks (pcie_root_enable)
 */

#define BP_CCM_CCGR4_CG0      (0)      //!< Bit position for CCM_CCGR4_CG0.
#define BM_CCM_CCGR4_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR4_CG0.

//! @brief Get value of CCM_CCGR4_CG0 from a register value.
#define BG_CCM_CCGR4_CG0(r)   (((r) & BM_CCM_CCGR4_CG0) >> BP_CCM_CCGR4_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG0.
#define BF_CCM_CCGR4_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG0) & BM_CCM_CCGR4_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG0.
#define BF_CCM_CCGR4_CG0(v)   (((v) << BP_CCM_CCGR4_CG0) & BM_CCM_CCGR4_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR4_CG0(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG0) | BF_CCM_CCGR4_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG1[3:2] (RW)
 *
 * perfmon1 clocks (perfmon1_apb_clk_enable) Reserved.
 */

#define BP_CCM_CCGR4_CG1      (2)      //!< Bit position for CCM_CCGR4_CG1.
#define BM_CCM_CCGR4_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR4_CG1.

//! @brief Get value of CCM_CCGR4_CG1 from a register value.
#define BG_CCM_CCGR4_CG1(r)   (((r) & BM_CCM_CCGR4_CG1) >> BP_CCM_CCGR4_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG1.
#define BF_CCM_CCGR4_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG1) & BM_CCM_CCGR4_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG1.
#define BF_CCM_CCGR4_CG1(v)   (((v) << BP_CCM_CCGR4_CG1) & BM_CCM_CCGR4_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR4_CG1(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG1) | BF_CCM_CCGR4_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG2[5:4] (RW)
 *
 * perfmon2 clock (perfmon2_apb_clk_enable) Reserved.
 */

#define BP_CCM_CCGR4_CG2      (4)      //!< Bit position for CCM_CCGR4_CG2.
#define BM_CCM_CCGR4_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR4_CG2.

//! @brief Get value of CCM_CCGR4_CG2 from a register value.
#define BG_CCM_CCGR4_CG2(r)   (((r) & BM_CCM_CCGR4_CG2) >> BP_CCM_CCGR4_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG2.
#define BF_CCM_CCGR4_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG2) & BM_CCM_CCGR4_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG2.
#define BF_CCM_CCGR4_CG2(v)   (((v) << BP_CCM_CCGR4_CG2) & BM_CCM_CCGR4_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR4_CG2(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG2) | BF_CCM_CCGR4_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG3[7:6] (RW)
 *
 * perfmon3 clocks (perfmon3_apb_clk_enable) Reserved.
 */

#define BP_CCM_CCGR4_CG3      (6)      //!< Bit position for CCM_CCGR4_CG3.
#define BM_CCM_CCGR4_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR4_CG3.

//! @brief Get value of CCM_CCGR4_CG3 from a register value.
#define BG_CCM_CCGR4_CG3(r)   (((r) & BM_CCM_CCGR4_CG3) >> BP_CCM_CCGR4_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG3.
#define BF_CCM_CCGR4_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG3) & BM_CCM_CCGR4_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG3.
#define BF_CCM_CCGR4_CG3(v)   (((v) << BP_CCM_CCGR4_CG3) & BM_CCM_CCGR4_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR4_CG3(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG3) | BF_CCM_CCGR4_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG4[9:8] (RW)
 *
 * pl301_mx6qfast1_s133 clock (pl301_mx6qfast1_s133clk_enable)
 */

#define BP_CCM_CCGR4_CG4      (8)      //!< Bit position for CCM_CCGR4_CG4.
#define BM_CCM_CCGR4_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR4_CG4.

//! @brief Get value of CCM_CCGR4_CG4 from a register value.
#define BG_CCM_CCGR4_CG4(r)   (((r) & BM_CCM_CCGR4_CG4) >> BP_CCM_CCGR4_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG4.
#define BF_CCM_CCGR4_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG4) & BM_CCM_CCGR4_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG4.
#define BF_CCM_CCGR4_CG4(v)   (((v) << BP_CCM_CCGR4_CG4) & BM_CCM_CCGR4_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR4_CG4(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG4) | BF_CCM_CCGR4_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG5[11:10] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR4_CG5      (10)      //!< Bit position for CCM_CCGR4_CG5.
#define BM_CCM_CCGR4_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR4_CG5.

//! @brief Get value of CCM_CCGR4_CG5 from a register value.
#define BG_CCM_CCGR4_CG5(r)   (((r) & BM_CCM_CCGR4_CG5) >> BP_CCM_CCGR4_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG5.
#define BF_CCM_CCGR4_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG5) & BM_CCM_CCGR4_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG5.
#define BF_CCM_CCGR4_CG5(v)   (((v) << BP_CCM_CCGR4_CG5) & BM_CCM_CCGR4_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR4_CG5(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG5) | BF_CCM_CCGR4_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG6[13:12] (RW)
 *
 * pl301_mx6qper1_bch clocks (pl301_mx6qper1_bchclk_enable)
 */

#define BP_CCM_CCGR4_CG6      (12)      //!< Bit position for CCM_CCGR4_CG6.
#define BM_CCM_CCGR4_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR4_CG6.

//! @brief Get value of CCM_CCGR4_CG6 from a register value.
#define BG_CCM_CCGR4_CG6(r)   (((r) & BM_CCM_CCGR4_CG6) >> BP_CCM_CCGR4_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG6.
#define BF_CCM_CCGR4_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG6) & BM_CCM_CCGR4_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG6.
#define BF_CCM_CCGR4_CG6(v)   (((v) << BP_CCM_CCGR4_CG6) & BM_CCM_CCGR4_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR4_CG6(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG6) | BF_CCM_CCGR4_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG7[15:14] (RW)
 *
 * pl301_mx6qper2_mainclk_enable (pl301_mx6qper2_mainclk_enable)
 */

#define BP_CCM_CCGR4_CG7      (14)      //!< Bit position for CCM_CCGR4_CG7.
#define BM_CCM_CCGR4_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR4_CG7.

//! @brief Get value of CCM_CCGR4_CG7 from a register value.
#define BG_CCM_CCGR4_CG7(r)   (((r) & BM_CCM_CCGR4_CG7) >> BP_CCM_CCGR4_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG7.
#define BF_CCM_CCGR4_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG7) & BM_CCM_CCGR4_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG7.
#define BF_CCM_CCGR4_CG7(v)   (((v) << BP_CCM_CCGR4_CG7) & BM_CCM_CCGR4_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR4_CG7(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG7) | BF_CCM_CCGR4_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG8[17:16] (RW)
 *
 * pwm1 clocks (pwm1_clk_enable)
 */

#define BP_CCM_CCGR4_CG8      (16)      //!< Bit position for CCM_CCGR4_CG8.
#define BM_CCM_CCGR4_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR4_CG8.

//! @brief Get value of CCM_CCGR4_CG8 from a register value.
#define BG_CCM_CCGR4_CG8(r)   (((r) & BM_CCM_CCGR4_CG8) >> BP_CCM_CCGR4_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG8.
#define BF_CCM_CCGR4_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG8) & BM_CCM_CCGR4_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG8.
#define BF_CCM_CCGR4_CG8(v)   (((v) << BP_CCM_CCGR4_CG8) & BM_CCM_CCGR4_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR4_CG8(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG8) | BF_CCM_CCGR4_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG9[19:18] (RW)
 *
 * pwm2 clocks (pwm2_clk_enable)
 */

#define BP_CCM_CCGR4_CG9      (18)      //!< Bit position for CCM_CCGR4_CG9.
#define BM_CCM_CCGR4_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR4_CG9.

//! @brief Get value of CCM_CCGR4_CG9 from a register value.
#define BG_CCM_CCGR4_CG9(r)   (((r) & BM_CCM_CCGR4_CG9) >> BP_CCM_CCGR4_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG9.
#define BF_CCM_CCGR4_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG9) & BM_CCM_CCGR4_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG9.
#define BF_CCM_CCGR4_CG9(v)   (((v) << BP_CCM_CCGR4_CG9) & BM_CCM_CCGR4_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR4_CG9(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG9) | BF_CCM_CCGR4_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG10[21:20] (RW)
 *
 * pwm3 clocks (pwm3_clk_enable)
 */

#define BP_CCM_CCGR4_CG10      (20)      //!< Bit position for CCM_CCGR4_CG10.
#define BM_CCM_CCGR4_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR4_CG10.

//! @brief Get value of CCM_CCGR4_CG10 from a register value.
#define BG_CCM_CCGR4_CG10(r)   (((r) & BM_CCM_CCGR4_CG10) >> BP_CCM_CCGR4_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG10.
#define BF_CCM_CCGR4_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG10) & BM_CCM_CCGR4_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG10.
#define BF_CCM_CCGR4_CG10(v)   (((v) << BP_CCM_CCGR4_CG10) & BM_CCM_CCGR4_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR4_CG10(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG10) | BF_CCM_CCGR4_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG11[23:22] (RW)
 *
 * pwm4 clocks (pwm4_clk_enable)
 */

#define BP_CCM_CCGR4_CG11      (22)      //!< Bit position for CCM_CCGR4_CG11.
#define BM_CCM_CCGR4_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR4_CG11.

//! @brief Get value of CCM_CCGR4_CG11 from a register value.
#define BG_CCM_CCGR4_CG11(r)   (((r) & BM_CCM_CCGR4_CG11) >> BP_CCM_CCGR4_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG11.
#define BF_CCM_CCGR4_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG11) & BM_CCM_CCGR4_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG11.
#define BF_CCM_CCGR4_CG11(v)   (((v) << BP_CCM_CCGR4_CG11) & BM_CCM_CCGR4_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR4_CG11(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG11) | BF_CCM_CCGR4_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG12[25:24] (RW)
 *
 * rawnand_u_bch_input_apb clock (rawnand_u_bch_input_apb_clk_enable)
 */

#define BP_CCM_CCGR4_CG12      (24)      //!< Bit position for CCM_CCGR4_CG12.
#define BM_CCM_CCGR4_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR4_CG12.

//! @brief Get value of CCM_CCGR4_CG12 from a register value.
#define BG_CCM_CCGR4_CG12(r)   (((r) & BM_CCM_CCGR4_CG12) >> BP_CCM_CCGR4_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG12.
#define BF_CCM_CCGR4_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG12) & BM_CCM_CCGR4_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG12.
#define BF_CCM_CCGR4_CG12(v)   (((v) << BP_CCM_CCGR4_CG12) & BM_CCM_CCGR4_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR4_CG12(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG12) | BF_CCM_CCGR4_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG13[27:26] (RW)
 *
 * rawnand_u_gpmi_bch_input_bch clock (rawnand_u_gpmi_bch_input_bch_clk_enable)
 */

#define BP_CCM_CCGR4_CG13      (26)      //!< Bit position for CCM_CCGR4_CG13.
#define BM_CCM_CCGR4_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR4_CG13.

//! @brief Get value of CCM_CCGR4_CG13 from a register value.
#define BG_CCM_CCGR4_CG13(r)   (((r) & BM_CCM_CCGR4_CG13) >> BP_CCM_CCGR4_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG13.
#define BF_CCM_CCGR4_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG13) & BM_CCM_CCGR4_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG13.
#define BF_CCM_CCGR4_CG13(v)   (((v) << BP_CCM_CCGR4_CG13) & BM_CCM_CCGR4_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR4_CG13(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG13) | BF_CCM_CCGR4_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG14[29:28] (RW)
 *
 * rawnand_u_gpmi_bch_input_gpmi_io clock (rawnand_u_gpmi_bch_input_gpmi_io_clk_enable)
 */

#define BP_CCM_CCGR4_CG14      (28)      //!< Bit position for CCM_CCGR4_CG14.
#define BM_CCM_CCGR4_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR4_CG14.

//! @brief Get value of CCM_CCGR4_CG14 from a register value.
#define BG_CCM_CCGR4_CG14(r)   (((r) & BM_CCM_CCGR4_CG14) >> BP_CCM_CCGR4_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG14.
#define BF_CCM_CCGR4_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG14) & BM_CCM_CCGR4_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG14.
#define BF_CCM_CCGR4_CG14(v)   (((v) << BP_CCM_CCGR4_CG14) & BM_CCM_CCGR4_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR4_CG14(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG14) | BF_CCM_CCGR4_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR4, field CG15[31:30] (RW)
 *
 * rawnand_u_gpmi_input_apb clock rawnand_u_gpmi_input_apb_clk_enable)
 */

#define BP_CCM_CCGR4_CG15      (30)      //!< Bit position for CCM_CCGR4_CG15.
#define BM_CCM_CCGR4_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR4_CG15.

//! @brief Get value of CCM_CCGR4_CG15 from a register value.
#define BG_CCM_CCGR4_CG15(r)   (((r) & BM_CCM_CCGR4_CG15) >> BP_CCM_CCGR4_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR4_CG15.
#define BF_CCM_CCGR4_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR4_CG15) & BM_CCM_CCGR4_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR4_CG15.
#define BF_CCM_CCGR4_CG15(v)   (((v) << BP_CCM_CCGR4_CG15) & BM_CCM_CCGR4_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR4_CG15(v)   (HW_CCM_CCGR4_WR((HW_CCM_CCGR4_RD() & ~BM_CCM_CCGR4_CG15) | BF_CCM_CCGR4_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR5 - CCM Clock Gating Register 5 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 5 (CCM_CCGR5). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr5
{
    reg32_t U;
    struct _hw_ccm_ccgr5_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] rom clock (rom_clk_enable)
        unsigned CG1 : 2; //!< [3:2] Reserved
        unsigned CG2 : 2; //!< [5:4] sata clock (sata_clk_enable)
        unsigned CG3 : 2; //!< [7:6] sdma clock (sdma_clk_enable)
        unsigned CG4 : 2; //!< [9:8] Reserved
        unsigned CG5 : 2; //!< [11:10] Reserved
        unsigned CG6 : 2; //!< [13:12] spba clock (spba_clk_enable)
        unsigned CG7 : 2; //!< [15:14] spdif clock (spdif_clk_enable)
        unsigned CG8 : 2; //!< [17:16] Reserved
        unsigned CG9 : 2; //!< [19:18] ssi1 clocks (ssi1_clk_enable)
        unsigned CG10 : 2; //!< [21:20] ssi2 clocks (ssi2_clk_enable)
        unsigned CG11 : 2; //!< [23:22] ssi3 clocks (ssi3_clk_enable)
        unsigned CG12 : 2; //!< [25:24] uart clock (uart_clk_enable)
        unsigned CG13 : 2; //!< [27:26] uart_serial clock (uart_serial_clk_enable)
        unsigned CG14 : 2; //!< [29:28] Reserved
        unsigned CG15 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CCGR5, field CG0[1:0] (RW)
 *
 * rom clock (rom_clk_enable)
 */

#define BP_CCM_CCGR5_CG0      (0)      //!< Bit position for CCM_CCGR5_CG0.
#define BM_CCM_CCGR5_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR5_CG0.

//! @brief Get value of CCM_CCGR5_CG0 from a register value.
#define BG_CCM_CCGR5_CG0(r)   (((r) & BM_CCM_CCGR5_CG0) >> BP_CCM_CCGR5_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG0.
#define BF_CCM_CCGR5_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG0) & BM_CCM_CCGR5_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG0.
#define BF_CCM_CCGR5_CG0(v)   (((v) << BP_CCM_CCGR5_CG0) & BM_CCM_CCGR5_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR5_CG0(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG0) | BF_CCM_CCGR5_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG1[3:2] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG1      (2)      //!< Bit position for CCM_CCGR5_CG1.
#define BM_CCM_CCGR5_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR5_CG1.

//! @brief Get value of CCM_CCGR5_CG1 from a register value.
#define BG_CCM_CCGR5_CG1(r)   (((r) & BM_CCM_CCGR5_CG1) >> BP_CCM_CCGR5_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG1.
#define BF_CCM_CCGR5_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG1) & BM_CCM_CCGR5_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG1.
#define BF_CCM_CCGR5_CG1(v)   (((v) << BP_CCM_CCGR5_CG1) & BM_CCM_CCGR5_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR5_CG1(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG1) | BF_CCM_CCGR5_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG2[5:4] (RW)
 *
 * sata clock (sata_clk_enable)
 */

#define BP_CCM_CCGR5_CG2      (4)      //!< Bit position for CCM_CCGR5_CG2.
#define BM_CCM_CCGR5_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR5_CG2.

//! @brief Get value of CCM_CCGR5_CG2 from a register value.
#define BG_CCM_CCGR5_CG2(r)   (((r) & BM_CCM_CCGR5_CG2) >> BP_CCM_CCGR5_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG2.
#define BF_CCM_CCGR5_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG2) & BM_CCM_CCGR5_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG2.
#define BF_CCM_CCGR5_CG2(v)   (((v) << BP_CCM_CCGR5_CG2) & BM_CCM_CCGR5_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR5_CG2(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG2) | BF_CCM_CCGR5_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG3[7:6] (RW)
 *
 * sdma clock (sdma_clk_enable)
 */

#define BP_CCM_CCGR5_CG3      (6)      //!< Bit position for CCM_CCGR5_CG3.
#define BM_CCM_CCGR5_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR5_CG3.

//! @brief Get value of CCM_CCGR5_CG3 from a register value.
#define BG_CCM_CCGR5_CG3(r)   (((r) & BM_CCM_CCGR5_CG3) >> BP_CCM_CCGR5_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG3.
#define BF_CCM_CCGR5_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG3) & BM_CCM_CCGR5_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG3.
#define BF_CCM_CCGR5_CG3(v)   (((v) << BP_CCM_CCGR5_CG3) & BM_CCM_CCGR5_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR5_CG3(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG3) | BF_CCM_CCGR5_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG4[9:8] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG4      (8)      //!< Bit position for CCM_CCGR5_CG4.
#define BM_CCM_CCGR5_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR5_CG4.

//! @brief Get value of CCM_CCGR5_CG4 from a register value.
#define BG_CCM_CCGR5_CG4(r)   (((r) & BM_CCM_CCGR5_CG4) >> BP_CCM_CCGR5_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG4.
#define BF_CCM_CCGR5_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG4) & BM_CCM_CCGR5_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG4.
#define BF_CCM_CCGR5_CG4(v)   (((v) << BP_CCM_CCGR5_CG4) & BM_CCM_CCGR5_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR5_CG4(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG4) | BF_CCM_CCGR5_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG5[11:10] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG5      (10)      //!< Bit position for CCM_CCGR5_CG5.
#define BM_CCM_CCGR5_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR5_CG5.

//! @brief Get value of CCM_CCGR5_CG5 from a register value.
#define BG_CCM_CCGR5_CG5(r)   (((r) & BM_CCM_CCGR5_CG5) >> BP_CCM_CCGR5_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG5.
#define BF_CCM_CCGR5_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG5) & BM_CCM_CCGR5_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG5.
#define BF_CCM_CCGR5_CG5(v)   (((v) << BP_CCM_CCGR5_CG5) & BM_CCM_CCGR5_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR5_CG5(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG5) | BF_CCM_CCGR5_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG6[13:12] (RW)
 *
 * spba clock (spba_clk_enable)
 */

#define BP_CCM_CCGR5_CG6      (12)      //!< Bit position for CCM_CCGR5_CG6.
#define BM_CCM_CCGR5_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR5_CG6.

//! @brief Get value of CCM_CCGR5_CG6 from a register value.
#define BG_CCM_CCGR5_CG6(r)   (((r) & BM_CCM_CCGR5_CG6) >> BP_CCM_CCGR5_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG6.
#define BF_CCM_CCGR5_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG6) & BM_CCM_CCGR5_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG6.
#define BF_CCM_CCGR5_CG6(v)   (((v) << BP_CCM_CCGR5_CG6) & BM_CCM_CCGR5_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR5_CG6(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG6) | BF_CCM_CCGR5_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG7[15:14] (RW)
 *
 * spdif clock (spdif_clk_enable)
 */

#define BP_CCM_CCGR5_CG7      (14)      //!< Bit position for CCM_CCGR5_CG7.
#define BM_CCM_CCGR5_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR5_CG7.

//! @brief Get value of CCM_CCGR5_CG7 from a register value.
#define BG_CCM_CCGR5_CG7(r)   (((r) & BM_CCM_CCGR5_CG7) >> BP_CCM_CCGR5_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG7.
#define BF_CCM_CCGR5_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG7) & BM_CCM_CCGR5_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG7.
#define BF_CCM_CCGR5_CG7(v)   (((v) << BP_CCM_CCGR5_CG7) & BM_CCM_CCGR5_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR5_CG7(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG7) | BF_CCM_CCGR5_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG8[17:16] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG8      (16)      //!< Bit position for CCM_CCGR5_CG8.
#define BM_CCM_CCGR5_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR5_CG8.

//! @brief Get value of CCM_CCGR5_CG8 from a register value.
#define BG_CCM_CCGR5_CG8(r)   (((r) & BM_CCM_CCGR5_CG8) >> BP_CCM_CCGR5_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG8.
#define BF_CCM_CCGR5_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG8) & BM_CCM_CCGR5_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG8.
#define BF_CCM_CCGR5_CG8(v)   (((v) << BP_CCM_CCGR5_CG8) & BM_CCM_CCGR5_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR5_CG8(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG8) | BF_CCM_CCGR5_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG9[19:18] (RW)
 *
 * ssi1 clocks (ssi1_clk_enable)
 */

#define BP_CCM_CCGR5_CG9      (18)      //!< Bit position for CCM_CCGR5_CG9.
#define BM_CCM_CCGR5_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR5_CG9.

//! @brief Get value of CCM_CCGR5_CG9 from a register value.
#define BG_CCM_CCGR5_CG9(r)   (((r) & BM_CCM_CCGR5_CG9) >> BP_CCM_CCGR5_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG9.
#define BF_CCM_CCGR5_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG9) & BM_CCM_CCGR5_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG9.
#define BF_CCM_CCGR5_CG9(v)   (((v) << BP_CCM_CCGR5_CG9) & BM_CCM_CCGR5_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR5_CG9(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG9) | BF_CCM_CCGR5_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG10[21:20] (RW)
 *
 * ssi2 clocks (ssi2_clk_enable)
 */

#define BP_CCM_CCGR5_CG10      (20)      //!< Bit position for CCM_CCGR5_CG10.
#define BM_CCM_CCGR5_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR5_CG10.

//! @brief Get value of CCM_CCGR5_CG10 from a register value.
#define BG_CCM_CCGR5_CG10(r)   (((r) & BM_CCM_CCGR5_CG10) >> BP_CCM_CCGR5_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG10.
#define BF_CCM_CCGR5_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG10) & BM_CCM_CCGR5_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG10.
#define BF_CCM_CCGR5_CG10(v)   (((v) << BP_CCM_CCGR5_CG10) & BM_CCM_CCGR5_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR5_CG10(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG10) | BF_CCM_CCGR5_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG11[23:22] (RW)
 *
 * ssi3 clocks (ssi3_clk_enable)
 */

#define BP_CCM_CCGR5_CG11      (22)      //!< Bit position for CCM_CCGR5_CG11.
#define BM_CCM_CCGR5_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR5_CG11.

//! @brief Get value of CCM_CCGR5_CG11 from a register value.
#define BG_CCM_CCGR5_CG11(r)   (((r) & BM_CCM_CCGR5_CG11) >> BP_CCM_CCGR5_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG11.
#define BF_CCM_CCGR5_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG11) & BM_CCM_CCGR5_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG11.
#define BF_CCM_CCGR5_CG11(v)   (((v) << BP_CCM_CCGR5_CG11) & BM_CCM_CCGR5_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR5_CG11(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG11) | BF_CCM_CCGR5_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG12[25:24] (RW)
 *
 * uart clock (uart_clk_enable)
 */

#define BP_CCM_CCGR5_CG12      (24)      //!< Bit position for CCM_CCGR5_CG12.
#define BM_CCM_CCGR5_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR5_CG12.

//! @brief Get value of CCM_CCGR5_CG12 from a register value.
#define BG_CCM_CCGR5_CG12(r)   (((r) & BM_CCM_CCGR5_CG12) >> BP_CCM_CCGR5_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG12.
#define BF_CCM_CCGR5_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG12) & BM_CCM_CCGR5_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG12.
#define BF_CCM_CCGR5_CG12(v)   (((v) << BP_CCM_CCGR5_CG12) & BM_CCM_CCGR5_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR5_CG12(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG12) | BF_CCM_CCGR5_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG13[27:26] (RW)
 *
 * uart_serial clock (uart_serial_clk_enable)
 */

#define BP_CCM_CCGR5_CG13      (26)      //!< Bit position for CCM_CCGR5_CG13.
#define BM_CCM_CCGR5_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR5_CG13.

//! @brief Get value of CCM_CCGR5_CG13 from a register value.
#define BG_CCM_CCGR5_CG13(r)   (((r) & BM_CCM_CCGR5_CG13) >> BP_CCM_CCGR5_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG13.
#define BF_CCM_CCGR5_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG13) & BM_CCM_CCGR5_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG13.
#define BF_CCM_CCGR5_CG13(v)   (((v) << BP_CCM_CCGR5_CG13) & BM_CCM_CCGR5_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR5_CG13(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG13) | BF_CCM_CCGR5_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG14[29:28] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG14      (28)      //!< Bit position for CCM_CCGR5_CG14.
#define BM_CCM_CCGR5_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR5_CG14.

//! @brief Get value of CCM_CCGR5_CG14 from a register value.
#define BG_CCM_CCGR5_CG14(r)   (((r) & BM_CCM_CCGR5_CG14) >> BP_CCM_CCGR5_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG14.
#define BF_CCM_CCGR5_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG14) & BM_CCM_CCGR5_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG14.
#define BF_CCM_CCGR5_CG14(v)   (((v) << BP_CCM_CCGR5_CG14) & BM_CCM_CCGR5_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR5_CG14(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG14) | BF_CCM_CCGR5_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR5, field CG15[31:30] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR5_CG15      (30)      //!< Bit position for CCM_CCGR5_CG15.
#define BM_CCM_CCGR5_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR5_CG15.

//! @brief Get value of CCM_CCGR5_CG15 from a register value.
#define BG_CCM_CCGR5_CG15(r)   (((r) & BM_CCM_CCGR5_CG15) >> BP_CCM_CCGR5_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR5_CG15.
#define BF_CCM_CCGR5_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR5_CG15) & BM_CCM_CCGR5_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR5_CG15.
#define BF_CCM_CCGR5_CG15(v)   (((v) << BP_CCM_CCGR5_CG15) & BM_CCM_CCGR5_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR5_CG15(v)   (HW_CCM_CCGR5_WR((HW_CCM_CCGR5_RD() & ~BM_CCM_CCGR5_CG15) | BF_CCM_CCGR5_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR6 - CCM Clock Gating Register 6 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 6 (CCM_CCGR6). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.
 */
typedef union _hw_ccm_ccgr6
{
    reg32_t U;
    struct _hw_ccm_ccgr6_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] usboh3 clock (usboh3_clk_enable)
        unsigned CG1 : 2; //!< [3:2] usdhc1 clocks (usdhc1_clk_enable)
        unsigned CG2 : 2; //!< [5:4] usdhc2 clocks (usdhc2_clk_enable)
        unsigned CG3 : 2; //!< [7:6] usdhc3 clocks (usdhc3_clk_enable)
        unsigned CG4 : 2; //!< [9:8] usdhc4 clocks (usdhc4_clk_enable)
        unsigned CG5 : 2; //!< [11:10] emi_slow clocks (emi_slow_clk_enable)
        unsigned CG6 : 2; //!< [13:12] vdoaxiclk root clock (vdoaxiclk_clk_enable)
        unsigned CG7 : 2; //!< [15:14] vpu clocks (vpu_clk_enable)
        unsigned CG8 : 2; //!< [17:16] Reserved
        unsigned CG9 : 2; //!< [19:18] Reserved
        unsigned CG10 : 2; //!< [21:20] Reserved
        unsigned CG11 : 2; //!< [23:22] Reserved
        unsigned CG12 : 2; //!< [25:24] Reserved
        unsigned CG13 : 2; //!< [27:26] Reserved
        unsigned CG14 : 2; //!< [29:28] Reserved
        unsigned CG15 : 2; //!< [31:30] Reserved
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

/* --- Register HW_CCM_CCGR6, field CG0[1:0] (RW)
 *
 * usboh3 clock (usboh3_clk_enable)
 */

#define BP_CCM_CCGR6_CG0      (0)      //!< Bit position for CCM_CCGR6_CG0.
#define BM_CCM_CCGR6_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR6_CG0.

//! @brief Get value of CCM_CCGR6_CG0 from a register value.
#define BG_CCM_CCGR6_CG0(r)   (((r) & BM_CCM_CCGR6_CG0) >> BP_CCM_CCGR6_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG0.
#define BF_CCM_CCGR6_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG0) & BM_CCM_CCGR6_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG0.
#define BF_CCM_CCGR6_CG0(v)   (((v) << BP_CCM_CCGR6_CG0) & BM_CCM_CCGR6_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR6_CG0(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG0) | BF_CCM_CCGR6_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG1[3:2] (RW)
 *
 * usdhc1 clocks (usdhc1_clk_enable)
 */

#define BP_CCM_CCGR6_CG1      (2)      //!< Bit position for CCM_CCGR6_CG1.
#define BM_CCM_CCGR6_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR6_CG1.

//! @brief Get value of CCM_CCGR6_CG1 from a register value.
#define BG_CCM_CCGR6_CG1(r)   (((r) & BM_CCM_CCGR6_CG1) >> BP_CCM_CCGR6_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG1.
#define BF_CCM_CCGR6_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG1) & BM_CCM_CCGR6_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG1.
#define BF_CCM_CCGR6_CG1(v)   (((v) << BP_CCM_CCGR6_CG1) & BM_CCM_CCGR6_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR6_CG1(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG1) | BF_CCM_CCGR6_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG2[5:4] (RW)
 *
 * usdhc2 clocks (usdhc2_clk_enable)
 */

#define BP_CCM_CCGR6_CG2      (4)      //!< Bit position for CCM_CCGR6_CG2.
#define BM_CCM_CCGR6_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR6_CG2.

//! @brief Get value of CCM_CCGR6_CG2 from a register value.
#define BG_CCM_CCGR6_CG2(r)   (((r) & BM_CCM_CCGR6_CG2) >> BP_CCM_CCGR6_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG2.
#define BF_CCM_CCGR6_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG2) & BM_CCM_CCGR6_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG2.
#define BF_CCM_CCGR6_CG2(v)   (((v) << BP_CCM_CCGR6_CG2) & BM_CCM_CCGR6_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR6_CG2(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG2) | BF_CCM_CCGR6_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG3[7:6] (RW)
 *
 * usdhc3 clocks (usdhc3_clk_enable)
 */

#define BP_CCM_CCGR6_CG3      (6)      //!< Bit position for CCM_CCGR6_CG3.
#define BM_CCM_CCGR6_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR6_CG3.

//! @brief Get value of CCM_CCGR6_CG3 from a register value.
#define BG_CCM_CCGR6_CG3(r)   (((r) & BM_CCM_CCGR6_CG3) >> BP_CCM_CCGR6_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG3.
#define BF_CCM_CCGR6_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG3) & BM_CCM_CCGR6_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG3.
#define BF_CCM_CCGR6_CG3(v)   (((v) << BP_CCM_CCGR6_CG3) & BM_CCM_CCGR6_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR6_CG3(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG3) | BF_CCM_CCGR6_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG4[9:8] (RW)
 *
 * usdhc4 clocks (usdhc4_clk_enable)
 */

#define BP_CCM_CCGR6_CG4      (8)      //!< Bit position for CCM_CCGR6_CG4.
#define BM_CCM_CCGR6_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR6_CG4.

//! @brief Get value of CCM_CCGR6_CG4 from a register value.
#define BG_CCM_CCGR6_CG4(r)   (((r) & BM_CCM_CCGR6_CG4) >> BP_CCM_CCGR6_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG4.
#define BF_CCM_CCGR6_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG4) & BM_CCM_CCGR6_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG4.
#define BF_CCM_CCGR6_CG4(v)   (((v) << BP_CCM_CCGR6_CG4) & BM_CCM_CCGR6_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR6_CG4(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG4) | BF_CCM_CCGR6_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG5[11:10] (RW)
 *
 * emi_slow clocks (emi_slow_clk_enable)
 */

#define BP_CCM_CCGR6_CG5      (10)      //!< Bit position for CCM_CCGR6_CG5.
#define BM_CCM_CCGR6_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR6_CG5.

//! @brief Get value of CCM_CCGR6_CG5 from a register value.
#define BG_CCM_CCGR6_CG5(r)   (((r) & BM_CCM_CCGR6_CG5) >> BP_CCM_CCGR6_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG5.
#define BF_CCM_CCGR6_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG5) & BM_CCM_CCGR6_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG5.
#define BF_CCM_CCGR6_CG5(v)   (((v) << BP_CCM_CCGR6_CG5) & BM_CCM_CCGR6_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR6_CG5(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG5) | BF_CCM_CCGR6_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG6[13:12] (RW)
 *
 * vdoaxiclk root clock (vdoaxiclk_clk_enable)
 */

#define BP_CCM_CCGR6_CG6      (12)      //!< Bit position for CCM_CCGR6_CG6.
#define BM_CCM_CCGR6_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR6_CG6.

//! @brief Get value of CCM_CCGR6_CG6 from a register value.
#define BG_CCM_CCGR6_CG6(r)   (((r) & BM_CCM_CCGR6_CG6) >> BP_CCM_CCGR6_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG6.
#define BF_CCM_CCGR6_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG6) & BM_CCM_CCGR6_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG6.
#define BF_CCM_CCGR6_CG6(v)   (((v) << BP_CCM_CCGR6_CG6) & BM_CCM_CCGR6_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR6_CG6(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG6) | BF_CCM_CCGR6_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG7[15:14] (RW)
 *
 * vpu clocks (vpu_clk_enable)
 */

#define BP_CCM_CCGR6_CG7      (14)      //!< Bit position for CCM_CCGR6_CG7.
#define BM_CCM_CCGR6_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR6_CG7.

//! @brief Get value of CCM_CCGR6_CG7 from a register value.
#define BG_CCM_CCGR6_CG7(r)   (((r) & BM_CCM_CCGR6_CG7) >> BP_CCM_CCGR6_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG7.
#define BF_CCM_CCGR6_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG7) & BM_CCM_CCGR6_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG7.
#define BF_CCM_CCGR6_CG7(v)   (((v) << BP_CCM_CCGR6_CG7) & BM_CCM_CCGR6_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR6_CG7(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG7) | BF_CCM_CCGR6_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG8[17:16] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG8      (16)      //!< Bit position for CCM_CCGR6_CG8.
#define BM_CCM_CCGR6_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR6_CG8.

//! @brief Get value of CCM_CCGR6_CG8 from a register value.
#define BG_CCM_CCGR6_CG8(r)   (((r) & BM_CCM_CCGR6_CG8) >> BP_CCM_CCGR6_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG8.
#define BF_CCM_CCGR6_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG8) & BM_CCM_CCGR6_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG8.
#define BF_CCM_CCGR6_CG8(v)   (((v) << BP_CCM_CCGR6_CG8) & BM_CCM_CCGR6_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR6_CG8(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG8) | BF_CCM_CCGR6_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG9[19:18] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG9      (18)      //!< Bit position for CCM_CCGR6_CG9.
#define BM_CCM_CCGR6_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR6_CG9.

//! @brief Get value of CCM_CCGR6_CG9 from a register value.
#define BG_CCM_CCGR6_CG9(r)   (((r) & BM_CCM_CCGR6_CG9) >> BP_CCM_CCGR6_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG9.
#define BF_CCM_CCGR6_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG9) & BM_CCM_CCGR6_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG9.
#define BF_CCM_CCGR6_CG9(v)   (((v) << BP_CCM_CCGR6_CG9) & BM_CCM_CCGR6_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR6_CG9(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG9) | BF_CCM_CCGR6_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG10[21:20] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG10      (20)      //!< Bit position for CCM_CCGR6_CG10.
#define BM_CCM_CCGR6_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR6_CG10.

//! @brief Get value of CCM_CCGR6_CG10 from a register value.
#define BG_CCM_CCGR6_CG10(r)   (((r) & BM_CCM_CCGR6_CG10) >> BP_CCM_CCGR6_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG10.
#define BF_CCM_CCGR6_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG10) & BM_CCM_CCGR6_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG10.
#define BF_CCM_CCGR6_CG10(v)   (((v) << BP_CCM_CCGR6_CG10) & BM_CCM_CCGR6_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR6_CG10(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG10) | BF_CCM_CCGR6_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG11[23:22] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG11      (22)      //!< Bit position for CCM_CCGR6_CG11.
#define BM_CCM_CCGR6_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR6_CG11.

//! @brief Get value of CCM_CCGR6_CG11 from a register value.
#define BG_CCM_CCGR6_CG11(r)   (((r) & BM_CCM_CCGR6_CG11) >> BP_CCM_CCGR6_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG11.
#define BF_CCM_CCGR6_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG11) & BM_CCM_CCGR6_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG11.
#define BF_CCM_CCGR6_CG11(v)   (((v) << BP_CCM_CCGR6_CG11) & BM_CCM_CCGR6_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR6_CG11(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG11) | BF_CCM_CCGR6_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG12[25:24] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG12      (24)      //!< Bit position for CCM_CCGR6_CG12.
#define BM_CCM_CCGR6_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR6_CG12.

//! @brief Get value of CCM_CCGR6_CG12 from a register value.
#define BG_CCM_CCGR6_CG12(r)   (((r) & BM_CCM_CCGR6_CG12) >> BP_CCM_CCGR6_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG12.
#define BF_CCM_CCGR6_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG12) & BM_CCM_CCGR6_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG12.
#define BF_CCM_CCGR6_CG12(v)   (((v) << BP_CCM_CCGR6_CG12) & BM_CCM_CCGR6_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR6_CG12(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG12) | BF_CCM_CCGR6_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG13[27:26] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG13      (26)      //!< Bit position for CCM_CCGR6_CG13.
#define BM_CCM_CCGR6_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR6_CG13.

//! @brief Get value of CCM_CCGR6_CG13 from a register value.
#define BG_CCM_CCGR6_CG13(r)   (((r) & BM_CCM_CCGR6_CG13) >> BP_CCM_CCGR6_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG13.
#define BF_CCM_CCGR6_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG13) & BM_CCM_CCGR6_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG13.
#define BF_CCM_CCGR6_CG13(v)   (((v) << BP_CCM_CCGR6_CG13) & BM_CCM_CCGR6_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR6_CG13(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG13) | BF_CCM_CCGR6_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG14[29:28] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG14      (28)      //!< Bit position for CCM_CCGR6_CG14.
#define BM_CCM_CCGR6_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR6_CG14.

//! @brief Get value of CCM_CCGR6_CG14 from a register value.
#define BG_CCM_CCGR6_CG14(r)   (((r) & BM_CCM_CCGR6_CG14) >> BP_CCM_CCGR6_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG14.
#define BF_CCM_CCGR6_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG14) & BM_CCM_CCGR6_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG14.
#define BF_CCM_CCGR6_CG14(v)   (((v) << BP_CCM_CCGR6_CG14) & BM_CCM_CCGR6_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR6_CG14(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG14) | BF_CCM_CCGR6_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR6, field CG15[31:30] (RW)
 *
 * Reserved
 */

#define BP_CCM_CCGR6_CG15      (30)      //!< Bit position for CCM_CCGR6_CG15.
#define BM_CCM_CCGR6_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR6_CG15.

//! @brief Get value of CCM_CCGR6_CG15 from a register value.
#define BG_CCM_CCGR6_CG15(r)   (((r) & BM_CCM_CCGR6_CG15) >> BP_CCM_CCGR6_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR6_CG15.
#define BF_CCM_CCGR6_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR6_CG15) & BM_CCM_CCGR6_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR6_CG15.
#define BF_CCM_CCGR6_CG15(v)   (((v) << BP_CCM_CCGR6_CG15) & BM_CCM_CCGR6_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR6_CG15(v)   (HW_CCM_CCGR6_WR((HW_CCM_CCGR6_RD() & ~BM_CCM_CCGR6_CG15) | BF_CCM_CCGR6_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CCGR7 - CCM Clock Gating Register 7 (RW)
 *
 * Reset value: 0xffffffff
 *
 * The figure below represents the CCM Clock Gating Register 7 (CCM_CCGR7). The clock gating
 * Registers define the clock gating for power reduction of each clock (CG(i) bits). There are 8 CGR
 * registers. The number of registers required is according to the number of peripherals in the
 * system.  CG(i) bits CCGR 0-7  This bits are used to turn on/off the clock to each module
 * independently.The following table details the possible clock activity conditions for each module
 * CGR value    Clock Activity Description        00    clock is off during all modes. stop enter
 * hardware handshake is disabled.      01    clock is on in run mode, but off in wait and stop
 * modes      10    Not applicable (Reserved).      11    clock is on during all modes, except stop
 * mode.       : Module should be stopped, before set it's bits to "0", since clocks to the module
 * will be stopped immediately.  The tables above show the register mapings for the different CGR's.
 * The clock connectivity table should be used to match the "CCM output affected" to the actual
 * clocks going into the modules.
 */
typedef union _hw_ccm_ccgr7
{
    reg32_t U;
    struct _hw_ccm_ccgr7_bitfields
    {
        unsigned CG0 : 2; //!< [1:0] CG0
        unsigned CG1 : 2; //!< [3:2] CG1
        unsigned CG2 : 2; //!< [5:4] CG2
        unsigned CG3 : 2; //!< [7:6] CG3
        unsigned CG4 : 2; //!< [9:8] CG4
        unsigned CG5 : 2; //!< [11:10] CG5
        unsigned CG6 : 2; //!< [13:12] CG6
        unsigned CG7 : 2; //!< [15:14] CG7
        unsigned CG8 : 2; //!< [17:16] CG8
        unsigned CG9 : 2; //!< [19:18] CG9
        unsigned CG10 : 2; //!< [21:20] CG10
        unsigned CG11 : 2; //!< [23:22] CG11
        unsigned CG12 : 2; //!< [25:24] CG12
        unsigned CG13 : 2; //!< [27:26] CG13
        unsigned CG14 : 2; //!< [29:28] CG14
        unsigned CG15 : 2; //!< [31:30] CG15
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

/* --- Register HW_CCM_CCGR7, field CG0[1:0] (RW)
 *
 * CG0
 */

#define BP_CCM_CCGR7_CG0      (0)      //!< Bit position for CCM_CCGR7_CG0.
#define BM_CCM_CCGR7_CG0      (0x00000003)  //!< Bit mask for CCM_CCGR7_CG0.

//! @brief Get value of CCM_CCGR7_CG0 from a register value.
#define BG_CCM_CCGR7_CG0(r)   (((r) & BM_CCM_CCGR7_CG0) >> BP_CCM_CCGR7_CG0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG0.
#define BF_CCM_CCGR7_CG0(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG0) & BM_CCM_CCGR7_CG0)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG0.
#define BF_CCM_CCGR7_CG0(v)   (((v) << BP_CCM_CCGR7_CG0) & BM_CCM_CCGR7_CG0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG0 field to a new value.
#define BW_CCM_CCGR7_CG0(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG0) | BF_CCM_CCGR7_CG0(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG1[3:2] (RW)
 *
 * CG1
 */

#define BP_CCM_CCGR7_CG1      (2)      //!< Bit position for CCM_CCGR7_CG1.
#define BM_CCM_CCGR7_CG1      (0x0000000c)  //!< Bit mask for CCM_CCGR7_CG1.

//! @brief Get value of CCM_CCGR7_CG1 from a register value.
#define BG_CCM_CCGR7_CG1(r)   (((r) & BM_CCM_CCGR7_CG1) >> BP_CCM_CCGR7_CG1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG1.
#define BF_CCM_CCGR7_CG1(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG1) & BM_CCM_CCGR7_CG1)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG1.
#define BF_CCM_CCGR7_CG1(v)   (((v) << BP_CCM_CCGR7_CG1) & BM_CCM_CCGR7_CG1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG1 field to a new value.
#define BW_CCM_CCGR7_CG1(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG1) | BF_CCM_CCGR7_CG1(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG2[5:4] (RW)
 *
 * CG2
 */

#define BP_CCM_CCGR7_CG2      (4)      //!< Bit position for CCM_CCGR7_CG2.
#define BM_CCM_CCGR7_CG2      (0x00000030)  //!< Bit mask for CCM_CCGR7_CG2.

//! @brief Get value of CCM_CCGR7_CG2 from a register value.
#define BG_CCM_CCGR7_CG2(r)   (((r) & BM_CCM_CCGR7_CG2) >> BP_CCM_CCGR7_CG2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG2.
#define BF_CCM_CCGR7_CG2(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG2) & BM_CCM_CCGR7_CG2)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG2.
#define BF_CCM_CCGR7_CG2(v)   (((v) << BP_CCM_CCGR7_CG2) & BM_CCM_CCGR7_CG2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG2 field to a new value.
#define BW_CCM_CCGR7_CG2(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG2) | BF_CCM_CCGR7_CG2(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG3[7:6] (RW)
 *
 * CG3
 */

#define BP_CCM_CCGR7_CG3      (6)      //!< Bit position for CCM_CCGR7_CG3.
#define BM_CCM_CCGR7_CG3      (0x000000c0)  //!< Bit mask for CCM_CCGR7_CG3.

//! @brief Get value of CCM_CCGR7_CG3 from a register value.
#define BG_CCM_CCGR7_CG3(r)   (((r) & BM_CCM_CCGR7_CG3) >> BP_CCM_CCGR7_CG3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG3.
#define BF_CCM_CCGR7_CG3(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG3) & BM_CCM_CCGR7_CG3)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG3.
#define BF_CCM_CCGR7_CG3(v)   (((v) << BP_CCM_CCGR7_CG3) & BM_CCM_CCGR7_CG3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG3 field to a new value.
#define BW_CCM_CCGR7_CG3(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG3) | BF_CCM_CCGR7_CG3(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG4[9:8] (RW)
 *
 * CG4
 */

#define BP_CCM_CCGR7_CG4      (8)      //!< Bit position for CCM_CCGR7_CG4.
#define BM_CCM_CCGR7_CG4      (0x00000300)  //!< Bit mask for CCM_CCGR7_CG4.

//! @brief Get value of CCM_CCGR7_CG4 from a register value.
#define BG_CCM_CCGR7_CG4(r)   (((r) & BM_CCM_CCGR7_CG4) >> BP_CCM_CCGR7_CG4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG4.
#define BF_CCM_CCGR7_CG4(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG4) & BM_CCM_CCGR7_CG4)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG4.
#define BF_CCM_CCGR7_CG4(v)   (((v) << BP_CCM_CCGR7_CG4) & BM_CCM_CCGR7_CG4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG4 field to a new value.
#define BW_CCM_CCGR7_CG4(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG4) | BF_CCM_CCGR7_CG4(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG5[11:10] (RW)
 *
 * CG5
 */

#define BP_CCM_CCGR7_CG5      (10)      //!< Bit position for CCM_CCGR7_CG5.
#define BM_CCM_CCGR7_CG5      (0x00000c00)  //!< Bit mask for CCM_CCGR7_CG5.

//! @brief Get value of CCM_CCGR7_CG5 from a register value.
#define BG_CCM_CCGR7_CG5(r)   (((r) & BM_CCM_CCGR7_CG5) >> BP_CCM_CCGR7_CG5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG5.
#define BF_CCM_CCGR7_CG5(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG5) & BM_CCM_CCGR7_CG5)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG5.
#define BF_CCM_CCGR7_CG5(v)   (((v) << BP_CCM_CCGR7_CG5) & BM_CCM_CCGR7_CG5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG5 field to a new value.
#define BW_CCM_CCGR7_CG5(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG5) | BF_CCM_CCGR7_CG5(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG6[13:12] (RW)
 *
 * CG6
 */

#define BP_CCM_CCGR7_CG6      (12)      //!< Bit position for CCM_CCGR7_CG6.
#define BM_CCM_CCGR7_CG6      (0x00003000)  //!< Bit mask for CCM_CCGR7_CG6.

//! @brief Get value of CCM_CCGR7_CG6 from a register value.
#define BG_CCM_CCGR7_CG6(r)   (((r) & BM_CCM_CCGR7_CG6) >> BP_CCM_CCGR7_CG6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG6.
#define BF_CCM_CCGR7_CG6(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG6) & BM_CCM_CCGR7_CG6)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG6.
#define BF_CCM_CCGR7_CG6(v)   (((v) << BP_CCM_CCGR7_CG6) & BM_CCM_CCGR7_CG6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG6 field to a new value.
#define BW_CCM_CCGR7_CG6(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG6) | BF_CCM_CCGR7_CG6(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG7[15:14] (RW)
 *
 * CG7
 */

#define BP_CCM_CCGR7_CG7      (14)      //!< Bit position for CCM_CCGR7_CG7.
#define BM_CCM_CCGR7_CG7      (0x0000c000)  //!< Bit mask for CCM_CCGR7_CG7.

//! @brief Get value of CCM_CCGR7_CG7 from a register value.
#define BG_CCM_CCGR7_CG7(r)   (((r) & BM_CCM_CCGR7_CG7) >> BP_CCM_CCGR7_CG7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG7.
#define BF_CCM_CCGR7_CG7(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG7) & BM_CCM_CCGR7_CG7)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG7.
#define BF_CCM_CCGR7_CG7(v)   (((v) << BP_CCM_CCGR7_CG7) & BM_CCM_CCGR7_CG7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG7 field to a new value.
#define BW_CCM_CCGR7_CG7(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG7) | BF_CCM_CCGR7_CG7(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG8[17:16] (RW)
 *
 * CG8
 */

#define BP_CCM_CCGR7_CG8      (16)      //!< Bit position for CCM_CCGR7_CG8.
#define BM_CCM_CCGR7_CG8      (0x00030000)  //!< Bit mask for CCM_CCGR7_CG8.

//! @brief Get value of CCM_CCGR7_CG8 from a register value.
#define BG_CCM_CCGR7_CG8(r)   (((r) & BM_CCM_CCGR7_CG8) >> BP_CCM_CCGR7_CG8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG8.
#define BF_CCM_CCGR7_CG8(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG8) & BM_CCM_CCGR7_CG8)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG8.
#define BF_CCM_CCGR7_CG8(v)   (((v) << BP_CCM_CCGR7_CG8) & BM_CCM_CCGR7_CG8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG8 field to a new value.
#define BW_CCM_CCGR7_CG8(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG8) | BF_CCM_CCGR7_CG8(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG9[19:18] (RW)
 *
 * CG9
 */

#define BP_CCM_CCGR7_CG9      (18)      //!< Bit position for CCM_CCGR7_CG9.
#define BM_CCM_CCGR7_CG9      (0x000c0000)  //!< Bit mask for CCM_CCGR7_CG9.

//! @brief Get value of CCM_CCGR7_CG9 from a register value.
#define BG_CCM_CCGR7_CG9(r)   (((r) & BM_CCM_CCGR7_CG9) >> BP_CCM_CCGR7_CG9)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG9.
#define BF_CCM_CCGR7_CG9(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG9) & BM_CCM_CCGR7_CG9)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG9.
#define BF_CCM_CCGR7_CG9(v)   (((v) << BP_CCM_CCGR7_CG9) & BM_CCM_CCGR7_CG9)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG9 field to a new value.
#define BW_CCM_CCGR7_CG9(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG9) | BF_CCM_CCGR7_CG9(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG10[21:20] (RW)
 *
 * CG10
 */

#define BP_CCM_CCGR7_CG10      (20)      //!< Bit position for CCM_CCGR7_CG10.
#define BM_CCM_CCGR7_CG10      (0x00300000)  //!< Bit mask for CCM_CCGR7_CG10.

//! @brief Get value of CCM_CCGR7_CG10 from a register value.
#define BG_CCM_CCGR7_CG10(r)   (((r) & BM_CCM_CCGR7_CG10) >> BP_CCM_CCGR7_CG10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG10.
#define BF_CCM_CCGR7_CG10(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG10) & BM_CCM_CCGR7_CG10)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG10.
#define BF_CCM_CCGR7_CG10(v)   (((v) << BP_CCM_CCGR7_CG10) & BM_CCM_CCGR7_CG10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG10 field to a new value.
#define BW_CCM_CCGR7_CG10(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG10) | BF_CCM_CCGR7_CG10(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG11[23:22] (RW)
 *
 * CG11
 */

#define BP_CCM_CCGR7_CG11      (22)      //!< Bit position for CCM_CCGR7_CG11.
#define BM_CCM_CCGR7_CG11      (0x00c00000)  //!< Bit mask for CCM_CCGR7_CG11.

//! @brief Get value of CCM_CCGR7_CG11 from a register value.
#define BG_CCM_CCGR7_CG11(r)   (((r) & BM_CCM_CCGR7_CG11) >> BP_CCM_CCGR7_CG11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG11.
#define BF_CCM_CCGR7_CG11(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG11) & BM_CCM_CCGR7_CG11)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG11.
#define BF_CCM_CCGR7_CG11(v)   (((v) << BP_CCM_CCGR7_CG11) & BM_CCM_CCGR7_CG11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG11 field to a new value.
#define BW_CCM_CCGR7_CG11(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG11) | BF_CCM_CCGR7_CG11(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG12[25:24] (RW)
 *
 * CG12
 */

#define BP_CCM_CCGR7_CG12      (24)      //!< Bit position for CCM_CCGR7_CG12.
#define BM_CCM_CCGR7_CG12      (0x03000000)  //!< Bit mask for CCM_CCGR7_CG12.

//! @brief Get value of CCM_CCGR7_CG12 from a register value.
#define BG_CCM_CCGR7_CG12(r)   (((r) & BM_CCM_CCGR7_CG12) >> BP_CCM_CCGR7_CG12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG12.
#define BF_CCM_CCGR7_CG12(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG12) & BM_CCM_CCGR7_CG12)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG12.
#define BF_CCM_CCGR7_CG12(v)   (((v) << BP_CCM_CCGR7_CG12) & BM_CCM_CCGR7_CG12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG12 field to a new value.
#define BW_CCM_CCGR7_CG12(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG12) | BF_CCM_CCGR7_CG12(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG13[27:26] (RW)
 *
 * CG13
 */

#define BP_CCM_CCGR7_CG13      (26)      //!< Bit position for CCM_CCGR7_CG13.
#define BM_CCM_CCGR7_CG13      (0x0c000000)  //!< Bit mask for CCM_CCGR7_CG13.

//! @brief Get value of CCM_CCGR7_CG13 from a register value.
#define BG_CCM_CCGR7_CG13(r)   (((r) & BM_CCM_CCGR7_CG13) >> BP_CCM_CCGR7_CG13)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG13.
#define BF_CCM_CCGR7_CG13(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG13) & BM_CCM_CCGR7_CG13)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG13.
#define BF_CCM_CCGR7_CG13(v)   (((v) << BP_CCM_CCGR7_CG13) & BM_CCM_CCGR7_CG13)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG13 field to a new value.
#define BW_CCM_CCGR7_CG13(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG13) | BF_CCM_CCGR7_CG13(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG14[29:28] (RW)
 *
 * CG14
 */

#define BP_CCM_CCGR7_CG14      (28)      //!< Bit position for CCM_CCGR7_CG14.
#define BM_CCM_CCGR7_CG14      (0x30000000)  //!< Bit mask for CCM_CCGR7_CG14.

//! @brief Get value of CCM_CCGR7_CG14 from a register value.
#define BG_CCM_CCGR7_CG14(r)   (((r) & BM_CCM_CCGR7_CG14) >> BP_CCM_CCGR7_CG14)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG14.
#define BF_CCM_CCGR7_CG14(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG14) & BM_CCM_CCGR7_CG14)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG14.
#define BF_CCM_CCGR7_CG14(v)   (((v) << BP_CCM_CCGR7_CG14) & BM_CCM_CCGR7_CG14)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG14 field to a new value.
#define BW_CCM_CCGR7_CG14(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG14) | BF_CCM_CCGR7_CG14(v)))
#endif

/* --- Register HW_CCM_CCGR7, field CG15[31:30] (RW)
 *
 * CG15
 */

#define BP_CCM_CCGR7_CG15      (30)      //!< Bit position for CCM_CCGR7_CG15.
#define BM_CCM_CCGR7_CG15      (0xc0000000)  //!< Bit mask for CCM_CCGR7_CG15.

//! @brief Get value of CCM_CCGR7_CG15 from a register value.
#define BG_CCM_CCGR7_CG15(r)   (((r) & BM_CCM_CCGR7_CG15) >> BP_CCM_CCGR7_CG15)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CCGR7_CG15.
#define BF_CCM_CCGR7_CG15(v)   ((((reg32_t) v) << BP_CCM_CCGR7_CG15) & BM_CCM_CCGR7_CG15)
#else
//! @brief Format value for bitfield CCM_CCGR7_CG15.
#define BF_CCM_CCGR7_CG15(v)   (((v) << BP_CCM_CCGR7_CG15) & BM_CCM_CCGR7_CG15)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CG15 field to a new value.
#define BW_CCM_CCGR7_CG15(v)   (HW_CCM_CCGR7_WR((HW_CCM_CCGR7_RD() & ~BM_CCM_CCGR7_CG15) | BF_CCM_CCGR7_CG15(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_CMEOR - CCM Module Enable Overide Register (RW)
 *
 * Reset value: 0xffffffff
 *
 * The follow figure represents the CCM Module Enable Override Register (CMEOR). The CMEOR register
 * contains bits to override the clock enable signal from the module. This should be used in case
 * that it is decided to bypass the clock enable signals from the modules. This bit will be
 * applicable only for module that their clock enable signal is used. The following table provides
 * its field descriptions.
 */
typedef union _hw_ccm_cmeor
{
    reg32_t U;
    struct _hw_ccm_cmeor_bitfields
    {
        unsigned RESERVED0 : 4; //!< [3:0] Reserved
        unsigned MOD_EN_OV_VDOA : 1; //!< [4] overide clock enable signal from vdoa - clock will not be gated based on vdoa signal.
        unsigned MOD_EN_OV_GPT : 1; //!< [5] overide clock enable signal from gpt - clock will not be gated based on gpt's signal 'ipg_enable_clk' .
        unsigned MOD_EN_OV_EPIT : 1; //!< [6] overide clock enable signal from epit - clock will not be gated based on epit's signal 'ipg_enable_clk' .
        unsigned MOD_EN_USDHC : 1; //!< [7] overide clock enable signal from usdhc.
        unsigned MOD_EN_OV_DAP : 1; //!< [8] overide clock enable signal from dap- clock will not be gated based on dap's signal 'dap_dbgen' .
        unsigned MOD_EN_OV_VPU : 1; //!< [9] overide clock enable signal from vpu- clock will not be gated based on vpu's signal 'vpu_idle' .
        unsigned MOD_EN_OV_GPU2D : 1; //!< [10] overide clock enable signal from gpu2d - clock will not be gated based on gpu2d's signal 'gpu2d_busy' .
        unsigned MOD_EN_OV_GPU3D : 1; //!< [11] overide clock enable signal from gpu3d - clock will not be gated based on gpu3d's signal.
        unsigned RESERVED1 : 16; //!< [27:12] Reserved
        unsigned MOD_EN_OV_CAN2_CPI : 1; //!< [28] overide clock enable signal from can2 - clock will not be gated based on can's signal 'enable_clk_cpi'.
        unsigned RESERVED2 : 1; //!< [29] Reserved
        unsigned MOD_EN_OV_CAN1_CPI : 1; //!< [30] overide clock enable signal from can1 - clock will not be gated based on can's signal 'enable_clk_cpi'.
        unsigned RESERVED3 : 1; //!< [31] Reserved
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

/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VDOA[4] (RW)
 *
 * overide clock enable signal from vdoa - clock will not be gated based on vdoa signal.
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_VDOA      (4)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_VDOA.
#define BM_CCM_CMEOR_MOD_EN_OV_VDOA      (0x00000010)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_VDOA.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_VDOA from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_VDOA(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_VDOA) >> BP_CCM_CMEOR_MOD_EN_OV_VDOA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_VDOA.
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_VDOA) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_VDOA.
#define BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_VDOA) & BM_CCM_CMEOR_MOD_EN_OV_VDOA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_VDOA field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_VDOA(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_VDOA) | BF_CCM_CMEOR_MOD_EN_OV_VDOA(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPT[5] (RW)
 *
 * overide clock enable signal from gpt - clock will not be gated based on gpt's signal
 * 'ipg_enable_clk' .
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPT      (5)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_GPT.
#define BM_CCM_CMEOR_MOD_EN_OV_GPT      (0x00000020)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_GPT.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_GPT from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_GPT(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_GPT) >> BP_CCM_CMEOR_MOD_EN_OV_GPT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPT.
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_GPT) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPT.
#define BF_CCM_CMEOR_MOD_EN_OV_GPT(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_GPT) & BM_CCM_CMEOR_MOD_EN_OV_GPT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_GPT field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_GPT(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_GPT) | BF_CCM_CMEOR_MOD_EN_OV_GPT(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_EPIT[6] (RW)
 *
 * overide clock enable signal from epit - clock will not be gated based on epit's signal
 * 'ipg_enable_clk' .
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_EPIT      (6)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_EPIT.
#define BM_CCM_CMEOR_MOD_EN_OV_EPIT      (0x00000040)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_EPIT.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_EPIT from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_EPIT(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_EPIT) >> BP_CCM_CMEOR_MOD_EN_OV_EPIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_EPIT.
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_EPIT) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_EPIT.
#define BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_EPIT) & BM_CCM_CMEOR_MOD_EN_OV_EPIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_EPIT field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_EPIT(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_EPIT) | BF_CCM_CMEOR_MOD_EN_OV_EPIT(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_USDHC[7] (RW)
 *
 * overide clock enable signal from usdhc.
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_USDHC      (7)      //!< Bit position for CCM_CMEOR_MOD_EN_USDHC.
#define BM_CCM_CMEOR_MOD_EN_USDHC      (0x00000080)  //!< Bit mask for CCM_CMEOR_MOD_EN_USDHC.

//! @brief Get value of CCM_CMEOR_MOD_EN_USDHC from a register value.
#define BG_CCM_CMEOR_MOD_EN_USDHC(r)   (((r) & BM_CCM_CMEOR_MOD_EN_USDHC) >> BP_CCM_CMEOR_MOD_EN_USDHC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_USDHC.
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_USDHC) & BM_CCM_CMEOR_MOD_EN_USDHC)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_USDHC.
#define BF_CCM_CMEOR_MOD_EN_USDHC(v)   (((v) << BP_CCM_CMEOR_MOD_EN_USDHC) & BM_CCM_CMEOR_MOD_EN_USDHC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_USDHC field to a new value.
#define BW_CCM_CMEOR_MOD_EN_USDHC(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_USDHC) | BF_CCM_CMEOR_MOD_EN_USDHC(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_DAP[8] (RW)
 *
 * overide clock enable signal from dap- clock will not be gated based on dap's signal 'dap_dbgen' .
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_DAP      (8)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_DAP.
#define BM_CCM_CMEOR_MOD_EN_OV_DAP      (0x00000100)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_DAP.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_DAP from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_DAP(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_DAP) >> BP_CCM_CMEOR_MOD_EN_OV_DAP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_DAP.
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_DAP) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_DAP.
#define BF_CCM_CMEOR_MOD_EN_OV_DAP(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_DAP) & BM_CCM_CMEOR_MOD_EN_OV_DAP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_DAP field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_DAP(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_DAP) | BF_CCM_CMEOR_MOD_EN_OV_DAP(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_VPU[9] (RW)
 *
 * overide clock enable signal from vpu- clock will not be gated based on vpu's signal 'vpu_idle' .
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_VPU      (9)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_VPU.
#define BM_CCM_CMEOR_MOD_EN_OV_VPU      (0x00000200)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_VPU.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_VPU from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_VPU(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_VPU) >> BP_CCM_CMEOR_MOD_EN_OV_VPU)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_VPU.
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_VPU) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_VPU.
#define BF_CCM_CMEOR_MOD_EN_OV_VPU(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_VPU) & BM_CCM_CMEOR_MOD_EN_OV_VPU)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_VPU field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_VPU(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_VPU) | BF_CCM_CMEOR_MOD_EN_OV_VPU(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU2D[10] (RW)
 *
 * overide clock enable signal from gpu2d - clock will not be gated based on gpu2d's signal
 * 'gpu2d_busy' .
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU2D      (10)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_GPU2D.
#define BM_CCM_CMEOR_MOD_EN_OV_GPU2D      (0x00000400)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_GPU2D.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_GPU2D from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_GPU2D(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D) >> BP_CCM_CMEOR_MOD_EN_OV_GPU2D)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPU2D.
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_GPU2D) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPU2D.
#define BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_GPU2D) & BM_CCM_CMEOR_MOD_EN_OV_GPU2D)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_GPU2D field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_GPU2D(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_GPU2D) | BF_CCM_CMEOR_MOD_EN_OV_GPU2D(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_GPU3D[11] (RW)
 *
 * overide clock enable signal from gpu3d - clock will not be gated based on gpu3d's signal.
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_GPU3D      (11)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_GPU3D.
#define BM_CCM_CMEOR_MOD_EN_OV_GPU3D      (0x00000800)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_GPU3D.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_GPU3D from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_GPU3D(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D) >> BP_CCM_CMEOR_MOD_EN_OV_GPU3D)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPU3D.
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_GPU3D) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_GPU3D.
#define BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_GPU3D) & BM_CCM_CMEOR_MOD_EN_OV_GPU3D)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_GPU3D field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_GPU3D(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_GPU3D) | BF_CCM_CMEOR_MOD_EN_OV_GPU3D(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN2_CPI[28] (RW)
 *
 * overide clock enable signal from can2 - clock will not be gated based on can's signal
 * 'enable_clk_cpi'.
 *
 * Values:
 * 0 - dont override module enable signal
 * 1 - override module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      (28)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_CAN2_CPI.
#define BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI      (0x10000000)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_CAN2_CPI.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_CAN2_CPI from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI) >> BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_CAN2_CPI.
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_CAN2_CPI.
#define BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_CAN2_CPI) & BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_CAN2_CPI field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_CAN2_CPI) | BF_CCM_CMEOR_MOD_EN_OV_CAN2_CPI(v)))
#endif


/* --- Register HW_CCM_CMEOR, field MOD_EN_OV_CAN1_CPI[30] (RW)
 *
 * overide clock enable signal from can1 - clock will not be gated based on can's signal
 * 'enable_clk_cpi'.
 *
 * Values:
 * 0 - dont overide module enable signal
 * 1 - overide module enable signal
 */

#define BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      (30)      //!< Bit position for CCM_CMEOR_MOD_EN_OV_CAN1_CPI.
#define BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI      (0x40000000)  //!< Bit mask for CCM_CMEOR_MOD_EN_OV_CAN1_CPI.

//! @brief Get value of CCM_CMEOR_MOD_EN_OV_CAN1_CPI from a register value.
#define BG_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(r)   (((r) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI) >> BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_CAN1_CPI.
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   ((((reg32_t) v) << BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#else
//! @brief Format value for bitfield CCM_CMEOR_MOD_EN_OV_CAN1_CPI.
#define BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   (((v) << BP_CCM_CMEOR_MOD_EN_OV_CAN1_CPI) & BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD_EN_OV_CAN1_CPI field to a new value.
#define BW_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)   (HW_CCM_CMEOR_WR((HW_CCM_CMEOR_RD() & ~BM_CCM_CMEOR_MOD_EN_OV_CAN1_CPI) | BF_CCM_CMEOR_MOD_EN_OV_CAN1_CPI(v)))
#endif



/*!
 * @brief All CCM module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ccm
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
} hw_ccm_t;
#pragma pack()

//! @brief Macro to access all CCM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM(0)</code>.
#define HW_CCM     (*(volatile hw_ccm_t *) REGS_CCM_BASE)

#endif


#endif // __HW_CCM_REGISTERS_H__
