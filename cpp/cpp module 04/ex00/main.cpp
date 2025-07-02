/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:49:21 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/02 20:49:22 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	const WrongCat* l = new WrongCat();

	std::cout << MAGENTA << "[1] Test Animal" << RESET << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl << MAGENTA << "[2] Test Dog" << RESET << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << std::endl << MAGENTA << "[2] Test Cat" << RESET << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << std::endl << MAGENTA << "[3] Test WrongCat used as WrongAnimal" << RESET << std::endl;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	std::cout << std::endl << MAGENTA << "[4] Test WrongCat used as WrongCat" << RESET << std::endl;
	std::cout << l->getType() << " " << std::endl;
	l->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	return (0);
}
