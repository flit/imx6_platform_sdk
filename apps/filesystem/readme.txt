filesystem application
======================

Simple performance test for the FAT32 filesystem on an SD card.


Description
-----------

This applications writes and reads files from a FAT formatted SD card in slot SD3
and displays performance statistics. Files are accessed using various chunk sizes from
512B to 1MB. Both buffered (filesystem) and raw read/write is tested.


Requirements
------------

Requires a FAT formatted SD card in SD3. For the file read test, a
file named TESTIN.DAT must exist. The easiest way to create this file is to run
the test one time and then copy TESTOUT0.DAT (which is created by the test) to
TESTIN.DAT. Then run the test again.


Build options
-------------

None.


Code organization
-----------------

This application contains one source file: fs_test.c. To enable extra debug messages,
define FS_DEBUG in this file.
