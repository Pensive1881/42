#include "ClapTrap.hpp"
#include "ScabTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ClapTrap test ===" << std::endl;

    ClapTrap clap("Clappy");

    clap.attack("Target");
    clap.takeDamage(4);
    clap.beRepaired(2);

    std::cout << std::endl;
    std::cout << "=== ScavTrap test ===" << std::endl;

    ScavTrap scav("Scavvy");

    robot.attack("Enemy");
    robot.takeDamage(30);
    robot.beRepaired(10);
    robot.guardGate());

    std::cout << std:endl;
    std::cout << "=== Destruction ===" << std::endl;

    return 0;
}