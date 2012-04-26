/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Chdir.c $                                        
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
>  Function Name:  RtStatus_t Chdir(uint8_t *filepath)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
				   
   Outputs:        SUCCESS or error code if error occurs      
   
   Description:    Searches for the given directoy path and if the path is found 
                   then changes the current working directoy to the given directory path 
----------------------------------------------------------------------------*/
RtStatus_t Chdir(uint8_t *filepath)
{
    uint32_t HandleNumber=0,strlen; 
    RtStatus_t Retval;
    int32_t clusterno=0;
    int32_t RecordNo;
    int32_t Dir_Attr;  
#ifdef CWD_STRING
    uint32_t Firstchar,secondchar;
    int32_t offset=0,currentposition=0, offset_dest=0;
#endif
    int index=0;
    uint8_t buf[32];

	/* Take temporary(directory)handle for searching the directory by changing path */
    HandleNumber = DIRECTORY_HANDLE; 

    /* if the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
	    return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
    Handle[HandleNumber].HandleActive = 1;
  
	/* first set the handle for search */
    if((Retval = SetHandleforsearch(HandleNumber,filepath,kDBCSEncoding,&index))<0)
	{
        Freehandle(HandleNumber);
	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
    }

    if(Retval != END_OF_DIR_PATH)
	{
        strlen = Strlength(filepath);
   	    /* Change the path to the specified path given */
	    if((clusterno =  Changepath(HandleNumber,filepath,kDBCSEncoding,strlen,index)) <0)
        {
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
        }
     	UpdateHandle(HandleNumber,clusterno);
    }
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
    
	    /* set the handle to original position */
	    if (Handle[HandleNumber].StartingCluster != 0)
		{
	        if((Retval= Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR))<0)
		        return Retval;
		}
    }
    /* copy the handle to handle 0 to change the current working directory */
    Handle[0]=Handle[HandleNumber];
    
	/* Free the handle used for file search */
    Freehandle(HandleNumber);
#ifdef CWD_STRING   
	currentposition=Strlength((uint8_t *)gCurrentWorkingdirectory);
    
    /* set the gCurrentWorkingdirectory buffer to the changed directory */
   	offset= 0;
    Firstchar = GetChar(filepath,&offset);
	secondchar = GetChar(filepath,&offset);
	strlen =  Strlength( filepath);
	if(secondchar == ':')
	{
        // Need to copy three Null terminating characters.  That is the
        // reason for strlen+2 and not strlen. This causes code that sees cwd as either ASCII or UTF-16
        // to see the same end of string.
	    Strcpy(filepath,(uint8_t *)gCurrentWorkingdirectory,strlen+2,0);
        return (SUCCESS); 
	}

    else if(Firstchar == '/')
	{
	    PutChar((uint8_t *)gCurrentWorkingdirectory,&offset,0);
	    currentposition=Strlength((uint8_t *)gCurrentWorkingdirectory);
	}
	
	else if(Firstchar == '.')
	{
	    if(secondchar != '.')
	    {
     	    currentposition=Strlength((uint8_t *)gCurrentWorkingdirectory);
	    }
	    else
	    {
	        offset=0;
		    currentposition=0;
	        strlen=Strlength((uint8_t *)gCurrentWorkingdirectory);
	        while(Firstchar == '.' && secondchar == '.')
	        {
                strlen = Extractfilename((uint8_t *)gCurrentWorkingdirectory,strlen,&currentposition);
	            if((ExtractPath(filepath,&offset)) == END_OF_DIR_PATH)
                    break;
                offset_dest = offset;
                Firstchar = GetChar(filepath,&offset_dest);
	            secondchar = GetChar(filepath,&offset_dest);
		    }
		    index=offset;
     	    currentposition=strlen-1;
 	    }
    }
        
	Setcwd(filepath, (uint8_t *)gCurrentWorkingdirectory,index,currentposition);
#endif    
	return (SUCCESS); 
}


	 




		







			 




			 
