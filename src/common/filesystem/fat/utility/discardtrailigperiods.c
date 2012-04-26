/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/DiscardTrailigPeriods.c $
 $Revision: 2 $                                       
 $Date: 9/23/03 10:08a $
 Description: DiscardTrailigPeriods.c
 Notes:	This file read provides utility function to remove the trailing periods from 
        the given string.
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
>  Function Name: int32_t DiscardTrailigPeriods(uint8_t *Buffer,int32_t length,int32_t index,int32_t Flag)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to Buffer
                  2) Length
                  3) Index
                  4) Flag

   Outputs:       Returns length

   Description:   This function removes all the trailing periods from the given string. 
<
-----------------------------------------------------------------------------*/
int32_t DiscardTrailigPeriods(uint8_t *Buffer,int32_t length,int32_t index,int32_t Flag)
{
    int32_t Char, strlen, offset=index;
    int dotfound=0;   

	if(Flag)
	    strlen = length -1;
	else
	    strlen =  length;
	while(offset<strlen)
	{
	    Char = GetChar(Buffer,&offset);
	    if(Char == '.')
		{
		    dotfound++;
		}
		else
		{
		    dotfound =0;
		}
    }
	length = (length - dotfound);
  
    return length;
}		          

/*----------------------------------------------------------------------------
>  Function Name: int32_t  DiscardTrailigPeriodsw(uint8_t *Buffer,int32_t length,int32_t index)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to Buffer
                  2) Length
                  3) Index

   Outputs:       Returns length

   Description:   This function removes all the trailing periods from the given string. 
<                 It considers the string in UNICODE.
-----------------------------------------------------------------------------*/
int32_t  DiscardTrailigPeriodsw(uint8_t *Buffer,int32_t length,int32_t index)
{
    int32_t Char,offset=index;
    int dotfound=0;   

  	while(offset<length)
	{
	    Char = FSGetWord(Buffer,offset);
		if(Char == '.')
		{
		    dotfound++;
		}
		else 
		{
		    dotfound =0;
		}
	    offset+=2;
	}
	length = (length - (dotfound<<1));
    return length;
}     
