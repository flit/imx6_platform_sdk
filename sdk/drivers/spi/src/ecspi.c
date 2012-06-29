/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include "ecspi.h"
#include "hardware.h"
#include "ecspi_ifc.h"
#include "iomux_config.h"

/*-------------------------------------------- Static Variable --------------------------------------------*/
static uint32_t ecspi_addr_table[NUM_OF_ECSPI] = {
    ECSPI1_BASE_ADDR,
    ECSPI2_BASE_ADDR,
    ECSPI3_BASE_ADDR,
    ECSPI4_BASE_ADDR,
    ECSPI5_BASE_ADDR,
};

/*-------------------------------------------- Static Function --------------------------------------------*/

static ecspi_register_ptr ecspi_get_instance(dev_ecspi_e dev)
{
    if (dev >= NUM_OF_ECSPI) {
        printf("Invalid eCSPI device instance.\n");
        return NULL;
    }

    return (ecspi_register_ptr) ecspi_addr_table[dev];
}

static void ecspi_start_transfer(ecspi_register_ptr base, uint16_t brs_bts)
{
    /* Set burst length */
    base->ctrl &= ~ECSPI_CTL_BURST_MASK;
    base->ctrl |= (brs_bts - 1) << ECSPI_CTL_BURST_SHIFT;

    /* Clear status */
    base->status &= ~ECSPI_STS_ALL_MASK;
}

static int ecspi_xfer_slv(ecspi_register_ptr base, uint8_t * tx_buf, uint8_t * rx_buf, int bytes)
{
    printf("Slave mode transfer code not validated yet.\n");
    return FAIL;
}

static int ecspi_xfer_mst(ecspi_register_ptr base, uint8_t * tx_buf, uint8_t * rx_buf, int bytes)
{
    uint32_t val, idx;

    /* Start burst */
    base->ctrl |= ECSPI_CTL_SMC_MASK;

    /* Write to Tx FIFO */
    for (idx = 0; idx < bytes; idx += 4) {
        val =
            tx_buf[idx] + (tx_buf[idx + 1] << 8) + (tx_buf[idx + 2] << 16) +
            (tx_buf[idx + 3] << 24);
        base->txfifo = val;
    }

    /* Wait for transfer complete */
    val = SPI_RETRY_TIMES;
    while ((base->status & ECSPI_STS_TC_MASK) == 0) {
        val--;
        if (val == 0) {
            printf("ecspi_xfer: Transfer timeout.\n");
            return FAIL;
        }

        hal_delay_us(500);
    }

    /* Read from Rx FIFO */
    for (idx = 0; bytes > 0; bytes -= 4, idx += 4) {
        val = base->rxfifo;

        switch (bytes) {
        default:
            rx_buf[idx + 3] = val >> 24;
        case 3:
            rx_buf[idx + 2] = (val >> 16) & 0xFF;
        case 2:
            rx_buf[idx + 1] = (val >> 8) & 0xFF;
        case 1:
            rx_buf[idx] = val & 0xFF;
            break;
        }
    }

    /* Clear status */
    base->status &= ~ECSPI_STS_TC_MASK;

    return SUCCESS;
}

static void ecspi_configure(ecspi_register_ptr base, param_ecspi_t param)
{
    /* Reset eCSPI controller */
    base->ctrl &= ~ECSPI_CTL_EN;

    /* Setup chip select */
    base->ctrl &= ~ECSPI_CTL_CS_MASK;
    base->ctrl |= param.B.channel << ECSPI_CTL_CS_SHIFT;

    /* Setup mode */
    base->ctrl &= ~(1 << (ECSPI_CTL_MD_SHIFT + param.B.channel));
    base->ctrl |= param.B.mode << (ECSPI_CTL_MD_SHIFT + param.B.channel);

    /* Setup pre & post clock divider */
    base->ctrl &= ~(ECSPI_CTL_PRE_MASK | ECSPI_CTL_POST_MASK);
    base->ctrl |= param.B.pre_div << ECSPI_CTL_PRE_SHIFT;
    base->ctrl |= param.B.post_div << ECSPI_CTL_POST_SHIFT;

    /* Enable eCSPI */
    base->ctrl |= ECSPI_CTL_EN;

    /* Setup SCLK_PHA, SCLK_POL, SS_POL */
    base->config &= ~ECSPI_CFG_MASK;
    base->config |= param.B.sclk_pha << (ECSPI_CFG_SCLK_PHA_SHIFT + param.B.channel);
    base->config |= param.B.sclk_pol << (ECSPI_CFG_SCLK_POL_SHIFT + param.B.channel);
    base->config |= param.B.ss_pol << (ECSPI_CFG_SS_POL_SHIFT + param.B.channel);
    base->config |= 1 << (ECSPI_CFG_SS_CTL_SHIFT + param.B.channel);
}

/*-------------------------------------------- Global Function --------------------------------------------*/
int ecspi_open(dev_ecspi_e dev, param_ecspi_t param)
{
    ecspi_register_ptr base = ecspi_get_instance(dev);

    if (base == NULL) {
        return FAIL;
    }

    /* Configure clock gating here if necessary */

    /* Configure IO signals */
    ecspi_iomux_config((uint32_t)(dev + 1));

    /* Configure eCSPI registers */
    ecspi_configure(base, param);

    return SUCCESS;
}

int ecspi_close(dev_ecspi_e dev)
{
    ecspi_register_ptr base = ecspi_get_instance(dev);

    if (base == NULL) {
        return FAIL;
    }

    /* Disable controller */
    base->ctrl &= ~ECSPI_CTL_EN;

    return SUCCESS;
}

int ecspi_ioctl(dev_ecspi_e dev, param_ecspi_t param)
{
    ecspi_register_ptr base = ecspi_get_instance(dev);

    if (base == NULL) {
        return FAIL;
    }

    ecspi_configure(base, param);

    return SUCCESS;
}

int ecspi_xfer(dev_ecspi_e dev, uint8_t * tx_buf, uint8_t * rx_buf, uint16_t brs_bts)
{
    int bytes;
    uint32_t channel, retv = SUCCESS;
    ecspi_register_ptr base = ecspi_get_instance(dev);

    if (base == NULL) {
        retv = FAIL;
    }

    /* Set bytes for burst */
    bytes = brs_bts >> 3;

    /* Handle non-byte-aligned bits */
    if ((brs_bts & 0x7) != 0) {
        bytes++;
    }

    /* Check burst length */
    if (bytes > ECSPI_FIFO_SIZE * 4) {
        printf("ecspi_xfer: Burst out of length.\n");
        retv = FAIL;
    }

    if (retv == SUCCESS) {
        /* Prepare transfer */
        ecspi_start_transfer(base, brs_bts);

        /* Initiate transfer  */
        channel = (base->ctrl & ECSPI_CTL_CS_MASK) >> ECSPI_CTL_CS_SHIFT;

        /* Handle different mode transfer */
        if ((base->ctrl & (1 << (ECSPI_CTL_MD_SHIFT + channel))) == 0) {
            retv = ecspi_xfer_slv(base, tx_buf, rx_buf, bytes);
        } else {
            retv = ecspi_xfer_mst(base, tx_buf, rx_buf, bytes);
        }
    }

    return retv;
}
