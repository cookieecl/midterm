#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string _name);
		virtual ~FragTrap();

		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap &other);

		void	highFivesGuys(void);

	private:


};

#endif