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

void PhoneBook_displayTable() const
{
    
}

void PhoneBook::_displayContact() const
{

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