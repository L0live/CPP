#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	MyPhoneBook[8];
		size_t	size;
		void	PutIndex();
	public:
		PhoneBook();
		void	AddContact();
		void	Search();
};

#endif