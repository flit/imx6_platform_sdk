/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Extractfilename.c $                                        
 $Revision: 6 $                                       
 $Date: 9/16/03 3:49p $                                           
 Description: Extractfilename.c
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
>  Function Name:  int32_t Extractfilename(uint8_t *filepath,int32_t strlength,int32_t *index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filepath
                   2) String length
                   3) Index

   Outputs:        Returns String length
   
   Description:    This function copies the string from last directory separator 
                   to end of file to another string called filename.
----------------------------------------------------------------------------*/
int32_t Extractfilename(uint8_t *filepath,int32_t strlength,int32_t *index)
{
    int32_t currentposition=*index,strlen=0;
   
 	while(currentposition  < strlength)
	{
        strlen	= currentposition;
	    currentposition  = Getname(filepath,currentposition); 
    }
	  		
	return strlen;
}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Extractfilenamew(uint8_t *filepath, int32_t *index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filepath
                   2) Pointer to index

   Outputs:        Returns string length
   
   Description:    This function copies the string from last directory separator 
                   to end of file to another string called filename. It considers
				   the file name in UNICODE.
<
----------------------------------------------------------------------------*/
int32_t Extractfilenamew(uint8_t *filepath, int32_t *index)
{
    int32_t word, strlen;
    int32_t i;

    strlen = StrlengthW(filepath);
    
    // StrlenthW returns in terms of number of Wide characters = 2 bytes per character. 
    i = strlen<<1;
    
    while(i >*index)
	{
	    word = FSGetWord(filepath, i);
		if( word =='/')
		{
		    i+=2;
		    break;
		}
	    i-=2;
	}
  
    return i;
}
/*----------------------------------------------------------------------------
>  Function Name:  int32_t Extractdirnamew(uint8_t *filepath,int32_t strlength,int32_t *index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filepath
                   2) String length
                   3) Index

   Outputs:        Returns String length
   
   Description:    This function copies the string from last directory separator 
                   to end of file to another string called filename.
----------------------------------------------------------------------------*/
int32_t Extractdirnamew(uint8_t *filepath,int32_t strlength,int32_t *index)
{
    int32_t currentposition=*index,strlen=0;
   
 	while(currentposition  < strlength)
	{
        strlen	= currentposition;
	    currentposition  = GetDirnameW(filepath,currentposition); 
    }
	  		
	return strlen;
}
       	
