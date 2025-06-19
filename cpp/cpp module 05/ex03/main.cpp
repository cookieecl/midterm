#include <sstream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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
	std::cout << BLUE << "///// Test intern /////" << RESET << std::endl;
	std::cout << MAGENTA << "[1] Check intern makeForm function with valid form type" << RESET << std::endl;
	Intern* intern = new Intern();
	std::string formType[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm* form[3];
	
	for (int i = 0; i < 3; ++i)
	{
		form[i] = NULL;
		try
		{
			form[i] = intern->makeForm(formType[i], "target" + std::to_string(i + 1));
			test(form[i] && form[i]->getName() == formType[i] && form[i]->getTarget() == "target" + std::to_string(i + 1));
		}
		catch(const std::exception& e)
		{
			test(0);
		}
	}

	for (int i = 0; i < 3; ++i)
		delete form[i];

	std::cout << std::endl << MAGENTA << "[2] Check intern makeForm function with invalid form type" << RESET << std::endl;
	std::string invalidFormType[3] = {"shrubberycreationform", "OtherTypeOfForm", ""};
	for (int i = 0; i < 3 ; ++i)
	{
		form[i] = NULL;
		try
		{
			form[i] = intern->makeForm(invalidFormType[i], "target" + std::to_string(i + 1));
			test(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			test(form[i] == NULL);
		}
	}

	return (0);
}
