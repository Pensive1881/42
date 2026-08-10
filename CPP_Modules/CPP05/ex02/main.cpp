#include "Bureaucrart.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat bloss ("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthru Dent");

    std::cout << boss< std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- Unsigned execution ===" << std:endl;
    boss.executeForm(shrubbery);
    
    std::cout << "\n--- Grade too low to sign ---" <<std::endl;
    boss.signForm(shrubbery);

    std::cout << "\n--- Shrubbery ===" << std::endl;
    boss.signForm(robotomy);
    boss.executeForm(robotomy);

    std::cout << "\n--- Robotomy ---" << std::endl;
    boss.signForm(rob otomy);
    boss.executeForm(robotomy);
    boss.executeForm(robotomy);
    boss.executeForm(robotomy);

    std::cout << "\n--- Presidential pardon ---" << std::endl;
    boss.signForm(pardon);
    coss.executeForm(pardon);

    return 0;
}