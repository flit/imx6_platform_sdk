/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx-ssi.c
 * @brief 
 *
 */

#include <stdio.h>
#include "io.h"
#include "hardware.h"
#include "soc_memory_map.h"
#include "../inc/imx-ssi.h"
#include "../inc/audio.h"

#define SSI_DEBUG_ENABLE	1
#if SSI_DEBUG_ENABLE
#define TRACE(fmt, args...)	printf(fmt,##args)
#else
#define TRACE(fmt, args...)
#endif

/*!
 * Dump the ssi's registers. 
 *
 * @param   module      pointer to the ssi module structure
 *
 * @return  false if failed
 *	    true if succeed
 */
static int ssi_dump(audio_ctrl_p ctrl)
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
    printf("STR    : 0x%08x\n", ssi->str);
    printf("SOR    : 0x%08x\n", ssi->sor);
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
 * Obtain SSI clock frequency
 *
 * @param   module      pointer to the ssi module structure
 *
 * @return  reference freq in hz
 */
static uint32_t ssi_get_freq(audio_ctrl_p ctrl)
{
	//TODO
    return 0;
}

/*!
 * Reset the SSI. 
 * The SSI status bits are preset to the same state produced by the Power-on reset.
 * The SSI control bits are unaffected. The SSI should be put into reset mode to configure.
 *
 * @param   module      pointer to the ssi module structure
 *
 * @return  false if failed
 *	    true if succeed
 */
static int ssi_soft_reset(audio_ctrl_p ctrl)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    ssi->scr &= ~SSI_SCR_SSIEN;

    return 0;
}

/*!
 * In master and synchronous mode, the unused port SRCK is used as Serial Oversampling 
 * Clock (network clock, or MCLK) enabled by the SCR register bit 15, SYS_CLK_EN.
 *
 * @param   module      pointer to the ssi module structure
 *	    is_out	the sysclk for SSI will output or not
 * @return  false if failed
 *	    true if succeed
*/
static int ssi_set_sysclk(audio_ctrl_p ctrl, bool is_out)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    if (is_out)
        ssi->scr |= SSI_SCR_SYS_CLK_EN;
    else
        ssi->scr &= ~SSI_SCR_SYS_CLK_EN;

    return 0;
}

/*!
 * Disable rx/tx,  and then the SSI. Refer to i.mx53_RM Chapter 72.4.7
 *
 * @param   module      pointer to the ssi module structure
 *
 * @return  
 */
static int ssi_shutdown_clk(audio_ctrl_p ctrl, uint32_t clk_id)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    //TODO 
    switch (clk_id) {
    case SSI_CLK_ID_TX:
        break;
    case SSI_CLK_ID_RX:
        break;
    default:
        break;
    }
    return 0;
}

/*!
 * SSI Clock dividers
 * Should only be called when port is inactive (i.e. SSIEN = 0).
 *
 * @param   module      pointer to the ssi module structure
 *	    clk_id	the clk want to set
 *	    div		divider value
 * @return  false if failed
 *	    true if succeed
 */
static int ssi_set_clkdiv(audio_ctrl_p ctrl, uint32_t div_id, uint32_t div)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    switch (div_id) {
    case IMX_SSI_TX_DIV_2:
        ssi->stccr &= ~SSI_STCCR_DIV2_MASK;
        ssi->stccr |= SSI_STCCR_DIV2(div);
        break;
    case IMX_SSI_TX_DIV_PSR:
        ssi->stccr &= ~SSI_STCCR_PSR_MASK;
        ssi->stccr |= SSI_STCCR_PSR(div);
        break;
    case IMX_SSI_TX_DIV_PM:
        ssi->stccr &= ~SSI_STCCR_PM_MASK;
        ssi->stccr |= SSI_STCCR_PM(div);
        break;
    case IMX_SSI_RX_DIV_2:
        ssi->srccr &= ~SSI_SRCCR_DIV2_MASK;
        ssi->srccr |= SSI_SRCCR_DIV2(div);
        break;
    case IMX_SSI_RX_DIV_PSR:
        ssi->srccr &= ~SSI_SRCCR_PSR_MASK;
        ssi->srccr |= SSI_SRCCR_PSR(div);
        break;
    case IMX_SSI_RX_DIV_PM:
        ssi->srccr &= ~SSI_SRCCR_PM_MASK;
        ssi->srccr |= SSI_SRCCR_PM(div);
        break;
    default:
        return -1;
    }

    return 0;
}

/*!
 * 
 * Should only be called when port is inactive (i.e. SSIEN = 0).
 *
 * @param   module      pointer to the ssi module structure
 *	    tx_mask	tdm slot mask for tx
 *	    rx_mask	tdm slot mask for rx
 *	    slots	number of time slot
 *	    slot_width	slot width
 * @return  false if failed
 *	    true if succeed
 */
static int ssi_set_tdm_slot(audio_ctrl_p ctrl,
                             unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    ssi->stmsk = tx_mask;
    ssi->srmsk = rx_mask;
    ssi->stccr &= ~SSI_STCCR_DC_MASK;
    ssi->stccr |= SSI_STCCR_DC(slots - 1);

    ssi->srccr &= ~SSI_SRCCR_DC_MASK;
    ssi->stccr |= SSI_SRCCR_DC(slots - 1);

    return 0;
}

/*!
 * Now the I2S is supported only. 
 * Although some register will be set automaticly if I2S mode is set, the function will set them manualy.
 *
 * @param   module      pointer to the ssi module structure
 *	    fmt		the fmt to be set
 * @return  false if failed
 *	    true if succeed
*/
static int ssi_set_fmt(audio_ctrl_p ctrl, uint32_t fmt)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    switch (fmt & SSI_FMT_FORMAT_MASK) {
    case SSI_FMT_FORMAT_NORMAL:
    case SSI_FMT_FORMAT_NETWORK:
    case SSI_FMT_FORMAT_AC97:
        //TODO 
        break;
    case SSI_FMT_FORMAT_I2S:
        //Transmit frame sync is one-clock-bit long | Transmit Early Frame Sync | Transmit Bit 0
        ssi->stcr |= SSI_STCR_TFSI | SSI_STCR_TEFS | SSI_STCR_TXBIT0;
        ssi->srcr |= SSI_SRCR_RFSI | SSI_SRCR_REFS | SSI_SRCR_RXBIT0;
        break;
    default:
        return -2;
    }

    switch (fmt & SSI_FMT_INV_MASK) {
    case SSI_FMT_INV_NB_NF:
        ssi->stcr &= ~(SSI_STCR_TSCKP | SSI_STCR_TFSI);
        ssi->srcr &= ~(SSI_SRCR_RSCKP | SSI_SRCR_RFSI);
        break;
    case SSI_FMT_INV_NB_IF:
        ssi->stcr |= SSI_STCR_TFSI;
        ssi->stcr &= ~SSI_STCR_TSCKP;
        ssi->srcr |= SSI_SRCR_RFSI;
        ssi->srcr &= ~SSI_SRCR_RSCKP;
        break;
    case SSI_FMT_INV_IB_NF:
        ssi->stcr &= ~SSI_STCR_TFSI;
        ssi->stcr |= SSI_STCR_TSCKP;
        ssi->srcr &= ~SSI_SRCR_RFSI;
        ssi->srcr |= SSI_SRCR_RSCKP;
        break;
    case SSI_FMT_INV_IB_IF:
        ssi->stcr |= SSI_STCR_TFSI | SSI_STCR_TSCKP;
        ssi->srcr |= SSI_SRCR_RFSI | SSI_SRCR_RSCKP;
        break;
    default:
        return -3;
    }

    switch (fmt & SSI_FMT_MASTER_MASK) {
    case SSI_FMT_MASTER_YES:
        ssi->stcr |= SSI_STCR_TFDIR | SSI_STCR_TXDIR;
        if (SSI_FMT_FORMAT_I2S == (fmt & SSI_FMT_FORMAT_MASK)) {
            ssi->scr &= ~SSI_SCR_I2S_MODE_MASK;
            ssi->scr |= SSI_SCR_I2S_MODE_MSTR;
        }
        break;
    case SSI_FMT_MASTER_NO:
        ssi->stcr &= (~SSI_STCR_TFDIR) | (~SSI_STCR_TXDIR);
        if (SSI_FMT_FORMAT_I2S == (fmt & SSI_FMT_FORMAT_MASK)) {
            ssi->scr &= ~SSI_SCR_I2S_MODE_MASK;
            ssi->scr |= SSI_SCR_I2S_MODE_SLAVE;
        }
        break;
    default:
        return -4;
    }

    switch (fmt & SSI_FMT_SYNC_MASK) {
    case SSI_FMT_SYNC_YES:
        ssi->scr |= SSI_SCR_SYN;
        break;
    case SSI_FMT_SYNC_NO:
        ssi->scr &= SSI_SCR_SYN;
        break;

    default:
        return -5;
    }

    return 0;
}

static int ssi_hw_tx_params(audio_ctrl_p ctrl, uint32_t wl, bool two_ch_enable)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    ssi->stccr &= ~SSI_STCCR_WL_MASK;
    ssi->stccr |= SSI_STCCR_WL(wl);

    ssi->sier |= SSI_SIER_TDMAE | SSI_SIER_TIE | SSI_SIER_TUE0_EN;

    ssi->stcr |= SSI_STCR_TFEN0;
    if (two_ch_enable)
        ssi->stcr |= SSI_STCR_TFEN1;

    return 0;
}

static int ssi_hw_rx_params(audio_ctrl_p ctrl, uint32_t wl, bool two_ch_enable)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    ssi->srccr &= ~SSI_SRCCR_WL_MASK;
    ssi->srccr |= SSI_SRCCR_WL(wl);

    ssi->sier |= SSI_SIER_RDMAE | SSI_SIER_RIE | SSI_SIER_ROE0_EN;

    ssi->srcr |= SSI_SRCR_RFEN0;
    if (two_ch_enable)
        ssi->srcr |= SSI_SRCR_RFEN1;

    return 0;
}

////////////////////////////////////API functions////////////////////////////////////////
/*!
 * This function
 *	1> Put the SSI to default status.
 *	2> Do the prepare work, such as IOMUX, AUDMUC, ccm clk, external osc, etc
 * 	3> Init data struct the SSI needed.
 */
int ssi_init(audio_ctrl_p ctrl)
{
    return 0;
}

/*!
 * This function
 *	1> Disable the ssi, clk-off the tx and tfs clk
 *	2> Gate off ccm clk for ssi.	
 */
int ssi_deinit(audio_ctrl_p ctrl)
{
    return 0;
}

int ssi_config(audio_ctrl_p ctrl)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (ssi->scr & SSI_SCR_SSIEN)
        return -1;

    ssi->scr |= SSI_SCR_SSIEN;

    return 0;
}

int ssi_ioctl(audio_ctrl_p ctrl, uint32_t cmd)
{
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (!(ssi->scr & SSI_SCR_SSIEN))
        return -1;

    switch (cmd) {
    case SSI_CMD_START_PLAY:
        ssi->scr |= SSI_SCR_TE;
        break;
    case SSI_CMD_STOP_PLAY:
        ssi->scr &= ~SSI_SCR_TE;
        break;
    case SSI_CMD_START_REC:
        ssi->scr |= SSI_SCR_RE;
        break;
    case SSI_CMD_STOP_REC:
        ssi->scr &= ~SSI_SCR_RE;
        break;
    default:
        break;
    }

    return 0;
}

/*!
 * Write data to SSI tx fifo.
 *
 * @param   module      pointer to the ssi module structure
 *	    buf		buffer to be written to the ssi tx fifo
 *	    size 	size of the buf
 * @return  
 */
int ssi_write_fifo(audio_ctrl_p ctrl, uint8_t * buf, uint32_t byte2write, uint32_t byte_written)
{
    //TODO 
    uint32_t wl = 0;
    uint32_t i = 0;
    imx_ssi_regs_p ssi = (imx_ssi_regs_p) (ctrl->base_addr);

    if (!(ssi->scr & SSI_SCR_SSIEN) || !(ssi->scr & SSI_SCR_TE))
        return false;
#if 0
    wl = (ssi->stccr & SSI_STCCR_WL_MASK) >> SSI_STCCR_WL_SHT;
    wl = (wl + 1) * 2;
    if (wl == 8) {

    } else if (wl == 16) {

    } else if {

    }
#endif
    for (; i < byte2write; i += 2) {
        while (((ssi->sfcsr & 0xF00) >> 8) < 0x0E) ;
        ssi->stx0 = *((uint16_t *) (buf + i));
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////
static audio_dev_ops_t ssi_ops = {
	.init = ssi_init,
	.deinit = ssi_deinit,
	.config = ssi_config,
	.ioctl = ssi_ioctl,
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
