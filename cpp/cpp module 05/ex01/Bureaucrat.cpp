#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("default"), grade(1)
{
	// std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
: name(_name.empty() ? "default" : _name), grade(_grade)
{
	// std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade)
{
	// std::cout << BLUE << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	// std::cout << BLUE << "Bureaucrat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::signForm(Form* form)
{
	if (!form)
		std::cout << "Form is invalid" << std::endl;
	else
	{
		try
		{
			form->beSigned(*this);
			std::cout << name << " signed " << form->getName() << std::endl; 
		}
		catch(const std::exception& e)
		{
			std::cout << name << " couldn't signed " << form->getName() << " because " << std::string(e.what()) << std::endl;
		}
	}
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
