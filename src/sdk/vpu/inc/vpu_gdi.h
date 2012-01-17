/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */

#ifndef GDI_H_INCLUDED
#define GDI_H_INCLUDED

#include "vpu_lib.h"

enum {
    X_SEL = 0,
    Y_SEL = 1,
};

enum {
    CA_SEL = 0,
    BA_SEL = 1,
    RA_SEL = 2,
    Z_SEL = 3,
};

#define XY2CONFIG(A,B,C,D,E,F,G,H,I) ((A)<<20 | (B)<<19 | (C)<<18 | (D)<<17 | (E)<<16 | (F)<<12 | (G)<<8 | (H)<<4 | (I))
#define XY2(A,B,C,D)                 ((A)<<12 | (B)<<8 | (C)<<4 | (D))
#define XY2BANK(A,B,C,D,E,F)         ((A)<<13 | (B)<<12 | (C)<<8 | (D)<<5 | (E)<<4 | (F))
#define RBC(A,B,C,D)                 ((A)<<10 | (B)<< 6 | (C)<<4 | (D))
#define RBC_SAME(A,B)                ((A)<<10 | (B)<< 6 | (A)<<4 | (B))

typedef struct {
    int xy2ca_map[16];
    int xy2ba_map[16];
    int xy2ra_map[16];
    int rbc2axi_map[32];
    int MapType;

    int xy2rbc_config;
    int tb_separate_map;
    int top_bot_split;
    int tiledMap;
    int ca_inc_hor;
    int value;
} GdiTiledMap;

int SetTiledMapTypeInfo(GDI_TILED_MAP_TYPE TiledMapType, GdiTiledMap * pTiledInfo);
void SetGDIRegs(GdiTiledMap * pTiledInfo);

#endif // end of GDI_H_INCLUDED
