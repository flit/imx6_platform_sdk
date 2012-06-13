/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
 
//! @name Number of cores available returned
//!{
#define GET_CORES_ERROR (0)             //!< Incorrect number of cores returned.
#define FOUR_CORES_ACTIVE (4)           //!< Four available cores returned.
#define TWO_CORES_ACTIVE (2)            //!< Two available cores returned.
//@}

//! @brief Find the number of available cores
//!
//! @return the integer value (2,4) of the number of cores

int cpu_get_cores(void);


