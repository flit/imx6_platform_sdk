/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/Firstsectorofcluster.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: Firstsectorofcluster.c
 Notes:	This file read provides first sector no. of given cluster
 ----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
/*----------------------------------------------------------------------------
>  Function Name: int32_t Firstsectorofcluster(int32_t DeviceNum,int32_t clusterno)

   FunctionType:  Reentrant

   Inputs:        1) Device number
				  2) cluster no.

   Outputs:       Returns First sector no. of given cluster 

   Description:   Determines First sector of given cluster by considering sector per cluter
                  and first data sector 
<
----------------------------------------------------------------------------*/
int32_t Firstsectorofcluster(int32_t DeviceNum,int32_t clusterno)
{
    int32_t sectorno;

    if(clusterno < 0)
        return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
    else if (clusterno == 0)
        sectorno = MediaTable[DeviceNum].FirRootdirsec;
	else
     	sectorno = ((clusterno - 2) * MediaTable[DeviceNum].SectorsPerCluster) + MediaTable[DeviceNum].FIRSTDataSector;

	return (sectorno);
}	 


