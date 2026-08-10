#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- Unsigned execution ---" << std::endl;
    boss.executeForm(shrubbery);

    std::cout << "\n--- Grade too low to sign ---" << std::endl;
    intern.signForm(shrubbery);

    std::cout << "\n--- Shrubbery ---" << std::endl;
    boss.signForm(shrubbery);
    boss.executeForm(shrubbery);

    std::cout << "\n--- Robotomy ---" << std::endl;
    boss.signForm(robotomy);
    boss.executeForm(robotomy);
    boss.executeForm(robotomy);
    boss.executeForm(robotomy);

    std::cout << "\n--- Presidential pardon ---" << std::endl;
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}