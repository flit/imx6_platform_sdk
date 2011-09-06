/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __TEXT_COLOR_H__
#define __TEXT_COLOR_H__
#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3

#define BLINK		5
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7
extern void textcolor(int attr, int fg, int bg);

#define DEFAULT_BG_COLOR    WHITE
#define DEFAULT_FG_COLOR    BLACK
#define ERROR_COLOR	        RED
#define ATTENTION_COLOR     YELLOW
#define PASS_COLOR          GREEN

#define printf_color(color, fmt, args...)	                    \
    do {					                                    \
        textcolor(BRIGHT, color, DEFAULT_BG_COLOR);		        \
        printf(fmt, args);		                                \
        textcolor(BRIGHT, DEFAULT_FG_COLOR, DEFAULT_BG_COLOR);	\
    } while(0)
#endif
