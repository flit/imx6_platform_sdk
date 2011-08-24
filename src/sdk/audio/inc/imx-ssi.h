/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __SSI_H__
#define __SSI_H__

#include "functions.h"
#include "io.h"
#include "hardware.h"

/* audmux  reg*/
#define AUDMUX_PTCR1 (AUDMUX_BASE_ADDR + 0x00)
#define AUDMUX_PDCR1 (AUDMUX_BASE_ADDR + 0x04)
#define AUDMUX_PTCR2 (AUDMUX_BASE_ADDR + 0x08)
#define AUDMUX_PDCR2 (AUDMUX_BASE_ADDR + 0x0c)
#define AUDMUX_PTCR3 (AUDMUX_BASE_ADDR + 0x10)
#define AUDMUX_PDCR3 (AUDMUX_BASE_ADDR + 0x14)
#define AUDMUX_PTCR5 (AUDMUX_BASE_ADDR + 0x20)
#define AUDMUX_PDCR5 (AUDMUX_BASE_ADDR + 0x24)

#define PCM_STREAM_PLAYBACK 1

#define	PCM_FORMAT_S16_LE	2
#define	PCM_FORMAT_S20_3LE	36  /* in three bytes */
#define	PCM_FORMAT_S24_LE	6   /* low three bytes */

/*
 * DAI hardware signal inversions
 */
#define SND_SOC_DAIFMT_NB_NF		(0 << 8)    /* normal bit clock + frame */
#define SND_SOC_DAIFMT_NB_IF		(1 << 8)    /* normal bclk + inv frm */
#define SND_SOC_DAIFMT_IB_NF		(2 << 8)    /* invert bclk + nor frm */
#define SND_SOC_DAIFMT_IB_IF		(3 << 8)    /* invert bclk + frm */

/*
 * DAI hardware clock masters
 * This is wrt the codec, the inverse is true for the interface
 * i.e. if the codec is clk and frm master then the interface is
 * clk and frame slave.
 */
#define SND_SOC_DAIFMT_CBM_CFM	(0 << 12)   /* codec clk & frm master */
#define SND_SOC_DAIFMT_CBS_CFM	(1 << 12)   /* codec clk slave & frm master */
#define SND_SOC_DAIFMT_CBM_CFS	(2 << 12)   /* codec clk master & frame slave */
#define SND_SOC_DAIFMT_CBS_CFS	(3 << 12)   /* codec clk & frm slave */

/*
 * DAI Sync
 * Synchronous LR (Left Right) clocks and Frame signals.
 */
#define SND_SOC_DAIFMT_SYNC		(0 << 5)    /* Tx FRM = Rx FRM */
#define SND_SOC_DAIFMT_ASYNC		(1 << 5)    /* Tx FRM ~ Rx FRM */

/*
 * TDM
 */
#define SND_SOC_DAIFMT_TDM		(1 << 6)

/*
 * Master Clock Directions
 */
#define SND_SOC_CLOCK_IN	0
#define SND_SOC_CLOCK_OUT	1

/*
 * Digital Audio Interface (DAI)
 * DAI hardware audio formats
 */
#define SND_SOC_DAIFMT_I2S		0   /* I2S mode */
#define SND_SOC_DAIFMT_RIGHT_J	1   /* Right justified mode */
#define SND_SOC_DAIFMT_LEFT_J	2   /* Left Justified mode */
#define SND_SOC_DAIFMT_DSP_A	3   /* L data msb after FRM or LRC */
#define SND_SOC_DAIFMT_DSP_B	4   /* L data msb during FRM or LRC */
#define SND_SOC_DAIFMT_AC97		5   /* AC97 */

#define SND_SOC_DAIFMT_FORMAT_MASK		0x000f
#define SND_SOC_DAIFMT_CLOCK_MASK		0x00f0
#define SND_SOC_DAIFMT_INV_MASK			0x0f00
#define SND_SOC_DAIFMT_MASTER_MASK		0xf000

#define PCM_TRIGGER_STOP		0
#define PCM_TRIGGER_START		1
#define PCM_TRIGGER_PAUSE_PUSH	3
#define PCM_TRIGGER_PAUSE_RELEASE	4
#define PCM_TRIGGER_SUSPEND	5
#define PCM_TRIGGER_RESUME	6

#define SSI_SFCSR_TX_WATERMARK      4   // Default 4
#define SSI_SFCSR_RX_WATERMARK      4   // Default 4

#define SSI_SCR_CLK_IST        (1 << 9)
#define SSI_SCR_TCH_EN         (1 << 8)
#define SSI_SCR_SYS_CLK_EN     (1 << 7)
#define SSI_SCR_I2S_MODE_NORM  (0 << 5)
#define SSI_SCR_I2S_MODE_MSTR  (1 << 5)
#define SSI_SCR_I2S_MODE_SLAVE (2 << 5)
#define SSI_SCR_SYN            (1 << 4)
#define SSI_SCR_NET            (1 << 3)
#define SSI_SCR_RE             (1 << 2)
#define SSI_SCR_TE             (1 << 1)
#define SSI_SCR_SSIEN          (1 << 0)

#define SSI_SISR_CMDAU         (1 << 18)
#define SSI_SISR_CMDDU         (1 << 17)
#define SSI_SISR_RXT           (1 << 16)
#define SSI_SISR_RDR1          (1 << 15)
#define SSI_SISR_RDR0          (1 << 14)
#define SSI_SISR_TDE1          (1 << 13)
#define SSI_SISR_TDE0          (1 << 12)
#define SSI_SISR_ROE1          (1 << 11)
#define SSI_SISR_ROE0          (1 << 10)
#define SSI_SISR_TUE1          (1 << 9)
#define SSI_SISR_TUE0          (1 << 8)
#define SSI_SISR_TFS           (1 << 7)
#define SSI_SISR_RFS           (1 << 6)
#define SSI_SISR_TLS           (1 << 5)
#define SSI_SISR_RLS           (1 << 4)
#define SSI_SISR_RFF1          (1 << 3)
#define SSI_SISR_RFF0          (1 << 2)
#define SSI_SISR_TFE1          (1 << 1)
#define SSI_SISR_TFE0          (1 << 0)

#define SSI_SIER_RDMAE         (1 << 22)
#define SSI_SIER_RIE           (1 << 21)
#define SSI_SIER_TDMAE         (1 << 20)
#define SSI_SIER_TIE           (1 << 19)
#define SSI_SIER_CMDAU_EN      (1 << 18)
#define SSI_SIER_CMDDU_EN      (1 << 17)
#define SSI_SIER_RXT_EN        (1 << 16)
#define SSI_SIER_RDR1_EN       (1 << 15)
#define SSI_SIER_RDR0_EN       (1 << 14)
#define SSI_SIER_TDE1_EN       (1 << 13)
#define SSI_SIER_TDE0_EN       (1 << 12)
#define SSI_SIER_ROE1_EN       (1 << 11)
#define SSI_SIER_ROE0_EN       (1 << 10)
#define SSI_SIER_TUE1_EN       (1 << 9)
#define SSI_SIER_TUE0_EN       (1 << 8)
#define SSI_SIER_TFS_EN        (1 << 7)
#define SSI_SIER_RFS_EN        (1 << 6)
#define SSI_SIER_TLS_EN        (1 << 5)
#define SSI_SIER_RLS_EN        (1 << 4)
#define SSI_SIER_RFF1_EN       (1 << 3)
#define SSI_SIER_RFF0_EN       (1 << 2)
#define SSI_SIER_TFE1_EN       (1 << 1)
#define SSI_SIER_TFE0_EN       (1 << 0)

#define SSI_STCR_TXBIT0        (1 << 9)
#define SSI_STCR_TFEN1         (1 << 8)
#define SSI_STCR_TFEN0         (1 << 7)
#define SSI_STCR_TFDIR         (1 << 6)
#define SSI_STCR_TXDIR         (1 << 5)
#define SSI_STCR_TSHFD         (1 << 4)
#define SSI_STCR_TSCKP         (1 << 3)
#define SSI_STCR_TFSI          (1 << 2)
#define SSI_STCR_TFSL          (1 << 1)
#define SSI_STCR_TEFS          (1 << 0)

#define SSI_SRCR_RXBIT0        (1 << 9)
#define SSI_SRCR_RFEN1         (1 << 8)
#define SSI_SRCR_RFEN0         (1 << 7)
#define SSI_SRCR_RFDIR         (1 << 6)
#define SSI_SRCR_RXDIR         (1 << 5)
#define SSI_SRCR_RSHFD         (1 << 4)
#define SSI_SRCR_RSCKP         (1 << 3)
#define SSI_SRCR_RFSI          (1 << 2)
#define SSI_SRCR_RFSL          (1 << 1)
#define SSI_SRCR_REFS          (1 << 0)

#define SSI_STCCR_DIV2         (1 << 18)
#define SSI_STCCR_PSR          (1 << 15)
#define SSI_STCCR_WL(x)        (((x >>1)-1 ) << 13)
#define SSI_STCCR_DC(x)        (((x) & 0x1f) << 8)
#define SSI_STCCR_PM(x)        (((x) & 0xff) << 0)
#define SSI_STCCR_WL_MASK        (0xf << 13)
#define SSI_STCCR_DC_MASK        (0x1f << 8)
#define SSI_STCCR_PM_MASK        (0xff << 0)
#define SSI_STCCR_WL_SHIFT	13
#define SSI_STCCR_DC_SHIFT	8
#define SSI_STCCR_PM_SHIFT	0

#define SSI_SRCCR_DIV2         (1 << 18)
#define SSI_SRCCR_PSR          (1 << 15)
#define SSI_SRCCR_WL(x)        ((((x) - 2) >> 1) << 13)
#define SSI_SRCCR_DC(x)        (((x) & 0x1f) << 8)
#define SSI_SRCCR_PM(x)        (((x) & 0xff) << 0)
#define SSI_SRCCR_WL_MASK        (0xf << 13)
#define SSI_SRCCR_DC_MASK        (0x1f << 8)
#define SSI_SRCCR_PM_MASK        (0xff << 0)
#define SSI_SRCCR_WL_SHIFT	13
#define SSI_SRCCR_DC_SHIFT	8
#define SSI_SRCCR_PM_SHIFT	0

#define SSI_SFCSR_RFCNT1(x)   (((x) & 0xf) << 28)
#define SSI_SFCSR_TFCNT1(x)   (((x) & 0xf) << 24)
#define SSI_SFCSR_RFWM1(x)    (((x) & 0xf) << 20)
#define SSI_SFCSR_TFWM1(x)    (((x) & 0xf) << 16)
#define SSI_SFCSR_RFCNT0(x)   (((x) & 0xf) << 12)
#define SSI_SFCSR_TFCNT0(x)   (((x) & 0xf) <<  8)
#define SSI_SFCSR_RFWM0(x)    (((x) & 0xf) <<  4)
#define SSI_SFCSR_TFWM0(x)    (((x) & 0xf) <<  0)
#define SSI_SFCSR_RFCNT1_SHIFT	28
#define SSI_SFCSR_TFCNT1_SHIFT	24
#define SSI_SFCSR_RFWM1_SHIFT	20
#define SSI_SFCSR_TFWM1_SHIFT	16
#define SSI_SFCSR_RFCNT0_SHIFT	12
#define SSI_SFCSR_TFCNT0_SHIFT	8
#define SSI_SFCSR_RFWM0_SHIFT	4
#define SSI_SFCSR_TFWM0_SHIFT	0
#define SSI_SFCSR_RFCNT1_MASK	(0xf << 28)
#define SSI_SFCSR_TFCNT1_MASK	(0xf << 24)
#define SSI_SFCSR_RFWM1_MASK    (0xf << 20)
#define SSI_SFCSR_TFWM1_MASK	(0xf << 16)
#define SSI_SFCSR_RFCNT0_MASK	(0xf << 12)
#define SSI_SFCSR_TFCNT0_MASK	(0xf <<  8)
#define SSI_SFCSR_RFWM0_MASK	(0xf <<  4)
#define SSI_SFCSR_TFWM0_MASK	(0xf <<  0)

#define SSI_STR_TEST          (1 << 15)
#define SSI_STR_RCK2TCK       (1 << 14)
#define SSI_STR_RFS2TFS       (1 << 13)
#define SSI_STR_RXSTATE(x)    (((x) & 0xf) << 8)
#define SSI_STR_TXD2RXD       (1 <<  7)
#define SSI_STR_TCK2RCK       (1 <<  6)
#define SSI_STR_TFS2RFS       (1 <<  5)
#define SSI_STR_TXSTATE(x)    (((x) & 0xf) << 0)

#define SSI_SOR_CLKOFF        (1 << 6)
#define SSI_SOR_RX_CLR        (1 << 5)
#define SSI_SOR_TX_CLR        (1 << 4)
#define SSI_SOR_INIT          (1 << 3)
#define SSI_SOR_WAIT(x)       (((x) & 0x3) << 1)
#define SSI_SOR_SYNRST        (1 << 0)

#define SSI_SACNT_FRDIV(x)    (((x) & 0x3f) << 5)
#define SSI_SACNT_WR          (x << 4)
#define SSI_SACNT_RD          (x << 3)
#define SSI_SACNT_TIF         (x << 2)
#define SSI_SACNT_FV          (x << 1)
#define SSI_SACNT_AC97EN      (x << 0)

// STCCR
#define SSI_STCCR_WL_8BIT               0x3 // 8-bit data word
#define SSI_STCCR_WL_10BIT              0x4 // 10-bit data word
#define SSI_STCCR_WL_12BIT              0x5 // 12-bit data word
#define SSI_STCCR_WL_14BIT              0x6 // 14-bit data word
#define SSI_STCCR_WL_16BIT              0x7 // 16-bit data word
#define SSI_STCCR_WL_18BIT              0x8 // 18-bit data word
#define SSI_STCCR_WL_20BIT              0x9 // 20-bit data word
#define SSI_STCCR_WL_22BIT              0xA // 22-bit data word
#define SSI_STCCR_WL_24BIT              0xB // 24-bit data word
#define SSI_STCCR_PSR_DIV8_BYPASS       0   // Bypass /8 prescalar
#define SSI_STCCR_PSR_DIV8_ENABLE       1   // Use /8 prescalar
#define SSI_STCCR_DIV2_BYPASS           0   // Bypass /2 prescalar
#define SSI_STCCR_DIV2_ENABLE           1   // Use /2 prescalar

/* i.MX DAI SSP ID's */
#define IMX_DAI_SSI0			0   /* SSI1 FIFO 0 */
#define IMX_DAI_SSI1			1   /* SSI1 FIFO 1 */
#define IMX_DAI_SSI2			2   /* SSI2 FIFO 0 */
#define IMX_DAI_SSI3			3   /* SSI2 FIFO 1 */

/* SSI clock sources */
#define IMX_SSP_SYS_CLK		0

/* SSI audio dividers */
#define IMX_SSI_TX_DIV_2			0
#define IMX_SSI_TX_DIV_PSR			1
#define IMX_SSI_TX_DIV_PM			2
#define IMX_SSI_RX_DIV_2			3
#define IMX_SSI_RX_DIV_PSR			4
#define IMX_SSI_RX_DIV_PM			5

/* SSI Div 2 */
#define IMX_SSI_DIV_2_OFF		~SSI_STCCR_DIV2
#define IMX_SSI_DIV_2_ON		SSI_STCCR_DIV2

//#########################################
//# SSI peripheral defines
//#########################################
#define SSI_STX0_OFFSET		0x00    //  32bit SSI tx reg 0
#define SSI_STX1_OFFSET		0x04    //  32bit SSI tx reg 1
#define SSI_SRX0_OFFSET		0x08    //  32bit SSI rx reg 0
#define SSI_SRX1_OFFSET		0x0C    //  32bit SSI rx reg 1
#define SSI_SCR_OFFSET		0x10    //  32bit SSI control reg
#define SSI_SISR_OFFSET		0x14    //  32bit SSI intr status reg
#define SSI_SIER_OFFSET		0x18    //  32bit SSI intr enable reg
#define SSI_STCR_OFFSET		0x1C    //  32bit SSI tx config reg
#define SSI_SRCR_OFFSET		0x20    //  32bit SSI rx config reg
#define SSI_STCCR_OFFSET	0x24    //  32bit SSI tx clock control reg
#define SSI_SRCCR_OFFSET	0x28    //  32bit SSI rx clock control reg
#define SSI_SFCSR_OFFSET	0x2C    //  32bit SSI fifo control/status reg
#define SSI_STR_OFFSET		0x30    //  32bit SSI test reg
#define SSI_SOR_OFFSET		0x34    //  32bit SSI option reg
#define SSI_SACNT_OFFSET	0x38    //  32bit SSI ac97 control reg
#define SSI_SACADD_OFFSET	0x3C    //  32bit SSI ac97 cmd addr reg
#define SSI_SACDAT_OFFSET	0x40    //  32bit SSI ac97 cmd data reg
#define SSI_SATAG_OFFSET	0x44    //  32bit SSI ac97 tag reg
#define SSI_STMSK_OFFSET	0x48    //  32bit SSI tx time slot mask reg
#define SSI_SRMSK_OFFSET	0x4C    //  32bit SSI rx time slot mask reg
#define SSI_SACCST_OFFSET	0x50
#define SSI_SACCEN_OFFSET	0x54
#define SSI_SACCDIS_OFFSET	0x58

#define SSI_SCR_RESET_VAL	0x00000000
#define SSI_SISR_RESET_VAL      0x00003003
#define SSI_SIER_RESET_VAL      0x00003003
#define SSI_STCR_RESET_VAL      0x00000200
#define SSI_SRCR_RESET_VAL      0x00000200
#define SSI_STCCR_RESET_VAL	0x00040000
#define SSI_SRCCR_RESET_VAL	0x00040000
#define SSI_SFCSR_RESET_VAL	0x00810081
#define SSI_SACNT_RESET_VAL	0x00000000
#define SSI_SACADD_RESET_VAL	0x00000000
#define SSI_SACDAT_RESET_VAL	0x00000000
#define SSI_SATAG_RESET_VAL	0x00000000
#define SSI_STMSK_RESET_VAL	0x00000000
#define SSI_SRMSK_RESET_VAL	0x00000000
#define SSI_SACCST_RESET_VAL	0x00000000
#define SSI_SACCEN_RESET_VAL	0x00000000
#define SSI_SACCDIS_RESET_VAL	0x00000000

typedef struct {
    volatile uint32_t stx0;     //0x00
    volatile uint32_t stx1;     //0x04
    volatile uint32_t srx0;     //0x08
    volatile uint32_t srx1;     //0x0c
    volatile uint32_t scr;      //0x10
    volatile uint32_t sisr;     //0x14
    volatile uint32_t sier;     //0x18
    volatile uint32_t stcr;     //0x1c
    volatile uint32_t srcr;     //0x20
    volatile uint32_t stccr;    //0x24
    volatile uint32_t srccr;    //0x28
    volatile uint32_t sfcsr;    //0x2c
    volatile uint32_t str;      //0x30
    volatile uint32_t sor;      //0x34
    volatile uint32_t sacnt;    //0x38
    volatile uint32_t sacadd;   //0x3c
    volatile uint32_t sacdat;   //0x40
    volatile uint32_t satag;    //0x44
    volatile uint32_t stmsk;    //0x48
    volatile uint32_t srmsk;    //0x4c
    volatile uint32_t saccst;   //0x50
    volatile uint32_t saccen;   //0x54
    volatile uint32_t saccdis;  //0x58
} imx_ssi_regs_t, *imx_ssi_regs_p;

typedef enum {
    SSI_SETTING_TX_FIFO1_DATAS_CNT,
    SSI_SETTING_TX_FIFO2_DATAS_CNT,
    SSI_SETTING_RX_FIFO1_DATAS_CNT,
    SSI_SETTING_RX_FIFO2_DATAS_CNT,
    SSI_SETTING_TX_WATERMARK,
    SSI_SETTING_RX_WATERMARK,
    SSI_SETTING_TX_WORD_LEN,
    SSI_SETTING_RX_WORD_LEN,
    SSI_SETTING_TX_BIT_CLOCK,
    SSI_SETTING_RX_BIT_CLOCK,
    SSI_SETTING_TX_FRAME_LENGTH,
    SSI_SETTING_RX_FRAME_LENGTH,
    SSI_SETTING_CLK_FS_DIR,
} ssi_setting_type_e;

typedef enum {
    SSI_CLK_FS_DIR_OUTPUT,
    SSI_CLK_FS_DIR_INPUT,
} ssi_clk_fs_dir_e;

typedef enum {
    SSI_HW_ENABLE_SSI,
    SSI_HW_ENABLE_TX,
    SSI_HW_ENABLE_RX,
    SSI_HW_ENABLE_TXFIFO1,
    SSI_HW_ENABLE_TXFIFO2,
    SSI_HW_ENABLE_RXFIFO1,
    SSI_HW_ENABLE_RXFIFO2,
} ssi_hw_enable_type_e;

#endif
