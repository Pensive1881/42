#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
    std::cout << "Flat constructor called" << std::endl;
    this->_value = roundf(value * (1 << _frationalBits));
}

Fixed:Fixed(const flat value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFlat(void) const
{
    return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int FIxed::toInt(void) const
{
    return (this->_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}