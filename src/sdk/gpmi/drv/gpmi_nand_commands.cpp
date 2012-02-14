/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include "gpmi.h"

/*!
 * @file gpmi_nand_commands.cpp
 * @brief Implementation of common NAND commands.
 *
 * @ingroup diag_nand
 */

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

int nand_reset(unsigned chipSelect)
{
}

int nand_read_id(unsigned chipSelect, uint8_t * resultID)
{
}

int nand_erase_block(unsigned chipSelect, uint32_t blockNumber)
{
}

int nand_read_page(unsigned chipSelect, uint32_t pageNumber, uint8_t * buffer, uint8_t * auxBuffer, const BchEccLayout_t * ecc)
{
}

int nand_read_metadata(unsigned chipSelect, uint32_t pageNumber, uint8_t * buffer)
{
}

int nand_write_page(unsigned chipSelect, uint32_t pageNumber, const uint8_t * buffer, const uint8_t * auxBuffer, const BchEccLayout_t * ecc)
{
}

// EOF
