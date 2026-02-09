#include "../cppMaker.main.hpp"

bool checkFile(std::string &filepath)
{
	if (std::filesystem::exists(filepath))
		return (false);
	return (true);
}

bool addToMakefile(MenuItem *item, MenuList *menu)
{
    if (!handleInputYesNo(menu, "Add .cpp to Makefile", MenuField::Name))
        return (false);

    std::string path = "Makefile";
    if (!checkFile(path)) 
    {
        item->setColor(RED);
        return (false);
    }
    std::ifstream in("Makefile");
    std::ofstream out("Makefile");
    std::string fileName = BASIC_PATH_CPP + item->getInput().getFileName();

    std::string line;
    const std::string pattern = "SRC = ";

    while (std::getline(in, line))
    {
        std::size_t pos = line.find(pattern);
        if (pos != std::string::npos) {
            // insert right after the pattern
            line.insert(pos + pattern.length(), fileName);
        }
    }
    return (true);
}
