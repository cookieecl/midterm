#include "ScavTrap.hpp"

int	main()
{
	std::cout << std::endl << MAGENTA << "[1]Test default constructor" << RESET << std::endl;
	ScavTrap	defaultScavTrap;
	defaultScavTrap.attack("boss");

	std::cout << std::endl << MAGENTA << "[2]Test copy constructor" << RESET << std::endl;
	ScavTrap	copy(defaultScavTrap);
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
	defaultScavTrap = copy;
	defaultScavTrap.attack("boss");
	std::cout << "Default should have 97 energy points, result: " << defaultScavTrap.getEnergyPoints() << std::endl;
	if (defaultScavTrap.getEnergyPoints() != 97)
	{
		std::cout << RED << "Test failed, program abort" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << YELLOW << "Test passed!" << std::endl;
	}

	std::cout << std::endl << MAGENTA << "[4]Test constructor with parameter" << RESET << std::endl;
	ScavTrap	scavTrap("x");

	std::cout << std::endl << MAGENTA << "[5]Test functions:" << RESET << std::endl;
	std::cout << MAGENTA << "Test the ability to attack, take damage, and heal (will pass)" << RESET << std::endl;
	scavTrap.attack("target 1");
	scavTrap.takeDamage(2);
	scavTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Drain energy for next test case" << RESET << std::endl;
	while (scavTrap.getEnergyPoints() != 0)
		scavTrap.attack("minions");
	
	std::cout << std::endl << MAGENTA << "After the energy is 0, test whether it is still able to heal and attack" << RESET << std::endl;
	scavTrap.beRepaired(1);
	scavTrap.attack("target 3");

	std::cout << std::endl << MAGENTA << "Drain the hit point to 0 while also checking for the hit point to not be able to go below 0" << RESET << std::endl;
	while (scavTrap.getHitPoints() != 0)
		scavTrap.takeDamage(2);
	
	std::cout << std::endl << MAGENTA << "Try to attack, take damage, and heal with 0 health" << RESET << std::endl;
	scavTrap.attack("target 3");
	scavTrap.takeDamage(1);
	scavTrap.beRepaired(1);

	std::cout << std::endl << MAGENTA << "Test special attack of ScavTrap (guardGate)" << RESET << std::endl;
	scavTrap.guardGate();

	std::cout << std::endl << MAGENTA << "[6]Testing the attack method, make sure its ScavTrap thats attacking, not clapTrap" << RESET << std::endl;
	ClapTrap*	attackTestTrap = new ScavTrap("attackTestTrap");
	attackTestTrap->attack("target");
	delete attackTestTrap;

	std::cout << std::endl;

	return (0);
}
