/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __USDHC_TEST__
#define __USDHC_TEST__

#include "io.h"

#define MMC_TEST_BUF_SIZE 8000
#define MMC_TEST_OFFSET   (1024 * 1024)

#define MMC_CARD_SECTOR_BUFFER 0x80

typedef struct {
    const char *name;
    int (*test) (void);
} usdhc_test_t;

#endif
