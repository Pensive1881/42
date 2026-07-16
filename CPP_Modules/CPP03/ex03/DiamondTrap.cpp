#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name("Default")
{
    ClapTrap::_name = "";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;

    std::cout << "DiamondTrap default onstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name  ""),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrao(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    std::cout << "" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    
}

DiamondTrap::~DiamondTrap()
{

}

void DiamondTrap::whoAmI()
{

}