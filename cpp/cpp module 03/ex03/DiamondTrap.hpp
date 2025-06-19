#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		virtual ~DiamondTrap();

		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap &other);

		void	attack(const std::string& target);
		void	whoAmI();

	private:
		std::string	name;

};

#endif