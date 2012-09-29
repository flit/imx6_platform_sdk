/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
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
#include <string.h>
#include "sdk.h"
#include "text_color.h"

int is_color_supported = INVALID_PARAMETER;

void printf_color(const char* const attrib, const char* const color, const char* format, ...)
{
    if ( is_color_supported )
    {
		if (attrib)
			printf(attrib);
		if (color)
			printf(color);
    }

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if ( is_color_supported )
    	printf(TEXT_ATTRIB_DEFAULT);
}

int get_color_supported()
{
	if ( is_color_supported == INVALID_PARAMETER )
	{
//		<http://invisible-island.net/xterm/ctlseqs/ctlseqs.html>
//
//		Search for "Send Device Attributes" in the page above.
//
//		Send this to query: "\033[>0c"
//
//		A terminal emulator should respond with one of:
//		CSI ? 1 ; 2 c (‘‘VT100 with Advanced Video Option’’)
//		CSI ? 1 ; 0 c (‘‘VT101 with No Options’’)
//		CSI ? 6 c (‘‘VT102’’)
//		CSI ? 6 0 ; 1 ; 2 ; 6 ; 8 ; 9 ; 1 5 ; c (‘‘VT220’’)
//
//		The first response is what I get from Terminal.app on OS X. The equivalent string in C is "\033[?1;2c". (CSI is "ESC[".)
//
//		But basically any response is good enough.
		is_color_supported = TRUE;
	}

  return is_color_supported;
}
