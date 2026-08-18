#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Intern someRnadomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* shrubbery =
        someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm* robotomy =
        someRandomIntern.makeForm("", "Bender");
    AForm* pardon =
        someRandomIntern.makeForm("", "");
    AForm* unkonwn =
        someRandomIntern.makeForm("", "");
    
    if (shrubbery)
    {
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
    }

    if (robotomy)
    {
        boss.signForm(*robotomy);
        boss.executeForm(*shrubbery);
    }

    if (robotomy)
    {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
    }

    if (pardon)
    {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
    }

    if (unknown)
    {
        boss.signForm(*unknown);
        boss.executeForm(*unknown);
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unknown;

    return 0;
}