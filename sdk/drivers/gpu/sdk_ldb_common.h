/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __LDB_COMMON_H__
#define __LDB_COMMON_H__

#define LDB_CH0_MODE(x)         ((x) << 0)
#define LDB_CH1_MODE(x)         ((x) << 2)
#define LDB_SPLIT_MODE(x)       ((x) << 4)
#define LDB_CH0_DATA_WIDTH(x)   ((x) << 5)
#define LDB_CH0_BIT_MAP(x)      ((x) << 6)
#define LDB_CH1_DATA_WIDTH(x)   ((x) << 7)
#define LDB_CH1_BIT_MAP(x)      ((x) << 8)
#define LDB_DI0_VS_POL(x)       ((x) << 9)
#define LDB_DI1_VS_POL(x)       ((x) << 10)
#define LDB_CLK_SHIFT(x)        ((x) << 11)

#endif
