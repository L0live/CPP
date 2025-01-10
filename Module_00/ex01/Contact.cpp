#include "Contact.hpp"

void	Contact::NewContact(std::string new_contact[5])
{
	first_name = new_contact[0];
	last_name = new_contact[1];
	nickname = new_contact[2];
	phone_number = new_contact[3];
	darkest_secret = new_contact[4];
}

void	Contact::PrintIndex()
{
	PutStringIndex(first_name);
	std::cout << '|';
	PutStringIndex(last_name);
	std::cout << '|';
	PutStringIndex(nickname);
	std::cout << '\n';
}

void	Contact::PutStringIndex(std::string str)
{
	if (StringLenght(str) > 10)
	{
		for (size_t i = 0; i < 9; i++)
		{
			std::cout << str[i];
		}
		std::cout << '.';
		return ;
	}
	for (size_t i = (10 - StringLenght(str)); i > 0; i--)
	{
		std::cout << ' ';
	}
	for (size_t i = 0; str[i]; i++)
	{
		std::cout << str[i];
	}
}

int	Contact::StringLenght(const std::string str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (!str[i + 1])
			return (i + 1);
	}
	return (0);
}

void	Contact::PrintContact()
{
	std::cout << "First Name : " << first_name << '\n';
	std::cout << "Last Name : " << last_name << '\n';
	std::cout << "Nickname : " << nickname << '\n';
	std::cout << "Phone Number : " << phone_number << '\n';
	std::cout << "Darkest Secret : " << darkest_secret << '\n';
}
