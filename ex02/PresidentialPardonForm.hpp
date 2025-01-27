#ifndef PREIDENTIALPARDONFORM_HPP
#define PREIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};

#endif
