#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&		operator=(const Bureaucrat &other);

		const std::string	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(Form* form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};

	private:
		const std::string	name;
		int					grade;

};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif