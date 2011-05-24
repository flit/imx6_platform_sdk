/*
 * Copyright (C) 2010, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  sys.c
 * @brief The system utility functions for the diagnostics environment.
 *
 * @ingroup diag_util
 */

#include <stdio.h>
#include <time.h>
#include "io.h"
#include "hardware.h"

#define TRUE 1
#define FALSE 0

/* Following are defined in uart.c */
void sendchar(unsigned char *ch);

/*!
 * __backspace must return the last char read to the stream
 * fgetc() needs to keep a record of whether __backspace was
 * called directly before it
 */
int last_char_read;
int backspace_called;

/*!
 * Put a char to a serial port
 *
 * @param	ch	char to send
 * @param	f	no use
 * @return  same as the char just sent
 */
int fputc(int ch, FILE * f)
{
    unsigned char tempch = ch;

    sendchar(&tempch);

    return ch;
}

/*!
 * Get a char from a serial port
 * @param	f	no use
 * @return  the char received through serial port
 */
int fgetc(FILE * f)
{
    unsigned char tempch;

    /* if we just backspaced, then return the backspaced character */
    /* otherwise output the next character in the stream */
    if (backspace_called == TRUE) {
        backspace_called = FALSE;
        return last_char_read;
    }

    tempch = receive_char();
    last_char_read = (int)tempch;   /* backspace must return this value */
    return tempch;
}

/*!
 * This function writes a character to the console which is the same as the serial port here.
 * @param   ch  character to send to serial port
 */
void _ttywrch(int ch)
{
    unsigned char tempch = ch;

    sendchar(&tempch);
}

/*!
 * The low level system call upon which malloc is built.
 * Here is a very simple implementation. We don't even check for exceeding available memory.
 * @param   nbytes  the number of bytes to be allocated from the heap
 * @return  the previous heap address
 */
caddr_t _sbrk(int nbytes)
{
    static caddr_t heap_ptr = NULL;
    caddr_t base;

    if (heap_ptr == NULL) {
        extern int free_memory_start;   //Defined in the linker script.
        heap_ptr = (caddr_t) & free_memory_start;
    }

    base = heap_ptr;
    heap_ptr += nbytes;
    return base;
}

/*!
 * Check to see if a terminal device is connected or not.
 * @param   fd  not used
 * @return 1 always to indicate a serial port exists always
 */
int _isatty(int fd)
{
    return 1;
}

/*!
 * Close a file descriptor.
 * @param   fd  not used
 * @return  0 always to indicate successful.
 */
int _close(int fd)
{
    return 0;
}

/*!
 * Move read/write pointer. Since a serial port is non-seekable, we return -1 as error always.
 */
off_t _lseek(int fd, off_t offset, int whence)
{
    return (off_t) - 1;
}

/*!
 * Get status of a file. Since we have no file system, we just return an error.
 * @param   fd      not used
 * @param   buf     not used
 * @return  -1 always
 */
int _fstat(int fd, struct stat *buf)
{
    return -1;
}

/*!
 * This function read characters from the serial port. It reads up to nbytes data or
 * till a new line (someone hits enter).
 *
 * @param   fd      not used
 * @param   buf     pointer to the buffer for the receiving characters via serial port
 * @param   nbytes  number of characters plan to receive
 *
 * @return  the number of characters actually read
 */
int _read(int fd, char *buf, int nbytes)
{
    int i = 0;

    for (i = 0; i < nbytes; i++) {
        *(buf + i) = fgetc(NULL);

        if ((*(buf + i) == '\n') || (*(buf + i) == '\r')) {
            (*(buf + i)) = 0;
            break;
        }
    }

    return i;
}

/*!
 * Write chars to the serial port. Ignore fd, since stdout and stderr are the same.
 * Since we have no filesystem, open will only return an error.
 *
 * @param   fd      not used
 * @param   buf     pointer to the buffer of data to the serial port
 * @param   nbytes  number of bytes to write to the serial port
 * @return  number of bytes to write to the serial port
 */
int _write(int fd, char *buf, int nbytes)
{
    int i;

    for (i = 0; i < nbytes; i++) {
        if (*(buf + i) == '\n') {
            fputc('\r', NULL);
        }

        fputc(*(buf + i), NULL);
    }

    return nbytes;
}

/*!
 * Exception signaling and handling for C lib functions. This function never returns.
 * @param    return_code     not used
 */
void _sys_exit(int return_code)
{
    // just put system into WFI mdoe
    __asm volatile ("mov r1, #0x0\n\t" "mcr p15, 0, r1, c7, c0, 4\n\t");

    while (1) ;
}

/*!
 * breakpoint function
 */
void mybkpt(void)
{
    __asm volatile ("BKPT #0\n\t" "BX lr\n\t");
}

/*!
 * This function waits for an input char to be received from the UART. Once a char is received,
 * it tests against the passed in char and return 0 if they don't match. 
 * It is mostly used before conducting each test.
 * @param   c   the input character to be expected (NOT case sensitive)
 * @return  0   if input char doesn't match with c
 *          non-zero otherwise
 */
int is_input_char(u8 c)
{
    u8 input, lc, uc;

    if (c >= 'A' && c <= 'Z') {
        uc = c;
        lc = c - 'A' + 'a';
    } else if (c >= 'a' && c <= 'z') {
        lc = c;
        uc = c - 'a' + 'A';
    } else {
        printf("Error: not a valid letter: %c\n", c);
        return 0;
    }
    printf("Please enter %c or %c to confirm\n", lc, uc);
    do {
        input = receive_char();
    } while (input == NONE_CHAR);
    printf("input char is: %c\n", input);

    if ((input == uc) || (input == lc))
        return 1;
    else
        return 0;
}
