/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/common/Fsinit.c $              
 $Revision: 4 $                                       
 $Date: 9/18/03 10:37a $      
 Description: Fsinit.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <string.h>

#include "types.h"
#include "fstypes.h"
#include <error.h>
#include "os/filesystem/fsapi.h"
#include "platform.h"
#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "filespec.h"
#include "os/filesystem.h"
#include "hw/profile/hw_profile.h"

/*----------------------------------------------------------------------------
		Globals and Declarations
----------------------------------------------------------------------------*/

int32_t g_FSinitErrorCode = 0;
HandleTable_t * Handle;
FileSystemMediaTable_t * MediaTable;
FileSpecs_t * FileSpec;

/*----------------------------------------------------------------------------

>  Function Name:  RtStatus_t FSInit(uint8_t *bufx, uint8_t *bufy, int32_t maxdevices, int32_t maxhandles, int32_t maxcaches)

   FunctionType:   Non-reentrant

   Inputs:         a) Pointer to X buffer for allocation of cache buffers.
                   b) Pointer to Y buffer for allocation of handles, descriptors, etc.
                   c) Max number of internal + external media supported.
                   d) Max handles supported.
                   e) Max cache buffers supported.

   Outputs:        Returns 0, if Success else an ERROR CODE

   Description:    Initialization of FileSystem.
<
--------- -------------------------------------------------------------------*/

RtStatus_t  FSInit
(
    uint8_t *bufx, 
    uint8_t *bufy, 
    int32_t maxdevices, 
    int32_t maxhandles, 
    int32_t maxcaches
)
{
    // Assign pointers
    MediaTable =  (FileSystemMediaTable_t *)&bufy[0];
    Handle = (HandleTable_t *)&bufy[maxdevices*sizeof(FileSystemMediaTable_t)];
    FileSpec = (FileSpecs_t *)&bufy[maxdevices*sizeof(FileSystemMediaTable_t) +
                                   maxhandles*sizeof(HandleTable_t)];

    // Now initialize the handle table to 0.
    memset(&Handle[0], 0, sizeof(Handle[0]) * maxhandles);

    return SUCCESS;
}

