#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Correct polymorphism ===" << std::endl;
    
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Type: " << animal->getType() << std::endl;
    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << "=== Wrong polymorphism ===" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type: " << wrongAnimal->getType() << std::endl;
    std::cout << "Type: " << wrongCat->getType() << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << std::endl;
    std::cout << "=== Direct WrongCat call ===" << std::endl;

    WrongCat directWrongCat;
    directWrongCat.makeSound();

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}