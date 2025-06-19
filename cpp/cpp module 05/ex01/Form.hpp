#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(std::string _name, int _gradeToSign, int _gradeToExecute);
		~Form();

		Form(const Form& other);
		Form&		operator=(const Form &other);

		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;

		void				beSigned(Bureaucrat& bureaucrat);

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
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				isSigned;

};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif