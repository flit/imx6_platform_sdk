/*
 * Copyright (C) 2008-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sdk_version.h
 * @brief SDK release version defines.
 *
 * @ingroup diag_util
 */

#if !defined(__SDK_VERSION_H__)
#define __SDK_VERSION_H__

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Current version of the SDK.
#define SDK_VERSION_STRING	"1.0"

//! @name SDK version number components
//@{
#define SDK_VERSION_MAJOR 1
#define SDK_VERSION_MINOR 0
#define SDK_VERSION_BUGFIX 0
//@}

//! @brief Current version of the SDK.
extern const char k_sdk_version[];

//! @brief Copyright string for the SDK.
extern const char k_sdk_copyright[];

#endif // __SDK_VERSION_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
