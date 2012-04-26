/*---------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Setcwd.c $                                        
 $Revision: 2 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: Setcwd.c
 Notes:	
----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
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
>  Function Name:  RtStatus_t Setcwd(uint8_t *filepath, uint8_t *gCworkingDir,int32_t index,int32_t length)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) pointer to gCworkingDir
                   3) index - index into filepath to start copying from
                   4) length - index into gCworkingDir to start copying to
				   
   Outputs:        Returns SUCCESS or an error if function fails.
      
   Description:    This function copies first string(filepath) to second string(gCworkingDir).
<
----------------------------------------------------------------------------*/
RtStatus_t Setcwd(uint8_t *filepath, uint8_t *gCworkingDir,int32_t index,int32_t length)
{
    int Char,Strlen,j,offset=index;

    EnterNonReentrantSection();
	Strlen = Strlength(filepath)-index;
	if(Strlen <= 0)
    {
        // Terminate with three nulls so code that sees gCworkingDir as either ASCII or UTF-16
        // will always see the same end of string.
        PutByte(gCworkingDir,0,length);
        PutByte(gCworkingDir,0,length+1);
        PutByte(gCworkingDir,0,length+2);
        
        LeaveNonReentrantSection();
        return SUCCESS;
    }

    if (length > 0)
    {
        Char = FSGetByte(gCworkingDir,length-1);
        if (Char != 0x2f)
        {
       	    PutByte(gCworkingDir,0x2f,length);
   	        length++;
        }
    }
   
    for(j = 0; j <= Strlen; j++)
	{
	    Char = GetChar(filepath,&offset);
		PutChar(gCworkingDir,&length,Char);
	}
    
    LeaveNonReentrantSection();
    return SUCCESS;
}
       	
/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t SetcwdW(uint8_t *filepath, uint8_t *gCworkingDir,int32_t index,int32_t length)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) pointer to gCworkingDir
                   3) index
                   4) length
				   
   Outputs:        Returns SUCCESS or an error if function fails.
      
   Description:    This function copies first Unicode string(filepath) to second string(gCworkingDir).
<
----------------------------------------------------------------------------*/
RtStatus_t SetcwdW(uint8_t *filepath, uint8_t *gCworkingDir,int32_t index,int32_t length)
{
    int Char,Strlen,j,offset=index;

    EnterNonReentrantSection();
	Strlen = StrlengthW(filepath);
    Strlen = Strlen-index;
    
	if(Strlen <= 0 && length >= 0)
    {
        // Terminate with three nulls so code that sees gCworkingDir as either ASCII or UTF-16
        // will always see the same end of string.
        PutByte(gCworkingDir,0,length);
        PutByte(gCworkingDir,0,length+1);
        PutByte(gCworkingDir,0,length+2);
        
        LeaveNonReentrantSection();
        return SUCCESS;
    }

    if (length > 0)
    {
        Char = FSGetByte(gCworkingDir,length-1);
        if (Char != 0x2f)
        {
       	    PutByte(gCworkingDir,0x2f,length);
   	        length++;
        }
    }
   
    for(j = 0; j <= Strlen; j++)
	{
	    Char = GetCharW(filepath,&offset);
		PutCharW(gCworkingDir,&length,Char);
	}
    
    LeaveNonReentrantSection();
    return SUCCESS;
}

      	
