#include "../cppMaker.main.hpp"

bool dotCppMaker(MenuItem *item, MenuList *menu)
{
	bool success = false;

	// CLASS NAME =================================
	if (!handleInputAndValidate(item->getInputName(), *menu, "file name", MenuField::Name))
		return (false);

	// HANDLE PATH =================================
	item->setInputPath(pwd() + BASIC_PATH_CPP);

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

		if (!handleInputYesNo(menu, "create " + item->getInputName() + DOT_CPP, MenuField::Path))
			return (false);

		if (!createFile(item->getInput()))
		{
			item->setColor(RED);
			return (false);
		}
		addToMakefile(item, menu);
		item->setColor(GREEN);
		item->increaseTimeUsed(1);
		return (false);
	}
	return (false);
}