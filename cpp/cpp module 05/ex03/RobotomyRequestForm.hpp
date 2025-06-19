#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class	RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&		operator=(const RobotomyRequestForm &other);

		std::string	getTarget() const;
		void		executeAction(Bureaucrat const & executor) const;

	private:
		const std::string	target;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm);

#endif