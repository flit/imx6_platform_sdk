/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fgets.c $
 $Revision: 4 $                                       
 $Date: 9/13/03 12:23p $
 Description: Fgets.c
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
>  Function Name: uint8_t *Fgets(int32_t HandleNumber,int32_t NumBytesToRead,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Number of Bytes to Read
                  3)Pointer to Buffer 

   Outputs:       Returns pointer to buffer containing string else Null Pointer.

   Description:   Reads the string from file.
<
----------------------------------------------------------------------------*/
uint8_t *Fgets(int32_t HandleNumber, int32_t NumBytesToRead, uint8_t *Buffer)
{
    int i;
    RtStatus_t RetValue;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return (uint8_t *)0;

    if((RetValue = Handleactive(HandleNumber))<0)
        return (uint8_t *)0;

    for(i=0; i < NumBytesToRead; i++)
    {
        if((RetValue = Fgetc(HandleNumber)) < 0)
            return (uint8_t *)0;
        PutByte(Buffer,RetValue,i);
        if( RetValue=='\n')
        {
            PutByte(Buffer,0,i+1);
            return Buffer;
        }
    }    
    PutByte(Buffer,0,i);
    return Buffer;
}
