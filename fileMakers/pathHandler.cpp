#include "../cppMaker.main.hpp"

// returns path on success, empty string on failure.
std::string pwd(void)
{
	char path[PATH_MAX];

	if (getcwd(path, sizeof(path)) != NULL)
		return (path);
	return (std::string(""));
}

// Return values:
// 1 = path exists
// 0 = path doesn't exist
// -1 = error
int checkPath(std::string &path)
{
	struct stat info;

	if (stat(path.c_str(), &info) == 0)
		return (1);

	else if (errno == ENOENT || errno == ENOTDIR)
		return (0);

	return (-1);
}

// // It should print a Menu with just the path.
// int setNewPath(std::string &currPath)
// {
// 	static MenuList list;
// 	if (list.getSize() < 2)
// 		list.addItem()
// 			list.resetMenu();
// }