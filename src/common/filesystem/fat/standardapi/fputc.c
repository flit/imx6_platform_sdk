/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fputc.c $
 $Revision: 7 $                                       
 $Date: 9/18/03 6:50p $
 Description: Fputc.c
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
>  Function Name: int32_t Fputc(int32_t HandleNumber,int32_t ByteToWrite)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Byte to Write

   Outputs:       Returns Byte Written or EOF or an Error Code if  Error Occurs

   Description:   Writes the Byte to file 
<
----------------------------------------------------------------------------*/
int32_t Fputc(int32_t HandleNumber,int32_t ByteToWrite)
{
    int32_t RetValue = SUCCESS;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if((RetValue = Handleactive(HandleNumber))<0)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if((RetValue = (RtStatus_t)Fwrite(HandleNumber,(uint8_t *)&ByteToWrite,1)) <= 0)
        return ERROR_OS_FILESYSTEM_EOF;

    //! todo - what does the following line do?
    (void)RetValue;    
    return ByteToWrite;
}

