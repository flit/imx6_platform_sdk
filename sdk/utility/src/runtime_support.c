/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  system_util.c
 * @brief The system utility functions for the environment.
 *
 * @ingroup diag_util
 */

#include <reent.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include "uart/imx_uart.h"
#include "sdk.h"

//! Set this define to 1 to have _write() convert LF line endings to CRLF
#define CONVERT_LF_TO_CRLF 1

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

// Must redefine errno as an extern int according to newlib docs.
#undef errno
extern int errno;

//! @name Malloc heap extents
//! 
//! Defined in the linker script.
//@{
extern int free_memory_start;
extern int free_memory_end;
//@}

//! @name Environment
//@{
char * __env[1] = { 0 };
char ** environ = __env;
//@}

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

int _execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

int _fork()
{
    errno = EAGAIN;
    return -1;
}

/*!
 * @brief Check to see if a terminal device is connected or not.
 * @return 1 always to indicate a serial port exists always
 */
int _isatty(int fd)
{
    return 1;
}

int _open(const char *name, int flags, int mode)
{
    return -1;
}

/*!
 * @brief Close a file descriptor.
 * @retval  -1
 */
int _close(int fd)
{
    return -1;
}

/*!
 * @brief Move read/write pointer.
 * @return 0 is always returned as specified in the newlib documentation for a minimal implementation.
 */
off_t _lseek(int fd, off_t offset, int whence)
{
    return (off_t)0;
}

/*!
 * @brief Get status of a file.
 *
 * @return 0 is always returned as specified in the newlib documentation for a minimal implementation.
 */
int _fstat(int fd, struct stat * st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

/*!
 * @brief Read characters from the serial port.
 *
 * It reads up to nbytes data or till a new line (someone hits enter).
 *
 * @param   fd      not used
 * @param   buf     pointer to the buffer for the receiving characters via serial port
 * @param   nbytes  Maximum number of characters that can be received.
 *
 * @return  the number of characters actually read
 */
int _read(int fd, char *buf, int nbytes)
{
    int i = 0;

    for (i = 0; i < nbytes; ++i, ++buf)
    {
        *buf = uart_getchar(&g_debug_uart);

        if ((*buf == '\n') || (*buf == '\r'))
        {
            ++i;
            break;
        }
    }

    return i;
}

/*!
 * @brief Write chars to the serial port.
 *
 * Ignore fd, since stdout and stderr are the same.
 * Since we have no filesystem, open will only return an error.
 *
 * If the #CONVERT_LF_TO_CRLF macro is set to 1, this function will convert any single
 * LF chars into CRLF pairs.
 *
 * @param   fd      not used
 * @param   buf     pointer to the buffer of data to the serial port
 * @param   nbytes  number of bytes to write to the serial port
 * @return  number of bytes to write to the serial port
 */
int _write(int fd, char *buf, int nbytes)
{
    int i;

    for (i = 0; i < nbytes; ++i, ++buf)
    {
#if CONVERT_LF_TO_CRLF
        static bool lastCharWasCR = false;
        
        // Insert a CR before the LF, unless the previous char in the source
        // buffer was a CR. This is to prevent converting a CRLF to CRCRLF.
        if (*buf == '\n' && !lastCharWasCR)
        {
            uint8_t cr = '\r';
            uart_putchar(&g_debug_uart, &cr);
        }
#endif // CONVERT_LF_TO_CRLF
        
        // Send the char out the debug UART.
        uart_putchar(&g_debug_uart, (uint8_t *)buf);
        
#if CONVERT_LF_TO_CRLF
        lastCharWasCR = (*buf == '\r');
#endif // CONVERT_LF_TO_CRLF
    }

    return nbytes;
}

/*!
 * @brief The low level system call upon which malloc is built.
 *
 * Here is a very simple implementation. The heap ranges from the variables
 * @i free_memory_start to @i free_memory_end that must be defined in the linker
 * script. Allocation starts at @i free_memory_start.
 *
 * If we run out of memory, a message is printed and abort() is called.
 *
 * @param   nbytes  the number of bytes to be allocated from the heap
 * @return  the previous heap address
 */
caddr_t _sbrk(int nbytes)
{
    static caddr_t heap_ptr = NULL;
    caddr_t base;

    if (heap_ptr == NULL)
    {
        heap_ptr = (caddr_t)&free_memory_start;
    }

    base = heap_ptr;
    heap_ptr += nbytes;
    
    // Abort if we run out of memory.
    if (heap_ptr > (caddr_t)&free_memory_end)
    {
        _write(1, "** Heap ran out of memory! **\n", 24);
        abort();
    }
    
    return base;
}

__attribute__ ((noreturn)) void _exit(int status)
{
    _sys_exit(status);
    while (1) ;
}

int _kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

pid_t _getpid()
{
    return 1;
}

int _link(char *old, char *new)
{
    errno = EMLINK;
    return -1;
}

int _unlink(char *name)
{
    errno = ENOENT;
    return -1; 
}

int _stat(const char *file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

clock_t _times(struct tms *buf)
{
    return -1;
}

int _gettimeofday(struct timeval *ptimeval, void *ptimezone)
{
    errno = EINVAL;
    return -1;
}

int _wait(int *status)
{
    errno = ECHILD;
    return -1;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////


    
