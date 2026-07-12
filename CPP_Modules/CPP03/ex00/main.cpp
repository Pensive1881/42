#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("Clappy");

    robot.attack("Target");
    robot.takeDamage(4);
    robot.beRepaired(2);
    robot.takeDamage(20);

    robot.attack("Another target");
    robot.beRepaired(5);

    return 0;
}