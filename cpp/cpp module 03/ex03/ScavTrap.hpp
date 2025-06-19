#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string _name);
		virtual ~ScavTrap();

		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap &other);

		// override from the base class
		void	attack(const std::string& target);
		void	guardGate();

	private:

};

#endif