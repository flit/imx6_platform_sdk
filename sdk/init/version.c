/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  version.c
 * @brief Contains function to print out the diag release version.
 *
 * @ingroup diag_init
 */

#include "sdk.h"
#include "version.h"

/*!
 * print out the diag release version info
 *
 * @param    chip     pointer to the string with chip info
 * @param    brd      pointer to the string with board info
 * @param    brd_rev  pointer to the string with board revision
 */
void print_ver(char *chip, char *brd, char *brd_rev)
{
    printf("\n\n\n\n");
    printf("**************************************************************************\n");
    printf("    Diagnostics Suite (%s) for %s %s %s\n", version_s, chip, brd, brd_rev);
    printf("    Build: %s, %s\n", __DATE__, __TIME__);
    printf("    Freescale Semiconductor, Inc.\n");
    printf("**************************************************************************\n\n");
}
