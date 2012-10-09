/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __CAN_H__
#define __CAN_H__

#include "hardware.h"

#define CAN_TIMING_MASK  0x00C0FFF8  // to zero out presdiv, pseg1, pseg2, prop_seg
#define CAN_NUMBER_OF_BUFFERS 64    // Define the number of MB
#define CAN_LAST_MB 63
#define CAN_TIMING_PARAMETERS 0x0892
#define CAN_MB_OFFSET 0x80

//! @brief  CAN message buffer structure
struct can_mb {
    volatile uint32_t cs;       //! Code and Status
    volatile uint32_t id;       //! ID
    volatile uint32_t data0;    
    volatile uint32_t data1;   
};

//! @brief  CAN Message Buffers   0x80 - 0x170
struct can_message_buffers {
    volatile struct can_mb MB[64];
};

//! @brief  CAN timing related structures 
struct time_segment {
	uint32_t propseg;
	uint32_t pseg1;
	uint32_t pseg2;
};

//! @brief    Baudrates of CAN bus(kps) 
enum can_bitrate {
      MBPS_1,
      KBPS_800,
      KBPS_500,
      KBPS_250,
      KBPS_125,
      KBPS_62,  //62.5kps
      KBPS_20,
      KBPS_10
};

// @brief CAN structure with attributes
struct imx_flexcan {
    hw_module_t *port;
    uint32_t presdiv;	//! Clock pre-divider
    enum can_bitrate bitrate;  //! default 500kbps
    struct time_segment ts;
};

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

/* CAN driver list of functions */
/*!
 * @brief Reset FlexCAN controller
 *
 * @param   port	pointer to the hw_module which presents this FlexCAN 
 */
void can_sw_reset(struct hw_module *port);

/*!
 * @brief Initialize CAN controller
 *
 * @param   port	pointer to FlexCAN module
 * @param   max_mb	Max mailbox will be used
 */
void can_init(struct hw_module *port, uint32_t max_mb);

/*!
 * @brief Set message box fields
 *
 * @param   port	pointer to the hw_module which presents this FlexCAN 
 * @param   mbID	Index of the message box 
 * @param   cs		control/statuc code
 * @param   id		ID of the message to be transfer
 * @param   data0	first 4 bytes of the CAN message 
 * @param   data1	last 4 bytes of the CAN message 
 */
void set_can_mb(struct hw_module *port, uint32_t mbID, uint32_t cs, uint32_t id, uint32_t data0,
                uint32_t data1);

/*!
 * @brief Dump the message box
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 * @param   mbID	Index of the message box 
 */
void print_can_mb(struct hw_module *port, uint32_t mbID);

/*!
 * @brief Enable the interrupt of the FlexCAN module
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 * @param   mbID	Index of the message box 
 */
void can_enable_mb_interrupt(struct hw_module *port, uint32_t mbID);

/*!
 * @brief Disable the interrupt of the FlexCAN module
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 * @param   mbID	Index of the message box 
 */
void can_disable_mb_interrupt(struct hw_module *port, uint32_t mbID);

/*!
 * @brief Un-freeze the FlexCAN module
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 */
void can_exit_freeze(struct hw_module *port);

/*!
 * @brief Freeze the FlexCAN module
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 */
void can_freeze(struct hw_module *port);

/*!
 * @brief Set bit rate
 *
 * CAN bit rate = sclk (aka Freq-TQ) / number-of-time-quanta
 *
 * @param   can_module	pointer to this FlexCAN module
 */
void can_update_bitrate(struct imx_flexcan *can_module);

/*!
 * @brief  Set the attributes of the FlexCAN module
 *
 * @param   can_module	pointer to FlexCAN module
 * @param   bitrate	bit rate to be set
 * @param   hw_port	pointer to the hw_module which presents this FlexCAN 
 */
void can_set_can_attributes(struct imx_flexcan *can_module, uint32_t bitrate, struct hw_module *hw_port);

/*!
 * @brief Get the interrupt flags(iflag1 | (iflag2<<32))
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 * 
 * @return 	interrupt flags(ie, iflag1 | (iflag2<<32))
 */
uint64_t can_mb_int_flag(struct hw_module *port);

/*!
 * @brief Clear the interrupt flag of the message box
 *
 * @param   port        pointer to the hw_module which presents this FlexCAN
 * @param   mbID	Index of the message box 
 */
void can_mb_int_ack(struct hw_module *port, uint32_t mbID);

#endif //__CAN_H__
