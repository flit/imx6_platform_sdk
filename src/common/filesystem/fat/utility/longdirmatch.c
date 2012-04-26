/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/LongdirMatch.c $                                        
 $Revision: 9 $                                       
 $Date: 10/01/03 2:23p $                                           
 Description: Longdirmatch.c
 Notes:	This file read provides utility function to match long directory record
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
#include "DirOffset.h" 

/*----------------------------------------------------------------------------
		Global Declarations
----------------------------------------------------------------------------*/
void UnicodeToOEM(uint8_t *file,uint8_t *shortname,int32_t length,int32_t index);
/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Longdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,int32_t index,int32_t length, int32_t stringtype)

   FunctionType:   Reentrant

   Inputs:         1) Handle Number
                   2) Record Number
				   3) Pointer to file name
                   4) Index
                   5) Length
                   6) String Type 

   Outputs:        Returns ERROR_OS_FILESYSTEM_FILE_FOUND if directory or file name matches else ERROR_OS_FILESYSTEM_FILE_NOT_FOUND
      
   Description:    This function first decrements the record no. and then reads the directory record 
                   for this record no. and then it matches the directory or file name with the 
                   directory record in the buffer word by word. If long name matches then returns 
                   ERROR_OS_FILESYSTEM_FILE_FOUND else returns ERROR_OS_FILESYSTEM_FILE_NOT_FOUND. 
>
----------------------------------------------------------------------------*/
RtStatus_t Longdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,int32_t index,int32_t length, int32_t stringtype)
{
    int32_t offset, wordno=0,filenameword,word,firstword,secondword, strlen;
    uint8_t buf[32];
    int32_t shortname[12];  
    int64_t NumBytesRead;
    int32_t LongDirEnd=0;

    offset = DIRRECORDSIZE;
	wordno= index;
    
    firstword = FSGetWord(file,offset);
    secondword = FSGetWord(file,(offset+2));

    strlen =  length-index;
 
    if(firstword == 0x2e && secondword == 0x2e && strlen ==2)
    {
	    UnicodeToOEM((uint8_t*)file,(uint8_t*)shortname,4,0);
        return (Shortdirmatch(HandleNumber,RecordNo,(uint8_t*)shortname,(uint8_t*)shortname,buf,0,0,3,0));
    }

    else
    {
        while(wordno<length) 
        {
            if (offset ==  DIRRECORDSIZE)
	        {
	            RecordNo--;
                NumBytesRead = ReadDirectoryRecord(HandleNumber,RecordNo,buf);
			//This will take care that we have reached the last record of long directory structure
			//LongDirEnd will be used later
			if( FSGetByte(buf,0) & 0x40)
				LongDirEnd=1;
			else
				LongDirEnd=0;
                offset = LDIRNAME1OFFSET;
	        }

		    word=FSGetWord(file,wordno);  
			wordno+=2;

            filenameword = FSGetWord(buf,offset);
		 	if (word != filenameword) 
			{
                filenameword = Changecase(filenameword);
			    if (word != filenameword)
				    return (ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
			}
		   	offset = offset + 2;
			/* if all words of longdir firstname field are occupied, check for 
			longdir secondname field */
	        if (offset ==   LDIRATTRIOFFSET)
		        offset  =  LDIRNAME2OFFSET ;
	      
			/* if all words of longdir secondname field are occupied, check for 
			longdir thirdname field */
	      	if(offset ==  LDIRFSTCLUSNOOFFSET)
		        offset = LDIRNAME3OFFSET ;
 
 	        /* if all words of longdir thirdname field are occupied, check for 
 	        next sub component of longdir entry */
        } // while(wordno<length)
           
    }
           
    /* check whether the file name found is correct or not */
    /* check whether the word at this offset is 00 or not */
              
    if (offset !=  DIRRECORDSIZE)
    {
        if(FSGetByte(buf,offset) != 0x00)
            return (ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
    }
    	RecordNo--;
	//We have compared the name corectly, just check if we are at the end of the long directory name?
	//If yes we found the name correctly else return error as we encountered similar name
	if((RecordNo>=0) && (LongDirEnd==0))
	   		return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;

	               
    (void)NumBytesRead;
    return (ERROR_OS_FILESYSTEM_FILE_FOUND);
}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Changecase(int32_t filenameword)

   FunctionType:   Reentrant

   Inputs:         filenameword
   
   Outputs:        filenameword
      
   Description:    Changes the case 
----------------------------------------------------------------------------*/
int32_t Changecase(int32_t filenameword)
{
    if (filenameword>=97 && filenameword <= 122)
	    filenameword = filenameword - 32;
    else if (filenameword>=65 && filenameword <= 90)
	    filenameword = filenameword + 32;
    return (filenameword);
} 
