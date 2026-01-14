#include "../cppMaker.main.hpp"

std::string toLower(std::string s)
{
	for (std::string::size_type i = 0; i < s.size(); ++i)
		s[i] = std::tolower(s[i]);
	return s;
}

std::string toUpper(std::string s)
{
	for (std::string::size_type i = 0; i < s.size(); ++i)
		s[i] = std::toupper(s[i]);
	return s;
}

std::string firstUp(std::string s)
{
	if (!s.empty())
		s[0] = std::toupper(s[0]);
	return s;
}

void replacePattern(std::string &str, const std::string &input, const std::string &pattern)
{
	std::size_t found = str.size();
	while ((found = str.rfind(pattern.c_str(), found, pattern.size())) != std::string::npos)
	{
		str.replace(found, pattern.size(), input);
		found -= pattern.size();
	}
}

void findAndReplace(std::string &str, UserInput &input)
{
	replacePattern(str, toLower(input.getName()), std::string(LOWERCASE));
	replacePattern(str, firstUp(input.getName()), std::string(FIRSTUPPER));
	replacePattern(str, toUpper(input.getName()), std::string(UPPERCASE));
}