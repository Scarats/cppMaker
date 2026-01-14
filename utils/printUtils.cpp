/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:51:18 by tcardair          #+#    #+#             */
/*   Updated: 2026/01/14 02:35:16 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cppMaker.main.hpp"

void printDelimiter()
{
	static std::string line = "";
	if (line.length() < 1)
	{
		line.append(44, '=');
	}
	std::cout << CYAN << line << RESET << std::endl;
}
void printMenuLineNumber(int i, int number, const std::string &str, const std::string &color)
{
	static const int nameWidth = 37;

	std::cout << i << ": "
			  << color << std::setw(nameWidth) << std::left << str
			  << " (" << number << ")" << RESET
			  << std::endl;
}

void printMenuLine(int i, const std::string &str, const std::string &color)
{
	if (i < 0)
		std::cout << color << str << RESET << std::endl;
	else
		std::cout << i << ": " << color << str << RESET << std::endl;
}

void printError(std::string const &error)
{
	std::cerr << RED << error << RESET << std::endl;
}

// Take an array of strings
void printListMenu(MenuList &list, const std::string &returnString, const MenuField &field)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		if (list.getItem(i) && list.getItem(i)->getTimeUsed() < 2)
		{
			switch (field)
			{
			case MenuField::Name:
				printMenuLine(i + 1, list.getItem(i)->getName(), list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLine(i + 1, list.getItem(i)->getInputPath(), list.getItem(i)->getColor());
				break;
			}
		}
		else
		{
			switch (field)
			{
			case MenuField::Name:
				printMenuLineNumber(i + 1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getName() + "", list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLineNumber(i + 1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getInputPath() + "", list.getItem(i)->getColor());
				break;
			}
		}
	}
	std::cout << std::endl;
	if (!returnString.empty())
		printMenuLine(0, returnString, PINK);
}

void printMenu(MenuList &list, const std::string &returnString, const MenuField &field)
{
	std::cout << CLEAR;
	printLogo();
	printDelimiter();
	std::cout << DARK_ORANGE << "_|'.~*-" << list.getName() << RESET << std::endl;
	printDelimiter();
	printListMenu(list, returnString, field);
	printDelimiter();
}

void printListMenuNoIndex(MenuList &list, const std::string &returnString, const MenuField &field)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		if (list.getItem(i) && list.getItem(i)->getTimeUsed() < 2)
			switch (field)
			{
			case MenuField::Name:
				printMenuLine(-1, list.getItem(i)->getInputName(), list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLine(-1, list.getItem(i)->getInputPath(), list.getItem(i)->getColor());
				break;
			}
		else
		{
			switch (field)
			{
			case MenuField::Name:
				printMenuLineNumber(-1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getInputName() + "", list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLineNumber(-1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getInputPath() + "", list.getItem(i)->getColor());
				break;
			}
		}
	}
	std::cout << std::endl;
	if (!returnString.empty())
		printMenuLine(0, returnString, PINK);
}

void printMenuNoIndex(MenuList &list, const std::string &returnString, const MenuField &field)
{
	std::cout << CLEAR;
	printLogo();
	printDelimiter();
	printListMenuNoIndex(list, returnString, field);
	printDelimiter();
}

void printListMenuInput(MenuList &list, const std::string &returnString, const MenuField &field)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		if (list.getItem(i) && list.getItem(i)->getTimeUsed() < 2)
		{
			switch (field)
			{
			case MenuField::Name:
				printMenuLine(i + 1, list.getItem(i)->getInputName(), list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLine(i + 1, list.getItem(i)->getInputPath(), list.getItem(i)->getColor());
				break;
			}
		}
		else
		{
			switch (field)
			{
			case MenuField::Name:
				printMenuLineNumber(i + 1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getInputName() + "", list.getItem(i)->getColor());
				break;
			case MenuField::Path:
				printMenuLineNumber(i + 1, list.getItem(i)->getTimeUsed(), list.getItem(i)->getInputPath() + "", list.getItem(i)->getColor());
				break;
			}
		}
	}
	std::cout << std::endl;
	if (!returnString.empty())
		printMenuLine(0, returnString, PINK);
}

void printMenuInput(MenuList &list, const std::string &returnString, const MenuField &field)
{
	std::cout << CLEAR;
	printLogo();
	printDelimiter();
	std::cout << DARK_ORANGE << "_|'.~*-" << list.getName() << RESET << std::endl;
	printDelimiter();
	printListMenu(list, returnString, field);
	printDelimiter();
}

void printLogo()
{
	std::cout << GREEN << R"ART(┌──────────────────────────────────────────┐
│                 __  ___     __           │
│  _______  ___  /  |/  /__ _/ /_____ ____ │
│ / __/ _ \/ _ \/ /|_/ / _ `/  '_/ -_) __/ │
│ \__/ .__/ .__/_/  /_/\_,_/_/\_\\__/_/    │
│   /_/  /_/                               │
└──────────────────────────────────────────┘
)ART" << RESET;
}
