#ifndef FILEMANAGER_HPP
# define FILEMANAGER_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>

class FileManager
{
	private:
		char		*file;
		std::string str_file;
		std::string	get_string_from_file();
	public:
		FileManager(char *file);
		std::string	get_string();
		void	replace(std::string s1, std::string s2);
		std::string	output_file();
		void	write_in_file(std::string str);
		~FileManager();
};

#endif
