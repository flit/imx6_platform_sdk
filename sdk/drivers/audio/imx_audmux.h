/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//! @addtogroup diag_audio
//! @{

/*! 
 * @file imx-audmux.h
 * @brief imx-audmux public inferface.
 */

#ifndef __AUDMUX_H__
#define __AUDMUX_H__

//! @brief AUDMUX ports supported by i.MX audumx controller
typedef enum {
    AUDMUX_PORT_1 = 1,
    AUDMUX_PORT_2,
    AUDMUX_PORT_3,
    AUDMUX_PORT_4,
    AUDMUX_PORT_5,
    AUDMUX_PORT_6,
    AUDMUX_PORT_7,
} audmux_port_e;

//! @brief AUDMUX modes
typedef enum {
    AUDMUX_SSI_SLAVE = 0,
    AUDMUX_SSI_MASTER,
} audmux_ssi_dir_e;

//////////////////////////////////API functions declaration////////////////////////////////
#if defined(__cplusplus)
extern "C" {
#endif                          // __cplusplus

/*!
 * @breif Set ptcr and pdcr of the audmux port
 *
 * @param   port	the port to be set
 * @param   ptcr	ptcr value to be set
 * @param   pdcr	pdcr value to be set
 * @return  0 if succeeded
 *	    -1 if failed. 
 */
    uint32_t audmux_port_set(uint32_t port, uint32_t ptcr, uint32_t pdcr);

/*!
 * @brief Set audmux port according the ssi mode(master/slave).
 *
 * We set the audumx ports in sync mode which is the default status for most codec.
 * 
 * @param   intPort	the internal port to be set
 * @param   extPort	the external port to be set
 * @param   is_master	ssi mode(master/slave)
 * @return  0 if succeeded
 *	    -1 if failed. 
 */
    uint32_t audmux_route(uint32_t intPort, uint32_t extPort, uint32_t is_master);

#if defined(__cplusplus)
}
#endif                          // __cplusplus
#endif
