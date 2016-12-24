# Cocos2D-X-Scene-Generator

This is a simple python (2.7) script that writes Cocos2D-X's scene file in C++ for you. 

## How to use
Open terminal or cmd at repo folder and run

> ./python sceneGenerator.py fileName className

First argument will be the file name you want to save and second argument is a class name you want to set.<br>
Script will create two files, one for source file(.cpp) and header(.h) as well.<br>

Generated scene class will have
- init, onEnter, update, onExit functions
- Mouse and keyboard listener with callback functions.

Some of above will need to be uncommented to use in source file. <br>
If you don't need any of these feature, just remove it.
