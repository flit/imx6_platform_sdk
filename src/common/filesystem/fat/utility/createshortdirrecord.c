/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/CreateShortDirRecord.c $
 $Revision: 2 $                                       
 $Date: 9/18/03 6:50p $
 Description: CreateShortDirRecord.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <string.h>

#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "DIrOffset.h"




extern void GetDateTime(int *,int *);


/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t CreateShortDirRecord(uint8_t *filename,int32_t HandleNumber,int32_t ClusterNumber,int32_t DirAttr)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name or directory
                  2) Handle Number
                  3) Cluster Number
                  4) Directory Attribute

   Outputs:       Returns SUCCESS else an error code

   Description:   Creates new directory record in the free record of the directory sector

   Notes:

  Date Format:
   A FAT directory entry date stamp is a 16-bit field that is basically a date
   relative to the MS-DOS epoch of 01/01/1980.
     Bits  0–4: Day of month, valid value range 1-31 inclusive
     Bits  5–8: Month of year, 1 = January, valid value range 1–12 inclusive
     Bits 9–15: Count of years from 1980, valid value range 0–127 inclusive (1980–2107)

  Time Format:
   A FAT directory entry time stamp is a 16-bit field that has a granularity
   of 2 seconds.  The valid time range is from Midnight 00:00:00 to 23:59:58.
     Bits   0–4: 2-second count, valid value range 0–29 inclusive (0 – 58 seconds)
     Bits  5–10: Minutes, valid value range 0–59 inclusive
     Bits 11–15: Hours, valid value range 0–23 inclusive
<
----------------------------------------------------------------------------*/
RtStatus_t CreateShortDirRecord
(
  uint8_t *filename,    // SFN
  int32_t HandleNumber,
  int32_t ClusterNumber,
  int32_t DirAttr,
  int32_t FileSize
)
{
    RtStatus_t RetValue;
    int  date,time;
    uint8_t buf[32]; 

    memset(buf,0,32);
    memcpy(buf,filename,12);
    buf[DIR_ATTRIBUTEOFFSET] = DirAttr;

    PutWord(buf,(ClusterNumber >>16 )& 0x00ffff,DIR_FSTCLUSHIOFFSET);
    PutWord(buf,ClusterNumber & 0x00ffff,DIR_FSTCLUSLOOFFSET);
    PutDword(buf,FileSize,DIR_FILESIZEOFFSET);


    GetDateTime(&date,&time);
    PutWord(buf, date, DIR_CRTDATEOFFSET);       // Set creation date
    PutWord(buf, date, DIR_LSTACCDATEOFFSET);    // Set last access date
    PutWord(buf, date, DIR_WRTDATEOFFSET);       // Set modification date
    PutWord(buf, time, DIR_CRTTIMEOFFSET);       // Set creation time
    PutWord(buf, time, DIR_WRTTIMEOFFSET);       // Set modification time

    if(Handle[HandleNumber].StartingCluster != 0)
    {
        if((RetValue=(RtStatus_t)Fwrite(HandleNumber,buf,DIRRECORDSIZE)) <= 0)
            return RetValue;
    }
    else
        if((RetValue = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentSector,Handle[HandleNumber].BytePosInSector,buf,0,
        DIRRECORDSIZE,WRITE_TYPE_RANDOM)) <0)
            return RetValue;

    return SUCCESS;
}



