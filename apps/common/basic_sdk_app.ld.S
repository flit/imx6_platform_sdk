/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(startup)

/*
 * OCRAM
 */
#if defined(CHIP_MX6SDL) || defined(CHIP_MX6SL)
    // mx6sl and mx6sdl both have 128kB of OCRAM.
    #define OCRAM_LEN 128K
#elif defined(CHIP_MX6DQ)
    // mx6dq has 256kB of OCRAM
    #define OCRAM_LEN 256K
#else
    #error Unknown chip!
#endif

/*
 * External DDR
 */
#if defined(CHIP_MX6SL)
    // mx6sl has only one DDR chip select that starts at a different address
    #define DDR_ORG 0x80000000
#elif defined(CHIP_MX6SDL) || defined(CHIP_MX6DQ)
    // mx6dq and mx6sdl DDR memory starts at this address
    #define DDR_ORG 0x10000000
#else
    #error Unknown chip!
#endif

#if defined(BOARD_SABRE_AI)
    // mx6dq and mx6sdl sabre-ai board has 2GB of DDR3
    #define DDR_LEN 2048M
#else
    // all other boards have 1GB of DDR3
    #define DDR_LEN 1024M
#endif

// Maximum size of the signed image
#define MAX_IMAGE_SIZE 256K

// Maximum size of HAB CSF data
#define MAX_HAB_CSF_DATA_SIZE 8K

// Size of exception stacks section
#define EXCEPTIONS_STACK_SIZE 40K

INPUT (crtbegin.o crti.o crtend.o crtn.o)

MEMORY
{
    OCRAM (rwx) : ORIGIN = 0x00900000, LENGTH = OCRAM_LEN - 0x100
    DDR (rwx)   : ORIGIN = DDR_ORG, LENGTH = DDR_LEN
}

SECTIONS
{
/* -- OCRAM -- */

    /* allocate a heap in ocram */
    .heap.ocram :
    {
        __heap_ocram_start = .;
        . += LENGTH(OCRAM) ;
        __heap_ocram_end = .;
    } > OCRAM

/* -- DDR -- */

    _start_image_add = ORIGIN(DDR);
    
    .ivt (ORIGIN(DDR)) :
    {
        . = . + 0x400;
        *(.ivt)
    } > DDR
    
    .boot_data :
    {
        __start_boot_data = .;
        *(.boot_data)
    } > DDR
    
    /* aligned to ease the hexdump read of generated binary */ 
    .dcd_hdr : ALIGN(16)
    {
        __start_dcd = .;
        *(.dcd_hdr)
    } > DDR
    .dcd_wrt_cmd :
    {
        *(.dcd_wrt_cmd)
    } > DDR
    .dcd_data :
    {
        *(.dcd_data)
    } > DDR
    
    .vectors ALIGN(32) :
    {
        *(.vectors)
    } > DDR

    .init :
    {
        KEEP (*(.init))
    } > DDR =0
    
    .text : ALIGN(8)
    {
        *(.startup)
        *(.text .text.*)
    } > DDR
    
    .fini :
    {
        KEEP (*(.fini))
    } > DDR =0

    .ctors :
    {
        /* gcc uses crtbegin.o to find the start of
           the constructors, so we make sure it is
           first.  Because this is a wildcard, it
           doesn't matter if the user does not
           actually link against crtbegin.o; the
           linker won't look for a file to match a
           wildcard.  The wildcard also means that it
           doesn't matter which directory crtbegin.o
           is in.  */
        KEEP (*crtbegin.o(.ctors))
        KEEP (*crtbegin?.o(.ctors))
        /* We don't want to include the .ctor section from
           the crtend.o file until after the sorted ctors.
           The .ctor section from the crtend file contains the
           end of ctors marker and it must be last */
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
    } > DDR
    .dtors :
    {
        KEEP (*crtbegin.o(.dtors))
        KEEP (*crtbegin?.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
    } > DDR

    .data :
    {
        *(.data .data.*)
        SORT(CONSTRUCTORS)
    } > DDR

    .rodata :
    {
        *(.rodata .rodata.*)
    } > DDR

    /* Unwind index. This section is related to C++ exceptions, and is required even
       though exceptions are disabled with -fno-exceptions. */
    PROVIDE_HIDDEN(__exidx_start = .);
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > DDR
    PROVIDE_HIDDEN(__exidx_end = .);

//    . = ALIGN (4);
    /* Reserve some space for HAB CSF data */
    .hab.data (_start_image_add + MAX_IMAGE_SIZE) : ALIGN(4)
    {
        __hab_data = .;
        . += MAX_HAB_CSF_DATA_SIZE;
        . = ALIGN (32);
        __hab_data_end = .;
    } > DDR
    _image_size = __hab_data_end - _start_image_add;
    /* End of HAB reserved space (must place it before BSS section) */

    /* The .bss section comes after the hab data because it is not signed */
    .bss :
    {
        __bss_start__ = .;
        *(.shbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        *(.bss)
        __bss_end__ = .;
    } > DDR

    /* Region to contain exception handler stacks */
    .exc_stacks (NOLOAD) :
    {
        . += EXCEPTIONS_STACK_SIZE;
        top_of_stacks = .;
    } > DDR
    
    . = ALIGN (4);
    . += 8;
    
    /* define section for the malloc heap */
    .heap (NOLOAD) : ALIGN(32)
    {
        free_memory_start = .; /* malloc starts allocating from here */
        . += ORIGIN(DDR) + LENGTH(DDR) - .;
        free_memory_end = .;
    } > DDR

//    _end = .;
}
