#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default")
{
	// std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
: AForm("PresidentialPardonForm", 25, 5), target(_target)
{
	// std::cout << GREEN << "PresidentialPardonForm " << name << " constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), target(other.target)
{
	// std::cout << BLUE << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	// std::cout << BLUE << "PresidentialPardonForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::executeAction(Bureaucrat const & executor) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& presidentialPardonForm)
{
	out << static_cast<const AForm&>(presidentialPardonForm);
	out << ", target: " << presidentialPardonForm.getTarget();
	return (out);
}
