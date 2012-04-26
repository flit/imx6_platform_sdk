/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/CheckForValidRecord.c $
 $Revision: 3 $                                       
 $Date: 8/30/03 10:14a $
 Description: CheckForValidRecord.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "diroffset.h"

/*----------------------------------------------------------------------------
>  Function Name: int32_t FindValidFileRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer)

   FunctionType:  Non-Reentrant

   Inputs:        1)HandleNumber
                  2)RecordNumber
                  3)Pointer to buffer to store the string

   Outputs:       Returns Record Number or Error

   Description:   Finds the valid record from the given record number
<
----------------------------------------------------------------------------*/
int32_t FindValidFileRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer)
{   
    uint8_t Byte;

    while(1)
    {
        if(ReadDirectoryRecord(HandleNumber,RecordNumber,Buffer) <=0 )
            return ERROR_OS_FILESYSTEM_EOF;
        RecordNumber++;
        Byte = FSGetByte(Buffer,0);
        // Check if file is Erased or . or  .. Entry is there
        // e5/05 kanji fix
        if((Byte==0xE5) || (Byte=='.') || (Byte==0x05))
            continue;
        // Else check for Long Directory Name and skip
        else if(((Byte = FSGetByte(Buffer,DIR_ATTRIBUTEOFFSET)) & 0x0f)==0x0f)
            continue;
        // Check for directory attribute and skip
        else if(((Byte = FSGetByte(Buffer,DIR_ATTRIBUTEOFFSET)) & DIRECTORY)==DIRECTORY)
            continue;
        else    
        // first short name found
            break;
    }
    if(Byte = FSGetByte(Buffer,0) ==0x05)
        PutByte(Buffer,0xE5,0);
   				
    return RecordNumber;
}
