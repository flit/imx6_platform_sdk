/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  abort_handler.c
 *
 * @ingroup diag_init
 */

#include "sdk.h"

/**************************** Functions ***************************************/

__attribute__ ((interrupt("ABORT")))
void ABORT_HDLR(void)
{
    printf("Welcome into the abort handler...\n");
}
