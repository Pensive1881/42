#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal()
{

}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{

}

WrongCat& WrongCat::operator=(const WrongCat& other)
{

}

WrongCat::~WrongCat()
{

}

void WrongCat::makeSound() const
{
    
}