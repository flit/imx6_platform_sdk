/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/filesetattrib.c $
 $Revision: 6 $                                       
 $Date: 9/13/03 12:20p $
 Description: fileSetattrib.c
 Notes:	This file read provides base api functon to set the attribute of the file.
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

>  Function Name: int32_t filesetattrib(int32_t HandleNumber,int32_t dirattribute)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)dirattribute

   Outputs:       Returns SUCCESS or ERROR Code if  Error Occurs

   Description:   Sets directory attributes for a file

<
----------------------------------------------------------------------------*/
int32_t filesetattrib(int32_t HandleNumber,int32_t dirattribute)
{
    RtStatus_t Retval;
    EnterNonReentrantSection();
    if((HandleNumber <0 )||(HandleNumber >= maxhandles))
    {
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}

    if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,
    (DIR_ATTRIBUTEOFFSET + Handle[HandleNumber].DirOffset),(uint8_t *)&dirattribute,0,2,WRITE_TYPE_RANDOM)) <0)
	{
	    LeaveNonReentrantSection();
		return Retval;
	}

    LeaveNonReentrantSection();
    return  SUCCESS;
}
