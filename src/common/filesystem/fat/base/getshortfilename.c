/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/getshortfilename.c $
 $Revision: 9 $                                       
 $Date: 9/18/03 6:49p $
 Description: getshortfilename.c
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
#include "diroffset.h"
#include <string.h>

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t GetShortfilename(int64_t Key,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)Key
                  2)Pointer to buffer

   Outputs:       Gets shortfilename from key
                  
<
//----------------------------------------------------------------------------*/
RtStatus_t GetShortfilename(int64_t Key,uint8_t *Buffer)
{
    int HandleNumber;
    uint8_t *buf;
    int32_t DirSector,DirOffset;
    uint8_t NameBuffer[36];
    int byte;
    int offset=0,offset_dest=0,j;
    uint32_t cacheToken;
    
    if((HandleNumber = Searchfreehandleallocate())<0)
    {
		return (RtStatus_t)HandleNumber;
    }
    
   	Handle[HandleNumber].Device = (int32_t)(( (Key >> 44) & 0x000000000000000F));
    DirSector = (Key & 0x00FFFFFFFF);
    DirOffset =	 (int32_t)((Key >> 32)& 0xFFF);
    Handle[HandleNumber].DirOffset = DirOffset;
    Handle[HandleNumber].DirSector = DirSector;
    
	EnterNonReentrantSection();
    if((buf = (uint8_t *)FSReadSector(Handle[HandleNumber].Device,DirSector,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
	{
        Freehandle(HandleNumber);
    	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}
	
    memcpy(NameBuffer, buf + DirOffset, DIRRECORDSIZE);
    
    FSReleaseSector(cacheToken);
    LeaveNonReentrantSection();
   
    byte = FSGetByte(NameBuffer,0);                    
	if(byte == 0x05)
    {
        PutByte(NameBuffer,0xe5,0);
	}
    
	while(offset<8)
	{
	    byte = GetChar((uint8_t*)NameBuffer,&offset);
		if(byte == 0x20)
        {
		    break;
        }
		PutChar((uint8_t*)Buffer,&offset_dest,byte);
    }

   PutChar((uint8_t*)Buffer,&offset_dest,'.');
   j=0;
   offset=8;
   while(offset<11)
   {
	    byte = GetChar((uint8_t*)NameBuffer,&offset);
		if(byte == 0x20)
		{
		    if((offset_dest<=9) && (j==0))
            {
		        offset_dest--; // i--;
            }
	        PutByte(Buffer,'\0',offset_dest);
		    break;
		}
		PutChar((uint8_t*)Buffer,&offset_dest,byte);
		j++;
   }
   PutByte(Buffer,'\0',offset_dest);
    
   Freehandle(HandleNumber);
   return SUCCESS;
}



