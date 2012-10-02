/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__OBDS_HARDWARE_H__)
#define __OBDS_HARDWARE_H__

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief SPI-NOR device types
enum
{
    AT45DB321D = 1,
    M25P32 = 2
};

//! @brief Flag decides the SPI-NOR device type
extern uint32_t spi_nor_flash_type;

//! @brief List of displays supported by the board.
extern int32_t ipu_display_panel[];

#endif // __OBDS_HARDWARE_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
