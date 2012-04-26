/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/IsShortNameValid.c $
 $Revision: 3 $                                       
 $Date: 9/16/03 12:24p $
 Description: IsShortNameValid.c
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
#include  "DIrOffset.h"

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t IsShortNameValid(uint8_t *Buffer,int32_t length,int32_t index)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to Buffer
                  2) Length
                  3) Index  
                  
   Outputs:       Returns SUCCESS, 1 (OK but reserved) or an error code if error occurs

   Description:   This function checks whehter the file name will fit in 8+3 format
                  and it does not contain any restricted characters. 
<
----------------------------------------------------------------------------*/
RtStatus_t IsShortNameValid(uint8_t *Buffer,int32_t length,int32_t index)
{
    RtStatus_t Flag=(RtStatus_t)1;      //Set value to OK - reserved.
    int count=0,i,j,Char;
    int32_t strlen, offset=index;
     
    strlen = length - index;
    if(strlen > 12)
        return (RtStatus_t)Flag;
       
    else
    {
        for(i=0;i<strlen;i++)
        {
            Char = GetChar(Buffer,&offset);
            if (Char == 0x2e)
            {
                count++; 
            }
            if(count>1)
                return Flag;
                  
            for(j=0;j<SHORTNAMERES_CH;j++)
            {
                if(Char < 0x20)
                    return ERROR_OS_FILESYSTEM_ILLEGAL_FILENAME_CHARA;
                if(Char == Short_NameRes_Ch[j])
                    return Flag;
                if(Char == 0x20)
                    return Flag;
            }
            for(j=0;j<LONGNAMERES_CH;j++)
            {
                if(Char == Long_NameRes_Ch[j])
                    return ERROR_OS_FILESYSTEM_ILLEGAL_FILENAME_CHARA;
            }
        }
        if(count == 0 && strlen > 8)
            return Flag;
        
        if(count==1)
        {
            if((Char = FSGetByte(Buffer,index)) == '.')
                return Flag;
           
            i=0;
            offset=index;
            while((Char = GetChar(Buffer,&offset))!='.')
            {
                i++;
            }
            if(i>8)
                return Flag;
            count=0;
            while(offset< length)
            {
                Char = GetChar(Buffer,&offset);
                count++;
            }
            if(count>3)
                return Flag;
        }

    } // else	  
   
    return SUCCESS;     
}



    
       
   
