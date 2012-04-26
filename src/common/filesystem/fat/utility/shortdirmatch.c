/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/ShortdirMatch.c $                                        
 $Revision: 10 $                                       
 $Date: 9/13/03 7:07p $                                           
 Description: Shortdirmatch.c
 Notes:	This file read provides utility function to match short directory record.
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
		Global Declarations
----------------------------------------------------------------------------*/
RtStatus_t ConverToShortname(uint8_t *file,uint8_t *filenamebuf,int32_t index,int32_t length);
/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Shortdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,
                       uint8_t *Shortname,uint8_t *buf,int32_t Flag,int32_t index,int32_t length,uint8_t *UniCodeBuffer)

   FunctionType:   Reentrant

   Inputs:         1) Handle Number
                   2) Record Number
				   3) Pointer to file name
				   4) Pointer to Short name
				   5) Pointer to buffer
                   6) Flag
                   7) Index
                   8) Length
                   9) Pointer to Unicodebuffer

   Outputs:        Returns ERROR_OS_FILESYSTEM_FILE_FOUND if directory or file name matches else ERROR_OS_FILESYSTEM_FILE_NOT_FOUND.

   Description:    This function matches the directory or file name with the directory record 
                   in the buffer byte-by-byte. If the short name matches, then returns ERROR_OS_FILESYSTEM_FILE_FOUND. 
                   If short name is alias of a long directory name then checks for long directory 
                   name in the previous directory entry. If short directory name does not match then 
                   returns ERROR_OS_FILESYSTEM_FILE_NOT_FOUND. 
<
----------------------------------------------------------------------------*/
RtStatus_t Shortdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,uint8_t *Shortname,uint8_t *buf,int32_t Flag,int32_t index,int32_t length,uint8_t *UniCodeBuffer)
{
    int byte;
    RtStatus_t filefound;
    int32_t offset=0, Byteno=0, filenamebyte, strlen;
    uint8_t filenamebuf[15];
   
    length = length -1;

    if(buf[0]==0xE5)
    {
        // a deleted record, don't bother to compare and return not found
  	    return (ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
    }
    
    offset=index;
    Setfilename((uint8_t*)buf,(uint8_t*)filenamebuf);
    while  ((byte =FSGetByte(Shortname,Byteno)) != '\0' )
    {                      
	    filenamebyte = FSGetByte(filenamebuf,Byteno);                    
        if(filenamebyte == '~')
		{
		    if(Flag==1)
			{
	            DBCStoUnicode(file,(uint8_t*)UniCodeBuffer,index,length);
	          	strlen = StrlengthW((uint8_t*)UniCodeBuffer);
			    strlen = strlen << 1;
				filefound = Longdirmatch(HandleNumber,RecordNo,(uint8_t*)UniCodeBuffer,0,strlen,UCS2s);
	            return(filefound);
	        }
        }
              
        if (byte != filenamebyte) 
     	    return (ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
 
        Byteno++;
    }

    if((filenamebyte = FSGetByte(filenamebuf,Byteno)) !='\0') 
        return  ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;                   

    (void)offset;
    return (ERROR_OS_FILESYSTEM_FILE_FOUND);
}

/*----------------------------------------------------------------------------
>  Function Name:  void Setfilename(uint8_t *buf,uint8_t *buffer_1)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to buffer
                   2) Pointer to buffer_1

   Outputs:        Nil

   Description:    Sets file name
<
----------------------------------------------------------------------------*/
void Setfilename(uint8_t *buf,uint8_t *buffer_1)
{
    int byte, j;
    int32_t offset=0,offset_dest=0;

    byte = FSGetByte(buf,0);                    
	if(byte == 0x05)
	    PutByte(buf,0xe5,0);

	while(offset<8)
	{
	    byte = GetChar(buf,&offset);
		if(byte == 0x20)
		    break;
		PutChar(buffer_1,&offset_dest,byte);
    }

    PutChar(buffer_1,&offset_dest,'.');
    j=0;
    offset=8;
    while(offset<11)
    {
	    byte = GetChar(buf,&offset);
		if(byte == 0x20)
		{
		    if((offset_dest <= 9) && (j==0))
    		    offset_dest--; 
	        PutByte(buffer_1,'\0',offset_dest);
		    break;
		}
		PutChar(buffer_1,&offset_dest,byte);
		j++;
    }
    PutByte(buffer_1,'\0',offset_dest);
}

/*----------------------------------------------------------------------------
>  Function Name:  void Uppercase(uint8_t *file)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
			   
   Outputs:        Nil
   
   Description:    Converts given file name in Uppercase
<
----------------------------------------------------------------------------*/
void Uppercase(uint8_t *file)
{
    int32_t offset=0,offset_dest=0, CharPrevious=1;
    int Char;
   	while((Char = GetChar(file,&offset))!='\0')
	{
        if ((Char >=97) && (Char <= 122)&&(CharPrevious)<0x80)   
            Char =Char - 32;
        PutChar(file,&offset_dest,Char);
        CharPrevious = Char;						
	}
	PutByte(file,0,offset_dest);
}

/*----------------------------------------------------------------------------
>  Function Name:  in32_t ConverToShortname(uint8_t *file,uint8_t *filenamebuf,int32_t index,int32_t length)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
                   2) Pointer to file name buffer 
			       3) Index
                   4) Length

   Outputs:        Returns Flag_1
   
   Description:    Converts given file name to Short name.
<
----------------------------------------------------------------------------*/
int32_t ConverToShortname(uint8_t *file,uint8_t *filenamebuf,int32_t index,int32_t length)
{
    int32_t offset=0,offset_dest=0,count=0,strlen;
    int Chara,CharaPrevious=1,Flag=0,j,Flag_1=1;		
    uint8_t temp[15];

   	offset=index;
    length = length -1;
     
   	while((offset<length) && count<=12)
	{
        Chara = GetChar(file,&offset);
    	for(j=0;j<SHORTNAMERES_CH;j++)
		{
		   if(  (Chara == Short_NameRes_Ch[j]) && (CharaPrevious < 0x80) )
		        Flag=1;
		}
		CharaPrevious = Chara;                         
		if(Flag == 1)
		{
		    Chara = 0x5F;
		    Flag=0;
		}
		PutChar((uint8_t*)temp,&offset_dest,Chara);
		count++;
    }
	PutChar((uint8_t*)temp,&offset_dest,0);

	/* strip all leading and embedded spaces from the long name */
	/* strip all leading periods from the long file name */
	offset=0;
    count=0;

   	while((Chara = GetChar((uint8_t*)temp,&offset))!='\0' && offset <= 12)
  	{
        if(Chara == '.')
            count++;
	    if(Chara == 0x20)
	        Flag=1;
    }
	offset=0;
	offset_dest=0;
	strlen = length-index-1;

	if(count == 0)
	{
        if((strlen<8) && (Flag == 0))
            Flag_1=0;
    }
	if(count>1)
	    Flag=1;
    /* strip all leading and embedded spaces from the long name */
	/* strip all leading periods from the long file name */
	while((Chara = GetChar((uint8_t*)temp,&offset)) !='\0' && offset<=12)
	{
        if(Chara =='.')
	    {
            if(count >1)
		        count--;
		    else
            {
                if(offset_dest!=0)
				{
	                PutChar(filenamebuf,&offset_dest,Chara);
                    if((offset<=9) && (Flag == 0))
                        Flag_1=0;
			    }
			    else
				{
				    count--;
					Flag=1;
				}
			}
		}
	   	if(Chara !=0x20 && Chara != 0x2E && Chara != 0x2f) 
	    {
	        PutChar(filenamebuf,&offset_dest,Chara);
		}
    }
	if(strlen<6 && Flag==1)
	{
	    PutChar(filenamebuf,&offset_dest,'~');
	    PutChar(filenamebuf,&offset_dest,0);
    }
	else
	    PutChar(filenamebuf,&offset_dest,0);
    return Flag_1;
}
