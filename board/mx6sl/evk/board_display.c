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
#include "registers/regsccmanalog.h"
#include "registers/regsccm.h"
#include "registers/regsiomuxc.h"
#include "iomux_define.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Turn on LCDIF power_en pin
 *
 * KEY_ROW5 (pin79) controls WVGA panel DISP pin, which is active high. 
 * 
 */
void lcdif_power_on(void)
{
	/* turn on lcdif power on
	 * (KEY_ROW5) ALT5: GPIO4_3 */
	HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW5.B.MUX_MODE = ALT5;

	gpio_set_direction(GPIO_PORT4, 3, GPIO_GDIR_OUTPUT);

	gpio_set_level(GPIO_PORT4, 3, GPIO_HIGH_LEVEL);
}

/* @brief Turn on lcdif backlight power supply
 *
 * 3V3_LCD_CONTRAST (pin 112) controls LED+ and LED- on imx28lcd board */
void lcdif_backlight_on(void)
{
	HW_IOMUXC_SW_MUX_CTL_PAD_PWM1.B.MUX_MODE = ALT5;
	gpio_set_direction(GPIO_PORT3, 23, GPIO_GDIR_OUTPUT);

	gpio_set_level(GPIO_PORT3, 23, GPIO_HIGH_LEVEL);
}

/*!
 * @brief Configure lcdif pixel clock.
 *
 * lcdif pixel clock is derived from PLL3(480MHz) and set as 33.5MHz
 */
void lcdif_clock_enable(void)
{
	/* select PLL3 (480MHz) as source of lcdif pixel clock */
	HW_CCM_CSCDR2.B.LCDIF_PIX_CLK_SEL = 0x01;

	/* pixel clock is 34MHz*/
	/* set pre divide: 2*/
	HW_CCM_CSCDR2.B.LCDIF_PIX_PRED = 2 - 1;

	/* set post divide: 7
	 * CCM_CSCMR1[22:20], bit 22 and bit 21 are inverted.
	 * 000 --- 110	div by 7
	 * 001 --- 111	div by 8
	 * 010 --- 100	div by 5
	 * etc*/
	HW_CCM_CSCMR1.B.LCDIF_PIX_PODF = (7 - 1) ^ 0x6;

	/* enable pixel clock and axi clock */
	HW_CCM_CCGR3.B.CG4 = 0x3;
	HW_CCM_CCGR3.B.CG3 = 0x3;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
