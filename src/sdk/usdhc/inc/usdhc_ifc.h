/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * Module Name: usdhc_ifc.h
 */

#ifndef __USDHC_IFC_H__
#define __USDHC_IFC_H__

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAIL
#define FAIL 1
#endif

/*
 * Whether to enable ADMA when read/write from/to card.
 * If enabled, then use ADMA for transfer, or else, use polling IO
 */
extern int SDHC_ADMA_mode;

/*
 * Whether use interrupt to indicate end of transfer
 * If enabled, will attach the status to interrupt, or else, poll the status
 */
extern int SDHC_INTR_mode;

/*
 * Initialize usdhc controller and card inserted.
 * Parameters:
 * base_address: Base address of uSDHC controller registers
 * bus_width: Bus width that card would be accessed: 1 bit, 4 bits, 8 bits(MMC only)
 */
extern int card_init(int, int);

/*
 * Read data from card
 * Parameters:
 * base_address: Base address of uSDHC controller registers
 * dst_address: Buffer to store data read
 * size: Size in bytes of data to be read
 * offset: Which sector in card should data be started to read
 */
extern int card_data_read(int, int *, int, int);

/*
 * Write data to card
 * Parameters:
 * base_address: Base address of uSDHC controller registers
 * src_address: Buffer that store the source data
 * size: Size in bytes of data to be written
 * offset: Which sector in card should data be started to written
 */

extern int card_data_write(int, int *, int, int);

#endif
