#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_count = 0;
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
        return;
    _contacts[_index].setLastName(input);

    std::cout << "Enter Nickname: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return;
    _contacts[_index].setNickname(input);

    std::cout << "Enter Phone Number: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return;
    _contacts[_index].setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return;
    _contacts[_index].setDarkestSecret(input);

    _index = (_index + 1) % 8;

    if (_count < 8)
        _count++;
}

std::string PhoneBook::_formatString(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::_displayTable() const
{
    std::cout << std::string(45, '_') << std::endl;
    std::cout << "|" << std::setw(10) << "index";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname"
              << "|" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    int i = 0;
    while (i < _count)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10)
                  << _formatString(_contacts[i].getFirstName());
        std::cout << "|" << std::setw(10)
                  << _formatString(_contacts[i].getLastName());
        std::cout << "|" << std::setw(10)
                  << _formatString(_contacts[i].getNickname());
        std::cout << "|" << std::endl;
        i++;
    }
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
        return;
    }
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        if (_count == 1)
            std::cout << "Error: Only index 0 is valid." << std::endl;
        else
            std::cout << "Error: Index must be a single digit (0-"
                      << _count - 1 << ")." << std::endl;
        return;
    }

    i = std::atoi(input.c_str());

    if (i < 0 || i >= _count)
    {
        std::cout << "Error: Contact does not exist." << std::endl;
        return;
    }

    std::cout << "First Name: " << _contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[i].getPhoneNumber()
              << std::endl;
    std::cout << "Darkest Secret: " << _contacts[i].getDarkestSecret()
              << std::endl;
}

void PhoneBook::searchContact() const
{
    if (_count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    _displayTable();
    _displayContact();
}
