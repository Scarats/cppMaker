#include "../cppMaker.main.hpp"

bool checkFile(const std::string &filepath)
{
	if (std::filesystem::exists(filepath))
		return (false);
	return (true);
}

bool addToMakefile(MenuItem *item, MenuList *menu)
{
    menu->changeItem(*item, 0);

    // DISPLAY THE MENU
	MenuList buffList("tmp");
	buffList.addItemBasic(item->getInputName());
    if (!handleInputYesNo(&buffList, "add " + item->getInputName() + " to Makefile", MenuField::Name))
        return (false);

    // BUILD THE CURR PATH FOR THE MAKEFILE
    std::string const currPath = pwd();
    if (currPath.empty())
        return (false);
    std::string const path = currPath + "/Makefile";
    if (checkFile(path))
    {
        item->setColor(RED);
        return (false);
    }

    // CREATE THE FILE STREAMS
    std::ifstream in(path);
    std::ofstream out(currPath + "/Makefile.tmp");

    if (!in || !out)
        return (false);

    // BUILD THE FILENAME WITH THE RELATIVE PATH FOR THE MAKEFILE
    std::string fileName = BASIC_PATH_CPP;
    if (!fileName.empty() && fileName.front() == '/')
        fileName.erase(0, 1);
    fileName.append("/" + item->getInput().getFileName() + " ");
    

    // FIND AND ADD THE FILE TO THE MAKEFILE
    const std::string pattern = "SRCS = ";
    std::string line;
    bool inserted = false;

    while (std::getline(in, line))
    {
        std::size_t pos = line.find(pattern);
        if (pos != std::string::npos && !inserted)
        {
            line.insert(pos + pattern.length(), fileName);
            inserted = true;
        }
        out << line << '\n';
    }

    in.close();
    out.close();

    std::remove("Makefile");
    std::rename("Makefile.tmp", "Makefile");

    return (true);
}
