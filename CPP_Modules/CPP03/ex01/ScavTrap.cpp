#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "Default ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
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
    std::cout << "ScavTrap copy assignment operator called" << std::endl;

    if (this != &other)
        ClapTrap::operator=(other)
    
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name
              << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name
                  << " cannot attack because it has no hit points"
                  << std::endl;
        return;
    }

    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name
                  << " cannot attack because it has no energy"
                  << std::endl;
        return;
    }

    --_energyPoints;

    std::cout << "ScavTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name
              << " is now in Gate Keeper mode"
              << std::endl;
}
