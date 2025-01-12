# include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin >> std::ws, input))
		    return (EXIT_FAILURE);
        std::cout << std::endl;
        if (input == "ADD") {
            if (phoneBook.addContact() == EXIT_FAILURE)
                break ;
        }
        else if (input == "SEARCH") {
            if (phoneBook.searchContact() == EXIT_FAILURE)
                break ;
        }
        else if (input == "EXIT")
            break ;
        std::cout << std::endl;
    }
    return 0;
}