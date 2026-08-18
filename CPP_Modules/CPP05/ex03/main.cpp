#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* shrubbery =
        someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm* robotomy =
        someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon =
        someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm* unknown =
        someRandomIntern.makeForm("coffee request", "Boss");
    
    if (shrubbery)
    {
        boss.signForm(*shrubbery);
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