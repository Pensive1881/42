#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* source = new MateriaSource();

    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* materia;

    materia = source->createMateria("ice");
    me->equip(materia);

    materia = source->createMateria("cure");
    me->equip(materia);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete source;

    return 0;
}