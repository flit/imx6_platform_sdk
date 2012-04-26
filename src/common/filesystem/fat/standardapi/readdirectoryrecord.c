/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/ReadDirectoryRecord.c $
 $Revision: 10 $                                       
 $Date: 9/18/03 5:27p $
 Description: ReadDirectoryRecord.c
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
>  Function Name: int64_t ReadDirectoryRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)RecordNumber
                  3)Pointer to Buffer

   Outputs:       Returns Number of Bytes read on Success else an Error Code

   Description:   Reads the directory record of the given record number
<
----------------------------------------------------------------------------*/
int64_t ReadDirectoryRecord(int32_t HandleNumber, int32_t RecordNumber, uint8_t *Buffer)
{
    RtStatus_t RetValue=SUCCESS;
    int32_t NumberOfBytestoSeek;
	int64_t Key, lTemp;

    if (Handle[HandleNumber].StartingCluster == 0)
    {
        if((lTemp = (int64_t)ReadRootdirRecord(HandleNumber,RecordNumber,Buffer))<0)
        {             
	        return lTemp;
        }
	    Key = ( ((int64_t)Handle[HandleNumber].Device << 44) | ((int64_t)Handle[HandleNumber].BytePosInSector<<32) | Handle[HandleNumber].CurrentSector);
	    return  Key;
	}
	else
	{
        if((NumberOfBytestoSeek = RecordNumber * DIRRECORDSIZE)!= Handle[HandleNumber].CurrentOffset)
        {
            if((RetValue = Fseek(HandleNumber,NumberOfBytestoSeek,SEEK_SET)) < 0)
		    {
                return RetValue;
		    }
        }    
	    if((Fread(HandleNumber,Buffer,DIRRECORDSIZE)) <= 0)
        {
	        return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;
        }
	    Key = ( ((int64_t)Handle[HandleNumber].Device << 44) | ((int64_t)(Handle[HandleNumber].BytePosInSector-32)<<32) | Handle[HandleNumber].CurrentSector);
  	    return Key;
    }
}
