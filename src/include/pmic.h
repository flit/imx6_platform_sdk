/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __PMIC_H__
#define __PMIC_H__

u32 pmic_reg(u32 reg, u32 val, u32 is_write);
void imx_pmic_init(void);

#define PMIC_READ       1
#define PMIC_WRITE      0

#endif /* __PMIC_H__ */
