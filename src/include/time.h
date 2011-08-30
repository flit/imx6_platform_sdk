/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __TIME_H__
#define __TIME_H__

#include "io.h"

void hal_delay_us(uint32_t usecs);
void system_time_init(uint32_t clock_src);

#endif /* __TIME_H__ */
