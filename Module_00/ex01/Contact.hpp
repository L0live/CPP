#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void	PutStringIndex(std::string str);
		int		StringLenght(const std::string str);
	public:
		void	NewContact(std::string new_contact[5]);
		void	PrintIndex();
		void	PrintContact();
};

#endif