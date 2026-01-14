#include "../cppMaker.main.hpp"

bool makefileMaker(MenuItem *item, MenuList *menu)
{
	int error = 0;
	bool success = false;

	if (!menu)
		return (true);

	// HANDLE PATH =================================
	item->setInputPath(pwd() + BASIC_PATH_MAKEFILE);

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
		// item->getInputPath().append("/" + item->getInputName());
		menu->changeItem(*item, 0);

		if (!handleInputYesNo(menu, "create Makefile at this path", MenuField::Path))
			return (false);

		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		// Create the file now.
		item->setColor(GREEN);
		item->increaseTimeUsed(1);
		return (false);
	}
	return (false);
}
