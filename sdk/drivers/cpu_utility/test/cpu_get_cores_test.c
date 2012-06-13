/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "cpu_utility/cpu_utility.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

//! @brief Display the number of cores to the debugging terminal
//!

void cpu_get_cores_test(void);

void cpu_get_cores_test(void)
{
    // Checks whether an invalid number of cores has been returned
    // and return error message.
    int num_cores = cpu_get_cores();
    if(num_cores == GET_CORES_ERROR)
    {
        printf("There has been an error!\n");
    }
    // Display the number of accessible cores.
    else
    {
        printf("\n There are %d accessible cores. \n", num_cores);
    }    
}

