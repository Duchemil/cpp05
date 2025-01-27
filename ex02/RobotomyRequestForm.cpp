#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) : AForm(robotomyRequestForm), _target(robotomyRequestForm._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	if (this != &robotomyRequestForm)
	{
		AForm::operator=(robotomyRequestForm);
		_target = robotomyRequestForm._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
	std::srand(std::time(0));
	int rand = std::rand() % 2;

	// AForm::execute(executor);
	std::cout << "BzzzzzZZZZZZzzzzzzZZZZZZZzzzzz" << std::endl;
	if (rand == 0)
		std::cout << _target <<" has been robotomized successfully." << std::endl;
	else
        std::cout << "The robotomy failed." << std::endl;
}
