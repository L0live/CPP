// find and replace all recurence of a string to an other in a file to a new file (with the same name + ".replace") in c++98

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " filename stringToReplace stringToReplaceWith" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string stringToReplace(argv[2]);
    std::string stringToReplaceWith(argv[3]);
    std::string newFilename = filename + ".replace";
    std::ofstream newFile(newFilename.c_str());
    if (!newFile.is_open())
    {
        std::cerr << "Error: could not open file " << newFilename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(stringToReplace, pos)) != std::string::npos)
        {
            line.replace(pos, stringToReplace.length(), stringToReplaceWith);
            pos += stringToReplaceWith.length();
        }
        newFile << line << std::endl;
    }

    file.close();
    newFile.close();

    return 0;
}