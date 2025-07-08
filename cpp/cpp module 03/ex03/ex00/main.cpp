/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:20:00 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 13:45:09 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	std::cout << std::endl << MAGENTA << "[1]Test default constructor" << RESET << std::endl;
	ClapTrap	defaultClapTrap;
	
	std::cout << "Should have 10 hitpoints, result: " << defaultClapTrap.getHitPoints() << std::endl;
	if (defaultClapTrap.getHitPoints() != 10)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	}

	std::cout << "Should have 10 energypoints, result: " << defaultClapTrap.getEnergyPoints() << std::endl;
	if (defaultClapTrap.getEnergyPoints() != 10)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	}

	std::cout << "Should have 0 attackdamage, result: " << defaultClapTrap.getAttackDamage() << std::endl;
	if (defaultClapTrap.getAttackDamage() != 0)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	}

	defaultClapTrap.attack("boss");
	std::cout << std::endl << MAGENTA << "[2]Test copy constructor" << RESET << std::endl;
	ClapTrap	copy(defaultClapTrap);
	copy.attack("boss");
	std::cout << "Copy should have 8 energy points, result: " << copy.getEnergyPoints() << std::endl;
	if (copy.getEnergyPoints() != 8)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[3]Test copy assignment (default = copy)" << RESET << std::endl;
	defaultClapTrap = copy;
	defaultClapTrap.attack("boss");
	std::cout << "Default should have 7 energy points, result: " << defaultClapTrap.getEnergyPoints() << std::endl;
	if (defaultClapTrap.getEnergyPoints() != 7)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[4]Test constructor with parameter" << RESET << std::endl;
	ClapTrap	clapTrap("x");

	std::cout << std::endl << MAGENTA << "[5]Test functions:" << RESET << std::endl;
	std::cout << MAGENTA << "Test the ability to attack, take damage, and heal (will pass)" << RESET << std::endl;
	clapTrap.attack("target 1");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Drain energy for next test case" << RESET << std::endl;
	while (clapTrap.getEnergyPoints() != 0)
		clapTrap.attack("minions");
	
	std::cout << std::endl << MAGENTA << "After the energy is 0, test whether it is still able to heal and attack" << RESET << std::endl;
	clapTrap.beRepaired(1);
	clapTrap.attack("target 3");

	std::cout << std::endl << MAGENTA << "Drain the hit point to 0 while also checking for the hit point to not be able to go below 0" << RESET << std::endl;
	while (clapTrap.getHitPoints() != 0)
		clapTrap.takeDamage(2);
	
	std::cout << std::endl << MAGENTA << "Try to attack, take damage, and heal with 0 health" << RESET << std::endl;
	clapTrap.attack("target 3");
	clapTrap.takeDamage(1);
	clapTrap.beRepaired(1);

	std::cout << std::endl;

	return (0);
}
