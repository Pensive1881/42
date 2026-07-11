#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap)
    : _name("Default"), _hitpoints(10),
      _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10),
      _energyPoint(10), _attackDamage(0)
{

}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage)
{

}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{

}

ClapTrap::~ClapTrap()
{

}

void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::taakeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}
