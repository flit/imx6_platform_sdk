This folder contains various tools needed for SDK on the Windows host.

Source code formatting tools - src-format
-----------------------------------------
    1. Add this directory in your windows PATH env variable and re-start the
       git bash.
    2. To make sure a source file (not assembly) conforms to the coding
       convention, simple run:
           src-format [file-name]
       and then check it into git.

Program sdk image to a SD card on Windows using USB card reader
----------------------------------------------------------------
    1. For the i.MX28 EVK board, use:
           cfimager.exe -f ./output/mx28/bin/mx28-sdk.sb -d xyz
       where xyz refer to the drive letter assigned by Windows.
    2. For other i.MX boards such as MX53 EVK, use:
           cfimager-imx.exe -o 0 -f ./output/mx53/bin/diag-sdk-mx53evk.bin -d xyz
       where xyz refer to the drive letter assigned by Windows.
