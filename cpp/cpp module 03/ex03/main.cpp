#include "DiamondTrap.hpp"

int	main()
{
	std::cout << std::endl << MAGENTA << "[1]Test default constructor" << RESET << std::endl;
	DiamondTrap	defaultDiamondTrap;
	defaultDiamondTrap.attack("boss");

	std::cout << std::endl << MAGENTA << "[2]Test copy constructor" << RESET << std::endl;
	DiamondTrap	copy(defaultDiamondTrap);
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
	defaultDiamondTrap = copy;
	defaultDiamondTrap.attack("boss");
	std::cout << "Default should have 97 energy points, result: " << defaultDiamondTrap.getEnergyPoints() << std::endl;
	if (defaultDiamondTrap.getEnergyPoints() != 97)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[4]Test constructor with parameter" << RESET << std::endl;
	DiamondTrap	diamondTrap("x");

	std::cout << std::endl << MAGENTA << "[5]Test functions:" << RESET << std::endl;
	std::cout << MAGENTA << "Test the ability to attack, take damage, and heal (will pass)" << RESET << std::endl;
	diamondTrap.attack("target 1");
	diamondTrap.takeDamage(2);
	diamondTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Drain energy for next test case" << RESET << std::endl;
	while (diamondTrap.getEnergyPoints() != 0)
		diamondTrap.attack("minions");
	
	std::cout << std::endl << MAGENTA << "After the energy is 0, test whether it is still able to heal and attack" << RESET << std::endl;
	diamondTrap.beRepaired(1);
	diamondTrap.attack("target 3");

	std::cout << std::endl << MAGENTA << "Drain the hit point to 0 while also checking for the hit point to not be able to go below 0" << RESET << std::endl;
	while (diamondTrap.getHitPoints() != 0)
		diamondTrap.takeDamage(2);
	
	std::cout << std::endl << MAGENTA << "Try to attack, take damage, and heal with 0 health" << RESET << std::endl;
	diamondTrap.attack("target 3");
	diamondTrap.takeDamage(1);
	diamondTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Test special attack of ScavTrap (guardGate)" << RESET << std::endl;
	diamondTrap.guardGate();

	std::cout << std::endl << MAGENTA << "Test special attack of FragTrap (highFivesGuys)" << RESET << std::endl;
	diamondTrap.highFivesGuys();

	std::cout << std::endl << MAGENTA << "Test special attack of DiamondTrap (whoAmI)" << RESET << std::endl;
	diamondTrap.whoAmI();

	std::cout << std::endl << MAGENTA << "[6]Testing the attack method, make sure its DiamondTrap thats attacking, not clapTrap" << RESET << std::endl;
	ClapTrap*	attackTestTrap = new DiamondTrap("attackTestTrap");
	attackTestTrap->attack("target");
	delete attackTestTrap;

	std::cout << std::endl;

	return (0);
}
