#include <iostream>

int main(int ac, char **av)
{
    std::string megaphone;
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < ac; i++)
        megaphone += av[i];
    for (std::string::iterator i = megaphone.begin(); i != megaphone.end(); i++)
        std::cout << (char)std::toupper(*i);
    std::cout << std::endl;
    return 0;
}
