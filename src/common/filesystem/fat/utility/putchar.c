/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Putchar.c $                                        
 $Revision: 3 $                                       
 $Date: 9/23/03 10:15a $                                           
 Description: PutChar.c
 Notes:	This file read provides utility function to put a character into the given string. 
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
>  Function Name: void PutChar(uint8_t *Buffer,int32_t *offset,int32_t Char)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to Buffer
                  2) Offset 
				  3) Char
                  
   Outputs:       Nil
   
   Description:   This function puts a character in the given string at given offset 
                  and updates the offset accordingly. 
----------------------------------------------------------------------------*/
void PutChar(uint8_t *Buffer,int32_t *offset,int32_t Char)
{
    PutByte(Buffer,Char,*offset);
	*offset =*offset +1;
}       	

/*----------------------------------------------------------------------------
>  Function Name: void PutCharW(uint8_t *Buffer,int32_t *offset,int32_t Char)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to Buffer
                  2) Offset 
				  3) Char
                  
   Outputs:       Nil
   
   Description:   This function puts a word in the given Unicode string at given offset 
                  and updates the offset accordingly. 
----------------------------------------------------------------------------*/
void PutCharW(uint8_t *Buffer,int32_t *offset,int32_t Char)
{
    PutWord(Buffer,Char,*offset);
    //PutByte(Buffer,Char,*offset);
	*offset =*offset +2;
}       	
