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

// File: iomux_config.c

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

#include <iomux_config.h>

// Function to configure iomux for i.MX6SDL board EVB rev. A.
void iomux_config(void)
{
    anatop_iomux_config();
    can1_iomux_config();
    can2_iomux_config();
    ccm_iomux_config();
    ecspi1_iomux_config();
    enet_iomux_config();
    esai_iomux_config();
    gpio3_iomux_config();
    gpio4_iomux_config();
    gpio5_iomux_config();
    gpio6_iomux_config();
    hdmi_tx_iomux_config();
    i2c1_iomux_config();
    i2c2_iomux_config();
    i2c3_iomux_config();
    ipu1_iomux_config();
    kpp_iomux_config();
    mlb_iomux_config();
    pwm1_iomux_config();
    rawnand_iomux_config();
    sjc_iomux_config();
    spdif_iomux_config();
    uart2_iomux_config();
    uart4_iomux_config();
    usboh3_iomux_config();
    usdhc1_iomux_config();
    usdhc2_iomux_config();
    usdhc3_iomux_config();
    usdhc4_iomux_config();
}

// Definitions for unused modules.
void asrc_iomux_config()
{
};

void audmux_iomux_config()
{
};

void caam_wrapper_iomux_config()
{
};

void csu_iomux_config()
{
};

void dcic1_iomux_config()
{
};

void dcic2_iomux_config()
{
};

void ecspi2_iomux_config()
{
};

void ecspi3_iomux_config()
{
};

void ecspi4_iomux_config()
{
};

void epdc_iomux_config()
{
};

void epit1_iomux_config()
{
};

void epit2_iomux_config()
{
};

void gpio1_iomux_config()
{
};

void gpio2_iomux_config()
{
};

void gpio7_iomux_config()
{
};

void gpt_iomux_config()
{
};

void i2c4_iomux_config()
{
};

void lcdif_iomux_config()
{
};

void ldb_iomux_config()
{
};

void mipi_core_iomux_config()
{
};

void mipi_hsi_ctrl_iomux_config()
{
};

void mmdc_iomux_config()
{
};

void pcie_ctrl_iomux_config()
{
};

void pwm2_iomux_config()
{
};

void pwm3_iomux_config()
{
};

void pwm4_iomux_config()
{
};

void sdma_iomux_config()
{
};

void simba_iomux_config()
{
};

void snvs_hp_wrapper_iomux_config()
{
};

void snvs_lp_wrapper_iomux_config()
{
};

void src_iomux_config()
{
};

void tcu_iomux_config()
{
};

void uart1_iomux_config()
{
};

void uart3_iomux_config()
{
};

void uart5_iomux_config()
{
};

void wdog1_iomux_config()
{
};

void wdog2_iomux_config()
{
};

void weim_iomux_config()
{
};
