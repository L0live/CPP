#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

PhoneBook::~PhoneBook() {}

static bool isNumber(std::string str) {
	for (std::string::iterator i = str.begin(); i != str.end(); i++) {
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

static bool isSearchIndex(std::string str) {
	if (str.length() == 1 && str[0] >= '1' && str[0] <= '8')
		return true;
	return false;
}

static std::string	getField(std::string field, bool (*f)(std::string)) {
	std::string	input;

	std::cout << field << ": ";
	if (!std::getline(std::cin, input))
		return "";
	while (input.empty() || (f && !f(input))) {
		std::cout << "Please enter a valid " << field << ": ";
		if (!std::getline(std::cin, input))
			return "";
	}
	return input;
}

int PhoneBook::addContact() {
	std::string	input;

    if (this->index == 8)
		this->index = 0;
	std::cout << "Adding contact " << this->index + 1 << std::endl;
	input = getField("First name", NULL);
	if (input.empty())
		return (EXIT_FAILURE);
    this->contacts[this->index].setFirstName(input);
	input = getField("Last name", NULL);
	if (input.empty())
		return (EXIT_FAILURE);
    this->contacts[this->index].setLastName(input);
	input = getField("Nickname", NULL);
	if (input.empty())
		return (EXIT_FAILURE);
    this->contacts[this->index].setNickname(input);
	input = getField("Phone number (0-9)", isNumber);
	if (input.empty())
		return (EXIT_FAILURE);
    this->contacts[this->index].setPhoneNumber(input);
	input = getField("Darkest secret", NULL);
	if (input.empty())
		return (EXIT_FAILURE);
    this->contacts[this->index].setDarkestSecret(input);
    this->index++;
	return (EXIT_SUCCESS);
}

static std::string searchLineCleaner(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	}
	str.resize(10, ' ');
	return str;
}

int PhoneBook::searchContact() const {
	std::string input;

	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << "No contacts available" << std::endl;
		return (EXIT_SUCCESS);
	}
	std::cout << "index     |first name|last name |nickname" << std::endl;
	for (int i = 0; i < 8 && !this->contacts[i].getFirstName().empty(); i++)
	{
		std::cout << i + 1 << std::string(9, ' ') << "|";
		std::cout << searchLineCleaner(this->contacts[i].getFirstName()) << "|";
		std::cout << searchLineCleaner(this->contacts[i].getLastName()) << "|";
		std::cout << searchLineCleaner(this->contacts[i].getNickname()) << std::endl;
	}
	input = getField("Index (1-8)", isSearchIndex);
	if (input.empty())
		return (EXIT_FAILURE);
	if (!this->contacts[input[0] - '1'].getFirstName().empty())
	{
		int	i = input[0] - '1';
		std::cout << "\nFirst name: " << this->contacts[i].getFirstName() << std::endl;
		std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
		std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "This contact doesn't exist" << std::endl;
	return (EXIT_SUCCESS);
}
