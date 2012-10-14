/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include <stdarg.h>

#ifndef __TEXT_COLOR_H__
#define __TEXT_COLOR_H__

extern const char* const g_TextAttributeDefault;
extern const char* const g_TextAttributeBold;
extern const char* const g_TextAttributeDim;
extern const char* const g_TextAttributeUnderline;
extern const char* const g_TextAttributeBlink;
extern const char* const g_TextAttributeReverse;
extern const char* const g_TextAttributeHidden;

extern const char* const g_TextColorBlack;
extern const char* const g_TextColorRed;
extern const char* const g_TextColorGreen;
extern const char* const g_TextColorYellow;
extern const char* const g_TextColorBlue;
extern const char* const g_TextColorMagenta;
extern const char* const g_TextColorCyan;
extern const char* const g_TextColorWhite;

void printf_color(const char* const attrib, const char* const color, const char* format, ...);

#endif // __TEXT_COLOR_H__
