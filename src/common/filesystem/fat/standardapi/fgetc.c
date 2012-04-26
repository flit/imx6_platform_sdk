/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fgetc.c $
 $Revision: 6 $                                       
 $Date: 9/18/03 7:10p $
 Description: Fgetc.c
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
>  Function Name: int32_t Fgetc(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns Byte read from file or EOF or an Error Code if  Error Occurs

   Description:   Reads the byte from file 
<
----------------------------------------------------------------------------*/
int32_t Fgetc(int32_t HandleNumber)
{
    int ReturnByte=0;
    RtStatus_t RetValue;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if((RetValue = Handleactive(HandleNumber))<0)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if((Feof(HandleNumber))==ERROR_OS_FILESYSTEM_EOF)
        return ERROR_OS_FILESYSTEM_EOF;
    
    if((RetValue = (RtStatus_t)(Fread(HandleNumber,(uint8_t *)&ReturnByte,1))) <= 0 )
        return RetValue;
    
    return ReturnByte;
}

