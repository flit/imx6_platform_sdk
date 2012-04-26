/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/ArrangeFileName.c $
 $Revision: 4 $                                       
 $Date: 9/13/03 12:19p $
 Description: ArrangeFileName.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <string.h>

#include <types.h>
#include <../os/filesystem/fat/include/fstypes.h> //! \todo malinclusion
#include <os/fsapi.h> //! \todo malinclusion
#include <error.h>
#include "platform.h"
#include "fat_internal.h"

/*----------------------------------------------------------------------------

>  Function Name:  void ArrangeFileName(uint8_t *Buffer,uint8_t *ShortNameDir)

   FunctionType:  Reentrant

   Inputs:        1)Pointer to file name or directory
                  2)Pointer to ShortName directory Buffer

   Outputs:       Nil

   Description:   Arranges the file name as short file name in 8+3 format
<
----------------------------------------------------------------------------*/
void ArrangeFileName(uint8_t *Buffer,uint8_t *ShortNameDir)
{
     int FName=0,i=0,j=0,Length=0;

     if((FName = FSGetByte(Buffer,0))!= 0x2e)
     {
        Uppercase((uint8_t*)Buffer);
		Length = Strlength((uint8_t*)Buffer);
		for(i=Length; i <12 ; i++)
		{
			PutByte(Buffer,i,0x20);
		}
	 }
     
     else
		 memcpy(ShortNameDir,Buffer,12);

     i=0;
     if(FName != 0x2e)
     {
         while((FName = FSGetByte(Buffer,i))!='\0')
         {
            if((i==0) && (FName == 0xe5))
			   FName=0x05;
             if(FName =='.')
             {
                i++;
                while((FName = FSGetByte(Buffer,i+j))!='\0')
                {
                    PutByte(ShortNameDir,FName,8+j);
                    j++;
                }
                break;
             }
             PutByte(ShortNameDir,FName,i);
             i++;
         }
     }
}

