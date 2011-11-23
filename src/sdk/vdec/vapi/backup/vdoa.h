/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef VDOA_H_
#define VDOA_H_

#include "hardware.h"
#include "io.h"

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
} vdoaRegs_t;

typedef vdoaRegs_t *vdoaRegs;

void vdoa_setup(int width, int height, int ipu_sl, int vpu_sl, int iubo, int vubo, int sync,
                int ipu_sel);
void vdoa_setIPUBuffer(uint32_t buffer);
void vdoa_setVPUBuffer(uint32_t buffer);
void vdoa_start(uint32_t src, uint32_t dst);
void vdoa_enable_interrupt(void);
void vdoa_disable_interrupt(void);
void vdoa_clear_interrupt(void);

#endif
