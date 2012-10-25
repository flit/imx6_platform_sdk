/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

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
    ipu1_iomux_config();
    hdmi_tx_cec_pgm_iomux();
    hdmi_tx_ddc_pgm_iomux();
    hdmi_tx_phydtb_pgm_iomux();
}

/*!
 * HDMI power up
 */
void ext_hdmi_transmitter_power_on(void)
{
    /*3.3V for core, default is on */
    /*5V for IO, default is on */
}

void hdmi_clock_set(int ipu_index, uint32_t pclk)
{
    switch (pclk) {
    case 74250000:
    case 148500000:
        if (ipu_index == 1) {
            //clk output from 540M PFD1 of PLL3 
            HW_CCM_CHSCCDR.B.IPU1_DI0_CLK_SEL = 0;  // derive clock from divided pre-muxed ipu1 di0 clock
            HW_CCM_CHSCCDR.B.IPU1_DI0_PODF = 5; // div by 6
            HW_CCM_CHSCCDR.B.IPU1_DI0_PRE_CLK_SEL = 5;  // derive clock from 540M PFD
        }
#if CHIP_MX6DQ
        else {
            //clk output from 540M PFD1 of PLL3 
            HW_CCM_CSCDR2.B.IPU2_DI0_CLK_SEL = 0;   // derive clock from divided pre-muxed ipu1 di0 clock
            HW_CCM_CSCDR2.B.IPU2_DI0_PODF = 5;  // div by 6
            HW_CCM_CSCDR2.B.IPU2_DI0_PRE_CLK_SEL = 5;   // derive clock from 540M PFD
        }

        //config PFD1 of PLL3 to be 445MHz 
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(0x13);
        break;
#endif // CHIP_MX6DQ

    default:
        printf("the hdmi pixel clock is not supported!\n");
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
