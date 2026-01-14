#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include <string>
#include <cctype>

#define UPPERCASE "TEMPLATE"
#define FIRSTUPPER "Template"
#define LOWERCASE "template"

typedef enum s_type
{
	NONE,
	tMAKEFILE,
	tMAIN_CPP,
	tMAIN_HPP,
	tCLASS_CPP,
	tCLASS_HPP,
	tCPP
} e_type;

class UserInput
{
public:
	UserInput() {}
	UserInput(const e_type &type, const std::string &name, const std::string &path);

	void setName(const std::string &name);
	std::string &getName(void);

	void setPath(const std::string &name);
	std::string &getPath(void);

	void setType(const e_type &type);
	const e_type &getType(void);

	void resetVariables(void);

	void setFileName(const std::string &name);
	std::string &getFileName();

private:
	e_type _type;
	std::string _name;
	std::string _path;
	std::string _fileName;
	bool addToMakefile = false;
};

#endif