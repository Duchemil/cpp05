#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(rand() % 150 + 1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	if (this != &bureaucrat) {
        _grade = bureaucrat._grade;
    }
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << _name <<" grade's incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << _name <<" grade's decremented to " << _grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(Form &form)
{
	if (_grade > form.getGradeToSign())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because bureaucrat's grade is too low" << std::endl;
	}
	else
	{
		std::cout << _name << " signs " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}
