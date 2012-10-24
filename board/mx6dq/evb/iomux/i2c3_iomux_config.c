/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
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

// File: i2c3_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.1
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for i2c3 module.
void i2c3_iomux_config(void)
{
    // Config i2c3.SCL to pad GPIO_5(R4)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_5_WR(0x00000016);
    // HW_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_5(0x020E023C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_5.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_5.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX2_RX3 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO2_SDI3_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: OBSRV_INT_OUT4 of instance: observe_mux.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CLKO of instance: ccm.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSU_ALARM_AUT[2] of instance: csu.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[5] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SCL of instance: i2c3.
    //                NOTE: - Config Register IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: EVENTI of instance: cheetah.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_5_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_5_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_5_MUX_MODE(ALT6));
    // Pad GPIO_5 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT(0x020E08A8)
    //   DAISY [1:0] Reset: SEL_EIM_D17_ALT6
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c3, In Pin: ipp_scl_in
    //     SEL_EIM_D17_ALT6 (0) - Selecting Pad: EIM_D17 for Mode: ALT6.
    //     SEL_GPIO_3_ALT2 (1) - Selecting Pad: GPIO_3 for Mode: ALT2.
    //     SEL_GPIO_5_ALT6 (2) - Selecting Pad: GPIO_5 for Mode: ALT6.
    HW_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_DAISY(SEL_GPIO_5_ALT6));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_5(0x020E060C)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_5.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_5.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_5.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_5.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_5.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_5.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_5.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_5.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_5_SRE(SRE_SLOW));

    // Config i2c3.SDA to pad GPIO_16(R2)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_16_WR(0x00000016);
    // HW_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_16(0x020E0248)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_16.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_16.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX3_RX2 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO3_SDI2_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: 1588_EVENT2_IN of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ANATOP_ETHERNET_REF_OUT of instance: enet.
    //                NOTE: - Config Register IOMUXC_ENET_IPG_CLK_RMII_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: LCTL of instance: usdhc1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: IN1 of instance: spdif.
    //                NOTE: - Config Register IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[11] of instance: gpio7.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SDA of instance: i2c3.
    //                NOTE: - Config Register IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DE_B of instance: sjc.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_16_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_16_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_16_MUX_MODE(ALT6));
    // Pad GPIO_16 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT(0x020E08AC)
    //   DAISY [1:0] Reset: SEL_EIM_D18_ALT6
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c3, In Pin: ipp_sda_in
    //     SEL_EIM_D18_ALT6 (0) - Selecting Pad: EIM_D18 for Mode: ALT6.
    //     SEL_GPIO_6_ALT2 (1) - Selecting Pad: GPIO_6 for Mode: ALT2.
    //     SEL_GPIO_16_ALT6 (2) - Selecting Pad: GPIO_16 for Mode: ALT6.
    HW_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_DAISY(SEL_GPIO_16_ALT6));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_16(0x020E0618)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_16.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_16.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_16.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_16.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_16.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_16.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_16.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_16.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_16_SRE(SRE_SLOW));
}
