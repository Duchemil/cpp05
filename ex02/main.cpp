#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Target");
        PresidentialPardonForm pardonForm("Target");

        // Test signing the forms
        low.signForm(shrubberyForm); // Should fail due to low grade
        high.signForm(shrubberyForm); // Should succeed

        low.executeForm(shrubberyForm); // Should fail due to low grade
        high.executeForm(shrubberyForm); // Should succeed and create a file
        std::cout << "\n" << std::endl;


        low.signForm(robotomyForm); // Should fail due to low grade
        high.signForm(robotomyForm); // Should succeed

        low.executeForm(robotomyForm); // Should fail due to low grade
        high.executeForm(robotomyForm); // Should succeed and perform robotomy
        std::cout << "\n" << std::endl;


        low.signForm(pardonForm); // Should fail due to low grade
        high.signForm(pardonForm); // Should succeed

        low.executeForm(pardonForm); // Should fail due to low grade
        high.executeForm(pardonForm); // Should succeed and pardon target
        std::cout << "\n" << std::endl;

        // Show execution state
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
