/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Setshortfilename.c $
 $Revision: 3 $                                       
 $Date: 9/18/03 11:52a $
 Description: Setshortfilename.c
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
		Global Declarations
----------------------------------------------------------------------------*/
void GeneratefilenameTail(uint8_t *shortfilename,int32_t i,int32_t flag);
/*----------------------------------------------------------------------------
>  Function Name: void Setshortfilename(int32_t HandleNumber,uint8_t *Buffer,uint8_t *shortfilename)

   FunctionType:  Reentrant

   Inputs:        1) Handle number
                  2) Pointer to file name or directory Buffer
                  3) Pointer to ShortName directory Buffer

   Outputs:       Nil

   Description:   Arranges the file name as short file name in 8+3 format
<
----------------------------------------------------------------------------*/
void Setshortfilename(int32_t HandleNumber,uint8_t *Buffer,uint8_t *shortfilename)
{
    uint8_t UpperCaseBuffer[256];
    int32_t byte=0;
    int32_t i=0;
    int32_t j=0;
    int32_t k=0;
    int32_t count=0;
    int32_t Flag;
	int32_t Strlen;
    int32_t RecordNum=0;
    RtStatus_t longFilenameFits8_3;
   
    // Get the string length in 2-byte characters, convert it to a byte count.
    Strlen = StrlengthW((uint8_t*)Buffer); 
    Strlen = Strlen << 1;

    // Convert to OEM (1-byte character string) and convert to all uppercase.
    UnicodeToOEM((uint8_t*)Buffer,(uint8_t*)UpperCaseBuffer,Strlen,0);
    Uppercase((uint8_t*)UpperCaseBuffer);

    // Check to see if OEM+UPPERCASE converted string already conforms to 8.3 short filename standard.
    // Note that IsShortNameValid() expects one-byte character strings as input.
    longFilenameFits8_3 = IsShortNameValid(UpperCaseBuffer, (Strlen >> 1), 0);
    if(longFilenameFits8_3 == SUCCESS)
    {
        // The name conforms, so copy it into the shortfilename buffer and exit.
        i = 0;
	    while((byte = FSGetByte(UpperCaseBuffer,i)) != '\0')
	    {
	        PutByte(shortfilename,byte,i);
	        i++;
	    }
        PutByte(shortfilename, '\0', i);
        return;
    }


    /* strip all leading and embedded spaces from the long name */
	/* strip all leading periods from the long file name */
    while((byte = FSGetByte(UpperCaseBuffer,j)) !='\0')
	{
	    if(byte == '.')
	        count++;

	    j++;
	}
    
	j=0;
    /* strip all leading and embedded spaces from the long name */
	/* strip all leading periods from the long file name */
	while((byte = FSGetByte(UpperCaseBuffer,i)) !='\0')
	{
	    if(byte =='.')
		{
            if(count >1)
		        count--;
		    else
            {
                if(j!=0)
                {
                    PutByte(UpperCaseBuffer,byte,j);
	                j++;
			    }
			    else
			        count--;
		    }
        }
		if(byte !=0x20 && byte != 0x2E)
	    {
            if (byte<0x20)
            {
              byte = '_';
            }
			else
            {
              for(k=0;k<SHORTNAMERES_CH;k++)
              {
                if (byte == Short_NameRes_Ch[k])	 
                {
                  byte = '_';
                  break;
                } 		
              }
              
              if ('_'!=byte)
              {
              
                for(k=0;k<LONGNAMERES_CH;k++)
                {
                
                  if (byte == Long_NameRes_Ch[k])
                  {
                    byte = '_';
                    break;
                  } 
                  
                } /* for */             
                
              } /* if */
              
            } /* else */
            
	        PutByte(UpperCaseBuffer,byte,j);
			j++;
		}
		i++;
    }   
	PutByte(UpperCaseBuffer,0,j);
    /* convert the filename to fit in 8+3 format */
    i=0;
	while((byte = FSGetByte(UpperCaseBuffer,i)) !='.' && i < 8 && byte !='\0')
	{
        PutByte(shortfilename,byte,i);
		i++;
    }
    
    
    PutByte(shortfilename,0,i);
    if(count!=0)
	{
	    while((byte = FSGetByte(UpperCaseBuffer,i)) !='.')
		{
    	    i++;
		}
		if(i>8)
		    Flag=8;
		else 
		    Flag=i;
     	
		j=i+2;
        if(j>8)
     	    j=8;
		count=0;
	    while( (byte = FSGetByte(UpperCaseBuffer,i)) !='\0' && count < 4)
	    {
	        PutByte(shortfilename,byte,j);
	        i++;
	        j++;
    		count++;
	    }
        PutByte(shortfilename,0,j);
	}
	else
        Flag = Strlength(shortfilename); 
	   
    /* check if the file name exists then add file name tail */
    i=1; 
	if(Flag>6)
        Flag = 6;
    PutByte(shortfilename,'~',Flag);
    PutByte(shortfilename,'1',(Flag+1));

   	Strlen= Strlength(shortfilename);
    while(Searchdirectory(HandleNumber,shortfilename,kDBCSEncoding,0,(Strlen+1),0,Buffer,1,&RecordNum) >= 0)
    {
        i++;
        GeneratefilenameTail(shortfilename,i,Flag);
	}
}

/*----------------------------------------------------------------------------
>  Function Name: void GeneratefilenameTail(uint8_t *shortfilename,int32_t i,int32_t Flag)

   FunctionType:  Reentrant

   Inputs:        1) pointer to shortfilename
                  2) i
                  3) Flag

   Outputs:       Nil

   Description:   Puts the given no. i in the given filename at the position 
                  indicated by the Flag.
<
----------------------------------------------------------------------------*/
void GeneratefilenameTail(uint8_t *shortfilename,int32_t i,int32_t Flag)
{
    int32_t length,count,j;
    uint8_t string[30];
  
    length = Convert_itoa(i,(uint8_t*)string);
    count = Flag - length +1;

    PutByte(shortfilename,'~',count);
	for(j=0;j<length;j++)
	{
        count++;
       	PutByte(shortfilename,string[j],count);
    }

}

