/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
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

#include "obds.h"
#include "io.h"
#include "registers/regsuart.h"

static uint32_t uart_instance = HW_UART2;

#if 0
/*!
 * Initialize debug uart
 *
 * @param   uart        pointer to the uart module structure
 * @param   baud        desired baud rate for ommunicating to external device
 */
void init_gps_uart(struct hw_module *uart, uint32_t baud)
{
    struct mx_uart *puart = (volatile struct mx_uart *)uart->base;

    /* Wait for UART to finish transmitting */
    while (!(puart->uts & UART_UTS_TXEMPTY)) ;

    /* Disable UART */
    puart->ucr1 &= ~UART_UCR1_UARTEN;

    /* Set to default POR state */
    puart->ucr1 = 0x00000000;
    puart->ucr2 = 0x00000000;

    while (!(puart->ucr2 & UART_UCR2_SRST_)) ;

    puart->ucr3 = 0x00000704;
    puart->ucr4 = 0x00008000;
    puart->ufcr = 0x00000801;
    puart->uesc = 0x0000002B;
    puart->utim = 0x00000000;
    puart->ubir = 0x00000000;
    puart->ubmr = 0x00000000;
    puart->onems = 0x00000000;
    puart->uts = 0x00000000;

    /* Configure FIFOs */
    puart->ufcr = (1 << UART_UFCR_RXTL_SHF) | UART_UFCR_RFDIV | (2 << UART_UFCR_TXTL_SHF);

    /* Setup One MS timer */
    puart->onems = mx_uart_reffreq(uart) / 1000;

    /* Set to 8N1 */
    puart->ucr2 &= ~UART_UCR2_PREN;
    puart->ucr2 |= UART_UCR2_WS;
    puart->ucr2 &= ~UART_UCR2_STPB;

    /* Ignore RTS */
    puart->ucr2 |= UART_UCR2_IRTS;

    /* Enable UART */
    puart->ucr1 |= UART_UCR1_UARTEN;

    /* Enable FIFOs */
    puart->ucr2 |= UART_UCR2_SRST_ | UART_UCR2_RXEN | UART_UCR2_TXEN;

    /* Clear status flags */
    puart->usr2 |= UART_USR2_ADET |
        UART_USR2_IDLE |
        UART_USR2_IRINT |
        UART_USR2_WAKE | UART_USR2_RTSF | UART_USR2_BRCD | UART_USR2_ORE | UART_USR2_RDR;

    /* Clear status flags */
    puart->usr1 |= UART_USR1_PARITYERR |
        UART_USR1_RTSD | UART_USR1_ESCF | UART_USR1_FRAMERR | UART_USR1_AIRINT | UART_USR1_AWAKE;

    /* Set the numerator value minus one of the BRM ratio */
    puart->ubir = (baud / 100) - 1;

    /* Set the denominator value minus one of the BRM ratio    */
    puart->ubmr = ((mx_uart_reffreq(uart) / 1600) - 1);
}

/*!
 * Output a character to the debug uart port
 *
 * @param       ch      pointer to the character for output
 */
void sendchar(struct mx_uart *puart, unsigned char *ch)
{
    // Wait for Tx FIFO not full
    while (puart->uts & UART_UTS_TXFULL)    // tx fifo not full
    {
    }

    if (*ch == '\n')            // Replace line feed with '\r'
    {
        puart->utxd[0] = '\r';

        while (puart->uts & UART_UTS_TXFULL) {
        }
    }

    puart->utxd[0] = *ch;
}

/*!
 * Receive a character for the debug uart port
 *
 * @return      a character received from the debug uart port; if the fifo
 *              is empty, return 0xff
 */
char receive_char(struct mx_uart *puart)
{
    // If receive fifo is empty, return false
    if (puart->uts & UART_UTS_RXEMPTY)
        return 0xFF;

    return (uint8_t) puart->urxd[0];
}
#endif

int gps_test_enable;
extern void init_uart(struct hw_module *uart, uint32_t baud);
int gps_test(void)
{
    int result = 0;

    if (!gps_test_enable) {
        return TEST_NOT_PRESENT;
    }

    PROMPT_RUN_TEST("GPS", NULL);

    /* IOMUX */
//    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_BUFFER_EN); //uart2 rxd
//    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DMARQ); //uart2 txd
//    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_INTRQ); //uart2 cts
//    writel(ALT3, IOMUXC_SW_MUX_CTL_PAD_PATA_DIOR);  //uart2 rts
//    writel(0x3, IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT);    //uart2 rxd daisy chain

//    init_uart(&uart2, 115200);

    uart2_iomux_config();
    uart_init(uart_instance, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);

   return result;
}

//RUN_TEST("GPS", gps_test)
