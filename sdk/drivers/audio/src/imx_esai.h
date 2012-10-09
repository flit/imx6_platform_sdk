/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//! @addtogroup diag_audio
//! @{

/*!
 * @file imx-esai.h
 * @brief ESAI header file.
 */

#ifndef __IMX_ESAI_H__
#define __IMX_ESAI_H__

//! @brief Parameter types supported by get/set routine
typedef enum {
    ESAI_HW_PARA_ECR,
    ESAI_HW_PARA_TCR,
    ESAI_HW_PARA_RCR,
    ESAI_HW_PARA_TCCR,
    ESAI_HW_PARA_RCCR,
    ESAI_HW_PARA_TFCR,
    ESAI_HW_PARA_RFCR,
    ESAI_HW_PARA_TSR,
    ESAI_HW_PARA_SAICR,
    ESAI_HW_PARA_TSM,           //time slot mask
    ESAI_HW_PARA_RSM,           //time slot mask
    ESAI_HW_PARA_TX_WL,         //word len in bits
    ESAI_HW_PARA_RX_WL,         //word len in bits
} esai_hw_para_type_e;

//! @brief Status supported by get_status routine
typedef enum {
    ESAI_STATUS_ESR,
    ESAI_STATUS_TFSR,
    ESAI_STATUS_RFSR,
    ESAI_STATUS_SAISR,
} esai_status_e;

//! @brief Types supported by enable routine
typedef enum {
    ESAI_SUB_ENABLE_TYPE_ESAI,
    ESAI_SUB_ENABLE_TYPE_TX,
    ESAI_SUB_ENABLE_TYPE_RX,
    ESAI_SUB_ENABLE_TYPE_TXFIFO,
    ESAI_SUB_ENABLE_TYPE_RXFIFO,
} esai_sub_enable_type_e;

////////////////////////////////////////////////////////////////////////////////
// APIs
////////////////////////////////////////////////////////////////////////////////

/*!
 * Configure the ESAI module according the parameters which was passed by audio_card driver.
 *
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 * @param       para    a pointer passed by audio card driver, consists of configuration parameters
 *              for ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_config(void *priv, audio_dev_para_p para);

/*!
 * Initialize the esai module and set the esai to default status. 
 * This function will be called by the snd_card driver. 
 *
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it 
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_init(void *priv);

/*!
 * Close the ESAI module
 * @param       priv    a pointer passed by audio card driver, ESAI driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_deinit(void *priv);

/*!
 * Write datas to the esai fifo in polling mode.
 * @param       priv    a pointer passed by audio card driver, esai driver should change it
 *                      to a audio_ctrl_p pointer which presents the ESAI controller.
 * @param       buf     points to the buffer which hold the data to be written to the ESAI tx fifo
 * @param       size    the size of the buffer pointed by buf.
 * @param       bytes_written	bytes be written to the ESAI tx fifo
 *
 * @return      0 if succeeded
 *              -1 if failed
 */
int32_t esai_write_fifo(void *priv, uint8_t * buf, uint32_t size, uint32_t * bytes_written);

#endif
