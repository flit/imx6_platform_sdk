/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//copy from OBDS
// Set up the chip select registers for the weim "parallel" nor flash
void weim_nor_flash_cs_setup(void)
{
   //DSIZ=010 (map 16-bit to D[31:16], csen=1
   // writel(0x00020001, WEIM_BASE_ADDR + 0x000);
   writel(0x00620081, WEIM_BASE_ADDR + 0x0000);

   // CS0 Read Config reg1
   // RWCS=11, OEA=2, OEN=1
   //writel(0x0B002100, WEIM_BASE_ADDR + 0x008);
   writel(0x1C022000, WEIM_BASE_ADDR + 0x0008);

   // CS0 Write Config Reg 1
   // WWCS=11, WEA=2, WEN=1
   //writel(0x0B000440, WEIM_BASE_ADDR + 0x010);
   writel(0x0804a240, WEIM_BASE_ADDR + 0x010); 
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
