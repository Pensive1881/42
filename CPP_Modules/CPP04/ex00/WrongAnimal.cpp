#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{

}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type(other.type)
{

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{

}

WrongAnimal::~WrongAnimal()
{

}

std::string WrongAnimal::getType() const
{

}

void WrongAnimal::makeSound() const
{
    
}