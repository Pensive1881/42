#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    : Animal()
{
    
}

Cat::Cat(const Cat& other)
    : Animal(other)
{

}

Cat& Cat::operator=(const Cat& other)
{

}

Cat::~Cat()
{

}

void Cat::makeSound() const
{
    
}