include $(SDK_ROOT)/mk/common.mk

# FS steering API source files.
define steering_src
steering/fs_steering_read.c 
steering/fs_steering_utility.c 
steering/fs_steering.c
endef

# FAT32 source files.
define fat32_src
fat/base/arrangefilename.c
fat/base/changetorootdirectory.c
fat/base/clearcluster.c
fat/base/createdirectory.c
fat/base/deletecontent.c
fat/base/deleterecord.c
fat/base/fastopen.c
fat/base/fcreate.c
fat/base/fflush.c
fat/base/filegetattrib.c
fat/base/filegetattribhandle.c
fat/base/filegetdate.c
fat/base/filesetattrib.c
fat/base/filesetdate.c
fat/base/fread_bypass.c
fat/base/fread.c
fat/base/fseek.c
fat/base/fwrite.c
fat/base/getfilesize.c
fat/base/getshortfilename.c
fat/base/readrootdirrecord.c
fat/base/updatefilesize.c
fat/common/cache_wrappers.c
fat/common/fsclearbuf.c
fat/common/fsdriveinit.c
fat/common/fsdriveshutdown.c
fat/common/fsinit.c
fat/common/fsrecoverdrive.c
fat/common/fsshutdown.c
fat/common/setcwdhandle.c
fat/device/readdevicerecord.c
fat/fatapi/checkspaceinrootdir.c
fat/fatapi/computefreeclusters.c
fat/fatapi/fatsector.c
fat/fatapi/filesystempresent.c
fat/fatapi/findnextcluster.c
fat/fatapi/findnextfreecurrentcluster.c
fat/fatapi/firstfreeandallocate.c
fat/fatapi/firstrootdirsector.c
fat/fatapi/firstsectorofcluster.c
fat/fatapi/getnewcluster.c
fat/fatapi/readfat12entry.c
fat/fatapi/readfatentry.c
fat/fatapi/totalfreecluster.c
fat/fatapi/writefatentry.c
fat/handle/fgetfasthandle.c
fat/handle/handle.c
fat/handle/handleres.c
fat/higherapi/changepath.c
fat/higherapi/chdir.c
fat/higherapi/chdirw.c
fat/higherapi/checkforvalidrecord.c
fat/higherapi/deletetree.c
fat/higherapi/feof.c
fat/higherapi/ferror.c
fat/higherapi/findfirst.c
fat/higherapi/findnext.c
fat/higherapi/fopen.c
fat/higherapi/fopenw.c
fat/higherapi/fremove.c
fat/higherapi/fremovew.c
fat/higherapi/frename.c
fat/higherapi/ftell.c
fat/higherapi/getcwd.c
fat/higherapi/getvolumelabel.c
fat/higherapi/longfilename.c
fat/higherapi/mkdir.c
fat/higherapi/mkdirw.c
fat/higherapi/rmdir.c
fat/higherapi/rmdirw.c
fat/higherapi/searchdirectory.c
fat/higherapi/searchfile.c
fat/higherapi/sethandleforsearch.c
fat/platform/platform.c
fat/standardapi/fclose.c
fat/standardapi/fgetc.c
fat/standardapi/fgets.c
fat/standardapi/fputc.c
fat/standardapi/fputs.c
fat/standardapi/readdirectoryrecord.c
fat/unicode/fsunicode.c
fat/utility/arrangelongfilename.c
fat/utility/checkmode.c
fat/utility/convert_itoa.c
fat/utility/createdirectoryrecord.c
fat/utility/createshortdirrecord.c
fat/utility/dbcstotwobytestring.c
fat/utility/discardtrailigperiods.c
fat/utility/extractfilename.c
fat/utility/extractpath.c
fat/utility/findfreerecord.c
fat/utility/findnextsector.c
fat/utility/fstrcpy.c
fat/utility/getchar.c
fat/utility/getname.c
fat/utility/isdirectoryempty.c
fat/utility/isshortnamevalid.c
fat/utility/longdirmatch.c
fat/utility/matchdirrecord.c
fat/utility/putchar.c
fat/utility/reentrant_section.c
fat/utility/searchfreerecord.c
fat/utility/setcwd.c
fat/utility/setshortfilename.c
fat/utility/shortdirmatch.c
fat/utility/strlength.c
fat/fs_fat_memory.c
endef

INCLUDES += \
	-I$(SDK_ROOT)/sdk/common/filesystem/ \
    -I$(SDK_ROOT)/sdk/common/filesystem/include \
    -I$(SDK_ROOT)/sdk/common/filesystem/fat/include


SOURCES = $(steering_src) $(fat32_src)


include $(SDK_ROOT)/mk/targets.mk
