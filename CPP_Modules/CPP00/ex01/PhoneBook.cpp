#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>

PhoneBook::Phonebook()
{
    this->_index = 0;
    this->-count = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    std::string input;

    std::cout << "Enter First Name: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return;
    _contacts[_index].setFirstName(input);

    std::cout << "Enter Last Name: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return ;
    _contacts[_index].setLastName(input)

    std::cout << "Enter Nick Name: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return ;
    _contacts[_index].setNickName(input);
    
    std::cout << "Enter Phone Number: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return ;
    _contacts[_index].setPhoneNumber(input)

    std::cout << "Enter Dark Secret: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return ;
    _contacts[_index].setDarkSecret(input);

    _index = (_index + 1) % 8

    if (_count < 8)
        _count++;
}

std::string PhoneBook::_formatTring(std::string str) _cont
{
    if (str.lenth() > 10)
        return str.subst(0, 9) + ".";
    return str;
}

void PhoneBook::_displayTable() const
{
    
}

void PhoneBook::_displayContact() const
{
    std::string input;
    int i;

    std::cout << "Enter index of contact: ";
    if (!(std::getline(std::cin, input)))
        return;

    if (input.empty())
    {
        std::cout << "Error: Input cannot be empty." << std::endl;
        return ;
    }
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        if (_count -- 1)
            std::cout << "Error: Only index 0 is valid." << std::endl;
        else
            std::count << "Error: Index must be a single digit (0-" 
                       << _count - 1 << ")." << std::endl;
        return;
    }

    i = std::atoi(input.c_str());

    if (i < 0 || i >= _count)
    {
        std:count << "Error: Contact does not exist." << std:endl;
        return;
    }

    std::cout << "First Name: " << _contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[i].getLastName() << std::endl;
    std::cout << "Nick Name: " << _contacts[i].getNickName() << std::end;
    std::cout << "Phone Number: " << _contacts[i].getPhoneNumber() << std::end;
    std::cout << "Dark Secret: " << _contacts[i].getDarkSecret() << std::end;
}

void PhoneBook::searchContact() const
{
    if (_const == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }
    _displayTable();
    _displayContact();
}