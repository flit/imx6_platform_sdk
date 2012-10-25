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

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! @brief IOMUX configuration for the Android_Buttons
void android_buttons_iomux_config()
{
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
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
