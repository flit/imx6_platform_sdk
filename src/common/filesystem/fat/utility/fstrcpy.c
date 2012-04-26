/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Fstrcpy.c $                                        
 $Revision: 6 $                                       
 $Date: 9/13/03 5:46p $                                           
 Description: Fstrcpy.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <os/fsapi.h> //! \todo malinclusion
#include <error.h>
#include "platform.h"
#include "BootSecOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Strcpy(uint8_t *filepath, uint8_t *file_path1,int32_t length, int32_t index)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) pointer to file_path1
                   3) length
                   4) index
				   
   Outputs:        Returns SUCCESS or an error if function fails.
      
   Description:    This function copies the first string to second string.
<
----------------------------------------------------------------------------*/
RtStatus_t Strcpy(uint8_t *filepath, uint8_t *file_path1,int32_t length, int32_t index)
{
    int32_t Char,offset=index,offset_dest=0;
	while(offset < length)
	{
        Char = GetChar(filepath,&offset);
		PutChar(file_path1,&offset_dest,Char);
     	if(offset >(MAXFILENAME_CH-1))
		    break;
	}
	PutChar(file_path1,&offset_dest,0);

    return SUCCESS;
}

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Strcpyw(uint8_t *filepath, uint8_t *file_path,int32_t length,int32_t index)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) pointer to file_path
                   3) length
                   4) index
				   
   Outputs:        Returns SUCCESS or an error if function fails.

   Description:    This function copies the first string to second string.
				   It considers the string as UNICODE.
<
----------------------------------------------------------------------------*/
RtStatus_t Strcpyw(uint8_t *filepath, uint8_t *file_path,int32_t length,int32_t index)
{
    int32_t word,Strlen,offset=index,offset_dest=0;
    int j;
	Strlen = (length - index)>>1;
	
	if(Strlen > MAXFILENAME_CH)
	    Strlen = MAXFILENAME_CH;
   
    for(j = 0; j < Strlen; j++)
	{
	    word = FSGetWord(filepath,offset);
		PutWord(file_path,word,offset_dest);
		offset=offset +2;
		offset_dest=offset_dest +2;
    }
    PutWord(file_path,0,offset_dest);

    return SUCCESS;
}
