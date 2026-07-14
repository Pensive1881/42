#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "Default ScavTrap";
    _energyPoints = 100;
    _attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap " << _name
              << " constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap copy assignment called" << std::endl;

    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap" << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap" << _name
              << " is now in Gate Keeper mode"
              << std::endl;
}
