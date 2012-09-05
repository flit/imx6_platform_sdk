/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx-ssi.c
 * @brief SSI driver.
 *
 *  * @ingroup diag_audio
 */

#include <stdio.h>
#include "sdk.h"
#include "hardware.h"
#include "audio/audio.h"
#include "audio/imx-ssi.h"

#define SSI_DEBUG 0
#define SSI_READ_TIMEOUT      0x400000
#define SSI_WRITE_TIMEOUT     0x400000

#if SSI_DEBUG
#define D(fmt,args...) printf(fmt, ## args)
#else
#define D(fmt,args...)
#endif

////////////////////////////////////Local variables and functions/////////////////////////// 

/*!
 * Dump the ssi registers which can be readable. 
 * @param  	ctrl	a pointer of audio controller(audio_ctrl_t) which presents the ssi module itself
 *			
 * @return	0 if succeeded
 *		-1 if failed   
 */
static int32_t ssi_dump(audio_ctrl_p ctrl)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    printf("=================%s dump==================\n", ctrl->name);
    printf("SCR    : 0x%08x\n", ssi->scr);
    printf("SISR   : 0x%08x\n", ssi->sisr);
    printf("SIER   : 0x%08x\n", ssi->sier);
    printf("STCR   : 0x%08x\n", ssi->stcr);
    printf("SRCR   : 0x%08x\n", ssi->srcr);
    printf("STCCR  : 0x%08x\n", ssi->stccr);
    printf("SRCCR  : 0x%08x\n", ssi->srccr);
    printf("SFCSR  : 0x%08x\n", ssi->sfcsr);
    printf("SACNT  : 0x%08x\n", ssi->sacnt);
    printf("SACADD : 0x%08x\n", ssi->sacadd);
    printf("SACDAT : 0x%08x\n", ssi->sacdat);
    printf("SATAG  : 0x%08x\n", ssi->satag);
    printf("STMSK  : 0x%08x\n", ssi->stmsk);
    printf("SRMSK  : 0x%08x\n", ssi->srmsk);
    printf("SACCST : 0x%08x\n", ssi->saccst);
    printf("SACCEN : 0x%08x\n", ssi->saccen);
    printf("SACCDIS: 0x%08x\n", ssi->saccdis);

    return 0;
}

/*! 
 * Put the ssi to soft-reset mode, and then can be configured.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t ssi_soft_reset(audio_ctrl_p ctrl)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    ssi->scr &= ~SSI_SCR_SSIEN;

    return 0;
}

/*!
 * Set all the registers to reset values, called by ssi_init.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static int32_t ssi_registers_reset(audio_ctrl_p ctrl)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    //Reset control regs. All the status regs will be reset by a soft reset. 
    ssi->scr = SSI_SCR_RESET_VAL;
    ssi->sier = SSI_SIER_RESET_VAL;
    ssi->stcr = SSI_STCR_RESET_VAL;
    ssi->srcr = SSI_SRCR_RESET_VAL;
    ssi->stccr = SSI_STCCR_RESET_VAL;
    ssi->srccr = SSI_SRCCR_RESET_VAL;
    ssi->sfcsr = SSI_SFCSR_RESET_VAL;
    ssi->sacnt = SSI_SACNT_RESET_VAL;
    ssi->sacadd = SSI_SACADD_RESET_VAL;
    ssi->sacdat = SSI_SACDAT_RESET_VAL;
    ssi->stmsk = SSI_STMSK_RESET_VAL;
    ssi->srmsk = SSI_SRMSK_RESET_VAL;
    ssi->saccen = SSI_SACCEN_RESET_VAL;
    ssi->saccdis = SSI_SACCDIS_RESET_VAL;

    return 0;
}

/*!
 * Get the ssi's settings.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 * @param       type    SSI FIFO settings
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static uint32_t ssi_get_hw_setting(audio_ctrl_p ctrl, uint32_t type)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);
    uint32_t val = 0;

    switch (type) {
    case SSI_SETTING_TX_FIFO1_DATAS_CNT:
        val = (ssi->sfcsr & SSI_SFCSR_TFCNT0_MASK) >> SSI_SFCSR_TFCNT0_SHIFT;
        break;
    case SSI_SETTING_TX_FIFO2_DATAS_CNT:
        val = (ssi->sfcsr & SSI_SFCSR_TFCNT1_MASK) >> SSI_SFCSR_TFCNT1_SHIFT;
        break;
    case SSI_SETTING_RX_FIFO1_DATAS_CNT:
        val = (ssi->sfcsr & SSI_SFCSR_RFCNT0_MASK) >> SSI_SFCSR_RFCNT0_SHIFT;
        break;
    case SSI_SETTING_RX_FIFO2_DATAS_CNT:
        val = (ssi->sfcsr & SSI_SFCSR_RFCNT1_MASK) >> SSI_SFCSR_RFCNT1_SHIFT;
        break;
    case SSI_SETTING_TX_WATERMARK:
        val = (ssi->stccr & SSI_SFCSR_TFWM0_MASK) >> SSI_SFCSR_TFWM0_SHIFT;
        break;
    case SSI_SETTING_RX_WATERMARK:
        val = (ssi->sfcsr & SSI_SFCSR_RFWM0_MASK) >> SSI_SFCSR_RFWM0_SHIFT;
        break;
    case SSI_SETTING_TX_WORD_LEN:
        val = (ssi->stccr & SSI_STCCR_WL_MASK) >> SSI_STCCR_WL_SHIFT;
        val = (val + 1) * 2;
        break;
    case SSI_SETTING_RX_WORD_LEN:
        val = (ssi->srccr & SSI_SRCCR_WL_MASK) >> SSI_SRCCR_WL_SHIFT;
        val = (val + 1) *2;
        break;
    default:
        break;
    }

    return val;
}

/*!
 * Set the ssi's settings.
 * @param       ctrl    a pointer of audio controller(audio_ctrl_t) which presents the ssi module
 * @param       type    SSI FIFO settings
 * @param       val     FIFO watermark level value 
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
static uint32_t ssi_set_hw_setting(audio_ctrl_p ctrl, uint32_t type, uint32_t val)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);
    uint32_t v = 0;

    switch (type) {
    case SSI_SETTING_TX_WATERMARK:
        v = ssi->sfcsr;
        v &= ~(SSI_SFCSR_TFWM0_MASK | SSI_SFCSR_TFWM1_MASK);
        v |= SSI_SFCSR_TFWM0(val) | SSI_SFCSR_TFWM1(val);
        ssi->sfcsr = v;
        break;
    case SSI_SETTING_RX_WATERMARK:
        v = ssi->sfcsr;
        v &= ~(SSI_SFCSR_RFWM0_MASK | SSI_SFCSR_RFWM1_MASK);
        v |= SSI_SFCSR_RFWM0(val) | SSI_SFCSR_RFWM1(val);
        ssi->sfcsr = v;
        break;
    case SSI_SETTING_TX_WORD_LEN:
        v = ssi->stccr;
        v &= ~SSI_STCCR_WL_MASK;
        v |= SSI_STCCR_WL(val);
        ssi->stccr = v;
        break;
    case SSI_SETTING_RX_WORD_LEN:
        v = ssi->srccr;
        v &= ~SSI_SRCCR_WL_MASK;
        v |= SSI_SRCCR_WL(val);
        ssi->srccr = v;
        break;
    case SSI_SETTING_TX_BIT_CLOCK:
        v = ssi->stccr;
//        v &= ~(SSI_STCCR_DIV2 | SSI_STCCR_PSR | SSI_STCCR_PM_MASK);
        v &= ~(SSI_STCCR_PSR | SSI_STCCR_PM_MASK);
        v |= val;
        ssi->stccr = v;
        break;
    case SSI_SETTING_RX_BIT_CLOCK:
        v = ssi->srccr;
        v &= ~(SSI_SRCCR_DIV2 | SSI_SRCCR_PSR | SSI_SRCCR_PM_MASK);
        v |= val;
        ssi->srccr = v;
        break;
    case SSI_SETTING_TX_FRAME_LENGTH:
        v = ssi->stccr;
        v &= ~SSI_STCCR_DC_MASK;
        v |= SSI_STCCR_DC(val);
        ssi->stccr = v;
        break;
    case SSI_SETTING_RX_FRAME_LENGTH:
        v = ssi->srccr;
        v &= ~SSI_SRCCR_DC_MASK;
        v |= SSI_SRCCR_DC(val);
        ssi->srccr = v;
        break;
    case SSI_SETTING_CLK_FS_DIR:
        if (SSI_CLK_FS_DIR_OUTPUT == val) {
            ssi->stcr |= SSI_STCR_TXDIR | SSI_STCR_TFDIR;
        } else if (SSI_CLK_FS_DIR_INPUT == val) {
            ssi->stcr &= ~(SSI_STCR_TXDIR | SSI_STCR_TFDIR);
        }
        break;
    default:
        return -1;
    }

    return 0;
}

static uint32_t ssi_hw_enable(audio_ctrl_p ctrl, uint32_t type, bool enable)
{
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    switch (type) {
    case SSI_HW_ENABLE_SSI:
        if (enable)
            ssi->scr |= SSI_SCR_SSIEN;
        else
            ssi->scr &= ~SSI_SCR_SSIEN;
        break;
    case SSI_HW_ENABLE_TX:
        if (enable)
            ssi->scr |= SSI_SCR_TE;
        else
            ssi->scr &= ~SSI_SCR_TE;
        break;
    case SSI_HW_ENABLE_RX:
        if (enable)
            ssi->scr |= SSI_SCR_RE;
        else
            ssi->scr &= ~SSI_SCR_RE;
        break;
    case SSI_HW_ENABLE_TXFIFO1:
        if (enable)
            ssi->stcr |= SSI_STCR_TFEN0;
        else
            ssi->stcr &= ~SSI_STCR_TFEN0;
        break;
    case SSI_HW_ENABLE_TXFIFO2:
        if (enable)
            ssi->stcr |= SSI_STCR_TFEN1;
        else
            ssi->stcr &= ~SSI_STCR_TFEN1;
        break;
    case SSI_HW_ENABLE_RXFIFO1:
        if (enable)
            ssi->srcr |= SSI_SRCR_RFEN0;
        else
            ssi->srcr &= ~SSI_SRCR_RFEN0;
        break;
    case SSI_HW_ENABLE_RXFIFO2:
        if (enable)
            ssi->srcr |= SSI_SRCR_RFEN1;
        else
            ssi->srcr &= ~SSI_SRCR_RFEN1;
        break;
    default:
        break;
    }

    return 0;
}

//////////////////////////////////////// APIs //////////////////////////////////////////////////////////////

/*!
 * Initialize the ssi module and set the ssi to default status. 
 * This function will be called by the snd_card driver. 
 *
 * @param       priv    a pointer passed by audio card driver, SSI driver should change it 
 *			to a audio_ctrl_p pointer which presents the SSI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t ssi_init(void *priv)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;

    audmux_iomux_config();
    ssi_soft_reset(ctrl);
    ssi_registers_reset(ctrl);

    return 0;
}

/*!
 * Configure the SSI module according the parameters which was passed by audio_card driver.
 *
 * @param       priv    a pointer passed by audio card driver, SSI driver should change it
 *                      to a audio_ctrl_p pointer which presents the SSI controller.
 * @param       para	a pointer passed by audio card driver, consists of configuration parameters
 *                      for SSI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t ssi_config(void *priv, audio_dev_para_p para)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (AUDIO_BUS_PROTOCOL_I2S == para->bus_protocol) {
        if (AUDIO_BUS_MODE_SLAVE == para->bus_mode) {
            ssi->scr |= SSI_SCR_I2S_MODE_SLAVE;
            ssi_set_hw_setting(ctrl, SSI_SETTING_CLK_FS_DIR, SSI_CLK_FS_DIR_INPUT);
        } else {
            ssi->scr |= SSI_SCR_I2S_MODE_MSTR;
            ssi_set_hw_setting(ctrl, SSI_SETTING_CLK_FS_DIR, SSI_CLK_FS_DIR_OUTPUT);
        }

        ssi->scr |= SSI_SCR_CLK_IST | SSI_SCR_SYN;
        ssi->stcr |= SSI_STCR_TSCKP | SSI_STCR_TEFS;
//        ssi->stccr |= SSI_STCCR_DC(1) | SSI_STCCR_PM(0);
        ssi->stccr |= SSI_STCCR_DC(1) | SSI_STCCR_PM(0xA);
    } else {
        //TODO
    }

    ssi_set_hw_setting(ctrl, SSI_SETTING_TX_WORD_LEN, para->word_length);

    ssi_set_hw_setting(ctrl, SSI_SETTING_TX_WATERMARK, SSI_SFCSR_TX_WATERMARK);
    ssi_set_hw_setting(ctrl, SSI_SETTING_RX_WATERMARK, SSI_SFCSR_RX_WATERMARK);

    ssi_hw_enable(ctrl, SSI_HW_ENABLE_SSI, true);
    ssi_hw_enable(ctrl, SSI_HW_ENABLE_TXFIFO1, true);
    ssi_hw_enable(ctrl, SSI_HW_ENABLE_TX, true);

    ssi_hw_enable(ctrl, SSI_HW_ENABLE_RX, true);
    ssi_hw_enable(ctrl, SSI_HW_ENABLE_RXFIFO1, true);

//    ssi_dump(ctrl);

    return 0;
}

/*!
 * Write datas to the ssi fifo in polling mode.
 * @param       priv    a pointer passed by audio card driver, SSI driver should change it
 *                      to a audio_ctrl_p pointer which presents the SSI controller.
 * @param       buf	points to the buffer which hold the data to be written to the SSI tx fifo
 * @param       size    the size of the buffer pointed by buf.
 * @param       bytes_written	bytes be written to the SSI tx fifo
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t ssi_write_fifo(void *priv, uint8_t * buf, uint32_t size, uint32_t * bytes_written)
{
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);
    uint32_t i = 0;
    uint32_t wl = ssi_get_hw_setting(ctrl, SSI_SETTING_TX_WORD_LEN);

    while (i < size) {
        if (0x0E > ssi_get_hw_setting(ctrl, SSI_SETTING_TX_FIFO1_DATAS_CNT)) {
            if (wl <= 8) {
                ssi->stx0 = *((uint8_t *) (buf + i));
                i++;
            } else if (wl <= 16) {
                ssi->stx0 = *((uint16_t *) (buf + i));
                i = i + 2;
            } else {
                ssi->stx0 = *((uint32_t *) (buf + i));
                i = i + 4;
            }
        }
    }

    *bytes_written = size;

    return 0;
}

int32_t ssi_read_fifo(void *priv, uint8_t *buf, uint32_t byte2read, uint32_t * byteread)
{
    uint32_t i, size, sample_cnt;
    uint16_t *buf_ptr = (uint16_t *) buf;
    audio_ctrl_p ctrl = (audio_ctrl_p) priv;
    volatile imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);
    uint32_t wl = ssi_get_hw_setting(ctrl, SSI_SETTING_RX_WORD_LEN);
    int32_t time_out_tmp;
    
    size = byte2read/(wl);
    for ( i = 0; i < size; i++, buf_ptr++) {
        time_out_tmp = SSI_READ_TIMEOUT;
        do {
            sample_cnt = ((ssi->sfcsr) >> 12) & 0x0F;
        } while ((time_out_tmp--) && (sample_cnt == 0));

        if (0 >= time_out_tmp) {
            return -1;
        }

        *buf_ptr = (ssi->srx0);
    }
    *byteread = byte2read;

    return 0; 
}

/*!
 * Close the SSI module
 * @param       priv    a pointer passed by audio card driver, SSI driver should change it
 *                      to a audio_ctrl_p pointer which presents the SSI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t ssi_deinit(void *priv)
{
    volatile uint32_t val;

    val = SSI_SISR_TDE0 | SSI_SISR_TDE1 | SSI_SISR_TFE0 | SSI_SISR_TFE1;
    writel(val, SSI2_BASE_ADDR + SSI_SISR_OFFSET);
    writel(0, SSI2_BASE_ADDR + SSI_SCR_OFFSET);

    return 0;
}

static audio_dev_ops_t ssi_ops = {
    .init = ssi_init,
    .deinit = ssi_deinit,
    .config = ssi_config,
    .ioctl = NULL,
    .write = ssi_write_fifo,
    .read = ssi_read_fifo,
};

audio_ctrl_t imx_ssi_1 = {
    .name = "imx SSI audio controller 1",
    .base_addr = SSI1_BASE_ADDR,
    .ops = &ssi_ops,
};
audio_ctrl_t imx_ssi_2 = {
    .name = "imx SSI audio controller 2",
    .base_addr = SSI2_BASE_ADDR,
    .ops = &ssi_ops,
};
audio_ctrl_t imx_ssi_3 = {
    .name = "imx SSI audio controller 3",
    .base_addr = SSI3_BASE_ADDR,
    .ops = &ssi_ops,
};
