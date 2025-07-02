/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:21:17 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:21:18 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("default_clap_name")
{
	name = "default";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDmg = FragTrap::attackDmg;
	std::cout << GREEN << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
: ClapTrap(_name + "_clap_name")
{
	name = _name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDmg = FragTrap::attackDmg;
	std::cout << GREEN << "DiamondTrap " << _name << " constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap " << name << " destructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << BLUE << "DiamondTrap " << name << " copy constructor called" << RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << BLUE << "DiamondTrap " << name << " copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		ClapTrap::operator=(other);
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
