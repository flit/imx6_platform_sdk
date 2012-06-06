/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#ifndef __ECSPI_HDR__
#define __ECSPI_HDR__

#include "sdk.h"

#define SUCCESS 1
#define FAIL 0

#define ECSPI_FIFO_SIZE 64

#define ECSPI_CTL_EN          ((uint32_t)0x00000001)
#define ECSPI_CTL_CS_MASK     ((uint32_t)0x000C0000)
#define ECSPI_CFG_MASK        ((uint32_t)0x00001011)
#define ECSPI_CTL_BURST_MASK  ((uint32_t)0xFFF00000)
#define ECSPI_CTL_SMC_MASK    ((uint32_t)0x00000008)
#define ECSPI_CTL_XCH_MASK    ((uint32_t)0x00000004)
#define ECSPI_CTL_PRE_MASK    ((uint32_t)0x0000F000)
#define ECSPI_CTL_POST_MASK   ((uint32_t)0x00000F00)
#define ECSPI_STS_TC_MASK     ((uint32_t)0x00000080)
#define ECSPI_STS_RO_MASK     ((uint32_t)0x00000040)
#define ECSPI_STS_ALL_MASK    ((uint32_t)0x000000C0)
#define ECSPI_STS_RR_MASK     ((uint32_t)0x00000008)
#define ECSPI_STS_TE_MASK     ((uint32_t)0x00000001)

#define ECSPI_CTL_CS_SHIFT       18
#define ECSPI_CTL_MD_SHIFT       4
#define ECSPI_CTL_BURST_SHIFT    20
#define ECSPI_CTL_PRE_SHIFT      12
#define ECSPI_CTL_POST_SHIFT     8
#define ECSPI_CFG_SCLK_PHA_SHIFT 0
#define ECSPI_CFG_SCLK_POL_SHIFT 4
#define ECSPI_CFG_SS_CTL_SHIFT   8
#define ECSPI_CFG_SS_POL_SHIFT   12

#define SPI_RETRY_TIMES 100

typedef struct {
    volatile uint32_t rxfifo;
    volatile uint32_t txfifo;
    volatile uint32_t ctrl;
    volatile uint32_t config;
    volatile uint32_t interrupt;
    volatile uint32_t dma;
    volatile uint32_t status;
    volatile uint32_t period;
    volatile uint32_t test;
    volatile uint32_t reserved[7];
    volatile uint32_t msg[16];
} ecspi_register, *ecspi_register_ptr;

#endif
