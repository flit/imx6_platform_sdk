/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/ArrangeLongFileName.c $                                        
 $Revision: 5 $                                       
 $Date: 9/18/03 6:50p $                                           
 Description: ArrangeLongFileName.c
 Notes:	
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
>  Function Name:  RtStatus_t ArrangeLongFileName(int32_t HandleNumber,uint8_t *filename,int32_t count, int32_t chksum)

   FunctionType:   Reentrant

   Inputs:         1) Handle number
				   2) Pointer to file name
				   3) Count 
				   4) Chksum

   Outputs:        Returns SUCCESS or an error code if function fails
      
   Description:    Arranges the given long file name. 
----------------------------------------------------------------------------*/
RtStatus_t ArrangeLongFileName(int32_t HandleNumber,uint8_t *filename,int32_t count, int32_t chksum)
{
    int32_t offset, Flag;
    RtStatus_t Retval;
    int32_t wordno=0, Ldirorder, word;
    uint8_t Longdirname[32]; 

	count--;
	Flag = count;
    
    PutByte(Longdirname,LONGDIRATTRIBUTE,LDIRATTRIOFFSET);	//long directory attribute
    PutByte(Longdirname,0,LDIRTYPEOFFSET);	  //directory type
    PutByte(Longdirname,chksum,LDIRCHKSUMOFFSET);  //chksum
    PutWord(Longdirname,0,DIR_FSTCLUSLOOFFSET);		//long directory first cluster
    
    while(Flag>=1) 
    {
        if(Flag == count)
		    Ldirorder = (Flag | 0x40);
		else
		    Ldirorder = Flag;
        PutByte(Longdirname,Ldirorder,LDIRORDOFFSET);

        offset = LDIRNAME1OFFSET;
		wordno = ((Flag-1)*LONGDIRCH_PER_RECORD)<<1;
		 
		while(offset !=  DIRRECORDSIZE)
	    {
            word = FSGetWord(filename,wordno);
            PutWord(Longdirname,word,offset);
                   
            wordno+=2;
			offset = offset + 2;
			/* if all words of longdir firstname field is occupied, check for 
			longdir secondname field */
	        if (offset ==   LDIRATTRIOFFSET)
		        offset  =  LDIRNAME2OFFSET ;
	      
			/* if all words of longdir secondname field is occupied  check for 
			longdir thirdname field */
	      	if(offset ==  LDIRFSTCLUSNOOFFSET)
		        offset = LDIRNAME3OFFSET ;
 
			if(word == '\0')
			{
                word = 0xFFFF;
			    while(offset !=  DIRRECORDSIZE)
			    {
			        if (offset ==   LDIRATTRIOFFSET)
		                offset  =  LDIRNAME2OFFSET ;
	      	        if(offset ==  LDIRFSTCLUSNOOFFSET)
		                offset = LDIRNAME3OFFSET ;
			        PutWord(Longdirname,word,offset);
			        offset+=2;  
 		        }
			}
           
 	        /* if all words of longdir thirdname field is occupied check for next sub component of longdir entry */
        } // while(offset !=  DIRRECORDSIZE)

        if(Handle[HandleNumber].StartingCluster!= 0)
        {
            if((Retval=(RtStatus_t)Fwrite(HandleNumber,Longdirname,DIRRECORDSIZE)) <=0)
			    return Retval;
        }
	    else
	    {
            if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentSector,Handle[HandleNumber].BytePosInSector,Longdirname,0,
            DIRRECORDSIZE,WRITE_TYPE_RANDOM))<0)
			    return Retval;

            offset =  (Handle[HandleNumber].CurrentOffset >>5) + 1;
            SetcurrentPos(HandleNumber,offset);
	    }
	  	Flag--;
    } // while(Flag>=1)
                   
    return (SUCCESS);
}
       	



