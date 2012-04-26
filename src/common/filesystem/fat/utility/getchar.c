/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Getchar.c $                                        
 $Revision: 3 $                                       
 $Date: 9/23/03 10:15a $                                           
 Description: GetChar.c
 Notes:	This file read provides utility function to get a character from the given string.
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
>  Function Name:  int32_t GetChar(uint8_t *Buffer,int32_t *offset)

   FunctionType:   Reentrant

   Inputs:         1) pointer to Buffer
                   2) offset 
                   
   Outputs:        Returns char of the given buffer at the given offset.
   
   Description:    This	function gets a character from the given string at the 
                   given offset and updates the offset accordingly.
<
----------------------------------------------------------------------------*/
int32_t GetChar(uint8_t *Buffer,int32_t *offset)
{
    int Char;
    Char = FSGetByte(Buffer,*offset);
	*offset =*offset +1;
    return Char;
}       	
/*----------------------------------------------------------------------------
>  Function Name:  int32_t GetCharW(uint8_t *Buffer,int32_t *offset)

   FunctionType:   Reentrant

   Inputs:         1) pointer to Buffer
                   2) offset 
                   
   Outputs:        Returns char of the given buffer at the given offset.
   
   Description:    This	function gets a word from the given Unicode string at the 
                   given offset and updates the offset accordingly.
<
----------------------------------------------------------------------------*/
int32_t GetCharW(uint8_t *Buffer,int32_t *offset)
{
    int Word;
    Word = FSGetWord(Buffer,*offset);
	*offset =*offset +2;
    return Word;
}       	
