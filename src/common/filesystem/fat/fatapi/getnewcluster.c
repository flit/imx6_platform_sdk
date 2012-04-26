/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/GetNewcluster.c $                                        
 $Revision: 14 $                                       
 $Date: 9/17/03 5:02p $                                           
 Description: GetNewcluster.c
 Notes:	This file read provides FAT API function to get a new cluster
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
//#include <stdio.h>
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
#include "DirOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  int32_t GetNewcluster(int32_t Handlenumber)

   FunctionType:   Reentrant

   Inputs:         1) Handlenumber

   Outputs:        Updates the handle according to the new cluster.
                   Returns ERROR_OS_FILESYSTEM_NO_FREE_CLUSTER if no free cluster is available else error NOSPACEINROOTDIRECTORY

   Description:    Finds a new free cluster and writes its value in the FAT table
                   for current cluster's entry.  
----------------------------------------------------------------------------*/
RtStatus_t GetNewcluster(int32_t Handlenumber)
{
    int32_t  currentcluster,Devicenum;
    int   FATNtryoffset;	   
    int32_t FATsector;
   
    Devicenum = Handle[Handlenumber].Device;
    currentcluster = Handle[Handlenumber].CurrentCluster;
   
    EnterNonReentrantSection();
    
    ddi_ldl_push_media_task("GetNewcluster");
        
    if((currentcluster = FirstfreeAndallocate(Devicenum))<0)
    {
        ddi_ldl_pop_media_task();
        LeaveNonReentrantSection();
   	    return(ERROR_OS_FILESYSTEM_NO_FREE_CLUSTER);
    }
   
    Handle[Handlenumber].CurrentSector = Firstsectorofcluster(Devicenum,currentcluster);
        
    if((FATsector = FATsectorno(Devicenum,Handle[Handlenumber].CurrentCluster,&FATNtryoffset))<=0)
    {
        ddi_ldl_pop_media_task();
        LeaveNonReentrantSection();
        return  ERROR_OS_FILESYSTEM_NOT_VALID_SECTOR; 
    }
  
    /* write the entry in the sector no. at the offset in the sector */
    WriteFATentry(Devicenum,FATsector,FATNtryoffset,Handle[Handlenumber].CurrentCluster,currentcluster);

    /* update the handle */
		 
    Handle[Handlenumber].CurrentCluster = currentcluster;
    Handle[Handlenumber].BytePosInSector=0;
    Handle[Handlenumber].SectorPosInCluster=0;
 
    LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
	return (SUCCESS);							
}

