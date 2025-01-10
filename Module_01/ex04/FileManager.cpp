#include "FileManager.hpp"

FileManager::FileManager(char *src_file)
{
	this->file = src_file;
	this->str_file = get_string_from_file();
}

std::string	FileManager::get_string(void)
{
	return this->str_file;
}

std::string	FileManager::get_string_from_file(void)
{
	std::ifstream	fs;
	std::streamsize	len;
	char			*src;
	std::string		dest;

	fs.open(this->file, std::ios_base::in);
	if (!fs.is_open())
	{
		std::cout << "ERROR\nOpen file error !\n";
		std::exit(-1);
	}
	fs.seekg(0, std::ios::end);
	len = fs.tellg();
	fs.seekg(0, std::ios::beg);
	src = new char[len + 1];
	fs.read(src, len);
	src[len] = '\0';
	fs.close();
	dest = src;
	delete[] src;
	return (dest);
}

void	FileManager::replace(std::string s1, std::string s2)
{
	std::size_t	found;

	found = this->str_file.find(s1);
	while (found != std::string::npos)
	{
		this->str_file.erase(found, s1.length());
		this->str_file.insert(found, s2);
		found = this->str_file.find(s1);
	}
}

std::string	FileManager::output_file()
{
	std::size_t	found;
	std::string	file_name(this->file);

	found = file_name.find(".");
	if (found != std::string::npos)
		file_name.erase(found, std::string::npos);
	file_name += ".replace";
	return (file_name);
}

void	FileManager::write_in_file(std::string str)
{
	std::ofstream	file;
	std::string		file_name = output_file();

	file.open(file_name.c_str(), std::ios_base::trunc | std::ios_base::out);
	file << str;
	file.close();
}

FileManager::~FileManager()
{
}
