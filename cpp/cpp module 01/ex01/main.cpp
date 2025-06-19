#include "Zombie.hpp"

int	main()
{
	int	zombieNum = 6;
	Zombie* horde = zombieHorde(zombieNum, "heap");

	for (int i = 0; i < zombieNum; ++i)
		horde[i].announce();

	delete[] horde;
	return (0);
}
