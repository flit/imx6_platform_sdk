///////////////////////////////////////////////////////////////////////////////
// Copyright (c) SigmaTel, Inc. All rights reserved.
// 
// SigmaTel, Inc.
// Proprietary & Confidential
// 
// This source code and the algorithms implemented therein constitute
// confidential information and may comprise trade secrets of SigmaTel, Inc.
// or its associates, and any use thereof is subject to the terms and
// conditions of the Confidential Disclosure Agreement pursual to which this
// source code was originally received.
///////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_filesystem_fat
//! @{
//! \file reentrant_section.c
//! \brief Contains filesystem locking functions.
//!
///////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "fstypes.h"
#include "fat_internal.h"
#include "error.h"
#include "os/filesystem/fsapi.h"
#include "platform.h"
#include "BootSecOffset.h" 
#include "DirOffset.h" 

///////////////////////////////////////////////////////////////////////////////
// Variables
///////////////////////////////////////////////////////////////////////////////

#if (defined(RTOS_THREADX))
    #include <os/tx_api.h>
    static TX_MUTEX   stc_fsMutex;
    static TX_MUTEX * stc_pFsMutex = NULL;
#endif

///////////////////////////////////////////////////////////////////////////////
// Code
///////////////////////////////////////////////////////////////////////////////

/*----------------------------------------------------------------------------
>  Function Name:  void EnterNonReentrantSection(void)

   FunctionType:   Function

   Inputs:         None

   Outputs:        None
<
----------------------------------------------------------------------------*/
void EnterNonReentrantSection(void)
{
#if (defined(RTOS_THREADX))
    UINT retCode;

    // create MUTEX if first time...
    if( stc_pFsMutex == NULL) 
    {
        stc_pFsMutex = &stc_fsMutex;
        retCode = tx_mutex_create(stc_pFsMutex, "FS_MUTEX", TX_NO_INHERIT);
        if( TX_SUCCESS != retCode )
        {
            SystemHalt();
        }
    } 
    
    // get the resource
    // Note: You must be in a thread in order for this code to work.
    retCode = tx_mutex_get(stc_pFsMutex, TX_WAIT_FOREVER);
    if( TX_SUCCESS != retCode )
    {
        SystemHalt();
    }
#endif
}

/*----------------------------------------------------------------------------
>  Function Name:  void LeaveNonReentrantSection(void)

   FunctionType:   Function

   Inputs:         None

   Outputs:        None
<
----------------------------------------------------------------------------*/
void LeaveNonReentrantSection(void)
{
#if (defined(RTOS_THREADX))
    UINT retCode;

    retCode = tx_mutex_put(stc_pFsMutex);
    if( TX_SUCCESS != retCode )
    {
        SystemHalt();
    }
#endif
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}

