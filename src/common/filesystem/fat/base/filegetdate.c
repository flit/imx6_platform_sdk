/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/filegetdate.c $
 $Revision: 6 $                                       
 $Date: 9/13/03 12:20p $
 Description: filegetdate.c
 Notes:	This file read provides base api functon to find the date or time of the file.
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

>  Function Name: int32_t filegetdate(int32_t HandleNumber,int32_t crt_mod_date_time_para,DIR_DATE *dirdate,DIR_TIME *dirtime)

   FunctionType:  Reentrant

   Inputs:        1) HandleNumber
                  2) create\modify\date\time parameter
                  3) pointer to sturcture DIR_DATE
                  4) pointer to structure DIR_TIME

   Outputs:       Returns SUCCESS or error code if error occurs.
   
   Description:   This function finds the creation / modification date or time of 
                  the file referenced by the given handle number.
<
----------------------------------------------------------------------------*/
int32_t filegetdate(int32_t HandleNumber,int32_t crt_mod_date_time_para,DIR_DATE *dirdate,DIR_TIME *dirtime)
{
    int date_time,offset=0;
    uint8_t *buf;
    uint32_t cacheToken;

    if((HandleNumber < 0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
        
    if(crt_mod_date_time_para == CREATION_DATE)
	    offset = DIR_CRTDATEOFFSET;
    
    else if(crt_mod_date_time_para == CREATION_TIME)
	    offset = DIR_CRTTIMEOFFSET;

    else if(crt_mod_date_time_para == MODIFICATION_DATE)
	    offset = DIR_WRTDATEOFFSET;

    else if(crt_mod_date_time_para == MODIFICATION_TIME)
	    offset = DIR_WRTTIMEOFFSET;

    EnterNonReentrantSection();

    if((buf = (uint8_t *)FSReadSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t*)0)
	{
	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}
    date_time = FSGetWord((uint8_t*)buf,(offset + Handle[HandleNumber].DirOffset));
    FSReleaseSector(cacheToken);
    LeaveNonReentrantSection();

    if(crt_mod_date_time_para == CREATION_DATE || crt_mod_date_time_para == MODIFICATION_DATE)
    {
	    dirdate->Day = date_time & 0x001F;
	    dirdate->Month = (date_time & 0x01E0) >> 5;
	    dirdate->Year = ((date_time & 0xFE00) >> 9) + 1980;
	}
	else
	{
		dirtime->Second = (date_time & 0x001F)*2;
		dirtime->Minute = (date_time & 0x07E0) >> 5;
		dirtime->Hour = ((date_time & 0xF800) >> 11);
	}
    return  SUCCESS;
}
