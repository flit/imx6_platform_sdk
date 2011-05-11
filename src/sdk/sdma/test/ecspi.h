/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __ESCPI_H__
#define __ESCPI_H__

typedef struct {
    volatile unsigned int rxdata;
    volatile unsigned int txdata;
    volatile unsigned int conreg;
    volatile unsigned int configreg;
    volatile unsigned int intreg;
    volatile unsigned int dmareg;
    volatile unsigned int statreg;
    volatile unsigned int periodreg;
    volatile unsigned int testreg;
    volatile unsigned int msgdata[16];
} ecspi_reg_t, *ecspi_reg_p;

#define ECSPI_TESTREG_LBC (1<<31)

#define ECSPI_DMA_RXDEN (1<<23)
#define ECSPI_DMA_RXTHR_SHIFT (16)

#define ECSPI_DMA_TXDEN (1<<7)
#define ECSPI_DMA_TXTHR_SHIFT (0)

#define ESCPI_CONREG_BL_ONEWORD (0x1F << 20)
#define ECSPI_CONREG_CHNL0SEL (0<<18)
#define ECSPI_CONREG_CHNL0MD_MASTER (1<<4)
#define ECSPI_CONREG_SMC (1<<3)
#define ECSPI_CONREG_XCH (1<<2)
#define ECSPI_CONREG_EN (1<<0)

#define ECSPI_CONREG_PREDIV (0x3 << 12)
#define ECSPI_CONREG_POSTDIV (0x2 << 8)

#define ECSPI_CONFIG_CHNL0SSCTL (1<<8)

#endif
