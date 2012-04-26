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
#include "types.h"
#include "fstypes.h"
#include "errordefs.h"
#include "platform.h"
#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "os/filesystem.h"
#include "os/filesystem/fat/include/fat_internal.h"

/*----------------------------------------------------------------------------

>  Function Name:  int FSInit(int _X *bufx, int _Y *bufy, int maxdevices, int maxhandles, int maxcaches)

   FunctionType:  

   Inputs:         a) Pointer to X buffer for allocation of cache buffers
                   b) Pointer to Y buffer for allocation of handles, descriptors, etc
                   c) Max number of internal + external media supported.
                   d) Max handles supported.
                   e) Max cache buffers supported.

   Outputs:        Returns 0, if Success, else ERROR CODE

   Description:    Initialization of FileSystem.
<
--------- -------------------------------------------------------------------*/
void  FSClearDriveBuf(int DriveNumber,int maxhandles)
{
    int i;
    
    // setup handle
    for (i=0; i < maxhandles; i++)
    {
        if(Handle[i].Device == DriveNumber)
            Handle[i].HandleActive=0;
    }

}

