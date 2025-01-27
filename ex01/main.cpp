#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // try {
    //     Bureaucrat high("High", 0);
    // } catch (const Bureaucrat::GradeTooHighException &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // } catch (const std::exception &e) {
    //     std::cout << "Unexpected exception: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat low("Low", 151);
    // } catch (const Bureaucrat::GradeTooLowException &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // } catch (const std::exception &e) {
    //     std::cout << "Unexpected exception: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat valid("Valid", 75);
    //     std::cout << valid << std::endl;
    //     valid.incrementGrade();
    //     std::cout << valid << std::endl;
    //     valid.decrementGrade();
    //     std::cout << valid << std::endl;
    // } catch (const std::exception &e) {
    //     std::cout << "Unexpected exception: " << e.what() << std::endl;
    // }

    try {
        Form form1("Form1", 50, 100);
        std::cout << form1 << std::endl;

        Bureaucrat bureaucrat1("Bureaucrat1", 60);
        bureaucrat1.signForm(form1);
        std::cout << form1 << std::endl;

        Bureaucrat bureaucrat2("Bureaucrat2", 40);
        bureaucrat2.signForm(form1);
        std::cout << form1 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form form2("Form2", 0, 100); // This should throw GradeTooHighException
    } catch (const Form::GradeTooHighException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Form form3("Form3", 151, 100); // This should throw GradeTooLowException
    } catch (const Form::GradeTooLowException &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
