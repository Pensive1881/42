#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriasource
{
    public:
        virtual ~IMateriaSrouce() {}

        virtual void learnMateria(!Materia* materia) = 0;
        virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif