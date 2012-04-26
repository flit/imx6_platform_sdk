/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fputs.c $
 $Revision: 8 $                                       
 $Date: 9/13/03 12:23p $
 Description: Fputs.c
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
>  Function Name: uint8_t *Fputs(int32_t HandleNumber,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to Buffer

   Outputs:       Returns pointer to buffer on success else NULL Pointer

   Description:   Writes the string to the file
<
----------------------------------------------------------------------------*/
uint8_t *Fputs(int32_t HandleNumber,uint8_t *Buffer)
{
    int32_t  NumBytesToWrite,i;
    RtStatus_t RetValue = SUCCESS;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return (uint8_t *)0;

    if((RetValue = Handleactive(HandleNumber))<0)
        return (uint8_t *)0;

    NumBytesToWrite = Strlength((uint8_t *)Buffer);
    for(i=0; i < NumBytesToWrite;i++)
    {
        if((RetValue = Fputc(HandleNumber,FSGetByte(Buffer,i))) < 0)
            return (uint8_t *)0;
    }

    (void)RetValue;
    return Buffer;
}
