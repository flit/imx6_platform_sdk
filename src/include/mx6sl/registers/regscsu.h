/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_CSU_REGISTERS_H__
#define __HW_CSU_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL CSU registers defined in this header file.
 *
 *
 * - hw_csu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CSU_BASE
#define HW_CSU_INSTANCE_COUNT (1) //!< Number of instances of the CSU module.
#define REGS_CSU_BASE (0x021c0000) //!< Base address for CSU.
#endif
//@}


/*!
 * @brief All CSU module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_csu
{
} hw_csu_t;
#pragma pack()

//! @brief Macro to access all CSU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSU(0)</code>.
#define HW_CSU     (*(volatile hw_csu_t *) REGS_CSU_BASE)

#endif


#endif // __HW_CSU_REGISTERS_H__
