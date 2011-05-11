/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(startup)

MEMORY
{
    DDR (rwx) : ORIGIN = 0x75000000, LENGTH = 512M
}

SECTIONS
{
    .vectors :
    {
        __vectors_start = .;
        *o(.vectors)
        __vectors_end = .;
    }>DDR

    /* OBDS tests to be run early */
    .test_launch_early :
    {
        . = ALIGN (4);
        __test_launch_early_start = .;
        KEEP(*(.test_launch_early))
	__test_launch_early_end = .;
    }
    /* most OBDS tests should be put in here */
    .test_launch :
    {
        . = ALIGN (4);
        __test_launch_start = .;
        KEEP(*(.test_launch))
	__test_launch_end = .;
    }
    /* OBDS tests to be run after most tests done */
    .test_launch_late :
    {
        . = ALIGN (4);
        __test_launch_late_start = .;
        KEEP(*(.test_launch_late))
	__test_launch_late_end = .;
    }

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
