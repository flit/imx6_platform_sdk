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

// File: uart2_iomux_config.c

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

// Function to configure IOMUXC for uart2 module.
void uart2_iomux_config(void)
{
    // Config uart2.RXD_MUX to pad EIM_D27(E25)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D27_WR(0x00000004);
    // HW_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D27(0x020E00C0)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D27.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D27.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[27] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN13 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI0_D[0] of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[13] of instance: ipu2.
    //                NOTE: - Config Register IOMUXC_IPU2_IPP_IND_SENS1_DATA_13_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RXD_MUX of instance: uart2.
    //                NOTE: - Config Register IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[27] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[3] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DISP1_DAT[23] of instance: ipu1.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D27_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D27_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D27_MUX_MODE(ALT4));
    // Pad EIM_D27 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0928)
    //   DAISY [2:0] Reset: SEL_EIM_D26_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2, In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D26_ALT4 (0) - Selecting Pad: EIM_D26 for Mode: ALT4.
    //     SEL_EIM_D27_ALT4 (1) - Selecting Pad: EIM_D27 for Mode: ALT4.
    //     SEL_GPIO_7_ALT4 (2) - Selecting Pad: GPIO_7 for Mode: ALT4.
    //     SEL_GPIO_8_ALT4 (3) - Selecting Pad: GPIO_8 for Mode: ALT4.
    //     SEL_SD3_DAT5_ALT1 (4) - Selecting Pad: SD3_DAT5 for Mode: ALT1.
    //     SEL_SD3_DAT4_ALT1 (5) - Selecting Pad: SD3_DAT4 for Mode: ALT1.
    //     SEL_SD4_DAT4_ALT2 (6) - Selecting Pad: SD4_DAT4 for Mode: ALT2.
    //     SEL_SD4_DAT7_ALT2 (7) - Selecting Pad: SD4_DAT7 for Mode: ALT2.
    HW_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_WR(
            BF_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(SEL_EIM_D27_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D27(0x020E03D4)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D27.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D27.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D27.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D27.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D27.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D27.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D27.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D27.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D27_SRE(SRE_SLOW));

    // Config uart2.TXD_MUX to pad EIM_D26(E24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D26_WR(0x00000004);
    // HW_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D26(0x020E00BC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D26.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D26.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[26] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN11 of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CSI0_D[1] of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[14] of instance: ipu2.
    //                NOTE: - Config Register IOMUXC_IPU2_IPP_IND_SENS1_DATA_14_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart2.
    //                NOTE: - Config Register IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[26] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[2] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DISP1_DAT[22] of instance: ipu1.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D26_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D26_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D26_MUX_MODE(ALT4));
    // Pad EIM_D26 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0928)
    //   DAISY [2:0] Reset: SEL_EIM_D26_ALT4
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart2, In Pin: ipp_uart_rxd_mux
    //     SEL_EIM_D26_ALT4 (0) - Selecting Pad: EIM_D26 for Mode: ALT4.
    //     SEL_EIM_D27_ALT4 (1) - Selecting Pad: EIM_D27 for Mode: ALT4.
    //     SEL_GPIO_7_ALT4 (2) - Selecting Pad: GPIO_7 for Mode: ALT4.
    //     SEL_GPIO_8_ALT4 (3) - Selecting Pad: GPIO_8 for Mode: ALT4.
    //     SEL_SD3_DAT5_ALT1 (4) - Selecting Pad: SD3_DAT5 for Mode: ALT1.
    //     SEL_SD3_DAT4_ALT1 (5) - Selecting Pad: SD3_DAT4 for Mode: ALT1.
    //     SEL_SD4_DAT4_ALT2 (6) - Selecting Pad: SD4_DAT4 for Mode: ALT2.
    //     SEL_SD4_DAT7_ALT2 (7) - Selecting Pad: SD4_DAT7 for Mode: ALT2.
    HW_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_WR(
            BF_IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(SEL_EIM_D27_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D26(0x020E03D0)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D26.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D26.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D26.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D26.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D26.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D26.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D26.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D26.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D26_SRE(SRE_SLOW));
}
