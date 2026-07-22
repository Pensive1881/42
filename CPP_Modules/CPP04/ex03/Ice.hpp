#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

clas Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual ~Ice();

        virtual AMaterial* close() const;
        virtual void use(ICharacter& trarget);
};

#endif