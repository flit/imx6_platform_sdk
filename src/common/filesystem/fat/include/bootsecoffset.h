
/* Fields of BootSector and their offset in Byte*/

#define BYTESPERSECTOROFFSET  11

#define SECPERCLUSTEROFFSET   13

#define RSVDSECOFFSET         14

#define NOFATSOFFSET          16

#define ROOTDIRENTRYOFFSET    17

#define TOTSECTOROFFSET       19

#define MEDIAOFFSET           21

#define FATSIZEOFFSET         22

#define SECPERTRACKOFFSET     24  

#define NUMHEADSOFFSET        26

#define HIDSECOFFSET          28

#define TOTBIGSECOFFSET       32

#define DRIVEROOFFSET         36

#define RSVDOFFSET            37

#define BOOTSIGOFFSET         38

#define VOLIDOFFSET           39

#define VOLLABOFFSET          43

#define FILSYSTYPEOFFSET      54

/* FOR FAT32 FILESYSTEM ONLY , NOT DEFINED FOR FAT12 OF FAT16 TYPE OF FILESYSTEM */

	#define FAT32SIZEOFFSET      36

	#define FAT32FLAGOFFSET      40

	#define FAT32FSVERSIONOFFSET 42

	#define FAT32ROOTCLUSOFFSET  44

	#define FAT32FSINFOOFFSET    48

	#define FAT32BKBOOTSECOFFSET 50

    #define FAT32DRIVEROOFFSET   64

    #define FAT32RSVDOFFSET      65

    #define FAT32BOOTSIGOFFSET   66

    #define FAT32VOLIDOFFSET     67

    #define FAT32VOLLABOFFSET    71

    #define FAT32FSTYPEOFFSET    82

  /* FAT32 FSINFO Offset */

	#define FAT32FSIFREECOUNTOFFSET		488
	#define FAT32FSINXTFREEOFFSET		492
