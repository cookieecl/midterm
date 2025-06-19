#include "Form.hpp"

Form::Form()
: name("default"), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
	// std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute)
: name(_name.empty() ? "default" : _name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	// std::cout << GREEN << "Form " << name << " constructor called" << RESET << std::endl;
	if (gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	// std::cout << RED << "Form destructor called" << RESET << std::endl;
}

Form::Form(const Form& other)
: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
	// std::cout << BLUE << "Form copy constructor called" << RESET << std::endl;
}

Form&	Form::operator=(const Form &other)
{
	// std::cout << BLUE << "Form copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return (*this);
}

const std::string	Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

const int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

const int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "form name: " << form.getName() << " ";
	if (form.getIsSigned() == false)
		out << "(is not signed), ";
	else
		out << "(is signed), ";
	out << "grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();

	return (out);
}