/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx-audmux.c
 * @brief Driver for AUDMUX.
 *
 * @ingroup diag_audio
 */

#include <stdio.h>
#include "sdk.h"
#include "hardware.h"
#include "audio/imx-audmux.h"

/*!
 * Dump the registers of audmux
 *
 * @return  always 0 
 */
static uint32_t audmux_dump(void)
{
    uint32_t idx;
    uint32_t pPTCR, pPDCR;

    printf("=======================AUDMUX dump===================\n");
    for (idx = AUDMUX_PORT_INDEX_MIN; idx < AUDMUX_PORT_INDEX_MAX; idx++) {
        pPTCR = AUDMUX_BASE_ADDR + AUDMUX_PTCR_OFFSET(idx);
        pPDCR = AUDMUX_BASE_ADDR + AUDMUX_PDCR_OFFSET(idx);
        printf("PTCR%d: 0x%x\n", idx, readl(pPTCR));
        printf("PDCR%d: 0x%x\n", idx, readl(pPDCR));
    }

    return 0;
}

/*!
 * Set ptcr and pdcr of the audmux port
 *
 * @param   port	the port to be set
 * @param   ptcr	ptcr value to be set
 * @param   pdcr	pdcr value to be set
 * @return  0 if succeeded
 *	    -1 if failed. 
 */
uint32_t audmux_port_set(uint32_t port, uint32_t ptcr, uint32_t pdcr)
{
    uint32_t pPTCR, pPDCR;

    if ((port < AUDMUX_PORT_INDEX_MIN) || (port > AUDMUX_PORT_INDEX_MAX)) {
        return -1;
    }

    pPTCR = AUDMUX_BASE_ADDR + AUDMUX_PTCR_OFFSET(port);
    pPDCR = AUDMUX_BASE_ADDR + AUDMUX_PDCR_OFFSET(port);

    writel(ptcr, pPTCR);
    writel(pdcr, pPDCR);

    return 0;
}

/*!
 * Set audmux port according the ssi mode(master/slave).
 * we set the audumx ports in sync mode which is the default status for most codec.
 * 
 * @param   intPort	the internal port to be set
 * @param   extPort	the external port to be set
 * @param   is_master	ssi mode(master/slave)
 * @return  0 if succeeded
 *	    -1 if failed. 
 */
uint32_t audmux_route(uint32_t intPort, uint32_t extPort, uint32_t is_master)
{
    uint32_t pPTCR, pPDCR;

    if ((intPort < AUDMUX_PORT_INDEX_MIN) || (intPort > AUDMUX_PORT_INDEX_MAX) ||
        (extPort < AUDMUX_PORT_INDEX_MIN) || (extPort > AUDMUX_PORT_INDEX_MAX)) {
        return -1;
    }
    // Get pointers to the Audio MUX internal port registers.
    pPTCR = AUDMUX_BASE_ADDR + AUDMUX_PTCR_OFFSET(intPort);
    pPDCR = AUDMUX_BASE_ADDR + AUDMUX_PDCR_OFFSET(intPort);

    // Configure the Audio MUX internal port to connect with the SSI based
    // upon who is acting as the bus master.
    //
    // But regardless of who is the master, we also configure the internal
    // port for synchronous 4-wire operation in normal mode (which is what
    // we actually need to support the SSI and PMIC for either network or I2S
    // modes).
    //
    // Note that we only configure the transmit framesync and bitclock here
    // because we are using synchronous mode and the receiver clock
    // settings will be determined by the transmitter settings.
    if (AUDMUX_SSI_MASTER == is_master) {
        // All clock signals for the internal port are input signals for
        // SSI master mode.
        writel(CSP_BITFVAL(AUDMUX_PTCR_TFSDIR, AUDMUX_PTCR_TFSDIR_INPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TCLKDIR, AUDMUX_PTCR_TCLKDIR_INPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_SYN, AUDMUX_PTCR_SYN_SYNC), pPTCR);
    } else {
        // All clock signals for the internal port are all output signals for
        //  slave mode. The source of the clock signals is the external
        // port that is connected to the PMIC.
        writel(CSP_BITFVAL(AUDMUX_PTCR_TFSDIR, AUDMUX_PTCR_TFSDIR_OUTPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TFSEL, extPort - 1) |
               CSP_BITFVAL(AUDMUX_PTCR_TCLKDIR, AUDMUX_PTCR_TCLKDIR_OUTPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TCSEL, extPort - 1) |
               CSP_BITFVAL(AUDMUX_PTCR_SYN, AUDMUX_PTCR_SYN_SYNC), pPTCR);
    }

    writel(CSP_BITFVAL(AUDMUX_PDCR_RXDSEL, extPort - 1) |
           CSP_BITFVAL(AUDMUX_PDCR_TXRXEN, AUDMUX_PDCR_TXRXEN_NO_SWAP) |
           CSP_BITFVAL(AUDMUX_PDCR_MODE, AUDMUX_PDCR_MODE_NORMAL), pPDCR);

    // Get pointers to the Audio MUX external port registers.
    pPTCR = AUDMUX_BASE_ADDR + AUDMUX_PTCR_OFFSET(extPort);
    pPDCR = AUDMUX_BASE_ADDR + AUDMUX_PDCR_OFFSET(extPort);

    // Configure the Audio MUX external port to connect with the PMIC based
    // upon who is acting as the bus master.
    //
    // But regardless of who is the master, we also configure the external
    // port for synchronous 4-wire operation in normal mode (which is what
    // we actually need to support the SSI and PMIC in either network or I2S
    // mode).
    if (AUDMUX_SSI_MASTER == is_master) {
        // All clock signals for the external port are output signals for
        // SSI master mode. The source of the clock signals is the internal
        // port that is connected to the SSI.
        writel(CSP_BITFVAL(AUDMUX_PTCR_TFSDIR, AUDMUX_PTCR_TFSDIR_OUTPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TFSEL, intPort - 1) |
               CSP_BITFVAL(AUDMUX_PTCR_TCLKDIR, AUDMUX_PTCR_TCLKDIR_OUTPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TCSEL, intPort - 1) |
               CSP_BITFVAL(AUDMUX_PTCR_SYN, AUDMUX_PTCR_SYN_SYNC), pPTCR);
    } else {
        // All clock signals for the external port are input signals for
        // PMIC master mode.
        writel(CSP_BITFVAL(AUDMUX_PTCR_TFSDIR, AUDMUX_PTCR_TFSDIR_INPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_TCLKDIR, AUDMUX_PTCR_TCLKDIR_INPUT) |
               CSP_BITFVAL(AUDMUX_PTCR_SYN, AUDMUX_PTCR_SYN_SYNC), pPTCR);
    }

    writel(CSP_BITFVAL(AUDMUX_PDCR_RXDSEL, intPort - 1) |
           CSP_BITFVAL(AUDMUX_PDCR_TXRXEN, AUDMUX_PDCR_TXRXEN_NO_SWAP) |
           CSP_BITFVAL(AUDMUX_PDCR_MODE, AUDMUX_PDCR_MODE_NORMAL), pPDCR);

    return 0;
}
