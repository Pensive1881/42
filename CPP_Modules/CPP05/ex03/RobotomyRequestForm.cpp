#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45),
      target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(
    const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45),
      target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(
    const RobotomyRequestForm& other)
    : AForm(other),
      target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(
    const Bureaucrat& executor) const
{
    checkExecution(executor);

    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2)
    {
        std::cout << target
                  << " has been robotomized successfully"
                  << std::endl;
    }
    else
    {
        std::cout << "Robotomy of "
                  << target
                  << " failed"
                  << std::endl;
    }
}
