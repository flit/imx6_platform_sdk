/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(startup)

MEMORY
{
    DDR (rwx) : ORIGIN = 0x10000000, LENGTH = 1024M
}

SECTIONS
{
    _start_image_add = ORIGIN(DDR);
       
    .ivt :
    {
        . = . + 0x400;
        *o(.ivt)
    } 
    
    .boot_data :
    {
        __start_boot_data = .;
        *o(.boot_data)
    } 
    
    .dcd_hdr :
    {
        __start_dcd = .;
        *o(.dcd_hdr)
    }
    .dcd_wrt_cmd :
    {
        *o(.dcd_wrt_cmd)
    }
    .dcd_data :
    {
        *o(.dcd_data)
    }
    
    . = ALIGN (32);
    .vectors :
    {
        *o(.vectors)
    } 

    . = ALIGN (32);
    .text :
    {
         *(.text)
    }

    . = ALIGN (32);
    .data :
    {
        *(.data)
    }

    . = ALIGN (32);
    .rodata :
    {
        *(.rodata)
    }

    /* This section and the symbols are related to C++ exceptions, and seems to be required even
       though exceptions are disabled with -fno-exceptions. */
    __exidx_start = .;
    .ARM.exidx : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) }
    __exidx_end = .;

    . = ALIGN (4);
    __hab_data = .;
    . = . + 0x2000;
    __hab_data_end = .;
    _end_image_add = .;
    _image_size = _end_image_add - _start_image_add;

    .bss :
    {
        __bss_start__ = .;
        *(.shbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        *(.bss)
        __bss_end__ = .;
    }

    . += 40K;

    top_of_stacks = .;
    . = ALIGN (4);
    . += 8;
    free_memory_start = .;

    _end = .;
}
