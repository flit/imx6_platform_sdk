/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSU_H
#define _CSU_H

#include "regs.h"

#ifndef REGS_CSU_BASE
#define REGS_CSU_BASE (REGS_BASE + 0x021c0000)
#endif




/*!
 * @brief All CSU module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
} hw_csu_t
#endif

//! @brief Macro to access all CSU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSU(0)</code>.
#define HW_CSU     (*(volatile hw_csu_t *) REGS_CSU_BASE)


#endif // _CSU_H
