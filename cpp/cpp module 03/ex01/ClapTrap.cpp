/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:20:03 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:20:03 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name("default"), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
: name(_name), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << GREEN << "ClapTrap " << _name << " constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap " << name << " destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDmg(other.attackDmg)
{
	std::cout << BLUE << "ClapTrap " << name << " copy constructor called" << RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << BLUE << "ClapTrap " << name << " copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDmg = other.attackDmg;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is no longer able to continue the battle! Aborting attack." << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no more energy points left! Aborting attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!" << std::endl;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	dmgTaken;

	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is no longer able to continue the battle! Can't take anymore damage." << std::endl;
		return ;
	}

	if (hitPoints > static_cast<int>(amount))
	{
		dmgTaken = amount;
		hitPoints -= amount;
	}
	else
	{
		dmgTaken = hitPoints;
		hitPoints = 0;
	}

	std::cout << "ClapTrap " << name << " takes " << dmgTaken << " damage point(s) and has " << hitPoints << " hit points left." << std::endl;
	
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is no longer able to continue the battle!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is no longer able to continue the battle! Can't do anything including healing." << std::endl;
		return ;
	}
	if (energyPoints < static_cast<int>(amount))
	{
		std::cout << "ClapTrap " << name << " has not enough energy point to heal " << amount << " hit point! Aborting heal." << std::endl;
		return ;
	}

	energyPoints -= amount;
	hitPoints += amount;

	std::cout << "ClapTrap " << name << " has healed " << amount << " hit point(s) and now has " << hitPoints << " hit points!" << std::endl;
}

int		ClapTrap::getHitPoints()
{
	return (hitPoints);
}

int		ClapTrap::getEnergyPoints()
{
	return (energyPoints);
}
