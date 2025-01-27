#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};

#endif
