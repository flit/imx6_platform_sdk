/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/FindNextSector.c $
 $Revision: 11 $                                       
 $Date: 9/18/03 3:45p $
 Description: FindNextSector.c
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

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t UpdateHandleOffsets(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns ERROR_OS_FILESYSTEM_EOF or an Error Code if error occurs

   Description:   Updates handle entries after each read and/or write
<
----------------------------------------------------------------------------*/
RtStatus_t UpdateHandleOffsets(int32_t HandleNumber)
{
    HandleTable_t * handle = &Handle[HandleNumber];
    int32_t Device = handle->Device;
    FileSystemMediaTable_t * media = &MediaTable[Device];
    uint32_t bytesPerSector = media->BytesPerSector;
    uint32_t sectorsPerCluster = media->SectorsPerCluster;
    RtStatus_t RetValue = SUCCESS;
    
    while (handle->BytePosInSector >= bytesPerSector)
    {
        handle->BytePosInSector -= bytesPerSector;
        handle->CurrentSector++;
        handle->SectorPosInCluster++;
        
        if (handle->SectorPosInCluster >= sectorsPerCluster)
        {
            if ((RetValue = FindNextSector(Device, HandleNumber)) == ERROR_OS_FILESYSTEM_EOF)
            {
                handle->BytePosInSector = bytesPerSector;
                handle->SectorPosInCluster = sectorsPerCluster - 1;
                return RetValue;
            }
            
		    if (RetValue == ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO)
            {
			    return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
            }
        }    
    }
    
    return RetValue;
}

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t FindNextSector(int32_t Device,int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1) Device
                  2) HandleNumber

   Outputs:       Returns 0 else an error code

   Description:   Finds the next cluster and sector 
<
----------------------------------------------------------------------------*/
RtStatus_t FindNextSector(int32_t Device, int32_t HandleNumber)
{
    HandleTable_t * handle = &Handle[HandleNumber];
    int32_t ClusterNumber = Findnextcluster(Device, handle->CurrentCluster);
    if (ClusterNumber == ERROR_OS_FILESYSTEM_EOF)
    {
        return ERROR_OS_FILESYSTEM_EOF;
    }
    else if (ClusterNumber <= 0)
    {
        return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
    }
    
    handle->CurrentCluster = ClusterNumber;
    handle->SectorPosInCluster = 0;
    handle->CurrentSector = Firstsectorofcluster(Device, handle->CurrentCluster);
    
    return SUCCESS;
}
