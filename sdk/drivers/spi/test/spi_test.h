/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __SPI_TEST_HDR__
#define __SPI_TEST_HDR__

#include "sdk.h"

#define TEST_BUF_SZ 128
#define TEST_SRC_VAL  0x3569AC00
#define TEST_ERASE_SZ (64 * 1024)

/*  
 * Channel: SS1
 * Mode: master
 * pre_div, post_div: 2 - clock: 60M/4 = 15MHz
 */
#define NUMONYX_INIT_PARAM ((uint32_t)0x00000445)

struct chip_id {
    uint8_t id0;
    uint8_t id1;
    uint8_t id2;
};

typedef struct {
    const char *name;
    int (*test) (void);
} spi_test_t;

#endif
