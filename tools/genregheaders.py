#!/usr/bin/env python

# Copyright (c) 2012 Freescale Semiconductor, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# o Redistributions of source code must retain the above copyright notice, this list
#   of conditions and the following disclaimer.
#
# o Redistributions in binary form must reproduce the above copyright notice, this
#   list of conditions and the following disclaimer in the documentation and/or
#   other materials provided with the distribution.
#
# o Neither the name of Freescale Semiconductor, Inc. nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

import sys, os, string, argparse, re, textwrap, datetime, codecs, types
from xml.etree import ElementTree
from UserDict import UserDict

##
# @main
#
# The purpose of this tool is to automatically generate register definition header files from the
# sidsc-component XML that is used to create the register sections of Freescale reference manuals.
#
# @par Remaining tasks:
#
# - Do HTML entities need to be converted?
# - Need to process and filter all elements to build text. Even <bitFieldName> sometimes has more
#   than one <ph> node within, each with different filter attribtues.
# - Handle uniqueing of register and bitfield names in those classes, not in HeaderGenerator.
# - Don't generate BW_ macros for bitfields that belong to a register without SCT macros, such
#   as write-only registers.
# - Add --enable=x (?) and --disable=x command line options that take a list of sections to include
#   or exclude in the output. For instance, to disable the module struct or read/write macros.
# - Use the relative paths in the sidsc-design file to find the input XML files, so most headers
#   for an entire design can be generated in one command. (?)
# - Use the log package for error output and honour the --quiet command.
# - Write a real template language with looping and conditionals. (?)
# - Add check for dimension addressIncrement less than register size in bytes.
# - Consider adding defs in header to access multi-instance registers with an index parameter to
#   the macro, just like registers of a multi-instance component are accessed.
#
# @par Version history:
#
# 1.0b7:
# - Handle all namePattern types instead of assuming the end. This fixes a number of register names.
# - Add check for unitQualifier elements not equal to dimensionValue.
# - Coalesce adjacent reserved bitfields.
#
# 1.0b6:
# - Added BG_ macros.
# - Single-bit bitfield bit ranges in the comment above the bitfield macros will now appear like
#   [12] instead of [12:12].
# - Corrected BW_ macros for multi-instance components.
# - Using more efficient BW_ macros for registers without true SCT variants.
# - Fixed name of real _SET macro. Was hardcoded to HW_GPMI_CTRL0_SET().
# - Added names for unions and structs.
# - '\' characters are stripped from comment text so they can't end up at the end of a line in
#   the output header file.
# - Identifying names that match some of the more common standard C library definitions, like
#   "NULL", and appending an underscore to prevent compiler errors.
# - Add an option to set the chip name and output it in the headers.
# - Prefixing the comment on bitfields in a register string with the bitfield bit range.
# - The module struct is wrapped with #pragma pack(1).
# - Putting the reset value in the register comments.
#
# 1.0b5:
# - Putting BP_ and BM_ macros in parentheses.
# - Start multi-instance numbering at 1 instead of 0, to match the RM.
# - Support true SCT variants of registers.
# - Fixed conversion of binary values.
# - Handles 'x' chars in binary bitfield values, treating them as a zero.
# - New --design-name, --base-address, and --instance-offsets arguments.
# - Removed --product, --feature, and --audience arguments. A filter file is now the only way to filter.
# - Warns when bitfields overlap.
# - Print warning for registers with too many bits.
# - BV_ macros are commented with the bitfield value description.
#
# 1.0b4:
# - Better parsing of access modes.
# - Support creating multi-instance registers.
# - Do a better job cleaning up register and bitfield names.
# - Make a reasonable attempt to identify reserved bitfields whose name is not '-'.
#
# 1.0b3:
# - Improve formatting of long description comments.
# - Compress whitespace in all text.
# - Warn for registers with duplicate addresses or names.
# - Added comment with list of all registers at top of header.
# - A few header improvements.
# - Support RW/RO registers and bitfields.
# - Moved template strings to CHeaderTemplates class.
# - Renamed WrongProductException to ExcludedByFilterException.
#
# 1.0b2:
# - initial released version
#

# Tool version number and copyright string.
kToolVersion = "1.0b7"
kToolCopyright = "Copyright (c) 2012 Freescale Semiconductor, Inc. All rights reserved."

## Possible access modes for registers and bitfields. This list is just for reference.
kAccessModes = ['R', 'W', 'RW', 'RO', 'WO', 'WORZ', 'ROZ', 'RORZ', 'ROO', 'RU', 'W1C', 'RC1']

## Standard C library names.
#
# There are a ton more standard C macros, but most aren't likely to cause a conflict.
kStandardLibNames = [ 'NULL', 'SIZE_MAX' ]

##
# @brief Returns true if the access mode allows for reading.
def isAccessModeReadable(mode):
    return ('R' in mode or mode == 'W1C') and mode != 'WORZ'

##
# @brief Returns true if the access mode allows for writing.
def isAccessModeWriteable(mode):
    return 'W' in mode

##
# @brief Replace runs of whitespace with single space characters.
#
# Also strips whitespace off the beginning and end of the input text.
def cleanWhitespace(text):
    if text is None:
        return ''
    return ' '.join(re.split('[ \t\n]+', text.strip().replace('\\', '')))

##
# @brief Turns an Element tree into a string.
#
# Given a tree of Element objects, this function will produce readable output from the text
# contained in those elements.
def formatText(rootElem):
    if rootElem is None:
        return ''
    return " ".join([cleanWhitespace(q) for q in rootElem.itertext()])

##
# @brief Make text into a valid C identifier.
def formatIdentifier(text):
    if text is None:
        return "_"
    # Find all "words". Allow a few other chars so words like "FOO.BAR" will be matched and
    # converted to "FOO_BAR".
    matches = [m for m in re.findall('([a-zA-Z0-9_]+[a-zA-Z0-9_ \.\-]*)', cleanWhitespace(text.upper())) if len(m)]
    if len(matches) == 0:   # Bail if we didn't get any matches.
        return "_"
    result = re.sub('[ \t\n\.\-]+', '_', matches[0].strip())    # Convert some chars to underscores.
    if result[0] in "0123456789":   # Add underscore prefix if the first char is a digit.
        result = '_' + result
    result = re.sub('_+$', '', result) # Remove trailing underscores.
#     print >> sys.stderr, "ID: %s -> %s" % (text, result)
    return result

##
# @brief Converts a hex address string to an integer value.
#
# @param addressString A string of hex digits in the form "020C_4000". There may be a "0x"
#   prefix. Any characters that are not hex digits are stripped.
# @param base Base of the number. Pass 0 to use the string prefix to determine the base.
# @return The integer value of @a addressString.
def convertHexValue(addressString, base=0):
    if len(addressString) == 0:
        return 0
    
    if addressString.startswith('0x'):
        addressString = addressString[2:]
        base = 16
    elif addressString.endswith('h'):
        addressString = addressString[:-1]
        base = 16

    digits = ''.join([d for d in addressString if (d in string.hexdigits)])

    hasHexDigit = False
    for d in digits:
        if d in 'abcdefABCDEF':
            hasHexDigit = True
            break

    if hasHexDigit or digits.startswith('0'):
        base = 16
    
    if len(digits) == 0:
        return 0
    
    return int(digits, base)

##
# @brief Test whether the string has only 0 and 1 characters in it.
def hasOnlyBinaryDigits(valueString):
    for digit in valueString:
        if digit not in "01xX":
            return False
    return True

##
# @brief Convert a binary number from string to an integer.
# @exception Exception Raised if the input string is not a binary number, i.e. if it contains
#   characters other than '0' or '1'.
def convertBinaryValue(valueString):
    #print >> sys.stderr, "converting bin: " + valueString
    if len(valueString) == 0:
        return 0
    
    result = 0
    for i in range(len(valueString)):
        digit = valueString[-(i + 1)]
        if digit not in "01xX":
            raise Exception("string in not a binary value: " + valueString)
        if digit.lower() == 'x':
            digit = '0'
        result += int(digit) << i
        #print >> sys.stderr, "   %d dig=%s, r= %x" % (i, digit, result)
    
    return result

##
# @brief Check an attribute against a list of values.
# @retval True There was either no feature attribute or the feature was found in the features list.
# @retval False A feature attribute was present but none of its values were found in the features
#       list.
def checkAttribList(elem, attribName, values):
    attrib = elem.get(attribName)
    if attrib is None:
        return True
    
    # See if any of the features in the attribute are in our features list.
    for theAttribValue in attrib.split():
        if theAttribValue.lower() in values:
            return True
    
    # Didn't find a feature in our features list, so return false.
    return False

##
# @brief Filter attributes against a dictionary of values.
# @param elem The Element object with the attribetus to check.
# @param attribs Dictionary with attribute names as keys and allowed attribute value lists as values.
# @retval True Attribtues passed all checks.
# @retval False An attribute value was not present in the dictionary.
def filterAttributes(elem, attribs):
    for attribName in attribs.keys():
        if not checkAttribList(elem, attribName, attribs[attribName]):
            return False
    
    # Everything checks out.
    return True

##
# @brief Get the text of an element path, or an empty string.
# @param rootElem The Element instance from which to find @a path. If @a path is not provided, then
#   the return value will be the text of this element itself.
# @param path Element path from the root to the child node whose text to get. This parameter is
#   optional, and if not provided the text of @a rootElem will be returned.
# @param default The default value to provide if the desired element does not exist or has no text.
# @return A string containing the text contained directly in the desired element. If no matching
#   element is found or there is no text then @a default is returned. The returned string
#   is stripped of whitespace at the beginning and end, all newlines are removed, and runs of
#   multiple spaces and/or tabs are compressed to a single space character (@ref cleanWhitespace()).
def getElementText(rootElem, path=None, default=''):
    if rootElem is None:
        return default
    
    if path is None:
        elem = rootElem
    else:
        elem = rootElem.find(path)
    
    if elem is None or elem.text is None:
        return default
    else:
        return cleanWhitespace(elem.text)

##
# @brief Test whether a bitfield name indicates the bitfield is reserved.
def isReservedName(ident):
    if ident == '-':
        return True
    elif ident == '_':
        return True
    elif ident.startswith("RESERVED"):
        return True
    elif ident.startswith("RSVD"):
        return True
    elif ident.startswith("UNDEFINED"):
        return True
    elif ident.startswith("RSRVD"):
        return True
    else:
        return False

##
# @brief Apply a pattern to a base name.
# @param baseName The base string to which the qualifiers are applied to generate the output list.
# @param qualifiers A list of strings to apply to the base name using the pattern.
# @param pattern Either the string "end", an integer as a string, or an integer value. The pattern
#   should already have whitespace cleaned and be stripped, but it doesn't have to be converted
#   to lowercase.
# @return A list of strings.
def applyNamePattern(baseName, qualifiers, pattern):
    # Get the position to insert the qualifier string in the base name.
    if type(pattern) == types.StringType:
        if pattern.lower() == "end":
            insertPos = len(baseName)
        else:
            insertPos = int(pattern)
    else:
        insertPos = pattern
    
    return [(baseName[:insertPos] + q + baseName[insertPos:]) for q in qualifiers]

##
# @brief Exception thrown to indicate a mismatched product.
class ExcludedByFilterException(Exception):
    pass

##
# @brief Holds component information.
class Component:
    def __init__(self, memoryMap, name, designName):
        self.memoryMap = memoryMap
        self.name = name.upper()
        self.designName = designName.upper()
        self.registers = []
        
        self.count = self.memoryMap.getInstanceCount(self.designName)
        self.isMultiInstance = (self.count > 1)
        
        # Get address of first instance.
        self.baseAddress = self.memoryMap.getBaseAddress(self.designName, 0)
        
        self.structName = "_hw_%s" % (self.name.lower())
        self.typedefName = "hw_%s_t" % (self.name.lower())
    
    def addRegister(self, reg):
        # Check for a pre-existing register with the same name.
        if self.getRegisterWithName(reg.name) is not None:
            print >> sys.stderr, "Warning: register already exists with the name %s in %s!" % (reg.name, self.name)
            return
        
        # Check for register with the same address offset.
        if self.getRegisterWithOffset(reg.addressOffset) is not None:
            print >> sys.stderr, "Warning: register %s of %s has the same offset as another register!" % (reg.name, self.name)
            return
        
        # Add the new register and sort the list.
        self.registers.append(reg)
        self.sortRegisters()
        
    ##
    # @brief Sort registers by ascending address offset.
    def sortRegisters(self):
        # Sort registers by address.
        self.registers.sort(key=lambda reg:reg.addressOffset)
    
    def getRegisterWithName(self, name):
        for reg in self.registers:
            if reg.name == name:
                return reg
        
        return None
    
    def getRegisterWithOffset(self, offset):
        for reg in self.registers:
            if reg.addressOffset == offset:
                return reg
        
        return None

##
# @brief Register definition.
class Register:
    ## Dict to convert byte count to standard C type.
    kBitFieldTypes = { 1:"unsigned char", 2:"unsigned short", 4:"unsigned" }
    ## Dict to convert byte count to regX_t type.
    kRegTypes = { 1:'reg8_t', 2:'reg16_t', 4:'reg32_t' }
    
    ##
    # @brief Factory for registers.
    #
    # @return A list of zero or more Register instances. 
    @staticmethod
    def buildFromXml(component, elem, filterAttribs):
        # Filter based on attributes.
        if not filterAttributes(elem, filterAttribs):
            return []
        
        # Get the base name and description.
        name = formatIdentifier(getElementText(elem, 'registerName'))
        fullName = getElementText(elem, 'registerNameMore/registerNameFull')
        description = formatText(elem.find('registerBody/registerDescription'))
        
        # Get register properties element.
        props = elem.find('registerBody/registerProperties/registerPropset')
        
        # Determine how many related registers there are. Start off with a count and list that will
        # produce a single register.
        registersList = []
        registerCount = 1
        registerQualifiers = ['']
        namePattern = "end"
        offsetIncrement = 0
        dims = props.find('dimension')
        if dims is not None:
            dimValue = dims.find('dimensionValue')
            if dimValue is not None and dimValue.text is not None:
                registerCount = int(getElementText(dimValue, default='1'))
                offsetIncrement = int(getElementText(dims, 'dimensionIncrement', default='0'))
                registerQualifiers = [cleanWhitespace(s) for s in getElementText(dims, 'unitQualifier').split(',')]
                namePattern = getElementText(dims, 'namePattern')
        
        # Verify there are the same number if qualifiers and the dimension value.
        if registerCount != len(registerQualifiers):
            print >> sys.stderr, "Warning: register %s of %s qualifier count not equal to dimensionValue!" % (name, component.name)
            
            # Adjust count so we don't get an error.
            registerCount = min(registerCount, len(registerQualifiers))
        
        # Handle SCT qualifiers specially, so we don't create a Register instance for each
        # of the SCT variants.
        hasSct = ('_SET' in registerQualifiers) and ('_CLR' in registerQualifiers) and ('_TOG' in registerQualifiers)

        # Determine the list of register names.
        if hasSct:
            names = [name]
        else:
            # Generate the list of register names by applying name modifiers.
            names = applyNamePattern(name, registerQualifiers, namePattern)
        
        # Create the new registers.
        offsetDelta = 0
        for thisName in names:
            # Create the register instance and add it to the list.
            newRegister = Register(thisName, fullName, description, offsetDelta, component, props, hasSct, filterAttribs)
            newRegister.buildBitfields(elem, filterAttribs)
            registersList.append(newRegister)
            
            offsetDelta += offsetIncrement
        
        return registersList
    
    ##
    # @brief Constructor.
    # @param self
    # @param name
    # @param fullName
    # @param desc
    # @param offsetDelta
    # @param component
    # @param props
    # @param hasSct
    # @param filterAttribs
    def __init__(self, name, fullName, desc, offsetDelta, component, props, hasSct, filterAttribs):
        self.memoryMap = component.memoryMap
        self.component = component
        
        self.name = name
        self.fullName = fullName
        self.description = desc
        
        self.formattedName = "%s_%s" % (self.component.name, self.name)
        self.typedefName = "hw_%s_t" % (self.formattedName.lower())
        self.unionName = "_hw_%s" % (self.formattedName.lower())
        
        # Extract register details.
        self.addressOffset = convertHexValue(getElementText(props, 'addressOffset')) + offsetDelta
        self.sizeInBits = int(getElementText(props, 'registerSize'), 0)
        self.sizeInBytes = self.sizeInBits / 8
        self.access = getElementText(props, 'registerAccess').upper()
        if len(self.access) == 0:
            self.access = 'RO'
        self.isReadable = isAccessModeReadable(self.access)
        self.isWritable = isAccessModeWriteable(self.access)
        self.resetValue = convertHexValue(getElementText(props, 'registerResetValue'))
        self.hasSct = hasSct
        self.bitFields = []
        
        # Validate register size.
        if self.sizeInBits not in [8, 16, 32]:
            raise Exception("invalid register size: " + str(self.sizeInBits))
        
        # Get bitfield and regX-t type.
        self.bitFieldType = Register.kBitFieldTypes[self.sizeInBytes]
        self.regType = Register.kRegTypes[self.sizeInBytes]
    
    ##
    # @brief Create the BitField objects from the register XML node.
    def buildBitfields(self, registerElem, filterAttribs):
        # Create the BitField objects.
#         self.bitFields = []
        for e in registerElem.findall('bitField'):
            try:
                newField = BitField(self, e, filterAttribs)
                
                # Verify that there is not already a bitfield with the same bit range.
                for bit in range(newField.offset, newField.width):
                    existingField = self.getBitFieldForBit(bit)
                    if existingField is not None:
                        print >> sys.stderr, "Warning: bitfield %s of %s overlaps with bitfield %s!" % (newField.name, self.formattedName, existingField.name)
                        raise ExcludedByFilterException()
                
                self.bitFields.append(newField)
            except ExcludedByFilterException:
                # Just ignore this exception
                pass
        
        # Make sure all bits have a bitfield.
        self._createMissingBitFields()
        
        # Now sort the bitfields by bit number.
        self.sortBitFields()
        
        # Coalesce reserved bitfields.
        self._coalesceReservedBitFields()
        
        # Finally, verify that there are not more bitfield bits than register bits.
        bits = 0
        for field in self.bitFields:
            bits += field.width
        if bits > self.sizeInBits:
            print >> sys.stderr, "Warning: register %s of %s has %d total bits!" % (self.name, self.component.name, bits)
    
    ##
    # @brief Create reserved bitfields for missing bits.
    def _createMissingBitFields(self):
        i = 0
        while i < self.sizeInBits:
            field = self.getBitFieldForBit(i)
            if field is not None:
                i += field.width
                continue
            
            # There is a hole in the bitfields, so fill it in. First find out how big the hole is.
            holeWidth = 1
            while (i + holeWidth < self.sizeInBits) and (self.getBitFieldForBit(i + holeWidth) is None):
                holeWidth += 1
            
            self.bitFields.append(ReservedBitField(self, holeWidth, i))
            
            i += holeWidth
    
    ##
    # @brief Reserved bitfields next to each other are merged.
    def _coalesceReservedBitFields(self):
        # This while loop is used to allow for multiple passes over the bitfield list.
        doAnotherPass = True
        while doAnotherPass:
            i = 0
            doAnotherPass = False
            for i in range(len(self.bitFields) - 1):
                # Get the current bitfield and the next one.
                thisField = self.bitFields[i]
                nextField = self.bitFields[i + 1]
                
                # Merge the two bitfields if they are both reserved.
                if thisField.isReserved and nextField.isReserved:
                    # Create the merged reserved bitfield.
                    width = thisField.width + nextField.width
                    offset = thisField.offset
                    replacementBitField = ReservedBitField(self, width, offset)
                    
                    # Remove the current list entries.
                    del self.bitFields[i + 1]
                    del self.bitFields[i]
                    
                    # Add the replacement and re-sort.
                    self.bitFields.append(replacementBitField)
                    self.sortBitFields()
                    
                    # Say we need another pass over the bitfields and exit the for loop. However,
                    # we don't need another pass if we are already at the end of the list.
                    doAnotherPass = (i < len(self.bitFields) - 2)
                    break
    
    ##
    # @brief Sort bitfields in ascending bit offset order.
    def sortBitFields(self):
        self.bitFields.sort(key=lambda field:field.offset)
    
    def getBitFieldForBit(self, bitNumber):
        for field in self.bitFields:
            if field.hasBit(bitNumber):
                return field
        
        # Didn't find a matching bitfield!
        return None
    
    def dump(self):
        print "%s (0x%08x, %d, %s, 0x%08x):" % (self.formattedName, self.addressOffset, self.sizeInBits, self.access, self.resetValue)
        print "  fullName: " + self.fullName
        print "  desc: " + self.description
        print "  offset: " + hex(self.addressOffset)
        print "  access: " + self.access
        print "  reset: " + hex(self.resetValue)
        print "  related: " + `self.relatedRegisterSuffixes`
        print "  fields: "
        for f in self.bitFields:
            f.dump()

##
# @brief A bit field of a register.
class BitField:
    ##
    # @brief Regular expression to help filter bitfield names.
    #
    # Some bitfield names in the XML definitions have the bit ranges appended to the name, but we
    # can't allow that since we need to produce valid C code.
    nameFilter = re.compile(r'^([a-zA-Z_]+[a-zA-Z0-9_]*)')
    
    ##
    # @brief Factory for bitfields.
    #
    # @return A list of zero or more BitField objects. 
    @staticmethod
    def buildFromXml(component, elem, filterAttribs):
        return None
    
    ##
    # @exception ExcludedByFilterException Raised when the XML element has an attribute that specifies
    #   that it belongs to a product other than the one passed on @a productName.
    def __init__(self, reg, elem, filterAttribs):
        # Filter based on attributes.
        if not filterAttributes(elem, filterAttribs):
            raise ExcludedByFilterException()
        
        self.register = reg
        self.element = elem
        self.name = getElementText(elem, 'bitFieldName')
        self.description = formatText(elem.find('bitFieldBody/bitFieldDescription'))
        
        identName = formatIdentifier(self.name)
        
        # Make sure the identifier isn't a standard C library identifier. If it is, add an underscore.
        if identName in kStandardLibNames:
            identName += '_'
        
        # Try to figure out if the bitfield is reserved.
        self.isReserved = isReservedName(self.name) or isReservedName(identName)
        
        # If it's not reserved, turn the name into a C identifier.
        if not self.isReserved:
            self.name = identName
        
        # Filter up the bitfield name and uppercase it. Some of the bitfield names has the bit
        # range appended to them, so we have to get rid of that.
        if not self.isReserved:
            try:
                nameMatch = BitField.nameFilter.match(self.name)
                self.name = nameMatch.group(1).upper()
            except:
                # We couldn't find an identifier leading the name, so mark this field as reserved.
                self.isReserved = True
        
        self.formattedName = "%s_%s" % (self.register.formattedName, self.name)
        
        # Set the internal flag if the bitfield has an audience attribute with a value of "internal"
        self.isInternal = (elem.get('audience') == 'internal')
        
        # Get bitfield properties.
        props = elem.find('bitFieldBody/bitFieldProperties/bitFieldPropset')
        self.width = int(getElementText(props, 'bitWidth'))
        self.offset = int(getElementText(props, 'bitOffset'))
        self.topBitOffset = self.offset + self.width - 1
        self.access = getElementText(props, 'bitFieldAccess').upper()
        if len(self.access) == 0:
            self.access = 'RO'
        self.isReadable = isAccessModeReadable(self.access)
        self.isWritable = isAccessModeWriteable(self.access)
        
        self._makeBitRangeString()
        
        # Build mask.
        self._buildMask()
        
        # Build values list.
        self._buildValuesList(elem.findall('bitFieldBody/bitFieldValues/bitFieldValueGroup'), filterAttribs)
        
    def setName(self, newName):
        self.name = newName
        self.formattedName = "%s_%s" % (self.register.formattedName, self.name)
        
    def _makeBitRangeString(self):
        # Create bitfield range string.
        if self.width == 1:
            self.bitRangeString = str(self.offset)
        else:
            self.bitRangeString = "%d:%d" % (self.offset + self.width - 1, self.offset)
    
    def _buildValuesList(self, allValueElems, filterAttribs):
        self.values = []
        for valueElem in allValueElems:
            # Check filter.
            if not filterAttributes(valueElem, filterAttribs):
                continue
            
            # Get element nodes.
            value = valueElem.find('bitFieldValue')
            name = valueElem.find('bitFieldValueName')
            desc = valueElem.find('bitFieldValueDescription')
            
            # Skip if there is no value or name node.
            if value is None: # or name is None:
                continue
            
            # Check filter on name and value nodes.
            if not filterAttributes(value, filterAttribs): # or not filterAttributes(name, filterAttribs):
                continue
            
            # Build the value info dictionary.
            thisValue = UserDict()
            thisValue.valueText = cleanWhitespace(value.text)
            
            # Check for a binary value.
            try:
                if (len(thisValue.valueText) == self.width) and (hasOnlyBinaryDigits(thisValue.valueText)):
                    thisValue.value = convertBinaryValue(thisValue.valueText)
                else:
                    thisValue.value = convertHexValue(thisValue.valueText)
            except:
                # Ignore a failure to convert the value to an int.
                thisValue.value = 0
            
            if name is not None and filterAttributes(name, filterAttribs):
                thisValue.name = cleanWhitespace(name.text)
            else:
                thisValue.name = None
            
            # Skip if the name is empty.
            #if len(thisValue.name) == 0:
            #    continue
            
            if desc is None or not filterAttributes(desc, filterAttribs):
                thisValue.desc = ''
            else:
                thisValue.desc = formatText(desc)
            
            self.values.append(thisValue)
        
        # Now sort the values array by value.
        self.values.sort(key=lambda x:x.value)
    
    def _buildMask(self):
        self.mask = 0
        for i in range(self.width):
            self.mask = (self.mask << 1) | 1
        self.mask = self.mask << self.offset
    
    def hasBit(self, whichBit):
        return ((1 << whichBit) & self.mask) != 0
    
    def dump(self):
        if self.width == 1:
            b = str(self.offset)
        else:
            b = "%d:%d" % ((self.offset + self.width - 1), self.offset)
        
        print "    %s[%s] (%s)" % (self.formattedName, b, self.access) #, self.description)
        for v in self.values:
            print "        0x%08x = %s" % (v.value, v.name)

class ReservedBitField(BitField):
    def __init__(self, reg, width, offset):
        self.register = reg
        self.name = "-"
        self.width = width
        self.offset = offset
        self.access = 'ROZ'
        self.values = []
        self.isReserved = True
        self.isInternal = False
        self.formattedName = "-"
        self.description = "Reserved."
        
        self._makeBitRangeString()
        self._buildMask()

##
# @brief Component memory map.
class MemoryMap:
    def __init__(self, elem):
        self.element = elem
        self.components = {}
        
        for theComponent in elem.findall('component-ref'):
            try:
                name, instances = self._processComponent(theComponent)
                
                self.components[name] = instances
                
            except Exception, e:
                print >> sys.stderr, "Error processing component: " + str(e)
                raise
    
    ##
    # @return A list containing UserDict objects for each instance of the component.
    def _processComponent(self, component):
        # Create a dictionary to hold component info
        instances = []
        
        # Extract attribtues.
        name = cleanWhitespace(component.get('ip-name')).upper()
        base = convertHexValue(component.get('base-address'), 16) # string in the form "020C_4000"
        
        # Try to get attributes for multiple instances. These are optional attributes. If the
        # attribute doesn't exist, then Element.get() will return None.
        count = component.get('instancesNumber')
        if count is None:
            count = 1
        else:
            count = int(cleanWhitespace(count))
            
        # Get the list of instance name modifiers. We assume these are appended to the name,
        # although we really should be using the namePattern attribute.
        qualifiers = cleanWhitespace(component.get('unitQualifier'))
        if qualifiers is None:
            qualifiers = ['']
        else:
            qualifiers = qualifiers.split(',')
        
        # Build the list of address offsets for each instance. The list must start with 0, for
        # the first instance, which is not included in the instanceOffsets attribute.
        offsets = cleanWhitespace(component.get('instanceOffsets'))
        if offsets is None:
            offsets = [0]
        else:
            offsets = [0] + [convertHexValue(o, 16) for o in offsets.split(',')]
        
        # Iterate over the instances.
        for i in range(count):
            instance = UserDict()
            instance.name = name + qualifiers[i]
            instance.offset = offsets[i]
            instance.baseAddress = base + offsets[i]
            
            instances.append(instance)
        
        return (name, instances)
    
    def dump(self):
        for k in sorted(self.components):
            i = self.components[k]
            print "%s: 0x%08x" % (i.name, i.baseAddress)
    
    def hasInstance(self, name, instance):
        try:
            x = self.components[name][instance].baseAddress
            return True
        except KeyError:
            #print >> sys.stderr, "Warning: failed to find base address for component %s instance %d" % (name, instance)
            return False
    
    def getBaseAddress(self, name, instance):
        try:
            return self.components[name][instance].baseAddress
        except KeyError:
            #print >> sys.stderr, "Warning: failed to find base address for component %s instance %d" % (name, instance)
            return 0
    
    def getInstanceCount(self, name):
        try:
            return len(self.components[name])
        except KeyError:
            return 0
    
    ##
    # @brief Override the list of instances for a component.
    # @param self
    # @param componentName The name of the component to set instances of.
    # @param baseAddress Base address of the first instance.
    # @param offsetList List of offsets from the base address for each instance. If an offset of 0
    #   is not present in the list, it will be added automatically.
    def setInstances(self, componentName, baseAddress, offsetList=[]):
        # Make sure there is a 0 in the list.
        if not 0 in offsetList:
            offsetList = [0] + offsetList
        
        instances = []
        i = 1
        for offset in offsetList:
            instance = UserDict()
            instance.name = componentName + str(i)
            instance.offset = offset
            instance.baseAddress = baseAddress + offset
            
            instances.append(instance)
        
        self.components[componentName] = instances

##
# @brief Class to hold template strings for header generation.
#
# The template strings are separated into this class in order to break the "view" out from the
# controller.
class CHeaderTemplates:
    fileTemplate = u"""/*
 * Copyright (C) {year}, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _{component.name}_H
#define _{component.name}_H

#include "regs.h"

/*
 * {fileCommentHead}
 *
{registerList} *
 * {component.typedefName} - Struct containing all module registers.
 */

//! @name Module base addresses
//@{{
#ifndef REGS_{component.name}_BASE
{baseAddressMacros}#endif
//@}}
{registerDefinitions}
{moduleStructDefinition}

#endif // _{component.name}_H
"""
    
    fileCommentHeadTemplate = u"{component.name} registers defined in this header file."
    fileCommentHeadWithChipTemplate = u"{chipName} {component.name} registers defined in this header file."
    
    baseAddressTemplate = u"#define REGS_{component.name}_BASE ({component.baseAddress:#010x}) //!< Base address for {component.name}.\n"

    baseAddressTemplateMulti = u"#define REGS_{component.name}{instanceNumber}_BASE ({instanceOffset:#010x}) //!< Base address for {component.name} instance number {instanceNumber}.\n"

    baseAddressMultiMacroTemplate1 = u"""
//! @brief Get the base address of {component.name} by instance number.
//! @param x {component.name} instance number, from 0 through {component.count}.
#define REGS_{component.name}_BASE(x) ( """
    baseAddressMultiMacroTemplate2 = u"x == {instanceNumber} ? REGS_{component.name}{instanceNumber}_BASE : "
    baseAddressMultiMacroTemplate3= u"0xffff0000)\n"
    
    regListEntryTemplate = u" * - HW_{reg.formattedName} - {reg.fullName}\n"

    regTemplate = u"""
#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_{reg.formattedName} - {reg.fullName} ({reg.access})
 *
 * Reset value: {reg.resetValue:#010x}
 *
{regComment}
 */
typedef union {reg.unionName}
{{
    reg{reg.sizeInBits}_t U;
    struct {reg.unionName}_bitfields
    {{
{bitFields}    }} B;
}} {reg.typedefName};
#endif

/*
 * constants & macros for entire {reg.formattedName} register
 */
#define HW_{reg.formattedName}_ADDR      (REGS_{component.name}_BASE + {reg.addressOffset:#x})
{sctAddresses}
#ifndef __LANGUAGE_ASM__
#define HW_{reg.formattedName}           (*(volatile {reg.typedefName} *) HW_{reg.formattedName}_ADDR)
{readMacros}{writeMacros}{sctMacros}#endif

/*
 * constants & macros for individual {reg.formattedName} bitfields
 */
"""

    regTemplateMulti = u"""
#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_{reg.formattedName} - {reg.fullName} ({reg.access})
 *
 * Reset value: {reg.resetValue:#010x}
 *
{regComment}
 */
typedef union {reg.unionName}
{{
    reg{reg.sizeInBits}_t U;
    struct {reg.unionName}_bitfields
    {{
{bitFields}    }} B;
}} {reg.typedefName};
#endif

/*
 * constants & macros for entire multi-block {reg.formattedName} register
 */
#define HW_{reg.formattedName}_ADDR(x)      (REGS_{component.name}_BASE(x) + {reg.addressOffset:#x})
{sctAddresses}
#ifndef __LANGUAGE_ASM__
#define HW_{reg.formattedName}(x)           (*(volatile {reg.typedefName} *) HW_{reg.formattedName}_ADDR(x))
{readMacros}{writeMacros}{sctMacros}#endif

/*
 * constants & macros for individual {reg.formattedName} bitfields
 */
"""
    
    regReadTemplate = u"#define HW_{reg.formattedName}_RD()      (HW_{reg.formattedName}.U)\n"
    regReadTemplateMulti = u"#define HW_{reg.formattedName}_RD(x)        (HW_{reg.formattedName}(x).U)\n"
    
    regWriteTemplate = u"#define HW_{reg.formattedName}_WR(v)     (HW_{reg.formattedName}.U = (v))\n"
    regWriteTemplateMulti = u"#define HW_{reg.formattedName}_WR(x, v)     (HW_{reg.formattedName}(x).U = (v))\n"
    
    regSctAddressesTemplate = u"""#define HW_{reg.formattedName}_SET_ADDR  (HW_{reg.formattedName}_ADDR + 0x4)
#define HW_{reg.formattedName}_CLR_ADDR  (HW_{reg.formattedName}_ADDR + 0x8)
#define HW_{reg.formattedName}_TOG_ADDR  (HW_{reg.formattedName}_ADDR + 0xC)
"""
    regSctAddressesTemplateMulti = u"""#define HW_{reg.formattedName}_SET_ADDR(x)  (HW_{reg.formattedName}_ADDR(x) + 0x4)
#define HW_{reg.formattedName}_CLR_ADDR(x)  (HW_{reg.formattedName}_ADDR(x) + 0x8)
#define HW_{reg.formattedName}_TOG_ADDR(x)  (HW_{reg.formattedName}_ADDR(x) + 0xC)
"""
    
    regSctTemplate = u"""#define HW_{reg.formattedName}_SET(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() |  (v)))
#define HW_{reg.formattedName}_CLR(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() & ~(v)))
#define HW_{reg.formattedName}_TOG(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() ^  (v)))
"""
    regSctTemplateMulti = u"""#define HW_{reg.formattedName}_SET(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) |  (v)))
#define HW_{reg.formattedName}_CLR(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) & ~(v)))
#define HW_{reg.formattedName}_TOG(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) ^  (v)))
"""

    regRealSctTemplate = u"""#define HW_{reg.formattedName}_SET(v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_SET_ADDR) = (v))
#define HW_{reg.formattedName}_CLR(v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_CLR_ADDR) = (v))
#define HW_{reg.formattedName}_TOG(v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_TOG_ADDR) = (v))
"""
    regRealSctTemplateMulti = u"""#define HW_{reg.formattedName}_SET(x, v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_SET_ADDR(x)) = (v))
#define HW_{reg.formattedName}_CLR(x, v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_CLR_ADDR(x)) = (v))
#define HW_{reg.formattedName}_TOG(x, v)    ((*(volatile reg32_t *) HW_{reg.formattedName}_TOG_ADDR(x)) = (v))
"""

    structBitFieldTemplate = u"        {fieldType} {fieldName} : {fieldWidth}; //!< [{fieldBitRange}] {fieldDesc}\n"

    bitFieldTemplate = u"""
/* --- Register HW_{reg.formattedName}, field {field.name}[{field.bitRangeString}] ({field.access})
 *
{fieldComment} */

#define BP_{field.formattedName}      ({field.offset})      //!< Bit position for {field.formattedName}.
#define BM_{field.formattedName}      ({field.mask:#010x})  //!< Bit mask for {field.formattedName}.

//! @brief Get value of {field.formattedName} from a register value.
#define BG_{field.formattedName}(r)   (((r) & BM_{field.formattedName}) >> BP_{field.formattedName})
"""

    bitFieldValuePrefixTemplate = u" *\n * Values:\n"
    bitFieldValueCommentTemplate = u" * {value.name} = {value.valueText} - {valueDesc}\n"
    bitFieldValueNoNameCommentTemplate = u" * {value.valueText} - {valueDesc}\n"
    
    bitFieldFormatTemplate = u"""
#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield {field.formattedName}.
#define BF_{field.formattedName}(v)   (((({reg.regType}) v) << BP_{field.formattedName}) & BM_{field.formattedName})
#else
//! @brief Format value for bitfield {field.formattedName}.
#define BF_{field.formattedName}(v)   (((v) << BP_{field.formattedName}) & BM_{field.formattedName})
#endif
"""

    bitFieldWriteSctTemplate = u"""
#ifndef __LANGUAGE_ASM__
//! @brief Set the {field.name} field to a new value.
#define BW_{field.formattedName}(v)   BF_CS1({component.name}_{reg.name}, {field.name}, v)
#endif
"""
    bitFieldWriteSctTemplateMulti = u"""
#ifndef __LANGUAGE_ASM__
//! @brief Set the {field.name} field to a new value.
#define BW_{field.formattedName}(x, v)   BFn_CS1((x), {component.name}_{reg.name}, {field.name}, v)
#endif
"""

    bitFieldWriteNoSctTemplate = u"""
#ifndef __LANGUAGE_ASM__
//! @brief Set the {field.name} field to a new value.
#define BW_{field.formattedName}(v)   (HW_{reg.formattedName}_WR((HW_{reg.formattedName}_RD() & ~BM_{field.formattedName}) | BF_{field.formattedName}(v)))
#endif
"""
    bitFieldWriteNoSctTemplateMulti = u"""
#ifndef __LANGUAGE_ASM__
//! @brief Set the {field.name} field to a new value.
#define BW_{field.formattedName}(x, v)   (HW_{reg.formattedName}_WR(x, (HW_{reg.formattedName}_RD(x) & ~BM_{field.formattedName}) | BF_{field.formattedName}(v)))
#endif
"""

    bitFieldValueTemplate = u"#define BV_{field.formattedName}__{value.name} ({value.value:#x}) //!< {value.desc}\n"

    moduleStructTemplate = u"""
/*!
 * @brief All {component.name} module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct {component.structName}
{{
{structMembers}}} {component.typedefName};
#pragma pack()
#endif
"""

    moduleStructMemberTemplate = u"    volatile {reg.typedefName} {reg.name}; //!< {reg.fullName}\n"
    moduleStructSctMemberTemplate = u"    volatile {reg.regType} {reg.name}{suffix}; //!< {reg.fullName} {sctDesc}\n"
    moduleStructPaddingTemplate = u"    {paddingType} {paddingName}{paddingBytes};\n"

    moduleStructRefTemplate = u"""
//! @brief Macro to access all {component.name} registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_{component.name}(0)</code>.
#define HW_{component.name}     (*(volatile {component.typedefName} *) REGS_{component.name}_BASE)
"""
    moduleStructRefTemplateMulti = u"""
//! @brief Macro to access all {component.name} registers.
//! @param x {component.name} instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_{component.name}(0)</code>.
#define HW_{component.name}(x)     (*(volatile {component.typedefName} *) REGS_{component.name}_BASE(x))
"""

##
# @brief Generate a header file from a component.
class HeaderGenerator:
    ##
    # @brief Constructor.
    def __init__(self, component):
        self.chipName = None
        self.component = component
        self.templates = CHeaderTemplates
        self.commentWrapper = textwrap.TextWrapper(width=100, initial_indent=" * ", subsequent_indent=" * ")
        self.bitfieldValueCommentWrapper = textwrap.TextWrapper(width=100, subsequent_indent=" *     ")
    
    ##
    # @brief Specify the chip name.
    def setChipName(self, name):
        self.chipName = name
    
    ##
    # @brief Generate output.
    def generate(self, outputFile=sys.stdout):
        regs = ""
        
        for aReg in self.component.registers:
            regs += self._generateRegister(aReg)
        
        baseAddressMacros = self._generateBaseAddressMacros()
        moduleStruct = self._generateModuleStruct()
        registerList = self._generateRegisterList()
        
        # Get the current year.
        year = datetime.datetime.today().year
        
        if self.chipName:
            commentHead = self.templates.fileCommentHeadWithChipTemplate.format(component=self.component, chipName=self.chipName)
        else:
            commentHead = self.templates.fileCommentHeadTemplate.format(component=self.component)
        
        formatDict = { 'component':self.component,
                        'baseAddressMacros':baseAddressMacros,
                        'registerList':registerList,
                        'registerDefinitions':regs,
                        'moduleStructDefinition':moduleStruct,
                        'year':year,
                        'fileCommentHead':commentHead }
        
        s = self.templates.fileTemplate.format(**formatDict)
        
        # Write the header in UTF-8 encoding to the output file.
        writer = codecs.getwriter('utf-8')(outputFile)
        writer.write(s)
    
    def _generateBaseAddressMacros(self):
        output = ""
        
        if not self.component.isMultiInstance:
            output = self.templates.baseAddressTemplate.format(component=self.component)
        else:
            txt = self.templates.baseAddressMultiMacroTemplate1.format(component=self.component)
            
            for i in range(self.component.count):
                # Check for a valid base address and print a warning if there isn't one.
                if not self.component.memoryMap.hasInstance(self.component.designName, i):
                    print >> sys.stderr, "Warning: failed to find base address for component %s instance %d" % (name, instance)

                # Get the base address for this instance. If the instance isn't in the memory map,
                # the base will default to 0.
                offset = self.component.memoryMap.getBaseAddress(self.component.designName, i)
                
                formatDict = { 'component':self.component,
                                'instanceNumber':i + 1, # Start numbering at 1 like the RM.
                                'instanceOffset':offset }
                output += self.templates.baseAddressTemplateMulti.format(**formatDict)
                txt += self.templates.baseAddressMultiMacroTemplate2.format(**formatDict)
            
            output += txt + self.templates.baseAddressMultiMacroTemplate3
        
        return output
    
    def _generateRegisterList(self):
        output = ""
        
        for reg in self.component.registers:
            output += self.templates.regListEntryTemplate.format(reg=reg)
        
        return output
        
    def _generateRegister(self, reg):
        # Select templates based on whether the compoennt is multi-instance.
        if self.component.isMultiInstance:
            whichTemplate = self.templates.regTemplateMulti
            whichReadTemplate = self.templates.regReadTemplateMulti
            whichWriteTemplate = self.templates.regWriteTemplateMulti
            
            if reg.hasSct:
                whichSctTemplate = self.templates.regRealSctTemplateMulti
            else:
                whichSctTemplate = self.templates.regSctTemplateMulti
            
            whichSctAddressesTemplate = self.templates.regSctAddressesTemplateMulti
        else:
            whichTemplate = self.templates.regTemplate
            whichReadTemplate = self.templates.regReadTemplate
            whichWriteTemplate = self.templates.regWriteTemplate
            
            if reg.hasSct:
                whichSctTemplate = self.templates.regRealSctTemplate
            else:
                whichSctTemplate = self.templates.regSctTemplate
            
            whichSctAddressesTemplate = self.templates.regSctAddressesTemplate
        
        bitFields = self._generateStructBitfields(reg)
        regComment = self.commentWrapper.fill(reg.description.strip().replace('\n', ' '))
        
        formatDict = { 'component':self.component,
                        'reg':reg,
                        'bitFields':bitFields,
                        'regComment':regComment,
                        'readMacros':'',
                        'writeMacros':'',
                        'sctMacros':'',
                        'sctAddresses':'' }
        
        # Add register read macros if the register is readable.
        if reg.isReadable:
            formatDict['readMacros'] = whichReadTemplate.format(**formatDict)
        
        # Add register write macros if the register is writable.
        if reg.isWritable:
            formatDict['writeMacros'] = whichWriteTemplate.format(**formatDict)
        
        # Add SCT macros if the register is both readable and writable.
        if reg.isReadable and reg.isWritable:
            # If the register has real SCT variants, we need to generate addresses for them.
            if reg.hasSct:
                formatDict['sctAddresses'] = whichSctAddressesTemplate.format(**formatDict)
            
            formatDict['sctMacros'] = whichSctTemplate.format(**formatDict)
        
        output = whichTemplate.format(**formatDict)
        output += self._generateBitfields(reg)
        
        return output
    
    def _generateStructBitfields(self, reg):
        output = ""
        reservedCount = 0
        usedNames = []
        
        for f in reg.bitFields:
            # Choose the name of this struct member. If the field is reserved, then ensure that
            # we have a unique name.
            if f.isReserved:
                fieldName = "RESERVED%d" % reservedCount
                reservedCount += 1
            else:
                fieldName = f.name
            
            # Second check for name uniqueness. If there was already a field with the same name,
            # then add a suffix to unique it.
            origFieldName = fieldName
            uniqueCount = 1
            hadDuplicateName = False
            while fieldName in usedNames:
                hadDuplicateName = True
                fieldName = origFieldName + str(uniqueCount)
                uniqueCount += 1
            
            # Handle a duplicate name.
            if hadDuplicateName:
                # Now, if the field is not reserved, go update the field's name to the uniqued value.
                if not f.isReserved:
                    f.setName(fieldName)
                
                # Print a warning.
                print >> sys.stderr, "Warning: register %s of %s has duplicate field %s, renamed to %s!" % (reg.name, self.component.name, origFieldName, fieldName)
            
            # Add to the list of used member names.
            usedNames.append(fieldName)
            
            # Clean up field description so it fits on one line.
            cleanDescription = cleanWhitespace(f.description)
            #" ".join([l.strip() for l in f.description.splitlines()])
            
            # Now generate this struct member definition.
            formatDict = { 'fieldName':fieldName,
                            'fieldWidth':f.width,
                            'fieldType':reg.bitFieldType,
                            'fieldDesc':cleanDescription,
                            'fieldBitRange':f.bitRangeString }
            output += self.templates.structBitFieldTemplate.format(**formatDict)
        
        return output
    
    def _generateBitfields(self, reg):
        output = ""
        
        for f in reg.bitFields:
            # Skip reserved bitfields.
            if f.isReserved:
                continue
            
            # Generate the comment for the bitfield.
            fieldComment = self.commentWrapper.fill(cleanWhitespace(f.description)) + '\n'

            # Add comments for each bitfield value.
            if len(f.values):
                fieldComment += self.templates.bitFieldValuePrefixTemplate
                for v in f.values:
                    if v.name:
                        theTemplate = self.templates.bitFieldValueCommentTemplate
                    else:
                        theTemplate = self.templates.bitFieldValueNoNameCommentTemplate
                    
                    valueDesc = self.bitfieldValueCommentWrapper.fill(v.desc)
                    fieldComment += theTemplate.format(value=v, valueDesc=valueDesc)
            
            # Generate the main bitfield definitions.
            formatDict = { 'component':self.component,
                            'reg':reg,
                            'field':f,
                            'fieldComment':fieldComment }
            output += self.templates.bitFieldTemplate.format(**formatDict)
            
            # Now append the bitfield write macros if both the register and bitfield are RW.
            if reg.isWritable and f.isWritable:
                # Select template to generate BW_ macros.
                if reg.hasSct:
                    if self.component.isMultiInstance:
                        whichWriteTemplate = self.templates.bitFieldWriteSctTemplateMulti
                    else:
                        whichWriteTemplate = self.templates.bitFieldWriteSctTemplate
                else:
                    if self.component.isMultiInstance:
                        whichWriteTemplate = self.templates.bitFieldWriteNoSctTemplateMulti
                    else:
                        whichWriteTemplate = self.templates.bitFieldWriteNoSctTemplate
                
                # Append BF_ macros.
                output += self.templates.bitFieldFormatTemplate.format(**formatDict)
                
                # Append BW_ macros only if the field is readable.
                if f.isReadable:
                    output += whichWriteTemplate.format(**formatDict)
            
            # Append bitfield value macros. Only add macros for values that have names.
            if len(f.values):
                output += "\n"
            for v in f.values:
                if v.name:
                    output += self.templates.bitFieldValueTemplate.format(value=v, **formatDict)
        
        return output
    
    def _generateModuleStruct(self):
        members = ""
        
        # Generate members of whole-module registers struct. If there are holes in the addresses,
        # then we have to insert padding fields.
        paddingCount = 0
        currentOffset = 0
        for aReg in self.component.registers:
            # Check if we need to insert padding.
            paddingBytes = aReg.addressOffset - currentOffset
            if paddingBytes > 0:
                currentOffset += paddingBytes
                
                if (paddingBytes % 4) == 0:
                    t = 'reg32_t'
                    n = paddingBytes / 4
                elif (paddingBytes % 2) == 0:
                    t = 'reg16_t'
                    n = paddingBytes / 2
                else:
                    t = 'reg8_t'
                    n = paddingBytes
                
                if n > 1:
                    nStr = "[%d]" % n
                else:
                    nStr = ''
                
                paddingName = "_reserved%d" % paddingCount
                paddingCount += 1
                
                paddingDict = { 'paddingType':t,
                                'paddingName':paddingName,
                                'paddingBytes':nStr }
                members += self.templates.moduleStructPaddingTemplate.format(**paddingDict)
            
            # Insert the main register struct member.
            members += self.templates.moduleStructMemberTemplate.format(reg=aReg)
            currentOffset += aReg.sizeInBytes
            
            # Insert members for SCT variants of the register.
            if aReg.hasSct:
                for suffix in ['_SET', '_CLR', '_TOG']:
                    sctDescriptions = { '_SET':"Set", '_CLR':"Clear", '_TOG':"Toggle" }
                    sctDict = { 'reg':aReg,
                                'suffix':suffix,
                                'sctDesc':sctDescriptions[suffix] }
                    members += self.templates.moduleStructSctMemberTemplate.format(**sctDict)
                    currentOffset += aReg.sizeInBytes
        
        formatDict = { 'component':self.component,
                        'structMembers':members }
        output = self.templates.moduleStructTemplate.format(**formatDict)
        
        if self.component.isMultiInstance:
            refTemplate = self.templates.moduleStructRefTemplateMulti
        else:
            refTemplate = self.templates.moduleStructRefTemplate
        
        output += refTemplate.format(**formatDict)
        
        return output

##
# @brief Tool to generate register header files from XML.
class HeaderGeneratorTool:
    def _printVersion(self):
        print os.path.basename(sys.argv[0]), kToolVersion
        print kToolCopyright

    ##
    # @brief Create a MemoryMap object from a design XML file.
    # @param self
    # @param design A file object containing the design XML.
    # @return A new MemoryMap instance that holds the component information read from the design XML.
    def _buildMap(self, designXml):
        if designXml is None:
            return None
        
        # Parse the design XML into a tree.
        designTree = ElementTree.ElementTree()
        designTree.parse(designXml)
        
        return MemoryMap(designTree.getroot())
    
    def _buildComponent(self, memoryMap, componentXmlFiles, forcedComponentName):
        component = None
        handledInstanceOverride = False
        for componentXml in componentXmlFiles:
            if not self.args.quiet:
                print >> sys.stderr, "Reading %s..." % (os.path.basename(componentXml.name))

            # Parse the component XML into a tree.
            tree = ElementTree.ElementTree()
            tree.parse(componentXml)
            
            # Extract the component's name. Fall back to componentName if ip-name is not there.
            nameNode = tree.find('ip-data/ip-name')
            if nameNode is None:
                nameNode = tree.find('componentName')
            componentName = nameNode.text.strip()
            
            if forcedComponentName is None:
                nameToUse = componentName
            else:
                nameToUse = forcedComponentName
            
            if self.args.design_name is None:
                designName = nameToUse
            else:
                designName = self.args.design_name
        
            # Override instances is provided on the command line. We have to wait until now to
            # do this because we only now know the component name. But we have to do it before the
            # first Component object is created.
            if self.args.base_address is not None and not handledInstanceOverride:
                baseAddress = convertHexValue(self.args.base_address, 16)
                if self.args.instance_offsets is None:
                    instanceOffsets = [0]
                else:
                    # Zero offset will be added for us by setInstances().
                    instanceOffsets = [convertHexValue(o) for o in self.args.instance_offsets.split(',')]
                memoryMap.setInstances(designName, baseAddress, instanceOffsets)
                handledInstanceOverride = True
    
            # Create component instance. If the component was already created, compare the name of
            # this component with previous ones to make sure they're the same.
            if component is None:
                component = Component(memoryMap, nameToUse, designName)
            elif (forcedComponentName is None) and (componentName != component.name):
                raise Exception("Error: not all input files are for the same component (%s, %s)" % (componentName, thisComponentName))
            
            # Get the list of registers.
            addrBlock = tree.find('memoryMap/addressBlock')
            registerElements = addrBlock.findall('register')
            
            for regElem in registerElements:
                try:
                    newRegs = Register.buildFromXml(component, regElem, self.filterAttribs)
                    for r in newRegs:
                        component.addRegister(r)
                except ExcludedByFilterException:
                    # Ignore this exception. It simply means that this register doesn't belong to the
                    # product we're working with.
                    pass
        
        return component
    
    ##
    # @brief Generate the register header file from input XML files.
    # @param self
    # @param designXml Chip design XML file object. May be None, but register addresses will be incorrect.
    # @param componentXmlFiles List of component XML file object that contains the register definitions.
    # @param forcedComponentName
    def _generateHeader(self, designXml, componentXmlFiles, forcedComponentName):
        # Create memory map and component objects from XML.
        memoryMap = self._buildMap(designXml)
        component = self._buildComponent(memoryMap, componentXmlFiles, forcedComponentName)
        
        # Generate output. It defaults to printing to stdout, but can be overidden with the
        # --output option.
        if not self.args.quiet:
            print >> sys.stderr, "Generating header for %s..." % (component.name)
        generator = HeaderGenerator(component)
        if self.args.chip_name is not None:
            generator.setChipName(self.args.chip_name)
        outputFile = self.args.output if (self.args.output is not None) else sys.stdout
        generator.generate(outputFile)

    ##
    # @brief Read the ditaval filter file.
    # @return A dictionary where the keys are attribute name and values are lists of included
    #       attribute values.
    def _readFilterFile(self, filterFile):
        tree = ElementTree.ElementTree()
        tree.parse(filterFile)
        result = {}
        for prop in tree.findall('prop'):
            action = prop.get('action')
            attribute = prop.get('att')
            value = prop.get('val')
            
            if action == 'include':
                if not result.has_key(attribute):
                    result[attribute] = []
                
                result[attribute].append(value)
        
        return result
    
    ##
    # @brief Read the command line and generate the output file.
    #
    # This method is the meat of the class; all other methods are here to support this one.
    #
    def run(self):
        # Process command line options.
        args = self._readOptions()
        self.args = args
        
        # Check for version option.
        if args.showVersion:
            self._printVersion()
            return

        # Verify that there is input.
        if len(args.components) == 0:
            print >> sys.stderr, "Error: no input component XML was provided"
            return
        
        # Check for a design file.
        if args.design is None and args.base_address is None:
            print >> sys.stderr, "Warning: no design XML was provided, register addresses will be invalid!"
        
        # Uppercase the forced component name.
        if args.name is not None:
            args.name = args.name.upper()
        
        # Read features from a file and add to features list.
        if args.filters is not None:
            self.filterAttribs = self._readFilterFile(args.filters)
        else:
            self.filterAttribs = { }
        #print >> sys.stderr, 'filter=' + repr(self.filterAttribs)
        
        # Generate the header file from the input XML.
        self._generateHeader(args.design, args.components, args.name)
        
    ##
    # @brief Parse command line options into an options dictionary.
    #
    # @return An object is returned that contains the command line options as attributes.
    def _readOptions(self):
        # Build arg parser.
        parser = argparse.ArgumentParser(description="Generate register headers from XML")

        parser.add_argument("-V", "--version", action="store_true", dest="showVersion", help="Show version information.")
        parser.add_argument("-q", "--quiet", action="store_true", help="Don't print informational messages.")
        parser.add_argument("-d", "--design", metavar="PATH", type=argparse.FileType('r'), help="Specify the design file with component details.")
        parser.add_argument("-f", "--filters", metavar="PATH", type=argparse.FileType('r'), help="Read filters from an XML file.")
        parser.add_argument("--chip-name", metavar="CHIP", help="Provide the name of the device, which will appear in header commments.")
        parser.add_argument("-n", "--name", help="Override the component name.")
        parser.add_argument("--design-name", metavar="NAME", help="Set the name used to look up the base address in the design file. Defaults to the component name.")
        parser.add_argument("--base-address", metavar="ADDRESS", help="Override component base address.")
        parser.add_argument("--instance-offsets", metavar="OFFSETS", help="Specify offsets of additional instances of the component. Offsets should be separated by a comma, with no extra whitespace. There will always be one instance with an offset of 0, so passing one offset to this option will result in two instances")
        parser.add_argument("-o", "--output", metavar="PATH", type=argparse.FileType('w'), help="Specify the output file.")
        parser.add_argument("components", nargs='*', type=argparse.FileType('r'), help="Component XML files. Must be for the same component.")

        return parser.parse_args()

# Are we being executed directly?
if __name__ == '__main__':
    HeaderGeneratorTool().run()


