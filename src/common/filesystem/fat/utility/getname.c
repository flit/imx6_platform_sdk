/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Getname.c $                                        
 $Revision: 2 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: Getname.c
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
>  Function Name:  int32_t GetnameW(uint8_t *filepath,int32_t currentPosition)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) current position

   Outputs:        Returns current position.
   
   Description:    This function copies the string from current position to the 
                   directory separator or null character in the file path to 
                   another string called name.Current position is set to next 
                   directory separator or to end of file path. (It considers the string as UNICODE)
----------------------------------------------------------------------------*/
int32_t GetnameW(uint8_t *filepath,int32_t currentPosition)
{
    int32_t word;
    while(1)
	{
	    word = FSGetWord(filepath, currentPosition);
		if(word =='/' || word =='\0')
		    break;
	    currentPosition+=2;
    }

    return (currentPosition);
}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Getname(uint8_t *filepath, int32_t currentPosition)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
				   2) current position

   Outputs:        Returns current position.
   
   Description:    This function copies the string from current position to the 
                   directory separator or null character in the file path to 
                   another string called name.Current position is set to next 
                   directory separator or to end of file path. (It considers the string as DBCS)
----------------------------------------------------------------------------*/
int32_t Getname(uint8_t *filepath, int32_t currentPosition)
{
    int Char;
    while(1)
	{
	    Char = GetChar(filepath,&currentPosition);
		if(Char =='/' || Char =='\0')
		    break;
    }

    return (currentPosition);
}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t GetDirnameW(uint8_t *filepath,int32_t currentPosition)

   FunctionType:   Reentrant

   Inputs:         1) pointer to filepath
                   2) current position

   Outputs:        Returns current position.
   
   Description:    This function copies the string from current position to the 
                   directory separator or null character in the file path to 
                   another string called name.Current position is set to next 
                   directory separator or to end of file path. (It considers the string as UNICODE)
----------------------------------------------------------------------------*/
int32_t GetDirnameW(uint8_t *filepath,int32_t currentPosition)
{
    int32_t word;
    while(1)
	{
	    word = GetCharW(filepath, &currentPosition);
		if(word =='/' || word =='\0')
		    break;
    }

    return (currentPosition);
}
