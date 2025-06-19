#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(std::string _name, int _gradeToSign, int _gradeToExecute);
		virtual ~AForm();

		AForm(const AForm& other);
		AForm&		operator=(const AForm &other);

		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;
		virtual std::string	getTarget() const = 0;

		void				beSigned(Bureaucrat& bureaucrat);

		virtual void		execute(Bureaucrat const & executor) const;
		virtual void		executeAction(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const _NOEXCEPT;
		};

		class FormAlreadySignedException : public std::exception
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

std::ostream&	operator<<(std::ostream& out, const AForm& aForm);

#endif