#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(std::string str)
{
    _firstName = str;
}

void Contact::setLastName(std::string str)
{
    _lastName = str;
}

void Contact::setNickName(std::string str)
{
    _nickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
    _phoneNumber = str;
}

void Contact::setDarkSecret(std::string str)
{
    _darkSecret = str;
}

std::string Contact::getFirstName(void) const
{
    return _firstName;
}

std::string Contact::getLastName(void) const
{
    return _lastName;
}

std::string Contact::getNickName(void) const
{
    return _nickName;
}

std::string Contact::getPhoneNumber(void) const
{
    return _phoneNumber;
}

std::string Contact::getDarkSecret(void) const
{
    return _darkSecret;
}