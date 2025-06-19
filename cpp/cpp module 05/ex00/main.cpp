#include <sstream>
#include "Bureaucrat.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"

void	test(bool condition)
{
	if (condition)
		std::cout << GREEN << "Test Passed!" << RESET << std::endl;
	else
	{
		std::cout << RED << "Test Failed!" << RESET << std::endl;
		std::exit(1);
	}
}

int	main()
{
	std::cout << BLUE << "///// Test Bureaucrat /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check bureaucrat construction" << RESET << std::endl;
	Bureaucrat* bureau[5];
	int gradeArr[5] = {1, 2, 70, 149, 150};
	for (int i = 0; i < 5; ++i)
	{
		bureau[i] = NULL;
		try
		{
			bureau[i] = new Bureaucrat("bureau" + std::to_string(i + 1), gradeArr[i]);
			test(1);
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << std::endl << MAGENTA << "[2] Check bureaucrat name" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
		test(bureau[i]->getName() == "bureau" + std::to_string(i + 1));

	std::cout << std::endl << MAGENTA << "[3] Check bureaucrat grade" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
		test(bureau[i]->getGrade() == gradeArr[i]);

	std::cout << std::endl << MAGENTA << "[4] Check operator <<" << RESET << std::endl;
	std::ostringstream	oss;
	for (int i = 0; i < 5; ++i)
	{
		oss.str("");
		oss.clear();
		oss << *bureau[i];
		std::cout << *bureau[i] << std::endl;
		test(oss.str() == "bureau" + std::to_string(i + 1) + ", bureaucrat grade " + std::to_string(gradeArr[i]));
		std::cout << std::endl;
	}

	for (int i = 0; i < 5; ++i)
		delete bureau[i];

	std::cout << std::endl << MAGENTA << "[.] Check bureaucrat construction with invalid grade" << RESET << std::endl;
	Bureaucrat*	invalidBureau[6];
	int	grade;
	for (int i = 0; i < 6; ++i)
	{
		invalidBureau[i] = NULL;
		if (i == 0)
			std::cout << MAGENTA << "[5] Check with grade higher than 1" << RESET << std::endl;
		else if (i == 3)
			std::cout << std::endl << MAGENTA << "[6] Check with grade lower than 150" << RESET << std::endl;
		if (i < 3)
			grade = 0 - (i * 2);
		else
			grade = 151 + (i % 3) * 2;
		try
		{
			invalidBureau[i] = new Bureaucrat("invalid" + std::to_string(i + 1), grade);
			test(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			if (i < 3)
				test(invalidBureau[i] == NULL && std::string(e.what()) == "Grade too high!");
			else
				test(invalidBureau[i] == NULL && std::string(e.what()) == "Grade too low!");
		}
	}

	std::cout << std::endl << MAGENTA << "[7] Check invalid name, is it constructed and changed into default?" << RESET << std::endl;
	try
	{
		Bureaucrat* invalidnameBureau = new Bureaucrat("", 8);
		std::cout << *invalidnameBureau << std::endl;
		test(invalidnameBureau->getName() == "default" && invalidnameBureau->getGrade() == 8);
		delete invalidnameBureau;
	}
	catch(const std::exception& e)
	{
		test(0);
	}
	
	std::cout << std::endl << MAGENTA << "[8] Check copy constructor is deep copy" << RESET << std::endl;
	Bureaucrat* original = new Bureaucrat("x", 3);
	Bureaucrat* bureauCopy = new Bureaucrat(*original);
	std::cout << "Original: " << *original << std::endl;
	std::cout << "Copy: " << *bureauCopy << std::endl;

	original->decrementGrade();
	std::cout << std::endl << "After decrement original grade:" << std::endl;
	std::cout << "Original: " << *original << std::endl;
	std::cout << "Copy: " << *bureauCopy << std::endl;
	test(original->getGrade() == bureauCopy->getGrade() + 1);

	std::cout << std::endl << MAGENTA << "[9] Check copy assignment" << RESET << std::endl;
	Bureaucrat* lowBureau = new Bureaucrat("y", 148);
	std::cout << "Before copy assignment: " << *original << std::endl;
	std::cout << "What will be copied from: " << *lowBureau << std::endl;
	*original = *lowBureau;
	std::cout << std::endl << "After copy assignment: " << *original << std::endl;
	lowBureau->decrementGrade();
	std::cout << "After decrement original grade: " << *lowBureau << std::endl;
	std::cout << "After copy assigment + decrementing original (make sure it does not decrement): " << *original << std::endl;
	test(lowBureau->getGrade() == original->getGrade() + 1);

	std::cout << std::endl << MAGENTA << "[10] Check incrementGrade()" << RESET << std::endl;
	int	prevGrade;
	while(1)
	{
		try
		{
			std::cout << "Before increment: " << *bureauCopy << std::endl;
			prevGrade = bureauCopy->getGrade();
			bureauCopy->incrementGrade();
			std::cout << "After increment: " << *bureauCopy << std::endl;
			test(bureauCopy->getGrade() == prevGrade - 1);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			test(bureauCopy->getGrade() == 1 && bureauCopy->getGrade() == prevGrade && std::string(e.what()) == "Grade too high!");
			break ;
		}
	}

	std::cout << std::endl << MAGENTA << "[12] Check decrementGrade()" << RESET << std::endl;
	while(1)
	{
		try
		{
			std::cout << "Before decrement: " << *original << std::endl;
			prevGrade = original->getGrade();
			original->decrementGrade();
			std::cout << "After decrement: " << *bureauCopy << std::endl;
			test(original->getGrade() == prevGrade + 1);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			test(original->getGrade() == 150 && original->getGrade() == prevGrade && std::string(e.what()) == "Grade too low!");
			break ;
		}
	}

	delete original;
	delete bureauCopy;
	delete lowBureau;

	return (0);
}
