/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Rmdirw.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Rmdirw.c
 Notes:	This file read provides higherlevel API function to remove a directory.
        It considers the string as UTF16.
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
>  Function Name: RtStatus_t Rmdirw(uint8_t *filepath)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name
				   
   Outputs:       SUCCESS or an error code if error occurs      
   
   Description:   Searches for the given directory and if it is found empty then
                  delete the directory. It considers the string as UTF16.
----------------------------------------------------------------------------*/
RtStatus_t Rmdirw(uint8_t *filepath)
{
    int32_t HandleNumber,RecordNo,index=0;  
    RtStatus_t Retval;
    int32_t dirsector,diroffset,dirStartcluster,Currentsector,Byteposinsec,Curoffset,SecPos;
    int32_t clusterno;
    int32_t Dir_Attr,Strlen;  
    uint8_t buf[32];
    

	/* Take temporary(directory) handle for searching the directory by changing path */
    HandleNumber = DIRECTORY_HANDLE; 

    /* If the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
	    return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
	Handle[HandleNumber].HandleActive = 1;
	/* first set the handle for search */
    if((Retval = SetHandleforsearch(HandleNumber,filepath,kUTF16Encoding,&index))<0)
	{
        Freehandle(HandleNumber);
	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
    }
    Strlen= StrlengthW(filepath);
    /* If directoy is root directory or parent directory then it can not be 
    removed. Return Error  */
    if((Retval == END_OF_DIR_PATH) || (Strlen==index))
	{
        Freehandle(HandleNumber);
	   	return ERROR_OS_FILESYSTEM_DIR_NOT_REMOVABLE;
    }

    /* Change the path to the specified path given */
    if((clusterno =  Changepath(HandleNumber,filepath,kUTF16Encoding,Strlen,index)) <0)
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;
    }
    RecordNo =   Handle[HandleNumber].CurrentOffset >> 5;
    /* check the attribute if it is not a directory, return error */
	if(ReadDirectoryRecord(HandleNumber,RecordNo,buf)<0)           
	{												
        Freehandle(HandleNumber);
	     return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;           
	}
	
    Dir_Attr = FSGetByte(buf,32);
    if(!(Dir_Attr & DIRECTORY))
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_FILE_DELETE_FAILED;	  
    }

    /* set the handle to original position */
    if (Handle[HandleNumber].StartingCluster != 0)
	{
        if((Retval= Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR))<0)
	        return Retval;
	}
    
    /* store the handle for deleting records */
    dirsector =  Handle[HandleNumber].DirSector;
    diroffset =  Handle[HandleNumber].DirOffset;
    dirStartcluster =  Handle[HandleNumber].StartingCluster;
    Currentsector = Handle[HandleNumber].CurrentSector;
    Byteposinsec = Handle[HandleNumber].BytePosInSector;  
    Curoffset = Handle[HandleNumber].CurrentOffset;
    SecPos = Handle[HandleNumber].SectorPosInCluster;
		     
    /* update the handle to associate with the directory to be deleted */
    UpdateHandle(HandleNumber,clusterno);
    /* check whether the directory is empty or not. If it is not empty, return error */
    if(Isdirectoryempty(HandleNumber) == ERROR_OS_FILESYSTEM_DIR_NOT_EMPTY)
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_DIR_NOT_EMPTY;
    } 

    /* check whether the directory is not current working directory. If it is, return error */
    if(IsCurrWorkDir(HandleNumber)<0)
	{
	    Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_CANNOT_DELETE_CWD;
	}
    /* Go one directory level up (directory to delete) */
	Handle[HandleNumber].DirSector= dirsector;
	Handle[HandleNumber].DirOffset = diroffset;
	Handle[HandleNumber].StartingCluster= dirStartcluster;
    Handle[HandleNumber].CurrentSector = Currentsector;
	Handle[HandleNumber].CurrentCluster = dirStartcluster;
    Handle[HandleNumber].BytePosInSector = Byteposinsec;
	Handle[HandleNumber].SectorPosInCluster = SecPos;
    Handle[HandleNumber].CurrentOffset = Curoffset;
    /* Delete the directory record */
    if((Retval=DeleteRecord(HandleNumber,RecordNo))<0)
	{
	    Freehandle(HandleNumber);
	    return Retval;
	}
    /* update the handle to associate with the directory to be deleted */
    UpdateHandle(HandleNumber,clusterno);
    /* Delete the contents of the directory (i.e. Mark all the clusters occupied by 
    the directory as zero in FAT Table). */
    if((Retval=DeleteContent(HandleNumber,0))<0)
	{
	    Freehandle(HandleNumber);
	    return Retval;
	}
    /* Free the handle used for file search */
    Freehandle(HandleNumber);
    return (SUCCESS); 
}
	 
