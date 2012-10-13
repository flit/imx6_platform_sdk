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

//! @name Android_Buttons test defines
//@{
#define HOME_BUTTON_GPIO_INST     GPIO_PORT1
#define HOME_BUTTON_GPIO_NUM      11
#define BACK_BUTTON_GPIO_INST     GPIO_PORT1
#define BACK_BUTTON_GPIO_NUM      12
#define PROG_BUTTON_GPIO_INST     GPIO_PORT2
#define PROG_BUTTON_GPIO_NUM      12
#define VOLPLUS_BUTTON_GPIO_INST  GPIO_PORT2
#define VOLPLUS_BUTTON_GPIO_NUM   15
#define VOLMINUS_BUTTON_GPIO_INST GPIO_PORT7
#define VOLMINUS_BUTTON_GPIO_NUM  8
//@}

//! @brief I2C addresses for devices tested by OBDS.
enum
{
    MMA8450_I2C_ID = 0x1C,
    MMA8451_I2C_ID = 0x1C,
    MAG3112_I2C_ID = 0x1D,
    ISL29023_I2C_ID = 0x44,
    MAG3110_I2C_ID = 0x0E,
    PPL3115_I2C_ID = 0x60,
    EMC1046_I2C_ID = 0x4C,
    MC1323_I2C_ID = 0x4C,
    MAX11801_I2C_ID = (0x90 >> 1),
    PMIC_MC13892_I2C_ADDR = 0x8
};

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
