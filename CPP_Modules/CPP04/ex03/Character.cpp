#include "Character.hpp"

Character::Character(const std::string& name)
    : name(name)
{

}

Character::Character(const Character& other)
    :name(other.name)
{

}

Character& Character::operator=(const Character& other)
{

}

Character::~Character()
{

}

const std::string& Character::getName() const
{

}

void Character::equip(AMateria* materia)
{

}

void Character::unequip(int index)
{

}

void Character::use(int index, ICharacter& target)
{
    
}