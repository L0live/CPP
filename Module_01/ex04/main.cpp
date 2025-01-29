#include <iostream>
#include <fstream>

void	replace(std::ifstream &file, std::ofstream &newFile, std::string s1, std::string s2) {

	if (s1 == s2) {
		newFile << file.rdbuf();
		return ;
	}
	
	std::string line;

	while (std::getline(file, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			// line.replace(pos, stringToReplace.length(), stringToReplaceWith);
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}

		newFile << line << std::endl;
	}
}

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " filename stringToReplace stringToReplaceWith" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}

	std::string newFilename = std::string(argv[1]) + ".replace";

	std::ofstream newFile(newFilename.c_str());
	if (!newFile.is_open()) {
		std::cout << "Error: could not open file " << newFilename << std::endl;
		return 1;
	}

	replace(file, newFile, argv[2], argv[3]);

	file.close();
	newFile.close();

	return 0;
}