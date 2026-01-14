#include "../cppMaker.main.hpp"

bool createNewFile(UserInput &input, std::string &content)
{
	std::string filepath = input.getPath() + input.getFileName();
	if (std::filesystem::exists(filepath))
		return (false);

	std::ofstream outfile(filepath);
	if (!outfile)
		return (false);
	outfile << content;
	return (true);
}

// Returns the file content if file opens correctly.
std::string getTemplate(const std::string &path)
{
	std::ifstream infile(path);
	if (!infile)
	{
		std::cerr << "error at opening " << path << std::endl;
		throw std::exception();
	}
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	return (buffer.str());
}

void createPath(UserInput &input)
{
	std::filesystem::path path;

	path = input.getPath().append("/");
	try
	{
		std::filesystem::create_directories(path.parent_path());
	}
	catch (const std::filesystem::filesystem_error &ex)
	{
		std::cerr << "error at creating directory at " << path << std::endl;
		throw std::exception();
	}
}

void buildFileName(UserInput &input)
{
	switch (input.getType())
	{
	case tMAKEFILE:
		input.setFileName(input.getName());
		break;
	case tMAIN_HPP:
	case tMAIN_CPP:
		if (input.getFileName().find(DOT_HPP) != std::string::npos)
			input.setFileName(input.getName() + DOT_CPP);
		else
			input.setFileName(input.getName() + DOT_HPP);
		break;
	case tCLASS_CPP:
	case tCLASS_HPP:
		if (input.getFileName().find(DOT_CLASS_HPP) != std::string::npos)
			input.setFileName(input.getName() + DOT_CLASS_CPP);
		else
			input.setFileName(input.getName() + DOT_CLASS_HPP);
		break;
	case tCPP:
		input.setFileName(input.getName() + DOT_CPP);
		break;
	case NONE:
		std::cerr << "error at building filename, no type for" << input.getName() << std::endl;
		throw std::exception();
		break;
	}
}

bool createFile(UserInput &input)
{
	std::string buff;

	switch (input.getType())
	{
	case tMAKEFILE:
		buff = getTemplate(MAKEFILE_PATH);
		if (buff.empty())
			return (false);
		break;
	case tMAIN_HPP:
		buff = getTemplate(MAIN_HPP_PATH);
		if (buff.empty())
			return (false);
		break;
	case tMAIN_CPP:
		buff = getTemplate(MAIN_CPP_PATH);
		if (buff.empty())
			return (false);
		break;
	case tCLASS_HPP:
		buff = getTemplate(CLASS_HPP_PATH);
		if (buff.empty())
			return (false);
		break;
	case tCLASS_CPP:
		buff = getTemplate(CLASS_CPP_PATH);
		if (buff.empty())
			return (false);
		break;
	case tCPP:
		break;
	case NONE:
		return (false);
	}
	createPath(input);
	findAndReplace(buff, input);
	buildFileName(input);
	return (createNewFile(input, buff));
}