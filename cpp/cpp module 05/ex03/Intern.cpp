#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
	// std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	// std::cout << BLUE << "Intern copy constructor called" << RESET << std::endl;
}

Intern&	Intern::operator=(const Intern &other)
{
	// std::cout << BLUE << "Intern copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		return (*this);
	}
	return (*this);
}

AForm*	Intern::makeShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*		(Intern::*action[3])(const std::string& target) = {
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm
	};

	std::string	formType[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (name == formType[i])
		{
			try
			{
				AForm*	newForm = (this->*action[i])(target);
				std::cout << "Intern creates " << name << std::endl;
				return (newForm);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				throw ;
			}
		}
		i++;
	}

	throw InvalidFormType();
}

const char* Intern::InvalidFormType::what() const _NOEXCEPT
{
	return ("Invalid form type!");
}
