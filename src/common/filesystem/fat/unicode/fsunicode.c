/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/FSUnicode.c $                                        
 $Revision: 10 $                                       
 $Date: 9/13/03 7:07p $                                           
 Description: FSUnicode.c
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
/*----------------------------------------------------------------------------
		Global Declarations
----------------------------------------------------------------------------*/
const uint8_t Long_NameRes_Ch[10]={0x22,0x2A,0x2F,0x3A,0x3C,0x3E,0x3F,0x5C,0x7C}; 
const uint8_t Short_NameRes_Ch[6]={0x2B,0x2C,0x3B,0x3D,0x5B,0x5D};  
/*----------------------------------------------------------------------------
>  Function Name:  void DBCStoUnicode(uint8_t *filepath,uint8_t *buf,int32_t index,int32_t length)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
				   2) Pointer to buffer
				   3) Index   (starting point for string)
                   4) Length  (Ending point for string)

  Outputs:         Nil
     
  Description:     Converts the given DBCS string to kUTF16Encoding.
<
----------------------------------------------------------------------------*/
void DBCStoUnicode(uint8_t *filepath,uint8_t *buf,int32_t index,int32_t length)
{
    int32_t offset=0,word=0,i;
    int Byte;

    for(i=index;i<length;i++)
    {
        Byte = FSGetByte(filepath,i);
        if(Byte=='/')
        Byte=0;
        PutByte((uint8_t*)&word,Byte,0);
        PutWord(buf,word,offset); 
        offset+=2; 
    } 
    PutWord(buf,0,offset); 
}
/*----------------------------------------------------------------------------
>  Function Name:  void UnicodeToOEM(uint8_t *file,uint8_t *shortname,int32_t length,int32_t index)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to file name
                   2) Pointer to Character
                   3) Length  (Ending point for string)
                   4) Index   (strating point for string)
   
   Outputs:        None

   Description:    Converts the given UTF16 string to OEM.
<
-----------------------------------------------------------------------------*/
void UnicodeToOEM(uint8_t *file,uint8_t *shortname,int32_t length,int32_t index)
{
    int offset=0,j,k=0;
    int word=0;

    offset=index;
    while(offset<length)
    {
        word =FSGetWord(file,offset);
        for(j=0;j<SHORTNAMERES_CH;j++)
	    {
	        if(word == Short_NameRes_Ch[j])
	 	        word = 0x5F;
        }
        if((word & 0x00FF) == 0) //if the unicode was like 0x6700 or 0xXX00.
	    word = 0x5F;
	PutByte(shortname,word,k);
  	    offset+=2; 
	    k++;
    } 
    PutByte(shortname,0,k);
}
