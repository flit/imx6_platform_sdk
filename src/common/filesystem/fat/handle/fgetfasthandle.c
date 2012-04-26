/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/handle/FgetFastHandle.c $
 $Revision: 3 $                                       
 $Date: 9/13/03 4:52p $
 Description: FgetFastHandle.c
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

/*----------------------------------------------------------------------------
>  Function Name: int64_t FgetFastHandle(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)Handle Number

   Outputs:       A packed int64_t containing key defined as a bit pattern
                  1) Lower 4 bits(0-3) for device
                  2) 32 Bits (4-35) for directory sector
                  3) 12 bits (36-47) for directory offset
                     bits 48-63 are not used.

   Description:   Provides the fast access to the handle 
<
----------------------------------------------------------------------------*/
int64_t FgetFastHandle(int32_t HandleNumber)
{
    int64_t FastHandle;

	// Check for boundary condition. 
	if((HandleNumber < 0)||(HandleNumber >= maxhandles))
	{
        FastHandle = 0;
	}
	else
	{
		FastHandle = (((int64_t)Handle[HandleNumber].Device << 44) | ((int64_t)Handle[HandleNumber].DirOffset << 32) | Handle[HandleNumber].DirSector);
	}
	
    return FastHandle;
}

/*----------------------------------------------------------------------------
>  Function Name: int64_t GetRootdirkey(int32_t DeviceNumber)

   FunctionType:  Reentrant

   Inputs:        1) Device Number

   Outputs:       An int64_t containing key defined as a bit pattern
                  4 bits for device Number      
                  others are zeros

   Description:   Provides Rootdirkey
<
----------------------------------------------------------------------------*/
int64_t GetRootdirkey(int32_t DeviceNumber)
{

    int64_t Rootdirkey;
 
    Rootdirkey = (((int64_t)DeviceNumber << 44) | ((int64_t)0) | 0);
     
    return (Rootdirkey);
}     


/*----------------------------------------------------------------------------
>  Function Name: int32_t FgetDevice(int64_t Key)

   FunctionType:  Reentrant

   Inputs:        1)Key

   Outputs:       It extracts the device from 64 bit Key and reurns the Device Number
   
   Description:   
----------------------------------------------------------------------------*/
int32_t FgetDevice(int64_t Key)
{
    int32_t Device;
    
   	Device = (int32_t)(((Key >> 44) & 0x000000000000000F));
  
    return Device;
}

