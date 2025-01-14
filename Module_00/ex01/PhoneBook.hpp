#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
    
public:

    PhoneBook();
    ~PhoneBook();

    int addContact();
    int searchContact() const;

private:

    Contact contacts[8];
    int index;

};

#endif