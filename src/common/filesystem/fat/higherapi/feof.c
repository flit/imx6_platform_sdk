/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Feof.c $
 $Revision: 10 $                                       
 $Date: 9/13/03 12:22p $
 Description: Feof.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"

/*----------------------------------------------------------------------------
>  Function Name: int32_t Feof(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)Handle Number

   Outputs:       Returns EOF if end of file else number of bytes left in file

   Description:   Checks for the end of file condition
<
----------------------------------------------------------------------------*/
int32_t Feof(int32_t HandleNumber)
{
    int32_t BytesLeft;
    int32_t FileSize;

    if(HandleNumber > maxhandles)
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if(Handle[HandleNumber].HandleActive!=1)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    else
        FileSize = GetFileSize(HandleNumber);

    if((BytesLeft = (FileSize - Ftell(HandleNumber)))>0)
        return BytesLeft;
        
    return ERROR_OS_FILESYSTEM_EOF;
}

