#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrubberyCreationForm);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};

#endif
