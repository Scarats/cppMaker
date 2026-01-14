#include "UserInput.class.hpp"

void UserInput::setName(const std::string &name)
{
	this->_name = name;
}

std::string &UserInput::getName(void)
{
	return (this->_name);
}

void UserInput::setPath(const std::string &path)
{
	this->_path = path;
}

std::string &UserInput::getPath(void)
{
	return (this->_path);
}

void UserInput::setType(const e_type &type)
{
	this->_type = type;
}

const e_type &UserInput::getType(void)
{
	return (this->_type);
}

void UserInput::resetVariables(void)
{
	this->_type = NONE;
	this->_name.clear();
	this->_path.clear();
}

UserInput::UserInput(const e_type &type, const std::string &name, const std::string &path) : _type(type), _name(name), _path(path) {}

void UserInput::setFileName(const std::string &name)
{
	this->_fileName = name;
}

std::string &UserInput::getFileName()
{
	return (this->_fileName);
}