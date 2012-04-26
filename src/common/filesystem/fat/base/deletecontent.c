/*----------------------------------------------------------------------------
SigmaTel Inc
$Archive: /Fatfs/FileSystem/Fat32/base/DeleteContent.c $
$Revision: 8 $
$Date: 9/18/03 11:50a $
Description: DeleteContent.c
Notes:
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
#include <drivers/sectordef.h>
#include "drivers/media/cache/media_cache.h"

/*----------------------------------------------------------------------------
>  Function Name: int32_t DeleteContent(int32_t HandleNumber,int32_t bUseVestigialClusterEraser)

   FunctionType:  Reentrant

   Inputs:        1) HandleNumber
                  2) bUseVestigialClusterEraser - If nonzero, then an old algorithm is used.  Not advisable.

   Outputs:       Returns an Error code if function fails otherwise SUCCESS

   Description:   This function deletes contents of the file referenced by the
                  handle no (i.e.  Marks the clusters occupied by the file as
                  zero in the FAT Table )
<
----------------------------------------------------------------------------*/
int32_t DeleteContent(int32_t HandleNumber,int32_t bUseVestigialClusterEraser)
{
    int32_t  clusterno, nFileSizeInBytes, nFileSizeInClusters, FATentry;
    int     FATsector, iCluster, Device, FATNtryOffsetInBytesInThisSector, iFirstFATSectorOnTheDevice;
    BOOL    exitCondition;
    int     oldFATSector;
#ifdef ENABLE_WRITE_FAT2  /* Write FAT2 */
	int     FATSize;
#endif

    uint8_t *p_u8_CopyOfASectorOfFAT;       // Like the name says, this points to a copy of
                                            // one sector of the FAT itself.
                                            // For performance reasons, a whole sector of the FAT is
                                            // read into this buffer at one time, the "DeleteContent"
                                            // procedure is performed, and then the sector is written back
                                            // to the FAT.

    int     SectorMask, BytesPerSector, ret, FAToffsetInBytes;
	int	    FatType;
	int     FatShift;
    MediaCacheParamBlock_t pb = {0};

    if((nFileSizeInBytes = GetFileSize(HandleNumber))==0)
    {
        nFileSizeInBytes =  0x7fffffff; // Set the file size as the largest positive number	for directory
    }
    Device = Handle[HandleNumber].Device;

    if(0x7fffffffL - nFileSizeInBytes >= MediaTable[Device].ClusterMask )
    {
        nFileSizeInClusters =   (MediaTable[Device].ClusterMask + nFileSizeInBytes) >> MediaTable[Device].ClusterShift;
        //
        // Note: Right-shifting by "ClusterShift" gives the quantity
        // of clusters, but truncates that value.
        // A 0.5 cluster file would be truncated to zero clusters.
        // But that file still consumes a cluster, so "zero" is not the right answer.
        //
        // What's needed is a "ceiling" calculation.  We can have that calculation by adding
        // "clustersize-in-bytes - 1" to the file size, then truncating to the integer quantity
        // of clusters.  ClusterMask happens to equal "clustersize-in-bytes - 1". 
        //
        // This way, 0.5 clusters becomes 1, 1 cluster is unchanged, 1.5 clusters becomes 2, etc.
    }
    else
    {
        nFileSizeInClusters = (0x7fffffffL >> MediaTable[Device].ClusterShift) + 1;
    }

    clusterno = Handle[HandleNumber].StartingCluster;
    if (0==clusterno) /* If starting cluster number is 0, there's no content to delete */
    {
        return SUCCESS;
    }

    BytesPerSector = MediaTable[Device].BytesPerSector;

    if (bUseVestigialClusterEraser)
    {
        FATentry = Findnextcluster(Device,clusterno);
        if(FATentry == ERROR_OS_FILESYSTEM_EOF)
        {
            return SUCCESS;
        }
        if(FATentry <=0)
        {
            return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
        }
        FATsector = FATsectorno(Device,clusterno,&FATNtryOffsetInBytesInThisSector);
        WriteFATentry(Device,FATsector,FATNtryOffsetInBytesInThisSector,clusterno,FAT32EOF);
        clusterno = FATentry;
        nFileSizeInClusters--;
    }

    //
    // All subsequent reads and writes to the FAT will be sector-by-sector.
    // This is the first sector that contains the FAT:
    //
    iFirstFATSectorOnTheDevice = FATsectorno(Device,0,&FATNtryOffsetInBytesInThisSector);

	FatType = MediaTable[Device].FATType;
    oldFATSector = -1;
#ifdef ENABLE_WRITE_FAT2  /* Write FAT2 */
    FATSize = MediaTable[Device].FATSize;
#endif
    SectorMask = MediaTable[Device].SectorMask;

	//
	// Check that HandleNumber refers to a real cluster, not free space nor
	// the end of a cluster chain.
    //
    if (FatType == FAT32)
    {                        // end of cluster chain or free cluster?
        exitCondition = ((FAT32EOF == clusterno) || (0 == clusterno));
    }
    else if( FatType == FAT12 )
    {
		exitCondition = ((((unsigned int)clusterno) > ((unsigned int)0x0FF5)) || (0==clusterno));
    }
	else					// FAT16
	{
		exitCondition = ((((unsigned int)clusterno) > ((unsigned int)0xFFF0)) || (0==clusterno));
    }

    if (exitCondition)
    {
        // Free space or the end of a cluster chain.
		return SUCCESS;
    }

	//
	// Determine the number of sectors per cluster.
    //
	if( FatType == FAT32 )
	{
		// shift to convert FAT32 cluster to FAT sector is sector size / 4 == sector shift - 2
		FatShift = MediaTable[Device].SectorShift - 2;
	}
	else if( FatType == FAT12 )
	{
		//FatShift  = FAT12_ENTRIES_PER_512SECTOR * (MediaTable[Device].BytesPerSector >> 9);
		FatShift  = ((BytesPerSector)*8)/12;
	}
	else // FAT16
	{
		// shift to convert FAT16 cluster to FAT sector is sector size / 2 == sector shift - 1
		FatShift = MediaTable[Device].SectorShift - 1;
	}

    EnterNonReentrantSection();

	//
    // Which sector in the FAT refers to this cluster?
    // Compute the sector number and read that sector in.
	//
	if( FatType == FAT12 )
	{
		FATsector = clusterno/FatShift;
	}
	else
	{
		FATsector = clusterno >> FatShift;
	}
    
    // Set up the param block. Here we're using the media cache directly instead
    // of going through the cache wrapper functions because using a pinned write
    // is much more efficient than a separate read and write call with a temporary
    // buffer.
    pb.drive = Device;
    pb.sector = FATsector + iFirstFATSectorOnTheDevice;
    pb.requestSectorCount = 1;
    pb.mode = WRITE_TYPE_RANDOM;
    pb.weight = kMediaCacheWeight_High;
    pb.flags = kMediaCacheFlag_ApplyWeight;

    if (media_cache_pinned_write(&pb) != SUCCESS)
    {
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
    }
    p_u8_CopyOfASectorOfFAT = pb.buffer;

    //
    // Loop over all clusters that contain the file, and mark those clusters
    // as free in the FAT.
    //
    for (iCluster=1 ; iCluster<=nFileSizeInClusters ; iCluster++)
    {
	    //
        // Which sector in the FAT refers to this cluster?
        // Compute the sector number and read that sector in.
	    //
		if( FatType == FAT12 )
		{
			FATsector = clusterno/FatShift;
		}
		else
		{
			FATsector = clusterno >> FatShift;
		}

        if ((FATsector != oldFATSector) && (oldFATSector != -1)) // skipped in 1st loop. Write Sector only when new sector reached.
        {   
            // We are looping through the FAT, and the current cluster is represented in a different
            // sector of the FAT than the previous cluster.
            // We need to write out our local sector buffer, and read in the next one.

            // sdk3.1 adds this ifndef check so when single fat mode enabled, don't write the second FAT.
#ifdef ENABLE_WRITE_FAT2  /* Write FAT2 */
            // Write the pinned sector contents (FAT1) to FAT2.
            pb.sector = oldFATSector + iFirstFATSectorOnTheDevice + FATSize;
            pb.writeOffset = 0;
            pb.writeByteCount = BytesPerSector;
            pb.weight = kMediaCacheWeight_Low;  // FAT2 has a low weighting
            pb.flags = kMediaCacheFlag_ApplyWeight;
            media_cache_write(&pb);
#endif
            
            // Complete the pinned write to commit our changes to the FAT sector.
            media_cache_release(pb.token);
            
            // Now set up a pinned write for the new sector.
            pb.sector = FATsector + iFirstFATSectorOnTheDevice;
            pb.weight = kMediaCacheWeight_High;
            pb.flags = kMediaCacheFlag_ApplyWeight;
            
            if (media_cache_pinned_write(&pb) != SUCCESS)
            {
                LeaveNonReentrantSection();
                return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
            }
            p_u8_CopyOfASectorOfFAT = pb.buffer;
        } /* if */

        //
        // What's the offset in bytes of the FAT entry that represents
        // clusterno?
        //
        if (FatType == FAT12)
		{
			FAToffsetInBytes = clusterno + (clusterno>>1);
		}
        // clusterno * 4 or 2 gives offset into FAT32 or FAT16 table entry
		else if (FatType == FAT32)
		{
			FAToffsetInBytes = clusterno << 2;
		}
		else //Fat16
		{
			FAToffsetInBytes = clusterno << 1;
		}
        FATNtryOffsetInBytesInThisSector = FAToffsetInBytes & SectorMask;

        //
        // Read the current FAT entry (which may be a link to the next FAT entry),
        // overwrite the current FAT entry as "free",
        // and then see if there *was* actually a link to a next entry.
        //
        if (FatType == FAT32)
        {
            FATentry = FSGetDWord(p_u8_CopyOfASectorOfFAT ,FATNtryOffsetInBytesInThisSector);
            PutDword(p_u8_CopyOfASectorOfFAT ,FAT32FREECX,FATNtryOffsetInBytesInThisSector);
            exitCondition = ((0x0FFFFFFF==FATentry) || (0==FATentry));
        }
		else if (FatType == FAT12)
        {
            FATentry = FSGetWord(p_u8_CopyOfASectorOfFAT ,FATNtryOffsetInBytesInThisSector);
			FATentry &= (FATentry & FAT12EOF);
			exitCondition = ((((unsigned int)FATentry) > ((unsigned int)0x0FF5)) || (0==FATentry));
			ret = (FATentry & ~FAT12EOF);
            PutWord(p_u8_CopyOfASectorOfFAT,ret,FATNtryOffsetInBytesInThisSector);
        }
        else
        {
            FATentry = FSGetWord(p_u8_CopyOfASectorOfFAT ,FATNtryOffsetInBytesInThisSector);
			PutWord(p_u8_CopyOfASectorOfFAT ,FAT16FREECX,FATNtryOffsetInBytesInThisSector);
            exitCondition = ((((unsigned int)FATentry) > ((unsigned int)0xFFF0)) || (0==FATentry));
        }

        MediaTable[Device].TotalFreeClusters++;
        
	    //
	    // Check if FATentry refers to a real cluster, not free space nor
	    // the end of a cluster chain.
        //
        if (exitCondition)
        {   
            // Free space or the end of a cluster chain.
            break;
        }

        //
        // Set the new cluster number for the next loop.
        //
        clusterno = FATentry;

//      if(clusterno == FS_EOF) // early exit if early EOF hit
//         break;  // this was present in old ver below. Do we need this here too?  TOVERIFY5

        if(clusterno <=0)
        {
            media_cache_release(pb.token);
            LeaveNonReentrantSection();
            return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
        }
        
        //
        // Note the current sector in the FAT, before we loop.
        //
        oldFATSector = FATsector;

    } /* end for */

    // sdk3.1 adds this ifndef check so when single fat mode enabled, don't write the second FAT.
#ifdef ENABLE_WRITE_FAT2  /* Write FAT2   */
    // Write the pinned sector contents (FAT1) to FAT2.
    pb.sector = FATsector+iFirstFATSectorOnTheDevice+FATSize;
    pb.writeOffset = 0;
    pb.writeByteCount = BytesPerSector;
    pb.weight = kMediaCacheWeight_Low;  // FAT2 has a low weight
    pb.flags = kMediaCacheFlag_ApplyWeight;
    media_cache_write(&pb);
#endif

    // Complete the pinned write to commit our changes to the FAT sector.
    media_cache_release(pb.token);
    
    LeaveNonReentrantSection();
    return SUCCESS;
}




