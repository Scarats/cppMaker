#include "cppMaker.main.hpp"

volatile std::sig_atomic_t g_interrupted = 0;

void on_sigint(int)
{
	g_interrupted = 1;
}

void setSignals(void)
{
	struct sigaction sa{};
	sa.sa_handler = on_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, nullptr);
}

void createMenus(ListOfMenu &listOfMenus)
{
	// CREATE THE SUBMENUS
	listOfMenus.addMenu("MainMenu");
	listOfMenus.addMenu(MAKEFILE);
	listOfMenus.addMenu(MAIN);
	listOfMenus.addMenu(CLASS);
	listOfMenus.addMenu(CPP);

	// INIT THE SUBMENUS INPUT TYPES
	int i = 0;
	MenuList *main = listOfMenus.getMenu(i);
	main->addItemBasic(MAKEFILE);
	main->getItem(i++)->setInputType(tMAKEFILE);
	main->addItemBasic(MAIN);
	main->getItem(i++)->setInputType(tMAIN_HPP);
	main->addItemBasic(CLASS);
	main->getItem(i++)->setInputType(tCLASS_HPP);
	main->addItemBasic(CPP);
	main->getItem(i++)->setInputType(tCPP);

	// INIT THE MAKEFILE LINKED FUNCTION
	MenuList *makeFile = listOfMenus.getMenu(1);
	makeFile->function = makefileMaker;

	MenuList *ptrMain = listOfMenus.getMenu(2);
	ptrMain->function = mainMaker;

	MenuList *ptrClass = listOfMenus.getMenu(3);
	ptrClass->function = classMaker;

	MenuList *ptrCpp = listOfMenus.getMenu(4);
	ptrCpp->function = dotCppMaker;
}

int main()
{
	setSignals();
	int index = -1;
	ListOfMenu ListOfMenus;
	MenuItem *item;
	MenuList *subMenu;
	MenuList *mainMenu;

	createMenus(ListOfMenus);
	std::cout << "listOfMenus of menu " << ListOfMenus.getSize() << std::endl;
	try
	{
		while (index == -1)
		{
			mainMenu = ListOfMenus.getMenu(0);
			printMenu(*mainMenu, "Exit", MenuField::Name);

			index = handleIndexInput("index", mainMenu->getSize(), getIndex);
			if (index == 0)
				return (0);

			item = mainMenu->getItem(index - 1);
			subMenu = ListOfMenus.getMenu(index);

			if (!item || !subMenu || !mainMenu || !subMenu->function)
			{
				std::cerr << "error main" << std::endl;
				return (1);
			}
			if (subMenu->function(item, subMenu))
				return (12);
			index = -1;
		}
	}
	catch (std::exception)
	{
		return (1);
	}
	return (0);
}