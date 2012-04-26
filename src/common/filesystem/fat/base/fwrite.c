/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fwrite.c $
 $Revision: 23 $                                       
 $Date: 9/18/03 6:50p $
 Description: Fwite.c
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
#include <os\fsapi.h> 
#include "fs_steering.h"   
#include "components/telemetry/tss_logtext.h"

/*----------------------------------------------------------------------------

>  Function Name: int32_t Fwrite(int32_t HandleNumber, 
                       uint8_t *Buffer, 
                       int32_t NumBytesToWrite,
                      )

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to Buffer
                  3)Number of Bytes To Write

   Outputs:       Returns   Number of bytes written upon success or
                                   0 upon failures - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED,
                                                          ERROR_OS_FILESYSTEM_INVALID_MODE,
                                                          NumBytesToWrite <= 0,
                                                          ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE,
                                                          ERROR_OS_FILESYSTEM_NO_FREE_CLUSTER,
                                                          ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO

   Description:   Writes the Specified number of Bytes to the FILE

<
----------------------------------------------------------------------------*/
int32_t Fwrite_FAT(int32_t HandleNumber, 
                         uint8_t *Buffer, 
                         int32_t NumBytesToWrite)
                                  
{
    int32_t BytesToCopy,clusterlo, clusterhi;
    RtStatus_t RetValue = SUCCESS;
    int32_t Device,BytesPerSector,RemainBytesInSector,Mode;
    int32_t BuffOffset=0,clusterno;
    int32_t RemainBytesToWrite = NumBytesToWrite, FileSize=0;
        
    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
    {
        // Error - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED
        return 0;
    }
    if(NumBytesToWrite <= 0)
        return 0;
         
    Device = Handle[HandleNumber].Device;
    BytesPerSector = MediaTable[Device].BytesPerSector;

    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return 0;
    }    
    
    if(((Handle[HandleNumber].Mode)& WRITE_MODE)!=WRITE_MODE )
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_MODE;
        return 0;
    }
    
    ddi_ldl_push_media_task("Fwrite_FAT");

    /* If zero length file is opened, its starting cluster is zero, so we have to
    allocate one cluster to the file and update the directory record */
    if((Handle[HandleNumber].StartingCluster) == 0)
    {
        if((clusterno = FirstfreeAndallocate(Device))<0)
        {
            ddi_ldl_pop_media_task();
            return 0;
        }        
        Handle[HandleNumber].StartingCluster    = clusterno;
        Handle[HandleNumber].CurrentCluster    = clusterno;
        Handle[HandleNumber].CurrentSector= Firstsectorofcluster(Device,clusterno);
      
        clusterlo = clusterno & 0x00ffff;
        clusterhi = (int32_t)( (clusterno >> 16 ) & 0x00ffff);
     
        //! todo - check this - RetValue wasn't being set previously.
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                       Handle[HandleNumber].DirSector,
                       (Handle[HandleNumber].DirOffset+DIR_FSTCLUSLOOFFSET),
                           (uint8_t *)&clusterlo,
                           0,2,
                           WRITE_TYPE_RANDOM)) <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
        
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                               Handle[HandleNumber].DirSector,
                               (Handle[HandleNumber].DirOffset+DIR_FSTCLUSHIOFFSET),
                               (uint8_t *)&clusterhi,
                               0, 2,
                               WRITE_TYPE_RANDOM)) 
                                < 0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
    }

    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(HandleNumber);
    }
    
    //In append mode seek to the end of file and write at the end
    if(((Handle[HandleNumber].Mode)& APPEND_MODE)==APPEND_MODE )
    {
        if(FileSize!=Handle[HandleNumber].CurrentOffset)
        {
            Fseek(HandleNumber,0,SEEK_END);
        }
    }

    RemainBytesInSector = BytesPerSector - Handle[HandleNumber].BytePosInSector;

    while(RemainBytesToWrite >0)
    {
    
        if ((RetValue = UpdateHandleOffsets(HandleNumber)))
        {   
            if(RetValue == ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO)
            {
                Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
                ddi_ldl_pop_media_task();
                return 0;
            }

            if((RetValue = GetNewcluster(HandleNumber)) < 0)
            {
                Handle[HandleNumber].ErrorCode = RetValue;
                ddi_ldl_pop_media_task();
                return (NumBytesToWrite - RemainBytesToWrite);
            }     
            if (Handle[HandleNumber].Mode & CREATE_MODE)
            {
                 if((RetValue = ClearCluster(HandleNumber)) <0)
                 {
                     ddi_ldl_pop_media_task();
                     return RetValue;
                 }
            }                             
        }    

        if ((RemainBytesInSector != 0)&&(RemainBytesToWrite > RemainBytesInSector))
        {
            BytesToCopy    = RemainBytesInSector;
            RemainBytesInSector = 0;
        }
        else
        {    
            BytesToCopy = RemainBytesToWrite;
            if(BytesToCopy > BytesPerSector)
            {
                BytesToCopy = BytesPerSector;
            }
        }
        RemainBytesToWrite-=BytesToCopy;

        if((FileSize - Handle[HandleNumber].CurrentOffset)<=0)
        {   
             Handle[HandleNumber].Mode |= SEQ_WRITE_MODE;
             Mode = WRITE_TYPE_NOREADBACK;

            }
        else
                Mode = WRITE_TYPE_RANDOM;
#ifdef SUPPORT_SEQ_WRITE
    if (((Handle[HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
            (Handle[HandleNumber].SectorPosInCluster==0))
      Mode = WRITE_TYPE_SEQ_FIRST;
     else
          if (((Handle[HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
              (Handle[HandleNumber].SectorPosInCluster!=0))
        
          Mode = WRITE_TYPE_SEQ_NEXT;

#endif    
    
        if((RetValue = FSWriteSector(Device,
                       Handle[HandleNumber].CurrentSector,
                       Handle[HandleNumber].BytePosInSector,
                   Buffer,
                   BuffOffset,
                   BytesToCopy,
                   Mode)) 
              <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }


        Handle[HandleNumber].CurrentOffset += BytesToCopy;
        Handle[HandleNumber].BytePosInSector += BytesToCopy;

        BuffOffset+=BytesToCopy;            
        
    }

    if((FileSize - Handle[HandleNumber].CurrentOffset)<0)
    {   
        Handle[HandleNumber].Mode |= SEQ_WRITE_MODE;
        UpdateFileSize(HandleNumber,0);
    }
        
    ddi_ldl_pop_media_task();
    return NumBytesToWrite;
}


//////////////////////////////////////////////////////////////////////////////
//! \brief This function is identical to Fwrite except that it bypasses cache
//!
//! \fntype Function
//!
//! Writes the Specified number of Bytes to the FILE.  This
//! function bypasses Cache and cannot be used unless 
//! the all except for the last Fwrite in a given sequence
//! are full writes.  Cache is bypassed for performance
//! reasons.  Writes need to be aligned on sector boundary,
//! and buffer has to be at least as large as a sector.
//!
//! \param[in]    i32HandleNumber
//! \param[out]   pBuffer
//! \param[in]    i32NumBytesToWrite
//!
//! \return Status of call.
//! \retval 0            If error has occurred    
//!
//! \pre Writes have to be aligned on sector boundary.
//! \pre Buffer has to be as large as sector.
//!
//////////////////////////////////////////////////////////////////////////////

int32_t Fwrite_BypassCache(int32_t i32HandleNumber, 
                         uint8_t *pBuffer, 
                         int32_t i32NumBytesToWrite)                                  
{
    int32_t BytesToCopy,clusterlo, clusterhi;
    RtStatus_t RetValue = SUCCESS;
    int32_t Device,BytesPerSector,RemainBytesInSector,Mode;
    int32_t BuffOffset=0,clusterno;
    int32_t RemainBytesToWrite = i32NumBytesToWrite, FileSize=0;
                 
    Device = Handle[i32HandleNumber].Device;
    BytesPerSector = MediaTable[Device].BytesPerSector;

    if(i32NumBytesToWrite <= 0)
        return 0;
    
    ddi_ldl_push_media_task("Fwrite_BypassCache");
    
#if DEBUG
    // Verify that clusters are at least as big as a native sector. This is necessary
    // because of the media cache flags we use to prevent unwanted readbacks. If the
    // cluster size is smaller than the native sector size, clusters after the end of
    // a file segment could potentially be corrupted.
    DriveGetInfo(Device, kDriveInfoNativeSectorSizeInBytes, &BytesToCopy);
    assert(BytesToCopy <= MediaTable[Device].SectorsPerCluster * BytesPerSector);
#endif
    
    /* If zero length file is opened, its starting cluster is zero, so we have to
    allocate one cluster to the file and update the directory record */
    if((Handle[i32HandleNumber].StartingCluster) == 0)
    {
                
        if((clusterno = FirstfreeAndallocate(Device))<0)
        {
            ddi_ldl_pop_media_task();
            return 0;
        }       
                
        Handle[i32HandleNumber].StartingCluster    = clusterno;
        Handle[i32HandleNumber].CurrentCluster    = clusterno;
        Handle[i32HandleNumber].CurrentSector= Firstsectorofcluster(Device,clusterno);
      
        clusterlo = clusterno & 0x00ffff;
        clusterhi = (int32_t)( (clusterno >> 16 ) & 0x00ffff);
     
        //! todo - check this - RetValue wasn't being set previously.
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                       Handle[i32HandleNumber].DirSector,
                       (Handle[i32HandleNumber].DirOffset+DIR_FSTCLUSLOOFFSET),
                           (uint8_t *)&clusterlo,
                           0,2,
                           WRITE_TYPE_RANDOM)) <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
     
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                               Handle[i32HandleNumber].DirSector,
                               (Handle[i32HandleNumber].DirOffset+DIR_FSTCLUSHIOFFSET),
                               (uint8_t *)&clusterhi,
                               0, 2,
                               WRITE_TYPE_RANDOM)) 
                                < 0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
      
    }

    if (Handle[i32HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(i32HandleNumber);
    }
    
    //In append mode seek to the end of file and write at the end
    if(((Handle[i32HandleNumber].Mode)& APPEND_MODE)==APPEND_MODE )
    {
        if(FileSize!=Handle[i32HandleNumber].CurrentOffset)
        {
            Fseek(i32HandleNumber,0,SEEK_END);
        }
    }
    
    // Make sure we're writing at the end of the file. This function can only be
    // called to append to a file.
    if(FileSize!=Handle[i32HandleNumber].CurrentOffset)
    {
#if DEBUG
        tss_logtext_Print(~0, "Warning: Fwrite_BypassCache() called for a sector in the middle of a file (handle=%d, file size=%u, current offset=%u)\n", i32HandleNumber, FileSize, Handle[i32HandleNumber].CurrentOffset);
#endif

        ddi_ldl_pop_media_task();
        return ERROR_OS_FILESYSTEM_NOT_EOF;
    }

    RemainBytesInSector = BytesPerSector - Handle[i32HandleNumber].BytePosInSector;

    while(RemainBytesToWrite >0)
    {
    
        if ((RetValue = UpdateHandleOffsets(i32HandleNumber)))
        {   
            if(RetValue == ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO)
            {
                Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
                ddi_ldl_pop_media_task();
                return 0;
            }

            if((RetValue = GetNewcluster(i32HandleNumber)) < 0)
            {
                Handle[i32HandleNumber].ErrorCode = RetValue;
                ddi_ldl_pop_media_task();
                return (i32NumBytesToWrite - RemainBytesToWrite);
            }
            if (Handle[i32HandleNumber].Mode & CREATE_MODE)
            {
                 if((RetValue = ClearCluster(i32HandleNumber)) <0)
                 {
                     ddi_ldl_pop_media_task();
                     return RetValue;
                 }
            }                 
        }    

        if ((RemainBytesInSector != 0)&&(RemainBytesToWrite > RemainBytesInSector))
        {
            BytesToCopy    = RemainBytesInSector;
            RemainBytesInSector = 0;
        }
        else
        {    
            BytesToCopy = RemainBytesToWrite;
            if(BytesToCopy > BytesPerSector)
            {
                BytesToCopy = BytesPerSector;
            }
        }
        RemainBytesToWrite-=BytesToCopy;

        if((FileSize - Handle[i32HandleNumber].CurrentOffset)<=0)
        {   
             Handle[i32HandleNumber].Mode |= SEQ_WRITE_MODE;
             Mode = WRITE_TYPE_NOREADBACK;

        }
        else
                Mode = WRITE_TYPE_RANDOM;
#ifdef SUPPORT_SEQ_WRITE
    if (((Handle[i32HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
            (Handle[i32HandleNumber].SectorPosInCluster==0))
      Mode = WRITE_TYPE_SEQ_FIRST;
     else
          if (((Handle[i32HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
              (Handle[i32HandleNumber].SectorPosInCluster!=0))
        
          Mode = WRITE_TYPE_SEQ_NEXT;

#endif       
    
        if((RetValue = FSWriteSector_BypassCache(Device,
                       Handle[i32HandleNumber].CurrentSector,
                       Handle[i32HandleNumber].BytePosInSector,
                   pBuffer,
                   BuffOffset,
                   BytesToCopy,
                   Mode)) <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }


        Handle[i32HandleNumber].CurrentOffset += BytesToCopy;
        Handle[i32HandleNumber].BytePosInSector += BytesToCopy;

        BuffOffset+=BytesToCopy;                    
    }

    if((FileSize - Handle[i32HandleNumber].CurrentOffset)<0)
    {   
        Handle[i32HandleNumber].Mode |= SEQ_WRITE_MODE;
        
        // We can do this in this function because we are
        // sure that there are no other handles open to
        // our file.
        // Otherwise, we will need to call UpdateFileSize.
        Handle[i32HandleNumber].FileSize = Handle[i32HandleNumber].CurrentOffset;
    }
        
    ddi_ldl_pop_media_task();
    return i32NumBytesToWrite;
}

//////////////////////////////////////////////////////////////////////////////
//! \brief This function is identical to Fwrite except that it bypasses cache
//!
//! \fntype Function
//!
//! This function is only used in growing a file which are initialized to
//! be all zeros.
//!
//! \param[in]    i32HandleNumber
//! \param[out]   pBuffer
//! \param[in]    i32NumBytesToWrite
//!
//! \return Status of call.
//! \retval 0            If error has occurred    
//!
//! \pre Writes have to be aligned on sector boundary.
//! \pre Buffer has to be as large as sector.
//!
//////////////////////////////////////////////////////////////////////////////

int32_t Fwrite_GrowFile
(
  int32_t i32HandleNumber, 
  int32_t i32NumBytesToWrite,
  bool    Create
)                                  
{
    int32_t BytesToCopy,clusterlo, clusterhi;
    int32_t RetValue = SUCCESS;
    int32_t Device,BytesPerSector,RemainBytesInSector;
    int32_t clusterno;
    int32_t RemainBytesToWrite = i32NumBytesToWrite, FileSize=0;
    //bool    useMultiWrite;
    //int32_t Mode;
               
    Device = Handle[i32HandleNumber].Device;
    BytesPerSector = MediaTable[Device].BytesPerSector;
    
    ddi_ldl_push_media_task("Fwrite_GrowFile");
   
//    useMultiWrite = (((MediaTable[Device].SectorsPerCluster)>1) && (Create));
    
    /* If zero length file is opened, its starting cluster is zero, so we have to
    allocate one cluster to the file and update the directory record */
    if((Handle[i32HandleNumber].StartingCluster) == 0)
    {
                
        if((clusterno = FirstfreeAndallocate(Device))<0)
        {
            ddi_ldl_pop_media_task();
            return 0;
        }       
                
        Handle[i32HandleNumber].StartingCluster    = clusterno;
        Handle[i32HandleNumber].CurrentCluster    = clusterno;
        Handle[i32HandleNumber].CurrentSector= Firstsectorofcluster(Device,clusterno);
      
        clusterlo = clusterno & 0x00ffff;
        clusterhi = (int32_t)( (clusterno >> 16 ) & 0x00ffff);
     
        //! todo - check this - RetValue wasn't being set previously.
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                       Handle[i32HandleNumber].DirSector,
                       (Handle[i32HandleNumber].DirOffset+DIR_FSTCLUSLOOFFSET),
                           (uint8_t *)&clusterlo,
                           0,2,
                           WRITE_TYPE_RANDOM)) <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
     
        //if((RetValue = myFSWriteSector(Device,
        if((RetValue = FSWriteSector(Device,
                               Handle[i32HandleNumber].DirSector,
                               (Handle[i32HandleNumber].DirOffset+DIR_FSTCLUSHIOFFSET),
                               (uint8_t *)&clusterhi,
                               0, 2,
                               WRITE_TYPE_RANDOM)) 
                                < 0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;                     
        }
      
    }

    if (Handle[i32HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(i32HandleNumber);
    }
    
    //In append mode seek to the end of file and write at the end
    if(((Handle[i32HandleNumber].Mode)& APPEND_MODE)==APPEND_MODE )
    {
        if(FileSize!=Handle[i32HandleNumber].CurrentOffset)
        {
            Fseek(i32HandleNumber,0,SEEK_END);
        }
    }

    RemainBytesInSector = BytesPerSector - Handle[i32HandleNumber].BytePosInSector;

    while(RemainBytesToWrite >0)
    {
    
        if ((RetValue = UpdateHandleOffsets(i32HandleNumber)))
        {   
            if(RetValue == ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO)
            {
                Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
                ddi_ldl_pop_media_task();
                return 0;
            }

            if((RetValue = GetNewcluster(i32HandleNumber)) < 0)
            {
                Handle[i32HandleNumber].ErrorCode = RetValue;
                ddi_ldl_pop_media_task();
                return (i32NumBytesToWrite - RemainBytesToWrite);
            }
             
        }    

       if ((RemainBytesInSector != 0)&&(RemainBytesToWrite > RemainBytesInSector))
        {
            BytesToCopy    = RemainBytesInSector;
            RemainBytesInSector = 0;
        }
        else
        {    
            BytesToCopy = RemainBytesToWrite;
            if(BytesToCopy > BytesPerSector)
            {
                BytesToCopy = BytesPerSector;
            }
        }
        RemainBytesToWrite-=BytesToCopy;

        if((FileSize - Handle[i32HandleNumber].CurrentOffset)<=0)
        {   
             Handle[i32HandleNumber].Mode |= SEQ_WRITE_MODE;
//             Mode = WRITE_TYPE_NOREADBACK;

            }
        else
        {
//                Mode = WRITE_TYPE_RANDOM;
        }
#ifdef SUPPORT_SEQ_WRITE
    if (((Handle[i32HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
            (Handle[i32HandleNumber].SectorPosInCluster==0))
    {
//      Mode = WRITE_TYPE_SEQ_FIRST;
    }
    else if (((Handle[i32HandleNumber].Mode & SEQ_WRITE_MODE)==SEQ_WRITE_MODE) &&
              (Handle[i32HandleNumber].SectorPosInCluster!=0))
    {

//          Mode = WRITE_TYPE_SEQ_NEXT;
    }

#endif       

        Handle[i32HandleNumber].CurrentOffset += BytesToCopy;
        Handle[i32HandleNumber].BytePosInSector += BytesToCopy;                  
                            
    }

    if((FileSize - Handle[i32HandleNumber].CurrentOffset)<0)
    {   
        Handle[i32HandleNumber].Mode |= SEQ_WRITE_MODE;
        
        // We can do this in this function because we are
        // sure that there are no other handles open to
        // our file.
        // Otherwise, we will need to call UpdateFileSize.
        Handle[i32HandleNumber].FileSize = Handle[i32HandleNumber].CurrentOffset;
    }
        
    ddi_ldl_pop_media_task();
    return i32NumBytesToWrite;
}

//---eof------------------------------------------------------------------------



