#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other), brain(new Brain(*other.brain))
{
    type = "Cat";
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;

    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }

    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain()
{
    return brain;
}

const Brain* Cat::getBrain() const
{
    return brain;
}