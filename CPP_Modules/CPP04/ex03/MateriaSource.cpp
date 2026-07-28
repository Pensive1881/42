#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.templates[i] != NULL)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete templates[i];
            templates[i] = NULL;

            if (other.templates[i] != NULL)
                templates[i] = other.templates[i]->clone();            }
        }

        return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (materia == NULL)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] == NULL)
        {
            templates[i] = materia;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] != NULL && templates[i]->getType() == type)
            return templates[i]->clone();
    }

    return NULL;
}