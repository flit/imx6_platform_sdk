/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/writeFATentry.c $                                        
 $Revision: 14 $                                       
 $Date: 9/29/03 2:32p $                                           
 Description: WriteFATentry.c
 Notes:	 This file read provides FAT API to write entry in FAT Table
 ----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t  WriteFATentry(int32_t DeviceNum,
    int32_t FATsector,int32_t FATNtryoffset,int32_t clusterno,int32_t writentry)
 
   FunctionType:  Reentrant

   Inputs:        1) Device number
				  2) FATsector
				  3) FATNtryoffset
				  4) cluster no.
				  5) write entry

   Outputs:       Returns SUCCESS else an error code

   Description:   Writes FAT entry  for the given cluster no. at the given FAT sector 
                  and FATentryoffset depending upon FAT type.
<
----------------------------------------------------------------------------*/
RtStatus_t  WriteFATentry(int32_t DeviceNum,int32_t FATsector,int32_t FATNtryoffset, int32_t clusterno, int32_t writentry)
{
    int32_t writeFATntry,FAT12word;
    RtStatus_t RetValue;
	int32_t FATentry;
	#ifdef ENABLE_WRITE_FAT2
	int Flag=0;	
	int32_t FATsize;
	#endif
    uint8_t *buffer;
    uint32_t cacheToken;
	
    EnterNonReentrantSection();
    ddi_ldl_push_media_task("WriteFATentry");

	#ifdef ENABLE_WRITE_FAT2
    /* check whether the second FAT is present or not */
	if (MediaTable[DeviceNum].NoOfFATs == 2)
	    Flag=1;
    FATsize =  MediaTable[DeviceNum].FATSize;
	#endif
	if (MediaTable[DeviceNum].FATType == FAT12)
	{
	    if((buffer = (uint8_t *)FSReadSector(DeviceNum, FATsector,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t *)0)
		{
            ddi_ldl_pop_media_task();
		    LeaveNonReentrantSection();
			return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
		}
	    if (FATNtryoffset == (MediaTable[DeviceNum].BytesPerSector-1))
	    {
	        FAT12word = FSGetByte((uint8_t *)buffer,FATNtryoffset);
            FSReleaseSector(cacheToken);
		    buffer = (uint8_t *)FSReadSector(DeviceNum,FATsector+1,WRITE_TYPE_RANDOM, &cacheToken);
	        FAT12word +=  (FSGetByte((uint8_t *)buffer,0) << 8);
	    }
	    else
        {
            FAT12word = FSGetWord((uint8_t *)buffer,FATNtryoffset);
        }
        FSReleaseSector(cacheToken);

	    if (clusterno & 0x0001)
	    {
    	        writeFATntry = writentry << 4 ;
	        FATentry =   FAT12word & 0x000F;
	    }
	    else
	    { 
    	        writeFATntry = writentry & 0x0FFF ;
            FATentry =   FAT12word & 0xF000;
	    }
	    writeFATntry  = (writeFATntry | FATentry);

	    /* check for boundary condition */
	    /* if the offset is at the boundary of a sector then write low byte to the last byte
	    of this sector and high byte to the first byte of next sector */
	  
	    if (FATNtryoffset == (MediaTable[DeviceNum].BytesPerSector-1))
	    {
		    FATentry = writeFATntry & 0x00FF;	// low byte 
		    if((RetValue = FSWriteSector(DeviceNum,FATsector,FATNtryoffset,(uint8_t *)&FATentry,0,1,WRITE_TYPE_RANDOM)) <0)
		    {
                ddi_ldl_pop_media_task();
		        LeaveNonReentrantSection();
			    return RetValue;
		    }
			#ifdef ENABLE_WRITE_FAT2
	        if(Flag==1)
		        if((RetValue = FSWriteSector(DeviceNum,(FATsector+FATsize),FATNtryoffset,(uint8_t *)&FATentry,0,1,WRITE_TYPE_RANDOM)) <0)
			    {
                    ddi_ldl_pop_media_task();
     		        LeaveNonReentrantSection();
				    return RetValue;
			    }
	        #endif
	        FATentry = 	writeFATntry >> 8;	   //  high byte
		    if((RetValue = FSWriteSector(DeviceNum,(FATsector+1),0,(uint8_t *)&FATentry,0,1,WRITE_TYPE_RANDOM)) <0)
		    {
                ddi_ldl_pop_media_task();
    		        LeaveNonReentrantSection();
	    		    return RetValue;
		    }
			#ifdef ENABLE_WRITE_FAT2
		    /* if second FAT is present duplicate the FAT Table */
		    if(Flag==1)
			    if((FSWriteSector(DeviceNum,(FATsector+1+FATsize),0,(uint8_t *)&FATentry,0,1,WRITE_TYPE_RANDOM)) <0)
			    {
                    ddi_ldl_pop_media_task();
		            LeaveNonReentrantSection();
				    return RetValue;
			    }
		    #endif
	    }
		else
		{
		    if((RetValue = FSWriteSector(DeviceNum,FATsector,FATNtryoffset,(uint8_t *)&writeFATntry,0,2,WRITE_TYPE_RANDOM)) <0)
		    {
                ddi_ldl_pop_media_task();
		        LeaveNonReentrantSection();
			    return RetValue;
		    }
			#ifdef ENABLE_WRITE_FAT2
		    /* if second FAT is present duplicate the FAT Table */
		    if(Flag==1)
		        if((RetValue = FSWriteSector(DeviceNum,(FATsector+FATsize),FATNtryoffset,(uint8_t *)&writeFATntry,0,2,WRITE_TYPE_RANDOM)) <0)
			    {
                    ddi_ldl_pop_media_task();
      		        LeaveNonReentrantSection();
				    return RetValue;
			    }
			#endif
		}
	}
	     
    else if (MediaTable[DeviceNum].FATType == FAT16)
	{
	    if((RetValue = FSWriteSector(DeviceNum,FATsector,FATNtryoffset,(uint8_t *)&writentry,0,2,WRITE_TYPE_RANDOM)) <0)
		{
            ddi_ldl_pop_media_task();
		    LeaveNonReentrantSection();
			return RetValue;
		}
		#ifdef ENABLE_WRITE_FAT2
	    /* if second FAT is present duplicate the FAT Table */
	    if(Flag == 1)
	        if((RetValue = FSWriteSector(DeviceNum,(FATsector+FATsize),FATNtryoffset,(uint8_t *)&writentry,0,2,WRITE_TYPE_RANDOM)) <0)
			{
                ddi_ldl_pop_media_task();
		        LeaveNonReentrantSection();
				return RetValue;
			}
		#endif
	}

    else if(MediaTable[DeviceNum].FATType == FAT32)
	{
	    if((RetValue = FSWriteSector(DeviceNum,FATsector,FATNtryoffset,(uint8_t *)&writentry,0,4,WRITE_TYPE_RANDOM)) <0)
	    {
            ddi_ldl_pop_media_task();
		    LeaveNonReentrantSection();
			return RetValue;
		}
		#ifdef ENABLE_WRITE_FAT2
	    /* if second FAT is present duplicate the FAT Table */
 	  	if(Flag==1)
	        if((RetValue = FSWriteSector(DeviceNum,(FATsector+FATsize),FATNtryoffset,(uint8_t *)&writentry,0,4,WRITE_TYPE_RANDOM)) <0)
			{
                ddi_ldl_pop_media_task();
		        LeaveNonReentrantSection();
	    	 	return RetValue;	
			}
		#endif
 	}
    ddi_ldl_pop_media_task();
    LeaveNonReentrantSection();
	return SUCCESS; 
}  

   


