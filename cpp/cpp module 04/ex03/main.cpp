/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:51:22 by aputri-a          #+#    #+#             */
/*   Updated: 2025/07/08 19:08:00 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main()
{	
	IMateriaSource*	srcFull;
	IMateriaSource* src;
	AMateria* cureMateria;
	AMateria* tmp;

	std::cout << MAGENTA << "[1] Test MateriaSource" << RESET << std::endl;
	srcFull = new MateriaSource();
	
	std::cout << std::endl << MAGENTA << "Learning non existent materia" << RESET << std::endl;
	srcFull->learnMateria(NULL);

	std::cout << std::endl << MAGENTA << "Learning Materia and make it full to check" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
			srcFull->learnMateria(new Ice());
		else
			srcFull->learnMateria(new Cure());
	}
	srcFull->learnMateria(new Ice());

	std::cout << std::endl << MAGENTA << "Test creating materia from empty materia library" << RESET << std::endl;
	src = new MateriaSource();
	tmp = src->createMateria("ice");
	if (tmp == 0)
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}
	
	std::cout << std::endl << MAGENTA << "Test creating materia from a materia that hasn't been learnt yet" << RESET << std::endl;
	cureMateria = new Cure();
	src->learnMateria(cureMateria);
	tmp = src->createMateria("ice");
	if (tmp == 0)
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}

	std::cout << std::endl << MAGENTA << "Test creating materia from a materia that is learnt, but in uppercase" << RESET << std::endl;
	tmp = src->createMateria("Cure");
	if (tmp == 0)
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}

	std::cout << std::endl << MAGENTA << "Creating valid materia which is learnt" << RESET << std::endl;
	tmp = src->createMateria("cure");
	if (tmp && tmp->getType() == "cure")
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}
	delete tmp;

	std::cout << std::endl << MAGENTA << "Create deep copy of materiaSrc" << RESET << std::endl;
	MateriaSource*	srcCopy = new MateriaSource(*dynamic_cast<MateriaSource*>(src));

	std::cout << std::endl << MAGENTA << "Check whether the copy is deep by learning ice in the original and try to create ice from the copy" << RESET << std::endl;
	src->learnMateria(new Ice());

	std::cout << "The original result: ";
	tmp = src->createMateria("ice");

	delete tmp;

	std::cout << "The copy result: ";
	tmp = srcCopy->createMateria("ice");

	if (tmp == 0)
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}

	std::cout << std::endl << MAGENTA << "[2] Test Character" << RESET << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	std::cout << std::endl << MAGENTA << "Check getName function of character" << RESET << std::endl;
	if (me->getName() == "me")
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}
	if (bob->getName() == "bob")
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}

	std::cout << std::endl << MAGENTA << "Make an array of Materia for testing purposes" << RESET << std::endl;
	AMateria* tmpArr[4];
	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
			tmpArr[i] = srcFull->createMateria("ice");
		else
			tmpArr[i] = srcFull->createMateria("cure");
	}

	std::cout << std::endl << MAGENTA << "Equip invalid materia" << RESET << std::endl;
	me->equip(NULL);

	std::cout << std::endl << MAGENTA << "Equip more materia when the inventory is already full" << RESET << std::endl;
	for (int i = 0; i < 4; ++i)
		me->equip(tmpArr[i]);
	me->equip(new Cure());

	std::cout << std::endl << MAGENTA << "Unequip valid materia and making sure its not being deleted" << RESET << std::endl;
	me->unequip(1); // unequip cure, so it should be (ice, ice, cure) now
	if (tmpArr[1])
		std::cout << YELLOW << "Test passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		return (1);
	}

	std::cout << std::endl << MAGENTA << "Unequip invalid materia" << RESET << std::endl;
	me->unequip(3);
	me->unequip(4);
	me->unequip(-1);

	std::cout << std::endl << MAGENTA << "Use valid materia, should be [ice, ice, cure]" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		me->use(i, *bob);
	}

	std::cout << std::endl << MAGENTA << "Use invalid materia" << RESET << std::endl;
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << std::endl << MAGENTA << "Create deep copy of character and test whether the copy still save the unequiped materia of the real one" << RESET << std::endl;
	Character*	charCopy = new Character(*dynamic_cast<Character*>(me));
	me->unequip(2);

	std::cout << "The original result of using index 3 : ";
	me->use(2, *bob);

	std::cout << "The copy result of using index 3: ";
	charCopy->use(2, *bob);

	std::cout << std::endl << "delete srcFull" << std::endl;
	delete srcFull;

	std::cout << std::endl << "delete src" << std::endl;
	delete src;

	std::cout << std::endl << "delete srcCopy" << std::endl;
	delete srcCopy;

	std::cout << std::endl << "delete bob" << std::endl;
	delete bob;

	std::cout << std::endl << "delete me" << std::endl;
	delete me;

	std::cout << std::endl << "delete charCopy" << std::endl;
	delete charCopy;

	std::cout << std::endl << "delete unequiped materia" << std::endl;
	delete tmpArr[1];
	delete tmpArr[3];

	return (0);
}
