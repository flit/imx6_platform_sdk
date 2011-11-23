/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef _SIIIIC_
#define _SIIIIC_

//--------------------------------------------------------------------
// typedef
//--------------------------------------------------------------------
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

#define FALSE                0
#define TRUE                  1

#define OFF                    0
#define ON                      1

#define SET 1
#define CLR 0

#define WRITE 0x00
#define READ   0x01

#define IIC_CAPTURED  1
#define IIC_NOACK     2
#define IIC_OK 0

byte I2CReadByte(byte SlaveAddr, byte RegAddr);
void I2CWriteByte(byte SlaveAddr, byte RegAddr, byte Data);

byte I2CReadBlock(byte SlaveAddr, byte RegAddr, byte NBytes, byte * Data);
byte I2CWriteBlock(byte SlaveAddr, byte RegAddr, byte NBytes, byte * Data);

byte siiReadSegmentBlockEDID(byte SlaveAddr, byte Segment, byte Offset, byte * Buffer, byte Length);

#endif
