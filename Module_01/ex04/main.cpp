#include "FileManager.hpp"

int	main(int ac, char **av)
{
	FileManager	fm(av[1]);

	if (ac != 4)
		return -1;
	std::cout << "\n########## REPLACE ##########\n";
	std::cout << "\nFile name : " << av[1];
	std::cout << "\nString to replace : " << av[2];
	std::cout << "\nString to replace by : " << av[3];
	std::cout << "\nOutput file name : " << fm.output_file();
	fm.replace(av[2], av[3]);
	std::cout << "\n\nReplacement of strings : ✅ (done)\n";
	fm.write_in_file(fm.get_string());
	std::cout << "New file creation and write strings into : ✅ (done)\n";
	return 0;
}
