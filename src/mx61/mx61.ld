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
    DDR (rwx) : ORIGIN = 0x80000000, LENGTH = 1024M
}

SECTIONS
{
    .vectors :
    {
        __vectors_start = .;
        *o(.vectors)
        __vectors_end = .;
    }>DDR

    .text :
    {
        . = ALIGN (4);
        *(.text)
    }

    .data :
    { *(.data) }

    .bss :
    {
        . = ALIGN (4);
        __bss_start__ = .;
        *(.shbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        __bss_end__ = .;
    }

    . += 10K;

    top_of_stacks = .;
    . = ALIGN (4);
    . += 8;
    free_memory_start = .;

    _end = .;
    __end = _end;
}
