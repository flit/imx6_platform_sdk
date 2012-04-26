/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/filesetdate.c $
 $Revision: 6 $
 $Date: 9/13/03 12:20p $
 Description: filesetdate.c
 Notes: This file read provides base api functon to set the date or time of the file.
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

>  Function Name: int32_t filesetdate(uint8_t *FilePath,int32_t crt_mod_date_time_para,DIR_DATE *dirdate,DIR_TIME *dirtime)

   FunctionType:  Reentrant

   Inputs:        1) FilePath
                  2) create\modify\date\time parameter
                  3) pointer to structure DIR_DATE
                  4) pointer to structure DIR_TIME

   Outputs:       Returns SUCCESS or error code if error occurs.
   
   Description:   This function sets the creation / modification date or time of 
                  the file referenced by the given handle to the specified date or time.

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
<----------------------------------------------------------------------------*/
RtStatus_t filesetdate(uint8_t *FilePath,int32_t crt_mod_date_time_para,DIR_DATE *dirdate,DIR_TIME *dirtime)
{
    uint32_t offset=0;
    int32_t HandleNumber;
    RtStatus_t Retval = SUCCESS;
    int date_time,year,month;
    int hour,minute,second;

    if((HandleNumber = Fopen(FilePath,(uint8_t *)"r")) < 0)
        return (RtStatus_t)HandleNumber;

    if(crt_mod_date_time_para == CREATION_DATE)
        offset = DIR_CRTDATEOFFSET;
    
    else if(crt_mod_date_time_para == CREATION_TIME)
        offset = DIR_CRTTIMEOFFSET;

    else if(crt_mod_date_time_para == MODIFICATION_DATE)
        offset = DIR_WRTDATEOFFSET;

    else if(crt_mod_date_time_para == MODIFICATION_TIME)
        offset = DIR_WRTTIMEOFFSET;

    if(crt_mod_date_time_para == CREATION_DATE || crt_mod_date_time_para == MODIFICATION_DATE)
    {
        // Local vars must have room to left shift the 8-bit dirdate fields
        month = ((dirdate->Month << 5 ) & 0x01E0);
        year = ((dirdate->Year -1980) << 9 );
        date_time = (dirdate->Day | month | year); 
    }
    else
    {
        // Local vars must have room to left shift the 8-bit dirtime fields
        second = dirtime->Second >> 1;
        minute = ((dirtime->Minute  << 5) & 0x07E0);
        hour = ((dirtime->Hour  << 11 ) & 0xF800);
        date_time = (second | minute | hour);
    }

    if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,
    (offset + Handle[HandleNumber].DirOffset),(uint8_t *)&date_time,0,2,WRITE_TYPE_RANDOM)) <0)
        return Retval;

    Freehandle(HandleNumber);
    return  SUCCESS;
}
