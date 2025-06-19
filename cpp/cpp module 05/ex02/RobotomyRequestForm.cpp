#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	// std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
: AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	// std::cout << GREEN << "RobotomyRequestForm " << name << " constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target)
{
	// std::cout << BLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	// std::cout << BLUE << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::executeAction(Bureaucrat const & executor) const
{
	int robotomized = rand() % 2;

	std::cout << "* drilling noises *" << std::endl;
	if (robotomized)
		std::cout << "Target \"" << target << "\" has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm)
{
	out << static_cast<const AForm&>(robotomyRequestForm);
	out << ", target: " << robotomyRequestForm.getTarget();
	return (out);
}
