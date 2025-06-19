#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : virtual public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&		operator=(const ShrubberyCreationForm &other);

		std::string	getTarget() const;
		void				executeAction(Bureaucrat const & executor) const;

	private:
		const std::string	target;
};

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm);

#endif