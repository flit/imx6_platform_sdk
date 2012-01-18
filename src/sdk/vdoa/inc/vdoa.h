/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __VDOA_H__
#define __VDOA_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vdoa.h"
#include "hardware.h"

#define 	VDOA_VDOAC			0x021E4000
#define 	VDOA_VDOASRR		0x021E4004
#define 	VDOA_VDOAIE			0x021E4008
#define 	VDOA_VDOAIST		0x021E400C
#define 	VDOA_VDOAFP			0x021E4010
#define 	VDOA_VDOAIEBA0_0	0x021E4014
#define 	VDOA_VDOAIEBA0_1	0x021E4018
#define 	VDOA_VDOAIEBA0_2	0x021E401C
#define 	VDOA_VDOAIEBA1_0	0x021E4020
#define 	VDOA_VDOAIEBA1_1	0x021E4024
#define 	VDOA_VDOAIEBA1_2	0x021E4028
#define 	VDOA_VDOASL			0x021E402C
#define 	VDOA_VDOAIUBO		0x021E4030
#define 	VDOA_VDOAVEBA0		0x021E4034
#define 	VDOA_VDOAVEBA1		0x021E4038
#define 	VDOA_VDOAVEBA2		0x021E403C
#define 	VDOA_VDOAVUBO		0x021E4040
#define 	VDOA_VDOASR			0x021E4044
#define 	VDOA_VDOATD			0x021E4048

typedef struct {
    uint32_t vdoac;             /* VDOA Control Register */
    uint32_t vdoasrr;           /* VDOA Start and Reset Register */
    uint32_t vdoaie;            /* VDOA Interrupt Enable Register */
    uint32_t vdoaist;           /* VDOA Interrupt Status Register */
    uint32_t vdoafp;            /* VDOA Frame Parameters Register */
    uint32_t vdoaieba00;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoaieba01;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoaieba02;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoaieba10;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoaieba11;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoaieba12;        /* VDOA External Buffer n Frame m Address Register */
    uint32_t vdoasl;            /* VDOA IPU Stride Line Register */
    uint32_t vdoaiubo;          /* VDOA IPU Chroma Buffer Offset Register */
    uint32_t vdoaveba0;         /* VDOA External Buffer m Address Register */
    uint32_t vdoaveba1;         /* VDOA External Buffer m Address Register */
    uint32_t vdoaveba2;         /* VDOA External Buffer m Address Register */
    uint32_t vdoavubo;          /* VDOA VPU Chroma Buffer Offset */
    uint32_t vdoasr;            /* VDOA Status Register */
    uint32_t vdoatd;            /* VDOA Test Debug Register */
} vdoa_regs_t;

//void vdoa_setup(int width, int height, int ipu_sl, int vpu_sl, int iubo, int vubo, int sync, int ipu_sel);
void vdoa_setup(int width, int height, int vpu_sl, int ipu_sl, int interlaced,
                int ipu_sel, int bandLines, int pfs);
void vdoa_start(uint32_t src, uint32_t ubo, uint32_t dst, uint32_t iubo);
void vdoa_enable_interrupt(void);
void vdoa_disable_interrupt(void);
void vdoa_clear_interrupt(void);
void vdoa_set_vpu_buffer(uint32_t vbuf);
void vdoa_set_ipu_buffer(uint32_t ibuf);
void vdoa_set_vpu_ubo(uint32_t vubo);
void vdoa_set_ipu_ubo(uint32_t iubo);
void vdoa_start_transfer(void);
uint32_t vdoa_check_tx_eot(void);

#endif
