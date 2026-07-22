#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
    : AMaterial("ice")
{
}

Ice::Ice(const Ice& other)
    : AMateria(other)
{
}

Ice& Ice:: operator=(Const Ice& other)
{

}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{

}

void Ice::use(ICharacter& target)
{

}