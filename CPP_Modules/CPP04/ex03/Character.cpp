#include "Character.hpp"

Character::Character(const std::string& name)
    : name(name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(const Character& other)
    :name(other.name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;

        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = NULL;

            if (other.inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
        }
    }

    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

const std::string& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* materia)
{
    if (materia == NULL)
        return;
    
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = materia;
            return;
        }
    }
}

void Character::unequip(int index)
{
    if (index < 0 || index >= 4)
        return;

    inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target)
{
    if (index < 0 || index >= 4)
        return;

    if (inventory[index] != NULL)
        inventory[index]->use(target);
}