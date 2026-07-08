#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
//    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
//    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
//    std::cout << "Int constructor called" << std::endl;
    this->_value = value * (1 << _fractionalBits);
}

Fixed::Fixed(const float value)
{
//    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
//    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
//    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
//    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

// comparison operators
bool Fixed::operator>(const Fixed& other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_value != other._value);
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() *  other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

// increment/decrement operator overloads
Fixed& Fixed::operator++()
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return (temp);
}

// min/max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}
