/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/DBCStoTwoByteString.c $                                        
 $Revision: 2 $                                       
 $Date: 9/23/03 10:08a $                                           
 Description: DBCStoTwoByteString.c
 Notes:	This file read provides utility function to convert the given DBCS string
        to two byte string. 
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
//#include <stdio.h>
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  void DBCStoTwoByteString(uint8_t *filename,uint8_t *string,int32_t length,int32_t index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to filename
                   2) Pointer to string 
                   3) Length
                   4) Index
                   
   Outputs:        Nil
      
   Description:    This function converts each character of the given string in two 
                   byte character and stores it in the second string.
<
----------------------------------------------------------------------------*/
void DBCStoTwoByteString(uint8_t *filename,uint8_t *string,int32_t length,int32_t index)
{
    int32_t Char,word=0;
    int i;
    int32_t offset=0,offset_dest=0;
    
	offset = index;
    for(i=index;i<length;i++)
	{
	    if((Char = GetChar(filename,&offset))<127)     //0x80
		{
	        word = 0;
		    PutByte((uint8_t *)&word,Char,0);
	   	}
	    else
	        word = Char;
	    PutWord(string,word,offset_dest); 
	    offset_dest+=2;	 
    } 	 
	PutWord(string,0,offset_dest); 
}       	
