/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/FindfreeRecord.c $                                        
 $Revision: 9 $                                       
 $Date: 9/13/03 7:05p $                                           
 Description: FindfreeRecord.c
 Notes:	This file read provides utility function to find free record.
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
#include "DirOffset.h"

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t FindfreeRecord(int32_t Handlenumber,int32_t Flag)

   FunctionType:   Reentrant

   Inputs:         1) Handlenumber
                   2) Flag

   Outputs:        Returns SUCCESS or an Error Code if error occurs
                      
   Description:    Determines free space by reading the all the records and 
                   updates handle according to the free space.
<
----------------------------------------------------------------------------*/
RtStatus_t FindfreeRecord(int32_t Handlenumber,int32_t Flag)
{
    RtStatus_t RetValue;
    int Devicenum, i, Firstbyte;
    uint8_t Buffer[96];	   
    int32_t Recordno;
    int64_t NumBytesRead;
   
    Devicenum = 	Handle[Handlenumber].Device;
    Recordno = 0;

	do 
    { 
        if((NumBytesRead = ReadDirectoryRecord(Handlenumber,Recordno,Buffer))<0)
		    break;
        Firstbyte = FSGetByte(Buffer,0);
        if(Firstbyte ==  0x00)
		{
		    Fseek(Handlenumber,-DIRRECORDSIZE,SEEK_CUR);
        	return(SUCCESS);
	    }
		else if(Firstbyte == 0xE5)
		{
		    if(Flag ==1)
			{
                Fseek(Handlenumber,-DIRRECORDSIZE,SEEK_CUR);
        	    return(SUCCESS);
			}
			else
			{
			    i=1;
			    while(1)
			    {
				    Recordno++; 
			        NumBytesRead = ReadDirectoryRecord(Handlenumber,Recordno,Buffer);
	                Firstbyte = FSGetByte(Buffer,0);
				    if(Firstbyte ==  0x00)
			   	    {
                        Fseek(Handlenumber,-DIRRECORDSIZE,SEEK_CUR);
			            return(SUCCESS);
				    }
			        else if(Firstbyte != 0xE5)
				        break;
				    else
				    {
				        i++;
				        if (i==Flag)
					    {
				            Fseek(Handlenumber,-(Flag*DIRRECORDSIZE),SEEK_CUR);
			                return SUCCESS;
				        }
				    }
		        } // while(1)
            }
        }
		Recordno++; 
    }while(NumBytesRead != 0);
		  
	// EOF is reached, so in order to allocate a new cluster we need to write.
    // Dummy Write the empty record. This will force allocation of new cluster.
    if((RetValue = GetNewcluster(Handlenumber)) < 0)
        return RetValue;
    if((RetValue = ClearCluster(Handlenumber)) <0)
	    return RetValue;

    (void)Devicenum;
    //Stmp00006804
    //If CurrentOffset isn't reset under this condition (directory table needs a new cluster to enter this particular record)
    //Handle[].DirSector will contain the wrong value after updating handle, which results in an erroneous fast_key, which can generate
    //the wrong short filename if used right after this Fopen() .
    Handle[Handlenumber].CurrentOffset = 0;

    return (SUCCESS);
}



