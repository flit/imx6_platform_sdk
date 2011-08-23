/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file cortexA9.s
 * @brief This file contains cortexA9 functions
 *
 */
 
    .code 32
    .section ".cortexA9","ax"
    
  .global getCPUnum
  @ int getCPUnum(void);
  @ get current CPU ID
  .func getCPUnum
getCPUnum: 
    MRC   p15, 0, r0, c0, c0, 5
    AND   r0, r0, #3
	BX	  lr
  .endfunc    @getCPUnum();

@ ------------------------------------------------------------
@ End of cortexA9.s
@ ------------------------------------------------------------
    .end
