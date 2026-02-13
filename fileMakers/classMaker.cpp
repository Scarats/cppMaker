#include "../cppMaker.main.hpp"

bool classMaker(MenuItem *item, MenuList *menu)
{
	bool success = false;

	// CLASS NAME =================================
	if (!handleInputAndValidate(item->getInputName(), *menu, "class name", MenuField::Name))
		return (false);

	// HANDLE PATH =================================
	item->setInputPath(pwd() + BASIC_PATH_CLASS_HPP + "/");

	if (menu->getSize() < 1)
		menu->addItemBasic(item->getName());

	menu->getItem(0)->setInputPath(item->getInputPath());

	// // HANDLE LOGIC =================================
	success = handleInputYesNo(menu, "use this location", MenuField::Path);
	if (!success)
		success = handleInputAndValidate(item->getInputPath(), *menu, "new path", MenuField::Path);

	// HANDLE SUCCESS =================================
	if (success)
	{
		menu->changeItem(*item, 0);

		if (!handleInputYesNo(menu, "create class at this path", MenuField::Path))
			return (false);

		// createFile(item->getInput());
		// createFile(item->getInput());
		item->setInputType(tCLASS_HPP);
		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		item->setInputPath(pwd() + BASIC_PATH_CPP + "/");
		item->setInputType(tCLASS_CPP);
		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		addToMakefile(item, menu);
		if (item->getColor() != RED)
			item->setColor(GREEN);
		item->increaseTimeUsed(1);
		return (false);
	}
	return (false);
}