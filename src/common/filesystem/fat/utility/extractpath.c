/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/ExtractPath.c $                                        
 $Revision: 3 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: ExtractPath.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t ExtractPathW(uint8_t *filepath,int32_t *index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filepath
                   2) Pointer to index
				   
   Outputs:        Returns SUCCESS or an error if function fails.
      
   Description:    This function copies the string from first directory separator(\\)
                   to the end of string to the same string. It considers the 
                   string as UNICODE.
<
----------------------------------------------------------------------------*/
int32_t ExtractPathW(uint8_t *filepath,int32_t *index)
{
    int32_t word,Strlen,k=0,offset=*index;

	Strlen = StrlengthW(filepath);
    while(1)
    {
 	    word = FSGetWord(filepath,offset);
 		if(word =='/' || word == '\0')
 		    break;
 	    offset+=2;
		k++;
    }
    *index = offset+2;
	if(k == Strlen)
	    return END_OF_DIR_PATH ;

    return SUCCESS;
}

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t ExtractPath(uint8_t *filepath,int32_t *index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filepath
                   2) Pointer to index
				   
   Outputs:        Returns SUCCESS or an error if function fails.

   Description:    This function copies the string from first directory separator(\\)
                   to the end of string to the same string. It considers the 
                   string as DBCS.
<
----------------------------------------------------------------------------*/
int32_t ExtractPath(uint8_t *filepath,int32_t *index)
{
    int32_t Strlen,offset=*index;
    int Char;
	Strlen = Strlength(filepath);
    while(1)
    {
 	    Char = GetChar(filepath,&offset);
 		if(Char =='/' || Char == '\0')
 		    break;
    }
    *index = offset;
    if(offset >= Strlen)
        return END_OF_DIR_PATH;

    return SUCCESS;
}
       	
