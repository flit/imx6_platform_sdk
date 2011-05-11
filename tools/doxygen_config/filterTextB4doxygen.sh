#!/bin/bash

# replace /** with /* so 
# doxygen does not see DocBook comments intended
# for /linux/scripts/kernel-doc
sed 's/\/\*\*/\/\*/' $1
