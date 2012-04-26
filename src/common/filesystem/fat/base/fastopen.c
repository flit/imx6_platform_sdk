/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/FastOpen.c $
 $Revision: 9 $                                       
 $Date: 9/18/03 6:49p $
 Description: FastOpen.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "diroffset.h"

/*----------------------------------------------------------------------------

>  Function Name: int32_t FastOpen(int32_t Key,uint8_t *mode)

   FunctionType:  Reentrant

   Inputs:        1) Key
                  2) mode

   Outputs:       HandleNumber on Success else an error code

   Description:   It reads the Key and mode of the file for FastOpen and then it finds the free handle 
                  and allocate handle according to the record.
                  
<
----------------------------------------------------------------------------*/
int32_t FastOpen(int64_t Key, uint8_t *mode)
{
    int32_t HandleNumber;
    uint8_t  *buf;
    int32_t ClusterNumber,DirSector;
    FileSystemModeTypes_t Mode;
    int32_t attribute,Device,DirOffset;
    RtStatus_t Retval;
    uint32_t cacheToken;

    if((mode[0]) == 'r')
    {
        if((mode[1]) == '+')
            Mode = (FileSystemModeTypes_t)(READ_MODE+WRITE_MODE);
        else
            Mode = READ_MODE;
    }
    else if((mode[0]) == 'w')
    {
        if((mode[1]) == '+')
            Mode = (FileSystemModeTypes_t)(READ_MODE+WRITE_MODE);
        else
            Mode = WRITE_MODE;
    }
    else if((mode[0]) == 'a')
    {
        if((mode[1]) == '+')
            Mode =  (FileSystemModeTypes_t)(READ_MODE+WRITE_MODE+APPEND_MODE);
        else
            Mode = (FileSystemModeTypes_t)(WRITE_MODE+ APPEND_MODE);
    }
    else if((mode[0]) == 'd')
    {
        if((mode[1]) == '+')
           Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE+READ_MODE+WRITE_MODE);
        else
           Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE+READ_MODE);
    }
    else
        return ERROR_OS_FILESYSTEM_MODE_NOT_SUPPORTED;


    if((HandleNumber = Searchfreehandleallocate())<0)
        return HandleNumber;
    
    Device = (int32_t)(( (Key >> 44) & 0x000000000000000F));
    Handle[HandleNumber].Device = Device;
    DirSector = (Key & 0xFFFFFFFF);
    DirOffset =  (int32_t)((Key >> 32) & 0xFFF);
    Handle[HandleNumber].DirOffset = DirOffset;
    Handle[HandleNumber].DirSector = DirSector;
    
        
    if(DirSector==0)
    {

        if (MediaTable[Device].FATType ==FAT32)
        {
            Handle[HandleNumber].StartingCluster = MediaTable[ Device].RootdirCluster;
            Handle[HandleNumber].CurrentCluster = MediaTable[ Device].RootdirCluster;
        }

        else
        {
            Handle[HandleNumber].StartingCluster = 0;
            Handle[HandleNumber].CurrentCluster = 0;
        }
    
    }
    
    else
    {
       
        EnterNonReentrantSection();
        if((buf = (uint8_t *)FSReadSector(Handle[HandleNumber].Device,DirSector,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t *)0)
        {
            LeaveNonReentrantSection();
            Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
        }
        
        ClusterNumber = ((int32_t)(FSGetWord((uint8_t*)buf,DIR_FSTCLUSLOOFFSET+DirOffset))|((int32_t)FSGetWord((uint8_t*)buf,DIR_FSTCLUSHIOFFSET+DirOffset)<<16));
        Handle[HandleNumber].CurrentCluster = ClusterNumber;
        Handle[HandleNumber].StartingCluster = ClusterNumber;
        Handle[HandleNumber].FileSize = FSGetDWord((uint8_t *)buf,DIR_FILESIZEOFFSET+DirOffset);
        attribute =  FSGetByte((uint8_t *)buf,DIR_ATTRIBUTEOFFSET+DirOffset);

        FSReleaseSector(cacheToken);
        
        LeaveNonReentrantSection();
        
    
        if(Mode & DIRECTORY_MODE)
        {
            if(!(attribute & DIRECTORY_MODE))
            {
                Freehandle(HandleNumber);
                return(ERROR_OS_FILESYSTEM_CANNOT_OPEN_DIRECTORY);
            }
        }   
        if(Mode & WRITE_MODE)
        {
            if(attribute & READ_ONLY)
            {
                Freehandle(HandleNumber);
                return(ERROR_OS_FILESYSTEM_FILE_WRITE_FAILED);
            }
        }      
          
   
    }
    if((Handle[HandleNumber].CurrentSector = Firstsectorofcluster(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentCluster))<0)
    {
        Freehandle(HandleNumber);
        return Handle[HandleNumber].CurrentSector;
    }
       

    if(Mode & WRITE_MODE)
    {
         if(IsHandleWriteAllocated(HandleNumber) == WRITE_MODE)
         {
            Freehandle(HandleNumber);
            return(ERROR_OS_FILESYSTEM_FILE_WRITE_FAILED);
         }
    }      

    Handle[HandleNumber].CurrentOffset = 0;
    Handle[HandleNumber].BytePosInSector = 0;
    Handle[HandleNumber].SectorPosInCluster = 0;
    if(Mode & APPEND_MODE)
    {
        if(( Retval = Fseek(HandleNumber,0,SEEK_END))< 0)
        {
            Freehandle(HandleNumber);
            return Retval;
        }
    }
   
    Updatehandlemode(HandleNumber, Mode);
    return HandleNumber;
}
