/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(startup_imx6x)

MEMORY
{
    DDR (rwx) : ORIGIN = 0x10000000, LENGTH = 1024M
}

SECTIONS
{
    _start_image_add = ORIGIN(DDR);

    .vectors :
    {
        __vectors_start = .;
        *o(.vectors)
        __vectors_end = .;
    }>DDR

    . = ALIGN (4);
    .text : 
    {
         *(.text)
    }

    . = ALIGN (4);
    .data :
    {
        *(.data)
    }

    . = ALIGN (4);
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
