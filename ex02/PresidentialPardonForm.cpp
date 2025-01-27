#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(presidentialPardonForm), _target(presidentialPardonForm._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	if (this != &presidentialPardonForm)
	{
		AForm::operator=(presidentialPardonForm);
		_target = presidentialPardonForm._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
	// AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
