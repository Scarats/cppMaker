#ifndef MAIN_HPP
#define MAIN_HPP

#include <csignal>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "classes/Menu/Menu.class.hpp"
#include "classes/UserInput/UserInput.class.hpp"
#include "includes/CheckString/CheckString.hpp"

// MAIN MENU ITEMS
#define RETURN "0"
#define MAKEFILE "Makefile"
#define MAIN "Main"
#define CLASS "Class"
#define CPP ".cpp"

// TEMPLATE PATH
#define MAKEFILE_PATH "templates/template.Makefile"
#define CLASS_CPP_PATH "templates/template.class.cpp"
#define CLASS_HPP_PATH "templates/template.class.hpp"
#define MAIN_HPP_PATH "templates/template.main.hpp"
#define MAIN_CPP_PATH "templates/template.main.cpp"

// CREATION PATH
#define BASIC_PATH_CLASS "/classes"
#define BASIC_PATH_CPP "/src"
#define BASIC_PATH_MAKEFILE ""
#define BASIC_PATH_MAIN ""

// FILE EXTENSION
#define DOT_CLASS_HPP ".class.hpp"
#define DOT_CLASS_CPP ".class.cpp"
#define DOT_CPP ".cpp"
#define DOT_HPP ".hpp"

extern volatile std::sig_atomic_t g_interrupted;

// PATH
std::string pwd(void);
int checkPath(std::string &path);

// FILE HANDLING
bool createFile(UserInput &input);

// FILE MAKERS
bool makefileMaker(MenuItem *item, MenuList *menu);
bool classMaker(MenuItem *item, MenuList *menu);
bool mainMaker(MenuItem *item, MenuList *menu);
bool dotCppMaker(MenuItem *item, MenuList *menu);

// INPUT
bool handleInputAndValidate(std::string &str, MenuList &list,
                            const std::string &inputType,
                            const MenuField &field);
bool handleInputYesNo(MenuList *list, const std::string &inputType,
                      const MenuField &field);
std::string handleInput(std::string const &inputType, bool (*f)(std::string));
int handleIndexInput(const std::string &inputType, int size,
                     int (*f)(int &, std::string &));
int getIndex(int &size, std::string &str);
bool checkString(std::string const str);

// REPLACE
void findAndReplace(std::string &str, UserInput &UserInput);

// PRINT
void printMenu(MenuList &list, const std::string &returnString,
               const MenuField &field);
void printMenuInput(MenuList &list, const std::string &returnString,
                    const MenuField &field);
void printMenuNoIndex(MenuList &list, const std::string &returnString,
                      const MenuField &field);
void printDelimiter();
void printLogo();
void printError(std::string const &error);

#endif