#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];

    public:
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        virtual const std::string& getName() const;
        virtual void equip(AMateria* materia);
        virtual void unequip(int index);
        virtual void use(int index, ICharacter& target);
};

#endif