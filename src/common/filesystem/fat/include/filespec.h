
#ifndef _FILESPEC_H_
#define _FILESPEC_H_
#include  "fstypes.h"
#define MAX_FILESNAME   13

typedef struct {
    uint32_t   gCurrentRecord;  //modify: original data type uint8_t if record is more
                                //then 255 at that time creates problem so modify it to uint32_t
    uint8_t    DirAttribute;
    uint8_t    FileName[9];
    uint8_t    FileExtension[4];
}FileSpecs_t;

typedef struct {
    int32_t   attrib;
	uint32_t  FileSize;
    int32_t   device;
    int32_t   startrecord;
    char      name[MAX_FILESNAME];
	int64_t   Key;
}Finddata;
#endif
