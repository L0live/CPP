#include <iostream>
#include <fstream>

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

    std::string filename(argv[1]);
    std::string stringToReplace(argv[2]);
    std::string stringToReplaceWith(argv[3]);
    std::string newFilename = filename + ".replace";

    std::ofstream newFile(newFilename.c_str());
    if (!newFile.is_open()) {
        std::cout << "Error: could not open file " << newFilename << std::endl;
        return 1;
    }

    if (stringToReplace == stringToReplaceWith) {
        newFile << file.rdbuf();
        file.close();
        newFile.close();
        return 0;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(stringToReplace, pos)) != std::string::npos) {
            // line.replace(pos, stringToReplace.length(), stringToReplaceWith);
            line.erase(pos, stringToReplace.length());
		    line.insert(pos, stringToReplaceWith);
            pos += stringToReplaceWith.length();
        }
        newFile << line << std::endl;
    }

    file.close();
    newFile.close();

    return 0;
}