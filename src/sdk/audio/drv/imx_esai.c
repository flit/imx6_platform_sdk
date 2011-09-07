/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_esai.c
 * @brief Enhanced Serial Audio Interface(ESAI) driver.
 *
 */

#include "hardware.h"
#include "../inc/audio.h"
#include "../inc/imx_esai.h"

#define ESAI_DEBUG	1
#if ESAI_DEBUG
#define TRACE(fmt,args...) printf(fmt, ## args)
#else
#define TRACE(fmt,args...)
#endif

extern void esai_clk_sel_gate_on(void);
extern void esai_io_cfg(void);

////////////////////////////////////Local variables and functions/////////////////////////// 
/*!
 * Dump ESAI registers
 */
static int32_t esai_dump(audio_ctrl_p ctrl)
{
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    printf("=========%s DUMP=========\n", ctrl->name);
    printf("ECR:0x%08x\n", esai->ecr);
    printf("ESR:0x%08x\n", esai->esr);
    printf("TFCR:0x%08x\n", esai->tfcr);
    printf("TFSR:0x%08x\n", esai->tfsr);
    printf("TSR:0x%08x\n", esai->tsr);
    printf("TCR:0x%08x\n", esai->tcr);
    printf("TCCR:0x%08x\n", esai->tccr);
    printf("RCR:0x%08x\n", esai->rcr);
    printf("RCCR:0x%08x\n", esai->rccr);

    return 0;
}

/*!
 * Reset sub-modules of ESAI
 */
static int32_t esai_reset(audio_ctrl_p ctrl)
{
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    //First put ESAI in Reset state then enable it
    esai->ecr = ESAI_ECR_ERST;
    esai->ecr = ESAI_ECR_ESAIEN;
    //reset tx fifo
    esai->tfcr |= ESAI_TFCR_TFR;
    esai->tfcr &= ~ESAI_TFCR_TFR;
    //reset rx fifo
    esai->rfcr |= ESAI_RFCR_RFR;
    esai->rfcr &= ~ESAI_RFCR_RFR;
    //put tx to personal reset state
    esai->tcr |= ESAI_TCR_TPR;
    //put rx to personal reset state
    esai->rcr |= ESAI_RCR_RPR;

    return 0;
}

/*!
 * Set parameters of transmitter
 */
static int32_t esai_set_tx_hw_para(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    return 0;
}

/*!
 * Set parameters of receiver
 */
static int32_t esai_set_rx_hw_para(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    return 0;
}

/*!
 * Get parameters of transmitter
 */
static int32_t esai_get_tx_hw_para(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    return 0;
}

/*!
 * Get parameters of receiver
 */
static int32_t esai_get_rx_hw_para(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    return 0;
}

/*!
 * Get status of  transmitter
 */
static uint32_t esai_get_tx_status(audio_ctrl_p ctrl, uint32_t type)
{

    return 0;
}

/*!
 * Get status of receiver
 */
static uint32_t esai_get_rx_status(audio_ctrl_p ctrl, uint32_t type)
{
    return 0;
}

/*!
 * Enable or disable sub-modules of ESAI.
 */
static int32_t esai_enable(audio_ctrl_p ctrl, uint32_t type, uint32_t enable)
{
    return 0;
}

/*!
 * Connect all ESAI pins, and this will make the ESAI out of personal reset state. 
 */
static int32_t esai_connect_pins(audio_ctrl_p ctrl)
{
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    esai->pcrc = ESAI_GPIO_ESAI;
    esai->prrc = ESAI_GPIO_ESAI;

    return 0;
}

////////////////////////////// APIs /////////////////////////////////////
int esai_config(void *priv, audio_dev_para_p para)
{
    unsigned int val;
    unsigned int i;
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    esai->tcr = ESAI_TCR_PADC | //TX ZERO PADDING ,BIT17  1: pad 0, 0:repeat
        ESAI_TCR_TSWS_STL32_WDL24 | //32bit slot len, 24bit word len
        ESAI_TCR_TMOD_NETWORK;  //network mode

    if (AUDIO_BUS_MODE_MASTER == para->bus_mode) {
        val = ESAI_TCCR_THCKD | ESAI_TCCR_TFSD | ESAI_TCCR_TCKD |   //HCKT is output (bit23=1), FST is output (bit22=1), SCKT is output (bit21=1)
            ESAI_TCCR_TCKP |    //tX clock polarity bit 18, clock out on falling edge
            ESAI_TCCR_TFP(3) |  // clk div 4
            ESAI_TCCR_TDC(1) |  //frame rate devider,  2word per frame
            ESAI_TCCR_TPSR_BYPASS | ESAI_TCCR_TPM(4);
    } else {
        val = ESAI_TCCR_TCKP |
            ESAI_TCCR_TFP(3) | ESAI_TCCR_TDC(1) | ESAI_TCCR_TPSR_BYPASS | ESAI_TCCR_TPM(4);
    }
    esai->tccr = val;
#define ESAI_TSM_NUM(x)  (0xffff >> (16-x))
    esai->tsma = ESAI_TSM_NUM(2);
    esai->tsmb = 0;

    esai->tfcr |= ESAI_TFCR_TFR;

    esai->tfcr = ESAI_TFCR_TIEN |
        ESAI_WORD_LEN_16 |
        ESAI_TFCR_TFWM(ESAI_WATERMARK) | ESAI_TFCR_TE(para->channel_number) | ESAI_TFCR_TFEN;
    //stuff fifo
    for (i = 0; i < 120; i++) {
        esai->etdr = 0;
    }

    val = esai->tcr;
    val &= ~0x3F;
    esai->tcr |= ESAI_TCR_TE(para->channel_number);

    esai_connect_pins(ctrl);

    return 0;
}

int esai_init(void *priv)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;

    esai_clk_sel_gate_on();

    esai_io_cfg();

    esai_reset(ctrl);

    return 0;
}

int esai_deinit(void *priv)
{
    //ESAI clk can be gate off here

    return 0;
}

int esai_write_fifo(void *priv, uint8_t * buf, uint32_t size, uint32_t * bytes_written)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);
    uint32_t i = 0;
    uint32_t wl = 16;
    uint32_t val = 0;

    while (i < size) {
        do {
            val = readl(ESAI1_BASE_ADDR + ESAI_ESR_OFFSET);
        } while (!(val & (0x01 << 8))); //wait for the tx fifo empty

        if (wl <= 8) {
            val = *((uint8_t *) (buf + i));
            i++;
        } else if (wl <= 16) {
            val = *((uint16_t *) (buf + i));
            i = i + 2;
        } else {
            val = *((uint32_t *) (buf + i));
            i = i + 4;
        }

        esai->etdr = val;
    }
    *bytes_written = size;

    return 0;
}

static audio_dev_ops_t esai_ops = {
    .init = esai_init,
    .deinit = esai_deinit,
    .config = esai_config,
    .ioctl = NULL,
    .write = esai_write_fifo,
};

audio_ctrl_t imx_esai_1 = {
    .name = "imx ESAI audio controller 1",
    .base_addr = ESAI1_BASE_ADDR,
    .ops = &esai_ops,
};
