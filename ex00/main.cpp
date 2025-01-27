#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat high("High", 0); // This should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 151); // This should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat valid("Valid", 75); // This should not throw any exception
        std::cout << valid << std::endl;

        valid.incrementGrade(); // This should work fine
        std::cout << valid << std::endl;

        valid.decrementGrade(); // This should work fine
        std::cout << valid << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
