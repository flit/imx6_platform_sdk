/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Changepath.c $
 $Revision: 7 $
 $Date: 9/17/03 10:19a $
 Description: Changepath.c
 Notes:	This file read provides higherlevel API function to Changepath
-----------------------------------------------------------------------------*/

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
#include <stdlib.h>

#undef FS_USE_MALLOC    // fix for sdk-4470

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Changepath(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t startposition,int32_t index)

   FunctionType:   Reentrant

   Inputs:         1) Handle number
                   2) Pointer to file name
				   3) string type
                   4) start position
                   5) index

   Outputs:        Returns ERROR_OS_FILESYSTEM_FILE_FOUND  if the file is found otherwise ERROR_OS_FILESYSTEM_FILE_NOT_FOUND

   Description:    This function searches for file or directory in the directory
                   identified by the given file handle. Every time when directory
                   within the file path is found the handle is updated according
                   to the directory record.
----------------------------------------------------------------------------*/
RtStatus_t Changepath(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t startposition,int32_t index)
{
    int32_t strlength,length;
    int32_t clusterno=0;
    int32_t currentposition = index;
    int32_t RecordNum=0;
#ifdef FS_USE_MALLOC
    uint8_t * Buffer;
    Buffer = malloc(512*sizeof(uint8_t));
    if( NULL == Buffer ) {
        return ERROR_OS_FILESYSTEM_MEMORY;
    }
#else
    uint8_t Buffer[512];
#endif

    if(stringtype == kDBCSEncoding)
	{
	    strlength = startposition;
	    while(currentposition  < strlength)
	    {
	        length = Getname(filepath,currentposition);
            // Modified by SGTL_HK
		    //if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer)) >=0)
		  //if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer,FALSE)) >=0)
           // fam:removing SGTL_HK code and restoring good old code
            if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer,0,&RecordNum)) >=0)
		    {
		        currentposition= length;
		        if(currentposition < strlength)
                {
     		        UpdateHandle(HandleNumber,clusterno);
                }
		    }
		    else
            {
#ifdef FS_USE_MALLOC
                free(Buffer);
#endif
		        return(ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
            }
	    }
	}

    if(stringtype == kUTF16Encoding)
    {
	    strlength = startposition;
	    while(currentposition  < strlength)
	    {
	        length = GetnameW(filepath,currentposition);
		    // Modified by SGTL_HK
            //if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer))>=0)
		    //if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer,FALSE)) >=0)
           // fam:removing SGTL_HK code and restoring good old code
            if((clusterno= Searchdirectory(HandleNumber,filepath,stringtype,1,length,currentposition,Buffer,0,&RecordNum))>=0)
		    {
		        currentposition= length;
		        if(currentposition  < strlength)
                {
     		        UpdateHandle(HandleNumber,clusterno);
                }
		    }
		    else
            {
#ifdef FS_USE_MALLOC
                free(Buffer);
#endif
		        return(ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
            }
		    currentposition =currentposition +2;
	    }
    }

#ifdef FS_USE_MALLOC
    free(Buffer);
#endif
    return ((RtStatus_t)clusterno);

}








