#include "Zombie.hpp"

int	main()
{
	Zombie* heapZombie = newZombie("heap");
	heapZombie->announce();

	randomChump("stack");
	delete heapZombie;
	return (0);
}
