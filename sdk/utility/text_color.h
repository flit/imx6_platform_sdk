/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include <stdarg.h>

#ifndef __TEXT_COLOR_H__
#define __TEXT_COLOR_H__

static const char* const TEXT_ATTRIB_DEFAULT   = "\033[00m";
static const char* const TEXT_ATTRIB_BOLD      = "\033[01m";
static const char* const TEXT_ATTRIB_DIM       = "\033[02m";
static const char* const TEXT_ATTRIB_UNDERLINE = "\033[03m";
static const char* const TEXT_ATTRIB_BLINK     = "\033[05m";
static const char* const TEXT_ATTRIB_REVERSE   = "\033[07m";
static const char* const TEXT_ATTRIB_HIDDEN    = "\033[08m";

static const char* const TEXT_COLOR_BLACK      = "\033[30m";
static const char* const TEXT_COLOR_RED        = "\033[31m";
static const char* const TEXT_COLOR_GREEN      = "\033[32m";
static const char* const TEXT_COLOR_YELLOW     = "\033[33m";
static const char* const TEXT_COLOR_BLUE       = "\033[34m";
static const char* const TEXT_COLOR_MAGENTA    = "\033[35m";
static const char* const TEXT_COLOR_CYAN       = "\033[36m";
static const char* const TEXT_COLOR_WHITE      = "\033[37m";

void printf_color(const char* const attrib, const char* const color, const char* format, ...);

#endif // __TEXT_COLOR_H__
