#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
: name(_name)
{
	std::cout << "Zombie " << name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been deleted" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
