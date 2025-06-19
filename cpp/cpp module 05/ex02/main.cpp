#include <sstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	Bureaucrat* bestBureau = new Bureaucrat("best", 1);
	Bureaucrat* worstBureau = new Bureaucrat("worse", 150);

	std::cout << BLUE << "///// Test all the forms construction /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check form construction" << RESET << std::endl;
	AForm* form[3];
	std::string	target[3] = {"target_shrub", "target_robotomy", "target_presidential"};
	
	for (int i = 0; i < 3; ++i)
	{
		form[i] = NULL;
		try
		{
			switch (i)
			{
				case 0:
					form[i] = new ShrubberyCreationForm(target[i]);
					break ;
				case 1:
					form[i] = new RobotomyRequestForm(target[i]);
					break ;
				case 2:
					form[i] = new PresidentialPardonForm(target[i]);
			}
			test(1);
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << std::endl << MAGENTA << "[2] Check form name" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << form[i]->getName() << std::endl;
		switch (i)
		{
			case 0:
				test(form[i]->getName() == "ShrubberyCreationForm");
				break ;
			case 1:
				test(form[i]->getName() == "RobotomyRequestForm");
				break ;
			case 2:
				test(form[i]->getName() == "PresidentialPardonForm");
		}
	}

	std::cout << std::endl << MAGENTA << "[3] Check form gradeToSign" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		switch (i)
		{
			case 0:
				test(form[i]->getGradeToSign() == 145);
				break;
			case 1:
				test(form[i]->getGradeToSign() == 72);
				break;
			case 2:
				test(form[i]->getGradeToSign() == 25);
		}
	}

	std::cout << std::endl << MAGENTA << "[4] Check form gradeToExecute" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		switch (i)
		{
			case 0:
				test(form[i]->getGradeToExecute() == 137);
				break ;
			case 1:
				test(form[i]->getGradeToExecute() == 45);
				break ;
			case 2:
				test(form[i]->getGradeToExecute() == 5);
		}
	}

	std::cout << std::endl << MAGENTA << "[5] Check operator <<" << RESET << std::endl;
	std::ostringstream	oss;
	std::string	expected;
	for (int i = 0; i < 3; ++i)
	{
		oss.str("");
		oss.clear();
		if (i == 0)
		{
			oss << *dynamic_cast<ShrubberyCreationForm*>(form[i]);
			std::cout << *dynamic_cast<ShrubberyCreationForm*>(form[i]) << std::endl;
		}
		else if (i == 1)
		{
			oss << *dynamic_cast<RobotomyRequestForm*>(form[i]);
			std::cout << *dynamic_cast<RobotomyRequestForm*>(form[i]) << std::endl;
		}
		else
		{
			oss << *dynamic_cast<PresidentialPardonForm*>(form[i]);
			std::cout << *dynamic_cast<PresidentialPardonForm*>(form[i]) << std::endl;
		}

		expected = "Form name: " + form[i]->getName();
		if (form[i]->getIsSigned() == false)
			expected += " (is not signed)";
		else
			expected += " (is signed)";
		expected += ", grade to sign: " + std::to_string(form[i]->getGradeToSign()) + ", grade to execute: " + std::to_string(form[i]->getGradeToExecute());
		expected += ", target: " + form[i]->getTarget();
		test(oss.str() == expected);
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; ++i)
	{
		delete form[i];
		form[i] = NULL;
	}

	std::cout << MAGENTA << "[6] Check invalid target name, is it constructed and changed into default?" << RESET << std::endl;
	try
	{
		for (int i = 0; i < 3; ++i)
		{
			switch (i)
			{
				case 0:
					form[i] = new ShrubberyCreationForm();
					break ;
				case 1:
					form[i] = new RobotomyRequestForm();
					break ;
				case 2:
					form[i] = new PresidentialPardonForm();
			}
			test(form[i]->getTarget() == "default");
		}
	}
	catch(const std::exception& e)
	{
		test(0);
	}
	
	std::cout << std::endl << MAGENTA << "[7] Check copy constructor is deep copy" << RESET << std::endl;
	AForm*	formCopy[3];

	for (int i = 0; i < 3; ++i)
	{
		formCopy[i] = NULL;
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			switch (i)
			{
				case 0:
					formCopy[i] = new ShrubberyCreationForm(*dynamic_cast<ShrubberyCreationForm *>(form[i]));
					break ;
				case 1:
					formCopy[i] =  new RobotomyRequestForm(*dynamic_cast<RobotomyRequestForm *>(form[i]));
					break ;
				case 2:
					formCopy[i] =  new PresidentialPardonForm(*dynamic_cast<PresidentialPardonForm *>(form[i]));
			}
			std::cout << "Original isSigned: " << form[i]->getIsSigned() << std::endl;
			std::cout << "Copy isSigned: " << formCopy[i]->getIsSigned() << std::endl;
			form[i]->beSigned(*bestBureau);
			std::cout << "Original isSigned (after signing original): " << form[i]->getIsSigned() << std::endl;
			std::cout << "Copy isSigned (after signing original): " << formCopy[i]->getIsSigned() << std::endl;

			test(form[i]->getIsSigned() == true && formCopy[i]->getIsSigned() == false);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << MAGENTA << "[8] Check copy assignment" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << "Original isSigned (before copy assignment): " << form[i]->getIsSigned() << std::endl;
			std::cout << "What will be copied from (source): " << formCopy[i]->getIsSigned() << std::endl;
			*form[i] = *formCopy[i];
			std::cout << "Original isSigned (after copy assignment): " << form[i]->getIsSigned() << std::endl;
			test(form[i]->getIsSigned() == false);
			std::cout << "Check deep copy by changing signing the form which the original copied from / source: " << std::endl;
			formCopy[i]->beSigned(*bestBureau);
			std::cout << "Original isSigned (after signing source): " << form[i]->getIsSigned() << std::endl;
			std::cout << "Souce form isSigned (after signing source): " << formCopy[i]->getIsSigned() << std::endl;
			test(form[i]->getIsSigned() == false && formCopy[i]->getIsSigned() == true);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	for (int i = 0; i < 3; ++i)
		*formCopy[i] = *form[i];

	std::cout << BLUE << "///// Test signing forms /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check valid signing" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << "Bureaucrat grade: " << bestBureau->getGrade() << std::endl;
			std::cout << "Grade to sign: " << form[i]->getGradeToSign() << std::endl;
			std::cout << "Form sign status before the attempt to sign: " << form[i]->getIsSigned() << std::endl;
			bestBureau->signForm(form[i]);
			std::cout << "Form sign status after the attempt to sign: " << form[i]->getIsSigned() << std::endl;
			test(form[i]->getIsSigned() == true);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << MAGENTA << "[2] Check invalid signing because the grade is too low" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << "Bureaucrat grade: " << worstBureau->getGrade() << std::endl;
			std::cout << "Grade to sign: " << formCopy[i]->getGradeToSign() << std::endl;
			std::cout << "Form sign status before the attempt to sign: " << formCopy[i]->getIsSigned() << std::endl;
			worstBureau->signForm(formCopy[i]);
			test(0);
		}
		catch(const std::exception& e)
		{
			std::cout << "Form sign status after the attempt to sign: " << formCopy[i]->getIsSigned() << std::endl;
			test(formCopy[i]->getIsSigned() == false);
			std::cout << std::endl;
		}
	}

	std::cout << MAGENTA << "[3] Check invalid signing because the form is already signed" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << "Bureaucrat grade: " << bestBureau->getGrade() << std::endl;
			std::cout << "Grade to sign: " << form[i]->getGradeToSign() << std::endl;
			std::cout << "Form sign status before the attempt to sign: " << form[i]->getIsSigned() << std::endl;
			bestBureau->signForm(form[i]);
			test(0);
		}
		catch(const std::exception& e)
		{
			test(1);
			std::cout << std::endl;
		}
	}

	std::cout << MAGENTA << "[4] Check invalid signing because the form is invalid" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << "Bureaucrat grade: " << bestBureau->getGrade() << std::endl;
			std::cout << "Grade to sign: " << formCopy[i]->getGradeToSign() << std::endl;
			std::cout << "Form sign status before the attempt to sign: " << formCopy[i]->getIsSigned() << std::endl;
			bestBureau->signForm(NULL);
			test(0);
		}
		catch(const std::exception& e)
		{
			test(1);
			std::cout << std::endl;
		}
	}

	std::cout << BLUE << "///// Test executing forms /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check valid execute" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << form[i]->getName() << "form sign status: " << form[i]->getIsSigned() << std::endl;
			std::cout << "Bureaucrat grade: " << bestBureau->getGrade() << std::endl;
			std::cout << "Grade to execute: " << form[i]->getGradeToExecute() << std::endl;
			bestBureau->executeForm(*form[i]);
			for (int j = 0; i == 1 && j < 9; ++j)
				bestBureau->executeForm(*form[i]);
			test(1);
			std::cout << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cout << RED << "ERROR OPENING FILE, CHECK FILE PERMISSION" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	std::cout << MAGENTA << "[2] Check invalid execute (form is not signed)" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << formCopy[i]->getName() << "form sign status: " << formCopy[i]->getIsSigned() << std::endl;
			std::cout << "Bureaucrat grade: " << bestBureau->getGrade() << std::endl;
			std::cout << "Grade to execute: " << formCopy[i]->getGradeToExecute() << std::endl;
			bestBureau->executeForm(*formCopy[i]);
			test(0);
		}
		catch(const std::exception& e)
		{
			test(1);
			std::cout << std::endl;
		}
	}

	std::cout << MAGENTA << "[3] Check invalid execute (grade is too low)" << RESET << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "// " << form[i]->getName() << " //" << std::endl;
		try
		{
			std::cout << form[i]->getName() << "form sign status: " << form[i]->getIsSigned() << std::endl;
			std::cout << "Bureaucrat grade: " << worstBureau->getGrade() << std::endl;
			std::cout << "Grade to execute: " << form[i]->getGradeToExecute() << std::endl;
			worstBureau->executeForm(*form[i]);
			test(0);
		}
		catch(const std::exception& e)
		{
			test(1);
			std::cout << std::endl;
		}
	}

	delete bestBureau;
	delete worstBureau;
	
	for (int i = 0; i < 3; ++i)
	{
		delete form[i];
		delete formCopy[i];
	}

	return (0);
}
