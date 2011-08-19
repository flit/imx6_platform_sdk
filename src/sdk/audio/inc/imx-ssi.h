/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx-ssi.h
 * @brief MACRO and struct definitions.
 *
 */

#ifndef _IMX_SSI_H_
#define _IMX_SSI_H_

#define SSI_STX0_OFFSET   		0x00
#define SSI_STX1_OFFSET   		0x04
#define SSI_SRX0_OFFSET   		0x08
#define SSI_SRX1_OFFSET   		0x0c
#define SSI_SCR_OFFSET    		0x10
#define SSI_SISR_OFFSET   		0x14
#define SSI_SIER_OFFSET   		0x18
#define SSI_STCR_OFFSET   		0x1c
#define SSI_SRCR_OFFSET   		0x20
#define SSI_STCCR_OFFSET  		0x24
#define SSI_SRCCR_OFFSET  		0x28
#define SSI_SFCSR_OFFSET  		0x2c
#define SSI_STR_OFFSET    		0x30
#define SSI_SOR_OFFSET    		0x34
#define SSI_SACNT_OFFSET  		0x38
#define SSI_SACADD_OFFSET 		0x3c
#define SSI_SACDAT_OFFSET 		0x40
#define SSI_SATAG_OFFSET  		0x44
#define SSI_STMSK_OFFSET  		0x48
#define SSI_SRMSK_OFFSET  		0x4c
#define SSI_SACCST_OFFSET 		0x50
#define SSI_SACCEN_OFFSET 		0x54
#define SSI_SACCDIS_OFFSET		0x58

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

/////////////////////BITs definition///////////////////////////////
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
#define SSI_SCR_I2S_MODE_MASK  (3 << 5)

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

#define SSI_STCCR_DIV2_MASK         (1 << 18)
#define SSI_STCCR_PSR_MASK          (1 << 15)
#define SSI_STCCR_DIV2(x)	((x & 0x01) << 18)
#define SSI_STCCR_PSR(x)	((x & 0x01) << 15)
#define SSI_STCCR_WL(x)        ((((x) - 2) >> 1) << 13)
#define SSI_STCCR_DC(x)        (((x) & 0x1f) << 8)
#define SSI_STCCR_PM(x)        (((x) & 0xff) << 0)
#define SSI_STCCR_WL_MASK        (0xf << 13)
#define SSI_STCCR_DC_MASK        (0x1f << 8)
#define SSI_STCCR_PM_MASK        (0xff << 0)
#define SSI_STCCR_WL_SHT	13

#define SSI_SRCCR_DIV2_MASK         (1 << 18)
#define SSI_SRCCR_PSR_MASK          (1 << 15)
#define SSI_SRCCR_DIV2(x)	((x & 0x01) << 18)
#define SSI_SRCCR_PSR(x)	((x & 0x01) << 15)
#define SSI_SRCCR_WL(x)        ((((x) - 2) >> 1) << 13)
#define SSI_SRCCR_DC(x)        (((x) & 0x1f) << 8)
#define SSI_SRCCR_PM(x)        (((x) & 0xff) << 0)
#define SSI_SRCCR_WL_MASK        (0xf << 13)
#define SSI_SRCCR_DC_MASK        (0x1f << 8)
#define SSI_SRCCR_PM_MASK        (0xff << 0)

#define SSI_SFCSR_RFCNT1(x)   (((x) & 0xf) << 28)
#define SSI_SFCSR_TFCNT1(x)   (((x) & 0xf) << 24)
#define SSI_SFCSR_RFWM1(x)    (((x) & 0xf) << 20)
#define SSI_SFCSR_TFWM1(x)    (((x) & 0xf) << 16)
#define SSI_SFCSR_RFCNT0(x)   (((x) & 0xf) << 12)
#define SSI_SFCSR_TFCNT0(x)   (((x) & 0xf) <<  8)
#define SSI_SFCSR_RFWM0(x)    (((x) & 0xf) <<  4)
#define SSI_SFCSR_TFWM0(x)    (((x) & 0xf) <<  0)

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
#define SSI_SACNT_WR          (1 << 4)
#define SSI_SACNT_RD          (1 << 3)
#define SSI_SACNT_TIF         (1 << 2)
#define SSI_SACNT_FV          (1 << 1)
#define SSI_SACNT_AC97EN      (1 << 0)

/* SDMA & SSI watermarks for FIFO's */
#define SDMA_TXFIFO_WATERMARK		0x4
#define SDMA_RXFIFO_WATERMARK		0x6
#define SSI_TXFIFO_WATERMARK		0x4
#define SSI_RXFIFO_WATERMARK		0x6

/* Maximum number of ssi channels (counting two channels per block) */
#define MAX_SSI_CHANNELS		12

/* i.MX DAI SSP ID's */
#define IMX_DAI_SSI0			0   /* SSI1 FIFO 0 */
#define IMX_DAI_SSI1			1   /* SSI1 FIFO 1 */
#define IMX_DAI_SSI2			2   /* SSI2 FIFO 0 */
#define IMX_DAI_SSI3			3   /* SSI2 FIFO 1 */
#define IMX_DAI_SSI4			4   /* SSI3 FIFO 0 */
#define IMX_DAI_SSI5			5   /* SSI3 FIFO 1 */

/* SSI clock sources */
#define IMX_SSP_SYS_CLK			0

/* SSI audio dividers */
#define IMX_SSI_TX_DIV_2		0
#define IMX_SSI_TX_DIV_PSR		1
#define IMX_SSI_TX_DIV_PM		2
#define IMX_SSI_RX_DIV_2		3
#define IMX_SSI_RX_DIV_PSR		4
#define IMX_SSI_RX_DIV_PM		5

/* SSI Div 2 */
#define IMX_SSI_DIV_2_OFF		(~SSI_STCCR_DIV2)
#define IMX_SSI_DIV_2_ON		SSI_STCCR_DIV2

#define IMX_DAI_AC97_1 0
#define IMX_DAI_AC97_2 1

#define SSI_FMT_FORMAT_MASK		(0xff << 0)
#define SSI_FMT_INV_MASK		(0xff << 8)
#define SSI_FMT_MASTER_MASK		(0xff << 16)
#define SSI_FMT_SYNC_MASK		(0xff << 24)
#define SSI_FMT_FORMAT_NORMAL		0x00
#define SSI_FMT_FORMAT_NETWORK		0x01
#define SSI_FMT_FORMAT_I2S		0x02
#define SSI_FMT_FORMAT_AC97		0x03
#define SSI_FMT_INV_NB_NF		(0x00 <<8)  /* normal bit clock + frame */
#define SSI_FMT_INV_NB_IF            	(0x01 << 8) /* normal BCLK + inv FRM */
#define SSI_FMT_INV_IB_NF            	(0x02 << 8) /* invert BCLK + nor FRM */
#define SSI_FMT_INV_IB_IF               (0x03 << 8) /* invert BCLK + FRM */
#define SSI_FMT_MASTER_YES		(0x00<<16)
#define SSI_FMT_MASTER_NO		(0x01<<16)
#define SSI_FMT_SYNC_YES		(0x00 << 24)
#define SSI_FMT_SYNC_NO			(0x01 << 24)

#define SSI_CLK_ID_TX		0
#define SSI_CLK_ID_RX		1

#define SSI_CMD_START_PLAY	0
#define SSI_CMD_STOP_PLAY	1
#define SSI_CMD_START_REC	2
#define SSI_CMD_STOP_REC	3

struct imx_ssi_priv {
    bool network_mode;
    bool sync_mode;
    unsigned long baseaddr;
    unsigned int int_port;      //internal port number of AUDMUX
    unsigned int ext_port;      //external port number of AUDMUX
    unsigned int ac97_tx_slots; //Will be used for AC97 mode only
    unsigned int ac97_rx_slots;
    int irq;
    int sdma_ch;                //Will be used for SDMA
};

#endif
