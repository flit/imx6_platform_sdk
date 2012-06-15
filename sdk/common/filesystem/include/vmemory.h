/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup hw_core
//! @{
//
// Copyright(C) SigmaTel, Inc. 2005
//
//! \file vmemory.h
//! \brief ARM Virtual Memory definitions
//! \version version 0.1
//! \date Feb, 2005
////////////////////////////////////////////////////////////////////////////////
#ifndef __VMEMORY_H__
#define __VMEMORY_H__

/*
   Example usage :

   void foo(void) __OCRAM_CODE;  // locate function in 1T-RAM

   int32_t bar __OCRAM_DATA = 1;     // locate data in 1-T RAM

   void foo(void)
   {
      printf("bar %d", bar);
   }

*/

#ifdef _WIN32

    // Empty defines for win32 platforms
    #define __STATIC_TEXT
    #define __STATIC_RODATA

    #define __OCRAM_TEXT
    #define __OCRAM_DATA
    #define __OCRAM_RODATA
    #define __OCRAM_BSS
    #define __OCRAM_DATA_NCNB

    #define __INIT_TEXT
    #define __INIT_RODATA

    #define __PAGEABLE_TEXT
    #define __PAGEABLE_RODATA

    #define __BSS_NCNB
    #define __DATA_NCNB

#else

// For placing specific variables and functions into INIT sections (to be steered into pageable init, or static .text/.rodata,
//      depending on the memory model chosen
    #define __INIT_TEXT          __attribute__ ((section (".init.text")))
    #define __INIT_RODATA        __attribute__ ((section (".init.rodata")))
// For placing specific variables and functions into static sections (to be steered to .ocram or .sdram in the .ld file)
    #define __STATIC_TEXT        __attribute__ ((section (".static.text")))
    #define __STATIC_RODATA      __attribute__ ((section (".static.rodata")))
// For placing specific variables and functions into OCRAM sections
    #define __OCRAM_TEXT         __attribute__ ((section (".ocram.text")))
    #define __OCRAM_RODATA       __attribute__ ((section (".ocram.rodata")))
    #define __OCRAM_DATA         __attribute__ ((section (".ocram.data")))
    #define __OCRAM_BSS          __attribute__ ((section (".ocram.bss")))
    #define __OCRAM_DATA_NCNB    __attribute__ ((section (".ocram.data.ncnb")))
    #define __OCRAM_BSS_NCNB     __attribute__ ((section (".ocram.bss.ncnb")))
    #define __OCRAM_BSS_USB_NCNB __attribute__ ((section (".ocram.bss.usb_ncnb")))
    #define __OCRAM_DATA_USB_NCNB __attribute__ ((section (".ocram.data.usb_ncnb")))
// For placing specific variables and functions into SDRAM sections
    #define __SDRAM_BSS           __attribute__ ((section (".sdram.bss")))


// For placing specific variables and functions into NCNB sections
    #define __BSS_NCNB           __attribute__ ((section (".bss.ncnb")))
    #define __DATA_NCNB          __attribute__ ((section (".data.ncnb")))
#endif

#endif // __VMEMORY_H__

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}




