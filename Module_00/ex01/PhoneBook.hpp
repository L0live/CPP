#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        int addContact();
        int searchContact();
};

#endif