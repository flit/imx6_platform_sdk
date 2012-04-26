/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Fopenw.c $                                        
 $Revision: 6 $                                       
 $Date: 9/18/03 11:51a $                                           
 Description: Fopenw.c
 Notes:	This file read provides higherlevel API function to open a file. It considers
        the string as UTF16.
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
>  Function Name: int32_t Fopenw(uint8_t *filepath,uint8_t *mode)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name
                  2) Open mode 
				   
   Outputs:       HandleNumber of free handle populated by the given filename 
                  or error if function fails      
   
   Description:   Opens the specified file in specified mode. It considers
                  the string as UTF16.
<
----------------------------------------------------------------------------*/
int32_t Fopenw(uint8_t *filepath,uint8_t *mode)
{
    int32_t HandleNumber,RecordNo,strlen,index=0,currentposition=0;
    FileSystemModeTypes_t Mode;
    RtStatus_t Retval; 
    uint8_t buf[32];
    int32_t clusterno;
    
    int32_t clusterlo,clusterhi;
    
    /* set the Mode according to the mode given */
    if((mode[0]) == 'r')
	{
	    if((mode[1]) == '+')
	        Mode = RPLUS;
	    else
            Mode = READ_MODE;
	}
	else if((mode[0]) == 'w')
	{
	    if((mode[1]) == '+')
	        Mode = WPLUS;
	    else
	        Mode = WRITE_MODE;
	}
    else if((mode[0]) == 'a')
	{
	    if((mode[1]) == '+')
	        Mode = APLUS;
	    else
	        Mode = APPEND_MODE;
	}
	else
	    return ERROR_OS_FILESYSTEM_MODE_NOT_SUPPORTED;

    /* Search for free handle and allocate it */   
    if((HandleNumber = Searchfreehandleallocate())<0)
	    return(ERROR_OS_FILESYSTEM_NO_FREE_HANDLE);
	
    /* set the handle for search */
    if(SetHandleforsearch(HandleNumber,(uint8_t *)filepath,kUTF16Encoding,&index) < 0)
    {
        Freehandle(HandleNumber);
   	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	}
    strlen = StrlengthW((uint8_t *)filepath);
  	currentposition= Extractfilenamew((uint8_t *)filepath,&index);

 	/* Go to the specified directory level by changing the path */
   	if(currentposition !=index)
	{
        if((clusterno =  Changepath(HandleNumber,(uint8_t *)filepath,kUTF16Encoding,currentposition,index)) <0)
        {
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	    }
        UpdateHandle(HandleNumber,clusterno);
    }
	    
    /* search for the specified file */
    if(currentposition==0)
        currentposition = index;
        
        //modify: double the string length for unicode
    if((clusterno =  Changepath(HandleNumber,(uint8_t *)filepath,kUTF16Encoding,strlen*2,currentposition)) <0)
    {
        if(Mode == READ_MODE  || Mode == RPLUS)
	    {
            Freehandle(HandleNumber);
		    return(ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
	    }
        /* If file is to be opened in w, w+(write), a or a+(append) mode and 
        if the file is not found then create a new file of the name 
        specified in the specified directory */	
        
        if((Retval = Fcreate(HandleNumber,(uint8_t *)filepath,kUTF16Encoding,strlen*2,currentposition)) <0)
	    {
            Freehandle(HandleNumber);
	  		return Retval;
	    }	
    }
	/* If file is found and is to be opened for w, w+(write), a or a+(append)
	mode then check the file attribute. If it is READ_ONLY then  return error
	ERROR_OS_FILESYSTEM_FILE_WRITE_FAILED */
    else
	{
        if(Mode != READ_MODE)
        {
            RecordNo =   Handle[HandleNumber].CurrentOffset >> 5;
            if(ReadDirectoryRecord(HandleNumber,RecordNo,buf)<0)
                return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;
     
     
            Handle[HandleNumber].FileSize =FSGetDWord((uint8_t *)buf,DIR_FILESIZEOFFSET);
            if(FSGetByte(buf,DIR_ATTRIBUTEOFFSET) & READ_ONLY)
		    {
                Freehandle(HandleNumber);
           	    return(ERROR_OS_FILESYSTEM_FILE_WRITE_FAILED);
		    }

            if (Handle[HandleNumber].StartingCluster != 0)
                Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR);
	  
            UpdateHandle(HandleNumber,clusterno);
            Updatehandlemode(HandleNumber,READ_MODE + WRITE_MODE);
            /* If file is found and is to be opened for w, w+(write), a or a+(append)
            mode then check if the file is already opened for write mode. If file is 
            already opened for write mode then return error 'File can not be opened in write mode' */
            
            if(IsHandleWriteAllocated(HandleNumber) == WRITE_MODE)
		    {
                Freehandle(HandleNumber);
			    return(ERROR_OS_FILESYSTEM_FILE_WRITE_FAILED);
		    }
		    /* If file is to be opened in write mode (i.e. W or WPLUS) then 
	        delete the contents of the file. */
            if(Mode == WRITE_MODE || Mode == WPLUS)
	        {
                if (Handle[HandleNumber].StartingCluster != 0)
                {
                    //if((Retval = DeleteContent(HandleNumber,1)) <0) // 3.05 had this line commented out.
                    if((Retval = DeleteContent(HandleNumber,0)) <0)   // 3.05 and 3.1prelim had this line active.
		            {
                        Freehandle(HandleNumber);
		                return Retval;
			        }
		            if((Retval = UpdateFileSize(HandleNumber,1)) <0)
		            {
                        Freehandle(HandleNumber);
		                return Retval;
			        }
                    Handle[HandleNumber].StartingCluster = 0;             
                    Handle[HandleNumber].CurrentCluster = 0;
                    Handle[HandleNumber].CurrentSector = 0;
                    clusterlo = 0;
                    clusterhi = 0;
			 
                    if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,
		                 (Handle[HandleNumber].DirOffset+DIR_FSTCLUSLOOFFSET),
		                 (uint8_t*)&clusterlo,0,2,WRITE_TYPE_RANDOM)) <0)
                        return Retval;
			 
                    if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,
			             (Handle[HandleNumber].DirOffset+DIR_FSTCLUSHIOFFSET),
			             (uint8_t*)&clusterhi,0,2,WRITE_TYPE_RANDOM)) <0)
                        return Retval;                
		        }
		    }
            /* If file is to be opened in append mode then set the current offset
            in the handle table to the end of file. */
            if(Mode == APPEND_MODE || Mode == APLUS)
	        {
                if(( Retval = Fseek(HandleNumber,0,SEEK_END))< 0)
			    {
                    Freehandle(HandleNumber);
 		            return Retval;
			    }
		    }
        }
        else       //   Mode == READ_MODE
        {
// SDK-6915: No need to seek the directory offset since we are at the right position already
//            if (Handle[HandleNumber].StartingCluster != 0)
//                Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR);
          
	        UpdateHandle(HandleNumber,clusterno);
        }
    }
  	/* Update the mode of handle table according to the given mode */
    if (Mode ==	RPLUS || Mode == WPLUS )
        Mode = (FileSystemModeTypes_t)(READ_MODE + WRITE_MODE);
  	else if (Mode == APPEND_MODE)
        Mode =  (FileSystemModeTypes_t)(WRITE_MODE+APPEND_MODE);
    else if (Mode == APLUS)
        Mode =  (FileSystemModeTypes_t)(READ_MODE+WRITE_MODE+APPEND_MODE);
  
    Updatehandlemode(HandleNumber, Mode);
    return (HandleNumber);
}
        	   
      
   									  
									   
