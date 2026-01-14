#include "../cppMaker.main.hpp"

bool mainMaker(MenuItem *item, MenuList *menu)
{
	int error = 0;
	bool success = false;

	if (!menu)
		return (true);

	if (!handleInputAndValidate(item->getInputName(), *menu, "main name", MenuField::Name))
		return (false);

	// HANDLE PATH =================================
	item->setInputPath(pwd() + BASIC_PATH_MAIN);

	error = checkPath(item->getInputPath());
	if (menu->getSize() < 1)
		menu->addItemBasic(item->getName());

	menu->getItem(0)->setInputPath(item->getInputPath());

	// HANDLE LOGIC =================================
	if (error == 1)
	{
		success = handleInputYesNo(menu, "use this location", MenuField::Path);
		if (!success)
			success = handleInputAndValidate(item->getInputPath(), *menu, "new path", MenuField::Path);
	}
	else if (error == 0)
		success = handleInputAndValidate(item->getInputPath(), *menu, "new path", MenuField::Path);
	else
	{
		item->setColor(RED);
		return (false);
	}

	// HANDLE SUCCESS =================================
	if (success)
	{
		menu->changeItem(*item, 0);

		if (!handleInputYesNo(menu, "create main at this path", MenuField::Path))
			return (false);

		// createFile(item->getInput());
		// createFile(item->getInput());
		item->setInputType(tMAIN_HPP);
		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		item->setInputType(tMAIN_CPP);
		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		item->setColor(GREEN);
		item->increaseTimeUsed(1);
		return (false);
	}
	return (false);
}