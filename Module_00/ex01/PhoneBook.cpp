#include "PhoneBook.hpp"

void	PhoneBook::Search()
{
	std::string	index;

	if (size == 0)
	{
		std::cout << "PhoneBook is empty !\n";
		return ;
	}
	PutIndex();
	while (1)
	{
		std::cout << "Search index : ";
		getline(std::cin, index);
		std::cout << '\n';
		if (index[1] == '\0' && index[0] >= '1'
			&& index[0] <= (48 + (int)size))
		{
			MyPhoneBook[(index[0] - 48) - 1].PrintContact();
			break ;
		}
		else
			std::cout << "Invalid index/contact !\n";
	}
}

void	PhoneBook::PutIndex()
{
	std::cout << "\ni |First Name| Last Name| Nickname\n";
	std::cout << "-----------------------------------\n";
	for (size_t i = 1; i <= size; i++)
	{
		std::cout << i << " |";
		MyPhoneBook[i - 1].PrintIndex();
		std::cout << '\n';
	}
}

PhoneBook::PhoneBook()
{
	size = 0;
}

void	PhoneBook::AddContact()
{
	static int	i = 0;
	std::string	contact[5];

	std::cout << "\n\nFirst Name : ";
	getline(std::cin, contact[0]);
	std::cout << "\nLast Name : ";
	getline(std::cin, contact[1]);
	std::cout << "\nNickname : ";
	getline(std::cin, contact[2]);
	std::cout << "\nPhone Number : ";
	getline(std::cin, contact[3]);
	std::cout << "\nDarkest Secret : ";
	getline(std::cin, contact[4]);
	MyPhoneBook[i].NewContact(contact);
	++i;
	if (i == 8)
		i = 0;
	if (size < 8)
		size += 1;
	std::cout << "\ncontact successfully added !\n";
}
