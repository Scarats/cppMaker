```
┌──────────────────────────────────────────┐
│                 __  ___     __           │
│  _______  ___  /  |/  /__ _/ /_____ ____ │
│ / __/ _ \/ _ \/ /|_/ / _ `/  '_/ -_) __/ │
│ \__/ .__/ .__/_/  /_/\_,_/_/\_\\__/_/    │
│   /_/  /_/                               │
└──────────────────────────────────────────┘
============================================
_|'.~*-MainMenu
============================================
1: Makefile
2: Main
3: Class
4: .cpp

0: Exit
============================================
```

# What's cppMaker
An auto class maker at first, that turned out to be a bootstraping tool for any C++ project.

It creates your `Makefile`, then the `main`, then `classes`, and then some utilities.

You can also use it to create only `classes`, or anything else you want — your machine, your choice.

For each file, a `path` is suggested. For classes, for example, they are created in `/classes/GivenClassName/`, but you can change it by entering a new path.

The next feature to be implemented is automatic Makefile updating, so that when you create a new class, the `.cpp` file is directly added to the `${SRC}` variable of your Makefile.

# How to use
## Compile
You can just compile it using ```make```, or use 
```
chmod +x build.sh
./build.sh
```
to have the program accessible anywhere in you terminal.
## Use
If you chose to just `make`, then 
```
./cppMaker
```
but if you chose to use `./build.sh`, then you can use
```
cppm
```
or 
```
cppMaker
```
anywhere in your terminal.


# Why cppMaker?
This is my first C++ project, so it is more of a learning exercise than a side project. It’s a fun way to learn and a very useful, time-saving tool for the rest of my C++ journey.
(The code is kinda aweful and would deserve to be rebuild from the ground up, but i'm too lazy for that, so as long as it works... lol)

# Customization
## Templates
You can customize the templates for each file directly in `./templates/`. The program replaces the word `template` during file creation using three variants:
- `template` → lowercase
- `Template` → first letter uppercase (class name, for example)
- `TEMPLATE` → uppercase (`#define`, for example)

## Paths and file extensions
You can change many settings, such as the paths used for each type of file and their file extensions (`.cpp`, `.hpp`, `.class.cpp`, etc.).  
You can find them in `cppMaker.main.hpp`.
