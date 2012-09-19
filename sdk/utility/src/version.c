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
#include "board_id/board_id.h"

/*!
 * print out the diag release version info
 *
 */
void print_version(void)
{
    char chip_str[64] = { 0 };
    char chip_rev_str[64] = { 0 };
    char board_str[64] = { 0 };
    char board_rev_str[64] = { 0 };

    fsl_board_id_t fsl_board_id = get_board_id();

    chip_name(chip_str, fsl_board_id.B.CHIP_TYPE_ID, false);
    chip_revision(chip_rev_str, fsl_board_id.B.CHIP_REV_MAJOR, fsl_board_id.B.CHIP_REV_MINOR);
    board_name(board_str, BOARD_TYPE);
    board_revision(board_rev_str, BOARD_REVISION);

    printf("\n\n\n\n");
    printf("**************************************************************************\n");
    printf("    Platform SDK (%s) for %s %s %s %s\n", version_s, chip_str, chip_rev_str,
           board_str, board_rev_str);
    printf("    Build: %s, %s\n", __DATE__, __TIME__);
    printf("    Freescale Semiconductor, Inc.\n");
    printf("**************************************************************************\n\n");
}
