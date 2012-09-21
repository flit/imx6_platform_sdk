/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

//!@addtogroup diag_usdhc
//!@{

/*!
 * @file usdhc_ifc.h
 * @brief uSDHC driver public interface. 
 */

#ifndef __USDHC_IFC_H__
#define __USDHC_IFC_H__

//////////////////////////////////////////////////////////////////////////////
// Definitions
/////////////////////////////////////////////////////////////////////////////

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

//! @brief boot part
typedef enum {
    EMMC_PART_USER,
    EMMC_PART_BOOT1,
    EMMC_PART_BOOT2
} emmc_part_e;

//! @brief eMMC bus width
typedef enum {
    EMMC_BOOT_SDR1,
    EMMC_BOOT_SDR4,
    EMMC_BOOT_SDR8,
    EMMC_BOOT_DDR4,
    EMMC_BOOT_DDR8
} emmc_bus_width_e;

/*!
 * Whether to enable ADMA when read/write from/to card.
 * If enabled, then use ADMA for transfer, or else, use polling IO
 */
extern int SDHC_ADMA_mode;

/*!
 * Whether use interrupt to indicate end of transfer
 * If enabled, will attach the status to interrupt, or else, poll the status
 */
extern int SDHC_INTR_mode;

//////////////////////////////////////////////////////////////////////////////////
// API
//////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize usdhc controller and card inserted.
 * 
 * @param   base_address   Base address of uSDHC controller registers
 * @param   bus_width      Bus width that card would be accessed: 1 bit, 4 bits, 8 bits(MMC only)
 *
 * @return  0 if successful; non-zero otherwise 
*/
extern int card_init(int base_address, int bus_width);

/*!
 * @brief Read data from card
 * 
 * @param   base_address   Base address of uSDHC controller registers
 * @param   dst_ptr        Buffer to store data read
 * @param   length         Size in bytes of data to be read
 * @param   offset         Which sector in card should data be started to read
 *
 * @return   0 if successful; non-zero otherwise 
*/
extern int card_data_read(int base_address, int *dst_ptr,  int length, int offset);

/*!
 * @brief Write data to card
 * 
 * @param   base_address   Base address of uSDHC controller registers
 * @param   src_ptr        Buffer that store the source data
 * @param   length         Size in bytes of data to be written
 * @param   offset         Which sector in card should data be started to written
 *
 * @return  0 if successful; non-zero otherwise 
*/
extern int card_data_write(int base_address, int *src_ptr, int length, int offset);

/*!
 * @brief Read the data transfer status(only in interrupt mode)
 * 
 * @param   base_address   Base address of uSDHC controller registers
 * @param   status         Store the readback status. 0: busy, 1: success, 2: error
 *
 * @return 0 if successful; non-zero otherwise
 */
extern int card_xfer_result(int base_address, int *status);

/*!
 * eMMC specific functions
 */
extern int card_emmc_init(int base_address);
extern void emmc_print_cfg_info(int base_address);
extern int mmc_set_boot_ack(int base_address, int enable);
extern int mmc_set_boot_partition(int base_address, emmc_part_e part);
extern int mmc_set_boot_bus_width(int base_address, emmc_bus_width_e width);

#if defined (__cplusplus)
}
#endif

//! @}
#endif  /*__USDHC_IFC_H__ */ 
/////////////////////////////////////////////////////////////////////////////////
// EOF
/////////////////////////////////////////////////////////////////////////////////
