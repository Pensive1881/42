#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const unsigned int count = 10;
    Animal* animals[count];

    std::cout << "=== Animal array construction ===" << std::endl;

    for (unsigned int i = 0; i < count; ++i)
    {
            if (i < count / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
    }

    std::cout << std::endl;
    std::cout << "=== Animal sounds ===" << std::endl;

    for (unsigned int i = 0; i < count; ++i)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    std::cout << "=== Animal array destruction ===" << std::endl;

    for (unsigned int i = 0; i < count; ++i)
        delete anhimals[i];
    
    std::cout << std::endl;
    std::cout << "=== Dog deep-copy test ===" << std::endl;

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the ball");

    Dog copiedDog(originalDog);

    originalDog.getBrain()->setIdea(0, "Sleep on the sofa");

    std::cout << "Original Dog: "
              << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog: "
              << copiedDog.getBrain()->getIdea(0) << std:endl;

    std::cout << std::endl;
    std::cout << "=== Cat assignment test ===" << std::endl;

    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Climb the curtains");

    Cat assignedCat;
    assignedCat = originalCat;

    originalCat.getBrain()->setIdea(0, "Sit in the box");

    std::cout << "Original Cat: "
              << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat: "
              << assignedCat.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}