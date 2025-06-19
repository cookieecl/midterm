#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
: name(_name)
{

}

HumanB::~HumanB()
{
	
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is unable to attack without any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}
