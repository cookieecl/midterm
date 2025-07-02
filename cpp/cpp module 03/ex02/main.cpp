/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:20:24 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:20:24 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	std::cout << std::endl << MAGENTA << "[1]Test default constructor" << RESET << std::endl;
	FragTrap	defaultFragTrap;
	defaultFragTrap.attack("boss");

	std::cout << std::endl << MAGENTA << "[2]Test copy constructor" << RESET << std::endl;
	FragTrap	copy(defaultFragTrap);
	copy.attack("boss");
	std::cout << "Copy should have 98 energy points, result: " << copy.getEnergyPoints() << std::endl;
	if (copy.getEnergyPoints() != 98)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[3]Test copy assignment (default = copy)" << RESET << std::endl;
	defaultFragTrap = copy;
	defaultFragTrap.attack("boss");
	std::cout << "Default should have 97 energy points, result: " << defaultFragTrap.getEnergyPoints() << std::endl;
	if (defaultFragTrap.getEnergyPoints() != 97)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[4]Test constructor with parameter" << RESET << std::endl;
	FragTrap	fragTrap("x");

	std::cout << std::endl << MAGENTA << "[5]Test functions:" << RESET << std::endl;
	std::cout << MAGENTA << "Test the ability to attack, take damage, and heal (will pass)" << RESET << std::endl;
	fragTrap.attack("target 1");
	fragTrap.takeDamage(2);
	fragTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Drain energy for next test case" << RESET << std::endl;
	while (fragTrap.getEnergyPoints() != 0)
		fragTrap.attack("minions");
	
	std::cout << std::endl << MAGENTA << "After the energy is 0, test whether it is still able to heal and attack" << RESET << std::endl;
	fragTrap.beRepaired(1);
	fragTrap.attack("target 3");

	std::cout << std::endl << MAGENTA << "Drain the hit point to 0 while also checking for the hit point to not be able to go below 0" << RESET << std::endl;
	while (fragTrap.getHitPoints() != 0)
		fragTrap.takeDamage(2);
	
	std::cout << std::endl << MAGENTA << "Try to attack, take damage, and heal with 0 health" << RESET << std::endl;
	fragTrap.attack("target 3");
	fragTrap.takeDamage(1);
	fragTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Test special attack of FragTrap (highFivesGuys)" << RESET << std::endl;
	fragTrap.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
