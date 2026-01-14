#ifndef MENU_CLASS_HPP
#define MENU_CLASS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "../../includes/termColors.hpp"
#include "../UserInput/UserInput.class.hpp"

enum class MenuField
{
	Name,
	Path
};
class MenuItem
{
public:
	MenuItem(std::string name, std::string color, bool status);
	MenuItem() = default;
	MenuItem(const MenuItem &obj);
	MenuItem &operator=(const MenuItem &obj);

	void setStatus(bool status);
	bool getStatus(void);

	void setName(std::string name);
	std::string &getName(void);

	void setColor(std::string color);
	const std::string &getColor(void);

	void resetItem(void);

	void increaseTimeUsed(int i);
	int getTimeUsed(void);

	void setInputPath(const std::string &path);
	std::string &getInputPath(void);

	void setInputType(e_type type);
	const e_type &getInputType();

	void setInputName(const std::string &name);
	std::string &getInputName();

	UserInput &getInput();

private:
	UserInput _input;
	int _timeUsed = 0;
	std::string _name;
	std::string _color;
	bool _status;
};

class MenuList
{
public:
	MenuList();
	MenuList(std::string name);
	MenuList(const MenuList &);
	MenuList &operator=(const MenuList &obj);
	std::string &getName();
	int addItemBasic(std::string name);
	int addItem(std::string name, std::string color, bool status);
	void deleteItem(std::size_t index);
	MenuItem *getItem(std::size_t index);
	int getSize(void);
	void resetMenu(void);
	void changeItem(MenuItem &item, std::size_t index);
	void copyAndAddItem(MenuItem &item);

	// item = the item from the parent menu, that will change color according to the called function behavior.
	//	it also contains the UserInput.
	// menu = the menu displayed in the called function.
	bool (*function)(MenuItem *item, MenuList *menu);

private:
	std::vector<MenuItem> _vList;
	std::string _name;
};

class ListOfMenu
{
public:
	ListOfMenu();
	ListOfMenu(const std::string &name);
	MenuList &addMenu(const std::string &name);
	MenuList *getMenu(std::size_t index);
	int getSize(void);

private:
	std::vector<MenuList> _listOfMenu;
};

#endif