#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	entry;
	PhoneBook	phone_book;

	while (1)
	{
		std::cout << "\n##############################\n";
		std::cout << "\nMY AWESOME PHONEBOOK\n\n";
		std::cout << "ADD : add new contact\n";
		std::cout << "SEARCH : search contact\n";
		std::cout << "EXIT : exit & delete contacts\n";
		std::cout << "\nType what you want here : ";
		getline(std::cin, entry);
		if (entry == "ADD")
			phone_book.AddContact();
		else if (entry == "SEARCH")
			phone_book.Search();
		else if (entry == "EXIT")
			break ;
		else
			std::cout << "\nInvalid option !\n";
	}
	return (0);
}