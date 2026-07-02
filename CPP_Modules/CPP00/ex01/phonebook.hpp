#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
    private:
        Contact _contacts [8];
        int _index;
        int _count;

        std::string _formatString(std::string str) const;
        void _displayTable() const;
        void _displayContact() const;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
};

#endif