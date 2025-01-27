#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(rand() % 150 + 1), _gradeToExecute(rand() % 150 + 1) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &form)
	: _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {}

Form &Form::operator=(Form const &form)
{
	if (this != &form)
	{
		this->_signed = form._signed;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << ", signed : " << (form.getSigned() ? "yes" : "no")
		<< ", grade to sign : " << form.getGradeToSign()
		<< ", grade to execute : " << form.getGradeToExecute();
	return out;
}
