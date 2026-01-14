#include "Menu.class.hpp"

// MENU ITEMS ===============================================

void MenuItem::setInputName(const std::string &name)
{
	this->_input.setName(name);
}

MenuItem::MenuItem(std::string name, std::string color, bool status) : _name(name),
																	   _color(color),
																	   _status(status)
{
	this->setInputName(name);
}

MenuItem::MenuItem(const MenuItem &obj) { *this = obj; };

void MenuItem::setStatus(bool status) { this->_status = status; }

bool MenuItem::getStatus(void) { return (this->_status); }

void MenuItem::setName(std::string name) { this->_name = name; }

std::string &MenuItem::getName(void) { return (this->_name); }

void MenuItem::setColor(std::string color) { this->_color = color; }

const std::string &MenuItem::getColor(void)
{
	return (this->_color);
}

int MenuItem::getTimeUsed(void) { return (this->_timeUsed); }

void MenuItem::increaseTimeUsed(int i) { this->_timeUsed += i; }

void MenuItem::setInputPath(const std::string &path) { this->_input.setPath(path); }

std::string &MenuItem::getInputPath(void) { return (this->_input.getPath()); }

void MenuItem::setInputType(e_type type) { this->_input.setType(type); }
const e_type &MenuItem::getInputType() { return (this->_input.getType()); }

std::string &MenuItem::getInputName() { return (this->_input.getName()); }

UserInput &MenuItem::getInput()
{
	return (this->_input);
}

// MENU LIST =================================================

std::string &MenuList::getName()
{
	return (this->_name);
}

int MenuList::addItem(std::string name, std::string color, bool status)
{
	this->_vList.emplace_back(name, color, status);
	return (this->_vList.size());
}

int MenuList::addItemBasic(std::string name)
{
	this->_vList.emplace_back(MenuItem(name, PINK, false));
	return (this->_vList.size());
}

void MenuList::deleteItem(std::size_t index)
{
	this->_vList.erase(this->_vList.begin() + index);
}

MenuItem *MenuList::getItem(std::size_t index)
{
	if (index >= this->_vList.size())
		return (nullptr);
	return (&this->_vList[index]);
}

int MenuList::getSize(void)
{
	return (this->_vList.size());
}

// Reset the color and status of the item (not the name)
void MenuItem::resetItem(void)
{
	this->_name = "";
	this->_color = PINK;
	this->_status = false;
}

// Reset all the items of the list.
void MenuList::resetMenu(void)
{
	for (std::size_t i = 0; i < this->_vList.size(); i++)
		this->_vList[i].resetItem();
}

void MenuList::changeItem(MenuItem &item, std::size_t index)
{
	if (index >= this->_vList.size())
		return;

	this->_vList[index] = item;
}

void MenuList::copyAndAddItem(MenuItem &item)
{
	this->_vList.emplace_back(item);
}

MenuItem &MenuItem::operator=(const MenuItem &obj)
{
	if (this != &obj)
	{
		this->_color = obj._color;
		this->_name = obj._name;
		this->_input = obj._input;
		this->_status = obj._status;
		this->_timeUsed = obj._timeUsed;
	}
	return (*this);
}

MenuList &MenuList::operator=(const MenuList &obj)
{
	if (this != &obj)
	{
		this->_vList = obj._vList;
		this->_name = obj._name;
	}
	return (*this);
}

MenuList::MenuList() : _vList()
{
	function = nullptr;
}

MenuList::MenuList(std::string name) : _name(name)
{
	function = nullptr;
}

MenuList::MenuList(const MenuList &obj)
	: _vList(obj._vList),
	  _name(obj._name)
{
	function = nullptr;
}

// LIST OF MENU =================================================
ListOfMenu::ListOfMenu() : _listOfMenu() {}

ListOfMenu::ListOfMenu(const std::string &name)
{
	_listOfMenu.push_back(MenuList(name));
}
MenuList &ListOfMenu::addMenu(const std::string &name)
{
	this->_listOfMenu.push_back(MenuList(name));
	return (this->_listOfMenu.back());
}

MenuList *ListOfMenu::getMenu(std::size_t index)
{
	if (index >= this->_listOfMenu.size())
		return (nullptr);
	return (&this->_listOfMenu[index]);
}

int ListOfMenu::getSize(void)
{
	return (this->_listOfMenu.size());
}