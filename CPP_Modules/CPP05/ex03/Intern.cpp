#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

namespace
{
    AForm* createShrubbery(const std::string& target)
    {
        return new ShrubberyCreationForm(target);
    }

    AForm* createRobotomy(const std::string& target)
    {
        return new RobotomyRequestForm(target);
    }

    AForm* createPardon(const std::string& target)
    {
        return new PresidentialPardonForm(target);
    }
}

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const
{
    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (*FormCreator)(const std::string&);

    FormCreator creators[] = {
        createShrubbery,
        createRobotomy,
        createPardon
    };

    int i = 0;
    while (i < 3)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates "
                      << formName << std::endl;
            return creators[i](target);
        }
        ++i;
    }

    std::cout << "Intern cannot create "
              << formName
              << " because the form name is unknown"
              << std::endl;

    return 0;
}