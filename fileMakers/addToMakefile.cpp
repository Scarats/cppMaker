#include "../cppMaker.main.hpp"

bool checkFile(const std::string &filepath)
{
	if (std::filesystem::exists(filepath))
		return (false);
	return (true);
}

bool addToMakefile(MenuItem *item, MenuList *menu)
{
    if (!handleInputYesNo(menu, "Add .cpp to Makefile", MenuField::Name))
        return false;

    std::string const path = "Makefile";
    if (!checkFile(path))
    {
        item->setColor(RED);
        return false;
    }

    std::ifstream in(path);
    std::ofstream out("Makefile.tmp");

    if (!in || !out)
        return false;

    std::string fileName = BASIC_PATH_CPP + item->getInput().getFileName() + " ";
    const std::string pattern = "SRC = ";

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

    return true;
}
