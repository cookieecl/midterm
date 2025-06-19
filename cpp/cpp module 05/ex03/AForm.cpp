#include "AForm.hpp"

AForm::AForm()
: name("default"), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
	// std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute)
: name(_name.empty() ? "default" : _name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	// std::cout << GREEN << "AForm " << name << " constructor called" << RESET << std::endl;
	if (gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	// std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other)
: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
	// std::cout << BLUE << "AForm copy constructor called" << RESET << std::endl;
}

AForm&	AForm::operator=(const AForm &other)
{
	// std::cout << BLUE << "AForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

const std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getIsSigned() const
{
	return (isSigned);
}

const int	AForm::getGradeToSign() const
{
	return (gradeToSign);
}

const int	AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (isSigned == true)
		throw FormAlreadySignedException();
	else if (bureaucrat.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	executeAction(executor);
}

const char* AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low!");
}

const char* AForm::FormNotSignedException::what() const _NOEXCEPT
{
	return ("Form has not been signed!");
}

const char* AForm::FormAlreadySignedException::what() const _NOEXCEPT
{
	return ("Form has already been signed, can not sign again!");
}

std::ostream&	operator<<(std::ostream& out, const AForm& aForm)
{
	out << "Form name: " << aForm.getName() << " ";
	if (aForm.getIsSigned() == false)
		out << "(is not signed), ";
	else
		out << "(is signed), ";
	out << "grade to sign: " << aForm.getGradeToSign() << ", grade to execute: " << aForm.getGradeToExecute();

	return (out);
}
