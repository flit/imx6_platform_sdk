/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fseek.c $
 $Revision: 23 $                                       
 $Date: 9/27/03 2:44p $
 Description: Fseek.c
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
#include "fs_steering.h"
#include "os/filesystem.h"


#define INVALID_CLUSTER     0x7fffffff

/*----------------------------------------------------------------------------
>  Function Name: void SeekPoint_InitializeBuffer(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)Handle number

   Outputs:       Nil

   Description:   Initialize seekpoint buffer and seekpoint step
   
<
----------------------------------------------------------------------------*/
void SeekPoint_InitializeBuffer(int32_t HandleNumber)
{
    int i;
    
    Handle[HandleNumber].SeekPointsClusterStep=INVALID_CLUSTER;
    Handle[HandleNumber].SeekPointsBaseFileSize = 0;
	for(i=0; i < NUM_SEEKPOINTS_CACHED; i++)
	    Handle[HandleNumber].SeekPointsClusters[i] = INVALID_CLUSTER;
}

/*----------------------------------------------------------------------------
>  Function Name: void SeekPoint_CalculateSeekPointStep(int32_t HandleNumber, int32_t FileSize)

   FunctionType:  Reentrant

   Inputs:        1)Handle number
                  2)old File size
                  3)new File size

   Outputs:       Nil

   Description:   Calculate seekpoint step according to the file size
   
<
----------------------------------------------------------------------------*/
void SeekPoint_CalculateSeekPointStep(int32_t HandleNumber, int32_t oldFileSize, int32_t newFileSize)
{
    if(Handle[HandleNumber].SeekPointsClusterStep==INVALID_CLUSTER || oldFileSize != newFileSize)
    {
        int32_t SeekPointsClusterStep, oldSeekPointsClusterStep;      
        
        //First calculate how many clusters the file uses              
        SeekPointsClusterStep = newFileSize >> MediaTable[Handle[HandleNumber].Device].ClusterShift;
        
        // calculate the step of the seekpoint
        SeekPointsClusterStep/=NUM_SEEKPOINTS_CACHED;
        if(SeekPointsClusterStep == 0)  
        {
            SeekPointsClusterStep = 1;
        }
        
        oldSeekPointsClusterStep = Handle[HandleNumber].SeekPointsClusterStep;
        Handle[HandleNumber].SeekPointsClusterStep = SeekPointsClusterStep;
        Handle[HandleNumber].SeekPointsBaseFileSize = newFileSize;

        //if file size increases, we need adjust SeekPointsClusterStep and move the seekpoint buffer
        //this case happens when file is opened with mode "w+", 
        if((oldSeekPointsClusterStep != INVALID_CLUSTER) && (oldSeekPointsClusterStep != SeekPointsClusterStep))
        {
            int i,cnt;
            int32_t ClusterOffsetInFile = oldSeekPointsClusterStep;
            int32_t SeekPointsClustersBackup[NUM_SEEKPOINTS_CACHED];
            int32_t *pSeekPointsClusters = Handle[HandleNumber].SeekPointsClusters;
            
            //backup the old seekpoint buffer
            memcpy(SeekPointsClustersBackup,pSeekPointsClusters, sizeof(int32_t)*NUM_SEEKPOINTS_CACHED);
            
           	for(i=0; i < NUM_SEEKPOINTS_CACHED; i++)
           	{
           	    //The file size only increases ( we don't support file shrink)
           	    //So the seekpoint can only move backward.
           	    pSeekPointsClusters[i] = INVALID_CLUSTER;
           	    if(SeekPointsClustersBackup[i]!= INVALID_CLUSTER)
           	    {
           	        // ClusterOffsetInFile presents the cluster position of old seekpoint buffer
           	        // check whether the old seekpoint should move to the new seekpoint buffer
           	        // Because file increases, seekpoint step increases, we need discard some old seekpoint
           	        if(ClusterOffsetInFile >= SeekPointsClusterStep &&
           	           ClusterOffsetInFile%SeekPointsClusterStep == 0)
           	        {
           	            cnt = ClusterOffsetInFile/SeekPointsClusterStep -1;
           	            pSeekPointsClusters[cnt] = SeekPointsClustersBackup[i];
           	        }
           	    }
           	    ClusterOffsetInFile += oldSeekPointsClusterStep;
        	}

        }
    }
} 

/*----------------------------------------------------------------------------
>  Function Name: SeekPoint_FillSeekPoint(int32_t HandleNumber, int32_t ClusterOffsetInFile, int32_t CurrentCluster)

   FunctionType:  Reentrant

   Inputs:        1)Handle number
                  2)ClusterOffsetInFile: the cluster offset of the current cluster with the beginning of file
                  3)CurrentCluster:  

   Outputs:       Nil

   Description:   Fill seekpoint cache buffer
   
<
----------------------------------------------------------------------------*/
void SeekPoint_FillSeekPoint(int32_t HandleNumber, int32_t ClusterOffsetInFile, int32_t CurrentCluster)
{
    // check whether the CurrentCluster should be cached.
    if( ClusterOffsetInFile >= Handle[HandleNumber].SeekPointsClusterStep &&
        ClusterOffsetInFile % Handle[HandleNumber].SeekPointsClusterStep == 0)
    {
        //Calculate the position in Seekpoint buffer
        int cnt = ClusterOffsetInFile/Handle[HandleNumber].SeekPointsClusterStep - 1;
        if(Handle[HandleNumber].SeekPointsClusters[cnt] == INVALID_CLUSTER)
        {
            Handle[HandleNumber].SeekPointsClusters[cnt] = CurrentCluster;
        }
    }
    
}

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t Fseek(int32_t HandleNumber, int32_t NumBytesToSeek, int32_t SeekPosition)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)NumBytesToSeek
                  3)SeekPosition

   Outputs:       Returns 0 or ERROR Code if  Error Occurs

   Description:   Adjusts the current position by the no. of byte specified

<
----------------------------------------------------------------------------*/
RtStatus_t Fseek_FAT(int32_t HandleNumber, int32_t NumBytesToSeek, int32_t SeekPosition)
{
    int32_t NumClusterSeek,i;
    RtStatus_t RetValue = SUCCESS;
    int RemainingByteOffsetInCluster,NumSectors;
    int32_t CurrentCluster,FileSize,CrtCLuster;
    int32_t Device;
    int32_t CurrentByteOffsetInCluster,RelativeSeekByteoffset;
    int32_t CurrentClusterByteOffsetInFile,SeekTargetByteOffset;  
    int32_t ClusterOffsetInFile;

    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
	{
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}
	
	Device = Handle[HandleNumber].Device;

    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return RetValue;
    }

    // We treat directories as files, so a special read mode for these.
    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize =  0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(HandleNumber);
        SeekPoint_CalculateSeekPointStep(HandleNumber,Handle[HandleNumber].SeekPointsBaseFileSize,FileSize);
    }
       
    if(SeekPosition == SEEK_SET)    
        SeekTargetByteOffset = NumBytesToSeek;
    else if(SeekPosition == SEEK_CUR)
        SeekTargetByteOffset = NumBytesToSeek + Handle[HandleNumber].CurrentOffset;
    else if(SeekPosition == SEEK_END)
        SeekTargetByteOffset = FileSize + NumBytesToSeek;
    else 
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_FSEEK_FAILED;
        return ERROR_OS_FILESYSTEM_FSEEK_FAILED;
    }    
				  
    if (SeekTargetByteOffset < 0)
        SeekTargetByteOffset = 0;
    if (SeekTargetByteOffset >= FileSize)
        SeekTargetByteOffset = FileSize;

    // find the begining offset of current cluster
	
    CurrentByteOffsetInCluster = Handle[HandleNumber].CurrentOffset & MediaTable[Device].ClusterMask;
    
    // Check for boundary condition. We could be at the end of the sector and cluster.
    if (CurrentByteOffsetInCluster == 0)
    {
        if (Handle[HandleNumber].CurrentOffset)
        {

               CurrentByteOffsetInCluster = Handle[HandleNumber].BytePosInSector + Handle[HandleNumber].SectorPosInCluster*MediaTable[Device].BytesPerSector;
        }
    }
    
    CurrentClusterByteOffsetInFile =Handle[HandleNumber].CurrentOffset - CurrentByteOffsetInCluster;

    RelativeSeekByteoffset =  SeekTargetByteOffset - CurrentClusterByteOffsetInFile;
  
    // if RelativeSeekByteoffset is positive then seek from file's current position, else seek from begining    
    if(RelativeSeekByteoffset >= 0) 
    {
        

        NumClusterSeek = RelativeSeekByteoffset >> MediaTable[Device].ClusterShift;

        RemainingByteOffsetInCluster = RelativeSeekByteoffset &  MediaTable[Device].ClusterMask;        

        CurrentCluster = Handle[HandleNumber].CurrentCluster;

        NumSectors = (RemainingByteOffsetInCluster >> MediaTable[Device].SectorShift);
        
        ClusterOffsetInFile = CurrentClusterByteOffsetInFile >> MediaTable[Device].ClusterShift;

    }
    else
    {

        NumClusterSeek = SeekTargetByteOffset >> MediaTable[Device].ClusterShift;

        RemainingByteOffsetInCluster = SeekTargetByteOffset &  MediaTable[Device].ClusterMask;        
  
        CurrentCluster = Handle[HandleNumber].StartingCluster;

        NumSectors = (RemainingByteOffsetInCluster >> MediaTable[Device].SectorShift);
        
        ClusterOffsetInFile = 0;

    }
    
    // we don't use seekpoint cache for directory 
    // for directory the value of SeekPointsClusterStep is INVALID_CLUSTER
    if((NumClusterSeek > 0) && (Handle[HandleNumber].SeekPointsClusterStep!=INVALID_CLUSTER))
    {
        int32_t *pSeekPointsClusters = Handle[HandleNumber].SeekPointsClusters;
        int32_t loopstart = (SeekTargetByteOffset >> MediaTable[Device].ClusterShift)/Handle[HandleNumber].SeekPointsClusterStep -1;
        
        // find closest seekpoint cluster. 
        // loopstart is the closest seekpoint to the target seek position.
        // we start search backward from loopstart whether there is valid seekpoint
        if(loopstart >= NUM_SEEKPOINTS_CACHED)
            loopstart = NUM_SEEKPOINTS_CACHED -1;
        for (i = loopstart; i >=0; i--)
        {
            if(pSeekPointsClusters[i]!= INVALID_CLUSTER)
            {
                int32_t SeekPointClusterByteOffsetInFile =  ((i+1)*Handle[HandleNumber].SeekPointsClusterStep) << MediaTable[Device].ClusterShift; 
                
                //if it is seek forward, we need check seekpoint cluster and current cluster which is closer to target seek position
                if(RelativeSeekByteoffset >= 0)
                {
                    // current cluster is closer to target position, nothing to do.
                    if(CurrentClusterByteOffsetInFile >= SeekPointClusterByteOffsetInFile )
                    {
                        break;
                    }
                }
                
                //we start from seekpoint cluster. update NumClusterSeek and CurrentCluster
                RelativeSeekByteoffset = SeekTargetByteOffset - SeekPointClusterByteOffsetInFile;
                NumClusterSeek = RelativeSeekByteoffset >> MediaTable[Device].ClusterShift;
                CurrentCluster = pSeekPointsClusters[i];
                ClusterOffsetInFile = SeekPointClusterByteOffsetInFile >> MediaTable[Device].ClusterShift;
                break;
            }
        }
    }
    
    ddi_ldl_push_media_task("Fseek_FAT");
    
    // Find the target cluster
    for (i=0; i < NumClusterSeek ;i++)
    {    
        CrtCLuster = CurrentCluster;
        CurrentCluster = Findnextcluster(Device,CurrentCluster);
        if((CurrentCluster == ERROR_OS_FILESYSTEM_EOF)&&(i == NumClusterSeek -1))
        {
            // reach the end of file
            CurrentCluster = CrtCLuster;
            NumSectors = MediaTable[Device].SectorsPerCluster - 1;  
            // Since the cluster has not changed, the Remaining offset should be changed
            RemainingByteOffsetInCluster = (NumSectors + 1) * MediaTable[Device].BytesPerSector;
            break;
        }    
        if(CurrentCluster < 0)
        {
            // error happens
            Handle[HandleNumber].ErrorCode = CurrentCluster;
            ddi_ldl_pop_media_task();
            return (RtStatus_t)CurrentCluster;
        }
            
        ClusterOffsetInFile ++;
        // check whether the cluster should be saved in seekpoint buffer
        SeekPoint_FillSeekPoint(HandleNumber,ClusterOffsetInFile, CurrentCluster);
    }

    //Updated Handle Entries
    Handle[HandleNumber].CurrentOffset = SeekTargetByteOffset;  
    Handle[HandleNumber].BytePosInSector = RemainingByteOffsetInCluster - NumSectors * MediaTable[Device].BytesPerSector;
    Handle[HandleNumber].SectorPosInCluster = NumSectors;
    Handle[HandleNumber].CurrentCluster = CurrentCluster;
    Handle[HandleNumber].CurrentSector = Handle[HandleNumber].SectorPosInCluster +
    Firstsectorofcluster(Device,CurrentCluster);
    ddi_ldl_pop_media_task();
    return SUCCESS;
}

/*-------------------------------------------------------------------------------------
>  Function Name: int SaveHandleContext(int32_t HandleNumber, HandleContext_t *Context)

   FunctionType:  Reentrant

   Inputs:        1)Handle number
                  2)Context

   Outputs:       Returns SUCCESS or Error if the context of handle is saved

   Description:   Save the context of the handle
   
<
---------------------------------------------------------------------------------------*/
int SaveHandleContext(int32_t HandleNumber, HandleContext_t *Context)
{
    int RetValue=0;
    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
	{
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}
    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return RetValue;
    }
    Context->CurrentOffset      = (Handle[HandleNumber].CurrentOffset >> MediaTable[Handle[HandleNumber].Device].ClusterShift);
    Context->CurrentCluster     = Handle[HandleNumber].CurrentCluster;
    return SUCCESS;
}

/*----------------------------------------------------------------------------------------
>  Function Name: int RestoreHandleContext(int32_t HandleNumber, HandleContext_t *Context)

   FunctionType:  Reentrant

   Inputs:        1)Handle number
                  2)Context

   Outputs:       Returns SUCCESS or Error if the context of handle is restored

   Description:   restore the context of the handle
   
<
-----------------------------------------------------------------------------------------*/
int RestoreHandleContext(int32_t HandleNumber, HandleContext_t *Context)
{
    int RetValue=0;
    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
	{
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}
    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return RetValue;
    }
    Handle[HandleNumber].CurrentOffset          =   (Context->CurrentOffset << MediaTable[Handle[HandleNumber].Device].ClusterShift);     
    Handle[HandleNumber].BytePosInSector        =   0;
    Handle[HandleNumber].SectorPosInCluster     =   0;
    Handle[HandleNumber].CurrentCluster         =   Context->CurrentCluster;
    Handle[HandleNumber].CurrentSector          =   Firstsectorofcluster(Handle[HandleNumber].Device,Context->CurrentCluster);
    
    SeekPoint_InitializeBuffer(HandleNumber);
    
    return SUCCESS;
}

