#include "Zombie.hpp"

Zombie::Zombie()
: name("[name not set]")
{
	std::cout << "A zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been deleted" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::assignName(std::string _name)
{
	name = _name;
}
