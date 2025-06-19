#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*animalArr[10];

	std::cout << MAGENTA << "[1] Test that they are constructed in the right other, animal, brain, [type of animal]" << RESET << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << MAGENTA << "[2] Test the brain class" << RESET << std::endl;
	std::cout << MAGENTA << "Adding ideas" << RESET << std::endl;
	Brain*	brain = animalArr[6]->getBrain();
	for (int i = 0; i < 100; ++i)
	{
		brain->addIdea("idea " + std::to_string(i + 1));
	}

	std::cout << std::endl << MAGENTA << "Adding idea after full" << RESET << std::endl;
	brain->addIdea("idea " + std::to_string(101));

	std::cout << std::endl << MAGENTA << "Copy full animal and check the brain idea" << RESET << std::endl;
	Dog	*dog1 = new Dog();
	dog1->getBrain()->addIdea("dog 1 first idea");

	Dog *dog2 = new Dog(*dog1);
	std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea[-1]: " << dog2->getBrain()->getIdea(-1) << std::endl;
	std::cout << "dog2 idea[1]: "<< dog2->getBrain()->getIdea(1) << std::endl;

	std::cout << std::endl << MAGENTA << "[3] Check deep copy, they should be different (first adding idea to dog2)" << RESET << std::endl;
	dog2->getBrain()->addIdea("dog 2 second idea");
	std::cout << "dog1 idea[1]: " << dog1->getBrain()->getIdea(1) << std::endl;
	std::cout << "dog2 idea[1]: " << dog2->getBrain()->getIdea(1) << std::endl;
	delete dog1;
	delete dog2;

	std::cout << std::endl;

	std::cout << MAGENTA << "[4] Test destructor" << RESET << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		delete animalArr[i];
		std::cout << std::endl;
	}

	// Animal	a;
	// Animal*	aDynamic = new Animal();

	return (0);
}
