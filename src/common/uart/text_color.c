/*
 * Copyright (C) 2009-2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file    text_color.c
 * @brief   This file has the function to print out text in color used in printf
 *
 * @ingroup diag_util
 */

#include <stdio.h>

void textcolor(int attr, int fg, int bg)
{
    char command[13];

    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
}
