/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __CAAM_H__
#define	__CAAM_H__

//! @name Error codes
//@{
#if !defined(SUCCESS)
#define SUCCESS (0)
#endif

#define ERROR_IN_PAGE_ALLOC (1)


////////////////////////////////////////////////////////////////////////////////
//! @brief Enable and initialize the CAAM driver.
//!
//! This function enables the clock to the CAAM. It initializes the RNG, and
//! instantiate it to allow generation of key for blob.
//!
////////////////////////////////////////////////////////////////////////////////
void caam_open(void);

////////////////////////////////////////////////////////////////////////////////
//! @brief Encrypt a data with a key obtained from a DEK blob.
//!
//! @param[in] plain_text_addr  Location address of the plain text data.
//! @param[in] cipher_text_addr  Location address of the cipher text.
//! @param[in] key_addr  Location address of the encryption key.
//!
//! @return SUCCESS
//! @return ERROR_XXX
////////////////////////////////////////////////////////////////////////////////
uint32_t caam_enc_data(uint32_t plain_text_addr, uint32_t cipher_text_addr,
                   uint32_t key_addr);

////////////////////////////////////////////////////////////////////////////////
//! @brief Generate a blob of a secure key.
//!
//! @param[in] plain_data_addr  Location address of the plain text data.
//! @param[in] blob_addr  Location address of the blob.
//!
//! @return SUCCESS
//! @return ERROR_XXX 
////////////////////////////////////////////////////////////////////////////////
uint32_t caam_gen_blob(uint32_t plain_data_addr, uint32_t blob_addr);

////////////////////////////////////////////////////////////////////////////////
//! @brief Decapsulate a blob of a secure key.
//!
//! @param[in] blob_addr  Location address of the blob.
//!
//! @return SUCCESS
//! @return ERROR_XXX
////////////////////////////////////////////////////////////////////////////////
uint32_t caam_decap_blob(uint32_t blob_addr);

#endif /* __CAAM_H__ */
