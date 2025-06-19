#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << MAGENTA << "[1] Test Animal" << RESET << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl << MAGENTA << "[2] Test Dog" << RESET << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << std::endl << MAGENTA << "[2] Test Cat" << RESET << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << std::endl << MAGENTA << "[3] Test WrongCat" << RESET << std::endl;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	return (0);
}
