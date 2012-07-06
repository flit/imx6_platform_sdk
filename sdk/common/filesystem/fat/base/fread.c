/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fread.c $
 $Revision: 19 $                                       
 $Date: 9/18/03 6:45p $
 Description: Fread.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include <string.h>
#include "fstypes.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "fs_steering.h"
#include <stdlib.h>

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t Fread(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to Buffer
                  3)Number of Bytes To Read

   Outputs:       Returns Number of bytes read upon success or 
                                 0 upon failures - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED,
                                                        ERROR_OS_FILESYSTEM_INVALID_MODE,
                                                        NumBytesToRead < 0,
                                                        ERROR_OS_FILESYSTEM_EOF,
                                                        ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE

   Description:   Reads the Specified number of Bytes from the FILE

<
----------------------------------------------------------------------------*/
RtStatus_t Fread_FAT(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead)
{
    RtStatus_t RetValue=SUCCESS;
    uint8_t *buf;
    int32_t FileSize,RemainBytesToRead;
    int32_t Device,BuffOffset=0,BytesToCopy;
    int32_t RemainBytesInSector,BytesPerSector;
    uint32_t cacheToken;

    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
    {
        // Error - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED 
        return 0;
    }

    Device = Handle[HandleNumber].Device;
    BytesPerSector = MediaTable[Device].BytesPerSector;

    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return 0;
    }    

    if((Handle[HandleNumber].Mode & READ_MODE)!=READ_MODE )
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_MODE;
        return 0;
    }    

    // We treat directories as files, so a special read mode for these.
    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(HandleNumber);
    }

    if(FileSize < (NumBytesToRead + Handle[HandleNumber].CurrentOffset))
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        NumBytesToRead = FileSize - Handle[HandleNumber].CurrentOffset;
    }

    RemainBytesToRead = NumBytesToRead;
    if (RemainBytesToRead<0)
    {
        return 0;
    }    

    // On EOF
    if (NumBytesToRead==0)
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        return 0;
    }    
    
    ddi_ldl_push_media_task("Fread_FAT");

    RemainBytesInSector = BytesPerSector - Handle[HandleNumber].BytePosInSector;

    while(RemainBytesToRead >0)
    {
        if (((RemainBytesInSector != 0) && (RemainBytesToRead > RemainBytesInSector)) || 
			(RemainBytesToRead <= BytesPerSector))
        {
        	/*if the start point of the data is not aligned to sector, read a single sector and get the data*/
			if(((RemainBytesInSector != 0) && (RemainBytesToRead > RemainBytesInSector))) {
				BytesToCopy	= RemainBytesInSector;
				RemainBytesInSector = 0;
			} else {
			    BytesToCopy = RemainBytesToRead;	
			}

	        if ((RetValue = UpdateHandleOffsets(HandleNumber)))
	        {
	            Handle[HandleNumber].ErrorCode = RetValue;
	            ddi_ldl_pop_media_task();
	            return (NumBytesToRead-RemainBytesToRead);
	        }

		    EnterNonReentrantSection();
	        if((buf = (uint8_t *)FSReadSector(Device,Handle[HandleNumber].CurrentSector,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t *)0)
			{
	            Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
			    LeaveNonReentrantSection();
	            ddi_ldl_pop_media_task();

	            return NumBytesToRead-RemainBytesToRead;  // READSECTOR_FAIL return here in 2.6 version fixes mmc eject bug 7183.
			}

	        RemainBytesToRead -= BytesToCopy;

	        memcpy(Buffer + BuffOffset, buf + Handle[HandleNumber].BytePosInSector, BytesToCopy);
	        
	        FSReleaseSector(cacheToken);
		    LeaveNonReentrantSection();

	        Handle[HandleNumber].CurrentOffset += BytesToCopy;
	        Handle[HandleNumber].BytePosInSector += BytesToCopy;

	        BuffOffset+=BytesToCopy;			
        } else {
			/*Multiple sectors read for large chunk of data*/	
			int sectorNum = 0, sectorStart = 0;
			int prevSectorPos = 0, prevSectorIndex = 0, sectorToBeRead = 0, prevClusterIndex = 0;
			BytesToCopy = RemainBytesToRead - RemainBytesToRead % BytesPerSector; // need to aligned to sector
			sectorNum = BytesToCopy / BytesPerSector;

			prevSectorIndex = Handle[HandleNumber].CurrentSector;
			prevClusterIndex = Handle[HandleNumber].CurrentCluster;
			while(sectorNum--)
			{
				Handle[HandleNumber].BytePosInSector = BytesPerSector; //always aligned to sector
	
				if ((RetValue = UpdateHandleOffsets(HandleNumber))) // increase the sector address by 1
				{
					Handle[HandleNumber].ErrorCode = RetValue;
					ddi_ldl_pop_media_task();
					return (NumBytesToRead-RemainBytesToRead);
				}		

				if(sectorStart == 0)
				sectorStart = Handle[HandleNumber].CurrentSector;

				if(prevSectorIndex + 1 == Handle[HandleNumber].CurrentSector) /*adjacent sectors*/
				{
					sectorToBeRead ++;
					prevSectorIndex = Handle[HandleNumber].CurrentSector;
					prevClusterIndex = Handle[HandleNumber].CurrentCluster;
					prevSectorPos = Handle[HandleNumber].SectorPosInCluster;
				} else { 
					/*backwards to the previous sector index, if the sector is not continous in physical address.*/
					Handle[HandleNumber].CurrentSector = prevSectorIndex;
					Handle[HandleNumber].CurrentCluster = prevClusterIndex;	
					Handle[HandleNumber].SectorPosInCluster = prevSectorPos;
					break;
				}
			}		

			BytesToCopy = sectorToBeRead * BytesPerSector;
	
			EnterNonReentrantSection();
		
			/*reuse the buffer to avoid extra memory copy*/
			if((buf = (uint8_t *)FSReadMultiSectors(Device,sectorStart,WRITE_TYPE_RANDOM, 
					(uint8_t *)(Buffer + BuffOffset), BytesToCopy))==(uint8_t *)0)
			{
				Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
				LeaveNonReentrantSection();
				ddi_ldl_pop_media_task();

				return NumBytesToRead-RemainBytesToRead;  // READSECTOR_FAIL return here in 2.6 version fixes mmc eject bug 7183.
			}

			RemainBytesToRead -= BytesToCopy;

			Handle[HandleNumber].CurrentOffset += BytesToCopy;

			Handle[HandleNumber].BytePosInSector = BytesPerSector; //always aligned to sector

			LeaveNonReentrantSection();

			BuffOffset+=BytesToCopy;			
        }
    }

    ddi_ldl_pop_media_task();

    // Force to RtStatus - all errors are negative so this will still work.
    return (RtStatus_t) NumBytesToRead;
}

RtStatus_t Fread_multi_sectors(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead)
{
    uint32_t clusterSize, sectorSize, NumBytesRead = 0;
    uint32_t Device, count, i, res;
    uint8_t *buffer;

    Device = Handle[HandleNumber].Device;
    sectorSize = MediaTable[Device].BytesPerSector;
    clusterSize = sectorSize * MediaTable[Device].SectorsPerCluster;

    buffer = (uint8_t *)malloc(NumBytesToRead);

    if(NumBytesToRead <= sectorSize)
    {
        while(NumBytesRead == 0)
            NumBytesRead = Fread_FAT(HandleNumber, (uint8_t *)buffer, NumBytesToRead);
    }
    else
    {
        count = (uint32_t) NumBytesToRead / sectorSize ;
        if((uint32_t) NumBytesToRead % sectorSize)
            count++;

//        printf("%X cnt %X\n",NumBytesToRead, count);
        i=0;
        while(i<count)
        {
            res = Fread_FAT(HandleNumber, (uint8_t *)(buffer + sectorSize * i), sectorSize);
            NumBytesRead += res;
            if (res != 0)
                i++;
//            printf("res %X \n",res);
        }
    }

    memcpy((uint8_t *)Buffer, (uint8_t *)buffer, NumBytesRead);

    free(buffer);

    return (RtStatus_t) NumBytesRead;
}
