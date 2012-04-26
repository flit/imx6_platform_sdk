/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Convert_itoa.c $
 $Revision: 1 $                                       
 $Date: 9/18/03 11:52a $
 Description: Convert_itoa.c
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
>  Function Name: int32_t Convert_itoa(int32_t Number,uint8_t *string)

   FunctionType:  Reentrant

   Inputs:        1) Number
                  2) Pointer to string

   Outputs:       Length

   Description:   Arranges the file name as short file name in 8+3 format
<
----------------------------------------------------------------------------*/
int32_t Convert_itoa(int32_t Number,uint8_t *string)
{
    uint8_t Temp[12];
    int i=0,j=0,Flag;
    int Length=0;
   
    while(Number!=0)
    { 
   	    Flag = Number/10;
	    Temp[Length] = Number -(Flag*10);
	    Number = Flag;
	    Length++;
    }
    j=Length-1; 
    for(i=0;i<Length;i++)
    {
        string[i] = Temp[j]+0x30;;
        j--;
    }
    return Length;
}      
   


