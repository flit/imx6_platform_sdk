/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_SPI_H__
#define __IMX_SPI_H__

#undef IMX_SPI_DEBUG
//#define IMX_SPI_DEBUG

#define IMX_CSPI_VER_0_7

#define IMX_SPI_ACTIVE_HIGH     1
#define IMX_SPI_ACTIVE_LOW      0
#define SPI_RETRY_TIMES         100

// Only for SPI master support
struct imx_spi_dev {
    unsigned int base;          // base address of SPI module the device is connected to
    unsigned int freq;          // desired clock freq in Hz for this device
    unsigned int ss_pol;        // ss polarity: 1=active high; 0=active low
    unsigned int ss;            // slave select
    unsigned int in_sctl;       // inactive sclk ctl: 1=stay low; 0=stay high
    unsigned int in_dctl;       // inactive data ctl: 1=stay low; 0=stay high
    unsigned int ssctl;         // single burst mode vs multiple: 0=single; 1=multi
    unsigned int sclkpol;       // sclk polarity: active high=0; active low=1
    unsigned int sclkpha;       // sclk phase: 0=phase 0; 1=phase1
    unsigned int fifo_sz;       // fifo size in bytes for either tx or rx. Don't add them up!
    unsigned int us_delay;      // us delay in each xfer
    void *reg;                  // pointer to a set of SPI registers
};

struct spi_v2_3_reg {
    unsigned int ctrl_reg;
    unsigned int cfg_reg;
};

int imx_ecspi_init(struct imx_spi_dev *dev);

// transfer up to fifo bytes data via spi. The data transferred is the sum of both the tx and rx
int imx_ecspi_xfer(struct imx_spi_dev *dev, // spi device pointer
                   unsigned char *tx_buf,   // tx buffer (has to be 4-byte aligned)
                   unsigned char *rx_buf,   // rx buffer (has to be 4-byte aligned)
                   int burst_bits   // total number of bits in one burst (or xfer)
    );

//
int imx_cspi_init(struct imx_spi_dev *dev);

// transfer up to fifo bytes data via spi. The data transferred is the sum of both the tx and rx
int imx_cspi_xfer(struct imx_spi_dev *dev,  // spi device pointer
                  unsigned char *tx_buf,    // tx buffer (has to be 4-byte aligned)
                  unsigned char *rx_buf,    // rx buffer (has to be 4-byte aligned)
                  int burst_bits    // total number of bits in one burst (or xfer)
    );

typedef int (*imx_spi_init_func_t) (struct imx_spi_dev *);
typedef int (*imx_spi_xfer_func_t) (struct imx_spi_dev *, unsigned char *, unsigned char *, int);

void io_cfg_spi(struct imx_spi_dev *dev);

#if defined(IMX_CSPI_VER_0_4)
#define SPI_CTRL_EN                          (1 << 0)
#define SPI_CTRL_MODE                     (1 << 1)
#define SPI_CTRL_REG_XCH_BIT        (1 << 2)
#define SPI_CTRL_SSPOL                    (1 << 7)
#define SPI_CTRL_SSPOL_OFF            (7)
#define SPI_CTRL_SSCTL                    (1 << 6)
#define SPI_CTRL_SSCTL_OFF            (6)
#define SPI_CTRL_SCLK_POL              (1 << 4)
#define SPI_CTRL_SCLK_POL_OFF      (4)
#define SPI_CTRL_SCLK_PHA              (1 << 5)
#define SPI_CTRL_SCLK_PHA_OFF      (5)
#define SPI_CTRL_SS_OFF                  (24)
#define SPI_CTRL_SS_MASK               (3 << 24)
#define SPI_CTRL_DATA_OFF             (16)
#define SPI_CTRL_DATA_MASK           (7 << 16)
#define SPI_CTRL_BURST_OFF            (8)
#define SPI_CTRL_BURST_MASK         (0x1F << 8)

#define SPI_INT_STAT_REG_OFF       0x14
#define SPI_INT_STAT_TC                 (1 << 8)

#elif defined(IMX_CSPI_VER_0_7)
#define SPI_CTRL_EN                          (1 << 0)
#define SPI_CTRL_MODE                     (1 << 1)
#define SPI_CTRL_REG_XCH_BIT        (1 << 2)
#define SPI_CTRL_SSPOL                    (1 << 7)
#define SPI_CTRL_SSPOL_OFF            (7)
#define SPI_CTRL_SSCTL                    (1 << 6)
#define SPI_CTRL_SSCTL_OFF            (6)
#define SPI_CTRL_SCLK_POL              (1 << 4)
#define SPI_CTRL_SCLK_POL_OFF      (4)
#define SPI_CTRL_SCLK_PHA              (1 << 5)
#define SPI_CTRL_SCLK_PHA_OFF      (5)
#define SPI_CTRL_SS_OFF                  (12)
#define SPI_CTRL_SS_MASK               (3 << 12)
#define SPI_CTRL_DATA_OFF             (16)
#define SPI_CTRL_DATA_MASK          (7 << 16)
#define SPI_CTRL_BURST_OFF           (20)
#define SPI_CTRL_BURST_MASK         (0xFFF << 20)

#define SPI_INT_STAT_REG_OFF       0x14
#define SPI_INT_STAT_TC                 (1 << 7)

#elif defined(IMX_CSPI_VER_XX)
#define SPI_CTRL_EN                          (1 << 10)
#define SPI_CTRL_MODE                     (1 << 11)
#define SPI_CTRL_REG_XCH_BIT        (1 << 9)
#define SPI_CTRL_SSPOL                    (1 << 8)
#define SPI_CTRL_SSPOL_OFF            (8)
#define SPI_CTRL_SSCTL                    (1 << 7)
#define SPI_CTRL_SSCTL_OFF            (7)
#define SPI_CTRL_SCLK_POL              (1 << 5)
#define SPI_CTRL_SCLK_POL_OFF      (5)
#define SPI_CTRL_SCLK_PHA              (1 << 6)
#define SPI_CTRL_SCLK_PHA_OFF     (6)
#define SPI_CTRL_SS_OFF                  (19)
#define SPI_CTRL_SS_MASK               (3 << 19)
#define SPI_CTRL_DATA_OFF             (14)
#define SPI_CTRL_DATA_MASK          (0x1F << 14)
#define SPI_CTRL_BURST_OFF           (0)
#define SPI_CTRL_BURST_MASK         (0x1F << 0)

#define SPI_INT_STAT_REG_OFF       0xC
#define SPI_INT_STAT_TC                 (1 << 3)

#endif

#define REV_ATLAS_LITE_1_0         0x8
#define REV_ATLAS_LITE_1_1         0x9
#define REV_ATLAS_LITE_2_0         0x10
#define REV_ATLAS_LITE_2_1         0x11

#endif // __IMX_SPI_H__
