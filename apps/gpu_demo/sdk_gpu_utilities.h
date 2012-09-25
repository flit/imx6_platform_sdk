/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __GPU_UTILITY_H__
#define __GPU_UTILITY_H__

#include "soc_memory_map.h"
#include "ipu_reg_def.h"

#define REG_BASE GPU_3D_BASE_ADDR
#define DEBUG_REG_BASE GPU_3D_BASE_ADDR

extern int width;
extern int height;
extern int pixel_format;        //2 - 16 bit; 4 - 32 bit
extern int lcd_pixel_format;    //2 - 16 bit; 4 - 32 bit
extern int depth_format;        //2 - 16 bit; 4 - 32 bit

extern int SAVE_BMP, ENABLEZC, HZ;
extern int USE_FAST_CLEAR;

typedef union {
    float f;
    unsigned int u;
} floatint;

extern float f;

extern floatint new_width;
extern floatint new_height;
extern floatint new_half_width;
extern floatint new_half_height;
extern floatint neg_new_half_height;

extern volatile int gpu_new_frame;

unsigned long ReadReg(unsigned int addr);
void WriteReg(unsigned int addr, unsigned long data);
void Poke(unsigned long addr, unsigned long data);
void clearFrameBufferMSAA(unsigned long phys);
void clearFrameBuffer(unsigned long phys, unsigned long colour);
void clearBuffers(unsigned long phys, int use2DClear);
void fastClear(unsigned long phys, unsigned long colour);
void disableFastClear(unsigned long phys);
void fastClearMSAA(unsigned long phys);
void start(unsigned long phys);
void DoResolve(unsigned long phys,
               unsigned long SrcAddress,
               unsigned long DestAddress,
               unsigned long DepthAddress,
               int Width,
               int Height,
               int SrcColorBpp,
               int DestColorBpp,
               int DepthBpp,
               int SrcTiled,
               int DepthTiled,
               int DestTiled,
               int DetectThresh,
               int FilterOffFrontZ,
               int EdgeDetect, int SuperSample, int SrcSuperTile, int DstSuperTile, int sRGB_en);
void CallResolve(unsigned long phys, int SuperSample, int SrcSuperTile, int DstSuperTile);
void clearTWOD(unsigned long phys, unsigned long target_address, unsigned long target_data);

#endif
