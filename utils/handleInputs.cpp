#include "../cppMaker.main.hpp"

bool checkString(std::string const str)
{
	if (str.empty())
		return (false);
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalnum(str[i]) && str[i] != '/')
			return (false);
	}
	return (true);
}

void checkStop(bool stop)
{
	if (stop || g_interrupted > 0)
		throw std::exception();
}

int handleIndexInput(const std::string &inputType, int size, int (*f)(int &, std::string &))
{
	int index = -1;
	std::string buff = "";
	bool firstTry = true;
	while (index < 0)
	{
		if (firstTry)
		{
			std::cout << "Enter " << inputType << ": ";
			firstTry = false;
		}
		else
		{
			std::cout << "Please enter a valid " << inputType << ":  ";
		}
		std::cin >> buff;
		checkStop(std::cin.eof());
		index = f(size, buff);
	}
	return (index);
}

// While the input is not valid according to the function f,
// ask the user to enter a valid input.
// return the valid input.
std::string handleInput(std::string const &inputType, bool (*f)(std::string))
{
	std::string buff = "";
	bool firstTry = true;
	while (!f(buff))
	{
		if (firstTry)
		{
			std::cout << "Enter " << inputType << ": ";
			firstTry = false;
		}
		else
		{
			std::cout << "Please enter a valid " << inputType << ":  ";
		}
		std::cin >> buff;
		checkStop(std::cin.eof());
		if (!buff.compare(RETURN))
			return ("");
	}
	return (buff);
}
// Do you want to {inputType} ? (y/n)
bool handleInputYesNo(MenuList *list, const std::string &inputType, const MenuField &field)
{
	std::string buff = "";
	bool firstTry = true;
	if (!list)
		throw std::exception();

	printMenuInput(*list, "", field);
	while (1)
	{
		if (firstTry)
		{
			std::cout << "Do you want to " << inputType << "? (y/n)" << std::endl;
			firstTry = false;
		}
		else
		{
			std::cout << "Please enter \"y\" or \"n\" to " << inputType << "." << std::endl;
		}
		std::cin >> buff;
		checkStop(std::cin.eof());
		if (!buff.compare("y"))
			return (true);
		else if (!buff.compare("n"))
			return (false);
	}
	return (false);
}

// The user input goes into str
bool handleInputAndValidate(std::string &str, MenuList &list, const std::string &inputType, const MenuField &field)
{
	std::string buff;
	MenuList buffList = list;
	if (buffList.getSize() < 1)
		buffList.addItem("", PINK, false);
	buff.clear();
	while (1)
	{
		printMenuInput(list, "Go back", field);
		switch (field)
		{
		case MenuField::Name:
			buff = handleInput(inputType, checkString);
			buffList.getItem(0)->setName(buff);
			break;
		case MenuField::Path:
			buff = handleInput(inputType, checkString);
			buffList.getItem(0)->setInputPath(buff);
			break;
		}
		if (buff.empty())
			return (false);
		if (handleInputYesNo(&buffList, "use this " + inputType, field))
		{
			str = buff;
			return (true);
		}
	}
	return (false);
}