/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Chdirw.c $                                        
 $Revision: 7 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Chdir.c
 Notes:	This file read provides higherlevel API function to change the current working directory
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
>  Function Name:  RtStatus_t Chdirw(uint8_t *filepath)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
				   
   Outputs:        SUCCESS or error code if error occurs      
   
   Description:    Searches for the given directoy path for UTF16 string and if the path is found 
                   then changes the current working directoy to the given directory path 
----------------------------------------------------------------------------*/
RtStatus_t Chdirw(uint8_t *filepath)
{
    uint32_t HandleNumber=0,strlen; 
    RtStatus_t Retval;
    int32_t clusterno=0;
#ifdef CWD_STRING
    int32_t Firstword,secondword;
    int32_t offset=0,currentposition=0, offset_dest=0;
#endif
    int index=0;
    uint8_t buf[32];
    int32_t RecordNo;
    int32_t Dir_Attr;  


	/* Take temporary(directory)handle for searching the directory by changing path */
    HandleNumber = DIRECTORY_HANDLE; 

    /* if the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
	    return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
    Handle[HandleNumber].HandleActive = 1;
  
	/* first set the handle for search */
    if((Retval = SetHandleforsearch(HandleNumber,filepath,kUTF16Encoding,&index))<0)
	{
        Freehandle(HandleNumber);
	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
    }

    if(Retval != END_OF_DIR_PATH)
	{
        strlen = StrlengthW((uint8_t *)filepath);
   	    /* Change the path to the specified path given */
	    if((clusterno =  Changepath(HandleNumber,filepath,kUTF16Encoding,strlen*2,index)) <0)
        {
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
        }
     	UpdateHandle(HandleNumber,clusterno);
    }
    /*Any one try to change the file without extension using chdir function then return error*/
    if(Retval != END_OF_DIR_PATH)
	{
        RecordNo =   Handle[HandleNumber].CurrentOffset >> 5;
        /* check the attribute if it is not a directory, return error */
	    if(ReadDirectoryRecord(HandleNumber,RecordNo,buf)<0)           
	    {												
            Freehandle(HandleNumber);
	         return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;           
	    }
	
        Dir_Attr = FSGetByte(buf,DIR_ATTRIBUTEOFFSET);
        if(!(Dir_Attr & DIRECTORY))
        {
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;	  
        }
    }    
    
    /* copy the handle to handle 0 to change the current working directory */
    Handle[0]=Handle[HandleNumber];
    
	/* Free the handle used for file search */
    Freehandle(HandleNumber);
#ifdef CWD_STRING   
	currentposition=StrlengthW((uint8_t *)gCurrentWorkingdirectory);
    
    /* set the gCurrentWorkingdirectory buffer to the changed directory */
   	offset= 0;
    Firstword = GetCharW(filepath,&offset);
	secondword = GetCharW(filepath,&offset);
	strlen =  StrlengthW( filepath);
	if(secondword == ':')
	{
	    Strcpyw(filepath,(uint8_t *)gCurrentWorkingdirectory,strlen*2,0);
        return (SUCCESS); 
	}

    else if(Firstword == '/')
	{
	    PutCharW((uint8_t *)gCurrentWorkingdirectory,&offset,0);
	    currentposition=StrlengthW((uint8_t *)gCurrentWorkingdirectory);
	}
	
	else if(Firstword == '.')
	{
	    if(secondword != '.')
	    {
     	    currentposition=StrlengthW((uint8_t *)gCurrentWorkingdirectory);
	    }
	    else
	    {
	        offset=0;
		    currentposition=0;
	        strlen=StrlengthW((uint8_t *)gCurrentWorkingdirectory);
            strlen+=strlen;
	        while(Firstword == '.' && secondword == '.')
	        {
                strlen=Extractdirnamew((uint8_t *)gCurrentWorkingdirectory,strlen,&currentposition);
	            if((ExtractPathW(filepath,&offset)) == END_OF_DIR_PATH)
                    break;
                offset_dest = offset;
	            Firstword = GetCharW(filepath,&offset_dest);
	            secondword = GetCharW(filepath,&offset_dest);
		    }
		    index=offset;
     	    currentposition=strlen-2;
 	    }
    }
	SetcwdW(filepath, (uint8_t *)gCurrentWorkingdirectory,index,currentposition);
#endif
	return (SUCCESS); 
}


	 




		







			 




			 
