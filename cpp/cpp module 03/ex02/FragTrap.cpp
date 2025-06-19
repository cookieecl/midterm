#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDmg = 30;
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string _name)
: ClapTrap(_name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDmg = 30;
	std::cout << GREEN << "FragTrap " << _name << " constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap " << name << " destructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{
	std::cout << BLUE << "FragTrap " << name << " copy constructor called" << RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	std::cout << BLUE << "FragTrap " << name << " copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " got a high fiveeee!" << std::endl;
}
