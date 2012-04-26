///////////////////////////////////////////
//! \addtogroup fs_fat
//! @{
//
// Copyright (c) 2004-2006 SigmaTel, Inc.
//
//! \file frename.c
//! \brief Renames file with given name.
//!
//! This function replaces the old name
//! of given file with new name.
//!
///////////////////////////////////////////

#include <types.h>
#include <error.h>
#include <../os/filesystem/fat/include/fat_internal.h> //! \todo malinclusion
#include <os/fsapi.h> //! \todo malinclusion
#include <../os/filesystem/fat/include/platform.h> //! \todo malinclusion
#include <diroffset.h>
#include <stdlib.h>

///////////////////////////////////////////
//! \brief Renames a file or directory
//!
//! \fntype Function
//!
//! This function renames given file.  
//!
//! \param[in]  oldFilename
//! \param[in]  newFilename
//!
//! \return Status of call.
//! \retval 0      If no error has occurred
//!
///////////////////////////////////////////

int32_t Frename(uint8_t *oldFilename,uint8_t *newFilename)
{
    int32_t HandleNumber;
    int32_t RecordNo;
    int32_t strLength;
    int32_t index=0;
    int32_t currentposition=0;
    int32_t Retval; 
    uint8_t buf[32];
    int32_t clusterno;    
    int32_t clusterlo;
    int32_t clusterhi;
    int32_t DirAttr;
    int32_t FileSize;
    
#ifdef FS_USE_MALLOC
    uint8_t * UnicodeBuffer;
    UnicodeBuffer = malloc(MAX_UNICODE_SIZE*sizeof(uint8_t));
    if( NULL == UnicodeBuffer ) {
        return ERROR_OS_FILESYSTEM_MEMORY;
    }
#else
    uint8_t UnicodeBuffer[MAX_UNICODE_SIZE];    
#endif

    /* Search for free handle and allocate it */   
    if((HandleNumber = Searchfreehandleallocate())<0)  
    {
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
	    return(ERROR_OS_FILESYSTEM_NO_FREE_HANDLE);
	}
    
    /* set the handle for search */
    if(SetHandleforsearch(HandleNumber,(uint8_t *)oldFilename,kUTF16Encoding,&index) < 0)
    {
        Freehandle(HandleNumber);
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
   	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
	}	   
    
    strLength = StrlengthW((uint8_t *)oldFilename);
    
  	currentposition = Extractfilenamew((uint8_t *)oldFilename,&index);

 	/* Go to the specified directory level by changing the path */
   	if(currentposition!=index)
	{
        if((clusterno = Changepath(HandleNumber,(uint8_t *)oldFilename,kUTF16Encoding,currentposition,index)) <0)
        {
            Freehandle(HandleNumber);
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
	    }
        UpdateHandle(HandleNumber,clusterno);
    }
	    
    /* search for the specified file */
    if(currentposition==0)
        currentposition = index;
                 
    if((clusterno = Changepath(HandleNumber,(uint8_t *)oldFilename,kUTF16Encoding,strLength*2,currentposition))<0)
    {
        Freehandle(HandleNumber);
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
        return(ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
    }
    else
	{    
            
        /* Directory entry of file-name has been located.  Now, change file-name. */
        
        RecordNo = Handle[HandleNumber].CurrentOffset >> 5;
        
	    if(ReadDirectoryRecord(HandleNumber,RecordNo,buf)<0)
        {
            Freehandle(HandleNumber);        
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
            return(ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);        
        }        
        
        clusterlo = FSGetWord(buf, DIR_FSTCLUSLOOFFSET);
        
        clusterhi = FSGetWord(buf, DIR_FSTCLUSHIOFFSET);
        
        clusterno = (clusterhi << 16) | (clusterlo & 0xFFFF);
                      
        DirAttr = buf[DIR_ATTRIBUTEOFFSET];
                  
        FileSize = FSGetDWord((uint8_t *)buf,DIR_FILESIZEOFFSET);
        
        if (Handle[HandleNumber].StartingCluster != 0)
        {
		    if((Retval = Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR)))
            {
                Freehandle(HandleNumber);            
#ifdef FS_USE_MALLOC
                free(UnicodeBuffer);
#endif
			    return Retval;
            }
        }
                  
        /* Delete the directory record of the file.  Contents are
         * intact, and as long as new record references old
         * cluster number, all is well
         */        
        if((Retval=DeleteRecord(HandleNumber,RecordNo))<0)
	    {
	        Freehandle(HandleNumber);
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
    	    return Retval;
	    }
               			
        index = 0;
        
  	    currentposition = Extractfilenamew((uint8_t *)newFilename,&index);
                    
        strLength = StrlengthW((uint8_t *)newFilename);
                                    							          
        Retval = (int32_t)CreateDirRecord(newFilename, 
                                          HandleNumber, 
                                          clusterno, 
                                          DirAttr,
                                          kUTF16Encoding, 
                                          strLength*2, 
                                          currentposition, 
                                          (uint8_t *)UnicodeBuffer,
                                          FileSize);

    	if (Retval < 0)
    	{
            Freehandle(HandleNumber);
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
    		return Retval;
    	}                                                                                
        
    } /* else */

#ifdef FS_USE_MALLOC
    free(UnicodeBuffer);
#endif
    Freehandle(HandleNumber);	 
    
    FlushCache();
    
    return (0);
}

