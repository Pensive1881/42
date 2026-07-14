#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << std::endl;
    std::cout << "=== Destruction ===" << std::endl;

    return 0;
}