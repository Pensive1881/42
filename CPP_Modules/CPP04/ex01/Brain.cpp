#include "Brain.hpp"
#include <iostream>

Brain:Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;

    for (unsigned int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(conwst Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;

    if (thisw != &other)
    {
        for (unsigned int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }

    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(unsigned int index, const std::string& idea)
{
    if (index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index) const
{
    if (index < 100)
        return ideas[index];

    return "";
}