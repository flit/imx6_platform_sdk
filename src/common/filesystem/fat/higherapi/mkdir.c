/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Mkdir.c $                                        
 $Revision: 8 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Mkdir.c
 Notes:	This file read provides higherlevel API function to make(create) a new directory
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
>  Function Name: RtStatus_t Mkdir(uint8_t *filepath)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name
				   
   Outputs:       SUCCESS or an error code if error occurs      
   
   Description:   Searches for given directory path, if path is found then creates
                  given directory in the directoy path.
----------------------------------------------------------------------------*/
RtStatus_t Mkdir(uint8_t *filepath)
{
    int32_t HandleNumber,strlen1;
    RtStatus_t Retvalue;
    int index=0,currentposition=0;  
    int32_t clusterno;	
    int32_t byte,source_offset=0;       
    int32_t length;		          

	/* Take temporary(directory) handle for searching the directory by changing path */
    HandleNumber = DIRECTORY_HANDLE; 

    /* If the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
	    return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
    Handle[HandleNumber].HandleActive = 1;
   
	/* first search for the given directory */
    if(SetHandleforsearch(HandleNumber,filepath,kDBCSEncoding,&index)<0)
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	}
	length=Strlength(filepath);
    if(length==0)
        return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;    
    /*if at the end of dirname Directory separator(/)is found then discard it.*/
    source_offset=length-1;
    byte = GetChar((uint8_t *)filepath,&source_offset);        
	if(byte == 0x2f)
	{
        source_offset=length-1;
        PutChar((uint8_t *)filepath,&source_offset,0);         
    }
    strlen1 = Strlength(filepath);
    currentposition = Extractfilename(filepath,strlen1,&index);
   
   	/* Change the path to the specified path given */
   	if(currentposition !=index)
	{
        if((clusterno =  Changepath(HandleNumber,filepath,kDBCSEncoding,currentposition,index)) <0)
        {
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	    }
        UpdateHandle(HandleNumber,clusterno);
   	}
	/* remove this, not required, due to compiler problem*/
	index=0;
	/* create given directory in the directory referenced by the handle */
    // Modified by SGTL_HK 
    //if((Retvalue = CreateDirectory(HandleNumber,filepath,strlen1,currentposition))< 0)
    if((Retvalue = CreateDirectory(HandleNumber,filepath,strlen1,currentposition,kDBCSEncoding))< 0)  
	{
        Freehandle(HandleNumber);
	    return Retvalue;
	}
    /* Free the handle used for search */
    Freehandle(HandleNumber);
    return (SUCCESS); 
}


	 




		







			 




			 
