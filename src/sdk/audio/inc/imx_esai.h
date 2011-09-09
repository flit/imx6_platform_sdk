/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_ESAI_H__
#define __IMX_ESAI_H__

#define ESAI_ETDR_OFFSET           0x00
#define ESAI_ERDR_OFFSET           0x04
#define ESAI_ECR_OFFSET            0x08
#define ESAI_ESR_OFFSET            0x0c
#define ESAI_TFCR_OFFSET           0x10
#define ESAI_TFSR_OFFSET           0x14
#define ESAI_RFCR_OFFSET           0x18
#define ESAI_RFSR_OFFSET           0x1c
#define ESAI_TX0_OFFSET            0x80
#define ESAI_TX1_OFFSET            0x84
#define ESAI_TX2_OFFSET            0x88
#define ESAI_TX3_OFFSET            0x8c
#define ESAI_TX4_OFFSET            0x90
#define ESAI_TX5_OFFSET            0x94
#define ESAI_TSR_OFFSET            0x98
#define ESAI_RX0_OFFSET            0xA0
#define ESAI_RX1_OFFSET            0xA4
#define ESAI_RX2_OFFSET            0xA8
#define ESAI_RX3_OFFSET            0xAC
#define ESAI_SAISR_OFFSET          0xCC
#define ESAI_SAICR_OFFSET          0xD0
#define ESAI_TCR_OFFSET            0xD4
#define ESAI_TCCR_OFFSET           0xD8
#define ESAI_RCR_OFFSET            0xDC
#define ESAI_RCCR_OFFSET           0xE0
#define ESAI_TSMA_OFFSET           0xE4
#define ESAI_TSMB_OFFSET           0xE8
#define ESAI_RSMA_OFFSET           0xEC
#define ESAI_RSMB_OFFSET           0xF0
#define ESAI_PRRC_OFFSET           0xF8
#define ESAI_PCRC_OFFSET           0xFC

typedef struct {
    volatile uint32_t etdr;     // 0x00
    volatile uint32_t erdr;     // 0x04 
    volatile uint32_t ecr;      // 0x08     
    volatile uint32_t esr;      // 0x0c     
    volatile uint32_t tfcr;     // 0x10     
    volatile uint32_t tfsr;     // 0x14     
    volatile uint32_t rfcr;     // 0x18     
    volatile uint32_t rfsr;     // 0x1c
    volatile uint32_t rsvd1[24];
    volatile uint32_t tx0;      // 0x80     
    volatile uint32_t tx1;      // 0x84     
    volatile uint32_t tx2;      // 0x88     
    volatile uint32_t tx3;      // 0x8c     
    volatile uint32_t tx4;      // 0x90     
    volatile uint32_t tx5;      // 0x94     
    volatile uint32_t tsr;      // 0x98     
    volatile uint32_t rsvd2[1];
    volatile uint32_t rx0;      // 0xA0     
    volatile uint32_t rx1;      // 0xA4     
    volatile uint32_t rx2;      // 0xA8     
    volatile uint32_t rx3;      // 0xAC     
    volatile uint32_t rsvd3[7];
    volatile uint32_t saisr;    // 0xCC     
    volatile uint32_t saicr;    // 0xD0     
    volatile uint32_t tcr;      // 0xD4     
    volatile uint32_t tccr;     // 0xD8     
    volatile uint32_t rcr;      // 0xDC     
    volatile uint32_t rccr;     // 0xE0     
    volatile uint32_t tsma;     // 0xE4     
    volatile uint32_t tsmb;     // 0xE8     
    volatile uint32_t rsma;     // 0xEC     
    volatile uint32_t rsmb;     // 0xF0     
    volatile uint32_t rsvd4;
    volatile uint32_t prrc;     // 0xF8     
    volatile uint32_t pcrc;     // 0xFC     
} imx_esai_regs_t, *imx_esai_regs_p;

/////////Field descriptons//////
#define ESAI_ECR_ETI	(1 << 19)
#define ESAI_ECR_ETO	(1 << 18)
#define ESAI_ECR_ERI	(1 << 17)
#define ESAI_ECR_ERO	(1 << 16)
#define ESAI_ECR_ERST	(1 << 1)
#define ESAI_ECR_ESAIEN	(1 << 0)

#define ESAI_ESR_TINIT	(1 << 10)
#define ESAI_ESR_RFF	(1 << 9)
#define ESAI_ESR_TFE	(1 << 8)
#define ESAI_ESR_TLS	(1 << 7)
#define ESAI_ESR_TDE	(1 << 6)
#define ESAI_ESR_TED	(1 << 5)
#define ESAI_ESR_TD	(1 << 4)
#define ESAI_ESR_RLS	(1 << 3)
#define ESAI_ESR_RDE	(1 << 2)
#define ESAI_ESR_RED	(1 << 1)
#define ESAI_ESR_RD	(1 << 0)

#define ESAI_TFCR_TIEN	(1 << 19)
#define ESAI_TFCR_TE5	(1 << 7)
#define ESAI_TFCR_TE4	(1 << 6)
#define ESAI_TFCR_TE3	(1 << 5)
#define ESAI_TFCR_TE2	(1 << 4)
#define ESAI_TFCR_TE1	(1 << 3)
#define ESAI_TFCR_TE0	(1 << 2)
#define ESAI_TFCR_TFR	(1 << 1)
#define ESAI_TFCR_TFEN	(1 << 0)
#define ESAI_TFCR_TE(x) ((0x3f >> (6 - (((x) + 1) >> 1))) << 2)
#define ESAI_TFCR_TE_MASK	0xfff03
#define ESAI_TFCR_TFWM(x)	(((x) - 1) << 8)
#define ESAI_TFCR_TWA_MASK	0xf8ffff

#define ESAI_RFCR_REXT	(1 << 19)
#define ESAI_RFCR_RE3	(1 << 5)
#define ESAI_RFCR_RE2	(1 << 4)
#define ESAI_RFCR_RE1	(1 << 3)
#define ESAI_RFCR_RE0	(1 << 2)
#define ESAI_RFCR_RFR	(1 << 1)
#define ESAI_RFCR_RFEN	(1 << 0)
#define ESAI_RFCR_RE(x) ((0xf >> (4 - (((x) + 1) >> 1))) << 2)
#define ESAI_RFCR_RE_MASK	0xfffc3
#define ESAI_RFCR_RFWM(x)       (((x)-1) << 8)
#define ESAI_RFCR_RWA_MASK	0xf8ffff

#define ESAI_WORD_LEN_32	(0x00 << 16)
#define ESAI_WORD_LEN_28	(0x01 << 16)
#define ESAI_WORD_LEN_24	(0x02 << 16)
#define ESAI_WORD_LEN_20	(0x03 << 16)
#define ESAI_WORD_LEN_16	(0x04 << 16)
#define ESAI_WORD_LEN_12	(0x05 << 16)
#define ESAI_WORD_LEN_8		(0x06 << 16)
#define ESAI_WORD_LEN_4		(0x07 << 16)
#define ESAI_WORD_LEN_MSK	(0x7 << 16)
#define ESAI_WORD_LEN_SHT	16

#define ESAI_SAISR_TODFE	(1 << 17)
#define ESAI_SAISR_TEDE	(1 << 16)
#define ESAI_SAISR_TDE	(1 << 15)
#define ESAI_SAISR_TUE	(1 << 14)
#define ESAI_SAISR_TFS	(1 << 13)
#define ESAI_SAISR_RODF	(1 << 10)
#define ESAI_SAISR_REDF	(1 << 9)
#define ESAI_SAISR_RDF	(1 << 8)
#define ESAI_SAISR_ROE	(1 << 7)
#define ESAI_SAISR_RFS	(1 << 6)
#define ESAI_SAISR_IF2	(1 << 2)
#define ESAI_SAISR_IF1	(1 << 1)
#define ESAI_SAISR_IF0	(1 << 0)

#define ESAI_SAICR_ALC	(1 << 8)
#define ESAI_SAICR_TEBE	(1 << 7)
#define ESAI_SAICR_SYNC	(1 << 6)
#define ESAI_SAICR_OF2	(1 << 2)
#define ESAI_SAICR_OF1	(1 << 1)
#define ESAI_SAICR_OF0	(1 << 0)

#define ESAI_TCR_TLIE	(1 << 23)
#define ESAI_TCR_TIE	(1 << 22)
#define ESAI_TCR_TEDIE	(1 << 21)
#define ESAI_TCR_TEIE	(1 << 20)
#define ESAI_TCR_TPR	(1 << 19)
#define ESAI_TCR_PADC	(1 << 17)
#define ESAI_TCR_TFSR	(1 << 16)
#define ESAI_TCR_TFSL	(1 << 15)
#define ESAI_TCR_TWA	(1 << 7)
#define ESAI_TCR_TSHFD_MSB	(0 << 6)
#define ESAI_TCR_TSHFD_LSB	(1 << 6)
#define ESAI_TCR_TE_MSK	(0x3F << 0)
#define ESAI_TCR_TE5	(1 << 5)
#define ESAI_TCR_TE4	(1 << 4)
#define ESAI_TCR_TE3	(1 << 3)
#define ESAI_TCR_TE2	(1 << 2)
#define ESAI_TCR_TE1	(1 << 1)
#define ESAI_TCR_TE0	(1 << 0)
#define ESAI_TCR_TE(x) (0x3f >> (6 - (((x) + 1) >> 1)))

#define ESAI_TCR_TMODE_MSK	(0x3 << 8)
#define ESAI_TCR_TMODE_SHIFT	8
#define ESAI_TCR_TSWS_MASK	0xff83ff
#define ESAI_TCR_TSWS_STL8_WDL8	(0x00 << 10)
#define ESAI_TCR_TSWS_STL12_WDL8	(0x04 << 10)
#define ESAI_TCR_TSWS_STL12_WDL12	(0x01 << 10)
#define ESAI_TCR_TSWS_STL16_WDL8	(0x08 << 10)
#define ESAI_TCR_TSWS_STL16_WDL12	(0x05 << 10)
#define ESAI_TCR_TSWS_STL16_WDL16	(0x02 << 10)
#define ESAI_TCR_TSWS_STL20_WDL8	(0x0c << 10)
#define ESAI_TCR_TSWS_STL20_WDL12	(0x09 << 10)
#define ESAI_TCR_TSWS_STL20_WDL16	(0x06 << 10)
#define ESAI_TCR_TSWS_STL20_WDL20	(0x03 << 10)
#define ESAI_TCR_TSWS_STL24_WDL8	(0x10 << 10)
#define ESAI_TCR_TSWS_STL24_WDL12	(0x0d << 10)
#define ESAI_TCR_TSWS_STL24_WDL16	(0x0a << 10)
#define ESAI_TCR_TSWS_STL24_WDL20	(0x07 << 10)
#define ESAI_TCR_TSWS_STL24_WDL24	(0x1e << 10)
#define ESAI_TCR_TSWS_STL32_WDL8	(0x18 << 10)
#define ESAI_TCR_TSWS_STL32_WDL12	(0x15 << 10)
#define ESAI_TCR_TSWS_STL32_WDL16	(0x12 << 10)
#define ESAI_TCR_TSWS_STL32_WDL20	(0x0f << 10)
#define ESAI_TCR_TSWS_STL32_WDL24	(0x1f << 10)

#define ESAI_TCR_TMOD_MASK	0xfffcff
#define ESAI_TCR_TMOD_NORMAL	(0x00 << 8)
#define ESAI_TCR_TMOD_ONDEMAND	(0x01 << 8)
#define ESAI_TCR_TMOD_NETWORK	(0x01 << 8)
#define ESAI_TCR_TMOD_RESERVED (0x02 << 8)
#define ESAI_TCR_TMOD_AC97	(0x03 << 8)

#define ESAI_TCCR_THCKD	(1 << 23)
#define ESAI_TCCR_TFSD	(1 << 22)
#define ESAI_TCCR_TCKD	(1 << 21)
#define ESAI_TCCR_THCKP	(1 << 20)
#define ESAI_TCCR_TFSP	(1 << 19)
#define ESAI_TCCR_TCKP	(1 << 18)

#define ESAI_TCCR_TPSR_MASK 0xfffeff
#define ESAI_TCCR_TPSR_BYPASS (1 << 8)
#define ESAI_TCCR_TPSR_DIV8 (0 << 8)

#define ESAI_TCCR_TFP_MASK	0xfc3fff
#define ESAI_TCCR_TFP(x)	((x & 0xf) << 14)

#define ESAI_TCCR_TDC_MASK	0xffc1ff
#define ESAI_TCCR_TDC(x)	(((x) & 0x1f) << 9)

#define ESAI_TCCR_TPM_MASK	0xffff00
#define ESAI_TCCR_TPM(x)	(x & 0xff)

#define ESAI_RCR_RLIE	(1 << 23)
#define ESAI_RCR_RIE	(1 << 22)
#define ESAI_RCR_REDIE	(1 << 21)
#define ESAI_RCR_REIE	(1 << 20)
#define ESAI_RCR_RPR	(1 << 19)
#define ESAI_RCR_RFSR	(1 << 16)
#define ESAI_RCR_RFSL	(1 << 15)
#define ESAI_RCR_RWA	(1 << 7)
#define ESAI_RCR_RSHFD_MSB (0 << 6)
#define ESAI_RCR_RSHFD_LSB (1 << 6)
#define ESAI_RCR_RE_MSK	(0xF << 0)
#define ESAI_RCR_RE3	(1 << 3)
#define ESAI_RCR_RE2	(1 << 2)
#define ESAI_RCR_RE1	(1 << 1)
#define ESAI_RCR_RE0	(1 << 0)
#define ESAI_RCR_RE(x) (0xf >> (4 - ((x + 1) >> 1)))

#define ESAI_RCR_RSWS_MASK	0xff83ff
#define ESAI_RCR_RSWS_STL8_WDL8	(0x00 << 10)
#define ESAI_RCR_RSWS_STL12_WDL8	(0x04 << 10)
#define ESAI_RCR_RSWS_STL12_WDL12	(0x01 << 10)
#define ESAI_RCR_RSWS_STL16_WDL8	(0x08 << 10)
#define ESAI_RCR_RSWS_STL16_WDL12	(0x05 << 10)
#define ESAI_RCR_RSWS_STL16_WDL16	(0x02 << 10)
#define ESAI_RCR_RSWS_STL20_WDL8	(0x0c << 10)
#define ESAI_RCR_RSWS_STL20_WDL12	(0x09 << 10)
#define ESAI_RCR_RSWS_STL20_WDL16	(0x06 << 10)
#define ESAI_RCR_RSWS_STL20_WDL20	(0x03 << 10)
#define ESAI_RCR_RSWS_STL24_WDL8	(0x10 << 10)
#define ESAI_RCR_RSWS_STL24_WDL12	(0x0d << 10)
#define ESAI_RCR_RSWS_STL24_WDL16	(0x0a << 10)
#define ESAI_RCR_RSWS_STL24_WDL20	(0x07 << 10)
#define ESAI_RCR_RSWS_STL24_WDL24	(0x1e << 10)
#define ESAI_RCR_RSWS_STL32_WDL8	(0x18 << 10)
#define ESAI_RCR_RSWS_STL32_WDL12	(0x15 << 10)
#define ESAI_RCR_RSWS_STL32_WDL16	(0x12 << 10)
#define ESAI_RCR_RSWS_STL32_WDL20	(0x0f << 10)
#define ESAI_RCR_RSWS_STL32_WDL24	(0x1f << 10)

#define ESAI_RCR_RMOD_MASK	0xfffcff
#define ESAI_RCR_RMOD_NORMAL	(0x00 << 8)
#define ESAI_RCR_RMOD_ONDEMAND	(0x01 << 8)
#define ESAI_RCR_RMOD_NETWORK	(0x01 << 8)
#define ESAI_RCR_RMOD_RESERVED (0x02 << 8)
#define ESAI_RCR_RMOD_AC97	(0x03 << 8)

#define ESAI_RCCR_RHCKD	(1 << 23)
#define ESAI_RCCR_RFSD	(1 << 22)
#define ESAI_RCCR_RCKD	(1 << 21)
#define ESAI_RCCR_RHCKP	(1 << 20)
#define ESAI_RCCR_RFSP	(1 << 19)
#define ESAI_RCCR_RCKP	(1 << 18)

#define ESAI_RCCR_RPSR_MASK 0xfffeff
#define ESAI_RCCR_RPSR_BYPASS (1 << 8)
#define ESAI_RCCR_RPSR_DIV8 (0 << 8)

#define ESAI_RCCR_RFP_MASK	0xfc3fff
#define ESAI_RCCR_RFP(x)	((x & 0xf) << 14)

#define ESAI_RCCR_RDC_MASK	0xffc1ff
#define ESAI_RCCR_RDC(x)	(((x) & 0x1f) << 9)

#define ESAI_RCCR_RPM_MASK	0xffff00
#define ESAI_RCCR_RPM(x)	(x & 0xff)

#define ESAI_TSM_NUM(x)  (0xffffffff >> (32-x))

#define ESAI_GPIO_ESAI		0xfff

#define ESAI_WATERMARK 		64
/////////////////////////////////
typedef enum {
    ESAI_HW_PARA_ECR,
    ESAI_HW_PARA_TCR,
    ESAI_HW_PARA_RCR,
    ESAI_HW_PARA_TCCR,
    ESAI_HW_PARA_RCCR,
    ESAI_HW_PARA_TFCR,
    ESAI_HW_PARA_RFCR,
    ESAI_HW_PARA_TSR,
    ESAI_HW_PARA_SAICR,
    ESAI_HW_PARA_TSM,           //time slot mask
    ESAI_HW_PARA_RSM,           //time slot mask
    ESAI_HW_PARA_TX_WL,         //word len in bits
    ESAI_HW_PARA_RX_WL,         //word len in bits
} esai_hw_para_type_e;

typedef enum {
    ESAI_STATUS_ESR,
    ESAI_STATUS_TFSR,
    ESAI_STATUS_RFSR,
    ESAI_STATUS_SAISR,
} esai_status_e;

typedef enum {
    ESAI_SUB_ENABLE_TYPE_ESAI,
    ESAI_SUB_ENABLE_TYPE_TX,
    ESAI_SUB_ENABLE_TYPE_RX,
    ESAI_SUB_ENABLE_TYPE_TXFIFO,
    ESAI_SUB_ENABLE_TYPE_RXFIFO,
} esai_sub_enable_type_e;

#endif
