#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure:cure()
    : AMateria("cure")
{
}

Cure::cure(const Cure& other)
    : Amateria(other)
{
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        AMateria::operator=(other);

    return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals"
              << target.getName()
              << ""'s wounds *" << std::endl;
}