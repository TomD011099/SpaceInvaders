#SpaceInvaders

This game was created for a university project.

One of the most important requirements was that we worked with the Abstract Factory paradigm so that is the reason this is used here.

##Layout
Because of the abstract factory paradigm, most of the code is divided into two folders/namespaces: 
* Abs: This is where the abstract classes are stored, which are then implemented
* SDL: Here is the implementation of the game for SDL2

The main code, so `Game.cpp`, `Game.h` and `main.cpp` are all located in the main folder.

Sprites, backgrounds and sounds are all stored in the Media folder.

The Util folder houses the tinyXML2 library and a class that'll use tinyXML2 to read an XML file.

All global variables and enumerators are stored in the Const folder.

Last but not least, the <a href="ConfigInfo.md">config file</a>. This file is used to change game variables without having to recompile the game. 

##Game field
The game field is always normalized between 0 and 1 where 1 is the width/height of the screen. 

``` 
   0              1
 0 +-------------->
   |
   |
   |
 1 v
```
