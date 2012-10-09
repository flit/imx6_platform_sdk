/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
///////////////////////////////////////////////////////////////////////////////
//! \addtogroup common
//! @{
//
// Copyright (c) 2000-2005 SigmaTel, Inc.
//
//! \file types.h
//! \brief Contains standard data types.
//! \todo [PUBS] Add definitions for TBDs in this file
///////////////////////////////////////////////////////////////////////////////


#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include "assert.h"

//------------------------------------------------------------------------------
// All of the following defs are included for compatability.  Please use the
// ANSI C99 defs for all new work.
//------------------------------------------------------------------------------

//! \brief TBD
typedef bool        BOOL;

// //! \brief TBD
// typedef uint8_t     UINT8;

// //! \brief TBD
typedef uint8_t     BYTE;

//! \brief TBD
typedef uint32_t    WORD;

// //! \brief TBD
typedef uint32_t    SECTOR_BUFFER;
//! \brief TBD
typedef uint32_t *  P_SECTOR_BUFFER;

#define REENTRANT

#endif // #ifndef _TYPES_H

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}
