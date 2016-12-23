#!/usr/bin/python
import sys
import os
import os.path

print "Note: This script was written for Cocos2D-X 3.13. May not work on other versions."

# Get argument length
argvLen = len(sys.argv)

if argvLen <= 2 :
	print "Try ./python sceneGenerator.py [file name] [class name]"
	quit()

templateFileName = "cocos2d_scene_template"
sourceFileName = templateFileName + ".cpp"
headerFileName = templateFileName + ".h"
sourceFilePath = "./" + sourceFileName
headerFilePath = "./" + headerFileName

# Check if template file exists
if not os.path.exists(sourceFilePath) :
	print("Template source file doesn't exists.")
	quit()

if not os.access(sourceFilePath, os.R_OK) :
	print("Tempalte source file is not accessable.")
	quit()

if not os.path.exists(headerFilePath) :
	print("Template header file doesn't exsits.")
	quit()

if not os.access(headerFilePath, os.R_OK) :
	print("Template header is not accessable.")
	quit()


# Both cocos2d_scene_template.cpp and cocos2d_scene_template.h exists. Read both.
sourceFile = open(sourceFilePath, 'r')
headerFile = open(headerFilePath, 'r')

# source and header file to string data
sourceFileData = sourceFile.read()
headerFileData = headerFile.read()

# Get new class name and key
className = sys.argv[2]
classNameKey = "%SCENE_NAME"

# Replace class name in source file
sourceFileData = sourceFileData.replace(classNameKey, className)
headerFileData = headerFileData.replace(classNameKey, className)

# Get new file name
newFileName = sys.argv[1]
newSourceFilePath = "./" + newFileName + ".cpp"
newHeaderFilePath = "./" + newFileName + ".h"

# Get new file name key
newFileNameKey = "%FILE_NAME"

# replace file name only on source file for #include header.h
sourceFileData = sourceFileData.replace(newFileNameKey, newFileName)

# #ifndef, #define in header file
ifndefKey = "%HEADER_DEFINE"
defineName = className.upper() + "_H"

# repalce ifndef with class name
headerFileData = headerFileData.replace(ifndefKey, defineName)

# open or create new source file
newSourceFile = open(newSourceFilePath, 'w')
newHeaderFile = open(newHeaderFilePath, 'w')

# write new data
newSourceFile.write(sourceFileData)
newHeaderFile.write(headerFileData)


# close files
sourceFile.close()
headerFile.close()

newSourceFile.close()
newHeaderFile.close()

# report
print "Successfully created Cocos2D-X scene files."