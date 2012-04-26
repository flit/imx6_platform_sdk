/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/ReadRootdirRecord.c $                                        
 $Revision: 7 $                                       
 $Date: 9/13/03 12:20p $                                           
 Description: ReadRootdirRecord.c
 Notes:	This file read provides base function to read root directory record
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
#include <string.h>

/*----------------------------------------------------------------------------

>  Function Name: int32_t ReadRootdirRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)RecordNumber
                  3)Pointer to Buffer

   Outputs:       Number of Bytes read if Success else an Error

   Description:   Reads the directory record of the given record number

<
----------------------------------------------------------------------------*/
int32_t ReadRootdirRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer)
{
    int32_t DeviceNum; 
    RtStatus_t Retval;
    uint8_t *buf;
    uint32_t cacheToken;

    DeviceNum = Handle[HandleNumber].Device;
    if (MediaTable[DeviceNum].FATType ==FAT12 ||MediaTable[DeviceNum].FATType ==FAT16)
    {
        if(RecordNumber >= MediaTable[ DeviceNum].MaxRootDirEntries || RecordNumber < 0 )
        {
            return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;
        }

        if((Retval=SetcurrentPos(HandleNumber,RecordNumber))<0)
        {
	        return Retval;
        }

	    EnterNonReentrantSection();
        if((buf = (uint8_t *)FSReadSector(DeviceNum,Handle[HandleNumber].CurrentSector,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t*)0)
		{
		    LeaveNonReentrantSection();
			return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
		}
		
	    memcpy(Buffer, buf + Handle[HandleNumber].BytePosInSector, DIRRECORDSIZE);
        
        FSReleaseSector(cacheToken);
	    LeaveNonReentrantSection();
 
        if(FSGetByte(Buffer,0) == 0)
        {
            return 0;
        }
      
        return DIRRECORDSIZE;	 //32
    
    }
    else
    {
        return  ERROR_OS_FILESYSTEM_MEDIA_TYPE_NOT_SUPPORTED;
    }
}

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t SetcurrentPos(int32_t HandleNumber,int32_t RecordNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)RecordNumber
                  

   Outputs:       SUCCESS OR error code if error occurs   

   Description:   Sets the given handle according to the given record number  
<
----------------------------------------------------------------------------*/
RtStatus_t SetcurrentPos(int32_t HandleNumber,int32_t RecordNumber)
{
    int DeviceNum; 
    int32_t offset;
    int32_t sectorno;  
 	   
 	DeviceNum = 	Handle[HandleNumber].Device;
 	offset = RecordNumber * DIRRECORDSIZE;
    Handle[HandleNumber].CurrentOffset = offset;

    sectorno = offset >> MediaTable[DeviceNum].SectorShift;
	  
    Handle[HandleNumber].CurrentSector = sectorno + MediaTable[DeviceNum].FirRootdirsec;
    Handle[HandleNumber].BytePosInSector = offset &  MediaTable[DeviceNum].SectorMask;

    return SUCCESS;
}

    
