/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_esai.c
 * @brief Enhanced Serial Audio Interface(ESAI) driver.
 *
 * @ingroup diag_audio
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

#define ESAI_TX_FIFO_SIZE	120

extern void esai_clk_sel_gate_on(void);

////////////////////////////////////Local variables and functions/////////////////////////// 
/*!
 * Dump the esai registers which can be readable. 
 * @param  	ctrl	a pointer of audio controller(audio_ctrl_t) which presents the esai module itself
 *			
 * @return	0 if succeeded
 *		-1 if failed   
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
 * Put the esai to soft-reset mode, and then can be configured.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 *
 * @return      0 if succeeded
 *              -1 if failed
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
 * Set parameters of esai
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * @param       type    the parameter type want to set, refer esai_hw_para_type_e for details.
 * @param       val     the parameter value to be set.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t esai_set_hw_para(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    switch (type) {
    case ESAI_HW_PARA_ECR:
        esai->ecr = val;
        break;
    case ESAI_HW_PARA_TCR:
        esai->tcr = val;
        break;
    case ESAI_HW_PARA_RCR:
        esai->rcr = val;
        break;
    case ESAI_HW_PARA_TCCR:
        esai->tccr = val;
        break;
    case ESAI_HW_PARA_RCCR:
        esai->rccr = val;
        break;
    case ESAI_HW_PARA_TFCR:
        esai->tfcr = val;
        break;
    case ESAI_HW_PARA_RFCR:
        esai->rfcr = val;
        break;
    case ESAI_HW_PARA_TSR:
        esai->tsr = val;
        break;
    case ESAI_HW_PARA_SAICR:
        esai->saicr = val;
        break;
    case ESAI_HW_PARA_TSM:
        esai->tsma = val & 0xFFFF;
        esai->tsmb = (val >> 16) & 0xFFFF;
        break;
    case ESAI_HW_PARA_RSM:
        esai->rsma = val & 0xFFFF;
        esai->rsmb = (val >> 16) & 0xFFFF;
        break;
    }

    return 0;
}

/*!
 * Get parameters of esai
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * @param       type    the parameter type want to get, refer esai_hw_para_type_e for details.
 *
 * @return      parameter valuw
 */
static uint32_t esai_get_hw_para(audio_ctrl_p ctrl, uint32_t type)
{
    uint32_t val = 0;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    switch (type) {
    case ESAI_HW_PARA_ECR:
        val = esai->ecr;
        break;
    case ESAI_HW_PARA_TCR:
        val = esai->tcr;
        break;
    case ESAI_HW_PARA_RCR:
        val = esai->rcr;
        break;
    case ESAI_HW_PARA_TCCR:
        val = esai->tccr;
        break;
    case ESAI_HW_PARA_RCCR:
        val = esai->rccr;
        break;
    case ESAI_HW_PARA_TFCR:
        val = esai->tfcr;
        break;
    case ESAI_HW_PARA_RFCR:
        val = esai->rfcr;
        break;
    case ESAI_HW_PARA_SAICR:
        val = esai->saicr;
        break;
    case ESAI_HW_PARA_TSM:
        val = ((esai->tsmb << 16) & 0xFFFF0000) | (esai->tsma & 0xFFFF);
        break;
    case ESAI_HW_PARA_RSM:
        val = ((esai->rsmb << 16) & 0xFFFF0000) | (esai->rsma & 0xFFFF);
        break;
    case ESAI_HW_PARA_TX_WL:
        val = (esai->tfcr & ESAI_WORD_LEN_MSK) >> ESAI_WORD_LEN_SHT;
        val = 32 - val * 4;
        break;
    case ESAI_HW_PARA_RX_WL:
        val = (esai->rfcr & ESAI_WORD_LEN_MSK) >> ESAI_WORD_LEN_SHT;
        val = 32 - val * 4;
        break;
    }

    return val;
}

/*!
 * Get status of esai
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * @param       type    the status type want to get, refer esai_status_e for details.
 *
 * @return      status value
 */
static uint32_t esai_get_status(audio_ctrl_p ctrl, uint32_t type)
{
    uint32_t val = 0;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    switch (type) {
    case ESAI_STATUS_ESR:
        val = esai->esr;
        break;
    case ESAI_STATUS_TFSR:
        val = esai->tfsr;
        break;
    case ESAI_STATUS_RFSR:
        val = esai->rfsr;
        break;
    case ESAI_STATUS_SAISR:
        val = esai->saisr;
        break;
    }

    return val;
}

/*!
 * Enable or disable sub-modules of ESAI.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * @param       type    the sub-module to be set, please refer esai_sub_enable_type_e for details.
 * @param       val     the parameter value to be set.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t esai_sub_enable(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    uint32_t v = 0;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    switch (type) {
    case ESAI_SUB_ENABLE_TYPE_TX:
        v = esai->tcr;
        v &= ~ESAI_TCR_TE_MSK;
        v |= ESAI_TCR_TE(val);
        esai->tcr = v;
        break;
    case ESAI_SUB_ENABLE_TYPE_RX:
        v = esai->rcr;
        v &= ~ESAI_RCR_RE_MSK;
        v |= ESAI_RCR_RE(val);
        esai->rcr = v;
        break;
    }

    return 0;
}

/*!
 * Connect all ESAI pins, and this will make the ESAI out of personal reset state. 
 *
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * 
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t esai_connect_pins(audio_ctrl_p ctrl)
{
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    esai->pcrc = ESAI_GPIO_ESAI;
    esai->prrc = ESAI_GPIO_ESAI;

    return 0;
}

/*!
 * Fill zeros to esai tx fifo to avoid noise data transfered.
 *
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the esai module
 * 
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t esai_stuff_tx_fifo(audio_ctrl_p ctrl)
{
    uint32_t i;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    //stuff fifo
    for (i = 0; i < ESAI_TX_FIFO_SIZE; i++) {
        esai->etdr = 0;
    }

    return 0;
}

////////////////////////////// APIs /////////////////////////////////////

/*!
 * Configure the ESAI module according the parameters which was passed by audio_card driver.
 *
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 * @param       para    a pointer passed by audio card driver, consists of configuration parameters
 *              for ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_config(void *priv, audio_dev_para_p para)
{
    uint32_t val;
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);

    val = ESAI_TCR_PADC |       //TX ZERO PADDING ,BIT17  1: pad 0, 0:repeat
        ESAI_TCR_TSWS_STL32_WDL24 | //32bit slot len, 24bit word len
        ESAI_TCR_TMOD_NETWORK;  //network mode
    esai_set_hw_para(ctrl, ESAI_HW_PARA_TCR, val);

    if (AUDIO_BUS_MODE_MASTER == para->bus_mode) {
        val = ESAI_TCCR_THCKD | //HCKT is output (bit23=1)
            ESAI_TCCR_TFSD |    //FST is output (bit22=1) 
            ESAI_TCCR_TCKD |    //SCKT is output (bit21=1)
            ESAI_TCCR_TCKP |    //tX clock polarity bit 18, clock out on falling edge
            ESAI_TCCR_TDC(para->channel_number - 1);    //frame rate devider
        if (SAMPLERATE_44_1KHz == para->sample_rate) {
            //This parameters should be set according the frequency of Fsys or the HCKT
            val |= ESAI_TCCR_TFP(3) |   // clk div 4
                ESAI_TCCR_TPSR_BYPASS | //bypass
                ESAI_TCCR_TPM(4);
        } else {
            //TODO
        }
    } else {
        val = ESAI_TCCR_TCKP | ESAI_TCCR_TDC(para->channel_number - 1); //frame rate devider
    }
    esai_set_hw_para(ctrl, ESAI_HW_PARA_TCCR, val);

    esai_set_hw_para(ctrl, ESAI_HW_PARA_TSM, ESAI_TSM_NUM(para->channel_number));

    esai->tfcr |= ESAI_TFCR_TFR;

    val = ESAI_TFCR_TIEN |
        ESAI_TFCR_TFWM(ESAI_WATERMARK) | ESAI_TFCR_TE(para->channel_number) | ESAI_TFCR_TFEN;
    if (WL_16 == para->word_length)
        val |= ESAI_WORD_LEN_16;
    else if (WL_24 == para->word_length)
        val |= ESAI_WORD_LEN_24;
    else if (WL_20 == para->word_length)
        val |= ESAI_WORD_LEN_20;
    esai_set_hw_para(ctrl, ESAI_HW_PARA_TFCR, val);

    esai_stuff_tx_fifo(ctrl);

    esai_sub_enable(ctrl, ESAI_SUB_ENABLE_TYPE_TX, para->channel_number);

    esai_connect_pins(ctrl);

    return 0;
}

/*!
 * Initialize the esai module and set the esai to default status. 
 * This function will be called by the snd_card driver. 
 *
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it 
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_init(void *priv)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;

    esai_clk_sel_gate_on();

    esai_iomux_config();

    esai_reset(ctrl);

    return 0;
}

/*!
 * Close the ESAI module
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_deinit(void *priv)
{
    //ESAI clk can be gate off here

    return 0;
}

/*!
 * Write datas to the esai fifo in polling mode.
 * @param       priv    a pointer passed by audio card driver, esai driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 * @param       buf     points to the buffer which hold the data to be written to the ESAI tx fifo
 * @param       size    the size of the buffer pointed by buf.
 * @param       bytes_written	bytes be written to the ESAI tx fifo
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_write_fifo(void *priv, uint8_t * buf, uint32_t size, uint32_t * bytes_written)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_esai_regs_p esai = (imx_esai_regs_p) (ctrl->base_addr);
    uint32_t i = 0;
    uint32_t wl = 0;
    uint32_t val = 0;

    wl = esai_get_hw_para(ctrl, ESAI_HW_PARA_TX_WL);

    while (i < size) {
        //wait for the tx fifo empty
        do {
            val = esai_get_status(ctrl, ESAI_STATUS_ESR);
        } while (!(val & ESAI_ESR_TFE));

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
