/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/


//! @addtogroup diag_pcie
//! @{

/*!
 * @file pcie_phy.h
 * @brief Public interface for PCIE phy.
 */

#ifndef _PCIE_PHY_H_
#define _PCIE_PHY_H_

// SSP ID_CODE
// -----------------
// RTL Version = 8.0          ==>  4'h7
// Product     = SSP          ==>  4'h2
// Foundry     = TSMC 40nm LP ==>  8'h11
// Test_chip   = PHY          ==>  1'h0
// Site ID     = Hillsboro    ==>  3'h6
// Synopsys                   ==> 12'h4CD
#define SSP_JTAG_DR_IDCODE_VAL_HI  0x7211
#define SSP_JTAG_DR_IDCODE_VAL_LO  0x64CD


////////////////////////////////////////////////////////////////////////////////
// API
///////////////////////////////////////////////////////////////////////////////

/*! 
 * @brief This function read the control register of the PCIE phy
 * @param    addr address of the register to be read	
 * @param    data 	register value be read
 *
 * @return   0 on success,
 *           -1 if failed
 */
int pcie_phy_cr_read(uint32_t addr, uint32_t * data);

/*! 
 * @brief This function write the control register of the PCIE phy
 * @param    addr address of the register to be written
 * @param    data 	register value to be written
 *
 * @return   0 on success,
 *           -1 if failed
 */
int pcie_phy_cr_write(uint32_t addr, uint32_t data);

#endif //_PCIE_PHY_REGS_H_
