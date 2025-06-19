#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDmg = 30;
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
: ClapTrap(_name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDmg = 30;
	std::cout << GREEN << "ScavTrap " << _name << " constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap " << name << " destructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{
	std::cout << BLUE << "ScavTrap " << name << " copy constructor called" << RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << BLUE << "ScavTrap " << name << " copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is no longer able to continue the battle! Aborting attack." << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " has no more energy points left! Aborting attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!" << std::endl;
	energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate keeper mode" << std::endl;
}
