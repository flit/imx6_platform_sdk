/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_file
//! @{
//!
//  Copyright (c) 2005 SigmaTel, Inc.
//!
//! \file    platform.h
//! \brief   FAT file system internal API to peek/poke inside a sector buffer.
//! \version 0.1
//! \date    03/2005
//!
//! This file provides a FAT file system internal API for reading or writing
//! 8-bit, 16-bit, or 32-bit objects inside a sector buffer.
//!
////////////////////////////////////////////////////////////////////////////////
#ifndef _PLATFORM_H
#define _PLATFORM_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <types.h>

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////
extern int32_t FSGetByte(uint8_t *buffer, int32_t iOffsetInUint8);
extern int32_t FSGetWord(uint8_t *buffer, int32_t iOffsetInUint8);
extern uint32_t FSGetDWord(uint8_t *buffer, int32_t iOffsetInUint8);

#define FS_GET_LITTLEENDIAN_INT32(buffer, Offset) (((uint32_t *)buffer)[(Offset)>>2])

extern void PutByte(uint8_t *buffer, uint8_t byte,int32_t Offset);
extern void PutWord(uint8_t *buffer, int32_t word, int32_t Offset);
extern void PutDword(uint8_t *buffer, uint32_t dword, int32_t Offset);

#endif // _PLATFORM_H
//! @}
