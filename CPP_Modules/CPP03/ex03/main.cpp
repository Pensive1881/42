#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== DiamondTrap test ===" << std::endl;

    DiamondTrap diamond("Shiny");

    diamond.whoAmI();
    diamond.attack("Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(10);
    diamond.guardGat();
    diamond.highFivesGuys();

    std::cout << std::endl;
    std::cout << "=== Copy test ===" << std::endl;

    DiamondTrap copy(Diamond);

    copy.whoAmI();
    copy.attack("Another enemy");

    std::cout << std::endl;
    std::cout << "=== Destruction ===" << std::endl;

    return 0;
}