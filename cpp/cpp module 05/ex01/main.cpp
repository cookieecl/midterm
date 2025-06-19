#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat* bestBureau = new Bureaucrat("best", 2);
	Bureaucrat* worstBureau = new Bureaucrat("worse", 140);

	std::cout << BLUE << "///// Test Form /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check form construction" << RESET << std::endl;
	Form* form[5];
	int gradeSignArr[5] = {1, 2, 70, 149, 150};
	int gradeExecuteArr[5] = {10, 8, 6, 4, 2};
	for (int i = 0; i < 5; ++i)
	{
		form[i] = NULL;
		try
		{
			form[i] = new Form("form" + std::to_string(i + 1), gradeSignArr[i], gradeExecuteArr[i]);
			test(1);
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << std::endl << MAGENTA << "[2] Check form name" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
		test(form[i]->getName() == "form" + std::to_string(i + 1));

	std::cout << std::endl << MAGENTA << "[3] Check form gradeToSign" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
		test(form[i]->getGradeToSign() == gradeSignArr[i]);

	std::cout << std::endl << MAGENTA << "[4] Check form gradeToExecute" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
		test(form[i]->getGradeToExecute() == gradeExecuteArr[i]);

	std::cout << std::endl << MAGENTA << "[5] Check operator <<" << RESET << std::endl;
	std::ostringstream	oss;
	std::string	expected;
	for (int i = 0; i < 5; ++i)
	{
		oss.str("");
		oss.clear();
		oss << *form[i];
		std::cout << *form[i] << std::endl;
		expected = "form name: " + form[i]->getName();
		if (form[i]->getIsSigned() == false)
			expected += " (is not signed)";
		else
			expected += " (is signed)";
		expected += ", grade to sign: " + std::to_string(form[i]->getGradeToSign()) + ", grade to execute: " + std::to_string(form[i]->getGradeToExecute());
		test(oss.str() == expected);
		std::cout << std::endl;
	}

	for (int i = 0; i < 5; ++i)
		delete form[i];

	std::cout << std::endl << MAGENTA << "[6] Check from construction with invalid grade" << RESET << std::endl;
	Form*	invalidForm[8];
	int	gradeToSign[8] = {-2, -1, 0, 75, 76, 151, 152, 153};
	int	gradeToExecute[8] = {-2, 75, 151, -1, 152, 0, 76, 153};
	for (int i = 0; i < 8; ++i)
	{
		invalidForm[i] = NULL;
		try
		{
			std::cout << "Grade to sign: " << gradeToSign[i] << ", Grade to execute: " << gradeToExecute[i] << std::endl;
			invalidForm[i] = new Form("invalid" + std::to_string(i + 1), gradeToSign[i], gradeToExecute[i]);
			test(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			if (i < 4)
				test(invalidForm[i] == NULL && std::string(e.what()) == "Grade too high!");
			else
				test(invalidForm[i] == NULL && std::string(e.what()) == "Grade too low!");
			std::cout << std::endl;
		}
	}

	std::cout << MAGENTA << "[7] Check invalid name, is it constructed and changed into default?" << RESET << std::endl;
	try
	{
		Form* invalidnameForm = new Form("", 6, 8);
		std::cout << *invalidnameForm << std::endl;
		test(invalidnameForm->getName() == "default" && invalidnameForm->getGradeToSign() == 6 && invalidnameForm->getGradeToExecute() == 8);
		delete invalidnameForm;
	}
	catch(const std::exception& e)
	{
		test(0);
	}
	
	std::cout << std::endl << MAGENTA << "[8] Check copy constructor is deep copy" << RESET << std::endl;
	Form* original = new Form("x", 6, 8);
	Form* formCopy = new Form(*original);
	std::cout << "Original: " << *original << std::endl;
	std::cout << "Copy: " << *formCopy << std::endl;

	original->beSigned(*bestBureau);
	std::cout << std::endl << "After signing original: " << std::endl;
	std::cout << "Original: " << *original << std::endl;
	std::cout << "Copy: " << *formCopy << std::endl;
	test(original->getIsSigned() == true && formCopy->getIsSigned() == false);

	std::cout << std::endl << MAGENTA << "[9] Check copy assignment" << RESET << std::endl;
	Form* basicForm = new Form("basic", 150, 150);
	std::cout << "Before copy assignment: " << *original << std::endl;
	std::cout << "What will be copied from: " << *basicForm << std::endl;
	*original = *basicForm;
	std::cout << std::endl << "After copy assignment: " << *original << std::endl;
	test(original->getIsSigned() == false);
	basicForm->beSigned(*bestBureau);
	std::cout << std::endl << "After signing original: " << *bestBureau << std::endl;
	std::cout << "After copy assigment + signing original: " << *original << std::endl;
	test(basicForm->getIsSigned() == true && original->getIsSigned() == false);

	delete original;
	delete formCopy;
	delete basicForm;

	std::cout << std::endl << BLUE << "///// Test Bureaucrat's signForm /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check whether incompetent bureaucrat can't sign "
		<< "(it doesn't matter if it pass the criteria of grade to execute)" << RESET << std::endl;
	Form* testForm1 = new Form("testForm1", 75, 1);
	Form* testForm2 = new Form("testForm1", 75, 150);

	std::cout << "Bureaucrat: " << *worstBureau << std::endl;
	std::cout << "Form: " << *testForm1 << std::endl;
	worstBureau->signForm(testForm1);
	test(testForm1->getIsSigned() == false);
	std::cout << std::endl << "Form: " << *testForm2 << std::endl;
	worstBureau->signForm(testForm2);
	test(testForm2->getIsSigned() == false);

	std::cout << std::endl << MAGENTA << "[2] Check whether competent bureaucrat can sign "
		<< "(it doesn't matter if it doesn't pass the criteria of grade to execute)" << RESET << std::endl;
	std::cout << "Bureaucrat: " << *bestBureau << std::endl;
	std::cout << "Form: " << *testForm1 << std::endl;
	bestBureau->signForm(testForm1);
	test(testForm1->getIsSigned() == true);
	std::cout << std::endl << "Form: " << *testForm2 << std::endl;
	bestBureau->signForm(testForm2);
	test(testForm2->getIsSigned() == true);

	delete testForm1;
	delete testForm2;
	delete bestBureau;
	delete worstBureau;

	return (0);
}
