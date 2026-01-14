#include "Template.class.hpp"

Template::Template() {};

Template::~Template() {};

Template::Template(const Template &obj) { *this = obj; };

Template &Template::operator=(const Template &obj)
{
	if (this != &obj)
	{
	}
	return (*this);
};